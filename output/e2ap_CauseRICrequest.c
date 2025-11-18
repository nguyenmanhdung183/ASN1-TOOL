/* e2ap_CauseRICrequest.c */
#include "e2ap_CauseRICrequest.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_CauseRICrequest_ENUMTAB[e2ap_CauseRICrequest_ENUMTABSIZE] = {
   { OSUTF8("ran_function_id_invalid"), 0, 23,  },   { OSUTF8("action_not_supported"), 1, 20,  },   { OSUTF8("excessive_actions"), 2, 17,  },   { OSUTF8("duplicate_action"), 3, 16,  },   { OSUTF8("duplicate_event_trigger"), 4, 23,  },   { OSUTF8("function_resource_limit"), 5, 23,  },   { OSUTF8("request_id_unknown"), 6, 18,  },   { OSUTF8("inconsistent_action_subsequent_action_sequence"), 7, 46,  },   { OSUTF8("control_message_invalid"), 8, 23,  },   { OSUTF8("ric_call_process_id_invalid"), 9, 27,  },   { OSUTF8("control_timer_expired"), 10, 21,  },   { OSUTF8("control_failed_to_execute"), 11, 25,  },   { OSUTF8("system_not_ready"), 12, 16,  },   { OSUTF8("unspecified"), 13, 11,  },   { OSUTF8("ric_subscription_end_time_expired"), 14, 33,  },   { OSUTF8("ric_subscription_end_time_invalid"), 15, 33,  },   { OSUTF8("duplicate_ric_request_id"), 16, 24,  },   { OSUTF8("eventTriggerNotSupported"), 17, 24,  },   { OSUTF8("requested_information_unavailable"), 18, 33,  },   { OSUTF8("invalid_information_request"), 19, 27,  }};

EXTERN int asn1PE_e2ap_CauseRICrequest (OSCTXT* pctxt, e2ap_CauseRICrequest value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseRICrequest");
   if (value >= 20) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(19));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_CauseRICrequest (OSCTXT* pctxt, e2ap_CauseRICrequest* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseRICrequest");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(19));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseRICrequest (const char* name, e2ap_CauseRICrequest* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_CauseRICrequest_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_CauseRICrequest_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}