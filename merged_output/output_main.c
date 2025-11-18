// --- Begin of e2ap_TransactionID.c ---
/* e2ap_TransactionID.c */



//interger with ext
/*****************************************/
/*           TransactionID                */
/*****************************************/


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


//octet string

/*****************************************/
/*           PLMN_Identity                */
/*****************************************/

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

// --- Begin of e2ap_GNB_ID_Choice.c ---
/* e2ap_GNB_ID_Choice.c */

// choice

/*****************************************/
/*           GNB_ID_Choice                */
/*****************************************/


EXTERN int asn1PE_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "GNB-ID-Choice");

   extbit = (OSBOOL)(pvalue->t > 0);
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
      case 0:
         RTXCTXPUSHELEMNAME (pctxt, "gnb-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.gnb-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "GNB_ID_Choice");

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
      case 0.0:
         RTXCTXPUSHELEMNAME (pctxt, "gnb-ID");
         pvalue->u.gnb-ID = rtxMemAllocType (pctxt, ASN1BitStr32);
         if (pvalue->u.gnb-ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.gnb-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
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
      case 0.0:
         if (pvalue->u.gnb-ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.gnb-ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gnb-ID);
         }
         break;
   }
   pvalue->t = 0;
}
// --- End of e2ap_GNB_ID_Choice.c ---

// --- Begin of e2ap_GlobalgNB_ID.c ---

/*****************************************/
/*           GlobalgNB_ID                */
/*****************************************/


int asn1PE_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalgNB_ID");

   stat = asn1PE_e2ap_PLMN-Identity (pctxt, &pvalue->plmn-id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_GNB-ID-Choice (pctxt, &pvalue->gnb-id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalgNB_ID");

   stat = asn1PD_e2ap_PLMN-Identity (pctxt, &pvalue->plmn-id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_GNB-ID-Choice (pctxt, &pvalue->gnb-id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_GlobalgNB_ID (e2ap_GlobalgNB_ID* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_PLMN-Identity (&pvalue->plmn-id);
   asn1Init_e2ap_GNB-ID-Choice (&pvalue->gnb-id);
}

void asn1Free_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue)
{
   %}
   asn1Free_e2ap_PLMN-Identity (pctxt, &pvalue->plmn-id);
   %}
   asn1Free_e2ap_GNB-ID-Choice (pctxt, &pvalue->gnb-id);
}
// --- End of e2ap_GlobalgNB_ID.c ---

/**********************************/
/* File .c missing: e2ap_gNB_ID.c */
/**********************************/

// --- Begin of e2ap_ENGNB_ID.c ---
/* e2ap_ENGNB_ID.c */

// choice

/*****************************************/
/*           ENGNB_ID                */
/*****************************************/


EXTERN int asn1PE_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "ENGNB-ID");

   extbit = (OSBOOL)(pvalue->t > 0);
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
      case 0:
         RTXCTXPUSHELEMNAME (pctxt, "gNB-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.gNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "ENGNB_ID");

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
      case 0.0:
         RTXCTXPUSHELEMNAME (pctxt, "gNB-ID");
         pvalue->u.gNB-ID = rtxMemAllocType (pctxt, ASN1BitStr32);
         if (pvalue->u.gNB-ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.gNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
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
      case 0.0:
         if (pvalue->u.gNB-ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.gNB-ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gNB-ID);
         }
         break;
   }
   pvalue->t = 0;
}
// --- End of e2ap_ENGNB_ID.c ---

// --- Begin of e2ap_GlobalenGNB_ID.c ---

/*****************************************/
/*           GlobalenGNB_ID                */
/*****************************************/


int asn1PE_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalenGNB_ID");

   stat = asn1PE_e2ap_PLMN-Identity (pctxt, &pvalue->pLMN-Identity);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_ENGNB-ID (pctxt, &pvalue->gNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalenGNB_ID");

   stat = asn1PD_e2ap_PLMN-Identity (pctxt, &pvalue->pLMN-Identity);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_ENGNB-ID (pctxt, &pvalue->gNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_GlobalenGNB_ID (e2ap_GlobalenGNB_ID* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_PLMN-Identity (&pvalue->pLMN-Identity);
   asn1Init_e2ap_ENGNB-ID (&pvalue->gNB-ID);
}

void asn1Free_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue)
{
   %}
   asn1Free_e2ap_PLMN-Identity (pctxt, &pvalue->pLMN-Identity);
   %}
   asn1Free_e2ap_ENGNB-ID (pctxt, &pvalue->gNB-ID);
}
// --- End of e2ap_GlobalenGNB_ID.c ---

// --- Begin of e2ap_GNB_CU_UP_ID.c ---
/* e2ap_GNB_CU_UP_ID.c */


//interger no ext
/*****************************************/
/*           GNB_CU_UP_ID                */
/*****************************************/

EXTERN int asn1PE_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GNB_CU_UP_ID");
   stat = pe_ConsUnsigned (pctxt, value, 0.0, 68719476735.0);
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


//interger no ext
/*****************************************/
/*           GNB_DU_ID                */
/*****************************************/

