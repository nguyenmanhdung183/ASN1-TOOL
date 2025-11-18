/* e2ap_E2setupRequestIEs.h */

//IE
/*****************************************/
/*           E2setupRequestIEs               */
/*****************************************/


typedef enum {
   T_E2AP_PDU_Contents_E2setupRequestIEs_UNDEF,

   T_E2AP_PDU_Contents_E2setupRequestIEs_TransactionID,   
   
   T_E2AP_PDU_Contents_E2setupRequestIEs_GlobalE2node_ID,   
   
   T_E2AP_PDU_Contents_E2setupRequestIEs_RANfunctions_List,   
   
   T_E2AP_PDU_Contents_E2setupRequestIEs_E2nodeComponentConfigAddition_List   
   

} e2ap_E2setupRequestIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2setupRequestIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2setupRequestIEs_TVALUE t;
      union {
         e2ap_TransactionID * _e2apE2setupRequestIEs_TransactionID,
         e2ap_GlobalE2node-ID * _e2apE2setupRequestIEs_GlobalE2node_ID,
         e2ap_RANfunctions-List * _e2apE2setupRequestIEs_RANfunctions_List,
         e2ap_E2nodeComponentConfigAddition-List * _e2apE2setupRequestIEs_E2nodeComponentConfigAddition_List

         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2setupRequestIEs;

EXTERN int  asn1PE_e2ap_E2setupRequestIEs (OSCTXT* pctxt, e2ap_E2setupRequestIEs* pvalue);
EXTERN int  asn1PD_e2ap_E2setupRequestIEs (OSCTXT* pctxt, e2ap_E2setupRequestIEs* pvalue);
EXTERN void asn1Init_e2ap_E2setupRequestIEs (e2ap_E2setupRequestIEs* pvalue);
EXTERN void asn1Free_e2ap_E2setupRequestIEs (OSCTXT* pctxt, e2ap_E2setupRequestIEs* pvalue);
