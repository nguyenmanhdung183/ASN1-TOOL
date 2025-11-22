
/*****************************************/
/*           E2nodeComponentInterfaceX2                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceX2");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field global_eNB_ID */  
   if (pvalue->m_global_eNB_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "global-eNB-ID");
   stat = asn1PE_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field global_en_gNB_ID */  
   if (pvalue->m_global_en_gNB_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "global-en-gNB-ID");
   stat = asn1PE_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
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

int asn1PD_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceX2");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 2; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field global_eNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-eNB-ID");
   if (optbits[0]) {
      pvalue->m_global_eNB_IDPresent = TRUE;
      stat = asn1PD_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_global_eNB_IDPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field global_en_gNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-en-gNB-ID");
   if (optbits[0]) {
      pvalue->m_global_en_gNB_IDPresent = TRUE;
      stat = asn1PD_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_global_en_gNB_IDPresent = FALSE;
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

int asn1Init_e2ap_E2nodeComponentInterfaceX2 (e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_GlobalENB_ID (&pvalue->global_eNB_ID);
   asn1Init_e2ap_GlobalenGNB_ID (&pvalue->global_en_gNB_ID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
   asn1Free_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentInterfaceX2 (const char* name, e2ap_E2nodeComponentInterfaceX2* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GlobalENB_ID ("global_eNB_ID", &pvalue->global_eNB_ID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GlobalenGNB_ID ("global_en_gNB_ID", &pvalue->global_en_gNB_ID, buffer, bufSize) < 0)
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