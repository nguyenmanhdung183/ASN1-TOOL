#include <stdio.h>
#include"output_main.h"
xnap_return_et e2ap_encode_e2setup_req(
    UInt8 *p_asn_msg,
    UInt16 *p_asn_msg_len)
{
    xnap_return_et retVal = XNAP_FAILURE;
    OSCTXT asn1_ctx;
    e2ap_E2AP_PDU e2ap_pdu;
    OSDListNode *p_node = GNB_PNULL;
    e2ap_E2SetupRequest *p_E2SetupRequest = XNAP_P_NULL;
    e2ap_E2SetupRequest_protocolIEs_element *p_e2ap_protocolIE_elem = XNAP_P_NULL;

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
        /* Fill the values in the ASN structures that shall be encoded by
         * ASN Encoder */

        /* Set Pdu type to Initiating message */
        e2ap_pdu.t = T_e2ap_E2AP_PDU_initiatingMessage; // --------------------> đổi nếu cần cho 3 loại message

        XNAP_TRACE(XNAP_DETAILED, "Quangdv26, Alloc e2ap_E2SetupRequest"); // ------------------> đổi nếu cần

        e2ap_pdu.u.initiatingMessage = rtxMemAllocType(&asn1_ctx, e2ap_InitiatingMessage);

        if (XNAP_P_NULL == e2ap_pdu.u.initiatingMessage)
        {
            XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed.", __FUNCTION__);
            break;
        }

        asn1Init_e2ap_InitiatingMessage(e2ap_pdu.u.initiatingMessage);

        e2ap_pdu.u.initiatingMessage->procedureCode = ASN1V_e2ap_id_E2Setup;      // -------------------------> đổi
        e2ap_pdu.u.initiatingMessage->criticality = e2ap_reject;                  // -------------------------> đổi nếu cần
        XNAP_TRACE(XNAP_DETAILED, "Quangdv26, Alloc e2ap_E2SetupRequest part 2"); // -------------------> đổi nếu cần

        /* Set the initiating message type to E2 Setup */
        e2ap_pdu.u.initiatingMessage->value.t =
            T_E2AP_PDU_Descriptions_e2ap_E2AP_ELEMENTARY_PROCEDURES_E2SetupRequest; // ------------> đổi

        p_E2SetupRequest = rtxMemAllocType(&asn1_ctx, e2ap_E2SetupRequest); //----------> đổi

        if (XNAP_P_NULL == p_E2SetupRequest) //--------> đổi
        {
            XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed.", __FUNCTION__);
            break;
        }
        else
        {
            XNAP_TRACE(XNAP_DETAILED, "Mem Alloc successful to e2ap_E2SetupRequest"); //-------------------------> đổi nếu cần
        }

        asn1Init_e2ap_E2SetupRequest(p_E2SetupRequest); //-----------> đổi

        e2ap_pdu.u.initiatingMessage->value.u.e2Setup = p_E2SetupRequest; //-----------> đổi

        // ============================================ ENCODE IE ================================================

        /* Encode TransactionID */
        {
            rtxDListAllocNodeAndData(&asn1_ctx,
                                     e2ap_E2SetupRequest_protocolIEs_element,
                                     &p_node,
                                     &p_e2ap_protocolIE_elem);

            if (XNAP_P_NULL == p_node)
            {
                /* Not enough memory */
                XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed.", __FUNCTION__);
                break;
            }

            asn1Init_e2ap_E2SetupRequest_protocolIEs_element(p_e2ap_protocolIE_elem);

            /* Fill the type of Protocol IE element */
            p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_TransactionID;
            p_e2ap_protocolIE_elem->criticality = e2ap_reject;
            p_e2ap_protocolIE_elem->value.t = T_E2AP_PDU_Contents_e2ap_E2SetupRequestIEs_id_TransactionID;

            p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_TransactionID = 0;

            rtxDListAppendNode(&p_E2SetupRequest->protocolIEs, p_node);
            XNAP_TRACE(XNAP_DETAILED, "Quangdv26, Alloc e2ap_E2SetupRequest component");
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
        }

        // ----------------------------------------------
        // Encode GlobalE2node_ID --> choice*
        // ----------------------------------------------
        {
            rtxDListAllocNodeAndData(&asn1_ctx,
                                     e2ap_E2SetupRequest_protocolIEs_element,
                                     &p_node,
                                     &p_e2ap_protocolIE_elem);

            if (XNAP_P_NULL == p_node)
            {
                /* Not enough memory */
                XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed.", __FUNCTION__);
                break;
            }

            asn1Init_e2ap_E2SetupRequest_protocolIEs_element(p_e2ap_protocolIE_elem);

            /* Fill the type of Protocol IE element */
            p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_GlobalE2node_ID;
            p_e2ap_protocolIE_elem->criticality = e2ap_reject;

            p_e2ap_protocolIE_elem->value.t = T_E2AP_PDU_Contents_e2ap_E2SetupRequestIEs_id_GlobalE2node_ID;

            p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_GlobalE2node_ID =
                rtxMemAllocType(&asn1_ctx, e2ap_GlobalE2node_ID);

            if (XNAP_P_NULL == p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_GlobalE2node_ID)
            {
                XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed.", __FUNCTION__);
                break;
            }

            asn1Init_e2ap_GlobalE2node_ID(p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_GlobalE2node_ID);
            /* ------------ */

            if (XNAP_FAILURE == e2ap_compose_GlobalE2node_ID(&asn1_ctx,
                                                             p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_GlobalE2node_ID))
            {
                XNAP_TRACE(XNAP_ERROR,
                           "%s: compose id-Global-gNB-ID returned Failure.",
                           __FUNCTION__);

                rtFreeContext(&asn1_ctx);
                XNAP_UT_TRACE_EXIT();
                return XNAP_FAILURE;
            }

            else
            {
                XNAP_TRACE(XNAP_DETAILED,
                           "compose id-Global-gNB-ID returned Success.");
            }

            /* -------------- */

            XNAP_TRACE(XNAP_DETAILED,
                       "Duongh7 debug Global-gNB-ID: id = %d - value.t = %d ",
                       p_e2ap_protocolIE_elem->id, p_e2ap_protocolIE_elem->value.t);
            XNAP_TRACE(XNAP_DETAILED,
                       "Duongh7 debug: value.t = %d - plmn.oct = %d",
                       p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_GlobalE2node_ID->u.gNB->globalgNB_ID->plmn_id.numocts);
            XNAP_TRACE(XNAP_DETAILED,
                       "Duongh7 debug: plmn_data[0] = %d - plmn_data[1] = %d - plmn_data[2] = %d ",
                       p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_GlobalE2node_ID->u.gNB->globalgNB_ID->plmn_id.data[0],
                       p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_GlobalE2node_ID->u.gNB->globalgNB_ID->plmn_id.data[1],
                       p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_GlobalE2node_ID->u.gNB->globalgNB_ID->plmn_id.data[2]);

            rtxDListAppendNode(&p_E2SetupRequest->protocolIEs, p_node);
            XNAP_TRACE(XNAP_DETAILED, "Quangdv26, Alloc e2ap_E2SetupRequest component");
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
        }
        /* Encode e2ap_RANfunctionsAdded_List */
        {
            rtxDListAllocNodeAndData(&asn1_ctx,
                                     e2ap_E2SetupRequest_protocolIEs_element,
                                     &p_node,
                                     &p_e2ap_protocolIE_elem);

            if (XNAP_P_NULL == p_node)
            {
                /* Not enough memory */
                XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed.", __FUNCTION__);
                break;
            }

            asn1Init_e2ap_E2SetupRequest_protocolIEs_element(p_e2ap_protocolIE_elem);

            /* Fill the type of Protocol IE element */
            p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_RANfunctionsAdded;
            p_e2ap_protocolIE_elem->criticality = e2ap_reject;
            p_e2ap_protocolIE_elem->value.t = T_E2AP_PDU_Contents_e2ap_E2SetupRequestIEs_id_RANfunctionsAdded_List;

            p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_RANfunctionsAdded_List =
                rtxMemAllocType(&asn1_ctx, e2ap_RANfunctionsAdded_List);

            if (XNAP_P_NULL == p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_RANfunctionsAdded_List)
            {
                XNAP_TRACE(XNAP_ERROR, "%s:ASN malloc failed.", __FUNCTION__);
                break;
            }

            asn1Init_e2ap_RANfunctionsAdded_List(p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_RANfunctionsAdded_List);
            /* ----------------*/
            if (XNAP_FAILURE == e2ap_compose_RANfunctionsAdded_List(&asn1_ctx,
                                                                    p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_RANfunctionsAdded_List))
            {
                XNAP_TRACE(XNAP_ERROR,
                           "%s:compose id-RANfunctionsAdded_List returned Failure.",
                           __FUNCTION__);

                rtFreeContext(&asn1_ctx);
                XNAP_UT_TRACE_EXIT();
                return XNAP_FAILURE;
            }
            else
            {
                XNAP_TRACE(XNAP_DETAILED,
                           "compose id-RANfunctionsAdded_List returned Success.");
            }
            /* ------------------ */
            rtxDListAppendNode(&p_E2SetupRequest->protocolIEs, p_node);
            XNAP_TRACE(XNAP_DETAILED, "Quangdv26, Alloc e2ap_E2SetupRequest component");
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
        }

        /*Encode E2nodeComponentConfigAddition */
        {
            rtxDListAllocNodeAndData(&asn1_ctx,
                                     e2ap_E2SetupRequest_protocolIEs_element,
                                     &p_node,
                                     &p_e2ap_protocolIE_elem);

            if (XNAP_P_NULL == p_node)
            {
                /* Not enough memory */
                XNAP_TRACE(XNAP_ERROR, "%s:ASN malloc failed.", __FUNCTION__);
                break;
            }

            asn1Init_e2ap_E2SetupRequest_protocolIEs_element(
                p_e2ap_protocolIE_elem);

            /* Fill the type of Protocol IE element */
            p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_E2nodeComponentConfigAddition;
            p_e2ap_protocolIE_elem->criticality = e2ap_reject;
            p_e2ap_protocolIE_elem->value.t = T_E2AP_PDU_Contents_e2ap_E2SetupRequestIEs_id_E2nodeComponentConfigAddition_List;

            p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_E2nodeComponentConfigAddition_List =
                rtxMemAllocType(&asn1_ctx, e2ap_E2nodeComponentConfigAddition_List);

            if (XNAP_P_NULL == p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_E2nodeComponentConfigAddition_List)
            {
                XNAP_TRACE(XNAP_ERROR,
                           "%s: ASN malloc failed.", __FUNCTION__);
                break;
            }

            // asn1Init_e2ap_AMF_Region_Information (p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_AMF_Region_Information);

            asn1Init_e2ap_E2nodeComponentConfigAddition_List(p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_E2nodeComponentConfigAddition_List);
            if (XNAP_FAILURE == e2ap_compose_E2nodeComponentConfigAddition_List(&asn1_ctx,
                                                                                p_e2ap_protocolIE_elem->value.u._e2ap_E2SetupRequestIEs_id_E2nodeComponentConfigAddition_List))
            {
                XNAP_TRACE(XNAP_ERROR,
                           "%s: compose id-E2nodeComponentConfigAddition_List returned Failure.",
                           __FUNCTION__);

                rtFreeContext(&asn1_ctx);
                XNAP_UT_TRACE_EXIT();
                return XNAP_FAILURE;
            }
            else
            {
                XNAP_TRACE(XNAP_DETAILED,
                           "compose id-E2nodeComponentConfigAddition_List returned Success.");
            }

            /*
             */
            rtxDListAppendNode(&p_E2SetupRequest->protocolIEs, p_node);
            XNAP_TRACE(XNAP_DETAILED, "Quangdv26, Alloc e2ap_E2SetupRequest component");
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
        }

        /* ASN Encode message */
        if (RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg, XNAP_MAX_ASN1_BUF_LEN, TRUE))
        {
            XNAP_TRACE(XNAP_ERROR, "pu_setBuffer failed.", __FUNCTION__);
            break;
        }

        if (0 != asn1PE_e2ap_E2AP_PDU(&asn1_ctx, &e2ap_pdu))
        {
            XNAP_TRACE(XNAP_ERROR, "ASN1 encoding of E2 SETUP REQUEST failed.");
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);

            SInt8 buff[500];
            rtxErrGetTextBuf(&asn1_ctx, buff, 500);
            XNAP_TRACE(XNAP_ERROR, "BUFFER[%s] %x\n", (SInt8 *)buff, buff);
            ASN_ERROR_PRINT(&asn1_ctx);
            break;
        }
        else
        {
            XNAP_TRACE(XNAP_INFO, "ASN1 encoding of E2 SETUP REQUEST passed.");
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);

            //  SInt8 buff[500];
            //  rtxErrGetTextBuf(&asn1_ctx,buff ,500);
            //  XNAP_TRACE(XNAP_ERROR, "BUFFER[%s] %x\n",(SInt8*)buff,buff);
            //  ASN_ERROR_PRINT(&asn1_ctx);

            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
            retVal = XNAP_SUCCESS;
        }
    } while (0);

    rtFreeContext(&asn1_ctx);
    XNAP_UT_TRACE_EXIT();
    return retVal;
}

