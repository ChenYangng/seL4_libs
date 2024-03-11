/*
 * Copyright 2018, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#pragma once

#include "sel4/arch/types.h"
#include <stdint.h>
#include <sel4/sel4.h>

#define EXCEPT_IPC_SYS_MR_IP EXCEPT_IPC_SYS_MR_RIP
#define ARCH_SYSCALL_INSTRUCTION_SIZE 4

static inline int sel4utils_is_read_fault(void)
{
    seL4_Word fsr = seL4_GetMR(seL4_VMFault_FSR);
    /* 目前没考虑特权等级无效例外，这可能是read或write触发的 */
    return (fsr == 1 || fsr == 3 || fsr == 5 || fsr == 6);
}

static inline void sel4utils_set_instruction_pointer(seL4_UserContext *regs,
                                                     seL4_Word value)
{
    regs->pc = value;
}

static inline seL4_Word sel4utils_get_instruction_pointer(seL4_UserContext regs)
{
    return regs.pc;
}

static inline void sel4utils_set_stack_pointer(seL4_UserContext *regs,
                                               seL4_Word value)
{
    regs->sp = value;
}

static inline seL4_Word sel4utils_get_ra(seL4_UserContext regs)
{
    return regs.ra;
}

static inline seL4_Word sel4utils_get_tp(seL4_UserContext regs)
{
    return regs.tp;
}

static inline seL4_Word sel4utils_get_sp(seL4_UserContext regs)
{
    return regs.sp;
}

static inline seL4_Word sel4utils_get_a0(seL4_UserContext regs)
{
    return regs.a0;
}

static inline seL4_Word sel4utils_get_a1(seL4_UserContext regs)
{
    return regs.a1;
}

static inline seL4_Word sel4utils_get_a2(seL4_UserContext regs)
{
    return regs.a2;
}

static inline seL4_Word sel4utils_get_a3(seL4_UserContext regs)
{
    return regs.a3;
}

static inline seL4_Word sel4utils_get_a4(seL4_UserContext regs)
{
    return regs.a4;
}

static inline seL4_Word sel4utils_get_a5(seL4_UserContext regs)
{
    return regs.a5;
}

static inline seL4_Word sel4utils_get_a6(seL4_UserContext regs)
{
    return regs.a6;
}

static inline seL4_Word sel4utils_get_a7(seL4_UserContext regs)
{
    return regs.a7;
}

static inline seL4_Word sel4utils_get_t0(seL4_UserContext regs)
{
    return regs.t0;
}

static inline seL4_Word sel4utils_get_t1(seL4_UserContext regs)
{
    return regs.t1;
}

static inline seL4_Word sel4utils_get_t2(seL4_UserContext regs)
{
    return regs.t2;
}

static inline seL4_Word sel4utils_get_t3(seL4_UserContext regs)
{
    return regs.t3;
}

static inline seL4_Word sel4utils_get_t4(seL4_UserContext regs)
{
    return regs.t4;
}

static inline seL4_Word sel4utils_get_t5(seL4_UserContext regs)
{
    return regs.t5;
}

static inline seL4_Word sel4utils_get_t6(seL4_UserContext regs)
{
    return regs.t6;
}

static inline seL4_Word sel4utils_get_t7(seL4_UserContext regs)
{
    return regs.t7;
}

static inline seL4_Word sel4utils_get_t8(seL4_UserContext regs)
{
    return regs.t8;
}

static inline seL4_Word sel4utils_get_fp(seL4_UserContext regs)
{
    return regs.fp;
}

static inline seL4_Word sel4utils_get_s0(seL4_UserContext regs)
{
    return regs.s0;
}

static inline seL4_Word sel4utils_get_s1(seL4_UserContext regs)
{
    return regs.s1;
}

static inline seL4_Word sel4utils_get_s2(seL4_UserContext regs)
{
    return regs.s2;
}

static inline seL4_Word sel4utils_get_s3(seL4_UserContext regs)
{
    return regs.s3;
}

static inline seL4_Word sel4utils_get_s4(seL4_UserContext regs)
{
    return regs.s4;
}

static inline seL4_Word sel4utils_get_s5(seL4_UserContext regs)
{
    return regs.s5;
}

