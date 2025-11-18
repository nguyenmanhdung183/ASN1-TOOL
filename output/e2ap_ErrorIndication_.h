/* e2ap_ErrorIndication_.h */
#ifndef _E2AP_ERRORINDICATION__H_
#define _E2AP_ERRORINDICATION__H_

#include "e2ap_TransactionID.h"
#include "e2ap_nan.h"

/* T_VALUE Union */
typedef union e2ap_ErrorIndication_IEs_T_VALUE {
   T_E2AP_PDU_Contents_e2ap__transactionID;
   T_E2AP_PDU_Contents_e2ap__nan;
} e2ap_ErrorIndication_IEs_TVALUE;

/* IE Struct */
typedef struct e2ap_ErrorIndication_IEs {
   e2ap_ProtocolIE_ID id;
   e2ap_Criticality criticality;
   e2ap_ErrorIndication_IEs_T_VALUE value;
} e2ap_ErrorIndication_IEs;

/* Container */
typedef struct e2ap_ErrorIndication__protocolIEs_Container {
   e2ap_ErrorIndication_IEs* elem;
   OSUINT16 n;
} e2ap_ErrorIndication__protocolIEs_Container;

/* Message */
typedef struct e2ap_ErrorIndication_ {
   e2ap_ErrorIndication__protocolIEs_Container protocolIEs;
} e2ap_ErrorIndication_;

EXTERN int asn1PE_e2ap_ErrorIndication_ (OSCTXT* pctxt, e2ap_ErrorIndication_* pvalue);
EXTERN int asn1PD_e2ap_ErrorIndication_ (OSCTXT* pctxt, e2ap_ErrorIndication_* pvalue);
EXTERN int asn1Init_e2ap_ErrorIndication_ (e2ap_ErrorIndication_* pvalue);
EXTERN void asn1Free_e2ap_ErrorIndication_ (OSCTXT* pctxt, e2ap_ErrorIndication_* pvalue);

#endif