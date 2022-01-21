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
 * Address:	80078DB0
 * Size:	0001E8
 */
AttentionCamera::AttentionCamera()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x4
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  li        r31, 0
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x24(r1)
	  sth       r31, 0xC(r3)
	  stw       r0, 0x4(r3)
	  stw       r31, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x31DE4
	  stw       r3, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  b         .loc_0x5C

	.loc_0x4C:
	  lwz       r3, 0x0(r30)
	  addi      r5, r5, 0x1
	  stwx      r31, r3, r4
	  addi      r4, r4, 0x4

	.loc_0x5C:
	  lwz       r0, 0x4(r30)
	  cmpw      r5, r0
	  blt+      .loc_0x4C
	  li        r3, 0x10
	  bl        -0x31E18
	  addi      r5, r3, 0
	  mr.       r0, r5
	  beq-      .loc_0xA0
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3418
	  lis       r3, 0x6466
	  stw       r0, 0x4(r5)
	  addi      r0, r3, 0x6C74
	  lis       r3, 0x802B
	  stw       r0, 0x0(r5)
	  subi      r0, r3, 0x3438
	  stw       r0, 0x4(r5)

	.loc_0xA0:
	  lwz       r4, 0x0(r30)
	  li        r3, 0x10
	  stw       r5, 0x0(r4)
	  lwz       r4, 0x8(r30)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r30)
	  bl        -0x31E64
	  addi      r5, r3, 0
	  mr.       r0, r5
	  beq-      .loc_0xEC
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3418
	  lis       r3, 0x736D
	  stw       r0, 0x4(r5)
	  addi      r0, r3, 0x706C
	  lis       r3, 0x802B
	  stw       r0, 0x0(r5)
	  subi      r0, r3, 0x3474
	  stw       r0, 0x4(r5)

	.loc_0xEC:
	  lwz       r4, 0x0(r30)
	  li        r3, 0x24
	  stw       r5, 0x4(r4)
	  lwz       r4, 0x8(r30)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r30)
	  bl        -0x31EB0
	  mr.       r31, r3
	  beq-      .loc_0x1B4
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3418
	  lis       r3, 0x636C
	  stw       r0, 0x4(r31)
	  addi      r0, r3, 0x6F74
	  lis       r3, 0x802B
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x34AC
	  stw       r0, 0x4(r31)
	  li        r3, 0x20
	  li        r0, 0x10
	  sth       r3, 0xE(r31)
	  sth       r0, 0x10(r31)
	  lhz       r3, 0xE(r31)
	  lhz       r0, 0x10(r31)
	  mullw     r0, r3, r0
	  sth       r0, 0xC(r31)
	  lhz       r29, 0xC(r31)
	  mulli     r3, r29, 0x24
	  addi      r3, r3, 0x8
	  bl        -0x31F0C
	  lis       r4, 0x8008
	  subi      r4, r4, 0x6BCC
	  addi      r7, r29, 0
	  li        r5, 0
	  li        r6, 0x24
	  bl        0x19BD00
	  stw       r3, 0x8(r31)
	  lhz       r4, 0xE(r31)
	  lhz       r3, 0x10(r31)
	  subi      r4, r4, 0x1
	  subi      r0, r3, 0x1
	  mullw     r0, r4, r0
	  rlwinm    r0,r0,2,16,29
	  sth       r0, 0x18(r31)
	  lhz       r0, 0x18(r31)
	  rlwinm    r3,r0,3,0,28
	  bl        -0x31F50
	  stw       r3, 0x14(r31)
	  mr        r3, r31
	  bl        .loc_0x1E8

	.loc_0x1B4:
	  lwz       r4, 0x0(r30)
	  mr        r3, r30
	  stw       r31, 0x8(r4)
	  lwz       r4, 0x8(r30)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r30)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0x1E8:
	*/
}

/*
 * --INFO--
 * Address:	80078F98
 * Size:	00049C
 */
