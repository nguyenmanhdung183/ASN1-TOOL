
/*****************************************/
/*           GlobalE2node-en-gNB-ID                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node-en-gNB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field global_en_gNB_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "global-en-gNB-ID");
   stat = asn1PE_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field en_gNB_CU_UP_ID */  
   if (pvalue->m_en_gNB_CU_UP_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "en-gNB-CU-UP-ID");
   stat = asn1PE_e2ap_GNB_CU_UP_ID (pctxt, &pvalue->en_gNB_CU_UP_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field en_gNB_DU_ID */  
   if (pvalue->m_en_gNB_DU_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "en-gNB-DU-ID");
   stat = asn1PE_e2ap_GNB_DU_ID (pctxt, &pvalue->en_gNB_DU_ID);
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

   RTXCTXPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node-en-gNB-ID");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 1; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field global_en_gNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-en-gNB-ID");
      stat = asn1PD_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field en_gNB_CU_UP_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "en-gNB-CU-UP-ID");
   if (optbits[0]) {
      pvalue->m_en_gNB_CU_UP_IDPresent = TRUE;
      stat = asn1PD_e2ap_GNB_CU_UP_ID (pctxt, &pvalue->en_gNB_CU_UP_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_en_gNB_CU_UP_IDPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field en_gNB_DU_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "en-gNB-DU-ID");
   if (optbits[0]) {
      pvalue->m_en_gNB_DU_IDPresent = TRUE;
      stat = asn1PD_e2ap_GNB_DU_ID (pctxt, &pvalue->en_gNB_DU_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_en_gNB_DU_IDPresent = FALSE;
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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_GlobalE2node_en_gNB_ID (e2ap_GlobalE2node_en_gNB_ID* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_GlobalenGNB_ID (&pvalue->global_en_gNB_ID);
   asn1Init_e2ap_GNB_CU_UP_ID (&pvalue->en_gNB_CU_UP_ID);
   asn1Init_e2ap_GNB_DU_ID (&pvalue->en_gNB_DU_ID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
   asn1Free_e2ap_GNB_CU_UP_ID (pctxt, &pvalue->en_gNB_CU_UP_ID);
   asn1Free_e2ap_GNB_DU_ID (pctxt, &pvalue->en_gNB_DU_ID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_GlobalE2node_en_gNB_ID (const char* name, e2ap_GlobalE2node_en_gNB_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GlobalenGNB_ID ("global_en_gNB_ID", &pvalue->global_en_gNB_ID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GNB_CU_UP_ID ("en_gNB_CU_UP_ID", &pvalue->en_gNB_CU_UP_ID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GNB_DU_ID ("en_gNB_DU_ID", &pvalue->en_gNB_DU_ID, buffer, bufSize) < 0)
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