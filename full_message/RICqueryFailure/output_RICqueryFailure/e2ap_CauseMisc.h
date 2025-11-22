/******************************************************/
/*                                                    */
/*    CauseMisc                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_control_processing_overload = 0,
    e2ap_hardware_failure = 1,
    e2ap_om_intervention = 2,
    e2ap_unspecified = 3
} e2ap_CauseMisc_Root;

typedef OSUINT32 e2ap_CauseMisc;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc value);
EXTERN int asn1PD_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_CauseMisc (const char* name, const e2ap_CauseMisc* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_CauseMisc (OSCTXT* pctxt, const char* name, const e2ap_CauseMisc* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_CauseMisc (const char* name,const e2ap_CauseMisc* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseMisc_ENUMTAB[];
#define e2ap_CauseMisc_ENUMTABSIZE 4

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseMisc_ToString (OSUINT32 value);
EXTERN int e2ap_CauseMisc_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseMisc* pvalue);
EXTERN int e2ap_CauseMisc_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseMisc* pvalue);