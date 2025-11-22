/*****************************************/
/*           RICsubscriptionTime                */
/*****************************************/
//octet string

/* Fixed SIZE OCTET STRING */
EXTERN int asn1PE_e2ap_RICsubscriptionTime (OSCTXT* pctxt, e2ap_RICsubscriptionTime* pvalue)
{
   int stat = 0;
 
   RTXCTXTPUSHTYPENAME (pctxt, "RICsubscriptionTime");
  
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(8), OSUINTCONST(8), 0, 0);
  
   stat = pe_OctetString (pctxt, pvalue->numocts, pvalue->data);

   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RICsubscriptionTime (OSCTXT* pctxt, e2ap_RICsubscriptionTime* pvalue)
{
   int stat = 0;
  
   RTXCTXTPUSHTYPENAME (pctxt, "RICsubscriptionTime");
  
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(8), OSUINTCONST(8), 0, 0);
  
   stat = pd_OctetString (pctxt, &pvalue->numocts, pvalue->data, sizeof(pvalue->data));

   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

int asn1Init_e2ap_RICsubscriptionTime (e2ap_RICsubscriptionTime* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->numocts = 0;
   return 0;
}

void asn1Free_e2ap_RICsubscriptionTime (OSCTXT* pctxt, e2ap_RICsubscriptionTime* pvalue)
{
   if(0==pvalue) return;
   if(pvalue->numocts > 0){
      rtxMemFreePtr(pctxt, (void*)pvalue->data);
      pvalue->numocts=0;
   }
}

/* Print to string */
int asn1PrtToStr_e2ap_RICsubscriptionTime (const char* name, e2ap_RICsubscriptionTime* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) {
      return -1;
   }
   if (rtPrintToStringHexStr (name, pvalue->numocts, pvalue->data, buffer, bufSize) < 0){
      return -1;
   }
   return 0;
}