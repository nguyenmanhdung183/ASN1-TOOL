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