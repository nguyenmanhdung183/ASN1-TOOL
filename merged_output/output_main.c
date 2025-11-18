// --- Begin of e2ap_TransactionID.c ---
/* e2ap_TransactionID.c */
#include "e2ap_TransactionID.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value)
{
   RTXCTXPUSHTYPENAME (pctxt, "TransactionID");
   OSBOOL exbit = (value > 255.0) ? TRUE : FALSE;
   int stat = rtxEncBit (pctxt, exbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!exbit) {
      stat = pe_ConsUnsigned (pctxt, value, 0.0, 255.0);
   } else {
      stat = pe_UnconsUnsigned (pctxt, value);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "TransactionID");
   stat = rtxDecBit (pctxt, &extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!extbit) {
      stat = pd_ConsUnsigned (pctxt, pvalue, 0.0, 255.0);
   } else {
      stat = pd_UnconsUnsigned (pctxt, pvalue);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

EXTERN int asn1PrtToStr_e2ap_TransactionID (const char* name, e2ap_TransactionID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_TransactionID.c ---

/******************************************/
/* File .c missing: e2ap_ricRequestorID.c */
/******************************************/

/*****************************************/
/* File .c missing: e2ap_ricInstanceID.c */
/*****************************************/

// --- Begin of e2ap_RICrequestID.c ---

int asn1PE_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "RICrequestID");

   stat = asn1PE_e2ap_ricRequestorID (pctxt, &pvalue->ricRequestorID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_ricInstanceID (pctxt, &pvalue->ricInstanceID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "RICrequestID");

   stat = asn1PD_e2ap_ricRequestorID (pctxt, &pvalue->ricRequestorID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_ricInstanceID (pctxt, &pvalue->ricInstanceID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_RICrequestID (e2ap_RICrequestID* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_ricRequestorID (&pvalue->ricRequestorID);
   asn1Init_e2ap_ricInstanceID (&pvalue->ricInstanceID);
}

void asn1Free_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue)
{
   %}
   asn1Free_e2ap_ricRequestorID (pctxt, &pvalue->ricRequestorID);
   %}
   asn1Free_e2ap_ricInstanceID (pctxt, &pvalue->ricInstanceID);
}
// --- End of e2ap_RICrequestID.c ---

// --- Begin of e2ap_RANfunctionID.c ---
/* e2ap_RANfunctionID.c */
#include "e2ap_RANfunctionID.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionID");
   stat = pe_ConsUnsigned (pctxt, value, 0.0, 4095.0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionID");
   if (pctxt->buffer.aligned) {
      int stat2 = pd_ByteAlign (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 16);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RANfunctionID (const char* name, e2ap_RANfunctionID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RANfunctionID.c ---

// --- Begin of e2ap_CauseRICrequest.c ---
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
// --- End of e2ap_CauseRICrequest.c ---

// --- Begin of e2ap_CauseRICservice.c ---
/* e2ap_CauseRICservice.c */
#include "e2ap_CauseRICservice.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_CauseRICservice_ENUMTAB[e2ap_CauseRICservice_ENUMTABSIZE] = {
   { OSUTF8("ran_function_not_supported"), 0, 26,  },   { OSUTF8("excessive_functions"), 1, 19,  },   { OSUTF8("ric_resource_limit"), 2, 18,  }};

EXTERN int asn1PE_e2ap_CauseRICservice (OSCTXT* pctxt, e2ap_CauseRICservice value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseRICservice");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_CauseRICservice (OSCTXT* pctxt, e2ap_CauseRICservice* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseRICservice");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseRICservice (const char* name, e2ap_CauseRICservice* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_CauseRICservice_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_CauseRICservice_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}
// --- End of e2ap_CauseRICservice.c ---

// --- Begin of e2ap_CauseE2node.c ---
/* e2ap_CauseE2node.c */
#include "e2ap_CauseE2node.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_CauseE2node_ENUMTAB[e2ap_CauseE2node_ENUMTABSIZE] = {
   { OSUTF8("e2node_component_unknown"), 0, 24,  }};

EXTERN int asn1PE_e2ap_CauseE2node (OSCTXT* pctxt, e2ap_CauseE2node value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseE2node");
   if (value >= 1) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(0));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_CauseE2node (OSCTXT* pctxt, e2ap_CauseE2node* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseE2node");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(0));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseE2node (const char* name, e2ap_CauseE2node* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_CauseE2node_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_CauseE2node_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}
// --- End of e2ap_CauseE2node.c ---

// --- Begin of e2ap_CauseTransport.c ---
/* e2ap_CauseTransport.c */
#include "e2ap_CauseTransport.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_CauseTransport_ENUMTAB[e2ap_CauseTransport_ENUMTABSIZE] = {
   { OSUTF8("unspecified"), 0, 11,  },   { OSUTF8("transport_resource_unavailable"), 1, 30,  }};

EXTERN int asn1PE_e2ap_CauseTransport (OSCTXT* pctxt, e2ap_CauseTransport value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseTransport");
   if (value >= 2) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(1));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_CauseTransport (OSCTXT* pctxt, e2ap_CauseTransport* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseTransport");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(1));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseTransport (const char* name, e2ap_CauseTransport* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_CauseTransport_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_CauseTransport_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}
// --- End of e2ap_CauseTransport.c ---

// --- Begin of e2ap_CauseProtocol.c ---
/* e2ap_CauseProtocol.c */
#include "e2ap_CauseProtocol.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_CauseProtocol_ENUMTAB[e2ap_CauseProtocol_ENUMTABSIZE] = {
   { OSUTF8("transfer_syntax_error"), 0, 21,  },   { OSUTF8("abstract_syntax_error_reject"), 1, 28,  },   { OSUTF8("abstract_syntax_error_ignore_and_notify"), 2, 39,  },   { OSUTF8("message_not_compatible_with_receiver_state"), 3, 42,  },   { OSUTF8("©2025bytheO_RANALLIANCEe.V.Youruseissubjecttothecopyrightstatementonthecoverpageofthisspecification.142O_RAN.WG3.TS.E2AP_R004_v07.00semantic_error"), 4, 146,  },   { OSUTF8("abstract_syntax_error_falsely_constructed_message"), 5, 49,  },   { OSUTF8("unspecified"), 6, 11,  }};

EXTERN int asn1PE_e2ap_CauseProtocol (OSCTXT* pctxt, e2ap_CauseProtocol value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseProtocol");
   if (value >= 7) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(6));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_CauseProtocol (OSCTXT* pctxt, e2ap_CauseProtocol* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseProtocol");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(6));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseProtocol (const char* name, e2ap_CauseProtocol* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_CauseProtocol_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_CauseProtocol_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}
// --- End of e2ap_CauseProtocol.c ---

// --- Begin of e2ap_CauseMisc.c ---
/* e2ap_CauseMisc.c */
#include "e2ap_CauseMisc.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_CauseMisc_ENUMTAB[e2ap_CauseMisc_ENUMTABSIZE] = {
   { OSUTF8("control_processing_overload"), 0, 27,  },   { OSUTF8("hardware_failure"), 1, 16,  },   { OSUTF8("om_intervention"), 2, 15,  },   { OSUTF8("unspecified"), 3, 11,  }};

EXTERN int asn1PE_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseMisc");
   if (value >= 4) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(3));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "CauseMisc");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(3));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseMisc (const char* name, e2ap_CauseMisc* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_CauseMisc_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_CauseMisc_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}
