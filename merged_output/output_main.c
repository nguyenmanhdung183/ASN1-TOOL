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

// --- Begin of e2ap_GNB_CU_UP_ID.c ---
/* e2ap_GNB_CU_UP_ID.c */
#include "e2ap_GNB_CU_UP_ID.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GNB_CU_UP_ID");
   stat = pe_ConsUnsigned (pctxt, value, nan, 68719476735.0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GNB_CU_UP_ID");
   if (pctxt->buffer.aligned) {
      int stat2 = pd_ByteAlign (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 64);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
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
#include "e2ap_GNB_DU_ID.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GNB_DU_ID");
   stat = pe_ConsUnsigned (pctxt, value, nan, 68719476735.0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GNB_DU_ID");
   if (pctxt->buffer.aligned) {
      int stat2 = pd_ByteAlign (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 64);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_GNB_DU_ID (const char* name, e2ap_GNB_DU_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_GNB_DU_ID.c ---

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

// --- Begin of e2ap_ENB_ID_Choice.c ---
/* e2ap_ENB_ID_Choice.c */

// choice
EXTERN int asn1PE_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "ENB_ID_Choice");

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
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb_ID_macro");
         stat = asn1PE_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_macro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb_ID_shortmacro");
         stat = asn1PE_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_shortmacro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb_ID_longmacro");
         stat = asn1PE_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_longmacro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "ENB_ID_Choice");

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
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb_ID_macro");
         pvalue->u.enb_ID_macro = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.enb_ID_macro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_macro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb_ID_shortmacro");
         pvalue->u.enb_ID_shortmacro = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.enb_ID_shortmacro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_shortmacro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb_ID_longmacro");
         pvalue->u.enb_ID_longmacro = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.enb_ID_longmacro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_longmacro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
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
      case 1.0:
         if (pvalue->u.enb_ID_macro) {
            asn1Free_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_macro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb_ID_macro);
         }
         break;
      case 2.0:
         if (pvalue->u.enb_ID_shortmacro) {
            asn1Free_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_shortmacro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb_ID_shortmacro);
         }
         break;
      case 3.0:
         if (pvalue->u.enb_ID_longmacro) {
            asn1Free_e2ap_BIT STRING (pctxt, pvalue->u.enb_ID_longmacro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb_ID_longmacro);
         }
         break;
   }
   pvalue->t = 0;
}
// --- End of e2ap_ENB_ID_Choice.c ---

/******************************************/
/* File .c missing: e2ap_GlobalngeNB_ID.c */
/******************************************/

/****************************************/
/* File .c missing: e2ap_macro_eNB_ID.c */
/****************************************/

/**************************************************/
/* File .c missing: e2ap___________error_______.c */
/**************************************************/

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

// --- Begin of e2ap_NGENB_DU_ID.c ---
/* e2ap_NGENB_DU_ID.c */
#include "e2ap_NGENB_DU_ID.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "NGENB_DU_ID");
   stat = pe_ConsUnsigned (pctxt, value, nan, 68719476735.0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "NGENB_DU_ID");
   if (pctxt->buffer.aligned) {
      int stat2 = pd_ByteAlign (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, 64);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_NGENB_DU_ID (const char* name, e2ap_NGENB_DU_ID* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_NGENB_DU_ID.c ---

/**************************************************/
/* File .c missing: e2ap_GlobalE2node_ng_eNB_ID.c */
/**************************************************/

/***********************************************/
/* File .c missing: e2ap_GlobalE2node_eNB_ID.c */
/***********************************************/

// --- Begin of e2ap_GlobalE2node_ID.c ---
/* e2ap_GlobalE2node_ID.c */

// choice
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
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "gNB");
         stat = asn1PE_e2ap_GlobalGNB_ID (pctxt, pvalue->u.gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "ng_eNB");
         stat = asn1PE_e2ap_GlobalNGeNB_ID (pctxt, pvalue->u.ng_eNB);
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
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "gNB");
         pvalue->u.gNB = rtxMemAllocType (pctxt, e2ap_GlobalGNB_ID);
         if (pvalue->u.gNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_GlobalGNB_ID (pctxt, pvalue->u.gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "ng_eNB");
         pvalue->u.ng_eNB = rtxMemAllocType (pctxt, e2ap_GlobalNGeNB_ID);
         if (pvalue->u.ng_eNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_GlobalNGeNB_ID (pctxt, pvalue->u.ng_eNB);
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
      case 1.0:
         if (pvalue->u.gNB) {
            asn1Free_e2ap_GlobalGNB_ID (pctxt, pvalue->u.gNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gNB);
         }
         break;
      case 2.0:
         if (pvalue->u.ng_eNB) {
            asn1Free_e2ap_GlobalNGeNB_ID (pctxt, pvalue->u.ng_eNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.ng_eNB);
         }
         break;
   }
   pvalue->t = 0;
}
// --- End of e2ap_GlobalE2node_ID.c ---

