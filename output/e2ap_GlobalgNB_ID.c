
int asn1PE_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalgNB_ID");

   stat = asn1PE_e2ap_PLMN-Identity (pctxt, &pvalue->plmn_id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_GNB-ID-Choice (pctxt, &pvalue->gnb_id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalgNB_ID");

   stat = asn1PD_e2ap_PLMN-Identity (pctxt, &pvalue->plmn_id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_GNB-ID-Choice (pctxt, &pvalue->gnb_id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_GlobalgNB_ID (e2ap_GlobalgNB_ID* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_PLMN-Identity (&pvalue->plmn_id);
   asn1Init_e2ap_GNB-ID-Choice (&pvalue->gnb_id);
}

void asn1Free_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue)
{
   %}
   asn1Free_e2ap_PLMN-Identity (pctxt, &pvalue->plmn_id);
   %}
   asn1Free_e2ap_GNB-ID-Choice (pctxt, &pvalue->gnb_id);
}