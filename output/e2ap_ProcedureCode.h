/* e2ap_ProcedureCode.h */
typedef OSUINT8 e2ap_ProcedureCode;

EXTERN int asn1PE_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode value);
EXTERN int asn1PD_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode* pvalue);
EXTERN void asn1Print_e2ap_ProcedureCode (const char* name, const e2ap_ProcedureCode* pvalue);
EXTERN int asn1PrtToStr_e2ap_ProcedureCode (const char* name, e2ap_ProcedureCode* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_ProcedureCode (OSCTXT* pctxt, const char* name, const e2ap_ProcedureCode* pvalue);