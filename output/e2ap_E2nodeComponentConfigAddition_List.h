/* e2ap_E2nodeComponentConfigAddition_List.h */
//seq of single container

/*****************************************/
/*           E2nodeComponentConfigAddition_List                */
/*****************************************/

typedef OSRTDList e2ap_E2nodeComponentConfigAddition_List;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List** ppvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigAddition_List (e2ap_E2nodeComponentConfigAddition_List* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* pvalue);