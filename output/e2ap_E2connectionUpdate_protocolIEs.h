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