xnap_return_et e2ap_compose_RANfunctionsAdded_List(
    OSCTXT *p_asn1_ctx,
    OSRTDLList *p_e2ap_ran_function_added_list)
{

    xnap_return_et retVal = XNAP_SUCCESS;
    e2ap_RANfunction_ItemIEs_t *p_RAN_function_item_IEs = NULL;
    OSRTDListNode *p_node_ran_function_item_ies = XNAP_P_NULL;
    UInt16 t_count = XNAP_NULL;

    for (t_count = 0; t_count < 1; t_count++)
    {
        rtxDListAllocNodeAndData(&asn1_ctx,
                                 e2ap_RANfunction_ItemIEs,
                                 &p_node_ran_function_item_ies,
                                 &p_RAN_function_item_IEs);

        if (XNAP_P_NULL == p_node_ran_function_item_ies)
        {
            XNAP_TRACE(XNAP_ERROR, "%s:ASN malloc failed.", __FUNCTION__);
            return XNAP_FAILURE;
        }

        asn1Init_e2ap_RANfunction_ItemIEs(p_RAN_function_item_IEs);

        p_RAN_function_item_IEs->id = ASN1V_e2ap_id_RANfunction_Item;
        p_RAN_function_item_IEs->criticality = e2ap_ignore;

        p_RAN_function_item_IEs->value.t = T_E2AP_PDU_Contents_e2ap_RANfunction_ItemIEs_id_RANfunction_Item;

        p_RAN_function_item_IEs->value.u._e2ap_RANfunction_ItemIEs_id_RANfunction_Item =
            rtxMemAllocType(p_asn1_ctx, e2ap_RANfunction_Item);

        if (XNAP_P_NULL == p_RAN_function_item_IEs->value.u._e2ap_RANfunction_ItemIEs_id_RANfunction_Item)
        {
            XNAP_TRACE(XNAP_ERROR, "%s:ASN malloc failed.", __FUNCTION__);
            break;
        }

        asn1Init_e2ap_RANfunction_Item(p_RAN_function_item_IEs->value.u._e2ap_RANfunction_ItemIEs_id_RANfunction_Item);

        /* ------------ */
        if (XNAP_FAILURE == e2ap_compose_RANfunction_Item(p_asn1_ctx,
                                                          p_RAN_function_item_IEs->value.u._e2ap_RANfunction_ItemIEs_id_RANfunction_Item))
        {
            XNAP_TRACE(XNAP_ERROR,
                       "%s: compose id-RANfunctionsAdded-List",
                       __FUNCTION__);

            rtFreeContext(p_asn1_ctx);
            return XNAP_FAILURE;
        }

        rtxDllListAppendNode(p_e2ap_ran_function_added_list, p_node_ran_function_item_ies);
    }
    XNAP_UT_TRACE_EXIT();
    return XNAP_SUCCESS;
}

