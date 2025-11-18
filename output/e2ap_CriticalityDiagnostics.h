
//seq normal

typedef struct e2ap_CriticalityDiagnostics {
   e2ap_ProcedureCode procedureCode;
OSBOOL m_procedureCodePresent;   e2ap_TriggeringMessage triggeringMessage;
OSBOOL m_triggeringMessagePresent;   e2ap_Criticality procedureCriticality;
OSBOOL m_procedureCriticalityPresent;   e2ap_RICrequestID ricRequestorID;
OSBOOL m_ricRequestorIDPresent;   e2ap_CriticalityDiagnostics-IE-List iEsCriticalityDiagnostics;
OSBOOL m_iEsCriticalityDiagnosticsPresent;ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_CriticalityDiagnostics;

EXTERN int asn1PE_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue);
EXTERN int asn1PD_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue);
EXTERN void asn1Init_e2ap_CriticalityDiagnostics (e2ap_CriticalityDiagnostics* pvalue);
EXTERN void asn1Free_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue);
EXTERN void asn1Print_e2ap_CriticalityDiagnostics (const char* name, const e2ap_CriticalityDiagnostics* pvalue);