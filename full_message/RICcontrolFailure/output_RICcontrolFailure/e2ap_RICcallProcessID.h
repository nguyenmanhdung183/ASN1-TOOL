/*****************************************/
/*           RICcallProcessID                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICcallProcessID;

EXTERN int asn1PE_e2ap_RICcallProcessID (OSCTXT* pctxt, e2ap_RICcallProcessID* pvalue);
EXTERN int asn1PD_e2ap_RICcallProcessID (OSCTXT* pctxt, e2ap_RICcallProcessID** ppvalue);
EXTERN void asn1Print_e2ap_RICcallProcessID (const char* name, const e2ap_RICcallProcessID* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICcallProcessID (const char* name, e2ap_RICcallProcessID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICcallProcessID (OSCTXT* pctxt, const char* name, const e2ap_RICcallProcessID* pvalue);
EXTERN int asn1Copy_e2ap_RICcallProcessID (OSCTXT* pctxt, const e2ap_RICcallProcessID* pSrcValue, e2ap_RICcallProcessID* pDstValue);
EXTERN int asn1Init_e2ap_RICcallProcessID (e2ap_RICcallProcessID* pvalue);
EXTERN void asn1Free_e2ap_RICcallProcessID (OSCTXT* pctxt, e2ap_RICcallProcessID* pvalue);