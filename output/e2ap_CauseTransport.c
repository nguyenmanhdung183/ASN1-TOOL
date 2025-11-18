/* e2ap_CauseTransport.c */
#include "e2ap_CauseTransport.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_CauseTransport_ENUMTAB[e2ap_CauseTransport_ENUMTABSIZE] = {
   { OSUTF8("unspecified"), 0, 11,  },   { OSUTF8("transport_resource_unavailable"), 1, 30,  }};

EXTERN int asn1PE_e2ap_CauseTransport (OSCTXT* pctxt, e2ap_CauseTransport value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseTransport");
   if (value >= 2) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(1));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_CauseTransport (OSCTXT* pctxt, e2ap_CauseTransport* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseTransport");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(1));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseTransport (const char* name, e2ap_CauseTransport* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_CauseTransport_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_CauseTransport_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}