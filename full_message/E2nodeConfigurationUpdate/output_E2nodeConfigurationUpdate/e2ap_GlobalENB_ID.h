/*****************************************/
/*           GlobalENB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalENB_ID {
   e2ap_PLMN-Identity pLMN_Identity;
   e2ap_ENB-ID eNB_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalENB_ID;

EXTERN int asn1PE_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalENB_ID (e2ap_GlobalENB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalENB_ID (const char* name, const e2ap_GlobalENB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalENB_ID (const char* name, e2ap_GlobalENB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalENB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalENB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalENB_ID (OSCTXT* pctxt, const e2ap_GlobalENB_ID* pSrcValue, e2ap_GlobalENB_ID* pDstValue);