EXTERN int asn1PE_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "GNB_DU_ID");
   stat = pe_ConsUnsigned (pctxt, value, 0.0, 68719476735.0);
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

// --- Begin of e2ap_GlobalE2node_gNB_ID.c ---

/*****************************************/
/*           GlobalE2node_gNB_ID                */
/*****************************************/


int asn1PE_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node_gNB_ID");

   stat = asn1PE_e2ap_GlobalgNB-ID (pctxt, &pvalue->global-gNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (pvalue->m_global-en-gNB-IDPresent) {
   stat = asn1PE_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_gNB-CU-UP-IDPresent) {
   stat = asn1PE_e2ap_GNB-CU-UP-ID (pctxt, &pvalue->gNB-CU-UP-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_gNB-DU-IDPresent) {
   stat = asn1PE_e2ap_GNB-DU-ID (pctxt, &pvalue->gNB-DU-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node_gNB_ID");

   stat = asn1PD_e2ap_GlobalgNB-ID (pctxt, &pvalue->global-gNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_global-en-gNB-IDPresent = TRUE;
      stat = asn1PD_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_global-en-gNB-IDPresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_gNB-CU-UP-IDPresent = TRUE;
      stat = asn1PD_e2ap_GNB-CU-UP-ID (pctxt, &pvalue->gNB-CU-UP-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_gNB-CU-UP-IDPresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_gNB-DU-IDPresent = TRUE;
      stat = asn1PD_e2ap_GNB-DU-ID (pctxt, &pvalue->gNB-DU-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_gNB-DU-IDPresent = FALSE;

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_GlobalE2node_gNB_ID (e2ap_GlobalE2node_gNB_ID* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_GlobalgNB-ID (&pvalue->global-gNB-ID);
   asn1Init_e2ap_GlobalenGNB-ID (&pvalue->global-en-gNB-ID);
   asn1Init_e2ap_GNB-CU-UP-ID (&pvalue->gNB-CU-UP-ID);
   asn1Init_e2ap_GNB-DU-ID (&pvalue->gNB-DU-ID);
}

void asn1Free_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue)
{
   %}
   asn1Free_e2ap_GlobalgNB-ID (pctxt, &pvalue->global-gNB-ID);
   %}
   asn1Free_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
   %}
   asn1Free_e2ap_GNB-CU-UP-ID (pctxt, &pvalue->gNB-CU-UP-ID);
   %}
   asn1Free_e2ap_GNB-DU-ID (pctxt, &pvalue->gNB-DU-ID);
}
// --- End of e2ap_GlobalE2node_gNB_ID.c ---

// --- Begin of e2ap_GlobalE2node_en_gNB_ID.c ---

/*****************************************/
/*           GlobalE2node_en_gNB_ID                */
/*****************************************/


int asn1PE_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node_en_gNB_ID");

   stat = asn1PE_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (pvalue->m_en-gNB-CU-UP-IDPresent) {
   stat = asn1PE_e2ap_GNB-CU-UP-ID (pctxt, &pvalue->en-gNB-CU-UP-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_en-gNB-DU-IDPresent) {
   stat = asn1PE_e2ap_GNB-DU-ID (pctxt, &pvalue->en-gNB-DU-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node_en_gNB_ID");

   stat = asn1PD_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_en-gNB-CU-UP-IDPresent = TRUE;
      stat = asn1PD_e2ap_GNB-CU-UP-ID (pctxt, &pvalue->en-gNB-CU-UP-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_en-gNB-CU-UP-IDPresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_en-gNB-DU-IDPresent = TRUE;
      stat = asn1PD_e2ap_GNB-DU-ID (pctxt, &pvalue->en-gNB-DU-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_en-gNB-DU-IDPresent = FALSE;

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_GlobalE2node_en_gNB_ID (e2ap_GlobalE2node_en_gNB_ID* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_GlobalenGNB-ID (&pvalue->global-en-gNB-ID);
   asn1Init_e2ap_GNB-CU-UP-ID (&pvalue->en-gNB-CU-UP-ID);
   asn1Init_e2ap_GNB-DU-ID (&pvalue->en-gNB-DU-ID);
}

void asn1Free_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue)
{
   %}
   asn1Free_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
   %}
   asn1Free_e2ap_GNB-CU-UP-ID (pctxt, &pvalue->en-gNB-CU-UP-ID);
   %}
   asn1Free_e2ap_GNB-DU-ID (pctxt, &pvalue->en-gNB-DU-ID);
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

// choice

/*****************************************/
/*           ENB_ID_Choice                */
/*****************************************/


EXTERN int asn1PE_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "ENB-ID-Choice");

   extbit = (OSBOOL)(pvalue->t > 0);
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
      case 0:
         RTXCTXPUSHELEMNAME (pctxt, "enb-ID-macro");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.enb-ID-macro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "enb-ID-shortmacro");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.enb-ID-shortmacro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXPUSHELEMNAME (pctxt, "enb-ID-longmacro");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.enb-ID-longmacro);
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
      case 0.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb-ID-macro");
         pvalue->u.enb-ID-macro = rtxMemAllocType (pctxt, ASN1BitStr32);
         if (pvalue->u.enb-ID-macro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.enb-ID-macro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb-ID-shortmacro");
         pvalue->u.enb-ID-shortmacro = rtxMemAllocType (pctxt, ASN1BitStr32);
         if (pvalue->u.enb-ID-shortmacro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.enb-ID-shortmacro);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "enb-ID-longmacro");
         pvalue->u.enb-ID-longmacro = rtxMemAllocType (pctxt, ASN1BitStr32);
         if (pvalue->u.enb-ID-longmacro == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.enb-ID-longmacro);
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
      case 0.0:
         if (pvalue->u.enb-ID-macro) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.enb-ID-macro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb-ID-macro);
         }
         break;
      case 1.0:
         if (pvalue->u.enb-ID-shortmacro) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.enb-ID-shortmacro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb-ID-shortmacro);
         }
         break;
      case 2.0:
         if (pvalue->u.enb-ID-longmacro) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.enb-ID-longmacro);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.enb-ID-longmacro);
         }
         break;
   }
   pvalue->t = 0;
}
// --- End of e2ap_ENB_ID_Choice.c ---

