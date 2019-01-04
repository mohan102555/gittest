/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _EXAMPLE_H_RPCGEN
#define _EXAMPLE_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define BUFFER_SIZE 1024

struct doubles {
	double a;
	double b;
};
typedef struct doubles doubles;

struct strings {
	char src[BUFFER_SIZE];
	char dst[BUFFER_SIZE];
};
typedef struct strings strings;

#define example_prog 0x11111111
#define example_vers 1

#if defined(__STDC__) || defined(__cplusplus)
#define fact 1
extern  int * fact_1(int *, CLIENT *);
extern  int * fact_1_svc(int *, struct svc_req *);
#define power 2
extern  double * power_1(doubles *, CLIENT *);
extern  double * power_1_svc(doubles *, struct svc_req *);
#define strconc 3
extern  char ** strconc_1(strings *, CLIENT *);
extern  char ** strconc_1_svc(strings *, struct svc_req *);
extern int example_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define fact 1
extern  int * fact_1();
extern  int * fact_1_svc();
#define power 2
extern  double * power_1();
extern  double * power_1_svc();
#define strconc 3
extern  char ** strconc_1();
extern  char ** strconc_1_svc();
extern int example_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_doubles (XDR *, doubles*);
extern  bool_t xdr_strings (XDR *, strings*);

#else /* K&R C */
extern bool_t xdr_doubles ();
extern bool_t xdr_strings ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_EXAMPLE_H_RPCGEN */