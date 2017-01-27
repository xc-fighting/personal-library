#include "MysqlAdapter.h"


DWORD WINAPI ListenThread(LPVOID p)
{
	SOCKADDR_IN addr_conn; 
	int nSize = sizeof(addr_conn); 
	char szPeerAddress[16]; 
	DWORD RecvBytes;
	DWORD Flags;

	cout<<"服务器监听线程启动,线程号:"<<::GetCurrentThreadId()<<endl;
	while(true)
	{
      if((Server::ACCEPTSOCKET=::accept(Server::LISTENSOCKET,NULL,NULL))==INVALID_SOCKET)
	  {
		  cout<<"accept socket error:"<<::WSAGetLastError()<<endl;
		  return 0;
	  }
	  ::getpeername(Server::ACCEPTSOCKET,(SOCKADDR *)&addr_conn,&nSize);
      ::memset(szPeerAddress,0,16);
      ::strcpy(szPeerAddress,inet_ntoa(addr_conn.sin_addr));
	  cout<<"客户机的ip地址:"<<szPeerAddress<<endl;

	  if((Server::SocketArray[Server::EventTotal]=new SOCKET_INFORMATION)==NULL)
	  {
		  cout<<"global allocation error:"<<::GetLastError()<<endl;
		  return 0;
	  }

	  Server::SocketArray[Server::EventTotal]->socket=Server::ACCEPTSOCKET;
	  ::memset(&Server::SocketArray[Server::EventTotal]->Overlapped,0,sizeof(OVERLAPPED));
	  ::memset(Server::SocketArray[Server::EventTotal]->Buffer,0,DATA_BUFSIZE);

	  Server::SocketArray[Server::EventTotal]->DataBuf.buf=Server::SocketArray[Server::EventTotal]->Buffer;
	  Server::SocketArray[Server::EventTotal]->DataBuf.len=DATA_BUFSIZE;
	  Server::SocketArray[Server::EventTotal]->ByteSend=0;
	  Server::SocketArray[Server::EventTotal]->FileLen=0;


	  if((Server::SocketArray[Server::EventTotal]->Overlapped.hEvent=Server::EventArray[Server::EventTotal]=::WSACreateEvent())== WSA_INVALID_EVENT)
	  {
		  cout<<"create event error:"<<::GetLastError()<<endl;
		  return 0;
	  }

	  Flags=0;

	  	//投递一个异步WSARecv请求
	  if (WSARecv(Server::SocketArray[Server::EventTotal]->socket, 
		  &(Server::SocketArray[Server::EventTotal]->DataBuf), 1, &RecvBytes, &Flags,
		  &(Server::SocketArray[Server::EventTotal]->Overlapped), NULL) == SOCKET_ERROR)
		{
			if (WSAGetLastError() != ERROR_IO_PENDING)
			{
				cout<<"recv error:"<<::WSAGetLastError()<<endl;
				return 0;
			}
		}
	//  cout<<Server::SocketArray[Server::EventTotal]->DataBuf.buf<<endl;
     

	  Server::EventTotal++;
      cout<<Server::EventTotal<<endl;
     
	  if(::WSASetEvent(Server::EventArray[0])==false)
	  {
		  cout<<"set event0 error:"<<::WSAGetLastError()<<endl;
		  return 0;
	  }

	}
}