static inline seL4_Word sel4utils_get_s6(seL4_UserContext regs)
{
    return regs.s6;
}

static inline seL4_Word sel4utils_get_s7(seL4_UserContext regs)
{
    return regs.s7;
}

static inline seL4_Word sel4utils_get_s8(seL4_UserContext regs)
{
    return regs.s8;
}

static inline seL4_Word sel4utils_reg_get_val(seL4_UserContext regs, seL4_Word num)
{
    switch (num) {
        case 1:
            return sel4utils_get_ra(regs);
        case 2:
            return sel4utils_get_tp(regs);
        case 3:
            return sel4utils_get_sp(regs);
        case 4:
            return sel4utils_get_a0(regs);
        case 5:
            return sel4utils_get_a1(regs);
        case 6:
            return sel4utils_get_a2(regs);
        case 7:
            return sel4utils_get_a3(regs);
        case 8:
            return sel4utils_get_a4(regs);
        case 9:
            return sel4utils_get_a5(regs);
        case 10:
            return sel4utils_get_a6(regs);
        case 11:
            return sel4utils_get_a7(regs);
        case 12:
            return sel4utils_get_t0(regs);
        case 13:
            return sel4utils_get_t1(regs);
        case 14:
            return sel4utils_get_t2(regs);
        case 15:
            return sel4utils_get_t3(regs);
        case 16:
            return sel4utils_get_t4(regs);
        case 17:
            return sel4utils_get_t5(regs);
        case 18:
            return sel4utils_get_t6(regs);
        case 19:
            return sel4utils_get_t7(regs);
        case 20:
            return sel4utils_get_t8(regs);
        case 22:
            return sel4utils_get_fp(regs);
        case 23:
            return sel4utils_get_s0(regs);
        case 24:
            return sel4utils_get_s1(regs);
        case 25:
            return sel4utils_get_s2(regs);
        case 26:
            return sel4utils_get_s3(regs);
        case 27:
            return sel4utils_get_s4(regs);
        case 28:
            return sel4utils_get_s5(regs);
        case 29:
            return sel4utils_get_s6(regs);
        case 30:
            return sel4utils_get_s7(regs);
        case 31:
            return sel4utils_get_s8(regs);
        default:
            return 0;
    }
}

static inline void sel4utils_set_ra(seL4_UserContext *regs, seL4_Word value)
{
    regs->ra = value;
}

static inline void sel4utils_set_tp(seL4_UserContext *regs, seL4_Word value)
{
    regs->tp = value;
}

static inline void sel4utils_set_sp(seL4_UserContext *regs, seL4_Word value)
{
    regs->sp = value;
}

static inline void sel4utils_set_a0(seL4_UserContext *regs, seL4_Word value)
{
    regs->a0 = value;
}

static inline void sel4utils_set_a1(seL4_UserContext *regs, seL4_Word value)
{
    regs->a1 = value;
}

static inline void sel4utils_set_a2(seL4_UserContext *regs, seL4_Word value)
{
    regs->a2 = value;
}

static inline void sel4utils_set_a3(seL4_UserContext *regs, seL4_Word value)
{
    regs->a3 = value;
}

static inline void sel4utils_set_a4(seL4_UserContext *regs, seL4_Word value)
{
    regs->a4 = value;
}

static inline void sel4utils_set_a5(seL4_UserContext *regs, seL4_Word value)
{
    regs->a5 = value;
}

static inline void sel4utils_set_a6(seL4_UserContext *regs, seL4_Word value)
{
    regs->a6 = value;
}

static inline void sel4utils_set_a7(seL4_UserContext *regs, seL4_Word value)
{
    regs->a7 = value;
}

static inline void sel4utils_set_t0(seL4_UserContext *regs, seL4_Word value)
{
    regs->t0 = value;
}

static inline void sel4utils_set_t1(seL4_UserContext *regs, seL4_Word value)
{
    regs->t1 = value;
}

static inline void sel4utils_set_t2(seL4_UserContext *regs, seL4_Word value)
{
    regs->t2 = value;
}

static inline void sel4utils_set_t3(seL4_UserContext *regs, seL4_Word value)
{
    regs->t3 = value;
}