// --- Begin of e2ap_GlobalngeNB_ID.c ---

/*****************************************/
/*           GlobalngeNB_ID                */
/*****************************************/


int asn1PE_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalngeNB_ID");

   stat = asn1PE_e2ap_PLMN-Identity (pctxt, &pvalue->plmn-id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_ENB-ID-Choice (pctxt, &pvalue->enb-id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalngeNB_ID");

   stat = asn1PD_e2ap_PLMN-Identity (pctxt, &pvalue->plmn-id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_ENB-ID-Choice (pctxt, &pvalue->enb-id);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_GlobalngeNB_ID (e2ap_GlobalngeNB_ID* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_PLMN-Identity (&pvalue->plmn-id);
   asn1Init_e2ap_ENB-ID-Choice (&pvalue->enb-id);
}

void asn1Free_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue)
{
   %}
   asn1Free_e2ap_PLMN-Identity (pctxt, &pvalue->plmn-id);
   %}
   asn1Free_e2ap_ENB-ID-Choice (pctxt, &pvalue->enb-id);
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

// choice

/*****************************************/
/*           ENB_ID                */
/*****************************************/


EXTERN int asn1PE_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "ENB-ID");

   extbit = (OSBOOL)(pvalue->t > 0);
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
      case 0:
         RTXCTXPUSHELEMNAME (pctxt, "macro-eNB-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.macro-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "home-eNB-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.home-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXPUSHELEMNAME (pctxt, "short-Macro-eNB-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.short-Macro-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXPUSHELEMNAME (pctxt, "long-Macro-eNB-ID");
         stat = asn1PE_ASN1BitStr32 (pctxt, pvalue->u.long-Macro-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "ENB_ID");

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
      case 0.0:
         RTXCTXPUSHELEMNAME (pctxt, "macro-eNB-ID");
         pvalue->u.macro-eNB-ID = rtxMemAllocType (pctxt, ASN1BitStr32);
         if (pvalue->u.macro-eNB-ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.macro-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "home-eNB-ID");
         pvalue->u.home-eNB-ID = rtxMemAllocType (pctxt, ASN1BitStr32);
         if (pvalue->u.home-eNB-ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.home-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "short-Macro-eNB-ID");
         pvalue->u.short-Macro-eNB-ID = rtxMemAllocType (pctxt, ASN1BitStr32);
         if (pvalue->u.short-Macro-eNB-ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.short-Macro-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "long-Macro-eNB-ID");
         pvalue->u.long-Macro-eNB-ID = rtxMemAllocType (pctxt, ASN1BitStr32);
         if (pvalue->u.long-Macro-eNB-ID == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_ASN1BitStr32 (pctxt, pvalue->u.long-Macro-eNB-ID);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
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
      case 0.0:
         if (pvalue->u.macro-eNB-ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.macro-eNB-ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.macro-eNB-ID);
         }
         break;
      case 1.0:
         if (pvalue->u.home-eNB-ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.home-eNB-ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.home-eNB-ID);
         }
         break;
      case 2.0:
         if (pvalue->u.short-Macro-eNB-ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.short-Macro-eNB-ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.short-Macro-eNB-ID);
         }
         break;
      case 3.0:
         if (pvalue->u.long-Macro-eNB-ID) {
            asn1Free_ASN1BitStr32 (pctxt, pvalue->u.long-Macro-eNB-ID);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.long-Macro-eNB-ID);
         }
         break;
   }
   pvalue->t = 0;
}
// --- End of e2ap_ENB_ID.c ---

// --- Begin of e2ap_GlobalENB_ID.c ---

/*****************************************/
/*           GlobalENB_ID                */
/*****************************************/


