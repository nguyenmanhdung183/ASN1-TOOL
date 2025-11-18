
//seq normal

/*****************************************/
/*           GlobalE2node_gNB_ID                */
/*****************************************/


typedef struct EXTERN e2ap_GlobalE2node_gNB_ID {
   e2ap_GlobalgNB-ID global_gNB_ID;
   e2ap_GlobalenGNB-ID global_en_gNB_ID;
OSBOOL m_global-en-gNB-IDPresent;   e2ap_GNB-CU-UP-ID gNB_CU_UP_ID;
OSBOOL m_gNB-CU-UP-IDPresent;   e2ap_GNB-DU-ID gNB_DU_ID;
OSBOOL m_gNB-DU-IDPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalE2node_gNB_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN void asn1Init_e2ap_GlobalE2node_gNB_ID (e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_gNB_ID (const char* name, const e2ap_GlobalE2node_gNB_ID* pvalue);