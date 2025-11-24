/* --- Compose ADD --- */
xnap_return_et e2ap_compose_E2connectionUpdateAdd_List(
    OSCTXT *pctxt,
    e2ap_E2connectionUpdate_List *p_list)
{
    OSRTDListNode *p_node;
    e2ap_E2connectionUpdate_ItemIEs *p_item;

    XNAP_TRACE(XNAP_INFO, "dungnm23 [ADD] Allocating E2connectionUpdateAdd item");

    rtxDListAllocNodeAndData(
        pctxt,
        e2ap_E2connectionUpdate_ItemIEs,
        &p_node,
        &p_item);

    if (!p_node || !p_item) {
        XNAP_TRACE(XNAP_INFO, "dungnm23 [ADD] Allocation FAILED for item or node");
        return XNAP_FAILURE;
    }

    asn1Init_e2ap_E2connectionUpdate_ItemIEs(p_item);

    p_item->id = ASN1V_e2ap_id_E2connectionUpdate_Item;
    p_item->criticality = e2ap_reject;
    p_item->value.t =
        T_E2AP_PDU_Contents_E2connectionUpdate_ItemIEs_E2connectionUpdate_Item;

    p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item =
        rtxMemAllocType(pctxt, e2ap_E2connectionUpdate_Item);

    if (!p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item) {
        XNAP_TRACE(XNAP_INFO, "dungnm23 [ADD] rtxMemAllocType FAILED for E2connectionUpdate_Item");
        return XNAP_FAILURE;
    }

    asn1Init_e2ap_E2connectionUpdate_Item(
        p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item);

    e2ap_TNLinformation *p_tnl =
        &p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item
             ->tnlInformation;

    uint8_t ip_data[4] = {192, 168, 0, 10};
    p_tnl->tnlAddress.numbits = 32;
    XNAP_MEMCPY(p_tnl->tnlAddress.data, ip_data, sizeof(ip_data));

    XNAP_TRACE(XNAP_INFO,
               "dungnm23 [ADD] tnlAddress set to %d.%d.%d.%d (numbits=%d)",
               ip_data[0], ip_data[1], ip_data[2], ip_data[3],
               p_tnl->tnlAddress.numbits);

    uint8_t port_data[2] = {0x1F, 0x90};  // 8080
    p_tnl->tnlPort.numbits = 16;
    XNAP_MEMCPY(p_tnl->tnlPort.data, port_data, sizeof(port_data));

    unsigned int port_val = (port_data[0] << 8) | port_data[1];
    XNAP_TRACE(XNAP_INFO,
               "dungnm23 [ADD] tnlPort set to %u (numbits=%d)",
               port_val,
               p_tnl->tnlPort.numbits);

    p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item
        ->tnlUsage = e2ap_ric_service;

    rtxDListAppendNode(p_list, p_node);
    XNAP_TRACE(XNAP_INFO, "dungnm23 [ADD] Item appended to E2connectionUpdateAdd list");

    return XNAP_SUCCESS;
}

