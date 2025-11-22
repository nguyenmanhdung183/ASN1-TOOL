/******************************************************/
/*                                                    */
/*    RICloadRequest                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_true = 0
} e2ap_RICloadRequest_Root;

typedef OSUINT32 e2ap_RICloadRequest;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICloadRequest (OSCTXT* pctxt, e2ap_RICloadRequest value);
EXTERN int asn1PD_e2ap_RICloadRequest (OSCTXT* pctxt, e2ap_RICloadRequest* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICloadRequest (const char* name, const e2ap_RICloadRequest* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICloadRequest (OSCTXT* pctxt, const char* name, const e2ap_RICloadRequest* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICloadRequest (const char* name,const e2ap_RICloadRequest* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICloadRequest_ENUMTAB[];
#define e2ap_RICloadRequest_ENUMTABSIZE 1

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICloadRequest_ToString (OSUINT32 value);
EXTERN int e2ap_RICloadRequest_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICloadRequest* pvalue);
EXTERN int e2ap_RICloadRequest_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICloadRequest* pvalue);