#include "Dolphin/PPCArch.h"

/**
 * @TODO: Documentation
 */
u32 PPCMfmsr(void)
{
	register u32 result;
	PPC_MOVE_FROM_MSR(result);
	return result;
}

/**
 * @TODO: Documentation
 */
void PPCMtmsr(register u32 value)
{
	PPC_MOVE_TO_MSR(value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C (Nonmatching)
 */
void PPCOrMsr(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C (Nonmatching)
 */
void PPCAndMsr(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C (Nonmatching)
 */
void PPCAndCMsr(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 */
u32 PPCMfhid0(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_HID0, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
void PPCMthid0(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_HID0, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
u32 PPCMfhid1(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_HID1, result);
	return result;
}

/**
 * @TODO: Documentation
 */
u32 PPCMfl2cr(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_L2CR, result);
	return result;
}

/**
 * @TODO: Documentation
 */
void PPCMtl2cr(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_L2CR, value);
}

/**
 * @TODO: Documentation
 */
void PPCMtdec(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_DEC, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
u32 PPCMfdec(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_DEC, result);
	return result;
}

/**
 * @TODO: Documentation
 */
void PPCSync(void)
{
#ifdef __MWERKS__
	asm { sc }
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034 (Matching by size)
 */
void PPCEieio(void)
{
#ifdef __MWERKS__
	asm {
		mfmsr   r5
		rlwinm  r6, r5, 0, 17, 15 // ~MSR_EE
		mtmsr   r6
		mfspr   r3, SPR_HID0
		ori     r4, r3, HID0_ABE
		mtspr   SPR_HID0, r4
		isync
		eieio
		isync

		mtspr   SPR_HID0, r3
		mtmsr   r5
		isync
	}
#endif
}

/**
 * @TODO: Documentation
 */
void PPCHalt(void)
{
	__mwerks_sync();
	for (;;) {
#ifdef __MWERKS__
		asm {
			nop
			li   r3, 0
			nop
		}
#endif
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
u32 PPCMfmmcr0(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_MMCR0, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
void PPCMtmmcr0(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_MMCR0, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
u32 PPCMfmmcr1(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_MMCR1, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
void PPCMtmmcr1(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_MMCR1, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
u32 PPCMfpmc1(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_PMC1, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
void PPCMtpmc1(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_PMC1, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
u32 PPCMfpmc2(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_PMC2, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
void PPCMtpmc2(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_PMC2, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
u32 PPCMfpmc3(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_PMC3, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
void PPCMtpmc3(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_PMC3, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
u32 PPCMfpmc4(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_PMC4, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
void PPCMtpmc4(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_PMC4, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
u32 PPCMfsia(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_SIA, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
void PPCMtsia(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_SIA, value);
}

/**
 * @TODO: Documentation
 */
u32 PPCMfhid2(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_HID2, result);
	return result;
}

/**
 * @TODO: Documentation
 */
void PPCMthid2(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_HID2, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C (Matching by size)
 */
u32 PPCMfwpar(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_WPAR, result);
	return result;
}

/**
 * @TODO: Documentation
 */
void PPCMtwpar(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_WPAR, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
u32 PPCMfdmaU(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_DMA_U, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
u32 PPCMfdmaL(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_DMA_L, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
void PPCMtdmaU(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_DMA_U, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
void PPCMtdmaL(register u32 value)
{
	PPC_MOVE_TO_SPR(SPR_DMA_L, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
u32 PPCMfpvr(void)
{
	register u32 result;
	PPC_MOVE_FROM_SPR(SPR_PVR, result);
	return result;
}
