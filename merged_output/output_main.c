#include "output_main.h"
// --- Begin of e2ap_TransactionID.c ---
/* e2ap_TransactionID.c */



//interger with ext
/*****************************************/
/*           TransactionID                */
/*****************************************/


EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value)
{ 
   RTXCTXPUSHTYPENAME (pctxt, "TransactionID");

   OSBOOL exbit = (value > 255) ? TRUE : FALSE;
   int stat = rtxEncBit (pctxt, exbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!exbit) {
      stat = pe_ConsUnsigned (pctxt, value, 0, 255);
   } else {
      stat = pe_UnconsUnsigned (pctxt, value);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "TransactionID");
   stat = rtxDecBit (pctxt, &extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!extbit) {
      stat = pd_ConsUnsigned (pctxt, pvalue, 0, 255);
   } else {
      stat = pd_UnconsUnsigned (pctxt, pvalue);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return 0;
}

EXTERN int asn1PrtToStr_e2ap_TransactionID (const char* name, e2ap_TransactionID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_TransactionID.c ---

// --- Begin of e2ap_PLMN_Identity.c ---
/* e2ap_PLMN_Identity.c */


//octet string

/*****************************************/
/*           PLMN_Identity                */
/*****************************************/

/* Fixed SIZE OCTET STRING */
EXTERN int asn1PE_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue)
{
   int stat = 0;
 
   RTXCTXPUSHTYPENAME (pctxt, "PLMN-Identity");
  
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(3), OSUINTCONST(3), 0, 0);
  
   stat = pe_OctetString (pctxt, pvalue->numocts, pvalue->data);

   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue)
{
   int stat = 0;
  
   RTXCTXPUSHTYPENAME (pctxt, "PLMN-Identity");
  
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(3), OSUINTCONST(3), 0, 0);
  
   stat = pd_OctetString (pctxt, &pvalue->numocts, pvalue->data, sizeof(pvalue->data));

   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

int asn1Init_e2ap_PLMN_Identity (e2ap_PLMN_Identity* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->numocts = 0;
   return 0;
}

void asn1Free_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue)
{
   if(0==pvalue) return;
   if(pvalue->numocts > 0){
      rtxMemFreePtr(pctxt, (void*)pvalue->data);
      pvalue->numocts=0;
   }
}

/* Print to string */
int asn1PrtToStr_e2ap_PLMN_Identity (const char* name, e2ap_PLMN_Identity* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) {
      return -1;
   }
   if (rtPrintToStringHexStr (name, pvalue->numocts, pvalue->data, buffer, bufSize) < 0){
      return -1;
   }
   return 0;
}
// --- End of e2ap_PLMN_Identity.c ---

/**********************************/
/* File .c missing: e2ap_gnb_ID.c */
/**********************************/

// --- Begin of e2ap_GNB_ID_Choice.c ---
/* e2ap_GNB_ID_Choice.c */

/*****************************************/
/*           GNB_ID_Choice                */
/*****************************************/
// choice

// choice without extension

EXTERN int asn1PE_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GNB-ID-Choice");
   RTXCTXTPUSHELEMNAME (pctxt, "t");
 
   stat = rtxEncBits (pctxt, pvalue->t - 1, 0);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   switch (pvalue->t) {
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "gnb-ID");

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(22), OSUINTCONST(32), 0, 0);
         stat = pe_BitString32 (pctxt, pvalue->u.gnb_ID, OSUINTCONST(22), OSUINTCONST(32));

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PD_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   RTXCTXPUSHTYPENAME (pctxt, "GNB-ID-Choice");

 
   stat = rtxDecBits (pctxt, &ui, 0);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   else pvalue->t = ui + 1;
   //RTXCTXTPOPELEMNAME (pctxt);

   switch (ui) {
      case 0:
         RTXCTXTPUSHELEMNAME (pctxt, "gnb-ID");

         pvalue->u.gnb_ID = rtxMemAllocType (pctxt, ASN1BitStr32);

         if (pvalue->u.gnb_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(22), OSUINTCONST(32), 0, 0);
         stat = pd_BitString32 (pctxt, pvalue->u.gnb_ID, OSUINTCONST(22), OSUINTCONST(32));
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PrtToStr_e2ap_GNB_ID_Choice (const char* name, e2ap_GNB_ID_Choice* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) return -1;
   

   switch (pvalue->t) {
      case T_e2ap_GNB_ID_Choice_gnb_ID:
         if (asn1PrtToStr_ASN1BitStr32 ( "gnb_ID", pvalue->u.gnb_ID, buffer, bufSize) < 0) return -1;
         break;
      default:
         return RTERR_INVOPT;
   }

   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}

int asn1Init_e2ap_GNB_ID_Choice (e2ap_GNB_ID_Choice* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->t = 0;
   OSRTLMEMSET (&pvalue->u, 0, sizeof(pvalue->u));
   return 0;
}


void asn1Free_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue)
{
   if (pvalue == 0) return;
   switch (pvalue->t) {
      case 0: //no choice nothing to free
         break;
      case 1:
         if (pvalue->u.gnb_ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.gnb_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gnb_ID);
            pvalue->u.gnb_ID = 0;
         }
         break;
   }
}


// --- End of e2ap_GNB_ID_Choice.c ---

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
   RTXCTXPUSHTYPENAME(pctxt, "GlobalgNB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field plmn_id */  

   RTXCTXTPUSHELEMNAME(pctxt, "plmn-id");
   stat = asn1PE_e2ap_PLMN_Identity (pctxt, &pvalue->plmn_id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field gnb_id */  

   RTXCTXTPUSHELEMNAME(pctxt, "gnb-id");
   stat = asn1PE_e2ap_GNB_ID_Choice (pctxt, &pvalue->gnb_id);
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

   RTXCTXPOPTYPENAME(pctxt);
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
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "GlobalgNB-ID");

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
   /* decode field plmn_id */
   RTXCTXTPUSHELEMNAME(pctxt, "plmn-id");
      stat = asn1PD_e2ap_PLMN_Identity (pctxt, &pvalue->plmn_id);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field gnb_id */
   RTXCTXTPUSHELEMNAME(pctxt, "gnb-id");
      stat = asn1PD_e2ap_GNB_ID_Choice (pctxt, &pvalue->gnb_id);
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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

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

/**********************************/
/* File .c missing: e2ap_gNB_ID.c */
/**********************************/

// --- Begin of e2ap_ENGNB_ID.c ---
/* e2ap_ENGNB_ID.c */

/*****************************************/
/*           ENGNB_ID                */
/*****************************************/
// choice

// choice without extension

EXTERN int asn1PE_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "ENGNB-ID");
   RTXCTXTPUSHELEMNAME (pctxt, "t");
 
   stat = rtxEncBits (pctxt, pvalue->t - 1, 0);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   switch (pvalue->t) {
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "gNB-ID");

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(22), OSUINTCONST(32), 0, 0);
         stat = pe_BitString32 (pctxt, pvalue->u.gNB_ID, OSUINTCONST(22), OSUINTCONST(32));

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PD_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   RTXCTXPUSHTYPENAME (pctxt, "ENGNB-ID");

 
   stat = rtxDecBits (pctxt, &ui, 0);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   else pvalue->t = ui + 1;
   //RTXCTXTPOPELEMNAME (pctxt);

   switch (ui) {
      case 0:
         RTXCTXTPUSHELEMNAME (pctxt, "gNB-ID");

         pvalue->u.gNB_ID = rtxMemAllocType (pctxt, ASN1BitStr32);

         if (pvalue->u.gNB_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(22), OSUINTCONST(32), 0, 0);
         stat = pd_BitString32 (pctxt, pvalue->u.gNB_ID, OSUINTCONST(22), OSUINTCONST(32));
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PrtToStr_e2ap_ENGNB_ID (const char* name, e2ap_ENGNB_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) return -1;
   

   switch (pvalue->t) {
      case T_e2ap_ENGNB_ID_gNB_ID:
         if (asn1PrtToStr_ASN1BitStr32 ( "gNB_ID", pvalue->u.gNB_ID, buffer, bufSize) < 0) return -1;
         break;
      default:
         return RTERR_INVOPT;
   }

   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}

int asn1Init_e2ap_ENGNB_ID (e2ap_ENGNB_ID* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->t = 0;
   OSRTLMEMSET (&pvalue->u, 0, sizeof(pvalue->u));
   return 0;
}


void asn1Free_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue)
{
   if (pvalue == 0) return;
   switch (pvalue->t) {
      case 0: //no choice nothing to free
         break;
      case 1:
         if (pvalue->u.gNB_ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.gNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gNB_ID);
            pvalue->u.gNB_ID = 0;
         }
         break;
   }
}


// --- End of e2ap_ENGNB_ID.c ---

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
   RTXCTXPUSHTYPENAME(pctxt, "GlobalenGNB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field pLMN_Identity */  

   RTXCTXTPUSHELEMNAME(pctxt, "pLMN-Identity");
   stat = asn1PE_e2ap_PLMN_Identity (pctxt, &pvalue->pLMN_Identity);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field gNB_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "gNB-ID");
   stat = asn1PE_e2ap_ENGNB_ID (pctxt, &pvalue->gNB_ID);
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

   RTXCTXPOPTYPENAME(pctxt);
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
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "GlobalenGNB-ID");

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
   /* decode field pLMN_Identity */
   RTXCTXTPUSHELEMNAME(pctxt, "pLMN-Identity");
      stat = asn1PD_e2ap_PLMN_Identity (pctxt, &pvalue->pLMN_Identity);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field gNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "gNB-ID");
      stat = asn1PD_e2ap_ENGNB_ID (pctxt, &pvalue->gNB_ID);
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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

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

