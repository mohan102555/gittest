#include<stdio.h>
#include<sqlite3.h>
int main(int argc,char * argv[])
{
	sqlite3 *db;
	char *zErrMsg=0;
	int rc;
//	&db=null;
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
	sqlite3_close(db);
}
