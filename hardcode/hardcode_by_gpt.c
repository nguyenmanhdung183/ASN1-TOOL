#include <stdio.h>
#include "output_main.h"

xnap_return_et e2ap_encode_e2connection_update(
    UInt8 *p_asn_msg,
    UInt16 *p_asn_msg_len)
{
    xnap_return_et retVal = XNAP_FAILURE;
    OSCTXT asn1_ctx;
    e2ap_E2AP_PDU e2ap_pdu;
    OSDListNode *p_node = GNB_PNULL;
    e2ap_E2connectionUpdate *p_E2connUpdate = XNAP_P_NULL;
    e2ap_E2connectionUpdate_protocolIEs_element *p_e2ap_protocolIE_elem = XNAP_P_NULL;

    if (0 != rtInitContext(&asn1_ctx)) {
        XNAP_TRACE(XNAP_ERROR, "%s: ASN context initialization failed.", __FUNCTION__);
        return retVal;
    }

    do {
        XNAP_MEMSET(&e2ap_pdu, 0, sizeof(e2ap_E2AP_PDU));

        /* Set PDU type to Initiating message */
        e2ap_pdu.t = T_e2ap_E2AP_PDU_initiatingMessage;

        e2ap_pdu.u.initiatingMessage = rtxMemAllocType(&asn1_ctx, e2ap_InitiatingMessage);
        if (XNAP_P_NULL == e2ap_pdu.u.initiatingMessage) break;
        asn1Init_e2ap_InitiatingMessage(e2ap_pdu.u.initiatingMessage);

        /* ProcedureCode for E2connectionUpdate */
        e2ap_pdu.u.initiatingMessage->procedureCode = ASN1V_e2ap_id_E2connectionUpdate;
        e2ap_pdu.u.initiatingMessage->criticality = e2ap_reject;

        /* Set initiating message type */
        e2ap_pdu.u.initiatingMessage->value.t = T_E2AP_PDU_Descriptions_e2ap_E2AP_ELEMENTARY_PROCEDURES_E2connectionUpdate;
        p_E2connUpdate = rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate);
        if (XNAP_P_NULL == p_E2connUpdate) break;
        asn1Init_e2ap_E2connectionUpdate(p_E2connUpdate);

        e2ap_pdu.u.initiatingMessage->value.u._e2connectionUpdate = p_E2connUpdate;

        // ----------------- Encode TransactionID -----------------
        rtxDListAllocNodeAndData(&asn1_ctx,
                                 e2ap_E2connectionUpdate_protocolIEs_element,
                                 &p_node,
                                 &p_e2ap_protocolIE_elem);
        if (XNAP_P_NULL == p_node) break;
        asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_e2ap_protocolIE_elem);

        p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_TransactionID;
        p_e2ap_protocolIE_elem->criticality = e2ap_reject;
        p_e2ap_protocolIE_elem->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdateIEs_id_TransactionID;
        p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdateIEs_id_TransactionID = 123; // ví dụ TransactionID

        rtxDListAppendNode(&p_E2connUpdate->protocolIEs, p_node);

        // ----------------- Encode E2connectionUpdateAdd -----------------
        rtxDListAllocNodeAndData(&asn1_ctx,
                                 e2ap_E2connectionUpdate_protocolIEs_element,
                                 &p_node,
                                 &p_e2ap_protocolIE_elem);
        if (XNAP_P_NULL == p_node) break;
        asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_e2ap_protocolIE_elem);

        p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_E2connectionUpdateAdd;
        p_e2ap_protocolIE_elem->criticality = e2ap_reject;
        p_e2ap_protocolIE_elem->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd;

        p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd =
            rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate_List);
        asn1Init_e2ap_E2connectionUpdate_List(
            p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd);

        // Example: add one E2connectionUpdate-Item
        {
            OSRTDListNode *p_item_node = XNAP_P_NULL;
            e2ap_E2connectionUpdate_ItemIEs *p_item_IE = XNAP_P_NULL;

            rtxDListAllocNodeAndData(&asn1_ctx,
                                     e2ap_E2connectionUpdate_ItemIEs,
                                     &p_item_node,
                                     &p_item_IE);
            if (XNAP_P_NULL != p_item_node) {
                asn1Init_e2ap_E2connectionUpdate_ItemIEs(p_item_IE);

                p_item_IE->id = ASN1V_e2ap_id_E2connectionUpdate_Item;
                p_item_IE->criticality = e2ap_ignore;
                p_item_IE->value.t = T_e2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_id_E2connectionUpdate_Item;

                p_item_IE->value.u._e2ap_E2connectionUpdate_ItemIEs_id_E2connectionUpdate_Item =
                    rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate_Item);
                asn1Init_e2ap_E2connectionUpdate_Item(
                    p_item_IE->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item);

                // tnlInformation
                p_item_IE->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item->tnlInformation.tnlAddress.numbits = 16;
                XNAP_MEMSET(p_item_IE->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item->tnlInformation.tnlAddress.data, 0xAB, 2);
                p_item_IE->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item->tnlInformation.tnlPort.numbits = 16;
                XNAP_MEMSET(p_item_IE->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item->tnlInformation.tnlPort.data, 0x12, 2);

                // tnlUsage
                p_item_IE->value.u._e2ap_E2connectionUpdate_ItemIEs_id_E2connectionUpdate_Item->tnlUsage = 2; // "both"

                rtxDListAppendNode(&p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdateIEs_id_E2connectionUpdateAdd->E2connectionUpdate_List,
                                   p_item_node);
            }
        }

        rtxDListAppendNode(&p_E2connUpdate->protocolIEs, p_node);

        /* ASN Encode message */
        if (RT_OK != pu_setBuffer(&asn1_ctx, p_asn_msg, XNAP_MAX_ASN1_BUF_LEN, TRUE)) break;
        if (0 != asn1PE_e2ap_E2AP_PDU(&asn1_ctx, &e2ap_pdu)) break;

        *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
        retVal = XNAP_SUCCESS;

    } while (0);

    rtFreeContext(&asn1_ctx);
    return retVal;
}
