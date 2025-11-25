// --- Begin of e2ap_TNLinformation.c ---

/*****************************************/
/*           TNLinformation                */
/*****************************************/
//sequence normal


// Các nội dung cần thiết từ template seq_normal.c.j2

    // Nội dung của file .c cho primitive BIT STRING (SIZE(1..160,...))
    /* bitstring intergrate header file */
//metadata.parsed.primitive_id == 2


//mau Transportlayeraddress xn bitstring (a..b,..)

EXTERN int asn1PE_e2ap_TNLinformation_tnlAddress(OSCTXT* pctxt, e2ap_TNLinformation_tnlAddress value){
    int stat =0;
    PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(1), OSUINTCONST(160), OSUINTCONST(0), OSUINT32_MAX);
    stat = pe_BitString (pctxt, OS_MIN(value.numbits, 160), value.data);
    if(stat != 0) return LOG_RTERR (pctxt, stat);
    return stat;
}
EXTERN int asn1PD_e2ap_TNLinformation_tnlAddress(OSCTXT* pctxt, e2ap_TNLinformation_tnlAddress* pvalue){
    int stat =0;
    PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(1), OSUINTCONST(160), OSUINTCONST(0), OSUINT32_MAX);
    stat =  pd_DynBitString (pctxt, pvalue);
    if(stat != 0) return LOG_RTERR (pctxt, stat);
    return stat;
}
//EXTERN int asn1PrtToStr_e2ap_TNLinformation_tnlAddress (const char* name, e2ap_TNLinformation_tnlAddress *pvalue, char* buffer, OSSIZE bufSize);
//EXTERN int asn1PrtToStrm_e2ap_TNLinformation_tnlAddress (OSCTXT* pctxt, const char* name, const e2ap_TNLinformation_tnlAddress* pvalue);
//EXTERN int asn1Copy_e2ap_TNLinformation_tnlAddress(OSCTXT* pctxt,const e2ap_TNLinformation_tnlAddress* pSrcValue,  e2ap_TNLinformation_tnlAddress* pDstValue);
EXTERN int asn1Init_e2ap_TNLinformation_tnlAddress(e2ap_TNLinformation_tnlAddress* pvalue){
    if(0==pvalue) return RTERR_NULLPTR;
    pvalue->numbits=0;
    pvalue->data =0;
    return 0;
}
EXTERN void asn1Free_e2ap_TNLinformation_tnlAddress(OSCTXT* pctxt, e2ap_TNLinformation_tnlAddress* pvalue){
    if(0==pvalue) return;   
    if(pvalue->numbits >0){
        rtFreeBitStr(pctxt, (void*)pvalue->data);
        pvalue->data =0;
        pvalue->numbits=0;
    }
}


    // Nội dung của file .c cho primitive BIT STRING (SIZE(16))
    /* bitstring intergrate header file */
//metadata.parsed.primitive_id == 3

//mau rnti_full ben xn  bitstring (n)

EXTERN int asn1PE_e2ap_TNLinformation_tnlPort(OSCTXT* pctxt, e2ap_TNLinformation_tnlPort* pvalue){
    int stat =0;
    PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(16), OSUINTCONST(16), 0, 0);
    stat = pe_BitString (pctxt, OS_MIN(pvalue->numbits, 16), pvalue->data);
    if(stat != 0) return LOG_RTERR (pctxt, stat);
    return stat;
}
EXTERN int asn1PD_e2ap_TNLinformation_tnlPort(OSCTXT* pctxt, e2ap_TNLinformation_tnlPort* pvalue){
    int stat =0;
    PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(16), OSUINTCONST(16), 0, 0);
    stat = pd_BitString (pctxt, &pvalue->numbits, pvalue->data, sizeof(pvalue->data));
    if(stat != 0) return LOG_RTERR (pctxt, stat);
    return stat;
}
//EXTERN int asn1PrtToStr_e2ap_TNLinformation_tnlPort (const char* name, e2ap_TNLinformation_tnlPort* pvalue, char* buffer, OSSIZE bufSize);
//EXTERN int asn1PrtToStrm_e2ap_TNLinformation_tnlPort (OSCTXT* pctxt, const char* name, const e2ap_TNLinformation_tnlPort* pvalue);
//EXTERN int asn1Copy_e2ap_TNLinformation_tnlPort(OSCTXT* pctxt,const e2ap_TNLinformation_tnlPort* pSrcValue,  e2ap_TNLinformation_tnlPort* pDstValue);
EXTERN int asn1Init_e2ap_TNLinformation_tnlPort(e2ap_TNLinformation_tnlPort* pvalue){
    if(0==pvalue) return RTERR_NULLPTR;
    pvalue->numbits=0;
    return 0;
}