xnap_return_et e2ap_compose_E2nodeComponentConfigAddition_List(
    OSCTXT *p_asn1_ctx,
    OSRTDList *p_e2ap_e2node_component_config_addition_list)
{
    xnap_return_et retVal = XNAP_SUCCESS;
    e2ap_E2nodeComponentConfigAddition_ItemIEs *p_E2nodeComponentConfigAddition_ItemIEs = NULL;
    OSRTDListNode *p_node_list = XNAP_NULL;
    UInt16 t_count = XNAP_NULL;

    for (t_count = 0; t_count < 1; t_count++)
    {
        rtxDListAllocNodeAndData(p_asn1_ctx,
                                 e2ap_E2nodeComponentConfigAddition_ItemIEs,
                                 &p_node_list,
                                 &p_E2nodeComponentConfigAddition_ItemIEs);

        if (XNAP_P_NULL == p_node_list)
        {
            XNAP_TRACE(XNAP_ERROR, "%s:ASN malloc failed.", __FUNCTION__);
            return XNAP_FAILURE;
        }

        asn1Init_e2ap_E2nodeComponentConfigAddition_ItemIEs(p_E2nodeComponentConfigAddition_ItemIEs);

        p_E2nodeComponentConfigAddition_ItemIEs->id = ASN1V_e2ap_id_E2nodeComponentConfigAddition_Item;
        p_E2nodeComponentConfigAddition_ItemIEs->criticality = e2ap_ignore;

        p_E2nodeComponentConfigAddition_ItemIEs->value.t =
            T_e2AP_PDU_Contents_e2ap_E2nodeComponentConfigAddition_ItemIEs_id_E2nodeComponentConfigAddition_Item;

        p_E2nodeComponentConfigAddition_ItemIEs->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_id_E2nodeComponentConfigAddition_Item =
            rtxMemAllocType(p_asn1_ctx, e2ap_E2nodeComponentConfigAddition_Item);

        if (XNAP_P_NULL == p_E2nodeComponentConfigAddition_ItemIEs->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_id_E2nodeComponentConfigAddition_Item)
        {
            XNAP_TRACE(XNAP_ERROR, "%s:ASN malloc failed.", __FUNCTION__);
            break;
        }

        asn1Init_e2ap_E2nodeComponentConfigAddition_Item(
            p_E2nodeComponentConfigAddition_ItemIEs->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_id_E2nodeComponentConfigAddition_Item);

        if (XNAP_FAILURE == e2ap_compose_E2nodeComponentConfigAddition_Item(p_asn1_ctx,
                                                                            p_E2nodeComponentConfigAddition_ItemIEs->value.u._e2ap_E2nodeComponentConfigAddition_ItemIEs_id_E2nodeComponentConfigAddition_Item))
        {
            XNAP_TRACE(XNAP_ERROR,
                       "%s: compose id-RANFunctionsAdded-List",
                       __FUNCTION__);

            rtFreeContext(p_asn1_ctx);
            return XNAP_FAILURE;
        }

        rtxDListAppendNode(p_e2ap_e2node_component_config_addition_list, p_node_list);
    }

    XNAP_UT_TRACE_EXIT();
    return XNAP_SUCCESS;
}

