

/*****************************************/
/*           ENB-ID                */
/*****************************************/
// choice




// Các nội dung cần thiết từ template choice.h.j2

    // Nội dung của file .h cho primitive BIT STRING (SIZE (20)
    /* bitstring intergrate header file */
    // Nội dung của file .h cho primitive BIT STRING (SIZE (28)
    /* bitstring intergrate header file */
    // Nội dung của file .h cho primitive BIT STRING (SIZE(18)
    /* bitstring intergrate header file */
    // Nội dung của file .h cho primitive BIT STRING (SIZE(21)
    /* bitstring intergrate header file */

// Các phần còn lại của template choice.h.j2



#define T_e2ap_ENB_ID_macro_eNB_ID  1
#define T_e2ap_ENB_ID_home_eNB_ID  2
#define T_e2ap_ENB_ID_short_Macro_eNB_ID  3
#define T_e2ap_ENB_ID_long_Macro_eNB_ID  4
#define T_e2ap_ENB_ID_extElem1 5

typedef struct e2ap_ENB_ID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      e2ap_ENB_ID_macro_eNB_ID *macro_eNB_ID;
      /* t =  2 */
      e2ap_ENB_ID_home_eNB_ID *home_eNB_ID;
      /* t =  3 */
      e2ap_ENB_ID_short_Macro_eNB_ID *short_Macro_eNB_ID;
      /* t =  4 */
      e2ap_ENB_ID_long_Macro_eNB_ID *long_Macro_eNB_ID;
      /* t = 5*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_ENB_ID;

EXTERN int asn1PE_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);
EXTERN int asn1PD_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);
EXTERN void asn1Print_e2ap_ENB_ID (const char* name, const e2ap_ENB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_ENB_ID (const char* name, e2ap_ENB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_ENB_ID (OSCTXT* pctxt, const char* name, const e2ap_ENB_ID* pvalue);
EXTERN int asn1Copy_e2ap_ENB_ID (OSCTXT* pctxt, const e2ap_ENB_ID* pSrcValue, e2ap_ENB_ID* pDstValue);
EXTERN int asn1Init_e2ap_ENB_ID (e2ap_ENB_ID* pvalue);
EXTERN void asn1Free_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);
