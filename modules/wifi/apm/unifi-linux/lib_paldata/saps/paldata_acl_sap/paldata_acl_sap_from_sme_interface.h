/* This is an autogenerated file */
/* Tag: noCheckHeader */

/*    CONFIDENTIAL */
/*    Copyright (C) Cambridge Silicon Radio Ltd 2008. All rights reserved. */

#ifndef PALDATA_ACL_OUTPUT_H
#define PALDATA_ACL_OUTPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SME_API_VALIDATE

#define call_pal_acl_data_ind(context, dataLength, data, physicalLinkHandle, aclOffset, freeFunction) CSR_UNUSED(dataLength), CSR_UNUSED(data), CSR_UNUSED(physicalLinkHandle), CSR_UNUSED(aclOffset), CSR_UNUSED(freeFunction)

#else

#include "paldata_acl_sap/paldata_acl_sap.h"

#ifdef FSM_TRANSITION_LOCK

#define call_pal_acl_data_ind(context, p_dataLength, p_data, p_physicalLinkHandle, p_aclOffset, p_freeFunction) \
    (void)CsrMutexUnlock(context->transitionLock); \
    sme_trace_msc((TR_MSC, "MSC MESSAGE :: From(%s) Event(PAL_ACL_DATA_IND) To(env)",\
        fsm_current_process_name((context))    ));\
    pal_acl_data_ind(context->externalContext, p_dataLength, p_data, p_physicalLinkHandle, p_aclOffset, p_freeFunction); \
    (void)CsrMutexLock(context->transitionLock);


#else

#define call_pal_acl_data_ind(context, p_dataLength, p_data, p_physicalLinkHandle, p_aclOffset, p_freeFunction) \
    sme_trace_msc((TR_MSC, "MSC MESSAGE :: From(%s) Event(PAL_ACL_DATA_IND) To(env)", \
                   fsm_current_process_name((context)))); \
    pal_acl_data_ind(context->externalContext, p_dataLength, p_data, p_physicalLinkHandle, p_aclOffset, p_freeFunction);


#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* PALDATA_ACL_OUTPUT_H */
