/* e2ap_ENB_ID.h */

// choice
typedef struct e2ap_ENB_ID {
   OSINT32 t;  /* choice tag */
   union {
      e2ap_BIT STRING* macro_eNB_ID;
      e2ap_WG3* O_RAN;
      e2ap_BIT STRING* home_eNB_ID;
      e2ap_BIT STRING* short_Macro_eNB_ID;
      e2ap_BIT STRING* long_Macro_eNB_ID;
      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_ENB_ID;

EXTERN int asn1PE_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);
EXTERN int asn1PD_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);
EXTERN void asn1Print_e2ap_ENB_ID (const char* name, const e2ap_ENB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_ENB_ID (const char* name, e2ap_ENB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_ENB_ID (OSCTXT* pctxt, const e2ap_ENB_ID* pSrcValue, e2ap_ENB_ID* pDstValue);
EXTERN int asn1Init_e2ap_ENB_ID (e2ap_ENB_ID* pvalue);
EXTERN void asn1Free_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);
