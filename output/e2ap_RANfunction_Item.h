
//seq normal

/*****************************************/
/*           RANfunction_Item                */
/*****************************************/


typedef struct EXTERN e2ap_RANfunction_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_RANfunctionDefinition ranFunctionDefinition;
   e2ap_RANfunctionRevision ranFunctionRevision;
   e2ap_RANfunctionOID ranFunctionOID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RANfunction_Item;

EXTERN int asn1PE_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN int asn1Init_e2ap_RANfunction_Item (e2ap_RANfunction_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunction_Item (const char* name, const e2ap_RANfunction_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunction_Item (const char* name, e2ap_RANfunction_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunction_Item (OSCTXT* pctxt, const char* name, const e2ap_RANfunction_Item* pvalue);
EXTERN int asn1Copy_e2ap_RANfunction_Item (OSCTXT* pctxt, const e2ap_RANfunction_Item* pSrcValue, e2ap_RANfunction_Item* pDstValue);