// --- End of e2ap_CauseMisc.c ---

// --- Begin of e2ap_ServiceLayerCause.c ---
/* e2ap_ServiceLayerCause.c */
#include "e2ap_ServiceLayerCause.h"
#include "rtxsrc/rtxErrCodes.h"

/* Dynamic OCTET STRING (no SIZE constraint) */
EXTERN int asn1PE_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "ServiceLayerCause");
   stat = pe_OctetString (pctxt, pvalue->numocts, pvalue->data);
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : 0;
}

EXTERN int asn1PD_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause** ppvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "ServiceLayerCause");
   stat = pd_DynOctetString (pctxt, (OSDynOctStr**)ppvalue);
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : 0;
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
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringHexStr (name, pvalue->numocts, pvalue->data, buffer, bufSize) < 0)
      return -1;
   return 0;
}
// --- End of e2ap_ServiceLayerCause.c ---

// --- Begin of e2ap_CauseServiceLayer.c ---

int asn1PE_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "CauseServiceLayer");

   stat = asn1PE_e2ap_ServiceLayerCause (pctxt, &pvalue->serviceLayerCause);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "CauseServiceLayer");

   stat = asn1PD_e2ap_ServiceLayerCause (pctxt, &pvalue->serviceLayerCause);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_CauseServiceLayer (e2ap_CauseServiceLayer* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_ServiceLayerCause (&pvalue->serviceLayerCause);
}

