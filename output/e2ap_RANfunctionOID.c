/* e2ap_RANfunctionOID.c */
#include "e2ap_RANfunctionOID.h"
#include "rtxsrc/rtxErrCodes.h"
#include "rtxsrc/rtxCharStr.h"
#include "rtxsrc/rtxMemBuf.h"

/* Constrained PrintableString */
EXTERN int asn1PE_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionOID");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(1000), OSUINTCONST(0), OSUINT32_MAX);

   char c = (char) rtValidateStr (19, value);  /* 19 = PrintableString */
   if (c != 0) {
      char lbuf[2];
      lbuf[0] = c;
      lbuf[1] = 0;
      rtxErrAddStrnParm (pctxt, lbuf);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   stat = pe_ConstrainedStringEx (pctxt, value, 0, 8, 7, 7);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID* ppvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionOID");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(1000), OSUINTCONST(0), OSUINT32_MAX);

   stat = pd_ConstrainedStringEx (pctxt, ppvalue, 0, 8, 7, 7);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}


void asn1Free_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID pvalue)
{
   if (pvalue) rtxMemFreePtr (pctxt, (void*)pvalue);
}

/* Print to string */
int asn1PrtToStr_e2ap_RANfunctionOID (const char* name, e2ap_RANfunctionOID pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringStr (name, pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}