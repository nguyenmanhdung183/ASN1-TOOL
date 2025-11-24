/*****************************************/
/*           ServiceLayerCause                */
/*****************************************/

//9 mau octet string


//type 9  mau la octet string mau la pdusessioncommonnetworkinstance

EXTERN int asn1PE_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause value){
   int stat = 0
   RTXCTCXTPUSHTYPENAME (pctxt, "ServiceLayerCause");
   stat = pe_OctetString(pctxt, value.numocts, value.data);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);

}
EXTERN int asn1PD_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause* pvalue){
   int stat = 0;
   RTXCTCXTPUSHTYPENAME (pctxt, "ServiceLayerCause");
   stat = pd_DynOctetString(pctxt, pvalue);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}
//EXTERN int asn1PrtToStr_e2ap_ServiceLayerCause (const char* name, e2ap_ServiceLayerCause *pvalue, char* buffer, OSSIZE bufSize);
//EXTERN int asn1PrtToStrm_e2ap_ServiceLayerCause (OSCTXT* pctxt, const char* name, const e2ap_ServiceLayerCause* pvalue);
//EXTERN int asn1Copy_e2ap_ServiceLayerCause (OSCTXT* pctxt, const e2ap_ServiceLayerCause* pSrcValue, e2ap_ServiceLayerCause* pDstValue);
 int asn1Init_e2ap_ServiceLayerCause (e2ap_ServiceLayerCause* pvalue){
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->numocts = 0;
   pvalue->data = 0;
   return 0;
}
 void asn1Free_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause* pvalue){
   if (pvalue == 0) return;
   if(pvalue->numocts>0){
       rtxMemFreePtr(pctxt, (void*)pvalue->data);
       pvalue->data = 0;
       pvalue->numocts = 0;
   }
}

