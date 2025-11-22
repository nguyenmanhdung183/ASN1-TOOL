/*****************************************/
/*        RICactionExecutionOrder         */
/*****************************************/
//interger no ext


typedef OSUINT8 e2ap_RICactionExecutionOrder;

EXTERN int asn1PE_e2ap_RICactionExecutionOrder (OSCTXT* pctxt, e2ap_RICactionExecutionOrder value);
EXTERN int asn1PD_e2ap_RICactionExecutionOrder (OSCTXT* pctxt, e2ap_RICactionExecutionOrder* pvalue);
EXTERN void asn1Print_e2ap_RICactionExecutionOrder (const char* name, const e2ap_RICactionExecutionOrder* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactionExecutionOrder (const char* name, e2ap_RICactionExecutionOrder* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICactionExecutionOrder (OSCTXT* pctxt, const char* name, const e2ap_RICactionExecutionOrder* pvalue);