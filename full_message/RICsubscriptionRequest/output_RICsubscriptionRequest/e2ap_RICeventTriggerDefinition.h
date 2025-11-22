/*****************************************/
/*           RICeventTriggerDefinition                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICeventTriggerDefinition;

EXTERN int asn1PE_e2ap_RICeventTriggerDefinition (OSCTXT* pctxt, e2ap_RICeventTriggerDefinition* pvalue);
EXTERN int asn1PD_e2ap_RICeventTriggerDefinition (OSCTXT* pctxt, e2ap_RICeventTriggerDefinition** ppvalue);
EXTERN void asn1Print_e2ap_RICeventTriggerDefinition (const char* name, const e2ap_RICeventTriggerDefinition* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICeventTriggerDefinition (const char* name, e2ap_RICeventTriggerDefinition* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICeventTriggerDefinition (OSCTXT* pctxt, const char* name, const e2ap_RICeventTriggerDefinition* pvalue);
EXTERN int asn1Copy_e2ap_RICeventTriggerDefinition (OSCTXT* pctxt, const e2ap_RICeventTriggerDefinition* pSrcValue, e2ap_RICeventTriggerDefinition* pDstValue);
EXTERN int asn1Init_e2ap_RICeventTriggerDefinition (e2ap_RICeventTriggerDefinition* pvalue);
EXTERN void asn1Free_e2ap_RICeventTriggerDefinition (OSCTXT* pctxt, e2ap_RICeventTriggerDefinition* pvalue);