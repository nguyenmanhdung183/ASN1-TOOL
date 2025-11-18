
//seq normal

typedef struct e2ap_E2nodeComponentConfigurationAck {
   e2ap_updateOutcome updateOutcome;
   e2ap_failure failure;
   e2ap_Cause failureCause;
OSBOOL m_failureCausePresent;ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_E2nodeComponentConfigurationAck;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigurationAck (e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigurationAck (OSCTXT* pctxt, e2ap_E2nodeComponentConfigurationAck* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigurationAck (const char* name, const e2ap_E2nodeComponentConfigurationAck* pvalue);