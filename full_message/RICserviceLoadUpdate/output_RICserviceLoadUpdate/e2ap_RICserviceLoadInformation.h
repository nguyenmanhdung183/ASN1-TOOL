/*****************************************/
/*           RICserviceLoadInformation                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICserviceLoadInformation {
   e2ap_RICloadInformation ricServiceReportLoadInformation;
     OSBOOL m_ricServiceReportLoadInformationPresent;   e2ap_RICloadInformation ricServiceInsertLoadInformation;
     OSBOOL m_ricServiceInsertLoadInformationPresent;   e2ap_RICloadInformation ricServiceControlLoadInformation;
     OSBOOL m_ricServiceControlLoadInformationPresent;   e2ap_RICloadInformation ricServicePolicyLoadInformation;
     OSBOOL m_ricServicePolicyLoadInformationPresent;   e2ap_RICloadInformation ricServiceQueryLoadInformation;
     OSBOOL m_ricServiceQueryLoadInformationPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICserviceLoadInformation;

EXTERN int asn1PE_e2ap_RICserviceLoadInformation (OSCTXT* pctxt, e2ap_RICserviceLoadInformation* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadInformation (OSCTXT* pctxt, e2ap_RICserviceLoadInformation* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadInformation (e2ap_RICserviceLoadInformation* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadInformation (OSCTXT* pctxt, e2ap_RICserviceLoadInformation* pvalue);
EXTERN void asn1Print_e2ap_RICserviceLoadInformation (const char* name, const e2ap_RICserviceLoadInformation* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadInformation (const char* name, e2ap_RICserviceLoadInformation* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICserviceLoadInformation (OSCTXT* pctxt, const char* name, const e2ap_RICserviceLoadInformation* pvalue);
EXTERN int asn1Copy_e2ap_RICserviceLoadInformation (OSCTXT* pctxt, const e2ap_RICserviceLoadInformation* pSrcValue, e2ap_RICserviceLoadInformation* pDstValue);