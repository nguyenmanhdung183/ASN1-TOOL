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