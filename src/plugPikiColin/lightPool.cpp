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
 * Address:	80073164
 * Size:	00016C
 */
LightPool::LightPool()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x738C
	  subi      r4, r13, 0x658C
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lis       r3, 0x8022
	  stw       r0, 0x0(r30)
	  addi      r0, r3, 0x737C
	  addi      r3, r30, 0
	  stw       r0, 0x0(r30)
	  stw       r31, 0x10(r30)
	  stw       r31, 0xC(r30)
	  stw       r31, 0x8(r30)
	  bl        -0x4E2D8
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  subi      r4, r13, 0x658C
	  bl        -0x32A88
	  lis       r3, 0x802B
	  subi      r0, r3, 0x603C
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0x20
	  bl        -0x49790
	  addi      r3, r30, 0x2F4
	  bl        -0x3001C
	  lfs       f0, -0x7788(r2)
	  stfs      f0, 0x658(r30)
	  stfs      f0, 0x654(r30)
	  stfs      f0, 0x650(r30)
	  stw       r31, 0x64C(r30)
	  bl        0x1A4E78
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7770(r2)
	  stw       r0, 0x14(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7780(r2)
	  li        r6, 0x1
	  stw       r0, 0x10(r1)
	  lfs       f1, -0x7784(r2)
	  li        r5, 0xFF
	  lfd       f3, 0x10(r1)
	  li        r4, 0x40
	  lfs       f0, -0x777C(r2)
	  fsubs     f3, f3, f4
	  li        r0, 0x80
	  addi      r3, r30, 0
	  fdivs     f2, f3, f2
	  fmuls     f2, f1, f2
	  fmuls     f0, f0, f2
	  stfs      f0, 0x65C(r30)
	  lfs       f0, -0x65B0(r13)
	  stfs      f0, 0x458(r30)
	  lfs       f0, -0x65AC(r13)
	  stfs      f0, 0x45C(r30)
	  lfs       f0, -0x65A8(r13)
	  stfs      f0, 0x460(r30)
	  lfs       f0, -0x65A4(r13)
	  stfs      f0, 0x464(r30)
	  lfs       f0, -0x65A0(r13)
	  stfs      f0, 0x468(r30)
	  lfs       f0, -0x659C(r13)
	  stfs      f0, 0x46C(r30)
	  lfs       f0, -0x6598(r13)
	  stfs      f0, 0x614(r30)
	  lfs       f0, -0x6594(r13)
	  stfs      f0, 0x618(r30)
	  lfs       f0, -0x6590(r13)
	  stfs      f0, 0x61C(r30)
	  lfs       f0, -0x7778(r2)
	  stfs      f0, 0x4C0(r30)
	  stfs      f1, 0x4C4(r30)
	  lfs       f0, -0x7774(r2)
	  stfs      f0, 0x4C8(r30)
	  stb       r6, 0x66C(r30)
	  stb       r5, 0x660(r30)
	  stb       r5, 0x661(r30)
	  stb       r4, 0x662(r30)
	  stb       r0, 0x663(r30)
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
 * Address:	800732D0
 * Size:	0005F8
 */
void LightPool::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x300(r1)
	  stfd      f31, 0x2F8(r1)
	  stfd      f30, 0x2F0(r1)
	  stfd      f29, 0x2E8(r1)
	  stfd      f28, 0x2E0(r1)
	  stfd      f27, 0x2D8(r1)
	  stfd      f26, 0x2D0(r1)
	  stmw      r27, 0x2BC(r1)
	  addi      r28, r4, 0
	  addi      r27, r3, 0
	  mr        r3, r28
	  addi      r31, r27, 0x2F4
	  lwz       r12, 0x3B4(r28)
	  lwz       r4, 0x2E4(r4)
	  lwz       r12, 0x74(r12)
	  addi      r4, r4, 0x1E0
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  li        r4, 0x3
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r28, 0
	  lwz       r12, 0x3B4(r28)
	  mr        r30, r0
	  li        r4, 0
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r0, r3
	  lwz       r4, 0x664(r27)
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  mr        r29, r0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0xFF
	  stb       r3, 0x220(r1)
	  li        r0, 0x40
	  addi      r4, r1, 0x220
	  stb       r3, 0x221(r1)
	  mr        r3, r28
	  li        r5, 0x1
	  stb       r0, 0x222(r1)
	  stb       r0, 0x223(r1)
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  addi      r4, r27, 0x660
	  li        r5, 0x1
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0x164(r31)
	  lfs       f2, 0x170(r31)
	  lfs       f1, 0x168(r31)
	  lfs       f0, 0x174(r31)
	  fsubs     f31, f3, f2
	  lfs       f2, 0x16C(r31)
	  fsubs     f30, f1, f0
	  lfs       f0, 0x178(r31)
	  fmuls     f1, f31, f31
	  fsubs     f29, f2, f0
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x657E4
	  lfs       f0, -0x7788(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x170
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x170:
	  lfs       f3, 0x164(r31)
	  lfs       f2, 0x170(r31)
	  lfs       f1, 0x168(r31)
	  lfs       f0, 0x174(r31)
	  fsubs     f28, f3, f2
	  lfs       f2, 0x16C(r31)
	  fsubs     f27, f1, f0
	  lfs       f0, 0x178(r31)
	  fmuls     f1, f28, f28
	  fsubs     f26, f2, f0
	  lfs       f3, -0x7768(r2)
	  fmuls     f0, f27, f27
	  fmuls     f2, f26, f26
	  fmuls     f31, f31, f3
	  fadds     f0, f1, f0
	  fmuls     f30, f30, f3
	  fmuls     f29, f29, f3
	  fadds     f1, f2, f0
	  bl        -0x65848
	  lfs       f0, -0x7788(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1D4
	  fdivs     f28, f28, f1
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1

	.loc_0x1D4:
	  lwz       r3, 0x2E4(r28)
	  lfsu      f8, 0x194(r3)
	  lfs       f2, -0x7764(r2)
	  lfs       f5, 0x8(r3)
	  fmuls     f7, f26, f8
	  lfs       f9, 0x4(r3)
	  lfs       f0, 0x1CC(r31)
	  fmuls     f4, f27, f5
	  lfs       f1, -0x7788(r2)
	  fmuls     f3, f26, f9
	  stfs      f1, 0x22C(r1)
	  fmuls     f6, f28, f5
	  stfs      f1, 0x228(r1)
	  fsubs     f5, f4, f3
	  fmuls     f4, f2, f0
	  stfs      f1, 0x224(r1)
	  fsubs     f0, f7, f6
	  fmuls     f2, f28, f9
	  stfs      f1, 0x238(r1)
	  fmuls     f6, f0, f4
	  stfs      f1, 0x234(r1)
	  fmuls     f0, f27, f8
	  fmuls     f5, f5, f4
	  stfs      f1, 0x230(r1)
	  fsubs     f0, f2, f0
	  stfs      f1, 0x244(r1)
	  fneg      f3, f6
	  fadds     f9, f5, f31
	  stfs      f1, 0x240(r1)
	  fmuls     f7, f0, f4
	  stfs      f1, 0x23C(r1)
	  fadds     f11, f6, f30
	  fneg      f2, f5
	  stfs      f1, 0x250(r1)
	  fneg      f4, f7
	  stfs      f1, 0x24C(r1)
	  fadds     f13, f7, f29
	  fadds     f8, f3, f30
	  stfs      f1, 0x248(r1)
	  fadds     f0, f4, f29
	  stfs      f1, 0x25C(r1)
	  stfs      f1, 0x258(r1)
	  stfs      f1, 0x254(r1)
	  stfs      f1, 0x268(r1)
	  stfs      f1, 0x264(r1)
	  stfs      f1, 0x260(r1)
	  lfs       f10, 0x164(r31)
	  lfs       f12, 0x168(r31)
	  fadds     f9, f10, f9
	  lfs       f27, 0x16C(r31)
	  fadds     f11, f12, f11
	  fadds     f10, f27, f13
	  stfs      f9, 0x224(r1)
	  stfs      f11, 0x228(r1)
	  stfs      f10, 0x22C(r1)
	  stfs      f2, 0x164(r1)
	  lfs       f9, 0x164(r1)
	  stfs      f1, 0x26C(r1)
	  fadds     f9, f9, f31
	  stfs      f1, 0x270(r1)
	  stfs      f9, 0x158(r1)
	  lfs       f9, 0x158(r1)
	  stfs      f9, 0x1E4(r1)
	  stfs      f8, 0x1E8(r1)
	  stfs      f0, 0x1EC(r1)
	  lfs       f8, 0x164(r31)
	  lfs       f0, 0x1E4(r1)
	  fadds     f0, f8, f0
	  stfs      f0, 0x14C(r1)
	  lfs       f0, 0x14C(r1)
	  stfs      f0, 0x1F0(r1)
	  lfs       f8, 0x168(r31)
	  lfs       f0, 0x1E8(r1)
	  fadds     f0, f8, f0
	  stfs      f0, 0x1F4(r1)
	  lfs       f8, 0x16C(r31)
	  lfs       f0, 0x1EC(r1)
	  fadds     f0, f8, f0
	  stfs      f0, 0x1F8(r1)
	  lwz       r0, 0x1F0(r1)
	  lwz       r3, 0x1F4(r1)
	  stw       r0, 0x230(r1)
	  lwz       r0, 0x1F8(r1)
	  stw       r3, 0x234(r1)
	  stw       r0, 0x238(r1)
	  lfs       f0, -0x7784(r2)
	  fneg      f11, f31
	  stfs      f2, 0x1B4(r1)
	  fneg      f9, f29
	  fneg      f10, f30
	  stfs      f0, 0x274(r1)
	  fadds     f8, f5, f11
	  mr        r3, r28
	  stfs      f1, 0x278(r1)
	  fadds     f5, f6, f10
	  addi      r4, r1, 0x224
	  stfs      f11, 0x13C(r1)
	  fadds     f2, f7, f9
	  addi      r6, r1, 0x26C
	  stfs      f3, 0x1B8(r1)
	  li        r5, 0
	  li        r7, 0x4
	  stfs      f4, 0x1BC(r1)
	  lfs       f4, 0x1B4(r1)
	  lfs       f3, 0x13C(r1)
	  fadds     f3, f4, f3
	  stfs      f3, 0x130(r1)
	  lfs       f3, 0x130(r1)
	  stfs      f3, 0x1C0(r1)
	  lfs       f3, 0x1B8(r1)
	  fadds     f3, f3, f10
	  stfs      f3, 0x1C4(r1)
	  lfs       f3, 0x1BC(r1)
	  fadds     f3, f3, f9
	  stfs      f3, 0x1C8(r1)
	  lfs       f4, 0x170(r31)
	  lfs       f3, 0x1C0(r1)
	  fadds     f3, f4, f3
	  stfs      f3, 0x124(r1)
	  lfs       f3, 0x124(r1)
	  stfs      f3, 0x1CC(r1)
	  lfs       f4, 0x174(r31)
	  lfs       f3, 0x1C4(r1)
	  fadds     f3, f4, f3
	  stfs      f3, 0x1D0(r1)
	  lfs       f4, 0x178(r31)
	  lfs       f3, 0x1C8(r1)
	  fadds     f4, f4, f3
	  stfs      f8, 0x10C(r1)
	  stfs      f0, 0x27C(r1)
	  lfs       f3, 0x10C(r1)
	  stfs      f4, 0x1D4(r1)
	  lwz       r0, 0x1CC(r1)
	  lwz       r8, 0x1D0(r1)
	  stw       r0, 0x23C(r1)
	  lwz       r0, 0x1D4(r1)
	  stw       r8, 0x240(r1)
	  stw       r0, 0x244(r1)
	  stfs      f0, 0x280(r1)
	  stfs      f3, 0x190(r1)
	  stfs      f5, 0x194(r1)
	  stfs      f2, 0x198(r1)
	  lfs       f3, 0x170(r31)
	  lfs       f2, 0x190(r1)
	  fadds     f2, f3, f2
	  stfs      f2, 0x100(r1)
	  lfs       f2, 0x100(r1)
	  stfs      f2, 0x19C(r1)
	  lfs       f3, 0x174(r31)
	  lfs       f2, 0x194(r1)
	  fadds     f2, f3, f2
	  stfs      f2, 0x1A0(r1)
	  lfs       f3, 0x178(r31)
	  lfs       f2, 0x198(r1)
	  fadds     f2, f3, f2
	  stfs      f1, 0x284(r1)
	  stfs      f0, 0x288(r1)
	  stfs      f2, 0x1A4(r1)
	  lwz       r0, 0x19C(r1)
	  lwz       r8, 0x1A0(r1)
	  stw       r0, 0x248(r1)
	  lwz       r0, 0x1A4(r1)
	  stw       r8, 0x24C(r1)
	  stw       r0, 0x250(r1)
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r4, 0x2E4(r28)
	  lwz       r12, 0x3B4(r28)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r4, 0x668(r27)
	  lwz       r12, 0x3B4(r28)
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  li        r4, 0x4
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0xFF
	  stb       r0, 0x180(r1)
	  addi      r4, r1, 0x180
	  addi      r3, r28, 0
	  stb       r0, 0x181(r1)
	  li        r5, 0x1
	  stb       r0, 0x182(r1)
	  stb       r0, 0x183(r1)
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  li        r4, 0x1
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x538
	  mr        r3, r28
	  lwz       r4, 0x2E4(r28)
	  lwz       r12, 0x3B4(r28)
	  addi      r5, r31, 0x164
	  lfs       f1, -0x7760(r2)
	  lwz       r12, 0x8C(r12)
	  mtlr      r12
	  blrl

	.loc_0x538:
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  addi      r4, r29, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  mr        r4, r30
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  li        r4, 0x1
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x66C(r27)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x5CC
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  li        r4, 0
	  lwz       r12, 0xB8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  bl        -0x32290
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  li        r4, 0x1
	  lwz       r12, 0xB8(r12)
	  mtlr      r12
	  blrl

	.loc_0x5CC:
	  lmw       r27, 0x2BC(r1)
	  lwz       r0, 0x304(r1)
	  lfd       f31, 0x2F8(r1)
	  lfd       f30, 0x2F0(r1)
	  lfd       f29, 0x2E8(r1)
	  lfd       f28, 0x2E0(r1)
	  lfd       f27, 0x2D8(r1)
	  lfd       f26, 0x2D0(r1)
	  addi      r1, r1, 0x300
	  mtlr      r0
	  blr
	*/
}
