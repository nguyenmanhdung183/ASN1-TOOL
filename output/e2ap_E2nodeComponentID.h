
// choice

/*****************************************/
/*           E2nodeComponentID                */
/*****************************************/

#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeNG 1
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeXn 2
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeE1 3
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeF1 4
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeW1 5
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeS1 6
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeX2 7
#define T_e2ap_E2nodeComponentID_extElem1 2

typedef struct e2ap_E2nodeComponentID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      e2ap_E2nodeComponentInterfaceNG* e2nodeComponentInterfaceTypeNG;
      /* t =  2 */
      e2ap_E2nodeComponentInterfaceXn* e2nodeComponentInterfaceTypeXn;
      /* t =  3 */
      e2ap_E2nodeComponentInterfaceE1* e2nodeComponentInterfaceTypeE1;
      /* t =  4 */
      e2ap_E2nodeComponentInterfaceF1* e2nodeComponentInterfaceTypeF1;
      /* t =  5 */
      e2ap_E2nodeComponentInterfaceW1* e2nodeComponentInterfaceTypeW1;
      /* t =  6 */
      e2ap_E2nodeComponentInterfaceS1* e2nodeComponentInterfaceTypeS1;
      /* t =  7 */
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
