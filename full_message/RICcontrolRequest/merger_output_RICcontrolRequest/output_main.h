
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

// --- Begin of e2ap_RICcallProcessID.h ---
/*****************************************/
/*           RICcallProcessID                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICcallProcessID;

EXTERN int asn1PE_e2ap_RICcallProcessID (OSCTXT* pctxt, e2ap_RICcallProcessID* pvalue);
EXTERN int asn1PD_e2ap_RICcallProcessID (OSCTXT* pctxt, e2ap_RICcallProcessID** ppvalue);
EXTERN void asn1Print_e2ap_RICcallProcessID (const char* name, const e2ap_RICcallProcessID* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICcallProcessID (const char* name, e2ap_RICcallProcessID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICcallProcessID (OSCTXT* pctxt, const char* name, const e2ap_RICcallProcessID* pvalue);
EXTERN int asn1Copy_e2ap_RICcallProcessID (OSCTXT* pctxt, const e2ap_RICcallProcessID* pSrcValue, e2ap_RICcallProcessID* pDstValue);
EXTERN int asn1Init_e2ap_RICcallProcessID (e2ap_RICcallProcessID* pvalue);
EXTERN void asn1Free_e2ap_RICcallProcessID (OSCTXT* pctxt, e2ap_RICcallProcessID* pvalue);
// --- End of e2ap_RICcallProcessID.h ---

// --- Begin of e2ap_RICcontrolHeader.h ---
/*****************************************/
/*           RICcontrolHeader                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICcontrolHeader;

EXTERN int asn1PE_e2ap_RICcontrolHeader (OSCTXT* pctxt, e2ap_RICcontrolHeader* pvalue);
EXTERN int asn1PD_e2ap_RICcontrolHeader (OSCTXT* pctxt, e2ap_RICcontrolHeader** ppvalue);
EXTERN void asn1Print_e2ap_RICcontrolHeader (const char* name, const e2ap_RICcontrolHeader* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICcontrolHeader (const char* name, e2ap_RICcontrolHeader* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICcontrolHeader (OSCTXT* pctxt, const char* name, const e2ap_RICcontrolHeader* pvalue);
EXTERN int asn1Copy_e2ap_RICcontrolHeader (OSCTXT* pctxt, const e2ap_RICcontrolHeader* pSrcValue, e2ap_RICcontrolHeader* pDstValue);
EXTERN int asn1Init_e2ap_RICcontrolHeader (e2ap_RICcontrolHeader* pvalue);
EXTERN void asn1Free_e2ap_RICcontrolHeader (OSCTXT* pctxt, e2ap_RICcontrolHeader* pvalue);
// --- End of e2ap_RICcontrolHeader.h ---

// --- Begin of e2ap_RICcontrolMessage.h ---
/*****************************************/
/*           RICcontrolMessage                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICcontrolMessage;

EXTERN int asn1PE_e2ap_RICcontrolMessage (OSCTXT* pctxt, e2ap_RICcontrolMessage* pvalue);
EXTERN int asn1PD_e2ap_RICcontrolMessage (OSCTXT* pctxt, e2ap_RICcontrolMessage** ppvalue);
EXTERN void asn1Print_e2ap_RICcontrolMessage (const char* name, const e2ap_RICcontrolMessage* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICcontrolMessage (const char* name, e2ap_RICcontrolMessage* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICcontrolMessage (OSCTXT* pctxt, const char* name, const e2ap_RICcontrolMessage* pvalue);
EXTERN int asn1Copy_e2ap_RICcontrolMessage (OSCTXT* pctxt, const e2ap_RICcontrolMessage* pSrcValue, e2ap_RICcontrolMessage* pDstValue);
EXTERN int asn1Init_e2ap_RICcontrolMessage (e2ap_RICcontrolMessage* pvalue);
EXTERN void asn1Free_e2ap_RICcontrolMessage (OSCTXT* pctxt, e2ap_RICcontrolMessage* pvalue);
// --- End of e2ap_RICcontrolMessage.h ---

// --- Begin of e2ap_RICcontrolAckRequest.h ---
/******************************************************/
/*                                                    */
/*    RICcontrolAckRequest                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_noAck = 0,
    e2ap_ack = 1
} e2ap_RICcontrolAckRequest_Root;

typedef OSUINT32 e2ap_RICcontrolAckRequest;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICcontrolAckRequest (OSCTXT* pctxt, e2ap_RICcontrolAckRequest value);
EXTERN int asn1PD_e2ap_RICcontrolAckRequest (OSCTXT* pctxt, e2ap_RICcontrolAckRequest* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICcontrolAckRequest (const char* name, const e2ap_RICcontrolAckRequest* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICcontrolAckRequest (OSCTXT* pctxt, const char* name, const e2ap_RICcontrolAckRequest* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICcontrolAckRequest (const char* name,const e2ap_RICcontrolAckRequest* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICcontrolAckRequest_ENUMTAB[];
#define e2ap_RICcontrolAckRequest_ENUMTABSIZE 2

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICcontrolAckRequest_ToString (OSUINT32 value);
EXTERN int e2ap_RICcontrolAckRequest_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICcontrolAckRequest* pvalue);
EXTERN int e2ap_RICcontrolAckRequest_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICcontrolAckRequest* pvalue);
// --- End of e2ap_RICcontrolAckRequest.h ---

/*************************************************/
/* File .h missing: e2ap_RICcontrolRequest_IEs.h */
/*************************************************/

