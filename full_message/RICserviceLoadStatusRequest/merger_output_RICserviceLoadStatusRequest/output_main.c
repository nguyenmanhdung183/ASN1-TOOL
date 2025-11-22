#include "output_main.h"
// --- Begin of doc/header.c ---
//======================E2AP.c========================//
// --- End of doc/header.c ---

// --- Begin of e2ap_LoadMeasurementID.c ---
/*****************************************/
/*           LoadMeasurementID                */
/*****************************************/
//interger with ext


EXTERN int asn1PE_e2ap_LoadMeasurementID (OSCTXT* pctxt, e2ap_LoadMeasurementID value)
{ 
   RTXCTXTPUSHTYPENAME (pctxt, "LoadMeasurementID");

   OSBOOL exbit = (value > 4095) ? TRUE : FALSE;
   int stat = rtxEncBit (pctxt, exbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!exbit) {
      stat = pe_ConsUnsigned (pctxt, value, 1, 4095);
   } else {
      stat = pe_UnconsUnsigned (pctxt, value);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_LoadMeasurementID (OSCTXT* pctxt, e2ap_LoadMeasurementID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME (pctxt, "LoadMeasurementID");
   stat = rtxDecBit (pctxt, &extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!extbit) {
      stat = pd_ConsUnsigned (pctxt, pvalue, 1, 4095);
   } else {
      stat = pd_UnconsUnsigned (pctxt, pvalue);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

EXTERN int asn1PrtToStr_e2ap_LoadMeasurementID (const char* name, e2ap_LoadMeasurementID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_LoadMeasurementID.c ---

// --- Begin of e2ap_RegistrationRequest.c ---
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
// --- End of e2ap_RegistrationRequest.c ---

// --- Begin of e2ap_RANfunctionID.c ---
/*****************************************/
/*         RANfunctionID     */
/*****************************************/
//interger no ext

EXTERN int asn1PE_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionID");
   stat = pe_ConsUnsigned (pctxt, value, 0, 4095);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionID");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 16);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RANfunctionID (const char* name, e2ap_RANfunctionID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RANfunctionID.c ---

// --- Begin of e2ap_RICloadRequest.c ---
/******************************************************/
/*                                                    */
/*    RICloadRequest                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_RICloadRequest_ENUMTAB[] = {
    { OSUTF8("true"), 0, 4, 0 }
};


const OSUTF8CHAR* e2ap_RICloadRequest_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_RICloadRequest_ENUMTABSIZE){
      return e2ap_RICloadRequest_ENUMTAB[e2ap_RICloadRequest_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_RICloadRequest_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICloadRequest* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_RICloadRequest_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_RICloadRequest_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICloadRequest* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_RICloadRequest_ENUMTAB, e2ap_RICloadRequest_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_RICloadRequest)e2ap_RICloadRequest_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_RICloadRequest (OSCTXT* pctxt, e2ap_RICloadRequest value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICloadRequest");
   if (value >= 1) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(0));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RICloadRequest (OSCTXT* pctxt, e2ap_RICloadRequest* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "RICloadRequest");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(0));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RICloadRequest (const char* name, e2ap_RICloadRequest* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = true", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_RICloadRequest.c ---

// --- Begin of e2ap_RICserviceLoadRequest.c ---

/*****************************************/
/*           RICserviceLoadRequest                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, e2ap_RICserviceLoadRequest* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceLoadRequest");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricServiceReportLoadRequest */  
   if (pvalue->m_ricServiceReportLoadRequestPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceReportLoadRequest");
   stat = asn1PE_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceReportLoadRequest);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceInsertLoadRequest */  
   if (pvalue->m_ricServiceInsertLoadRequestPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceInsertLoadRequest");
   stat = asn1PE_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceInsertLoadRequest);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceControlLoadRequest */  
   if (pvalue->m_ricServiceControlLoadRequestPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceControlLoadRequest");
   stat = asn1PE_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceControlLoadRequest);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServicePolicyLoadRequest */  
   if (pvalue->m_ricServicePolicyLoadRequestPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServicePolicyLoadRequest");
   stat = asn1PE_e2ap_RICloadRequest (pctxt, &pvalue->ricServicePolicyLoadRequest);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceQueryLoadRequest */  
   if (pvalue->m_ricServiceQueryLoadRequestPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceQueryLoadRequest");
   stat = asn1PE_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceQueryLoadRequest);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }


   /*
   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   */

   if(extbit) {
      /*encode extension optional bits length */
      stat = pe_SmallLength(pctxt, pvalue->extElem1.count);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode optional bit*/
      stat = pe_OpenTypeExtBits(pctxt, &pvalue->extElem1);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode extension elements*/
      if (pvalue->extElem1.count > 0) {
         stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, e2ap_RICserviceLoadRequest* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[5];

   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceLoadRequest");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 5; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field ricServiceReportLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceReportLoadRequest");
   if (optbits[0]) {
      pvalue->m_ricServiceReportLoadRequestPresent = TRUE;
      stat = asn1PD_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceReportLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceReportLoadRequestPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceInsertLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceInsertLoadRequest");
   if (optbits[0]) {
      pvalue->m_ricServiceInsertLoadRequestPresent = TRUE;
      stat = asn1PD_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceInsertLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceInsertLoadRequestPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceControlLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceControlLoadRequest");
   if (optbits[0]) {
      pvalue->m_ricServiceControlLoadRequestPresent = TRUE;
      stat = asn1PD_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceControlLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceControlLoadRequestPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServicePolicyLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServicePolicyLoadRequest");
   if (optbits[0]) {
      pvalue->m_ricServicePolicyLoadRequestPresent = TRUE;
      stat = asn1PD_e2ap_RICloadRequest (pctxt, &pvalue->ricServicePolicyLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServicePolicyLoadRequestPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceQueryLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceQueryLoadRequest");
   if (optbits[0]) {
      pvalue->m_ricServiceQueryLoadRequestPresent = TRUE;
      stat = asn1PD_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceQueryLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceQueryLoadRequestPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pdSmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFree(pctxt, poptbits);
            return LOG_RTERR(pctxt, stat);
         }
      }

      for(i_ = 0; i_ < bitcnt; i_++) {
         if(stat != 0) break;
         if(poptbits[i_]) {
            /*decode extension element*/
            stat = pd_OpenType (pctxt, &openType, &openType.numocts);

            if(0==stat){
               pOpenType = rtxMemAllocType(pctxt, ASN1OpenType);
               if(0!=pOpenType){
                  pOpenType->numocts = openType.numocts;
                  pOpenType->data = openType.data;
                  rtxDListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxDListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXTPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_RICserviceLoadRequest (e2ap_RICserviceLoadRequest* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RICloadRequest (&pvalue->ricServiceReportLoadRequest);
   asn1Init_e2ap_RICloadRequest (&pvalue->ricServiceInsertLoadRequest);
   asn1Init_e2ap_RICloadRequest (&pvalue->ricServiceControlLoadRequest);
   asn1Init_e2ap_RICloadRequest (&pvalue->ricServicePolicyLoadRequest);
   asn1Init_e2ap_RICloadRequest (&pvalue->ricServiceQueryLoadRequest);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, e2ap_RICserviceLoadRequest* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceReportLoadRequest);
   asn1Free_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceInsertLoadRequest);
   asn1Free_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceControlLoadRequest);
   asn1Free_e2ap_RICloadRequest (pctxt, &pvalue->ricServicePolicyLoadRequest);
   asn1Free_e2ap_RICloadRequest (pctxt, &pvalue->ricServiceQueryLoadRequest);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICserviceLoadRequest (const char* name, e2ap_RICserviceLoadRequest* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadRequest ("ricServiceReportLoadRequest", &pvalue->ricServiceReportLoadRequest, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadRequest ("ricServiceInsertLoadRequest", &pvalue->ricServiceInsertLoadRequest, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadRequest ("ricServiceControlLoadRequest", &pvalue->ricServiceControlLoadRequest, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadRequest ("ricServicePolicyLoadRequest", &pvalue->ricServicePolicyLoadRequest, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadRequest ("ricServiceQueryLoadRequest", &pvalue->ricServiceQueryLoadRequest, buffer, bufSize) < 0)
   {
      return -1;
   }

   /*assum there is an extension*/
   if(rtPrintToStringOpenTypeExtBraceText("extElem1", &pvalue->extElem1, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RICserviceLoadRequest.c ---

/******************************************/
/* File .c missing: e2ap_ricRequestorID.c */
/******************************************/

/*****************************************/
/* File .c missing: e2ap_ricInstanceID.c */
/*****************************************/

// --- Begin of e2ap_RICrequestID.c ---

/*****************************************/
/*           RICrequestID                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICrequestID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricRequestorID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricRequestorID");
   stat = asn1PE_e2ap_ricRequestorID (pctxt, &pvalue->ricRequestorID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ricInstanceID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricInstanceID");
   stat = asn1PE_e2ap_ricInstanceID (pctxt, &pvalue->ricInstanceID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);



   /*
   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   */

   if(extbit) {
      /*encode extension optional bits length */
      stat = pe_SmallLength(pctxt, pvalue->extElem1.count);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode optional bit*/
      stat = pe_OpenTypeExtBits(pctxt, &pvalue->extElem1);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode extension elements*/
      if (pvalue->extElem1.count > 0) {
         stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "RICrequestID");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 2; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field ricRequestorID */
   RTXCTXTPUSHELEMNAME(pctxt, "ricRequestorID");
      stat = asn1PD_e2ap_ricRequestorID (pctxt, &pvalue->ricRequestorID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ricInstanceID */
   RTXCTXTPUSHELEMNAME(pctxt, "ricInstanceID");
      stat = asn1PD_e2ap_ricInstanceID (pctxt, &pvalue->ricInstanceID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pdSmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFree(pctxt, poptbits);
            return LOG_RTERR(pctxt, stat);
         }
      }

      for(i_ = 0; i_ < bitcnt; i_++) {
         if(stat != 0) break;
         if(poptbits[i_]) {
            /*decode extension element*/
            stat = pd_OpenType (pctxt, &openType, &openType.numocts);

            if(0==stat){
               pOpenType = rtxMemAllocType(pctxt, ASN1OpenType);
               if(0!=pOpenType){
                  pOpenType->numocts = openType.numocts;
                  pOpenType->data = openType.data;
                  rtxDListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxDListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXTPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_RICrequestID (e2ap_RICrequestID* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_ricRequestorID (&pvalue->ricRequestorID);
   asn1Init_e2ap_ricInstanceID (&pvalue->ricInstanceID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_ricRequestorID (pctxt, &pvalue->ricRequestorID);
   asn1Free_e2ap_ricInstanceID (pctxt, &pvalue->ricInstanceID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICrequestID (const char* name, e2ap_RICrequestID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ricRequestorID ("ricRequestorID", &pvalue->ricRequestorID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ricInstanceID ("ricInstanceID", &pvalue->ricInstanceID, buffer, bufSize) < 0)
   {
      return -1;
   }

   /*assum there is an extension*/
   if(rtPrintToStringOpenTypeExtBraceText("extElem1", &pvalue->extElem1, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RICrequestID.c ---

// --- Begin of e2ap_RICactionID.c ---
/*****************************************/
/*         RICactionID     */
/*****************************************/
//interger no ext

EXTERN int asn1PE_e2ap_RICactionID (OSCTXT* pctxt, e2ap_RICactionID value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICactionID");
   stat = pe_ConsUnsigned (pctxt, value, 0, 255);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RICactionID (OSCTXT* pctxt, e2ap_RICactionID* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICactionID");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 8);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RICactionID (const char* name, e2ap_RICactionID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RICactionID.c ---

// --- Begin of e2ap_RICactionLoadRequest_Item.c ---

/*****************************************/
/*           RICactionLoadRequest-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICactionLoadRequest_Item (OSCTXT* pctxt, e2ap_RICactionLoadRequest_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICactionLoadRequest-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricActionID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionID");
   stat = asn1PE_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ricActionLoadRequest */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionLoadRequest");
   stat = asn1PE_e2ap_RICloadRequest (pctxt, &pvalue->ricActionLoadRequest);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);



   /*
   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   */

   if(extbit) {
      /*encode extension optional bits length */
      stat = pe_SmallLength(pctxt, pvalue->extElem1.count);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode optional bit*/
      stat = pe_OpenTypeExtBits(pctxt, &pvalue->extElem1);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode extension elements*/
      if (pvalue->extElem1.count > 0) {
         stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_RICactionLoadRequest_Item (OSCTXT* pctxt, e2ap_RICactionLoadRequest_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "RICactionLoadRequest-Item");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 2; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field ricActionID */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionID");
      stat = asn1PD_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ricActionLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionLoadRequest");
      stat = asn1PD_e2ap_RICloadRequest (pctxt, &pvalue->ricActionLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pdSmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFree(pctxt, poptbits);
            return LOG_RTERR(pctxt, stat);
         }
      }

      for(i_ = 0; i_ < bitcnt; i_++) {
         if(stat != 0) break;
         if(poptbits[i_]) {
            /*decode extension element*/
            stat = pd_OpenType (pctxt, &openType, &openType.numocts);

            if(0==stat){
               pOpenType = rtxMemAllocType(pctxt, ASN1OpenType);
               if(0!=pOpenType){
                  pOpenType->numocts = openType.numocts;
                  pOpenType->data = openType.data;
                  rtxDListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxDListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXTPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_RICactionLoadRequest_Item (e2ap_RICactionLoadRequest_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RICactionID (&pvalue->ricActionID);
   asn1Init_e2ap_RICloadRequest (&pvalue->ricActionLoadRequest);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICactionLoadRequest_Item (OSCTXT* pctxt, e2ap_RICactionLoadRequest_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
   asn1Free_e2ap_RICloadRequest (pctxt, &pvalue->ricActionLoadRequest);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICactionLoadRequest_Item (const char* name, e2ap_RICactionLoadRequest_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICactionID ("ricActionID", &pvalue->ricActionID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadRequest ("ricActionLoadRequest", &pvalue->ricActionLoadRequest, buffer, bufSize) < 0)
   {
      return -1;
   }

   /*assum there is an extension*/
   if(rtPrintToStringOpenTypeExtBraceText("extElem1", &pvalue->extElem1, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RICactionLoadRequest_Item.c ---

// --- Begin of e2ap_RICactionLoadRequest_ItemIEs.c ---
/* e2ap_RICactionLoadRequest_ItemIEs.c */

/*****************************************/
/*           RICactionLoadRequest_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_RICactionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoadRequest_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICactionLoadRequest-ItemIEs");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_RICactionLoadRequest_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_RICactionLoadRequest_ItemIEs_.criticality);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode value */
   RTXCTXTPUSHELEMNAME (pctxt, "value");

   {
      OSCTXT ictxt;
      OSOCTET* pDynamicEncodeBuffer;
      ASN1OpenType openType;
      OSBOOL  encoded = TRUE;

      openType.numocts = 0;
      openType.data = 0;

      rtxCopyContext (&ictxt, pctxt);
      pctxt->pStream = 0;

      stat = rtxInitContextBuffer (pctxt, 0, 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      switch (pvalue->value.t) {
      case T_E2AP_PDU_Contents_RICactionLoadRequest_ItemIEs_RICactionLoadRequest_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "RICactionLoadRequest_Item");
         stat = asn1PE_e2ap_RICactionLoadRequest_Item (pctxt, pvalue->value.u._e2apRICactionLoadRequest_ItemIEs_RICactionLoadRequest_Item);
         RTXCTXTPOPELEMNAME (pctxt);
      
         break;

      default:
         encoded = FALSE;
         stat = RTERR_INVOPT;
      }

      if (encoded) {
         size_t bitOffset = PU_GETCTXBITSAVED (pctxt);
         size_t bitsConsumed = bitOffset;
         if (bitsConsumed < bitOffset) {
            stat = pd_moveBitCursor (pctxt, (int)(bitOffset - bitsConsumed));
         } else {
            stat = (bitsConsumed > bitOffset) ? ASN_E_INVLEN : 0;
         }
         if (stat != 0) return LOG_RTERR (pctxt, stat);
      }

      RTXCTXTPOPELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RICactionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoadRequest_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_RICactionLoadRequest_ItemIEs (e2ap_RICactionLoadRequest_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_RICactionLoadRequest_ItemIEs));
}

void asn1Free_e2ap_RICactionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoadRequest_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
// --- End of e2ap_RICactionLoadRequest_ItemIEs.c ---

// --- Begin of e2ap_RICactionLoadRequest_List.c ---
/*****************************************/
/*           RICactionLoadRequest_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_RICactionLoadRequest_List (OSCTXT* pctxt, e2ap_RICactionLoadRequest_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICactionLoadRequest_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICactionLoadRequest-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRICactionID), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RICactionLoadRequest_ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RICactionLoadRequest_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RICactionLoadRequest_List (OSCTXT* pctxt, e2ap_RICactionLoadRequest_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICactionLoadRequest_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICactionLoadRequest-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRICactionID), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RICactionLoadRequest_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RICactionLoadRequest_ItemIEs (pdata);

      stat = asn1PD_e2ap_RICactionLoadRequest_ItemIEs (pctxt, pdata);
      if (stat != 0) {
         rtxMemFreePtr (pctxt, pdata);
         return LOG_RTERR (pctxt, stat);
      }

      rtxDListAppendNode (ppvalue, pdata);

      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

void asn1Init_e2ap_RICactionLoadRequest_List (e2ap_RICactionLoadRequest_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_RICactionLoadRequest_List (OSCTXT* pctxt, e2ap_RICactionLoadRequest_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RICactionLoadRequest_ItemIEs* pdata = (e2ap_RICactionLoadRequest_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RICactionLoadRequest_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}

#if 0
void asn1Free_e2ap_RICactionLoadRequest_List (OSCTXT* pctxt, e2ap_RICactionLoadRequest_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_RICactionLoadRequest_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_RICactionLoadRequest_ItemIEs*)pnode->data;
         asn1Free_e2ap_RICactionLoadRequest_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_RICactionLoadRequest_List.c ---

// --- Begin of e2ap_RICsubscriptionLoadRequest_ItemIE.c ---

/*****************************************/
/*           RICsubscriptionLoadRequest-ItemIE                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICsubscriptionLoadRequest_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_ItemIE* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICsubscriptionLoadRequest-ItemIE");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricRequestID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricRequestID");
   stat = asn1PE_e2ap_RICrequestID (pctxt, &pvalue->ricRequestID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ricSubscriptionLoadRequest */  
   if (pvalue->m_ricSubscriptionLoadRequestPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricSubscriptionLoadRequest");
   stat = asn1PE_e2ap_RICloadRequest (pctxt, &pvalue->ricSubscriptionLoadRequest);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricActionLoadRequest_list */  
   if (pvalue->m_ricActionLoadRequest_listPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionLoadRequest-list");
   stat = asn1PE_e2ap_RICactionLoadRequest_List (pctxt, &pvalue->ricActionLoadRequest_list);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }


   /*
   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   */

   if(extbit) {
      /*encode extension optional bits length */
      stat = pe_SmallLength(pctxt, pvalue->extElem1.count);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode optional bit*/
      stat = pe_OpenTypeExtBits(pctxt, &pvalue->extElem1);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode extension elements*/
      if (pvalue->extElem1.count > 0) {
         stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_RICsubscriptionLoadRequest_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_ItemIE* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[3];

   RTXCTXTPUSHTYPENAME(pctxt, "RICsubscriptionLoadRequest-ItemIE");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 3; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field ricRequestID */
   RTXCTXTPUSHELEMNAME(pctxt, "ricRequestID");
      stat = asn1PD_e2ap_RICrequestID (pctxt, &pvalue->ricRequestID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ricSubscriptionLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ricSubscriptionLoadRequest");
   if (optbits[0]) {
      pvalue->m_ricSubscriptionLoadRequestPresent = TRUE;
      stat = asn1PD_e2ap_RICloadRequest (pctxt, &pvalue->ricSubscriptionLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricSubscriptionLoadRequestPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricActionLoadRequest_list */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionLoadRequest-list");
   if (optbits[0]) {
      pvalue->m_ricActionLoadRequest_listPresent = TRUE;
      stat = asn1PD_e2ap_RICactionLoadRequest_List (pctxt, &pvalue->ricActionLoadRequest_list);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricActionLoadRequest_listPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pdSmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFree(pctxt, poptbits);
            return LOG_RTERR(pctxt, stat);
         }
      }

      for(i_ = 0; i_ < bitcnt; i_++) {
         if(stat != 0) break;
         if(poptbits[i_]) {
            /*decode extension element*/
            stat = pd_OpenType (pctxt, &openType, &openType.numocts);

            if(0==stat){
               pOpenType = rtxMemAllocType(pctxt, ASN1OpenType);
               if(0!=pOpenType){
                  pOpenType->numocts = openType.numocts;
                  pOpenType->data = openType.data;
                  rtxDListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxDListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXTPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_RICsubscriptionLoadRequest_ItemIE (e2ap_RICsubscriptionLoadRequest_ItemIE* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RICrequestID (&pvalue->ricRequestID);
   asn1Init_e2ap_RICloadRequest (&pvalue->ricSubscriptionLoadRequest);
   asn1Init_e2ap_RICactionLoadRequest_List (&pvalue->ricActionLoadRequest_list);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICsubscriptionLoadRequest_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_ItemIE* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RICrequestID (pctxt, &pvalue->ricRequestID);
   asn1Free_e2ap_RICloadRequest (pctxt, &pvalue->ricSubscriptionLoadRequest);
   asn1Free_e2ap_RICactionLoadRequest_List (pctxt, &pvalue->ricActionLoadRequest_list);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICsubscriptionLoadRequest_ItemIE (const char* name, e2ap_RICsubscriptionLoadRequest_ItemIE* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICrequestID ("ricRequestID", &pvalue->ricRequestID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadRequest ("ricSubscriptionLoadRequest", &pvalue->ricSubscriptionLoadRequest, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICactionLoadRequest_List ("ricActionLoadRequest_list", &pvalue->ricActionLoadRequest_list, buffer, bufSize) < 0)
   {
      return -1;
   }

   /*assum there is an extension*/
   if(rtPrintToStringOpenTypeExtBraceText("extElem1", &pvalue->extElem1, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RICsubscriptionLoadRequest_ItemIE.c ---

// --- Begin of e2ap_RICsubscriptionLoadRequest_ItemIEs.c ---
/* e2ap_RICsubscriptionLoadRequest_ItemIEs.c */

/*****************************************/
/*           RICsubscriptionLoadRequest_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_RICsubscriptionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICsubscriptionLoadRequest-ItemIEs");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_RICsubscriptionLoadRequest_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_RICsubscriptionLoadRequest_ItemIEs_.criticality);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode value */
   RTXCTXTPUSHELEMNAME (pctxt, "value");

   {
      OSCTXT ictxt;
      OSOCTET* pDynamicEncodeBuffer;
      ASN1OpenType openType;
      OSBOOL  encoded = TRUE;

      openType.numocts = 0;
      openType.data = 0;

      rtxCopyContext (&ictxt, pctxt);
      pctxt->pStream = 0;

      stat = rtxInitContextBuffer (pctxt, 0, 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      switch (pvalue->value.t) {
      case T_E2AP_PDU_Contents_RICsubscriptionLoadRequest_ItemIEs_RICsubscriptionLoadRequest_ItemIE:
         
         RTXCTXTPUSHELEMNAME (pctxt, "RICsubscriptionLoadRequest_ItemIE");
         stat = asn1PE_e2ap_RICsubscriptionLoadRequest_ItemIE (pctxt, pvalue->value.u._e2apRICsubscriptionLoadRequest_ItemIEs_RICsubscriptionLoadRequest_ItemIE);
         RTXCTXTPOPELEMNAME (pctxt);
      
         break;

      default:
         encoded = FALSE;
         stat = RTERR_INVOPT;
      }

      if (encoded) {
         size_t bitOffset = PU_GETCTXBITSAVED (pctxt);
         size_t bitsConsumed = bitOffset;
         if (bitsConsumed < bitOffset) {
            stat = pd_moveBitCursor (pctxt, (int)(bitOffset - bitsConsumed));
         } else {
            stat = (bitsConsumed > bitOffset) ? ASN_E_INVLEN : 0;
         }
         if (stat != 0) return LOG_RTERR (pctxt, stat);
      }

      RTXCTXTPOPELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RICsubscriptionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_RICsubscriptionLoadRequest_ItemIEs (e2ap_RICsubscriptionLoadRequest_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_RICsubscriptionLoadRequest_ItemIEs));
}

void asn1Free_e2ap_RICsubscriptionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
// --- End of e2ap_RICsubscriptionLoadRequest_ItemIEs.c ---

// --- Begin of e2ap_RICsubscriptionLoadRequest_List.c ---
/*****************************************/
/*           RICsubscriptionLoadRequest_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_RICsubscriptionLoadRequest_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICsubscriptionLoadRequest_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICsubscriptionLoadRequest-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRICrequestID), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RICsubscriptionLoadRequest_ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RICsubscriptionLoadRequest_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RICsubscriptionLoadRequest_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICsubscriptionLoadRequest_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICsubscriptionLoadRequest-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRICrequestID), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RICsubscriptionLoadRequest_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RICsubscriptionLoadRequest_ItemIEs (pdata);

      stat = asn1PD_e2ap_RICsubscriptionLoadRequest_ItemIEs (pctxt, pdata);
      if (stat != 0) {
         rtxMemFreePtr (pctxt, pdata);
         return LOG_RTERR (pctxt, stat);
      }

      rtxDListAppendNode (ppvalue, pdata);

      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

void asn1Init_e2ap_RICsubscriptionLoadRequest_List (e2ap_RICsubscriptionLoadRequest_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_RICsubscriptionLoadRequest_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RICsubscriptionLoadRequest_ItemIEs* pdata = (e2ap_RICsubscriptionLoadRequest_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RICsubscriptionLoadRequest_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}

#if 0
void asn1Free_e2ap_RICsubscriptionLoadRequest_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_RICsubscriptionLoadRequest_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_RICsubscriptionLoadRequest_ItemIEs*)pnode->data;
         asn1Free_e2ap_RICsubscriptionLoadRequest_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_RICsubscriptionLoadRequest_List.c ---

// --- Begin of e2ap_RANfunctionLoadRequest_Item.c ---

/*****************************************/
/*           RANfunctionLoadRequest-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RANfunctionLoadRequest_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RANfunctionLoadRequest-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ranFunctionID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionID");
   stat = asn1PE_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ranFunctionLoadRequest */  
   if (pvalue->m_ranFunctionLoadRequestPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionLoadRequest");
   stat = asn1PE_e2ap_RICloadRequest (pctxt, &pvalue->ranFunctionLoadRequest);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceLoadRequest */  
   if (pvalue->m_ricServiceLoadRequestPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceLoadRequest");
   stat = asn1PE_e2ap_RICserviceLoadRequest (pctxt, &pvalue->ricServiceLoadRequest);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricSubscriptionLoadRequest_list */  
   if (pvalue->m_ricSubscriptionLoadRequest_listPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricSubscriptionLoadRequest-list");
   stat = asn1PE_e2ap_RICsubscriptionLoadRequest_List (pctxt, &pvalue->ricSubscriptionLoadRequest_list);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }


   /*
   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   */

   if(extbit) {
      /*encode extension optional bits length */
      stat = pe_SmallLength(pctxt, pvalue->extElem1.count);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode optional bit*/
      stat = pe_OpenTypeExtBits(pctxt, &pvalue->extElem1);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode extension elements*/
      if (pvalue->extElem1.count > 0) {
         stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_RANfunctionLoadRequest_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[4];

   RTXCTXTPUSHTYPENAME(pctxt, "RANfunctionLoadRequest-Item");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 4; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field ranFunctionID */
   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionID");
      stat = asn1PD_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ranFunctionLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionLoadRequest");
   if (optbits[0]) {
      pvalue->m_ranFunctionLoadRequestPresent = TRUE;
      stat = asn1PD_e2ap_RICloadRequest (pctxt, &pvalue->ranFunctionLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ranFunctionLoadRequestPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceLoadRequest */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceLoadRequest");
   if (optbits[0]) {
      pvalue->m_ricServiceLoadRequestPresent = TRUE;
      stat = asn1PD_e2ap_RICserviceLoadRequest (pctxt, &pvalue->ricServiceLoadRequest);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceLoadRequestPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricSubscriptionLoadRequest_list */
   RTXCTXTPUSHELEMNAME(pctxt, "ricSubscriptionLoadRequest-list");
   if (optbits[0]) {
      pvalue->m_ricSubscriptionLoadRequest_listPresent = TRUE;
      stat = asn1PD_e2ap_RICsubscriptionLoadRequest_List (pctxt, &pvalue->ricSubscriptionLoadRequest_list);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricSubscriptionLoadRequest_listPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pdSmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFree(pctxt, poptbits);
            return LOG_RTERR(pctxt, stat);
         }
      }

      for(i_ = 0; i_ < bitcnt; i_++) {
         if(stat != 0) break;
         if(poptbits[i_]) {
            /*decode extension element*/
            stat = pd_OpenType (pctxt, &openType, &openType.numocts);

            if(0==stat){
               pOpenType = rtxMemAllocType(pctxt, ASN1OpenType);
               if(0!=pOpenType){
                  pOpenType->numocts = openType.numocts;
                  pOpenType->data = openType.data;
                  rtxDListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxDListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXTPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_RANfunctionLoadRequest_Item (e2ap_RANfunctionLoadRequest_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RANfunctionID (&pvalue->ranFunctionID);
   asn1Init_e2ap_RICloadRequest (&pvalue->ranFunctionLoadRequest);
   asn1Init_e2ap_RICserviceLoadRequest (&pvalue->ricServiceLoadRequest);
   asn1Init_e2ap_RICsubscriptionLoadRequest_List (&pvalue->ricSubscriptionLoadRequest_list);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RANfunctionLoadRequest_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   asn1Free_e2ap_RICloadRequest (pctxt, &pvalue->ranFunctionLoadRequest);
   asn1Free_e2ap_RICserviceLoadRequest (pctxt, &pvalue->ricServiceLoadRequest);
   asn1Free_e2ap_RICsubscriptionLoadRequest_List (pctxt, &pvalue->ricSubscriptionLoadRequest_list);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RANfunctionLoadRequest_Item (const char* name, e2ap_RANfunctionLoadRequest_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RANfunctionID ("ranFunctionID", &pvalue->ranFunctionID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadRequest ("ranFunctionLoadRequest", &pvalue->ranFunctionLoadRequest, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICserviceLoadRequest ("ricServiceLoadRequest", &pvalue->ricServiceLoadRequest, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICsubscriptionLoadRequest_List ("ricSubscriptionLoadRequest_list", &pvalue->ricSubscriptionLoadRequest_list, buffer, bufSize) < 0)
   {
      return -1;
   }

   /*assum there is an extension*/
   if(rtPrintToStringOpenTypeExtBraceText("extElem1", &pvalue->extElem1, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RANfunctionLoadRequest_Item.c ---

// --- Begin of e2ap_RANfunctionLoadRequest_ItemIEs.c ---
/* e2ap_RANfunctionLoadRequest_ItemIEs.c */

/*****************************************/
/*           RANfunctionLoadRequest_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_RANfunctionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionLoadRequest-ItemIEs");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_RANfunctionLoadRequest_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_RANfunctionLoadRequest_ItemIEs_.criticality);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode value */
   RTXCTXTPUSHELEMNAME (pctxt, "value");

   {
      OSCTXT ictxt;
      OSOCTET* pDynamicEncodeBuffer;
      ASN1OpenType openType;
      OSBOOL  encoded = TRUE;

      openType.numocts = 0;
      openType.data = 0;

      rtxCopyContext (&ictxt, pctxt);
      pctxt->pStream = 0;

      stat = rtxInitContextBuffer (pctxt, 0, 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      switch (pvalue->value.t) {
      case T_E2AP_PDU_Contents_RANfunctionLoadRequest_ItemIEs_RANfunctionLoadRequest_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "RANfunctionLoadRequest_Item");
         stat = asn1PE_e2ap_RANfunctionLoadRequest_Item (pctxt, pvalue->value.u._e2apRANfunctionLoadRequest_ItemIEs_RANfunctionLoadRequest_Item);
         RTXCTXTPOPELEMNAME (pctxt);
      
         break;

      default:
         encoded = FALSE;
         stat = RTERR_INVOPT;
      }

      if (encoded) {
         size_t bitOffset = PU_GETCTXBITSAVED (pctxt);
         size_t bitsConsumed = bitOffset;
         if (bitsConsumed < bitOffset) {
            stat = pd_moveBitCursor (pctxt, (int)(bitOffset - bitsConsumed));
         } else {
            stat = (bitsConsumed > bitOffset) ? ASN_E_INVLEN : 0;
         }
         if (stat != 0) return LOG_RTERR (pctxt, stat);
      }

      RTXCTXTPOPELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RANfunctionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_RANfunctionLoadRequest_ItemIEs (e2ap_RANfunctionLoadRequest_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_RANfunctionLoadRequest_ItemIEs));
}

void asn1Free_e2ap_RANfunctionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
// --- End of e2ap_RANfunctionLoadRequest_ItemIEs.c ---

// --- Begin of e2ap_RANfunctionLoadRequest_List.c ---
/*****************************************/
/*           RANfunctionLoadRequest_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_RANfunctionLoadRequest_List (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RANfunctionLoadRequest_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionLoadRequest-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRANfunctionID), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RANfunctionLoadRequest_ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RANfunctionLoadRequest_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RANfunctionLoadRequest_List (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RANfunctionLoadRequest_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionLoadRequest-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRANfunctionID), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RANfunctionLoadRequest_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RANfunctionLoadRequest_ItemIEs (pdata);

      stat = asn1PD_e2ap_RANfunctionLoadRequest_ItemIEs (pctxt, pdata);
      if (stat != 0) {
         rtxMemFreePtr (pctxt, pdata);
         return LOG_RTERR (pctxt, stat);
      }

      rtxDListAppendNode (ppvalue, pdata);

      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

void asn1Init_e2ap_RANfunctionLoadRequest_List (e2ap_RANfunctionLoadRequest_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_RANfunctionLoadRequest_List (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RANfunctionLoadRequest_ItemIEs* pdata = (e2ap_RANfunctionLoadRequest_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RANfunctionLoadRequest_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}

#if 0
void asn1Free_e2ap_RANfunctionLoadRequest_List (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_RANfunctionLoadRequest_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_RANfunctionLoadRequest_ItemIEs*)pnode->data;
         asn1Free_e2ap_RANfunctionLoadRequest_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_RANfunctionLoadRequest_List.c ---

// --- Begin of e2ap_ReportingPeriodicity.c ---
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
// --- End of e2ap_ReportingPeriodicity.c ---

/***********************************************************/
/* File .c missing: e2ap_RICserviceLoadStatusRequest_IEs.c */
/***********************************************************/

// --- Begin of e2ap_RICserviceLoadStatusRequest.c ---

/*****************************************/
/*           RICserviceLoadStatusRequest                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICserviceLoadStatusRequest (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceLoadStatusRequest");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field protocolIEs */  

   RTXCTXTPUSHELEMNAME(pctxt, "protocolIEs");
   stat = asn1PE_e2ap_ProtocolIE_Container (pctxt, &pvalue->protocolIEs);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);



   /*
   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   */

   if(extbit) {
      /*encode extension optional bits length */
      stat = pe_SmallLength(pctxt, pvalue->extElem1.count);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode optional bit*/
      stat = pe_OpenTypeExtBits(pctxt, &pvalue->extElem1);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*encode extension elements*/
      if (pvalue->extElem1.count > 0) {
         stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_RICserviceLoadStatusRequest (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceLoadStatusRequest");

   /*extension bit*/
   stat = DEC_BIT(pctxt, &extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   rtxDListInit(&pvalue->extElem1); 

   /*optional bits*/
   for(i_ = 0; i_ < 1; i_++) {
      stat = DEC_BIT(pctxt, &optbits[i_]);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   /*decode root elements*/
   /* decode field protocolIEs */
   RTXCTXTPUSHELEMNAME(pctxt, "protocolIEs");
      stat = asn1PD_e2ap_ProtocolIE_Container (pctxt, &pvalue->protocolIEs);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pdSmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFree(pctxt, poptbits);
            return LOG_RTERR(pctxt, stat);
         }
      }

      for(i_ = 0; i_ < bitcnt; i_++) {
         if(stat != 0) break;
         if(poptbits[i_]) {
            /*decode extension element*/
            stat = pd_OpenType (pctxt, &openType, &openType.numocts);

            if(0==stat){
               pOpenType = rtxMemAllocType(pctxt, ASN1OpenType);
               if(0!=pOpenType){
                  pOpenType->numocts = openType.numocts;
                  pOpenType->data = openType.data;
                  rtxDListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxDListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXTPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_RICserviceLoadStatusRequest (e2ap_RICserviceLoadStatusRequest* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_ProtocolIE_Container (&pvalue->protocolIEs);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICserviceLoadStatusRequest (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_ProtocolIE_Container (pctxt, &pvalue->protocolIEs);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICserviceLoadStatusRequest (const char* name, e2ap_RICserviceLoadStatusRequest* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ProtocolIE_Container ("protocolIEs", &pvalue->protocolIEs, buffer, bufSize) < 0)
   {
      return -1;
   }

   /*assum there is an extension*/
   if(rtPrintToStringOpenTypeExtBraceText("extElem1", &pvalue->extElem1, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RICserviceLoadStatusRequest.c ---

// --- Begin of e2ap_RICserviceLoadStatusRequest_protocolIEs.c ---
/******************************************************/
/*                                                    */
/*    RICserviceLoadStatusRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

EXTERN int asn1PE_e2ap_RICserviceLoadStatusRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEst* pvalue)
{
    int stat =0;
    OSRTDListNode* pnode;
    OSUINT32 xx1;

    /*encode length determinant */
    PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(0), OSUINTCONST(ASN1V_e2ap_maxProtocolIEs), 0, 0);
    stat = pe_Length(pctxt, pvalue->count);
    if(stat!=0) return LOG_RTERR(pctxt, stat);

    /*encode each element*/
    xx1 =0;
    for(pnode = pvalue->head; pnode != 0 && xx1<pvalue->count; pnode = pnode->next){
        RTXCTXTPUSHARRAYELEMNAME(pctxt, "SEQUENCE", xx1);
        stat = asn1PE_e2ap_RICserviceLoadStatusRequest_protocolIEs_element (pctxt, ((e2ap_RICserviceLoadStatusRequest_protocolIEs_element*)pnode->data));
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        xx1++;
        RTXCTXTPOPARRAYELEMNAME(pctxt);
    }

    return (stat);
}

EXTERN int  asn1PD_e2ap_RICserviceLoadStatusRequest_protocolIEs(OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs* pvalue)
{
     int stat =0;
     OSRTDListNode* pnode;
     OSSIZE count =0;
     OSSIZE xx1=0;


     /*decode length determinant */
    PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(0), OSUINTCONST(ASN1V_e2ap_maxProtocolIEs), 0, 0);
    stat = pd_Length64(pctxt, &count); //tai sao lai 64
    if(stat!=0) return LOG_RTERR(pctxt, stat);

    /*decode each element*/
    rtxDListInit(pvalue);

    for(xx1=0; xx1 < count; xx1++){
        e2ap_RICserviceLoadStatusRequest_protocolIEs_element* pdata;
        RTXCTXTPUSHARRAYELEMNAME(pctxt, "SEQUENCE", &pnode, &pdata);

        if(pnode == NULL) return LOG_RTERR(pctxt, RTERR_NOMEM);

        asn1Init_e2ap_RICserviceLoadStatusRequest_protocolIEs_element(pdata);
        rtxDListAppendNode(pvalue, pnode);
       // stat = asn1PD_e2ap_RICserviceLoadStatusRequest_protocolIEs_element (pctxt, pdata);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        RTXCTXTPOPARRAYELEMNAME(pctxt);

    }
    return (stat);
}


int asn1Init_e2ap_RICserviceLoadStatusRequest_protocolIEs(e2ap_RICserviceLoadStatusRequest_protocolIEs* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    rtxDListFastInit (pvalue);
    return 0;
}

void asn1Free_e2ap_RICserviceLoadStatusRequest_protocolIEs(OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs* pvalue)
{
    if(0==pvalue) return;   
    e2ap_RICserviceLoadStatusRequest_protocolIEs_element* pdata;
    OSRTDListNode* pnode=pvalue->head;
    while(0!=pnode){
        pdata = (e2ap_RICserviceLoadStatusRequest_protocolIEs_element*)pnode->data;
       // asn1Free_e2ap_RICserviceLoadStatusRequest_protocolIEs_element(pctxt, pdata);
        pnode = pnode->next;
    }
    rtxDListFreeAll(pctxt, pvalue);
}

// --- End of e2ap_RICserviceLoadStatusRequest_protocolIEs.c ---

// --- Begin of e2ap_RICserviceLoadStatusRequest_protocolIEs_element.c ---
/*****************************************/
/*    RICserviceLoadStatusRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe

EXTERN int asn1PE_e2ap_RICserviceLoadStatusRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs_element* pvalue)
{
    int stat =0;

    /*encode id*/

    RTXCTXTPUSHELEMNAME(pctxt, "id");
        stat = asn1PE_e2ap_ProtocolIE_ID(pctxt, &pvalue->id);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*encode criticality*/
    RTXCTXTPUSHELEMNAME(pctxt, "criticality");
        stat = asn1PE_e2ap_Criticality(pctxt, &pvalue->criticality);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*encode value*/
    RTXCTXTPUSHELEMNAME(pctxt, "value");
        
    {
        OSCTXT lctxt;
        OSOCTET *pDynamicEncodeBuffer;
        ASN1OpenType openType;
        OSBOOL encoded = TRUE;

        openType.numocts = 0;
        openType.data =0;

        rtxCopyContext(&lctxt, pctxt);
        pctxt->pStream =0;

        stat = rtxInitContextBuffer(pctxt, 0, 0);
        if(stat!=0) return LOG_RTERR(pctxt, stat);

        switch(pvalue->value.t){
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_RICloadMeasurementID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RICloadMeasurementID");

                stat = asn1PE_e2ap_LoadMeasurementID (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RICloadMeasurementID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_E2nodeLoadMeasurementID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-E2nodeLoadMeasurementID");

                stat = asn1PE_e2ap_LoadMeasurementID (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_E2nodeLoadMeasurementID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RegistrationRequest");

                stat = asn1PE_e2ap_RegistrationRequest (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RANfunctionLoadRequest-List");

                stat = asn1PE_e2ap_RANfunctionLoadRequest_List (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-ReportingPeriodicity");

                stat = asn1PE_e2ap_ReportingPeriodicity (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_UNDEF_:
            {
                if(0!=pvalue->value.u.extElem1){
                    openType.numocts = pvalue->value.u.extElem1->numocts;
                    openType.data = pvalue->value.u.extElem1->data;
                } else {
                    /* No extension element to encode */
                }
                encoded = FALSE;
                break;
            }

            default:
                encoded = FALSE;
                stat = RTERR_INVOPT;
                break;
        } 

        if(encoded){
            openType.numocts = (OSUINT32)pe_GetMsgLen(pctxt);
            openType.data = pDynamicEncodeBuffer = pctxt -> buffer.data;
        }
        rtxCopyContext(pctxt, &lctxt);

        if(stat == 0) {
            stat = pe_OpenType (pctxt, openType.numocts, openType.data);
        }
    #if 0
        if(encoded){//dungnm23 check lai nhe
            rtxMemFreePtr(pctxt, pDynamicEncodeBuffer);
        }
    #endif

    }

    if(stat!=0) return LOG_RTERR(pctxt, stat);  
    RTXCTXTPOPELEMNAME(pctxt);
    return (stat);

}

EXTERN int  asn1PD_e2ap_RICserviceLoadStatusRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs_element* pvalue){
    int stat =0;

    /*decode id*/
    RTXCTXTPUSHELEMNAME(pctxt, "id");
        stat = asn1PD_e2ap_ProtocolIE_ID(pctxt, &pvalue->id);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*decode criticality*/
    RTXCTXTPUSHELEMNAME(pctxt, "criticality");
        stat = asn1PD_e2ap_Criticality(pctxt, &pvalue->criticality);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*decode value*/
    RTXCTXTPUSHELEMNAME(pctxt, "value");

    {
        OSUINT32 openTypeLen;
        size_t bitStartOffset, bitLength;

        stat = pd_UnconsLength(pctxt, &openTypeLen);
        if(stat<0) return LOG_RTERR(pctxt, stat);
        else if(stat == RT_OK_FRAG){
            rtxErrAddStrParm(pctxt, "open type with fragment length");
            return LOG_RTERRNEW(pctxt, RTERR_NOTSUPP);
        }
        bitStartOffset = PU_GETCTXBITOFFSET(pctxt);
        bitLength = openTypeLen * 8;

        switch(pvalue->id){//dungnm23 check case lai nhe
        
            case ASN1V_e2ap_id_RICloadMeasurementID:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RICloadMeasurementID");
            pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID 
                = rtxMemAllocType(pctxt, e2ap_LoadMeasurementID);

            asn1Init_e2ap_LoadMeasurementID(pvalue->
                value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID);

            stat = asn1PD_e2ap_LoadMeasurementID (pctxt,
                (e2ap_LoadMeasurementID*)pvalue->value.
                u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_E2nodeLoadMeasurementID:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2nodeLoadMeasurementID");
            pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID 
                = rtxMemAllocType(pctxt, e2ap_LoadMeasurementID);

            asn1Init_e2ap_LoadMeasurementID(pvalue->
                value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID);

            stat = asn1PD_e2ap_LoadMeasurementID (pctxt,
                (e2ap_LoadMeasurementID*)pvalue->value.
                u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_RegistrationRequest:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RegistrationRequest");
            pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest 
                = rtxMemAllocType(pctxt, e2ap_RegistrationRequest);

            asn1Init_e2ap_RegistrationRequest(pvalue->
                value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest);

            stat = asn1PD_e2ap_RegistrationRequest (pctxt,
                (e2ap_RegistrationRequest*)pvalue->value.
                u._e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_RANfunctionLoadRequest_List:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RANfunctionLoadRequest-List");
            pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List 
                = rtxMemAllocType(pctxt, e2ap_RANfunctionLoadRequest_List);

            asn1Init_e2ap_RANfunctionLoadRequest_List(pvalue->
                value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List);

            stat = asn1PD_e2ap_RANfunctionLoadRequest_List (pctxt,
                (e2ap_RANfunctionLoadRequest_List*)pvalue->value.
                u._e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_ReportingPeriodicity:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity;
            RTXCTXTPUSHELEMNAME(pctxt, "id-ReportingPeriodicity");
            pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity 
                = rtxMemAllocType(pctxt, e2ap_ReportingPeriodicity);

            asn1Init_e2ap_ReportingPeriodicity(pvalue->
                value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity);

            stat = asn1PD_e2ap_ReportingPeriodicity (pctxt,
                (e2ap_ReportingPeriodicity*)pvalue->value.
                u._e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    

        default:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_UNDEF_;
            pvalue->value.u.extElem1 = rtxMemAllocType(pctxt, ASN1OpenType);
            if(0==pvalue->value.u.extElem1){
                return LOG_RTERR(pctxt, RTERR_NOMEM);
            }

            {
                OSOCTET *pdata =(OSOCTET*) rtxMemAlloc(pctxt, openTypeLen);
                if(0==pdata){
                    return LOG_RTERR(pctxt, RTERR_NOMEM);
                }
                stat = rtxDecBitsToByteArray(pctxt, pdata, openTypeLen, openTypeLen*8);
                if(stat!=0){
                    rtxMemFreePtr(pctxt, pdata);
                    rtxMemFreePtr(pctxt, pvalue->value.u.extElem1);
                    return LOG_RTERR(pctxt, stat);
                }

                pvalue->value.u.extElem1->numocts = openTypeLen;
                pvalue->value.u.extElem1->data = pdata;
            }
            break;
    }
    {
    size_t bitEndOffset = PU_GETCTXBITOFFSET(pctxt);
    size_t bitsConsumed = bitEndOffset-bitStartOffset;
    if(bitsConsumed<bitLength){
        stat = pd_moveBitCursor(pctxt, (int)(bitLength - bitsConsumed));
    }
    else stat =(bitsConsumed > bitLength) ? ASN_E_INVLEN : 0;
    }}
    if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);
    return (stat);

}


int asn1Init_e2ap_RICserviceLoadStatusRequest_protocolIEs_element(e2ap_RICserviceLoadStatusRequest_protocolIEs_element* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    OSCRTLMEMSET (&pvalue->value, 0, sizeof(pvalue->value));
    return 0;
}


//-----> chuaw có template rtxFreeASN1OpenType
#if 0
void asn1Free_e2ap_RICserviceLoadStatusRequest_protocolIEs_element(OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs_element* pvalue)
{
    if(NULL==pvalue) return;
    switch(pvalue->value.t){
        case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID:
            // rtxFreeE2ap_LoadMeasurementID(pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID);

            if(pvalue->value.i._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID!=NULL){
            asn1Free_e2ap_LoadMeasurementID(pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID);
            pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID:
            // rtxFreeE2ap_LoadMeasurementID(pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID);

            if(pvalue->value.i._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID!=NULL){
            asn1Free_e2ap_LoadMeasurementID(pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID);
            pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest:
            // rtxFreeE2ap_RegistrationRequest(pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest);

            if(pvalue->value.i._e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest!=NULL){
            asn1Free_e2ap_RegistrationRequest(pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest);
            pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List:
            // rtxFreeE2ap_RANfunctionLoadRequest_List(pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List);

            if(pvalue->value.i._e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List!=NULL){
            asn1Free_e2ap_RANfunctionLoadRequest_List(pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List);
            pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity:
            // rtxFreeE2ap_ReportingPeriodicity(pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity);

            if(pvalue->value.i._e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity!=NULL){
            asn1Free_e2ap_ReportingPeriodicity(pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity);
            pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_UNDEF_:
            rtxFreeASN1OpenType(pvalue->value.u.extElem1);
            break;
        default:
            break;
    }
}

int asn1PrtToStr_e2ap_RICserviceLoadStatusRequest_protocolIEs_element(OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs_element* pvalue)
{
    int stat =0;
    RTXCTXTPUSHELEMNAME(pctxt, "e2ap_RICserviceLoadStatusRequest_protocolIEs_element");

    /*print id*/
    RTXCTXTPUSHELEMNAME(pctxt, "id");
        stat = asn1PrtToStr_e2ap_ProtocolIE_ID(pctxt, &pvalue->id);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*print criticality*/
    RTXCTXTPUSHELEMNAME(pctxt, "criticality");
        stat = asn1PrtToStr_e2ap_Criticality(pctxt, &pvalue->criticality);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*print value*/
    RTXCTXTPUSHELEMNAME(pctxt, "value");
        
        switch(pvalue->value.t){
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "LoadMeasurementID");

                stat = asn1PrtToStr_e2ap_LoadMeasurementID (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "LoadMeasurementID");

                stat = asn1PrtToStr_e2ap_LoadMeasurementID (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_LoadMeasurementID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RegistrationRequest");

                stat = asn1PrtToStr_e2ap_RegistrationRequest (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RANfunctionLoadRequest-List");

                stat = asn1PrtToStr_e2ap_RANfunctionLoadRequest_List (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "ReportingPeriodicity");

                stat = asn1PrtToStr_e2ap_ReportingPeriodicity (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_UNDEF_:
            {
                rtxPLogMsg(pctxt, "Extension element present - raw data not printed.\n");
                break;
            }

            default:
                stat = RTERR_INVOPT;
                return LOG_RTERR(pctxt, stat);
        }
    RTXCTXTPOPELEMNAME(pctxt);
    return (stat);
}
#endif
// --- End of e2ap_RICserviceLoadStatusRequest_protocolIEs_element.c ---