/*****************************************/
/* File .c missing: e2ap_RANfunctionID.c */
/*****************************************/

// --- Begin of e2ap_RANfunctionDefinition.c ---
/* e2ap_RANfunctionDefinition.c */
#include "e2ap_RANfunctionDefinition.h"
#include "rtxsrc/rtxErrCodes.h"

/* Dynamic OCTET STRING (no SIZE constraint) */
EXTERN int asn1PE_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionDefinition");
   stat = pe_OctetString (pctxt, pvalue->numocts, pvalue->data);
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : 0;
}

EXTERN int asn1PD_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition** ppvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionDefinition");
   stat = pd_DynOctetString (pctxt, (OSDynOctStr**)ppvalue);
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : 0;
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
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringHexStr (name, pvalue->numocts, pvalue->data, buffer, bufSize) < 0)
      return -1;
   return 0;
}
// --- End of e2ap_RANfunctionDefinition.c ---

/***********************************************/
/* File .c missing: e2ap_RANfunctionRevision.c */
/***********************************************/

/*******************************************/
/* File .c missing: e2ap_PrintableString.c */
/*******************************************/

// --- Begin of e2ap_RANfunctionOID.c ---
/* e2ap_RANfunctionOID.c */
#include "e2ap_RANfunctionOID.h"
#include "rtxsrc/rtxErrCodes.h"
#include "rtxsrc/rtxCharStr.h"
#include "rtxsrc/rtxMemBuf.h"

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
      rtxErrAddStrnParm (pctxt, lbuf);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   stat = pe_ConstrainedStringEx (pctxt, value, 0, 8, 7, 7);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID* ppvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunctionOID");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(1000), OSUINTCONST(0), OSUINT32_MAX);

   stat = pd_ConstrainedStringEx (pctxt, ppvalue, 0, 8, 7, 7);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}


void asn1Free_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID pvalue)
{
   if (pvalue) rtxMemFreePtr (pctxt, (void*)pvalue);
}

/* Print to string */
int asn1PrtToStr_e2ap_RANfunctionOID (const char* name, e2ap_RANfunctionOID pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringStr (name, pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_RANfunctionOID.c ---

// --- Begin of e2ap_RANfunction_Item.c ---

int asn1PE_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "RANfunction_Item");

   stat = asn1PE_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_RANfunctionDefinition (pctxt, &pvalue->ranFunctionDefinition);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_RANfunctionOID (pctxt, &pvalue->ranFunctionOID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "RANfunction_Item");

   stat = asn1PD_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_RANfunctionDefinition (pctxt, &pvalue->ranFunctionDefinition);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_RANfunctionOID (pctxt, &pvalue->ranFunctionOID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_RANfunction_Item (e2ap_RANfunction_Item* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_RANfunctionID (&pvalue->ranFunctionID);
   asn1Init_e2ap_RANfunctionDefinition (&pvalue->ranFunctionDefinition);
   asn1Init_e2ap_RANfunctionRevision (&pvalue->ranFunctionRevision);
   asn1Init_e2ap_RANfunctionOID (&pvalue->ranFunctionOID);
}

void asn1Free_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue)
{
   %}
   asn1Free_e2ap_RANfunctionID (pctxt, &pvalue->ranFunctionID);
   %}
   asn1Free_e2ap_RANfunctionDefinition (pctxt, &pvalue->ranFunctionDefinition);
   %}
   asn1Free_e2ap_RANfunctionRevision (pctxt, &pvalue->ranFunctionRevision);
   %}
   asn1Free_e2ap_RANfunctionOID (pctxt, &pvalue->ranFunctionOID);
}
// --- End of e2ap_RANfunction_Item.c ---

