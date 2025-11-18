
/*****************************************/
/*           E2nodeComponentInterfaceX2                */
/*****************************************/


int asn1PE_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceX2");

   if (pvalue->m_global-eNB-IDPresent) {
   stat = asn1PE_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_global-en-gNB-IDPresent) {
   stat = asn1PE_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceX2");

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
      pvalue->m_global-en-gNB-IDPresent = TRUE;
      stat = asn1PD_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_global-en-gNB-IDPresent = FALSE;

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentInterfaceX2 (e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_GlobalENB-ID (&pvalue->global-eNB-ID);
   asn1Init_e2ap_GlobalenGNB-ID (&pvalue->global-en-gNB-ID);
}

void asn1Free_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   %}
   asn1Free_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
   %}
   asn1Free_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
}