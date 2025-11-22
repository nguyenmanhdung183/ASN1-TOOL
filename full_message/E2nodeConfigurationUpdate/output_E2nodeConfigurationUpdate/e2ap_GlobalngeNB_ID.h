/*****************************************/
/*           GlobalngeNB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalngeNB_ID {
   e2ap_PLMN_Identity plmn_id;
   e2ap_ENB_ID_Choice enb_id;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalngeNB_ID;

EXTERN int asn1PE_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalngeNB_ID (e2ap_GlobalngeNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalngeNB_ID (const char* name, const e2ap_GlobalngeNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalngeNB_ID (const char* name, e2ap_GlobalngeNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalngeNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, const e2ap_GlobalngeNB_ID* pSrcValue, e2ap_GlobalngeNB_ID* pDstValue);