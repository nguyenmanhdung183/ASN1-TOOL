/*****************************************/
/*           CriticalityDiagnostics_IE_List                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_CriticalityDiagnostics_IE_List {
   e2ap_Criticality iECriticality;
   e2ap_ProtocolIE-ID iE_ID;
   e2ap_TypeOfError typeOfError;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_CriticalityDiagnostics_IE_List;

EXTERN int asn1PE_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN int asn1PD_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN int asn1Init_e2ap_CriticalityDiagnostics_IE_List (e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN void asn1Free_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN void asn1Print_e2ap_CriticalityDiagnostics_IE_List (const char* name, const e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_CriticalityDiagnostics_IE_List (const char* name, e2ap_CriticalityDiagnostics_IE_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, const char* name, const e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN int asn1Copy_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, const e2ap_CriticalityDiagnostics_IE_List* pSrcValue, e2ap_CriticalityDiagnostics_IE_List* pDstValue);