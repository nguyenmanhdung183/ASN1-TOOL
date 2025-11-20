/*****************************************/
/*           E2nodeComponentInterfaceX2                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceX2 {
   e2ap_GlobalENB-ID global_eNB_ID;
     OSBOOL m_global_eNB_IDPresent;   e2ap_GlobalenGNB-ID global_en_gNB_ID;
     OSBOOL m_global_en_gNB_IDPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceX2;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceX2 (e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceX2 (const char* name, const e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceX2 (const char* name, e2ap_E2nodeComponentInterfaceX2* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceX2* pSrcValue, e2ap_E2nodeComponentInterfaceX2* pDstValue);