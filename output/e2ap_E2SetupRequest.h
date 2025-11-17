#ifndef _E2AP_E2SETUPREQUEST_H_
#define _E2AP_E2SETUPREQUEST_H_

#include "rtxsrc/rtxContext.h"

typedef struct e2ap_E2SetupRequest {
} e2ap_E2SetupRequest;

EXTERN int asn1PE_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue);
EXTERN int asn1PD_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue);
EXTERN void asn1Init_e2ap_E2SetupRequest (e2ap_E2SetupRequest* pvalue);
EXTERN void asn1Free_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue);
EXTERN void asn1Print_e2ap_E2SetupRequest (const char* name, const e2ap_E2SetupRequest* pvalue);

#endif