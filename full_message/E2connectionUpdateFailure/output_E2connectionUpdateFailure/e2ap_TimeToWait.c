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