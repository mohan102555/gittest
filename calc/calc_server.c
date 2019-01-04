/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calc.h"

float *
calculator_1_svc(inputs *argp, struct svc_req *rqstp)
{
	static float  result;

	/*
	 * insert server code here
	 */
	if(argp->op=='+')
	{
		result=(argp->a) + (argp->b);
	return &result;
	}
	else if(argp->op=='-')
	{
		result=(argp->a) - (argp->b);
	return &result;	
	}
	else if(argp->op=='*')
	{
		result=(argp->a) * (argp->b);
	return &result;
	}
	else if(argp->op=='/')
	{
		result=(argp->a) / (argp->b);
	return &result;
	}
	else
	{
		printf("enter valid option\n");
	}
}