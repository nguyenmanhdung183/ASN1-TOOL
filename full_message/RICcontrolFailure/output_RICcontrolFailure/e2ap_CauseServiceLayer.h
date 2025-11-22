/*****************************************/
/*           CauseServiceLayer                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_CauseServiceLayer {
   e2ap_ServiceLayerCause serviceLayerCause;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_CauseServiceLayer;

EXTERN int asn1PE_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue);
EXTERN int asn1PD_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue);
EXTERN int asn1Init_e2ap_CauseServiceLayer (e2ap_CauseServiceLayer* pvalue);
EXTERN void asn1Free_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue);
EXTERN void asn1Print_e2ap_CauseServiceLayer (const char* name, const e2ap_CauseServiceLayer* pvalue);
EXTERN int asn1PrtToStr_e2ap_CauseServiceLayer (const char* name, e2ap_CauseServiceLayer* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_CauseServiceLayer (OSCTXT* pctxt, const char* name, const e2ap_CauseServiceLayer* pvalue);
EXTERN int asn1Copy_e2ap_CauseServiceLayer (OSCTXT* pctxt, const e2ap_CauseServiceLayer* pSrcValue, e2ap_CauseServiceLayer* pDstValue);