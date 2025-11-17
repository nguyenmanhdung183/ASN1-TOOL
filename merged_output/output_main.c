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

/*****************************************/
/* File .c missing: e2ap_GNB_ID_Choice.c */
/*****************************************/

/****************************************/
/* File .c missing: e2ap_GlobalgNB_ID.c */
/****************************************/

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
#include "e2ap_ENB_ID_Choice.h"
#include "rtxsrc/rtxErrCodes.h"

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
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "enb-ID-macro");
         pvalue->u.enb-ID-macro = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.enb-ID-macro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_BIT STRING (pvalue->u.enb-ID-macro);
         stat = asn1PE_e2ap_BIT STRING (pctxt, pvalue->u.enb-ID-macro);
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
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "enb-ID-macro");
         pvalue->u.enb-ID-macro = rtxMemAllocType (pctxt, e2ap_BIT STRING);
         if (pvalue->u.enb-ID-macro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         asn1Init_e2ap_BIT STRING (pvalue->u.enb-ID-macro);
         stat = asn1PD_e2ap_BIT STRING (pctxt, pvalue->u.enb-ID-macro);
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
      case 1:
         if (pvalue->u.enb-ID-macro) {
            asn1Free_e2ap_BIT STRING (pctxt, pvalue->u.enb-ID-macro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb-ID-macro);
         }
         break;
   }
   pvalue->t = 0;
}
// --- End of e2ap_ENB_ID_Choice.c ---

/******************************************/
/* File .c missing: e2ap_GlobalngeNB_ID.c */
/******************************************/

/****************************************/
/* File .c missing: e2ap_macro_eNB_ID.c */
/****************************************/

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

/********************************************/
/* File .c missing: e2ap_RANfunction_Item.c */
/********************************************/

/***********************************************/
/* File .c missing: e2ap_RANfunction_ItemIEs.c */
/***********************************************/

/*********************************************/
/* File .c missing: e2ap_RANfunctions_List.c */
/*********************************************/

/********************************************************/
/* File .c missing: e2ap_E2nodeComponentInterfaceType.c */
/********************************************************/

/***********************************/
/* File .c missing: e2ap_AMFName.c */
/***********************************/

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

/******************************************************/
/* File .c missing: e2ap_E2nodeComponentInterfaceS1.c */
/******************************************************/

/******************************************************/
/* File .c missing: e2ap_E2nodeComponentInterfaceX2.c */
/******************************************************/

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
#include "e2ap_E2nodeComponentConfigAddition_Item.h"
#include "rtxsrc/rtxErrCodes.h"

int asn1PE_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigAddition_Item");



   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfigAddition_Item");



   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfigAddition_Item (e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
}

void asn1Free_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue)
{
}
// --- End of e2ap_E2nodeComponentConfigAddition_Item.c ---

/*****************************************************************/
/* File .c missing: e2ap_E2nodeComponentConfigAddition_ItemIEs.c */
/*****************************************************************/

/**************************************************************/
/* File .c missing: e2ap_E2nodeComponentConfigAddition_List.c */
/**************************************************************/

/*********************************************/
/* File .c missing: e2ap_E2setupRequestIEs.c */
/*********************************************/

// --- Begin of e2ap_E2setupRequest.c ---
#include "e2ap_E2SetupRequest.h"
#include "rtxsrc/rtxErrCodes.h"

int asn1PE_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2SetupRequest");



   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2SetupRequest");



   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2SetupRequest (e2ap_E2SetupRequest* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
}

void asn1Free_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue)
{
}
// --- End of e2ap_E2setupRequest.c ---

