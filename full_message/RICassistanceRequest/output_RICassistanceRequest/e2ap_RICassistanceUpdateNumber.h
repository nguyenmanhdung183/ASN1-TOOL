/*****************************************/
/*        RICassistanceUpdateNumber         */
/*****************************************/
//interger no ext


typedef OSUINT16 e2ap_RICassistanceUpdateNumber;

EXTERN int asn1PE_e2ap_RICassistanceUpdateNumber (OSCTXT* pctxt, e2ap_RICassistanceUpdateNumber value);
EXTERN int asn1PD_e2ap_RICassistanceUpdateNumber (OSCTXT* pctxt, e2ap_RICassistanceUpdateNumber* pvalue);
EXTERN void asn1Print_e2ap_RICassistanceUpdateNumber (const char* name, const e2ap_RICassistanceUpdateNumber* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceUpdateNumber (const char* name, e2ap_RICassistanceUpdateNumber* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICassistanceUpdateNumber (OSCTXT* pctxt, const char* name, const e2ap_RICassistanceUpdateNumber* pvalue);