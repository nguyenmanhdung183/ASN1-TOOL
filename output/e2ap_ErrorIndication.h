
//seq normal

typedef struct e2ap_ErrorIndication {
   e2ap_ProtocolIE-Container protocolIEs;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_ErrorIndication;

EXTERN int asn1PE_e2ap_ErrorIndication (OSCTXT* pctxt, e2ap_ErrorIndication* pvalue);
EXTERN int asn1PD_e2ap_ErrorIndication (OSCTXT* pctxt, e2ap_ErrorIndication* pvalue);
EXTERN void asn1Init_e2ap_ErrorIndication (e2ap_ErrorIndication* pvalue);
EXTERN void asn1Free_e2ap_ErrorIndication (OSCTXT* pctxt, e2ap_ErrorIndication* pvalue);
EXTERN void asn1Print_e2ap_ErrorIndication (const char* name, const e2ap_ErrorIndication* pvalue);