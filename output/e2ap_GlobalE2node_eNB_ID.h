
//seq normal

/*****************************************/
/*           GlobalE2node_eNB_ID                */
/*****************************************/


typedef struct EXTERN e2ap_GlobalE2node_eNB_ID {
   e2ap_GlobalENB-ID global_eNB_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalE2node_eNB_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN void asn1Init_e2ap_GlobalE2node_eNB_ID (e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_eNB_ID (const char* name, const e2ap_GlobalE2node_eNB_ID* pvalue);