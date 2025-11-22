
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

// --- Begin of e2ap_PLMN_Identity.h ---
/*****************************************/
/*           PLMN_Identity                */
/*****************************************/
//octet string


typedef struct e2ap_PLMN_Identity {
   OSUINT32 numocts;
   OSOCTET data[3];
} e2ap_PLMN_Identity;

EXTERN int asn1PE_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue);
EXTERN int asn1PD_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity** ppvalue);
EXTERN void asn1Print_e2ap_PLMN_Identity (const char* name, const e2ap_PLMN_Identity* pvalue);
EXTERN int asn1PrtToStr_e2ap_PLMN_Identity (const char* name, e2ap_PLMN_Identity* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_PLMN_Identity (OSCTXT* pctxt, const char* name, const e2ap_PLMN_Identity* pvalue);
EXTERN int asn1Copy_e2ap_PLMN_Identity (OSCTXT* pctxt, const e2ap_PLMN_Identity* pSrcValue, e2ap_PLMN_Identity* pDstValue);
EXTERN int asn1Init_e2ap_PLMN_Identity (e2ap_PLMN_Identity* pvalue);
EXTERN void asn1Free_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue);
// --- End of e2ap_PLMN_Identity.h ---

/**********************************/
/* File .h missing: e2ap_ric_ID.h */
/**********************************/

// --- Begin of e2ap_GlobalRIC_ID.h ---
/*****************************************/
/*           GlobalRIC_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalRIC_ID {
   e2ap_PLMN_Identity pLMN_Identity;
   ASN1BitStr32 ric_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalRIC_ID;

EXTERN int asn1PE_e2ap_GlobalRIC_ID (OSCTXT* pctxt, e2ap_GlobalRIC_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalRIC_ID (OSCTXT* pctxt, e2ap_GlobalRIC_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalRIC_ID (e2ap_GlobalRIC_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalRIC_ID (OSCTXT* pctxt, e2ap_GlobalRIC_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalRIC_ID (const char* name, const e2ap_GlobalRIC_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalRIC_ID (const char* name, e2ap_GlobalRIC_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalRIC_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalRIC_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalRIC_ID (OSCTXT* pctxt, const e2ap_GlobalRIC_ID* pSrcValue, e2ap_GlobalRIC_ID* pDstValue);
// --- End of e2ap_GlobalRIC_ID.h ---

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

// --- Begin of e2ap_RANfunctionRevision.h ---
/*****************************************/
/*        RANfunctionRevision         */
/*****************************************/
//interger no ext


typedef OSUINT16 e2ap_RANfunctionRevision;

