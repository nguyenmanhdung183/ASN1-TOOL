/* --- Init container struct (not malloc, because it's embedded) --- */
asn1Init_e2ap_TNLinformation(&p_e2connectionupdate_item->tnlInformation);

/* Mark presence of tnlAddress */
p_e2connectionupdate_item->tnlInformation.m.tnlAddressPresent = 1;

/* Init dynamic BIT STRING structure */
asn1Init_e2ap_TNLinformation_tnlAddress(
    &p_e2connectionupdate_item->tnlInformation.tnlAddress);

/* Hardcode IPv4 192.168.0.9 → 32 bits */
OSUINT32 numbits = 32;
size_t nbytes = (numbits + 7) / 8;

/* Set numbits */
p_e2connectionupdate_item->tnlInformation.tnlAddress.numbits = numbits;

/* Allocate dynamic buffer (same style as sample code) */
p_e2connectionupdate_item->tnlInformation.tnlAddress.data =
    (OSOCTET*) rtxMemAllocZ(p_asn1_ctx, nbytes);

if (p_e2connectionupdate_item->tnlInformation.tnlAddress.data == NULL) {
    XNAP_TRACE(XNAP_ERROR, "Malloc failed: tnlAddress.data");
    return XNAP_FAILURE;
}

/* Hardcoded byte array */
OSOCTET ipv4_addr[4] = {192, 168, 0, 9};

/* Copy to BIT STRING buffer (same style as your sample) */
XNAP_MEMCPY(
    p_e2connectionupdate_item->tnlInformation.tnlAddress.data,
    ipv4_addr,
    nbytes
);
