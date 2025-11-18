/* e2ap_E2nodeComponentInterfaceType.c */

//enumerated
/******************************************************/
/*                                                    */
/*    E2nodeComponentInterfaceType                                       */
/*                                                    */
/***********************


const OSEnumItem e2ap_E2nodeComponentInterfaceType_ENUMTAB[e2ap_E2nodeComponentInterfaceType_ENUMTABSIZE] = {
   { OSUTF8("ng"), 0, 2,  },   { OSUTF8("xn"), 1, 2,  },   { OSUTF8("e1"), 2, 2,  },   { OSUTF8("f1"), 3, 2,  },   { OSUTF8("w1"), 4, 2,  },   { OSUTF8("s1"), 5, 2,  },   { OSUTF8("x2"), 6, 2,  }};

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceType value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentInterfaceType");
   if (value >= 7) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(6));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceType* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentInterfaceType");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(6));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceType (const char* name, e2ap_E2nodeComponentInterfaceType* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_E2nodeComponentInterfaceType_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_E2nodeComponentInterfaceType_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}