/*****************************************/
/*           RICactions_ConfirmedForModification_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_RICactions_ConfirmedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ConfirmedForModification_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICaction_ConfirmedForModification_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICactions-ConfirmedForModification-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(0), OSUINTCONST(ASN1V_e2ap_maxofRICactionID), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RICaction_ConfirmedForModification_ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RICaction_ConfirmedForModification_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RICactions_ConfirmedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ConfirmedForModification_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICaction_ConfirmedForModification_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICactions-ConfirmedForModification-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(0), OSUINTCONST(ASN1V_e2ap_maxofRICactionID), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RICaction_ConfirmedForModification_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RICaction_ConfirmedForModification_ItemIEs (pdata);

      stat = asn1PD_e2ap_RICaction_ConfirmedForModification_ItemIEs (pctxt, pdata);
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

void asn1Init_e2ap_RICactions_ConfirmedForModification_List (e2ap_RICactions_ConfirmedForModification_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_RICactions_ConfirmedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ConfirmedForModification_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RICaction_ConfirmedForModification_ItemIEs* pdata = (e2ap_RICaction_ConfirmedForModification_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RICaction_ConfirmedForModification_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}

#if 0
void asn1Free_e2ap_RICactions_ConfirmedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ConfirmedForModification_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_RICaction_ConfirmedForModification_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_RICaction_ConfirmedForModification_ItemIEs*)pnode->data;
         asn1Free_e2ap_RICaction_ConfirmedForModification_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif