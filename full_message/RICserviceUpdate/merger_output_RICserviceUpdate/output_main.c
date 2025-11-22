#include "output_main.h"
// --- Begin of doc/header.c ---
//======================E2AP.c========================//
// --- End of doc/header.c ---

// --- Begin of e2ap_TransactionID.c ---
/*****************************************/
/*           TransactionID                */
/*****************************************/
//interger with ext


EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value)
{ 
   RTXCTXTPUSHTYPENAME (pctxt, "TransactionID");

   OSBOOL exbit = (value > 255) ? TRUE : FALSE;
   int stat = rtxEncBit (pctxt, exbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!exbit) {
      stat = pe_ConsUnsigned (pctxt, value, 0, 255);
   } else {
      stat = pe_UnconsUnsigned (pctxt, value);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME (pctxt, "TransactionID");
   stat = rtxDecBit (pctxt, &extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!extbit) {
      stat = pd_ConsUnsigned (pctxt, pvalue, 0, 255);
   } else {
      stat = pd_UnconsUnsigned (pctxt, pvalue);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

EXTERN int asn1PrtToStr_e2ap_TransactionID (const char* name, e2ap_TransactionID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_TransactionID.c ---

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

// --- Begin of e2ap_RANfunctionDefinition.c ---
/*****************************************/
/*           RANfunctionDefinition                */
/*****************************************/
//octet string

/* Dynamic OCTET STRING (no SIZE constraint) */
EXTERN int asn1PE_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition* pvalue)
{
   int stat = 0;
  
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionDefinition");
   
   stat = pe_OctetString (pctxt, pvalue->numocts, pvalue->data);
 
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition** ppvalue)
{
   int stat = 0;
  
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionDefinition");
 
   stat = pd_DynOctetString (pctxt, (OSDynOctStr**)ppvalue);
   
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

int asn1Init_e2ap_RANfunctionDefinition (e2ap_RANfunctionDefinition* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->numocts = 0;
   pvalue->data = 0;
   return 0;
}

void asn1Free_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition* pvalue)
{
   if (pvalue == 0) return;
   if (pvalue->numocts > 0 && pvalue->data != 0) {
      rtxMemFreePtr (pctxt, (void*)pvalue->data);
   }
   pvalue->numocts = 0;
   pvalue->data = 0;
}


/* Print to string */
int asn1PrtToStr_e2ap_RANfunctionDefinition (const char* name, e2ap_RANfunctionDefinition* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) {
      return -1;
   }
   if (rtPrintToStringHexStr (name, pvalue->numocts, pvalue->data, buffer, bufSize) < 0){
      return -1;
   }
   return 0;
}
// --- End of e2ap_RANfunctionDefinition.c ---

// --- Begin of e2ap_RANfunctionRevision.c ---
/*****************************************/
/*         RANfunctionRevision     */
/*****************************************/
//interger no ext

EXTERN int asn1PE_e2ap_RANfunctionRevision (OSCTXT* pctxt, e2ap_RANfunctionRevision value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionRevision");
   stat = pe_ConsUnsigned (pctxt, value, 0, 4095);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RANfunctionRevision (OSCTXT* pctxt, e2ap_RANfunctionRevision* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionRevision");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 16);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RANfunctionRevision (const char* name, e2ap_RANfunctionRevision* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RANfunctionRevision.c ---

/*******************************************/
/* File .c missing: e2ap_PrintableString.c */
/*******************************************/

// --- Begin of e2ap_RANfunctionOID.c ---
/* e2ap_RANfunctionOID.c */

//printable string
/*****************************************/
/*           RANfunctionOID                */
/*****************************************/

/* Constrained PrintableString */
EXTERN int asn1PE_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionOID");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(1000), OSUINTCONST(0), OSUINT32_MAX);

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

EXTERN int asn1PD_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID* ppvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionOID");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(1000), OSUINTCONST(0), OSUINT32_MAX);

   stat = pd_ConstrainedStringEx (pctxt, ppvalue, 0, 8, 7, 7);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}


void asn1Free_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID pvalue)
{
   if(0==pvalue) return;
   rtxMemFreePtr (pctxt, (void*)pvalue);
   pvalue = 0;
}

/* Print to string */
int asn1PrtToStr_e2ap_RANfunctionOID (const char* name, e2ap_RANfunctionOID pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringCharStr (name, pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RANfunctionOID.c ---

// --- Begin of e2ap_RANfunction_Item.c ---

/*****************************************/
/*           RANfunction-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RANfunction-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ranFunctionID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionID");
   stat = asn1PE_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ranFunctionDefinition */  

   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionDefinition");
   stat = asn1PE_e2ap_RANfunctionDefinition (pctxt, &pvalue->ranFunctionDefinition);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ranFunctionRevision */  

   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionRevision");
   stat = asn1PE_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ranFunctionOID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionOID");
   stat = asn1PE_e2ap_RANfunctionOID (pctxt, &pvalue->ranFunctionOID);
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

int asn1PD_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[4];

   RTXCTXTPUSHTYPENAME(pctxt, "RANfunction-Item");

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

   /* decode field ranFunctionDefinition */
   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionDefinition");
      stat = asn1PD_e2ap_RANfunctionDefinition (pctxt, &pvalue->ranFunctionDefinition);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ranFunctionRevision */
   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionRevision");
      stat = asn1PD_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ranFunctionOID */
   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionOID");
      stat = asn1PD_e2ap_RANfunctionOID (pctxt, &pvalue->ranFunctionOID);
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

int asn1Init_e2ap_RANfunction_Item (e2ap_RANfunction_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RANfunctionID (&pvalue->ranFunctionID);
   asn1Init_e2ap_RANfunctionDefinition (&pvalue->ranFunctionDefinition);
   asn1Init_e2ap_RANfunctionRevision (&pvalue->ranFunctionRevision);
   asn1Init_e2ap_RANfunctionOID (&pvalue->ranFunctionOID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   asn1Free_e2ap_RANfunctionDefinition (pctxt, &pvalue->ranFunctionDefinition);
   asn1Free_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
   asn1Free_e2ap_RANfunctionOID (pctxt, &pvalue->ranFunctionOID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RANfunction_Item (const char* name, e2ap_RANfunction_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RANfunctionID ("ranFunctionID", &pvalue->ranFunctionID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RANfunctionDefinition ("ranFunctionDefinition", &pvalue->ranFunctionDefinition, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RANfunctionRevision ("ranFunctionRevision", &pvalue->ranFunctionRevision, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RANfunctionOID ("ranFunctionOID", &pvalue->ranFunctionOID, buffer, bufSize) < 0)
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
// --- End of e2ap_RANfunction_Item.c ---

// --- Begin of e2ap_RANfunction_ItemIEs.c ---
/* e2ap_RANfunction_ItemIEs.c */

/*****************************************/
/*           RANfunction_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunction-ItemIEs");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_RANfunction_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_RANfunction_ItemIEs_.criticality);
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
      case T_E2AP_PDU_Contents_RANfunction_ItemIEs_RANfunction_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "RANfunction_Item");
         stat = asn1PE_e2ap_RANfunction_Item (pctxt, pvalue->value.u._e2apRANfunction_ItemIEs_RANfunction_Item);
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

int asn1PD_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_RANfunction_ItemIEs (e2ap_RANfunction_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_RANfunction_ItemIEs));
}

void asn1Free_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
// --- End of e2ap_RANfunction_ItemIEs.c ---

// --- Begin of e2ap_RANfunctions_List.c ---
/*****************************************/
/*           RANfunctions_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RANfunction_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctions-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRANfunctionID), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RANfunction_ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RANfunction_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RANfunction_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctions-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRANfunctionID), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RANfunction_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RANfunction_ItemIEs (pdata);

      stat = asn1PD_e2ap_RANfunction_ItemIEs (pctxt, pdata);
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

void asn1Init_e2ap_RANfunctions_List (e2ap_RANfunctions_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RANfunction_ItemIEs* pdata = (e2ap_RANfunction_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RANfunction_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}

#if 0
void asn1Free_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_RANfunction_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_RANfunction_ItemIEs*)pnode->data;
         asn1Free_e2ap_RANfunction_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_RANfunctions_List.c ---

// --- Begin of e2ap_RANfunctionID_Item.c ---

/*****************************************/
/*           RANfunctionID-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RANfunctionID-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ranFunctionID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionID");
   stat = asn1PE_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ranFunctionRevision */  

   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionRevision");
   stat = asn1PE_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
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

int asn1PD_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "RANfunctionID-Item");

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
   /* decode field ranFunctionID */
   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionID");
      stat = asn1PD_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ranFunctionRevision */
   RTXCTXTPUSHELEMNAME(pctxt, "ranFunctionRevision");
      stat = asn1PD_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
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

int asn1Init_e2ap_RANfunctionID_Item (e2ap_RANfunctionID_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RANfunctionID (&pvalue->ranFunctionID);
   asn1Init_e2ap_RANfunctionRevision (&pvalue->ranFunctionRevision);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   asn1Free_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RANfunctionID_Item (const char* name, e2ap_RANfunctionID_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RANfunctionID ("ranFunctionID", &pvalue->ranFunctionID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RANfunctionRevision ("ranFunctionRevision", &pvalue->ranFunctionRevision, buffer, bufSize) < 0)
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
// --- End of e2ap_RANfunctionID_Item.c ---

// --- Begin of e2ap_RANfunctionID_ItemIEs.c ---
/* e2ap_RANfunctionID_ItemIEs.c */

/*****************************************/
/*           RANfunctionID_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_RANfunctionID_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionID_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionID-ItemIEs");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_RANfunctionID_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_RANfunctionID_ItemIEs_.criticality);
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
      case T_E2AP_PDU_Contents_RANfunctionID_ItemIEs_RANfunctionID_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "RANfunctionID_Item");
         stat = asn1PE_e2ap_RANfunctionID_Item (pctxt, pvalue->value.u._e2apRANfunctionID_ItemIEs_RANfunctionID_Item);
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

int asn1PD_e2ap_RANfunctionID_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionID_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_RANfunctionID_ItemIEs (e2ap_RANfunctionID_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_RANfunctionID_ItemIEs));
}

void asn1Free_e2ap_RANfunctionID_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionID_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
// --- End of e2ap_RANfunctionID_ItemIEs.c ---

// --- Begin of e2ap_RANfunctionsID_List.c ---
/*****************************************/
/*           RANfunctionsID_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_RANfunctionsID_List (OSCTXT* pctxt, e2ap_RANfunctionsID_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RANfunctionID_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionsID-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRANfunctionID), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RANfunctionID_ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RANfunctionID_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RANfunctionsID_List (OSCTXT* pctxt, e2ap_RANfunctionsID_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RANfunctionID_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RANfunctionsID-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofRANfunctionID), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RANfunctionID_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RANfunctionID_ItemIEs (pdata);

      stat = asn1PD_e2ap_RANfunctionID_ItemIEs (pctxt, pdata);
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

void asn1Init_e2ap_RANfunctionsID_List (e2ap_RANfunctionsID_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_RANfunctionsID_List (OSCTXT* pctxt, e2ap_RANfunctionsID_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RANfunctionID_ItemIEs* pdata = (e2ap_RANfunctionID_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RANfunctionID_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}

#if 0
void asn1Free_e2ap_RANfunctionsID_List (OSCTXT* pctxt, e2ap_RANfunctionsID_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_RANfunctionID_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_RANfunctionID_ItemIEs*)pnode->data;
         asn1Free_e2ap_RANfunctionID_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_RANfunctionsID_List.c ---

/************************************************/
/* File .c missing: e2ap_RICserviceUpdate_IEs.c */
/************************************************/

// --- Begin of e2ap_RICserviceUpdate.c ---

/*****************************************/
/*           RICserviceUpdate                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICserviceUpdate (OSCTXT* pctxt, e2ap_RICserviceUpdate* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceUpdate");

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

int asn1PD_e2ap_RICserviceUpdate (OSCTXT* pctxt, e2ap_RICserviceUpdate* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "RICserviceUpdate");

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

int asn1Init_e2ap_RICserviceUpdate (e2ap_RICserviceUpdate* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_ProtocolIE_Container (&pvalue->protocolIEs);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICserviceUpdate (OSCTXT* pctxt, e2ap_RICserviceUpdate* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_ProtocolIE_Container (pctxt, &pvalue->protocolIEs);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICserviceUpdate (const char* name, e2ap_RICserviceUpdate* pvalue, char* buffer, OSSIZE bufSize)
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
// --- End of e2ap_RICserviceUpdate.c ---

// --- Begin of e2ap_RICserviceUpdate_protocolIEs.c ---
/******************************************************/
/*                                                    */
/*    RICserviceUpdate_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

EXTERN int asn1PE_e2ap_RICserviceUpdate_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEst* pvalue)
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
        stat = asn1PE_e2ap_RICserviceUpdate_protocolIEs_element (pctxt, ((e2ap_RICserviceUpdate_protocolIEs_element*)pnode->data));
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        xx1++;
        RTXCTXTPOPARRAYELEMNAME(pctxt);
    }

    return (stat);
}

EXTERN int  asn1PD_e2ap_RICserviceUpdate_protocolIEs(OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs* pvalue)
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
        e2ap_RICserviceUpdate_protocolIEs_element* pdata;
        RTXCTXTPUSHARRAYELEMNAME(pctxt, "SEQUENCE", &pnode, &pdata);

        if(pnode == NULL) return LOG_RTERR(pctxt, RTERR_NOMEM);

        asn1Init_e2ap_RICserviceUpdate_protocolIEs_element(pdata);
        rtxDListAppendNode(pvalue, pnode);
       // stat = asn1PD_e2ap_RICserviceUpdate_protocolIEs_element (pctxt, pdata);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        RTXCTXTPOPARRAYELEMNAME(pctxt);

    }
    return (stat);
}


int asn1Init_e2ap_RICserviceUpdate_protocolIEs(e2ap_RICserviceUpdate_protocolIEs* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    rtxDListFastInit (pvalue);
    return 0;
}

void asn1Free_e2ap_RICserviceUpdate_protocolIEs(OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs* pvalue)
{
    if(0==pvalue) return;   
    e2ap_RICserviceUpdate_protocolIEs_element* pdata;
    OSRTDListNode* pnode=pvalue->head;
    while(0!=pnode){
        pdata = (e2ap_RICserviceUpdate_protocolIEs_element*)pnode->data;
       // asn1Free_e2ap_RICserviceUpdate_protocolIEs_element(pctxt, pdata);
        pnode = pnode->next;
    }
    rtxDListFreeAll(pctxt, pvalue);
}

// --- End of e2ap_RICserviceUpdate_protocolIEs.c ---

// --- Begin of e2ap_RICserviceUpdate_protocolIEs_element.c ---
/*****************************************/
/*    RICserviceUpdate_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe

EXTERN int asn1PE_e2ap_RICserviceUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs_element* pvalue)
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
            case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_TransactionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-TransactionID");

                stat = asn1PE_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctionsAdded:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RANfunctionsAdded");

                stat = asn1PE_e2ap_RANfunctions_List (pctxt, pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctionsAdded);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctionsModified:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RANfunctionsModified");

                stat = asn1PE_e2ap_RANfunctions_List (pctxt, pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctionsModified);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctionsDeleted:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RANfunctionsDeleted");

                stat = asn1PE_e2ap_RANfunctionsID_List (pctxt, pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctionsDeleted);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_UNDEF_:
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

EXTERN int  asn1PD_e2ap_RICserviceUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs_element* pvalue){
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
        
            case ASN1V_e2ap_id_TransactionID:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_TransactionID;
            RTXCTXTPUSHELEMNAME(pctxt, "id-TransactionID");
            pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_TransactionID 
                = rtxMemAllocType(pctxt, e2ap_TransactionID);

            asn1Init_e2ap_TransactionID(pvalue->
                value.u._e2ap_RICserviceUpdate_IEs_id_TransactionID);

            stat = asn1PD_e2ap_TransactionID (pctxt,
                (e2ap_TransactionID*)pvalue->value.
                u._e2ap_RICserviceUpdate_IEs_id_TransactionID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_RANfunctionsAdded:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctions_List;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RANfunctionsAdded");
            pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List 
                = rtxMemAllocType(pctxt, e2ap_RANfunctions_List);

            asn1Init_e2ap_RANfunctions_List(pvalue->
                value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List);

            stat = asn1PD_e2ap_RANfunctions_List (pctxt,
                (e2ap_RANfunctions_List*)pvalue->value.
                u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_RANfunctionsModified:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctions_List;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RANfunctionsModified");
            pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List 
                = rtxMemAllocType(pctxt, e2ap_RANfunctions_List);

            asn1Init_e2ap_RANfunctions_List(pvalue->
                value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List);

            stat = asn1PD_e2ap_RANfunctions_List (pctxt,
                (e2ap_RANfunctions_List*)pvalue->value.
                u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_RANfunctionsDeleted:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctionsID_List;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RANfunctionsDeleted");
            pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctionsID_List 
                = rtxMemAllocType(pctxt, e2ap_RANfunctionsID_List);

            asn1Init_e2ap_RANfunctionsID_List(pvalue->
                value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctionsID_List);

            stat = asn1PD_e2ap_RANfunctionsID_List (pctxt,
                (e2ap_RANfunctionsID_List*)pvalue->value.
                u._e2ap_RICserviceUpdate_IEs_id_RANfunctionsID_List);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    

        default:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_UNDEF_;
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


int asn1Init_e2ap_RICserviceUpdate_protocolIEs_element(e2ap_RICserviceUpdate_protocolIEs_element* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    OSCRTLMEMSET (&pvalue->value, 0, sizeof(pvalue->value));
    return 0;
}


//-----> chuaw có template rtxFreeASN1OpenType
#if 0
void asn1Free_e2ap_RICserviceUpdate_protocolIEs_element(OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs_element* pvalue)
{
    if(NULL==pvalue) return;
    switch(pvalue->value.t){
        case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_TransactionID:
            // rtxFreeE2ap_TransactionID(pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_TransactionID);

            if(pvalue->value.i._e2ap_RICserviceUpdate_IEs_id_TransactionID!=NULL){
            asn1Free_e2ap_TransactionID(pctxt, pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_TransactionID);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_TransactionID);
            pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_TransactionID = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctions_List:
            // rtxFreeE2ap_RANfunctions_List(pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List);

            if(pvalue->value.i._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List!=NULL){
            asn1Free_e2ap_RANfunctions_List(pctxt, pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List);
            pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctions_List:
            // rtxFreeE2ap_RANfunctions_List(pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List);

            if(pvalue->value.i._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List!=NULL){
            asn1Free_e2ap_RANfunctions_List(pctxt, pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List);
            pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctionsID_List:
            // rtxFreeE2ap_RANfunctionsID_List(pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctionsID_List);

            if(pvalue->value.i._e2ap_RICserviceUpdate_IEs_id_RANfunctionsID_List!=NULL){
            asn1Free_e2ap_RANfunctionsID_List(pctxt, pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctionsID_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctionsID_List);
            pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctionsID_List = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_UNDEF_:
            rtxFreeASN1OpenType(pvalue->value.u.extElem1);
            break;
        default:
            break;
    }
}

int asn1PrtToStr_e2ap_RICserviceUpdate_protocolIEs_element(OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs_element* pvalue)
{
    int stat =0;
    RTXCTXTPUSHELEMNAME(pctxt, "e2ap_RICserviceUpdate_protocolIEs_element");

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
            case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_TransactionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "TransactionID");

                stat = asn1PrtToStr_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctions_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RANfunctions-List");

                stat = asn1PrtToStr_e2ap_RANfunctions_List (pctxt, pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctions_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RANfunctions-List");

                stat = asn1PrtToStr_e2ap_RANfunctions_List (pctxt, pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctions_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctionsID_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RANfunctionsID-List");

                stat = asn1PrtToStr_e2ap_RANfunctionsID_List (pctxt, pvalue->value.u._e2ap_RICserviceUpdate_IEs_id_RANfunctionsID_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_UNDEF_:
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
// --- End of e2ap_RICserviceUpdate_protocolIEs_element.c ---