// --- Begin of e2ap_GNB_CU_UP_ID.c ---
/* e2ap_GNB_CU_UP_ID.c */


//interger no ext
/*****************************************/
/*         GNB-CU-UP-ID     */
/*****************************************/

EXTERN int asn1PE_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GNB-CU-UP-ID");
   stat = pe_ConsUnsigned (pctxt, value, 0, 68719476735);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GNB-CU-UP-ID");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 64);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_GNB_CU_UP_ID (const char* name, e2ap_GNB_CU_UP_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_GNB_CU_UP_ID.c ---

// --- Begin of e2ap_GNB_DU_ID.c ---
/* e2ap_GNB_DU_ID.c */


//interger no ext
/*****************************************/
/*         GNB-DU-ID     */
/*****************************************/

EXTERN int asn1PE_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GNB-DU-ID");
   stat = pe_ConsUnsigned (pctxt, value, 0, 68719476735);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GNB-DU-ID");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 64);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_GNB_DU_ID (const char* name, e2ap_GNB_DU_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_GNB_DU_ID.c ---

// --- Begin of e2ap_GlobalE2node_gNB_ID.c ---

/*****************************************/
/*           GlobalE2node-gNB-ID                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node-gNB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field global_gNB_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "global-gNB-ID");
   stat = asn1PE_e2ap_GlobalgNB_ID (pctxt, &pvalue->global_gNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field global_en_gNB_ID */  
   if (pvalue->m_global_en_gNB_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "global-en-gNB-ID");
   stat = asn1PE_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field gNB_CU_UP_ID */  
   if (pvalue->m_gNB_CU_UP_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "gNB-CU-UP-ID");
   stat = asn1PE_e2ap_GNB_CU_UP_ID (pctxt, &pvalue->gNB_CU_UP_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field gNB_DU_ID */  
   if (pvalue->m_gNB_DU_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "gNB-DU-ID");
   stat = asn1PE_e2ap_GNB_DU_ID (pctxt, &pvalue->gNB_DU_ID);
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

   RTXCTXPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node-gNB-ID");

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
   /* decode field global_gNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-gNB-ID");
      stat = asn1PD_e2ap_GlobalgNB_ID (pctxt, &pvalue->global_gNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field global_en_gNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-en-gNB-ID");
   if (optbits[0]) {
      pvalue->m_global_en_gNB_IDPresent = TRUE;
      stat = asn1PD_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_global_en_gNB_IDPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field gNB_CU_UP_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "gNB-CU-UP-ID");
   if (optbits[0]) {
      pvalue->m_gNB_CU_UP_IDPresent = TRUE;
      stat = asn1PD_e2ap_GNB_CU_UP_ID (pctxt, &pvalue->gNB_CU_UP_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_gNB_CU_UP_IDPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field gNB_DU_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "gNB-DU-ID");
   if (optbits[0]) {
      pvalue->m_gNB_DU_IDPresent = TRUE;
      stat = asn1PD_e2ap_GNB_DU_ID (pctxt, &pvalue->gNB_DU_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_gNB_DU_IDPresent = FALSE;
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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_GlobalE2node_gNB_ID (e2ap_GlobalE2node_gNB_ID* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_GlobalgNB_ID (&pvalue->global_gNB_ID);
   asn1Init_e2ap_GlobalenGNB_ID (&pvalue->global_en_gNB_ID);
   asn1Init_e2ap_GNB_CU_UP_ID (&pvalue->gNB_CU_UP_ID);
   asn1Init_e2ap_GNB_DU_ID (&pvalue->gNB_DU_ID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_GlobalgNB_ID (pctxt, &pvalue->global_gNB_ID);
   asn1Free_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
   asn1Free_e2ap_GNB_CU_UP_ID (pctxt, &pvalue->gNB_CU_UP_ID);
   asn1Free_e2ap_GNB_DU_ID (pctxt, &pvalue->gNB_DU_ID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_GlobalE2node_gNB_ID (const char* name, e2ap_GlobalE2node_gNB_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GlobalgNB_ID ("global_gNB_ID", &pvalue->global_gNB_ID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GlobalenGNB_ID ("global_en_gNB_ID", &pvalue->global_en_gNB_ID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GNB_CU_UP_ID ("gNB_CU_UP_ID", &pvalue->gNB_CU_UP_ID, buffer, bufSize) < 0)
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
// --- End of e2ap_GlobalE2node_gNB_ID.c ---

// --- Begin of e2ap_GlobalE2node_en_gNB_ID.c ---

/*****************************************/
/*           GlobalE2node-en-gNB-ID                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node-en-gNB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field global_en_gNB_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "global-en-gNB-ID");
   stat = asn1PE_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field en_gNB_CU_UP_ID */  
   if (pvalue->m_en_gNB_CU_UP_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "en-gNB-CU-UP-ID");
   stat = asn1PE_e2ap_GNB_CU_UP_ID (pctxt, &pvalue->en_gNB_CU_UP_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field en_gNB_DU_ID */  
   if (pvalue->m_en_gNB_DU_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "en-gNB-DU-ID");
   stat = asn1PE_e2ap_GNB_DU_ID (pctxt, &pvalue->en_gNB_DU_ID);
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

   RTXCTXPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node-en-gNB-ID");

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
   /* decode field global_en_gNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-en-gNB-ID");
      stat = asn1PD_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field en_gNB_CU_UP_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "en-gNB-CU-UP-ID");
   if (optbits[0]) {
      pvalue->m_en_gNB_CU_UP_IDPresent = TRUE;
      stat = asn1PD_e2ap_GNB_CU_UP_ID (pctxt, &pvalue->en_gNB_CU_UP_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_en_gNB_CU_UP_IDPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field en_gNB_DU_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "en-gNB-DU-ID");
   if (optbits[0]) {
      pvalue->m_en_gNB_DU_IDPresent = TRUE;
      stat = asn1PD_e2ap_GNB_DU_ID (pctxt, &pvalue->en_gNB_DU_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_en_gNB_DU_IDPresent = FALSE;
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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_GlobalE2node_en_gNB_ID (e2ap_GlobalE2node_en_gNB_ID* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_GlobalenGNB_ID (&pvalue->global_en_gNB_ID);
   asn1Init_e2ap_GNB_CU_UP_ID (&pvalue->en_gNB_CU_UP_ID);
   asn1Init_e2ap_GNB_DU_ID (&pvalue->en_gNB_DU_ID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
   asn1Free_e2ap_GNB_CU_UP_ID (pctxt, &pvalue->en_gNB_CU_UP_ID);
   asn1Free_e2ap_GNB_DU_ID (pctxt, &pvalue->en_gNB_DU_ID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_GlobalE2node_en_gNB_ID (const char* name, e2ap_GlobalE2node_en_gNB_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GlobalenGNB_ID ("global_en_gNB_ID", &pvalue->global_en_gNB_ID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GNB_CU_UP_ID ("en_gNB_CU_UP_ID", &pvalue->en_gNB_CU_UP_ID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GNB_DU_ID ("en_gNB_DU_ID", &pvalue->en_gNB_DU_ID, buffer, bufSize) < 0)
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
// --- End of e2ap_GlobalE2node_en_gNB_ID.c ---

/****************************************/
/* File .c missing: e2ap_enb_ID_macro.c */
/****************************************/

/*********************************************/
/* File .c missing: e2ap_enb_ID_shortmacro.c */
/*********************************************/

/********************************************/
/* File .c missing: e2ap_enb_ID_longmacro.c */
/********************************************/

// --- Begin of e2ap_ENB_ID_Choice.c ---
/* e2ap_ENB_ID_Choice.c */

/*****************************************/
/*           ENB_ID_Choice                */
/*****************************************/
// choice

// choice without extension

EXTERN int asn1PE_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "ENB-ID-Choice");
   RTXCTXTPUSHELEMNAME (pctxt, "t");
 
   stat = rtxEncBits (pctxt, pvalue->t - 1, 2);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   switch (pvalue->t) {
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "enb-ID-macro");

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(20), OSUINTCONST(20), 0, 0);
         stat = pe_BitString32 (pctxt, pvalue->u.enb_ID_macro, OSUINTCONST(20), OSUINTCONST(20));

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXTPUSHELEMNAME (pctxt, "enb-ID-shortmacro");

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(18), OSUINTCONST(18), 0, 0);
         stat = pe_BitString32 (pctxt, pvalue->u.enb_ID_shortmacro, OSUINTCONST(18), OSUINTCONST(18));

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXTPUSHELEMNAME (pctxt, "enb-ID-longmacro");

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(21), OSUINTCONST(21), 0, 0);
         stat = pe_BitString32 (pctxt, pvalue->u.enb_ID_longmacro, OSUINTCONST(21), OSUINTCONST(21));

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PD_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   RTXCTXPUSHTYPENAME (pctxt, "ENB-ID-Choice");

 
   stat = rtxDecBits (pctxt, &ui, 2);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   else pvalue->t = ui + 1;
   //RTXCTXTPOPELEMNAME (pctxt);

   switch (ui) {
      case 0:
         RTXCTXTPUSHELEMNAME (pctxt, "enb-ID-macro");

         pvalue->u.enb_ID_macro = rtxMemAllocType (pctxt, ASN1BitStr32);

         if (pvalue->u.enb_ID_macro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(20), OSUINTCONST(20), 0, 0);
         stat = pd_BitString32 (pctxt, pvalue->u.enb_ID_macro, OSUINTCONST(20), OSUINTCONST(20));
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "enb-ID-shortmacro");

         pvalue->u.enb_ID_shortmacro = rtxMemAllocType (pctxt, ASN1BitStr32);

         if (pvalue->u.enb_ID_shortmacro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(18), OSUINTCONST(18), 0, 0);
         stat = pd_BitString32 (pctxt, pvalue->u.enb_ID_shortmacro, OSUINTCONST(18), OSUINTCONST(18));
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXTPUSHELEMNAME (pctxt, "enb-ID-longmacro");

         pvalue->u.enb_ID_longmacro = rtxMemAllocType (pctxt, ASN1BitStr32);

         if (pvalue->u.enb_ID_longmacro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(21), OSUINTCONST(21), 0, 0);
         stat = pd_BitString32 (pctxt, pvalue->u.enb_ID_longmacro, OSUINTCONST(21), OSUINTCONST(21));
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PrtToStr_e2ap_ENB_ID_Choice (const char* name, e2ap_ENB_ID_Choice* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) return -1;
   

   switch (pvalue->t) {
      case T_e2ap_ENB_ID_Choice_enb_ID_macro:
         if (asn1PrtToStr_ASN1BitStr32 ( "enb_ID_macro", pvalue->u.enb_ID_macro, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_ENB_ID_Choice_enb_ID_shortmacro:
         if (asn1PrtToStr_ASN1BitStr32 ( "enb_ID_shortmacro", pvalue->u.enb_ID_shortmacro, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_ENB_ID_Choice_enb_ID_longmacro:
         if (asn1PrtToStr_ASN1BitStr32 ( "enb_ID_longmacro", pvalue->u.enb_ID_longmacro, buffer, bufSize) < 0) return -1;
         break;
      default:
         return RTERR_INVOPT;
   }

   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}

int asn1Init_e2ap_ENB_ID_Choice (e2ap_ENB_ID_Choice* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->t = 0;
   OSRTLMEMSET (&pvalue->u, 0, sizeof(pvalue->u));
   return 0;
}


void asn1Free_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue)
{
   if (pvalue == 0) return;
   switch (pvalue->t) {
      case 0: //no choice nothing to free
         break;
      case 1:
         if (pvalue->u.enb_ID_macro) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.enb_ID_macro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb_ID_macro);
            pvalue->u.enb_ID_macro = 0;
         }
         break;
      case 2:
         if (pvalue->u.enb_ID_shortmacro) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.enb_ID_shortmacro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb_ID_shortmacro);
            pvalue->u.enb_ID_shortmacro = 0;
         }
         break;
      case 3:
         if (pvalue->u.enb_ID_longmacro) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.enb_ID_longmacro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb_ID_longmacro);
            pvalue->u.enb_ID_longmacro = 0;
         }
         break;
   }
}