// Các phần còn lại của template seq_normal.c.j2


//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "TNLinformation");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field tnlAddress */  

   RTXCTXTPUSHELEMNAME(pctxt, "tnlAddress");
   stat = asn1PE_e2ap_TNLinformation_tnlAddress(pctxt, &pvalue->tnlAddress); //primitive
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field tnlPort */  
   if (pvalue->m_tnlPortPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "tnlPort");
   stat = asn1PE_e2ap_TNLinformation_tnlPort(pctxt, &pvalue->tnlPort); //primitive
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

int asn1PD_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "TNLinformation");

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
   /* decode field tnlAddress */
   RTXCTXTPUSHELEMNAME(pctxt, "tnlAddress");
      stat = asn1PD_e2ap_TNLinformation_tnlAddress (pctxt, &pvalue->tnlAddress); //primitive
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field tnlPort */
   RTXCTXTPUSHELEMNAME(pctxt, "tnlPort");
   if (optbits[0]) {
      pvalue->m_tnlPortPresent = TRUE;
      stat = asn1PD_e2ap_TNLinformation_tnlPort (pctxt, &pvalue->tnlPort); //primitive
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_tnlPortPresent = FALSE;
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

int asn1Init_e2ap_TNLinformation (e2ap_TNLinformation* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_TNLinformation_tnlAddress (&pvalue->tnlAddress); //primitive delete &
   asn1Init_e2ap_TNLinformation_tnlPort (&pvalue->tnlPort); //primitive delete &
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_TNLinformation_tnlAddress (pctxt, &pvalue->tnlAasn1Free_e2ap_TNLinformation_tnlAddressddress); //primitive delete &
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_TNLinformation (const char* name, e2ap_TNLinformation* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
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
// --- End of e2ap_TNLinformation.c ---

// --- Begin of e2ap_TNLusage.c ---
/******************************************************/
/*                                                    */
/*    TNLusage                          */
/*                                                    */
/******************************************************/
//enumerated


const OSEnumItem e2ap_TNLusage_ENUMTAB[] = {
    { OSUTF8("ric_service"), 0, 11, 0 },
    { OSUTF8("support_function"), 1, 16, 1 },
    { OSUTF8("both"), 2, 4, 2 }
};


const OSUTF8CHAR* e2ap_TNLusage_ToString (OSUINT32 value){
   OSINT32 idx = value;
   if(idx >=0 && idx < e2ap_TNLusage_ENUMTABSIZE){
      return e2ap_TNLusage_ENUMTAB[e2ap_TNLusage_ENUMTAB[idx].transidx].name;
   }else{
      return OSUTF8("_UNKNOWN_");
   }
}


int e2ap_TNLusage_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_TNLusage* pvalue)
{
   OSSIZE valueLen = rtxUTF8LenBytes(value);
   return e2ap_TNLusage_ToEnum2 (pctxt, value, valueLen, pvalue);
}

int e2ap_TNLusage_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_TNLusage* pvalue)
{
   OSINT32 idx = rtxLookupEnum(value, valueLen,
      e2ap_TNLusage_ENUMTAB, e2ap_TNLusage_ENUMTABSIZE);
   if (idx >= 0) {
      *pvalue = (e2ap_TNLusage)e2ap_TNLusage_ENUMTAB[idx].value;
      return 0;
   } else {
      rtxErrAddIntParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

EXTERN int asn1PE_e2ap_TNLusage (OSCTXT* pctxt, e2ap_TNLusage value)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "TNLusage");
   if (value >= 3) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_TNLusage (OSCTXT* pctxt, e2ap_TNLusage* pvalue)
{
   int stat = 0;

   RTXCTXTPUSHTYPENAME (pctxt, "TNLusage");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(2));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXTPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_TNLusage (const char* name, e2ap_TNLusage* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIndent(buffer, bufSize) < 0) return -1;
   if(rtPrintToString(name, buffer, bufSize) < 0) return -1;

   switch(*pvalue) {
      case 0:
         stat = rtPrintToString(" = ric_service", buffer, bufSize);
         break;
      case 1:
         stat = rtPrintToString(" = support_function", buffer, bufSize);
         break;
      case 2:
         stat = rtPrintToString(" = both", buffer, bufSize);
         break;
      default:
         stat = rtPrintToString(" = ???\n", buffer, bufSize);
   }

   if (stat < 0) return -1;
   return 0;

}
// --- End of e2ap_TNLusage.c ---

// --- Begin of e2ap_E2connectionUpdate_Item.c ---

/*****************************************/
/*           E2connectionUpdate-Item                */
/*****************************************/
//sequence normal


// Các nội dung cần thiết từ template seq_normal.c.j2


// Các phần còn lại của template seq_normal.c.j2


//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2connectionUpdate_Item (OSCTXT* pctxt, e2ap_E2connectionUpdate_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2connectionUpdate-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field tnlInformation */  

   RTXCTXTPUSHELEMNAME(pctxt, "tnlInformation");
   stat = asn1PE_e2ap_TNLinformation (pctxt, pvalue->tnlInformation);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);


   /* encode field tnlUsage */  

   RTXCTXTPUSHELEMNAME(pctxt, "tnlUsage");
   stat = asn1PE_e2ap_TNLusage (pctxt, pvalue->tnlUsage);
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

