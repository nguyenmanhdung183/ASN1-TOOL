/*****************************************/
/*           RICsubscriptionLoad_ItemIE                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionLoad_ItemIE {
   e2ap_RICrequestID ricRequestID;
   e2ap_RICloadInformation ricSubscriptionLoadInformation;
     OSBOOL m_ricSubscriptionLoadInformationPresent;   e2ap_RICactionLoad_List ricActionLoad_list;
     OSBOOL m_ricActionLoad_listPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionLoad_ItemIE;

EXTERN int asn1PE_e2ap_RICsubscriptionLoad_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_ItemIE* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionLoad_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_ItemIE* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionLoad_ItemIE (e2ap_RICsubscriptionLoad_ItemIE* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionLoad_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_ItemIE* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionLoad_ItemIE (const char* name, const e2ap_RICsubscriptionLoad_ItemIE* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionLoad_ItemIE (const char* name, e2ap_RICsubscriptionLoad_ItemIE* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionLoad_ItemIE (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionLoad_ItemIE* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionLoad_ItemIE (OSCTXT* pctxt, const e2ap_RICsubscriptionLoad_ItemIE* pSrcValue, e2ap_RICsubscriptionLoad_ItemIE* pDstValue);