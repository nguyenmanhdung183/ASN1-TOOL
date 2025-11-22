
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

/**************************************/
/* File .h missing: e2ap_loadStatus.h */
/**************************************/

/****************************************/
/* File .h missing: e2ap_loadEstimate.h */
/****************************************/

// --- Begin of e2ap_RICloadInformation.h ---
/*****************************************/
/*           RICloadInformation                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICloadInformation {
   e2ap_loadStatus loadStatus;
   e2ap_OPTIONAL notoverload;
     OSBOOL m_notoverloadPresent;   e2ap_loadEstimate loadEstimate;
     OSBOOL m_loadEstimatePresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICloadInformation;

EXTERN int asn1PE_e2ap_RICloadInformation (OSCTXT* pctxt, e2ap_RICloadInformation* pvalue);
EXTERN int asn1PD_e2ap_RICloadInformation (OSCTXT* pctxt, e2ap_RICloadInformation* pvalue);
EXTERN int asn1Init_e2ap_RICloadInformation (e2ap_RICloadInformation* pvalue);
EXTERN void asn1Free_e2ap_RICloadInformation (OSCTXT* pctxt, e2ap_RICloadInformation* pvalue);
EXTERN void asn1Print_e2ap_RICloadInformation (const char* name, const e2ap_RICloadInformation* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICloadInformation (const char* name, e2ap_RICloadInformation* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICloadInformation (OSCTXT* pctxt, const char* name, const e2ap_RICloadInformation* pvalue);
EXTERN int asn1Copy_e2ap_RICloadInformation (OSCTXT* pctxt, const e2ap_RICloadInformation* pSrcValue, e2ap_RICloadInformation* pDstValue);
// --- End of e2ap_RICloadInformation.h ---

// --- Begin of e2ap_RICserviceLoadInformation.h ---
/*****************************************/
/*           RICserviceLoadInformation                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICserviceLoadInformation {
   e2ap_RICloadInformation ricServiceReportLoadInformation;
     OSBOOL m_ricServiceReportLoadInformationPresent;   e2ap_RICloadInformation ricServiceInsertLoadInformation;
     OSBOOL m_ricServiceInsertLoadInformationPresent;   e2ap_RICloadInformation ricServiceControlLoadInformation;
     OSBOOL m_ricServiceControlLoadInformationPresent;   e2ap_RICloadInformation ricServicePolicyLoadInformation;
     OSBOOL m_ricServicePolicyLoadInformationPresent;   e2ap_RICloadInformation ricServiceQueryLoadInformation;
     OSBOOL m_ricServiceQueryLoadInformationPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICserviceLoadInformation;

EXTERN int asn1PE_e2ap_RICserviceLoadInformation (OSCTXT* pctxt, e2ap_RICserviceLoadInformation* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadInformation (OSCTXT* pctxt, e2ap_RICserviceLoadInformation* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadInformation (e2ap_RICserviceLoadInformation* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadInformation (OSCTXT* pctxt, e2ap_RICserviceLoadInformation* pvalue);
EXTERN void asn1Print_e2ap_RICserviceLoadInformation (const char* name, const e2ap_RICserviceLoadInformation* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadInformation (const char* name, e2ap_RICserviceLoadInformation* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICserviceLoadInformation (OSCTXT* pctxt, const char* name, const e2ap_RICserviceLoadInformation* pvalue);
EXTERN int asn1Copy_e2ap_RICserviceLoadInformation (OSCTXT* pctxt, const e2ap_RICserviceLoadInformation* pSrcValue, e2ap_RICserviceLoadInformation* pDstValue);
// --- End of e2ap_RICserviceLoadInformation.h ---

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

// --- Begin of e2ap_RICactionLoad_Item.h ---
/*****************************************/
/*           RICactionLoad_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICactionLoad_Item {
   e2ap_RICactionID ricActionID;
   e2ap_RICloadInformation ricActionLoadInformation;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICactionLoad_Item;

EXTERN int asn1PE_e2ap_RICactionLoad_Item (OSCTXT* pctxt, e2ap_RICactionLoad_Item* pvalue);
EXTERN int asn1PD_e2ap_RICactionLoad_Item (OSCTXT* pctxt, e2ap_RICactionLoad_Item* pvalue);
EXTERN int asn1Init_e2ap_RICactionLoad_Item (e2ap_RICactionLoad_Item* pvalue);
EXTERN void asn1Free_e2ap_RICactionLoad_Item (OSCTXT* pctxt, e2ap_RICactionLoad_Item* pvalue);
EXTERN void asn1Print_e2ap_RICactionLoad_Item (const char* name, const e2ap_RICactionLoad_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactionLoad_Item (const char* name, e2ap_RICactionLoad_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICactionLoad_Item (OSCTXT* pctxt, const char* name, const e2ap_RICactionLoad_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICactionLoad_Item (OSCTXT* pctxt, const e2ap_RICactionLoad_Item* pSrcValue, e2ap_RICactionLoad_Item* pDstValue);
// --- End of e2ap_RICactionLoad_Item.h ---

// --- Begin of e2ap_RICactionLoad_ItemIEs.h ---
/* e2ap_RICactionLoad_ItemIEs.h */

