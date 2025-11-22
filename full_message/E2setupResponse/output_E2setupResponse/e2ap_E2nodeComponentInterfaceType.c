/******************************************************/
/*                                                    */
/*    E2nodeComponentInterfaceType                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_E2nodeComponentInterfaceType_ENUMTAB[] = {
    { OSUTF8("ng"), 0, 2, 0 },
    { OSUTF8("xn"), 1, 2, 1 },
    { OSUTF8("e1"), 2, 2, 2 },
    { OSUTF8("f1"), 3, 2, 3 },
    { OSUTF8("w1"), 4, 2, 4 },
    { OSUTF8("s1"), 5, 2, 5 },
    { OSUTF8("x2"), 6, 2, 6 }
};


const OSUTF8CHAR* e2ap_E2nodeComponentInterfaceType_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_E2nodeComponentInterfaceType_ENUMTABSIZE){
      return e2ap_E2nodeComponentInterfaceType_ENUMTAB[e2ap_E2nodeComponentInterfaceType_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_E2nodeComponentInterfaceType_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_E2nodeComponentInterfaceType* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_E2nodeComponentInterfaceType_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_E2nodeComponentInterfaceType_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_E2nodeComponentInterfaceType* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_E2nodeComponentInterfaceType_ENUMTAB, e2ap_E2nodeComponentInterfaceType_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_E2nodeComponentInterfaceType)e2ap_E2nodeComponentInterfaceType_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceType value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "E2nodeComponentInterfaceType");
   if (value >= 7) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(6));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceType* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "E2nodeComponentInterfaceType");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(6));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceType (const char* name, e2ap_E2nodeComponentInterfaceType* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = ng", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = xn", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = e1", buffer, bufSize);
         break;
      case 3:
         stat = rtPrintToString(" = f1", buffer, bufSize);
         break;
      case 4:
         stat = rtPrintToString(" = w1", buffer, bufSize);
         break;
      case 5:
         stat = rtPrintToString(" = s1", buffer, bufSize);
         break;
      case 6:
         stat = rtPrintToString(" = x2", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}