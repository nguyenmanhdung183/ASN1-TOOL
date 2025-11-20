/*****************************************/
/*    E2RemovalRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from E2RemovalRequest*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2RemovalRequestIEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2RemovalRequestIEs_id_TransactionID 
}


typedef struct EXTERN e2ap_E2RemovalRequest_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2RemovalRequestIEs_TVALUE t;
      union {
        /*
        *id: id-TransactionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_TransactionID *_e2apE2RemovalRequest_id_TransactionID


        ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2RemovalRequest_protocolIEs_element;


EXTERN int asn1PE_e2ap_E2RemovalRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2RemovalRequest_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_E2RemovalRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2RemovalRequest_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_E2RemovalRequest_protocolIEs_element (e2ap_E2RemovalRequest_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_E2RemovalRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2RemovalRequest_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2RemovalRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2RemovalRequest_protocolIEs_element* pvalue);