/*****************************************/
/*           RICactionLoad_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICactionLoad_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICactionLoad_ItemIEs_RICactionLoad_Item   
   

} e2ap_RICactionLoad_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICactionLoad_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICactionLoad_ItemIEs_TVALUE t;
      union {
         e2ap_RICactionLoad_Item * _e2apRICactionLoad_ItemIEs_RICactionLoad_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICactionLoad_ItemIEs;

EXTERN int  asn1PE_e2ap_RICactionLoad_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoad_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICactionLoad_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoad_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICactionLoad_ItemIEs (e2ap_RICactionLoad_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICactionLoad_ItemIEs (OSCTXT* pctxt, e2ap_RICactionLoad_ItemIEs* pvalue);

// --- End of e2ap_RICactionLoad_ItemIEs.h ---

// --- Begin of e2ap_RICactionLoad_List.h ---
/*****************************************/
/*           RICactionLoad_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICactionLoad_List;

EXTERN int asn1PE_e2ap_RICactionLoad_List (OSCTXT* pctxt, e2ap_RICactionLoad_List* pvalue);
EXTERN int asn1PD_e2ap_RICactionLoad_List (OSCTXT* pctxt, e2ap_RICactionLoad_List* ppvalue);
EXTERN void asn1Init_e2ap_RICactionLoad_List (e2ap_RICactionLoad_List* pvalue);
EXTERN void asn1Free_e2ap_RICactionLoad_List (OSCTXT* pctxt, e2ap_RICactionLoad_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICactionLoad_List (const char* name, e2ap_RICactionLoad_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICactionLoad_List (OSCTXT* pctxt, const e2ap_RICactionLoad_List* pSrcValue, e2ap_RICactionLoad_List* pDstValue);
EXTERN void asn1Print_e2ap_RICactionLoad_List (const char *name, const e2ap_RICactionLoad_List* pvalue);
// --- End of e2ap_RICactionLoad_List.h ---

// --- Begin of e2ap_RICsubscriptionLoad_ItemIE.h ---
/*****************************************/
/*           RICsubscriptionLoad_ItemIE                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionLoad_ItemIE {
   e2ap_RICrequestID ricRequestID;
   e2ap_RICloadInformation ricSubscriptionLoadInformation;
     OSBOOL m_ricSubscriptionLoadInformationPresent;   e2ap_RICactionLoad_List ricActionLoad_list;
     OSBOOL m_ricActionLoad_listPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionLoad_ItemIE;

EXTERN int asn1PE_e2ap_RICsubscriptionLoad_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_ItemIE* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionLoad_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_ItemIE* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionLoad_ItemIE (e2ap_RICsubscriptionLoad_ItemIE* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionLoad_ItemIE (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_ItemIE* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionLoad_ItemIE (const char* name, const e2ap_RICsubscriptionLoad_ItemIE* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionLoad_ItemIE (const char* name, e2ap_RICsubscriptionLoad_ItemIE* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionLoad_ItemIE (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionLoad_ItemIE* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionLoad_ItemIE (OSCTXT* pctxt, const e2ap_RICsubscriptionLoad_ItemIE* pSrcValue, e2ap_RICsubscriptionLoad_ItemIE* pDstValue);
// --- End of e2ap_RICsubscriptionLoad_ItemIE.h ---

// --- Begin of e2ap_RICsubscriptionLoad_ItemIEs.h ---
/* e2ap_RICsubscriptionLoad_ItemIEs.h */

