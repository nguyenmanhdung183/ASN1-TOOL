/* e2ap_RICindicationType.c */
#include "e2ap_RICindicationType.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_RICindicationType_ENUMTAB[e2ap_RICindicationType_ENUMTABSIZE] = {
   { OSUTF8("report"), 0, 6,  },   { OSUTF8("insert"), 1, 6,  }};

EXTERN int asn1PE_e2ap_RICindicationType (OSCTXT* pctxt, e2ap_RICindicationType value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RICindicationType");
   if (value >= 2) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(1));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_RICindicationType (OSCTXT* pctxt, e2ap_RICindicationType* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RICindicationType");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(1));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_RICindicationType (const char* name, e2ap_RICindicationType* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_RICindicationType_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_RICindicationType_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}