/* e2ap_E2connectionUpdateAck_IEs.h */

/*****************************************/
/*           E2connectionUpdateAck_IEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdateAck_IEs_UNDEF_,

   T_E2AP_PDU_Contents_E2connectionUpdateAck_IEs_TransactionID,   
   
   T_E2AP_PDU_Contents_E2connectionUpdateAck_IEs_E2connectionUpdate_List,   
   
   T_E2AP_PDU_Contents_E2connectionUpdateAck_IEs_E2connectionSetupFailed_List   
   

} e2ap_E2connectionUpdateAck_IEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2connectionUpdateAck_IEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2connectionUpdateAck_IEs_TVALUE t;
      union {
         e2ap_TransactionID * _e2apE2connectionUpdateAck_IEs_TransactionID;

         e2ap_E2connectionUpdate_List * _e2apE2connectionUpdateAck_IEs_E2connectionUpdate_List;

         e2ap_E2connectionSetupFailed_List * _e2apE2connectionUpdateAck_IEs_E2connectionSetupFailed_List;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2connectionUpdateAck_IEs;

EXTERN int  asn1PE_e2ap_E2connectionUpdateAck_IEs (OSCTXT* pctxt, e2ap_E2connectionUpdateAck_IEs* pvalue);
EXTERN int  asn1PD_e2ap_E2connectionUpdateAck_IEs (OSCTXT* pctxt, e2ap_E2connectionUpdateAck_IEs* pvalue);
EXTERN void asn1Init_e2ap_E2connectionUpdateAck_IEs (e2ap_E2connectionUpdateAck_IEs* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdateAck_IEs (OSCTXT* pctxt, e2ap_E2connectionUpdateAck_IEs* pvalue);
