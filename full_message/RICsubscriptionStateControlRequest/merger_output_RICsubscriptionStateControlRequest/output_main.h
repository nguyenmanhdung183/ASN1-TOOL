
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

// --- Begin of e2ap_RICactionList_Item.h ---
/*****************************************/
/*           RICactionList_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICactionList_Item {
   e2ap_RICactionID ricActionID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICactionList_Item;

EXTERN int asn1PE_e2ap_RICactionList_Item (OSCTXT* pctxt, e2ap_RICactionList_Item* pvalue);
EXTERN int asn1PD_e2ap_RICactionList_Item (OSCTXT* pctxt, e2ap_RICactionList_Item* pvalue);
EXTERN int asn1Init_e2ap_RICactionList_Item (e2ap_RICactionList_Item* pvalue);
EXTERN void asn1Free_e2ap_RICactionList_Item (OSCTXT* pctxt, e2ap_RICactionList_Item* pvalue);
EXTERN void asn1Print_e2ap_RICactionList_Item (const char* name, const e2ap_RICactionList_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactionList_Item (const char* name, e2ap_RICactionList_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICactionList_Item (OSCTXT* pctxt, const char* name, const e2ap_RICactionList_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICactionList_Item (OSCTXT* pctxt, const e2ap_RICactionList_Item* pSrcValue, e2ap_RICactionList_Item* pDstValue);
// --- End of e2ap_RICactionList_Item.h ---

// --- Begin of e2ap_RICaction_ItemIEs.h ---
/* e2ap_RICaction_ItemIEs.h */

/*****************************************/
/*           RICaction_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICaction_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICaction_ItemIEs_RICactionList_Item   
   

} e2ap_RICaction_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICaction_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICaction_ItemIEs_TVALUE t;
      union {
         e2ap_RICactionList_Item * _e2apRICaction_ItemIEs_RICactionList_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICaction_ItemIEs;

EXTERN int  asn1PE_e2ap_RICaction_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICaction_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICaction_ItemIEs (e2ap_RICaction_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICaction_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ItemIEs* pvalue);

// --- End of e2ap_RICaction_ItemIEs.h ---

// --- Begin of e2ap_RICaction_List.h ---
/*****************************************/
/*           RICaction_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICaction_List;

EXTERN int asn1PE_e2ap_RICaction_List (OSCTXT* pctxt, e2ap_RICaction_List* pvalue);
EXTERN int asn1PD_e2ap_RICaction_List (OSCTXT* pctxt, e2ap_RICaction_List* ppvalue);
EXTERN void asn1Init_e2ap_RICaction_List (e2ap_RICaction_List* pvalue);
EXTERN void asn1Free_e2ap_RICaction_List (OSCTXT* pctxt, e2ap_RICaction_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICaction_List (const char* name, e2ap_RICaction_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICaction_List (OSCTXT* pctxt, const e2ap_RICaction_List* pSrcValue, e2ap_RICaction_List* pDstValue);
EXTERN void asn1Print_e2ap_RICaction_List (const char *name, const e2ap_RICaction_List* pvalue);
// --- End of e2ap_RICaction_List.h ---

// --- Begin of e2ap_RICsubscriptionList_Item.h ---
/*****************************************/
/*           RICsubscriptionList_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionList_Item {
   e2ap_RICrequestID ricRequestID;
   e2ap_RICaction_List ricAction_list;
     OSBOOL m_ricAction_listPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionList_Item;

EXTERN int asn1PE_e2ap_RICsubscriptionList_Item (OSCTXT* pctxt, e2ap_RICsubscriptionList_Item* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionList_Item (OSCTXT* pctxt, e2ap_RICsubscriptionList_Item* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionList_Item (e2ap_RICsubscriptionList_Item* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionList_Item (OSCTXT* pctxt, e2ap_RICsubscriptionList_Item* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionList_Item (const char* name, const e2ap_RICsubscriptionList_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionList_Item (const char* name, e2ap_RICsubscriptionList_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionList_Item (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionList_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionList_Item (OSCTXT* pctxt, const e2ap_RICsubscriptionList_Item* pSrcValue, e2ap_RICsubscriptionList_Item* pDstValue);
// --- End of e2ap_RICsubscriptionList_Item.h ---

// --- Begin of e2ap_RICsubscriptionList_ItemIEs.h ---
/* e2ap_RICsubscriptionList_ItemIEs.h */

