/* e2ap_Cause.h */

// choice
typedef struct e2ap_Cause {
   OSINT32 t;  /* choice tag */
   union {
      e2ap_CauseRICrequest* ricRequest;
      e2ap_CauseRICservice* ricService;
      e2ap_CauseE2node* e2Node;
      e2ap_CauseTransport* transport;
      e2ap_CauseProtocol* protocol;
      e2ap_CauseMisc* misc;
      e2ap_CauseServiceLayer* serviceLayer;
      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_Cause;

EXTERN int asn1PE_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue);
EXTERN int asn1PD_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue);
EXTERN void asn1Print_e2ap_Cause (const char* name, const e2ap_Cause* pvalue);
EXTERN int asn1PrtToStr_e2ap_Cause (const char* name, e2ap_Cause* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_Cause (OSCTXT* pctxt, const e2ap_Cause* pSrcValue, e2ap_Cause* pDstValue);
EXTERN int asn1Init_e2ap_Cause (e2ap_Cause* pvalue);
EXTERN void asn1Free_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue);
