/*****************************************/
/*    RICserviceUpdateFailure_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICserviceUpdateFailure*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICserviceUpdateFailure_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICserviceUpdateFailure_IEs_id_TransactionID,

   T_E2AP_PDU_Contents_e2ap_RICserviceUpdateFailure_IEs_id_Cause,

   T_E2AP_PDU_Contents_e2ap_RICserviceUpdateFailure_IEs_id_TimeToWait,

   T_E2AP_PDU_Contents_e2ap_RICserviceUpdateFailure_IEs_id_CriticalityDiagnostics,

   T_E2AP_PDU_Contents_e2ap_RICserviceUpdateFailure_IEs_id_Extended_RANNodeName_

}e2ap_RICserviceUpdateFailure_IEs_TVALUE;


typedef struct EXTERN e2ap_RICserviceUpdateFailure_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICserviceUpdateFailure_IEs_TVALUE t;
      union {
        /*
        *id: id-TransactionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_TransactionID *_e2ap_RICserviceUpdateFailure_IEs_id_TransactionID;


        /*
        *id: id-Cause
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_Cause *_e2ap_RICserviceUpdateFailure_IEs_id_Cause;


        /*
        *id: id-TimeToWait
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_TimeToWait *_e2ap_RICserviceUpdateFailure_IEs_id_TimeToWait;


        /*
        *id: id-CriticalityDiagnostics
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_CriticalityDiagnostics *_e2ap_RICserviceUpdateFailure_IEs_id_CriticalityDiagnostics;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICserviceUpdateFailure_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICserviceUpdateFailure_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceUpdateFailure_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICserviceUpdateFailure_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceUpdateFailure_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICserviceUpdateFailure_protocolIEs_element (e2ap_RICserviceUpdateFailure_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICserviceUpdateFailure_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceUpdateFailure_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceUpdateFailure_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceUpdateFailure_protocolIEs_element* pvalue);