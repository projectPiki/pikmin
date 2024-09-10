#include "types.h"
#include "system.h"
#include "Texture.h"
#include "Animator.h"
#include "sysNew.h"
#include "CmdStream.h"
#include "stl/string.h"

static char file[] = __FILE__;
static char name[] = "StdSystem";

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
 * Address:	8003EE34
 * Size:	000030
 */
void AnmobjInfo::detach() { mAnimation->detach(); }

/*
 * --INFO--
 * Address:	8003EE64
 * Size:	000144
 */
StdSystem::StdSystem()
    : _200("CoreNode")
    , _214("CoreNode")
{
	mConsFont         = nullptr;
	mCurrentFade      = 0.0f;
	mFadeStart        = 0.0f;
	mFadeEnd          = 1.0;
	mToggleFileInfo   = 1;
	_198              = 0;
	mGfxobjInfo.mPrev = &mGfxobjInfo;
	mGfxobjInfo.mNext = &mGfxobjInfo;
	mHasGfxObjects    = true;
	mLightFlares      = nullptr;

	initSoftReset();
	mDataRoot = "dataDir/";
	_19C      = 0;
}

/*
 * --INFO--
 * Address:	8003EFB4
 * Size:	000068
 */
void StdSystem::onceInit()
{
	mMatrixCount = 0x2000;
	mMatrices    = new (0x20) Matrix4f[mMatrixCount];
}

/*
 * --INFO--
 * Address:	8003F020
 * Size:	000014
 */
AyuHeap* StdSystem::getHeap(int heapIdx) { return &mHeaps[heapIdx]; }

/*
 * --INFO--
 * Address:	8003F034
 * Size:	000034
 */
void StdSystem::resetHeap(int heapIdx, int flag) { mHeaps[heapIdx].reset(flag); }

/*
 * --INFO--
 * Address:	8003F068
 * Size:	000010
 */
