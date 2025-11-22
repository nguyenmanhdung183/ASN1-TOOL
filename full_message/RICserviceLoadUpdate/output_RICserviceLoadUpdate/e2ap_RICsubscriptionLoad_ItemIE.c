
/*****************************************/
/*           RICsubscriptionLoad-ItemIE                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICsubscriptionLoad_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_ItemIE* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICsubscriptionLoad-ItemIE");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricRequestID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricRequestID");
   stat = asn1PE_e2ap_RICrequestID (pctxt, &pvalue->ricRequestID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ricSubscriptionLoadInformation */  
   if (pvalue->m_ricSubscriptionLoadInformationPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricSubscriptionLoadInformation");
   stat = asn1PE_e2ap_RICloadInformation (pctxt, &pvalue->ricSubscriptionLoadInformation);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricActionLoad_list */  
   if (pvalue->m_ricActionLoad_listPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionLoad-list");
   stat = asn1PE_e2ap_RICactionLoad_List (pctxt, &pvalue->ricActionLoad_list);
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

int asn1PD_e2ap_RICsubscriptionLoad_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_ItemIE* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[3];

   RTXCTXTPUSHTYPENAME(pctxt, "RICsubscriptionLoad-ItemIE");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 3; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field ricRequestID */
   RTXCTXTPUSHELEMNAME(pctxt, "ricRequestID");
      stat = asn1PD_e2ap_RICrequestID (pctxt, &pvalue->ricRequestID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ricSubscriptionLoadInformation */
   RTXCTXTPUSHELEMNAME(pctxt, "ricSubscriptionLoadInformation");
   if (optbits[0]) {
      pvalue->m_ricSubscriptionLoadInformationPresent = TRUE;
      stat = asn1PD_e2ap_RICloadInformation (pctxt, &pvalue->ricSubscriptionLoadInformation);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricSubscriptionLoadInformationPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricActionLoad_list */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionLoad-list");
   if (optbits[0]) {
      pvalue->m_ricActionLoad_listPresent = TRUE;
      stat = asn1PD_e2ap_RICactionLoad_List (pctxt, &pvalue->ricActionLoad_list);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricActionLoad_listPresent = FALSE;
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

int asn1Init_e2ap_RICsubscriptionLoad_ItemIE (e2ap_RICsubscriptionLoad_ItemIE* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RICrequestID (&pvalue->ricRequestID);
   asn1Init_e2ap_RICloadInformation (&pvalue->ricSubscriptionLoadInformation);
   asn1Init_e2ap_RICactionLoad_List (&pvalue->ricActionLoad_list);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICsubscriptionLoad_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_ItemIE* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RICrequestID (pctxt, &pvalue->ricRequestID);
   asn1Free_e2ap_RICloadInformation (pctxt, &pvalue->ricSubscriptionLoadInformation);
   asn1Free_e2ap_RICactionLoad_List (pctxt, &pvalue->ricActionLoad_list);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICsubscriptionLoad_ItemIE (const char* name, e2ap_RICsubscriptionLoad_ItemIE* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICrequestID ("ricRequestID", &pvalue->ricRequestID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadInformation ("ricSubscriptionLoadInformation", &pvalue->ricSubscriptionLoadInformation, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICactionLoad_List ("ricActionLoad_list", &pvalue->ricActionLoad_list, buffer, bufSize) < 0)
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