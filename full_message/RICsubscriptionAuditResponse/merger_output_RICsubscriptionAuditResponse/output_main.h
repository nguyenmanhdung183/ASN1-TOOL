
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

// --- Begin of e2ap_RICaction_Admitted_Item.h ---
/*****************************************/
/*           RICaction_Admitted_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICaction_Admitted_Item {
   e2ap_RICactionID ricActionID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICaction_Admitted_Item;

EXTERN int asn1PE_e2ap_RICaction_Admitted_Item (OSCTXT* pctxt, e2ap_RICaction_Admitted_Item* pvalue);
EXTERN int asn1PD_e2ap_RICaction_Admitted_Item (OSCTXT* pctxt, e2ap_RICaction_Admitted_Item* pvalue);
EXTERN int asn1Init_e2ap_RICaction_Admitted_Item (e2ap_RICaction_Admitted_Item* pvalue);
EXTERN void asn1Free_e2ap_RICaction_Admitted_Item (OSCTXT* pctxt, e2ap_RICaction_Admitted_Item* pvalue);
EXTERN void asn1Print_e2ap_RICaction_Admitted_Item (const char* name, const e2ap_RICaction_Admitted_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICaction_Admitted_Item (const char* name, e2ap_RICaction_Admitted_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICaction_Admitted_Item (OSCTXT* pctxt, const char* name, const e2ap_RICaction_Admitted_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICaction_Admitted_Item (OSCTXT* pctxt, const e2ap_RICaction_Admitted_Item* pSrcValue, e2ap_RICaction_Admitted_Item* pDstValue);
// --- End of e2ap_RICaction_Admitted_Item.h ---

// --- Begin of e2ap_RICaction_Admitted_ItemIEs.h ---
/* e2ap_RICaction_Admitted_ItemIEs.h */

/*****************************************/
/*           RICaction_Admitted_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICaction_Admitted_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICaction_Admitted_ItemIEs_RICaction_Admitted_Item   
   

} e2ap_RICaction_Admitted_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICaction_Admitted_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICaction_Admitted_ItemIEs_TVALUE t;
      union {
         e2ap_RICaction_Admitted_Item * _e2apRICaction_Admitted_ItemIEs_RICaction_Admitted_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICaction_Admitted_ItemIEs;

EXTERN int  asn1PE_e2ap_RICaction_Admitted_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_Admitted_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICaction_Admitted_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_Admitted_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICaction_Admitted_ItemIEs (e2ap_RICaction_Admitted_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICaction_Admitted_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_Admitted_ItemIEs* pvalue);

// --- End of e2ap_RICaction_Admitted_ItemIEs.h ---

// --- Begin of e2ap_RICaction_Admitted_List.h ---
/*****************************************/
/*           RICaction_Admitted_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICaction_Admitted_List;

EXTERN int asn1PE_e2ap_RICaction_Admitted_List (OSCTXT* pctxt, e2ap_RICaction_Admitted_List* pvalue);
EXTERN int asn1PD_e2ap_RICaction_Admitted_List (OSCTXT* pctxt, e2ap_RICaction_Admitted_List* ppvalue);
EXTERN void asn1Init_e2ap_RICaction_Admitted_List (e2ap_RICaction_Admitted_List* pvalue);
EXTERN void asn1Free_e2ap_RICaction_Admitted_List (OSCTXT* pctxt, e2ap_RICaction_Admitted_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICaction_Admitted_List (const char* name, e2ap_RICaction_Admitted_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICaction_Admitted_List (OSCTXT* pctxt, const e2ap_RICaction_Admitted_List* pSrcValue, e2ap_RICaction_Admitted_List* pDstValue);
EXTERN void asn1Print_e2ap_RICaction_Admitted_List (const char *name, const e2ap_RICaction_Admitted_List* pvalue);
// --- End of e2ap_RICaction_Admitted_List.h ---

// --- Begin of e2ap_RICsubscriptionAuditAction_Item.h ---
/*****************************************/
/*           RICsubscriptionAuditAction_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionAuditAction_Item {
   e2ap_RICrequestID ricRequestID;
   e2ap_RANfunctionID ranFunctionID;
   e2ap_RICaction_Admitted_List ricAction_Admitted_List;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionAuditAction_Item;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditAction_Item (OSCTXT* pctxt, e2ap_RICsubscriptionAuditAction_Item* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditAction_Item (OSCTXT* pctxt, e2ap_RICsubscriptionAuditAction_Item* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAuditAction_Item (e2ap_RICsubscriptionAuditAction_Item* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditAction_Item (OSCTXT* pctxt, e2ap_RICsubscriptionAuditAction_Item* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionAuditAction_Item (const char* name, const e2ap_RICsubscriptionAuditAction_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditAction_Item (const char* name, e2ap_RICsubscriptionAuditAction_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionAuditAction_Item (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionAuditAction_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionAuditAction_Item (OSCTXT* pctxt, const e2ap_RICsubscriptionAuditAction_Item* pSrcValue, e2ap_RICsubscriptionAuditAction_Item* pDstValue);
// --- End of e2ap_RICsubscriptionAuditAction_Item.h ---

// --- Begin of e2ap_RICsubscriptionAuditAction_ItemIEs.h ---
/* e2ap_RICsubscriptionAuditAction_ItemIEs.h */

