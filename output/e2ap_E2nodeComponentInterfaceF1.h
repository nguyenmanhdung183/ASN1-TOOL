
//seq normal

typedef struct e2ap_E2nodeComponentInterfaceF1 {
   e2ap_GNB-DU-ID gNB_DU_ID;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_E2nodeComponentInterfaceF1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentInterfaceF1 (e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceF1 (const char* name, const e2ap_E2nodeComponentInterfaceF1* pvalue);