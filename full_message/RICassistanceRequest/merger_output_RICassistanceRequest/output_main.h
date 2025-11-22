
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

// --- Begin of e2ap_RICassistanceMessage.h ---
/*****************************************/
/*           RICassistanceMessage                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICassistanceMessage;

EXTERN int asn1PE_e2ap_RICassistanceMessage (OSCTXT* pctxt, e2ap_RICassistanceMessage* pvalue);
EXTERN int asn1PD_e2ap_RICassistanceMessage (OSCTXT* pctxt, e2ap_RICassistanceMessage** ppvalue);
EXTERN void asn1Print_e2ap_RICassistanceMessage (const char* name, const e2ap_RICassistanceMessage* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceMessage (const char* name, e2ap_RICassistanceMessage* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICassistanceMessage (OSCTXT* pctxt, const char* name, const e2ap_RICassistanceMessage* pvalue);
EXTERN int asn1Copy_e2ap_RICassistanceMessage (OSCTXT* pctxt, const e2ap_RICassistanceMessage* pSrcValue, e2ap_RICassistanceMessage* pDstValue);
EXTERN int asn1Init_e2ap_RICassistanceMessage (e2ap_RICassistanceMessage* pvalue);
EXTERN void asn1Free_e2ap_RICassistanceMessage (OSCTXT* pctxt, e2ap_RICassistanceMessage* pvalue);
// --- End of e2ap_RICassistanceMessage.h ---

// --- Begin of e2ap_RICassistanceUpdate.h ---
/******************************************************/
/*                                                    */
/*    RICassistanceUpdate                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_true = 0
} e2ap_RICassistanceUpdate_Root;

typedef OSUINT32 e2ap_RICassistanceUpdate;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICassistanceUpdate (OSCTXT* pctxt, e2ap_RICassistanceUpdate value);
EXTERN int asn1PD_e2ap_RICassistanceUpdate (OSCTXT* pctxt, e2ap_RICassistanceUpdate* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICassistanceUpdate (const char* name, const e2ap_RICassistanceUpdate* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICassistanceUpdate (OSCTXT* pctxt, const char* name, const e2ap_RICassistanceUpdate* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICassistanceUpdate (const char* name,const e2ap_RICassistanceUpdate* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICassistanceUpdate_ENUMTAB[];
#define e2ap_RICassistanceUpdate_ENUMTABSIZE 1

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICassistanceUpdate_ToString (OSUINT32 value);
EXTERN int e2ap_RICassistanceUpdate_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICassistanceUpdate* pvalue);
EXTERN int e2ap_RICassistanceUpdate_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICassistanceUpdate* pvalue);
// --- End of e2ap_RICassistanceUpdate.h ---

// --- Begin of e2ap_RICassistanceUpdateNumber.h ---
/*****************************************/
/*        RICassistanceUpdateNumber         */
/*****************************************/
//interger no ext


typedef OSUINT16 e2ap_RICassistanceUpdateNumber;