// --- Begin of e2ap_RANfunction_ItemIEs.c ---
/* e2ap_RANfunction_ItemIEs.c */
//IE
int asn1PE_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "RANfunction_ItemIEs");

   /* encode id */
   RTXCTXPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_RANfunction_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_RANfunction_ItemIEs_.criticality);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPELEMNAME (pctxt);

   /* encode value */
   RTXCTXPUSHELEMNAME (pctxt, "value");

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
            RTXCTXPUSHELEMNAME (pctxt, "e2ap-E2nodeComponentConfigAddition-Item");
            stat = asn1PE_e2ap_RANfunction-Item (pctxt, &pvalue->value.u_RANfunction_ItemIEs_.value);
            if (stat != 0) return LOG_RTERR (pctxt, stat);
            RTXCTXPOPELEMNAME (pctxt);
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

      RTXCTXPOPELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   /* ... (em có thể gửi đầy đủ nếu anh cần) */
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
/* e2ap_RANfunctions_List.c */

//seq_of_single_container.c

int asn1PE_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   e2ap_RANfunction-ItemIEs* pdata;

   RTXCTXPUSHTYPENAME (pctxt, "RANfunctions_List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(256), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_RANfunction-ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_RANfunction-ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List** ppvalue)
{
   int stat = 0;
   OSSIZE count = 0;
   e2ap_RANfunction-ItemIEs* pdata;

   RTXCTXPUSHTYPENAME (pctxt, "RANfunctions_List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(256), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_RANfunction-ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_RANfunction-ItemIEs (pdata);

      stat = asn1PD_e2ap_RANfunction-ItemIEs (pctxt, pdata);
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
   rtxDListInit (pvalue);
}

void asn1Free_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List* pvalue)
{
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_RANfunction-ItemIEs* pdata = (e2ap_RANfunction-ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_RANfunction-ItemIEs (pctxt, pdata);
         rtxMemFreePtr (pctxt, pdata);
      }
      pnode = pnode->next;
   }
   rtxDListFreeAll (pvalue);
}
// --- End of e2ap_RANfunctions_List.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceType.c ---
/* e2ap_E2nodeComponentInterfaceType.c */
#include "e2ap_E2nodeComponentInterfaceType.h"
#include "rtxsrc/rtxErrCodes.h"

const OSEnumItem e2ap_E2nodeComponentInterfaceType_ENUMTAB[e2ap_E2nodeComponentInterfaceType_ENUMTABSIZE] = {
   { OSUTF8("ng"), 0, 2,  },   { OSUTF8("xn"), 1, 2,  },   { OSUTF8("e1"), 2, 2,  },   { OSUTF8("f1"), 3, 2,  },   { OSUTF8("w1"), 4, 2,  },   { OSUTF8("s1"), 5, 2,  },   { OSUTF8("x2"), 6, 2,  }};

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceType value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentInterfaceType");
   if (value >= 7) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST(6));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceType* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentInterfaceType");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST(6));
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : stat;
}

EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceType (const char* name, e2ap_E2nodeComponentInterfaceType* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   const char* enumStr = "???";
   if (*pvalue < e2ap_E2nodeComponentInterfaceType_ENUMTABSIZE) {
      enumStr = (const char*)e2ap_E2nodeComponentInterfaceType_ENUMTAB[*pvalue].name;
   }
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   stat = rtPrintToString (" = %s\n", enumStr, buffer, bufSize);
   return (stat < 0) ? -1 : 0;
}
// --- End of e2ap_E2nodeComponentInterfaceType.c ---

