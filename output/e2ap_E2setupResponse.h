
//seq normal

typedef struct e2ap_E2setupResponse {
   e2ap_ProtocolIE-Container protocolIEs;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_E2setupResponse;

EXTERN int asn1PE_e2ap_E2setupResponse (OSCTXT* pctxt, e2ap_E2setupResponse* pvalue);
EXTERN int asn1PD_e2ap_E2setupResponse (OSCTXT* pctxt, e2ap_E2setupResponse* pvalue);
EXTERN void asn1Init_e2ap_E2setupResponse (e2ap_E2setupResponse* pvalue);
EXTERN void asn1Free_e2ap_E2setupResponse (OSCTXT* pctxt, e2ap_E2setupResponse* pvalue);
EXTERN void asn1Print_e2ap_E2setupResponse (const char* name, const e2ap_E2setupResponse* pvalue);