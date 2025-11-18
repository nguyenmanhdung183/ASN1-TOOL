/* e2ap_GlobalE2node_ID.c */

// choice

/*****************************************/
/*           GlobalE2node_ID                */
/*****************************************/


EXTERN int asn1PE_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "GlobalE2node-ID");

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
         RTXCTXPUSHELEMNAME (pctxt, "gNB");
         stat = asn1PE_e2ap_GlobalE2node-gNB-ID (pctxt, pvalue->u.gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "en-gNB");
         stat = asn1PE_e2ap_GlobalE2node-en-gNB-ID (pctxt, pvalue->u.en-gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXPUSHELEMNAME (pctxt, "ng-eNB");
         stat = asn1PE_e2ap_GlobalE2node-ng-eNB-ID (pctxt, pvalue->u.ng-eNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXPUSHELEMNAME (pctxt, "eNB");
         stat = asn1PE_e2ap_GlobalE2node-eNB-ID (pctxt, pvalue->u.eNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "GlobalE2node_ID");

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
         RTXCTXPUSHELEMNAME (pctxt, "gNB");
         pvalue->u.gNB = rtxMemAllocType (pctxt, e2ap_GlobalE2node-gNB-ID);
         if (pvalue->u.gNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_GlobalE2node-gNB-ID (pctxt, pvalue->u.gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "en-gNB");
         pvalue->u.en-gNB = rtxMemAllocType (pctxt, e2ap_GlobalE2node-en-gNB-ID);
         if (pvalue->u.en-gNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_GlobalE2node-en-gNB-ID (pctxt, pvalue->u.en-gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "ng-eNB");
         pvalue->u.ng-eNB = rtxMemAllocType (pctxt, e2ap_GlobalE2node-ng-eNB-ID);
         if (pvalue->u.ng-eNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_GlobalE2node-ng-eNB-ID (pctxt, pvalue->u.ng-eNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "eNB");
         pvalue->u.eNB = rtxMemAllocType (pctxt, e2ap_GlobalE2node-eNB-ID);
         if (pvalue->u.eNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_GlobalE2node-eNB-ID (pctxt, pvalue->u.eNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

int asn1Init_e2ap_GlobalE2node_ID (e2ap_GlobalE2node_ID* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->t = 0;
   OSRTLMEMSET (&pvalue->u, 0, sizeof(pvalue->u));
   return 0;
}

void asn1Free_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue)
{
   if (pvalue == 0) return;
   switch (pvalue->t) {
      case 0.0:
         if (pvalue->u.gNB) {
            asn1Free_e2ap_GlobalE2node-gNB-ID (pctxt, pvalue->u.gNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gNB);
         }
         break;
      case 1.0:
         if (pvalue->u.en-gNB) {
            asn1Free_e2ap_GlobalE2node-en-gNB-ID (pctxt, pvalue->u.en-gNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.en-gNB);
         }
         break;
      case 2.0:
         if (pvalue->u.ng-eNB) {
            asn1Free_e2ap_GlobalE2node-ng-eNB-ID (pctxt, pvalue->u.ng-eNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.ng-eNB);
         }
         break;
      case 3.0:
         if (pvalue->u.eNB) {
            asn1Free_e2ap_GlobalE2node-eNB-ID (pctxt, pvalue->u.eNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.eNB);
         }
         break;
   }
   pvalue->t = 0;
}