/*****************************************/
/*    RICserviceLoadUpdate_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICserviceLoadUpdate*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICserviceLoadUpdate_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICserviceLoadUpdate_IEs_id_RICloadMeasurementID,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadUpdate_IEs_id_E2nodeLoadMeasurementID,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadUpdate_IEs_id_RANfunctionLoad_List,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadUpdate_IEs_id_Extended_RANNodeName_

}e2ap_RICserviceLoadUpdate_IEs_TVALUE;


typedef struct EXTERN e2ap_RICserviceLoadUpdate_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICserviceLoadUpdate_IEs_TVALUE t;
      union {
        /*
        *id: id-LoadMeasurementID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_LoadMeasurementID *_e2ap_RICserviceLoadUpdate_IEs_id_RICloadMeasurementID;


        /*
        *id: id-LoadMeasurementID
        *criticality: ignore
        *presence: MANDATORY
        */
        e2ap_LoadMeasurementID *_e2ap_RICserviceLoadUpdate_IEs_id_E2nodeLoadMeasurementID;


        /*
        *id: id-RANfunctionLoad-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctionLoad_List *_e2ap_RICserviceLoadUpdate_IEs_id_RANfunctionLoad_List;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICserviceLoadUpdate_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICserviceLoadUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadUpdate_protocolIEs_element (e2ap_RICserviceLoadUpdate_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate_protocolIEs_element* pvalue);