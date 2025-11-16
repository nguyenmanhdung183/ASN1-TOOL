/* e2ap_Criticality.c */
#include "e2ap_Criticality.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_Criticality_ENUMTAB[e2ap_Criticality_ENUMTABSIZE] = {
   { OSUTF8("reject"), 0, 6,  },   { OSUTF8("ignore"), 1, 6,  },   { OSUTF8("notify"), 2, 6,  }};

EXTERN int asn1PE_e2ap_Criticality (OSCTXT* pctxt, e2ap_Criticality value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "Criticality");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_Criticality (OSCTXT* pctxt, e2ap_Criticality* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "Criticality");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_Criticality (const char* name, e2ap_Criticality* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_Criticality_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_Criticality_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}