/*****************************************/
/*           RICsubscriptionLoad_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionLoad_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICsubscriptionLoad_ItemIEs_RICsubscriptionLoad_ItemIE   
   

} e2ap_RICsubscriptionLoad_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICsubscriptionLoad_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionLoad_ItemIEs_TVALUE t;
      union {
         e2ap_RICsubscriptionLoad_ItemIE * _e2apRICsubscriptionLoad_ItemIEs_RICsubscriptionLoad_ItemIE;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICsubscriptionLoad_ItemIEs;

EXTERN int  asn1PE_e2ap_RICsubscriptionLoad_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICsubscriptionLoad_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionLoad_ItemIEs (e2ap_RICsubscriptionLoad_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionLoad_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_ItemIEs* pvalue);

// --- End of e2ap_RICsubscriptionLoad_ItemIEs.h ---

// --- Begin of e2ap_RICsubscriptionLoad_List.h ---
/*****************************************/
/*           RICsubscriptionLoad_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICsubscriptionLoad_List;

EXTERN int asn1PE_e2ap_RICsubscriptionLoad_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_List* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionLoad_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_List* ppvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionLoad_List (e2ap_RICsubscriptionLoad_List* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionLoad_List (OSCTXT* pctxt, e2ap_RICsubscriptionLoad_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionLoad_List (const char* name, e2ap_RICsubscriptionLoad_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICsubscriptionLoad_List (OSCTXT* pctxt, const e2ap_RICsubscriptionLoad_List* pSrcValue, e2ap_RICsubscriptionLoad_List* pDstValue);
EXTERN void asn1Print_e2ap_RICsubscriptionLoad_List (const char *name, const e2ap_RICsubscriptionLoad_List* pvalue);
// --- End of e2ap_RICsubscriptionLoad_List.h ---

// --- Begin of e2ap_RANfunctionLoad_Item.h ---
/*****************************************/
/*           RANfunctionLoad_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RANfunctionLoad_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_RICloadInformation ranFunctionLoadInformation;
     OSBOOL m_ranFunctionLoadInformationPresent;   e2ap_RICserviceLoadInformation ricServiceLoadInformation;
     OSBOOL m_ricServiceLoadInformationPresent;   e2ap_RICsubscriptionLoad_List ricSubscriptionLoad_list;
     OSBOOL m_ricSubscriptionLoad_listPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RANfunctionLoad_Item;

EXTERN int asn1PE_e2ap_RANfunctionLoad_Item (OSCTXT* pctxt, e2ap_RANfunctionLoad_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionLoad_Item (OSCTXT* pctxt, e2ap_RANfunctionLoad_Item* pvalue);
EXTERN int asn1Init_e2ap_RANfunctionLoad_Item (e2ap_RANfunctionLoad_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionLoad_Item (OSCTXT* pctxt, e2ap_RANfunctionLoad_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionLoad_Item (const char* name, const e2ap_RANfunctionLoad_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionLoad_Item (const char* name, e2ap_RANfunctionLoad_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionLoad_Item (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionLoad_Item* pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionLoad_Item (OSCTXT* pctxt, const e2ap_RANfunctionLoad_Item* pSrcValue, e2ap_RANfunctionLoad_Item* pDstValue);
// --- End of e2ap_RANfunctionLoad_Item.h ---

// --- Begin of e2ap_RANfunctionLoad_ItemIEs.h ---
/* e2ap_RANfunctionLoad_ItemIEs.h */

/*****************************************/
/*           RANfunctionLoad_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RANfunctionLoad_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RANfunctionLoad_ItemIEs_RANfunctionLoad_Item   
   

} e2ap_RANfunctionLoad_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RANfunctionLoad_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RANfunctionLoad_ItemIEs_TVALUE t;
      union {
         e2ap_RANfunctionLoad_Item * _e2apRANfunctionLoad_ItemIEs_RANfunctionLoad_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RANfunctionLoad_ItemIEs;

EXTERN int  asn1PE_e2ap_RANfunctionLoad_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoad_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RANfunctionLoad_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoad_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RANfunctionLoad_ItemIEs (e2ap_RANfunctionLoad_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionLoad_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionLoad_ItemIEs* pvalue);

// --- End of e2ap_RANfunctionLoad_ItemIEs.h ---

// --- Begin of e2ap_RANfunctionLoad_List.h ---
/*****************************************/
/*           RANfunctionLoad_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RANfunctionLoad_List;

EXTERN int asn1PE_e2ap_RANfunctionLoad_List (OSCTXT* pctxt, e2ap_RANfunctionLoad_List* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionLoad_List (OSCTXT* pctxt, e2ap_RANfunctionLoad_List* ppvalue);
EXTERN void asn1Init_e2ap_RANfunctionLoad_List (e2ap_RANfunctionLoad_List* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionLoad_List (OSCTXT* pctxt, e2ap_RANfunctionLoad_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionLoad_List (const char* name, e2ap_RANfunctionLoad_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RANfunctionLoad_List (OSCTXT* pctxt, const e2ap_RANfunctionLoad_List* pSrcValue, e2ap_RANfunctionLoad_List* pDstValue);
EXTERN void asn1Print_e2ap_RANfunctionLoad_List (const char *name, const e2ap_RANfunctionLoad_List* pvalue);
// --- End of e2ap_RANfunctionLoad_List.h ---

/****************************************************/
/* File .h missing: e2ap_RICserviceLoadUpdate_IEs.h */
/****************************************************/

