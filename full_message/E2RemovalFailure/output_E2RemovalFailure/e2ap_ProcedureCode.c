/*****************************************/
/*         ProcedureCode     */
/*****************************************/
//interger no ext

EXTERN int asn1PE_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "ProcedureCode");
   stat = pe_ConsUnsigned (pctxt, value, 0, 255);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "ProcedureCode");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 8);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_ProcedureCode (const char* name, e2ap_ProcedureCode* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}