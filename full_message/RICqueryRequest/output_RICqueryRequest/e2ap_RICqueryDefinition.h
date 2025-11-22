/*****************************************/
/*           RICqueryDefinition                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICqueryDefinition;

EXTERN int asn1PE_e2ap_RICqueryDefinition (OSCTXT* pctxt, e2ap_RICqueryDefinition* pvalue);
EXTERN int asn1PD_e2ap_RICqueryDefinition (OSCTXT* pctxt, e2ap_RICqueryDefinition** ppvalue);
EXTERN void asn1Print_e2ap_RICqueryDefinition (const char* name, const e2ap_RICqueryDefinition* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICqueryDefinition (const char* name, e2ap_RICqueryDefinition* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICqueryDefinition (OSCTXT* pctxt, const char* name, const e2ap_RICqueryDefinition* pvalue);
EXTERN int asn1Copy_e2ap_RICqueryDefinition (OSCTXT* pctxt, const e2ap_RICqueryDefinition* pSrcValue, e2ap_RICqueryDefinition* pDstValue);
EXTERN int asn1Init_e2ap_RICqueryDefinition (e2ap_RICqueryDefinition* pvalue);
EXTERN void asn1Free_e2ap_RICqueryDefinition (OSCTXT* pctxt, e2ap_RICqueryDefinition* pvalue);