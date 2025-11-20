
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

/**************************************/
/* File .h missing: e2ap_tnlAddress.h */
/**************************************/

/***********************************/
/* File .h missing: e2ap_tnlPort.h */
/***********************************/

// --- Begin of e2ap_TNLinformation.h ---
/*****************************************/
/*           TNLinformation                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_TNLinformation {
   ASN1BitStr32 tnlAddress;
   ASN1BitStr32 tnlPort;
     OSBOOL m_tnlPortPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_TNLinformation;

EXTERN int asn1PE_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue);
EXTERN int asn1PD_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue);
EXTERN int asn1Init_e2ap_TNLinformation (e2ap_TNLinformation* pvalue);
EXTERN void asn1Free_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue);
EXTERN void asn1Print_e2ap_TNLinformation (const char* name, const e2ap_TNLinformation* pvalue);
EXTERN int asn1PrtToStr_e2ap_TNLinformation (const char* name, e2ap_TNLinformation* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_TNLinformation (OSCTXT* pctxt, const char* name, const e2ap_TNLinformation* pvalue);
EXTERN int asn1Copy_e2ap_TNLinformation (OSCTXT* pctxt, const e2ap_TNLinformation* pSrcValue, e2ap_TNLinformation* pDstValue);
// --- End of e2ap_TNLinformation.h ---

// --- Begin of e2ap_TNLusage.h ---
/******************************************************/
/*                                                    */
/*    TNLusage                             */
/*                                                    */
/*******************************************************/
//enumerated

typedef enum {
    e2ap_ric_service = 0,
    e2ap_support_function = 1,
    e2ap_both = 2
} e2ap_TNLusage_Root;

typedef OSUINT32 e2ap_TNLusage;

/* Encode / Decode */
EXTERN int asn1PE_e2ap_TNLusage (OSCTXT* pctxt, e2ap_TNLusage value);
EXTERN int asn1PD_e2ap_TNLusage (OSCTXT* pctxt, e2ap_TNLusage* pvalue);

/* Print helpers */
EXTERN void asn1Print_e2ap_TNLusage (const char* name, const e2ap_TNLusage* pvalue);

/* Convert to stream (pretty print to stream) */
EXTERN int asn1PrtToStrm_e2ap_TNLusage (OSCTXT* pctxt, const char* name, const e2ap_TNLusage* pvalue);

/* Convert to string (write into user buffer) */
EXTERN int asn1PrtToStr_e2ap_TNLusage (const char* name,const e2ap_TNLusage* pvalue, char* buffer,OSSIZE bufSize);
/* Enumeration table */
EXTERN extern const OSEnumItem e2ap_TNLusage_ENUMTAB[];
#define e2ap_TNLusage_ENUMTABSIZE 3

/* Enum <-> String conversion */
EXTERN const OSUTF8CHAR* e2ap_TNLusage_ToString (OSUINT32 value);
EXTERN int e2ap_TNLusage_ToEnum (OSCTXT* pctxt, const OSUTF8CHAR* value,e2ap_TNLusage* pvalue);
EXTERN int e2ap_TNLusage_ToEnum2 (OSCTXT* pctxt, const OSUTF8CHAR* value, OSSIZE valueLen,e2ap_TNLusage* pvalue);
// --- End of e2ap_TNLusage.h ---

// --- Begin of e2ap_E2connectionUpdate_Item.h ---
/*****************************************/
/*           E2connectionUpdate_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2connectionUpdate_Item {
   e2ap_TNLinformation tnlInformation;
   e2ap_TNLusage tnlUsage;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2connectionUpdate_Item;

EXTERN int asn1PE_e2ap_E2connectionUpdate_Item (OSCTXT* pctxt, e2ap_E2connectionUpdate_Item* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdate_Item (OSCTXT* pctxt, e2ap_E2connectionUpdate_Item* pvalue);
EXTERN int asn1Init_e2ap_E2connectionUpdate_Item (e2ap_E2connectionUpdate_Item* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdate_Item (OSCTXT* pctxt, e2ap_E2connectionUpdate_Item* pvalue);
EXTERN void asn1Print_e2ap_E2connectionUpdate_Item (const char* name, const e2ap_E2connectionUpdate_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionUpdate_Item (const char* name, e2ap_E2connectionUpdate_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2connectionUpdate_Item (OSCTXT* pctxt, const char* name, const e2ap_E2connectionUpdate_Item* pvalue);
EXTERN int asn1Copy_e2ap_E2connectionUpdate_Item (OSCTXT* pctxt, const e2ap_E2connectionUpdate_Item* pSrcValue, e2ap_E2connectionUpdate_Item* pDstValue);
// --- End of e2ap_E2connectionUpdate_Item.h ---

/******************************************************/
/* File .h missing: e2ap_E2connectionUpdate_ItemIEs.h */
/******************************************************/

