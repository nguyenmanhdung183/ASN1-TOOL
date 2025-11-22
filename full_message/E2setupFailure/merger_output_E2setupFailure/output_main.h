
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

// --- Begin of e2ap_TimeToWait.h ---
/******************************************************/
/*                                                    */
/*    TimeToWait                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_v1s = 0,
    e2ap_v2s = 1,
    e2ap_v5s = 2,
    e2ap_v10s = 3,
    e2ap_v20s = 4,
    e2ap_v60s = 5
} e2ap_TimeToWait_Root;

typedef OSUINT32 e2ap_TimeToWait;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_TimeToWait (OSCTXT* pctxt, e2ap_TimeToWait value);
EXTERN int asn1PD_e2ap_TimeToWait (OSCTXT* pctxt, e2ap_TimeToWait* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_TimeToWait (const char* name, const e2ap_TimeToWait* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_TimeToWait (OSCTXT* pctxt, const char* name, const e2ap_TimeToWait* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_TimeToWait (const char* name,const e2ap_TimeToWait* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_TimeToWait_ENUMTAB[];
#define e2ap_TimeToWait_ENUMTABSIZE 6

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_TimeToWait_ToString (OSUINT32 value);
EXTERN int e2ap_TimeToWait_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_TimeToWait* pvalue);
EXTERN int e2ap_TimeToWait_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_TimeToWait* pvalue);
// --- End of e2ap_TimeToWait.h ---

// --- Begin of e2ap_ProcedureCode.h ---
/*****************************************/
/*        ProcedureCode         */
/*****************************************/
//interger no ext


typedef OSUINT8 e2ap_ProcedureCode;

