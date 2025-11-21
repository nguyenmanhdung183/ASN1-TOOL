/******************************************************/
/*                                                    */
/*    E2nodeComponentInterfaceType                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_ng = 0,
    e2ap_xn = 1,
    e2ap_e1 = 2,
    e2ap_f1 = 3,
    e2ap_w1 = 4,
    e2ap_s1 = 5,
    e2ap_x2 = 6
} e2ap_E2nodeComponentInterfaceType_Root;

typedef OSUINT32 e2ap_E2nodeComponentInterfaceType;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceType value);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceType* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceType (const char* name, const e2ap_E2nodeComponentInterfaceType* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceType* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceType (const char* name,const e2ap_E2nodeComponentInterfaceType* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_E2nodeComponentInterfaceType_ENUMTAB[];
#define e2ap_E2nodeComponentInterfaceType_ENUMTABSIZE 7

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_E2nodeComponentInterfaceType_ToString (OSUINT32 value);
EXTERN int e2ap_E2nodeComponentInterfaceType_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_E2nodeComponentInterfaceType* pvalue);
EXTERN int e2ap_E2nodeComponentInterfaceType_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_E2nodeComponentInterfaceType* pvalue);