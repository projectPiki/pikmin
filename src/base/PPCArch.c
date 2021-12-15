#include "types.h"

/*
 * --INFO--
 * Address:	801F5944
 * Size:	000008
 */
asm u32 PPCMfmsr (void)
{
    nofralloc
    mfmsr r3
    blr
}

/*
 * --INFO--
 * Address:	801F594C
 * Size:	000008
 */
asm void PPCMtmsr (register u32 newMSR)
{
    nofralloc
    mtmsr newMSR
    blr
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void PPCOrMsr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void PPCAndMsr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void PPCAndCMsr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F5954
 * Size:	000008
 */
asm u32 PPCMfhid0 (void)
{
    nofralloc
    mfspr r3, HID0
    blr
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMthid0(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfhid1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F595C
 * Size:	000008
 */
asm u32 PPCMfl2cr (void)
{
    nofralloc
    mfspr r3, L2CR
    blr
}

/*
 * --INFO--
 * Address:	801F5964
 * Size:	000008
 */
asm void PPCMtl2cr (register u32 newL2cr)
{
    nofralloc
    mtspr L2CR, newL2cr
    blr
}

/*
 * --INFO--
 * Address:	801F596C
 * Size:	000008
 */
__declspec ( weak ) asm void PPCMtdec ( register u32 newDec )
{
    nofralloc
    mtdec newDec
    blr
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfdec(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F5974
 * Size:	000008
 */
asm void PPCSync (void)
{
    nofralloc
    sc
    blr
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void PPCEieio(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F597C
 * Size:	000014
 */
__declspec ( weak ) asm void PPCHalt (void) //spins infinitely
{
    nofralloc

    sync

_spin:
    nop
    li r3, 0
    nop
    b _spin

    // NEVER REACHED
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfmmcr0(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtmmcr0(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfmmcr1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtmmcr1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfpmc1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtpmc1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfpmc2(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtpmc2(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfpmc3(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtpmc3(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfpmc4(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtpmc4(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfsia(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtsia(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F5990
 * Size:	000008
 */
asm u32 PPCMfhid2 ( void )
{
    nofralloc
    mfspr r3, 920
    blr
}

/*
 * --INFO--
 * Address:	801F5998
 * Size:	000008
 */
asm void PPCMthid2 ( register u32 newhid2 )
{
    nofralloc
    mtspr 920, newhid2
    blr
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void PPCMfwpar(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F59A0
 * Size:	000008
 */
asm void PPCMtwpar ( register u32 newwpar )
{
    nofralloc
    mtspr WPAR, newwpar
    blr
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfdmaU(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfdmaL(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtdmaU(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtdmaL(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfpvr(void)
{
	// UNUSED FUNCTION
}
