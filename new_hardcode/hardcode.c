#include"output_main1.h"
#include<stdio.h>
#include"harcode_e2setupreq.h"
/*

E2connectionUpdate (SEQUENCE)
└── protocolIEs (ProtocolIE-Container, SEQUENCE OF E2connectionUpdate-IEs)
    ├── id-TransactionID (TransactionID, INTEGER 0..255, PRIMITIVE) [reject, mandatory]
    ├── id-E2connectionUpdateAdd (E2connectionUpdate-List, SingleContainer, OPTIONAL) [reject]
    │   └── E2connectionUpdate-ItemIEs (SEQUENCE OF E2connectionUpdate-Item)
    │       ├── tnlInformation (TNLinformation, SEQUENCE)
    │       │   ├── tnlAddress (BIT STRING, SIZE 1..160, PRIMITIVE)
    │       │   └── tnlPort (BIT STRING, SIZE 16, PRIMITIVE, OPTIONAL)
    │       └── tnlUsage (TNLusage, ENUMERATED {ric-service=0, support-function=1, both=2}, PRIMITIVE)
    ├── id-E2connectionUpdateRemove (E2connectionUpdateRemove-List, SingleContainer, OPTIONAL) [reject]
    │   └── E2connectionUpdateRemove-ItemIEs (SEQUENCE OF E2connectionUpdateRemove-Item)
    │       └── tnlInformation (TNLinformation, SEQUENCE)
    │           ├── tnlAddress (BIT STRING, SIZE 1..160, PRIMITIVE)
    │           └── tnlPort (BIT STRING, SIZE 16, PRIMITIVE, OPTIONAL)
    └── id-E2connectionUpdateModify (E2connectionUpdate-List, SingleContainer, OPTIONAL) [reject]
        └── E2connectionUpdate-ItemIEs (SEQUENCE OF E2connectionUpdate-Item)
            ├── tnlInformation (TNLinformation, SEQUENCE)
            │   ├── tnlAddress (BIT STRING, SIZE 1..160, PRIMITIVE)
            │   └── tnlPort (BIT STRING, SIZE 16, PRIMITIVE, OPTIONAL)
            └── tnlUsage (TNLusage, ENUMERATED {ric-service=0, support-function=1, both=2}, PRIMITIVE)

*/
xnap_return_et e2ap_compose_E2connectionUpdate_Item(OSCTXT* p_asn1_ctx,
                                                    e2ap_E2connectionUpdate_Item *p_e2connectionupdate_item)
{
    xnap_return_et retVal = XNAP_FAILURE;

    if (!p_asn1_ctx || !p_e2connectionupdate_item) return XNAP_FAILURE;

    /* init TNLinformation (no malloc since it's non-pointer in header) */
    asn1Init_e2ap_TNLinformation(&p_e2connectionupdate_item->tnlInformation);

    /* --- tnlAddress (dynamic bitstring) --- */
    asn1Init_e2ap_TNLinformation_tnlAddress(&p_e2connectionupdate_item->tnlInformation.tnlAddress);

    /* set 32 bits (4 bytes) example 192.168.0.1 */
    {
        OSUINT32 numbits = 32;
        size_t nbytes = (numbits + 7) / 8;
        p_e2connectionupdate_item->tnlInformation.tnlAddress.numbits = numbits;
        p_e2connectionupdate_item->tnlInformation.tnlAddress.data =
            (OSOCTET*) rtxMemAlloc(p_asn1_ctx, nbytes);
        if (p_e2connectionupdate_item->tnlInformation.tnlAddress.data == NULL) {
            XNAP_TRACE(XNAP_ERROR, "ASN malloc failed for tnlAddress.data");
            return XNAP_FAILURE;
        }
        memset(p_e2connectionupdate_item->tnlInformation.tnlAddress.data, 0, nbytes);
        p_e2connectionupdate_item->tnlInformation.tnlAddress.data[0] = 192;
        p_e2connectionupdate_item->tnlInformation.tnlAddress.data[1] = 168;
        p_e2connectionupdate_item->tnlInformation.tnlAddress.data[2] = 0;
        p_e2connectionupdate_item->tnlInformation.tnlAddress.data[3] = 1;
    }

    /* --- tnlPort (fixed size 16 bits) --- */
    p_e2connectionupdate_item->tnlInformation.m_tnlPortPresent = 1;
    p_e2connectionupdate_item->tnlInformation.tnlPort.numbits = 16;
    /* data is a 2-byte array inside struct, set directly */
    p_e2connectionupdate_item->tnlInformation.tnlPort.data[0] = 0x1F;
    p_e2connectionupdate_item->tnlInformation.tnlPort.data[1] = 0x90;

    /* --- tnlUsage (enum) --- */
    p_e2connectionupdate_item->tnlUsage = e2ap_ric_service; /* or other value */

    retVal = XNAP_SUCCESS;
    return retVal;
}


