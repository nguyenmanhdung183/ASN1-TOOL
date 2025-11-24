
/* Helper: compose TNLinformation (fills tnlAddress, optional tnlPort and sets tnlUsage on caller item) */
static xnap_return_et
e2ap_compose_TNLinformation(OSCTXT *p_asn1_ctx,
                           e2ap_TNLinformation *p_tnlinfo,
                           const OSOCTET *addr_bytes, size_t addr_bytes_len,
                           const OSOCTET *port_bytes, size_t port_bytes_len)
{
    if (!p_asn1_ctx || !p_tnlinfo || !addr_bytes) return XNAP_FAILURE;

    asn1Init_e2ap_TNLinformation(p_tnlinfo);

    /* tnlAddress: BIT STRING, size 1..160 (bits)
       we expect addr_bytes is the minimal octet array (addr_bytes_len bytes).
       set numbits = addr_bytes_len * 8 (caller must ensure <=160 bits)
    */
    p_tnlinfo->tnlAddress.numbits = (OSUINT32)(addr_bytes_len * 8);
    if (addr_bytes_len > sizeof(p_tnlinfo->tnlAddress.data)) {
        XNAP_TRACE(XNAP_INFO, " dungnm23 tnlAddress too large.");
        return XNAP_FAILURE;
    }
    XNAP_MEMCPY(p_tnlinfo->tnlAddress.data, addr_bytes, addr_bytes_len);

    /* optional tnlPort: BIT STRING size 16 bits (2 bytes) */
    if (port_bytes && port_bytes_len >= 2) {
        p_tnlinfo->m_tnlPortPresent = TRUE;
        p_tnlinfo->tnlPort.numbits = 16;
        XNAP_MEMCPY(p_tnlinfo->tnlPort.data, port_bytes, 2);
    } else {
        p_tnlinfo->m_tnlPortPresent = FALSE;
    }

    return XNAP_SUCCESS;
}

/* Helper: compose a E2connectionUpdate_List with one item (Add/Modify) */
static xnap_return_et
e2ap_compose_E2connectionUpdate_List(OSCTXT *p_asn1_ctx,
                                     OSRTDList *p_list /* e2ap_E2connectionUpdate_List */)
{
    OSRTDListNode *p_item_node = XNAP_P_NULL;
    e2ap_E2connectionUpdate_ItemIEs *p_itemIE = XNAP_P_NULL;
    e2ap_E2connectionUpdate_Item *p_item = XNAP_P_NULL;

    /* sample hardcoded address & port (change to real values as needed) */
    const OSOCTET sample_addr[20] = {
        0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,
        0xBB,0xCC,0xDD,0xEE,0xFF,0x00,0x11,0x22,0x33,0x44
    }; /* 20 bytes = 160 bits */
    const OSOCTET sample_port[2] = { 0x1F, 0x90 }; /* port 8080 example */

    /* allocate node+data for list item IE (this type is defined in output_main.h) */
    rtxDListAllocNodeAndData(p_asn1_ctx,
                             e2ap_E2connectionUpdate_ItemIEs,
                             &p_item_node,
                             &p_itemIE);

    if (XNAP_P_NULL == p_item_node) {
        XNAP_TRACE(XNAP_INFO, " dungnm23 %s: ASN malloc failed.", __FUNCTION__);
        return XNAP_FAILURE;
    }

    asn1Init_e2ap_E2connectionUpdate_ItemIEs(p_itemIE);

    /* According to header, the IE container will carry an E2connectionUpdate_Item */
    /* set id/criticality. The exact ASN1V id symbol may vary in your project.
       Use the appropriate macro if different. */
    p_itemIE->id = ASN1V_e2ap_id_E2connectionUpdate_Item; /* assume defined */
    p_itemIE->criticality = e2ap_ignore;
    p_itemIE->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_E2connectionUpdate_Item;

    /* allocate the actual E2connectionUpdate_Item */
    p_itemIE->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item =
        rtxMemAllocType(p_asn1_ctx, e2ap_E2connectionUpdate_Item);

    if (XNAP_P_NULL == p_itemIE->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item) {
        XNAP_TRACE(XNAP_INFO, " dungnm23 %s: ASN malloc failed.", __FUNCTION__);
        return XNAP_FAILURE;
    }

    p_item = p_itemIE->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item;
    asn1Init_e2ap_E2connectionUpdate_Item(p_item);

    /* Compose tnlInformation (hard-coded sample) */
    if (XNAP_FAILURE == e2ap_compose_TNLinformation(p_asn1_ctx,
                                                   &p_item->tnlInformation,
                                                   sample_addr, sizeof(sample_addr),
                                                   sample_port, sizeof(sample_port))) {
        XNAP_TRACE(XNAP_INFO, " dungnm23 %s: compose TNLinformation failed.", __FUNCTION__);
        return XNAP_FAILURE;
    }

    /* Set tnlUsage (enum): e2ap_ric_service = 0, e2ap_support_function = 1, e2ap_both = 2 */
    p_item->tnlUsage = e2ap_both;

    /* append node to the list */
    rtxDListAppendNode(p_list, p_item_node);

    return XNAP_SUCCESS;
}

