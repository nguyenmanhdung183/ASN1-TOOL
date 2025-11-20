
/*****************************************/
/*           E2nodeComponentConfigurationAck                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentConfigurationAck");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field updateOutcome */  

   RTXCTXTPUSHELEMNAME(pctxt, "updateOutcome");
   stat = asn1PE_e2ap_updateOutcome (pctxt, &pvalue->updateOutcome);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field failure */  

   RTXCTXTPUSHELEMNAME(pctxt, "failure");
   stat = asn1PE_e2ap_failure (pctxt, &pvalue->failure);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field failureCause */  
   if (pvalue->m_failureCausePresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "failureCause");
   stat = asn1PE_e2ap_Cause (pctxt, &pvalue->failureCause);
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

int asn1PD_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentConfigurationAck");

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
   /* decode field updateOutcome */
   RTXCTXTPUSHELEMNAME(pctxt, "updateOutcome");
      stat = asn1PD_e2ap_updateOutcome (pctxt, &pvalue->updateOutcome);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field failure */
   RTXCTXTPUSHELEMNAME(pctxt, "failure");
      stat = asn1PD_e2ap_failure (pctxt, &pvalue->failure);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field failureCause */
   RTXCTXTPUSHELEMNAME(pctxt, "failureCause");
   if (optbits[0]) {
      pvalue->m_failureCausePresent = TRUE;
      stat = asn1PD_e2ap_Cause (pctxt, &pvalue->failureCause);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_failureCausePresent = FALSE;
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

int asn1Init_e2ap_E2nodeComponentConfigurationAck (e2ap_E2nodeComponentConfigurationAck* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_updateOutcome (&pvalue->updateOutcome);
   asn1Init_e2ap_failure (&pvalue->failure);
   asn1Init_e2ap_Cause (&pvalue->failureCause);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_updateOutcome (pctxt, &pvalue->updateOutcome);
   asn1Free_e2ap_failure (pctxt, &pvalue->failure);
   asn1Free_e2ap_Cause (pctxt, &pvalue->failureCause);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentConfigurationAck (const char* name, e2ap_E2nodeComponentConfigurationAck* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_updateOutcome ("updateOutcome", &pvalue->updateOutcome, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_failure ("failure", &pvalue->failure, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_Cause ("failureCause", &pvalue->failureCause, buffer, bufSize) < 0)
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