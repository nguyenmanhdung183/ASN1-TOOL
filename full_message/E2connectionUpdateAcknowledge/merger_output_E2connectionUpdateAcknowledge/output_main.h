
#ifndef OUTPUT_MAIN_H
#define OUTPUT_MAIN_H

// --- Begin of doc/header.h ---
//======================E2AP.h========================//
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

/**************************************/
/* File .h missing: e2ap_tnlAddress.h */
/**************************************/

/***********************************/
/* File .h missing: e2ap_tnlPort.h */
/***********************************/

// --- Begin of e2ap_TNLinformation.h ---
/*****************************************/
/*           TNLinformation                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_TNLinformation {
   ASN1BitStr32 tnlAddress;
   ASN1BitStr32 tnlPort;
     OSBOOL m_tnlPortPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_TNLinformation;

EXTERN int asn1PE_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue);
EXTERN int asn1PD_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue);
EXTERN int asn1Init_e2ap_TNLinformation (e2ap_TNLinformation* pvalue);
EXTERN void asn1Free_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue);
EXTERN void asn1Print_e2ap_TNLinformation (const char* name, const e2ap_TNLinformation* pvalue);
EXTERN int asn1PrtToStr_e2ap_TNLinformation (const char* name, e2ap_TNLinformation* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_TNLinformation (OSCTXT* pctxt, const char* name, const e2ap_TNLinformation* pvalue);
EXTERN int asn1Copy_e2ap_TNLinformation (OSCTXT* pctxt, const e2ap_TNLinformation* pSrcValue, e2ap_TNLinformation* pDstValue);
// --- End of e2ap_TNLinformation.h ---

// --- Begin of e2ap_TNLusage.h ---
/******************************************************/
/*                                                    */
/*    TNLusage                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_ric_service = 0,
    e2ap_support_function = 1,
    e2ap_both = 2
} e2ap_TNLusage_Root;

typedef OSUINT32 e2ap_TNLusage;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_TNLusage (OSCTXT* pctxt, e2ap_TNLusage value);
EXTERN int asn1PD_e2ap_TNLusage (OSCTXT* pctxt, e2ap_TNLusage* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_TNLusage (const char* name, const e2ap_TNLusage* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_TNLusage (OSCTXT* pctxt, const char* name, const e2ap_TNLusage* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_TNLusage (const char* name,const e2ap_TNLusage* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_TNLusage_ENUMTAB[];
#define e2ap_TNLusage_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_TNLusage_ToString (OSUINT32 value);
EXTERN int e2ap_TNLusage_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_TNLusage* pvalue);
EXTERN int e2ap_TNLusage_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_TNLusage* pvalue);
// --- End of e2ap_TNLusage.h ---

// --- Begin of e2ap_E2connectionUpdate_Item.h ---
/*****************************************/
/*           E2connectionUpdate_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2connectionUpdate_Item {
   e2ap_TNLinformation tnlInformation;
   e2ap_TNLusage tnlUsage;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2connectionUpdate_Item;

EXTERN int asn1PE_e2ap_E2connectionUpdate_Item (OSCTXT* pctxt, e2ap_E2connectionUpdate_Item* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdate_Item (OSCTXT* pctxt, e2ap_E2connectionUpdate_Item* pvalue);
EXTERN int asn1Init_e2ap_E2connectionUpdate_Item (e2ap_E2connectionUpdate_Item* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdate_Item (OSCTXT* pctxt, e2ap_E2connectionUpdate_Item* pvalue);
EXTERN void asn1Print_e2ap_E2connectionUpdate_Item (const char* name, const e2ap_E2connectionUpdate_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionUpdate_Item (const char* name, e2ap_E2connectionUpdate_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2connectionUpdate_Item (OSCTXT* pctxt, const char* name, const e2ap_E2connectionUpdate_Item* pvalue);
EXTERN int asn1Copy_e2ap_E2connectionUpdate_Item (OSCTXT* pctxt, const e2ap_E2connectionUpdate_Item* pSrcValue, e2ap_E2connectionUpdate_Item* pDstValue);
// --- End of e2ap_E2connectionUpdate_Item.h ---

// --- Begin of e2ap_E2connectionUpdate_ItemIEs.h ---
/* e2ap_E2connectionUpdate_ItemIEs.h */

