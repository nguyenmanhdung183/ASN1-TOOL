/*****************************************/
/*           E2nodeComponentInterfaceE1                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceE1 {
   e2ap_GNB_CU_UP_ID gNB_CU_UP_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceE1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceE1 (e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceE1 (const char* name, const e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceE1 (const char* name, e2ap_E2nodeComponentInterfaceE1* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceE1* pSrcValue, e2ap_E2nodeComponentInterfaceE1* pDstValue);