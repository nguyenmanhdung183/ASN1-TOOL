/* e2ap_RICaction_RefusedToBeModified_ItemIEs.h */

/*****************************************/
/*           RICaction_RefusedToBeModified_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICaction_RefusedToBeModified_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICaction_RefusedToBeModified_ItemIEs_RICaction_RefusedToBeModified_Item   
   

} e2ap_RICaction_RefusedToBeModified_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICaction_RefusedToBeModified_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICaction_RefusedToBeModified_ItemIEs_TVALUE t;
      union {
         e2ap_RICaction_RefusedToBeModified_Item * _e2apRICaction_RefusedToBeModified_ItemIEs_RICaction_RefusedToBeModified_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICaction_RefusedToBeModified_ItemIEs;

EXTERN int  asn1PE_e2ap_RICaction_RefusedToBeModified_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_RefusedToBeModified_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICaction_RefusedToBeModified_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_RefusedToBeModified_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICaction_RefusedToBeModified_ItemIEs (e2ap_RICaction_RefusedToBeModified_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICaction_RefusedToBeModified_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_RefusedToBeModified_ItemIEs* pvalue);
