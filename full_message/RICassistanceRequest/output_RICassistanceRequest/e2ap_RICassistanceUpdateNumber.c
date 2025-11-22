/*****************************************/
/*         RICassistanceUpdateNumber     */
/*****************************************/
//interger no ext

EXTERN int asn1PE_e2ap_RICassistanceUpdateNumber (OSCTXT* pctxt, e2ap_RICassistanceUpdateNumber value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICassistanceUpdateNumber");
   stat = pe_ConsUnsigned (pctxt, value, 0, 65535);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RICassistanceUpdateNumber (OSCTXT* pctxt, e2ap_RICassistanceUpdateNumber* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICassistanceUpdateNumber");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 16);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RICassistanceUpdateNumber (const char* name, e2ap_RICassistanceUpdateNumber* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}