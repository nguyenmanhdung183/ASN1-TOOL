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

