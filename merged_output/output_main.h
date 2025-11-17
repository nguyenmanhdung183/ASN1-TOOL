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

/*****************************************/
/* File .h missing: e2ap_ENB_ID_Choice.h */
/*****************************************/

/******************************************/
/* File .h missing: e2ap_GlobalngeNB_ID.h */
/******************************************/

/****************************************/
/* File .h missing: e2ap_macro_eNB_ID.h */
/****************************************/

/*****************************/
/* File .h missing: e2ap_©.h */
/*****************************/

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

/*********************************************/
/* File .h missing: e2ap_RANfunctions_List.h */
/*********************************************/

/************************************/
/* File .h missing: e2ap_SEQUENCE.h */
/************************************/

/**************************************************************/
/* File .h missing: e2ap_E2nodeComponentConfigAddition_List.h */
/**************************************************************/

// --- Begin of e2ap_E2setupRequestIEs.h ---
/* e2ap_E2SetupRequestIEs.h */
#ifndef _E2AP_E2SETUPREQUESTIES_H_
#define _E2AP_E2SETUPREQUESTIES_H_

#include "rtxsrc/rtxDList.h"
#include "e2ap_ProtocolIE_ID.h"
#include "e2ap_Criticality.h"
#include "e2ap_E2SetupRequestIEs_T_VALUE.h"

typedef struct e2ap_E2SetupRequestIEs_Element {
   e2ap_ProtocolIE_ID_t id;
   e2ap_Criticality_t criticality;
   e2ap_E2SetupRequestIEs_T_VALUE value;
} e2ap_E2SetupRequestIEs_Element;

typedef struct e2ap_E2SetupRequestIEs {
   OSRTDList elem;  /* list of e2ap_E2SetupRequestIEs_Element */
} e2ap_E2SetupRequestIEs;

#endif
// --- End of e2ap_E2setupRequestIEs.h ---

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

