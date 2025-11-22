
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

// --- Begin of e2ap_RegistrationRequest.h ---
/******************************************************/
/*                                                    */
/*    RegistrationRequest                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_start = 0,
    e2ap_stop = 1,
    e2ap_add = 2
} e2ap_RegistrationRequest_Root;

typedef OSUINT32 e2ap_RegistrationRequest;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RegistrationRequest (OSCTXT* pctxt, e2ap_RegistrationRequest value);
EXTERN int asn1PD_e2ap_RegistrationRequest (OSCTXT* pctxt, e2ap_RegistrationRequest* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RegistrationRequest (const char* name, const e2ap_RegistrationRequest* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RegistrationRequest (OSCTXT* pctxt, const char* name, const e2ap_RegistrationRequest* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RegistrationRequest (const char* name,const e2ap_RegistrationRequest* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RegistrationRequest_ENUMTAB[];
#define e2ap_RegistrationRequest_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RegistrationRequest_ToString (OSUINT32 value);
EXTERN int e2ap_RegistrationRequest_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RegistrationRequest* pvalue);
EXTERN int e2ap_RegistrationRequest_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RegistrationRequest* pvalue);
// --- End of e2ap_RegistrationRequest.h ---

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

// --- Begin of e2ap_RICloadRequest.h ---
/******************************************************/
/*                                                    */
/*    RICloadRequest                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_true = 0
} e2ap_RICloadRequest_Root;

typedef OSUINT32 e2ap_RICloadRequest;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_RICloadRequest (OSCTXT* pctxt, e2ap_RICloadRequest value);
EXTERN int asn1PD_e2ap_RICloadRequest (OSCTXT* pctxt, e2ap_RICloadRequest* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_RICloadRequest (const char* name, const e2ap_RICloadRequest* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_RICloadRequest (OSCTXT* pctxt, const char* name, const e2ap_RICloadRequest* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_RICloadRequest (const char* name,const e2ap_RICloadRequest* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_RICloadRequest_ENUMTAB[];
#define e2ap_RICloadRequest_ENUMTABSIZE 1

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_RICloadRequest_ToString (OSUINT32 value);
EXTERN int e2ap_RICloadRequest_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_RICloadRequest* pvalue);
EXTERN int e2ap_RICloadRequest_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_RICloadRequest* pvalue);
// --- End of e2ap_RICloadRequest.h ---

// --- Begin of e2ap_RICserviceLoadRequest.h ---
/*****************************************/
/*           RICserviceLoadRequest                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICserviceLoadRequest {
   e2ap_RICloadRequest ricServiceReportLoadRequest;
     OSBOOL m_ricServiceReportLoadRequestPresent;   e2ap_RICloadRequest ricServiceInsertLoadRequest;
     OSBOOL m_ricServiceInsertLoadRequestPresent;   e2ap_RICloadRequest ricServiceControlLoadRequest;
     OSBOOL m_ricServiceControlLoadRequestPresent;   e2ap_RICloadRequest ricServicePolicyLoadRequest;
     OSBOOL m_ricServicePolicyLoadRequestPresent;   e2ap_RICloadRequest ricServiceQueryLoadRequest;
     OSBOOL m_ricServiceQueryLoadRequestPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICserviceLoadRequest;

EXTERN int asn1PE_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, e2ap_RICserviceLoadRequest* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, e2ap_RICserviceLoadRequest* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadRequest (e2ap_RICserviceLoadRequest* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, e2ap_RICserviceLoadRequest* pvalue);
EXTERN void asn1Print_e2ap_RICserviceLoadRequest (const char* name, const e2ap_RICserviceLoadRequest* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadRequest (const char* name, e2ap_RICserviceLoadRequest* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, const char* name, const e2ap_RICserviceLoadRequest* pvalue);
EXTERN int asn1Copy_e2ap_RICserviceLoadRequest (OSCTXT* pctxt, const e2ap_RICserviceLoadRequest* pSrcValue, e2ap_RICserviceLoadRequest* pDstValue);
// --- End of e2ap_RICserviceLoadRequest.h ---

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

// --- Begin of e2ap_RICactionLoadRequest_Item.h ---
/*****************************************/
/*           RICactionLoadRequest_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICactionLoadRequest_Item {
   e2ap_RICactionID ricActionID;
   e2ap_RICloadRequest ricActionLoadRequest;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICactionLoadRequest_Item;

EXTERN int asn1PE_e2ap_RICactionLoadRequest_Item (OSCTXT* pctxt, e2ap_RICactionLoadRequest_Item* pvalue);
EXTERN int asn1PD_e2ap_RICactionLoadRequest_Item (OSCTXT* pctxt, e2ap_RICactionLoadRequest_Item* pvalue);
EXTERN int asn1Init_e2ap_RICactionLoadRequest_Item (e2ap_RICactionLoadRequest_Item* pvalue);
EXTERN void asn1Free_e2ap_RICactionLoadRequest_Item (OSCTXT* pctxt, e2ap_RICactionLoadRequest_Item* pvalue);
EXTERN void asn1Print_e2ap_RICactionLoadRequest_Item (const char* name, const e2ap_RICactionLoadRequest_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactionLoadRequest_Item (const char* name, e2ap_RICactionLoadRequest_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICactionLoadRequest_Item (OSCTXT* pctxt, const char* name, const e2ap_RICactionLoadRequest_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICactionLoadRequest_Item (OSCTXT* pctxt, const e2ap_RICactionLoadRequest_Item* pSrcValue, e2ap_RICactionLoadRequest_Item* pDstValue);
// --- End of e2ap_RICactionLoadRequest_Item.h ---

// --- Begin of e2ap_RICactionLoadRequest_ItemIEs.h ---
/* e2ap_RICactionLoadRequest_ItemIEs.h */

