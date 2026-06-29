#include "Dolphin/PPCArch.h"
#include "Dolphin/db.h"
#include "Dolphin/os.h"
#include <stddef.h>

/**
 * @TODO: Documentation
 */
static ASM void __OSLoadFPUContext(register u32, register OSContext* fpuContext)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	lhz      r5, fpuContext->state;
	clrlwi.  r5, r5, 31  // OS_CONTEXT_STATE_FPSAVED
	beq      _return

	lfd      fp0, fpuContext->fpscr
	mtfsf    0xFF, fp0
	mfspr    r5, SPR_HID2
	rlwinm.  r5, r5, 3, 31, 31  // HID2_PSE
	beq      _regular_FPRs

	// fpuContext->psf does not work for paired-singles instructions.
	// Gives "illegal object reference in constant expression" error.
	psq_l    fp0, OSContext.psf[0] (fpuContext), 0, 0
	psq_l    fp1, OSContext.psf[1] (fpuContext), 0, 0
	psq_l    fp2, OSContext.psf[2] (fpuContext), 0, 0
	psq_l    fp3, OSContext.psf[3] (fpuContext), 0, 0
	psq_l    fp4, OSContext.psf[4] (fpuContext), 0, 0
	psq_l    fp5, OSContext.psf[5] (fpuContext), 0, 0
	psq_l    fp6, OSContext.psf[6] (fpuContext), 0, 0
	psq_l    fp7, OSContext.psf[7] (fpuContext), 0, 0
	psq_l    fp8, OSContext.psf[8] (fpuContext), 0, 0
	psq_l    fp9, OSContext.psf[9] (fpuContext), 0, 0
	psq_l    fp10, OSContext.psf[10] (fpuContext), 0, 0
	psq_l    fp11, OSContext.psf[11] (fpuContext), 0, 0
	psq_l    fp12, OSContext.psf[12] (fpuContext), 0, 0
	psq_l    fp13, OSContext.psf[13] (fpuContext), 0, 0
	psq_l    fp14, OSContext.psf[14] (fpuContext), 0, 0
	psq_l    fp15, OSContext.psf[15] (fpuContext), 0, 0
	psq_l    fp16, OSContext.psf[16] (fpuContext), 0, 0
	psq_l    fp17, OSContext.psf[17] (fpuContext), 0, 0
	psq_l    fp18, OSContext.psf[18] (fpuContext), 0, 0
	psq_l    fp19, OSContext.psf[19] (fpuContext), 0, 0
	psq_l    fp20, OSContext.psf[20] (fpuContext), 0, 0
	psq_l    fp21, OSContext.psf[21] (fpuContext), 0, 0
	psq_l    fp22, OSContext.psf[22] (fpuContext), 0, 0
	psq_l    fp23, OSContext.psf[23] (fpuContext), 0, 0
	psq_l    fp24, OSContext.psf[24] (fpuContext), 0, 0
	psq_l    fp25, OSContext.psf[25] (fpuContext), 0, 0
	psq_l    fp26, OSContext.psf[26] (fpuContext), 0, 0
	psq_l    fp27, OSContext.psf[27] (fpuContext), 0, 0
	psq_l    fp28, OSContext.psf[28] (fpuContext), 0, 0
	psq_l    fp29, OSContext.psf[29] (fpuContext), 0, 0
	psq_l    fp30, OSContext.psf[30] (fpuContext), 0, 0
	psq_l    fp31, OSContext.psf[31] (fpuContext), 0, 0

_regular_FPRs:
	lfd      fp0,  fpuContext->fpr[0]
	lfd      fp1,  fpuContext->fpr[1]
	lfd      fp2,  fpuContext->fpr[2]
	lfd      fp3,  fpuContext->fpr[3]
	lfd      fp4,  fpuContext->fpr[4]
	lfd      fp5,  fpuContext->fpr[5]
	lfd      fp6,  fpuContext->fpr[6]
	lfd      fp7,  fpuContext->fpr[7]
	lfd      fp8,  fpuContext->fpr[8]
	lfd      fp9,  fpuContext->fpr[9]
	lfd      fp10, fpuContext->fpr[10]
	lfd      fp11, fpuContext->fpr[11]
	lfd      fp12, fpuContext->fpr[12]
	lfd      fp13, fpuContext->fpr[13]
	lfd      fp14, fpuContext->fpr[14]
	lfd      fp15, fpuContext->fpr[15]
	lfd      fp16, fpuContext->fpr[16]
	lfd      fp17, fpuContext->fpr[17]
	lfd      fp18, fpuContext->fpr[18]
	lfd      fp19, fpuContext->fpr[19]
	lfd      fp20, fpuContext->fpr[20]
	lfd      fp21, fpuContext->fpr[21]
	lfd      fp22, fpuContext->fpr[22]
	lfd      fp23, fpuContext->fpr[23]
	lfd      fp24, fpuContext->fpr[24]
	lfd      fp25, fpuContext->fpr[25]
	lfd      fp26, fpuContext->fpr[26]
	lfd      fp27, fpuContext->fpr[27]
	lfd      fp28, fpuContext->fpr[28]
	lfd      fp29, fpuContext->fpr[29]
	lfd      fp30, fpuContext->fpr[30]
	lfd      fp31, fpuContext->fpr[31]
