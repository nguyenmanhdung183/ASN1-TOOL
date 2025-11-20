/* e2ap_GNB_CU_UP_ID.h */


//interger no ext
/*****************************************/
/*           GNB-CU-UP-ID         */
/*****************************************/


typedef OSUINT64 e2ap_GNB_CU_UP_ID;

EXTERN int asn1PE_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID value);
EXTERN int asn1PD_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID* pvalue);
EXTERN void asn1Print_e2ap_GNB_CU_UP_ID (const char* name, const e2ap_GNB_CU_UP_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GNB_CU_UP_ID (const char* name, e2ap_GNB_CU_UP_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, const char* name, const e2ap_GNB_CU_UP_ID* pvalue);