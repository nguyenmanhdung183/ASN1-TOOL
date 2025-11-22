/******************************************************/
/*                                                    */
/*    RICactionType                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_report = 0,
    e2ap_insert = 1,
    e2ap_policy = 2
} e2ap_RICactionType_Root;

typedef OSUINT32 e2ap_RICactionType;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICactionType (OSCTXT* pctxt, e2ap_RICactionType value);
EXTERN int asn1PD_e2ap_RICactionType (OSCTXT* pctxt, e2ap_RICactionType* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICactionType (const char* name, const e2ap_RICactionType* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICactionType (OSCTXT* pctxt, const char* name, const e2ap_RICactionType* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICactionType (const char* name,const e2ap_RICactionType* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICactionType_ENUMTAB[];
#define e2ap_RICactionType_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICactionType_ToString (OSUINT32 value);
EXTERN int e2ap_RICactionType_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICactionType* pvalue);
EXTERN int e2ap_RICactionType_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICactionType* pvalue);