
#ifndef OUTPUT_MAIN_H
#define OUTPUT_MAIN_H

// --- Begin of doc/header.h ---
//======================E2AP.h========================//
typedef pd_BitString32 pd_BitString32;
typedef pe_BitString32 pe_BitString32;
typedef asn1PrtToStr_ASN1BitStr32 rtPrintToStringBitStrBraceText;
typedef //asn1Free_ASN1BitStr32 

// --- End of doc/header.h ---

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

// --- Begin of e2ap_RICeventTriggerDefinition.h ---
/*****************************************/
/*           RICeventTriggerDefinition                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICeventTriggerDefinition;

EXTERN int asn1PE_e2ap_RICeventTriggerDefinition (OSCTXT* pctxt, e2ap_RICeventTriggerDefinition* pvalue);
EXTERN int asn1PD_e2ap_RICeventTriggerDefinition (OSCTXT* pctxt, e2ap_RICeventTriggerDefinition** ppvalue);
EXTERN void asn1Print_e2ap_RICeventTriggerDefinition (const char* name, const e2ap_RICeventTriggerDefinition* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICeventTriggerDefinition (const char* name, e2ap_RICeventTriggerDefinition* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICeventTriggerDefinition (OSCTXT* pctxt, const char* name, const e2ap_RICeventTriggerDefinition* pvalue);
EXTERN int asn1Copy_e2ap_RICeventTriggerDefinition (OSCTXT* pctxt, const e2ap_RICeventTriggerDefinition* pSrcValue, e2ap_RICeventTriggerDefinition* pDstValue);
EXTERN int asn1Init_e2ap_RICeventTriggerDefinition (e2ap_RICeventTriggerDefinition* pvalue);
EXTERN void asn1Free_e2ap_RICeventTriggerDefinition (OSCTXT* pctxt, e2ap_RICeventTriggerDefinition* pvalue);
// --- End of e2ap_RICeventTriggerDefinition.h ---

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

// --- Begin of e2ap_RICaction_ToBeRemovedForModification_Item.h ---
/*****************************************/
/*           RICaction_ToBeRemovedForModification_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICaction_ToBeRemovedForModification_Item {
   e2ap_RICactionID ricActionID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICaction_ToBeRemovedForModification_Item;

EXTERN int asn1PE_e2ap_RICaction_ToBeRemovedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeRemovedForModification_Item* pvalue);
EXTERN int asn1PD_e2ap_RICaction_ToBeRemovedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeRemovedForModification_Item* pvalue);
EXTERN int asn1Init_e2ap_RICaction_ToBeRemovedForModification_Item (e2ap_RICaction_ToBeRemovedForModification_Item* pvalue);
EXTERN void asn1Free_e2ap_RICaction_ToBeRemovedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeRemovedForModification_Item* pvalue);
EXTERN void asn1Print_e2ap_RICaction_ToBeRemovedForModification_Item (const char* name, const e2ap_RICaction_ToBeRemovedForModification_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICaction_ToBeRemovedForModification_Item (const char* name, e2ap_RICaction_ToBeRemovedForModification_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICaction_ToBeRemovedForModification_Item (OSCTXT* pctxt, const char* name, const e2ap_RICaction_ToBeRemovedForModification_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICaction_ToBeRemovedForModification_Item (OSCTXT* pctxt, const e2ap_RICaction_ToBeRemovedForModification_Item* pSrcValue, e2ap_RICaction_ToBeRemovedForModification_Item* pDstValue);
// --- End of e2ap_RICaction_ToBeRemovedForModification_Item.h ---

// --- Begin of e2ap_RICaction_ToBeRemovedForModification_ItemIEs.h ---
/* e2ap_RICaction_ToBeRemovedForModification_ItemIEs.h */