// --- Begin of e2ap_RICcontrolRequest.h ---
/*****************************************/
/*           RICcontrolRequest                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICcontrolRequest {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICcontrolRequest;

EXTERN int asn1PE_e2ap_RICcontrolRequest (OSCTXT* pctxt, e2ap_RICcontrolRequest* pvalue);
EXTERN int asn1PD_e2ap_RICcontrolRequest (OSCTXT* pctxt, e2ap_RICcontrolRequest* pvalue);
EXTERN int asn1Init_e2ap_RICcontrolRequest (e2ap_RICcontrolRequest* pvalue);
EXTERN void asn1Free_e2ap_RICcontrolRequest (OSCTXT* pctxt, e2ap_RICcontrolRequest* pvalue);
EXTERN void asn1Print_e2ap_RICcontrolRequest (const char* name, const e2ap_RICcontrolRequest* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICcontrolRequest (const char* name, e2ap_RICcontrolRequest* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICcontrolRequest (OSCTXT* pctxt, const char* name, const e2ap_RICcontrolRequest* pvalue);
EXTERN int asn1Copy_e2ap_RICcontrolRequest (OSCTXT* pctxt, const e2ap_RICcontrolRequest* pSrcValue, e2ap_RICcontrolRequest* pDstValue);
// --- End of e2ap_RICcontrolRequest.h ---

// --- Begin of e2ap_RICcontrolRequest_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICcontrolRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICcontrolRequest*/

typedef OSRTDList e2ap_RICcontrolRequest_protocolIEs;

EXTERN int asn1PE_e2ap_RICcontrolRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICcontrolRequest_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICcontrolRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICcontrolRequest_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICcontrolRequest_protocolIEs (e2ap_RICcontrolRequest_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICcontrolRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICcontrolRequest_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICcontrolRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICcontrolRequest_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICcontrolRequest_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICcontrolRequest_protocolIEs* pvalue);
// --- End of e2ap_RICcontrolRequest_protocolIEs.h ---

// --- Begin of e2ap_RICcontrolRequest_protocolIEs_element.h ---
/*****************************************/
/*    RICcontrolRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICcontrolRequest*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICcontrolRequest_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICcontrolRequest_IEs_id_RICrequestID,

   T_E2AP_PDU_Contents_e2ap_RICcontrolRequest_IEs_id_RANfunctionID,

   T_E2AP_PDU_Contents_e2ap_RICcontrolRequest_IEs_id_RICcallProcessID,

   T_E2AP_PDU_Contents_e2ap_RICcontrolRequest_IEs_id_RICcontrolHeader,

   T_E2AP_PDU_Contents_e2ap_RICcontrolRequest_IEs_id_RICcontrolMessage,

   T_E2AP_PDU_Contents_e2ap_RICcontrolRequest_IEs_id_RICcontrolAckRequest,

   T_E2AP_PDU_Contents_e2ap_RICcontrolRequest_IEs_id_Extended_RANNodeName_

}e2ap_RICcontrolRequest_IEs_TVALUE;


typedef struct EXTERN e2ap_RICcontrolRequest_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICcontrolRequest_IEs_TVALUE t;
      union {
        /*
        *id: id-RICrequestID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICrequestID *_e2ap_RICcontrolRequest_IEs_id_RICrequestID;


        /*
        *id: id-RANfunctionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctionID *_e2ap_RICcontrolRequest_IEs_id_RANfunctionID;


        /*
        *id: id-RICcallProcessID
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RICcallProcessID *_e2ap_RICcontrolRequest_IEs_id_RICcallProcessID;


        /*
        *id: id-RICcontrolHeader
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICcontrolHeader *_e2ap_RICcontrolRequest_IEs_id_RICcontrolHeader;


        /*
        *id: id-RICcontrolMessage
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICcontrolMessage *_e2ap_RICcontrolRequest_IEs_id_RICcontrolMessage;


        /*
        *id: id-RICcontrolAckRequest
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RICcontrolAckRequest *_e2ap_RICcontrolRequest_IEs_id_RICcontrolAckRequest;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICcontrolRequest_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICcontrolRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICcontrolRequest_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICcontrolRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICcontrolRequest_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICcontrolRequest_protocolIEs_element (e2ap_RICcontrolRequest_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICcontrolRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICcontrolRequest_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICcontrolRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICcontrolRequest_protocolIEs_element* pvalue);
// --- End of e2ap_RICcontrolRequest_protocolIEs_element.h ---

#endif
