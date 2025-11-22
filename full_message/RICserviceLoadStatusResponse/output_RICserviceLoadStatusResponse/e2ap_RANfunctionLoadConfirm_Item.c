
/*****************************************/
/*           RANfunctionLoadConfirm-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RANfunctionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RANfunctionLoadConfirm-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ranFunctionID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionID");
   stat = asn1PE_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ranFunctionLoadConfirm */  
   if (pvalue->m_ranFunctionLoadConfirmPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionLoadConfirm");
   stat = asn1PE_e2ap_RICloadConfirm (pctxt, &pvalue->ranFunctionLoadConfirm);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceLoadConfirm */  
   if (pvalue->m_ricServiceLoadConfirmPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceLoadConfirm");
   stat = asn1PE_e2ap_RICserviceLoadConfirm (pctxt, &pvalue->ricServiceLoadConfirm);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricSubscriptionLoadConfirm_list */  
   if (pvalue->m_ricSubscriptionLoadConfirm_listPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricSubscriptionLoadConfirm-list");
   stat = asn1PE_e2ap_RICsubscriptionLoadConfirm_List (pctxt, &pvalue->ricSubscriptionLoadConfirm_list);
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

int asn1PD_e2ap_RANfunctionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[4];

   RTXCTXTPUSHTYPENAME(pctxt, "RANfunctionLoadConfirm-Item");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 4; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field ranFunctionID */
   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionID");
      stat = asn1PD_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ranFunctionLoadConfirm */
   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionLoadConfirm");
   if (optbits[0]) {
      pvalue->m_ranFunctionLoadConfirmPresent = TRUE;
      stat = asn1PD_e2ap_RICloadConfirm (pctxt, &pvalue->ranFunctionLoadConfirm);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ranFunctionLoadConfirmPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceLoadConfirm */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceLoadConfirm");
   if (optbits[0]) {
      pvalue->m_ricServiceLoadConfirmPresent = TRUE;
      stat = asn1PD_e2ap_RICserviceLoadConfirm (pctxt, &pvalue->ricServiceLoadConfirm);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceLoadConfirmPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricSubscriptionLoadConfirm_list */
   RTXCTXTPUSHELEMNAME(pctxt, "ricSubscriptionLoadConfirm-list");
   if (optbits[0]) {
      pvalue->m_ricSubscriptionLoadConfirm_listPresent = TRUE;
      stat = asn1PD_e2ap_RICsubscriptionLoadConfirm_List (pctxt, &pvalue->ricSubscriptionLoadConfirm_list);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricSubscriptionLoadConfirm_listPresent = FALSE;
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

int asn1Init_e2ap_RANfunctionLoadConfirm_Item (e2ap_RANfunctionLoadConfirm_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RANfunctionID (&pvalue->ranFunctionID);
   asn1Init_e2ap_RICloadConfirm (&pvalue->ranFunctionLoadConfirm);
   asn1Init_e2ap_RICserviceLoadConfirm (&pvalue->ricServiceLoadConfirm);
   asn1Init_e2ap_RICsubscriptionLoadConfirm_List (&pvalue->ricSubscriptionLoadConfirm_list);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RANfunctionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   asn1Free_e2ap_RICloadConfirm (pctxt, &pvalue->ranFunctionLoadConfirm);
   asn1Free_e2ap_RICserviceLoadConfirm (pctxt, &pvalue->ricServiceLoadConfirm);
   asn1Free_e2ap_RICsubscriptionLoadConfirm_List (pctxt, &pvalue->ricSubscriptionLoadConfirm_list);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RANfunctionLoadConfirm_Item (const char* name, e2ap_RANfunctionLoadConfirm_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RANfunctionID ("ranFunctionID", &pvalue->ranFunctionID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadConfirm ("ranFunctionLoadConfirm", &pvalue->ranFunctionLoadConfirm, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICserviceLoadConfirm ("ricServiceLoadConfirm", &pvalue->ricServiceLoadConfirm, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICsubscriptionLoadConfirm_List ("ricSubscriptionLoadConfirm_list", &pvalue->ricSubscriptionLoadConfirm_list, buffer, bufSize) < 0)
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