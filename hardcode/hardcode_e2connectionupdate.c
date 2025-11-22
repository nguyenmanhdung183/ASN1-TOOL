#include <stdio.h>
#include "output_main.h"
#include "hardcode_e2setupreq.h"

xnap_return_et e2ap_encode_connectionupdate(
    UInt8 *p_asn_msg,
    UInt16 *p_asn_msg_len)
{
    xnap_return_et retVal = XNAP_FAILURE;
    OSCTXT asn1_ctx;
    e2ap_PDU e2ap_pdu;
    OSRTDListNode *p_node = GNB_NULL;
    e2ap_E2connectionUpdate *p_e2connectionupdate = XNAP_P_NULL;
    e2ap_E2connectionUpdate_protocolIEs_element *p_e2ap_protocolIE_elem = XNAP_P_NULL;

    /* Initialize ASN.1 context */
    if (rtInitContext(&asn1_ctx) != 0)
    {
        XNAP_TRACE(XNAP_ERROR, "ASN.1 context initialization failed" __FUNCTION__);
        XNAP_UT_TRACE_ENTER();
        return retVal;
    }

    do
    {
        XNAP_MEMSET(&e2ap_pdu, 0, sizeof(e2ap_PDU));
        e2ap_pdu.t = T_e2ap_PDU_initiatingMessage;
        e2ap_pdu.u.initiatingMessage = rtxMemAllocType(&asn1_ctx, e2ap_InitiatingMessage);
        if (e2ap_pdu.u.initiatingMessage == XNAP_P_NULL)
        {
            XNAP_TRACE(XNAP_ERROR, "Memory allocation failed for e2ap_InitiatingMessage" __FUNCTION__);
            break;
        }
        asn1Init_e2ap_InitiatingMessage(e2ap_pdu.u.initiatingMessage);
        e2ap_pdu.u.initiatingMessage->procedureCode = ASN1V_e2ap_id_E2connectionUpdate;
        e2ap_pdu.u.initiatingMessage->criticality = e2ap_reject;
        XNAP_TRACE(XNAP_DETAILED, "Memory allocation successful for e2ap_InitiatingMessage" __FUNCTION__);

        /*set the initing msg type to e2 connection update*/
        e2ap_pdu.u.initiatingMessage->value.t = T_E2AP_PDU_Descriptions_initiatingMessage_e2ap_E2connectionUpdate; //----> fix
        p_e2connectionupdate = rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate);
        if (XNAP_P_NULL == p_e2connectionupdate)
        {
            XNAP_TRACE(XNAP_ERROR, "Memory allocation failed for e2ap_E2connectionUpdate" __FUNCTION__);
            break;
        }
        else
        {
            XNAP_TRACE(XNAP_DETAILED, "Memory allocation successful for e2ap_E2connectionUpdate" __FUNCTION__);
        }

        asn1Init_e2ap_E2connectionUpdate(p_e2connectionupdate);
        e2ap_pdu.u.initiatingMessage->value.u._e2ap_E2connectionUpdate = p_e2connectionupdate; // tự thêm ở code

        /*encode transaction id*/
        {
            rtxDListAllocNode(&asn1_ctx,
                              e2ap_E2connectionUpdate_protocolIEs_element,
                              &p_node,
                              &p_e2ap_protocolIE_elem);
            if (p_node == GNB_NULL)
            {
                XNAP_TRACE(XNAP_ERROR, "Memory allocation failed for e2ap_E2connectionUpdate_protocolIEs_element" __FUNCTION__);
                break;
            }

            asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_e2ap_protocolIE_elem);
            /*fill the type of protocol ie elememt*/
            p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_TransactionID;
            p_e2ap_protocolIE_elem->criticality = e2ap_reject;
            p_e2ap_protocolIE_elem->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID;
            p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID = 0;
            rtxDListAppendNode(&p_e2connectionupdate->protocolIEs, p_node);
            XNAP_TRACE(XNAP_DETAILED, "Memory allocation successful for e2ap_E2connectionUpdate_protocolIEs_element - TransactionID" __FUNCTION__);
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
        } /* end encode transaction id*/

        /* encode E2connectionUpdateAdd  */
        {
            rtxDListAllocNode(&asn1_ctx,
                              e2ap_E2connectionUpdate_protocolIEs_element,
                              &p_node,
                              &p_e2ap_protocolIE_elem);

            if (p_node == XNAP_P_NULL)
            {
                XNAP_TRACE(XNAP_ERROR, "Memory allocation failed for e2ap_E2connectionUpdate_protocolIEs_element" __FUNCTION__);
                break;
            }
            asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_e2ap_protocolIE_elem);
            /*fill the type of Protocol IE element*/
            p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_E2connectionUpdateAdd; //------>dungnm23
            p_e2ap_protocolIE_elem->criticality = e2ap_reject;
            p_e2ap_protocolIE_elem->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd; //-->
            p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd = rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate_List);
            if (XNAP_P_NULL == p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd)
            {
                XNAP_TRACE(XNAP_ERROR, "Memory allocation failed for e2ap_E2connectionUpdate_List" __FUNCTION__);
                break;
            }
            asn1Init_e2ap_E2connectionUpdate_List(
                p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd);

            /*----------*/
            if (XNAP_FAILURE == e2ap_compose_E2connectionUpdateAdd_List(
                                    &asn1_ctx,
                                    p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd))
            {
                XNAP_TRACE(XNAP_ERROR,
                           "E2connectionUpdateAdd composition failed" __FUNCTION__);
                rtFreeContext(&asn1_ctx);
                XNAP_UT_TRACE_EXIT();
                return XNAP_FAILURE;
            }
            else
            {
                XNAP_TRACE(XNAP_DETAILED,
                           "E2connectionUpdateAdd composition successful" __FUNCTION__);
            }
            rtxDListAppendNode(&p_e2connectionupdate->protocolIEs, p_node);
            XNAP_TRACE(XNAP_DETAILED, "Memory allocation successful for e2ap_E2connectionUpdate_protocolIEs_element - E2connectionUpdateAdd" __FUNCTION__);
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);

        } /* end encode E2connectionUpdateAdd  */

        /*encode E2connectionUpdateRemove*/

        //=======================
        /*ASN ENCODE MESSAGE*/
        if (RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg, XNAP_MAX_ASN1_BUF_LEN, TRUE))
        {
            XNAP_TRACE(XNAP_ERROR, "pu_setBuffer failed" __FUNCTION__);
            break;
        }
        if (0 != asn1PE_e2ap_PDU(&asn1_ctx, &e2ap_pdu))
        {
            XNAP_TRACE(XNAP_ERROR, "ASN.1 encoding failed" __FUNCTION__);
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);

            SInt8 buff[500];
            rtxErrGetTextBuf(&asn1_ctx, buff, 500);
            XNAP_TRACE(XNAP_ERROR, "BUFFER[%s]", (SInt8 *)buff, buff);
            ASN_ERROR_PRINT(&asn1_ctx);
            break;
        }
        else
        {
            XNAP_TRACE(XNAP_INFO, "ASN.1 encoding e2 connection update successful");
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
            retVal = XNAP_SUCCESS;
        }

    } while (0);
    rtFreeContext(&asn1_ctx);
    XNAP_UT_TRACE_EXIT();
    return retVal;
}

