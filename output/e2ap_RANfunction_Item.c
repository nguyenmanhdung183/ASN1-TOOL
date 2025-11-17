
int asn1PE_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "RANfunction_Item");

   stat = asn1PE_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_RANfunctionDefinition (pctxt, &pvalue->ranFunctionDefinition);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_RANfunctionOID (pctxt, &pvalue->ranFunctionOID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "RANfunction_Item");

   stat = asn1PD_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_RANfunctionDefinition (pctxt, &pvalue->ranFunctionDefinition);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_RANfunctionOID (pctxt, &pvalue->ranFunctionOID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_RANfunction_Item (e2ap_RANfunction_Item* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_RANfunctionID (&pvalue->ranFunctionID);
   asn1Init_e2ap_RANfunctionDefinition (&pvalue->ranFunctionDefinition);
   asn1Init_e2ap_RANfunctionRevision (&pvalue->ranFunctionRevision);
   asn1Init_e2ap_RANfunctionOID (&pvalue->ranFunctionOID);
}

void asn1Free_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue)
{
   %}
   asn1Free_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   %}
   asn1Free_e2ap_RANfunctionDefinition (pctxt, &pvalue->ranFunctionDefinition);
   %}
   asn1Free_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
   %}
   asn1Free_e2ap_RANfunctionOID (pctxt, &pvalue->ranFunctionOID);
}