/* e2ap_GlobalE2node_ID.c */
#include "e2ap_GlobalE2node_ID.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "GlobalE2node_ID");

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
         RTXCTXPUSHELEMNAME (pctxt, "gNB");
         pvalue->u.gNB = rtxMemAllocType (pctxt, e2ap_GlobalGNB_ID);
         if (pvalue->u.gNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_GlobalGNB_ID (pvalue->u.gNB);
         stat = asn1PE_e2ap_GlobalGNB_ID (pctxt, pvalue->u.gNB);
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
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "gNB");
         pvalue->u.gNB = rtxMemAllocType (pctxt, e2ap_GlobalGNB_ID);
         if (pvalue->u.gNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_GlobalGNB_ID (pvalue->u.gNB);
         stat = asn1PD_e2ap_GlobalGNB_ID (pctxt, pvalue->u.gNB);
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
      case 1:
         if (pvalue->u.gNB) {
            asn1Free_e2ap_GlobalGNB_ID (pctxt, pvalue->u.gNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gNB);
         }
         break;
   }
   pvalue->t = 0;
}