/* e2ap_GNB_ID_Choice.h */

// choice
typedef struct e2ap_GNB_ID_Choice {
   OSINT32 t;  /* choice tag */
   union {
      e2ap_BIT STRING* gnb_ID;
      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_GNB_ID_Choice;

EXTERN int asn1PE_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue);
EXTERN int asn1PD_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue);
EXTERN void asn1Print_e2ap_GNB_ID_Choice (const char* name, const e2ap_GNB_ID_Choice* pvalue);
EXTERN int asn1PrtToStr_e2ap_GNB_ID_Choice (const char* name, e2ap_GNB_ID_Choice* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_GNB_ID_Choice (OSCTXT* pctxt, const e2ap_GNB_ID_Choice* pSrcValue, e2ap_GNB_ID_Choice* pDstValue);
EXTERN int asn1Init_e2ap_GNB_ID_Choice (e2ap_GNB_ID_Choice* pvalue);
EXTERN void asn1Free_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue);