// --- End of e2ap_ENB_ID_Choice.c ---

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
   RTXCTXPUSHTYPENAME(pctxt, "GlobalngeNB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field plmn_id */  

   RTXCTXTPUSHELEMNAME(pctxt, "plmn-id");
   stat = asn1PE_e2ap_PLMN_Identity (pctxt, &pvalue->plmn_id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field enb_id */  

   RTXCTXTPUSHELEMNAME(pctxt, "enb-id");
   stat = asn1PE_e2ap_ENB_ID_Choice (pctxt, &pvalue->enb_id);
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

   RTXCTXPOPTYPENAME(pctxt);
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
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "GlobalngeNB-ID");

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
   /* decode field plmn_id */
   RTXCTXTPUSHELEMNAME(pctxt, "plmn-id");
      stat = asn1PD_e2ap_PLMN_Identity (pctxt, &pvalue->plmn_id);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field enb_id */
   RTXCTXTPUSHELEMNAME(pctxt, "enb-id");
      stat = asn1PD_e2ap_ENB_ID_Choice (pctxt, &pvalue->enb_id);
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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

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

// --- Begin of e2ap_ENB_ID.c ---
/* e2ap_ENB_ID.c */

/*****************************************/
/*           ENB_ID                */
/*****************************************/
// choice

// choice without extension

EXTERN int asn1PE_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "ENB-ID");
   RTXCTXTPUSHELEMNAME (pctxt, "t");
 
   stat = rtxEncBits (pctxt, pvalue->t - 1, 2);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   switch (pvalue->t) {
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "macro-eNB-ID");

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(20), OSUINTCONST(20), 0, 0);
         stat = pe_BitString32 (pctxt, pvalue->u.macro_eNB_ID, OSUINTCONST(20), OSUINTCONST(20));

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXTPUSHELEMNAME (pctxt, "home-eNB-ID");

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(28), OSUINTCONST(28), 0, 0);
         stat = pe_BitString32 (pctxt, pvalue->u.home_eNB_ID, OSUINTCONST(28), OSUINTCONST(28));

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXTPUSHELEMNAME (pctxt, "short-Macro-eNB-ID");

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(18), OSUINTCONST(18), 0, 0);
         stat = pe_BitString32 (pctxt, pvalue->u.short_Macro_eNB_ID, OSUINTCONST(18), OSUINTCONST(18));

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 4:
         RTXCTXTPUSHELEMNAME (pctxt, "long-Macro-eNB-ID");

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(21), OSUINTCONST(21), 0, 0);
         stat = pe_BitString32 (pctxt, pvalue->u.long_Macro_eNB_ID, OSUINTCONST(21), OSUINTCONST(21));

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PD_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   RTXCTXPUSHTYPENAME (pctxt, "ENB-ID");

 
   stat = rtxDecBits (pctxt, &ui, 2);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   else pvalue->t = ui + 1;
   //RTXCTXTPOPELEMNAME (pctxt);

   switch (ui) {
      case 0:
         RTXCTXTPUSHELEMNAME (pctxt, "macro-eNB-ID");

         pvalue->u.macro_eNB_ID = rtxMemAllocType (pctxt, ASN1BitStr32);

         if (pvalue->u.macro_eNB_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(20), OSUINTCONST(20), 0, 0);
         stat = pd_BitString32 (pctxt, pvalue->u.macro_eNB_ID, OSUINTCONST(20), OSUINTCONST(20));
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "home-eNB-ID");

         pvalue->u.home_eNB_ID = rtxMemAllocType (pctxt, ASN1BitStr32);

         if (pvalue->u.home_eNB_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(28), OSUINTCONST(28), 0, 0);
         stat = pd_BitString32 (pctxt, pvalue->u.home_eNB_ID, OSUINTCONST(28), OSUINTCONST(28));
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXTPUSHELEMNAME (pctxt, "short-Macro-eNB-ID");

         pvalue->u.short_Macro_eNB_ID = rtxMemAllocType (pctxt, ASN1BitStr32);

         if (pvalue->u.short_Macro_eNB_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(18), OSUINTCONST(18), 0, 0);
         stat = pd_BitString32 (pctxt, pvalue->u.short_Macro_eNB_ID, OSUINTCONST(18), OSUINTCONST(18));
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXTPUSHELEMNAME (pctxt, "long-Macro-eNB-ID");

         pvalue->u.long_Macro_eNB_ID = rtxMemAllocType (pctxt, ASN1BitStr32);

         if (pvalue->u.long_Macro_eNB_ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(21), OSUINTCONST(21), 0, 0);
         stat = pd_BitString32 (pctxt, pvalue->u.long_Macro_eNB_ID, OSUINTCONST(21), OSUINTCONST(21));
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PrtToStr_e2ap_ENB_ID (const char* name, e2ap_ENB_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) return -1;
   

   switch (pvalue->t) {
      case T_e2ap_ENB_ID_macro_eNB_ID:
         if (asn1PrtToStr_ASN1BitStr32 ( "macro_eNB_ID", pvalue->u.macro_eNB_ID, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_ENB_ID_home_eNB_ID:
         if (asn1PrtToStr_ASN1BitStr32 ( "home_eNB_ID", pvalue->u.home_eNB_ID, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_ENB_ID_short_Macro_eNB_ID:
         if (asn1PrtToStr_ASN1BitStr32 ( "short_Macro_eNB_ID", pvalue->u.short_Macro_eNB_ID, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_ENB_ID_long_Macro_eNB_ID:
         if (asn1PrtToStr_ASN1BitStr32 ( "long_Macro_eNB_ID", pvalue->u.long_Macro_eNB_ID, buffer, bufSize) < 0) return -1;
         break;
      default:
         return RTERR_INVOPT;
   }

   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}

int asn1Init_e2ap_ENB_ID (e2ap_ENB_ID* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->t = 0;
   OSRTLMEMSET (&pvalue->u, 0, sizeof(pvalue->u));
   return 0;
}


void asn1Free_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue)
{
   if (pvalue == 0) return;
   switch (pvalue->t) {
      case 0: //no choice nothing to free
         break;
      case 1:
         if (pvalue->u.macro_eNB_ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.macro_eNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.macro_eNB_ID);
            pvalue->u.macro_eNB_ID = 0;
         }
         break;
      case 2:
         if (pvalue->u.home_eNB_ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.home_eNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.home_eNB_ID);
            pvalue->u.home_eNB_ID = 0;
         }
         break;
      case 3:
         if (pvalue->u.short_Macro_eNB_ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.short_Macro_eNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.short_Macro_eNB_ID);
            pvalue->u.short_Macro_eNB_ID = 0;
         }
         break;
      case 4:
         if (pvalue->u.long_Macro_eNB_ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.long_Macro_eNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.long_Macro_eNB_ID);
            pvalue->u.long_Macro_eNB_ID = 0;
         }
         break;
   }
}


