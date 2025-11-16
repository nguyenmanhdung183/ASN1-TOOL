// --- Begin of e2ap_TransactionID.c ---
/* e2ap_TransactionID.c */
#include "e2ap_TransactionID.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value)
{
   RTXCTXPUSHTYPENAME (pctxt, "TransactionID");
   OSBOOL exbit = (value > 255.0) ? TRUE : FALSE;
   int stat = rtxEncBit (pctxt, exbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!exbit) {
      stat = pe_ConsUnsigned (pctxt, value, 0.0, 255.0);
   } else {
      stat = pe_UnconsUnsigned (pctxt, value);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
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
      stat = pd_ConsUnsigned (pctxt, pvalue, 0.0, 255.0);
   } else {
      stat = pd_UnconsUnsigned (pctxt, pvalue);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
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
#include "e2ap_PLMN_Identity.h"
#include "rtxsrc/rtxErrCodes.h"

/* Fixed SIZE OCTET STRING */
EXTERN int asn1PE_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "PLMN_Identity");
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(3), OSUINTCONST(3), 0, 0);
   stat = pe_OctetString (pctxt, pvalue->numocts, pvalue->data);
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : 0;
}

EXTERN int asn1PD_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "PLMN_Identity");
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(3), OSUINTCONST(3), 0, 0);
   stat = pd_OctetString (pctxt, &pvalue->numocts, pvalue->data, sizeof(pvalue->data));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : 0;
}

int asn1Init_e2ap_PLMN_Identity (e2ap_PLMN_Identity* pvalue)
{
   if (pvalue == 0) return RTERR_NULLPTR;
   pvalue->numocts = 0;
   return 0;
}

void asn1Free_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue)
{
   /* Không cần free vì data nằm trong struct */
   if (pvalue) pvalue->numocts = 0;
}

/* Print to string */
int asn1PrtToStr_e2ap_PLMN_Identity (const char* name, e2ap_PLMN_Identity* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringHexStr (name, pvalue->numocts, pvalue->data, buffer, bufSize) < 0)
      return -1;
   return 0;
}
// --- End of e2ap_PLMN_Identity.c ---

/**********************************/
/* File .c missing: e2ap_gnb_ID.c */
/**********************************/

/*****************************************/
/* File .c missing: e2ap_GNB_ID_Choice.c */
/*****************************************/

/****************************************/
/* File .c missing: e2ap_GlobalgNB_ID.c */
/****************************************/

/**********************************/
/* File .c missing: e2ap_gNB_ID.c */
/**********************************/

/************************************/
/* File .c missing: e2ap_ENGNB_ID.c */
/************************************/

/******************************************/
/* File .c missing: e2ap_GlobalenGNB_ID.c */
/******************************************/

/****************************************/
/* File .c missing: e2ap_GNB_CU_UP_ID.c */
/****************************************/

/*************************************/
/* File .c missing: e2ap_GNB_DU_ID.c */
/*************************************/

/***********************************************/
/* File .c missing: e2ap_GlobalE2node_gNB_ID.c */
/***********************************************/

/**************************************************/
/* File .c missing: e2ap_GlobalE2node_en_gNB_ID.c */
/**************************************************/

/****************************************/
/* File .c missing: e2ap_enb_ID_macro.c */
/****************************************/

/*********************************************/
/* File .c missing: e2ap_enb_ID_shortmacro.c */
/*********************************************/

/********************************************/
/* File .c missing: e2ap_enb_ID_longmacro.c */
/********************************************/

/*****************************************/
/* File .c missing: e2ap_ENB_ID_Choice.c */
/*****************************************/

/******************************************/
/* File .c missing: e2ap_GlobalngeNB_ID.c */
/******************************************/

/****************************************/
/* File .c missing: e2ap_macro_eNB_ID.c */
/****************************************/

/*****************************/
/* File .c missing: e2ap_©.c */
/*****************************/

/**********************************************/
/* File .c missing: e2ap_short_Macro_eNB_ID.c */
/**********************************************/

/*********************************************/
/* File .c missing: e2ap_long_Macro_eNB_ID.c */
/*********************************************/

/**********************************/
/* File .c missing: e2ap_ENB_ID.c */
/**********************************/

/****************************************/
/* File .c missing: e2ap_GlobalENB_ID.c */
/****************************************/

/***************************************/
/* File .c missing: e2ap_NGENB_DU_ID.c */
/***************************************/

/**************************************************/
/* File .c missing: e2ap_GlobalE2node_ng_eNB_ID.c */
/**************************************************/