int asn1PE_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalENB_ID");

   stat = asn1PE_e2ap_PLMN-Identity (pctxt, &pvalue->pLMN-Identity);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_ENB-ID (pctxt, &pvalue->eNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalENB_ID");

   stat = asn1PD_e2ap_PLMN-Identity (pctxt, &pvalue->pLMN-Identity);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_ENB-ID (pctxt, &pvalue->eNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_GlobalENB_ID (e2ap_GlobalENB_ID* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_PLMN-Identity (&pvalue->pLMN-Identity);
   asn1Init_e2ap_ENB-ID (&pvalue->eNB-ID);
}

void asn1Free_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue)
{
   %}
   asn1Free_e2ap_PLMN-Identity (pctxt, &pvalue->pLMN-Identity);
   %}
   asn1Free_e2ap_ENB-ID (pctxt, &pvalue->eNB-ID);
}
// --- End of e2ap_GlobalENB_ID.c ---

// --- Begin of e2ap_NGENB_DU_ID.c ---
/* e2ap_NGENB_DU_ID.c */


//interger no ext
/*****************************************/
/*           NGENB_DU_ID                */
/*****************************************/

EXTERN int asn1PE_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "NGENB_DU_ID");
   stat = pe_ConsUnsigned (pctxt, value, 0.0, 68719476735.0);
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

// --- Begin of e2ap_GlobalE2node_ng_eNB_ID.c ---

/*****************************************/
/*           GlobalE2node_ng_eNB_ID                */
/*****************************************/


int asn1PE_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node_ng_eNB_ID");

   stat = asn1PE_e2ap_GlobalngeNB-ID (pctxt, &pvalue->global-ng-eNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (pvalue->m_global-eNB-IDPresent) {
   stat = asn1PE_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_ngENB-DU-IDPresent) {
   stat = asn1PE_e2ap_NGENB-DU-ID (pctxt, &pvalue->ngENB-DU-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node_ng_eNB_ID");

   stat = asn1PD_e2ap_GlobalngeNB-ID (pctxt, &pvalue->global-ng-eNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_global-eNB-IDPresent = TRUE;
      stat = asn1PD_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_global-eNB-IDPresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_ngENB-DU-IDPresent = TRUE;
      stat = asn1PD_e2ap_NGENB-DU-ID (pctxt, &pvalue->ngENB-DU-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_ngENB-DU-IDPresent = FALSE;

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_GlobalE2node_ng_eNB_ID (e2ap_GlobalE2node_ng_eNB_ID* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_GlobalngeNB-ID (&pvalue->global-ng-eNB-ID);
   asn1Init_e2ap_GlobalENB-ID (&pvalue->global-eNB-ID);
   asn1Init_e2ap_NGENB-DU-ID (&pvalue->ngENB-DU-ID);
}

void asn1Free_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue)
{
   %}
   asn1Free_e2ap_GlobalngeNB-ID (pctxt, &pvalue->global-ng-eNB-ID);
   %}
   asn1Free_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
   %}
   asn1Free_e2ap_NGENB-DU-ID (pctxt, &pvalue->ngENB-DU-ID);
}
// --- End of e2ap_GlobalE2node_ng_eNB_ID.c ---

// --- Begin of e2ap_GlobalE2node_eNB_ID.c ---

/*****************************************/
/*           GlobalE2node_eNB_ID                */
/*****************************************/


int asn1PE_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node_eNB_ID");

   stat = asn1PE_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "GlobalE2node_eNB_ID");

   stat = asn1PD_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_GlobalE2node_eNB_ID (e2ap_GlobalE2node_eNB_ID* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_GlobalENB-ID (&pvalue->global-eNB-ID);
}

void asn1Free_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue)
{
   %}
   asn1Free_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
}
// --- End of e2ap_GlobalE2node_eNB_ID.c ---

// --- Begin of e2ap_GlobalE2node_ID.c ---
/* e2ap_GlobalE2node_ID.c */

// choice

/*****************************************/
/*           GlobalE2node_ID                */
/*****************************************/


