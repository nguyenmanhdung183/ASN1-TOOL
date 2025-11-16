/* e2ap_CauseMisc.c */
#include "e2ap_CauseMisc.h"
#include "rtxsrc/rtxErrCodes.h"

const OSUTF8CHAR* const e2ap_CauseMisc_ENUMTAB[e2ap_CauseMisc_ENUMTABSIZE] = {

   (OSUTF8CHAR*)"control-processing-overload",

   (OSUTF8CHAR*)"hardware-failure",

   (OSUTF8CHAR*)"om-intervention",

   (OSUTF8CHAR*)"unspecified"

};

EXTERN int asn1PE_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseMisc");
   if (value >= 4) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(3));
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseMisc");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(3));
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseMisc (const char* name, e2ap_CauseMisc* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   switch (*pvalue) {

      case 0:
         stat = rtPrintToString (" = control-processing-overload\n", buffer, bufSize);
         break;

      case 1:
         stat = rtPrintToString (" = hardware-failure\n", buffer, bufSize);
         break;

      case 2:
         stat = rtPrintToString (" = om-intervention\n", buffer, bufSize);
         break;

      case 3:
         stat = rtPrintToString (" = unspecified\n", buffer, bufSize);
         break;

      default:
         stat = rtPrintToString (" = ???\n", buffer, bufSize);
   }
   return (stat < 0) ? -1 : 0;
}