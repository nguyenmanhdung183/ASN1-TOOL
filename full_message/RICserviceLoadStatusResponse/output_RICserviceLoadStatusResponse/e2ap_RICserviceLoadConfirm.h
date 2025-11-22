/*****************************************/
/*           RICserviceLoadConfirm                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICserviceLoadConfirm {
   e2ap_RICloadConfirm ricServiceReportLoadConfirm;
     OSBOOL m_ricServiceReportLoadConfirmPresent;   e2ap_RICloadConfirm ricServiceInsertLoadConfirm;
     OSBOOL m_ricServiceInsertLoadConfirmPresent;   e2ap_RICloadConfirm ricServiceControlLoadConfirm;
     OSBOOL m_ricServiceControlLoadConfirmPresent;   e2ap_RICloadConfirm ricServicePolicyLoadConfirm;
     OSBOOL m_ricServicePolicyLoadConfirmPresent;   e2ap_RICloadConfirm ricServiceQueryLoadConfirm;
     OSBOOL m_ricServiceQueryLoadConfirmPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICserviceLoadConfirm;

EXTERN int asn1PE_e2ap_RICserviceLoadConfirm (OSCTXT* pctxt, e2ap_RICserviceLoadConfirm* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadConfirm (OSCTXT* pctxt, e2ap_RICserviceLoadConfirm* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadConfirm (e2ap_RICserviceLoadConfirm* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadConfirm (OSCTXT* pctxt, e2ap_RICserviceLoadConfirm* pvalue);
EXTERN void asn1Print_e2ap_RICserviceLoadConfirm (const char* name, const e2ap_RICserviceLoadConfirm* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadConfirm (const char* name, e2ap_RICserviceLoadConfirm* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICserviceLoadConfirm (OSCTXT* pctxt, const char* name, const e2ap_RICserviceLoadConfirm* pvalue);
EXTERN int asn1Copy_e2ap_RICserviceLoadConfirm (OSCTXT* pctxt, const e2ap_RICserviceLoadConfirm* pSrcValue, e2ap_RICserviceLoadConfirm* pDstValue);