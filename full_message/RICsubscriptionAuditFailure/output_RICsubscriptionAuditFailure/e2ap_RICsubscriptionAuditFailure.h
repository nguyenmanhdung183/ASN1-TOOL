/*****************************************/
/*           RICsubscriptionAuditFailure                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionAuditFailure {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionAuditFailure;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditFailure (OSCTXT* pctxt, e2ap_RICsubscriptionAuditFailure* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditFailure (OSCTXT* pctxt, e2ap_RICsubscriptionAuditFailure* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAuditFailure (e2ap_RICsubscriptionAuditFailure* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditFailure (OSCTXT* pctxt, e2ap_RICsubscriptionAuditFailure* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionAuditFailure (const char* name, const e2ap_RICsubscriptionAuditFailure* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditFailure (const char* name, e2ap_RICsubscriptionAuditFailure* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionAuditFailure (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionAuditFailure* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionAuditFailure (OSCTXT* pctxt, const e2ap_RICsubscriptionAuditFailure* pSrcValue, e2ap_RICsubscriptionAuditFailure* pDstValue);