/*****************************************/
/*           RICassistanceHeader                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICassistanceHeader;

EXTERN int asn1PE_e2ap_RICassistanceHeader (OSCTXT* pctxt, e2ap_RICassistanceHeader* pvalue);
EXTERN int asn1PD_e2ap_RICassistanceHeader (OSCTXT* pctxt, e2ap_RICassistanceHeader** ppvalue);
EXTERN void asn1Print_e2ap_RICassistanceHeader (const char* name, const e2ap_RICassistanceHeader* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceHeader (const char* name, e2ap_RICassistanceHeader* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICassistanceHeader (OSCTXT* pctxt, const char* name, const e2ap_RICassistanceHeader* pvalue);
EXTERN int asn1Copy_e2ap_RICassistanceHeader (OSCTXT* pctxt, const e2ap_RICassistanceHeader* pSrcValue, e2ap_RICassistanceHeader* pDstValue);
EXTERN int asn1Init_e2ap_RICassistanceHeader (e2ap_RICassistanceHeader* pvalue);
EXTERN void asn1Free_e2ap_RICassistanceHeader (OSCTXT* pctxt, e2ap_RICassistanceHeader* pvalue);