// --- Begin of e2ap_RICserviceLoadUpdate.h ---
/*****************************************/
/*           RICserviceLoadUpdate                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICserviceLoadUpdate {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICserviceLoadUpdate;

EXTERN int asn1PE_e2ap_RICserviceLoadUpdate (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadUpdate (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadUpdate (e2ap_RICserviceLoadUpdate* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadUpdate (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate* pvalue);
EXTERN void asn1Print_e2ap_RICserviceLoadUpdate (const char* name, const e2ap_RICserviceLoadUpdate* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadUpdate (const char* name, e2ap_RICserviceLoadUpdate* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICserviceLoadUpdate (OSCTXT* pctxt, const char* name, const e2ap_RICserviceLoadUpdate* pvalue);
EXTERN int asn1Copy_e2ap_RICserviceLoadUpdate (OSCTXT* pctxt, const e2ap_RICserviceLoadUpdate* pSrcValue, e2ap_RICserviceLoadUpdate* pDstValue);
// --- End of e2ap_RICserviceLoadUpdate.h ---

// --- Begin of e2ap_RICserviceLoadUpdate_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICserviceLoadUpdate_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICserviceLoadUpdate*/

typedef OSRTDList e2ap_RICserviceLoadUpdate_protocolIEs;

EXTERN int asn1PE_e2ap_RICserviceLoadUpdate_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadUpdate_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadUpdate_protocolIEs (e2ap_RICserviceLoadUpdate_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadUpdate_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadUpdate_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICserviceLoadUpdate_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICserviceLoadUpdate_protocolIEs* pvalue);
// --- End of e2ap_RICserviceLoadUpdate_protocolIEs.h ---

// --- Begin of e2ap_RICserviceLoadUpdate_protocolIEs_element.h ---
/*****************************************/
/*    RICserviceLoadUpdate_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICserviceLoadUpdate*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICserviceLoadUpdate_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICserviceLoadUpdate_IEs_id_RICloadMeasurementID,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadUpdate_IEs_id_E2nodeLoadMeasurementID,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadUpdate_IEs_id_RANfunctionLoad_List,

   T_E2AP_PDU_Contents_e2ap_RICserviceLoadUpdate_IEs_id_Extended_RANNodeName_

}e2ap_RICserviceLoadUpdate_IEs_TVALUE;


typedef struct EXTERN e2ap_RICserviceLoadUpdate_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICserviceLoadUpdate_IEs_TVALUE t;
      union {
        /*
        *id: id-LoadMeasurementID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_LoadMeasurementID *_e2ap_RICserviceLoadUpdate_IEs_id_RICloadMeasurementID;


        /*
        *id: id-LoadMeasurementID
        *criticality: ignore
        *presence: MANDATORY
        */
        e2ap_LoadMeasurementID *_e2ap_RICserviceLoadUpdate_IEs_id_E2nodeLoadMeasurementID;


        /*
        *id: id-RANfunctionLoad-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RANfunctionLoad_List *_e2ap_RICserviceLoadUpdate_IEs_id_RANfunctionLoad_List;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICserviceLoadUpdate_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICserviceLoadUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICserviceLoadUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICserviceLoadUpdate_protocolIEs_element (e2ap_RICserviceLoadUpdate_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICserviceLoadUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceLoadUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceLoadUpdate_protocolIEs_element* pvalue);
// --- End of e2ap_RICserviceLoadUpdate_protocolIEs_element.h ---

#endif