xnap_return_et e2ap_compose_GlobalE2node_ID(
    OSCTXT *asn1_ctx,
    e2ap_GlobalE2node_ID *p_e2ap_IE_gb_e2node_id)
{
    p_e2ap_IE_gb_e2node_id->t = T_e2ap_GlobalE2node_ID_gNB;
    xnap_return_et retVal = XNAP_SUCCESS;

    p_e2ap_IE_gb_e2node_id->u.gNB = rtxMemAllocType(asn1_ctx, e2ap_GlobalE2node_gNB_ID);

    if (XNAP_P_NULL == p_e2ap_IE_gb_e2node_id->u.gNB)
    {
        XNAP_TRACE(XNAP_ERROR, "%s:ASN malloc failed.", __FUNCTION__);
        //break;
    }

    asn1Init_e2ap_GlobalE2node_gNB_ID(p_e2ap_IE_gb_e2node_id->u.gNB);

    p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID = rtxMemAllocType(asn1_ctx, e2ap_GlobalgNB_ID);
    asn1Init_e2ap_GlobalgNB_ID(p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID);

    p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID.plmn_id.numocts = MAX_PLMN_ID_BYTES;

    p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID.plmn_id.data[0] = 0;
    p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID.plmn_id.data[1] = 241;
    p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID.plmn_id.data[2] = 16;

    p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID.gnb_id.t = T_e2ap_GNB_ID_Choice_gnb_ID;

    p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID.gnb_id.u.gnb_ID = rtxMemAllocType(asn1_ctx, ASN1BitStr32);

    if (XNAP_P_NULL == p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID.gnb_id.u.gnb_ID)
    {
        XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed.", __FUNCTION__);
        return XNAP_FAILURE;
    }

    memset(p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID.gnb_id.u.gnb_ID, XNAP_NULL, sizeof(ASN1BitStr32));

    p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID.gnb_id.u.gnb_ID->numbits = 28;

    p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID.gnb_id.u.gnb_ID->data[0] = 0;
    p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID.gnb_id.u.gnb_ID->data[1] = 0;
    p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID.gnb_id.u.gnb_ID->data[2] = 25;
    p_e2ap_IE_gb_e2node_id->u.gNB->globalgNB_ID.gnb_id.u.gnb_ID->data[3] = 176;

    retVal = NR_SUCCESS;
    return retVal;
}

