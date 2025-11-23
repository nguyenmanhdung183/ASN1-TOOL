xnap_return_et e2ap_compose_E2connectionUpdateAdd_List(
    OSCTXT *pctxt,
    e2ap_E2connectionUpdate_List *p_list)
{
    OSRTDListNode *p_node;
    e2ap_E2connectionUpdate_ItemIEs *p_item;

    rtxDListAllocNodeAndData(
        pctxt,
        e2ap_E2connectionUpdate_ItemIEs,
        &p_node,
        &p_item);

    asn1Init_e2ap_E2connectionUpdate_ItemIEs(p_item);

    p_item->id = ASN1V_e2ap_id_E2connectionUpdate_Item;
    p_item->criticality = e2ap_reject;
    p_item->value.t =
        T_E2AP_PDU_Contents_E2connectionUpdate_ItemIEs_E2connectionUpdate_Item;

    p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item =
        rtxMemAllocType(pctxt, e2ap_E2connectionUpdate_Item);

    asn1Init_e2ap_E2connectionUpdate_Item(
        p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item);

    e2ap_TNLinformation *p_tnl =
        &p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item
             ->tnlInformation;

    /* ---------------------------------------------------------
     * Gán BIT STRING cho tnlAddress theo đúng mẫu bạn gửi
     * --------------------------------------------------------- */
    uint8_t ip_data[4] = {192, 168, 0, 10};
    p_tnl->tnlAddress.numbits = 32;

    XNAP_MEMCPY(
        p_tnl->tnlAddress.data,
        ip_data,
        sizeof(ip_data));   //4 bytes

    /* ---------------------------------------------------------
     * Gán BIT STRING cho tnlPort (16 bits)
     * --------------------------------------------------------- */
    uint8_t port_data[2] = {0x1F, 0x90};  // 8080
    p_tnl->tnlPort.numbits = 16;

    XNAP_MEMCPY(
        p_tnl->tnlPort.data,
        port_data,
        sizeof(port_data));

    p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item
        ->tnlUsage = e2ap_ric_service;

    rtxDListAppendNode(p_list, p_node);
    return XNAP_SUCCESS;
}
xnap_return_et e2ap_compose_E2connectionUpdateRemove_List(
    OSCTXT *pctxt,
    e2ap_E2connectionUpdateRemove_List *p_list)
{
    OSRTDListNode *p_node;
    e2ap_E2connectionUpdateRemove_ItemIEs *p_item;

    rtxDListAllocNodeAndData(
        pctxt,
        e2ap_E2connectionUpdateRemove_ItemIEs,
        &p_node,
        &p_item);

    asn1Init_e2ap_E2connectionUpdateRemove_ItemIEs(p_item);

    p_item->id = ASN1V_e2ap_id_E2connectionUpdateRemove_Item;
    p_item->criticality = e2ap_reject;
    p_item->value.t =
        T_E2AP_PDU_Contents_E2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item;

    p_item->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item =
        rtxMemAllocType(pctxt, e2ap_E2connectionUpdateRemove_Item);

    asn1Init_e2ap_E2connectionUpdateRemove_Item(
        p_item->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item);

    e2ap_TNLinformation *p_tnl =
        &p_item->value.u._e2apE2connectionUpdateRemove_ItemIEs_E2connectionUpdateRemove_Item
             ->tnlInformation;

    uint8_t ip_data[4] = {10, 0, 0, 5};
    p_tnl->tnlAddress.numbits = 32;

    XNAP_MEMCPY(
        p_tnl->tnlAddress.data,
        ip_data,
        sizeof(ip_data));

    /* Không có tnlPort → set numbits = 0 */
    p_tnl->tnlPort.numbits = 0;

    rtxDListAppendNode(p_list, p_node);
    return XNAP_SUCCESS;
}

xnap_return_et e2ap_compose_E2connectionUpdateModify_List(
    OSCTXT *pctxt,
    e2ap_E2connectionUpdate_List *p_list)
{
    OSRTDListNode *p_node;
    e2ap_E2connectionUpdate_ItemIEs *p_item;

    rtxDListAllocNodeAndData(
        pctxt,
        e2ap_E2connectionUpdate_ItemIEs,
        &p_node,
        &p_item);

    asn1Init_e2ap_E2connectionUpdate_ItemIEs(p_item);

    p_item->id = ASN1V_e2ap_id_E2connectionUpdate_Item;
    p_item->criticality = e2ap_reject;
    p_item->value.t =
        T_E2AP_PDU_Contents_E2connectionUpdate_ItemIEs_E2connectionUpdate_Item;

    p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item =
        rtxMemAllocType(pctxt, e2ap_E2connectionUpdate_Item);

    asn1Init_e2ap_E2connectionUpdate_Item(
        p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item);

    e2ap_TNLinformation *p_tnl =
        &p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item
             ->tnlInformation;

    uint8_t ip_data[4] = {172, 16, 1, 20};
    p_tnl->tnlAddress.numbits = 32;

    XNAP_MEMCPY(
        p_tnl->tnlAddress.data,
        ip_data,
        sizeof(ip_data));

    uint8_t port_data[2] = {0x23, 0x84}; //9092
    p_tnl->tnlPort.numbits = 16;

    XNAP_MEMCPY(
        p_tnl->tnlPort.data,
        port_data,
        sizeof(port_data));

    p_item->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item
        ->tnlUsage = e2ap_both;

    rtxDListAppendNode(p_list, p_node);
    return XNAP_SUCCESS;
}