xnap_return_et e2ap_compose_E2connectionUpdate_List(OSCTXT* p_asn1_ctx, OSRTDList *p_e2connectionupdate_list)
{
    xnap_return_et retVal = XNAP_SUCCESS;
    e2ap_E2connectionUpdate_ItemIEs *p_E2connectionUpdate_ItemIEs = NULL;
    OSRTDListNode *p_node_e2connectionupdate_item_ies = XNAP_P_NULL;
    UInt16 t_count = XNAP_NULL;

    for (t_count = 0; t_count < 1; t_count++)
    {
        rtxDListAllocNodeAndData(p_asn1_ctx,
                                 e2ap_E2connectionUpdate_ItemIEs,
                                 &p_node_e2connectionupdate_item_ies,
                                 &p_E2connectionUpdate_ItemIEs);

        if (XNAP_P_NULL == p_node_e2connectionupdate_item_ies)
        {
            XNAP_TRACE(XNAP_ERROR, "%s:ASN malloc failed.", __FUNCTION__);
            return XNAP_FAILURE;
        }

        asn1Init_e2ap_E2connectionUpdate_ItemIEs(p_E2connectionUpdate_ItemIEs);
        p_E2connectionUpdate_ItemIEs->id = ASN1V_e2ap_id_E2connectionUpdate_Item;
        p_E2connectionUpdate_ItemIEs->criticality = e2ap_ignore;
        p_E2connectionUpdate_ItemIEs->value.t =  T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_ItemIEs_E2connectionUpdate_Item;
        p_E2connectionUpdate_ItemIEs->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item =
            rtxMemAllocType(p_asn1_ctx, e2ap_E2connectionUpdate_Item);
         
        if(XNAP_P_NULL == p_E2connectionUpdate_ItemIEs->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item)
        {
            XNAP_TRACE(XNAP_ERROR, "%s:ASN malloc failed.", __FUNCTION__);
            break;
        }
        asn1Init_e2ap_E2connectionUpdate_Item(
            p_E2connectionUpdate_ItemIEs->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item);

        if(XNAP_FAILURE == e2ap_compose_E2connectionUpdate_Item(p_asn1_ctx,
                                                                p_E2connectionUpdate_ItemIEs->value.u._e2apE2connectionUpdate_ItemIEs_E2connectionUpdate_Item))
        {
            XNAP_TRACE(XNAP_ERROR,
                       "%s: compose id-E2connectionUpdate-List",
                       __FUNCTION__);

            rtFreeContext(p_asn1_ctx);
            return XNAP_FAILURE;
        }
        rtxDListAppendNode(p_e2connectionupdate_list, p_node_e2connectionupdate_item_ies);
    }
    XNAP_UT_TRACE_EXIT();
    return XNAP_SUCCESS;
}

