#include "Pellet.h"
#include "PelletView.h"
#include "StateMachine.h"
#include "Interactions.h"
#include "KEffect.h"

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
 * Address:	80094B14
 * Size:	000044
 */
void PelletMgr::getUfoIndexFromID(u32)
{
	/*
	.loc_0x0:
	  lis       r4, 0x802B
	  subi      r4, r4, 0xD8
	  li        r6, 0

	.loc_0xC:
	  lwz       r5, 0x0(r4)
	  subis     r0, r5, 0x7564
	  cmplwi    r0, 0x6566
	  bne-      .loc_0x24
	  li        r3, -0x1
	  blr

	.loc_0x24:
	  cmplw     r3, r5
	  bne-      .loc_0x34
	  mr        r3, r6
	  blr

	.loc_0x34:
	  addi      r4, r4, 0x4
	  addi      r6, r6, 0x1
	  b         .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80094B58
 * Size:	000018
 */
void PelletMgr::getUfoIDFromIndex(int)
{
	/*
	.loc_0x0:
	  lis       r4, 0x802B
	  rlwinm    r3,r3,2,0,29
	  subi      r0, r4, 0xD8
	  add       r3, r0, r3
	  lwz       r3, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80094B70
 * Size:	000390
 */
PelletConfig::PelletConfig()
    : mPelletName(this, String("new", 0), String("", 0), String("", 0), "x99", nullptr)
    , mPelletType(this, PELTYPE_Blue, 0, 0, "p00", nullptr)
    , mPelletColor(this, PELCOLOR_NULL, 0, 0, "p09", nullptr)
    , mCarryMinPikis(this, 1, 0, 0, "p01", nullptr)
    , mCarryMaxPikis(this, 1, 0, 0, "p02", nullptr)
    , _90(this, 0, 0, 0, "p03", nullptr)
    , _A0(this, 10.0f, 0.0f, 0.0f, "p04", nullptr)
    , _B0(this, 4.0f, 0.0f, 0.0f, "p05", nullptr)
    , _C0(this, 4, 0, 0, "p08", nullptr)
    , mMatchingOnyonSeeds(this, 1, 0, 0, "p06", nullptr)
    , mNonMatchingOnyonSeeds(this, 1, 0, 0, "p07", nullptr)
    , mPelletScale(this, 1.0f, 0.0f, 0.0f, "p10", nullptr)
    , mCarryInfoHeight(this, 30.0f, 0.0f, 0.0f, "p11", nullptr)
    , _110(this, 6, 0, 0, "p12", nullptr)
    , mBounceSoundID(this, 0xFFFFFFFF, 0, 0, "p13", nullptr)
{
	_2C.setID('none');
	_38.setID('none');
	_44.setID('none');
	initCore("pelletConfig");
	_130 = -1;
}

/*
 * --INFO--
 * Address:	80094F00
 * Size:	000074
 */
void PelletConfig::read(RandomAccessStream&)
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
	  bl        -0x36384
	  addi      r3, r30, 0x2C
	  addi      r4, r31, 0
	  bl        -0x50E8C
	  addi      r3, r30, 0x44
	  addi      r4, r31, 0
	  bl        -0x50E98
	  addi      r3, r30, 0x38
	  addi      r4, r31, 0
	  bl        -0x50EA4
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x130(r30)
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
 * Address:	80094F74
 * Size:	0001C8
 */
void PelletView::becomePellet(u32, Vector3f&, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  fmr       f30, f1
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x34(r1)
	  mr        r29, r3
	  lwz       r0, 0x4(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x1A4
	  lwz       r3, 0x301C(r13)
	  mr        r5, r29
	  bl        0x35FC
	  mr.       r31, r3
	  beq-      .loc_0x1A4
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x0(r30)
	  lfs       f2, 0x8(r30)
	  bl        -0x2D0CC
	  fmr       f31, f1
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r30)
	  li        r4, 0x1
	  lfs       f2, 0x8(r30)
	  bl        -0x2CF80
	  lfs       f0, 0x4(r30)
	  fsubs     f2, f0, f31
	  fsubs     f0, f0, f1
	  fabs      f2, f2
	  fabs      f0, f0
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0x9C
	  stfs      f1, 0x4(r30)
	  b         .loc_0xA0

	.loc_0x9C:
	  stfs      f31, 0x4(r30)

	.loc_0xA0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  stfs      f30, 0xA0(r31)
	  addi      r4, r1, 0x20
	  addi      r3, r31, 0xE0
	  lfs       f1, -0x58B4(r13)
	  lfs       f0, -0x58B0(r13)
	  stfs      f1, 0x20(r1)
	  stfs      f30, 0x24(r1)
	  stfs      f0, 0x28(r1)
	  bl        -0x5CD64
	  lfs       f0, -0x58AC(r13)
	  addi      r3, r31, 0
	  li        r4, 0
	  stfs      f0, 0x88(r31)
	  stfs      f30, 0x8C(r31)
	  lfs       f0, -0x58A8(r13)
	  stfs      f0, 0x90(r31)
	  lfs       f0, -0x58A4(r13)
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x58A0(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x589C(r13)
	  stfs      f0, 0x78(r31)
	  lfs       f0, -0x5898(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x5894(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x5890(r13)
	  stfs      f0, 0xAC(r31)
	  lfs       f0, -0x588C(r13)
	  stfs      f0, 0x2B8(r31)
	  lfs       f0, -0x5888(r13)
	  stfs      f0, 0x2BC(r31)
	  lfs       f0, -0x5884(r13)
	  stfs      f0, 0x2C0(r31)
	  lfs       f0, -0x5880(r13)
	  stfs      f0, 0x2C4(r31)
	  lfs       f0, -0x587C(r13)
	  stfs      f0, 0x2C8(r31)
	  lfs       f0, -0x5878(r13)
	  stfs      f0, 0x2CC(r31)
	  lfs       f0, -0x5874(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x5870(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x586C(r13)
	  stfs      f0, 0xC4(r31)
	  lfs       f0, -0x5868(r13)
	  stfs      f0, 0xB0(r31)
	  lfs       f0, -0x5864(r13)
	  stfs      f0, 0xB4(r31)
	  lfs       f0, -0x5860(r13)
	  stfs      f0, 0xB8(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x3084
	  stw       r31, 0x4(r29)

	.loc_0x1A4:
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009513C
 * Size:	000270
 */
Pellet::Pellet()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  stw       r30, 0x10(r1)
	  bl        -0x3294
	  lis       r3, 0x802B
	  subi      r0, r3, 0x246C
	  lis       r3, 0x802B
	  stw       r0, 0x440(r31)
	  addi      r3, r3, 0x3A0
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x120
	  addi      r3, r31, 0x4AC
	  stw       r0, 0x440(r31)
	  lfs       f2, -0x73E8(r2)
	  stfs      f2, 0x44C(r31)
	  fmr       f1, f2
	  fmr       f0, f2
	  stfs      f2, 0x448(r31)
	  stfs      f2, 0x444(r31)
	  stfs      f2, 0x46C(r31)
	  stfs      f2, 0x468(r31)
	  stfs      f2, 0x464(r31)
	  stfs      f1, 0x484(r31)
	  stfs      f1, 0x480(r31)
	  stfs      f1, 0x47C(r31)
	  stfs      f0, 0x49C(r31)
	  stfs      f0, 0x498(r31)
	  stfs      f0, 0x494(r31)
	  bl        0x47B4
	  lis       r3, 0x8009
	  subi      r4, r3, 0x5808
	  addi      r3, r31, 0x578
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x4
	  bl        0x17F89C
	  li        r4, 0
	  stw       r4, 0x5A8(r31)
	  li        r0, 0x1
	  li        r3, 0x28
	  stw       r4, 0x5AC(r31)
	  stw       r4, 0x5B0(r31)
	  stw       r4, 0x5B4(r31)
	  stb       r0, 0x450(r31)
	  lfs       f0, -0x585C(r13)
	  stfs      f0, 0x444(r31)
	  lfs       f0, -0x5858(r13)
	  stfs      f0, 0x448(r31)
	  lfs       f0, -0x5854(r13)
	  stfs      f0, 0x44C(r31)
	  bl        -0x4E20C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xE8
	  bl        0xEA3C

	.loc_0xE8:
	  stw       r30, 0x2C(r31)
	  addi      r4, r31, 0
	  li        r5, 0x2
	  lwz       r3, 0x2C(r31)
	  bl        0xEB00
	  li        r3, 0x18
	  bl        -0x4E238
	  cmplwi    r3, 0
	  beq-      .loc_0x178
	  lis       r4, 0x802B
	  addi      r0, r4, 0x600
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x5F4
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x5E8
	  lis       r4, 0x802B
	  stw       r0, 0x8(r3)
	  addi      r5, r4, 0x5AC
	  stw       r5, 0x0(r3)
	  addi      r0, r5, 0xC
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  addi      r6, r4, 0x2660
	  addi      r0, r5, 0x18
	  stw       r0, 0x8(r3)
	  addi      r5, r6, 0xC
	  addi      r4, r6, 0x18
	  stw       r6, 0x0(r3)
	  li        r0, 0
	  stw       r5, 0x4(r3)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  stw       r0, 0x14(r3)
	  stw       r0, 0x10(r3)

	.loc_0x178:
	  stw       r3, 0x454(r31)
	  li        r4, 0
	  li        r0, 0x34
	  stw       r4, 0x4A8(r31)
	  li        r3, 0x14
	  stw       r4, 0x478(r31)
	  stw       r4, 0x554(r31)
	  stw       r4, 0x55C(r31)
	  lfs       f0, -0x73E8(r2)
	  stfs      f0, 0x560(r31)
	  stw       r0, 0x6C(r31)
	  stw       r4, 0x220(r31)
	  bl        -0x4E2E0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1C0
	  li        r4, 0x6
	  bl        -0xC6C8

	.loc_0x1C0:
	  stw       r30, 0x574(r31)
	  li        r0, 0
	  li        r3, 0x1C
	  stw       r0, 0x474(r31)
	  bl        -0x4E308
	  cmplwi    r3, 0
	  beq-      .loc_0x1FC
	  lis       r4, 0x802B
	  addi      r0, r4, 0x4E8
	  stw       r0, 0x0(r3)
	  li        r0, -0x1
	  lis       r4, 0x802B
	  stw       r0, 0x18(r3)
	  addi      r0, r4, 0xE44
	  stw       r0, 0x0(r3)

	.loc_0x1FC:
	  stw       r3, 0x470(r31)
	  mr        r4, r31
	  lwz       r3, 0x470(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r31, 0x1B8
	  addi      r4, r31, 0x578
	  li        r5, 0x4
	  bl        0x4E920
	  lfs       f0, -0x73F4(r2)
	  addi      r3, r31, 0
	  li        r4, 0
	  stfs      f0, 0x270(r31)
	  lfs       f0, -0x5850(r13)
	  stfs      f0, 0x47C(r31)
	  lfs       f0, -0x584C(r13)
	  stfs      f0, 0x480(r31)
	  lfs       f0, -0x5848(r13)
	  stfs      f0, 0x484(r31)
	  bl        0x2A0
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
 * Address:	800953AC
 * Size:	00003C
 */
bool Pellet::isUfoPartsID(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r4, r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  addi      r3, r1, 0xC
	  bl        -0x5152C
	  lis       r4, 0x752A
	  addi      r3, r1, 0xC
	  addi      r4, r4, 0x2A2A
	  li        r5, 0x2A
	  bl        -0x514EC
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800953E8
 * Size:	000090
 */
void Pellet::startWaterEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  addi      r0, r3, 0x94
	  stwu      r1, -0x68(r1)
	  lfs       f2, -0x73E8(r2)
	  addi      r4, r1, 0xC
	  lfs       f1, -0x73F0(r2)
	  stfs      f2, 0x40(r1)
	  stfs      f2, 0x3C(r1)
	  stfs      f2, 0x38(r1)
	  stfs      f2, 0x4C(r1)
	  stfs      f2, 0x48(r1)
	  stfs      f2, 0x44(r1)
	  stw       r0, 0x58(r1)
	  stfs      f1, 0x5C(r1)
	  stfs      f2, 0x14(r1)
	  lfs       f0, -0x73E4(r2)
	  stfs      f2, 0x10(r1)
	  stfs      f2, 0xC(r1)
	  stfs      f2, 0x20(r1)
	  stfs      f2, 0x1C(r1)
	  stfs      f2, 0x18(r1)
	  lwz       r5, 0x94(r3)
	  lwz       r0, 0x98(r3)
	  stw       r5, 0xC(r1)
	  stw       r0, 0x10(r1)
	  lwz       r0, 0x9C(r3)
	  li        r3, 0x11
	  stw       r0, 0x14(r1)
	  stfs      f1, 0x30(r1)
	  stfs      f0, 0x5C(r1)
	  bl        0x7EE7C
	  lwz       r0, 0x6C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80095478
 * Size:	000030
 */
void Pellet::finishWaterEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x454(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
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
 * Address:	800954A8
 * Size:	000090
 */
void Pellet::doKill()
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
	  bl        0x168
	  li        r31, 0
	  stb       r31, 0x5B8(r30)
	  lwz       r3, 0x4A8(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stw       r31, 0x4A8(r30)

	.loc_0x48:
	  lwz       r3, 0x2C(r30)
	  bl        0xEA8C
	  mr        r3, r30
	  bl        -0x35A8
	  lwz       r3, 0x301C(r13)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x7C(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x1E0
	  bl        -0x38468
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
 * Address:	80095538
 * Size:	00001C
 */
void Pellet::getState()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x474(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x14
	  lwz       r3, 0x4(r3)
	  blr

	.loc_0x14:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80095554
 * Size:	000038
 */
bool Pellet::ignoreAtari(Creature*)
{
	return false;
	/*
	.loc_0x0:
	  lwz       r0, 0x184(r4)
	  cmplw     r0, r3
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  lwz       r0, 0x4A8(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x30
	  cmplw     r4, r0
	  bne-      .loc_0x30
	  li        r3, 0x1
	  blr

	.loc_0x30:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009558C
 * Size:	000008
 */
bool Pellet::isAlive()
{
	return false;
	/*
	.loc_0x0:
	  lbz       r3, 0x5B8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80095594
 * Size:	000048
 */
bool Pellet::isAtari()
{
	return false;
	/*
	.loc_0x0:
	  lwz       r3, 0x474(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x14
	  lwz       r0, 0x4(r3)
	  b         .loc_0x18

	.loc_0x14:
	  li        r0, 0

	.loc_0x18:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x28
	  li        r3, 0
	  blr

	.loc_0x28:
	  cmpwi     r0, 0x3
	  beq-      .loc_0x38
	  cmpwi     r0, 0x1
	  bne-      .loc_0x40

	.loc_0x38:
	  li        r3, 0
	  blr

	.loc_0x40:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800955DC
 * Size:	000050
 */
bool Pellet::isVisible()
{
	return false;
	/*
	.loc_0x0:
	  lwz       r4, 0x474(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x14
	  lwz       r4, 0x4(r4)
	  b         .loc_0x18

	.loc_0x14:
	  li        r4, 0

	.loc_0x18:
	  lbz       r0, 0x5B8(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x2C
	  li        r3, 0
	  blr

	.loc_0x2C:
	  subi      r0, r4, 0x1
	  cmplwi    r0, 0x1
	  ble-      .loc_0x40
	  cmpwi     r4, 0x4
	  bne-      .loc_0x48

	.loc_0x40:
	  li        r3, 0
	  blr

	.loc_0x48:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009562C
 * Size:	000080
 */
void Pellet::setTrySound(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,24,31
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  bne-      .loc_0x38
	  li        r0, 0
	  stb       r0, 0x451(r31)
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xB8
	  bl        -0xB070
	  b         .loc_0x6C

	.loc_0x38:
	  lbz       r0, 0x451(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x6C
	  lfs       f1, -0x73E8(r2)
	  lfs       f0, 0x2D0(r31)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x6C
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xB8
	  bl        -0xB0D8
	  li        r0, 0x1
	  stb       r0, 0x451(r31)

	.loc_0x6C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800956AC
 * Size:	0003A0
 */
void Pellet::startPick()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x9
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stfd      f30, 0x68(r1)
	  stw       r31, 0x64(r1)
	  stw       r30, 0x60(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x5C(r1)
	  stw       r28, 0x58(r1)
	  lwz       r5, 0x2F6C(r13)
	  addi      r3, r5, 0x54
	  bl        -0x1321C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x50
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x9
	  addi      r3, r3, 0x54
	  bl        -0x12FA8

	.loc_0x50:
	  li        r0, 0
	  stb       r0, 0x451(r30)
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0xB8
	  bl        -0xB124
	  lwz       r0, 0xC8(r30)
	  addi      r3, r30, 0
	  rlwinm    r0,r0,0,10,8
	  stw       r0, 0xC8(r30)
	  lwz       r0, 0xC8(r30)
	  rlwinm    r0,r0,0,11,9
	  stw       r0, 0xC8(r30)
	  lbz       r0, 0x438(r30)
	  rlwinm    r0,r0,0,0,30
	  stb       r0, 0x438(r30)
	  lfs       f1, -0x73EC(r2)
	  bl        0x1268
	  lwz       r0, 0x4A8(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x108
	  lbz       r0, 0x452(r30)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0xF0
	  cmplwi    r30, 0
	  addi      r5, r30, 0
	  beq-      .loc_0xC0
	  addi      r5, r5, 0x440

	.loc_0xC0:
	  addi      r3, r1, 0x20
	  li        r4, 0x3
	  bl        0x89818
	  addi      r31, r3, 0
	  addi      r3, r1, 0x28
	  li        r4, 0
	  bl        0x897D4
	  addi      r4, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r30, 0x4AC
	  bl        0x42D4
	  b         .loc_0x108

	.loc_0xF0:
	  addi      r3, r1, 0x18
	  li        r4, 0
	  bl        0x897B4
	  addi      r4, r3, 0
	  addi      r3, r30, 0x4AC
	  bl        0x4310

	.loc_0x108:
	  lwz       r0, 0x4A8(r30)
	  lfs       f30, -0x73E0(r2)
	  cmplwi    r0, 0
	  beq-      .loc_0x120
	  lfs       f30, -0x73F4(r2)
	  b         .loc_0x128

	.loc_0x120:
	  lfs       f0, 0x80(r30)
	  fdivs     f30, f30, f0

	.loc_0x128:
	  lfs       f31, -0x73F0(r2)
	  mr        r3, r30
	  bl        -0x3854
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x140
	  lfs       f31, -0x73DC(r2)

	.loc_0x140:
	  mr        r3, r30
	  fmr       f1, f30
	  bl        -0x2C14
	  addi      r3, r1, 0x44
	  addi      r4, r30, 0
	  bl        -0x4B7C
	  addi      r31, r1, 0x44
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  li        r28, 0x1
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  fmuls     f31, f30, f31
	  mr        r29, r3
	  b         .loc_0x1FC

	.loc_0x180:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x1A8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r5, r3
	  b         .loc_0x1C4

	.loc_0x1A8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r5, r3

	.loc_0x1C4:
	  lwz       r0, 0x6C(r5)
	  cmpwi     r0, 0x37
	  bne-      .loc_0x1D4
	  li        r28, 0

	.loc_0x1D4:
	  lfs       f0, 0x198(r5)
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  fsubs     f0, f0, f31
	  stfs      f0, 0x198(r5)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x1FC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x224
	  li        r0, 0x1
	  b         .loc_0x250

	.loc_0x224:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x24C
	  li        r0, 0x1
	  b         .loc_0x250

	.loc_0x24C:
	  li        r0, 0

	.loc_0x250:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x180
	  rlwinm.   r0,r28,0,24,31
	  bne-      .loc_0x34C
	  mr        r3, r30
	  bl        -0x2D14
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x2F0

	.loc_0x284:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x2AC
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r5, r3
	  b         .loc_0x2C8

	.loc_0x2AC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r5, r3

	.loc_0x2C8:
	  lfs       f0, 0x198(r5)
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  fadds     f0, f0, f31
	  stfs      f0, 0x198(r5)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x2F0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x318
	  li        r0, 0x1
	  b         .loc_0x344

	.loc_0x318:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x340
	  li        r0, 0x1
	  b         .loc_0x344

	.loc_0x340:
	  li        r0, 0

	.loc_0x344:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x284

	.loc_0x34C:
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x94(r30)
	  lfs       f2, 0x9C(r30)
	  bl        -0x2DB04
	  lbz       r0, 0x43C(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x378
	  lfs       f0, 0x98(r30)
	  fadds     f0, f0, f30
	  stfs      f0, 0x98(r30)

	.loc_0x378:
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lfd       f30, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  lwz       r28, 0x58(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80095A4C
 * Size:	000080
 */
void Pellet::finishPick()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0xB9
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r4, r30, 0
	  sth       r31, 0x570(r3)
	  lwz       r0, 0xC8(r30)
	  oris      r0, r0, 0x40
	  stw       r0, 0xC8(r30)
	  bl        -0xB494
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0xB8
	  bl        -0xB4A4
	  lbz       r0, 0x438(r30)
	  addi      r3, r30, 0
	  ori       r0, r0, 0x1
	  stb       r0, 0x438(r30)
	  bl        0xF50
	  mr        r3, r30
	  bl        -0x2EB0
	  sth       r31, 0x490(r30)
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
 * Address:	80095ACC
 * Size:	0000B8
 */
void Pellet::startGoal()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0xB9
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r4, r30, 0
	  sth       r31, 0x570(r3)
	  lwz       r0, 0xC8(r30)
	  oris      r0, r0, 0x40
	  stw       r0, 0xC8(r30)
	  bl        -0xB514
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0xB8
	  bl        -0xB524
	  lbz       r0, 0x438(r30)
	  addi      r3, r30, 0
	  ori       r0, r0, 0x1
	  stb       r0, 0x438(r30)
	  bl        0xED0
	  mr        r3, r30
	  bl        -0x2F30
	  sth       r31, 0x490(r30)
	  addi      r4, r30, 0
	  li        r5, 0x1
	  lwz       r3, 0x470(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stw       r31, 0x478(r30)
	  lfs       f0, -0x5844(r13)
	  stfs      f0, 0x47C(r30)
	  lfs       f0, -0x5840(r13)
	  stfs      f0, 0x480(r30)
	  lfs       f0, -0x583C(r13)
	  stfs      f0, 0x484(r30)
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
 * Address:	80095B84
 * Size:	0000B0
 */
void StateMachine<Pellet>::transit(Pellet*, int)
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
	  lwz       r31, 0x474(r4)
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
	  stw       r3, 0x474(r29)
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
 * Address:	80095C34
 * Size:	000004
 */
void AState<Pellet>::init(Pellet*) { }

/*
 * --INFO--
 * Address:	80095C38
 * Size:	000004
 */
void AState<Pellet>::cleanup(Pellet*) { }

/*
 * --INFO--
 * Address:	80095C3C
 * Size:	00016C
 */
void Pellet::doCarry(Creature*, Vector3f&, u16)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  lhz       r8, 0x490(r3)
	  cmplwi    r8, 0x1
	  bne-      .loc_0x9C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x48C(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x48C(r31)
	  lfs       f1, 0x48C(r31)
	  lfs       f0, -0x73E8(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x50
	  li        r0, 0x2
	  sth       r0, 0x490(r31)

	.loc_0x50:
	  lfs       f2, -0x5838(r13)
	  lfs       f0, 0x0(r5)
	  lfs       f1, 0x8(r5)
	  fmuls     f0, f0, f2
	  fmuls     f1, f1, f2
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x38(r1)
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x4(r5)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x48(r1)
	  stfs      f1, 0x4C(r1)
	  lwz       r3, 0x44(r1)
	  lwz       r0, 0x48(r1)
	  stw       r3, 0x47C(r31)
	  stw       r0, 0x480(r31)
	  lwz       r0, 0x4C(r1)
	  stw       r0, 0x484(r31)
	  b         .loc_0x158

	.loc_0x9C:
	  lwz       r7, 0x478(r31)
	  cmplwi    r7, 0
	  beq-      .loc_0x138
	  lwz       r3, 0x6C(r7)
	  lwz       r0, 0x6C(r4)
	  cmpw      r3, r0
	  beq-      .loc_0x138
	  cmplwi    r8, 0
	  bne-      .loc_0xD4
	  li        r0, 0x1
	  sth       r0, 0x490(r31)
	  lfs       f0, -0x73D8(r2)
	  stfs      f0, 0x48C(r31)
	  b         .loc_0x158

	.loc_0xD4:
	  lwz       r0, 0x184(r7)
	  cmplw     r0, r31
	  bne-      .loc_0xF8
	  lhz       r7, 0x488(r31)
	  rlwinm    r0,r6,0,16,31
	  cmplw     r7, r0
	  ble-      .loc_0xF8
	  bl        -0x12F4
	  b         .loc_0x158

	.loc_0xF8:
	  lwz       r3, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r3, 0x47C(r31)
	  stw       r0, 0x480(r31)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x484(r31)
	  stw       r4, 0x478(r31)
	  sth       r6, 0x488(r31)
	  lwz       r3, 0x478(r31)
	  lwz       r3, 0x6C(r3)
	  bl        -0x1324
	  li        r0, 0x1
	  sth       r0, 0x490(r31)
	  lfs       f0, -0x73D8(r2)
	  stfs      f0, 0x48C(r31)
	  b         .loc_0x158

	.loc_0x138:
	  lwz       r3, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r3, 0x47C(r31)
	  stw       r0, 0x480(r31)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x484(r31)
	  stw       r4, 0x478(r31)
	  sth       r6, 0x488(r31)

	.loc_0x158:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80095DA8
 * Size:	000108
 */
void Pellet::getBottomRadius()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x4A8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xF0

	.loc_0x38:
	  lwz       r3, 0x220(r30)
	  li        r31, 0
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  bl        -0xC2A0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x70
	  lis       r4, 0x6365
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x6E74
	  bl        -0xC6F8
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  li        r31, 0x1

	.loc_0x70:
	  rlwinm.   r0,r31,0,24,31
	  bne-      .loc_0xDC
	  lwz       r3, 0x4A8(r30)
	  cmplwi    r3, 0
	  bne-      .loc_0xD4
	  lbz       r0, 0x3018(r13)
	  extsb.    r0, r0
	  bne-      .loc_0xA0
	  li        r3, 0
	  li        r0, 0x1
	  stw       r3, 0x3014(r13)
	  stb       r0, 0x3018(r13)

	.loc_0xA0:
	  lwz       r3, 0x3014(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x3014(r13)
	  lwz       r0, 0x3014(r13)
	  cmpwi     r0, 0xA
	  ble-      .loc_0xCC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl

	.loc_0xCC:
	  lfs       f1, -0x73F8(r2)
	  b         .loc_0xF0

	.loc_0xD4:
	  lwz       r3, 0x6C(r3)
	  bl        -0x1448

	.loc_0xDC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl

	.loc_0xF0:
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
 * Address:	80095EB0
 * Size:	00001C
 */
Vector3f Pellet::getCentre()
{
	/*
	.loc_0x0:
	  lfs       f0, 0x94(r4)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x98(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x9C(r4)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80095ECC
 * Size:	000048
 */
f32 Pellet::getCylinderHeight()
{
	return 0.0f;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x4A8(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x30
	  mr        r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x38

	.loc_0x30:
	  lwz       r3, 0x55C(r3)
	  lfs       f1, 0x10C(r3)

	.loc_0x38:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80095F14
 * Size:	000078
 */
f32 Pellet::getSize()
{
	return 0.0f;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  lwz       r4, 0x4A8(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x58
	  lwz       r12, 0x0(r4)
	  addi      r3, r1, 0x14
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4A8(r31)
	  lfs       f31, 0x14(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  fmuls     f1, f31, f1
	  b         .loc_0x60

	.loc_0x58:
	  mr        r3, r31
	  bl        -0x1C8

	.loc_0x60:
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80095F8C
 * Size:	00001C
 */
Vector3f PelletView::viewGetScale()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x5900(r13)
	  stfs      f0, 0x0(r3)
	  lfs       f0, -0x58FC(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x58F8(r13)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80095FA8
 * Size:	000008
 */
f32 Pellet::getiMass()
{
	return 0.0f;
	/*
	.loc_0x0:
	  lfs       f1, -0x73E8(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80095FB0
 * Size:	0000E4
 */
void Pellet::startStickTeki(Creature*, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stfd      f29, 0x58(r1)
	  fmr       f29, f1
	  stw       r31, 0x54(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x50(r1)
	  mr        r30, r3
	  addi      r4, r30, 0
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x34
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r4, r31
	  lfs       f31, 0x34(r1)
	  lwz       r12, 0x0(r31)
	  addi      r3, r1, 0x28
	  lfs       f30, 0x3C(r1)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x28(r1)
	  lfs       f0, 0x30(r1)
	  fsubs     f1, f1, f31
	  fsubs     f2, f0, f30
	  bl        0x1859D4
	  lfs       f0, 0xA0(r30)
	  fsubs     f1, f1, f0
	  bl        -0x5DAA8
	  stfs      f1, 0x460(r30)
	  fmr       f1, f29
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  li        r5, 0
	  li        r6, -0x2
	  bl        -0x5994
	  lwz       r0, 0x184(r31)
	  cmplw     r0, r30
	  beq-      .loc_0xB4
	  li        r3, 0
	  b         .loc_0xC0

	.loc_0xB4:
	  mr        r3, r30
	  bl        -0x9BC
	  li        r3, 0x1

	.loc_0xC0:
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lfd       f29, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80096094
 * Size:	000094
 */
void Pellet::endStickTeki(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0xB9
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  addi      r4, r29, 0
	  sth       r31, 0x570(r3)
	  lwz       r0, 0xC8(r29)
	  oris      r0, r0, 0x40
	  stw       r0, 0xC8(r29)
	  bl        -0xBAE4
	  addi      r3, r29, 0
	  addi      r4, r29, 0
	  li        r5, 0xB8
	  bl        -0xBAF4
	  lbz       r0, 0x438(r29)
	  addi      r3, r29, 0
	  ori       r0, r0, 0x1
	  stb       r0, 0x438(r29)
	  bl        0x900
	  mr        r3, r29
	  bl        -0x3500
	  sth       r31, 0x490(r29)
	  mr        r3, r30
	  bl        -0x5890
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
 * Address:	80096128
 * Size:	000174
 */
void Pellet::winnable(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x4E41
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  mr        r29, r3
	  stw       r28, 0x38(r1)
	  addi      r28, r4, 0
	  addi      r4, r5, 0x5649
	  lwz       r3, 0x55C(r3)
	  li        r5, 0x2A
	  addi      r3, r3, 0x2C
	  bl        -0x52278
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x4C
	  li        r3, 0
	  b         .loc_0x154

	.loc_0x4C:
	  addi      r3, r1, 0x28
	  addi      r4, r29, 0
	  bl        -0x54F8
	  addi      r31, r1, 0x28
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  li        r29, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xE4

	.loc_0x7C:
	  cmpwi     r30, -0x1
	  bne-      .loc_0xA0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xB8

	.loc_0xA0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xB8:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xC8
	  addi      r29, r29, 0x1

	.loc_0xC8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xE4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10C
	  li        r0, 0x1
	  b         .loc_0x138

	.loc_0x10C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
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
	  beq+      .loc_0x7C
	  cmpw      r28, r29
	  ble-      .loc_0x150
	  li        r3, 0x1
	  b         .loc_0x154

	.loc_0x150:
	  li        r3, 0

	.loc_0x154:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009629C
 * Size:	000068
 */
void Pellet::stickSlot(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  cmpwi     r31, -0x1
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  beq-      .loc_0x4C
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x5BC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x4C
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x540
	  li        r3, 0x1
	  b         .loc_0x50

	.loc_0x4C:
	  li        r3, 0

	.loc_0x50:
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
 * Address:	80096304
 * Size:	00005C
 */
void Pellet::stickOffSlot(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  cmpwi     r31, -0x1
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  beq-      .loc_0x44
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x554
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x44
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x50C

	.loc_0x44:
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
 * Address:	80096360
 * Size:	00006C
 */
void Pellet::getMinFreeSlotIndex()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  b         .loc_0x40

	.loc_0x20:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x4FC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x3C
	  mr        r3, r31
	  b         .loc_0x54

	.loc_0x3C:
	  addi      r31, r31, 0x1

	.loc_0x40:
	  lwz       r3, 0x55C(r30)
	  lwz       r0, 0x8C(r3)
	  cmpw      r31, r0
	  blt+      .loc_0x20
	  li        r3, -0x1

	.loc_0x54:
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
 * Address:	800963CC
 * Size:	000160
 */
void Pellet::getNearestFreeSlotIndex(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stfd      f30, 0x88(r1)
	  stfd      f29, 0x80(r1)
	  stfd      f28, 0x78(r1)
	  stw       r31, 0x74(r1)
	  li        r31, -0x1
	  stw       r30, 0x70(r1)
	  li        r30, 0
	  stw       r29, 0x6C(r1)
	  mr        r29, r4
	  stw       r28, 0x68(r1)
	  mr        r28, r3
	  lfs       f28, -0x73D4(r2)
	  lfs       f29, -0x73E8(r2)
	  lfd       f30, -0x73D0(r2)
	  lfd       f31, -0x73C8(r2)
	  b         .loc_0x11C

	.loc_0x50:
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        0x460
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x118
	  lfs       f1, -0x73E8(r2)
	  addi      r4, r28, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x3C
	  bl        0x364
	  lfs       f3, 0x40(r1)
	  lfs       f2, 0x4(r29)
	  lfs       f1, 0x3C(r1)
	  lfs       f0, 0x0(r29)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x44(r1)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x8(r29)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f29
	  ble-      .loc_0x108
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0x34(r1)
	  lfs       f2, 0x34(r1)

	.loc_0x108:
	  fcmpo     cr0, f2, f28
	  bge-      .loc_0x118
	  fmr       f28, f2
	  mr        r31, r30

	.loc_0x118:
	  addi      r30, r30, 0x1

	.loc_0x11C:
	  lwz       r3, 0x55C(r28)
	  lwz       r0, 0x8C(r3)
	  cmpw      r30, r0
	  blt+      .loc_0x50
	  mr        r3, r31
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lfd       f30, 0x88(r1)
	  lfd       f29, 0x80(r1)
	  lfd       f28, 0x78(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  lwz       r28, 0x68(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009652C
 * Size:	0000D8
 */
void Pellet::getRandomFreeSlotIndex()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r26, 0x38(r1)
	  mr        r26, r3
	  lwz       r3, 0x55C(r3)
	  lwz       r31, 0x8C(r3)
	  bl        0x181B28
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x73B8(r2)
	  stw       r0, 0x34(r1)
	  lis       r3, 0x4330
	  xoris     r0, r31, 0x8000
	  lfs       f0, -0x73C0(r2)
	  stw       r3, 0x30(r1)
	  lfs       f1, -0x73F0(r2)
	  li        r29, 0x80
	  lfd       f2, 0x30(r1)
	  li        r28, -0x1
	  stw       r0, 0x2C(r1)
	  fsubs     f2, f2, f3
	  li        r27, 0
	  stw       r3, 0x28(r1)
	  fdivs     f2, f2, f0
	  lfd       f0, 0x28(r1)
	  fmuls     f1, f1, f2
	  fsubs     f0, f0, f3
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r30, 0x24(r1)
	  b         .loc_0xB8

	.loc_0x80:
	  addi      r3, r26, 0
	  addi      r4, r27, 0
	  bl        0x2D0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xB4
	  sub.      r0, r27, r30
	  ble-      .loc_0xA0
	  b         .loc_0xA4

	.loc_0xA0:
	  neg       r0, r0

	.loc_0xA4:
	  cmpw      r0, r29
	  bge-      .loc_0xB4
	  mr        r29, r0
	  addi      r28, r27, 0

	.loc_0xB4:
	  addi      r27, r27, 0x1

	.loc_0xB8:
	  cmpw      r27, r31
	  blt+      .loc_0x80
	  mr        r3, r28
	  lmw       r26, 0x38(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80096604
 * Size:	0001A0
 */
void Pellet::getSlotLocalPos(int, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r5, -0x2
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stfd      f30, 0x68(r1)
	  stfd      f29, 0x60(r1)
	  fmr       f29, f1
	  stfd      f28, 0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  bne-      .loc_0x40
	  lfs       f30, 0x460(r31)
	  b         .loc_0x84

	.loc_0x40:
	  lwz       r3, 0x55C(r31)
	  xoris     r0, r5, 0x8000
	  lis       r4, 0x4330
	  stw       r0, 0x4C(r1)
	  lwz       r0, 0x8C(r3)
	  stw       r4, 0x48(r1)
	  xoris     r0, r0, 0x8000
	  lfd       f3, -0x73B8(r2)
	  stw       r0, 0x44(r1)
	  lfd       f0, 0x48(r1)
	  stw       r4, 0x40(r1)
	  lfs       f1, -0x73B0(r2)
	  fsubs     f2, f0, f3
	  lfd       f0, 0x40(r1)
	  fsubs     f0, f0, f3
	  fdivs     f0, f1, f0
	  fmuls     f30, f2, f0

	.loc_0x84:
	  lwz       r0, 0x4A8(r31)
	  lfs       f28, 0x2D0(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xAC
	  mr        r3, r31
	  bl        -0x8F4
	  fadds     f29, f29, f1
	  lfs       f0, 0x7C(r31)
	  fdivs     f29, f29, f0
	  b         .loc_0xB8

	.loc_0xAC:
	  mr        r3, r31
	  bl        -0x90C
	  fadds     f29, f29, f1

	.loc_0xB8:
	  lbz       r0, 0x3010(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x108
	  lbz       r0, 0x439(r31)
	  cmplwi    r0, 0x55
	  beq-      .loc_0xE8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  fsubs     f28, f1, f28

	.loc_0xE8:
	  fmr       f1, f30
	  bl        0x185464
	  fmuls     f31, f29, f1
	  fmr       f1, f30
	  bl        0x1855EC
	  fmuls     f1, f29, f1
	  fmr       f0, f28
	  b         .loc_0x16C

	.loc_0x108:
	  mr        r3, r31
	  bl        -0x4788
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x138
	  fmr       f1, f30
	  bl        0x185434
	  fmuls     f31, f29, f1
	  fmr       f1, f30
	  bl        0x1855BC
	  fmuls     f1, f29, f1
	  fmr       f0, f28
	  b         .loc_0x16C

	.loc_0x138:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  fsubs     f28, f1, f28
	  fmr       f1, f30
	  bl        0x1853FC
	  fmuls     f31, f29, f1
	  fmr       f1, f30
	  bl        0x185584
	  fmuls     f1, f29, f1
	  fmr       f0, f28

	.loc_0x16C:
	  stfs      f1, 0x0(r30)
	  stfs      f0, 0x4(r30)
	  stfs      f31, 0x8(r30)
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lfd       f30, 0x68(r1)
	  lfd       f29, 0x60(r1)
	  lfd       f28, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800967A4
 * Size:	000078
 */
void Pellet::getSlotGlobalPos(int, f32)
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
	  addi      r3, r1, 0x20
	  bl        -0x1C0
	  lfs       f1, 0x20(r1)
	  addi      r3, r1, 0x2C
	  lfs       f0, 0x24(r1)
	  addi      r4, r31, 0x228
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x34(r1)
	  bl        -0x5F09C
	  lfs       f0, 0x2C(r1)
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0x30(r1)
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x34(r1)
	  stfs      f0, 0x8(r30)
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
 * Address:	........
 * Size:	000014
 */
void Pellet::initSlotFlags()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8009681C
 * Size:	000034
 */
void Pellet::setSlotFlag(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, -0x2
	  beqlr-
	  srawi     r5, r4, 0x5
	  rlwinm    r0,r5,2,0,29
	  add       r6, r3, r0
	  rlwinm    r0,r5,5,0,26
	  lwz       r5, 0x564(r6)
	  sub       r0, r4, r0
	  li        r3, 0x1
	  slw       r0, r3, r0
	  or        r0, r5, r0
	  stw       r0, 0x564(r6)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80096850
 * Size:	000034
 */
void Pellet::resetSlotFlag(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, -0x2
	  beqlr-
	  srawi     r5, r4, 0x5
	  rlwinm    r0,r5,2,0,29
	  add       r6, r3, r0
	  rlwinm    r0,r5,5,0,26
	  lwz       r5, 0x564(r6)
	  sub       r0, r4, r0
	  li        r3, 0x1
	  slw       r0, r3, r0
	  andc      r0, r5, r0
	  stw       r0, 0x564(r6)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80096884
 * Size:	000044
 */
void Pellet::isSlotFlag(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, -0x2
	  bne-      .loc_0x10
	  li        r3, 0
	  blr

	.loc_0x10:
	  srawi     r5, r4, 0x5
	  rlwinm    r0,r5,2,0,29
	  add       r3, r3, r0
	  rlwinm    r0,r5,5,0,26
	  lwz       r5, 0x564(r3)
	  sub       r0, r4, r0
	  li        r3, 0x1
	  slw       r0, r3, r0
	  and       r0, r5, r0
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800968C8
 * Size:	0000E0
 */
void Pellet::initPellet(PelletShapeObject*, PelletConfig*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  sth       r0, 0x570(r3)
	  li        r0, 0x1
	  stb       r0, 0x452(r3)
	  stw       r4, 0x554(r3)
	  lbz       r0, 0x28(r4)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x48
	  lbz       r0, 0x452(r30)
	  ori       r0, r0, 0x2
	  stb       r0, 0x452(r30)

	.loc_0x48:
	  stw       r31, 0x55C(r30)
	  li        r5, 0
	  li        r6, 0
	  lwz       r0, 0x574(r30)
	  stw       r0, 0x220(r30)
	  lwz       r4, 0x554(r30)
	  lwz       r3, 0x220(r30)
	  lwz       r4, 0x0(r4)
	  bl        -0xCDCC
	  lfs       f0, 0xFC(r31)
	  stfs      f0, 0x7C(r30)
	  stfs      f0, 0x80(r30)
	  stfs      f0, 0x84(r30)
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, -0x1
	  bne-      .loc_0xB4
	  lwz       r3, 0x55C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xA8
	  lwz       r0, 0x5C(r3)
	  subfic    r0, r0, 0x3
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,24,31
	  b         .loc_0xAC

	.loc_0xA8:
	  li        r0, 0

	.loc_0xAC:
	  cmpwi     r0, 0
	  beq-      .loc_0xC8

	.loc_0xB4:
	  lwz       r3, 0x554(r30)
	  addi      r4, r30, 0x5A8
	  li        r5, 0
	  lwz       r3, 0x0(r3)
	  bl        -0x67060

	.loc_0xC8:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void Pellet::initPellet(PelletView*, PelletConfig*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800969A8
 * Size:	000044
 */
void Pellet::startCarryMotion(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  stfs      f1, 0x560(r3)
	  lwz       r3, 0x4A8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  lwz       r12, 0x0(r3)
	  lfs       f1, 0x560(r4)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800969EC
 * Size:	000004
 */
void PelletView::viewStartTrembleMotion(f32) { }

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void Pellet::stopMotion()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800969F0
 * Size:	000004
 */
void PelletView::viewSetMotionSpeed(f32) { }

/*
 * --INFO--
 * Address:	800969F4
 * Size:	000064
 */
void Pellet::finishMotion()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r3, 0x4A8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x50

	.loc_0x34:
	  addi      r3, r1, 0xC
	  li        r4, -0x1
	  bl        0x88528
	  addi      r4, r3, 0
	  addi      r3, r31, 0x4AC
	  li        r5, 0
	  bl        0x2FD0

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
 * Address:	80096A58
 * Size:	000004
 */
void PelletView::viewFinishMotion() { }

/*
 * --INFO--
 * Address:	80096A5C
 * Size:	000098
 */
void Pellet::init(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  bl        -0xBE6C
	  lwz       r8, 0x554(r31)
	  cmplwi    r8, 0
	  beq-      .loc_0x40
	  lwz       r5, 0x301C(r13)
	  addi      r3, r31, 0x4AC
	  lwz       r6, 0x4(r8)
	  addi      r4, r8, 0x8
	  lwz       r7, 0x1F8(r5)
	  addi      r5, r8, 0x18
	  bl        0x2F0C

	.loc_0x40:
	  li        r4, 0
	  stw       r4, 0x56C(r31)
	  stw       r4, 0x568(r31)
	  stw       r4, 0x564(r31)
	  lbz       r0, 0x438(r31)
	  ori       r0, r0, 0x1
	  stb       r0, 0x438(r31)
	  lwz       r3, 0x55C(r31)
	  lwz       r0, 0x9C(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x74
	  stb       r4, 0x43F(r31)
	  b         .loc_0x7C

	.loc_0x74:
	  li        r0, 0x1
	  stb       r0, 0x43F(r31)

	.loc_0x7C:
	  li        r0, 0
	  sth       r0, 0x490(r31)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80096AF4
 * Size:	000034
 */
bool Pellet::isFree()
{
	return false;
	/*
	.loc_0x0:
	  lwz       r0, 0x564(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x2C
	  lwz       r0, 0x568(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x2C
	  lwz       r0, 0x56C(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x2C
	  li        r3, 0x1
	  blr

	.loc_0x2C:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80096B28
 * Size:	000248
 */
void Pellet::doLoad(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x50(r1)
	  addi      r30, r4, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x450(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x444(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x448(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x44C(r31)
	  lfs       f1, 0x444(r31)
	  lfs       f0, 0x94(r31)
	  lfs       f3, 0x448(r31)
	  lfs       f2, 0x98(r31)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x44C(r31)
	  lfs       f1, 0x9C(r31)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x40(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x44(r1)
	  stfs      f0, 0x48(r1)
	  lfs       f1, 0x40(r1)
	  lfs       f3, 0x48(r1)
	  lfs       f0, 0x44(r1)
	  fmuls     f2, f1, f1
	  fmuls     f3, f3, f3
	  fmuls     f1, f0, f0
	  lfs       f0, -0x73E8(r2)
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x140
	  fsqrte    f1, f4
	  lfd       f3, -0x73D0(r2)
	  lfd       f2, -0x73C8(r2)
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
	  stfs      f0, 0x20(r1)
	  lfs       f4, 0x20(r1)

	.loc_0x140:
	  lfs       f0, -0x73AC(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x168
	  lwz       r3, 0x444(r31)
	  lwz       r0, 0x448(r31)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x44C(r31)
	  stw       r0, 0x9C(r31)
	  b         .loc_0x1E4

	.loc_0x168:
	  lfs       f1, 0x94(r31)
	  bl        0x7BA30
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x198
	  lfs       f1, 0x98(r31)
	  bl        0x7BA20
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x198
	  lfs       f1, 0x9C(r31)
	  bl        0x7BA10
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1B4

	.loc_0x198:
	  lwz       r3, 0x444(r31)
	  lwz       r0, 0x448(r31)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x44C(r31)
	  stw       r0, 0x9C(r31)
	  b         .loc_0x1E4

	.loc_0x1B4:
	  lis       r5, 0x7465
	  lwz       r4, 0x302C(r13)
	  addi      r3, r1, 0x28
	  addi      r5, r5, 0x7374
	  addi      r6, r31, 0x94
	  bl        0x9464
	  lwz       r3, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x9C(r31)

	.loc_0x1E4:
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x2EE18
	  stfs      f1, 0x98(r31)
	  addi      r4, r31, 0
	  li        r5, 0x5
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,10,8
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  oris      r0, r0, 0x40
	  stw       r0, 0xC8(r31)
	  lwz       r3, 0x470(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80096D70
 * Size:	000078
 */
void Pellet::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x452(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x68
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x6
	  bne-      .loc_0x68
	  lwz       r4, 0x55C(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x44
	  lwz       r0, 0x5C(r4)
	  subfic    r0, r0, 0x3
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,24,31
	  b         .loc_0x48

	.loc_0x44:
	  li        r0, 0

	.loc_0x48:
	  cmpwi     r0, 0
	  beq-      .loc_0x68
	  lwz       r5, 0x11C(r4)
	  cmpwi     r5, 0
	  blt-      .loc_0x68
	  addi      r4, r3, 0
	  addi      r5, r5, 0xBE
	  bl        -0xC820

	.loc_0x68:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80096DE8
 * Size:	000094
 */
void Pellet::doSave(RandomAccessStream&)
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
	  lwz       r12, 0x4(r31)
	  lbz       r4, 0x450(r30)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lfs       f1, 0x444(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lfs       f1, 0x448(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lfs       f1, 0x44C(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x30(r12)
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
 * Address:	80096E7C
 * Size:	0003B8
 */
void Pellet::startAI(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB0(r1)
	  stw       r31, 0xAC(r1)
	  addi      r0, r1, 0x5C
	  mr        r31, r4
	  stw       r30, 0xA8(r1)
	  mr        r30, r3
	  mr        r4, r0
	  stw       r29, 0xA4(r1)
	  lfs       f1, -0x5834(r13)
	  lfs       f0, -0x5830(r13)
	  stfs      f1, 0x5C(r1)
	  lfs       f1, 0xA0(r3)
	  addi      r3, r30, 0xE0
	  stfs      f1, 0x60(r1)
	  stfs      f0, 0x64(r1)
	  bl        -0x5EBD8
	  lfs       f0, -0x582C(r13)
	  stfs      f0, 0x88(r30)
	  lfs       f0, 0xA0(r30)
	  stfs      f0, 0x8C(r30)
	  lfs       f0, -0x5828(r13)
	  stfs      f0, 0x90(r30)
	  lwz       r3, 0x94(r30)
	  lwz       r0, 0x98(r30)
	  stw       r3, 0x464(r30)
	  stw       r0, 0x468(r30)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0x46C(r30)
	  lwz       r0, 0xC8(r30)
	  oris      r0, r0, 0x40
	  stw       r0, 0xC8(r30)
	  lbz       r0, 0x450(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xA8
	  lwz       r3, 0x94(r30)
	  lwz       r0, 0x98(r30)
	  stw       r3, 0x444(r30)
	  stw       r0, 0x448(r30)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0x44C(r30)

	.loc_0xA8:
	  li        r29, 0
	  stb       r29, 0x451(r30)
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0xB8
	  bl        -0xC94C
	  lwz       r3, 0x55C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xDC
	  lwz       r0, 0x5C(r3)
	  subfic    r0, r0, 0x3
	  cntlzw    r0, r0
	  rlwinm    r29,r0,27,24,31

	.loc_0xDC:
	  cmpwi     r29, 0
	  beq-      .loc_0x100
	  lwz       r5, 0x11C(r3)
	  cmpwi     r5, 0
	  blt-      .loc_0x100
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  addi      r5, r5, 0xBE
	  bl        -0xC9C4

	.loc_0x100:
	  li        r0, 0x1
	  stb       r0, 0x5B8(r30)
	  lwz       r3, 0x55C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x128
	  lwz       r0, 0x5C(r3)
	  subfic    r0, r0, 0x3
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,24,31
	  b         .loc_0x12C

	.loc_0x128:
	  li        r0, 0

	.loc_0x12C:
	  cmpwi     r0, 0
	  beq-      .loc_0x140
	  lwz       r3, 0x2F28(r13)
	  mr        r4, r30
	  bl        -0x1B98C

	.loc_0x140:
	  li        r0, 0
	  stw       r0, 0x458(r30)
	  li        r29, 0
	  stw       r0, 0x45C(r30)
	  stw       r0, 0x478(r30)
	  lbz       r3, 0x452(r30)
	  cmplwi    r3, 0x3
	  bne-      .loc_0x164
	  li        r29, 0x1

	.loc_0x164:
	  lwz       r0, 0x4A8(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x1D8
	  rlwinm.   r0,r3,0,30,30
	  beq-      .loc_0x1BC
	  cmplwi    r30, 0
	  addi      r5, r30, 0
	  beq-      .loc_0x188
	  addi      r5, r5, 0x440

	.loc_0x188:
	  addi      r3, r1, 0x4C
	  li        r4, 0x3
	  bl        0x87F80
	  addi      r29, r3, 0
	  addi      r3, r1, 0x54
	  li        r4, 0
	  bl        0x87F3C
	  addi      r4, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r30, 0x4AC
	  bl        0x2A3C
	  li        r29, 0
	  b         .loc_0x200

	.loc_0x1BC:
	  addi      r3, r1, 0x44
	  li        r4, 0
	  bl        0x87F18
	  addi      r4, r3, 0
	  addi      r3, r30, 0x4AC
	  bl        0x2A74
	  b         .loc_0x200

	.loc_0x1D8:
	  lfs       f0, -0x73E8(r2)
	  stfs      f0, 0x560(r30)
	  lwz       r3, 0x4A8(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x200
	  lwz       r12, 0x0(r3)
	  lfs       f1, 0x560(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x200:
	  rlwinm.   r0,r29,0,24,31
	  lwz       r0, 0x4A8(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x218
	  cmpwi     r31, 0x1
	  bne-      .loc_0x238

	.loc_0x218:
	  lwz       r3, 0x470(r30)
	  addi      r4, r30, 0
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x254

	.loc_0x238:
	  lwz       r3, 0x470(r30)
	  addi      r4, r30, 0
	  li        r5, 0x2
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x254:
	  lwz       r3, 0x4A8(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x278
	  lwz       r12, 0x0(r3)
	  lfs       f1, -0x73E8(r2)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x280

	.loc_0x278:
	  lfs       f0, -0x73E8(r2)
	  stfs      f0, 0x560(r30)

	.loc_0x280:
	  lwz       r4, 0x55C(r30)
	  addi      r5, r1, 0x98
	  lwz       r3, 0x301C(r13)
	  addi      r6, r1, 0x94
	  lwz       r4, 0x2C(r4)
	  bl        0x1368
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x38C
	  lis       r3, 0x8022
	  addi      r10, r3, 0x23F8
	  lwz       r4, 0x0(r10)
	  lis       r3, 0x8022
	  lwz       r0, 0x4(r10)
	  addi      r9, r3, 0x2408
	  addi      r3, r1, 0x84
	  stw       r4, 0x84(r1)
	  addi      r4, r1, 0x74
	  addi      r5, r1, 0x68
	  stw       r0, 0x88(r1)
	  li        r6, 0
	  li        r7, 0
	  lwz       r8, 0x8(r10)
	  lwz       r0, 0xC(r10)
	  stw       r8, 0x8C(r1)
	  stw       r0, 0x90(r1)
	  lwz       r8, 0x0(r9)
	  lwz       r0, 0x4(r9)
	  stw       r8, 0x74(r1)
	  stw       r0, 0x78(r1)
	  lwz       r8, 0x8(r9)
	  lwz       r0, 0xC(r9)
	  stw       r8, 0x7C(r1)
	  stw       r0, 0x80(r1)
	  lfs       f0, 0x94(r30)
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x9C(r30)
	  lwz       r0, 0x94(r1)
	  stfs      f0, 0x70(r1)
	  rlwinm    r0,r0,2,0,29
	  lfs       f0, 0x6C(r1)
	  lfsx      f1, r3, r0
	  fadds     f0, f0, f1
	  stfs      f0, 0x6C(r1)
	  stfs      f1, 0x4A4(r30)
	  lwz       r3, 0x68(r1)
	  lwz       r0, 0x6C(r1)
	  stw       r3, 0x494(r30)
	  stw       r0, 0x498(r30)
	  lwz       r0, 0x70(r1)
	  stw       r0, 0x49C(r30)
	  lwz       r0, 0x94(r1)
	  lwz       r3, 0x3180(r13)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r4, r0
	  bl        0x10595C
	  cmplwi    r3, 0
	  beq-      .loc_0x380
	  addi      r0, r30, 0x494
	  stw       r0, 0x18(r3)
	  li        r0, 0x5A
	  sth       r0, 0x4A0(r30)
	  b         .loc_0x394

	.loc_0x380:
	  li        r0, 0
	  sth       r0, 0x4A0(r30)
	  b         .loc_0x394

	.loc_0x38C:
	  li        r0, 0
	  sth       r0, 0x4A0(r30)

	.loc_0x394:
	  li        r0, 0x1
	  stb       r0, 0x5B9(r30)
	  lwz       r0, 0xB4(r1)
	  lwz       r31, 0xAC(r1)
	  lwz       r30, 0xA8(r1)
	  lwz       r29, 0xA4(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void Pellet::startAppear()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80097234
 * Size:	000060
 */
void Pellet::doAnimation()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x554(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x30
	  lfs       f1, 0x560(r31)
	  addi      r3, r31, 0x4AC
	  lfs       f2, -0x73EC(r2)
	  bl        0x2888

	.loc_0x30:
	  lwz       r3, 0x4A8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl

	.loc_0x4C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80097294
 * Size:	000004
 */
void PelletView::viewDoAnimation() { }

/*
 * --INFO--
 * Address:	80097298
 * Size:	000088
 */
void Pellet::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x474(r3)
	  cmplwi    r5, 0
	  beq-      .loc_0x20
	  lwz       r6, 0x4(r5)
	  b         .loc_0x24

	.loc_0x20:
	  li        r6, 0

	.loc_0x24:
	  cmpwi     r6, 0x3
	  bne-      .loc_0x3C
	  lwz       r5, 0x301C(r13)
	  lhz       r0, 0x200(r5)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x78

	.loc_0x3C:
	  cmpwi     r6, 0
	  bne-      .loc_0x64
	  lfs       f1, -0x73E8(r2)
	  lfs       f0, 0x2D0(r3)
	  fcmpu     cr0, f1, f0
	  beq-      .loc_0x64
	  lwz       r5, 0x301C(r13)
	  lhz       r0, 0x200(r5)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x78

	.loc_0x64:
	  lwz       r5, 0x301C(r13)
	  lhz       r0, 0x200(r5)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x78
	  bl        -0x50F4

	.loc_0x78:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80097320
 * Size:	000088
 */
void Pellet::postUpdate(int, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x474(r3)
	  cmplwi    r5, 0
	  beq-      .loc_0x20
	  lwz       r6, 0x4(r5)
	  b         .loc_0x24

	.loc_0x20:
	  li        r6, 0

	.loc_0x24:
	  cmpwi     r6, 0x3
	  bne-      .loc_0x3C
	  lwz       r5, 0x301C(r13)
	  lhz       r0, 0x200(r5)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x78

	.loc_0x3C:
	  cmpwi     r6, 0
	  bne-      .loc_0x64
	  lfs       f2, -0x73E8(r2)
	  lfs       f0, 0x2D0(r3)
	  fcmpu     cr0, f2, f0
	  beq-      .loc_0x64
	  lwz       r5, 0x301C(r13)
	  lhz       r0, 0x200(r5)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x78

	.loc_0x64:
	  lwz       r5, 0x301C(r13)
	  lhz       r0, 0x200(r5)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x78
	  bl        -0xBC0C

	.loc_0x78:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800973A8
 * Size:	00094C
 */
void Pellet::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F8(r1)
	  stfd      f31, 0x1F0(r1)
	  stmw      r26, 0x1D8(r1)
	  mr        r31, r3
	  lwz       r4, 0x94(r3)
	  lwz       r0, 0x98(r31)
	  stw       r4, 0x464(r31)
	  stw       r0, 0x468(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x46C(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x114(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  addi      r29, r3, 0
	  beq-      .loc_0xE4
	  lbz       r0, 0x5B9(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xE4
	  lwz       r3, 0x55C(r31)
	  lwz       r0, 0x12C(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0xE4
	  lis       r3, 0x802B
	  rlwinm    r4,r0,2,0,29
	  subi      r0, r3, 0x40
	  add       r3, r0, r4
	  lwz       r5, 0x0(r3)
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  bl        -0xCE78
	  mr        r3, r31
	  bl        -0x544C
	  lfs       f0, -0x73A8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xE4
	  lis       r3, 0x802B
	  lfs       f2, -0x73A4(r2)
	  subi      r0, r3, 0x3064
	  lfs       f1, -0x73E8(r2)
	  stw       r0, 0x1C0(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3168
	  lfs       f0, -0x73A0(r2)
	  stw       r31, 0x1C4(r1)
	  mr        r3, r31
	  stw       r0, 0x1C0(r1)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x1C0
	  stfs      f2, 0x1C8(r1)
	  li        r6, 0
	  stfs      f1, 0x1CC(r1)
	  stfs      f0, 0x1D0(r1)
	  bl        -0x7AC4

	.loc_0xE4:
	  stb       r29, 0x5B9(r31)
	  lwz       r3, 0x474(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xFC
	  lwz       r4, 0x4(r3)
	  b         .loc_0x100

	.loc_0xFC:
	  li        r4, 0

	.loc_0x100:
	  cmpwi     r4, 0x3
	  bne-      .loc_0x134
	  lwz       r3, 0x301C(r13)
	  lhz       r0, 0x200(r3)
	  rlwinm.   r0,r0,0,31,31
	  bne-      .loc_0x134
	  lfs       f0, -0x5824(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x5820(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x581C(r13)
	  stfs      f0, 0xC4(r31)
	  b         .loc_0x934

	.loc_0x134:
	  cmpwi     r4, 0
	  bne-      .loc_0x178
	  lfs       f1, -0x73E8(r2)
	  lfs       f0, 0x2D0(r31)
	  fcmpu     cr0, f1, f0
	  beq-      .loc_0x178
	  lwz       r3, 0x301C(r13)
	  lhz       r0, 0x200(r3)
	  rlwinm.   r0,r0,0,30,30
	  bne-      .loc_0x178
	  lfs       f0, -0x5818(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x5814(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x5810(r13)
	  stfs      f0, 0xC4(r31)
	  b         .loc_0x934

	.loc_0x178:
	  lwz       r3, 0x301C(r13)
	  lhz       r0, 0x200(r3)
	  rlwinm.   r0,r0,0,29,29
	  bne-      .loc_0x1A4
	  lfs       f0, -0x580C(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x5808(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x5804(r13)
	  stfs      f0, 0xC4(r31)
	  b         .loc_0x934

	.loc_0x1A4:
	  lhz       r3, 0x4A0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1E0
	  subi      r0, r3, 0x1
	  sth       r0, 0x4A0(r31)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x494(r31)
	  stw       r0, 0x498(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x49C(r31)
	  lfs       f1, 0x498(r31)
	  lfs       f0, 0x4A4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x498(r31)

	.loc_0x1E0:
	  addi      r3, r1, 0x1AC
	  addi      r4, r31, 0
	  bl        -0x690C
	  addi      r29, r1, 0x1AC
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  li        r27, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x280

	.loc_0x210:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x234
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x24C

	.loc_0x234:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x24C:
	  cmplwi    r3, 0
	  beq-      .loc_0x264
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x264
	  addi      r27, r27, 0x1

	.loc_0x264:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x280:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2A8
	  li        r0, 0x1
	  b         .loc_0x2D4

	.loc_0x2A8:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2D0
	  li        r0, 0x1
	  b         .loc_0x2D4

	.loc_0x2D0:
	  li        r0, 0

	.loc_0x2D4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x210
	  sth       r27, 0x570(r31)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x1E0(r31)
	  stw       r0, 0x1E4(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x1E8(r31)
	  lfs       f0, -0x739C(r2)
	  lfs       f2, 0x1E4(r31)
	  fadds     f0, f0, f1
	  fadds     f0, f2, f0
	  stfs      f0, 0x1E4(r31)
	  lfs       f0, -0x7398(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x270(r31)
	  lfs       f1, -0x73E8(r2)
	  lfs       f0, 0x2D0(r31)
	  fcmpu     cr0, f1, f0
	  beq-      .loc_0x51C
	  lwz       r0, 0x180(r31)
	  li        r30, 0
	  cmplwi    r0, 0
	  bne-      .loc_0x354
	  li        r30, 0x1
	  b         .loc_0x480

	.loc_0x354:
	  lwz       r3, 0x478(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x480
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x480
	  addi      r3, r1, 0x18C
	  addi      r4, r31, 0
	  bl        -0x6A98
	  addi      r29, r1, 0x18C
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  li        r27, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x40C

	.loc_0x39C:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x3C0
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3D8

	.loc_0x3C0:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x3D8:
	  cmplwi    r3, 0
	  beq-      .loc_0x3F0
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x3F0
	  addi      r27, r27, 0x1

	.loc_0x3F0:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x40C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x434
	  li        r0, 0x1
	  b         .loc_0x460

	.loc_0x434:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x45C
	  li        r0, 0x1
	  b         .loc_0x460

	.loc_0x45C:
	  li        r0, 0

	.loc_0x460:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x39C
	  sth       r27, 0x570(r31)
	  lwz       r3, 0x55C(r31)
	  lwz       r0, 0x7C(r3)
	  cmpw      r27, r0
	  bge-      .loc_0x480
	  li        r30, 0x1

	.loc_0x480:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0x51C
	  li        r0, 0
	  stw       r0, 0x478(r31)
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  sth       r0, 0x570(r31)
	  li        r5, 0xB9
	  lwz       r0, 0xC8(r31)
	  oris      r0, r0, 0x40
	  stw       r0, 0xC8(r31)
	  bl        -0xD268
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xB8
	  bl        -0xD278
	  lbz       r0, 0x438(r31)
	  ori       r0, r0, 0x1
	  stb       r0, 0x438(r31)
	  lwz       r3, 0x4A8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x4EC
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x508

	.loc_0x4EC:
	  addi      r3, r1, 0xAC
	  li        r4, -0x1
	  bl        0x876BC
	  addi      r4, r3, 0
	  addi      r3, r31, 0x4AC
	  li        r5, 0
	  bl        0x2164

	.loc_0x508:
	  mr        r3, r31
	  bl        -0x4CB8
	  li        r0, 0
	  sth       r0, 0x490(r31)
	  b         .loc_0x934

	.loc_0x51C:
	  lwz       r0, 0x478(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x818
	  lwz       r0, 0x180(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x5C8
	  li        r0, 0
	  stw       r0, 0x478(r31)
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  sth       r0, 0x570(r31)
	  li        r5, 0xB9
	  lwz       r0, 0xC8(r31)
	  oris      r0, r0, 0x40
	  stw       r0, 0xC8(r31)
	  bl        -0xD314
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xB8
	  bl        -0xD324
	  lbz       r0, 0x438(r31)
	  ori       r0, r0, 0x1
	  stb       r0, 0x438(r31)
	  lwz       r3, 0x4A8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x598
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5B4

	.loc_0x598:
	  addi      r3, r1, 0xA4
	  li        r4, -0x1
	  bl        0x87610
	  addi      r4, r3, 0
	  addi      r3, r31, 0x4AC
	  li        r5, 0
	  bl        0x20B8

	.loc_0x5B4:
	  mr        r3, r31
	  bl        -0x4D64
	  li        r0, 0
	  sth       r0, 0x490(r31)
	  b         .loc_0x934

	.loc_0x5C8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x114(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x604
	  lfs       f0, 0x47C(r31)
	  stfs      f0, 0x70(r31)
	  lfs       f0, 0x484(r31)
	  stfs      f0, 0x78(r31)
	  lfs       f1, 0x74(r31)
	  lfs       f0, 0x480(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x74(r31)

	.loc_0x604:
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x2FAB8
	  lwz       r3, 0x478(r31)
	  li        r30, 0
	  li        r29, 0
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x76C
	  addi      r3, r1, 0x16C
	  addi      r4, r31, 0
	  bl        -0x6D5C
	  addi      r28, r1, 0x16C
	  addi      r3, r28, 0
	  lwz       r12, 0x0(r28)
	  li        r26, 0x1
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x6D0

	.loc_0x660:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x684
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x69C

	.loc_0x684:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x69C:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x37
	  bne-      .loc_0x6B4
	  addi      r29, r3, 0
	  li        r26, 0
	  b         .loc_0x72C

	.loc_0x6B4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x6D0:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x6F8
	  li        r0, 0x1
	  b         .loc_0x724

	.loc_0x6F8:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x720
	  li        r0, 0x1
	  b         .loc_0x724

	.loc_0x720:
	  li        r0, 0

	.loc_0x724:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x660

	.loc_0x72C:
	  rlwinm.   r0,r26,0,24,31
	  bne-      .loc_0x738
	  li        r30, 0x1

	.loc_0x738:
	  rlwinm.   r0,r26,0,24,31
	  beq-      .loc_0x76C
	  lhz       r0, 0x570(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x76C
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xB9
	  bl        -0xD514
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xB8
	  bl        -0xD524

	.loc_0x76C:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0x798
	  lfs       f3, 0x94(r31)
	  lfs       f1, 0x94(r29)
	  lfs       f2, 0x9C(r31)
	  lfs       f0, 0x9C(r29)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0x183EC4
	  fmr       f31, f1
	  b         .loc_0x7BC

	.loc_0x798:
	  lwz       r3, 0x478(r31)
	  lfsu      f3, 0x94(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x9C(r31)
	  lfs       f2, 0x8(r3)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0x183E9C
	  fmr       f31, f1

	.loc_0x7BC:
	  lfs       f1, 0x70(r31)
	  lfs       f2, 0x78(r31)
	  bl        0x183E8C
	  fmr       f2, f31
	  bl        -0x5F5C0
	  fmr       f31, f1
	  lfs       f0, -0x7394(r2)
	  fabs      f1, f31
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x854
	  mr        r3, r31
	  bl        -0x1DE8
	  lfs       f0, -0x738C(r2)
	  mr        r3, r31
	  lwz       r4, 0x2DEC(r13)
	  fdivs     f1, f0, f1
	  lfs       f0, -0x7390(r2)
	  lfs       f2, 0x28C(r4)
	  fmuls     f1, f0, f1
	  fmuls     f0, f31, f2
	  fmuls     f1, f1, f0
	  bl        -0x5A98
	  b         .loc_0x854

	.loc_0x818:
	  lwz       r0, 0x28C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x854
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7388(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x70(r31)
	  fmuls     f3, f1, f0
	  fmuls     f0, f2, f3
	  fsubs     f0, f2, f0
	  stfs      f0, 0x70(r31)
	  lfs       f1, 0x78(r31)
	  fmuls     f0, f1, f3
	  fsubs     f0, f1, f0
	  stfs      f0, 0x78(r31)

	.loc_0x854:
	  lwz       r3, 0x470(r31)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x5A34
	  lwz       r0, 0x28C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x934
	  lbz       r0, 0x438(r31)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x934
	  lfs       f1, -0x5800(r13)
	  lfs       f6, 0x70(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f5, 0x74(r31)
	  fmuls     f0, f6, f1
	  lfs       f4, 0x78(r31)
	  lfs       f3, 0x28C(r3)
	  fmuls     f2, f5, f1
	  fmuls     f1, f4, f1
	  stfs      f0, 0xD8(r1)
	  lfs       f0, 0xD8(r1)
	  stfs      f0, 0x104(r1)
	  stfs      f2, 0x108(r1)
	  stfs      f1, 0x10C(r1)
	  lfs       f0, 0x104(r1)
	  fmuls     f0, f0, f3
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0xC8(r1)
	  stfs      f0, 0x110(r1)
	  lfs       f0, 0x108(r1)
	  fmuls     f0, f0, f3
	  stfs      f0, 0x114(r1)
	  lfs       f0, 0x10C(r1)
	  fmuls     f0, f0, f3
	  stfs      f0, 0x118(r1)
	  lfs       f0, 0x110(r1)
	  fsubs     f0, f6, f0
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xBC(r1)
	  stfs      f0, 0x11C(r1)
	  lfs       f0, 0x114(r1)
	  fsubs     f0, f5, f0
	  stfs      f0, 0x120(r1)
	  lfs       f0, 0x118(r1)
	  fsubs     f0, f4, f0
	  stfs      f0, 0x124(r1)
	  lwz       r3, 0x11C(r1)
	  lwz       r0, 0x120(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x124(r1)
	  stw       r0, 0x78(r31)

	.loc_0x934:
	  lmw       r26, 0x1D8(r1)
	  lwz       r0, 0x1FC(r1)
	  lfd       f31, 0x1F0(r1)
	  addi      r1, r1, 0x1F8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80097CF4
 * Size:	00003C
 */
void StateMachine<Pellet>::exec(Pellet*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x474(r4)
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
 * Address:	80097D30
 * Size:	000004
 */
void AState<Pellet>::exec(Pellet*) { }

/*
 * --INFO--
 * Address:	80097D34
 * Size:	000050
 */
void Pellet::bounceCallback()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x38(r1)
	  lfs       f0, -0x57FC(r13)
	  addi      r4, r1, 0x24
	  stw       r0, 0x24(r1)
	  lfs       f1, -0x57F8(r13)
	  stfs      f0, 0x28(r1)
	  lfs       f0, -0x57F4(r13)
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x30(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80097D84
 * Size:	000020
 */
void Pellet::collisionCallback(CollEvent&)
{
	/*
	.loc_0x0:
	  lwz       r4, 0xC8(r3)
	  rlwinm.   r0,r4,0,9,9
	  beqlr-
	  rlwinm.   r0,r4,0,10,10
	  beqlr-
	  rlwinm    r0,r4,0,11,9
	  stw       r0, 0xC8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80097DA4
 * Size:	000074
 */
bool Pellet::stimulate(Interaction&)
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
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x58
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5C

	.loc_0x58:
	  li        r3, 0

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
 * Address:	80097E18
 * Size:	0002F8
 */
void Pellet::doRender(Graphics&, Matrix4f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x148(r1)
	  stw       r31, 0x144(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x140(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x13C(r1)
	  mr        r29, r3
	  lwz       r6, 0x45C(r3)
	  cmplwi    r6, 0
	  beq-      .loc_0x1B8
	  lwz       r3, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  lfs       f0, -0x73E8(r2)
	  stw       r3, 0xF0(r1)
	  stw       r0, 0xF4(r1)
	  lwz       r3, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r3, 0xF8(r1)
	  stw       r0, 0xFC(r1)
	  lwz       r3, 0x20(r6)
	  lwz       r0, 0x24(r6)
	  stw       r3, 0x100(r1)
	  stw       r0, 0x104(r1)
	  lwz       r3, 0x28(r6)
	  lwz       r0, 0x2C(r6)
	  stw       r3, 0x108(r1)
	  stw       r0, 0x10C(r1)
	  lwz       r3, 0x30(r6)
	  lwz       r0, 0x34(r6)
	  stw       r3, 0x110(r1)
	  stw       r0, 0x114(r1)
	  lwz       r3, 0x38(r6)
	  lwz       r0, 0x3C(r6)
	  stw       r3, 0x118(r1)
	  stw       r0, 0x11C(r1)
	  lwz       r3, 0x40(r6)
	  lwz       r0, 0x44(r6)
	  stw       r3, 0x120(r1)
	  stw       r0, 0x124(r1)
	  lwz       r3, 0x48(r6)
	  lwz       r0, 0x4C(r6)
	  stw       r3, 0x128(r1)
	  stw       r0, 0x12C(r1)
	  lfs       f2, 0xF0(r1)
	  lfs       f1, 0xF4(r1)
	  lfs       f3, 0xF8(r1)
	  fmuls     f2, f2, f2
	  fmuls     f1, f1, f1
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x134
	  fsqrte    f1, f4
	  lfd       f3, -0x73D0(r2)
	  lfd       f2, -0x73C8(r2)
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
	  stfs      f0, 0x38(r1)
	  lfs       f4, 0x38(r1)

	.loc_0x134:
	  lfs       f0, -0x73F0(r2)
	  addi      r6, r1, 0x48
	  lfs       f1, -0x57E4(r13)
	  addi      r5, r1, 0x54
	  fdivs     f4, f0, f4
	  lfs       f0, -0x57F0(r13)
	  addi      r4, r1, 0x60
	  stfs      f1, 0x48(r1)
	  addi      r3, r1, 0xB0
	  stfs      f4, 0x60(r1)
	  lfs       f3, -0x57E0(r13)
	  stfs      f0, 0x54(r1)
	  lfs       f1, -0x57EC(r13)
	  stfs      f4, 0x64(r1)
	  lfs       f2, -0x57DC(r13)
	  stfs      f3, 0x4C(r1)
	  lfs       f0, -0x57E8(r13)
	  stfs      f1, 0x58(r1)
	  stfs      f2, 0x50(r1)
	  stfs      f0, 0x5C(r1)
	  stfs      f4, 0x68(r1)
	  bl        -0x59EAC
	  lwz       r7, 0x45C(r29)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xF0
	  lwz       r6, 0x4(r7)
	  addi      r4, r1, 0xB0
	  lwz       r0, 0x8(r7)
	  stw       r6, 0x94(r29)
	  stw       r0, 0x98(r29)
	  lwz       r0, 0xC(r7)
	  stw       r0, 0x9C(r29)
	  bl        -0x59EF8

	.loc_0x1B8:
	  lwz       r3, 0x4A8(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x1EC
	  lwz       r0, 0xC8(r29)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x2DC
	  lwz       r12, 0x0(r3)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x2DC

	.loc_0x1EC:
	  lwz       r12, 0x3B4(r30)
	  lis       r4, 0x803A
	  mr        r3, r30
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  addi      r3, r29, 0x4AC
	  bl        0x1B1C
	  lwz       r4, 0x55C(r29)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x254
	  xoris     r0, r0, 0x8000
	  lfd       f1, -0x73B8(r2)
	  stw       r0, 0x134(r1)
	  lis       r0, 0x4330
	  addi      r3, r29, 0x5A8
	  stw       r0, 0x130(r1)
	  addi      r4, r1, 0xAC
	  lfd       f0, 0x130(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0xAC(r1)
	  bl        -0x68FC8
	  b         .loc_0x288

	.loc_0x254:
	  cmplwi    r4, 0
	  beq-      .loc_0x270
	  lwz       r0, 0x5C(r4)
	  subfic    r0, r0, 0x3
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,24,31
	  b         .loc_0x274

	.loc_0x270:
	  li        r0, 0

	.loc_0x274:
	  cmpwi     r0, 0
	  beq-      .loc_0x288
	  addi      r3, r29, 0x5A8
	  li        r4, 0
	  bl        -0x69000

	.loc_0x288:
	  lwz       r3, 0x554(r29)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0x62DA0
	  lwz       r3, 0x220(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x2B8
	  addi      r4, r30, 0
	  li        r5, 0
	  bl        -0xE5E0

	.loc_0x2B8:
	  lwz       r0, 0xC8(r29)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x2DC
	  lwz       r3, 0x554(r29)
	  mr        r4, r30
	  lwz       r5, 0x2E4(r30)
	  addi      r6, r29, 0x5A8
	  lwz       r3, 0x0(r3)
	  bl        -0x67C84

	.loc_0x2DC:
	  lwz       r0, 0x14C(r1)
	  lwz       r31, 0x144(r1)
	  lwz       r30, 0x140(r1)
	  lwz       r29, 0x13C(r1)
	  addi      r1, r1, 0x148
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098110
 * Size:	0001BC
 */
void Pellet::doCreateColls(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stfd      f31, 0xA0(r1)
	  stfd      f30, 0x98(r1)
	  stfd      f29, 0x90(r1)
	  stfd      f28, 0x88(r1)
	  stfd      f27, 0x80(r1)
	  stfd      f26, 0x78(r1)
	  stfd      f25, 0x70(r1)
	  stmw      r27, 0x5C(r1)
	  mr        r27, r3
	  lfs       f0, -0x73E8(r2)
	  stfs      f0, 0x2F4(r27)
	  bl        -0x23A0
	  lwz       r4, 0x4A8(r27)
	  fmr       f31, f1
	  lwz       r3, 0x55C(r27)
	  cmplwi    r4, 0
	  lfs       f30, -0x7384(r2)
	  lfs       f29, -0x73E8(r2)
	  lwz       r29, 0xCC(r3)
	  beq-      .loc_0x78
	  lwz       r12, 0x0(r4)
	  addi      r3, r1, 0x28
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x28(r1)
	  fmuls     f31, f31, f0

	.loc_0x78:
	  lfs       f27, -0x73B0(r2)
	  xoris     r30, r29, 0x8000
	  lfd       f28, -0x73B8(r2)
	  li        r28, 0
	  lis       r31, 0x4330
	  b         .loc_0x184

	.loc_0x90:
	  stw       r30, 0x54(r1)
	  xoris     r0, r28, 0x8000
	  stw       r31, 0x50(r1)
	  lfd       f0, 0x50(r1)
	  stw       r0, 0x4C(r1)
	  fsubs     f0, f0, f28
	  stw       r31, 0x48(r1)
	  fdivs     f1, f27, f0
	  lfd       f0, 0x48(r1)
	  fsubs     f0, f0, f28
	  fmuls     f25, f1, f0
	  fmr       f1, f25
	  bl        0x183B18
	  fmuls     f26, f31, f1
	  fmr       f1, f25
	  bl        0x183978
	  fmuls     f2, f31, f1
	  lfs       f0, -0x57D8(r13)
	  fmr       f1, f30
	  addi      r3, r27, 0
	  addi      r4, r1, 0x34
	  stfs      f2, 0x34(r1)
	  stfs      f0, 0x38(r1)
	  stfs      f26, 0x3C(r1)
	  bl        -0x55EC
	  fmr       f1, f25
	  bl        0x183AE0
	  fmuls     f26, f31, f1
	  fmr       f1, f25
	  bl        0x183940
	  fmuls     f1, f31, f1
	  lfs       f0, -0x57D4(r13)
	  stfs      f1, 0x34(r1)
	  stfs      f0, 0x38(r1)
	  stfs      f26, 0x3C(r1)
	  lwz       r0, 0x4A8(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x144
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  fmr       f2, f1
	  b         .loc_0x164

	.loc_0x144:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x55C(r27)
	  lfs       f0, 0xFC(r3)
	  fmuls     f2, f1, f0

	.loc_0x164:
	  lfs       f0, 0x38(r1)
	  fmr       f1, f29
	  mr        r3, r27
	  fadds     f0, f0, f2
	  addi      r4, r1, 0x34
	  stfs      f0, 0x38(r1)
	  bl        -0x5678
	  addi      r28, r28, 0x1

	.loc_0x184:
	  cmpw      r28, r29
	  blt+      .loc_0x90
	  lmw       r27, 0x5C(r1)
	  lwz       r0, 0xAC(r1)
	  lfd       f31, 0xA0(r1)
	  lfd       f30, 0x98(r1)
	  lfd       f29, 0x90(r1)
	  lfd       f28, 0x88(r1)
	  lfd       f27, 0x80(r1)
	  lfd       f26, 0x78(r1)
	  lfd       f25, 0x70(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800982CC
 * Size:	000064
 */
bool InteractSwallow::actPellet(Pellet*)
{
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r6, r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x474(r4)
	  cmplwi    r5, 0
	  beq-      .loc_0x24
	  lwz       r0, 0x4(r5)
	  b         .loc_0x28

	.loc_0x24:
	  li        r0, 0

	.loc_0x28:
	  cmpwi     r0, 0x3
	  bne-      .loc_0x38
	  li        r3, 0
	  b         .loc_0x54

	.loc_0x38:
	  lwz       r0, 0xC(r6)
	  mr        r3, r4
	  stw       r0, 0x45C(r4)
	  lwz       r4, 0x4(r6)
	  lwz       r5, 0xC(r6)
	  bl        -0x8380
	  li        r3, 0x1

	.loc_0x54:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098330
 * Size:	000148
 */
bool InteractKill::actPellet(Pellet*)
{
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  mr        r29, r4
	  lwz       r0, 0x45C(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x11C
	  addi      r3, r1, 0x24
	  addi      r4, r29, 0
	  bl        -0x76DC
	  addi      r31, r1, 0x24
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xC0

	.loc_0x54:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x78
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x90

	.loc_0x78:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x90:
	  li        r4, 0
	  bl        -0xD6E4
	  cmpwi     r30, 0
	  blt-      .loc_0xA4
	  subi      r30, r30, 0x1

	.loc_0xA4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xC0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE8
	  li        r0, 0x1
	  b         .loc_0x114

	.loc_0xE8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x110
	  li        r0, 0x1
	  b         .loc_0x114

	.loc_0x110:
	  li        r0, 0

	.loc_0x114:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x54

	.loc_0x11C:
	  addi      r3, r29, 0
	  li        r4, 0
	  bl        -0xD774
	  lwz       r0, 0x4C(r1)
	  li        r3, 0x1
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
 * Address:	80098478
 * Size:	000058
 */
void PelletMgr::decomposeNumberPellet(u32, int&, int&)
{
	/*
	.loc_0x0:
	  lis       r3, 0x802B
	  li        r0, 0x14
	  subi      r3, r3, 0xE8
	  mtctr     r0
	  addi      r7, r3, 0xD8
	  li        r8, 0

	.loc_0x18:
	  lwz       r0, 0x8(r7)
	  cmplw     r4, r0
	  bne-      .loc_0x44
	  mulli     r0, r8, 0xC
	  add       r4, r3, r0
	  lwz       r0, 0xD8(r4)
	  li        r3, 0x1
	  stw       r0, 0x0(r5)
	  lwz       r0, 0xDC(r4)
	  stw       r0, 0x0(r6)
	  blr

	.loc_0x44:
	  addi      r7, r7, 0xC
	  addi      r8, r8, 0x1
	  bdnz+     .loc_0x18
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800984D0
 * Size:	000068
 */
void PelletMgr::registerUfoParts()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  lwz       r31, 0x6C(r3)
	  b         .loc_0x4C

	.loc_0x18:
	  cmplwi    r31, 0
	  addi      r6, r31, 0
	  beq-      .loc_0x28
	  subi      r6, r6, 0x4

	.loc_0x28:
	  lwz       r0, 0x5C(r6)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x48
	  lwz       r3, 0x2F6C(r13)
	  lwz       r4, 0x130(r6)
	  lwz       r5, 0x2C(r6)
	  lwz       r6, 0x44(r6)
	  bl        -0x1784C

	.loc_0x48:
	  lwz       r31, 0xC(r31)

	.loc_0x4C:
	  cmplwi    r31, 0
	  bne+      .loc_0x18
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098538
 * Size:	000078
 */
Pellet* PelletMgr::newNumberPellet(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r6, 0x10
	  mr        r6, r0
	  stwu      r1, -0x8(r1)
	  li        r7, 0
	  b         .loc_0x40

	.loc_0x20:
	  cmpw      r4, r0
	  bne-      .loc_0x3C
	  lwz       r0, 0x4(r6)
	  cmpw      r5, r0
	  bne-      .loc_0x3C
	  lwz       r7, 0x8(r6)
	  b         .loc_0x4C

	.loc_0x3C:
	  addi      r6, r6, 0xC

	.loc_0x40:
	  lwz       r0, 0x0(r6)
	  cmpwi     r0, -0x1
	  bne+      .loc_0x20

	.loc_0x4C:
	  cmplwi    r7, 0
	  beq-      .loc_0x64
	  addi      r4, r7, 0
	  li        r5, 0
	  bl        .loc_0x78
	  b         .loc_0x68

	.loc_0x64:
	  li        r3, 0

	.loc_0x68:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x78:
	*/
}

/*
 * --INFO--
 * Address:	800985B0
 * Size:	000154
 */
Pellet* PelletMgr::newPellet(u32, PelletView*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r27, 0x34(r1)
	  addi      r27, r3, 0
	  addi      r31, r4, 0
	  addi      r28, r5, 0
	  bl        0x758
	  mr.       r30, r3
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x140

	.loc_0x30:
	  lis       r4, 0x746B
	  addi      r3, r30, 0x2C
	  addi      r4, r4, 0x2A2A
	  li        r5, 0x2A
	  bl        -0x54708
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x50
	  cmplwi    r28, 0

	.loc_0x50:
	  cmplwi    r28, 0
	  beq-      .loc_0xD4
	  cmplwi    r30, 0
	  beq-      .loc_0x13C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r29, r3
	  beq-      .loc_0xCC
	  li        r31, 0
	  sth       r31, 0x570(r29)
	  li        r0, 0x1
	  addi      r4, r28, 0
	  stb       r0, 0x452(r29)
	  addi      r3, r1, 0x14
	  stw       r28, 0x4A8(r29)
	  stw       r30, 0x55C(r29)
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x14(r1)
	  stfs      f0, 0x7C(r29)
	  lfs       f0, 0x18(r1)
	  stfs      f0, 0x80(r29)
	  lfs       f0, 0x1C(r1)
	  stfs      f0, 0x84(r29)
	  stw       r31, 0x554(r29)
	  stw       r31, 0x220(r29)

	.loc_0xCC:
	  mr        r3, r29
	  b         .loc_0x140

	.loc_0xD4:
	  addi      r3, r27, 0
	  addi      r4, r31, 0
	  bl        .loc_0x154
	  addi      r29, r3, 0
	  addi      r4, r31, 0
	  addi      r3, r1, 0x20
	  bl        -0x54808
	  addi      r3, r1, 0x20
	  bl        -0x5454C
	  cmplwi    r30, 0
	  beq-      .loc_0x13C
	  cmplwi    r29, 0
	  beq-      .loc_0x13C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  beq-      .loc_0x134
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  bl        -0x1E18

	.loc_0x134:
	  mr        r3, r31
	  b         .loc_0x140

	.loc_0x13C:
	  li        r3, 0

	.loc_0x140:
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr

	.loc_0x154:
	*/
}

/*
 * --INFO--
 * Address:	80098704
 * Size:	000094
 */
PelletShapeObject* PelletMgr::getShapeObject(u32)
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
	  bl        0x604
	  cmplwi    r3, 0
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x7C

	.loc_0x30:
	  lwz       r6, 0x1A8(r30)
	  b         .loc_0x64

	.loc_0x38:
	  cmplwi    r6, 0
	  addi      r5, r6, 0
	  beq-      .loc_0x48
	  subi      r5, r5, 0x4

	.loc_0x48:
	  lwz       r4, 0x18(r5)
	  lwz       r0, 0x44(r3)
	  cmplw     r4, r0
	  bne-      .loc_0x60
	  lwz       r3, 0x5C(r5)
	  b         .loc_0x7C

	.loc_0x60:
	  lwz       r6, 0xC(r6)

	.loc_0x64:
	  cmplwi    r6, 0
	  bne+      .loc_0x38
	  addi      r3, r1, 0x10
	  addi      r4, r31, 0
	  bl        -0x548E4
	  li        r3, 0

	.loc_0x7C:
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
 * Address:	80098798
 * Size:	000054
 */
Pellet* PelletMgr::createObject()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  li        r3, 0x5BC
	  bl        -0x517B0
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x30
	  bl        -0x3688

	.loc_0x30:
	  lwz       r0, 0x1F4(r30)
	  mr        r3, r31
	  stw       r0, 0x224(r31)
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
 * Address:	800987EC
 * Size:	000254
 */
PelletMgr::PelletMgr(MapMgr*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  bl        0x48844
	  lis       r3, 0x802B
	  lwz       r31, 0x8(r1)
	  addi      r3, r3, 0x188
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  lis       r3, 0x8022
	  stw       r0, 0x8(r31)
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x3C(r31)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x802B
	  stw       r0, 0x3C(r31)
	  li        r30, 0
	  subi      r4, r3, 0x5C
	  stw       r30, 0x4C(r31)
	  addi      r3, r31, 0x3C
	  stw       r30, 0x48(r31)
	  stw       r30, 0x44(r31)
	  bl        -0x73984
	  lis       r3, 0x802B
	  addi      r0, r3, 0x278
	  stw       r0, 0x3C(r31)
	  subi      r0, r13, 0x57D0
	  addi      r3, r31, 0x58
	  stw       r30, 0x4C(r31)
	  stw       r30, 0x48(r31)
	  stw       r30, 0x44(r31)
	  stw       r0, 0x40(r31)
	  bl        -0x3D10
	  addi      r3, r31, 0x194
	  bl        0xCC0
	  bl        0x1304
	  stw       r3, 0x1F8(r31)
	  subi      r0, r13, 0x57C8
	  li        r3, 0x58
	  stw       r30, 0x1A8(r31)
	  stw       r30, 0x1A4(r31)
	  stw       r30, 0x1A0(r31)
	  stw       r0, 0x19C(r31)
	  stw       r30, 0x190(r31)
	  bl        -0x518AC
	  mr.       r31, r3
	  beq-      .loc_0x1F8
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C8
	  stw       r0, 0x54(r31)
	  addi      r3, r1, 0x28
	  subi      r4, r13, 0x57C4
	  stw       r30, 0x0(r31)
	  bl        -0x47DFC
	  lwz       r0, 0x28(r1)
	  addi      r5, r1, 0x24
	  lfs       f1, -0x7398(r2)
	  mr        r4, r31
	  stw       r0, 0x24(r1)
	  lfs       f2, -0x73E8(r2)
	  addi      r3, r31, 0x4
	  lfs       f3, -0x73F0(r2)
	  li        r6, 0
	  bl        .loc_0x254
	  addi      r3, r1, 0x30
	  subi      r4, r13, 0x57C0
	  bl        -0x47E30
	  lwz       r0, 0x30(r1)
	  addi      r5, r1, 0x2C
	  lfs       f1, -0x7398(r2)
	  mr        r4, r31
	  stw       r0, 0x2C(r1)
	  lfs       f2, -0x73E8(r2)
	  addi      r3, r31, 0x14
	  lfs       f3, -0x73F0(r2)
	  li        r6, 0
	  bl        .loc_0x254
	  addi      r3, r1, 0x38
	  subi      r4, r13, 0x57BC
	  bl        -0x47E64
	  lwz       r0, 0x38(r1)
	  addi      r5, r1, 0x34
	  lfs       f1, -0x7380(r2)
	  mr        r4, r31
	  stw       r0, 0x34(r1)
	  lfs       f2, -0x73E8(r2)
	  addi      r3, r31, 0x24
	  lfs       f3, -0x73F0(r2)
	  li        r6, 0
	  bl        .loc_0x254
	  addi      r3, r1, 0x40
	  subi      r4, r13, 0x57B8
	  bl        -0x47E98
	  lwz       r0, 0x40(r1)
	  addi      r5, r1, 0x3C
	  lfs       f1, -0x737C(r2)
	  mr        r4, r31
	  stw       r0, 0x3C(r1)
	  lfs       f2, -0x7378(r2)
	  addi      r3, r31, 0x34
	  lfs       f3, -0x73E4(r2)
	  li        r6, 0
	  bl        .loc_0x254
	  addi      r3, r1, 0x48
	  subi      r4, r13, 0x57B4
	  bl        -0x47ECC
	  lwz       r0, 0x48(r1)
	  addi      r5, r1, 0x44
	  lfs       f1, -0x7374(r2)
	  mr        r4, r31
	  stw       r0, 0x44(r1)
	  lfs       f2, -0x7378(r2)
	  addi      r3, r31, 0x44
	  lfs       f3, -0x73E4(r2)
	  li        r6, 0
	  bl        .loc_0x254
	  lis       r3, 0x802B
	  addi      r0, r3, 0x238
	  stw       r0, 0x54(r31)
	  lfs       f0, -0x737C(r2)
	  stfs      f0, 0x10(r31)

	.loc_0x1F8:
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x802B
	  addi      r5, r3, 0x8C
	  stw       r31, 0x1F4(r30)
	  li        r0, 0
	  addi      r3, r30, 0x8
	  stw       r0, 0x54(r30)
	  subi      r4, r13, 0x57B0
	  li        r6, 0x1
	  stw       r0, 0x1FC(r30)
	  bl        -0x5836C
	  addi      r3, r30, 0
	  li        r4, 0x60
	  bl        0x486D8
	  li        r0, 0x7
	  sth       r0, 0x200(r30)
	  mr        r3, r30
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr

	.loc_0x254:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void PelletMgr::useShape(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80098B04
 * Size:	0000F0
 */
void PelletMgr::addUseList(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  lwz       r3, 0x4C(r3)
	  b         .loc_0x44

	.loc_0x2C:
	  lwz       r0, 0x14(r3)
	  cmplw     r0, r31
	  bne-      .loc_0x40
	  li        r0, 0x1
	  b         .loc_0x50

	.loc_0x40:
	  lwz       r3, 0xC(r3)

	.loc_0x44:
	  cmplwi    r3, 0
	  bne+      .loc_0x2C
	  li        r0, 0

	.loc_0x50:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0xD0
	  li        r3, 0x18
	  bl        -0x51B5C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0xC0
	  lis       r4, 0x8022
	  addi      r0, r4, 0x738C
	  lis       r4, 0x8022
	  stw       r0, 0x0(r28)
	  addi      r0, r4, 0x737C
	  stw       r0, 0x0(r28)
	  li        r29, 0
	  lis       r4, 0x802B
	  stw       r29, 0x10(r28)
	  subi      r4, r4, 0x5C
	  stw       r29, 0xC(r28)
	  stw       r29, 0x8(r28)
	  bl        -0x73CCC
	  lis       r3, 0x802B
	  addi      r0, r3, 0x278
	  stw       r0, 0x0(r28)
	  subi      r0, r13, 0x57D0
	  stw       r29, 0x10(r28)
	  stw       r29, 0xC(r28)
	  stw       r29, 0x8(r28)
	  stw       r0, 0x4(r28)

	.loc_0xC0:
	  stw       r31, 0x14(r28)
	  mr        r4, r28
	  addi      r3, r30, 0x3C
	  bl        -0x585F8

	.loc_0xD0:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098BF4
 * Size:	000054
 */
void PelletMgr::initShapeInfos()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802B
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  addi      r4, r4, 0x98
	  stwu      r1, -0x18(r1)
	  li        r6, 0x1
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x1FC(r3)
	  lis       r3, 0x802B
	  addi      r5, r3, 0xA4
	  addi      r3, r31, 0x8
	  bl        -0x58588
	  mr        r3, r31
	  bl        0x3BC
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098C48
 * Size:	000040
 */
void PelletMgr::getConfigIndex(u32)
{
	/*
	.loc_0x0:
	  lwz       r6, 0x6C(r3)
	  li        r3, 0
	  b         .loc_0x30

	.loc_0xC:
	  cmplwi    r6, 0
	  addi      r5, r6, 0
	  beq-      .loc_0x1C
	  subi      r5, r5, 0x4

	.loc_0x1C:
	  lwz       r0, 0x2C(r5)
	  cmplw     r0, r4
	  beqlr-
	  lwz       r6, 0xC(r6)
	  addi      r3, r3, 0x1

	.loc_0x30:
	  cmplwi    r6, 0
	  bne+      .loc_0xC
	  li        r3, -0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098C88
 * Size:	00009C
 */
PelletConfig* PelletMgr::getConfigFromIdx(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  blt-      .loc_0x14
	  lwz       r0, 0x54(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x1C

	.loc_0x14:
	  li        r3, 0
	  blr

	.loc_0x1C:
	  cmpwi     r4, 0
	  lwz       r3, 0x6C(r3)
	  li        r6, 0
	  ble-      .loc_0x8C
	  cmpwi     r4, 0x8
	  subi      r5, r4, 0x8
	  ble-      .loc_0x74
	  addi      r0, r5, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r5, 0
	  mtctr     r0
	  ble-      .loc_0x74

	.loc_0x4C:
	  lwz       r3, 0xC(r3)
	  addi      r6, r6, 0x8
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  bdnz+     .loc_0x4C

	.loc_0x74:
	  sub       r0, r4, r6
	  cmpw      r6, r4
	  mtctr     r0
	  bge-      .loc_0x8C

	.loc_0x84:
	  lwz       r3, 0xC(r3)
	  bdnz+     .loc_0x84

	.loc_0x8C:
	  cmplwi    r3, 0
	  beqlr-
	  subi      r3, r3, 0x4
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void PelletMgr::getConfigIdAt(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80098D24
 * Size:	000038
 */
PelletConfig* PelletMgr::getConfig(u32)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x6C(r3)
	  b         .loc_0x28

	.loc_0x8:
	  cmplwi    r5, 0
	  addi      r3, r5, 0
	  beq-      .loc_0x18
	  subi      r3, r3, 0x4

	.loc_0x18:
	  lwz       r0, 0x2C(r3)
	  cmplw     r0, r4
	  beqlr-
	  lwz       r5, 0xC(r5)

	.loc_0x28:
	  cmplwi    r5, 0
	  bne+      .loc_0x8
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098D5C
 * Size:	000044
 */
void PelletMgr::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x1FC(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x30
	  bge-      .loc_0x34
	  cmpwi     r0, 0
	  bge-      .loc_0x28
	  b         .loc_0x34

	.loc_0x28:
	  bl        .loc_0x44
	  b         .loc_0x34

	.loc_0x30:
	  bl        0xD0

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x44:
	*/
}

/*
 * --INFO--
 * Address:	80098DA0
 * Size:	0000BC
 */
void PelletMgr::readConfigs(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x54(r28)
	  li        r30, 0
	  b         .loc_0x90

	.loc_0x44:
	  li        r3, 0x138
	  bl        -0x51DE4
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x5C
	  bl        -0x4288

	.loc_0x5C:
	  lwz       r12, 0x134(r31)
	  mr        r3, r31
	  mr        r4, r29
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r31, 0
	  beq-      .loc_0x80
	  addi      r31, r31, 0x4

	.loc_0x80:
	  addi      r3, r28, 0x5C
	  addi      r4, r31, 0
	  bl        -0x58850
	  addi      r30, r30, 0x1

	.loc_0x90:
	  lwz       r0, 0x54(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x44
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098E5C
 * Size:	0000BC
 */
void PelletMgr::readAnimInfos(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x190(r28)
	  li        r30, 0
	  b         .loc_0x90

	.loc_0x44:
	  li        r3, 0x60
	  bl        -0x51EA0
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x5C
	  bl        0x694

	.loc_0x5C:
	  lwz       r12, 0x58(r31)
	  mr        r3, r31
	  mr        r4, r29
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r31, 0
	  beq-      .loc_0x80
	  addi      r31, r31, 0x4

	.loc_0x80:
	  addi      r3, r28, 0x198
	  addi      r4, r31, 0
	  bl        -0x5890C
	  addi      r30, r30, 0x1

	.loc_0x90:
	  lwz       r0, 0x190(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x44
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098F18
 * Size:	0000D4
 */
void PelletMgr::initTekiNakaParts()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  lis       r31, 0x756E
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r30, 0x1A8(r3)
	  b         .loc_0xAC

	.loc_0x2C:
	  cmplwi    r30, 0
	  addi      r3, r30, 0
	  beq-      .loc_0x3C
	  subi      r3, r3, 0x4

	.loc_0x3C:
	  lwz       r4, 0x18(r3)
	  mr        r29, r3
	  lwz       r3, 0x4C(r28)
	  b         .loc_0x64

	.loc_0x4C:
	  lwz       r0, 0x14(r3)
	  cmplw     r0, r4
	  bne-      .loc_0x60
	  li        r0, 0x1
	  b         .loc_0x70

	.loc_0x60:
	  lwz       r3, 0xC(r3)

	.loc_0x64:
	  cmplwi    r3, 0
	  bne+      .loc_0x4C
	  li        r0, 0

	.loc_0x70:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xA8
	  lwz       r0, 0x5C(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0xA8
	  addi      r3, r29, 0x18
	  addi      r4, r31, 0x2A2A
	  li        r5, 0x2A
	  bl        -0x550C0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA8
	  mr        r3, r29
	  bl        0x710
	  cmplwi    r3, 0

	.loc_0xA8:
	  lwz       r30, 0xC(r30)

	.loc_0xAC:
	  cmplwi    r30, 0
	  bne+      .loc_0x2C
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80098FEC
 * Size:	0000DC
 */
void PelletMgr::createShapeObjects()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r31, 0x1A8(r3)
	  b         .loc_0xBC

	.loc_0x20:
	  cmplwi    r31, 0
	  addi      r3, r31, 0
	  beq-      .loc_0x30
	  subi      r3, r3, 0x4

	.loc_0x30:
	  lwz       r0, 0x24(r3)
	  li        r4, 0
	  cmpwi     r0, 0x2
	  beq-      .loc_0x98
	  bge-      .loc_0xA8
	  cmpwi     r0, 0
	  beq-      .loc_0x58
	  bge-      .loc_0x60
	  b         .loc_0xA8
	  b         .loc_0xA8

	.loc_0x58:
	  li        r4, 0x1
	  b         .loc_0xA8

	.loc_0x60:
	  lwz       r5, 0x18(r3)
	  lwz       r4, 0x4C(r30)
	  b         .loc_0x84

	.loc_0x6C:
	  lwz       r0, 0x14(r4)
	  cmplw     r0, r5
	  bne-      .loc_0x80
	  li        r0, 0x1
	  b         .loc_0x90

	.loc_0x80:
	  lwz       r4, 0xC(r4)

	.loc_0x84:
	  cmplwi    r4, 0
	  bne+      .loc_0x6C
	  li        r0, 0

	.loc_0x90:
	  mr        r4, r0
	  b         .loc_0xA8

	.loc_0x98:
	  lwz       r4, 0x28(r3)
	  lwz       r5, 0x3160(r13)
	  addi      r0, r4, 0x164
	  lbzx      r4, r5, r0

	.loc_0xA8:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0xB8
	  bl        0x62C
	  cmplwi    r3, 0

	.loc_0xB8:
	  lwz       r31, 0xC(r31)

	.loc_0xBC:
	  cmplwi    r31, 0
	  bne+      .loc_0x20
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
 * Address:	800990C8
 * Size:	000210
 */
void PelletMgr::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r27, 0x4C(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  bl        0x48218
	  addi      r30, r27, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  addi      r31, r1, 0x18
	  b         .loc_0x1A0

	.loc_0x40:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x64
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x7C

	.loc_0x64:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x7C:
	  lbz       r0, 0x2FA8(r13)
	  addi      r27, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x184
	  li        r6, 0
	  stb       r6, 0x18(r1)
	  li        r0, 0xFF
	  addi      r3, r28, 0
	  stb       r0, 0x19(r1)
	  addi      r4, r31, 0
	  li        r5, 0x1
	  stb       r6, 0x1A(r1)
	  stb       r0, 0x1B(r1)
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  bl        -0x7204
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE4
	  addi      r3, r1, 0x28
	  crclr     6, 0x6
	  subi      r4, r13, 0x57A8
	  bl        0x17D3F4
	  b         .loc_0xF4

	.loc_0xE4:
	  addi      r3, r1, 0x28
	  crclr     6, 0x6
	  subi      r4, r13, 0x57A0
	  bl        0x17D3E0

	.loc_0xF4:
	  lfs       f0, 0x94(r27)
	  mr        r3, r27
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x98(r27)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x9C(r27)
	  stfs      f0, 0x24(r1)
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x20(r1)
	  addi      r3, r1, 0x1C
	  fadds     f0, f0, f1
	  stfs      f0, 0x20(r1)
	  lwz       r4, 0x2E4(r28)
	  addi      r4, r4, 0x1E0
	  bl        -0x61AB4
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x28
	  lwz       r3, 0x10(r3)
	  bl        -0x710DC
	  lwz       r12, 0x3B4(r28)
	  srawi     r0, r3, 0x1
	  lwz       r4, 0x2DEC(r13)
	  addze     r0, r0
	  lwz       r12, 0xF0(r12)
	  lwz       r4, 0x10(r4)
	  addi      r3, r28, 0
	  mtlr      r12
	  neg       r6, r0
	  addi      r5, r1, 0x1C
	  crclr     6, 0x6
	  addi      r8, r1, 0x28
	  li        r7, 0
	  blrl

	.loc_0x184:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x1A0:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C8
	  li        r0, 0x1
	  b         .loc_0x1F4

	.loc_0x1C8:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1F0
	  li        r0, 0x1
	  b         .loc_0x1F4

	.loc_0x1F0:
	  li        r0, 0

	.loc_0x1F4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x40
	  lmw       r27, 0x4C(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800992D8
 * Size:	000004
 */
void PelletMgr::refresh2d(Graphics&) { }

/*
 * --INFO--
 * Address:	800992DC
 * Size:	000084
 */
PelletMgr::~PelletMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr.       r31, r3
	  beq-      .loc_0x6C
	  lis       r3, 0x802B
	  addi      r3, r3, 0x188
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x5038
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
	  bl        -0x52198

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
 * Address:	80099360
 * Size:	000008
 */
int MonoObjectMgr::getSize() { return mSize; }

/*
 * --INFO--
 * Address:	80099368
 * Size:	000008
 */
int MonoObjectMgr::getMax() { return mMaxElements; }

/*
 * --INFO--
 * Address:	80099370
 * Size:	000008
 */
bool KEffect::invoke(zen::particleGenerator*) { return false; }

/*
 * --INFO--
 * Address:	80099378
 * Size:	000004
 */
void KEffect::kill() { }

/*
 * --INFO--
 * Address:	8009937C
 * Size:	000004
 */
void KEffect::stop() { }

/*
 * --INFO--
 * Address:	80099380
 * Size:	000004
 */
void KEffect::restart() { }

/*
 * --INFO--
 * Address:	80099384
 * Size:	000008
 */
bool KEffect::invoke(zen::particleGenerator*, zen::particleMdl*) { return false; }

/*
 * --INFO--
 * Address:	8009938C
 * Size:	000008
 */
bool KEffect::invoke(zen::particleMdl*) { return false; }

/*
 * --INFO--
 * Address:	80099394
 * Size:	000004
 */
void StateMachine<Pellet>::init(Pellet*) { }

/*
 * --INFO--
 * Address:	80099398
 * Size:	00003C
 */
void StateMachine<Pellet>::procMsg(Pellet*, Msg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x474(r4)
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
 * Address:	800993D4
 * Size:	000118
 */
void Receiver<Pellet>::procMsg(Pellet*, Msg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x0(r5)
	  cmplwi    r0, 0xA
	  bgt-      .loc_0x108
	  lis       r6, 0x802B
	  addi      r6, r6, 0x71C
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
 * Address:	800994EC
 * Size:	000004
 */
void Receiver<Pellet>::procGroundMsg(Pellet*, MsgGround*) { }

/*
 * --INFO--
 * Address:	800994F0
 * Size:	000004
 */
void Receiver<Pellet>::procUserMsg(Pellet*, MsgUser*) { }

/*
 * --INFO--
 * Address:	800994F4
 * Size:	000004
 */
void Receiver<Pellet>::procOffWallMsg(Pellet*, MsgOffWall*) { }

/*
 * --INFO--
 * Address:	800994F8
 * Size:	000004
 */
void Receiver<Pellet>::procWallMsg(Pellet*, MsgWall*) { }

/*
 * --INFO--
 * Address:	800994FC
 * Size:	000004
 */
void Receiver<Pellet>::procDamageMsg(Pellet*, MsgDamage*) { }

/*
 * --INFO--
 * Address:	80099500
 * Size:	000004
 */
void Receiver<Pellet>::procAnimMsg(Pellet*, MsgAnim*) { }

/*
 * --INFO--
 * Address:	80099504
 * Size:	000004
 */
void Receiver<Pellet>::procCollideMsg(Pellet*, MsgCollide*) { }

/*
 * --INFO--
 * Address:	80099508
 * Size:	000004
 */
void Receiver<Pellet>::procTargetMsg(Pellet*, MsgTarget*) { }

/*
 * --INFO--
 * Address:	8009950C
 * Size:	000004
 */
void Receiver<Pellet>::procHangMsg(Pellet*, MsgHang*) { }

/*
 * --INFO--
 * Address:	80099510
 * Size:	000004
 */
void Receiver<Pellet>::procStickMsg(Pellet*, MsgStick*) { }

/*
 * --INFO--
 * Address:	80099514
 * Size:	000004
 */
void Receiver<Pellet>::procBounceMsg(Pellet*, MsgBounce*) { }
