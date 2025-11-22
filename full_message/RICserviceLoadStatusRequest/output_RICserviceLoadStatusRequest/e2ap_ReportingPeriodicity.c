/******************************************************/
/*                                                    */
/*    ReportingPeriodicity                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_ReportingPeriodicity_ENUMTAB[] = {
    { OSUTF8("ms500"), 0, 5, 0 },
    { OSUTF8("ms1000"), 1, 6, 1 },
    { OSUTF8("ms2000"), 2, 6, 2 },
    { OSUTF8("ms5000"), 3, 6, 3 },
    { OSUTF8("ms10000"), 4, 7, 4 }
};


const OSUTF8CHAR* e2ap_ReportingPeriodicity_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_ReportingPeriodicity_ENUMTABSIZE){
      return e2ap_ReportingPeriodicity_ENUMTAB[e2ap_ReportingPeriodicity_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_ReportingPeriodicity_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_ReportingPeriodicity* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_ReportingPeriodicity_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_ReportingPeriodicity_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_ReportingPeriodicity* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_ReportingPeriodicity_ENUMTAB, e2ap_ReportingPeriodicity_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_ReportingPeriodicity)e2ap_ReportingPeriodicity_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_ReportingPeriodicity (OSCTXT* pctxt, e2ap_ReportingPeriodicity value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "ReportingPeriodicity");
   if (value >= 5) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(4));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_ReportingPeriodicity (OSCTXT* pctxt, e2ap_ReportingPeriodicity* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "ReportingPeriodicity");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(4));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_ReportingPeriodicity (const char* name, e2ap_ReportingPeriodicity* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = ms500", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = ms1000", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = ms2000", buffer, bufSize);
         break;
      case 3:
         stat = rtPrintToString(" = ms5000", buffer, bufSize);
         break;
      case 4:
         stat = rtPrintToString(" = ms10000", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}