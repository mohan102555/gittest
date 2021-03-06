/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _FACT_H_RPCGEN
#define _FACT_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct s {
	int n;
};
typedef struct s s;

#define fact_prog 0x12345678
#define fact_vers 1

#if defined(__STDC__) || defined(__cplusplus)
#define FCTORIAL 1
extern  int * fctorial_1(s *, CLIENT *);
extern  int * fctorial_1_svc(s *, struct svc_req *);
extern int fact_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define FCTORIAL 1
extern  int * fctorial_1();
extern  int * fctorial_1_svc();
extern int fact_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_s (XDR *, s*);

#else /* K&R C */
extern bool_t xdr_s ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_FACT_H_RPCGEN */
