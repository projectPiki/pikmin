#include "types.h"
#include "Ayu.h"
#include "system.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void AyuStack::create(char*, int, void*, int, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void AyuStack::reset()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void AyuStack::checkStack()
{
#ifndef __MWERKS__
	if (mAllocType & 2 && mStackTop - *((u32*)mStackTop - 2) != mInitialStackTop) {
		_Error("trashed memory stack (%s)\n", mName);
	}
#endif
}

/*
 * --INFO--
 * Address:	800246E4
 * Size:	0000BC
 */
void AyuStack::reset(int i)
{
	if (i & 2) {
		int prev = setAllocType(i);
		gsys->invalidateObjs(mInitialStackTop, mStackTop);

		while (mStackTop != mInitialStackTop) {
			pop();
		}

		setAllocType(prev);
	}

	if (i & 1) {
		int prev = setAllocType(i);
		gsys->invalidateObjs(mStackLimit, _10);

		while (mStackLimit != _10) {
			pop();
		}

		setAllocType(prev);
	}
}

/*
 * --INFO--
 * Address:	800247A0
 * Size:	000114
 */
void* AyuStack::push(int requestedSize)
{
	if (!requestedSize) {
		requestedSize = 1;
	}

	if (IS_NOT_ALIGNED(requestedSize, 8)) {
		requestedSize = ALIGN_NEXT(requestedSize, 8);
	}

	if (mAllocType == 2) {
		if (requestedSize + 8 + mStackTop > mStackLimit) {
			return nullptr;
		}

		u32 previousSize;
		u32 stackStart;
		if (mStackTop != mInitialStackTop) {
			previousSize = *(u32*)(mStackTop - 4);
			stackStart   = mStackTop - previousSize - 8;
		} else {
			previousSize = 0;
			stackStart   = mStackTop;
		}

		mTotalSize += requestedSize + 8;
		mStackTop += requestedSize + 8;
		*(u32*)mStackLimit = requestedSize + 8;
		checkStack();
		return (void*)stackStart;
	} else {
		if (mStackLimit - (requestedSize + 8) < mStackTop) {
			return nullptr;
		}

		mTotalSize += requestedSize + 8;
		mStackLimit -= requestedSize + 8;
		*(u32*)mStackLimit = requestedSize + 8;
		return (void*)(mStackLimit + 8);
	}
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  bne-      .loc_0xC
	  li        r4, 0x1

	.loc_0xC:
	  rlwinm.   r0,r4,0,29,31
	  beq-      .loc_0x1C
	  addi      r0, r4, 0x7
	  rlwinm    r4,r0,0,0,28

	.loc_0x1C:
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0xC4
	  lwz       r6, 0x14(r3)
	  lwz       r0, 0x18(r3)
	  add       r5, r4, r6
	  addi      r5, r5, 0x8
	  cmplw     r5, r0
	  ble-      .loc_0x48
	  li        r3, 0
	  blr

	.loc_0x48:
	  lwz       r0, 0xC(r3)
	  cmplw     r6, r0
	  beq-      .loc_0x64
	  subi      r5, r6, 0x8
	  lwz       r0, -0x8(r6)
	  mr        r7, r5
	  b         .loc_0x6C

	.loc_0x64:
	  li        r0, 0
	  addi      r7, r6, 0

	.loc_0x6C:
	  lwz       r6, 0x8(r3)
	  add       r5, r4, r0
	  addi      r0, r5, 0x8
	  add       r5, r4, r6
	  addi      r5, r5, 0x8
	  stw       r5, 0x8(r3)
	  lwz       r5, 0x14(r3)
	  add       r4, r4, r5
	  addi      r4, r4, 0x8
	  stw       r4, 0x14(r3)
	  lwz       r4, 0x14(r3)
	  stw       r0, -0x8(r4)
	  lwz       r0, 0x0(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0xBC
	  lwz       r4, 0x14(r3)
	  lwz       r0, 0xC(r3)
	  lwz       r3, -0x8(r4)
	  sub       r3, r4, r3
	  cmplw     r3, r0

	.loc_0xBC:
	  mr        r3, r7
	  blr

	.loc_0xC4:
	  lwz       r5, 0x18(r3)
	  addi      r6, r4, 0x8
	  lwz       r0, 0x14(r3)
	  sub       r5, r5, r6
	  cmplw     r5, r0
	  bge-      .loc_0xE4
	  li        r3, 0
	  blr

	.loc_0xE4:
	  lwz       r0, 0x8(r3)
	  add       r4, r4, r0
	  addi      r0, r4, 0x8
	  stw       r0, 0x8(r3)
	  lwz       r0, 0x18(r3)
	  sub       r0, r0, r6
	  stw       r0, 0x18(r3)
	  lwz       r4, 0x18(r3)
	  stw       r6, 0x0(r4)
	  lwz       r3, 0x18(r3)
	  addi      r3, r3, 0x8
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800248B4
 * Size:	000054
 */
void AyuStack::pop()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x30
	  lwz       r4, 0x14(r3)
	  lwz       r0, 0x8(r3)
	  lwz       r4, -0x8(r4)
	  sub       r0, r0, r4
	  stw       r0, 0x8(r3)
	  lwz       r0, 0x14(r3)
	  sub       r0, r0, r4
	  stw       r0, 0x14(r3)
	  blr

	.loc_0x30:
	  lwz       r4, 0x18(r3)
	  lwz       r0, 0x8(r3)
	  lwz       r4, 0x0(r4)
	  sub       r0, r0, r4
	  stw       r0, 0x8(r3)
	  lwz       r0, 0x18(r3)
	  add       r0, r0, r4
	  stw       r0, 0x18(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80024908
 * Size:	000074
 */
void AyuHeap::init(char*, int, void*, int)
{
	/*
	.loc_0x0:
	  stw       r5, 0x0(r3)
	  li        r5, 0x1
	  li        r0, 0
	  stb       r5, 0x1D(r3)
	  stw       r4, 0x20(r3)
	  stw       r6, 0xC(r3)
	  lwz       r4, 0xC(r3)
	  add       r4, r4, r7
	  stw       r4, 0x10(r3)
	  lwz       r5, 0xC(r3)
	  lwz       r4, 0x10(r3)
	  sub       r4, r4, r5
	  stw       r4, 0x4(r3)
	  stb       r0, 0x1C(r3)
	  lbz       r0, 0x1C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x54
	  lis       r5, 0x1234
	  lwz       r4, 0xC(r3)
	  addi      r0, r5, 0x5678
	  stw       r0, 0x0(r4)

	.loc_0x54:
	  lwz       r4, 0xC(r3)
	  li        r0, 0
	  stw       r4, 0x14(r3)
	  lwz       r4, 0x10(r3)
	  stw       r4, 0x18(r3)
	  stw       r0, 0x8(r3)
	  stb       r0, 0x24(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8002497C
 * Size:	000068
 */
AyuCache::AyuCache(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x4330
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x1F
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  rlwinm    r31,r0,0,0,26
	  srawi     r0, r31, 0x2
	  stw       r4, 0x14(r1)
	  addze     r0, r0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  rlwinm    r3,r0,2,0,29
	  stw       r5, 0x10(r1)
	  bl        0x22650
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  add       r5, r4, r31
	  bl        .loc_0x68
	  mr        r3, r30
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0x68:
	*/
}

/*
 * --INFO--
 * Address:	800249E4
 * Size:	000198
 */
void AyuCache::init(u32, u32)
{
	/*
	.loc_0x0:
	  li        r8, 0
	  stw       r8, 0x24(r3)
	  sub       r0, r5, r4
	  lis       r6, 0x8765
	  stw       r0, 0x28(r3)
	  rlwinm    r5,r0,28,4,31
	  subis     r5, r5, 0x100
	  stw       r8, 0x20(r3)
	  addi      r7, r3, 0x10
	  li        r0, 0x8
	  stw       r7, 0x14(r3)
	  addi      r6, r6, 0x4321
	  subi      r5, r5, 0x1
	  mtctr     r0
	  stw       r7, 0x18(r3)
	  lis       r0, 0xFF00
	  stw       r8, 0x10(r3)
	  li        r11, 0
	  stw       r6, 0x1C(r3)
	  stw       r3, 0x4(r4)
	  stw       r3, 0x8(r4)
	  stw       r5, 0x0(r4)
	  stw       r6, 0xC(r4)
	  stw       r4, 0x4(r3)
	  stw       r4, 0x8(r3)
	  stw       r0, 0x0(r3)

	.loc_0x68:
	  addi      r10, r11, 0x2C
	  add       r10, r3, r10
	  stb       r11, 0x0(r10)
	  addi      r9, r11, 0x1
	  addi      r8, r11, 0x2
	  stb       r9, 0x1(r10)
	  addi      r7, r11, 0x3
	  addi      r6, r11, 0x4
	  stb       r8, 0x2(r10)
	  addi      r5, r11, 0x5
	  addi      r4, r11, 0x6
	  stb       r7, 0x3(r10)
	  addi      r0, r11, 0x7
	  addi      r11, r11, 0x8
	  stb       r6, 0x4(r10)
	  addi      r9, r11, 0x1
	  addi      r8, r11, 0x2
	  stb       r5, 0x5(r10)
	  addi      r7, r11, 0x3
	  addi      r6, r11, 0x4
	  stb       r4, 0x6(r10)
	  addi      r5, r11, 0x5
	  addi      r4, r11, 0x6
	  stb       r0, 0x7(r10)
	  addi      r10, r11, 0x2C
	  add       r10, r3, r10
	  stb       r11, 0x0(r10)
	  addi      r0, r11, 0x7
	  addi      r11, r11, 0x8
	  stb       r9, 0x1(r10)
	  addi      r9, r11, 0x1
	  stb       r8, 0x2(r10)
	  addi      r8, r11, 0x2
	  stb       r7, 0x3(r10)
	  addi      r7, r11, 0x3
	  stb       r6, 0x4(r10)
	  addi      r6, r11, 0x4
	  stb       r5, 0x5(r10)
	  addi      r5, r11, 0x5
	  stb       r4, 0x6(r10)
	  addi      r4, r11, 0x6
	  stb       r0, 0x7(r10)
	  addi      r10, r11, 0x2C
	  add       r10, r3, r10
	  stb       r11, 0x0(r10)
	  addi      r0, r11, 0x7
	  addi      r11, r11, 0x8
	  stb       r9, 0x1(r10)
	  addi      r9, r11, 0x1
	  stb       r8, 0x2(r10)
	  addi      r8, r11, 0x2
	  stb       r7, 0x3(r10)
	  addi      r7, r11, 0x3
	  stb       r6, 0x4(r10)
	  addi      r6, r11, 0x4
	  stb       r5, 0x5(r10)
	  addi      r5, r11, 0x5
	  stb       r4, 0x6(r10)
	  addi      r4, r11, 0x6
	  stb       r0, 0x7(r10)
	  addi      r10, r11, 0x2C
	  add       r10, r3, r10
	  stb       r11, 0x0(r10)
	  addi      r0, r11, 0x7
	  addi      r11, r11, 0x8
	  stb       r9, 0x1(r10)
	  stb       r8, 0x2(r10)
	  stb       r7, 0x3(r10)
	  stb       r6, 0x4(r10)
	  stb       r5, 0x5(r10)
	  stb       r4, 0x6(r10)
	  stb       r0, 0x7(r10)
	  bdnz+     .loc_0x68
	  li        r0, 0
	  stw       r0, 0x12C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void AyuCache::getIndex()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void AyuCache::releaseIndex(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void linkChunk(MemHead*, u32, MemHead*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80024B7C
 * Size:	000120
 */
void AyuCache::mallocL(u32)
{
	/*
	.loc_0x0:
	  addi      r0, r4, 0xF
	  lwz       r6, 0x4(r3)
	  lis       r4, 0x8000
	  rlwinm    r7,r0,28,4,31
	  subi      r0, r4, 0x1
	  li        r4, 0
	  b         .loc_0x40

	.loc_0x1C:
	  lwz       r5, 0x0(r6)
	  rlwinm    r5,r5,0,8,31
	  sub.      r5, r5, r7
	  blt-      .loc_0x3C
	  cmpw      r5, r0
	  bge-      .loc_0x3C
	  mr        r4, r6
	  b         .loc_0x48

	.loc_0x3C:
	  lwz       r6, 0x4(r6)

	.loc_0x40:
	  cmplw     r6, r3
	  bne+      .loc_0x1C

	.loc_0x48:
	  cmplwi    r4, 0
	  bne-      .loc_0x58
	  li        r3, 0
	  blr

	.loc_0x58:
	  lwz       r0, 0x0(r4)
	  rlwinm    r0,r0,0,8,31
	  cmplw     r0, r7
	  bne-      .loc_0x84
	  lwz       r0, 0x8(r4)
	  lwz       r5, 0x4(r4)
	  stw       r0, 0x8(r5)
	  lwz       r0, 0x4(r4)
	  lwz       r5, 0x8(r4)
	  stw       r0, 0x4(r5)
	  b         .loc_0xCC

	.loc_0x84:
	  rlwinm    r5,r7,4,0,27
	  lwz       r0, 0x4(r4)
	  addi      r6, r5, 0x10
	  add       r6, r4, r6
	  stw       r0, 0x4(r6)
	  lis       r5, 0x8765
	  addi      r0, r5, 0x4321
	  lwz       r5, 0x8(r4)
	  stw       r5, 0x8(r6)
	  lwz       r5, 0x4(r6)
	  stw       r6, 0x8(r5)
	  lwz       r5, 0x8(r6)
	  stw       r6, 0x4(r5)
	  lwz       r5, 0x0(r4)
	  sub       r5, r5, r7
	  subi      r5, r5, 0x1
	  stw       r5, 0x0(r6)
	  stw       r0, 0xC(r6)

	.loc_0xCC:
	  lwz       r6, 0x20(r3)
	  addi      r0, r3, 0x10
	  lis       r5, 0x1234
	  stw       r0, 0x4(r4)
	  rlwinm    r0,r6,24,0,7
	  add       r7, r0, r7
	  lwz       r6, 0x18(r3)
	  addi      r0, r5, 0x5678
	  stw       r6, 0x8(r4)
	  stw       r4, 0x18(r3)
	  lwz       r5, 0x8(r4)
	  stw       r4, 0x4(r5)
	  stw       r7, 0x0(r4)
	  lwz       r5, 0x0(r4)
	  lwz       r6, 0x24(r3)
	  rlwinm    r5,r5,0,8,31
	  add       r5, r6, r5
	  stw       r5, 0x24(r3)
	  addi      r3, r4, 0x10
	  stw       r0, 0xC(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80024C9C
 * Size:	000114
 */
void AyuCache::cacheFree(void*)
{
	/*
	.loc_0x0:
	  lwzu      r5, -0x10(r4)
	  addi      r6, r3, 0
	  lwz       r0, 0x24(r3)
	  rlwinm    r5,r5,0,8,31
	  sub       r0, r0, r5
	  stw       r0, 0x24(r3)
	  lwz       r5, 0x4(r3)
	  b         .loc_0x30

	.loc_0x20:
	  cmplw     r4, r5
	  bge-      .loc_0x2C
	  mr        r6, r5

	.loc_0x2C:
	  lwz       r5, 0x4(r5)

	.loc_0x30:
	  cmplw     r5, r3
	  beq-      .loc_0x40
	  cmplw     r6, r3
	  beq+      .loc_0x20

	.loc_0x40:
	  lwz       r0, 0x8(r4)
	  lwz       r3, 0x4(r4)
	  stw       r0, 0x8(r3)
	  lwz       r0, 0x4(r4)
	  lwz       r3, 0x8(r4)
	  stw       r0, 0x4(r3)
	  lwz       r0, 0x0(r4)
	  rlwinm    r3,r0,0,8,31
	  stw       r6, 0x4(r4)
	  subis     r5, r3, 0x100
	  lwz       r0, 0x8(r6)
	  stw       r0, 0x8(r4)
	  stw       r4, 0x8(r6)
	  lwz       r3, 0x8(r4)
	  stw       r4, 0x4(r3)
	  stw       r5, 0x0(r4)
	  lwz       r5, 0x0(r4)
	  lwz       r6, 0x4(r4)
	  rlwinm    r3,r5,4,4,27
	  addi      r0, r3, 0x10
	  add       r0, r4, r0
	  cmplw     r0, r6
	  bne-      .loc_0xC8
	  lwz       r0, 0x0(r6)
	  rlwinm    r0,r0,0,8,31
	  add       r3, r0, r5
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x4(r3)
	  stw       r4, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x4(r4)

	.loc_0xC8:
	  lwz       r6, 0x8(r4)
	  lwz       r5, 0x0(r6)
	  rlwinm    r3,r5,4,4,27
	  addi      r0, r3, 0x10
	  add       r0, r6, r0
	  cmplw     r0, r4
	  bnelr-
	  lwz       r0, 0x0(r4)
	  rlwinm    r0,r0,0,8,31
	  add       r3, r0, r5
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r6)
	  lwz       r0, 0x8(r4)
	  lwz       r3, 0x4(r4)
	  stw       r0, 0x8(r3)
	  lwz       r0, 0x4(r4)
	  lwz       r3, 0x8(r4)
	  stw       r0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void AyuCache::deleteIdAll(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void AyuCache::amountFree()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80024DB0
 * Size:	000018
 */
bool AyuCache::isEmpty()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x14(r3)
	  addi      r0, r3, 0x10
	  sub       r0, r0, r4
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80024DC8
 * Size:	000034
 */
void AyuCache::largestBlockFree()
{
	/*
	.loc_0x0:
	  lwz       r5, 0x4(r3)
	  li        r4, 0
	  b         .loc_0x24

	.loc_0xC:
	  lwz       r0, 0x0(r5)
	  rlwinm    r0,r0,4,4,27
	  cmplw     r0, r4
	  ble-      .loc_0x20
	  mr        r4, r0

	.loc_0x20:
	  lwz       r5, 0x4(r5)

	.loc_0x24:
	  cmplw     r5, r3
	  bne+      .loc_0xC
	  mr        r3, r4
	  blr
	*/
}
