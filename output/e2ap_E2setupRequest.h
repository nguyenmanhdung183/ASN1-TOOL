
//seq normal

/*****************************************/
/*           E2setupRequest                */
/*****************************************/


typedef struct EXTERN e2ap_E2setupRequest {
   e2ap_ProtocolIE-Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2setupRequest;

EXTERN int asn1PE_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue);
EXTERN int asn1PD_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue);
EXTERN void asn1Init_e2ap_E2setupRequest (e2ap_E2setupRequest* pvalue);
EXTERN void asn1Free_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue);
EXTERN void asn1Print_e2ap_E2setupRequest (const char* name, const e2ap_E2setupRequest* pvalue);