/*****************************************/
/*           NGENB_DU_ID                */
/*****************************************/

//6 mau octet string



// mau integer size(a...b) mau la procedurecode
EXTERN int asn1PE_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID value){
    int stat = 0;
    RTXCTCXTPUSHTYPENAME (pctxt, "NGENB-DU-ID");
    stat = pe_ConsUnsigned (pctxt, value, 0, 68719476735);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
EXTERN int asn1PD_e2ap_NGENB_DU_ID (OSCTXT* pctxt, e2ap_NGENB_DU_ID* pvalue){
    int stat = 0;
    RTXCTCXTPUSHTYPENAME (pctxt, "NGENB-DU-ID");
    if(pctxt->buffer.aligned){
        int stat2 = PD_BYTE_ALIGN(pctxt);
        if(stat2 != 0) return LOG_RTERR (pctxt, stat2);
    }
    stat = rtxDecBitsToByte(pctxt, pvalue, 0);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
//EXTERN int asn1Print_e2ap_NGENB_DU_ID (const char* name, const e2ap_NGENB_DU_ID* pvalue);
//EXTERN int asn1PrtToStr_e2ap_NGENB_DU_ID (const char* name, e2ap_NGENB_DU_ID* pvalue, char* buffer, OSSIZE bufSize);
//EXTERN int asn1PrtToStrm_e2ap_NGENB_DU_ID (OSCTXT* pctxt, const char* name, const e2ap_NGENB_DU_ID* pvalue);



