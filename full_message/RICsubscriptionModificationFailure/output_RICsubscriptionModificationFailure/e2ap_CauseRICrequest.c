/******************************************************/
/*                                                    */
/*    CauseRICrequest                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_CauseRICrequest_ENUMTAB[] = {
    { OSUTF8("ran_function_id_invalid"), 0, 23, 0 },
    { OSUTF8("action_not_supported"), 1, 20, 1 },
    { OSUTF8("excessive_actions"), 2, 17, 2 },
    { OSUTF8("duplicate_action"), 3, 16, 3 },
    { OSUTF8("duplicate_event_trigger"), 4, 23, 4 },
    { OSUTF8("function_resource_limit"), 5, 23, 5 },
    { OSUTF8("request_id_unknown"), 6, 18, 6 },
    { OSUTF8("inconsistent_action_subsequent_action_sequence"), 7, 46, 7 },
    { OSUTF8("control_message_invalid"), 8, 23, 8 },
    { OSUTF8("ric_call_process_id_invalid"), 9, 27, 9 },
    { OSUTF8("control_timer_expired"), 10, 21, 10 },
    { OSUTF8("control_failed_to_execute"), 11, 25, 11 },
    { OSUTF8("system_not_ready"), 12, 16, 12 },
    { OSUTF8("unspecified"), 13, 11, 13 },
    { OSUTF8("ric_subscription_end_time_expired"), 14, 33, 14 },
    { OSUTF8("ric_subscription_end_time_invalid"), 15, 33, 15 },
    { OSUTF8("duplicate_ric_request_id"), 16, 24, 16 },
    { OSUTF8("eventTriggerNotSupported"), 17, 24, 17 },
    { OSUTF8("requested_information_unavailable"), 18, 33, 18 },
    { OSUTF8("invalid_information_request"), 19, 27, 19 }
};


const OSUTF8CHAR* e2ap_CauseRICrequest_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_CauseRICrequest_ENUMTABSIZE){
      return e2ap_CauseRICrequest_ENUMTAB[e2ap_CauseRICrequest_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_CauseRICrequest_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseRICrequest* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_CauseRICrequest_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_CauseRICrequest_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseRICrequest* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_CauseRICrequest_ENUMTAB, e2ap_CauseRICrequest_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_CauseRICrequest)e2ap_CauseRICrequest_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_CauseRICrequest (OSCTXT* pctxt, e2ap_CauseRICrequest value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "CauseRICrequest");
   if (value >= 20) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(19));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseRICrequest (OSCTXT* pctxt, e2ap_CauseRICrequest* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CauseRICrequest");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(19));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseRICrequest (const char* name, e2ap_CauseRICrequest* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = ran_function_id_invalid", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = action_not_supported", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = excessive_actions", buffer, bufSize);
         break;
      case 3:
         stat = rtPrintToString(" = duplicate_action", buffer, bufSize);
         break;
      case 4:
         stat = rtPrintToString(" = duplicate_event_trigger", buffer, bufSize);
         break;
      case 5:
         stat = rtPrintToString(" = function_resource_limit", buffer, bufSize);
         break;
      case 6:
         stat = rtPrintToString(" = request_id_unknown", buffer, bufSize);
         break;
      case 7:
         stat = rtPrintToString(" = inconsistent_action_subsequent_action_sequence", buffer, bufSize);
         break;
      case 8:
         stat = rtPrintToString(" = control_message_invalid", buffer, bufSize);
         break;
      case 9:
         stat = rtPrintToString(" = ric_call_process_id_invalid", buffer, bufSize);
         break;
      case 10:
         stat = rtPrintToString(" = control_timer_expired", buffer, bufSize);
         break;
      case 11:
         stat = rtPrintToString(" = control_failed_to_execute", buffer, bufSize);
         break;
      case 12:
         stat = rtPrintToString(" = system_not_ready", buffer, bufSize);
         break;
      case 13:
         stat = rtPrintToString(" = unspecified", buffer, bufSize);
         break;
      case 14:
         stat = rtPrintToString(" = ric_subscription_end_time_expired", buffer, bufSize);
         break;
      case 15:
         stat = rtPrintToString(" = ric_subscription_end_time_invalid", buffer, bufSize);
         break;
      case 16:
         stat = rtPrintToString(" = duplicate_ric_request_id", buffer, bufSize);
         break;
      case 17:
         stat = rtPrintToString(" = eventTriggerNotSupported", buffer, bufSize);
         break;
      case 18:
         stat = rtPrintToString(" = requested_information_unavailable", buffer, bufSize);
         break;
      case 19:
         stat = rtPrintToString(" = invalid_information_request", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}