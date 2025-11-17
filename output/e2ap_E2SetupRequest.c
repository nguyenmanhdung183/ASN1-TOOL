#include "e2ap_E2SetupRequest.h"
#include "rtxsrc/rtxErrCodes.h"

int asn1PE_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2SetupRequest");



   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2SetupRequest");



   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2SetupRequest (e2ap_E2SetupRequest* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
}

void asn1Free_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue)
{
}