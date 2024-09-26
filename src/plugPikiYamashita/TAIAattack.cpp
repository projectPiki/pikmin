#include "TAI/Aattack.h"

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
 * Address:	801AE19C
 * Size:	00003C
 */
void TAIAattackWorkObject::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x14AC
	  li        r0, 0
	  stw       r0, 0x46C(r31)
	  lfs       f0, -0x49D0(r2)
	  stfs      f0, 0x478(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AE1D8
 * Size:	000254
 */
bool TAIAattackWorkObject::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  stw       r31, 0x84(r1)
	  li        r31, 0
	  stw       r30, 0x80(r1)
	  mr        r30, r4
	  stw       r29, 0x7C(r1)
	  addi      r29, r3, 0
	  lwz       r0, 0x46C(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x94
	  bge-      .loc_0x44
	  cmpwi     r0, 0
	  bge-      .loc_0x50
	  b         .loc_0x230

	.loc_0x44:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x230
	  b         .loc_0x20C

	.loc_0x50:
	  mr        r3, r30
	  lwz       r4, 0xC(r29)
	  bl        -0xB230
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x230
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0x320
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8C
	  li        r0, 0x1
	  stw       r0, 0x46C(r30)
	  lfs       f0, -0x49D0(r2)
	  stfs      f0, 0x478(r30)
	  b         .loc_0x230

	.loc_0x8C:
	  li        r31, 0x1
	  b         .loc_0x230

	.loc_0x94:
	  mr        r3, r30
	  lwz       r4, 0xC(r29)
	  bl        -0xB274
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x230
	  lfs       f0, -0x49D0(r2)
	  stfs      f0, 0x70(r1)
	  stfs      f0, 0x6C(r1)
	  stfs      f0, 0x68(r1)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x388(r30)
	  lfs       f4, 0x9C(r30)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x390(r30)
	  lfs       f2, 0x98(r30)
	  lfs       f1, 0x38C(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x5C(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x5C(r1)
	  stfs      f0, 0x68(r1)
	  stfs      f1, 0x6C(r1)
	  stfs      f3, 0x70(r1)
	  lfs       f1, 0x68(r1)
	  lfs       f0, 0x6C(r1)
	  lfs       f2, 0x70(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1A06A8
	  mr        r3, r29
	  fmr       f31, f1
	  lwz       r12, 0x4(r29)
	  mr        r4, r30
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f31, f1
	  bge-      .loc_0x174
	  lfs       f0, 0x17D0(r13)
	  li        r0, 0x2
	  stfs      f0, 0xA4(r30)
	  lfs       f0, 0x17D4(r13)
	  stfs      f0, 0xA8(r30)
	  lfs       f0, 0x17D8(r13)
	  stfs      f0, 0xAC(r30)
	  lwz       r4, 0xA4(r30)
	  lwz       r3, 0xA8(r30)
	  stw       r4, 0x70(r30)
	  stw       r3, 0x74(r30)
	  lwz       r3, 0xAC(r30)
	  stw       r3, 0x78(r30)
	  stw       r0, 0x46C(r30)
	  b         .loc_0x230

	.loc_0x174:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x478(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x478(r30)
	  lfs       f1, 0x478(r30)
	  lfs       f0, -0x49CC(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1BC
	  lwz       r5, 0x2C4(r30)
	  addi      r3, r30, 0
	  addi      r4, r30, 0x388
	  lwz       r5, 0x84(r5)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f1, 0xC(r5)
	  bl        -0xB8C4
	  b         .loc_0x230

	.loc_0x1BC:
	  lwz       r29, 0x4BC(r30)
	  mr        r3, r30
	  bl        -0x124154
	  cmplw     r3, r29
	  bne-      .loc_0x230
	  lfs       f0, 0x17DC(r13)
	  li        r0, 0x2
	  stfs      f0, 0xA4(r30)
	  lfs       f0, 0x17E0(r13)
	  stfs      f0, 0xA8(r30)
	  lfs       f0, 0x17E4(r13)
	  stfs      f0, 0xAC(r30)
	  lwz       r4, 0xA4(r30)
	  lwz       r3, 0xA8(r30)
	  stw       r4, 0x70(r30)
	  stw       r3, 0x74(r30)
	  lwz       r3, 0xAC(r30)
	  stw       r3, 0x78(r30)
	  stw       r0, 0x46C(r30)
	  b         .loc_0x230

	.loc_0x20C:
	  mr        r3, r30
	  lwz       r4, 0x10(r29)
	  bl        -0xB3EC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x230
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0x34
	  mr        r31, r3

	.loc_0x230:
	  mr        r3, r31
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  lwz       r29, 0x7C(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AE42C
 * Size:	000008
 */
f32 TAIAattackWorkObject::getAttackPointRadius(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x49C8(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AE434
 * Size:	000124
 */
bool TAIAattackWorkObject::attackWorkObject(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stmw      r27, 0x3C(r1)
	  mr        r28, r4
	  addi      r27, r3, 0
	  li        r29, 0
	  lwz       r31, 0x4BC(r4)
	  cmplwi    r31, 0
	  addi      r3, r31, 0
	  beq-      .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x108
	  lwz       r30, 0x470(r28)
	  cmpwi     r30, 0
	  bge-      .loc_0x5C
	  li        r29, 0x1
	  b         .loc_0x108

	.loc_0x5C:
	  addi      r3, r27, 0
	  addi      r4, r31, 0
	  bl        0x2E4
	  cmpw      r3, r30
	  bne-      .loc_0x100
	  mr        r3, r27
	  lwz       r5, 0x2DEC(r13)
	  lwz       r12, 0x4(r27)
	  mr        r4, r28
	  lfs       f31, 0x28C(r5)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x803A
	  lwz       r4, 0x470(r28)
	  subi      r3, r3, 0x2848
	  lfs       f0, 0x2D8(r3)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3064
	  fdivs     f0, f31, f0
	  stw       r0, 0x24(r1)
	  lis       r3, 0x802B
	  stw       r28, 0x28(r1)
	  addi      r0, r3, 0x1090
	  stw       r0, 0x24(r1)
	  fmuls     f0, f0, f1
	  mr        r3, r31
	  stw       r4, 0x2C(r1)
	  addi      r4, r1, 0x24
	  stfs      f0, 0x30(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x4(r27)
	  mr        r4, r28
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108

	.loc_0x100:
	  li        r0, 0
	  stw       r0, 0x46C(r28)

	.loc_0x108:
	  mr        r3, r29
	  lmw       r27, 0x3C(r1)
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AE558
 * Size:	000004
 */
void TAIAattackWorkObject::attackEffect(Teki&) { }

/*
 * --INFO--
 * Address:	801AE55C
 * Size:	000008
 */
f32 TAIAattackWorkObject::getDamage(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x49C4(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AE564
 * Size:	000218
 */
bool TAIAattackWorkObject::setTargetPosition(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  li        r30, 0
	  stw       r29, 0x44(r1)
	  addi      r29, r3, 0
	  stw       r28, 0x40(r1)
	  mr        r28, r4
	  lwz       r31, 0x4BC(r4)
	  lfs       f0, 0x94(r4)
	  cmplwi    r31, 0
	  stfs      f0, 0x388(r28)
	  addi      r3, r31, 0
	  lfs       f0, 0x98(r28)
	  stfs      f0, 0x38C(r28)
	  lfs       f0, 0x9C(r28)
	  stfs      f0, 0x390(r28)
	  beq-      .loc_0x1F0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1F0
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  bl        .loc_0x218
	  mr.       r29, r3
	  blt-      .loc_0x1EC
	  lfs       f0, -0x49D0(r2)
	  addi      r4, r31, 0
	  addi      r5, r29, 0
	  stfs      f0, 0x30(r1)
	  addi      r3, r1, 0x1C
	  stfs      f0, 0x2C(r1)
	  stfs      f0, 0x28(r1)
	  bl        -0x10FCB8
	  lfs       f0, 0x1C(r1)
	  addi      r4, r31, 0
	  addi      r3, r1, 0x28
	  stfs      f0, 0x388(r28)
	  lfs       f0, 0x20(r1)
	  stfs      f0, 0x38C(r28)
	  lfs       f0, 0x24(r1)
	  stfs      f0, 0x390(r28)
	  bl        -0x10FAC8
	  mr        r3, r31
	  bl        -0x10F914
	  fneg      f1, f1
	  lfs       f0, 0x28(r1)
	  li        r4, 0x1
	  fmuls     f0, f0, f1
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x2C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x30(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x30(r1)
	  lfs       f1, 0x388(r28)
	  lfs       f0, 0x28(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x388(r28)
	  lfs       f1, 0x38C(r28)
	  lfs       f0, 0x2C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x38C(r28)
	  lfs       f1, 0x390(r28)
	  lfs       f0, 0x30(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x390(r28)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x388(r28)
	  lfs       f2, 0x390(r28)
	  bl        -0x146794
	  stfs      f1, 0x38C(r28)
	  addi      r4, r31, 0
	  addi      r3, r1, 0x28
	  bl        -0x10FAEC
	  bl        0x699C4
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x49B0(r2)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lfs       f1, -0x49C0(r2)
	  mr        r3, r31
	  stw       r0, 0x38(r1)
	  lfs       f0, -0x49C4(r2)
	  lfd       f2, 0x38(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f31, f0, f1
	  bl        -0x10F9C0
	  lfs       f0, -0x49B8(r2)
	  li        r30, 0x1
	  lfs       f2, -0x49BC(r2)
	  fsubs     f3, f31, f0
	  lfs       f0, 0x28(r1)
	  fmuls     f1, f1, f3
	  fmuls     f1, f2, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x2C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x30(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x30(r1)
	  lfs       f1, 0x388(r28)
	  lfs       f0, 0x28(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x388(r28)
	  lfs       f1, 0x38C(r28)
	  lfs       f0, 0x2C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x38C(r28)
	  lfs       f1, 0x390(r28)
	  lfs       f0, 0x30(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x390(r28)

	.loc_0x1EC:
	  stw       r29, 0x470(r28)

	.loc_0x1F0:
	  mr        r3, r30
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  lwz       r28, 0x40(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr

	.loc_0x218:
	*/
}

/*
 * --INFO--
 * Address:	801AE77C
 * Size:	000068
 */
int TAIAattackWorkObject::getLastFinishedStageBridge(Bridge*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  lwz       r3, 0x404(r4)
	  subi      r31, r3, 0x1
	  b         .loc_0x44

	.loc_0x24:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x11045C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x40
	  mr        r3, r31
	  b         .loc_0x50

	.loc_0x40:
	  subi      r31, r31, 0x1

	.loc_0x44:
	  cmpwi     r31, 0
	  bge+      .loc_0x24
	  li        r3, -0x1

	.loc_0x50:
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
 * Address:	801AE7E4
 * Size:	000044
 */
void TAIAflickingAfterMotionLoop::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x18B8
	  mr        r3, r31
	  lwz       r4, -0x9A4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
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
 * Address:	801AE828
 * Size:	00001C
 */
bool TAIAflickingAfterMotionLoop::permitFlick(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AE844
 * Size:	0000A0
 */
bool TAIAflickingAfterMotionLoop::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x44
	  mr        r3, r30
	  bl        -0x66B10

	.loc_0x44:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0x191C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x80
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x80
	  mr        r3, r30
	  lwz       r4, -0x9A4(r13)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  li        r31, 0x1

	.loc_0x80:
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
 * Address:	801AE8E4
 * Size:	00008C
 */
bool TAIAtargetNavi::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  lwz       r3, 0x3120(r13)
	  bl        -0x9753C
	  addi      r31, r3, 0
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x677C4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x70
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x54
	  beq-      .loc_0x54
	  bl        -0xCA5C0
	  li        r0, 0
	  stw       r0, 0x418(r30)

	.loc_0x54:
	  stw       r31, 0x418(r30)
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x68
	  bl        -0xCA5EC

	.loc_0x68:
	  li        r3, 0x1
	  b         .loc_0x74

	.loc_0x70:
	  li        r3, 0

	.loc_0x74:
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
 * Address:	801AE970
 * Size:	000158
 */
bool TAIAtargetPiki::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r27, 0x2C(r1)
	  addi      r27, r4, 0
	  li        r28, 0
	  lwz       r30, 0x3068(r13)
	  lwz       r12, 0x0(r30)
	  addi      r3, r30, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0xE4

	.loc_0x38:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x60
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3
	  b         .loc_0x7C

	.loc_0x60:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x7C:
	  addi      r4, r31, 0
	  addi      r3, r27, 0
	  bl        -0x678A8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC8
	  lwz       r3, 0x418(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0xAC
	  beq-      .loc_0xAC
	  bl        -0xCA6A4
	  li        r0, 0
	  stw       r0, 0x418(r27)

	.loc_0xAC:
	  stw       r31, 0x418(r27)
	  lwz       r3, 0x418(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0xC0
	  bl        -0xCA6D0

	.loc_0xC0:
	  li        r28, 0x1
	  b         .loc_0x140

	.loc_0xC8:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0xE4:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10C
	  li        r0, 0x1
	  b         .loc_0x138

	.loc_0x10C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x134
	  li        r0, 0x1
	  b         .loc_0x138

	.loc_0x134:
	  li        r0, 0

	.loc_0x138:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x38

	.loc_0x140:
	  mr        r3, r28
	  lmw       r27, 0x2C(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AEAC8
 * Size:	000078
 */
void TAIAfireBreath::start(Teki&)
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
	  bl        -0x1DE4
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  fmr       f31, f1
	  lwz       r12, 0x0(r31)
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  stfs      f31, 0x3B4(r31)
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
 * Address:	801AEB40
 * Size:	000008
 */
f32 TAIAfireBreath::getPreviousAnimSpeed(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x49A8(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AEB48
 * Size:	0000D8
 */
bool TAIAfireBreath::act(Teki&)
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
	  bl        -0x1CB0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB8
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  fmr       f31, f1
	  lwz       r12, 0x0(r31)
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  stfs      f31, 0x3B4(r31)
	  lwz       r3, 0xC(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x84
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x84:
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0xB0
	  mr        r3, r31
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0xBC

	.loc_0xB0:
	  li        r3, 0
	  b         .loc_0xBC

	.loc_0xB8:
	  li        r3, 0

	.loc_0xBC:
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
 * Address:	801AEC20
 * Size:	000008
 */
f32 TAIAfireBreath::getAttackAnimSpeed(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x49A8(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AEC28
 * Size:	000128
 */
bool TAIAflickCheck::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  li        r31, 0
	  stw       r30, 0x30(r1)
	  mr        r30, r4
	  stw       r29, 0x2C(r1)
	  mr        r29, r3
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r3, 0
	  bge-      .loc_0xB0
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x18(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x18(r1)
	  subi      r0, r3, 0x2A84
	  stw       r0, 0x18(r1)
	  addi      r4, r1, 0x18
	  addi      r3, r30, 0
	  stw       r30, 0x1C(r1)
	  bl        -0x66834
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  bl        -0x666F8
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x49B0(r2)
	  stw       r0, 0x24(r1)
	  lis       r0, 0x4330
	  lfs       f0, 0x340(r30)
	  stw       r0, 0x20(r1)
	  lfd       f1, 0x20(r1)
	  fsubs     f1, f1, f2
	  fcmpo     cr0, f0, f1
	  cror      2, 0x1, 0x2
	  mfcr      r0
	  rlwinm    r31,r0,3,31,31
	  b         .loc_0xF8

	.loc_0xB0:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r30
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x49B0(r2)
	  stw       r0, 0x24(r1)
	  lis       r0, 0x4330
	  lfs       f0, 0x340(r30)
	  stw       r0, 0x20(r1)
	  lfd       f1, 0x20(r1)
	  fsubs     f1, f1, f2
	  fcmpo     cr0, f0, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xF8
	  li        r31, 0x1

	.loc_0xF8:
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x108
	  lfs       f0, -0x49D0(r2)
	  stfs      f0, 0x340(r30)

	.loc_0x108:
	  mr        r3, r31
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AED50
 * Size:	000008
 */
int TAIAflickCheck::getDamageCountLimit(Teki&) { return mDamageCountLimit; }

/*
 * --INFO--
 * Address:	801AED58
 * Size:	000094
 */
void TAIAflicking::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  bl        -0x20F4
	  addi      r3, r1, 0x1C
	  addi      r4, r13, 0x17C4
	  addi      r5, r13, 0x17C8
	  addi      r6, r13, 0x17CC
	  bl        -0x177C64
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x1C
	  addi      r5, r1, 0x20
	  addi      r6, r1, 0x24
	  bl        -0x151708
	  addi      r3, r1, 0x10
	  addi      r4, r13, 0x17B8
	  addi      r5, r13, 0x17BC
	  addi      r6, r13, 0x17C0
	  bl        -0x177C8C
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x10
	  addi      r5, r1, 0x14
	  addi      r6, r1, 0x18
	  bl        -0x151730
	  mr        r3, r31
	  lwz       r4, -0x9A4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AEDEC
 * Size:	000080
 */
bool TAIAflicking::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x50
	  mr        r3, r30
	  lwz       r4, -0x9A4(r13)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x49D0(r2)
	  li        r31, 0x1
	  stfs      f0, 0x340(r30)
	  b         .loc_0x64

	.loc_0x50:
	  lwz       r12, 0x4(r3)
	  mr        r4, r30
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl

	.loc_0x64:
	  mr        r3, r31
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
 * Address:	801AEE6C
 * Size:	000098
 */
void TAIAflicking::flick(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  mr        r31, r4
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x84
	  lwz       r12, 0x4(r3)
	  mr        r4, r31
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C4(r31)
	  lis       r5, 0x802B
	  subi      r6, r5, 0x3064
	  lwz       r7, 0x84(r3)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3168
	  lwz       r5, 0x4(r7)
	  addi      r4, r1, 0x70
	  addi      r3, r31, 0
	  lwz       r7, 0x0(r5)
	  mr        r5, r4
	  lfs       f0, 0x8C(r7)
	  lfs       f2, 0x84(r7)
	  stw       r6, 0x70(r1)
	  stw       r31, 0x74(r1)
	  stw       r0, 0x70(r1)
	  stfs      f2, 0x78(r1)
	  stfs      f0, 0x7C(r1)
	  stfs      f1, 0x80(r1)
	  bl        -0x67144

	.loc_0x84:
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AEF04
 * Size:	000094
 */
void TAIAflickingReserveMotion::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  bl        -0x2214
	  addi      r3, r1, 0x1C
	  addi      r4, r13, 0x17C4
	  addi      r5, r13, 0x17C8
	  addi      r6, r13, 0x17CC
	  bl        -0x177E10
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x1C
	  addi      r5, r1, 0x20
	  addi      r6, r1, 0x24
	  bl        -0x1518B4
	  addi      r3, r1, 0x10
	  addi      r4, r13, 0x17B8
	  addi      r5, r13, 0x17BC
	  addi      r6, r13, 0x17C0
	  bl        -0x177E38
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x10
	  addi      r5, r1, 0x14
	  addi      r6, r1, 0x18
	  bl        -0x1518DC
	  mr        r3, r31
	  lwz       r4, -0x9A4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AEF98
 * Size:	00009C
 */
bool TAIAflickingReserveMotion::act(Teki&)
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
	  bl        -0x2104
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7C
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x64
	  mr        r3, r30
	  lwz       r4, -0x9A4(r13)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x49D0(r2)
	  li        r31, 0x1
	  stfs      f0, 0x340(r30)
	  b         .loc_0x7C

	.loc_0x64:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r30
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl

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
 * Address:	801AF034
 * Size:	000098
 */
void TAIAflickingReserveMotion::flick(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  mr        r31, r4
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x84
	  lwz       r12, 0x4(r3)
	  mr        r4, r31
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C4(r31)
	  lis       r5, 0x802B
	  subi      r6, r5, 0x3064
	  lwz       r7, 0x84(r3)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3168
	  lwz       r5, 0x4(r7)
	  addi      r4, r1, 0x70
	  addi      r3, r31, 0
	  lwz       r7, 0x0(r5)
	  mr        r5, r4
	  lfs       f0, 0x8C(r7)
	  lfs       f2, 0x84(r7)
	  stw       r6, 0x70(r1)
	  stw       r31, 0x74(r1)
	  stw       r0, 0x70(r1)
	  stfs      f2, 0x78(r1)
	  stfs      f0, 0x7C(r1)
	  stfs      f1, 0x80(r1)
	  bl        -0x6730C

	.loc_0x84:
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AF0CC
 * Size:	000008
 */
f32 TAIAflickingReserveMotion::getFlickDirection(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x49A4(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AF0D4
 * Size:	000074
 */
void TAIAbiteForKabekui::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  bl        -0x23E8
	  lbz       r0, 0x4C8(r30)
	  li        r31, 0
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0x4C8(r30)
	  lwz       r3, 0x420(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  beq-      .loc_0x44
	  bl        -0xCADA4
	  stw       r31, 0x420(r30)

	.loc_0x44:
	  li        r0, 0
	  stw       r0, 0x420(r30)
	  lwz       r3, 0x420(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C
	  bl        -0xCADD0

	.loc_0x5C:
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
 * Address:	801AF148
 * Size:	0000D0
 */
bool TAIAbiteForKabekui::act(Teki&)
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
	  bl        -0x22B4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB0
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x64
	  lwz       r0, 0x420(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x54
	  lwz       r0, 0xC(r29)
	  stw       r0, 0x0(r29)
	  b         .loc_0x5C

	.loc_0x54:
	  lwz       r0, 0x10(r29)
	  stw       r0, 0x0(r29)

	.loc_0x5C:
	  li        r31, 0x1
	  b         .loc_0xB0

	.loc_0x64:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x80
	  lbz       r0, 0x4C8(r30)
	  li        r3, 0x1
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0x4C8(r30)
	  b         .loc_0x98

	.loc_0x80:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x98
	  lbz       r0, 0x4C8(r30)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0x4C8(r30)

	.loc_0x98:
	  lbz       r0, 0x4C8(r30)
	  rlwinm.   r0,r0,25,31,31
	  beq-      .loc_0xB0
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        .loc_0xD0

	.loc_0xB0:
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0xD0:
	*/
}

/*
 * --INFO--
 * Address:	801AF218
 * Size:	0004B4
 */
bool TAIAbiteForKabekui::hitCheck(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x158(r1)
	  stfd      f31, 0x150(r1)
	  stfd      f30, 0x148(r1)
	  stfd      f29, 0x140(r1)
	  stfd      f28, 0x138(r1)
	  stmw      r21, 0x10C(r1)
	  mr        r29, r4
	  addi      r28, r3, 0
	  li        r31, 0
	  lwz       r0, 0x420(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x48C
	  lis       r4, 0x736C
	  lwz       r3, 0x220(r29)
	  addi      r4, r4, 0x6F74
	  bl        -0x125B4C
	  lis       r5, 0x802B
	  lfs       f30, -0x49D0(r2)
	  lis       r4, 0x802B
	  addi      r30, r3, 0
	  subi      r26, r5, 0x3064
	  subi      r25, r4, 0x3244
	  li        r22, 0
	  b         .loc_0x274

	.loc_0x68:
	  lwz       r24, 0x3068(r13)
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x214

	.loc_0x88:
	  cmpwi     r27, -0x1
	  bne-      .loc_0xB0
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r21, r3
	  b         .loc_0xCC

	.loc_0xB0:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r21, r3

	.loc_0xCC:
	  lwz       r12, 0x0(r21)
	  mr        r3, r21
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1F8
	  addi      r3, r30, 0
	  addi      r4, r22, 0
	  addi      r23, r21, 0x94
	  bl        -0x127520
	  stfs      f30, 0xD0(r1)
	  stfs      f30, 0xCC(r1)
	  stfs      f30, 0xC8(r1)
	  lfsu      f0, 0x4(r3)
	  lfs       f1, 0x0(r23)
	  lfs       f4, 0x8(r23)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x4(r23)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0xA8(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0xA8(r1)
	  stfs      f0, 0xC8(r1)
	  stfs      f1, 0xCC(r1)
	  stfs      f3, 0xD0(r1)
	  lfs       f1, 0xC8(r1)
	  lfs       f0, 0xCC(r1)
	  lfs       f2, 0xD0(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1A1734
	  mr        r3, r28
	  fmr       f29, f1
	  lwz       r12, 0x4(r28)
	  mr        r4, r29
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f29, f1
	  bge-      .loc_0x1F8
	  lwz       r3, 0x420(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x1A0
	  beq-      .loc_0x1A0
	  bl        -0xCB040
	  li        r0, 0
	  stw       r0, 0x420(r29)

	.loc_0x1A0:
	  stw       r21, 0x420(r29)
	  lwz       r3, 0x420(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x1B4
	  bl        -0xCB06C

	.loc_0x1B4:
	  addi      r3, r30, 0
	  addi      r4, r22, 0
	  bl        -0x1275E8
	  stw       r26, 0xEC(r1)
	  li        r0, 0x1
	  addi      r4, r1, 0xEC
	  stw       r29, 0xF0(r1)
	  stw       r25, 0xEC(r1)
	  stw       r0, 0xF4(r1)
	  stw       r3, 0xF8(r1)
	  mr        r3, r21
	  lwz       r12, 0x0(r21)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  li        r31, 0x1
	  b         .loc_0x270

	.loc_0x1F8:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x214:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x23C
	  li        r0, 0x1
	  b         .loc_0x268

	.loc_0x23C:
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x264
	  li        r0, 0x1
	  b         .loc_0x268

	.loc_0x264:
	  li        r0, 0

	.loc_0x268:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x88

	.loc_0x270:
	  addi      r22, r22, 0x1

	.loc_0x274:
	  mr        r3, r30
	  bl        -0x127700
	  cmpw      r22, r3
	  blt+      .loc_0x68
	  rlwinm.   r0,r31,0,24,31
	  bne-      .loc_0x48C
	  lwz       r23, 0x3120(r13)
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r6, 0x802B
	  lfs       f29, -0x49D0(r2)
	  lis       r5, 0x802C
	  lis       r4, 0x802D
	  addi      r22, r3, 0
	  subi      r25, r6, 0xF68
	  addi      r26, r5, 0x6964
	  subi      r27, r4, 0x295C
	  addi      r24, r1, 0xD8
	  b         .loc_0x430

	.loc_0x2CC:
	  cmpwi     r22, -0x1
	  bne-      .loc_0x2F0
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x308

	.loc_0x2F0:
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x308:
	  stfs      f29, 0xBC(r1)
	  mr        r21, r3
	  stfs      f29, 0xB8(r1)
	  stfs      f29, 0xB4(r1)
	  lfs       f1, 0x94(r3)
	  lfs       f0, 0x4(r30)
	  lfs       f4, 0x9C(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0xC(r30)
	  lfs       f2, 0x98(r3)
	  lfs       f1, 0x8(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0xA0(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0xA0(r1)
	  stfs      f0, 0xB4(r1)
	  stfs      f1, 0xB8(r1)
	  stfs      f3, 0xBC(r1)
	  lfs       f1, 0xB4(r1)
	  lfs       f0, 0xB8(r1)
	  lfs       f2, 0xBC(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1A1948
	  mr        r3, r28
	  fmr       f30, f1
	  lwz       r12, 0x4(r28)
	  mr        r4, r29
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f30, f1
	  bge-      .loc_0x414
	  stw       r25, 0xD8(r1)
	  li        r4, 0
	  stw       r26, 0xD8(r1)
	  stw       r27, 0xD8(r1)
	  stw       r29, 0xDC(r1)
	  lwz       r3, 0x2C4(r29)
	  lwz       r6, 0x2C8(r29)
	  lwz       r5, 0x84(r3)
	  lwz       r3, 0x34(r6)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f28, 0x30(r5)
	  bl        -0x8C3D0
	  lwz       r3, 0x2C4(r29)
	  fmr       f30, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x8C3E4
	  lwz       r3, 0x2C4(r29)
	  fmr       f31, f1
	  li        r4, 0xA
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x8D138
	  fmuls     f0, f31, f30
	  mr        r3, r29
	  fmr       f2, f28
	  addi      r4, r21, 0
	  addi      r5, r24, 0
	  fmuls     f1, f1, f0
	  bl        -0x67CF4

	.loc_0x414:
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  mr        r4, r22
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3

	.loc_0x430:
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  mr        r4, r22
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x458
	  li        r0, 0x1
	  b         .loc_0x484

	.loc_0x458:
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x480
	  li        r0, 0x1
	  b         .loc_0x484

	.loc_0x480:
	  li        r0, 0

	.loc_0x484:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x2CC

	.loc_0x48C:
	  mr        r3, r31
	  lmw       r21, 0x10C(r1)
	  lwz       r0, 0x15C(r1)
	  lfd       f31, 0x150(r1)
	  lfd       f30, 0x148(r1)
	  lfd       f29, 0x140(r1)
	  lfd       f28, 0x138(r1)
	  addi      r1, r1, 0x158
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AF6CC
 * Size:	000008
 */
f32 TAIAbiteForKabekui::getNaviAttackSize(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x49CC(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AF6D4
 * Size:	000008
 */
f32 TAIAbiteForKabekui::getPikiAttackSize(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x49CC(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AF6DC
 * Size:	000020
 */
void TAIAeatPiki::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x29E4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AF6FC
 * Size:	000080
 */
bool TAIAeatPiki::act(Teki&)
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
	  bl        -0x2868
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x60
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x60
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r30
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  bl        -0xC8F8
	  li        r31, 0x1

	.loc_0x60:
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
 * Address:	801AF77C
 * Size:	000028
 */
void TAIAeatPiki::eatEffect(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0
	  stw       r0, 0x4(r1)
	  li        r5, 0x7D
	  stwu      r1, -0x8(r1)
	  bl        -0x1251DC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AF7A4
 * Size:	000008
 */
f32 TAIAflickingAfterMotionLoop::getFrameMax(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0xC(r3)
	  blr
	*/
}
