/*****************************************/
/*           RANfunctionDefinition                */
/*****************************************/
//octet string

/* Dynamic OCTET STRING (no SIZE constraint) */
EXTERN int asn1PE_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition* pvalue)
{
   int stat = 0;
  
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionDefinition");
   
   stat = pe_OctetString (pctxt, pvalue->numocts, pvalue->data);
 
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition** ppvalue)
{
   int stat = 0;
  
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionDefinition");
 
   stat = pd_DynOctetString (pctxt, (OSDynOctStr**)ppvalue);
   
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

int asn1Init_e2ap_RANfunctionDefinition (e2ap_RANfunctionDefinition* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->numocts = 0;
   pvalue->data = 0;
   return 0;
}

void asn1Free_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition* pvalue)
{
   if (pvalue == 0) return;
   if (pvalue->numocts > 0 && pvalue->data != 0) {
      rtxMemFreePtr (pctxt, (void*)pvalue->data);
   }
   pvalue->numocts = 0;
   pvalue->data = 0;
}


/* Print to string */
int asn1PrtToStr_e2ap_RANfunctionDefinition (const char* name, e2ap_RANfunctionDefinition* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) {
      return -1;
   }
   if (rtPrintToStringHexStr (name, pvalue->numocts, pvalue->data, buffer, bufSize) < 0){
      return -1;
   }
   return 0;
}