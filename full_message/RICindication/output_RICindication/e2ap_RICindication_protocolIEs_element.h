/*****************************************/
/*    RICindication_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICindication*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICindication_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICindication_IEs_id_RICrequestID,

   T_E2AP_PDU_Contents_e2ap_RICindication_IEs_id_RANfunctionID,

   T_E2AP_PDU_Contents_e2ap_RICindication_IEs_id_RICactionID,

   T_E2AP_PDU_Contents_e2ap_RICindication_IEs_id_RICindicationSN,

   T_E2AP_PDU_Contents_e2ap_RICindication_IEs_id_RICindicationType,

   T_E2AP_PDU_Contents_e2ap_RICindication_IEs_id_RICindicationHeader,

   T_E2AP_PDU_Contents_e2ap_RICindication_IEs_id_RICindicationMessage,

   T_E2AP_PDU_Contents_e2ap_RICindication_IEs_id_RICcallProcessID,

   T_E2AP_PDU_Contents_e2ap_RICindication_IEs_id_Extended_RANNodeName_

}e2ap_RICindication_IEs_TVALUE;


typedef struct EXTERN e2ap_RICindication_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICindication_IEs_TVALUE t;
      union {
        /*
        *id: id-RICrequestID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICrequestID *_e2ap_RICindication_IEs_id_RICrequestID;


        /*
        *id: id-RANfunctionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctionID *_e2ap_RICindication_IEs_id_RANfunctionID;


        /*
        *id: id-RICactionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICactionID *_e2ap_RICindication_IEs_id_RICactionID;


        /*
        *id: id-RICindicationSN
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RICindicationSN *_e2ap_RICindication_IEs_id_RICindicationSN;


        /*
        *id: id-RICindicationType
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICindicationType *_e2ap_RICindication_IEs_id_RICindicationType;


        /*
        *id: id-RICindicationHeader
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICindicationHeader *_e2ap_RICindication_IEs_id_RICindicationHeader;


        /*
        *id: id-RICindicationMessage
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICindicationMessage *_e2ap_RICindication_IEs_id_RICindicationMessage;


        /*
        *id: id-RICcallProcessID
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RICcallProcessID *_e2ap_RICindication_IEs_id_RICcallProcessID;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICindication_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICindication_protocolIEs_element (OSCTXT* pctxt, e2ap_RICindication_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICindication_protocolIEs_element (OSCTXT* pctxt, e2ap_RICindication_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICindication_protocolIEs_element (e2ap_RICindication_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICindication_protocolIEs_element (OSCTXT* pctxt, e2ap_RICindication_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICindication_protocolIEs_element (OSCTXT* pctxt, e2ap_RICindication_protocolIEs_element* pvalue);