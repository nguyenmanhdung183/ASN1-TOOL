/* e2ap_PLMN_Identity.c */
#include "e2ap_PLMN_Identity.h"
#include "rtxsrc/rtxErrCodes.h"

/* Fixed SIZE OCTET STRING */
EXTERN int asn1PE_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "PLMN_Identity");
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(3), OSUINTCONST(3), 0, 0);
   stat = pe_OctetString (pctxt, pvalue->numocts, pvalue->data);
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : 0;
}

EXTERN int asn1PD_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "PLMN_Identity");
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(3), OSUINTCONST(3), 0, 0);
   stat = pd_OctetString (pctxt, &pvalue->numocts, pvalue->data, sizeof(pvalue->data));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : 0;
}

int asn1Init_e2ap_PLMN_Identity (e2ap_PLMN_Identity* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->numocts = 0;
   return 0;
}

void asn1Free_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue)
{
   /* Không cần free vì data nằm trong struct */
   if (pvalue) pvalue->numocts = 0;
}

/* Print to string */
int asn1PrtToStr_e2ap_PLMN_Identity (const char* name, e2ap_PLMN_Identity* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringHexStr (name, pvalue->numocts, pvalue->data, buffer, bufSize) < 0)
      return -1;
   return 0;
}