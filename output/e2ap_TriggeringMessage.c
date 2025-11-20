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