// --- Begin of e2ap_AMFName.c ---
/* e2ap_AMFName.c */
#include "e2ap_AMFName.h"
#include "rtxsrc/rtxErrCodes.h"
#include "rtxsrc/rtxCharStr.h"
#include "rtxsrc/rtxMemBuf.h"

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
      rtxErrAddStrnParm (pctxt, lbuf);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   stat = pe_ConstrainedStringEx (pctxt, value, 0, 8, 7, 7);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName* ppvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "AMFName");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(150), OSUINTCONST(0), OSUINT32_MAX);

   stat = pd_ConstrainedStringEx (pctxt, ppvalue, 0, 8, 7, 7);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}


void asn1Free_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName pvalue)
{
   if (pvalue) rtxMemFreePtr (pctxt, (void*)pvalue);
}

/* Print to string */
int asn1PrtToStr_e2ap_AMFName (const char* name, e2ap_AMFName pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringStr (name, pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
// --- End of e2ap_AMFName.c ---

/******************************************************/
/* File .c missing: e2ap_E2nodeComponentInterfaceNG.c */
/******************************************************/

/***********************************************/
/* File .c missing: e2ap_GlobalNG_RANNode_ID.c */
/***********************************************/

/******************************************************/
/* File .c missing: e2ap_E2nodeComponentInterfaceXn.c */
/******************************************************/

/******************************************************/
/* File .c missing: e2ap_E2nodeComponentInterfaceE1.c */
/******************************************************/

/******************************************************/
/* File .c missing: e2ap_E2nodeComponentInterfaceF1.c */
/******************************************************/

/******************************************************/
/* File .c missing: e2ap_E2nodeComponentInterfaceW1.c */
/******************************************************/

/***********************************/
/* File .c missing: e2ap_MMEname.c */
/***********************************/

// --- Begin of e2ap_E2nodeComponentInterfaceS1.c ---

int asn1PE_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceS1");

   stat = asn1PE_e2ap_MMEname (pctxt, &pvalue->mme_name );
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceS1");

   stat = asn1PD_e2ap_MMEname (pctxt, &pvalue->mme_name );
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentInterfaceS1 (e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_MMEname (&pvalue->mme_name );
}

void asn1Free_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   %}
   asn1Free_e2ap_MMEname (pctxt, &pvalue->mme_name );
}
// --- End of e2ap_E2nodeComponentInterfaceS1.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceX2.c ---

int asn1PE_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceX2");

   stat = asn1PE_e2ap_GlobalENB-ID (pctxt, &pvalue->global_eNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global_en_gNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceX2");

   stat = asn1PD_e2ap_GlobalENB-ID (pctxt, &pvalue->global_eNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global_en_gNB_ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentInterfaceX2 (e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_GlobalENB-ID (&pvalue->global_eNB_ID);
   asn1Init_e2ap_GlobalenGNB-ID (&pvalue->global_en_gNB_ID);
}

void asn1Free_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   %}
   asn1Free_e2ap_GlobalENB-ID (pctxt, &pvalue->global_eNB_ID);
   %}
   asn1Free_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global_en_gNB_ID);
}
// --- End of e2ap_E2nodeComponentInterfaceX2.c ---

/*********************************************/
/* File .c missing: e2ap_E2nodeComponentID.c */
/*********************************************/

/******************************************************/
/* File .c missing: e2ap_e2nodeComponentRequestPart.c */
/******************************************************/

/*******************************************************/
/* File .c missing: e2ap_e2nodeComponentResponsePart.c */
/*******************************************************/

/********************************************************/
/* File .c missing: e2ap_E2nodeComponentConfiguration.c */
/********************************************************/

// --- Begin of e2ap_E2nodeComponentConfigAddition_Item.c ---

int asn1PE_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigAddition_Item");

   stat = asn1PE_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_E2nodeComponentConfiguration (pctxt, &pvalue->e2nodeComponentConfiguration);
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigAddition_Item");

   stat = asn1PD_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_E2nodeComponentConfiguration (pctxt, &pvalue->e2nodeComponentConfiguration);
   if (stat != 0) return LOG_RTERR(pctxt, stat);


   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigAddition_Item (e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_E2nodeComponentInterfaceType (&pvalue->e2nodeComponentInterfaceType);
   asn1Init_e2ap_E2nodeComponentID (&pvalue->e2nodeComponentID);
   asn1Init_e2ap_E2nodeComponentConfiguration (&pvalue->e2nodeComponentConfiguration);
}

