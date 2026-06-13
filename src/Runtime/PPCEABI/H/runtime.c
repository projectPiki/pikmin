#include "PowerPC_EABI_Support/Runtime/runtime.h"

void _savefpr_14(void);
void _savefpr_15(void);
void _savefpr_16(void);
void _savefpr_17(void);
void _savefpr_18(void);
void _savefpr_19(void);
void _savefpr_20(void);
void _savefpr_21(void);
void _savefpr_22(void);
void _savefpr_23(void);
void _savefpr_24(void);
void _savefpr_25(void);
void _savefpr_26(void);
void _savefpr_27(void);
void _savefpr_28(void);
void _savefpr_29(void);
void _savefpr_30(void);
void _savefpr_31(void);

void _restfpr_14(void);
void _restfpr_15(void);
void _restfpr_16(void);
void _restfpr_17(void);
void _restfpr_18(void);
void _restfpr_19(void);
void _restfpr_20(void);
void _restfpr_21(void);
void _restfpr_22(void);
void _restfpr_23(void);
void _restfpr_24(void);
void _restfpr_25(void);
void _restfpr_26(void);
void _restfpr_27(void);
void _restfpr_28(void);
void _restfpr_29(void);
void _restfpr_30(void);
void _restfpr_31(void);

void _savegpr_14(void);
void _savegpr_15(void);
void _savegpr_16(void);
void _savegpr_17(void);
void _savegpr_18(void);
void _savegpr_19(void);
void _savegpr_20(void);
void _savegpr_21(void);
void _savegpr_22(void);
void _savegpr_23(void);
void _savegpr_24(void);
void _savegpr_25(void);
void _savegpr_26(void);
void _savegpr_27(void);
void _savegpr_28(void);
void _savegpr_29(void);
void _savegpr_30(void);
void _savegpr_31(void);

void _restgpr_14(void);
void _restgpr_15(void);
void _restgpr_16(void);
void _restgpr_17(void);
void _restgpr_18(void);
void _restgpr_19(void);
void _restgpr_20(void);
void _restgpr_21(void);
void _restgpr_22(void);
void _restgpr_23(void);
void _restgpr_24(void);
void _restgpr_25(void);
void _restgpr_26(void);
void _restgpr_27(void);
void _restgpr_28(void);
void _restgpr_29(void);
void _restgpr_30(void);
void _restgpr_31(void);

void __savev20(void);
void __savev21(void);
void __savev22(void);
void __savev23(void);
void __savev24(void);
void __savev25(void);
void __savev26(void);
void __savev27(void);
void __savev28(void);
void __savev29(void);
void __savev30(void);
void __savev31(void);

void __restv20(void);
void __restv21(void);
void __restv22(void);
void __restv23(void);
void __restv24(void);
void __restv25(void);
void __restv26(void);
void __restv27(void);
void __restv28(void);
void __restv29(void);
void __restv30(void);
void __restv31(void);

static const u32 __constants[] = {
	0x00000000, 0x00000000, 0x41F00000, 0x00000000, 0x41E00000, 0x00000000,
};

/**
 * @TODO: Documentation
 */
ASM u32 __cvt_fp2unsigned(register f64 d)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	stwu    r1, -16 (r1)
	lis     r4,     __constants @h
	ori     r4, r4, __constants @l
	li      r3, 0
	lfd     fp0, 0 (r4)
	lfd     fp3, 8 (r4)
	lfd     fp4, 16 (r4)
	fcmpu   cr0, fp1, fp0
	fcmpu   cr6, fp1, fp3
	blt     cr0, @exit
	addi    r3, r3, -1
	bge     cr6, @exit
	fcmpu   cr7, fp1, fp4
	fmr     fp2, fp1
	blt     cr7, @1
	fsub    fp2, fp1, fp4
@1	fctiwz  fp2, fp2
	stfd    fp2, 8 (r1)
	lwz     r3, 12 (r1)
	blt     cr7, @exit
	addis   r3, r3, -0x8000
@exit:
	addi    r1, r1, 16
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
ASM static void __save_fpr(void)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
entry _savefpr_14
	stfd  fp14, -144 (r11)
entry _savefpr_15
	stfd  fp15, -136 (r11)
