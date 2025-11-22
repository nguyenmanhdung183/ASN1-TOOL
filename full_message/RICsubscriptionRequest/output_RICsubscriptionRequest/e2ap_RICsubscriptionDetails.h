/*****************************************/
/*           RICsubscriptionDetails                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionDetails {
   e2ap_RICeventTriggerDefinition ricEventTriggerDefinition;
   e2ap_RICactions_ToBeSetup_List ricAction_ToBeSetup_List;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionDetails;

EXTERN int asn1PE_e2ap_RICsubscriptionDetails (OSCTXT* pctxt, e2ap_RICsubscriptionDetails* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionDetails (OSCTXT* pctxt, e2ap_RICsubscriptionDetails* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionDetails (e2ap_RICsubscriptionDetails* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionDetails (OSCTXT* pctxt, e2ap_RICsubscriptionDetails* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionDetails (const char* name, const e2ap_RICsubscriptionDetails* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionDetails (const char* name, e2ap_RICsubscriptionDetails* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionDetails (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionDetails* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionDetails (OSCTXT* pctxt, const e2ap_RICsubscriptionDetails* pSrcValue, e2ap_RICsubscriptionDetails* pDstValue);