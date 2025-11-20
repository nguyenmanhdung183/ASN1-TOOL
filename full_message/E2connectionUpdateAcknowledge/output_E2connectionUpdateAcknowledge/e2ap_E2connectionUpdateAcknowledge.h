/*****************************************/
/*           E2connectionUpdateAcknowledge                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2connectionUpdateAcknowledge {
   e2ap_ProtocolIE-Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2connectionUpdateAcknowledge;

EXTERN int asn1PE_e2ap_E2connectionUpdateAcknowledge (OSCTXT* pctxt, e2ap_E2connectionUpdateAcknowledge* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdateAcknowledge (OSCTXT* pctxt, e2ap_E2connectionUpdateAcknowledge* pvalue);
EXTERN int asn1Init_e2ap_E2connectionUpdateAcknowledge (e2ap_E2connectionUpdateAcknowledge* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdateAcknowledge (OSCTXT* pctxt, e2ap_E2connectionUpdateAcknowledge* pvalue);
EXTERN void asn1Print_e2ap_E2connectionUpdateAcknowledge (const char* name, const e2ap_E2connectionUpdateAcknowledge* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionUpdateAcknowledge (const char* name, e2ap_E2connectionUpdateAcknowledge* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2connectionUpdateAcknowledge (OSCTXT* pctxt, const char* name, const e2ap_E2connectionUpdateAcknowledge* pvalue);
EXTERN int asn1Copy_e2ap_E2connectionUpdateAcknowledge (OSCTXT* pctxt, const e2ap_E2connectionUpdateAcknowledge* pSrcValue, e2ap_E2connectionUpdateAcknowledge* pDstValue);