/*****************************************/
/*           RICactionLoadRequest_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICactionLoadRequest_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICactionLoadRequest_ItemIEs_RICactionLoadRequest_Item   
   

} e2ap_RICactionLoadRequest_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICactionLoadRequest_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICactionLoadRequest_ItemIEs_TVALUE t;
      union {
         e2ap_RICactionLoadRequest_Item * _e2apRICactionLoadRequest_ItemIEs_RICactionLoadRequest_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICactionLoadRequest_ItemIEs;

EXTERN int  asn1PE_e2ap_RICactionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoadRequest_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICactionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoadRequest_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICactionLoadRequest_ItemIEs (e2ap_RICactionLoadRequest_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICactionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoadRequest_ItemIEs* pvalue);

// --- End of e2ap_RICactionLoadRequest_ItemIEs.h ---

// --- Begin of e2ap_RICactionLoadRequest_List.h ---
/*****************************************/
/*           RICactionLoadRequest_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICactionLoadRequest_List;

EXTERN int asn1PE_e2ap_RICactionLoadRequest_List (OSCTXT* pctxt, e2ap_RICactionLoadRequest_List* pvalue);
EXTERN int asn1PD_e2ap_RICactionLoadRequest_List (OSCTXT* pctxt, e2ap_RICactionLoadRequest_List* ppvalue);
EXTERN void asn1Init_e2ap_RICactionLoadRequest_List (e2ap_RICactionLoadRequest_List* pvalue);
EXTERN void asn1Free_e2ap_RICactionLoadRequest_List (OSCTXT* pctxt, e2ap_RICactionLoadRequest_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactionLoadRequest_List (const char* name, e2ap_RICactionLoadRequest_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICactionLoadRequest_List (OSCTXT* pctxt, const e2ap_RICactionLoadRequest_List* pSrcValue, e2ap_RICactionLoadRequest_List* pDstValue);
EXTERN void asn1Print_e2ap_RICactionLoadRequest_List (const char *name, const e2ap_RICactionLoadRequest_List* pvalue);
// --- End of e2ap_RICactionLoadRequest_List.h ---

// --- Begin of e2ap_RICsubscriptionLoadRequest_ItemIE.h ---
/*****************************************/
/*           RICsubscriptionLoadRequest_ItemIE                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionLoadRequest_ItemIE {
   e2ap_RICrequestID ricRequestID;
   e2ap_RICloadRequest ricSubscriptionLoadRequest;
     OSBOOL m_ricSubscriptionLoadRequestPresent;   e2ap_RICactionLoadRequest_List ricActionLoadRequest_list;
     OSBOOL m_ricActionLoadRequest_listPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionLoadRequest_ItemIE;

EXTERN int asn1PE_e2ap_RICsubscriptionLoadRequest_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_ItemIE* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionLoadRequest_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_ItemIE* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionLoadRequest_ItemIE (e2ap_RICsubscriptionLoadRequest_ItemIE* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionLoadRequest_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_ItemIE* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionLoadRequest_ItemIE (const char* name, const e2ap_RICsubscriptionLoadRequest_ItemIE* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionLoadRequest_ItemIE (const char* name, e2ap_RICsubscriptionLoadRequest_ItemIE* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionLoadRequest_ItemIE (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionLoadRequest_ItemIE* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionLoadRequest_ItemIE (OSCTXT* pctxt, const e2ap_RICsubscriptionLoadRequest_ItemIE* pSrcValue, e2ap_RICsubscriptionLoadRequest_ItemIE* pDstValue);
// --- End of e2ap_RICsubscriptionLoadRequest_ItemIE.h ---

// --- Begin of e2ap_RICsubscriptionLoadRequest_ItemIEs.h ---
/* e2ap_RICsubscriptionLoadRequest_ItemIEs.h */

