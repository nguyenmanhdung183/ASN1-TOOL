/*****************************************/
/*    E2nodeConfigurationUpdate_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from E2nodeConfigurationUpdate*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_id_TransactionID ,
   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_id_GlobalE2node_ID ,
   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_id_E2nodeComponentConfigAddition_List ,
   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_id_E2nodeComponentConfigUpdate_List ,
   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_id_E2nodeComponentConfigRemoval_List ,
   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_id_E2nodeTNLassociationRemoval_List 
}


typedef struct EXTERN e2ap_E2nodeConfigurationUpdate_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2nodeConfigurationUpdate_IEs_TVALUE t;
      union {
        /*
        *id: id-TransactionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_TransactionID *_e2apE2nodeConfigurationUpdate_id_TransactionID,

        /*
        *id: id-GlobalE2node-ID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_GlobalE2node_ID *_e2apE2nodeConfigurationUpdate_id_GlobalE2node_ID,

        /*
        *id: id-E2nodeComponentConfigAddition-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_E2nodeComponentConfigAddition_List *_e2apE2nodeConfigurationUpdate_id_E2nodeComponentConfigAddition_List,

        /*
        *id: id-E2nodeComponentConfigUpdate-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_E2nodeComponentConfigUpdate_List *_e2apE2nodeConfigurationUpdate_id_E2nodeComponentConfigUpdate_List,

        /*
        *id: id-E2nodeComponentConfigRemoval-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_E2nodeComponentConfigRemoval_List *_e2apE2nodeConfigurationUpdate_id_E2nodeComponentConfigRemoval_List,

        /*
        *id: id-E2nodeTNLassociationRemoval-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_E2nodeTNLassociationRemoval_List *_e2apE2nodeConfigurationUpdate_id_E2nodeTNLassociationRemoval_List


        ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2nodeConfigurationUpdate_protocolIEs_element;


EXTERN int asn1PE_e2ap_E2nodeConfigurationUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_E2nodeConfigurationUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_E2nodeConfigurationUpdate_protocolIEs_element (e2ap_E2nodeConfigurationUpdate_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_E2nodeConfigurationUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeConfigurationUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate_protocolIEs_element* pvalue);