
#ifndef OUTPUT_MAIN_H
#define OUTPUT_MAIN_H

// --- Begin of doc/header.h ---
//======================E2AP.h========================//
typedef pd_BitString32 pd_BitString32;
typedef pe_BitString32 pe_BitString32;
typedef asn1PrtToStr_ASN1BitStr32 rtPrintToStringBitStrBraceText;
typedef //asn1Free_ASN1BitStr32 

// --- End of doc/header.h ---

// --- Begin of e2ap_LoadMeasurementID.h ---
/*****************************************/
/*           LoadMeasurementID                */
/*****************************************/
//interger with ext


typedef OSUINT16 e2ap_LoadMeasurementID;

EXTERN int asn1PE_e2ap_LoadMeasurementID (OSCTXT* pctxt, e2ap_LoadMeasurementID value);
EXTERN int asn1PD_e2ap_LoadMeasurementID (OSCTXT* pctxt, e2ap_LoadMeasurementID* pvalue);
EXTERN void asn1Print_e2ap_LoadMeasurementID (const char* name, const e2ap_LoadMeasurementID* pvalue);
EXTERN int asn1PrtToStr_e2ap_LoadMeasurementID (const char* name, e2ap_LoadMeasurementID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_LoadMeasurementID (OSCTXT* pctxt, const char* name, const e2ap_LoadMeasurementID* pvalue);
// --- End of e2ap_LoadMeasurementID.h ---

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

// --- Begin of e2ap_RICloadConfirm.h ---
/******************************************************/
/*                                                    */
/*    RICloadConfirm                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_true = 0
} e2ap_RICloadConfirm_Root;

typedef OSUINT32 e2ap_RICloadConfirm;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICloadConfirm (OSCTXT* pctxt, e2ap_RICloadConfirm value);
EXTERN int asn1PD_e2ap_RICloadConfirm (OSCTXT* pctxt, e2ap_RICloadConfirm* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICloadConfirm (const char* name, const e2ap_RICloadConfirm* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICloadConfirm (OSCTXT* pctxt, const char* name, const e2ap_RICloadConfirm* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICloadConfirm (const char* name,const e2ap_RICloadConfirm* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICloadConfirm_ENUMTAB[];
#define e2ap_RICloadConfirm_ENUMTABSIZE 1

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICloadConfirm_ToString (OSUINT32 value);
EXTERN int e2ap_RICloadConfirm_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICloadConfirm* pvalue);
EXTERN int e2ap_RICloadConfirm_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICloadConfirm* pvalue);
// --- End of e2ap_RICloadConfirm.h ---

// --- Begin of e2ap_RICserviceLoadConfirm.h ---
/*****************************************/
/*           RICserviceLoadConfirm                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICserviceLoadConfirm {
   e2ap_RICloadConfirm ricServiceReportLoadConfirm;
     OSBOOL m_ricServiceReportLoadConfirmPresent;   e2ap_RICloadConfirm ricServiceInsertLoadConfirm;
     OSBOOL m_ricServiceInsertLoadConfirmPresent;   e2ap_RICloadConfirm ricServiceControlLoadConfirm;
     OSBOOL m_ricServiceControlLoadConfirmPresent;   e2ap_RICloadConfirm ricServicePolicyLoadConfirm;
     OSBOOL m_ricServicePolicyLoadConfirmPresent;   e2ap_RICloadConfirm ricServiceQueryLoadConfirm;
     OSBOOL m_ricServiceQueryLoadConfirmPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICserviceLoadConfirm;

EXTERN int asn1PE_e2ap_RICserviceLoadConfirm (OSCTXT* pctxt, e2ap_RICserviceLoadConfirm* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadConfirm (OSCTXT* pctxt, e2ap_RICserviceLoadConfirm* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadConfirm (e2ap_RICserviceLoadConfirm* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadConfirm (OSCTXT* pctxt, e2ap_RICserviceLoadConfirm* pvalue);
EXTERN void asn1Print_e2ap_RICserviceLoadConfirm (const char* name, const e2ap_RICserviceLoadConfirm* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadConfirm (const char* name, e2ap_RICserviceLoadConfirm* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICserviceLoadConfirm (OSCTXT* pctxt, const char* name, const e2ap_RICserviceLoadConfirm* pvalue);
EXTERN int asn1Copy_e2ap_RICserviceLoadConfirm (OSCTXT* pctxt, const e2ap_RICserviceLoadConfirm* pSrcValue, e2ap_RICserviceLoadConfirm* pDstValue);
// --- End of e2ap_RICserviceLoadConfirm.h ---

/******************************************/
/* File .h missing: e2ap_ricRequestorID.h */
/******************************************/

/*****************************************/
/* File .h missing: e2ap_ricInstanceID.h */
/*****************************************/

// --- Begin of e2ap_RICrequestID.h ---
/*****************************************/
/*           RICrequestID                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICrequestID {
   e2ap_ricRequestorID ricRequestorID;
   e2ap_ricInstanceID ricInstanceID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICrequestID;

EXTERN int asn1PE_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue);
EXTERN int asn1PD_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue);
EXTERN int asn1Init_e2ap_RICrequestID (e2ap_RICrequestID* pvalue);
EXTERN void asn1Free_e2ap_RICrequestID (OSCTXT* pctxt, e2ap_RICrequestID* pvalue);
EXTERN void asn1Print_e2ap_RICrequestID (const char* name, const e2ap_RICrequestID* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICrequestID (const char* name, e2ap_RICrequestID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICrequestID (OSCTXT* pctxt, const char* name, const e2ap_RICrequestID* pvalue);
EXTERN int asn1Copy_e2ap_RICrequestID (OSCTXT* pctxt, const e2ap_RICrequestID* pSrcValue, e2ap_RICrequestID* pDstValue);
// --- End of e2ap_RICrequestID.h ---

// --- Begin of e2ap_RICactionID.h ---
/*****************************************/
/*        RICactionID         */
/*****************************************/
//interger no ext


typedef OSUINT8 e2ap_RICactionID;

EXTERN int asn1PE_e2ap_RICactionID (OSCTXT* pctxt, e2ap_RICactionID value);
EXTERN int asn1PD_e2ap_RICactionID (OSCTXT* pctxt, e2ap_RICactionID* pvalue);
EXTERN void asn1Print_e2ap_RICactionID (const char* name, const e2ap_RICactionID* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactionID (const char* name, e2ap_RICactionID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICactionID (OSCTXT* pctxt, const char* name, const e2ap_RICactionID* pvalue);
// --- End of e2ap_RICactionID.h ---

// --- Begin of e2ap_RICactionLoadConfirm_Item.h ---
/*****************************************/
/*           RICactionLoadConfirm_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICactionLoadConfirm_Item {
   e2ap_RICactionID ricActionID;
   e2ap_RICloadConfirm ricActionLoadConfirm;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICactionLoadConfirm_Item;

EXTERN int asn1PE_e2ap_RICactionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_Item* pvalue);
EXTERN int asn1PD_e2ap_RICactionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_Item* pvalue);
EXTERN int asn1Init_e2ap_RICactionLoadConfirm_Item (e2ap_RICactionLoadConfirm_Item* pvalue);
EXTERN void asn1Free_e2ap_RICactionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_Item* pvalue);
EXTERN void asn1Print_e2ap_RICactionLoadConfirm_Item (const char* name, const e2ap_RICactionLoadConfirm_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactionLoadConfirm_Item (const char* name, e2ap_RICactionLoadConfirm_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICactionLoadConfirm_Item (OSCTXT* pctxt, const char* name, const e2ap_RICactionLoadConfirm_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICactionLoadConfirm_Item (OSCTXT* pctxt, const e2ap_RICactionLoadConfirm_Item* pSrcValue, e2ap_RICactionLoadConfirm_Item* pDstValue);
// --- End of e2ap_RICactionLoadConfirm_Item.h ---

// --- Begin of e2ap_RICactionLoadConfirm_ItemIEs.h ---
/* e2ap_RICactionLoadConfirm_ItemIEs.h */

/*****************************************/
/*           RICactionLoadConfirm_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICactionLoadConfirm_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICactionLoadConfirm_ItemIEs_RICactionLoadConfirm_Item   
   

} e2ap_RICactionLoadConfirm_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICactionLoadConfirm_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICactionLoadConfirm_ItemIEs_TVALUE t;
      union {
         e2ap_RICactionLoadConfirm_Item * _e2apRICactionLoadConfirm_ItemIEs_RICactionLoadConfirm_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICactionLoadConfirm_ItemIEs;

EXTERN int  asn1PE_e2ap_RICactionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICactionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICactionLoadConfirm_ItemIEs (e2ap_RICactionLoadConfirm_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICactionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_ItemIEs* pvalue);

// --- End of e2ap_RICactionLoadConfirm_ItemIEs.h ---

// --- Begin of e2ap_RICactionLoadConfirm_List.h ---
/*****************************************/
/*           RICactionLoadConfirm_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICactionLoadConfirm_List;

EXTERN int asn1PE_e2ap_RICactionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_List* pvalue);
EXTERN int asn1PD_e2ap_RICactionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_List* ppvalue);
EXTERN void asn1Init_e2ap_RICactionLoadConfirm_List (e2ap_RICactionLoadConfirm_List* pvalue);
EXTERN void asn1Free_e2ap_RICactionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICactionLoadConfirm_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactionLoadConfirm_List (const char* name, e2ap_RICactionLoadConfirm_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICactionLoadConfirm_List (OSCTXT* pctxt, const e2ap_RICactionLoadConfirm_List* pSrcValue, e2ap_RICactionLoadConfirm_List* pDstValue);
EXTERN void asn1Print_e2ap_RICactionLoadConfirm_List (const char *name, const e2ap_RICactionLoadConfirm_List* pvalue);
// --- End of e2ap_RICactionLoadConfirm_List.h ---

// --- Begin of e2ap_RICsubscriptionLoadConfirm_ItemIE.h ---
/*****************************************/
/*           RICsubscriptionLoadConfirm_ItemIE                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionLoadConfirm_ItemIE {
   e2ap_RICrequestID ricRequestID;
   e2ap_RICloadConfirm ricSubscriptionLoadConfirm;
     OSBOOL m_ricSubscriptionLoadConfirmPresent;   e2ap_RICactionLoadConfirm_List ricActionLoadConfirm_list;
     OSBOOL m_ricActionLoadConfirm_listPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionLoadConfirm_ItemIE;

EXTERN int asn1PE_e2ap_RICsubscriptionLoadConfirm_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_ItemIE* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionLoadConfirm_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_ItemIE* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionLoadConfirm_ItemIE (e2ap_RICsubscriptionLoadConfirm_ItemIE* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionLoadConfirm_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_ItemIE* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionLoadConfirm_ItemIE (const char* name, const e2ap_RICsubscriptionLoadConfirm_ItemIE* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionLoadConfirm_ItemIE (const char* name, e2ap_RICsubscriptionLoadConfirm_ItemIE* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionLoadConfirm_ItemIE (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionLoadConfirm_ItemIE* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionLoadConfirm_ItemIE (OSCTXT* pctxt, const e2ap_RICsubscriptionLoadConfirm_ItemIE* pSrcValue, e2ap_RICsubscriptionLoadConfirm_ItemIE* pDstValue);
// --- End of e2ap_RICsubscriptionLoadConfirm_ItemIE.h ---

// --- Begin of e2ap_RICsubscriptionLoadConfirm_ItemIEs.h ---
/* e2ap_RICsubscriptionLoadConfirm_ItemIEs.h */

/*****************************************/
/*           RICsubscriptionLoadConfirm_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionLoadConfirm_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICsubscriptionLoadConfirm_ItemIEs_RICsubscriptionLoadConfirm_ItemIE   
   

} e2ap_RICsubscriptionLoadConfirm_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICsubscriptionLoadConfirm_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionLoadConfirm_ItemIEs_TVALUE t;
      union {
         e2ap_RICsubscriptionLoadConfirm_ItemIE * _e2apRICsubscriptionLoadConfirm_ItemIEs_RICsubscriptionLoadConfirm_ItemIE;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICsubscriptionLoadConfirm_ItemIEs;

EXTERN int  asn1PE_e2ap_RICsubscriptionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICsubscriptionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionLoadConfirm_ItemIEs (e2ap_RICsubscriptionLoadConfirm_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_ItemIEs* pvalue);

// --- End of e2ap_RICsubscriptionLoadConfirm_ItemIEs.h ---

// --- Begin of e2ap_RICsubscriptionLoadConfirm_List.h ---
/*****************************************/
/*           RICsubscriptionLoadConfirm_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICsubscriptionLoadConfirm_List;

EXTERN int asn1PE_e2ap_RICsubscriptionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_List* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_List* ppvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionLoadConfirm_List (e2ap_RICsubscriptionLoadConfirm_List* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionLoadConfirm_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadConfirm_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionLoadConfirm_List (const char* name, e2ap_RICsubscriptionLoadConfirm_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICsubscriptionLoadConfirm_List (OSCTXT* pctxt, const e2ap_RICsubscriptionLoadConfirm_List* pSrcValue, e2ap_RICsubscriptionLoadConfirm_List* pDstValue);
EXTERN void asn1Print_e2ap_RICsubscriptionLoadConfirm_List (const char *name, const e2ap_RICsubscriptionLoadConfirm_List* pvalue);
// --- End of e2ap_RICsubscriptionLoadConfirm_List.h ---

// --- Begin of e2ap_RANfunctionLoadConfirm_Item.h ---
/*****************************************/
/*           RANfunctionLoadConfirm_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RANfunctionLoadConfirm_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_RICloadConfirm ranFunctionLoadConfirm;
     OSBOOL m_ranFunctionLoadConfirmPresent;   e2ap_RICserviceLoadConfirm ricServiceLoadConfirm;
     OSBOOL m_ricServiceLoadConfirmPresent;   e2ap_RICsubscriptionLoadConfirm_List ricSubscriptionLoadConfirm_list;
     OSBOOL m_ricSubscriptionLoadConfirm_listPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RANfunctionLoadConfirm_Item;

EXTERN int asn1PE_e2ap_RANfunctionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_Item* pvalue);
EXTERN int asn1Init_e2ap_RANfunctionLoadConfirm_Item (e2ap_RANfunctionLoadConfirm_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionLoadConfirm_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionLoadConfirm_Item (const char* name, const e2ap_RANfunctionLoadConfirm_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionLoadConfirm_Item (const char* name, e2ap_RANfunctionLoadConfirm_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionLoadConfirm_Item (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionLoadConfirm_Item* pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionLoadConfirm_Item (OSCTXT* pctxt, const e2ap_RANfunctionLoadConfirm_Item* pSrcValue, e2ap_RANfunctionLoadConfirm_Item* pDstValue);
// --- End of e2ap_RANfunctionLoadConfirm_Item.h ---

// --- Begin of e2ap_RANfunctionLoadConfirm_ItemIEs.h ---
/* e2ap_RANfunctionLoadConfirm_ItemIEs.h */

/*****************************************/
/*           RANfunctionLoadConfirm_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RANfunctionLoadConfirm_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RANfunctionLoadConfirm_ItemIEs_RANfunctionLoadConfirm_Item   
   

} e2ap_RANfunctionLoadConfirm_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RANfunctionLoadConfirm_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RANfunctionLoadConfirm_ItemIEs_TVALUE t;
      union {
         e2ap_RANfunctionLoadConfirm_Item * _e2apRANfunctionLoadConfirm_ItemIEs_RANfunctionLoadConfirm_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RANfunctionLoadConfirm_ItemIEs;

EXTERN int  asn1PE_e2ap_RANfunctionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RANfunctionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RANfunctionLoadConfirm_ItemIEs (e2ap_RANfunctionLoadConfirm_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionLoadConfirm_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_ItemIEs* pvalue);

// --- End of e2ap_RANfunctionLoadConfirm_ItemIEs.h ---

// --- Begin of e2ap_RANfunctionLoadConfirm_List.h ---
/*****************************************/
/*           RANfunctionLoadConfirm_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RANfunctionLoadConfirm_List;

EXTERN int asn1PE_e2ap_RANfunctionLoadConfirm_List (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_List* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionLoadConfirm_List (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_List* ppvalue);
EXTERN void asn1Init_e2ap_RANfunctionLoadConfirm_List (e2ap_RANfunctionLoadConfirm_List* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionLoadConfirm_List (OSCTXT* pctxt, e2ap_RANfunctionLoadConfirm_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionLoadConfirm_List (const char* name, e2ap_RANfunctionLoadConfirm_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RANfunctionLoadConfirm_List (OSCTXT* pctxt, const e2ap_RANfunctionLoadConfirm_List* pSrcValue, e2ap_RANfunctionLoadConfirm_List* pDstValue);
EXTERN void asn1Print_e2ap_RANfunctionLoadConfirm_List (const char *name, const e2ap_RANfunctionLoadConfirm_List* pvalue);
// --- End of e2ap_RANfunctionLoadConfirm_List.h ---

/************************************************************/
/* File .h missing: e2ap_RICserviceLoadStatusResponse_IEs.h */
/************************************************************/

// --- Begin of e2ap_RICserviceLoadStatusResponse.h ---
/*****************************************/
/*           RICserviceLoadStatusResponse                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICserviceLoadStatusResponse {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICserviceLoadStatusResponse;

EXTERN int asn1PE_e2ap_RICserviceLoadStatusResponse (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadStatusResponse (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadStatusResponse (e2ap_RICserviceLoadStatusResponse* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadStatusResponse (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse* pvalue);
EXTERN void asn1Print_e2ap_RICserviceLoadStatusResponse (const char* name, const e2ap_RICserviceLoadStatusResponse* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadStatusResponse (const char* name, e2ap_RICserviceLoadStatusResponse* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICserviceLoadStatusResponse (OSCTXT* pctxt, const char* name, const e2ap_RICserviceLoadStatusResponse* pvalue);
EXTERN int asn1Copy_e2ap_RICserviceLoadStatusResponse (OSCTXT* pctxt, const e2ap_RICserviceLoadStatusResponse* pSrcValue, e2ap_RICserviceLoadStatusResponse* pDstValue);
// --- End of e2ap_RICserviceLoadStatusResponse.h ---

// --- Begin of e2ap_RICserviceLoadStatusResponse_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICserviceLoadStatusResponse_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICserviceLoadStatusResponse*/

typedef OSRTDList e2ap_RICserviceLoadStatusResponse_protocolIEs;

EXTERN int asn1PE_e2ap_RICserviceLoadStatusResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadStatusResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadStatusResponse_protocolIEs (e2ap_RICserviceLoadStatusResponse_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadStatusResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadStatusResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICserviceLoadStatusResponse_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICserviceLoadStatusResponse_protocolIEs* pvalue);
// --- End of e2ap_RICserviceLoadStatusResponse_protocolIEs.h ---

// --- Begin of e2ap_RICserviceLoadStatusResponse_protocolIEs_element.h ---
/*****************************************/
/*    RICserviceLoadStatusResponse_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICserviceLoadStatusResponse*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_RICloadMeasurementID,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_E2nodeLoadMeasurementID,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusResponse_IEs_id_Extended_RANNodeName_

}e2ap_RICserviceLoadStatusResponse_IEs_TVALUE;


typedef struct EXTERN e2ap_RICserviceLoadStatusResponse_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICserviceLoadStatusResponse_IEs_TVALUE t;
      union {
        /*
        *id: id-LoadMeasurementID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_LoadMeasurementID *_e2ap_RICserviceLoadStatusResponse_IEs_id_RICloadMeasurementID;


        /*
        *id: id-LoadMeasurementID
        *criticality: ignore
        *presence: MANDATORY
        */
        e2ap_LoadMeasurementID *_e2ap_RICserviceLoadStatusResponse_IEs_id_E2nodeLoadMeasurementID;


        /*
        *id: id-RANfunctionLoadConfirm-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctionLoadConfirm_List *_e2ap_RICserviceLoadStatusResponse_IEs_id_RANfunctionLoadConfirm_List;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICserviceLoadStatusResponse_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICserviceLoadStatusResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadStatusResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadStatusResponse_protocolIEs_element (e2ap_RICserviceLoadStatusResponse_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadStatusResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadStatusResponse_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadStatusResponse_protocolIEs_element* pvalue);
// --- End of e2ap_RICserviceLoadStatusResponse_protocolIEs_element.h ---

#endif
