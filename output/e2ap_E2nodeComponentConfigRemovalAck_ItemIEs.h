/* e2ap_E2nodeComponentConfigRemovalAck-Item.h */

/*****************************************/
/*           E2nodeComponentConfigRemovalAck-Item               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigRemovalAck-Item_UNDEF_,

   T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item   
   

} e2ap_E2nodeComponentConfigRemovalAck-Item_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2nodeComponentConfigRemovalAck-Item {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2nodeComponentConfigRemovalAck_Item_TVALUE t;
      union {
         e2ap_E2nodeComponentConfigRemovalAck_Item * _e2apE2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value;
} e2ap_E2nodeComponentConfigRemovalAck-Item;

EXTERN int  asn1PE_e2ap_E2nodeComponentConfigRemovalAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue);
EXTERN int  asn1PD_e2ap_E2nodeComponentConfigRemovalAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigRemovalAck-Item (e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigRemovalAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue);
