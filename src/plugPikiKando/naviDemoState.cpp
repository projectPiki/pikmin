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
 * Address:	8010B0E0
 * Size:	000478
 */
void NaviDemoSunsetState::DemoStateMachine::init(NaviDemoSunsetState*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x24
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x58(r1)
	  li        r30, 0
	  stw       r0, 0xC(r3)
	  stw       r30, 0x8(r3)
	  lwz       r0, 0xC(r3)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xC410C
	  stw       r3, 0x4(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xC411C
	  stw       r3, 0x10(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xC412C
	  stw       r3, 0x14(r31)
	  li        r3, 0x18
	  bl        -0xC4138
	  cmplwi    r3, 0
	  beq-      .loc_0xA0
	  lis       r4, 0x802C
	  addi      r0, r4, 0x20D4
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x2084
	  stw       r0, 0x0(r3)
	  lis       r5, 0x802C
	  lis       r4, 0x802C
	  stw       r30, 0x4(r3)
	  addi      r5, r5, 0x2034
	  addi      r0, r4, 0x1FE4
	  stw       r30, 0x8(r3)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)

	.loc_0xA0:
	  lwz       r5, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r5, r0
	  bge-      .loc_0x120
	  lwz       r4, 0x4(r31)
	  rlwinm    r0,r5,2,0,29
	  stwx      r3, r4, r0
	  lwz       r4, 0x4(r3)
	  cmpwi     r4, 0
	  blt-      .loc_0xD4
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  blt-      .loc_0xDC

	.loc_0xD4:
	  li        r0, 0
	  b         .loc_0xE0

	.loc_0xDC:
	  li        r0, 0x1

	.loc_0xE0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x120
	  stw       r31, 0x8(r3)
	  lwz       r0, 0x8(r31)
	  lwz       r5, 0x4(r3)
	  lwz       r4, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r5, r4, r0
	  lwz       r0, 0x4(r3)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x120:
	  li        r3, 0x10
	  bl        -0xC4200
	  cmplwi    r3, 0
	  beq-      .loc_0x170
	  lis       r4, 0x802C
	  addi      r0, r4, 0x20D4
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x2084
	  stw       r0, 0x0(r3)
	  li        r0, 0x1
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  addi      r5, r5, 0x2034
	  addi      r0, r4, 0x1F58
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)

	.loc_0x170:
	  lwz       r5, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r5, r0
	  bge-      .loc_0x1F0
	  lwz       r4, 0x4(r31)
	  rlwinm    r0,r5,2,0,29
	  stwx      r3, r4, r0
	  lwz       r4, 0x4(r3)
	  cmpwi     r4, 0
	  blt-      .loc_0x1A4
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  blt-      .loc_0x1AC

	.loc_0x1A4:
	  li        r0, 0
	  b         .loc_0x1B0

	.loc_0x1AC:
	  li        r0, 0x1

	.loc_0x1B0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1F0
	  stw       r31, 0x8(r3)
	  lwz       r0, 0x8(r31)
	  lwz       r5, 0x4(r3)
	  lwz       r4, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r5, r4, r0
	  lwz       r0, 0x4(r3)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x1F0:
	  li        r3, 0x14
	  bl        -0xC42D0
	  cmplwi    r3, 0
	  beq-      .loc_0x240
	  lis       r4, 0x802C
	  addi      r0, r4, 0x20D4
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x2084
	  stw       r0, 0x0(r3)
	  li        r0, 0x2
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  addi      r5, r5, 0x2034
	  addi      r0, r4, 0x1ECC
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)

	.loc_0x240:
	  lwz       r5, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r5, r0
	  bge-      .loc_0x2C0
	  lwz       r4, 0x4(r31)
	  rlwinm    r0,r5,2,0,29
	  stwx      r3, r4, r0
	  lwz       r4, 0x4(r3)
	  cmpwi     r4, 0
	  blt-      .loc_0x274
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  blt-      .loc_0x27C

	.loc_0x274:
	  li        r0, 0
	  b         .loc_0x280

	.loc_0x27C:
	  li        r0, 0x1

	.loc_0x280:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x2C0
	  stw       r31, 0x8(r3)
	  lwz       r0, 0x8(r31)
	  lwz       r5, 0x4(r3)
	  lwz       r4, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r5, r4, r0
	  lwz       r0, 0x4(r3)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x2C0:
	  li        r3, 0x10
	  bl        -0xC43A0
	  cmplwi    r3, 0
	  beq-      .loc_0x310
	  lis       r4, 0x802C
	  addi      r0, r4, 0x20D4
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x2084
	  stw       r0, 0x0(r3)
	  li        r0, 0x3
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  addi      r5, r5, 0x2034
	  addi      r0, r4, 0x1E3C
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)

	.loc_0x310:
	  lwz       r5, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r5, r0
	  bge-      .loc_0x390
	  lwz       r4, 0x4(r31)
	  rlwinm    r0,r5,2,0,29
	  stwx      r3, r4, r0
	  lwz       r4, 0x4(r3)
	  cmpwi     r4, 0
	  blt-      .loc_0x344
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  blt-      .loc_0x34C

	.loc_0x344:
	  li        r0, 0
	  b         .loc_0x350

	.loc_0x34C:
	  li        r0, 0x1

	.loc_0x350:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x390
	  stw       r31, 0x8(r3)
	  lwz       r0, 0x8(r31)
	  lwz       r5, 0x4(r3)
	  lwz       r4, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r5, r4, r0
	  lwz       r0, 0x4(r3)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x390:
	  li        r3, 0x10
	  bl        -0xC4470
	  cmplwi    r3, 0
	  beq-      .loc_0x3E0
	  lis       r4, 0x802C
	  addi      r0, r4, 0x20D4
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x2084
	  stw       r0, 0x0(r3)
	  li        r0, 0x4
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  addi      r5, r5, 0x2034
	  addi      r0, r4, 0x1DB0
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)

	.loc_0x3E0:
	  lwz       r5, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r5, r0
	  bge-      .loc_0x460
	  lwz       r4, 0x4(r31)
	  rlwinm    r0,r5,2,0,29
	  stwx      r3, r4, r0
	  lwz       r4, 0x4(r3)
	  cmpwi     r4, 0
	  blt-      .loc_0x414
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  blt-      .loc_0x41C

	.loc_0x414:
	  li        r0, 0
	  b         .loc_0x420

	.loc_0x41C:
	  li        r0, 0x1

	.loc_0x420:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x460
	  stw       r31, 0x8(r3)
	  lwz       r0, 0x8(r31)
	  lwz       r5, 0x4(r3)
	  lwz       r4, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r5, r4, r0
	  lwz       r0, 0x4(r3)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x460:
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
 * Address:	8010B558
 * Size:	000090
 */
