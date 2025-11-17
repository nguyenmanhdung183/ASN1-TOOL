/* e2ap_E2AP_PDU.h */

// choice
typedef struct e2ap_E2AP_PDU {
   OSINT32 t;  /* choice tag */
   union {
      e2ap_InitiatingMessage* initiatingMessage;
      e2ap_SuccessfulOutcome* successfulOutcome;
      e2ap_UnsuccessfulOutcome* unsuccessfulOutcome;
      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_E2AP_PDU;

EXTERN int asn1PE_e2ap_E2AP_PDU (OSCTXT* pctxt, e2ap_E2AP_PDU* pvalue);
EXTERN int asn1PD_e2ap_E2AP_PDU (OSCTXT* pctxt, e2ap_E2AP_PDU* pvalue);
EXTERN void asn1Print_e2ap_E2AP_PDU (const char* name, const e2ap_E2AP_PDU* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2AP_PDU (const char* name, e2ap_E2AP_PDU* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_E2AP_PDU (OSCTXT* pctxt, const e2ap_E2AP_PDU* pSrcValue, e2ap_E2AP_PDU* pDstValue);
EXTERN int asn1Init_e2ap_E2AP_PDU (e2ap_E2AP_PDU* pvalue);
EXTERN void asn1Free_e2ap_E2AP_PDU (OSCTXT* pctxt, e2ap_E2AP_PDU* pvalue);