/*****************************************/
/*           E2connectionUpdate_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_E2connectionUpdate_ItemIEs_E2connectionUpdate_Item   
   

} e2ap_E2connectionUpdate_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2connectionUpdate_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2connectionUpdate_ItemIEs_TVALUE t;
      union {
         e2ap_E2connectionUpdate-Item * _e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item

         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2connectionUpdate_ItemIEs;

EXTERN int  asn1PE_e2ap_E2connectionUpdate_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_E2connectionUpdate_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_E2connectionUpdate_ItemIEs (e2ap_E2connectionUpdate_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdate_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate_ItemIEs* pvalue);

// --- End of e2ap_E2connectionUpdate_ItemIEs.h ---

// --- Begin of e2ap_E2connectionUpdate_List.h ---
/*****************************************/
/*           E2connectionUpdate_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_E2connectionUpdate_List;

EXTERN int asn1PE_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List** ppvalue);
EXTERN void asn1Init_e2ap_E2connectionUpdate_List (e2ap_E2connectionUpdate_List* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List* pvalue);
// --- End of e2ap_E2connectionUpdate_List.h ---

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

// --- Begin of e2ap_E2connectionSetupFailed_Item.h ---
/*****************************************/
/*           E2connectionSetupFailed_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2connectionSetupFailed_Item {
   e2ap_TNLinformation tnlInformation;
   e2ap_Cause cause;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2connectionSetupFailed_Item;

EXTERN int asn1PE_e2ap_E2connectionSetupFailed_Item (OSCTXT* pctxt, e2ap_E2connectionSetupFailed_Item* pvalue);
EXTERN int asn1PD_e2ap_E2connectionSetupFailed_Item (OSCTXT* pctxt, e2ap_E2connectionSetupFailed_Item* pvalue);
EXTERN int asn1Init_e2ap_E2connectionSetupFailed_Item (e2ap_E2connectionSetupFailed_Item* pvalue);
EXTERN void asn1Free_e2ap_E2connectionSetupFailed_Item (OSCTXT* pctxt, e2ap_E2connectionSetupFailed_Item* pvalue);
EXTERN void asn1Print_e2ap_E2connectionSetupFailed_Item (const char* name, const e2ap_E2connectionSetupFailed_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionSetupFailed_Item (const char* name, e2ap_E2connectionSetupFailed_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2connectionSetupFailed_Item (OSCTXT* pctxt, const char* name, const e2ap_E2connectionSetupFailed_Item* pvalue);
EXTERN int asn1Copy_e2ap_E2connectionSetupFailed_Item (OSCTXT* pctxt, const e2ap_E2connectionSetupFailed_Item* pSrcValue, e2ap_E2connectionSetupFailed_Item* pDstValue);
// --- End of e2ap_E2connectionSetupFailed_Item.h ---

// --- Begin of e2ap_E2connectionSetupFailed_ItemIEs.h ---
/* e2ap_E2connectionSetupFailed_ItemIEs.h */

/*****************************************/
/*           E2connectionSetupFailed_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_E2connectionSetupFailed_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_E2connectionSetupFailed_ItemIEs_E2connectionSetupFailed_Item   
   

} e2ap_E2connectionSetupFailed_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2connectionSetupFailed_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2connectionSetupFailed_ItemIEs_TVALUE t;
      union {
         e2ap_E2connectionSetupFailed-Item * _e2apE2connectionSetupFailed_ItemIEs_E2connectionSetupFailed_Item

         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2connectionSetupFailed_ItemIEs;

EXTERN int  asn1PE_e2ap_E2connectionSetupFailed_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionSetupFailed_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_E2connectionSetupFailed_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionSetupFailed_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_E2connectionSetupFailed_ItemIEs (e2ap_E2connectionSetupFailed_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_E2connectionSetupFailed_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionSetupFailed_ItemIEs* pvalue);

// --- End of e2ap_E2connectionSetupFailed_ItemIEs.h ---

// --- Begin of e2ap_E2connectionSetupFailed_List.h ---
/*****************************************/
/*           E2connectionSetupFailed_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_E2connectionSetupFailed_List;

EXTERN int asn1PE_e2ap_E2connectionSetupFailed_List (OSCTXT* pctxt, e2ap_E2connectionSetupFailed_List* pvalue);
EXTERN int asn1PD_e2ap_E2connectionSetupFailed_List (OSCTXT* pctxt, e2ap_E2connectionSetupFailed_List** ppvalue);
EXTERN void asn1Init_e2ap_E2connectionSetupFailed_List (e2ap_E2connectionSetupFailed_List* pvalue);
EXTERN void asn1Free_e2ap_E2connectionSetupFailed_List (OSCTXT* pctxt, e2ap_E2connectionSetupFailed_List* pvalue);
// --- End of e2ap_E2connectionSetupFailed_List.h ---

// --- Begin of e2ap_E2connectionUpdateAck_IEs.h ---
/* e2ap_E2connectionUpdateAck_IEs.h */

