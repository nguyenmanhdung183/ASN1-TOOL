/******************************************************/
/*                                                    */
/*    RICtimeToWait                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_RICtimeToWait_ENUMTAB[] = {
    { OSUTF8("w1ms"), 0, 4, 0 },
    { OSUTF8("w2ms"), 1, 4, 1 },
    { OSUTF8("w5ms"), 2, 4, 2 },
    { OSUTF8("w10ms"), 3, 5, 3 },
    { OSUTF8("w20ms"), 4, 5, 4 },
    { OSUTF8("w30ms"), 5, 5, 5 },
    { OSUTF8("w40ms"), 6, 5, 6 },
    { OSUTF8("w50ms"), 7, 5, 7 },
    { OSUTF8("w100ms"), 8, 6, 8 },
    { OSUTF8("w200ms"), 9, 6, 9 },
    { OSUTF8("w500ms"), 10, 6, 10 },
    { OSUTF8("w1s"), 11, 3, 11 },
    { OSUTF8("w2s"), 12, 3, 12 },
    { OSUTF8("w5s"), 13, 3, 13 },
    { OSUTF8("w10s"), 14, 4, 14 },
    { OSUTF8("w20s"), 15, 4, 15 },
    { OSUTF8("w60s"), 16, 4, 16 }
};


const OSUTF8CHAR* e2ap_RICtimeToWait_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_RICtimeToWait_ENUMTABSIZE){
      return e2ap_RICtimeToWait_ENUMTAB[e2ap_RICtimeToWait_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_RICtimeToWait_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICtimeToWait* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_RICtimeToWait_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_RICtimeToWait_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICtimeToWait* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_RICtimeToWait_ENUMTAB, e2ap_RICtimeToWait_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_RICtimeToWait)e2ap_RICtimeToWait_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_RICtimeToWait (OSCTXT* pctxt, e2ap_RICtimeToWait value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICtimeToWait");
   if (value >= 17) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(16));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RICtimeToWait (OSCTXT* pctxt, e2ap_RICtimeToWait* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "RICtimeToWait");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(16));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RICtimeToWait (const char* name, e2ap_RICtimeToWait* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = w1ms", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = w2ms", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = w5ms", buffer, bufSize);
         break;
      case 3:
         stat = rtPrintToString(" = w10ms", buffer, bufSize);
         break;
      case 4:
         stat = rtPrintToString(" = w20ms", buffer, bufSize);
         break;
      case 5:
         stat = rtPrintToString(" = w30ms", buffer, bufSize);
         break;
      case 6:
         stat = rtPrintToString(" = w40ms", buffer, bufSize);
         break;
      case 7:
         stat = rtPrintToString(" = w50ms", buffer, bufSize);
         break;
      case 8:
         stat = rtPrintToString(" = w100ms", buffer, bufSize);
         break;
      case 9:
         stat = rtPrintToString(" = w200ms", buffer, bufSize);
         break;
      case 10:
         stat = rtPrintToString(" = w500ms", buffer, bufSize);
         break;
      case 11:
         stat = rtPrintToString(" = w1s", buffer, bufSize);
         break;
      case 12:
         stat = rtPrintToString(" = w2s", buffer, bufSize);
         break;
      case 13:
         stat = rtPrintToString(" = w5s", buffer, bufSize);
         break;
      case 14:
         stat = rtPrintToString(" = w10s", buffer, bufSize);
         break;
      case 15:
         stat = rtPrintToString(" = w20s", buffer, bufSize);
         break;
      case 16:
         stat = rtPrintToString(" = w60s", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}