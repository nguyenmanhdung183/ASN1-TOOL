/*****************************************/
/*         GNB-CU-UP-ID     */
/*****************************************/
//interger no ext

EXTERN int asn1PE_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "GNB-CU-UP-ID");
   stat = pe_ConsUnsigned (pctxt, value, 0, 68719476735);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "GNB-CU-UP-ID");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 64);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_GNB_CU_UP_ID (const char* name, e2ap_GNB_CU_UP_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}