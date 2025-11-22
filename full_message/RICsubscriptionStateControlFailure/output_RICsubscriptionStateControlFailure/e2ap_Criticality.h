/******************************************************/
/*                                                    */
/*    Criticality                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_reject = 0,
    e2ap_ignore = 1,
    e2ap_notify = 2
} e2ap_Criticality_Root;

typedef OSUINT32 e2ap_Criticality;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_Criticality (OSCTXT* pctxt, e2ap_Criticality value);
EXTERN int asn1PD_e2ap_Criticality (OSCTXT* pctxt, e2ap_Criticality* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_Criticality (const char* name, const e2ap_Criticality* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_Criticality (OSCTXT* pctxt, const char* name, const e2ap_Criticality* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_Criticality (const char* name,const e2ap_Criticality* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_Criticality_ENUMTAB[];
#define e2ap_Criticality_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_Criticality_ToString (OSUINT32 value);
EXTERN int e2ap_Criticality_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_Criticality* pvalue);
EXTERN int e2ap_Criticality_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_Criticality* pvalue);