/* e2ap_TriggeringMessage.c */
#include "e2ap_TriggeringMessage.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_TriggeringMessage_ENUMTAB[e2ap_TriggeringMessage_ENUMTABSIZE] = {
   { OSUTF8("initiating_message"), 0, 18,  },   { OSUTF8("successful_outcome"), 1, 18,  },   { OSUTF8("unsuccessfull_outcome"), 2, 21,  }};

EXTERN int asn1PE_e2ap_TriggeringMessage (OSCTXT* pctxt, e2ap_TriggeringMessage value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "TriggeringMessage");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_TriggeringMessage (OSCTXT* pctxt, e2ap_TriggeringMessage* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "TriggeringMessage");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_TriggeringMessage (const char* name, e2ap_TriggeringMessage* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_TriggeringMessage_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_TriggeringMessage_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}