/*****************************************/
/*    RICsubscriptionModificationResponse_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICsubscriptionModificationResponse*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationResponse_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationResponse_IEs_id_RICrequestID,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationResponse_IEs_id_RANfunctionID,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationResponse_IEs_id_RICactionsRemovedForModification_List,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationResponse_IEs_id_RICactionsFailedToBeRemovedForModification_List,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationResponse_IEs_id_RICactionsModifiedForModification_List,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationResponse_IEs_id_RICactionsFailedToBeModifiedForModification_List,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationResponse_IEs_id_RICactionsAddedForModification_List,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationResponse_IEs_id_RICactionsFailedToBeAddedForModification_List,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationResponse_IEs_id_Extended_RANNodeName_

}e2ap_RICsubscriptionModificationResponse_IEs_TVALUE;


typedef struct EXTERN e2ap_RICsubscriptionModificationResponse_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionModificationResponse_IEs_TVALUE t;
      union {
        /*
        *id: id-RICrequestID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICrequestID *_e2ap_RICsubscriptionModificationResponse_IEs_id_RICrequestID;


        /*
        *id: id-RANfunctionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctionID *_e2ap_RICsubscriptionModificationResponse_IEs_id_RANfunctionID;


        /*
        *id: id-RICactions-RemovedForModification-List
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICactions_RemovedForModification_List *_e2ap_RICsubscriptionModificationResponse_IEs_id_RICactionsRemovedForModification_List;


        /*
        *id: id-RICactions-FailedToBeRemovedForModification-List
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICactions_FailedToBeRemovedForModification_List *_e2ap_RICsubscriptionModificationResponse_IEs_id_RICactionsFailedToBeRemovedForModification_List;


        /*
        *id: id-RICactions-ModifiedForModification-List
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICactions_ModifiedForModification_List *_e2ap_RICsubscriptionModificationResponse_IEs_id_RICactionsModifiedForModification_List;


        /*
        *id: id-RICactions-FailedToBeModifiedForModification-List
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICactions_FailedToBeModifiedForModification_List *_e2ap_RICsubscriptionModificationResponse_IEs_id_RICactionsFailedToBeModifiedForModification_List;


        /*
        *id: id-RICactions-AddedForModification-List
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICactions_AddedForModification_List *_e2ap_RICsubscriptionModificationResponse_IEs_id_RICactionsAddedForModification_List;


        /*
        *id: id-RICactions-FailedToBeAddedForModification-List
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICactions_FailedToBeAddedForModification_List *_e2ap_RICsubscriptionModificationResponse_IEs_id_RICactionsFailedToBeAddedForModification_List;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICsubscriptionModificationResponse_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICsubscriptionModificationResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationResponse_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionModificationResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationResponse_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionModificationResponse_protocolIEs_element (e2ap_RICsubscriptionModificationResponse_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionModificationResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationResponse_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionModificationResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationResponse_protocolIEs_element* pvalue);