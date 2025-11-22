
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

// --- Begin of e2ap_ListedRecordsOnly.h ---
/******************************************************/
/*                                                    */
/*    ListedRecordsOnly                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_true = 0
} e2ap_ListedRecordsOnly_Root;

typedef OSUINT32 e2ap_ListedRecordsOnly;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_ListedRecordsOnly (OSCTXT* pctxt, e2ap_ListedRecordsOnly value);
EXTERN int asn1PD_e2ap_ListedRecordsOnly (OSCTXT* pctxt, e2ap_ListedRecordsOnly* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_ListedRecordsOnly (const char* name, const e2ap_ListedRecordsOnly* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_ListedRecordsOnly (OSCTXT* pctxt, const char* name, const e2ap_ListedRecordsOnly* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_ListedRecordsOnly (const char* name,const e2ap_ListedRecordsOnly* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_ListedRecordsOnly_ENUMTAB[];
#define e2ap_ListedRecordsOnly_ENUMTABSIZE 1

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_ListedRecordsOnly_ToString (OSUINT32 value);
EXTERN int e2ap_ListedRecordsOnly_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_ListedRecordsOnly* pvalue);
EXTERN int e2ap_ListedRecordsOnly_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_ListedRecordsOnly* pvalue);
// --- End of e2ap_ListedRecordsOnly.h ---

// --- Begin of e2ap_RICsubscriptionAuditFlag.h ---
/*****************************************/
/*           RICsubscriptionAuditFlag                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionAuditFlag {
   e2ap_ListedRecordsOnly listedRecordsOnly;
     OSBOOL m_listedRecordsOnlyPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionAuditFlag;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditFlag (OSCTXT* pctxt, e2ap_RICsubscriptionAuditFlag* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditFlag (OSCTXT* pctxt, e2ap_RICsubscriptionAuditFlag* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAuditFlag (e2ap_RICsubscriptionAuditFlag* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditFlag (OSCTXT* pctxt, e2ap_RICsubscriptionAuditFlag* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionAuditFlag (const char* name, const e2ap_RICsubscriptionAuditFlag* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditFlag (const char* name, e2ap_RICsubscriptionAuditFlag* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionAuditFlag (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionAuditFlag* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionAuditFlag (OSCTXT* pctxt, const e2ap_RICsubscriptionAuditFlag* pSrcValue, e2ap_RICsubscriptionAuditFlag* pDstValue);
// --- End of e2ap_RICsubscriptionAuditFlag.h ---

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

// --- Begin of e2ap_RICsubscriptionAudit_Item.h ---
/*****************************************/
/*           RICsubscriptionAudit_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionAudit_Item {
   e2ap_RICrequestID ricRequestID;
   e2ap_RANfunctionID ranFunctionID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionAudit_Item;

EXTERN int asn1PE_e2ap_RICsubscriptionAudit_Item (OSCTXT* pctxt, e2ap_RICsubscriptionAudit_Item* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAudit_Item (OSCTXT* pctxt, e2ap_RICsubscriptionAudit_Item* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAudit_Item (e2ap_RICsubscriptionAudit_Item* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAudit_Item (OSCTXT* pctxt, e2ap_RICsubscriptionAudit_Item* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionAudit_Item (const char* name, const e2ap_RICsubscriptionAudit_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAudit_Item (const char* name, e2ap_RICsubscriptionAudit_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionAudit_Item (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionAudit_Item* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionAudit_Item (OSCTXT* pctxt, const e2ap_RICsubscriptionAudit_Item* pSrcValue, e2ap_RICsubscriptionAudit_Item* pDstValue);
// --- End of e2ap_RICsubscriptionAudit_Item.h ---

// --- Begin of e2ap_RICsubscriptionAudit_ItemIEs.h ---
/* e2ap_RICsubscriptionAudit_ItemIEs.h */

