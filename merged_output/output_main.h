// --- Begin of e2ap_TransactionID.h ---
/* e2ap_TransactionID.h */
typedef OSUINT8 e2ap_TransactionID;

EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value);
EXTERN int asn1PD_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID* pvalue);
EXTERN void asn1Print_e2ap_TransactionID (const char* name, const e2ap_TransactionID* pvalue);
EXTERN int asn1PrtToStr_e2ap_TransactionID (const char* name, e2ap_TransactionID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_TransactionID (OSCTXT* pctxt, const char* name, const e2ap_TransactionID* pvalue);
// --- End of e2ap_TransactionID.h ---

/******************************************/
/* File .h missing: e2ap_ricRequestorID.h */
/******************************************/

/*****************************************/
/* File .h missing: e2ap_ricInstanceID.h */
/*****************************************/

// --- Begin of e2ap_RICrequestID.h ---

//seq normal

typedef struct e2ap_RICrequestID {
   e2ap_ricRequestorID ricRequestorID;
   e2ap_ricInstanceID ricInstanceID;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_RICrequestID;

EXTERN int asn1PE_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue);
EXTERN int asn1PD_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue);
EXTERN void asn1Init_e2ap_RICrequestID (e2ap_RICrequestID* pvalue);
EXTERN void asn1Free_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue);
EXTERN void asn1Print_e2ap_RICrequestID (const char* name, const e2ap_RICrequestID* pvalue);
// --- End of e2ap_RICrequestID.h ---

// --- Begin of e2ap_RANfunctionID.h ---
/* e2ap_RANfunctionID.h */
typedef OSUINT16 e2ap_RANfunctionID;