xnap_return_et e2ap_compose_E2connectionUpdateAdd_List(
    OSCTXT *p_asn1_ctx,
    e2ap_E2connectionUpdate_List *p_e2connectionupdate_list)
{
    xnap_return_et retVal = XNAP_FAILURE;
    e2ap_E2connectionUpdate_ItemIEs *p_e2connectionupdate_item_IEs = XNAP_P_NULL;
    OSRTDListNode *p_node_connectionupdate_item_ies = XNAP_P_NULL;
    UInt16 t_count = XNAP_NULL;

    for (t_count = 0; t_count < 1; t_count++)
    {
        rtxDListAllocNodeAndData(p_asn1_ctx,
                                 e2ap_E2connectionUpdate_ItemIEs,
                                 &p_node_connectionupdate_item_ies,
                                 &p_e2connectionupdate_item_IEs);
        if (p_node_connectionupdate_item_ies == XNAP_P_NULL)
        {
            XNAP_TRACE(XNAP_ERROR, "Memory allocation failed for e2ap_E2connectionUpdate_ItemIEs" __FUNCTION__);
            break;
        }
        asn1Init_e2ap_E2connectionUpdate_ItemIEs(p_e2connectionupdate_item_IEs);
        /*fill the type of E2connectionUpdate Item IEs*/
        p_e2connectionupdate_item_IEs->id = ASN1V_e2ap_id_E2connectionUpdate_Item; ///===>dungnm23
        p_e2connectionupdate_item_IEs->criticality = e2ap_reject;
        p_e2connectionupdate_item_IEs->value.t = T_E2AP_PDU_Contents_E2connectionUpdate_ItemIEs_E2connectionUpdate_Item;
        p_e2connectionupdate_item_IEs->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item = rtxMemAllocType(p_asn1_ctx, e2ap_E2connectionUpdate_Item);
        if (XNAP_P_NULL == p_e2connectionupdate_item_IEs->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item)
        {
            XNAP_TRACE(XNAP_ERROR, "Memory allocation failed for e2ap_E2connectionUpdate_Item" __FUNCTION__);
            break;
        }

        asn1Init_e2ap_E2connectionUpdate_Item(
            p_e2connectionupdate_item_IEs->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item);
        /*----------*/
        if (XNAP_FAILURE == e2ap_compose_E2connectionUpdateItem(
                                p_asn1_ctx,
                                p_e2connectionupdate_item_IEs->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item))
        {
            XNAP_TRACE(XNAP_ERROR,
                       "E2connectionUpdate Item filling failed" __FUNCTION__);
            rtFreeContext(p_asn1_ctx);
            XNAP_UT_TRACE_EXIT();
            return XNAP_FAILURE;
        }
        else
        {
            XNAP_TRACE(XNAP_DETAILED,
                       "E2connectionUpdate Item filling successful" __FUNCTION__);
        }
        rtxDListAppendNode(p_e2connectionupdate_list, p_node_connectionupdate_item_ies);
    }
    retVal = XNAP_SUCCESS;
    XNAP_UT_TRACE_EXIT();
    return retVal;
}

xnap_return_et e2ap_compose_E2connectionUpdateItem(
    OSCTXT *p_asn1_ctx,
    e2ap_E2connectionUpdate_Item *p_e2connectionupdate_item)
{
    xnap_return_et retVal = XNAP_FAILURE;
    OSRTDListNode *p_node = GNB_NULL;

    // encode tnl information -> sequence
    {
        // p_e2connectionupdate_item->tnlInformation.tnlAddress; -> bit string
        // p_e2connectionupdate_item->tnlInformation.tnlPort; -> bit string



    }
    // encode tnl usage -> enum
    {
        // p_e2connectionupdate_item->tnlUsage;

    }

    retval = NR_SUCCESS;
    return retVal;
}