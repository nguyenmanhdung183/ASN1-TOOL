/******************************************************/
/*                                                    */
/*    RICsubscriptionAuditResponse_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICsubscriptionAuditResponse*/

typedef OSRTDList e2ap_RICsubscriptionAuditResponse_protocolIEs;

EXTERN int asn1PE_e2ap_RICsubscriptionAuditResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICsubscriptionAuditResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICsubscriptionAuditResponse_protocolIEs (e2ap_RICsubscriptionAuditResponse_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICsubscriptionAuditResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICsubscriptionAuditResponse_protocolIEs (OSCTXT* pctxt, e2ap_RICsubscriptionAuditResponse_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICsubscriptionAuditResponse_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICsubscriptionAuditResponse_protocolIEs* pvalue);