/******************************************************/
/*                                                    */
/*    RICsubsequentActionType                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_RICsubsequentActionType_ENUMTAB[] = {
    { OSUTF8("continue"), 0, 8, 0 },
    { OSUTF8("wait"), 1, 4, 1 }
};


const OSUTF8CHAR* e2ap_RICsubsequentActionType_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_RICsubsequentActionType_ENUMTABSIZE){
      return e2ap_RICsubsequentActionType_ENUMTAB[e2ap_RICsubsequentActionType_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_RICsubsequentActionType_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICsubsequentActionType* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_RICsubsequentActionType_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_RICsubsequentActionType_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICsubsequentActionType* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_RICsubsequentActionType_ENUMTAB, e2ap_RICsubsequentActionType_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_RICsubsequentActionType)e2ap_RICsubsequentActionType_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_RICsubsequentActionType (OSCTXT* pctxt, e2ap_RICsubsequentActionType value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICsubsequentActionType");
   if (value >= 2) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(1));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RICsubsequentActionType (OSCTXT* pctxt, e2ap_RICsubsequentActionType* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "RICsubsequentActionType");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(1));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RICsubsequentActionType (const char* name, e2ap_RICsubsequentActionType* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = continue", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = wait", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}