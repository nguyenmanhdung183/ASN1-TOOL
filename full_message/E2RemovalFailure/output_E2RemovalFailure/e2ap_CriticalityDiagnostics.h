/*****************************************/
/*           CriticalityDiagnostics                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_CriticalityDiagnostics {
   e2ap_ProcedureCode procedureCode;
     OSBOOL m_procedureCodePresent;   e2ap_TriggeringMessage triggeringMessage;
     OSBOOL m_triggeringMessagePresent;   e2ap_Criticality procedureCriticality;
     OSBOOL m_procedureCriticalityPresent;   e2ap_RICrequestID ricRequestorID;
     OSBOOL m_ricRequestorIDPresent;   e2ap_CriticalityDiagnostics-IE-List iEsCriticalityDiagnostics;
     OSBOOL m_iEsCriticalityDiagnosticsPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_CriticalityDiagnostics;

EXTERN int asn1PE_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue);
EXTERN int asn1PD_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue);
EXTERN int asn1Init_e2ap_CriticalityDiagnostics (e2ap_CriticalityDiagnostics* pvalue);
EXTERN void asn1Free_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue);
EXTERN void asn1Print_e2ap_CriticalityDiagnostics (const char* name, const e2ap_CriticalityDiagnostics* pvalue);
EXTERN int asn1PrtToStr_e2ap_CriticalityDiagnostics (const char* name, e2ap_CriticalityDiagnostics* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, const char* name, const e2ap_CriticalityDiagnostics* pvalue);
EXTERN int asn1Copy_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, const e2ap_CriticalityDiagnostics* pSrcValue, e2ap_CriticalityDiagnostics* pDstValue);