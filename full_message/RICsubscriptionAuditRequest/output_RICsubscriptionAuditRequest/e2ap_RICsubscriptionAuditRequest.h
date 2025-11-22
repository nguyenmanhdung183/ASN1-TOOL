/*****************************************/
/*           RICsubscriptionAuditRequest                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionAuditRequest {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionAuditRequest;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditRequest (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditRequest (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAuditRequest (e2ap_RICsubscriptionAuditRequest* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditRequest (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionAuditRequest (const char* name, const e2ap_RICsubscriptionAuditRequest* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditRequest (const char* name, e2ap_RICsubscriptionAuditRequest* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionAuditRequest (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionAuditRequest* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionAuditRequest (OSCTXT* pctxt, const e2ap_RICsubscriptionAuditRequest* pSrcValue, e2ap_RICsubscriptionAuditRequest* pDstValue);