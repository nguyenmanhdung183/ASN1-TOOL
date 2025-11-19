/* e2ap_E2nodeComponentID.c */

/*****************************************/
/*           E2nodeComponentID                */
/*****************************************/
// choice

// choice with extension typefef từ 1
EXTERN int asn1PE_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentID");

   extbit = (OSBOOL)(pvalue->t > 6);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   if(!extbit){
      RTXCTXPUSHELEMNAME (pctxt, "t");

      stat = rtxEncBits (pctxt, pvalue->t - 1, 3);// kha nang la numbits
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      RTXCTXPOPELEMNAME (pctxt);

      switch (pvalue->t) {
      case 0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeNG");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceNG (pctxt, pvalue->u.e2nodeComponentInterfaceTypeNG);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeXn");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceXn (pctxt, pvalue->u.e2nodeComponentInterfaceTypeXn);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeE1");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceE1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeE1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeF1");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceF1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeF1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 4:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeW1");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceW1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeW1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 5:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeS1");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceS1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeS1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 6:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeX2");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceX2 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeX2);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
      }
   }else{
      stat = pe_SmallNonNegWholeNumber (pctxt, pvalue->t - 7);// can xem lai
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      RTXCTXPUSHELEMNAME (pctxt, "...");
      stat = pe_OpenType (pctxt, pvalue->u.extElem1->numocts, pvalue->u.extElem1->data);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      RTXCTXPOPELEMNAME (pctxt);
   }
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentID");

   stat = DECBIT (pctxt, &extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   if(!extbit){
      stat = rtxDecBits (pctxt, &ui, 3);// kha nang la numbits
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      else pvalue->t = ui + 1;

      switch (ui)
      {
      case 0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeNG");

         pvalue->u.e2nodeComponentInterfaceTypeNG = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceNG);

         if (pvalue->u.e2nodeComponentInterfaceTypeNG == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_E2nodeComponentInterfaceNG(pvalue->u.e2nodeComponentInterfaceTypeNG);
         //stat = asn1PD_e2ap_E2nodeComponentInterfaceNG (pctxt, pvalue->u.e2nodeComponentInterfaceTypeNG);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeXn");

         pvalue->u.e2nodeComponentInterfaceTypeXn = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceXn);

         if (pvalue->u.e2nodeComponentInterfaceTypeXn == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_E2nodeComponentInterfaceXn(pvalue->u.e2nodeComponentInterfaceTypeXn);
         //stat = asn1PD_e2ap_E2nodeComponentInterfaceXn (pctxt, pvalue->u.e2nodeComponentInterfaceTypeXn);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeE1");

         pvalue->u.e2nodeComponentInterfaceTypeE1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceE1);

         if (pvalue->u.e2nodeComponentInterfaceTypeE1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_E2nodeComponentInterfaceE1(pvalue->u.e2nodeComponentInterfaceTypeE1);
         //stat = asn1PD_e2ap_E2nodeComponentInterfaceE1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeE1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeF1");

         pvalue->u.e2nodeComponentInterfaceTypeF1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceF1);

         if (pvalue->u.e2nodeComponentInterfaceTypeF1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_E2nodeComponentInterfaceF1(pvalue->u.e2nodeComponentInterfaceTypeF1);
         //stat = asn1PD_e2ap_E2nodeComponentInterfaceF1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeF1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 4:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeW1");

         pvalue->u.e2nodeComponentInterfaceTypeW1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceW1);

         if (pvalue->u.e2nodeComponentInterfaceTypeW1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_E2nodeComponentInterfaceW1(pvalue->u.e2nodeComponentInterfaceTypeW1);
         //stat = asn1PD_e2ap_E2nodeComponentInterfaceW1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeW1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 5:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeS1");

         pvalue->u.e2nodeComponentInterfaceTypeS1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceS1);

         if (pvalue->u.e2nodeComponentInterfaceTypeS1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_E2nodeComponentInterfaceS1(pvalue->u.e2nodeComponentInterfaceTypeS1);
         //stat = asn1PD_e2ap_E2nodeComponentInterfaceS1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeS1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 6:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeX2");

         pvalue->u.e2nodeComponentInterfaceTypeX2 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceX2);

         if (pvalue->u.e2nodeComponentInterfaceTypeX2 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_E2nodeComponentInterfaceX2(pvalue->u.e2nodeComponentInterfaceTypeX2);
         //stat = asn1PD_e2ap_E2nodeComponentInterfaceX2 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeX2);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
      }
   }else{
      stat = pd_SmallNonNegWholeNumber (pctxt, &ui);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      else pvalue->t = ui + 8;
      if(pvalue->t < 8){
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

int asn1Init_e2ap_E2nodeComponentID (e2ap_E2nodeComponentID* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->t = 0;
   OSRTLMEMSET (&pvalue->u, 0, sizeof(pvalue->u));
   return 0;
}

void asn1Free_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue)
{
   if (pvalue == 0) return;
   switch (pvalue->t) {
      case 0: //no choice nothing to free
         break;
      case 1:
         if (pvalue->u.e2nodeComponentInterfaceTypeNG) {
            asn1Free_e2ap_E2nodeComponentInterfaceNG (pctxt, pvalue->u.e2nodeComponentInterfaceTypeNG);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeNG);
            pvalue->u.e2nodeComponentInterfaceTypeNG = 0;
         }
         break;
      case 2:
         if (pvalue->u.e2nodeComponentInterfaceTypeXn) {
            asn1Free_e2ap_E2nodeComponentInterfaceXn (pctxt, pvalue->u.e2nodeComponentInterfaceTypeXn);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeXn);
            pvalue->u.e2nodeComponentInterfaceTypeXn = 0;
         }
         break;
      case 3:
         if (pvalue->u.e2nodeComponentInterfaceTypeE1) {
            asn1Free_e2ap_E2nodeComponentInterfaceE1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeE1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeE1);
            pvalue->u.e2nodeComponentInterfaceTypeE1 = 0;
         }
         break;
      case 4:
         if (pvalue->u.e2nodeComponentInterfaceTypeF1) {
            asn1Free_e2ap_E2nodeComponentInterfaceF1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeF1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeF1);
            pvalue->u.e2nodeComponentInterfaceTypeF1 = 0;
         }
         break;
      case 5:
         if (pvalue->u.e2nodeComponentInterfaceTypeW1) {
            asn1Free_e2ap_E2nodeComponentInterfaceW1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeW1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeW1);
            pvalue->u.e2nodeComponentInterfaceTypeW1 = 0;
         }
         break;
      case 6:
         if (pvalue->u.e2nodeComponentInterfaceTypeS1) {
            asn1Free_e2ap_E2nodeComponentInterfaceS1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeS1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeS1);
            pvalue->u.e2nodeComponentInterfaceTypeS1 = 0;
         }
         break;
      case 7:
         if (pvalue->u.e2nodeComponentInterfaceTypeX2) {
            asn1Free_e2ap_E2nodeComponentInterfaceX2 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeX2);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeX2);
            pvalue->u.e2nodeComponentInterfaceTypeX2 = 0;
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


