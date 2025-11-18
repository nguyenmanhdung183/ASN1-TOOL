/* e2ap_CauseProtocol.c */
#include "e2ap_CauseProtocol.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_CauseProtocol_ENUMTAB[e2ap_CauseProtocol_ENUMTABSIZE] = {
   { OSUTF8("transfer_syntax_error"), 0, 21,  },   { OSUTF8("abstract_syntax_error_reject"), 1, 28,  },   { OSUTF8("abstract_syntax_error_ignore_and_notify"), 2, 39,  },   { OSUTF8("message_not_compatible_with_receiver_state"), 3, 42,  },   { OSUTF8("©2025bytheO_RANALLIANCEe.V.Youruseissubjecttothecopyrightstatementonthecoverpageofthisspecification.142O_RAN.WG3.TS.E2AP_R004_v07.00semantic_error"), 4, 146,  },   { OSUTF8("abstract_syntax_error_falsely_constructed_message"), 5, 49,  },   { OSUTF8("unspecified"), 6, 11,  }};

EXTERN int asn1PE_e2ap_CauseProtocol (OSCTXT* pctxt, e2ap_CauseProtocol value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseProtocol");
   if (value >= 7) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(6));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_CauseProtocol (OSCTXT* pctxt, e2ap_CauseProtocol* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseProtocol");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(6));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseProtocol (const char* name, e2ap_CauseProtocol* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_CauseProtocol_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_CauseProtocol_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}