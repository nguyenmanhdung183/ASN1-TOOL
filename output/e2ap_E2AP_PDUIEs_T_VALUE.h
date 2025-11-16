/* e2ap_.h */
#ifndef _E2AP__H_
#define _E2AP__H_

#include "rtxsrc/rtxDList.h"
#include "e2ap_ProtocolIE_ID.h"
#include "e2ap_Criticality.h"
#include "e2ap_E2AP_PDUIEs_T_VALUE.h"

typedef struct e2ap__Element {
   e2ap_ProtocolIE_ID_t id;
   e2ap_Criticality_t criticality;
   e2ap_E2AP_PDUIEs_T_VALUE value;
} e2ap__Element;

typedef struct e2ap_ {
   OSRTDList elem;  /* list of e2ap__Element */
} e2ap_;

#endif