/*****************************************/
/*        RICindicationSN         */
/*****************************************/
//interger no ext


typedef OSUINT16 e2ap_RICindicationSN;

EXTERN int asn1PE_e2ap_RICindicationSN (OSCTXT* pctxt, e2ap_RICindicationSN value);
EXTERN int asn1PD_e2ap_RICindicationSN (OSCTXT* pctxt, e2ap_RICindicationSN* pvalue);
EXTERN void asn1Print_e2ap_RICindicationSN (const char* name, const e2ap_RICindicationSN* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICindicationSN (const char* name, e2ap_RICindicationSN* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICindicationSN (OSCTXT* pctxt, const char* name, const e2ap_RICindicationSN* pvalue);