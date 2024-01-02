#include "Action.h"

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
 * Address:	800A82E8
 * Size:	0000C8
 */
ActAttack::ActAttack(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  stw       r3, 0x8(r1)
	  lwz       r30, 0x8(r1)
	  addi      r3, r30, 0
	  bl        0x1BAC0
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7ED0
	  stw       r0, 0x0(r30)
	  li        r5, 0
	  lis       r3, 0x802B
	  stw       r5, 0x14(r30)
	  subi      r0, r3, 0x246C
	  lis       r3, 0x802B
	  stw       r0, 0x18(r30)
	  addi      r3, r3, 0x54E8
	  addi      r4, r3, 0x64
	  stw       r3, 0x0(r30)
	  subi      r0, r13, 0x5008
	  li        r3, 0x30
	  stw       r4, 0x18(r30)
	  stw       r5, 0x24(r30)
	  stw       r0, 0x10(r30)
	  bl        -0x61354
	  mr.       r30, r3
	  beq-      .loc_0x88
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x704

	.loc_0x88:
	  lwz       r3, 0x8(r1)
	  addi      r5, r30, 0
	  crclr     6, 0x6
	  li        r4, 0x1
	  li        r6, 0
	  bl        0x1BFEC
	  lwz       r3, 0x8(r1)
	  li        r0, 0
	  stw       r0, 0x24(r3)
	  stb       r0, 0x1F(r3)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A83B0
 * Size:	000064
 */
AndAction::~AndAction()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x48
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7ED0
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x1BA24
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x61248

	.loc_0x48:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A8414
 * Size:	000150
 */
void ActAttack::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  addi      r29, r4, 0
	  lwz       r5, 0x2F6C(r13)
	  lbz       r0, 0x1B5(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0x134
	  lwz       r3, 0xC(r31)
	  li        r30, 0
	  li        r0, 0x5
	  stb       r30, 0x408(r3)
	  lwz       r3, 0xC(r31)
	  stb       r0, 0x400(r3)
	  lwz       r3, 0xC(r31)
	  bl        0x200F4
	  cmplwi    r29, 0
	  bne-      .loc_0x68
	  stw       r30, 0x28(r31)
	  stw       r30, 0x20(r31)
	  stb       r30, 0x1F(r31)
	  b         .loc_0x9C

	.loc_0x68:
	  lwz       r0, 0x6C(r29)
	  cmpwi     r0, 0x36
	  bne-      .loc_0x90
	  stw       r29, 0x28(r31)
	  li        r0, 0x1
	  addi      r3, r31, 0
	  stb       r0, 0x1F(r31)
	  bl        0x230
	  mr        r29, r3
	  b         .loc_0x9C

	.loc_0x90:
	  stw       r30, 0x28(r31)
	  stw       r30, 0x20(r31)
	  stb       r30, 0x1F(r31)

	.loc_0x9C:
	  cmplwi    r29, 0
	  beq-      .loc_0x120
	  lwz       r3, 0x24(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xC0
	  beq-      .loc_0xC0
	  bl        0x3BEA4
	  li        r0, 0
	  stw       r0, 0x24(r31)

	.loc_0xC0:
	  stw       r29, 0x24(r31)
	  lwz       r3, 0x24(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xD4
	  bl        0x3BE78

	.loc_0xD4:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        0x1BA24
	  lwz       r0, 0x6C(r29)
	  cmpwi     r0, 0x37
	  bne-      .loc_0x120
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x9
	  addi      r3, r3, 0x54
	  bl        -0x26048
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x120
	  lwz       r0, 0x320(r29)
	  cmpwi     r0, 0x7
	  bne-      .loc_0x120
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x9
	  addi      r3, r3, 0x54
	  bl        -0x25DE0

	.loc_0x120:
	  lwz       r3, 0x3030(r13)
	  bl        -0x4F30
	  li        r0, 0
	  stb       r0, 0x1C(r31)
	  stb       r0, 0x1D(r31)

	.loc_0x134:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
// void ActAttack::startLost()
// {
// 	// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	800A8564
 * Size:	0000FC
 */
void ActAttack::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x8
	  beq-      .loc_0x48
	  bge-      .loc_0xE8
	  cmpwi     r0, 0
	  beq-      .loc_0x30
	  b         .loc_0xE8

	.loc_0x30:
	  lbz       r0, 0x1C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xE8
	  li        r0, 0x1
	  stb       r0, 0x1D(r31)
	  b         .loc_0xE8

	.loc_0x48:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0xC8(r3)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0xE8
	  lwz       r0, -0x5F04(r13)
	  cmpwi     r0, 0x1
	  ble-      .loc_0x74
	  addi      r3, r3, 0x174
	  bl        -0x3174
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE8

	.loc_0x74:
	  lwz       r3, 0xC(r31)
	  lfsu      f0, 0x464(r3)
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x20(r1)
	  lbz       r0, 0x1E(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xB8
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x18
	  li        r4, 0x45
	  li        r6, 0
	  li        r7, 0
	  bl        0xF4524
	  b         .loc_0xE8

	.loc_0xB8:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x18
	  li        r4, 0x2F
	  li        r6, 0
	  li        r7, 0
	  bl        0xF4508
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x18
	  li        r4, 0x30
	  li        r6, 0
	  li        r7, 0
	  bl        0xF44F0

	.loc_0xE8:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A8660
 * Size:	00000C
 */
void ActAttack::resume()
{
	// Generated from stb r0, 0x1C(r3)
	_1C = 0;
}

/*
 * --INFO--
 * Address:	800A866C
 * Size:	000054
 */
void ActAttack::restart()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x24(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x40
	  lwz       r3, 0x3030(r13)
	  bl        -0x5078
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r4, 0x24(r31)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x40:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A86C0
 * Size:	000008
 */
u32 ActAttack::resumable() { return 0x1; }

/*
 * --INFO--
 * Address:	800A86C8
 * Size:	000008
 */
u32 ActAttack::findTarget() { return 0x0; }

/*
 * --INFO--
 * Address:	........
 * Size:	0002C8
 */
void ActAttack::decideTarget()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A86D0
 * Size:	00033C
 */
void ActAttack::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  lwz       r4, 0x2F6C(r13)
	  lbz       r0, 0x1B5(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  li        r3, 0x2
	  b         .loc_0x320

	.loc_0x34:
	  lbz       r0, 0x1C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x78
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x5000(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4FFC(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4FF8(r13)
	  stfs      f0, 0x8(r3)
	  lbz       r0, 0x1D(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  li        r3, 0x2
	  b         .loc_0x320

	.loc_0x70:
	  li        r3, 0
	  b         .loc_0x320

	.loc_0x78:
	  lwz       r3, 0x24(r31)
	  cmplwi    r3, 0
	  bne-      .loc_0xC4
	  mr        r3, r31
	  bl        -0x90
	  mr.       r29, r3
	  beq-      .loc_0xBC
	  lwz       r3, 0x3030(r13)
	  bl        -0x5150
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r29
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  b         .loc_0x320

	.loc_0xBC:
	  li        r3, 0x2
	  b         .loc_0x320

	.loc_0xC4:
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xF8
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xF0
	  bl        -0x17F44

	.loc_0xF0:
	  li        r3, 0x2
	  b         .loc_0x320

	.loc_0xF8:
	  lwz       r3, 0x24(r31)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x164
	  mr        r29, r3
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x150
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x164
	  mr        r3, r29
	  bl        0x1FD40
	  cmpwi     r3, 0x1D
	  bne-      .loc_0x164

	.loc_0x150:
	  lwz       r4, 0xC(r31)
	  li        r0, 0x7
	  li        r3, 0x2
	  stb       r0, 0x400(r4)
	  b         .loc_0x320

	.loc_0x164:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x220
	  lwz       r3, 0x24(r31)
	  lwz       r0, 0xC8(r3)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x19C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x220

	.loc_0x19C:
	  mr        r3, r31
	  bl        -0x1A8
	  mr.       r4, r3
	  beq-      .loc_0x1C8
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  b         .loc_0x320

	.loc_0x1C8:
	  li        r0, 0x1
	  stb       r0, 0x1C(r31)
	  li        r0, 0
	  cmplwi    r31, 0
	  stb       r0, 0x1D(r31)
	  mr        r29, r31
	  beq-      .loc_0x1E8
	  addi      r29, r29, 0x18

	.loc_0x1E8:
	  addi      r3, r1, 0x34
	  li        r4, 0x41
	  bl        0x76698
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x2C
	  li        r4, 0x41
	  bl        0x766B8
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x220F4
	  li        r3, 0
	  b         .loc_0x320

	.loc_0x220:
	  mr        r3, r31
	  bl        0x1B700
	  mr.       r29, r3
	  beq-      .loc_0x31C
	  lbz       r0, 0x1F(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x284
	  mr        r3, r31
	  bl        -0x248
	  cmplwi    r3, 0
	  beq-      .loc_0x27C
	  cmpwi     r29, 0x2
	  bne-      .loc_0x27C
	  lwz       r3, 0x3030(r13)
	  bl        -0x5310
	  mr        r3, r31
	  lwz       r4, 0x28(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x2
	  b         .loc_0x320

	.loc_0x27C:
	  li        r3, 0x2
	  b         .loc_0x320

	.loc_0x284:
	  lwz       r3, 0x2F80(r13)
	  lwz       r29, 0x24(r31)
	  lwz       r0, 0xD0(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x314
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2DC
	  lwz       r3, 0x3030(r13)
	  bl        -0x5370
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r29
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  b         .loc_0x320

	.loc_0x2DC:
	  mr        r3, r31
	  bl        -0x2E8
	  mr.       r29, r3
	  beq-      .loc_0x314
	  lwz       r3, 0x3030(r13)
	  bl        -0x53A8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r29
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  b         .loc_0x320

	.loc_0x314:
	  li        r3, 0x2
	  b         .loc_0x320

	.loc_0x31C:
	  mr        r3, r29

	.loc_0x320:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A8A0C
 * Size:	000064
 */
void ActAttack::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0xC(r3)
	  bl        -0x18AE4
	  lwz       r3, 0x3030(r13)
	  bl        -0x5414
	  lwz       r3, 0xC(r31)
	  bl        -0x181BC
	  lwz       r3, 0x24(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  bl        0x3B928
	  li        r0, 0
	  stw       r0, 0x24(r31)

	.loc_0x44:
	  lwz       r3, 0xC(r31)
	  li        r0, 0
	  stb       r0, 0x519(r3)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A8A70
 * Size:	000060
 */
ActJumpAttack::ActJumpAttack(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        0x1B348
	  lis       r3, 0x802B
	  subi      r0, r3, 0x246C
	  lis       r3, 0x802B
	  stw       r0, 0x14(r31)
	  addi      r3, r3, 0x5424
	  stw       r3, 0x0(r31)
	  addi      r3, r3, 0x64
	  li        r0, 0
	  stw       r3, 0x14(r31)
	  mr        r3, r31
	  stw       r0, 0x24(r31)
	  stw       r0, 0x24(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A8AD0
 * Size:	0001CC
 */
void ActJumpAttack::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x5
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr.       r31, r4
	  stw       r30, 0x50(r1)
	  mr        r30, r3
	  stw       r29, 0x4C(r1)
	  li        r29, 0
	  stw       r28, 0x48(r1)
	  lwz       r3, 0xC(r3)
	  stb       r29, 0x408(r3)
	  lwz       r3, 0xC(r30)
	  stb       r0, 0x400(r3)
	  beq-      .loc_0x6C
	  lwz       r3, 0x24(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x58
	  beq-      .loc_0x58
	  bl        0x3B84C
	  stw       r29, 0x24(r30)

	.loc_0x58:
	  stw       r31, 0x24(r30)
	  lwz       r3, 0x24(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x6C
	  bl        0x3B824

	.loc_0x6C:
	  li        r0, 0
	  stw       r0, 0x18(r30)
	  stb       r0, 0x2C(r30)
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x150
	  lwz       r3, 0x188(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xF4
	  bl        -0x20E80
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF4
	  lwz       r3, 0xC(r30)
	  bl        -0x18C9C
	  li        r0, 0x6
	  cmplwi    r30, 0
	  stw       r0, 0x18(r30)
	  mr        r28, r30
	  beq-      .loc_0xC0
	  addi      r28, r28, 0x14

	.loc_0xC0:
	  addi      r3, r1, 0x38
	  li        r4, 0x3F
	  bl        0x763C0
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x40
	  li        r4, 0x3F
	  bl        0x763E0
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r29
	  bl        0x21E1C
	  b         .loc_0x144

	.loc_0xF4:
	  li        r0, 0x5
	  stw       r0, 0x18(r30)
	  li        r0, 0
	  cmplwi    r30, 0
	  stb       r0, 0x2D(r30)
	  mr        r28, r30
	  beq-      .loc_0x114
	  addi      r28, r28, 0x14

	.loc_0x114:
	  addi      r3, r1, 0x28
	  li        r4, 0x30
	  bl        0x7636C
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x30
	  li        r4, 0x30
	  bl        0x7638C
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r29
	  bl        0x21DC8

	.loc_0x144:
	  li        r0, 0
	  stw       r0, 0x20(r30)
	  b         .loc_0x190

	.loc_0x150:
	  cmplwi    r30, 0
	  addi      r28, r30, 0
	  beq-      .loc_0x160
	  addi      r28, r28, 0x14

	.loc_0x160:
	  addi      r3, r1, 0x18
	  li        r4, 0
	  bl        0x76320
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x20
	  li        r4, 0
	  bl        0x76340
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r29
	  bl        0x21D7C

	.loc_0x190:
	  lwz       r4, 0xC(r30)
	  lis       r5, 0x2A74
	  addi      r3, r31, 0
	  addi      r4, r4, 0x94
	  addi      r5, r5, 0x2A2A
	  bl        -0x1E918
	  stw       r3, 0x28(r30)
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  lwz       r28, 0x48(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void ActJumpAttack::getAttackPos()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void ActJumpAttack::getAttackSize()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A8C9C
 * Size:	00009C
 */
void ActJumpAttack::procStickMsg(Piki*, MsgStick*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x5
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x28(r1)
	  mr.       r28, r3
	  stw       r0, 0x18(r3)
	  li        r0, 0
	  addi      r30, r28, 0
	  stb       r0, 0x2D(r3)
	  beq-      .loc_0x40
	  addi      r30, r30, 0x14

	.loc_0x40:
	  addi      r3, r1, 0x14
	  li        r4, 0x30
	  bl        0x76274
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x30
	  bl        0x76294
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        0x21CD0
	  li        r0, 0
	  stw       r0, 0x20(r28)
	  stb       r0, 0x470(r29)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A8D38
 * Size:	00001C
 */
void ActJumpAttack::procBounceMsg(Piki*, MsgBounce*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x18(r3)
	  cmpwi     r0, 0x1
	  bnelr-
	  li        r0, 0
	  stw       r0, 0x18(r3)
	  stb       r0, 0x2C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A8D54
 * Size:	000268
 */
void ActJumpAttack::procCollideMsg(Piki*, MsgCollide*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x58(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x54(r1)
	  mr        r29, r3
	  stw       r28, 0x50(r1)
	  lwz       r3, 0x24(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x248
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x248
	  mr        r3, r30
	  bl        0x1F7B0
	  cmpwi     r3, 0x1A
	  bne-      .loc_0x60
	  b         .loc_0x248

	.loc_0x60:
	  lwz       r3, 0x24(r29)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x94
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x94
	  li        r0, 0x1
	  stb       r0, 0x2C(r29)
	  b         .loc_0x248

	.loc_0x94:
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x24(r29)
	  cmplw     r3, r0
	  bne-      .loc_0x248
	  lwz       r0, 0x18(r29)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x248
	  lwz       r0, 0x184(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x248
	  lwz       r3, 0x8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x248
	  lbz       r4, 0x5C(r3)
	  cmplwi    r4, 0x3
	  bne-      .loc_0x11C
	  bl        -0x21268
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF4
	  lwz       r4, 0x4(r31)
	  mr        r3, r30
	  lwz       r5, 0x8(r31)
	  bl        -0x1855C
	  b         .loc_0x174

	.loc_0xF4:
	  lwz       r3, 0x8(r31)
	  bl        -0x21168
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x248
	  lwz       r4, 0x4(r31)
	  mr        r3, r30
	  lwz       r5, 0x8(r31)
	  bl        -0x18580
	  b         .loc_0x174
	  b         .loc_0x248

	.loc_0x11C:
	  cmplwi    r4, 0
	  beq-      .loc_0x144
	  cmplwi    r4, 0x5
	  li        r0, 0x1
	  beq-      .loc_0x13C
	  cmplwi    r4, 0x6
	  beq-      .loc_0x13C
	  li        r0, 0

	.loc_0x13C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x248

	.loc_0x144:
	  bl        -0x212D8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x248
	  lwz       r4, 0x4(r31)
	  mr        r3, r30
	  lwz       r5, 0x8(r31)
	  li        r6, -0x1
	  lfs       f1, -0x7168(r2)
	  bl        -0x18800
	  b         .loc_0x174
	  b         .loc_0x248
	  b         .loc_0x248

	.loc_0x174:
	  li        r0, 0x5
	  stw       r0, 0x18(r29)
	  lwz       r3, 0x8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1F4
	  lbz       r0, 0x5C(r3)
	  cmplwi    r0, 0x3
	  bne-      .loc_0x1F4
	  bl        -0x21204
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1F4
	  mr        r3, r30
	  bl        -0x19020
	  cmplwi    r29, 0
	  addi      r28, r29, 0
	  beq-      .loc_0x1B8
	  addi      r28, r28, 0x14

	.loc_0x1B8:
	  addi      r3, r1, 0x38
	  li        r4, 0x3F
	  bl        0x76044
	  addi      r31, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x40
	  li        r4, 0x3F
	  bl        0x76064
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  bl        0x21AA0
	  li        r0, 0x6
	  stw       r0, 0x18(r29)
	  b         .loc_0x23C

	.loc_0x1F4:
	  li        r0, 0
	  cmplwi    r29, 0
	  stb       r0, 0x2D(r29)
	  mr        r28, r29
	  beq-      .loc_0x20C
	  addi      r28, r28, 0x14

	.loc_0x20C:
	  addi      r3, r1, 0x28
	  li        r4, 0x30
	  bl        0x75FF0
	  addi      r31, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x30
	  li        r4, 0x30
	  bl        0x76010
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  bl        0x21A4C

	.loc_0x23C:
	  li        r0, 0
	  stw       r0, 0x20(r29)
	  stb       r0, 0x470(r30)

	.loc_0x248:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  lwz       r28, 0x50(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A8FBC
 * Size:	000E6C
 */
void ActJumpAttack::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x250(r1)
	  stfd      f31, 0x248(r1)
	  stfd      f30, 0x240(r1)
	  stfd      f29, 0x238(r1)
	  stfd      f28, 0x230(r1)
	  stw       r31, 0x22C(r1)
	  mr        r31, r3
	  stw       r30, 0x228(r1)
	  stw       r29, 0x224(r1)
	  stw       r28, 0x220(r1)
	  lwz       r30, 0x24(r3)
	  cmplwi    r30, 0
	  beq-      .loc_0x74
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x90

	.loc_0x74:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x88
	  bl        -0x187C8

	.loc_0x88:
	  li        r3, 0x2
	  b         .loc_0xE3C

	.loc_0x90:
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0xC0
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xC0
	  li        r3, 0x2
	  b         .loc_0xE3C

	.loc_0xC0:
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x184(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xF4
	  beq-      .loc_0xF4
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xF4
	  li        r3, 0x2
	  b         .loc_0xE3C

	.loc_0xF4:
	  lwz       r0, 0x18(r31)
	  cmplwi    r0, 0x6
	  bgt-      .loc_0xE38
	  lis       r3, 0x802B
	  addi      r3, r3, 0x5374
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  mr        r3, r31
	  bl        0xEF4
	  b         .loc_0xE38
	  lwz       r4, 0x28(r31)
	  lwz       r3, 0xC(r31)
	  cmplwi    r4, 0
	  addi      r29, r3, 0x94
	  beq-      .loc_0x148
	  addi      r3, r1, 0x170
	  addi      r4, r4, 0x4
	  bl        -0x35FB8
	  b         .loc_0x160

	.loc_0x148:
	  lwz       r4, 0x24(r31)
	  addi      r3, r1, 0x170
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x160:
	  lfs       f1, 0x170(r1)
	  lfs       f0, 0x0(r29)
	  lfs       f3, 0x174(r1)
	  lfs       f2, 0x4(r29)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x8(r29)
	  lfs       f4, 0x178(r1)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x20C(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x210(r1)
	  stfs      f0, 0x214(r1)
	  lfs       f0, 0x20C(r1)
	  lfs       f1, 0x214(r1)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x7168(r2)
	  fmuls     f1, f1, f1
	  fadds     f31, f2, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x1C4
	  fsqrte    f0, f31
	  fmul      f0, f31, f0
	  frsp      f0, f0
	  stfs      f0, 0xCC(r1)
	  lfs       f31, 0xCC(r1)

	.loc_0x1C4:
	  lfs       f1, 0x20C(r1)
	  lfs       f0, 0x210(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x214(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9B560
	  lfs       f0, -0x7168(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x218
	  lfs       f0, 0x20C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x20C(r1)
	  lfs       f0, 0x210(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x210(r1)
	  lfs       f0, 0x214(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x214(r1)

	.loc_0x218:
	  lfs       f1, 0x20C(r1)
	  lfs       f2, 0x214(r1)
	  bl        0x17281C
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x70C34
	  lwz       r3, 0x28(r31)
	  fmr       f29, f1
	  cmplwi    r3, 0
	  beq-      .loc_0x248
	  lfs       f30, 0x0(r3)
	  b         .loc_0x260

	.loc_0x248:
	  lwz       r3, 0x24(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f30, f1

	.loc_0x260:
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f30, f1
	  fcmpo     cr0, f31, f1
	  bge-      .loc_0x2E4
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x20C
	  lfs       f1, -0x7150(r2)
	  bl        0x22B90
	  lwz       r3, 0xC(r31)
	  lfs       f2, -0x4FF4(r13)
	  addi      r4, r3, 0xA4
	  lfs       f0, 0xA4(r3)
	  lfs       f1, 0xAC(r3)
	  fmuls     f0, f0, f2
	  fmuls     f1, f1, f2
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xBC(r1)
	  stfs      f0, 0x164(r1)
	  lfs       f0, 0xA8(r3)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x168(r1)
	  stfs      f1, 0x16C(r1)
	  lwz       r3, 0x164(r1)
	  lwz       r0, 0x168(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x16C(r1)
	  stw       r0, 0x8(r4)
	  b         .loc_0xE38

	.loc_0x2E4:
	  lfs       f0, -0x714C(r2)
	  fadds     f0, f0, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x308
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x20C
	  lfs       f1, -0x7150(r2)
	  bl        0x22B1C
	  b         .loc_0xE38

	.loc_0x308:
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4FF0(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4FEC(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4FE8(r13)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x7148(r2)
	  fcmpo     cr0, f29, f0
	  bge-      .loc_0x3AC
	  lfs       f2, -0x7144(r2)
	  cmplwi    r31, 0
	  lfs       f0, 0x20C(r1)
	  mr        r30, r31
	  lfs       f1, 0x214(r1)
	  fmuls     f0, f2, f0
	  lwz       r3, 0xC(r31)
	  fmuls     f1, f2, f1
	  stfsu     f0, 0x70(r3)
	  lfs       f0, -0x7140(r2)
	  stfs      f0, 0x4(r3)
	  stfs      f1, 0x8(r3)
	  beq-      .loc_0x368
	  addi      r30, r30, 0x14

	.loc_0x368:
	  addi      r3, r1, 0x150
	  li        r4, 0x16
	  bl        0x75C2C
	  addi      r29, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x158
	  li        r4, 0x16
	  bl        0x75C4C
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r29
	  bl        0x21688
	  li        r0, 0x1
	  stw       r0, 0x18(r31)
	  lwz       r3, 0xC(r31)
	  stb       r0, 0x470(r3)
	  b         .loc_0xE38

	.loc_0x3AC:
	  lfs       f0, -0x713C(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f0, f0, f29
	  lfs       f1, 0xA0(r3)
	  fadds     f1, f1, f0
	  bl        -0x70DF4
	  lwz       r3, 0xC(r31)
	  stfs      f1, 0xA0(r3)
	  b         .loc_0xE38
	  lwz       r4, 0x28(r31)
	  lwz       r3, 0xC(r31)
	  cmplwi    r4, 0
	  addi      r29, r3, 0x94
	  beq-      .loc_0x3F4
	  addi      r3, r1, 0x138
	  addi      r4, r4, 0x4
	  bl        -0x36264
	  b         .loc_0x40C

	.loc_0x3F4:
	  lwz       r4, 0x24(r31)
	  addi      r3, r1, 0x138
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x40C:
	  lfs       f1, 0x138(r1)
	  lfs       f0, 0x0(r29)
	  lfs       f3, 0x13C(r1)
	  lfs       f2, 0x4(r29)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x8(r29)
	  lfs       f4, 0x140(r1)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x1F0(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x1F4(r1)
	  stfs      f0, 0x1F8(r1)
	  lfs       f0, 0x1F0(r1)
	  lfs       f1, 0x1F8(r1)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x7168(r2)
	  fmuls     f1, f1, f1
	  fadds     f30, f2, f1
	  fcmpo     cr0, f30, f0
	  ble-      .loc_0x470
	  fsqrte    f0, f30
	  fmul      f0, f30, f0
	  frsp      f0, f0
	  stfs      f0, 0xB8(r1)
	  lfs       f30, 0xB8(r1)

	.loc_0x470:
	  lfs       f1, 0x1F0(r1)
	  lfs       f0, 0x1F4(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x1F8(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9B80C
	  fmr       f29, f1
	  lfs       f0, -0x7168(r2)
	  fcmpu     cr0, f0, f29
	  beq-      .loc_0x4C8
	  lfs       f0, 0x1F0(r1)
	  fdivs     f0, f0, f29
	  stfs      f0, 0x1F0(r1)
	  lfs       f0, 0x1F4(r1)
	  fdivs     f0, f0, f29
	  stfs      f0, 0x1F4(r1)
	  lfs       f0, 0x1F8(r1)
	  fdivs     f0, f0, f29
	  stfs      f0, 0x1F8(r1)

	.loc_0x4C8:
	  lfs       f1, 0x1F0(r1)
	  lfs       f2, 0x1F8(r1)
	  bl        0x17256C
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x70EE4
	  lbz       r0, 0x2C(r31)
	  fabs      f31, f1
	  cmplwi    r0, 0
	  beq-      .loc_0x50C
	  beq-      .loc_0x604
	  lwz       r3, 0x28(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x604
	  bl        -0x218FC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x604

	.loc_0x50C:
	  lfs       f0, -0x7148(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x604
	  lwz       r3, 0x28(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x52C
	  lfs       f28, 0x0(r3)
	  b         .loc_0x544

	.loc_0x52C:
	  lwz       r3, 0x24(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f28, f1

	.loc_0x544:
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f28, f1
	  lfs       f0, -0x7138(r2)
	  fadds     f0, f0, f1
	  fcmpo     cr0, f29, f0
	  bge-      .loc_0x604
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x730
	  li        r0, 0
	  cmplwi    r31, 0
	  stb       r0, 0x2D(r31)
	  mr        r28, r31
	  beq-      .loc_0x594
	  addi      r28, r28, 0x14

	.loc_0x594:
	  addi      r3, r1, 0x128
	  li        r4, 0x17
	  bl        0x75A00
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x130
	  li        r4, 0x17
	  bl        0x75A20
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r29
	  bl        0x2145C
	  lwz       r3, 0xC(r31)
	  addi      r4, r30, 0
	  li        r5, 0x17
	  bl        -0x1EFD8
	  li        r0, 0
	  stw       r0, 0x20(r31)
	  li        r0, 0x4
	  stw       r0, 0x18(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4FE4(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4FE0(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4FDC(r13)
	  stfs      f0, 0x8(r3)
	  b         .loc_0x730

	.loc_0x604:
	  lwz       r3, 0x28(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x61C
	  bl        -0x21A0C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x670

	.loc_0x61C:
	  lbz       r0, 0x2C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x670
	  bl        0x16EA8C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7158(r2)
	  stw       r0, 0x21C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7160(r2)
	  stw       r0, 0x218(r1)
	  lfs       f1, -0x7164(r2)
	  lfd       f3, 0x218(r1)
	  lfs       f0, -0x7134(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x670
	  li        r0, 0x2
	  stw       r0, 0x18(r31)
	  b         .loc_0x730

	.loc_0x670:
	  lwz       r3, 0x28(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x684
	  lfs       f28, 0x0(r3)
	  b         .loc_0x69C

	.loc_0x684:
	  lwz       r3, 0x24(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f28, f1

	.loc_0x69C:
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f28, f1
	  fcmpo     cr0, f30, f0
	  bge-      .loc_0x700
	  bl        0x16E9F8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7158(r2)
	  stw       r0, 0x21C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7160(r2)
	  stw       r0, 0x218(r1)
	  lfs       f1, -0x7164(r2)
	  lfd       f3, 0x218(r1)
	  lfs       f0, -0x7130(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x700
	  li        r0, 0x2
	  stw       r0, 0x18(r31)

	.loc_0x700:
	  lfs       f0, -0x713C(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f0, f0, f31
	  lfs       f1, 0xA0(r3)
	  fadds     f1, f1, f0
	  bl        -0x71148
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x1F0
	  stfs      f1, 0xA0(r3)
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x7164(r2)
	  bl        0x226F0

	.loc_0x730:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xE38
	  lwz       r0, 0x28C(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xE38
	  li        r0, 0x5
	  stw       r0, 0x18(r31)
	  li        r0, 0
	  cmplwi    r31, 0
	  stb       r0, 0x2D(r31)
	  mr        r28, r31
	  beq-      .loc_0x76C
	  addi      r28, r28, 0x14

	.loc_0x76C:
	  addi      r3, r1, 0x118
	  li        r4, 0x30
	  bl        0x75828
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x120
	  li        r4, 0x30
	  bl        0x75848
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r29
	  bl        0x21284
	  lwz       r3, 0xC(r31)
	  addi      r4, r30, 0
	  li        r5, 0x17
	  bl        -0x1F1B0
	  li        r0, 0
	  stw       r0, 0x20(r31)
	  b         .loc_0xE38
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4FD8(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4FD4(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4FD0(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x85C
	  lwz       r0, 0x28C(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x85C
	  li        r0, 0x5
	  stw       r0, 0x18(r31)
	  li        r0, 0
	  cmplwi    r31, 0
	  stb       r0, 0x2D(r31)
	  mr        r28, r31
	  beq-      .loc_0x810
	  addi      r28, r28, 0x14

	.loc_0x810:
	  addi      r3, r1, 0x108
	  li        r4, 0x30
	  bl        0x75784
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x110
	  li        r4, 0x30
	  bl        0x757A4
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r29
	  bl        0x211E0
	  lwz       r3, 0xC(r31)
	  addi      r4, r30, 0
	  li        r5, 0x17
	  bl        -0x1F254
	  li        r0, 0
	  stw       r0, 0x20(r31)
	  b         .loc_0xE38

	.loc_0x85C:
	  lwz       r0, 0x20(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xBA0
	  lwz       r4, 0x28(r31)
	  addi      r29, r3, 0x94
	  cmplwi    r4, 0
	  beq-      .loc_0x888
	  addi      r3, r1, 0xF0
	  addi      r4, r4, 0x4
	  bl        -0x366F8
	  b         .loc_0x8A0

	.loc_0x888:
	  lwz       r4, 0x24(r31)
	  addi      r3, r1, 0xF0
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x8A0:
	  lfs       f3, 0xF8(r1)
	  lfs       f2, 0x8(r29)
	  lfs       f1, 0xF0(r1)
	  lfs       f0, 0x0(r29)
	  fsubs     f30, f3, f2
	  lfs       f2, 0xF4(r1)
	  fsubs     f29, f1, f0
	  lfs       f0, 0x4(r29)
	  fsubs     f28, f2, f0
	  fmr       f2, f30
	  fmr       f1, f29
	  bl        0x172170
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x712E0
	  fmuls     f3, f29, f29
	  lfs       f0, -0x7168(r2)
	  fmuls     f2, f28, f28
	  fmr       f31, f1
	  fmuls     f4, f30, f30
	  fadds     f1, f3, f2
	  fadds     f30, f4, f1
	  fcmpo     cr0, f30, f0
	  ble-      .loc_0x958
	  fsqrte    f1, f30
	  lfd       f3, -0x7128(r2)
	  lfd       f2, -0x7120(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f30, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f30, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f30, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f30, f0
	  frsp      f0, f0
	  stfs      f0, 0x74(r1)
	  lfs       f30, 0x74(r1)

	.loc_0x958:
	  lwz       r3, 0x28(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x96C
	  lfs       f28, 0x0(r3)
	  b         .loc_0x984

	.loc_0x96C:
	  lwz       r3, 0x24(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f28, f1

	.loc_0x984:
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fsubs     f2, f30, f28
	  lfs       f0, -0x7138(r2)
	  fsubs     f28, f2, f1
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0xA98
	  fabs      f1, f31
	  lfs       f0, -0x7118(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xA98
	  mr        r3, r30
	  bl        -0x1F6D4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x9D8
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0x37
	  bne-      .loc_0xA98

	.loc_0x9D8:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA98
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA98
	  lwz       r3, 0xC(r31)
	  bl        0x1D0EC
	  lwz       r0, 0x2FDC(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0xA28
	  lfs       f1, -0x7114(r2)

	.loc_0xA28:
	  lis       r3, 0x802B
	  lwz       r5, 0xC(r31)
	  subi      r0, r3, 0x3064
	  stw       r0, 0x1C4(r1)
	  lis       r3, 0x802B
	  subi      r4, r3, 0x31FC
	  stw       r5, 0x1C8(r1)
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r4, 0x1C4(r1)
	  addi      r4, r1, 0x1C4
	  stfs      f1, 0x1CC(r1)
	  stw       r0, 0x1D0(r1)
	  stb       r0, 0x1D4(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA8C
	  mr        r3, r31
	  bl        0x43C
	  li        r0, 0x2
	  stw       r0, 0x20(r31)
	  b         .loc_0xE38

	.loc_0xA8C:
	  li        r0, 0x1
	  stb       r0, 0x2D(r31)
	  b         .loc_0xE38

	.loc_0xA98:
	  lfs       f0, -0x7138(r2)
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0xB94
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0xB94
	  mr        r28, r30
	  lwz       r4, 0xC(r31)
	  mr        r3, r28
	  bl        0x1E508
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE38
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE38
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE38
	  lbz       r0, 0x2B4(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0xE38
	  lwz       r3, 0xC(r31)
	  bl        0x1CFF0
	  lwz       r0, 0x2FDC(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0xB24
	  lfs       f1, -0x7114(r2)

	.loc_0xB24:
	  lis       r3, 0x802B
	  lwz       r5, 0xC(r31)
	  subi      r0, r3, 0x3064
	  stw       r0, 0x1B0(r1)
	  lis       r3, 0x802B
	  subi      r4, r3, 0x31FC
	  stw       r5, 0x1B4(r1)
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r4, 0x1B0(r1)
	  addi      r4, r1, 0x1B0
	  stfs      f1, 0x1B8(r1)
	  stw       r0, 0x1BC(r1)
	  stb       r0, 0x1C0(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB88
	  mr        r3, r31
	  bl        0x340
	  li        r0, 0x2
	  stw       r0, 0x20(r31)
	  b         .loc_0xE38

	.loc_0xB88:
	  li        r0, 0x1
	  stb       r0, 0x2D(r31)
	  b         .loc_0xE38

	.loc_0xB94:
	  li        r0, 0x1
	  stb       r0, 0x2D(r31)
	  b         .loc_0xE38

	.loc_0xBA0:
	  cmpwi     r0, 0x4
	  bne-      .loc_0xE38
	  li        r3, 0x2
	  b         .loc_0xE3C
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4FCC(r13)
	  stfsu     f0, 0x70(r3)
	  lfs       f0, -0x4FC8(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4FC4(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4FC0(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4FBC(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4FB8(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r0, 0x20(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xDC8
	  lwz       r3, 0xC(r31)
	  lwz       r28, 0x184(r3)
	  cmplwi    r28, 0
	  beq-      .loc_0xDD8
	  addi      r30, r28, 0
	  addi      r3, r30, 0
	  bl        -0x1F920
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xC24
	  lwz       r0, 0x6C(r28)
	  cmpwi     r0, 0x37
	  bne-      .loc_0xCE4

	.loc_0xC24:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xCE4
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xCE4
	  lwz       r3, 0xC(r31)
	  bl        0x1CEA0
	  lwz       r0, 0x2FDC(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0xC74
	  lfs       f1, -0x7114(r2)

	.loc_0xC74:
	  lwz       r7, 0xC(r31)
	  lis       r4, 0x802B
	  lis       r3, 0x802B
	  lwz       r6, 0x188(r7)
	  subi      r0, r4, 0x3064
	  subi      r5, r3, 0x31FC
	  stw       r0, 0x19C(r1)
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r7, 0x1A0(r1)
	  addi      r4, r1, 0x19C
	  stw       r5, 0x19C(r1)
	  stfs      f1, 0x1A4(r1)
	  stw       r6, 0x1A8(r1)
	  stb       r0, 0x1AC(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xCDC
	  mr        r3, r31
	  bl        0x1EC
	  li        r0, 0x2
	  stw       r0, 0x20(r31)
	  b         .loc_0xCE4

	.loc_0xCDC:
	  li        r0, 0x1
	  stb       r0, 0x2D(r31)

	.loc_0xCE4:
	  lwz       r0, 0x6C(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0xDD8
	  lwz       r4, 0xC(r31)
	  mr        r3, r28
	  bl        0x1E2CC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDD8
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDD8
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDD8
	  lwz       r3, 0xC(r31)
	  bl        0x1CDC0
	  lwz       r0, 0x2FDC(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0xD54
	  lfs       f1, -0x7114(r2)

	.loc_0xD54:
	  lwz       r7, 0xC(r31)
	  lis       r4, 0x802B
	  lis       r3, 0x802B
	  lwz       r6, 0x188(r7)
	  subi      r0, r4, 0x3064
	  subi      r5, r3, 0x31FC
	  stw       r0, 0x188(r1)
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r7, 0x18C(r1)
	  addi      r4, r1, 0x188
	  stw       r5, 0x188(r1)
	  stfs      f1, 0x190(r1)
	  stw       r6, 0x194(r1)
	  stb       r0, 0x198(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDBC
	  mr        r3, r31
	  bl        0x10C
	  li        r0, 0x2
	  stw       r0, 0x20(r31)
	  b         .loc_0xDD8

	.loc_0xDBC:
	  li        r0, 0x1
	  stb       r0, 0x2D(r31)
	  b         .loc_0xDD8

	.loc_0xDC8:
	  cmpwi     r0, 0x4
	  bne-      .loc_0xDD8
	  li        r3, 0x2
	  b         .loc_0xE3C

	.loc_0xDD8:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xE38
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0xDF8
	  addi      r28, r28, 0x14

	.loc_0xDF8:
	  addi      r3, r1, 0xE0
	  li        r4, 0x2
	  bl        0x7519C
	  addi      r30, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0xE8
	  li        r4, 0x2
	  bl        0x751BC
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x20BF8
	  li        r0, 0
	  stw       r0, 0x18(r31)
	  li        r3, 0
	  b         .loc_0xE3C

	.loc_0xE38:
	  li        r3, 0

	.loc_0xE3C:
	  lwz       r0, 0x254(r1)
	  lfd       f31, 0x248(r1)
	  lfd       f30, 0x240(r1)
	  lfd       f29, 0x238(r1)
	  lfd       f28, 0x230(r1)
	  lwz       r31, 0x22C(r1)
	  lwz       r30, 0x228(r1)
	  lwz       r29, 0x224(r1)
	  lwz       r28, 0x220(r1)
	  addi      r1, r1, 0x250
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A9E28
 * Size:	00004C
 */
void ActJumpAttack::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x24(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C
	  bl        0x3A524
	  li        r0, 0
	  stw       r0, 0x24(r31)

	.loc_0x2C:
	  lwz       r3, 0xC(r31)
	  li        r0, 0
	  stb       r0, 0x470(r3)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A9E74
 * Size:	00002C
 */
void ActJumpAttack::attackHit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x19
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x24(r3)
	  lwz       r3, 0xC(r3)
	  bl        -0x1F8D8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A9EA0
 * Size:	00012C
 */
void ActJumpAttack::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x4C
	  bge-      .loc_0x34
	  cmpwi     r0, 0
	  beq-      .loc_0x58
	  bge-      .loc_0x40
	  b         .loc_0x118

	.loc_0x34:
	  cmpwi     r0, 0x8
	  beq-      .loc_0x78
	  b         .loc_0x118

	.loc_0x40:
	  li        r0, 0x1
	  stw       r0, 0x20(r31)
	  b         .loc_0x118

	.loc_0x4C:
	  li        r0, 0
	  stw       r0, 0x20(r31)
	  b         .loc_0x118

	.loc_0x58:
	  lwz       r0, 0x18(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x6C
	  li        r0, 0
	  stw       r0, 0x18(r31)

	.loc_0x6C:
	  li        r0, 0x4
	  stw       r0, 0x20(r31)
	  b         .loc_0x118

	.loc_0x78:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0xC8(r3)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x118
	  lwz       r0, -0x5F04(r13)
	  cmpwi     r0, 0x1
	  ble-      .loc_0xA4
	  addi      r3, r3, 0x174
	  bl        -0x4AE0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x118

	.loc_0xA4:
	  lwz       r3, 0xC(r31)
	  lfsu      f0, 0x464(r3)
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x20(r1)
	  lbz       r0, 0x2D(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xE8
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x18
	  li        r4, 0x45
	  li        r6, 0
	  li        r7, 0
	  bl        0xF2BB8
	  b         .loc_0x118

	.loc_0xE8:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x18
	  li        r4, 0x2F
	  li        r6, 0
	  li        r7, 0
	  bl        0xF2B9C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x18
	  li        r4, 0x30
	  li        r6, 0
	  li        r7, 0
	  bl        0xF2B84

	.loc_0x118:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A9FCC
 * Size:	000458
 */
void ActJumpAttack::doClimb()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF0(r1)
	  stfd      f31, 0xE8(r1)
	  stfd      f30, 0xE0(r1)
	  stfd      f29, 0xD8(r1)
	  stw       r31, 0xD4(r1)
	  mr        r31, r3
	  stw       r30, 0xD0(r1)
	  stw       r29, 0xCC(r1)
	  stw       r28, 0xC8(r1)
	  lwz       r30, 0x24(r3)
	  cmplwi    r30, 0
	  beq-      .loc_0x1D4
	  lwz       r3, 0x220(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x1D4
	  bl        -0x204C0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D4
	  lis       r4, 0x6365
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x6E74
	  bl        -0x20918
	  mr.       r30, r3
	  beq-      .loc_0x1D4
	  lwz       r3, 0xC(r31)
	  lfs       f3, 0x8(r30)
	  addi      r3, r3, 0x94
	  lfs       f1, 0x4(r30)
	  lfs       f2, 0x4(r3)
	  lfs       f0, 0x0(r3)
	  fsubs     f4, f3, f2
	  lfs       f2, 0xC(r30)
	  fsubs     f5, f1, f0
	  lfs       f1, 0x8(r3)
	  lfs       f0, -0x7168(r2)
	  fsubs     f3, f2, f1
	  fmuls     f2, f5, f5
	  fmuls     f1, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f31, f3, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x10C
	  fsqrte    f1, f31
	  lfd       f3, -0x7128(r2)
	  lfd       f2, -0x7120(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f31, f0
	  frsp      f0, f0
	  stfs      f0, 0x48(r1)
	  lfs       f31, 0x48(r1)

	.loc_0x10C:
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, 0x0(r30)
	  lfs       f0, -0x7110(r2)
	  fsubs     f2, f31, f2
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1D4
	  li        r0, 0x5
	  stw       r0, 0x18(r31)
	  li        r0, 0
	  cmplwi    r31, 0
	  stb       r0, 0x2D(r31)
	  mr        r29, r31
	  beq-      .loc_0x158
	  addi      r29, r29, 0x14

	.loc_0x158:
	  addi      r3, r1, 0x74
	  li        r4, 0x30
	  bl        0x74E2C
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x7C
	  li        r4, 0x30
	  bl        0x74E4C
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x20888
	  lwz       r3, 0xC(r31)
	  li        r0, 0
	  lfs       f0, -0x4FB4(r13)
	  stfsu     f0, 0x70(r3)
	  lfs       f0, -0x4FB0(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4FAC(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4FA8(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4FA4(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4FA0(r13)
	  stfs      f0, 0x8(r3)
	  stw       r0, 0x20(r31)
	  lwz       r3, 0xC(r31)
	  bl        -0x1A258
	  b         .loc_0x42C

	.loc_0x1D4:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x288(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x1F8
	  li        r0, 0
	  stw       r0, 0x18(r31)
	  lwz       r3, 0xC(r31)
	  bl        -0x1A27C
	  b         .loc_0x42C

	.loc_0x1F8:
	  lfs       f31, -0x710C(r2)
	  li        r30, 0x1
	  li        r28, 0
	  li        r29, 0

	.loc_0x208:
	  lwz       r3, 0xC(r31)
	  addi      r4, r29, 0x28
	  lwz       r0, 0x288(r3)
	  lwz       r12, 0x0(r3)
	  add       r4, r0, r4
	  lfs       f2, 0x94(r3)
	  lfs       f3, 0x0(r4)
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x98(r3)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x8(r4)
	  fmuls     f1, f1, f0
	  lfs       f0, 0x9C(r3)
	  lwz       r12, 0x5C(r12)
	  fmuls     f3, f3, f0
	  lfs       f0, 0xC(r4)
	  fadds     f1, f2, f1
	  mtlr      r12
	  fadds     f1, f3, f1
	  fsubs     f30, f1, f0
	  blrl
	  fmuls     f0, f31, f1
	  fcmpo     cr0, f30, f0
	  bge-      .loc_0x280
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  li        r30, 0

	.loc_0x280:
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x3
	  addi      r29, r29, 0x10
	  blt+      .loc_0x208
	  rlwinm.   r0,r30,0,24,31
	  bne-      .loc_0x2AC
	  lwz       r3, 0xC(r31)
	  bl        -0x1988C
	  li        r0, 0
	  stw       r0, 0x18(r31)
	  b         .loc_0x42C

	.loc_0x2AC:
	  lfs       f1, -0x4F9C(r13)
	  lfs       f0, -0x4F98(r13)
	  stfs      f1, 0xA8(r1)
	  stfs      f0, 0xAC(r1)
	  lfs       f0, -0x4F94(r13)
	  stfs      f0, 0xB0(r1)
	  lfs       f0, -0x7168(r2)
	  stfs      f0, 0xA4(r1)
	  stfs      f0, 0xA0(r1)
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x284(r3)
	  lfs       f30, 0x0(r3)
	  lfs       f31, 0x4(r3)
	  fmuls     f1, f30, f30
	  lfs       f29, 0x8(r3)
	  fmuls     f0, f31, f31
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9C684
	  lfs       f0, -0x7168(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x314
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1
	  fdivs     f29, f29, f1

	.loc_0x314:
	  lfs       f1, 0xA8(r1)
	  addi      r6, r1, 0x3C
	  lfs       f0, 0xAC(r1)
	  addi      r5, r1, 0x38
	  fmuls     f1, f1, f30
	  fmuls     f0, f0, f31
	  lfs       f2, 0xB0(r1)
	  addi      r4, r1, 0x34
	  fmuls     f2, f2, f29
	  fadds     f0, f1, f0
	  addi      r3, r1, 0x68
	  fadds     f0, f2, f0
	  fmuls     f2, f29, f0
	  fmuls     f1, f31, f0
	  fmuls     f0, f30, f0
	  stfs      f2, 0x3C(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f0, 0x34(r1)
	  bl        -0x7320C
	  lwz       r0, 0xA8(r1)
	  lwz       r3, 0xAC(r1)
	  stw       r0, 0x9C(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r3, 0xA0(r1)
	  stw       r0, 0xA4(r1)
	  lfs       f1, 0x9C(r1)
	  lfs       f0, 0xA0(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xA4(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9C724
	  lfs       f0, -0x7168(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x3CC
	  lfs       f0, 0x9C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0xA0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xA0(r1)
	  lfs       f0, 0xA4(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xA4(r1)

	.loc_0x3CC:
	  lfs       f4, -0x4F90(r13)
	  lfs       f0, 0x9C(r1)
	  lfs       f1, 0xA0(r1)
	  lfs       f2, 0xA4(r1)
	  fmuls     f0, f0, f4
	  fmuls     f3, f1, f4
	  fmuls     f1, f2, f4
	  stfs      f0, 0x9C(r1)
	  stfs      f3, 0xA0(r1)
	  stfs      f1, 0xA4(r1)
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x9C(r1)
	  lwz       r0, 0xA0(r1)
	  stw       r3, 0xA4(r4)
	  stw       r0, 0xA8(r4)
	  lwz       r0, 0xA4(r1)
	  stw       r0, 0xAC(r4)
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x9C(r1)
	  lwz       r0, 0xA0(r1)
	  stw       r3, 0x70(r4)
	  stw       r0, 0x74(r4)
	  lwz       r0, 0xA4(r1)
	  stw       r0, 0x78(r4)

	.loc_0x42C:
	  lwz       r0, 0xF4(r1)
	  lfd       f31, 0xE8(r1)
	  lfd       f30, 0xE0(r1)
	  lfd       f29, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  lwz       r29, 0xCC(r1)
	  lwz       r28, 0xC8(r1)
	  addi      r1, r1, 0xF0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AA424
 * Size:	00006C
 */
ActJumpAttack::~ActJumpAttack()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x50
	  lis       r3, 0x802B
	  addi      r3, r3, 0x5424
	  stw       r3, 0x0(r30)
	  addi      r0, r3, 0x64
	  addi      r3, r30, 0
	  stw       r0, 0x14(r30)
	  li        r4, 0
	  bl        0x199A8
	  extsh.    r0, r31
	  ble-      .loc_0x50
	  mr        r3, r30
	  bl        -0x632C4

	.loc_0x50:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AA490
 * Size:	00007C
 */
ActAttack::~ActAttack()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x60
	  lis       r3, 0x802B
	  addi      r3, r3, 0x54E8
	  stw       r3, 0x0(r30)
	  addi      r0, r3, 0x64
	  stw       r0, 0x18(r30)
	  beq-      .loc_0x50
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7ED0
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x1992C

	.loc_0x50:
	  extsh.    r0, r31
	  ble-      .loc_0x60
	  mr        r3, r30
	  bl        -0x63340

	.loc_0x60:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AA50C
 * Size:	000008
 */
void ActAttack::@24 @animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  subi      r3, r3, 0x18
	  b         -0x1FAC
	*/
}

/*
 * --INFO--
 * Address:	800AA514
 * Size:	000008
 */
void ActJumpAttack::@20 @animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  subi      r3, r3, 0x14
	  b         -0x678
	*/
}
