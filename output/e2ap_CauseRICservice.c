/* e2ap_CauseRICservice.c */
#include "e2ap_CauseRICservice.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_CauseRICservice_ENUMTAB[e2ap_CauseRICservice_ENUMTABSIZE] = {
   { OSUTF8("ran_function_not_supported"), 0, 26,  },   { OSUTF8("excessive_functions"), 1, 19,  },   { OSUTF8("ric_resource_limit"), 2, 18,  }};

EXTERN int asn1PE_e2ap_CauseRICservice (OSCTXT* pctxt, e2ap_CauseRICservice value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseRICservice");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_CauseRICservice (OSCTXT* pctxt, e2ap_CauseRICservice* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseRICservice");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseRICservice (const char* name, e2ap_CauseRICservice* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_CauseRICservice_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_CauseRICservice_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}