int asn1PD_e2ap_E2connectionUpdate_Item (OSCTXT* pctxt, e2ap_E2connectionUpdate_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[2];

   RTXCTXTPUSHTYPENAME(pctxt, "E2connectionUpdate-Item");

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
   /* decode field tnlInformation */
   RTXCTXTPUSHELEMNAME(pctxt, "tnlInformation");
      stat = asn1PD_e2ap_TNLinformation (pctxt, &pvalue->tnlInformation);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /* decode field tnlUsage */
   RTXCTXTPUSHELEMNAME(pctxt, "tnlUsage");
      stat = asn1PD_e2ap_TNLusage (pctxt, &pvalue->tnlUsage);
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

int asn1Init_e2ap_E2connectionUpdate_Item (e2ap_E2connectionUpdate_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_TNLinformation (&pvalue->tnlInformation);
   asn1Init_e2ap_TNLusage (&pvalue->tnlUsage);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2connectionUpdate_Item (OSCTXT* pctxt, e2ap_E2connectionUpdate_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_TNLinformation (pctxt, &pvalue->tnlInformation);
   asn1Free_e2ap_TNLusage (pctxt, &pvalue->tnlUsage);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2connectionUpdate_Item (const char* name, e2ap_E2connectionUpdate_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_TNLinformation ("tnlInformation", &pvalue->tnlInformation, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_TNLusage ("tnlUsage", &pvalue->tnlUsage, buffer, bufSize) < 0)
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
// --- End of e2ap_E2connectionUpdate_Item.c ---

// --- Begin of e2ap_E2connectionUpdate_ItemIEs.c ---
/* e2ap_E2connectionUpdate_ItemIEs.c */

/*****************************************/
/*           E2connectionUpdate_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_E2connectionUpdate_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate_ItemIEs* pvalue)
{
   int stat = 0;
   //RTXCTXTPUSHTYPENAME (pctxt, "E2connectionUpdate-ItemIEs");

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
      case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_E2connectionUpdate_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "_e2ap_E2connectionUpdate_ItemIEs_id_E2connectionUpdate_Item");
         stat = asn1PE_e2ap_E2connectionUpdate_Item (pctxt, pvalue->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item);
         RTXCTXTPOPELEMNAME (pctxt);
      
         break;

      case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_UNDEF_:
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
         openType.numocts = (OSUINT32) pe_GetMsgLen (pctxt);
         openType.data = pDynamicEncodeBuffer = pctxt->buffer.data;
      }
      rtxCopyContext (pctxt, &ictxt);
      if(stat ==0) stat = pe_OpenType(pctxt, openType.numocts, openType.data);
      /*free dynamic encode buffer*/
      if(encoded){
          rtxFreeContextBuffer(pctxt);
      }
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);
   //RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2connectionUpdate_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate_ItemIEs* pvalue)
{
   int stat =0;
   /*deode root element id*/
   RTXCTXTPUSHELEMNAME(pctxt, "id");
   stat = asn1PD_e2ap_ProtocolIE_ID (pctxt, &pvalue->id);
   if(stat!=0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /*decode root element criticality*/
   RTXCTXTPUSHELEMNAME(pctxt, "criticality");
   stat = asn1PD_e2ap_Criticality (pctxt, &pvalue->criticality);
   if(stat!=0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);
   /*decode root element value*/
   RTXCTXTPUSHELEMNAME(pctxt, "value");
   {
      OSUINT32 openTypeLen;
      size_t bitStartOffset, bitLength;
      stat = pd_UnconsLength(pctxt, &openTypeLen);
      if(stat <0) return LOG_RTERR(pctxt, stat);
      else if(stat == RT_OK_FRAG){
         rtxErrAddStrParam(pctxt, "open type with fragmented length use - perindef");
         return LOG_RTERRNEW(pctxt, RTERR_NOTSUPP);
      }
      bitStartOffset = PU_GETCTXTBITOFFSET(pctxt);
      bitLength = openTypeLen * 8;
      switch (pvalue->id){
         case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_E2connectionUpdate_Item:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_E2connectionUpdate_Item;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2connectionUpdate-Item");
            //pvalue->value.u._e2ap_E2connectionUpdate_ItemIEs_id_E2connectionUpdate_Item 
             pvalue->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item = rtxMemAllocType(pctxt, e2ap_E2connectionUpdate_Item);
            //asn1Init_e2ap_E2connectionUpdate_Item(pvalue->value.u._e2ap_E2connectionUpdate_ItemIEs_id_E2connectionUpdate_Item);
                 asn1Init_e2ap_E2connectionUpdate_Item(pvalue->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item);
            stat = asn1PD_e2ap_E2connectionUpdate_Item (pctxt,
                (e2ap_E2connectionUpdate_Item*)pvalue->value.
                u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;

        default:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_UNDEF_;
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
      size_t bitsConsumed = bitEndOffset - bitStartOffset;
      if(bitsConsumed < bitLength){
         stat = pd_moveBitCursor(pctxt, (int)(bitLength - bitsConsumed));
      } else {
         stat = (bitsConsumed > bitLength) ? ASN_E_INVLEN : 0;
      }
      }
   }
   if(stat!=0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);
   return stat;
}

void asn1Init_e2ap_E2connectionUpdate_ItemIEs (e2ap_E2connectionUpdate_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_E2connectionUpdate_ItemIEs));
}

#if 0
void asn1Free_e2ap_E2connectionUpdate_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
#endif
void asn1Free_e2ap_E2connectionUpdate_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate_ItemIEs* pvalue)
{
   if(0==pvalue) return;
   switch(pvalue->value.t){
      case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_E2connectionUpdate_Item:
         asn1Free_e2ap_E2connectionUpdate_Item (pctxt, pvalue->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item);
         rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item);
         pvalue->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item = 0;
         break;
      case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_UNDEF_:
         if(0!=pvalue->value.u.extElem1){
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1->data);
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1);
             pvalue->value.u.extElem1 =0;
         }
         break;
         default:;
   }
}
// --- End of e2ap_E2connectionUpdate_ItemIEs.c ---

