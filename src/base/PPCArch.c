#include "Dolphin/PPCArch.h"

/*
 * --INFO--
 * Address: 801F5944
 * Size:    000008
 */
ASM u32 PPCMfmsr(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	mfmsr r3
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address: 801F594C
 * Size:    000008
 */
ASM void PPCMtmsr(register u32 newMSR)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	mtmsr newMSR
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address: ........
 * Size:    00000C
 */
void PPCOrMsr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    00000C
 */
void PPCAndMsr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    00000C
 */
void PPCAndCMsr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: 801F5954
 * Size:    000008
 */
ASM u32 PPCMfhid0(void)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	mfspr r3, HID0
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMthid0(u32 newHID0)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMfhid1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: 801F595C
 * Size:    000008
 */
ASM u32 PPCMfl2cr(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	mfspr r3, L2CR
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address: 801F5964
 * Size:    000008
 */
ASM void PPCMtl2cr(register u32 newL2cr) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	mtspr L2CR, newL2cr
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address: 801F596C
 * Size:    000008
 */
WEAKFUNC ASM void PPCMtdec(register u32 newDec)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	mtdec newDec
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMfdec(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: 801F5974
 * Size:    000008
 */
ASM void PPCSync(void)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	sc
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address: ........
 * Size:    000034
 */
void PPCEieio(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: 801F597C
 * Size:    000014
 */
WEAKFUNC ASM void PPCHalt(void) // spins infinitely
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

	sync

_spin:
	nop
	li r3, 0
	nop
	b _spin

	// NEVER REACHED
#endif // clang-format on
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMfmmcr0(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMtmmcr0(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMfmmcr1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMtmmcr1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMfpmc1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMtpmc1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMfpmc2(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMtpmc2(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMfpmc3(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMtpmc3(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMfpmc4(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMtpmc4(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMfsia(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMtsia(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: 801F5990
 * Size:    000008
 */
ASM u32 PPCMfhid2(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	mfspr r3, 920
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address: 801F5998
 * Size:    000008
 */
ASM void PPCMthid2(register u32 newhid2) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	mtspr 920, newhid2
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address: ........
 * Size:    00000C
 */
u32 PPCMfwpar(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: 801F59A0
 * Size:    000008
 */
ASM void PPCMtwpar(register u32 newwpar)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	mtspr WPAR, newwpar
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMfdmaU(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMfdmaL(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMtdmaU(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMtdmaL(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000008
 */
void PPCMfpvr(void)
{
	// UNUSED FUNCTION
}
