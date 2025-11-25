/*****************************************/
/*           TNLinformation                */
/*****************************************/
//seq normal



// Các nội dung cần thiết từ template seq_normal.h.j2

    // Nội dung của file .h cho primitive BIT STRING (SIZE(1..160,...))
    /* bitstring intergrate header file */
 //metadata.parsed.primitive_id == 2


//mau Transportlayeraddress xn bitstring (a..b,..)

typedef ASN1DynBitStr e2ap_TNLinformation_tnlAddress;

EXTERN int asn1PE_e2ap_TNLinformation_tnlAddress(OSCTXT* pctxt, e2ap_TNLinformation_tnlAddress value);
EXTERN int asn1PD_e2ap_TNLinformation_tnlAddress(OSCTXT* pctxt, e2ap_TNLinformation_tnlAddress* pvalue);
EXTERN int asn1PrtToStr_e2ap_TNLinformation_tnlAddress (const char* name, e2ap_TNLinformation_tnlAddress *pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_TNLinformation_tnlAddress (OSCTXT* pctxt, const char* name, const e2ap_TNLinformation_tnlAddress* pvalue);
EXTERN int asn1Copy_e2ap_TNLinformation_tnlAddress(OSCTXT* pctxt,const e2ap_TNLinformation_tnlAddress* pSrcValue,  e2ap_TNLinformation_tnlAddress* pDstValue);
EXTERN int asn1Init_e2ap_TNLinformation_tnlAddress(e2ap_TNLinformation_tnlAddress* pvalue);
EXTERN void asn1Free_e2ap_TNLinformation_tnlAddress(OSCTXT* pctxt, e2ap_TNLinformation_tnlAddress* pvalue);


    // Nội dung của file .h cho primitive BIT STRING (SIZE(16))
    /* bitstring intergrate header file */
 //metadata.parsed.primitive_id == 3

//mau NID ben xn  bitstring (n)
typedef struct e2ap_TNLinformation_tnlPort {
    OSUINT8 numbits;
    OSOCTET data[2];
} e2ap_TNLinformation_tnlPort;

EXTERN int asn1PE_e2ap_TNLinformation_tnlPort(OSCTXT* pctxt, e2ap_TNLinformation_tnlPort* pvalue);
EXTERN int asn1PD_e2ap_TNLinformation_tnlPort(OSCTXT* pctxt, e2ap_TNLinformation_tnlPort* pvalue);
EXTERN int asn1PrtToStr_e2ap_TNLinformation_tnlPort (const char* name, e2ap_TNLinformation_tnlPort* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_TNLinformation_tnlPort (OSCTXT* pctxt, const char* name, const e2ap_TNLinformation_tnlPort* pvalue);
EXTERN int asn1Copy_e2ap_TNLinformation_tnlPort(OSCTXT* pctxt,const e2ap_TNLinformation_tnlPort* pSrcValue,  e2ap_TNLinformation_tnlPort* pDstValue);
EXTERN int asn1Init_e2ap_TNLinformation_tnlPort(e2ap_TNLinformation_tnlPort* pvalue);




// Các phần còn lại của template seq_normal.h.j2


typedef struct EXTERN e2ap_TNLinformation {
      //primitive
   e2ap_TNLinformation_tnlAddress tnlAddress;
      //primitive
   e2ap_TNLinformation_tnlPort tnlPort;
   OSBOOL m_tnlPortPresent;
   OSRTDList extElem1;  /* Extension elements */
} e2ap_TNLinformation;

EXTERN int asn1PE_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue);
EXTERN int asn1PD_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue);
EXTERN int asn1Init_e2ap_TNLinformation (e2ap_TNLinformation* pvalue);
EXTERN void asn1Free_e2ap_TNLinformation (OSCTXT* pctxt, e2ap_TNLinformation* pvalue);
EXTERN void asn1Print_e2ap_TNLinformation (const char* name, const e2ap_TNLinformation* pvalue);
EXTERN int asn1PrtToStr_e2ap_TNLinformation (const char* name, e2ap_TNLinformation* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_TNLinformation (OSCTXT* pctxt, const char* name, const e2ap_TNLinformation* pvalue);
EXTERN int asn1Copy_e2ap_TNLinformation (OSCTXT* pctxt, const e2ap_TNLinformation* pSrcValue, e2ap_TNLinformation* pDstValue);