void asn1Free_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue)
{
   %}
   asn1Free_e2ap_ServiceLayerCause (pctxt, &pvalue->serviceLayerCause);
}
// --- End of e2ap_CauseServiceLayer.c ---

// --- Begin of e2ap_Cause.c ---
/* e2ap_Cause.c */

// choice
EXTERN int asn1PE_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "Cause");

   extbit = (OSBOOL)(pvalue->t > 3);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   if (extbit) {
      stat = pe_SmallNonNegWholeNumber (pctxt, pvalue->t - 4);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   } else {
      stat = rtxEncBits (pctxt, pvalue->t - 1, 2);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   switch (pvalue->t) {
      case 0.0:
         RTXCTXPUSHELEMNAME (pctxt, "ricRequest");
         stat = asn1PE_e2ap_CauseRICrequest (pctxt, pvalue->u.ricRequest);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "ricService");
         stat = asn1PE_e2ap_CauseRICservice (pctxt, pvalue->u.ricService);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2Node");
         stat = asn1PE_e2ap_CauseE2node (pctxt, pvalue->u.e2Node);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "transport");
         stat = asn1PE_e2ap_CauseTransport (pctxt, pvalue->u.transport);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 4.0:
         RTXCTXPUSHELEMNAME (pctxt, "protocol");
         stat = asn1PE_e2ap_CauseProtocol (pctxt, pvalue->u.protocol);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 5.0:
         RTXCTXPUSHELEMNAME (pctxt, "misc");
         stat = asn1PE_e2ap_CauseMisc (pctxt, pvalue->u.misc);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 6.0:
         RTXCTXPUSHELEMNAME (pctxt, "serviceLayer");
         stat = asn1PE_e2ap_CauseServiceLayer (pctxt, pvalue->u.serviceLayer);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_Cause (OSCTXT* pctxt, e2ap_Cause* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "Cause");

   stat = rtxDecBit (pctxt, &extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   if (extbit) {
      stat = pd_SmallNonNegWholeNumber (pctxt, &ui);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      pvalue->t = ui + 4;
   } else {
      pvalue->t = ui + 1;
   }

   switch (pvalue->t) {
      case 0.0:
         RTXCTXPUSHELEMNAME (pctxt, "ricRequest");
         pvalue->u.ricRequest = rtxMemAllocType (pctxt, e2ap_CauseRICrequest);
         if (pvalue->u.ricRequest == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_CauseRICrequest (pctxt, pvalue->u.ricRequest);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "ricService");
         pvalue->u.ricService = rtxMemAllocType (pctxt, e2ap_CauseRICservice);
         if (pvalue->u.ricService == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_CauseRICservice (pctxt, pvalue->u.ricService);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2Node");
         pvalue->u.e2Node = rtxMemAllocType (pctxt, e2ap_CauseE2node);
         if (pvalue->u.e2Node == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_CauseE2node (pctxt, pvalue->u.e2Node);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "transport");
         pvalue->u.transport = rtxMemAllocType (pctxt, e2ap_CauseTransport);
         if (pvalue->u.transport == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_CauseTransport (pctxt, pvalue->u.transport);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 4.0:
         RTXCTXPUSHELEMNAME (pctxt, "protocol");
         pvalue->u.protocol = rtxMemAllocType (pctxt, e2ap_CauseProtocol);
         if (pvalue->u.protocol == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_CauseProtocol (pctxt, pvalue->u.protocol);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 5.0:
         RTXCTXPUSHELEMNAME (pctxt, "misc");
         pvalue->u.misc = rtxMemAllocType (pctxt, e2ap_CauseMisc);
         if (pvalue->u.misc == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_CauseMisc (pctxt, pvalue->u.misc);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 6.0:
         RTXCTXPUSHELEMNAME (pctxt, "serviceLayer");
         pvalue->u.serviceLayer = rtxMemAllocType (pctxt, e2ap_CauseServiceLayer);
         if (pvalue->u.serviceLayer == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_CauseServiceLayer (pctxt, pvalue->u.serviceLayer);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
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
      case 0.0:
         if (pvalue->u.ricRequest) {
            asn1Free_e2ap_CauseRICrequest (pctxt, pvalue->u.ricRequest);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.ricRequest);
         }
         break;
      case 1.0:
         if (pvalue->u.ricService) {
            asn1Free_e2ap_CauseRICservice (pctxt, pvalue->u.ricService);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.ricService);
         }
         break;
      case 2.0:
         if (pvalue->u.e2Node) {
            asn1Free_e2ap_CauseE2node (pctxt, pvalue->u.e2Node);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2Node);
         }
         break;
      case 3.0:
         if (pvalue->u.transport) {
            asn1Free_e2ap_CauseTransport (pctxt, pvalue->u.transport);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.transport);
         }
         break;
      case 4.0:
         if (pvalue->u.protocol) {
            asn1Free_e2ap_CauseProtocol (pctxt, pvalue->u.protocol);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.protocol);
         }
         break;
      case 5.0:
         if (pvalue->u.misc) {
            asn1Free_e2ap_CauseMisc (pctxt, pvalue->u.misc);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.misc);
         }
         break;
      case 6.0:
         if (pvalue->u.serviceLayer) {
            asn1Free_e2ap_CauseServiceLayer (pctxt, pvalue->u.serviceLayer);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.serviceLayer);
         }
         break;
   }
   pvalue->t = 0;
}
// --- End of e2ap_Cause.c ---

