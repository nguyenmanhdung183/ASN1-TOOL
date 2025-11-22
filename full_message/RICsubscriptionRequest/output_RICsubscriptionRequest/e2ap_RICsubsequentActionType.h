/******************************************************/
/*                                                    */
/*    RICsubsequentActionType                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_continue = 0,
    e2ap_wait = 1
} e2ap_RICsubsequentActionType_Root;

typedef OSUINT32 e2ap_RICsubsequentActionType;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICsubsequentActionType (OSCTXT* pctxt, e2ap_RICsubsequentActionType value);
EXTERN int asn1PD_e2ap_RICsubsequentActionType (OSCTXT* pctxt, e2ap_RICsubsequentActionType* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICsubsequentActionType (const char* name, const e2ap_RICsubsequentActionType* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICsubsequentActionType (OSCTXT* pctxt, const char* name, const e2ap_RICsubsequentActionType* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICsubsequentActionType (const char* name,const e2ap_RICsubsequentActionType* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICsubsequentActionType_ENUMTAB[];
#define e2ap_RICsubsequentActionType_ENUMTABSIZE 2

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICsubsequentActionType_ToString (OSUINT32 value);
EXTERN int e2ap_RICsubsequentActionType_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICsubsequentActionType* pvalue);
EXTERN int e2ap_RICsubsequentActionType_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICsubsequentActionType* pvalue);