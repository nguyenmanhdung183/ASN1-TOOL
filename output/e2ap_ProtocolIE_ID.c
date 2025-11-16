/* e2ap_ProtocolIE_ID.c */
#include "e2ap_ProtocolIE_ID.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_ProtocolIE_ID (OSCTXT* pctxt, e2ap_ProtocolIE_ID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "ProtocolIE_ID");
   stat = pe_ConsUnsigned (pctxt, value, 0.0, 65535.0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_ProtocolIE_ID (OSCTXT* pctxt, e2ap_ProtocolIE_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "ProtocolIE_ID");
   if (pctxt->buffer.aligned) {
      int stat2 = pd_ByteAlign (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 16);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_ProtocolIE_ID (const char* name, e2ap_ProtocolIE_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}