/* --- Compose REMOVE --- */
xnap_return_et e2ap_compose_E2connectionUpdateRemove_List(
    OSCTXT *pctxt,
    e2ap_E2connectionUpdateRemove_List *p_list)
{
    OSRTDListNode *p_node;
    e2ap_E2connectionUpdateRemove_ItemIEs *p_item;

    XNAP_TRACE(XNAP_INFO, "dungnm23 [REMOVE] Allocating E2connectionUpdateRemove item");

    rtxDListAllocNodeAndData(
        pctxt,
        e2ap_E2connectionUpdateRemove_ItemIEs,
        &p_node,
        &p_item);

    if (!p_node || !p_item) {
        XNAP_TRACE(XNAP_INFO, "dungnm23 [REMOVE] Allocation FAILED for remove item or node");
        return XNAP_FAILURE;
    }

    asn1Init_e2ap_E2connectionUpdateRemove_ItemIEs(p_item);

    p_item->id = ASN1V_e2ap_id_E2connectionUpdateRemove_Item;
    p_item->criticality = e2ap_reject;
    p_item->value.t =
        T_E2AP_PDU_Contents_E2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item;

    p_item->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item =
        rtxMemAllocType(pctxt, e2ap_E2connectionUpdateRemove_Item);

    if (!p_item->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item) {
        XNAP_TRACE(XNAP_INFO, "dungnm23 [REMOVE] rtxMemAllocType FAILED for E2connectionUpdateRemove_Item");
        return XNAP_FAILURE;
    }

    asn1Init_e2ap_E2connectionUpdateRemove_Item(
        p_item->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item);

    e2ap_TNLinformation *p_tnl =
        &p_item->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item
             ->tnlInformation;

    uint8_t ip_data[4] = {10, 0, 0, 5};
    p_tnl->tnlAddress.numbits = 32;
    XNAP_MEMCPY(p_tnl->tnlAddress.data, ip_data, sizeof(ip_data));

    XNAP_TRACE(XNAP_INFO,
               "dungnm23 [REMOVE] tnlAddress set to %d.%d.%d.%d (numbits=%d)",
               ip_data[0], ip_data[1], ip_data[2], ip_data[3],
               p_tnl->tnlAddress.numbits);

    /* Không có tnlPort → set numbits = 0 */
    p_tnl->tnlPort.numbits = 0;
    XNAP_TRACE(XNAP_INFO, "dungnm23 [REMOVE] tnlPort not present (numbits=0)");

    rtxDListAppendNode(p_list, p_node);
    XNAP_TRACE(XNAP_INFO, "dungnm23 [REMOVE] Item appended to E2connectionUpdateRemove list");

    return XNAP_SUCCESS;
}

/* --- Compose MODIFY --- */
xnap_return_et e2ap_compose_E2connectionUpdateModify_List(
    OSCTXT *pctxt,
    e2ap_E2connectionUpdate_List *p_list)
{
    OSRTDListNode *p_node;
    e2ap_E2connectionUpdate_ItemIEs *p_item;

    XNAP_TRACE(XNAP_INFO, "dungnm23 [MOD] Allocating E2connectionUpdateModify item");

    rtxDListAllocNodeAndData(
        pctxt,
        e2ap_E2connectionUpdate_ItemIEs,
        &p_node,
        &p_item);

    if (!p_node || !p_item) {
        XNAP_TRACE(XNAP_INFO, "dungnm23 [MOD] Allocation FAILED for modify item or node");
        return XNAP_FAILURE;
    }

    asn1Init_e2ap_E2connectionUpdate_ItemIEs(p_item);

    p_item->id = ASN1V_e2ap_id_E2connectionUpdate_Item;
    p_item->criticality = e2ap_reject;
    p_item->value.t =
        T_E2AP_PDU_Contents_E2connectionUpdate_ItemIEs_E2connectionUpdate_Item;

    p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item =
        rtxMemAllocType(pctxt, e2ap_E2connectionUpdate_Item);

    if (!p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item) {
        XNAP_TRACE(XNAP_INFO, "dungnm23 [MOD] rtxMemAllocType FAILED for E2connectionUpdate_Item");
        return XNAP_FAILURE;
    }

    asn1Init_e2ap_E2connectionUpdate_Item(
        p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item);

    e2ap_TNLinformation *p_tnl =
        &p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item
             ->tnlInformation;

    uint8_t ip_data[4] = {172, 16, 1, 20};
    p_tnl->tnlAddress.numbits = 32;
    XNAP_MEMCPY(p_tnl->tnlAddress.data, ip_data, sizeof(ip_data));

    XNAP_TRACE(XNAP_INFO,
               "dungnm23 [MOD] tnlAddress set to %d.%d.%d.%d (numbits=%d)",
               ip_data[0], ip_data[1], ip_data[2], ip_data[3],
               p_tnl->tnlAddress.numbits);

    uint8_t port_data[2] = {0x23, 0x84}; //9092
    p_tnl->tnlPort.numbits = 16;
    XNAP_MEMCPY(p_tnl->tnlPort.data, port_data, sizeof(port_data));

    unsigned int port_val = (port_data[0] << 8) | port_data[1];
    XNAP_TRACE(XNAP_INFO,
               "dungnm23 [MOD] tnlPort set to %u (numbits=%d)",
               port_val,
               p_tnl->tnlPort.numbits);

    p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item
        ->tnlUsage = e2ap_both;

    rtxDListAppendNode(p_list, p_node);
    XNAP_TRACE(XNAP_INFO, "dungnm23 [MOD] Item appended to E2connectionUpdateModify list");

    return XNAP_SUCCESS;
}

