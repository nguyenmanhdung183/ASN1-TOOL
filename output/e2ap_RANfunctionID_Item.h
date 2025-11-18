
//seq normal

typedef struct e2ap_RANfunctionID_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_RANfunctionRevision ranFunctionRevision;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_RANfunctionID_Item;

EXTERN int asn1PE_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue);
EXTERN void asn1Init_e2ap_RANfunctionID_Item (e2ap_RANfunctionID_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionID_Item (const char* name, const e2ap_RANfunctionID_Item* pvalue);