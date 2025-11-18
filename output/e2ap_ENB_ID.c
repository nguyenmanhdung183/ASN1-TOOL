/* e2ap_ENB_ID.c */

// choice
EXTERN int asn1PE_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "ENB_ID");

   extbit = (OSBOOL)(pvalue->t > 3);
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
      case 0.0:
         RTXCTXPUSHELEMNAME (pctxt, "macro_eNB_ID");
         stat = asn1PE_e2ap_BIT STRING (pctxt, pvalue->u.macro_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "O_RAN");
         stat = asn1PE_e2ap_WG3 (pctxt, pvalue->u.O_RAN);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "home_eNB_ID");
         stat = asn1PE_e2ap_BIT STRING (pctxt, pvalue->u.home_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "short_Macro_eNB_ID");
         stat = asn1PE_e2ap_BIT STRING (pctxt, pvalue->u.short_Macro_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 4.0:
         RTXCTXPUSHELEMNAME (pctxt, "long_Macro_eNB_ID");
         stat = asn1PE_e2ap_BIT STRING (pctxt, pvalue->u.long_Macro_eNB_ID);
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
         RTXCTXPUSHELEMNAME (pctxt, "macro_eNB_ID");
         pvalue->u.macro_eNB_ID = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.macro_eNB_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_BIT STRING (pctxt, pvalue->u.macro_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "O_RAN");
         pvalue->u.O_RAN = rtxMemAllocType (pctxt, e2ap_WG3);
         if (pvalue->u.O_RAN == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_WG3 (pctxt, pvalue->u.O_RAN);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "home_eNB_ID");
         pvalue->u.home_eNB_ID = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.home_eNB_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_BIT STRING (pctxt, pvalue->u.home_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "short_Macro_eNB_ID");
         pvalue->u.short_Macro_eNB_ID = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.short_Macro_eNB_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_BIT STRING (pctxt, pvalue->u.short_Macro_eNB_ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 4.0:
         RTXCTXPUSHELEMNAME (pctxt, "long_Macro_eNB_ID");
         pvalue->u.long_Macro_eNB_ID = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.long_Macro_eNB_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_BIT STRING (pctxt, pvalue->u.long_Macro_eNB_ID);
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
         if (pvalue->u.macro_eNB_ID) {
            asn1Free_e2ap_BIT STRING (pctxt, pvalue->u.macro_eNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.macro_eNB_ID);
         }
         break;
      case 1.0:
         if (pvalue->u.O_RAN) {
            asn1Free_e2ap_WG3 (pctxt, pvalue->u.O_RAN);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.O_RAN);
         }
         break;
      case 2.0:
         if (pvalue->u.home_eNB_ID) {
            asn1Free_e2ap_BIT STRING (pctxt, pvalue->u.home_eNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.home_eNB_ID);
         }
         break;
      case 3.0:
         if (pvalue->u.short_Macro_eNB_ID) {
            asn1Free_e2ap_BIT STRING (pctxt, pvalue->u.short_Macro_eNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.short_Macro_eNB_ID);
         }
         break;
      case 4.0:
         if (pvalue->u.long_Macro_eNB_ID) {
            asn1Free_e2ap_BIT STRING (pctxt, pvalue->u.long_Macro_eNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.long_Macro_eNB_ID);
         }
         break;
   }
   pvalue->t = 0;
}