void asn1Free_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   %}
   asn1Free_e2ap_E2nodeComponentInterfaceType (pctxt, &pvalue->e2nodeComponentInterfaceType);
   %}
   asn1Free_e2ap_E2nodeComponentID (pctxt, &pvalue->e2nodeComponentID);
   %}
   asn1Free_e2ap_E2nodeComponentConfiguration (pctxt, &pvalue->e2nodeComponentConfiguration);
}
// --- End of e2ap_E2nodeComponentConfigAddition_Item.c ---

// --- Begin of e2ap_E2nodeComponentConfigAddition_ItemIEs.c ---
/* e2ap_E2nodeComponentConfigAddition_ItemIEs.c */
//IE
int asn1PE_e2ap_E2nodeComponentConfigAddition_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentConfigAddition_ItemIEs");

   /* encode id */
   RTXCTXPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_E2nodeComponentConfigAddition_ItemIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_E2nodeComponentConfigAddition_ItemIEs_.criticality);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPELEMNAME (pctxt);

   /* encode value */
   RTXCTXPUSHELEMNAME (pctxt, "value");

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
            RTXCTXPUSHELEMNAME (pctxt, "e2ap-E2nodeComponentConfigAddition-Item");
            stat = asn1PE_e2ap_E2nodeComponentConfigAddition-Item (pctxt, &pvalue->value.u_E2nodeComponentConfigAddition_ItemIEs_.value);
            if (stat != 0) return LOG_RTERR (pctxt, stat);
            RTXCTXPOPELEMNAME (pctxt);
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

      RTXCTXPOPELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigAddition_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   /* ... (em có thể gửi đầy đủ nếu anh cần) */
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
/* e2ap_E2nodeComponentConfigAddition_List.c */

//seq_of_single_container.c

int asn1PE_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* pvalue)
{
   int stat = 0;
   OSRTDListNode* pnode;
   e2ap_E2nodeComponentConfigAddition-ItemIEs* pdata;

   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentConfigAddition_List");

   /* encode length determinant */
   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(256), 0, 0);

   stat = pe_Length (pctxt, pvalue->count);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   /* encode elements */
   pnode = pvalue->head;
   for (xx1 = 0; pnode != 0 && xx1 < pvalue->count; pnode = pnode->next, xx1++) {
      pdata = (e2ap_E2nodeComponentConfigAddition-ItemIEs*) pnode->data;
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      stat = asn1PE_e2ap_E2nodeComponentConfigAddition-ItemIEs (pctxt, pdata);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      xx1++;
      RTXCTXPPOPARRAYELEMNAME (pctxt);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List** ppvalue)
{
   int stat = 0;
   OSSIZE count = 0;
   e2ap_E2nodeComponentConfigAddition-ItemIEs* pdata;

   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentConfigAddition_List");

   PU_SETSIZECONSTRAINT (pctxt, OSUINTCONST(1), OSUINTCONST(256), 0, 0);

   stat = pd_Length64 (pctxt, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   rtxDListInit (ppvalue);

   for (xx1 = 0; xx1 < count; xx1++) {
      RTXCTXPUSHARRAYELEMNAME (pctxt, "SEQUENCE", xx1);

      pdata = rtxMemAllocType (pctxt, e2ap_E2nodeComponentConfigAddition-ItemIEs);
      if (!pdata) return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_e2ap_E2nodeComponentConfigAddition-ItemIEs (pdata);

      stat = asn1PD_e2ap_E2nodeComponentConfigAddition-ItemIEs (pctxt, pdata);
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
   rtxDListInit (pvalue);
}

void asn1Free_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* pvalue)
{
   OSRTDListNode* pnode = pvalue->head;
   while (pnode) {
      e2ap_E2nodeComponentConfigAddition-ItemIEs* pdata = (e2ap_E2nodeComponentConfigAddition-ItemIEs*) pnode->data;
      if (pdata) {
         asn1Free_e2ap_E2nodeComponentConfigAddition-ItemIEs (pctxt, pdata);
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

