/* e2ap_RANfunctionRevision.c */


//interger no ext
/*****************************************/
/*         RANfunctionRevision     */
/*****************************************/

EXTERN int asn1PE_e2ap_RANfunctionRevision (OSCTXT* pctxt, e2ap_RANfunctionRevision value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionRevision");
   stat = pe_ConsUnsigned (pctxt, value, 0, 4095);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RANfunctionRevision (OSCTXT* pctxt, e2ap_RANfunctionRevision* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionRevision");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 16);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RANfunctionRevision (const char* name, e2ap_RANfunctionRevision* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}