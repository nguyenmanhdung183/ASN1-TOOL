/*****************************************/
/*           E2nodeComponentConfiguration                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentConfiguration {
   e2ap_e2nodeComponentRequestPart e2nodeComponentRequestPart;
   e2ap_e2nodeComponentResponsePart e2nodeComponentResponsePart;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentConfiguration;

EXTERN int asn1PE_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentConfiguration (e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfiguration (const char* name, const e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentConfiguration (const char* name, e2ap_E2nodeComponentConfiguration* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, const e2ap_E2nodeComponentConfiguration* pSrcValue, e2ap_E2nodeComponentConfiguration* pDstValue);