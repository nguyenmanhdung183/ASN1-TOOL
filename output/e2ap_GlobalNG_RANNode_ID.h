/* e2ap_GlobalNG_RANNode_ID.h */

// choice
typedef struct e2ap_GlobalNG_RANNode_ID {
   OSINT32 t;  /* choice tag */
   union {
      e2ap_GlobalgNB-ID* gNB;
      e2ap_GlobalngeNB-ID* ng_eNB;
      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_GlobalNG_RANNode_ID;

EXTERN int asn1PE_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalNG_RANNode_ID (const char* name, const e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalNG_RANNode_ID (const char* name, e2ap_GlobalNG_RANNode_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, const e2ap_GlobalNG_RANNode_ID* pSrcValue, e2ap_GlobalNG_RANNode_ID* pDstValue);
EXTERN int asn1Init_e2ap_GlobalNG_RANNode_ID (e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue);