EXTERN int asn1PE_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "GlobalE2node-ID");

   extbit = (OSBOOL)(pvalue->t > 0);
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
      case 0:
         RTXCTXPUSHELEMNAME (pctxt, "gNB");
         stat = asn1PE_e2ap_GlobalE2node-gNB-ID (pctxt, pvalue->u.gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "en-gNB");
         stat = asn1PE_e2ap_GlobalE2node-en-gNB-ID (pctxt, pvalue->u.en-gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXPUSHELEMNAME (pctxt, "ng-eNB");
         stat = asn1PE_e2ap_GlobalE2node-ng-eNB-ID (pctxt, pvalue->u.ng-eNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXPUSHELEMNAME (pctxt, "eNB");
         stat = asn1PE_e2ap_GlobalE2node-eNB-ID (pctxt, pvalue->u.eNB);
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
      case 0.0:
         RTXCTXPUSHELEMNAME (pctxt, "gNB");
         pvalue->u.gNB = rtxMemAllocType (pctxt, e2ap_GlobalE2node-gNB-ID);
         if (pvalue->u.gNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_GlobalE2node-gNB-ID (pctxt, pvalue->u.gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "en-gNB");
         pvalue->u.en-gNB = rtxMemAllocType (pctxt, e2ap_GlobalE2node-en-gNB-ID);
         if (pvalue->u.en-gNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_GlobalE2node-en-gNB-ID (pctxt, pvalue->u.en-gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "ng-eNB");
         pvalue->u.ng-eNB = rtxMemAllocType (pctxt, e2ap_GlobalE2node-ng-eNB-ID);
         if (pvalue->u.ng-eNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_GlobalE2node-ng-eNB-ID (pctxt, pvalue->u.ng-eNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "eNB");
         pvalue->u.eNB = rtxMemAllocType (pctxt, e2ap_GlobalE2node-eNB-ID);
         if (pvalue->u.eNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_GlobalE2node-eNB-ID (pctxt, pvalue->u.eNB);
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
      case 0.0:
         if (pvalue->u.gNB) {
            asn1Free_e2ap_GlobalE2node-gNB-ID (pctxt, pvalue->u.gNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gNB);
         }
         break;
      case 1.0:
         if (pvalue->u.en-gNB) {
            asn1Free_e2ap_GlobalE2node-en-gNB-ID (pctxt, pvalue->u.en-gNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.en-gNB);
         }
         break;
      case 2.0:
         if (pvalue->u.ng-eNB) {
            asn1Free_e2ap_GlobalE2node-ng-eNB-ID (pctxt, pvalue->u.ng-eNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.ng-eNB);
         }
         break;
      case 3.0:
         if (pvalue->u.eNB) {
            asn1Free_e2ap_GlobalE2node-eNB-ID (pctxt, pvalue->u.eNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.eNB);
         }
         break;
   }
   pvalue->t = 0;
}
// --- End of e2ap_GlobalE2node_ID.c ---

/*********************************************/
/* File .c missing: e2ap_RANfunctions_List.c */
/*********************************************/

// --- Begin of e2ap_E2nodeComponentInterfaceType.c ---
/* e2ap_E2nodeComponentInterfaceType.c */

//enumerated
/******************************************************/
/*                                                    */
/*    E2nodeComponentInterfaceType                                       */
/*                                                    */
/***********************


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

/*******************************************/
/* File .c missing: e2ap_PrintableString.c */
/*******************************************/

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

// --- Begin of e2ap_E2nodeComponentInterfaceNG.c ---

/*****************************************/
/*           E2nodeComponentInterfaceNG                */
/*****************************************/


int asn1PE_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceNG");

   stat = asn1PE_e2ap_AMFName (pctxt, &pvalue->amf-name);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceNG");

   stat = asn1PD_e2ap_AMFName (pctxt, &pvalue->amf-name);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentInterfaceNG (e2ap_E2nodeComponentInterfaceNG* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_AMFName (&pvalue->amf-name);
}

void asn1Free_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue)
{
   %}
   asn1Free_e2ap_AMFName (pctxt, &pvalue->amf-name);
}
// --- End of e2ap_E2nodeComponentInterfaceNG.c ---

// --- Begin of e2ap_GlobalNG_RANNode_ID.c ---
/* e2ap_GlobalNG_RANNode_ID.c */

// choice

/*****************************************/
/*           GlobalNG_RANNode_ID                */
/*****************************************/


EXTERN int asn1PE_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "GlobalNG-RANNode-ID");

   extbit = (OSBOOL)(pvalue->t > 0);
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
      case 0:
         RTXCTXPUSHELEMNAME (pctxt, "gNB");
         stat = asn1PE_e2ap_GlobalgNB-ID (pctxt, pvalue->u.gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "ng-eNB");
         stat = asn1PE_e2ap_GlobalngeNB-ID (pctxt, pvalue->u.ng-eNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "GlobalNG_RANNode_ID");

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
      case 0.0:
         RTXCTXPUSHELEMNAME (pctxt, "gNB");
         pvalue->u.gNB = rtxMemAllocType (pctxt, e2ap_GlobalgNB-ID);
         if (pvalue->u.gNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_GlobalgNB-ID (pctxt, pvalue->u.gNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "ng-eNB");
         pvalue->u.ng-eNB = rtxMemAllocType (pctxt, e2ap_GlobalngeNB-ID);
         if (pvalue->u.ng-eNB == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_GlobalngeNB-ID (pctxt, pvalue->u.ng-eNB);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
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
      case 0.0:
         if (pvalue->u.gNB) {
            asn1Free_e2ap_GlobalgNB-ID (pctxt, pvalue->u.gNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.gNB);
         }
         break;
      case 1.0:
         if (pvalue->u.ng-eNB) {
            asn1Free_e2ap_GlobalngeNB-ID (pctxt, pvalue->u.ng-eNB);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.ng-eNB);
         }
         break;
   }
   pvalue->t = 0;
}
// --- End of e2ap_GlobalNG_RANNode_ID.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceXn.c ---

/*****************************************/
/*           E2nodeComponentInterfaceXn                */
/*****************************************/


