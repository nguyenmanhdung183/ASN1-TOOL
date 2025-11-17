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

/*****************************************/
/* File .h missing: e2ap_GNB_ID_Choice.h */
/*****************************************/

/****************************************/
/* File .h missing: e2ap_GlobalgNB_ID.h */
/****************************************/

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
#ifndef _E2AP_ENB_ID_CHOICE_H_
#define _E2AP_ENB_ID_CHOICE_H_

#include "rtxsrc/rtxContext.h"
#include "e2ap_BIT STRING.h"

typedef struct e2ap_ENB_ID_Choice {
   OSINT32 t;  /* choice tag */
   union {
      e2ap_BIT STRING* enb-ID-macro;
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

#endif
// --- End of e2ap_ENB_ID_Choice.h ---

/******************************************/
/* File .h missing: e2ap_GlobalngeNB_ID.h */
/******************************************/

/****************************************/
/* File .h missing: e2ap_macro_eNB_ID.h */
/****************************************/

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
#ifndef _E2AP_GLOBALE2NODE_ID_H_
#define _E2AP_GLOBALE2NODE_ID_H_

#include "rtxsrc/rtxContext.h"
#include "e2ap_GlobalGNB_ID.h"

typedef struct e2ap_GlobalE2node_ID {
   OSINT32 t;  /* choice tag */
   union {
      e2ap_GlobalGNB_ID* gNB;
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

#endif
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

/********************************************/
/* File .h missing: e2ap_RANfunction_Item.h */
/********************************************/

/***********************************************/
/* File .h missing: e2ap_RANfunction_ItemIEs.h */
/***********************************************/

/*********************************************/
/* File .h missing: e2ap_RANfunctions_List.h */
/*********************************************/

/********************************************************/
/* File .h missing: e2ap_E2nodeComponentInterfaceType.h */
/********************************************************/

/***********************************/
/* File .h missing: e2ap_AMFName.h */
/***********************************/

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

/******************************************************/
/* File .h missing: e2ap_E2nodeComponentInterfaceS1.h */
/******************************************************/

/******************************************************/
/* File .h missing: e2ap_E2nodeComponentInterfaceX2.h */
/******************************************************/

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
#ifndef _E2AP_E2NODECOMPONENTCONFIGADDITION_ITEM_H_
#define _E2AP_E2NODECOMPONENTCONFIGADDITION_ITEM_H_

#include "rtxsrc/rtxContext.h"

typedef struct e2ap_E2nodeComponentConfigAddition_Item {
} e2ap_E2nodeComponentConfigAddition_Item;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigAddition_Item (e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAddition_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAddition_Item* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigAddition_Item (const char* name, const e2ap_E2nodeComponentConfigAddition_Item* pvalue);

#endif
// --- End of e2ap_E2nodeComponentConfigAddition_Item.h ---

/*****************************************************************/
/* File .h missing: e2ap_E2nodeComponentConfigAddition_ItemIEs.h */
/*****************************************************************/

/**************************************************************/
/* File .h missing: e2ap_E2nodeComponentConfigAddition_List.h */
/**************************************************************/

/*********************************************/
/* File .h missing: e2ap_E2setupRequestIEs.h */
/*********************************************/

// --- Begin of e2ap_E2setupRequest.h ---
#ifndef _E2AP_E2SETUPREQUEST_H_
#define _E2AP_E2SETUPREQUEST_H_

#include "rtxsrc/rtxContext.h"

typedef struct e2ap_E2SetupRequest {
} e2ap_E2SetupRequest;

EXTERN int asn1PE_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue);
EXTERN int asn1PD_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue);
EXTERN void asn1Init_e2ap_E2SetupRequest (e2ap_E2SetupRequest* pvalue);
EXTERN void asn1Free_e2ap_E2SetupRequest (OSCTXT* pctxt, e2ap_E2SetupRequest* pvalue);
EXTERN void asn1Print_e2ap_E2SetupRequest (const char* name, const e2ap_E2SetupRequest* pvalue);

#endif
// --- End of e2ap_E2setupRequest.h ---

