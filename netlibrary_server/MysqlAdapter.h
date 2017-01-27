// MysqlAdapter.h: interface for the MysqlAdapter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSQLADAPTER_H__3AA20ADB_EFC6_405C_BAA5_BB5A27BF1865__INCLUDED_)
#define AFX_MYSQLADAPTER_H__3AA20ADB_EFC6_405C_BAA5_BB5A27BF1865__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Server.h"

class MysqlAdapter  
{
public:
	MysqlAdapter();
	virtual ~MysqlAdapter();
public:
	void searchbook(char* info);
	void getbookdetail(char* isbn);
	

private:
	
	MYSQL mysql;
    MYSQL_RES *result;
	MYSQL_ROW row;
public:
	 char booklist[300];
	 char bookdetail[500];

};

#endif // !defined(AFX_MYSQLADAPTER_H__3AA20ADB_EFC6_405C_BAA5_BB5A27BF1865__INCLUDED_)
