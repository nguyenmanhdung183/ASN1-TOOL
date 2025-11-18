/* e2ap_ENB_ID.c */

// choice

/*****************************************/
/*           ENB_ID                */
/*****************************************/


EXTERN int asn1PE_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "ENB-ID");

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
         RTXCTXPUSHELEMNAME (pctxt, "macro-eNB-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.macro-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "home-eNB-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.home-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXPUSHELEMNAME (pctxt, "short-Macro-eNB-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.short-Macro-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXPUSHELEMNAME (pctxt, "long-Macro-eNB-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.long-Macro-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "ENB_ID");

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
         RTXCTXPUSHELEMNAME (pctxt, "macro-eNB-ID");
         pvalue->u.macro-eNB-ID = rtxMemAllocType (pctxt, ASN1BitStr32);
         if (pvalue->u.macro-eNB-ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.macro-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "home-eNB-ID");
         pvalue->u.home-eNB-ID = rtxMemAllocType (pctxt, ASN1BitStr32);
         if (pvalue->u.home-eNB-ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.home-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "short-Macro-eNB-ID");
         pvalue->u.short-Macro-eNB-ID = rtxMemAllocType (pctxt, ASN1BitStr32);
         if (pvalue->u.short-Macro-eNB-ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.short-Macro-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "long-Macro-eNB-ID");
         pvalue->u.long-Macro-eNB-ID = rtxMemAllocType (pctxt, ASN1BitStr32);
         if (pvalue->u.long-Macro-eNB-ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.long-Macro-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
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
      case 0.0:
         if (pvalue->u.macro-eNB-ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.macro-eNB-ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.macro-eNB-ID);
         }
         break;
      case 1.0:
         if (pvalue->u.home-eNB-ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.home-eNB-ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.home-eNB-ID);
         }
         break;
      case 2.0:
         if (pvalue->u.short-Macro-eNB-ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.short-Macro-eNB-ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.short-Macro-eNB-ID);
         }
         break;
      case 3.0:
         if (pvalue->u.long-Macro-eNB-ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.long-Macro-eNB-ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.long-Macro-eNB-ID);
         }
         break;
   }
   pvalue->t = 0;
}