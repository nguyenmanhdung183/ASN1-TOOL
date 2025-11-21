/*****************************************/
/*    E2setupRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from E2setupRequest*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2setupRequest_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_TransactionID,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_GlobalE2node_ID,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_RANfunctionsAdded,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_Extended_RANNodeName_
}


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_TransactionID ,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_GlobalE2node_ID ,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_RANfunctions_List ,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition_List 
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_Extended_RANNodeName_

}e2ap_E2setupRequestIEs_TVALUE;


typedef struct EXTERN e2ap_E2setupRequest_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2setupRequestIEs_TVALUE t;
      union {
        /*
        *id: id-TransactionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_TransactionID *_e2ap_E2setupRequestIEs_id_TransactionID,

        /*
        *id: id-GlobalE2node-ID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_GlobalE2node_ID *_e2ap_E2setupRequestIEs_id_GlobalE2node_ID,

        /*
        *id: id-RANfunctions-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctions_List *_e2ap_E2setupRequestIEs_id_RANfunctionsAdded,

        /*
        *id: id-E2nodeComponentConfigAddition-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_E2nodeComponentConfigAddition_List *_e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition


        ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2setupRequest_protocolIEs_element;


EXTERN int asn1PE_e2ap_E2setupRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_E2setupRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_E2setupRequest_protocolIEs_element (e2ap_E2setupRequest_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_E2setupRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2setupRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs_element* pvalue);