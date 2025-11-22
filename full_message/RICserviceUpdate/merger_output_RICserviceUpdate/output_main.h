
#ifndef OUTPUT_MAIN_H
#define OUTPUT_MAIN_H

// --- Begin of doc/header.h ---
//======================E2AP.h========================//
typedef pd_BitString32 pd_BitString32;
typedef pe_BitString32 pe_BitString32;
typedef asn1PrtToStr_ASN1BitStr32 rtPrintToStringBitStrBraceText;
typedef //asn1Free_ASN1BitStr32 

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

// --- Begin of e2ap_RANfunctionDefinition.h ---
/*****************************************/
/*           RANfunctionDefinition                */
/*****************************************/
//octet string


typedef OSDynOctStr e2ap_RANfunctionDefinition;

EXTERN int asn1PE_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition** ppvalue);
EXTERN void asn1Print_e2ap_RANfunctionDefinition (const char* name, const e2ap_RANfunctionDefinition* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionDefinition (const char* name, e2ap_RANfunctionDefinition* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionDefinition (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionDefinition* pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionDefinition (OSCTXT* pctxt, const e2ap_RANfunctionDefinition* pSrcValue, e2ap_RANfunctionDefinition* pDstValue);
EXTERN int asn1Init_e2ap_RANfunctionDefinition (e2ap_RANfunctionDefinition* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionDefinition (OSCTXT* pctxt, e2ap_RANfunctionDefinition* pvalue);
// --- End of e2ap_RANfunctionDefinition.h ---

// --- Begin of e2ap_RANfunctionRevision.h ---
/*****************************************/
/*        RANfunctionRevision         */
/*****************************************/
//interger no ext


typedef OSUINT16 e2ap_RANfunctionRevision;

EXTERN int asn1PE_e2ap_RANfunctionRevision (OSCTXT* pctxt, e2ap_RANfunctionRevision value);
EXTERN int asn1PD_e2ap_RANfunctionRevision (OSCTXT* pctxt, e2ap_RANfunctionRevision* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionRevision (const char* name, const e2ap_RANfunctionRevision* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionRevision (const char* name, e2ap_RANfunctionRevision* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionRevision (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionRevision* pvalue);
// --- End of e2ap_RANfunctionRevision.h ---

/*******************************************/
/* File .h missing: e2ap_PrintableString.h */
/*******************************************/

// --- Begin of e2ap_RANfunctionOID.h ---
/* e2ap_RANfunctionOID.h */

//printable string
/*****************************************/
/*           RANfunctionOID                */
/*****************************************/


typedef const char* e2ap_RANfunctionOID;

EXTERN int asn1PE_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID value);
EXTERN int asn1PD_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID* ppvalue);
EXTERN void asn1Print_e2ap_RANfunctionOID (const char* name, e2ap_RANfunctionOID pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionOID (const char* name, e2ap_RANfunctionOID pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionOID (OSCTXT* pctxt, const char* name, e2ap_RANfunctionOID pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID pSrcValue, e2ap_RANfunctionOID* pDstValue);
EXTERN void asn1Free_e2ap_RANfunctionOID (OSCTXT* pctxt, e2ap_RANfunctionOID pvalue);
// --- End of e2ap_RANfunctionOID.h ---

// --- Begin of e2ap_RANfunction_Item.h ---
/*****************************************/
/*           RANfunction_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RANfunction_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_RANfunctionDefinition ranFunctionDefinition;
   e2ap_RANfunctionRevision ranFunctionRevision;
   e2ap_RANfunctionOID ranFunctionOID;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RANfunction_Item;

EXTERN int asn1PE_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN int asn1Init_e2ap_RANfunction_Item (e2ap_RANfunction_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunction_Item (OSCTXT* pctxt, e2ap_RANfunction_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunction_Item (const char* name, const e2ap_RANfunction_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunction_Item (const char* name, e2ap_RANfunction_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunction_Item (OSCTXT* pctxt, const char* name, const e2ap_RANfunction_Item* pvalue);
EXTERN int asn1Copy_e2ap_RANfunction_Item (OSCTXT* pctxt, const e2ap_RANfunction_Item* pSrcValue, e2ap_RANfunction_Item* pDstValue);
// --- End of e2ap_RANfunction_Item.h ---

// --- Begin of e2ap_RANfunction_ItemIEs.h ---
/* e2ap_RANfunction_ItemIEs.h */

/*****************************************/
/*           RANfunction_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RANfunction_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RANfunction_ItemIEs_RANfunction_Item   
   

} e2ap_RANfunction_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RANfunction_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RANfunction_ItemIEs_TVALUE t;
      union {
         e2ap_RANfunction_Item * _e2apRANfunction_ItemIEs_RANfunction_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RANfunction_ItemIEs;

EXTERN int  asn1PE_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RANfunction_ItemIEs (e2ap_RANfunction_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue);

// --- End of e2ap_RANfunction_ItemIEs.h ---

// --- Begin of e2ap_RANfunctions_List.h ---
/*****************************************/
/*           RANfunctions_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RANfunctions_List;

EXTERN int asn1PE_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List* pvalue);
EXTERN int asn1PD_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List* ppvalue);
EXTERN void asn1Init_e2ap_RANfunctions_List (e2ap_RANfunctions_List* pvalue);
EXTERN void asn1Free_e2ap_RANfunctions_List (OSCTXT* pctxt, e2ap_RANfunctions_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctions_List (const char* name, e2ap_RANfunctions_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RANfunctions_List (OSCTXT* pctxt, const e2ap_RANfunctions_List* pSrcValue, e2ap_RANfunctions_List* pDstValue);
EXTERN void asn1Print_e2ap_RANfunctions_List (const char *name, const e2ap_RANfunctions_List* pvalue);
// --- End of e2ap_RANfunctions_List.h ---

// --- Begin of e2ap_RANfunctionID_Item.h ---
/*****************************************/
/*           RANfunctionID_Item                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RANfunctionID_Item {
   e2ap_RANfunctionID ranFunctionID;
   e2ap_RANfunctionRevision ranFunctionRevision;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RANfunctionID_Item;

EXTERN int asn1PE_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue);
EXTERN int asn1Init_e2ap_RANfunctionID_Item (e2ap_RANfunctionID_Item* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionID_Item (OSCTXT* pctxt, e2ap_RANfunctionID_Item* pvalue);
EXTERN void asn1Print_e2ap_RANfunctionID_Item (const char* name, const e2ap_RANfunctionID_Item* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionID_Item (const char* name, e2ap_RANfunctionID_Item* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RANfunctionID_Item (OSCTXT* pctxt, const char* name, const e2ap_RANfunctionID_Item* pvalue);
EXTERN int asn1Copy_e2ap_RANfunctionID_Item (OSCTXT* pctxt, const e2ap_RANfunctionID_Item* pSrcValue, e2ap_RANfunctionID_Item* pDstValue);
// --- End of e2ap_RANfunctionID_Item.h ---

// --- Begin of e2ap_RANfunctionID_ItemIEs.h ---
/* e2ap_RANfunctionID_ItemIEs.h */

/*****************************************/
/*           RANfunctionID_ItemIEs               */
/*****************************************/
//IE


typedef enum {
   T_E2AP_PDU_Contents_e2ap_RANfunctionID_ItemIEs_UNDEF_,

   T_E2AP_PDU_Contents_RANfunctionID_ItemIEs_RANfunctionID_Item   
   

} e2ap_RANfunctionID_ItemIEs_TVALUE;

/* The actual IE container */
typedef struct EXTERN e2ap_RANfunctionID_ItemIEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RANfunctionID_ItemIEs_TVALUE t;
      union {
         e2ap_RANfunctionID_Item * _e2apRANfunctionID_ItemIEs_RANfunctionID_Item;


         ASN1OpenType* extElem1;  /* extension */
      } u;
   }value
} e2ap_RANfunctionID_ItemIEs;

EXTERN int  asn1PE_e2ap_RANfunctionID_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionID_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RANfunctionID_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionID_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RANfunctionID_ItemIEs (e2ap_RANfunctionID_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionID_ItemIEs (OSCTXT* pctxt, e2ap_RANfunctionID_ItemIEs* pvalue);

// --- End of e2ap_RANfunctionID_ItemIEs.h ---

// --- Begin of e2ap_RANfunctionsID_List.h ---
/*****************************************/
/*           RANfunctionsID_List                */
/*****************************************/
//seq_of_single_container


/*List of ... ITEM*/
typedef OSRTDList e2ap_RANfunctionsID_List;

EXTERN int asn1PE_e2ap_RANfunctionsID_List (OSCTXT* pctxt, e2ap_RANfunctionsID_List* pvalue);
EXTERN int asn1PD_e2ap_RANfunctionsID_List (OSCTXT* pctxt, e2ap_RANfunctionsID_List* ppvalue);
EXTERN void asn1Init_e2ap_RANfunctionsID_List (e2ap_RANfunctionsID_List* pvalue);
EXTERN void asn1Free_e2ap_RANfunctionsID_List (OSCTXT* pctxt, e2ap_RANfunctionsID_List* pvalue);
EXTERN int asn1PrtToStr_e2ap_RANfunctionsID_List (const char* name, e2ap_RANfunctionsID_List* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1Copy_e2ap_RANfunctionsID_List (OSCTXT* pctxt, const e2ap_RANfunctionsID_List* pSrcValue, e2ap_RANfunctionsID_List* pDstValue);
EXTERN void asn1Print_e2ap_RANfunctionsID_List (const char *name, const e2ap_RANfunctionsID_List* pvalue);
// --- End of e2ap_RANfunctionsID_List.h ---

/************************************************/
/* File .h missing: e2ap_RICserviceUpdate_IEs.h */
/************************************************/

// --- Begin of e2ap_RICserviceUpdate.h ---
/*****************************************/
/*           RICserviceUpdate                */
/*****************************************/
//seq normal


typedef struct EXTERN e2ap_RICserviceUpdate {
   e2ap_ProtocolIE_Container protocolIEs;

   OSRTDList extElem1;  /* Extension elements */
} e2ap_RICserviceUpdate;

EXTERN int asn1PE_e2ap_RICserviceUpdate (OSCTXT* pctxt, e2ap_RICserviceUpdate* pvalue);
EXTERN int asn1PD_e2ap_RICserviceUpdate (OSCTXT* pctxt, e2ap_RICserviceUpdate* pvalue);
EXTERN int asn1Init_e2ap_RICserviceUpdate (e2ap_RICserviceUpdate* pvalue);
EXTERN void asn1Free_e2ap_RICserviceUpdate (OSCTXT* pctxt, e2ap_RICserviceUpdate* pvalue);
EXTERN void asn1Print_e2ap_RICserviceUpdate (const char* name, const e2ap_RICserviceUpdate* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceUpdate (const char* name, e2ap_RICserviceUpdate* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_RICserviceUpdate (OSCTXT* pctxt, const char* name, const e2ap_RICserviceUpdate* pvalue);
EXTERN int asn1Copy_e2ap_RICserviceUpdate (OSCTXT* pctxt, const e2ap_RICserviceUpdate* pSrcValue, e2ap_RICserviceUpdate* pDstValue);
// --- End of e2ap_RICserviceUpdate.h ---

// --- Begin of e2ap_RICserviceUpdate_protocolIEs.h ---
/******************************************************/
/*                                                    */
/*    RICserviceUpdate_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICserviceUpdate*/

typedef OSRTDList e2ap_RICserviceUpdate_protocolIEs;

EXTERN int asn1PE_e2ap_RICserviceUpdate_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICserviceUpdate_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICserviceUpdate_protocolIEs (e2ap_RICserviceUpdate_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICserviceUpdate_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceUpdate_protocolIEs (OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICserviceUpdate_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICserviceUpdate_protocolIEs* pvalue);
// --- End of e2ap_RICserviceUpdate_protocolIEs.h ---

// --- Begin of e2ap_RICserviceUpdate_protocolIEs_element.h ---
/*****************************************/
/*    RICserviceUpdate_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe
/*type was extract from RICserviceUpdate*/


typedef enum{
   T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_UNDEF_,
   T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_TransactionID,

   T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctionsAdded,

   T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctionsModified,

   T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_RANfunctionsDeleted,

   T_E2AP_PDU_Contents_e2ap_RICserviceUpdate_IEs_id_Extended_RANNodeName_

}e2ap_RICserviceUpdate_IEs_TVALUE;


typedef struct EXTERN e2ap_RICserviceUpdate_protocolIEs_element {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   struct{
      e2ap_RICserviceUpdate_IEs_TVALUE t;
      union {
        /*
        *id: id-TransactionID
        *criticality: reject
        *presence: MANDATORY
        */
        e2ap_TransactionID *_e2ap_RICserviceUpdate_IEs_id_TransactionID;


        /*
        *id: id-RANfunctions-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RANfunctions_List *_e2ap_RICserviceUpdate_IEs_id_RANfunctionsAdded;


        /*
        *id: id-RANfunctions-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RANfunctions_List *_e2ap_RICserviceUpdate_IEs_id_RANfunctionsModified;


        /*
        *id: id-RANfunctionsID-List
        *criticality: reject
        *presence: OPTIONAL
        */
        e2ap_RANfunctionsID_List *_e2ap_RICserviceUpdate_IEs_id_RANfunctionsDeleted;



        ASN1OpenType* extElem1;  /* extension */
      } u;
   } value;
} e2ap_RICserviceUpdate_protocolIEs_element;


EXTERN int asn1PE_e2ap_RICserviceUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PD_e2ap_RICserviceUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs_element* pvalue);
EXTERN int asn1Init_e2ap_RICserviceUpdate_protocolIEs_element (e2ap_RICserviceUpdate_protocolIEs_element* pvalue);
EXTERN void asn1Free_e2ap_RICserviceUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs_element* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICserviceUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_RICserviceUpdate_protocolIEs_element* pvalue);
// --- End of e2ap_RICserviceUpdate_protocolIEs_element.h ---

#endif
