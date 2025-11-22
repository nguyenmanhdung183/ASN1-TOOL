/*****************************************/
/*           RICactionDefinition                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICactionDefinition;

EXTERN int asn1PE_e2ap_RICactionDefinition (OSCTXT* pctxt, e2ap_RICactionDefinition* pvalue);
EXTERN int asn1PD_e2ap_RICactionDefinition (OSCTXT* pctxt, e2ap_RICactionDefinition** ppvalue);
EXTERN void asn1Print_e2ap_RICactionDefinition (const char* name, const e2ap_RICactionDefinition* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactionDefinition (const char* name, e2ap_RICactionDefinition* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICactionDefinition (OSCTXT* pctxt, const char* name, const e2ap_RICactionDefinition* pvalue);
EXTERN int asn1Copy_e2ap_RICactionDefinition (OSCTXT* pctxt, const e2ap_RICactionDefinition* pSrcValue, e2ap_RICactionDefinition* pDstValue);
EXTERN int asn1Init_e2ap_RICactionDefinition (e2ap_RICactionDefinition* pvalue);
EXTERN void asn1Free_e2ap_RICactionDefinition (OSCTXT* pctxt, e2ap_RICactionDefinition* pvalue);