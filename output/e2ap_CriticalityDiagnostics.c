
int asn1PE_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "CriticalityDiagnostics");

   if (pvalue->m_procedureCodePresent) {
   stat = asn1PE_e2ap_ProcedureCode (pctxt, &pvalue->procedureCode);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_triggeringMessagePresent) {
   stat = asn1PE_e2ap_TriggeringMessage (pctxt, &pvalue->triggeringMessage);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_procedureCriticalityPresent) {
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->procedureCriticality);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_ricRequestorIDPresent) {
   stat = asn1PE_e2ap_RICrequestID (pctxt, &pvalue->ricRequestorID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_iEsCriticalityDiagnosticsPresent) {
   stat = asn1PE_e2ap_CriticalityDiagnostics-IE-List (pctxt, &pvalue->iEsCriticalityDiagnostics);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "CriticalityDiagnostics");

   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_procedureCodePresent = TRUE;
      stat = asn1PD_e2ap_ProcedureCode (pctxt, &pvalue->procedureCode);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_procedureCodePresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_triggeringMessagePresent = TRUE;
      stat = asn1PD_e2ap_TriggeringMessage (pctxt, &pvalue->triggeringMessage);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_triggeringMessagePresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_procedureCriticalityPresent = TRUE;
      stat = asn1PD_e2ap_Criticality (pctxt, &pvalue->procedureCriticality);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_procedureCriticalityPresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_ricRequestorIDPresent = TRUE;
      stat = asn1PD_e2ap_RICrequestID (pctxt, &pvalue->ricRequestorID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_ricRequestorIDPresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_iEsCriticalityDiagnosticsPresent = TRUE;
      stat = asn1PD_e2ap_CriticalityDiagnostics-IE-List (pctxt, &pvalue->iEsCriticalityDiagnostics);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_iEsCriticalityDiagnosticsPresent = FALSE;

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_CriticalityDiagnostics (e2ap_CriticalityDiagnostics* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_ProcedureCode (&pvalue->procedureCode);
   asn1Init_e2ap_TriggeringMessage (&pvalue->triggeringMessage);
   asn1Init_e2ap_Criticality (&pvalue->procedureCriticality);
   asn1Init_e2ap_RICrequestID (&pvalue->ricRequestorID);
   asn1Init_e2ap_CriticalityDiagnostics-IE-List (&pvalue->iEsCriticalityDiagnostics);
}

void asn1Free_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue)
{
   %}
   asn1Free_e2ap_ProcedureCode (pctxt, &pvalue->procedureCode);
   %}
   asn1Free_e2ap_TriggeringMessage (pctxt, &pvalue->triggeringMessage);
   %}
   asn1Free_e2ap_Criticality (pctxt, &pvalue->procedureCriticality);
   %}
   asn1Free_e2ap_RICrequestID (pctxt, &pvalue->ricRequestorID);
   %}
   asn1Free_e2ap_CriticalityDiagnostics-IE-List (pctxt, &pvalue->iEsCriticalityDiagnostics);
}