/******************************************************/
/*                                                    */
/*    ErrorIndication_protocolIEs                      */
/*                                                    */
/******************************************************/
//ie big msg

/*type was extract from ErrorIndication*/

typedef OSRTDList e2ap_ErrorIndication_protocolIEs;

EXTERN int asn1PE_e2ap_ErrorIndication_protocolIEs (OSCTXT* pctxt, e2ap_ErrorIndication_protocolIEs* pvalue);
EXTERN int asn1PD_e2ap_ErrorIndication_protocolIEs (OSCTXT* pctxt, e2ap_ErrorIndication_protocolIEs* pvalue);
EXTERN int asn1Init_e2ap_ErrorIndication_protocolIEs (e2ap_ErrorIndication_protocolIEs* pvalue);
EXTERN void asn1Free_e2ap_ErrorIndication_protocolIEs (OSCTXT* pctxt, e2ap_ErrorIndication_protocolIEs* pvalue);
EXTERN int asn1PrtToStr_e2ap_ErrorIndication_protocolIEs (OSCTXT* pctxt, e2ap_ErrorIndication_protocolIEs* pvalue, char*buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2apErrorIndication_protocolIEs (OSCTXT* pctxt, const char * name, const e2ap_ErrorIndication_protocolIEs* pvalue);