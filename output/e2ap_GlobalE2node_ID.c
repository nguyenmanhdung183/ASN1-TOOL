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