// --- Begin of e2ap_E2connectionUpdate_List.h ---
/*****************************************/
/*           E2connectionUpdate_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_E2connectionUpdate_List;

EXTERN int asn1PE_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List** ppvalue);
EXTERN void asn1Init_e2ap_E2connectionUpdate_List (e2ap_E2connectionUpdate_List* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdate_List (OSCTXT* pctxt, e2ap_E2connectionUpdate_List* pvalue);
// --- End of e2ap_E2connectionUpdate_List.h ---

// --- Begin of e2ap_E2connectionUpdateRemove_Item.h ---
/*****************************************/
/*           E2connectionUpdateRemove_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2connectionUpdateRemove_Item {
   e2ap_TNLinformation tnlInformation;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2connectionUpdateRemove_Item;

EXTERN int asn1PE_e2ap_E2connectionUpdateRemove_Item (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_Item* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdateRemove_Item (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_Item* pvalue);
EXTERN int asn1Init_e2ap_E2connectionUpdateRemove_Item (e2ap_E2connectionUpdateRemove_Item* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdateRemove_Item (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_Item* pvalue);
EXTERN void asn1Print_e2ap_E2connectionUpdateRemove_Item (const char* name, const e2ap_E2connectionUpdateRemove_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionUpdateRemove_Item (const char* name, e2ap_E2connectionUpdateRemove_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2connectionUpdateRemove_Item (OSCTXT* pctxt, const char* name, const e2ap_E2connectionUpdateRemove_Item* pvalue);
EXTERN int asn1Copy_e2ap_E2connectionUpdateRemove_Item (OSCTXT* pctxt, const e2ap_E2connectionUpdateRemove_Item* pSrcValue, e2ap_E2connectionUpdateRemove_Item* pDstValue);
// --- End of e2ap_E2connectionUpdateRemove_Item.h ---

/************************************************************/
/* File .h missing: e2ap_E2connectionUpdateRemove_ItemIEs.h */
/************************************************************/

// --- Begin of e2ap_E2connectionUpdateRemove_List.h ---
/*****************************************/
/*           E2connectionUpdateRemove_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_E2connectionUpdateRemove_List;

EXTERN int asn1PE_e2ap_E2connectionUpdateRemove_List (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_List* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdateRemove_List (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_List** ppvalue);
EXTERN void asn1Init_e2ap_E2connectionUpdateRemove_List (e2ap_E2connectionUpdateRemove_List* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdateRemove_List (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove_List* pvalue);
// --- End of e2ap_E2connectionUpdateRemove_List.h ---

/**************************************************/
/* File .h missing: e2ap_E2connectionUpdate_IEs.h */
/**************************************************/

// --- Begin of e2ap_E2connectionUpdate.h ---
/*****************************************/
/*           E2connectionUpdate                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_E2connectionUpdate {
   e2ap_ProtocolIE-Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_E2connectionUpdate;

EXTERN int asn1PE_e2ap_E2connectionUpdate (OSCTXT* pctxt, e2ap_E2connectionUpdate* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdate (OSCTXT* pctxt, e2ap_E2connectionUpdate* pvalue);
EXTERN int asn1Init_e2ap_E2connectionUpdate (e2ap_E2connectionUpdate* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdate (OSCTXT* pctxt, e2ap_E2connectionUpdate* pvalue);
EXTERN void asn1Print_e2ap_E2connectionUpdate (const char* name, const e2ap_E2connectionUpdate* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionUpdate (const char* name, e2ap_E2connectionUpdate* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_E2connectionUpdate (OSCTXT* pctxt, const char* name, const e2ap_E2connectionUpdate* pvalue);
EXTERN int asn1Copy_e2ap_E2connectionUpdate (OSCTXT* pctxt, const e2ap_E2connectionUpdate* pSrcValue, e2ap_E2connectionUpdate* pDstValue);
// --- End of e2ap_E2connectionUpdate.h ---

// --- Begin of e2ap_E2connectionUpdateRemove_Item_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    E2connectionUpdateRemove-Item_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from E2connectionUpdateRemove-Item*/

