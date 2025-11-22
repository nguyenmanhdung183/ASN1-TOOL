/******************************************************/
/*                                                    */
/*    ListedRecordsOnly                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_true = 0
} e2ap_ListedRecordsOnly_Root;

typedef OSUINT32 e2ap_ListedRecordsOnly;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_ListedRecordsOnly (OSCTXT* pctxt, e2ap_ListedRecordsOnly value);
EXTERN int asn1PD_e2ap_ListedRecordsOnly (OSCTXT* pctxt, e2ap_ListedRecordsOnly* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_ListedRecordsOnly (const char* name, const e2ap_ListedRecordsOnly* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_ListedRecordsOnly (OSCTXT* pctxt, const char* name, const e2ap_ListedRecordsOnly* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_ListedRecordsOnly (const char* name,const e2ap_ListedRecordsOnly* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_ListedRecordsOnly_ENUMTAB[];
#define e2ap_ListedRecordsOnly_ENUMTABSIZE 1

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_ListedRecordsOnly_ToString (OSUINT32 value);
EXTERN int e2ap_ListedRecordsOnly_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_ListedRecordsOnly* pvalue);
EXTERN int e2ap_ListedRecordsOnly_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_ListedRecordsOnly* pvalue);