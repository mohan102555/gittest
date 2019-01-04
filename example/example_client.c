/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "example.h"


void
example_prog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	int  fact_1_arg;
	double  *result_2;
	doubles  power_1_arg;
	char * *result_3;
	strings  strconc_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, example_prog, example_vers, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	printf("enter number:");
	scanf("%d",&fact_1_arg);

	result_1 = fact_1(&fact_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		printf("result1=%d\n",*result_1);	
	}

	printf("enter two numbers:");
	scanf("%lf%lf",&(power_1_arg.a),&(power_1_arg.b));

	result_2 = power_1(&power_1_arg, clnt);
	if (result_2 == (double *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		printf("result2=%lf\n",*result_2);	
	}
	
	printf("enter two strings:");
	scanf("%s%s",(strconc_1_arg.dst),(strconc_1_arg.src));

	result_3 = strconc_1(&strconc_1_arg, clnt);
	if (result_3 == (char **) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		printf("result3=%s\n",*result_3);	
	}


#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	example_prog_1 (host);
exit (0);
}