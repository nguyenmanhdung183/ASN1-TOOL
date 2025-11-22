/*****************************************/
/*           RICcontrolOutcome                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICcontrolOutcome;

EXTERN int asn1PE_e2ap_RICcontrolOutcome (OSCTXT* pctxt, e2ap_RICcontrolOutcome* pvalue);
EXTERN int asn1PD_e2ap_RICcontrolOutcome (OSCTXT* pctxt, e2ap_RICcontrolOutcome** ppvalue);
EXTERN void asn1Print_e2ap_RICcontrolOutcome (const char* name, const e2ap_RICcontrolOutcome* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICcontrolOutcome (const char* name, e2ap_RICcontrolOutcome* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICcontrolOutcome (OSCTXT* pctxt, const char* name, const e2ap_RICcontrolOutcome* pvalue);
EXTERN int asn1Copy_e2ap_RICcontrolOutcome (OSCTXT* pctxt, const e2ap_RICcontrolOutcome* pSrcValue, e2ap_RICcontrolOutcome* pDstValue);
EXTERN int asn1Init_e2ap_RICcontrolOutcome (e2ap_RICcontrolOutcome* pvalue);
EXTERN void asn1Free_e2ap_RICcontrolOutcome (OSCTXT* pctxt, e2ap_RICcontrolOutcome* pvalue);