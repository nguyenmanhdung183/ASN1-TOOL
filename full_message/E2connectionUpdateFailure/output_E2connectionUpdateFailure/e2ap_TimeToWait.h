/******************************************************/
/*                                                    */
/*    TimeToWait                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_v1s = 0,
    e2ap_v2s = 1,
    e2ap_v5s = 2,
    e2ap_v10s = 3,
    e2ap_v20s = 4,
    e2ap_v60s = 5
} e2ap_TimeToWait_Root;

typedef OSUINT32 e2ap_TimeToWait;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_TimeToWait (OSCTXT* pctxt, e2ap_TimeToWait value);
EXTERN int asn1PD_e2ap_TimeToWait (OSCTXT* pctxt, e2ap_TimeToWait* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_TimeToWait (const char* name, const e2ap_TimeToWait* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_TimeToWait (OSCTXT* pctxt, const char* name, const e2ap_TimeToWait* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_TimeToWait (const char* name,const e2ap_TimeToWait* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_TimeToWait_ENUMTAB[];
#define e2ap_TimeToWait_ENUMTABSIZE 6

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_TimeToWait_ToString (OSUINT32 value);
EXTERN int e2ap_TimeToWait_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_TimeToWait* pvalue);
EXTERN int e2ap_TimeToWait_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_TimeToWait* pvalue);