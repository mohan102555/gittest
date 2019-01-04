#include<stdio.h>
#include<sqlite3.h>
static int callback(void *notused,int argc,char **argv,char **azcolname)
{
	int i;
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
                fprintf(stderr,"cant open database:%s\n",sqlite3_errmsg(db));
                return 0;
        }
        else
        {
                fprintf(stderr,"open database successfully:%s\n",sqlite3_errmsg(db));
        }
	//create sql
	sql="create table company(id int not null,"\
	     "name text not null,age int not null,"\
	     "address char(20),salary real);";
	//execute sql
	rc=sqlite3_exec(db,sql,callback,0,&zerrmsg);
	if(rc)
	{
		fprintf(stderr,"sql error:%s\n",zerrmsg);
		sqlite3_free(zerrmsg);
	}
	else
	{
		fprintf(stdout,"table created successfully\n");
	}
        sqlite3_close(db);
	return 0;
}
