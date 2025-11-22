/*****************************************/
/*    E2connectionUpdate_protocolIEs_element     */
/*****************************************/
//message  -> tao emlement cho ban tin to nhat nhe

EXTERN int asn1PE_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue)
{
    int stat =0;

    /*encode id*/

    RTXCTXTPUSHELEMNAME(pctxt, "id");
        stat = asn1PE_e2ap_ProtocolIE_ID(pctxt, &pvalue->id);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*encode criticality*/
    RTXCTXTPUSHELEMNAME(pctxt, "criticality");
        stat = asn1PE_e2ap_Criticality(pctxt, &pvalue->criticality);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*encode value*/
    RTXCTXTPUSHELEMNAME(pctxt, "value");
        
    {
        OSCTXT lctxt;
        OSOCTET *pDynamicEncodeBuffer;
        ASN1OpenType openType;
        OSBOOL encoded = TRUE;

        openType.numocts = 0;
        openType.data =0;

        rtxCopyContext(&lctxt, pctxt);
        pctxt->pStream =0;

        stat = rtxInitContextBuffer(pctxt, 0, 0);
        if(stat!=0) return LOG_RTERR(pctxt, stat);

        switch(pvalue->value.t){
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-TransactionID");

                stat = asn1PE_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-E2connectionUpdateAdd");

                stat = asn1PE_e2ap_E2connectionUpdate_List (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-E2connectionUpdateRemove");

                stat = asn1PE_e2ap_E2connectionUpdateRemove_List (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "id-E2connectionUpdateModify");

                stat = asn1PE_e2ap_E2connectionUpdate_List (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_UNDEF_:
            {
                if(0!=pvalue->value.u.extElem1){
                    openType.numocts = pvalue->value.u.extElem1->numocts;
                    openType.data = pvalue->value.u.extElem1->data;
                } else {
                    /* No extension element to encode */
                }
                encoded = FALSE;
                break;
            }

            default:
                encoded = FALSE;
                stat = RTERR_INVOPT;
                break;
        } 

        if(encoded){
            openType.numocts = (OSUINT32)pe_GetMsgLen(pctxt);
            openType.data = pDynamicEncodeBuffer = pctxt -> buffer.data;
        }
        rtxCopyContext(pctxt, &lctxt);

        if(stat == 0) {
            stat = pe_OpenType (pctxt, openType.numocts, openType.data);
        }
    #if 0
        if(encoded){//dungnm23 check lai nhe
            rtxMemFreePtr(pctxt, pDynamicEncodeBuffer);
        }
    #endif

    }

    if(stat!=0) return LOG_RTERR(pctxt, stat);  
    RTXCTXTPOPELEMNAME(pctxt);
    return (stat);

}

EXTERN int  asn1PD_e2ap_E2connectionUpdate_protocolIEs_element (OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue){
    int stat =0;

    /*decode id*/
    RTXCTXTPUSHELEMNAME(pctxt, "id");
        stat = asn1PD_e2ap_ProtocolIE_ID(pctxt, &pvalue->id);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*decode criticality*/
    RTXCTXTPUSHELEMNAME(pctxt, "criticality");
        stat = asn1PD_e2ap_Criticality(pctxt, &pvalue->criticality);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*decode value*/
    RTXCTXTPUSHELEMNAME(pctxt, "value");

    {
        OSUINT32 openTypeLen;
        size_t bitStartOffset, bitLength;

        stat = pd_UnconsLength(pctxt, &openTypeLen);
        if(stat<0) return LOG_RTERR(pctxt, stat);
        else if(stat == RT_OK_FRAG){
            rtxErrAddStrParm(pctxt, "open type with fragment length");
            return LOG_RTERRNEW(pctxt, RTERR_NOTSUPP);
        }
        bitStartOffset = PU_GETCTXBITOFFSET(pctxt);
        bitLength = openTypeLen * 8;

        switch(pvalue->id){//dungnm23 check case lai nhe
        
            case ASN1V_e2ap_id_TransactionID:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID;
            RTXCTXTPUSHELEMNAME(pctxt, "id-TransactionID");
            pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID 
                = rtxMemAllocType(pctxt, e2ap_TransactionID);

            asn1Init_e2ap_TransactionID(pvalue->
                value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID);

            stat = asn1PD_e2ap_TransactionID (pctxt,
                (e2ap_TransactionID*)pvalue->value.
                u._e2ap_E2connectionUpdate_IEs_id_TransactionID);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_E2connectionUpdateAdd:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2connectionUpdateAdd");
            pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List 
                = rtxMemAllocType(pctxt, e2ap_E2connectionUpdate_List);

            asn1Init_e2ap_E2connectionUpdate_List(pvalue->
                value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);

            stat = asn1PD_e2ap_E2connectionUpdate_List (pctxt,
                (e2ap_E2connectionUpdate_List*)pvalue->value.
                u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_E2connectionUpdateRemove:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2connectionUpdateRemove");
            pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List 
                = rtxMemAllocType(pctxt, e2ap_E2connectionUpdateRemove_List);

            asn1Init_e2ap_E2connectionUpdateRemove_List(pvalue->
                value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List);

            stat = asn1PD_e2ap_E2connectionUpdateRemove_List (pctxt,
                (e2ap_E2connectionUpdateRemove_List*)pvalue->value.
                u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    
        
            case ASN1V_e2ap_id_E2connectionUpdateModify:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List;
            RTXCTXTPUSHELEMNAME(pctxt, "id-E2connectionUpdateModify");
            pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List 
                = rtxMemAllocType(pctxt, e2ap_E2connectionUpdate_List);

            asn1Init_e2ap_E2connectionUpdate_List(pvalue->
                value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);

            stat = asn1PD_e2ap_E2connectionUpdate_List (pctxt,
                (e2ap_E2connectionUpdate_List*)pvalue->value.
                u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
            if(stat!=0) return LOG_RTERR(pctxt, stat);
            RTXCTXTPOPELEMNAME(pctxt);
            break;
    

        default:
            pvalue->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_UNDEF_;
            pvalue->value.u.extElem1 = rtxMemAllocType(pctxt, ASN1OpenType);
            if(0==pvalue->value.u.extElem1){
                return LOG_RTERR(pctxt, RTERR_NOMEM);
            }

            {
                OSOCTET *pdata =(OSOCTET*) rtxMemAlloc(pctxt, openTypeLen);
                if(0==pdata){
                    return LOG_RTERR(pctxt, RTERR_NOMEM);
                }
                stat = rtxDecBitsToByteArray(pctxt, pdata, openTypeLen, openTypeLen*8);
                if(stat!=0){
                    rtxMemFreePtr(pctxt, pdata);
                    rtxMemFreePtr(pctxt, pvalue->value.u.extElem1);
                    return LOG_RTERR(pctxt, stat);
                }

                pvalue->value.u.extElem1->numocts = openTypeLen;
                pvalue->value.u.extElem1->data = pdata;
            }
            break;
    }
    {
    size_t bitEndOffset = PU_GETCTXBITOFFSET(pctxt);
    size_t bitsConsumed = bitEndOffset-bitStartOffset;
    if(bitsConsumed<bitLength){
        stat = pd_moveBitCursor(pctxt, (int)(bitLength - bitsConsumed));
    }
    else stat =(bitsConsumed > bitLength) ? ASN_E_INVLEN : 0;
    }}
    if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);
    return (stat);

}


int asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(e2ap_E2connectionUpdate_protocolIEs_element* pvalue)
{
    if(0==pvalue) return RTERR_NULLPTR;
    OSCRTLMEMSET (&pvalue->value, 0, sizeof(pvalue->value));
    return 0;
}


//-----> chuaw có template rtxFreeASN1OpenType
#if 0
void asn1Free_e2ap_E2connectionUpdate_protocolIEs_element(OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue)
{
    if(NULL==pvalue) return;
    switch(pvalue->value.t){
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID:
            // rtxFreeE2ap_TransactionID(pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID);

            if(pvalue->value.i._e2ap_E2connectionUpdate_IEs_id_TransactionID!=NULL){
            asn1Free_e2ap_TransactionID(pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID);
            pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List:
            // rtxFreeE2ap_E2connectionUpdate_List(pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);

            if(pvalue->value.i._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List!=NULL){
            asn1Free_e2ap_E2connectionUpdate_List(pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
            pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List:
            // rtxFreeE2ap_E2connectionUpdateRemove_List(pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List);

            if(pvalue->value.i._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List!=NULL){
            asn1Free_e2ap_E2connectionUpdateRemove_List(pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List);
            pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List:
            // rtxFreeE2ap_E2connectionUpdate_List(pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);

            if(pvalue->value.i._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List!=NULL){
            asn1Free_e2ap_E2connectionUpdate_List(pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
            rtxMemFreePtr(pctxt, (void*)pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
            pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List = NULL;
            }
            break;
        case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_UNDEF_:
            rtxFreeASN1OpenType(pvalue->value.u.extElem1);
            break;
        default:
            break;
    }
}

int asn1PrtToStr_e2ap_E2connectionUpdate_protocolIEs_element(OSCTXT* pctxt, e2ap_E2connectionUpdate_protocolIEs_element* pvalue)
{
    int stat =0;
    RTXCTXTPUSHELEMNAME(pctxt, "e2ap_E2connectionUpdate_protocolIEs_element");

    /*print id*/
    RTXCTXTPUSHELEMNAME(pctxt, "id");
        stat = asn1PrtToStr_e2ap_ProtocolIE_ID(pctxt, &pvalue->id);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*print criticality*/
    RTXCTXTPUSHELEMNAME(pctxt, "criticality");
        stat = asn1PrtToStr_e2ap_Criticality(pctxt, &pvalue->criticality);
        if(stat!=0) return LOG_RTERR(pctxt, stat);
    RTXCTXTPOPELEMNAME(pctxt);

    /*print value*/
    RTXCTXTPUSHELEMNAME(pctxt, "value");
        
        switch(pvalue->value.t){
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "TransactionID");

                stat = asn1PrtToStr_e2ap_TransactionID (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "E2connectionUpdate-List");

                stat = asn1PrtToStr_e2ap_E2connectionUpdate_List (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "E2connectionUpdateRemove-List");

                stat = asn1PrtToStr_e2ap_E2connectionUpdateRemove_List (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }
            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List:
            {
                RTXCTXTPUSHELEMNAME (pctxt, "E2connectionUpdate-List");

                stat = asn1PrtToStr_e2ap_E2connectionUpdate_List (pctxt, pvalue->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdate_List);
                if (stat != 0) return LOG_RTERR (pctxt, stat);

                RTXCTXTPOPELEMNAME (pctxt);
                break;
            }

            case T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_UNDEF_:
            {
                rtxPLogMsg(pctxt, "Extension element present - raw data not printed.\n");
                break;
            }

            default:
                stat = RTERR_INVOPT;
                return LOG_RTERR(pctxt, stat);
        }
    RTXCTXTPOPELEMNAME(pctxt);
    return (stat);
}
#endif