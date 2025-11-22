
#ifndef OUTPUT_MAIN_H
#define OUTPUT_MAIN_H

// --- Begin of doc/header.h ---
//======================E2AP.h========================//
typedef pd_BitString32 pd_BitString32;
typedef pe_BitString32 pe_BitString32;
typedef asn1PrtToStr_ASN1BitStr32 rtPrintToStringBitStrBraceText;
typedef //asn1Free_ASN1BitStr32 

// --- End of doc/header.h ---

// --- Begin of e2ap_TransactionID.h ---
/*****************************************/
/*           TransactionID                */
/*****************************************/
//interger with ext


typedef OSUINT8 e2ap_TransactionID;

EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value);
EXTERN int asn1PD_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID* pvalue);
EXTERN void asn1Print_e2ap_TransactionID (const char* name, const e2ap_TransactionID* pvalue);
EXTERN int asn1PrtToStr_e2ap_TransactionID (const char* name, e2ap_TransactionID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_TransactionID (OSCTXT* pctxt, const char* name, const e2ap_TransactionID* pvalue);
// --- End of e2ap_TransactionID.h ---

// --- Begin of e2ap_PLMN_Identity.h ---
/*****************************************/
/*           PLMN_Identity                */
/*****************************************/
//octet string


typedef struct e2ap_PLMN_Identity {
   OSUINT32 numocts;
   OSOCTET data[3];
} e2ap_PLMN_Identity;

EXTERN int asn1PE_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue);
EXTERN int asn1PD_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity** ppvalue);
EXTERN void asn1Print_e2ap_PLMN_Identity (const char* name, const e2ap_PLMN_Identity* pvalue);
EXTERN int asn1PrtToStr_e2ap_PLMN_Identity (const char* name, e2ap_PLMN_Identity* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_PLMN_Identity (OSCTXT* pctxt, const char* name, const e2ap_PLMN_Identity* pvalue);
EXTERN int asn1Copy_e2ap_PLMN_Identity (OSCTXT* pctxt, const e2ap_PLMN_Identity* pSrcValue, e2ap_PLMN_Identity* pDstValue);
EXTERN int asn1Init_e2ap_PLMN_Identity (e2ap_PLMN_Identity* pvalue);
EXTERN void asn1Free_e2ap_PLMN_Identity (OSCTXT* pctxt, e2ap_PLMN_Identity* pvalue);
// --- End of e2ap_PLMN_Identity.h ---

/**********************************/
/* File .h missing: e2ap_gnb_ID.h */
/**********************************/

// --- Begin of e2ap_GNB_ID_Choice.h ---


/*****************************************/
/*           GNB-ID-Choice                */
/*****************************************/
// choice

#define T_e2ap_GNB_ID_Choice_gnb_ID  1
#define T_e2ap_GNB_ID_Choice_extElem1 2

typedef struct e2ap_GNB_ID_Choice {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      ASN1BitStr32 *gnb_ID;
      /* t = 2*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_GNB_ID_Choice;

EXTERN int asn1PE_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue);
EXTERN int asn1PD_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue);
EXTERN void asn1Print_e2ap_GNB_ID_Choice (const char* name, const e2ap_GNB_ID_Choice* pvalue);
EXTERN int asn1PrtToStr_e2ap_GNB_ID_Choice (const char* name, e2ap_GNB_ID_Choice* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GNB_ID_Choice (OSCTXT* pctxt, const char* name, const e2ap_GNB_ID_Choice* pvalue);
EXTERN int asn1Copy_e2ap_GNB_ID_Choice (OSCTXT* pctxt, const e2ap_GNB_ID_Choice* pSrcValue, e2ap_GNB_ID_Choice* pDstValue);
EXTERN int asn1Init_e2ap_GNB_ID_Choice (e2ap_GNB_ID_Choice* pvalue);
EXTERN void asn1Free_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue);

// --- End of e2ap_GNB_ID_Choice.h ---

// --- Begin of e2ap_GlobalgNB_ID.h ---
/*****************************************/
/*           GlobalgNB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalgNB_ID {
   e2ap_PLMN_Identity plmn_id;
   e2ap_GNB_ID_Choice gnb_id;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalgNB_ID;

EXTERN int asn1PE_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalgNB_ID (e2ap_GlobalgNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalgNB_ID (const char* name, const e2ap_GlobalgNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalgNB_ID (const char* name, e2ap_GlobalgNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalgNB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalgNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalgNB_ID (OSCTXT* pctxt, const e2ap_GlobalgNB_ID* pSrcValue, e2ap_GlobalgNB_ID* pDstValue);
// --- End of e2ap_GlobalgNB_ID.h ---

/**********************************/
/* File .h missing: e2ap_gNB_ID.h */
/**********************************/

// --- Begin of e2ap_ENGNB_ID.h ---


/*****************************************/
/*           ENGNB-ID                */
/*****************************************/
// choice

#define T_e2ap_ENGNB_ID_gNB_ID  1
#define T_e2ap_ENGNB_ID_extElem1 2

typedef struct e2ap_ENGNB_ID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      ASN1BitStr32 *gNB_ID;
      /* t = 2*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_ENGNB_ID;

EXTERN int asn1PE_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue);
EXTERN int asn1PD_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue);
EXTERN void asn1Print_e2ap_ENGNB_ID (const char* name, const e2ap_ENGNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_ENGNB_ID (const char* name, e2ap_ENGNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_ENGNB_ID (OSCTXT* pctxt, const char* name, const e2ap_ENGNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_ENGNB_ID (OSCTXT* pctxt, const e2ap_ENGNB_ID* pSrcValue, e2ap_ENGNB_ID* pDstValue);
EXTERN int asn1Init_e2ap_ENGNB_ID (e2ap_ENGNB_ID* pvalue);
EXTERN void asn1Free_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue);

// --- End of e2ap_ENGNB_ID.h ---

// --- Begin of e2ap_GlobalenGNB_ID.h ---
/*****************************************/
/*           GlobalenGNB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalenGNB_ID {
   e2ap_PLMN_Identity pLMN_Identity;
   e2ap_ENGNB_ID gNB_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalenGNB_ID;

EXTERN int asn1PE_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalenGNB_ID (e2ap_GlobalenGNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalenGNB_ID (const char* name, const e2ap_GlobalenGNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalenGNB_ID (const char* name, e2ap_GlobalenGNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalenGNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, const e2ap_GlobalenGNB_ID* pSrcValue, e2ap_GlobalenGNB_ID* pDstValue);
// --- End of e2ap_GlobalenGNB_ID.h ---

// --- Begin of e2ap_GNB_CU_UP_ID.h ---
/*****************************************/
/*        GNB-CU-UP-ID         */
/*****************************************/
//interger no ext


typedef OSUINT64 e2ap_GNB_CU_UP_ID;

EXTERN int asn1PE_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID value);
EXTERN int asn1PD_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID* pvalue);
EXTERN void asn1Print_e2ap_GNB_CU_UP_ID (const char* name, const e2ap_GNB_CU_UP_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GNB_CU_UP_ID (const char* name, e2ap_GNB_CU_UP_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, const char* name, const e2ap_GNB_CU_UP_ID* pvalue);
// --- End of e2ap_GNB_CU_UP_ID.h ---

// --- Begin of e2ap_GNB_DU_ID.h ---
/*****************************************/
/*        GNB-DU-ID         */
/*****************************************/
//interger no ext


typedef OSUINT64 e2ap_GNB_DU_ID;

EXTERN int asn1PE_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID value);
EXTERN int asn1PD_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID* pvalue);
EXTERN void asn1Print_e2ap_GNB_DU_ID (const char* name, const e2ap_GNB_DU_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GNB_DU_ID (const char* name, e2ap_GNB_DU_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GNB_DU_ID (OSCTXT* pctxt, const char* name, const e2ap_GNB_DU_ID* pvalue);
// --- End of e2ap_GNB_DU_ID.h ---

// --- Begin of e2ap_GlobalE2node_gNB_ID.h ---
/*****************************************/
/*           GlobalE2node_gNB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalE2node_gNB_ID {
   e2ap_GlobalgNB_ID global_gNB_ID;
   e2ap_GlobalenGNB_ID global_en_gNB_ID;
     OSBOOL m_global_en_gNB_IDPresent;   e2ap_GNB_CU_UP_ID gNB_CU_UP_ID;
     OSBOOL m_gNB_CU_UP_IDPresent;   e2ap_GNB_DU_ID gNB_DU_ID;
     OSBOOL m_gNB_DU_IDPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalE2node_gNB_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalE2node_gNB_ID (e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_gNB_ID (const char* name, const e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalE2node_gNB_ID (const char* name, e2ap_GlobalE2node_gNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, const e2ap_GlobalE2node_gNB_ID* pSrcValue, e2ap_GlobalE2node_gNB_ID* pDstValue);
// --- End of e2ap_GlobalE2node_gNB_ID.h ---

// --- Begin of e2ap_GlobalE2node_en_gNB_ID.h ---
/*****************************************/
/*           GlobalE2node_en_gNB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalE2node_en_gNB_ID {
   e2ap_GlobalenGNB_ID global_en_gNB_ID;
   e2ap_GNB_CU_UP_ID en_gNB_CU_UP_ID;
     OSBOOL m_en_gNB_CU_UP_IDPresent;   e2ap_GNB_DU_ID en_gNB_DU_ID;
     OSBOOL m_en_gNB_DU_IDPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalE2node_en_gNB_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalE2node_en_gNB_ID (e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_en_gNB_ID (const char* name, const e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalE2node_en_gNB_ID (const char* name, e2ap_GlobalE2node_en_gNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, const e2ap_GlobalE2node_en_gNB_ID* pSrcValue, e2ap_GlobalE2node_en_gNB_ID* pDstValue);
// --- End of e2ap_GlobalE2node_en_gNB_ID.h ---

/****************************************/
/* File .h missing: e2ap_enb_ID_macro.h */
/****************************************/

/*********************************************/
/* File .h missing: e2ap_enb_ID_shortmacro.h */
/*********************************************/

/********************************************/
/* File .h missing: e2ap_enb_ID_longmacro.h */
/********************************************/

// --- Begin of e2ap_ENB_ID_Choice.h ---


/*****************************************/
/*           ENB-ID-Choice                */
/*****************************************/
// choice

#define T_e2ap_ENB_ID_Choice_enb_ID_macro  1
#define T_e2ap_ENB_ID_Choice_enb_ID_shortmacro  2
#define T_e2ap_ENB_ID_Choice_enb_ID_longmacro  3
#define T_e2ap_ENB_ID_Choice_extElem1 4

typedef struct e2ap_ENB_ID_Choice {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      ASN1BitStr32 *enb_ID_macro;
      /* t =  2 */
      ASN1BitStr32 *enb_ID_shortmacro;
      /* t =  3 */
      ASN1BitStr32 *enb_ID_longmacro;
      /* t = 4*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_ENB_ID_Choice;

EXTERN int asn1PE_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue);
EXTERN int asn1PD_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue);
EXTERN void asn1Print_e2ap_ENB_ID_Choice (const char* name, const e2ap_ENB_ID_Choice* pvalue);
EXTERN int asn1PrtToStr_e2ap_ENB_ID_Choice (const char* name, e2ap_ENB_ID_Choice* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_ENB_ID_Choice (OSCTXT* pctxt, const char* name, const e2ap_ENB_ID_Choice* pvalue);
EXTERN int asn1Copy_e2ap_ENB_ID_Choice (OSCTXT* pctxt, const e2ap_ENB_ID_Choice* pSrcValue, e2ap_ENB_ID_Choice* pDstValue);
EXTERN int asn1Init_e2ap_ENB_ID_Choice (e2ap_ENB_ID_Choice* pvalue);
EXTERN void asn1Free_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue);

// --- End of e2ap_ENB_ID_Choice.h ---

// --- Begin of e2ap_GlobalngeNB_ID.h ---
/*****************************************/
/*           GlobalngeNB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalngeNB_ID {
   e2ap_PLMN_Identity plmn_id;
   e2ap_ENB_ID_Choice enb_id;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalngeNB_ID;

EXTERN int asn1PE_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalngeNB_ID (e2ap_GlobalngeNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalngeNB_ID (const char* name, const e2ap_GlobalngeNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalngeNB_ID (const char* name, e2ap_GlobalngeNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalngeNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, const e2ap_GlobalngeNB_ID* pSrcValue, e2ap_GlobalngeNB_ID* pDstValue);
// --- End of e2ap_GlobalngeNB_ID.h ---

/****************************************/
/* File .h missing: e2ap_macro_eNB_ID.h */
/****************************************/

/***************************************/
/* File .h missing: e2ap_home_eNB_ID.h */
/***************************************/

/**********************************************/
/* File .h missing: e2ap_short_Macro_eNB_ID.h */
/**********************************************/

/*********************************************/
/* File .h missing: e2ap_long_Macro_eNB_ID.h */
/*********************************************/

// --- Begin of e2ap_ENB_ID.h ---


/*****************************************/
/*           ENB-ID                */
/*****************************************/
// choice

#define T_e2ap_ENB_ID_macro_eNB_ID  1
#define T_e2ap_ENB_ID_home_eNB_ID  2
#define T_e2ap_ENB_ID_short_Macro_eNB_ID  3
#define T_e2ap_ENB_ID_long_Macro_eNB_ID  4
#define T_e2ap_ENB_ID_extElem1 5

typedef struct e2ap_ENB_ID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      ASN1BitStr32 *macro_eNB_ID;
      /* t =  2 */
      ASN1BitStr32 *home_eNB_ID;
      /* t =  3 */
      ASN1BitStr32 *short_Macro_eNB_ID;
      /* t =  4 */
      ASN1BitStr32 *long_Macro_eNB_ID;
      /* t = 5*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_ENB_ID;

EXTERN int asn1PE_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);
EXTERN int asn1PD_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);
EXTERN void asn1Print_e2ap_ENB_ID (const char* name, const e2ap_ENB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_ENB_ID (const char* name, e2ap_ENB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_ENB_ID (OSCTXT* pctxt, const char* name, const e2ap_ENB_ID* pvalue);
EXTERN int asn1Copy_e2ap_ENB_ID (OSCTXT* pctxt, const e2ap_ENB_ID* pSrcValue, e2ap_ENB_ID* pDstValue);
EXTERN int asn1Init_e2ap_ENB_ID (e2ap_ENB_ID* pvalue);
EXTERN void asn1Free_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);

// --- End of e2ap_ENB_ID.h ---

// --- Begin of e2ap_GlobalENB_ID.h ---
/*****************************************/
/*           GlobalENB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalENB_ID {
   e2ap_PLMN_Identity pLMN_Identity;
   e2ap_ENB_ID eNB_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalENB_ID;

EXTERN int asn1PE_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalENB_ID (e2ap_GlobalENB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalENB_ID (const char* name, const e2ap_GlobalENB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalENB_ID (const char* name, e2ap_GlobalENB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalENB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalENB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalENB_ID (OSCTXT* pctxt, const e2ap_GlobalENB_ID* pSrcValue, e2ap_GlobalENB_ID* pDstValue);
// --- End of e2ap_GlobalENB_ID.h ---

// --- Begin of e2ap_NGENB_DU_ID.h ---
/*****************************************/
/*        NGENB-DU-ID         */
/*****************************************/
//interger no ext


typedef OSUINT64 e2ap_NGENB_DU_ID;

EXTERN int asn1PE_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID value);
EXTERN int asn1PD_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID* pvalue);
EXTERN void asn1Print_e2ap_NGENB_DU_ID (const char* name, const e2ap_NGENB_DU_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_NGENB_DU_ID (const char* name, e2ap_NGENB_DU_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_NGENB_DU_ID (OSCTXT* pctxt, const char* name, const e2ap_NGENB_DU_ID* pvalue);
// --- End of e2ap_NGENB_DU_ID.h ---

// --- Begin of e2ap_GlobalE2node_ng_eNB_ID.h ---
/*****************************************/
/*           GlobalE2node_ng_eNB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalE2node_ng_eNB_ID {
   e2ap_GlobalngeNB_ID global_ng_eNB_ID;
   e2ap_GlobalENB_ID global_eNB_ID;
     OSBOOL m_global_eNB_IDPresent;   e2ap_NGENB_DU_ID ngENB_DU_ID;
     OSBOOL m_ngENB_DU_IDPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalE2node_ng_eNB_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalE2node_ng_eNB_ID (e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_ng_eNB_ID (const char* name, const e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalE2node_ng_eNB_ID (const char* name, e2ap_GlobalE2node_ng_eNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, const e2ap_GlobalE2node_ng_eNB_ID* pSrcValue, e2ap_GlobalE2node_ng_eNB_ID* pDstValue);
// --- End of e2ap_GlobalE2node_ng_eNB_ID.h ---

// --- Begin of e2ap_GlobalE2node_eNB_ID.h ---
/*****************************************/
/*           GlobalE2node_eNB_ID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_GlobalE2node_eNB_ID {
   e2ap_GlobalENB_ID global_eNB_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalE2node_eNB_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN int asn1Init_e2ap_GlobalE2node_eNB_ID (e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_eNB_ID (const char* name, const e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalE2node_eNB_ID (const char* name, e2ap_GlobalE2node_eNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, const e2ap_GlobalE2node_eNB_ID* pSrcValue, e2ap_GlobalE2node_eNB_ID* pDstValue);
// --- End of e2ap_GlobalE2node_eNB_ID.h ---

// --- Begin of e2ap_GlobalE2node_ID.h ---


/*****************************************/
/*           GlobalE2node-ID                */
/*****************************************/
// choice

#define T_e2ap_GlobalE2node_ID_gNB  1
#define T_e2ap_GlobalE2node_ID_en_gNB  2
#define T_e2ap_GlobalE2node_ID_ng_eNB  3
#define T_e2ap_GlobalE2node_ID_eNB  4
#define T_e2ap_GlobalE2node_ID_extElem1 5

typedef struct e2ap_GlobalE2node_ID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      e2ap_GlobalE2node_gNB_ID *gNB;
      /* t =  2 */
      e2ap_GlobalE2node_en_gNB_ID *en_gNB;
      /* t =  3 */
      e2ap_GlobalE2node_ng_eNB_ID *ng_eNB;
      /* t =  4 */
      e2ap_GlobalE2node_eNB_ID *eNB;
      /* t = 5*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_GlobalE2node_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_ID (const char* name, const e2ap_GlobalE2node_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalE2node_ID (const char* name, e2ap_GlobalE2node_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalE2node_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalE2node_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalE2node_ID (OSCTXT* pctxt, const e2ap_GlobalE2node_ID* pSrcValue, e2ap_GlobalE2node_ID* pDstValue);
EXTERN int asn1Init_e2ap_GlobalE2node_ID (e2ap_GlobalE2node_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue);

// --- End of e2ap_GlobalE2node_ID.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceType.h ---
/******************************************************/
/*                                                    */
/*    E2nodeComponentInterfaceType                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_ng = 0,
    e2ap_xn = 1,
    e2ap_e1 = 2,
    e2ap_f1 = 3,
    e2ap_w1 = 4,
    e2ap_s1 = 5,
    e2ap_x2 = 6
} e2ap_E2nodeComponentInterfaceType_Root;

typedef OSUINT32 e2ap_E2nodeComponentInterfaceType;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceType value);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceType* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceType (const char* name, const e2ap_E2nodeComponentInterfaceType* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceType (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceType* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceType (const char* name,const e2ap_E2nodeComponentInterfaceType* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_E2nodeComponentInterfaceType_ENUMTAB[];
#define e2ap_E2nodeComponentInterfaceType_ENUMTABSIZE 7

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_E2nodeComponentInterfaceType_ToString (OSUINT32 value);
EXTERN int e2ap_E2nodeComponentInterfaceType_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_E2nodeComponentInterfaceType* pvalue);
EXTERN int e2ap_E2nodeComponentInterfaceType_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_E2nodeComponentInterfaceType* pvalue);
// --- End of e2ap_E2nodeComponentInterfaceType.h ---

/*******************************************/
/* File .h missing: e2ap_PrintableString.h */
/*******************************************/

// --- Begin of e2ap_AMFName.h ---
/* e2ap_AMFName.h */

//printable string
/*****************************************/
/*           AMFName                */
/*****************************************/


typedef const char* e2ap_AMFName;

EXTERN int asn1PE_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName value);
EXTERN int asn1PD_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName* ppvalue);
EXTERN void asn1Print_e2ap_AMFName (const char* name, e2ap_AMFName pvalue);
EXTERN int asn1PrtToStr_e2ap_AMFName (const char* name, e2ap_AMFName pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_AMFName (OSCTXT* pctxt, const char* name, e2ap_AMFName pvalue);
EXTERN int asn1Copy_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName pSrcValue, e2ap_AMFName* pDstValue);
EXTERN void asn1Free_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName pvalue);
// --- End of e2ap_AMFName.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceNG.h ---
/*****************************************/
/*           E2nodeComponentInterfaceNG                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceNG {
   e2ap_AMFName amf_name;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceNG;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceNG (e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceNG (const char* name, const e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceNG (const char* name, e2ap_E2nodeComponentInterfaceNG* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceNG* pSrcValue, e2ap_E2nodeComponentInterfaceNG* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceNG.h ---

// --- Begin of e2ap_GlobalNG_RANNode_ID.h ---


/*****************************************/
/*           GlobalNG-RANNode-ID                */
/*****************************************/
// choice