xnap_return_et e2ap_compose_RANfunction_Item(
    OSCTXT *p_asn1_ctx,
    e2ap_RANfunction_Item_t *p_e2ap_ran_function_item)
{
    gnb_return_t retVal = NR_FAILURE;

    /* asn1Init_e2ap_RANfunctionItem(p_e2ap_ran_function_item); */
    /* Encode ranFunctionID */
    p_e2ap_ran_function_item->ranFunctionID = 147;

    /* Encode ranFunctionDefinition */
    {
        p_e2ap_ran_function_item->ranFunctionDefinition = rtxMemAllocType(p_asn1_ctx, e2ap_RANfunctionDefinition);

        asn1Init_e2ap_RANfunctionDefinition(p_e2ap_ran_function_item->ranFunctionDefinition);

        const char *buff = "6034052412e346353241d42b530440d050000813102e332e312e302e372e322e230505040204d6fe697467f2200010070e965572696fe646963265265706f772480100001300f3604d36f6e646974696f6e2d62617365";

        p_e2ap_ran_function_item->ranFunctionDefinition->numocts = 306;

        p_e2ap_ran_function_item->ranFunctionDefinition->data =
            rtxMemAllocZ(p_asn1_ctx, p_e2ap_ran_function_item->ranFunctionDefinition->numocts);

        memcpy_wrapper(p_e2ap_ran_function_item->ranFunctionDefinition->data,
                       buff,
                       p_e2ap_ran_function_item->ranFunctionDefinition->numocts);
    }

    /* Encode ranFunctionRevision */
    p_e2ap_ran_function_item->ranFunctionRevision = 0;

    /* Encode ranFunctionOID */
    {
        p_e2ap_ran_function_item->ranFunctionOID = rtxMemAllocZ(p_asn1_ctx, 1000);

        memset_wrapper((SInt8 *)p_e2ap_ran_function_item->ranFunctionOID, NR_ZERO, 1000);

        if (NULL == p_e2ap_ran_function_item->ranFunctionOID)
        {
            /* ASN 16.4 changes stop */

            X2NAP_TRACE(X2NAP_ERROR, "ASN malloc failed.");

            // break;
        }

        const char *buff2 = "1.3.6.1.4.1.53148.1.1.2.2.";
        UInt8 sz_buff2 = 25;

        memcpy_wrapper((SInt8 *)p_e2ap_ran_function_item->ranFunctionOID,
                       buff2,
                       sz_buff2);
    }

    retVal = NR_SUCCESS;
    return retVal;
}