int asn1PE_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceXn");

   stat = asn1PE_e2ap_GlobalNG-RANNode-ID (pctxt, &pvalue->global-NG-RAN-Node-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceXn");

   stat = asn1PD_e2ap_GlobalNG-RANNode-ID (pctxt, &pvalue->global-NG-RAN-Node-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentInterfaceXn (e2ap_E2nodeComponentInterfaceXn* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_GlobalNG-RANNode-ID (&pvalue->global-NG-RAN-Node-ID);
}

void asn1Free_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue)
{
   %}
   asn1Free_e2ap_GlobalNG-RANNode-ID (pctxt, &pvalue->global-NG-RAN-Node-ID);
}
// --- End of e2ap_E2nodeComponentInterfaceXn.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceE1.c ---

/*****************************************/
/*           E2nodeComponentInterfaceE1                */
/*****************************************/


int asn1PE_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceE1");

   stat = asn1PE_e2ap_GNB-CU-UP-ID (pctxt, &pvalue->gNB-CU-UP-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceE1");

   stat = asn1PD_e2ap_GNB-CU-UP-ID (pctxt, &pvalue->gNB-CU-UP-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentInterfaceE1 (e2ap_E2nodeComponentInterfaceE1* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_GNB-CU-UP-ID (&pvalue->gNB-CU-UP-ID);
}

void asn1Free_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue)
{
   %}
   asn1Free_e2ap_GNB-CU-UP-ID (pctxt, &pvalue->gNB-CU-UP-ID);
}
// --- End of e2ap_E2nodeComponentInterfaceE1.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceF1.c ---

/*****************************************/
/*           E2nodeComponentInterfaceF1                */
/*****************************************/


int asn1PE_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceF1");

   stat = asn1PE_e2ap_GNB-DU-ID (pctxt, &pvalue->gNB-DU-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceF1");

   stat = asn1PD_e2ap_GNB-DU-ID (pctxt, &pvalue->gNB-DU-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentInterfaceF1 (e2ap_E2nodeComponentInterfaceF1* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_GNB-DU-ID (&pvalue->gNB-DU-ID);
}

void asn1Free_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue)
{
   %}
   asn1Free_e2ap_GNB-DU-ID (pctxt, &pvalue->gNB-DU-ID);
}
// --- End of e2ap_E2nodeComponentInterfaceF1.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceW1.c ---

/*****************************************/
/*           E2nodeComponentInterfaceW1                */
/*****************************************/


int asn1PE_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceW1");

   stat = asn1PE_e2ap_NGENB-DU-ID (pctxt, &pvalue->ng-eNB-DU-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceW1");

   stat = asn1PD_e2ap_NGENB-DU-ID (pctxt, &pvalue->ng-eNB-DU-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentInterfaceW1 (e2ap_E2nodeComponentInterfaceW1* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_NGENB-DU-ID (&pvalue->ng-eNB-DU-ID);
}

void asn1Free_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue)
{
   %}
   asn1Free_e2ap_NGENB-DU-ID (pctxt, &pvalue->ng-eNB-DU-ID);
}
// --- End of e2ap_E2nodeComponentInterfaceW1.c ---

/***********************************/
/* File .c missing: e2ap_MMEname.c */
/***********************************/

// --- Begin of e2ap_E2nodeComponentInterfaceS1.c ---

/*****************************************/
/*           E2nodeComponentInterfaceS1                */
/*****************************************/


int asn1PE_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceS1");

   stat = asn1PE_e2ap_MMEname (pctxt, &pvalue->mme-name);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceS1");

   stat = asn1PD_e2ap_MMEname (pctxt, &pvalue->mme-name);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentInterfaceS1 (e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_MMEname (&pvalue->mme-name);
}

void asn1Free_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue)
{
   %}
   asn1Free_e2ap_MMEname (pctxt, &pvalue->mme-name);
}
// --- End of e2ap_E2nodeComponentInterfaceS1.c ---

// --- Begin of e2ap_E2nodeComponentInterfaceX2.c ---

/*****************************************/
/*           E2nodeComponentInterfaceX2                */
/*****************************************/


int asn1PE_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceX2");

   if (pvalue->m_global-eNB-IDPresent) {
   stat = asn1PE_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }
   if (pvalue->m_global-en-gNB-IDPresent) {
   stat = asn1PE_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentInterfaceX2");

   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_global-eNB-IDPresent = TRUE;
      stat = asn1PD_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_global-eNB-IDPresent = FALSE;
   stat = rtxDecBit (pctxt, &bit);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   if (bit) {
      pvalue->m_global-en-gNB-IDPresent = TRUE;
      stat = asn1PD_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   );
   } else pvalue->m_global-en-gNB-IDPresent = FALSE;

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentInterfaceX2 (e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_GlobalENB-ID (&pvalue->global-eNB-ID);
   asn1Init_e2ap_GlobalenGNB-ID (&pvalue->global-en-gNB-ID);
}

void asn1Free_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue)
{
   %}
   asn1Free_e2ap_GlobalENB-ID (pctxt, &pvalue->global-eNB-ID);
   %}
   asn1Free_e2ap_GlobalenGNB-ID (pctxt, &pvalue->global-en-gNB-ID);
}
// --- End of e2ap_E2nodeComponentInterfaceX2.c ---

