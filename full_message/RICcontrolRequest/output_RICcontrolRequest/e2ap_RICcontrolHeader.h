/*****************************************/
/*           RICcontrolHeader                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICcontrolHeader;

EXTERN int asn1PE_e2ap_RICcontrolHeader (OSCTXT* pctxt, e2ap_RICcontrolHeader* pvalue);
EXTERN int asn1PD_e2ap_RICcontrolHeader (OSCTXT* pctxt, e2ap_RICcontrolHeader** ppvalue);
EXTERN void asn1Print_e2ap_RICcontrolHeader (const char* name, const e2ap_RICcontrolHeader* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICcontrolHeader (const char* name, e2ap_RICcontrolHeader* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICcontrolHeader (OSCTXT* pctxt, const char* name, const e2ap_RICcontrolHeader* pvalue);
EXTERN int asn1Copy_e2ap_RICcontrolHeader (OSCTXT* pctxt, const e2ap_RICcontrolHeader* pSrcValue, e2ap_RICcontrolHeader* pDstValue);
EXTERN int asn1Init_e2ap_RICcontrolHeader (e2ap_RICcontrolHeader* pvalue);
EXTERN void asn1Free_e2ap_RICcontrolHeader (OSCTXT* pctxt, e2ap_RICcontrolHeader* pvalue);