/* e2ap_RANfunctionsIDcause_List.c */

//seq_of_single_container.c

int asn1PE_e2ap_RANfunctionsIDcause_List (OSCTXT* pctxt, e2ap_RANfunctionsIDcause_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   e2ap_RANfunctionIDcause-ItemIEs* pdata;

   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionsIDcause_List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(256), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RANfunctionIDcause-ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RANfunctionIDcause-ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RANfunctionsIDcause_List (OSCTXT* pctxt, e2ap_RANfunctionsIDcause_List** ppvalue)
{
   int stat = 0;
   OSSIZE count = 0;
   e2ap_RANfunctionIDcause-ItemIEs* pdata;

   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionsIDcause_List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(256), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RANfunctionIDcause-ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RANfunctionIDcause-ItemIEs (pdata);

      stat = asn1PD_e2ap_RANfunctionIDcause-ItemIEs (pctxt, pdata);
      if (stat != 0) {
         rtxMemFreePtr (pctxt, pdata);
         return LOG_RTERR (pctxt, stat);
      }

      rtxDListAppendNode (ppvalue, pdata);

      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

void asn1Init_e2ap_RANfunctionsIDcause_List (e2ap_RANfunctionsIDcause_List* pvalue)
{
   rtxDListInit (pvalue);
}

void asn1Free_e2ap_RANfunctionsIDcause_List (OSCTXT* pctxt, e2ap_RANfunctionsIDcause_List* pvalue)
{
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RANfunctionIDcause-ItemIEs* pdata = (e2ap_RANfunctionIDcause-ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RANfunctionIDcause-ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}