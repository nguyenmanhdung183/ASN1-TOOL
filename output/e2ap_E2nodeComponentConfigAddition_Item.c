
int asn1PE_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigAddition_Item");

   stat = asn1PE_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_E2nodeComponentConfiguration (pctxt, &pvalue->e2nodeComponentConfiguration);
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigAddition_Item");

   stat = asn1PD_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_E2nodeComponentConfiguration (pctxt, &pvalue->e2nodeComponentConfiguration);
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigAddition_Item (e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_E2nodeComponentInterfaceType (&pvalue->e2nodeComponentInterfaceType);
   asn1Init_e2ap_E2nodeComponentID (&pvalue->e2nodeComponentID);
   asn1Init_e2ap_E2nodeComponentConfiguration (&pvalue->e2nodeComponentConfiguration);
}

void asn1Free_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   %}
   asn1Free_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   %}
   asn1Free_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   %}
   asn1Free_e2ap_E2nodeComponentConfiguration (pctxt, &pvalue->e2nodeComponentConfiguration);
}