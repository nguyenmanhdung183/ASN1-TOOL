#include "output_main.h"
// --- Begin of doc/header.c ---
//======================E2AP.c========================//
// --- End of doc/header.c ---

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

// --- Begin of e2ap_RICeventTriggerDefinition.c ---
/*****************************************/
/*           RICeventTriggerDefinition                */
/*****************************************/
//octet string

/* Dynamic OCTET STRING (no SIZE constraint) */
EXTERN int asn1PE_e2ap_RICeventTriggerDefinition (OSCTXT* pctxt, e2ap_RICeventTriggerDefinition* pvalue)
{
   int stat = 0;
  
   RTXCTXTPUSHTYPENAME (pctxt, "RICeventTriggerDefinition");
   
   stat = pe_OctetString (pctxt, pvalue->numocts, pvalue->data);
 
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RICeventTriggerDefinition (OSCTXT* pctxt, e2ap_RICeventTriggerDefinition** ppvalue)
{
   int stat = 0;
  
   RTXCTXTPUSHTYPENAME (pctxt, "RICeventTriggerDefinition");
 
   stat = pd_DynOctetString (pctxt, (OSDynOctStr**)ppvalue);
   
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

int asn1Init_e2ap_RICeventTriggerDefinition (e2ap_RICeventTriggerDefinition* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->numocts = 0;
   pvalue->data = 0;
   return 0;
}

void asn1Free_e2ap_RICeventTriggerDefinition (OSCTXT* pctxt, e2ap_RICeventTriggerDefinition* pvalue)
{
   if (pvalue == 0) return;
   if (pvalue->numocts > 0 && pvalue->data != 0) {
      rtxMemFreePtr (pctxt, (void*)pvalue->data);
   }
   pvalue->numocts = 0;
   pvalue->data = 0;
}


/* Print to string */
int asn1PrtToStr_e2ap_RICeventTriggerDefinition (const char* name, e2ap_RICeventTriggerDefinition* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) {
      return -1;
   }
   if (rtPrintToStringHexStr (name, pvalue->numocts, pvalue->data, buffer, bufSize) < 0){
      return -1;
   }
   return 0;
}
// --- End of e2ap_RICeventTriggerDefinition.c ---

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

// --- Begin of e2ap_RICaction_ToBeRemovedForModification_Item.c ---

/*****************************************/
/*           RICaction-ToBeRemovedForModification-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICaction_ToBeRemovedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeRemovedForModification_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICaction-ToBeRemovedForModification-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricActionID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionID");
   stat = asn1PE_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
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

int asn1PD_e2ap_RICaction_ToBeRemovedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeRemovedForModification_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "RICaction-ToBeRemovedForModification-Item");

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
   /* decode field ricActionID */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionID");
      stat = asn1PD_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
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

int asn1Init_e2ap_RICaction_ToBeRemovedForModification_Item (e2ap_RICaction_ToBeRemovedForModification_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RICactionID (&pvalue->ricActionID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICaction_ToBeRemovedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeRemovedForModification_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICaction_ToBeRemovedForModification_Item (const char* name, e2ap_RICaction_ToBeRemovedForModification_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICactionID ("ricActionID", &pvalue->ricActionID, buffer, bufSize) < 0)
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
// --- End of e2ap_RICaction_ToBeRemovedForModification_Item.c ---

// --- Begin of e2ap_RICaction_ToBeRemovedForModification_ItemIEs.c ---
/* e2ap_RICaction_ToBeRemovedForModification_ItemIEs.c */

/*****************************************/
/*           RICaction_ToBeRemovedForModification_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_RICaction_ToBeRemovedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeRemovedForModification_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICaction-ToBeRemovedForModification-ItemIEs");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_RICaction_ToBeRemovedForModification_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_RICaction_ToBeRemovedForModification_ItemIEs_.criticality);
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
      case T_E2AP_PDU_Contents_RICaction_ToBeRemovedForModification_ItemIEs_RICaction_ToBeRemovedForModification_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "RICaction_ToBeRemovedForModification_Item");
         stat = asn1PE_e2ap_RICaction_ToBeRemovedForModification_Item (pctxt, pvalue->value.u._e2apRICaction_ToBeRemovedForModification_ItemIEs_RICaction_ToBeRemovedForModification_Item);
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

int asn1PD_e2ap_RICaction_ToBeRemovedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeRemovedForModification_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_RICaction_ToBeRemovedForModification_ItemIEs (e2ap_RICaction_ToBeRemovedForModification_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_RICaction_ToBeRemovedForModification_ItemIEs));
}

void asn1Free_e2ap_RICaction_ToBeRemovedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeRemovedForModification_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
// --- End of e2ap_RICaction_ToBeRemovedForModification_ItemIEs.c ---

// --- Begin of e2ap_RICactions_ToBeRemovedForModification_List.c ---
/*****************************************/
/*           RICactions_ToBeRemovedForModification_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_RICactions_ToBeRemovedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeRemovedForModification_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICaction_ToBeRemovedForModification_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICactions-ToBeRemovedForModification-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(0), OSUINTCONST(ASN1V_e2ap_maxofRICactionID), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RICaction_ToBeRemovedForModification_ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RICaction_ToBeRemovedForModification_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RICactions_ToBeRemovedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeRemovedForModification_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICaction_ToBeRemovedForModification_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICactions-ToBeRemovedForModification-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(0), OSUINTCONST(ASN1V_e2ap_maxofRICactionID), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RICaction_ToBeRemovedForModification_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RICaction_ToBeRemovedForModification_ItemIEs (pdata);

      stat = asn1PD_e2ap_RICaction_ToBeRemovedForModification_ItemIEs (pctxt, pdata);
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

void asn1Init_e2ap_RICactions_ToBeRemovedForModification_List (e2ap_RICactions_ToBeRemovedForModification_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_RICactions_ToBeRemovedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeRemovedForModification_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RICaction_ToBeRemovedForModification_ItemIEs* pdata = (e2ap_RICaction_ToBeRemovedForModification_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RICaction_ToBeRemovedForModification_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}

#if 0
void asn1Free_e2ap_RICactions_ToBeRemovedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeRemovedForModification_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_RICaction_ToBeRemovedForModification_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_RICaction_ToBeRemovedForModification_ItemIEs*)pnode->data;
         asn1Free_e2ap_RICaction_ToBeRemovedForModification_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_RICactions_ToBeRemovedForModification_List.c ---

// --- Begin of e2ap_RICactionDefinition.c ---
/*****************************************/
/*           RICactionDefinition                */
/*****************************************/
//octet string

/* Dynamic OCTET STRING (no SIZE constraint) */
EXTERN int asn1PE_e2ap_RICactionDefinition (OSCTXT* pctxt, e2ap_RICactionDefinition* pvalue)
{
   int stat = 0;
  
   RTXCTXTPUSHTYPENAME (pctxt, "RICactionDefinition");
   
   stat = pe_OctetString (pctxt, pvalue->numocts, pvalue->data);
 
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RICactionDefinition (OSCTXT* pctxt, e2ap_RICactionDefinition** ppvalue)
{
   int stat = 0;
  
   RTXCTXTPUSHTYPENAME (pctxt, "RICactionDefinition");
 
   stat = pd_DynOctetString (pctxt, (OSDynOctStr**)ppvalue);
   
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

int asn1Init_e2ap_RICactionDefinition (e2ap_RICactionDefinition* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->numocts = 0;
   pvalue->data = 0;
   return 0;
}

void asn1Free_e2ap_RICactionDefinition (OSCTXT* pctxt, e2ap_RICactionDefinition* pvalue)
{
   if (pvalue == 0) return;
   if (pvalue->numocts > 0 && pvalue->data != 0) {
      rtxMemFreePtr (pctxt, (void*)pvalue->data);
   }
   pvalue->numocts = 0;
   pvalue->data = 0;
}


/* Print to string */
int asn1PrtToStr_e2ap_RICactionDefinition (const char* name, e2ap_RICactionDefinition* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) {
      return -1;
   }
   if (rtPrintToStringHexStr (name, pvalue->numocts, pvalue->data, buffer, bufSize) < 0){
      return -1;
   }
   return 0;
}
// --- End of e2ap_RICactionDefinition.c ---

// --- Begin of e2ap_RICactionExecutionOrder.c ---
/*****************************************/
/*         RICactionExecutionOrder     */
/*****************************************/
//interger no ext

EXTERN int asn1PE_e2ap_RICactionExecutionOrder (OSCTXT* pctxt, e2ap_RICactionExecutionOrder value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICactionExecutionOrder");
   stat = pe_ConsUnsigned (pctxt, value, 0, 255);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RICactionExecutionOrder (OSCTXT* pctxt, e2ap_RICactionExecutionOrder* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICactionExecutionOrder");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 8);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RICactionExecutionOrder (const char* name, e2ap_RICactionExecutionOrder* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RICactionExecutionOrder.c ---

// --- Begin of e2ap_RICsubsequentActionType.c ---
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
// --- End of e2ap_RICsubsequentActionType.c ---

// --- Begin of e2ap_RICtimeToWait.c ---
/******************************************************/
/*                                                    */
/*    RICtimeToWait                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_RICtimeToWait_ENUMTAB[] = {
    { OSUTF8("w1ms"), 0, 4, 0 },
    { OSUTF8("w2ms"), 1, 4, 1 },
    { OSUTF8("w5ms"), 2, 4, 2 },
    { OSUTF8("w10ms"), 3, 5, 3 },
    { OSUTF8("w20ms"), 4, 5, 4 },
    { OSUTF8("w30ms"), 5, 5, 5 },
    { OSUTF8("w40ms"), 6, 5, 6 },
    { OSUTF8("w50ms"), 7, 5, 7 },
    { OSUTF8("w100ms"), 8, 6, 8 },
    { OSUTF8("w200ms"), 9, 6, 9 },
    { OSUTF8("w500ms"), 10, 6, 10 },
    { OSUTF8("w1s"), 11, 3, 11 },
    { OSUTF8("w2s"), 12, 3, 12 },
    { OSUTF8("w5s"), 13, 3, 13 },
    { OSUTF8("w10s"), 14, 4, 14 },
    { OSUTF8("w20s"), 15, 4, 15 },
    { OSUTF8("w60s"), 16, 4, 16 }
};


const OSUTF8CHAR* e2ap_RICtimeToWait_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_RICtimeToWait_ENUMTABSIZE){
      return e2ap_RICtimeToWait_ENUMTAB[e2ap_RICtimeToWait_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_RICtimeToWait_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICtimeToWait* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_RICtimeToWait_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_RICtimeToWait_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICtimeToWait* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_RICtimeToWait_ENUMTAB, e2ap_RICtimeToWait_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_RICtimeToWait)e2ap_RICtimeToWait_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_RICtimeToWait (OSCTXT* pctxt, e2ap_RICtimeToWait value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICtimeToWait");
   if (value >= 17) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(16));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RICtimeToWait (OSCTXT* pctxt, e2ap_RICtimeToWait* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "RICtimeToWait");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(16));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RICtimeToWait (const char* name, e2ap_RICtimeToWait* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = w1ms", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = w2ms", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = w5ms", buffer, bufSize);
         break;
      case 3:
         stat = rtPrintToString(" = w10ms", buffer, bufSize);
         break;
      case 4:
         stat = rtPrintToString(" = w20ms", buffer, bufSize);
         break;
      case 5:
         stat = rtPrintToString(" = w30ms", buffer, bufSize);
         break;
      case 6:
         stat = rtPrintToString(" = w40ms", buffer, bufSize);
         break;
      case 7:
         stat = rtPrintToString(" = w50ms", buffer, bufSize);
         break;
      case 8:
         stat = rtPrintToString(" = w100ms", buffer, bufSize);
         break;
      case 9:
         stat = rtPrintToString(" = w200ms", buffer, bufSize);
         break;
      case 10:
         stat = rtPrintToString(" = w500ms", buffer, bufSize);
         break;
      case 11:
         stat = rtPrintToString(" = w1s", buffer, bufSize);
         break;
      case 12:
         stat = rtPrintToString(" = w2s", buffer, bufSize);
         break;
      case 13:
         stat = rtPrintToString(" = w5s", buffer, bufSize);
         break;
      case 14:
         stat = rtPrintToString(" = w10s", buffer, bufSize);
         break;
      case 15:
         stat = rtPrintToString(" = w20s", buffer, bufSize);
         break;
      case 16:
         stat = rtPrintToString(" = w60s", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_RICtimeToWait.c ---

// --- Begin of e2ap_RICsubsequentAction.c ---

/*****************************************/
/*           RICsubsequentAction                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICsubsequentAction (OSCTXT* pctxt, e2ap_RICsubsequentAction* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICsubsequentAction");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricSubsequentActionType */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricSubsequentActionType");
   stat = asn1PE_e2ap_RICsubsequentActionType (pctxt, &pvalue->ricSubsequentActionType);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ricTimeToWait */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricTimeToWait");
   stat = asn1PE_e2ap_RICtimeToWait (pctxt, &pvalue->ricTimeToWait);
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

int asn1PD_e2ap_RICsubsequentAction (OSCTXT* pctxt, e2ap_RICsubsequentAction* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "RICsubsequentAction");

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
   /* decode field ricSubsequentActionType */
   RTXCTXTPUSHELEMNAME(pctxt, "ricSubsequentActionType");
      stat = asn1PD_e2ap_RICsubsequentActionType (pctxt, &pvalue->ricSubsequentActionType);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ricTimeToWait */
   RTXCTXTPUSHELEMNAME(pctxt, "ricTimeToWait");
      stat = asn1PD_e2ap_RICtimeToWait (pctxt, &pvalue->ricTimeToWait);
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

int asn1Init_e2ap_RICsubsequentAction (e2ap_RICsubsequentAction* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RICsubsequentActionType (&pvalue->ricSubsequentActionType);
   asn1Init_e2ap_RICtimeToWait (&pvalue->ricTimeToWait);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICsubsequentAction (OSCTXT* pctxt, e2ap_RICsubsequentAction* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RICsubsequentActionType (pctxt, &pvalue->ricSubsequentActionType);
   asn1Free_e2ap_RICtimeToWait (pctxt, &pvalue->ricTimeToWait);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICsubsequentAction (const char* name, e2ap_RICsubsequentAction* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICsubsequentActionType ("ricSubsequentActionType", &pvalue->ricSubsequentActionType, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICtimeToWait ("ricTimeToWait", &pvalue->ricTimeToWait, buffer, bufSize) < 0)
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
// --- End of e2ap_RICsubsequentAction.c ---

// --- Begin of e2ap_RICaction_ToBeModifiedForModification_Item.c ---

/*****************************************/
/*           RICaction-ToBeModifiedForModification-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICaction_ToBeModifiedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeModifiedForModification_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICaction-ToBeModifiedForModification-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricActionID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionID");
   stat = asn1PE_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ricActionDefinition */  
   if (pvalue->m_ricActionDefinitionPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionDefinition");
   stat = asn1PE_e2ap_RICactionDefinition (pctxt, &pvalue->ricActionDefinition);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricActionExecutionOrder */  
   if (pvalue->m_ricActionExecutionOrderPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionExecutionOrder");
   stat = asn1PE_e2ap_RICactionExecutionOrder (pctxt, &pvalue->ricActionExecutionOrder);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ricSubsequentAction */  
   if (pvalue->m_ricSubsequentActionPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricSubsequentAction");
   stat = asn1PE_e2ap_RICsubsequentAction (pctxt, &pvalue->ricSubsequentAction);
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

int asn1PD_e2ap_RICaction_ToBeModifiedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeModifiedForModification_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[4];

   RTXCTXTPUSHTYPENAME(pctxt, "RICaction-ToBeModifiedForModification-Item");

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
   /* decode field ricActionID */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionID");
      stat = asn1PD_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ricActionDefinition */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionDefinition");
   if (optbits[0]) {
      pvalue->m_ricActionDefinitionPresent = TRUE;
      stat = asn1PD_e2ap_RICactionDefinition (pctxt, &pvalue->ricActionDefinition);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricActionDefinitionPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricActionExecutionOrder */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionExecutionOrder");
   if (optbits[0]) {
      pvalue->m_ricActionExecutionOrderPresent = TRUE;
      stat = asn1PD_e2ap_RICactionExecutionOrder (pctxt, &pvalue->ricActionExecutionOrder);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricActionExecutionOrderPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ricSubsequentAction */
   RTXCTXTPUSHELEMNAME(pctxt, "ricSubsequentAction");
   if (optbits[0]) {
      pvalue->m_ricSubsequentActionPresent = TRUE;
      stat = asn1PD_e2ap_RICsubsequentAction (pctxt, &pvalue->ricSubsequentAction);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricSubsequentActionPresent = FALSE;
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

int asn1Init_e2ap_RICaction_ToBeModifiedForModification_Item (e2ap_RICaction_ToBeModifiedForModification_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RICactionID (&pvalue->ricActionID);
   asn1Init_e2ap_RICactionDefinition (&pvalue->ricActionDefinition);
   asn1Init_e2ap_RICactionExecutionOrder (&pvalue->ricActionExecutionOrder);
   asn1Init_e2ap_RICsubsequentAction (&pvalue->ricSubsequentAction);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICaction_ToBeModifiedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeModifiedForModification_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
   asn1Free_e2ap_RICactionDefinition (pctxt, &pvalue->ricActionDefinition);
   asn1Free_e2ap_RICactionExecutionOrder (pctxt, &pvalue->ricActionExecutionOrder);
   asn1Free_e2ap_RICsubsequentAction (pctxt, &pvalue->ricSubsequentAction);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICaction_ToBeModifiedForModification_Item (const char* name, e2ap_RICaction_ToBeModifiedForModification_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICactionID ("ricActionID", &pvalue->ricActionID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICactionDefinition ("ricActionDefinition", &pvalue->ricActionDefinition, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICactionExecutionOrder ("ricActionExecutionOrder", &pvalue->ricActionExecutionOrder, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICsubsequentAction ("ricSubsequentAction", &pvalue->ricSubsequentAction, buffer, bufSize) < 0)
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
// --- End of e2ap_RICaction_ToBeModifiedForModification_Item.c ---

// --- Begin of e2ap_RICaction_ToBeModifiedForModification_ItemIEs.c ---
/* e2ap_RICaction_ToBeModifiedForModification_ItemIEs.c */

/*****************************************/
/*           RICaction_ToBeModifiedForModification_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_RICaction_ToBeModifiedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeModifiedForModification_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICaction-ToBeModifiedForModification-ItemIEs");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_RICaction_ToBeModifiedForModification_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_RICaction_ToBeModifiedForModification_ItemIEs_.criticality);
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
      case T_E2AP_PDU_Contents_RICaction_ToBeModifiedForModification_ItemIEs_RICaction_ToBeModifiedForModification_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "RICaction_ToBeModifiedForModification_Item");
         stat = asn1PE_e2ap_RICaction_ToBeModifiedForModification_Item (pctxt, pvalue->value.u._e2apRICaction_ToBeModifiedForModification_ItemIEs_RICaction_ToBeModifiedForModification_Item);
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

int asn1PD_e2ap_RICaction_ToBeModifiedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeModifiedForModification_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_RICaction_ToBeModifiedForModification_ItemIEs (e2ap_RICaction_ToBeModifiedForModification_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_RICaction_ToBeModifiedForModification_ItemIEs));
}

void asn1Free_e2ap_RICaction_ToBeModifiedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeModifiedForModification_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
// --- End of e2ap_RICaction_ToBeModifiedForModification_ItemIEs.c ---

// --- Begin of e2ap_RICactions_ToBeModifiedForModification_List.c ---
/*****************************************/
/*           RICactions_ToBeModifiedForModification_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_RICactions_ToBeModifiedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeModifiedForModification_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICaction_ToBeModifiedForModification_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICactions-ToBeModifiedForModification-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(0), OSUINTCONST(ASN1V_e2ap_maxofRICactionID), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RICaction_ToBeModifiedForModification_ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RICaction_ToBeModifiedForModification_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RICactions_ToBeModifiedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeModifiedForModification_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICaction_ToBeModifiedForModification_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICactions-ToBeModifiedForModification-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(0), OSUINTCONST(ASN1V_e2ap_maxofRICactionID), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RICaction_ToBeModifiedForModification_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RICaction_ToBeModifiedForModification_ItemIEs (pdata);

      stat = asn1PD_e2ap_RICaction_ToBeModifiedForModification_ItemIEs (pctxt, pdata);
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

void asn1Init_e2ap_RICactions_ToBeModifiedForModification_List (e2ap_RICactions_ToBeModifiedForModification_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_RICactions_ToBeModifiedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeModifiedForModification_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RICaction_ToBeModifiedForModification_ItemIEs* pdata = (e2ap_RICaction_ToBeModifiedForModification_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RICaction_ToBeModifiedForModification_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}

#if 0
void asn1Free_e2ap_RICactions_ToBeModifiedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeModifiedForModification_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_RICaction_ToBeModifiedForModification_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_RICaction_ToBeModifiedForModification_ItemIEs*)pnode->data;
         asn1Free_e2ap_RICaction_ToBeModifiedForModification_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_RICactions_ToBeModifiedForModification_List.c ---

// --- Begin of e2ap_RICactionType.c ---
/******************************************************/
/*                                                    */
/*    RICactionType                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_RICactionType_ENUMTAB[] = {
    { OSUTF8("report"), 0, 6, 0 },
    { OSUTF8("insert"), 1, 6, 1 },
    { OSUTF8("policy"), 2, 6, 2 }
};


const OSUTF8CHAR* e2ap_RICactionType_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_RICactionType_ENUMTABSIZE){
      return e2ap_RICactionType_ENUMTAB[e2ap_RICactionType_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_RICactionType_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICactionType* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_RICactionType_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_RICactionType_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICactionType* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_RICactionType_ENUMTAB, e2ap_RICactionType_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_RICactionType)e2ap_RICactionType_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_RICactionType (OSCTXT* pctxt, e2ap_RICactionType value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICactionType");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RICactionType (OSCTXT* pctxt, e2ap_RICactionType* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "RICactionType");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_RICactionType (const char* name, e2ap_RICactionType* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = report", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = insert", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = policy", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_RICactionType.c ---

// --- Begin of e2ap_RICaction_ToBeAddedForModification_Item.c ---

/*****************************************/
/*           RICaction-ToBeAddedForModification-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICaction_ToBeAddedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeAddedForModification_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICaction-ToBeAddedForModification-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ricActionID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionID");
   stat = asn1PE_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ricActionType */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionType");
   stat = asn1PE_e2ap_RICactionType (pctxt, &pvalue->ricActionType);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ricActionDefinition */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionDefinition");
   stat = asn1PE_e2ap_RICactionDefinition (pctxt, &pvalue->ricActionDefinition);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ricActionExecutionOrder */  

   RTXCTXTPUSHELEMNAME(pctxt, "ricActionExecutionOrder");
   stat = asn1PE_e2ap_RICactionExecutionOrder (pctxt, &pvalue->ricActionExecutionOrder);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field ricSubsequentAction */  
   if (pvalue->m_ricSubsequentActionPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ricSubsequentAction");
   stat = asn1PE_e2ap_RICsubsequentAction (pctxt, &pvalue->ricSubsequentAction);
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

int asn1PD_e2ap_RICaction_ToBeAddedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeAddedForModification_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[5];

   RTXCTXTPUSHTYPENAME(pctxt, "RICaction-ToBeAddedForModification-Item");

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
   /* decode field ricActionID */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionID");
      stat = asn1PD_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ricActionType */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionType");
      stat = asn1PD_e2ap_RICactionType (pctxt, &pvalue->ricActionType);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ricActionDefinition */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionDefinition");
      stat = asn1PD_e2ap_RICactionDefinition (pctxt, &pvalue->ricActionDefinition);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ricActionExecutionOrder */
   RTXCTXTPUSHELEMNAME(pctxt, "ricActionExecutionOrder");
      stat = asn1PD_e2ap_RICactionExecutionOrder (pctxt, &pvalue->ricActionExecutionOrder);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field ricSubsequentAction */
   RTXCTXTPUSHELEMNAME(pctxt, "ricSubsequentAction");
   if (optbits[0]) {
      pvalue->m_ricSubsequentActionPresent = TRUE;
      stat = asn1PD_e2ap_RICsubsequentAction (pctxt, &pvalue->ricSubsequentAction);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ricSubsequentActionPresent = FALSE;
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

int asn1Init_e2ap_RICaction_ToBeAddedForModification_Item (e2ap_RICaction_ToBeAddedForModification_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_RICactionID (&pvalue->ricActionID);
   asn1Init_e2ap_RICactionType (&pvalue->ricActionType);
   asn1Init_e2ap_RICactionDefinition (&pvalue->ricActionDefinition);
   asn1Init_e2ap_RICactionExecutionOrder (&pvalue->ricActionExecutionOrder);
   asn1Init_e2ap_RICsubsequentAction (&pvalue->ricSubsequentAction);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICaction_ToBeAddedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeAddedForModification_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_RICactionID (pctxt, &pvalue->ricActionID);
   asn1Free_e2ap_RICactionType (pctxt, &pvalue->ricActionType);
   asn1Free_e2ap_RICactionDefinition (pctxt, &pvalue->ricActionDefinition);
   asn1Free_e2ap_RICactionExecutionOrder (pctxt, &pvalue->ricActionExecutionOrder);
   asn1Free_e2ap_RICsubsequentAction (pctxt, &pvalue->ricSubsequentAction);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICaction_ToBeAddedForModification_Item (const char* name, e2ap_RICaction_ToBeAddedForModification_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICactionID ("ricActionID", &pvalue->ricActionID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICactionType ("ricActionType", &pvalue->ricActionType, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICactionDefinition ("ricActionDefinition", &pvalue->ricActionDefinition, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICactionExecutionOrder ("ricActionExecutionOrder", &pvalue->ricActionExecutionOrder, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_RICsubsequentAction ("ricSubsequentAction", &pvalue->ricSubsequentAction, buffer, bufSize) < 0)
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
// --- End of e2ap_RICaction_ToBeAddedForModification_Item.c ---

// --- Begin of e2ap_RICaction_ToBeAddedForModification_ItemIEs.c ---
/* e2ap_RICaction_ToBeAddedForModification_ItemIEs.c */

/*****************************************/
/*           RICaction_ToBeAddedForModification_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_RICaction_ToBeAddedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeAddedForModification_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "RICaction-ToBeAddedForModification-ItemIEs");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_RICaction_ToBeAddedForModification_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_RICaction_ToBeAddedForModification_ItemIEs_.criticality);
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
      case T_E2AP_PDU_Contents_RICaction_ToBeAddedForModification_ItemIEs_RICaction_ToBeAddedForModification_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "RICaction_ToBeAddedForModification_Item");
         stat = asn1PE_e2ap_RICaction_ToBeAddedForModification_Item (pctxt, pvalue->value.u._e2apRICaction_ToBeAddedForModification_ItemIEs_RICaction_ToBeAddedForModification_Item);
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

int asn1PD_e2ap_RICaction_ToBeAddedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeAddedForModification_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_RICaction_ToBeAddedForModification_ItemIEs (e2ap_RICaction_ToBeAddedForModification_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_RICaction_ToBeAddedForModification_ItemIEs));
}

void asn1Free_e2ap_RICaction_ToBeAddedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeAddedForModification_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
// --- End of e2ap_RICaction_ToBeAddedForModification_ItemIEs.c ---

// --- Begin of e2ap_RICactions_ToBeAddedForModification_List.c ---
/*****************************************/
/*           RICactions_ToBeAddedForModification_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_RICactions_ToBeAddedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeAddedForModification_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICaction_ToBeAddedForModification_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICactions-ToBeAddedForModification-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(0), OSUINTCONST(ASN1V_e2ap_maxofRICactionID), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RICaction_ToBeAddedForModification_ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RICaction_ToBeAddedForModification_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RICactions_ToBeAddedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeAddedForModification_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_RICaction_ToBeAddedForModification_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "RICactions-ToBeAddedForModification-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(0), OSUINTCONST(ASN1V_e2ap_maxofRICactionID), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RICaction_ToBeAddedForModification_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RICaction_ToBeAddedForModification_ItemIEs (pdata);

      stat = asn1PD_e2ap_RICaction_ToBeAddedForModification_ItemIEs (pctxt, pdata);
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

void asn1Init_e2ap_RICactions_ToBeAddedForModification_List (e2ap_RICactions_ToBeAddedForModification_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_RICactions_ToBeAddedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeAddedForModification_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RICaction_ToBeAddedForModification_ItemIEs* pdata = (e2ap_RICaction_ToBeAddedForModification_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RICaction_ToBeAddedForModification_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}

#if 0
void asn1Free_e2ap_RICactions_ToBeAddedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeAddedForModification_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_RICaction_ToBeAddedForModification_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_RICaction_ToBeAddedForModification_ItemIEs*)pnode->data;
         asn1Free_e2ap_RICaction_ToBeAddedForModification_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_RICactions_ToBeAddedForModification_List.c ---

/******************************************************************/
/* File .c missing: e2ap_RICsubscriptionModificationRequest_IEs.c */
/******************************************************************/

// --- Begin of e2ap_RICsubscriptionModificationRequest.c ---

/*****************************************/
/*           RICsubscriptionModificationRequest                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICsubscriptionModificationRequest (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICsubscriptionModificationRequest");

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

int asn1PD_e2ap_RICsubscriptionModificationRequest (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "RICsubscriptionModificationRequest");

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

int asn1Init_e2ap_RICsubscriptionModificationRequest (e2ap_RICsubscriptionModificationRequest* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_ProtocolIE_Container (&pvalue->protocolIEs);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICsubscriptionModificationRequest (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_ProtocolIE_Container (pctxt, &pvalue->protocolIEs);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICsubscriptionModificationRequest (const char* name, e2ap_RICsubscriptionModificationRequest* pvalue, char* buffer, OSSIZE bufSize)
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
// --- End of e2ap_RICsubscriptionModificationRequest.c ---

// --- Begin of e2ap_RICsubscriptionModificationRequest_protocolIEs.c ---
/******************************************************/
/*                                                    */
/*    RICsubscriptionModificationRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

EXTERN int asn1PE_e2ap_RICsubscriptionModificationRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEst* pvalue)
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
        stat = asn1PE_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (pctxt, ((e2ap_RICsubscriptionModificationRequest_protocolIEs_element*)pnode->data));
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        xx1++;
        RTXCTXTPOPARRAYELEMNAME(pctxt);
    }

    return (stat);
}

EXTERN int  asn1PD_e2ap_RICsubscriptionModificationRequest_protocolIEs(OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs* pvalue)
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
        e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pdata;
        RTXCTXTPUSHARRAYELEMNAME(pctxt, "SEQUENCE", &pnode, &pdata);

        if(pnode == NULL) return LOG_RTERR(pctxt, RTERR_NOMEM);

        asn1Init_e2ap_RICsubscriptionModificationRequest_protocolIEs_element(pdata);
        rtxDListAppendNode(pvalue, pnode);
       // stat = asn1PD_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (pctxt, pdata);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        RTXCTXTPOPARRAYELEMNAME(pctxt);

    }
    return (stat);
}


int asn1Init_e2ap_RICsubscriptionModificationRequest_protocolIEs(e2ap_RICsubscriptionModificationRequest_protocolIEs* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    rtxDListFastInit (pvalue);
    return 0;
}

void asn1Free_e2ap_RICsubscriptionModificationRequest_protocolIEs(OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs* pvalue)
{
    if(0==pvalue) return;   
    e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pdata;
    OSRTDListNode* pnode=pvalue->head;
    while(0!=pnode){
        pdata = (e2ap_RICsubscriptionModificationRequest_protocolIEs_element*)pnode->data;
       // asn1Free_e2ap_RICsubscriptionModificationRequest_protocolIEs_element(pctxt, pdata);
        pnode = pnode->next;
    }
    rtxDListFreeAll(pctxt, pvalue);
}

// --- End of e2ap_RICsubscriptionModificationRequest_protocolIEs.c ---

// --- Begin of e2ap_RICsubscriptionModificationRequest_protocolIEs_element.c ---
/*****************************************/
/*    RICsubscriptionModificationRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe

EXTERN int asn1PE_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue)
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
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RICrequestID");

                stat = asn1PE_e2ap_RICrequestID (pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RANfunctionID");

                stat = asn1PE_e2ap_RANfunctionID (pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinitionToBeModified:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RICeventTriggerDefinitionToBeModified");

                stat = asn1PE_e2ap_RICeventTriggerDefinition (pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinitionToBeModified);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeRemovedForModification_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RICactionsToBeRemovedForModification-List");

                stat = asn1PE_e2ap_RICactions_ToBeRemovedForModification_List (pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeRemovedForModification_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeModifiedForModification_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RICactionsToBeModifiedForModification-List");

                stat = asn1PE_e2ap_RICactions_ToBeModifiedForModification_List (pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeModifiedForModification_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeAddedForModification_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RICactionsToBeAddedForModification-List");

                stat = asn1PE_e2ap_RICactions_ToBeAddedForModification_List (pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeAddedForModification_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_UNDEF_:
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

EXTERN int  asn1PD_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue){
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
        
            case ASN1V_e2ap_id_RICrequestID:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RICrequestID");
            pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID 
                = rtxMemAllocType(pctxt, e2ap_RICrequestID);

            asn1Init_e2ap_RICrequestID(pvalue->
                value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID);

            stat = asn1PD_e2ap_RICrequestID (pctxt,
                (e2ap_RICrequestID*)pvalue->value.
                u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_RANfunctionID:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RANfunctionID");
            pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID 
                = rtxMemAllocType(pctxt, e2ap_RANfunctionID);

            asn1Init_e2ap_RANfunctionID(pvalue->
                value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID);

            stat = asn1PD_e2ap_RANfunctionID (pctxt,
                (e2ap_RANfunctionID*)pvalue->value.
                u._e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_RICeventTriggerDefinitionToBeModified:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinition;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RICeventTriggerDefinitionToBeModified");
            pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinition 
                = rtxMemAllocType(pctxt, e2ap_RICeventTriggerDefinition);

            asn1Init_e2ap_RICeventTriggerDefinition(pvalue->
                value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinition);

            stat = asn1PD_e2ap_RICeventTriggerDefinition (pctxt,
                (e2ap_RICeventTriggerDefinition*)pvalue->value.
                u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinition);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_RICactionsToBeRemovedForModification_List:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeRemovedForModification_List;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RICactionsToBeRemovedForModification-List");
            pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeRemovedForModification_List 
                = rtxMemAllocType(pctxt, e2ap_RICactions_ToBeRemovedForModification_List);

            asn1Init_e2ap_RICactions_ToBeRemovedForModification_List(pvalue->
                value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeRemovedForModification_List);

            stat = asn1PD_e2ap_RICactions_ToBeRemovedForModification_List (pctxt,
                (e2ap_RICactions_ToBeRemovedForModification_List*)pvalue->value.
                u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeRemovedForModification_List);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_RICactionsToBeModifiedForModification_List:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeModifiedForModification_List;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RICactionsToBeModifiedForModification-List");
            pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeModifiedForModification_List 
                = rtxMemAllocType(pctxt, e2ap_RICactions_ToBeModifiedForModification_List);

            asn1Init_e2ap_RICactions_ToBeModifiedForModification_List(pvalue->
                value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeModifiedForModification_List);

            stat = asn1PD_e2ap_RICactions_ToBeModifiedForModification_List (pctxt,
                (e2ap_RICactions_ToBeModifiedForModification_List*)pvalue->value.
                u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeModifiedForModification_List);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_RICactionsToBeAddedForModification_List:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeAddedForModification_List;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RICactionsToBeAddedForModification-List");
            pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeAddedForModification_List 
                = rtxMemAllocType(pctxt, e2ap_RICactions_ToBeAddedForModification_List);

            asn1Init_e2ap_RICactions_ToBeAddedForModification_List(pvalue->
                value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeAddedForModification_List);

            stat = asn1PD_e2ap_RICactions_ToBeAddedForModification_List (pctxt,
                (e2ap_RICactions_ToBeAddedForModification_List*)pvalue->value.
                u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeAddedForModification_List);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    

        default:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_UNDEF_;
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


int asn1Init_e2ap_RICsubscriptionModificationRequest_protocolIEs_element(e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    OSCRTLMEMSET (&pvalue->value, 0, sizeof(pvalue->value));
    return 0;
}


//-----> chuaw có template rtxFreeASN1OpenType
#if 0
void asn1Free_e2ap_RICsubscriptionModificationRequest_protocolIEs_element(OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue)
{
    if(NULL==pvalue) return;
    switch(pvalue->value.t){
        case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID:
            // rtxFreeE2ap_RICrequestID(pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID);

            if(pvalue->value.i._e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID!=NULL){
            asn1Free_e2ap_RICrequestID(pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID);
            pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID:
            // rtxFreeE2ap_RANfunctionID(pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID);

            if(pvalue->value.i._e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID!=NULL){
            asn1Free_e2ap_RANfunctionID(pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID);
            pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinition:
            // rtxFreeE2ap_RICeventTriggerDefinition(pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinition);

            if(pvalue->value.i._e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinition!=NULL){
            asn1Free_e2ap_RICeventTriggerDefinition(pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinition);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinition);
            pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinition = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeRemovedForModification_List:
            // rtxFreeE2ap_RICactions_ToBeRemovedForModification_List(pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeRemovedForModification_List);

            if(pvalue->value.i._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeRemovedForModification_List!=NULL){
            asn1Free_e2ap_RICactions_ToBeRemovedForModification_List(pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeRemovedForModification_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeRemovedForModification_List);
            pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeRemovedForModification_List = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeModifiedForModification_List:
            // rtxFreeE2ap_RICactions_ToBeModifiedForModification_List(pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeModifiedForModification_List);

            if(pvalue->value.i._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeModifiedForModification_List!=NULL){
            asn1Free_e2ap_RICactions_ToBeModifiedForModification_List(pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeModifiedForModification_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeModifiedForModification_List);
            pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeModifiedForModification_List = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeAddedForModification_List:
            // rtxFreeE2ap_RICactions_ToBeAddedForModification_List(pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeAddedForModification_List);

            if(pvalue->value.i._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeAddedForModification_List!=NULL){
            asn1Free_e2ap_RICactions_ToBeAddedForModification_List(pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeAddedForModification_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeAddedForModification_List);
            pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeAddedForModification_List = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_UNDEF_:
            rtxFreeASN1OpenType(pvalue->value.u.extElem1);
            break;
        default:
            break;
    }
}

int asn1PrtToStr_e2ap_RICsubscriptionModificationRequest_protocolIEs_element(OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue)
{
    int stat =0;
    RTXCTXTPUSHELEMNAME(pctxt, "e2ap_RICsubscriptionModificationRequest_protocolIEs_element");

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
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RICrequestID");

                stat = asn1PrtToStr_e2ap_RICrequestID (pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RANfunctionID");

                stat = asn1PrtToStr_e2ap_RANfunctionID (pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinition:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RICeventTriggerDefinition");

                stat = asn1PrtToStr_e2ap_RICeventTriggerDefinition (pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinition);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeRemovedForModification_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RICactions-ToBeRemovedForModification-List");

                stat = asn1PrtToStr_e2ap_RICactions_ToBeRemovedForModification_List (pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeRemovedForModification_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeModifiedForModification_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RICactions-ToBeModifiedForModification-List");

                stat = asn1PrtToStr_e2ap_RICactions_ToBeModifiedForModification_List (pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeModifiedForModification_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeAddedForModification_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RICactions-ToBeAddedForModification-List");

                stat = asn1PrtToStr_e2ap_RICactions_ToBeAddedForModification_List (pctxt, pvalue->value.u._e2ap_RICsubscriptionModificationRequest_IEs_id_RICactions_ToBeAddedForModification_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_UNDEF_:
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
// --- End of e2ap_RICsubscriptionModificationRequest_protocolIEs_element.c ---