entry _savefpr_16
	stfd  fp16, -128 (r11)
entry _savefpr_17
	stfd  fp17, -120 (r11)
entry _savefpr_18
	stfd  fp18, -112 (r11)
entry _savefpr_19
	stfd  fp19, -104 (r11)
entry _savefpr_20
	stfd  fp20, -96 (r11)
entry _savefpr_21
	stfd  fp21, -88 (r11)
entry _savefpr_22
	stfd  fp22, -80 (r11)
entry _savefpr_23
	stfd  fp23, -72 (r11)
entry _savefpr_24
	stfd  fp24, -64 (r11)
entry _savefpr_25
	stfd  fp25, -56 (r11)
entry _savefpr_26
	stfd  fp26, -48 (r11)
entry _savefpr_27
	stfd  fp27, -40 (r11)
entry _savefpr_28
	stfd  fp28, -32 (r11)
entry _savefpr_29
	stfd  fp29, -24 (r11)
entry _savefpr_30
	stfd  fp30, -16 (r11)
entry _savefpr_31
	stfd  fp31, -8 (r11)
	blr
#endif // clang-format on
}

#pragma altivec_model on

/**
 * @brief Stores AltiVec vector registers to the stack.  Used with `-vector on`, which is invalid for GCN/Wii.
 * @note UNUSED Size: 000064 (Matching by size)
 */
ASM static void _savevr(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
entry __savev20
	li    r12, -0xC0
	stvx  v20, r12, r0
entry __savev21
	li    r12, -0xB0
	stvx  v21, r12, r0
entry __savev22
	li    r12, -0xA0
	stvx  v22, r12, r0
entry __savev23
	li    r12, -0x90
	stvx  v23, r12, r0
entry __savev24
	li    r12, -0x80
	stvx  v24, r12, r0
entry __savev25
	li    r12, -0x70
	stvx  v25, r12, r0
entry __savev26
	li    r12, -0x60
	stvx  v26, r12, r0
entry __savev27
	li    r12, -0x50
	stvx  v27, r12, r0
entry __savev28
	li    r12, -0x40
	stvx  v28, r12, r0
entry __savev29
	li    r12, -0x30
	stvx  v29, r12, r0
entry __savev30
	li    r12, -0x20
	stvx  v30, r12, r0
entry __savev31
	li    r12, -0x10
	stvx  v31, r12, r0
	blr
#endif // clang-format on
}

#pragma altivec_model off

/**
 * @TODO: Documentation
 */
