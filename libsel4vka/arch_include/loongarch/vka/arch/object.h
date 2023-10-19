/*
 * Copyright 2018, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#pragma once

#include "kobject_t.h"
#include <vka/vka.h>
#include <vka/kobject_t.h>
#include <utils/util.h>

/*resource allocation interfaces for virtual machine extensions on LoongArch */
#ifdef CONFIG_LOONGARCH_HYPERVISOR_SUPPORT
static inline int vka_alloc_vcpu(vka_t *vka, vka_object_t *result)
{
    return vka_alloc_object(vka, seL4_LOONGARCH_VCPUObject, seL4_LOONGARCH_VCPUBits, result);
}

LEAKY(vcpu)
#endif

static inline int vka_alloc_vspace_root(vka_t *vka, vka_object_t *result)
{
    return vka_alloc_object(vka, kobject_get_type(KOBJECT_PAGE_DIRECTORY, 0), seL4_PageDirBits, result);
}


static inline unsigned long
vka_arch_get_object_size(seL4_Word objectType)
{
    switch (objectType) {
    case seL4_LOONGARCH_16K_Page:
        return seL4_PageBits;
    case seL4_LOONGARCH_Mega_Page:
        return seL4_LargePageBits;
#if CONFIG_PT_LEVELS > 2
    case seL4_LOONGARCH_Giga_Page:
        return seL4_HugePageBits;
#endif
#if CONFIG_PT_LEVELS > 3
    case seL4_LOONGARCH_Tera_Page:
        return seL4_TeraPageBits;
#endif
    case seL4_LOONGARCH_PageTableObject:
        return seL4_PageTableBits;
#ifdef CONFIG_LOONGARCH_HYPERVISOR_SUPPORT
    case seL4_LOONGARCH_VCPUObject:
        return seL4_LOONGARCH_VCPUBits;
#endif /* CONFIG_LOONGARCH_HYPERVISOR_SUPPORT */ 

    default:
         ZF_LOGE("Unknown object type %ld", (long)objectType);
         return -1;
    }
}

