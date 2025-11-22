/*****************************************/
/*           RICindicationHeader                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICindicationHeader;

EXTERN int asn1PE_e2ap_RICindicationHeader (OSCTXT* pctxt, e2ap_RICindicationHeader* pvalue);
EXTERN int asn1PD_e2ap_RICindicationHeader (OSCTXT* pctxt, e2ap_RICindicationHeader** ppvalue);
EXTERN void asn1Print_e2ap_RICindicationHeader (const char* name, const e2ap_RICindicationHeader* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICindicationHeader (const char* name, e2ap_RICindicationHeader* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICindicationHeader (OSCTXT* pctxt, const char* name, const e2ap_RICindicationHeader* pvalue);
EXTERN int asn1Copy_e2ap_RICindicationHeader (OSCTXT* pctxt, const e2ap_RICindicationHeader* pSrcValue, e2ap_RICindicationHeader* pDstValue);
EXTERN int asn1Init_e2ap_RICindicationHeader (e2ap_RICindicationHeader* pvalue);
EXTERN void asn1Free_e2ap_RICindicationHeader (OSCTXT* pctxt, e2ap_RICindicationHeader* pvalue);