/* e2ap_Criticality.c */
#include "e2ap_Criticality.h"
#include "rtxsrc/rtxErrCodes.h"

const OSUTF8CHAR* const e2ap_Criticality_ENUMTAB[e2ap_Criticality_ENUMTABSIZE] = {

   (OSUTF8CHAR*)"reject",

   (OSUTF8CHAR*)"ignore",

   (OSUTF8CHAR*)"notify"

};

EXTERN int asn1PE_e2ap_Criticality (OSCTXT* pctxt, e2ap_Criticality value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "Criticality");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_Criticality (OSCTXT* pctxt, e2ap_Criticality* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "Criticality");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_Criticality (const char* name, e2ap_Criticality* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   switch (*pvalue) {

      case 0:
         stat = rtPrintToString (" = reject\n", buffer, bufSize);
         break;

      case 1:
         stat = rtPrintToString (" = ignore\n", buffer, bufSize);
         break;

      case 2:
         stat = rtPrintToString (" = notify\n", buffer, bufSize);
         break;

      default:
         stat = rtPrintToString (" = ???\n", buffer, bufSize);
   }
   return (stat < 0) ? -1 : 0;
}