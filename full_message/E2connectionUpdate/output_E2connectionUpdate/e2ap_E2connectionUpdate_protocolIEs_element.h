/*****************************************/
/*    E2connectionUpdate_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from E2connectionUpdate*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID ,
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List ,
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List ,
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List ,
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_id_E2connectionUpdate_Item ,
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_id_E2connectionUpdateRemove_Item 
}


typedef struct EXTERN e2ap_E2connectionUpdate_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2connectionUpdate_IEs_TVALUE t;
      union {
        /*
        *id: id-TransactionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_TransactionID *_e2apE2connectionUpdate_id_TransactionID,

        /*
        *id: id-E2connectionUpdate-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_E2connectionUpdate_List *_e2apE2connectionUpdate_id_E2connectionUpdate_List,

        /*
        *id: id-E2connectionUpdateRemove-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_E2connectionUpdateRemove_List *_e2apE2connectionUpdate_id_E2connectionUpdateRemove_List,

        /*
        *id: id-E2connectionUpdate-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_E2connectionUpdate_List *_e2apE2connectionUpdate_id_E2connectionUpdate_List,

        /*
        *id: id-E2connectionUpdate-Item
        *criticality: ignore
        *presence: MANDATORY
        */
        e2ap_E2connectionUpdate_Item *_e2apE2connectionUpdate_id_E2connectionUpdate_Item,

        /*
        *id: id-E2connectionUpdateRemove-Item
        *criticality: ignore
        *presence: MANDATORY
        */
        e2ap_E2connectionUpdateRemove_Item *_e2apE2connectionUpdate_id_E2connectionUpdateRemove_Item


        ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2connectionUpdate_protocolIEs_element;


EXTERN int asn1PE_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_E2connectionUpdate_protocolIEs_element (e2ap_E2connectionUpdate_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue);