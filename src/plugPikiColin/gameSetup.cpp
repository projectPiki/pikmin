#include "GameSetupSection.h"
#include "gameflow.h"
#include "system.h"
#include "stl/mem.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80054B34
 * Size:	000190
 */
void GameSetupSection::preCacheShapes()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802A
	  stw       r0, 0x4(r1)
	  subi      r0, r13, 0x73C8
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0x69A8
	  li        r3, 0
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  addi      r29, r31, 0x9D4
	  lwz       r6, 0x2DEC(r13)
	  addi      r5, r6, 0x31C
	  lwz       r4, 0x320(r6)
	  lwz       r7, 0x320(r6)
	  addi      r8, r6, 0x310
	  lwz       r6, 0x31C(r6)
	  lwz       r5, 0x8(r5)
	  add       r5, r6, r5
	  stw       r4, 0x0(r8)
	  sub       r4, r5, r7
	  stw       r4, 0x8(r8)
	  lwz       r4, 0x0(r8)
	  stw       r4, 0x4(r8)
	  lwz       r5, 0x2DEC(r13)
	  addi      r4, r5, 0x310
	  stw       r4, 0x328(r5)
	  lwz       r4, 0x2DEC(r13)
	  addi      r4, r4, 0x214
	  stw       r3, 0x10(r4)
	  stw       r3, 0xC(r4)
	  stw       r3, 0x8(r4)
	  stw       r0, 0x4(r4)
	  lwz       r3, 0x2DEC(r13)
	  addi      r0, r3, 0x214
	  stw       r0, 0x228(r3)
	  b         .loc_0xB0

	.loc_0x94:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r5, 0x4(r29)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r29, 0x8

	.loc_0xB0:
	  lwz       r4, 0x0(r29)
	  cmplwi    r4, 0
	  bne+      .loc_0x94
	  lwz       r4, 0x2DEC(r13)
	  lis       r3, 0x803A
	  lwzu      r5, 0x1C(r4)
	  li        r0, 0x1
	  subi      r30, r3, 0x2848
	  stw       r0, 0x0(r4)
	  addi      r29, r31, 0x174
	  lwz       r3, 0x2DEC(r13)
	  stw       r5, 0x1C(r3)
	  b         .loc_0x118

	.loc_0xE4:
	  addi      r3, r30, 0
	  li        r5, 0x1
	  bl        -0x1F10
	  lwz       r0, 0x4(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x114
	  lwz       r4, 0x2DEC(r13)
	  li        r5, 0
	  stw       r3, 0x1FC(r4)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x4(r29)
	  bl        -0x14E70

	.loc_0x114:
	  addi      r29, r29, 0x8

	.loc_0x118:
	  lwz       r4, 0x0(r29)
	  cmplwi    r4, 0
	  bne+      .loc_0xE4
	  lis       r3, 0x803A
	  addi      r30, r31, 0x5CC
	  subi      r31, r3, 0x2848
	  b         .loc_0x168

	.loc_0x134:
	  addi      r3, r31, 0
	  li        r5, 0x1
	  bl        -0x1F60
	  lwz       r0, 0x4(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x164
	  lwz       r4, 0x2DEC(r13)
	  li        r5, 0
	  stw       r3, 0x1FC(r4)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x4(r30)
	  bl        -0x14EC0

	.loc_0x164:
	  addi      r30, r30, 0x8

	.loc_0x168:
	  lwz       r4, 0x0(r30)
	  cmplwi    r4, 0
	  bne+      .loc_0x134
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80054CC4
 * Size:	000284
 */
GameSetupSection::GameSetupSection()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stmw      r19, 0x24(r1)
	  addi      r21, r4, 0x69A8
	  addi      r31, r3, 0
	  subi      r4, r13, 0x73C4
	  bl        -0x1FD2C
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0
	  subi      r4, r13, 0x73C4
	  bl        -0x145C0
	  lis       r3, 0x802A
	  addi      r0, r3, 0x642C
	  lis       r3, 0x802A
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x74CC
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0
	  addi      r4, r21, 0xA64
	  bl        -0x145E4
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        -0x15D0C
	  mr        r30, r3
	  lwz       r22, 0x0(r3)
	  li        r0, 0x1
	  li        r3, 0xA0
	  stw       r0, 0x0(r30)
	  bl        -0xDD40
	  addi      r19, r3, 0
	  mr.       r3, r19
	  beq-      .loc_0x94
	  bl        0x3193C

	.loc_0x94:
	  stw       r19, 0x2FE8(r13)
	  subi      r4, r13, 0x73BC
	  lwz       r3, 0x2FE8(r13)
	  bl        0x319D4
	  lis       r3, 0x803A
	  subi      r5, r3, 0x2848
	  li        r6, 0x1
	  stb       r6, 0x1C4(r5)
	  li        r0, -0x1
	  lis       r3, 0x803A
	  stw       r0, 0x1C0(r5)
	  subi      r20, r3, 0x24E0
	  li        r19, 0
	  stw       r0, 0x1BC(r5)
	  addi      r23, r5, 0x1C4
	  addi      r24, r5, 0x1C0
	  stw       r0, 0x1B8(r5)
	  addi      r25, r5, 0x1BC
	  addi      r29, r5, 0x1B8
	  stb       r6, 0x1C5(r5)
	  addi      r28, r5, 0x1C5
	  addi      r27, r5, 0x1C6
	  stb       r19, 0x1C6(r5)
	  addi      r26, r5, 0x1C8
	  addi      r3, r20, 0
	  stw       r6, 0x1C8(r5)
	  addi      r4, r21, 0xA78
	  stw       r6, 0x2FC(r5)
	  stw       r19, 0x248(r20)
	  stw       r19, 0x254(r20)
	  stw       r19, 0x258(r20)
	  stw       r19, 0x24C(r20)
	  stw       r19, 0x250(r20)
	  bl        -0x1B14
	  stw       r19, 0x244(r20)
	  mr        r3, r31
	  bl        -0x2B4
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r21, 0xA8C
	  bl        0x31944
	  li        r3, 0x84
	  bl        -0xDDF8
	  addi      r19, r3, 0
	  mr.       r3, r19
	  beq-      .loc_0x14C
	  bl        0x89F5C

	.loc_0x14C:
	  stw       r19, 0x3098(r13)
	  lwz       r3, 0x3098(r13)
	  bl        0x8A098
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r21, 0xA8C
	  bl        0x31A24
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r21, 0xA98
	  bl        0x31908
	  li        r3, 0x1CC
	  bl        -0xDE34
	  addi      r19, r3, 0
	  mr.       r3, r19
	  beq-      .loc_0x188
	  bl        0x2A930

	.loc_0x188:
	  stw       r19, 0x2F6C(r13)
	  lwz       r3, 0x2F6C(r13)
	  bl        0x2A758
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r21, 0xA98
	  bl        0x319E8
	  li        r3, 0x14
	  bl        -0xDE64
	  addi      r19, r3, 0
	  mr.       r3, r19
	  beq-      .loc_0x1B8
	  bl        0x2F4FC

	.loc_0x1B8:
	  stw       r19, 0x2F88(r13)
	  lwz       r3, 0x2F88(r13)
	  bl        0x2F54C
	  li        r3, 0xBB8
	  bl        0xC0FD4
	  addi      r20, r3, 0
	  li        r4, 0x20
	  bl        -0xDD30
	  addi      r21, r3, 0
	  li        r3, 0x14
	  bl        -0xDEA0
	  cmplwi    r3, 0
	  beq-      .loc_0x220
	  lis       r4, 0x8022
	  addi      r0, r4, 0x7398
	  lis       r4, 0x8022
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x74C8
	  lis       r4, 0x802A
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x755C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  stw       r21, 0x8(r3)
	  stw       r0, 0xC(r3)
	  stw       r20, 0x10(r3)

	.loc_0x220:
	  stw       r3, 0x3118(r13)
	  bl        0x2A3EC
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x73BC
	  bl        0x31954
	  lis       r3, 0x803D
	  stw       r22, 0x0(r30)
	  addi      r3, r3, 0x1DF0
	  bl        0x70964
	  li        r5, 0x1
	  stb       r5, 0x0(r23)
	  li        r4, -0x1
	  li        r0, 0
	  stw       r4, 0x0(r24)
	  mr        r3, r31
	  stw       r4, 0x0(r25)
	  stw       r4, 0x0(r29)
	  stb       r5, 0x0(r28)
	  stb       r0, 0x0(r27)
	  stw       r5, 0x0(r26)
	  lwz       r0, 0x5C(r1)
	  lmw       r19, 0x24(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80054F48
 * Size:	00001C
 */
void GameSetupSection::update()
{
	gameflow._1F4  = 1;
	gsys->mPending = true;
}

/*
 * --INFO--
 * Address:	80054F64
 * Size:	000004
 */
void GameSetupSection::init() { }

/*
 * --INFO--
 * Address:	80054F68
 * Size:	000010
 */
int RamStream::getPending() { return mLength - mPosition; }

/*
 * --INFO--
 * Address:	80054F78
 * Size:	000008
 */
void RamStream::setPosition(int pos) { mPosition = pos; }

/*
 * --INFO--
 * Address:	80054F80
 * Size:	000008
 */
int RamStream::getPosition() { return mPosition; }

/*
 * --INFO--
 * Address:	80054F88
 * Size:	000008
 */
int RamStream::getLength() { return mLength; }

/*
 * --INFO--
 * Address:	80054F90
 * Size:	000008
 */
void RamStream::setLength(int len) { mLength = len; }

/*
 * --INFO--
 * Address:	80054F98
 * Size:	000054
 */
void RamStream::read(void* dest, int size)
{
	memcpy(dest, (const void*)((int)mBufferAddr + mPosition), size);
	mPosition += size;
}

/*
 * --INFO--
 * Address:	80054FEC
 * Size:	000050
 */
void RamStream::write(void* src, int size)
{
	memcpy((void*)((int)mBufferAddr + mPosition), src, size);
	mPosition += size;
}