EXTERN int asn1PE_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode value);
EXTERN int asn1PD_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode* pvalue);
EXTERN void asn1Print_e2ap_ProcedureCode (const char* name, const e2ap_ProcedureCode* pvalue);
EXTERN int asn1PrtToStr_e2ap_ProcedureCode (const char* name, e2ap_ProcedureCode* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_ProcedureCode (OSCTXT* pctxt, const char* name, const e2ap_ProcedureCode* pvalue);
// --- End of e2ap_ProcedureCode.h ---

// --- Begin of e2ap_TriggeringMessage.h ---
/******************************************************/
/*                                                    */
/*    TriggeringMessage                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_initiating_message = 0,
    e2ap_successful_outcome = 1,
    e2ap_unsuccessfull_outcome = 2
} e2ap_TriggeringMessage_Root;

typedef OSUINT32 e2ap_TriggeringMessage;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_TriggeringMessage (OSCTXT* pctxt, e2ap_TriggeringMessage value);
EXTERN int asn1PD_e2ap_TriggeringMessage (OSCTXT* pctxt, e2ap_TriggeringMessage* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_TriggeringMessage (const char* name, const e2ap_TriggeringMessage* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_TriggeringMessage (OSCTXT* pctxt, const char* name, const e2ap_TriggeringMessage* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_TriggeringMessage (const char* name,const e2ap_TriggeringMessage* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_TriggeringMessage_ENUMTAB[];
#define e2ap_TriggeringMessage_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_TriggeringMessage_ToString (OSUINT32 value);
EXTERN int e2ap_TriggeringMessage_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_TriggeringMessage* pvalue);
EXTERN int e2ap_TriggeringMessage_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_TriggeringMessage* pvalue);
// --- End of e2ap_TriggeringMessage.h ---

// --- Begin of e2ap_Criticality.h ---
/******************************************************/
/*                                                    */
/*    Criticality                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_reject = 0,
    e2ap_ignore = 1,
    e2ap_notify = 2
} e2ap_Criticality_Root;

typedef OSUINT32 e2ap_Criticality;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_Criticality (OSCTXT* pctxt, e2ap_Criticality value);
EXTERN int asn1PD_e2ap_Criticality (OSCTXT* pctxt, e2ap_Criticality* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_Criticality (const char* name, const e2ap_Criticality* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_Criticality (OSCTXT* pctxt, const char* name, const e2ap_Criticality* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_Criticality (const char* name,const e2ap_Criticality* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_Criticality_ENUMTAB[];
#define e2ap_Criticality_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_Criticality_ToString (OSUINT32 value);
EXTERN int e2ap_Criticality_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_Criticality* pvalue);
EXTERN int e2ap_Criticality_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_Criticality* pvalue);
// --- End of e2ap_Criticality.h ---

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

/************************************/
/* File .h missing: e2ap_SEQUENCE.h */
/************************************/

// --- Begin of e2ap_CriticalityDiagnostics_IE_List.h ---
/*****************************************/
/*           CriticalityDiagnostics_IE_List                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_CriticalityDiagnostics_IE_List {
   e2ap_Criticality iECriticality;
   e2ap_ProtocolIE_ID iE_ID;
   e2ap_TypeOfError typeOfError;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_CriticalityDiagnostics_IE_List;

EXTERN int asn1PE_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN int asn1PD_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN int asn1Init_e2ap_CriticalityDiagnostics_IE_List (e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN void asn1Free_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN void asn1Print_e2ap_CriticalityDiagnostics_IE_List (const char* name, const e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_CriticalityDiagnostics_IE_List (const char* name, e2ap_CriticalityDiagnostics_IE_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, const char* name, const e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN int asn1Copy_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, const e2ap_CriticalityDiagnostics_IE_List* pSrcValue, e2ap_CriticalityDiagnostics_IE_List* pDstValue);
// --- End of e2ap_CriticalityDiagnostics_IE_List.h ---

// --- Begin of e2ap_CriticalityDiagnostics.h ---
/*****************************************/
/*           CriticalityDiagnostics                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_CriticalityDiagnostics {
   e2ap_ProcedureCode procedureCode;
     OSBOOL m_procedureCodePresent;   e2ap_TriggeringMessage triggeringMessage;
     OSBOOL m_triggeringMessagePresent;   e2ap_Criticality procedureCriticality;
     OSBOOL m_procedureCriticalityPresent;   e2ap_RICrequestID ricRequestorID;
     OSBOOL m_ricRequestorIDPresent;   e2ap_CriticalityDiagnostics_IE_List iEsCriticalityDiagnostics;
     OSBOOL m_iEsCriticalityDiagnosticsPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_CriticalityDiagnostics;

EXTERN int asn1PE_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue);
EXTERN int asn1PD_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue);
EXTERN int asn1Init_e2ap_CriticalityDiagnostics (e2ap_CriticalityDiagnostics* pvalue);
EXTERN void asn1Free_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue);
EXTERN void asn1Print_e2ap_CriticalityDiagnostics (const char* name, const e2ap_CriticalityDiagnostics* pvalue);
EXTERN int asn1PrtToStr_e2ap_CriticalityDiagnostics (const char* name, e2ap_CriticalityDiagnostics* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, const char* name, const e2ap_CriticalityDiagnostics* pvalue);
EXTERN int asn1Copy_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, const e2ap_CriticalityDiagnostics* pSrcValue, e2ap_CriticalityDiagnostics* pDstValue);
// --- End of e2ap_CriticalityDiagnostics.h ---

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

/*********************************************/
/* File .h missing: e2ap_E2setupFailureIEs.h */
/*********************************************/

// --- Begin of e2ap_E2setupFailure.h ---
/*****************************************/
/*           E2setupFailure                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2setupFailure {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2setupFailure;

EXTERN int asn1PE_e2ap_E2setupFailure (OSCTXT* pctxt, e2ap_E2setupFailure* pvalue);
EXTERN int asn1PD_e2ap_E2setupFailure (OSCTXT* pctxt, e2ap_E2setupFailure* pvalue);
EXTERN int asn1Init_e2ap_E2setupFailure (e2ap_E2setupFailure* pvalue);
EXTERN void asn1Free_e2ap_E2setupFailure (OSCTXT* pctxt, e2ap_E2setupFailure* pvalue);
EXTERN void asn1Print_e2ap_E2setupFailure (const char* name, const e2ap_E2setupFailure* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2setupFailure (const char* name, e2ap_E2setupFailure* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2setupFailure (OSCTXT* pctxt, const char* name, const e2ap_E2setupFailure* pvalue);
EXTERN int asn1Copy_e2ap_E2setupFailure (OSCTXT* pctxt, const e2ap_E2setupFailure* pSrcValue, e2ap_E2setupFailure* pDstValue);
// --- End of e2ap_E2setupFailure.h ---

// --- Begin of e2ap_E2setupFailure_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    E2setupFailure_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from E2setupFailure*/

typedef OSRTDList e2ap_E2setupFailure_protocolIEs;

EXTERN int asn1PE_e2ap_E2setupFailure_protocolIEs (OSCTXT* pctxt, e2ap_E2setupFailure_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_E2setupFailure_protocolIEs (OSCTXT* pctxt, e2ap_E2setupFailure_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_E2setupFailure_protocolIEs (e2ap_E2setupFailure_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_E2setupFailure_protocolIEs (OSCTXT* pctxt, e2ap_E2setupFailure_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2setupFailure_protocolIEs (OSCTXT* pctxt, e2ap_E2setupFailure_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apE2setupFailure_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_E2setupFailure_protocolIEs* pvalue);
// --- End of e2ap_E2setupFailure_protocolIEs.h ---

// --- Begin of e2ap_E2setupFailure_protocolIEs_element.h ---
/*****************************************/
/*    E2setupFailure_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from E2setupFailure*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2setupFailureIEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2setupFailureIEs_id_TransactionID,

   T_E2AP_PDU_Contents_e2ap_E2setupFailureIEs_id_Cause,

   T_E2AP_PDU_Contents_e2ap_E2setupFailureIEs_id_TimeToWait,

   T_E2AP_PDU_Contents_e2ap_E2setupFailureIEs_id_CriticalityDiagnostics,

   T_E2AP_PDU_Contents_e2ap_E2setupFailureIEs_id_TNLinformation,

   T_E2AP_PDU_Contents_e2ap_E2setupFailureIEs_id_Extended_RANNodeName_

}e2ap_E2setupFailureIEs_TVALUE;


typedef struct EXTERN e2ap_E2setupFailure_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2setupFailureIEs_TVALUE t;
      union {
        /*
        *id: id-TransactionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_TransactionID *_e2ap_E2setupFailureIEs_id_TransactionID;


        /*
        *id: id-Cause
        *criticality: ignore
        *presence: MANDATORY
        */
        e2ap_Cause *_e2ap_E2setupFailureIEs_id_Cause;


        /*
        *id: id-TimeToWait
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_TimeToWait *_e2ap_E2setupFailureIEs_id_TimeToWait;


        /*
        *id: id-CriticalityDiagnostics
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_CriticalityDiagnostics *_e2ap_E2setupFailureIEs_id_CriticalityDiagnostics;


        /*
        *id: id-TNLinformation
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_TNLinformation *_e2ap_E2setupFailureIEs_id_TNLinformation;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_E2setupFailure_protocolIEs_element;


EXTERN int asn1PE_e2ap_E2setupFailure_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupFailure_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_E2setupFailure_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupFailure_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_E2setupFailure_protocolIEs_element (e2ap_E2setupFailure_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_E2setupFailure_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupFailure_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2setupFailure_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupFailure_protocolIEs_element* pvalue);
// --- End of e2ap_E2setupFailure_protocolIEs_element.h ---

#endif
