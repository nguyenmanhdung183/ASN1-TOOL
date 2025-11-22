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

/************************************************************/
/* File .c missing: e2ap_RICsubscriptionDeleteRequest_IEs.c */
/************************************************************/

// --- Begin of e2ap_RICsubscriptionDeleteRequest.c ---

/*****************************************/
/*           RICsubscriptionDeleteRequest                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_RICsubscriptionDeleteRequest (OSCTXT* pctxt, e2ap_RICsubscriptionDeleteRequest* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "RICsubscriptionDeleteRequest");

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

int asn1PD_e2ap_RICsubscriptionDeleteRequest (OSCTXT* pctxt, e2ap_RICsubscriptionDeleteRequest* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "RICsubscriptionDeleteRequest");

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

int asn1Init_e2ap_RICsubscriptionDeleteRequest (e2ap_RICsubscriptionDeleteRequest* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_ProtocolIE_Container (&pvalue->protocolIEs);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_RICsubscriptionDeleteRequest (OSCTXT* pctxt, e2ap_RICsubscriptionDeleteRequest* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_ProtocolIE_Container (pctxt, &pvalue->protocolIEs);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_RICsubscriptionDeleteRequest (const char* name, e2ap_RICsubscriptionDeleteRequest* pvalue, char* buffer, OSSIZE bufSize)
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
// --- End of e2ap_RICsubscriptionDeleteRequest.c ---

// --- Begin of e2ap_RICsubscriptionDeleteRequest_protocolIEs.c ---
/******************************************************/
/*                                                    */
/*    RICsubscriptionDeleteRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

EXTERN int asn1PE_e2ap_RICsubscriptionDeleteRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionDeleteRequest_protocolIEst* pvalue)
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
        stat = asn1PE_e2ap_RICsubscriptionDeleteRequest_protocolIEs_element (pctxt, ((e2ap_RICsubscriptionDeleteRequest_protocolIEs_element*)pnode->data));
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        xx1++;
        RTXCTXTPOPARRAYELEMNAME(pctxt);
    }

    return (stat);
}

EXTERN int  asn1PD_e2ap_RICsubscriptionDeleteRequest_protocolIEs(OSCTXT* pctxt, e2ap_RICsubscriptionDeleteRequest_protocolIEs* pvalue)
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
        e2ap_RICsubscriptionDeleteRequest_protocolIEs_element* pdata;
        RTXCTXTPUSHARRAYELEMNAME(pctxt, "SEQUENCE", &pnode, &pdata);

        if(pnode == NULL) return LOG_RTERR(pctxt, RTERR_NOMEM);

        asn1Init_e2ap_RICsubscriptionDeleteRequest_protocolIEs_element(pdata);
        rtxDListAppendNode(pvalue, pnode);
       // stat = asn1PD_e2ap_RICsubscriptionDeleteRequest_protocolIEs_element (pctxt, pdata);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        RTXCTXTPOPARRAYELEMNAME(pctxt);

    }
    return (stat);
}


int asn1Init_e2ap_RICsubscriptionDeleteRequest_protocolIEs(e2ap_RICsubscriptionDeleteRequest_protocolIEs* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    rtxDListFastInit (pvalue);
    return 0;
}

void asn1Free_e2ap_RICsubscriptionDeleteRequest_protocolIEs(OSCTXT* pctxt, e2ap_RICsubscriptionDeleteRequest_protocolIEs* pvalue)
{
    if(0==pvalue) return;   
    e2ap_RICsubscriptionDeleteRequest_protocolIEs_element* pdata;
    OSRTDListNode* pnode=pvalue->head;
    while(0!=pnode){
        pdata = (e2ap_RICsubscriptionDeleteRequest_protocolIEs_element*)pnode->data;
       // asn1Free_e2ap_RICsubscriptionDeleteRequest_protocolIEs_element(pctxt, pdata);
        pnode = pnode->next;
    }
    rtxDListFreeAll(pctxt, pvalue);
}

// --- End of e2ap_RICsubscriptionDeleteRequest_protocolIEs.c ---

// --- Begin of e2ap_RICsubscriptionDeleteRequest_protocolIEs_element.c ---
/*****************************************/
/*    RICsubscriptionDeleteRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe

EXTERN int asn1PE_e2ap_RICsubscriptionDeleteRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionDeleteRequest_protocolIEs_element* pvalue)
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
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RICrequestID");

                stat = asn1PE_e2ap_RICrequestID (pctxt, pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-RANfunctionID");

                stat = asn1PE_e2ap_RANfunctionID (pctxt, pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionDeleteRequest_IEs_UNDEF_:
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

EXTERN int  asn1PD_e2ap_RICsubscriptionDeleteRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionDeleteRequest_protocolIEs_element* pvalue){
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
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RICrequestID");
            pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID 
                = rtxMemAllocType(pctxt, e2ap_RICrequestID);

            asn1Init_e2ap_RICrequestID(pvalue->
                value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID);

            stat = asn1PD_e2ap_RICrequestID (pctxt,
                (e2ap_RICrequestID*)pvalue->value.
                u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_RANfunctionID:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID;
            RTXCTXTPUSHELEMNAME(pctxt, "id-RANfunctionID");
            pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID 
                = rtxMemAllocType(pctxt, e2ap_RANfunctionID);

            asn1Init_e2ap_RANfunctionID(pvalue->
                value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID);

            stat = asn1PD_e2ap_RANfunctionID (pctxt,
                (e2ap_RANfunctionID*)pvalue->value.
                u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    

        default:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_RICsubscriptionDeleteRequest_IEs_UNDEF_;
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


int asn1Init_e2ap_RICsubscriptionDeleteRequest_protocolIEs_element(e2ap_RICsubscriptionDeleteRequest_protocolIEs_element* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    OSCRTLMEMSET (&pvalue->value, 0, sizeof(pvalue->value));
    return 0;
}


//-----> chuaw có template rtxFreeASN1OpenType
#if 0
void asn1Free_e2ap_RICsubscriptionDeleteRequest_protocolIEs_element(OSCTXT* pctxt, e2ap_RICsubscriptionDeleteRequest_protocolIEs_element* pvalue)
{
    if(NULL==pvalue) return;
    switch(pvalue->value.t){
        case T_E2AP_PDU_Contents_e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID:
            // rtxFreeE2ap_RICrequestID(pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID);

            if(pvalue->value.i._e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID!=NULL){
            asn1Free_e2ap_RICrequestID(pctxt, pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID);
            pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID:
            // rtxFreeE2ap_RANfunctionID(pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID);

            if(pvalue->value.i._e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID!=NULL){
            asn1Free_e2ap_RANfunctionID(pctxt, pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID);
            pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_RICsubscriptionDeleteRequest_IEs_UNDEF_:
            rtxFreeASN1OpenType(pvalue->value.u.extElem1);
            break;
        default:
            break;
    }
}

int asn1PrtToStr_e2ap_RICsubscriptionDeleteRequest_protocolIEs_element(OSCTXT* pctxt, e2ap_RICsubscriptionDeleteRequest_protocolIEs_element* pvalue)
{
    int stat =0;
    RTXCTXTPUSHELEMNAME(pctxt, "e2ap_RICsubscriptionDeleteRequest_protocolIEs_element");

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
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RICrequestID");

                stat = asn1PrtToStr_e2ap_RICrequestID (pctxt, pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RICrequestID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RANfunctionID");

                stat = asn1PrtToStr_e2ap_RANfunctionID (pctxt, pvalue->value.u._e2ap_RICsubscriptionDeleteRequest_IEs_id_RANfunctionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_RICsubscriptionDeleteRequest_IEs_UNDEF_:
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
// --- End of e2ap_RICsubscriptionDeleteRequest_protocolIEs_element.c ---

