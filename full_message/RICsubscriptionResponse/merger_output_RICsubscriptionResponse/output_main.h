
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

// --- Begin of e2ap_RICaction_NotAdmitted_Item.h ---
/*****************************************/
/*           RICaction_NotAdmitted_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICaction_NotAdmitted_Item {
   e2ap_RICactionID ricActionID;
   e2ap_Cause cause;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICaction_NotAdmitted_Item;

EXTERN int asn1PE_e2ap_RICaction_NotAdmitted_Item (OSCTXT* pctxt, e2ap_RICaction_NotAdmitted_Item* pvalue);
EXTERN int asn1PD_e2ap_RICaction_NotAdmitted_Item (OSCTXT* pctxt, e2ap_RICaction_NotAdmitted_Item* pvalue);
EXTERN int asn1Init_e2ap_RICaction_NotAdmitted_Item (e2ap_RICaction_NotAdmitted_Item* pvalue);
EXTERN void asn1Free_e2ap_RICaction_NotAdmitted_Item (OSCTXT* pctxt, e2ap_RICaction_NotAdmitted_Item* pvalue);
EXTERN void asn1Print_e2ap_RICaction_NotAdmitted_Item (const char* name, const e2ap_RICaction_NotAdmitted_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICaction_NotAdmitted_Item (const char* name, e2ap_RICaction_NotAdmitted_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICaction_NotAdmitted_Item (OSCTXT* pctxt, const char* name, const e2ap_RICaction_NotAdmitted_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICaction_NotAdmitted_Item (OSCTXT* pctxt, const e2ap_RICaction_NotAdmitted_Item* pSrcValue, e2ap_RICaction_NotAdmitted_Item* pDstValue);
// --- End of e2ap_RICaction_NotAdmitted_Item.h ---

// --- Begin of e2ap_RICaction_NotAdmitted_ItemIEs.h ---
/* e2ap_RICaction_NotAdmitted_ItemIEs.h */

/*****************************************/
/*           RICaction_NotAdmitted_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICaction_NotAdmitted_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICaction_NotAdmitted_ItemIEs_RICaction_NotAdmitted_Item   
   

} e2ap_RICaction_NotAdmitted_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICaction_NotAdmitted_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICaction_NotAdmitted_ItemIEs_TVALUE t;
      union {
         e2ap_RICaction_NotAdmitted_Item * _e2apRICaction_NotAdmitted_ItemIEs_RICaction_NotAdmitted_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICaction_NotAdmitted_ItemIEs;

EXTERN int  asn1PE_e2ap_RICaction_NotAdmitted_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_NotAdmitted_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICaction_NotAdmitted_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_NotAdmitted_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICaction_NotAdmitted_ItemIEs (e2ap_RICaction_NotAdmitted_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICaction_NotAdmitted_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_NotAdmitted_ItemIEs* pvalue);

// --- End of e2ap_RICaction_NotAdmitted_ItemIEs.h ---

// --- Begin of e2ap_RICaction_NotAdmitted_List.h ---
/*****************************************/
/*           RICaction_NotAdmitted_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICaction_NotAdmitted_List;

EXTERN int asn1PE_e2ap_RICaction_NotAdmitted_List (OSCTXT* pctxt, e2ap_RICaction_NotAdmitted_List* pvalue);
EXTERN int asn1PD_e2ap_RICaction_NotAdmitted_List (OSCTXT* pctxt, e2ap_RICaction_NotAdmitted_List* ppvalue);
EXTERN void asn1Init_e2ap_RICaction_NotAdmitted_List (e2ap_RICaction_NotAdmitted_List* pvalue);
EXTERN void asn1Free_e2ap_RICaction_NotAdmitted_List (OSCTXT* pctxt, e2ap_RICaction_NotAdmitted_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICaction_NotAdmitted_List (const char* name, e2ap_RICaction_NotAdmitted_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICaction_NotAdmitted_List (OSCTXT* pctxt, const e2ap_RICaction_NotAdmitted_List* pSrcValue, e2ap_RICaction_NotAdmitted_List* pDstValue);
EXTERN void asn1Print_e2ap_RICaction_NotAdmitted_List (const char *name, const e2ap_RICaction_NotAdmitted_List* pvalue);
// --- End of e2ap_RICaction_NotAdmitted_List.h ---

/*******************************************************/
/* File .h missing: e2ap_RICsubscriptionResponse_IEs.h */
/*******************************************************/

// --- Begin of e2ap_RICsubscriptionResponse.h ---
/*****************************************/
/*           RICsubscriptionResponse                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionResponse {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionResponse;

EXTERN int asn1PE_e2ap_RICsubscriptionResponse (OSCTXT* pctxt, e2ap_RICsubscriptionResponse* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionResponse (OSCTXT* pctxt, e2ap_RICsubscriptionResponse* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionResponse (e2ap_RICsubscriptionResponse* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionResponse (OSCTXT* pctxt, e2ap_RICsubscriptionResponse* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionResponse (const char* name, const e2ap_RICsubscriptionResponse* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionResponse (const char* name, e2ap_RICsubscriptionResponse* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionResponse (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionResponse* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionResponse (OSCTXT* pctxt, const e2ap_RICsubscriptionResponse* pSrcValue, e2ap_RICsubscriptionResponse* pDstValue);
// --- End of e2ap_RICsubscriptionResponse.h ---

// --- Begin of e2ap_RICsubscriptionResponse_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICsubscriptionResponse_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICsubscriptionResponse*/

typedef OSRTDList e2ap_RICsubscriptionResponse_protocolIEs;

EXTERN int asn1PE_e2ap_RICsubscriptionResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionResponse_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionResponse_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionResponse_protocolIEs (e2ap_RICsubscriptionResponse_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionResponse_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionResponse_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICsubscriptionResponse_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICsubscriptionResponse_protocolIEs* pvalue);
// --- End of e2ap_RICsubscriptionResponse_protocolIEs.h ---

// --- Begin of e2ap_RICsubscriptionResponse_protocolIEs_element.h ---
/*****************************************/
/*    RICsubscriptionResponse_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICsubscriptionResponse*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionResponse_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionResponse_IEs_id_RICrequestID,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionResponse_IEs_id_RANfunctionID,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionResponse_IEs_id_RICactions_Admitted,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionResponse_IEs_id_RICactions_NotAdmitted,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionResponse_IEs_id_Extended_RANNodeName_

}e2ap_RICsubscriptionResponse_IEs_TVALUE;


typedef struct EXTERN e2ap_RICsubscriptionResponse_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionResponse_IEs_TVALUE t;
      union {
        /*
        *id: id-RICrequestID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICrequestID *_e2ap_RICsubscriptionResponse_IEs_id_RICrequestID;


        /*
        *id: id-RANfunctionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctionID *_e2ap_RICsubscriptionResponse_IEs_id_RANfunctionID;


        /*
        *id: id-RICaction-Admitted-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICaction_Admitted_List *_e2ap_RICsubscriptionResponse_IEs_id_RICactions_Admitted;


        /*
        *id: id-RICaction-NotAdmitted-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RICaction_NotAdmitted_List *_e2ap_RICsubscriptionResponse_IEs_id_RICactions_NotAdmitted;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICsubscriptionResponse_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICsubscriptionResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionResponse_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionResponse_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionResponse_protocolIEs_element (e2ap_RICsubscriptionResponse_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionResponse_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionResponse_protocolIEs_element* pvalue);
// --- End of e2ap_RICsubscriptionResponse_protocolIEs_element.h ---

#endif
