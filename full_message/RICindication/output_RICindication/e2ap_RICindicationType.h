/******************************************************/
/*                                                    */
/*    RICindicationType                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_report = 0,
    e2ap_insert = 1
} e2ap_RICindicationType_Root;

typedef OSUINT32 e2ap_RICindicationType;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICindicationType (OSCTXT* pctxt, e2ap_RICindicationType value);
EXTERN int asn1PD_e2ap_RICindicationType (OSCTXT* pctxt, e2ap_RICindicationType* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICindicationType (const char* name, const e2ap_RICindicationType* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICindicationType (OSCTXT* pctxt, const char* name, const e2ap_RICindicationType* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICindicationType (const char* name,const e2ap_RICindicationType* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICindicationType_ENUMTAB[];
#define e2ap_RICindicationType_ENUMTABSIZE 2

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICindicationType_ToString (OSUINT32 value);
EXTERN int e2ap_RICindicationType_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICindicationType* pvalue);
EXTERN int e2ap_RICindicationType_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICindicationType* pvalue);