// --- Begin of e2ap_E2connectionUpdate_List.c ---
/*****************************************/
/*           E2connectionUpdate_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2connectionUpdate_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "E2connectionUpdate-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(32), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_E2connectionUpdate_ItemIEs*) pnode->data;
      RTXCTXTPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_E2connectionUpdate_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXTPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2connectionUpdate_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "E2connectionUpdate-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(32), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXTPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_E2connectionUpdate_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);
      asn1Init_e2ap_E2connectionUpdate_ItemIEs (pdata);
      stat = asn1PD_e2ap_E2connectionUpdate_ItemIEs (pctxt, pdata);
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

void asn1Init_e2ap_E2connectionUpdate_List (e2ap_E2connectionUpdate_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_E2connectionUpdate_ItemIEs* pdata = (e2ap_E2connectionUpdate_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_E2connectionUpdate_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
      rtxDListFreeAll(pctxt, pvalue);
}

#if 0
void asn1Free_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_E2connectionUpdate_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_E2connectionUpdate_ItemIEs*)pnode->data;
         asn1Free_e2ap_E2connectionUpdate_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_E2connectionUpdate_List.c ---

// --- Begin of e2ap_E2connectionUpdateRemove_Item.c ---

/*****************************************/
/*           E2connectionUpdateRemove-Item                */
/*****************************************/
//sequence normal


// Các nội dung cần thiết từ template seq_normal.c.j2


// Các phần còn lại của template seq_normal.c.j2


//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2connectionUpdateRemove_Item (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2connectionUpdateRemove-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field tnlInformation */  

   RTXCTXTPUSHELEMNAME(pctxt, "tnlInformation");
   stat = asn1PE_e2ap_TNLinformation (pctxt, &pvalue->tnlInformation);//--> fix here
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

