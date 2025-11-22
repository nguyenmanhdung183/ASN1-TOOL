/*****************************************/
/*           RICsubscriptionAuditActionList                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICsubscriptionAuditActionList;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditActionList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditActionList* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditActionList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditActionList* ppvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionAuditActionList (e2ap_RICsubscriptionAuditActionList* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditActionList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditActionList* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditActionList (const char* name, e2ap_RICsubscriptionAuditActionList* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICsubscriptionAuditActionList (OSCTXT* pctxt, const e2ap_RICsubscriptionAuditActionList* pSrcValue, e2ap_RICsubscriptionAuditActionList* pDstValue);
EXTERN void asn1Print_e2ap_RICsubscriptionAuditActionList (const char *name, const e2ap_RICsubscriptionAuditActionList* pvalue);