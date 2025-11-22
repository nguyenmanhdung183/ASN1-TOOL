/*****************************************/
/*    RICsubscriptionModificationRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICsubscriptionModificationRequest*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinitionToBeModified,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeRemovedForModification_List,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeModifiedForModification_List,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeAddedForModification_List,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_Extended_RANNodeName_

}e2ap_RICsubscriptionModificationRequest_IEs_TVALUE;


typedef struct EXTERN e2ap_RICsubscriptionModificationRequest_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionModificationRequest_IEs_TVALUE t;
      union {
        /*
        *id: id-RICrequestID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICrequestID *_e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID;


        /*
        *id: id-RANfunctionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctionID *_e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID;


        /*
        *id: id-RICeventTriggerDefinition
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICeventTriggerDefinition *_e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinitionToBeModified;


        /*
        *id: id-RICactions-ToBeRemovedForModification-List
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICactions_ToBeRemovedForModification_List *_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeRemovedForModification_List;


        /*
        *id: id-RICactions-ToBeModifiedForModification-List
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICactions_ToBeModifiedForModification_List *_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeModifiedForModification_List;


        /*
        *id: id-RICactions-ToBeAddedForModification-List
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICactions_ToBeAddedForModification_List *_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeAddedForModification_List;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICsubscriptionModificationRequest_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue);