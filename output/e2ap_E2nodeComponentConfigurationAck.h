/*****************************************/
/*           E2nodeComponentConfigurationAck                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentConfigurationAck {
   e2ap_ENUMERATED updateOutcome;
   e2ap_failure failure;
   e2ap_Cause failureCause;
     OSBOOL m_failureCausePresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentConfigurationAck;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentConfigurationAck (e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigurationAck (const char* name, const e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentConfigurationAck (const char* name, e2ap_E2nodeComponentConfigurationAck* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, const e2ap_E2nodeComponentConfigurationAck* pSrcValue, e2ap_E2nodeComponentConfigurationAck* pDstValue);