/*****************************************/
/*           RICsubscriptionAuditAction_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditAction_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICsubscriptionAuditAction_ItemIEs_RICsubscriptionAuditAction_Item   
   

} e2ap_RICsubscriptionAuditAction_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICsubscriptionAuditAction_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionAuditAction_ItemIEs_TVALUE t;
      union {
         e2ap_RICsubscriptionAuditAction_Item * _e2apRICsubscriptionAuditAction_ItemIEs_RICsubscriptionAuditAction_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICsubscriptionAuditAction_ItemIEs;

EXTERN int  asn1PE_e2ap_RICsubscriptionAuditAction_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditAction_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICsubscriptionAuditAction_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditAction_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionAuditAction_ItemIEs (e2ap_RICsubscriptionAuditAction_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditAction_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditAction_ItemIEs* pvalue);

// --- End of e2ap_RICsubscriptionAuditAction_ItemIEs.h ---

// --- Begin of e2ap_RICsubscriptionAuditActionList.h ---
/*****************************************/
/*           RICsubscriptionAuditActionList                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICsubscriptionAuditActionList;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditActionList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditActionList* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditActionList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditActionList* ppvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionAuditActionList (e2ap_RICsubscriptionAuditActionList* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditActionList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditActionList* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditActionList (const char* name, e2ap_RICsubscriptionAuditActionList* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICsubscriptionAuditActionList (OSCTXT* pctxt, const e2ap_RICsubscriptionAuditActionList* pSrcValue, e2ap_RICsubscriptionAuditActionList* pDstValue);
EXTERN void asn1Print_e2ap_RICsubscriptionAuditActionList (const char *name, const e2ap_RICsubscriptionAuditActionList* pvalue);
// --- End of e2ap_RICsubscriptionAuditActionList.h ---

// --- Begin of e2ap_RICsubscriptionAudit_Item.h ---
/*****************************************/
/*           RICsubscriptionAudit_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionAudit_Item {
   e2ap_RICrequestID ricRequestID;
   e2ap_RANfunctionID ranFunctionID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionAudit_Item;

EXTERN int asn1PE_e2ap_RICsubscriptionAudit_Item (OSCTXT* pctxt, e2ap_RICsubscriptionAudit_Item* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAudit_Item (OSCTXT* pctxt, e2ap_RICsubscriptionAudit_Item* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAudit_Item (e2ap_RICsubscriptionAudit_Item* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAudit_Item (OSCTXT* pctxt, e2ap_RICsubscriptionAudit_Item* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionAudit_Item (const char* name, const e2ap_RICsubscriptionAudit_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAudit_Item (const char* name, e2ap_RICsubscriptionAudit_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionAudit_Item (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionAudit_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionAudit_Item (OSCTXT* pctxt, const e2ap_RICsubscriptionAudit_Item* pSrcValue, e2ap_RICsubscriptionAudit_Item* pDstValue);
// --- End of e2ap_RICsubscriptionAudit_Item.h ---

// --- Begin of e2ap_RICsubscriptionAudit_ItemIEs.h ---
/* e2ap_RICsubscriptionAudit_ItemIEs.h */

