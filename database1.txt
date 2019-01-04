#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sqlite3.h>
int z;
char condition[25];
static int callback(void *data,int ncol,char** colinrow,char ** colname)
{
	int i;
	if((*(char *)data)=='*')
		printf("full details of employee %d:\n",z++);
	else
		printf("%s of employee %d:\n",(char *)data,z++);
	for(i=0;i<ncol;i++)
		printf("%s=%s\n",colname[i],colinrow[i]?colinrow[i]:"null");
	return 0;
}
int main(void)
{
	sqlite3 *db;
	char *errmsg=0;
	int rc,opendb=1;
	char *sql;
	int choice;
	int eid,sal;
	char ch,ch1,ename[20],city[20];
	char newcondition[25];
	printf("enter choice:1-insert,2-update,3-delete,4-select:");
	scanf("%d",&choice);
	do
	{
		if((choice>=1) && (choice<=4) && (opendb!=0))
		{
			opendb=sqlite3_open("mohan.db",&db);
			if(opendb)
			{
				printf("cant open database:%s\n",sqlite3_errmsg(db));
				sqlite3_free(errmsg);
				sqlite3_close(db);
				printf("closed database successfully\n");
				return 1;
			}
			else
				printf("opened database successfully\n");
		}
		if(choice==1)
		{
			sql="select * from details;";
			rc=sqlite3_exec(db,sql,0,0,&errmsg);
			if(rc)
			{
				sql="create table details(id int,name char(20),city char(20),salary int);";
				rc=sqlite3_exec(db,sql,0,0,&errmsg);
				if(rc)
				{
					printf("sql error:%s\n",errmsg);
					sqlite3_free(errmsg);	
					sqlite3_close(db);
					printf("closed database successfully\n");
				sql=NULL;
					return 1;
				}
				else
					printf("table created successfully\n");
			}
		}
		ch=0;
		ch1=0;
		switch(choice)
		{
		case 1:printf("enter employee details\n");
		       printf("employee id:");
		       scanf("%d",&eid);
		       printf("employee name:");
		       scanf("%s",ename);
		       printf("employee city:");
		       scanf("%s",city);
		       printf("employee salary:");
		       scanf("%d",&sal);
		       sql=sqlite3_mprintf("insert into details values(%d,'%s','%s',%d)",eid,ename,city,sal);
		       break;
		case 2:sql="select *from details;";
		       rc=sqlite3_exec(db,sql,0,0,&errmsg);
		       if(rc==0)
		       {
				printf("give set condition and where condition\n");
				scanf("%s",condition);
				scanf("%s",newcondition);
				sql=sqlite3_mprintf("update details set %s where %s",newcondition,condition);
		       }
		       else
		       {
			       printf("sql error:%s\n",errmsg);
			       sqlite3_free(errmsg);
			       sqlite3_close(db);
			       printf("closed database successfully\n");
				sql=NULL;
			       return 1;
		       }
	       	       break;
		case 3:sql="select *from details;";
		       rc=sqlite3_exec(db,sql,0,0,&errmsg);
                       if(rc==0)
		       {
			       printf("give the condition to delete\n");
			       scanf("%s",condition);
			       sql=sqlite3_mprintf("delete from details where %s",condition);
		       }
		       else
		       {
			       printf("sql error:%s\n",errmsg);
			       sqlite3_free(errmsg);
			       sqlite3_close(db);
			       printf("closed database successfully\n");
				sql=NULL;
			       return 1;
		       }
		       break;
		case 4:sql="select *from details;";
		       rc=sqlite3_exec(db,sql,0,0,&errmsg);
		       if(rc==0)
		       {
			       z=1;
			       printf("enter select options:");
			       scanf("%s",condition);
			       sql=sqlite3_mprintf("select %s from details;",condition);
		       }
		       else
		       {
			       printf("sql error:%s\n",errmsg);
			       sqlite3_free(errmsg);
			       sqlite3_close(db);
			       printf("closed database successfully\n");
				sql=NULL;
			       return 1;
		       }
		       break;
		default:printf("choose valid option\n");
			printf("do u want to give choice again y/n:");
			scanf(" %c",&ch1);
			if(ch1!='y')
			{
				 if(opendb==0)
				 {
					 sqlite3_close(db);
					 printf("closed database successfully\n");
				 }
				sql=NULL;
				 return 0;
			}
		}
		if(ch1!='y')
		{
			rc=sqlite3_exec(db,sql,callback,(void *)condition,&errmsg);
			if(rc)
			{
				printf("sql error:%s\n",sqlite3_errmsg(db));
				sqlite3_free(errmsg);
				sqlite3_close(db);
				printf("closed database successfully\n");
				sql=NULL;
				return 1;
			}
			else
				printf("operation successfull\n");
			printf("u want to do operation again y/n:");
			scanf(" %c",&ch);
		}
		if((ch1=='y')||(ch=='y'))
		{
			printf("enter choice:1-insert,2-update,3-delete,4-select:");
			scanf("%d",&choice);
		}
	}while((ch=='y')||(ch1=='y'));
	if(opendb==0)
	{
		sqlite3_close(db);
		printf("closed database successfully\n");
	}
	sql=NULL;	
	return 0;
}  