DWORD WINAPI ProcessIO(LPVOID p)
{

	
	DWORD Index;
	LPSOCKET_INFORMATION SI;
	DWORD BytesTransferred;
	DWORD RecvBytes;
	DWORD Flags;
	int i;
    char buffer[10240];

    cout<<"IO处理线程开始进行工作"<<::GetCurrentThreadId()<<endl;




  while(true)
  {
	

	  	//检测事件数组EventArray的状态
		if((Index = WSAWaitForMultipleEvents(Server::EventTotal, Server::EventArray, FALSE,
		WSA_INFINITE, FALSE)) == WSA_WAIT_FAILED)
		{
			printf("WSAWaitForMultipleEvents failed %d\n", WSAGetLastError());
			return 0;
		}      
		//如果是EventArray[0]状态发生改变，清除为未置信号进入下一次循环
		if (Index  == 0)
		{
			WSAResetEvent(Server::EventArray[0]);
			continue;
		}
		cout<<"准备处理io事件响应..."<<"当期index为"<<Index<<endl;


			//得到导致WSAWaitForMultipleEvents函数返回的元素SI
		SI = Server::SocketArray[Index];

		//把EventArray[Index-WSA_WAIT_EVENT_0]清除为未置信号
		WSAResetEvent(Server::EventArray[Index-WSA_WAIT_EVENT_0]);

		//返回状态发生改变的插口上重叠操作的结果
		//如果结果为false或重叠I/O操作传输的字节数等于0，则关闭该插口并释放资源
		if (WSAGetOverlappedResult(SI->socket, &(SI->Overlapped), &BytesTransferred,
		FALSE, &Flags) == FALSE || BytesTransferred == 0)
		{
			printf("Closing socket %d\n", SI->socket);
			if (closesocket(SI->socket) == SOCKET_ERROR)
			{
				printf("closesocket() failed with error %d\n", WSAGetLastError());
			}

			delete SI;
			WSACloseEvent(Server::EventArray[Index]);      
			if (Index + 1 != Server::EventTotal)
				for (i = Index ; i < Server::EventTotal; i++)
				{
					Server::EventArray[i] = Server::EventArray[i + 1];
					Server::SocketArray[i] = Server::SocketArray[i + 1];
				}

			Server::EventTotal--;     
			continue;
		}     


		char message[DATA_BUFSIZE];
		::memset(message,0,DATA_BUFSIZE);
		::strcpy(message,SI->DataBuf.buf);

		//当客户端进行连接时候的代码
		if(strcmp(message,"connect")==0)
		{
			char temp[16];
			::memset(temp,0,16);
			strcpy(temp,"success!");
			::send(SI->socket,temp,strlen(temp),0);
		}
		//返回书籍的列表信息部分
        else if(::strstr(message,":search")!=NULL)
		{
			//字符串信息的拆分.....
			int len=strlen(message);
			int ilen=len-7;
			char info[50];
			memset(info,0,50);
			strncpy(info,message,ilen);
			//数据库的查询操作.....
            MysqlAdapter* db=new MysqlAdapter();
			db->searchbook(info);           
			//将信息进行拼装......
			char message_back[300];
			memset(message_back,0,300);
			strcpy(message_back,db->booklist);
			//将结果进行返回......
			::send(SI->socket,message_back,strlen(message_back),0);
			//释放数据库对象
			delete db;
		}
        else if(::strstr(message,":detail")!=NULL)
		{
			//字符串信息的拆分
			int len=strlen(message);
			int ilen=len-7;
			char info[50];
			memset(info,0,50);
			strncpy(info,message,ilen);
			//数据库查询操作
			MysqlAdapter* db=new MysqlAdapter();
			db->getbookdetail(info);
			//信息进行拼装
			char message_back[500];
			memset(message_back,0,500);
			strcpy(message_back,db->bookdetail);
			//将结果进行返回
			::send(SI->socket,message_back,strlen(message_back),0);
			//释放数据库对象
			delete db;
		}



		//这一部分用来进行图片读取操作
		else if(::strstr(message,":image")!=NULL)
		{
          //字符串信息拆分，抽取其中的isbn号码
			int len=strlen(message);
			int ilen=len-6;
			char isbn[20];
			::memset(isbn,0,20);
			strncpy(isbn,message,ilen);
           //相关分析操作
			char tempname[40];
			memset(tempname,0,40);
			strcpy(tempname,isbn);
			strcat(tempname,".bmp");

         
		   //初始化SI->file对象
			strcpy(SI->FileName,tempname);
           // SI->file.open("d:\\test.txt",ios::in||ios::binary);
			char path[40];
			memset(path,0,40);
			strcat(path,"img\\");
			strcat(path,SI->FileName);


			SI->file.open(path,ios::binary);

			


			SI->file.seekg(0,ios::end);
			SI->FileLen=SI->file.tellg();
			cout<<"文件长度显示"<<SI->FileLen<<endl;
		
           //发送信息开始
			char infosend[60];
			memset(infosend,0,60);
			strcpy(infosend,SI->FileName);
			
			::send(SI->socket,infosend,strlen(infosend),0);
			cout<<infosend<<endl;
			Sleep(200);

		
	        

			memset(infosend,0,60);
			ltoa(SI->FileLen,infosend,10);

			::send(SI->socket,infosend,strlen(infosend),0);
			cout<<infosend<<endl;
            
			SI->file.seekg(0,ios::beg);
		    
			
			while(SI->file.eof()==false)
			{
			   memset(buffer,0,10240);
			   SI->file.read(buffer,10240);
			   Sleep(200);
			   int len=SI->file.gcount();
			   cout<<len<<endl;
			   send(SI->socket,buffer,len,0);
			   Sleep(200);
			   		   
			}
            SI->file.close();
			cout<<"文件传输完毕"<<endl;


		}
	
	    cout<<SI->DataBuf.buf<<endl;

		Flags = 0;
		ZeroMemory(&(SI->Overlapped), sizeof(WSAOVERLAPPED));
		SI->Overlapped.hEvent = Server::EventArray[Index];
		SI->DataBuf.len = DATA_BUFSIZE;
		SI->DataBuf.buf = SI->Buffer;
		memset(SI->DataBuf.buf,0,DATA_BUFSIZE);
		if (WSARecv(SI->socket, &(SI->DataBuf), 1, &RecvBytes, &Flags,
		&(SI->Overlapped), NULL) == SOCKET_ERROR)
		{
			if (WSAGetLastError() != ERROR_IO_PENDING)
			{
			   printf("WSARecv() failed with error %d\n", WSAGetLastError());
			   return 0;
			}
		}		

		




  }
}






int main()
{
	char ip[16];
    int port;
	cout<<"请输入服务器ip地址"<<endl;
    cin>>ip;
	cout<<"请输入服务器端口号"<<endl;
	cin>>port;
	Server::static_server=new Server(ip,port);
    ::CreateThread(NULL,0,ListenThread,NULL,0,NULL);
	::CreateThread(NULL,0,ProcessIO,NULL,0,NULL);
	while(true);
	return 0;
}