xnap_return_et e2ap_compose_E2nodeComponentConfigAddition_Item(
    OSCTXT *p_asn1_ctx,
    e2ap_E2nodeComponentConfigAddition_Item *p_e2ap_e2node_component_config_addition_item)
{
    gnb_return_t retVal = NR_FAILURE;

    /* Encode e2ap_E2nodeComponentInterfaceType */
    p_e2ap_e2node_component_config_addition_item->e2nodeComponentInterfaceType = 0;

    /* Encode E2nodeComponentID */
    p_e2ap_e2node_component_config_addition_item->e2nodeComponentID =
        rtxMemAllocType(p_asn1_ctx, e2ap_E2nodeComponentID);
    if (PNULL == p_e2ap_e2node_component_config_addition_item->e2nodeComponentID)
    /* ASN 16.4 changes stop */
    {
        XNAP_TRACE(XNAP_ERROR, "ASN malloc failed.");
        // break;
    }

    asn1Init_e2ap_E2nodeComponentID(p_e2ap_e2node_component_config_addition_item->e2nodeComponentID);

    p_e2ap_e2node_component_config_addition_item->e2nodeComponentID->t =
        T_e2ap_E2nodeComponentID_e2nodeComponentInterfaceTypeE1;

    p_e2ap_e2node_component_config_addition_item->e2nodeComponentID->u.e2nodeComponentInterfaceE1 =
        rtxMemAllocType(p_asn1_ctx, e2ap_E2nodeComponentInterfaceTypeE1);

    asn1Init_e2ap_E2nodeComponentInterfaceTypeE1(
        p_e2ap_e2node_component_config_addition_item->e2nodeComponentID->u.e2nodeComponentInterfaceE1);

    p_e2ap_e2node_component_config_addition_item->e2nodeComponentID
        ->u.e2nodeComponentInterfaceE1->gNB_CU_UP_ID = 100;

    p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration =
        rtxMemAllocType(p_asn1_ctx, e2ap_E2nodeComponentConfiguration);
    if (PNULL == p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration)
    /*ASN 16.4 changes stop*/
    {
        XNAP_TRACE(XNAP_ERROR, "ASN malloc failed.");
        // break;
    }

    asn1Init_e2ap_E2nodeComponentConfiguration(
        p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration);

    // p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentRequestPart =
    //          rtxMemAllocType(p_asn1_ctx, e2ap_E2nodeComponentRequestPart);

    // asn1Init_e2ap_E2nodeComponentRequestPart(
    //          p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentRequestPart);

    const char *buff2 = "72657170617274";

    p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentRequestPart.numocts = 14;

    p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentRequestPart.data =
        rtxMemAllocZ(p_asn1_ctx,
                     p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentRequestPart.numocts);

    memcpy_wrapper(p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentRequestPart.data,
                   buff2,
                   p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentRequestPart.numocts);

    // p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentResponsePart =
    //          rtxMemAllocType(p_asn1_ctx, e2ap_E2nodeComponentResponsePart);

    // asn1Init_e2ap_E2nodeComponentResponsePart(
    //          p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentResponsePart);

    const char *buff3 = "72657370617274";

    p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentResponsePart.numocts = 14;

    p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentResponsePart.data =
        rtxMemAllocZ(p_asn1_ctx,
                     p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentResponsePart.numocts);

    memcpy_wrapper(p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentResponsePart.data,
                   buff3,
                   p_e2ap_e2node_component_config_addition_item->e2nodeComponentConfiguration->e2nodeComponentResponsePart.numocts);

    retVal = NR_SUCCESS;
    return retVal;
}