/* Full encoder: e2ap_encode_e2connection_update */
xnap_return_et e2ap_encode_e2connection_update(
    UInt8 *p_asn_msg,
    UInt16 *p_asn_msg_len)
{
    xnap_return_et retVal = XNAP_FAILURE;
    OSCTXT asn1_ctx;
    e2ap_E2AP_PDU e2ap_pdu;
    OSRTDListNode *p_node = GNB_PNULL;
    e2ap_E2connectionUpdate *p_E2connectionUpdate = XNAP_P_NULL;
    e2ap_E2connectionUpdate_protocolIEs_element *p_e2ap_protocolIE_elem = XNAP_P_NULL;

    /* Init ASN1 context */
    if (0 != rtInitContext(&asn1_ctx)) {
        XNAP_TRACE(XNAP_INFO, " dungnm23 %s: ASN context initialization failed.", __FUNCTION__);
        return retVal;
    }

    do {
        XNAP_MEMSET(&e2ap_pdu, 0, sizeof(e2ap_E2AP_PDU));

        /* Set Pdu type to Initiating message */
        e2ap_pdu.t = T_e2ap_E2AP_PDU_initiatingMessage;
        e2ap_pdu.u.initiatingMessage = rtxMemAllocType(&asn1_ctx, e2ap_InitiatingMessage);
        if (XNAP_P_NULL == e2ap_pdu.u.initiatingMessage) {
            XNAP_TRACE(XNAP_INFO, " dungnm23 %s: ASN malloc failed.", __FUNCTION__);
            break;
        }
        asn1Init_e2ap_InitiatingMessage(e2ap_pdu.u.initiatingMessage);

        /* Set procedureCode = E2connectionUpdate (use correct macro in your project) */
        e2ap_pdu.u.initiatingMessage->procedureCode = ASN1V_e2ap_id_E2connectionUpdate;
        e2ap_pdu.u.initiatingMessage->criticality = e2ap_reject;
        e2ap_pdu.u.initiatingMessage->value.t = T_E2AP_PDU_Descriptions_e2ap_E2AP_ELEMENTARY_PROCEDURES_E2connectionUpdate;

        /* allocate E2connectionUpdate body */
        p_E2connectionUpdate = rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate);
        if (XNAP_P_NULL == p_E2connectionUpdate) {
            XNAP_TRACE(XNAP_INFO, " dungnm23 %s: ASN malloc failed for E2connectionUpdate.", __FUNCTION__);
            break;
        }
        asn1Init_e2ap_E2connectionUpdate(p_E2connectionUpdate);
        e2ap_pdu.u.initiatingMessage->value.u.e2connectionUpdate = p_E2connectionUpdate;

        /* ---------- IE 1: TransactionID (mandatory) ---------- */
        {
            rtxDListAllocNodeAndData(&asn1_ctx,
                                     e2ap_E2connectionUpdate_protocolIEs_element,
                                     &p_node,
                                     &p_e2ap_protocolIE_elem);
            if (XNAP_P_NULL == p_node) {
                XNAP_TRACE(XNAP_INFO, " dungnm23 %s: ASN malloc failed.", __FUNCTION__);
                break;
            }

            asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_e2ap_protocolIE_elem);

            p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_TransactionID;
            p_e2ap_protocolIE_elem->criticality = e2ap_reject;
            p_e2ap_protocolIE_elem->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID;

            /* Hardcode transaction id (0..255) */
            {
                e2ap_TransactionID *p_tx = rtxMemAllocType(&asn1_ctx, e2ap_TransactionID);
                if (XNAP_P_NULL == p_tx) {
                    XNAP_TRACE(XNAP_INFO, " dungnm23 %s: ASN malloc failed for TransactionID.", __FUNCTION__);
                    break;
                }
                *p_tx = (e2ap_TransactionID) 1; /* example transaction id */
                p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID = p_tx;
            }

            rtxDListAppendNode(&p_E2connectionUpdate->protocolIEs, p_node);
        }

        /* ---------- IE 2: E2connectionUpdateAdd (OPTIONAL) ---------- */
        {
            rtxDListAllocNodeAndData(&asn1_ctx,
                                     e2ap_E2connectionUpdate_protocolIEs_element,
                                     &p_node,
                                     &p_e2ap_protocolIE_elem);
            if (XNAP_P_NULL == p_node) {
                XNAP_TRACE(XNAP_INFO, " dungnm23 %s: ASN malloc failed.", __FUNCTION__);
                break;
            }

            asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_e2ap_protocolIE_elem);

            p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_E2connectionUpdateAdd;
            p_e2ap_protocolIE_elem->criticality = e2ap_reject;
            p_e2ap_protocolIE_elem->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd;

            p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd =
                rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate_List);
            if (XNAP_P_NULL == p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd) {
                XNAP_TRACE(XNAP_INFO, " dungnm23 %s: ASN malloc failed for Add list.", __FUNCTION__);
                break;
            }
            asn1Init_e2ap_E2connectionUpdate_List(p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd);

            /* Compose one item (you can loop to add multiple) */
            if (XNAP_FAILURE == e2ap_compose_E2connectionUpdate_List(&asn1_ctx,
                                                                    p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd)) {
                XNAP_TRACE(XNAP_INFO, " dungnm23 %s: compose E2connectionUpdate_Add list failed.", __FUNCTION__);
                rtFreeContext(&asn1_ctx);
                return XNAP_FAILURE;
            }

            rtxDListAppendNode(&p_E2connectionUpdate->protocolIEs, p_node);
        }

        /* ---------- Optional: E2connectionUpdateRemove or Modify could be built similarly ---------- */

        /* ASN Encode message */
        if (RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg, XNAP_MAX_ASN1_BUF_LEN, TRUE)) {
            XNAP_TRACE(XNAP_INFO, " dungnm23 pu_setBuffer failed.", __FUNCTION__);
            break;
        }

        if (0 != asn1PE_e2ap_E2AP_PDU(&asn1_ctx, &e2ap_pdu)) {
            XNAP_TRACE(XNAP_INFO, " dungnm23 ASN1 encoding of E2 CONNECTION UPDATE failed.");
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
            SInt8 buff[500];
            rtxErrGetTextBuf(&asn1_ctx, buff, 500);
            XNAP_TRACE(XNAP_INFO, " dungnm23 ASN ERROR: %s", (char*)buff);
            break;
        } else {
            XNAP_TRACE(XNAP_INFO, " dungnm23 ASN1 encoding of E2 CONNECTION UPDATE passed.");
            *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
            retVal = XNAP_SUCCESS;
        }

    } while (0);

    rtFreeContext(&asn1_ctx);
    return retVal;
}
