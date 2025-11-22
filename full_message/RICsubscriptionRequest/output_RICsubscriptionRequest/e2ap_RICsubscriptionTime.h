/*****************************************/
/*           RICsubscriptionTime                */
/*****************************************/
//octet string


typedef struct e2ap_RICsubscriptionTime {
   OSUINT32 numocts;
   OSOCTET data[8];
} e2ap_RICsubscriptionTime;

EXTERN int asn1PE_e2ap_RICsubscriptionTime (OSCTXT* pctxt, e2ap_RICsubscriptionTime* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionTime (OSCTXT* pctxt, e2ap_RICsubscriptionTime** ppvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionTime (const char* name, const e2ap_RICsubscriptionTime* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionTime (const char* name, e2ap_RICsubscriptionTime* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionTime (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionTime* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionTime (OSCTXT* pctxt, const e2ap_RICsubscriptionTime* pSrcValue, e2ap_RICsubscriptionTime* pDstValue);
EXTERN int asn1Init_e2ap_RICsubscriptionTime (e2ap_RICsubscriptionTime* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionTime (OSCTXT* pctxt, e2ap_RICsubscriptionTime* pvalue);