
#ifndef OUTPUT_MAIN_H
#define OUTPUT_MAIN_H

// --- Begin of doc/header.h ---
//======================E2AP.h========================//
typedef pd_BitString32 pd_BitString32;
typedef pe_BitString32 pe_BitString32;
typedef asn1PrtToStr_ASN1BitStr32 rtPrintToStringBitStrBraceText;
typedef //asn1Free_ASN1BitStr32 

// --- End of doc/header.h ---

/******************************************/
/* File .h missing: e2ap_ricRequestorID.h */
/******************************************/

/*****************************************/
/* File .h missing: e2ap_ricInstanceID.h */
/*****************************************/

// --- Begin of e2ap_RICrequestID.h ---
/*****************************************/
/*           RICrequestID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICrequestID {
   e2ap_ricRequestorID ricRequestorID;
   e2ap_ricInstanceID ricInstanceID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICrequestID;

EXTERN int asn1PE_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue);
EXTERN int asn1PD_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue);
EXTERN int asn1Init_e2ap_RICrequestID (e2ap_RICrequestID* pvalue);
EXTERN void asn1Free_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue);
EXTERN void asn1Print_e2ap_RICrequestID (const char* name, const e2ap_RICrequestID* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICrequestID (const char* name, e2ap_RICrequestID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICrequestID (OSCTXT* pctxt, const char* name, const e2ap_RICrequestID* pvalue);
EXTERN int asn1Copy_e2ap_RICrequestID (OSCTXT* pctxt, const e2ap_RICrequestID* pSrcValue, e2ap_RICrequestID* pDstValue);
// --- End of e2ap_RICrequestID.h ---

// --- Begin of e2ap_RANfunctionID.h ---
/*****************************************/
/*        RANfunctionID         */
/*****************************************/
//interger no ext


typedef OSUINT16 e2ap_RANfunctionID;

