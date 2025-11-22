/******************************************************/
/*                                                    */
/*    RegistrationRequest                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_start = 0,
    e2ap_stop = 1,
    e2ap_add = 2
} e2ap_RegistrationRequest_Root;

typedef OSUINT32 e2ap_RegistrationRequest;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RegistrationRequest (OSCTXT* pctxt, e2ap_RegistrationRequest value);
EXTERN int asn1PD_e2ap_RegistrationRequest (OSCTXT* pctxt, e2ap_RegistrationRequest* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RegistrationRequest (const char* name, const e2ap_RegistrationRequest* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RegistrationRequest (OSCTXT* pctxt, const char* name, const e2ap_RegistrationRequest* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RegistrationRequest (const char* name,const e2ap_RegistrationRequest* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RegistrationRequest_ENUMTAB[];
#define e2ap_RegistrationRequest_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RegistrationRequest_ToString (OSUINT32 value);
EXTERN int e2ap_RegistrationRequest_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RegistrationRequest* pvalue);
EXTERN int e2ap_RegistrationRequest_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RegistrationRequest* pvalue);