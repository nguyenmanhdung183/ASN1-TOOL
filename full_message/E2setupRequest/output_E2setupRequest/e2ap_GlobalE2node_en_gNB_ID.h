/*****************************************/
/*           GlobalE2node_en_gNB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalE2node_en_gNB_ID {
   e2ap_GlobalenGNB-ID global_en_gNB_ID;
   e2ap_GNB-CU-UP-ID en_gNB_CU_UP_ID;
     OSBOOL m_en_gNB_CU_UP_IDPresent;   e2ap_GNB-DU-ID en_gNB_DU_ID;
     OSBOOL m_en_gNB_DU_IDPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalE2node_en_gNB_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalE2node_en_gNB_ID (e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_en_gNB_ID (const char* name, const e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalE2node_en_gNB_ID (const char* name, e2ap_GlobalE2node_en_gNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, const e2ap_GlobalE2node_en_gNB_ID* pSrcValue, e2ap_GlobalE2node_en_gNB_ID* pDstValue);