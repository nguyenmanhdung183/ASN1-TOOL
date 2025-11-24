/*****************************************/
/*           E2nodeConfigurationUpdateAcknowledge                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeConfigurationUpdateAcknowledge {
e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeConfigurationUpdateAcknowledge;

EXTERN int asn1PE_e2ap_E2nodeConfigurationUpdateAcknowledge (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge* pvalue);
EXTERN int asn1PD_e2ap_E2nodeConfigurationUpdateAcknowledge (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge* pvalue);
EXTERN int asn1Init_e2ap_E2nodeConfigurationUpdateAcknowledge (e2ap_E2nodeConfigurationUpdateAcknowledge* pvalue);
EXTERN void asn1Free_e2ap_E2nodeConfigurationUpdateAcknowledge (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge* pvalue);
EXTERN void asn1Print_e2ap_E2nodeConfigurationUpdateAcknowledge (const char* name, const e2ap_E2nodeConfigurationUpdateAcknowledge* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeConfigurationUpdateAcknowledge (const char* name, e2ap_E2nodeConfigurationUpdateAcknowledge* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeConfigurationUpdateAcknowledge (OSCTXT* pctxt, const char* name, const e2ap_E2nodeConfigurationUpdateAcknowledge* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeConfigurationUpdateAcknowledge (OSCTXT* pctxt, const e2ap_E2nodeConfigurationUpdateAcknowledge* pSrcValue, e2ap_E2nodeConfigurationUpdateAcknowledge* pDstValue);