/*****************************************/
/*           RICqueryRequest                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICqueryRequest {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICqueryRequest;

EXTERN int asn1PE_e2ap_RICqueryRequest (OSCTXT* pctxt, e2ap_RICqueryRequest* pvalue);
EXTERN int asn1PD_e2ap_RICqueryRequest (OSCTXT* pctxt, e2ap_RICqueryRequest* pvalue);
EXTERN int asn1Init_e2ap_RICqueryRequest (e2ap_RICqueryRequest* pvalue);
EXTERN void asn1Free_e2ap_RICqueryRequest (OSCTXT* pctxt, e2ap_RICqueryRequest* pvalue);
EXTERN void asn1Print_e2ap_RICqueryRequest (const char* name, const e2ap_RICqueryRequest* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICqueryRequest (const char* name, e2ap_RICqueryRequest* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICqueryRequest (OSCTXT* pctxt, const char* name, const e2ap_RICqueryRequest* pvalue);
EXTERN int asn1Copy_e2ap_RICqueryRequest (OSCTXT* pctxt, const e2ap_RICqueryRequest* pSrcValue, e2ap_RICqueryRequest* pDstValue);