/* e2ap_E2setupRequestIEs.c */

//IE
/*****************************************/
/*           E2setupRequestIEs               */
/*****************************************/
int asn1PE_e2ap_E2setupRequestIEs (OSCTXT* pctxt, e2ap_E2setupRequestIEs* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "E2setupRequestIEs");

   /* encode id */
   RTXCTXPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_E2setupRequestIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_E2setupRequestIEs_.criticality);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPELEMNAME (pctxt);

   /* encode value */
   RTXCTXPUSHELEMNAME (pctxt, "value");

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
         case T_E2AP_PDU_Contents_E2setupRequestIEs_:
            RTXCTXPUSHELEMNAME (pctxt, "e2ap-E2nodeComponentConfigAddition-Item");
            stat = asn1PE_e2ap_ (pctxt, &pvalue->value.u_E2setupRequestIEs_.value);
            if (stat != 0) return LOG_RTERR (pctxt, stat);
            RTXCTXPOPELEMNAME (pctxt);
            break;

         default:
            encoded = FALSE;
            stat = RTERR_INVOPT;
      }

      if (encoded) {
         size_t bitOffset = PU_GETCTXBITSAVED (pctxt);
         size_t bitsConsumed = bitOffset;
         if (bitsConsumed < bitOffset) {
            stat = pd_moveBitCursor (pctxt, (int)(bitOffset - bitsConsumed));
         } else {
            stat = (bitsConsumed > bitOffset) ? ASN_E_INVLEN : 0;
         }
         if (stat != 0) return LOG_RTERR (pctxt, stat);
      }

      RTXCTXPOPELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2setupRequestIEs (OSCTXT* pctxt, e2ap_E2setupRequestIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_E2setupRequestIEs (e2ap_E2setupRequestIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_E2setupRequestIEs));
}

void asn1Free_e2ap_E2setupRequestIEs (OSCTXT* pctxt, e2ap_E2setupRequestIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}