/*****************************************/
/*           RICsubscriptionAudit_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAudit_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICsubscriptionAudit_ItemIEs_RICsubscriptionAudit_Item   
   

} e2ap_RICsubscriptionAudit_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICsubscriptionAudit_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionAudit_ItemIEs_TVALUE t;
      union {
         e2ap_RICsubscriptionAudit_Item * _e2apRICsubscriptionAudit_ItemIEs_RICsubscriptionAudit_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICsubscriptionAudit_ItemIEs;

EXTERN int  asn1PE_e2ap_RICsubscriptionAudit_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAudit_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICsubscriptionAudit_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAudit_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionAudit_ItemIEs (e2ap_RICsubscriptionAudit_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAudit_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAudit_ItemIEs* pvalue);

// --- End of e2ap_RICsubscriptionAudit_ItemIEs.h ---

// --- Begin of e2ap_RICsubscriptionAuditList.h ---
/*****************************************/
/*           RICsubscriptionAuditList                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICsubscriptionAuditList;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditList* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditList* ppvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionAuditList (e2ap_RICsubscriptionAuditList* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditList* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditList (const char* name, e2ap_RICsubscriptionAuditList* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICsubscriptionAuditList (OSCTXT* pctxt, const e2ap_RICsubscriptionAuditList* pSrcValue, e2ap_RICsubscriptionAuditList* pDstValue);
EXTERN void asn1Print_e2ap_RICsubscriptionAuditList (const char *name, const e2ap_RICsubscriptionAuditList* pvalue);
// --- End of e2ap_RICsubscriptionAuditList.h ---

/************************************************************/
/* File .h missing: e2ap_RICsubscriptionAuditResponse_IEs.h */
/************************************************************/

// --- Begin of e2ap_RICsubscriptionAuditResponse.h ---
/*****************************************/
/*           RICsubscriptionAuditResponse                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionAuditResponse {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionAuditResponse;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditResponse (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditResponse (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAuditResponse (e2ap_RICsubscriptionAuditResponse* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditResponse (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionAuditResponse (const char* name, const e2ap_RICsubscriptionAuditResponse* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditResponse (const char* name, e2ap_RICsubscriptionAuditResponse* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionAuditResponse (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionAuditResponse* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionAuditResponse (OSCTXT* pctxt, const e2ap_RICsubscriptionAuditResponse* pSrcValue, e2ap_RICsubscriptionAuditResponse* pDstValue);
// --- End of e2ap_RICsubscriptionAuditResponse.h ---

// --- Begin of e2ap_RICsubscriptionAuditResponse_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICsubscriptionAuditResponse_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICsubscriptionAuditResponse*/

typedef OSRTDList e2ap_RICsubscriptionAuditResponse_protocolIEs;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAuditResponse_protocolIEs (e2ap_RICsubscriptionAuditResponse_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICsubscriptionAuditResponse_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICsubscriptionAuditResponse_protocolIEs* pvalue);
// --- End of e2ap_RICsubscriptionAuditResponse_protocolIEs.h ---

// --- Begin of e2ap_RICsubscriptionAuditResponse_protocolIEs_element.h ---
/*****************************************/
/*    RICsubscriptionAuditResponse_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICsubscriptionAuditResponse*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditResponse_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditResponse_IEs_id_RICrequestID,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditResponse_IEs_id_RICsubscriptionAuditConfirmedList,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditResponse_IEs_id_RICsubscriptionAuditUnkownList,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditResponse_IEs_id_RICsubscriptionAuditMissingList,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditResponse_IEs_id_Extended_RANNodeName_

}e2ap_RICsubscriptionAuditResponse_IEs_TVALUE;


typedef struct EXTERN e2ap_RICsubscriptionAuditResponse_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionAuditResponse_IEs_TVALUE t;
      union {
        /*
        *id: id-RICrequestID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICrequestID *_e2ap_RICsubscriptionAuditResponse_IEs_id_RICrequestID;


        /*
        *id: id-RICsubscriptionAuditActionList
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICsubscriptionAuditActionList *_e2ap_RICsubscriptionAuditResponse_IEs_id_RICsubscriptionAuditConfirmedList;


        /*
        *id: id-RICsubscriptionAuditList
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RICsubscriptionAuditList *_e2ap_RICsubscriptionAuditResponse_IEs_id_RICsubscriptionAuditUnkownList;


        /*
        *id: id-RICsubscriptionAuditActionList
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RICsubscriptionAuditActionList *_e2ap_RICsubscriptionAuditResponse_IEs_id_RICsubscriptionAuditMissingList;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICsubscriptionAuditResponse_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICsubscriptionAuditResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAuditResponse_protocolIEs_element (e2ap_RICsubscriptionAuditResponse_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs_element* pvalue);
// --- End of e2ap_RICsubscriptionAuditResponse_protocolIEs_element.h ---

#endif
