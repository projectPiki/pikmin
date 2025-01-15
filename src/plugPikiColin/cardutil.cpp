#include "types.h"
#include "CardUtil.h"
#include "Dolphin/card.h"

CardUtilThread CardThread;
CardUtilControl CardControl;

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
 * Size:	000010
 */
void CardUtilNumFiles()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void CardUtilLockDirectory()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void CardUtilUnlockDirectory()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void CardUtilByteNotUsed()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void CardUtilBlocksNotUsed()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void CardUtilFilesNotUsed()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void CardUtilSectorSize()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8004C93C
 * Size:	000104
 */
static int DoMount(s32 channel, void* a2)
{
	OSLockMutex(&CardControl.mMutex);
	CardControl.mChannel = 0;
	OSUnlockMutex(&CardControl.mMutex);

	s32 res = CARDMount(channel, (CARDMemoryCard*)a2, 0);
	switch (res) {
	case CARD_RESULT_BROKEN:
		res = CARDGetSectorSize(channel, 0);
		if (res > 0) {
			return res;
		}
		CARDCheck(channel);
		break;
	case CARD_RESULT_ENCODING:
		res = CARDGetSectorSize(channel, 0);
		if (res >= 0) {
			return res;
		}
		break;
	}

	if (res == CARD_RESULT_READY) {
		CARDFreeBlocks(channel, 0, 0);
	}
	return res;

	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r26, 0x10(r1)
	  subi      r30, r5, 0x2BC8
	  addi      r29, r30, 0x360
	  addi      r26, r3, 0
	  addi      r27, r4, 0
	  addi      r3, r29, 0
	  bl        0x1AD08C
	  li        r31, 0
	  stw       r31, 0x37C(r30)
	  mr        r3, r29
	  bl        0x1AD158
	  addi      r29, r30, 0x350
	  stw       r31, 0x350(r30)
	  addi      r28, r30, 0x34C
	  lis       r3, 0x1
	  stw       r31, 0x34C(r30)
	  subi      r0, r3, 0x6000
	  addi      r3, r26, 0
	  stw       r0, 0x35C(r30)
	  addi      r4, r27, 0
	  li        r5, 0
	  bl        0x1BE76C
	  addi      r31, r3, 0
	  cmpwi     r31, -0x6
	  beq-      .loc_0x90
	  bge-      .loc_0x84
	  cmpwi     r31, -0xD
	  beq-      .loc_0xB8
	  b         .loc_0xD0

	.loc_0x84:
	  cmpwi     r31, 0
	  beq-      .loc_0x90
	  b         .loc_0xD0

	.loc_0x90:
	  addi      r3, r26, 0
	  addi      r4, r30, 0x354
	  bl        0x1BC6EC
	  cmpwi     r3, 0
	  bge-      .loc_0xA8
	  b         .loc_0xF0

	.loc_0xA8:
	  mr        r3, r26
	  bl        0x1BE068
	  mr        r31, r3
	  b         .loc_0xD0

	.loc_0xB8:
	  addi      r3, r26, 0
	  addi      r4, r30, 0x354
	  bl        0x1BC6C4
	  cmpwi     r3, 0
	  bge-      .loc_0xD0
	  b         .loc_0xF0

	.loc_0xD0:
	  cmpwi     r31, 0
	  bne-      .loc_0xEC
	  addi      r3, r26, 0
	  addi      r4, r28, 0
	  addi      r5, r29, 0
	  bl        0x1BC580
	  mr        r31, r3

	.loc_0xEC:
	  mr        r3, r31

	.loc_0xF0:
	  lmw       r26, 0x10(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
static void DoUnmount(s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
static void DoFormat(s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8004CA40
 * Size:	0000FC
 */
static int DoErase(s32, s32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  li        r0, 0x4000
	  stwu      r1, -0x30(r1)
	  stmw      r25, 0x14(r1)
	  subi      r31, r5, 0x2BC8
	  addi      r25, r3, 0
	  mr        r26, r4
	  stw       r0, 0x35C(r31)
	  bl        0x1C01C8
	  cmpwi     r3, 0
	  bge-      .loc_0x38
	  b         .loc_0xE8

	.loc_0x38:
	  addi      r28, r31, 0x378
	  lwz       r0, 0x378(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xD8
	  mr        r27, r0
	  addi      r30, r31, 0x360
	  addi      r29, r31, 0x37C
	  b         .loc_0xC0

	.loc_0x58:
	  lwz       r0, 0x5A40(r27)
	  cmpw      r0, r26
	  bne-      .loc_0xBC
	  mr        r3, r30
	  bl        0x1ACF48
	  lwz       r0, 0x0(r29)
	  addi      r4, r27, 0x5B40
	  lwz       r5, 0x0(r28)
	  addi      r3, r27, 0
	  mulli     r0, r0, 0x5B40
	  add       r0, r5, r0
	  sub       r5, r0, r4
	  bl        0x1C9714
	  lwz       r4, 0x0(r29)
	  addi      r3, r27, 0
	  subi      r0, r4, 0x1
	  stw       r0, 0x0(r29)
	  lwz       r0, 0x0(r29)
	  lwz       r4, 0x0(r28)
	  mulli     r0, r0, 0x5B40
	  add       r0, r4, r0
	  sub       r4, r0, r27
	  bl        0x1AA12C
	  mr        r3, r30
	  bl        0x1ACFD4

	.loc_0xBC:
	  addi      r27, r27, 0x5B40

	.loc_0xC0:
	  lwz       r0, 0x0(r29)
	  lwz       r3, 0x0(r28)
	  mulli     r0, r0, 0x5B40
	  add       r0, r3, r0
	  cmplw     r27, r0
	  blt+      .loc_0x58

	.loc_0xD8:
	  addi      r3, r25, 0
	  addi      r4, r31, 0x34C
	  addi      r5, r31, 0x350
	  bl        0x1BC47C

	.loc_0xE8:
	  lmw       r25, 0x14(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004CB3C
 * Size:	0005CC
 */
static int DoList(s32, CardUtilDirent*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stmw      r20, 0x70(r1)
	  addi      r31, r3, 0
	  addi      r25, r4, 0
	  subi      r20, r5, 0x2BC8
	  bl        0x1B51A0
	  addi      r28, r20, 0x360
	  addi      r26, r3, 0
	  addi      r3, r28, 0
	  li        r21, 0
	  bl        0x1ACE80
	  stw       r25, 0x378(r20)
	  addi      r30, r20, 0x37C
	  addi      r3, r28, 0
	  stw       r21, 0x37C(r20)
	  bl        0x1ACF48
	  cmplwi    r25, 0
	  bne-      .loc_0x5C
	  li        r3, 0
	  b         .loc_0x5B8

	.loc_0x5C:
	  lis       r4, 0x2D
	  addi      r3, r25, 0
	  addi      r5, r4, 0x44C0
	  li        r4, 0
	  bl        -0x49888
	  addi      r22, r1, 0x11
	  addi      r23, r20, 0x350
	  addi      r24, r20, 0x34C
	  li        r29, 0
	  b         .loc_0x5AC

	.loc_0x84:
	  lwz       r0, 0x0(r30)
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  mulli     r0, r0, 0x5B40
	  add       r27, r25, r0
	  addi      r5, r27, 0x5A44
	  bl        0x1C0298
	  cmpwi     r3, 0
	  blt-      .loc_0x5A8
	  addi      r4, r26, 0
	  addi      r3, r27, 0x5A6C
	  li        r5, 0x4
	  bl        0x1C957C
	  cmpwi     r3, 0
	  bne-      .loc_0x5A8
	  addi      r3, r27, 0x5A70
	  addi      r4, r26, 0x4
	  li        r5, 0x2
	  bl        0x1C9564
	  cmpwi     r3, 0
	  bne-      .loc_0x5A8
	  lbz       r0, 0x5A44(r27)
	  cmplwi    r0, 0x7E
	  bne-      .loc_0x178
	  addi      r3, r1, 0x10
	  addi      r4, r27, 0x5A44
	  li        r5, 0x20
	  bl        0x1CC6E8
	  li        r20, 0
	  stb       r20, 0x30(r1)
	  addi      r4, r22, 0
	  addi      r3, r1, 0x34
	  li        r5, 0x20
	  bl        0x1CC6D0
	  stb       r20, 0x54(r1)
	  lwz       r3, 0x5A64(r27)
	  lwz       r4, 0x5A7C(r27)
	  subi      r0, r3, 0x40
	  cmplw     r4, r0
	  bgt-      .loc_0x144
	  addi      r3, r31, 0
	  addi      r4, r1, 0x10
	  addi      r5, r1, 0x34
	  bl        0x1C06D4
	  cmpwi     r3, 0
	  bne-      .loc_0x144
	  subi      r29, r29, 0x1
	  b         .loc_0x5A8

	.loc_0x144:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        0x1BFFA8
	  mr.       r21, r3
	  blt-      .loc_0x170
	  addi      r3, r31, 0
	  addi      r4, r24, 0
	  addi      r5, r23, 0
	  bl        0x1BC300
	  mr.       r21, r3
	  bge-      .loc_0x5A8

	.loc_0x170:
	  mr        r3, r21
	  b         .loc_0x5B8

	.loc_0x178:
	  addi      r3, r27, 0x5A00
	  li        r4, 0
	  li        r5, 0x40
	  bl        -0x499A0
	  lwz       r3, 0x5A64(r27)
	  lwz       r4, 0x5A7C(r27)
	  subi      r0, r3, 0x40
	  cmplw     r4, r0
	  bgt-      .loc_0x210
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r5, r1, 0x58
	  bl        0x1BEEC0
	  cmpwi     r3, 0
	  bge-      .loc_0x1B8
	  b         .loc_0x5B8

	.loc_0x1B8:
	  lwz       r5, 0x5A7C(r27)
	  addi      r4, r27, 0
	  addi      r3, r1, 0x58
	  rlwinm    r6,r5,0,0,22
	  addi      r0, r5, 0x40
	  sub       r5, r0, r6
	  addi      r0, r5, 0x1FF
	  rlwinm    r5,r0,0,0,22
	  bl        0x1BF990
	  addi      r21, r3, 0
	  addi      r3, r1, 0x58
	  bl        0x1BF16C
	  cmpwi     r21, 0
	  bge-      .loc_0x1F8
	  mr        r3, r21
	  b         .loc_0x5B8

	.loc_0x1F8:
	  lwz       r0, 0x5A7C(r27)
	  addi      r3, r27, 0x5A00
	  li        r5, 0x40
	  rlwinm    r0,r0,0,23,31
	  add       r4, r27, r0
	  bl        0x1C9494

	.loc_0x210:
	  lbz       r0, 0x5A72(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x228
	  lhz       r0, 0x5A78(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x588

	.loc_0x228:
	  lwz       r3, 0x5AAC(r27)
	  lwz       r0, 0x5A64(r27)
	  cmplw     r3, r0
	  bgt-      .loc_0x588
	  lwz       r0, 0x5A74(r27)
	  cmplw     r0, r3
	  bge-      .loc_0x588
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r5, r1, 0x58
	  bl        0x1BEE18
	  cmpwi     r3, 0
	  bge-      .loc_0x260
	  b         .loc_0x5B8

	.loc_0x260:
	  lwz       r5, 0x5A74(r27)
	  mr        r4, r27
	  lwz       r0, 0x5AAC(r27)
	  addi      r3, r1, 0x58
	  rlwinm    r6,r5,0,0,22
	  sub       r5, r0, r6
	  addi      r0, r5, 0x1FF
	  rlwinm    r5,r0,0,0,22
	  bl        0x1BF8E8
	  addi      r21, r3, 0
	  addi      r3, r1, 0x58
	  bl        0x1BF0C4
	  cmpwi     r21, 0
	  bge-      .loc_0x2A0
	  mr        r3, r21
	  b         .loc_0x5B8

	.loc_0x2A0:
	  lwz       r5, 0x5A74(r27)
	  mr        r3, r27
	  lwz       r0, 0x5AAC(r27)
	  rlwinm    r4,r5,0,23,31
	  add       r4, r27, r4
	  sub       r5, r0, r5
	  bl        0x1C93E8
	  lwz       r4, 0x5A74(r27)
	  mr        r3, r27
	  lwz       r0, 0x5AAC(r27)
	  sub       r4, r0, r4
	  bl        0x1A9DE0
	  li        r7, 0
	  li        r0, 0x2
	  stw       r7, 0x5AB0(r27)
	  mtctr     r0
	  addi      r8, r27, 0
	  addi      r9, r7, 0
	  li        r4, 0
	  li        r5, 0
	  li        r3, 0

	.loc_0x2F4:
	  lhz       r0, 0x5A7A(r27)
	  sraw      r0, r0, r7
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x448
	  lwz       r6, 0x5AB0(r27)
	  rlwinm    r0,r0,2,0,29
	  stw       r6, 0x5AB4(r8)
	  stw       r3, 0x5AEC(r8)
	  lwz       r6, 0x5AB0(r27)
	  add       r0, r6, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r0, 0x5A78(r27)
	  sraw      r0, r0, r9
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x338
	  addi      r9, r9, 0x2
	  addi      r3, r3, 0x1

	.loc_0x338:
	  lhz       r0, 0x5A7A(r27)
	  addi      r7, r7, 0x2
	  addi      r8, r8, 0x4
	  sraw      r0, r0, r7
	  rlwinm.   r0,r0,0,30,31
	  addi      r4, r4, 0x1
	  addi      r5, r5, 0x1
	  beq-      .loc_0x448
	  lwz       r6, 0x5AB0(r27)
	  rlwinm    r0,r0,2,0,29
	  stw       r6, 0x5AB4(r8)
	  stw       r3, 0x5AEC(r8)
	  lwz       r6, 0x5AB0(r27)
	  add       r0, r6, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r0, 0x5A78(r27)
	  sraw      r0, r0, r9
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x38C
	  addi      r9, r9, 0x2
	  addi      r3, r3, 0x1

	.loc_0x38C:
	  lhz       r0, 0x5A7A(r27)
	  addi      r7, r7, 0x2
	  addi      r8, r8, 0x4
	  sraw      r0, r0, r7
	  rlwinm.   r0,r0,0,30,31
	  addi      r4, r4, 0x1
	  addi      r5, r5, 0x1
	  beq-      .loc_0x448
	  lwz       r6, 0x5AB0(r27)
	  rlwinm    r0,r0,2,0,29
	  stw       r6, 0x5AB4(r8)
	  stw       r3, 0x5AEC(r8)
	  lwz       r6, 0x5AB0(r27)
	  add       r0, r6, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r0, 0x5A78(r27)
	  sraw      r0, r0, r9
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x3E0
	  addi      r9, r9, 0x2
	  addi      r3, r3, 0x1

	.loc_0x3E0:
	  lhz       r0, 0x5A7A(r27)
	  addi      r7, r7, 0x2
	  addi      r8, r8, 0x4
	  sraw      r0, r0, r7
	  rlwinm.   r0,r0,0,30,31
	  addi      r4, r4, 0x1
	  addi      r5, r5, 0x1
	  beq-      .loc_0x448
	  lwz       r6, 0x5AB0(r27)
	  rlwinm    r0,r0,2,0,29
	  stw       r6, 0x5AB4(r8)
	  stw       r3, 0x5AEC(r8)
	  lwz       r6, 0x5AB0(r27)
	  add       r0, r6, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r0, 0x5A78(r27)
	  sraw      r0, r0, r9
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x434
	  addi      r9, r9, 0x2
	  addi      r3, r3, 0x1

	.loc_0x434:
	  addi      r7, r7, 0x2
	  addi      r5, r5, 0x1
	  addi      r8, r8, 0x4
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x2F4

	.loc_0x448:
	  lbz       r0, 0x5A72(r27)
	  rlwinm    r0,r0,0,29,29
	  cmpwi     r0, 0x4
	  bne-      .loc_0x588
	  cmpwi     r5, 0x2
	  ble-      .loc_0x588
	  subic.    r3, r5, 0x2
	  rlwinm    r4,r4,2,0,29
	  add       r6, r27, r4
	  rlwinm    r0,r3,2,0,29
	  rlwinm    r5,r3,1,0,30
	  add       r7, r27, r0
	  ble-      .loc_0x588
	  rlwinm.   r0,r3,30,2,31
	  mtctr     r0
	  beq-      .loc_0x54C

	.loc_0x488:
	  lhz       r4, 0x5A7A(r27)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5AB4(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AEC(r7)
	  stw       r4, 0x5AEC(r6)
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r4, 0x5A7A(r27)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5AB8(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AE8(r7)
	  stw       r4, 0x5AF0(r6)
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r4, 0x5A7A(r27)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5ABC(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AE4(r7)
	  stw       r4, 0x5AF4(r6)
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r4, 0x5A7A(r27)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5AC0(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AE0(r7)
	  subi      r7, r7, 0x10
	  stw       r4, 0x5AF8(r6)
	  addi      r6, r6, 0x10
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  bdnz+     .loc_0x488
	  andi.     r3, r3, 0x3
	  beq-      .loc_0x588

	.loc_0x54C:
	  mtctr     r3

	.loc_0x550:
	  lhz       r4, 0x5A7A(r27)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5AB4(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AEC(r7)
	  subi      r7, r7, 0x4
	  stw       r4, 0x5AEC(r6)
	  addi      r6, r6, 0x4
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  bdnz+     .loc_0x550

	.loc_0x588:
	  stw       r29, 0x5A40(r27)
	  mr        r3, r28
	  bl        0x1AC924
	  lwz       r4, 0x0(r30)
	  addi      r3, r28, 0
	  addi      r0, r4, 0x1
	  stw       r0, 0x0(r30)
	  bl        0x1AC9EC

	.loc_0x5A8:
	  addi      r29, r29, 0x1

	.loc_0x5AC:
	  cmpwi     r29, 0x7F
	  blt+      .loc_0x84
	  mr        r3, r21

	.loc_0x5B8:
	  lmw       r20, 0x70(r1)
	  lwz       r0, 0xA4(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
static void DoOpen(s32, s32, void*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
static void DoWrite(s32, s32, void*, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8004D108
 * Size:	0005AC
 */
static int DoSave(s32, CARDStat*, void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stmw      r24, 0x70(r1)
	  addi      r24, r3, 0
	  addi      r26, r5, 0
	  addi      r25, r4, 0
	  subi      r31, r6, 0x2BC8
	  addi      r3, r1, 0x38
	  li        r5, 0x20
	  bl        0x1CC1E0
	  li        r27, 0
	  stb       r27, 0x58(r1)
	  addi      r3, r1, 0x38
	  bl        0x1CC2C8
	  cmplwi    r3, 0x20
	  blt-      .loc_0x50
	  li        r3, -0xC
	  b         .loc_0x598

	.loc_0x50:
	  lbz       r0, 0x38(r1)
	  cmplwi    r0, 0x7E
	  bne-      .loc_0x64
	  li        r3, -0x80
	  b         .loc_0x598

	.loc_0x64:
	  li        r0, 0x7E
	  stb       r0, 0x14(r1)
	  addi      r4, r25, 0
	  addi      r3, r1, 0x15
	  li        r5, 0x1F
	  bl        0x1CC194
	  stb       r27, 0x34(r1)
	  addi      r3, r24, 0
	  addi      r4, r1, 0x38
	  addi      r5, r1, 0x5C
	  li        r28, -0x1
	  bl        0x1BEB80
	  cmpwi     r3, 0
	  bne-      .loc_0xA8
	  lwz       r28, 0x60(r1)
	  addi      r3, r1, 0x5C
	  bl        0x1BECE0

	.loc_0xA8:
	  lwz       r3, 0x20(r25)
	  cmpwi     r28, 0
	  addi      r4, r31, 0x35C
	  addis     r3, r3, 0x1
	  subi      r0, r3, 0x8000
	  stw       r0, 0x35C(r31)
	  blt-      .loc_0xD8
	  cmpwi     r28, 0x7F
	  bge-      .loc_0xD8
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x4000
	  stw       r0, 0x0(r4)

	.loc_0xD8:
	  lwz       r5, 0x20(r25)
	  addi      r3, r24, 0
	  addi      r4, r1, 0x14
	  addi      r6, r1, 0x5C
	  bl        0x1BF040
	  cmpwi     r3, 0
	  bge-      .loc_0xF8
	  b         .loc_0x598

	.loc_0xF8:
	  lwz       r29, 0x60(r1)
	  mr        r4, r26
	  lwz       r5, 0x20(r25)
	  addi      r3, r1, 0x5C
	  li        r6, 0
	  bl        0x1BF808
	  addi      r27, r3, 0
	  addi      r3, r1, 0x5C
	  bl        0x1BEC6C
	  cmpwi     r27, 0
	  blt-      .loc_0x13C
	  addi      r3, r24, 0
	  addi      r4, r29, 0
	  addi      r5, r25, 0
	  bl        0x1BFED0
	  mr.       r27, r3
	  bge-      .loc_0x144

	.loc_0x13C:
	  mr        r3, r27
	  b         .loc_0x598

	.loc_0x144:
	  cmpwi     r28, 0
	  blt-      .loc_0x16C
	  cmpwi     r28, 0x7F
	  bge-      .loc_0x16C
	  addi      r3, r24, 0
	  addi      r4, r28, 0
	  bl        0x1BF9CC
	  cmpwi     r3, 0
	  bge-      .loc_0x16C
	  b         .loc_0x598

	.loc_0x16C:
	  addi      r3, r24, 0
	  addi      r4, r1, 0x14
	  addi      r5, r1, 0x38
	  bl        0x1C00C0
	  cmpwi     r3, 0
	  bge-      .loc_0x188
	  b         .loc_0x598

	.loc_0x188:
	  addi      r27, r31, 0x378
	  lwz       r0, 0x378(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x1AC
	  addi      r3, r24, 0
	  addi      r4, r31, 0x34C
	  addi      r5, r31, 0x350
	  bl        0x1BBCF4
	  b         .loc_0x598

	.loc_0x1AC:
	  addi      r30, r31, 0x360
	  addi      r3, r30, 0
	  bl        0x1AC734
	  cmpwi     r28, -0x1
	  bne-      .loc_0x1DC
	  lwz       r4, 0x37C(r31)
	  lwz       r5, 0x0(r27)
	  mulli     r3, r4, 0x5B40
	  addi      r0, r4, 0x1
	  stw       r0, 0x37C(r31)
	  add       r27, r5, r3
	  b         .loc_0x238

	.loc_0x1DC:
	  addi      r5, r31, 0x37C
	  lwz       r4, 0x0(r27)
	  lwz       r3, 0x37C(r31)
	  li        r0, 0x5B40
	  addi      r27, r4, 0
	  mulli     r3, r3, 0x5B40
	  add       r4, r4, r3
	  addi      r3, r4, 0x5B3F
	  sub       r3, r3, r27
	  divwu     r3, r3, r0
	  cmplw     r27, r4
	  mtctr     r3
	  bge-      .loc_0x224

	.loc_0x210:
	  lwz       r0, 0x5A40(r27)
	  cmpw      r0, r28
	  beq-      .loc_0x224
	  addi      r27, r27, 0x5B40
	  bdnz+     .loc_0x210

	.loc_0x224:
	  cmplw     r27, r4
	  bne-      .loc_0x238
	  lwz       r3, 0x0(r5)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r5)

	.loc_0x238:
	  addi      r3, r27, 0x5A00
	  li        r4, 0
	  li        r5, 0x40
	  bl        -0x4A02C
	  lwz       r3, 0x20(r25)
	  lwz       r4, 0x38(r25)
	  subi      r0, r3, 0x40
	  cmplw     r4, r0
	  bgt-      .loc_0x26C
	  addi      r3, r27, 0x5A00
	  add       r4, r26, r4
	  li        r5, 0x40
	  bl        0x1C8E6C

	.loc_0x26C:
	  li        r0, 0
	  stw       r0, 0x5AB0(r27)
	  lbz       r0, 0x2E(r25)
	  cmplwi    r0, 0
	  bne-      .loc_0x28C
	  lhz       r0, 0x34(r25)
	  cmplwi    r0, 0
	  beq-      .loc_0x56C

	.loc_0x28C:
	  lwz       r5, 0x30(r25)
	  mr        r3, r27
	  lwz       r0, 0x68(r25)
	  add       r4, r26, r5
	  sub       r5, r0, r5
	  bl        0x1C8E34
	  lwz       r4, 0x30(r25)
	  mr        r3, r27
	  lwz       r0, 0x68(r25)
	  sub       r4, r0, r4
	  bl        0x1A982C
	  li        r0, 0x2
	  li        r4, 0
	  mtctr     r0
	  addi      r5, r27, 0
	  addi      r6, r4, 0
	  li        r8, 0
	  li        r9, 0
	  li        r7, 0

	.loc_0x2D8:
	  lhz       r0, 0x36(r25)
	  sraw      r0, r0, r4
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x42C
	  lwz       r3, 0x5AB0(r27)
	  rlwinm    r0,r0,2,0,29
	  stw       r3, 0x5AB4(r5)
	  stw       r7, 0x5AEC(r5)
	  lwz       r3, 0x5AB0(r27)
	  add       r0, r3, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r0, 0x34(r25)
	  sraw      r0, r0, r6
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x31C
	  addi      r6, r6, 0x2
	  addi      r7, r7, 0x1

	.loc_0x31C:
	  lhz       r0, 0x36(r25)
	  addi      r4, r4, 0x2
	  addi      r5, r5, 0x4
	  sraw      r0, r0, r4
	  rlwinm.   r0,r0,0,30,31
	  addi      r8, r8, 0x1
	  addi      r9, r9, 0x1
	  beq-      .loc_0x42C
	  lwz       r3, 0x5AB0(r27)
	  rlwinm    r0,r0,2,0,29
	  stw       r3, 0x5AB4(r5)
	  stw       r7, 0x5AEC(r5)
	  lwz       r3, 0x5AB0(r27)
	  add       r0, r3, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r0, 0x34(r25)
	  sraw      r0, r0, r6
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x370
	  addi      r6, r6, 0x2
	  addi      r7, r7, 0x1

	.loc_0x370:
	  lhz       r0, 0x36(r25)
	  addi      r4, r4, 0x2
	  addi      r5, r5, 0x4
	  sraw      r0, r0, r4
	  rlwinm.   r0,r0,0,30,31
	  addi      r8, r8, 0x1
	  addi      r9, r9, 0x1
	  beq-      .loc_0x42C
	  lwz       r3, 0x5AB0(r27)
	  rlwinm    r0,r0,2,0,29
	  stw       r3, 0x5AB4(r5)
	  stw       r7, 0x5AEC(r5)
	  lwz       r3, 0x5AB0(r27)
	  add       r0, r3, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r0, 0x34(r25)
	  sraw      r0, r0, r6
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x3C4
	  addi      r6, r6, 0x2
	  addi      r7, r7, 0x1

	.loc_0x3C4:
	  lhz       r0, 0x36(r25)
	  addi      r4, r4, 0x2
	  addi      r5, r5, 0x4
	  sraw      r0, r0, r4
	  rlwinm.   r0,r0,0,30,31
	  addi      r8, r8, 0x1
	  addi      r9, r9, 0x1
	  beq-      .loc_0x42C
	  lwz       r3, 0x5AB0(r27)
	  rlwinm    r0,r0,2,0,29
	  stw       r3, 0x5AB4(r5)
	  stw       r7, 0x5AEC(r5)
	  lwz       r3, 0x5AB0(r27)
	  add       r0, r3, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r0, 0x34(r25)
	  sraw      r0, r0, r6
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x418
	  addi      r6, r6, 0x2
	  addi      r7, r7, 0x1

	.loc_0x418:
	  addi      r4, r4, 0x2
	  addi      r9, r9, 0x1
	  addi      r5, r5, 0x4
	  addi      r8, r8, 0x1
	  bdnz+     .loc_0x2D8

	.loc_0x42C:
	  lbz       r0, 0x2E(r25)
	  rlwinm    r0,r0,0,29,29
	  cmpwi     r0, 0x4
	  bne-      .loc_0x56C
	  cmpwi     r9, 0x2
	  ble-      .loc_0x56C
	  subic.    r3, r9, 0x2
	  rlwinm    r4,r8,2,0,29
	  add       r6, r27, r4
	  rlwinm    r0,r3,2,0,29
	  rlwinm    r5,r3,1,0,30
	  add       r7, r27, r0
	  ble-      .loc_0x56C
	  rlwinm.   r0,r3,30,2,31
	  mtctr     r0
	  beq-      .loc_0x530

	.loc_0x46C:
	  lhz       r4, 0x36(r25)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5AB4(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AEC(r7)
	  stw       r4, 0x5AEC(r6)
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r4, 0x36(r25)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5AB8(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AE8(r7)
	  stw       r4, 0x5AF0(r6)
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r4, 0x36(r25)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5ABC(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AE4(r7)
	  stw       r4, 0x5AF4(r6)
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r4, 0x36(r25)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5AC0(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AE0(r7)
	  subi      r7, r7, 0x10
	  stw       r4, 0x5AF8(r6)
	  addi      r6, r6, 0x10
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  bdnz+     .loc_0x46C
	  andi.     r3, r3, 0x3
	  beq-      .loc_0x56C

	.loc_0x530:
	  mtctr     r3

	.loc_0x534:
	  lhz       r4, 0x36(r25)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5AB4(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AEC(r7)
	  subi      r7, r7, 0x4
	  stw       r4, 0x5AEC(r6)
	  addi      r6, r6, 0x4
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  bdnz+     .loc_0x534

	.loc_0x56C:
	  addi      r4, r25, 0
	  addi      r3, r27, 0x5A44
	  li        r5, 0x6C
	  bl        -0x4A26C
	  stw       r29, 0x5A40(r27)
	  mr        r3, r30
	  bl        0x1AC440
	  addi      r3, r24, 0
	  addi      r4, r31, 0x34C
	  addi      r5, r31, 0x350
	  bl        0x1BB904

	.loc_0x598:
	  lmw       r24, 0x70(r1)
	  lwz       r0, 0x94(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004D6B4
 * Size:	0000B0
 */
static int CardUtilCommand(s32 chan, s32 command, s32 file, void* a3, u32 a4, u32 a5)
{
	OSLockMutex(&CardControl.mMutex);
	int res;
	if (CardControl.mChannel != -1) {
		res = CardControl.test2[2];
	} else {

		CardControl.mChannel = CardControl.mChannel;
		CardControl.mChannel = chan;
		CardControl.mCommand = command;
		CardControl.test[0]  = file;
		CardControl.test[1]  = (int)a3;
		CardControl.test[2]  = a4;
		CardControl.test[3]  = a5;
		CardControl.test[4]  = -1;

		if (command != 4) {
			CardControl.test2[6] = CARDGetXferredBytes(chan);
		}
		res = 0;
		OSSignalCond(&CardControl.mCondition);
	}
	OSUnlockMutex(&CardControl.mMutex);
	return res;
}

/*
 * --INFO--
 * Address:	8004D764
 * Size:	000010
 */
int CardUtilResultCode()
{
	return CardControl.test2[2];
}

/*
 * --INFO--
 * Address:	8004D774
 * Size:	000034
 */
void CardUtilMount(s32 channel, void* a1)
{
	CardUtilCommand(channel, 1, 0, a1, 0, 0);
}

/*
 * --INFO--
 * Address:	8004D7A8
 * Size:	000034
 */
void CardUtilUnmount(s32 channel)
{
	CardUtilCommand(channel, 2, 0, 0, 0, 0);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void CardUtilList(s32, CardUtilDirent*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void CardUtilFormat(s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8004D7DC
 * Size:	00001C
 */
bool CardUtilIsCardBusy()
{
	return CardControl.mChannel == -1;
	/*
	.loc_0x0:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x28B8
	  lwz       r0, 0x20(r3)
	  subfic    r3, r0, -0x1
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8004D7F8
 * Size:	000040
 */
void CardUtilIdleWhileBusy()
{
	while (CardControl.mChannel != -1) {
		OSYieldThread();
	}
}

/*
 * --INFO--
 * Address:	8004D838
 * Size:	000034
 */
void CardUtilErase(s32 channel, s32 file)
{
	CardUtilCommand(channel, 5, file, 0, 0, 0);
}

/*
 * --INFO--
 * Address:	8004D86C
 * Size:	000034
 */
void CardUtilOpen(s32 channel, s32 file, void* a1)
{
	CardUtilCommand(channel, 6, file, a1, 0, 0);
}

/*
 * --INFO--
 * Address:	8004D8A0
 * Size:	000034
 */
void CardUtilSave(s32 channel, CARDStat* stat, void* a1)
{
	CardUtilCommand(channel, 7, (int)stat, a1, 0, 0);
}

/*
 * --INFO--
 * Address:	8004D8D4
 * Size:	00003C
 */
void CardUtilWrite(s32 channel, s32 a2, void* a3, u32 a4, u32 a5)
{
	CardUtilCommand(channel, 9, a2, a3, a4, a5);
}

/*
 * --INFO--
 * Address:	8004D910
 * Size:	00025C
 */
static void* CardUtilMain(void* a1)
{
	int res;
	while (true) {
		OSLockMutex(&CardControl.mMutex);
		while (CardControl.mChannel == -1) {
			OSWaitCond(&CardControl.mCondition, &CardControl.mMutex);
		}
		OSUnlockMutex(&CardControl.mMutex);

		switch (CardControl.test[10]) {
		case 1:
			res = DoMount(CardControl.mChannel, (void*)CardControl.test[9]);
			break;
		case 2:
			OSLockMutex(&CardControl.mMutex2);
			CardControl.test[8] = 0;
			OSUnlockMutex(&CardControl.mMutex2);
			res = CARDUnmount(CardControl.mChannel);
			break;
		case 3:
			OSLockMutex(&CardControl.mMutex2);
			CardControl.mChannel = 0;
			OSUnlockMutex(&CardControl.mMutex2);
			CardControl.test[9] = 0xa000;
			res                 = CARDFormat(CardControl.mChannel);
			if (res == 0) {
				res = CARDFreeBlocks(CardControl.mChannel, (s32*)CardControl.test[9], (s32*)CardControl.test[10]);
			}
			break;
		case 4:
			res = DoList(CardControl.mChannel, (CardUtilDirent*)CardControl.test[8]);
			break;
		case 5:
			res = DoErase(CardControl.mChannel, CardControl.mFileId);
			break;
		case 6:
			CARDStat stat;
			res = CARDGetStatus(CardControl.mChannel, CardControl.mFileId, &stat);
			if (res > 0) {
				res = CARDFastOpen(CardControl.mChannel, CardControl.mFileId, (CARDFileInfo*)&stat);
				if (res > 0) {
					CardControl.test[1] = stat.iconAddr;
					res                 = CARDRead((CARDFileInfo*)&stat, (void*)CardControl.test[7], stat.iconAddr, 0);
				}
			}
			break;
		case 7:
			res = DoSave(CardControl.mChannel, (CARDStat*)CardControl.mFileId, (void*)CardControl.test[5]);
			break;
		case 9:
			CARDStat stat2;
			res = CARDGetStatus(CardControl.mChannel, CardControl.mFileId, &stat2);
			if (res > 0) {
				res = CARDFastOpen(CardControl.mChannel, CardControl.mFileId, (CARDFileInfo*)&stat2);
				if (res > 0) {
					CardControl.test[5] = stat2.iconAddr;
					res                 = CARDWrite((CARDFileInfo*)&stat, (void*)CardControl.test[3], stat2.iconAddr, 0);
					CARDClose((CARDFileInfo*)&stat2);
				}
			}
			break;
		}
		OSLockMutex(&CardControl.mMutex);
		if (res == -5) {
			CardControl.mFileId = 1;
		}
		CardControl.mChannel = -1;
		CardControl.test[7]  = res;
		OSUnlockMutex(&CardControl.mMutex);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  lis       r4, 0x1
	  lis       r5, 0x802A
	  stwu      r1, -0x158(r1)
	  stmw      r16, 0x118(r1)
	  subi      r31, r3, 0x2BC8
	  lis       r3, 0x803A
	  addi      r29, r31, 0x328
	  addi      r28, r31, 0x360
	  addi      r26, r31, 0x350
	  addi      r27, r31, 0x34C
	  addi      r30, r31, 0x330
	  subi      r24, r4, 0x6000
	  addi      r25, r5, 0x5EB0
	  subi      r18, r3, 0x2848

	.loc_0x44:
	  addi      r3, r31, 0x310
	  bl        0x1AC098
	  b         .loc_0x5C

	.loc_0x50:
	  addi      r3, r29, 0
	  addi      r4, r31, 0x310
	  bl        0x1AC2BC

	.loc_0x5C:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, -0x1
	  beq+      .loc_0x50
	  lwz       r16, 0x334(r31)
	  mr        r23, r0
	  lwz       r19, 0x338(r31)
	  addi      r3, r31, 0x310
	  lwz       r22, 0x33C(r31)
	  lwz       r21, 0x340(r31)
	  lwz       r17, 0x344(r31)
	  bl        0x1AC138
	  cmplwi    r16, 0x9
	  bgt-      .loc_0x22C
	  rlwinm    r0,r16,2,0,29
	  lwzx      r0, r25, r0
	  mtctr     r0
	  bctr
	  addi      r3, r23, 0
	  addi      r4, r22, 0
	  bl        -0x107C
	  mr        r20, r3
	  b         .loc_0x22C
	  mr        r3, r28
	  bl        0x1AC028
	  li        r0, 0
	  stw       r0, 0x37C(r31)
	  mr        r3, r28
	  bl        0x1AC0F4
	  mr        r3, r23
	  bl        0x1BD810
	  mr        r20, r3
	  b         .loc_0x22C
	  mr        r3, r28
	  bl        0x1AC000
	  li        r0, 0
	  stw       r0, 0x37C(r31)
	  mr        r3, r28
	  bl        0x1AC0CC
	  stw       r24, 0x35C(r31)
	  mr        r3, r23
	  bl        0x1BE02C
	  cmpwi     r3, 0
	  bne-      .loc_0x118
	  addi      r3, r23, 0
	  addi      r4, r27, 0
	  addi      r5, r26, 0
	  bl        0x1BB57C

	.loc_0x118:
	  mr        r20, r3
	  b         .loc_0x22C
	  addi      r3, r23, 0
	  addi      r4, r22, 0
	  bl        -0xEFC
	  mr        r20, r3
	  b         .loc_0x22C
	  addi      r3, r23, 0
	  addi      r4, r19, 0
	  bl        -0x100C
	  mr        r20, r3
	  b         .loc_0x22C
	  addi      r3, r23, 0
	  addi      r4, r19, 0
	  addi      r5, r1, 0x94
	  bl        0x1BF40C
	  cmpwi     r3, 0
	  bge-      .loc_0x164
	  b         .loc_0x1A8

	.loc_0x164:
	  addi      r3, r23, 0
	  addi      r4, r19, 0
	  addi      r5, r1, 0x100
	  bl        0x1BE124
	  cmpwi     r3, 0
	  bge-      .loc_0x180
	  b         .loc_0x1A8

	.loc_0x180:
	  lwz       r5, 0xB4(r1)
	  addi      r4, r22, 0
	  addi      r3, r1, 0x100
	  stw       r5, 0x35C(r31)
	  li        r6, 0
	  bl        0x1BEC00
	  addi      r17, r3, 0
	  addi      r3, r1, 0x100
	  bl        0x1BE3DC
	  mr        r3, r17

	.loc_0x1A8:
	  mr        r20, r3
	  b         .loc_0x22C
	  addi      r3, r23, 0
	  addi      r4, r19, 0
	  addi      r5, r22, 0
	  bl        -0x9C4
	  mr        r20, r3
	  b         .loc_0x22C
	  addi      r20, r17, 0
	  addi      r3, r23, 0
	  addi      r4, r19, 0
	  addi      r5, r1, 0x14
	  bl        0x1BF388
	  cmpwi     r3, 0
	  bge-      .loc_0x1E8
	  b         .loc_0x228

	.loc_0x1E8:
	  addi      r3, r23, 0
	  addi      r4, r19, 0
	  addi      r5, r1, 0x80
	  bl        0x1BE0A0
	  cmpwi     r3, 0
	  bge-      .loc_0x204
	  b         .loc_0x228

	.loc_0x204:
	  addi      r4, r22, 0
	  addi      r5, r20, 0
	  addi      r6, r21, 0
	  addi      r3, r1, 0x80
	  bl        0x1BEEF8
	  addi      r17, r3, 0
	  addi      r3, r1, 0x80
	  bl        0x1BE35C
	  mr        r3, r17

	.loc_0x228:
	  mr        r20, r3

	.loc_0x22C:
	  addi      r3, r31, 0x310
	  bl        0x1ABEB0
	  cmpwi     r20, -0x5
	  bne-      .loc_0x244
	  li        r0, 0x1
	  stb       r0, 0x8C(r18)

	.loc_0x244:
	  stw       r20, 0x348(r31)
	  li        r0, -0x1
	  addi      r3, r31, 0x310
	  stw       r0, 0x0(r30)
	  bl        0x1ABF68
	  b         .loc_0x44
	*/
}

/*
 * --INFO--
 * Address:	8004DB6C
 * Size:	000094
 */
void CardUtilInit(void* a1, u32 a2, s32 a3)
{
	OSInitMutex(&CardControl.mMutex);
	OSInitMutex(&CardControl.mMutex2);
	OSInitCond(&CardControl.mCondition);
	OSCreateThread(&CardThread.mThread, CardUtilMain, 0, a1, a2, a3, 1);
	OSResumeThread(&CardThread.mThread);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000238
 */
void CardUtilDrawIcon(int, int, int, void*, void*, u16, u16, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000168
 */
void CardUtilDrawAnimatedIcon(CardUtilDirent*, int, int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void CardUtilGetProgress(s32)
{
	// UNUSED FUNCTION
}