xnap_return_et e2ap_encode_e2connection_update(UInt8 *p_asn_msg, UInt16 *p_asn_msg_len)
{
    xnap_return_et retVal = XNAP_FAILURE;
    OSCTXT asn1_ctx;
    e2ap_E2AP_PDU e2ap_pdu;
    OSDListNode *p_node = GNB_PNULL;
    e2ap_E2connectionUpdate *p_E2connectionUpdate = XNAP_P_NULL;
    e2ap_E2connectionUpdate_protocolIEs_element *p_e2ap_protocolIE_elem = XNAP_P_NULL;
    /* Init ASN1 context */
    if (0 != rtInitContext(&asn1_ctx))
    {
        XNAP_TRACE(XNAP_ERROR, "%s: ASN context initialization failed.",
                   __FUNCTION__);
        XNAP_UT_TRACE_ENTER();
        return retVal;
    }do{
        XNAP_MEMSET(&e2ap_pdu, 0, sizeof(e2ap_E2AP_PDU));
        /* Fill the values in the ASN structures that shall be encoded by
         * ASN Encoder */

        /* Set Pdu type to Initiating message */
        e2ap_pdu.t = T_e2ap_E2AP_PDU_initiatingMessage; // --------------------> đổi nếu cần cho 3 loại message

        XNAP_TRACE(XNAP_DETAILED, "dungnm23 Alloc e2ap_E2connectionUpdate");

        e2ap_pdu.u.initiatingMessage = rtxMemAllocType(&asn1_ctx, e2ap_InitiatingMessage);

        if (XNAP_P_NULL == e2ap_pdu.u.initiatingMessage)
        {
            XNAP_TRACE(XNAP_INFO, "%s: ASN malloc failed.", __FUNCTION__);
            break;
        }
        asn1Init_e2ap_InitiatingMessage(e2ap_pdu.u.initiatingMessage);
        e2ap_pdu.u.initiatingMessage->procedureCode = ASN1V_e2ap_id_E2connectionUpdate; 
        e2ap_pdu.u.initiatingMessage->criticality = e2ap_reject;
        XNAP_TRACE(XNAP_DETAILED, "dungnm23 Alloc e2ap_E2connectionUpdate part 2");
        /* Set the initiating message type to E2connectionUpdate */
        e2ap_pdu.u.initiatingMessage->value.t =
            T_E2AP_PDU_Descriptions_e2ap_E2AP_ELEMENTARY_PROCEDURES_E2connectionUpdate;
        p_E2connectionUpdate = rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate);    
        if (XNAP_P_NULL == p_E2connectionUpdate) 
        {
            XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed.", __FUNCTION__);
            break;
        }else{
            XNAP_TRACE(XNAP_DETAILED, "Mem Alloc successful to e2ap_E2connectionUpdate");
        }

        asn1Init_e2ap_E2connectionUpdate(p_E2connectionUpdate);
        e2ap_pdu.u.initiatingMessage->value.u.e2ap_E2connectionUpdate = p_E2connectionUpdate;
        /* encode transaction id*/
        {
            rtxDListAllocNodeAndData(&asn1_ctx,
                                     e2ap_E2connectionUpdate_protocolIEs_element,
                                     &p_node,
                                     &p_e2ap_protocolIE_elem);
            if( XNAP_P_NULL == p_node)
            {
                /* Not enough memory */
                XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed.", __FUNCTION__);
                break;
            }

            asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_e2ap_protocolIE_elem);
            /* Fill the type of Protocol IE element */
            p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_TransactionID;
            p_e2ap_protocolIE_elem->criticality = e2ap_reject;
            p_e2ap_protocolIE_elem->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_TransactionID;
            p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_TransactionID = 45; // hardcode value để * ở đầu nếu sai
            rtxDListAppendNode(&p_E2connectionUpdate->protocolIEs, p_node);
            XNAP_TRACE(XNAP_DETAILED, "dungnm23, Alloc e2ap_E2connectionUpdate component");
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
        }

        /* encode E2connectionUpdateAdd*/

        {
            rtxDListAllocNodeAndData(&asn1_ctx,
                                     e2ap_E2connectionUpdate_protocolIEs_element,
                                     &p_node,
                                     &p_e2ap_protocolIE_elem);
            if( XNAP_P_NULL == p_node){
                /* Not enough memory */
                XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed.", __FUNCTION__);
                break;
            }         
            
            asn1Init_e2ap_E2connectionUpdate_protocolIEs_element(p_e2ap_protocolIE_elem);
            /* Fill the type of Protocol IE element */
            p_e2ap_protocolIE_elem->id = ASN1V_e2ap_id_E2connectionUpdateAdd;
            p_e2ap_protocolIE_elem->criticality = e2ap_reject;
            p_e2ap_protocolIE_elem->value.t = T_E2AP_PDU_Contents_e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd;
            p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd =
                rtxMemAllocType(&asn1_ctx, e2ap_E2connectionUpdate_List);
            if( XNAP_P_NULL == p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd){
                XNAP_TRACE(XNAP_ERROR, "%s: ASN malloc failed.", __FUNCTION__);
                break;
            }
            
            asn1Init_e2ap_E2connectionUpdate_List(p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd);
            if (XNAP_FAILURE == e2ap_compose_E2connectionUpdate_List(&asn1_ctx,
                                                                      p_e2ap_protocolIE_elem->value.u._e2ap_E2connectionUpdate_IEs_id_E2connectionUpdateAdd))
            {
                XNAP_TRACE(XNAP_ERROR,
                           "%s:compose id-E2connectionUpdateAdd returned Failure.",
                           __FUNCTION__);
                //rtFreeContext(&asn1_ctx);
                //XNAP_UT_TRACE_EXIT();
                return XNAP_FAILURE;
            }
            else
            {
                XNAP_TRACE(XNAP_DETAILED,
                           "compose id-E2connectionUpdateAdd returned Success.");
            }
            rtxDListAppendNode(&p_E2connectionUpdate->protocolIEs, p_node);
            XNAP_TRACE(XNAP_DETAILED, "dungnm23, Alloc e2ap_E2connectionUpdate component");
            rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
        }

        /* encode E2connectionUpdateRemove*/
        {
            
        }

        /* encode E2connectionUpdateModify*/

        {

        }
        /* ASN encode message*/
        {
            if(RT_OK!= pu_setBuffer(&asn1_ctx, p_asn_msg, XNAP_MAX_ASN1_BUF_SIZE, TRUE))
            {
                XNAP_TRACE(XNAP_ERROR, "%s: pu_setBuffer failed.", __FUNCTION__);
                break;
            }
            if (0!= asn1PE_e2ap_E2AP_PDU(&asn1_ctx, &e2ap_pdu))
            {
                XNAP_TRACE(XNAP_ERROR, "%s: ASN encoding failed.", __FUNCTION__);
                *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
                rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
                SInt8 buff[500];
                rtxErrGetTextBuff(&asn1_ctx, buff, 500);
                XNAP_TRACE(XNAP_ERROR,"BUFFER[%s], %x\n", (SInt8*) buff, buff);
                ASN_ERROR_PRINT(&asn1_ctx);
                break;
            }else{
                XNAP_TRACE(XNAP_DETAILED, "%s: ASN encoding successful.", __FUNCTION__);
                *p_asn_msg_len = (UInt16)pe_GetMsgLen(&asn1_ctx);
                rrc_asn1PrtToStr_E2AP_PDU(XNAP_ASN, "E2AP_PDU", &e2ap_pdu);
                retVal = XNAP_SUCCESS;
            }
        }
    }while(0);
    rtFreeContext(&asn1_ctx);
    XNAP_UT_TRACE_EXIT();
    return retVal;
}