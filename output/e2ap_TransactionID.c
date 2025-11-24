/*****************************************/
/*           TransactionID                */
/*****************************************/

//6 mau octet string



// mau integer size(a...b) mau la procedurecode
EXTERN int asn1PE_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID value){
    int stat = 0;
    RTXCTCXTPUSHTYPENAME (pctxt, "TransactionID");
    stat = pe_ConsUnsigned (pctxt, value, -1, -1);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
EXTERN int asn1PD_e2ap_TransactionID (OSCTXT* pctxt, e2ap_TransactionID* pvalue){
    int stat = 0;
    RTXCTCXTPUSHTYPENAME (pctxt, "TransactionID");
    if(pctxt->buffer.aligned){
        int stat2 = PD_BYTE_ALIGN(pctxt);
        if(stat2 != 0) return LOG_RTERR (pctxt, stat2);
    }
    stat = rtxDecBitsToByte(pctxt, pvalue, 0);
    if (stat != 0) return LOG_RTERR (pctxt, stat);
    RTXCTXTPOPTYPENAME (pctxt);
    return stat;
}
//EXTERN int asn1Print_e2ap_TransactionID (const char* name, const e2ap_TransactionID* pvalue);
//EXTERN int asn1PrtToStr_e2ap_TransactionID (const char* name, e2ap_TransactionID* pvalue, char* buffer, OSSIZE bufSize);
//EXTERN int asn1PrtToStrm_e2ap_TransactionID (OSCTXT* pctxt, const char* name, const e2ap_TransactionID* pvalue);



