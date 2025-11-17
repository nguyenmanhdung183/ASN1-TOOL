
int asn1PE_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceS1");

   stat = asn1PE_e2ap_MMEname (pctxt, &pvalue->mme_name );
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceS1");

   stat = asn1PD_e2ap_MMEname (pctxt, &pvalue->mme_name );
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentInterfaceS1 (e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_MMEname (&pvalue->mme_name );
}

void asn1Free_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   %}
   asn1Free_e2ap_MMEname (pctxt, &pvalue->mme_name );
}