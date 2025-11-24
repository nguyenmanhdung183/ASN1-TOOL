/* e2ap_E2nodeComponentConfigRemovalAck-Item.c */

/*****************************************/
/*           E2nodeComponentConfigRemovalAck-Item               */
/*****************************************/
//IE

int asn1PE_e2ap_E2nodeComponentConfigRemovalAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue)
{
   int stat = 0;
   //RTXCTXTPUSHTYPENAME (pctxt, "E2nodeComponentConfigRemovalAck-Item");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->criticality);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode value */
   RTXCTXTPUSHELEMNAME (pctxt, "value");

   {
      OSCTXT ictxt;
      OSOCTET* pDynamicEncodeBuffer;
      ASN1OpenType openType;
      OSBOOL  encoded = TRUE;

      openType.numocts = 0;
      openType.data = 0;

      rtxCopyContext (&ictxt, pctxt);
      pctxt->pStream = 0;

      stat = rtxInitContextBuffer (pctxt, 0, 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      switch (pvalue->value.t) {
      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "_e2ap_E2nodeComponentConfigRemovalAck-Item_id_E2nodeComponentConfigRemovalAck_Item");
         stat = asn1PE_e2ap_E2nodeComponentConfigRemovalAck_Item (pctxt, pvalue->value.u._e2apE2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item);
         RTXCTXTPOPELEMNAME (pctxt);
      
         break;

      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigRemovalAck-Item_UNDEF_:
      {
          if(0!=pvalue->value.u.extElem1){
              openType.numocts = pvalue->value.u.extElem1->numocts;
              openType.data = pvalue->value.u.extElem1->data;
          } else {
              /* No extension element to encode */
          }
          encoded = FALSE;
          break;
      }
      default:
         encoded = FALSE;
         stat = RTERR_INVOPT;
      }

      if (encoded) {
         size_t bitOffset = PU_GETCTXTBITOFFSET (pctxt);
         size_t bitsConsumed = bitOffset;
         if (bitsConsumed < bitOffset) {
            stat = pd_moveBitCursor (pctxt, (int)(bitOffset - bitsConsumed));
         } else {
            stat = (bitsConsumed > bitOffset) ? ASN_E_INVLEN : 0;
         }
         if (stat != 0) return LOG_RTERR (pctxt, stat);
      }

      RTXCTXTPOPELEMNAME (pctxt);
   }

   //RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigRemovalAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigRemovalAck-Item (e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_E2nodeComponentConfigRemovalAck-Item));
}

#if 0
void asn1Free_e2ap_E2nodeComponentConfigRemovalAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
#endif
void asn1Free_e2ap_E2nodeComponentConfigRemovalAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue)
{
   if(0==pvalue) return;
   switch(pvalue->value.t){
      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item:
         asn1Free_e2ap_E2nodeComponentConfigRemovalAck_Item (pctxt, pvalue->value.u._e2apE2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item);
         rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2apE2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item);
         pvalue->value.u._e2apE2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item = 0;
         break;
      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigRemovalAck-Item_UNDEF_:
         if(0!=pvalue->value.u.extElem1){
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1->data);
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1);
             pvalue->value.u.extElem1 =0;
         }
         break;
         default:;
   }
}