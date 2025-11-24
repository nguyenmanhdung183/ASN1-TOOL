/* e2ap_E2nodeComponentConfigAdditionAck-Item.h */

/*****************************************/
/*           E2nodeComponentConfigAdditionAck-Item               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigAdditionAck-Item_UNDEF_,

   T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigAdditionAck-Item_E2nodeComponentConfigAdditionAck_Item   
   

} e2ap_E2nodeComponentConfigAdditionAck-Item_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2nodeComponentConfigAdditionAck-Item {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2nodeComponentConfigAdditionAck_Item_TVALUE t;
      union {
         e2ap_E2nodeComponentConfigAdditionAck_Item * _e2apE2nodeComponentConfigAdditionAck-Item_E2nodeComponentConfigAdditionAck_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value;
} e2ap_E2nodeComponentConfigAdditionAck-Item;

EXTERN int  asn1PE_e2ap_E2nodeComponentConfigAdditionAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck-Item* pvalue);
EXTERN int  asn1PD_e2ap_E2nodeComponentConfigAdditionAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck-Item* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigAdditionAck-Item (e2ap_E2nodeComponentConfigAdditionAck-Item* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAdditionAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck-Item* pvalue);
