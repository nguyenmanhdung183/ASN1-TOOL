/*****************************************/
/*    RICsubscriptionAuditResponse_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICsubscriptionAuditResponse*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditResponse_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditResponse_IEs_id_RICrequestID,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditResponse_IEs_id_RICsubscriptionAuditConfirmedList,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditResponse_IEs_id_RICsubscriptionAuditUnkownList,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditResponse_IEs_id_RICsubscriptionAuditMissingList,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditResponse_IEs_id_Extended_RANNodeName_

}e2ap_RICsubscriptionAuditResponse_IEs_TVALUE;


typedef struct EXTERN e2ap_RICsubscriptionAuditResponse_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionAuditResponse_IEs_TVALUE t;
      union {
        /*
        *id: id-RICrequestID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICrequestID *_e2ap_RICsubscriptionAuditResponse_IEs_id_RICrequestID;


        /*
        *id: id-RICsubscriptionAuditActionList
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICsubscriptionAuditActionList *_e2ap_RICsubscriptionAuditResponse_IEs_id_RICsubscriptionAuditConfirmedList;


        /*
        *id: id-RICsubscriptionAuditList
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RICsubscriptionAuditList *_e2ap_RICsubscriptionAuditResponse_IEs_id_RICsubscriptionAuditUnkownList;


        /*
        *id: id-RICsubscriptionAuditActionList
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RICsubscriptionAuditActionList *_e2ap_RICsubscriptionAuditResponse_IEs_id_RICsubscriptionAuditMissingList;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICsubscriptionAuditResponse_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICsubscriptionAuditResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAuditResponse_protocolIEs_element (e2ap_RICsubscriptionAuditResponse_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs_element* pvalue);