int asn1PD_e2ap_E2connectionUpdateRemove_Item (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "E2connectionUpdateRemove-Item");

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
   /* decode field tnlInformation */
   RTXCTXTPUSHELEMNAME(pctxt, "tnlInformation");
      stat = asn1PD_e2ap_TNLinformation (pctxt, &pvalue->tnlInformation);
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

int asn1Init_e2ap_E2connectionUpdateRemove_Item (e2ap_E2connectionUpdateRemove_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_TNLinformation (&pvalue->tnlInformation);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2connectionUpdateRemove_Item (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_TNLinformation (pctxt, &pvalue->tnlInformation);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2connectionUpdateRemove_Item (const char* name, e2ap_E2connectionUpdateRemove_Item* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_TNLinformation ("tnlInformation", &pvalue->tnlInformation, buffer, bufSize) < 0)
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
// --- End of e2ap_E2connectionUpdateRemove_Item.c ---

// --- Begin of e2ap_E2connectionUpdateRemove_ItemIEs.c ---
/* e2ap_E2connectionUpdateRemove_ItemIEs.c */

/*****************************************/
/*           E2connectionUpdateRemove_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_E2connectionUpdateRemove_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_ItemIEs* pvalue)
{
   int stat = 0;
   //RTXCTXTPUSHTYPENAME (pctxt, "E2connectionUpdateRemove-ItemIEs");

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
      case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item:
         
         RTXCTXTPUSHELEMNAME (pctxt, "_e2ap_E2connectionUpdateRemove_ItemIEs_id_E2connectionUpdateRemove_Item");
         stat = asn1PE_e2ap_E2connectionUpdateRemove_Item (pctxt, pvalue->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item);
         RTXCTXTPOPELEMNAME (pctxt);
      
         break;

      case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_UNDEF_:
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
         openType.numocts = (OSUINT32) pe_GetMsgLen (pctxt);
         openType.data = pDynamicEncodeBuffer = pctxt->buffer.data;
      }
      rtxCopyContext (pctxt, &ictxt);
      if(stat ==0) stat = pe_OpenType(pctxt, openType.numocts, openType.data);
      /*free dynamic encode buffer*/
      if(encoded){
          rtxFreeContextBuffer(pctxt);
      }
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);
   //RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2connectionUpdateRemove_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_ItemIEs* pvalue)
{
   int stat =0;
   /*deode root element id*/
   RTXCTXTPUSHELEMNAME(pctxt, "id");
   stat = asn1PD_e2ap_ProtocolIE_ID (pctxt, &pvalue->id);
   if(stat!=0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);

   /*decode root element criticality*/
   RTXCTXTPUSHELEMNAME(pctxt, "criticality");
   stat = asn1PD_e2ap_Criticality (pctxt, &pvalue->criticality);
   if(stat!=0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);
   /*decode root element value*/
   RTXCTXTPUSHELEMNAME(pctxt, "value");
   {
      OSUINT32 openTypeLen;
      size_t bitStartOffset, bitLength;
      stat = pd_UnconsLength(pctxt, &openTypeLen);
      if(stat <0) return LOG_RTERR(pctxt, stat);
      else if(stat == RT_OK_FRAG){
         rtxErrAddStrParam(pctxt, "open type with fragmented length use - perindef");
         return LOG_RTERRNEW(pctxt, RTERR_NOTSUPP);
      }
      bitStartOffset = PU_GETCTXTBITOFFSET(pctxt);
      bitLength = openTypeLen * 8;
      switch (pvalue->id){
         case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_E2connectionUpdate_Item:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2connectionUpdateRemove-Item");
            //pvalue->value.u._e2ap_E2connectionUpdateRemove_ItemIEs_id_E2connectionUpdateRemove_Item 
             pvalue->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item = rtxMemAllocType(pctxt, e2ap_E2connectionUpdateRemove_Item);
            //asn1Init_e2ap_E2connectionUpdateRemove_Item(pvalue->value.u._e2ap_E2connectionUpdateRemove_ItemIEs_id_E2connectionUpdateRemove_Item);
                 asn1Init_e2ap_E2connectionUpdateRemove_Item(pvalue->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item);
            stat = asn1PD_e2ap_E2connectionUpdateRemove_Item (pctxt,
                (e2ap_E2connectionUpdateRemove_Item*)pvalue->value.
                u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;

        default:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_UNDEF_;
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
      size_t bitsConsumed = bitEndOffset - bitStartOffset;
      if(bitsConsumed < bitLength){
         stat = pd_moveBitCursor(pctxt, (int)(bitLength - bitsConsumed));
      } else {
         stat = (bitsConsumed > bitLength) ? ASN_E_INVLEN : 0;
      }
      }
   }
   if(stat!=0) return LOG_RTERR(pctxt, stat);
   RTXCTXTPOPELEMNAME(pctxt);
   return stat;
}

void asn1Init_e2ap_E2connectionUpdateRemove_ItemIEs (e2ap_E2connectionUpdateRemove_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_E2connectionUpdateRemove_ItemIEs));
}

