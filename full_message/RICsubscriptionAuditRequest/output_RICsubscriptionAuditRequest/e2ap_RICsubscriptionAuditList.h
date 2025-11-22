/*****************************************/
/*           RICsubscriptionAuditList                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICsubscriptionAuditList;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditList* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditList* ppvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionAuditList (e2ap_RICsubscriptionAuditList* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditList* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditList (const char* name, e2ap_RICsubscriptionAuditList* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICsubscriptionAuditList (OSCTXT* pctxt, const e2ap_RICsubscriptionAuditList* pSrcValue, e2ap_RICsubscriptionAuditList* pDstValue);
EXTERN void asn1Print_e2ap_RICsubscriptionAuditList (const char *name, const e2ap_RICsubscriptionAuditList* pvalue);