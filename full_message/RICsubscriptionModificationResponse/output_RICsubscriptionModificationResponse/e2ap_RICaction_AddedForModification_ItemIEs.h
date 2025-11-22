/* e2ap_RICaction_AddedForModification_ItemIEs.h */

/*****************************************/
/*           RICaction_AddedForModification_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICaction_AddedForModification_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICaction_AddedForModification_ItemIEs_RICaction_AddedForModification_Item   
   

} e2ap_RICaction_AddedForModification_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICaction_AddedForModification_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICaction_AddedForModification_ItemIEs_TVALUE t;
      union {
         e2ap_RICaction_AddedForModification_Item * _e2apRICaction_AddedForModification_ItemIEs_RICaction_AddedForModification_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICaction_AddedForModification_ItemIEs;

EXTERN int  asn1PE_e2ap_RICaction_AddedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_AddedForModification_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICaction_AddedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_AddedForModification_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICaction_AddedForModification_ItemIEs (e2ap_RICaction_AddedForModification_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICaction_AddedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_AddedForModification_ItemIEs* pvalue);