// --- Begin of e2ap_E2nodeComponentID.c ---
/* e2ap_E2nodeComponentID.c */

// choice

/*****************************************/
/*           E2nodeComponentID                */
/*****************************************/


EXTERN int asn1PE_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentID");

   extbit = (OSBOOL)(pvalue->t > 0);
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
      case 0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeNG");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceNG (pctxt, pvalue->u.e2nodeComponentInterfaceTypeNG);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeXn");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceXn (pctxt, pvalue->u.e2nodeComponentInterfaceTypeXn);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeE1");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceE1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeE1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeF1");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceF1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeF1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 4:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeW1");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceW1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeW1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 5:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeS1");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceS1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeS1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 6:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeX2");
         stat = asn1PE_e2ap_E2nodeComponentInterfaceX2 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeX2);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue)
{
   int stat = 0;
   OSUINT32 ui;
   OSBOOL extbit = FALSE;
   ASN1OpenType openType;
   RTXCTXPUSHTYPENAME (pctxt, "E2nodeComponentID");

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
      case 0.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeNG");
         pvalue->u.e2nodeComponentInterfaceTypeNG = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceNG);
         if (pvalue->u.e2nodeComponentInterfaceTypeNG == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceNG (pctxt, pvalue->u.e2nodeComponentInterfaceTypeNG);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 1.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeXn");
         pvalue->u.e2nodeComponentInterfaceTypeXn = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceXn);
         if (pvalue->u.e2nodeComponentInterfaceTypeXn == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceXn (pctxt, pvalue->u.e2nodeComponentInterfaceTypeXn);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 2.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeE1");
         pvalue->u.e2nodeComponentInterfaceTypeE1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceE1);
         if (pvalue->u.e2nodeComponentInterfaceTypeE1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceE1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeE1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 3.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeF1");
         pvalue->u.e2nodeComponentInterfaceTypeF1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceF1);
         if (pvalue->u.e2nodeComponentInterfaceTypeF1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceF1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeF1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 4.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeW1");
         pvalue->u.e2nodeComponentInterfaceTypeW1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceW1);
         if (pvalue->u.e2nodeComponentInterfaceTypeW1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceW1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeW1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 5.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeS1");
         pvalue->u.e2nodeComponentInterfaceTypeS1 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceS1);
         if (pvalue->u.e2nodeComponentInterfaceTypeS1 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceS1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeS1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      case 6.0:
         RTXCTXPUSHELEMNAME (pctxt, "e2nodeComponentInterfaceTypeX2");
         pvalue->u.e2nodeComponentInterfaceTypeX2 = rtxMemAllocType (pctxt, e2ap_E2nodeComponentInterfaceX2);
         if (pvalue->u.e2nodeComponentInterfaceTypeX2 == NULL) return LOG_RTERR (pctxt, RTERR_NOMEM);
         stat = asn1PD_e2ap_E2nodeComponentInterfaceX2 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeX2);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         RTXCTXPOPELEMNAME (pctxt);
         break;
      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   RTXCTXPOPELEMNAME (pctxt);
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
      case 0.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeNG) {
            asn1Free_e2ap_E2nodeComponentInterfaceNG (pctxt, pvalue->u.e2nodeComponentInterfaceTypeNG);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeNG);
         }
         break;
      case 1.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeXn) {
            asn1Free_e2ap_E2nodeComponentInterfaceXn (pctxt, pvalue->u.e2nodeComponentInterfaceTypeXn);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeXn);
         }
         break;
      case 2.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeE1) {
            asn1Free_e2ap_E2nodeComponentInterfaceE1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeE1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeE1);
         }
         break;
      case 3.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeF1) {
            asn1Free_e2ap_E2nodeComponentInterfaceF1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeF1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeF1);
         }
         break;
      case 4.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeW1) {
            asn1Free_e2ap_E2nodeComponentInterfaceW1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeW1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeW1);
         }
         break;
      case 5.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeS1) {
            asn1Free_e2ap_E2nodeComponentInterfaceS1 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeS1);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeS1);
         }
         break;
      case 6.0:
         if (pvalue->u.e2nodeComponentInterfaceTypeX2) {
            asn1Free_e2ap_E2nodeComponentInterfaceX2 (pctxt, pvalue->u.e2nodeComponentInterfaceTypeX2);
            rtxMemFreePtr (pctxt, (void*)pvalue->u.e2nodeComponentInterfaceTypeX2);
         }
         break;
   }
   pvalue->t = 0;
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


int asn1PE_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfiguration");

   stat = asn1PE_e2ap_e2nodeComponentRequestPart (pctxt, &pvalue->e2nodeComponentRequestPart);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PE_e2ap_e2nodeComponentResponsePart (pctxt, &pvalue->e2nodeComponentResponsePart);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2nodeComponentConfiguration");

   stat = asn1PD_e2ap_e2nodeComponentRequestPart (pctxt, &pvalue->e2nodeComponentRequestPart);
   if (stat != 0) return LOG_RTERR(pctxt, stat);
   stat = asn1PD_e2ap_e2nodeComponentResponsePart (pctxt, &pvalue->e2nodeComponentResponsePart);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2nodeComponentConfiguration (e2ap_E2nodeComponentConfiguration* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_e2nodeComponentRequestPart (&pvalue->e2nodeComponentRequestPart);
   asn1Init_e2ap_e2nodeComponentResponsePart (&pvalue->e2nodeComponentResponsePart);
}

