/*****************************************/
/*           RICsubsequentAction                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubsequentAction {
   e2ap_RICsubsequentActionType ricSubsequentActionType;
   e2ap_RICtimeToWait ricTimeToWait;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubsequentAction;

EXTERN int asn1PE_e2ap_RICsubsequentAction (OSCTXT* pctxt, e2ap_RICsubsequentAction* pvalue);
EXTERN int asn1PD_e2ap_RICsubsequentAction (OSCTXT* pctxt, e2ap_RICsubsequentAction* pvalue);
EXTERN int asn1Init_e2ap_RICsubsequentAction (e2ap_RICsubsequentAction* pvalue);
EXTERN void asn1Free_e2ap_RICsubsequentAction (OSCTXT* pctxt, e2ap_RICsubsequentAction* pvalue);
EXTERN void asn1Print_e2ap_RICsubsequentAction (const char* name, const e2ap_RICsubsequentAction* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubsequentAction (const char* name, e2ap_RICsubsequentAction* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubsequentAction (OSCTXT* pctxt, const char* name, const e2ap_RICsubsequentAction* pvalue);
EXTERN int asn1Copy_e2ap_RICsubsequentAction (OSCTXT* pctxt, const e2ap_RICsubsequentAction* pSrcValue, e2ap_RICsubsequentAction* pDstValue);