EXTERN int asn1PE_e2ap_RANfunctionRevision (OSCTXT* pctxt, e2ap_RANfunctionRevision value);
EXTERN int asn1PD_e2ap_RANfunctionRevision (OSCTXT* pctxt, e2ap_RANfunctionRevision* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionRevision (const char* name, const e2ap_RANfunctionRevision* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionRevision (const char* name, e2ap_RANfunctionRevision* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionRevision (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionRevision* pvalue);
// --- End of e2ap_RANfunctionRevision.h ---

// --- Begin of e2ap_RANfunctionID_Item.h ---
/*****************************************/
/*           RANfunctionID_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RANfunctionID_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_RANfunctionRevision ranFunctionRevision;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RANfunctionID_Item;

EXTERN int asn1PE_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue);
EXTERN int asn1Init_e2ap_RANfunctionID_Item (e2ap_RANfunctionID_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionID_Item (const char* name, const e2ap_RANfunctionID_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionID_Item (const char* name, e2ap_RANfunctionID_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionID_Item (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionID_Item* pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionID_Item (OSCTXT* pctxt, const e2ap_RANfunctionID_Item* pSrcValue, e2ap_RANfunctionID_Item* pDstValue);
// --- End of e2ap_RANfunctionID_Item.h ---

// --- Begin of e2ap_RANfunctionID_ItemIEs.h ---
/* e2ap_RANfunctionID_ItemIEs.h */

/*****************************************/
/*           RANfunctionID_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RANfunctionID_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RANfunctionID_ItemIEs_RANfunctionID_Item   
   

} e2ap_RANfunctionID_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RANfunctionID_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RANfunctionID_ItemIEs_TVALUE t;
      union {
         e2ap_RANfunctionID_Item * _e2apRANfunctionID_ItemIEs_RANfunctionID_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RANfunctionID_ItemIEs;

EXTERN int  asn1PE_e2ap_RANfunctionID_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionID_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RANfunctionID_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionID_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RANfunctionID_ItemIEs (e2ap_RANfunctionID_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionID_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionID_ItemIEs* pvalue);

// --- End of e2ap_RANfunctionID_ItemIEs.h ---

// --- Begin of e2ap_RANfunctionsID_List.h ---
/*****************************************/
/*           RANfunctionsID_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RANfunctionsID_List;

EXTERN int asn1PE_e2ap_RANfunctionsID_List (OSCTXT* pctxt, e2ap_RANfunctionsID_List* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionsID_List (OSCTXT* pctxt, e2ap_RANfunctionsID_List* ppvalue);
EXTERN void asn1Init_e2ap_RANfunctionsID_List (e2ap_RANfunctionsID_List* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionsID_List (OSCTXT* pctxt, e2ap_RANfunctionsID_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionsID_List (const char* name, e2ap_RANfunctionsID_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RANfunctionsID_List (OSCTXT* pctxt, const e2ap_RANfunctionsID_List* pSrcValue, e2ap_RANfunctionsID_List* pDstValue);
EXTERN void asn1Print_e2ap_RANfunctionsID_List (const char *name, const e2ap_RANfunctionsID_List* pvalue);
// --- End of e2ap_RANfunctionsID_List.h ---

// --- Begin of e2ap_CauseRICrequest.h ---
/******************************************************/
/*                                                    */
/*    CauseRICrequest                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_ran_function_id_invalid = 0,
    e2ap_action_not_supported = 1,
    e2ap_excessive_actions = 2,
    e2ap_duplicate_action = 3,
    e2ap_duplicate_event_trigger = 4,
    e2ap_function_resource_limit = 5,
    e2ap_request_id_unknown = 6,
    e2ap_inconsistent_action_subsequent_action_sequence = 7,
    e2ap_control_message_invalid = 8,
    e2ap_ric_call_process_id_invalid = 9,
    e2ap_control_timer_expired = 10,
    e2ap_control_failed_to_execute = 11,
    e2ap_system_not_ready = 12,
    e2ap_unspecified = 13,
    e2ap_ric_subscription_end_time_expired = 14,
    e2ap_ric_subscription_end_time_invalid = 15,
    e2ap_duplicate_ric_request_id = 16,
    e2ap_eventTriggerNotSupported = 17,
    e2ap_requested_information_unavailable = 18,
    e2ap_invalid_information_request = 19
} e2ap_CauseRICrequest_Root;

typedef OSUINT32 e2ap_CauseRICrequest;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_CauseRICrequest (OSCTXT* pctxt, e2ap_CauseRICrequest value);
EXTERN int asn1PD_e2ap_CauseRICrequest (OSCTXT* pctxt, e2ap_CauseRICrequest* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_CauseRICrequest (const char* name, const e2ap_CauseRICrequest* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_CauseRICrequest (OSCTXT* pctxt, const char* name, const e2ap_CauseRICrequest* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_CauseRICrequest (const char* name,const e2ap_CauseRICrequest* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseRICrequest_ENUMTAB[];
#define e2ap_CauseRICrequest_ENUMTABSIZE 20

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseRICrequest_ToString (OSUINT32 value);
EXTERN int e2ap_CauseRICrequest_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseRICrequest* pvalue);
EXTERN int e2ap_CauseRICrequest_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseRICrequest* pvalue);
// --- End of e2ap_CauseRICrequest.h ---

// --- Begin of e2ap_CauseRICservice.h ---
/******************************************************/
/*                                                    */
/*    CauseRICservice                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_ran_function_not_supported = 0,
    e2ap_excessive_functions = 1,
    e2ap_ric_resource_limit = 2
} e2ap_CauseRICservice_Root;

typedef OSUINT32 e2ap_CauseRICservice;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_CauseRICservice (OSCTXT* pctxt, e2ap_CauseRICservice value);
EXTERN int asn1PD_e2ap_CauseRICservice (OSCTXT* pctxt, e2ap_CauseRICservice* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_CauseRICservice (const char* name, const e2ap_CauseRICservice* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_CauseRICservice (OSCTXT* pctxt, const char* name, const e2ap_CauseRICservice* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_CauseRICservice (const char* name,const e2ap_CauseRICservice* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseRICservice_ENUMTAB[];
#define e2ap_CauseRICservice_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseRICservice_ToString (OSUINT32 value);
EXTERN int e2ap_CauseRICservice_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseRICservice* pvalue);
EXTERN int e2ap_CauseRICservice_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseRICservice* pvalue);
// --- End of e2ap_CauseRICservice.h ---

// --- Begin of e2ap_CauseE2node.h ---
/******************************************************/
/*                                                    */
/*    CauseE2node                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_e2node_component_unknown = 0
} e2ap_CauseE2node_Root;

typedef OSUINT32 e2ap_CauseE2node;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_CauseE2node (OSCTXT* pctxt, e2ap_CauseE2node value);
EXTERN int asn1PD_e2ap_CauseE2node (OSCTXT* pctxt, e2ap_CauseE2node* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_CauseE2node (const char* name, const e2ap_CauseE2node* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_CauseE2node (OSCTXT* pctxt, const char* name, const e2ap_CauseE2node* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_CauseE2node (const char* name,const e2ap_CauseE2node* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseE2node_ENUMTAB[];
#define e2ap_CauseE2node_ENUMTABSIZE 1

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseE2node_ToString (OSUINT32 value);
EXTERN int e2ap_CauseE2node_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseE2node* pvalue);
EXTERN int e2ap_CauseE2node_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseE2node* pvalue);
// --- End of e2ap_CauseE2node.h ---

// --- Begin of e2ap_CauseTransport.h ---
/******************************************************/
/*                                                    */
/*    CauseTransport                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_unspecified = 0,
    e2ap_transport_resource_unavailable = 1
} e2ap_CauseTransport_Root;

typedef OSUINT32 e2ap_CauseTransport;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_CauseTransport (OSCTXT* pctxt, e2ap_CauseTransport value);
EXTERN int asn1PD_e2ap_CauseTransport (OSCTXT* pctxt, e2ap_CauseTransport* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_CauseTransport (const char* name, const e2ap_CauseTransport* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_CauseTransport (OSCTXT* pctxt, const char* name, const e2ap_CauseTransport* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_CauseTransport (const char* name,const e2ap_CauseTransport* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseTransport_ENUMTAB[];
#define e2ap_CauseTransport_ENUMTABSIZE 2

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseTransport_ToString (OSUINT32 value);
EXTERN int e2ap_CauseTransport_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseTransport* pvalue);
EXTERN int e2ap_CauseTransport_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseTransport* pvalue);
// --- End of e2ap_CauseTransport.h ---

// --- Begin of e2ap_CauseProtocol.h ---
/******************************************************/
/*                                                    */
/*    CauseProtocol                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_transfer_syntax_error = 0,
    e2ap_abstract_syntax_error_reject = 1,
    e2ap_abstract_syntax_error_ignore_and_notify = 2,
    e2ap_message_not_compatible_with_receiver_state = 3,
    e2ap_semantic_error = 4,
    e2ap_abstract_syntax_error_falsely_constructed_message = 5,
    e2ap_unspecified = 6
} e2ap_CauseProtocol_Root;

typedef OSUINT32 e2ap_CauseProtocol;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_CauseProtocol (OSCTXT* pctxt, e2ap_CauseProtocol value);
EXTERN int asn1PD_e2ap_CauseProtocol (OSCTXT* pctxt, e2ap_CauseProtocol* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_CauseProtocol (const char* name, const e2ap_CauseProtocol* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_CauseProtocol (OSCTXT* pctxt, const char* name, const e2ap_CauseProtocol* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_CauseProtocol (const char* name,const e2ap_CauseProtocol* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseProtocol_ENUMTAB[];
#define e2ap_CauseProtocol_ENUMTABSIZE 7

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseProtocol_ToString (OSUINT32 value);
EXTERN int e2ap_CauseProtocol_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseProtocol* pvalue);
EXTERN int e2ap_CauseProtocol_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseProtocol* pvalue);
// --- End of e2ap_CauseProtocol.h ---

// --- Begin of e2ap_CauseMisc.h ---
/******************************************************/
/*                                                    */
/*    CauseMisc                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_control_processing_overload = 0,
    e2ap_hardware_failure = 1,
    e2ap_om_intervention = 2,
    e2ap_unspecified = 3
} e2ap_CauseMisc_Root;

typedef OSUINT32 e2ap_CauseMisc;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc value);
EXTERN int asn1PD_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_CauseMisc (const char* name, const e2ap_CauseMisc* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_CauseMisc (OSCTXT* pctxt, const char* name, const e2ap_CauseMisc* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_CauseMisc (const char* name,const e2ap_CauseMisc* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseMisc_ENUMTAB[];
#define e2ap_CauseMisc_ENUMTABSIZE 4

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseMisc_ToString (OSUINT32 value);
EXTERN int e2ap_CauseMisc_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseMisc* pvalue);
EXTERN int e2ap_CauseMisc_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseMisc* pvalue);
// --- End of e2ap_CauseMisc.h ---

// --- Begin of e2ap_ServiceLayerCause.h ---
/*****************************************/
/*           ServiceLayerCause                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_ServiceLayerCause;

EXTERN int asn1PE_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause* pvalue);
EXTERN int asn1PD_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause** ppvalue);
EXTERN void asn1Print_e2ap_ServiceLayerCause (const char* name, const e2ap_ServiceLayerCause* pvalue);
EXTERN int asn1PrtToStr_e2ap_ServiceLayerCause (const char* name, e2ap_ServiceLayerCause* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_ServiceLayerCause (OSCTXT* pctxt, const char* name, const e2ap_ServiceLayerCause* pvalue);
EXTERN int asn1Copy_e2ap_ServiceLayerCause (OSCTXT* pctxt, const e2ap_ServiceLayerCause* pSrcValue, e2ap_ServiceLayerCause* pDstValue);
EXTERN int asn1Init_e2ap_ServiceLayerCause (e2ap_ServiceLayerCause* pvalue);
EXTERN void asn1Free_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause* pvalue);
// --- End of e2ap_ServiceLayerCause.h ---

// --- Begin of e2ap_CauseServiceLayer.h ---
/*****************************************/
/*           CauseServiceLayer                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_CauseServiceLayer {
   e2ap_ServiceLayerCause serviceLayerCause;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_CauseServiceLayer;

EXTERN int asn1PE_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue);
EXTERN int asn1PD_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue);
EXTERN int asn1Init_e2ap_CauseServiceLayer (e2ap_CauseServiceLayer* pvalue);
EXTERN void asn1Free_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue);
EXTERN void asn1Print_e2ap_CauseServiceLayer (const char* name, const e2ap_CauseServiceLayer* pvalue);
EXTERN int asn1PrtToStr_e2ap_CauseServiceLayer (const char* name, e2ap_CauseServiceLayer* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_CauseServiceLayer (OSCTXT* pctxt, const char* name, const e2ap_CauseServiceLayer* pvalue);
EXTERN int asn1Copy_e2ap_CauseServiceLayer (OSCTXT* pctxt, const e2ap_CauseServiceLayer* pSrcValue, e2ap_CauseServiceLayer* pDstValue);
// --- End of e2ap_CauseServiceLayer.h ---

// --- Begin of e2ap_Cause.h ---


/*****************************************/
/*           Cause                */
/*****************************************/
// choice

#define T_e2ap_Cause_ricRequest  1
#define T_e2ap_Cause_ricService  2
#define T_e2ap_Cause_e2Node  3
#define T_e2ap_Cause_transport  4
#define T_e2ap_Cause_protocol  5
#define T_e2ap_Cause_misc  6
#define T_e2ap_Cause_serviceLayer  7
#define T_e2ap_Cause_extElem1 8

typedef struct e2ap_Cause {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      e2ap_CauseRICrequest *ricRequest;
      /* t =  2 */
      e2ap_CauseRICservice *ricService;
      /* t =  3 */
      e2ap_CauseE2node *e2Node;
      /* t =  4 */
      e2ap_CauseTransport *transport;
      /* t =  5 */
      e2ap_CauseProtocol *protocol;
      /* t =  6 */
      e2ap_CauseMisc *misc;
      /* t =  7 */
      e2ap_CauseServiceLayer *serviceLayer;
      /* t = 8*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_Cause;

EXTERN int asn1PE_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue);
EXTERN int asn1PD_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue);
EXTERN void asn1Print_e2ap_Cause (const char* name, const e2ap_Cause* pvalue);
EXTERN int asn1PrtToStr_e2ap_Cause (const char* name, e2ap_Cause* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_Cause (OSCTXT* pctxt, const char* name, const e2ap_Cause* pvalue);
EXTERN int asn1Copy_e2ap_Cause (OSCTXT* pctxt, const e2ap_Cause* pSrcValue, e2ap_Cause* pDstValue);
EXTERN int asn1Init_e2ap_Cause (e2ap_Cause* pvalue);
EXTERN void asn1Free_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue);

// --- End of e2ap_Cause.h ---

// --- Begin of e2ap_RANfunctionIDcause_Item.h ---
/*****************************************/
/*           RANfunctionIDcause_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RANfunctionIDcause_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_Cause cause;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RANfunctionIDcause_Item;

EXTERN int asn1PE_e2ap_RANfunctionIDcause_Item (OSCTXT* pctxt, e2ap_RANfunctionIDcause_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionIDcause_Item (OSCTXT* pctxt, e2ap_RANfunctionIDcause_Item* pvalue);
EXTERN int asn1Init_e2ap_RANfunctionIDcause_Item (e2ap_RANfunctionIDcause_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionIDcause_Item (OSCTXT* pctxt, e2ap_RANfunctionIDcause_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionIDcause_Item (const char* name, const e2ap_RANfunctionIDcause_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionIDcause_Item (const char* name, e2ap_RANfunctionIDcause_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionIDcause_Item (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionIDcause_Item* pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionIDcause_Item (OSCTXT* pctxt, const e2ap_RANfunctionIDcause_Item* pSrcValue, e2ap_RANfunctionIDcause_Item* pDstValue);
// --- End of e2ap_RANfunctionIDcause_Item.h ---

// --- Begin of e2ap_RANfunctionIDcause_ItemIEs.h ---
/* e2ap_RANfunctionIDcause_ItemIEs.h */

/*****************************************/
/*           RANfunctionIDcause_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RANfunctionIDcause_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RANfunctionIDcause_ItemIEs_RANfunctionIDcause_Item   
   

} e2ap_RANfunctionIDcause_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RANfunctionIDcause_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RANfunctionIDcause_ItemIEs_TVALUE t;
      union {
         e2ap_RANfunctionIDcause_Item * _e2apRANfunctionIDcause_ItemIEs_RANfunctionIDcause_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RANfunctionIDcause_ItemIEs;

EXTERN int  asn1PE_e2ap_RANfunctionIDcause_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionIDcause_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RANfunctionIDcause_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionIDcause_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RANfunctionIDcause_ItemIEs (e2ap_RANfunctionIDcause_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionIDcause_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionIDcause_ItemIEs* pvalue);

// --- End of e2ap_RANfunctionIDcause_ItemIEs.h ---

// --- Begin of e2ap_RANfunctionsIDcause_List.h ---
/*****************************************/
/*           RANfunctionsIDcause_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RANfunctionsIDcause_List;

EXTERN int asn1PE_e2ap_RANfunctionsIDcause_List (OSCTXT* pctxt, e2ap_RANfunctionsIDcause_List* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionsIDcause_List (OSCTXT* pctxt, e2ap_RANfunctionsIDcause_List* ppvalue);
EXTERN void asn1Init_e2ap_RANfunctionsIDcause_List (e2ap_RANfunctionsIDcause_List* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionsIDcause_List (OSCTXT* pctxt, e2ap_RANfunctionsIDcause_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionsIDcause_List (const char* name, e2ap_RANfunctionsIDcause_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RANfunctionsIDcause_List (OSCTXT* pctxt, const e2ap_RANfunctionsIDcause_List* pSrcValue, e2ap_RANfunctionsIDcause_List* pDstValue);
EXTERN void asn1Print_e2ap_RANfunctionsIDcause_List (const char *name, const e2ap_RANfunctionsIDcause_List* pvalue);
// --- End of e2ap_RANfunctionsIDcause_List.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceType.h ---
/******************************************************/
/*                                                    */
/*    E2nodeComponentInterfaceType                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_ng = 0,
    e2ap_xn = 1,
    e2ap_e1 = 2,
    e2ap_f1 = 3,
    e2ap_w1 = 4,
    e2ap_s1 = 5,
    e2ap_x2 = 6
} e2ap_E2nodeComponentInterfaceType_Root;

typedef OSUINT32 e2ap_E2nodeComponentInterfaceType;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceType value);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceType* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceType (const char* name, const e2ap_E2nodeComponentInterfaceType* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceType* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceType (const char* name,const e2ap_E2nodeComponentInterfaceType* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_E2nodeComponentInterfaceType_ENUMTAB[];
#define e2ap_E2nodeComponentInterfaceType_ENUMTABSIZE 7

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_E2nodeComponentInterfaceType_ToString (OSUINT32 value);
EXTERN int e2ap_E2nodeComponentInterfaceType_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_E2nodeComponentInterfaceType* pvalue);
EXTERN int e2ap_E2nodeComponentInterfaceType_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_E2nodeComponentInterfaceType* pvalue);
// --- End of e2ap_E2nodeComponentInterfaceType.h ---

/*******************************************/
/* File .h missing: e2ap_PrintableString.h */
/*******************************************/

// --- Begin of e2ap_AMFName.h ---
/* e2ap_AMFName.h */

//printable string
/*****************************************/
/*           AMFName                */
/*****************************************/


typedef const char* e2ap_AMFName;

EXTERN int asn1PE_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName value);
EXTERN int asn1PD_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName* ppvalue);
EXTERN void asn1Print_e2ap_AMFName (const char* name, e2ap_AMFName pvalue);
EXTERN int asn1PrtToStr_e2ap_AMFName (const char* name, e2ap_AMFName pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_AMFName (OSCTXT* pctxt, const char* name, e2ap_AMFName pvalue);
EXTERN int asn1Copy_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName pSrcValue, e2ap_AMFName* pDstValue);
EXTERN void asn1Free_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName pvalue);
// --- End of e2ap_AMFName.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceNG.h ---
/*****************************************/
/*           E2nodeComponentInterfaceNG                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceNG {
   e2ap_AMFName amf_name;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceNG;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceNG (e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceNG (const char* name, const e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceNG (const char* name, e2ap_E2nodeComponentInterfaceNG* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceNG* pSrcValue, e2ap_E2nodeComponentInterfaceNG* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceNG.h ---

/**********************************/
/* File .h missing: e2ap_gnb_ID.h */
/**********************************/

// --- Begin of e2ap_GNB_ID_Choice.h ---


/*****************************************/
/*           GNB-ID-Choice                */
/*****************************************/
// choice

#define T_e2ap_GNB_ID_Choice_gnb_ID  1
#define T_e2ap_GNB_ID_Choice_extElem1 2

typedef struct e2ap_GNB_ID_Choice {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      ASN1BitStr32 *gnb_ID;
      /* t = 2*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_GNB_ID_Choice;

EXTERN int asn1PE_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue);
EXTERN int asn1PD_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue);
EXTERN void asn1Print_e2ap_GNB_ID_Choice (const char* name, const e2ap_GNB_ID_Choice* pvalue);
EXTERN int asn1PrtToStr_e2ap_GNB_ID_Choice (const char* name, e2ap_GNB_ID_Choice* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GNB_ID_Choice (OSCTXT* pctxt, const char* name, const e2ap_GNB_ID_Choice* pvalue);
EXTERN int asn1Copy_e2ap_GNB_ID_Choice (OSCTXT* pctxt, const e2ap_GNB_ID_Choice* pSrcValue, e2ap_GNB_ID_Choice* pDstValue);
EXTERN int asn1Init_e2ap_GNB_ID_Choice (e2ap_GNB_ID_Choice* pvalue);
EXTERN void asn1Free_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue);

// --- End of e2ap_GNB_ID_Choice.h ---

// --- Begin of e2ap_GlobalgNB_ID.h ---
/*****************************************/
/*           GlobalgNB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalgNB_ID {
   e2ap_PLMN_Identity plmn_id;
   e2ap_GNB_ID_Choice gnb_id;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalgNB_ID;

EXTERN int asn1PE_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalgNB_ID (e2ap_GlobalgNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalgNB_ID (const char* name, const e2ap_GlobalgNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalgNB_ID (const char* name, e2ap_GlobalgNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalgNB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalgNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalgNB_ID (OSCTXT* pctxt, const e2ap_GlobalgNB_ID* pSrcValue, e2ap_GlobalgNB_ID* pDstValue);
// --- End of e2ap_GlobalgNB_ID.h ---

/****************************************/
/* File .h missing: e2ap_enb_ID_macro.h */
/****************************************/

/*********************************************/
/* File .h missing: e2ap_enb_ID_shortmacro.h */
/*********************************************/

/********************************************/
/* File .h missing: e2ap_enb_ID_longmacro.h */
/********************************************/

// --- Begin of e2ap_ENB_ID_Choice.h ---


/*****************************************/
/*           ENB-ID-Choice                */
/*****************************************/
// choice

#define T_e2ap_ENB_ID_Choice_enb_ID_macro  1
#define T_e2ap_ENB_ID_Choice_enb_ID_shortmacro  2
#define T_e2ap_ENB_ID_Choice_enb_ID_longmacro  3
#define T_e2ap_ENB_ID_Choice_extElem1 4

typedef struct e2ap_ENB_ID_Choice {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      ASN1BitStr32 *enb_ID_macro;
      /* t =  2 */
      ASN1BitStr32 *enb_ID_shortmacro;
      /* t =  3 */
      ASN1BitStr32 *enb_ID_longmacro;
      /* t = 4*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_ENB_ID_Choice;

EXTERN int asn1PE_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue);
EXTERN int asn1PD_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue);
EXTERN void asn1Print_e2ap_ENB_ID_Choice (const char* name, const e2ap_ENB_ID_Choice* pvalue);
EXTERN int asn1PrtToStr_e2ap_ENB_ID_Choice (const char* name, e2ap_ENB_ID_Choice* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_ENB_ID_Choice (OSCTXT* pctxt, const char* name, const e2ap_ENB_ID_Choice* pvalue);
EXTERN int asn1Copy_e2ap_ENB_ID_Choice (OSCTXT* pctxt, const e2ap_ENB_ID_Choice* pSrcValue, e2ap_ENB_ID_Choice* pDstValue);
EXTERN int asn1Init_e2ap_ENB_ID_Choice (e2ap_ENB_ID_Choice* pvalue);
EXTERN void asn1Free_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue);

// --- End of e2ap_ENB_ID_Choice.h ---

// --- Begin of e2ap_GlobalngeNB_ID.h ---
/*****************************************/
/*           GlobalngeNB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalngeNB_ID {
   e2ap_PLMN_Identity plmn_id;
   e2ap_ENB_ID_Choice enb_id;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalngeNB_ID;

EXTERN int asn1PE_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalngeNB_ID (e2ap_GlobalngeNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalngeNB_ID (const char* name, const e2ap_GlobalngeNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalngeNB_ID (const char* name, e2ap_GlobalngeNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalngeNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, const e2ap_GlobalngeNB_ID* pSrcValue, e2ap_GlobalngeNB_ID* pDstValue);
// --- End of e2ap_GlobalngeNB_ID.h ---

// --- Begin of e2ap_GlobalNG_RANNode_ID.h ---


/*****************************************/
/*           GlobalNG-RANNode-ID                */
/*****************************************/
// choice

#define T_e2ap_GlobalNG_RANNode_ID_gNB  1
#define T_e2ap_GlobalNG_RANNode_ID_ng_eNB  2
#define T_e2ap_GlobalNG_RANNode_ID_extElem1 3

typedef struct e2ap_GlobalNG_RANNode_ID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      e2ap_GlobalgNB_ID *gNB;
      /* t =  2 */
      e2ap_GlobalngeNB_ID *ng_eNB;
      /* t = 3*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_GlobalNG_RANNode_ID;

EXTERN int asn1PE_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalNG_RANNode_ID (const char* name, const e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalNG_RANNode_ID (const char* name, e2ap_GlobalNG_RANNode_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, const e2ap_GlobalNG_RANNode_ID* pSrcValue, e2ap_GlobalNG_RANNode_ID* pDstValue);
EXTERN int asn1Init_e2ap_GlobalNG_RANNode_ID (e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue);

// --- End of e2ap_GlobalNG_RANNode_ID.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceXn.h ---
/*****************************************/
/*           E2nodeComponentInterfaceXn                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceXn {
   e2ap_GlobalNG_RANNode_ID global_NG_RAN_Node_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceXn;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceXn (e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceXn (const char* name, const e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceXn (const char* name, e2ap_E2nodeComponentInterfaceXn* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceXn* pSrcValue, e2ap_E2nodeComponentInterfaceXn* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceXn.h ---

// --- Begin of e2ap_GNB_CU_UP_ID.h ---
/*****************************************/
/*        GNB-CU-UP-ID         */
/*****************************************/
//interger no ext


typedef OSUINT64 e2ap_GNB_CU_UP_ID;

EXTERN int asn1PE_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID value);
EXTERN int asn1PD_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID* pvalue);
EXTERN void asn1Print_e2ap_GNB_CU_UP_ID (const char* name, const e2ap_GNB_CU_UP_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GNB_CU_UP_ID (const char* name, e2ap_GNB_CU_UP_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, const char* name, const e2ap_GNB_CU_UP_ID* pvalue);
// --- End of e2ap_GNB_CU_UP_ID.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceE1.h ---
/*****************************************/
/*           E2nodeComponentInterfaceE1                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceE1 {
   e2ap_GNB_CU_UP_ID gNB_CU_UP_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceE1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceE1 (e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceE1 (const char* name, const e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceE1 (const char* name, e2ap_E2nodeComponentInterfaceE1* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceE1* pSrcValue, e2ap_E2nodeComponentInterfaceE1* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceE1.h ---

// --- Begin of e2ap_GNB_DU_ID.h ---
/*****************************************/
/*        GNB-DU-ID         */
/*****************************************/
//interger no ext


typedef OSUINT64 e2ap_GNB_DU_ID;

EXTERN int asn1PE_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID value);
EXTERN int asn1PD_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID* pvalue);
EXTERN void asn1Print_e2ap_GNB_DU_ID (const char* name, const e2ap_GNB_DU_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GNB_DU_ID (const char* name, e2ap_GNB_DU_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GNB_DU_ID (OSCTXT* pctxt, const char* name, const e2ap_GNB_DU_ID* pvalue);
// --- End of e2ap_GNB_DU_ID.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceF1.h ---
/*****************************************/
/*           E2nodeComponentInterfaceF1                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceF1 {
   e2ap_GNB_DU_ID gNB_DU_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceF1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceF1 (e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceF1 (const char* name, const e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceF1 (const char* name, e2ap_E2nodeComponentInterfaceF1* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceF1* pSrcValue, e2ap_E2nodeComponentInterfaceF1* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceF1.h ---

// --- Begin of e2ap_NGENB_DU_ID.h ---
/*****************************************/
/*        NGENB-DU-ID         */
/*****************************************/
//interger no ext


typedef OSUINT64 e2ap_NGENB_DU_ID;

EXTERN int asn1PE_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID value);
EXTERN int asn1PD_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID* pvalue);
EXTERN void asn1Print_e2ap_NGENB_DU_ID (const char* name, const e2ap_NGENB_DU_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_NGENB_DU_ID (const char* name, e2ap_NGENB_DU_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_NGENB_DU_ID (OSCTXT* pctxt, const char* name, const e2ap_NGENB_DU_ID* pvalue);
// --- End of e2ap_NGENB_DU_ID.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceW1.h ---
/*****************************************/
/*           E2nodeComponentInterfaceW1                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceW1 {
   e2ap_NGENB_DU_ID ng_eNB_DU_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceW1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceW1 (e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceW1 (const char* name, const e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceW1 (const char* name, e2ap_E2nodeComponentInterfaceW1* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceW1* pSrcValue, e2ap_E2nodeComponentInterfaceW1* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceW1.h ---

/***********************************/
/* File .h missing: e2ap_MMEname.h */
/***********************************/

// --- Begin of e2ap_E2nodeComponentInterfaceS1.h ---
/*****************************************/
/*           E2nodeComponentInterfaceS1                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceS1 {
   e2ap_MMEname mme_name;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceS1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceS1 (e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceS1 (const char* name, const e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceS1 (const char* name, e2ap_E2nodeComponentInterfaceS1* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceS1* pSrcValue, e2ap_E2nodeComponentInterfaceS1* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceS1.h ---

/****************************************/
/* File .h missing: e2ap_macro_eNB_ID.h */
/****************************************/

/***************************************/
/* File .h missing: e2ap_home_eNB_ID.h */
/***************************************/

/**********************************************/
/* File .h missing: e2ap_short_Macro_eNB_ID.h */
/**********************************************/

/*********************************************/
/* File .h missing: e2ap_long_Macro_eNB_ID.h */
/*********************************************/

// --- Begin of e2ap_ENB_ID.h ---


/*****************************************/
/*           ENB-ID                */
/*****************************************/
// choice

#define T_e2ap_ENB_ID_macro_eNB_ID  1
#define T_e2ap_ENB_ID_home_eNB_ID  2
#define T_e2ap_ENB_ID_short_Macro_eNB_ID  3
#define T_e2ap_ENB_ID_long_Macro_eNB_ID  4
#define T_e2ap_ENB_ID_extElem1 5

typedef struct e2ap_ENB_ID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      ASN1BitStr32 *macro_eNB_ID;
      /* t =  2 */
      ASN1BitStr32 *home_eNB_ID;
      /* t =  3 */
      ASN1BitStr32 *short_Macro_eNB_ID;
      /* t =  4 */
      ASN1BitStr32 *long_Macro_eNB_ID;
      /* t = 5*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_ENB_ID;

EXTERN int asn1PE_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);
EXTERN int asn1PD_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);
EXTERN void asn1Print_e2ap_ENB_ID (const char* name, const e2ap_ENB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_ENB_ID (const char* name, e2ap_ENB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_ENB_ID (OSCTXT* pctxt, const char* name, const e2ap_ENB_ID* pvalue);
EXTERN int asn1Copy_e2ap_ENB_ID (OSCTXT* pctxt, const e2ap_ENB_ID* pSrcValue, e2ap_ENB_ID* pDstValue);
EXTERN int asn1Init_e2ap_ENB_ID (e2ap_ENB_ID* pvalue);
EXTERN void asn1Free_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);

// --- End of e2ap_ENB_ID.h ---

// --- Begin of e2ap_GlobalENB_ID.h ---
/*****************************************/
/*           GlobalENB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalENB_ID {
   e2ap_PLMN_Identity pLMN_Identity;
   e2ap_ENB_ID eNB_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalENB_ID;

EXTERN int asn1PE_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalENB_ID (e2ap_GlobalENB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalENB_ID (const char* name, const e2ap_GlobalENB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalENB_ID (const char* name, e2ap_GlobalENB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalENB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalENB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalENB_ID (OSCTXT* pctxt, const e2ap_GlobalENB_ID* pSrcValue, e2ap_GlobalENB_ID* pDstValue);
// --- End of e2ap_GlobalENB_ID.h ---

/**********************************/
/* File .h missing: e2ap_gNB_ID.h */
/**********************************/

// --- Begin of e2ap_ENGNB_ID.h ---


/*****************************************/
/*           ENGNB-ID                */
/*****************************************/
// choice

#define T_e2ap_ENGNB_ID_gNB_ID  1
#define T_e2ap_ENGNB_ID_extElem1 2

typedef struct e2ap_ENGNB_ID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      ASN1BitStr32 *gNB_ID;
      /* t = 2*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_ENGNB_ID;

EXTERN int asn1PE_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue);
EXTERN int asn1PD_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue);
EXTERN void asn1Print_e2ap_ENGNB_ID (const char* name, const e2ap_ENGNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_ENGNB_ID (const char* name, e2ap_ENGNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_ENGNB_ID (OSCTXT* pctxt, const char* name, const e2ap_ENGNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_ENGNB_ID (OSCTXT* pctxt, const e2ap_ENGNB_ID* pSrcValue, e2ap_ENGNB_ID* pDstValue);
EXTERN int asn1Init_e2ap_ENGNB_ID (e2ap_ENGNB_ID* pvalue);
EXTERN void asn1Free_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue);

// --- End of e2ap_ENGNB_ID.h ---

// --- Begin of e2ap_GlobalenGNB_ID.h ---
/*****************************************/
/*           GlobalenGNB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalenGNB_ID {
   e2ap_PLMN_Identity pLMN_Identity;
   e2ap_ENGNB_ID gNB_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalenGNB_ID;

EXTERN int asn1PE_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalenGNB_ID (e2ap_GlobalenGNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalenGNB_ID (const char* name, const e2ap_GlobalenGNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalenGNB_ID (const char* name, e2ap_GlobalenGNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalenGNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, const e2ap_GlobalenGNB_ID* pSrcValue, e2ap_GlobalenGNB_ID* pDstValue);
// --- End of e2ap_GlobalenGNB_ID.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceX2.h ---
/*****************************************/
/*           E2nodeComponentInterfaceX2                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceX2 {
   e2ap_GlobalENB_ID global_eNB_ID;
     OSBOOL m_global_eNB_IDPresent;   e2ap_GlobalenGNB_ID global_en_gNB_ID;
     OSBOOL m_global_en_gNB_IDPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceX2;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceX2 (e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceX2 (const char* name, const e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceX2 (const char* name, e2ap_E2nodeComponentInterfaceX2* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceX2* pSrcValue, e2ap_E2nodeComponentInterfaceX2* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceX2.h ---

// --- Begin of e2ap_E2nodeComponentID.h ---


/*****************************************/
/*           E2nodeComponentID                */
/*****************************************/
// choice

#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeNG  1
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeXn  2
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeE1  3
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeF1  4
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeW1  5
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeS1  6
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeX2  7
#define T_e2ap_E2nodeComponentID_extElem1 8

typedef struct e2ap_E2nodeComponentID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      e2ap_E2nodeComponentInterfaceNG *e2nodeComponentInterfaceTypeNG;
      /* t =  2 */
      e2ap_E2nodeComponentInterfaceXn *e2nodeComponentInterfaceTypeXn;
      /* t =  3 */
      e2ap_E2nodeComponentInterfaceE1 *e2nodeComponentInterfaceTypeE1;
      /* t =  4 */
      e2ap_E2nodeComponentInterfaceF1 *e2nodeComponentInterfaceTypeF1;
      /* t =  5 */
      e2ap_E2nodeComponentInterfaceW1 *e2nodeComponentInterfaceTypeW1;
      /* t =  6 */
      e2ap_E2nodeComponentInterfaceS1 *e2nodeComponentInterfaceTypeS1;
      /* t =  7 */
      e2ap_E2nodeComponentInterfaceX2 *e2nodeComponentInterfaceTypeX2;
      /* t = 8*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_E2nodeComponentID;

EXTERN int asn1PE_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentID (const char* name, const e2ap_E2nodeComponentID* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentID (const char* name, e2ap_E2nodeComponentID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentID (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentID* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentID (OSCTXT* pctxt, const e2ap_E2nodeComponentID* pSrcValue, e2ap_E2nodeComponentID* pDstValue);
EXTERN int asn1Init_e2ap_E2nodeComponentID (e2ap_E2nodeComponentID* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue);

// --- End of e2ap_E2nodeComponentID.h ---

/*****************************************/
/* File .h missing: e2ap_updateOutcome.h */
/*****************************************/

// --- Begin of e2ap_E2nodeComponentConfigurationAck.h ---
/*****************************************/
/*           E2nodeComponentConfigurationAck                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentConfigurationAck {
   e2ap_updateOutcome updateOutcome;
   e2ap_failure failure;
   e2ap_Cause failureCause;
     OSBOOL m_failureCausePresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentConfigurationAck;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentConfigurationAck (e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigurationAck (const char* name, const e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentConfigurationAck (const char* name, e2ap_E2nodeComponentConfigurationAck* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, const e2ap_E2nodeComponentConfigurationAck* pSrcValue, e2ap_E2nodeComponentConfigurationAck* pDstValue);
// --- End of e2ap_E2nodeComponentConfigurationAck.h ---

// --- Begin of e2ap_E2nodeComponentConfigAdditionAck_Item.h ---
/*****************************************/
/*           E2nodeComponentConfigAdditionAck_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentConfigAdditionAck_Item {
   e2ap_E2nodeComponentInterfaceType e2nodeComponentInterfaceType;
   e2ap_E2nodeComponentID e2nodeComponentID;
   e2ap_E2nodeComponentConfigurationAck e2nodeComponentConfigurationAck;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentConfigAdditionAck_Item;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentConfigAdditionAck_Item (e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigAdditionAck_Item (const char* name, const e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentConfigAdditionAck_Item (const char* name, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, const e2ap_E2nodeComponentConfigAdditionAck_Item* pSrcValue, e2ap_E2nodeComponentConfigAdditionAck_Item* pDstValue);
// --- End of e2ap_E2nodeComponentConfigAdditionAck_Item.h ---

// --- Begin of e2ap_E2nodeComponentConfigAdditionAck_ItemIEs.h ---
/* e2ap_E2nodeComponentConfigAdditionAck_ItemIEs.h */

/*****************************************/
/*           E2nodeComponentConfigAdditionAck_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigAdditionAck_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_E2nodeComponentConfigAdditionAck_ItemIEs_E2nodeComponentConfigAdditionAck_Item   
   

} e2ap_E2nodeComponentConfigAdditionAck_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2nodeComponentConfigAdditionAck_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2nodeComponentConfigAdditionAck_ItemIEs_TVALUE t;
      union {
         e2ap_E2nodeComponentConfigAdditionAck_Item * _e2apE2nodeComponentConfigAdditionAck_ItemIEs_E2nodeComponentConfigAdditionAck_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2nodeComponentConfigAdditionAck_ItemIEs;

EXTERN int  asn1PE_e2ap_E2nodeComponentConfigAdditionAck_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_E2nodeComponentConfigAdditionAck_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigAdditionAck_ItemIEs (e2ap_E2nodeComponentConfigAdditionAck_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAdditionAck_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_ItemIEs* pvalue);

// --- End of e2ap_E2nodeComponentConfigAdditionAck_ItemIEs.h ---

// --- Begin of e2ap_E2nodeComponentConfigAdditionAck_List.h ---
/*****************************************/
/*           E2nodeComponentConfigAdditionAck_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_E2nodeComponentConfigAdditionAck_List;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigAdditionAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_List* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigAdditionAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_List* ppvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigAdditionAck_List (e2ap_E2nodeComponentConfigAdditionAck_List* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAdditionAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentConfigAdditionAck_List (const char* name, e2ap_E2nodeComponentConfigAdditionAck_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_E2nodeComponentConfigAdditionAck_List (OSCTXT* pctxt, const e2ap_E2nodeComponentConfigAdditionAck_List* pSrcValue, e2ap_E2nodeComponentConfigAdditionAck_List* pDstValue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigAdditionAck_List (const char *name, const e2ap_E2nodeComponentConfigAdditionAck_List* pvalue);
// --- End of e2ap_E2nodeComponentConfigAdditionAck_List.h ---

/**********************************************/
/* File .h missing: e2ap_E2setupResponseIEs.h */
/**********************************************/

// --- Begin of e2ap_E2setupResponse.h ---
/*****************************************/
/*           E2setupResponse                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2setupResponse {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2setupResponse;

EXTERN int asn1PE_e2ap_E2setupResponse (OSCTXT* pctxt, e2ap_E2setupResponse* pvalue);
EXTERN int asn1PD_e2ap_E2setupResponse (OSCTXT* pctxt, e2ap_E2setupResponse* pvalue);
EXTERN int asn1Init_e2ap_E2setupResponse (e2ap_E2setupResponse* pvalue);
EXTERN void asn1Free_e2ap_E2setupResponse (OSCTXT* pctxt, e2ap_E2setupResponse* pvalue);
EXTERN void asn1Print_e2ap_E2setupResponse (const char* name, const e2ap_E2setupResponse* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2setupResponse (const char* name, e2ap_E2setupResponse* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2setupResponse (OSCTXT* pctxt, const char* name, const e2ap_E2setupResponse* pvalue);
EXTERN int asn1Copy_e2ap_E2setupResponse (OSCTXT* pctxt, const e2ap_E2setupResponse* pSrcValue, e2ap_E2setupResponse* pDstValue);
// --- End of e2ap_E2setupResponse.h ---

// --- Begin of e2ap_E2setupResponse_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    E2setupResponse_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from E2setupResponse*/

typedef OSRTDList e2ap_E2setupResponse_protocolIEs;

EXTERN int asn1PE_e2ap_E2setupResponse_protocolIEs (OSCTXT* pctxt, e2ap_E2setupResponse_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_E2setupResponse_protocolIEs (OSCTXT* pctxt, e2ap_E2setupResponse_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_E2setupResponse_protocolIEs (e2ap_E2setupResponse_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_E2setupResponse_protocolIEs (OSCTXT* pctxt, e2ap_E2setupResponse_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2setupResponse_protocolIEs (OSCTXT* pctxt, e2ap_E2setupResponse_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apE2setupResponse_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_E2setupResponse_protocolIEs* pvalue);
// --- End of e2ap_E2setupResponse_protocolIEs.h ---

// --- Begin of e2ap_E2setupResponse_protocolIEs_element.h ---
/*****************************************/
/*    E2setupResponse_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from E2setupResponse*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2setupResponseIEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2setupResponseIEs_id_TransactionID,

   T_E2AP_PDU_Contents_e2ap_E2setupResponseIEs_id_GlobalRIC_ID,

   T_E2AP_PDU_Contents_e2ap_E2setupResponseIEs_id_RANfunctionsAccepted,

   T_E2AP_PDU_Contents_e2ap_E2setupResponseIEs_id_RANfunctionsRejected,

   T_E2AP_PDU_Contents_e2ap_E2setupResponseIEs_id_E2nodeComponentConfigAdditionAck,

   T_E2AP_PDU_Contents_e2ap_E2setupResponseIEs_id_Extended_RANNodeName_

}e2ap_E2setupResponseIEs_TVALUE;


typedef struct EXTERN e2ap_E2setupResponse_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2setupResponseIEs_TVALUE t;
      union {
        /*
        *id: id-TransactionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_TransactionID *_e2ap_E2setupResponseIEs_id_TransactionID;


        /*
        *id: id-GlobalRIC-ID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_GlobalRIC_ID *_e2ap_E2setupResponseIEs_id_GlobalRIC_ID;


        /*
        *id: id-RANfunctionsID-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RANfunctionsID_List *_e2ap_E2setupResponseIEs_id_RANfunctionsAccepted;


        /*
        *id: id-RANfunctionsIDcause-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RANfunctionsIDcause_List *_e2ap_E2setupResponseIEs_id_RANfunctionsRejected;


        /*
        *id: id-E2nodeComponentConfigAdditionAck-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_E2nodeComponentConfigAdditionAck_List *_e2ap_E2setupResponseIEs_id_E2nodeComponentConfigAdditionAck;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_E2setupResponse_protocolIEs_element;


EXTERN int asn1PE_e2ap_E2setupResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupResponse_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_E2setupResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupResponse_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_E2setupResponse_protocolIEs_element (e2ap_E2setupResponse_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_E2setupResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupResponse_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2setupResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupResponse_protocolIEs_element* pvalue);
// --- End of e2ap_E2setupResponse_protocolIEs_element.h ---

#endif