int StdSystem::setHeap(int newHeapIdx)
{
	int oldIdx     = mActiveHeapIdx;
	mActiveHeapIdx = newHeapIdx;
	return oldIdx;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void StdSystem::getAppMemory(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8003F078
 * Size:	000090
 */
void StdSystem::findGfxObject(char*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0x1D0
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  addi      r29, r5, 0
	  stw       r28, 0x18(r1)
	  addi      r28, r4, 0
	  lwz       r30, 0x1D4(r3)
	  b         .loc_0x64

	.loc_0x30:
	  addi      r3, r30, 0xC
	  addi      r4, r29, 0
	  bl        0x4F30
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x60
	  lwz       r3, 0x8(r30)
	  mr        r4, r28
	  bl        0x1DA100
	  cmpwi     r3, 0
	  bne-      .loc_0x60
	  mr        r3, r30
	  b         .loc_0x70

	.loc_0x60:
	  lwz       r30, 0x4(r30)

	.loc_0x64:
	  cmplw     r30, r31
	  bne+      .loc_0x30
	  li        r3, 0

	.loc_0x70:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void StdSystem::findAnyGfxObject(char*, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8003F108
 * Size:	0000F4
 */
Texture* StdSystem::loadTexture(char*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r26, 0x18(r1)
	  mr        r26, r3
	  addi      r27, r4, 0
	  addi      r28, r5, 0
	  addi      r31, r26, 0x1D0
	  lis       r30, 0x5F74
	  lwz       r29, 0x1D4(r3)
	  b         .loc_0x5C

	.loc_0x2C:
	  addi      r3, r29, 0xC
	  addi      r4, r30, 0x6578
	  bl        0x4EA4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x58
	  lwz       r3, 0x8(r29)
	  mr        r4, r27
	  bl        0x1DA074
	  cmpwi     r3, 0
	  bne-      .loc_0x58
	  b         .loc_0x68

	.loc_0x58:
	  lwz       r29, 0x4(r29)

	.loc_0x5C:
	  cmplw     r29, r31
	  bne+      .loc_0x2C
	  li        r29, 0

	.loc_0x68:
	  cmplwi    r29, 0
	  beq-      .loc_0x78
	  lwz       r3, 0x20(r29)
	  b         .loc_0xE0

	.loc_0x78:
	  mr        r3, r26
	  lwz       r12, 0x1A0(r26)
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  lwz       r12, 0xC(r12)
	  li        r29, 0
	  li        r6, 0x1
	  mtlr      r12
	  blrl
	  mr.       r30, r3
	  beq-      .loc_0xDC
	  li        r3, 0x3C
	  bl        0x7E54
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xBC
	  bl        0x4FD4

	.loc_0xBC:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0x510C
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0xDC:
	  mr        r3, r29

	.loc_0xE0:
	  lmw       r26, 0x18(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8003F1FC
 * Size:	000008
 */
BufferedInputStream* StdSystem::openFile(char*, bool, bool) { return nullptr; }

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void StdSystem::findTexture(Texture*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8003F204
 * Size:	0001A8
 */
void StdSystem::loadShape(char*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r5,0,24,31
	  stwu      r1, -0x130(r1)
	  stmw      r26, 0x118(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  li        r31, 0
	  beq-      .loc_0x7C
	  lwz       r26, 0x1D4(r29)
	  addi      r28, r29, 0x1D0
	  lis       r27, 0x5F73
	  b         .loc_0x64

	.loc_0x34:
	  addi      r3, r26, 0xC
	  addi      r4, r27, 0x6870
	  bl        0x4DA0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x60
	  lwz       r3, 0x8(r26)
	  mr        r4, r30
	  bl        0x1D9F70
	  cmpwi     r3, 0
	  bne-      .loc_0x60
	  b         .loc_0x70

	.loc_0x60:
	  lwz       r26, 0x4(r26)

	.loc_0x64:
	  cmplw     r26, r28
	  bne+      .loc_0x34
	  li        r26, 0

	.loc_0x70:
	  cmplwi    r26, 0
	  beq-      .loc_0x7C
	  lwz       r31, 0x20(r26)

	.loc_0x7C:
	  cmplwi    r31, 0
	  bne-      .loc_0x190
	  addi      r5, r30, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x14
	  subi      r4, r13, 0x7A04
	  bl        0x1D7300
	  li        r26, 0
	  addi      r3, r1, 0x14
	  bl        0x1DA168
	  subic.    r4, r3, 0x1
	  addi      r0, r4, 0x1
	  mtctr     r0
	  add       r3, r30, r4
	  blt-      .loc_0xE8

	.loc_0xB8:
	  lbz       r0, 0x0(r3)
	  cmplwi    r0, 0x3F
	  bne-      .loc_0xDC
	  addi      r3, r1, 0x14
	  li        r0, 0
	  addi      r26, r1, 0x15
	  stbx      r0, r3, r4
	  add       r26, r26, r4
	  b         .loc_0xE8

	.loc_0xDC:
	  subi      r4, r4, 0x1
	  subi      r3, r3, 0x1
	  bdnz+     .loc_0xB8

	.loc_0xE8:
	  addi      r3, r29, 0
	  addi      r5, r30, 0
	  addi      r6, r26, 0
	  addi      r4, r1, 0x14
	  li        r7, 0x1
	  bl        0x5DC
	  mr.       r31, r3
	  beq-      .loc_0x190
	  li        r3, 0x24
	  bl        0x7CF4
	  mr.       r26, r3
	  beq-      .loc_0x164
	  lis       r3, 0x8023
	  subi      r0, r3, 0x795C
	  stw       r0, 0x1C(r26)
	  addi      r3, r26, 0xC
	  bl        0x4B30
	  li        r28, 0
	  stw       r28, 0x4(r26)
	  lis       r4, 0x6E6F
	  subi      r0, r13, 0x7A08
	  stw       r28, 0x0(r26)
	  addi      r3, r26, 0xC
	  addi      r4, r4, 0x6E65
	  stw       r0, 0x8(r26)
	  bl        0x4B74
	  lis       r3, 0x8023
	  stw       r28, 0x18(r26)
	  subi      r0, r3, 0x72E8
	  stw       r0, 0x1C(r26)
	  stw       r28, 0x20(r26)

	.loc_0x164:
	  mr        r3, r30
	  bl        0xFD4
	  stw       r3, 0x8(r26)
	  lis       r4, 0x5F73
	  addi      r3, r26, 0xC
	  addi      r4, r4, 0x6870
	  bl        0x4B44
	  stw       r31, 0x20(r26)
	  addi      r3, r29, 0
	  addi      r4, r26, 0
	  bl        0x2D4

	.loc_0x190:
	  mr        r3, r31
	  lmw       r26, 0x118(r1)
	  lwz       r0, 0x134(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8003F3AC
 * Size:	0000A0
 */
void StdSystem::findAnimation(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0x1D0
	  stw       r30, 0x20(r1)
	  lis       r30, 0x5F61
	  stw       r29, 0x1C(r1)
	  stw       r28, 0x18(r1)
	  addi      r28, r4, 0
	  lwz       r29, 0x1D4(r3)
	  b         .loc_0x60

	.loc_0x30:
	  addi      r3, r29, 0xC
	  addi      r4, r30, 0x6E6D
	  bl        0x4BFC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5C
	  lwz       r3, 0x8(r29)
	  mr        r4, r28
	  bl        0x1D9DCC
	  cmpwi     r3, 0
	  bne-      .loc_0x5C
	  b         .loc_0x6C

	.loc_0x5C:
	  lwz       r29, 0x4(r29)

	.loc_0x60:
	  cmplw     r29, r31
	  bne+      .loc_0x30
	  li        r29, 0

	.loc_0x6C:
	  cmplwi    r29, 0
	  beq-      .loc_0x7C
	  lwz       r3, 0x20(r29)
	  b         .loc_0x80

	.loc_0x7C:
	  li        r3, 0

	.loc_0x80:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void StdSystem::findAnyAnimation(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void StdSystem::findIndexAnimation(char*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8003F44C
 * Size:	0000A4
 */
void StdSystem::findAnyIndex(char*, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r26, 0x18(r1)
	  addi      r26, r4, 0
	  addi      r27, r5, 0
	  addi      r31, r3, 0x1D0
	  li        r29, 0
	  lis       r30, 0x5F61
	  lwz       r28, 0x1D4(r3)
	  b         .loc_0x84

	.loc_0x2C:
	  addi      r3, r28, 0xC
	  addi      r4, r30, 0x6E6D
	  bl        0x4B60
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x80
	  mr        r3, r26
	  bl        0x1D9F7C
	  mr        r5, r3
	  lwz       r3, 0x8(r28)
	  mr        r4, r26
	  bl        0x1D9CE4
	  cmpwi     r3, 0
	  bne-      .loc_0x80
	  lwz       r3, 0x8(r28)
	  mr        r4, r27
	  bl        0x1D9D10
	  cmpwi     r3, 0
	  bne-      .loc_0x7C
	  mr        r3, r29
	  b         .loc_0x90

	.loc_0x7C:
	  addi      r29, r29, 0x1

	.loc_0x80:
	  lwz       r28, 0x4(r28)

	.loc_0x84:
	  cmplw     r28, r31
	  bne+      .loc_0x2C
	  li        r3, 0

	.loc_0x90:
	  lmw       r26, 0x18(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8003F4F0
 * Size:	0000BC
 */
void StdSystem::loadAnimation(Shape*, char*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r25, 0x24(r1)
	  mr        r25, r3
	  addi      r26, r4, 0
	  addi      r27, r5, 0
	  addi      r28, r6, 0
	  addi      r31, r25, 0x1D0
	  lis       r30, 0x5F61
	  lwz       r29, 0x1D4(r3)
	  b         .loc_0x60

	.loc_0x30:
	  addi      r3, r29, 0xC
	  addi      r4, r30, 0x6E6D
	  bl        0x4AB8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5C
	  lwz       r3, 0x8(r29)
	  mr        r4, r27
	  bl        0x1D9C88
	  cmpwi     r3, 0
	  bne-      .loc_0x5C
	  b         .loc_0x6C

	.loc_0x5C:
	  lwz       r29, 0x4(r29)

	.loc_0x60:
	  cmplw     r29, r31
	  bne+      .loc_0x30
	  li        r29, 0

	.loc_0x6C:
	  cmplwi    r29, 0
	  beq-      .loc_0x7C
	  lwz       r3, 0x20(r29)
	  b         .loc_0xA8

	.loc_0x7C:
	  addi      r3, r26, 0
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  bl        -0xA784
	  mr.       r29, r3
	  beq-      .loc_0xA4
	  addi      r3, r25, 0
	  addi      r4, r29, 0
	  addi      r5, r27, 0
	  bl        .loc_0xBC

	.loc_0xA4:
	  mr        r3, r29

	.loc_0xA8:
	  lmw       r25, 0x24(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr

	.loc_0xBC:
	*/
}

/*
 * --INFO--
 * Address:	8003F5AC
 * Size:	0000B8
 */
void StdSystem::addAnimation(AnimData*, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  li        r3, 0x24
	  bl        0x7A38
	  mr.       r30, r3
	  beq-      .loc_0x78
	  lis       r3, 0x8023
	  subi      r0, r3, 0x795C
	  stw       r0, 0x1C(r30)
	  addi      r3, r30, 0xC
	  bl        0x4874
	  li        r31, 0
	  stw       r31, 0x4(r30)
	  lis       r4, 0x6E6F
	  subi      r0, r13, 0x7A08
	  stw       r31, 0x0(r30)
	  addi      r3, r30, 0xC
	  addi      r4, r4, 0x6E65
	  stw       r0, 0x8(r30)
	  bl        0x48B8
	  lis       r3, 0x8023
	  stw       r31, 0x18(r30)
	  subi      r0, r3, 0x7294
	  stw       r0, 0x1C(r30)
	  stw       r31, 0x20(r30)

	.loc_0x78:
	  mr        r3, r29
	  bl        0xD18
	  stw       r3, 0x8(r30)
	  lis       r4, 0x5F61
	  addi      r3, r30, 0xC
	  addi      r4, r4, 0x6E6D
	  bl        0x4888
	  stw       r28, 0x20(r30)
	  addi      r3, r27, 0
	  addi      r4, r30, 0
	  bl        .loc_0xB8
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0xB8:
	*/
}

/*
 * --INFO--
 * Address:	8003F664
 * Size:	000028
 */
void StdSystem::addGfxObject(GfxobjInfo*)
{
	/*
	.loc_0x0:
	  lwz       r6, 0x1D4(r3)
	  addi      r5, r3, 0x1D0
	  li        r0, 0x1
	  stw       r6, 0x4(r4)
	  stw       r5, 0x0(r4)
	  lwz       r5, 0x1D4(r3)
	  stw       r4, 0x0(r5)
	  stw       r4, 0x1D4(r3)
	  stb       r0, 0x1F0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8003F68C
 * Size:	00009C
 */
void StdSystem::attachObjs()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  lbz       r0, 0x1F0(r28)
	  lwz       r3, 0x2DEC(r13)
	  cmplwi    r0, 0
	  lwz       r3, 0x26C(r3)
	  beq-      .loc_0x7C
	  lwz       r29, 0x1D4(r28)
	  addi      r31, r28, 0x1D0
	  li        r30, 0x1
	  b         .loc_0x6C

	.loc_0x44:
	  lwz       r0, 0x18(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x68
	  mr        r3, r29
	  lwz       r12, 0x1C(r29)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r30, 0x18(r29)

	.loc_0x68:
	  lwz       r29, 0x4(r29)

	.loc_0x6C:
	  cmplw     r29, r31
	  bne+      .loc_0x44
	  li        r0, 0
	  stb       r0, 0x1F0(r28)

	.loc_0x7C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8003F728
 * Size:	000088
 */
void StdSystem::detachObjs()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  addi      r31, r28, 0x1D0
	  lwz       r29, 0x1D4(r3)
	  b         .loc_0x58

	.loc_0x30:
	  lwz       r0, 0x18(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x54
	  mr        r3, r29
	  lwz       r12, 0x1C(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stw       r30, 0x18(r29)

	.loc_0x54:
	  lwz       r29, 0x4(r29)

	.loc_0x58:
	  cmplw     r29, r31
	  bne+      .loc_0x30
	  li        r0, 0x1
	  stb       r0, 0x1F0(r28)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8003F7B0
 * Size:	000048
 */
void StdSystem::invalidateObjs(u32, u32)
{
	/*
	.loc_0x0:
	  lwz       r8, 0x1D4(r3)
	  addi      r0, r3, 0x1D0
	  b         .loc_0x3C

	.loc_0xC:
	  lwz       r6, 0x4(r8)
	  cmplw     r8, r4
	  addi      r7, r6, 0
	  blt-      .loc_0x38
	  cmplw     r8, r5
	  bge-      .loc_0x38
	  lwz       r3, 0x0(r8)
	  stw       r3, 0x0(r6)
	  lwz       r6, 0x4(r8)
	  lwz       r3, 0x0(r8)
	  stw       r6, 0x4(r3)

	.loc_0x38:
	  mr        r8, r7

	.loc_0x3C:
	  cmplw     r8, r0
	  bne+      .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8003F7F8
 * Size:	0000D4
 */
void StdSystem::addTexture(Texture*, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  li        r3, 0x24
	  bl        0x77EC
	  mr.       r30, r3
	  beq-      .loc_0x78
	  lis       r3, 0x8023
	  subi      r0, r3, 0x795C
	  stw       r0, 0x1C(r30)
	  addi      r3, r30, 0xC
	  bl        0x4628
	  li        r31, 0
	  stw       r31, 0x4(r30)
	  lis       r4, 0x6E6F
	  subi      r0, r13, 0x7A08
	  stw       r31, 0x0(r30)
	  addi      r3, r30, 0xC
	  addi      r4, r4, 0x6E65
	  stw       r0, 0x8(r30)
	  bl        0x466C
	  lis       r3, 0x8023
	  stw       r31, 0x18(r30)
	  subi      r0, r3, 0x7310
	  stw       r0, 0x1C(r30)
	  stw       r31, 0x20(r30)

	.loc_0x78:
	  mr        r3, r29
	  bl        0xACC
	  stw       r3, 0x8(r30)
	  lis       r4, 0x5F74
	  addi      r3, r30, 0xC
	  addi      r4, r4, 0x6578
	  bl        0x463C
	  stw       r28, 0x20(r30)
	  addi      r3, r27, 0x1D0
	  li        r0, 0x1
	  stw       r30, 0x38(r28)
	  lwz       r4, 0x1D4(r27)
	  stw       r4, 0x4(r30)
	  stw       r3, 0x0(r30)
	  lwz       r3, 0x1D4(r27)
	  stw       r30, 0x0(r3)
	  stw       r30, 0x1D4(r27)
	  stb       r0, 0x1F0(r27)
	  lwz       r0, 0x34(r1)
	  lmw       r27, 0x1C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8003F8CC
 * Size:	000010
 */
void StdSystem::initSoftReset()
{
	CmdStream::statbuff = nullptr;
	mCurrentShape       = nullptr;
}

/*
 * --INFO--
 * Address:	8003F8DC
 * Size:	000108
 */
void StdSystem::getShape(char*, char*, char*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  mr        r26, r3
	  mr        r28, r6
	  addi      r27, r5, 0
	  addi      r5, r7, 0
	  li        r30, 0
	  li        r6, 0x1
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr.       r29, r3
	  beq-      .loc_0x9C
	  li        r3, 0x2B0
	  bl        0x76E0
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x5C
	  bl        0xCE20

	.loc_0x5C:
	  stw       r31, 0x1FC(r26)
	  addi      r30, r31, 0
	  addi      r3, r27, 0
	  bl        0x9FC
	  stw       r3, 0x4(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x9C:
	  cmplwi    r30, 0
	  beq-      .loc_0xF0
	  lwz       r4, 0x2DEC(r13)
	  subi      r31, r13, 0x7A08
	  addi      r3, r30, 0
	  stw       r31, 0x1F4(r4)
	  stw       r28, 0x1F8(r4)
	  bl        -0xF388
	  mr        r3, r30
	  bl        -0xBE9C
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0xC0F0
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r30
	  stw       r31, 0x1F4(r4)
	  stw       r31, 0x1F8(r4)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0xF0:
	  mr        r3, r30
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8003F9E4
 * Size:	000068
 */
void StdSystem::initLFlares(int count)
{
	mLfInfoCount = count;
	mLfInfo      = new LFInfo[count];
	resetLFlares();
}

/*
 * --INFO--
 * Address:	8003FA68
 * Size:	00000C
 */
void StdSystem::resetLFlares() { mFlareCount = 0; }

/*
 * --INFO--
 * Address:	8003FA74
 * Size:	000038
 */
LFInfo* StdSystem::getLFlareInfo()
{
	if (mFlareCount < mLfInfoCount) {
		mFlareCount++;
		return &mLfInfo[mFlareCount - 1];
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	8003FAAC
 * Size:	0000DC
 */
LFlareGroup* StdSystem::registerLFlare(Texture*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r3, 0x238(r3)
	  lwz       r3, 0x10(r3)
	  b         .loc_0x40

	.loc_0x2C:
	  lwz       r0, 0x18(r3)
	  cmplw     r0, r30
	  bne-      .loc_0x3C
	  b         .loc_0xC0

	.loc_0x3C:
	  lwz       r3, 0xC(r3)

	.loc_0x40:
	  cmplwi    r3, 0
	  bne+      .loc_0x2C
	  li        r3, 0x28
	  bl        0x750C
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0xAC
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x0(r31)
	  li        r5, 0
	  lis       r3, 0x8023
	  stw       r5, 0x10(r31)
	  subi      r4, r13, 0x7A00
	  subi      r3, r3, 0x736C
	  stw       r5, 0xC(r31)
	  li        r0, 0x1
	  stw       r5, 0x8(r31)
	  stw       r4, 0x4(r31)
	  stw       r3, 0x0(r31)
	  stw       r5, 0x18(r31)
	  stw       r5, 0x1C(r31)
	  stw       r5, 0x20(r31)
	  stw       r0, 0x24(r31)

	.loc_0xAC:
	  stw       r30, 0x18(r31)
	  mr        r4, r31
	  lwz       r3, 0x238(r29)
	  bl        0xA74
	  mr        r3, r31

	.loc_0xC0:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8003FB88
 * Size:	00024C
 */
void StdSystem::flushLFlares(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r27, r4, 0
	  addi      r28, r3, 0
	  addi      r5, r1, 0x10
	  addi      r3, r27, 0
	  li        r4, 0x1
	  stb       r0, 0x10(r1)
	  lfs       f1, -0x7C0C(r2)
	  stb       r0, 0x11(r1)
	  stb       r0, 0x12(r1)
	  stb       r0, 0x13(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r6, 0x2E4(r27)
	  lwz       r12, 0xBC(r12)
	  lfs       f2, 0x1D0(r6)
	  mtlr      r12
	  lfs       f3, 0x1D4(r6)
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0x1
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r27, 0
	  lwz       r12, 0x3B4(r27)
	  mr        r31, r0
	  li        r4, 0
	  lwz       r12, 0x30(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r27)
	  addi      r0, r3, 0
	  lis       r4, 0x803A
	  lwz       r12, 0x74(r12)
	  addi      r3, r27, 0
	  subi      r4, r4, 0x77C0
	  mtlr      r12
	  mr        r30, r0
	  li        r5, 0
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x238(r28)
	  lwz       r29, 0x10(r3)
	  b         .loc_0x1E4

	.loc_0xE0:
	  lwz       r0, 0x20(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x1E0
	  lwz       r4, 0x1C(r29)
	  cmplwi    r4, 0
	  beq-      .loc_0x110
	  lwz       r12, 0x3B4(r27)
	  mr        r3, r27
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x15C

	.loc_0x110:
	  mr        r3, r27
	  lwz       r4, 0x24(r29)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r4, 0x18(r29)
	  lwz       r12, 0x3B4(r27)
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl

	.loc_0x15C:
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0x1
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  lwz       r28, 0x20(r29)
	  b         .loc_0x1D0

	.loc_0x17C:
	  lwz       r0, 0x1C(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x1A4
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  addi      r4, r28, 0
	  li        r5, 0x1
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1A4:
	  mr        r3, r27
	  lwz       r4, 0x2E4(r27)
	  lwz       r12, 0x3B4(r27)
	  addi      r5, r28, 0x4
	  addi      r6, r28, 0x10
	  lwz       r12, 0x94(r12)
	  addi      r7, r28, 0x18
	  addi      r8, r28, 0x20
	  mtlr      r12
	  blrl
	  lwz       r28, 0x28(r28)

	.loc_0x1D0:
	  cmplwi    r28, 0
	  bne+      .loc_0x17C
	  li        r0, 0
	  stw       r0, 0x20(r29)

	.loc_0x1E0:
	  lwz       r29, 0xC(r29)

	.loc_0x1E4:
	  cmplwi    r29, 0
	  bne+      .loc_0xE0
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  mr        r4, r31
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  addi      r4, r30, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8003FDD4
 * Size:	000560
 */
void StdSystem::loadBundle(char*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stmw      r14, 0x40(r1)
	  mr        r29, r3
	  mr        r14, r5
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr.       r28, r3
	  beq-      .loc_0x54C
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lis       r7, 0x8023
	  subi      r0, r7, 0x73A8
	  lis       r10, 0x8023
	  stw       r0, 0x34(r1)
	  subi      r0, r10, 0x7F20
	  lis       r11, 0x8023
	  stw       r0, 0x28(r1)
	  subi      r0, r11, 0x7310
	  stw       r0, 0x2C(r1)
	  lis       r0, 0x5F62
	  lis       r8, 0x8023
	  stw       r0, 0x38(r1)
	  lis       r0, 0x5F74
	  lis       r6, 0x8022
	  lis       r5, 0x8022
	  stw       r0, 0x30(r1)
	  lis       r4, 0x8023
	  lis       r9, 0x8023
	  addi      r18, r3, 0
	  subi      r25, r8, 0x795C
	  addi      r17, r6, 0x738C
	  addi      r16, r5, 0x737C
	  subi      r15, r4, 0x7EBC
	  rlwinm    r14,r14,0,24,31
	  subi      r20, r9, 0x7294
	  addi      r21, r29, 0x1D0
	  li        r22, 0
	  lis       r24, 0x6E6F
	  lis       r19, 0x5F61
	  b         .loc_0x530

	.loc_0xC4:
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  addi      r3, r28, 0
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  li        r30, 0
	  stw       r30, 0x24(r1)
	  addi      r0, r3, 0
	  addi      r3, r28, 0
	  stw       r30, 0x20(r1)
	  mr        r27, r0
	  addi      r4, r1, 0x20
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r31, 0x2
	  beq-      .loc_0x144
	  bge-      .loc_0x138
	  cmpwi     r31, 0
	  beq-      .loc_0x43C
	  bge-      .loc_0x284
	  b         .loc_0x4FC

	.loc_0x138:
	  cmpwi     r31, 0x4
	  bge-      .loc_0x4FC
	  b         .loc_0x1E4

	.loc_0x144:
	  lwz       r3, 0x1FC(r29)
	  mr        r5, r28
	  lwz       r4, 0x24(r1)
	  bl        -0xB20C
	  lwz       r26, 0x24(r1)
	  addi      r27, r3, 0
	  li        r3, 0x24
	  bl        0x70D0
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x1A4
	  stw       r25, 0x1C(r31)
	  addi      r3, r31, 0xC
	  bl        0x3F10
	  stw       r30, 0x4(r31)
	  subi      r0, r13, 0x7A08
	  addi      r3, r31, 0xC
	  stw       r30, 0x0(r31)
	  addi      r4, r24, 0x6E65
	  stw       r0, 0x8(r31)
	  bl        0x3F5C
	  stw       r30, 0x18(r31)
	  stw       r20, 0x1C(r31)
	  stw       r30, 0x20(r31)

	.loc_0x1A4:
	  mr        r3, r26
	  bl        0x3C4
	  stw       r3, 0x8(r31)
	  addi      r3, r31, 0xC
	  addi      r4, r19, 0x6E6D
	  bl        0x3F38
	  stw       r27, 0x20(r31)
	  li        r0, 0x1
	  lwz       r3, 0x1D4(r29)
	  stw       r3, 0x4(r31)
	  stw       r21, 0x0(r31)
	  lwz       r3, 0x1D4(r29)
	  stw       r31, 0x0(r3)
	  stw       r31, 0x1D4(r29)
	  stb       r0, 0x1F0(r29)
	  b         .loc_0x52C

	.loc_0x1E4:
	  lwz       r3, 0x1FC(r29)
	  mr        r5, r28
	  lwz       r4, 0x24(r1)
	  bl        -0xB574
	  lwz       r26, 0x24(r1)
	  addi      r27, r3, 0
	  li        r3, 0x24
	  bl        0x7030
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x244
	  stw       r25, 0x1C(r31)
	  addi      r3, r31, 0xC
	  bl        0x3E70
	  stw       r30, 0x4(r31)
	  subi      r0, r13, 0x7A08
	  addi      r3, r31, 0xC
	  stw       r30, 0x0(r31)
	  addi      r4, r24, 0x6E65
	  stw       r0, 0x8(r31)
	  bl        0x3EBC
	  stw       r30, 0x18(r31)
	  stw       r20, 0x1C(r31)
	  stw       r30, 0x20(r31)

	.loc_0x244:
	  mr        r3, r26
	  bl        0x324
	  stw       r3, 0x8(r31)
	  addi      r3, r31, 0xC
	  addi      r4, r19, 0x6E6D
	  bl        0x3E98
	  stw       r27, 0x20(r31)
	  li        r0, 0x1
	  lwz       r3, 0x1D4(r29)
	  stw       r3, 0x4(r31)
	  stw       r21, 0x0(r31)
	  lwz       r3, 0x1D4(r29)
	  stw       r31, 0x0(r3)
	  stw       r31, 0x1D4(r29)
	  stb       r0, 0x1F0(r29)
	  b         .loc_0x52C

	.loc_0x284:
	  li        r3, 0x34
	  bl        0x6FA8
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x2C4
	  stw       r17, 0x0(r31)
	  subi      r3, r13, 0x79F8
	  li        r0, 0x1
	  stw       r16, 0x0(r31)
	  stw       r30, 0x10(r31)
	  stw       r30, 0xC(r31)
	  stw       r30, 0x8(r31)
	  stw       r3, 0x4(r31)
	  stw       r15, 0x0(r31)
	  stw       r0, 0x24(r31)
	  stw       r30, 0x30(r31)

	.loc_0x2C4:
	  cmplwi    r14, 0
	  beq-      .loc_0x368
	  li        r3, 0x4C
	  bl        0x6F60
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x2FC
	  bl        0x40E0
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  stw       r0, 0x3C(r30)
	  stw       r0, 0x44(r30)
	  stw       r0, 0x40(r30)

	.loc_0x2FC:
	  stw       r31, 0x44(r30)
	  addi      r4, r30, 0
	  addi      r26, r30, 0
	  lwz       r5, 0x1CC(r29)
	  mr        r3, r31
	  lwz       r6, 0x384(r5)
	  addi      r5, r28, 0
	  addi      r0, r6, 0x1F
	  rlwinm    r6,r0,0,0,26
	  bl        -0x17764
	  mr        r3, r29
	  lwz       r4, 0x2C(r31)
	  lwz       r12, 0x1A0(r29)
	  li        r6, 0
	  lwz       r5, 0x28(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x48(r30)
	  mr        r3, r29
	  lwz       r12, 0x1A0(r29)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stw       r0, 0x2C(r31)
	  b         .loc_0x398

	.loc_0x368:
	  li        r3, 0x3C
	  bl        0x6EC4
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x380
	  bl        0x4044

	.loc_0x380:
	  addi      r4, r27, 0
	  addi      r26, r27, 0
	  addi      r3, r31, 0
	  addi      r5, r28, 0
	  li        r6, 0
	  bl        -0x177D8

	.loc_0x398:
	  lwz       r23, 0x24(r1)
	  li        r3, 0x24
	  lwz       r30, 0x2DEC(r13)
	  bl        0x6E8C
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x3F0
	  stw       r25, 0x1C(r31)
	  addi      r3, r31, 0xC
	  bl        0x3CCC
	  li        r27, 0
	  stw       r27, 0x4(r31)
	  subi      r0, r13, 0x7A08
	  addi      r3, r31, 0xC
	  stw       r27, 0x0(r31)
	  addi      r4, r24, 0x6E65
	  stw       r0, 0x8(r31)
	  bl        0x3D14
	  stw       r27, 0x18(r31)
	  lwz       r0, 0x2C(r1)
	  stw       r0, 0x1C(r31)
	  stw       r27, 0x20(r31)

	.loc_0x3F0:
	  mr        r3, r23
	  bl        0x178
	  lwz       r4, 0x30(r1)
	  stw       r3, 0x8(r31)
	  addi      r3, r31, 0xC
	  addi      r4, r4, 0x6578
	  bl        0x3CE8
	  stw       r26, 0x20(r31)
	  addi      r3, r30, 0x1D0
	  li        r0, 0x1
	  stw       r31, 0x38(r26)
	  lwz       r4, 0x1D4(r30)
	  stw       r4, 0x4(r31)
	  stw       r3, 0x0(r31)
	  lwz       r3, 0x1D4(r30)
	  stw       r31, 0x0(r3)
	  stw       r31, 0x1D4(r30)
	  stb       r0, 0x1F0(r30)
	  b         .loc_0x52C

	.loc_0x43C:
	  mr        r3, r27
	  bl        0x6DF0
	  lwz       r12, 0x4(r28)
	  addi      r26, r3, 0
	  addi      r3, r28, 0
	  lwz       r12, 0x3C(r12)
	  mr        r4, r26
	  addi      r5, r27, 0
	  mtlr      r12
	  blrl
	  li        r3, 0x24
	  bl        0x6DC8
	  addi      r31, r3, 0
	  mr.       r27, r31
	  beq-      .loc_0x4B0
	  stw       r25, 0x1C(r31)
	  addi      r3, r27, 0xC
	  bl        0x3C08
	  stw       r30, 0x4(r31)
	  subi      r0, r13, 0x7A08
	  addi      r3, r27, 0xC
	  stw       r30, 0x0(r31)
	  addi      r4, r24, 0x6E65
	  stw       r0, 0x8(r31)
	  bl        0x3C54
	  stw       r30, 0x18(r31)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0x1C(r31)
	  stw       r30, 0x20(r31)

	.loc_0x4B0:
	  lwz       r3, 0x24(r1)
	  bl        0xB8
	  lwz       r4, 0x38(r1)
	  stw       r3, 0x8(r31)
	  addi      r3, r31, 0xC
	  addi      r4, r4, 0x696E
	  bl        0x3C28
	  stw       r26, 0x20(r31)
	  li        r0, 0x1
	  lwz       r3, 0x2DEC(r13)
	  lwz       r5, 0x1D4(r3)
	  addi      r4, r3, 0x1D0
	  stw       r5, 0x4(r31)
	  stw       r4, 0x0(r31)
	  lwz       r4, 0x1D4(r3)
	  stw       r31, 0x0(r4)
	  stw       r31, 0x1D4(r3)
	  stb       r0, 0x1F0(r3)
	  b         .loc_0x52C

	.loc_0x4FC:
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r28, 0
	  lwz       r12, 0x4(r28)
	  add       r4, r0, r27
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl

	.loc_0x52C:
	  addi      r22, r22, 0x1

	.loc_0x530:
	  cmpw      r22, r18
	  blt+      .loc_0xC4
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x54C:
	  lmw       r14, 0x40(r1)
	  lwz       r0, 0x8C(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80040340
 * Size:	00005C
 */
char* StdSystem::stringDup(char* str)
{
	size_t len   = strlen(str) + 1;
	char* outStr = new char[len];
	memcpy(outStr, str, len);
	return outStr;
}

/*
 * --INFO--
 * Address:	8004039C
 * Size:	000048
 */
void TextureCacher::updateInfo(CacheTexture*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x8(r3)
	  lwz       r6, 0x40(r4)
	  cmplw     r0, r6
	  beqlr-
	  lwz       r0, 0x4(r6)
	  lwz       r5, 0x8(r6)
	  stw       r0, 0x4(r5)
	  lwz       r0, 0x8(r6)
	  lwz       r5, 0x4(r6)
	  stw       r0, 0x8(r5)
	  lwz       r5, 0x40(r4)
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x8(r5)
	  stw       r3, 0x4(r5)
	  lwz       r4, 0x8(r3)
	  stw       r5, 0x4(r4)
	  stw       r5, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800403E4
 * Size:	000044
 */
void TextureCacher::purgeAll()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  b         .loc_0x20

	.loc_0x18:
	  mr        r3, r31
	  bl        .loc_0x44

	.loc_0x20:
	  lwz       r3, 0x14(r31)
	  bl        -0x1B658
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x18
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x44:
	*/
}

/*
 * --INFO--
 * Address:	80040428
 * Size:	000050
 */
void TextureCacher::removeOldest()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  lwz       r7, 0x4(r3)
	  lwz       r6, 0x4(r7)
	  mr        r4, r7
	  lwz       r5, 0x8(r7)
	  stw       r6, 0x4(r5)
	  lwz       r6, 0x8(r7)
	  lwz       r5, 0x4(r7)
	  stw       r6, 0x8(r5)
	  lwz       r5, 0xC(r7)
	  stw       r0, 0x0(r5)
	  lwz       r3, 0x14(r3)
	  bl        -0x1B7C8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80040478
 * Size:	0000E0
 */
void TextureCacher::cacheTexture(CacheTexture*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x1C(r1)
	  li        r29, 0
	  stw       r28, 0x18(r1)
	  lwz       r4, 0x44(r4)
	  lwz       r3, 0x28(r4)
	  addi      r0, r3, 0x53
	  rlwinm    r28,r0,0,0,26

	.loc_0x38:
	  lwz       r3, 0x14(r30)
	  bl        -0x1B6EC
	  cmplw     r3, r28
	  ble-      .loc_0x8C
	  lwz       r3, 0x14(r30)
	  mr        r4, r28
	  bl        -0x1B94C
	  addi      r0, r3, 0x33
	  lwz       r4, 0x44(r31)
	  rlwinm    r0,r0,0,0,26
	  stw       r0, 0x2C(r4)
	  addi      r0, r31, 0x40
	  stw       r0, 0xC(r3)
	  stw       r3, 0x40(r31)
	  lwz       r0, 0x8(r30)
	  stw       r0, 0x8(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0x8(r30)
	  stw       r3, 0x4(r4)
	  stw       r3, 0x8(r30)
	  b         .loc_0xC0

	.loc_0x8C:
	  lwz       r5, 0x4(r30)
	  lwz       r0, 0x4(r5)
	  mr        r4, r5
	  lwz       r3, 0x8(r5)
	  stw       r0, 0x4(r3)
	  lwz       r0, 0x8(r5)
	  lwz       r3, 0x4(r5)
	  stw       r0, 0x8(r3)
	  lwz       r3, 0xC(r5)
	  stw       r29, 0x0(r3)
	  lwz       r3, 0x14(r30)
	  bl        -0x1B894
	  b         .loc_0x38

	.loc_0xC0:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}
