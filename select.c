#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>
static int callback(void *notused,int argc,char **argv,char **azcolname)
{
	int i;
	printf("callback function called:");
	for(i=0;i<argc;i++)
	{
		printf("%s=%s\n",azcolname[i],argv[i]?argv[i]:"null");
	}
	printf("\n");
	return 0;
}	
int main()
{
        sqlite3 *db;
        char *zerrmsg=0;
        int rc;
	char *sql;
	//const char *data="callback function called";
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
	sql="delete from company where id=4;"\
		"select * from company;";
	//execute sql
	rc=sqlite3_exec(db,sql,callback,0,&zerrmsg);
	if(rc)
	{
		printf("sql error:%s\n",zerrmsg);
		sqlite3_free(zerrmsg);
	}
	else
	{
		printf("operation done successfully\n");
	}
        sqlite3_close(db);
	return 0;
}