#if 0
void asn1Free_e2ap_E2connectionUpdateRemove_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
#endif
void asn1Free_e2ap_E2connectionUpdateRemove_ItemIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_ItemIEs* pvalue)
{
   if(0==pvalue) return;
   switch(pvalue->value.t){
      case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item:
         asn1Free_e2ap_E2connectionUpdateRemove_Item (pctxt, pvalue->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item);
         rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item);
         pvalue->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item = 0;
         break;
      case T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_UNDEF_:
         if(0!=pvalue->value.u.extElem1){
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1->data);
             rtxMemFreePtr(pctxt, pvalue->value.u.extElem1);
             pvalue->value.u.extElem1 =0;
         }
         break;
         default:;
   }
}
// --- End of e2ap_E2connectionUpdateRemove_ItemIEs.c ---

// --- Begin of e2ap_E2connectionUpdateRemove_List.c ---
/*****************************************/
/*           E2connectionUpdateRemove_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_E2connectionUpdateRemove_List (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2connectionUpdateRemove_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "E2connectionUpdateRemove-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(32), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_E2connectionUpdateRemove_ItemIEs*) pnode->data;
      RTXCTXTPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_E2connectionUpdateRemove_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      //xx1++;
      RTXCTXTPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXTPOPTYPENAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2connectionUpdateRemove_List (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2connectionUpdateRemove_ItemIEs* pdata;

   RTXCTXTPUSHTYPENAME (pctxt, "E2connectionUpdateRemove-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(32), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXTPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_E2connectionUpdateRemove_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);
      asn1Init_e2ap_E2connectionUpdateRemove_ItemIEs (pdata);
      stat = asn1PD_e2ap_E2connectionUpdateRemove_ItemIEs (pctxt, pdata);
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

void asn1Init_e2ap_E2connectionUpdateRemove_List (e2ap_E2connectionUpdateRemove_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_E2connectionUpdateRemove_List (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_E2connectionUpdateRemove_ItemIEs* pdata = (e2ap_E2connectionUpdateRemove_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_E2connectionUpdateRemove_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
      rtxDListFreeAll(pctxt, pvalue);
}

#if 0
void asn1Free_e2ap_E2connectionUpdateRemove_List (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_List* pvalue){
   if(0==pvalue ) return;
   {
      e2ap_E2connectionUpdateRemove_ItemIEs * pdata;
      OSRTDListNode *pnode = pvalue->head;
      while(0!=pnode){
         pdata = (e2ap_E2connectionUpdateRemove_ItemIEs*)pnode->data;
         asn1Free_e2ap_E2connectionUpdateRemove_ItemIEs(pctxt, pdata);
         pnode = pnode->next;
      }
      rtxDListFreeAll(pctxt, pvalue);
   }
}
#endif
// --- End of e2ap_E2connectionUpdateRemove_List.c ---

/**************************************************/
/* File .c missing: e2ap_E2connectionUpdate_IEs.c */
/**************************************************/



