
int asn1PE_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "CauseServiceLayer");

   stat = asn1PE_e2ap_ServiceLayerCause (pctxt, &pvalue->serviceLayerCause);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "CauseServiceLayer");

   stat = asn1PD_e2ap_ServiceLayerCause (pctxt, &pvalue->serviceLayerCause);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_CauseServiceLayer (e2ap_CauseServiceLayer* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_ServiceLayerCause (&pvalue->serviceLayerCause);
}

void asn1Free_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue)
{
   %}
   asn1Free_e2ap_ServiceLayerCause (pctxt, &pvalue->serviceLayerCause);
}