
/*****************************************/
/*           RICserviceLoadInformation                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICserviceLoadInformation (OSCTXT* pctxt, e2ap_RICserviceLoadInformation* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceLoadInformation");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricServiceReportLoadInformation */  
   if (pvalue->m_ricServiceReportLoadInformationPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceReportLoadInformation");
   stat = asn1PE_e2ap_RICloadInformation (pctxt, &pvalue->ricServiceReportLoadInformation);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceInsertLoadInformation */  
   if (pvalue->m_ricServiceInsertLoadInformationPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceInsertLoadInformation");
   stat = asn1PE_e2ap_RICloadInformation (pctxt, &pvalue->ricServiceInsertLoadInformation);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceControlLoadInformation */  
   if (pvalue->m_ricServiceControlLoadInformationPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceControlLoadInformation");
   stat = asn1PE_e2ap_RICloadInformation (pctxt, &pvalue->ricServiceControlLoadInformation);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServicePolicyLoadInformation */  
   if (pvalue->m_ricServicePolicyLoadInformationPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServicePolicyLoadInformation");
   stat = asn1PE_e2ap_RICloadInformation (pctxt, &pvalue->ricServicePolicyLoadInformation);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceQueryLoadInformation */  
   if (pvalue->m_ricServiceQueryLoadInformationPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceQueryLoadInformation");
   stat = asn1PE_e2ap_RICloadInformation (pctxt, &pvalue->ricServiceQueryLoadInformation);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }


   /*
   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   */

   if(extbit) {
      /*encode extension optional bits length */
      stat = pe_SmallLength(pctxt, pvalue->extElem1.count);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode optional bit*/
      stat = pe_OpenTypeExtBits(pctxt, &pvalue->extElem1);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode extension elements*/
      if (pvalue->extElem1.count > 0) {
         stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_RICserviceLoadInformation (OSCTXT* pctxt, e2ap_RICserviceLoadInformation* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[5];

   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceLoadInformation");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 5; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field ricServiceReportLoadInformation */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceReportLoadInformation");
   if (optbits[0]) {
      pvalue->m_ricServiceReportLoadInformationPresent = TRUE;
      stat = asn1PD_e2ap_RICloadInformation (pctxt, &pvalue->ricServiceReportLoadInformation);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceReportLoadInformationPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceInsertLoadInformation */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceInsertLoadInformation");
   if (optbits[0]) {
      pvalue->m_ricServiceInsertLoadInformationPresent = TRUE;
      stat = asn1PD_e2ap_RICloadInformation (pctxt, &pvalue->ricServiceInsertLoadInformation);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceInsertLoadInformationPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceControlLoadInformation */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceControlLoadInformation");
   if (optbits[0]) {
      pvalue->m_ricServiceControlLoadInformationPresent = TRUE;
      stat = asn1PD_e2ap_RICloadInformation (pctxt, &pvalue->ricServiceControlLoadInformation);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceControlLoadInformationPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServicePolicyLoadInformation */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServicePolicyLoadInformation");
   if (optbits[0]) {
      pvalue->m_ricServicePolicyLoadInformationPresent = TRUE;
      stat = asn1PD_e2ap_RICloadInformation (pctxt, &pvalue->ricServicePolicyLoadInformation);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServicePolicyLoadInformationPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceQueryLoadInformation */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceQueryLoadInformation");
   if (optbits[0]) {
      pvalue->m_ricServiceQueryLoadInformationPresent = TRUE;
      stat = asn1PD_e2ap_RICloadInformation (pctxt, &pvalue->ricServiceQueryLoadInformation);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceQueryLoadInformationPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pdSmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFree(pctxt, poptbits);
            return LOG_RTERR(pctxt, stat);
         }
      }

      for(i_ = 0; i_ < bitcnt; i_++) {
         if(stat != 0) break;
         if(poptbits[i_]) {
            /*decode extension element*/
            stat = pd_OpenType (pctxt, &openType, &openType.numocts);

            if(0==stat){
               pOpenType = rtxMemAllocType(pctxt, ASN1OpenType);
               if(0!=pOpenType){
                  pOpenType->numocts = openType.numocts;
                  pOpenType->data = openType.data;
                  rtxDListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxDListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXTPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_RICserviceLoadInformation (e2ap_RICserviceLoadInformation* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RICloadInformation (&pvalue->ricServiceReportLoadInformation);
   asn1Init_e2ap_RICloadInformation (&pvalue->ricServiceInsertLoadInformation);
   asn1Init_e2ap_RICloadInformation (&pvalue->ricServiceControlLoadInformation);
   asn1Init_e2ap_RICloadInformation (&pvalue->ricServicePolicyLoadInformation);
   asn1Init_e2ap_RICloadInformation (&pvalue->ricServiceQueryLoadInformation);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICserviceLoadInformation (OSCTXT* pctxt, e2ap_RICserviceLoadInformation* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RICloadInformation (pctxt, &pvalue->ricServiceReportLoadInformation);
   asn1Free_e2ap_RICloadInformation (pctxt, &pvalue->ricServiceInsertLoadInformation);
   asn1Free_e2ap_RICloadInformation (pctxt, &pvalue->ricServiceControlLoadInformation);
   asn1Free_e2ap_RICloadInformation (pctxt, &pvalue->ricServicePolicyLoadInformation);
   asn1Free_e2ap_RICloadInformation (pctxt, &pvalue->ricServiceQueryLoadInformation);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICserviceLoadInformation (const char* name, e2ap_RICserviceLoadInformation* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadInformation ("ricServiceReportLoadInformation", &pvalue->ricServiceReportLoadInformation, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadInformation ("ricServiceInsertLoadInformation", &pvalue->ricServiceInsertLoadInformation, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadInformation ("ricServiceControlLoadInformation", &pvalue->ricServiceControlLoadInformation, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadInformation ("ricServicePolicyLoadInformation", &pvalue->ricServicePolicyLoadInformation, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadInformation ("ricServiceQueryLoadInformation", &pvalue->ricServiceQueryLoadInformation, buffer, bufSize) < 0)
   {
      return -1;
   }

   /*assum there is an extension*/
   if(rtPrintToStringOpenTypeExtBraceText("extElem1", &pvalue->extElem1, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}