/*****************************************/
/*           E2connectionUpdateAck_IEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdateAck_IEs_UNDEF_,

   T_E2AP_PDU_Contents_E2connectionUpdateAck_IEs_TransactionID,   
   
   T_E2AP_PDU_Contents_E2connectionUpdateAck_IEs_E2connectionUpdate_List,   
   
   T_E2AP_PDU_Contents_E2connectionUpdateAck_IEs_E2connectionSetupFailed_List   
   

} e2ap_E2connectionUpdateAck_IEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2connectionUpdateAck_IEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2connectionUpdateAck_IEs_TVALUE t;
      union {
         e2ap_TransactionID * _e2apE2connectionUpdateAck_IEs_TransactionID,
         e2ap_E2connectionUpdate-List * _e2apE2connectionUpdateAck_IEs_E2connectionUpdate_List,
         e2ap_E2connectionSetupFailed-List * _e2apE2connectionUpdateAck_IEs_E2connectionSetupFailed_List

         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2connectionUpdateAck_IEs;

EXTERN int  asn1PE_e2ap_E2connectionUpdateAck_IEs (OSCTXT* pctxt, e2ap_E2connectionUpdateAck_IEs* pvalue);
EXTERN int  asn1PD_e2ap_E2connectionUpdateAck_IEs (OSCTXT* pctxt, e2ap_E2connectionUpdateAck_IEs* pvalue);
EXTERN void asn1Init_e2ap_E2connectionUpdateAck_IEs (e2ap_E2connectionUpdateAck_IEs* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdateAck_IEs (OSCTXT* pctxt, e2ap_E2connectionUpdateAck_IEs* pvalue);

// --- End of e2ap_E2connectionUpdateAck_IEs.h ---

// --- Begin of e2ap_E2connectionUpdateAcknowledge.h ---
/*****************************************/
/*           E2connectionUpdateAcknowledge                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2connectionUpdateAcknowledge {
   e2ap_ProtocolIE-Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2connectionUpdateAcknowledge;

EXTERN int asn1PE_e2ap_E2connectionUpdateAcknowledge (OSCTXT* pctxt, e2ap_E2connectionUpdateAcknowledge* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdateAcknowledge (OSCTXT* pctxt, e2ap_E2connectionUpdateAcknowledge* pvalue);
EXTERN int asn1Init_e2ap_E2connectionUpdateAcknowledge (e2ap_E2connectionUpdateAcknowledge* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdateAcknowledge (OSCTXT* pctxt, e2ap_E2connectionUpdateAcknowledge* pvalue);
EXTERN void asn1Print_e2ap_E2connectionUpdateAcknowledge (const char* name, const e2ap_E2connectionUpdateAcknowledge* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionUpdateAcknowledge (const char* name, e2ap_E2connectionUpdateAcknowledge* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2connectionUpdateAcknowledge (OSCTXT* pctxt, const char* name, const e2ap_E2connectionUpdateAcknowledge* pvalue);
EXTERN int asn1Copy_e2ap_E2connectionUpdateAcknowledge (OSCTXT* pctxt, const e2ap_E2connectionUpdateAcknowledge* pSrcValue, e2ap_E2connectionUpdateAcknowledge* pDstValue);
// --- End of e2ap_E2connectionUpdateAcknowledge.h ---

#endif
