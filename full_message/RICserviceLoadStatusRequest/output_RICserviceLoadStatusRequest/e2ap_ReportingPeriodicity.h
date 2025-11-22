/******************************************************/
/*                                                    */
/*    ReportingPeriodicity                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_ms500 = 0,
    e2ap_ms1000 = 1,
    e2ap_ms2000 = 2,
    e2ap_ms5000 = 3,
    e2ap_ms10000 = 4
} e2ap_ReportingPeriodicity_Root;

typedef OSUINT32 e2ap_ReportingPeriodicity;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_ReportingPeriodicity (OSCTXT* pctxt, e2ap_ReportingPeriodicity value);
EXTERN int asn1PD_e2ap_ReportingPeriodicity (OSCTXT* pctxt, e2ap_ReportingPeriodicity* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_ReportingPeriodicity (const char* name, const e2ap_ReportingPeriodicity* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_ReportingPeriodicity (OSCTXT* pctxt, const char* name, const e2ap_ReportingPeriodicity* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_ReportingPeriodicity (const char* name,const e2ap_ReportingPeriodicity* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_ReportingPeriodicity_ENUMTAB[];
#define e2ap_ReportingPeriodicity_ENUMTABSIZE 5

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_ReportingPeriodicity_ToString (OSUINT32 value);
EXTERN int e2ap_ReportingPeriodicity_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_ReportingPeriodicity* pvalue);
EXTERN int e2ap_ReportingPeriodicity_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_ReportingPeriodicity* pvalue);