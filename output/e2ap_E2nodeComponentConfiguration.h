
//seq normal

/*****************************************/
/*           E2nodeComponentConfiguration                */
/*****************************************/


typedef struct EXTERN e2ap_E2nodeComponentConfiguration {
   e2ap_e2nodeComponentRequestPart e2nodeComponentRequestPart;
   e2ap_e2nodeComponentResponsePart e2nodeComponentResponsePart;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentConfiguration;

EXTERN int asn1PE_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfiguration (e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfiguration (const char* name, const e2ap_E2nodeComponentConfiguration* pvalue);