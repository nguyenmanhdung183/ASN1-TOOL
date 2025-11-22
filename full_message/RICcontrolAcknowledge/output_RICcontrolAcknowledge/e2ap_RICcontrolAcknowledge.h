/*****************************************/
/*           RICcontrolAcknowledge                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICcontrolAcknowledge {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICcontrolAcknowledge;

EXTERN int asn1PE_e2ap_RICcontrolAcknowledge (OSCTXT* pctxt, e2ap_RICcontrolAcknowledge* pvalue);
EXTERN int asn1PD_e2ap_RICcontrolAcknowledge (OSCTXT* pctxt, e2ap_RICcontrolAcknowledge* pvalue);
EXTERN int asn1Init_e2ap_RICcontrolAcknowledge (e2ap_RICcontrolAcknowledge* pvalue);
EXTERN void asn1Free_e2ap_RICcontrolAcknowledge (OSCTXT* pctxt, e2ap_RICcontrolAcknowledge* pvalue);
EXTERN void asn1Print_e2ap_RICcontrolAcknowledge (const char* name, const e2ap_RICcontrolAcknowledge* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICcontrolAcknowledge (const char* name, e2ap_RICcontrolAcknowledge* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICcontrolAcknowledge (OSCTXT* pctxt, const char* name, const e2ap_RICcontrolAcknowledge* pvalue);
EXTERN int asn1Copy_e2ap_RICcontrolAcknowledge (OSCTXT* pctxt, const e2ap_RICcontrolAcknowledge* pSrcValue, e2ap_RICcontrolAcknowledge* pDstValue);