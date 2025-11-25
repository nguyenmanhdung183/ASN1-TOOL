/*****************************************/
/*           E2connectionUpdate                */
/*****************************************/
//seq normal



// Các nội dung cần thiết từ template seq_normal.h.j2


// Các phần còn lại của template seq_normal.h.j2


typedef struct EXTERN e2ap_E2connectionUpdate {
e2ap_E2connectionUpdate_protocolIEs protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2connectionUpdate;

EXTERN int asn1PE_e2ap_E2connectionUpdate (OSCTXT* pctxt, e2ap_E2connectionUpdate* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdate (OSCTXT* pctxt, e2ap_E2connectionUpdate* pvalue);
EXTERN int asn1Init_e2ap_E2connectionUpdate (e2ap_E2connectionUpdate* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdate (OSCTXT* pctxt, e2ap_E2connectionUpdate* pvalue);
EXTERN void asn1Print_e2ap_E2connectionUpdate (const char* name, const e2ap_E2connectionUpdate* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionUpdate (const char* name, e2ap_E2connectionUpdate* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2connectionUpdate (OSCTXT* pctxt, const char* name, const e2ap_E2connectionUpdate* pvalue);
EXTERN int asn1Copy_e2ap_E2connectionUpdate (OSCTXT* pctxt, const e2ap_E2connectionUpdate* pSrcValue, e2ap_E2connectionUpdate* pDstValue);