// --- Begin of e2ap_E2connectionUpdate_protocolIEs_element.c ---
/*****************************************/
/*    E2connectionUpdate_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe

EXTERN int asn1PE_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue)
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
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-TransactionID");

                stat = asn1PE_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-E2connectionUpdateAdd");

                stat = asn1PE_e2ap_E2connectionUpdate_List (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-E2connectionUpdateRemove");

                stat = asn1PE_e2ap_E2connectionUpdateRemove_List (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-E2connectionUpdateModify");

                stat = asn1PE_e2ap_E2connectionUpdate_List (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_UNDEF_:
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

EXTERN int  asn1PD_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue){
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
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID;
            RTXCTXTPUSHELEMNAME(pctxt, "id-TransactionID");
            //pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID 
             pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID = rtxMemAllocType(pctxt, e2ap_TransactionID);
            //asn1Init_e2ap_TransactionID(pvalue->
              //  value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID);

                 asn1Init_e2ap_TransactionID(pvalue->
                value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID);
            stat = asn1PD_e2ap_TransactionID (pctxt,
                (e2ap_TransactionID*)pvalue->value.
                u._e2ap_E2connectionUpdate_IEs_id_TransactionID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_E2connectionUpdateAdd:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2connectionUpdateAdd");
            //pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List 
             pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd = rtxMemAllocType(pctxt, e2ap_E2connectionUpdate_List);
            //asn1Init_e2ap_E2connectionUpdate_List(pvalue->
              //  value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);

                 asn1Init_e2ap_E2connectionUpdate_List(pvalue->
                value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd);
            stat = asn1PD_e2ap_E2connectionUpdate_List (pctxt,
                (e2ap_E2connectionUpdate_List*)pvalue->value.
                u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_E2connectionUpdateRemove:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2connectionUpdateRemove");
            //pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List 
             pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove = rtxMemAllocType(pctxt, e2ap_E2connectionUpdateRemove_List);
            //asn1Init_e2ap_E2connectionUpdateRemove_List(pvalue->
              //  value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List);

                 asn1Init_e2ap_E2connectionUpdateRemove_List(pvalue->
                value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove);
            stat = asn1PD_e2ap_E2connectionUpdateRemove_List (pctxt,
                (e2ap_E2connectionUpdateRemove_List*)pvalue->value.
                u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_E2connectionUpdateModify:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2connectionUpdateModify");
            //pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List 
             pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify = rtxMemAllocType(pctxt, e2ap_E2connectionUpdate_List);
            //asn1Init_e2ap_E2connectionUpdate_List(pvalue->
              //  value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);

                 asn1Init_e2ap_E2connectionUpdate_List(pvalue->
                value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify);
            stat = asn1PD_e2ap_E2connectionUpdate_List (pctxt,
                (e2ap_E2connectionUpdate_List*)pvalue->value.
                u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    

        default:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_UNDEF_;
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


int asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(e2ap_E2connectionUpdate_protocolIEs_element* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    OSCRTLMEMSET (&pvalue->value, 0, sizeof(pvalue->value));
    return 0;
}


//-----> chuaw có template rtxFreeASN1OpenType
#if 0
void asn1Free_e2ap_E2connectionUpdate_protocolIEs_element(OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue)
{
    if(NULL==pvalue) return;
    switch(pvalue->value.t){
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID:
            // rtxFreeE2ap_TransactionID(pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID);

            if(pvalue->value.i._e2ap_E2connectionUpdate_IEs_id_TransactionID!=NULL){
            asn1Free_e2ap_TransactionID(pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID);
           // pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID = NULL;
           pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List:
            // rtxFreeE2ap_E2connectionUpdate_List(pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);

            if(pvalue->value.i._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List!=NULL){
            asn1Free_e2ap_E2connectionUpdate_List(pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
           // pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List = NULL;
           pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List:
            // rtxFreeE2ap_E2connectionUpdateRemove_List(pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List);

            if(pvalue->value.i._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List!=NULL){
            asn1Free_e2ap_E2connectionUpdateRemove_List(pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List);
           // pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List = NULL;
           pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List:
            // rtxFreeE2ap_E2connectionUpdate_List(pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);

            if(pvalue->value.i._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List!=NULL){
            asn1Free_e2ap_E2connectionUpdate_List(pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
           // pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List = NULL;
           pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_UNDEF_:
            rtxFreeASN1OpenType(pvalue->value.u.extElem1);
            break;
        default:
            break;
    }
}

int asn1PrtToStr_e2ap_E2connectionUpdate_protocolIEs_element(OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue)
{
    int stat =0;
    RTXCTXTPUSHELEMNAME(pctxt, "e2ap_E2connectionUpdate_protocolIEs_element");

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
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "TransactionID");

                stat = asn1PrtToStr_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "E2connectionUpdate-List");

                stat = asn1PrtToStr_e2ap_E2connectionUpdate_List (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "E2connectionUpdateRemove-List");

                stat = asn1PrtToStr_e2ap_E2connectionUpdateRemove_List (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "E2connectionUpdate-List");

                stat = asn1PrtToStr_e2ap_E2connectionUpdate_List (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_UNDEF_:
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
// --- End of e2ap_E2connectionUpdate_protocolIEs_element.c ---

// --- Begin of e2ap_E2connectionUpdate_protocolIEs.c ---
/******************************************************/
/*                                                    */
/*    E2connectionUpdate_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

EXTERN int asn1PE_e2ap_E2connectionUpdate_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs* pvalue)
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
        stat = asn1PE_e2ap_E2connectionUpdate_protocolIEs_element (pctxt, ((e2ap_E2connectionUpdate_protocolIEs_element*)pnode->data));
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        xx1++;
        RTXCTXTPOPARRAYELEMNAME(pctxt);
    }

    return (stat);
}

EXTERN int  asn1PD_e2ap_E2connectionUpdate_protocolIEs(OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs* pvalue)
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
        e2ap_E2connectionUpdate_protocolIEs_element* pdata;
        RTXCTXTPUSHARRAYELEMNAME(pctxt, "SEQUENCE",xx1);

        if(pnode == NULL) return LOG_RTERR(pctxt, RTERR_NOMEM);

        asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(pdata);
        rtxDListAppendNode(pvalue, pnode);
       // stat = asn1PD_e2ap_E2connectionUpdate_protocolIEs_element (pctxt, pdata);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        RTXCTXTPOPARRAYELEMNAME(pctxt);

    }
    return (stat);
}


int asn1Init_e2ap_E2connectionUpdate_protocolIEs(e2ap_E2connectionUpdate_protocolIEs* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    rtxDListFastInit (pvalue);
    return 0;
}
#if 1 //ao that day
void asn1Free_e2ap_E2connectionUpdate_protocolIEs(OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs* pvalue)
{
    if(0==pvalue) return;   
    e2ap_E2connectionUpdate_protocolIEs_element* pdata;
    OSRTDListNode* pnode=pvalue->head;
    while(0!=pnode){
        pdata = (e2ap_E2connectionUpdate_protocolIEs_element*)pnode->data;
       // asn1Free_e2ap_E2connectionUpdate_protocolIEs_element(pctxt, pdata);
        pnode = pnode->next;
    }
    rtxDListFreeAll(pctxt, pvalue);
}
#endif


EXTERN int asn1PrtToStr_e2ap_E2connectionUpdate_protocolIEs(const char* name, e2ap_E2connectionUpdate_protocolIEs* pvalue, char* buffer, OSSIZE bufSize)
{
    e2ap_E2connectionUpdate_protocolIEs_element* pdata0;
    OSRTDListNode* pnode0;
    char nameBuf[256];
    char numBuf[32];
    OSUINT32 xx1=0;
    for(pnode0 = pvalue->head;  xx1 < pvalue->count && pnode0 != 0; pnode0 = pnode0->next, xx1++){
        pdata0 = (e2ap_E2connectionUpdate_protocolIEs_element*)pnode0->data;
        rtxUIntToCharStr(xx1, numBuf, sizeof(numBuf), 0);
        rtxStrJoin(nameBuf, sizeof(nameBuf), name, "[", numBuf, "]", 0);
        #if 0
        if(asn1PrtToStr_e2ap_E2connectionUpdate_protocolIEs_element(nameBuf, pdata0, buffer, bufSize) <0){
            return -1;
        }
        #endif
    }
    return 0;
}
// --- End of e2ap_E2connectionUpdate_protocolIEs.c ---

// --- Begin of e2ap_E2connectionUpdate.c ---

/*****************************************/
/*           E2connectionUpdate                */
/*****************************************/
//sequence normal


