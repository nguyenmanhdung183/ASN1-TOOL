
//seq normal

typedef struct e2ap_GlobalenGNB_ID {
   e2ap_PLMN-Identity pLMN_Identity;
   e2ap_ENGNB-ID gNB_ID;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_GlobalenGNB_ID;

EXTERN int asn1PE_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue);
EXTERN void asn1Init_e2ap_GlobalenGNB_ID (e2ap_GlobalenGNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalenGNB_ID (const char* name, const e2ap_GlobalenGNB_ID* pvalue);