// --- Begin of e2ap_TransactionID.h ---
/* e2ap_TransactionID.h */

//interger with ext
/*****************************************/
/*           TransactionID                */
/*****************************************/


typedef OSUINT8 e2ap_TransactionID;

EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value);
EXTERN int asn1PD_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID* pvalue);
EXTERN void asn1Print_e2ap_TransactionID (const char* name, const e2ap_TransactionID* pvalue);
EXTERN int asn1PrtToStr_e2ap_TransactionID (const char* name, e2ap_TransactionID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_TransactionID (OSCTXT* pctxt, const char* name, const e2ap_TransactionID* pvalue);
// --- End of e2ap_TransactionID.h ---

// --- Begin of e2ap_PLMN_Identity.h ---
/* e2ap_PLMN_Identity.h */

//octet string

/*****************************************/
/*           PLMN_Identity                */
/*****************************************/


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

// choice

/*****************************************/
/*           GNB_ID_Choice                */
/*****************************************/

#define T_e2ap_GNB_ID_Choice_gnb_ID 1
#define T_e2ap_GNB_ID_Choice_extElem1 2

typedef struct e2ap_GNB_ID_Choice {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      ASN1BitStr32* gnb_ID;

      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_GNB_ID_Choice;

EXTERN int asn1PE_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue);
EXTERN int asn1PD_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue);
EXTERN void asn1Print_e2ap_GNB_ID_Choice (const char* name, const e2ap_GNB_ID_Choice* pvalue);
EXTERN int asn1PrtToStr_e2ap_GNB_ID_Choice (const char* name, e2ap_GNB_ID_Choice* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_GNB_ID_Choice (OSCTXT* pctxt, const e2ap_GNB_ID_Choice* pSrcValue, e2ap_GNB_ID_Choice* pDstValue);
EXTERN int asn1Init_e2ap_GNB_ID_Choice (e2ap_GNB_ID_Choice* pvalue);
EXTERN void asn1Free_e2ap_GNB_ID_Choice (OSCTXT* pctxt, e2ap_GNB_ID_Choice* pvalue);

// --- End of e2ap_GNB_ID_Choice.h ---

// --- Begin of e2ap_GlobalgNB_ID.h ---

//seq normal

/*****************************************/
/*           GlobalgNB_ID                */
/*****************************************/


typedef struct EXTERN e2ap_GlobalgNB_ID {
   e2ap_PLMN-Identity plmn_id;
   e2ap_GNB-ID-Choice gnb_id;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalgNB_ID;

EXTERN int asn1PE_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue);
EXTERN void asn1Init_e2ap_GlobalgNB_ID (e2ap_GlobalgNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalgNB_ID (OSCTXT* pctxt, e2ap_GlobalgNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalgNB_ID (const char* name, const e2ap_GlobalgNB_ID* pvalue);
// --- End of e2ap_GlobalgNB_ID.h ---

/**********************************/
/* File .h missing: e2ap_gNB_ID.h */
/**********************************/

// --- Begin of e2ap_ENGNB_ID.h ---

// choice

/*****************************************/
/*           ENGNB_ID                */
/*****************************************/

#define T_e2ap_ENGNB_ID_gNB_ID 1
#define T_e2ap_ENGNB_ID_extElem1 2

typedef struct e2ap_ENGNB_ID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      ASN1BitStr32* gNB_ID;

      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_ENGNB_ID;

EXTERN int asn1PE_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue);
EXTERN int asn1PD_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue);
EXTERN void asn1Print_e2ap_ENGNB_ID (const char* name, const e2ap_ENGNB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_ENGNB_ID (const char* name, e2ap_ENGNB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_ENGNB_ID (OSCTXT* pctxt, const e2ap_ENGNB_ID* pSrcValue, e2ap_ENGNB_ID* pDstValue);
EXTERN int asn1Init_e2ap_ENGNB_ID (e2ap_ENGNB_ID* pvalue);
EXTERN void asn1Free_e2ap_ENGNB_ID (OSCTXT* pctxt, e2ap_ENGNB_ID* pvalue);

// --- End of e2ap_ENGNB_ID.h ---

// --- Begin of e2ap_GlobalenGNB_ID.h ---

//seq normal

/*****************************************/
/*           GlobalenGNB_ID                */
/*****************************************/


typedef struct EXTERN e2ap_GlobalenGNB_ID {
   e2ap_PLMN-Identity pLMN_Identity;
   e2ap_ENGNB-ID gNB_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalenGNB_ID;

EXTERN int asn1PE_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue);
EXTERN void asn1Init_e2ap_GlobalenGNB_ID (e2ap_GlobalenGNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalenGNB_ID (OSCTXT* pctxt, e2ap_GlobalenGNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalenGNB_ID (const char* name, const e2ap_GlobalenGNB_ID* pvalue);
// --- End of e2ap_GlobalenGNB_ID.h ---

// --- Begin of e2ap_GNB_CU_UP_ID.h ---
/* e2ap_GNB_CU_UP_ID.h */


//interger no ext
/*****************************************/
/*           GNB_CU_UP_ID                */
/*****************************************/


typedef OSUINT32 e2ap_GNB_CU_UP_ID;

EXTERN int asn1PE_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID value);
EXTERN int asn1PD_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID* pvalue);
EXTERN void asn1Print_e2ap_GNB_CU_UP_ID (const char* name, const e2ap_GNB_CU_UP_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GNB_CU_UP_ID (const char* name, e2ap_GNB_CU_UP_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, const char* name, const e2ap_GNB_CU_UP_ID* pvalue);
// --- End of e2ap_GNB_CU_UP_ID.h ---

// --- Begin of e2ap_GNB_DU_ID.h ---
/* e2ap_GNB_DU_ID.h */


//interger no ext
/*****************************************/
/*           GNB_DU_ID                */
/*****************************************/


typedef OSUINT32 e2ap_GNB_DU_ID;

EXTERN int asn1PE_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID value);
EXTERN int asn1PD_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID* pvalue);
EXTERN void asn1Print_e2ap_GNB_DU_ID (const char* name, const e2ap_GNB_DU_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GNB_DU_ID (const char* name, e2ap_GNB_DU_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GNB_DU_ID (OSCTXT* pctxt, const char* name, const e2ap_GNB_DU_ID* pvalue);
// --- End of e2ap_GNB_DU_ID.h ---

// --- Begin of e2ap_GlobalE2node_gNB_ID.h ---

//seq normal

/*****************************************/
/*           GlobalE2node_gNB_ID                */
/*****************************************/


typedef struct EXTERN e2ap_GlobalE2node_gNB_ID {
   e2ap_GlobalgNB-ID global_gNB_ID;
   e2ap_GlobalenGNB-ID global_en_gNB_ID;
OSBOOL m_global-en-gNB-IDPresent;   e2ap_GNB-CU-UP-ID gNB_CU_UP_ID;
OSBOOL m_gNB-CU-UP-IDPresent;   e2ap_GNB-DU-ID gNB_DU_ID;
OSBOOL m_gNB-DU-IDPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalE2node_gNB_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN void asn1Init_e2ap_GlobalE2node_gNB_ID (e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_gNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_gNB_ID (const char* name, const e2ap_GlobalE2node_gNB_ID* pvalue);
// --- End of e2ap_GlobalE2node_gNB_ID.h ---

// --- Begin of e2ap_GlobalE2node_en_gNB_ID.h ---

//seq normal

/*****************************************/
/*           GlobalE2node_en_gNB_ID                */
/*****************************************/


typedef struct EXTERN e2ap_GlobalE2node_en_gNB_ID {
   e2ap_GlobalenGNB-ID global_en_gNB_ID;
   e2ap_GNB-CU-UP-ID en_gNB_CU_UP_ID;
OSBOOL m_en-gNB-CU-UP-IDPresent;   e2ap_GNB-DU-ID en_gNB_DU_ID;
OSBOOL m_en-gNB-DU-IDPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalE2node_en_gNB_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN void asn1Init_e2ap_GlobalE2node_en_gNB_ID (e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_en_gNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_en_gNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_en_gNB_ID (const char* name, const e2ap_GlobalE2node_en_gNB_ID* pvalue);
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

// choice

/*****************************************/
/*           ENB_ID_Choice                */
/*****************************************/

#define T_e2ap_ENB_ID_Choice_enb_ID_macro 1
#define T_e2ap_ENB_ID_Choice_enb_ID_shortmacro 2
#define T_e2ap_ENB_ID_Choice_enb_ID_longmacro 3
#define T_e2ap_ENB_ID_Choice_extElem1 2

typedef struct e2ap_ENB_ID_Choice {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      ASN1BitStr32* enb_ID_macro;
      /* t =  2 */
      ASN1BitStr32* enb_ID_shortmacro;
      /* t =  3 */
      ASN1BitStr32* enb_ID_longmacro;

      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_ENB_ID_Choice;

EXTERN int asn1PE_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue);
EXTERN int asn1PD_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue);
EXTERN void asn1Print_e2ap_ENB_ID_Choice (const char* name, const e2ap_ENB_ID_Choice* pvalue);
EXTERN int asn1PrtToStr_e2ap_ENB_ID_Choice (const char* name, e2ap_ENB_ID_Choice* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_ENB_ID_Choice (OSCTXT* pctxt, const e2ap_ENB_ID_Choice* pSrcValue, e2ap_ENB_ID_Choice* pDstValue);
EXTERN int asn1Init_e2ap_ENB_ID_Choice (e2ap_ENB_ID_Choice* pvalue);
EXTERN void asn1Free_e2ap_ENB_ID_Choice (OSCTXT* pctxt, e2ap_ENB_ID_Choice* pvalue);

// --- End of e2ap_ENB_ID_Choice.h ---

// --- Begin of e2ap_GlobalngeNB_ID.h ---

//seq normal

/*****************************************/
/*           GlobalngeNB_ID                */
/*****************************************/


typedef struct EXTERN e2ap_GlobalngeNB_ID {
   e2ap_PLMN-Identity plmn_id;
   e2ap_ENB-ID-Choice enb_id;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalngeNB_ID;

EXTERN int asn1PE_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue);
EXTERN void asn1Init_e2ap_GlobalngeNB_ID (e2ap_GlobalngeNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalngeNB_ID (OSCTXT* pctxt, e2ap_GlobalngeNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalngeNB_ID (const char* name, const e2ap_GlobalngeNB_ID* pvalue);
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

// choice

/*****************************************/
/*           ENB_ID                */
/*****************************************/

#define T_e2ap_ENB_ID_macro_eNB_ID 1
#define T_e2ap_ENB_ID_home_eNB_ID 2
#define T_e2ap_ENB_ID_short_Macro_eNB_ID 3
#define T_e2ap_ENB_ID_long_Macro_eNB_ID 4
#define T_e2ap_ENB_ID_extElem1 2

typedef struct e2ap_ENB_ID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      ASN1BitStr32* macro_eNB_ID;
      /* t =  2 */
      ASN1BitStr32* home_eNB_ID;
      /* t =  3 */
      ASN1BitStr32* short_Macro_eNB_ID;
      /* t =  4 */
      ASN1BitStr32* long_Macro_eNB_ID;

      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_ENB_ID;

EXTERN int asn1PE_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);
EXTERN int asn1PD_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);
EXTERN void asn1Print_e2ap_ENB_ID (const char* name, const e2ap_ENB_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_ENB_ID (const char* name, e2ap_ENB_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_ENB_ID (OSCTXT* pctxt, const e2ap_ENB_ID* pSrcValue, e2ap_ENB_ID* pDstValue);
EXTERN int asn1Init_e2ap_ENB_ID (e2ap_ENB_ID* pvalue);
EXTERN void asn1Free_e2ap_ENB_ID (OSCTXT* pctxt, e2ap_ENB_ID* pvalue);

// --- End of e2ap_ENB_ID.h ---

// --- Begin of e2ap_GlobalENB_ID.h ---

//seq normal

/*****************************************/
/*           GlobalENB_ID                */
/*****************************************/


typedef struct EXTERN e2ap_GlobalENB_ID {
   e2ap_PLMN-Identity pLMN_Identity;
   e2ap_ENB-ID eNB_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalENB_ID;

EXTERN int asn1PE_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue);
EXTERN void asn1Init_e2ap_GlobalENB_ID (e2ap_GlobalENB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalENB_ID (OSCTXT* pctxt, e2ap_GlobalENB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalENB_ID (const char* name, const e2ap_GlobalENB_ID* pvalue);
// --- End of e2ap_GlobalENB_ID.h ---

// --- Begin of e2ap_NGENB_DU_ID.h ---
/* e2ap_NGENB_DU_ID.h */


//interger no ext
/*****************************************/
/*           NGENB_DU_ID                */
/*****************************************/


typedef OSUINT32 e2ap_NGENB_DU_ID;

EXTERN int asn1PE_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID value);
EXTERN int asn1PD_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID* pvalue);
EXTERN void asn1Print_e2ap_NGENB_DU_ID (const char* name, const e2ap_NGENB_DU_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_NGENB_DU_ID (const char* name, e2ap_NGENB_DU_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_NGENB_DU_ID (OSCTXT* pctxt, const char* name, const e2ap_NGENB_DU_ID* pvalue);
// --- End of e2ap_NGENB_DU_ID.h ---

// --- Begin of e2ap_GlobalE2node_ng_eNB_ID.h ---

//seq normal

/*****************************************/
/*           GlobalE2node_ng_eNB_ID                */
/*****************************************/


typedef struct EXTERN e2ap_GlobalE2node_ng_eNB_ID {
   e2ap_GlobalngeNB-ID global_ng_eNB_ID;
   e2ap_GlobalENB-ID global_eNB_ID;
OSBOOL m_global-eNB-IDPresent;   e2ap_NGENB-DU-ID ngENB_DU_ID;
OSBOOL m_ngENB-DU-IDPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalE2node_ng_eNB_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN void asn1Init_e2ap_GlobalE2node_ng_eNB_ID (e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_ng_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ng_eNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_ng_eNB_ID (const char* name, const e2ap_GlobalE2node_ng_eNB_ID* pvalue);
// --- End of e2ap_GlobalE2node_ng_eNB_ID.h ---

// --- Begin of e2ap_GlobalE2node_eNB_ID.h ---

//seq normal

/*****************************************/
/*           GlobalE2node_eNB_ID                */
/*****************************************/


typedef struct EXTERN e2ap_GlobalE2node_eNB_ID {
   e2ap_GlobalENB-ID global_eNB_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_GlobalE2node_eNB_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN void asn1Init_e2ap_GlobalE2node_eNB_ID (e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_eNB_ID (OSCTXT* pctxt, e2ap_GlobalE2node_eNB_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_eNB_ID (const char* name, const e2ap_GlobalE2node_eNB_ID* pvalue);
// --- End of e2ap_GlobalE2node_eNB_ID.h ---

// --- Begin of e2ap_GlobalE2node_ID.h ---

// choice

/*****************************************/
/*           GlobalE2node_ID                */
/*****************************************/

#define T_e2ap_GlobalE2node_ID_gNB 1
#define T_e2ap_GlobalE2node_ID_en_gNB 2
#define T_e2ap_GlobalE2node_ID_ng_eNB 3
#define T_e2ap_GlobalE2node_ID_eNB 4
#define T_e2ap_GlobalE2node_ID_extElem1 2

typedef struct e2ap_GlobalE2node_ID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      e2ap_GlobalE2node-gNB-ID* gNB;
      /* t =  2 */
      e2ap_GlobalE2node-en-gNB-ID* en_gNB;
      /* t =  3 */
      e2ap_GlobalE2node-ng-eNB-ID* ng_eNB;
      /* t =  4 */
      e2ap_GlobalE2node-eNB-ID* eNB;

      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_GlobalE2node_ID;

EXTERN int asn1PE_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalE2node_ID (const char* name, const e2ap_GlobalE2node_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalE2node_ID (const char* name, e2ap_GlobalE2node_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_GlobalE2node_ID (OSCTXT* pctxt, const e2ap_GlobalE2node_ID* pSrcValue, e2ap_GlobalE2node_ID* pDstValue);
EXTERN int asn1Init_e2ap_GlobalE2node_ID (e2ap_GlobalE2node_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalE2node_ID (OSCTXT* pctxt, e2ap_GlobalE2node_ID* pvalue);

// --- End of e2ap_GlobalE2node_ID.h ---

/*********************************************/
/* File .h missing: e2ap_RANfunctions_List.h */
/*********************************************/

// --- Begin of e2ap_E2nodeComponentInterfaceType.h ---
/* e2ap_E2nodeComponentInterfaceType.h - enumurate*/
/* e2ap_E2nodeComponentInterfaceType.h */

//enumerated
/******************************************************/
/*                                                    */
/*    E2nodeComponentInterfaceType                                       */
/*                                                    */
/******************************************************/

typedef enum {
    e2ap_ng = 0,
    e2ap_xn = 1,
    e2ap_e1 = 2,
    e2ap_f1 = 3,
    e2ap_w1 = 4,
    e2ap_s1 = 5,
    e2ap_x2 = 6
//add other values as needed
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
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentInterfaceType (const char* name,const e2ap_E2nodeComponentInterfaceType* pvalue,char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_E2nodeComponentInterfaceType_ENUMTAB[];
#define e2ap_E2nodeComponentInterfaceType_ENUMTABSIZE 7

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_E2nodeComponentInterfaceType_ToString (OSUINT32 value);
EXTERN int e2ap_E2nodeComponentInterfaceType_ToEnum (OSCTXT* pctxt,const OSUTF8CHAR* value,e2ap_E2nodeComponentInterfaceType* pvalue);
EXTERN int e2ap_E2nodeComponentInterfaceType_ToEnum2 (OSCTXT* pctxt,const OSUTF8CHAR* value,OSSIZE valueLen,e2ap_E2nodeComponentInterfaceType* pvalue);
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
EXTERN int asn1Copy_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName pSrcValue, e2ap_AMFName* ppDstValue);
EXTERN void asn1Free_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName pvalue);
// --- End of e2ap_AMFName.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceNG.h ---

//seq normal

/*****************************************/
/*           E2nodeComponentInterfaceNG                */
/*****************************************/


typedef struct EXTERN e2ap_E2nodeComponentInterfaceNG {
   e2ap_AMFName amf_name;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceNG;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentInterfaceNG (e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceNG (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceNG* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceNG (const char* name, const e2ap_E2nodeComponentInterfaceNG* pvalue);
// --- End of e2ap_E2nodeComponentInterfaceNG.h ---

// --- Begin of e2ap_GlobalNG_RANNode_ID.h ---

// choice

/*****************************************/
/*           GlobalNG_RANNode_ID                */
/*****************************************/

#define T_e2ap_GlobalNG_RANNode_ID_gNB 1
#define T_e2ap_GlobalNG_RANNode_ID_ng_eNB 2
#define T_e2ap_GlobalNG_RANNode_ID_extElem1 2

typedef struct e2ap_GlobalNG_RANNode_ID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      e2ap_GlobalgNB-ID* gNB;
      /* t =  2 */
      e2ap_GlobalngeNB-ID* ng_eNB;

      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_GlobalNG_RANNode_ID;

EXTERN int asn1PE_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN int asn1PD_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN void asn1Print_e2ap_GlobalNG_RANNode_ID (const char* name, const e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GlobalNG_RANNode_ID (const char* name, e2ap_GlobalNG_RANNode_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, const e2ap_GlobalNG_RANNode_ID* pSrcValue, e2ap_GlobalNG_RANNode_ID* pDstValue);
EXTERN int asn1Init_e2ap_GlobalNG_RANNode_ID (e2ap_GlobalNG_RANNode_ID* pvalue);
EXTERN void asn1Free_e2ap_GlobalNG_RANNode_ID (OSCTXT* pctxt, e2ap_GlobalNG_RANNode_ID* pvalue);

// --- End of e2ap_GlobalNG_RANNode_ID.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceXn.h ---

//seq normal

/*****************************************/
/*           E2nodeComponentInterfaceXn                */
/*****************************************/


typedef struct EXTERN e2ap_E2nodeComponentInterfaceXn {
   e2ap_GlobalNG-RANNode-ID global_NG_RAN_Node_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceXn;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentInterfaceXn (e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceXn (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceXn* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceXn (const char* name, const e2ap_E2nodeComponentInterfaceXn* pvalue);
// --- End of e2ap_E2nodeComponentInterfaceXn.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceE1.h ---

//seq normal

/*****************************************/
/*           E2nodeComponentInterfaceE1                */
/*****************************************/


typedef struct EXTERN e2ap_E2nodeComponentInterfaceE1 {
   e2ap_GNB-CU-UP-ID gNB_CU_UP_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceE1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentInterfaceE1 (e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceE1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceE1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceE1 (const char* name, const e2ap_E2nodeComponentInterfaceE1* pvalue);
// --- End of e2ap_E2nodeComponentInterfaceE1.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceF1.h ---

//seq normal

/*****************************************/
/*           E2nodeComponentInterfaceF1                */
/*****************************************/


typedef struct EXTERN e2ap_E2nodeComponentInterfaceF1 {
   e2ap_GNB-DU-ID gNB_DU_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceF1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentInterfaceF1 (e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceF1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceF1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceF1 (const char* name, const e2ap_E2nodeComponentInterfaceF1* pvalue);
// --- End of e2ap_E2nodeComponentInterfaceF1.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceW1.h ---

//seq normal

/*****************************************/
/*           E2nodeComponentInterfaceW1                */
/*****************************************/


typedef struct EXTERN e2ap_E2nodeComponentInterfaceW1 {
   e2ap_NGENB-DU-ID ng_eNB_DU_ID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceW1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentInterfaceW1 (e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceW1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceW1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceW1 (const char* name, const e2ap_E2nodeComponentInterfaceW1* pvalue);
// --- End of e2ap_E2nodeComponentInterfaceW1.h ---

/***********************************/
/* File .h missing: e2ap_MMEname.h */
/***********************************/

// --- Begin of e2ap_E2nodeComponentInterfaceS1.h ---

//seq normal

/*****************************************/
/*           E2nodeComponentInterfaceS1                */
/*****************************************/


typedef struct EXTERN e2ap_E2nodeComponentInterfaceS1 {
   e2ap_MMEname mme_name;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceS1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentInterfaceS1 (e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceS1 (const char* name, const e2ap_E2nodeComponentInterfaceS1* pvalue);
// --- End of e2ap_E2nodeComponentInterfaceS1.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceX2.h ---

//seq normal

/*****************************************/
/*           E2nodeComponentInterfaceX2                */
/*****************************************/


typedef struct EXTERN e2ap_E2nodeComponentInterfaceX2 {
   e2ap_GlobalENB-ID global_eNB_ID;
OSBOOL m_global-eNB-IDPresent;   e2ap_GlobalenGNB-ID global_en_gNB_ID;
OSBOOL m_global-en-gNB-IDPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentInterfaceX2;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentInterfaceX2 (e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceX2 (const char* name, const e2ap_E2nodeComponentInterfaceX2* pvalue);
// --- End of e2ap_E2nodeComponentInterfaceX2.h ---

// --- Begin of e2ap_E2nodeComponentID.h ---

// choice

/*****************************************/
/*           E2nodeComponentID                */
/*****************************************/

#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeNG 1
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeXn 2
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeE1 3
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeF1 4
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeW1 5
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeS1 6
#define T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeX2 7
#define T_e2ap_E2nodeComponentID_extElem1 2

typedef struct e2ap_E2nodeComponentID {
   OSINT32 t;  /* choice tag */
   union {
      /* t =  1 */
      e2ap_E2nodeComponentInterfaceNG* e2nodeComponentInterfaceTypeNG;
      /* t =  2 */
      e2ap_E2nodeComponentInterfaceXn* e2nodeComponentInterfaceTypeXn;
      /* t =  3 */
      e2ap_E2nodeComponentInterfaceE1* e2nodeComponentInterfaceTypeE1;
      /* t =  4 */
      e2ap_E2nodeComponentInterfaceF1* e2nodeComponentInterfaceTypeF1;
      /* t =  5 */
      e2ap_E2nodeComponentInterfaceW1* e2nodeComponentInterfaceTypeW1;
      /* t =  6 */
      e2ap_E2nodeComponentInterfaceS1* e2nodeComponentInterfaceTypeS1;
      /* t =  7 */
      e2ap_E2nodeComponentInterfaceX2* e2nodeComponentInterfaceTypeX2;

      ASN1OpenType* extElem1;  /* extension */
   } u;
} e2ap_E2nodeComponentID;

EXTERN int asn1PE_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentID (OSCTXT* pctxt, e2ap_E2nodeComponentID* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentID (const char* name, const e2ap_E2nodeComponentID* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2nodeComponentID (const char* name, e2ap_E2nodeComponentID* pvalue, char* buffer, OSSIZE bufSize);
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

//seq normal

/*****************************************/
/*           E2nodeComponentConfiguration                */
/*****************************************/


typedef struct EXTERN e2ap_E2nodeComponentConfiguration {
   e2ap_e2nodeComponentRequestPart e2nodeComponentRequestPart;
   e2ap_e2nodeComponentResponsePart e2nodeComponentResponsePart;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentConfiguration;

EXTERN int asn1PE_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfiguration (e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfiguration (OSCTXT* pctxt, e2ap_E2nodeComponentConfiguration* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfiguration (const char* name, const e2ap_E2nodeComponentConfiguration* pvalue);
// --- End of e2ap_E2nodeComponentConfiguration.h ---

// --- Begin of e2ap_E2nodeComponentConfigAddition_Item.h ---

//seq normal

/*****************************************/
/*           E2nodeComponentConfigAddition_Item                */
/*****************************************/


typedef struct EXTERN e2ap_E2nodeComponentConfigAddition_Item {
   e2ap_E2nodeComponentInterfaceType e2nodeComponentInterfaceType;
   e2ap_E2nodeComponentID e2nodeComponentID;
   e2ap_E2nodeComponentConfiguration e2nodeComponentConfiguration;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2nodeComponentConfigAddition_Item;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigAddition_Item (e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigAddition_Item (const char* name, const e2ap_E2nodeComponentConfigAddition_Item* pvalue);
// --- End of e2ap_E2nodeComponentConfigAddition_Item.h ---

// --- Begin of e2ap_E2nodeComponentConfigAddition_ItemIEs.h ---
/* e2ap_E2nodeComponentConfigAddition_ItemIEs.h */

//IE
/*****************************************/
/*           E2nodeComponentConfigAddition_ItemIEs               */
/*****************************************/


typedef enum {
   T_E2AP_PDU_Contents_E2nodeComponentConfigAddition_ItemIEs_UNDEF,

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
/* e2ap_E2nodeComponentConfigAddition_List.h */
//seq of single container

/*****************************************/
/*           E2nodeComponentConfigAddition_List                */
/*****************************************/

typedef OSRTDList e2ap_E2nodeComponentConfigAddition_List;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List** ppvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigAddition_List (e2ap_E2nodeComponentConfigAddition_List* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* pvalue);
// --- End of e2ap_E2nodeComponentConfigAddition_List.h ---

// --- Begin of e2ap_E2setupRequestIEs.h ---
/* e2ap_E2setupRequestIEs.h */

//IE
/*****************************************/
/*           E2setupRequestIEs               */
/*****************************************/


typedef enum {
   T_E2AP_PDU_Contents_E2setupRequestIEs_UNDEF,

   T_E2AP_PDU_Contents_E2setupRequestIEs_TransactionID,   
   
   T_E2AP_PDU_Contents_E2setupRequestIEs_GlobalE2node_ID,   
   
   T_E2AP_PDU_Contents_E2setupRequestIEs_RANfunctions_List,   
   
   T_E2AP_PDU_Contents_E2setupRequestIEs_E2nodeComponentConfigAddition_List   
   

} e2ap_E2setupRequestIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_E2setupRequestIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2setupRequestIEs_TVALUE t;
      union {
         e2ap_TransactionID * _e2apE2setupRequestIEs_TransactionID,
         e2ap_GlobalE2node-ID * _e2apE2setupRequestIEs_GlobalE2node_ID,
         e2ap_RANfunctions-List * _e2apE2setupRequestIEs_RANfunctions_List,
         e2ap_E2nodeComponentConfigAddition-List * _e2apE2setupRequestIEs_E2nodeComponentConfigAddition_List

         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2setupRequestIEs;

EXTERN int  asn1PE_e2ap_E2setupRequestIEs (OSCTXT* pctxt, e2ap_E2setupRequestIEs* pvalue);
EXTERN int  asn1PD_e2ap_E2setupRequestIEs (OSCTXT* pctxt, e2ap_E2setupRequestIEs* pvalue);
EXTERN void asn1Init_e2ap_E2setupRequestIEs (e2ap_E2setupRequestIEs* pvalue);
EXTERN void asn1Free_e2ap_E2setupRequestIEs (OSCTXT* pctxt, e2ap_E2setupRequestIEs* pvalue);

// --- End of e2ap_E2setupRequestIEs.h ---

// --- Begin of e2ap_E2setupRequest.h ---

//seq normal

/*****************************************/
/*           E2setupRequest                */
/*****************************************/


typedef struct EXTERN e2ap_E2setupRequest {
   e2ap_ProtocolIE-Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2setupRequest;

EXTERN int asn1PE_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue);
EXTERN int asn1PD_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue);
EXTERN void asn1Init_e2ap_E2setupRequest (e2ap_E2setupRequest* pvalue);
EXTERN void asn1Free_e2ap_E2setupRequest (OSCTXT* pctxt, e2ap_E2setupRequest* pvalue);
EXTERN void asn1Print_e2ap_E2setupRequest (const char* name, const e2ap_E2setupRequest* pvalue);
// --- End of e2ap_E2setupRequest.h ---