/*****************************************/
/*           RICsubscriptionLoadRequest_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionLoadRequest_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICsubscriptionLoadRequest_ItemIEs_RICsubscriptionLoadRequest_ItemIE   
   

} e2ap_RICsubscriptionLoadRequest_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICsubscriptionLoadRequest_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionLoadRequest_ItemIEs_TVALUE t;
      union {
         e2ap_RICsubscriptionLoadRequest_ItemIE * _e2apRICsubscriptionLoadRequest_ItemIEs_RICsubscriptionLoadRequest_ItemIE;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICsubscriptionLoadRequest_ItemIEs;

EXTERN int  asn1PE_e2ap_RICsubscriptionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICsubscriptionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionLoadRequest_ItemIEs (e2ap_RICsubscriptionLoadRequest_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_ItemIEs* pvalue);

// --- End of e2ap_RICsubscriptionLoadRequest_ItemIEs.h ---

// --- Begin of e2ap_RICsubscriptionLoadRequest_List.h ---
/*****************************************/
/*           RICsubscriptionLoadRequest_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICsubscriptionLoadRequest_List;

EXTERN int asn1PE_e2ap_RICsubscriptionLoadRequest_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_List* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionLoadRequest_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_List* ppvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionLoadRequest_List (e2ap_RICsubscriptionLoadRequest_List* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionLoadRequest_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoadRequest_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionLoadRequest_List (const char* name, e2ap_RICsubscriptionLoadRequest_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICsubscriptionLoadRequest_List (OSCTXT* pctxt, const e2ap_RICsubscriptionLoadRequest_List* pSrcValue, e2ap_RICsubscriptionLoadRequest_List* pDstValue);
EXTERN void asn1Print_e2ap_RICsubscriptionLoadRequest_List (const char *name, const e2ap_RICsubscriptionLoadRequest_List* pvalue);
// --- End of e2ap_RICsubscriptionLoadRequest_List.h ---

// --- Begin of e2ap_RANfunctionLoadRequest_Item.h ---
/*****************************************/
/*           RANfunctionLoadRequest_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RANfunctionLoadRequest_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_RICloadRequest ranFunctionLoadRequest;
     OSBOOL m_ranFunctionLoadRequestPresent;   e2ap_RICserviceLoadRequest ricServiceLoadRequest;
     OSBOOL m_ricServiceLoadRequestPresent;   e2ap_RICsubscriptionLoadRequest_List ricSubscriptionLoadRequest_list;
     OSBOOL m_ricSubscriptionLoadRequest_listPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RANfunctionLoadRequest_Item;

EXTERN int asn1PE_e2ap_RANfunctionLoadRequest_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionLoadRequest_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_Item* pvalue);
EXTERN int asn1Init_e2ap_RANfunctionLoadRequest_Item (e2ap_RANfunctionLoadRequest_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionLoadRequest_Item (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionLoadRequest_Item (const char* name, const e2ap_RANfunctionLoadRequest_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionLoadRequest_Item (const char* name, e2ap_RANfunctionLoadRequest_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionLoadRequest_Item (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionLoadRequest_Item* pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionLoadRequest_Item (OSCTXT* pctxt, const e2ap_RANfunctionLoadRequest_Item* pSrcValue, e2ap_RANfunctionLoadRequest_Item* pDstValue);
// --- End of e2ap_RANfunctionLoadRequest_Item.h ---

// --- Begin of e2ap_RANfunctionLoadRequest_ItemIEs.h ---
/* e2ap_RANfunctionLoadRequest_ItemIEs.h */