// --- End of e2ap_ENB_ID.c ---

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
   RTXCTXPUSHTYPENAME(pctxt, "GlobalENB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field pLMN_Identity */  

   RTXCTXTPUSHELEMNAME(pctxt, "pLMN-Identity");
   stat = asn1PE_e2ap_PLMN_Identity (pctxt, &pvalue->pLMN_Identity);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field eNB_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "eNB-ID");
   stat = asn1PE_e2ap_ENB_ID (pctxt, &pvalue->eNB_ID);
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

   RTXCTXPOPTYPENAME(pctxt);
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
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "GlobalENB-ID");

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
   /* decode field pLMN_Identity */
   RTXCTXTPUSHELEMNAME(pctxt, "pLMN-Identity");
      stat = asn1PD_e2ap_PLMN_Identity (pctxt, &pvalue->pLMN_Identity);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field eNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "eNB-ID");
      stat = asn1PD_e2ap_ENB_ID (pctxt, &pvalue->eNB_ID);
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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

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

// --- Begin of e2ap_NGENB_DU_ID.c ---
/* e2ap_NGENB_DU_ID.c */


//interger no ext
/*****************************************/
/*         NGENB-DU-ID     */
/*****************************************/

EXTERN int asn1PE_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "NGENB-DU-ID");
   stat = pe_ConsUnsigned (pctxt, value, 0, 68719476735);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "NGENB-DU-ID");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 64);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_NGENB_DU_ID (const char* name, e2ap_NGENB_DU_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_NGENB_DU_ID.c ---

// --- Begin of e2ap_GlobalE2node_ng_eNB_ID.c ---

/*****************************************/
/*           GlobalE2node-ng-eNB-ID                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node-ng-eNB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field global_ng_eNB_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "global-ng-eNB-ID");
   stat = asn1PE_e2ap_GlobalngeNB_ID (pctxt, &pvalue->global_ng_eNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field global_eNB_ID */  
   if (pvalue->m_global_eNB_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "global-eNB-ID");
   stat = asn1PE_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field ngENB_DU_ID */  
   if (pvalue->m_ngENB_DU_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "ngENB-DU-ID");
   stat = asn1PE_e2ap_NGENB_DU_ID (pctxt, &pvalue->ngENB_DU_ID);
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

   RTXCTXPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node-ng-eNB-ID");

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
   /* decode field global_ng_eNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-ng-eNB-ID");
      stat = asn1PD_e2ap_GlobalngeNB_ID (pctxt, &pvalue->global_ng_eNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field global_eNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-eNB-ID");
   if (optbits[0]) {
      pvalue->m_global_eNB_IDPresent = TRUE;
      stat = asn1PD_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_global_eNB_IDPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field ngENB_DU_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "ngENB-DU-ID");
   if (optbits[0]) {
      pvalue->m_ngENB_DU_IDPresent = TRUE;
      stat = asn1PD_e2ap_NGENB_DU_ID (pctxt, &pvalue->ngENB_DU_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_ngENB_DU_IDPresent = FALSE;
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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_GlobalE2node_ng_eNB_ID (e2ap_GlobalE2node_ng_eNB_ID* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_GlobalngeNB_ID (&pvalue->global_ng_eNB_ID);
   asn1Init_e2ap_GlobalENB_ID (&pvalue->global_eNB_ID);
   asn1Init_e2ap_NGENB_DU_ID (&pvalue->ngENB_DU_ID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_GlobalngeNB_ID (pctxt, &pvalue->global_ng_eNB_ID);
   asn1Free_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
   asn1Free_e2ap_NGENB_DU_ID (pctxt, &pvalue->ngENB_DU_ID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_GlobalE2node_ng_eNB_ID (const char* name, e2ap_GlobalE2node_ng_eNB_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GlobalngeNB_ID ("global_ng_eNB_ID", &pvalue->global_ng_eNB_ID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GlobalENB_ID ("global_eNB_ID", &pvalue->global_eNB_ID, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_NGENB_DU_ID ("ngENB_DU_ID", &pvalue->ngENB_DU_ID, buffer, bufSize) < 0)
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
// --- End of e2ap_GlobalE2node_ng_eNB_ID.c ---

// --- Begin of e2ap_GlobalE2node_eNB_ID.c ---

/*****************************************/
/*           GlobalE2node-eNB-ID                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node-eNB-ID");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field global_eNB_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "global-eNB-ID");
   stat = asn1PE_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
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

   RTXCTXPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node-eNB-ID");

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
   /* decode field global_eNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-eNB-ID");
      stat = asn1PD_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_GlobalE2node_eNB_ID (e2ap_GlobalE2node_eNB_ID* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_GlobalENB_ID (&pvalue->global_eNB_ID);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_GlobalE2node_eNB_ID (const char* name, e2ap_GlobalE2node_eNB_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_GlobalENB_ID ("global_eNB_ID", &pvalue->global_eNB_ID, buffer, bufSize) < 0)
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
// --- End of e2ap_GlobalE2node_eNB_ID.c ---

// --- Begin of e2ap_GlobalE2node_ID.c ---
/* e2ap_GlobalE2node_ID.c */

/*****************************************/
/*           GlobalE2node_ID                */
/*****************************************/
// choice

// choice without extension

EXTERN int asn1PE_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GlobalE2node-ID");
   RTXCTXTPUSHELEMNAME (pctxt, "t");
 
   stat = rtxEncBits (pctxt, pvalue->t - 1, 2);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   switch (pvalue->t) {
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "gNB");

         stat = asn1PE_e2ap_GlobalE2node_gNB_ID (pctxt, pvalue->u.gNB);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXTPUSHELEMNAME (pctxt, "en-gNB");

         stat = asn1PE_e2ap_GlobalE2node_en_gNB_ID (pctxt, pvalue->u.en_gNB);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXTPUSHELEMNAME (pctxt, "ng-eNB");

         stat = asn1PE_e2ap_GlobalE2node_ng_eNB_ID (pctxt, pvalue->u.ng_eNB);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 4:
         RTXCTXTPUSHELEMNAME (pctxt, "eNB");

         stat = asn1PE_e2ap_GlobalE2node_eNB_ID (pctxt, pvalue->u.eNB);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PD_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   RTXCTXPUSHTYPENAME (pctxt, "GlobalE2node-ID");

 
   stat = rtxDecBits (pctxt, &ui, 2);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   else pvalue->t = ui + 1;
   //RTXCTXTPOPELEMNAME (pctxt);

   switch (ui) {
      case 0:
         RTXCTXTPUSHELEMNAME (pctxt, "gNB");

         pvalue->u.gNB = rtxMemAllocType (pctxt, e2ap_GlobalE2node_gNB_ID);

         if (pvalue->u.gNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_GlobalE2node_gNB_ID (pctxt, pvalue->u.gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "en-gNB");

         pvalue->u.en_gNB = rtxMemAllocType (pctxt, e2ap_GlobalE2node_en_gNB_ID);

         if (pvalue->u.en_gNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_GlobalE2node_en_gNB_ID (pctxt, pvalue->u.en_gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXTPUSHELEMNAME (pctxt, "ng-eNB");

         pvalue->u.ng_eNB = rtxMemAllocType (pctxt, e2ap_GlobalE2node_ng_eNB_ID);

         if (pvalue->u.ng_eNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_GlobalE2node_ng_eNB_ID (pctxt, pvalue->u.ng_eNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXTPUSHELEMNAME (pctxt, "eNB");

         pvalue->u.eNB = rtxMemAllocType (pctxt, e2ap_GlobalE2node_eNB_ID);

         if (pvalue->u.eNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_GlobalE2node_eNB_ID (pctxt, pvalue->u.eNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PrtToStr_e2ap_GlobalE2node_ID (const char* name, e2ap_GlobalE2node_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) return -1;
   

   switch (pvalue->t) {
      case T_e2ap_GlobalE2node_ID_gNB:
         if (asn1PrtToStr_e2ap_GlobalE2node_gNB_ID ( "gNB", pvalue->u.gNB, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_GlobalE2node_ID_en_gNB:
         if (asn1PrtToStr_e2ap_GlobalE2node_en_gNB_ID ( "en_gNB", pvalue->u.en_gNB, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_GlobalE2node_ID_ng_eNB:
         if (asn1PrtToStr_e2ap_GlobalE2node_ng_eNB_ID ( "ng_eNB", pvalue->u.ng_eNB, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_GlobalE2node_ID_eNB:
         if (asn1PrtToStr_e2ap_GlobalE2node_eNB_ID ( "eNB", pvalue->u.eNB, buffer, bufSize) < 0) return -1;
         break;
      default:
         return RTERR_INVOPT;
   }

   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}

int asn1Init_e2ap_GlobalE2node_ID (e2ap_GlobalE2node_ID* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->t = 0;
   OSRTLMEMSET (&pvalue->u, 0, sizeof(pvalue->u));
   return 0;
}


void asn1Free_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue)
{
   if (pvalue == 0) return;
   switch (pvalue->t) {
      case 0: //no choice nothing to free
         break;
      case 1:
         if (pvalue->u.gNB) {
            asn1Free_e2ap_GlobalE2node_gNB_ID (pctxt, pvalue->u.gNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gNB);
            pvalue->u.gNB = 0;
         }
         break;
      case 2:
         if (pvalue->u.en_gNB) {
            asn1Free_e2ap_GlobalE2node_en_gNB_ID (pctxt, pvalue->u.en_gNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.en_gNB);
            pvalue->u.en_gNB = 0;
         }
         break;
      case 3:
         if (pvalue->u.ng_eNB) {
            asn1Free_e2ap_GlobalE2node_ng_eNB_ID (pctxt, pvalue->u.ng_eNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.ng_eNB);
            pvalue->u.ng_eNB = 0;
         }
         break;
      case 4:
         if (pvalue->u.eNB) {
            asn1Free_e2ap_GlobalE2node_eNB_ID (pctxt, pvalue->u.eNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.eNB);
            pvalue->u.eNB = 0;
         }
         break;
   }
}


// --- End of e2ap_GlobalE2node_ID.c ---

// --- Begin of e2ap_RANfunctionID.c ---
/* e2ap_RANfunctionID.c */


//interger no ext
/*****************************************/
/*         RANfunctionID     */
/*****************************************/

EXTERN int asn1PE_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionID");
   stat = pe_ConsUnsigned (pctxt, value, 0, 4095);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionID");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 16);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
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
/* e2ap_RANfunctionDefinition.c */


//octet string

/*****************************************/
/*           RANfunctionDefinition                */
/*****************************************/

/* Dynamic OCTET STRING (no SIZE constraint) */
EXTERN int asn1PE_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition* pvalue)
{
   int stat = 0;
  
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionDefinition");
   
   stat = pe_OctetString (pctxt, pvalue->numocts, pvalue->data);
 
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition** ppvalue)
{
   int stat = 0;
  
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionDefinition");
 
   stat = pd_DynOctetString (pctxt, (OSDynOctStr**)ppvalue);
   
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
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
/* e2ap_RANfunctionRevision.c */


//interger no ext
/*****************************************/
/*         RANfunctionRevision     */
/*****************************************/

EXTERN int asn1PE_e2ap_RANfunctionRevision (OSCTXT* pctxt, e2ap_RANfunctionRevision value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionRevision");
   stat = pe_ConsUnsigned (pctxt, value, 0, 4095);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RANfunctionRevision (OSCTXT* pctxt, e2ap_RANfunctionRevision* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionRevision");
   if (pctxt->buffer.aligned) {
      int stat2 = PD_BYTE_ALIGN (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 16);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
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
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionOID");

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

   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID* ppvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionOID");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(1000), OSUINTCONST(0), OSUINT32_MAX);

   stat = pd_ConstrainedStringEx (pctxt, ppvalue, 0, 8, 7, 7);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);
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
   RTXCTXPUSHTYPENAME(pctxt, "RANfunction-Item");

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

   RTXCTXPOPTYPENAME(pctxt);
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
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "RANfunction-Item");

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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

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
   RTXCTXPUSHTYPENAME (pctxt, "RANfunction_ItemIEs");

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
         case T_E2AP_PDU_Contents_RANfunction_ItemIEs_:
            RTXCTXTPUSHELEMNAME (pctxt, "e2ap-E2nodeComponentConfigAddition-Item");
            stat = asn1PE_e2ap_ (pctxt, &pvalue->value.u_RANfunction_ItemIEs_.value);
            if (stat != 0) return LOG_RTERR (pctxt, stat);
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

   RTXCTXPUSHTYPENAME (pctxt, "RANfunctions-List");

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

      xx1++;
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

   RTXCTXPUSHTYPENAME (pctxt, "RANfunctions-List");

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
   if(0==pvalue) return RTERR_NULLPTR
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
// --- End of e2ap_RANfunctions_List.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceType.c ---
/* e2ap_E2nodeComponentInterfaceType.c - enum */


//enumerated
/******************************************************/
/*                                                    */
/*    E2nodeComponentInterfaceType                          */
/*                                                    */
/******************************************************/


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
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentInterfaceType");
   if (value >= 7) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(6));
   if(stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceType* pvalue)
{
   int stat = 0;

   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentInterfaceType");

   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(6));
   if(stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);

   return stat;
}

EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceType (const char* name, e2ap_E2nodeComponentInterfaceType* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;

   if(rtPrintToStringIdent(buffer, bufSize) < 0) return -1;
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
   RTXCTXPUSHTYPENAME (pctxt, "AMFName");

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

   RTXCTXPOPTYPENAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName* ppvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "AMFName");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(150), OSUINTCONST(0), OSUINT32_MAX);

   stat = pd_ConstrainedStringEx (pctxt, ppvalue, 0, 8, 7, 7);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPTYPENAME (pctxt);
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
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceNG");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field amf_name */  

   RTXCTXTPUSHELEMNAME(pctxt, "amf-name");
   stat = asn1PE_e2ap_AMFName (pctxt, &pvalue->amf_name);
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

   RTXCTXPOPTYPENAME(pctxt);
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

   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceNG");

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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

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

// --- Begin of e2ap_GlobalNG_RANNode_ID.c ---
/* e2ap_GlobalNG_RANNode_ID.c */

/*****************************************/
/*           GlobalNG_RANNode_ID                */
/*****************************************/
// choice

// choice without extension

EXTERN int asn1PE_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GlobalNG-RANNode-ID");
   RTXCTXTPUSHELEMNAME (pctxt, "t");
 
   stat = rtxEncBits (pctxt, pvalue->t - 1, 1);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   switch (pvalue->t) {
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "gNB");

         stat = asn1PE_e2ap_GlobalgNB_ID (pctxt, pvalue->u.gNB);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXTPUSHELEMNAME (pctxt, "ng-eNB");

         stat = asn1PE_e2ap_GlobalngeNB_ID (pctxt, pvalue->u.ng_eNB);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PD_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   RTXCTXPUSHTYPENAME (pctxt, "GlobalNG-RANNode-ID");

 
   stat = rtxDecBits (pctxt, &ui, 1);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   else pvalue->t = ui + 1;
   //RTXCTXTPOPELEMNAME (pctxt);

   switch (ui) {
      case 0:
         RTXCTXTPUSHELEMNAME (pctxt, "gNB");

         pvalue->u.gNB = rtxMemAllocType (pctxt, e2ap_GlobalgNB_ID);

         if (pvalue->u.gNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_GlobalgNB_ID (pctxt, pvalue->u.gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "ng-eNB");

         pvalue->u.ng_eNB = rtxMemAllocType (pctxt, e2ap_GlobalngeNB_ID);

         if (pvalue->u.ng_eNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_GlobalngeNB_ID (pctxt, pvalue->u.ng_eNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PrtToStr_e2ap_GlobalNG_RANNode_ID (const char* name, e2ap_GlobalNG_RANNode_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) return -1;
   

   switch (pvalue->t) {
      case T_e2ap_GlobalNG_RANNode_ID_gNB:
         if (asn1PrtToStr_e2ap_GlobalgNB_ID ( "gNB", pvalue->u.gNB, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_GlobalNG_RANNode_ID_ng_eNB:
         if (asn1PrtToStr_e2ap_GlobalngeNB_ID ( "ng_eNB", pvalue->u.ng_eNB, buffer, bufSize) < 0) return -1;
         break;
      default:
         return RTERR_INVOPT;
   }

   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}

int asn1Init_e2ap_GlobalNG_RANNode_ID (e2ap_GlobalNG_RANNode_ID* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->t = 0;
   OSRTLMEMSET (&pvalue->u, 0, sizeof(pvalue->u));
   return 0;
}


void asn1Free_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue)
{
   if (pvalue == 0) return;
   switch (pvalue->t) {
      case 0: //no choice nothing to free
         break;
      case 1:
         if (pvalue->u.gNB) {
            asn1Free_e2ap_GlobalgNB_ID (pctxt, pvalue->u.gNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gNB);
            pvalue->u.gNB = 0;
         }
         break;
      case 2:
         if (pvalue->u.ng_eNB) {
            asn1Free_e2ap_GlobalngeNB_ID (pctxt, pvalue->u.ng_eNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.ng_eNB);
            pvalue->u.ng_eNB = 0;
         }
         break;
   }
}


// --- End of e2ap_GlobalNG_RANNode_ID.c ---

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
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceXn");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field global_NG_RAN_Node_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "global-NG-RAN-Node-ID");
   stat = asn1PE_e2ap_GlobalNG_RANNode_ID (pctxt, &pvalue->global_NG_RAN_Node_ID);
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

   RTXCTXPOPTYPENAME(pctxt);
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

   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceXn");

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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

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
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceE1");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field gNB_CU_UP_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "gNB-CU-UP-ID");
   stat = asn1PE_e2ap_GNB_CU_UP_ID (pctxt, &pvalue->gNB_CU_UP_ID);
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

   RTXCTXPOPTYPENAME(pctxt);
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

   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceE1");

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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

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
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceF1");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field gNB_DU_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "gNB-DU-ID");
   stat = asn1PE_e2ap_GNB_DU_ID (pctxt, &pvalue->gNB_DU_ID);
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

   RTXCTXPOPTYPENAME(pctxt);
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

   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceF1");

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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

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
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceW1");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field ng_eNB_DU_ID */  

   RTXCTXTPUSHELEMNAME(pctxt, "ng-eNB-DU-ID");
   stat = asn1PE_e2ap_NGENB_DU_ID (pctxt, &pvalue->ng_eNB_DU_ID);
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

   RTXCTXPOPTYPENAME(pctxt);
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

   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceW1");

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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

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
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceS1");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field mme_name */  

   RTXCTXTPUSHELEMNAME(pctxt, "mme-name");
   stat = asn1PE_e2ap_MMEname (pctxt, &pvalue->mme_name);
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

   RTXCTXPOPTYPENAME(pctxt);
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

   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceS1");

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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

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
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceX2");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field global_eNB_ID */  
   if (pvalue->m_global_eNB_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "global-eNB-ID");
   stat = asn1PE_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   }

   /* encode field global_en_gNB_ID */  
   if (pvalue->m_global_en_gNB_IDPresent) {

   RTXCTXTPUSHELEMNAME(pctxt, "global-en-gNB-ID");
   stat = asn1PE_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
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

   RTXCTXPOPTYPENAME(pctxt);
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
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceX2");

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
   /* decode field global_eNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-eNB-ID");
   if (optbits[0]) {
      pvalue->m_global_eNB_IDPresent = TRUE;
      stat = asn1PD_e2ap_GlobalENB_ID (pctxt, &pvalue->global_eNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_global_eNB_IDPresent = FALSE;
   }
   RTXPOPELEMNAME(pctxt);

   /* decode field global_en_gNB_ID */
   RTXCTXTPUSHELEMNAME(pctxt, "global-en-gNB-ID");
   if (optbits[0]) {
      pvalue->m_global_en_gNB_IDPresent = TRUE;
      stat = asn1PD_e2ap_GlobalenGNB_ID (pctxt, &pvalue->global_en_gNB_ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   } else {
      pvalue->m_global_en_gNB_IDPresent = FALSE;
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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

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

// --- Begin of e2ap_E2nodeComponentID.c ---
/* e2ap_E2nodeComponentID.c */

/*****************************************/
/*           E2nodeComponentID                */
/*****************************************/
// choice

// choice without extension

EXTERN int asn1PE_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentID");
   RTXCTXTPUSHELEMNAME (pctxt, "t");
 
   stat = rtxEncBits (pctxt, pvalue->t - 1, 3);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   switch (pvalue->t) {
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeNG");

         stat = asn1PE_e2ap_E2nodeComponentInterfaceNG (pctxt, pvalue->u.e2nodeComponentInterfaceTypeNG);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeXn");

         stat = asn1PE_e2ap_E2nodeComponentInterfaceXn (pctxt, pvalue->u.e2nodeComponentInterfaceTypeXn);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeE1");

         stat = asn1PE_e2ap_E2nodeComponentInterfaceE1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeE1);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 4:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeF1");

         stat = asn1PE_e2ap_E2nodeComponentInterfaceF1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeF1);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 5:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeW1");

         stat = asn1PE_e2ap_E2nodeComponentInterfaceW1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeW1);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 6:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeS1");

         stat = asn1PE_e2ap_E2nodeComponentInterfaceS1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeS1);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 7:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeX2");

         stat = asn1PE_e2ap_E2nodeComponentInterfaceX2 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeX2);

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentID");

 
   stat = rtxDecBits (pctxt, &ui, 3);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   else pvalue->t = ui + 1;
   //RTXCTXTPOPELEMNAME (pctxt);

   switch (ui) {
      case 0:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeNG");

         pvalue->u.e2nodeComponentInterfaceTypeNG = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceNG);

         if (pvalue->u.e2nodeComponentInterfaceTypeNG == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_E2nodeComponentInterfaceNG (pctxt, pvalue->u.e2nodeComponentInterfaceTypeNG);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeXn");

         pvalue->u.e2nodeComponentInterfaceTypeXn = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceXn);

         if (pvalue->u.e2nodeComponentInterfaceTypeXn == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_E2nodeComponentInterfaceXn (pctxt, pvalue->u.e2nodeComponentInterfaceTypeXn);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeE1");

         pvalue->u.e2nodeComponentInterfaceTypeE1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceE1);

         if (pvalue->u.e2nodeComponentInterfaceTypeE1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_E2nodeComponentInterfaceE1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeE1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeF1");

         pvalue->u.e2nodeComponentInterfaceTypeF1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceF1);

         if (pvalue->u.e2nodeComponentInterfaceTypeF1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_E2nodeComponentInterfaceF1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeF1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 4:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeW1");

         pvalue->u.e2nodeComponentInterfaceTypeW1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceW1);

         if (pvalue->u.e2nodeComponentInterfaceTypeW1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_E2nodeComponentInterfaceW1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeW1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 5:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeS1");

         pvalue->u.e2nodeComponentInterfaceTypeS1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceS1);

         if (pvalue->u.e2nodeComponentInterfaceTypeS1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_E2nodeComponentInterfaceS1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeS1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 6:
         RTXCTXTPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeX2");

         pvalue->u.e2nodeComponentInterfaceTypeX2 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceX2);

         if (pvalue->u.e2nodeComponentInterfaceTypeX2 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         stat = asn1PD_e2ap_E2nodeComponentInterfaceX2 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeX2);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PrtToStr_e2ap_E2nodeComponentID (const char* name, e2ap_E2nodeComponentID* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) return -1;
   

   switch (pvalue->t) {
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeNG:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceNG ( "e2nodeComponentInterfaceTypeNG", pvalue->u.e2nodeComponentInterfaceTypeNG, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeXn:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceXn ( "e2nodeComponentInterfaceTypeXn", pvalue->u.e2nodeComponentInterfaceTypeXn, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeE1:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceE1 ( "e2nodeComponentInterfaceTypeE1", pvalue->u.e2nodeComponentInterfaceTypeE1, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeF1:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceF1 ( "e2nodeComponentInterfaceTypeF1", pvalue->u.e2nodeComponentInterfaceTypeF1, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeW1:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceW1 ( "e2nodeComponentInterfaceTypeW1", pvalue->u.e2nodeComponentInterfaceTypeW1, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeS1:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceS1 ( "e2nodeComponentInterfaceTypeS1", pvalue->u.e2nodeComponentInterfaceTypeS1, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeX2:
         if (asn1PrtToStr_e2ap_E2nodeComponentInterfaceX2 ( "e2nodeComponentInterfaceTypeX2", pvalue->u.e2nodeComponentInterfaceTypeX2, buffer, bufSize) < 0) return -1;
         break;
      default:
         return RTERR_INVOPT;
   }

   if(rtPrintToStringCloseBrace(buffer, bufSize) < 0) return -1;
   return 0;
}

int asn1Init_e2ap_E2nodeComponentID (e2ap_E2nodeComponentID* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->t = 0;
   OSRTLMEMSET (&pvalue->u, 0, sizeof(pvalue->u));
   return 0;
}


void asn1Free_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue)
{
   if (pvalue == 0) return;
   switch (pvalue->t) {
      case 0: //no choice nothing to free
         break;
      case 1:
         if (pvalue->u.e2nodeComponentInterfaceTypeNG) {
            asn1Free_e2ap_E2nodeComponentInterfaceNG (pctxt, pvalue->u.e2nodeComponentInterfaceTypeNG);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeNG);
            pvalue->u.e2nodeComponentInterfaceTypeNG = 0;
         }
         break;
      case 2:
         if (pvalue->u.e2nodeComponentInterfaceTypeXn) {
            asn1Free_e2ap_E2nodeComponentInterfaceXn (pctxt, pvalue->u.e2nodeComponentInterfaceTypeXn);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeXn);
            pvalue->u.e2nodeComponentInterfaceTypeXn = 0;
         }
         break;
      case 3:
         if (pvalue->u.e2nodeComponentInterfaceTypeE1) {
            asn1Free_e2ap_E2nodeComponentInterfaceE1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeE1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeE1);
            pvalue->u.e2nodeComponentInterfaceTypeE1 = 0;
         }
         break;
      case 4:
         if (pvalue->u.e2nodeComponentInterfaceTypeF1) {
            asn1Free_e2ap_E2nodeComponentInterfaceF1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeF1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeF1);
            pvalue->u.e2nodeComponentInterfaceTypeF1 = 0;
         }
         break;
      case 5:
         if (pvalue->u.e2nodeComponentInterfaceTypeW1) {
            asn1Free_e2ap_E2nodeComponentInterfaceW1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeW1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeW1);
            pvalue->u.e2nodeComponentInterfaceTypeW1 = 0;
         }
         break;
      case 6:
         if (pvalue->u.e2nodeComponentInterfaceTypeS1) {
            asn1Free_e2ap_E2nodeComponentInterfaceS1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeS1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeS1);
            pvalue->u.e2nodeComponentInterfaceTypeS1 = 0;
         }
         break;
      case 7:
         if (pvalue->u.e2nodeComponentInterfaceTypeX2) {
            asn1Free_e2ap_E2nodeComponentInterfaceX2 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeX2);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeX2);
            pvalue->u.e2nodeComponentInterfaceTypeX2 = 0;
         }
         break;
   }
}


// --- End of e2ap_E2nodeComponentID.c ---

/******************************************************/
/* File .c missing: e2ap_e2nodeComponentRequestPart.c */
/******************************************************/

/*******************************************************/
/* File .c missing: e2ap_e2nodeComponentResponsePart.c */
/*******************************************************/

// --- Begin of e2ap_E2nodeComponentConfiguration.c ---

/*****************************************/
/*           E2nodeComponentConfiguration                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfiguration");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field e2nodeComponentRequestPart */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentRequestPart");
   stat = asn1PE_e2ap_e2nodeComponentRequestPart (pctxt, &pvalue->e2nodeComponentRequestPart);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field e2nodeComponentResponsePart */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentResponsePart");
   stat = asn1PE_e2ap_e2nodeComponentResponsePart (pctxt, &pvalue->e2nodeComponentResponsePart);
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

   RTXCTXPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfiguration");

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
   /* decode field e2nodeComponentRequestPart */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentRequestPart");
      stat = asn1PD_e2ap_e2nodeComponentRequestPart (pctxt, &pvalue->e2nodeComponentRequestPart);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field e2nodeComponentResponsePart */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentResponsePart");
      stat = asn1PD_e2ap_e2nodeComponentResponsePart (pctxt, &pvalue->e2nodeComponentResponsePart);
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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_E2nodeComponentConfiguration (e2ap_E2nodeComponentConfiguration* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_e2nodeComponentRequestPart (&pvalue->e2nodeComponentRequestPart);
   asn1Init_e2ap_e2nodeComponentResponsePart (&pvalue->e2nodeComponentResponsePart);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_e2nodeComponentRequestPart (pctxt, &pvalue->e2nodeComponentRequestPart);
   asn1Free_e2ap_e2nodeComponentResponsePart (pctxt, &pvalue->e2nodeComponentResponsePart);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentConfiguration (const char* name, e2ap_E2nodeComponentConfiguration* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) 
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_e2nodeComponentRequestPart ("e2nodeComponentRequestPart", &pvalue->e2nodeComponentRequestPart, buffer, bufSize) < 0)
   {
      return -1;
   }
   if(asn1PrtToStr_e2ap_e2nodeComponentResponsePart ("e2nodeComponentResponsePart", &pvalue->e2nodeComponentResponsePart, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeComponentConfiguration.c ---

// --- Begin of e2ap_E2nodeComponentConfigAddition_Item.c ---

/*****************************************/
/*           E2nodeComponentConfigAddition-Item                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigAddition-Item");

   /*extension bit*/
   extbit = (OSBOOL)(pvalue->extElem1.count > 0);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   /* encode field e2nodeComponentInterfaceType */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentInterfaceType");
   stat = asn1PE_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field e2nodeComponentID */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentID");
   stat = asn1PE_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);


   /* encode field e2nodeComponentConfiguration */  

   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentConfiguration");
   stat = asn1PE_e2ap_E2nodeComponentConfiguration (pctxt, &pvalue->e2nodeComponentConfiguration);
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

   RTXCTXPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigAddition-Item");

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
   /* decode field e2nodeComponentInterfaceType */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentInterfaceType");
      stat = asn1PD_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field e2nodeComponentID */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentID");
      stat = asn1PD_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   RTXPOPELEMNAME(pctxt);

   /* decode field e2nodeComponentConfiguration */
   RTXCTXTPUSHELEMNAME(pctxt, "e2nodeComponentConfiguration");
      stat = asn1PD_e2ap_E2nodeComponentConfiguration (pctxt, &pvalue->e2nodeComponentConfiguration);
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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_E2nodeComponentConfigAddition_Item (e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_E2nodeComponentInterfaceType (&pvalue->e2nodeComponentInterfaceType);
   asn1Init_e2ap_E2nodeComponentID (&pvalue->e2nodeComponentID);
   asn1Init_e2ap_E2nodeComponentConfiguration (&pvalue->e2nodeComponentConfiguration);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   asn1Free_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   asn1Free_e2ap_E2nodeComponentConfiguration (pctxt, &pvalue->e2nodeComponentConfiguration);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2nodeComponentConfigAddition_Item (const char* name, e2ap_E2nodeComponentConfigAddition_Item* pvalue, char* buffer, OSSIZE bufSize)
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
   if(asn1PrtToStr_e2ap_E2nodeComponentConfiguration ("e2nodeComponentConfiguration", &pvalue->e2nodeComponentConfiguration, buffer, bufSize) < 0)
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
// --- End of e2ap_E2nodeComponentConfigAddition_Item.c ---

// --- Begin of e2ap_E2nodeComponentConfigAddition_ItemIEs.c ---
/* e2ap_E2nodeComponentConfigAddition_ItemIEs.c */

/*****************************************/
/*           E2nodeComponentConfigAddition_ItemIEs               */
/*****************************************/
//IE

int asn1PE_e2ap_E2nodeComponentConfigAddition_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentConfigAddition_ItemIEs");

   /* encode id */
   RTXCTXTPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_E2nodeComponentConfigAddition_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXTPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_E2nodeComponentConfigAddition_ItemIEs_.criticality);
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
         case T_E2AP_PDU_Contents_E2nodeComponentConfigAddition_ItemIEs_:
            RTXCTXTPUSHELEMNAME (pctxt, "e2ap-E2nodeComponentConfigAddition-Item");
            stat = asn1PE_e2ap_ (pctxt, &pvalue->value.u_E2nodeComponentConfigAddition_ItemIEs_.value);
            if (stat != 0) return LOG_RTERR (pctxt, stat);
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

int asn1PD_e2ap_E2nodeComponentConfigAddition_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigAddition_ItemIEs (e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_E2nodeComponentConfigAddition_ItemIEs));
}

void asn1Free_e2ap_E2nodeComponentConfigAddition_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
// --- End of e2ap_E2nodeComponentConfigAddition_ItemIEs.c ---

// --- Begin of e2ap_E2nodeComponentConfigAddition_List.c ---
/*****************************************/
/*           E2nodeComponentConfigAddition_List                */
/*****************************************/
//seq_of_single_container


int asn1PE_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2nodeComponentConfigAddition_ItemIEs* pdata;

   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentConfigAddition-List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofE2nodeComponents), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_E2nodeComponentConfigAddition_ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_E2nodeComponentConfigAddition_ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* ppvalue)
{
   int stat = 0;
   OSSIZE xx1 = 0;
   OSSIZE count = 0;

   e2ap_E2nodeComponentConfigAddition_ItemIEs* pdata;

   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentConfigAddition-List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(ASN1V_e2ap_maxofE2nodeComponents), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_E2nodeComponentConfigAddition_ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_E2nodeComponentConfigAddition_ItemIEs (pdata);

      stat = asn1PD_e2ap_E2nodeComponentConfigAddition_ItemIEs (pctxt, pdata);
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

void asn1Init_e2ap_E2nodeComponentConfigAddition_List (e2ap_E2nodeComponentConfigAddition_List* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR
   rtxDListFastInit (pvalue);
}

void asn1Free_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* pvalue)
{
   if(pvalue==0) return;
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_E2nodeComponentConfigAddition_ItemIEs* pdata = (e2ap_E2nodeComponentConfigAddition_ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_E2nodeComponentConfigAddition_ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}
// --- End of e2ap_E2nodeComponentConfigAddition_List.c ---

/*********************************************/
/* File .c missing: e2ap_E2setupRequestIEs.c */
/*********************************************/

// --- Begin of e2ap_E2setupRequest.c ---

/*****************************************/
/*           E2setupRequest                */
/*****************************************/
//sequence normal

//contain extensition bit -> theo mau cu GlobalgNB-ID
int asn1PE_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME(pctxt, "E2setupRequest");

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

   RTXCTXPOPTYPENAME(pctxt);
   return (stat);
}

int asn1PD_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue)
{
   int stat =0;
   ASN1OpenType openType;
   ASN1OpenType* pOpenType;
   OSUINT32 bitcnt;
   OSUINT32 i_;
   OSBOOL extbit = FALSE;
   OSBOOL optbits[1];

   RTXCTXPUSHTYPENAME(pctxt, "E2setupRequest");

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
                  rtxListAppend(pctxt, &pvalue->extElem1, pOpenType);
               }
               else stat = RTERR_NOMEM;
            }
            else{
               LOG_RTERR(pctxt, stat);
               break;
            }
         }
         else{//unknown element
            rtxListAppend(pctxt, &pvalue->extElem1, 0);
         }
      }
      rtxMemFreePtr(pctxt, poptbits);
   }

   RTXCTXPOPTYPENAME(pctxt);

   return (stat);

}