xnap_return_et e2ap_encode_e2connection_update(
    UInt8 *p_asn_msg,
    UInt16 *p_asn_msg_len)
{
    XNAP_TRACE(XNAP_INFO, "dungnm23 Encoding E2ConnectionUpdate message");
    xnap_return_et retVal = XNAP_FAILURE;
    OSCTXT asn1_ctx;
    e2ap_E2AP_PDU e2ap_pdu;
    e2ap_E2connectionUpdate *p_E2connectionUpdate = NULL;
    e2ap_E2connectionUpdate_protocolIEs_element *p_ie = NULL;
    OSRTDListNode *p_node = NULL;

    /* Init ASN1 context */
    if (0 != rtInitContext(&asn1_ctx))
    {
        XNAP_TRACE(XNAP_ERROR, "ASN context init failed");
        return retVal;
    }

    do
    {
        memset(&e2ap_pdu, 0, sizeof(e2ap_E2AP_PDU));

        /* This is InitiatingMessage for E2ConnectionUpdate */
        e2ap_pdu.t = T_e2ap_E2AP_PDU_initiatingMessage;

        e2ap_pdu.u.initiatingMessage =
            rtxMemAllocType(&asn1_ctx, e2ap_InitiatingMessage);

        asn1Init_e2ap_InitiatingMessage(e2ap_pdu.u.initiatingMessage);

        e2ap_pdu.u.initiatingMessage->procedureCode =
            ASN1V_e2ap_id_E2connectionUpdate;

        e2ap_pdu.u.initiatingMessage->criticality = e2ap_reject;

        e2ap_pdu.u.initiatingMessage->value.t =
            T_E2AP_PDU_Descriptions_e2ap_E2AP_ELEMENTARY_PROCEDURES_E2connectionUpdate;

        p_E2connectionUpdate =
            rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate);

        asn1Init_e2ap_E2connectionUpdate(p_E2connectionUpdate);

        e2ap_pdu.u.initiatingMessage->value.u.e2connectionUpdate =
            p_E2connectionUpdate;

        XNAP_TRACE(XNAP_INFO, "dungnm23 Composing E2connectionUpdate protocolIEs...");

        /****************************************************************/
        /* ======================   I E   LIST   ====================== */
        /****************************************************************/

        /* ================== TransactionID ==================*/
        rtxDListAllocNodeAndData(&asn1_ctx,
                                 e2ap_E2connectionUpdate_protocolIEs_element,
                                 &p_node,
                                 &p_ie);

        asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_ie);

        p_ie->id = ASN1V_e2ap_id_TransactionID;
        p_ie->criticality = e2ap_reject;
        p_ie->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID;

        p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID =
            rtxMemAllocType(&asn1_ctx, e2ap_TransactionID);

        *(p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID) = 1;

        rtxDListAppendNode(&p_E2connectionUpdate->protocolIEs, p_node);

        /* ================== E2connectionUpdateAdd ==================*/
        rtxDListAllocNodeAndData(&asn1_ctx,
                                 e2ap_E2connectionUpdate_protocolIEs_element,
                                 &p_node,
                                 &p_ie);

        asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_ie);

        p_ie->id = ASN1V_e2ap_id_E2connectionUpdateAdd;
        p_ie->criticality = e2ap_reject;
        p_ie->value.t =
            T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd;

        p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd =
            rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate_List);

        asn1Init_e2ap_E2connectionUpdate_List(
            p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd);

        e2ap_compose_E2connectionUpdateAdd_List(
            &asn1_ctx,
            p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd);

        rtxDListAppendNode(&p_E2connectionUpdate->protocolIEs, p_node);

        /* ================== E2connectionUpdateRemove ==================*/
        rtxDListAllocNodeAndData(&asn1_ctx,
                                 e2ap_E2connectionUpdate_protocolIEs_element,
                                 &p_node,
                                 &p_ie);

        asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_ie);

        p_ie->id = ASN1V_e2ap_id_E2connectionUpdateRemove;
        p_ie->criticality = e2ap_reject;
        p_ie->value.t =
            T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove;

        p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove =
            rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdateRemove_List);

        asn1Init_e2ap_E2connectionUpdateRemove_List(
            p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove);

        e2ap_compose_E2connectionUpdateRemove_List(
            &asn1_ctx,
            p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateRemove);

        rtxDListAppendNode(&p_E2connectionUpdate->protocolIEs, p_node);

        /* ================== E2connectionUpdateModify ==================*/
        rtxDListAllocNodeAndData(&asn1_ctx,
                                 e2ap_E2connectionUpdate_protocolIEs_element,
                                 &p_node,
                                 &p_ie);

        asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_ie);

        p_ie->id = ASN1V_e2ap_id_E2connectionUpdateModify;
        p_ie->criticality = e2ap_reject;
        p_ie->value.t =
            T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify;

        p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify =
            rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate_List);

        asn1Init_e2ap_E2connectionUpdate_List(
            p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify);

        e2ap_compose_E2connectionUpdateModify_List(
            &asn1_ctx,
            p_ie->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateModify);

        rtxDListAppendNode(&p_E2connectionUpdate->protocolIEs, p_node);

        /* ============ Encode PDU ============ */
        if (RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg, XNAP_MAX_ASN1_BUF_LEN, TRUE))
            break;

        if (0 != asn1PE_e2ap_E2AP_PDU(&asn1_ctx, &e2ap_pdu))
        {
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
            break;
        }

        *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
        retVal = XNAP_SUCCESS;

    } while (0);

    rtFreeContext(&asn1_ctx);
    return retVal;
}
