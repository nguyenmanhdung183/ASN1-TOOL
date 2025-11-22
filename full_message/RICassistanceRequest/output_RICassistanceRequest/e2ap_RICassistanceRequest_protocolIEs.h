/******************************************************/
/*                                                    */
/*    RICassistanceRequest_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from RICassistanceRequest*/

typedef OSRTDList e2ap_RICassistanceRequest_protocolIEs;

EXTERN int asn1PE_e2ap_RICassistanceRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICassistanceRequest_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_RICassistanceRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICassistanceRequest_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_RICassistanceRequest_protocolIEs (e2ap_RICassistanceRequest_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_RICassistanceRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICassistanceRequest_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_RICassistanceRequest_protocolIEs (OSCTXT* pctxt, e2ap_RICassistanceRequest_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apRICassistanceRequest_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_RICassistanceRequest_protocolIEs* pvalue);