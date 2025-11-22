
#ifndef OUTPUT_MAIN_H
#define OUTPUT_MAIN_H

// --- Begin of doc/header.h ---
//======================E2AP.h========================//
typedef pd_BitString32 pd_BitString32;
typedef pe_BitString32 pe_BitString32;
typedef asn1PrtToStr_ASN1BitStr32 rtPrintToStringBitStrBraceText;
typedef //asn1Free_ASN1BitStr32 

// --- End of doc/header.h ---

// --- Begin of e2ap_TransactionID.h ---
/*****************************************/
/*           TransactionID                */
/*****************************************/
//interger with ext


typedef OSUINT8 e2ap_TransactionID;

EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value);
EXTERN int asn1PD_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID* pvalue);
EXTERN void asn1Print_e2ap_TransactionID (const char* name, const e2ap_TransactionID* pvalue);
EXTERN int asn1PrtToStr_e2ap_TransactionID (const char* name, e2ap_TransactionID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_TransactionID (OSCTXT* pctxt, const char* name, const e2ap_TransactionID* pvalue);
// --- End of e2ap_TransactionID.h ---

/***********************************************/
/* File .h missing: e2ap_E2RemovalRequestIEs.h */
/***********************************************/

// --- Begin of e2ap_E2RemovalRequest.h ---
/*****************************************/
/*           E2RemovalRequest                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2RemovalRequest {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2RemovalRequest;

EXTERN int asn1PE_e2ap_E2RemovalRequest (OSCTXT* pctxt, e2ap_E2RemovalRequest* pvalue);
EXTERN int asn1PD_e2ap_E2RemovalRequest (OSCTXT* pctxt, e2ap_E2RemovalRequest* pvalue);
EXTERN int asn1Init_e2ap_E2RemovalRequest (e2ap_E2RemovalRequest* pvalue);
EXTERN void asn1Free_e2ap_E2RemovalRequest (OSCTXT* pctxt, e2ap_E2RemovalRequest* pvalue);
EXTERN void asn1Print_e2ap_E2RemovalRequest (const char* name, const e2ap_E2RemovalRequest* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2RemovalRequest (const char* name, e2ap_E2RemovalRequest* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2RemovalRequest (OSCTXT* pctxt, const char* name, const e2ap_E2RemovalRequest* pvalue);
EXTERN int asn1Copy_e2ap_E2RemovalRequest (OSCTXT* pctxt, const e2ap_E2RemovalRequest* pSrcValue, e2ap_E2RemovalRequest* pDstValue);
// --- End of e2ap_E2RemovalRequest.h ---

// --- Begin of e2ap_E2RemovalRequest_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    E2RemovalRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from E2RemovalRequest*/

typedef OSRTDList e2ap_E2RemovalRequest_protocolIEs;

EXTERN int asn1PE_e2ap_E2RemovalRequest_protocolIEs (OSCTXT* pctxt, e2ap_E2RemovalRequest_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_E2RemovalRequest_protocolIEs (OSCTXT* pctxt, e2ap_E2RemovalRequest_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_E2RemovalRequest_protocolIEs (e2ap_E2RemovalRequest_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_E2RemovalRequest_protocolIEs (OSCTXT* pctxt, e2ap_E2RemovalRequest_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2RemovalRequest_protocolIEs (OSCTXT* pctxt, e2ap_E2RemovalRequest_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apE2RemovalRequest_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_E2RemovalRequest_protocolIEs* pvalue);
// --- End of e2ap_E2RemovalRequest_protocolIEs.h ---

// --- Begin of e2ap_E2RemovalRequest_protocolIEs_element.h ---
/*****************************************/
/*    E2RemovalRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from E2RemovalRequest*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2RemovalRequestIEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2RemovalRequestIEs_id_TransactionID,

   T_E2AP_PDU_Contents_e2ap_E2RemovalRequestIEs_id_Extended_RANNodeName_

}e2ap_E2RemovalRequestIEs_TVALUE;


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
        e2ap_TransactionID *_e2ap_E2RemovalRequestIEs_id_TransactionID;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_E2RemovalRequest_protocolIEs_element;


EXTERN int asn1PE_e2ap_E2RemovalRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2RemovalRequest_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_E2RemovalRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2RemovalRequest_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_E2RemovalRequest_protocolIEs_element (e2ap_E2RemovalRequest_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_E2RemovalRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2RemovalRequest_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2RemovalRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2RemovalRequest_protocolIEs_element* pvalue);
// --- End of e2ap_E2RemovalRequest_protocolIEs_element.h ---

#endif
