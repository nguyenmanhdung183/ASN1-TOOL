// --- Begin of e2ap_TransactionID.h ---
/* e2ap_TransactionID.h */
typedef OSUINT8 e2ap_TransactionID;

EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value);
EXTERN int asn1PD_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID* pvalue);
EXTERN void asn1Print_e2ap_TransactionID (const char* name, const e2ap_TransactionID* pvalue);
EXTERN int asn1PrtToStr_e2ap_TransactionID (const char* name, e2ap_TransactionID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_TransactionID (OSCTXT* pctxt, const char* name, const e2ap_TransactionID* pvalue);
// --- End of e2ap_TransactionID.h ---

// --- Begin of e2ap_PLMN_Identity.h ---
/* e2ap_PLMN_Identity.h */
#ifndef _E2AP_PLMN_IDENTITY_H_
#define _E2AP_PLMN_IDENTITY_H_

#include "rtxsrc/rtxContext.h"
#include "rtxsrc/rtxDList.h"

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

#endif
// --- End of e2ap_PLMN_Identity.h ---

/**********************************/
/* File .h missing: e2ap_gnb_ID.h */
/**********************************/

/*****************************************/
/* File .h missing: e2ap_GNB_ID_Choice.h */
/*****************************************/

/****************************************/
/* File .h missing: e2ap_GlobalgNB_ID.h */
/****************************************/

/**********************************/
/* File .h missing: e2ap_gNB_ID.h */
/**********************************/

/************************************/
/* File .h missing: e2ap_ENGNB_ID.h */
/************************************/

/******************************************/
/* File .h missing: e2ap_GlobalenGNB_ID.h */
/******************************************/

// --- Begin of e2ap_GNB_CU_UP_ID.h ---
/* e2ap_GNB_CU_UP_ID.h */
typedef OSUINT32 e2ap_GNB_CU_UP_ID;

EXTERN int asn1PE_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID value);
EXTERN int asn1PD_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, e2ap_GNB_CU_UP_ID* pvalue);
EXTERN void asn1Print_e2ap_GNB_CU_UP_ID (const char* name, const e2ap_GNB_CU_UP_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GNB_CU_UP_ID (const char* name, e2ap_GNB_CU_UP_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GNB_CU_UP_ID (OSCTXT* pctxt, const char* name, const e2ap_GNB_CU_UP_ID* pvalue);
// --- End of e2ap_GNB_CU_UP_ID.h ---

// --- Begin of e2ap_GNB_DU_ID.h ---
/* e2ap_GNB_DU_ID.h */
typedef OSUINT32 e2ap_GNB_DU_ID;

EXTERN int asn1PE_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID value);
EXTERN int asn1PD_e2ap_GNB_DU_ID (OSCTXT* pctxt, e2ap_GNB_DU_ID* pvalue);
EXTERN void asn1Print_e2ap_GNB_DU_ID (const char* name, const e2ap_GNB_DU_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_GNB_DU_ID (const char* name, e2ap_GNB_DU_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_GNB_DU_ID (OSCTXT* pctxt, const char* name, const e2ap_GNB_DU_ID* pvalue);
// --- End of e2ap_GNB_DU_ID.h ---

/***********************************************/
/* File .h missing: e2ap_GlobalE2node_gNB_ID.h */
/***********************************************/

/**************************************************/
/* File .h missing: e2ap_GlobalE2node_en_gNB_ID.h */
/**************************************************/

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
/* e2ap_ENB_ID_Choice.h */

// choice
typedef struct e2ap_ENB_ID_Choice {
   OSINT32 t;  /* choice tag */
   union {
      e2ap_BIT STRING* enb_ID_macro;
      e2ap_BIT STRING* enb_ID_shortmacro;
      e2ap_BIT STRING* enb_ID_longmacro;
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

/******************************************/
/* File .h missing: e2ap_GlobalngeNB_ID.h */
/******************************************/

/****************************************/
/* File .h missing: e2ap_macro_eNB_ID.h */
/****************************************/

/**************************************************/
/* File .h missing: e2ap___________error_______.h */
/**************************************************/

/**********************************************/
/* File .h missing: e2ap_short_Macro_eNB_ID.h */
/**********************************************/

/*********************************************/
/* File .h missing: e2ap_long_Macro_eNB_ID.h */
/*********************************************/

/**********************************/
/* File .h missing: e2ap_ENB_ID.h */
/**********************************/

/****************************************/
/* File .h missing: e2ap_GlobalENB_ID.h */
/****************************************/

// --- Begin of e2ap_NGENB_DU_ID.h ---
/* e2ap_NGENB_DU_ID.h */
typedef OSUINT32 e2ap_NGENB_DU_ID;

EXTERN int asn1PE_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID value);
EXTERN int asn1PD_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID* pvalue);
EXTERN void asn1Print_e2ap_NGENB_DU_ID (const char* name, const e2ap_NGENB_DU_ID* pvalue);
EXTERN int asn1PrtToStr_e2ap_NGENB_DU_ID (const char* name, e2ap_NGENB_DU_ID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_NGENB_DU_ID (OSCTXT* pctxt, const char* name, const e2ap_NGENB_DU_ID* pvalue);
// --- End of e2ap_NGENB_DU_ID.h ---

/**************************************************/
/* File .h missing: e2ap_GlobalE2node_ng_eNB_ID.h */
/**************************************************/

/***********************************************/
/* File .h missing: e2ap_GlobalE2node_eNB_ID.h */
/***********************************************/

// --- Begin of e2ap_GlobalE2node_ID.h ---
/* e2ap_GlobalE2node_ID.h */

// choice
typedef struct e2ap_GlobalE2node_ID {
   OSINT32 t;  /* choice tag */
   union {
      e2ap_GlobalGNB_ID* gNB;
      e2ap_GlobalNGeNB_ID* ng_eNB;
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

/*****************************************/
/* File .h missing: e2ap_RANfunctionID.h */
/*****************************************/

// --- Begin of e2ap_RANfunctionDefinition.h ---
/* e2ap_RANfunctionDefinition.h */
#ifndef _E2AP_RANFUNCTIONDEFINITION_H_
#define _E2AP_RANFUNCTIONDEFINITION_H_

#include "rtxsrc/rtxContext.h"
#include "rtxsrc/rtxDList.h"

typedef OSDynOctStr e2ap_RANfunctionDefinition;

EXTERN int asn1PE_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition** ppvalue);
EXTERN void asn1Print_e2ap_RANfunctionDefinition (const char* name, const e2ap_RANfunctionDefinition* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionDefinition (const char* name, e2ap_RANfunctionDefinition* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionDefinition (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionDefinition* pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionDefinition (OSCTXT* pctxt, const e2ap_RANfunctionDefinition* pSrcValue, e2ap_RANfunctionDefinition* pDstValue);
EXTERN int asn1Init_e2ap_RANfunctionDefinition (e2ap_RANfunctionDefinition* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition* pvalue);

#endif
// --- End of e2ap_RANfunctionDefinition.h ---

/***********************************************/
/* File .h missing: e2ap_RANfunctionRevision.h */
/***********************************************/

/*******************************************/
/* File .h missing: e2ap_PrintableString.h */
/*******************************************/

// --- Begin of e2ap_RANfunctionOID.h ---
/* e2ap_RANfunctionOID.h */
#ifndef _E2AP_RANFUNCTIONOID_H_
#define _E2AP_RANFUNCTIONOID_H_

#include "rtxsrc/rtxContext.h"

typedef const char* e2ap_RANfunctionOID;

EXTERN int asn1PE_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID value);
EXTERN int asn1PD_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID* ppvalue);
EXTERN void asn1Print_e2ap_RANfunctionOID (const char* name, e2ap_RANfunctionOID pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionOID (const char* name, e2ap_RANfunctionOID pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionOID (OSCTXT* pctxt, const char* name, e2ap_RANfunctionOID pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID pSrcValue, e2ap_RANfunctionOID* ppDstValue);
EXTERN void asn1Free_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID pvalue);

#endif
// --- End of e2ap_RANfunctionOID.h ---

// --- Begin of e2ap_RANfunction_Item.h ---

//seq normal

typedef struct e2ap_RANfunction_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_RANfunctionDefinition ranFunctionDefinition;
   e2ap_RANfunctionRevision ranFunctionRevision;
   e2ap_RANfunctionOID ranFunctionOID;
} e2ap_RANfunction_Item;

EXTERN int asn1PE_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN void asn1Init_e2ap_RANfunction_Item (e2ap_RANfunction_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunction_Item (const char* name, const e2ap_RANfunction_Item* pvalue);
// --- End of e2ap_RANfunction_Item.h ---

// --- Begin of e2ap_RANfunction_ItemIEs.h ---
/* e2ap_RANfunction_ItemIEs.h */
//IE
/* Forward declaration for the enum */
typedef enum {
   T_E2AP_PDU_Contents_RANfunction_ItemIEs_UNDEF,
   T_E2AP_PDU_Contents_RANfunction_ItemIEs_
} T_E2AP_PDU_Contents_RANfunction_ItemIEs;

/* The actual IE container */
typedef struct EXTERN e2ap_RANfunction_ItemIEs {
   ASN1OpenType* extElem1;
   OSSIZE        extElem1_n;
   union {
      e2ap_RANfunction-Item u_RANfunction_ItemIEs_;
   } value;
} e2ap_RANfunction_ItemIEs;

EXTERN int  asn1PE_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RANfunction_ItemIEs (e2ap_RANfunction_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue);

// --- End of e2ap_RANfunction_ItemIEs.h ---

// --- Begin of e2ap_RANfunctions_List.h ---
/* e2ap_RANfunctions_List.h */

//seq_of_single_container.c

typedef OSRTDList e2ap_RANfunctions_List;

EXTERN int asn1PE_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List* pvalue);
EXTERN int asn1PD_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List** ppvalue);
EXTERN void asn1Init_e2ap_RANfunctions_List (e2ap_RANfunctions_List* pvalue);
EXTERN void asn1Free_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List* pvalue);
// --- End of e2ap_RANfunctions_List.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceType.h ---
/* e2ap_E2nodeComponentInterfaceType.h - enumurate*/
/* e2ap_E2nodeComponentInterfaceType.h */

/******************************************************/
/*                                                    */
/*    E2nodeComponentInterfaceType                                       */
/*                                                    */
/******************************************************/

typedef enum {
    e2ap_ng = 0,    e2ap_xn = 1,    e2ap_e1 = 2,    e2ap_f1 = 3,    e2ap_w1 = 4,    e2ap_s1 = 5,    e2ap_x2 = 6//add other values as needed
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

// --- Begin of e2ap_AMFName.h ---
/* e2ap_AMFName.h */
#ifndef _E2AP_AMFNAME_H_
#define _E2AP_AMFNAME_H_

#include "rtxsrc/rtxContext.h"

typedef const char* e2ap_AMFName;

EXTERN int asn1PE_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName value);
EXTERN int asn1PD_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName* ppvalue);
EXTERN void asn1Print_e2ap_AMFName (const char* name, e2ap_AMFName pvalue);
EXTERN int asn1PrtToStr_e2ap_AMFName (const char* name, e2ap_AMFName pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_AMFName (OSCTXT* pctxt, const char* name, e2ap_AMFName pvalue);
EXTERN int asn1Copy_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName pSrcValue, e2ap_AMFName* ppDstValue);
EXTERN void asn1Free_e2ap_AMFName (OSCTXT* pctxt, e2ap_AMFName pvalue);

#endif
// --- End of e2ap_AMFName.h ---

/******************************************************/
/* File .h missing: e2ap_E2nodeComponentInterfaceNG.h */
/******************************************************/

/***********************************************/
/* File .h missing: e2ap_GlobalNG_RANNode_ID.h */
/***********************************************/

/******************************************************/
/* File .h missing: e2ap_E2nodeComponentInterfaceXn.h */
/******************************************************/

/******************************************************/
/* File .h missing: e2ap_E2nodeComponentInterfaceE1.h */
/******************************************************/

/******************************************************/
/* File .h missing: e2ap_E2nodeComponentInterfaceF1.h */
/******************************************************/

/******************************************************/
/* File .h missing: e2ap_E2nodeComponentInterfaceW1.h */
/******************************************************/

/***********************************/
/* File .h missing: e2ap_MMEname.h */
/***********************************/

// --- Begin of e2ap_E2nodeComponentInterfaceS1.h ---

//seq normal

typedef struct e2ap_E2nodeComponentInterfaceS1 {
   e2ap_MMEname mme_name ;
} e2ap_E2nodeComponentInterfaceS1;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentInterfaceS1 (e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceS1 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceS1* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceS1 (const char* name, const e2ap_E2nodeComponentInterfaceS1* pvalue);
// --- End of e2ap_E2nodeComponentInterfaceS1.h ---

// --- Begin of e2ap_E2nodeComponentInterfaceX2.h ---

//seq normal

typedef struct e2ap_E2nodeComponentInterfaceX2 {
   e2ap_GlobalENB-ID global_eNB_ID;
   e2ap_GlobalenGNB-ID global_en_gNB_ID;
} e2ap_E2nodeComponentInterfaceX2;

EXTERN int asn1PE_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentInterfaceX2 (e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentInterfaceX2 (OSCTXT* pctxt, e2ap_E2nodeComponentInterfaceX2* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentInterfaceX2 (const char* name, const e2ap_E2nodeComponentInterfaceX2* pvalue);
// --- End of e2ap_E2nodeComponentInterfaceX2.h ---

/*********************************************/
/* File .h missing: e2ap_E2nodeComponentID.h */
/*********************************************/

/******************************************************/
/* File .h missing: e2ap_e2nodeComponentRequestPart.h */
/******************************************************/

/*******************************************************/
/* File .h missing: e2ap_e2nodeComponentResponsePart.h */
/*******************************************************/

/********************************************************/
/* File .h missing: e2ap_E2nodeComponentConfiguration.h */
/********************************************************/

// --- Begin of e2ap_E2nodeComponentConfigAddition_Item.h ---

//seq normal

typedef struct e2ap_E2nodeComponentConfigAddition_Item {
   e2ap_E2nodeComponentInterfaceType e2nodeComponentInterfaceType;
   e2ap_E2nodeComponentID e2nodeComponentID;
   e2ap_E2nodeComponentConfiguration e2nodeComponentConfiguration;
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
/* Forward declaration for the enum */
typedef enum {
   T_E2AP_PDU_Contents_E2nodeComponentConfigAddition_ItemIEs_UNDEF,
   T_E2AP_PDU_Contents_E2nodeComponentConfigAddition_ItemIEs_
} T_E2AP_PDU_Contents_E2nodeComponentConfigAddition_ItemIEs;

/* The actual IE container */
typedef struct EXTERN e2ap_E2nodeComponentConfigAddition_ItemIEs {
   ASN1OpenType* extElem1;
   OSSIZE        extElem1_n;
   union {
      e2ap_E2nodeComponentConfigAddition-Item u_E2nodeComponentConfigAddition_ItemIEs_;
   } value;
} e2ap_E2nodeComponentConfigAddition_ItemIEs;

EXTERN int  asn1PE_e2ap_E2nodeComponentConfigAddition_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_E2nodeComponentConfigAddition_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigAddition_ItemIEs (e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAddition_ItemIEs (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_ItemIEs* pvalue);

// --- End of e2ap_E2nodeComponentConfigAddition_ItemIEs.h ---

// --- Begin of e2ap_E2nodeComponentConfigAddition_List.h ---
/* e2ap_E2nodeComponentConfigAddition_List.h */

//seq_of_single_container.c

typedef OSRTDList e2ap_E2nodeComponentConfigAddition_List;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List** ppvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigAddition_List (e2ap_E2nodeComponentConfigAddition_List* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAddition_List (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_List* pvalue);
// --- End of e2ap_E2nodeComponentConfigAddition_List.h ---

/*********************************************/
/* File .h missing: e2ap_E2setupRequestIEs.h */
/*********************************************/

// --- Begin of e2ap_E2setupRequest.h ---
/* e2ap_E2SetupRequest.h */
#ifndef _E2AP_E2SETUPREQUEST_H_
#define _E2AP_E2SETUPREQUEST_H_

#include "e2ap_E2nodeComponentConfigAddition_List.h"
#include "e2ap_GlobalE2node_ID.h"
#include "e2ap_RANfunctions_List.h"
#include "e2ap_TransactionID.h"

/* T_VALUE Union */
typedef union e2ap_E2SetupRequestIEs_T_VALUE {
   T_E2AP_PDU_Contents_e2ap__transactionID;
   T_E2AP_PDU_Contents_e2ap__globalE2node_ID;
   T_E2AP_PDU_Contents_e2ap__rANfunctionsAdded;
   T_E2AP_PDU_Contents_e2ap__e2nodeComponentConfigAddition;
} e2ap_E2SetupRequestIEs_TVALUE;

/* IE Struct */
typedef struct e2ap_E2SetupRequestIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   e2ap_E2SetupRequestIEs_T_VALUE value;
} e2ap_E2SetupRequestIEs;

/* Container */
typedef struct e2ap_E2SetupRequest_protocolIEs_Container {
   e2ap_E2SetupRequestIEs* elem;
   OSUINT16 n;
} e2ap_E2SetupRequest_protocolIEs_Container;

/* Message */
typedef struct e2ap_E2SetupRequest {
   e2ap_E2SetupRequest_protocolIEs_Container protocolIEs;
} e2ap_E2SetupRequest;

EXTERN int asn1PE_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue);
EXTERN int asn1PD_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue);
EXTERN int asn1Init_e2ap_E2SetupRequest (e2ap_E2SetupRequest* pvalue);
EXTERN void asn1Free_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue);

#endif
// --- End of e2ap_E2setupRequest.h ---

