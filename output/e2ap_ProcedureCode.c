/* e2ap_ProcedureCode.c */
#include "e2ap_ProcedureCode.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "ProcedureCode");
   stat = pe_ConsUnsigned (pctxt, value, 0.0, 255.0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_ProcedureCode (OSCTXT* pctxt, e2ap_ProcedureCode* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "ProcedureCode");
   if (pctxt->buffer.aligned) {
      int stat2 = pd_ByteAlign (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 8);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_ProcedureCode (const char* name, e2ap_ProcedureCode* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
=====================

E2setupRequest ::= SEQUENCE { 
 protocolIEs  ProtocolIE-Container  { {E2setupRequestIEs} }, 
 ... 
} 
-------------------------------
E2setupRequestIEs E2AP-PROTOCOL-IES ::= { 
 { ID id-TransactionID     CRITICALITY reject TYPE TransactionID     PRESENCE mandatory }| 
 { ID id-GlobalE2node-ID     CRITICALITY reject TYPE GlobalE2node-ID    PRESENCE mandatory }| 
 { ID id-RANfunctionsAdded    CRITICALITY reject TYPE RANfunctions-List    PRESENCE mandatory }| 
 { ID id-E2nodeComponentConfigAddition CRITICALITY reject TYPE E2nodeComponentConfigAddition-List 	 PRESENCE mandatory }, 
 ... 
} 
-------------------------------
GlobalE2node-ID ::= CHOICE{ 
 gNB     GlobalE2node-gNB-ID, 
 en-gNB    GlobalE2node-en-gNB-ID, 
 ng-eNB    GlobalE2node-ng-eNB-ID, 
 eNB     GlobalE2node-eNB-ID, 
 ... 
} 
-------------------------------
GlobalE2node-gNB-ID ::= SEQUENCE{ 
 global-gNB-ID  GlobalgNB-ID, 
 global-en-gNB-ID GlobalenGNB-ID OPTIONAL, 
 gNB-CU-UP-ID  GNB-CU-UP-ID OPTIONAL, 
 gNB-DU-ID   GNB-DU-ID  OPTIONAL, 
 ... 
} 
-------------------------------
GlobalgNB-ID ::= SEQUENCE { 
 plmn-id    PLMN-Identity, 
 gnb-id    GNB-ID-Choice, 
 ... 
} 
---------------------------------
PLMN-Identity ::= OCTET STRING (SIZE(3)) 

=================CODE IMPLEMENT==================