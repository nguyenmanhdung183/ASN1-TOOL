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