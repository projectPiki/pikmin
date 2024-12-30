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
}
