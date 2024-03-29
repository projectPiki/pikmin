#include "types.h"

/*
 * --INFO--
 * Address:	8020CC78
 * Size:	0001F8
 */
void UpdateIconOffsets(void)
{
	/*
	.loc_0x0:
	  lwz       r8, 0x2C(r3)
	  addis     r0, r8, 0x1
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0x24
	  li        r0, 0
	  stb       r0, 0x2E(r4)
	  li        r8, 0
	  sth       r0, 0x34(r4)
	  sth       r0, 0x36(r4)

	.loc_0x24:
	  lbz       r0, 0x7(r3)
	  li        r9, 0
	  rlwinm    r0,r0,0,30,31
	  cmpwi     r0, 0x2
	  beq-      .loc_0x5C
	  bge-      .loc_0x70
	  cmpwi     r0, 0x1
	  bge-      .loc_0x48
	  b         .loc_0x70

	.loc_0x48:
	  stw       r8, 0x3C(r4)
	  addi      r0, r8, 0xC00
	  addi      r8, r8, 0xE00
	  stw       r0, 0x40(r4)
	  b         .loc_0x7C

	.loc_0x5C:
	  stw       r8, 0x3C(r4)
	  li        r0, -0x1
	  addi      r8, r8, 0x1800
	  stw       r0, 0x40(r4)
	  b         .loc_0x7C

	.loc_0x70:
	  li        r0, -0x1
	  stw       r0, 0x3C(r4)
	  stw       r0, 0x40(r4)

	.loc_0x7C:
	  li        r0, 0x2
	  mtctr     r0
	  addi      r7, r4, 0
	  li        r10, 0
	  li        r6, 0
	  li        r0, -0x1

	.loc_0x94:
	  lhz       r5, 0x30(r3)
	  sraw      r5, r5, r6
	  rlwinm    r5,r5,0,30,31
	  cmpwi     r5, 0x2
	  beq-      .loc_0xC8
	  bge-      .loc_0xD4
	  cmpwi     r5, 0x1
	  bge-      .loc_0xB8
	  b         .loc_0xD4

	.loc_0xB8:
	  stw       r8, 0x44(r7)
	  li        r9, 0x1
	  addi      r8, r8, 0x400
	  b         .loc_0xD8

	.loc_0xC8:
	  stw       r8, 0x44(r7)
	  addi      r8, r8, 0x800
	  b         .loc_0xD8

	.loc_0xD4:
	  stw       r0, 0x44(r7)

	.loc_0xD8:
	  lhz       r5, 0x30(r3)
	  addi      r6, r6, 0x2
	  addi      r7, r7, 0x4
	  sraw      r5, r5, r6
	  rlwinm    r5,r5,0,30,31
	  cmpwi     r5, 0x2
	  beq-      .loc_0x114
	  bge-      .loc_0x120
	  cmpwi     r5, 0x1
	  bge-      .loc_0x104
	  b         .loc_0x120

	.loc_0x104:
	  stw       r8, 0x44(r7)
	  li        r9, 0x1
	  addi      r8, r8, 0x400
	  b         .loc_0x124

	.loc_0x114:
	  stw       r8, 0x44(r7)
	  addi      r8, r8, 0x800
	  b         .loc_0x124

	.loc_0x120:
	  stw       r0, 0x44(r7)

	.loc_0x124:
	  lhz       r5, 0x30(r3)
	  addi      r6, r6, 0x2
	  addi      r10, r10, 0x1
	  sraw      r5, r5, r6
	  rlwinm    r5,r5,0,30,31
	  cmpwi     r5, 0x2
	  addi      r7, r7, 0x4
	  beq-      .loc_0x164
	  bge-      .loc_0x170
	  cmpwi     r5, 0x1
	  bge-      .loc_0x154
	  b         .loc_0x170

	.loc_0x154:
	  stw       r8, 0x44(r7)
	  li        r9, 0x1
	  addi      r8, r8, 0x400
	  b         .loc_0x174

	.loc_0x164:
	  stw       r8, 0x44(r7)
	  addi      r8, r8, 0x800
	  b         .loc_0x174

	.loc_0x170:
	  stw       r0, 0x44(r7)

	.loc_0x174:
	  lhz       r5, 0x30(r3)
	  addi      r6, r6, 0x2
	  addi      r10, r10, 0x1
	  sraw      r5, r5, r6
	  rlwinm    r5,r5,0,30,31
	  cmpwi     r5, 0x2
	  addi      r7, r7, 0x4
	  beq-      .loc_0x1B4
	  bge-      .loc_0x1C0
	  cmpwi     r5, 0x1
	  bge-      .loc_0x1A4
	  b         .loc_0x1C0

	.loc_0x1A4:
	  stw       r8, 0x44(r7)
	  li        r9, 0x1
	  addi      r8, r8, 0x400
	  b         .loc_0x1C4

	.loc_0x1B4:
	  stw       r8, 0x44(r7)
	  addi      r8, r8, 0x800
	  b         .loc_0x1C4

	.loc_0x1C0:
	  stw       r0, 0x44(r7)

	.loc_0x1C4:
	  addi      r6, r6, 0x2
	  addi      r7, r7, 0x4
	  addi      r10, r10, 0x1
	  bdnz+     .loc_0x94
	  cmpwi     r9, 0
	  beq-      .loc_0x1E8
	  stw       r8, 0x64(r4)
	  addi      r8, r8, 0x200
	  b         .loc_0x1F0

	.loc_0x1E8:
	  li        r0, -0x1
	  stw       r0, 0x64(r4)

	.loc_0x1F0:
	  stw       r8, 0x68(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020CE70
 * Size:	000128
 */
void CARDGetStatus(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  mr.       r29, r4
	  blt-      .loc_0x2C
	  cmpwi     r29, 0x7F
	  blt-      .loc_0x34

	.loc_0x2C:
	  li        r3, -0x80
	  b         .loc_0x10C

	.loc_0x34:
	  addi      r4, r1, 0x14
	  bl        -0x4038
	  cmpwi     r3, 0
	  bge-      .loc_0x48
	  b         .loc_0x10C

	.loc_0x48:
	  lwz       r3, 0x14(r1)
	  bl        -0x360C
	  rlwinm    r0,r29,6,0,25
	  add       r29, r3, r0
	  addi      r3, r29, 0
	  bl        -0x13E4
	  addi      r30, r3, 0
	  cmpwi     r30, -0xA
	  bne-      .loc_0x78
	  mr        r3, r29
	  bl        -0x136C
	  mr        r30, r3

	.loc_0x78:
	  cmpwi     r30, 0
	  blt-      .loc_0x100
	  addi      r4, r29, 0
	  addi      r3, r31, 0x28
	  li        r5, 0x4
	  bl        -0x209AE8
	  addi      r3, r31, 0x2C
	  addi      r4, r29, 0x4
	  li        r5, 0x2
	  bl        -0x209AF8
	  lwz       r5, 0x14(r1)
	  mr        r3, r31
	  lhz       r6, 0x38(r29)
	  addi      r4, r29, 0x8
	  lwz       r0, 0xC(r5)
	  li        r5, 0x20
	  mullw     r0, r6, r0
	  stw       r0, 0x20(r31)
	  bl        -0x209B1C
	  lwz       r0, 0x28(r29)
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  stw       r0, 0x24(r31)
	  lbz       r0, 0x7(r29)
	  stb       r0, 0x2E(r31)
	  lwz       r0, 0x2C(r29)
	  stw       r0, 0x30(r31)
	  lhz       r0, 0x30(r29)
	  sth       r0, 0x34(r31)
	  lhz       r0, 0x32(r29)
	  sth       r0, 0x36(r31)
	  lwz       r0, 0x3C(r29)
	  stw       r0, 0x38(r31)
	  bl        -0x2F4

	.loc_0x100:
	  lwz       r3, 0x14(r1)
	  mr        r4, r30
	  bl        -0x4058

	.loc_0x10C:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  mtlr      r0
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020CF98
 * Size:	000170
 */
void CARDSetStatusAsync(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr.       r31, r4
	  stw       r30, 0x28(r1)
	  addi      r30, r6, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r5, 0
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  blt-      .loc_0x6C
	  cmpwi     r31, 0x7F
	  bge-      .loc_0x6C
	  lwz       r3, 0x30(r29)
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  beq-      .loc_0x50
	  cmplwi    r3, 0x200
	  bge-      .loc_0x6C

	.loc_0x50:
	  lwz       r3, 0x38(r29)
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  beq-      .loc_0x74
	  rlwinm    r0,r3,0,19,31
	  cmplwi    r0, 0x1FC0
	  ble-      .loc_0x74

	.loc_0x6C:
	  li        r3, -0x80
	  b         .loc_0x150

	.loc_0x74:
	  addi      r3, r28, 0
	  addi      r4, r1, 0x18
	  bl        -0x41A4
	  cmpwi     r3, 0
	  bge-      .loc_0x8C
	  b         .loc_0x150

	.loc_0x8C:
	  lwz       r3, 0x18(r1)
	  bl        -0x3778
	  rlwinm    r0,r31,6,0,25
	  add       r31, r3, r0
	  addi      r3, r31, 0
	  bl        -0x1550
	  mr.       r4, r3
	  bge-      .loc_0xB8
	  lwz       r3, 0x18(r1)
	  bl        -0x4128
	  b         .loc_0x150

	.loc_0xB8:
	  lbz       r0, 0x2E(r29)
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  stb       r0, 0x7(r31)
	  lwz       r0, 0x30(r29)
	  stw       r0, 0x2C(r31)
	  lhz       r0, 0x34(r29)
	  sth       r0, 0x30(r31)
	  lhz       r0, 0x36(r29)
	  sth       r0, 0x32(r31)
	  lwz       r0, 0x38(r29)
	  stw       r0, 0x3C(r31)
	  bl        -0x408
	  lwz       r3, 0x2C(r31)
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0x10C
	  lhz       r0, 0x32(r31)
	  rlwinm    r0,r0,0,0,29
	  ori       r0, r0, 0x1
	  sth       r0, 0x32(r31)

	.loc_0x10C:
	  lis       r3, 0x8000
	  lwz       r0, 0xF8(r3)
	  rlwinm    r29,r0,30,2,31
	  bl        -0xFD10
	  addi      r6, r29, 0
	  li        r5, 0
	  bl        0x7EEC
	  stw       r4, 0x28(r31)
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        -0x367C
	  mr.       r28, r3
	  bge-      .loc_0x14C
	  lwz       r3, 0x18(r1)
	  mr        r4, r28
	  bl        -0x41C0

	.loc_0x14C:
	  mr        r3, r28

	.loc_0x150:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  mtlr      r0
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020D108
 * Size:	000048
 */
void CARDSetStatus(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8020
	  stw       r0, 0x4(r1)
	  addi      r6, r6, 0x7E64
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  bl        -0x18C
	  cmpwi     r3, 0
	  bge-      .loc_0x2C
	  b         .loc_0x34

	.loc_0x2C:
	  mr        r3, r31
	  bl        -0x400C

	.loc_0x34:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
