
int asn1PE_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigAdditionAck_Item");

   stat = asn1PE_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_E2nodeComponentConfigurationAck (pctxt, &pvalue->e2nodeComponentConfigurationAck);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigAdditionAck_Item");

   stat = asn1PD_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_E2nodeComponentConfigurationAck (pctxt, &pvalue->e2nodeComponentConfigurationAck);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigAdditionAck_Item (e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_E2nodeComponentInterfaceType (&pvalue->e2nodeComponentInterfaceType);
   asn1Init_e2ap_E2nodeComponentID (&pvalue->e2nodeComponentID);
   asn1Init_e2ap_E2nodeComponentConfigurationAck (&pvalue->e2nodeComponentConfigurationAck);
}

void asn1Free_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue)
{
   %}
   asn1Free_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   %}
   asn1Free_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   %}
   asn1Free_e2ap_E2nodeComponentConfigurationAck (pctxt, &pvalue->e2nodeComponentConfigurationAck);
}