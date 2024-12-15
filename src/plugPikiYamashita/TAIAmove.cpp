#include "TAI/Amove.h"
#include "nlib/Math.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "TAIAmove");
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
 * Address:	801A8C2C
 * Size:	000094
 */
void TAIAappearKabekui::start(Teki& teki)
{
	TAIAmotion::start(teki);
	teki.setMotionSpeed(mMotionSpeed);
	teki.set4C8(0);
	if (_10) {
		teki.setVisible();
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stfd      f31, 0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  bl        0x402C
	  mr        r3, r31
	  lfs       f31, 0xC(r30)
	  lwz       r12, 0x0(r31)
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  stfs      f31, 0x3B4(r31)
	  li        r3, 0
	  lbz       r0, 0x4C8(r31)
	  rlwimi    r0,r3,4,27,27
	  stb       r0, 0x4C8(r31)
	  lbz       r0, 0x10(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x78
	  mr        r3, r31
	  lwz       r4, -0x9D4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl

	.loc_0x78:
	  lwz       r0, 0x2C(r1)
	  lfd       f31, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A8CC0
 * Size:	0001A4
 */
bool TAIAappearKabekui::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x38(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x34(r1)
	  lwz       r3, 0x220(r4)
	  lis       r4, 0x6365
	  addi      r4, r4, 0x6E74
	  bl        -0x11F5DC
	  lfs       f0, -0x4A68(r2)
	  mr        r29, r3
	  li        r4, 0x1
	  stfs      f0, 0x20(r1)
	  stfs      f0, 0x1C(r1)
	  stfs      f0, 0x18(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x4(r29)
	  lfs       f2, 0xC(r29)
	  bl        -0x140E10
	  lfs       f0, 0x4(r29)
	  stfs      f0, 0x18(r1)
	  stfs      f1, 0x1C(r1)
	  lfs       f0, 0xC(r29)
	  stfs      f0, 0x20(r1)
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x98
	  lbz       r0, 0x4C8(r31)
	  li        r3, 0x1
	  rlwimi    r0,r3,4,27,27
	  stb       r0, 0x4C8(r31)
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x7F
	  bl        -0x11E7A0

	.loc_0x98:
	  lbz       r0, 0x4C8(r31)
	  rlwinm.   r0,r0,28,31,31
	  beq-      .loc_0x134
	  lwz       r3, 0x2CC(r31)
	  lfs       f0, -0x4A68(r2)
	  lfs       f1, 0x2C(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xC8
	  lfs       f0, -0x4A64(r2)
	  fadds     f0, f0, f1
	  b         .loc_0xD0

	.loc_0xC8:
	  lfs       f0, -0x4A64(r2)
	  fsubs     f0, f1, f0

	.loc_0xD0:
	  fctiwz    f0, f0
	  lis       r3, 0x9249
	  addi      r0, r3, 0x2493
	  stfd      f0, 0x28(r1)
	  lwz       r4, 0x2C(r1)
	  mulhw     r0, r0, r4
	  add       r0, r0, r4
	  srawi     r0, r0, 0x2
	  rlwinm    r3,r0,1,31,31
	  add       r0, r0, r3
	  mulli     r0, r0, 0x7
	  sub.      r0, r4, r0
	  bne-      .loc_0x134
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x18
	  li        r4, 0x32
	  li        r6, 0
	  li        r7, 0
	  bl        -0xC2A0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x18
	  li        r4, 0x33
	  li        r6, 0
	  li        r7, 0
	  bl        -0xC2B8

	.loc_0x134:
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x184
	  mr        r3, r31
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x10(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x17C
	  mr        r3, r31
	  lwz       r4, -0x9D4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl

	.loc_0x17C:
	  li        r3, 0x1
	  b         .loc_0x188

	.loc_0x184:
	  li        r3, 0

	.loc_0x188:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A8E64
 * Size:	000140
 */
void TAIAsetTargetPointWorkObject::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  mr        r30, r4
	  lwz       r31, 0x4BC(r4)
	  lfs       f0, 0x94(r4)
	  cmplwi    r31, 0
	  stfs      f0, 0x388(r30)
	  mr        r3, r31
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x38C(r30)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x390(r30)
	  beq-      .loc_0x124
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x124
	  lfs       f0, -0x4A68(r2)
	  mr        r4, r31
	  addi      r3, r1, 0x44
	  stfs      f0, 0x4C(r1)
	  stfs      f0, 0x48(r1)
	  stfs      f0, 0x44(r1)
	  bl        -0x10A31C
	  bl        0x6F194
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4A50(r2)
	  stw       r0, 0x54(r1)
	  lis       r0, 0x4330
	  lfs       f1, -0x4A5C(r2)
	  mr        r3, r31
	  stw       r0, 0x50(r1)
	  lfs       f0, -0x4A60(r2)
	  lfd       f2, 0x50(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f31, f0, f1
	  bl        -0x10A1F0
	  lfs       f0, -0x4A64(r2)
	  mr        r4, r31
	  lfs       f2, -0x4A58(r2)
	  addi      r3, r1, 0x2C
	  fsubs     f3, f31, f0
	  lfs       f0, 0x44(r1)
	  fmuls     f1, f1, f3
	  fmuls     f1, f2, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x48(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x4C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4C(r1)
	  bl        -0x10A338
	  lfs       f1, 0x2C(r1)
	  lfs       f0, 0x44(r1)
	  lfs       f3, 0x30(r1)
	  lfs       f2, 0x48(r1)
	  fadds     f0, f1, f0
	  lfs       f4, 0x34(r1)
	  lfs       f1, 0x4C(r1)
	  fadds     f2, f3, f2
	  stfs      f0, 0x388(r30)
	  fadds     f0, f4, f1
	  stfs      f2, 0x38C(r30)
	  stfs      f0, 0x390(r30)

	.loc_0x124:
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A8FA4
 * Size:	000008
 */
bool TAIAsetTargetPointWorkObject::act(Teki& teki) { return true; }

/*
 * --INFO--
 * Address:	801A8FAC
 * Size:	0001B0
 */
void TAIAgoGoalPath::makePath(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  stw       r30, 0x88(r1)
	  stw       r29, 0x84(r1)
	  mr        r29, r4
	  addi      r30, r29, 0x94
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r30
	  lfs       f1, -0x4A48(r2)
	  bl        -0xB64E4
	  mr.       r31, r3
	  beq-      .loc_0x9C
	  addi      r5, r31, 0x94
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  li        r6, 0x1
	  bl        -0x6061C
	  lwz       r0, 0x34C(r29)
	  cmpwi     r0, 0
	  ble-      .loc_0x80
	  lwz       r4, 0x470(r29)
	  mr        r3, r29
	  bl        -0x60490
	  lfs       f0, 0x0(r3)
	  stfs      f0, 0x388(r29)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x38C(r29)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x390(r29)
	  b         .loc_0xBC

	.loc_0x80:
	  lfs       f0, 0x0(r30)
	  stfs      f0, 0x388(r29)
	  lfs       f0, 0x4(r30)
	  stfs      f0, 0x38C(r29)
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x390(r29)
	  b         .loc_0xBC

	.loc_0x9C:
	  lfs       f0, 0x0(r30)
	  li        r0, 0x1
	  stfs      f0, 0x388(r29)
	  lfs       f0, 0x4(r30)
	  stfs      f0, 0x38C(r29)
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x390(r29)
	  stw       r0, 0x34C(r29)

	.loc_0xBC:
	  lwz       r0, 0x34C(r29)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x190
	  lfs       f3, 0x98(r31)
	  lfs       f4, 0x98(r29)
	  lfs       f2, 0x94(r29)
	  lfs       f1, 0x94(r31)
	  fsubs     f4, f4, f3
	  lfs       f3, 0x9C(r29)
	  fsubs     f5, f2, f1
	  lfs       f2, 0x9C(r31)
	  fmuls     f1, f4, f4
	  fsubs     f3, f3, f2
	  lfs       f0, -0x4A68(r2)
	  fmuls     f2, f5, f5
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x164
	  fsqrte    f1, f4
	  lfd       f3, -0x4A40(r2)
	  lfd       f2, -0x4A38(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x50(r1)
	  lfs       f4, 0x50(r1)

	.loc_0x164:
	  lwz       r3, 0x2C4(r29)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x3C(r3)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x188
	  li        r3, 0x1
	  b         .loc_0x194

	.loc_0x188:
	  li        r3, 0
	  b         .loc_0x194

	.loc_0x190:
	  li        r3, 0

	.loc_0x194:
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  lwz       r29, 0x84(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A915C
 * Size:	00004C
 */
void TAIAgoGoalPath::start(Teki& teki)
{
	teki._470 = 0;
	makePath(teki);
	TAIAgoTargetPriorityFaceDir::start(teki);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  stw       r0, 0x470(r4)
	  bl        -0x1D4
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x5D4
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
 * Address:	801A91A8
 * Size:	000118
 */
bool TAIAgoGoalPath::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  li        r31, 0
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r4, 0
	  bl        0x5CC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF8
	  lwz       r3, 0x470(r29)
	  addi      r0, r3, 0x1
	  stw       r0, 0x470(r29)
	  lwz       r4, 0x470(r29)
	  lwz       r0, 0x34C(r29)
	  cmpw      r4, r0
	  blt-      .loc_0x70
	  li        r0, 0
	  stw       r0, 0x470(r29)
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  bl        -0x258
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF8
	  li        r31, 0x1
	  b         .loc_0xF8

	.loc_0x70:
	  mr        r3, r29
	  bl        -0x606A0
	  lbz       r0, 0x38(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xA0
	  lfs       f0, 0x0(r3)
	  stfs      f0, 0x388(r29)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x38C(r29)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x390(r29)
	  b         .loc_0xF8

	.loc_0xA0:
	  lwz       r3, 0x470(r29)
	  subic.    r0, r3, 0x2
	  mr        r30, r0
	  blt-      .loc_0xD4
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0x606E4
	  lbz       r0, 0x38(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xD0
	  stw       r30, 0x470(r29)
	  b         .loc_0xD4

	.loc_0xD0:
	  li        r31, 0x1

	.loc_0xD4:
	  lwz       r4, 0x470(r29)
	  mr        r3, r29
	  bl        -0x60708
	  lfs       f0, 0x0(r3)
	  stfs      f0, 0x388(r29)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x38C(r29)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x390(r29)

	.loc_0xF8:
	  mr        r3, r31
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
 * Address:	801A92C0
 * Size:	0000EC
 */
bool TAIAgoGoalPath::checkArrival(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  mr        r30, r4
	  mr        r3, r30
	  lwz       r4, 0x470(r4)
	  bl        -0x60768
	  mr.       r31, r3
	  beq-      .loc_0xCC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, 0xC(r31)
	  lfs       f0, -0x4A68(r2)
	  fadds     f31, f2, f1
	  stfs      f0, 0x38(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x388(r30)
	  lfs       f4, 0x9C(r30)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x390(r30)
	  lfs       f2, 0x98(r30)
	  lfs       f1, 0x38C(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x28(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x30(r1)
	  stfs      f1, 0x34(r1)
	  stfs      f3, 0x38(r1)
	  lfs       f1, 0x30(r1)
	  lfs       f0, 0x34(r1)
	  lfs       f2, 0x38(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19B734
	  fcmpo     cr0, f1, f31
	  cror      2, 0, 0x2
	  mfcr      r0
	  rlwinm    r3,r0,3,31,31
	  b         .loc_0xD0

	.loc_0xCC:
	  li        r3, 0x1

	.loc_0xD0:
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A93AC
 * Size:	000100
 */
void TAIAsetTargetPointCircleRandom::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stfd      f30, 0x68(r1)
	  stw       r31, 0x64(r1)
	  stw       r30, 0x60(r1)
	  mr        r30, r4
	  bl        0x6ECA4
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C4(r30)
	  stw       r0, 0x5C(r1)
	  lis       r31, 0x4330
	  lwz       r3, 0x84(r3)
	  stw       r31, 0x58(r1)
	  lwz       r3, 0x4(r3)
	  lfd       f1, -0x4A50(r2)
	  lfd       f0, 0x58(r1)
	  lwz       r3, 0x0(r3)
	  fsubs     f2, f0, f1
	  lfs       f1, -0x4A5C(r2)
	  lfs       f0, -0x4A30(r2)
	  lfs       f31, 0x3C(r3)
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fmr       f30, f0
	  bl        0x6EC5C
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4A50(r2)
	  stw       r0, 0x54(r1)
	  fmr       f1, f30
	  lfs       f0, -0x4A5C(r2)
	  stw       r31, 0x50(r1)
	  lfd       f2, 0x50(r1)
	  fsubs     f2, f2, f3
	  fdivs     f0, f2, f0
	  fmuls     f31, f31, f0
	  bl        0x728A8
	  lwz       r3, 0x2C8(r30)
	  fmuls     f0, f31, f1
	  fmr       f1, f30
	  lfs       f2, 0x10(r3)
	  fadds     f30, f2, f0
	  bl        0x726FC
	  lwz       r4, 0x2C8(r30)
	  fmuls     f0, f31, f1
	  fmr       f1, f30
	  lwz       r3, 0x2F00(r13)
	  lfs       f2, 0x18(r4)
	  li        r4, 0x1
	  fadds     f31, f2, f0
	  fmr       f2, f31
	  bl        -0x141578
	  stfs      f30, 0x388(r30)
	  stfs      f1, 0x38C(r30)
	  stfs      f31, 0x390(r30)
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lfd       f30, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A94AC
 * Size:	000008
 */
bool TAIAsetTargetPointCircleRandom::act(Teki& teki) { return true; }

/*
 * --INFO--
 * Address:	801A94B4
 * Size:	000020
 */
void TAIAsetTargetPointCircle::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x38
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A94D4
 * Size:	000024
 */
bool TAIAsetTargetPointCircle::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        .loc_0x24
	  li        r3, 0x1
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x24:
	*/
}

/*
 * --INFO--
 * Address:	801A94F8
 * Size:	000110
 */
void TAIAsetTargetPointCircle::setTargetPoint(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  addi      r30, r4, 0
	  addi      r31, r30, 0x94
	  stw       r29, 0x54(r1)
	  addi      r29, r3, 0
	  lfs       f31, 0x8(r3)
	  bl        0x6EB48
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C8(r30)
	  stw       r0, 0x4C(r1)
	  lis       r0, 0x4330
	  lfd       f1, -0x4A50(r2)
	  stw       r0, 0x48(r1)
	  lfs       f4, -0x4A5C(r2)
	  lfd       f0, 0x48(r1)
	  lfs       f3, 0x0(r31)
	  fsubs     f5, f0, f1
	  lfs       f1, 0x10(r3)
	  lfs       f2, 0x8(r31)
	  lfs       f0, 0x18(r3)
	  fsubs     f1, f3, f1
	  fdivs     f3, f5, f4
	  fmuls     f31, f31, f3
	  fsubs     f2, f2, f0
	  bl        -0x8B768
	  lfs       f0, 0x8(r29)
	  lwz       r3, 0x2C4(r30)
	  fadds     f0, f0, f31
	  lwz       r3, 0x84(r3)
	  fadds     f30, f0, f1
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  fmr       f1, f30
	  lfs       f31, 0x40(r3)
	  bl        0x72750
	  lwz       r3, 0x2C8(r30)
	  fmuls     f0, f31, f1
	  fmr       f1, f30
	  lfs       f2, 0x10(r3)
	  fadds     f30, f2, f0
	  bl        0x725A4
	  lwz       r4, 0x2C8(r30)
	  fmuls     f0, f31, f1
	  fmr       f1, f30
	  lwz       r3, 0x2F00(r13)
	  lfs       f2, 0x18(r4)
	  li        r4, 0x1
	  fadds     f31, f2, f0
	  fmr       f2, f31
	  bl        -0x1416D0
	  stfs      f30, 0x388(r30)
	  stfs      f1, 0x38C(r30)
	  stfs      f31, 0x390(r30)
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A9608
 * Size:	000038
 */
void TAIAgoTarget::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x36E8
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,22,20
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
 * Address:	801A9640
 * Size:	000108
 */
bool TAIAgoTarget::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  li        r31, 0
	  stw       r30, 0x70(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x6C(r1)
	  addi      r29, r3, 0
	  bl        0x3854
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE8
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x60(r1)
	  stfs      f0, 0x5C(r1)
	  stfs      f0, 0x58(r1)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x388(r30)
	  lfs       f4, 0x9C(r30)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x390(r30)
	  lfs       f2, 0x98(r30)
	  lfs       f1, 0x38C(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x50(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x58(r1)
	  stfs      f1, 0x5C(r1)
	  stfs      f3, 0x60(r1)
	  lfs       f1, 0x58(r1)
	  lfs       f0, 0x5C(r1)
	  lfs       f2, 0x60(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19BA98
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xC(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xC4
	  li        r31, 0x1
	  b         .loc_0xE8

	.loc_0xC4:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r30
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0
	  addi      r4, r30, 0x388
	  bl        -0x62334

	.loc_0xE8:
	  mr        r3, r31
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A9748
 * Size:	000018
 */
f32 TAIAgoTarget::getVelocity(Teki& teki)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A9760
 * Size:	000038
 */
void TAIAgoTargetPriorityFaceDir::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x3590
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
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
 * Address:	801A9798
 * Size:	00009C
 */
bool TAIAgoTargetPriorityFaceDir::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        0x36FC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7C
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r30
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x58
	  li        r31, 0x1
	  b         .loc_0x7C

	.loc_0x58:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r30
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0
	  addi      r4, r30, 0x388
	  bl        -0x6D48

	.loc_0x7C:
	  mr        r3, r31
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
 * Address:	801A9834
 * Size:	0000B8
 */
bool TAIAgoTargetPriorityFaceDir::checkArrival(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r4
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x60(r1)
	  stfs      f0, 0x5C(r1)
	  stfs      f0, 0x58(r1)
	  lfs       f1, 0x94(r4)
	  lfs       f0, 0x388(r4)
	  lfs       f4, 0x9C(r4)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x390(r4)
	  lfs       f2, 0x98(r4)
	  lfs       f1, 0x38C(r4)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x50(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x58(r1)
	  stfs      f1, 0x5C(r1)
	  stfs      f3, 0x60(r1)
	  lfs       f1, 0x58(r1)
	  lfs       f0, 0x5C(r1)
	  lfs       f2, 0x60(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19BC70
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xC(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  mfcr      r0
	  rlwinm    r3,r0,3,31,31
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A98EC
 * Size:	000018
 */
f32 TAIAgoTargetPriorityFaceDir::getWalkVelocity(Teki& teki)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A9904
 * Size:	000038
 */
void TAIAapproachTargetPriorityFaceDir::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x33EC
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
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
 * Address:	801A993C
 * Size:	000088
 */
bool TAIAapproachTargetPriorityFaceDir::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  bl        0x3560
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x6C
	  lwz       r5, 0x418(r30)
	  cmplwi    r5, 0
	  beq-      .loc_0x64
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  addi      r4, r30, 0
	  addi      r31, r5, 0x94
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x6ECC
	  li        r3, 0
	  b         .loc_0x70

	.loc_0x64:
	  li        r3, 0x1
	  b         .loc_0x70

	.loc_0x6C:
	  li        r3, 0

	.loc_0x70:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A99C4
 * Size:	000018
 */
f32 TAIAapproachTargetPriorityFaceDir::getVelocity(Teki& teki)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void TAIAlookAround::setTargetDirection(Teki&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A99DC
 * Size:	0000DC
 */
void TAIAlookAround::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  bl        0x3310
	  lfs       f0, -0x4A68(r2)
	  li        r0, 0x2
	  stfs      f0, 0x478(r31)
	  stw       r0, 0x46C(r31)
	  bl        0x6E668
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4A50(r2)
	  stw       r0, 0x24(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x4A5C(r2)
	  stw       r0, 0x20(r1)
	  lfs       f1, -0x4A2C(r2)
	  lfd       f3, 0x20(r1)
	  lfs       f0, -0x4A28(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x70
	  lfs       f31, -0x4A60(r2)
	  b         .loc_0x74

	.loc_0x70:
	  lfs       f31, -0x4A24(r2)

	.loc_0x74:
	  bl        0x6E620
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4A50(r2)
	  stw       r0, 0x24(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x4A5C(r2)
	  stw       r0, 0x20(r1)
	  lfs       f0, -0x4A20(r2)
	  lfd       f3, 0x20(r1)
	  lfs       f1, 0xA0(r31)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f2, f0, f2
	  fadds     f0, f0, f2
	  fmuls     f0, f0, f31
	  fadds     f0, f1, f0
	  stfs      f0, 0x394(r31)
	  lfs       f1, 0x394(r31)
	  bl        -0x171510
	  stfs      f1, 0x394(r31)
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A9AB8
 * Size:	00031C
 */
bool TAIAlookAround::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stw       r31, 0xC4(r1)
	  mr        r31, r4
	  stw       r30, 0xC0(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x46C(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x178
	  bge-      .loc_0x3C
	  cmpwi     r0, 0
	  bge-      .loc_0x64
	  b         .loc_0x2FC

	.loc_0x3C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x2FC
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x33B4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2FC
	  li        r0, 0x1
	  stw       r0, 0x46C(r31)
	  b         .loc_0x2FC

	.loc_0x64:
	  lfs       f1, 0x394(r31)
	  lfs       f2, 0xA0(r31)
	  bl        -0x171570
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x84
	  lwz       r30, 0xC(r30)
	  b         .loc_0x88

	.loc_0x84:
	  lwz       r30, 0x10(r30)

	.loc_0x88:
	  lwz       r3, 0x2CC(r31)
	  lwz       r0, 0x44(r3)
	  cmpw      r30, r0
	  bne-      .loc_0xA4
	  lbz       r0, 0x48(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x114

	.loc_0xA4:
	  lbz       r0, 0x48(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xD8
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0xC0
	  lwz       r5, 0x2C0(r31)

	.loc_0xC0:
	  addi      r3, r1, 0xA8
	  li        r4, -0x1
	  bl        -0x8ABF4
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8A95C

	.loc_0xD8:
	  lwz       r3, 0x2CC(r31)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x2FC
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0xF8
	  lwz       r5, 0x2C0(r31)

	.loc_0xF8:
	  addi      r4, r30, 0
	  addi      r3, r1, 0xA0
	  bl        -0x8AC2C
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8AA04
	  b         .loc_0x2FC

	.loc_0x114:
	  lwz       r4, 0x2C4(r31)
	  mr        r3, r31
	  lfs       f1, 0x394(r31)
	  lwz       r4, 0x84(r4)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f2, 0x14(r4)
	  bl        -0x6261C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2FC
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x14C
	  lwz       r5, 0x2C0(r31)

	.loc_0x14C:
	  addi      r3, r1, 0x98
	  li        r4, -0x1
	  bl        -0x8AC80
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8A9E8
	  lfs       f0, -0x4A68(r2)
	  li        r0, 0x1
	  stfs      f0, 0x478(r31)
	  stw       r0, 0x46C(r31)
	  b         .loc_0x2FC

	.loc_0x178:
	  lwz       r4, 0x2CC(r31)
	  lwz       r0, 0x8(r30)
	  lwz       r3, 0x44(r4)
	  cmpw      r0, r3
	  bne-      .loc_0x198
	  lbz       r0, 0x48(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x208

	.loc_0x198:
	  lbz       r0, 0x48(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x1CC
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x1B4
	  lwz       r5, 0x2C0(r31)

	.loc_0x1B4:
	  addi      r3, r1, 0x90
	  li        r4, -0x1
	  bl        -0x8ACE8
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8AA50

	.loc_0x1CC:
	  lwz       r3, 0x2CC(r31)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x2FC
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x1EC
	  lwz       r5, 0x2C0(r31)

	.loc_0x1EC:
	  lwz       r4, 0x8(r30)
	  addi      r3, r1, 0x88
	  bl        -0x8AD20
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8AAF8
	  b         .loc_0x2FC

	.loc_0x208:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x478(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x478(r31)
	  lfs       f1, 0x478(r31)
	  lfs       f0, -0x4A1C(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2FC
	  lfs       f0, -0x4A68(r2)
	  li        r0, 0
	  stfs      f0, 0x478(r31)
	  stw       r0, 0x46C(r31)
	  bl        0x6E37C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4A50(r2)
	  stw       r0, 0xBC(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x4A5C(r2)
	  stw       r0, 0xB8(r1)
	  lfs       f1, -0x4A2C(r2)
	  lfd       f3, 0xB8(r1)
	  lfs       f0, -0x4A28(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x280
	  lfs       f31, -0x4A60(r2)
	  b         .loc_0x284

	.loc_0x280:
	  lfs       f31, -0x4A24(r2)

	.loc_0x284:
	  bl        0x6E334
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4A50(r2)
	  stw       r0, 0xBC(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x4A5C(r2)
	  stw       r0, 0xB8(r1)
	  lfs       f0, -0x4A20(r2)
	  lfd       f3, 0xB8(r1)
	  lfs       f1, 0xA0(r31)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f2, f0, f2
	  fadds     f0, f0, f2
	  fmuls     f0, f0, f31
	  fadds     f0, f1, f0
	  stfs      f0, 0x394(r31)
	  lfs       f1, 0x394(r31)
	  bl        -0x1717FC
	  cmplwi    r31, 0
	  stfs      f1, 0x394(r31)
	  mr        r5, r31
	  beq-      .loc_0x2E4
	  lwz       r5, 0x2C0(r31)

	.loc_0x2E4:
	  addi      r3, r1, 0x80
	  li        r4, -0x1
	  bl        -0x8AE18
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8AB80

	.loc_0x2FC:
	  lwz       r0, 0xD4(r1)
	  li        r3, 0
	  lfd       f31, 0xC8(r1)
	  lwz       r31, 0xC4(r1)
	  lwz       r30, 0xC0(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
int TAIAturnToTarget::getTurnMotionIndex(Teki& teki)
{
	Vector3f direction;
	direction.sub2(teki.mTargetPosition, teki.mPosition);
	teki.mTargetAngle = NMathF::atan2Vec(direction);

	if (angDist(teki.mTargetAngle, teki.mDirection) > 0.0f) {
		return mLeftTurnAnimID;
	} else {
		return mRightTurnAnimID;
	}
}

/*
 * --INFO--
 * Address:	801A9DD4
 * Size:	0000CC
 */
void TAIAturnToTarget::start(Teki& teki)
{
	teki.setCreatureFlag(CF_Unk11);
	mMotionID = getTurnMotionIndex(teki);
	// Vector3f vec;
	// vec = teki._388 - teki.mPosition;
	// teki._394 = NMathF::atan2(vec.x, vec.z);
	// mMotionID = (angDist(teki._394, teki.mDirection) > 0.0f) ? _0C : _10;
	TAIAreserveMotion::start(teki);

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0xC8(r4)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r4)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x38(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  lfs       f1, 0x388(r4)
	  lfs       f0, 0x94(r4)
	  lfs       f4, 0x390(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r31)
	  lfs       f2, 0x38C(r31)
	  lfs       f1, 0x98(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x28(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x30(r1)
	  stfs      f1, 0x34(r1)
	  stfs      f3, 0x38(r1)
	  lfs       f1, 0x30(r1)
	  lfs       f2, 0x38(r1)
	  bl        -0x8C044
	  stfs      f1, 0x394(r31)
	  lfs       f1, 0x394(r31)
	  lfs       f2, 0xA0(r31)
	  bl        -0x1718A8
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xA0
	  lwz       r0, 0xC(r30)
	  b         .loc_0xA4

	.loc_0xA0:
	  lwz       r0, 0x10(r30)

	.loc_0xA4:
	  stw       r0, 0x8(r30)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x2E80
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
 * Address:	801A9EA0
 * Size:	0001E8
 */
bool TAIAturnToTarget::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  mr        r31, r4
	  stw       r30, 0x78(r1)
	  li        r30, 0
	  stw       r29, 0x74(r1)
	  stw       r28, 0x70(r1)
	  mr        r28, r3
	  lfs       f1, 0x394(r4)
	  lfs       f2, 0xA0(r4)
	  bl        -0x17191C
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x48
	  lwz       r0, 0xC(r28)
	  b         .loc_0x4C

	.loc_0x48:
	  lwz       r0, 0x10(r28)

	.loc_0x4C:
	  lwz       r4, 0x2CC(r31)
	  mr        r29, r0
	  lwz       r3, 0x44(r4)
	  cmpw      r0, r3
	  bne-      .loc_0x6C
	  lbz       r0, 0x48(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xDC

	.loc_0x6C:
	  lbz       r0, 0x48(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0xA0
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x88
	  lwz       r5, 0x2C0(r31)

	.loc_0x88:
	  addi      r3, r1, 0x64
	  li        r4, -0x1
	  bl        -0x8AFA4
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8AD0C

	.loc_0xA0:
	  lwz       r3, 0x2CC(r31)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x1C4
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0xC0
	  lwz       r5, 0x2C0(r31)

	.loc_0xC0:
	  addi      r4, r29, 0
	  addi      r3, r1, 0x5C
	  bl        -0x8AFDC
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8ADB4
	  b         .loc_0x1C4

	.loc_0xDC:
	  lfs       f0, 0x1578(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x157C(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x1580(r13)
	  stfs      f0, 0xAC(r31)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x3C(r1)
	  stfs      f0, 0x38(r1)
	  stfs      f0, 0x34(r1)
	  lfs       f1, 0x388(r31)
	  lfs       f0, 0x94(r31)
	  lfs       f4, 0x390(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r31)
	  lfs       f2, 0x38C(r31)
	  lfs       f1, 0x98(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x2C(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x2C(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f3, 0x3C(r1)
	  lfs       f1, 0x34(r1)
	  lfs       f2, 0x3C(r1)
	  bl        -0x8C1DC
	  stfs      f1, 0x394(r31)
	  lwz       r3, 0x2CC(r31)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  blt-      .loc_0x1C4
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  fmr       f2, f1
	  lfs       f1, 0x394(r31)
	  mr        r3, r31
	  bl        -0x62A54
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C4
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C0
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x1A8
	  lwz       r5, 0x2C0(r31)

	.loc_0x1A8:
	  addi      r3, r1, 0x54
	  li        r4, -0x1
	  bl        -0x8B0C4
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8AE2C

	.loc_0x1C0:
	  li        r30, 0x1

	.loc_0x1C4:
	  mr        r3, r30
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  lwz       r29, 0x74(r1)
	  lwz       r28, 0x70(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AA088
 * Size:	000078
 */
void TAIAstop::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r13, 0x1570
	  stw       r0, 0x4(r1)
	  addi      r6, r13, 0x1574
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  addi      r3, r1, 0x1C
	  addi      r4, r13, 0x156C
	  bl        -0x172F90
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x1C
	  addi      r5, r1, 0x20
	  addi      r6, r1, 0x24
	  bl        -0x14CA34
	  addi      r3, r1, 0x10
	  addi      r4, r13, 0x1560
	  addi      r5, r13, 0x1564
	  addi      r6, r13, 0x1568
	  bl        -0x172FB8
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x10
	  addi      r5, r1, 0x14
	  addi      r6, r1, 0x18
	  bl        -0x14CA5C
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AA100
 * Size:	00005C
 */
void TAIArandomWalk::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  bl        0x2BE8
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x11C
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,22,20
	  stw       r0, 0xC8(r31)
	  lfs       f0, -0x4A18(r2)
	  lwz       r3, 0x224(r31)
	  stfs      f0, 0x30(r3)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AA15C
 * Size:	0000E8
 */
bool TAIArandomWalk::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stw       r31, 0x94(r1)
	  li        r31, 0
	  stw       r30, 0x90(r1)
	  addi      r30, r4, 0
	  bl        0x2D40
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xCC
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x84(r1)
	  stfs      f0, 0x80(r1)
	  stfs      f0, 0x7C(r1)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x388(r30)
	  lfs       f4, 0x9C(r30)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x390(r30)
	  lfs       f2, 0x98(r30)
	  lfs       f1, 0x38C(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x74(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x74(r1)
	  stfs      f0, 0x7C(r1)
	  stfs      f1, 0x80(r1)
	  stfs      f3, 0x84(r1)
	  lfs       f1, 0x7C(r1)
	  lfs       f0, 0x80(r1)
	  lfs       f2, 0x84(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19C5AC
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xC(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xBC
	  li        r31, 0x1
	  b         .loc_0xCC

	.loc_0xBC:
	  fmr       f1, f0
	  addi      r3, r30, 0
	  addi      r4, r30, 0x388
	  bl        -0x62E34

	.loc_0xCC:
	  mr        r3, r31
	  lwz       r0, 0x9C(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AA244
 * Size:	000100
 */
void TAIArandomWalk::makeTargetPosition(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stfd      f30, 0x68(r1)
	  stfd      f29, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  mr        r30, r4
	  bl        0x6DE08
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4A50(r2)
	  stw       r0, 0x54(r1)
	  lis       r31, 0x4330
	  lfs       f3, -0x4A5C(r2)
	  stw       r31, 0x50(r1)
	  lfs       f2, -0x4A60(r2)
	  lfd       f1, 0x50(r1)
	  lfs       f0, -0x4A14(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x1CA4(r13)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f30, f1, f0
	  bl        0x6DDC8
	  xoris     r0, r3, 0x8000
	  lfd       f5, -0x4A50(r2)
	  stw       r0, 0x4C(r1)
	  fmr       f1, f30
	  lfs       f3, -0x4A5C(r2)
	  stw       r31, 0x48(r1)
	  lfs       f2, -0x4A60(r2)
	  lfd       f4, 0x48(r1)
	  lfs       f0, -0x4A10(r2)
	  fsubs     f4, f4, f5
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f29, f0, f2
	  bl        0x71874
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0x719FC
	  fmuls     f0, f29, f1
	  lfs       f1, 0x94(r30)
	  lfs       f2, 0x98(r30)
	  fmuls     f3, f29, f31
	  lfs       f4, 0x9C(r30)
	  fadds     f0, f1, f0
	  lfs       f1, 0x1584(r13)
	  fadds     f3, f4, f3
	  fadds     f1, f2, f1
	  stfs      f0, 0x388(r30)
	  stfs      f1, 0x38C(r30)
	  stfs      f3, 0x390(r30)
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lfd       f30, 0x68(r1)
	  lfd       f29, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AA344
 * Size:	000020
 */
void TAIAturnOccasion::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x29B4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AA364
 * Size:	0000B4
 */
bool TAIAturnOccasion::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r4
	  bl        0x2B40
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9C
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x58(r1)
	  stfs      f0, 0x54(r1)
	  stfs      f0, 0x50(r1)
	  lfs       f1, 0x388(r31)
	  lfs       f0, 0x94(r31)
	  lfs       f4, 0x390(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r31)
	  lfs       f2, 0x38C(r31)
	  lfs       f1, 0x98(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x4C(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x4C(r1)
	  stfs      f0, 0x50(r1)
	  stfs      f1, 0x54(r1)
	  stfs      f3, 0x58(r1)
	  lfs       f1, 0x50(r1)
	  lfs       f2, 0x58(r1)
	  bl        -0x8C5CC
	  stfs      f1, 0x394(r31)
	  mr        r3, r31
	  lwz       r4, 0x2C4(r31)
	  lfs       f1, 0x394(r31)
	  lwz       r4, 0x84(r4)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f2, 0x14(r4)
	  bl        -0x62E2C
	  b         .loc_0xA0

	.loc_0x9C:
	  li        r3, 0

	.loc_0xA0:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AA418
 * Size:	000118
 */
void TAIAturnFocusCreature::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r4
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  lwz       r4, 0x418(r4)
	  cmplwi    r4, 0
	  beq-      .loc_0x88
	  lfs       f0, -0x4A68(r2)
	  addi      r3, r4, 0x94
	  stfs      f0, 0x40(r1)
	  stfs      f0, 0x3C(r1)
	  stfs      f0, 0x38(r1)
	  lfs       f1, 0x94(r4)
	  lfs       f0, 0x94(r31)
	  lfs       f4, 0x8(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r31)
	  lfs       f2, 0x4(r3)
	  lfs       f1, 0x98(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x2C(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x2C(r1)
	  stfs      f0, 0x38(r1)
	  stfs      f1, 0x3C(r1)
	  stfs      f3, 0x40(r1)
	  lfs       f1, 0x38(r1)
	  lfs       f2, 0x40(r1)
	  bl        -0x8C68C
	  stfs      f1, 0x394(r31)
	  b         .loc_0x90

	.loc_0x88:
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x394(r31)

	.loc_0x90:
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,22,20
	  stw       r0, 0xC8(r31)
	  lfs       f1, 0x394(r31)
	  lfs       f2, 0xA0(r31)
	  bl        -0x171F08
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xBC
	  lwz       r0, 0xC(r30)
	  b         .loc_0xC0

	.loc_0xBC:
	  lwz       r0, 0x10(r30)

	.loc_0xC0:
	  stw       r0, 0x8(r30)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x2820
	  lfs       f0, 0x1588(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x158C(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x1590(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r3, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AA530
 * Size:	000078
 */
bool TAIAturnFocusCreature::act(Teki& teki)
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
	  lwz       r4, 0x418(r4)
	  cmplwi    r4, 0
	  beq-      .loc_0x5C
	  addi      r4, r4, 0x94
	  addi      r3, r1, 0x10
	  bl        -0x8D6E0
	  lwz       r5, 0x0(r3)
	  mr        r4, r31
	  lwz       r0, 0x4(r3)
	  stw       r5, 0x388(r31)
	  stw       r0, 0x38C(r31)
	  lwz       r0, 0x8(r3)
	  mr        r3, r30
	  stw       r0, 0x390(r31)
	  bl        -0x6E4
	  b         .loc_0x60

	.loc_0x5C:
	  li        r3, 0x1

	.loc_0x60:
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
 * Address:	801AA5A8
 * Size:	000084
 */
void TAIAwait::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  bl        0x2748
	  addi      r3, r1, 0x1C
	  addi      r4, r13, 0x156C
	  addi      r5, r13, 0x1570
	  addi      r6, r13, 0x1574
	  bl        -0x1734B4
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x1C
	  addi      r5, r1, 0x20
	  addi      r6, r1, 0x24
	  bl        -0x14CF58
	  addi      r3, r1, 0x10
	  addi      r4, r13, 0x1560
	  addi      r5, r13, 0x1564
	  addi      r6, r13, 0x1568
	  bl        -0x1734DC
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x10
	  addi      r5, r1, 0x14
	  addi      r6, r1, 0x18
	  bl        -0x14CF80
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x478(r31)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AA62C
 * Size:	000098
 */
bool TAIAwait::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  stw       r31, 0x34(r1)
	  li        r31, 0
	  stw       r30, 0x30(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x2C(r1)
	  addi      r29, r3, 0
	  bl        0x2864
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r29
	  lfs       f1, 0x478(r30)
	  mr        r4, r30
	  lfs       f0, 0x28C(r5)
	  fadds     f31, f1, f0
	  stfs      f31, 0x478(r30)
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x74
	  lfs       f0, -0x4A68(r2)
	  li        r31, 0x1
	  stfs      f0, 0x478(r30)

	.loc_0x74:
	  mr        r3, r31
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AA6C4
 * Size:	000008
 */
f32 TAIAwait::getWaitCounterMax(Teki& teki)
{
	/*
	.loc_0x0:
	  lfs       f1, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void TAIApatrol::changeStatus(int, Teki& teki)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801AA6CC
 * Size:	00007C
 */
TAIApatrol::TAIApatrol(int, int, int, int, Vector3f*, int, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r25, 0x2C(r1)
	  addi      r27, r6, 0
	  addi      r26, r5, 0
	  addi      r25, r3, 0
	  addi      r28, r7, 0
	  addi      r29, r8, 0
	  addi      r30, r9, 0
	  addi      r31, r10, 0
	  addi      r5, r27, 0
	  bl        0x25E4
	  lis       r3, 0x802E
	  subi      r0, r3, 0x6D0
	  stw       r0, 0x4(r25)
	  lis       r3, 0x802E
	  subi      r0, r3, 0x818
	  stw       r27, 0xC(r25)
	  mr        r3, r25
	  stw       r28, 0x10(r25)
	  stb       r31, 0x14(r25)
	  stw       r0, 0x4(r25)
	  stw       r26, 0x20(r25)
	  stw       r29, 0x18(r25)
	  stw       r30, 0x1C(r25)
	  lwz       r0, 0x4C(r1)
	  lmw       r25, 0x2C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void TAIApatrol::setTargetPosition(Teki& teki)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801AA748
 * Size:	0002B0
 */
void TAIApatrol::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stw       r31, 0xAC(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xA8(r1)
	  addi      r30, r3, 0
	  stw       r29, 0xA4(r1)
	  stw       r28, 0xA0(r1)
	  li        r28, 0
	  stw       r0, 0x470(r4)
	  lfs       f30, -0x4A68(r2)
	  b         .loc_0x118

	.loc_0x40:
	  lwz       r0, 0x470(r31)
	  li        r4, 0xF
	  lwz       r3, 0x2C4(r31)
	  mulli     r0, r0, 0xC
	  lwz       r5, 0x18(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  add       r29, r5, r0
	  bl        -0x882D4
	  lfs       f0, 0x0(r29)
	  lwz       r3, 0x2C8(r31)
	  lfs       f3, 0x4(r29)
	  fmuls     f0, f0, f1
	  lfs       f2, 0x10(r3)
	  lfs       f5, 0x8(r29)
	  fmuls     f3, f3, f1
	  lfs       f4, 0x14(r3)
	  fadds     f0, f2, f0
	  lfs       f2, 0x18(r3)
	  fmuls     f1, f5, f1
	  fadds     f3, f4, f3
	  stfs      f0, 0x388(r31)
	  fadds     f0, f2, f1
	  stfs      f3, 0x38C(r31)
	  stfs      f0, 0x390(r31)
	  stfs      f30, 0x478(r31)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0x38C(r31)
	  fsubs     f2, f1, f0
	  fcmpo     cr0, f2, f30
	  bge-      .loc_0xC0
	  fneg      f2, f2

	.loc_0xC0:
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x388(r31)
	  fsubs     f3, f1, f0
	  fcmpo     cr0, f3, f30
	  bge-      .loc_0xD8
	  fneg      f3, f3

	.loc_0xD8:
	  lfs       f1, 0x9C(r31)
	  lfs       f0, 0x390(r31)
	  fsubs     f1, f1, f0
	  fcmpo     cr0, f1, f30
	  bge-      .loc_0xF0
	  fneg      f1, f1

	.loc_0xF0:
	  fadds     f0, f3, f2
	  cmpwi     r28, 0
	  fadds     f0, f1, f0
	  bne-      .loc_0x108
	  fmr       f31, f0
	  b         .loc_0x114

	.loc_0x108:
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x114
	  stw       r28, 0x470(r31)

	.loc_0x114:
	  addi      r28, r28, 0x1

	.loc_0x118:
	  lwz       r0, 0x1C(r30)
	  cmpw      r28, r0
	  blt+      .loc_0x40
	  lwz       r0, 0x470(r31)
	  li        r4, 0xF
	  lwz       r3, 0x2C4(r31)
	  mulli     r0, r0, 0xC
	  lwz       r5, 0x18(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  add       r29, r5, r0
	  bl        -0x883B8
	  lfs       f0, 0x0(r29)
	  addi      r6, r1, 0x70
	  lwz       r3, 0x2C8(r31)
	  addi      r5, r1, 0x6C
	  lfs       f3, 0x4(r29)
	  fmuls     f0, f0, f1
	  lfs       f2, 0x10(r3)
	  lfs       f5, 0x8(r29)
	  fmuls     f3, f3, f1
	  lfs       f4, 0x14(r3)
	  fadds     f0, f2, f0
	  lfs       f2, 0x18(r3)
	  fmuls     f1, f5, f1
	  addi      r4, r1, 0x68
	  fadds     f3, f4, f3
	  stfs      f0, 0x388(r31)
	  fadds     f0, f2, f1
	  addi      r3, r1, 0x80
	  stfs      f3, 0x38C(r31)
	  stfs      f0, 0x390(r31)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x478(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  stfs      f0, 0x88(r1)
	  stfs      f0, 0x84(r1)
	  stfs      f0, 0x80(r1)
	  lfs       f1, 0x390(r31)
	  lfs       f0, 0x9C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  lfs       f1, 0x38C(r31)
	  lfs       f0, 0x98(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x6C(r1)
	  lfs       f1, 0x388(r31)
	  lfs       f0, 0x94(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x68(r1)
	  bl        -0x14D2A4
	  lfs       f1, 0x80(r1)
	  lfs       f2, 0x88(r1)
	  bl        -0x8CB34
	  stfs      f1, 0x394(r31)
	  lfs       f1, 0x394(r31)
	  lfs       f2, 0xA0(r31)
	  bl        -0x172398
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x21C
	  lwz       r0, 0xC(r30)
	  b         .loc_0x220

	.loc_0x21C:
	  lwz       r0, 0x10(r30)

	.loc_0x220:
	  stw       r0, 0x8(r30)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x2390
	  li        r0, 0x1
	  stw       r0, 0x46C(r31)
	  lwz       r0, 0x46C(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x254
	  bge-      .loc_0x288
	  cmpwi     r0, 0
	  bge-      .loc_0x27C
	  b         .loc_0x288

	.loc_0x254:
	  lfs       f0, 0x1594(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x1598(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x159C(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  b         .loc_0x288

	.loc_0x27C:
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,22,20
	  stw       r0, 0xC8(r31)

	.loc_0x288:
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lwz       r31, 0xAC(r1)
	  lwz       r30, 0xA8(r1)
	  lwz       r29, 0xA4(r1)
	  lwz       r28, 0xA0(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AA9F8
 * Size:	000354
 */
bool TAIApatrol::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x108(r1)
	  stfd      f31, 0x100(r1)
	  stw       r31, 0xFC(r1)
	  mr        r31, r4
	  stw       r30, 0xF8(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x46C(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x3C
	  bge-      .loc_0x334
	  cmpwi     r0, 0
	  bge-      .loc_0xAC
	  b         .loc_0x334

	.loc_0x3C:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0xB9C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x334
	  li        r0, 0
	  stw       r0, 0x46C(r31)
	  lwz       r0, 0x46C(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x74
	  bge-      .loc_0x334
	  cmpwi     r0, 0
	  bge-      .loc_0x9C
	  b         .loc_0x334

	.loc_0x74:
	  lfs       f0, 0x1594(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x1598(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x159C(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  b         .loc_0x334

	.loc_0x9C:
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,22,20
	  stw       r0, 0xC8(r31)
	  b         .loc_0x334

	.loc_0xAC:
	  lwz       r4, 0x2CC(r31)
	  lwz       r0, 0x20(r30)
	  lwz       r3, 0x44(r4)
	  cmpw      r0, r3
	  bne-      .loc_0xCC
	  lbz       r0, 0x48(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x13C

	.loc_0xCC:
	  lbz       r0, 0x48(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x100
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0xE8
	  lwz       r5, 0x2C0(r31)

	.loc_0xE8:
	  addi      r3, r1, 0xEC
	  li        r4, -0x1
	  bl        -0x8BB5C
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8B8C4

	.loc_0x100:
	  lwz       r3, 0x2CC(r31)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x334
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x120
	  lwz       r5, 0x2C0(r31)

	.loc_0x120:
	  lwz       r4, 0x20(r30)
	  addi      r3, r1, 0xE4
	  bl        -0x8BB94
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8B96C
	  b         .loc_0x334

	.loc_0x13C:
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0xC8(r1)
	  stfs      f0, 0xC4(r1)
	  stfs      f0, 0xC0(r1)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x388(r31)
	  lfs       f4, 0x9C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x390(r31)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x38C(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0xA8(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0xA8(r1)
	  stfs      f0, 0xC0(r1)
	  stfs      f1, 0xC4(r1)
	  stfs      f3, 0xC8(r1)
	  lfs       f1, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  lfs       f2, 0xC8(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19CF5C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x478(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f2, f0
	  stfs      f0, 0x478(r31)
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xC(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x200
	  mr        r3, r30
	  lfs       f31, 0x478(r31)
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x314

	.loc_0x200:
	  lwz       r3, 0x470(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x470(r31)
	  lwz       r3, 0x470(r31)
	  lwz       r0, 0x1C(r30)
	  cmpw      r3, r0
	  blt-      .loc_0x224
	  li        r0, 0
	  stw       r0, 0x470(r31)

	.loc_0x224:
	  lwz       r0, 0x470(r31)
	  li        r4, 0xF
	  lwz       r3, 0x2C4(r31)
	  mulli     r0, r0, 0xC
	  lwz       r5, 0x18(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  add       r30, r5, r0
	  bl        -0x88768
	  lfs       f0, 0x0(r30)
	  cmplwi    r31, 0
	  lwz       r3, 0x2C8(r31)
	  mr        r5, r31
	  lfs       f3, 0x4(r30)
	  fmuls     f0, f0, f1
	  lfs       f2, 0x10(r3)
	  lfs       f5, 0x8(r30)
	  fmuls     f3, f3, f1
	  lfs       f4, 0x14(r3)
	  fadds     f0, f2, f0
	  lfs       f2, 0x18(r3)
	  fmuls     f1, f5, f1
	  fadds     f3, f4, f3
	  stfs      f0, 0x388(r31)
	  fadds     f0, f2, f1
	  stfs      f3, 0x38C(r31)
	  stfs      f0, 0x390(r31)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x478(r31)
	  beq-      .loc_0x2A0
	  lwz       r5, 0x2C0(r31)

	.loc_0x2A0:
	  addi      r3, r1, 0xDC
	  li        r4, -0x1
	  bl        -0x8BD14
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8BA7C
	  li        r0, 0x1
	  stw       r0, 0x46C(r31)
	  lwz       r0, 0x46C(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x2DC
	  bge-      .loc_0x334
	  cmpwi     r0, 0
	  bge-      .loc_0x304
	  b         .loc_0x334

	.loc_0x2DC:
	  lfs       f0, 0x1594(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x1598(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x159C(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  b         .loc_0x334

	.loc_0x304:
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,22,20
	  stw       r0, 0xC8(r31)
	  b         .loc_0x334

	.loc_0x314:
	  lwz       r5, 0x2C4(r31)
	  addi      r3, r31, 0
	  addi      r4, r31, 0x388
	  lwz       r5, 0x84(r5)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f1, 0xC(r5)
	  bl        -0x63938

	.loc_0x334:
	  lwz       r0, 0x10C(r1)
	  li        r3, 0
	  lfd       f31, 0x100(r1)
	  lwz       r31, 0xFC(r1)
	  lwz       r30, 0xF8(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AAD4C
 * Size:	000008
 */
f32 TAIApatrol::getTimeout(Teki& teki)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x4A28(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AAD54
 * Size:	000038
 */
void TAIAstepBack::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x1F9C
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
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
 * Address:	801AAD8C
 * Size:	000164
 */
bool TAIAstepBack::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x58(r1)
	  addi      r30, r3, 0
	  bl        0x2108
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x140
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x418(r31)
	  fmr       f30, f1
	  cmplwi    r4, 0
	  beq-      .loc_0x138
	  lfsu      f3, 0x94(r4)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x8(r4)
	  lfs       f0, 0x9C(r31)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        -0x8CFF4
	  stfs      f1, 0x394(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x394(r31)
	  lfs       f31, 0x28C(r3)
	  lfs       f2, 0xA0(r31)
	  bl        -0x172860
	  lwz       r3, 0x2C4(r31)
	  lfs       f2, -0x4A2C(r2)
	  lwz       r3, 0x84(r3)
	  lfs       f0, 0xA0(r31)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f3, 0x14(r3)
	  fmuls     f1, f1, f3
	  fmuls     f1, f31, f1
	  fmuls     f1, f2, f1
	  fadds     f0, f0, f1
	  stfs      f0, 0xA0(r31)
	  lfs       f1, 0xA0(r31)
	  bl        -0x1728C4
	  stfs      f1, 0xA0(r31)
	  lfs       f0, 0x15A0(r13)
	  stfs      f0, 0x88(r31)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x8C(r31)
	  lfs       f0, 0x15A4(r13)
	  stfs      f0, 0x90(r31)
	  lfs       f1, 0xA0(r31)
	  bl        0x70CE4
	  lfs       f0, 0xA0(r31)
	  fmr       f31, f1
	  fmr       f1, f0
	  bl        0x70E68
	  stfs      f1, 0xA4(r31)
	  fneg      f1, f30
	  li        r3, 0
	  lfs       f0, 0x15A8(r13)
	  stfs      f0, 0xA8(r31)
	  stfs      f31, 0xAC(r31)
	  lfs       f0, 0xA4(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0xAC(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xAC(r31)
	  b         .loc_0x144

	.loc_0x138:
	  li        r3, 0x1
	  b         .loc_0x144

	.loc_0x140:
	  li        r3, 0

	.loc_0x144:
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AAEF0
 * Size:	000018
 */
f32 TAIAstepBack::getVelocity(Teki& teki)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AAF08
 * Size:	000110
 */
void TAIAturnHome::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r4
	  stw       r30, 0x38(r1)
	  mr        r30, r3
	  lwz       r4, 0x2C8(r4)
	  lfs       f0, 0x10(r4)
	  stfs      f0, 0x388(r31)
	  lfs       f0, 0x14(r4)
	  stfs      f0, 0x38C(r31)
	  lfs       f0, 0x18(r4)
	  stfs      f0, 0x390(r31)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  stfs      f0, 0x2C(r1)
	  lfs       f1, 0x388(r31)
	  lfs       f0, 0x94(r31)
	  lfs       f4, 0x390(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r31)
	  lfs       f2, 0x38C(r31)
	  lfs       f1, 0x98(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x28(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x2C(r1)
	  stfs      f1, 0x30(r1)
	  stfs      f3, 0x34(r1)
	  lfs       f1, 0x2C(r1)
	  lfs       f2, 0x34(r1)
	  bl        -0x8D188
	  stfs      f1, 0x394(r31)
	  lfs       f1, 0x394(r31)
	  lfs       f2, 0xA0(r31)
	  bl        -0x1729EC
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xB4
	  lwz       r0, 0xC(r30)
	  stw       r0, 0x8(r30)
	  b         .loc_0xBC

	.loc_0xB4:
	  lwz       r0, 0x10(r30)
	  stw       r0, 0x8(r30)

	.loc_0xBC:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x1D38
	  lfs       f0, 0x15AC(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x15B0(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x15B4(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r3, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AB018
 * Size:	0000C4
 */
bool TAIAturnHome::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r4
	  bl        0x1E8C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xAC
	  lfs       f0, -0x4A68(r2)
	  addi      r6, r1, 0x34
	  addi      r5, r1, 0x30
	  stfs      f0, 0x40(r1)
	  addi      r4, r1, 0x2C
	  addi      r3, r1, 0x38
	  stfs      f0, 0x3C(r1)
	  stfs      f0, 0x38(r1)
	  lfs       f1, 0x390(r31)
	  lfs       f0, 0x9C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x34(r1)
	  lfs       f1, 0x38C(r31)
	  lfs       f0, 0x98(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x30(r1)
	  lfs       f1, 0x388(r31)
	  lfs       f0, 0x94(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2C(r1)
	  bl        -0x14D9FC
	  lfs       f1, 0x38(r1)
	  lfs       f2, 0x40(r1)
	  bl        -0x8D28C
	  stfs      f1, 0x394(r31)
	  li        r4, 0x5
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x88BD8
	  fmr       f2, f1
	  lfs       f1, 0x394(r31)
	  mr        r3, r31
	  bl        -0x63AF0
	  b         .loc_0xB0

	.loc_0xAC:
	  li        r3, 0

	.loc_0xB0:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AB0DC
 * Size:	000038
 */
void TAIAgoingHome::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x1C14
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,22,20
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
 * Address:	801AB114
 * Size:	0000F0
 */
bool TAIAgoingHome::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  li        r31, 0
	  stw       r30, 0x88(r1)
	  addi      r30, r4, 0
	  bl        0x1D88
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD4
	  lwz       r3, 0x2C8(r30)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x80(r1)
	  stfs      f0, 0x7C(r1)
	  stfs      f0, 0x78(r1)
	  lfsu      f0, 0x10(r3)
	  lfs       f1, 0x94(r30)
	  lfs       f4, 0x9C(r30)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x98(r30)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x70(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x70(r1)
	  stfs      f0, 0x78(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f3, 0x80(r1)
	  lfs       f1, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  lfs       f2, 0x80(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19D568
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x40(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xC0
	  li        r31, 0x1
	  b         .loc_0xD4

	.loc_0xC0:
	  lwz       r4, 0x2C8(r30)
	  lfs       f1, 0x10(r3)
	  mr        r3, r30
	  addi      r4, r4, 0x10
	  bl        -0x63DF4

	.loc_0xD4:
	  mr        r3, r31
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AB204
 * Size:	000038
 */
void TAIAgoingHomePriorityFaceDir::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x1AEC
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
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
 * Address:	801AB23C
 * Size:	0000F0
 */
bool TAIAgoingHomePriorityFaceDir::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  li        r31, 0
	  stw       r30, 0x88(r1)
	  addi      r30, r4, 0
	  bl        0x1C60
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD4
	  lwz       r3, 0x2C8(r30)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x80(r1)
	  stfs      f0, 0x7C(r1)
	  stfs      f0, 0x78(r1)
	  lfsu      f0, 0x10(r3)
	  lfs       f1, 0x94(r30)
	  lfs       f4, 0x9C(r30)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x98(r30)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x70(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x70(r1)
	  stfs      f0, 0x78(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f3, 0x80(r1)
	  lfs       f1, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  lfs       f2, 0x80(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19D690
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x40(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xC0
	  li        r31, 0x1
	  b         .loc_0xD4

	.loc_0xC0:
	  lwz       r4, 0x2C8(r30)
	  lfs       f1, 0x10(r3)
	  mr        r3, r30
	  addi      r4, r4, 0x10
	  bl        -0x8844

	.loc_0xD4:
	  mr        r3, r31
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AB32C
 * Size:	00002C
 */
void TAIAflyingBase::start(Teki& teki)
{
	/*
	.loc_0x0:
	  lwz       r0, 0xC8(r4)
	  li        r3, 0
	  ori       r0, r0, 0x40
	  stw       r0, 0xC8(r4)
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,31,29
	  stw       r0, 0xC8(r4)
	  lbz       r0, 0x4C8(r4)
	  rlwimi    r0,r3,1,30,30
	  stb       r0, 0x4C8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AB358
 * Size:	000078
 */
bool TAIAflyingBase::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r4
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x8638
	  mr        r3, r31
	  bl        -0x629F4
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x74(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x60
	  lbz       r0, 0x4C8(r31)
	  li        r3, 0x1
	  rlwimi    r0,r3,1,30,30
	  stb       r0, 0x4C8(r31)

	.loc_0x60:
	  lwz       r0, 0x44(r1)
	  li        r3, 0
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AB3D0
 * Size:	00003C
 */
f32 TAIAflyingBase::getFlyingStayVelocity(Teki& teki)
{
	/*
	.loc_0x0:
	  lbz       r0, 0x4C8(r4)
	  rlwinm.   r0,r0,31,31,31
	  beq-      .loc_0x24
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xC(r3)
	  blr

	.loc_0x24:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000144
 */
void TAIAflyingInTerritory::setTargetPosition(Teki& teki)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801AB40C
 * Size:	0001B0
 */
void TAIAflyingInTerritory::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stfd      f31, 0x78(r1)
	  stw       r31, 0x74(r1)
	  stw       r30, 0x70(r1)
	  mr        r30, r4
	  stw       r29, 0x6C(r1)
	  addi      r29, r3, 0
	  lwz       r0, 0xC8(r4)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r4)
	  lwz       r0, 0xC8(r4)
	  ori       r0, r0, 0x40
	  stw       r0, 0xC8(r4)
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,31,29
	  stw       r0, 0xC8(r4)
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,22,20
	  stw       r0, 0xC8(r4)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x44(r1)
	  stfs      f0, 0x40(r1)
	  stfs      f0, 0x3C(r1)
	  bl        0x6CC00
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4A50(r2)
	  stw       r0, 0x64(r1)
	  lis       r31, 0x4330
	  lfs       f1, -0x4A5C(r2)
	  stw       r31, 0x60(r1)
	  lfs       f0, -0x4A14(r2)
	  lfd       f2, 0x60(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f31, f0, f1
	  bl        0x6CBD0
	  xoris     r0, r3, 0x8000
	  lfs       f2, -0x4A60(r2)
	  stw       r0, 0x5C(r1)
	  lfd       f5, -0x4A50(r2)
	  fsubs     f0, f31, f2
	  stw       r31, 0x58(r1)
	  lfs       f4, -0x4A5C(r2)
	  lfd       f1, 0x58(r1)
	  lfs       f3, -0x4A14(r2)
	  fsubs     f5, f1, f5
	  lfs       f1, 0x15B8(r13)
	  fdivs     f4, f5, f4
	  fmuls     f3, f3, f4
	  fsubs     f2, f3, f2
	  stfs      f2, 0x3C(r1)
	  stfs      f1, 0x40(r1)
	  stfs      f0, 0x44(r1)
	  lfs       f1, 0x3C(r1)
	  lfs       f0, 0x40(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x44(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19D8C8
	  lfs       f0, -0x4A68(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x114
	  addi      r3, r1, 0x3C
	  bl        -0x121FD0

	.loc_0x114:
	  lwz       r3, 0x2C4(r30)
	  li        r4, 0x10
	  lwz       r3, 0x84(r3)
	  bl        -0x8831C
	  lfs       f0, 0x3C(r1)
	  li        r4, 0x1D
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x40(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x40(r1)
	  lfs       f0, 0x44(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x44(r1)
	  lwz       r3, 0x2C8(r30)
	  lwz       r5, 0x2C4(r30)
	  lfs       f1, 0x44(r1)
	  lfs       f0, 0x18(r3)
	  lwz       r3, 0x84(r5)
	  fadds     f31, f1, f0
	  bl        -0x88360
	  lwz       r3, 0x2C8(r30)
	  lfs       f2, 0x3C(r1)
	  lfs       f0, 0x10(r3)
	  fadds     f0, f2, f0
	  stfs      f0, 0x388(r30)
	  stfs      f1, 0x38C(r30)
	  stfs      f31, 0x390(r30)
	  lfs       f0, 0x8(r29)
	  lwz       r3, 0x224(r30)
	  stfs      f0, 0x30(r3)
	  lwz       r0, 0x84(r1)
	  lfd       f31, 0x78(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AB5BC
 * Size:	000430
 */
bool TAIAflyingInTerritory::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x168(r1)
	  stfd      f31, 0x160(r1)
	  stfd      f30, 0x158(r1)
	  stfd      f29, 0x150(r1)
	  stw       r31, 0x14C(r1)
	  mr        r31, r4
	  stw       r30, 0x148(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  stw       r29, 0x144(r1)
	  stw       r28, 0x140(r1)
	  lwz       r4, 0x2C4(r4)
	  lwz       r4, 0x84(r4)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f31, 0xC(r4)
	  bl        -0x62C70
	  lfs       f30, 0xA8(r31)
	  addi      r28, r31, 0x9C
	  lfs       f4, 0x94(r31)
	  lfs       f5, 0x9C(r31)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x100(r1)
	  stfs      f0, 0xFC(r1)
	  stfs      f0, 0xF8(r1)
	  lfs       f0, 0x388(r31)
	  lfs       f3, 0x390(r31)
	  lfs       f2, 0x38C(r31)
	  fsubs     f0, f4, f0
	  fsubs     f3, f5, f3
	  fsubs     f1, f1, f2
	  stfs      f0, 0xD4(r1)
	  lfs       f0, 0xD4(r1)
	  stfs      f0, 0xF8(r1)
	  stfs      f1, 0xFC(r1)
	  stfs      f3, 0x100(r1)
	  lfs       f1, 0xF8(r1)
	  lfs       f0, 0xFC(r1)
	  lfs       f2, 0x100(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19DA34
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xC(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x218
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0xE4(r1)
	  stfs      f0, 0xE0(r1)
	  stfs      f0, 0xDC(r1)
	  bl        0x6C9C8
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4A50(r2)
	  stw       r0, 0x13C(r1)
	  lis       r29, 0x4330
	  lfs       f1, -0x4A5C(r2)
	  stw       r29, 0x138(r1)
	  lfs       f0, -0x4A14(r2)
	  lfd       f2, 0x138(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f29, f0, f1
	  bl        0x6C998
	  xoris     r0, r3, 0x8000
	  lfs       f2, -0x4A60(r2)
	  stw       r0, 0x134(r1)
	  lfd       f5, -0x4A50(r2)
	  fsubs     f0, f29, f2
	  stw       r29, 0x130(r1)
	  lfs       f4, -0x4A5C(r2)
	  lfd       f1, 0x130(r1)
	  lfs       f3, -0x4A14(r2)
	  fsubs     f5, f1, f5
	  lfs       f1, 0x15B8(r13)
	  fdivs     f4, f5, f4
	  fmuls     f3, f3, f4
	  fsubs     f2, f3, f2
	  stfs      f2, 0xDC(r1)
	  stfs      f1, 0xE0(r1)
	  stfs      f0, 0xE4(r1)
	  lfs       f1, 0xDC(r1)
	  lfs       f0, 0xE0(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xE4(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19DB00
	  lfs       f0, -0x4A68(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x19C
	  addi      r3, r1, 0xDC
	  bl        -0x122208

	.loc_0x19C:
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0x10
	  lwz       r3, 0x84(r3)
	  bl        -0x88554
	  lfs       f0, 0xDC(r1)
	  li        r4, 0x1D
	  fmuls     f0, f0, f1
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0xE0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xE0(r1)
	  lfs       f0, 0xE4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xE4(r1)
	  lwz       r3, 0x2C8(r31)
	  lwz       r5, 0x2C4(r31)
	  lfs       f1, 0xE4(r1)
	  lfs       f0, 0x18(r3)
	  lwz       r3, 0x84(r5)
	  fadds     f29, f1, f0
	  bl        -0x88598
	  lwz       r3, 0x2C8(r31)
	  lfs       f2, 0xDC(r1)
	  lfs       f0, 0x10(r3)
	  fadds     f0, f2, f0
	  stfs      f0, 0x388(r31)
	  stfs      f1, 0x38C(r31)
	  stfs      f29, 0x390(r31)
	  lfs       f0, 0x8(r30)
	  lwz       r3, 0x224(r31)
	  stfs      f0, 0x30(r3)

	.loc_0x218:
	  lfs       f1, 0x388(r31)
	  lfs       f0, 0x94(r31)
	  lfs       f3, 0x390(r31)
	  fsubs     f2, f1, f0
	  lfs       f0, 0x0(r28)
	  lfs       f1, -0x4A68(r2)
	  fsubs     f0, f3, f0
	  fmuls     f3, f2, f2
	  fmuls     f4, f0, f0
	  fadds     f3, f3, f1
	  fadds     f7, f4, f3
	  fcmpo     cr0, f7, f1
	  ble-      .loc_0x2A4
	  fsqrte    f4, f7
	  lfd       f6, -0x4A40(r2)
	  lfd       f5, -0x4A38(r2)
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f3, f4, f3
	  fmul      f3, f7, f3
	  frsp      f3, f3
	  stfs      f3, 0xC0(r1)
	  lfs       f7, 0xC0(r1)

	.loc_0x2A4:
	  lfs       f3, -0x4A18(r2)
	  fmuls     f3, f3, f31
	  fcmpo     cr0, f7, f3
	  ble-      .loc_0x2CC
	  fdivs     f2, f2, f7
	  fdivs     f1, f1, f7
	  fdivs     f0, f0, f7
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  fmuls     f0, f0, f3

	.loc_0x2CC:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f4, -0x4A0C(r2)
	  lfs       f5, 0x28C(r3)
	  lfs       f3, 0xA4(r31)
	  fmuls     f4, f4, f5
	  fmuls     f4, f4, f5
	  fmuls     f2, f2, f4
	  fmuls     f1, f1, f4
	  fmuls     f0, f0, f4
	  fadds     f2, f3, f2
	  stfs      f2, 0xA4(r31)
	  lfs       f2, 0xA8(r31)
	  fadds     f1, f2, f1
	  stfs      f1, 0xA8(r31)
	  lfs       f1, 0xAC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0xAC(r31)
	  lfs       f1, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fmuls     f2, f1, f1
	  lfs       f3, 0xAC(r31)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x4A68(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x394
	  fsqrte    f1, f4
	  lfd       f3, -0x4A40(r2)
	  lfd       f2, -0x4A38(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0xB4(r1)
	  lfs       f4, 0xB4(r1)

	.loc_0x394:
	  fcmpo     cr0, f4, f31
	  ble-      .loc_0x3E4
	  lfs       f0, 0xA4(r31)
	  fdivs     f0, f0, f4
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fdivs     f0, f0, f4
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0xAC(r31)
	  fdivs     f0, f0, f4
	  stfs      f0, 0xAC(r31)
	  lfs       f0, 0xA4(r31)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0xAC(r31)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xAC(r31)

	.loc_0x3E4:
	  stfs      f30, 0xA8(r31)
	  li        r3, 0
	  lwz       r4, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  lwz       r0, 0x16C(r1)
	  lfd       f31, 0x160(r1)
	  lfd       f30, 0x158(r1)
	  lfd       f29, 0x150(r1)
	  lwz       r31, 0x14C(r1)
	  lwz       r30, 0x148(r1)
	  lwz       r29, 0x144(r1)
	  lwz       r28, 0x140(r1)
	  addi      r1, r1, 0x168
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AB9EC
 * Size:	000050
 */
void TAIAflyingToGoal::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x1304
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x40
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,31,29
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
 * Address:	801ABA3C
 * Size:	000330
 */
bool TAIAflyingToGoal::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stw       r31, 0x8C(r1)
	  mr        r31, r4
	  stw       r30, 0x88(r1)
	  mr        r30, r3
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  fmr       f31, f1
	  mr        r3, r31
	  bl        -0x630E0
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x1438
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x310
	  lfs       f1, -0x4A68(r2)
	  addi      r4, r31, 0x9C
	  lfs       f3, 0xA8(r31)
	  stfs      f1, 0xA8(r31)
	  lfs       f2, 0x388(r31)
	  lfs       f0, 0x94(r31)
	  lfs       f4, 0x390(r31)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x9C(r31)
	  fsubs     f0, f4, f0
	  fmuls     f4, f2, f2
	  fmuls     f5, f0, f0
	  fadds     f4, f4, f1
	  fadds     f8, f5, f4
	  fcmpo     cr0, f8, f1
	  ble-      .loc_0xE8
	  fsqrte    f5, f8
	  lfd       f7, -0x4A40(r2)
	  lfd       f6, -0x4A38(r2)
	  fmul      f4, f5, f5
	  fmul      f5, f7, f5
	  fmul      f4, f8, f4
	  fsub      f4, f6, f4
	  fmul      f5, f5, f4
	  fmul      f4, f5, f5
	  fmul      f5, f7, f5
	  fmul      f4, f8, f4
	  fsub      f4, f6, f4
	  fmul      f5, f5, f4
	  fmul      f4, f5, f5
	  fmul      f5, f7, f5
	  fmul      f4, f8, f4
	  fsub      f4, f6, f4
	  fmul      f4, f5, f4
	  fmul      f4, f8, f4
	  frsp      f4, f4
	  stfs      f4, 0x68(r1)
	  lfs       f8, 0x68(r1)

	.loc_0xE8:
	  lfs       f4, -0x4A18(r2)
	  fmuls     f4, f4, f31
	  fcmpo     cr0, f8, f4
	  ble-      .loc_0x110
	  fdivs     f2, f2, f8
	  fdivs     f1, f1, f8
	  fdivs     f0, f0, f8
	  fmuls     f2, f2, f4
	  fmuls     f1, f1, f4
	  fmuls     f0, f0, f4

	.loc_0x110:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f5, -0x4A0C(r2)
	  lfs       f6, 0x28C(r3)
	  lfs       f4, 0xA4(r31)
	  fmuls     f5, f5, f6
	  fmuls     f5, f5, f6
	  fmuls     f2, f2, f5
	  fmuls     f1, f1, f5
	  fmuls     f0, f0, f5
	  fadds     f2, f4, f2
	  stfs      f2, 0xA4(r31)
	  lfs       f2, 0xA8(r31)
	  fadds     f1, f2, f1
	  stfs      f1, 0xA8(r31)
	  lfs       f1, 0xAC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0xAC(r31)
	  lfs       f1, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fmuls     f2, f1, f1
	  lfs       f4, 0xAC(r31)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x4A68(r2)
	  fmuls     f4, f4, f4
	  fadds     f1, f2, f1
	  fadds     f5, f4, f1
	  fcmpo     cr0, f5, f0
	  ble-      .loc_0x1D8
	  fsqrte    f1, f5
	  lfd       f4, -0x4A40(r2)
	  lfd       f2, -0x4A38(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f4, f1
	  fmul      f0, f5, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f4, f1
	  fmul      f0, f5, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f4, f1
	  fmul      f0, f5, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f5, f0
	  frsp      f0, f0
	  stfs      f0, 0x5C(r1)
	  lfs       f5, 0x5C(r1)

	.loc_0x1D8:
	  fcmpo     cr0, f5, f31
	  ble-      .loc_0x228
	  lfs       f0, 0xA4(r31)
	  fdivs     f0, f0, f5
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fdivs     f0, f0, f5
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0xAC(r31)
	  fdivs     f0, f0, f5
	  stfs      f0, 0xAC(r31)
	  lfs       f0, 0xA4(r31)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0xAC(r31)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xAC(r31)

	.loc_0x228:
	  stfs      f3, 0xA8(r31)
	  lwz       r3, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  lfs       f3, 0x388(r31)
	  lfs       f0, 0x94(r31)
	  lfs       f2, 0x390(r31)
	  lfs       f1, 0x0(r4)
	  fsubs     f3, f3, f0
	  lfs       f0, -0x4A68(r2)
	  fsubs     f1, f2, f1
	  fmuls     f2, f3, f3
	  fmuls     f1, f1, f1
	  fadds     f4, f2, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x2CC
	  fsqrte    f1, f4
	  lfd       f3, -0x4A40(r2)
	  lfd       f2, -0x4A38(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x6C(r1)
	  lfs       f4, 0x6C(r1)

	.loc_0x2CC:
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xC(r3)
	  fcmpo     cr0, f4, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x308
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x314

	.loc_0x308:
	  li        r3, 0
	  b         .loc_0x314

	.loc_0x310:
	  li        r3, 0

	.loc_0x314:
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ABD6C
 * Size:	000008
 */
bool TAIAflyingToGoal::goal(Teki& teki) { return true; }

/*
 * --INFO--
 * Address:	801ABD74
 * Size:	000018
 */
f32 TAIAflyingToGoal::getVelocity(Teki& teki)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ABD8C
 * Size:	000080
 */
void TAIAflyingDistanceInTerritory::start(Teki& teki)
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
	  bl        0xF5C
	  lwz       r0, 0xC8(r31)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x40
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,31,29
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x1C(r12)
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
 * Address:	801ABE0C
 * Size:	000048
 */
bool TAIAflyingDistanceInTerritory::act(Teki& teki)
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
	  addi      r3, r31, 0
	  bl        -0x91E0
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x3FC
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
 * Address:	801ABE54
 * Size:	000348
 */
bool TAIAflyingDistanceInTerritory::goal(Teki& teki)
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
	  stw       r31, 0x12C(r1)
	  mr        r31, r4
	  stw       r30, 0x128(r1)
	  stw       r29, 0x124(r1)
	  addi      r29, r3, 0
	  lwz       r30, 0x418(r4)
	  cmplwi    r30, 0
	  beq-      .loc_0x2FC
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x98(r30)
	  lfs       f0, -0x4A68(r2)
	  fsubs     f29, f2, f1
	  fcmpo     cr0, f29, f0
	  bge-      .loc_0x58
	  fneg      f29, f29

	.loc_0x58:
	  lfs       f1, 0xC(r29)
	  bl        0x6FC20
	  addi      r3, r29, 0xC
	  fmr       f28, f1
	  lwz       r12, 0x18(r29)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  fdivs     f5, f29, f28
	  lwz       r3, 0x2C8(r31)
	  lfs       f0, 0x98(r30)
	  addi      r3, r3, 0x10
	  lfs       f3, 0x4(r3)
	  fsubs     f30, f3, f0
	  lfs       f2, 0x0(r3)
	  lfs       f0, 0x94(r30)
	  fadds     f28, f5, f1
	  lfs       f4, 0x8(r3)
	  fsubs     f29, f2, f0
	  lfs       f3, 0x9C(r30)
	  fmuls     f1, f30, f30
	  lfs       f0, -0x4A68(r2)
	  fsubs     f31, f4, f3
	  fmuls     f2, f29, f29
	  fadds     f1, f2, f1
	  fmuls     f2, f31, f31
	  fadds     f4, f2, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x128
	  fsqrte    f1, f4
	  lfd       f3, -0x4A40(r2)
	  lfd       f2, -0x4A38(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0xBC(r1)
	  lfs       f4, 0xBC(r1)

	.loc_0x128:
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x168
	  fmuls     f1, f29, f29
	  fmuls     f0, f30, f30
	  fmuls     f2, f31, f31
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19E35C
	  lfs       f0, -0x4A68(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x174
	  fdivs     f29, f29, f1
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1
	  b         .loc_0x174

	.loc_0x168:
	  lfs       f29, 0x15BC(r13)
	  lfs       f30, 0x15C0(r13)
	  lfs       f31, 0x15C4(r13)

	.loc_0x174:
	  fmuls     f29, f29, f28
	  lfs       f2, 0x94(r30)
	  fmuls     f30, f30, f28
	  lfs       f1, 0x98(r30)
	  fmuls     f31, f31, f28
	  lfs       f0, 0x9C(r30)
	  fadds     f29, f29, f2
	  fadds     f30, f30, f1
	  fadds     f31, f31, f0
	  stfs      f29, 0x388(r31)
	  stfs      f30, 0x38C(r31)
	  stfs      f31, 0x390(r31)
	  lwz       r3, 0x2C8(r31)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0xCC(r1)
	  stfs      f0, 0xC8(r1)
	  stfs      f0, 0xC4(r1)
	  lfsu      f1, 0x10(r3)
	  lfs       f0, 0x388(r31)
	  lfs       f4, 0x8(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x390(r31)
	  lfs       f2, 0x4(r3)
	  lfs       f1, 0x38C(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0xB4(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0xB4(r1)
	  stfs      f0, 0xC4(r1)
	  stfs      f1, 0xC8(r1)
	  stfs      f3, 0xCC(r1)
	  lfs       f1, 0xC4(r1)
	  lfs       f0, 0xC8(r1)
	  lfs       f2, 0xCC(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19E424
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x3C(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2F4
	  lwz       r3, 0x2C8(r31)
	  lfsu      f1, 0x10(r3)
	  lfs       f3, 0x388(r31)
	  lfs       f2, 0x38C(r31)
	  lfs       f0, 0x4(r3)
	  fsubs     f30, f3, f1
	  lfs       f1, 0x390(r31)
	  fsubs     f29, f2, f0
	  lfs       f0, 0x8(r3)
	  fsubs     f28, f1, f0
	  fmuls     f1, f30, f30
	  fmuls     f0, f29, f29
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19E480
	  lfs       f0, -0x4A68(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x288
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1
	  fdivs     f28, f28, f1

	.loc_0x288:
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0xF
	  bl        -0x84218
	  fmuls     f3, f28, f1
	  addi      r6, r1, 0x8C
	  fmuls     f2, f29, f1
	  addi      r5, r1, 0x88
	  fmuls     f0, f30, f1
	  stfs      f3, 0x8C(r1)
	  addi      r4, r1, 0x84
	  addi      r3, r1, 0xD8
	  stfs      f2, 0x88(r1)
	  stfs      f0, 0x84(r1)
	  bl        -0x174FF4
	  lwz       r3, 0x2C8(r31)
	  lfsu      f1, 0x10(r3)
	  lfs       f0, 0xD8(r1)
	  lfs       f2, 0xDC(r1)
	  lfs       f3, 0x4(r3)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  lfs       f1, 0xE0(r1)
	  fadds     f2, f3, f2
	  stfs      f0, 0x388(r31)
	  fadds     f0, f4, f1
	  stfs      f2, 0x38C(r31)
	  stfs      f0, 0x390(r31)

	.loc_0x2F4:
	  li        r3, 0x1
	  b         .loc_0x31C

	.loc_0x2FC:
	  lwz       r4, 0x2C8(r31)
	  li        r3, 0x1
	  lfsu      f0, 0x10(r4)
	  stfs      f0, 0x388(r31)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x38C(r31)
	  lfs       f0, 0x8(r4)
	  stfs      f0, 0x390(r31)

	.loc_0x31C:
	  lwz       r0, 0x154(r1)
	  lfd       f31, 0x148(r1)
	  lfd       f30, 0x140(r1)
	  lfd       f29, 0x138(r1)
	  lfd       f28, 0x130(r1)
	  lwz       r31, 0x12C(r1)
	  lwz       r30, 0x128(r1)
	  lwz       r29, 0x124(r1)
	  addi      r1, r1, 0x150
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AC19C
 * Size:	00003C
 */
void TAIAflyingDistance::start(Teki& teki)
{
	/*
	.loc_0x0:
	  lwz       r0, 0xC8(r4)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r4)
	  lwz       r0, 0xC8(r4)
	  ori       r0, r0, 0x40
	  stw       r0, 0xC8(r4)
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,31,29
	  stw       r0, 0xC8(r4)
	  lfs       f0, 0x10(r3)
	  lwz       r3, 0x224(r4)
	  stfs      f0, 0x30(r3)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x490(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AC1D8
 * Size:	0003A0
 */
bool TAIAflyingDistance::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x158(r1)
	  stfd      f31, 0x150(r1)
	  stfd      f30, 0x148(r1)
	  stfd      f29, 0x140(r1)
	  stw       r31, 0x13C(r1)
	  mr        r31, r4
	  stw       r30, 0x138(r1)
	  stw       r29, 0x134(r1)
	  stw       r28, 0x130(r1)
	  mr        r28, r3
	  lwz       r4, 0x2C4(r4)
	  lwz       r30, 0x418(r31)
	  lwz       r3, 0x84(r4)
	  cmplwi    r30, 0
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f31, 0x10(r3)
	  beq-      .loc_0x370
	  lfs       f2, 0x98(r31)
	  li        r29, 0
	  lfs       f1, 0x98(r30)
	  lfs       f0, -0x4A68(r2)
	  fsubs     f29, f2, f1
	  fcmpo     cr0, f29, f0
	  bge-      .loc_0x70
	  fneg      f29, f29

	.loc_0x70:
	  lfs       f1, 0x8(r28)
	  bl        0x6F884
	  addi      r3, r28, 0x8
	  fmr       f30, f1
	  lwz       r12, 0x14(r28)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  fdivs     f2, f29, f30
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x118(r1)
	  stfs      f0, 0x114(r1)
	  stfs      f0, 0x110(r1)
	  fadds     f30, f2, f1
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x94(r30)
	  lfs       f4, 0x9C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r30)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x98(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0xE4(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0xE4(r1)
	  stfs      f0, 0x110(r1)
	  stfs      f1, 0x114(r1)
	  stfs      f3, 0x118(r1)
	  lfs       f1, 0x110(r1)
	  lfs       f0, 0x114(r1)
	  lfs       f2, 0x118(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x19E69C
	  fsubs     f1, f1, f30
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  fmr       f29, f1
	  bge-      .loc_0x124
	  fneg      f30, f29
	  b         .loc_0x128

	.loc_0x124:
	  fmr       f30, f29

	.loc_0x128:
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  mr        r4, r31
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f30, f1
	  bge-      .loc_0x16C
	  lwz       r3, 0x2DEC(r13)
	  li        r29, 0x1
	  lfs       f1, -0x4A08(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x490(r31)
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  stfs      f0, 0x490(r31)
	  b         .loc_0x1D4

	.loc_0x16C:
	  lfs       f0, -0x4A68(r2)
	  lfs       f1, -0x4A04(r2)
	  fcmpo     cr0, f29, f0
	  fmuls     f1, f1, f31
	  bge-      .loc_0x188
	  fneg      f0, f29
	  b         .loc_0x18C

	.loc_0x188:
	  fmr       f0, f29

	.loc_0x18C:
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x1B0
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f29, f0
	  ble-      .loc_0x1A8
	  lfs       f0, -0x4A60(r2)
	  b         .loc_0x1AC

	.loc_0x1A8:
	  lfs       f0, -0x4A24(r2)

	.loc_0x1AC:
	  fmuls     f29, f1, f0

	.loc_0x1B0:
	  lfs       f0, -0x4A0C(r2)
	  lwz       r3, 0x2DEC(r13)
	  fmuls     f0, f0, f29
	  lfs       f1, 0x490(r31)
	  lfs       f2, 0x28C(r3)
	  fmuls     f0, f0, f2
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x490(r31)

	.loc_0x1D4:
	  lfs       f1, 0x490(r31)
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1EC
	  fneg      f0, f1
	  b         .loc_0x1F0

	.loc_0x1EC:
	  fmr       f0, f1

	.loc_0x1F0:
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x218
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x20C
	  lfs       f0, -0x4A60(r2)
	  b         .loc_0x210

	.loc_0x20C:
	  lfs       f0, -0x4A24(r2)

	.loc_0x210:
	  fmuls     f0, f31, f0
	  stfs      f0, 0x490(r31)

	.loc_0x218:
	  lfs       f1, 0x94(r31)
	  lfs       f3, 0x94(r30)
	  lfs       f2, 0x9C(r30)
	  lfs       f0, 0x9C(r31)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        -0x8E600
	  stfs      f1, 0x394(r31)
	  lfs       f1, 0x394(r31)
	  lfs       f2, 0xA0(r31)
	  bl        -0x173E64
	  lwz       r4, 0x224(r31)
	  fmr       f30, f1
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x30(r4)
	  lfs       f0, 0x28C(r3)
	  fmuls     f1, f30, f2
	  lfs       f3, -0x4A2C(r2)
	  lfs       f2, 0xA0(r31)
	  fmuls     f0, f1, f0
	  fmuls     f0, f3, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xA0(r31)
	  lfs       f1, 0xA0(r31)
	  bl        -0x173EC8
	  stfs      f1, 0xA0(r31)
	  lfs       f0, 0x15C8(r13)
	  stfs      f0, 0x88(r31)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x8C(r31)
	  lfs       f0, 0x15CC(r13)
	  stfs      f0, 0x90(r31)
	  lfs       f1, 0xA0(r31)
	  bl        0x6F6E0
	  lfs       f0, 0x490(r31)
	  lfs       f2, 0xA0(r31)
	  fmuls     f31, f1, f0
	  fmr       f1, f2
	  bl        0x6F860
	  lfs       f0, 0x490(r31)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xA4(r31)
	  stfs      f31, 0xAC(r31)
	  lwz       r3, 0x2C4(r31)
	  lfs       f0, -0x4A68(r2)
	  lwz       r3, 0x84(r3)
	  fcmpo     cr0, f30, f0
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f2, 0x24(r3)
	  bge-      .loc_0x2EC
	  fneg      f3, f30
	  b         .loc_0x2F0

	.loc_0x2EC:
	  fmr       f3, f30

	.loc_0x2F0:
	  lfs       f1, -0x4A00(r2)
	  lfs       f0, -0x49FC(r2)
	  fmuls     f1, f1, f2
	  fdivs     f0, f1, f0
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x350
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x350
	  lfs       f1, 0x490(r31)
	  lfs       f0, -0x4A68(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x324
	  fneg      f1, f1

	.loc_0x324:
	  lfs       f0, -0x4A60(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x350
	  lfs       f0, 0x15D0(r13)
	  li        r3, 0x1
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x15D4(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x15D8(r13)
	  stfs      f0, 0xAC(r31)
	  b         .loc_0x354

	.loc_0x350:
	  li        r3, 0

	.loc_0x354:
	  lwz       r4, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  b         .loc_0x374

	.loc_0x370:
	  li        r3, 0x1

	.loc_0x374:
	  lwz       r0, 0x15C(r1)
	  lfd       f31, 0x150(r1)
	  lfd       f30, 0x148(r1)
	  lfd       f29, 0x140(r1)
	  lwz       r31, 0x13C(r1)
	  lwz       r30, 0x138(r1)
	  lwz       r29, 0x134(r1)
	  lwz       r28, 0x130(r1)
	  addi      r1, r1, 0x158
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AC578
 * Size:	000020
 */
f32 TAIAflyingDistance::getGoalAreaRange(Teki& teki)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lfs       f1, -0x49F8(r2)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x10(r3)
	  fmuls     f1, f1, f0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AC598
 * Size:	000080
 */
void TAIAdescent::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  bl        0x758
	  lwz       r0, 0xC8(r31)
	  li        r4, 0x1
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x40
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,31,29
	  stw       r0, 0xC8(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x1446E0
	  lfs       f0, 0x94(r31)
	  stfs      f0, 0x388(r31)
	  stfs      f1, 0x38C(r31)
	  lfs       f0, 0x9C(r31)
	  stfs      f0, 0x390(r31)
	  lfs       f0, -0x4A68(r2)
	  stfs      f0, 0x478(r31)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AC618
 * Size:	0002BC
 */
bool TAIAdescent::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stfd      f30, 0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  bl        -0x63CAC
	  fmr       f30, f1
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x868
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x298
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r30
	  lfs       f1, 0x478(r31)
	  mr        r4, r31
	  lfs       f0, 0x28C(r5)
	  fadds     f31, f1, f0
	  stfs      f31, 0x478(r31)
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x90
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,26,24
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x2
	  stw       r0, 0xC8(r31)

	.loc_0x90:
	  lfs       f0, -0x49F4(r2)
	  fcmpo     cr0, f30, f0
	  ble-      .loc_0x290
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  fneg      f0, f1
	  lfs       f2, -0x4A04(r2)
	  lfs       f4, 0x388(r31)
	  lfs       f3, 0x94(r31)
	  fmuls     f2, f2, f0
	  fsubs     f7, f4, f3
	  lfs       f3, 0x390(r31)
	  lfs       f0, 0x9C(r31)
	  fmuls     f4, f2, f2
	  fsubs     f0, f3, f0
	  fmuls     f5, f7, f7
	  lfs       f3, -0x4A68(r2)
	  fmuls     f6, f0, f0
	  fadds     f4, f5, f4
	  fadds     f8, f6, f4
	  fcmpo     cr0, f8, f3
	  ble-      .loc_0x150
	  fsqrte    f4, f8
	  lfd       f6, -0x4A40(r2)
	  lfd       f5, -0x4A38(r2)
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f8, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f8, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f8, f3
	  fsub      f3, f5, f3
	  fmul      f3, f4, f3
	  fmul      f3, f8, f3
	  frsp      f3, f3
	  stfs      f3, 0x30(r1)
	  lfs       f8, 0x30(r1)

	.loc_0x150:
	  lfs       f3, -0x4A18(r2)
	  fmuls     f3, f3, f1
	  fcmpo     cr0, f8, f3
	  ble-      .loc_0x178
	  fdivs     f7, f7, f8
	  fdivs     f2, f2, f8
	  fdivs     f0, f0, f8
	  fmuls     f7, f7, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f3

	.loc_0x178:
	  lfs       f3, 0xA4(r31)
	  fadds     f3, f3, f7
	  stfs      f3, 0xA4(r31)
	  lfs       f3, 0xA8(r31)
	  fadds     f2, f3, f2
	  stfs      f2, 0xA8(r31)
	  lfs       f2, 0xAC(r31)
	  fadds     f0, f2, f0
	  stfs      f0, 0xAC(r31)
	  lfs       f2, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fmuls     f3, f2, f2
	  lfs       f4, 0xAC(r31)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x4A68(r2)
	  fmuls     f4, f4, f4
	  fadds     f2, f3, f2
	  fadds     f5, f4, f2
	  fcmpo     cr0, f5, f0
	  ble-      .loc_0x220
	  fsqrte    f2, f5
	  lfd       f4, -0x4A40(r2)
	  lfd       f3, -0x4A38(r2)
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f5, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f5, f0
	  fsub      f0, f3, f0
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fmul      f0, f5, f0
	  fsub      f0, f3, f0
	  fmul      f0, f2, f0
	  fmul      f0, f5, f0
	  frsp      f0, f0
	  stfs      f0, 0x2C(r1)
	  lfs       f5, 0x2C(r1)

	.loc_0x220:
	  fcmpo     cr0, f5, f1
	  ble-      .loc_0x270
	  lfs       f0, 0xA4(r31)
	  fdivs     f0, f0, f5
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fdivs     f0, f0, f5
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0xAC(r31)
	  fdivs     f0, f0, f5
	  stfs      f0, 0xAC(r31)
	  lfs       f0, 0xA4(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0xAC(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xAC(r31)

	.loc_0x270:
	  lwz       r4, 0xA4(r31)
	  li        r3, 0
	  lwz       r0, 0xA8(r31)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  b         .loc_0x29C

	.loc_0x290:
	  li        r3, 0x1
	  b         .loc_0x29C

	.loc_0x298:
	  li        r3, 0

	.loc_0x29C:
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lfd       f30, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AC8D4
 * Size:	000018
 */
f32 TAIAdescent::getFlyingVelocity(Teki& teki)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AC8EC
 * Size:	000008
 */
f32 TAIAdescent::getForceDescentFrame(Teki& teki)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x4A64(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AC8F4
 * Size:	000090
 */
void TAIAlanding::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x3FC
	  lwz       r0, 0xC8(r31)
	  li        r3, 0x1
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,26,24
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x2
	  stw       r0, 0xC8(r31)
	  lfs       f0, 0x15DC(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x15E0(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x15E4(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r4, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  lbz       r0, 0x4C8(r31)
	  rlwimi    r0,r3,4,27,27
	  stb       r0, 0x4C8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AC984
 * Size:	000110
 */
bool TAIAlanding::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stfd      f31, 0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f31, f1
	  mr        r3, r31
	  bl        -0x6402C
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x7C
	  lbz       r0, 0x4C8(r31)
	  rlwinm.   r0,r0,28,31,31
	  beq-      .loc_0x7C
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x4C8(r31)
	  li        r3, 0
	  rlwimi    r0,r3,4,27,27
	  stb       r0, 0x4C8(r31)

	.loc_0x7C:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x4B0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF0
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xC8
	  mr        r3, r31
	  bl        -0x64090
	  lfs       f0, -0x4A60(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xC8
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl

	.loc_0xC8:
	  lwz       r3, 0x2CC(r31)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0xE8
	  lfs       f0, -0x4A68(r2)
	  li        r3, 0x1
	  stfs      f0, 0x340(r31)
	  b         .loc_0xF4

	.loc_0xE8:
	  li        r3, 0
	  b         .loc_0xF4

	.loc_0xF0:
	  li        r3, 0

	.loc_0xF4:
	  lwz       r0, 0x2C(r1)
	  lfd       f31, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ACA94
 * Size:	000004
 */
void TAIAlanding::landingEffect(Teki& teki) { }

/*
 * --INFO--
 * Address:	801ACA98
 * Size:	000090
 */
void TAIAtakeOff::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x258
	  lwz       r0, 0xC8(r31)
	  li        r3, 0
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x40
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,31,29
	  stw       r0, 0xC8(r31)
	  lfs       f0, 0x15E8(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x15EC(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x15F0(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r4, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  lbz       r0, 0x4C8(r31)
	  rlwimi    r0,r3,3,28,28
	  stb       r0, 0x4C8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ACB28
 * Size:	000118
 */
bool TAIAtakeOff::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x60(r1)
	  addi      r30, r3, 0
	  bl        0x374
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xFC
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x4C
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl

	.loc_0x4C:
	  lbz       r0, 0x4C8(r31)
	  rlwinm.   r0,r0,29,31,31
	  beq-      .loc_0xE0
	  mr        r3, r31
	  bl        -0x641F0
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x74(r3)
	  lfs       f2, 0xC(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x88
	  lfs       f3, -0x4A60(r2)
	  b         .loc_0x8C

	.loc_0x88:
	  lfs       f3, -0x4A24(r2)

	.loc_0x8C:
	  lfs       f0, -0x4A64(r2)
	  lfs       f1, 0xA8(r31)
	  fmuls     f0, f0, f2
	  fmuls     f0, f0, f3
	  fadds     f0, f1, f0
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0xA8(r31)
	  fcmpo     cr0, f0, f2
	  ble-      .loc_0xB4
	  stfs      f2, 0xA8(r31)

	.loc_0xB4:
	  fneg      f1, f2
	  lfs       f0, 0xA8(r31)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0xC8
	  stfs      f1, 0xA8(r31)

	.loc_0xC8:
	  lwz       r3, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)

	.loc_0xE0:
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0xF4
	  li        r3, 0x1
	  b         .loc_0x100

	.loc_0xF4:
	  li        r3, 0
	  b         .loc_0x100

	.loc_0xFC:
	  li        r3, 0

	.loc_0x100:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ACC40
 * Size:	000014
 */
void TAIAtakeOff::startFlying(Teki& teki)
{
	/*
	.loc_0x0:
	  lbz       r0, 0x4C8(r4)
	  li        r3, 0x1
	  rlwimi    r0,r3,3,28,28
	  stb       r0, 0x4C8(r4)
	  blr
	*/
}
