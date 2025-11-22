
/*****************************************/
/*           CriticalityDiagnostics-IE-List                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "CriticalityDiagnostics-IE-List");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field iECriticality */  

   RTXCTXTPUSHELEMNAME(pctxt, "iECriticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->iECriticality);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field iE_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "iE-ID");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->iE_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field typeOfError */  

   RTXCTXTPUSHELEMNAME(pctxt, "typeOfError");
   stat = asn1PE_e2ap_TypeOfError (pctxt, &pvalue->typeOfError);
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

int asn1PD_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[3];

   RTXCTXTPUSHTYPENAME(pctxt, "CriticalityDiagnostics-IE-List");

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
   /* decode field iECriticality */
   RTXCTXTPUSHELEMNAME(pctxt, "iECriticality");
      stat = asn1PD_e2ap_Criticality (pctxt, &pvalue->iECriticality);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field iE_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "iE-ID");
      stat = asn1PD_e2ap_ProtocolIE_ID (pctxt, &pvalue->iE_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field typeOfError */
   RTXCTXTPUSHELEMNAME(pctxt, "typeOfError");
      stat = asn1PD_e2ap_TypeOfError (pctxt, &pvalue->typeOfError);
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

int asn1Init_e2ap_CriticalityDiagnostics_IE_List (e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_Criticality (&pvalue->iECriticality);
   asn1Init_e2ap_ProtocolIE_ID (&pvalue->iE_ID);
   asn1Init_e2ap_TypeOfError (&pvalue->typeOfError);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_Criticality (pctxt, &pvalue->iECriticality);
   asn1Free_e2ap_ProtocolIE_ID (pctxt, &pvalue->iE_ID);
   asn1Free_e2ap_TypeOfError (pctxt, &pvalue->typeOfError);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_CriticalityDiagnostics_IE_List (const char* name, e2ap_CriticalityDiagnostics_IE_List* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_Criticality ("iECriticality", &pvalue->iECriticality, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ProtocolIE_ID ("iE_ID", &pvalue->iE_ID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_TypeOfError ("typeOfError", &pvalue->typeOfError, buffer, bufSize) < 0)
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