#define T_e2ap_GlobalNG_RANNode_ID_gNB  1
#define T_e2ap_GlobalNG_RANNode_ID_ng_eNB  2
#define T_e2ap_GlobalNG_RANNode_ID_extElem1 3

typedef struct e2ap_GlobalNG_RANNode_ID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      e2ap_GlobalgNB_ID *gNB;
      /* t =  2 */
      e2ap_GlobalngeNB_ID *ng_eNB;
      /* t = 3*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_GlobalNG_RANNode_ID;

EXTERN int asn1PE_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalNG_RANNode_ID (const char* name, const e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalNG_RANNode_ID (const char* name, e2ap_GlobalNG_RANNode_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, const char* name, const e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN int asn1Copy_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, const e2ap_GlobalNG_RANNode_ID* pSrcValue, e2ap_GlobalNG_RANNode_ID* pDstValue);
EXTERN int asn1Init_e2ap_GlobalNG_RANNode_ID (e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue);

// --- End of e2ap_GlobalNG_RANNode_ID.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceXn.h ---
/*****************************************/
/*           E2nodeComponentInterfaceXn                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceXn {
   e2ap_GlobalNG_RANNode_ID global_NG_RAN_Node_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceXn;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceXn (e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceXn (const char* name, const e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceXn (const char* name, e2ap_E2nodeComponentInterfaceXn* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceXn* pSrcValue, e2ap_E2nodeComponentInterfaceXn* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceXn.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceE1.h ---
/*****************************************/
/*           E2nodeComponentInterfaceE1                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceE1 {
   e2ap_GNB_CU_UP_ID gNB_CU_UP_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceE1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceE1 (e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceE1 (const char* name, const e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceE1 (const char* name, e2ap_E2nodeComponentInterfaceE1* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceE1* pSrcValue, e2ap_E2nodeComponentInterfaceE1* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceE1.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceF1.h ---
/*****************************************/
/*           E2nodeComponentInterfaceF1                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceF1 {
   e2ap_GNB_DU_ID gNB_DU_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceF1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceF1 (e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceF1 (const char* name, const e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceF1 (const char* name, e2ap_E2nodeComponentInterfaceF1* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceF1* pSrcValue, e2ap_E2nodeComponentInterfaceF1* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceF1.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceW1.h ---
/*****************************************/
/*           E2nodeComponentInterfaceW1                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceW1 {
   e2ap_NGENB_DU_ID ng_eNB_DU_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceW1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceW1 (e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceW1 (const char* name, const e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceW1 (const char* name, e2ap_E2nodeComponentInterfaceW1* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceW1* pSrcValue, e2ap_E2nodeComponentInterfaceW1* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceW1.h ---

/***********************************/
/* File .h missing: e2ap_MMEname.h */
/***********************************/