/*****************************************/
/*           RICsubscriptionAudit_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAudit_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RICsubscriptionAudit_ItemIEs_RICsubscriptionAudit_Item   
   

} e2ap_RICsubscriptionAudit_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RICsubscriptionAudit_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionAudit_ItemIEs_TVALUE t;
      union {
         e2ap_RICsubscriptionAudit_Item * _e2apRICsubscriptionAudit_ItemIEs_RICsubscriptionAudit_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RICsubscriptionAudit_ItemIEs;

EXTERN int  asn1PE_e2ap_RICsubscriptionAudit_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAudit_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RICsubscriptionAudit_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAudit_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionAudit_ItemIEs (e2ap_RICsubscriptionAudit_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAudit_ItemIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAudit_ItemIEs* pvalue);

// --- End of e2ap_RICsubscriptionAudit_ItemIEs.h ---

// --- Begin of e2ap_RICsubscriptionAuditList.h ---
/*****************************************/
/*           RICsubscriptionAuditList                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RICsubscriptionAuditList;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditList* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditList* ppvalue);
EXTERN void asn1Init_e2ap_RICsubscriptionAuditList (e2ap_RICsubscriptionAuditList* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditList (OSCTXT* pctxt, e2ap_RICsubscriptionAuditList* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditList (const char* name, e2ap_RICsubscriptionAuditList* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RICsubscriptionAuditList (OSCTXT* pctxt, const e2ap_RICsubscriptionAuditList* pSrcValue, e2ap_RICsubscriptionAuditList* pDstValue);
EXTERN void asn1Print_e2ap_RICsubscriptionAuditList (const char *name, const e2ap_RICsubscriptionAuditList* pvalue);
// --- End of e2ap_RICsubscriptionAuditList.h ---

/***********************************************************/
/* File .h missing: e2ap_RICsubscriptionAuditRequest_IEs.h */
/***********************************************************/

// --- Begin of e2ap_RICsubscriptionAuditRequest.h ---
/*****************************************/
/*           RICsubscriptionAuditRequest                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICsubscriptionAuditRequest {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICsubscriptionAuditRequest;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditRequest (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditRequest (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAuditRequest (e2ap_RICsubscriptionAuditRequest* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditRequest (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest* pvalue);
EXTERN void asn1Print_e2ap_RICsubscriptionAuditRequest (const char* name, const e2ap_RICsubscriptionAuditRequest* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditRequest (const char* name, e2ap_RICsubscriptionAuditRequest* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICsubscriptionAuditRequest (OSCTXT* pctxt, const char* name, const e2ap_RICsubscriptionAuditRequest* pvalue);
EXTERN int asn1Copy_e2ap_RICsubscriptionAuditRequest (OSCTXT* pctxt, const e2ap_RICsubscriptionAuditRequest* pSrcValue, e2ap_RICsubscriptionAuditRequest* pDstValue);
// --- End of e2ap_RICsubscriptionAuditRequest.h ---

// --- Begin of e2ap_RICsubscriptionAuditRequest_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICsubscriptionAuditRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICsubscriptionAuditRequest*/

typedef OSRTDList e2ap_RICsubscriptionAuditRequest_protocolIEs;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAuditRequest_protocolIEs (e2ap_RICsubscriptionAuditRequest_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICsubscriptionAuditRequest_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICsubscriptionAuditRequest_protocolIEs* pvalue);
// --- End of e2ap_RICsubscriptionAuditRequest_protocolIEs.h ---

// --- Begin of e2ap_RICsubscriptionAuditRequest_protocolIEs_element.h ---
/*****************************************/
/*    RICsubscriptionAuditRequest_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICsubscriptionAuditRequest*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditRequest_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditRequest_IEs_id_RICrequestID,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditRequest_IEs_id_RICsubscriptionAuditFlag,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditRequest_IEs_id_RICsubscriptionAuditList,

   T_E2AP_PDU_Contents_e2ap_RICsubscriptionAuditRequest_IEs_id_Extended_RANNodeName_

}e2ap_RICsubscriptionAuditRequest_IEs_TVALUE;


typedef struct EXTERN e2ap_RICsubscriptionAuditRequest_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICsubscriptionAuditRequest_IEs_TVALUE t;
      union {
        /*
        *id: id-RICrequestID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_RICrequestID *_e2ap_RICsubscriptionAuditRequest_IEs_id_RICrequestID;


        /*
        *id: id-RICsubscriptionAuditFlag
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RICsubscriptionAuditFlag *_e2ap_RICsubscriptionAuditRequest_IEs_id_RICsubscriptionAuditFlag;


        /*
        *id: id-RICsubscriptionAuditList
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RICsubscriptionAuditList *_e2ap_RICsubscriptionAuditRequest_IEs_id_RICsubscriptionAuditList;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICsubscriptionAuditRequest_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICsubscriptionAuditRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAuditRequest_protocolIEs_element (e2ap_RICsubscriptionAuditRequest_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditRequest_protocolIEs_element (OSCTXT* pctxt, e2ap_RICsubscriptionAuditRequest_protocolIEs_element* pvalue);
// --- End of e2ap_RICsubscriptionAuditRequest_protocolIEs_element.h ---

#endif