typedef OSRTDList e2ap_E2connectionUpdateRemove-Item_protocolIEs;

EXTERN int asn1PE_e2ap_E2connectionUpdateRemove-Item_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove-Item_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdateRemove-Item_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove-Item_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_E2connectionUpdateRemove-Item_protocolIEs (e2ap_E2connectionUpdateRemove-Item_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdateRemove-Item_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove-Item_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionUpdateRemove-Item_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdateRemove-Item_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apE2connectionUpdateRemove-Item_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_E2connectionUpdateRemove-Item_protocolIEs* pvalue);
// --- End of e2ap_E2connectionUpdateRemove_Item_protocolIEs.h ---

// --- Begin of e2ap_E2connectionUpdate_Item_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    E2connectionUpdate-Item_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from E2connectionUpdate-Item*/

typedef OSRTDList e2ap_E2connectionUpdate-Item_protocolIEs;

EXTERN int asn1PE_e2ap_E2connectionUpdate-Item_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate-Item_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdate-Item_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate-Item_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_E2connectionUpdate-Item_protocolIEs (e2ap_E2connectionUpdate-Item_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdate-Item_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate-Item_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionUpdate-Item_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate-Item_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apE2connectionUpdate-Item_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_E2connectionUpdate-Item_protocolIEs* pvalue);
// --- End of e2ap_E2connectionUpdate_Item_protocolIEs.h ---

// --- Begin of e2ap_E2connectionUpdate_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    E2connectionUpdate_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from E2connectionUpdate*/

typedef OSRTDList e2ap_E2connectionUpdate_protocolIEs;

EXTERN int asn1PE_e2ap_E2connectionUpdate_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdate_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_E2connectionUpdate_protocolIEs (e2ap_E2connectionUpdate_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdate_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionUpdate_protocolIEs (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apE2connectionUpdate_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_E2connectionUpdate_protocolIEs* pvalue);
// --- End of e2ap_E2connectionUpdate_protocolIEs.h ---

// --- Begin of e2ap_E2connectionUpdate_protocolIEs_element.h ---
/*****************************************/
/*    E2connectionUpdate_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from E2connectionUpdate*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID ,
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List ,
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List ,
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List ,
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_id_E2connectionUpdate_Item ,
   T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_id_E2connectionUpdateRemove_Item 
}


typedef struct EXTERN e2ap_E2connectionUpdate_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_E2connectionUpdate_IEs_TVALUE t;
      union {
        /*
        *id: id-TransactionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_TransactionID *_e2apE2connectionUpdate_id_TransactionID,

        /*
        *id: id-E2connectionUpdate-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_E2connectionUpdate_List *_e2apE2connectionUpdate_id_E2connectionUpdate_List,

        /*
        *id: id-E2connectionUpdateRemove-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_E2connectionUpdateRemove_List *_e2apE2connectionUpdate_id_E2connectionUpdateRemove_List,

        /*
        *id: id-E2connectionUpdate-List
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_E2connectionUpdate_List *_e2apE2connectionUpdate_id_E2connectionUpdate_List,

        /*
        *id: id-E2connectionUpdate-Item
        *criticality: ignore
        *presence: MANDATORY
        */
        e2ap_E2connectionUpdate_Item *_e2apE2connectionUpdate_id_E2connectionUpdate_Item,

        /*
        *id: id-E2connectionUpdateRemove-Item
        *criticality: ignore
        *presence: MANDATORY
        */
        e2ap_E2connectionUpdateRemove_Item *_e2apE2connectionUpdate_id_E2connectionUpdateRemove_Item


        ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_E2connectionUpdate_protocolIEs_element;


EXTERN int asn1PE_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_E2connectionUpdate_protocolIEs_element (e2ap_E2connectionUpdate_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue);
// --- End of e2ap_E2connectionUpdate_protocolIEs_element.h ---

#endif
