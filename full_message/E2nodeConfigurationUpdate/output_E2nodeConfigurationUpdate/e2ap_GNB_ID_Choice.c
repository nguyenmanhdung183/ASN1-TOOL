/* e2ap_GNB_ID_Choice.c */

/*****************************************/
/*           GNB_ID_Choice                */
/*****************************************/
// choice

// choice without extension

EXTERN int asn1PE_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "GNB-ID-Choice");
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

   RTXCTXTPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PD_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   RTXCTXTPUSHTYPENAME (pctxt, "GNB-ID-Choice");

 
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

   RTXCTXTPOPTYPENAME (pctxt);
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
            //asn1Free_ASN1BitStr32 (pctxt, pvalue->u.gnb_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gnb_ID);
            pvalue->u.gnb_ID = 0;
         }
         break;
   }
}

