/*****************************************/
/*           RICaction_ToBeSetup_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICaction_ToBeSetup_Item {
   e2ap_RICactionID ricActionID;
   e2ap_RICactionType ricActionType;
   e2ap_RICactionDefinition ricActionDefinition;
     OSBOOL m_ricActionDefinitionPresent;   e2ap_RICsubsequentAction ricSubsequentAction;
     OSBOOL m_ricSubsequentActionPresent;   e2ap_RICactionExecutionOrder ricActionExecutionOrder;
     OSBOOL m_ricActionExecutionOrderPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICaction_ToBeSetup_Item;

EXTERN int asn1PE_e2ap_RICaction_ToBeSetup_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeSetup_Item* pvalue);
EXTERN int asn1PD_e2ap_RICaction_ToBeSetup_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeSetup_Item* pvalue);
EXTERN int asn1Init_e2ap_RICaction_ToBeSetup_Item (e2ap_RICaction_ToBeSetup_Item* pvalue);
EXTERN void asn1Free_e2ap_RICaction_ToBeSetup_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeSetup_Item* pvalue);
EXTERN void asn1Print_e2ap_RICaction_ToBeSetup_Item (const char* name, const e2ap_RICaction_ToBeSetup_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICaction_ToBeSetup_Item (const char* name, e2ap_RICaction_ToBeSetup_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICaction_ToBeSetup_Item (OSCTXT* pctxt, const char* name, const e2ap_RICaction_ToBeSetup_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICaction_ToBeSetup_Item (OSCTXT* pctxt, const e2ap_RICaction_ToBeSetup_Item* pSrcValue, e2ap_RICaction_ToBeSetup_Item* pDstValue);