/* e2ap_TriggeringMessage.h - enumurate*/
/* e2ap_TriggeringMessage.h */

/******************************************************/
/*                                                    */
/*    TriggeringMessage                                       */
/*                                                    */
/******************************************************/

typedef enum {
    e2ap_initiating_message = 0,    e2ap_successful_outcome = 1,    e2ap_unsuccessfull_outcome = 2//add other values as needed
} e2ap_TriggeringMessage_Root;

typedef OSUINT32 e2ap_TriggeringMessage;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_TriggeringMessage (OSCTXT* pctxt, e2ap_TriggeringMessage value);
EXTERN int asn1PD_e2ap_TriggeringMessage (OSCTXT* pctxt, e2ap_TriggeringMessage* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_TriggeringMessage (const char* name, const e2ap_TriggeringMessage* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_TriggeringMessage (OSCTXT* pctxt, const char* name, const e2ap_TriggeringMessage* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_TriggeringMessage (const char* name,const e2ap_TriggeringMessage* pvalue,char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_TriggeringMessage_ENUMTAB[];
#define e2ap_TriggeringMessage_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_TriggeringMessage_ToString (OSUINT32 value);
EXTERN int e2ap_TriggeringMessage_ToEnum (OSCTXT* pctxt,const OSUTF8CHAR* value,e2ap_TriggeringMessage* pvalue);
EXTERN int e2ap_TriggeringMessage_ToEnum2 (OSCTXT* pctxt,const OSUTF8CHAR* value,OSSIZE valueLen,e2ap_TriggeringMessage* pvalue);