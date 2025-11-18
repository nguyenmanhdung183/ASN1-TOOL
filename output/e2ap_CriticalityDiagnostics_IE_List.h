
//seq normal

typedef struct e2ap_CriticalityDiagnostics_IE_List {
   e2ap_Criticality iECriticality;
   e2ap_ProtocolIE-ID iE_ID;
   e2ap_TypeOfError typeOfError;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_CriticalityDiagnostics_IE_List;

EXTERN int asn1PE_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN int asn1PD_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN void asn1Init_e2ap_CriticalityDiagnostics_IE_List (e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN void asn1Free_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN void asn1Print_e2ap_CriticalityDiagnostics_IE_List (const char* name, const e2ap_CriticalityDiagnostics_IE_List* pvalue);