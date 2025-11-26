/* e2ap_E2connectionUpdateRemove_ItemIEs.c */

/*****************************************/
/*           E2connectionUpdateRemove_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_E2connectionUpdateRemove_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_ItemIEs* pvalue)
{
   int stat = 0;
   //RTXCTXTPUSHTYPENAME (pctxt, "E2connectionUpdateRemove-ItemIEs");

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
      case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "_e2ap_E2connectionUpdateRemove_ItemIEs_id_E2connectionUpdateRemove_Item");
         stat = asn1PE_e2ap_E2connectionUpdateRemove_Item (pctxt, pvalue->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item);
         RTXCTXTPOPELEMNAME (pctxt);
      
         break;

      case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_UNDEF_:
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
         openType.numocts = (OSUINT32) pe_GetMsgLen (pctxt);
         openType.data = pDynamicEncodeBuffer = pctxt->buffer.data;
      }
      rtxCopyContext (pctxt, &ictxt);
      if(stat ==0) stat = pe_OpenType(pctxt, openType.numocts, openType.data);
      /*free dynamic encode buffer*/
      if(encoded){
          rtxMemFreePtr(pctxt, pDynamicEncodeBuffer);
      }
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);
   //RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2connectionUpdateRemove_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_ItemIEs* pvalue)
{
   int stat =0;
   /*deode root element id*/
   RTXCTXTPUSHELEMNAME(pctxt, "id");
   stat = asn1PD_e2ap_ProtocolIE_ID (pctxt, &pvalue->id);
   if(stat!=0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /*decode root element criticality*/
   RTXCTXTPUSHELEMNAME(pctxt, "criticality");
   stat = asn1PD_e2ap_Criticality (pctxt, &pvalue->criticality);
   if(stat!=0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);
   /*decode root element value*/
   RTXCTXTPUSHELEMNAME(pctxt, "value");
   {
      OSUINT32 openTypeLen;
      size_t bitStartOffset, bitLength;
      stat = pd_UnconsLength(pctxt, &openTypeLen);
      if(stat <0) return LOG_RTERR(pctxt, stat);
      else if(stat == RT_OK_FRAG){
         rtxErrAddStrParm(pctxt, "open type with fragmented length use - perindef");
         return LOG_RTERRNEW(pctxt, RTERR_NOTSUPP);
      }
      bitStartOffset = PU_GETCTXTBITOFFSET(pctxt);
      bitLength = openTypeLen * 8;
      switch (pvalue->id){
         case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2connectionUpdateRemove-Item");
            //pvalue->value.u._e2ap_E2connectionUpdateRemove_ItemIEs_id_E2connectionUpdateRemove_Item 
             pvalue->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item = rtxMemAllocType(pctxt, e2ap_E2connectionUpdateRemove_Item);
            //asn1Init_e2ap_E2connectionUpdateRemove_Item(pvalue->value.u._e2ap_E2connectionUpdateRemove_ItemIEs_id_E2connectionUpdateRemove_Item);
                 asn1Init_e2ap_E2connectionUpdateRemove_Item(pvalue->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item);
            stat = asn1PD_e2ap_E2connectionUpdateRemove_Item (pctxt,
                (e2ap_E2connectionUpdateRemove_Item*)pvalue->value.
                u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;

        default:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_UNDEF_;
            pvalue->value.u.extElem1 = rtxMemAllocType(pctxt, ASN1OpenType);
            if(0==pvalue->value.u.extElem1){
                return LOG_RTERR(pctxt, RTERR_NOMEM);
            }

            {
                OSOCTET *pdata =(OSOCTET*) rtxMemAlloc(pctxt, openTypeLen);
                if(0==pdata){
                    return LOG_RTERR(pctxt, RTERR_NOMEM);
                }
                stat = rtxDecBitsToByteArray(pctxt, pdata, openTypeLen, openTypeLen*8);
                if(stat!=0){
                    rtxMemFreePtr(pctxt, pdata);
                    rtxMemFreePtr(pctxt, pvalue->value.u.extElem1);
                    return LOG_RTERR(pctxt, stat);
                }

                pvalue->value.u.extElem1->numocts = openTypeLen;
                pvalue->value.u.extElem1->data = pdata;
            }
            break;
      }
      {
      size_t bitEndOffset = PU_GETCTXTBITOFFSET(pctxt);
      size_t bitsConsumed = bitEndOffset - bitStartOffset;
      if(bitsConsumed < bitLength){
         stat = pd_moveBitCursor(pctxt, (int)(bitLength - bitsConsumed));
      } else {
         stat = (bitsConsumed > bitLength) ? ASN_E_INVLEN : 0;
      }
      }
   }
   if(stat!=0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);
   return stat;
}

void asn1Init_e2ap_E2connectionUpdateRemove_ItemIEs (e2ap_E2connectionUpdateRemove_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_E2connectionUpdateRemove_ItemIEs));
}

#if 0
void asn1Free_e2ap_E2connectionUpdateRemove_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
#endif
void asn1Free_e2ap_E2connectionUpdateRemove_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_ItemIEs* pvalue)
{
   if(0==pvalue) return;
   switch(pvalue->value.t){
      case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item:
         asn1Free_e2ap_E2connectionUpdateRemove_Item (pctxt, pvalue->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item);
         rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item);
         pvalue->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item = 0;
         break;
      case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_UNDEF_:
         if(0!=pvalue->value.u.extElem1){
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1->data);
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1);
             pvalue->value.u.extElem1 =0;
         }
         break;
         default:;
   }
}

int  asn1PrtToStr_e2ap_E2connectionUpdateRemove_ItemIEs (const char * name, e2ap_E2connectionUpdateRemove_ItemIEs* pvalue, char * buffer, OSSIZE bufSize){
   if(rtPrintToStringOpenBrace(name, buffer, bufSize)<0)
       return -1;

      if(asn1PrtToStr_e2ap_ProtocolIE_ID("id", &pvalue->id, buffer, bufSize)<0)
         return -1;

      if(asn1PrtToStr_e2ap_Criticality("criticality", &pvalue->criticality, buffer, bufSize)<0)
         return -1;
      if(rtPrintToStringOpenBrace("value", buffer, bufSize)<0)
         return -1;
      switch (pvalue->value.t) {
      case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item:
         if(asn1PrtToStr_e2ap_E2connectionUpdateRemove_Item("E2connectionUpdateRemove-Item",
            pvalue->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item, buffer, bufSize)<0)
            return -1;
         break;
      default:
         if(0!=pvalue -> value.u.extElem1){
             rtPrintToStringIndent(buffer, bufSize);
             rtPrintToStringHexStr("extElem1", pvalue->value.u.extElem1->numocts, pvalue->value.u.extElem1->data, buffer, bufSize);

         }
      }
      if(rtPrintToStringCloseBrace( buffer, bufSize)<0) return -1;
      if(rtPrintToStringCloseBrace( buffer, bufSize)<0) return -1;

      return 0;

}