/*****************************************/
/*           E2nodeComponentInterfaceNG                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceNG {
   e2ap_AMFName amf_name;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceNG;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceNG (e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceNG (const char* name, const e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceNG (const char* name, e2ap_E2nodeComponentInterfaceNG* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceNG* pSrcValue, e2ap_E2nodeComponentInterfaceNG* pDstValue);