// --- Begin of e2ap_E2nodeComponentInterfaceS1.h ---
/*****************************************/
/*           E2nodeComponentInterfaceS1                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceS1 {
   e2ap_MMEname mme_name;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceS1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceS1 (e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceS1 (const char* name, const e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceS1 (const char* name, e2ap_E2nodeComponentInterfaceS1* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceS1* pSrcValue, e2ap_E2nodeComponentInterfaceS1* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceS1.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceX2.h ---
/*****************************************/
/*           E2nodeComponentInterfaceX2                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentInterfaceX2 {
   e2ap_GlobalENB_ID global_eNB_ID;
     OSBOOL m_global_eNB_IDPresent;   e2ap_GlobalenGNB_ID global_en_gNB_ID;
     OSBOOL m_global_en_gNB_IDPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceX2;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentInterfaceX2 (e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceX2 (const char* name, const e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceX2 (const char* name, e2ap_E2nodeComponentInterfaceX2* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, const e2ap_E2nodeComponentInterfaceX2* pSrcValue, e2ap_E2nodeComponentInterfaceX2* pDstValue);
// --- End of e2ap_E2nodeComponentInterfaceX2.h ---

// --- Begin of e2ap_E2nodeComponentID.h ---


/*****************************************/
/*           E2nodeComponentID                */
/*****************************************/
// choice

