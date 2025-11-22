/*****************************************/
/*           RICindicationMessage                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICindicationMessage;

EXTERN int asn1PE_e2ap_RICindicationMessage (OSCTXT* pctxt, e2ap_RICindicationMessage* pvalue);
EXTERN int asn1PD_e2ap_RICindicationMessage (OSCTXT* pctxt, e2ap_RICindicationMessage** ppvalue);
EXTERN void asn1Print_e2ap_RICindicationMessage (const char* name, const e2ap_RICindicationMessage* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICindicationMessage (const char* name, e2ap_RICindicationMessage* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICindicationMessage (OSCTXT* pctxt, const char* name, const e2ap_RICindicationMessage* pvalue);
EXTERN int asn1Copy_e2ap_RICindicationMessage (OSCTXT* pctxt, const e2ap_RICindicationMessage* pSrcValue, e2ap_RICindicationMessage* pDstValue);
EXTERN int asn1Init_e2ap_RICindicationMessage (e2ap_RICindicationMessage* pvalue);
EXTERN void asn1Free_e2ap_RICindicationMessage (OSCTXT* pctxt, e2ap_RICindicationMessage* pvalue);