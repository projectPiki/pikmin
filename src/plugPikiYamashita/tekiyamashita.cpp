#include "types.h"

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
 * Address:	801A30F8
 * Size:	000180
 */
void TekiYamashita::makeTekiParameters(TekiMgr*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  li        r3, 0x88
	  stw       r30, 0x10(r1)
	  bl        -0x15C110
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x30
	  bl        0x530

	.loc_0x30:
	  stw       r30, 0x88(r31)
	  li        r3, 0x88
	  bl        -0x15C12C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x4C
	  bl        0x26B8

	.loc_0x4C:
	  stw       r30, 0x8C(r31)
	  li        r3, 0x88
	  bl        -0x15C148
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x68
	  bl        0x228FC

	.loc_0x68:
	  stw       r30, 0x90(r31)
	  li        r3, 0x88
	  bl        -0x15C164
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x84
	  bl        0x271B4

	.loc_0x84:
	  stw       r30, 0x94(r31)
	  li        r3, 0x88
	  bl        -0x15C180
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xA0
	  bl        0x28A58

	.loc_0xA0:
	  stw       r30, 0x98(r31)
	  li        r3, 0x88
	  bl        -0x15C19C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xBC
	  bl        0x2A5F4

	.loc_0xBC:
	  stw       r30, 0x9C(r31)
	  li        r3, 0x88
	  bl        -0x15C1B8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xD8
	  bl        0x2CCC4

	.loc_0xD8:
	  stw       r30, 0xA0(r31)
	  li        r3, 0x88
	  bl        -0x15C1D4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xF4
	  bl        0x2E03C

	.loc_0xF4:
	  stw       r30, 0xA4(r31)
	  li        r3, 0x88
	  bl        -0x15C1F0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x110
	  bl        0x31680

	.loc_0x110:
	  stw       r30, 0xA8(r31)
	  li        r3, 0x88
	  bl        -0x15C20C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x12C
	  bl        0x330B0

	.loc_0x12C:
	  stw       r30, 0xAC(r31)
	  li        r3, 0x88
	  bl        -0x15C228
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x148
	  bl        0x46D64

	.loc_0x148:
	  stw       r30, 0xB4(r31)
	  li        r3, 0x88
	  bl        -0x15C244
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x164
	  bl        0x4789C

	.loc_0x164:
	  stw       r30, 0xB0(r31)
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
 * Address:	801A3278
 * Size:	00031C
 */
void TekiYamashita::makeTekis(TekiMgr*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  li        r3, 0x10
	  stw       r30, 0x40(r1)
	  bl        -0x15C290
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x30
	  bl        0x714

	.loc_0x30:
	  lwz       r4, 0x3C(r31)
	  li        r3, 0x8
	  lwz       r4, 0x4(r4)
	  stw       r30, 0x3C(r4)
	  bl        -0x15C2B4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x54
	  bl        0x308

	.loc_0x54:
	  lwz       r4, 0x44(r31)
	  li        r3, 0x10
	  stw       r30, 0x3C(r4)
	  bl        -0x15C2D4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x74
	  bl        0x2950

	.loc_0x74:
	  lwz       r4, 0x3C(r31)
	  li        r3, 0x8
	  lwz       r4, 0x4(r4)
	  stw       r30, 0x40(r4)
	  bl        -0x15C2F8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x98
	  bl        0x2468

	.loc_0x98:
	  lwz       r4, 0x44(r31)
	  li        r3, 0x10
	  stw       r30, 0x40(r4)
	  bl        -0x15C318
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xB8
	  bl        0x22B44

	.loc_0xB8:
	  lwz       r4, 0x3C(r31)
	  li        r3, 0x8
	  lwz       r4, 0x4(r4)
	  stw       r30, 0x44(r4)
	  bl        -0x15C33C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xDC
	  bl        0x22684

	.loc_0xDC:
	  lwz       r4, 0x44(r31)
	  li        r3, 0x10
	  stw       r30, 0x44(r4)
	  bl        -0x15C35C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xFC
	  bl        0x27328

	.loc_0xFC:
	  lwz       r4, 0x3C(r31)
	  li        r3, 0x8
	  lwz       r4, 0x4(r4)
	  stw       r30, 0x48(r4)
	  bl        -0x15C380
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x120
	  bl        0x26F14

	.loc_0x120:
	  lwz       r4, 0x44(r31)
	  li        r3, 0x10
	  stw       r30, 0x48(r4)
	  bl        -0x15C3A0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x140
	  bl        0x28BF8

	.loc_0x140:
	  lwz       r4, 0x3C(r31)
	  li        r3, 0x8
	  lwz       r4, 0x4(r4)
	  stw       r30, 0x4C(r4)
	  bl        -0x15C3C4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x164
	  bl        0x28790

	.loc_0x164:
	  lwz       r4, 0x44(r31)
	  li        r3, 0x10
	  stw       r30, 0x4C(r4)
	  bl        -0x15C3E4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x184
	  bl        0x2A824

	.loc_0x184:
	  lwz       r4, 0x3C(r31)
	  li        r3, 0x8
	  lwz       r4, 0x4(r4)
	  stw       r30, 0x50(r4)
	  bl        -0x15C408
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1A8
	  bl        0x2A304

	.loc_0x1A8:
	  lwz       r4, 0x44(r31)
	  li        r3, 0x10
	  stw       r30, 0x50(r4)
	  bl        -0x15C428
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1C8
	  bl        0x2CD48

	.loc_0x1C8:
	  lwz       r4, 0x3C(r31)
	  li        r3, 0x8
	  lwz       r4, 0x4(r4)
	  stw       r30, 0x54(r4)
	  bl        -0x15C44C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1EC
	  bl        0x2C9AC

	.loc_0x1EC:
	  lwz       r4, 0x44(r31)
	  li        r3, 0x18
	  stw       r30, 0x54(r4)
	  bl        -0x15C46C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x20C
	  bl        0x2E164

	.loc_0x20C:
	  lwz       r4, 0x3C(r31)
	  li        r3, 0x8
	  lwz       r4, 0x4(r4)
	  stw       r30, 0x58(r4)
	  bl        -0x15C490
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x230
	  bl        0x2DCFC

	.loc_0x230:
	  lwz       r4, 0x44(r31)
	  li        r3, 0x10
	  stw       r30, 0x58(r4)
	  bl        -0x15C4B0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x250
	  bl        0x316B8

	.loc_0x250:
	  lwz       r4, 0x3C(r31)
	  li        r3, 0x8
	  lwz       r4, 0x4(r4)
	  stw       r30, 0x5C(r4)
	  bl        -0x15C4D4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x274
	  bl        0x31318

	.loc_0x274:
	  lwz       r4, 0x44(r31)
	  li        r3, 0x10
	  stw       r30, 0x5C(r4)
	  bl        -0x15C4F4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x294
	  bl        0x331CC

	.loc_0x294:
	  lwz       r4, 0x3C(r31)
	  li        r3, 0x8
	  lwz       r4, 0x4(r4)
	  stw       r30, 0x60(r4)
	  bl        -0x15C518
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x2B8
	  bl        0x32D20

	.loc_0x2B8:
	  lwz       r4, 0x44(r31)
	  li        r3, 0x10
	  stw       r30, 0x60(r4)
	  bl        -0x15C538
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x2D8
	  bl        0x478E4

	.loc_0x2D8:
	  lwz       r4, 0x3C(r31)
	  li        r3, 0x8
	  lwz       r4, 0x4(r4)
	  stw       r30, 0x64(r4)
	  bl        -0x15C55C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x2FC
	  bl        0x47500

	.loc_0x2FC:
	  lwz       r3, 0x44(r31)
	  stw       r30, 0x64(r3)
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000488
 */
void TekiYamashita::makeDefaultAnimations()
{
	// UNUSED FUNCTION
}
