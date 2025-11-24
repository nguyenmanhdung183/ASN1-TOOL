#include "output_main.h"
// --- Begin of doc/header.c ---
//======================E2AP.c========================//
// --- End of doc/header.c ---

// --- Begin of e2ap_TransactionID.c ---
/*****************************************/
/*           TransactionID                */
/*****************************************/

//6 mau octet string



// mau integer size(a...b) mau la procedurecode
EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value){
    int stat = 0;
    RTXCTCXTPUSHTYPENAME (pctxt, "TransactionID");
    stat = pe_ConsUnsigned (pctxt, value, -1, -1);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
EXTERN int asn1PD_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID* pvalue){
    int stat = 0;
    RTXCTCXTPUSHTYPENAME (pctxt, "TransactionID");
    if(pctxt->buffer.aligned){
        int stat2 = PD_BYTE_ALIGN(pctxt);
        if(stat2 != 0) return LOG_RTERR (pctxt, stat2);
    }
    stat = rtxDecBitsToByte(pctxt, pvalue, 0);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
//EXTERN int asn1Print_e2ap_TransactionID (const char* name, const e2ap_TransactionID* pvalue);
//EXTERN int asn1PrtToStr_e2ap_TransactionID (const char* name, e2ap_TransactionID* pvalue, char* buffer, OSSIZE bufSize);
//EXTERN int asn1PrtToStrm_e2ap_TransactionID (OSCTXT* pctxt, const char* name, const e2ap_TransactionID* pvalue);




// --- End of e2ap_TransactionID.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceType.c ---
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

   if(rtPrintToStringIndent(buffer, bufSize) < 0) return -1;
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
// --- End of e2ap_E2nodeComponentInterfaceType.c ---

/*******************************************/
/* File .c missing: e2ap_PrintableString.c */
/*******************************************/

// --- Begin of e2ap_AMFName.c ---
/* e2ap_AMFName.c */

//printable string
/*****************************************/
/*           AMFName                */
/*****************************************/

/* Constrained PrintableString */
EXTERN int asn1PE_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "AMFName");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(150), OSUINTCONST(0), OSUINT32_MAX);

   char c = (char) rtValidateStr (19, value);  /* 19 = PrintableString */
   if (c != 0) {
      char lbuf[2];
      lbuf[0] = c;
      lbuf[1] = 0;

      rtxErrAddEleNameParm(pctxt);
      rtxErrAddStrParm (pctxt, lbuf);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   stat = pe_ConstrainedStringEx (pctxt, value, 0, 8, 7, 7);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName* ppvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "AMFName");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(150), OSUINTCONST(0), OSUINT32_MAX);

   stat = pd_ConstrainedStringEx (pctxt, ppvalue, 0, 8, 7, 7);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}


void asn1Free_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName pvalue)
{
   if(0==pvalue) return;
   rtxMemFreePtr (pctxt, (void*)pvalue);
   pvalue = 0;
}

