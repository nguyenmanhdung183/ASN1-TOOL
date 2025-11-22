/******************************************************/
/*                                                    */
/*    RICcontrolAckRequest                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_noAck = 0,
    e2ap_ack = 1
} e2ap_RICcontrolAckRequest_Root;

typedef OSUINT32 e2ap_RICcontrolAckRequest;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICcontrolAckRequest (OSCTXT* pctxt, e2ap_RICcontrolAckRequest value);
EXTERN int asn1PD_e2ap_RICcontrolAckRequest (OSCTXT* pctxt, e2ap_RICcontrolAckRequest* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICcontrolAckRequest (const char* name, const e2ap_RICcontrolAckRequest* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICcontrolAckRequest (OSCTXT* pctxt, const char* name, const e2ap_RICcontrolAckRequest* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICcontrolAckRequest (const char* name,const e2ap_RICcontrolAckRequest* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICcontrolAckRequest_ENUMTAB[];
#define e2ap_RICcontrolAckRequest_ENUMTABSIZE 2

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICcontrolAckRequest_ToString (OSUINT32 value);
EXTERN int e2ap_RICcontrolAckRequest_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICcontrolAckRequest* pvalue);
EXTERN int e2ap_RICcontrolAckRequest_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICcontrolAckRequest* pvalue);