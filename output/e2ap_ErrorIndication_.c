/* e2ap_ErrorIndication_.c */
#include "e2ap_ErrorIndication_.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_ErrorIndication_ (OSCTXT* pctxt, e2ap_ErrorIndication_* pvalue)
{
   RTXCTXPUSHTYPENAME (pctxt, "ErrorIndication_");
   int stat = asn1PE_e2ap_ErrorIndication__protocolIEs_Container (pctxt, &pvalue->protocolIEs);
   RTXCTXPOPEXTNAME (pctxt);
   return (stat != 0) ? LOG_RTERR (pctxt, stat) : 0;
}

EXTERN int asn1PE_e2ap_ErrorIndication__protocolIEs_Container (OSCTXT* pctxt, const e2ap_ErrorIndication__protocolIEs_Container* pList)
{
   int i, stat;
   RTXCTXPUSHTYPENAME (pctxt, "ErrorIndication_-protocolIEs");

   stat = rtxEncLengthDeterminant (pctxt, pList->n);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   for (i = 0; i < pList->n; i++) {
      stat = asn1PE_e2ap_ProtocolIE_ID (pctxt, pList->elem[i].id);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      stat = asn1PE_e2ap_Criticality (pctxt, pList->elem[i].criticality);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      stat = rtxEncOpenTypeStart (pctxt);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      switch (pList->elem[i].id) {
         case ID_id_TransactionID:
            stat = asn1PE_e2ap_TransactionID (pctxt, &pList->elem[i].value.transactionID);
            break;
         case ID_id_:
            stat = asn1PE_e2ap_nan (pctxt, &pList->elem[i].value.nan);
            break;
         default:
            return LOG_RTERR (pctxt, RTERR_INVOPT);
      }
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      stat = rtxEncOpenTypeEnd (pctxt);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}