#include "TAI/Areaction.h"
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
 * Size:	0000F4
 */
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	801A8490
 * Size:	000050
 */
bool TAIAhitCheckFlyingPiki::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x3C
	  lwz       r3, 0x8(r4)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x3C
	  bl        -0xDFF64
	  cmpwi     r3, 0xE
	  bne-      .loc_0x3C
	  li        r3, 0x1
	  b         .loc_0x40

	.loc_0x3C:
	  li        r3, 0

	.loc_0x40:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A84E0
 * Size:	00001C
 */
bool TAIAdeadCheck::act(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0x58(r4)
	  lfs       f0, -0x4A78(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  mfcr      r0
	  rlwinm    r3,r0,3,31,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A84FC
 * Size:	000030
 */
void TAIAdie::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x178(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A852C
 * Size:	0000F8
 */
void TAIAdying::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x4738
	  mr        r3, r31
	  lwz       r4, -0x9C4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x4A78(r2)
	  stfs      f0, 0x58(r31)
	  lwz       r0, 0x320(r31)
	  cmpwi     r0, 0x16
	  beq-      .loc_0x78
	  bge-      .loc_0xB4
	  cmpwi     r0, 0x10
	  beq-      .loc_0x54
	  b         .loc_0xB4

	.loc_0x54:
	  mr        r3, r31
	  lwz       r4, -0x9CC(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x62938
	  b         .loc_0xDC

	.loc_0x78:
	  mr        r3, r31
	  lwz       r4, -0x9CC(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9D0(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x62974
	  b         .loc_0xDC

	.loc_0xB4:
	  mr        r3, r31
	  lwz       r4, -0x9D0(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x62998
	  mr        r3, r31
	  bl        -0x6279C

	.loc_0xDC:
	  mr        r3, r31
	  bl        -0x629CC
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A8624
 * Size:	0000AC
 */
bool TAIAdying::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lwz       r3, 0x2CC(r4)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x94
	  lwz       r0, 0x320(r31)
	  cmpwi     r0, 0x16
	  beq-      .loc_0x64
	  bge-      .loc_0x40
	  cmpwi     r0, 0x10
	  beq-      .loc_0x4C
	  b         .loc_0x78

	.loc_0x40:
	  cmpwi     r0, 0x18
	  beq-      .loc_0x70
	  b         .loc_0x78

	.loc_0x4C:
	  mr        r3, r31
	  lwz       r4, -0x9D0(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl

	.loc_0x64:
	  mr        r3, r31
	  bl        -0x62824
	  b         .loc_0x78

	.loc_0x70:
	  mr        r3, r31
	  bl        -0x62A34

	.loc_0x78:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x178(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x98

	.loc_0x94:
	  li        r3, 0

	.loc_0x98:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A86D0
 * Size:	000044
 */
void TAIAdyingKabekui::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x1B8
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,26,24
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x2
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A8714
 * Size:	000144
 */
bool TAIAdyingKabekui::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r4
	  stw       r30, 0x38(r1)
	  mr        r30, r3
	  lfs       f1, 0x94(r4)
	  lfs       f2, 0x9C(r4)
	  li        r4, 0x1
	  lfs       f31, 0x98(r31)
	  lwz       r3, 0x2F00(r13)
	  bl        -0x140844
	  fsubs     f1, f1, f31
	  lfs       f0, -0x4A78(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x4C
	  fneg      f1, f1

	.loc_0x4C:
	  lfs       f0, -0x4A74(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xA4
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r31
	  lfs       f31, 0x28C(r4)
	  bl        -0x5FE50
	  lfs       f2, -0x4A70(r2)
	  lfs       f0, 0x74(r31)
	  fmuls     f1, f2, f1
	  fmuls     f1, f1, f31
	  fcmpo     cr0, f0, f1
	  blt-      .loc_0x8C
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xA4

	.loc_0x8C:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  lwz       r4, 0xC(r30)
	  li        r6, 0
	  li        r7, 0
	  bl        -0xBC7C

	.loc_0xA4:
	  lwz       r3, 0x2CC(r31)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x124
	  lwz       r0, 0x320(r31)
	  cmpwi     r0, 0x16
	  beq-      .loc_0xF4
	  bge-      .loc_0xD0
	  cmpwi     r0, 0x10
	  beq-      .loc_0xDC
	  b         .loc_0x108

	.loc_0xD0:
	  cmpwi     r0, 0x18
	  beq-      .loc_0x100
	  b         .loc_0x108

	.loc_0xDC:
	  mr        r3, r31
	  lwz       r4, -0x9D0(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl

	.loc_0xF4:
	  mr        r3, r31
	  bl        -0x629A4
	  b         .loc_0x108

	.loc_0x100:
	  mr        r3, r31
	  bl        -0x62BB4

	.loc_0x108:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x178(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x128

	.loc_0x124:
	  li        r3, 0

	.loc_0x128:
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A8858
 * Size:	000044
 */
void TAIAdyingCrushKabekui::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x340
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,26,24
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x2
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A889C
 * Size:	0000E0
 */
bool TAIAdamage::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r4
	  stw       r30, 0x58(r1)
	  mr        r30, r3
	  lfs       f0, -0x4A78(r2)
	  lfs       f1, 0x33C(r4)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x38
	  li        r3, 0
	  b         .loc_0xC8

	.loc_0x38:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x18C(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x8(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xC4
	  lwz       r4, 0x2C4(r31)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r4, 0x84(r4)
	  lwz       r12, 0x190(r12)
	  lwz       r4, 0x4(r4)
	  mtlr      r12
	  lwz       r4, 0x0(r4)
	  lfs       f2, 0x7C(r4)
	  lfs       f1, 0x78(r4)
	  blrl
	  lwz       r0, 0x320(r31)
	  cmpwi     r0, 0xF
	  beq-      .loc_0xB4
	  b         .loc_0xC4

	.loc_0xB4:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x40
	  bl        -0x11E3A8

	.loc_0xC4:
	  li        r3, 0x1

	.loc_0xC8:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A897C
 * Size:	000008
 */
bool TAIAdamage::judgeDamage(Teki&)
{
	return true;
}

/*
 * --INFO--
 * Address:	801A8984
 * Size:	000048
 */
bool TAIAinWater::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  lwz       r3, 0x28C(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x30
	  bl        -0x92924
	  cmpwi     r3, 0x5
	  bne-      .loc_0x30
	  li        r31, 0x1

	.loc_0x30:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A89CC
 * Size:	000068
 */
bool TAIAinWater::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x50
	  lwz       r5, 0x4(r4)
	  li        r4, 0x1
	  lfsu      f1, 0x94(r5)
	  lwz       r3, 0x2F00(r13)
	  lfs       f2, 0x8(r5)
	  bl        -0x140828
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  bl        -0x9298C
	  cmpwi     r3, 0x5
	  bne-      .loc_0x50
	  li        r31, 0x1

	.loc_0x50:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A8A34
 * Size:	000100
 */
bool TAIAinWaterDamage::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  li        r30, 0
	  stw       r29, 0x2C(r1)
	  mr        r29, r4
	  stw       r28, 0x28(r1)
	  addi      r28, r3, 0
	  lwz       r0, 0x28C(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x48
	  mr        r3, r0
	  bl        -0x929EC
	  cmpwi     r3, 0x5
	  bne-      .loc_0x48
	  li        r30, 0x1

	.loc_0x48:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0x6C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r28)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x58(r29)
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x58(r29)

	.loc_0x6C:
	  lbz       r0, 0xC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0xDC
	  lwz       r3, 0x28C(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0xD4
	  bl        -0x92A38
	  addi      r31, r3, 0
	  cmpwi     r31, 0x5
	  beq-      .loc_0x98
	  b         .loc_0xB4

	.loc_0x98:
	  lwz       r0, 0x474(r29)
	  cmpwi     r0, 0x5
	  beq-      .loc_0xCC
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        0xFC
	  b         .loc_0xCC

	.loc_0xB4:
	  lwz       r0, 0x474(r29)
	  cmpwi     r0, 0x5
	  bne-      .loc_0xCC
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        0xE0

	.loc_0xCC:
	  stw       r31, 0x474(r29)
	  b         .loc_0xDC

	.loc_0xD4:
	  li        r0, -0x1
	  stw       r0, 0x474(r29)

	.loc_0xDC:
	  mr        r3, r30
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
 * Address:	801A8B34
 * Size:	0000A8
 */
bool TAIAinWaterDamage::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  li        r31, 0
	  stw       r30, 0x40(r1)
	  mr        r30, r4
	  stw       r29, 0x3C(r1)
	  addi      r29, r3, 0
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x60
	  lwz       r5, 0x4(r30)
	  li        r4, 0x1
	  lfsu      f1, 0x94(r5)
	  lwz       r3, 0x2F00(r13)
	  lfs       f2, 0x8(r5)
	  bl        -0x1409A0
	  cmplwi    r3, 0
	  beq-      .loc_0x60
	  bl        -0x92B04
	  cmpwi     r3, 0x5
	  bne-      .loc_0x60
	  li        r31, 0x1

	.loc_0x60:
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x88
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x4(r30)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x58(r4)
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x58(r4)

	.loc_0x88:
	  mr        r3, r31
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A8BDC
 * Size:	000050
 */
void TAIAinWaterDamage::createEffect(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  addi      r5, r31, 0x94
	  lwz       r3, 0x3180(r13)
	  li        r4, 0xF
	  bl        -0xC0CC
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xA7
	  bl        -0x11E660
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
