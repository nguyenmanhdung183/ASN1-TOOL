
/*****************************************/
/*           GlobalE2node_gNB_ID                */
/*****************************************/


int asn1PE_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node_gNB_ID");

   stat = asn1PE_e2ap_GlobalgNB-ID (pctxt, &pvalue->global-gNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (pvalue->m_global-en-gNB-IDPresent) {
   stat = asn1PE_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_gNB-CU-UP-IDPresent) {
   stat = asn1PE_e2ap_GNB-CU-UP-ID (pctxt, &pvalue->gNB-CU-UP-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_gNB-DU-IDPresent) {
   stat = asn1PE_e2ap_GNB-DU-ID (pctxt, &pvalue->gNB-DU-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node_gNB_ID");

   stat = asn1PD_e2ap_GlobalgNB-ID (pctxt, &pvalue->global-gNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_global-en-gNB-IDPresent = TRUE;
      stat = asn1PD_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_global-en-gNB-IDPresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_gNB-CU-UP-IDPresent = TRUE;
      stat = asn1PD_e2ap_GNB-CU-UP-ID (pctxt, &pvalue->gNB-CU-UP-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_gNB-CU-UP-IDPresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_gNB-DU-IDPresent = TRUE;
      stat = asn1PD_e2ap_GNB-DU-ID (pctxt, &pvalue->gNB-DU-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_gNB-DU-IDPresent = FALSE;

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_GlobalE2node_gNB_ID (e2ap_GlobalE2node_gNB_ID* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_GlobalgNB-ID (&pvalue->global-gNB-ID);
   asn1Init_e2ap_GlobalenGNB-ID (&pvalue->global-en-gNB-ID);
   asn1Init_e2ap_GNB-CU-UP-ID (&pvalue->gNB-CU-UP-ID);
   asn1Init_e2ap_GNB-DU-ID (&pvalue->gNB-DU-ID);
}

void asn1Free_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue)
{
   %}
   asn1Free_e2ap_GlobalgNB-ID (pctxt, &pvalue->global-gNB-ID);
   %}
   asn1Free_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
   %}
   asn1Free_e2ap_GNB-CU-UP-ID (pctxt, &pvalue->gNB-CU-UP-ID);
   %}
   asn1Free_e2ap_GNB-DU-ID (pctxt, &pvalue->gNB-DU-ID);
}