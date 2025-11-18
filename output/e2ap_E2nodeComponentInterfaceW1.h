
//seq normal

typedef struct e2ap_E2nodeComponentInterfaceW1 {
   e2ap_NGENB-DU-ID ng_eNB_DU_ID;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_E2nodeComponentInterfaceW1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentInterfaceW1 (e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceW1 (const char* name, const e2ap_E2nodeComponentInterfaceW1* pvalue);