// Các nội dung cần thiết từ template seq_normal.c.j2


// Các phần còn lại của template seq_normal.c.j2


//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2connectionUpdate (OSCTXT* pctxt, e2ap_E2connectionUpdate* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXTPUSHTYPENAME(pctxt, "E2connectionUpdate");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field protocolIEs */  

   RTXCTXTPUSHELEMNAME(pctxt, "protocolIEs");
   stat = asn1PE_e2ap_E2connectionUpdate_protocolIEs (pctxt, &pvalue->protocolIEs);//-> sua con tro
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

int asn1PD_e2ap_E2connectionUpdate (OSCTXT* pctxt, e2ap_E2connectionUpdate* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXTPUSHTYPENAME(pctxt, "E2connectionUpdate");

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
      stat = asn1PD_e2ap_E2connectionUpdate_protocolIEs (pctxt, &pvalue->protocolIEs);
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

int asn1Init_e2ap_E2connectionUpdate (e2ap_E2connectionUpdate* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_E2connectionUpdate_protocolIEs (&pvalue->protocolIEs);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2connectionUpdate (OSCTXT* pctxt, e2ap_E2connectionUpdate* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_E2connectionUpdate_protocolIEs (pctxt, &pvalue->protocolIEs);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2connectionUpdate (const char* name, e2ap_E2connectionUpdate* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_E2connectionUpdate_protocolIEs ("protocolIEs", &pvalue->protocolIEs, buffer, bufSize) < 0)
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
// --- End of e2ap_E2connectionUpdate.c ---