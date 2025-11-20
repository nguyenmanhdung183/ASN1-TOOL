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

