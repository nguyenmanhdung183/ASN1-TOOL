/* e2ap_InitiatingMessageIEs.h */
#ifndef _E2AP_INITIATINGMESSAGEIES_H_
#define _E2AP_INITIATINGMESSAGEIES_H_

#include "rtxsrc/rtxDList.h"
#include "e2ap_ProtocolIE_ID.h"
#include "e2ap_Criticality.h"
#include "e2ap_InitiatingMessageIEs_T_VALUE.h"

typedef struct e2ap_InitiatingMessageIEs_Element {
   e2ap_ProtocolIE_ID_t id;
   e2ap_Criticality_t criticality;
   e2ap_InitiatingMessageIEs_T_VALUE value;
} e2ap_InitiatingMessageIEs_Element;

typedef struct e2ap_InitiatingMessageIEs {
   OSRTDList elem;  /* list of e2ap_InitiatingMessageIEs_Element */
} e2ap_InitiatingMessageIEs;

#endif