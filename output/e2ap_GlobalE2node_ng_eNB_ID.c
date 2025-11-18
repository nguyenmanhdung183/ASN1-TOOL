
/*****************************************/
/*           GlobalE2node_ng_eNB_ID                */
/*****************************************/


int asn1PE_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node_ng_eNB_ID");

   stat = asn1PE_e2ap_GlobalngeNB-ID (pctxt, &pvalue->global-ng-eNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (pvalue->m_global-eNB-IDPresent) {
   stat = asn1PE_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_ngENB-DU-IDPresent) {
   stat = asn1PE_e2ap_NGENB-DU-ID (pctxt, &pvalue->ngENB-DU-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node_ng_eNB_ID");

   stat = asn1PD_e2ap_GlobalngeNB-ID (pctxt, &pvalue->global-ng-eNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_global-eNB-IDPresent = TRUE;
      stat = asn1PD_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_global-eNB-IDPresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_ngENB-DU-IDPresent = TRUE;
      stat = asn1PD_e2ap_NGENB-DU-ID (pctxt, &pvalue->ngENB-DU-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_ngENB-DU-IDPresent = FALSE;

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_GlobalE2node_ng_eNB_ID (e2ap_GlobalE2node_ng_eNB_ID* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_GlobalngeNB-ID (&pvalue->global-ng-eNB-ID);
   asn1Init_e2ap_GlobalENB-ID (&pvalue->global-eNB-ID);
   asn1Init_e2ap_NGENB-DU-ID (&pvalue->ngENB-DU-ID);
}

void asn1Free_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue)
{
   %}
   asn1Free_e2ap_GlobalngeNB-ID (pctxt, &pvalue->global-ng-eNB-ID);
   %}
   asn1Free_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
   %}
   asn1Free_e2ap_NGENB-DU-ID (pctxt, &pvalue->ngENB-DU-ID);
}