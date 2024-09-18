#include "PlantMgr.h"
#include "Generator.h"

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
 * Address:	80119D3C
 * Size:	0000C8
 */
Plant::Plant()
    : AICreature(nullptr)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  bl        -0x9CAEC
	  lis       r3, 0x802C
	  addi      r3, r3, 0x3E74
	  stw       r3, 0x0(r30)
	  addi      r0, r3, 0x114
	  addi      r3, r30, 0x310
	  stw       r0, 0x2B8(r30)
	  bl        0x151C
	  lis       r3, 0x8009
	  subi      r4, r3, 0x5808
	  addi      r3, r30, 0x364
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x3
	  bl        0xFACE0
	  lfs       f0, -0x6038(r2)
	  lis       r3, 0x1
	  li        r4, 0x33
	  stfs      f0, 0x390(r30)
	  subi      r0, r3, 0x1
	  li        r3, 0x14
	  stfs      f0, 0x38C(r30)
	  stfs      f0, 0x388(r30)
	  stw       r4, 0x6C(r30)
	  sth       r0, 0x304(r30)
	  bl        -0xD2DB8
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x98
	  li        r4, 0x8
	  bl        -0x911A0

	.loc_0x98:
	  stw       r31, 0x220(r30)
	  addi      r3, r30, 0x1B8
	  addi      r4, r30, 0x364
	  li        r5, 0x3
	  bl        -0x36164
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
 * Address:	80119E04
 * Size:	000048
 */
