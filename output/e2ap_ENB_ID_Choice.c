/* e2ap_ENB_ID_Choice.c */

// choice
EXTERN int asn1PE_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "ENB_ID_Choice");

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
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb_ID_macro");
         stat = asn1PE_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_macro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb_ID_shortmacro");
         stat = asn1PE_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_shortmacro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb_ID_longmacro");
         stat = asn1PE_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_longmacro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "ENB_ID_Choice");

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
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb_ID_macro");
         pvalue->u.enb_ID_macro = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.enb_ID_macro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_macro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb_ID_shortmacro");
         pvalue->u.enb_ID_shortmacro = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.enb_ID_shortmacro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_shortmacro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb_ID_longmacro");
         pvalue->u.enb_ID_longmacro = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.enb_ID_longmacro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_longmacro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

int asn1Init_e2ap_ENB_ID_Choice (e2ap_ENB_ID_Choice* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->t = 0;
   OSRTLMEMSET (&pvalue->u, 0, sizeof(pvalue->u));
   return 0;
}

void asn1Free_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue)
{
   if (pvalue == 0) return;
   switch (pvalue->t) {
      case 1.0:
         if (pvalue->u.enb_ID_macro) {
            asn1Free_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_macro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb_ID_macro);
         }
         break;
      case 2.0:
         if (pvalue->u.enb_ID_shortmacro) {
            asn1Free_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_shortmacro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb_ID_shortmacro);
         }
         break;
      case 3.0:
         if (pvalue->u.enb_ID_longmacro) {
            asn1Free_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_longmacro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb_ID_longmacro);
         }
         break;
   }
   pvalue->t = 0;
}