/* e2ap_RANfunctionID.c */


//interger no ext
/*****************************************/
/*         RANfunctionID     */
/*****************************************/

EXTERN int asn1PE_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionID");
   stat = pe_ConsUnsigned (pctxt, value, 0, 4095);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionID");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 16);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RANfunctionID (const char* name, e2ap_RANfunctionID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}