void NaviDemoSunsetState::GoState::init(NaviDemoSunsetState*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr        r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  lwz       r30, 0x10(r4)
	  cmplwi    r30, 0
	  beq-      .loc_0x34
	  addi      r30, r30, 0x2B8

	.loc_0x34:
	  addi      r3, r1, 0x10
	  li        r4, 0
	  bl        0x139C4
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0
	  bl        0x139E4
	  lwz       r6, 0x10(r29)
	  addi      r4, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r6, 0x834
	  bl        0x144AC
	  li        r0, 0
	  stb       r0, 0x14(r28)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010B5E8
 * Size:	00034C
 */
void NaviDemoSunsetState::GoState::exec(NaviDemoSunsetState*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stfd      f30, 0xC0(r1)
	  stw       r31, 0xBC(r1)
	  mr        r31, r3
	  stw       r30, 0xB8(r1)
	  stw       r29, 0xB4(r1)
	  stw       r28, 0xB0(r1)
	  addi      r28, r4, 0
	  lbz       r0, 0x14(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  lwz       r3, 0x10(r28)
	  lfs       f1, -0x6188(r2)
	  lfsu      f0, 0x70(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r3)
	  lwz       r4, 0x10(r28)
	  lwz       r3, 0x70(r4)
	  lwz       r0, 0x74(r4)
	  stw       r3, 0xA4(r4)
	  stw       r0, 0xA8(r4)
	  lwz       r0, 0x78(r4)
	  stw       r0, 0xAC(r4)
	  b         .loc_0x324

	.loc_0x84:
	  lwz       r3, 0x10(r28)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x20(r28)
	  lfs       f3, 0x24(r28)
	  lfs       f2, 0x4(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x28(r28)
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x90(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, 0x90(r1)
	  lfs       f1, 0x98(r1)
	  fmuls     f4, f0, f0
	  lfs       f0, -0x6184(r2)
	  fmuls     f5, f1, f1
	  fadds     f31, f4, f5
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x130
	  fsqrte    f1, f31
	  lfd       f3, -0x6180(r2)
	  lfd       f2, -0x6178(r2)
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
	  stfs      f0, 0x5C(r1)
	  lfs       f31, 0x5C(r1)

	.loc_0x130:
	  lfs       f0, 0x94(r1)
	  fmuls     f0, f0, f0
	  fadds     f0, f4, f0
	  fadds     f1, f5, f0
	  bl        -0xFDAE8
	  lfs       f0, -0x6184(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x174
	  lfs       f0, 0x90(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x94(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x98(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x98(r1)

	.loc_0x174:
	  lfs       f2, 0x2C(r28)
	  lfs       f0, -0x6170(r2)
	  fdivs     f30, f1, f2
	  fcmpo     cr0, f30, f0
	  ble-      .loc_0x270
	  lfs       f0, -0x616C(r2)
	  fcmpo     cr0, f30, f0
	  bge-      .loc_0x270
	  bl        0x10C8F4
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6148(r2)
	  stw       r0, 0xAC(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x6164(r2)
	  stw       r0, 0xA8(r1)
	  lfs       f1, -0x6168(r2)
	  lfd       f3, 0xA8(r1)
	  lfs       f0, -0x6160(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x270
	  li        r0, 0x1
	  stb       r0, 0x14(r31)
	  lwz       r29, 0x10(r28)
	  cmplwi    r29, 0
	  beq-      .loc_0x1EC
	  addi      r29, r29, 0x2B8

	.loc_0x1EC:
	  addi      r3, r1, 0x6C
	  li        r4, 0x14
	  bl        0x1377C
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x74
	  li        r4, 0x14
	  bl        0x1379C
	  lwz       r6, 0x10(r28)
	  addi      r4, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r6, 0x834
	  bl        0x14264
	  bl        0x10C868
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6148(r2)
	  stw       r0, 0xAC(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x6164(r2)
	  stw       r0, 0xA8(r1)
	  lfs       f1, -0x6168(r2)
	  lfd       f3, 0xA8(r1)
	  lfs       f0, -0x615C(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0xA0(r1)
	  lwz       r3, 0xA4(r1)
	  addi      r0, r3, 0x2
	  stw       r0, 0x10(r31)
	  b         .loc_0x324

	.loc_0x270:
	  lfs       f0, -0x6158(r2)
	  fcmpo     cr0, f31, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x2C0
	  lwz       r5, 0x10(r28)
	  mr        r3, r31
	  lfs       f0, -0x2688(r13)
	  addi      r4, r28, 0
	  addi      r6, r5, 0xA4
	  stfs      f0, 0xA4(r5)
	  li        r5, 0x1
	  lfs       f0, -0x2684(r13)
	  stfs      f0, 0x4(r6)
	  lfs       f0, -0x2680(r13)
	  stfs      f0, 0x8(r6)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x324

	.loc_0x2C0:
	  lwz       r4, 0x10(r28)
	  lfs       f0, -0x6150(r2)
	  lwz       r3, 0x224(r4)
	  fmuls     f2, f0, f30
	  lfs       f3, -0x6154(r2)
	  lfs       f0, 0x90(r1)
	  lfs       f4, 0xD8(r3)
	  lfs       f1, 0x94(r1)
	  fadds     f3, f3, f2
	  lfs       f2, 0x98(r1)
	  fmuls     f1, f1, f4
	  fmuls     f0, f0, f4
	  fmuls     f4, f2, f4
	  fmuls     f1, f1, f3
	  fmuls     f2, f0, f3
	  fmuls     f0, f4, f3
	  stfs      f2, 0x90(r1)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lwz       r3, 0x90(r1)
	  lwz       r0, 0x94(r1)
	  stw       r3, 0xA4(r4)
	  stw       r0, 0xA8(r4)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0xAC(r4)

	.loc_0x324:
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lfd       f30, 0xC0(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  lwz       r29, 0xB4(r1)
	  lwz       r28, 0xB0(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010B934
 * Size:	000030
 */
void AState<NaviDemoSunsetState>::transit(NaviDemoSunsetState*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x8(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
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
 * Address:	8010B964
 * Size:	0000B0
 */
void StateMachine<NaviDemoSunsetState>::transit(NaviDemoSunsetState*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r5,2,0,29
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  mr        r29, r4
	  stw       r28, 0x18(r1)
	  mr        r28, r3
	  lwz       r31, 0x3C(r4)
	  lwz       r3, 0x14(r3)
	  cmplwi    r31, 0
	  lwzx      r30, r3, r0
	  mr        r3, r31
	  beq-      .loc_0x5C
	  lwz       r12, 0x0(r3)
	  mr        r4, r29
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x4(r31)
	  stw       r0, 0x18(r28)

	.loc_0x5C:
	  lwz       r0, 0xC(r28)
	  cmpw      r30, r0
	  blt-      .loc_0x6C

	.loc_0x68:
	  b         .loc_0x68

	.loc_0x6C:
	  lwz       r3, 0x4(r28)
	  rlwinm    r0,r30,2,0,29
	  addi      r4, r29, 0
	  lwzx      r3, r3, r0
	  stw       r3, 0x3C(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010BA14
 * Size:	000004
 */
void AState<NaviDemoSunsetState>::init(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010BA18
 * Size:	000004
 */
void AState<NaviDemoSunsetState>::cleanup(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010BA1C
 * Size:	00012C
 */
void NaviDemoSunsetState::GoState::procAnimMsg(NaviDemoSunsetState*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x28(r1)
	  addi      r28, r3, 0
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x44
	  bge-      .loc_0x10C
	  cmpwi     r0, 0
	  beq-      .loc_0xC0
	  b         .loc_0x10C

	.loc_0x44:
	  lbz       r0, 0x14(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x10C
	  lwz       r3, 0x10(r28)
	  subi      r0, r3, 0x1
	  stw       r0, 0x10(r28)
	  lwz       r3, 0x10(r29)
	  lfs       f0, -0x267C(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x2678(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x2674(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x10(r29)
	  lfs       f0, -0x2670(r13)
	  stfsu     f0, 0x70(r3)
	  lfs       f0, -0x266C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x2668(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r0, 0x10(r28)
	  cmpwi     r0, 0
	  bgt-      .loc_0x10C
	  lwz       r3, 0x10(r29)
	  cmplwi    r3, 0
	  addi      r4, r3, 0
	  beq-      .loc_0xB4
	  addi      r4, r4, 0x2B8

	.loc_0xB4:
	  addi      r3, r3, 0x834
	  bl        0x13FEC
	  b         .loc_0x10C

	.loc_0xC0:
	  lwz       r30, 0x10(r29)
	  cmplwi    r30, 0
	  beq-      .loc_0xD0
	  addi      r30, r30, 0x2B8

	.loc_0xD0:
	  addi      r3, r1, 0x14
	  li        r4, 0x2
	  bl        0x13464
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x2
	  bl        0x13484
	  lwz       r6, 0x10(r29)
	  addi      r4, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r6, 0x834
	  bl        0x13F4C
	  li        r0, 0
	  stb       r0, 0x14(r28)

	.loc_0x10C:
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
 * Address:	8010BB48
 * Size:	000004
 */
void NaviDemoSunsetState::GoState::cleanup(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010BB4C
 * Size:	000084
 */
void NaviDemoSunsetState::LookState::init(NaviDemoSunsetState*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr        r29, r4
	  lwz       r30, 0x10(r4)
	  cmplwi    r30, 0
	  beq-      .loc_0x2C
	  addi      r30, r30, 0x2B8

	.loc_0x2C:
	  addi      r3, r1, 0x10
	  li        r4, 0x41
	  bl        0x133D8
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x41
	  bl        0x133F8
	  mr        r4, r3
	  lwz       r3, 0x10(r29)
	  mr        r5, r31
	  bl        -0x11334
	  lwz       r3, 0x30D8(r13)
	  lwz       r3, 0x20(r3)
	  bl        0x174C4
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
 * Address:	8010BBD0
 * Size:	000004
 */
void NaviDemoSunsetState::LookState::exec(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010BBD4
 * Size:	000004
 */
void NaviDemoSunsetState::LookState::cleanup(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010BBD8
 * Size:	00007C
 */
void NaviDemoSunsetState::LookState::procAnimMsg(NaviDemoSunsetState*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x20
	  b         .loc_0x6C

	.loc_0x20:
	  lis       r5, 0x803D
	  addi      r5, r5, 0x1ED0
	  lwz       r6, 0x8(r5)
	  lwz       r0, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  add       r0, r0, r6
	  add.      r0, r5, r0
	  bne-      .loc_0x58
	  lwz       r12, 0x0(r3)
	  li        r5, 0x4
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x6C

	.loc_0x58:
	  lwz       r12, 0x0(r3)
	  li        r5, 0x2
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x6C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010BC54
 * Size:	00009C
 */
void NaviDemoSunsetState::WhistleState::init(NaviDemoSunsetState*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr        r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  lwz       r30, 0x10(r4)
	  cmplwi    r30, 0
	  beq-      .loc_0x34
	  addi      r30, r30, 0x2B8

	.loc_0x34:
	  addi      r3, r1, 0x10
	  li        r4, 0x31
	  bl        0x132C8
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x31
	  bl        0x132E8
	  mr        r4, r3
	  lwz       r3, 0x10(r29)
	  mr        r5, r31
	  bl        -0x11444
	  li        r0, 0
	  lis       r3, 0x803A
	  stw       r0, 0x10(r28)
	  subi      r3, r3, 0x24E0
	  li        r0, 0x1
	  stw       r0, 0x23C(r3)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010BCF0
 * Size:	000004
 */
void NaviDemoSunsetState::WhistleState::exec(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010BCF4
 * Size:	0000C0
 */
void NaviDemoSunsetState::WhistleState::procAnimMsg(NaviDemoSunsetState*, MsgAnim*)
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
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x3C
	  bge-      .loc_0xA8
	  cmpwi     r0, 0
	  beq-      .loc_0x8C
	  b         .loc_0xA8

	.loc_0x3C:
	  lwz       r3, 0x10(r30)
	  addi      r0, r3, 0x1
	  stw       r0, 0x10(r30)
	  lwz       r0, 0x10(r30)
	  cmpwi     r0, 0x8
	  bne-      .loc_0x60
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0xC0

	.loc_0x60:
	  lwz       r0, 0x10(r30)
	  cmpwi     r0, 0x10
	  bne-      .loc_0xA8
	  lwz       r3, 0x10(r31)
	  cmplwi    r3, 0
	  addi      r4, r3, 0
	  beq-      .loc_0x80
	  addi      r4, r4, 0x2B8

	.loc_0x80:
	  addi      r3, r3, 0x834
	  bl        0x13D48
	  b         .loc_0xA8

	.loc_0x8C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x3
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0xA8:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0xC0:
	*/
}

/*
 * --INFO--
 * Address:	8010BDB4
 * Size:	0002C8
 */
void NaviDemoSunsetState::WhistleState::enterAllPikis(NaviDemoSunsetState*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x590(r1)
	  stmw      r26, 0x578(r1)
	  lwz       r29, 0x30AC(r13)
	  lwz       r31, 0x10(r4)
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r3, 0
	  addi      r28, r1, 0x23C
	  b         .loc_0xA8

	.loc_0x38:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x5C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x74

	.loc_0x5C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x10
	  bne-      .loc_0x8C
	  lhz       r0, 0x428(r3)
	  rlwinm    r0,r0,2,0,29
	  stwx      r3, r28, r0

	.loc_0x8C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xA8:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD0
	  li        r0, 0x1
	  b         .loc_0xFC

	.loc_0xD0:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xF8
	  li        r0, 0x1
	  b         .loc_0xFC

	.loc_0xF8:
	  li        r0, 0

	.loc_0xFC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x38
	  lis       r3, 0x802C
	  addi      r27, r1, 0x23C
	  addi      r28, r3, 0x1AC8
	  li        r26, 0

	.loc_0x114:
	  lwz       r0, 0x0(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x134
	  addi      r4, r28, 0
	  crclr     6, 0x6
	  addi      r5, r26, 0
	  addi      r3, r1, 0x130
	  bl        0x10A6B4

	.loc_0x134:
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x3
	  addi      r27, r27, 0x4
	  blt+      .loc_0x114
	  lwz       r29, 0x710(r31)
	  li        r30, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r27, r3, 0
	  addi      r28, r1, 0x254
	  b         .loc_0x1EC

	.loc_0x16C:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x190
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1A8

	.loc_0x190:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1A8:
	  mr        r26, r3
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D0
	  rlwinm    r0,r30,2,0,29
	  stwx      r26, r28, r0
	  addi      r30, r30, 0x1

	.loc_0x1D0:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x1EC:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x214
	  li        r0, 0x1
	  b         .loc_0x240

	.loc_0x214:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x23C
	  li        r0, 0x1
	  b         .loc_0x240

	.loc_0x23C:
	  li        r0, 0

	.loc_0x240:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x16C
	  lis       r3, 0x802C
	  addi      r27, r1, 0x254
	  addi      r28, r3, 0x1AD8
	  addi      r29, r1, 0x23C
	  li        r26, 0
	  b         .loc_0x2AC

	.loc_0x260:
	  lwz       r3, 0x0(r27)
	  lhz       r5, 0x510(r3)
	  cmplwi    r5, 0x3
	  blt-      .loc_0x280
	  addi      r4, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x24
	  bl        0x10A568

	.loc_0x280:
	  lwz       r3, 0x0(r27)
	  li        r4, 0xB
	  li        r5, 0
	  lhz       r0, 0x510(r3)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r29, r0
	  stw       r0, 0x708(r31)
	  lwz       r3, 0x0(r27)
	  bl        -0x3EE88
	  addi      r27, r27, 0x4
	  addi      r26, r26, 0x1

	.loc_0x2AC:
	  cmpw      r26, r30
	  blt+      .loc_0x260
	  lmw       r26, 0x578(r1)
	  lwz       r0, 0x594(r1)
	  addi      r1, r1, 0x590
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010C07C
 * Size:	000004
 */
void NaviDemoSunsetState::WhistleState::cleanup(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010C080
 * Size:	000078
 */
void NaviDemoSunsetState::WaitState::init(NaviDemoSunsetState*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr        r29, r4
	  lwz       r30, 0x10(r4)
	  cmplwi    r30, 0
	  beq-      .loc_0x2C
	  addi      r30, r30, 0x2B8

	.loc_0x2C:
	  addi      r3, r1, 0x10
	  li        r4, 0x3
	  bl        0x12EA4
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x3
	  bl        0x12EC4
	  mr        r4, r3
	  lwz       r3, 0x10(r29)
	  mr        r5, r31
	  bl        -0x11868
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
 * Address:	8010C0F8
 * Size:	000004
 */
void NaviDemoSunsetState::WaitState::exec(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010C0FC
 * Size:	000004
 */
void NaviDemoSunsetState::WaitState::cleanup(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010C100
 * Size:	000078
 */
void NaviDemoSunsetState::SitState::init(NaviDemoSunsetState*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr        r29, r4
	  lwz       r30, 0x10(r4)
	  cmplwi    r30, 0
	  beq-      .loc_0x2C
	  addi      r30, r30, 0x2B8

	.loc_0x2C:
	  addi      r3, r1, 0x10
	  li        r4, 0x32
	  bl        0x12E24
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x32
	  bl        0x12E44
	  mr        r4, r3
	  lwz       r3, 0x10(r29)
	  mr        r5, r31
	  bl        -0x118E8
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
 * Address:	8010C178
 * Size:	000004
 */
void NaviDemoSunsetState::SitState::exec(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010C17C
 * Size:	000004
 */
void NaviDemoSunsetState::SitState::cleanup(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010C180
 * Size:	0000D4
 */
NaviDemoSunsetState::NaviDemoSunsetState()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802C
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x19F8
	  lis       r4, 0x802C
	  stwu      r1, -0x18(r1)
	  addi      r4, r4, 0x1954
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x802C
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x19A8
	  lis       r3, 0x802C
	  stw       r0, 0x0(r31)
	  li        r0, 0x19
	  stw       r0, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x8(r31)
	  addi      r0, r3, 0x1B8C
	  li        r3, 0x1C
	  stw       r4, 0x0(r31)
	  stw       r0, 0x0(r31)
	  lfs       f0, -0x6184(r2)
	  stfs      f0, 0x1C(r31)
	  stfs      f0, 0x18(r31)
	  stfs      f0, 0x14(r31)
	  stfs      f0, 0x28(r31)
	  stfs      f0, 0x24(r31)
	  stfs      f0, 0x20(r31)
	  bl        -0xC51F0
	  cmplwi    r3, 0
	  beq-      .loc_0xA0
	  lis       r4, 0x802C
	  addi      r0, r4, 0x1C04
	  stw       r0, 0x0(r3)
	  li        r0, -0x1
	  lis       r4, 0x802C
	  stw       r0, 0x18(r3)
	  addi      r0, r4, 0x2140
	  stw       r0, 0x0(r3)

	.loc_0xA0:
	  stw       r3, 0x38(r31)
	  mr        r4, r31
	  lwz       r3, 0x38(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
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
 * Address:	8010C254
 * Size:	000200
 */
void NaviDemoSunsetState::init(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r4, 0
	  li        r4, 0
	  stw       r30, 0x38(r1)
	  mr        r30, r3
	  stw       r29, 0x34(r1)
	  stw       r28, 0x30(r1)
	  lwz       r3, 0x3030(r13)
	  bl        -0x68C44
	  lwz       r3, 0x3030(r13)
	  li        r4, 0
	  li        r5, 0
	  bl        -0x68CE8
	  stw       r31, 0x10(r30)
	  li        r0, 0
	  addi      r4, r30, 0
	  stw       r0, 0x3C(r30)
	  li        r5, 0
	  lwz       r3, 0x38(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x2664(r13)
	  stfs      f0, 0x14(r30)
	  lfs       f0, -0x2660(r13)
	  stfs      f0, 0x18(r30)
	  lfs       f0, -0x265C(r13)
	  stfs      f0, 0x1C(r30)
	  lfs       f0, -0x2658(r13)
	  stfs      f0, 0x20(r30)
	  lfs       f0, -0x2654(r13)
	  stfs      f0, 0x24(r30)
	  lfs       f0, -0x2650(r13)
	  stfs      f0, 0x28(r30)
	  lwz       r29, 0x30AC(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x158

	.loc_0xB8:
	  cmpwi     r28, -0x1
	  bne-      .loc_0xDC
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xF4

	.loc_0xDC:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xF4:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x1B
	  bne-      .loc_0x11C
	  lwz       r4, 0x94(r3)
	  lwz       r0, 0x98(r3)
	  stw       r4, 0x14(r30)
	  stw       r0, 0x18(r30)
	  lwz       r0, 0x9C(r3)
	  stw       r0, 0x1C(r30)
	  b         .loc_0x13C

	.loc_0x11C:
	  cmpwi     r0, 0x1C
	  bne-      .loc_0x13C
	  lwz       r4, 0x94(r3)
	  lwz       r0, 0x98(r3)
	  stw       r4, 0x20(r30)
	  stw       r0, 0x24(r30)
	  lwz       r0, 0x9C(r3)
	  stw       r0, 0x28(r30)

	.loc_0x13C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x158:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x180
	  li        r0, 0x1
	  b         .loc_0x1AC

	.loc_0x180:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1A8
	  li        r0, 0x1
	  b         .loc_0x1AC

	.loc_0x1A8:
	  li        r0, 0

	.loc_0x1AC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xB8
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0x200
	  lfs       f0, -0x6140(r2)
	  stfs      f0, 0x30(r30)
	  lwz       r3, 0x30D8(r13)
	  lwz       r3, 0x20(r3)
	  addi      r4, r3, 0x38
	  bl        0x16BD0
	  li        r0, 0
	  stb       r0, 0x34(r30)
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  lwz       r28, 0x30(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr

	.loc_0x200:
	*/
}

/*
 * --INFO--
 * Address:	8010C454
 * Size:	0004A0
 */
void NaviDemoSunsetState::setActors(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF0(r1)
	  stfd      f31, 0xE8(r1)
	  stfd      f30, 0xE0(r1)
	  stw       r31, 0xDC(r1)
	  stw       r30, 0xD8(r1)
	  stw       r29, 0xD4(r1)
	  mr        r29, r4
	  stw       r28, 0xD0(r1)
	  mr        r28, r3
	  lwz       r3, 0x14(r3)
	  lwz       r0, 0x18(r28)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r0, 0x1C(r28)
	  stw       r0, 0x9C(r4)
	  lfs       f3, 0x20(r28)
	  lfs       f2, 0x14(r28)
	  lfs       f1, 0x24(r28)
	  fsubs     f31, f3, f2
	  lfs       f0, 0x18(r28)
	  lfs       f2, 0x28(r28)
	  fsubs     f3, f1, f0
	  lfs       f0, 0x1C(r28)
	  fsubs     f30, f2, f0
	  fmuls     f1, f31, f31
	  fmuls     f0, f3, f3
	  fmuls     f2, f30, f30
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xFE890
	  lfs       f0, -0x6184(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x94
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1

	.loc_0x94:
	  stfs      f1, 0x2C(r28)
	  fmr       f1, f31
	  fmr       f2, f30
	  bl        0x10F504
	  stfs      f1, 0xA0(r29)
	  addi      r3, r29, 0
	  li        r4, 0
	  bl        -0xE118
	  lwz       r31, 0x710(r29)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x1D0

	.loc_0xD4:
	  cmpwi     r30, -0x1
	  bne-      .loc_0xFC
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x118

	.loc_0xFC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x118:
	  lwz       r3, 0x4F8(r28)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x130
	  li        r3, 0
	  b         .loc_0x13C

	.loc_0x130:
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0

	.loc_0x13C:
	  lwz       r6, 0x710(r29)
	  li        r4, 0x1
	  lwz       r0, 0x58(r3)
	  lwz       r5, 0x80(r6)
	  rlwinm    r3,r0,5,0,26
	  lfsu      f0, 0x94(r6)
	  addi      r3, r3, 0xC
	  add       r3, r5, r3
	  lfs       f1, 0x0(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x4(r6)
	  fadds     f0, f1, f0
	  stfs      f0, 0xAC(r1)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x8(r6)
	  fadds     f0, f1, f0
	  stfs      f0, 0xB0(r1)
	  lwz       r3, 0xA8(r1)
	  lwz       r0, 0xAC(r1)
	  stw       r3, 0x94(r28)
	  stw       r0, 0x98(r28)
	  lwz       r0, 0xB0(r1)
	  stw       r0, 0x9C(r28)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r28)
	  lfs       f2, 0x9C(r28)
	  bl        -0xA46FC
	  stfs      f1, 0x98(r28)
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x1D0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1F8
	  li        r0, 0x1
	  b         .loc_0x224

	.loc_0x1F8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x220
	  li        r0, 0x1
	  b         .loc_0x224

	.loc_0x220:
	  li        r0, 0

	.loc_0x224:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xD4
	  lwz       r28, 0x3068(r13)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x2E4

	.loc_0x24C:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x270
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x288

	.loc_0x270:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x288:
	  lhz       r0, 0x4FC(r3)
	  addi      r30, r3, 0
	  cmplwi    r0, 0x1
	  bne-      .loc_0x2A8
	  mr        r3, r30
	  bl        -0x4419C
	  cmpwi     r3, 0xE
	  bne-      .loc_0x2C8

	.loc_0x2A8:
	  li        r0, 0x1
	  stb       r0, 0x584(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x81A2C
	  cmpwi     r29, 0
	  blt-      .loc_0x2C8
	  subi      r29, r29, 0x1

	.loc_0x2C8:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x2E4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x30C
	  li        r0, 0x1
	  b         .loc_0x338

	.loc_0x30C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x334
	  li        r0, 0x1
	  b         .loc_0x338

	.loc_0x334:
	  li        r0, 0

	.loc_0x338:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x24C
	  lwz       r3, 0x3160(r13)
	  bl        -0x2C234
	  lwz       r3, 0x30AC(r13)
	  bl        -0x2C23C
	  lwz       r3, 0x3160(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3168(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r28, 0x30AC(r13)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x41C

	.loc_0x398:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x3BC
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3D4

	.loc_0x3BC:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x3D4:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0xF
	  beq-      .loc_0x400
	  cmpwi     r0, 0x10
	  beq-      .loc_0x400
	  cmpwi     r0, 0x11
	  beq-      .loc_0x400
	  cmpwi     r0, 0x12
	  beq-      .loc_0x400
	  li        r4, 0
	  bl        -0x81B70

	.loc_0x400:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x41C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x444
	  li        r0, 0x1
	  b         .loc_0x470

	.loc_0x444:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x46C
	  li        r0, 0x1
	  b         .loc_0x470

	.loc_0x46C:
	  li        r0, 0

	.loc_0x470:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x398
	  lwz       r0, 0xF4(r1)
	  lfd       f31, 0xE8(r1)
	  lfd       f30, 0xE0(r1)
	  lwz       r31, 0xDC(r1)
	  lwz       r30, 0xD8(r1)
	  lwz       r29, 0xD4(r1)
	  lwz       r28, 0xD0(r1)
	  addi      r1, r1, 0xF0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010C8F4
 * Size:	000160
 */
void NaviDemoSunsetState::exec(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x48(r1)
	  addi      r30, r4, 0
	  addi      r3, r30, 0
	  bl        -0x12230
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0xE534
	  lfs       f0, -0x6184(r2)
	  mr        r4, r31
	  stfs      f0, 0x738(r30)
	  lwz       r3, 0x38(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x30(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x30(r31)
	  lfs       f1, 0x30(r31)
	  lfs       f0, -0x6184(r2)
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0x9C
	  lfs       f0, -0x613C(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xC8
	  lwz       r4, 0x2E4(r30)
	  lis       r3, 0x108
	  subi      r0, r3, 0x1000
	  lwz       r3, 0x28(r4)
	  and.      r0, r3, r0
	  beq-      .loc_0xC8

	.loc_0x9C:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  li        r0, 0x1
	  stw       r0, 0x240(r3)
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x148

	.loc_0xC8:
	  lbz       r0, 0x34(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x148
	  lfs       f0, -0x6138(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x148
	  lwz       r4, 0x3100(r13)
	  lis       r3, 0x803D
	  lwz       r0, 0x3104(r13)
	  addi      r7, r3, 0x1E58
	  extsh     r3, r4
	  sth       r3, 0x38(r1)
	  extsh     r0, r0
	  lwz       r3, 0x30F8(r13)
	  addi      r4, r1, 0x38
	  sth       r0, 0x3A(r1)
	  lwz       r0, 0x30FC(r13)
	  extsh     r5, r3
	  lwz       r6, 0x8(r7)
	  lwz       r3, 0x4(r7)
	  extsh     r0, r0
	  lwz       r7, 0x0(r7)
	  add       r6, r3, r6
	  lwz       r3, 0x30E4(r13)
	  add       r6, r7, r6
	  sth       r6, 0x3C(r1)
	  sth       r5, 0x3E(r1)
	  sth       r0, 0x40(r1)
	  bl        0xB5CD4
	  li        r0, 0x1
	  stb       r0, 0x34(r31)

	.loc_0x148:
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
 * Address:	8010CA54
 * Size:	00003C
 */
void StateMachine<NaviDemoSunsetState>::exec(NaviDemoSunsetState*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x3C(r4)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x2C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010CA90
 * Size:	000004
 */
void AState<NaviDemoSunsetState>::exec(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010CA94
 * Size:	000218
 */
void NaviDemoSunsetState::cleanup(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stmw      r27, 0x44(r1)
	  lwz       r31, 0x3068(r13)
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x1A8

	.loc_0x30:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x54
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x6C

	.loc_0x54:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x6C:
	  cmplwi    r3, 0
	  addi      r27, r3, 0
	  beq-      .loc_0x18C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x18C
	  lwz       r29, 0x30AC(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x130

	.loc_0xB4:
	  cmpwi     r28, -0x1
	  bne-      .loc_0xD8
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xF0

	.loc_0xD8:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xF0:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x10
	  bne-      .loc_0x114
	  lhz       r4, 0x428(r3)
	  lhz       r0, 0x510(r27)
	  cmplw     r4, r0
	  bne-      .loc_0x114
	  mr        r4, r27
	  bl        -0x2194C

	.loc_0x114:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x130:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x158
	  li        r0, 0x1
	  b         .loc_0x184

	.loc_0x158:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x180
	  li        r0, 0x1
	  b         .loc_0x184

	.loc_0x180:
	  li        r0, 0

	.loc_0x184:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xB4

	.loc_0x18C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x1A8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D0
	  li        r0, 0x1
	  b         .loc_0x1FC

	.loc_0x1D0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1F8
	  li        r0, 0x1
	  b         .loc_0x1FC

	.loc_0x1F8:
	  li        r0, 0

	.loc_0x1FC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x30
	  lmw       r27, 0x44(r1)
	  lwz       r0, 0x5C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010CCAC
 * Size:	000034
 */
void NaviDemoSunsetState::procAnimMsg(Navi*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x38(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
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
 * Address:	8010CCE0
 * Size:	00003C
 */
void StateMachine<NaviDemoSunsetState>::procMsg(NaviDemoSunsetState*, Msg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x3C(r4)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x2C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010CD1C
 * Size:	000118
 */
void Receiver<NaviDemoSunsetState>::procMsg(NaviDemoSunsetState*, Msg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x0(r5)
	  cmplwi    r0, 0xA
	  bgt-      .loc_0x108
	  lis       r6, 0x802C
	  addi      r6, r6, 0x1AE4
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r6, r0
	  mtctr     r0
	  bctr
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x108:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010CE34
 * Size:	000004
 */
void Receiver<NaviDemoSunsetState>::procGroundMsg(NaviDemoSunsetState*, MsgGround*) { }

/*
 * --INFO--
 * Address:	8010CE38
 * Size:	000004
 */
void Receiver<NaviDemoSunsetState>::procUserMsg(NaviDemoSunsetState*, MsgUser*) { }

/*
 * --INFO--
 * Address:	8010CE3C
 * Size:	000004
 */
void Receiver<NaviDemoSunsetState>::procOffWallMsg(NaviDemoSunsetState*, MsgOffWall*) { }

/*
 * --INFO--
 * Address:	8010CE40
 * Size:	000004
 */
void Receiver<NaviDemoSunsetState>::procWallMsg(NaviDemoSunsetState*, MsgWall*) { }

/*
 * --INFO--
 * Address:	8010CE44
 * Size:	000004
 */
void Receiver<NaviDemoSunsetState>::procDamageMsg(NaviDemoSunsetState*, MsgDamage*) { }

/*
 * --INFO--
 * Address:	8010CE48
 * Size:	000004
 */
void Receiver<NaviDemoSunsetState>::procAnimMsg(NaviDemoSunsetState*, MsgAnim*) { }

/*
 * --INFO--
 * Address:	8010CE4C
 * Size:	000004
 */
void Receiver<NaviDemoSunsetState>::procCollideMsg(NaviDemoSunsetState*, MsgCollide*) { }

/*
 * --INFO--
 * Address:	8010CE50
 * Size:	000004
 */
void Receiver<NaviDemoSunsetState>::procTargetMsg(NaviDemoSunsetState*, MsgTarget*) { }

/*
 * --INFO--
 * Address:	8010CE54
 * Size:	000004
 */
void Receiver<NaviDemoSunsetState>::procHangMsg(NaviDemoSunsetState*, MsgHang*) { }

/*
 * --INFO--
 * Address:	8010CE58
 * Size:	000004
 */
void Receiver<NaviDemoSunsetState>::procStickMsg(NaviDemoSunsetState*, MsgStick*) { }

/*
 * --INFO--
 * Address:	8010CE5C
 * Size:	000004
 */
void Receiver<NaviDemoSunsetState>::procBounceMsg(NaviDemoSunsetState*, MsgBounce*) { }

/*
 * --INFO--
 * Address:	8010CE60
 * Size:	000004
 */
void AState<NaviDemoSunsetState>::resume(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010CE64
 * Size:	000004
 */
void AState<NaviDemoSunsetState>::restart(NaviDemoSunsetState*) { }

/*
 * --INFO--
 * Address:	8010CE68
 * Size:	000004
 */
void StateMachine<NaviDemoSunsetState>::init(NaviDemoSunsetState*) { }