void Plant::startMotion(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr.       r31, r3
	  addi      r5, r31, 0
	  beq-      .loc_0x20
	  addi      r5, r5, 0x2B8

	.loc_0x20:
	  addi      r3, r1, 0x10
	  bl        0x5164
	  addi      r4, r3, 0
	  addi      r3, r31, 0x310
	  bl        0x538C
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void Plant::reset(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80119E4C
 * Size:	0000B8
 */
void Plant::startAI(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  stb       r0, 0x30C(r3)
	  lwz       r5, 0x3140(r13)
	  lwz       r0, 0x48(r5)
	  stw       r0, 0x2F00(r13)
	  lwz       r0, 0x68(r5)
	  stw       r0, 0x224(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x6038(r2)
	  addi      r3, r1, 0x10
	  li        r4, 0
	  stfs      f0, 0x308(r31)
	  bl        0x50B8
	  addi      r4, r3, 0
	  addi      r3, r31, 0x310
	  bl        0x5314
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0xB1FBC
	  stfs      f1, 0x98(r31)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r3, 0x3140(r13)
	  lwz       r3, 0x64(r3)
	  bl        -0x9C780
	  lhz       r0, 0x304(r31)
	  cmplwi    r0, 0x7
	  bne-      .loc_0xA4
	  lfs       f0, -0x6034(r2)
	  stfs      f0, 0x308(r31)

	.loc_0xA4:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80119F04
 * Size:	000038
 */
void Plant::doAnimation()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r4, r3, 0
	  stw       r0, 0x4(r1)
	  addi      r3, r4, 0x310
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x340(r4)
	  lfs       f1, 0x308(r4)
	  lwz       r12, 0xC(r12)
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
 * Address:	80119F3C
 * Size:	0000A4
 */
void Plant::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lbz       r0, 0x30C(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x90
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  bl        -0x85A44
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  li        r5, 0
	  bl        -0x859B8
	  lhz       r0, 0x304(r31)
	  cmplwi    r0, 0xB
	  beq-      .loc_0x60
	  cmplwi    r0, 0x7
	  beq-      .loc_0x60
	  addi      r3, r31, 0x40
	  bl        -0x85E00
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x90

	.loc_0x60:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x108(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3140(r13)
	  mr        r4, r31
	  lwz       r3, 0x64(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x90:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80119FE0
 * Size:	0003C0
 */
void Plant::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  stw       r30, 0xA0(r1)
	  mr        r30, r4
	  stw       r29, 0x9C(r1)
	  mr        r29, r3
	  lwz       r5, 0x3140(r13)
	  lhz       r3, 0x304(r3)
	  lwz       r0, 0x338(r29)
	  lwz       r4, 0x40(r5)
	  rlwinm    r3,r3,2,0,29
	  cmplwi    r0, 0
	  lwzx      r31, r4, r3
	  beq-      .loc_0x3A4
	  lwz       r3, 0x220(r29)
	  bl        -0x904D4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x304
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, -0x6030(r2)
	  lfs       f0, -0x6038(r2)
	  fmuls     f5, f2, f1
	  fcmpo     cr0, f5, f0
	  ble-      .loc_0x304
	  lfs       f4, 0x94(r29)
	  fmuls     f1, f2, f5
	  lis       r3, 0x1
	  fadds     f3, f4, f5
	  subi      r0, r3, 0x7FC1
	  fsubs     f2, f4, f5
	  addi      r4, r1, 0x7C
	  stfs      f3, 0x1C(r1)
	  li        r3, 0
	  lfs       f4, 0x98(r29)
	  fadds     f1, f4, f1
	  stfs      f1, 0x20(r1)
	  lfs       f1, 0x9C(r29)
	  stfs      f0, 0x84(r1)
	  fadds     f3, f1, f5
	  fsubs     f1, f1, f5
	  stfs      f0, 0x80(r1)
	  stfs      f2, 0x30(r1)
	  stfs      f0, 0x7C(r1)
	  stfs      f4, 0x34(r1)
	  stfs      f0, 0x90(r1)
	  stfs      f3, 0x24(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f0, 0x8C(r1)
	  stfs      f0, 0x88(r1)
	  lwz       r5, 0x30(r1)
	  lwz       r6, 0x34(r1)
	  stw       r5, 0x7C(r1)
	  lwz       r5, 0x38(r1)
	  stw       r6, 0x80(r1)
	  lwz       r6, 0x1C(r1)
	  stw       r5, 0x84(r1)
	  lwz       r5, 0x20(r1)
	  stw       r6, 0x88(r1)
	  stw       r5, 0x8C(r1)
	  lwz       r5, 0x24(r1)
	  stw       r5, 0x90(r1)
	  lwz       r5, 0x2E4(r30)
	  lwz       r7, 0x4(r5)
	  addi      r6, r5, 0
	  cmpwi     r7, 0
	  mtctr     r7
	  ble-      .loc_0x2D4

	.loc_0x124:
	  lwz       r7, 0x114(r6)
	  lbz       r8, 0x28(r7)
	  cmplwi    r8, 0
	  beq-      .loc_0x2C8
	  li        r8, 0x1
	  slw       r8, r8, r3
	  and.      r9, r0, r8
	  beq-      .loc_0x2C8
	  lbz       r9, 0x154(r5)
	  cmplwi    r9, 0
	  beq-      .loc_0x220
	  lwz       r10, 0x1C(r7)
	  lwz       r9, 0x20(r7)
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0x24(r7)
	  rlwinm    r9,r9,2,0,29
	  lfs       f6, 0x158(r5)
	  lfsx      f2, r4, r10
	  rlwinm    r10,r11,2,0,29
	  lfs       f4, 0x15C(r5)
	  lfsx      f1, r4, r9
	  fadds     f2, f6, f2
	  lfs       f7, 0x0(r7)
	  fadds     f1, f4, f1
	  lfs       f5, 0x4(r7)
	  lfs       f8, 0x160(r5)
	  lfsx      f3, r4, r10
	  fmuls     f2, f7, f2
	  fmuls     f1, f5, f1
	  lfs       f9, 0x8(r7)
	  fadds     f3, f8, f3
	  lfs       f10, 0xC(r7)
	  fadds     f1, f2, f1
	  fmuls     f2, f9, f3
	  fadds     f1, f2, f1
	  fsubs     f1, f1, f10
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1C4
	  li        r0, 0
	  b         .loc_0x2D4

	.loc_0x1C4:
	  lwz       r10, 0x10(r7)
	  lwz       r9, 0x14(r7)
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0x18(r7)
	  rlwinm    r7,r9,2,0,29
	  lfsx      f2, r4, r10
	  lfsx      f1, r4, r7
	  rlwinm    r7,r11,2,0,29
	  fadds     f2, f6, f2
	  lfsx      f3, r4, r7
	  fadds     f1, f4, f1
	  fadds     f3, f8, f3
	  fmuls     f2, f7, f2
	  fmuls     f1, f5, f1
	  fmuls     f3, f9, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f1, f1, f10
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2C8
	  andc      r0, r0, r8
	  b         .loc_0x2C8

	.loc_0x220:
	  lwz       r10, 0x1C(r7)
	  lwz       r9, 0x20(r7)
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0x24(r7)
	  rlwinm    r9,r9,2,0,29
	  lfs       f5, 0x0(r7)
	  lfsx      f2, r4, r10
	  rlwinm    r10,r11,2,0,29
	  lfs       f4, 0x4(r7)
	  lfsx      f1, r4, r9
	  fmuls     f2, f5, f2
	  lfs       f6, 0x8(r7)
	  fmuls     f1, f4, f1
	  lfsx      f3, r4, r10
	  lfs       f7, 0xC(r7)
	  fmuls     f3, f6, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f1, f1, f7
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x27C
	  li        r0, 0
	  b         .loc_0x2D4

	.loc_0x27C:
	  lwz       r10, 0x10(r7)
	  lwz       r9, 0x14(r7)
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0x18(r7)
	  rlwinm    r7,r9,2,0,29
	  lfsx      f2, r4, r10
	  lfsx      f1, r4, r7
	  rlwinm    r7,r11,2,0,29
	  fmuls     f2, f5, f2
	  lfsx      f3, r4, r7
	  fmuls     f1, f4, f1
	  fmuls     f3, f6, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f1, f1, f7
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2C8
	  andc      r0, r0, r8

	.loc_0x2C8:
	  addi      r6, r6, 0x4
	  addi      r3, r3, 0x1
	  bdnz+     .loc_0x124

	.loc_0x2D4:
	  cmpwi     r0, 0
	  bne-      .loc_0x304
	  lbz       r0, 0x394(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x304
	  lwz       r3, 0x2E8(r29)
	  addi      r4, r29, 0
	  li        r5, 0
	  bl        -0x9CB7C
	  li        r0, 0x1
	  stb       r0, 0x30C(r29)
	  b         .loc_0x3A4

	.loc_0x304:
	  li        r0, 0
	  stb       r0, 0x30C(r29)
	  addi      r3, r29, 0x228
	  addi      r4, r29, 0x7C
	  stb       r0, 0x394(r29)
	  addi      r5, r29, 0x88
	  addi      r6, r29, 0x94
	  bl        -0xDC20C
	  lwz       r3, 0x2E4(r30)
	  addi      r4, r29, 0x228
	  addi      r5, r1, 0x3C
	  addi      r3, r3, 0x1E0
	  bl        -0xDC240
	  addi      r3, r29, 0x310
	  lwz       r12, 0x340(r29)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  addi      r4, r30, 0
	  addi      r5, r1, 0x3C
	  li        r6, 0
	  bl        -0xE5028
	  lwz       r12, 0x3B4(r30)
	  lis       r4, 0x803A
	  mr        r3, r30
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  mr        r4, r30
	  lwz       r5, 0x2E4(r30)
	  li        r6, 0
	  bl        -0xE9F04
	  lwz       r3, 0x220(r29)
	  addi      r4, r30, 0
	  li        r5, 0
	  bl        -0x90894

	.loc_0x3A4:
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  lwz       r29, 0x9C(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011A3A0
 * Size:	000004
 */
void Plant::doKill() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000170
 */
PlantAI::PlantAI()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011A3A4
 * Size:	0000AC
 */
bool PlantAI::OpponentMove::satisfy(AICreature*)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  lwz       r3, 0x2BC(r4)
	  lfs       f0, -0x6038(r2)
	  lfs       f2, 0x70(r3)
	  lfs       f1, 0x74(r3)
	  fmuls     f2, f2, f2
	  lfs       f3, 0x78(r3)
	  fmuls     f1, f1, f1
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x8C
	  fsqrte    f1, f4
	  lfd       f3, -0x6028(r2)
	  lfd       f2, -0x6020(r2)
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
	  stfs      f0, 0x14(r1)
	  lfs       f4, 0x14(r1)

	.loc_0x8C:
	  lfs       f0, -0x6018(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xA0
	  li        r3, 0x1
	  b         .loc_0xA4

	.loc_0xA0:
	  li        r3, 0

	.loc_0xA4:
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011A450
 * Size:	000094
 */
void PlantAI::WaitInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lhz       r0, 0x304(r4)
	  cmplwi    r0, 0x7
	  bne-      .loc_0x54
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lfs       f1, -0x6034(r2)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x80

	.loc_0x54:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x150(r12)
	  mtlr      r12
	  blrl

	.loc_0x80:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011A4E4
 * Size:	000064
 */
void PlantAI::TouchInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lhz       r0, 0x304(r4)
	  cmplwi    r0, 0x7
	  beq-      .loc_0x50
	  lwz       r3, 0x2BC(r31)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x36
	  bne-      .loc_0x38
	  li        r3, 0x135
	  bl        -0x7513C

	.loc_0x38:
	  mr        r3, r31
	  lfs       f1, -0x6034(r2)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl

	.loc_0x50:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011A548
 * Size:	000478
 */
PlantMgr::PlantMgr(MapMgr*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stmw      r25, 0x84(r1)
	  addi      r27, r4, 0
	  li        r30, 0
	  addi      r29, r5, 0x38A8
	  subi      r4, r13, 0x1F28
	  stw       r3, 0x8(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x2374
	  lwz       r28, 0x8(r1)
	  stw       r28, 0x7C(r1)
	  stw       r0, 0x0(r28)
	  lwz       r31, 0x7C(r1)
	  stw       r30, 0x4(r31)
	  addi      r3, r31, 0x8
	  bl        -0xC78EC
	  lis       r3, 0x802C
	  subi      r3, r3, 0x4F80
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  lis       r3, 0x802C
	  stw       r0, 0x8(r31)
	  subi      r3, r3, 0x51A8
	  lis       r4, 0x8022
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  lis       r3, 0x8022
	  stw       r0, 0x8(r31)
	  addi      r25, r4, 0x738C
	  addi      r26, r3, 0x737C
	  stw       r25, 0x28(r31)
	  addi      r3, r31, 0x28
	  subi      r4, r13, 0x1F20
	  stw       r26, 0x28(r31)
	  stw       r30, 0x38(r31)
	  stw       r30, 0x34(r31)
	  stw       r30, 0x30(r31)
	  bl        -0xF5714
	  lis       r3, 0x802C
	  subi      r0, r3, 0x102C
	  stw       r0, 0x28(r31)
	  lis       r3, 0x802C
	  addi      r4, r3, 0x3B08
	  stw       r30, 0x3C(r31)
	  addi      r0, r4, 0x18
	  addi      r3, r28, 0x4C
	  stw       r4, 0x0(r28)
	  addi      r4, r29, 0x1C
	  stw       r0, 0x8(r28)
	  stw       r25, 0x4C(r28)
	  stw       r26, 0x4C(r28)
	  stw       r30, 0x5C(r28)
	  stw       r30, 0x58(r28)
	  stw       r30, 0x54(r28)
	  bl        -0xF5758
	  lis       r3, 0x802C
	  addi      r0, r3, 0x3C00
	  stw       r0, 0x4C(r28)
	  addi      r0, r29, 0x28
	  cmplwi    r28, 0
	  stw       r30, 0x5C(r28)
	  addi      r5, r28, 0
	  stw       r30, 0x58(r28)
	  stw       r30, 0x54(r28)
	  stw       r0, 0x50(r28)
	  stw       r27, 0x48(r28)
	  beq-      .loc_0x11C
	  addi      r5, r5, 0x8

	.loc_0x11C:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r4, r29, 0x10
	  bl        -0xC7910
	  bl        0xAD4
	  lwz       r27, 0x8(r1)
	  stw       r3, 0x44(r27)
	  li        r3, 0x30
	  bl        -0xD3680
	  stw       r3, 0x40(r27)
	  li        r4, 0
	  li        r6, 0x8
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x0(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x4(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x8(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0xC(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x10(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x14(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x18(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x1C(r3)
	  b         .loc_0x45C

	.loc_0x190:
	  subfic    r0, r6, 0xC
	  cmpwi     r6, 0xC
	  mtctr     r0
	  bge-      .loc_0x1B4

	.loc_0x1A0:
	  lwz       r3, 0x8(r1)
	  lwz       r3, 0x40(r3)
	  stwx      r4, r3, r5
	  addi      r5, r5, 0x4
	  bdnz+     .loc_0x1A0

	.loc_0x1B4:
	  li        r3, 0x1C
	  bl        -0xD36FC
	  addi      r30, r3, 0
	  mr.       r27, r30
	  beq-      .loc_0x308
	  mr        r3, r27
	  bl        -0x9D230
	  lis       r3, 0x802C
	  addi      r0, r3, 0x3DB0
	  stw       r0, 0x0(r30)
	  li        r3, 0x14
	  bl        -0xD3724
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x214
	  addi      r3, r31, 0
	  addi      r4, r29, 0x1C
	  bl        -0xE5788
	  lis       r3, 0x802B
	  subi      r0, r3, 0x26FC
	  lis       r3, 0x802C
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x3D18
	  stw       r0, 0x0(r31)

	.loc_0x214:
	  li        r0, 0x2
	  stw       r0, 0xC(r30)
	  li        r0, 0
	  stw       r0, 0x8(r30)
	  lwz       r0, 0xC(r30)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xD3770
	  stw       r3, 0x4(r30)
	  lwz       r0, 0xC(r30)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xD3780
	  stw       r3, 0x10(r30)
	  lwz       r0, 0xC(r30)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xD3790
	  stw       r3, 0x14(r30)
	  li        r3, 0x4
	  bl        -0xD379C
	  mr.       r6, r3
	  beq-      .loc_0x27C
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x3CB4
	  stw       r0, 0x0(r3)

	.loc_0x27C:
	  addi      r3, r27, 0
	  li        r4, 0
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x9D260
	  li        r3, 0x4
	  bl        -0xD37DC
	  mr.       r6, r3
	  beq-      .loc_0x2BC
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x3C88
	  stw       r0, 0x0(r3)

	.loc_0x2BC:
	  addi      r3, r27, 0
	  li        r4, 0x1
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x9D2A0
	  lwz       r5, 0x2F40(r13)
	  addi      r3, r27, 0
	  li        r4, 0
	  li        r6, 0x1
	  bl        -0x9D1CC
	  addi      r4, r31, 0
	  addi      r3, r3, 0x20
	  bl        -0xDA260
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r27, 0
	  li        r4, 0x1
	  li        r6, 0
	  bl        -0x9D1EC

	.loc_0x308:
	  lwz       r4, 0x8(r1)
	  li        r3, 0x58
	  stw       r30, 0x64(r4)
	  bl        -0xD3858
	  mr.       r25, r3
	  beq-      .loc_0x42C
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C8
	  stw       r0, 0x54(r25)
	  li        r0, 0
	  addi      r3, r1, 0x4C
	  stw       r0, 0x0(r25)
	  subi      r4, r13, 0x1F18
	  bl        -0xC9DAC
	  lwz       r0, 0x4C(r1)
	  addi      r5, r1, 0x44
	  addi      r4, r25, 0
	  stw       r0, 0x44(r1)
	  addi      r3, r25, 0x4
	  bl        -0xBBE1C
	  lis       r3, 0x802A
	  addi      r27, r3, 0x6098
	  stw       r27, 0xC(r25)
	  addi      r3, r1, 0x54
	  subi      r4, r13, 0x1F14
	  lfs       f0, -0x6014(r2)
	  stfs      f0, 0x10(r25)
	  bl        -0xC9DE4
	  lwz       r0, 0x54(r1)
	  addi      r5, r1, 0x40
	  addi      r4, r25, 0
	  stw       r0, 0x40(r1)
	  addi      r3, r25, 0x14
	  bl        -0xBBE54
	  stw       r27, 0x1C(r25)
	  addi      r3, r1, 0x5C
	  subi      r4, r13, 0x1F10
	  lfs       f0, -0x6014(r2)
	  stfs      f0, 0x20(r25)
	  bl        -0xC9E14
	  lwz       r0, 0x5C(r1)
	  addi      r5, r1, 0x3C
	  addi      r4, r25, 0
	  stw       r0, 0x3C(r1)
	  addi      r3, r25, 0x24
	  bl        -0xBBE84
	  stw       r27, 0x2C(r25)
	  addi      r3, r1, 0x64
	  subi      r4, r13, 0x1F0C
	  lfs       f0, -0x6010(r2)
	  stfs      f0, 0x30(r25)
	  bl        -0xC9E44
	  lwz       r0, 0x64(r1)
	  addi      r5, r1, 0x38
	  addi      r4, r25, 0
	  stw       r0, 0x38(r1)
	  addi      r3, r25, 0x34
	  bl        -0xBBEB4
	  stw       r27, 0x3C(r25)
	  addi      r3, r1, 0x6C
	  subi      r4, r13, 0x1F08
	  lfs       f0, -0x600C(r2)
	  stfs      f0, 0x40(r25)
	  bl        -0xC9E74
	  lwz       r0, 0x6C(r1)
	  addi      r5, r1, 0x34
	  addi      r4, r25, 0
	  stw       r0, 0x34(r1)
	  addi      r3, r25, 0x44
	  bl        -0xBBEE4
	  stw       r27, 0x4C(r25)
	  lfs       f0, -0x6008(r2)
	  stfs      f0, 0x50(r25)

	.loc_0x42C:
	  lwz       r4, 0x8(r1)
	  li        r3, 0x18
	  stw       r25, 0x68(r4)
	  bl        -0xD397C
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x450
	  li        r4, 0x3E8
	  bl        -0xE589C

	.loc_0x450:
	  lwz       r3, 0x8(r1)
	  stw       r25, 0x6C(r3)
	  b         .loc_0x464

	.loc_0x45C:
	  rlwinm    r5,r6,2,0,29
	  b         .loc_0x190

	.loc_0x464:
	  lmw       r25, 0x84(r1)
	  lwz       r0, 0xA4(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void PlantMgr::getPlantName(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011A9C0
 * Size:	0000EC
 */
void PlantMgr::initialise()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802C
	  stw       r0, 0x4(r1)
	  lis       r5, 0x802C
	  stwu      r1, -0x330(r1)
	  stmw      r25, 0x314(r1)
	  addi      r28, r4, 0x390C
	  lis       r4, 0x803A
	  addi      r25, r3, 0
	  subi      r31, r4, 0x2848
	  addi      r30, r5, 0x393C
	  li        r26, 0
	  li        r27, 0

	.loc_0x34:
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  bl        0x188
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC4
	  lwz       r29, 0x0(r28)
	  addi      r4, r30, 0
	  addi      r3, r1, 0x20C
	  crclr     6, 0x6
	  addi      r5, r29, 0
	  bl        0xFBB7C
	  addi      r5, r29, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x10C
	  subi      r4, r13, 0x1ECC
	  bl        0xFBB68
	  addi      r5, r29, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0xC
	  subi      r4, r13, 0x1EC8
	  bl        0xFBB54
	  li        r3, 0x18
	  bl        -0xD3A48
	  mr.       r29, r3
	  beq-      .loc_0xBC
	  addi      r3, r31, 0
	  addi      r4, r1, 0x20C
	  li        r5, 0x1
	  bl        -0xC7D54
	  lwz       r5, 0x0(r28)
	  mr        r4, r3
	  addi      r3, r29, 0
	  addi      r6, r1, 0xC
	  bl        0x13C

	.loc_0xBC:
	  lwz       r3, 0x40(r25)
	  stwx      r29, r3, r27

	.loc_0xC4:
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0xC
	  addi      r28, r28, 0x4
	  addi      r27, r27, 0x4
	  blt+      .loc_0x34
	  lmw       r25, 0x314(r1)
	  lwz       r0, 0x334(r1)
	  addi      r1, r1, 0x330
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011AAAC
 * Size:	0000D8
 */
Plant* PlantMgr::createObject()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x398
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  bl        -0xD3AC0
	  mr.       r31, r3
	  beq-      .loc_0xBC
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x9D86C
	  lis       r3, 0x802C
	  addi      r3, r3, 0x3E74
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x114
	  addi      r3, r31, 0x310
	  stw       r0, 0x2B8(r31)
	  bl        0x79C
	  lis       r3, 0x8009
	  subi      r4, r3, 0x5808
	  addi      r3, r31, 0x364
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x3
	  bl        0xF9F60
	  lfs       f0, -0x6038(r2)
	  lis       r3, 0x1
	  li        r4, 0x33
	  stfs      f0, 0x390(r31)
	  subi      r0, r3, 0x1
	  li        r3, 0x14
	  stfs      f0, 0x38C(r31)
	  stfs      f0, 0x388(r31)
	  stw       r4, 0x6C(r31)
	  sth       r0, 0x304(r31)
	  bl        -0xD3B38
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xA8
	  li        r4, 0x8
	  bl        -0x91F20

	.loc_0xA8:
	  stw       r30, 0x220(r31)
	  addi      r3, r31, 0x1B8
	  addi      r4, r31, 0x364
	  li        r5, 0x3
	  bl        -0x36EE4

	.loc_0xBC:
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
 * Address:	8011AB84
 * Size:	000030
 */
void PlantMgr::usePlantType(int)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x5C(r3)
	  b         .loc_0x20

	.loc_0x8:
	  lwz       r0, 0x14(r3)
	  cmpw      r0, r4
	  bne-      .loc_0x1C
	  li        r3, 0x1
	  blr

	.loc_0x1C:
	  lwz       r3, 0xC(r3)

	.loc_0x20:
	  cmplwi    r3, 0
	  bne+      .loc_0x8
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void PlantMgr::addUseList(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000150
 */
void PlantMgr::birth()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011ABB4
 * Size:	000118
 */
PlantShapeObject::PlantShapeObject(Shape*, char*, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r7, 0x8023
	  stw       r0, 0x4(r1)
	  subi      r0, r7, 0x7730
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  addi      r31, r3, 0
	  stw       r30, 0xA0(r1)
	  stw       r29, 0x9C(r1)
	  mr.       r29, r5
	  stw       r28, 0x98(r1)
	  mr        r28, r4
	  stw       r0, 0x14(r3)
	  li        r0, 0
	  stw       r0, 0x8(r3)
	  lfs       f0, -0x6038(r2)
	  stfs      f0, 0xC(r3)
	  lfs       f0, -0x6034(r2)
	  stfs      f0, 0x10(r3)
	  stw       r28, 0x0(r3)
	  lwz       r4, 0x3140(r13)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x6C(r4)
	  stw       r0, 0x24(r3)
	  beq-      .loc_0xB8
	  lis       r3, 0x802C
	  crclr     6, 0x6
	  addi      r4, r3, 0x3954
	  addi      r5, r6, 0
	  addi      r3, r1, 0x18
	  bl        0xFB96C
	  li        r3, 0xB8
	  bl        -0xD3C30
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xA8
	  lis       r6, 0x1
	  addi      r4, r28, 0
	  addi      r5, r1, 0x18
	  subi      r6, r6, 0x8000
	  li        r7, 0
	  bl        -0xCA3B4

	.loc_0xA8:
	  stw       r30, 0x4(r31)
	  lwz       r3, 0x4(r31)
	  stw       r29, 0x4(r3)
	  b         .loc_0xE4

	.loc_0xB8:
	  li        r3, 0xB8
	  bl        -0xD3C6C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xE0
	  addi      r4, r28, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  bl        -0xCA3EC

	.loc_0xE0:
	  stw       r30, 0x4(r31)

	.loc_0xE4:
	  lwz       r3, 0x0(r31)
	  addi      r5, r31, 0x8
	  li        r4, 0
	  bl        -0xE5C40
	  mr        r3, r31
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  lwz       r29, 0x9C(r1)
	  lwz       r28, 0x98(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
GenObjectPlant::GenObjectPlant()
    : GenObject('plnt', "")
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011ACCC
 * Size:	000078
 */
static GenObjectPlant* makeObjectPlant()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x1C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  bl        -0xD3CDC
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x60
	  lis       r4, 0x802C
	  lis       r5, 0x802C
	  addi      r6, r4, 0x3974
	  lis       r4, 0x706C
	  addi      r5, r5, 0x3968
	  addi      r4, r4, 0x6E74
	  bl        -0x40054
	  lis       r3, 0x802C
	  subi      r0, r3, 0x5490
	  lis       r3, 0x802C
	  stw       r0, 0x4(r31)
	  addi      r0, r3, 0x39F8
	  stw       r0, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x18(r31)

	.loc_0x60:
	  mr        r3, r31
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011AD44
 * Size:	00008C
 */
void GenObjectPlant::initialise()
{
	/*
	.loc_0x0:
	  lwz       r7, 0x3074(r13)
	  lwz       r5, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  cmpw      r5, r0
	  bgelr-
	  lis       r4, 0x706C
	  lwz       r3, 0x8(r7)
	  addi      r4, r4, 0x6E74
	  rlwinm    r0,r5,4,0,27
	  stwx      r4, r3, r0
	  lis       r6, 0x8012
	  lis       r4, 0x802C
	  lwz       r0, 0x0(r7)
	  lis       r3, 0x7630
	  lwz       r5, 0x8(r7)
	  subi      r6, r6, 0x5334
	  rlwinm    r0,r0,4,0,27
	  add       r5, r5, r0
	  stw       r6, 0x4(r5)
	  addi      r5, r4, 0x3984
	  addi      r4, r3, 0x2E30
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
 * Address:	8011ADD0
 * Size:	000040
 */
void GenObjectPlant::doRead(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x4(r4)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x18(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011AE10
 * Size:	0000CC
 */
void GenObjectPlant::updateUseList(Generator*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  lwz       r29, 0x3140(r13)
	  lwz       r31, 0x18(r3)
	  lwz       r3, 0x5C(r29)
	  b         .loc_0x40

	.loc_0x28:
	  lwz       r0, 0x14(r3)
	  cmpw      r0, r31
	  bne-      .loc_0x3C
	  li        r0, 0x1
	  b         .loc_0x4C

	.loc_0x3C:
	  lwz       r3, 0xC(r3)

	.loc_0x40:
	  cmplwi    r3, 0
	  bne+      .loc_0x28
	  li        r0, 0

	.loc_0x4C:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0xB0
	  li        r3, 0x18
	  bl        -0xD3E64
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xA0
	  lis       r3, 0x802C
	  addi      r4, r3, 0x38C4
	  addi      r3, r30, 0
	  bl        -0xE5ECC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x3C00
	  stw       r0, 0x0(r30)
	  li        r4, 0
	  lis       r3, 0x802C
	  stw       r4, 0x10(r30)
	  addi      r0, r3, 0x38D0
	  stw       r4, 0xC(r30)
	  stw       r4, 0x8(r30)
	  stw       r0, 0x4(r30)

	.loc_0xA0:
	  stw       r31, 0x14(r30)
	  addi      r4, r30, 0
	  addi      r3, r29, 0x4C
	  bl        -0xDA8E4

	.loc_0xB0:
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
 * Address:	8011AEDC
 * Size:	000190
 */
void* GenObjectPlant::birth(BirthInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r27, 0x14(r1)
	  addi      r30, r3, 0
	  addi      r31, r4, 0
	  li        r3, 0x18
	  lwz       r28, 0x3140(r13)
	  bl        -0xD3EF8
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x74
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x0(r27)
	  li        r29, 0
	  addi      r3, r27, 0
	  stw       r29, 0x10(r27)
	  subi      r4, r13, 0x1F20
	  stw       r29, 0xC(r27)
	  stw       r29, 0x8(r27)
	  bl        -0xF6068
	  lis       r3, 0x802C
	  subi      r0, r3, 0x102C
	  stw       r0, 0x0(r27)
	  stw       r29, 0x14(r27)

	.loc_0x74:
	  li        r3, 0x398
	  bl        -0xD3F50
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x8C
	  bl        -0x1228

	.loc_0x8C:
	  stw       r29, 0x14(r27)
	  addi      r4, r27, 0
	  addi      r3, r28, 0x28
	  bl        -0xDA99C
	  lwz       r29, 0x14(r27)
	  cmplwi    r29, 0
	  addi      r27, r29, 0
	  beq-      .loc_0x178
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r31
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0xC(r31)
	  li        r0, 0x1
	  lwz       r5, 0x10(r31)
	  li        r4, 0x33
	  addi      r3, r29, 0x310
	  stw       r6, 0x88(r29)
	  stw       r5, 0x8C(r29)
	  lwz       r5, 0x14(r31)
	  stw       r5, 0x90(r29)
	  lfs       f0, 0x8C(r29)
	  stfs      f0, 0xA0(r29)
	  lwz       r5, 0x18(r30)
	  stb       r0, 0x394(r29)
	  rlwinm    r0,r5,2,0,29
	  stw       r4, 0x6C(r29)
	  sth       r5, 0x304(r29)
	  lwz       r5, 0x3140(r13)
	  lwz       r4, 0x40(r5)
	  lwz       r6, 0x44(r5)
	  lwzx      r28, r4, r0
	  lwz       r5, 0x4(r28)
	  addi      r4, r28, 0x8
	  bl        0x412C
	  lfs       f0, -0x6038(r2)
	  li        r5, 0
	  li        r6, 0
	  stfs      f0, 0x308(r29)
	  lwz       r3, 0x220(r29)
	  lwz       r4, 0x0(r28)
	  bl        -0x914B0
	  lwz       r5, 0x3140(r13)
	  addi      r3, r27, 0
	  li        r4, 0
	  lwz       r0, 0x64(r5)
	  stw       r0, 0x2E8(r29)
	  lwz       r0, 0x24(r31)
	  stw       r0, 0x64(r29)
	  lfs       f0, -0x6004(r2)
	  stfs      f0, 0x58(r29)
	  lfs       f0, 0x58(r29)
	  stfs      f0, 0x5C(r29)
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x178:
	  mr        r3, r29
	  lmw       r27, 0x14(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011B06C
 * Size:	00002C
 */
void GenObjectPlant::render(Graphics&, Generator*)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x3140(r13)
	  lwz       r5, 0x18(r3)
	  lwz       r3, 0x5C(r4)
	  b         .loc_0x20

	.loc_0x10:
	  lwz       r0, 0x14(r3)
	  cmpw      r0, r5
	  beqlr-
	  lwz       r3, 0xC(r3)

	.loc_0x20:
	  cmplwi    r3, 0
	  bne+      .loc_0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011B098
 * Size:	000084
 */
PlantMgr::~PlantMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr.       r31, r3
	  beq-      .loc_0x6C
	  lis       r3, 0x802C
	  addi      r3, r3, 0x3B08
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x51A8
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x4F80
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)

	.loc_0x5C:
	  extsh.    r0, r4
	  ble-      .loc_0x6C
	  mr        r3, r31
	  bl        -0xD3F54

	.loc_0x6C:
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
 * Address:	8011B11C
 * Size:	000008
 */
f32 Plant::getiMass()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x6038(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011B124
 * Size:	000010
 */
bool Plant::isAlive()
{
	/*
	.loc_0x0:
	  lbz       r0, 0x30C(r3)
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011B134
 * Size:	000008
 */
void Plant::setMotionSpeed(f32)
{
	/*
	.loc_0x0:
	  stfs      f1, 0x308(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011B13C
 * Size:	00000C
 */
void Plant::stopMotion()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x6038(r2)
	  stfs      f0, 0x308(r3)
	  blr
	*/
}
