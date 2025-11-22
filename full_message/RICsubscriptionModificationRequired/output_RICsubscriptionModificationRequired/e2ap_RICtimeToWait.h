/******************************************************/
/*                                                    */
/*    RICtimeToWait                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_w1ms = 0,
    e2ap_w2ms = 1,
    e2ap_w5ms = 2,
    e2ap_w10ms = 3,
    e2ap_w20ms = 4,
    e2ap_w30ms = 5,
    e2ap_w40ms = 6,
    e2ap_w50ms = 7,
    e2ap_w100ms = 8,
    e2ap_w200ms = 9,
    e2ap_w500ms = 10,
    e2ap_w1s = 11,
    e2ap_w2s = 12,
    e2ap_w5s = 13,
    e2ap_w10s = 14,
    e2ap_w20s = 15,
    e2ap_w60s = 16
} e2ap_RICtimeToWait_Root;

typedef OSUINT32 e2ap_RICtimeToWait;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICtimeToWait (OSCTXT* pctxt, e2ap_RICtimeToWait value);
EXTERN int asn1PD_e2ap_RICtimeToWait (OSCTXT* pctxt, e2ap_RICtimeToWait* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICtimeToWait (const char* name, const e2ap_RICtimeToWait* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICtimeToWait (OSCTXT* pctxt, const char* name, const e2ap_RICtimeToWait* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICtimeToWait (const char* name,const e2ap_RICtimeToWait* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICtimeToWait_ENUMTAB[];
#define e2ap_RICtimeToWait_ENUMTABSIZE 17

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICtimeToWait_ToString (OSUINT32 value);
EXTERN int e2ap_RICtimeToWait_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICtimeToWait* pvalue);
EXTERN int e2ap_RICtimeToWait_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICtimeToWait* pvalue);