/* e2ap_RANfunction_ItemIEs.h */
//IE
/* Forward declaration for the enum */
typedef enum {
   T_E2AP_PDU_Contents_RANfunction_ItemIEs_UNDEF,
   T_E2AP_PDU_Contents_RANfunction_ItemIEs_
} T_E2AP_PDU_Contents_RANfunction_ItemIEs;

/* The actual IE container */
typedef struct EXTERN e2ap_RANfunction_ItemIEs {
   ASN1OpenType* extElem1;
   OSSIZE        extElem1_n;
   union {
      e2ap_RANfunction-Item u_RANfunction_ItemIEs_;
   } value;
} e2ap_RANfunction_ItemIEs;

EXTERN int  asn1PE_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue);
EXTERN int  asn1PD_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue);
EXTERN void asn1Init_e2ap_RANfunction_ItemIEs (e2ap_RANfunction_ItemIEs* pvalue);
EXTERN void asn1Free_e2ap_RANfunction_ItemIEs (OSCTXT* pctxt, e2ap_RANfunction_ItemIEs* pvalue);
