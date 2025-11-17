/* e2ap_ENB_ID_Choice.c */
#include "e2ap_ENB_ID_Choice.h"
#include "rtxsrc/rtxErrCodes.h"

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
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "enb-ID-macro");
         pvalue->u.enb-ID-macro = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.enb-ID-macro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_BIT STRING (pvalue->u.enb-ID-macro);
         stat = asn1PE_e2ap_BIT STRING (pctxt, pvalue->u.enb-ID-macro);
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
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "enb-ID-macro");
         pvalue->u.enb-ID-macro = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.enb-ID-macro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_BIT STRING (pvalue->u.enb-ID-macro);
         stat = asn1PD_e2ap_BIT STRING (pctxt, pvalue->u.enb-ID-macro);
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
      case 1:
         if (pvalue->u.enb-ID-macro) {
            asn1Free_e2ap_BIT STRING (pctxt, pvalue->u.enb-ID-macro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb-ID-macro);
         }
         break;
   }
   pvalue->t = 0;
}