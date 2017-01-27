// MysqlAdapter.cpp: implementation of the MysqlAdapter class.
//
//////////////////////////////////////////////////////////////////////

#include "MysqlAdapter.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MysqlAdapter::MysqlAdapter()
{
  mysql_init(&mysql);
	if(!mysql_real_connect(&mysql,_server,_username,_password,_dbname,0,NULL,0))
	{
		printf("can't connect the db\n");
	}
	else
	{
		printf("connect database success!\n");
	}
}

MysqlAdapter::~MysqlAdapter()
{
  mysql_close(&mysql);
   printf("关闭连接成功\n");
}

void MysqlAdapter::searchbook(char *info)
{
	cout<<"书籍列表函数进行调用"<<endl;
	char sql[100];
	memset(sql,0,100);
	char dest[100]={" "};
	strcpy(sql,"select isbn,bookname,author from bookinfo where isbn like '%");
	::strcat(dest,sql);
	::strcat(dest,info);
	::strcat(dest,"%' or bookname like '%");
	::strcat(dest,info);
    ::strcat(dest,"%' or author like '%");
	::strcat(dest,info);
	::strcat(dest,"%'");
	cout<<dest<<endl;
	if(mysql_query(&mysql,dest))
	{
		fprintf(stdout,"查询数据库失败%s\n",mysql_error(&mysql));
	}
	else
	{
		
		result=mysql_store_result(&mysql);
		if(mysql_num_rows(result)!=NULL)
		{
		  memset(this->booklist,0,300);
          while((row=mysql_fetch_row(result)))
		  {
			  
			  
			  strcat(this->booklist,"图书isbn:");
			  strcat(this->booklist,row[0]);
			  strcat(this->booklist," ");
			  
			   strcat(this->booklist,"图书名称:");
			  strcat(this->booklist,row[1]);
			  strcat(this->booklist," ");
			  
			 strcat(this->booklist,"图书作者:");
			  strcat(this->booklist,row[2]);
			  strcat(this->booklist," ");
			 
			  strcat(this->booklist,"~");
              
		  }
		 

		}
		else
		{
			memset(this->booklist,0,300);
			strcpy(this->booklist,"no record");
		}
		mysql_free_result(result);
	}
}



void MysqlAdapter::getbookdetail(char* isbn)
{
  cout<<"书籍详细信息函数进行调用"<<endl;
  char sql[100];
  memset(sql,0,100);
  char dest[100]={" "};
  strcpy(sql,"select * from bookinfo where isbn='");
  ::strcat(dest,sql);
  ::strcat(dest,isbn);
  ::strcat(dest,"'");
  if(mysql_query(&mysql,dest))
  {
    fprintf(stdout,"查询数据库失败%s\n",mysql_error(&mysql));
  }
  else
  {
	  	result=mysql_store_result(&mysql);
		if(mysql_num_rows(result)!=NULL)
		{
			memset(this->bookdetail,0,500);
          while((row=mysql_fetch_row(result)))
		  {
			  for(int i=0;i<5;i++)
			  {
				  strcat(this->booklist,row[i]);
				  strcat(this->booklist,"|");  
			  }
		  }
		 

		}
		else
		{
			memset(this->booklist,0,500);
			strcpy(this->booklist,"no details");
		}
		mysql_free_result(result);

  }


}
