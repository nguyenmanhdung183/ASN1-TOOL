
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

// --- Begin of e2ap_RICactionID.h ---
/*****************************************/
/*        RICactionID         */
/*****************************************/
//interger no ext


typedef OSUINT8 e2ap_RICactionID;

EXTERN int asn1PE_e2ap_RICactionID (OSCTXT* pctxt, e2ap_RICactionID value);
EXTERN int asn1PD_e2ap_RICactionID (OSCTXT* pctxt, e2ap_RICactionID* pvalue);
EXTERN void asn1Print_e2ap_RICactionID (const char* name, const e2ap_RICactionID* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactionID (const char* name, e2ap_RICactionID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICactionID (OSCTXT* pctxt, const char* name, const e2ap_RICactionID* pvalue);
// --- End of e2ap_RICactionID.h ---

// --- Begin of e2ap_RICindicationSN.h ---
/*****************************************/
/*        RICindicationSN         */
/*****************************************/
//interger no ext


typedef OSUINT16 e2ap_RICindicationSN;

EXTERN int asn1PE_e2ap_RICindicationSN (OSCTXT* pctxt, e2ap_RICindicationSN value);
EXTERN int asn1PD_e2ap_RICindicationSN (OSCTXT* pctxt, e2ap_RICindicationSN* pvalue);
EXTERN void asn1Print_e2ap_RICindicationSN (const char* name, const e2ap_RICindicationSN* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICindicationSN (const char* name, e2ap_RICindicationSN* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICindicationSN (OSCTXT* pctxt, const char* name, const e2ap_RICindicationSN* pvalue);
// --- End of e2ap_RICindicationSN.h ---

// --- Begin of e2ap_RICindicationType.h ---
/******************************************************/
/*                                                    */
/*    RICindicationType                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_report = 0,
    e2ap_insert = 1
} e2ap_RICindicationType_Root;

typedef OSUINT32 e2ap_RICindicationType;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICindicationType (OSCTXT* pctxt, e2ap_RICindicationType value);
EXTERN int asn1PD_e2ap_RICindicationType (OSCTXT* pctxt, e2ap_RICindicationType* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICindicationType (const char* name, const e2ap_RICindicationType* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICindicationType (OSCTXT* pctxt, const char* name, const e2ap_RICindicationType* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICindicationType (const char* name,const e2ap_RICindicationType* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICindicationType_ENUMTAB[];
#define e2ap_RICindicationType_ENUMTABSIZE 2

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICindicationType_ToString (OSUINT32 value);
EXTERN int e2ap_RICindicationType_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICindicationType* pvalue);
EXTERN int e2ap_RICindicationType_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICindicationType* pvalue);
// --- End of e2ap_RICindicationType.h ---

// --- Begin of e2ap_RICindicationHeader.h ---
/*****************************************/
/*           RICindicationHeader                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICindicationHeader;

EXTERN int asn1PE_e2ap_RICindicationHeader (OSCTXT* pctxt, e2ap_RICindicationHeader* pvalue);
EXTERN int asn1PD_e2ap_RICindicationHeader (OSCTXT* pctxt, e2ap_RICindicationHeader** ppvalue);
EXTERN void asn1Print_e2ap_RICindicationHeader (const char* name, const e2ap_RICindicationHeader* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICindicationHeader (const char* name, e2ap_RICindicationHeader* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICindicationHeader (OSCTXT* pctxt, const char* name, const e2ap_RICindicationHeader* pvalue);
EXTERN int asn1Copy_e2ap_RICindicationHeader (OSCTXT* pctxt, const e2ap_RICindicationHeader* pSrcValue, e2ap_RICindicationHeader* pDstValue);
EXTERN int asn1Init_e2ap_RICindicationHeader (e2ap_RICindicationHeader* pvalue);
EXTERN void asn1Free_e2ap_RICindicationHeader (OSCTXT* pctxt, e2ap_RICindicationHeader* pvalue);
// --- End of e2ap_RICindicationHeader.h ---

// --- Begin of e2ap_RICindicationMessage.h ---
/*****************************************/
/*           RICindicationMessage                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICindicationMessage;

EXTERN int asn1PE_e2ap_RICindicationMessage (OSCTXT* pctxt, e2ap_RICindicationMessage* pvalue);
EXTERN int asn1PD_e2ap_RICindicationMessage (OSCTXT* pctxt, e2ap_RICindicationMessage** ppvalue);
EXTERN void asn1Print_e2ap_RICindicationMessage (const char* name, const e2ap_RICindicationMessage* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICindicationMessage (const char* name, e2ap_RICindicationMessage* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICindicationMessage (OSCTXT* pctxt, const char* name, const e2ap_RICindicationMessage* pvalue);
EXTERN int asn1Copy_e2ap_RICindicationMessage (OSCTXT* pctxt, const e2ap_RICindicationMessage* pSrcValue, e2ap_RICindicationMessage* pDstValue);
EXTERN int asn1Init_e2ap_RICindicationMessage (e2ap_RICindicationMessage* pvalue);
EXTERN void asn1Free_e2ap_RICindicationMessage (OSCTXT* pctxt, e2ap_RICindicationMessage* pvalue);
// --- End of e2ap_RICindicationMessage.h ---

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

/*********************************************/
/* File .h missing: e2ap_RICindication_IEs.h */
/*********************************************/

// --- Begin of e2ap_RICindication.h ---
/*****************************************/
/*           RICindication                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICindication {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICindication;

EXTERN int asn1PE_e2ap_RICindication (OSCTXT* pctxt, e2ap_RICindication* pvalue);
EXTERN int asn1PD_e2ap_RICindication (OSCTXT* pctxt, e2ap_RICindication* pvalue);
EXTERN int asn1Init_e2ap_RICindication (e2ap_RICindication* pvalue);
EXTERN void asn1Free_e2ap_RICindication (OSCTXT* pctxt, e2ap_RICindication* pvalue);
EXTERN void asn1Print_e2ap_RICindication (const char* name, const e2ap_RICindication* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICindication (const char* name, e2ap_RICindication* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICindication (OSCTXT* pctxt, const char* name, const e2ap_RICindication* pvalue);
EXTERN int asn1Copy_e2ap_RICindication (OSCTXT* pctxt, const e2ap_RICindication* pSrcValue, e2ap_RICindication* pDstValue);
// --- End of e2ap_RICindication.h ---

// --- Begin of e2ap_RICindication_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICindication_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICindication*/

typedef OSRTDList e2ap_RICindication_protocolIEs;

EXTERN int asn1PE_e2ap_RICindication_protocolIEs (OSCTXT* pctxt, e2ap_RICindication_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICindication_protocolIEs (OSCTXT* pctxt, e2ap_RICindication_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICindication_protocolIEs (e2ap_RICindication_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICindication_protocolIEs (OSCTXT* pctxt, e2ap_RICindication_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICindication_protocolIEs (OSCTXT* pctxt, e2ap_RICindication_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICindication_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICindication_protocolIEs* pvalue);
// --- End of e2ap_RICindication_protocolIEs.h ---

// --- Begin of e2ap_RICindication_protocolIEs_element.h ---
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
// --- End of e2ap_RICindication_protocolIEs_element.h ---

#endif
