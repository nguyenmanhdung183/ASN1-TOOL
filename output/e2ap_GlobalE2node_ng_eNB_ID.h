
//seq normal

/*****************************************/
/*           GlobalE2node_ng_eNB_ID                */
/*****************************************/


typedef struct EXTERN e2ap_GlobalE2node_ng_eNB_ID {
   e2ap_GlobalngeNB-ID global_ng_eNB_ID;
   e2ap_GlobalENB-ID global_eNB_ID;
OSBOOL m_global_eNB_IDPresent;   e2ap_NGENB-DU-ID ngENB_DU_ID;
OSBOOL m_ngENB_DU_IDPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalE2node_ng_eNB_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalE2node_ng_eNB_ID (e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_ng_eNB_ID (const char* name, const e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalE2node_ng_eNB_ID (const char* name, e2ap_GlobalE2node_ng_eNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, const e2ap_GlobalE2node_ng_eNB_ID* pSrcValue, e2ap_GlobalE2node_ng_eNB_ID* pDstValue);