/***********************************************/
/* File .c missing: e2ap_GlobalE2node_eNB_ID.c */
/***********************************************/

// --- Begin of e2ap_GlobalE2node_ID.c ---
/* e2ap_GlobalE2node_ID.c */
#include "e2ap_GlobalE2node_ID.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "GlobalE2node_ID");

   extbit = (OSBOOL)(pvalue->t > 3);
   stat = rtxEncBit (pctxt, extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   if (extbit) {
      stat = pe_SmallNonNegWholeNumber (pctxt, pvalue->t - 4);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   } else {
      stat = rtxEncBits (pctxt, pvalue->t - 1, 2);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   switch (pvalue->t) {
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "gNB");
         pvalue->u.gNB = rtxMemAllocType (pctxt, e2ap_GlobalGNB_ID);
         if (pvalue->u.gNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_GlobalGNB_ID (pvalue->u.gNB);
         stat = asn1PE_e2ap_GlobalGNB_ID (pctxt, pvalue->u.gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "GlobalE2node_ID");

   stat = rtxDecBit (pctxt, &extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   if (extbit) {
      stat = pd_SmallNonNegWholeNumber (pctxt, &ui);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      pvalue->t = ui + 4;
   } else {
      pvalue->t = ui + 1;
   }

   switch (pvalue->t) {
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "gNB");
         pvalue->u.gNB = rtxMemAllocType (pctxt, e2ap_GlobalGNB_ID);
         if (pvalue->u.gNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_GlobalGNB_ID (pvalue->u.gNB);
         stat = asn1PD_e2ap_GlobalGNB_ID (pctxt, pvalue->u.gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
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
      case 1:
         if (pvalue->u.gNB) {
            asn1Free_e2ap_GlobalGNB_ID (pctxt, pvalue->u.gNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gNB);
         }
         break;
   }
   pvalue->t = 0;
}
// --- End of e2ap_GlobalE2node_ID.c ---

/*********************************************/
/* File .c missing: e2ap_RANfunctions_List.c */
/*********************************************/

/************************************/
/* File .c missing: e2ap_SEQUENCE.c */
/************************************/

/**************************************************************/
/* File .c missing: e2ap_E2nodeComponentConfigAddition_List.c */
/**************************************************************/

/*********************************************/
/* File .c missing: e2ap_E2setupRequestIEs.c */
/*********************************************/

// --- Begin of e2ap_E2setupRequest.c ---
/* e2ap_E2SetupRequest.c */
#include "e2ap_E2SetupRequest.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue)
{
   RTXCTXPUSHTYPENAME (pctxt, "E2SetupRequest");
   int stat = asn1PE_e2ap_E2SetupRequest_protocolIEs_Container (pctxt, &pvalue->protocolIEs);
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : 0;
}

EXTERN int asn1PE_e2ap_E2SetupRequest_protocolIEs_Container (OSCTXT* pctxt, const e2ap_E2SetupRequest_protocolIEs_Container* pList)
{
   int i, stat;
   RTXCTXPUSHTYPENAME (pctxt, "E2SetupRequest-protocolIEs");

   stat = rtxEncLengthDeterminant (pctxt, pList->n);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   for (i = 0; i < pList->n; i++) {
      stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, pList->elem[i].id);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      stat = asn1PE_e2ap_Criticality (pctxt, pList->elem[i].criticality);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      stat = rtxEncOpenTypeStart (pctxt);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      switch (pList->elem[i].id) {
         case ID_id_TransactionID:
            stat = asn1PE_e2ap_TransactionID (pctxt, &pList->elem[i].value.transactionID);
            break;
         case ID_id_GlobalE2node_ID:
            stat = asn1PE_e2ap_GlobalE2node_ID (pctxt, &pList->elem[i].value.globalE2node_ID);
            break;
         case ID_id_RANfunctionsAdded:
            stat = asn1PE_e2ap_RANfunctions_List (pctxt, &pList->elem[i].value.rANfunctionsAdded);
            break;
         case ID_id_E2nodeComponentConfigAddition:
            stat = asn1PE_e2ap_E2nodeComponentConfigAddition_List (pctxt, &pList->elem[i].value.e2nodeComponentConfigAddition);
            break;
         default:
            return LOG_RTERR (pctxt, RTERR_INVOPT);
      }
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      stat = rtxEncOpenTypeEnd (pctxt);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}
// --- End of e2ap_E2setupRequest.c ---

