/* e2ap_CauseMisc.c */
#include "e2ap_CauseMisc.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_CauseMisc_ENUMTAB[e2ap_CauseMisc_ENUMTABSIZE] = {
   { OSUTF8("control_processing_overload"), 0, 27,  },   { OSUTF8("hardware_failure"), 1, 16,  },   { OSUTF8("om_intervention"), 2, 15,  },   { OSUTF8("unspecified"), 3, 11,  }};

EXTERN int asn1PE_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseMisc");
   if (value >= 4) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(3));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseMisc");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(3));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseMisc (const char* name, e2ap_CauseMisc* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_CauseMisc_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_CauseMisc_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}