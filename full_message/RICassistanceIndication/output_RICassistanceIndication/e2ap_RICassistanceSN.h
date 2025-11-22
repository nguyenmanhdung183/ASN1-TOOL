/*****************************************/
/*        RICassistanceSN         */
/*****************************************/
//interger no ext


typedef OSUINT16 e2ap_RICassistanceSN;

EXTERN int asn1PE_e2ap_RICassistanceSN (OSCTXT* pctxt, e2ap_RICassistanceSN value);
EXTERN int asn1PD_e2ap_RICassistanceSN (OSCTXT* pctxt, e2ap_RICassistanceSN* pvalue);
EXTERN void asn1Print_e2ap_RICassistanceSN (const char* name, const e2ap_RICassistanceSN* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceSN (const char* name, e2ap_RICassistanceSN* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICassistanceSN (OSCTXT* pctxt, const char* name, const e2ap_RICassistanceSN* pvalue);