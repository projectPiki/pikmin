#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
zen::EffectMgr2D::~EffectMgr2D()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801E98C0
 * Size:	00027C
 */
zen::EffectMgr2D::EffectMgr2D(int, int, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stfd      f31, 0x58(r1)
  stmw      r25, 0x3C(r1)
  addi      r29, r5, 0
  addi      r30, r6, 0
  addi      r28, r4, 0
  li        r31, 0
  stw       r3, 0x8(r1)
  lis       r3, 0x802D
  addi      r11, r3, 0x68DC
  lwz       r3, 0x8(r1)
  stw       r11, 0x4(r3)
  addi      r27, r3, 0x10
  addi      r0, r3, 0x4
  stw       r0, 0xC(r3)
  addi      r4, r27, 0x34
  addi      r10, r27, 0x4
  stw       r0, 0x8(r3)
  addi      r26, r27, 0x14
  addi      r25, r27, 0x24
  stw       r0, 0x0(r3)
  addi      r9, r4, 0x4
  addi      r0, r4, 0x14
  lwz       r12, 0x0(r3)
  addi      r8, r27, 0x64
  stw       r12, 0x8(r12)
  lwz       r5, 0x0(r3)
  addi      r3, r3, 0x17C
  stw       r12, 0x4(r5)
  stw       r11, 0x4(r27)
  stw       r10, 0xC(r27)
  stw       r10, 0x8(r27)
  stw       r10, 0x0(r27)
  lwz       r6, 0x0(r27)
  stw       r6, 0x8(r6)
  lwz       r5, 0x0(r27)
  stw       r6, 0x4(r5)
  stw       r11, 0x14(r27)
  stw       r26, 0x1C(r27)
  stw       r26, 0x18(r27)
  stw       r26, 0x10(r27)
  lwz       r6, 0x10(r27)
  stw       r6, 0x8(r6)
  lwz       r5, 0x10(r27)
  stw       r6, 0x4(r5)
  stw       r11, 0x24(r27)
  stw       r25, 0x2C(r27)
  stw       r25, 0x28(r27)
  stw       r25, 0x20(r27)
  lwz       r6, 0x20(r27)
  stw       r6, 0x8(r6)
  lwz       r5, 0x20(r27)
  stw       r6, 0x4(r5)
  stw       r11, 0x38(r27)
  stw       r9, 0x40(r27)
  stw       r9, 0x3C(r27)
  stw       r9, 0x34(r27)
  lwz       r6, 0x34(r27)
  stw       r6, 0x8(r6)
  lwz       r5, 0x34(r27)
  stw       r6, 0x4(r5)
  stw       r11, 0x48(r27)
  stw       r0, 0x50(r27)
  stw       r0, 0x4C(r27)
  stw       r0, 0x44(r27)
  lwz       r6, 0x44(r27)
  stw       r6, 0x8(r6)
  lwz       r5, 0x44(r27)
  stw       r6, 0x4(r5)
  stw       r31, 0x54(r27)
  stw       r31, 0x58(r27)
  stw       r11, 0x64(r27)
  stw       r8, 0x6C(r27)
  stw       r8, 0x68(r27)
  stw       r8, 0x60(r27)
  lwz       r5, 0x60(r27)
  stw       r5, 0x8(r5)
  lwz       r4, 0x60(r27)
  stw       r5, 0x4(r4)
  stw       r31, 0x70(r27)
  stw       r31, 0x30(r27)
  stw       r31, 0x5C(r27)
  bl        -0x1A684C
  lfs       f1, -0x3FE8(r2)
  addi      r3, r27, 0
  addi      r4, r28, 0
  addi      r5, r29, 0
  addi      r6, r30, 0
  bl        -0x48928
  lis       r3, 0x802E
  addi      r30, r3, 0x6144
  li        r25, 0

.loc_0x178:
  li        r3, 0xC
  bl        -0x1A2A38
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0x1E4
  lwz       r4, 0x0(r30)
  li        r5, 0x1
  lwz       r28, 0x8(r30)
  lwz       r27, 0x4(r30)
  lwz       r3, 0x8(r1)
  bl        -0x48B3C
  stw       r3, 0x0(r29)
  addi      r4, r27, 0
  li        r5, 0x1
  lwz       r3, 0x2DEC(r13)
  bl        -0x1AA96C
  cmplwi    r28, 0
  stw       r3, 0x4(r29)
  beq-      .loc_0x1DC
  lwz       r3, 0x2DEC(r13)
  addi      r4, r28, 0
  li        r5, 0x1
  bl        -0x1AA988
  stw       r3, 0x8(r29)
  b         .loc_0x1E4

.loc_0x1DC:
  li        r0, 0
  stw       r0, 0x8(r29)

.loc_0x1E4:
  addi      r25, r25, 0x1
  lwz       r27, 0x8(r1)
  addi      r0, r31, 0xAC
  cmpwi     r25, 0x34
  stwx      r29, r27, r0
  addi      r30, r30, 0xC
  addi      r31, r31, 0x4
  blt+      .loc_0x178
  lfs       f1, -0x3FE4(r2)
  bl        0x32220
  fmr       f31, f1
  lfs       f1, -0x3FE4(r2)
  bl        0x32080
  lfs       f2, 0x26A0(r13)
  addi      r3, r27, 0x17C
  lfs       f0, 0x26A8(r13)
  addi      r4, r1, 0x28
  stfs      f2, 0x28(r1)
  fdivs     f2, f1, f31
  lfs       f3, -0x3FE0(r2)
  lfs       f4, 0x26A4(r13)
  addi      r5, r1, 0x1C
  stfs      f0, 0x1C(r1)
  lfs       f1, 0x26AC(r13)
  fmuls     f2, f3, f2
  stfs      f4, 0x2C(r1)
  lfs       f0, 0x26B0(r13)
  stfs      f1, 0x20(r1)
  stfs      f0, 0x24(r1)
  stfs      f2, 0x30(r1)
  bl        -0x1A6D78
  mr        r3, r27
  lmw       r25, 0x3C(r1)
  lwz       r0, 0x64(r1)
  lfd       f31, 0x58(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801E9B3C
 * Size:	00004C
 */
void zen::EffectMgr2D::create(unsigned long, Vector3f &, zen::CallBack1<zen::particleGenerator *> *, zen::CallBack2<zen::particleGenerator *, zen::particleMdl *> *)
{
/*
.loc_0x0:
  mflr      r0
  addi      r8, r6, 0
  stw       r0, 0x4(r1)
  rlwinm    r0,r4,2,0,29
  add       r4, r3, r0
  stwu      r1, -0x8(r1)
  addi      r0, r5, 0
  addi      r9, r7, 0
  lwz       r10, 0xAC(r4)
  mr        r7, r0
  addi      r3, r3, 0x10
  lwz       r4, 0x0(r10)
  lwz       r5, 0x4(r10)
  lwz       r6, 0x8(r10)
  bl        -0x488EC
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801E9B88
 * Size:	000024
 */
void zen::EffectMgr2D::update()
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0x10
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x4889C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801E9BAC
 * Size:	000128
 */
void zen::EffectMgr2D::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  mr        r31, r4
  stw       r30, 0x30(r1)
  mr        r30, r3
  lwz       r5, 0x30C(r4)
  lwz       r0, 0x310(r4)
  lis       r4, 0x4330
  xoris     r3, r5, 0x8000
  lfd       f5, -0x3FD0(r2)
  stw       r3, 0x2C(r1)
  xoris     r0, r0, 0x8000
  lfs       f2, -0x3FDC(r2)
  stw       r0, 0x24(r1)
  addi      r3, r30, 0x17C
  lfs       f3, -0x3FD8(r2)
  stw       r4, 0x28(r1)
  lfs       f4, -0x3FD4(r2)
  stw       r4, 0x20(r1)
  lfd       f1, 0x28(r1)
  lfd       f0, 0x20(r1)
  fsubs     f1, f1, f5
  fsubs     f0, f0, f5
  fdivs     f1, f1, f0
  bl        -0x1A6FC0
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r30, 0x17C
  lwz       r12, 0x6C(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lfs       f1, 0x348(r30)
  lwz       r12, 0x3B4(r31)
  addi      r4, r30, 0x3DC
  lfs       f2, 0x340(r30)
  lwz       r12, 0x3C(r12)
  lfs       f3, 0x34C(r30)
  mtlr      r12
  lfs       f4, 0x350(r30)
  lfs       f5, -0x3FD8(r2)
  blrl      
  lwz       r6, 0x310(r31)
  li        r0, 0
  lwz       r5, 0x30C(r31)
  addi      r4, r1, 0x10
  addi      r3, r31, 0
  stw       r0, 0x10(r1)
  stw       r0, 0x14(r1)
  stw       r5, 0x18(r1)
  stw       r6, 0x1C(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x50(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r4, 0x2E4(r31)
  lwz       r12, 0x3B4(r31)
  li        r5, 0
  addi      r4, r4, 0x1E0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  addi      r3, r30, 0x10
  addi      r4, r31, 0
  bl        -0x488AC
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801E9CD4
 * Size:	000024
 */
void zen::EffectMgr2D::killAll(bool)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0x10
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x487BC
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}
