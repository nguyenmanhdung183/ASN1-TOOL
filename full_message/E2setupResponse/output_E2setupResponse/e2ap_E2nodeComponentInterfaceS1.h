/*****************************************/
/*           E2nodeComponentInterfaceS1                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceS1 {
   e2ap_MMEname mme_name;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceS1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceS1 (e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceS1 (const char* name, const e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceS1 (const char* name, e2ap_E2nodeComponentInterfaceS1* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceS1* pSrcValue, e2ap_E2nodeComponentInterfaceS1* pDstValue);