int asn1Init_e2ap_E2setupRequest (e2ap_E2setupRequest* pvalue)
{
   if(0==pvalue) return RTERR_NULLPTR;
   asn1Init_e2ap_ProtocolIE_Container (&pvalue->protocolIEs);
   rtxDListFastInit(&pvalue->extElem1);
   return 0;
}

void asn1Free_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue)
{
   if(0==pvalue) return;
   asn1Free_e2ap_ProtocolIE_Container (pctxt, &pvalue->protocolIEs);
   rtxMemFreeOpenSeqExt(pctxt, &pvalue->extElem1);
}

int asn1PrtToStr_e2ap_E2setupRequest (const char* name, e2ap_E2setupRequest* pvalue, char* buffer, OSSIZE bufSize)
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
// --- End of e2ap_E2setupRequest.c ---

// --- Begin of e2ap_E2setupRequest_protocolIEs.c ---
/******************************************************/
/*                                                    */
/*    E2setupRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

EXTERN int asn1PE_e2ap_E2setupRequest_protocolIEs (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEst* pvalue)
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
        stat = asn1PE_e2ap_E2setupRequest_protocolIEs_element (pctxt, ((e2ap_E2setupRequest_protocolIEs_element*)pnode->data));
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        xx1++;
        RTXCTXTPOPARRAYELEMNAME(pctxt);
    }

    return (stat);
}

EXTERN int  asn1PD_e2ap_E2setupRequest_protocolIEs(OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs* pvalue)
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
        e2ap_E2setupRequest_protocolIEs_element* pdata;
        RTXCTXTPUSHARRAYELEMNAME(pctxt, "SEQUENCE", &pnode, &pdata);

        if(pnode == NULL) return LOG_RTERR(pctxt, RTERR_NOMEM);

        asn1Init_e2ap_E2setupRequest_protocolIEs_element(pdata);
        rtxDListAppendNode(pvalue, pnode);
       // stat = asn1PD_e2ap_E2setupRequest_protocolIEs_element (pctxt, pdata);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
        RTXCTXTPOPARRAYELEMNAME(pctxt);

    }
    return (stat);
}


int asn1Init_e2ap_E2setupRequest_protocolIEs(e2ap_E2setupRequest_protocolIEs* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    rtxDListFastInit (pvalue);
    return 0;
}

void asn1Free_e2ap_E2setupRequest_protocolIEs(OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs* pvalue)
{
    if(0==pvalue) return;   
    e2ap_E2setupRequest_protocolIEs_element* pdata;
    OSRTDListNode* pnode=pvalue->head;
    while(0!=pnode){
        pdata = (e2ap_E2setupRequest_protocolIEs_element*)pnode->data;
       // asn1Free_e2ap_E2setupRequest_protocolIEs_element(pctxt, pdata);
        pnode = pnode->next;
    }
    rtxDListFreeAll(pctxt, pvalue);
}

// --- End of e2ap_E2setupRequest_protocolIEs.c ---

// --- Begin of e2ap_E2setupRequest_protocolIEs_element.c ---
/*****************************************/
/*    E2setupRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe

EXTERN int asn1PE_e2ap_E2setupRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs_element* pvalue)
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
            case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_TransactionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-TransactionID");

                stat = asn1PE_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2SetupRequestIEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_GlobalE2node_ID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-TransactionID");

                stat = asn1PE_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2SetupRequestIEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_RANfunctions_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-TransactionID");

                stat = asn1PE_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2SetupRequestIEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-TransactionID");

                stat = asn1PE_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2SetupRequestIEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_UNDEF_:
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

        if(decoded){
            rtxMemFreePtr(pctxt, pDynamicEncodeBuffer);
        }

    }

    if(stat!=0) return LOG_RTERR(pctxt, stat);  
    RTXCTXTPOPELEMNAME(pctxt);
    return (stat);

}

EXTERN int  asn1PD_e2ap_E2setupRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs_element* pvalue){
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

        switch(pvalue->id){
        
            case ASN1V_e2ap_id:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_TransactionID;
            RTXCTXTPUSHELEMNAME(pctxt, "TransactionID");
            pvalue->value.u._e2ap_E2setupRequestIEs_id_TransactionID 
                = rtxMemAllocType(pctxt, e2ap_TransactionID);

            asn1Init_e2ap_TransactionID(pvalue->
                value.u._e2ap_E2setupRequestIEs_id_TransactionID);

            stat = asn1PD_e2ap_TransactionID (pctxt,
                (e2ap_TransactionID*)pvalue->value.
                u._e2ap_E2setupRequestIEs_id_TransactionID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_GlobalE2node_ID;
            RTXCTXTPUSHELEMNAME(pctxt, "GlobalE2node-ID");
            pvalue->value.u._e2ap_E2setupRequestIEs_id_GlobalE2node_ID 
                = rtxMemAllocType(pctxt, e2ap_GlobalE2node_ID);

            asn1Init_e2ap_GlobalE2node_ID(pvalue->
                value.u._e2ap_E2setupRequestIEs_id_GlobalE2node_ID);

            stat = asn1PD_e2ap_GlobalE2node_ID (pctxt,
                (e2ap_GlobalE2node_ID*)pvalue->value.
                u._e2ap_E2setupRequestIEs_id_GlobalE2node_ID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_RANfunctions_List;
            RTXCTXTPUSHELEMNAME(pctxt, "RANfunctions-List");
            pvalue->value.u._e2ap_E2setupRequestIEs_id_RANfunctions_List 
                = rtxMemAllocType(pctxt, e2ap_RANfunctions_List);

            asn1Init_e2ap_RANfunctions_List(pvalue->
                value.u._e2ap_E2setupRequestIEs_id_RANfunctions_List);

            stat = asn1PD_e2ap_RANfunctions_List (pctxt,
                (e2ap_RANfunctions_List*)pvalue->value.
                u._e2ap_E2setupRequestIEs_id_RANfunctions_List);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition_List;
            RTXCTXTPUSHELEMNAME(pctxt, "E2nodeComponentConfigAddition-List");
            pvalue->value.u._e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition_List 
                = rtxMemAllocType(pctxt, e2ap_E2nodeComponentConfigAddition_List);

            asn1Init_e2ap_E2nodeComponentConfigAddition_List(pvalue->
                value.u._e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition_List);

            stat = asn1PD_e2ap_E2nodeComponentConfigAddition_List (pctxt,
                (e2ap_E2nodeComponentConfigAddition_List*)pvalue->value.
                u._e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition_List);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    

        default:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_UNDEF_;
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


int asn1Init_e2ap_E2setupRequest_protocolIEs_element(e2ap_E2setupRequest_protocolIEs_element* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    OSCRTLMEMSET (&pvalue->value, 0, sizeof(pvalue->value));
    return 0;
}

void free_e2ap_E2setupRequest_protocolIEs_element(e2ap_E2setupRequest_protocolIEs_element* pvalue)
{
    if(NULL==pvalue) return;
    switch(pvalue->value.t){
        case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_TransactionID:
            rtxFreeE2ap_TransactionID(pvalue->value.u._e2ap_E2setupRequestIEs_id_TransactionID);
            break;
        case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_GlobalE2node_ID:
            rtxFreeE2ap_GlobalE2node_ID(pvalue->value.u._e2ap_E2setupRequestIEs_id_GlobalE2node_ID);
            break;
        case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_RANfunctions_List:
            rtxFreeE2ap_RANfunctions_List(pvalue->value.u._e2ap_E2setupRequestIEs_id_RANfunctions_List);
            break;
        case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition_List:
            rtxFreeE2ap_E2nodeComponentConfigAddition_List(pvalue->value.u._e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition_List);
            break;
        case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_UNDEF_:
            rtxFreeASN1OpenType(pvalue->value.u.extElem1);
            break;
        default:
            break;
    }
}

int asn1PrtToStr_e2ap_E2setupRequest_protocolIEs_element(OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs_element* pvalue)
{
    int stat =0;
    RTXCTXTPUSHELEMNAME(pctxt, "e2ap_E2setupRequest_protocolIEs_element");

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
            case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_TransactionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "TransactionID");

                stat = asn1PrtToStr_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2setupRequestIEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_GlobalE2node_ID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "GlobalE2node-ID");

                stat = asn1PrtToStr_e2ap_GlobalE2node_ID (pctxt, pvalue->value.u._e2ap_E2setupRequestIEs_id_GlobalE2node_ID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_RANfunctions_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "RANfunctions-List");

                stat = asn1PrtToStr_e2ap_RANfunctions_List (pctxt, pvalue->value.u._e2ap_E2setupRequestIEs_id_RANfunctions_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "E2nodeComponentConfigAddition-List");

                stat = asn1PrtToStr_e2ap_E2nodeComponentConfigAddition_List (pctxt, pvalue->value.u._e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_UNDEF_:
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
// --- End of e2ap_E2setupRequest_protocolIEs_element.c ---

