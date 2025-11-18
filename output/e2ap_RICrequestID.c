
int asn1PE_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "RICrequestID");

   stat = asn1PE_e2ap_ricRequestorID (pctxt, &pvalue->ricRequestorID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_ricInstanceID (pctxt, &pvalue->ricInstanceID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "RICrequestID");

   stat = asn1PD_e2ap_ricRequestorID (pctxt, &pvalue->ricRequestorID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_ricInstanceID (pctxt, &pvalue->ricInstanceID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_RICrequestID (e2ap_RICrequestID* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_ricRequestorID (&pvalue->ricRequestorID);
   asn1Init_e2ap_ricInstanceID (&pvalue->ricInstanceID);
}

void asn1Free_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue)
{
   %}
   asn1Free_e2ap_ricRequestorID (pctxt, &pvalue->ricRequestorID);
   %}
   asn1Free_e2ap_ricInstanceID (pctxt, &pvalue->ricInstanceID);
}