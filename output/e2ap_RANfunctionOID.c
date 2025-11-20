/* e2ap_RANfunctionOID.c */

//printable string
/*****************************************/
/*           RANfunctionOID                */
/*****************************************/

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

      rtxErrAddEleNameParm(pctxt);
      rtxErrAddStrParm (pctxt, lbuf);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   stat = pe_ConstrainedStringEx (pctxt, value, 0, 8, 7, 7);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID* ppvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionOID");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(1000), OSUINTCONST(0), OSUINT32_MAX);

   stat = pd_ConstrainedStringEx (pctxt, ppvalue, 0, 8, 7, 7);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}


void asn1Free_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID pvalue)
{
   if(0==pvalue) return;
   rtxMemFreePtr (pctxt, (void*)pvalue);
   pvalue = 0;
}

/* Print to string */
int asn1PrtToStr_e2ap_RANfunctionOID (const char* name, e2ap_RANfunctionOID pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringCharStr (name, pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}