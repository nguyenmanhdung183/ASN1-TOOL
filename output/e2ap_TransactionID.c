/*****************************************/
/*           TransactionID                */
/*****************************************/

//5 mau octet string




//mau 5 integer size(a .. b..) mau la nrfreqencyband
EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value){
    int stat =0;
    OSBOOL extbit = FALSE;
    RTXCTCXTPUSHTYPENAME (pctxt, "TransactionID");
    if(value>0 && value<=255){
        extbit = 0;
    }
    else extbit =1;
    stat = rtxEncBit (pctxt, extbit);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    if(extbit){
        stat = pe_UnconsUnsigned (pctxt, value);
        if(stat != 0) return LOG_RTERR (pctxt, stat);
    }
    else{
        stat = pe_ConsUnsigned (pctxt, value, 0, 255);
        if (stat != 0) return LOG_RTERR (pctxt, stat);
    }
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
EXTERN int asn1PD_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID* pvalue){
    int stat =0;
    OSBOOL extbit = FALSE;
    RTXCTCXTPUSHTYPENAME (pctxt, "TransactionID");
    /*extensiobit*/
    stat = DECBIT (pctxt, &extbit);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    if(extbit==0){
        stat = pd_ConsUnsigned (pctxt, pvalue, 0, 255);
        if (stat != 0) return LOG_RTERR (pctxt, stat);
    }else{
        stat = pd_UnconsUnsigned (pctxt, pvalue);
        if (stat != 0) return LOG_RTERR (pctxt, stat);
    }
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
//EXTERN int asn1Print_e2ap_TransactionID (const char* name, const e2ap_TransactionID* pvalue);
//EXTERN int asn1PrtToStr_e2ap_TransactionID (const char* name, e2ap_TransactionID* pvalue, char* buffer, OSSIZE bufSize);
//EXTERN int asn1PrtToStrm_e2ap_TransactionID (OSCTXT* pctxt, const char* name, const e2ap_TransactionID* pvalue);