/*****************************************/
/*           RANfunctionLoadRequest_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RANfunctionLoadRequest_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RANfunctionLoadRequest_ItemIEs_RANfunctionLoadRequest_Item   
   

} e2ap_RANfunctionLoadRequest_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RANfunctionLoadRequest_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RANfunctionLoadRequest_ItemIEs_TVALUE t;
      union {
         e2ap_RANfunctionLoadRequest_Item * _e2apRANfunctionLoadRequest_ItemIEs_RANfunctionLoadRequest_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RANfunctionLoadRequest_ItemIEs;

EXTERN int  asn1PE_e2ap_RANfunctionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RANfunctionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RANfunctionLoadRequest_ItemIEs (e2ap_RANfunctionLoadRequest_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionLoadRequest_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_ItemIEs* pvalue);

// --- End of e2ap_RANfunctionLoadRequest_ItemIEs.h ---

// --- Begin of e2ap_RANfunctionLoadRequest_List.h ---
/*****************************************/
/*           RANfunctionLoadRequest_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RANfunctionLoadRequest_List;

EXTERN int asn1PE_e2ap_RANfunctionLoadRequest_List (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_List* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionLoadRequest_List (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_List* ppvalue);
EXTERN void asn1Init_e2ap_RANfunctionLoadRequest_List (e2ap_RANfunctionLoadRequest_List* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionLoadRequest_List (OSCTXT* pctxt, e2ap_RANfunctionLoadRequest_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionLoadRequest_List (const char* name, e2ap_RANfunctionLoadRequest_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RANfunctionLoadRequest_List (OSCTXT* pctxt, const e2ap_RANfunctionLoadRequest_List* pSrcValue, e2ap_RANfunctionLoadRequest_List* pDstValue);
EXTERN void asn1Print_e2ap_RANfunctionLoadRequest_List (const char *name, const e2ap_RANfunctionLoadRequest_List* pvalue);
// --- End of e2ap_RANfunctionLoadRequest_List.h ---

// --- Begin of e2ap_ReportingPeriodicity.h ---
/******************************************************/
/*                                                    */
/*    ReportingPeriodicity                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_ms500 = 0,
    e2ap_ms1000 = 1,
    e2ap_ms2000 = 2,
    e2ap_ms5000 = 3,
    e2ap_ms10000 = 4
} e2ap_ReportingPeriodicity_Root;

typedef OSUINT32 e2ap_ReportingPeriodicity;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_ReportingPeriodicity (OSCTXT* pctxt, e2ap_ReportingPeriodicity value);
EXTERN int asn1PD_e2ap_ReportingPeriodicity (OSCTXT* pctxt, e2ap_ReportingPeriodicity* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_ReportingPeriodicity (const char* name, const e2ap_ReportingPeriodicity* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_ReportingPeriodicity (OSCTXT* pctxt, const char* name, const e2ap_ReportingPeriodicity* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_ReportingPeriodicity (const char* name,const e2ap_ReportingPeriodicity* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_ReportingPeriodicity_ENUMTAB[];
#define e2ap_ReportingPeriodicity_ENUMTABSIZE 5

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_ReportingPeriodicity_ToString (OSUINT32 value);
EXTERN int e2ap_ReportingPeriodicity_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_ReportingPeriodicity* pvalue);
EXTERN int e2ap_ReportingPeriodicity_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_ReportingPeriodicity* pvalue);
// --- End of e2ap_ReportingPeriodicity.h ---

/***********************************************************/
/* File .h missing: e2ap_RICserviceLoadStatusRequest_IEs.h */
/***********************************************************/

