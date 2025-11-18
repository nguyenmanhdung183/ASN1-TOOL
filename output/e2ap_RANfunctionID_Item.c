
int asn1PE_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "RANfunctionID_Item");

   stat = asn1PE_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "RANfunctionID_Item");

   stat = asn1PD_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_RANfunctionID_Item (e2ap_RANfunctionID_Item* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_RANfunctionID (&pvalue->ranFunctionID);
   asn1Init_e2ap_RANfunctionRevision (&pvalue->ranFunctionRevision);
}

void asn1Free_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue)
{
   %}
   asn1Free_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   %}
   asn1Free_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
}