static inline void sel4utils_set_t4(seL4_UserContext *regs, seL4_Word value)
{
    regs->t4 = value;
}

static inline void sel4utils_set_t5(seL4_UserContext *regs, seL4_Word value)
{
    regs->t5 = value;
}

static inline void sel4utils_set_t6(seL4_UserContext *regs, seL4_Word value)
{
    regs->t6 = value;
}

static inline void sel4utils_set_t7(seL4_UserContext *regs, seL4_Word value)
{
    regs->t7 = value;
}

static inline void sel4utils_set_t8(seL4_UserContext *regs, seL4_Word value)
{
    regs->t8 = value;
}

static inline void sel4utils_set_fp(seL4_UserContext *regs, seL4_Word value)
{
    regs->fp = value;
}

static inline void sel4utils_set_s0(seL4_UserContext *regs, seL4_Word value)
{
    regs->s0 = value;
}

static inline void sel4utils_set_s1(seL4_UserContext *regs, seL4_Word value)
{
    regs->s1 = value;
}

static inline void sel4utils_set_s2(seL4_UserContext *regs, seL4_Word value)
{
    regs->s2 = value;
}

static inline void sel4utils_set_s3(seL4_UserContext *regs, seL4_Word value)
{
    regs->s3 = value;
}

static inline void sel4utils_set_s4(seL4_UserContext *regs, seL4_Word value)
{
    regs->s4 = value;
}

static inline void sel4utils_set_s5(seL4_UserContext *regs, seL4_Word value)
{
    regs->s5 = value;
}

static inline void sel4utils_set_s6(seL4_UserContext *regs, seL4_Word value)
{
    regs->s6 = value;
}

static inline void sel4utils_set_s7(seL4_UserContext *regs, seL4_Word value)
{
    regs->s7 = value;
}

static inline void sel4utils_set_s8(seL4_UserContext *regs, seL4_Word value)
{
    regs->s8 = value;
}

static inline void sel4utils_reg_set_val(seL4_UserContext *regs, seL4_Word num, seL4_Word value)
{
    switch (num) {
        case 1:
            sel4utils_set_ra(regs, value);
            break;
        case 2:
            sel4utils_set_tp(regs, value);
            break;
        case 3:
            sel4utils_set_sp(regs, value);
            break;
        case 4:
            sel4utils_set_a0(regs, value);
            break;
        case 5:
            sel4utils_set_a1(regs, value);
            break;
        case 6:
            sel4utils_set_a2(regs, value);
            break;
        case 7:
            sel4utils_set_a3(regs, value);
            break;
        case 8:
            sel4utils_set_a4(regs, value);
            break;
        case 9:
            sel4utils_set_a5(regs, value);
            break;
        case 10:
            sel4utils_set_a6(regs, value);
            break;
        case 11:
            sel4utils_set_a7(regs, value);
            break;
        case 12:
            sel4utils_set_t0(regs, value);
            break;
        case 13:
            sel4utils_set_t1(regs, value);
            break;
        case 14:
            sel4utils_set_t2(regs, value);
            break;
        case 15:
            sel4utils_set_t3(regs, value);
            break;
        case 16:
            sel4utils_set_t4(regs, value);
            break;
        case 17:
            sel4utils_set_t5(regs, value);
            break;
        case 18:
            sel4utils_set_t6(regs, value);
            break;
        case 19:
            sel4utils_set_t7(regs, value);
            break;
        case 20:
            sel4utils_set_t8(regs, value);
            break;
        case 22:
            sel4utils_set_fp(regs, value);
            break;
        case 23:
            sel4utils_set_s0(regs, value);
            break;
        case 24:
            sel4utils_set_s1(regs, value);
            break;
        case 25:
            sel4utils_set_s2(regs, value);
            break;
        case 26:
            sel4utils_set_s3(regs, value);
            break;
        case 27:
            sel4utils_set_s4(regs, value);
            break;
        case 28:
            sel4utils_set_s5(regs, value);
            break;
        case 29:
            sel4utils_set_s6(regs, value);
            break;
        case 30:
            sel4utils_set_s7(regs, value);
            break;
        case 31:
            sel4utils_set_s8(regs, value);
            break;
        default:
            break;
    }
}
