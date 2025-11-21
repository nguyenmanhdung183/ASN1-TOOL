/* e2ap_E2connectionUpdateRemove_ItemIEs.h */

/*****************************************/
/*           E2connectionUpdateRemove_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_E2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item   
   

} e2ap_E2connectionUpdateRemove_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2connectionUpdateRemove_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2connectionUpdateRemove_ItemIEs_TVALUE t;
      union {
         e2ap_E2connectionUpdateRemove_Item * _e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2connectionUpdateRemove_ItemIEs;

EXTERN int  asn1PE_e2ap_E2connectionUpdateRemove_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_E2connectionUpdateRemove_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_E2connectionUpdateRemove_ItemIEs (e2ap_E2connectionUpdateRemove_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdateRemove_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_ItemIEs* pvalue);
