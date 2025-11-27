/*****************************************/
/*           E2connectionUpdate_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2connectionUpdate_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "E2connectionUpdate-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(32), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_E2connectionUpdate_ItemIEs*) pnode->data;
      RTXCTXTPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_E2connectionUpdate_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXTPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

int asn1PD_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2connectionUpdate_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "E2connectionUpdate-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(32), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXTPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_E2connectionUpdate_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);
      asn1Init_e2ap_E2connectionUpdate_ItemIEs (pdata);
      stat = asn1PD_e2ap_E2connectionUpdate_ItemIEs (pctxt, pdata);
      if (stat != 0) {
         rtxMemFreePtr (pctxt, pdata);
         return LOG_RTERR (pctxt, stat);
      }

      rtxDListAppendNode (ppvalue, pdata);

      RTXCTXTPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

void asn1Init_e2ap_E2connectionUpdate_List (e2ap_E2connectionUpdate_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_E2connectionUpdate_ItemIEs* pdata = (e2ap_E2connectionUpdate_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_E2connectionUpdate_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
      rtxDListFreeAll(pctxt, pvalue);
}

#if 0
void asn1Free_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_E2connectionUpdate_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_E2connectionUpdate_ItemIEs*)pnode->data;
         asn1Free_e2ap_E2connectionUpdate_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif


int asn1PrtToStr_e2ap_E2connectionUpdate_List(const char* name, e2ap_E2connectionUpdate_List* pvalue, char* buffer, OSSIZE bufSize)
{
    e2ap_E2connectionUpdate_ItemIEs* pdata;
    OSRTDListNode* pnode;
    char nameBuf[256];
    char numBuf[32];
    OSUINT32 xx1=0;
    for(pnode = pvalue->head;  xx1 < pvalue->count && pnode != 0; pnode = pnode->next, xx1++){
        pdata = (e2ap_E2connectionUpdate_ItemIEs*)pnode->data;
        rtxUIntToCharStr(xx1, numBuf, sizeof(numBuf), 0);
        rtxStrJoin(nameBuf, sizeof(nameBuf), name, "[", numBuf, "]", 0);
        #if 1
        if(asn1PrtToStr_e2ap_E2connectionUpdate_ItemIEs(nameBuf, pdata, buffer, bufSize) <0){
            return -1;
        }
        #endif
    }
    return 0;
}