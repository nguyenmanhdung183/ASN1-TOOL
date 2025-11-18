
//seq normal

typedef struct e2ap_E2nodeComponentConfigAdditionAck_Item {
   e2ap_E2nodeComponentInterfaceType e2nodeComponentInterfaceType;
   e2ap_E2nodeComponentID e2nodeComponentID;
   e2ap_E2nodeComponentConfigurationAck e2nodeComponentConfigurationAck;
ASN1OpenType extElem1; OSBOOL extElem1Present;} e2ap_E2nodeComponentConfigAdditionAck_Item;

EXTERN int asn1PE_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue);
EXTERN int asn1PD_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue);
EXTERN void asn1Init_e2ap_E2nodeComponentConfigAdditionAck_Item (e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue);
EXTERN void asn1Free_e2ap_E2nodeComponentConfigAdditionAck_Item (OSCTXT* pctxt, e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue);
EXTERN void asn1Print_e2ap_E2nodeComponentConfigAdditionAck_Item (const char* name, const e2ap_E2nodeComponentConfigAdditionAck_Item* pvalue);