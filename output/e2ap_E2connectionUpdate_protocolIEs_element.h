/*****************************************/
/*    E2connectionUpdate_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from E2connectionUpdate*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdateIEs_id_TransactionID,

   T_E2AP_PDU_Contents_e2ap_E2connectionUpdateIEs_id_E2connectionUpdateAdd,

   T_E2AP_PDU_Contents_e2ap_E2connectionUpdateIEs_id_E2connectionUpdateRemove,

   T_E2AP_PDU_Contents_e2ap_E2connectionUpdateIEs_id_E2connectionUpdateModify,

   T_E2AP_PDU_Contents_e2ap_E2connectionUpdateIEs_id_Extended_RANNodeName_

}e2ap_E2connectionUpdate_IEs_TVALUE;


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
        e2ap_TransactionID *_e2ap_E2connectionUpdateIEs_id_TransactionID,

        /*
        *id: id-E2connectionUpdate-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_E2connectionUpdate_List *_e2ap_E2connectionUpdateIEs_id_E2connectionUpdateAdd,

        /*
        *id: id-E2connectionUpdateRemove-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_E2connectionUpdateRemove_List *_e2ap_E2connectionUpdateIEs_id_E2connectionUpdateRemove,

        /*
        *id: id-E2connectionUpdate-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_E2connectionUpdate_List *_e2ap_E2connectionUpdateIEs_id_E2connectionUpdateModify


        ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2connectionUpdate_protocolIEs_element;


EXTERN int asn1PE_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_E2connectionUpdate_protocolIEs_element (e2ap_E2connectionUpdate_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue);