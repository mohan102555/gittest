#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>
static int callback(void *notused,int argc,char **argv,char **azcolname)
{
	int i;
	printf("callback function called\n");
	for(i=0;i<argc;i++)
	{
		printf("%s=%s\n",azcolname[i],argv[i]?argv[i]:"null");
	}
	printf("\n");
	return 0;
}	
int main(int argc,char *argv[])
{
        sqlite3 *db;
        char *zerrmsg=0;
        int rc;
	char *sql;
	//open db
        rc=sqlite3_open("test.db",&db);
        if(rc)
        {
                printf("cant open database:%s\n",sqlite3_errmsg(db));
                return 0;
        }
        else
        {
                printf("open database successfully:%s\n",sqlite3_errmsg(db));
        }
	//create sql
	sql="insert into company (id,name,age,address,salary)"\
		"values(1,'mohan',25,'bangalore',31000.00);"\
	     "insert into company (id,name,age,address,salary)"\
	     	"values(2,'sreekanth',21,'bangalore',29000.00);"\
	     "insert into company (id,name,age,address,salary)"\
	     	"values(3,'nilesh',22,'bangalore',29000.00);"\
	     "insert into company (id,name,age,address,salary)"\
	     	"values(4,'kiran',21,'baroda',26000.00);";
	//execute sql
	rc=sqlite3_exec(db,sql,callback,0,&zerrmsg);
	if(rc)
	{
		printf("sql error:%s\n",zerrmsg);
		sqlite3_free(zerrmsg);
	}
	else
	{
		printf("records created successfully\n");
	}
        sqlite3_close(db);
	return 0;
}

