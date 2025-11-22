/******************************************************/
/*                                                    */
/*    RegistrationRequest                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_RegistrationRequest_ENUMTAB[] = {
    { OSUTF8("start"), 0, 5, 0 },
    { OSUTF8("stop"), 1, 4, 1 },
    { OSUTF8("add"), 2, 3, 2 }
};


const OSUTF8CHAR* e2ap_RegistrationRequest_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_RegistrationRequest_ENUMTABSIZE){
      return e2ap_RegistrationRequest_ENUMTAB[e2ap_RegistrationRequest_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_RegistrationRequest_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RegistrationRequest* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_RegistrationRequest_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_RegistrationRequest_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RegistrationRequest* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_RegistrationRequest_ENUMTAB, e2ap_RegistrationRequest_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_RegistrationRequest)e2ap_RegistrationRequest_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_RegistrationRequest (OSCTXT* pctxt, e2ap_RegistrationRequest value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RegistrationRequest");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RegistrationRequest (OSCTXT* pctxt, e2ap_RegistrationRequest* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "RegistrationRequest");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RegistrationRequest (const char* name, e2ap_RegistrationRequest* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = start", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = stop", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = add", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}