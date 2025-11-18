/* e2ap_E2nodeComponentID.h */

// choice
typedef struct e2ap_E2nodeComponentID {
   OSINT32 t;  /* choice tag */
   union {
      e2ap_E2nodeComponentInterfaceNG* e2nodeComponentInterfaceTypeNG;
      e2ap_E2nodeComponentInterfaceXn* e2nodeComponentInterfaceTypeXn;
      e2ap_E2nodeComponentInterfaceE1* e2nodeComponentInterfaceTypeE1;
      e2ap_E2nodeComponentInterfaceF1* e2nodeComponentInterfaceTypeF1;
      e2ap_E2nodeComponentInterfaceW1* e2nodeComponentInterfaceTypeW1;
      e2ap_E2nodeComponentInterfaceS1* e2nodeComponentInterfaceTypeS1;
      e2ap_E2nodeComponentInterfaceX2* e2nodeComponentInterfaceTypeX2;
      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_E2nodeComponentID;

EXTERN int asn1PE_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentID (const char* name, const e2ap_E2nodeComponentID* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentID (const char* name, e2ap_E2nodeComponentID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_E2nodeComponentID (OSCTXT* pctxt, const e2ap_E2nodeComponentID* pSrcValue, e2ap_E2nodeComponentID* pDstValue);
EXTERN int asn1Init_e2ap_E2nodeComponentID (e2ap_E2nodeComponentID* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue);
