#include "output_main.h"
// --- Begin of doc/header.c ---
//======================E2AP.c========================//
// --- End of doc/header.c ---

// --- Begin of e2ap_TransactionID.c ---
/*****************************************/
/*           TransactionID                */
/*****************************************/
//interger with ext


EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value)
{ 
   RTXCTXTPUSHTYPENAME (pctxt, "TransactionID");

   OSBOOL exbit = (value > 255) ? TRUE : FALSE;
   int stat = rtxEncBit (pctxt, exbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!exbit) {
      stat = pe_ConsUnsigned (pctxt, value, 0, 255);
   } else {
      stat = pe_UnconsUnsigned (pctxt, value);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME (pctxt, "TransactionID");
   stat = rtxDecBit (pctxt, &extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!extbit) {
      stat = pd_ConsUnsigned (pctxt, pvalue, 0, 255);
   } else {
      stat = pd_UnconsUnsigned (pctxt, pvalue);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return 0;
}

EXTERN int asn1PrtToStr_e2ap_TransactionID (const char* name, e2ap_TransactionID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_TransactionID.c ---

// --- Begin of e2ap_CauseRICrequest.c ---
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
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseRICrequest (OSCTXT* pctxt, e2ap_CauseRICrequest* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CauseRICrequest");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(19));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);

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
// --- End of e2ap_CauseRICrequest.c ---

// --- Begin of e2ap_CauseRICservice.c ---
/******************************************************/
/*                                                    */
/*    CauseRICservice                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_CauseRICservice_ENUMTAB[] = {
    { OSUTF8("ran_function_not_supported"), 0, 26, 0 },
    { OSUTF8("excessive_functions"), 1, 19, 1 },
    { OSUTF8("ric_resource_limit"), 2, 18, 2 }
};


const OSUTF8CHAR* e2ap_CauseRICservice_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_CauseRICservice_ENUMTABSIZE){
      return e2ap_CauseRICservice_ENUMTAB[e2ap_CauseRICservice_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_CauseRICservice_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseRICservice* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_CauseRICservice_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_CauseRICservice_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseRICservice* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_CauseRICservice_ENUMTAB, e2ap_CauseRICservice_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_CauseRICservice)e2ap_CauseRICservice_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_CauseRICservice (OSCTXT* pctxt, e2ap_CauseRICservice value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "CauseRICservice");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseRICservice (OSCTXT* pctxt, e2ap_CauseRICservice* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CauseRICservice");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseRICservice (const char* name, e2ap_CauseRICservice* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = ran_function_not_supported", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = excessive_functions", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = ric_resource_limit", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_CauseRICservice.c ---

// --- Begin of e2ap_CauseE2node.c ---
/******************************************************/
/*                                                    */
/*    CauseE2node                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_CauseE2node_ENUMTAB[] = {
    { OSUTF8("e2node_component_unknown"), 0, 24, 0 }
};


const OSUTF8CHAR* e2ap_CauseE2node_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_CauseE2node_ENUMTABSIZE){
      return e2ap_CauseE2node_ENUMTAB[e2ap_CauseE2node_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_CauseE2node_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseE2node* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_CauseE2node_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_CauseE2node_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseE2node* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_CauseE2node_ENUMTAB, e2ap_CauseE2node_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_CauseE2node)e2ap_CauseE2node_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_CauseE2node (OSCTXT* pctxt, e2ap_CauseE2node value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "CauseE2node");
   if (value >= 1) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(0));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseE2node (OSCTXT* pctxt, e2ap_CauseE2node* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CauseE2node");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(0));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseE2node (const char* name, e2ap_CauseE2node* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = e2node_component_unknown", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_CauseE2node.c ---

// --- Begin of e2ap_CauseTransport.c ---
/******************************************************/
/*                                                    */
/*    CauseTransport                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_CauseTransport_ENUMTAB[] = {
    { OSUTF8("unspecified"), 0, 11, 0 },
    { OSUTF8("transport_resource_unavailable"), 1, 30, 1 }
};


const OSUTF8CHAR* e2ap_CauseTransport_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_CauseTransport_ENUMTABSIZE){
      return e2ap_CauseTransport_ENUMTAB[e2ap_CauseTransport_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_CauseTransport_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseTransport* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_CauseTransport_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_CauseTransport_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseTransport* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_CauseTransport_ENUMTAB, e2ap_CauseTransport_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_CauseTransport)e2ap_CauseTransport_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_CauseTransport (OSCTXT* pctxt, e2ap_CauseTransport value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "CauseTransport");
   if (value >= 2) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(1));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseTransport (OSCTXT* pctxt, e2ap_CauseTransport* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CauseTransport");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(1));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseTransport (const char* name, e2ap_CauseTransport* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = unspecified", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = transport_resource_unavailable", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_CauseTransport.c ---

// --- Begin of e2ap_CauseProtocol.c ---
/******************************************************/
/*                                                    */
/*    CauseProtocol                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_CauseProtocol_ENUMTAB[] = {
    { OSUTF8("transfer_syntax_error"), 0, 21, 0 },
    { OSUTF8("abstract_syntax_error_reject"), 1, 28, 1 },
    { OSUTF8("abstract_syntax_error_ignore_and_notify"), 2, 39, 2 },
    { OSUTF8("message_not_compatible_with_receiver_state"), 3, 42, 3 },
    { OSUTF8("semantic_error"), 4, 14, 4 },
    { OSUTF8("abstract_syntax_error_falsely_constructed_message"), 5, 49, 5 },
    { OSUTF8("unspecified"), 6, 11, 6 }
};


const OSUTF8CHAR* e2ap_CauseProtocol_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_CauseProtocol_ENUMTABSIZE){
      return e2ap_CauseProtocol_ENUMTAB[e2ap_CauseProtocol_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_CauseProtocol_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseProtocol* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_CauseProtocol_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_CauseProtocol_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseProtocol* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_CauseProtocol_ENUMTAB, e2ap_CauseProtocol_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_CauseProtocol)e2ap_CauseProtocol_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_CauseProtocol (OSCTXT* pctxt, e2ap_CauseProtocol value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "CauseProtocol");
   if (value >= 7) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(6));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseProtocol (OSCTXT* pctxt, e2ap_CauseProtocol* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CauseProtocol");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(6));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseProtocol (const char* name, e2ap_CauseProtocol* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = transfer_syntax_error", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = abstract_syntax_error_reject", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = abstract_syntax_error_ignore_and_notify", buffer, bufSize);
         break;
      case 3:
         stat = rtPrintToString(" = message_not_compatible_with_receiver_state", buffer, bufSize);
         break;
      case 4:
         stat = rtPrintToString(" = semantic_error", buffer, bufSize);
         break;
      case 5:
         stat = rtPrintToString(" = abstract_syntax_error_falsely_constructed_message", buffer, bufSize);
         break;
      case 6:
         stat = rtPrintToString(" = unspecified", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_CauseProtocol.c ---

// --- Begin of e2ap_CauseMisc.c ---
/******************************************************/
/*                                                    */
/*    CauseMisc                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_CauseMisc_ENUMTAB[] = {
    { OSUTF8("control_processing_overload"), 0, 27, 0 },
    { OSUTF8("hardware_failure"), 1, 16, 1 },
    { OSUTF8("om_intervention"), 2, 15, 2 },
    { OSUTF8("unspecified"), 3, 11, 3 }
};


const OSUTF8CHAR* e2ap_CauseMisc_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_CauseMisc_ENUMTABSIZE){
      return e2ap_CauseMisc_ENUMTAB[e2ap_CauseMisc_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_CauseMisc_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseMisc* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_CauseMisc_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_CauseMisc_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseMisc* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_CauseMisc_ENUMTAB, e2ap_CauseMisc_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_CauseMisc)e2ap_CauseMisc_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "CauseMisc");
   if (value >= 4) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(3));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CauseMisc");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(3));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseMisc (const char* name, e2ap_CauseMisc* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = control_processing_overload", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = hardware_failure", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = om_intervention", buffer, bufSize);
         break;
      case 3:
         stat = rtPrintToString(" = unspecified", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_CauseMisc.c ---

// --- Begin of e2ap_ServiceLayerCause.c ---
/*****************************************/
/*           ServiceLayerCause                */
/*****************************************/
//octet string

/* Dynamic OCTET STRING (no SIZE constraint) */
EXTERN int asn1PE_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause* pvalue)
{
   int stat = 0;
  
   RTXCTXTPUSHTYPENAME (pctxt, "ServiceLayerCause");
   
   stat = pe_OctetString (pctxt, pvalue->numocts, pvalue->data);
 
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause** ppvalue)
{
   int stat = 0;
  
   RTXCTXTPUSHTYPENAME (pctxt, "ServiceLayerCause");
 
   stat = pd_DynOctetString (pctxt, (OSDynOctStr**)ppvalue);
   
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

int asn1Init_e2ap_ServiceLayerCause (e2ap_ServiceLayerCause* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->numocts = 0;
   pvalue->data = 0;
   return 0;
}

void asn1Free_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause* pvalue)
{
   if (pvalue == 0) return;
   if (pvalue->numocts > 0 && pvalue->data != 0) {
      rtxMemFreePtr (pctxt, (void*)pvalue->data);
   }
   pvalue->numocts = 0;
   pvalue->data = 0;
}


/* Print to string */
int asn1PrtToStr_e2ap_ServiceLayerCause (const char* name, e2ap_ServiceLayerCause* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) {
      return -1;
   }
   if (rtPrintToStringHexStr (name, pvalue->numocts, pvalue->data, buffer, bufSize) < 0){
      return -1;
   }
   return 0;
}
// --- End of e2ap_ServiceLayerCause.c ---

// --- Begin of e2ap_CauseServiceLayer.c ---

/*****************************************/
/*           CauseServiceLayer                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "CauseServiceLayer");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field serviceLayerCause */  

   RTXCTXTPUSHELEMNAME(pctxt, "serviceLayerCause");
   stat = asn1PE_e2ap_ServiceLayerCause (pctxt, &pvalue->serviceLayerCause);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);



   /*
   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   */

   if(extbit) {
      /*encode extension optional bits length */
      stat = pe_SmallLength(pctxt, pvalue->extElem1.count);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode optional bit*/
      stat = pe_OpenTypeExtBits(pctxt, &pvalue->extElem1);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode extension elements*/
      if (pvalue->extElem1.count > 0) {
         stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "CauseServiceLayer");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 1; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field serviceLayerCause */
   RTXCTXTPUSHELEMNAME(pctxt, "serviceLayerCause");
      stat = asn1PD_e2ap_ServiceLayerCause (pctxt, &pvalue->serviceLayerCause);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pdSmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFree(pctxt, poptbits);
            return LOG_RTERR(pctxt, stat);
         }
      }

      for(i_ = 0; i_ < bitcnt; i_++) {
         if(stat != 0) break;
         if(poptbits[i_]) {
            /*decode extension element*/
            stat = pd_OpenType (pctxt, &openType, &openType.numocts);

            if(0==stat){
               pOpenType = rtxMemAllocType(pctxt, ASN1OpenType);
               if(0!=pOpenType){
                  pOpenType->numocts = openType.numocts;
                  pOpenType->data = openType.data;
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_CauseServiceLayer (e2ap_CauseServiceLayer* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_ServiceLayerCause (&pvalue->serviceLayerCause);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_ServiceLayerCause (pctxt, &pvalue->serviceLayerCause);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_CauseServiceLayer (const char* name, e2ap_CauseServiceLayer* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ServiceLayerCause ("serviceLayerCause", &pvalue->serviceLayerCause, buffer, bufSize) < 0)
   {
      return -1;
   }

   /*assum there is an extension*/
   if(rtPrintToStringOpenTypeExtBraceText("extElem1", &pvalue->extElem1, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_CauseServiceLayer.c ---

// --- Begin of e2ap_Cause.c ---
/* e2ap_Cause.c */

/*****************************************/
/*           Cause                */
/*****************************************/
// choice

// choice without extension

EXTERN int asn1PE_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "Cause");
   RTXCTXTPUSHELEMNAME (pctxt, "t");
 
   stat = rtxEncBits (pctxt, pvalue->t - 1, 3);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   switch (pvalue->t) {
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "ricRequest");

         stat = asn1PE_e2ap_CauseRICrequest (pctxt, pvalue->u.ricRequest);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXTPUSHELEMNAME (pctxt, "ricService");

         stat = asn1PE_e2ap_CauseRICservice (pctxt, pvalue->u.ricService);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXTPUSHELEMNAME (pctxt, "e2Node");

         stat = asn1PE_e2ap_CauseE2node (pctxt, pvalue->u.e2Node);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 4:
         RTXCTXTPUSHELEMNAME (pctxt, "transport");

         stat = asn1PE_e2ap_CauseTransport (pctxt, pvalue->u.transport);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 5:
         RTXCTXTPUSHELEMNAME (pctxt, "protocol");

         stat = asn1PE_e2ap_CauseProtocol (pctxt, pvalue->u.protocol);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 6:
         RTXCTXTPUSHELEMNAME (pctxt, "misc");

         stat = asn1PE_e2ap_CauseMisc (pctxt, pvalue->u.misc);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 7:
         RTXCTXTPUSHELEMNAME (pctxt, "serviceLayer");

         stat = asn1PE_e2ap_CauseServiceLayer (pctxt, pvalue->u.serviceLayer);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PD_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   RTXCTXTPUSHTYPENAME (pctxt, "Cause");

 
   stat = rtxDecBits (pctxt, &ui, 3);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   else pvalue->t = ui + 1;
   //RTXCTXTPOPELEMNAME (pctxt);

   switch (ui) {
      case 0:
         RTXCTXTPUSHELEMNAME (pctxt, "ricRequest");

         pvalue->u.ricRequest = rtxMemAllocType (pctxt, e2ap_CauseRICrequest);

         if (pvalue->u.ricRequest == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_CauseRICrequest (pctxt, pvalue->u.ricRequest);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "ricService");

         pvalue->u.ricService = rtxMemAllocType (pctxt, e2ap_CauseRICservice);

         if (pvalue->u.ricService == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_CauseRICservice (pctxt, pvalue->u.ricService);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXTPUSHELEMNAME (pctxt, "e2Node");

         pvalue->u.e2Node = rtxMemAllocType (pctxt, e2ap_CauseE2node);

         if (pvalue->u.e2Node == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_CauseE2node (pctxt, pvalue->u.e2Node);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXTPUSHELEMNAME (pctxt, "transport");

         pvalue->u.transport = rtxMemAllocType (pctxt, e2ap_CauseTransport);

         if (pvalue->u.transport == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_CauseTransport (pctxt, pvalue->u.transport);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 4:
         RTXCTXTPUSHELEMNAME (pctxt, "protocol");

         pvalue->u.protocol = rtxMemAllocType (pctxt, e2ap_CauseProtocol);

         if (pvalue->u.protocol == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_CauseProtocol (pctxt, pvalue->u.protocol);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 5:
         RTXCTXTPUSHELEMNAME (pctxt, "misc");

         pvalue->u.misc = rtxMemAllocType (pctxt, e2ap_CauseMisc);

         if (pvalue->u.misc == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_CauseMisc (pctxt, pvalue->u.misc);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 6:
         RTXCTXTPUSHELEMNAME (pctxt, "serviceLayer");

         pvalue->u.serviceLayer = rtxMemAllocType (pctxt, e2ap_CauseServiceLayer);

         if (pvalue->u.serviceLayer == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_CauseServiceLayer (pctxt, pvalue->u.serviceLayer);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PrtToStr_e2ap_Cause (const char* name, e2ap_Cause* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) return -1;
   

   switch (pvalue->t) {
      case T_e2ap_Cause_ricRequest:
         if (asn1PrtToStr_e2ap_CauseRICrequest ( "ricRequest", pvalue->u.ricRequest, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_Cause_ricService:
         if (asn1PrtToStr_e2ap_CauseRICservice ( "ricService", pvalue->u.ricService, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_Cause_e2Node:
         if (asn1PrtToStr_e2ap_CauseE2node ( "e2Node", pvalue->u.e2Node, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_Cause_transport:
         if (asn1PrtToStr_e2ap_CauseTransport ( "transport", pvalue->u.transport, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_Cause_protocol:
         if (asn1PrtToStr_e2ap_CauseProtocol ( "protocol", pvalue->u.protocol, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_Cause_misc:
         if (asn1PrtToStr_e2ap_CauseMisc ( "misc", pvalue->u.misc, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_Cause_serviceLayer:
         if (asn1PrtToStr_e2ap_CauseServiceLayer ( "serviceLayer", pvalue->u.serviceLayer, buffer, bufSize) < 0) return -1;
         break;
      default:
         return RTERR_INVOPT;
   }

   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}

int asn1Init_e2ap_Cause (e2ap_Cause* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->t = 0;
   OSRTLMEMSET (&pvalue->u, 0, sizeof(pvalue->u));
   return 0;
}


void asn1Free_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue)
{
   if (pvalue == 0) return;
   switch (pvalue->t) {
      case 0: //no choice nothing to free
         break;
      case 1:
         if (pvalue->u.ricRequest) {
            asn1Free_e2ap_CauseRICrequest (pctxt, pvalue->u.ricRequest);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.ricRequest);
            pvalue->u.ricRequest = 0;
         }
         break;
      case 2:
         if (pvalue->u.ricService) {
            asn1Free_e2ap_CauseRICservice (pctxt, pvalue->u.ricService);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.ricService);
            pvalue->u.ricService = 0;
         }
         break;
      case 3:
         if (pvalue->u.e2Node) {
            asn1Free_e2ap_CauseE2node (pctxt, pvalue->u.e2Node);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2Node);
            pvalue->u.e2Node = 0;
         }
         break;
      case 4:
         if (pvalue->u.transport) {
            asn1Free_e2ap_CauseTransport (pctxt, pvalue->u.transport);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.transport);
            pvalue->u.transport = 0;
         }
         break;
      case 5:
         if (pvalue->u.protocol) {
            asn1Free_e2ap_CauseProtocol (pctxt, pvalue->u.protocol);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.protocol);
            pvalue->u.protocol = 0;
         }
         break;
      case 6:
         if (pvalue->u.misc) {
            asn1Free_e2ap_CauseMisc (pctxt, pvalue->u.misc);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.misc);
            pvalue->u.misc = 0;
         }
         break;
      case 7:
         if (pvalue->u.serviceLayer) {
            asn1Free_e2ap_CauseServiceLayer (pctxt, pvalue->u.serviceLayer);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.serviceLayer);
            pvalue->u.serviceLayer = 0;
         }
         break;
   }
}


// --- End of e2ap_Cause.c ---

// --- Begin of e2ap_TimeToWait.c ---
/******************************************************/
/*                                                    */
/*    TimeToWait                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_TimeToWait_ENUMTAB[] = {
    { OSUTF8("v1s"), 0, 3, 0 },
    { OSUTF8("v2s"), 1, 3, 1 },
    { OSUTF8("v5s"), 2, 3, 2 },
    { OSUTF8("v10s"), 3, 4, 3 },
    { OSUTF8("v20s"), 4, 4, 4 },
    { OSUTF8("v60s"), 5, 4, 5 }
};


const OSUTF8CHAR* e2ap_TimeToWait_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_TimeToWait_ENUMTABSIZE){
      return e2ap_TimeToWait_ENUMTAB[e2ap_TimeToWait_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_TimeToWait_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_TimeToWait* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_TimeToWait_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_TimeToWait_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_TimeToWait* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_TimeToWait_ENUMTAB, e2ap_TimeToWait_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_TimeToWait)e2ap_TimeToWait_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_TimeToWait (OSCTXT* pctxt, e2ap_TimeToWait value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "TimeToWait");
   if (value >= 6) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(5));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_TimeToWait (OSCTXT* pctxt, e2ap_TimeToWait* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "TimeToWait");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(5));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_TimeToWait (const char* name, e2ap_TimeToWait* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = v1s", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = v2s", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = v5s", buffer, bufSize);
         break;
      case 3:
         stat = rtPrintToString(" = v10s", buffer, bufSize);
         break;
      case 4:
         stat = rtPrintToString(" = v20s", buffer, bufSize);
         break;
      case 5:
         stat = rtPrintToString(" = v60s", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_TimeToWait.c ---

// --- Begin of e2ap_ProcedureCode.c ---
/*****************************************/
/*         ProcedureCode     */
/*****************************************/
//interger no ext

EXTERN int asn1PE_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "ProcedureCode");
   stat = pe_ConsUnsigned (pctxt, value, 0, 255);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "ProcedureCode");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 8);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_ProcedureCode (const char* name, e2ap_ProcedureCode* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_ProcedureCode.c ---

// --- Begin of e2ap_TriggeringMessage.c ---
/******************************************************/
/*                                                    */
/*    TriggeringMessage                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_TriggeringMessage_ENUMTAB[] = {
    { OSUTF8("initiating_message"), 0, 18, 0 },
    { OSUTF8("successful_outcome"), 1, 18, 1 },
    { OSUTF8("unsuccessfull_outcome"), 2, 21, 2 }
};


const OSUTF8CHAR* e2ap_TriggeringMessage_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_TriggeringMessage_ENUMTABSIZE){
      return e2ap_TriggeringMessage_ENUMTAB[e2ap_TriggeringMessage_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_TriggeringMessage_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_TriggeringMessage* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_TriggeringMessage_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_TriggeringMessage_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_TriggeringMessage* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_TriggeringMessage_ENUMTAB, e2ap_TriggeringMessage_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_TriggeringMessage)e2ap_TriggeringMessage_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_TriggeringMessage (OSCTXT* pctxt, e2ap_TriggeringMessage value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "TriggeringMessage");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_TriggeringMessage (OSCTXT* pctxt, e2ap_TriggeringMessage* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "TriggeringMessage");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_TriggeringMessage (const char* name, e2ap_TriggeringMessage* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = initiating_message", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = successful_outcome", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = unsuccessfull_outcome", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_TriggeringMessage.c ---

// --- Begin of e2ap_Criticality.c ---
/******************************************************/
/*                                                    */
/*    Criticality                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_Criticality_ENUMTAB[] = {
    { OSUTF8("reject"), 0, 6, 0 },
    { OSUTF8("ignore"), 1, 6, 1 },
    { OSUTF8("notify"), 2, 6, 2 }
};


const OSUTF8CHAR* e2ap_Criticality_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_Criticality_ENUMTABSIZE){
      return e2ap_Criticality_ENUMTAB[e2ap_Criticality_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_Criticality_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_Criticality* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_Criticality_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_Criticality_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_Criticality* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_Criticality_ENUMTAB, e2ap_Criticality_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_Criticality)e2ap_Criticality_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_Criticality (OSCTXT* pctxt, e2ap_Criticality value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "Criticality");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_Criticality (OSCTXT* pctxt, e2ap_Criticality* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "Criticality");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_Criticality (const char* name, e2ap_Criticality* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = reject", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = ignore", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = notify", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_Criticality.c ---

/******************************************/
/* File .c missing: e2ap_ricRequestorID.c */
/******************************************/

/*****************************************/
/* File .c missing: e2ap_ricInstanceID.c */
/*****************************************/

// --- Begin of e2ap_RICrequestID.c ---

/*****************************************/
/*           RICrequestID                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICrequestID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricRequestorID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricRequestorID");
   stat = asn1PE_e2ap_ricRequestorID (pctxt, &pvalue->ricRequestorID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ricInstanceID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricInstanceID");
   stat = asn1PE_e2ap_ricInstanceID (pctxt, &pvalue->ricInstanceID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);



   /*
   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   */

   if(extbit) {
      /*encode extension optional bits length */
      stat = pe_SmallLength(pctxt, pvalue->extElem1.count);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode optional bit*/
      stat = pe_OpenTypeExtBits(pctxt, &pvalue->extElem1);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode extension elements*/
      if (pvalue->extElem1.count > 0) {
         stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "RICrequestID");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 1; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field ricRequestorID */
   RTXCTXTPUSHELEMNAME(pctxt, "ricRequestorID");
      stat = asn1PD_e2ap_ricRequestorID (pctxt, &pvalue->ricRequestorID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ricInstanceID */
   RTXCTXTPUSHELEMNAME(pctxt, "ricInstanceID");
      stat = asn1PD_e2ap_ricInstanceID (pctxt, &pvalue->ricInstanceID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pdSmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFree(pctxt, poptbits);
            return LOG_RTERR(pctxt, stat);
         }
      }

      for(i_ = 0; i_ < bitcnt; i_++) {
         if(stat != 0) break;
         if(poptbits[i_]) {
            /*decode extension element*/
            stat = pd_OpenType (pctxt, &openType, &openType.numocts);

            if(0==stat){
               pOpenType = rtxMemAllocType(pctxt, ASN1OpenType);
               if(0!=pOpenType){
                  pOpenType->numocts = openType.numocts;
                  pOpenType->data = openType.data;
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_RICrequestID (e2ap_RICrequestID* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_ricRequestorID (&pvalue->ricRequestorID);
   asn1Init_e2ap_ricInstanceID (&pvalue->ricInstanceID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_ricRequestorID (pctxt, &pvalue->ricRequestorID);
   asn1Free_e2ap_ricInstanceID (pctxt, &pvalue->ricInstanceID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICrequestID (const char* name, e2ap_RICrequestID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ricRequestorID ("ricRequestorID", &pvalue->ricRequestorID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ricInstanceID ("ricInstanceID", &pvalue->ricInstanceID, buffer, bufSize) < 0)
   {
      return -1;
   }

   /*assum there is an extension*/
   if(rtPrintToStringOpenTypeExtBraceText("extElem1", &pvalue->extElem1, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RICrequestID.c ---

/************************************/
/* File .c missing: e2ap_SEQUENCE.c */
/************************************/

// --- Begin of e2ap_CriticalityDiagnostics_IE_List.c ---

/*****************************************/
/*           CriticalityDiagnostics-IE-List                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "CriticalityDiagnostics-IE-List");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field iECriticality */  

   RTXCTXTPUSHELEMNAME(pctxt, "iECriticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->iECriticality);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field iE_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "iE-ID");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->iE_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field typeOfError */  

   RTXCTXTPUSHELEMNAME(pctxt, "typeOfError");
   stat = asn1PE_e2ap_TypeOfError (pctxt, &pvalue->typeOfError);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);



   /*
   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   */

   if(extbit) {
      /*encode extension optional bits length */
      stat = pe_SmallLength(pctxt, pvalue->extElem1.count);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode optional bit*/
      stat = pe_OpenTypeExtBits(pctxt, &pvalue->extElem1);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode extension elements*/
      if (pvalue->extElem1.count > 0) {
         stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "CriticalityDiagnostics-IE-List");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 1; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field iECriticality */
   RTXCTXTPUSHELEMNAME(pctxt, "iECriticality");
      stat = asn1PD_e2ap_Criticality (pctxt, &pvalue->iECriticality);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field iE_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "iE-ID");
      stat = asn1PD_e2ap_ProtocolIE_ID (pctxt, &pvalue->iE_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field typeOfError */
   RTXCTXTPUSHELEMNAME(pctxt, "typeOfError");
      stat = asn1PD_e2ap_TypeOfError (pctxt, &pvalue->typeOfError);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pdSmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFree(pctxt, poptbits);
            return LOG_RTERR(pctxt, stat);
         }
      }

      for(i_ = 0; i_ < bitcnt; i_++) {
         if(stat != 0) break;
         if(poptbits[i_]) {
            /*decode extension element*/
            stat = pd_OpenType (pctxt, &openType, &openType.numocts);

            if(0==stat){
               pOpenType = rtxMemAllocType(pctxt, ASN1OpenType);
               if(0!=pOpenType){
                  pOpenType->numocts = openType.numocts;
                  pOpenType->data = openType.data;
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_CriticalityDiagnostics_IE_List (e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_Criticality (&pvalue->iECriticality);
   asn1Init_e2ap_ProtocolIE_ID (&pvalue->iE_ID);
   asn1Init_e2ap_TypeOfError (&pvalue->typeOfError);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_Criticality (pctxt, &pvalue->iECriticality);
   asn1Free_e2ap_ProtocolIE_ID (pctxt, &pvalue->iE_ID);
   asn1Free_e2ap_TypeOfError (pctxt, &pvalue->typeOfError);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_CriticalityDiagnostics_IE_List (const char* name, e2ap_CriticalityDiagnostics_IE_List* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_Criticality ("iECriticality", &pvalue->iECriticality, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ProtocolIE_ID ("iE_ID", &pvalue->iE_ID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_TypeOfError ("typeOfError", &pvalue->typeOfError, buffer, bufSize) < 0)
   {
      return -1;
   }

   /*assum there is an extension*/
   if(rtPrintToStringOpenTypeExtBraceText("extElem1", &pvalue->extElem1, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_CriticalityDiagnostics_IE_List.c ---

// --- Begin of e2ap_CriticalityDiagnostics.c ---

/*****************************************/
/*           CriticalityDiagnostics                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "CriticalityDiagnostics");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field procedureCode */  
   if (pvalue->m_procedureCodePresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "procedureCode");
   stat = asn1PE_e2ap_ProcedureCode (pctxt, &pvalue->procedureCode);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field triggeringMessage */  
   if (pvalue->m_triggeringMessagePresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "triggeringMessage");
   stat = asn1PE_e2ap_TriggeringMessage (pctxt, &pvalue->triggeringMessage);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field procedureCriticality */  
   if (pvalue->m_procedureCriticalityPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "procedureCriticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->procedureCriticality);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricRequestorID */  
   if (pvalue->m_ricRequestorIDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricRequestorID");
   stat = asn1PE_e2ap_RICrequestID (pctxt, &pvalue->ricRequestorID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field iEsCriticalityDiagnostics */  
   if (pvalue->m_iEsCriticalityDiagnosticsPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "iEsCriticalityDiagnostics");
   stat = asn1PE_e2ap_CriticalityDiagnostics_IE_List (pctxt, &pvalue->iEsCriticalityDiagnostics);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }


   /*
   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   */

   if(extbit) {
      /*encode extension optional bits length */
      stat = pe_SmallLength(pctxt, pvalue->extElem1.count);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode optional bit*/
      stat = pe_OpenTypeExtBits(pctxt, &pvalue->extElem1);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode extension elements*/
      if (pvalue->extElem1.count > 0) {
         stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "CriticalityDiagnostics");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 1; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field procedureCode */
   RTXCTXTPUSHELEMNAME(pctxt, "procedureCode");
   if (optbits[0]) {
      pvalue->m_procedureCodePresent = TRUE;
      stat = asn1PD_e2ap_ProcedureCode (pctxt, &pvalue->procedureCode);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_procedureCodePresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field triggeringMessage */
   RTXCTXTPUSHELEMNAME(pctxt, "triggeringMessage");
   if (optbits[0]) {
      pvalue->m_triggeringMessagePresent = TRUE;
      stat = asn1PD_e2ap_TriggeringMessage (pctxt, &pvalue->triggeringMessage);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_triggeringMessagePresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field procedureCriticality */
   RTXCTXTPUSHELEMNAME(pctxt, "procedureCriticality");
   if (optbits[0]) {
      pvalue->m_procedureCriticalityPresent = TRUE;
      stat = asn1PD_e2ap_Criticality (pctxt, &pvalue->procedureCriticality);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_procedureCriticalityPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricRequestorID */
   RTXCTXTPUSHELEMNAME(pctxt, "ricRequestorID");
   if (optbits[0]) {
      pvalue->m_ricRequestorIDPresent = TRUE;
      stat = asn1PD_e2ap_RICrequestID (pctxt, &pvalue->ricRequestorID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricRequestorIDPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field iEsCriticalityDiagnostics */
   RTXCTXTPUSHELEMNAME(pctxt, "iEsCriticalityDiagnostics");
   if (optbits[0]) {
      pvalue->m_iEsCriticalityDiagnosticsPresent = TRUE;
      stat = asn1PD_e2ap_CriticalityDiagnostics_IE_List (pctxt, &pvalue->iEsCriticalityDiagnostics);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_iEsCriticalityDiagnosticsPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pdSmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFree(pctxt, poptbits);
            return LOG_RTERR(pctxt, stat);
         }
      }

      for(i_ = 0; i_ < bitcnt; i_++) {
         if(stat != 0) break;
         if(poptbits[i_]) {
            /*decode extension element*/
            stat = pd_OpenType (pctxt, &openType, &openType.numocts);

            if(0==stat){
               pOpenType = rtxMemAllocType(pctxt, ASN1OpenType);
               if(0!=pOpenType){
                  pOpenType->numocts = openType.numocts;
                  pOpenType->data = openType.data;
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_CriticalityDiagnostics (e2ap_CriticalityDiagnostics* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_ProcedureCode (&pvalue->procedureCode);
   asn1Init_e2ap_TriggeringMessage (&pvalue->triggeringMessage);
   asn1Init_e2ap_Criticality (&pvalue->procedureCriticality);
   asn1Init_e2ap_RICrequestID (&pvalue->ricRequestorID);
   asn1Init_e2ap_CriticalityDiagnostics_IE_List (&pvalue->iEsCriticalityDiagnostics);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_ProcedureCode (pctxt, &pvalue->procedureCode);
   asn1Free_e2ap_TriggeringMessage (pctxt, &pvalue->triggeringMessage);
   asn1Free_e2ap_Criticality (pctxt, &pvalue->procedureCriticality);
   asn1Free_e2ap_RICrequestID (pctxt, &pvalue->ricRequestorID);
   asn1Free_e2ap_CriticalityDiagnostics_IE_List (pctxt, &pvalue->iEsCriticalityDiagnostics);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_CriticalityDiagnostics (const char* name, e2ap_CriticalityDiagnostics* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ProcedureCode ("procedureCode", &pvalue->procedureCode, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_TriggeringMessage ("triggeringMessage", &pvalue->triggeringMessage, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_Criticality ("procedureCriticality", &pvalue->procedureCriticality, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICrequestID ("ricRequestorID", &pvalue->ricRequestorID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_CriticalityDiagnostics_IE_List ("iEsCriticalityDiagnostics", &pvalue->iEsCriticalityDiagnostics, buffer, bufSize) < 0)
   {
      return -1;
   }

   /*assum there is an extension*/
   if(rtPrintToStringOpenTypeExtBraceText("extElem1", &pvalue->extElem1, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_CriticalityDiagnostics.c ---

/*********************************************************/
/* File .c missing: e2ap_E2connectionUpdateFailure_IEs.c */
/*********************************************************/

// --- Begin of e2ap_E2connectionUpdateFailure.c ---

/*****************************************/
/*           E2connectionUpdateFailure                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2connectionUpdateFailure (OSCTXT* pctxt, e2ap_E2connectionUpdateFailure* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2connectionUpdateFailure");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field protocolIEs */  

   RTXCTXTPUSHELEMNAME(pctxt, "protocolIEs");
   stat = asn1PE_e2ap_ProtocolIE_Container (pctxt, &pvalue->protocolIEs);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);



   /*
   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   */

   if(extbit) {
      /*encode extension optional bits length */
      stat = pe_SmallLength(pctxt, pvalue->extElem1.count);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode optional bit*/
      stat = pe_OpenTypeExtBits(pctxt, &pvalue->extElem1);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode extension elements*/
      if (pvalue->extElem1.count > 0) {
         stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2connectionUpdateFailure (OSCTXT* pctxt, e2ap_E2connectionUpdateFailure* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "E2connectionUpdateFailure");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 1; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field protocolIEs */
   RTXCTXTPUSHELEMNAME(pctxt, "protocolIEs");
      stat = asn1PD_e2ap_ProtocolIE_Container (pctxt, &pvalue->protocolIEs);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pdSmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFree(pctxt, poptbits);
            return LOG_RTERR(pctxt, stat);
         }
      }

      for(i_ = 0; i_ < bitcnt; i_++) {
         if(stat != 0) break;
         if(poptbits[i_]) {
            /*decode extension element*/
            stat = pd_OpenType (pctxt, &openType, &openType.numocts);

            if(0==stat){
               pOpenType = rtxMemAllocType(pctxt, ASN1OpenType);
               if(0!=pOpenType){
                  pOpenType->numocts = openType.numocts;
                  pOpenType->data = openType.data;
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_E2connectionUpdateFailure (e2ap_E2connectionUpdateFailure* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_ProtocolIE_Container (&pvalue->protocolIEs);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2connectionUpdateFailure (OSCTXT* pctxt, e2ap_E2connectionUpdateFailure* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_ProtocolIE_Container (pctxt, &pvalue->protocolIEs);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2connectionUpdateFailure (const char* name, e2ap_E2connectionUpdateFailure* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ProtocolIE_Container ("protocolIEs", &pvalue->protocolIEs, buffer, bufSize) < 0)
   {
      return -1;
   }

   /*assum there is an extension*/
   if(rtPrintToStringOpenTypeExtBraceText("extElem1", &pvalue->extElem1, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_E2connectionUpdateFailure.c ---

// --- Begin of e2ap_E2connectionUpdateFailure_protocolIEs.c ---
/******************************************************/
/*                                                    */
/*    E2connectionUpdateFailure_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

EXTERN int asn1PE_e2ap_E2connectionUpdateFailure_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateFailure_protocolIEst* pvalue)
{
    int stat =0;
    OSRTDListNode* pnode;
    OSUINT32 xx1;

    /*encode length determinant */
    PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(0), OSUINTCONST(ASN1V_e2ap_maxProtocolIEs), 0, 0);
    stat = pe_Length(pctxt, pvalue->count);
    if(stat!=0) return LOG_RTERR(pctxt, stat);

    /*encode each element*/
    xx1 =0;
    for(pnode = pvalue->head; pnode != 0 && xx1<pvalue->count; pnode = pnode->next){
        RTXCTXTPUSHARRAYELEMNAME(pctxt, "SEQUENCE", xx1);
        stat = asn1PE_e2ap_E2connectionUpdateFailure_protocolIEs_element (pctxt, ((e2ap_E2connectionUpdateFailure_protocolIEs_element*)pnode->data));
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        xx1++;
        RTXCTXTPOPARRAYELEMNAME(pctxt);
    }

    return (stat);
}

EXTERN int  asn1PD_e2ap_E2connectionUpdateFailure_protocolIEs(OSCTXT* pctxt, e2ap_E2connectionUpdateFailure_protocolIEs* pvalue)
{
     int stat =0;
     OSRTDListNode* pnode;
     OSSIZE count =0;
     OSSIZE xx1=0;


     /*decode length determinant */
    PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(0), OSUINTCONST(ASN1V_e2ap_maxProtocolIEs), 0, 0);
    stat = pd_Length64(pctxt, &count); //tai sao lai 64
    if(stat!=0) return LOG_RTERR(pctxt, stat);

    /*decode each element*/
    rtxDListInit(pvalue);

    for(xx1=0; xx1 < count; xx1++){
        e2ap_E2connectionUpdateFailure_protocolIEs_element* pdata;
        RTXCTXTPUSHARRAYELEMNAME(pctxt, "SEQUENCE", &pnode, &pdata);

        if(pnode == NULL) return LOG_RTERR(pctxt, RTERR_NOMEM);

        asn1Init_e2ap_E2connectionUpdateFailure_protocolIEs_element(pdata);
        rtxDListAppendNode(pvalue, pnode);
       // stat = asn1PD_e2ap_E2connectionUpdateFailure_protocolIEs_element (pctxt, pdata);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        RTXCTXTPOPARRAYELEMNAME(pctxt);

    }
    return (stat);
}


int asn1Init_e2ap_E2connectionUpdateFailure_protocolIEs(e2ap_E2connectionUpdateFailure_protocolIEs* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    rtxDListFastInit (pvalue);
    return 0;
}

void asn1Free_e2ap_E2connectionUpdateFailure_protocolIEs(OSCTXT* pctxt, e2ap_E2connectionUpdateFailure_protocolIEs* pvalue)
{
    if(0==pvalue) return;   
    e2ap_E2connectionUpdateFailure_protocolIEs_element* pdata;
    OSRTDListNode* pnode=pvalue->head;
    while(0!=pnode){
        pdata = (e2ap_E2connectionUpdateFailure_protocolIEs_element*)pnode->data;
       // asn1Free_e2ap_E2connectionUpdateFailure_protocolIEs_element(pctxt, pdata);
        pnode = pnode->next;
    }
    rtxDListFreeAll(pctxt, pvalue);
}

// --- End of e2ap_E2connectionUpdateFailure_protocolIEs.c ---

// --- Begin of e2ap_E2connectionUpdateFailure_protocolIEs_element.c ---
/*****************************************/
/*    E2connectionUpdateFailure_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe

EXTERN int asn1PE_e2ap_E2connectionUpdateFailure_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdateFailure_protocolIEs_element* pvalue)
{
    int stat =0;

    /*encode id*/

    RTXCTXTPUSHELEMNAME(pctxt, "id");
        stat = asn1PE_e2ap_ProtocolIE_ID(pctxt, &pvalue->id);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*encode criticality*/
    RTXCTXTPUSHELEMNAME(pctxt, "criticality");
        stat = asn1PE_e2ap_Criticality(pctxt, &pvalue->criticality);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*encode value*/
    RTXCTXTPUSHELEMNAME(pctxt, "value");
        
    {
        OSCTXT lctxt;
        OSOCTET *pDynamicEncodeBuffer;
        ASN1OpenType openType;
        OSBOOL encoded = TRUE;

        openType.numocts = 0;
        openType.data =0;

        rtxCopyContext(&lctxt, pctxt);
        pctxt->pStream =0;

        stat = rtxInitContextBuffer(pctxt, 0, 0);
        if(stat!=0) return LOG_RTERR(pctxt, stat);

        switch(pvalue->value.t){
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_TransactionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "TransactionID");

                stat = asn1PE_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2SetupRequestIEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_Cause:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "Cause");

                stat = asn1PE_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2SetupRequestIEs_id_Cause);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_TimeToWait:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "TimeToWait");

                stat = asn1PE_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2SetupRequestIEs_id_TimeToWait);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_CriticalityDiagnostics:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "CriticalityDiagnostics");

                stat = asn1PE_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2SetupRequestIEs_id_CriticalityDiagnostics);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_UNDEF_:
            {
                if(0!=pvalue->value.u.extElem1){
                    openType.numocts = pvalue->value.u.extElem1->numocts;
                    openType.data = pvalue->value.u.extElem1->data;
                } else {
                    /* No extension element to encode */
                }
                encoded = FALSE;
                break;
            }

            default:
                encoded = FALSE;
                stat = RTERR_INVOPT;
                break;
        } 

        if(encoded){
            openType.numocts = (OSUINT32)pe_GetMsgLen(pctxt);
            openType.data = pDynamicEncodeBuffer = pctxt -> buffer.data;
        }
        rtxCopyContext(pctxt, &lctxt);

        if(stat == 0) {
            stat = pe_OpenType (pctxt, openType.numocts, openType.data);
        }

        if(decoded){
            rtxMemFreePtr(pctxt, pDynamicEncodeBuffer);
        }

    }

    if(stat!=0) return LOG_RTERR(pctxt, stat);  
    RTXCTXTPOPELEMNAME(pctxt);
    return (stat);

}

EXTERN int  asn1PD_e2ap_E2connectionUpdateFailure_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdateFailure_protocolIEs_element* pvalue){
    int stat =0;

    /*decode id*/
    RTXCTXTPUSHELEMNAME(pctxt, "id");
        stat = asn1PD_e2ap_ProtocolIE_ID(pctxt, &pvalue->id);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*decode criticality*/
    RTXCTXTPUSHELEMNAME(pctxt, "criticality");
        stat = asn1PD_e2ap_Criticality(pctxt, &pvalue->criticality);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*decode value*/
    RTXCTXTPUSHELEMNAME(pctxt, "value");

    {
        OSUINT32 openTypeLen;
        size_t bitStartOffset, bitLength;

        stat = pd_UnconsLength(pctxt, &openTypeLen);
        if(stat<0) return LOG_RTERR(pctxt, stat);
        else if(stat == RT_OK_FRAG){
            rtxErrAddStrParm(pctxt, "open type with fragment length");
            return LOG_RTERRNEW(pctxt, RTERR_NOTSUPP);
        }
        bitStartOffset = PU_GETCTXBITOFFSET(pctxt);
        bitLength = openTypeLen * 8;

        switch(pvalue->id){
        
            case ASN1V_e2ap_id:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_TransactionID;
            RTXCTXTPUSHELEMNAME(pctxt, "TransactionID");
            pvalue->value.u._e2ap_E2connectionUpdateFailure_IEs_id_TransactionID 
                = rtxMemAllocType(pctxt, e2ap_TransactionID);

            asn1Init_e2ap_TransactionID(pvalue->
                value.u._e2ap_E2connectionUpdateFailure_IEs_id_TransactionID);

            stat = asn1PD_e2ap_TransactionID (pctxt,
                (e2ap_TransactionID*)pvalue->value.
                u._e2ap_E2connectionUpdateFailure_IEs_id_TransactionID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_Cause;
            RTXCTXTPUSHELEMNAME(pctxt, "Cause");
            pvalue->value.u._e2ap_E2connectionUpdateFailure_IEs_id_Cause 
                = rtxMemAllocType(pctxt, e2ap_Cause);

            asn1Init_e2ap_Cause(pvalue->
                value.u._e2ap_E2connectionUpdateFailure_IEs_id_Cause);

            stat = asn1PD_e2ap_Cause (pctxt,
                (e2ap_Cause*)pvalue->value.
                u._e2ap_E2connectionUpdateFailure_IEs_id_Cause);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_TimeToWait;
            RTXCTXTPUSHELEMNAME(pctxt, "TimeToWait");
            pvalue->value.u._e2ap_E2connectionUpdateFailure_IEs_id_TimeToWait 
                = rtxMemAllocType(pctxt, e2ap_TimeToWait);

            asn1Init_e2ap_TimeToWait(pvalue->
                value.u._e2ap_E2connectionUpdateFailure_IEs_id_TimeToWait);

            stat = asn1PD_e2ap_TimeToWait (pctxt,
                (e2ap_TimeToWait*)pvalue->value.
                u._e2ap_E2connectionUpdateFailure_IEs_id_TimeToWait);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_CriticalityDiagnostics;
            RTXCTXTPUSHELEMNAME(pctxt, "CriticalityDiagnostics");
            pvalue->value.u._e2ap_E2connectionUpdateFailure_IEs_id_CriticalityDiagnostics 
                = rtxMemAllocType(pctxt, e2ap_CriticalityDiagnostics);

            asn1Init_e2ap_CriticalityDiagnostics(pvalue->
                value.u._e2ap_E2connectionUpdateFailure_IEs_id_CriticalityDiagnostics);

            stat = asn1PD_e2ap_CriticalityDiagnostics (pctxt,
                (e2ap_CriticalityDiagnostics*)pvalue->value.
                u._e2ap_E2connectionUpdateFailure_IEs_id_CriticalityDiagnostics);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    

        default:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_UNDEF_;
            pvalue->value.u.extElem1 = rtxMemAllocType(pctxt, ASN1OpenType);
            if(0==pvalue->value.u.extElem1){
                return LOG_RTERR(pctxt, RTERR_NOMEM);
            }

            {
                OSOCTET *pdata =(OSOCTET*) rtxMemAlloc(pctxt, openTypeLen);
                if(0==pdata){
                    return LOG_RTERR(pctxt, RTERR_NOMEM);
                }
                stat = rtxDecBitsToByteArray(pctxt, pdata, openTypeLen, openTypeLen*8);
                if(stat!=0){
                    rtxMemFreePtr(pctxt, pdata);
                    rtxMemFreePtr(pctxt, pvalue->value.u.extElem1);
                    return LOG_RTERR(pctxt, stat);
                }

                pvalue->value.u.extElem1->numocts = openTypeLen;
                pvalue->value.u.extElem1->data = pdata;
            }
            break;
    }
    {
    size_t bitEndOffset = PU_GETCTXBITOFFSET(pctxt);
    size_t bitsConsumed = bitEndOffset-bitStartOffset;
    if(bitsConsumed<bitLength){
        stat = pd_moveBitCursor(pctxt, (int)(bitLength - bitsConsumed));
    }
    else stat =(bitsConsumed > bitLength) ? ASN_E_INVLEN : 0;
    }}
    if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);
    return (stat);

}


int asn1Init_e2ap_E2connectionUpdateFailure_protocolIEs_element(e2ap_E2connectionUpdateFailure_protocolIEs_element* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    OSCRTLMEMSET (&pvalue->value, 0, sizeof(pvalue->value));
    return 0;
}

void free_e2ap_E2connectionUpdateFailure_protocolIEs_element(e2ap_E2connectionUpdateFailure_protocolIEs_element* pvalue)
{
    if(NULL==pvalue) return;
    switch(pvalue->value.t){
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_TransactionID:
            rtxFreeE2ap_TransactionID(pvalue->value.u._e2ap_E2connectionUpdateFailure_IEs_id_TransactionID);
            break;
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_Cause:
            rtxFreeE2ap_Cause(pvalue->value.u._e2ap_E2connectionUpdateFailure_IEs_id_Cause);
            break;
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_TimeToWait:
            rtxFreeE2ap_TimeToWait(pvalue->value.u._e2ap_E2connectionUpdateFailure_IEs_id_TimeToWait);
            break;
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_CriticalityDiagnostics:
            rtxFreeE2ap_CriticalityDiagnostics(pvalue->value.u._e2ap_E2connectionUpdateFailure_IEs_id_CriticalityDiagnostics);
            break;
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_UNDEF_:
            rtxFreeASN1OpenType(pvalue->value.u.extElem1);
            break;
        default:
            break;
    }
}

int asn1PrtToStr_e2ap_E2connectionUpdateFailure_protocolIEs_element(OSCTXT* pctxt, e2ap_E2connectionUpdateFailure_protocolIEs_element* pvalue)
{
    int stat =0;
    RTXCTXTPUSHELEMNAME(pctxt, "e2ap_E2connectionUpdateFailure_protocolIEs_element");

    /*print id*/
    RTXCTXTPUSHELEMNAME(pctxt, "id");
        stat = asn1PrtToStr_e2ap_ProtocolIE_ID(pctxt, &pvalue->id);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*print criticality*/
    RTXCTXTPUSHELEMNAME(pctxt, "criticality");
        stat = asn1PrtToStr_e2ap_Criticality(pctxt, &pvalue->criticality);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*print value*/
    RTXCTXTPUSHELEMNAME(pctxt, "value");
        
        switch(pvalue->value.t){
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_TransactionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "TransactionID");

                stat = asn1PrtToStr_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2connectionUpdateFailure_IEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_Cause:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "Cause");

                stat = asn1PrtToStr_e2ap_Cause (pctxt, pvalue->value.u._e2ap_E2connectionUpdateFailure_IEs_id_Cause);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_TimeToWait:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "TimeToWait");

                stat = asn1PrtToStr_e2ap_TimeToWait (pctxt, pvalue->value.u._e2ap_E2connectionUpdateFailure_IEs_id_TimeToWait);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_id_CriticalityDiagnostics:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "CriticalityDiagnostics");

                stat = asn1PrtToStr_e2ap_CriticalityDiagnostics (pctxt, pvalue->value.u._e2ap_E2connectionUpdateFailure_IEs_id_CriticalityDiagnostics);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateFailure_IEs_UNDEF_:
            {
                rtxPLogMsg(pctxt, "Extension element present - raw data not printed.\n");
                break;
            }

            default:
                stat = RTERR_INVOPT;
                return LOG_RTERR(pctxt, stat);
        }
    RTXCTXTPOPELEMNAME(pctxt);
    return (stat);
}
// --- End of e2ap_E2connectionUpdateFailure_protocolIEs_element.c ---

