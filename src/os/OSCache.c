#include "Dolphin/PPCArch.h"
#include "Dolphin/db.h"
#include "Dolphin/os.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000010
 */
void DCFlashInvalidate(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000014
 */
void DCDisable(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000014
 */
void DCFreeze(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000010
 */
void DCUnfreeze(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void DCTouchLoad(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void DCBlockZero(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void DCBlockStore(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void DCBlockFlush(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void DCBlockInvalidate(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

	sc

	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
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

	sc

	blr
#endif // clang-format on
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
void DCTouchRange(register void* addr, register u32 nBytes)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000014
 */
void ICDisable(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000014
 */
void ICFreeze(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000010
 */
void ICUnfreeze(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void ICBlockInvalidate(void*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void ICSync(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000CC
 */
void __LCEnable(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000038
 */
void LCEnable(void)
{
	// UNUSED FUNCTION
}

#define LC_LINES    512
#define CACHE_LINES 1024

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
ASM void LCDisable(void)
{
#ifdef __MWERKS__ // clang-format off
  nofralloc
  lis     r3, LC_BASE_PREFIX
  li      r4, LC_LINES
  mtctr r4
@1
  dcbi r0, r3
  addi r3, r3, 32
  bdnz @1
  mfspr r4, HID2
  rlwinm r4, r4, 0, 4, 2
  mtspr HID2, r4
  blr

#endif // clang-format on \
    // UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000014
 */
void LCAllocOneTag(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void LCAllocTags(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
void LCLoadBlocks(void* destTag, void* srcAddr, u32 numBlocks)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
void LCStoreBlocks(register void* destAddr, register void* srcTag, register u32 numBlocks)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070
 */
void LCAlloc(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070
 */
void LCAllocNoInvalidate(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000AC
 */
u32 LCLoadData(void* destAddr, void* srcAddr, u32 nBytes)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000AC
 */
u32 LCStoreData(void* destAddr, void* srcAddr, u32 nBytes)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
u32 LCQueueLength(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000018
 */
void LCQueueWait(register u32 len)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000048
 */
void LCFlushQueue(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00002C
 */
void L2Enable(void)
{
	PPCMtl2cr((PPCMfl2cr() | L2CR_L2E) & ~L2CR_L2I);
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
void L2Disable(void)
{
	__sync();
	PPCMtl2cr(PPCMfl2cr() & ~L2CR_L2E);
	__sync();
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void L2SetDataOnly(int)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void L2SetWriteThrough(int)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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
