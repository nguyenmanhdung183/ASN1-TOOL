#include "e2ap_E2nodeComponentConfigAddition_Item.h"
#include "rtxsrc/rtxErrCodes.h"

int asn1PE_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigAddition_Item");



   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigAddition_Item");



   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigAddition_Item (e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
}

void asn1Free_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
}