#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeNG  1
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeXn  2
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeE1  3
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeF1  4
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeW1  5
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeS1  6
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeX2  7
#define T_e2ap_E2nodeComponentID_extElem1 8

typedef struct e2ap_E2nodeComponentID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      e2ap_E2nodeComponentInterfaceNG *e2nodeComponentInterfaceTypeNG;
      /* t =  2 */
      e2ap_E2nodeComponentInterfaceXn *e2nodeComponentInterfaceTypeXn;
      /* t =  3 */
      e2ap_E2nodeComponentInterfaceE1 *e2nodeComponentInterfaceTypeE1;
      /* t =  4 */
      e2ap_E2nodeComponentInterfaceF1 *e2nodeComponentInterfaceTypeF1;
      /* t =  5 */
      e2ap_E2nodeComponentInterfaceW1 *e2nodeComponentInterfaceTypeW1;
      /* t =  6 */
      e2ap_E2nodeComponentInterfaceS1 *e2nodeComponentInterfaceTypeS1;
      /* t =  7 */
      e2ap_E2nodeComponentInterfaceX2 *e2nodeComponentInterfaceTypeX2;
      /* t = 8*/
      ASN1OpenType *extElem1;  /* extension */
      
   } u;
} e2ap_E2nodeComponentID;

EXTERN int asn1PE_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentID (const char* name, const e2ap_E2nodeComponentID* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentID (const char* name, e2ap_E2nodeComponentID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentID (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentID* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentID (OSCTXT* pctxt, const e2ap_E2nodeComponentID* pSrcValue, e2ap_E2nodeComponentID* pDstValue);
EXTERN int asn1Init_e2ap_E2nodeComponentID (e2ap_E2nodeComponentID* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue);

// --- End of e2ap_E2nodeComponentID.h ---

/******************************************************/
/* File .h missing: e2ap_e2nodeComponentRequestPart.h */
/******************************************************/

/*******************************************************/
/* File .h missing: e2ap_e2nodeComponentResponsePart.h */
/*******************************************************/

// --- Begin of e2ap_E2nodeComponentConfiguration.h ---
/*****************************************/
/*           E2nodeComponentConfiguration                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentConfiguration {
   e2ap_e2nodeComponentRequestPart e2nodeComponentRequestPart;
   e2ap_e2nodeComponentResponsePart e2nodeComponentResponsePart;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentConfiguration;

EXTERN int asn1PE_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentConfiguration (e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfiguration (const char* name, const e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentConfiguration (const char* name, e2ap_E2nodeComponentConfiguration* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, const e2ap_E2nodeComponentConfiguration* pSrcValue, e2ap_E2nodeComponentConfiguration* pDstValue);
// --- End of e2ap_E2nodeComponentConfiguration.h ---

// --- Begin of e2ap_E2nodeComponentConfigAddition_Item.h ---
/*****************************************/
/*           E2nodeComponentConfigAddition_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentConfigAddition_Item {
   e2ap_E2nodeComponentInterfaceType e2nodeComponentInterfaceType;
   e2ap_E2nodeComponentID e2nodeComponentID;
   e2ap_E2nodeComponentConfiguration e2nodeComponentConfiguration;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentConfigAddition_Item;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentConfigAddition_Item (e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigAddition_Item (const char* name, const e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentConfigAddition_Item (const char* name, e2ap_E2nodeComponentConfigAddition_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, const e2ap_E2nodeComponentConfigAddition_Item* pSrcValue, e2ap_E2nodeComponentConfigAddition_Item* pDstValue);
// --- End of e2ap_E2nodeComponentConfigAddition_Item.h ---

// --- Begin of e2ap_E2nodeComponentConfigAddition_ItemIEs.h ---
/* e2ap_E2nodeComponentConfigAddition_ItemIEs.h */

/*****************************************/
/*           E2nodeComponentConfigAddition_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigAddition_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_E2nodeComponentConfigAddition_ItemIEs_E2nodeComponentConfigAddition_Item   
   

} e2ap_E2nodeComponentConfigAddition_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2nodeComponentConfigAddition_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2nodeComponentConfigAddition_ItemIEs_TVALUE t;
      union {
         e2ap_E2nodeComponentConfigAddition_Item * _e2apE2nodeComponentConfigAddition_ItemIEs_E2nodeComponentConfigAddition_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2nodeComponentConfigAddition_ItemIEs;

EXTERN int  asn1PE_e2ap_E2nodeComponentConfigAddition_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_E2nodeComponentConfigAddition_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigAddition_ItemIEs (e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAddition_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue);

// --- End of e2ap_E2nodeComponentConfigAddition_ItemIEs.h ---

// --- Begin of e2ap_E2nodeComponentConfigAddition_List.h ---
/*****************************************/
/*           E2nodeComponentConfigAddition_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_E2nodeComponentConfigAddition_List;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* ppvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigAddition_List (e2ap_E2nodeComponentConfigAddition_List* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentConfigAddition_List (const char* name, e2ap_E2nodeComponentConfigAddition_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, const e2ap_E2nodeComponentConfigAddition_List* pSrcValue, e2ap_E2nodeComponentConfigAddition_List* pDstValue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigAddition_List (const char *name, const e2ap_E2nodeComponentConfigAddition_List* pvalue);
// --- End of e2ap_E2nodeComponentConfigAddition_List.h ---

// --- Begin of e2ap_E2nodeComponentConfigUpdate_Item.h ---
/*****************************************/
/*           E2nodeComponentConfigUpdate_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentConfigUpdate_Item {
   e2ap_E2nodeComponentInterfaceType e2nodeComponentInterfaceType;
   e2ap_E2nodeComponentID e2nodeComponentID;
   e2ap_E2nodeComponentConfiguration e2nodeComponentConfiguration;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentConfigUpdate_Item;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigUpdate_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdate_Item* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigUpdate_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdate_Item* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentConfigUpdate_Item (e2ap_E2nodeComponentConfigUpdate_Item* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigUpdate_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdate_Item* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigUpdate_Item (const char* name, const e2ap_E2nodeComponentConfigUpdate_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentConfigUpdate_Item (const char* name, e2ap_E2nodeComponentConfigUpdate_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentConfigUpdate_Item (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentConfigUpdate_Item* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentConfigUpdate_Item (OSCTXT* pctxt, const e2ap_E2nodeComponentConfigUpdate_Item* pSrcValue, e2ap_E2nodeComponentConfigUpdate_Item* pDstValue);
// --- End of e2ap_E2nodeComponentConfigUpdate_Item.h ---

// --- Begin of e2ap_E2nodeComponentConfigUpdate_ItemIEs.h ---
/* e2ap_E2nodeComponentConfigUpdate_ItemIEs.h */

/*****************************************/
/*           E2nodeComponentConfigUpdate_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigUpdate_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_E2nodeComponentConfigUpdate_ItemIEs_E2nodeComponentConfigUpdate_Item   
   

} e2ap_E2nodeComponentConfigUpdate_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2nodeComponentConfigUpdate_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2nodeComponentConfigUpdate_ItemIEs_TVALUE t;
      union {
         e2ap_E2nodeComponentConfigUpdate_Item * _e2apE2nodeComponentConfigUpdate_ItemIEs_E2nodeComponentConfigUpdate_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2nodeComponentConfigUpdate_ItemIEs;

EXTERN int  asn1PE_e2ap_E2nodeComponentConfigUpdate_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdate_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_E2nodeComponentConfigUpdate_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdate_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigUpdate_ItemIEs (e2ap_E2nodeComponentConfigUpdate_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigUpdate_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdate_ItemIEs* pvalue);

// --- End of e2ap_E2nodeComponentConfigUpdate_ItemIEs.h ---

// --- Begin of e2ap_E2nodeComponentConfigUpdate_List.h ---
/*****************************************/
/*           E2nodeComponentConfigUpdate_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_E2nodeComponentConfigUpdate_List;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigUpdate_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdate_List* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigUpdate_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdate_List* ppvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigUpdate_List (e2ap_E2nodeComponentConfigUpdate_List* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigUpdate_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigUpdate_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentConfigUpdate_List (const char* name, e2ap_E2nodeComponentConfigUpdate_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_E2nodeComponentConfigUpdate_List (OSCTXT* pctxt, const e2ap_E2nodeComponentConfigUpdate_List* pSrcValue, e2ap_E2nodeComponentConfigUpdate_List* pDstValue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigUpdate_List (const char *name, const e2ap_E2nodeComponentConfigUpdate_List* pvalue);
// --- End of e2ap_E2nodeComponentConfigUpdate_List.h ---

// --- Begin of e2ap_E2nodeComponentConfigRemoval_Item.h ---
/*****************************************/
/*           E2nodeComponentConfigRemoval_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeComponentConfigRemoval_Item {
   e2ap_E2nodeComponentInterfaceType e2nodeComponentInterfaceType;
   e2ap_E2nodeComponentID e2nodeComponentID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentConfigRemoval_Item;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigRemoval_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemoval_Item* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigRemoval_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemoval_Item* pvalue);
EXTERN int asn1Init_e2ap_E2nodeComponentConfigRemoval_Item (e2ap_E2nodeComponentConfigRemoval_Item* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigRemoval_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemoval_Item* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigRemoval_Item (const char* name, const e2ap_E2nodeComponentConfigRemoval_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentConfigRemoval_Item (const char* name, e2ap_E2nodeComponentConfigRemoval_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeComponentConfigRemoval_Item (OSCTXT* pctxt, const char* name, const e2ap_E2nodeComponentConfigRemoval_Item* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeComponentConfigRemoval_Item (OSCTXT* pctxt, const e2ap_E2nodeComponentConfigRemoval_Item* pSrcValue, e2ap_E2nodeComponentConfigRemoval_Item* pDstValue);
// --- End of e2ap_E2nodeComponentConfigRemoval_Item.h ---

// --- Begin of e2ap_E2nodeComponentConfigRemoval_ItemIEs.h ---
/* e2ap_E2nodeComponentConfigRemoval_ItemIEs.h */

/*****************************************/
/*           E2nodeComponentConfigRemoval_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_E2nodeComponentConfigRemoval_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_E2nodeComponentConfigRemoval_ItemIEs_E2nodeComponentConfigRemoval_Item   
   

} e2ap_E2nodeComponentConfigRemoval_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2nodeComponentConfigRemoval_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2nodeComponentConfigRemoval_ItemIEs_TVALUE t;
      union {
         e2ap_E2nodeComponentConfigRemoval_Item * _e2apE2nodeComponentConfigRemoval_ItemIEs_E2nodeComponentConfigRemoval_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2nodeComponentConfigRemoval_ItemIEs;

EXTERN int  asn1PE_e2ap_E2nodeComponentConfigRemoval_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemoval_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_E2nodeComponentConfigRemoval_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemoval_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigRemoval_ItemIEs (e2ap_E2nodeComponentConfigRemoval_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigRemoval_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemoval_ItemIEs* pvalue);

// --- End of e2ap_E2nodeComponentConfigRemoval_ItemIEs.h ---

// --- Begin of e2ap_E2nodeComponentConfigRemoval_List.h ---
/*****************************************/
/*           E2nodeComponentConfigRemoval_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_E2nodeComponentConfigRemoval_List;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigRemoval_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemoval_List* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigRemoval_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemoval_List* ppvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigRemoval_List (e2ap_E2nodeComponentConfigRemoval_List* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigRemoval_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigRemoval_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentConfigRemoval_List (const char* name, e2ap_E2nodeComponentConfigRemoval_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_E2nodeComponentConfigRemoval_List (OSCTXT* pctxt, const e2ap_E2nodeComponentConfigRemoval_List* pSrcValue, e2ap_E2nodeComponentConfigRemoval_List* pDstValue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigRemoval_List (const char *name, const e2ap_E2nodeComponentConfigRemoval_List* pvalue);
// --- End of e2ap_E2nodeComponentConfigRemoval_List.h ---

/**************************************/
/* File .h missing: e2ap_tnlAddress.h */
/**************************************/

/***********************************/
/* File .h missing: e2ap_tnlPort.h */
/***********************************/

// --- Begin of e2ap_TNLinformation.h ---
/*****************************************/
/*           TNLinformation                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_TNLinformation {
   ASN1BitStr32 tnlAddress;
   ASN1BitStr32 tnlPort;
     OSBOOL m_tnlPortPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_TNLinformation;

EXTERN int asn1PE_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue);
EXTERN int asn1PD_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue);
EXTERN int asn1Init_e2ap_TNLinformation (e2ap_TNLinformation* pvalue);
EXTERN void asn1Free_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue);
EXTERN void asn1Print_e2ap_TNLinformation (const char* name, const e2ap_TNLinformation* pvalue);
EXTERN int asn1PrtToStr_e2ap_TNLinformation (const char* name, e2ap_TNLinformation* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_TNLinformation (OSCTXT* pctxt, const char* name, const e2ap_TNLinformation* pvalue);
EXTERN int asn1Copy_e2ap_TNLinformation (OSCTXT* pctxt, const e2ap_TNLinformation* pSrcValue, e2ap_TNLinformation* pDstValue);
// --- End of e2ap_TNLinformation.h ---

// --- Begin of e2ap_E2nodeTNLassociationRemoval_Item.h ---
/*****************************************/
/*           E2nodeTNLassociationRemoval_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeTNLassociationRemoval_Item {
   e2ap_TNLinformation tnlInformation;
   e2ap_TNLinformation tnlInformationRIC;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeTNLassociationRemoval_Item;

EXTERN int asn1PE_e2ap_E2nodeTNLassociationRemoval_Item (OSCTXT* pctxt, e2ap_E2nodeTNLassociationRemoval_Item* pvalue);
EXTERN int asn1PD_e2ap_E2nodeTNLassociationRemoval_Item (OSCTXT* pctxt, e2ap_E2nodeTNLassociationRemoval_Item* pvalue);
EXTERN int asn1Init_e2ap_E2nodeTNLassociationRemoval_Item (e2ap_E2nodeTNLassociationRemoval_Item* pvalue);
EXTERN void asn1Free_e2ap_E2nodeTNLassociationRemoval_Item (OSCTXT* pctxt, e2ap_E2nodeTNLassociationRemoval_Item* pvalue);
EXTERN void asn1Print_e2ap_E2nodeTNLassociationRemoval_Item (const char* name, const e2ap_E2nodeTNLassociationRemoval_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeTNLassociationRemoval_Item (const char* name, e2ap_E2nodeTNLassociationRemoval_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeTNLassociationRemoval_Item (OSCTXT* pctxt, const char* name, const e2ap_E2nodeTNLassociationRemoval_Item* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeTNLassociationRemoval_Item (OSCTXT* pctxt, const e2ap_E2nodeTNLassociationRemoval_Item* pSrcValue, e2ap_E2nodeTNLassociationRemoval_Item* pDstValue);
// --- End of e2ap_E2nodeTNLassociationRemoval_Item.h ---

// --- Begin of e2ap_E2nodeTNLassociationRemoval_ItemIEs.h ---
/* e2ap_E2nodeTNLassociationRemoval_ItemIEs.h */

/*****************************************/
/*           E2nodeTNLassociationRemoval_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_E2nodeTNLassociationRemoval_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_E2nodeTNLassociationRemoval_ItemIEs_E2nodeTNLassociationRemoval_Item   
   

} e2ap_E2nodeTNLassociationRemoval_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2nodeTNLassociationRemoval_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2nodeTNLassociationRemoval_ItemIEs_TVALUE t;
      union {
         e2ap_E2nodeTNLassociationRemoval_Item * _e2apE2nodeTNLassociationRemoval_ItemIEs_E2nodeTNLassociationRemoval_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2nodeTNLassociationRemoval_ItemIEs;

EXTERN int  asn1PE_e2ap_E2nodeTNLassociationRemoval_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeTNLassociationRemoval_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_E2nodeTNLassociationRemoval_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeTNLassociationRemoval_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_E2nodeTNLassociationRemoval_ItemIEs (e2ap_E2nodeTNLassociationRemoval_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_E2nodeTNLassociationRemoval_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeTNLassociationRemoval_ItemIEs* pvalue);

// --- End of e2ap_E2nodeTNLassociationRemoval_ItemIEs.h ---

// --- Begin of e2ap_E2nodeTNLassociationRemoval_List.h ---
/*****************************************/
/*           E2nodeTNLassociationRemoval_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_E2nodeTNLassociationRemoval_List;

EXTERN int asn1PE_e2ap_E2nodeTNLassociationRemoval_List (OSCTXT* pctxt, e2ap_E2nodeTNLassociationRemoval_List* pvalue);
EXTERN int asn1PD_e2ap_E2nodeTNLassociationRemoval_List (OSCTXT* pctxt, e2ap_E2nodeTNLassociationRemoval_List* ppvalue);
EXTERN void asn1Init_e2ap_E2nodeTNLassociationRemoval_List (e2ap_E2nodeTNLassociationRemoval_List* pvalue);
EXTERN void asn1Free_e2ap_E2nodeTNLassociationRemoval_List (OSCTXT* pctxt, e2ap_E2nodeTNLassociationRemoval_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeTNLassociationRemoval_List (const char* name, e2ap_E2nodeTNLassociationRemoval_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_E2nodeTNLassociationRemoval_List (OSCTXT* pctxt, const e2ap_E2nodeTNLassociationRemoval_List* pSrcValue, e2ap_E2nodeTNLassociationRemoval_List* pDstValue);
EXTERN void asn1Print_e2ap_E2nodeTNLassociationRemoval_List (const char *name, const e2ap_E2nodeTNLassociationRemoval_List* pvalue);
// --- End of e2ap_E2nodeTNLassociationRemoval_List.h ---

/*********************************************************/
/* File .h missing: e2ap_E2nodeConfigurationUpdate_IEs.h */
/*********************************************************/

// --- Begin of e2ap_E2nodeConfigurationUpdate.h ---
/*****************************************/
/*           E2nodeConfigurationUpdate                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2nodeConfigurationUpdate {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeConfigurationUpdate;

EXTERN int asn1PE_e2ap_E2nodeConfigurationUpdate (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate* pvalue);
EXTERN int asn1PD_e2ap_E2nodeConfigurationUpdate (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate* pvalue);
EXTERN int asn1Init_e2ap_E2nodeConfigurationUpdate (e2ap_E2nodeConfigurationUpdate* pvalue);
EXTERN void asn1Free_e2ap_E2nodeConfigurationUpdate (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate* pvalue);
EXTERN void asn1Print_e2ap_E2nodeConfigurationUpdate (const char* name, const e2ap_E2nodeConfigurationUpdate* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeConfigurationUpdate (const char* name, e2ap_E2nodeConfigurationUpdate* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2nodeConfigurationUpdate (OSCTXT* pctxt, const char* name, const e2ap_E2nodeConfigurationUpdate* pvalue);
EXTERN int asn1Copy_e2ap_E2nodeConfigurationUpdate (OSCTXT* pctxt, const e2ap_E2nodeConfigurationUpdate* pSrcValue, e2ap_E2nodeConfigurationUpdate* pDstValue);
// --- End of e2ap_E2nodeConfigurationUpdate.h ---

// --- Begin of e2ap_E2nodeConfigurationUpdate_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    E2nodeConfigurationUpdate_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from E2nodeConfigurationUpdate*/

typedef OSRTDList e2ap_E2nodeConfigurationUpdate_protocolIEs;

EXTERN int asn1PE_e2ap_E2nodeConfigurationUpdate_protocolIEs (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_E2nodeConfigurationUpdate_protocolIEs (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_E2nodeConfigurationUpdate_protocolIEs (e2ap_E2nodeConfigurationUpdate_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_E2nodeConfigurationUpdate_protocolIEs (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeConfigurationUpdate_protocolIEs (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apE2nodeConfigurationUpdate_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_E2nodeConfigurationUpdate_protocolIEs* pvalue);
// --- End of e2ap_E2nodeConfigurationUpdate_protocolIEs.h ---

// --- Begin of e2ap_E2nodeConfigurationUpdate_protocolIEs_element.h ---
/*****************************************/
/*    E2nodeConfigurationUpdate_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from E2nodeConfigurationUpdate*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_id_TransactionID,

   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_id_GlobalE2node_ID,

   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_id_E2nodeComponentConfigAddition,

   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_id_E2nodeComponentConfigUpdate,

   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_id_E2nodeComponentConfigRemoval,

   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_id_E2nodeTNLassociationRemoval,

   T_E2AP_PDU_Contents_e2ap_E2nodeConfigurationUpdate_IEs_id_Extended_RANNodeName_

}e2ap_E2nodeConfigurationUpdate_IEs_TVALUE;


typedef struct EXTERN e2ap_E2nodeConfigurationUpdate_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2nodeConfigurationUpdate_IEs_TVALUE t;
      union {
        /*
        *id: id-TransactionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_TransactionID *_e2ap_E2nodeConfigurationUpdate_IEs_id_TransactionID;


        /*
        *id: id-GlobalE2node-ID
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_GlobalE2node_ID *_e2ap_E2nodeConfigurationUpdate_IEs_id_GlobalE2node_ID;


        /*
        *id: id-E2nodeComponentConfigAddition-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_E2nodeComponentConfigAddition_List *_e2ap_E2nodeConfigurationUpdate_IEs_id_E2nodeComponentConfigAddition;


        /*
        *id: id-E2nodeComponentConfigUpdate-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_E2nodeComponentConfigUpdate_List *_e2ap_E2nodeConfigurationUpdate_IEs_id_E2nodeComponentConfigUpdate;


        /*
        *id: id-E2nodeComponentConfigRemoval-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_E2nodeComponentConfigRemoval_List *_e2ap_E2nodeConfigurationUpdate_IEs_id_E2nodeComponentConfigRemoval;


        /*
        *id: id-E2nodeTNLassociationRemoval-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_E2nodeTNLassociationRemoval_List *_e2ap_E2nodeConfigurationUpdate_IEs_id_E2nodeTNLassociationRemoval;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_E2nodeConfigurationUpdate_protocolIEs_element;


EXTERN int asn1PE_e2ap_E2nodeConfigurationUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_E2nodeConfigurationUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_E2nodeConfigurationUpdate_protocolIEs_element (e2ap_E2nodeConfigurationUpdate_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_E2nodeConfigurationUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeConfigurationUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2nodeConfigurationUpdate_protocolIEs_element* pvalue);
// --- End of e2ap_E2nodeConfigurationUpdate_protocolIEs_element.h ---

#endif
