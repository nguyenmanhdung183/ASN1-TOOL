
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
EXTERN int asn1PrtToStr_e2ap_TNLinformation_tnlAddress (const char* name, e2ap_TNLinformation_tnlAddress *pvalue, char* buffer, OSSIZE bufSize){
    if(rtPrintToStringIndent(buffer, bufSize) < 0) return -1;
    if(rtPrintToStringBitStrBraceText(name, OS_MIN(pvalue->numbits, 160), pvalue->data, buffer, bufSize) < 0) return -1;
    return 0;
}
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
        rtxMemFreePtr(pctxt, (void*)pvalue->data);
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
EXTERN int asn1PrtToStr_e2ap_TNLinformation_tnlPort (const char* name, e2ap_TNLinformation_tnlPort* pvalue, char* buffer, OSSIZE bufSize){
    if(rtPrintToStringIndent(buffer, bufSize) < 0) return -1;
    if(rtPrintToStringBitStrBraceText (name, OS_MIN(pvalue->numbits, 16), pvalue->data, buffer, bufSize) < 0) return -1;
    return 0;
}
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
   stat = asn1PE_e2ap_TNLinformation_tnlAddress(pctxt, pvalue->tnlAddress); //primitive
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
   asn1Free_e2ap_TNLinformation_tnlAddress (pctxt, &pvalue->tnlAddress); //primitive delete &
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_TNLinformation (const char* name, e2ap_TNLinformation* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }

   if(asn1PrtToStr_e2ap_TNLinformation_tnlAddress ("tnlAddress", pvalue->tnlAddress, buffer, bufSize) < 0)
   {
      return -1;
   }


   if(asn1PrtToStr_e2ap_TNLinformation_tnlPort ("tnlPort", pvalue->tnlPort, buffer, bufSize) < 0)
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