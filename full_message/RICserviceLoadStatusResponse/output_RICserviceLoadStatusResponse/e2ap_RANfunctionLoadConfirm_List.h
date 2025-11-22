/*****************************************/
/*           RANfunctionLoadConfirm_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RANfunctionLoadConfirm_List;

EXTERN int asn1PE_e2ap_RANfunctionLoadConfirm_List (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_List* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionLoadConfirm_List (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_List* ppvalue);
EXTERN void asn1Init_e2ap_RANfunctionLoadConfirm_List (e2ap_RANfunctionLoadConfirm_List* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionLoadConfirm_List (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionLoadConfirm_List (const char* name, e2ap_RANfunctionLoadConfirm_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RANfunctionLoadConfirm_List (OSCTXT* pctxt, const e2ap_RANfunctionLoadConfirm_List* pSrcValue, e2ap_RANfunctionLoadConfirm_List* pDstValue);
EXTERN void asn1Print_e2ap_RANfunctionLoadConfirm_List (const char *name, const e2ap_RANfunctionLoadConfirm_List* pvalue);