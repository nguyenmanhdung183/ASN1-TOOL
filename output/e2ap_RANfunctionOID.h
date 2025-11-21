/* e2ap_RANfunctionOID.h */

//printable string
/*****************************************/
/*           RANfunctionOID                */
/*****************************************/


typedef const char* e2ap_RANfunctionOID;

EXTERN int asn1PE_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID value);
EXTERN int asn1PD_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID* ppvalue);
EXTERN void asn1Print_e2ap_RANfunctionOID (const char* name, e2ap_RANfunctionOID pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionOID (const char* name, e2ap_RANfunctionOID pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionOID (OSCTXT* pctxt, const char* name, e2ap_RANfunctionOID pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID pSrcValue, e2ap_RANfunctionOID* pDstValue);
EXTERN void asn1Free_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID pvalue);