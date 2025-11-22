/* e2ap_ENGNB_ID.c */

/*****************************************/
/*           ENGNB_ID                */
/*****************************************/
// choice

// choice without extension

EXTERN int asn1PE_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "ENGNB-ID");
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

   RTXCTXTPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PD_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   RTXCTXTPUSHTYPENAME (pctxt, "ENGNB-ID");

 
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

   RTXCTXTPOPTYPENAME (pctxt);
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
            //asn1Free_ASN1BitStr32 (pctxt, pvalue->u.gNB_ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gNB_ID);
            pvalue->u.gNB_ID = 0;
         }
         break;
   }
}

