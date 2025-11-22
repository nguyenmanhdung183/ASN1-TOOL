/*****************************************/
/*           RICqueryHeader                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICqueryHeader;

EXTERN int asn1PE_e2ap_RICqueryHeader (OSCTXT* pctxt, e2ap_RICqueryHeader* pvalue);
EXTERN int asn1PD_e2ap_RICqueryHeader (OSCTXT* pctxt, e2ap_RICqueryHeader** ppvalue);
EXTERN void asn1Print_e2ap_RICqueryHeader (const char* name, const e2ap_RICqueryHeader* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICqueryHeader (const char* name, e2ap_RICqueryHeader* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICqueryHeader (OSCTXT* pctxt, const char* name, const e2ap_RICqueryHeader* pvalue);
EXTERN int asn1Copy_e2ap_RICqueryHeader (OSCTXT* pctxt, const e2ap_RICqueryHeader* pSrcValue, e2ap_RICqueryHeader* pDstValue);
EXTERN int asn1Init_e2ap_RICqueryHeader (e2ap_RICqueryHeader* pvalue);
EXTERN void asn1Free_e2ap_RICqueryHeader (OSCTXT* pctxt, e2ap_RICqueryHeader* pvalue);