// --- Begin of e2ap_ProcedureCode.c ---
/* e2ap_ProcedureCode.c */
#include "e2ap_ProcedureCode.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "ProcedureCode");
   stat = pe_ConsUnsigned (pctxt, value, 0.0, 255.0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "ProcedureCode");
   if (pctxt->buffer.aligned) {
      int stat2 = pd_ByteAlign (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 8);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
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
/* e2ap_TriggeringMessage.c */
#include "e2ap_TriggeringMessage.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_TriggeringMessage_ENUMTAB[e2ap_TriggeringMessage_ENUMTABSIZE] = {
   { OSUTF8("initiating_message"), 0, 18,  },   { OSUTF8("successful_outcome"), 1, 18,  },   { OSUTF8("unsuccessfull_outcome"), 2, 21,  }};

EXTERN int asn1PE_e2ap_TriggeringMessage (OSCTXT* pctxt, e2ap_TriggeringMessage value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "TriggeringMessage");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_TriggeringMessage (OSCTXT* pctxt, e2ap_TriggeringMessage* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "TriggeringMessage");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_TriggeringMessage (const char* name, e2ap_TriggeringMessage* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_TriggeringMessage_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_TriggeringMessage_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}
// --- End of e2ap_TriggeringMessage.c ---

// --- Begin of e2ap_Criticality.c ---
/* e2ap_Criticality.c */
#include "e2ap_Criticality.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_Criticality_ENUMTAB[e2ap_Criticality_ENUMTABSIZE] = {
   { OSUTF8("reject"), 0, 6,  },   { OSUTF8("ignore"), 1, 6,  },   { OSUTF8("notify"), 2, 6,  }};

EXTERN int asn1PE_e2ap_Criticality (OSCTXT* pctxt, e2ap_Criticality value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "Criticality");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_Criticality (OSCTXT* pctxt, e2ap_Criticality* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "Criticality");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_Criticality (const char* name, e2ap_Criticality* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_Criticality_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_Criticality_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}
// --- End of e2ap_Criticality.c ---

/************************************/
/* File .c missing: e2ap_SEQUENCE.c */
/************************************/

// --- Begin of e2ap_CriticalityDiagnostics_IE_List.c ---

int asn1PE_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "CriticalityDiagnostics_IE_List");

   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->iECriticality);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_ProtocolIE-ID (pctxt, &pvalue->iE_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_TypeOfError (pctxt, &pvalue->typeOfError);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "CriticalityDiagnostics_IE_List");

   stat = asn1PD_e2ap_Criticality (pctxt, &pvalue->iECriticality);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_ProtocolIE-ID (pctxt, &pvalue->iE_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_TypeOfError (pctxt, &pvalue->typeOfError);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_CriticalityDiagnostics_IE_List (e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_Criticality (&pvalue->iECriticality);
   asn1Init_e2ap_ProtocolIE-ID (&pvalue->iE_ID);
   asn1Init_e2ap_TypeOfError (&pvalue->typeOfError);
}

void asn1Free_e2ap_CriticalityDiagnostics_IE_List (OSCTXT* pctxt, e2ap_CriticalityDiagnostics_IE_List* pvalue)
{
   %}
   asn1Free_e2ap_Criticality (pctxt, &pvalue->iECriticality);
   %}
   asn1Free_e2ap_ProtocolIE-ID (pctxt, &pvalue->iE_ID);
   %}
   asn1Free_e2ap_TypeOfError (pctxt, &pvalue->typeOfError);
}
// --- End of e2ap_CriticalityDiagnostics_IE_List.c ---

