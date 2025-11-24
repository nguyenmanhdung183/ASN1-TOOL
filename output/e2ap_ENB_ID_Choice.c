/* e2ap_ENB_ID_Choice.c */

/*****************************************/
/*           ENB_ID_Choice                */
/*****************************************/
// choice


// Các nội dung cần thiết từ template choice.c.j2

    // Nội dung của file .c cho primitive BIT STRING (SIZE(20)
    /* bitstring intergrate header file */
    // Nội dung của file .c cho primitive BIT STRING (SIZE(18)
    /* bitstring intergrate header file */
    // Nội dung của file .c cho primitive BIT STRING (SIZE(21)
    /* bitstring intergrate header file */

// Các phần còn lại của template choice.c.j2


// choice without extension

EXTERN int asn1PE_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue)
{
   int stat = 0;
   RTXCTXTPUSHTYPENAME (pctxt, "ENB-ID-Choice");
   RTXCTXTPUSHELEMNAME (pctxt, "t");
 
   stat = rtxEncBits (pctxt, pvalue->t - 1, 2);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXTPOPELEMNAME (pctxt);

   switch (pvalue->t) {
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "enb-ID-macro");

         //primitive BIT STRING

         stat = asn1PE_e2ap_ENB_ID_Choice_enb_ID_macro (pctxt, pvalue->u.enb_ID_macro);// primitive

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXTPUSHELEMNAME (pctxt, "enb-ID-shortmacro");

         //primitive BIT STRING

         stat = asn1PE_e2ap_ENB_ID_Choice_enb_ID_shortmacro (pctxt, pvalue->u.enb_ID_shortmacro);// primitive

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXTPUSHELEMNAME (pctxt, "enb-ID-longmacro");

         //primitive BIT STRING

         stat = asn1PE_e2ap_ENB_ID_Choice_enb_ID_longmacro (pctxt, pvalue->u.enb_ID_longmacro);// primitive

         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXTPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PD_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   RTXCTXTPUSHTYPENAME (pctxt, "ENB-ID-Choice");

 
   stat = rtxDecBits (pctxt, &ui, 2);// kha nang la numbits
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   else pvalue->t = ui + 1;
   //RTXCTXTPOPELEMNAME (pctxt);

   switch (ui) {
      case 0:
         RTXCTXTPUSHELEMNAME (pctxt, "enb-ID-macro");

         pvalue->u.enb_ID_macro = rtxMemAllocType (pctxt, e2ap_BIT STRING (SIZE(20));

         if (pvalue->u.enb_ID_macro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(), OSUINTCONST(), 0, 0);
         //primitive BIT STRING
         //stat = pd_BitString32 (pctxt, pvalue->u.enb_ID_macro, OSUINTCONST(), OSUINTCONST());
         stat = asn1PD_e2ap_ENB_ID_Choice_enb_ID_macro(pctxt, pvalue->u.enb_ID_macro, OSUINTCONST(), OSUINTCONST());
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXTPUSHELEMNAME (pctxt, "enb-ID-shortmacro");

         pvalue->u.enb_ID_shortmacro = rtxMemAllocType (pctxt, e2ap_BIT STRING (SIZE(18));

         if (pvalue->u.enb_ID_shortmacro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(), OSUINTCONST(), 0, 0);
         //primitive BIT STRING
         //stat = pd_BitString32 (pctxt, pvalue->u.enb_ID_shortmacro, OSUINTCONST(), OSUINTCONST());
         stat = asn1PD_e2ap_ENB_ID_Choice_enb_ID_shortmacro(pctxt, pvalue->u.enb_ID_shortmacro, OSUINTCONST(), OSUINTCONST());
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXTPUSHELEMNAME (pctxt, "enb-ID-longmacro");

         pvalue->u.enb_ID_longmacro = rtxMemAllocType (pctxt, e2ap_BIT STRING (SIZE(21));

         if (pvalue->u.enb_ID_longmacro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);

         PU_SETSIZECONSTRAINT(pctxt, OSUINTCONST(), OSUINTCONST(), 0, 0);
         //primitive BIT STRING
         //stat = pd_BitString32 (pctxt, pvalue->u.enb_ID_longmacro, OSUINTCONST(), OSUINTCONST());
         stat = asn1PD_e2ap_ENB_ID_Choice_enb_ID_longmacro(pctxt, pvalue->u.enb_ID_longmacro, OSUINTCONST(), OSUINTCONST());
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXTPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXTPOPTYPENAME (pctxt);
   return (stat);
}

int asn1PrtToStr_e2ap_ENB_ID_Choice (const char* name, e2ap_ENB_ID_Choice* pvalue, char* buffer, OSSIZE bufSize)
{
   if(rtPrintToStringOpenBrace(name, buffer, bufSize) < 0) return -1;
   

   switch (pvalue->t) {
      case T_e2ap_ENB_ID_Choice_enb_ID_macro:
         //primitive BIT STRING
         if (asn1PrtToStr_e2ap_ENB_ID_Choice_enb_ID_macro ( "enb_ID_macro", pvalue->u.enb_ID_macro, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_ENB_ID_Choice_enb_ID_shortmacro:
         //primitive BIT STRING
         if (asn1PrtToStr_e2ap_ENB_ID_Choice_enb_ID_shortmacro ( "enb_ID_shortmacro", pvalue->u.enb_ID_shortmacro, buffer, bufSize) < 0) return -1;
         break;
      case T_e2ap_ENB_ID_Choice_enb_ID_longmacro:
         //primitive BIT STRING
         if (asn1PrtToStr_e2ap_ENB_ID_Choice_enb_ID_longmacro ( "enb_ID_longmacro", pvalue->u.enb_ID_longmacro, buffer, bufSize) < 0) return -1;
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
            //primitive BIT STRING
            asn1Free_e2ap_ENB_ID_Choice_enb_ID_macro (pctxt, pvalue->u.enb_ID_macro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb_ID_macro);
            pvalue->u.enb_ID_macro = 0;
         }
         break;
      case 2:
         if (pvalue->u.enb_ID_shortmacro) {
            //primitive BIT STRING
            asn1Free_e2ap_ENB_ID_Choice_enb_ID_shortmacro (pctxt, pvalue->u.enb_ID_shortmacro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb_ID_shortmacro);
            pvalue->u.enb_ID_shortmacro = 0;
         }
         break;
      case 3:
         if (pvalue->u.enb_ID_longmacro) {
            //primitive BIT STRING
            asn1Free_e2ap_ENB_ID_Choice_enb_ID_longmacro (pctxt, pvalue->u.enb_ID_longmacro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb_ID_longmacro);
            pvalue->u.enb_ID_longmacro = 0;
         }
         break;
   }
}

