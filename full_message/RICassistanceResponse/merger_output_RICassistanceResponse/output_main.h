
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

// --- Begin of e2ap_RICassistanceHeader.h ---
/*****************************************/
/*           RICassistanceHeader                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICassistanceHeader;

EXTERN int asn1PE_e2ap_RICassistanceHeader (OSCTXT* pctxt, e2ap_RICassistanceHeader* pvalue);
EXTERN int asn1PD_e2ap_RICassistanceHeader (OSCTXT* pctxt, e2ap_RICassistanceHeader** ppvalue);
EXTERN void asn1Print_e2ap_RICassistanceHeader (const char* name, const e2ap_RICassistanceHeader* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceHeader (const char* name, e2ap_RICassistanceHeader* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICassistanceHeader (OSCTXT* pctxt, const char* name, const e2ap_RICassistanceHeader* pvalue);
EXTERN int asn1Copy_e2ap_RICassistanceHeader (OSCTXT* pctxt, const e2ap_RICassistanceHeader* pSrcValue, e2ap_RICassistanceHeader* pDstValue);
EXTERN int asn1Init_e2ap_RICassistanceHeader (e2ap_RICassistanceHeader* pvalue);
EXTERN void asn1Free_e2ap_RICassistanceHeader (OSCTXT* pctxt, e2ap_RICassistanceHeader* pvalue);
// --- End of e2ap_RICassistanceHeader.h ---

// --- Begin of e2ap_RICassistanceOutcome.h ---
/*****************************************/
/*           RICassistanceOutcome                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICassistanceOutcome;

EXTERN int asn1PE_e2ap_RICassistanceOutcome (OSCTXT* pctxt, e2ap_RICassistanceOutcome* pvalue);
EXTERN int asn1PD_e2ap_RICassistanceOutcome (OSCTXT* pctxt, e2ap_RICassistanceOutcome** ppvalue);
EXTERN void asn1Print_e2ap_RICassistanceOutcome (const char* name, const e2ap_RICassistanceOutcome* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceOutcome (const char* name, e2ap_RICassistanceOutcome* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICassistanceOutcome (OSCTXT* pctxt, const char* name, const e2ap_RICassistanceOutcome* pvalue);
EXTERN int asn1Copy_e2ap_RICassistanceOutcome (OSCTXT* pctxt, const e2ap_RICassistanceOutcome* pSrcValue, e2ap_RICassistanceOutcome* pDstValue);
EXTERN int asn1Init_e2ap_RICassistanceOutcome (e2ap_RICassistanceOutcome* pvalue);
EXTERN void asn1Free_e2ap_RICassistanceOutcome (OSCTXT* pctxt, e2ap_RICassistanceOutcome* pvalue);
// --- End of e2ap_RICassistanceOutcome.h ---

/*****************************************************/
/* File .h missing: e2ap_RICassistanceResponse_IEs.h */
/*****************************************************/

// --- Begin of e2ap_RICassistanceResponse.h ---
/*****************************************/
/*           RICassistanceResponse                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICassistanceResponse {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICassistanceResponse;

EXTERN int asn1PE_e2ap_RICassistanceResponse (OSCTXT* pctxt, e2ap_RICassistanceResponse* pvalue);
EXTERN int asn1PD_e2ap_RICassistanceResponse (OSCTXT* pctxt, e2ap_RICassistanceResponse* pvalue);
EXTERN int asn1Init_e2ap_RICassistanceResponse (e2ap_RICassistanceResponse* pvalue);
EXTERN void asn1Free_e2ap_RICassistanceResponse (OSCTXT* pctxt, e2ap_RICassistanceResponse* pvalue);
EXTERN void asn1Print_e2ap_RICassistanceResponse (const char* name, const e2ap_RICassistanceResponse* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceResponse (const char* name, e2ap_RICassistanceResponse* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICassistanceResponse (OSCTXT* pctxt, const char* name, const e2ap_RICassistanceResponse* pvalue);
EXTERN int asn1Copy_e2ap_RICassistanceResponse (OSCTXT* pctxt, const e2ap_RICassistanceResponse* pSrcValue, e2ap_RICassistanceResponse* pDstValue);
// --- End of e2ap_RICassistanceResponse.h ---

// --- Begin of e2ap_RICassistanceResponse_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICassistanceResponse_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICassistanceResponse*/

typedef OSRTDList e2ap_RICassistanceResponse_protocolIEs;

EXTERN int asn1PE_e2ap_RICassistanceResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICassistanceResponse_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICassistanceResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICassistanceResponse_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICassistanceResponse_protocolIEs (e2ap_RICassistanceResponse_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICassistanceResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICassistanceResponse_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICassistanceResponse_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICassistanceResponse_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICassistanceResponse_protocolIEs* pvalue);
// --- End of e2ap_RICassistanceResponse_protocolIEs.h ---

// --- Begin of e2ap_RICassistanceResponse_protocolIEs_element.h ---
/*****************************************/
/*    RICassistanceResponse_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICassistanceResponse*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICassistanceResponse_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICassistanceResponse_IEs_id_RICrequestID,

   T_E2AP_PDU_Contents_e2ap_RICassistanceResponse_IEs_id_RICassistanceHeader,

   T_E2AP_PDU_Contents_e2ap_RICassistanceResponse_IEs_id_RICassistanceOutcome,

   T_E2AP_PDU_Contents_e2ap_RICassistanceResponse_IEs_id_Extended_RANNodeName_

}e2ap_RICassistanceResponse_IEs_TVALUE;


typedef struct EXTERN e2ap_RICassistanceResponse_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICassistanceResponse_IEs_TVALUE t;
      union {
        /*
        *id: id-RICrequestID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICrequestID *_e2ap_RICassistanceResponse_IEs_id_RICrequestID;


        /*
        *id: id-RICassistanceHeader
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICassistanceHeader *_e2ap_RICassistanceResponse_IEs_id_RICassistanceHeader;


        /*
        *id: id-RICassistanceOutcome
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICassistanceOutcome *_e2ap_RICassistanceResponse_IEs_id_RICassistanceOutcome;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICassistanceResponse_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICassistanceResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICassistanceResponse_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICassistanceResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICassistanceResponse_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICassistanceResponse_protocolIEs_element (e2ap_RICassistanceResponse_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICassistanceResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICassistanceResponse_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICassistanceResponse_protocolIEs_element* pvalue);
// --- End of e2ap_RICassistanceResponse_protocolIEs_element.h ---

#endif