EXTERN int asn1PE_e2ap_RICassistanceUpdateNumber (OSCTXT* pctxt, e2ap_RICassistanceUpdateNumber value);
EXTERN int asn1PD_e2ap_RICassistanceUpdateNumber (OSCTXT* pctxt, e2ap_RICassistanceUpdateNumber* pvalue);
EXTERN void asn1Print_e2ap_RICassistanceUpdateNumber (const char* name, const e2ap_RICassistanceUpdateNumber* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceUpdateNumber (const char* name, e2ap_RICassistanceUpdateNumber* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICassistanceUpdateNumber (OSCTXT* pctxt, const char* name, const e2ap_RICassistanceUpdateNumber* pvalue);
// --- End of e2ap_RICassistanceUpdateNumber.h ---

/****************************************************/
/* File .h missing: e2ap_RICassistanceRequest_IEs.h */
/****************************************************/

// --- Begin of e2ap_RICassistanceRequest.h ---
/*****************************************/
/*           RICassistanceRequest                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICassistanceRequest {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICassistanceRequest;

EXTERN int asn1PE_e2ap_RICassistanceRequest (OSCTXT* pctxt, e2ap_RICassistanceRequest* pvalue);
EXTERN int asn1PD_e2ap_RICassistanceRequest (OSCTXT* pctxt, e2ap_RICassistanceRequest* pvalue);
EXTERN int asn1Init_e2ap_RICassistanceRequest (e2ap_RICassistanceRequest* pvalue);
EXTERN void asn1Free_e2ap_RICassistanceRequest (OSCTXT* pctxt, e2ap_RICassistanceRequest* pvalue);
EXTERN void asn1Print_e2ap_RICassistanceRequest (const char* name, const e2ap_RICassistanceRequest* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceRequest (const char* name, e2ap_RICassistanceRequest* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICassistanceRequest (OSCTXT* pctxt, const char* name, const e2ap_RICassistanceRequest* pvalue);
EXTERN int asn1Copy_e2ap_RICassistanceRequest (OSCTXT* pctxt, const e2ap_RICassistanceRequest* pSrcValue, e2ap_RICassistanceRequest* pDstValue);
// --- End of e2ap_RICassistanceRequest.h ---

// --- Begin of e2ap_RICassistanceRequest_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICassistanceRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICassistanceRequest*/

typedef OSRTDList e2ap_RICassistanceRequest_protocolIEs;

EXTERN int asn1PE_e2ap_RICassistanceRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICassistanceRequest_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICassistanceRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICassistanceRequest_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICassistanceRequest_protocolIEs (e2ap_RICassistanceRequest_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICassistanceRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICassistanceRequest_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICassistanceRequest_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICassistanceRequest_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICassistanceRequest_protocolIEs* pvalue);
// --- End of e2ap_RICassistanceRequest_protocolIEs.h ---

// --- Begin of e2ap_RICassistanceRequest_protocolIEs_element.h ---
/*****************************************/
/*    RICassistanceRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICassistanceRequest*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICassistanceRequest_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICassistanceRequest_IEs_id_RICrequestID,

   T_E2AP_PDU_Contents_e2ap_RICassistanceRequest_IEs_id_RICassistanceHeader,

   T_E2AP_PDU_Contents_e2ap_RICassistanceRequest_IEs_id_RICassistanceMessage,

   T_E2AP_PDU_Contents_e2ap_RICassistanceRequest_IEs_id_RICassistanceUpdate,

   T_E2AP_PDU_Contents_e2ap_RICassistanceRequest_IEs_id_RICassistanceUpdateNumber,

   T_E2AP_PDU_Contents_e2ap_RICassistanceRequest_IEs_id_Extended_RANNodeName_

}e2ap_RICassistanceRequest_IEs_TVALUE;


typedef struct EXTERN e2ap_RICassistanceRequest_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICassistanceRequest_IEs_TVALUE t;
      union {
        /*
        *id: id-RICrequestID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICrequestID *_e2ap_RICassistanceRequest_IEs_id_RICrequestID;


        /*
        *id: id-RICassistanceHeader
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICassistanceHeader *_e2ap_RICassistanceRequest_IEs_id_RICassistanceHeader;


        /*
        *id: id-RICassistanceMessage
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICassistanceMessage *_e2ap_RICassistanceRequest_IEs_id_RICassistanceMessage;


        /*
        *id: id-RICassistanceUpdate
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RICassistanceUpdate *_e2ap_RICassistanceRequest_IEs_id_RICassistanceUpdate;


        /*
        *id: id-RICassistanceUpdateNumber
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RICassistanceUpdateNumber *_e2ap_RICassistanceRequest_IEs_id_RICassistanceUpdateNumber;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICassistanceRequest_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICassistanceRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICassistanceRequest_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICassistanceRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICassistanceRequest_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICassistanceRequest_protocolIEs_element (e2ap_RICassistanceRequest_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICassistanceRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICassistanceRequest_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICassistanceRequest_protocolIEs_element* pvalue);
// --- End of e2ap_RICassistanceRequest_protocolIEs_element.h ---

#endif
