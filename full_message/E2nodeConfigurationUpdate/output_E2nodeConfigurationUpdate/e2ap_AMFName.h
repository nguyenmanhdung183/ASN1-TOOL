/* e2ap_AMFName.h */

//printable string
/*****************************************/
/*           AMFName                */
/*****************************************/


typedef const char* e2ap_AMFName;

EXTERN int asn1PE_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName value);
EXTERN int asn1PD_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName* ppvalue);
EXTERN void asn1Print_e2ap_AMFName (const char* name, e2ap_AMFName pvalue);
EXTERN int asn1PrtToStr_e2ap_AMFName (const char* name, e2ap_AMFName pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_AMFName (OSCTXT* pctxt, const char* name, e2ap_AMFName pvalue);
EXTERN int asn1Copy_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName pSrcValue, e2ap_AMFName* pDstValue);
EXTERN void asn1Free_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName pvalue);