void ClothFader::reset()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0x280
	  stw       r0, 0x4(r1)
	  li        r4, 0x1E0
	  li        r11, 0
	  stwu      r1, -0xE0(r1)
	  li        r8, 0
	  stfd      f31, 0xD8(r1)
	  stfd      f30, 0xD0(r1)
	  stfd      f29, 0xC8(r1)
	  stfd      f28, 0xC0(r1)
	  stfd      f27, 0xB8(r1)
	  stfd      f26, 0xB0(r1)
	  stmw      r20, 0x80(r1)
	  mr        r20, r3
	  lhz       r5, 0xE(r3)
	  lhz       r3, 0x10(r3)
	  subi      r5, r5, 0x1
	  lfd       f2, -0x7700(r2)
	  subi      r0, r3, 0x1
	  divw      r9, r6, r5
	  divw      r10, r4, r0
	  lis       r5, 0x4330
	  b         .loc_0x10C

	.loc_0x60:
	  xoris     r6, r8, 0x8000
	  li        r12, 0
	  li        r7, 0
	  b         .loc_0xF8

	.loc_0x70:
	  lhz       r3, 0xE(r20)
	  xoris     r0, r7, 0x8000
	  stw       r6, 0x7C(r1)
	  add       r7, r7, r10
	  mullw     r3, r12, r3
	  stw       r0, 0x74(r1)
	  lwz       r4, 0x8(r20)
	  stw       r5, 0x78(r1)
	  lfd       f0, 0x78(r1)
	  add       r0, r11, r3
	  stw       r5, 0x70(r1)
	  mulli     r0, r0, 0x24
	  fsubs     f1, f0, f2
	  lfd       f0, 0x70(r1)
	  add       r3, r4, r0
	  fsubs     f0, f0, f2
	  stfs      f1, 0x0(r3)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x6464(r13)
	  stfs      f0, 0x8(r3)
	  lhz       r0, 0xE(r20)
	  lwz       r4, 0x8(r20)
	  mullw     r0, r12, r0
	  lfs       f0, -0x6460(r13)
	  add       r0, r11, r0
	  mulli     r3, r0, 0x24
	  addi      r3, r3, 0xC
	  add       r3, r4, r3
	  stfs      f0, 0x0(r3)
	  addi      r12, r12, 0x1
	  lfs       f0, -0x645C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x6458(r13)
	  stfs      f0, 0x8(r3)

	.loc_0xF8:
	  lhz       r0, 0x10(r20)
	  cmpw      r12, r0
	  blt+      .loc_0x70
	  add       r8, r8, r9
	  addi      r11, r11, 0x1

	.loc_0x10C:
	  lhz       r0, 0xE(r20)
	  cmpw      r11, r0
	  blt+      .loc_0x60
	  li        r27, 0
	  addi      r25, r27, 0
	  addi      r23, r27, 0
	  b         .loc_0x358

	.loc_0x128:
	  addi      r24, r23, 0
	  li        r26, 0
	  b         .loc_0x344

	.loc_0x134:
	  lhz       r4, 0xE(r20)
	  addi      r0, r24, 0x2
	  lwz       r3, 0x14(r20)
	  mullw     r4, r26, r4
	  add       r28, r25, r4
	  rlwinm    r29,r28,0,16,31
	  sthx      r28, r3, r24
	  addi      r4, r28, 0x1
	  rlwinm    r30,r4,0,16,31
	  lwz       r3, 0x14(r20)
	  mulli     r21, r28, 0x24
	  sthx      r4, r3, r0
	  mulli     r31, r4, 0x24
	  lwz       r0, 0x8(r20)
	  add       r4, r0, r21
	  add       r3, r0, r31
	  lfs       f2, 0x0(r4)
	  lfs       f3, 0x0(r3)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x4(r4)
	  fsubs     f4, f3, f2
	  lfs       f2, 0x8(r3)
	  fsubs     f3, f1, f0
	  lfs       f0, 0x8(r4)
	  fmuls     f1, f4, f4
	  fsubs     f2, f2, f0
	  fmuls     f0, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x6B504
	  lwz       r4, 0x14(r20)
	  addi      r3, r24, 0x4
	  addi      r0, r27, 0x1
	  stfsx     f1, r4, r3
	  rlwinm    r22,r0,3,0,28
	  addi      r3, r22, 0x2
	  lhz       r0, 0xE(r20)
	  lwz       r4, 0x14(r20)
	  add       r5, r28, r0
	  sthx      r29, r4, r22
	  mulli     r0, r5, 0x24
	  lwz       r4, 0x14(r20)
	  sthx      r5, r4, r3
	  lwz       r3, 0x8(r20)
	  add       r4, r3, r21
	  add       r3, r3, r0
	  lfs       f2, 0x0(r4)
	  lfs       f3, 0x0(r3)
	  lfs       f1, 0x4(r3)
	  fsubs     f4, f3, f2
	  lfs       f0, 0x4(r4)
	  lfs       f2, 0x8(r3)
	  fsubs     f3, f1, f0
	  lfs       f0, 0x8(r4)
	  fsubs     f2, f2, f0
	  fmuls     f1, f4, f4
	  fmuls     f0, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x6B580
	  lwz       r4, 0x14(r20)
	  addi      r3, r22, 0x4
	  addi      r0, r27, 0x2
	  stfsx     f1, r4, r3
	  rlwinm    r22,r0,3,0,28
	  addi      r3, r22, 0x2
	  lhz       r0, 0xE(r20)
	  lwz       r4, 0x14(r20)
	  add       r5, r28, r0
	  sthx      r29, r4, r22
	  addi      r5, r5, 0x1
	  mulli     r0, r5, 0x24
	  lwz       r4, 0x14(r20)
	  sthx      r5, r4, r3
	  lwz       r3, 0x8(r20)
	  add       r4, r3, r21
	  add       r3, r3, r0
	  lfs       f2, 0x0(r4)
	  lfs       f3, 0x0(r3)
	  lfs       f1, 0x4(r3)
	  fsubs     f4, f3, f2
	  lfs       f0, 0x4(r4)
	  lfs       f2, 0x8(r3)
	  fsubs     f3, f1, f0
	  lfs       f0, 0x8(r4)
	  fsubs     f2, f2, f0
	  fmuls     f1, f4, f4
	  fmuls     f0, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x6B600
	  lwz       r4, 0x14(r20)
	  addi      r3, r22, 0x4
	  addi      r0, r27, 0x3
	  stfsx     f1, r4, r3
	  rlwinm    r21,r0,3,0,28
	  addi      r3, r21, 0x2
	  lhz       r0, 0xE(r20)
	  lwz       r4, 0x14(r20)
	  add       r5, r28, r0
	  sthx      r30, r4, r21
	  mulli     r0, r5, 0x24
	  lwz       r4, 0x14(r20)
	  sthx      r5, r4, r3
	  lwz       r3, 0x8(r20)
	  add       r4, r3, r31
	  add       r3, r3, r0
	  lfs       f2, 0x0(r4)
	  lfs       f3, 0x0(r3)
	  lfs       f1, 0x4(r3)
	  fsubs     f4, f3, f2
	  lfs       f0, 0x4(r4)
	  lfs       f2, 0x8(r3)
	  fsubs     f3, f1, f0
	  lfs       f0, 0x8(r4)
	  fsubs     f2, f2, f0
	  fmuls     f1, f4, f4
	  fmuls     f0, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x6B67C
	  lwz       r3, 0x14(r20)
	  addi      r0, r21, 0x4
	  addi      r23, r23, 0x20
	  stfsx     f1, r3, r0
	  addi      r27, r27, 0x4
	  addi      r26, r26, 0x1
	  addi      r24, r24, 0x20

	.loc_0x344:
	  lhz       r3, 0x10(r20)
	  subi      r0, r3, 0x1
	  cmpw      r26, r0
	  blt+      .loc_0x134
	  addi      r25, r25, 0x1

	.loc_0x358:
	  lhz       r3, 0xE(r20)
	  subi      r0, r3, 0x1
	  cmpw      r25, r0
	  blt+      .loc_0x128
	  lfd       f27, -0x7700(r2)
	  li        r22, 0
	  lfs       f28, -0x770C(r2)
	  lis       r21, 0x4330
	  lfs       f29, -0x7710(r2)
	  lfs       f30, -0x7708(r2)
	  lfs       f31, -0x7704(r2)
	  b         .loc_0x464

	.loc_0x388:
	  li        r23, 0
	  b         .loc_0x454

	.loc_0x390:
	  cmpwi     r22, 0
	  beq-      .loc_0x450
	  cmpwi     r23, 0
	  beq-      .loc_0x450
	  lhz       r3, 0xE(r20)
	  subi      r0, r3, 0x1
	  cmpw      r22, r0
	  beq-      .loc_0x450
	  subi      r0, r4, 0x1
	  cmpw      r23, r0
	  beq-      .loc_0x450
	  bl        0x19ED1C
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x74(r1)
	  stw       r21, 0x70(r1)
	  lfd       f0, 0x70(r1)
	  fsubs     f0, f0, f27
	  fdivs     f0, f0, f28
	  fmuls     f26, f29, f0
	  bl        0x19ECFC
	  xoris     r3, r3, 0x8000
	  lhz       r0, 0xE(r20)
	  stw       r3, 0x7C(r1)
	  fsubs     f2, f26, f30
	  mullw     r0, r23, r0
	  lfs       f3, -0x6454(r13)
	  stw       r21, 0x78(r1)
	  lwz       r3, 0x8(r20)
	  lfd       f0, 0x78(r1)
	  fsubs     f0, f0, f27
	  add       r0, r22, r0
	  mulli     r0, r0, 0x24
	  fmuls     f2, f2, f31
	  fmuls     f3, f3, f31
	  fdivs     f1, f0, f28
	  add       r3, r3, r0
	  lfs       f0, 0x0(r3)
	  fmuls     f1, f29, f1
	  fsubs     f1, f1, f30
	  fmuls     f1, f1, f31
	  fadds     f0, f0, f1
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f0, f2
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f0, f3
	  stfs      f0, 0x8(r3)

	.loc_0x450:
	  addi      r23, r23, 0x1

	.loc_0x454:
	  lhz       r4, 0x10(r20)
	  cmpw      r23, r4
	  blt+      .loc_0x390
	  addi      r22, r22, 0x1

	.loc_0x464:
	  lhz       r0, 0xE(r20)
	  cmpw      r22, r0
	  blt+      .loc_0x388
	  lmw       r20, 0x80(r1)
	  lwz       r0, 0xE4(r1)
	  lfd       f31, 0xD8(r1)
	  lfd       f30, 0xD0(r1)
	  lfd       f29, 0xC8(r1)
	  lfd       f28, 0xC0(r1)
	  lfd       f27, 0xB8(r1)
	  lfd       f26, 0xB0(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80079434
 * Size:	00002C
 */
ClothFader::Particle::Particle()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x76F8(r2)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0xC(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  stfs      f0, 0x18(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void AttentionCamera::start(unsigned long, Creature*, float, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80079460
 * Size:	000004
 */
void AttentionCamera::Fader::initFadeOut() { }

/*
 * --INFO--
 * Address:	80079464
 * Size:	000050
 */
void AttentionCamera::finish()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x3120(r13)
	  bl        0x9DF48
	  stw       r3, 0x10(r31)
	  li        r0, 0x1
	  sth       r0, 0xC(r31)
	  lwz       r3, 0x14(r31)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800794B4
 * Size:	0000F0
 */
void AttentionCamera::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lhz       r0, 0xC(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xB8
	  bge-      .loc_0xDC
	  cmpwi     r0, 0x1
	  bge-      .loc_0x30
	  b         .loc_0xDC

	.loc_0x30:
	  lwz       r3, 0x14(r31)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDC
	  lwz       r3, 0x10(r31)
	  lfs       f1, -0x76E0(r2)
	  lfs       f2, -0x76DC(r2)
	  addi      r3, r3, 0x94
	  bl        0x99A00
	  bl        -0x40F8C
	  lwz       r3, 0x10(r31)
	  stfs      f1, 0xA0(r3)
	  lwz       r4, 0x10(r31)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x36
	  beq-      .loc_0x8C
	  lwz       r3, 0x30D8(r13)
	  lwz       r3, 0x20(r3)
	  bl        0xA8808
	  b         .loc_0x98

	.loc_0x8C:
	  lwz       r3, 0x30D8(r13)
	  lwz       r3, 0x20(r3)
	  bl        0xA87F8

	.loc_0x98:
	  li        r0, 0x2
	  sth       r0, 0xC(r31)
	  lwz       r3, 0x14(r31)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xDC

	.loc_0xB8:
	  lwz       r3, 0x14(r31)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDC
	  li        r0, 0
	  sth       r0, 0xC(r31)

	.loc_0xDC:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800795A4
 * Size:	000008
 */
u32 AttentionCamera::Fader::updateFadeIn() { return 0x1; }

/*
 * --INFO--
 * Address:	800795AC
 * Size:	000004
 */
void AttentionCamera::Fader::initFadeIn() { }

/*
 * --INFO--
 * Address:	800795B0
 * Size:	000008
 */
u32 AttentionCamera::Fader::updateFadeOut() { return 0x1; }

/*
 * --INFO--
 * Address:	800795B8
 * Size:	00005C
 */
void AttentionCamera::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lhz       r0, 0xC(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x30
	  lwz       r3, 0x14(r3)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4C

	.loc_0x30:
	  cmplwi    r0, 0x2
	  bne-      .loc_0x4C
	  lwz       r3, 0x14(r3)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x4C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80079614
 * Size:	000004
 */
void AttentionCamera::Fader::drawFadeIn(Graphics&) { }

/*
 * --INFO--
 * Address:	80079618
 * Size:	000004
 */
void AttentionCamera::Fader::drawFadeOut(Graphics&) { }

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void AttentionCamera::setFader(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void NoiseFunction::init(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void NoiseFunction::getValue(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000EC
 */
void TurbulenceFun::init(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000240
 */
void TurbulenceFun::getValue(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8007961C
 * Size:	000288
 */
void ClothFader::initFadeIn()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r7, 0x280
	  stw       r0, 0x4(r1)
	  li        r9, 0
	  li        r4, 0x1E0
	  stwu      r1, -0x88(r1)
	  addi      r0, r9, 0
	  lis       r5, 0x4330
	  stfd      f31, 0x80(r1)
	  stfd      f30, 0x78(r1)
	  stfd      f29, 0x70(r1)
	  stfd      f28, 0x68(r1)
	  stfd      f27, 0x60(r1)
	  stfd      f26, 0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  stw       r28, 0x48(r1)
	  lfs       f0, -0x76D8(r2)
	  stfs      f0, 0x1C(r3)
	  lfs       f0, 0x1C(r3)
	  stfs      f0, 0x20(r3)
	  lhz       r6, 0xE(r3)
	  lhz       r3, 0x10(r3)
	  subi      r6, r6, 0x1
	  lfd       f2, -0x7700(r2)
	  subi      r3, r3, 0x1
	  divw      r11, r7, r6
	  divw      r10, r4, r3
	  b         .loc_0x128

	.loc_0x7C:
	  li        r8, 0
	  addi      r12, r8, 0
	  xoris     r6, r0, 0x8000
	  b         .loc_0x114

	.loc_0x8C:
	  lhz       r4, 0xE(r31)
	  xoris     r3, r12, 0x8000
	  stw       r6, 0x44(r1)
	  add       r12, r12, r10
	  mullw     r4, r8, r4
	  stw       r3, 0x3C(r1)
	  lwz       r7, 0x8(r31)
	  stw       r5, 0x40(r1)
	  lfd       f0, 0x40(r1)
	  add       r3, r9, r4
	  stw       r5, 0x38(r1)
	  mulli     r3, r3, 0x24
	  fsubs     f1, f0, f2
	  lfd       f0, 0x38(r1)
	  add       r3, r7, r3
	  fsubs     f0, f0, f2
	  stfs      f1, 0x0(r3)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x6464(r13)
	  stfs      f0, 0x8(r3)
	  lhz       r3, 0xE(r31)
	  lwz       r4, 0x8(r31)
	  mullw     r3, r8, r3
	  lfs       f0, -0x6460(r13)
	  add       r3, r9, r3
	  mulli     r3, r3, 0x24
	  addi      r3, r3, 0xC
	  add       r3, r4, r3
	  stfs      f0, 0x0(r3)
	  addi      r8, r8, 0x1
	  lfs       f0, -0x645C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x6458(r13)
	  stfs      f0, 0x8(r3)

	.loc_0x114:
	  lhz       r3, 0x10(r31)
	  cmpw      r8, r3
	  blt+      .loc_0x8C
	  add       r0, r0, r11
	  addi      r9, r9, 0x1

	.loc_0x128:
	  lhz       r3, 0xE(r31)
	  cmpw      r9, r3
	  blt+      .loc_0x7C
	  mr        r3, r31
	  bl        .loc_0x288
	  lfd       f27, -0x7700(r2)
	  li        r29, 0
	  lfs       f28, -0x770C(r2)
	  lis       r30, 0x4330
	  lfs       f29, -0x7710(r2)
	  lfs       f30, -0x7708(r2)
	  lfs       f31, -0x7704(r2)
	  b         .loc_0x238

	.loc_0x15C:
	  li        r28, 0
	  b         .loc_0x228

	.loc_0x164:
	  cmpwi     r29, 0
	  beq-      .loc_0x224
	  cmpwi     r28, 0
	  beq-      .loc_0x224
	  lhz       r3, 0xE(r31)
	  subi      r0, r3, 0x1
	  cmpw      r29, r0
	  beq-      .loc_0x224
	  subi      r0, r4, 0x1
	  cmpw      r28, r0
	  beq-      .loc_0x224
	  bl        0x19E8C4
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  lfd       f0, 0x38(r1)
	  fsubs     f0, f0, f27
	  fdivs     f0, f0, f28
	  fmuls     f26, f29, f0
	  bl        0x19E8A4
	  xoris     r3, r3, 0x8000
	  lhz       r0, 0xE(r31)
	  stw       r3, 0x44(r1)
	  fsubs     f2, f26, f30
	  mullw     r0, r28, r0
	  lfs       f3, -0x6454(r13)
	  stw       r30, 0x40(r1)
	  lwz       r3, 0x8(r31)
	  lfd       f0, 0x40(r1)
	  fsubs     f0, f0, f27
	  add       r0, r29, r0
	  mulli     r0, r0, 0x24
	  fmuls     f2, f2, f31
	  fmuls     f3, f3, f31
	  fdivs     f1, f0, f28
	  add       r3, r3, r0
	  lfs       f0, 0x0(r3)
	  fmuls     f1, f29, f1
	  fsubs     f1, f1, f30
	  fmuls     f1, f1, f31
	  fadds     f0, f0, f1
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f0, f2
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f0, f3
	  stfs      f0, 0x8(r3)

	.loc_0x224:
	  addi      r28, r28, 0x1

	.loc_0x228:
	  lhz       r4, 0x10(r31)
	  cmpw      r28, r4
	  blt+      .loc_0x164
	  addi      r29, r29, 0x1

	.loc_0x238:
	  lhz       r0, 0xE(r31)
	  cmpw      r29, r0
	  blt+      .loc_0x15C
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0
	  stw       r0, 0x28(r3)
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lfd       f30, 0x78(r1)
	  lfd       f29, 0x70(r1)
	  lfd       f28, 0x68(r1)
	  lfd       f27, 0x60(r1)
	  lfd       f26, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  lwz       r28, 0x48(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr

	.loc_0x288:
	*/
}

/*
 * --INFO--
 * Address:	800798A4
 * Size:	0003C8
 */
void ClothFader::makeSprings()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x50(r1)
	  li        r8, 0
	  li        r6, 0
	  stw       r31, 0x4C(r1)
	  li        r5, 0
	  stw       r30, 0x48(r1)
	  lfs       f2, -0x76F8(r2)
	  lfd       f1, -0x76F0(r2)
	  lfd       f0, -0x76E8(r2)
	  b         .loc_0x3A8

	.loc_0x28:
	  addi      r4, r5, 0
	  li        r7, 0
	  b         .loc_0x394

	.loc_0x34:
	  lhz       r0, 0xE(r3)
	  addi      r10, r4, 0x2
	  lwz       r11, 0x14(r3)
	  mullw     r0, r7, r0
	  add       r9, r6, r0
	  sthx      r9, r11, r4
	  addi      r12, r9, 0x1
	  mulli     r0, r9, 0x24
	  lwz       r11, 0x14(r3)
	  sthx      r12, r11, r10
	  mulli     r10, r12, 0x24
	  lwz       r12, 0x8(r3)
	  add       r11, r12, r0
	  add       r10, r12, r10
	  lfs       f5, 0x4(r11)
	  lfs       f6, 0x4(r10)
	  lfs       f4, 0x0(r10)
	  lfs       f3, 0x0(r11)
	  fsubs     f6, f6, f5
	  lfs       f5, 0x8(r10)
	  fsubs     f7, f4, f3
	  lfs       f4, 0x8(r11)
	  fmuls     f3, f6, f6
	  fsubs     f5, f5, f4
	  fmuls     f4, f7, f7
	  fmuls     f5, f5, f5
	  fadds     f3, f4, f3
	  fadds     f5, f5, f3
	  fcmpo     cr0, f5, f2
	  ble-      .loc_0xFC
	  fsqrte    f4, f5
	  fmul      f3, f4, f4
	  fmul      f4, f1, f4
	  fmul      f3, f5, f3
	  fsub      f3, f0, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f1, f4
	  fmul      f3, f5, f3
	  fsub      f3, f0, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f1, f4
	  fmul      f3, f5, f3
	  fsub      f3, f0, f3
	  fmul      f3, f4, f3
	  fmul      f3, f5, f3
	  frsp      f3, f3
	  stfs      f3, 0x34(r1)
	  lfs       f5, 0x34(r1)

	.loc_0xFC:
	  lwz       r12, 0x14(r3)
	  addi      r11, r4, 0x4
	  addi      r10, r8, 0x1
	  stfsx     f5, r12, r11
	  rlwinm    r31,r10,3,0,28
	  addi      r11, r31, 0x2
	  lhz       r12, 0xE(r3)
	  lwz       r10, 0x14(r3)
	  add       r30, r9, r12
	  sthx      r9, r10, r31
	  mulli     r10, r30, 0x24
	  lwz       r12, 0x14(r3)
	  sthx      r30, r12, r11
	  lwz       r12, 0x8(r3)
	  add       r11, r12, r0
	  add       r10, r12, r10
	  lfs       f5, 0x4(r11)
	  lfs       f6, 0x4(r10)
	  lfs       f4, 0x0(r10)
	  lfs       f3, 0x0(r11)
	  fsubs     f6, f6, f5
	  lfs       f5, 0x8(r10)
	  fsubs     f7, f4, f3
	  lfs       f4, 0x8(r11)
	  fmuls     f3, f6, f6
	  fsubs     f5, f5, f4
	  fmuls     f4, f7, f7
	  fmuls     f5, f5, f5
	  fadds     f3, f4, f3
	  fadds     f5, f5, f3
	  fcmpo     cr0, f5, f2
	  ble-      .loc_0x1CC
	  fsqrte    f4, f5
	  fmul      f3, f4, f4
	  fmul      f4, f1, f4
	  fmul      f3, f5, f3
	  fsub      f3, f0, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f1, f4
	  fmul      f3, f5, f3
	  fsub      f3, f0, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f1, f4
	  fmul      f3, f5, f3
	  fsub      f3, f0, f3
	  fmul      f3, f4, f3
	  fmul      f3, f5, f3
	  frsp      f3, f3
	  stfs      f3, 0x30(r1)
	  lfs       f5, 0x30(r1)

	.loc_0x1CC:
	  lwz       r12, 0x14(r3)
	  addi      r11, r31, 0x4
	  addi      r10, r8, 0x2
	  stfsx     f5, r12, r11
	  rlwinm    r31,r10,3,0,28
	  addi      r11, r31, 0x2
	  lhz       r12, 0xE(r3)
	  lwz       r10, 0x14(r3)
	  add       r30, r9, r12
	  sthx      r9, r10, r31
	  addi      r30, r30, 0x1
	  mulli     r10, r30, 0x24
	  lwz       r12, 0x14(r3)
	  sthx      r30, r12, r11
	  lwz       r12, 0x8(r3)
	  add       r11, r12, r0
	  add       r10, r12, r10
	  lfs       f5, 0x4(r11)
	  lfs       f6, 0x4(r10)
	  lfs       f4, 0x0(r10)
	  lfs       f3, 0x0(r11)
	  fsubs     f6, f6, f5
	  lfs       f5, 0x8(r10)
	  fsubs     f7, f4, f3
	  lfs       f4, 0x8(r11)
	  fmuls     f3, f6, f6
	  fsubs     f5, f5, f4
	  fmuls     f4, f7, f7
	  fmuls     f5, f5, f5
	  fadds     f3, f4, f3
	  fadds     f5, f5, f3
	  fcmpo     cr0, f5, f2
	  ble-      .loc_0x2A0
	  fsqrte    f4, f5
	  fmul      f3, f4, f4
	  fmul      f4, f1, f4
	  fmul      f3, f5, f3
	  fsub      f3, f0, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f1, f4
	  fmul      f3, f5, f3
	  fsub      f3, f0, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f1, f4
	  fmul      f3, f5, f3
	  fsub      f3, f0, f3
	  fmul      f3, f4, f3
	  fmul      f3, f5, f3
	  frsp      f3, f3
	  stfs      f3, 0x2C(r1)
	  lfs       f5, 0x2C(r1)

	.loc_0x2A0:
	  lwz       r10, 0x14(r3)
	  addi      r0, r31, 0x4
	  addi      r30, r9, 0x1
	  stfsx     f5, r10, r0
	  addi      r0, r8, 0x3
	  rlwinm    r12,r0,3,0,28
	  lhz       r11, 0xE(r3)
	  addi      r0, r12, 0x2
	  lwz       r10, 0x14(r3)
	  add       r11, r9, r11
	  sthx      r30, r10, r12
	  mulli     r9, r30, 0x24
	  lwz       r10, 0x14(r3)
	  sthx      r11, r10, r0
	  mulli     r0, r11, 0x24
	  lwz       r11, 0x8(r3)
	  add       r10, r11, r9
	  add       r9, r11, r0
	  lfs       f5, 0x4(r10)
	  lfs       f6, 0x4(r9)
	  lfs       f4, 0x0(r9)
	  lfs       f3, 0x0(r10)
	  fsubs     f6, f6, f5
	  lfs       f5, 0x8(r9)
	  fsubs     f7, f4, f3
	  lfs       f4, 0x8(r10)
	  fmuls     f3, f6, f6
	  fsubs     f5, f5, f4
	  fmuls     f4, f7, f7
	  fmuls     f5, f5, f5
	  fadds     f3, f4, f3
	  fadds     f5, f5, f3
	  fcmpo     cr0, f5, f2
	  ble-      .loc_0x378
	  fsqrte    f4, f5
	  fmul      f3, f4, f4
	  fmul      f4, f1, f4
	  fmul      f3, f5, f3
	  fsub      f3, f0, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f1, f4
	  fmul      f3, f5, f3
	  fsub      f3, f0, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f1, f4
	  fmul      f3, f5, f3
	  fsub      f3, f0, f3
	  fmul      f3, f4, f3
	  fmul      f3, f5, f3
	  frsp      f3, f3
	  stfs      f3, 0x28(r1)
	  lfs       f5, 0x28(r1)

	.loc_0x378:
	  lwz       r9, 0x14(r3)
	  addi      r0, r12, 0x4
	  addi      r5, r5, 0x20
	  stfsx     f5, r9, r0
	  addi      r8, r8, 0x4
	  addi      r7, r7, 0x1
	  addi      r4, r4, 0x20

	.loc_0x394:
	  lhz       r9, 0x10(r3)
	  subi      r0, r9, 0x1
	  cmpw      r7, r0
	  blt+      .loc_0x34
	  addi      r6, r6, 0x1

	.loc_0x3A8:
	  lhz       r4, 0xE(r3)
	  subi      r0, r4, 0x1
	  cmpw      r6, r0
	  blt+      .loc_0x28
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80079C6C
 * Size:	000288
 */
void ClothFader::initFadeOut()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r7, 0x280
	  stw       r0, 0x4(r1)
	  li        r9, 0
	  li        r4, 0x1E0
	  stwu      r1, -0x88(r1)
	  addi      r0, r9, 0
	  lis       r5, 0x4330
	  stfd      f31, 0x80(r1)
	  stfd      f30, 0x78(r1)
	  stfd      f29, 0x70(r1)
	  stfd      f28, 0x68(r1)
	  stfd      f27, 0x60(r1)
	  stfd      f26, 0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  stw       r28, 0x48(r1)
	  lfs       f0, -0x76D8(r2)
	  stfs      f0, 0x1C(r3)
	  lfs       f0, 0x1C(r3)
	  stfs      f0, 0x20(r3)
	  lhz       r6, 0xE(r3)
	  lhz       r3, 0x10(r3)
	  subi      r6, r6, 0x1
	  lfd       f2, -0x7700(r2)
	  subi      r3, r3, 0x1
	  divw      r11, r7, r6
	  divw      r10, r4, r3
	  b         .loc_0x128

	.loc_0x7C:
	  li        r8, 0
	  addi      r12, r8, 0
	  xoris     r6, r0, 0x8000
	  b         .loc_0x114

	.loc_0x8C:
	  lhz       r4, 0xE(r31)
	  xoris     r3, r12, 0x8000
	  stw       r6, 0x44(r1)
	  add       r12, r12, r10
	  mullw     r4, r8, r4
	  stw       r3, 0x3C(r1)
	  lwz       r7, 0x8(r31)
	  stw       r5, 0x40(r1)
	  lfd       f0, 0x40(r1)
	  add       r3, r9, r4
	  stw       r5, 0x38(r1)
	  mulli     r3, r3, 0x24
	  fsubs     f1, f0, f2
	  lfd       f0, 0x38(r1)
	  add       r3, r7, r3
	  fsubs     f0, f0, f2
	  stfs      f1, 0x0(r3)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x6464(r13)
	  stfs      f0, 0x8(r3)
	  lhz       r3, 0xE(r31)
	  lwz       r4, 0x8(r31)
	  mullw     r3, r8, r3
	  lfs       f0, -0x6460(r13)
	  add       r3, r9, r3
	  mulli     r3, r3, 0x24
	  addi      r3, r3, 0xC
	  add       r3, r4, r3
	  stfs      f0, 0x0(r3)
	  addi      r8, r8, 0x1
	  lfs       f0, -0x645C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x6458(r13)
	  stfs      f0, 0x8(r3)

	.loc_0x114:
	  lhz       r3, 0x10(r31)
	  cmpw      r8, r3
	  blt+      .loc_0x8C
	  add       r0, r0, r11
	  addi      r9, r9, 0x1

	.loc_0x128:
	  lhz       r3, 0xE(r31)
	  cmpw      r9, r3
	  blt+      .loc_0x7C
	  mr        r3, r31
	  bl        -0x500
	  lfd       f27, -0x7700(r2)
	  li        r29, 0
	  lfs       f28, -0x770C(r2)
	  lis       r30, 0x4330
	  lfs       f29, -0x7710(r2)
	  lfs       f30, -0x7708(r2)
	  lfs       f31, -0x7704(r2)
	  b         .loc_0x238

	.loc_0x15C:
	  li        r28, 0
	  b         .loc_0x228

	.loc_0x164:
	  cmpwi     r29, 0
	  beq-      .loc_0x224
	  cmpwi     r28, 0
	  beq-      .loc_0x224
	  lhz       r3, 0xE(r31)
	  subi      r0, r3, 0x1
	  cmpw      r29, r0
	  beq-      .loc_0x224
	  subi      r0, r4, 0x1
	  cmpw      r28, r0
	  beq-      .loc_0x224
	  bl        0x19E274
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  lfd       f0, 0x38(r1)
	  fsubs     f0, f0, f27
	  fdivs     f0, f0, f28
	  fmuls     f26, f29, f0
	  bl        0x19E254
	  xoris     r3, r3, 0x8000
	  lhz       r0, 0xE(r31)
	  stw       r3, 0x44(r1)
	  fsubs     f2, f26, f30
	  mullw     r0, r28, r0
	  lfs       f3, -0x6454(r13)
	  stw       r30, 0x40(r1)
	  lwz       r3, 0x8(r31)
	  lfd       f0, 0x40(r1)
	  fsubs     f0, f0, f27
	  add       r0, r29, r0
	  mulli     r0, r0, 0x24
	  fmuls     f2, f2, f31
	  fmuls     f3, f3, f31
	  fdivs     f1, f0, f28
	  add       r3, r3, r0
	  lfs       f0, 0x0(r3)
	  fmuls     f1, f29, f1
	  fsubs     f1, f1, f30
	  fmuls     f1, f1, f31
	  fadds     f0, f0, f1
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f0, f2
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f0, f3
	  stfs      f0, 0x8(r3)

	.loc_0x224:
	  addi      r28, r28, 0x1

	.loc_0x228:
	  lhz       r4, 0x10(r31)
	  cmpw      r28, r4
	  blt+      .loc_0x164
	  addi      r29, r29, 0x1

	.loc_0x238:
	  lhz       r0, 0xE(r31)
	  cmpw      r29, r0
	  blt+      .loc_0x15C
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0
	  stw       r0, 0x28(r3)
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lfd       f30, 0x78(r1)
	  lfd       f29, 0x70(r1)
	  lfd       f28, 0x68(r1)
	  lfd       f27, 0x60(r1)
	  lfd       f26, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  lwz       r28, 0x48(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80079EF4
 * Size:	000410
 */
void ClothFader::updateFadeIn()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F8(r1)
	  stfd      f31, 0x1F0(r1)
	  stfd      f30, 0x1E8(r1)
	  stfd      f29, 0x1E0(r1)
	  stfd      f28, 0x1D8(r1)
	  stfd      f27, 0x1D0(r1)
	  stfd      f26, 0x1C8(r1)
	  stfd      f25, 0x1C0(r1)
	  stmw      r17, 0x184(r1)
	  mr        r17, r3
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x20(r3)
	  lfs       f0, 0x28C(r4)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x20(r3)
	  lfs       f1, 0x20(r3)
	  lfs       f0, -0x76F8(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x70
	  stfs      f0, 0x20(r17)
	  li        r0, 0x1
	  li        r3, 0x1
	  lwz       r4, 0x2DEC(r13)
	  stw       r0, 0x28(r4)
	  b         .loc_0x3E0

	.loc_0x70:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0
	  addi      r5, r4, 0
	  lfs       f28, 0x28C(r3)
	  b         .loc_0xB0

	.loc_0x84:
	  lwz       r0, 0x8(r17)
	  addi      r3, r5, 0x18
	  lfs       f0, -0x6470(r13)
	  addi      r5, r5, 0x24
	  add       r3, r0, r3
	  stfs      f0, 0x0(r3)
	  addi      r4, r4, 0x1
	  lfs       f0, -0x646C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x6468(r13)
	  stfs      f0, 0x8(r3)

	.loc_0xB0:
	  lhz       r0, 0xC(r17)
	  cmpw      r4, r0
	  blt+      .loc_0x84
	  li        r18, 0
	  lfs       f30, -0x76F8(r2)
	  lfs       f31, -0x76D4(r2)
	  addi      r19, r18, 0
	  addi      r28, r1, 0xA4
	  addi      r27, r1, 0xA0
	  addi      r26, r1, 0x9C
	  addi      r25, r1, 0x8C
	  addi      r24, r1, 0x88
	  addi      r23, r1, 0x84
	  addi      r22, r1, 0x80
	  addi      r21, r1, 0x7C
	  addi      r20, r1, 0x78
	  b         .loc_0x2B0

	.loc_0xF4:
	  lwz       r0, 0x14(r17)
	  mr        r4, r26
	  lwz       r8, 0x8(r17)
	  addi      r5, r27, 0
	  add       r29, r0, r19
	  lhz       r7, 0x0(r29)
	  mr        r6, r28
	  lhz       r0, 0x2(r29)
	  addi      r3, r1, 0x110
	  mulli     r7, r7, 0x24
	  mulli     r0, r0, 0x24
	  add       r30, r8, r7
	  add       r31, r8, r0
	  lfs       f1, 0x8(r30)
	  lfs       f0, 0x8(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA4(r1)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x4(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA0(r1)
	  lfs       f1, 0x0(r30)
	  lfs       f0, 0x0(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x9C(r1)
	  bl        -0x42F30
	  lfs       f27, 0x110(r1)
	  lfs       f26, 0x114(r1)
	  fmuls     f1, f27, f27
	  lfs       f25, 0x118(r1)
	  fmuls     f0, f26, f26
	  fmuls     f2, f25, f25
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x6C430
	  fmr       f29, f1
	  fcmpu     cr0, f30, f29
	  beq-      .loc_0x198
	  fdivs     f27, f27, f29
	  fdivs     f26, f26, f29
	  fdivs     f25, f25, f29

	.loc_0x198:
	  lfs       f0, 0x4(r29)
	  addi      r4, r23, 0
	  addi      r5, r24, 0
	  fsubs     f0, f29, f0
	  addi      r6, r25, 0
	  addi      r3, r1, 0x128
	  fmuls     f0, f31, f0
	  fmuls     f2, f25, f0
	  fmuls     f1, f26, f0
	  fmuls     f0, f27, f0
	  stfs      f2, 0x8C(r1)
	  stfs      f1, 0x88(r1)
	  stfs      f0, 0x84(r1)
	  bl        -0x42FA4
	  lfs       f0, 0x128(r1)
	  mr        r4, r20
	  lfs       f2, 0x18(r30)
	  mr        r5, r21
	  lfs       f1, 0x12C(r1)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x130(r1)
	  addi      r6, r22, 0
	  addi      r3, r1, 0x140
	  stfs      f2, 0xD8(r1)
	  lfs       f2, 0xD8(r1)
	  stfs      f2, 0x11C(r1)
	  lfs       f2, 0x1C(r30)
	  fsubs     f1, f2, f1
	  stfs      f1, 0x120(r1)
	  lfs       f1, 0x20(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x124(r1)
	  lwz       r7, 0x11C(r1)
	  lwz       r0, 0x120(r1)
	  stw       r7, 0x18(r30)
	  stw       r0, 0x1C(r30)
	  lwz       r0, 0x124(r1)
	  stw       r0, 0x20(r30)
	  lfs       f0, 0x4(r29)
	  fsubs     f0, f29, f0
	  fmuls     f0, f31, f0
	  fmuls     f2, f25, f0
	  fmuls     f1, f26, f0
	  fmuls     f0, f27, f0
	  stfs      f2, 0x80(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f0, 0x78(r1)
	  bl        -0x4302C
	  lfs       f0, 0x140(r1)
	  addi      r19, r19, 0x8
	  lfs       f2, 0x18(r31)
	  addi      r18, r18, 0x1
	  lfs       f1, 0x144(r1)
	  fadds     f2, f2, f0
	  lfs       f0, 0x148(r1)
	  stfs      f2, 0xCC(r1)
	  lfs       f2, 0xCC(r1)
	  stfs      f2, 0x134(r1)
	  lfs       f2, 0x1C(r31)
	  fadds     f1, f2, f1
	  stfs      f1, 0x138(r1)
	  lfs       f1, 0x20(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x13C(r1)
	  lwz       r3, 0x134(r1)
	  lwz       r0, 0x138(r1)
	  stw       r3, 0x18(r31)
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0x13C(r1)
	  stw       r0, 0x20(r31)

	.loc_0x2B0:
	  lhz       r0, 0x18(r17)
	  cmpw      r18, r0
	  blt+      .loc_0xF4
	  li        r8, 0
	  addi      r7, r8, 0
	  b         .loc_0x3D0

	.loc_0x2C8:
	  lwz       r0, 0x8(r17)
	  addi      r8, r8, 0x1
	  add       r4, r0, r7
	  lfs       f0, 0xC(r4)
	  addi      r7, r7, 0x24
	  lfs       f2, 0x14(r4)
	  fmuls     f0, f0, f28
	  lfs       f1, 0x10(r4)
	  fmuls     f2, f2, f28
	  fmuls     f1, f1, f28
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0xC8(r1)
	  stfs      f0, 0x158(r1)
	  stfs      f1, 0x15C(r1)
	  stfs      f2, 0x160(r1)
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0x158(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xBC(r1)
	  stfs      f0, 0x14C(r1)
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x15C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x150(r1)
	  lfs       f1, 0x8(r4)
	  lfs       f0, 0x160(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x154(r1)
	  lwz       r3, 0x14C(r1)
	  lwz       r0, 0x150(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x154(r1)
	  stw       r0, 0x8(r4)
	  lfs       f0, 0x18(r4)
	  lfs       f2, 0x20(r4)
	  lfs       f1, 0x1C(r4)
	  fmuls     f0, f0, f28
	  fmuls     f2, f2, f28
	  fmuls     f1, f1, f28
	  stfs      f0, 0xB4(r1)
	  lfs       f0, 0xB4(r1)
	  stfs      f0, 0x170(r1)
	  stfs      f1, 0x174(r1)
	  stfs      f2, 0x178(r1)
	  lfs       f1, 0xC(r4)
	  lfs       f0, 0x170(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f0, 0xA8(r1)
	  stfs      f0, 0x164(r1)
	  lfs       f1, 0x10(r4)
	  lfs       f0, 0x174(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x168(r1)
	  lfs       f1, 0x14(r4)
	  lfs       f0, 0x178(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x16C(r1)
	  lwz       r3, 0x164(r1)
	  lwz       r0, 0x168(r1)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0x16C(r1)
	  stw       r0, 0x14(r4)

	.loc_0x3D0:
	  lhz       r0, 0xC(r17)
	  cmpw      r8, r0
	  blt+      .loc_0x2C8
	  li        r3, 0

	.loc_0x3E0:
	  lmw       r17, 0x184(r1)
	  lwz       r0, 0x1FC(r1)
	  lfd       f31, 0x1F0(r1)
	  lfd       f30, 0x1E8(r1)
	  lfd       f29, 0x1E0(r1)
	  lfd       f28, 0x1D8(r1)
	  lfd       f27, 0x1D0(r1)
	  lfd       f26, 0x1C8(r1)
	  lfd       f25, 0x1C0(r1)
	  addi      r1, r1, 0x1F8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007A304
 * Size:	000410
 */
void ClothFader::updateFadeOut()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F8(r1)
	  stfd      f31, 0x1F0(r1)
	  stfd      f30, 0x1E8(r1)
	  stfd      f29, 0x1E0(r1)
	  stfd      f28, 0x1D8(r1)
	  stfd      f27, 0x1D0(r1)
	  stfd      f26, 0x1C8(r1)
	  stfd      f25, 0x1C0(r1)
	  stmw      r17, 0x184(r1)
	  mr        r17, r3
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x20(r3)
	  lfs       f0, 0x28C(r4)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x20(r3)
	  lfs       f1, 0x20(r3)
	  lfs       f0, -0x76F8(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x70
	  stfs      f0, 0x20(r17)
	  li        r0, 0x1
	  li        r3, 0x1
	  lwz       r4, 0x2DEC(r13)
	  stw       r0, 0x28(r4)
	  b         .loc_0x3E0

	.loc_0x70:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0
	  addi      r5, r4, 0
	  lfs       f28, 0x28C(r3)
	  b         .loc_0xB0

	.loc_0x84:
	  lwz       r0, 0x8(r17)
	  addi      r3, r5, 0x18
	  lfs       f0, -0x6470(r13)
	  addi      r5, r5, 0x24
	  add       r3, r0, r3
	  stfs      f0, 0x0(r3)
	  addi      r4, r4, 0x1
	  lfs       f0, -0x646C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x6468(r13)
	  stfs      f0, 0x8(r3)

	.loc_0xB0:
	  lhz       r0, 0xC(r17)
	  cmpw      r4, r0
	  blt+      .loc_0x84
	  li        r18, 0
	  lfs       f30, -0x76F8(r2)
	  lfs       f31, -0x76D4(r2)
	  addi      r19, r18, 0
	  addi      r28, r1, 0xA4
	  addi      r27, r1, 0xA0
	  addi      r26, r1, 0x9C
	  addi      r25, r1, 0x8C
	  addi      r24, r1, 0x88
	  addi      r23, r1, 0x84
	  addi      r22, r1, 0x80
	  addi      r21, r1, 0x7C
	  addi      r20, r1, 0x78
	  b         .loc_0x2B0

	.loc_0xF4:
	  lwz       r0, 0x14(r17)
	  mr        r4, r26
	  lwz       r8, 0x8(r17)
	  addi      r5, r27, 0
	  add       r29, r0, r19
	  lhz       r7, 0x0(r29)
	  mr        r6, r28
	  lhz       r0, 0x2(r29)
	  addi      r3, r1, 0x110
	  mulli     r7, r7, 0x24
	  mulli     r0, r0, 0x24
	  add       r30, r8, r7
	  add       r31, r8, r0
	  lfs       f1, 0x8(r30)
	  lfs       f0, 0x8(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA4(r1)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x4(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA0(r1)
	  lfs       f1, 0x0(r30)
	  lfs       f0, 0x0(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x9C(r1)
	  bl        -0x43340
	  lfs       f27, 0x110(r1)
	  lfs       f26, 0x114(r1)
	  fmuls     f1, f27, f27
	  lfs       f25, 0x118(r1)
	  fmuls     f0, f26, f26
	  fmuls     f2, f25, f25
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x6C840
	  fmr       f29, f1
	  fcmpu     cr0, f30, f29
	  beq-      .loc_0x198
	  fdivs     f27, f27, f29
	  fdivs     f26, f26, f29
	  fdivs     f25, f25, f29

	.loc_0x198:
	  lfs       f0, 0x4(r29)
	  addi      r4, r23, 0
	  addi      r5, r24, 0
	  fsubs     f0, f29, f0
	  addi      r6, r25, 0
	  addi      r3, r1, 0x128
	  fmuls     f0, f31, f0
	  fmuls     f2, f25, f0
	  fmuls     f1, f26, f0
	  fmuls     f0, f27, f0
	  stfs      f2, 0x8C(r1)
	  stfs      f1, 0x88(r1)
	  stfs      f0, 0x84(r1)
	  bl        -0x433B4
	  lfs       f0, 0x128(r1)
	  mr        r4, r20
	  lfs       f2, 0x18(r30)
	  mr        r5, r21
	  lfs       f1, 0x12C(r1)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x130(r1)
	  addi      r6, r22, 0
	  addi      r3, r1, 0x140
	  stfs      f2, 0xD8(r1)
	  lfs       f2, 0xD8(r1)
	  stfs      f2, 0x11C(r1)
	  lfs       f2, 0x1C(r30)
	  fsubs     f1, f2, f1
	  stfs      f1, 0x120(r1)
	  lfs       f1, 0x20(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x124(r1)
	  lwz       r7, 0x11C(r1)
	  lwz       r0, 0x120(r1)
	  stw       r7, 0x18(r30)
	  stw       r0, 0x1C(r30)
	  lwz       r0, 0x124(r1)
	  stw       r0, 0x20(r30)
	  lfs       f0, 0x4(r29)
	  fsubs     f0, f29, f0
	  fmuls     f0, f31, f0
	  fmuls     f2, f25, f0
	  fmuls     f1, f26, f0
	  fmuls     f0, f27, f0
	  stfs      f2, 0x80(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f0, 0x78(r1)
	  bl        -0x4343C
	  lfs       f0, 0x140(r1)
	  addi      r19, r19, 0x8
	  lfs       f2, 0x18(r31)
	  addi      r18, r18, 0x1
	  lfs       f1, 0x144(r1)
	  fadds     f2, f2, f0
	  lfs       f0, 0x148(r1)
	  stfs      f2, 0xCC(r1)
	  lfs       f2, 0xCC(r1)
	  stfs      f2, 0x134(r1)
	  lfs       f2, 0x1C(r31)
	  fadds     f1, f2, f1
	  stfs      f1, 0x138(r1)
	  lfs       f1, 0x20(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x13C(r1)
	  lwz       r3, 0x134(r1)
	  lwz       r0, 0x138(r1)
	  stw       r3, 0x18(r31)
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0x13C(r1)
	  stw       r0, 0x20(r31)

	.loc_0x2B0:
	  lhz       r0, 0x18(r17)
	  cmpw      r18, r0
	  blt+      .loc_0xF4
	  li        r8, 0
	  addi      r7, r8, 0
	  b         .loc_0x3D0

	.loc_0x2C8:
	  lwz       r0, 0x8(r17)
	  addi      r8, r8, 0x1
	  add       r4, r0, r7
	  lfs       f0, 0xC(r4)
	  addi      r7, r7, 0x24
	  lfs       f2, 0x14(r4)
	  fmuls     f0, f0, f28
	  lfs       f1, 0x10(r4)
	  fmuls     f2, f2, f28
	  fmuls     f1, f1, f28
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0xC8(r1)
	  stfs      f0, 0x158(r1)
	  stfs      f1, 0x15C(r1)
	  stfs      f2, 0x160(r1)
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0x158(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xBC(r1)
	  stfs      f0, 0x14C(r1)
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x15C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x150(r1)
	  lfs       f1, 0x8(r4)
	  lfs       f0, 0x160(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x154(r1)
	  lwz       r3, 0x14C(r1)
	  lwz       r0, 0x150(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x154(r1)
	  stw       r0, 0x8(r4)
	  lfs       f0, 0x18(r4)
	  lfs       f2, 0x20(r4)
	  lfs       f1, 0x1C(r4)
	  fmuls     f0, f0, f28
	  fmuls     f2, f2, f28
	  fmuls     f1, f1, f28
	  stfs      f0, 0xB4(r1)
	  lfs       f0, 0xB4(r1)
	  stfs      f0, 0x170(r1)
	  stfs      f1, 0x174(r1)
	  stfs      f2, 0x178(r1)
	  lfs       f1, 0xC(r4)
	  lfs       f0, 0x170(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f0, 0xA8(r1)
	  stfs      f0, 0x164(r1)
	  lfs       f1, 0x10(r4)
	  lfs       f0, 0x174(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x168(r1)
	  lfs       f1, 0x14(r4)
	  lfs       f0, 0x178(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x16C(r1)
	  lwz       r3, 0x164(r1)
	  lwz       r0, 0x168(r1)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0x16C(r1)
	  stw       r0, 0x14(r4)

	.loc_0x3D0:
	  lhz       r0, 0xC(r17)
	  cmpw      r8, r0
	  blt+      .loc_0x2C8
	  li        r3, 0

	.loc_0x3E0:
	  lmw       r17, 0x184(r1)
	  lwz       r0, 0x1FC(r1)
	  lfd       f31, 0x1F0(r1)
	  lfd       f30, 0x1E8(r1)
	  lfd       f29, 0x1E0(r1)
	  lfd       f28, 0x1D8(r1)
	  lfd       f27, 0x1D0(r1)
	  lfd       f26, 0x1C8(r1)
	  lfd       f25, 0x1C0(r1)
	  addi      r1, r1, 0x1F8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007A714
 * Size:	000338
 */
void ClothFader::drawFadeOut(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x168(r1)
	  stfd      f31, 0x160(r1)
	  stfd      f30, 0x158(r1)
	  stfd      f29, 0x150(r1)
	  stfd      f28, 0x148(r1)
	  stfd      f27, 0x140(r1)
	  stfd      f26, 0x138(r1)
	  stfd      f25, 0x130(r1)
	  stfd      f24, 0x128(r1)
	  stfd      f23, 0x120(r1)
	  stfd      f22, 0x118(r1)
	  stfd      f21, 0x110(r1)
	  stfd      f20, 0x108(r1)
	  stfd      f19, 0x100(r1)
	  stfd      f18, 0xF8(r1)
	  stfd      f17, 0xF0(r1)
	  stfd      f16, 0xE8(r1)
	  stfd      f15, 0xE0(r1)
	  stfd      f14, 0xD8(r1)
	  stmw      r26, 0xC0(r1)
	  addi      r27, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x3B4(r3)
	  lwz       r5, 0x2F00(r13)
	  lwz       r12, 0xCC(r12)
	  lwz       r4, 0x4B8(r5)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  bl        0x19546C
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x194C64
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x194C58
	  li        r3, 0xD
	  li        r4, 0x1
	  bl        0x194C4C
	  li        r3, 0
	  li        r4, 0x9
	  li        r5, 0x1
	  li        r6, 0x4
	  li        r7, 0
	  bl        0x19547C
	  li        r3, 0
	  li        r4, 0xB
	  li        r5, 0x1
	  li        r6, 0x5
	  li        r7, 0
	  bl        0x195464
	  li        r3, 0
	  li        r4, 0xD
	  li        r5, 0x1
	  li        r6, 0x4
	  li        r7, 0
	  bl        0x19544C
	  li        r3, 0
	  li        r4, 0
	  bl        0x198794
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0
	  bl        0x199430
	  li        r0, 0xFF
	  lfd       f29, -0x7700(r2)
	  stb       r0, 0x70(r1)
	  li        r6, 0x280
	  li        r4, 0x1E0
	  lfs       f2, -0x76D0(r2)
	  stb       r0, 0x71(r1)
	  lis       r31, 0x4330
	  lfs       f0, -0x76CC(r2)
	  stb       r0, 0x72(r1)
	  li        r29, 0
	  lis       r26, 0xCC01
	  stb       r0, 0x73(r1)
	  lhz       r5, 0xE(r27)
	  lhz       r3, 0x10(r27)
	  subi      r5, r5, 0x1
	  lwz       r28, 0x70(r1)
	  subi      r0, r3, 0x1
	  divw      r3, r6, r5
	  divw      r0, r4, r0
	  xoris     r3, r3, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r3, 0xBC(r1)
	  stw       r0, 0xB4(r1)
	  stw       r31, 0xB8(r1)
	  stw       r31, 0xB0(r1)
	  lfd       f3, 0xB8(r1)
	  lfd       f1, 0xB0(r1)
	  fsubs     f3, f3, f29
	  fsubs     f1, f1, f29
	  fdivs     f26, f3, f2
	  fdivs     f27, f1, f0
	  b         .loc_0x2CC

	.loc_0x190:
	  xoris     r0, r29, 0x8000
	  stw       r0, 0xB4(r1)
	  li        r30, 0
	  stw       r31, 0xB0(r1)
	  lfd       f0, 0xB0(r1)
	  fsubs     f0, f0, f29
	  fmuls     f31, f26, f0
	  fadds     f30, f31, f26
	  b         .loc_0x2B8

	.loc_0x1B4:
	  lhz       r7, 0xE(r27)
	  addi      r3, r30, 0x1
	  xoris     r0, r30, 0x8000
	  lwz       r6, 0x8(r27)
	  mullw     r4, r30, r7
	  stw       r0, 0xB4(r1)
	  stw       r31, 0xB0(r1)
	  add       r5, r29, r4
	  lfd       f0, 0xB0(r1)
	  mullw     r0, r3, r7
	  fsubs     f0, f0, f29
	  fmuls     f28, f27, f0
	  add       r3, r29, r0
	  addi      r4, r5, 0x1
	  addi      r0, r3, 0x1
	  mulli     r5, r5, 0x24
	  add       r5, r6, r5
	  mulli     r4, r4, 0x24
	  lfs       f25, 0x0(r5)
	  lfs       f24, 0x4(r5)
	  lfs       f23, 0x8(r5)
	  add       r4, r6, r4
	  mulli     r3, r3, 0x24
	  lfs       f22, 0x0(r4)
	  lfs       f21, 0x4(r4)
	  lfs       f20, 0x8(r4)
	  add       r3, r6, r3
	  mulli     r0, r0, 0x24
	  lfs       f19, 0x0(r3)
	  lfs       f18, 0x4(r3)
	  lfs       f17, 0x8(r3)
	  add       r5, r6, r0
	  lfs       f16, 0x0(r5)
	  li        r3, 0x80
	  lfs       f15, 0x4(r5)
	  li        r4, 0
	  lfs       f14, 0x8(r5)
	  li        r5, 0x4
	  bl        0x196274
	  stfs      f25, -0x8000(r26)
	  fadds     f0, f28, f27
	  addi      r30, r30, 0x1
	  stfs      f24, -0x8000(r26)
	  stfs      f23, -0x8000(r26)
	  stw       r28, -0x8000(r26)
	  stfs      f31, -0x8000(r26)
	  stfs      f28, -0x8000(r26)
	  stfs      f22, -0x8000(r26)
	  stfs      f21, -0x8000(r26)
	  stfs      f20, -0x8000(r26)
	  stw       r28, -0x8000(r26)
	  stfs      f30, -0x8000(r26)
	  stfs      f28, -0x8000(r26)
	  stfs      f16, -0x8000(r26)
	  stfs      f15, -0x8000(r26)
	  stfs      f14, -0x8000(r26)
	  stw       r28, -0x8000(r26)
	  stfs      f30, -0x8000(r26)
	  stfs      f0, -0x8000(r26)
	  stfs      f19, -0x8000(r26)
	  stfs      f18, -0x8000(r26)
	  stfs      f17, -0x8000(r26)
	  stw       r28, -0x8000(r26)
	  stfs      f31, -0x8000(r26)
	  stfs      f0, -0x8000(r26)

	.loc_0x2B8:
	  lhz       r3, 0x10(r27)
	  subi      r0, r3, 0x1
	  cmpw      r30, r0
	  blt+      .loc_0x1B4
	  addi      r29, r29, 0x1

	.loc_0x2CC:
	  lhz       r3, 0xE(r27)
	  subi      r0, r3, 0x1
	  cmpw      r29, r0
	  blt+      .loc_0x190
	  lmw       r26, 0xC0(r1)
	  lwz       r0, 0x16C(r1)
	  lfd       f31, 0x160(r1)
	  lfd       f30, 0x158(r1)
	  lfd       f29, 0x150(r1)
	  lfd       f28, 0x148(r1)
	  lfd       f27, 0x140(r1)
	  lfd       f26, 0x138(r1)
	  lfd       f25, 0x130(r1)
	  lfd       f24, 0x128(r1)
	  lfd       f23, 0x120(r1)
	  lfd       f22, 0x118(r1)
	  lfd       f21, 0x110(r1)
	  lfd       f20, 0x108(r1)
	  lfd       f19, 0x100(r1)
	  lfd       f18, 0xF8(r1)
	  lfd       f17, 0xF0(r1)
	  lfd       f16, 0xE8(r1)
	  lfd       f15, 0xE0(r1)
	  lfd       f14, 0xD8(r1)
	  addi      r1, r1, 0x168
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007AA4C
 * Size:	000338
 */
void ClothFader::drawFadeIn(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x168(r1)
	  stfd      f31, 0x160(r1)
	  stfd      f30, 0x158(r1)
	  stfd      f29, 0x150(r1)
	  stfd      f28, 0x148(r1)
	  stfd      f27, 0x140(r1)
	  stfd      f26, 0x138(r1)
	  stfd      f25, 0x130(r1)
	  stfd      f24, 0x128(r1)
	  stfd      f23, 0x120(r1)
	  stfd      f22, 0x118(r1)
	  stfd      f21, 0x110(r1)
	  stfd      f20, 0x108(r1)
	  stfd      f19, 0x100(r1)
	  stfd      f18, 0xF8(r1)
	  stfd      f17, 0xF0(r1)
	  stfd      f16, 0xE8(r1)
	  stfd      f15, 0xE0(r1)
	  stfd      f14, 0xD8(r1)
	  stmw      r26, 0xC0(r1)
	  addi      r27, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x3B4(r3)
	  lwz       r5, 0x2F00(r13)
	  lwz       r12, 0xCC(r12)
	  lwz       r4, 0x4B8(r5)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  bl        0x195134
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x19492C
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x194920
	  li        r3, 0xD
	  li        r4, 0x1
	  bl        0x194914
	  li        r3, 0
	  li        r4, 0x9
	  li        r5, 0x1
	  li        r6, 0x4
	  li        r7, 0
	  bl        0x195144
	  li        r3, 0
	  li        r4, 0xB
	  li        r5, 0x1
	  li        r6, 0x5
	  li        r7, 0
	  bl        0x19512C
	  li        r3, 0
	  li        r4, 0xD
	  li        r5, 0x1
	  li        r6, 0x4
	  li        r7, 0
	  bl        0x195114
	  li        r3, 0
	  li        r4, 0
	  bl        0x19845C
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0
	  bl        0x1990F8
	  li        r0, 0xFF
	  lfd       f29, -0x7700(r2)
	  stb       r0, 0x70(r1)
	  li        r6, 0x280
	  li        r4, 0x1E0
	  lfs       f2, -0x76D0(r2)
	  stb       r0, 0x71(r1)
	  lis       r31, 0x4330
	  lfs       f0, -0x76CC(r2)
	  stb       r0, 0x72(r1)
	  li        r29, 0
	  lis       r26, 0xCC01
	  stb       r0, 0x73(r1)
	  lhz       r5, 0xE(r27)
	  lhz       r3, 0x10(r27)
	  subi      r5, r5, 0x1
	  lwz       r28, 0x70(r1)
	  subi      r0, r3, 0x1
	  divw      r3, r6, r5
	  divw      r0, r4, r0
	  xoris     r3, r3, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r3, 0xBC(r1)
	  stw       r0, 0xB4(r1)
	  stw       r31, 0xB8(r1)
	  stw       r31, 0xB0(r1)
	  lfd       f3, 0xB8(r1)
	  lfd       f1, 0xB0(r1)
	  fsubs     f3, f3, f29
	  fsubs     f1, f1, f29
	  fdivs     f26, f3, f2
	  fdivs     f27, f1, f0
	  b         .loc_0x2CC

	.loc_0x190:
	  xoris     r0, r29, 0x8000
	  stw       r0, 0xB4(r1)
	  li        r30, 0
	  stw       r31, 0xB0(r1)
	  lfd       f0, 0xB0(r1)
	  fsubs     f0, f0, f29
	  fmuls     f31, f26, f0
	  fadds     f30, f31, f26
	  b         .loc_0x2B8

	.loc_0x1B4:
	  lhz       r7, 0xE(r27)
	  addi      r3, r30, 0x1
	  xoris     r0, r30, 0x8000
	  lwz       r6, 0x8(r27)
	  mullw     r4, r30, r7
	  stw       r0, 0xB4(r1)
	  stw       r31, 0xB0(r1)
	  add       r5, r29, r4
	  lfd       f0, 0xB0(r1)
	  mullw     r0, r3, r7
	  fsubs     f0, f0, f29
	  fmuls     f28, f27, f0
	  add       r3, r29, r0
	  addi      r4, r5, 0x1
	  addi      r0, r3, 0x1
	  mulli     r5, r5, 0x24
	  add       r5, r6, r5
	  mulli     r4, r4, 0x24
	  lfs       f25, 0x0(r5)
	  lfs       f24, 0x4(r5)
	  lfs       f23, 0x8(r5)
	  add       r4, r6, r4
	  mulli     r3, r3, 0x24
	  lfs       f22, 0x0(r4)
	  lfs       f21, 0x4(r4)
	  lfs       f20, 0x8(r4)
	  add       r3, r6, r3
	  mulli     r0, r0, 0x24
	  lfs       f19, 0x0(r3)
	  lfs       f18, 0x4(r3)
	  lfs       f17, 0x8(r3)
	  add       r5, r6, r0
	  lfs       f16, 0x0(r5)
	  li        r3, 0x80
	  lfs       f15, 0x4(r5)
	  li        r4, 0
	  lfs       f14, 0x8(r5)
	  li        r5, 0x4
	  bl        0x195F3C
	  stfs      f25, -0x8000(r26)
	  fadds     f0, f28, f27
	  addi      r30, r30, 0x1
	  stfs      f24, -0x8000(r26)
	  stfs      f23, -0x8000(r26)
	  stw       r28, -0x8000(r26)
	  stfs      f31, -0x8000(r26)
	  stfs      f28, -0x8000(r26)
	  stfs      f22, -0x8000(r26)
	  stfs      f21, -0x8000(r26)
	  stfs      f20, -0x8000(r26)
	  stw       r28, -0x8000(r26)
	  stfs      f30, -0x8000(r26)
	  stfs      f28, -0x8000(r26)
	  stfs      f16, -0x8000(r26)
	  stfs      f15, -0x8000(r26)
	  stfs      f14, -0x8000(r26)
	  stw       r28, -0x8000(r26)
	  stfs      f30, -0x8000(r26)
	  stfs      f0, -0x8000(r26)
	  stfs      f19, -0x8000(r26)
	  stfs      f18, -0x8000(r26)
	  stfs      f17, -0x8000(r26)
	  stw       r28, -0x8000(r26)
	  stfs      f31, -0x8000(r26)
	  stfs      f0, -0x8000(r26)

	.loc_0x2B8:
	  lhz       r3, 0x10(r27)
	  subi      r0, r3, 0x1
	  cmpw      r30, r0
	  blt+      .loc_0x1B4
	  addi      r29, r29, 0x1

	.loc_0x2CC:
	  lhz       r3, 0xE(r27)
	  subi      r0, r3, 0x1
	  cmpw      r29, r0
	  blt+      .loc_0x190
	  lmw       r26, 0xC0(r1)
	  lwz       r0, 0x16C(r1)
	  lfd       f31, 0x160(r1)
	  lfd       f30, 0x158(r1)
	  lfd       f29, 0x150(r1)
	  lfd       f28, 0x148(r1)
	  lfd       f27, 0x140(r1)
	  lfd       f26, 0x138(r1)
	  lfd       f25, 0x130(r1)
	  lfd       f24, 0x128(r1)
	  lfd       f23, 0x120(r1)
	  lfd       f22, 0x118(r1)
	  lfd       f21, 0x110(r1)
	  lfd       f20, 0x108(r1)
	  lfd       f19, 0x100(r1)
	  lfd       f18, 0xF8(r1)
	  lfd       f17, 0xF0(r1)
	  lfd       f16, 0xE8(r1)
	  lfd       f15, 0xE0(r1)
	  lfd       f14, 0xD8(r1)
	  addi      r1, r1, 0x168
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007AD84
 * Size:	000014
 */
void SimpleFader::initFadeIn()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x76C8(r2)
	  stfs      f0, 0xC(r3)
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007AD98
 * Size:	000014
 */
void SimpleFader::initFadeOut()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x76C8(r2)
	  stfs      f0, 0xC(r3)
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007ADAC
 * Size:	00003C
 */
void SimpleFader::updateFadeIn()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x28C(r4)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x8(r3)
	  lfs       f1, 0x8(r3)
	  lfs       f0, -0x76F8(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x34
	  stfs      f0, 0x8(r3)
	  li        r3, 0x1
	  blr

	.loc_0x34:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007ADE8
 * Size:	00003C
 */
void SimpleFader::updateFadeOut()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x28C(r4)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x8(r3)
	  lfs       f1, 0x8(r3)
	  lfs       f0, -0x76F8(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x34
	  stfs      f0, 0x8(r3)
	  li        r3, 0x1
	  blr

	.loc_0x34:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007AE24
 * Size:	000188
 */
void SimpleFader::drawFadeOut(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  li        r30, 0xFF
	  stw       r29, 0x54(r1)
	  addi      r29, r4, 0
	  addi      r4, r1, 0x24
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0xC(r3)
	  mr        r3, r29
	  lfs       f2, -0x76C4(r2)
	  fdivs     f0, f1, f0
	  lfs       f1, -0x7710(r2)
	  stb       r30, 0x24(r1)
	  stb       r30, 0x25(r1)
	  stb       r30, 0x26(r1)
	  fsubs     f0, f1, f0
	  fmuls     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  stb       r0, 0x27(r1)
	  rlwinm    r31,r0,0,24,31
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0x20(r1)
	  addi      r4, r1, 0x20
	  addi      r3, r29, 0
	  stb       r30, 0x21(r1)
	  stb       r30, 0x22(r1)
	  stb       r31, 0x23(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r4, 0x2F00(r13)
	  lwz       r12, 0x3B4(r29)
	  li        r5, 0
	  lwz       r4, 0x4B8(r4)
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0
	  bl        0x198D58
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x4
	  bl        0x1988BC
	  li        r3, 0
	  li        r4, 0xF
	  li        r5, 0xF
	  li        r6, 0xF
	  li        r7, 0x8
	  bl        0x198220
	  li        r3, 0
	  li        r4, 0x7
	  li        r5, 0x7
	  li        r6, 0x7
	  li        r7, 0x5
	  bl        0x198288
	  li        r4, 0
	  stw       r4, 0x28(r1)
	  li        r6, 0x280
	  li        r7, 0x140
	  stw       r4, 0x10(r1)
	  li        r8, 0x1E0
	  li        r0, 0xF0
	  stw       r4, 0x2C(r1)
	  addi      r5, r1, 0x10
	  addi      r3, r29, 0
	  stw       r4, 0x14(r1)
	  addi      r4, r1, 0x28
	  stw       r6, 0x30(r1)
	  li        r6, 0
	  stw       r7, 0x18(r1)
	  stw       r8, 0x34(r1)
	  stw       r0, 0x1C(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
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
 * Address:	8007AFAC
 * Size:	000180
 */
void SimpleFader::drawFadeIn(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  li        r30, 0xFF
	  stw       r29, 0x54(r1)
	  addi      r29, r4, 0
	  addi      r4, r1, 0x24
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0xC(r3)
	  mr        r3, r29
	  fdivs     f0, f1, f0
	  lfs       f1, -0x76C4(r2)
	  stb       r30, 0x24(r1)
	  stb       r30, 0x25(r1)
	  stb       r30, 0x26(r1)
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  stb       r0, 0x27(r1)
	  rlwinm    r31,r0,0,24,31
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0x20(r1)
	  addi      r4, r1, 0x20
	  addi      r3, r29, 0
	  stb       r30, 0x21(r1)
	  stb       r30, 0x22(r1)
	  stb       r31, 0x23(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r4, 0x2F00(r13)
	  lwz       r12, 0x3B4(r29)
	  li        r5, 0
	  lwz       r4, 0x4B8(r4)
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0
	  bl        0x198BD8
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x4
	  bl        0x19873C
	  li        r3, 0
	  li        r4, 0xF
	  li        r5, 0xF
	  li        r6, 0xF
	  li        r7, 0x8
	  bl        0x1980A0
	  li        r3, 0
	  li        r4, 0x7
	  li        r5, 0x7
	  li        r6, 0x7
	  li        r7, 0x5
	  bl        0x198108
	  li        r4, 0
	  stw       r4, 0x28(r1)
	  li        r6, 0x280
	  li        r7, 0x140
	  stw       r4, 0x10(r1)
	  li        r8, 0x1E0
	  li        r0, 0xF0
	  stw       r4, 0x2C(r1)
	  addi      r5, r1, 0x10
	  addi      r3, r29, 0
	  stw       r4, 0x14(r1)
	  addi      r4, r1, 0x28
	  stw       r6, 0x30(r1)
	  li        r6, 0
	  stw       r7, 0x18(r1)
	  stw       r8, 0x34(r1)
	  stw       r0, 0x1C(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
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
 * Address:	8007B12C
 * Size:	000014
 */
void DefaultFader::initFadeIn()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x76C8(r2)
	  stfs      f0, 0xC(r3)
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007B140
 * Size:	00003C
 */
void DefaultFader::updateFadeIn()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x28C(r4)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x8(r3)
	  lfs       f1, 0x8(r3)
	  lfs       f0, -0x76F8(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x34
	  stfs      f0, 0x8(r3)
	  li        r3, 0x1
	  blr

	.loc_0x34:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007B17C
 * Size:	0001D0
 */
void DefaultFader::drawFadeOut(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  li        r0, 0x1E0
	  stwu      r1, -0x78(r1)
	  stmw      r27, 0x64(r1)
	  addi      r27, r4, 0
	  li        r30, 0
	  li        r31, 0xFF
	  addi      r4, r1, 0x2C
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0xC(r3)
	  li        r3, 0x280
	  lfs       f2, -0x7710(r2)
	  fdivs     f0, f1, f0
	  stw       r30, 0x40(r1)
	  lfs       f1, -0x76C0(r2)
	  stb       r30, 0x2C(r1)
	  stw       r30, 0x44(r1)
	  fsubs     f2, f2, f0
	  lfs       f0, -0x76BC(r2)
	  stw       r3, 0x48(r1)
	  mr        r3, r27
	  stb       r30, 0x2D(r1)
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f2
	  stb       r30, 0x2E(r1)
	  fctiwz    f1, f1
	  stw       r0, 0x4C(r1)
	  fctiwz    f0, f0
	  stb       r31, 0x2F(r1)
	  lwz       r12, 0x3B4(r27)
	  stfd      f1, 0x58(r1)
	  lwz       r12, 0xA8(r12)
	  stfd      f0, 0x50(r1)
	  lwz       r29, 0x5C(r1)
	  mtlr      r12
	  lwz       r28, 0x54(r1)
	  blrl
	  stb       r30, 0x28(r1)
	  addi      r4, r1, 0x28
	  addi      r3, r27, 0
	  stb       r30, 0x29(r1)
	  stb       r30, 0x2A(r1)
	  stb       r31, 0x2B(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  addi      r4, r1, 0x40
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl
	  stb       r31, 0x24(r1)
	  addi      r4, r1, 0x24
	  addi      r3, r27, 0
	  stb       r31, 0x25(r1)
	  li        r5, 0x1
	  stb       r31, 0x26(r1)
	  stb       r31, 0x27(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r31, 0x20(r1)
	  addi      r4, r1, 0x20
	  addi      r3, r27, 0
	  stb       r31, 0x21(r1)
	  stb       r31, 0x22(r1)
	  stb       r31, 0x23(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r4, 0x2F00(r13)
	  lwz       r12, 0x3B4(r27)
	  li        r5, 0
	  lwz       r4, 0x4B8(r4)
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  stw       r29, 0x30(r1)
	  subfic    r6, r29, 0x280
	  li        r7, 0x140
	  stw       r30, 0x10(r1)
	  subfic    r8, r28, 0x1E0
	  li        r0, 0xF0
	  stw       r28, 0x34(r1)
	  addi      r5, r1, 0x10
	  addi      r3, r27, 0
	  stw       r6, 0x38(r1)
	  addi      r4, r1, 0x30
	  li        r6, 0
	  stw       r30, 0x14(r1)
	  stw       r7, 0x18(r1)
	  stw       r8, 0x3C(r1)
	  stw       r0, 0x1C(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
	  lmw       r27, 0x64(r1)
	  lwz       r0, 0x7C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007B34C
 * Size:	000014
 */
void DefaultFader::initFadeOut()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x76C8(r2)
	  stfs      f0, 0xC(r3)
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007B360
 * Size:	00003C
 */
void DefaultFader::updateFadeOut()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x28C(r4)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x8(r3)
	  lfs       f1, 0x8(r3)
	  lfs       f0, -0x76F8(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x34
	  stfs      f0, 0x8(r3)
	  li        r3, 0x1
	  blr

	.loc_0x34:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007B39C
 * Size:	0001C8
 */
void DefaultFader::drawFadeIn(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  li        r0, 0x1E0
	  stwu      r1, -0x78(r1)
	  stmw      r27, 0x64(r1)
	  addi      r27, r4, 0
	  li        r30, 0
	  li        r31, 0xFF
	  addi      r4, r1, 0x2C
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0xC(r3)
	  li        r3, 0x280
	  fdivs     f2, f1, f0
	  stw       r30, 0x40(r1)
	  lfs       f0, -0x76C0(r2)
	  stb       r30, 0x2C(r1)
	  stw       r30, 0x44(r1)
	  fmuls     f1, f0, f2
	  stw       r3, 0x48(r1)
	  lfs       f0, -0x76BC(r2)
	  mr        r3, r27
	  stb       r30, 0x2D(r1)
	  fmuls     f0, f0, f2
	  stb       r30, 0x2E(r1)
	  fctiwz    f1, f1
	  stw       r0, 0x4C(r1)
	  fctiwz    f0, f0
	  stb       r31, 0x2F(r1)
	  lwz       r12, 0x3B4(r27)
	  stfd      f1, 0x58(r1)
	  lwz       r12, 0xA8(r12)
	  stfd      f0, 0x50(r1)
	  lwz       r29, 0x5C(r1)
	  mtlr      r12
	  lwz       r28, 0x54(r1)
	  blrl
	  stb       r30, 0x28(r1)
	  addi      r4, r1, 0x28
	  addi      r3, r27, 0
	  stb       r30, 0x29(r1)
	  stb       r30, 0x2A(r1)
	  stb       r31, 0x2B(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  addi      r4, r1, 0x40
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl
	  stb       r31, 0x24(r1)
	  addi      r4, r1, 0x24
	  addi      r3, r27, 0
	  stb       r31, 0x25(r1)
	  li        r5, 0x1
	  stb       r31, 0x26(r1)
	  stb       r31, 0x27(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r31, 0x20(r1)
	  addi      r4, r1, 0x20
	  addi      r3, r27, 0
	  stb       r31, 0x21(r1)
	  stb       r31, 0x22(r1)
	  stb       r31, 0x23(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r4, 0x2F00(r13)
	  lwz       r12, 0x3B4(r27)
	  li        r5, 0
	  lwz       r4, 0x4B8(r4)
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  stw       r29, 0x30(r1)
	  subfic    r6, r29, 0x280
	  li        r7, 0x140
	  stw       r30, 0x10(r1)
	  subfic    r8, r28, 0x1E0
	  li        r0, 0xF0
	  stw       r28, 0x34(r1)
	  addi      r5, r1, 0x10
	  addi      r3, r27, 0
	  stw       r6, 0x38(r1)
	  addi      r4, r1, 0x30
	  li        r6, 0
	  stw       r30, 0x14(r1)
	  stw       r7, 0x18(r1)
	  stw       r8, 0x3C(r1)
	  stw       r0, 0x1C(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
	  lmw       r27, 0x64(r1)
	  lwz       r0, 0x7C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}