// --- Begin of e2ap_RICserviceLoadStatusRequest.h ---
/*****************************************/
/*           RICserviceLoadStatusRequest                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICserviceLoadStatusRequest {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICserviceLoadStatusRequest;

EXTERN int asn1PE_e2ap_RICserviceLoadStatusRequest (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadStatusRequest (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadStatusRequest (e2ap_RICserviceLoadStatusRequest* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadStatusRequest (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest* pvalue);
EXTERN void asn1Print_e2ap_RICserviceLoadStatusRequest (const char* name, const e2ap_RICserviceLoadStatusRequest* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadStatusRequest (const char* name, e2ap_RICserviceLoadStatusRequest* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICserviceLoadStatusRequest (OSCTXT* pctxt, const char* name, const e2ap_RICserviceLoadStatusRequest* pvalue);
EXTERN int asn1Copy_e2ap_RICserviceLoadStatusRequest (OSCTXT* pctxt, const e2ap_RICserviceLoadStatusRequest* pSrcValue, e2ap_RICserviceLoadStatusRequest* pDstValue);
// --- End of e2ap_RICserviceLoadStatusRequest.h ---

// --- Begin of e2ap_RICserviceLoadStatusRequest_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICserviceLoadStatusRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICserviceLoadStatusRequest*/

typedef OSRTDList e2ap_RICserviceLoadStatusRequest_protocolIEs;

EXTERN int asn1PE_e2ap_RICserviceLoadStatusRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadStatusRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadStatusRequest_protocolIEs (e2ap_RICserviceLoadStatusRequest_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadStatusRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadStatusRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICserviceLoadStatusRequest_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICserviceLoadStatusRequest_protocolIEs* pvalue);
// --- End of e2ap_RICserviceLoadStatusRequest_protocolIEs.h ---

// --- Begin of e2ap_RICserviceLoadStatusRequest_protocolIEs_element.h ---
/*****************************************/
/*    RICserviceLoadStatusRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICserviceLoadStatusRequest*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_RICloadMeasurementID,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_E2nodeLoadMeasurementID,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadStatusRequest_IEs_id_Extended_RANNodeName_

}e2ap_RICserviceLoadStatusRequest_IEs_TVALUE;


typedef struct EXTERN e2ap_RICserviceLoadStatusRequest_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICserviceLoadStatusRequest_IEs_TVALUE t;
      union {
        /*
        *id: id-LoadMeasurementID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_LoadMeasurementID *_e2ap_RICserviceLoadStatusRequest_IEs_id_RICloadMeasurementID;


        /*
        *id: id-LoadMeasurementID
        *criticality: ignore
        *presence: MANDATORY
        */
        e2ap_LoadMeasurementID *_e2ap_RICserviceLoadStatusRequest_IEs_id_E2nodeLoadMeasurementID;


        /*
        *id: id-RegistrationRequest
        *criticality: ignore
        *presence: MANDATORY
        */
        e2ap_RegistrationRequest *_e2ap_RICserviceLoadStatusRequest_IEs_id_RegistrationRequest;


        /*
        *id: id-RANfunctionLoadRequest-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctionLoadRequest_List *_e2ap_RICserviceLoadStatusRequest_IEs_id_RANfunctionLoadRequest_List;


        /*
        *id: id-ReportingPeriodicity
        *criticality: ignore
        *presence: OPTIONAL
        */
        e2ap_ReportingPeriodicity *_e2ap_RICserviceLoadStatusRequest_IEs_id_ReportingPeriodicity;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICserviceLoadStatusRequest_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICserviceLoadStatusRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadStatusRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadStatusRequest_protocolIEs_element (e2ap_RICserviceLoadStatusRequest_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadStatusRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadStatusRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadStatusRequest_protocolIEs_element* pvalue);
// --- End of e2ap_RICserviceLoadStatusRequest_protocolIEs_element.h ---

#endif
