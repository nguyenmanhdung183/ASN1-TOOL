/*****************************************/
/*           TransactionID                */
/*****************************************/
//interger with ext


EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value)
{ 
   RTXCTXTPUSHTYPENAME (pctxt, "TransactionID");

   OSBOOL exbit = (value > 255) ? TRUE : FALSE;
   int stat = rtxEncBit (pctxt, exbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!exbit) {
      stat = pe_ConsUnsigned (pctxt, value, 0, 255);
   } else {
      stat = pe_UnconsUnsigned (pctxt, value);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME (pctxt, "TransactionID");
   stat = rtxDecBit (pctxt, &extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!extbit) {
      stat = pd_ConsUnsigned (pctxt, pvalue, 0, 255);
   } else {
      stat = pd_UnconsUnsigned (pctxt, pvalue);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

EXTERN int asn1PrtToStr_e2ap_TransactionID (const char* name, e2ap_TransactionID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}