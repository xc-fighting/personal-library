// Server.cpp: implementation of the Server class.
//
//////////////////////////////////////////////////////////////////////

#include "Server.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Server* Server:: static_server;
SOCKET Server:: LISTENSOCKET;
SOCKET Server:: ACCEPTSOCKET;
int Server:: EventTotal=0;
WSAEVENT Server:: EventArray[WSA_MAXIMUM_WAIT_EVENTS];	//SendEventArray
LPSOCKET_INFORMATION Server:: SocketArray[WSA_MAXIMUM_WAIT_EVENTS];


void Server::Init()
{
  WORD wVersion;
  WSADATA wsadata;
  wVersion=MAKEWORD(2,2);
  if(WSAStartup(wVersion,&wsadata)<0)
  {
	  cout<<"error in startup socket dll error code:"<<::WSAGetLastError()<<endl;
	  return ;
  }
   
  if((LISTENSOCKET=::WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, 
      WSA_FLAG_OVERLAPPED))==INVALID_SOCKET)
  {
	  cout<<"error in create socket,error code:"<<::WSAGetLastError()<<endl;
      return ;
  }

  SOCKADDR_IN stSrcAddr;
  stSrcAddr.sin_family=AF_INET;
  stSrcAddr.sin_port=htons(this->port);
  stSrcAddr.sin_addr.s_addr=inet_addr(this->ip);

  if(::bind(LISTENSOCKET,(struct sockaddr FAR*)&stSrcAddr,sizeof(sockaddr))<0)
  {
	  cout<<"bind error ,error code"<<::WSAGetLastError()<<endl;

	  return ;
  }

  if(::listen(LISTENSOCKET,50))
  {
	  cout<<"listen error ,error code"<<::WSAGetLastError()<<endl;

	  return;

  }

  if((EventArray[0]=::WSACreateEvent())==WSA_INVALID_EVENT)
  {
	  cout<<"wsaevent create error,error code:"<<::WSAGetLastError()<<endl;
	  return ;
  }

  EventTotal=1;
}


Server::Server(char *ipaddr,int portnum)
{
	cout<<"服务器对象构建"<<endl;
	::memset(ip,0,16);
	::strcpy(ip,ipaddr);
	port=portnum;
	this->Init();
	
}

Server::~Server()
{

}
