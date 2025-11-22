/*****************************************/
/*           RICcontrolMessage                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICcontrolMessage;

EXTERN int asn1PE_e2ap_RICcontrolMessage (OSCTXT* pctxt, e2ap_RICcontrolMessage* pvalue);
EXTERN int asn1PD_e2ap_RICcontrolMessage (OSCTXT* pctxt, e2ap_RICcontrolMessage** ppvalue);
EXTERN void asn1Print_e2ap_RICcontrolMessage (const char* name, const e2ap_RICcontrolMessage* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICcontrolMessage (const char* name, e2ap_RICcontrolMessage* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICcontrolMessage (OSCTXT* pctxt, const char* name, const e2ap_RICcontrolMessage* pvalue);
EXTERN int asn1Copy_e2ap_RICcontrolMessage (OSCTXT* pctxt, const e2ap_RICcontrolMessage* pSrcValue, e2ap_RICcontrolMessage* pDstValue);
EXTERN int asn1Init_e2ap_RICcontrolMessage (e2ap_RICcontrolMessage* pvalue);
EXTERN void asn1Free_e2ap_RICcontrolMessage (OSCTXT* pctxt, e2ap_RICcontrolMessage* pvalue);