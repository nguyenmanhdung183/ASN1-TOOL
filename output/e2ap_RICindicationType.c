/* e2ap_RICindicationType.c */
#include "e2ap_RICindicationType.h"
#include "rtxsrc/rtxErrCodes.h"

const OSUTF8CHAR* const e2ap_RICindicationType_ENUMTAB[e2ap_RICindicationType_ENUMTABSIZE] = {

   (OSUTF8CHAR*)"report",

   (OSUTF8CHAR*)"insert"

};

EXTERN int asn1PE_e2ap_RICindicationType (OSCTXT* pctxt, e2ap_RICindicationType value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RICindicationType");
   if (value >= 2) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(1));
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RICindicationType (OSCTXT* pctxt, e2ap_RICindicationType* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RICindicationType");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(1));
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RICindicationType (const char* name, e2ap_RICindicationType* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   switch (*pvalue) {

      case 0:
         stat = rtPrintToString (" = report\n", buffer, bufSize);
         break;

      case 1:
         stat = rtPrintToString (" = insert\n", buffer, bufSize);
         break;

      default:
         stat = rtPrintToString (" = ???\n", buffer, bufSize);
   }
   return (stat < 0) ? -1 : 0;
}