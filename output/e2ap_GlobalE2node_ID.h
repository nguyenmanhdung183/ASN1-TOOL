

/*****************************************/
/*           GlobalE2node-ID                */
/*****************************************/
// choice

#define T_e2ap_GlobalE2node_ID_gNB  1
#define T_e2ap_GlobalE2node_ID_en_gNB  2
#define T_e2ap_GlobalE2node_ID_ng_eNB  3
#define T_e2ap_GlobalE2node_ID_eNB  4
#define T_e2ap_GlobalE2node_ID_extElem1 5

typedef struct e2ap_GlobalE2node_ID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      e2ap_GlobalE2node_gNB_ID *gNB;
      /* t =  2 */
      e2ap_GlobalE2node_en_gNB_ID *en_gNB;
      /* t =  3 */
      e2ap_GlobalE2node_ng_eNB_ID *ng_eNB;
      /* t =  4 */
      e2ap_GlobalE2node_eNB_ID *eNB;
      /* t = 5*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_GlobalE2node_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_ID (const char* name, const e2ap_GlobalE2node_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalE2node_ID (const char* name, e2ap_GlobalE2node_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalE2node_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalE2node_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalE2node_ID (OSCTXT* pctxt, const e2ap_GlobalE2node_ID* pSrcValue, e2ap_GlobalE2node_ID* pDstValue);
EXTERN int asn1Init_e2ap_GlobalE2node_ID (e2ap_GlobalE2node_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue);
