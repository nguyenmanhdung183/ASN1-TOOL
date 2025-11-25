/* e2ap_E2connectionUpdate-Item.h */

/*****************************************/
/*           E2connectionUpdate-Item               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate-Item_UNDEF_,

   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate-Item_E2connectionUpdate_Item   
   

} e2ap_E2connectionUpdate-Item_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2connectionUpdate-Item {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2connectionUpdate_Item_TVALUE t;
      union {
         e2ap_E2connectionUpdate_Item * _e2apE2connectionUpdate-Item_E2connectionUpdate_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value;
} e2ap_E2connectionUpdate-Item;

EXTERN int  asn1PE_e2ap_E2connectionUpdate-Item (OSCTXT* pctxt, e2ap_E2connectionUpdate-Item* pvalue);
EXTERN int  asn1PD_e2ap_E2connectionUpdate-Item (OSCTXT* pctxt, e2ap_E2connectionUpdate-Item* pvalue);
EXTERN void asn1Init_e2ap_E2connectionUpdate-Item (e2ap_E2connectionUpdate-Item* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdate-Item (OSCTXT* pctxt, e2ap_E2connectionUpdate-Item* pvalue);
