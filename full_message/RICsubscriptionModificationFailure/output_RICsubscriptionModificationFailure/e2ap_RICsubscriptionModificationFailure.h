/*****************************************/
/*           RICsubscriptionModificationFailure                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionModificationFailure {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionModificationFailure;

EXTERN int asn1PE_e2ap_RICsubscriptionModificationFailure (OSCTXT* pctxt, e2ap_RICsubscriptionModificationFailure* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionModificationFailure (OSCTXT* pctxt, e2ap_RICsubscriptionModificationFailure* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionModificationFailure (e2ap_RICsubscriptionModificationFailure* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionModificationFailure (OSCTXT* pctxt, e2ap_RICsubscriptionModificationFailure* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionModificationFailure (const char* name, const e2ap_RICsubscriptionModificationFailure* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionModificationFailure (const char* name, e2ap_RICsubscriptionModificationFailure* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionModificationFailure (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionModificationFailure* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionModificationFailure (OSCTXT* pctxt, const e2ap_RICsubscriptionModificationFailure* pSrcValue, e2ap_RICsubscriptionModificationFailure* pDstValue);