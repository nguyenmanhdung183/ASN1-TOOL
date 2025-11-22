/*****************************************/
/*    E2nodeConfigurationUpdateAcknowledge_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from E2nodeConfigurationUpdateAcknowledge*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID,

   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck,

   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck,

   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck,

   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_Extended_RANNodeName_

}e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_TVALUE;


typedef struct EXTERN e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_TVALUE t;
      union {
        /*
        *id: id-TransactionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_TransactionID *_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID;


        /*
        *id: id-E2nodeComponentConfigAdditionAck-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_E2nodeComponentConfigAdditionAck_List *_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck;


        /*
        *id: id-E2nodeComponentConfigUpdateAck-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_E2nodeComponentConfigUpdateAck_List *_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck;


        /*
        *id: id-E2nodeComponentConfigRemovalAck-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_E2nodeComponentConfigRemovalAck_List *_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element;


EXTERN int asn1PE_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element (e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element* pvalue);