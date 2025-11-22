/*****************************************/
/*           RICsubscription_List_withCause                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICsubscription_List_withCause;

EXTERN int asn1PE_e2ap_RICsubscription_List_withCause (OSCTXT* pctxt, e2ap_RICsubscription_List_withCause* pvalue);
EXTERN int asn1PD_e2ap_RICsubscription_List_withCause (OSCTXT* pctxt, e2ap_RICsubscription_List_withCause* ppvalue);
EXTERN void asn1Init_e2ap_RICsubscription_List_withCause (e2ap_RICsubscription_List_withCause* pvalue);
EXTERN void asn1Free_e2ap_RICsubscription_List_withCause (OSCTXT* pctxt, e2ap_RICsubscription_List_withCause* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscription_List_withCause (const char* name, e2ap_RICsubscription_List_withCause* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICsubscription_List_withCause (OSCTXT* pctxt, const e2ap_RICsubscription_List_withCause* pSrcValue, e2ap_RICsubscription_List_withCause* pDstValue);
EXTERN void asn1Print_e2ap_RICsubscription_List_withCause (const char *name, const e2ap_RICsubscription_List_withCause* pvalue);