int asn1PtrToStr_e2ap_E2nodeComponentID (const char* name, e2ap_E2nodeComponentID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) return -1;
   

   switch (pvalue->t) {
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeNG:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceNG ( "e2nodeComponentInterfaceTypeNG", pvalue->u.e2nodeComponentInterfaceTypeNG, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeXn:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceXn ( "e2nodeComponentInterfaceTypeXn", pvalue->u.e2nodeComponentInterfaceTypeXn, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeE1:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceE1 ( "e2nodeComponentInterfaceTypeE1", pvalue->u.e2nodeComponentInterfaceTypeE1, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeF1:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceF1 ( "e2nodeComponentInterfaceTypeF1", pvalue->u.e2nodeComponentInterfaceTypeF1, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeW1:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceW1 ( "e2nodeComponentInterfaceTypeW1", pvalue->u.e2nodeComponentInterfaceTypeW1, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeS1:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceS1 ( "e2nodeComponentInterfaceTypeS1", pvalue->u.e2nodeComponentInterfaceTypeS1, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeX2:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceX2 ( "e2nodeComponentInterfaceTypeX2", pvalue->u.e2nodeComponentInterfaceTypeX2, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_E2nodeComponentID_extElem1:
         if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
         if(rtPrintToStringHexStr("extElem1", pvalue->u.extElem1->numocts, pvalue->u.extElem1->data, buffer, bufSize) < 0) return -1;
         break;
      default:;
   }

   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}