EXTERN int asn1PE_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID value);
EXTERN int asn1PD_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionID (const char* name, const e2ap_RANfunctionID* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionID (const char* name, e2ap_RANfunctionID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionID (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionID* pvalue);
// --- End of e2ap_RANfunctionID.h ---

// --- Begin of e2ap_CauseRICrequest.h ---
/* e2ap_CauseRICrequest.h - enumurate*/
/* e2ap_CauseRICrequest.h */

/******************************************************/
/*                                                    */
/*    CauseRICrequest                                       */
/*                                                    */
/******************************************************/

typedef enum {
    e2ap_ran_function_id_invalid = 0,    e2ap_action_not_supported = 1,    e2ap_excessive_actions = 2,    e2ap_duplicate_action = 3,    e2ap_duplicate_event_trigger = 4,    e2ap_function_resource_limit = 5,    e2ap_request_id_unknown = 6,    e2ap_inconsistent_action_subsequent_action_sequence = 7,    e2ap_control_message_invalid = 8,    e2ap_ric_call_process_id_invalid = 9,    e2ap_control_timer_expired = 10,    e2ap_control_failed_to_execute = 11,    e2ap_system_not_ready = 12,    e2ap_unspecified = 13,    e2ap_ric_subscription_end_time_expired = 14,    e2ap_ric_subscription_end_time_invalid = 15,    e2ap_duplicate_ric_request_id = 16,    e2ap_eventTriggerNotSupported = 17,    e2ap_requested_information_unavailable = 18,    e2ap_invalid_information_request = 19//add other values as needed
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
EXTERN int asn1PrtToStr_e2ap_CauseRICrequest (const char* name,const e2ap_CauseRICrequest* pvalue,char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseRICrequest_ENUMTAB[];
#define e2ap_CauseRICrequest_ENUMTABSIZE 20

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseRICrequest_ToString (OSUINT32 value);
EXTERN int e2ap_CauseRICrequest_ToEnum (OSCTXT* pctxt,const OSUTF8CHAR* value,e2ap_CauseRICrequest* pvalue);
EXTERN int e2ap_CauseRICrequest_ToEnum2 (OSCTXT* pctxt,const OSUTF8CHAR* value,OSSIZE valueLen,e2ap_CauseRICrequest* pvalue);
// --- End of e2ap_CauseRICrequest.h ---

// --- Begin of e2ap_CauseRICservice.h ---
/* e2ap_CauseRICservice.h - enumurate*/
/* e2ap_CauseRICservice.h */

/******************************************************/
/*                                                    */
/*    CauseRICservice                                       */
/*                                                    */
/******************************************************/

typedef enum {
    e2ap_ran_function_not_supported = 0,    e2ap_excessive_functions = 1,    e2ap_ric_resource_limit = 2//add other values as needed
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
EXTERN int asn1PrtToStr_e2ap_CauseRICservice (const char* name,const e2ap_CauseRICservice* pvalue,char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseRICservice_ENUMTAB[];
#define e2ap_CauseRICservice_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseRICservice_ToString (OSUINT32 value);
EXTERN int e2ap_CauseRICservice_ToEnum (OSCTXT* pctxt,const OSUTF8CHAR* value,e2ap_CauseRICservice* pvalue);
EXTERN int e2ap_CauseRICservice_ToEnum2 (OSCTXT* pctxt,const OSUTF8CHAR* value,OSSIZE valueLen,e2ap_CauseRICservice* pvalue);
// --- End of e2ap_CauseRICservice.h ---

// --- Begin of e2ap_CauseE2node.h ---
/* e2ap_CauseE2node.h - enumurate*/
/* e2ap_CauseE2node.h */

/******************************************************/
/*                                                    */
/*    CauseE2node                                       */
/*                                                    */
/******************************************************/

typedef enum {
    e2ap_e2node_component_unknown = 0//add other values as needed
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
EXTERN int asn1PrtToStr_e2ap_CauseE2node (const char* name,const e2ap_CauseE2node* pvalue,char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseE2node_ENUMTAB[];
#define e2ap_CauseE2node_ENUMTABSIZE 1

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseE2node_ToString (OSUINT32 value);
EXTERN int e2ap_CauseE2node_ToEnum (OSCTXT* pctxt,const OSUTF8CHAR* value,e2ap_CauseE2node* pvalue);
EXTERN int e2ap_CauseE2node_ToEnum2 (OSCTXT* pctxt,const OSUTF8CHAR* value,OSSIZE valueLen,e2ap_CauseE2node* pvalue);
// --- End of e2ap_CauseE2node.h ---

// --- Begin of e2ap_CauseTransport.h ---
/* e2ap_CauseTransport.h - enumurate*/
/* e2ap_CauseTransport.h */

/******************************************************/
/*                                                    */
/*    CauseTransport                                       */
/*                                                    */
/******************************************************/

typedef enum {
    e2ap_unspecified = 0,    e2ap_transport_resource_unavailable = 1//add other values as needed
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
EXTERN int asn1PrtToStr_e2ap_CauseTransport (const char* name,const e2ap_CauseTransport* pvalue,char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseTransport_ENUMTAB[];
#define e2ap_CauseTransport_ENUMTABSIZE 2

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseTransport_ToString (OSUINT32 value);
EXTERN int e2ap_CauseTransport_ToEnum (OSCTXT* pctxt,const OSUTF8CHAR* value,e2ap_CauseTransport* pvalue);
EXTERN int e2ap_CauseTransport_ToEnum2 (OSCTXT* pctxt,const OSUTF8CHAR* value,OSSIZE valueLen,e2ap_CauseTransport* pvalue);
// --- End of e2ap_CauseTransport.h ---

// --- Begin of e2ap_CauseProtocol.h ---
/* e2ap_CauseProtocol.h - enumurate*/
/* e2ap_CauseProtocol.h */

/******************************************************/
/*                                                    */
/*    CauseProtocol                                       */
/*                                                    */
/******************************************************/

typedef enum {
    e2ap_transfer_syntax_error = 0,    e2ap_abstract_syntax_error_reject = 1,    e2ap_abstract_syntax_error_ignore_and_notify = 2,    e2ap_message_not_compatible_with_receiver_state = 3,    e2ap_©2025bytheO_RANALLIANCEe.V.Youruseissubjecttothecopyrightstatementonthecoverpageofthisspecification.142O_RAN.WG3.TS.E2AP_R004_v07.00semantic_error = 4,    e2ap_abstract_syntax_error_falsely_constructed_message = 5,    e2ap_unspecified = 6//add other values as needed
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
EXTERN int asn1PrtToStr_e2ap_CauseProtocol (const char* name,const e2ap_CauseProtocol* pvalue,char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseProtocol_ENUMTAB[];
#define e2ap_CauseProtocol_ENUMTABSIZE 7

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseProtocol_ToString (OSUINT32 value);
EXTERN int e2ap_CauseProtocol_ToEnum (OSCTXT* pctxt,const OSUTF8CHAR* value,e2ap_CauseProtocol* pvalue);
EXTERN int e2ap_CauseProtocol_ToEnum2 (OSCTXT* pctxt,const OSUTF8CHAR* value,OSSIZE valueLen,e2ap_CauseProtocol* pvalue);
// --- End of e2ap_CauseProtocol.h ---

// --- Begin of e2ap_CauseMisc.h ---
/* e2ap_CauseMisc.h - enumurate*/
/* e2ap_CauseMisc.h */

/******************************************************/
/*                                                    */
/*    CauseMisc                                       */
/*                                                    */
/******************************************************/

typedef enum {
    e2ap_control_processing_overload = 0,    e2ap_hardware_failure = 1,    e2ap_om_intervention = 2,    e2ap_unspecified = 3//add other values as needed
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
EXTERN int asn1PrtToStr_e2ap_CauseMisc (const char* name,const e2ap_CauseMisc* pvalue,char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_CauseMisc_ENUMTAB[];
#define e2ap_CauseMisc_ENUMTABSIZE 4

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_CauseMisc_ToString (OSUINT32 value);
EXTERN int e2ap_CauseMisc_ToEnum (OSCTXT* pctxt,const OSUTF8CHAR* value,e2ap_CauseMisc* pvalue);
EXTERN int e2ap_CauseMisc_ToEnum2 (OSCTXT* pctxt,const OSUTF8CHAR* value,OSSIZE valueLen,e2ap_CauseMisc* pvalue);
// --- End of e2ap_CauseMisc.h ---

// --- Begin of e2ap_ServiceLayerCause.h ---
/* e2ap_ServiceLayerCause.h */
#ifndef _E2AP_SERVICELAYERCAUSE_H_
#define _E2AP_SERVICELAYERCAUSE_H_

#include "rtxsrc/rtxContext.h"
#include "rtxsrc/rtxDList.h"

typedef OSDynOctStr e2ap_ServiceLayerCause;

EXTERN int asn1PE_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause* pvalue);
EXTERN int asn1PD_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause** ppvalue);
EXTERN void asn1Print_e2ap_ServiceLayerCause (const char* name, const e2ap_ServiceLayerCause* pvalue);
EXTERN int asn1PrtToStr_e2ap_ServiceLayerCause (const char* name, e2ap_ServiceLayerCause* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_ServiceLayerCause (OSCTXT* pctxt, const char* name, const e2ap_ServiceLayerCause* pvalue);
EXTERN int asn1Copy_e2ap_ServiceLayerCause (OSCTXT* pctxt, const e2ap_ServiceLayerCause* pSrcValue, e2ap_ServiceLayerCause* pDstValue);
EXTERN int asn1Init_e2ap_ServiceLayerCause (e2ap_ServiceLayerCause* pvalue);
EXTERN void asn1Free_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause* pvalue);

#endif
// --- End of e2ap_ServiceLayerCause.h ---

// --- Begin of e2ap_CauseServiceLayer.h ---

//seq normal

typedef struct e2ap_CauseServiceLayer {
   e2ap_ServiceLayerCause serviceLayerCause;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_CauseServiceLayer;

EXTERN int asn1PE_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue);
EXTERN int asn1PD_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue);
EXTERN void asn1Init_e2ap_CauseServiceLayer (e2ap_CauseServiceLayer* pvalue);
EXTERN void asn1Free_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue);
EXTERN void asn1Print_e2ap_CauseServiceLayer (const char* name, const e2ap_CauseServiceLayer* pvalue);
// --- End of e2ap_CauseServiceLayer.h ---

// --- Begin of e2ap_Cause.h ---
/* e2ap_Cause.h */

// choice
typedef struct e2ap_Cause {
   OSINT32 t;  /* choice tag */
   union {
      e2ap_CauseRICrequest* ricRequest;
      e2ap_CauseRICservice* ricService;
      e2ap_CauseE2node* e2Node;
      e2ap_CauseTransport* transport;
      e2ap_CauseProtocol* protocol;
      e2ap_CauseMisc* misc;
      e2ap_CauseServiceLayer* serviceLayer;
      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_Cause;

EXTERN int asn1PE_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue);
EXTERN int asn1PD_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue);
EXTERN void asn1Print_e2ap_Cause (const char* name, const e2ap_Cause* pvalue);
EXTERN int asn1PrtToStr_e2ap_Cause (const char* name, e2ap_Cause* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_Cause (OSCTXT* pctxt, const e2ap_Cause* pSrcValue, e2ap_Cause* pDstValue);
EXTERN int asn1Init_e2ap_Cause (e2ap_Cause* pvalue);
EXTERN void asn1Free_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue);

// --- End of e2ap_Cause.h ---

// --- Begin of e2ap_ProcedureCode.h ---
/* e2ap_ProcedureCode.h */
typedef OSUINT8 e2ap_ProcedureCode;

EXTERN int asn1PE_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode value);
EXTERN int asn1PD_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode* pvalue);
EXTERN void asn1Print_e2ap_ProcedureCode (const char* name, const e2ap_ProcedureCode* pvalue);
EXTERN int asn1PrtToStr_e2ap_ProcedureCode (const char* name, e2ap_ProcedureCode* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_ProcedureCode (OSCTXT* pctxt, const char* name, const e2ap_ProcedureCode* pvalue);
// --- End of e2ap_ProcedureCode.h ---

// --- Begin of e2ap_TriggeringMessage.h ---
/* e2ap_TriggeringMessage.h - enumurate*/
/* e2ap_TriggeringMessage.h */

/******************************************************/
/*                                                    */
/*    TriggeringMessage                                       */
/*                                                    */
/******************************************************/

typedef enum {
    e2ap_initiating_message = 0,    e2ap_successful_outcome = 1,    e2ap_unsuccessfull_outcome = 2//add other values as needed
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
EXTERN int asn1PrtToStr_e2ap_TriggeringMessage (const char* name,const e2ap_TriggeringMessage* pvalue,char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_TriggeringMessage_ENUMTAB[];
#define e2ap_TriggeringMessage_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_TriggeringMessage_ToString (OSUINT32 value);
EXTERN int e2ap_TriggeringMessage_ToEnum (OSCTXT* pctxt,const OSUTF8CHAR* value,e2ap_TriggeringMessage* pvalue);
EXTERN int e2ap_TriggeringMessage_ToEnum2 (OSCTXT* pctxt,const OSUTF8CHAR* value,OSSIZE valueLen,e2ap_TriggeringMessage* pvalue);
// --- End of e2ap_TriggeringMessage.h ---

// --- Begin of e2ap_Criticality.h ---
/* e2ap_Criticality.h - enumurate*/
/* e2ap_Criticality.h */

/******************************************************/
/*                                                    */
/*    Criticality                                       */
/*                                                    */
/******************************************************/

typedef enum {
    e2ap_reject = 0,    e2ap_ignore = 1,    e2ap_notify = 2//add other values as needed
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
EXTERN int asn1PrtToStr_e2ap_Criticality (const char* name,const e2ap_Criticality* pvalue,char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_Criticality_ENUMTAB[];
#define e2ap_Criticality_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_Criticality_ToString (OSUINT32 value);
EXTERN int e2ap_Criticality_ToEnum (OSCTXT* pctxt,const OSUTF8CHAR* value,e2ap_Criticality* pvalue);
EXTERN int e2ap_Criticality_ToEnum2 (OSCTXT* pctxt,const OSUTF8CHAR* value,OSSIZE valueLen,e2ap_Criticality* pvalue);
// --- End of e2ap_Criticality.h ---

/************************************/
/* File .h missing: e2ap_SEQUENCE.h */
/************************************/

// --- Begin of e2ap_CriticalityDiagnostics_IE_List.h ---

//seq normal

typedef struct e2ap_CriticalityDiagnostics_IE_List {
   e2ap_Criticality iECriticality;
   e2ap_ProtocolIE-ID iE_ID;
   e2ap_TypeOfError typeOfError;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_CriticalityDiagnostics_IE_List;

EXTERN int asn1PE_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN int asn1PD_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN void asn1Init_e2ap_CriticalityDiagnostics_IE_List (e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN void asn1Free_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue);
EXTERN void asn1Print_e2ap_CriticalityDiagnostics_IE_List (const char* name, const e2ap_CriticalityDiagnostics_IE_List* pvalue);
// --- End of e2ap_CriticalityDiagnostics_IE_List.h ---

// --- Begin of e2ap_CriticalityDiagnostics.h ---

//seq normal

typedef struct e2ap_CriticalityDiagnostics {
   e2ap_ProcedureCode procedureCode;
OSBOOL m_procedureCodePresent;   e2ap_TriggeringMessage triggeringMessage;
OSBOOL m_triggeringMessagePresent;   e2ap_Criticality procedureCriticality;
OSBOOL m_procedureCriticalityPresent;   e2ap_RICrequestID ricRequestorID;
OSBOOL m_ricRequestorIDPresent;   e2ap_CriticalityDiagnostics-IE-List iEsCriticalityDiagnostics;
OSBOOL m_iEsCriticalityDiagnosticsPresent;ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_CriticalityDiagnostics;

EXTERN int asn1PE_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue);
EXTERN int asn1PD_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue);
EXTERN void asn1Init_e2ap_CriticalityDiagnostics (e2ap_CriticalityDiagnostics* pvalue);
EXTERN void asn1Free_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue);
EXTERN void asn1Print_e2ap_CriticalityDiagnostics (const char* name, const e2ap_CriticalityDiagnostics* pvalue);
// --- End of e2ap_CriticalityDiagnostics.h ---

/***********************************************/
/* File .h missing: e2ap_ErrorIndication_IEs.h */
/***********************************************/

// --- Begin of e2ap_ErrorIndication.h ---

//seq normal

typedef struct e2ap_ErrorIndication {
   e2ap_ProtocolIE-Container protocolIEs;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_ErrorIndication;

EXTERN int asn1PE_e2ap_ErrorIndication (OSCTXT* pctxt, e2ap_ErrorIndication* pvalue);
EXTERN int asn1PD_e2ap_ErrorIndication (OSCTXT* pctxt, e2ap_ErrorIndication* pvalue);
EXTERN void asn1Init_e2ap_ErrorIndication (e2ap_ErrorIndication* pvalue);
EXTERN void asn1Free_e2ap_ErrorIndication (OSCTXT* pctxt, e2ap_ErrorIndication* pvalue);
EXTERN void asn1Print_e2ap_ErrorIndication (const char* name, const e2ap_ErrorIndication* pvalue);
// --- End of e2ap_ErrorIndication.h ---

