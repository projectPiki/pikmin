#include "TitlesSection.h"
#include "Interface.h"
#include "Delegate.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	8005F804
 * Size:	00008C
 */
void TitleSetupSection::menuSelectOption(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  lis       r3, 0x803A
	  lwz       r4, 0x30(r4)
	  subi      r5, r3, 0x2848
	  li        r3, 0xD
	  lwz       r4, 0x1C(r4)
	  stw       r4, 0x24(r30)
	  li        r4, 0
	  stw       r0, 0x2B4(r5)
	  bl        -0x45B64
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x1
	  stw       r0, 0x20(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, -0x7930(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x792C(r2)
	  stfs      f0, 0xC(r3)
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
 * Address:	8005F890
 * Size:	000038
 */
void TitlesMovieInterface::message(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x18
	  b         .loc_0x28

	.loc_0x18:
	  lwz       r3, 0x2EC8(r13)
	  bl        0x1391D4
	  li        r0, 0x1
	  stb       r0, 0x2ECC(r13)

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005F8C8
 * Size:	00087C
 */
void TitlesSection::init()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stfd      f31, 0xC0(r1)
	  stfd      f30, 0xB8(r1)
	  stfd      f29, 0xB0(r1)
	  stfd      f28, 0xA8(r1)
	  stfd      f27, 0xA0(r1)
	  stfd      f26, 0x98(r1)
	  stfd      f25, 0x90(r1)
	  stmw      r23, 0x6C(r1)
	  subi      r30, r4, 0x76E0
	  addi      r28, r3, 0
	  addi      r4, r30, 0x24
	  bl        -0x1F1C8
	  bl        -0x484E8
	  lwz       r4, 0x2DEC(r13)
	  li        r7, 0
	  lis       r3, 0x803A
	  stw       r7, 0x18(r4)
	  subi      r23, r3, 0x2848
	  addi      r24, r23, 0x24
	  lwz       r3, 0x2DEC(r13)
	  li        r6, 0x1
	  addi      r0, r30, 0x34
	  stw       r6, 0x14(r3)
	  addi      r3, r24, 0
	  li        r4, 0x1
	  lwz       r5, 0x2DEC(r13)
	  stw       r0, 0x50(r5)
	  stw       r7, 0x310(r23)
	  lfs       f0, -0x7928(r2)
	  stfs      f0, 0x314(r23)
	  stb       r6, 0xB2(r23)
	  bl        0x1459C
	  cmpwi     r3, 0
	  bne-      .loc_0xAC
	  lwz       r0, 0x5C(r23)
	  cmpwi     r0, 0
	  blt-      .loc_0xAC
	  mr        r3, r24
	  bl        0x14980

	.loc_0xAC:
	  lis       r3, 0x803A
	  subi      r23, r3, 0x2848
	  addi      r29, r23, 0x94
	  addi      r3, r29, 0
	  bl        -0xB420
	  lwz       r0, 0x2D4(r23)
	  cmpwi     r0, 0
	  beq-      .loc_0xD4
	  li        r6, 0
	  b         .loc_0xD8

	.loc_0xD4:
	  li        r6, 0x3C

	.loc_0xD8:
	  lwz       r3, 0x2DEC(r13)
	  lis       r4, 0x803A
	  subi      r23, r4, 0x2848
	  lwz       r12, 0x1A0(r3)
	  addi      r4, r23, 0x31C
	  li        r5, 0x1
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xAC(r23)
	  addi      r3, r23, 0x2A8
	  lwz       r4, 0x2A8(r23)
	  rlwinm.   r0,r0,0,29,29
	  bne-      .loc_0x11C
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  b         .loc_0x124

	.loc_0x11C:
	  li        r0, 0x1
	  stw       r0, 0x0(r3)

	.loc_0x124:
	  lwz       r0, 0x0(r3)
	  cmpw      r0, r4
	  beq-      .loc_0x134
	  bl        -0xDB50

	.loc_0x134:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0
	  stw       r0, 0x2B4(r3)
	  stw       r0, 0x2B8(r3)
	  stw       r0, 0x2B0(r3)
	  lwz       r0, 0x1F4(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x15C
	  b         .loc_0x82C

	.loc_0x15C:
	  li        r3, 0xA4C
	  bl        -0x18A24
	  mr.       r31, r3
	  beq-      .loc_0x820
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6DE4
	  bl        -0x2AA84
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6DE4
	  bl        -0x1F318
	  lis       r3, 0x802B
	  subi      r0, r3, 0x74F8
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0x54
	  bl        -0x1C8A4
	  lfs       f0, -0x7930(r2)
	  addi      r3, r31, 0x3C4
	  stfs      f0, 0x3BC(r31)
	  stfs      f0, 0x3B8(r31)
	  stfs      f0, 0x3B4(r31)
	  bl        0x136E4
	  lfs       f0, -0x7930(r2)
	  addi      r0, r30, 0x40
	  li        r3, 0x8
	  stfs      f0, 0xA48(r31)
	  stfs      f0, 0xA44(r31)
	  stfs      f0, 0xA40(r31)
	  stw       r0, 0x4(r31)
	  lfs       f0, -0x7924(r2)
	  stfs      f0, 0x48(r31)
	  lfs       f0, -0x6E38(r13)
	  stfs      f0, 0xA40(r31)
	  lfs       f0, -0x6E34(r13)
	  stfs      f0, 0xA44(r31)
	  lfs       f0, -0x6E30(r13)
	  stfs      f0, 0xA48(r31)
	  bl        -0x18ABC
	  cmplwi    r3, 0
	  beq-      .loc_0x220
	  lis       r4, 0x802A
	  addi      r0, r4, 0x7BE0
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x7420
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)

	.loc_0x220:
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  stw       r3, 0x1E8(r4)
	  li        r3, 0x50
	  bl        -0x18AF4
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x27C
	  addi      r3, r23, 0
	  addi      r4, r30, 0x50
	  bl        -0x2AB58
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r23)
	  addi      r3, r23, 0
	  addi      r4, r30, 0x50
	  bl        -0x1F3EC
	  lis       r3, 0x8023
	  subi      r0, r3, 0x714C
	  stw       r0, 0x0(r23)
	  addi      r3, r23, 0
	  li        r4, 0x1
	  bl        -0x1F190

	.loc_0x27C:
	  stw       r23, 0x30(r31)
	  li        r0, 0
	  li        r3, 0xA8
	  stw       r0, 0x20(r31)
	  bl        -0x18B50
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x2A0
	  bl        0x12152C

	.loc_0x2A0:
	  li        r0, 0
	  stw       r23, 0x2EB8(r13)
	  li        r3, 0x1418
	  stb       r0, 0x2EBC(r13)
	  bl        -0x18B74
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x2CC
	  lwz       r5, 0x30(r31)
	  li        r4, 0
	  bl        0xB924

	.loc_0x2CC:
	  lis       r3, 0x803A
	  stw       r23, 0xA3C(r31)
	  subi      r3, r3, 0x2848
	  li        r0, 0
	  stw       r0, 0x1D8(r3)
	  li        r3, 0x2E8
	  bl        -0x18BA8
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x2FC
	  addi      r4, r30, 0x60
	  bl        0x10018

	.loc_0x2FC:
	  stw       r23, 0x50(r31)
	  lwz       r3, 0x50(r31)
	  addi      r3, r3, 0x8
	  bl        -0x21E14
	  lwz       r3, 0x50(r31)
	  li        r0, 0x1
	  addi      r4, r30, 0x74
	  stb       r0, 0x2E5(r3)
	  li        r5, 0x1
	  li        r6, 0x1
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr.       r23, r3
	  beq-      .loc_0x3E8
	  li        r3, 0x11C
	  bl        -0x18C08
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x398
	  mr        r4, r23
	  bl        -0x1F0A4
	  b         .loc_0x398

	.loc_0x360:
	  addi      r3, r24, 0
	  li        r4, 0x1
	  bl        -0x1EB80
	  addi      r3, r24, 0
	  subi      r4, r13, 0x6DDC
	  bl        -0x1E868
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x398
	  addi      r3, r24, 0
	  li        r4, 0x1
	  bl        -0x1EBA0
	  lwz       r3, 0xA3C(r31)
	  mr        r4, r24
	  bl        0xF410

	.loc_0x398:
	  mr        r3, r24
	  bl        -0x1EF0C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x3B8
	  mr        r3, r24
	  bl        -0x1E7EC
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x360

	.loc_0x3B8:
	  mr        r3, r24
	  bl        -0x1EF2C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x3D4
	  addi      r3, r24, 0
	  li        r4, 0x1
	  bl        -0x1EBE8

	.loc_0x3D4:
	  mr        r3, r23
	  lwz       r12, 0x4(r23)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x3E8:
	  lfs       f0, -0x7920(r2)
	  lis       r3, 0x803A
	  li        r26, 0
	  stfs      f0, 0x4C(r31)
	  addi      r0, r30, 0x88
	  subi      r23, r3, 0x2848
	  lfs       f0, -0x7928(r2)
	  lis       r27, 0x4330
	  stfs      f0, 0x39C(r31)
	  stw       r26, 0xA34(r31)
	  stw       r26, 0x3D4(r31)
	  stw       r26, 0x3D0(r31)
	  stw       r26, 0x3CC(r31)
	  stw       r0, 0x3C8(r31)
	  lfs       f26, -0x791C(r2)
	  lfd       f27, -0x7908(r2)
	  lfs       f28, -0x7918(r2)
	  lfs       f29, -0x7914(r2)
	  lfs       f30, -0x7910(r2)
	  lfs       f31, -0x790C(r2)
	  lfs       f25, -0x7930(r2)
	  b         .loc_0x610

	.loc_0x440:
	  li        r3, 0x670
	  bl        -0x18D08
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x458
	  bl        0x13448

	.loc_0x458:
	  li        r0, 0
	  stb       r0, 0x66C(r24)
	  li        r3, 0xFF
	  li        r0, 0x40
	  stb       r3, 0x660(r24)
	  addi      r4, r30, 0x94
	  li        r5, 0x1
	  stb       r3, 0x661(r24)
	  stb       r0, 0x662(r24)
	  stb       r0, 0x663(r24)
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x20C44
	  xoris     r0, r26, 0x8000
	  stw       r3, 0x668(r24)
	  cmpwi     r26, 0x1
	  stw       r0, 0x64(r1)
	  stw       r27, 0x60(r1)
	  lfd       f0, 0x60(r1)
	  fsubs     f0, f0, f27
	  fmuls     f0, f26, f0
	  stfs      f0, 0x65C(r24)
	  beq-      .loc_0x4E8
	  bge-      .loc_0x4C0
	  cmpwi     r26, 0
	  bge-      .loc_0x4CC
	  b         .loc_0x51C

	.loc_0x4C0:
	  cmpwi     r26, 0x3
	  bge-      .loc_0x51C
	  b         .loc_0x504

	.loc_0x4CC:
	  lfs       f0, -0x6E2C(r13)
	  stfs      f0, 0x458(r24)
	  lfs       f0, -0x6E28(r13)
	  stfs      f0, 0x45C(r24)
	  lfs       f0, -0x6E24(r13)
	  stfs      f0, 0x460(r24)
	  b         .loc_0x51C

	.loc_0x4E8:
	  lfs       f0, -0x6E20(r13)
	  stfs      f0, 0x458(r24)
	  lfs       f0, -0x6E1C(r13)
	  stfs      f0, 0x45C(r24)
	  lfs       f0, -0x6E18(r13)
	  stfs      f0, 0x460(r24)
	  b         .loc_0x51C

	.loc_0x504:
	  lfs       f0, -0x6E14(r13)
	  stfs      f0, 0x458(r24)
	  lfs       f0, -0x6E10(r13)
	  stfs      f0, 0x45C(r24)
	  lfs       f0, -0x6E0C(r13)
	  stfs      f0, 0x460(r24)

	.loc_0x51C:
	  lfs       f0, -0x6E08(r13)
	  li        r3, 0x303
	  li        r0, 0x2
	  stfs      f0, 0x464(r24)
	  addi      r25, r24, 0x80
	  lfs       f0, -0x6E04(r13)
	  stfs      f0, 0x468(r24)
	  lfs       f0, -0x6E00(r13)
	  stfs      f0, 0x46C(r24)
	  stfs      f28, 0x468(r24)
	  lfs       f0, 0x46C(r24)
	  fadds     f0, f0, f29
	  stfs      f0, 0x46C(r24)
	  stfs      f30, 0x4C0(r24)
	  lwz       r5, 0x458(r24)
	  lwz       r4, 0x45C(r24)
	  stw       r5, 0x74(r24)
	  stw       r4, 0x78(r24)
	  lwz       r4, 0x460(r24)
	  stw       r4, 0x7C(r24)
	  lwz       r4, 0x660(r24)
	  stw       r4, 0x8C(r24)
	  stw       r3, 0x34(r24)
	  lfs       f0, 0x4C0(r24)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x40(r24)
	  stw       r0, 0x48(r24)
	  lfs       f0, -0x6DFC(r13)
	  stfs      f0, 0x80(r24)
	  lfs       f0, -0x6DF8(r13)
	  stfs      f0, 0x84(r24)
	  lfs       f0, -0x6DF4(r13)
	  stfs      f0, 0x88(r24)
	  lfs       f1, 0x80(r24)
	  lfs       f0, 0x84(r24)
	  lfs       f2, 0x88(r24)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x52248
	  fcmpu     cr0, f25, f1
	  beq-      .loc_0x5F0
	  lfs       f0, 0x0(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r25)
	  lfs       f0, 0x4(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r25)
	  lfs       f0, 0x8(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r25)

	.loc_0x5F0:
	  addi      r3, r23, 0
	  addi      r5, r24, 0
	  addi      r4, r30, 0xAC
	  bl        -0xD164
	  addi      r3, r31, 0x3C4
	  addi      r4, r24, 0
	  bl        -0x1F8F8
	  addi      r26, r26, 0x1

	.loc_0x610:
	  cmpwi     r26, 0
	  blt+      .loc_0x440
	  li        r0, 0
	  stw       r0, 0x2C(r31)
	  li        r3, 0xB4
	  bl        -0x18EE8
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x648
	  lwz       r5, 0x2DEC(r13)
	  li        r6, 0
	  lwz       r4, 0x30(r31)
	  lwz       r5, 0x10(r5)
	  bl        -0x2814

	.loc_0x648:
	  stw       r23, 0x28(r31)
	  li        r3, 0x14
	  lwz       r0, -0x7848(r13)
	  lwz       r4, 0x28(r31)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  stw       r0, 0x48(r4)
	  lwz       r0, -0x7844(r13)
	  lwz       r4, 0x28(r31)
	  srawi     r5, r0, 0x1
	  addze     r5, r5
	  addi      r0, r5, 0x50
	  stw       r0, 0x4C(r4)
	  bl        -0x18F40
	  mr.       r6, r3
	  beq-      .loc_0x6D4
	  lwz       r0, 0xC(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x10(r30)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x3C(r1)
	  subi      r0, r4, 0x757C
	  stw       r7, 0x40(r1)
	  lwz       r4, 0x14(r30)
	  stw       r4, 0x44(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  lwz       r4, 0x3C(r1)
	  lwz       r0, 0x40(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x44(r1)
	  stw       r0, 0x10(r3)

	.loc_0x6D4:
	  lis       r4, 0x100
	  lwz       r3, 0x28(r31)
	  addi      r5, r4, 0x1000
	  li        r4, 0x10
	  bl        -0x2658
	  li        r3, 0x14
	  bl        -0x18FB0
	  mr.       r6, r3
	  beq-      .loc_0x748
	  lwz       r0, 0x18(r30)
	  lis       r5, 0x802A
	  lwz       r7, 0x1C(r30)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x48(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0x4C(r1)
	  lwz       r4, 0x20(r30)
	  stw       r4, 0x50(r1)
	  lwz       r4, 0x28(r31)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r4, 0x4(r3)
	  lwz       r4, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x50(r1)
	  stw       r0, 0x10(r3)

	.loc_0x748:
	  lwz       r3, 0x28(r31)
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        -0x26C8
	  li        r0, 0
	  stw       r0, 0x24(r31)
	  li        r3, 0x18
	  bl        -0x19028
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x77C
	  li        r4, 0x1F40
	  bl        -0x2AF48

	.loc_0x77C:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  stw       r23, 0x308(r3)
	  li        r5, 0x1E
	  li        r0, 0
	  lfs       f0, -0x6DF0(r13)
	  addi      r3, r29, 0
	  addi      r4, r1, 0x20
	  stfs      f0, 0x3B4(r31)
	  lfs       f0, -0x6DEC(r13)
	  stfs      f0, 0x3B8(r31)
	  lfs       f0, -0x6DE8(r13)
	  stfs      f0, 0x3BC(r31)
	  stw       r5, 0x24(r1)
	  stw       r0, 0x28(r1)
	  stw       r0, 0x2C(r1)
	  stw       r0, 0x20(r1)
	  bl        -0xBFE8
	  li        r3, 0x54
	  bl        -0x1908C
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x7DC
	  bl        0x1909E0

	.loc_0x7DC:
	  li        r0, 0
	  stw       r23, 0x2EC0(r13)
	  li        r3, 0x14
	  stb       r0, 0x2EC4(r13)
	  bl        -0x190B0
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x800
	  bl        0x1388C4

	.loc_0x800:
	  li        r0, 0
	  stw       r23, 0x2EC8(r13)
	  lwz       r3, 0x2DEC(r13)
	  stb       r0, 0x2ECC(r13)
	  lfs       f0, -0x7928(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x792C(r2)
	  stfs      f0, 0xC(r3)

	.loc_0x820:
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        -0x1FB18

	.loc_0x82C:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  li        r4, 0
	  bl        -0x46890
	  lmw       r23, 0x6C(r1)
	  lwz       r0, 0xCC(r1)
	  lfd       f31, 0xC0(r1)
	  lfd       f30, 0xB8(r1)
	  lfd       f29, 0xB0(r1)
	  lfd       f28, 0xA8(r1)
	  lfd       f27, 0xA0(r1)
	  lfd       f26, 0x98(r1)
	  lfd       f25, 0x90(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80060144
 * Size:	000734
 */
void TitleSetupSection::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x150(r1)
	  stfd      f31, 0x148(r1)
	  stfd      f30, 0x140(r1)
	  stfd      f29, 0x138(r1)
	  stfd      f28, 0x130(r1)
	  stfd      f27, 0x128(r1)
	  stmw      r22, 0x100(r1)
	  mr        r27, r3
	  lwz       r3, 0x30(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x20(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0xC0
	  lbz       r0, 0x2ECC(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xC0
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x48(r27)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x48(r27)
	  lfs       f1, 0x48(r27)
	  lfs       f0, -0x7930(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xC0
	  lis       r3, 0x803A
	  stfs      f0, 0x48(r27)
	  subi      r5, r3, 0x2848
	  lwz       r4, 0x2AC(r5)
	  lis       r3, 0x2
	  li        r0, 0x1
	  stw       r4, 0x2B0(r5)
	  lwz       r4, 0x2AC(r5)
	  addi      r4, r4, 0x1
	  rlwinm    r4,r4,0,30,31
	  stw       r4, 0x2AC(r5)
	  stw       r3, 0x24(r27)
	  stw       r0, 0x20(r27)
	  lwz       r3, 0x2DEC(r13)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x792C(r2)
	  stfs      f0, 0xC(r3)
	  b         .loc_0x70C

	.loc_0xC0:
	  lwz       r0, 0x2C(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0xE0
	  lis       r3, 0x803A
	  lfs       f1, -0x7928(r2)
	  subi      r3, r3, 0x2848
	  addi      r3, r3, 0x2D8
	  bl        -0xE95C

	.loc_0xE0:
	  lwz       r0, 0x2C(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x2BC
	  lwz       r5, 0x30(r27)
	  lis       r3, 0x4330
	  lfd       f4, -0x7908(r2)
	  lbz       r4, 0x45(r5)
	  lbz       r0, 0x46(r5)
	  extsb     r4, r4
	  lfs       f5, -0x7900(r2)
	  xoris     r4, r4, 0x8000
	  lfs       f0, 0x1D0(r27)
	  stw       r4, 0xFC(r1)
	  extsb     r0, r0
	  xoris     r0, r0, 0x8000
	  lfs       f1, 0x1D8(r27)
	  stw       r3, 0xF8(r1)
	  lfs       f27, -0x6E54(r13)
	  lfd       f2, 0xF8(r1)
	  stw       r0, 0xF4(r1)
	  fsubs     f2, f2, f4
	  lfs       f31, -0x6E58(r13)
	  lfs       f7, -0x6E50(r13)
	  stw       r3, 0xF0(r1)
	  fmuls     f6, f5, f2
	  lfd       f2, 0xF0(r1)
	  fmuls     f3, f31, f7
	  lfs       f30, -0x6E4C(r13)
	  fmuls     f10, f0, f6
	  fsubs     f0, f2, f4
	  lfs       f29, -0x6E44(r13)
	  fmuls     f11, f1, f6
	  lfs       f1, 0x1E8(r27)
	  fmuls     f4, f10, f27
	  fmuls     f8, f5, f0
	  lfs       f0, 0x1F0(r27)
	  fmuls     f5, f11, f30
	  lfs       f28, -0x6E40(r13)
	  fadds     f3, f4, f3
	  fmuls     f12, f1, f8
	  lfs       f1, -0x6E48(r13)
	  fmuls     f0, f0, f8
	  lfs       f2, -0x6E3C(r13)
	  fadds     f13, f5, f3
	  fmuls     f8, f12, f29
	  lfs       f6, 0xA40(r27)
	  fmuls     f9, f0, f2
	  fmuls     f4, f13, f27
	  fmuls     f3, f13, f7
	  fmuls     f7, f1, f28
	  fsubs     f5, f4, f10
	  fsubs     f4, f3, f31
	  fadds     f7, f8, f7
	  fneg      f5, f5
	  fmuls     f3, f13, f30
	  fadds     f8, f9, f7
	  fadds     f5, f6, f5
	  fneg      f6, f4
	  fmuls     f4, f8, f29
	  stfs      f5, 0xA40(r27)
	  fsubs     f3, f3, f11
	  lfs       f7, 0xA44(r27)
	  fsubs     f4, f4, f12
	  fneg      f5, f3
	  fadds     f6, f7, f6
	  fmuls     f3, f8, f28
	  stfs      f6, 0xA44(r27)
	  fsubs     f3, f3, f1
	  fmuls     f1, f8, f2
	  fneg      f2, f4
	  lfs       f4, 0xA48(r27)
	  fadds     f4, f4, f5
	  fsubs     f0, f1, f0
	  fneg      f1, f3
	  stfs      f4, 0xA48(r27)
	  fneg      f0, f0
	  lfs       f3, 0xA40(r27)
	  fadds     f2, f3, f2
	  stfs      f2, 0xA40(r27)
	  lfs       f2, 0xA44(r27)
	  fadds     f1, f2, f1
	  stfs      f1, 0xA44(r27)
	  lfs       f1, 0xA48(r27)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA48(r27)
	  lwz       r3, 0x30(r27)
	  lwz       r3, 0x20(r3)
	  rlwinm.   r0,r3,0,14,14
	  beq-      .loc_0x25C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4C(r27)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4C(r27)
	  b         .loc_0x278

	.loc_0x25C:
	  rlwinm.   r0,r3,0,13,13
	  beq-      .loc_0x278
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4C(r27)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4C(r27)

	.loc_0x278:
	  lwz       r3, 0x30(r27)
	  lwz       r3, 0x20(r3)
	  rlwinm.   r0,r3,0,30,30
	  beq-      .loc_0x2A0
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x374(r27)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x374(r27)
	  b         .loc_0x2BC

	.loc_0x2A0:
	  rlwinm.   r0,r3,0,31,31
	  beq-      .loc_0x2BC
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x374(r27)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x374(r27)

	.loc_0x2BC:
	  lfs       f0, -0x7930(r2)
	  stfs      f0, 0xD0(r1)
	  stfs      f0, 0xCC(r1)
	  stfs      f0, 0xC8(r1)
	  lfs       f1, 0x374(r27)
	  bl        0x1BB8D4
	  lfs       f3, -0x78FC(r2)
	  lfs       f2, 0x4C(r27)
	  lfs       f0, 0xA40(r27)
	  fmuls     f2, f3, f2
	  fmuls     f1, f2, f1
	  fadds     f0, f0, f1
	  stfs      f0, 0xC8(r1)
	  lfs       f1, 0x378(r27)
	  bl        0x1BB8B0
	  lfs       f2, -0x78F4(r2)
	  lfs       f0, 0x4C(r27)
	  lfs       f3, 0xA44(r27)
	  fmuls     f0, f2, f0
	  lfs       f2, -0x78F8(r2)
	  fadds     f1, f3, f1
	  fmuls     f0, f2, f0
	  fadds     f0, f0, f1
	  stfs      f0, 0xCC(r1)
	  lfs       f1, 0x374(r27)
	  bl        0x1BB6F0
	  lfs       f3, -0x78FC(r2)
	  addi      r3, r27, 0x54
	  lfs       f2, 0x4C(r27)
	  addi      r4, r1, 0xC8
	  lfs       f0, 0xA48(r27)
	  fmuls     f2, f3, f2
	  addi      r5, r27, 0xA40
	  li        r6, 0
	  fmuls     f1, f2, f1
	  fadds     f0, f0, f1
	  stfs      f0, 0xD0(r1)
	  lwz       r7, 0xC8(r1)
	  lwz       r0, 0xCC(r1)
	  stw       r7, 0x1B8(r27)
	  stw       r0, 0x1BC(r27)
	  lwz       r0, 0xD0(r1)
	  stw       r0, 0x1C0(r27)
	  bl        -0x1D4A0
	  lwz       r3, 0x2C(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x3A8
	  lwz       r12, 0x0(r3)
	  li        r4, 0
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x2C(r27)
	  lfs       f0, -0x78F0(r2)
	  lwz       r3, 0x50(r27)
	  stfs      f0, 0x2A0(r3)
	  lwz       r3, 0x50(r27)
	  bl        0x10494
	  b         .loc_0x6AC

	.loc_0x3A8:
	  lfs       f0, -0x78F0(r2)
	  lwz       r3, 0x50(r27)
	  stfs      f0, 0x2A0(r3)
	  lwz       r3, 0x50(r27)
	  bl        0x1047C
	  lwz       r0, 0x20(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x6AC
	  lwz       r3, 0x2EC0(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x3FC
	  lwz       r4, 0x30(r27)
	  bl        0x19093C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3FC
	  li        r0, 0
	  lwz       r3, 0x2EC8(r13)
	  stb       r0, 0x2EC4(r13)
	  bl        0x13854C
	  li        r0, 0x1
	  stb       r0, 0x2ECC(r13)

	.loc_0x3FC:
	  lbz       r0, 0x2EC4(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x6A4
	  lbz       r0, 0x2ECC(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x470
	  lbz       r0, 0x2EBC(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x470
	  lwz       r4, 0x30(r27)
	  lis       r3, 0x100
	  addi      r0, r3, 0x1000
	  lwz       r3, 0x28(r4)
	  and.      r0, r3, r0
	  beq-      .loc_0x470
	  lwz       r3, 0x2EC8(r13)
	  bl        0x138538
	  li        r0, 0
	  lwz       r3, 0x2EB8(r13)
	  lis       r4, 0x803A
	  stb       r0, 0x2ECC(r13)
	  subi      r4, r4, 0x2848
	  lbz       r0, 0xB6(r4)
	  neg       r4, r0
	  subic     r0, r4, 0x1
	  subfe     r4, r0, r4
	  bl        0x120F90
	  li        r0, 0x1
	  stb       r0, 0x2EBC(r13)

	.loc_0x470:
	  lwz       r3, 0x2EC8(r13)
	  lwz       r4, 0x30(r27)
	  bl        0x138524
	  lwz       r3, 0x2EB8(r13)
	  lwz       r4, 0x30(r27)
	  bl        0x121054
	  cmpwi     r3, 0x6
	  bne-      .loc_0x4D8
	  lis       r0, 0x4
	  lis       r3, 0x803A
	  stw       r0, 0x24(r27)
	  subi      r4, r3, 0x2848
	  li        r0, 0
	  stb       r0, 0xB2(r4)
	  li        r26, 0x1
	  li        r3, 0xD
	  stw       r26, 0x2B4(r4)
	  li        r4, 0
	  bl        -0x4691C
	  stw       r26, 0x20(r27)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, -0x7930(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x792C(r2)
	  stfs      f0, 0xC(r3)
	  b         .loc_0x6A4

	.loc_0x4D8:
	  cmpwi     r3, 0x7
	  bne-      .loc_0x4FC
	  li        r4, 0
	  lwz       r3, 0x2EC0(r13)
	  li        r0, 0x1
	  stb       r4, 0x2EBC(r13)
	  stb       r0, 0x2EC4(r13)
	  bl        0x190AFC
	  b         .loc_0x6A4

	.loc_0x4FC:
	  cmpwi     r3, 0x4
	  bne-      .loc_0x558
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lbz       r0, 0xB2(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x524
	  lis       r0, 0x4
	  stw       r0, 0x24(r27)
	  b         .loc_0x52C

	.loc_0x524:
	  lis       r0, 0x4
	  stw       r0, 0x24(r27)

	.loc_0x52C:
	  li        r3, 0xD
	  li        r4, 0
	  bl        -0x46998
	  li        r0, 0x1
	  stw       r0, 0x20(r27)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, -0x7930(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x792C(r2)
	  stfs      f0, 0xC(r3)
	  b         .loc_0x6A4

	.loc_0x558:
	  cmpwi     r3, 0x5
	  beq-      .loc_0x568
	  cmpwi     r3, 0x3
	  bne-      .loc_0x6A4

	.loc_0x568:
	  lis       r3, 0x803A
	  subi      r26, r3, 0x2848
	  addi      r30, r26, 0xA8
	  lwz       r6, 0xAC(r26)
	  lbz       r0, 0xA8(r26)
	  rlwinm    r3,r6,0,29,29
	  neg       r5, r3
	  subic     r3, r5, 0x1
	  cmplwi    r0, 0
	  subfe     r31, r3, r5
	  beq-      .loc_0x648
	  rlwinm    r0,r6,0,31,31
	  lbz       r29, 0xB0(r26)
	  neg       r4, r0
	  lbz       r28, 0xB1(r26)
	  subic     r3, r4, 0x1
	  rlwinm    r0,r6,0,30,30
	  subfe     r24, r3, r4
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r23, r0, r3
	  subic     r0, r5, 0x1
	  addi      r25, r26, 0x24
	  addi      r3, r25, 0
	  subfe     r22, r0, r5
	  li        r4, 0x1
	  bl        0x137DC
	  cmpwi     r3, 0
	  bne-      .loc_0x5F0
	  lwz       r0, 0x5C(r26)
	  cmpwi     r0, 0
	  blt-      .loc_0x5F0
	  mr        r3, r25
	  bl        0x13BC0

	.loc_0x5F0:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  addi      r4, r24, 0
	  bl        -0xC990
	  addi      r3, r26, 0
	  addi      r4, r23, 0
	  bl        -0xCA38
	  addi      r3, r26, 0
	  addi      r4, r22, 0
	  bl        -0xC8F0
	  addi      r3, r26, 0
	  addi      r4, r29, 0
	  bl        -0xCAD0
	  addi      r3, r26, 0
	  addi      r4, r28, 0
	  bl        -0xCA9C
	  li        r0, 0
	  stb       r0, 0x0(r30)
	  mr        r3, r25
	  bl        0x13C0C

	.loc_0x648:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r4, r3, 0x2A8
	  lwz       r3, 0x2A8(r3)
	  rlwinm    r0,r31,0,24,31
	  cmpw      r3, r0
	  beq-      .loc_0x68C
	  li        r0, -0x1
	  stw       r0, 0x0(r4)
	  li        r0, 0x1
	  stw       r0, 0x20(r27)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, -0x7930(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x792C(r2)
	  stfs      f0, 0xC(r3)
	  b         .loc_0x6A4

	.loc_0x68C:
	  lwz       r3, 0x2EC8(r13)
	  bl        0x1382AC
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x2ECC(r13)
	  stb       r0, 0x2EBC(r13)

	.loc_0x6A4:
	  mr        r3, r27
	  bl        -0x20088

	.loc_0x6AC:
	  lwz       r0, 0x20(r27)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x70C
	  lwz       r0, 0x2C(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x70C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7930(r2)
	  lfs       f0, 0x4(r3)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x70C
	  li        r0, -0x1
	  stw       r0, 0x20(r27)
	  lis       r3, 0x803A
	  subi      r4, r3, 0x2848
	  lwz       r3, 0x24(r27)
	  li        r0, 0x1
	  rlwinm    r3,r3,16,16,31
	  stw       r3, 0x1F0(r4)
	  lwz       r3, 0x24(r27)
	  rlwinm    r3,r3,0,16,31
	  stw       r3, 0x1F4(r4)
	  lwz       r3, 0x2DEC(r13)
	  stb       r0, 0x0(r3)

	.loc_0x70C:
	  lmw       r22, 0x100(r1)
	  lwz       r0, 0x154(r1)
	  lfd       f31, 0x148(r1)
	  lfd       f30, 0x140(r1)
	  lfd       f29, 0x138(r1)
	  lfd       f28, 0x130(r1)
	  lfd       f27, 0x128(r1)
	  addi      r1, r1, 0x150
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80060878
 * Size:	0008BC
 */
void TitleSetupSection::draw(Graphics&)
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
	  stmw      r27, 0x1C4(r1)
	  mr        r30, r3
	  mr        r31, r4
	  lwz       r3, 0x50(r3)
	  lwz       r4, 0x7C(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x58
	  mr        r3, r31
	  lwz       r4, 0x1C(r4)
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r4, 0xA8
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xC0

	.loc_0x58:
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r30, 0x54
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x30C(r31)
	  lis       r4, 0x4330
	  lwz       r0, 0x310(r31)
	  addi      r3, r30, 0x54
	  xoris     r5, r5, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r5, 0x1BC(r1)
	  lfd       f5, -0x7908(r2)
	  stw       r0, 0x1B4(r1)
	  lfs       f2, 0x220(r30)
	  stw       r4, 0x1B8(r1)
	  lfs       f3, -0x78EC(r2)
	  stw       r4, 0x1B0(r1)
	  lfd       f1, 0x1B8(r1)
	  lfd       f0, 0x1B0(r1)
	  fsubs     f1, f1, f5
	  lfs       f4, -0x78E8(r2)
	  fsubs     f0, f0, f5
	  fdivs     f1, f1, f0
	  bl        -0x1DCE0

	.loc_0xC0:
	  lwz       r0, 0xA34(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0x258
	  lwz       r27, 0x3D4(r30)
	  lfs       f30, -0x78E4(r2)
	  lfs       f31, -0x7924(r2)
	  lfs       f29, -0x7930(r2)
	  b         .loc_0x250

	.loc_0xE0:
	  lwz       r3, 0x2DEC(r13)
	  addi      r28, r27, 0x2F4
	  lfs       f1, 0x65C(r27)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f30, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x65C(r27)
	  lfs       f1, 0x65C(r27)
	  bl        0x1BB1DC
	  fmuls     f2, f31, f1
	  lfs       f0, 0x16C(r28)
	  lfs       f1, 0x65C(r27)
	  fadds     f28, f0, f2
	  bl        0x1BB35C
	  fmuls     f1, f31, f1
	  lfs       f0, 0x164(r28)
	  li        r0, 0
	  addi      r3, r28, 0
	  fadds     f0, f0, f1
	  addi      r4, r28, 0x164
	  addi      r5, r28, 0x170
	  stfs      f0, 0x170(r28)
	  stfs      f28, 0x178(r28)
	  stw       r0, 0x358(r28)
	  bl        -0x1DC14
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  li        r5, 0x1
	  li        r6, 0
	  bl        -0x1D5E8
	  lwz       r3, 0x164(r28)
	  lwz       r0, 0x168(r28)
	  stw       r3, 0x74(r27)
	  stw       r0, 0x78(r27)
	  lwz       r0, 0x16C(r28)
	  stw       r0, 0x7C(r27)
	  lfs       f1, 0x170(r28)
	  lfs       f0, 0x164(r28)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x80(r1)
	  stfs      f0, 0xDC(r1)
	  lfs       f1, 0x174(r28)
	  lfs       f0, 0x168(r28)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xE0(r1)
	  lfs       f1, 0x178(r28)
	  lfs       f0, 0x16C(r28)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xE4(r1)
	  lwz       r3, 0xDC(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r3, 0x80(r27)
	  stw       r0, 0x84(r27)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x88(r27)
	  lfs       f1, 0x80(r27)
	  lfs       f0, 0x84(r27)
	  lfs       f2, 0x88(r27)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x52E18
	  fcmpu     cr0, f29, f1
	  beq-      .loc_0x210
	  lfs       f0, 0x80(r27)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x80(r27)
	  lfs       f0, 0x84(r27)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x84(r27)
	  lfs       f0, 0x88(r27)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x88(r27)

	.loc_0x210:
	  addi      r3, r27, 0x20
	  bl        -0x36BC4
	  li        r5, 0
	  stw       r5, 0x30(r27)
	  subi      r0, r13, 0x6D8C
	  addi      r3, r31, 0x10
	  stw       r5, 0x2C(r27)
	  addi      r4, r27, 0x20
	  stw       r5, 0x28(r27)
	  stw       r0, 0x24(r27)
	  lwz       r6, 0x2DEC(r13)
	  lwz       r5, 0x1B0(r6)
	  addi      r0, r5, 0x1
	  stw       r0, 0x1B0(r6)
	  bl        -0x204E8
	  lwz       r27, 0xC(r27)

	.loc_0x250:
	  cmplwi    r27, 0
	  bne+      .loc_0xE0

	.loc_0x258:
	  lwz       r5, 0x310(r31)
	  li        r28, 0
	  lwz       r0, 0x30C(r31)
	  addi      r4, r1, 0xCC
	  addi      r3, r31, 0
	  stw       r28, 0xCC(r1)
	  stw       r28, 0xD0(r1)
	  stw       r0, 0xD4(r1)
	  stw       r5, 0xD8(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r31)
	  addi      r4, r1, 0xBC
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  stw       r28, 0xBC(r1)
	  stw       r28, 0xC0(r1)
	  stw       r0, 0xC4(r1)
	  stw       r5, 0xC8(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  stb       r28, 0xB8(r1)
	  addi      r4, r1, 0xB8
	  addi      r3, r31, 0
	  stb       r28, 0xB9(r1)
	  stb       r28, 0xBA(r1)
	  stb       r28, 0xBB(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xB4(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0x3
	  li        r5, 0
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  li        r4, 0x30
	  stb       r4, 0x368(r31)
	  lis       r3, 0x803A
	  subi      r28, r3, 0x77C0
	  stb       r4, 0x369(r31)
	  li        r0, 0xFF
	  addi      r3, r31, 0
	  stb       r4, 0x36A(r31)
	  addi      r4, r28, 0
	  addi      r5, r1, 0x130
	  stb       r0, 0x36B(r31)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r5, 0x2E4(r31)
	  lwz       r12, 0x3B4(r31)
	  lfs       f1, 0x1CC(r5)
	  addi      r4, r5, 0x260
	  lwz       r12, 0x3C(r12)
	  lfs       f2, 0x1C4(r5)
	  mtlr      r12
	  lfs       f3, 0x1D0(r5)
	  lfs       f4, 0x1D4(r5)
	  lfs       f5, -0x7928(r2)
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  lwz       r12, 0xB8(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r31)
	  mr        r3, r31
	  mr        r4, r28
	  lwz       r12, 0x70(r12)
	  addi      r5, r1, 0xF0
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r31)
	  mr        r3, r31
	  mr        r4, r28
	  lwz       r12, 0x74(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  rlwinm.   r0,r0,0,24,24
	  bne-      .loc_0x414
	  lwz       r3, 0xA3C(r30)
	  mr        r4, r31
	  lfs       f1, -0x78E0(r2)
	  li        r5, 0x8
	  bl        0xD8E8
	  lwz       r3, 0xA3C(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        0xE310
	  b         .loc_0x420

	.loc_0x414:
	  lwz       r3, 0x50(r30)
	  mr        r4, r31
	  bl        0x10258

	.loc_0x420:
	  mr        r3, r31
	  lfs       f1, -0x7928(r2)
	  bl        -0x374C4
	  lbz       r0, 0x2ED4(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x448
	  lfs       f0, -0x7930(r2)
	  li        r0, 0x1
	  stb       r0, 0x2ED4(r13)
	  stfs      f0, 0x2ED0(r13)

	.loc_0x448:
	  lwz       r3, 0x2DEC(r13)
	  lbz       r0, 0x2EDC(r13)
	  lfs       f1, -0x790C(r2)
	  lfs       f0, 0x28C(r3)
	  extsb.    r0, r0
	  lfs       f2, 0x2ED0(r13)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x2ED0(r13)
	  bne-      .loc_0x480
	  li        r3, 0xF
	  li        r0, 0x1
	  stw       r3, 0x2ED8(r13)
	  stb       r0, 0x2EDC(r13)

	.loc_0x480:
	  lbz       r0, 0x2EE4(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x49C
	  li        r3, 0x14
	  li        r0, 0x1
	  stw       r3, 0x2EE0(r13)
	  stb       r0, 0x2EE4(r13)

	.loc_0x49C:
	  lwz       r3, 0x30(r30)
	  lwz       r3, 0x28(r3)
	  rlwinm.   r0,r3,0,17,17
	  beq-      .loc_0x4BC
	  lwz       r3, 0x2ED8(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2ED8(r13)
	  b         .loc_0x4D0

	.loc_0x4BC:
	  rlwinm.   r0,r3,0,16,16
	  beq-      .loc_0x4D0
	  lwz       r3, 0x2ED8(r13)
	  subi      r0, r3, 0x1
	  stw       r0, 0x2ED8(r13)

	.loc_0x4D0:
	  lwz       r3, 0x50(r30)
	  mr        r4, r31
	  bl        0x10260
	  lbz       r0, 0x2EEC(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x4F8
	  lfs       f0, -0x7930(r2)
	  li        r0, 0x1
	  stb       r0, 0x2EEC(r13)
	  stfs      f0, 0x2EE8(r13)

	.loc_0x4F8:
	  lwz       r4, 0x2DEC(r13)
	  lis       r3, 0x803A
	  subi      r28, r3, 0x77C0
	  lfs       f1, -0x78DC(r2)
	  lfs       f0, 0x28C(r4)
	  lfs       f2, 0x2EE8(r13)
	  mr        r3, r31
	  fmuls     f0, f1, f0
	  addi      r4, r28, 0
	  li        r5, 0
	  fadds     f0, f2, f0
	  stfs      f0, 0x2EE8(r13)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r31)
	  mr        r3, r31
	  mr        r4, r28
	  lwz       r12, 0x74(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r31)
	  mr        r3, r31
	  mr        r4, r28
	  lwz       r12, 0x74(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r0, 0xA34(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0x5A8
	  lwz       r27, 0x3D4(r30)
	  b         .loc_0x5A0

	.loc_0x584:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r27, 0xC(r27)

	.loc_0x5A0:
	  cmplwi    r27, 0
	  bne+      .loc_0x584

	.loc_0x5A8:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x20658
	  mr        r3, r31
	  bl        -0x38764
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r31
	  bl        -0x212B4
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0xA8
	  addi      r3, r31, 0
	  stw       r0, 0xA8(r1)
	  addi      r4, r1, 0x170
	  stw       r0, 0xAC(r1)
	  stw       r6, 0xB0(r1)
	  stw       r7, 0xB4(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lbz       r0, 0x2EF4(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x63C
	  lfs       f0, -0x7930(r2)
	  li        r0, 0x1
	  stb       r0, 0x2EF4(r13)
	  stfs      f0, 0x2EF0(r13)

	.loc_0x63C:
	  lwz       r0, 0x2C(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x67C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x78D8(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x2EF0(r13)
	  fmuls     f1, f1, f0
	  lfs       f0, -0x7930(r2)
	  fsubs     f1, f2, f1
	  stfs      f1, 0x2EF0(r13)
	  lfs       f1, 0x2EF0(r13)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x6AC
	  stfs      f0, 0x2EF0(r13)
	  b         .loc_0x6AC

	.loc_0x67C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x78D8(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x2EF0(r13)
	  fmuls     f1, f1, f0
	  lfs       f0, -0x78D4(r2)
	  fadds     f1, f2, f1
	  stfs      f1, 0x2EF0(r13)
	  lfs       f1, 0x2EF0(r13)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x6AC
	  stfs      f0, 0x2EF0(r13)

	.loc_0x6AC:
	  lfs       f1, 0x2EF0(r13)
	  lfs       f0, -0x7930(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x740
	  fctiwz    f0, f1
	  li        r28, 0xFF
	  stb       r28, 0xA4(r1)
	  li        r29, 0x40
	  addi      r4, r1, 0xA4
	  stfd      f0, 0x1B0(r1)
	  mr        r3, r31
	  li        r5, 0x1
	  stb       r28, 0xA5(r1)
	  lwz       r0, 0x1B4(r1)
	  stb       r29, 0xA6(r1)
	  stb       r0, 0xA7(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x790C(r2)
	  li        r0, 0
	  lfs       f0, 0x2EF0(r13)
	  addi      r4, r1, 0xA0
	  stb       r28, 0xA0(r1)
	  fmuls     f0, f1, f0
	  mr        r3, r31
	  stb       r0, 0xA1(r1)
	  fctiwz    f0, f0
	  stb       r29, 0xA2(r1)
	  stfd      f0, 0x1B8(r1)
	  lwz       r0, 0x1BC(r1)
	  stb       r0, 0xA3(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl

	.loc_0x740:
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  lwz       r28, 0x2C(r30)
	  cmplwi    r28, 0
	  beq-      .loc_0x7D8
	  lwz       r0, 0x3C(r28)
	  cmpwi     r0, 0
	  beq-      .loc_0x7C4
	  lwz       r29, 0x20(r28)
	  lwz       r0, 0x3C(r29)
	  cmpwi     r0, 0
	  beq-      .loc_0x7B4
	  lwz       r27, 0x20(r29)
	  lwz       r0, 0x3C(r27)
	  cmpwi     r0, 0
	  beq-      .loc_0x7A4
	  lwz       r5, 0x20(r27)
	  mr        r3, r30
	  lfs       f1, -0x78D0(r2)
	  mr        r4, r31
	  bl        .loc_0x8BC

	.loc_0x7A4:
	  lfs       f1, -0x78CC(r2)
	  addi      r3, r27, 0
	  addi      r4, r31, 0
	  bl        -0x2C18

	.loc_0x7B4:
	  lfs       f1, -0x790C(r2)
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  bl        -0x2C28

	.loc_0x7C4:
	  lfs       f1, -0x7928(r2)
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        -0x2C38
	  b         .loc_0x840

	.loc_0x7D8:
	  lwz       r3, 0x2EC8(r13)
	  mr        r4, r31
	  bl        0x137C48
	  lwz       r3, 0x2EB8(r13)
	  mr        r4, r31
	  bl        0x120FB0
	  lwz       r0, 0x2EC0(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x840
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x90
	  addi      r3, r31, 0
	  stw       r0, 0x90(r1)
	  addi      r4, r1, 0x170
	  stw       r0, 0x94(r1)
	  stw       r6, 0x98(r1)
	  stw       r7, 0x9C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2EC0(r13)
	  mr        r4, r31
	  bl        0x18FED0

	.loc_0x840:
	  lis       r3, 0x803A
	  lfs       f2, -0x7930(r2)
	  subi      r3, r3, 0x2848
	  addi      r5, r3, 0x314
	  lfs       f1, 0x314(r3)
	  fcmpo     cr0, f1, f2
	  ble-      .loc_0x898
	  lwz       r4, 0x2DEC(r13)
	  lfs       f0, 0x28C(r4)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x0(r5)
	  lfs       f1, 0x0(r5)
	  fcmpo     cr0, f1, f2
	  bge-      .loc_0x888
	  stfs      f2, 0x0(r5)
	  li        r0, 0
	  stw       r0, 0x2D4(r3)
	  b         .loc_0x898

	.loc_0x888:
	  lwz       r6, 0x310(r3)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0xFB44

	.loc_0x898:
	  lmw       r27, 0x1C4(r1)
	  lwz       r0, 0x1FC(r1)
	  lfd       f31, 0x1F0(r1)
	  lfd       f30, 0x1E8(r1)
	  lfd       f29, 0x1E0(r1)
	  lfd       f28, 0x1D8(r1)
	  addi      r1, r1, 0x1F8
	  mtlr      r0
	  blr

	.loc_0x8BC:
	*/
}

/*
 * --INFO--
 * Address:	80061134
 * Size:	0000EC
 */
void TitleSetupSection::drawMenu(Graphics&, Menu*, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  fmr       f31, f1
	  stmw      r27, 0x1C(r1)
	  mr        r28, r5
	  addi      r27, r4, 0
	  lwz       r0, 0x3C(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0xC4
	  lwz       r31, 0x20(r28)
	  lwz       r0, 0x3C(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0xB0
	  lwz       r30, 0x20(r31)
	  lwz       r0, 0x3C(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0x98
	  lwz       r29, 0x20(r30)
	  lwz       r0, 0x3C(r29)
	  cmpwi     r0, 0
	  beq-      .loc_0x7C
	  lfs       f1, -0x790C(r2)
	  mr        r4, r27
	  lwz       r5, 0x20(r29)
	  fmuls     f0, f1, f31
	  fmuls     f0, f1, f0
	  fmuls     f0, f1, f0
	  fmuls     f1, f1, f0
	  bl        .loc_0x0

	.loc_0x7C:
	  lfs       f1, -0x790C(r2)
	  addi      r3, r29, 0
	  addi      r4, r27, 0
	  fmuls     f0, f1, f31
	  fmuls     f0, f1, f0
	  fmuls     f1, f1, f0
	  bl        -0x2DB8

	.loc_0x98:
	  lfs       f1, -0x790C(r2)
	  addi      r3, r30, 0
	  addi      r4, r27, 0
	  fmuls     f0, f1, f31
	  fmuls     f1, f1, f0
	  bl        -0x2DD0

	.loc_0xB0:
	  lfs       f0, -0x790C(r2)
	  addi      r3, r31, 0
	  addi      r4, r27, 0
	  fmuls     f1, f0, f31
	  bl        -0x2DE4

	.loc_0xC4:
	  fmr       f1, f31
	  addi      r3, r28, 0
	  addi      r4, r27, 0
	  bl        -0x2DF4
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80061220
 * Size:	000030
 */
void Delegate1<TitleSetupSection, Menu&>::invoke(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  addi      r12, r5, 0x8
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  bl        0x1B3AF8
	  nop
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
