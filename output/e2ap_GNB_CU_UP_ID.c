/* e2ap_GNB_CU_UP_ID.c */
#include "e2ap_GNB_CU_UP_ID.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GNB_CU_UP_ID");
   stat = pe_ConsUnsigned (pctxt, value, nan, 68719476735.0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GNB_CU_UP_ID");
   if (pctxt->buffer.aligned) {
      int stat2 = pd_ByteAlign (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 64);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_GNB_CU_UP_ID (const char* name, e2ap_GNB_CU_UP_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}