// --- Begin of e2ap_CriticalityDiagnostics.c ---

int asn1PE_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "CriticalityDiagnostics");

   if (pvalue->m_procedureCodePresent) {
   stat = asn1PE_e2ap_ProcedureCode (pctxt, &pvalue->procedureCode);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_triggeringMessagePresent) {
   stat = asn1PE_e2ap_TriggeringMessage (pctxt, &pvalue->triggeringMessage);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_procedureCriticalityPresent) {
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->procedureCriticality);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_ricRequestorIDPresent) {
   stat = asn1PE_e2ap_RICrequestID (pctxt, &pvalue->ricRequestorID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_iEsCriticalityDiagnosticsPresent) {
   stat = asn1PE_e2ap_CriticalityDiagnostics-IE-List (pctxt, &pvalue->iEsCriticalityDiagnostics);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "CriticalityDiagnostics");

   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_procedureCodePresent = TRUE;
      stat = asn1PD_e2ap_ProcedureCode (pctxt, &pvalue->procedureCode);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_procedureCodePresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_triggeringMessagePresent = TRUE;
      stat = asn1PD_e2ap_TriggeringMessage (pctxt, &pvalue->triggeringMessage);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_triggeringMessagePresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_procedureCriticalityPresent = TRUE;
      stat = asn1PD_e2ap_Criticality (pctxt, &pvalue->procedureCriticality);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_procedureCriticalityPresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_ricRequestorIDPresent = TRUE;
      stat = asn1PD_e2ap_RICrequestID (pctxt, &pvalue->ricRequestorID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_ricRequestorIDPresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_iEsCriticalityDiagnosticsPresent = TRUE;
      stat = asn1PD_e2ap_CriticalityDiagnostics-IE-List (pctxt, &pvalue->iEsCriticalityDiagnostics);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_iEsCriticalityDiagnosticsPresent = FALSE;

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_CriticalityDiagnostics (e2ap_CriticalityDiagnostics* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_ProcedureCode (&pvalue->procedureCode);
   asn1Init_e2ap_TriggeringMessage (&pvalue->triggeringMessage);
   asn1Init_e2ap_Criticality (&pvalue->procedureCriticality);
   asn1Init_e2ap_RICrequestID (&pvalue->ricRequestorID);
   asn1Init_e2ap_CriticalityDiagnostics-IE-List (&pvalue->iEsCriticalityDiagnostics);
}

void asn1Free_e2ap_CriticalityDiagnostics (OSCTXT* pctxt, e2ap_CriticalityDiagnostics* pvalue)
{
   %}
   asn1Free_e2ap_ProcedureCode (pctxt, &pvalue->procedureCode);
   %}
   asn1Free_e2ap_TriggeringMessage (pctxt, &pvalue->triggeringMessage);
   %}
   asn1Free_e2ap_Criticality (pctxt, &pvalue->procedureCriticality);
   %}
   asn1Free_e2ap_RICrequestID (pctxt, &pvalue->ricRequestorID);
   %}
   asn1Free_e2ap_CriticalityDiagnostics-IE-List (pctxt, &pvalue->iEsCriticalityDiagnostics);
}
// --- End of e2ap_CriticalityDiagnostics.c ---

/***********************************************/
/* File .c missing: e2ap_ErrorIndication_IEs.c */
/***********************************************/

// --- Begin of e2ap_ErrorIndication.c ---

int asn1PE_e2ap_ErrorIndication (OSCTXT* pctxt, e2ap_ErrorIndication* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "ErrorIndication");

   stat = asn1PE_e2ap_ProtocolIE-Container (pctxt, &pvalue->protocolIEs);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_ErrorIndication (OSCTXT* pctxt, e2ap_ErrorIndication* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "ErrorIndication");

   stat = asn1PD_e2ap_ProtocolIE-Container (pctxt, &pvalue->protocolIEs);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_ErrorIndication (e2ap_ErrorIndication* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_ProtocolIE-Container (&pvalue->protocolIEs);
}

void asn1Free_e2ap_ErrorIndication (OSCTXT* pctxt, e2ap_ErrorIndication* pvalue)
{
   %}
   asn1Free_e2ap_ProtocolIE-Container (pctxt, &pvalue->protocolIEs);
}
// --- End of e2ap_ErrorIndication.c ---

