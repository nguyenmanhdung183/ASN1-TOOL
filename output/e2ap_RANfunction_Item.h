
//seq normal

typedef struct e2ap_RANfunction_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_RANfunctionDefinition ranFunctionDefinition;
   e2ap_RANfunctionRevision ranFunctionRevision;
   e2ap_RANfunctionOID ranFunctionOID;
} e2ap_RANfunction_Item;

EXTERN int asn1PE_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN void asn1Init_e2ap_RANfunction_Item (e2ap_RANfunction_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunction_Item (const char* name, const e2ap_RANfunction_Item* pvalue);