/*****************************************/
/*           RICsubscriptionList_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionList_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICsubscriptionList_ItemIEs_RICsubscriptionList_Item   
   

} e2ap_RICsubscriptionList_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICsubscriptionList_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionList_ItemIEs_TVALUE t;
      union {
         e2ap_RICsubscriptionList_Item * _e2apRICsubscriptionList_ItemIEs_RICsubscriptionList_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICsubscriptionList_ItemIEs;

EXTERN int  asn1PE_e2ap_RICsubscriptionList_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionList_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICsubscriptionList_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionList_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionList_ItemIEs (e2ap_RICsubscriptionList_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionList_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionList_ItemIEs* pvalue);

// --- End of e2ap_RICsubscriptionList_ItemIEs.h ---

// --- Begin of e2ap_RICsubscriptionToBeSuspended_List.h ---
/*****************************************/
/*           RICsubscriptionToBeSuspended_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICsubscriptionToBeSuspended_List;

EXTERN int asn1PE_e2ap_RICsubscriptionToBeSuspended_List (OSCTXT* pctxt, e2ap_RICsubscriptionToBeSuspended_List* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionToBeSuspended_List (OSCTXT* pctxt, e2ap_RICsubscriptionToBeSuspended_List* ppvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionToBeSuspended_List (e2ap_RICsubscriptionToBeSuspended_List* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionToBeSuspended_List (OSCTXT* pctxt, e2ap_RICsubscriptionToBeSuspended_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionToBeSuspended_List (const char* name, e2ap_RICsubscriptionToBeSuspended_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICsubscriptionToBeSuspended_List (OSCTXT* pctxt, const e2ap_RICsubscriptionToBeSuspended_List* pSrcValue, e2ap_RICsubscriptionToBeSuspended_List* pDstValue);
EXTERN void asn1Print_e2ap_RICsubscriptionToBeSuspended_List (const char *name, const e2ap_RICsubscriptionToBeSuspended_List* pvalue);
// --- End of e2ap_RICsubscriptionToBeSuspended_List.h ---

// --- Begin of e2ap_RICsubscriptionToBeResumed_List.h ---
/*****************************************/
/*           RICsubscriptionToBeResumed_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICsubscriptionToBeResumed_List;

EXTERN int asn1PE_e2ap_RICsubscriptionToBeResumed_List (OSCTXT* pctxt, e2ap_RICsubscriptionToBeResumed_List* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionToBeResumed_List (OSCTXT* pctxt, e2ap_RICsubscriptionToBeResumed_List* ppvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionToBeResumed_List (e2ap_RICsubscriptionToBeResumed_List* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionToBeResumed_List (OSCTXT* pctxt, e2ap_RICsubscriptionToBeResumed_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionToBeResumed_List (const char* name, e2ap_RICsubscriptionToBeResumed_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICsubscriptionToBeResumed_List (OSCTXT* pctxt, const e2ap_RICsubscriptionToBeResumed_List* pSrcValue, e2ap_RICsubscriptionToBeResumed_List* pDstValue);
EXTERN void asn1Print_e2ap_RICsubscriptionToBeResumed_List (const char *name, const e2ap_RICsubscriptionToBeResumed_List* pvalue);
// --- End of e2ap_RICsubscriptionToBeResumed_List.h ---

// --- Begin of e2ap_RANfunctionStateControl_Item.h ---
/*****************************************/
/*           RANfunctionStateControl_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RANfunctionStateControl_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_RICsubscriptionToBeSuspended_List ricSubscriptionToBeSuspended_list;
     OSBOOL m_ricSubscriptionToBeSuspended_listPresent;   e2ap_RICsubscriptionToBeResumed_List ricSubscriptionToBeResumed_list;
     OSBOOL m_ricSubscriptionToBeResumed_listPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RANfunctionStateControl_Item;

EXTERN int asn1PE_e2ap_RANfunctionStateControl_Item (OSCTXT* pctxt, e2ap_RANfunctionStateControl_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionStateControl_Item (OSCTXT* pctxt, e2ap_RANfunctionStateControl_Item* pvalue);
EXTERN int asn1Init_e2ap_RANfunctionStateControl_Item (e2ap_RANfunctionStateControl_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionStateControl_Item (OSCTXT* pctxt, e2ap_RANfunctionStateControl_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionStateControl_Item (const char* name, const e2ap_RANfunctionStateControl_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionStateControl_Item (const char* name, e2ap_RANfunctionStateControl_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionStateControl_Item (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionStateControl_Item* pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionStateControl_Item (OSCTXT* pctxt, const e2ap_RANfunctionStateControl_Item* pSrcValue, e2ap_RANfunctionStateControl_Item* pDstValue);
// --- End of e2ap_RANfunctionStateControl_Item.h ---

// --- Begin of e2ap_RANfunctionStateControl_ItemIEs.h ---
/* e2ap_RANfunctionStateControl_ItemIEs.h */

