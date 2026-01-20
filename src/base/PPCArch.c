#include "Dolphin/PPCArch.h"

#ifdef __MWERKS__
#define MOVE_FROM_SPR(name, rD) asm { mfspr rD, name }
#define MOVE_TO_SPR(name, rS)   asm { mtspr name, rS }
#define MOVE_FROM_MSR(rD)       asm { mfmsr rD }
#define MOVE_TO_MSR(rS)         asm { mtmsr rS }
#else
#define MOVE_FROM_SPR(name, rD) (void)0
#define MOVE_TO_SPR(name, rS)   (void)0
#define MOVE_FROM_MSR(rD)       (void)0
#define MOVE_TO_MSR(rS)         (void)0
#endif

/**
 * @TODO: Documentation
 */
u32 PPCMfmsr(void)
{
	register u32 result;
	MOVE_FROM_MSR(result);
	return result;
}

/**
 * @TODO: Documentation
 */
void PPCMtmsr(register u32 value)
{
	MOVE_TO_MSR(value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
void PPCOrMsr(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
void PPCAndMsr(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
void PPCAndCMsr(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
u32 PPCMfhid0(void)
{
	register u32 result;
	MOVE_FROM_SPR(HID0, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void PPCMthid0(register u32 value)
{
	MOVE_TO_SPR(HID0, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
u32 PPCMfhid1(void)
{
	register u32 result;
	MOVE_FROM_SPR(HID1, result);
	return result;
}

/**
 * @TODO: Documentation
 */
u32 PPCMfl2cr(void)
{
	register u32 result;
	MOVE_FROM_SPR(L2CR, result);
	return result;
}

/**
 * @TODO: Documentation
 */
void PPCMtl2cr(register u32 value)
{
	MOVE_TO_SPR(L2CR, value);
}

/**
 * @TODO: Documentation
 */
void PPCMtdec(register u32 value)
{
	MOVE_TO_SPR(dec, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
u32 PPCMfdec(void)
{
	register u32 result;
	MOVE_FROM_SPR(dec, result);
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
 * @note UNUSED Size: 000034
 */
void PPCEieio(void)
{
	// UNUSED FUNCTION
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
			li r3, 0
			nop
		}
#endif
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
u32 PPCMfmmcr0(void)
{
	register u32 result;
	MOVE_FROM_SPR(MMCR0, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void PPCMtmmcr0(register u32 value)
{
	MOVE_TO_SPR(MMCR0, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
u32 PPCMfmmcr1(void)
{
	register u32 result;
	MOVE_FROM_SPR(MMCR1, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void PPCMtmmcr1(register u32 value)
{
	MOVE_TO_SPR(MMCR1, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
u32 PPCMfpmc1(void)
{
	register u32 result;
	MOVE_FROM_SPR(PMC1, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void PPCMtpmc1(register u32 value)
{
	MOVE_TO_SPR(PMC1, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
u32 PPCMfpmc2(void)
{
	register u32 result;
	MOVE_FROM_SPR(PMC2, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void PPCMtpmc2(register u32 value)
{
	MOVE_TO_SPR(PMC2, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
u32 PPCMfpmc3(void)
{
	register u32 result;
	MOVE_FROM_SPR(PMC3, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void PPCMtpmc3(register u32 value)
{
	MOVE_TO_SPR(PMC3, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
u32 PPCMfpmc4(void)
{
	register u32 result;
	MOVE_FROM_SPR(PMC4, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void PPCMtpmc4(register u32 value)
{
	MOVE_TO_SPR(PMC4, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
u32 PPCMfsia(void)
{
	register u32 result;
	MOVE_FROM_SPR(SIA, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void PPCMtsia(register u32 value)
{
	MOVE_TO_SPR(SIA, value);
}

/**
 * @TODO: Documentation
 */
u32 PPCMfhid2(void)
{
	register u32 result;
	MOVE_FROM_SPR(HID2, result);
	return result;
}

/**
 * @TODO: Documentation
 */
void PPCMthid2(register u32 value)
{
	MOVE_TO_SPR(HID2, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
u32 PPCMfwpar(void)
{
	register u32 result;
	MOVE_FROM_SPR(WPAR, result);
	return result;
}

/**
 * @TODO: Documentation
 */
void PPCMtwpar(register u32 value)
{
	MOVE_TO_SPR(WPAR, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
u32 PPCMfdmaU(void)
{
	register u32 result;
	MOVE_FROM_SPR(DMA_U, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
u32 PPCMfdmaL(void)
{
	register u32 result;
	MOVE_FROM_SPR(DMA_L, result);
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void PPCMtdmaU(register u32 value)
{
	MOVE_TO_SPR(DMA_U, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void PPCMtdmaL(register u32 value)
{
	MOVE_TO_SPR(DMA_L, value);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
u32 PPCMfpvr(void)
{
	// UNUSED FUNCTION
}
