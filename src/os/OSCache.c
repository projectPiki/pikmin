#include "Dolphin/os.h"
#include "Dolphin/db.h"
#define PPCSYNC sc // system call performs PPCSync()

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void DCFlashInvalidate(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F6BA4
 * Size:	000014
 */
ASM void DCEnable(void)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

	sync

	mfspr   r3, HID0
	ori     r3, r3, HID0_DCE
	mtspr   HID0, r3

	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void DCDisable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void DCFreeze(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void DCUnfreeze(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void DCTouchLoad(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void DCBlockZero(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void DCBlockStore(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void DCBlockFlush(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void DCBlockInvalidate(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F6BB8
 * Size:	000030
 */
ASM void DCInvalidateRange(register void* addr, register u32 nBytes) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	cmplwi  nBytes,0
	blelr-
	rlwinm.  r5,addr,0,27,31
	beq      _noadd
	addi     r4, r4, 0x20
_noadd:
	addi    nBytes,nBytes,31
	srwi    nBytes,nBytes,5
	mtctr   nBytes
_loop:
	dcbi    0,addr
	addi    addr,addr,32
	bdnz    _loop
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address:	801F6BE8
 * Size:	000034
 */
ASM void DCFlushRange(register void* addr, register u32 nBytes) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	cmplwi  nBytes,0
	blelr-
	rlwinm.  r5,addr,0,27,31
	beq      _noadd
	addi     r4, r4, 0x20
_noadd:
	addi    nBytes,nBytes,31
	srwi    nBytes,nBytes,5
	mtctr   nBytes
_loop:
	dcbf    0,addr
	addi    addr,addr,32
	bdnz    _loop

	PPCSYNC

	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address:	801F6C1C
 * Size:	000034
 */
ASM void DCStoreRange(register void* addr, register u32 nBytes) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	cmplwi  nBytes,0
	blelr-
	rlwinm.  r5,addr,0,27,31
	beq      _noadd
	addi     r4, r4, 0x20
_noadd:
	addi    nBytes,nBytes,31
	srwi    nBytes,nBytes,5
	mtctr   nBytes
_loop:
	dcbst   0,addr
	addi    addr,addr,32
	bdnz    _loop

	PPCSYNC

	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address:	801F6C50
 * Size:	000030
 */
ASM void DCFlushRangeNoSync(register void* addr, register u32 nBytes) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	cmplwi  nBytes,0
	blelr-
	rlwinm.  r5,addr,0,27,31
	beq      _noadd
	addi     r4, r4, 0x20
_noadd:
	addi    nBytes,nBytes,31
	srwi    nBytes,nBytes,5
	mtctr   nBytes
_loop:
	dcbf    0,addr
	addi    addr,addr,32
	bdnz    _loop

	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address:	801F6C80
 * Size:	000030
 */
ASM void DCStoreRangeNoSync(register void* addr, register u32 nBytes) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	cmplwi  nBytes,0
	blelr-
	rlwinm.  r5,addr,0,27,31
	beq      _noadd
	addi     r4, r4, 0x20
_noadd:
	addi    nBytes,nBytes,31
	srwi    nBytes,nBytes,5
	mtctr   nBytes
_loop:
	dcbst   0,addr
	addi    addr,addr,32
	bdnz    _loop

	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address:	801F6CB0
 * Size:	000030
 */
ASM void DCZeroRange(register void* addr, register u32 nBytes)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	cmplwi  nBytes,0
	blelr-
	rlwinm.  r5,addr,0,27,31
	beq      _noadd
	addi     r4, r4, 0x20
_noadd:
	addi    nBytes,nBytes,31
	srwi    nBytes,nBytes,5
	mtctr   nBytes
_loop:
	dcbz    0,addr
	addi    addr,addr,32
	bdnz    _loop
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void DCTouchRange(register void* addr, register u32 nBytes)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F6CE0
 * Size:	000038
 */
ASM void ICInvalidateRange(register void* addr, register u32 nBytes) {
#ifdef __MWERKS__ // clang-format off
	nofralloc
	cmplwi  nBytes,0
	blelr-
	rlwinm.  r5,addr,0,27,31
	beq      _noadd
	addi     r4, r4, 0x20
_noadd:
	addi    nBytes,nBytes,31
	srwi    nBytes,nBytes,5
	mtctr   nBytes
_loop:
	icbi    0,addr
	addi    addr,addr,32
	bdnz    _loop
	sync
	isync
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address:	801F6D18
 * Size:	000010
 */
ASM void ICFlashInvalidate(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc

	mfspr   r3, HID0
	ori     r3, r3, HID0_ICFI
	mtspr   HID0, r3

	blr
#endif // clang-format on
	/*
	.loc_0x0:
	  mfspr     r3, 0x3F0
	  ori       r3, r3, 0x800
	  mtspr     1008, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F6D28
 * Size:	000014
 */
ASM void ICEnable(void)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

	isync

	mfspr   r3, HID0
	ori     r3, r3, HID0_ICE
	mtspr   HID0, r3

	blr
#endif // clang-format on
	/*
	.loc_0x0:
	  isync
	  mfspr     r3, 0x3F0
	  ori       r3, r3, 0x8000
	  mtspr     1008, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void ICDisable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void ICFreeze(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void ICUnfreeze(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void ICBlockInvalidate(void*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void ICSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void __LCEnable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void LCEnable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void LCDisable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void LCAllocOneTag(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void LCAllocTags(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void LCLoadBlocks(void* destTag, void* srcAddr, u32 numBlocks)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void LCStoreBlocks(register void* destAddr, register void* srcTag, register u32 numBlocks)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void LCAlloc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void LCAllocNoInvalidate(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
u32 LCLoadData(void* destAddr, void* srcAddr, u32 nBytes)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
u32 LCStoreData(void* destAddr, void* srcAddr, u32 nBytes)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
u32 LCQueueLength(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void LCQueueWait(register u32 len)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void LCFlushQueue(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void L2Init(void)
{
	u32 oldMSR;

	oldMSR = PPCMfmsr();

	__sync();
	PPCMtmsr(MSR_IR | MSR_DR);
	__sync();

	L2Disable();

	L2GlobalInvalidate();

	PPCMtmsr(oldMSR);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void L2Enable(void)
{
	PPCMtl2cr((PPCMfl2cr() | L2CR_L2E) & ~L2CR_L2I);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void L2Disable(void)
{
	__sync();
	PPCMtl2cr(PPCMfl2cr() & ~L2CR_L2E);
	__sync();
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F6D3C
 * Size:	000098
 */
void L2GlobalInvalidate(void)
{
	L2Disable();

	PPCMtl2cr(PPCMfl2cr() | L2CR_L2I);

	while (PPCMfl2cr() & L2CR_L2IP)
		;

	PPCMtl2cr(PPCMfl2cr() & ~L2CR_L2I);

	while (PPCMfl2cr() & L2CR_L2IP) {
		DBPrintf(">>> L2 INVALIDATE : SHOULD NEVER HAPPEN\n");
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void L2SetDataOnly(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void L2SetWriteThrough(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F6DD4
 * Size:	000160
 */
void DMAErrorHandler(OSError error, OSContext* context, ...)
{
#pragma unused(error)
	u32 hid2 = PPCMfhid2();

	OSReport("Machine check received\n");
	OSReport("HID2 = 0x%x   SRR1 = 0x%x\n", hid2, context->srr1);
	if (!(hid2 & (HID2_DCHERR | HID2_DNCERR | HID2_DCMERR | HID2_DQOERR)) || !(context->srr1 & SRR1_DMA_BIT)) {
		OSReport("Machine check was not DMA/locked cache related\n");
		OSDumpContext(context);
		PPCHalt();
		// spins forever, so not reached
	}

	OSReport("DMAErrorHandler(): An error occurred while processing DMA.\n");
	OSReport("The following errors have been detected and cleared :\n");

	if (hid2 & HID2_DCHERR) {
		OSReport("\t- Requested a locked cache tag that was already in the cache\n");
	}

	if (hid2 & HID2_DNCERR) {
		OSReport("\t- DMA attempted to access normal cache\n");
	}

	if (hid2 & HID2_DCMERR) {
		OSReport("\t- DMA missed in data cache\n");
	}

	if (hid2 & HID2_DQOERR) {
		OSReport("\t- DMA queue overflowed\n");
	}

	// write hid2 back (to clear the error bits)
	PPCMthid2(hid2);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  stw       r30, 0x78(r1)
	  stw       r29, 0x74(r1)
	  bne-      cr1, .loc_0x3C
	  stfd      f1, 0x28(r1)
	  stfd      f2, 0x30(r1)
	  stfd      f3, 0x38(r1)
	  stfd      f4, 0x40(r1)
	  stfd      f5, 0x48(r1)
	  stfd      f6, 0x50(r1)
	  stfd      f7, 0x58(r1)
	  stfd      f8, 0x60(r1)

	.loc_0x3C:
	  stw       r3, 0x8(r1)
	  stw       r4, 0xC(r1)
	  stw       r5, 0x10(r1)
	  stw       r6, 0x14(r1)
	  stw       r7, 0x18(r1)
	  stw       r8, 0x1C(r1)
	  stw       r9, 0x20(r1)
	  stw       r10, 0x24(r1)
	  mr        r29, r4
	  lis       r3, 0x802E
	  addi      r31, r3, 0x74E8
	  bl        -0x14AC
	  mr        r30, r3
	  crclr     6, 0x6
	  addi      r3, r31, 0x2C
	  bl        0xA44
	  lwz       r5, 0x19C(r29)
	  mr        r4, r30
	  addi      r3, r31, 0x44
	  crclr     6, 0x6
	  bl        0xA30
	  rlwinm    r0,r30,0,8,11
	  cmplwi    r0, 0
	  beq-      .loc_0xAC
	  lwz       r0, 0x19C(r29)
	  rlwinm    r0,r0,0,10,10
	  cmplwi    r0, 0
	  bne-      .loc_0xC4

	.loc_0xAC:
	  addi      r3, r31, 0x60
	  crclr     6, 0x6
	  bl        0xA08
	  mr        r3, r29
	  bl        0x68C
	  bl        -0x1518

	.loc_0xC4:
	  addi      r3, r31, 0x90
	  crclr     6, 0x6
	  bl        0x9F0
	  addi      r3, r31, 0xCC
	  crclr     6, 0x6
	  bl        0x9E4
	  rlwinm    r0,r30,0,8,8
	  cmplwi    r0, 0
	  beq-      .loc_0xF4
	  addi      r3, r31, 0x104
	  crclr     6, 0x6
	  bl        0x9CC

	.loc_0xF4:
	  rlwinm    r0,r30,0,9,9
	  cmplwi    r0, 0
	  beq-      .loc_0x10C
	  addi      r3, r31, 0x144
	  crclr     6, 0x6
	  bl        0x9B4

	.loc_0x10C:
	  rlwinm    r0,r30,0,10,10
	  cmplwi    r0, 0
	  beq-      .loc_0x124
	  addi      r3, r31, 0x170
	  crclr     6, 0x6
	  bl        0x99C

	.loc_0x124:
	  rlwinm    r0,r30,0,11,11
	  cmplwi    r0, 0
	  beq-      .loc_0x13C
	  addi      r3, r31, 0x190
	  crclr     6, 0x6
	  bl        0x984

	.loc_0x13C:
	  mr        r3, r30
	  bl        -0x157C
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  mtlr      r0
	  lwz       r29, 0x74(r1)
	  addi      r1, r1, 0x80
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F6F34
 * Size:	0000F4
 */
void __OSCacheInit(void)
{
	if (!(PPCMfhid0() & HID0_ICE)) {
		ICEnable();
		DBPrintf("L1 i-caches initialized\n");
	}
	if (!(PPCMfhid0() & HID0_DCE)) {
		DCEnable();
		DBPrintf("L1 d-caches initialized\n");
	}

	if (!(PPCMfl2cr() & L2CR_L2E)) {
		L2Init();
		L2Enable();
		DBPrintf("L2 cache initialized\n");
	}

	OSSetErrorHandler(OS_ERROR_MACHINE_CHECK, DMAErrorHandler);
	DBPrintf("Locked cache machine check handler installed\n");
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  stw       r30, 0x8(r1)
	  lis       r3, 0x802E
	  addi      r31, r3, 0x74E8
	  bl        -0x15FC
	  rlwinm    r0,r3,0,16,16
	  cmplwi    r0, 0
	  bne-      .loc_0x3C
	  bl        -0x238
	  addi      r3, r31, 0x1AC
	  crclr     6, 0x6
	  bl        0x6BD8

	.loc_0x3C:
	  bl        -0x161C
	  rlwinm    r0,r3,0,17,17
	  cmplwi    r0, 0
	  bne-      .loc_0x5C
	  bl        -0x3DC
	  addi      r3, r31, 0x1C8
	  crclr     6, 0x6
	  bl        0x6BB8

	.loc_0x5C:
	  bl        -0x1634
	  rlwinm    r0,r3,0,0,0
	  cmplwi    r0, 0
	  bne-      .loc_0xC0
	  bl        -0x165C
	  mr        r30, r3
	  sync
	  li        r3, 0x30
	  bl        -0x1664
	  sync
	  sync
	  bl        -0x1660
	  rlwinm    r3,r3,0,1,31
	  bl        -0x1660
	  sync
	  bl        -0x290
	  mr        r3, r30
	  bl        -0x1688
	  bl        -0x167C
	  oris      r0, r3, 0x8000
	  rlwinm    r3,r0,0,11,9
	  bl        -0x1680
	  addi      r3, r31, 0x1E4
	  crclr     6, 0x6
	  bl        0x6B54

	.loc_0xC0:
	  lis       r3, 0x801F
	  addi      r4, r3, 0x6DD4
	  li        r3, 0x1
	  bl        0xA3C
	  addi      r3, r31, 0x1FC
	  crclr     6, 0x6
	  bl        0x6B38
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  lwz       r30, 0x8(r1)
	  mtlr      r0
	  addi      r1, r1, 0x10
	  blr
	*/
}