ASM static void __restore_fpr(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
entry _restfpr_14
	lfd  fp14, -144 (r11)
entry _restfpr_15
	lfd  fp15, -136 (r11)
entry _restfpr_16
	lfd  fp16, -128 (r11)
entry _restfpr_17
	lfd  fp17, -120 (r11)
entry _restfpr_18
	lfd  fp18, -112 (r11)
entry _restfpr_19
	lfd  fp19, -104 (r11)
entry _restfpr_20
	lfd  fp20, -96 (r11)
entry _restfpr_21
	lfd  fp21, -88 (r11)
entry _restfpr_22
	lfd  fp22, -80 (r11)
entry _restfpr_23
	lfd  fp23, -72 (r11)
entry _restfpr_24
	lfd  fp24, -64 (r11)
entry _restfpr_25
	lfd  fp25, -56 (r11)
entry _restfpr_26
	lfd  fp26, -48 (r11)
entry _restfpr_27
	lfd  fp27, -40 (r11)
entry _restfpr_28
	lfd  fp28, -32 (r11)
entry _restfpr_29
	lfd  fp29, -24 (r11)
entry _restfpr_30
	lfd  fp30, -16 (r11)
entry _restfpr_31
	lfd  fp31, -8 (r11)
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
 */
ASM static void __save_gpr(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
entry _savegpr_14
	stw  r14, -72 (r11)
entry _savegpr_15
	stw  r15, -68 (r11)
entry _savegpr_16
	stw  r16, -64 (r11)
entry _savegpr_17
	stw  r17, -60 (r11)
entry _savegpr_18
	stw  r18, -56 (r11)
entry _savegpr_19
	stw  r19, -52 (r11)
entry _savegpr_20
	stw  r20, -48 (r11)
entry _savegpr_21
	stw  r21, -44 (r11)
entry _savegpr_22
	stw  r22, -40 (r11)
entry _savegpr_23
	stw  r23, -36 (r11)
entry _savegpr_24
	stw  r24, -32 (r11)
entry _savegpr_25
	stw  r25, -28 (r11)
entry _savegpr_26
	stw  r26, -24 (r11)
entry _savegpr_27
	stw  r27, -20 (r11)
entry _savegpr_28
	stw  r28, -16 (r11)
entry _savegpr_29
	stw  r29, -12 (r11)
entry _savegpr_30
	stw  r30, -8 (r11)
entry _savegpr_31
	stw  r31, -4 (r11)
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
 */
ASM static void __restore_gpr(void)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
entry _restgpr_14
	lwz  r14, -72 (r11)
entry _restgpr_15
	lwz  r15, -68 (r11)
entry _restgpr_16
	lwz  r16, -64 (r11)
entry _restgpr_17
	lwz  r17, -60 (r11)
entry _restgpr_18
	lwz  r18, -56 (r11)
entry _restgpr_19
	lwz  r19, -52 (r11)
entry _restgpr_20
	lwz  r20, -48 (r11)
entry _restgpr_21
	lwz  r21, -44 (r11)
entry _restgpr_22
	lwz  r22, -40 (r11)
entry _restgpr_23
	lwz  r23, -36 (r11)
entry _restgpr_24
	lwz  r24, -32 (r11)
entry _restgpr_25
	lwz  r25, -28 (r11)
entry _restgpr_26
	lwz  r26, -24 (r11)
entry _restgpr_27
	lwz  r27, -20 (r11)
entry _restgpr_28
	lwz  r28, -16 (r11)
entry _restgpr_29
	lwz  r29, -12 (r11)
entry _restgpr_30
	lwz  r30, -8 (r11)
entry _restgpr_31
	lwz  r31, -4 (r11)
	blr
#endif // clang-format on
}

#pragma altivec_model on

/**
 * @brief Loads AltiVec vector registers from the stack.  Used with `-vector on`, which is invalid for GCN/Wii.
 * @note UNUSED Size: 000064 (Matching by size)
 */
ASM static void _restorevr(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
entry __restv20
	li   r12, -0xC0
	lvx  v20, r12, r0
entry __restv21
	li   r12, -0xB0
	lvx  v21, r12, r0
entry __restv22
	li   r12, -0xA0
	lvx  v22, r12, r0
entry __restv23
	li   r12, -0x90
	lvx  v23, r12, r0
entry __restv24
	li   r12, -0x80
	lvx  v24, r12, r0
entry __restv25
	li   r12, -0x70
	lvx  v25, r12, r0
entry __restv26
	li   r12, -0x60
	lvx  v26, r12, r0
entry __restv27
	li   r12, -0x50
	lvx  v27, r12, r0
entry __restv28
	li   r12, -0x40
	lvx  v28, r12, r0
entry __restv29
	li   r12, -0x30
	lvx  v29, r12, r0
entry __restv30
	li   r12, -0x20
	lvx  v30, r12, r0
entry __restv31
	li   r12, -0x10
	lvx  v31, r12, r0
	blr
#endif // clang-format on
}

#pragma altivec_model off

/**
 * @TODO: Documentation
 */
ASM void __div2u(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	cmpwi   r3, 0
	cntlzw  r0, r3
	cntlzw  r9, r4
	bne     lab1
	addi    r0, r9, 32
lab1:
	cmpwi   r5, 0
	cntlzw  r9, r5
	cntlzw  r10, r6
	bne     lab2
	addi    r9, r10, 32
lab2:
	cmpw    r0, r9
	subfic  r10, r0, 64
	bgt     lab9
	addi    r9, r9, 1
	subfic  r9, r9, 64
	add     r0, r0, r9
	subf    r9, r9, r10
	mtctr   r9
	cmpwi   r9, 32
	addi    r7, r9, -32
	blt     lab3
	srw     r8, r3, r7
	li      r7, 0
	b       lab4
lab3:
	srw     r8, r4, r9
	subfic  r7, r9, 32
	slw     r7, r3, r7
	or      r8, r8, r7
	srw     r7, r3, r9
lab4:
	cmpwi   r0, 32
	addic   r9, r0, -32
	blt     lab5
	slw     r3, r4, r9
	li      r4, 0
	b       lab6
lab5:
	slw     r3, r3, r0
	subfic  r9, r0, 32
	srw     r9, r4, r9
	or      r3, r3, r9
	slw     r4, r4, r0
lab6:
	li      r10, -1
	addic   r7, r7, 0
lab7:
	adde    r4, r4, r4
	adde    r3, r3, r3
	adde    r8, r8, r8
	adde    r7, r7, r7
	subfc   r0, r6, r8
	subfe.  r9, r5, r7
	blt     lab8
	mr      r8, r0
	mr      r7, r9
	addic   r0, r10,1
lab8:
	bdnz    lab7
	adde    r4, r4, r4
	adde    r3, r3, r3
	blr
lab9:
	li      r4, 0
	li      r3, 0
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */

ASM void __div2i(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	stwu     r1, -16 (r1)
	rlwinm.  r9, r3, 0, 0, 0
	beq      positive1
	subfic   r4, r4, 0
	subfze   r3, r3
positive1:
	stw      r9, 8 (r1)
	rlwinm.  r9, r5, 0, 0, 0
	beq      positive2
	subfic   r6, r6, 0
	subfze   r5, r5
positive2:
	stw      r9, 12 (r1)
	cmpwi    r3, 0
	cntlzw   r0, r3
	cntlzw   r9, r4
	bne      lab1
	addi     r0, r9, 32
lab1:
	cmpwi    r5, 0
	cntlzw   r9, r5
	cntlzw   r10, r6
	bne      lab2
	addi     r9, r10, 32
lab2:
	cmpw     r0, r9
	subfic   r10, r0, 64
	bgt      lab9
	addi     r9, r9, 1
	subfic   r9, r9, 64
	add      r0, r0, r9
	subf     r9, r9, r10
	mtctr    r9
	cmpwi    r9, 32
	addi     r7, r9, -32
	blt      lab3
	srw      r8, r3, r7
	li       r7, 0
	b        lab4
lab3:
	srw      r8, r4, r9
	subfic   r7, r9, 32
	slw      r7, r3, r7
	or       r8, r8, r7
	srw      r7, r3, r9
lab4:
	cmpwi    r0, 32
	addic    r9, r0, -32
	blt      lab5
	slw      r3, r4, r9
	li       r4, 0
	b        lab6
lab5:
	slw      r3, r3, r0
	subfic   r9, r0, 32
	srw      r9, r4, r9
	or       r3, r3, r9
	slw      r4, r4, r0
lab6:
	li       r10, -1
	addic    r7, r7, 0
lab7:
	adde     r4, r4, r4
	adde     r3, r3, r3
	adde     r8, r8, r8
	adde     r7, r7, r7
	subfc    r0, r6, r8
	subfe.   r9, r5, r7
	blt      lab8
	mr       r8, r0
	mr       r7, r9
	addic    r0, r10, 1
lab8:
	bdnz     lab7
	adde     r4, r4, r4
	adde     r3, r3, r3
	lwz      r9, 8 (r1)
	lwz      r10, 12 (r1)
	xor.     r7, r9, r10
	beq      no_adjust
	cmpwi    r9, 0
	subfic   r4, r4, 0
	subfze   r3, r3

no_adjust:
	b        func_end

lab9:
	li       r4, 0
	li       r3, 0
func_end:
	addi     r1, r1, 16
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
ASM void __mod2u(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	cmpwi   r3, 0
	cntlzw  r0, r3
	cntlzw  r9, r4
	bne     lab1
	addi    r0, r9, 32
lab1:
	cmpwi   r5, 0
	cntlzw  r9, r5
	cntlzw  r10, r6
	bne     lab2
	addi    r9, r10, 32
lab2:
	cmpw    r0, r9
	subfic  r10, r0, 64
	bgt     lab9
	addi    r9, r9, 1
	subfic  r9, r9, 64
	add     r0, r0, r9
	subf    r9, r9, r10
	mtctr   r9
	cmpwi   r9, 32
	addi    r7, r9, -32
	blt     lab3
	srw     r8, r3, r7
	li      r7, 0
	b       lab4
lab3:
	srw     r8, r4, r9
	subfic  r7, r9, 32
	slw     r7, r3, r7
	or      r8, r8, r7
	srw     r7, r3, r9
lab4:
	cmpwi   r0, 32
	addic   r9, r0, -32
	blt     lab5
	slw     r3, r4, r9
	li      r4, 0
	b       lab6
lab5:
	slw     r3, r3, r0
	subfic  r9, r0, 32
	srw     r9, r4, r9
	or      r3, r3, r9
	slw     r4, r4, r0
lab6:
	li      r10, -1
	addic   r7, r7, 0
lab7:
	adde    r4, r4, r4
	adde    r3, r3, r3
	adde    r8, r8, r8
	adde    r7, r7, r7
	subfc   r0, r6, r8
	subfe.  r9, r5, r7
	blt     lab8
	mr      r8, r0
	mr      r7, r9
	addic   r0, r10, 1
lab8:
	bdnz    lab7
	mr      r4, r8
	mr      r3, r7
	blr
lab9:
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
ASM void __mod2i(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc

	cmpwi   cr7, r3, 0
	bge     cr7, positive1
	subfic  r4, r4, 0
	subfze  r3, r3
positive1:
	cmpwi   r5, 0
	bge     positive2
	subfic  r6, r6, 0
	subfze  r5, r5
positive2:
	cmpwi   r3, 0
	cntlzw  r0, r3
	cntlzw  r9, r4
	bne     lab1
	addi    r0, r9, 32
lab1:
	cmpwi   r5, 0
	cntlzw  r9, r5
	cntlzw  r10, r6
	bne     lab2
	addi    r9, r10, 32
lab2:
	cmpw    r0, r9
	subfic  r10, r0, 64
	bgt     lab9
	addi    r9, r9, 1
	subfic  r9, r9, 64
	add     r0, r0, r9
	subf    r9, r9, r10
	mtctr   r9
	cmpwi   r9, 32
	addi    r7, r9, -32
	blt     lab3
	srw     r8, r3, r7
	li      r7, 0
	b       lab4
lab3:
	srw     r8, r4, r9
	subfic  r7, r9, 32
	slw     r7, r3, r7
	or      r8, r8, r7
	srw     r7, r3, r9
lab4:
	cmpwi   r0, 32
	addic   r9, r0, -32
	blt     lab5
	slw     r3, r4, r9
	li      r4, 0
	b       lab6
lab5:
	slw     r3, r3, r0
	subfic  r9, r0, 32
	srw     r9, r4, r9
	or      r3, r3, r9
	slw     r4, r4, r0
lab6:
	li      r10, -1
	addic   r7, r7, 0
lab7:
	adde    r4, r4, r4
	adde    r3, r3, r3
	adde    r8, r8, r8
	adde    r7, r7, r7
	subfc   r0, r6, r8
	subfe.  r9, r5, r7
	blt     lab8
	mr      r8, r0
	mr      r7, r9
	addic   r0, r10, 1
lab8:
	bdnz    lab7
	mr      r4, r8
	mr      r3, r7
lab9:
	bge     cr7, no_adjust
	subfic  r4, r4, 0
	subfze  r3, r3
no_adjust:
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
ASM void __shl2i(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	subfic  r8, r5, 32
	subic   r9, r5, 32
	slw     r3, r3, r5
	srw     r10, r4, r8
	or      r3, r3, r10
	slw     r10, r4, r9
	or      r3, r3, r10
	slw     r4, r4, r5
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
ASM void __shr2u(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	subfic  r8, r5, 32
	subic   r9, r5, 32
	srw     r4, r4, r5
	slw     r10, r3, r8
	or      r4, r4, r10
	srw     r10, r3, r9
	or      r4, r4, r10
	srw     r3, r3, r5
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
ASM void __shr2i(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	subfic  r8, r5, 0x20
	addic.  r9, r5, -0x20
	srw     r4, r4, r5
	slw     r10, r3, r8
	or      r4, r4, r10
	sraw    r10, r3, r9
	ble     around
	or      r4, r4, r10
around:
	sraw    r3, r3, r5
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000B0
 */
ASM void __cvt_sll_dbl(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	stwu     r1, -16 (r1)
	rlwinm.  r5, r3, 0, 0, 0
	beq      positive
	subfic   r4, r4, 0
	subfze   r3, r3
positive:
	or.      r7, r3, r4
	li       r6, 0
	beq      zero
	cntlzw   r7, r3
	cntlzw   r8, r4
	rlwinm   r9, r7, 26, 0, 4
	srawi    r9, r9, 31
	and      r9, r9, r8
	add      r7, r7, r9
	subfic   r8, r7, 32
	subic    r9, r7, 32
	slw      r3, r3, r7
	srw      r10, r4, r8
	or       r3, r3, r10
	slw      r10, r4, r9
	or       r3, r3, r10
	slw      r4, r4, r7
	sub      r6, r6, r7
	rlwinm   r7, r4, 0, 21, 31
	cmpwi    r7, 0x400
	addi     r6, r6, 1086
	blt      noround
	bgt      round
	rlwinm.  r7, r4, 0, 20, 20
	beq      noround
round:
	addic    r4, r4, 0x0800
	addze    r3, r3
	addze    r6, r6
noround:
	rlwinm   r4, r4, 21, 0, 31
	rlwimi   r4, r3, 21, 0, 10
	rlwinm   r3, r3, 21, 12, 31
	rlwinm   r6, r6, 20, 0, 11
	or       r3, r6, r3
	or       r3, r5, r3
zero:
	stw      r3, 8 (r1)
	stw      r4, 12 (r1)
	lfd      f1, 8 (r1)
	addi     r1, r1, 16
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
ASM void __cvt_ull_dbl(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	stwu     r1, -0x10 (r1)
	or.      r7, r3, r4
	li       r6, 0x0
	beq      zero
	cntlzw   r7, r3
	cntlzw   r8, r4
	rlwinm   r9, r7, 0x1a, 0x0, 0x4
	srawi    r9, r9, 0x1f
	and      r9, r9, r8
	add      r7, r7, r9
	subfic   r8, r7, 0x20
	subic    r9, r7, 0x20
	slw      r3, r3, r7
	srw      r10, r4, r8
	or       r3, r3, r10
	slw      r10, r4, r9
	or       r3, r3, r10
	slw      r4, r4, r7
	subf     r6, r7, r6
	rlwinm   r7, r4, 0x0, 0x15, 0x1f
	cmpwi    r7, 0x400
	addi     r6, r6, 0x43e
	blt      noround
	bgt      round
	rlwinm.  r7, r4, 0x0, 0x14, 0x14
	beq      noround
round:
	addic    r4, r4, 0x800
	addze    r3, r3
	addze    r6, r6
noround:
	rlwinm   r4, r4, 0x15, 0x0, 0x1f
	rlwimi   r4, r3, 0x15, 0x0, 0xa
	rlwinm   r3, r3, 0x15, 0xc, 0x1f
	rlwinm   r6, r6, 0x14, 0x0, 0xb
	or       r3, r6, r3
zero:
	stw      r3, 0x8 (r1)
	stw      r4, 0xc (r1)
	lfd      f1, 0x8 (r1)
	addi     r1, r1, 0x10
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
ASM void __cvt_sll_flt(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	stwu    r1, -0x10 (r1)
	clrrwi. r5, r3, 31
	beq     positive
	subfic  r4, r4, 0x0
	subfze  r3, r3
positive:
	or.     r7, r3, r4
	li      r6, 0x0
	beq     zero
	cntlzw  r7, r3
	cntlzw  r8, r4
	extlwi  r9, r7, 5, 26
	srawi   r9, r9, 31
	and     r9, r9, r8
	add     r7, r7, r9
	subfic  r8, r7, 0x20
	addic   r9, r7, -0x20
	slw     r3, r3, r7
	srw     r10, r4, r8
	or      r3, r3, r10
	slw     r10, r4, r9
	or      r3, r3, r10
	slw     r4, r4, r7
	subf    r6, r7, r6
	clrlwi  r7, r4, 21
	cmpwi   r7, 0x400
	addi    r6, r6, 0x43e
	blt     noround
	bgt     round
	rlwinm. r7, r4, 0, 20, 20
	beq     noround
round:
	addic   r4, r4, 0x800
	addze   r3, r3
	addze   r6, r6
noround:
	rotrwi  r4, r4, 11
	rlwimi  r4, r3, 21, 0, 10
	extrwi  r3, r3, 20, 1
	slwi    r6, r6, 20
	or      r3, r6, r3
	or      r3, r5, r3
zero:
	stw     r3, 0x8 (r1)
	stw     r4, 0xc (r1)
	lfd     f1, 0x8 (r1)
	frsp    f1, f1
	addi    r1, r1, 0x10
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000A0
 */
ASM void __cvt_ull_flt(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	stwu     r1, -0x10 (r1)
	or.      r7, r3, r4
	li       r6, 0x0
	beq      zero
	cntlzw   r7, r3
	cntlzw   r8, r4
	rlwinm   r9, r7, 0x1a, 0x0, 0x4
	srawi    r9, r9, 0x1f
	and      r9, r9, r8
	add      r7, r7, r9
	subfic   r8, r7, 0x20
	subic    r9, r7, 0x20
	slw      r3, r3, r7
	srw      r10, r4, r8
	or       r3, r3, r10
	slw      r10, r4, r9
	or       r3, r3, r10
	slw      r4, r4, r7
	subf     r6, r7, r6
	rlwinm   r7, r4, 0x0, 0x15, 0x1f
	cmpwi    r7, 0x400
	addi     r6, r6, 0x43e
	blt      noround
	bgt      round
	rlwinm.  r7, r4, 0x0, 0x14, 0x14
	beq      noround
round:
	addic    r4, r4, 0x800
	addze    r3, r3
	addze    r6, r6
noround:
	rlwinm   r4, r4, 0x15, 0x0, 0x1f
	rlwimi   r4, r3, 0x15, 0x0, 0xa
	rlwinm   r3, r3, 0x15, 0xc, 0x1f
	rlwinm   r6, r6, 0x14, 0x0, 0xb
	or       r3, r6, r3
zero:
	stw      r3, 0x8 (r1)
	stw      r4, 0xc (r1)
	lfd      f1, 0x8 (r1)
	frsp     f1, f1
	addi     r1, r1, 0x10
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
ASM void __cvt_dbl_usll(void)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	stwu     r1, -16 (r1)
	stfd     f1, 8 (r1)
	lwz      r3, 8 (r1)
	lwz      r4, 12 (r1)
	rlwinm   r5, r3, 12, 21, 31
	cmplwi   r5, 1023
	bge      not_fraction
	li       r3, 0
	li       r4, 0
	b        func_end
not_fraction:
	mr       r6, r3
	rlwinm   r3, r3, 0, 12, 31
	oris     r3, r3, 0x0010
	addi     r5, r5, -1075
	cmpwi    r5, 0
	bge      left
	neg      r5, r5
	subfic   r8, r5, 32
	subic    r9, r5, 32
	srw      r4, r4, r5
	slw      r10, r3, r8
	or       r4, r4, r10
	srw      r10, r3, r9
	or       r4, r4, r10
	srw      r3, r3, r5
	b        around
left:
	cmpwi    r5, 10
	ble+     no_overflow
	rlwinm.  r6, r6, 0, 0, 0
	beq      max_positive
	lis      r3, 0x8000
	li       r4, 0
	b        func_end
max_positive:
	lis      r3,     0x7FFFFFFF @h
	ori      r3, r3, 0x7FFFFFFF @l
	li       r4, -1
	b        func_end
no_overflow:
	subfic   r8, r5, 32
	subic    r9, r5, 32
	slw      r3, r3, r5
	srw      r10, r4, r8
	or       r3, r3, r10
	slw      r10, r4, r9
	or       r3, r3, r10
	slw      r4, r4, r5
around:
	rlwinm.  r6, r6, 0, 0, 0
	beq      positive
	subfic   r4, r4, 0
	subfze   r3, r3
positive:
func_end:
	addi     r1, r1, 16
	blr
#endif // clang-format on
}