/*****************************************/
/*           RICaction_ToBeRemovedForModification_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICaction_ToBeRemovedForModification_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICaction_ToBeRemovedForModification_ItemIEs_RICaction_ToBeRemovedForModification_Item   
   

} e2ap_RICaction_ToBeRemovedForModification_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICaction_ToBeRemovedForModification_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICaction_ToBeRemovedForModification_ItemIEs_TVALUE t;
      union {
         e2ap_RICaction_ToBeRemovedForModification_Item * _e2apRICaction_ToBeRemovedForModification_ItemIEs_RICaction_ToBeRemovedForModification_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICaction_ToBeRemovedForModification_ItemIEs;

EXTERN int  asn1PE_e2ap_RICaction_ToBeRemovedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeRemovedForModification_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICaction_ToBeRemovedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeRemovedForModification_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICaction_ToBeRemovedForModification_ItemIEs (e2ap_RICaction_ToBeRemovedForModification_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICaction_ToBeRemovedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeRemovedForModification_ItemIEs* pvalue);

// --- End of e2ap_RICaction_ToBeRemovedForModification_ItemIEs.h ---

// --- Begin of e2ap_RICactions_ToBeRemovedForModification_List.h ---
/*****************************************/
/*           RICactions_ToBeRemovedForModification_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICactions_ToBeRemovedForModification_List;

EXTERN int asn1PE_e2ap_RICactions_ToBeRemovedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeRemovedForModification_List* pvalue);
EXTERN int asn1PD_e2ap_RICactions_ToBeRemovedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeRemovedForModification_List* ppvalue);
EXTERN void asn1Init_e2ap_RICactions_ToBeRemovedForModification_List (e2ap_RICactions_ToBeRemovedForModification_List* pvalue);
EXTERN void asn1Free_e2ap_RICactions_ToBeRemovedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeRemovedForModification_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactions_ToBeRemovedForModification_List (const char* name, e2ap_RICactions_ToBeRemovedForModification_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICactions_ToBeRemovedForModification_List (OSCTXT* pctxt, const e2ap_RICactions_ToBeRemovedForModification_List* pSrcValue, e2ap_RICactions_ToBeRemovedForModification_List* pDstValue);
EXTERN void asn1Print_e2ap_RICactions_ToBeRemovedForModification_List (const char *name, const e2ap_RICactions_ToBeRemovedForModification_List* pvalue);
// --- End of e2ap_RICactions_ToBeRemovedForModification_List.h ---

// --- Begin of e2ap_RICactionDefinition.h ---
/*****************************************/
/*           RICactionDefinition                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RICactionDefinition;

EXTERN int asn1PE_e2ap_RICactionDefinition (OSCTXT* pctxt, e2ap_RICactionDefinition* pvalue);
EXTERN int asn1PD_e2ap_RICactionDefinition (OSCTXT* pctxt, e2ap_RICactionDefinition** ppvalue);
EXTERN void asn1Print_e2ap_RICactionDefinition (const char* name, const e2ap_RICactionDefinition* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactionDefinition (const char* name, e2ap_RICactionDefinition* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICactionDefinition (OSCTXT* pctxt, const char* name, const e2ap_RICactionDefinition* pvalue);
EXTERN int asn1Copy_e2ap_RICactionDefinition (OSCTXT* pctxt, const e2ap_RICactionDefinition* pSrcValue, e2ap_RICactionDefinition* pDstValue);
EXTERN int asn1Init_e2ap_RICactionDefinition (e2ap_RICactionDefinition* pvalue);
EXTERN void asn1Free_e2ap_RICactionDefinition (OSCTXT* pctxt, e2ap_RICactionDefinition* pvalue);
// --- End of e2ap_RICactionDefinition.h ---

// --- Begin of e2ap_RICactionExecutionOrder.h ---
/*****************************************/
/*        RICactionExecutionOrder         */
/*****************************************/
//interger no ext


typedef OSUINT8 e2ap_RICactionExecutionOrder;

