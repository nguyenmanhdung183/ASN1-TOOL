
/*****************************************/
/*           RICserviceLoadRequest                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, e2ap_RICserviceLoadRequest* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceLoadRequest");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricServiceReportLoadRequest */  
   if (pvalue->m_ricServiceReportLoadRequestPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceReportLoadRequest");
   stat = asn1PE_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceReportLoadRequest);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceInsertLoadRequest */  
   if (pvalue->m_ricServiceInsertLoadRequestPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceInsertLoadRequest");
   stat = asn1PE_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceInsertLoadRequest);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceControlLoadRequest */  
   if (pvalue->m_ricServiceControlLoadRequestPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceControlLoadRequest");
   stat = asn1PE_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceControlLoadRequest);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServicePolicyLoadRequest */  
   if (pvalue->m_ricServicePolicyLoadRequestPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServicePolicyLoadRequest");
   stat = asn1PE_e2ap_RICloadRequest (pctxt, &pvalue->ricServicePolicyLoadRequest);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceQueryLoadRequest */  
   if (pvalue->m_ricServiceQueryLoadRequestPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceQueryLoadRequest");
   stat = asn1PE_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceQueryLoadRequest);
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

int asn1PD_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, e2ap_RICserviceLoadRequest* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[5];

   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceLoadRequest");

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
   /* decode field ricServiceReportLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceReportLoadRequest");
   if (optbits[0]) {
      pvalue->m_ricServiceReportLoadRequestPresent = TRUE;
      stat = asn1PD_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceReportLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceReportLoadRequestPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceInsertLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceInsertLoadRequest");
   if (optbits[0]) {
      pvalue->m_ricServiceInsertLoadRequestPresent = TRUE;
      stat = asn1PD_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceInsertLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceInsertLoadRequestPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceControlLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceControlLoadRequest");
   if (optbits[0]) {
      pvalue->m_ricServiceControlLoadRequestPresent = TRUE;
      stat = asn1PD_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceControlLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceControlLoadRequestPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServicePolicyLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServicePolicyLoadRequest");
   if (optbits[0]) {
      pvalue->m_ricServicePolicyLoadRequestPresent = TRUE;
      stat = asn1PD_e2ap_RICloadRequest (pctxt, &pvalue->ricServicePolicyLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServicePolicyLoadRequestPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceQueryLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceQueryLoadRequest");
   if (optbits[0]) {
      pvalue->m_ricServiceQueryLoadRequestPresent = TRUE;
      stat = asn1PD_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceQueryLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceQueryLoadRequestPresent = FALSE;
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

int asn1Init_e2ap_RICserviceLoadRequest (e2ap_RICserviceLoadRequest* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RICloadRequest (&pvalue->ricServiceReportLoadRequest);
   asn1Init_e2ap_RICloadRequest (&pvalue->ricServiceInsertLoadRequest);
   asn1Init_e2ap_RICloadRequest (&pvalue->ricServiceControlLoadRequest);
   asn1Init_e2ap_RICloadRequest (&pvalue->ricServicePolicyLoadRequest);
   asn1Init_e2ap_RICloadRequest (&pvalue->ricServiceQueryLoadRequest);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, e2ap_RICserviceLoadRequest* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceReportLoadRequest);
   asn1Free_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceInsertLoadRequest);
   asn1Free_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceControlLoadRequest);
   asn1Free_e2ap_RICloadRequest (pctxt, &pvalue->ricServicePolicyLoadRequest);
   asn1Free_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceQueryLoadRequest);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICserviceLoadRequest (const char* name, e2ap_RICserviceLoadRequest* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadRequest ("ricServiceReportLoadRequest", &pvalue->ricServiceReportLoadRequest, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadRequest ("ricServiceInsertLoadRequest", &pvalue->ricServiceInsertLoadRequest, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadRequest ("ricServiceControlLoadRequest", &pvalue->ricServiceControlLoadRequest, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadRequest ("ricServicePolicyLoadRequest", &pvalue->ricServicePolicyLoadRequest, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadRequest ("ricServiceQueryLoadRequest", &pvalue->ricServiceQueryLoadRequest, buffer, bufSize) < 0)
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