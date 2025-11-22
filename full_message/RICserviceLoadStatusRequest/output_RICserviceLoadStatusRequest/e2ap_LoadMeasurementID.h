/*****************************************/
/*           LoadMeasurementID                */
/*****************************************/
//interger with ext


typedef OSUINT16 e2ap_LoadMeasurementID;

EXTERN int asn1PE_e2ap_LoadMeasurementID (OSCTXT* pctxt, e2ap_LoadMeasurementID value);
EXTERN int asn1PD_e2ap_LoadMeasurementID (OSCTXT* pctxt, e2ap_LoadMeasurementID* pvalue);
EXTERN void asn1Print_e2ap_LoadMeasurementID (const char* name, const e2ap_LoadMeasurementID* pvalue);
EXTERN int asn1PrtToStr_e2ap_LoadMeasurementID (const char* name, e2ap_LoadMeasurementID* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_LoadMeasurementID (OSCTXT* pctxt, const char* name, const e2ap_LoadMeasurementID* pvalue);