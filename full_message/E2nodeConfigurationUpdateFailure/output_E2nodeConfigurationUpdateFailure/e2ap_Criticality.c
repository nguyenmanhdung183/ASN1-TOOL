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
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_Criticality (OSCTXT* pctxt, e2ap_Criticality* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "Criticality");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

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