/*****************************************/
/*           RANfunctionStateControl_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RANfunctionStateControl_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RANfunctionStateControl_ItemIEs_RANfunctionStateControl_Item   
   

} e2ap_RANfunctionStateControl_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RANfunctionStateControl_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RANfunctionStateControl_ItemIEs_TVALUE t;
      union {
         e2ap_RANfunctionStateControl_Item * _e2apRANfunctionStateControl_ItemIEs_RANfunctionStateControl_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RANfunctionStateControl_ItemIEs;

EXTERN int  asn1PE_e2ap_RANfunctionStateControl_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionStateControl_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RANfunctionStateControl_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionStateControl_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RANfunctionStateControl_ItemIEs (e2ap_RANfunctionStateControl_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionStateControl_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionStateControl_ItemIEs* pvalue);

// --- End of e2ap_RANfunctionStateControl_ItemIEs.h ---

// --- Begin of e2ap_RANfunctionStateControl_List.h ---
/*****************************************/
/*           RANfunctionStateControl_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RANfunctionStateControl_List;

EXTERN int asn1PE_e2ap_RANfunctionStateControl_List (OSCTXT* pctxt, e2ap_RANfunctionStateControl_List* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionStateControl_List (OSCTXT* pctxt, e2ap_RANfunctionStateControl_List* ppvalue);
EXTERN void asn1Init_e2ap_RANfunctionStateControl_List (e2ap_RANfunctionStateControl_List* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionStateControl_List (OSCTXT* pctxt, e2ap_RANfunctionStateControl_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionStateControl_List (const char* name, e2ap_RANfunctionStateControl_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RANfunctionStateControl_List (OSCTXT* pctxt, const e2ap_RANfunctionStateControl_List* pSrcValue, e2ap_RANfunctionStateControl_List* pDstValue);
EXTERN void asn1Print_e2ap_RANfunctionStateControl_List (const char *name, const e2ap_RANfunctionStateControl_List* pvalue);
// --- End of e2ap_RANfunctionStateControl_List.h ---

/******************************************************************/
/* File .h missing: e2ap_RICsubscriptionStateControlRequest_IEs.h */
/******************************************************************/

// --- Begin of e2ap_RICsubscriptionStateControlRequest.h ---
/*****************************************/
/*           RICsubscriptionStateControlRequest                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionStateControlRequest {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionStateControlRequest;

EXTERN int asn1PE_e2ap_RICsubscriptionStateControlRequest (OSCTXT* pctxt, e2ap_RICsubscriptionStateControlRequest* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionStateControlRequest (OSCTXT* pctxt, e2ap_RICsubscriptionStateControlRequest* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionStateControlRequest (e2ap_RICsubscriptionStateControlRequest* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionStateControlRequest (OSCTXT* pctxt, e2ap_RICsubscriptionStateControlRequest* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionStateControlRequest (const char* name, const e2ap_RICsubscriptionStateControlRequest* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionStateControlRequest (const char* name, e2ap_RICsubscriptionStateControlRequest* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionStateControlRequest (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionStateControlRequest* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionStateControlRequest (OSCTXT* pctxt, const e2ap_RICsubscriptionStateControlRequest* pSrcValue, e2ap_RICsubscriptionStateControlRequest* pDstValue);
// --- End of e2ap_RICsubscriptionStateControlRequest.h ---

// --- Begin of e2ap_RICsubscriptionStateControlRequest_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICsubscriptionStateControlRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICsubscriptionStateControlRequest*/

typedef OSRTDList e2ap_RICsubscriptionStateControlRequest_protocolIEs;

EXTERN int asn1PE_e2ap_RICsubscriptionStateControlRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionStateControlRequest_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionStateControlRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionStateControlRequest_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionStateControlRequest_protocolIEs (e2ap_RICsubscriptionStateControlRequest_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionStateControlRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionStateControlRequest_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionStateControlRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionStateControlRequest_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICsubscriptionStateControlRequest_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICsubscriptionStateControlRequest_protocolIEs* pvalue);
// --- End of e2ap_RICsubscriptionStateControlRequest_protocolIEs.h ---

// --- Begin of e2ap_RICsubscriptionStateControlRequest_protocolIEs_element.h ---
/*****************************************/
/*    RICsubscriptionStateControlRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICsubscriptionStateControlRequest*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionStateControlRequest_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionStateControlRequest_IEs_id_RICrequestID,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionStateControlRequest_IEs_id_RANfunctionStateControl_List,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionStateControlRequest_IEs_id_Extended_RANNodeName_

}e2ap_RICsubscriptionStateControlRequest_IEs_TVALUE;


typedef struct EXTERN e2ap_RICsubscriptionStateControlRequest_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionStateControlRequest_IEs_TVALUE t;
      union {
        /*
        *id: id-RICrequestID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICrequestID *_e2ap_RICsubscriptionStateControlRequest_IEs_id_RICrequestID;


        /*
        *id: id-RANfunctionStateControl-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctionStateControl_List *_e2ap_RICsubscriptionStateControlRequest_IEs_id_RANfunctionStateControl_List;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICsubscriptionStateControlRequest_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICsubscriptionStateControlRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionStateControlRequest_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionStateControlRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionStateControlRequest_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionStateControlRequest_protocolIEs_element (e2ap_RICsubscriptionStateControlRequest_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionStateControlRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionStateControlRequest_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionStateControlRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionStateControlRequest_protocolIEs_element* pvalue);
// --- End of e2ap_RICsubscriptionStateControlRequest_protocolIEs_element.h ---

#endif