/* --- Encode function --- */
xnap_return_et e2ap_encode_e2connection_update(
    UInt8 *p_asn_msg,
    UInt16 *p_asn_msg_len)
{
    XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Encoding E2ConnectionUpdate message - start");
    xnap_return_et retVal = XNAP_FAILURE;
    OSCTXT asn1_ctx;
    e2ap_E2AP_PDU e2ap_pdu;
    e2ap_E2connectionUpdate *p_E2connectionUpdate = NULL;
    e2ap_E2connectionUpdate_protocolIEs_element *p_ie = NULL;
    OSRTDListNode *p_node = NULL;

    XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Initializing ASN.1 context");
    if (0 != rtInitContext(&asn1_ctx))
    {
        XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] ASN context init failed");
        return retVal;
    }

    do
    {
        memset(&e2ap_pdu, 0, sizeof(e2ap_E2AP_PDU));

        /* This is InitiatingMessage for E2ConnectionUpdate */
        e2ap_pdu.t = T_e2ap_E2AP_PDU_initiatingMessage;

        e2ap_pdu.u.initiatingMessage =
            rtxMemAllocType(&asn1_ctx, e2ap_InitiatingMessage);

        if (!e2ap_pdu.u.initiatingMessage) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] rtxMemAllocType FAILED for InitiatingMessage");
            break;
        }

        asn1Init_e2ap_InitiatingMessage(e2ap_pdu.u.initiatingMessage);

        e2ap_pdu.u.initiatingMessage->procedureCode =
            ASN1V_e2ap_id_E2connectionUpdate;

        e2ap_pdu.u.initiatingMessage->criticality = e2ap_reject;

        e2ap_pdu.u.initiatingMessage->value.t =
            T_E2AP_PDU_Descriptions_e2ap_E2AP_ELEMENTARY_PROCEDURES_E2connectionUpdate;

        p_E2connectionUpdate =
            rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate);

        if (!p_E2connectionUpdate) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] rtxMemAllocType FAILED for e2ap_E2connectionUpdate");
            break;
        }

        asn1Init_e2ap_E2connectionUpdate(p_E2connectionUpdate);

        /* Use the same union member name as in your original headers */
        e2ap_pdu.u.initiatingMessage->value.u.e2connectionUpdate =
            p_E2connectionUpdate;

        XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Composing E2connectionUpdate protocolIEs");

        /* ----------------- TransactionID IE ----------------- */
        rtxDListAllocNodeAndData(&asn1_ctx,
                                 e2ap_E2connectionUpdate_protocolIEs_element,
                                 &p_node,
                                 &p_ie);

        if (!p_node || !p_ie) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Allocation FAILED for protocolIE element (TransactionID)");
            break;
        }

        asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_ie);

        p_ie->id = ASN1V_e2ap_id_TransactionID;
        p_ie->criticality = e2ap_reject;
        p_ie->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID;

        p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID =
            rtxMemAllocType(&asn1_ctx, e2ap_TransactionID);

        if (!p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] rtxMemAllocType FAILED for TransactionID value");
            break;
        }

        *(p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID) = 1;
        XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] TransactionID set to 1");

        rtxDListAppendNode(&p_E2connectionUpdate->protocolIEs, p_node);
        XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Appended TransactionID IE");

        /* ----------------- Add IE ----------------- */
        rtxDListAllocNodeAndData(&asn1_ctx,
                                 e2ap_E2connectionUpdate_protocolIEs_element,
                                 &p_node,
                                 &p_ie);
        if (!p_node || !p_ie) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Allocation FAILED for protocolIE element (Add)");
            break;
        }

        asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_ie);

        p_ie->id = ASN1V_e2ap_id_E2connectionUpdateAdd;
        p_ie->criticality = e2ap_reject;
        p_ie->value.t =
            T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd;

        p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd =
            rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate_List);

        if (!p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] rtxMemAllocType FAILED for E2connectionUpdateAdd list");
            break;
        }

        asn1Init_e2ap_E2connectionUpdate_List(
            p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd);

        if (XNAP_FAILURE == e2ap_compose_E2connectionUpdateAdd_List(
            &asn1_ctx,
            p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd)) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] e2ap_compose_E2connectionUpdateAdd_List returned FAILURE");
            break;
        }

        rtxDListAppendNode(&p_E2connectionUpdate->protocolIEs, p_node);
        XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Appended E2connectionUpdateAdd IE");

        /* ----------------- Remove IE ----------------- */
        rtxDListAllocNodeAndData(&asn1_ctx,
                                 e2ap_E2connectionUpdate_protocolIEs_element,
                                 &p_node,
                                 &p_ie);
        if (!p_node || !p_ie) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Allocation FAILED for protocolIE element (Remove)");
            break;
        }

        asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_ie);

        p_ie->id = ASN1V_e2ap_id_E2connectionUpdateRemove;
        p_ie->criticality = e2ap_reject;
        p_ie->value.t =
            T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove;

        p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove =
            rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdateRemove_List);

        if (!p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] rtxMemAllocType FAILED for E2connectionUpdateRemove list");
            break;
        }

        asn1Init_e2ap_E2connectionUpdateRemove_List(
            p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove);

        if (XNAP_FAILURE == e2ap_compose_E2connectionUpdateRemove_List(
            &asn1_ctx,
            p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove)) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] e2ap_compose_E2connectionUpdateRemove_List returned FAILURE");
            break;
        }

        rtxDListAppendNode(&p_E2connectionUpdate->protocolIEs, p_node);
        XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Appended E2connectionUpdateRemove IE");

        /* ----------------- Modify IE ----------------- */
        rtxDListAllocNodeAndData(&asn1_ctx,
                                 e2ap_E2connectionUpdate_protocolIEs_element,
                                 &p_node,
                                 &p_ie);
        if (!p_node || !p_ie) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Allocation FAILED for protocolIE element (Modify)");
            break;
        }

        asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_ie);

        p_ie->id = ASN1V_e2ap_id_E2connectionUpdateModify;
        p_ie->criticality = e2ap_reject;
        p_ie->value.t =
            T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify;

        p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify =
            rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate_List);

        if (!p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] rtxMemAllocType FAILED for E2connectionUpdateModify list");
            break;
        }

        asn1Init_e2ap_E2connectionUpdate_List(
            p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify);

        if (XNAP_FAILURE == e2ap_compose_E2connectionUpdateModify_List(
            &asn1_ctx,
            p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify)) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] e2ap_compose_E2connectionUpdateModify_List returned FAILURE");
            break;
        }

        rtxDListAppendNode(&p_E2connectionUpdate->protocolIEs, p_node);
        XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Appended E2connectionUpdateModify IE");

        /* ============ Encode PDU ============ */
        XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Setting buffer for ASN.1 output");
        if (RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg, XNAP_MAX_ASN1_BUF_LEN, TRUE)) {
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] pu_setBuffer FAILED");
            break;
        }

        XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Performing ASN.1 encoding of E2 AP PDU");
        if (0 != asn1PE_e2ap_E2AP_PDU(&asn1_ctx, &e2ap_pdu))
        {
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
            SInt8 buff[500];
            rtxErrGetTextBuf(&asn1_ctx, buff, 500);
            XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] ASN1 encoding FAILED. msgLen=%u. ASN1 error: %s",
                       *p_asn_msg_len, (char*)buff);
            ASN_ERROR_PRINT(&asn1_ctx);
            break;
        }

        *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
        XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] ASN1 encoding SUCCESS. msgLen=%u bytes", *p_asn_msg_len);
        rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
        retVal = XNAP_SUCCESS;

    } while (0);

    rtFreeContext(&asn1_ctx);
    XNAP_TRACE(XNAP_INFO, "dungnm23 [ENC] Exiting encode function (ret=%d)", retVal);
    return retVal;
}