_return:
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
static ASM void __OSSaveFPUContext(register u32, register u32, register OSContext* fpuContext)
{
#ifdef __MWERKS__ // clang-format off
  	nofralloc

	lhz      r3,   fpuContext->state
	ori      r3,   r3, OS_CONTEXT_STATE_FPSAVED
	sth      r3,   fpuContext->state

	stfd     fp0,  fpuContext->fpr[0]
	stfd     fp1,  fpuContext->fpr[1]
	stfd     fp2,  fpuContext->fpr[2]
	stfd     fp3,  fpuContext->fpr[3]
	stfd     fp4,  fpuContext->fpr[4]
	stfd     fp5,  fpuContext->fpr[5]
	stfd     fp6,  fpuContext->fpr[6]
	stfd     fp7,  fpuContext->fpr[7]
	stfd     fp8,  fpuContext->fpr[8]
	stfd     fp9,  fpuContext->fpr[9]
	stfd     fp10, fpuContext->fpr[10]
	stfd     fp11, fpuContext->fpr[11]
	stfd     fp12, fpuContext->fpr[12]
	stfd     fp13, fpuContext->fpr[13]
	stfd     fp14, fpuContext->fpr[14]
	stfd     fp15, fpuContext->fpr[15]
	stfd     fp16, fpuContext->fpr[16]
	stfd     fp17, fpuContext->fpr[17]
	stfd     fp18, fpuContext->fpr[18]
	stfd     fp19, fpuContext->fpr[19]
	stfd     fp20, fpuContext->fpr[20]
	stfd     fp21, fpuContext->fpr[21]
	stfd     fp22, fpuContext->fpr[22]
	stfd     fp23, fpuContext->fpr[23]
	stfd     fp24, fpuContext->fpr[24]
	stfd     fp25, fpuContext->fpr[25]
	stfd     fp26, fpuContext->fpr[26]
	stfd     fp27, fpuContext->fpr[27]
	stfd     fp28, fpuContext->fpr[28]
	stfd     fp29, fpuContext->fpr[29]
	stfd     fp30, fpuContext->fpr[30]
	stfd     fp31, fpuContext->fpr[31]

	mffs     fp0
	stfd     fp0,  fpuContext->fpscr

	lfd      fp0,  fpuContext->fpr[0]

	mfspr    r3, SPR_HID2
	rlwinm.  r3, r3, 3, 31, 31
	beq      _return

	// fpuContext->psf does not work for paired-singles instructions.
	// Gives "illegal object reference in constant expression" error.
	psq_st   fp0, OSContext.psf[0] (fpuContext), 0, 0
	psq_st   fp1, OSContext.psf[1] (fpuContext), 0, 0
	psq_st   fp2, OSContext.psf[2] (fpuContext), 0, 0
	psq_st   fp3, OSContext.psf[3] (fpuContext), 0, 0
	psq_st   fp4, OSContext.psf[4] (fpuContext), 0, 0
	psq_st   fp5, OSContext.psf[5] (fpuContext), 0, 0
	psq_st   fp6, OSContext.psf[6] (fpuContext), 0, 0
	psq_st   fp7, OSContext.psf[7] (fpuContext), 0, 0
	psq_st   fp8, OSContext.psf[8] (fpuContext), 0, 0
	psq_st   fp9, OSContext.psf[9] (fpuContext), 0, 0
	psq_st   fp10, OSContext.psf[10] (fpuContext), 0, 0
	psq_st   fp11, OSContext.psf[11] (fpuContext), 0, 0
	psq_st   fp12, OSContext.psf[12] (fpuContext), 0, 0
	psq_st   fp13, OSContext.psf[13] (fpuContext), 0, 0
	psq_st   fp14, OSContext.psf[14] (fpuContext), 0, 0
	psq_st   fp15, OSContext.psf[15] (fpuContext), 0, 0
	psq_st   fp16, OSContext.psf[16] (fpuContext), 0, 0
	psq_st   fp17, OSContext.psf[17] (fpuContext), 0, 0
	psq_st   fp18, OSContext.psf[18] (fpuContext), 0, 0
	psq_st   fp19, OSContext.psf[19] (fpuContext), 0, 0
	psq_st   fp20, OSContext.psf[20] (fpuContext), 0, 0
	psq_st   fp21, OSContext.psf[21] (fpuContext), 0, 0
	psq_st   fp22, OSContext.psf[22] (fpuContext), 0, 0
	psq_st   fp23, OSContext.psf[23] (fpuContext), 0, 0
	psq_st   fp24, OSContext.psf[24] (fpuContext), 0, 0
	psq_st   fp25, OSContext.psf[25] (fpuContext), 0, 0
	psq_st   fp26, OSContext.psf[26] (fpuContext), 0, 0
	psq_st   fp27, OSContext.psf[27] (fpuContext), 0, 0
	psq_st   fp28, OSContext.psf[28] (fpuContext), 0, 0
	psq_st   fp29, OSContext.psf[29] (fpuContext), 0, 0
	psq_st   fp30, OSContext.psf[30] (fpuContext), 0, 0
	psq_st   fp31, OSContext.psf[31] (fpuContext), 0, 0

_return:
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
ASM void OSLoadFPUContext(register OSContext* fpuContext) {
#ifdef __MWERKS__ // clang-format off
	// Just a guess based on the UNUSED size.
	nofralloc
	mr  r4, fpuContext
	b   __OSLoadFPUContext
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
ASM void OSSaveFPUContext(register OSContext* fpuContext) {
#ifdef __MWERKS__ // clang-format off
	// Just a guess based on the UNUSED size.
	nofralloc
	mr  r5, fpuContext
	b   __OSSaveFPUContext
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
ASM void OSSetCurrentContext(register OSContext* context) {
#ifdef __MWERKS__ // clang-format off
	nofralloc

	lis     r4, OS_BASE_CACHED @ha

	stw     context, __OSCurrentContext @l (r4)

	clrlwi  r5, context, 2
	stw     r5, OS_CURRENTCONTEXT_PADDR (r4)

	lwz     r5, __OSFPUContext @l (r4)
	cmpw    r5, context
	bne     _disableFPU

	lwz     r6, context->srr1
	ori     r6, r6, MSR_FP
	stw     r6, context->srr1
	mfmsr   r6
	ori     r6, r6, MSR_RI
	mtmsr   r6
	blr

_disableFPU:
	lwz     r6, context->srr1
	rlwinm  r6, r6, 0, 19, 17  // ~MSR_FP
	stw     r6, context->srr1
	mfmsr   r6
	rlwinm  r6, r6, 0, 19, 17  // ~MSR_FP
	ori     r6, r6, MSR_RI
	mtmsr   r6
	isync
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
OSContext* OSGetCurrentContext(void)
{
	return (OSContext*)__OSCurrentContext;
}

/**
 * @TODO: Documentation
 */
ASM u32 OSSaveContext(register OSContext* context) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	stmw   r13, context->gpr[13]
	mfspr  r0, SPR_GQR1
	stw    r0, context->gqr[1]
	mfspr  r0, SPR_GQR2
	stw    r0, context->gqr[2]
	mfspr  r0, SPR_GQR3
	stw    r0, context->gqr[3]
	mfspr  r0, SPR_GQR4
	stw    r0, context->gqr[4]
	mfspr  r0, SPR_GQR5
	stw    r0, context->gqr[5]
	mfspr  r0, SPR_GQR6
	stw    r0, context->gqr[6]
	mfspr  r0, SPR_GQR7
	stw    r0, context->gqr[7]
	mfcr   r0
	stw    r0, context->cr
	mflr   r0
	stw    r0, context->lr
	stw    r0, context->srr0
	mfmsr  r0
	stw    r0, context->srr1
	mfctr  r0
	stw    r0, context->ctr
	mfxer  r0
	stw    r0, context->xer
	stw    r1, context->gpr[1]
	stw    r2, context->gpr[2]
	li     r0, 0x1
	stw    r0, context->gpr[3]
	li     r3, 0
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
ASM void OSLoadContext(register OSContext* context)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

	lis      r4,     __RAS_OSDisableInterrupts_begin @ha
	lwz      r6, context->srr0
	addi     r5, r4, __RAS_OSDisableInterrupts_begin @l
	cmplw    r6, r5
	blt      _notInRAS
	lis      r4,     __RAS_OSDisableInterrupts_end @ha
	addi     r0, r4, __RAS_OSDisableInterrupts_end @l
	cmplw    r6, r0
	bgt      _notInRAS
	stw      r5, context->srr0

_notInRAS:

	lwz      r0, context->gpr[0]
	lwz      r1, context->gpr[1]
	lwz      r2, context->gpr[2]

	lhz      r4, context->state
	rlwinm.  r5, r4, 0, 30, 30
	beq      notexc
	rlwinm   r4, r4, 0, 31, 29
	sth      r4, context->state
	lmw      r5, context->gpr[5]
	b        misc
notexc:
	lmw      r13, context->gpr[13]
misc:

	lwz      r4, context->gqr[1]
	mtspr    SPR_GQR1, r4
	lwz      r4, context->gqr[2]
	mtspr    SPR_GQR2, r4
	lwz      r4, context->gqr[3]
	mtspr    SPR_GQR3, r4
	lwz      r4, context->gqr[4]
	mtspr    SPR_GQR4, r4
	lwz      r4, context->gqr[5]
	mtspr    SPR_GQR5, r4
	lwz      r4, context->gqr[6]
	mtspr    SPR_GQR6, r4
	lwz      r4, context->gqr[7]
	mtspr    SPR_GQR7, r4

	lwz      r4, context->cr
	mtcr     r4
	lwz      r4, context->lr
	mtlr     r4
	lwz      r4, context->ctr
	mtctr    r4
	lwz      r4, context->xer
	mtxer    r4

	mfmsr    r4
	rlwinm   r4, r4, 0, 17, 15  // ~MSR_EE
	rlwinm   r4, r4, 0, 31, 29  // ~MSR_RI
	mtmsr    r4

	lwz      r4, context->srr0
	mtsrr0   r4
	lwz      r4, context->srr1
	mtsrr1   r4

	lwz      r4, context->gpr[4]
	lwz      r3, context->gpr[3]

	rfi
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
ASM u32 OSGetStackPointer(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	mr   r3, r1
	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000010
 */
u32 OSSwitchStack(register u32 newsp)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
int OSSwitchFiber(register u32 pc, register u32 newsp)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 */
void OSClearContext(OSContext* context)
{
	context->mode  = 0;
	context->state = 0;
	if (context == __OSFPUContext) {
		__OSFPUContext = NULL;
	}
}

/**
 * @TODO: Documentation
 */
ASM void OSInitContext(register OSContext* context, register u32 pc, register u32 newsp)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

	stw  pc,  context->srr0
	stw  newsp,  context->gpr[1]
	li   r11, 0
	ori  r11, r11, MSR_EE | MSR_IR | MSR_DR | MSR_RI | MSR_ME
	stw  r11, context->srr1
	li   r0,  0
	stw  r0,  context->cr
	stw  r0,  context->xer

	stw  r2,  context->gpr[2]
	stw  r13, context->gpr[13]

	stw  r0,  context->gpr[3]
	stw  r0,  context->gpr[4]
	stw  r0,  context->gpr[5]
	stw  r0,  context->gpr[6]
	stw  r0,  context->gpr[7]
	stw  r0,  context->gpr[8]
	stw  r0,  context->gpr[9]
	stw  r0,  context->gpr[10]
	stw  r0,  context->gpr[11]
	stw  r0,  context->gpr[12]

	stw  r0,  context->gpr[14]
	stw  r0,  context->gpr[15]
	stw  r0,  context->gpr[16]
	stw  r0,  context->gpr[17]
	stw  r0,  context->gpr[18]
	stw  r0,  context->gpr[19]
	stw  r0,  context->gpr[20]
	stw  r0,  context->gpr[21]
	stw  r0,  context->gpr[22]
	stw  r0,  context->gpr[23]
	stw  r0,  context->gpr[24]
	stw  r0,  context->gpr[25]
	stw  r0,  context->gpr[26]
	stw  r0,  context->gpr[27]
	stw  r0,  context->gpr[28]
	stw  r0,  context->gpr[29]
	stw  r0,  context->gpr[30]
	stw  r0,  context->gpr[31]

	stw  r0,  context->gqr[0]
	stw  r0,  context->gqr[1]
	stw  r0,  context->gqr[2]
	stw  r0,  context->gqr[3]
	stw  r0,  context->gqr[4]
	stw  r0,  context->gqr[5]
	stw  r0,  context->gqr[6]
	stw  r0,  context->gqr[7]

	b       OSClearContext
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
void OSDumpContext(OSContext* context)
{
	u32 i;
	u32* p;

	OSReport("------------------------- Context 0x%08x -------------------------\n", context);

	for (i = 0; i < 16; ++i) {
		OSReport("r%-2d  = 0x%08x (%14d)  r%-2d  = 0x%08x (%14d)\n", i, context->gpr[i], context->gpr[i], i + 16, context->gpr[i + 16],
		         context->gpr[i + 16]);
	}

	OSReport("LR   = 0x%08x                   CR   = 0x%08x\n", context->lr, context->cr);
	OSReport("SRR0 = 0x%08x                   SRR1 = 0x%08x\n", context->srr0, context->srr1);

	OSReport("\nGQRs----------\n");
	for (i = 0; i < 4; ++i) {
		OSReport("gqr%d = 0x%08x \t gqr%d = 0x%08x\n", i, context->gqr[i], i + 4, context->gqr[i + 4]);
	}

	if (context->state & OS_CONTEXT_STATE_FPSAVED) {
		OSContext* currentContext;
		OSContext fpuContext;
		BOOL enabled;

		enabled        = OSDisableInterrupts();
		currentContext = OSGetCurrentContext();
		OSClearContext(&fpuContext);
		OSSetCurrentContext(&fpuContext);

		OSReport("\n\nFPRs----------\n");
		for (i = 0; i < 32; i += 2) {
			OSReport("fr%d \t= %d \t fr%d \t= %d\n", i, (u32)context->fpr[i], i + 1, (u32)context->fpr[i + 1]);
		}
		OSReport("\n\nPSFs----------\n");
		for (i = 0; i < 32; i += 2) {
			OSReport("ps%d \t= 0x%x \t ps%d \t= 0x%x\n", i, (u32)context->psf[i], i + 1, (u32)context->psf[i + 1]);
		}

		OSClearContext(&fpuContext);
		OSSetCurrentContext(currentContext);
		OSRestoreInterrupts(enabled);
	}

	OSReport("\nAddress:      Back Chain    LR Save\n");
	for (i = 0, p = (u32*)context->gpr[1]; p && (u32)p != 0xffffffff && i++ < 16; p = (u32*)*p) {
		OSReport("0x%08x:   0x%08x    0x%08x\n", p, p[0], p[1]);
	}
}

/**
 * @TODO: Documentation
 */
static ASM void OSSwitchFPUContext(register __OSException exception, register OSContext* context)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	mfmsr   r5
	ori     r5, r5, MSR_FP
	mtmsr   r5
	isync
	lwz     r5, context->srr1
	ori     r5, r5, MSR_FP
	mtsrr1  r5
	lis     r3, __OSFPUContext @ha
	lwz     r5, __OSFPUContext @l (r3)
	stw     context, __OSFPUContext @l (r3)
	cmpw    r5, r4
	beq     _restoreAndExit
	cmpwi   r5, 0x0
	beq     _loadNewFPUContext
	bl      __OSSaveFPUContext
_loadNewFPUContext:
	bl      __OSLoadFPUContext
_restoreAndExit:
	lwz     r3, context->cr
	mtcr    r3
	lwz     r3, context->lr
	mtlr    r3
	lwz     r3, context->srr0
	mtsrr0  r3
	lwz     r3, context->ctr
	mtctr   r3
	lwz     r3, context->xer
	mtxer   r3
	lhz     r3, context->state
	rlwinm  r3, r3, 0, 31, 29
	sth     r3, context->state
	lwz     r5, context->gpr[5]
	lwz     r3, context->gpr[3]
	lwz     r4, context->gpr[4]
	rfi
#endif // clang-format on
}

/**
 * @TODO: Documentation
 */
void __OSContextInit(void)
{
	__OSSetExceptionHandler(__OS_EXCEPTION_FLOATING_POINT, OSSwitchFPUContext);
	__OSFPUContext = NULL;
	DBPrintf("FPU-unavailable handler installed\n");
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00012C
 */
void OSFillFPUContext(register OSContext* context)
{
	TRAP_UNIMPLEMENTED;
}
