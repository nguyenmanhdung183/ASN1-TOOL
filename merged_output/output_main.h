
#ifndef OUTPUT_MAIN_H
#define OUTPUT_MAIN_H

// --- Begin of doc/header.h ---
//======================E2AP.h========================//
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
   e2ap_PLMN-Identity plmn_id;
   e2ap_GNB-ID-Choice gnb_id;

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
   e2ap_PLMN-Identity pLMN_Identity;
   e2ap_ENGNB-ID gNB_ID;

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
   e2ap_GlobalgNB-ID global_gNB_ID;
   e2ap_GlobalenGNB-ID global_en_gNB_ID;
     OSBOOL m_global_en_gNB_IDPresent;   e2ap_GNB-CU-UP-ID gNB_CU_UP_ID;
     OSBOOL m_gNB_CU_UP_IDPresent;   e2ap_GNB-DU-ID gNB_DU_ID;
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
   e2ap_GlobalenGNB-ID global_en_gNB_ID;
   e2ap_GNB-CU-UP-ID en_gNB_CU_UP_ID;
     OSBOOL m_en_gNB_CU_UP_IDPresent;   e2ap_GNB-DU-ID en_gNB_DU_ID;
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
   e2ap_PLMN-Identity plmn_id;
   e2ap_ENB-ID-Choice enb_id;

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
   e2ap_PLMN-Identity pLMN_Identity;
   e2ap_ENB-ID eNB_ID;

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
   e2ap_GlobalngeNB-ID global_ng_eNB_ID;
   e2ap_GlobalENB-ID global_eNB_ID;
     OSBOOL m_global_eNB_IDPresent;   e2ap_NGENB-DU-ID ngENB_DU_ID;
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
   e2ap_GlobalENB-ID global_eNB_ID;

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

// --- Begin of e2ap_RANfunctionID.h ---
/*****************************************/
/*        RANfunctionID         */
/*****************************************/
//interger no ext


typedef OSUINT16 e2ap_RANfunctionID;