void asn1Free_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue)
{
   %}
   asn1Free_e2ap_e2nodeComponentRequestPart (pctxt, &pvalue->e2nodeComponentRequestPart);
   %}
   asn1Free_e2ap_e2nodeComponentResponsePart (pctxt, &pvalue->e2nodeComponentResponsePart);
}
// --- End of e2ap_E2nodeComponentConfiguration.c ---

// --- Begin of e2ap_E2nodeComponentConfigAddition_Item.c ---

/*****************************************/
/*           E2nodeComponentConfigAddition_Item                */
/*****************************************/


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

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

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

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

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
/*****************************************/
/*           E2nodeComponentConfigAddition_ItemIEs               */
/*****************************************/
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
            stat = asn1PE_e2ap_ (pctxt, &pvalue->value.u_E2nodeComponentConfigAddition_ItemIEs_.value);
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
/*****************************************/
/*           E2nodeComponentConfigAddition_List                */
/*****************************************/


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

// --- Begin of e2ap_E2setupRequestIEs.c ---
/* e2ap_E2setupRequestIEs.c */

//IE
/*****************************************/
/*           E2setupRequestIEs               */
/*****************************************/
int asn1PE_e2ap_E2setupRequestIEs (OSCTXT* pctxt, e2ap_E2setupRequestIEs* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "E2setupRequestIEs");

   /* encode id */
   RTXCTXPUSHELEMNAME (pctxt, "id");
   stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, &pvalue->value.u_E2setupRequestIEs_.id);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPELEMNAME (pctxt);

   /* encode criticality */
   RTXCTXPUSHELEMNAME (pctxt, "criticality");
   stat = asn1PE_e2ap_Criticality (pctxt, &pvalue->value.u_E2setupRequestIEs_.criticality);
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
         case T_E2AP_PDU_Contents_E2setupRequestIEs_:
            RTXCTXPUSHELEMNAME (pctxt, "e2ap-E2nodeComponentConfigAddition-Item");
            stat = asn1PE_e2ap_ (pctxt, &pvalue->value.u_E2setupRequestIEs_.value);
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

int asn1PD_e2ap_E2setupRequestIEs (OSCTXT* pctxt, e2ap_E2setupRequestIEs* pvalue)
{
   /* decode logic tương tự, có switch + openType */
   return 0;
}

void asn1Init_e2ap_E2setupRequestIEs (e2ap_E2setupRequestIEs* pvalue)
{
   if (!pvalue) return;
   OSCRTLMEMSET (pvalue, 0, sizeof(e2ap_E2setupRequestIEs));
}

void asn1Free_e2ap_E2setupRequestIEs (OSCTXT* pctxt, e2ap_E2setupRequestIEs* pvalue)
{
   if (!pvalue) return;
   if (pvalue->extElem1) {
      rtxMemFreeArray (pctxt, pvalue->extElem1);
      pvalue->extElem1 = 0;
      pvalue->extElem1_n = 0;
   }
}
// --- End of e2ap_E2setupRequestIEs.c ---

// --- Begin of e2ap_E2setupRequest.c ---

/*****************************************/
/*           E2setupRequest                */
/*****************************************/


int asn1PE_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME(pctxt, "E2setupRequest");

   stat = asn1PE_e2ap_ProtocolIE-Container (pctxt, &pvalue->protocolIEs);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   if (pvalue->extElem1Present) {
      stat = pe_OpenType (pctxt, pvalue->extElem1.numocts, pvalue->extElem1.data);
      if (stat != 0) return LOG_RTERR(pctxt, stat);
   }

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

int asn1PD_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue)
{
   int stat = 0;
   OSBOOL bit;
   RTXCTXPUSHTYPENAME(pctxt, "E2setupRequest");

   stat = asn1PD_e2ap_ProtocolIE-Container (pctxt, &pvalue->protocolIEs);
   if (stat != 0) return LOG_RTERR(pctxt, stat);

   stat = pd_OpenType (pctxt, &pvalue->extElem1.numocts, &pvalue->extElem1.data);
   if (stat > 0) pvalue->extElem1Present = TRUE;

   RTXCTXPOPEXTNAME(pctxt);
   return 0;
}

void asn1Init_e2ap_E2setupRequest (e2ap_E2setupRequest* pvalue)
{
   memset(pvalue, 0, sizeof(*pvalue));
   asn1Init_e2ap_ProtocolIE-Container (&pvalue->protocolIEs);
}

void asn1Free_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue)
{
   %}
   asn1Free_e2ap_ProtocolIE-Container (pctxt, &pvalue->protocolIEs);
}
// --- End of e2ap_E2setupRequest.c ---

