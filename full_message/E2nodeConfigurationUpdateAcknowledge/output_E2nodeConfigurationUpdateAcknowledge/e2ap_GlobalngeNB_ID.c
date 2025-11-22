
/*****************************************/
/*           GlobalngeNB-ID                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "GlobalngeNB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field plmn_id */  

   RTXCTXTPUSHELEMNAME(pctxt, "plmn-id");
   stat = asn1PE_e2ap_PLMN_Identity (pctxt, &pvalue->plmn_id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field enb_id */  

   RTXCTXTPUSHELEMNAME(pctxt, "enb-id");
   stat = asn1PE_e2ap_ENB_ID_Choice (pctxt, &pvalue->enb_id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);



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

int asn1PD_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "GlobalngeNB-ID");

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
   /* decode field plmn_id */
   RTXCTXTPUSHELEMNAME(pctxt, "plmn-id");
      stat = asn1PD_e2ap_PLMN_Identity (pctxt, &pvalue->plmn_id);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field enb_id */
   RTXCTXTPUSHELEMNAME(pctxt, "enb-id");
      stat = asn1PD_e2ap_ENB_ID_Choice (pctxt, &pvalue->enb_id);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
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

int asn1Init_e2ap_GlobalngeNB_ID (e2ap_GlobalngeNB_ID* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_PLMN_Identity (&pvalue->plmn_id);
   asn1Init_e2ap_ENB_ID_Choice (&pvalue->enb_id);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_PLMN_Identity (pctxt, &pvalue->plmn_id);
   asn1Free_e2ap_ENB_ID_Choice (pctxt, &pvalue->enb_id);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_GlobalngeNB_ID (const char* name, e2ap_GlobalngeNB_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_PLMN_Identity ("plmn_id", &pvalue->plmn_id, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ENB_ID_Choice ("enb_id", &pvalue->enb_id, buffer, bufSize) < 0)
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