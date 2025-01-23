#include "TAI/Mizinko.h"
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
 * Address:	80131F64
 * Size:	0000B0
 */
TaiMizigenParameters::TaiMizigenParameters()
    : TekiParameters(20, 50)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x14
	  stw       r0, 0x4(r1)
	  li        r5, 0x32
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  bl        0x19DC8
	  lis       r3, 0x802D
	  subi      r0, r3, 0x6DA0
	  stw       r0, 0x0(r31)
	  li        r5, 0x6
	  li        r0, 0x1
	  lwz       r6, 0x84(r31)
	  mr        r3, r31
	  lwz       r4, 0x0(r6)
	  lwz       r4, 0x0(r4)
	  stw       r5, 0xC(r4)
	  lwz       r4, 0x0(r6)
	  lwz       r4, 0x0(r4)
	  stw       r0, 0x1C(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f0, -0x5C18(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0x3C(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f0, -0x5C14(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0x34(r4)
	  lwz       r4, 0x4(r6)
	  lfs       f0, -0x5C10(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0x58(r4)
	  lwz       r4, 0x4(r6)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0x5C(r4)
	  lwz       r4, 0x4(r6)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0x60(r4)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80132014
 * Size:	00017C
 */
TaiMizigenStrategy::TaiMizigenStrategy(TekiParameters*)
    : TaiStrategy(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x48(r1)
	  stw       r29, 0x44(r1)
	  addi      r29, r4, 0
	  li        r4, 0x2
	  bl        -0xAC58
	  lis       r3, 0x802D
	  subi      r0, r3, 0x6E20
	  stw       r0, 0x0(r31)
	  li        r3, 0x14
	  bl        -0xEB04C
	  cmplwi    r3, 0
	  beq-      .loc_0x8C
	  lwz       r6, 0x84(r29)
	  lis       r5, 0x802C
	  lis       r4, 0x802D
	  lwz       r7, 0x4(r6)
	  addi      r6, r5, 0x6620
	  li        r5, 0x1
	  lwz       r7, 0x0(r7)
	  subi      r4, r4, 0x35D8
	  li        r0, 0
	  lfs       f0, 0x34(r7)
	  stw       r6, 0x4(r3)
	  stw       r5, 0x0(r3)
	  stw       r4, 0x4(r3)
	  stw       r0, 0x8(r3)
	  stfs      f0, 0xC(r3)
	  lfs       f0, -0x5C0C(r2)
	  stfs      f0, 0x10(r3)

	.loc_0x8C:
	  li        r3, 0x8
	  bl        -0xEB0A0
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xC0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6EA8
	  stw       r0, 0x4(r30)

	.loc_0xC0:
	  li        r3, 0xC
	  bl        -0xEB0D4
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xDC
	  li        r4, 0x1
	  bl        -0xB054

	.loc_0xDC:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r3, 0x8
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x0(r4)
	  bl        -0xEB108
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x128
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6E64
	  stw       r0, 0x4(r29)

	.loc_0x128:
	  li        r3, 0xC
	  bl        -0xEB13C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x144
	  li        r4, 0x1
	  bl        -0xB0BC

	.loc_0x144:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r0
	  mr        r3, r31
	  lwz       r4, 0x8(r31)
	  stw       r30, 0x4(r4)
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80132190
 * Size:	00008C
 */
void TaiMizigenStrategy::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0xAD10
	  mr        r3, r31
	  lwz       r4, -0x9D4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9C0(r13)
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
	  lwz       r4, -0x9C8(r13)
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
 * Address:	8013221C
 * Size:	000164
 */
void TaiMizigenGeneratingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stfd      f30, 0xC0(r1)
	  stw       r31, 0xBC(r1)
	  stw       r30, 0xB8(r1)
	  mr        r30, r4
	  mr        r3, r30
	  lwz       r4, 0x2C4(r4)
	  lwz       r12, 0x0(r30)
	  lwz       r4, 0x84(r4)
	  lwz       r12, 0x194(r12)
	  lwz       r4, 0x0(r4)
	  mtlr      r12
	  lwz       r4, 0x0(r4)
	  lwz       r4, 0xC(r4)
	  blrl
	  mr.       r31, r3
	  beq-      .loc_0x144
	  lwz       r4, 0x2C8(r30)
	  li        r0, 0
	  addi      r3, r1, 0xAC
	  lwz       r4, 0x34(r4)
	  lwz       r4, 0x0(r4)
	  lwz       r4, 0x0(r4)
	  stw       r0, 0x10(r4)
	  bl        -0x15434
	  lfs       f30, 0xA0(r30)
	  fmr       f1, f30
	  bl        0xE98C0
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE9A48
	  stfs      f1, 0xAC(r1)
	  lfs       f0, -0x1320(r13)
	  stfs      f0, 0xB0(r1)
	  stfs      f31, 0xB4(r1)
	  lwz       r3, 0x2C8(r30)
	  lfs       f0, -0x5C10(r2)
	  lwz       r3, 0x34(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0x8(r3)
	  fcmpo     cr0, f1, f0
	  fmr       f5, f1
	  cror      2, 0, 0x2
	  bne-      .loc_0xC4
	  lfs       f5, -0x5C08(r2)

	.loc_0xC4:
	  lfs       f0, 0xAC(r1)
	  mr        r3, r31
	  li        r4, 0
	  fmuls     f0, f0, f5
	  stfs      f0, 0xAC(r1)
	  lfs       f0, 0xB0(r1)
	  fmuls     f0, f0, f5
	  stfs      f0, 0xB0(r1)
	  lfs       f0, 0xB4(r1)
	  fmuls     f0, f0, f5
	  stfs      f0, 0xB4(r1)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0xAC(r1)
	  lfs       f3, 0x98(r30)
	  lfs       f2, 0xB0(r1)
	  fadds     f0, f1, f0
	  lfs       f4, 0x9C(r30)
	  lfs       f1, 0xB4(r1)
	  fadds     f2, f3, f2
	  stfs      f0, 0x388(r31)
	  fadds     f0, f4, f1
	  stfs      f2, 0x38C(r31)
	  stfs      f0, 0x390(r31)
	  lwz       r5, 0x2C8(r31)
	  lwz       r5, 0x34(r5)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0x8(r5)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x144:
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lfd       f30, 0xC0(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80132380
 * Size:	000008
 */
bool TaiMizigenGeneratingAction::act(Teki&)
{
	return true;
}

/*
 * --INFO--
 * Address:	80132388
 * Size:	0000B8
 */
bool TaiMizigenNaviApprouchAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  mr        r31, r4
	  lwz       r3, 0x2C8(r4)
	  lwz       r3, 0x34(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x10(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x38
	  li        r3, 0
	  b         .loc_0xA4

	.loc_0x38:
	  addi      r4, r31, 0x94
	  addi      r3, r1, 0x90
	  bl        -0x15548
	  lwz       r3, 0x3120(r13)
	  li        r4, 0
	  bl        -0x1AF9C
	  addi      r3, r3, 0x94
	  lfs       f3, 0x98(r1)
	  lfs       f2, 0x8(r3)
	  lfs       f1, 0x90(r1)
	  lfs       f0, 0x0(r3)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f1, f1, f0
	  bl        -0x1247C0
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x3C(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xA0
	  li        r3, 0
	  b         .loc_0xA4

	.loc_0xA0:
	  li        r3, 0x1

	.loc_0xA4:
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80132440
 * Size:	000380
 */
TaiMizinkoParameters::TaiMizinkoParameters()
    : TekiParameters(20, 64)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  li        r5, 0x40
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  subi      r31, r4, 0x73A8
	  li        r4, 0x14
	  stw       r30, 0x78(r1)
	  addi      r30, r3, 0
	  bl        0x198E0
	  lis       r3, 0x802D
	  subi      r0, r3, 0x6F04
	  stw       r0, 0x0(r30)
	  li        r0, 0x32
	  li        r6, 0x33
	  lwz       r3, 0x84(r30)
	  li        r5, 0x34
	  li        r4, 0x35
	  lwz       r8, 0x4(r3)
	  li        r3, 0x36
	  mulli     r7, r0, 0xC
	  lwz       r0, 0x8(r8)
	  add       r8, r0, r7
	  addi      r7, r31, 0x1C
	  stw       r7, 0x0(r8)
	  mulli     r7, r6, 0xC
	  lfs       f1, -0x5C10(r2)
	  mulli     r6, r5, 0xC
	  stfs      f1, 0x4(r8)
	  lfs       f0, -0x5C18(r2)
	  mulli     r5, r4, 0xC
	  stfs      f0, 0x8(r8)
	  add       r8, r0, r7
	  addi      r4, r31, 0x2C
	  stw       r4, 0x0(r8)
	  mulli     r4, r3, 0xC
	  stfs      f1, 0x4(r8)
	  li        r3, 0x37
	  lfs       f6, -0x5C04(r2)
	  mulli     r7, r3, 0xC
	  stfs      f6, 0x8(r8)
	  add       r9, r0, r6
	  addi      r3, r31, 0x3C
	  stw       r3, 0x0(r9)
	  li        r3, 0x38
	  mulli     r6, r3, 0xC
	  stfs      f1, 0x4(r9)
	  lfs       f0, -0x5C00(r2)
	  add       r10, r0, r5
	  addi      r8, r31, 0x54
	  stfs      f0, 0x8(r9)
	  li        r3, 0x39
	  mulli     r5, r3, 0xC
	  stw       r8, 0x0(r10)
	  stfs      f1, 0x4(r10)
	  add       r9, r0, r4
	  addi      r8, r31, 0x70
	  stfs      f0, 0x8(r10)
	  li        r3, 0x3A
	  mulli     r4, r3, 0xC
	  stw       r8, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  li        r3, 0x3B
	  mulli     r3, r3, 0xC
	  lfs       f5, -0x5BFC(r2)
	  stfs      f5, 0x8(r9)
	  add       r8, r0, r7
	  addi      r7, r31, 0x7C
	  stw       r7, 0x0(r8)
	  add       r7, r0, r6
	  addi      r6, r31, 0x8C
	  stfs      f1, 0x4(r8)
	  add       r9, r0, r5
	  addi      r5, r31, 0xA8
	  lfs       f0, -0x5BF8(r2)
	  add       r10, r0, r4
	  addi      r4, r31, 0xC4
	  stfs      f0, 0x8(r8)
	  add       r8, r0, r3
	  stw       r6, 0x0(r7)
	  stfs      f1, 0x4(r7)
	  lfs       f4, -0x5C08(r2)
	  stfs      f4, 0x8(r7)
	  stw       r5, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f4, 0x8(r9)
	  stw       r4, 0x0(r10)
	  stfs      f1, 0x4(r10)
	  stfs      f6, 0x8(r10)
	  addi      r3, r31, 0xD8
	  stw       r3, 0x0(r8)
	  li        r3, 0x3C
	  mulli     r4, r3, 0xC
	  stfs      f1, 0x4(r8)
	  stfs      f4, 0x8(r8)
	  li        r3, 0x3D
	  add       r6, r0, r4
	  addi      r4, r31, 0xF8
	  stw       r4, 0x0(r6)
	  mulli     r5, r3, 0xC
	  stfs      f1, 0x4(r6)
	  li        r3, 0x3E
	  lfs       f3, -0x1CA4(r13)
	  mulli     r4, r3, 0xC
	  stfs      f3, 0x8(r6)
	  add       r5, r0, r5
	  addi      r3, r31, 0x10C
	  stw       r3, 0x0(r5)
	  li        r3, 0x3F
	  mulli     r3, r3, 0xC
	  stfs      f1, 0x4(r5)
	  stfs      f4, 0x8(r5)
	  add       r6, r0, r4
	  addi      r4, r31, 0x12C
	  stw       r4, 0x0(r6)
	  add       r4, r0, r3
	  addi      r3, r31, 0x138
	  stfs      f1, 0x4(r6)
	  li        r5, -0x1
	  li        r0, 0x1
	  stfs      f0, 0x8(r6)
	  stw       r3, 0x0(r4)
	  stfs      f1, 0x4(r4)
	  stfs      f4, 0x8(r4)
	  lwz       r4, 0x84(r30)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0xC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x20(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x5BF4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5BF0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x74(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x5BEC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x64(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x44(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x48(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x50(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5C14(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x54(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0xAC(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r5, 0x4(r4)
	  mr        r3, r30
	  lfs       f0, -0x5BE8(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xCC(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5BE4(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xD0(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f6, 0xD4(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f4, 0xD8(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0xDC(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5BE0(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xE0(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xE4(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0xE8(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xEC(r5)
	  lfs       f0, -0x5BDC(r2)
	  lwz       r5, 0x4(r4)
	  fmuls     f0, f3, f0
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xF0(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5BD8(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xF4(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0xF8(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0xFC(r4)
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801327C0
 * Size:	000084
 */
TaiMizinkoSoundTable::TaiMizinkoSoundTable()
    : PaniSoundTable(4)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0x1376C
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0xEB7F0
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0x89
	  stw       r0, 0x0(r3)

	.loc_0x48:
	  lwz       r4, 0x4(r29)
	  addi      r30, r30, 0x1
	  stwx      r3, r4, r31
	  addi      r31, r31, 0x4

	.loc_0x58:
	  lwz       r0, 0x0(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x30
	  mr        r3, r29
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
 * Address:	80132844
 * Size:	0008B4
 */
TaiMizinkoStrategy::TaiMizinkoStrategy(TekiParameters*)
    : TaiStrategy(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x168(r1)
	  stmw      r18, 0x130(r1)
	  addi      r21, r4, 0
	  addi      r31, r3, 0
	  li        r4, 0x7
	  bl        -0xB480
	  lis       r3, 0x802D
	  subi      r0, r3, 0x6FC0
	  stw       r0, 0x0(r31)
	  li        r3, 0x8
	  bl        -0xEB874
	  addi      r22, r3, 0
	  mr.       r0, r22
	  beq-      .loc_0x64
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r22)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r22)
	  subi      r0, r3, 0x6318
	  stw       r0, 0x4(r22)

	.loc_0x64:
	  li        r3, 0x8
	  bl        -0xEB8A8
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x98
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x63D0
	  stw       r0, 0x4(r30)

	.loc_0x98:
	  li        r3, 0x8
	  bl        -0xEB8DC
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0xCC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r23)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r23)
	  subi      r0, r3, 0x6290
	  stw       r0, 0x4(r23)

	.loc_0xCC:
	  li        r3, 0x8
	  bl        -0xEB910
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x100
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r24)
	  subi      r0, r3, 0x71E4
	  stw       r0, 0x4(r24)

	.loc_0x100:
	  li        r3, 0xC
	  bl        -0xEB944
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x13C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0x2
	  stw       r3, 0x4(r29)
	  stw       r0, 0x8(r29)

	.loc_0x13C:
	  li        r3, 0x8
	  bl        -0xEB980
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x170
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x70E0
	  stw       r0, 0x4(r28)

	.loc_0x170:
	  li        r3, 0x8
	  bl        -0xEB9B4
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x1B0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x4
	  lis       r3, 0x802C
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x7D8C
	  lis       r3, 0x802C
	  stw       r0, 0x4(r27)
	  addi      r0, r3, 0x7D70
	  stw       r0, 0x4(r27)

	.loc_0x1B0:
	  li        r3, 0x8
	  bl        -0xEB9F4
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x1E4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, 0x4
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x4580
	  stw       r0, 0x4(r26)

	.loc_0x1E4:
	  li        r3, 0x14
	  bl        -0xEBA28
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0x248
	  lwz       r3, 0x84(r21)
	  lis       r5, 0x802C
	  lis       r4, 0x802D
	  lwz       r6, 0x4(r3)
	  lis       r3, 0x802D
	  addi      r7, r5, 0x6620
	  lwz       r8, 0x0(r6)
	  li        r6, -0x1
	  subi      r5, r4, 0x35D8
	  lfs       f0, 0xFC(r8)
	  li        r4, 0x1
	  lfs       f1, 0xF8(r8)
	  subi      r0, r3, 0x702C
	  stw       r7, 0x4(r25)
	  stw       r6, 0x0(r25)
	  stw       r5, 0x4(r25)
	  stw       r4, 0x8(r25)
	  stfs      f1, 0xC(r25)
	  stfs      f0, 0x10(r25)
	  stw       r0, 0x4(r25)

	.loc_0x248:
	  li        r3, 0x8
	  bl        -0xEBA8C
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x27C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r20)
	  subi      r0, r3, 0x7120
	  stw       r0, 0x4(r20)

	.loc_0x27C:
	  li        r3, 0x14
	  bl        -0xEBAC0
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x2D0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r19)
	  subi      r0, r3, 0x35D8
	  li        r4, 0
	  stw       r0, 0x4(r19)
	  lis       r3, 0x802D
	  subi      r0, r3, 0x7078
	  stw       r4, 0x8(r19)
	  lfs       f0, -0x5C10(r2)
	  stfs      f0, 0xC(r19)
	  stfs      f0, 0x10(r19)
	  stw       r0, 0x4(r19)

	.loc_0x2D0:
	  li        r3, 0xC
	  bl        -0xEBB14
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x2EC
	  li        r4, 0x9
	  bl        -0xBA94

	.loc_0x2EC:
	  li        r0, 0
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r26, r3, r0
	  li        r6, 0x4
	  li        r7, 0x5
	  lwz       r3, 0x8(r18)
	  rlwinm    r0,r4,2,0,29
	  li        r8, 0x6
	  stwx      r29, r3, r0
	  li        r9, 0x7
	  li        r10, 0x8
	  lwz       r4, 0x8(r18)
	  rlwinm    r0,r5,2,0,29
	  rlwinm    r3,r6,2,0,29
	  stwx      r30, r4, r0
	  rlwinm    r6,r7,2,0,29
	  rlwinm    r5,r8,2,0,29
	  lwz       r7, 0x8(r18)
	  rlwinm    r4,r9,2,0,29
	  rlwinm    r0,r10,2,0,29
	  stwx      r23, r7, r3
	  li        r3, 0x14
	  lwz       r7, 0x8(r18)
	  stwx      r19, r7, r6
	  lwz       r6, 0x8(r18)
	  stwx      r20, r6, r5
	  lwz       r5, 0x8(r18)
	  stwx      r28, r5, r4
	  lwz       r4, 0x8(r18)
	  stwx      r25, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r18, 0x0(r4)
	  bl        -0xEBBC8
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x3DC
	  lwz       r5, 0x84(r21)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, 0x2
	  lwz       r6, 0x0(r6)
	  subi      r3, r3, 0x35D8
	  li        r0, 0
	  lfs       f0, 0xE0(r6)
	  lfs       f1, 0xDC(r6)
	  stw       r5, 0x4(r18)
	  stw       r4, 0x0(r18)
	  stw       r3, 0x4(r18)
	  stw       r0, 0x8(r18)
	  stfs      f1, 0xC(r18)
	  stfs      f0, 0x10(r18)

	.loc_0x3DC:
	  li        r3, 0xC
	  bl        -0xEBC20
	  addi      r19, r3, 0
	  mr.       r3, r19
	  beq-      .loc_0x3F8
	  li        r4, 0x2
	  bl        -0xBBA0

	.loc_0x3F8:
	  li        r0, 0
	  lwz       r3, 0x8(r19)
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r19)
	  li        r3, 0x8
	  stwx      r24, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r19, 0x4(r4)
	  bl        -0xEBC64
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x454
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r18)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r18)
	  subi      r0, r3, 0x7160
	  stw       r0, 0x4(r18)

	.loc_0x454:
	  li        r3, 0x14
	  bl        -0xEBC98
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x4A8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, 0x3
	  lis       r3, 0x802D
	  stw       r0, 0x0(r19)
	  subi      r0, r3, 0x35D8
	  li        r4, 0
	  stw       r0, 0x4(r19)
	  lis       r3, 0x802D
	  subi      r0, r3, 0x7078
	  stw       r4, 0x8(r19)
	  lfs       f0, -0x5C10(r2)
	  stfs      f0, 0xC(r19)
	  stfs      f0, 0x10(r19)
	  stw       r0, 0x4(r19)

	.loc_0x4A8:
	  li        r3, 0xC
	  bl        -0xEBCEC
	  addi      r20, r3, 0
	  mr.       r3, r20
	  beq-      .loc_0x4C4
	  li        r4, 0x9
	  bl        -0xBC6C

	.loc_0x4C4:
	  li        r0, 0
	  lwz       r3, 0x8(r20)
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r20)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r26, r3, r0
	  li        r6, 0x4
	  li        r7, 0x5
	  lwz       r3, 0x8(r20)
	  rlwinm    r0,r4,2,0,29
	  li        r8, 0x6
	  stwx      r29, r3, r0
	  li        r9, 0x7
	  li        r10, 0x8
	  lwz       r4, 0x8(r20)
	  rlwinm    r0,r5,2,0,29
	  rlwinm    r3,r6,2,0,29
	  stwx      r30, r4, r0
	  rlwinm    r6,r7,2,0,29
	  rlwinm    r5,r8,2,0,29
	  lwz       r7, 0x8(r20)
	  rlwinm    r4,r9,2,0,29
	  rlwinm    r0,r10,2,0,29
	  stwx      r23, r7, r3
	  li        r3, 0x14
	  lwz       r7, 0x8(r20)
	  stwx      r19, r7, r6
	  lwz       r6, 0x8(r20)
	  stwx      r18, r6, r5
	  lwz       r5, 0x8(r20)
	  stwx      r28, r5, r4
	  lwz       r4, 0x8(r20)
	  stwx      r25, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r20, 0x8(r4)
	  bl        -0xEBDA0
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x5B0
	  lwz       r5, 0x84(r21)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, 0
	  lwz       r6, 0x0(r6)
	  subi      r0, r3, 0x35D8
	  lfs       f0, 0xE0(r6)
	  lfs       f1, 0xDC(r6)
	  stw       r5, 0x4(r18)
	  stw       r4, 0x0(r18)
	  stw       r0, 0x4(r18)
	  stw       r4, 0x8(r18)
	  stfs      f1, 0xC(r18)
	  stfs      f0, 0x10(r18)

	.loc_0x5B0:
	  li        r3, 0xC
	  bl        -0xEBDF4
	  addi      r19, r3, 0
	  mr.       r3, r19
	  beq-      .loc_0x5CC
	  li        r4, 0x2
	  bl        -0xBD74

	.loc_0x5CC:
	  li        r0, 0
	  lwz       r3, 0x8(r19)
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r19)
	  li        r3, 0x8
	  stwx      r24, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r19, 0xC(r4)
	  bl        -0xEBE38
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x628
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r18)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r18)
	  addi      r0, r3, 0x6A60
	  stw       r0, 0x4(r18)

	.loc_0x628:
	  li        r3, 0xC
	  bl        -0xEBE6C
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x670
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, 0x5
	  lis       r3, 0x802D
	  stw       r0, 0x0(r19)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r19)
	  li        r4, 0x1
	  subi      r0, r3, 0x4650
	  stw       r4, 0x8(r19)
	  stw       r0, 0x4(r19)

	.loc_0x670:
	  li        r3, 0x8
	  bl        -0xEBEB4
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x6A4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r20)
	  subi      r0, r3, 0x71A0
	  stw       r0, 0x4(r20)

	.loc_0x6A4:
	  li        r3, 0xC
	  bl        -0xEBEE8
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x6C0
	  li        r4, 0x3
	  bl        -0xBE68

	.loc_0x6C0:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r0,r0,2,0,29
	  stwx      r19, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r4, 0x8(r24)
	  rlwinm    r3,r0,2,0,29
	  rlwinm    r0,r5,2,0,29
	  stwx      r20, r4, r3
	  li        r3, 0x14
	  lwz       r4, 0x8(r24)
	  stwx      r18, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x10(r4)
	  bl        -0xEBF3C
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x750
	  lwz       r5, 0x84(r21)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x4(r5)
	  addi      r5, r4, 0x6620
	  li        r4, 0x6
	  lwz       r6, 0x0(r6)
	  subi      r3, r3, 0x35D8
	  li        r0, 0
	  lfs       f0, 0x64(r6)
	  stw       r5, 0x4(r18)
	  stw       r4, 0x0(r18)
	  stw       r3, 0x4(r18)
	  stw       r0, 0x8(r18)
	  stfs      f0, 0xC(r18)
	  lfs       f0, -0x5C10(r2)
	  stfs      f0, 0x10(r18)

	.loc_0x750:
	  li        r3, 0x8
	  bl        -0xEBF94
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x784
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r19)
	  subi      r0, r3, 0x7224
	  stw       r0, 0x4(r19)

	.loc_0x784:
	  li        r3, 0xC
	  bl        -0xEBFC8
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x7C0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r20)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0
	  stw       r3, 0x4(r20)
	  stw       r0, 0x8(r20)

	.loc_0x7C0:
	  li        r3, 0xC
	  bl        -0xEC004
	  addi      r21, r3, 0
	  mr.       r3, r21
	  beq-      .loc_0x7DC
	  li        r4, 0x5
	  bl        -0xBF84

	.loc_0x7DC:
	  li        r0, 0
	  lwz       r3, 0x8(r21)
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r21)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x3
	  stwx      r20, r3, r0
	  li        r0, 0x4
	  rlwinm    r3,r4,2,0,29
	  lwz       r5, 0x8(r21)
	  rlwinm    r4,r6,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r22, r5, r3
	  li        r3, 0x8
	  lwz       r5, 0x8(r21)
	  stwx      r23, r5, r4
	  lwz       r4, 0x8(r21)
	  stwx      r19, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r21, 0x14(r4)
	  bl        -0xEC078
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x868
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r18)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r18)
	  subi      r0, r3, 0x4388
	  stw       r0, 0x4(r18)

	.loc_0x868:
	  li        r3, 0xC
	  bl        -0xEC0AC
	  addi      r19, r3, 0
	  mr.       r3, r19
	  beq-      .loc_0x884
	  li        r4, 0x1
	  bl        -0xC02C

	.loc_0x884:
	  li        r0, 0
	  lwz       r3, 0x8(r19)
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r0
	  mr        r3, r31
	  lwz       r4, 0x8(r31)
	  stw       r19, 0x18(r4)
	  lwz       r0, 0x16C(r1)
	  lmw       r18, 0x130(r1)
	  addi      r1, r1, 0x168
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801330F8
 * Size:	0000A8
 */
void TaiMizinkoStrategy::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  addi      r5, r1, 0x10
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  li        r4, 0x56
	  lfs       f0, -0x131C(r13)
	  lfs       f1, -0x1318(r13)
	  stfs      f0, 0x10(r1)
	  lfs       f0, -0x1314(r13)
	  stfs      f1, 0x14(r1)
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x18(r1)
	  bl        0x699F8
	  lwz       r5, 0x3D8(r31)
	  mr        r4, r31
	  stw       r3, 0x0(r5)
	  mr        r3, r30
	  bl        -0xBCC0
	  lwz       r0, 0xC8(r31)
	  addi      r3, r31, 0
	  ori       r0, r0, 0x40
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,31,29
	  stw       r0, 0xC8(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r4, -0x9CC(r13)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
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
 * Address:	801331A0
 * Size:	00010C
 */
void TaiMizinkoStrategy::draw(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x70(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x6C(r1)
	  addi      r29, r3, 0
	  bl        .loc_0x10C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x44
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  bl        0x19FE8
	  b         .loc_0x54

	.loc_0x44:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  bl        0x19FD4

	.loc_0x54:
	  lwz       r3, 0x3D8(r30)
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xF0
	  lwz       r3, 0x410(r30)
	  lwz       r0, -0x9AC(r13)
	  and.      r0, r3, r0
	  bne-      .loc_0x84
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x16800
	  b         .loc_0xF0

	.loc_0x84:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        .loc_0x10C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xA8
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x167DC
	  b         .loc_0xF0

	.loc_0xA8:
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x167A8
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r1, 0x24
	  addi      r3, r3, 0x1E0
	  bl        -0xF4E24
	  addi      r3, r1, 0x18
	  bl        -0x16414
	  addi      r3, r30, 0
	  addi      r4, r1, 0x18
	  addi      r6, r1, 0x24
	  li        r5, 0xD
	  bl        0x165CC
	  addi      r3, r30, 0
	  addi      r5, r1, 0x18
	  li        r4, 0
	  bl        0x167B4

	.loc_0xF0:
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr

	.loc_0x10C:
	*/
}

/*
 * --INFO--
 * Address:	801332AC
 * Size:	000014
 */
bool TaiMizinkoStrategy::hasWater(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x420(r4)
	  neg       r0, r0
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801332C0
 * Size:	00007C
 */
bool TaiMizinkoCryTimerAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r0, 0x8(r3)
	  lfs       f0, -0x5C10(r2)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r31, r0
	  lfs       f1, 0x3C4(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x60
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  li        r4, 0x8C
	  lwz       r12, 0x1C0(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x103FC

	.loc_0x60:
	  lwz       r0, 0x24(r1)
	  li        r3, 0
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013333C
 * Size:	000050
 */
void TaiMizinkoMovingTimerAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r6, 0x2C8(r4)
	  lwz       r5, 0x2C4(r4)
	  lwz       r6, 0x34(r6)
	  lwz       r5, 0x84(r5)
	  lwz       r6, 0x4(r6)
	  lwz       r5, 0x4(r5)
	  lwz       r6, 0x0(r6)
	  lwz       r5, 0x0(r5)
	  lfs       f1, 0x8(r6)
	  lfs       f0, 0xC(r5)
	  fdivs     f0, f1, f0
	  stfs      f0, 0xC(r3)
	  bl        0x103A0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013338C
 * Size:	000088
 */
bool TaiMizinkoFadingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x2C4(r4)
	  lwz       r3, 0x2C8(r4)
	  lwz       r5, 0x84(r5)
	  lwz       r3, 0x34(r3)
	  lwz       r5, 0x4(r5)
	  lwz       r3, 0x4(r3)
	  lwz       r5, 0x0(r5)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xC(r5)
	  lfs       f0, 0x8(r3)
	  lfs       f2, 0x3C4(r4)
	  fdivs     f0, f0, f1
	  lfs       f1, 0xD8(r5)
	  fsubs     f0, f0, f2
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x4C
	  fdivs     f0, f0, f1
	  stfs      f0, 0x3C0(r4)
	  b         .loc_0x68

	.loc_0x4C:
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x60
	  fdivs     f0, f2, f1
	  stfs      f0, 0x3C0(r4)
	  b         .loc_0x68

	.loc_0x60:
	  lfs       f0, -0x5C08(r2)
	  stfs      f0, 0x3C0(r4)

	.loc_0x68:
	  lwz       r5, 0x2C8(r4)
	  li        r3, 0
	  lfs       f0, 0x3C0(r4)
	  lwz       r4, 0x34(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0x0(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80133414
 * Size:	0003C4
 */
void TaiMizinkoGoingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r5, r13, 0x1328
	  stw       r0, 0x4(r1)
	  subi      r6, r13, 0x1324
	  stwu      r1, -0x268(r1)
	  stfd      f31, 0x260(r1)
	  addi      r3, r1, 0x17C
	  stfd      f30, 0x258(r1)
	  stfd      f29, 0x250(r1)
	  stfd      f28, 0x248(r1)
	  stfd      f27, 0x240(r1)
	  stw       r31, 0x23C(r1)
	  addi      r31, r4, 0
	  subi      r4, r13, 0x132C
	  stw       r30, 0x238(r1)
	  bl        -0xFC334
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x17C
	  addi      r5, r1, 0x180
	  addi      r6, r1, 0x184
	  bl        -0xD5DD8
	  addi      r3, r1, 0x170
	  subi      r4, r13, 0x1338
	  subi      r5, r13, 0x1334
	  subi      r6, r13, 0x1330
	  bl        -0xFC35C
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x170
	  addi      r5, r1, 0x174
	  addi      r6, r1, 0x178
	  bl        -0xD5E00
	  mr        r3, r31
	  lwz       r4, -0x9D4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r0, -0x9C8(r13)
	  lwz       r12, 0x1CC(r12)
	  lwz       r5, -0x9A8(r13)
	  or        r0, r4, r0
	  lwz       r4, -0x9D0(r13)
	  mtlr      r12
	  or        r0, r5, r0
	  or        r4, r4, r0
	  blrl
	  lwz       r4, 0x2C8(r31)
	  addi      r3, r1, 0x208
	  addi      r4, r4, 0x10
	  bl        -0x1664C
	  lwz       r12, 0x358(r31)
	  addi      r3, r31, 0x358
	  lfs       f28, 0x388(r31)
	  addi      r4, r1, 0x208
	  lwz       r12, 0x8(r12)
	  lfs       f29, 0x38C(r31)
	  mtlr      r12
	  lfs       f30, 0x390(r31)
	  blrl
	  addi      r3, r1, 0x1F0
	  bl        -0x166A4
	  lfs       f0, 0x208(r1)
	  addi      r3, r1, 0x1F0
	  fsubs     f0, f28, f0
	  stfs      f0, 0x1F0(r1)
	  lfs       f0, 0x20C(r1)
	  fsubs     f0, f29, f0
	  stfs      f0, 0x1F4(r1)
	  lfs       f0, 0x210(r1)
	  fsubs     f0, f30, f0
	  stfs      f0, 0x1F8(r1)
	  bl        -0x1650C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x144
	  lfs       f29, 0xA0(r31)
	  fmr       f1, f29
	  bl        0xE861C
	  fmr       f28, f1
	  fmr       f1, f29
	  bl        0xE87A4
	  stfs      f1, 0x1F0(r1)
	  lfs       f0, -0x1320(r13)
	  stfs      f0, 0x1F4(r1)
	  stfs      f28, 0x1F8(r1)

	.loc_0x144:
	  lfs       f1, 0x1F0(r1)
	  lfs       f2, 0x1F8(r1)
	  bl        -0x15758
	  stfs      f1, 0xA0(r31)
	  li        r4, 0x3
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x110A4
	  lfs       f0, 0x1F0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1F0(r1)
	  lfs       f0, 0x1F4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1F4(r1)
	  lfs       f0, 0x1F8(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1F8(r1)
	  lwz       r3, 0x2C4(r31)
	  lfs       f1, 0x20C(r1)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x74(r3)
	  lfs       f29, 0xE4(r3)
	  fadds     f28, f1, f0
	  bl        0xE4AB0
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C4(r31)
	  stw       r0, 0x234(r1)
	  lis       r30, 0x4330
	  lwz       r3, 0x84(r3)
	  stw       r30, 0x230(r1)
	  lwz       r3, 0x4(r3)
	  lfd       f1, -0x5BC8(r2)
	  lfd       f0, 0x230(r1)
	  lwz       r3, 0x0(r3)
	  fsubs     f3, f0, f1
	  lfs       f1, -0x5BD4(r2)
	  lfs       f2, -0x5C08(r2)
	  lfs       f0, -0x5C0C(r2)
	  fdivs     f3, f3, f1
	  lfs       f1, -0x5BD0(r2)
	  lfs       f31, 0xEC(r3)
	  lfs       f30, 0xE8(r3)
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f28, f0
	  fmuls     f0, f29, f0
	  fadds     f29, f28, f0
	  bl        0xE4A4C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x5BC8(r2)
	  stw       r0, 0x22C(r1)
	  lfs       f3, -0x5BD4(r2)
	  stw       r30, 0x228(r1)
	  lfs       f2, -0x5C08(r2)
	  lfd       f1, 0x228(r1)
	  lfs       f0, -0x5C0C(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x5BD0(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f30, f0
	  fmuls     f0, f31, f0
	  fadds     f28, f30, f0
	  bl        0xE4A04
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C4(r31)
	  stw       r0, 0x224(r1)
	  lwz       r3, 0x84(r3)
	  stw       r30, 0x220(r1)
	  lwz       r3, 0x4(r3)
	  lfd       f1, -0x5BC8(r2)
	  lfd       f0, 0x220(r1)
	  lwz       r3, 0x0(r3)
	  fsubs     f3, f0, f1
	  lfs       f2, -0x5BD4(r2)
	  lfs       f1, -0x5BD0(r2)
	  lfs       f0, -0x1CA4(r13)
	  fdivs     f4, f3, f2
	  lfs       f3, -0x5C08(r2)
	  lfs       f2, -0x5C10(r2)
	  lfs       f30, 0xF4(r3)
	  lfs       f31, 0xF0(r3)
	  fmuls     f0, f1, f0
	  fmuls     f1, f3, f4
	  fsubs     f0, f0, f2
	  fmuls     f0, f0, f1
	  fadds     f27, f2, f0
	  bl        0xE49A4
	  xoris     r0, r3, 0x8000
	  lfs       f0, 0x1F0(r1)
	  stw       r0, 0x21C(r1)
	  fmr       f1, f29
	  lfd       f6, -0x5BC8(r2)
	  fmr       f2, f28
	  stw       r30, 0x218(r1)
	  lfs       f4, -0x5BD4(r2)
	  lfd       f5, 0x218(r1)
	  fmr       f3, f27
	  stfs      f0, 0x1D8(r1)
	  addi      r6, r1, 0x1D8
	  fsubs     f6, f5, f6
	  lfs       f0, 0x1F4(r1)
	  lfs       f5, -0x5C08(r2)
	  addi      r5, r31, 0x358
	  fdivs     f6, f6, f4
	  stfs      f0, 0x1DC(r1)
	  li        r4, 0
	  lfs       f4, -0x5C0C(r2)
	  lfs       f0, 0x1F8(r1)
	  fmuls     f6, f5, f6
	  stfs      f0, 0x1E0(r1)
	  lfs       f5, -0x5BD0(r2)
	  lwz       r3, 0x468(r31)
	  fsubs     f0, f6, f4
	  fmuls     f0, f5, f0
	  fmuls     f0, f31, f0
	  fmuls     f0, f30, f0
	  fadds     f4, f31, f0
	  bl        -0xD550
	  lwz       r3, 0x468(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x468(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x1E4
	  bl        -0x16924
	  addi      r3, r31, 0x358
	  lwz       r12, 0x358(r31)
	  addi      r4, r1, 0x1E4
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x1E4(r1)
	  lwz       r0, 0x1E8(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x1EC(r1)
	  stw       r0, 0x9C(r31)
	  lwz       r0, 0x26C(r1)
	  lfd       f31, 0x260(r1)
	  lfd       f30, 0x258(r1)
	  lfd       f29, 0x250(r1)
	  lfd       f28, 0x248(r1)
	  lfd       f27, 0x240(r1)
	  lwz       r31, 0x23C(r1)
	  lwz       r30, 0x238(r1)
	  addi      r1, r1, 0x268
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801337D8
 * Size:	00051C
 */
void TaiMizinkoComingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r5, r13, 0x1328
	  stw       r0, 0x4(r1)
	  subi      r6, r13, 0x1324
	  stwu      r1, -0x2B0(r1)
	  stfd      f31, 0x2A8(r1)
	  addi      r3, r1, 0x18C
	  stfd      f30, 0x2A0(r1)
	  stfd      f29, 0x298(r1)
	  stfd      f28, 0x290(r1)
	  stfd      f27, 0x288(r1)
	  stw       r31, 0x284(r1)
	  addi      r31, r4, 0
	  subi      r4, r13, 0x132C
	  stw       r30, 0x280(r1)
	  bl        -0xFC6F8
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x18C
	  addi      r5, r1, 0x190
	  addi      r6, r1, 0x194
	  bl        -0xD619C
	  addi      r3, r1, 0x180
	  subi      r4, r13, 0x1338
	  subi      r5, r13, 0x1334
	  subi      r6, r13, 0x1330
	  bl        -0xFC720
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x180
	  addi      r5, r1, 0x184
	  addi      r6, r1, 0x188
	  bl        -0xD61C4
	  mr        r3, r31
	  lwz       r4, -0x9D4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r0, -0x9C8(r13)
	  lwz       r12, 0x1CC(r12)
	  lwz       r5, -0x9A8(r13)
	  or        r0, r4, r0
	  lwz       r4, -0x9D0(r13)
	  mtlr      r12
	  or        r0, r5, r0
	  or        r4, r4, r0
	  blrl
	  lfs       f0, 0x388(r31)
	  addi      r3, r1, 0x248
	  stfs      f0, 0x254(r1)
	  lfs       f0, 0x38C(r31)
	  stfs      f0, 0x258(r1)
	  lfs       f0, 0x390(r31)
	  stfs      f0, 0x25C(r1)
	  lwz       r4, 0x2C8(r31)
	  addi      r4, r4, 0x10
	  bl        -0x16A28
	  addi      r3, r1, 0x23C
	  bl        -0x16A5C
	  lfs       f1, 0x248(r1)
	  addi      r3, r1, 0x230
	  lfs       f0, 0x254(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x23C(r1)
	  lfs       f1, 0x24C(r1)
	  lfs       f0, 0x258(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x240(r1)
	  lfs       f1, 0x250(r1)
	  lfs       f0, 0x25C(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x244(r1)
	  bl        -0x16A94
	  lfs       f1, -0x5C10(r2)
	  addi      r3, r1, 0x20C
	  lfs       f2, -0x5C08(r2)
	  fmr       f3, f1
	  bl        -0x16A20
	  lfs       f0, 0x210(r1)
	  addi      r3, r1, 0x230
	  lfs       f2, 0x244(r1)
	  lfs       f3, 0x214(r1)
	  lfs       f1, 0x240(r1)
	  fmuls     f5, f0, f2
	  lfs       f6, 0x23C(r1)
	  fmuls     f4, f3, f1
	  lfs       f7, 0x20C(r1)
	  fmuls     f0, f0, f6
	  fmuls     f1, f7, f1
	  fsubs     f4, f5, f4
	  fmuls     f3, f3, f6
	  fmuls     f2, f7, f2
	  fsubs     f0, f1, f0
	  stfs      f4, 0x230(r1)
	  fsubs     f1, f3, f2
	  stfs      f1, 0x234(r1)
	  stfs      f0, 0x238(r1)
	  bl        -0x16934
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x198
	  lfs       f1, -0x1310(r13)
	  lfs       f0, -0x130C(r13)
	  stfs      f1, 0x230(r1)
	  stfs      f0, 0x234(r1)
	  lfs       f0, -0x1308(r13)
	  stfs      f0, 0x238(r1)

	.loc_0x198:
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0x33
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x114AC
	  lfs       f0, 0x230(r1)
	  addi      r3, r31, 0x358
	  addi      r4, r1, 0x254
	  fmuls     f0, f0, f1
	  stfs      f0, 0x230(r1)
	  lfs       f0, 0x234(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x234(r1)
	  lfs       f0, 0x238(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x238(r1)
	  lfs       f0, 0x254(r1)
	  lfs       f1, 0x230(r1)
	  fadds     f0, f0, f1
	  stfs      f0, 0x254(r1)
	  lfs       f0, 0x258(r1)
	  lfs       f2, 0x234(r1)
	  fadds     f0, f0, f2
	  stfs      f0, 0x258(r1)
	  lfs       f0, 0x25C(r1)
	  lfs       f3, 0x238(r1)
	  fadds     f0, f0, f3
	  stfs      f0, 0x25C(r1)
	  lfs       f0, 0x248(r1)
	  fadds     f0, f0, f1
	  stfs      f0, 0x248(r1)
	  lfs       f0, 0x24C(r1)
	  fadds     f0, f0, f2
	  stfs      f0, 0x24C(r1)
	  lfs       f0, 0x250(r1)
	  fadds     f0, f0, f3
	  stfs      f0, 0x250(r1)
	  lwz       r12, 0x358(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x224
	  bl        -0x16BC4
	  lfs       f1, 0x248(r1)
	  addi      r3, r1, 0x224
	  lfs       f0, 0x254(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x224(r1)
	  lfs       f1, 0x24C(r1)
	  lfs       f0, 0x258(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x228(r1)
	  lfs       f1, 0x250(r1)
	  lfs       f0, 0x25C(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x22C(r1)
	  bl        -0x16A38
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x29C
	  lfs       f1, -0x1304(r13)
	  lfs       f0, -0x1300(r13)
	  stfs      f1, 0x224(r1)
	  stfs      f0, 0x228(r1)
	  lfs       f0, -0x12FC(r13)
	  stfs      f0, 0x22C(r1)

	.loc_0x29C:
	  lfs       f1, 0x224(r1)
	  lfs       f2, 0x22C(r1)
	  bl        -0x15C74
	  stfs      f1, 0xA0(r31)
	  li        r4, 0x3
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x115C0
	  lfs       f0, 0x224(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x224(r1)
	  lfs       f0, 0x228(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x228(r1)
	  lfs       f0, 0x22C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x22C(r1)
	  lwz       r3, 0x2C4(r31)
	  lfs       f1, 0x258(r1)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x74(r3)
	  lfs       f29, 0xE4(r3)
	  fadds     f28, f1, f0
	  bl        0xE4594
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C4(r31)
	  stw       r0, 0x27C(r1)
	  lis       r30, 0x4330
	  lwz       r3, 0x84(r3)
	  stw       r30, 0x278(r1)
	  lwz       r3, 0x4(r3)
	  lfd       f1, -0x5BC8(r2)
	  lfd       f0, 0x278(r1)
	  lwz       r3, 0x0(r3)
	  fsubs     f3, f0, f1
	  lfs       f1, -0x5BD4(r2)
	  lfs       f2, -0x5C08(r2)
	  lfs       f0, -0x5C0C(r2)
	  fdivs     f3, f3, f1
	  lfs       f1, -0x5BD0(r2)
	  lfs       f31, 0xEC(r3)
	  lfs       f30, 0xE8(r3)
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f28, f0
	  fmuls     f0, f29, f0
	  fadds     f29, f28, f0
	  bl        0xE4530
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x5BC8(r2)
	  stw       r0, 0x274(r1)
	  lfs       f3, -0x5BD4(r2)
	  stw       r30, 0x270(r1)
	  lfs       f2, -0x5C08(r2)
	  lfd       f1, 0x270(r1)
	  lfs       f0, -0x5C0C(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x5BD0(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f30, f0
	  fmuls     f0, f31, f0
	  fadds     f28, f30, f0
	  bl        0xE44E8
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C4(r31)
	  stw       r0, 0x26C(r1)
	  lwz       r3, 0x84(r3)
	  stw       r30, 0x268(r1)
	  lwz       r3, 0x4(r3)
	  lfd       f1, -0x5BC8(r2)
	  lfd       f0, 0x268(r1)
	  lwz       r3, 0x0(r3)
	  fsubs     f3, f0, f1
	  lfs       f2, -0x5BD4(r2)
	  lfs       f1, -0x5BD0(r2)
	  lfs       f0, -0x1CA4(r13)
	  fdivs     f4, f3, f2
	  lfs       f3, -0x5C08(r2)
	  lfs       f2, -0x5C10(r2)
	  lfs       f30, 0xF4(r3)
	  lfs       f31, 0xF0(r3)
	  fmuls     f0, f1, f0
	  fmuls     f1, f3, f4
	  fsubs     f0, f0, f2
	  fmuls     f0, f0, f1
	  fadds     f27, f2, f0
	  bl        0xE4488
	  xoris     r0, r3, 0x8000
	  lfs       f0, 0x224(r1)
	  stw       r0, 0x264(r1)
	  fmr       f1, f29
	  lfd       f6, -0x5BC8(r2)
	  fmr       f2, f28
	  stw       r30, 0x260(r1)
	  lfs       f4, -0x5BD4(r2)
	  lfd       f5, 0x260(r1)
	  fmr       f3, f27
	  stfs      f0, 0x200(r1)
	  addi      r6, r1, 0x200
	  fsubs     f6, f5, f6
	  lfs       f0, 0x228(r1)
	  lfs       f5, -0x5C08(r2)
	  addi      r5, r31, 0x358
	  fdivs     f6, f6, f4
	  stfs      f0, 0x204(r1)
	  li        r4, 0
	  lfs       f4, -0x5C0C(r2)
	  lfs       f0, 0x22C(r1)
	  fmuls     f6, f5, f6
	  stfs      f0, 0x208(r1)
	  lfs       f5, -0x5BD0(r2)
	  lwz       r3, 0x468(r31)
	  fsubs     f0, f6, f4
	  fmuls     f0, f5, f0
	  fmuls     f0, f31, f0
	  fmuls     f0, f30, f0
	  fadds     f4, f31, f0
	  bl        -0xDA6C
	  lwz       r3, 0x468(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x468(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x218
	  bl        -0x16E40
	  addi      r3, r31, 0x358
	  lwz       r12, 0x358(r31)
	  addi      r4, r1, 0x218
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x218(r1)
	  lwz       r0, 0x21C(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x220(r1)
	  stw       r0, 0x9C(r31)
	  lwz       r0, 0x2B4(r1)
	  lfd       f31, 0x2A8(r1)
	  lfd       f30, 0x2A0(r1)
	  lfd       f29, 0x298(r1)
	  lfd       f28, 0x290(r1)
	  lfd       f27, 0x288(r1)
	  lwz       r31, 0x284(r1)
	  lwz       r30, 0x280(r1)
	  addi      r1, r1, 0x2B0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80133CF4
 * Size:	000104
 */
bool TaiMizinkoDropWaterAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  mr        r30, r4
	  lwz       r0, -0x99C(r13)
	  lwz       r3, 0x414(r4)
	  and.      r0, r3, r0
	  beq-      .loc_0xE8
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0x6
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  bne-      .loc_0x50
	  li        r3, 0
	  b         .loc_0xEC

	.loc_0x50:
	  lfs       f0, 0x94(r30)
	  mr        r3, r31
	  addi      r4, r1, 0x40
	  stfs      f0, 0x40(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x48(r1)
	  lwz       r5, 0x2C4(r30)
	  lfs       f1, 0x44(r1)
	  lwz       r5, 0x84(r5)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f0, 0xC8(r5)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x44(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x420(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xD4
	  beq-      .loc_0xD4
	  bl        -0x4FA50
	  li        r0, 0
	  stw       r0, 0x420(r30)

	.loc_0xD4:
	  stw       r31, 0x420(r30)
	  lwz       r3, 0x420(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xE8
	  bl        -0x4FA7C

	.loc_0xE8:
	  li        r3, 0

	.loc_0xEC:
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
 * Address:	80133DF8
 * Size:	0000A8
 */
void TaiMizinkoWaitingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r5, r13, 0x1328
	  stw       r0, 0x4(r1)
	  subi      r6, r13, 0x1324
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  addi      r3, r1, 0x1C
	  subi      r4, r13, 0x132C
	  bl        -0xFCD00
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x1C
	  addi      r5, r1, 0x20
	  addi      r6, r1, 0x24
	  bl        -0xD67A4
	  addi      r3, r1, 0x10
	  subi      r4, r13, 0x1338
	  subi      r5, r13, 0x1334
	  subi      r6, r13, 0x1330
	  bl        -0xFCD28
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x10
	  addi      r5, r1, 0x14
	  addi      r6, r1, 0x18
	  bl        -0xD67CC
	  mr        r3, r31
	  lwz       r4, -0x9D4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r0, -0x9C8(r13)
	  lwz       r12, 0x1D0(r12)
	  lwz       r5, -0x9A8(r13)
	  or        r0, r4, r0
	  lwz       r4, -0x9D0(r13)
	  mtlr      r12
	  or        r0, r5, r0
	  or        r4, r4, r0
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
 * Address:	80133EA0
 * Size:	000178
 */
void TaiMizinkoFlyingAwayAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r5, r13, 0x1328
	  stw       r0, 0x4(r1)
	  subi      r6, r13, 0x1324
	  stwu      r1, -0xA0(r1)
	  stw       r31, 0x9C(r1)
	  mr        r31, r4
	  addi      r3, r1, 0x64
	  lwz       r0, 0xC8(r4)
	  subi      r4, r13, 0x132C
	  ori       r0, r0, 0x40
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,31,29
	  stw       r0, 0xC8(r31)
	  bl        -0xFCDC0
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x64
	  addi      r5, r1, 0x68
	  addi      r6, r1, 0x6C
	  bl        -0xD6864
	  addi      r3, r1, 0x58
	  subi      r4, r13, 0x1338
	  subi      r5, r13, 0x1334
	  subi      r6, r13, 0x1330
	  bl        -0xFCDE8
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x58
	  addi      r5, r1, 0x5C
	  addi      r6, r1, 0x60
	  bl        -0xD688C
	  mr        r3, r31
	  lwz       r4, -0x9D4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r0, -0x9C8(r13)
	  lwz       r12, 0x1D0(r12)
	  or        r4, r4, r0
	  mtlr      r12
	  blrl
	  addi      r4, r31, 0x94
	  addi      r3, r1, 0x70
	  bl        -0x170C4
	  lwz       r12, 0x358(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0x358
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2C4(r31)
	  addi      r3, r1, 0x88
	  lfs       f1, -0x5C10(r2)
	  lwz       r4, 0x84(r4)
	  fmr       f3, f1
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f2, 0xD0(r4)
	  bl        -0x170A4
	  addi      r3, r31, 0x368
	  lwz       r12, 0x368(r31)
	  addi      r4, r1, 0x88
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2C4(r31)
	  addi      r3, r1, 0x7C
	  lfs       f1, -0x5C10(r2)
	  lwz       r4, 0x84(r4)
	  fmr       f3, f1
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f2, 0xD4(r4)
	  bl        -0x170E0
	  addi      r3, r31, 0x378
	  lwz       r12, 0x378(r31)
	  addi      r4, r1, 0x7C
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x460(r31)
	  addi      r5, r31, 0x358
	  addi      r6, r31, 0x368
	  addi      r7, r31, 0x378
	  li        r4, 0
	  bl        -0xE0A8
	  lwz       r3, 0x460(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xA4(r1)
	  lwz       r31, 0x9C(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}
