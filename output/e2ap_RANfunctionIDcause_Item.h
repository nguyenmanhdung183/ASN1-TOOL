
//seq normal

typedef struct e2ap_RANfunctionIDcause_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_Cause cause;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_RANfunctionIDcause_Item;

EXTERN int asn1PE_e2ap_RANfunctionIDcause_Item (OSCTXT* pctxt, e2ap_RANfunctionIDcause_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionIDcause_Item (OSCTXT* pctxt, e2ap_RANfunctionIDcause_Item* pvalue);
EXTERN void asn1Init_e2ap_RANfunctionIDcause_Item (e2ap_RANfunctionIDcause_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionIDcause_Item (OSCTXT* pctxt, e2ap_RANfunctionIDcause_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionIDcause_Item (const char* name, const e2ap_RANfunctionIDcause_Item* pvalue);