EXTERN int asn1PE_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID value);
EXTERN int asn1PD_e2ap_RANfunctionID (OSCTXT* pctxt, e2ap_RANfunctionID* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionID (const char* name, const e2ap_RANfunctionID* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionID (const char* name, e2ap_RANfunctionID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionID (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionID* pvalue);
// --- End of e2ap_RANfunctionID.h ---

// --- Begin of e2ap_RANfunctionDefinition.h ---
/*****************************************/
/*           RANfunctionDefinition                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RANfunctionDefinition;

EXTERN int asn1PE_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition** ppvalue);
EXTERN void asn1Print_e2ap_RANfunctionDefinition (const char* name, const e2ap_RANfunctionDefinition* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionDefinition (const char* name, e2ap_RANfunctionDefinition* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionDefinition (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionDefinition* pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionDefinition (OSCTXT* pctxt, const e2ap_RANfunctionDefinition* pSrcValue, e2ap_RANfunctionDefinition* pDstValue);
EXTERN int asn1Init_e2ap_RANfunctionDefinition (e2ap_RANfunctionDefinition* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition* pvalue);
// --- End of e2ap_RANfunctionDefinition.h ---

// --- Begin of e2ap_RANfunctionRevision.h ---
/*****************************************/
/*        RANfunctionRevision         */
/*****************************************/
//interger no ext


typedef OSUINT16 e2ap_RANfunctionRevision;

EXTERN int asn1PE_e2ap_RANfunctionRevision (OSCTXT* pctxt, e2ap_RANfunctionRevision value);
EXTERN int asn1PD_e2ap_RANfunctionRevision (OSCTXT* pctxt, e2ap_RANfunctionRevision* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionRevision (const char* name, const e2ap_RANfunctionRevision* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionRevision (const char* name, e2ap_RANfunctionRevision* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionRevision (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionRevision* pvalue);
// --- End of e2ap_RANfunctionRevision.h ---

/*******************************************/
/* File .h missing: e2ap_PrintableString.h */
/*******************************************/

// --- Begin of e2ap_RANfunctionOID.h ---
/* e2ap_RANfunctionOID.h */

//printable string
/*****************************************/
/*           RANfunctionOID                */
/*****************************************/


typedef const char* e2ap_RANfunctionOID;

EXTERN int asn1PE_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID value);
EXTERN int asn1PD_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID* ppvalue);
EXTERN void asn1Print_e2ap_RANfunctionOID (const char* name, e2ap_RANfunctionOID pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionOID (const char* name, e2ap_RANfunctionOID pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionOID (OSCTXT* pctxt, const char* name, e2ap_RANfunctionOID pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID pSrcValue, e2ap_RANfunctionOID* pDstValue);
EXTERN void asn1Free_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID pvalue);
// --- End of e2ap_RANfunctionOID.h ---

// --- Begin of e2ap_RANfunction_Item.h ---
/*****************************************/
/*           RANfunction_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RANfunction_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_RANfunctionDefinition ranFunctionDefinition;
   e2ap_RANfunctionRevision ranFunctionRevision;
   e2ap_RANfunctionOID ranFunctionOID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RANfunction_Item;

EXTERN int asn1PE_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN int asn1Init_e2ap_RANfunction_Item (e2ap_RANfunction_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunction_Item (const char* name, const e2ap_RANfunction_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunction_Item (const char* name, e2ap_RANfunction_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunction_Item (OSCTXT* pctxt, const char* name, const e2ap_RANfunction_Item* pvalue);
EXTERN int asn1Copy_e2ap_RANfunction_Item (OSCTXT* pctxt, const e2ap_RANfunction_Item* pSrcValue, e2ap_RANfunction_Item* pDstValue);
// --- End of e2ap_RANfunction_Item.h ---

// --- Begin of e2ap_RANfunction_ItemIEs.h ---
/* e2ap_RANfunction_ItemIEs.h */

/*****************************************/
/*           RANfunction_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RANfunction_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RANfunction_ItemIEs_RANfunction_Item   
   

} e2ap_RANfunction_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RANfunction_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RANfunction_ItemIEs_TVALUE t;
      union {
         e2ap_RANfunction-Item * _e2apRANfunction_ItemIEs_RANfunction_Item

         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RANfunction_ItemIEs;

EXTERN int  asn1PE_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RANfunction_ItemIEs (e2ap_RANfunction_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue);

// --- End of e2ap_RANfunction_ItemIEs.h ---

// --- Begin of e2ap_RANfunctions_List.h ---
/*****************************************/
/*           RANfunctions_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RANfunctions_List;

EXTERN int asn1PE_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List* pvalue);
EXTERN int asn1PD_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List** ppvalue);
EXTERN void asn1Init_e2ap_RANfunctions_List (e2ap_RANfunctions_List* pvalue);
EXTERN void asn1Free_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctions_List (const char* name, e2ap_RANfunctions_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RANfunctions_List (OSCTXT* pctxt, const e2ap_RANfunctions_List* pSrcValue, e2ap_RANfunctions_List* pDstValue);
EXTERN void asn1Print_e2ap_RANfunctions_List (const char *name, const e2ap_* pvalue);
// --- End of e2ap_RANfunctions_List.h ---

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
   e2ap_GlobalNG-RANNode-ID global_NG_RAN_Node_ID;

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
   e2ap_GNB-CU-UP-ID gNB_CU_UP_ID;

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
   e2ap_GNB-DU-ID gNB_DU_ID;

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
   e2ap_NGENB-DU-ID ng_eNB_DU_ID;

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
   e2ap_GlobalENB-ID global_eNB_ID;
     OSBOOL m_global_eNB_IDPresent;   e2ap_GlobalenGNB-ID global_en_gNB_ID;
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
         e2ap_E2nodeComponentConfigAddition-Item * _e2apE2nodeComponentConfigAddition_ItemIEs_E2nodeComponentConfigAddition_Item

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
EXTERN int asn1PD_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List** ppvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigAddition_List (e2ap_E2nodeComponentConfigAddition_List* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentConfigAddition_List (const char* name, e2ap_E2nodeComponentConfigAddition_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, const e2ap_E2nodeComponentConfigAddition_List* pSrcValue, e2ap_E2nodeComponentConfigAddition_List* pDstValue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigAddition_List (const char *name, const e2ap_* pvalue);
// --- End of e2ap_E2nodeComponentConfigAddition_List.h ---

/*********************************************/
/* File .h missing: e2ap_E2setupRequestIEs.h */
/*********************************************/

// --- Begin of e2ap_E2setupRequest.h ---
/*****************************************/
/*           E2setupRequest                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2setupRequest {
   e2ap_ProtocolIE-Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2setupRequest;

EXTERN int asn1PE_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue);
EXTERN int asn1PD_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue);
EXTERN int asn1Init_e2ap_E2setupRequest (e2ap_E2setupRequest* pvalue);
EXTERN void asn1Free_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue);
EXTERN void asn1Print_e2ap_E2setupRequest (const char* name, const e2ap_E2setupRequest* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2setupRequest (const char* name, e2ap_E2setupRequest* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2setupRequest (OSCTXT* pctxt, const char* name, const e2ap_E2setupRequest* pvalue);
EXTERN int asn1Copy_e2ap_E2setupRequest (OSCTXT* pctxt, const e2ap_E2setupRequest* pSrcValue, e2ap_E2setupRequest* pDstValue);
// --- End of e2ap_E2setupRequest.h ---

// --- Begin of e2ap_E2setupRequest_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    E2setupRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from E2setupRequest*/

typedef OSRTDList e2ap_E2setupRequest_protocolIEs;

EXTERN int asn1PE_e2ap_E2setupRequest_protocolIEs (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_E2setupRequest_protocolIEs (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_E2setupRequest_protocolIEs (e2ap_E2setupRequest_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_E2setupRequest_protocolIEs (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2setupRequest_protocolIEs (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apE2setupRequest_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_E2setupRequest_protocolIEs* pvalue);
// --- End of e2ap_E2setupRequest_protocolIEs.h ---

// --- Begin of e2ap_E2setupRequest_protocolIEs_element.h ---
/*****************************************/
/*    E2setupRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from E2setupRequest*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2setupRequest_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_TransactionID,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_GlobalE2node_ID,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_RANfunctionsAdded,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_Extended_RANNodeName_
}


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_TransactionID ,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_GlobalE2node_ID ,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_RANfunctions_List ,
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition_List 
   T_E2AP_PDU_Contents_e2ap_E2setupRequestIEs_id_Extended_RANNodeName_

}e2ap_E2setupRequestIEs_TVALUE;


typedef struct EXTERN e2ap_E2setupRequest_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2setupRequestIEs_TVALUE t;
      union {
        /*
        *id: id-TransactionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_TransactionID *_e2ap_E2setupRequestIEs_id_TransactionID,

        /*
        *id: id-GlobalE2node-ID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_GlobalE2node_ID *_e2ap_E2setupRequestIEs_id_GlobalE2node_ID,

        /*
        *id: id-RANfunctions-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctions_List *_e2ap_E2setupRequestIEs_id_RANfunctionsAdded,

        /*
        *id: id-E2nodeComponentConfigAddition-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_E2nodeComponentConfigAddition_List *_e2ap_E2setupRequestIEs_id_E2nodeComponentConfigAddition


        ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2setupRequest_protocolIEs_element;


EXTERN int asn1PE_e2ap_E2setupRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_E2setupRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_E2setupRequest_protocolIEs_element (e2ap_E2setupRequest_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_E2setupRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2setupRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_E2setupRequest_protocolIEs_element* pvalue);
// --- End of e2ap_E2setupRequest_protocolIEs_element.h ---

#endif
