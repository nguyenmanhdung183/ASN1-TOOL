/* e2ap_ENB_ID.c */

/*****************************************/
/*           ENB_ID                */
/*****************************************/
// choice

// choice with extension typefef từ 1
EXTERN int asn1PE_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "ENB-ID");

   extbit = (OSBOOL)(pvalue->t > 3);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   if(!extbit){
      RTXCTXPUSHELEMNAME (pctxt, "t");

      stat = rtxEncBits (pctxt, pvalue->t - 1, 2);// kha nang la numbits
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      RTXCTXPOPELEMNAME (pctxt);

      switch (pvalue->t) {
      case 0:
         RTXCTXPUSHELEMNAME (pctxt, "macro-eNB-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.macro_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "home-eNB-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.home_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXPUSHELEMNAME (pctxt, "short-Macro-eNB-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.short_Macro_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXPUSHELEMNAME (pctxt, "long-Macro-eNB-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.long_Macro_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
      }
   }else{
      stat = pe_SmallNonNegWholeNumber (pctxt, pvalue->t - 4);// can xem lai
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      RTXCTXPUSHELEMNAME (pctxt, "...");
      stat = pe_OpenType (pctxt, pvalue->u.extElem1->numocts, pvalue->u.extElem1->data);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      RTXCTXPOPELEMNAME (pctxt);
   }
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "ENB_ID");

   stat = DECBIT (pctxt, &extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   if(!extbit){
      stat = rtxDecBits (pctxt, &ui, 2);// kha nang la numbits
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      else pvalue->t = ui + 1;

      switch (ui)
      {
      case 0:
         RTXCTXPUSHELEMNAME (pctxt, "macro-eNB-ID");

         pvalue->u.macro_eNB_ID = rtxMemAllocType (pctxt, ASN1BitStr32);

         if (pvalue->u.macro_eNB_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_ASN1BitStr32(pvalue->u.macro_eNB_ID);
         //stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.macro_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "home-eNB-ID");

         pvalue->u.home_eNB_ID = rtxMemAllocType (pctxt, ASN1BitStr32);

         if (pvalue->u.home_eNB_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_ASN1BitStr32(pvalue->u.home_eNB_ID);
         //stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.home_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXPUSHELEMNAME (pctxt, "short-Macro-eNB-ID");

         pvalue->u.short_Macro_eNB_ID = rtxMemAllocType (pctxt, ASN1BitStr32);

         if (pvalue->u.short_Macro_eNB_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_ASN1BitStr32(pvalue->u.short_Macro_eNB_ID);
         //stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.short_Macro_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXPUSHELEMNAME (pctxt, "long-Macro-eNB-ID");

         pvalue->u.long_Macro_eNB_ID = rtxMemAllocType (pctxt, ASN1BitStr32);

         if (pvalue->u.long_Macro_eNB_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_ASN1BitStr32(pvalue->u.long_Macro_eNB_ID);
         //stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.long_Macro_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
      }
   }else{
      stat = pd_SmallNonNegWholeNumber (pctxt, &ui);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      else pvalue->t = ui + 5;
      if(pvalue->t < 5){
         return LOG_RTERR (pctxt, RTERR_INVOPT);
      }
      stat = PD_BYTE_ALIGN (pctxt);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      RTXCTXPUSHELEMNAME (pctxt, "...");
      stat = pd_OpenType (pctxt, &openType);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      pvalue->u.extElem1 = rtxMemAllocType (pctxt, ASN1OpenType);
      if (pvalue->u.extElem1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
      pvalue->u.extElem1->numocts = openType.numocts;
      pvalue->u.extElem1->data = openType.data;
      RTXCTXPOPELEMNAME (pctxt);
   }
   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1Init_e2ap_ENB_ID (e2ap_ENB_ID* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->t = 0;
   OSRTLMEMSET (&pvalue->u, 0, sizeof(pvalue->u));
   return 0;
}

void asn1Free_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue)
{
   if (pvalue == 0) return;
   switch (pvalue->t) {
      case 0: //no choice nothing to free
         break;
      case 1:
         if (pvalue->u.macro_eNB_ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.macro_eNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.macro_eNB_ID);
            pvalue->u.macro_eNB_ID = 0;
         }
         break;
      case 2:
         if (pvalue->u.home_eNB_ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.home_eNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.home_eNB_ID);
            pvalue->u.home_eNB_ID = 0;
         }
         break;
      case 3:
         if (pvalue->u.short_Macro_eNB_ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.short_Macro_eNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.short_Macro_eNB_ID);
            pvalue->u.short_Macro_eNB_ID = 0;
         }
         break;
      case 4:
         if (pvalue->u.long_Macro_eNB_ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.long_Macro_eNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.long_Macro_eNB_ID);
            pvalue->u.long_Macro_eNB_ID = 0;
         }
         break;
      default:
         if(0!=pvalue->u.extElem1){
            if(!rtxCtxtTestFlag(pctxt, ASN1FASTCOPY)){
               rtxMemFreePtr(pctxt, (void*)pvalue->u.extElem1->data);
               pvalue->u.extElem1->data = 0;
            }
            rtxMemFreePtr (pctxt, (void*)pvalue->u.extElem1);
            pvalue->u.extElem1 = 0;
         }
   }
}


int asn1PtrToStr_e2ap_ENB_ID (const char* name, e2ap_ENB_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) return -1;
   

   switch (pvalue->t) {
      case T_e2ap_ENB_ID_macro_eNB_ID:
         if (asn1PrtToStr_ASN1BitStr32 ( "macro_eNB_ID", pvalue->u.macro_eNB_ID, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_ENB_ID_home_eNB_ID:
         if (asn1PrtToStr_ASN1BitStr32 ( "home_eNB_ID", pvalue->u.home_eNB_ID, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_ENB_ID_short_Macro_eNB_ID:
         if (asn1PrtToStr_ASN1BitStr32 ( "short_Macro_eNB_ID", pvalue->u.short_Macro_eNB_ID, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_ENB_ID_long_Macro_eNB_ID:
         if (asn1PrtToStr_ASN1BitStr32 ( "long_Macro_eNB_ID", pvalue->u.long_Macro_eNB_ID, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_ENB_ID_extElem1:
         if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
         if(rtPrintToStringHexStr("extElem1", pvalue->u.extElem1->numocts, pvalue->u.extElem1->data, buffer, bufSize) < 0) return -1;
         break;
      default:;
   }

   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}


