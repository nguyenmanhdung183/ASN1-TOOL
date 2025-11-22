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

// --- Begin of e2ap_RICloadConfirm.c ---
/******************************************************/
/*                                                    */
/*    RICloadConfirm                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_RICloadConfirm_ENUMTAB[] = {
    { OSUTF8("true"), 0, 4, 0 }
};


const OSUTF8CHAR* e2ap_RICloadConfirm_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_RICloadConfirm_ENUMTABSIZE){
      return e2ap_RICloadConfirm_ENUMTAB[e2ap_RICloadConfirm_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_RICloadConfirm_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICloadConfirm* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_RICloadConfirm_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_RICloadConfirm_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICloadConfirm* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_RICloadConfirm_ENUMTAB, e2ap_RICloadConfirm_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_RICloadConfirm)e2ap_RICloadConfirm_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_RICloadConfirm (OSCTXT* pctxt, e2ap_RICloadConfirm value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICloadConfirm");
   if (value >= 1) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(0));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RICloadConfirm (OSCTXT* pctxt, e2ap_RICloadConfirm* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "RICloadConfirm");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(0));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RICloadConfirm (const char* name, e2ap_RICloadConfirm* pvalue, char* buffer, OSSIZE bufSize)
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
// --- End of e2ap_RICloadConfirm.c ---

// --- Begin of e2ap_RICserviceLoadConfirm.c ---

/*****************************************/
/*           RICserviceLoadConfirm                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICserviceLoadConfirm (OSCTXT* pctxt, e2ap_RICserviceLoadConfirm* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceLoadConfirm");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricServiceReportLoadConfirm */  
   if (pvalue->m_ricServiceReportLoadConfirmPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceReportLoadConfirm");
   stat = asn1PE_e2ap_RICloadConfirm (pctxt, &pvalue->ricServiceReportLoadConfirm);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceInsertLoadConfirm */  
   if (pvalue->m_ricServiceInsertLoadConfirmPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceInsertLoadConfirm");
   stat = asn1PE_e2ap_RICloadConfirm (pctxt, &pvalue->ricServiceInsertLoadConfirm);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceControlLoadConfirm */  
   if (pvalue->m_ricServiceControlLoadConfirmPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceControlLoadConfirm");
   stat = asn1PE_e2ap_RICloadConfirm (pctxt, &pvalue->ricServiceControlLoadConfirm);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServicePolicyLoadConfirm */  
   if (pvalue->m_ricServicePolicyLoadConfirmPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServicePolicyLoadConfirm");
   stat = asn1PE_e2ap_RICloadConfirm (pctxt, &pvalue->ricServicePolicyLoadConfirm);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceQueryLoadConfirm */  
   if (pvalue->m_ricServiceQueryLoadConfirmPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceQueryLoadConfirm");
   stat = asn1PE_e2ap_RICloadConfirm (pctxt, &pvalue->ricServiceQueryLoadConfirm);
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

int asn1PD_e2ap_RICserviceLoadConfirm (OSCTXT* pctxt, e2ap_RICserviceLoadConfirm* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[5];

   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceLoadConfirm");

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
   /* decode field ricServiceReportLoadConfirm */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceReportLoadConfirm");
   if (optbits[0]) {
      pvalue->m_ricServiceReportLoadConfirmPresent = TRUE;
      stat = asn1PD_e2ap_RICloadConfirm (pctxt, &pvalue->ricServiceReportLoadConfirm);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceReportLoadConfirmPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceInsertLoadConfirm */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceInsertLoadConfirm");
   if (optbits[0]) {
      pvalue->m_ricServiceInsertLoadConfirmPresent = TRUE;
      stat = asn1PD_e2ap_RICloadConfirm (pctxt, &pvalue->ricServiceInsertLoadConfirm);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceInsertLoadConfirmPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceControlLoadConfirm */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceControlLoadConfirm");
   if (optbits[0]) {
      pvalue->m_ricServiceControlLoadConfirmPresent = TRUE;
      stat = asn1PD_e2ap_RICloadConfirm (pctxt, &pvalue->ricServiceControlLoadConfirm);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceControlLoadConfirmPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServicePolicyLoadConfirm */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServicePolicyLoadConfirm");
   if (optbits[0]) {
      pvalue->m_ricServicePolicyLoadConfirmPresent = TRUE;
      stat = asn1PD_e2ap_RICloadConfirm (pctxt, &pvalue->ricServicePolicyLoadConfirm);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServicePolicyLoadConfirmPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceQueryLoadConfirm */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceQueryLoadConfirm");
   if (optbits[0]) {
      pvalue->m_ricServiceQueryLoadConfirmPresent = TRUE;
      stat = asn1PD_e2ap_RICloadConfirm (pctxt, &pvalue->ricServiceQueryLoadConfirm);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceQueryLoadConfirmPresent = FALSE;
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

int asn1Init_e2ap_RICserviceLoadConfirm (e2ap_RICserviceLoadConfirm* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RICloadConfirm (&pvalue->ricServiceReportLoadConfirm);
   asn1Init_e2ap_RICloadConfirm (&pvalue->ricServiceInsertLoadConfirm);
   asn1Init_e2ap_RICloadConfirm (&pvalue->ricServiceControlLoadConfirm);
   asn1Init_e2ap_RICloadConfirm (&pvalue->ricServicePolicyLoadConfirm);
   asn1Init_e2ap_RICloadConfirm (&pvalue->ricServiceQueryLoadConfirm);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICserviceLoadConfirm (OSCTXT* pctxt, e2ap_RICserviceLoadConfirm* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RICloadConfirm (pctxt, &pvalue->ricServiceReportLoadConfirm);
   asn1Free_e2ap_RICloadConfirm (pctxt, &pvalue->ricServiceInsertLoadConfirm);
   asn1Free_e2ap_RICloadConfirm (pctxt, &pvalue->ricServiceControlLoadConfirm);
   asn1Free_e2ap_RICloadConfirm (pctxt, &pvalue->ricServicePolicyLoadConfirm);
   asn1Free_e2ap_RICloadConfirm (pctxt, &pvalue->ricServiceQueryLoadConfirm);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICserviceLoadConfirm (const char* name, e2ap_RICserviceLoadConfirm* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadConfirm ("ricServiceReportLoadConfirm", &pvalue->ricServiceReportLoadConfirm, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadConfirm ("ricServiceInsertLoadConfirm", &pvalue->ricServiceInsertLoadConfirm, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadConfirm ("ricServiceControlLoadConfirm", &pvalue->ricServiceControlLoadConfirm, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadConfirm ("ricServicePolicyLoadConfirm", &pvalue->ricServicePolicyLoadConfirm, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadConfirm ("ricServiceQueryLoadConfirm", &pvalue->ricServiceQueryLoadConfirm, buffer, bufSize) < 0)
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
// --- End of e2ap_RICserviceLoadConfirm.c ---

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

// --- Begin of e2ap_RICactionLoadConfirm_Item.c ---

/*****************************************/
/*           RICactionLoadConfirm-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICactionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICactionLoadConfirm-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricActionID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionID");
   stat = asn1PE_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ricActionLoadConfirm */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionLoadConfirm");
   stat = asn1PE_e2ap_RICloadConfirm (pctxt, &pvalue->ricActionLoadConfirm);
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

int asn1PD_e2ap_RICactionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "RICactionLoadConfirm-Item");

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

   /* decode field ricActionLoadConfirm */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionLoadConfirm");
      stat = asn1PD_e2ap_RICloadConfirm (pctxt, &pvalue->ricActionLoadConfirm);
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

int asn1Init_e2ap_RICactionLoadConfirm_Item (e2ap_RICactionLoadConfirm_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RICactionID (&pvalue->ricActionID);
   asn1Init_e2ap_RICloadConfirm (&pvalue->ricActionLoadConfirm);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICactionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
   asn1Free_e2ap_RICloadConfirm (pctxt, &pvalue->ricActionLoadConfirm);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICactionLoadConfirm_Item (const char* name, e2ap_RICactionLoadConfirm_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICactionID ("ricActionID", &pvalue->ricActionID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadConfirm ("ricActionLoadConfirm", &pvalue->ricActionLoadConfirm, buffer, bufSize) < 0)
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
// --- End of e2ap_RICactionLoadConfirm_Item.c ---

// --- Begin of e2ap_RICactionLoadConfirm_ItemIEs.c ---
/* e2ap_RICactionLoadConfirm_ItemIEs.c */

/*****************************************/
/*           RICactionLoadConfirm_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_RICactionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICactionLoadConfirm-ItemIEs");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_RICactionLoadConfirm_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_RICactionLoadConfirm_ItemIEs_.criticality);
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
      case T_E2AP_PDU_Contents_RICactionLoadConfirm_ItemIEs_RICactionLoadConfirm_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "RICactionLoadConfirm_Item");
         stat = asn1PE_e2ap_RICactionLoadConfirm_Item (pctxt, pvalue->value.u._e2apRICactionLoadConfirm_ItemIEs_RICactionLoadConfirm_Item);
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

int asn1PD_e2ap_RICactionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_RICactionLoadConfirm_ItemIEs (e2ap_RICactionLoadConfirm_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_RICactionLoadConfirm_ItemIEs));
}

void asn1Free_e2ap_RICactionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
// --- End of e2ap_RICactionLoadConfirm_ItemIEs.c ---

// --- Begin of e2ap_RICactionLoadConfirm_List.c ---
/*****************************************/
/*           RICactionLoadConfirm_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_RICactionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICactionLoadConfirm_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICactionLoadConfirm-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRICactionID), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RICactionLoadConfirm_ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RICactionLoadConfirm_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RICactionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICactionLoadConfirm_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICactionLoadConfirm-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRICactionID), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RICactionLoadConfirm_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RICactionLoadConfirm_ItemIEs (pdata);

      stat = asn1PD_e2ap_RICactionLoadConfirm_ItemIEs (pctxt, pdata);
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

void asn1Init_e2ap_RICactionLoadConfirm_List (e2ap_RICactionLoadConfirm_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_RICactionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RICactionLoadConfirm_ItemIEs* pdata = (e2ap_RICactionLoadConfirm_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RICactionLoadConfirm_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}

#if 0
void asn1Free_e2ap_RICactionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_RICactionLoadConfirm_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_RICactionLoadConfirm_ItemIEs*)pnode->data;
         asn1Free_e2ap_RICactionLoadConfirm_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_RICactionLoadConfirm_List.c ---

// --- Begin of e2ap_RICsubscriptionLoadConfirm_ItemIE.c ---

/*****************************************/
/*           RICsubscriptionLoadConfirm-ItemIE                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICsubscriptionLoadConfirm_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_ItemIE* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICsubscriptionLoadConfirm-ItemIE");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricRequestID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricRequestID");
   stat = asn1PE_e2ap_RICrequestID (pctxt, &pvalue->ricRequestID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ricSubscriptionLoadConfirm */  
   if (pvalue->m_ricSubscriptionLoadConfirmPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricSubscriptionLoadConfirm");
   stat = asn1PE_e2ap_RICloadConfirm (pctxt, &pvalue->ricSubscriptionLoadConfirm);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricActionLoadConfirm_list */  
   if (pvalue->m_ricActionLoadConfirm_listPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionLoadConfirm-list");
   stat = asn1PE_e2ap_RICactionLoadConfirm_List (pctxt, &pvalue->ricActionLoadConfirm_list);
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

int asn1PD_e2ap_RICsubscriptionLoadConfirm_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_ItemIE* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[3];

   RTXCTXTPUSHTYPENAME(pctxt, "RICsubscriptionLoadConfirm-ItemIE");

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

   /* decode field ricSubscriptionLoadConfirm */
   RTXCTXTPUSHELEMNAME(pctxt, "ricSubscriptionLoadConfirm");
   if (optbits[0]) {
      pvalue->m_ricSubscriptionLoadConfirmPresent = TRUE;
      stat = asn1PD_e2ap_RICloadConfirm (pctxt, &pvalue->ricSubscriptionLoadConfirm);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricSubscriptionLoadConfirmPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricActionLoadConfirm_list */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionLoadConfirm-list");
   if (optbits[0]) {
      pvalue->m_ricActionLoadConfirm_listPresent = TRUE;
      stat = asn1PD_e2ap_RICactionLoadConfirm_List (pctxt, &pvalue->ricActionLoadConfirm_list);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricActionLoadConfirm_listPresent = FALSE;
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

int asn1Init_e2ap_RICsubscriptionLoadConfirm_ItemIE (e2ap_RICsubscriptionLoadConfirm_ItemIE* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RICrequestID (&pvalue->ricRequestID);
   asn1Init_e2ap_RICloadConfirm (&pvalue->ricSubscriptionLoadConfirm);
   asn1Init_e2ap_RICactionLoadConfirm_List (&pvalue->ricActionLoadConfirm_list);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICsubscriptionLoadConfirm_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_ItemIE* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RICrequestID (pctxt, &pvalue->ricRequestID);
   asn1Free_e2ap_RICloadConfirm (pctxt, &pvalue->ricSubscriptionLoadConfirm);
   asn1Free_e2ap_RICactionLoadConfirm_List (pctxt, &pvalue->ricActionLoadConfirm_list);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICsubscriptionLoadConfirm_ItemIE (const char* name, e2ap_RICsubscriptionLoadConfirm_ItemIE* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICrequestID ("ricRequestID", &pvalue->ricRequestID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadConfirm ("ricSubscriptionLoadConfirm", &pvalue->ricSubscriptionLoadConfirm, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICactionLoadConfirm_List ("ricActionLoadConfirm_list", &pvalue->ricActionLoadConfirm_list, buffer, bufSize) < 0)
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
// --- End of e2ap_RICsubscriptionLoadConfirm_ItemIE.c ---

// --- Begin of e2ap_RICsubscriptionLoadConfirm_ItemIEs.c ---
/* e2ap_RICsubscriptionLoadConfirm_ItemIEs.c */

/*****************************************/
/*           RICsubscriptionLoadConfirm_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_RICsubscriptionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICsubscriptionLoadConfirm-ItemIEs");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_RICsubscriptionLoadConfirm_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_RICsubscriptionLoadConfirm_ItemIEs_.criticality);
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
      case T_E2AP_PDU_Contents_RICsubscriptionLoadConfirm_ItemIEs_RICsubscriptionLoadConfirm_ItemIE:
         
         RTXCTXTPUSHELEMNAME (pctxt, "RICsubscriptionLoadConfirm_ItemIE");
         stat = asn1PE_e2ap_RICsubscriptionLoadConfirm_ItemIE (pctxt, pvalue->value.u._e2apRICsubscriptionLoadConfirm_ItemIEs_RICsubscriptionLoadConfirm_ItemIE);
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

int asn1PD_e2ap_RICsubscriptionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_RICsubscriptionLoadConfirm_ItemIEs (e2ap_RICsubscriptionLoadConfirm_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_RICsubscriptionLoadConfirm_ItemIEs));
}

void asn1Free_e2ap_RICsubscriptionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
// --- End of e2ap_RICsubscriptionLoadConfirm_ItemIEs.c ---

// --- Begin of e2ap_RICsubscriptionLoadConfirm_List.c ---
/*****************************************/
/*           RICsubscriptionLoadConfirm_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_RICsubscriptionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICsubscriptionLoadConfirm_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICsubscriptionLoadConfirm-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRICrequestID), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RICsubscriptionLoadConfirm_ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RICsubscriptionLoadConfirm_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RICsubscriptionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICsubscriptionLoadConfirm_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICsubscriptionLoadConfirm-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRICrequestID), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RICsubscriptionLoadConfirm_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RICsubscriptionLoadConfirm_ItemIEs (pdata);

      stat = asn1PD_e2ap_RICsubscriptionLoadConfirm_ItemIEs (pctxt, pdata);
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

void asn1Init_e2ap_RICsubscriptionLoadConfirm_List (e2ap_RICsubscriptionLoadConfirm_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_RICsubscriptionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RICsubscriptionLoadConfirm_ItemIEs* pdata = (e2ap_RICsubscriptionLoadConfirm_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RICsubscriptionLoadConfirm_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}

#if 0
void asn1Free_e2ap_RICsubscriptionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_RICsubscriptionLoadConfirm_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_RICsubscriptionLoadConfirm_ItemIEs*)pnode->data;
         asn1Free_e2ap_RICsubscriptionLoadConfirm_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_RICsubscriptionLoadConfirm_List.c ---

// --- Begin of e2ap_RANfunctionLoadConfirm_Item.c ---

/*****************************************/
/*           RANfunctionLoadConfirm-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RANfunctionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RANfunctionLoadConfirm-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ranFunctionID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionID");
   stat = asn1PE_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ranFunctionLoadConfirm */  
   if (pvalue->m_ranFunctionLoadConfirmPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionLoadConfirm");
   stat = asn1PE_e2ap_RICloadConfirm (pctxt, &pvalue->ranFunctionLoadConfirm);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricServiceLoadConfirm */  
   if (pvalue->m_ricServiceLoadConfirmPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceLoadConfirm");
   stat = asn1PE_e2ap_RICserviceLoadConfirm (pctxt, &pvalue->ricServiceLoadConfirm);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricSubscriptionLoadConfirm_list */  
   if (pvalue->m_ricSubscriptionLoadConfirm_listPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricSubscriptionLoadConfirm-list");
   stat = asn1PE_e2ap_RICsubscriptionLoadConfirm_List (pctxt, &pvalue->ricSubscriptionLoadConfirm_list);
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

int asn1PD_e2ap_RANfunctionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[4];

   RTXCTXTPUSHTYPENAME(pctxt, "RANfunctionLoadConfirm-Item");

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

   /* decode field ranFunctionLoadConfirm */
   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionLoadConfirm");
   if (optbits[0]) {
      pvalue->m_ranFunctionLoadConfirmPresent = TRUE;
      stat = asn1PD_e2ap_RICloadConfirm (pctxt, &pvalue->ranFunctionLoadConfirm);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ranFunctionLoadConfirmPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricServiceLoadConfirm */
   RTXCTXTPUSHELEMNAME(pctxt, "ricServiceLoadConfirm");
   if (optbits[0]) {
      pvalue->m_ricServiceLoadConfirmPresent = TRUE;
      stat = asn1PD_e2ap_RICserviceLoadConfirm (pctxt, &pvalue->ricServiceLoadConfirm);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricServiceLoadConfirmPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricSubscriptionLoadConfirm_list */
   RTXCTXTPUSHELEMNAME(pctxt, "ricSubscriptionLoadConfirm-list");
   if (optbits[0]) {
      pvalue->m_ricSubscriptionLoadConfirm_listPresent = TRUE;
      stat = asn1PD_e2ap_RICsubscriptionLoadConfirm_List (pctxt, &pvalue->ricSubscriptionLoadConfirm_list);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricSubscriptionLoadConfirm_listPresent = FALSE;
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

int asn1Init_e2ap_RANfunctionLoadConfirm_Item (e2ap_RANfunctionLoadConfirm_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RANfunctionID (&pvalue->ranFunctionID);
   asn1Init_e2ap_RICloadConfirm (&pvalue->ranFunctionLoadConfirm);
   asn1Init_e2ap_RICserviceLoadConfirm (&pvalue->ricServiceLoadConfirm);
   asn1Init_e2ap_RICsubscriptionLoadConfirm_List (&pvalue->ricSubscriptionLoadConfirm_list);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RANfunctionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   asn1Free_e2ap_RICloadConfirm (pctxt, &pvalue->ranFunctionLoadConfirm);
   asn1Free_e2ap_RICserviceLoadConfirm (pctxt, &pvalue->ricServiceLoadConfirm);
   asn1Free_e2ap_RICsubscriptionLoadConfirm_List (pctxt, &pvalue->ricSubscriptionLoadConfirm_list);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RANfunctionLoadConfirm_Item (const char* name, e2ap_RANfunctionLoadConfirm_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RANfunctionID ("ranFunctionID", &pvalue->ranFunctionID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICloadConfirm ("ranFunctionLoadConfirm", &pvalue->ranFunctionLoadConfirm, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICserviceLoadConfirm ("ricServiceLoadConfirm", &pvalue->ricServiceLoadConfirm, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICsubscriptionLoadConfirm_List ("ricSubscriptionLoadConfirm_list", &pvalue->ricSubscriptionLoadConfirm_list, buffer, bufSize) < 0)
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
// --- End of e2ap_RANfunctionLoadConfirm_Item.c ---

// --- Begin of e2ap_RANfunctionLoadConfirm_ItemIEs.c ---
/* e2ap_RANfunctionLoadConfirm_ItemIEs.c */

/*****************************************/
/*           RANfunctionLoadConfirm_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_RANfunctionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionLoadConfirm-ItemIEs");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_RANfunctionLoadConfirm_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_RANfunctionLoadConfirm_ItemIEs_.criticality);
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
      case T_E2AP_PDU_Contents_RANfunctionLoadConfirm_ItemIEs_RANfunctionLoadConfirm_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "RANfunctionLoadConfirm_Item");
         stat = asn1PE_e2ap_RANfunctionLoadConfirm_Item (pctxt, pvalue->value.u._e2apRANfunctionLoadConfirm_ItemIEs_RANfunctionLoadConfirm_Item);
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

int asn1PD_e2ap_RANfunctionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_RANfunctionLoadConfirm_ItemIEs (e2ap_RANfunctionLoadConfirm_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_RANfunctionLoadConfirm_ItemIEs));
}

void asn1Free_e2ap_RANfunctionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
// --- End of e2ap_RANfunctionLoadConfirm_ItemIEs.c ---

// --- Begin of e2ap_RANfunctionLoadConfirm_List.c ---
/*****************************************/
/*           RANfunctionLoadConfirm_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_RANfunctionLoadConfirm_List (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RANfunctionLoadConfirm_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionLoadConfirm-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRANfunctionID), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RANfunctionLoadConfirm_ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RANfunctionLoadConfirm_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RANfunctionLoadConfirm_List (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RANfunctionLoadConfirm_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionLoadConfirm-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRANfunctionID), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RANfunctionLoadConfirm_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RANfunctionLoadConfirm_ItemIEs (pdata);

      stat = asn1PD_e2ap_RANfunctionLoadConfirm_ItemIEs (pctxt, pdata);
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

void asn1Init_e2ap_RANfunctionLoadConfirm_List (e2ap_RANfunctionLoadConfirm_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_RANfunctionLoadConfirm_List (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RANfunctionLoadConfirm_ItemIEs* pdata = (e2ap_RANfunctionLoadConfirm_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RANfunctionLoadConfirm_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}

#if 0
void asn1Free_e2ap_RANfunctionLoadConfirm_List (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_RANfunctionLoadConfirm_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_RANfunctionLoadConfirm_ItemIEs*)pnode->data;
         asn1Free_e2ap_RANfunctionLoadConfirm_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_RANfunctionLoadConfirm_List.c ---

/************************************************************/
/* File .c missing: e2ap_RICserviceLoadStatusResponse_IEs.c */
/************************************************************/

// --- Begin of e2ap_RICserviceLoadStatusResponse.c ---

/*****************************************/
/*           RICserviceLoadStatusResponse                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICserviceLoadStatusResponse (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceLoadStatusResponse");

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

int asn1PD_e2ap_RICserviceLoadStatusResponse (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceLoadStatusResponse");

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

int asn1Init_e2ap_RICserviceLoadStatusResponse (e2ap_RICserviceLoadStatusResponse* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_ProtocolIE_Container (&pvalue->protocolIEs);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICserviceLoadStatusResponse (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_ProtocolIE_Container (pctxt, &pvalue->protocolIEs);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICserviceLoadStatusResponse (const char* name, e2ap_RICserviceLoadStatusResponse* pvalue, char* buffer, OSSIZE bufSize)
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
// --- End of e2ap_RICserviceLoadStatusResponse.c ---

// --- Begin of e2ap_RICserviceLoadStatusResponse_protocolIEs.c ---
/******************************************************/
/*                                                    */
/*    RICserviceLoadStatusResponse_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

EXTERN int asn1PE_e2ap_RICserviceLoadStatusResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEst* pvalue)
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
        stat = asn1PE_e2ap_RICserviceLoadStatusResponse_protocolIEs_element (pctxt, ((e2ap_RICserviceLoadStatusResponse_protocolIEs_element*)pnode->data));
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        xx1++;
        RTXCTXTPOPARRAYELEMNAME(pctxt);
    }

    return (stat);
}

EXTERN int  asn1PD_e2ap_RICserviceLoadStatusResponse_protocolIEs(OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs* pvalue)
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
        e2ap_RICserviceLoadStatusResponse_protocolIEs_element* pdata;
        RTXCTXTPUSHARRAYELEMNAME(pctxt, "SEQUENCE", &pnode, &pdata);

        if(pnode == NULL) return LOG_RTERR(pctxt, RTERR_NOMEM);

        asn1Init_e2ap_RICserviceLoadStatusResponse_protocolIEs_element(pdata);
        rtxDListAppendNode(pvalue, pnode);
       // stat = asn1PD_e2ap_RICserviceLoadStatusResponse_protocolIEs_element (pctxt, pdata);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        RTXCTXTPOPARRAYELEMNAME(pctxt);

    }
    return (stat);
}


int asn1Init_e2ap_RICserviceLoadStatusResponse_protocolIEs(e2ap_RICserviceLoadStatusResponse_protocolIEs* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    rtxDListFastInit (pvalue);
    return 0;
}

void asn1Free_e2ap_RICserviceLoadStatusResponse_protocolIEs(OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs* pvalue)
{
    if(0==pvalue) return;   
    e2ap_RICserviceLoadStatusResponse_protocolIEs_element* pdata;
    OSRTDListNode* pnode=pvalue->head;
    while(0!=pnode){
        pdata = (e2ap_RICserviceLoadStatusResponse_protocolIEs_element*)pnode->data;
       // asn1Free_e2ap_RICserviceLoadStatusResponse_protocolIEs_element(pctxt, pdata);
        pnode = pnode->next;
    }
    rtxDListFreeAll(pctxt, pvalue);
}

// --- End of e2ap_RICserviceLoadStatusResponse_protocolIEs.c ---

// --- Begin of e2ap_RICserviceLoadStatusResponse_protocolIEs_element.c ---
/*****************************************/
/*    RICserviceLoadStatusResponse_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe

EXTERN int asn1PE_e2ap_RICserviceLoadStatusResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs_element* pvalue)
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
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_RICloadMeasurementID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RICloadMeasurementID");

                stat = asn1PE_e2ap_LoadMeasurementID (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_RICloadMeasurementID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_E2nodeLoadMeasurementID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-E2nodeLoadMeasurementID");

                stat = asn1PE_e2ap_LoadMeasurementID (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_E2nodeLoadMeasurementID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RANfunctionLoadConfirm-List");

                stat = asn1PE_e2ap_RANfunctionLoadConfirm_List (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_UNDEF_:
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

EXTERN int  asn1PD_e2ap_RICserviceLoadStatusResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs_element* pvalue){
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
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RICloadMeasurementID");
            pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID 
                = rtxMemAllocType(pctxt, e2ap_LoadMeasurementID);

            asn1Init_e2ap_LoadMeasurementID(pvalue->
                value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID);

            stat = asn1PD_e2ap_LoadMeasurementID (pctxt,
                (e2ap_LoadMeasurementID*)pvalue->value.
                u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_E2nodeLoadMeasurementID:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2nodeLoadMeasurementID");
            pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID 
                = rtxMemAllocType(pctxt, e2ap_LoadMeasurementID);

            asn1Init_e2ap_LoadMeasurementID(pvalue->
                value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID);

            stat = asn1PD_e2ap_LoadMeasurementID (pctxt,
                (e2ap_LoadMeasurementID*)pvalue->value.
                u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_RANfunctionLoadConfirm_List:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RANfunctionLoadConfirm-List");
            pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List 
                = rtxMemAllocType(pctxt, e2ap_RANfunctionLoadConfirm_List);

            asn1Init_e2ap_RANfunctionLoadConfirm_List(pvalue->
                value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List);

            stat = asn1PD_e2ap_RANfunctionLoadConfirm_List (pctxt,
                (e2ap_RANfunctionLoadConfirm_List*)pvalue->value.
                u._e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    

        default:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_UNDEF_;
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


int asn1Init_e2ap_RICserviceLoadStatusResponse_protocolIEs_element(e2ap_RICserviceLoadStatusResponse_protocolIEs_element* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    OSCRTLMEMSET (&pvalue->value, 0, sizeof(pvalue->value));
    return 0;
}


//-----> chuaw có template rtxFreeASN1OpenType
#if 0
void asn1Free_e2ap_RICserviceLoadStatusResponse_protocolIEs_element(OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs_element* pvalue)
{
    if(NULL==pvalue) return;
    switch(pvalue->value.t){
        case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID:
            // rtxFreeE2ap_LoadMeasurementID(pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID);

            if(pvalue->value.i._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID!=NULL){
            asn1Free_e2ap_LoadMeasurementID(pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID);
            pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID:
            // rtxFreeE2ap_LoadMeasurementID(pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID);

            if(pvalue->value.i._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID!=NULL){
            asn1Free_e2ap_LoadMeasurementID(pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID);
            pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List:
            // rtxFreeE2ap_RANfunctionLoadConfirm_List(pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List);

            if(pvalue->value.i._e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List!=NULL){
            asn1Free_e2ap_RANfunctionLoadConfirm_List(pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List);
            pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_UNDEF_:
            rtxFreeASN1OpenType(pvalue->value.u.extElem1);
            break;
        default:
            break;
    }
}

int asn1PrtToStr_e2ap_RICserviceLoadStatusResponse_protocolIEs_element(OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs_element* pvalue)
{
    int stat =0;
    RTXCTXTPUSHELEMNAME(pctxt, "e2ap_RICserviceLoadStatusResponse_protocolIEs_element");

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
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "LoadMeasurementID");

                stat = asn1PrtToStr_e2ap_LoadMeasurementID (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "LoadMeasurementID");

                stat = asn1PrtToStr_e2ap_LoadMeasurementID (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_LoadMeasurementID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RANfunctionLoadConfirm-List");

                stat = asn1PrtToStr_e2ap_RANfunctionLoadConfirm_List (pctxt, pvalue->value.u._e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_UNDEF_:
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
// --- End of e2ap_RICserviceLoadStatusResponse_protocolIEs_element.c ---

