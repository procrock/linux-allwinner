/* This is an autogenerated file */
/* Tag: noCheckHeader */
/*    Copyright (C) Cambridge Silicon Radio Ltd 2009. All rights reserved. */
/* */
/*   Refer to LICENSE.txt included with this source for details on the */
/*   license terms. */

/* STANDARD INCLUDES *********************************************************/
#include "ie_utils/ie_utils.h"
#include "ie_access/ie_wpa.h"

/* PUBLIC FUNCTION DEFINITIONS ***********************************************/

ie_result ie_get_wpa(CsrUint8* elements, CsrUint32 length, ie_wpa* wpa)
{
    CsrUint8 *pBuf;
    CsrUint8 *pStart;

    ie_result result = ie_find_vendor_specific(ieWpaOui, ieWpaOuiSubtype, 1, elements, length, &pBuf);

    if (result != ie_success)
    {
        return result;
    }

    pStart = pBuf; /* track the start of the IE as used to ensure we don't read pass the end of it*/
    wpa->header = (struct wpa_header*)pBuf;
    pBuf += sizeof(struct wpa_header);

    /* bytelength: pw_cipher_pair*/
    if ((pBuf - pStart) < wpa->header->length)
    {
        wpa->pwCipherPair = (struct wpa_pwCipherPair *)pBuf;
        pBuf+=2;
        pBuf+= (ie_2_byte_array_to_csruint8(wpa->pwCipherPair->pwCipherCount) * 4);

    }
    else
    {
        wpa->pwCipherPair = NULL;
    }

    /* bytelength: AKM_cipher_pair*/
    if ((pBuf - pStart) < wpa->header->length)
    {
        wpa->akmCipherPair = (struct wpa_akmCipherPair *)pBuf;
        pBuf+=2;
        pBuf+= (ie_2_byte_array_to_csruint8(wpa->akmCipherPair->akmCipherCount) * 4);

    }
    else
    {
        wpa->akmCipherPair = NULL;
    }

    wpa->body1 = (struct wpa_body1 *)pBuf;

    return result;
}



