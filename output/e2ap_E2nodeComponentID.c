/* e2ap_E2nodeComponentID.c */

// choice

/*****************************************/
/*           E2nodeComponentID                */
/*****************************************/


EXTERN int asn1PE_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentID");

   extbit = (OSBOOL)(pvalue->t > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   if (extbit) {
      stat = pe_SmallNonNegWholeNumber (pctxt, pvalue->t - 4);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   } else {
      stat = rtxEncBits (pctxt, pvalue->t - 1, 2);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

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

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentID");

   stat = rtxDecBit (pctxt, &extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   if (extbit) {
      stat = pd_SmallNonNegWholeNumber (pctxt, &ui);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      pvalue->t = ui + 4;
   } else {
      pvalue->t = ui + 1;
   }

   switch (pvalue->t) {
      case 0.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeNG");
         pvalue->u.e2nodeComponentInterfaceTypeNG = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceNG);
         if (pvalue->u.e2nodeComponentInterfaceTypeNG == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceNG (pctxt, pvalue->u.e2nodeComponentInterfaceTypeNG);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeXn");
         pvalue->u.e2nodeComponentInterfaceTypeXn = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceXn);
         if (pvalue->u.e2nodeComponentInterfaceTypeXn == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceXn (pctxt, pvalue->u.e2nodeComponentInterfaceTypeXn);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeE1");
         pvalue->u.e2nodeComponentInterfaceTypeE1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceE1);
         if (pvalue->u.e2nodeComponentInterfaceTypeE1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceE1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeE1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeF1");
         pvalue->u.e2nodeComponentInterfaceTypeF1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceF1);
         if (pvalue->u.e2nodeComponentInterfaceTypeF1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceF1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeF1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 4.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeW1");
         pvalue->u.e2nodeComponentInterfaceTypeW1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceW1);
         if (pvalue->u.e2nodeComponentInterfaceTypeW1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceW1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeW1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 5.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeS1");
         pvalue->u.e2nodeComponentInterfaceTypeS1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceS1);
         if (pvalue->u.e2nodeComponentInterfaceTypeS1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceS1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeS1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 6.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeX2");
         pvalue->u.e2nodeComponentInterfaceTypeX2 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceX2);
         if (pvalue->u.e2nodeComponentInterfaceTypeX2 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceX2 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeX2);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
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
      case 0.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeNG) {
            asn1Free_e2ap_E2nodeComponentInterfaceNG (pctxt, pvalue->u.e2nodeComponentInterfaceTypeNG);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeNG);
         }
         break;
      case 1.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeXn) {
            asn1Free_e2ap_E2nodeComponentInterfaceXn (pctxt, pvalue->u.e2nodeComponentInterfaceTypeXn);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeXn);
         }
         break;
      case 2.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeE1) {
            asn1Free_e2ap_E2nodeComponentInterfaceE1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeE1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeE1);
         }
         break;
      case 3.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeF1) {
            asn1Free_e2ap_E2nodeComponentInterfaceF1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeF1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeF1);
         }
         break;
      case 4.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeW1) {
            asn1Free_e2ap_E2nodeComponentInterfaceW1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeW1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeW1);
         }
         break;
      case 5.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeS1) {
            asn1Free_e2ap_E2nodeComponentInterfaceS1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeS1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeS1);
         }
         break;
      case 6.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeX2) {
            asn1Free_e2ap_E2nodeComponentInterfaceX2 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeX2);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeX2);
         }
         break;
   }
   pvalue->t = 0;
}