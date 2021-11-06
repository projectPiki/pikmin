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
 * Size:	0000F0
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014D8CC
 * Size:	0005AC
 */
BossProp::BossProp()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802B
  stw       r0, 0x4(r1)
  subi      r0, r4, 0x6C8
  subi      r4, r13, 0x578
  stwu      r1, -0x200(r1)
  stw       r31, 0x1FC(r1)
  addi      r31, r3, 0
  stw       r30, 0x1F8(r1)
  stw       r29, 0x1F4(r1)
  stw       r28, 0x1F0(r1)
  li        r28, 0
  stw       r0, 0x54(r3)
  addi      r3, r1, 0x100
  stw       r28, 0x0(r31)
  bl        -0xFCE30
  lwz       r0, 0x100(r1)
  addi      r5, r1, 0x94
  addi      r4, r31, 0
  stw       r0, 0x94(r1)
  addi      r3, r31, 0x4
  bl        -0xEEEA0
  lis       r3, 0x802A
  addi      r30, r3, 0x6098
  stw       r30, 0xC(r31)
  addi      r3, r1, 0x108
  subi      r4, r13, 0x574
  lfs       f0, -0x5800(r2)
  stfs      f0, 0x10(r31)
  bl        -0xFCE68
  lwz       r0, 0x108(r1)
  addi      r5, r1, 0x90
  addi      r4, r31, 0
  stw       r0, 0x90(r1)
  addi      r3, r31, 0x14
  bl        -0xEEED8
  stw       r30, 0x1C(r31)
  addi      r3, r1, 0x110
  subi      r4, r13, 0x570
  lfs       f0, -0x5800(r2)
  stfs      f0, 0x20(r31)
  bl        -0xFCE98
  lwz       r0, 0x110(r1)
  addi      r5, r1, 0x8C
  addi      r4, r31, 0
  stw       r0, 0x8C(r1)
  addi      r3, r31, 0x24
  bl        -0xEEF08
  stw       r30, 0x2C(r31)
  addi      r3, r1, 0x118
  subi      r4, r13, 0x56C
  lfs       f0, -0x57FC(r2)
  stfs      f0, 0x30(r31)
  bl        -0xFCEC8
  lwz       r0, 0x118(r1)
  addi      r5, r1, 0x88
  addi      r4, r31, 0
  stw       r0, 0x88(r1)
  addi      r3, r31, 0x34
  bl        -0xEEF38
  stw       r30, 0x3C(r31)
  addi      r3, r1, 0x120
  subi      r4, r13, 0x568
  lfs       f0, -0x57F8(r2)
  stfs      f0, 0x40(r31)
  bl        -0xFCEF8
  lwz       r0, 0x120(r1)
  addi      r5, r1, 0x84
  addi      r4, r31, 0
  stw       r0, 0x84(r1)
  addi      r3, r31, 0x44
  bl        -0xEEF68
  stw       r30, 0x4C(r31)
  lis       r3, 0x802D
  subi      r0, r3, 0x15C8
  lfs       f0, -0x57F4(r2)
  addi      r5, r1, 0xF8
  addi      r3, r31, 0x5C
  stfs      f0, 0x50(r31)
  addi      r4, r31, 0x58
  stw       r0, 0x54(r31)
  stw       r28, 0x58(r31)
  lwz       r0, -0x564(r13)
  stw       r0, 0x128(r1)
  lwz       r0, 0x128(r1)
  stw       r0, 0xF8(r1)
  bl        -0xEEFA4
  stw       r30, 0x64(r31)
  addi      r5, r1, 0xF4
  addi      r3, r31, 0x6C
  lfs       f0, -0x57F0(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0x68(r31)
  lwz       r0, -0x560(r13)
  stw       r0, 0x130(r1)
  lwz       r0, 0x130(r1)
  stw       r0, 0xF4(r1)
  bl        -0xEEFD0
  stw       r30, 0x74(r31)
  addi      r5, r1, 0xF0
  addi      r3, r31, 0x7C
  lfs       f0, -0x57EC(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0x78(r31)
  lwz       r0, -0x55C(r13)
  stw       r0, 0x138(r1)
  lwz       r0, 0x138(r1)
  stw       r0, 0xF0(r1)
  bl        -0xEEFFC
  stw       r30, 0x84(r31)
  addi      r5, r1, 0xEC
  addi      r3, r31, 0x8C
  lfs       f0, -0x57EC(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0x88(r31)
  lwz       r0, -0x558(r13)
  stw       r0, 0x140(r1)
  lwz       r0, 0x140(r1)
  stw       r0, 0xEC(r1)
  bl        -0xEF028
  stw       r30, 0x94(r31)
  addi      r5, r1, 0xE8
  addi      r3, r31, 0x9C
  lfs       f0, -0x57E8(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0x98(r31)
  lwz       r0, -0x554(r13)
  stw       r0, 0x148(r1)
  lwz       r0, 0x148(r1)
  stw       r0, 0xE8(r1)
  bl        -0xEF054
  stw       r30, 0xA4(r31)
  addi      r5, r1, 0xE4
  addi      r3, r31, 0xAC
  lfs       f0, -0x57E4(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0xA8(r31)
  lwz       r0, -0x550(r13)
  stw       r0, 0x150(r1)
  lwz       r0, 0x150(r1)
  stw       r0, 0xE4(r1)
  bl        -0xEF080
  stw       r30, 0xB4(r31)
  addi      r5, r1, 0xE0
  addi      r3, r31, 0xBC
  lfs       f0, -0x57E0(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0xB8(r31)
  lwz       r0, -0x54C(r13)
  stw       r0, 0x158(r1)
  lwz       r0, 0x158(r1)
  stw       r0, 0xE0(r1)
  bl        -0xEF0AC
  stw       r30, 0xC4(r31)
  addi      r5, r1, 0xDC
  addi      r3, r31, 0xCC
  lfs       f0, -0x57DC(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0xC8(r31)
  lwz       r0, -0x548(r13)
  stw       r0, 0x160(r1)
  lwz       r0, 0x160(r1)
  stw       r0, 0xDC(r1)
  bl        -0xEF0D8
  stw       r30, 0xD4(r31)
  addi      r5, r1, 0xD8
  addi      r3, r31, 0xDC
  lfs       f0, -0x57E0(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0xD8(r31)
  lwz       r0, -0x544(r13)
  stw       r0, 0x168(r1)
  lwz       r0, 0x168(r1)
  stw       r0, 0xD8(r1)
  bl        -0xEF104
  stw       r30, 0xE4(r31)
  addi      r5, r1, 0xD4
  addi      r3, r31, 0xEC
  lfs       f0, -0x57E0(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0xE8(r31)
  lwz       r0, -0x540(r13)
  stw       r0, 0x170(r1)
  lwz       r0, 0x170(r1)
  stw       r0, 0xD4(r1)
  bl        -0xEF130
  stw       r30, 0xF4(r31)
  addi      r5, r1, 0xD0
  addi      r3, r31, 0xFC
  lfs       f0, -0x57D8(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0xF8(r31)
  lwz       r0, -0x53C(r13)
  stw       r0, 0x178(r1)
  lwz       r0, 0x178(r1)
  stw       r0, 0xD0(r1)
  bl        -0xEF15C
  stw       r30, 0x104(r31)
  addi      r5, r1, 0xCC
  addi      r3, r31, 0x10C
  lfs       f0, -0x57D4(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0x108(r31)
  lwz       r0, -0x538(r13)
  stw       r0, 0x180(r1)
  lwz       r0, 0x180(r1)
  stw       r0, 0xCC(r1)
  bl        -0xEF188
  stw       r30, 0x114(r31)
  addi      r5, r1, 0xC8
  addi      r3, r31, 0x11C
  lfs       f0, -0x57E0(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0x118(r31)
  lwz       r0, -0x534(r13)
  stw       r0, 0x188(r1)
  lwz       r0, 0x188(r1)
  stw       r0, 0xC8(r1)
  bl        -0xEF1B4
  stw       r30, 0x124(r31)
  addi      r5, r1, 0xC4
  addi      r3, r31, 0x12C
  lfs       f0, -0x57EC(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0x128(r31)
  lwz       r0, -0x530(r13)
  stw       r0, 0x190(r1)
  lwz       r0, 0x190(r1)
  stw       r0, 0xC4(r1)
  bl        -0xEF1E0
  stw       r30, 0x134(r31)
  addi      r5, r1, 0xC0
  addi      r3, r31, 0x13C
  lfs       f0, -0x57DC(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0x138(r31)
  lwz       r0, -0x52C(r13)
  stw       r0, 0x198(r1)
  lwz       r0, 0x198(r1)
  stw       r0, 0xC0(r1)
  bl        -0xEF20C
  stw       r30, 0x144(r31)
  addi      r5, r1, 0xBC
  addi      r3, r31, 0x14C
  lfs       f0, -0x57D0(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0x148(r31)
  lwz       r0, -0x528(r13)
  stw       r0, 0x1A0(r1)
  lwz       r0, 0x1A0(r1)
  stw       r0, 0xBC(r1)
  bl        -0xEF238
  stw       r30, 0x154(r31)
  addi      r5, r1, 0xB8
  addi      r3, r31, 0x15C
  lfs       f0, -0x57DC(r2)
  addi      r4, r31, 0x58
  stfs      f0, 0x158(r31)
  lwz       r0, -0x524(r13)
  stw       r0, 0x1A8(r1)
  lwz       r0, 0x1A8(r1)
  stw       r0, 0xB8(r1)
  bl        -0xEF264
  lis       r3, 0x802A
  addi      r29, r3, 0x60C4
  stw       r29, 0x164(r31)
  li        r30, 0x1
  addi      r5, r1, 0xB4
  stw       r30, 0x168(r31)
  addi      r3, r31, 0x16C
  addi      r4, r31, 0x58
  lwz       r0, -0x520(r13)
  stw       r0, 0x1B0(r1)
  lwz       r0, 0x1B0(r1)
  stw       r0, 0xB4(r1)
  bl        -0xEF298
  stw       r29, 0x174(r31)
  li        r28, 0xA
  addi      r5, r1, 0xB0
  stw       r28, 0x178(r31)
  addi      r3, r31, 0x17C
  addi      r4, r31, 0x58
  lwz       r0, -0x51C(r13)
  stw       r0, 0x1B8(r1)
  lwz       r0, 0x1B8(r1)
  stw       r0, 0xB0(r1)
  bl        -0xEF2C4
  stw       r29, 0x184(r31)
  li        r0, 0x14
  addi      r5, r1, 0xAC
  stw       r0, 0x188(r31)
  addi      r3, r31, 0x18C
  addi      r4, r31, 0x58
  lwz       r0, -0x518(r13)
  stw       r0, 0x1C0(r1)
  lwz       r0, 0x1C0(r1)
  stw       r0, 0xAC(r1)
  bl        -0xEF2F0
  stw       r29, 0x194(r31)
  li        r0, 0x1E
  addi      r5, r1, 0xA8
  stw       r0, 0x198(r31)
  addi      r3, r31, 0x19C
  addi      r4, r31, 0x58
  lwz       r0, -0x514(r13)
  stw       r0, 0x1C8(r1)
  lwz       r0, 0x1C8(r1)
  stw       r0, 0xA8(r1)
  bl        -0xEF31C
  stw       r29, 0x1A4(r31)
  addi      r5, r1, 0xA4
  addi      r3, r31, 0x1AC
  stw       r28, 0x1A8(r31)
  addi      r4, r31, 0x58
  lwz       r0, -0x510(r13)
  stw       r0, 0x1D0(r1)
  lwz       r0, 0x1D0(r1)
  stw       r0, 0xA4(r1)
  bl        -0xEF344
  stw       r29, 0x1B4(r31)
  li        r0, 0x32
  addi      r5, r1, 0xA0
  stw       r0, 0x1B8(r31)
  addi      r3, r31, 0x1BC
  addi      r4, r31, 0x58
  lwz       r0, -0x50C(r13)
  stw       r0, 0x1D8(r1)
  lwz       r0, 0x1D8(r1)
  stw       r0, 0xA0(r1)
  bl        -0xEF370
  stw       r29, 0x1C4(r31)
  li        r0, 0x64
  addi      r5, r1, 0x9C
  stw       r0, 0x1C8(r31)
  addi      r3, r31, 0x1CC
  addi      r4, r31, 0x58
  lwz       r0, -0x508(r13)
  stw       r0, 0x1E0(r1)
  lwz       r0, 0x1E0(r1)
  stw       r0, 0x9C(r1)
  bl        -0xEF39C
  stw       r29, 0x1D4(r31)
  li        r0, 0xC8
  addi      r5, r1, 0x98
  stw       r0, 0x1D8(r31)
  addi      r3, r31, 0x1DC
  addi      r4, r31, 0x58
  lwz       r0, -0x504(r13)
  stw       r0, 0x1E8(r1)
  lwz       r0, 0x1E8(r1)
  stw       r0, 0x98(r1)
  bl        -0xEF3C8
  stw       r29, 0x1E4(r31)
  mr        r3, r31
  stw       r30, 0x1E8(r31)
  lwz       r0, 0x204(r1)
  lwz       r31, 0x1FC(r1)
  lwz       r30, 0x1F8(r1)
  lwz       r29, 0x1F4(r1)
  lwz       r28, 0x1F0(r1)
  addi      r1, r1, 0x200
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014DE78
 * Size:	0000EC
 */
Boss::Boss(CreatureProp *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  bl        -0xC2FC0
  lis       r3, 0x802D
  subi      r0, r3, 0x179C
  stw       r0, 0x0(r29)
  addi      r3, r29, 0x31C
  lfs       f0, -0x57DC(r2)
  stfs      f0, 0x308(r29)
  stfs      f0, 0x304(r29)
  stfs      f0, 0x300(r29)
  stfs      f0, 0x314(r29)
  stfs      f0, 0x310(r29)
  stfs      f0, 0x30C(r29)
  bl        -0x10A06C
  lfs       f0, -0x57DC(r2)
  addi      r3, r29, 0x33C
  stfs      f0, 0x330(r29)
  stfs      f0, 0x32C(r29)
  stfs      f0, 0x328(r29)
  bl        -0x2E024
  lis       r3, 0x8009
  subi      r4, r3, 0x5808
  addi      r3, r29, 0x394
  li        r5, 0
  li        r6, 0xC
  li        r7, 0x3
  bl        0xC6B74
  li        r3, 0x28
  bl        -0x106F00
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0xA8
  addi      r4, r29, 0
  li        r5, 0x1
  bl        -0xAA250

.loc_0xA8:
  stw       r31, 0x2C(r29)
  li        r0, 0x1
  addi      r3, r29, 0x1B8
  stw       r0, 0x1FC(r29)
  addi      r4, r29, 0x394
  li        r5, 0x3
  lfs       f0, 0xF8(r30)
  stfs      f0, 0x214(r29)
  bl        -0x6A2C0
  mr        r3, r29
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
 * Address:	8014DF64
 * Size:	000114
 */
void Boss::initBoss(BirthInfo &, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  addi      r31, r5, 0
  stw       r30, 0x38(r1)
  addi      r30, r4, 0
  stw       r29, 0x34(r1)
  addi      r29, r3, 0
  bl        -0xC3384
  stw       r31, 0x6C(r29)
  li        r0, 0x1
  li        r4, 0
  lwz       r5, 0xC(r30)
  lwz       r3, 0x10(r30)
  stw       r5, 0x88(r29)
  stw       r3, 0x8C(r29)
  lwz       r3, 0x14(r30)
  stw       r3, 0x90(r29)
  lfs       f0, 0x8C(r29)
  stfs      f0, 0xA0(r29)
  stb       r0, 0x2B8(r29)
  stb       r0, 0x2B9(r29)
  stb       r0, 0x2BA(r29)
  stb       r0, 0x2BB(r29)
  stb       r4, 0x2BC(r29)
  stb       r4, 0x2BD(r29)
  stb       r4, 0x2BE(r29)
  stb       r4, 0x2BF(r29)
  lfs       f3, -0x57DC(r2)
  stfs      f3, 0x2C0(r29)
  lwz       r3, 0x224(r29)
  lfs       f0, 0xA8(r3)
  stfs      f0, 0x2C8(r29)
  stfs      f0, 0x2C4(r29)
  stfs      f3, 0x2D8(r29)
  stfs      f3, 0x2D4(r29)
  stfs      f3, 0x2D0(r29)
  stfs      f3, 0x2CC(r29)
  lwz       r3, 0x224(r29)
  lfs       f0, -0x57E8(r2)
  lfs       f1, 0x98(r3)
  lfs       f2, -0x57CC(r2)
  fdivs     f0, f1, f0
  fmuls     f0, f2, f0
  stfs      f0, 0x2DC(r29)
  stfs      f3, 0x2E0(r29)
  stw       r4, 0x2EC(r29)
  stw       r4, 0x2F0(r29)
  lwz       r3, 0x0(r30)
  lwz       r0, 0x4(r30)
  stw       r3, 0x300(r29)
  stw       r0, 0x304(r29)
  lwz       r0, 0x8(r30)
  stw       r0, 0x308(r29)
  stw       r4, 0x318(r29)
  lwz       r3, 0x0(r30)
  lwz       r0, 0x4(r30)
  stw       r3, 0x30C(r29)
  stw       r0, 0x310(r29)
  lwz       r0, 0x8(r30)
  stw       r0, 0x314(r29)
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
 * Address:	8014E078
 * Size:	000098
 */
void Boss::calcFlickPiki()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802B
  stw       r0, 0x4(r1)
  subi      r0, r4, 0xF68
  lis       r4, 0x802D
  stwu      r1, -0x50(r1)
  stw       r31, 0x4C(r1)
  addi      r31, r3, 0
  lis       r3, 0x802B
  stw       r0, 0x28(r1)
  subi      r0, r4, 0x1404
  lis       r4, 0x802B
  lfs       f0, -0x57C8(r2)
  stw       r0, 0x28(r1)
  subi      r0, r3, 0x3168
  stw       r31, 0x2C(r1)
  subi      r4, r4, 0x3064
  addi      r6, r1, 0x28
  lwz       r8, 0x224(r31)
  addi      r5, r1, 0x30
  addi      r3, r31, 0
  lfs       f1, 0x128(r8)
  lfs       f2, 0x138(r8)
  stw       r4, 0x30(r1)
  mr        r4, r31
  stw       r31, 0x34(r1)
  stw       r0, 0x30(r1)
  stfs      f1, 0x38(r1)
  stfs      f2, 0x3C(r1)
  stfs      f0, 0x40(r1)
  bl        -0xBE72C
  li        r0, 0
  stw       r0, 0x2F0(r31)
  lwz       r0, 0x54(r1)
  lwz       r31, 0x4C(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014E110
 * Size:	0002A0
 */
void Boss::createPellet(Vector3f &, float, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB8(r1)
  stfd      f31, 0xB0(r1)
  stfd      f30, 0xA8(r1)
  stfd      f29, 0xA0(r1)
  stfd      f28, 0x98(r1)
  stfd      f27, 0x90(r1)
  stfd      f26, 0x88(r1)
  stfd      f25, 0x80(r1)
  fmr       f25, f1
  stfd      f24, 0x78(r1)
  stfd      f23, 0x70(r1)
  stfd      f22, 0x68(r1)
  stmw      r26, 0x50(r1)
  mr        r30, r3
  addi      r31, r4, 0
  addi      r26, r5, 0
  lwz       r0, 0x2FC(r3)
  cmpwi     r0, 0
  beq-      .loc_0x1CC
  bl        0xC9F0C
  xoris     r3, r3, 0x8000
  lwz       r0, 0x2FC(r30)
  stw       r3, 0x4C(r1)
  lis       r29, 0x4330
  xoris     r0, r0, 0x8000
  lfd       f28, -0x57B8(r2)
  stw       r29, 0x48(r1)
  lfs       f29, -0x57C4(r2)
  li        r28, 0
  stw       r0, 0x44(r1)
  lfd       f0, 0x48(r1)
  stw       r29, 0x40(r1)
  fsubs     f3, f0, f28
  lfs       f1, -0x57C0(r2)
  lfd       f0, 0x40(r1)
  lfs       f2, -0x57CC(r2)
  fdivs     f3, f3, f29
  lfs       f24, -0x57EC(r2)
  lfs       f22, -0x57E0(r2)
  lfs       f23, -0x57BC(r2)
  fsubs     f0, f0, f28
  fmuls     f27, f2, f3
  fdivs     f26, f1, f0
  b         .loc_0x1C0

.loc_0xB8:
  xoris     r0, r28, 0x8000
  lwz       r27, 0x2F8(r30)
  stw       r0, 0x44(r1)
  stw       r29, 0x40(r1)
  lfd       f0, 0x40(r1)
  fsubs     f0, f0, f28
  fmuls     f0, f26, f0
  fadds     f31, f27, f0
  fmr       f1, f31
  bl        0xCDAFC
  fmr       f30, f1
  fmr       f1, f31
  bl        0xCD95C
  lfs       f0, 0x0(r31)
  fmr       f31, f1
  lfs       f1, 0x8(r31)
  cmpwi     r27, 0x2
  fadds     f0, f0, f30
  fadds     f1, f1, f31
  stfs      f0, 0x2C(r1)
  lfs       f0, 0x4(r31)
  stfs      f0, 0x30(r1)
  stfs      f1, 0x34(r1)
  bgt-      .loc_0x120
  cmpwi     r27, 0
  bge-      .loc_0x150

.loc_0x120:
  bl        0xC9E40
  xoris     r0, r3, 0x8000
  stw       r0, 0x44(r1)
  stw       r29, 0x40(r1)
  lfd       f0, 0x40(r1)
  fsubs     f0, f0, f28
  fdivs     f0, f0, f29
  fmuls     f0, f22, f0
  fmuls     f0, f23, f0
  fctiwz    f0, f0
  stfd      f0, 0x48(r1)
  lwz       r27, 0x4C(r1)

.loc_0x150:
  lwz       r3, 0x301C(r13)
  mr        r4, r27
  lwz       r5, 0x2F4(r30)
  bl        -0xB5D34
  mr.       r27, r3
  beq-      .loc_0x1BC
  mr        r3, r27
  lwz       r12, 0x0(r27)
  addi      r4, r1, 0x2C
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  fmuls     f1, f24, f30
  mr        r3, r27
  fmuls     f0, f24, f31
  li        r4, 0
  stfs      f1, 0x70(r27)
  stfs      f25, 0x74(r27)
  stfs      f0, 0x78(r27)
  lwz       r12, 0x0(r27)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r3, r27, 0
  addi      r4, r27, 0
  li        r5, 0xBB
  bl        -0xC3D14

.loc_0x1BC:
  addi      r28, r28, 0x1

.loc_0x1C0:
  lwz       r0, 0x2FC(r30)
  cmpw      r28, r0
  blt+      .loc_0xB8

.loc_0x1CC:
  rlwinm.   r0,r26,0,24,31
  beq-      .loc_0x25C
  lwz       r3, 0x301C(r13)
  li        r5, 0
  lwz       r4, 0x31C(r30)
  bl        -0xB5D40
  mr.       r27, r3
  beq-      .loc_0x25C
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r31
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lfs       f0, -0x500(r13)
  addi      r3, r27, 0
  li        r4, 0
  stfs      f0, 0x70(r27)
  stfs      f25, 0x74(r27)
  lfs       f0, -0x4FC(r13)
  stfs      f0, 0x78(r27)
  lfs       f0, 0xA0(r30)
  stfs      f0, 0xA0(r27)
  lwz       r12, 0x0(r27)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x2F28(r13)
  mr        r4, r30
  bl        -0xD2C3C
  lwz       r3, 0x31C(r30)
  bl        -0xB8FAC
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x25C
  li        r3, 0x122
  bl        -0xA8FF4

.loc_0x25C:
  mr        r3, r30
  bl        -0xC36D4
  lmw       r26, 0x50(r1)
  lwz       r0, 0xBC(r1)
  lfd       f31, 0xB0(r1)
  lfd       f30, 0xA8(r1)
  lfd       f29, 0xA0(r1)
  lfd       f28, 0x98(r1)
  lfd       f27, 0x90(r1)
  lfd       f26, 0x88(r1)
  lfd       f25, 0x80(r1)
  lfd       f24, 0x78(r1)
  lfd       f23, 0x70(r1)
  lfd       f22, 0x68(r1)
  addi      r1, r1, 0xB8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014E3B0
 * Size:	000164
 */
void Boss::changeDirection(float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stfd      f31, 0x30(r1)
  stw       r31, 0x2C(r1)
  li        r31, 0
  stw       r30, 0x28(r1)
  mr        r30, r3
  lwz       r4, 0x2DEC(r13)
  lfs       f4, 0x30C(r3)
  lfs       f0, 0x28C(r4)
  lfs       f3, 0x94(r3)
  fmuls     f31, f1, f0
  lfs       f2, 0x314(r3)
  lfs       f0, 0x9C(r3)
  fsubs     f1, f4, f3
  fsubs     f2, f2, f0
  bl        0xCD604
  lfs       f2, 0xA0(r30)
  lfs       f0, -0x57DC(r2)
  fcmpo     cr0, f2, f0
  bge-      .loc_0x64
  lfs       f0, -0x57C0(r2)
  fadds     f2, f0, f2
  b         .loc_0x78

.loc_0x64:
  lfs       f0, -0x57C0(r2)
  fcmpo     cr0, f2, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x78
  fsubs     f2, f2, f0

.loc_0x78:
  stfs      f2, 0xA0(r30)
  lfs       f4, 0xA0(r30)
  fcmpo     cr0, f1, f4
  cror      2, 0x1, 0x2
  bne-      .loc_0xA8
  fsubs     f3, f1, f4
  lfs       f2, -0x57C0(r2)
  fsubs     f0, f2, f3
  fcmpo     cr0, f0, f3
  bge-      .loc_0xC0
  fsubs     f1, f1, f2
  b         .loc_0xC0

.loc_0xA8:
  fsubs     f3, f4, f1
  lfs       f2, -0x57C0(r2)
  fsubs     f0, f2, f3
  fcmpo     cr0, f0, f3
  bge-      .loc_0xC0
  fadds     f1, f1, f2

.loc_0xC0:
  fcmpo     cr0, f1, f4
  ble-      .loc_0xEC
  fsubs     f0, f1, f4
  fcmpo     cr0, f0, f31
  bge-      .loc_0xDC
  stfs      f1, 0xA0(r30)
  b         .loc_0x10C

.loc_0xDC:
  fadds     f0, f4, f31
  li        r31, 0x1
  stfs      f0, 0xA0(r30)
  b         .loc_0x10C

.loc_0xEC:
  fsubs     f0, f4, f1
  fcmpo     cr0, f0, f31
  bge-      .loc_0x100
  stfs      f1, 0xA0(r30)
  b         .loc_0x10C

.loc_0x100:
  fsubs     f0, f4, f31
  li        r31, 0x1
  stfs      f0, 0xA0(r30)

.loc_0x10C:
  lfs       f1, 0xA0(r30)
  lfs       f0, -0x57DC(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x128
  lfs       f0, -0x57C0(r2)
  fadds     f1, f0, f1
  b         .loc_0x13C

.loc_0x128:
  lfs       f0, -0x57C0(r2)
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x13C
  fsubs     f1, f1, f0

.loc_0x13C:
  stfs      f1, 0x8C(r30)
  mr        r3, r31
  stfs      f1, 0xA0(r30)
  lwz       r0, 0x3C(r1)
  lfd       f31, 0x30(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void Boss::towardFaceDirection(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014E514
 * Size:	000034
 */
void Boss::stopMovement()
{
/*
.loc_0x0:
  lfs       f0, -0x4F8(r13)
  stfs      f0, 0xA4(r3)
  lfs       f0, -0x4F4(r13)
  stfs      f0, 0xA8(r3)
  lfs       f0, -0x4F0(r13)
  stfs      f0, 0xAC(r3)
  lfs       f0, -0x4EC(r13)
  stfs      f0, 0x70(r3)
  lfs       f0, -0x4E8(r13)
  stfs      f0, 0x74(r3)
  lfs       f0, -0x4E4(r13)
  stfs      f0, 0x78(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8014E548
 * Size:	000050
 */
void Boss::calcBossDamage()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lfs       f1, 0x2C4(r3)
  addi      r3, r31, 0x1E0
  lfs       f0, 0x2C0(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0x2C4(r31)
  lfs       f1, 0x2C4(r31)
  lfs       f2, 0x2C8(r31)
  bl        -0xF2504
  lfs       f0, -0x57DC(r2)
  stfs      f0, 0x2C0(r31)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014E598
 * Size:	000030
 */
void Boss::makeTargetCreature()
{
/*
.loc_0x0:
  lwz       r4, 0x318(r3)
  cmplwi    r4, 0
  beqlr-    
  lfs       f0, 0x94(r4)
  stfs      f0, 0x30C(r3)
  lwz       r4, 0x318(r3)
  lfs       f0, 0x98(r4)
  stfs      f0, 0x310(r3)
  lwz       r4, 0x318(r3)
  lfs       f0, 0x9C(r4)
  stfs      f0, 0x314(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8014E5C8
 * Size:	000144
 */
void Boss::makeTargetRandom(float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x80(r1)
  stfd      f31, 0x78(r1)
  stfd      f30, 0x70(r1)
  stfd      f29, 0x68(r1)
  fmr       f29, f1
  stw       r31, 0x64(r1)
  stw       r30, 0x60(r1)
  mr        r30, r3
  lwz       r4, 0x2DEC(r13)
  lfs       f2, 0x2D0(r3)
  lfs       f0, 0x28C(r4)
  fadds     f0, f2, f0
  stfs      f0, 0x2D0(r3)
  lfs       f1, 0x2D0(r3)
  lfs       f0, -0x57B0(r2)
  fcmpo     cr0, f1, f0
  bgt-      .loc_0x68
  lfs       f1, 0x94(r30)
  lfs       f2, 0x9C(r30)
  lfs       f3, 0x30C(r30)
  lfs       f4, 0x314(r30)
  bl        -0x115FFC
  fcmpo     cr0, f1, f29
  bge-      .loc_0x120

.loc_0x68:
  bl        0xC9A40
  xoris     r0, r3, 0x8000
  lwz       r3, 0x224(r30)
  stw       r0, 0x5C(r1)
  lis       r31, 0x4330
  lfd       f3, -0x57B8(r2)
  stw       r31, 0x58(r1)
  lfs       f2, -0x57C4(r2)
  lfd       f0, 0x58(r1)
  lfs       f1, -0x57E0(r2)
  fsubs     f3, f0, f3
  lfs       f0, -0x57AC(r2)
  lfs       f31, 0x78(r3)
  fdivs     f2, f3, f2
  fmuls     f1, f1, f2
  fmuls     f29, f0, f1
  bl        0xC9A00
  xoris     r0, r3, 0x8000
  lfs       f0, -0x57A8(r2)
  stw       r0, 0x54(r1)
  fmr       f1, f29
  lfd       f5, -0x57B8(r2)
  fmuls     f0, f0, f31
  stw       r31, 0x50(r1)
  lfs       f3, -0x57C4(r2)
  lfd       f4, 0x50(r1)
  lfs       f2, -0x57E0(r2)
  fsubs     f4, f4, f5
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f30, f0, f2
  bl        0xCD4A8
  fmuls     f2, f30, f1
  lfs       f0, 0x308(r30)
  fmr       f1, f29
  fadds     f31, f0, f2
  bl        0xCD628
  fmuls     f1, f30, f1
  lfs       f0, 0x300(r30)
  lfs       f2, -0x4E0(r13)
  fadds     f0, f0, f1
  stfs      f0, 0x30C(r30)
  stfs      f2, 0x310(r30)
  stfs      f31, 0x314(r30)
  lfs       f0, -0x57DC(r2)
  stfs      f0, 0x2D0(r30)

.loc_0x120:
  lwz       r0, 0x84(r1)
  lfd       f31, 0x78(r1)
  lfd       f30, 0x70(r1)
  lfd       f29, 0x68(r1)
  lwz       r31, 0x64(r1)
  lwz       r30, 0x60(r1)
  addi      r1, r1, 0x80
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014E70C
 * Size:	0002D0
 */
void Boss::chaseNaviTransit()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB8(r1)
  stfd      f31, 0xB0(r1)
  stfd      f30, 0xA8(r1)
  stmw      r27, 0x94(r1)
  mr        r30, r3
  li        r31, 0
  lwz       r3, 0x318(r3)
  lfs       f31, -0x57A4(r2)
  cmplwi    r3, 0
  beq-      .loc_0xA0
  lfs       f0, -0x57DC(r2)
  stfs      f0, 0x7C(r1)
  stfs      f0, 0x78(r1)
  stfs      f0, 0x74(r1)
  lfsu      f1, 0x94(r3)
  lfs       f0, 0x94(r30)
  lfs       f4, 0x8(r3)
  fsubs     f0, f1, f0
  lfs       f3, 0x9C(r30)
  lfs       f2, 0x4(r3)
  lfs       f1, 0x98(r30)
  fsubs     f3, f4, f3
  stfs      f0, 0x58(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x58(r1)
  stfs      f0, 0x74(r1)
  stfs      f1, 0x78(r1)
  stfs      f3, 0x7C(r1)
  lfs       f1, 0x74(r1)
  lfs       f0, 0x78(r1)
  lfs       f2, 0x7C(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x140B64
  fmr       f31, f1

.loc_0xA0:
  lwz       r28, 0x3120(r13)
  mr        r3, r28
  lwz       r12, 0x0(r28)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lfs       f30, -0x57DC(r2)
  mr        r27, r3
  b         .loc_0x240

.loc_0xC4:
  cmpwi     r27, -0x1
  bne-      .loc_0xEC
  mr        r3, r28
  lwz       r12, 0x0(r28)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r29, r3
  b         .loc_0x108

.loc_0xEC:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r27
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0x108:
  lwz       r12, 0x0(r29)
  mr        r3, r29
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x224
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x224
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x224
  lfs       f1, 0x94(r30)
  lfs       f2, 0x9C(r30)
  lfs       f3, 0x94(r29)
  lfs       f4, 0x9C(r29)
  bl        -0x116250
  lwz       r3, 0x224(r30)
  lfs       f0, 0x88(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x224
  fcmpo     cr0, f1, f31
  bge-      .loc_0x224
  addi      r3, r30, 0
  addi      r4, r29, 0
  bl        0x634
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x224
  stfs      f30, 0x68(r1)
  stfs      f30, 0x64(r1)
  stfs      f30, 0x60(r1)
  lfs       f1, 0x94(r29)
  lfs       f0, 0x94(r30)
  lfs       f4, 0x9C(r29)
  lfs       f3, 0x9C(r30)
  fsubs     f0, f1, f0
  lfs       f2, 0x98(r29)
  lfs       f1, 0x98(r30)
  fsubs     f3, f4, f3
  stfs      f0, 0x50(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x50(r1)
  stfs      f0, 0x60(r1)
  stfs      f1, 0x64(r1)
  stfs      f3, 0x68(r1)
  lfs       f1, 0x60(r1)
  lfs       f0, 0x64(r1)
  lfs       f2, 0x68(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x140CCC
  lwz       r3, 0x224(r30)
  lfs       f0, 0x88(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x224
  fcmpo     cr0, f1, f31
  bge-      .loc_0x224
  fmr       f31, f1
  mr        r31, r29

.loc_0x224:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r27
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r27, r3

.loc_0x240:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r27
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x268
  li        r0, 0x1
  b         .loc_0x294

.loc_0x268:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r27
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x290
  li        r0, 0x1
  b         .loc_0x294

.loc_0x290:
  li        r0, 0

.loc_0x294:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0xC4
  cmplwi    r31, 0
  beq-      .loc_0x2B0
  stw       r31, 0x318(r30)
  li        r3, 0x1
  b         .loc_0x2B4

.loc_0x2B0:
  li        r3, 0

.loc_0x2B4:
  lmw       r27, 0x94(r1)
  lwz       r0, 0xBC(r1)
  lfd       f31, 0xB0(r1)
  lfd       f30, 0xA8(r1)
  addi      r1, r1, 0xB8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014E9DC
 * Size:	0002DC
 */
void Boss::chasePikiTransit()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xC0(r1)
  stfd      f31, 0xB8(r1)
  stfd      f30, 0xB0(r1)
  stmw      r27, 0x9C(r1)
  mr        r29, r3
  li        r30, 0
  lwz       r3, 0x318(r3)
  lfs       f31, -0x57A4(r2)
  cmplwi    r3, 0
  beq-      .loc_0xA0
  lfs       f0, -0x57DC(r2)
  stfs      f0, 0x80(r1)
  stfs      f0, 0x7C(r1)
  stfs      f0, 0x78(r1)
  lfsu      f1, 0x94(r3)
  lfs       f0, 0x94(r29)
  lfs       f4, 0x8(r3)
  fsubs     f0, f1, f0
  lfs       f3, 0x9C(r29)
  lfs       f2, 0x4(r3)
  lfs       f1, 0x98(r29)
  fsubs     f3, f4, f3
  stfs      f0, 0x5C(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x5C(r1)
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
  bl        -0x140E34
  fmr       f31, f1

.loc_0xA0:
  lwz       r31, 0x3068(r13)
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lfs       f30, -0x57DC(r2)
  mr        r27, r3
  b         .loc_0x24C

.loc_0xC4:
  cmpwi     r27, -0x1
  bne-      .loc_0xEC
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r28, r3
  b         .loc_0x108

.loc_0xEC:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r27
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r28, r3

.loc_0x108:
  lwz       r12, 0x0(r28)
  mr        r3, r28
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x230
  mr        r3, r28
  lwz       r12, 0x0(r28)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x230
  mr        r3, r28
  lwz       r12, 0x0(r28)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x230
  lwz       r0, 0x184(r28)
  cmplw     r0, r29
  beq-      .loc_0x230
  lfs       f1, 0x94(r29)
  lfs       f2, 0x9C(r29)
  lfs       f3, 0x94(r28)
  lfs       f4, 0x9C(r28)
  bl        -0x11652C
  lwz       r3, 0x224(r29)
  lfs       f0, 0x88(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x230
  fcmpo     cr0, f1, f31
  bge-      .loc_0x230
  addi      r3, r29, 0
  addi      r4, r28, 0
  bl        0x358
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x230
  stfs      f30, 0x6C(r1)
  stfs      f30, 0x68(r1)
  stfs      f30, 0x64(r1)
  lfs       f1, 0x94(r28)
  lfs       f0, 0x94(r29)
  lfs       f4, 0x9C(r28)
  lfs       f3, 0x9C(r29)
  fsubs     f0, f1, f0
  lfs       f2, 0x98(r28)
  lfs       f1, 0x98(r29)
  fsubs     f3, f4, f3
  stfs      f0, 0x54(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x54(r1)
  stfs      f0, 0x64(r1)
  stfs      f1, 0x68(r1)
  stfs      f3, 0x6C(r1)
  lfs       f1, 0x64(r1)
  lfs       f0, 0x68(r1)
  lfs       f2, 0x6C(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x140FA8
  lwz       r3, 0x224(r29)
  lfs       f0, 0x88(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x230
  fcmpo     cr0, f1, f31
  bge-      .loc_0x230
  fmr       f31, f1
  mr        r30, r28

.loc_0x230:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r27
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r27, r3

.loc_0x24C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r27
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x274
  li        r0, 0x1
  b         .loc_0x2A0

.loc_0x274:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r27
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x29C
  li        r0, 0x1
  b         .loc_0x2A0

.loc_0x29C:
  li        r0, 0

.loc_0x2A0:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0xC4
  cmplwi    r30, 0
  beq-      .loc_0x2BC
  stw       r30, 0x318(r29)
  li        r3, 0x1
  b         .loc_0x2C0

.loc_0x2BC:
  li        r3, 0

.loc_0x2C0:
  lmw       r27, 0x9C(r1)
  lwz       r0, 0xC4(r1)
  lfd       f31, 0xB8(r1)
  lfd       f30, 0xB0(r1)
  addi      r1, r1, 0xC0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014ECB8
 * Size:	000158
 */
void Boss::targetLostTransit()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stw       r31, 0x4C(r1)
  mr        r31, r3
  lwz       r3, 0x318(r3)
  cmplwi    r3, 0
  beq-      .loc_0x140
  lwz       r12, 0x0(r3)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x80
  lwz       r3, 0x318(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x80
  lwz       r3, 0x318(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x80
  lwz       r4, 0x318(r31)
  lwz       r0, 0x184(r4)
  cmplw     r0, r31
  bne-      .loc_0x90

.loc_0x80:
  li        r0, 0
  stw       r0, 0x318(r31)
  li        r3, 0x1
  b         .loc_0x144

.loc_0x90:
  mr        r3, r31
  bl        0x184
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0xB0
  li        r0, 0
  stw       r0, 0x318(r31)
  li        r3, 0x1
  b         .loc_0x144

.loc_0xB0:
  lwz       r3, 0x318(r31)
  lfs       f0, -0x57DC(r2)
  stfs      f0, 0x40(r1)
  stfs      f0, 0x3C(r1)
  stfs      f0, 0x38(r1)
  lfsu      f1, 0x94(r3)
  lfs       f0, 0x94(r31)
  lfs       f4, 0x8(r3)
  fsubs     f0, f1, f0
  lfs       f3, 0x9C(r31)
  lfs       f2, 0x4(r3)
  lfs       f1, 0x98(r31)
  fsubs     f3, f4, f3
  stfs      f0, 0x30(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x30(r1)
  stfs      f0, 0x38(r1)
  stfs      f1, 0x3C(r1)
  stfs      f3, 0x40(r1)
  lfs       f1, 0x38(r1)
  lfs       f0, 0x3C(r1)
  lfs       f2, 0x40(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x141194
  lwz       r3, 0x224(r31)
  lfs       f0, 0x88(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x140
  li        r0, 0
  stw       r0, 0x318(r31)
  li        r3, 0x1
  b         .loc_0x144

.loc_0x140:
  li        r3, 0

.loc_0x144:
  lwz       r0, 0x54(r1)
  lwz       r31, 0x4C(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014EE10
 * Size:	000060
 */
void Boss::inSideWaitRangeTransit()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  lfs       f1, 0x94(r3)
  lfs       f2, 0x9C(r3)
  lfs       f3, 0x300(r3)
  lfs       f4, 0x308(r3)
  bl        -0x11680C
  lwz       r3, 0x224(r31)
  lfs       f0, 0x78(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x48
  li        r0, 0
  stw       r0, 0x318(r31)
  li        r3, 0x1
  b         .loc_0x4C

.loc_0x48:
  li        r3, 0

.loc_0x4C:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014EE70
 * Size:	000060
 */
void Boss::outSideChaseRangeTransit()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  lfs       f1, 0x94(r3)
  lfs       f2, 0x9C(r3)
  lfs       f3, 0x300(r3)
  lfs       f4, 0x308(r3)
  bl        -0x11686C
  lwz       r3, 0x224(r31)
  lfs       f0, 0x68(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x48
  li        r0, 0
  stw       r0, 0x318(r31)
  li        r3, 0x1
  b         .loc_0x4C

.loc_0x48:
  li        r3, 0

.loc_0x4C:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014EED0
 * Size:	0000C4
 */
void Boss::inSearchAngle(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r3
  lfs       f3, 0x94(r4)
  lfs       f1, 0x94(r3)
  lfs       f2, 0x9C(r4)
  lfs       f0, 0x9C(r3)
  fsubs     f1, f3, f1
  fsubs     f2, f2, f0
  bl        0xCCAFC
  lfs       f4, 0xA0(r31)
  fcmpo     cr0, f1, f4
  cror      2, 0x1, 0x2
  bne-      .loc_0x5C
  fsubs     f3, f1, f4
  lfs       f2, -0x57C0(r2)
  fsubs     f0, f2, f3
  fcmpo     cr0, f0, f3
  bge-      .loc_0x74
  fsubs     f1, f1, f2
  b         .loc_0x74

.loc_0x5C:
  fsubs     f3, f4, f1
  lfs       f2, -0x57C0(r2)
  fsubs     f0, f2, f3
  fcmpo     cr0, f0, f3
  bge-      .loc_0x74
  fadds     f1, f1, f2

.loc_0x74:
  fcmpo     cr0, f1, f4
  ble-      .loc_0x94
  fsubs     f1, f1, f4
  lfs       f0, 0x2DC(r31)
  fcmpo     cr0, f1, f0
  bge-      .loc_0xAC
  li        r3, 0x1
  b         .loc_0xB0

.loc_0x94:
  fsubs     f1, f4, f1
  lfs       f0, 0x2DC(r31)
  fcmpo     cr0, f1, f0
  bge-      .loc_0xAC
  li        r3, 0x1
  b         .loc_0xB0

.loc_0xAC:
  li        r3, 0

.loc_0xB0:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014EF94
 * Size:	0000B8
 */
void Boss::flickPikiTransit()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x68(r1)
  stw       r31, 0x64(r1)
  mr        r31, r3
  bl        0x228
  lwz       r5, 0x224(r31)
  lwz       r0, 0x198(r5)
  cmpw      r3, r0
  blt-      .loc_0x40
  lwz       r3, 0x2F0(r31)
  lwz       r0, 0x1D8(r5)
  cmpw      r3, r0
  blt-      .loc_0xA0
  li        r3, 0x1
  b         .loc_0xA4

.loc_0x40:
  lwz       r0, 0x188(r5)
  cmpw      r3, r0
  blt-      .loc_0x64
  lwz       r3, 0x2F0(r31)
  lwz       r0, 0x1C8(r5)
  cmpw      r3, r0
  blt-      .loc_0xA0
  li        r3, 0x1
  b         .loc_0xA4

.loc_0x64:
  lwz       r0, 0x178(r5)
  cmpw      r3, r0
  blt-      .loc_0x88
  lwz       r3, 0x2F0(r31)
  lwz       r0, 0x1B8(r5)
  cmpw      r3, r0
  blt-      .loc_0xA0
  li        r3, 0x1
  b         .loc_0xA4

.loc_0x88:
  lwz       r3, 0x2F0(r31)
  lwz       r0, 0x1A8(r5)
  cmpw      r3, r0
  blt-      .loc_0xA0
  li        r3, 0x1
  b         .loc_0xA4

.loc_0xA0:
  li        r3, 0

.loc_0xA4:
  lwz       r0, 0x6C(r1)
  lwz       r31, 0x64(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F04C
 * Size:	00002C
 */
void Boss::getStickPikiCount()
{
/*
.loc_0x0:
  mflr      r0
  addi      r4, r3, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  addi      r3, r1, 0xC
  bl        -0xBE3DC
  lwz       r3, 0x14(r1)
  lwz       r0, 0x24(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F078
 * Size:	000158
 */
void Boss::getStickMouthPikiCount()
{
/*
.loc_0x0:
  mflr      r0
  addi      r4, r3, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  addi      r3, r1, 0x20
  stw       r30, 0x38(r1)
  stw       r29, 0x34(r1)
  stw       r28, 0x30(r1)
  li        r28, 0
  bl        -0xBE41C
  addi      r30, r1, 0x20
  addi      r3, r30, 0
  lwz       r12, 0x0(r30)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r29, r3
  b         .loc_0xD8

.loc_0x4C:
  cmpwi     r29, -0x1
  bne-      .loc_0x74
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3
  b         .loc_0x90

.loc_0x74:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3

.loc_0x90:
  lwz       r12, 0x0(r31)
  mr        r3, r31
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xBC
  lwz       r0, 0xC8(r31)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0xBC
  addi      r28, r28, 0x1

.loc_0xBC:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0xD8:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x100
  li        r0, 0x1
  b         .loc_0x12C

.loc_0x100:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x128
  li        r0, 0x1
  b         .loc_0x12C

.loc_0x128:
  li        r0, 0

.loc_0x12C:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x4C
  mr        r3, r28
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  lwz       r29, 0x34(r1)
  lwz       r28, 0x30(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F1D0
 * Size:	000158
 */
void Boss::getStickNoMouthPikiCount()
{
/*
.loc_0x0:
  mflr      r0
  addi      r4, r3, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  addi      r3, r1, 0x20
  stw       r30, 0x38(r1)
  stw       r29, 0x34(r1)
  stw       r28, 0x30(r1)
  li        r28, 0
  bl        -0xBE574
  addi      r30, r1, 0x20
  addi      r3, r30, 0
  lwz       r12, 0x0(r30)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r29, r3
  b         .loc_0xD8

.loc_0x4C:
  cmpwi     r29, -0x1
  bne-      .loc_0x74
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3
  b         .loc_0x90

.loc_0x74:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3

.loc_0x90:
  lwz       r12, 0x0(r31)
  mr        r3, r31
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xBC
  lwz       r0, 0xC8(r31)
  rlwinm.   r0,r0,0,16,16
  bne-      .loc_0xBC
  addi      r28, r28, 0x1

.loc_0xBC:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0xD8:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x100
  li        r0, 0x1
  b         .loc_0x12C

.loc_0x100:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x128
  li        r0, 0x1
  b         .loc_0x12C

.loc_0x128:
  li        r0, 0

.loc_0x12C:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x4C
  mr        r3, r28
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  lwz       r29, 0x34(r1)
  lwz       r28, 0x30(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F328
 * Size:	000048
 */
void Boss::killStickToMouthPiki()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802B
  stw       r0, 0x4(r1)
  subi      r0, r4, 0xF68
  lis       r4, 0x802D
  stwu      r1, -0x18(r1)
  li        r6, 0
  stw       r0, 0xC(r1)
  subi      r0, r4, 0x1458
  addi      r5, r1, 0xC
  stw       r0, 0xC(r1)
  addi      r4, r3, 0
  stw       r3, 0x10(r1)
  bl        -0xBF838
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void Boss::checkInWater(Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014F370
 * Size:	000050
 */
void Boss::getMapAttribute(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  li        r31, -0x1
  lwz       r3, 0x2F00(r13)
  lfs       f1, 0x0(r4)
  lfs       f2, 0x8(r4)
  li        r4, 0x1
  bl        -0xE71BC
  cmplwi    r3, 0
  beq-      .loc_0x38
  bl        -0x39320
  mr        r31, r3

.loc_0x38:
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
 * Address:	8014F3C0
 * Size:	00006C
 */
void Boss::insideAndInSearch()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r3
  lwz       r0, 0xC8(r3)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x54
  lwz       r3, 0x3120(r13)
  bl        -0x38020
  lfs       f1, 0x94(r31)
  lfs       f2, 0x9C(r31)
  lfs       f3, 0x94(r3)
  lfs       f4, 0x9C(r3)
  bl        -0x116DD0
  lwz       r3, 0x224(r31)
  lfs       f0, 0x88(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x54
  li        r3, 0x1
  b         .loc_0x58

.loc_0x54:
  li        r3, 0

.loc_0x58:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void Boss::recoveryLife()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014F42C
 * Size:	000100
 */
void Boss::updateBoss()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stw       r31, 0x44(r1)
  addi      r31, r3, 0
  addi      r3, r31, 0x40
  addi      r4, r31, 0x94
  bl        -0xBAF28
  addi      r3, r31, 0x40
  addi      r4, r31, 0x94
  li        r5, 0
  bl        -0xBAE9C
  lwz       r3, 0x2C(r31)
  cmplwi    r3, 0
  beq-      .loc_0x40
  bl        -0xAB57C

.loc_0x40:
  lfs       f2, 0x2C4(r31)
  lfs       f1, -0x57DC(r2)
  fcmpo     cr0, f2, f1
  ble-      .loc_0xE4
  lfs       f0, 0x2C8(r31)
  fcmpo     cr0, f2, f0
  bge-      .loc_0xE4
  lwz       r4, 0x224(r31)
  lfs       f0, 0xC8(r4)
  fcmpo     cr0, f0, f1
  ble-      .loc_0xE4
  lfs       f0, 0xB8(r4)
  fcmpo     cr0, f0, f1
  ble-      .loc_0xE4
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x2CC(r31)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x2CC(r31)
  lwz       r4, 0x224(r31)
  lfs       f1, 0x2CC(r31)
  lfs       f0, 0xB8(r4)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xE4
  lfs       f1, 0x2C8(r31)
  lfs       f0, 0xC8(r4)
  lfs       f2, 0x2C4(r31)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x2C4(r31)
  lfs       f0, 0x2C4(r31)
  lfs       f1, 0x2C8(r31)
  fcmpo     cr0, f0, f1
  ble-      .loc_0xCC
  stfs      f1, 0x2C4(r31)

.loc_0xCC:
  lfs       f1, 0x2C4(r31)
  addi      r3, r31, 0x1E0
  lfs       f2, 0x2C8(r31)
  bl        -0xF3490
  lfs       f0, -0x57DC(r2)
  stfs      f0, 0x2CC(r31)

.loc_0xE4:
  lwz       r0, 0x2E8(r31)
  stw       r0, 0x2E4(r31)
  lwz       r0, 0x4C(r1)
  lwz       r31, 0x44(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F52C
 * Size:	00008C
 */
void Boss::refreshViewCulling(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  mr        r31, r3
  lfs       f0, 0x94(r3)
  stfs      f0, 0x24(r1)
  lfs       f0, 0x98(r3)
  stfs      f0, 0x28(r1)
  lfs       f0, 0x9C(r3)
  stfs      f0, 0x2C(r1)
  lwz       r3, 0x224(r3)
  lfs       f1, 0x28(r1)
  lfs       f0, 0x158(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x28(r1)
  lwz       r5, 0x224(r31)
  lwz       r3, 0x2E4(r4)
  addi      r4, r1, 0x24
  lfs       f1, 0x148(r5)
  bl        -0x10DFF8
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x6C
  lwz       r0, 0xC8(r31)
  oris      r0, r0, 0x8
  stw       r0, 0xC8(r31)
  b         .loc_0x78

.loc_0x6C:
  lwz       r0, 0xC8(r31)
  rlwinm    r0,r0,0,13,11
  stw       r0, 0xC8(r31)

.loc_0x78:
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F5B8
 * Size:	000004
 */
void Boss::drawShape(Graphics &)
{
}

/*
 * --INFO--
 * Address:	8014F5BC
 * Size:	00006C
 */
void Boss::refresh2d(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  mr        r7, r3
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r5, 0x94(r3)
  lwz       r0, 0x98(r3)
  addi      r3, r7, 0x1E0
  stw       r5, 0x1E0(r7)
  stw       r0, 0x1E4(r7)
  lwz       r0, 0x9C(r7)
  stw       r0, 0x1E8(r7)
  lwz       r5, 0x224(r7)
  lfs       f1, 0x1E4(r7)
  lfs       f0, 0x108(r5)
  fadds     f0, f1, f0
  stfs      f0, 0x1E4(r7)
  lwz       r6, 0x224(r7)
  lwz       r5, 0x2E4(r4)
  lfs       f1, 0xF8(r6)
  lfs       f0, 0x1D0(r5)
  fdivs     f0, f1, f0
  stfs      f0, 0x214(r7)
  bl        -0xF3570
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F628
 * Size:	000030
 */
void Boss::wallCallback(Plane &, DynCollObject *)
{
/*
.loc_0x0:
  li        r0, 0x1
  stb       r0, 0x2BF(r3)
  lwz       r6, 0x0(r4)
  lwz       r0, 0x4(r4)
  stw       r6, 0x328(r3)
  stw       r0, 0x32C(r3)
  lwz       r6, 0x8(r4)
  lwz       r0, 0xC(r4)
  stw       r6, 0x330(r3)
  stw       r0, 0x334(r3)
  stw       r5, 0x338(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F658
 * Size:	000114
 */
void InteractAttack::actBoss(Boss *)
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
  lfs       f0, -0x57DC(r2)
  lfs       f1, 0x2C4(r4)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xF8
  lbz       r0, 0x2BC(r31)
  cmplwi    r0, 0
  bne-      .loc_0xF8
  mr        r3, r30
  bl        -0xD3654
  cmpwi     r3, 0x1
  beq-      .loc_0x78
  bge-      .loc_0x58
  cmpwi     r3, 0
  bge-      .loc_0x64
  b         .loc_0xD4

.loc_0x58:
  cmpwi     r3, 0x3
  bge-      .loc_0xD4
  b         .loc_0x9C

.loc_0x64:
  lwz       r4, 0x2F0(r31)
  li        r3, 0
  addi      r0, r4, 0x1
  stw       r0, 0x2F0(r31)
  b         .loc_0xFC

.loc_0x78:
  lwz       r4, 0x2F0(r31)
  li        r3, 0x1
  addi      r0, r4, 0x1
  stw       r0, 0x2F0(r31)
  lfs       f1, 0x2C0(r31)
  lfs       f0, 0x8(r30)
  fadds     f0, f1, f0
  stfs      f0, 0x2C0(r31)
  b         .loc_0xFC

.loc_0x9C:
  lwz       r4, 0x224(r31)
  li        r3, 0x1
  lwz       r5, 0x2F0(r31)
  lwz       r0, 0x168(r4)
  add       r0, r5, r0
  stw       r0, 0x2F0(r31)
  lwz       r4, 0x224(r31)
  lfs       f1, 0x8(r30)
  lfs       f0, 0xD8(r4)
  lfs       f2, 0x2C0(r31)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x2C0(r31)
  b         .loc_0xFC

.loc_0xD4:
  lwz       r4, 0x2F0(r31)
  addi      r3, r31, 0
  addi      r0, r4, 0x1
  stw       r0, 0x2F0(r31)
  lwz       r12, 0x0(r31)
  lwz       r12, 0x118(r12)
  mtlr      r12
  blrl      
  b         .loc_0xFC

.loc_0xF8:
  li        r3, 0

.loc_0xFC:
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
 * Address:	8014F76C
 * Size:	000008
 */
u32  Boss::attackDefaultPortion()
{
	return 0x0;
}

/*
 * --INFO--
 * Address:	8014F774
 * Size:	00003C
 */
void InteractFlick::actBoss(Boss *)
{
/*
.loc_0x0:
  lfs       f1, 0x2C4(r4)
  lfs       f0, -0x57DC(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x34
  lbz       r0, 0x2BC(r4)
  cmplwi    r0, 0
  bne-      .loc_0x34
  lfs       f0, 0xC(r3)
  li        r3, 0x1
  lfs       f1, 0x2C0(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x2C0(r4)
  blr       

.loc_0x34:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F7B0
 * Size:	000084
 */
void InteractBomb::actBoss(Boss *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lfs       f0, -0x57DC(r2)
  lfs       f1, 0x2C4(r4)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x70
  lbz       r0, 0x2BC(r4)
  cmplwi    r0, 0
  bne-      .loc_0x70
  lwz       r5, 0x224(r4)
  lfs       f1, 0x8(r3)
  lfs       f0, 0xE8(r5)
  lfs       f2, 0x2C0(r4)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x2C0(r4)
  lwz       r0, 0xC(r3)
  cmplwi    r0, 0
  beq-      .loc_0x68
  mr        r3, r4
  lwz       r12, 0x0(r4)
  mr        r4, r0
  lwz       r12, 0x11C(r12)
  mtlr      r12
  blrl      

.loc_0x68:
  li        r3, 0x1
  b         .loc_0x74

.loc_0x70:
  li        r3, 0

.loc_0x74:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F834
 * Size:	000004
 */
void Boss::bombDamageCounter(CollPart *)
{
}

/*
 * --INFO--
 * Address:	8014F838
 * Size:	000110
 */
void InteractHitEffect::actBoss(Boss *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r4
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  lwz       r4, 0x6C(r4)
  subi      r0, r4, 0x27
  cmplwi    r0, 0x7
  bgt-      .loc_0xF4
  lis       r3, 0x802D
  subi      r3, r3, 0x1814
  rlwinm    r0,r0,2,0,29
  lwzx      r0, r3, r0
  mtctr     r0
  bctr      
  lwz       r3, 0x3180(r13)
  addi      r5, r30, 0x8
  li        r4, 0x45
  li        r6, 0
  li        r7, 0
  bl        0x4D2A8
  li        r3, 0x1
  b         .loc_0xF8
  lwz       r3, 0x3180(r13)
  addi      r5, r30, 0x8
  li        r4, 0x45
  li        r6, 0
  li        r7, 0
  bl        0x4D288
  li        r3, 0x1
  b         .loc_0xF8
  lwz       r3, 0x3180(r13)
  addi      r5, r30, 0x8
  li        r4, 0x45
  li        r6, 0
  li        r7, 0
  bl        0x4D268
  lwz       r3, 0x20(r30)
  cmplwi    r3, 0
  beq-      .loc_0xCC
  lwz       r0, 0x2C(r31)
  cmplwi    r0, 0
  beq-      .loc_0xCC
  bl        -0xC7BAC
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xCC
  lwz       r3, 0x2C(r31)
  li        r4, 0x46
  bl        -0xABB30

.loc_0xCC:
  li        r3, 0x1
  b         .loc_0xF8
  lwz       r3, 0x3180(r13)
  addi      r5, r30, 0x8
  li        r4, 0x45
  li        r6, 0
  li        r7, 0
  bl        0x4D218
  li        r3, 0x1
  b         .loc_0xF8

.loc_0xF4:
  li        r3, 0

.loc_0xF8:
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
 * Address:	8014F948
 * Size:	00006C
 */
void Boss::stimulate(Interaction &)
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
  beq-      .loc_0x54
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x18(r12)
  mtlr      r12
  blrl      

.loc_0x54:
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
 * Address:	8014F9B4
 * Size:	000008
 */
void Boss::isAlive()
{
/*
.loc_0x0:
  lbz       r3, 0x2B8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F9BC
 * Size:	000008
 */
void Boss::isAtari()
{
/*
.loc_0x0:
  lbz       r3, 0x2B9(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F9C4
 * Size:	000008
 */
void Boss::isVisible()
{
/*
.loc_0x0:
  lbz       r3, 0x2BA(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F9CC
 * Size:	000008
 */
void Boss::isOrganic()
{
/*
.loc_0x0:
  lbz       r3, 0x2BB(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8014F9D4
 * Size:	000008
 */
u32  Boss::isFixed()
{
	return 0x1;
}

/*
 * --INFO--
 * Address:	8014F9DC
 * Size:	000008
 */
u32  Boss::ignoreAtari(Creature *)
{
	return 0x0;
}

/*
 * --INFO--
 * Address:	8014F9E4
 * Size:	00001C
 */
void Boss::getCentre()
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
 * Address:	8014FA00
 * Size:	000008
 */
void Boss::needShadow()
{
/*
.loc_0x0:
  lbz       r3, 0x2BE(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8014FA08
 * Size:	000008
 */
void Boss::getShadowSize()
{
/*
.loc_0x0:
  lfs       f1, 0x2E0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8014FA10
 * Size:	000004
 */
void Boss::update()
{
}

/*
 * --INFO--
 * Address:	8014FA14
 * Size:	000004
 */
void Boss::refresh(Graphics &)
{
}

/*
 * --INFO--
 * Address:	8014FA18
 * Size:	000004
 */
void Boss::doKill()
{
}

/*
 * --INFO--
 * Address:	8014FA1C
 * Size:	000004
 */
void Boss::exitCourse()
{
}

/*
 * --INFO--
 * Address:	8014FA20
 * Size:	000004
 */
void Boss::collisionCallback(CollEvent &)
{
}

/*
 * --INFO--
 * Address:	8014FA24
 * Size:	000044
 */
void BossProp::read(RandomAccessStream &)
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
  bl        -0xF0EA8
  addi      r3, r30, 0x58
  addi      r4, r31, 0
  bl        -0xF0EB4
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}
