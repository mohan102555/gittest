/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "fact.h"

bool_t
xdr_s (XDR *xdrs, s *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->n))
		 return FALSE;
	return TRUE;
}