/* Print to string */
int asn1PrtToStr_e2ap_AMFName (const char* name, e2ap_AMFName pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringCharStr (name, pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_AMFName.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceNG.c ---

/*****************************************/
/*           E2nodeComponentInterfaceNG                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceNG");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field amf_name */  

   RTXCTXTPUSHELEMNAME(pctxt, "amf-name");
   stat = asn1PE_e2ap_AMFName (pctxt, &pvalue->amf_name);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceNG");

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
   /* decode field amf_name */
   RTXCTXTPUSHELEMNAME(pctxt, "amf-name");


      stat = asn1PD_e2ap_AMFName (pctxt, &pvalue->amf_name);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_E2nodeComponentInterfaceNG (e2ap_E2nodeComponentInterfaceNG* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_AMFName (&pvalue->amf_name);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_AMFName (pctxt, &pvalue->amf_name);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentInterfaceNG (const char* name, e2ap_E2nodeComponentInterfaceNG* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_AMFName ("amf_name", &pvalue->amf_name, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeComponentInterfaceNG.c ---

// --- Begin of e2ap_PLMN_Identity.c ---
/*****************************************/
/*           PLMN_Identity                */
/*****************************************/

//8 mau octet string

//type 8  mau la octet string size(n) mau la plmn_identity
EXTERN int asn1PE_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue){
   int stat = 0;
   RTXCTCXTPUSHTYPENAME (pctxt, "PLMN-Identity");
   PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(), OSUINTCONST(), 0, 0);

   stat = pe_OctetString(pctxt, pvalue->numocts, pvalue->data);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}
EXTERN int asn1PD_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue){
   int stat = 0;
   RTXCTCXTPUSHTYPENAME (pctxt, "PLMN-Identity");
   PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(), OSUINTCONST(), 0, 0);

   stat = pd_OctetString(pctxt, &pvalue->numocts, pvalue->data, sizeof(pvalue->data));
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}
//EXTERN int asn1PrtToStr_e2ap_PLMN_Identity (const char* name, e2ap_PLMN_Identity* pvalue, char* buffer, OSSIZE bufSize);
//EXTERN int asn1PrtToStrm_e2ap_PLMN_Identity (OSCTXT* pctxt, const char* name, const e2ap_PLMN_Identity* pvalue);
//EXTERN int asn1Copy_e2ap_PLMN_Identity (OSCTXT* pctxt, const e2ap_PLMN_Identity* pSrcValue, e2ap_PLMN_Identity* pDstValue);

int asn1Init_e2ap_PLMN_Identity (e2ap_PLMN_Identity* pvalue){
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->numocts = 0;
   return 0;
}



// --- End of e2ap_PLMN_Identity.c ---

/**********************************/
/* File .c missing: e2ap_gnb_ID.c */
/**********************************/

/*****************************************/
/* File .c missing: e2ap_GNB_ID_Choice.c */
/*****************************************/

// --- Begin of e2ap_GlobalgNB_ID.c ---

/*****************************************/
/*           GlobalgNB-ID                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "GlobalgNB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field plmn_id */  

   RTXCTXTPUSHELEMNAME(pctxt, "plmn-id");
   stat = asn1PE_e2ap_PLMN_Identity (pctxt, &pvalue->plmn_id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field gnb_id */  

   RTXCTXTPUSHELEMNAME(pctxt, "gnb-id");
   stat = asn1PE_e2ap_GNB_ID_Choice (pctxt, &pvalue->gnb_id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "GlobalgNB-ID");

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
   /* decode field plmn_id */
   RTXCTXTPUSHELEMNAME(pctxt, "plmn-id");


      stat = asn1PD_e2ap_PLMN_Identity (pctxt, &pvalue->plmn_id);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field gnb_id */
   RTXCTXTPUSHELEMNAME(pctxt, "gnb-id");


      stat = asn1PD_e2ap_GNB_ID_Choice (pctxt, &pvalue->gnb_id);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_GlobalgNB_ID (e2ap_GlobalgNB_ID* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_PLMN_Identity (&pvalue->plmn_id);
   asn1Init_e2ap_GNB_ID_Choice (&pvalue->gnb_id);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_PLMN_Identity (pctxt, &pvalue->plmn_id);
   asn1Free_e2ap_GNB_ID_Choice (pctxt, &pvalue->gnb_id);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_GlobalgNB_ID (const char* name, e2ap_GlobalgNB_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_PLMN_Identity ("plmn_id", &pvalue->plmn_id, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GNB_ID_Choice ("gnb_id", &pvalue->gnb_id, buffer, bufSize) < 0)
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
// --- End of e2ap_GlobalgNB_ID.c ---

/****************************************/
/* File .c missing: e2ap_enb_ID_macro.c */
/****************************************/

/*********************************************/
/* File .c missing: e2ap_enb_ID_shortmacro.c */
/*********************************************/

/********************************************/
/* File .c missing: e2ap_enb_ID_longmacro.c */
/********************************************/

/*****************************************/
/* File .c missing: e2ap_ENB_ID_Choice.c */
/*****************************************/

// --- Begin of e2ap_GlobalngeNB_ID.c ---

/*****************************************/
/*           GlobalngeNB-ID                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "GlobalngeNB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field plmn_id */  

   RTXCTXTPUSHELEMNAME(pctxt, "plmn-id");
   stat = asn1PE_e2ap_PLMN_Identity (pctxt, &pvalue->plmn_id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field enb_id */  

   RTXCTXTPUSHELEMNAME(pctxt, "enb-id");
   stat = asn1PE_e2ap_ENB_ID_Choice (pctxt, &pvalue->enb_id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "GlobalngeNB-ID");

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
   /* decode field plmn_id */
   RTXCTXTPUSHELEMNAME(pctxt, "plmn-id");


      stat = asn1PD_e2ap_PLMN_Identity (pctxt, &pvalue->plmn_id);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field enb_id */
   RTXCTXTPUSHELEMNAME(pctxt, "enb-id");


      stat = asn1PD_e2ap_ENB_ID_Choice (pctxt, &pvalue->enb_id);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_GlobalngeNB_ID (e2ap_GlobalngeNB_ID* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_PLMN_Identity (&pvalue->plmn_id);
   asn1Init_e2ap_ENB_ID_Choice (&pvalue->enb_id);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_PLMN_Identity (pctxt, &pvalue->plmn_id);
   asn1Free_e2ap_ENB_ID_Choice (pctxt, &pvalue->enb_id);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_GlobalngeNB_ID (const char* name, e2ap_GlobalngeNB_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_PLMN_Identity ("plmn_id", &pvalue->plmn_id, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ENB_ID_Choice ("enb_id", &pvalue->enb_id, buffer, bufSize) < 0)
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
// --- End of e2ap_GlobalngeNB_ID.c ---

/***********************************************/
/* File .c missing: e2ap_GlobalNG_RANNode_ID.c */
/***********************************************/

// --- Begin of e2ap_E2nodeComponentInterfaceXn.c ---

/*****************************************/
/*           E2nodeComponentInterfaceXn                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceXn");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field global_NG_RAN_Node_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "global-NG-RAN-Node-ID");
   stat = asn1PE_e2ap_GlobalNG_RANNode_ID (pctxt, &pvalue->global_NG_RAN_Node_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceXn");

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
   /* decode field global_NG_RAN_Node_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-NG-RAN-Node-ID");


      stat = asn1PD_e2ap_GlobalNG_RANNode_ID (pctxt, &pvalue->global_NG_RAN_Node_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_E2nodeComponentInterfaceXn (e2ap_E2nodeComponentInterfaceXn* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_GlobalNG_RANNode_ID (&pvalue->global_NG_RAN_Node_ID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_GlobalNG_RANNode_ID (pctxt, &pvalue->global_NG_RAN_Node_ID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentInterfaceXn (const char* name, e2ap_E2nodeComponentInterfaceXn* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GlobalNG_RANNode_ID ("global_NG_RAN_Node_ID", &pvalue->global_NG_RAN_Node_ID, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeComponentInterfaceXn.c ---

// --- Begin of e2ap_GNB_CU_UP_ID.c ---
/*****************************************/
/*           GNB_CU_UP_ID                */
/*****************************************/

//6 mau octet string



// mau integer size(a...b) mau la procedurecode
EXTERN int asn1PE_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID value){
    int stat = 0;
    RTXCTCXTPUSHTYPENAME (pctxt, "GNB-CU-UP-ID");
    stat = pe_ConsUnsigned (pctxt, value, 0, 68719476735);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
EXTERN int asn1PD_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID* pvalue){
    int stat = 0;
    RTXCTCXTPUSHTYPENAME (pctxt, "GNB-CU-UP-ID");
    if(pctxt->buffer.aligned){
        int stat2 = PD_BYTE_ALIGN(pctxt);
        if(stat2 != 0) return LOG_RTERR (pctxt, stat2);
    }
    stat = rtxDecBitsToByte(pctxt, pvalue, 0);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
//EXTERN int asn1Print_e2ap_GNB_CU_UP_ID (const char* name, const e2ap_GNB_CU_UP_ID* pvalue);
//EXTERN int asn1PrtToStr_e2ap_GNB_CU_UP_ID (const char* name, e2ap_GNB_CU_UP_ID* pvalue, char* buffer, OSSIZE bufSize);
//EXTERN int asn1PrtToStrm_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, const char* name, const e2ap_GNB_CU_UP_ID* pvalue);




// --- End of e2ap_GNB_CU_UP_ID.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceE1.c ---

/*****************************************/
/*           E2nodeComponentInterfaceE1                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceE1");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field gNB_CU_UP_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "gNB-CU-UP-ID");
   stat = asn1PE_e2ap_GNB_CU_UP_ID (pctxt, &pvalue->gNB_CU_UP_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceE1");

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
   /* decode field gNB_CU_UP_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "gNB-CU-UP-ID");


      stat = asn1PD_e2ap_GNB_CU_UP_ID (pctxt, &pvalue->gNB_CU_UP_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_E2nodeComponentInterfaceE1 (e2ap_E2nodeComponentInterfaceE1* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_GNB_CU_UP_ID (&pvalue->gNB_CU_UP_ID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_GNB_CU_UP_ID (pctxt, &pvalue->gNB_CU_UP_ID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentInterfaceE1 (const char* name, e2ap_E2nodeComponentInterfaceE1* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GNB_CU_UP_ID ("gNB_CU_UP_ID", &pvalue->gNB_CU_UP_ID, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeComponentInterfaceE1.c ---

// --- Begin of e2ap_GNB_DU_ID.c ---
/*****************************************/
/*           GNB_DU_ID                */
/*****************************************/

//6 mau octet string



// mau integer size(a...b) mau la procedurecode
EXTERN int asn1PE_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID value){
    int stat = 0;
    RTXCTCXTPUSHTYPENAME (pctxt, "GNB-DU-ID");
    stat = pe_ConsUnsigned (pctxt, value, 0, 68719476735);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
EXTERN int asn1PD_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID* pvalue){
    int stat = 0;
    RTXCTCXTPUSHTYPENAME (pctxt, "GNB-DU-ID");
    if(pctxt->buffer.aligned){
        int stat2 = PD_BYTE_ALIGN(pctxt);
        if(stat2 != 0) return LOG_RTERR (pctxt, stat2);
    }
    stat = rtxDecBitsToByte(pctxt, pvalue, 0);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
//EXTERN int asn1Print_e2ap_GNB_DU_ID (const char* name, const e2ap_GNB_DU_ID* pvalue);
//EXTERN int asn1PrtToStr_e2ap_GNB_DU_ID (const char* name, e2ap_GNB_DU_ID* pvalue, char* buffer, OSSIZE bufSize);
//EXTERN int asn1PrtToStrm_e2ap_GNB_DU_ID (OSCTXT* pctxt, const char* name, const e2ap_GNB_DU_ID* pvalue);




// --- End of e2ap_GNB_DU_ID.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceF1.c ---

/*****************************************/
/*           E2nodeComponentInterfaceF1                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceF1");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field gNB_DU_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "gNB-DU-ID");
   stat = asn1PE_e2ap_GNB_DU_ID (pctxt, &pvalue->gNB_DU_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceF1");

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
   /* decode field gNB_DU_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "gNB-DU-ID");


      stat = asn1PD_e2ap_GNB_DU_ID (pctxt, &pvalue->gNB_DU_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_E2nodeComponentInterfaceF1 (e2ap_E2nodeComponentInterfaceF1* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_GNB_DU_ID (&pvalue->gNB_DU_ID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_GNB_DU_ID (pctxt, &pvalue->gNB_DU_ID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentInterfaceF1 (const char* name, e2ap_E2nodeComponentInterfaceF1* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GNB_DU_ID ("gNB_DU_ID", &pvalue->gNB_DU_ID, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeComponentInterfaceF1.c ---

// --- Begin of e2ap_NGENB_DU_ID.c ---
/*****************************************/
/*           NGENB_DU_ID                */
/*****************************************/

//6 mau octet string



// mau integer size(a...b) mau la procedurecode
EXTERN int asn1PE_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID value){
    int stat = 0;
    RTXCTCXTPUSHTYPENAME (pctxt, "NGENB-DU-ID");
    stat = pe_ConsUnsigned (pctxt, value, 0, 68719476735);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
EXTERN int asn1PD_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID* pvalue){
    int stat = 0;
    RTXCTCXTPUSHTYPENAME (pctxt, "NGENB-DU-ID");
    if(pctxt->buffer.aligned){
        int stat2 = PD_BYTE_ALIGN(pctxt);
        if(stat2 != 0) return LOG_RTERR (pctxt, stat2);
    }
    stat = rtxDecBitsToByte(pctxt, pvalue, 0);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
//EXTERN int asn1Print_e2ap_NGENB_DU_ID (const char* name, const e2ap_NGENB_DU_ID* pvalue);
//EXTERN int asn1PrtToStr_e2ap_NGENB_DU_ID (const char* name, e2ap_NGENB_DU_ID* pvalue, char* buffer, OSSIZE bufSize);
//EXTERN int asn1PrtToStrm_e2ap_NGENB_DU_ID (OSCTXT* pctxt, const char* name, const e2ap_NGENB_DU_ID* pvalue);




// --- End of e2ap_NGENB_DU_ID.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceW1.c ---

/*****************************************/
/*           E2nodeComponentInterfaceW1                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceW1");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ng_eNB_DU_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ng-eNB-DU-ID");
   stat = asn1PE_e2ap_NGENB_DU_ID (pctxt, &pvalue->ng_eNB_DU_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceW1");

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
   /* decode field ng_eNB_DU_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "ng-eNB-DU-ID");


      stat = asn1PD_e2ap_NGENB_DU_ID (pctxt, &pvalue->ng_eNB_DU_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_E2nodeComponentInterfaceW1 (e2ap_E2nodeComponentInterfaceW1* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_NGENB_DU_ID (&pvalue->ng_eNB_DU_ID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_NGENB_DU_ID (pctxt, &pvalue->ng_eNB_DU_ID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentInterfaceW1 (const char* name, e2ap_E2nodeComponentInterfaceW1* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_NGENB_DU_ID ("ng_eNB_DU_ID", &pvalue->ng_eNB_DU_ID, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeComponentInterfaceW1.c ---

/***********************************/
/* File .c missing: e2ap_MMEname.c */
/***********************************/

// --- Begin of e2ap_E2nodeComponentInterfaceS1.c ---

/*****************************************/
/*           E2nodeComponentInterfaceS1                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceS1");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field mme_name */  

   RTXCTXTPUSHELEMNAME(pctxt, "mme-name");
   stat = asn1PE_e2ap_MMEname (pctxt, &pvalue->mme_name);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceS1");

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
   /* decode field mme_name */
   RTXCTXTPUSHELEMNAME(pctxt, "mme-name");


      stat = asn1PD_e2ap_MMEname (pctxt, &pvalue->mme_name);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_E2nodeComponentInterfaceS1 (e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_MMEname (&pvalue->mme_name);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_MMEname (pctxt, &pvalue->mme_name);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentInterfaceS1 (const char* name, e2ap_E2nodeComponentInterfaceS1* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_MMEname ("mme_name", &pvalue->mme_name, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeComponentInterfaceS1.c ---

/****************************************/
/* File .c missing: e2ap_macro_eNB_ID.c */
/****************************************/

/***************************************/
/* File .c missing: e2ap_home_eNB_ID.c */
/***************************************/

/**********************************************/
/* File .c missing: e2ap_short_Macro_eNB_ID.c */
/**********************************************/

/*********************************************/
/* File .c missing: e2ap_long_Macro_eNB_ID.c */
/*********************************************/

/**********************************/
/* File .c missing: e2ap_ENB_ID.c */
/**********************************/

// --- Begin of e2ap_GlobalENB_ID.c ---

/*****************************************/
/*           GlobalENB-ID                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "GlobalENB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field pLMN_Identity */  

   RTXCTXTPUSHELEMNAME(pctxt, "pLMN-Identity");
   stat = asn1PE_e2ap_PLMN_Identity (pctxt, &pvalue->pLMN_Identity);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field eNB_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "eNB-ID");
   stat = asn1PE_e2ap_ENB_ID (pctxt, &pvalue->eNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "GlobalENB-ID");

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
   /* decode field pLMN_Identity */
   RTXCTXTPUSHELEMNAME(pctxt, "pLMN-Identity");


      stat = asn1PD_e2ap_PLMN_Identity (pctxt, &pvalue->pLMN_Identity);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field eNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "eNB-ID");


      stat = asn1PD_e2ap_ENB_ID (pctxt, &pvalue->eNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_GlobalENB_ID (e2ap_GlobalENB_ID* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_PLMN_Identity (&pvalue->pLMN_Identity);
   asn1Init_e2ap_ENB_ID (&pvalue->eNB_ID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_PLMN_Identity (pctxt, &pvalue->pLMN_Identity);
   asn1Free_e2ap_ENB_ID (pctxt, &pvalue->eNB_ID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_GlobalENB_ID (const char* name, e2ap_GlobalENB_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_PLMN_Identity ("pLMN_Identity", &pvalue->pLMN_Identity, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ENB_ID ("eNB_ID", &pvalue->eNB_ID, buffer, bufSize) < 0)
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
// --- End of e2ap_GlobalENB_ID.c ---

/**********************************/
/* File .c missing: e2ap_gNB_ID.c */
/**********************************/

/************************************/
/* File .c missing: e2ap_ENGNB_ID.c */
/************************************/

// --- Begin of e2ap_GlobalenGNB_ID.c ---

/*****************************************/
/*           GlobalenGNB-ID                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "GlobalenGNB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field pLMN_Identity */  

   RTXCTXTPUSHELEMNAME(pctxt, "pLMN-Identity");
   stat = asn1PE_e2ap_PLMN_Identity (pctxt, &pvalue->pLMN_Identity);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field gNB_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "gNB-ID");
   stat = asn1PE_e2ap_ENGNB_ID (pctxt, &pvalue->gNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "GlobalenGNB-ID");

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
   /* decode field pLMN_Identity */
   RTXCTXTPUSHELEMNAME(pctxt, "pLMN-Identity");


      stat = asn1PD_e2ap_PLMN_Identity (pctxt, &pvalue->pLMN_Identity);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field gNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "gNB-ID");


      stat = asn1PD_e2ap_ENGNB_ID (pctxt, &pvalue->gNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_GlobalenGNB_ID (e2ap_GlobalenGNB_ID* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_PLMN_Identity (&pvalue->pLMN_Identity);
   asn1Init_e2ap_ENGNB_ID (&pvalue->gNB_ID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_PLMN_Identity (pctxt, &pvalue->pLMN_Identity);
   asn1Free_e2ap_ENGNB_ID (pctxt, &pvalue->gNB_ID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_GlobalenGNB_ID (const char* name, e2ap_GlobalenGNB_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_PLMN_Identity ("pLMN_Identity", &pvalue->pLMN_Identity, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ENGNB_ID ("gNB_ID", &pvalue->gNB_ID, buffer, bufSize) < 0)
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
// --- End of e2ap_GlobalenGNB_ID.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceX2.c ---

/*****************************************/
/*           E2nodeComponentInterfaceX2                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceX2");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field global_eNB_ID */  
   if (pvalue->m_global_eNB_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "global-eNB-ID");
   stat = asn1PE_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   }

   /* encode field global_en_gNB_ID */  
   if (pvalue->m_global_en_gNB_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "global-en-gNB-ID");
   stat = asn1PE_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceX2");

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
   /* decode field global_eNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-eNB-ID");
   if (optbits[0]) {
      pvalue->m_global_eNB_IDPresent = TRUE;


      stat = asn1PD_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_global_eNB_IDPresent = FALSE;
   }
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field global_en_gNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-en-gNB-ID");
   if (optbits[0]) {
      pvalue->m_global_en_gNB_IDPresent = TRUE;


      stat = asn1PD_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_global_en_gNB_IDPresent = FALSE;
   }
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_E2nodeComponentInterfaceX2 (e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_GlobalENB_ID (&pvalue->global_eNB_ID);
   asn1Init_e2ap_GlobalenGNB_ID (&pvalue->global_en_gNB_ID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
   asn1Free_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentInterfaceX2 (const char* name, e2ap_E2nodeComponentInterfaceX2* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GlobalENB_ID ("global_eNB_ID", &pvalue->global_eNB_ID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GlobalenGNB_ID ("global_en_gNB_ID", &pvalue->global_en_gNB_ID, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeComponentInterfaceX2.c ---

/*********************************************/
/* File .c missing: e2ap_E2nodeComponentID.c */
/*********************************************/

/*****************************************/
/* File .c missing: e2ap_updateOutcome.c */
/*****************************************/

// --- Begin of e2ap_CauseRICrequest.c ---
/******************************************************/
/*                                                    */
/*    CauseRICrequest                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_CauseRICrequest_ENUMTAB[] = {
    { OSUTF8("ran_function_id_invalid"), 0, 23, 0 },
    { OSUTF8("action_not_supported"), 1, 20, 1 },
    { OSUTF8("excessive_actions"), 2, 17, 2 },
    { OSUTF8("duplicate_action"), 3, 16, 3 },
    { OSUTF8("duplicate_event_trigger"), 4, 23, 4 },
    { OSUTF8("function_resource_limit"), 5, 23, 5 },
    { OSUTF8("request_id_unknown"), 6, 18, 6 },
    { OSUTF8("inconsistent_action_subsequent_action_sequence"), 7, 46, 7 },
    { OSUTF8("control_message_invalid"), 8, 23, 8 },
    { OSUTF8("ric_call_process_id_invalid"), 9, 27, 9 },
    { OSUTF8("control_timer_expired"), 10, 21, 10 },
    { OSUTF8("control_failed_to_execute"), 11, 25, 11 },
    { OSUTF8("system_not_ready"), 12, 16, 12 },
    { OSUTF8("unspecified"), 13, 11, 13 },
    { OSUTF8("ric_subscription_end_time_expired"), 14, 33, 14 },
    { OSUTF8("ric_subscription_end_time_invalid"), 15, 33, 15 },
    { OSUTF8("duplicate_ric_request_id"), 16, 24, 16 },
    { OSUTF8("eventTriggerNotSupported"), 17, 24, 17 },
    { OSUTF8("requested_information_unavailable"), 18, 33, 18 },
    { OSUTF8("invalid_information_request"), 19, 27, 19 }
};


const OSUTF8CHAR* e2ap_CauseRICrequest_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_CauseRICrequest_ENUMTABSIZE){
      return e2ap_CauseRICrequest_ENUMTAB[e2ap_CauseRICrequest_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_CauseRICrequest_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseRICrequest* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_CauseRICrequest_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_CauseRICrequest_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseRICrequest* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_CauseRICrequest_ENUMTAB, e2ap_CauseRICrequest_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_CauseRICrequest)e2ap_CauseRICrequest_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_CauseRICrequest (OSCTXT* pctxt, e2ap_CauseRICrequest value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "CauseRICrequest");
   if (value >= 20) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(19));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseRICrequest (OSCTXT* pctxt, e2ap_CauseRICrequest* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CauseRICrequest");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(19));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseRICrequest (const char* name, e2ap_CauseRICrequest* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIndent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = ran_function_id_invalid", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = action_not_supported", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = excessive_actions", buffer, bufSize);
         break;
      case 3:
         stat = rtPrintToString(" = duplicate_action", buffer, bufSize);
         break;
      case 4:
         stat = rtPrintToString(" = duplicate_event_trigger", buffer, bufSize);
         break;
      case 5:
         stat = rtPrintToString(" = function_resource_limit", buffer, bufSize);
         break;
      case 6:
         stat = rtPrintToString(" = request_id_unknown", buffer, bufSize);
         break;
      case 7:
         stat = rtPrintToString(" = inconsistent_action_subsequent_action_sequence", buffer, bufSize);
         break;
      case 8:
         stat = rtPrintToString(" = control_message_invalid", buffer, bufSize);
         break;
      case 9:
         stat = rtPrintToString(" = ric_call_process_id_invalid", buffer, bufSize);
         break;
      case 10:
         stat = rtPrintToString(" = control_timer_expired", buffer, bufSize);
         break;
      case 11:
         stat = rtPrintToString(" = control_failed_to_execute", buffer, bufSize);
         break;
      case 12:
         stat = rtPrintToString(" = system_not_ready", buffer, bufSize);
         break;
      case 13:
         stat = rtPrintToString(" = unspecified", buffer, bufSize);
         break;
      case 14:
         stat = rtPrintToString(" = ric_subscription_end_time_expired", buffer, bufSize);
         break;
      case 15:
         stat = rtPrintToString(" = ric_subscription_end_time_invalid", buffer, bufSize);
         break;
      case 16:
         stat = rtPrintToString(" = duplicate_ric_request_id", buffer, bufSize);
         break;
      case 17:
         stat = rtPrintToString(" = eventTriggerNotSupported", buffer, bufSize);
         break;
      case 18:
         stat = rtPrintToString(" = requested_information_unavailable", buffer, bufSize);
         break;
      case 19:
         stat = rtPrintToString(" = invalid_information_request", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_CauseRICrequest.c ---

// --- Begin of e2ap_CauseRICservice.c ---
/******************************************************/
/*                                                    */
/*    CauseRICservice                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_CauseRICservice_ENUMTAB[] = {
    { OSUTF8("ran_function_not_supported"), 0, 26, 0 },
    { OSUTF8("excessive_functions"), 1, 19, 1 },
    { OSUTF8("ric_resource_limit"), 2, 18, 2 }
};


const OSUTF8CHAR* e2ap_CauseRICservice_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_CauseRICservice_ENUMTABSIZE){
      return e2ap_CauseRICservice_ENUMTAB[e2ap_CauseRICservice_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_CauseRICservice_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseRICservice* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_CauseRICservice_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_CauseRICservice_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseRICservice* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_CauseRICservice_ENUMTAB, e2ap_CauseRICservice_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_CauseRICservice)e2ap_CauseRICservice_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_CauseRICservice (OSCTXT* pctxt, e2ap_CauseRICservice value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "CauseRICservice");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseRICservice (OSCTXT* pctxt, e2ap_CauseRICservice* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CauseRICservice");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseRICservice (const char* name, e2ap_CauseRICservice* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIndent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = ran_function_not_supported", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = excessive_functions", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = ric_resource_limit", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_CauseRICservice.c ---

// --- Begin of e2ap_CauseE2node.c ---
/******************************************************/
/*                                                    */
/*    CauseE2node                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_CauseE2node_ENUMTAB[] = {
    { OSUTF8("e2node_component_unknown"), 0, 24, 0 }
};


const OSUTF8CHAR* e2ap_CauseE2node_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_CauseE2node_ENUMTABSIZE){
      return e2ap_CauseE2node_ENUMTAB[e2ap_CauseE2node_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_CauseE2node_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseE2node* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_CauseE2node_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_CauseE2node_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseE2node* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_CauseE2node_ENUMTAB, e2ap_CauseE2node_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_CauseE2node)e2ap_CauseE2node_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_CauseE2node (OSCTXT* pctxt, e2ap_CauseE2node value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "CauseE2node");
   if (value >= 1) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(0));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseE2node (OSCTXT* pctxt, e2ap_CauseE2node* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CauseE2node");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(0));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseE2node (const char* name, e2ap_CauseE2node* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIndent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = e2node_component_unknown", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_CauseE2node.c ---

// --- Begin of e2ap_CauseTransport.c ---
/******************************************************/
/*                                                    */
/*    CauseTransport                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_CauseTransport_ENUMTAB[] = {
    { OSUTF8("unspecified"), 0, 11, 0 },
    { OSUTF8("transport_resource_unavailable"), 1, 30, 1 }
};


const OSUTF8CHAR* e2ap_CauseTransport_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_CauseTransport_ENUMTABSIZE){
      return e2ap_CauseTransport_ENUMTAB[e2ap_CauseTransport_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_CauseTransport_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseTransport* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_CauseTransport_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_CauseTransport_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseTransport* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_CauseTransport_ENUMTAB, e2ap_CauseTransport_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_CauseTransport)e2ap_CauseTransport_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_CauseTransport (OSCTXT* pctxt, e2ap_CauseTransport value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "CauseTransport");
   if (value >= 2) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(1));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseTransport (OSCTXT* pctxt, e2ap_CauseTransport* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CauseTransport");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(1));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseTransport (const char* name, e2ap_CauseTransport* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIndent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = unspecified", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = transport_resource_unavailable", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_CauseTransport.c ---

// --- Begin of e2ap_CauseProtocol.c ---
/******************************************************/
/*                                                    */
/*    CauseProtocol                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_CauseProtocol_ENUMTAB[] = {
    { OSUTF8("transfer_syntax_error"), 0, 21, 0 },
    { OSUTF8("abstract_syntax_error_reject"), 1, 28, 1 },
    { OSUTF8("abstract_syntax_error_ignore_and_notify"), 2, 39, 2 },
    { OSUTF8("message_not_compatible_with_receiver_state"), 3, 42, 3 },
    { OSUTF8("semantic_error"), 4, 14, 4 },
    { OSUTF8("abstract_syntax_error_falsely_constructed_message"), 5, 49, 5 },
    { OSUTF8("unspecified"), 6, 11, 6 }
};


const OSUTF8CHAR* e2ap_CauseProtocol_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_CauseProtocol_ENUMTABSIZE){
      return e2ap_CauseProtocol_ENUMTAB[e2ap_CauseProtocol_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_CauseProtocol_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseProtocol* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_CauseProtocol_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_CauseProtocol_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseProtocol* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_CauseProtocol_ENUMTAB, e2ap_CauseProtocol_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_CauseProtocol)e2ap_CauseProtocol_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_CauseProtocol (OSCTXT* pctxt, e2ap_CauseProtocol value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "CauseProtocol");
   if (value >= 7) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(6));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseProtocol (OSCTXT* pctxt, e2ap_CauseProtocol* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CauseProtocol");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(6));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseProtocol (const char* name, e2ap_CauseProtocol* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIndent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = transfer_syntax_error", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = abstract_syntax_error_reject", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = abstract_syntax_error_ignore_and_notify", buffer, bufSize);
         break;
      case 3:
         stat = rtPrintToString(" = message_not_compatible_with_receiver_state", buffer, bufSize);
         break;
      case 4:
         stat = rtPrintToString(" = semantic_error", buffer, bufSize);
         break;
      case 5:
         stat = rtPrintToString(" = abstract_syntax_error_falsely_constructed_message", buffer, bufSize);
         break;
      case 6:
         stat = rtPrintToString(" = unspecified", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_CauseProtocol.c ---

// --- Begin of e2ap_CauseMisc.c ---
/******************************************************/
/*                                                    */
/*    CauseMisc                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_CauseMisc_ENUMTAB[] = {
    { OSUTF8("control_processing_overload"), 0, 27, 0 },
    { OSUTF8("hardware_failure"), 1, 16, 1 },
    { OSUTF8("om_intervention"), 2, 15, 2 },
    { OSUTF8("unspecified"), 3, 11, 3 }
};


const OSUTF8CHAR* e2ap_CauseMisc_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_CauseMisc_ENUMTABSIZE){
      return e2ap_CauseMisc_ENUMTAB[e2ap_CauseMisc_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_CauseMisc_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_CauseMisc* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_CauseMisc_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_CauseMisc_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_CauseMisc* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_CauseMisc_ENUMTAB, e2ap_CauseMisc_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_CauseMisc)e2ap_CauseMisc_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "CauseMisc");
   if (value >= 4) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(3));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_CauseMisc (OSCTXT* pctxt, e2ap_CauseMisc* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "CauseMisc");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(3));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_CauseMisc (const char* name, e2ap_CauseMisc* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIndent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = control_processing_overload", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = hardware_failure", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = om_intervention", buffer, bufSize);
         break;
      case 3:
         stat = rtPrintToString(" = unspecified", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_CauseMisc.c ---

// --- Begin of e2ap_ServiceLayerCause.c ---
/*****************************************/
/*           ServiceLayerCause                */
/*****************************************/

//9 mau octet string


//type 9  mau la octet string mau la pdusessioncommonnetworkinstance

EXTERN int asn1PE_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause value){
   int stat = 0
   RTXCTCXTPUSHTYPENAME (pctxt, "ServiceLayerCause");
   stat = pe_OctetString(pctxt, value.numocts, value.data);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);

}
EXTERN int asn1PD_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause* pvalue){
   int stat = 0;
   RTXCTCXTPUSHTYPENAME (pctxt, "ServiceLayerCause");
   stat = pd_DynOctetString(pctxt, pvalue);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}
//EXTERN int asn1PrtToStr_e2ap_ServiceLayerCause (const char* name, e2ap_ServiceLayerCause *pvalue, char* buffer, OSSIZE bufSize);
//EXTERN int asn1PrtToStrm_e2ap_ServiceLayerCause (OSCTXT* pctxt, const char* name, const e2ap_ServiceLayerCause* pvalue);
//EXTERN int asn1Copy_e2ap_ServiceLayerCause (OSCTXT* pctxt, const e2ap_ServiceLayerCause* pSrcValue, e2ap_ServiceLayerCause* pDstValue);
 int asn1Init_e2ap_ServiceLayerCause (e2ap_ServiceLayerCause* pvalue){
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->numocts = 0;
   pvalue->data = 0;
   return 0;
}
 void asn1Free_e2ap_ServiceLayerCause (OSCTXT* pctxt, e2ap_ServiceLayerCause* pvalue){
   if (pvalue == 0) return;
   if(pvalue->numocts>0){
       rtxMemFreePtr(pctxt, (void*)pvalue->data);
       pvalue->data = 0;
       pvalue->numocts = 0;
   }
}


// --- End of e2ap_ServiceLayerCause.c ---

// --- Begin of e2ap_CauseServiceLayer.c ---

/*****************************************/
/*           CauseServiceLayer                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "CauseServiceLayer");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field serviceLayerCause */  

   RTXCTXTPUSHELEMNAME(pctxt, "serviceLayerCause");
   stat = asn1PE_e2ap_ServiceLayerCause (pctxt, &pvalue->serviceLayerCause);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "CauseServiceLayer");

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
   /* decode field serviceLayerCause */
   RTXCTXTPUSHELEMNAME(pctxt, "serviceLayerCause");


      stat = asn1PD_e2ap_ServiceLayerCause (pctxt, &pvalue->serviceLayerCause);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_CauseServiceLayer (e2ap_CauseServiceLayer* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_ServiceLayerCause (&pvalue->serviceLayerCause);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_CauseServiceLayer (OSCTXT* pctxt, e2ap_CauseServiceLayer* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_ServiceLayerCause (pctxt, &pvalue->serviceLayerCause);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_CauseServiceLayer (const char* name, e2ap_CauseServiceLayer* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_ServiceLayerCause ("serviceLayerCause", &pvalue->serviceLayerCause, buffer, bufSize) < 0)
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
// --- End of e2ap_CauseServiceLayer.c ---

/*********************************/
/* File .c missing: e2ap_Cause.c */
/*********************************/

// --- Begin of e2ap_E2nodeComponentConfigurationAck.c ---

/*****************************************/
/*           E2nodeComponentConfigurationAck                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentConfigurationAck");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field updateOutcome */  

   RTXCTXTPUSHELEMNAME(pctxt, "updateOutcome");
   stat = asn1PE_e2ap_ENUMERATED (pctxt, &pvalue->updateOutcome);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field failure */  

   RTXCTXTPUSHELEMNAME(pctxt, "failure");
   stat = asn1PE_e2ap_failure (pctxt, &pvalue->failure);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field failureCause */  
   if (pvalue->m_failureCausePresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "failureCause");
   stat = asn1PE_e2ap_Cause (pctxt, &pvalue->failureCause);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[3];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentConfigurationAck");

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
   /* decode field updateOutcome */
   RTXCTXTPUSHELEMNAME(pctxt, "updateOutcome");


      stat = asn1PD_e2ap_ENUMERATED (pctxt, &pvalue->updateOutcome);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field failure */
   RTXCTXTPUSHELEMNAME(pctxt, "failure");


      stat = asn1PD_e2ap_failure (pctxt, &pvalue->failure);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field failureCause */
   RTXCTXTPUSHELEMNAME(pctxt, "failureCause");
   if (optbits[0]) {
      pvalue->m_failureCausePresent = TRUE;


      stat = asn1PD_e2ap_Cause (pctxt, &pvalue->failureCause);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_failureCausePresent = FALSE;
   }
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_E2nodeComponentConfigurationAck (e2ap_E2nodeComponentConfigurationAck* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_failure (&pvalue->failure);
   asn1Init_e2ap_Cause (&pvalue->failureCause);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_failure (pctxt, &pvalue->failure);
   asn1Free_e2ap_Cause (pctxt, &pvalue->failureCause);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentConfigurationAck (const char* name, e2ap_E2nodeComponentConfigurationAck* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_failure ("failure", &pvalue->failure, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_Cause ("failureCause", &pvalue->failureCause, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeComponentConfigurationAck.c ---

// --- Begin of e2ap_E2nodeComponentConfigAdditionAck_Item.c ---

/*****************************************/
/*           E2nodeComponentConfigAdditionAck-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentConfigAdditionAck-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field e2nodeComponentInterfaceType */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentInterfaceType");
   stat = asn1PE_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field e2nodeComponentID */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentID");
   stat = asn1PE_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field e2nodeComponentConfigurationAck */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentConfigurationAck");
   stat = asn1PE_e2ap_E2nodeComponentConfigurationAck (pctxt, &pvalue->e2nodeComponentConfigurationAck);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[3];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentConfigAdditionAck-Item");

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
   /* decode field e2nodeComponentInterfaceType */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentInterfaceType");


      stat = asn1PD_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field e2nodeComponentID */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentID");


      stat = asn1PD_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field e2nodeComponentConfigurationAck */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentConfigurationAck");


      stat = asn1PD_e2ap_E2nodeComponentConfigurationAck (pctxt, &pvalue->e2nodeComponentConfigurationAck);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_E2nodeComponentConfigAdditionAck_Item (e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_E2nodeComponentInterfaceType (&pvalue->e2nodeComponentInterfaceType);
   asn1Init_e2ap_E2nodeComponentID (&pvalue->e2nodeComponentID);
   asn1Init_e2ap_E2nodeComponentConfigurationAck (&pvalue->e2nodeComponentConfigurationAck);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   asn1Free_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   asn1Free_e2ap_E2nodeComponentConfigurationAck (pctxt, &pvalue->e2nodeComponentConfigurationAck);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentConfigAdditionAck_Item (const char* name, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_E2nodeComponentInterfaceType ("e2nodeComponentInterfaceType", &pvalue->e2nodeComponentInterfaceType, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_E2nodeComponentID ("e2nodeComponentID", &pvalue->e2nodeComponentID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_E2nodeComponentConfigurationAck ("e2nodeComponentConfigurationAck", &pvalue->e2nodeComponentConfigurationAck, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeComponentConfigAdditionAck_Item.c ---

// --- Begin of e2ap_E2nodeComponentConfigAdditionAck_ItemIEs.c ---
/* e2ap_E2nodeComponentConfigAdditionAck-Item.c */

/*****************************************/
/*           E2nodeComponentConfigAdditionAck-Item               */
/*****************************************/
//IE

int asn1PE_e2ap_E2nodeComponentConfigAdditionAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck-Item* pvalue)
{
   int stat = 0;
   //RTXCTXTPUSHTYPENAME (pctxt, "E2nodeComponentConfigAdditionAck-Item");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->criticality);
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
      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigAdditionAck-Item_E2nodeComponentConfigAdditionAck_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "_e2ap_E2nodeComponentConfigAdditionAck-Item_id_E2nodeComponentConfigAdditionAck_Item");
         stat = asn1PE_e2ap_E2nodeComponentConfigAdditionAck_Item (pctxt, pvalue->value.u._e2apE2nodeComponentConfigAdditionAck-Item_E2nodeComponentConfigAdditionAck_Item);
         RTXCTXTPOPELEMNAME (pctxt);
      
         break;

      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigAdditionAck-Item_UNDEF_:
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
      }

      if (encoded) {
         size_t bitOffset = PU_GETCTXTBITOFFSET (pctxt);
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

   //RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigAdditionAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck-Item* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigAdditionAck-Item (e2ap_E2nodeComponentConfigAdditionAck-Item* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_E2nodeComponentConfigAdditionAck-Item));
}

#if 0
void asn1Free_e2ap_E2nodeComponentConfigAdditionAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck-Item* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
#endif
void asn1Free_e2ap_E2nodeComponentConfigAdditionAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck-Item* pvalue)
{
   if(0==pvalue) return;
   switch(pvalue->value.t){
      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigAdditionAck-Item_E2nodeComponentConfigAdditionAck_Item:
         asn1Free_e2ap_E2nodeComponentConfigAdditionAck_Item (pctxt, pvalue->value.u._e2apE2nodeComponentConfigAdditionAck-Item_E2nodeComponentConfigAdditionAck_Item);
         rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2apE2nodeComponentConfigAdditionAck-Item_E2nodeComponentConfigAdditionAck_Item);
         pvalue->value.u._e2apE2nodeComponentConfigAdditionAck-Item_E2nodeComponentConfigAdditionAck_Item = 0;
         break;
      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigAdditionAck-Item_UNDEF_:
         if(0!=pvalue->value.u.extElem1){
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1->data);
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1);
             pvalue->value.u.extElem1 =0;
         }
         break;
         default:;
   }
}
// --- End of e2ap_E2nodeComponentConfigAdditionAck_ItemIEs.c ---

// --- Begin of e2ap_E2nodeComponentConfigAdditionAck_List.c ---
/*****************************************/
/*           E2nodeComponentConfigAdditionAck_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_E2nodeComponentConfigAdditionAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2nodeComponentConfigAdditionAck_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "E2nodeComponentConfigAdditionAck-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(1024), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_E2nodeComponentConfigAdditionAck_ItemIEs*) pnode->data;
      RTXCTXTPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_E2nodeComponentConfigAdditionAck_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXTPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigAdditionAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2nodeComponentConfigAdditionAck_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "E2nodeComponentConfigAdditionAck-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_1024), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXTPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_E2nodeComponentConfigAdditionAck_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);
      asn1Init_e2ap_E2nodeComponentConfigAdditionAck_ItemIEs (pdata);
      stat = asn1PD_e2ap_E2nodeComponentConfigAdditionAck_ItemIEs (pctxt, pdata);
      if (stat != 0) {
         rtxMemFreePtr (pctxt, pdata);
         return LOG_RTERR (pctxt, stat);
      }

      rtxDListAppendNode (ppvalue, pdata);

      RTXCTXTPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigAdditionAck_List (e2ap_E2nodeComponentConfigAdditionAck_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_E2nodeComponentConfigAdditionAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_E2nodeComponentConfigAdditionAck_ItemIEs* pdata = (e2ap_E2nodeComponentConfigAdditionAck_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_E2nodeComponentConfigAdditionAck_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
      rtxDListFreeAll(pctxt, pvalue);
}

#if 0
void asn1Free_e2ap_E2nodeComponentConfigAdditionAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_E2nodeComponentConfigAdditionAck_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_E2nodeComponentConfigAdditionAck_ItemIEs*)pnode->data;
         asn1Free_e2ap_E2nodeComponentConfigAdditionAck_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_E2nodeComponentConfigAdditionAck_List.c ---

// --- Begin of e2ap_E2nodeComponentConfigUpdateAck_Item.c ---

/*****************************************/
/*           E2nodeComponentConfigUpdateAck-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentConfigUpdateAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdateAck_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentConfigUpdateAck-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field e2nodeComponentInterfaceType */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentInterfaceType");
   stat = asn1PE_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field e2nodeComponentID */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentID");
   stat = asn1PE_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field e2nodeComponentConfigurationAck */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentConfigurationAck");
   stat = asn1PE_e2ap_E2nodeComponentConfigurationAck (pctxt, &pvalue->e2nodeComponentConfigurationAck);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentConfigUpdateAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdateAck_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[3];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentConfigUpdateAck-Item");

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
   /* decode field e2nodeComponentInterfaceType */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentInterfaceType");


      stat = asn1PD_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field e2nodeComponentID */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentID");


      stat = asn1PD_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field e2nodeComponentConfigurationAck */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentConfigurationAck");


      stat = asn1PD_e2ap_E2nodeComponentConfigurationAck (pctxt, &pvalue->e2nodeComponentConfigurationAck);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_E2nodeComponentConfigUpdateAck_Item (e2ap_E2nodeComponentConfigUpdateAck_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_E2nodeComponentInterfaceType (&pvalue->e2nodeComponentInterfaceType);
   asn1Init_e2ap_E2nodeComponentID (&pvalue->e2nodeComponentID);
   asn1Init_e2ap_E2nodeComponentConfigurationAck (&pvalue->e2nodeComponentConfigurationAck);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentConfigUpdateAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdateAck_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   asn1Free_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   asn1Free_e2ap_E2nodeComponentConfigurationAck (pctxt, &pvalue->e2nodeComponentConfigurationAck);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentConfigUpdateAck_Item (const char* name, e2ap_E2nodeComponentConfigUpdateAck_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_E2nodeComponentInterfaceType ("e2nodeComponentInterfaceType", &pvalue->e2nodeComponentInterfaceType, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_E2nodeComponentID ("e2nodeComponentID", &pvalue->e2nodeComponentID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_E2nodeComponentConfigurationAck ("e2nodeComponentConfigurationAck", &pvalue->e2nodeComponentConfigurationAck, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeComponentConfigUpdateAck_Item.c ---

// --- Begin of e2ap_E2nodeComponentConfigUpdateAck_ItemIEs.c ---
/* e2ap_E2nodeComponentConfigUpdateAck-Item.c */

/*****************************************/
/*           E2nodeComponentConfigUpdateAck-Item               */
/*****************************************/
//IE

int asn1PE_e2ap_E2nodeComponentConfigUpdateAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdateAck-Item* pvalue)
{
   int stat = 0;
   //RTXCTXTPUSHTYPENAME (pctxt, "E2nodeComponentConfigUpdateAck-Item");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->criticality);
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
      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigUpdateAck-Item_E2nodeComponentConfigUpdateAck_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "_e2ap_E2nodeComponentConfigUpdateAck-Item_id_E2nodeComponentConfigUpdateAck_Item");
         stat = asn1PE_e2ap_E2nodeComponentConfigUpdateAck_Item (pctxt, pvalue->value.u._e2apE2nodeComponentConfigUpdateAck-Item_E2nodeComponentConfigUpdateAck_Item);
         RTXCTXTPOPELEMNAME (pctxt);
      
         break;

      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigUpdateAck-Item_UNDEF_:
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
      }

      if (encoded) {
         size_t bitOffset = PU_GETCTXTBITOFFSET (pctxt);
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

   //RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigUpdateAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdateAck-Item* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigUpdateAck-Item (e2ap_E2nodeComponentConfigUpdateAck-Item* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_E2nodeComponentConfigUpdateAck-Item));
}

#if 0
void asn1Free_e2ap_E2nodeComponentConfigUpdateAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdateAck-Item* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
#endif
void asn1Free_e2ap_E2nodeComponentConfigUpdateAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdateAck-Item* pvalue)
{
   if(0==pvalue) return;
   switch(pvalue->value.t){
      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigUpdateAck-Item_E2nodeComponentConfigUpdateAck_Item:
         asn1Free_e2ap_E2nodeComponentConfigUpdateAck_Item (pctxt, pvalue->value.u._e2apE2nodeComponentConfigUpdateAck-Item_E2nodeComponentConfigUpdateAck_Item);
         rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2apE2nodeComponentConfigUpdateAck-Item_E2nodeComponentConfigUpdateAck_Item);
         pvalue->value.u._e2apE2nodeComponentConfigUpdateAck-Item_E2nodeComponentConfigUpdateAck_Item = 0;
         break;
      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigUpdateAck-Item_UNDEF_:
         if(0!=pvalue->value.u.extElem1){
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1->data);
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1);
             pvalue->value.u.extElem1 =0;
         }
         break;
         default:;
   }
}
// --- End of e2ap_E2nodeComponentConfigUpdateAck_ItemIEs.c ---

// --- Begin of e2ap_E2nodeComponentConfigUpdateAck_List.c ---
/*****************************************/
/*           E2nodeComponentConfigUpdateAck_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_E2nodeComponentConfigUpdateAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdateAck_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2nodeComponentConfigUpdateAck_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "E2nodeComponentConfigUpdateAck-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(1024), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_E2nodeComponentConfigUpdateAck_ItemIEs*) pnode->data;
      RTXCTXTPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_E2nodeComponentConfigUpdateAck_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXTPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigUpdateAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdateAck_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2nodeComponentConfigUpdateAck_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "E2nodeComponentConfigUpdateAck-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_1024), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXTPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_E2nodeComponentConfigUpdateAck_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);
      asn1Init_e2ap_E2nodeComponentConfigUpdateAck_ItemIEs (pdata);
      stat = asn1PD_e2ap_E2nodeComponentConfigUpdateAck_ItemIEs (pctxt, pdata);
      if (stat != 0) {
         rtxMemFreePtr (pctxt, pdata);
         return LOG_RTERR (pctxt, stat);
      }

      rtxDListAppendNode (ppvalue, pdata);

      RTXCTXTPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigUpdateAck_List (e2ap_E2nodeComponentConfigUpdateAck_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_E2nodeComponentConfigUpdateAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdateAck_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_E2nodeComponentConfigUpdateAck_ItemIEs* pdata = (e2ap_E2nodeComponentConfigUpdateAck_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_E2nodeComponentConfigUpdateAck_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
      rtxDListFreeAll(pctxt, pvalue);
}

#if 0
void asn1Free_e2ap_E2nodeComponentConfigUpdateAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdateAck_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_E2nodeComponentConfigUpdateAck_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_E2nodeComponentConfigUpdateAck_ItemIEs*)pnode->data;
         asn1Free_e2ap_E2nodeComponentConfigUpdateAck_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_E2nodeComponentConfigUpdateAck_List.c ---

// --- Begin of e2ap_E2nodeComponentConfigRemovalAck_Item.c ---

/*****************************************/
/*           E2nodeComponentConfigRemovalAck-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentConfigRemovalAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentConfigRemovalAck-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field e2nodeComponentInterfaceType */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentInterfaceType");
   stat = asn1PE_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field e2nodeComponentID */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentID");
   stat = asn1PE_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field e2nodeComponentConfigurationAck */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentConfigurationAck");
   stat = asn1PE_e2ap_E2nodeComponentConfigurationAck (pctxt, &pvalue->e2nodeComponentConfigurationAck);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentConfigRemovalAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[3];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeComponentConfigRemovalAck-Item");

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
   /* decode field e2nodeComponentInterfaceType */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentInterfaceType");


      stat = asn1PD_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field e2nodeComponentID */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentID");


      stat = asn1PD_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field e2nodeComponentConfigurationAck */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentConfigurationAck");


      stat = asn1PD_e2ap_E2nodeComponentConfigurationAck (pctxt, &pvalue->e2nodeComponentConfigurationAck);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_E2nodeComponentConfigRemovalAck_Item (e2ap_E2nodeComponentConfigRemovalAck_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_E2nodeComponentInterfaceType (&pvalue->e2nodeComponentInterfaceType);
   asn1Init_e2ap_E2nodeComponentID (&pvalue->e2nodeComponentID);
   asn1Init_e2ap_E2nodeComponentConfigurationAck (&pvalue->e2nodeComponentConfigurationAck);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentConfigRemovalAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   asn1Free_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   asn1Free_e2ap_E2nodeComponentConfigurationAck (pctxt, &pvalue->e2nodeComponentConfigurationAck);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentConfigRemovalAck_Item (const char* name, e2ap_E2nodeComponentConfigRemovalAck_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_E2nodeComponentInterfaceType ("e2nodeComponentInterfaceType", &pvalue->e2nodeComponentInterfaceType, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_E2nodeComponentID ("e2nodeComponentID", &pvalue->e2nodeComponentID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_E2nodeComponentConfigurationAck ("e2nodeComponentConfigurationAck", &pvalue->e2nodeComponentConfigurationAck, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeComponentConfigRemovalAck_Item.c ---

// --- Begin of e2ap_E2nodeComponentConfigRemovalAck_ItemIEs.c ---
/* e2ap_E2nodeComponentConfigRemovalAck-Item.c */

/*****************************************/
/*           E2nodeComponentConfigRemovalAck-Item               */
/*****************************************/
//IE

int asn1PE_e2ap_E2nodeComponentConfigRemovalAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue)
{
   int stat = 0;
   //RTXCTXTPUSHTYPENAME (pctxt, "E2nodeComponentConfigRemovalAck-Item");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->criticality);
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
      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "_e2ap_E2nodeComponentConfigRemovalAck-Item_id_E2nodeComponentConfigRemovalAck_Item");
         stat = asn1PE_e2ap_E2nodeComponentConfigRemovalAck_Item (pctxt, pvalue->value.u._e2apE2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item);
         RTXCTXTPOPELEMNAME (pctxt);
      
         break;

      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigRemovalAck-Item_UNDEF_:
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
      }

      if (encoded) {
         size_t bitOffset = PU_GETCTXTBITOFFSET (pctxt);
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

   //RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigRemovalAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigRemovalAck-Item (e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_E2nodeComponentConfigRemovalAck-Item));
}

#if 0
void asn1Free_e2ap_E2nodeComponentConfigRemovalAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
#endif
void asn1Free_e2ap_E2nodeComponentConfigRemovalAck-Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck-Item* pvalue)
{
   if(0==pvalue) return;
   switch(pvalue->value.t){
      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item:
         asn1Free_e2ap_E2nodeComponentConfigRemovalAck_Item (pctxt, pvalue->value.u._e2apE2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item);
         rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2apE2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item);
         pvalue->value.u._e2apE2nodeComponentConfigRemovalAck-Item_E2nodeComponentConfigRemovalAck_Item = 0;
         break;
      case T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigRemovalAck-Item_UNDEF_:
         if(0!=pvalue->value.u.extElem1){
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1->data);
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1);
             pvalue->value.u.extElem1 =0;
         }
         break;
         default:;
   }
}
// --- End of e2ap_E2nodeComponentConfigRemovalAck_ItemIEs.c ---

// --- Begin of e2ap_E2nodeComponentConfigRemovalAck_List.c ---
/*****************************************/
/*           E2nodeComponentConfigRemovalAck_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_E2nodeComponentConfigRemovalAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2nodeComponentConfigRemovalAck_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "E2nodeComponentConfigRemovalAck-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(1024), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_E2nodeComponentConfigRemovalAck_ItemIEs*) pnode->data;
      RTXCTXTPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_E2nodeComponentConfigRemovalAck_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXTPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigRemovalAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2nodeComponentConfigRemovalAck_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "E2nodeComponentConfigRemovalAck-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_1024), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXTPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_E2nodeComponentConfigRemovalAck_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);
      asn1Init_e2ap_E2nodeComponentConfigRemovalAck_ItemIEs (pdata);
      stat = asn1PD_e2ap_E2nodeComponentConfigRemovalAck_ItemIEs (pctxt, pdata);
      if (stat != 0) {
         rtxMemFreePtr (pctxt, pdata);
         return LOG_RTERR (pctxt, stat);
      }

      rtxDListAppendNode (ppvalue, pdata);

      RTXCTXTPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigRemovalAck_List (e2ap_E2nodeComponentConfigRemovalAck_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_E2nodeComponentConfigRemovalAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_E2nodeComponentConfigRemovalAck_ItemIEs* pdata = (e2ap_E2nodeComponentConfigRemovalAck_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_E2nodeComponentConfigRemovalAck_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
      rtxDListFreeAll(pctxt, pvalue);
}

#if 0
void asn1Free_e2ap_E2nodeComponentConfigRemovalAck_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemovalAck_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_E2nodeComponentConfigRemovalAck_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_E2nodeComponentConfigRemovalAck_ItemIEs*)pnode->data;
         asn1Free_e2ap_E2nodeComponentConfigRemovalAck_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_E2nodeComponentConfigRemovalAck_List.c ---

/********************************************************************/
/* File .c missing: e2ap_E2nodeConfigurationUpdateAcknowledge_IEs.c */
/********************************************************************/

// --- Begin of e2ap_E2nodeConfigurationUpdateAcknowledge.c ---

/*****************************************/
/*           E2nodeConfigurationUpdateAcknowledge                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeConfigurationUpdateAcknowledge (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeConfigurationUpdateAcknowledge");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field protocolIEs */  

   RTXCTXTPUSHELEMNAME(pctxt, "protocolIEs");
   stat = asn1PE_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs (pctxt, &pvalue->protocolIEs);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);



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
         //stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
         stat = pe_OpenTypeExt(pctxt, &pvalue->extElem1);
         if (stat != 0) return LOG_RTERR(pctxt, stat);
      }
   }

   RTXCTXTPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeConfigurationUpdateAcknowledge (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "E2nodeConfigurationUpdateAcknowledge");

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
      stat = asn1PD_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs (pctxt, &pvalue->protocolIEs);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /*decode extension elements*/
   if(extbit) {
      OSOCTET *poptbits;
      /*decode optional bits length */
      stat = pd_SmallLength(pctxt, &bitcnt);
      if (stat != 0) return LOG_RTERR(pctxt, stat);

      /*decode optional bits*/
      poptbits = (OSOCTET*)rtxMemAlloc(pctxt, bitcnt);
      if(0==poptbits) return LOG_RTERR(pctxt, RTERR_NOMEM);

      for(i_ = 0; i_ < bitcnt; i_++) {
         stat = DEC_BIT(pctxt, &poptbits[i_]);
         if (stat != 0) {
            rtxMemFreePtr(pctxt, poptbits);
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

int asn1Init_e2ap_E2nodeConfigurationUpdateAcknowledge (e2ap_E2nodeConfigurationUpdateAcknowledge* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs (&pvalue->protocolIEs);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeConfigurationUpdateAcknowledge (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs (pctxt, &pvalue->protocolIEs);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeConfigurationUpdateAcknowledge (const char* name, e2ap_E2nodeConfigurationUpdateAcknowledge* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs ("protocolIEs", &pvalue->protocolIEs, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeConfigurationUpdateAcknowledge.c ---

// --- Begin of e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element.c ---
/*****************************************/
/*    E2nodeConfigurationUpdateAcknowledge_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe

EXTERN int asn1PE_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element* pvalue)
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
            case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-TransactionID");

                stat = asn1PE_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-E2nodeComponentConfigAdditionAck");

                stat = asn1PE_e2ap_E2nodeComponentConfigAdditionAck_List (pctxt, pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-E2nodeComponentConfigUpdateAck");

                stat = asn1PE_e2ap_E2nodeComponentConfigUpdateAck_List (pctxt, pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-E2nodeComponentConfigRemovalAck");

                stat = asn1PE_e2ap_E2nodeComponentConfigRemovalAck_List (pctxt, pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_UNDEF_:
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

EXTERN int  asn1PD_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element* pvalue){
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
        bitStartOffset = PU_GETCTXTBITOFFSET(pctxt);
        bitLength = openTypeLen * 8;

        switch(pvalue->id){//dungnm23 check case lai nhe
        
            case ASN1V_e2ap_id_TransactionID:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID;
            RTXCTXTPUSHELEMNAME(pctxt, "id-TransactionID");
            //pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID 
             pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID = rtxMemAllocType(pctxt, e2ap_TransactionID);
            //asn1Init_e2ap_TransactionID(pvalue->
              //  value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID);

                 asn1Init_e2ap_TransactionID(pvalue->
                value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID);
            stat = asn1PD_e2ap_TransactionID (pctxt,
                (e2ap_TransactionID*)pvalue->value.
                u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_E2nodeComponentConfigAdditionAck:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2nodeComponentConfigAdditionAck");
            //pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck_List 
             pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck = rtxMemAllocType(pctxt, e2ap_E2nodeComponentConfigAdditionAck_List);
            //asn1Init_e2ap_E2nodeComponentConfigAdditionAck_List(pvalue->
              //  value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck_List);

                 asn1Init_e2ap_E2nodeComponentConfigAdditionAck_List(pvalue->
                value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck);
            stat = asn1PD_e2ap_E2nodeComponentConfigAdditionAck_List (pctxt,
                (e2ap_E2nodeComponentConfigAdditionAck_List*)pvalue->value.
                u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_E2nodeComponentConfigUpdateAck:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2nodeComponentConfigUpdateAck");
            //pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck_List 
             pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck = rtxMemAllocType(pctxt, e2ap_E2nodeComponentConfigUpdateAck_List);
            //asn1Init_e2ap_E2nodeComponentConfigUpdateAck_List(pvalue->
              //  value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck_List);

                 asn1Init_e2ap_E2nodeComponentConfigUpdateAck_List(pvalue->
                value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck);
            stat = asn1PD_e2ap_E2nodeComponentConfigUpdateAck_List (pctxt,
                (e2ap_E2nodeComponentConfigUpdateAck_List*)pvalue->value.
                u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_E2nodeComponentConfigRemovalAck:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2nodeComponentConfigRemovalAck");
            //pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck_List 
             pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck = rtxMemAllocType(pctxt, e2ap_E2nodeComponentConfigRemovalAck_List);
            //asn1Init_e2ap_E2nodeComponentConfigRemovalAck_List(pvalue->
              //  value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck_List);

                 asn1Init_e2ap_E2nodeComponentConfigRemovalAck_List(pvalue->
                value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck);
            stat = asn1PD_e2ap_E2nodeComponentConfigRemovalAck_List (pctxt,
                (e2ap_E2nodeComponentConfigRemovalAck_List*)pvalue->value.
                u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    

        default:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_UNDEF_;
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
    size_t bitEndOffset = PU_GETCTXTBITOFFSET(pctxt);
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


int asn1Init_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element(e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    OSCRTLMEMSET (&pvalue->value, 0, sizeof(pvalue->value));
    return 0;
}


//-----> chuaw có template rtxFreeASN1OpenType
#if 0
void asn1Free_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element(OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element* pvalue)
{
    if(NULL==pvalue) return;
    switch(pvalue->value.t){
        case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID:
            // rtxFreeE2ap_TransactionID(pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID);

            if(pvalue->value.i._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID!=NULL){
            asn1Free_e2ap_TransactionID(pctxt, pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID);
           // pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID = NULL;
           pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck_List:
            // rtxFreeE2ap_E2nodeComponentConfigAdditionAck_List(pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck_List);

            if(pvalue->value.i._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck_List!=NULL){
            asn1Free_e2ap_E2nodeComponentConfigAdditionAck_List(pctxt, pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck_List);
           // pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck_List = NULL;
           pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck_List:
            // rtxFreeE2ap_E2nodeComponentConfigUpdateAck_List(pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck_List);

            if(pvalue->value.i._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck_List!=NULL){
            asn1Free_e2ap_E2nodeComponentConfigUpdateAck_List(pctxt, pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck_List);
           // pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck_List = NULL;
           pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck_List:
            // rtxFreeE2ap_E2nodeComponentConfigRemovalAck_List(pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck_List);

            if(pvalue->value.i._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck_List!=NULL){
            asn1Free_e2ap_E2nodeComponentConfigRemovalAck_List(pctxt, pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck_List);
           // pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck_List = NULL;
           pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_UNDEF_:
            rtxFreeASN1OpenType(pvalue->value.u.extElem1);
            break;
        default:
            break;
    }
}

int asn1PrtToStr_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element(OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element* pvalue)
{
    int stat =0;
    RTXCTXTPUSHELEMNAME(pctxt, "e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element");

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
            case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "TransactionID");

                stat = asn1PrtToStr_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "E2nodeComponentConfigAdditionAck-List");

                stat = asn1PrtToStr_e2ap_E2nodeComponentConfigAdditionAck_List (pctxt, pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigAdditionAck_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "E2nodeComponentConfigUpdateAck-List");

                stat = asn1PrtToStr_e2ap_E2nodeComponentConfigUpdateAck_List (pctxt, pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigUpdateAck_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "E2nodeComponentConfigRemovalAck-List");

                stat = asn1PrtToStr_e2ap_E2nodeComponentConfigRemovalAck_List (pctxt, pvalue->value.u._e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_id_E2nodeComponentConfigRemovalAck_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdateAcknowledge_IEs_UNDEF_:
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
// --- End of e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element.c ---

// --- Begin of e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs.c ---
/******************************************************/
/*                                                    */
/*    E2nodeConfigurationUpdateAcknowledge_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

EXTERN int asn1PE_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs* pvalue)
{
    int stat =0;
    OSRTDListNode* pnode;
    OSUINT32 xx1;

    /*encode length determinant */
    PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(0), OSUINTCONST(65535), 0, 0);
    stat = pe_Length(pctxt, pvalue->count);
    if(stat!=0) return LOG_RTERR(pctxt, stat);

    /*encode each element*/
    xx1 =0;
    for(pnode = pvalue->head; pnode != 0 && xx1<pvalue->count; pnode = pnode->next){
        RTXCTXTPUSHARRAYELEMNAME(pctxt, "SEQUENCE", xx1);
        stat = asn1PE_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element (pctxt, ((e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element*)pnode->data));
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        xx1++;
        RTXCTXTPOPARRAYELEMNAME(pctxt);
    }

    return (stat);
}

EXTERN int  asn1PD_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs(OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs* pvalue)
{
     int stat =0;
     OSRTDListNode* pnode;
     OSSIZE count =0;
     OSSIZE xx1=0;


     /*decode length determinant */
    PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(0), OSUINTCONST(65535), 0, 0);
    stat = pd_Length64(pctxt, &count); //tai sao lai 64
    if(stat!=0) return LOG_RTERR(pctxt, stat);

    /*decode each element*/
    rtxDListInit(pvalue);

    for(xx1=0; xx1 < count; xx1++){
        e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element* pdata;
        RTXCTXTPUSHARRAYELEMNAME(pctxt, "SEQUENCE",xx1);

        if(pnode == NULL) return LOG_RTERR(pctxt, RTERR_NOMEM);

        asn1Init_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element(pdata);
        rtxDListAppendNode(pvalue, pnode);
       // stat = asn1PD_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element (pctxt, pdata);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        RTXCTXTPOPARRAYELEMNAME(pctxt);

    }
    return (stat);
}


int asn1Init_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs(e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    rtxDListFastInit (pvalue);
    return 0;
}
#if 1 //ao that day
void asn1Free_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs(OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs* pvalue)
{
    if(0==pvalue) return;   
    e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element* pdata;
    OSRTDListNode* pnode=pvalue->head;
    while(0!=pnode){
        pdata = (e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element*)pnode->data;
       // asn1Free_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element(pctxt, pdata);
        pnode = pnode->next;
    }
    rtxDListFreeAll(pctxt, pvalue);
}
#endif


EXTERN int asn1PrtToStr_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs(const char* name, e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs* pvalue, char* buffer, OSSIZE bufSize)
{
    e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element* pdata0;
    OSRTDListNode* pnode0;
    char nameBuf[256];
    char numBuf[32];
    OSUINT32 xx1=0;
    for(pnode0 = pvalue->head;  xx1 < pvalue->count && pnode0 != 0; pnode0 = pnode0->next, xx1++){
        pdata0 = (e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element*)pnode0->data;
        rtxUIntToCharStr(xx1, numBuf, sizeof(numBuf), 0);
        rtxStrJoin(nameBuf, sizeof(nameBuf), name, "[", numBuf, "]", 0);
        #if 0
        if(asn1PrtToStr_e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs_element(nameBuf, pdata0, buffer, bufSize) <0){
            return -1;
        }
        #endif
    }
    return 0;
}
// --- End of e2ap_E2nodeConfigurationUpdateAcknowledge_protocolIEs.c ---

