
int asn1PE_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "CriticalityDiagnostics_IE_List");

   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->iECriticality);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_ProtocolIE-ID (pctxt, &pvalue->iE_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_TypeOfError (pctxt, &pvalue->typeOfError);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "CriticalityDiagnostics_IE_List");

   stat = asn1PD_e2ap_Criticality (pctxt, &pvalue->iECriticality);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_ProtocolIE-ID (pctxt, &pvalue->iE_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_TypeOfError (pctxt, &pvalue->typeOfError);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_CriticalityDiagnostics_IE_List (e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_Criticality (&pvalue->iECriticality);
   asn1Init_e2ap_ProtocolIE-ID (&pvalue->iE_ID);
   asn1Init_e2ap_TypeOfError (&pvalue->typeOfError);
}

void asn1Free_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   %}
   asn1Free_e2ap_Criticality (pctxt, &pvalue->iECriticality);
   %}
   asn1Free_e2ap_ProtocolIE-ID (pctxt, &pvalue->iE_ID);
   %}
   asn1Free_e2ap_TypeOfError (pctxt, &pvalue->typeOfError);
}