EXTERN int asn1PE_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID value);
EXTERN int asn1PD_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionID (const char* name, const e2ap_RANfunctionID* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionID (const char* name, e2ap_RANfunctionID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionID (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionID* pvalue);
// --- End of e2ap_RANfunctionID.h ---

// --- Begin of e2ap_RICqueryHeader.h ---
/*****************************************/
/*           RICqueryHeader                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICqueryHeader;

EXTERN int asn1PE_e2ap_RICqueryHeader (OSCTXT* pctxt, e2ap_RICqueryHeader* pvalue);
EXTERN int asn1PD_e2ap_RICqueryHeader (OSCTXT* pctxt, e2ap_RICqueryHeader** ppvalue);
EXTERN void asn1Print_e2ap_RICqueryHeader (const char* name, const e2ap_RICqueryHeader* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICqueryHeader (const char* name, e2ap_RICqueryHeader* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICqueryHeader (OSCTXT* pctxt, const char* name, const e2ap_RICqueryHeader* pvalue);
EXTERN int asn1Copy_e2ap_RICqueryHeader (OSCTXT* pctxt, const e2ap_RICqueryHeader* pSrcValue, e2ap_RICqueryHeader* pDstValue);
EXTERN int asn1Init_e2ap_RICqueryHeader (e2ap_RICqueryHeader* pvalue);
EXTERN void asn1Free_e2ap_RICqueryHeader (OSCTXT* pctxt, e2ap_RICqueryHeader* pvalue);
// --- End of e2ap_RICqueryHeader.h ---

// --- Begin of e2ap_RICqueryDefinition.h ---
/*****************************************/
/*           RICqueryDefinition                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICqueryDefinition;

EXTERN int asn1PE_e2ap_RICqueryDefinition (OSCTXT* pctxt, e2ap_RICqueryDefinition* pvalue);
EXTERN int asn1PD_e2ap_RICqueryDefinition (OSCTXT* pctxt, e2ap_RICqueryDefinition** ppvalue);
EXTERN void asn1Print_e2ap_RICqueryDefinition (const char* name, const e2ap_RICqueryDefinition* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICqueryDefinition (const char* name, e2ap_RICqueryDefinition* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICqueryDefinition (OSCTXT* pctxt, const char* name, const e2ap_RICqueryDefinition* pvalue);
EXTERN int asn1Copy_e2ap_RICqueryDefinition (OSCTXT* pctxt, const e2ap_RICqueryDefinition* pSrcValue, e2ap_RICqueryDefinition* pDstValue);
EXTERN int asn1Init_e2ap_RICqueryDefinition (e2ap_RICqueryDefinition* pvalue);
EXTERN void asn1Free_e2ap_RICqueryDefinition (OSCTXT* pctxt, e2ap_RICqueryDefinition* pvalue);
// --- End of e2ap_RICqueryDefinition.h ---

/***********************************************/
/* File .h missing: e2ap_RICqueryRequest_IEs.h */
/***********************************************/

// --- Begin of e2ap_RICqueryRequest.h ---
/*****************************************/
/*           RICqueryRequest                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICqueryRequest {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICqueryRequest;

EXTERN int asn1PE_e2ap_RICqueryRequest (OSCTXT* pctxt, e2ap_RICqueryRequest* pvalue);
EXTERN int asn1PD_e2ap_RICqueryRequest (OSCTXT* pctxt, e2ap_RICqueryRequest* pvalue);
EXTERN int asn1Init_e2ap_RICqueryRequest (e2ap_RICqueryRequest* pvalue);
EXTERN void asn1Free_e2ap_RICqueryRequest (OSCTXT* pctxt, e2ap_RICqueryRequest* pvalue);
EXTERN void asn1Print_e2ap_RICqueryRequest (const char* name, const e2ap_RICqueryRequest* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICqueryRequest (const char* name, e2ap_RICqueryRequest* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICqueryRequest (OSCTXT* pctxt, const char* name, const e2ap_RICqueryRequest* pvalue);
EXTERN int asn1Copy_e2ap_RICqueryRequest (OSCTXT* pctxt, const e2ap_RICqueryRequest* pSrcValue, e2ap_RICqueryRequest* pDstValue);
// --- End of e2ap_RICqueryRequest.h ---

// --- Begin of e2ap_RICqueryRequest_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICqueryRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICqueryRequest*/

typedef OSRTDList e2ap_RICqueryRequest_protocolIEs;

EXTERN int asn1PE_e2ap_RICqueryRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICqueryRequest_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICqueryRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICqueryRequest_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICqueryRequest_protocolIEs (e2ap_RICqueryRequest_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICqueryRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICqueryRequest_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICqueryRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICqueryRequest_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICqueryRequest_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICqueryRequest_protocolIEs* pvalue);
// --- End of e2ap_RICqueryRequest_protocolIEs.h ---

// --- Begin of e2ap_RICqueryRequest_protocolIEs_element.h ---
/*****************************************/
/*    RICqueryRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICqueryRequest*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICqueryRequest_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICqueryRequest_IEs_id_RICrequestID,

   T_E2AP_PDU_Contents_e2ap_RICqueryRequest_IEs_id_RANfunctionID,

   T_E2AP_PDU_Contents_e2ap_RICqueryRequest_IEs_id_RICqueryHeader,

   T_E2AP_PDU_Contents_e2ap_RICqueryRequest_IEs_id_RICqueryDefinition,

   T_E2AP_PDU_Contents_e2ap_RICqueryRequest_IEs_id_Extended_RANNodeName_

}e2ap_RICqueryRequest_IEs_TVALUE;


typedef struct EXTERN e2ap_RICqueryRequest_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICqueryRequest_IEs_TVALUE t;
      union {
        /*
        *id: id-RICrequestID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICrequestID *_e2ap_RICqueryRequest_IEs_id_RICrequestID;


        /*
        *id: id-RANfunctionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctionID *_e2ap_RICqueryRequest_IEs_id_RANfunctionID;


        /*
        *id: id-RICqueryHeader
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICqueryHeader *_e2ap_RICqueryRequest_IEs_id_RICqueryHeader;


        /*
        *id: id-RICqueryDefinition
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICqueryDefinition *_e2ap_RICqueryRequest_IEs_id_RICqueryDefinition;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICqueryRequest_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICqueryRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICqueryRequest_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICqueryRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICqueryRequest_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICqueryRequest_protocolIEs_element (e2ap_RICqueryRequest_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICqueryRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICqueryRequest_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICqueryRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICqueryRequest_protocolIEs_element* pvalue);
// --- End of e2ap_RICqueryRequest_protocolIEs_element.h ---

#endif
