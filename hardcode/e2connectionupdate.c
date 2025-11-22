#include"output_main.h"
xnap_return_et e2ap_encode_e2connection_update(
    UInt8 *p_asn_msg,
    UInt16 *p_asn_msg_len)
{
    xnap_return_et retVal = XNAP_FAILURE;
    OSCTXT asn1_ctx;
    e2ap_E2AP_PDU e2ap_pdu;
    OSRTDListNode *p_node = XNAP_P_NULL;

    e2ap_E2connectionUpdate *p_E2ConnectionUpdate = XNAP_P_NULL;
    e2ap_E2connectionUpdate_protocolIEs_element *p_e2ap_protocolIE_elem = XNAP_P_NULL;

    /* Init ASN1 context */
    if (0 != rtInitContext(&asn1_ctx))
    {
        XNAP_TRACE(XNAP_ERROR, "%s: ASN context initialization failed.",
                   __FUNCTION__);
        XNAP_UT_TRACE_ENTER();
        return retVal;
    }

    do
    {
        XNAP_MEMSET(&e2ap_pdu, 0, sizeof(e2ap_E2AP_PDU));

        /**************************************************************************
         *                   Fill E2AP PDU
         **************************************************************************/

        e2ap_pdu.t = T_e2ap_E2AP_PDU_initiatingMessage;

        XNAP_TRACE(XNAP_DETAILED, "Quangdv26, Alloc e2ap_E2connectionUpdate");

        e2ap_pdu.u.initiatingMessage =
            rtxMemAllocType(&asn1_ctx, e2ap_InitiatingMessage);

        if (XNAP_P_NULL == e2ap_pdu.u.initiatingMessage)
        {
            XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed.", __FUNCTION__);
            break;
        }

        asn1Init_e2ap_InitiatingMessage(e2ap_pdu.u.initiatingMessage);

        e2ap_pdu.u.initiatingMessage->procedureCode = ASN1V_e2ap_id_E2connectionUpdate;
        e2ap_pdu.u.initiatingMessage->criticality = e2ap_reject;

        XNAP_TRACE(XNAP_DETAILED,
                   "Quangdv26, Alloc e2ap_E2connectionUpdate part 2");

        e2ap_pdu.u.initiatingMessage->value.t =
            T_E2AP_PDU_Descriptions_e2ap_E2AP_ELEMENTARY_PROCEDURES_e2connectionUpdate;

        p_E2ConnectionUpdate =
            rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate);

        if (XNAP_P_NULL == p_E2ConnectionUpdate)
        {
            XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed.", __FUNCTION__);
            break;
        }
        else
        {
            XNAP_TRACE(XNAP_DETAILED,
                       "Mem Alloc successful for e2ap_E2connectionUpdate");
        }

        asn1Init_e2ap_E2connectionUpdate(p_E2ConnectionUpdate);

        e2ap_pdu.u.initiatingMessage->value.u._e2connectionUpdate =
            p_E2ConnectionUpdate;

        /**************************************************************************
         *                          IE 1: TransactionID
         **************************************************************************/

        {
            rtxDListAllocNodeAndData(&asn1_ctx,
                                     e2ap_E2connectionUpdate_protocolIEs_element,
                                     &p_node,
                                     &p_e2ap_protocolIE_elem);

            if (XNAP_P_NULL == p_node)
            {
                XNAP_TRACE(XNAP_ERROR,
                           "%s: ASN malloc failed(TransactionID IE).",
                           __FUNCTION__);
                break;
            }

            asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(
                p_e2ap_protocolIE_elem);

            p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_TransactionID;
            p_e2ap_protocolIE_elem->criticality = e2ap_reject;
            p_e2ap_protocolIE_elem->value.t =
                T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID;

            /* Hardcode transaction ID */
            p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID =
                rtxMemAllocType(&asn1_ctx, e2ap_TransactionID);

            *(p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID) = 7;

            rtxDListAppendNode(&p_E2ConnectionUpdate->protocolIEs, p_node);

            XNAP_TRACE(XNAP_DETAILED,
                       "Quangdv26, Add IE TransactionID");
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
        }


        /**************************************************************************
         *                  IE 2: E2connectionUpdateAdd List
         **************************************************************************/

        {
            rtxDListAllocNodeAndData(&asn1_ctx,
                                     e2ap_E2connectionUpdate_protocolIEs_element,
                                     &p_node,
                                     &p_e2ap_protocolIE_elem);

            if (XNAP_P_NULL == p_node)
            {
                XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed(UpdateAdd).",
                           __FUNCTION__);
                break;
            }

            asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(
                p_e2ap_protocolIE_elem);

            p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_E2connectionUpdateAdd;
            p_e2ap_protocolIE_elem->criticality = e2ap_reject;
            p_e2ap_protocolIE_elem->value.t =
                T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd;

            p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd =
                rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate_List);

            if (XNAP_P_NULL ==
                p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd)
            {
                XNAP_TRACE(XNAP_ERROR,
                           "%s: ASN malloc failed(UpdateAdd list alloc).",
                           __FUNCTION__);
                break;
            }

            asn1Init_e2ap_E2connectionUpdate_List(
                p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd);

            /**************** Add 1 item ****************/
            {
                OSRTDListNode *p_node_item = XNAP_P_NULL;
                e2ap_E2connectionUpdate_ItemIEs *p_item_ie = XNAP_P_NULL;

                rtxDListAllocNodeAndData(&asn1_ctx,
                                         e2ap_E2connectionUpdate_ItemIEs,
                                         &p_node_item,
                                         &p_item_ie);

                if (XNAP_P_NULL == p_node_item)
                {
                    XNAP_TRACE(XNAP_ERROR,
                               "%s: ASN malloc failed(UpdateAdd item).",
                               __FUNCTION__);
                    break;
                }

                asn1Init_e2ap_E2connectionUpdate_ItemIEs(p_item_ie);

                p_item_ie->id = ASN1V_e2ap_id_E2connectionUpdate_Item;
                p_item_ie->criticality = e2ap_ignore;
                p_item_ie->value.t =
                    T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_id_E2connectionUpdate_Item;

                p_item_ie->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item =
                    rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate_Item);

                if (XNAP_P_NULL ==
                    p_item_ie->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item)
                {
                    XNAP_TRACE(XNAP_ERROR,
                               "%s: ASN malloc failed(UpdateAdd item2).",
                               __FUNCTION__);
                    break;
                }

                asn1Init_e2ap_E2connectionUpdate_Item(
                    p_item_ie->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item);

                e2ap_E2connectionUpdate_Item *p_item =
                    p_item_ie->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item;

                /* TNLinformation */
                asn1Init_e2ap_TNLinformation(&p_item->tnlInformation);

                p_item->tnlInformation.tnlAddress = 0xAABBCCDD;
                p_item->tnlInformation.tnlPort = 38472;

                /* TNLusage */
                p_item->tnlUsage = e2ap_ric_service;

                rtxDListAppendNode(
                    p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd,
                    p_node_item);

                XNAP_TRACE(XNAP_DETAILED,
                           "Quangdv26, Add E2connectionUpdateAdd Item OK");
            }

            rtxDListAppendNode(&p_E2ConnectionUpdate->protocolIEs, p_node);
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
        }


        /**************************************************************************
         *                  IE 3: E2connectionUpdateRemove List
         **************************************************************************/

        {
            rtxDListAllocNodeAndData(&asn1_ctx,
                                     e2ap_E2connectionUpdate_protocolIEs_element,
                                     &p_node,
                                     &p_e2ap_protocolIE_elem);

            if (XNAP_P_NULL == p_node)
            {
                XNAP_TRACE(XNAP_ERROR,
                           "%s: ASN malloc failed(RemoveList).",
                           __FUNCTION__);
                break;
            }

            asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(
                p_e2ap_protocolIE_elem);

            p_e2ap_protocolIE_elem->id =
                ASN1V_e2ap_id_E2connectionUpdateRemove;
            p_e2ap_protocolIE_elem->criticality = e2ap_reject;
            p_e2ap_protocolIE_elem->value.t =
                T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove;

            p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove =
                rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdateRemove_List);

            if (XNAP_P_NULL ==
                p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove)
            {
                XNAP_TRACE(XNAP_ERROR,
                           "%s: ASN malloc failed(RemoveList alloc).",
                           __FUNCTION__);
                break;
            }

            asn1Init_e2ap_E2connectionUpdateRemove_List(
                p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove);

            /**************** Add 1 remove item ****************/
            {
                OSRTDListNode *p_node_item = XNAP_P_NULL;
                e2ap_E2connectionUpdateRemove_ItemIEs *p_item_ie = XNAP_P_NULL;

                rtxDListAllocNodeAndData(&asn1_ctx,
                                         e2ap_E2connectionUpdateRemove_ItemIEs,
                                         &p_node_item,
                                         &p_item_ie);

                if (XNAP_P_NULL == p_node_item)
                {
                    XNAP_TRACE(XNAP_ERROR,
                               "%s: ASN malloc failed(Remove item).",
                               __FUNCTION__);
                    break;
                }

                asn1Init_e2ap_E2connectionUpdateRemove_ItemIEs(p_item_ie);

                p_item_ie->id = ASN1V_e2ap_id_E2connectionUpdateRemove_Item;
                p_item_ie->criticality = e2ap_ignore;
                p_item_ie->value.t =
                    T_E2AP_PDU_Contents_e2ap_E2connectionUpdateRemove_ItemIEs_id_E2connectionUpdateRemove_Item;

                p_item_ie->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item =
                    rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdateRemove_Item);

                if (XNAP_P_NULL ==
                    p_item_ie->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item)
                {
                    XNAP_TRACE(XNAP_ERROR,
                               "%s: ASN malloc failed(Remove item2).",
                               __FUNCTION__);
                    break;
                }

                asn1Init_e2ap_E2connectionUpdateRemove_Item(
                    p_item_ie->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item);

                e2ap_E2connectionUpdateRemove_Item *p_item =
                    p_item_ie->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item;

                /* Fill TNLinformation */
                asn1Init_e2ap_TNLinformation(&p_item->tnlInformation);

                p_item->tnlInformation.tnlAddress = 0x11223344;
                p_item->tnlInformation.tnlPort = 9090;

                rtxDListAppendNode(
                    p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove,
                    p_node_item);

                XNAP_TRACE(XNAP_DETAILED,
                           "Quangdv26, Add E2connectionUpdateRemove Item OK");
            }

            rtxDListAppendNode(&p_E2ConnectionUpdate->protocolIEs, p_node);

            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
        }

        /**************************************************************************
         *                          ASN ENCODE
         **************************************************************************/

        if (RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg,
                                  XNAP_MAX_ASN1_BUF_LEN, TRUE))
        {
            XNAP_TRACE(XNAP_ERROR, "pu_setBuffer failed");
            break;
        }

        if (0 != asn1PE_e2ap_E2AP_PDU(&asn1_ctx, &e2ap_pdu))
        {
            XNAP_TRACE(XNAP_ERROR,
                       "ASN1 encoding of E2 CONNECTION UPDATE failed.");

            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN,
                                      "E2AP_PDU Encode fail",
                                      &e2ap_pdu);
            ASN_ERROR_PRINT(&asn1_ctx);
            break;
        }
        else
        {
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
            XNAP_TRACE(XNAP_INFO,
                       "ASN1 encoding of E2 CONNECTION UPDATE passed.");

            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN,
                                      "E2AP_PDU Encode OK",
                                      &e2ap_pdu);
            retVal = XNAP_SUCCESS;
        }

    } while (0);

    rtFreeContext(&asn1_ctx);
    XNAP_UT_TRACE_EXIT();
    return retVal;
}
