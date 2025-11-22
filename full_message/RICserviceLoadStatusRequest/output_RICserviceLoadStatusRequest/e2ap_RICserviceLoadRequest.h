/*****************************************/
/*           RICserviceLoadRequest                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICserviceLoadRequest {
   e2ap_RICloadRequest ricServiceReportLoadRequest;
     OSBOOL m_ricServiceReportLoadRequestPresent;   e2ap_RICloadRequest ricServiceInsertLoadRequest;
     OSBOOL m_ricServiceInsertLoadRequestPresent;   e2ap_RICloadRequest ricServiceControlLoadRequest;
     OSBOOL m_ricServiceControlLoadRequestPresent;   e2ap_RICloadRequest ricServicePolicyLoadRequest;
     OSBOOL m_ricServicePolicyLoadRequestPresent;   e2ap_RICloadRequest ricServiceQueryLoadRequest;
     OSBOOL m_ricServiceQueryLoadRequestPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICserviceLoadRequest;

EXTERN int asn1PE_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, e2ap_RICserviceLoadRequest* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, e2ap_RICserviceLoadRequest* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadRequest (e2ap_RICserviceLoadRequest* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, e2ap_RICserviceLoadRequest* pvalue);
EXTERN void asn1Print_e2ap_RICserviceLoadRequest (const char* name, const e2ap_RICserviceLoadRequest* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadRequest (const char* name, e2ap_RICserviceLoadRequest* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, const char* name, const e2ap_RICserviceLoadRequest* pvalue);
EXTERN int asn1Copy_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, const e2ap_RICserviceLoadRequest* pSrcValue, e2ap_RICserviceLoadRequest* pDstValue);