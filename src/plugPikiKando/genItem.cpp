#include "types.h"

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
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
GenObjectItem::GenObjectItem()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800EE320
 * Size:	0000A8
 */
void GenObjectItem::ramSaveParameters(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r4, r30, 0x24
	  lwz       r12, 0x4(r31)
	  addi      r3, r31, 0
	  lwz       r4, 0x0(r4)
	  lwz       r12, 0x28(r12)
	  addi      r4, r4, 0x1
	  mtlr      r12
	  blrl
	  lwz       r12, 0x4(r31)
	  mr        r3, r31
	  lwz       r0, 0x34(r30)
	  lwz       r12, 0x28(r12)
	  rlwinm    r4,r0,0,24,31
	  mtlr      r12
	  blrl
	  lwz       r12, 0x4(r31)
	  mr        r3, r31
	  lwz       r0, 0x44(r30)
	  lwz       r12, 0x28(r12)
	  rlwinm    r4,r0,0,24,31
	  mtlr      r12
	  blrl
	  lwz       r12, 0x4(r31)
	  mr        r3, r31
	  lwz       r0, 0x54(r30)
	  lwz       r12, 0x28(r12)
	  rlwinm    r4,r0,0,24,31
	  mtlr      r12
	  blrl
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
 * Address:	800EE3C8
 * Size:	0000A8
 */
void GenObjectItem::ramLoadParameters(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r3,r3,0,24,31
	  subi      r0, r3, 0x1
	  stw       r0, 0x24(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  stw       r0, 0x34(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  stw       r0, 0x44(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  stw       r0, 0x54(r30)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EE470
 * Size:	000158
 */
void makeObjectItem()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x9C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  bl        -0xA7488
	  mr.       r31, r3
	  beq-      .loc_0x138
	  lis       r4, 0x802C
	  lis       r3, 0x802C
	  subi      r5, r4, 0x285C
	  lis       r4, 0x6974
	  subi      r6, r3, 0x2850
	  addi      r3, r31, 0
	  addi      r4, r4, 0x656D
	  bl        -0x13800
	  lis       r3, 0x802C
	  subi      r0, r3, 0x5490
	  lis       r3, 0x802C
	  stw       r0, 0x4(r31)
	  subi      r0, r3, 0x2770
	  stw       r0, 0x4(r31)
	  addi      r5, r1, 0x24
	  addi      r4, r31, 0
	  lwz       r0, -0x32C8(r13)
	  addi      r3, r31, 0x18
	  stw       r0, 0x2C(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r0, 0x24(r1)
	  bl        -0x8FA6C
	  lis       r3, 0x802A
	  addi      r29, r3, 0x60C4
	  stw       r29, 0x20(r31)
	  li        r30, 0
	  addi      r5, r1, 0x20
	  stw       r30, 0x24(r31)
	  mr        r4, r31
	  addi      r3, r31, 0x28
	  lwz       r0, -0x32C4(r13)
	  stw       r0, 0x34(r1)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0x20(r1)
	  bl        -0x8FAA0
	  stw       r29, 0x30(r31)
	  addi      r5, r1, 0x1C
	  addi      r4, r31, 0
	  stw       r30, 0x34(r31)
	  addi      r3, r31, 0x38
	  lwz       r0, -0x32C0(r13)
	  stw       r0, 0x3C(r1)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x1C(r1)
	  bl        -0x8FAC8
	  stw       r29, 0x40(r31)
	  addi      r5, r1, 0x18
	  addi      r4, r31, 0
	  stw       r30, 0x44(r31)
	  addi      r3, r31, 0x48
	  lwz       r0, -0x32BC(r13)
	  stw       r0, 0x44(r1)
	  lwz       r0, 0x44(r1)
	  stw       r0, 0x18(r1)
	  bl        -0x8FAF0
	  stw       r29, 0x50(r31)
	  li        r3, 0x3
	  li        r0, 0x1
	  crclr     6, 0x6
	  stw       r3, 0x54(r31)
	  addi      r3, r31, 0x5C
	  stw       r0, 0x58(r31)
	  subi      r4, r13, 0x32B8
	  bl        0x128004
	  addi      r3, r31, 0x7C
	  crclr     6, 0x6
	  subi      r4, r13, 0x32B8
	  bl        0x127FF4

	.loc_0x138:
	  mr        r3, r31
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EE5C8
 * Size:	00008C
 */
void GenObjectItem::initialise()
{
	/*
	.loc_0x0:
	  lwz       r7, 0x3074(r13)
	  lwz       r5, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  cmpw      r5, r0
	  bgelr-
	  lis       r4, 0x6974
	  lwz       r3, 0x8(r7)
	  addi      r4, r4, 0x656D
	  rlwinm    r0,r5,4,0,27
	  stwx      r4, r3, r0
	  lis       r6, 0x800F
	  lis       r4, 0x802C
	  lwz       r0, 0x0(r7)
	  lis       r3, 0x7630
	  lwz       r5, 0x8(r7)
	  subi      r6, r6, 0x1B90
	  rlwinm    r0,r0,4,0,27
	  add       r5, r5, r0
	  stw       r6, 0x4(r5)
	  subi      r5, r4, 0x2840
	  addi      r4, r3, 0x2E31
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r5, 0x8(r3)
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r4, 0xC(r3)
	  lwz       r3, 0x0(r7)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r7)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EE654
 * Size:	00011C
 */
void GenObjectItem::doRead(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x120(r1)
	  stw       r31, 0x11C(r1)
	  stw       r30, 0x118(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x114(r1)
	  addi      r29, r3, 0
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  stw       r0, 0x58(r29)
	  b         .loc_0x100

	.loc_0x4C:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  addi      r4, r1, 0x10
	  li        r5, 0x100
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x10
	  bl        -0x59C40
	  stw       r3, 0x58(r29)
	  lwz       r3, 0xC(r29)
	  subis     r0, r3, 0x7630
	  cmplwi    r0, 0x2E30
	  beq-      .loc_0xE0
	  li        r31, 0

	.loc_0x88:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r31, 0x5C
	  addi      r31, r31, 0x1
	  stbx      r3, r29, r0
	  cmpwi     r31, 0x20
	  blt+      .loc_0x88
	  li        r31, 0

	.loc_0xB4:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r31, 0x7C
	  addi      r31, r31, 0x1
	  stbx      r3, r29, r0
	  cmpwi     r31, 0x20
	  blt+      .loc_0xB4
	  b         .loc_0x100

	.loc_0xE0:
	  addi      r3, r29, 0x5C
	  crclr     6, 0x6
	  subi      r4, r13, 0x32B8
	  bl        0x127E58
	  addi      r3, r29, 0x7C
	  crclr     6, 0x6
	  subi      r4, r13, 0x32B8
	  bl        0x127E48

	.loc_0x100:
	  lwz       r0, 0x124(r1)
	  lwz       r31, 0x11C(r1)
	  lwz       r30, 0x118(r1)
	  lwz       r29, 0x114(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EE770
 * Size:	000100
 */
void GenObjectItem::doWrite(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  mr        r3, r30
	  lwz       r0, 0x58(r29)
	  lwz       r12, 0x4(r30)
	  rlwinm    r4,r0,0,24,31
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE4

	.loc_0x4C:
	  lwz       r3, 0x58(r29)
	  bl        -0x59D88
	  lwz       r12, 0x4(r30)
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  subis     r0, r3, 0x7630
	  cmplwi    r0, 0x2E30
	  beq-      .loc_0xE4
	  li        r31, 0

	.loc_0x90:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  addi      r0, r31, 0x5C
	  lbzx      r4, r29, r0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x20
	  blt+      .loc_0x90
	  li        r31, 0

	.loc_0xBC:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  addi      r0, r31, 0x7C
	  lbzx      r4, r29, r0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x20
	  blt+      .loc_0xBC

	.loc_0xE4:
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
 * Address:	........
 * Size:	000028
 */
void sprintID(char*, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800EE870
 * Size:	000030
 */
void GenObjectItem::updateUseList(Generator*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x58(r3)
	  cmpwi     r4, -0x1
	  beq-      .loc_0x20
	  lwz       r3, 0x30AC(r13)
	  bl        0x5010

	.loc_0x20:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EE8A0
 * Size:	000448
 */
void GenObjectItem::birth(BirthInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stfd      f31, 0xA0(r1)
	  stmw      r27, 0x8C(r1)
	  mr        r29, r3
	  addi      r30, r4, 0
	  lwz       r0, 0x58(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x430

	.loc_0x30:
	  cmpwi     r0, 0x10
	  bne-      .loc_0x9C
	  lwz       r4, 0x2F6C(r13)
	  li        r3, 0x1
	  lwz       r0, 0x24(r29)
	  lbz       r4, 0x184(r4)
	  slw       r0, r3, r0
	  and.      r0, r4, r0
	  bne-      .loc_0x78
	  lwz       r5, 0x24(r30)
	  lis       r3, 0x6E65
	  addi      r4, r3, 0x7874
	  addi      r3, r5, 0x58
	  bl        -0xAA910
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9C
	  li        r3, 0
	  b         .loc_0x430

	.loc_0x78:
	  lwz       r5, 0x24(r30)
	  lis       r3, 0x6E65
	  addi      r4, r3, 0x7874
	  addi      r3, r5, 0x58
	  bl        -0xAA948
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9C
	  li        r3, 0
	  b         .loc_0x430

	.loc_0x9C:
	  lwz       r3, 0x30AC(r13)
	  lwz       r4, 0x58(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  beq-      .loc_0x42C
	  lwz       r3, 0x6C(r31)
	  subi      r0, r3, 0xC
	  cmplwi    r0, 0x16
	  bgt-      .loc_0x1E4
	  lis       r3, 0x802C
	  subi      r3, r3, 0x2830
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  addi      r4, r29, 0x24
	  lwz       r4, 0x0(r4)
	  addi      r3, r31, 0
	  bl        -0x32A4
	  b         .loc_0x1E4
	  lwz       r0, 0x24(r29)
	  mr        r3, r31
	  stw       r0, 0x2D0(r31)
	  bl        -0xEBC
	  b         .loc_0x1E4
	  addi      r4, r29, 0x24
	  lwz       r4, 0x0(r4)
	  addi      r3, r31, 0
	  bl        -0xA628
	  b         .loc_0x1E4
	  lwz       r0, 0x54(r29)
	  stw       r0, 0x440(r31)
	  b         .loc_0x1E4
	  lwz       r4, 0x24(r29)
	  lis       r0, 0x4330
	  lfd       f2, -0x6460(r2)
	  addi      r3, r31, 0
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x7C(r1)
	  lfs       f0, -0x6470(r2)
	  stw       r0, 0x78(r1)
	  lfd       f1, 0x78(r1)
	  stw       r4, 0x84(r1)
	  fsubs     f1, f1, f2
	  stw       r0, 0x80(r1)
	  fcmpo     cr0, f1, f0
	  lfd       f0, 0x80(r1)
	  fsubs     f1, f0, f2
	  cror      2, 0, 0x2
	  bne-      .loc_0x174
	  lfs       f1, -0x646C(r2)

	.loc_0x174:
	  addi      r4, r29, 0x54
	  lwz       r4, 0x0(r4)
	  bl        -0x9B10
	  b         .loc_0x1E4
	  lwz       r4, 0x24(r29)
	  lis       r0, 0x4330
	  lfd       f2, -0x6460(r2)
	  addi      r3, r31, 0
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x84(r1)
	  lfs       f0, -0x6470(r2)
	  stw       r0, 0x80(r1)
	  lfd       f1, 0x80(r1)
	  stw       r4, 0x7C(r1)
	  fsubs     f1, f1, f2
	  stw       r0, 0x78(r1)
	  fcmpo     cr0, f1, f0
	  lfd       f0, 0x78(r1)
	  fsubs     f1, f0, f2
	  cror      2, 0, 0x2
	  bne-      .loc_0x1CC
	  lfs       f1, -0x646C(r2)

	.loc_0x1CC:
	  addi      r4, r29, 0x54
	  lwz       r4, 0x0(r4)
	  bl        -0x9494
	  b         .loc_0x1E4
	  lwz       r0, 0x54(r29)
	  stw       r0, 0x3C8(r31)

	.loc_0x1E4:
	  lis       r3, 0x803A
	  lwz       r0, 0x34(r29)
	  subi      r3, r3, 0x2848
	  lwz       r6, 0x44(r29)
	  lfs       f0, 0x2DC(r3)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  fctiwz    f0, f0
	  lwz       r12, 0x28(r12)
	  stfd      f0, 0x78(r1)
	  mtlr      r12
	  lwz       r5, 0x7C(r1)
	  mullw     r0, r5, r0
	  add       r28, r6, r0
	  blrl
	  lwz       r4, 0xC(r30)
	  xoris     r3, r28, 0x8000
	  lwz       r5, 0x10(r30)
	  lis       r0, 0x4330
	  stw       r3, 0x84(r1)
	  mr        r3, r31
	  stw       r4, 0x88(r31)
	  li        r4, 0
	  stw       r5, 0x8C(r31)
	  lwz       r5, 0x14(r30)
	  stw       r0, 0x80(r1)
	  stw       r5, 0x90(r31)
	  lfd       f0, 0x80(r1)
	  lfs       f1, 0x8C(r31)
	  stfs      f1, 0xA0(r31)
	  lwz       r0, 0x24(r30)
	  stw       r0, 0x64(r31)
	  lfd       f1, -0x6460(r2)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x58(r31)
	  lfs       f0, 0x58(r31)
	  stfs      f0, 0x5C(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x24(r30)
	  lwz       r3, 0x28(r3)
	  lwz       r0, 0x34(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x2AC
	  lwz       r0, 0xC8(r31)
	  oris      r0, r0, 0x1
	  stw       r0, 0xC8(r31)

	.loc_0x2AC:
	  lwz       r3, 0x64(r31)
	  addi      r4, r1, 0x64
	  addi      r3, r3, 0x58
	  bl        -0xAA9FC
	  lwz       r3, 0xC(r29)
	  subis     r0, r3, 0x7630
	  cmplwi    r0, 0x2E30
	  beq-      .loc_0x2E8
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x4
	  bne-      .loc_0x2E8
	  addi      r0, r29, 0x5C
	  stw       r0, 0x3D0(r31)
	  addi      r0, r29, 0x7C
	  stw       r0, 0x3D4(r31)

	.loc_0x2E8:
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0xD
	  bne-      .loc_0x310
	  lwz       r0, 0x24(r29)
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  extsh     r0, r0
	  sth       r0, 0x3CA(r31)
	  sth       r0, 0x3C8(r31)
	  bl        -0x5A68C

	.loc_0x310:
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0xF
	  bne-      .loc_0x42C
	  lwz       r30, 0x30AC(r13)
	  li        r27, 0
	  lfs       f31, -0x6468(r2)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x3CC

	.loc_0x344:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x36C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x388

	.loc_0x36C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x388:
	  lwz       r0, 0x6C(r29)
	  addi      r3, r29, 0
	  cmpwi     r0, 0x10
	  bne-      .loc_0x3B0
	  mr        r4, r31
	  bl        -0x6311C
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x3B0
	  fmr       f31, f1
	  mr        r27, r29

	.loc_0x3B0:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x3CC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3F4
	  li        r0, 0x1
	  b         .loc_0x420

	.loc_0x3F4:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x41C
	  li        r0, 0x1
	  b         .loc_0x420

	.loc_0x41C:
	  li        r0, 0

	.loc_0x420:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x344
	  stw       r27, 0x3E0(r31)

	.loc_0x42C:
	  mr        r3, r31

	.loc_0x430:
	  lmw       r27, 0x8C(r1)
	  lwz       r0, 0xAC(r1)
	  lfd       f31, 0xA0(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}
