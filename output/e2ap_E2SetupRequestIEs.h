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