/*****************************************/
/*           RICsubscriptionAuditFlag                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionAuditFlag {
   e2ap_ListedRecordsOnly listedRecordsOnly;
     OSBOOL m_listedRecordsOnlyPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionAuditFlag;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditFlag (OSCTXT* pctxt, e2ap_RICsubscriptionAuditFlag* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditFlag (OSCTXT* pctxt, e2ap_RICsubscriptionAuditFlag* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAuditFlag (e2ap_RICsubscriptionAuditFlag* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditFlag (OSCTXT* pctxt, e2ap_RICsubscriptionAuditFlag* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionAuditFlag (const char* name, const e2ap_RICsubscriptionAuditFlag* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditFlag (const char* name, e2ap_RICsubscriptionAuditFlag* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionAuditFlag (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionAuditFlag* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionAuditFlag (OSCTXT* pctxt, const e2ap_RICsubscriptionAuditFlag* pSrcValue, e2ap_RICsubscriptionAuditFlag* pDstValue);