EXTERN int asn1PE_e2ap_RICactionExecutionOrder (OSCTXT* pctxt, e2ap_RICactionExecutionOrder value);
EXTERN int asn1PD_e2ap_RICactionExecutionOrder (OSCTXT* pctxt, e2ap_RICactionExecutionOrder* pvalue);
EXTERN void asn1Print_e2ap_RICactionExecutionOrder (const char* name, const e2ap_RICactionExecutionOrder* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactionExecutionOrder (const char* name, e2ap_RICactionExecutionOrder* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICactionExecutionOrder (OSCTXT* pctxt, const char* name, const e2ap_RICactionExecutionOrder* pvalue);
// --- End of e2ap_RICactionExecutionOrder.h ---

// --- Begin of e2ap_RICsubsequentActionType.h ---
/******************************************************/
/*                                                    */
/*    RICsubsequentActionType                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_continue = 0,
    e2ap_wait = 1
} e2ap_RICsubsequentActionType_Root;

typedef OSUINT32 e2ap_RICsubsequentActionType;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICsubsequentActionType (OSCTXT* pctxt, e2ap_RICsubsequentActionType value);
EXTERN int asn1PD_e2ap_RICsubsequentActionType (OSCTXT* pctxt, e2ap_RICsubsequentActionType* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICsubsequentActionType (const char* name, const e2ap_RICsubsequentActionType* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICsubsequentActionType (OSCTXT* pctxt, const char* name, const e2ap_RICsubsequentActionType* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICsubsequentActionType (const char* name,const e2ap_RICsubsequentActionType* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICsubsequentActionType_ENUMTAB[];
#define e2ap_RICsubsequentActionType_ENUMTABSIZE 2

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICsubsequentActionType_ToString (OSUINT32 value);
EXTERN int e2ap_RICsubsequentActionType_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICsubsequentActionType* pvalue);
EXTERN int e2ap_RICsubsequentActionType_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICsubsequentActionType* pvalue);
// --- End of e2ap_RICsubsequentActionType.h ---

// --- Begin of e2ap_RICtimeToWait.h ---
/******************************************************/
/*                                                    */
/*    RICtimeToWait                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_w1ms = 0,
    e2ap_w2ms = 1,
    e2ap_w5ms = 2,
    e2ap_w10ms = 3,
    e2ap_w20ms = 4,
    e2ap_w30ms = 5,
    e2ap_w40ms = 6,
    e2ap_w50ms = 7,
    e2ap_w100ms = 8,
    e2ap_w200ms = 9,
    e2ap_w500ms = 10,
    e2ap_w1s = 11,
    e2ap_w2s = 12,
    e2ap_w5s = 13,
    e2ap_w10s = 14,
    e2ap_w20s = 15,
    e2ap_w60s = 16
} e2ap_RICtimeToWait_Root;

typedef OSUINT32 e2ap_RICtimeToWait;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICtimeToWait (OSCTXT* pctxt, e2ap_RICtimeToWait value);
EXTERN int asn1PD_e2ap_RICtimeToWait (OSCTXT* pctxt, e2ap_RICtimeToWait* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICtimeToWait (const char* name, const e2ap_RICtimeToWait* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICtimeToWait (OSCTXT* pctxt, const char* name, const e2ap_RICtimeToWait* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICtimeToWait (const char* name,const e2ap_RICtimeToWait* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICtimeToWait_ENUMTAB[];
#define e2ap_RICtimeToWait_ENUMTABSIZE 17

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICtimeToWait_ToString (OSUINT32 value);
EXTERN int e2ap_RICtimeToWait_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICtimeToWait* pvalue);
EXTERN int e2ap_RICtimeToWait_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICtimeToWait* pvalue);
// --- End of e2ap_RICtimeToWait.h ---

// --- Begin of e2ap_RICsubsequentAction.h ---
/*****************************************/
/*           RICsubsequentAction                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubsequentAction {
   e2ap_RICsubsequentActionType ricSubsequentActionType;
   e2ap_RICtimeToWait ricTimeToWait;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubsequentAction;

EXTERN int asn1PE_e2ap_RICsubsequentAction (OSCTXT* pctxt, e2ap_RICsubsequentAction* pvalue);
EXTERN int asn1PD_e2ap_RICsubsequentAction (OSCTXT* pctxt, e2ap_RICsubsequentAction* pvalue);
EXTERN int asn1Init_e2ap_RICsubsequentAction (e2ap_RICsubsequentAction* pvalue);
EXTERN void asn1Free_e2ap_RICsubsequentAction (OSCTXT* pctxt, e2ap_RICsubsequentAction* pvalue);
EXTERN void asn1Print_e2ap_RICsubsequentAction (const char* name, const e2ap_RICsubsequentAction* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubsequentAction (const char* name, e2ap_RICsubsequentAction* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubsequentAction (OSCTXT* pctxt, const char* name, const e2ap_RICsubsequentAction* pvalue);
EXTERN int asn1Copy_e2ap_RICsubsequentAction (OSCTXT* pctxt, const e2ap_RICsubsequentAction* pSrcValue, e2ap_RICsubsequentAction* pDstValue);
// --- End of e2ap_RICsubsequentAction.h ---

// --- Begin of e2ap_RICaction_ToBeModifiedForModification_Item.h ---
/*****************************************/
/*           RICaction_ToBeModifiedForModification_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICaction_ToBeModifiedForModification_Item {
   e2ap_RICactionID ricActionID;
   e2ap_RICactionDefinition ricActionDefinition;
     OSBOOL m_ricActionDefinitionPresent;   e2ap_RICactionExecutionOrder ricActionExecutionOrder;
     OSBOOL m_ricActionExecutionOrderPresent;   e2ap_RICsubsequentAction ricSubsequentAction;
     OSBOOL m_ricSubsequentActionPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICaction_ToBeModifiedForModification_Item;

EXTERN int asn1PE_e2ap_RICaction_ToBeModifiedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeModifiedForModification_Item* pvalue);
EXTERN int asn1PD_e2ap_RICaction_ToBeModifiedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeModifiedForModification_Item* pvalue);
EXTERN int asn1Init_e2ap_RICaction_ToBeModifiedForModification_Item (e2ap_RICaction_ToBeModifiedForModification_Item* pvalue);
EXTERN void asn1Free_e2ap_RICaction_ToBeModifiedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeModifiedForModification_Item* pvalue);
EXTERN void asn1Print_e2ap_RICaction_ToBeModifiedForModification_Item (const char* name, const e2ap_RICaction_ToBeModifiedForModification_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICaction_ToBeModifiedForModification_Item (const char* name, e2ap_RICaction_ToBeModifiedForModification_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICaction_ToBeModifiedForModification_Item (OSCTXT* pctxt, const char* name, const e2ap_RICaction_ToBeModifiedForModification_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICaction_ToBeModifiedForModification_Item (OSCTXT* pctxt, const e2ap_RICaction_ToBeModifiedForModification_Item* pSrcValue, e2ap_RICaction_ToBeModifiedForModification_Item* pDstValue);
// --- End of e2ap_RICaction_ToBeModifiedForModification_Item.h ---

// --- Begin of e2ap_RICaction_ToBeModifiedForModification_ItemIEs.h ---
/* e2ap_RICaction_ToBeModifiedForModification_ItemIEs.h */

/*****************************************/
/*           RICaction_ToBeModifiedForModification_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICaction_ToBeModifiedForModification_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICaction_ToBeModifiedForModification_ItemIEs_RICaction_ToBeModifiedForModification_Item   
   

} e2ap_RICaction_ToBeModifiedForModification_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICaction_ToBeModifiedForModification_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICaction_ToBeModifiedForModification_ItemIEs_TVALUE t;
      union {
         e2ap_RICaction_ToBeModifiedForModification_Item * _e2apRICaction_ToBeModifiedForModification_ItemIEs_RICaction_ToBeModifiedForModification_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICaction_ToBeModifiedForModification_ItemIEs;

EXTERN int  asn1PE_e2ap_RICaction_ToBeModifiedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeModifiedForModification_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICaction_ToBeModifiedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeModifiedForModification_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICaction_ToBeModifiedForModification_ItemIEs (e2ap_RICaction_ToBeModifiedForModification_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICaction_ToBeModifiedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeModifiedForModification_ItemIEs* pvalue);

// --- End of e2ap_RICaction_ToBeModifiedForModification_ItemIEs.h ---

// --- Begin of e2ap_RICactions_ToBeModifiedForModification_List.h ---
/*****************************************/
/*           RICactions_ToBeModifiedForModification_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICactions_ToBeModifiedForModification_List;

EXTERN int asn1PE_e2ap_RICactions_ToBeModifiedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeModifiedForModification_List* pvalue);
EXTERN int asn1PD_e2ap_RICactions_ToBeModifiedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeModifiedForModification_List* ppvalue);
EXTERN void asn1Init_e2ap_RICactions_ToBeModifiedForModification_List (e2ap_RICactions_ToBeModifiedForModification_List* pvalue);
EXTERN void asn1Free_e2ap_RICactions_ToBeModifiedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeModifiedForModification_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactions_ToBeModifiedForModification_List (const char* name, e2ap_RICactions_ToBeModifiedForModification_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICactions_ToBeModifiedForModification_List (OSCTXT* pctxt, const e2ap_RICactions_ToBeModifiedForModification_List* pSrcValue, e2ap_RICactions_ToBeModifiedForModification_List* pDstValue);
EXTERN void asn1Print_e2ap_RICactions_ToBeModifiedForModification_List (const char *name, const e2ap_RICactions_ToBeModifiedForModification_List* pvalue);
// --- End of e2ap_RICactions_ToBeModifiedForModification_List.h ---

// --- Begin of e2ap_RICactionType.h ---
/******************************************************/
/*                                                    */
/*    RICactionType                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_report = 0,
    e2ap_insert = 1,
    e2ap_policy = 2
} e2ap_RICactionType_Root;

typedef OSUINT32 e2ap_RICactionType;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICactionType (OSCTXT* pctxt, e2ap_RICactionType value);
EXTERN int asn1PD_e2ap_RICactionType (OSCTXT* pctxt, e2ap_RICactionType* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICactionType (const char* name, const e2ap_RICactionType* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICactionType (OSCTXT* pctxt, const char* name, const e2ap_RICactionType* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICactionType (const char* name,const e2ap_RICactionType* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICactionType_ENUMTAB[];
#define e2ap_RICactionType_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICactionType_ToString (OSUINT32 value);
EXTERN int e2ap_RICactionType_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICactionType* pvalue);
EXTERN int e2ap_RICactionType_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICactionType* pvalue);
// --- End of e2ap_RICactionType.h ---

// --- Begin of e2ap_RICaction_ToBeAddedForModification_Item.h ---
/*****************************************/
/*           RICaction_ToBeAddedForModification_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICaction_ToBeAddedForModification_Item {
   e2ap_RICactionID ricActionID;
   e2ap_RICactionType ricActionType;
   e2ap_RICactionDefinition ricActionDefinition;
   e2ap_RICactionExecutionOrder ricActionExecutionOrder;
   e2ap_RICsubsequentAction ricSubsequentAction;
     OSBOOL m_ricSubsequentActionPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICaction_ToBeAddedForModification_Item;

EXTERN int asn1PE_e2ap_RICaction_ToBeAddedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeAddedForModification_Item* pvalue);
EXTERN int asn1PD_e2ap_RICaction_ToBeAddedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeAddedForModification_Item* pvalue);
EXTERN int asn1Init_e2ap_RICaction_ToBeAddedForModification_Item (e2ap_RICaction_ToBeAddedForModification_Item* pvalue);
EXTERN void asn1Free_e2ap_RICaction_ToBeAddedForModification_Item (OSCTXT* pctxt, e2ap_RICaction_ToBeAddedForModification_Item* pvalue);
EXTERN void asn1Print_e2ap_RICaction_ToBeAddedForModification_Item (const char* name, const e2ap_RICaction_ToBeAddedForModification_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICaction_ToBeAddedForModification_Item (const char* name, e2ap_RICaction_ToBeAddedForModification_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICaction_ToBeAddedForModification_Item (OSCTXT* pctxt, const char* name, const e2ap_RICaction_ToBeAddedForModification_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICaction_ToBeAddedForModification_Item (OSCTXT* pctxt, const e2ap_RICaction_ToBeAddedForModification_Item* pSrcValue, e2ap_RICaction_ToBeAddedForModification_Item* pDstValue);
// --- End of e2ap_RICaction_ToBeAddedForModification_Item.h ---

// --- Begin of e2ap_RICaction_ToBeAddedForModification_ItemIEs.h ---
/* e2ap_RICaction_ToBeAddedForModification_ItemIEs.h */

/*****************************************/
/*           RICaction_ToBeAddedForModification_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICaction_ToBeAddedForModification_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICaction_ToBeAddedForModification_ItemIEs_RICaction_ToBeAddedForModification_Item   
   

} e2ap_RICaction_ToBeAddedForModification_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICaction_ToBeAddedForModification_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICaction_ToBeAddedForModification_ItemIEs_TVALUE t;
      union {
         e2ap_RICaction_ToBeAddedForModification_Item * _e2apRICaction_ToBeAddedForModification_ItemIEs_RICaction_ToBeAddedForModification_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICaction_ToBeAddedForModification_ItemIEs;

EXTERN int  asn1PE_e2ap_RICaction_ToBeAddedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeAddedForModification_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICaction_ToBeAddedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeAddedForModification_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICaction_ToBeAddedForModification_ItemIEs (e2ap_RICaction_ToBeAddedForModification_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICaction_ToBeAddedForModification_ItemIEs (OSCTXT* pctxt, e2ap_RICaction_ToBeAddedForModification_ItemIEs* pvalue);

// --- End of e2ap_RICaction_ToBeAddedForModification_ItemIEs.h ---

// --- Begin of e2ap_RICactions_ToBeAddedForModification_List.h ---
/*****************************************/
/*           RICactions_ToBeAddedForModification_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICactions_ToBeAddedForModification_List;

EXTERN int asn1PE_e2ap_RICactions_ToBeAddedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeAddedForModification_List* pvalue);
EXTERN int asn1PD_e2ap_RICactions_ToBeAddedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeAddedForModification_List* ppvalue);
EXTERN void asn1Init_e2ap_RICactions_ToBeAddedForModification_List (e2ap_RICactions_ToBeAddedForModification_List* pvalue);
EXTERN void asn1Free_e2ap_RICactions_ToBeAddedForModification_List (OSCTXT* pctxt, e2ap_RICactions_ToBeAddedForModification_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactions_ToBeAddedForModification_List (const char* name, e2ap_RICactions_ToBeAddedForModification_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICactions_ToBeAddedForModification_List (OSCTXT* pctxt, const e2ap_RICactions_ToBeAddedForModification_List* pSrcValue, e2ap_RICactions_ToBeAddedForModification_List* pDstValue);
EXTERN void asn1Print_e2ap_RICactions_ToBeAddedForModification_List (const char *name, const e2ap_RICactions_ToBeAddedForModification_List* pvalue);
// --- End of e2ap_RICactions_ToBeAddedForModification_List.h ---

/******************************************************************/
/* File .h missing: e2ap_RICsubscriptionModificationRequest_IEs.h */
/******************************************************************/

// --- Begin of e2ap_RICsubscriptionModificationRequest.h ---
/*****************************************/
/*           RICsubscriptionModificationRequest                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionModificationRequest {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionModificationRequest;

EXTERN int asn1PE_e2ap_RICsubscriptionModificationRequest (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionModificationRequest (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionModificationRequest (e2ap_RICsubscriptionModificationRequest* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionModificationRequest (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionModificationRequest (const char* name, const e2ap_RICsubscriptionModificationRequest* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionModificationRequest (const char* name, e2ap_RICsubscriptionModificationRequest* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionModificationRequest (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionModificationRequest* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionModificationRequest (OSCTXT* pctxt, const e2ap_RICsubscriptionModificationRequest* pSrcValue, e2ap_RICsubscriptionModificationRequest* pDstValue);
// --- End of e2ap_RICsubscriptionModificationRequest.h ---

// --- Begin of e2ap_RICsubscriptionModificationRequest_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICsubscriptionModificationRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICsubscriptionModificationRequest*/

typedef OSRTDList e2ap_RICsubscriptionModificationRequest_protocolIEs;

EXTERN int asn1PE_e2ap_RICsubscriptionModificationRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionModificationRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionModificationRequest_protocolIEs (e2ap_RICsubscriptionModificationRequest_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionModificationRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionModificationRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICsubscriptionModificationRequest_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICsubscriptionModificationRequest_protocolIEs* pvalue);
// --- End of e2ap_RICsubscriptionModificationRequest_protocolIEs.h ---

// --- Begin of e2ap_RICsubscriptionModificationRequest_protocolIEs_element.h ---
/*****************************************/
/*    RICsubscriptionModificationRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICsubscriptionModificationRequest*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinitionToBeModified,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeRemovedForModification_List,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeModifiedForModification_List,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeAddedForModification_List,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionModificationRequest_IEs_id_Extended_RANNodeName_

}e2ap_RICsubscriptionModificationRequest_IEs_TVALUE;


typedef struct EXTERN e2ap_RICsubscriptionModificationRequest_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionModificationRequest_IEs_TVALUE t;
      union {
        /*
        *id: id-RICrequestID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICrequestID *_e2ap_RICsubscriptionModificationRequest_IEs_id_RICrequestID;


        /*
        *id: id-RANfunctionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctionID *_e2ap_RICsubscriptionModificationRequest_IEs_id_RANfunctionID;


        /*
        *id: id-RICeventTriggerDefinition
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICeventTriggerDefinition *_e2ap_RICsubscriptionModificationRequest_IEs_id_RICeventTriggerDefinitionToBeModified;


        /*
        *id: id-RICactions-ToBeRemovedForModification-List
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICactions_ToBeRemovedForModification_List *_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeRemovedForModification_List;


        /*
        *id: id-RICactions-ToBeModifiedForModification-List
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICactions_ToBeModifiedForModification_List *_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeModifiedForModification_List;


        /*
        *id: id-RICactions-ToBeAddedForModification-List
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_RICactions_ToBeAddedForModification_List *_e2ap_RICsubscriptionModificationRequest_IEs_id_RICactionsToBeAddedForModification_List;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICsubscriptionModificationRequest_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionModificationRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionModificationRequest_protocolIEs_element* pvalue);
// --- End of e2ap_RICsubscriptionModificationRequest_protocolIEs_element.h ---

#endif
