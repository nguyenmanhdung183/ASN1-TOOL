/******************************************************/
/*                                                    */
/*    CauseE2node                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_e2node_component_unknown = 0
} e2ap_CauseE2node_Root;

typedef OSUINT32 e2ap_CauseE2node;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_CauseE2node (OSCTXT* pctxt, e2ap_CauseE2node value);
EXTERN int asn1PD_e2ap_CauseE2node (OSCTXT* pctxt, e2ap_CauseE2node* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_CauseE2node (const char* name, const e2ap_CauseE2node* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_CauseE2node (OSCTXT* pctxt, const char* name, const e2ap_CauseE2node* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_CauseE2node (const char* name,const e2ap_CauseE2node* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseE2node_ENUMTAB[];
#define e2ap_CauseE2node_ENUMTABSIZE 1

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseE2node_ToString (OSUINT32 value);
EXTERN int e2ap_CauseE2node_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseE2node* pvalue);
EXTERN int e2ap_CauseE2node_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseE2node* pvalue);