// Server.h: interface for the Server class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERVER_H__914854B2_B569_4627_9EE8_BF96AB87C688__INCLUDED_)
#define AFX_SERVER_H__914854B2_B569_4627_9EE8_BF96AB87C688__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <mysql.h>
#pragma comment (lib,"libmysql.lib")
using namespace std;
#pragma comment (lib,"WS2_32.lib")


#define DATA_BUFSIZE 8192
#define _server "127.0.0.1"
#define _username "root"
#define _password "1234"
#define _dbname "netlibrary"




typedef struct SOCKET_INFORMATION
{

   CHAR Buffer[DATA_BUFSIZE];//发送的信息缓冲区
   WSABUF DataBuf;//wsa结构体
   SOCKET socket;//套接字
   WSAOVERLAPPED Overlapped;//重叠结构体
   DWORD FileLen;//文件长度
   char FileName[20];//文件名
   long ByteSend;//已经发送的长度
   ifstream file;//文件输出对象
   

}SOCKET_INFORMATION,*LPSOCKET_INFORMATION;




class Server  
{
public:
	Server(char *ipaddr,int portnum);
	virtual ~Server();

public:
	static Server* static_server;
	static SOCKET LISTENSOCKET;
	static SOCKET ACCEPTSOCKET;
	static int EventTotal;
	static WSAEVENT EventArray[WSA_MAXIMUM_WAIT_EVENTS];	//SendEventArray

	static LPSOCKET_INFORMATION SocketArray[WSA_MAXIMUM_WAIT_EVENTS];


public:

	void Init();

private:
	char ip[16];
	int port;




};

#endif // !defined(AFX_SERVER_H__914854B2_B569_4627_9EE8_BF96AB87C688__INCLUDED_)
