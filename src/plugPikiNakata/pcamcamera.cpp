#include "Pcam/Camera.h"
#include "Creature.h"
#include "ParaParameters.h"
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
 * Address:	80121BB8
 * Size:	000004
 */
PcamMotionInfo::PcamMotionInfo()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void PcamMotionInfo::init(f32, f32, f32, f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PcamMotionInfo::println()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80121BBC
 * Size:	000024
 */
PcamControlInfo::PcamControlInfo()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  stb       r0, 0x1(r3)
	  stb       r0, 0x2(r3)
	  stb       r0, 0x3(r3)
	  stb       r0, 0x4(r3)
	  stb       r0, 0x5(r3)
	  stb       r0, 0x6(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80121BE0
 * Size:	00002C
 */
void PcamControlInfo::init(bool, bool, bool, bool, bool, bool, bool, f32, f32, f32)
{
	/*
	.loc_0x0:
	  stb       r4, 0x0(r3)
	  stb       r5, 0x1(r3)
	  stb       r6, 0x2(r3)
	  stb       r7, 0x3(r3)
	  stb       r8, 0x4(r3)
	  stb       r9, 0x5(r3)
	  stb       r10, 0x6(r3)
	  stfs      f1, 0x8(r3)
	  stfs      f2, 0xC(r3)
	  stfs      f3, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80121C0C
 * Size:	000134
 */
PcamCamera::PcamCamera(Camera* camera)
    : NCamera(camera)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  bl        -0x42CC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x51E8
	  stw       r0, 0x50(r31)
	  addi      r3, r31, 0xC0
	  bl        -0x5898
	  lis       r3, 0x8012
	  addi      r4, r3, 0x1BB8
	  addi      r3, r31, 0xE0
	  li        r5, 0
	  li        r6, 0x18
	  li        r7, 0x6
	  bl        0xF2E18
	  li        r3, 0x28
	  bl        -0xDAC5C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x68
	  bl        0x2D54

	.loc_0x68:
	  stw       r30, 0xD0(r31)
	  lis       r3, 0x802C
	  addi      r5, r3, 0x5194
	  lwz       r3, 0xD0(r31)
	  subi      r4, r13, 0x1AF0
	  li        r6, 0x1
	  bl        -0xE15EC
	  li        r3, 0x10
	  bl        -0xDAC90
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0xEC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x5208
	  stw       r0, 0x0(r29)
	  li        r0, 0x4
	  li        r30, 0
	  stw       r0, 0x4(r29)
	  stw       r30, 0x8(r29)
	  lwz       r0, 0x4(r29)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xDACC4
	  stw       r3, 0xC(r29)
	  addi      r4, r30, 0
	  addi      r5, r30, 0
	  b         .loc_0xE0

	.loc_0xD0:
	  lwz       r3, 0xC(r29)
	  addi      r4, r4, 0x1
	  stwx      r30, r3, r5
	  addi      r5, r5, 0x4

	.loc_0xE0:
	  lwz       r0, 0x4(r29)
	  cmpw      r4, r0
	  blt+      .loc_0xD0

	.loc_0xEC:
	  stw       r29, 0x84(r31)
	  mr        r3, r31
	  lfs       f0, -0x5F40(r2)
	  stfs      f0, 0xB4(r31)
	  lfs       f0, -0x5F3C(r2)
	  lfs       f1, -0x1CA8(r13)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xB8(r31)
	  lfs       f0, -0x5F38(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xBC(r31)
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
 * Address:	80121D40
 * Size:	000028
 */
void PcamCamera::startCamera(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r6, 0
	  stwu      r1, -0x8(r1)
	  bl        .loc_0x28
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x28:
	*/
}

/*
 * --INFO--
 * Address:	80121D68
 * Size:	00018C
 */
void PcamCamera::startCamera(Creature*, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x40(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x3C(r1)
	  addi      r29, r6, 0
	  stw       r28, 0x38(r1)
	  addi      r28, r5, 0
	  stw       r31, 0xCC(r3)
	  bl        0x270
	  stw       r28, 0x88(r30)
	  addi      r3, r30, 0
	  addi      r4, r30, 0x6C
	  stw       r29, 0x90(r30)
	  lwz       r5, 0x90(r30)
	  lwz       r0, 0x88(r30)
	  mulli     r5, r5, 0x48
	  mulli     r0, r0, 0x18
	  add       r5, r5, r0
	  addi      r0, r5, 0xE0
	  add       r6, r30, r0
	  lwz       r5, 0x0(r6)
	  lwz       r0, 0x4(r6)
	  stw       r5, 0x6C(r30)
	  stw       r0, 0x70(r30)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x74(r30)
	  stw       r0, 0x78(r30)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x7C(r30)
	  stw       r0, 0x80(r30)
	  bl        0x1200
	  mr        r3, r30
	  bl        0x1424
	  lwz       r4, 0x4(r30)
	  mr        r3, r30
	  stfs      f1, 0x1CC(r4)
	  lfs       f0, -0x5F34(r2)
	  lwz       r4, 0x4(r30)
	  stfs      f0, 0x1C4(r4)
	  bl        0x1484
	  lwz       r5, 0x4(r30)
	  lis       r3, 0x803A
	  li        r4, 0x1
	  stfs      f1, 0x344(r5)
	  li        r0, 0
	  subi      r3, r3, 0x24E0
	  lfs       f0, -0x5F34(r2)
	  stfs      f0, 0xA4(r30)
	  stb       r4, 0x20(r30)
	  stb       r4, 0x28(r30)
	  stb       r4, 0x30(r30)
	  stw       r0, 0x8C(r30)
	  stw       r0, 0x94(r30)
	  stw       r0, 0x98(r30)
	  stw       r0, 0x9C(r30)
	  lfs       f0, -0x5F30(r2)
	  stfs      f0, 0xD4(r30)
	  stfs      f0, 0xD8(r30)
	  stfs      f0, 0xDC(r30)
	  lwz       r0, 0x230(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x158
	  lwz       r3, 0x3120(r13)
	  li        r4, 0
	  bl        -0xAA48
	  mr        r4, r3
	  lwz       r3, 0x84(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3120(r13)
	  li        r4, 0x1
	  bl        -0xAA6C
	  mr        r4, r3
	  lwz       r3, 0x84(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl

	.loc_0x158:
	  lfs       f1, 0xA0(r31)
	  mr        r3, r30
	  lfs       f0, -0x1CA4(r13)
	  fadds     f1, f1, f0
	  bl        0x5C
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
 * Address:	80121EF4
 * Size:	000038
 */
void NArray<Creature>::add(Creature*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  cmpw      r5, r0
	  bgelr-
	  addi      r0, r5, 0x1
	  stw       r0, 0x8(r3)
	  b         .loc_0x20
	  blr

	.loc_0x20:
	  lwz       r0, 0x8(r3)
	  lwz       r3, 0xC(r3)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  stw       r4, -0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80121F2C
 * Size:	0000DC
 */
void PcamCamera::makeCurrentPosition(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  fmr       f3, f1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  addi      r3, r31, 0xC0
	  lfs       f2, -0x5F2C(r2)
	  lfs       f1, 0x70(r31)
	  lfs       f0, -0x1CA8(r13)
	  fsubs     f2, f2, f1
	  lfs       f1, 0x6C(r31)
	  fmuls     f2, f2, f0
	  bl        -0x5B30
	  lfs       f0, 0xC0(r31)
	  addi      r3, r1, 0x24
	  stfs      f0, 0xA8(r31)
	  bl        -0x511C
	  addi      r3, r31, 0
	  addi      r4, r1, 0x24
	  bl        0x1748
	  addi      r3, r1, 0x18
	  bl        -0x5130
	  addi      r3, r31, 0xC0
	  addi      r4, r1, 0x18
	  bl        -0x5AA8
	  lfs       f1, 0x18(r1)
	  lfs       f0, 0x24(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r1)
	  lfs       f1, 0x1C(r1)
	  lfs       f0, 0x28(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r1)
	  lfs       f1, 0x20(r1)
	  lfs       f0, 0x2C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x18(r1)
	  stfs      f0, 0x8(r31)
	  lfs       f0, 0x1C(r1)
	  stfs      f0, 0xC(r31)
	  lfs       f0, 0x20(r1)
	  stfs      f0, 0x10(r31)
	  lfs       f0, 0x24(r1)
	  stfs      f0, 0x14(r31)
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x18(r31)
	  lfs       f0, 0x2C(r1)
	  stfs      f0, 0x1C(r31)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80122008
 * Size:	0004CC
 */
void PcamCamera::parameterUpdated()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x5
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x448(r1)
	  stfd      f31, 0x440(r1)
	  stfd      f30, 0x438(r1)
	  stfd      f29, 0x430(r1)
	  stfd      f28, 0x428(r1)
	  stfd      f27, 0x420(r1)
	  stw       r31, 0x41C(r1)
	  mr        r31, r3
	  lwz       r3, 0xD0(r3)
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f31, f1
	  li        r4, 0x4
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f30, f1
	  li        r4, 0x3
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f29, f1
	  li        r4, 0x2
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f28, f1
	  li        r4, 0x1
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f27, f1
	  li        r4, 0
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  stfs      f1, 0xE0(r31)
	  li        r4, 0xB
	  stfs      f27, 0xE4(r31)
	  stfs      f28, 0xE8(r31)
	  stfs      f29, 0xEC(r31)
	  stfs      f30, 0xF0(r31)
	  stfs      f31, 0xF4(r31)
	  lwz       r3, 0xD0(r31)
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f31, f1
	  li        r4, 0xA
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f30, f1
	  li        r4, 0x9
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f29, f1
	  li        r4, 0x8
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f28, f1
	  li        r4, 0x7
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f27, f1
	  li        r4, 0x6
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  stfs      f1, 0xF8(r31)
	  li        r4, 0x11
	  stfs      f27, 0xFC(r31)
	  stfs      f28, 0x100(r31)
	  stfs      f29, 0x104(r31)
	  stfs      f30, 0x108(r31)
	  stfs      f31, 0x10C(r31)
	  lwz       r3, 0xD0(r31)
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f31, f1
	  li        r4, 0x10
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f30, f1
	  li        r4, 0xF
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f29, f1
	  li        r4, 0xE
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f28, f1
	  li        r4, 0xD
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f27, f1
	  li        r4, 0xC
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  stfs      f1, 0x110(r31)
	  li        r4, 0x17
	  stfs      f27, 0x114(r31)
	  stfs      f28, 0x118(r31)
	  stfs      f29, 0x11C(r31)
	  stfs      f30, 0x120(r31)
	  stfs      f31, 0x124(r31)
	  lwz       r3, 0xD0(r31)
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f31, f1
	  li        r4, 0x16
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f30, f1
	  li        r4, 0x15
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f29, f1
	  li        r4, 0x14
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f28, f1
	  li        r4, 0x13
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f27, f1
	  li        r4, 0x12
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  stfs      f1, 0x128(r31)
	  li        r4, 0x1D
	  stfs      f27, 0x12C(r31)
	  stfs      f28, 0x130(r31)
	  stfs      f29, 0x134(r31)
	  stfs      f30, 0x138(r31)
	  stfs      f31, 0x13C(r31)
	  lwz       r3, 0xD0(r31)
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f31, f1
	  li        r4, 0x1C
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f30, f1
	  li        r4, 0x1B
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f29, f1
	  li        r4, 0x1A
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f28, f1
	  li        r4, 0x19
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f27, f1
	  li        r4, 0x18
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  stfs      f1, 0x140(r31)
	  li        r4, 0x23
	  stfs      f27, 0x144(r31)
	  stfs      f28, 0x148(r31)
	  stfs      f29, 0x14C(r31)
	  stfs      f30, 0x150(r31)
	  stfs      f31, 0x154(r31)
	  lwz       r3, 0xD0(r31)
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f31, f1
	  li        r4, 0x22
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f30, f1
	  li        r4, 0x21
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f29, f1
	  li        r4, 0x20
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f28, f1
	  li        r4, 0x1F
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f27, f1
	  li        r4, 0x1E
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  stfs      f1, 0x158(r31)
	  li        r4, 0x29
	  stfs      f27, 0x15C(r31)
	  stfs      f28, 0x160(r31)
	  stfs      f29, 0x164(r31)
	  stfs      f30, 0x168(r31)
	  stfs      f31, 0x16C(r31)
	  lwz       r3, 0xD0(r31)
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f27, f1
	  li        r4, 0x28
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f28, f1
	  li        r4, 0x27
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f29, f1
	  li        r4, 0x26
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f30, f1
	  li        r4, 0x25
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  lwz       r3, 0xD0(r31)
	  fmr       f31, f1
	  li        r4, 0x24
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        .loc_0x4CC
	  stfs      f1, 0x38(r31)
	  stfs      f31, 0x3C(r31)
	  stfs      f30, 0x40(r31)
	  stfs      f29, 0x44(r31)
	  stfs      f28, 0x48(r31)
	  stfs      f27, 0x4C(r31)
	  lwz       r0, 0x44C(r1)
	  lfd       f31, 0x440(r1)
	  lfd       f30, 0x438(r1)
	  lfd       f29, 0x430(r1)
	  lfd       f28, 0x428(r1)
	  lfd       f27, 0x420(r1)
	  lwz       r31, 0x41C(r1)
	  addi      r1, r1, 0x448
	  mtlr      r0
	  blr

	.loc_0x4CC:
	*/
}

/*
 * --INFO--
 * Address:	801224E4
 * Size:	000154
 */
void PcamCamera::control(Controller&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  lis       r0, 0x4330
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  stfd      f30, 0x80(r1)
	  stmw      r27, 0x6C(r1)
	  mr        r30, r4
	  mr        r29, r3
	  li        r31, 0
	  lbz       r4, 0x4B(r4)
	  lwz       r3, 0xD0(r3)
	  stw       r4, 0x64(r1)
	  lwz       r3, 0x24(r3)
	  stw       r0, 0x60(r1)
	  lwz       r3, 0x4(r3)
	  lfd       f1, -0x5F20(r2)
	  lfd       f0, 0x60(r1)
	  lwz       r0, 0x28(r30)
	  fsubs     f2, f0, f1
	  lfs       f1, -0x5F28(r2)
	  lwz       r3, 0x0(r3)
	  rlwinm    r0,r0,0,15,15
	  fdivs     f1, f2, f1
	  lfs       f0, 0xC4(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  mfcr      r3
	  cmplwi    r0, 0
	  rlwinm    r27,r3,3,31,31
	  beq-      .loc_0x80
	  li        r31, 0x1

	.loc_0x80:
	  lwz       r0, 0x20(r30)
	  lfs       f30, -0x5F30(r2)
	  rlwinm.   r0,r0,0,17,17
	  beq-      .loc_0x9C
	  mr        r3, r30
	  bl        -0xE1A34
	  fmr       f30, f1

	.loc_0x9C:
	  li        r28, 0
	  stb       r28, 0x40(r1)
	  mr        r3, r30
	  stb       r28, 0x41(r1)
	  stb       r28, 0x42(r1)
	  stb       r28, 0x43(r1)
	  stb       r28, 0x44(r1)
	  stb       r28, 0x45(r1)
	  stb       r28, 0x46(r1)
	  bl        -0xE1A60
	  fmr       f31, f1
	  mr        r3, r30
	  bl        -0xE1B14
	  lwz       r3, 0x28(r30)
	  rlwinm.   r0,r3,0,13,13
	  beq-      .loc_0xEC
	  lwz       r0, 0x20(r30)
	  rlwinm.   r0,r0,0,17,17
	  bne-      .loc_0xEC
	  li        r28, 0x1

	.loc_0xEC:
	  li        r0, 0x1
	  stb       r0, 0x40(r1)
	  rlwinm    r0,r3,0,14,14
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  stb       r27, 0x41(r1)
	  subfe     r0, r0, r3
	  stb       r0, 0x42(r1)
	  li        r0, 0
	  addi      r3, r29, 0
	  stb       r28, 0x43(r1)
	  addi      r4, r1, 0x40
	  stb       r31, 0x44(r1)
	  stb       r0, 0x45(r1)
	  stb       r0, 0x46(r1)
	  stfs      f1, 0x48(r1)
	  stfs      f30, 0x4C(r1)
	  stfs      f31, 0x50(r1)
	  bl        .loc_0x154
	  lmw       r27, 0x6C(r1)
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lfd       f30, 0x80(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr

	.loc_0x154:
	*/
}

/*
 * --INFO--
 * Address:	80122638
 * Size:	00017C
 */
void PcamCamera::control(PcamControlInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  stw       r30, 0x58(r1)
	  addi      r30, r4, 0
	  lbz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x164
	  lbz       r0, 0x0(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x164
	  lbz       r0, 0x30(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x80
	  lbz       r0, 0x3(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x54
	  li        r0, 0x1
	  stw       r0, 0x8C(r31)

	.loc_0x54:
	  lbz       r0, 0x4(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x6C
	  li        r0, 0x1
	  stw       r0, 0x94(r31)
	  b         .loc_0x80

	.loc_0x6C:
	  lbz       r0, 0x5(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x80
	  li        r0, 0x2
	  stw       r0, 0x94(r31)

	.loc_0x80:
	  lbz       r0, 0x28(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xAC
	  lbz       r0, 0x2(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xAC
	  lwz       r0, 0x9C(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0xAC
	  mr        r3, r31
	  bl        .loc_0x17C

	.loc_0xAC:
	  lwz       r0, 0x9C(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x164
	  lbz       r0, 0x1(r30)
	  lwz       r3, 0x3150(r13)
	  cmplwi    r0, 0
	  lfs       f3, 0x28C(r3)
	  beq-      .loc_0x164
	  lfs       f1, 0x8(r30)
	  lfs       f0, -0x5F30(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xE0
	  b         .loc_0xE4

	.loc_0xE0:
	  fneg      f1, f1

	.loc_0xE4:
	  lfs       f0, -0x5F18(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xFC
	  lfs       f0, -0x5F30(r2)
	  stfs      f0, 0x8(r30)

	.loc_0xFC:
	  lwz       r3, 0xD0(r31)
	  lfs       f0, 0x8(r30)
	  lwz       r3, 0x24(r3)
	  lfs       f2, 0xC8(r31)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xB0(r3)
	  fneg      f1, f1
	  fmuls     f0, f1, f0
	  fmuls     f0, f3, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xC8(r31)
	  lfs       f3, 0xC8(r31)
	  lfs       f0, -0x5F30(r2)
	  lfs       f2, -0x5F3C(r2)
	  lfs       f1, -0x1CA4(r13)
	  fcmpo     cr0, f3, f0
	  fmuls     f0, f2, f1
	  bge-      .loc_0x150
	  fadds     f3, f3, f0
	  b         .loc_0x160

	.loc_0x150:
	  fcmpo     cr0, f3, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x160
	  fsubs     f3, f3, f0

	.loc_0x160:
	  stfs      f3, 0xC8(r31)

	.loc_0x164:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr

	.loc_0x17C:
	*/
}

/*
 * --INFO--
 * Address:	801227B4
 * Size:	00002C
 */
void PcamCamera::startAttention()
{
	/*
	.loc_0x0:
	  lwz       r4, 0xD0(r3)
	  li        r0, 0x1
	  lwz       r4, 0x24(r4)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f0, 0xBC(r4)
	  stfs      f0, 0xD8(r3)
	  stw       r0, 0x9C(r3)
	  lfs       f0, 0xC8(r3)
	  stfs      f0, 0xB0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void PcamCamera::playCameraSound(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801227E0
 * Size:	000110
 */
void PcamCamera::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  bl        0xB0C
	  stfs      f1, 0xAC(r31)
	  lwz       r0, 0x8C(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x7C
	  lwz       r3, 0x88(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x88(r31)
	  lwz       r0, 0x88(r31)
	  cmpwi     r0, 0x3
	  blt-      .loc_0x48
	  li        r0, 0
	  stw       r0, 0x88(r31)

	.loc_0x48:
	  lwz       r4, 0x90(r31)
	  mr        r3, r31
	  lwz       r0, 0x88(r31)
	  mulli     r4, r4, 0x48
	  mulli     r0, r0, 0x18
	  add       r4, r4, r0
	  addi      r4, r4, 0xE0
	  add       r4, r31, r4
	  bl        0x7B0
	  li        r0, 0
	  stw       r0, 0x8C(r31)
	  li        r3, 0x11C
	  bl        -0x7D4E4

	.loc_0x7C:
	  lwz       r0, 0x94(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xDC
	  lwz       r3, 0x90(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x90(r31)
	  lwz       r0, 0x90(r31)
	  cmpwi     r0, 0x2
	  blt-      .loc_0xA8
	  li        r0, 0
	  stw       r0, 0x90(r31)

	.loc_0xA8:
	  lwz       r4, 0x90(r31)
	  mr        r3, r31
	  lwz       r0, 0x88(r31)
	  mulli     r4, r4, 0x48
	  mulli     r0, r0, 0x18
	  add       r4, r4, r0
	  addi      r4, r4, 0xE0
	  add       r4, r31, r4
	  bl        0x750
	  li        r0, 0
	  stw       r0, 0x94(r31)
	  li        r3, 0x11C
	  bl        -0x7D544

	.loc_0xDC:
	  mr        r3, r31
	  bl        0x670
	  mr        r3, r31
	  bl        .loc_0x110
	  mr        r3, r31
	  bl        -0x4EF0
	  mr        r3, r31
	  bl        -0x4E28
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0x110:
	*/
}

/*
 * --INFO--
 * Address:	801228F0
 * Size:	0003A0
 */
void PcamCamera::makePosture()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x128(r1)
	  stfd      f31, 0x120(r1)
	  stmw      r27, 0x10C(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0xEC
	  bl        -0x5AB8
	  addi      r28, r3, 0
	  addi      r3, r1, 0xE0
	  bl        -0x5AC4
	  addi      r27, r3, 0
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  bl        0xD9C
	  mr        r3, r31
	  bl        0x958
	  fmr       f31, f1
	  addi      r3, r1, 0xD4
	  bl        -0x5AE8
	  lfs       f1, 0x0(r28)
	  mr        r30, r3
	  lfs       f0, 0x14(r31)
	  lfs       f3, 0x4(r28)
	  lfs       f2, 0x18(r31)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r28)
	  lfs       f1, 0x1C(r31)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x0(r3)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x4(r3)
	  stfs      f0, 0x8(r3)
	  lfs       f0, 0x0(r3)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x8(r3)
	  lfs       f1, 0x14(r31)
	  lfs       f0, 0x0(r3)
	  lfs       f3, 0x18(r31)
	  lfs       f2, 0x4(r3)
	  fadds     f0, f1, f0
	  lfs       f4, 0x1C(r31)
	  lfs       f1, 0x8(r3)
	  fadds     f2, f3, f2
	  stfs      f0, 0x0(r28)
	  fadds     f0, f4, f1
	  stfs      f2, 0x4(r28)
	  stfs      f0, 0x8(r28)
	  lwz       r0, 0x9C(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1D4
	  lfs       f1, 0xD8(r31)
	  lfs       f0, -0x5F30(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x104
	  li        r0, 0
	  stw       r0, 0x9C(r31)
	  b         .loc_0x1D4

	.loc_0x104:
	  mr        r3, r31
	  bl        0x964
	  lfs       f4, -0x1CA4(r13)
	  lfs       f2, -0x5F3C(r2)
	  fadds     f3, f4, f1
	  lfs       f0, -0x5F30(r2)
	  fmuls     f2, f2, f4
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x130
	  fadds     f3, f3, f2
	  b         .loc_0x140

	.loc_0x130:
	  fcmpo     cr0, f3, f2
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x140
	  fsubs     f3, f3, f2

	.loc_0x140:
	  lfs       f4, 0xB0(r31)
	  fcmpo     cr0, f3, f4
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x168
	  fsubs     f1, f3, f4
	  fsubs     f0, f2, f1
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x17C
	  fsubs     f3, f3, f2
	  b         .loc_0x17C

	.loc_0x168:
	  fsubs     f1, f4, f3
	  fsubs     f0, f2, f1
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x17C
	  fadds     f3, f3, f2

	.loc_0x17C:
	  lwz       r3, 0xD0(r31)
	  fsubs     f0, f3, f4
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xB8(r3)
	  lfs       f2, 0xD8(r3)
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f0, f2
	  fmr       f1, f0
	  ble-      .loc_0x1B0
	  fmr       f1, f2
	  b         .loc_0x1C0

	.loc_0x1B0:
	  fneg      f0, f2
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1C0
	  fmr       f1, f0

	.loc_0x1C0:
	  lfs       f0, 0xB0(r31)
	  fadds     f0, f0, f1
	  stfs      f0, 0xB0(r31)
	  lfs       f0, 0xB0(r31)
	  stfs      f0, 0xC8(r31)

	.loc_0x1D4:
	  mr        r3, r31
	  bl        .loc_0x3A0
	  lfs       f3, 0xC8(r31)
	  lfs       f0, -0x5F30(r2)
	  lfs       f2, -0x5F3C(r2)
	  lfs       f1, -0x1CA4(r13)
	  fcmpo     cr0, f3, f0
	  fmuls     f0, f2, f1
	  bge-      .loc_0x200
	  fadds     f3, f3, f0
	  b         .loc_0x210

	.loc_0x200:
	  fcmpo     cr0, f3, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x210
	  fsubs     f3, f3, f0

	.loc_0x210:
	  stfs      f3, 0xC8(r31)
	  mr        r3, r31
	  bl        0x6A8
	  lfs       f2, -0x5F2C(r2)
	  mr        r4, r27
	  lfs       f0, -0x1CA8(r13)
	  addi      r3, r31, 0xC0
	  fsubs     f1, f2, f1
	  fmuls     f0, f1, f0
	  stfs      f0, 0xC4(r31)
	  bl        -0x6640
	  lfs       f1, 0x0(r27)
	  addi      r29, r31, 0x8
	  lfs       f0, 0x0(r28)
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  fadds     f0, f1, f0
	  mr        r5, r27
	  stfs      f0, 0x0(r27)
	  lfs       f1, 0x4(r27)
	  lfs       f0, 0x4(r28)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r27)
	  lfs       f1, 0x8(r27)
	  lfs       f0, 0x8(r28)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r27)
	  lfs       f1, 0x0(r27)
	  lfs       f0, 0x8(r31)
	  lfs       f3, 0x4(r27)
	  lfs       f2, 0xC(r31)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r27)
	  lfs       f1, 0x10(r31)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x0(r30)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x4(r30)
	  stfs      f0, 0x8(r30)
	  lfs       f0, 0x0(r30)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0x4(r30)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x8(r30)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x8(r30)
	  lfs       f1, 0x8(r31)
	  lfs       f0, 0x0(r30)
	  lfs       f3, 0xC(r31)
	  lfs       f2, 0x4(r30)
	  fadds     f0, f1, f0
	  lfs       f4, 0x10(r31)
	  lfs       f1, 0x8(r30)
	  fadds     f2, f3, f2
	  stfs      f0, 0x0(r27)
	  fadds     f0, f4, f1
	  stfs      f2, 0x4(r27)
	  stfs      f0, 0x8(r27)
	  bl        0xE8
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0xB8
	  bl        -0x6540
	  addi      r30, r3, 0
	  addi      r4, r30, 0x4
	  addi      r3, r29, 0
	  addi      r5, r4, 0x4
	  addi      r6, r4, 0x8
	  bl        -0xC558C
	  addi      r4, r30, 0x10
	  addi      r3, r31, 0x14
	  addi      r5, r4, 0x4
	  addi      r6, r4, 0x8
	  bl        -0xC55A0
	  lwz       r4, 0x4(r31)
	  mr        r3, r31
	  lfs       f31, 0x1CC(r4)
	  bl        0x5E8
	  lwz       r5, 0xD0(r31)
	  fsubs     f1, f1, f31
	  lwz       r4, 0x4(r31)
	  mr        r3, r31
	  lwz       r5, 0x24(r5)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f0, 0xAC(r5)
	  fmuls     f0, f1, f0
	  fadds     f0, f31, f0
	  stfs      f0, 0x1CC(r4)
	  bl        0x634
	  lwz       r3, 0x4(r31)
	  stfs      f1, 0x344(r3)
	  lmw       r27, 0x10C(r1)
	  lwz       r0, 0x12C(r1)
	  lfd       f31, 0x120(r1)
	  addi      r1, r1, 0x128
	  mtlr      r0
	  blr

	.loc_0x3A0:
	*/
}

/*
 * --INFO--
 * Address:	80122C90
 * Size:	000048
 */
void PcamCamera::makePolarRadius()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0xA0(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x28
	  lfs       f1, 0xA8(r31)
	  b         .loc_0x30

	.loc_0x28:
	  mr        r3, r31
	  bl        0x488

	.loc_0x30:
	  stfs      f1, 0xC0(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80122CD8
 * Size:	000228
 */
void PcamCamera::makeWatchObjectViewpoint(NVector3f&, NVector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r6, r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x120(r1)
	  stfd      f31, 0x118(r1)
	  stfd      f30, 0x110(r1)
	  stfd      f29, 0x108(r1)
	  stfd      f28, 0x100(r1)
	  stfd      f27, 0xF8(r1)
	  stw       r31, 0xF4(r1)
	  stw       r30, 0xF0(r1)
	  stw       r29, 0xEC(r1)
	  addi      r29, r5, 0
	  stw       r28, 0xE8(r1)
	  mr        r28, r3
	  lwz       r3, 0x84(r3)
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x1F4
	  addi      r4, r29, 0
	  addi      r5, r6, 0
	  addi      r3, r1, 0xDC
	  bl        -0x5E04
	  addi      r3, r1, 0xDC
	  bl        -0x5C38
	  addi      r4, r29, 0
	  addi      r3, r1, 0xC0
	  addi      r5, r1, 0xDC
	  bl        -0x594C
	  addi      r3, r1, 0xA8
	  addi      r4, r1, 0xDC
	  bl        -0x6E08
	  addi      r3, r1, 0xA8
	  bl        -0x6D48
	  addi      r5, r29, 0
	  addi      r3, r1, 0x94
	  addi      r4, r1, 0xB4
	  bl        -0x5688
	  addi      r3, r1, 0x88
	  bl        -0x5F20
	  addi      r3, r1, 0xA8
	  addi      r4, r1, 0x88
	  bl        -0x6C98
	  addi      r5, r29, 0
	  addi      r3, r1, 0x74
	  addi      r4, r1, 0x88
	  bl        -0x56AC
	  lwz       r3, 0x4(r28)
	  lfs       f1, -0x5F10(r2)
	  lfs       f2, 0x1CC(r3)
	  lfs       f0, -0x1CA8(r13)
	  fmuls     f1, f2, f1
	  lfs       f2, -0x5F14(r2)
	  fmuls     f0, f1, f0
	  fmuls     f1, f2, f0
	  bl        0xF8D1C
	  lfs       f0, -0x5F34(r2)
	  li        r30, 0
	  lwz       r3, 0x4(r28)
	  fdivs     f30, f0, f1
	  lfs       f28, -0x5F0C(r2)
	  lfs       f0, 0x1C4(r3)
	  lfs       f31, -0x5F30(r2)
	  fdivs     f29, f30, f0
	  b         .loc_0x1C8

	.loc_0x104:
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  addi      r3, r1, 0x68
	  bl        -0x5FA4
	  lwz       r4, 0x94(r31)
	  addi      r3, r1, 0x5C
	  lwz       r0, 0x98(r31)
	  stw       r4, 0x68(r1)
	  stw       r0, 0x6C(r1)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x70(r1)
	  bl        -0x5FC4
	  addi      r3, r1, 0x94
	  addi      r4, r1, 0x68
	  addi      r5, r1, 0x5C
	  bl        -0x568C
	  stfs      f31, 0x58(r1)
	  addi      r3, r1, 0xC0
	  addi      r4, r1, 0x5C
	  addi      r5, r1, 0x58
	  bl        -0x599C
	  fmuls     f0, f1, f29
	  lfs       f1, 0x58(r1)
	  addi      r3, r1, 0x48
	  fsubs     f27, f1, f0
	  bl        -0x5FFC
	  addi      r3, r1, 0x74
	  addi      r4, r1, 0x68
	  addi      r5, r1, 0x48
	  bl        -0x56C4
	  stfs      f31, 0x44(r1)
	  addi      r3, r1, 0xC0
	  addi      r4, r1, 0x48
	  addi      r5, r1, 0x44
	  bl        -0x59D4
	  fmuls     f0, f1, f30
	  lfs       f1, 0x44(r1)
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f27, f0
	  bge-      .loc_0x1B8
	  fmr       f0, f27

	.loc_0x1B8:
	  fcmpo     cr0, f0, f28
	  bge-      .loc_0x1C4
	  fmr       f28, f0

	.loc_0x1C4:
	  addi      r30, r30, 0x1

	.loc_0x1C8:
	  lwz       r3, 0x84(r28)
	  lwz       r0, 0x8(r3)
	  cmpw      r30, r0
	  blt+      .loc_0x104
	  lfs       f0, -0x5F30(r2)
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0x1F4
	  fmr       f1, f28
	  addi      r4, r29, 0
	  addi      r3, r1, 0xC0
	  bl        -0x5904

	.loc_0x1F4:
	  lwz       r0, 0x124(r1)
	  lfd       f31, 0x118(r1)
	  lfd       f30, 0x110(r1)
	  lfd       f29, 0x108(r1)
	  lfd       f28, 0x100(r1)
	  lfd       f27, 0xF8(r1)
	  lwz       r31, 0xF4(r1)
	  lwz       r30, 0xF0(r1)
	  lwz       r29, 0xEC(r1)
	  lwz       r28, 0xE8(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80122F00
 * Size:	000030
 */
void NArray<Creature>::get(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  blt-      .loc_0x18
	  lwz       r5, 0x4(r3)
	  subi      r0, r5, 0x1
	  cmpw      r4, r0
	  ble-      .loc_0x20

	.loc_0x18:
	  li        r3, 0
	  blr

	.loc_0x20:
	  lwz       r3, 0xC(r3)
	  rlwinm    r0,r4,2,0,29
	  lwzx      r3, r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80122F30
 * Size:	000084
 */
void PcamCamera::updateTimers()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x5F30(r2)
	  lfs       f0, 0xD4(r3)
	  lwz       r4, 0x3150(r13)
	  fcmpo     cr0, f0, f1
	  lfs       f2, 0x28C(r4)
	  ble-      .loc_0x30
	  fsubs     f0, f0, f2
	  stfs      f0, 0xD4(r3)
	  lfs       f0, 0xD4(r3)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x30
	  stfs      f1, 0xD4(r3)

	.loc_0x30:
	  addi      r3, r3, 0x4
	  lfs       f0, 0xD4(r3)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x58
	  fsubs     f0, f0, f2
	  stfs      f0, 0xD4(r3)
	  lfs       f0, 0xD4(r3)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x58
	  stfs      f1, 0xD4(r3)

	.loc_0x58:
	  lfs       f0, 0xD8(r3)
	  addi      r3, r3, 0x4
	  fcmpo     cr0, f0, f1
	  blelr-
	  fsubs     f0, f0, f2
	  stfs      f0, 0xD4(r3)
	  lfs       f0, 0xD4(r3)
	  fcmpo     cr0, f0, f1
	  bgelr-
	  stfs      f1, 0xD4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80122FB4
 * Size:	000044
 */
void PcamCamera::startMotion(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  stw       r4, 0x88(r3)
	  stw       r5, 0x90(r3)
	  lwz       r4, 0x90(r3)
	  lwz       r0, 0x88(r3)
	  mulli     r4, r4, 0x48
	  mulli     r0, r0, 0x18
	  add       r4, r4, r0
	  addi      r4, r4, 0xE0
	  add       r4, r3, r4
	  bl        .loc_0x44
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x44:
	*/
}

/*
 * --INFO--
 * Address:	80122FF8
 * Size:	00007C
 */
void PcamCamera::startMotion(PcamMotionInfo&)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x6C(r3)
	  lwz       r0, 0x70(r3)
	  stw       r5, 0x54(r3)
	  stw       r0, 0x58(r3)
	  lwz       r5, 0x74(r3)
	  lwz       r0, 0x78(r3)
	  stw       r5, 0x5C(r3)
	  stw       r0, 0x60(r3)
	  lwz       r5, 0x7C(r3)
	  lwz       r0, 0x80(r3)
	  stw       r5, 0x64(r3)
	  stw       r0, 0x68(r3)
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r5, 0x6C(r3)
	  stw       r0, 0x70(r3)
	  lwz       r5, 0x8(r4)
	  lwz       r0, 0xC(r4)
	  stw       r5, 0x74(r3)
	  stw       r0, 0x78(r3)
	  lwz       r5, 0x10(r4)
	  lwz       r0, 0x14(r4)
	  stw       r5, 0x7C(r3)
	  stw       r0, 0x80(r3)
	  lwz       r4, 0xD0(r3)
	  lwz       r4, 0x24(r4)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f0, 0xC0(r4)
	  stfs      f0, 0xD4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80123074
 * Size:	0000D0
 */
void PcamCamera::finishMotion()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x30
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lfs       f0, 0x54(r3)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x58(r3)
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x5C(r3)
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x60(r3)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x64(r3)
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x68(r3)
	  stfs      f0, 0x34(r1)
	  lwz       r3, 0x6C(r3)
	  lwz       r0, 0x70(r31)
	  stw       r3, 0x54(r31)
	  stw       r0, 0x58(r31)
	  lwz       r3, 0x74(r31)
	  lwz       r0, 0x78(r31)
	  stw       r3, 0x5C(r31)
	  stw       r0, 0x60(r31)
	  lwz       r3, 0x7C(r31)
	  lwz       r0, 0x80(r31)
	  stw       r3, 0x64(r31)
	  stw       r0, 0x68(r31)
	  lwz       r3, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stw       r3, 0x6C(r31)
	  stw       r0, 0x70(r31)
	  lwz       r3, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r3, 0x74(r31)
	  stw       r0, 0x78(r31)
	  lwz       r3, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  stw       r3, 0x7C(r31)
	  stw       r0, 0x80(r31)
	  lwz       r3, 0xD0(r31)
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xC54
	  stfs      f1, 0xD4(r31)
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
f32 PcamCamera::getChangingMotionRate()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80123144
 * Size:	00006C
 */
f32 PcamCamera::getGoalDistance()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x30
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r3
	  lwz       r3, 0xD0(r3)
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xC94
	  lfs       f0, 0xD4(r31)
	  lfs       f4, -0x5F34(r2)
	  fdivs     f1, f0, f1
	  lfs       f2, 0x54(r31)
	  lfs       f0, 0x6C(r31)
	  lfs       f3, 0xA4(r31)
	  fsubs     f5, f4, f1
	  fsubs     f1, f4, f5
	  fmuls     f0, f0, f5
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  fmuls     f1, f3, f0
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801231B0
 * Size:	000060
 */
f32 PcamCamera::getCurrentAngle()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x30
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r3, 0xD0(r3)
	  lwz       r3, 0x24(r3)
	  bl        .loc_0x60
	  lfs       f0, 0xD4(r31)
	  lfs       f3, -0x5F34(r2)
	  fdivs     f1, f0, f1
	  lfs       f2, 0x58(r31)
	  lfs       f0, 0x70(r31)
	  fsubs     f4, f3, f1
	  fsubs     f1, f3, f4
	  fmuls     f0, f0, f4
	  fmuls     f1, f2, f1
	  fadds     f1, f1, f0
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0x60:
	*/
}

/*
 * --INFO--
 * Address:	80123224
 * Size:	000064
 */
f32 PcamCamera::getCurrentFov()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x30
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lwz       r3, 0xD0(r3)
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xD74
	  lfs       f0, 0xD4(r31)
	  lfs       f3, -0x5F34(r2)
	  fdivs     f1, f0, f1
	  lfs       f2, 0x5C(r31)
	  lfs       f0, 0x74(r31)
	  fsubs     f4, f3, f1
	  fsubs     f1, f3, f4
	  fmuls     f0, f0, f4
	  fmuls     f1, f2, f1
	  fadds     f1, f1, f0
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80123288
 * Size:	000018
 */
f32 PcamCamera::getCurrentHomingSpeed()
{
	/*
	.loc_0x0:
	  lwz       r3, 0xD0(r3)
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xA8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
f32 PcamCamera::getCurrentWatchAdjustment()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
f32 PcamCamera::getCurrentNaviWatchWeight()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801232A0
 * Size:	000060
 */
f32 PcamCamera::getCurrentBlur()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x30
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r3, 0xD0(r3)
	  lwz       r3, 0x24(r3)
	  bl        -0xB0
	  lfs       f0, 0xD4(r31)
	  lfs       f3, -0x5F34(r2)
	  fdivs     f1, f0, f1
	  lfs       f2, 0x68(r31)
	  lfs       f0, 0x80(r31)
	  fsubs     f4, f3, f1
	  fsubs     f1, f3, f4
	  fmuls     f0, f0, f4
	  fmuls     f1, f2, f1
	  fadds     f1, f1, f0
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80123300
 * Size:	00005C
 */
f32 PcamCamera::calcCurrentDistance()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r4, r3, 0x8
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lfs       f3, 0x8(r3)
	  lfsu      f2, 0x14(r3)
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x4(r3)
	  fsubs     f4, f3, f2
	  lfs       f2, 0x8(r4)
	  fsubs     f3, f1, f0
	  lfs       f0, 0x8(r3)
	  fmuls     f1, f4, f4
	  fsubs     f2, f2, f0
	  fmuls     f0, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x115708
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
f32 PcamCamera::calcCurrentDirection()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
f32 PcamCamera::calcTargetDistance()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
f32 PcamCamera::getTargetDirection()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8012335C
 * Size:	000094
 */
f32 PcamCamera::getCursorDirection()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0x24
	  bl        -0x6520
	  addi      r3, r31, 0
	  addi      r4, r1, 0x24
	  bl        .loc_0x94
	  addi      r3, r1, 0x18
	  bl        -0x6534
	  addi      r3, r31, 0
	  addi      r4, r1, 0x18
	  bl        0x7C
	  addi      r3, r1, 0xC
	  bl        -0x6548
	  lfs       f1, 0x18(r1)
	  lfs       f0, 0x24(r1)
	  lfs       f3, 0x1C(r1)
	  fsubs     f4, f1, f0
	  lfs       f2, 0x28(r1)
	  lfs       f1, 0x20(r1)
	  lfs       f0, 0x2C(r1)
	  fsubs     f2, f3, f2
	  stfs      f4, 0xC(r1)
	  fsubs     f0, f1, f0
	  stfs      f2, 0x10(r1)
	  stfs      f0, 0x14(r1)
	  lfs       f1, 0xC(r1)
	  lfs       f2, 0x14(r1)
	  bl        -0x55D0
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr

	.loc_0x94:
	*/
}

/*
 * --INFO--
 * Address:	801233F0
 * Size:	000020
 */
void PcamCamera::outputTargetPosition(NVector3f&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0xCC(r3)
	  lfsu      f0, 0x94(r3)
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x4(r4)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80123410
 * Size:	000048
 */
void PcamCamera::outputCursorPosition(NVector3f&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0xCC(r3)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x36
	  bne-      .loc_0x2C
	  lfs       f0, 0x6F0(r3)
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x6F4(r3)
	  stfs      f0, 0x4(r4)
	  lfs       f0, 0x6F8(r3)
	  stfs      f0, 0x8(r4)
	  blr

	.loc_0x2C:
	  lfsu      f0, 0x94(r3)
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x4(r4)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80123458
 * Size:	00026C
 */
void PcamCamera::outputFormationWatchpoint(Navi*, NVector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stmw      r26, 0xB0(r1)
	  addi      r26, r4, 0
	  addi      r29, r3, 0
	  addi      r4, r26, 0x94
	  addi      r30, r5, 0
	  addi      r3, r1, 0x9C
	  bl        -0x6600
	  lfs       f0, 0x9C(r1)
	  li        r4, 0x30
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0xA0(r1)
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0xA4(r1)
	  stfs      f0, 0x8(r30)
	  lwz       r3, 0xD0(r29)
	  lwz       r3, 0x24(r3)
	  bl        -0x298
	  lfs       f0, 0xD4(r29)
	  lfs       f4, -0x5F34(r2)
	  fdivs     f2, f0, f1
	  lfs       f3, 0x64(r29)
	  lfs       f1, 0x7C(r29)
	  lfs       f0, -0x5F30(r2)
	  fsubs     f5, f4, f2
	  fsubs     f2, f4, f5
	  fmuls     f1, f1, f5
	  fmuls     f2, f3, f2
	  fadds     f31, f2, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x254
	  lfs       f0, 0x0(r30)
	  li        r31, 0
	  fmuls     f0, f0, f31
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0x4(r30)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x8(r30)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x8(r30)
	  lwz       r0, 0x710(r26)
	  cmplwi    r0, 0
	  beq-      .loc_0x210
	  mr        r27, r0
	  addi      r3, r27, 0
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3
	  b         .loc_0x1B4

	.loc_0xDC:
	  cmpwi     r26, -0x1
	  bne-      .loc_0x100
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x118

	.loc_0x100:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x118:
	  addi      r28, r3, 0x94
	  lfs       f3, 0xA4(r1)
	  lfs       f2, 0x9C(r3)
	  lfs       f1, 0x9C(r1)
	  lfs       f0, 0x94(r3)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f1, f1, f0
	  bl        -0x115958
	  lwz       r3, 0xD0(r29)
	  lwz       r3, 0x24(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xD0(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x198
	  lfs       f1, 0x0(r30)
	  addi      r31, r31, 0x1
	  lfs       f0, 0x0(r28)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x4(r28)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x8(r30)
	  lfs       f0, 0x8(r28)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r30)

	.loc_0x198:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0x1B4:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1DC
	  li        r0, 0x1
	  b         .loc_0x208

	.loc_0x1DC:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x204
	  li        r0, 0x1
	  b         .loc_0x208

	.loc_0x204:
	  li        r0, 0

	.loc_0x208:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xDC

	.loc_0x210:
	  xoris     r0, r31, 0x8000
	  lfd       f1, -0x5F08(r2)
	  stw       r0, 0xAC(r1)
	  lis       r0, 0x4330
	  lfs       f2, 0x0(r30)
	  stw       r0, 0xA8(r1)
	  lfd       f0, 0xA8(r1)
	  fsubs     f0, f0, f1
	  fadds     f1, f31, f0
	  fdivs     f0, f2, f1
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0x4(r30)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x8(r30)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r30)

	.loc_0x254:
	  lmw       r26, 0xB0(r1)
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801236C4
 * Size:	0000B4
 */
void PcamCamera::outputTargetWatchpoint(NVector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r4
	  stw       r30, 0x50(r1)
	  mr        r30, r3
	  lwz       r5, 0xCC(r3)
	  lwz       r0, 0x6C(r5)
	  cmpwi     r0, 0x36
	  bne-      .loc_0x40
	  addi      r3, r30, 0
	  addi      r4, r5, 0
	  addi      r5, r31, 0
	  bl        -0x2A4
	  b         .loc_0x58

	.loc_0x40:
	  lfs       f0, 0x94(r5)
	  stfs      f0, 0x0(r31)
	  lfs       f0, 0x98(r5)
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x9C(r5)
	  stfs      f0, 0x8(r31)

	.loc_0x58:
	  lwz       r3, 0xD0(r30)
	  li        r4, 0x30
	  lwz       r3, 0x24(r3)
	  bl        -0x518
	  lfs       f0, 0xD4(r30)
	  lfs       f4, -0x5F34(r2)
	  fdivs     f1, f0, f1
	  lfs       f2, 0x60(r30)
	  lfs       f0, 0x78(r30)
	  lfs       f3, 0x4(r31)
	  fsubs     f5, f4, f1
	  fsubs     f1, f4, f5
	  fmuls     f0, f0, f5
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x4(r31)
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
 * Address:	........
 * Size:	00006C
 */
void PcamCamera::makePolar()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
void PcamCamera::printInfo(Graphics&, Font*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80123778
 * Size:	000054
 */
void NArray<Creature>::indexOf(Creature*, int)
{
	/*
	.loc_0x0:
	  cmplwi    r4, 0
	  bne-      .loc_0x10
	  li        r3, -0x1
	  blr

	.loc_0x10:
	  lwz       r6, 0x8(r3)
	  rlwinm    r7,r5,2,0,29
	  sub       r0, r6, r5
	  cmpw      r5, r6
	  mtctr     r0
	  bge-      .loc_0x4C

	.loc_0x28:
	  lwz       r6, 0xC(r3)
	  lwzx      r0, r6, r7
	  cmplw     r0, r4
	  bne-      .loc_0x40
	  mr        r3, r5
	  blr

	.loc_0x40:
	  addi      r7, r7, 0x4
	  addi      r5, r5, 0x1
	  bdnz+     .loc_0x28

	.loc_0x4C:
	  li        r3, -0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801237CC
 * Size:	00003C
 */
void NArray<Creature>::set(int, Creature*)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  bltlr-
	  lwz       r6, 0x4(r3)
	  subi      r0, r6, 0x1
	  cmpw      r4, r0
	  bgtlr-
	  lwz       r6, 0xC(r3)
	  rlwinm    r0,r4,2,0,29
	  addi      r4, r4, 0x1
	  stwx      r5, r6, r0
	  lwz       r0, 0x8(r3)
	  cmpw      r4, r0
	  blelr-
	  stw       r4, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80123808
 * Size:	00013C
 */
void NArray<Creature>::remove(int, int)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  cmpwi     r5, 0
	  li        r6, 0
	  stw       r31, 0x1C(r1)
	  ble-      .loc_0xEC
	  cmpwi     r5, 0x8
	  subi      r7, r5, 0x8
	  ble-      .loc_0xC0
	  addi      r0, r7, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r7, 0
	  mtctr     r0
	  ble-      .loc_0xC0

	.loc_0x34:
	  add       r12, r4, r6
	  lwz       r7, 0xC(r3)
	  rlwinm    r0,r12,2,0,29
	  li        r31, 0
	  stwx      r31, r7, r0
	  addi      r7, r12, 0x1
	  addi      r0, r12, 0x2
	  lwz       r8, 0xC(r3)
	  rlwinm    r7,r7,2,0,29
	  addi      r10, r12, 0x3
	  stwx      r31, r8, r7
	  addi      r9, r12, 0x4
	  addi      r8, r12, 0x5
	  lwz       r11, 0xC(r3)
	  rlwinm    r0,r0,2,0,29
	  addi      r7, r12, 0x6
	  stwx      r31, r11, r0
	  addi      r0, r12, 0x7
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0xC(r3)
	  rlwinm    r9,r9,2,0,29
	  rlwinm    r8,r8,2,0,29
	  stwx      r31, r11, r10
	  rlwinm    r7,r7,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r10, 0xC(r3)
	  addi      r6, r6, 0x8
	  stwx      r31, r10, r9
	  lwz       r9, 0xC(r3)
	  stwx      r31, r9, r8
	  lwz       r8, 0xC(r3)
	  stwx      r31, r8, r7
	  lwz       r7, 0xC(r3)
	  stwx      r31, r7, r0
	  bdnz+     .loc_0x34

	.loc_0xC0:
	  sub       r0, r5, r6
	  cmpw      r6, r5
	  mtctr     r0
	  li        r8, 0
	  bge-      .loc_0xEC

	.loc_0xD4:
	  add       r0, r4, r6
	  lwz       r7, 0xC(r3)
	  rlwinm    r0,r0,2,0,29
	  stwx      r8, r7, r0
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0xD4

	.loc_0xEC:
	  add       r7, r4, r5
	  li        r9, 0
	  b         .loc_0x118

	.loc_0xF8:
	  add       r0, r5, r9
	  lwz       r8, 0xC(r3)
	  rlwinm    r6,r0,2,0,29
	  add       r0, r4, r9
	  lwzx      r6, r8, r6
	  rlwinm    r0,r0,2,0,29
	  stwx      r6, r8, r0
	  addi      r9, r9, 0x1

	.loc_0x118:
	  lwz       r6, 0x8(r3)
	  sub       r0, r6, r7
	  cmpw      r9, r0
	  blt+      .loc_0xF8
	  sub       r0, r6, r5
	  stw       r0, 0x8(r3)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80123944
 * Size:	000050
 */
void NArray<Creature>::remove(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  bltlr-
	  lwz       r5, 0x8(r3)
	  subi      r0, r5, 0x1
	  cmpw      r4, r0
	  bgtlr-
	  rlwinm    r6,r4,2,0,29
	  b         .loc_0x38

	.loc_0x20:
	  lwz       r0, 0xC(r3)
	  addi      r4, r4, 0x1
	  add       r5, r0, r6
	  lwz       r0, 0x4(r5)
	  addi      r6, r6, 0x4
	  stw       r0, 0x0(r5)

	.loc_0x38:
	  lwz       r5, 0x8(r3)
	  subi      r0, r5, 0x1
	  cmpw      r4, r0
	  blt+      .loc_0x20
	  stw       r0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80123994
 * Size:	000114
 */
void NArray<Creature>::insert(int, Creature*)
{
	/*
	.loc_0x0:
	  lwz       r7, 0x8(r3)
	  cmpw      r4, r7
	  bgelr-
	  addi      r0, r4, 0x1
	  cmpw      r7, r0
	  addi      r6, r7, 0x1
	  rlwinm    r7,r7,2,0,29
	  sub       r6, r6, r0
	  blt-      .loc_0xF8
	  rlwinm.   r0,r6,29,3,31
	  mtctr     r0
	  beq-      .loc_0xDC

	.loc_0x30:
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  bdnz+     .loc_0x30
	  andi.     r6, r6, 0x7
	  beq-      .loc_0xF8

	.loc_0xDC:
	  mtctr     r6

	.loc_0xE0:
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  bdnz+     .loc_0xE0

	.loc_0xF8:
	  lwz       r6, 0xC(r3)
	  rlwinm    r0,r4,2,0,29
	  stwx      r5, r6, r0
	  lwz       r4, 0x8(r3)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80123AA8
 * Size:	000030
 */
void NArray<Creature>::firstElement()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
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
 * Address:	80123AD8
 * Size:	000034
 */
void NArray<Creature>::lastElement()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x8(r3)
	  lwz       r12, 0x34(r12)
	  subi      r4, r4, 0x1
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
 * Address:	80123B0C
 * Size:	000050
 */
void NArray<Creature>::remove(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x0(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x28(r12)
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
 * Address:	80123B5C
 * Size:	000034
 */
void NArray<Creature>::removeAll()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r5, 0x8(r3)
	  lwz       r12, 0x20(r12)
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
 * Address:	80123B90
 * Size:	000050
 */
void NArray<Creature>::add(int, Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x8(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x30
	  lwz       r12, 0x0(r3)
	  mr        r4, r5
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x40

	.loc_0x30:
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x40:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80123BE0
 * Size:	000030
 */
void NArray<Creature>::indexOf(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
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
 * Address:	80123C10
 * Size:	000044
 */
void NArray<Creature>::contains(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  srawi     r4, r3, 0x1F
	  rlwinm    r5,r0,1,31,31
	  subc      r0, r3, r0
	  adde      r3, r4, r5
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
