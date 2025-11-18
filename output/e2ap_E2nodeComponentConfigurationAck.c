
int asn1PE_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigurationAck");

   stat = asn1PE_e2ap_updateOutcome (pctxt, &pvalue->updateOutcome);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_failure (pctxt, &pvalue->failure);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (pvalue->m_failureCausePresent) {
   stat = asn1PE_e2ap_Cause (pctxt, &pvalue->failureCause);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigurationAck");

   stat = asn1PD_e2ap_updateOutcome (pctxt, &pvalue->updateOutcome);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_failure (pctxt, &pvalue->failure);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_failureCausePresent = TRUE;
      stat = asn1PD_e2ap_Cause (pctxt, &pvalue->failureCause);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_failureCausePresent = FALSE;

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigurationAck (e2ap_E2nodeComponentConfigurationAck* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_updateOutcome (&pvalue->updateOutcome);
   asn1Init_e2ap_failure (&pvalue->failure);
   asn1Init_e2ap_Cause (&pvalue->failureCause);
}

void asn1Free_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue)
{
   %}
   asn1Free_e2ap_updateOutcome (pctxt, &pvalue->updateOutcome);
   %}
   asn1Free_e2ap_failure (pctxt, &pvalue->failure);
   %}
   asn1Free_e2ap_Cause (pctxt, &pvalue->failureCause);
}