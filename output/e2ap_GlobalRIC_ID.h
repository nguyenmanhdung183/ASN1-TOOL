
//seq normal

typedef struct e2ap_GlobalRIC_ID {
   e2ap_PLMN-Identity pLMN_Identity;
   e2ap_BIT STRING ric_ID;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_GlobalRIC_ID;

EXTERN int asn1PE_e2ap_GlobalRIC_ID (OSCTXT* pctxt, e2ap_GlobalRIC_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalRIC_ID (OSCTXT* pctxt, e2ap_GlobalRIC_ID* pvalue);
EXTERN void asn1Init_e2ap_GlobalRIC_ID (e2ap_GlobalRIC_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalRIC_ID (OSCTXT* pctxt, e2ap_GlobalRIC_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalRIC_ID (const char* name, const e2ap_GlobalRIC_ID* pvalue);