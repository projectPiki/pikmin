#include "Slime.h"
#include "system.h"

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
 * Address:	80163714
 * Size:	000578
 */
SlimeProp::SlimeProp()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1D8(r1)
	  stw       r31, 0x1D4(r1)
	  mr        r31, r3
	  stw       r30, 0x1D0(r1)
	  bl        -0x15E60
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x1EC(r31)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x1EC(r31)
	  li        r7, 0
	  lis       r3, 0x802D
	  stw       r7, 0x1FC(r31)
	  subi      r6, r3, 0x148
	  lis       r4, 0x802D
	  stw       r7, 0x1F8(r31)
	  subi      r3, r4, 0x4BC
	  addi      r0, r6, 0xC
	  stw       r7, 0x1F4(r31)
	  addi      r5, r1, 0xE8
	  addi      r4, r31, 0x200
	  stw       r3, 0x1F0(r31)
	  addi      r3, r31, 0x204
	  stw       r6, 0x54(r31)
	  stw       r0, 0x1EC(r31)
	  stw       r7, 0x200(r31)
	  lwz       r0, 0x30(r13)
	  stw       r0, 0xF0(r1)
	  lwz       r0, 0xF0(r1)
	  stw       r0, 0xE8(r1)
	  bl        -0x104D18
	  lis       r3, 0x802A
	  addi      r30, r3, 0x6098
	  stw       r30, 0x20C(r31)
	  addi      r5, r1, 0xE4
	  addi      r3, r31, 0x214
	  lfs       f0, -0x5518(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x210(r31)
	  lwz       r0, 0x34(r13)
	  stw       r0, 0xF8(r1)
	  lwz       r0, 0xF8(r1)
	  stw       r0, 0xE4(r1)
	  bl        -0x104D4C
	  stw       r30, 0x21C(r31)
	  addi      r5, r1, 0xE0
	  addi      r3, r31, 0x224
	  lfs       f0, -0x5514(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x220(r31)
	  lwz       r0, 0x38(r13)
	  stw       r0, 0x100(r1)
	  lwz       r0, 0x100(r1)
	  stw       r0, 0xE0(r1)
	  bl        -0x104D78
	  stw       r30, 0x22C(r31)
	  addi      r5, r1, 0xDC
	  addi      r3, r31, 0x234
	  lfs       f0, -0x5510(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x230(r31)
	  lwz       r0, 0x3C(r13)
	  stw       r0, 0x108(r1)
	  lwz       r0, 0x108(r1)
	  stw       r0, 0xDC(r1)
	  bl        -0x104DA4
	  stw       r30, 0x23C(r31)
	  addi      r5, r1, 0xD8
	  addi      r3, r31, 0x244
	  lfs       f0, -0x550C(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x240(r31)
	  lwz       r0, 0x40(r13)
	  stw       r0, 0x110(r1)
	  lwz       r0, 0x110(r1)
	  stw       r0, 0xD8(r1)
	  bl        -0x104DD0
	  stw       r30, 0x24C(r31)
	  addi      r5, r1, 0xD4
	  addi      r3, r31, 0x254
	  lfs       f0, -0x5514(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x250(r31)
	  lwz       r0, 0x44(r13)
	  stw       r0, 0x118(r1)
	  lwz       r0, 0x118(r1)
	  stw       r0, 0xD4(r1)
	  bl        -0x104DFC
	  stw       r30, 0x25C(r31)
	  addi      r5, r1, 0xD0
	  addi      r3, r31, 0x264
	  lfs       f0, -0x5508(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x260(r31)
	  lwz       r0, 0x48(r13)
	  stw       r0, 0x120(r1)
	  lwz       r0, 0x120(r1)
	  stw       r0, 0xD0(r1)
	  bl        -0x104E28
	  stw       r30, 0x26C(r31)
	  addi      r5, r1, 0xCC
	  addi      r3, r31, 0x274
	  lfs       f0, -0x550C(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x270(r31)
	  lwz       r0, 0x4C(r13)
	  stw       r0, 0x128(r1)
	  lwz       r0, 0x128(r1)
	  stw       r0, 0xCC(r1)
	  bl        -0x104E54
	  stw       r30, 0x27C(r31)
	  addi      r5, r1, 0xC8
	  addi      r3, r31, 0x284
	  lfs       f0, -0x5504(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x280(r31)
	  lwz       r0, 0x50(r13)
	  stw       r0, 0x130(r1)
	  lwz       r0, 0x130(r1)
	  stw       r0, 0xC8(r1)
	  bl        -0x104E80
	  stw       r30, 0x28C(r31)
	  addi      r5, r1, 0xC4
	  addi      r3, r31, 0x294
	  lfs       f0, -0x5500(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x290(r31)
	  lwz       r0, 0x54(r13)
	  stw       r0, 0x138(r1)
	  lwz       r0, 0x138(r1)
	  stw       r0, 0xC4(r1)
	  bl        -0x104EAC
	  stw       r30, 0x29C(r31)
	  addi      r5, r1, 0xC0
	  addi      r3, r31, 0x2A4
	  lfs       f0, -0x54FC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2A0(r31)
	  lwz       r0, 0x58(r13)
	  stw       r0, 0x140(r1)
	  lwz       r0, 0x140(r1)
	  stw       r0, 0xC0(r1)
	  bl        -0x104ED8
	  stw       r30, 0x2AC(r31)
	  addi      r5, r1, 0xBC
	  addi      r3, r31, 0x2B4
	  lfs       f0, -0x54F8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2B0(r31)
	  lwz       r0, 0x5C(r13)
	  stw       r0, 0x148(r1)
	  lwz       r0, 0x148(r1)
	  stw       r0, 0xBC(r1)
	  bl        -0x104F04
	  stw       r30, 0x2BC(r31)
	  addi      r5, r1, 0xB8
	  addi      r3, r31, 0x2C4
	  lfs       f0, -0x550C(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2C0(r31)
	  lwz       r0, 0x60(r13)
	  stw       r0, 0x150(r1)
	  lwz       r0, 0x150(r1)
	  stw       r0, 0xB8(r1)
	  bl        -0x104F30
	  stw       r30, 0x2CC(r31)
	  addi      r5, r1, 0xB4
	  addi      r3, r31, 0x2D4
	  lfs       f0, -0x5518(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2D0(r31)
	  lwz       r0, 0x64(r13)
	  stw       r0, 0x158(r1)
	  lwz       r0, 0x158(r1)
	  stw       r0, 0xB4(r1)
	  bl        -0x104F5C
	  stw       r30, 0x2DC(r31)
	  addi      r5, r1, 0xB0
	  addi      r3, r31, 0x2E4
	  lfs       f0, -0x5514(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2E0(r31)
	  lwz       r0, 0x68(r13)
	  stw       r0, 0x160(r1)
	  lwz       r0, 0x160(r1)
	  stw       r0, 0xB0(r1)
	  bl        -0x104F88
	  stw       r30, 0x2EC(r31)
	  addi      r5, r1, 0xAC
	  addi      r3, r31, 0x2F4
	  lfs       f0, -0x5500(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2F0(r31)
	  lwz       r0, 0x6C(r13)
	  stw       r0, 0x168(r1)
	  lwz       r0, 0x168(r1)
	  stw       r0, 0xAC(r1)
	  bl        -0x104FB4
	  stw       r30, 0x2FC(r31)
	  addi      r5, r1, 0xA8
	  addi      r3, r31, 0x304
	  lfs       f0, -0x54F4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x300(r31)
	  lwz       r0, 0x70(r13)
	  stw       r0, 0x170(r1)
	  lwz       r0, 0x170(r1)
	  stw       r0, 0xA8(r1)
	  bl        -0x104FE0
	  stw       r30, 0x30C(r31)
	  addi      r5, r1, 0xA4
	  addi      r3, r31, 0x314
	  lfs       f0, -0x54F0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x310(r31)
	  lwz       r0, 0x74(r13)
	  stw       r0, 0x178(r1)
	  lwz       r0, 0x178(r1)
	  stw       r0, 0xA4(r1)
	  bl        -0x10500C
	  stw       r30, 0x31C(r31)
	  addi      r5, r1, 0xA0
	  addi      r3, r31, 0x324
	  lfs       f0, -0x5510(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x320(r31)
	  lwz       r0, 0x78(r13)
	  stw       r0, 0x180(r1)
	  lwz       r0, 0x180(r1)
	  stw       r0, 0xA0(r1)
	  bl        -0x105038
	  stw       r30, 0x32C(r31)
	  addi      r5, r1, 0x9C
	  addi      r3, r31, 0x334
	  lfs       f0, -0x54EC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x330(r31)
	  lwz       r0, 0x7C(r13)
	  stw       r0, 0x188(r1)
	  lwz       r0, 0x188(r1)
	  stw       r0, 0x9C(r1)
	  bl        -0x105064
	  stw       r30, 0x33C(r31)
	  addi      r5, r1, 0x98
	  addi      r3, r31, 0x344
	  lfs       f0, -0x5510(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x340(r31)
	  lwz       r0, 0x80(r13)
	  stw       r0, 0x190(r1)
	  lwz       r0, 0x190(r1)
	  stw       r0, 0x98(r1)
	  bl        -0x105090
	  stw       r30, 0x34C(r31)
	  addi      r5, r1, 0x94
	  addi      r3, r31, 0x354
	  lfs       f0, -0x54E8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x350(r31)
	  lwz       r0, 0x84(r13)
	  stw       r0, 0x198(r1)
	  lwz       r0, 0x198(r1)
	  stw       r0, 0x94(r1)
	  bl        -0x1050BC
	  stw       r30, 0x35C(r31)
	  addi      r5, r1, 0x90
	  addi      r3, r31, 0x364
	  lfs       f0, -0x54E8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x360(r31)
	  lwz       r0, 0x88(r13)
	  stw       r0, 0x1A0(r1)
	  lwz       r0, 0x1A0(r1)
	  stw       r0, 0x90(r1)
	  bl        -0x1050E8
	  stw       r30, 0x36C(r31)
	  addi      r5, r1, 0x8C
	  addi      r3, r31, 0x374
	  lfs       f0, -0x5518(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x370(r31)
	  lwz       r0, 0x8C(r13)
	  stw       r0, 0x1A8(r1)
	  lwz       r0, 0x1A8(r1)
	  stw       r0, 0x8C(r1)
	  bl        -0x105114
	  stw       r30, 0x37C(r31)
	  addi      r5, r1, 0x88
	  addi      r3, r31, 0x384
	  lfs       f0, -0x54E4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x380(r31)
	  lwz       r0, 0x90(r13)
	  stw       r0, 0x1B0(r1)
	  lwz       r0, 0x1B0(r1)
	  stw       r0, 0x88(r1)
	  bl        -0x105140
	  stw       r30, 0x38C(r31)
	  addi      r5, r1, 0x84
	  addi      r3, r31, 0x394
	  lfs       f0, -0x5514(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x390(r31)
	  lwz       r0, 0x94(r13)
	  stw       r0, 0x1B8(r1)
	  lwz       r0, 0x1B8(r1)
	  stw       r0, 0x84(r1)
	  bl        -0x10516C
	  stw       r30, 0x39C(r31)
	  addi      r5, r1, 0x80
	  addi      r3, r31, 0x3A4
	  lfs       f0, -0x54E0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x3A0(r31)
	  lwz       r0, 0x98(r13)
	  stw       r0, 0x1C0(r1)
	  lwz       r0, 0x1C0(r1)
	  stw       r0, 0x80(r1)
	  bl        -0x105198
	  stw       r30, 0x3AC(r31)
	  addi      r5, r1, 0x7C
	  addi      r3, r31, 0x3B4
	  lfs       f0, -0x54DC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x3B0(r31)
	  lwz       r0, 0x9C(r13)
	  stw       r0, 0x1C8(r1)
	  lwz       r0, 0x1C8(r1)
	  stw       r0, 0x7C(r1)
	  bl        -0x1051C4
	  lis       r3, 0x802A
	  addi      r0, r3, 0x60C4
	  stw       r0, 0x3BC(r31)
	  li        r0, 0xA
	  addi      r3, r31, 0
	  stw       r0, 0x3C0(r31)
	  lfs       f1, -0x54F4(r2)
	  stfs      f1, 0x10(r31)
	  lfs       f0, -0x54D8(r2)
	  stfs      f0, 0x30(r31)
	  stfs      f1, 0x40(r31)
	  lwz       r0, 0x1DC(r1)
	  lwz       r31, 0x1D4(r1)
	  lwz       r30, 0x1D0(r1)
	  addi      r1, r1, 0x1D8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80163C8C
 * Size:	0001D4
 */
Slime::Slime(CreatureProp* props, BossShapeObject* shape)
    : Boss(props)
{
	mCollInfo = new CollInfo(12);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r27, 0x2C(r1)
	  addi      r31, r3, 0
	  addi      r30, r4, 0
	  addi      r27, r5, 0
	  bl        -0x15E30
	  lis       r3, 0x802D
	  subi      r0, r3, 0x3FC
	  stw       r0, 0x0(r31)
	  li        r3, 0x14
	  lfs       f0, -0x54D8(r2)
	  stfs      f0, 0x3E4(r31)
	  stfs      f0, 0x3E0(r31)
	  stfs      f0, 0x3DC(r31)
	  stfs      f0, 0x3F0(r31)
	  stfs      f0, 0x3EC(r31)
	  stfs      f0, 0x3E8(r31)
	  stw       r27, 0x390(r31)
	  bl        -0x11CCD8
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x68
	  li        r4, 0xC
	  bl        -0xDB0C0

	.loc_0x68:
	  stw       r29, 0x220(r31)
	  lwz       r3, 0x3168(r13)
	  lwz       r0, 0x28(r3)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x11CD00
	  stw       r3, 0x3F4(r31)
	  li        r27, 0
	  li        r28, 0
	  b         .loc_0xC8

	.loc_0x8C:
	  li        r3, 0x2EC
	  bl        -0x11CD18
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xA8
	  mr        r4, r30
	  bl        0x7548

	.loc_0xA8:
	  lwz       r3, 0x3F4(r31)
	  addi      r27, r27, 0x1
	  stwx      r29, r3, r28
	  lwz       r3, 0x3F4(r31)
	  lwz       r0, 0x6C(r31)
	  lwzx      r3, r3, r28
	  addi      r28, r28, 0x4
	  stw       r0, 0x6C(r3)

	.loc_0xC8:
	  lwz       r3, 0x3168(r13)
	  lwz       r0, 0x28(r3)
	  cmpw      r27, r0
	  blt+      .loc_0x8C
	  li        r3, 0x24
	  bl        -0x11CD64
	  addi      r29, r3, 0
	  mr.       r27, r29
	  beq-      .loc_0x118
	  lis       r3, 0x802D
	  subi      r0, r3, 0x760
	  stw       r0, 0x0(r29)
	  addi      r3, r27, 0x4
	  bl        -0x11FF2C
	  addi      r3, r27, 0x10
	  bl        -0x11FF34
	  lis       r3, 0x802D
	  subi      r0, r3, 0x230
	  stw       r0, 0x0(r29)
	  stw       r31, 0x1C(r29)

	.loc_0x118:
	  stw       r29, 0x3B8(r31)
	  lwz       r3, 0x3168(r13)
	  lwz       r30, 0x28(r3)
	  mulli     r3, r30, 0x24
	  addi      r3, r3, 0x8
	  bl        -0x11CDB4
	  lis       r4, 0x8016
	  addi      r4, r4, 0x3EB4
	  addi      r7, r30, 0
	  li        r5, 0
	  li        r6, 0x24
	  bl        0xB0E58
	  stw       r3, 0x3BC(r31)
	  lwz       r3, 0x3168(r13)
	  lwz       r30, 0x28(r3)
	  rlwinm    r3,r30,5,0,26
	  addi      r3, r3, 0x8
	  bl        -0x11CDE4
	  lis       r4, 0x8016
	  addi      r4, r4, 0x3E60
	  addi      r7, r30, 0
	  li        r5, 0
	  li        r6, 0x20
	  bl        0xB0E28
	  stw       r3, 0x3C0(r31)
	  li        r3, 0x24
	  bl        -0x11CE08
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x198
	  mr        r4, r31
	  bl        0xD60

	.loc_0x198:
	  stw       r29, 0x400(r31)
	  li        r3, 0x20
	  bl        -0x11CE28
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x1B8
	  mr        r4, r31
	  bl        0x67F0

	.loc_0x1B8:
	  stw       r29, 0x404(r31)
	  mr        r3, r31
	  lmw       r27, 0x2C(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80163E60
 * Size:	000054
 */
Slime::TubeSphereUpdater::TubeSphereUpdater()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  subi      r0, r4, 0x760
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x0(r3)
	  addi      r3, r31, 0x4
	  bl        -0x120028
	  addi      r3, r31, 0x10
	  bl        -0x120030
	  lis       r3, 0x802D
	  subi      r0, r3, 0x268
	  stw       r0, 0x0(r31)
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
 * Address:	80163EB4
 * Size:	000054
 */
Slime::CollideSphereUpdater::CollideSphereUpdater()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  subi      r0, r4, 0x760
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x0(r3)
	  addi      r3, r31, 0x4
	  bl        -0x12007C
	  addi      r3, r31, 0x10
	  bl        -0x120084
	  lis       r3, 0x802D
	  subi      r0, r3, 0x2A0
	  stw       r0, 0x0(r31)
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
 * Address:	80163F08
 * Size:	00000C
 */
f32 Slime::getCentreSize()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x3B8(r3)
	  lfs       f1, 0x20(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80163F14
 * Size:	000008
 */
f32 Slime::getiMass() { return 0.0001f; }

/*
 * --INFO--
 * Address:	80163F1C
 * Size:	00027C
 */
void Slime::init(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  li        r30, 0
	  rlwinm    r31,r30,2,0,29
	  stw       r29, 0x34(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x30(r1)
	  addi      r28, r3, 0
	  lfs       f0, -0x5510(r2)
	  stfs      f0, 0x270(r3)
	  li        r3, 0
	  stb       r3, 0x2BB(r28)
	  stb       r0, 0x3C4(r28)
	  stb       r3, 0x3C5(r28)
	  stw       r3, 0x3C8(r28)
	  lwz       r3, 0x3168(r13)
	  lwz       r3, 0x28(r3)
	  subi      r0, r3, 0x1
	  stw       r0, 0x3CC(r28)
	  lfs       f0, -0x54D8(r2)
	  stfs      f0, 0x3D0(r28)
	  stfs      f0, 0x3D4(r28)
	  lwz       r3, 0x224(r28)
	  lfs       f0, 0x360(r3)
	  stfs      f0, 0x3D8(r28)
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r3, 0x3DC(r28)
	  stw       r0, 0x3E0(r28)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x3E4(r28)
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r3, 0x3E8(r28)
	  stw       r0, 0x3EC(r28)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x3F0(r28)
	  b         .loc_0xC4

	.loc_0xA8:
	  lwz       r3, 0x3F4(r28)
	  addi      r4, r29, 0
	  addi      r5, r28, 0
	  lwzx      r3, r3, r31
	  bl        0x731C
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0xC4:
	  lwz       r3, 0x3168(r13)
	  lwz       r0, 0x28(r3)
	  cmpw      r30, r0
	  blt+      .loc_0xA8
	  lwz       r3, 0x400(r28)
	  mr        r4, r28
	  bl        0xB90
	  lwz       r3, 0x404(r28)
	  mr        r4, r28
	  bl        0x6768
	  lis       r4, 0x6365
	  lwz       r3, 0x220(r28)
	  lwz       r5, 0x3B8(r28)
	  addi      r4, r4, 0x6E74
	  bl        -0xDA360
	  lwz       r3, 0x3F4(r28)
	  lis       r29, 0x7374
	  lwz       r5, 0x3BC(r28)
	  addi      r4, r29, 0x6B31
	  lwz       r0, 0x0(r3)
	  stw       r28, 0x1C(r5)
	  stw       r0, 0x20(r5)
	  lwz       r5, 0x3F4(r28)
	  lwz       r3, 0x3BC(r28)
	  lwz       r0, 0x4(r5)
	  addi      r3, r3, 0x24
	  stw       r28, 0x1C(r3)
	  stw       r0, 0x20(r3)
	  lwz       r5, 0x3F4(r28)
	  lwz       r3, 0x3BC(r28)
	  lwz       r0, 0x8(r5)
	  addi      r3, r3, 0x48
	  stw       r28, 0x1C(r3)
	  stw       r0, 0x20(r3)
	  lwz       r5, 0x3F4(r28)
	  lwz       r3, 0x3BC(r28)
	  lwz       r0, 0xC(r5)
	  addi      r3, r3, 0x6C
	  stw       r28, 0x1C(r3)
	  stw       r0, 0x20(r3)
	  lwz       r3, 0x220(r28)
	  lwz       r5, 0x3BC(r28)
	  bl        -0xDA3D0
	  lwz       r5, 0x3BC(r28)
	  addi      r4, r29, 0x6B32
	  lwz       r3, 0x220(r28)
	  addi      r5, r5, 0x24
	  bl        -0xDA3E4
	  lwz       r5, 0x3BC(r28)
	  addi      r4, r29, 0x6B33
	  lwz       r3, 0x220(r28)
	  addi      r5, r5, 0x48
	  bl        -0xDA3F8
	  lwz       r5, 0x3BC(r28)
	  addi      r4, r29, 0x6B34
	  lwz       r3, 0x220(r28)
	  addi      r5, r5, 0x6C
	  bl        -0xDA40C
	  lwz       r3, 0x220(r28)
	  addi      r4, r29, 0x6B31
	  bl        -0xDA9C0
	  lwz       r5, 0x3C0(r28)
	  addi      r4, r29, 0x6B32
	  stw       r3, 0x1C(r5)
	  lwz       r3, 0x220(r28)
	  bl        -0xDA9D4
	  lwz       r5, 0x3C0(r28)
	  addi      r4, r29, 0x6B33
	  stw       r3, 0x3C(r5)
	  lwz       r3, 0x220(r28)
	  bl        -0xDA9E8
	  lwz       r5, 0x3C0(r28)
	  addi      r4, r29, 0x6B34
	  stw       r3, 0x5C(r5)
	  lwz       r3, 0x220(r28)
	  bl        -0xDA9FC
	  lwz       r5, 0x3C0(r28)
	  lis       r29, 0x7475
	  addi      r4, r29, 0x6231
	  stw       r3, 0x7C(r5)
	  lwz       r3, 0x220(r28)
	  lwz       r5, 0x3C0(r28)
	  bl        -0xDA470
	  lwz       r5, 0x3C0(r28)
	  addi      r4, r29, 0x6232
	  lwz       r3, 0x220(r28)
	  addi      r5, r5, 0x20
	  bl        -0xDA484
	  lwz       r5, 0x3C0(r28)
	  addi      r4, r29, 0x6233
	  lwz       r3, 0x220(r28)
	  addi      r5, r5, 0x40
	  bl        -0xDA498
	  lwz       r5, 0x3C0(r28)
	  addi      r4, r29, 0x6234
	  lwz       r3, 0x220(r28)
	  addi      r5, r5, 0x60
	  bl        -0xDA4AC
	  lwz       r3, 0x220(r28)
	  addi      r4, r29, 0x6231
	  li        r5, 0x3
	  bl        -0xDA56C
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
 * Address:	80164198
 * Size:	000034
 */
void Slime::doKill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  stb       r0, 0x2B8(r3)
	  stb       r0, 0x2B9(r3)
	  lwz       r3, 0x3168(r13)
	  bl        -0x12020
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801641CC
 * Size:	000004
 */
void Slime::exitCourse() { }

/*
 * --INFO--
 * Address:	801641D0
 * Size:	0000A4
 */
void Slime::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x104(r12)
	  mtlr      r12
	  blrl
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x60

	.loc_0x38:
	  lwz       r3, 0x3F4(r29)
	  lwzx      r3, r3, r31
	  cmplwi    r3, 0
	  beq-      .loc_0x58
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xE0(r12)
	  mtlr      r12
	  blrl

	.loc_0x58:
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x60:
	  lwz       r3, 0x3168(r13)
	  lwz       r0, 0x28(r3)
	  cmpw      r30, r0
	  blt+      .loc_0x38
	  mr        r3, r29
	  bl        -0xD7248
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r29
	  lfs       f1, 0x28C(r4)
	  bl        -0xD5C78
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
 * Address:	80164274
 * Size:	0000A8
 */
void Slime::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  addi      r3, r30, 0x228
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  bl        -0x1261AC
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x10
	  addi      r3, r3, 0x1E0
	  bl        -0x1261E0
	  addi      r3, r30, 0x33C
	  lwz       r12, 0x36C(r30)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x390(r30)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x10
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0x12EFCC
	  lwz       r3, 0x404(r30)
	  mr        r5, r31
	  lwz       r4, 0x390(r30)
	  bl        0x6E70
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0xDA814
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
 * Address:	8016431C
 * Size:	0000A0
 */
void Slime::drawShape(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x108(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lfs       f1, 0x3D4(r30)
	  lfs       f0, -0x54D8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x88
	  lwz       r3, 0x390(r30)
	  addi      r4, r31, 0
	  li        r6, 0
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x13C(r3)
	  ori       r0, r0, 0x3
	  stw       r0, 0x13C(r3)
	  lwz       r3, 0x390(r30)
	  lwz       r5, 0x2E4(r31)
	  lwz       r3, 0x0(r3)
	  bl        -0x133F34

	.loc_0x88:
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
 * Address:	801643BC
 * Size:	000024
 */
void Slime::doAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x400(r3)
	  bl        0x34A8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801643E0
 * Size:	000024
 */
void Slime::doAnimation()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x404(r3)
	  bl        0x690C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80164404
 * Size:	000168
 */
void Slime::collisionCallback(CollEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r4
	  stw       r30, 0x48(r1)
	  mr        r30, r3
	  lwz       r4, 0x0(r4)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x34
	  cmpwi     r0, 0x36
	  bne-      .loc_0x150

	.loc_0x34:
	  mr        r3, r4
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x150
	  lwz       r3, 0x0(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x150
	  lwz       r3, 0x0(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x150
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xD8
	  lis       r3, 0x802B
	  lfs       f0, -0x550C(r2)
	  subi      r0, r3, 0x3064
	  stw       r0, 0x38(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3090
	  stw       r30, 0x3C(r1)
	  addi      r4, r1, 0x38
	  stw       r0, 0x38(r1)
	  stfs      f0, 0x40(r1)
	  lwz       r3, 0x0(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x130

	.loc_0xD8:
	  cmpwi     r0, 0x36
	  bne-      .loc_0x130
	  lwz       r6, 0x224(r30)
	  lis       r4, 0x802B
	  subi      r5, r4, 0x3064
	  lfs       f0, -0x54D0(r2)
	  lfs       f2, 0x138(r6)
	  lfs       f1, 0x128(r6)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3168
	  stw       r5, 0x24(r1)
	  addi      r4, r1, 0x24
	  stw       r30, 0x28(r1)
	  stw       r0, 0x24(r1)
	  stfs      f1, 0x2C(r1)
	  stfs      f2, 0x30(r1)
	  stfs      f0, 0x34(r1)
	  lwz       r3, 0x0(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x130:
	  mr        r3, r30
	  bl        -0x15178
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x150
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x32
	  addi      r3, r3, 0x70
	  bl        -0xE0B50

	.loc_0x150:
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
 * Address:	8016456C
 * Size:	000020
 */
void Slime::CollideSphereUpdater::getPos()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x20(r4)
	  lfsu      f0, 0x94(r4)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r4)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016458C
 * Size:	000440
 */
void Slime::CollideSphereUpdater::getSize()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x188(r1)
	  stfd      f31, 0x180(r1)
	  stfd      f30, 0x178(r1)
	  stfd      f29, 0x170(r1)
	  stfd      f28, 0x168(r1)
	  stfd      f27, 0x160(r1)
	  stfd      f26, 0x158(r1)
	  stfd      f25, 0x150(r1)
	  stmw      r26, 0x138(r1)
	  mr        r26, r3
	  addi      r28, r1, 0x104
	  addi      r31, r1, 0x68
	  addi      r30, r1, 0x64
	  addi      r29, r1, 0x60
	  li        r27, 0
	  lfs       f27, -0x54D8(r2)
	  stfs      f27, 0x10C(r1)
	  stfs      f27, 0x108(r1)
	  stfs      f27, 0x104(r1)
	  lfs       f1, 0x10(r13)
	  stfs      f27, 0x118(r1)
	  lfs       f0, 0x14(r13)
	  stfs      f27, 0x114(r1)
	  stfs      f27, 0x110(r1)
	  stfs      f27, 0x124(r1)
	  stfs      f27, 0x120(r1)
	  stfs      f27, 0x11C(r1)
	  stfs      f27, 0x130(r1)
	  stfs      f27, 0x12C(r1)
	  stfs      f27, 0x128(r1)
	  stfs      f1, 0x104(r1)
	  stfs      f0, 0x108(r1)
	  lfs       f0, 0x18(r13)
	  stfs      f0, 0x10C(r1)
	  lfs       f0, 0x1C(r13)
	  stfs      f0, 0x110(r1)
	  lfs       f0, 0x20(r13)
	  stfs      f0, 0x114(r1)
	  lfs       f0, 0x24(r13)
	  stfs      f0, 0x118(r1)
	  lfs       f0, 0x104(r1)
	  lfs       f31, -0x54C8(r2)
	  fneg      f0, f0
	  lfd       f29, -0x54C0(r2)
	  lfd       f30, -0x54B8(r2)
	  lfs       f28, -0x54DC(r2)
	  stfs      f0, 0xA0(r1)
	  lfs       f0, 0xA0(r1)
	  stfs      f0, 0xD0(r1)
	  lfs       f0, 0x108(r1)
	  fneg      f0, f0
	  stfs      f0, 0xD4(r1)
	  lfs       f0, 0x10C(r1)
	  fneg      f0, f0
	  stfs      f0, 0xD8(r1)
	  lwz       r0, 0xD0(r1)
	  lwz       r3, 0xD4(r1)
	  stw       r0, 0x11C(r1)
	  lwz       r0, 0xD8(r1)
	  stw       r3, 0x120(r1)
	  stw       r0, 0x124(r1)
	  lfs       f0, 0x110(r1)
	  fneg      f0, f0
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x94(r1)
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0x114(r1)
	  fneg      f0, f0
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0x118(r1)
	  fneg      f0, f0
	  stfs      f0, 0xCC(r1)
	  lwz       r0, 0xC4(r1)
	  lwz       r3, 0xC8(r1)
	  stw       r0, 0x128(r1)
	  lwz       r0, 0xCC(r1)
	  stw       r3, 0x12C(r1)
	  stw       r0, 0x130(r1)

	.loc_0x140:
	  lwz       r3, 0x1C(r26)
	  mr        r4, r29
	  lfs       f1, 0x8(r28)
	  mr        r5, r30
	  lwz       r3, 0x224(r3)
	  addi      r6, r31, 0
	  addi      r7, r3, 0x370
	  lfs       f0, 0x370(r3)
	  addi      r3, r1, 0xAC
	  fmuls     f0, f1, f0
	  stfs      f0, 0x68(r1)
	  lfs       f1, 0x4(r28)
	  lfs       f0, 0x0(r7)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x64(r1)
	  lfs       f1, 0x0(r28)
	  lfs       f0, 0x0(r7)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x60(r1)
	  bl        -0x12D5FC
	  lwz       r3, 0x20(r26)
	  li        r5, 0
	  lfs       f1, 0xB4(r1)
	  addi      r3, r3, 0x94
	  lfs       f0, 0xB0(r1)
	  lfs       f8, 0x8(r3)
	  lfs       f7, 0x4(r3)
	  fadds     f2, f8, f1
	  lfs       f6, 0x0(r3)
	  fadds     f1, f7, f0
	  lfs       f0, 0xAC(r1)
	  fadds     f0, f6, f0
	  fmr       f4, f1
	  fmr       f5, f2
	  fmr       f3, f0
	  b         .loc_0x378

	.loc_0x1D0:
	  fadds     f0, f3, f6
	  li        r0, 0x2
	  fadds     f1, f4, f7
	  mtctr     r0
	  fadds     f2, f5, f8
	  fmuls     f0, f0, f28
	  lfs       f9, -0x54D8(r2)
	  fmuls     f1, f1, f28
	  li        r6, 0
	  fmuls     f2, f2, f28
	  li        r4, 0

	.loc_0x1FC:
	  lwz       r3, 0x1C(r26)
	  lwz       r3, 0x3F4(r3)
	  lwzx      r3, r3, r4
	  lfs       f13, 0x94(r3)
	  lfs       f12, 0x98(r3)
	  fsubs     f13, f0, f13
	  lfs       f11, 0x9C(r3)
	  fsubs     f26, f1, f12
	  fsubs     f25, f2, f11
	  fmuls     f12, f13, f13
	  fmuls     f11, f26, f26
	  fmuls     f13, f25, f25
	  fadds     f10, f12, f11
	  fadds     f12, f13, f10
	  fcmpo     cr0, f12, f27
	  ble-      .loc_0x28C
	  fsqrte    f11, f12
	  fmul      f10, f11, f11
	  fmul      f11, f29, f11
	  fmul      f10, f12, f10
	  fsub      f10, f30, f10
	  fmul      f11, f11, f10
	  fmul      f10, f11, f11
	  fmul      f11, f29, f11
	  fmul      f10, f12, f10
	  fsub      f10, f30, f10
	  fmul      f11, f11, f10
	  fmul      f10, f11, f11
	  fmul      f11, f29, f11
	  fmul      f10, f12, f10
	  fsub      f10, f30, f10
	  fmul      f10, f11, f10
	  fmul      f10, f12, f10
	  frsp      f10, f10
	  stfs      f10, 0x8C(r1)
	  lfs       f12, 0x8C(r1)

	.loc_0x28C:
	  lwz       r3, 0x1C(r26)
	  addi      r4, r4, 0x4
	  lfs       f10, 0x3D4(r3)
	  lwz       r3, 0x3F4(r3)
	  fdivs     f10, f10, f12
	  lwzx      r3, r3, r4
	  lfs       f13, 0x94(r3)
	  lfs       f12, 0x98(r3)
	  lfs       f11, 0x9C(r3)
	  fsubs     f13, f0, f13
	  fsubs     f26, f1, f12
	  fsubs     f25, f2, f11
	  fmuls     f12, f13, f13
	  fmuls     f11, f26, f26
	  fadds     f9, f9, f10
	  fmuls     f13, f25, f25
	  fadds     f10, f12, f11
	  fadds     f12, f13, f10
	  fcmpo     cr0, f12, f27
	  ble-      .loc_0x32C
	  fsqrte    f11, f12
	  fmul      f10, f11, f11
	  fmul      f11, f29, f11
	  fmul      f10, f12, f10
	  fsub      f10, f30, f10
	  fmul      f11, f11, f10
	  fmul      f10, f11, f11
	  fmul      f11, f29, f11
	  fmul      f10, f12, f10
	  fsub      f10, f30, f10
	  fmul      f11, f11, f10
	  fmul      f10, f11, f11
	  fmul      f11, f29, f11
	  fmul      f10, f12, f10
	  fsub      f10, f30, f10
	  fmul      f10, f11, f10
	  fmul      f10, f12, f10
	  frsp      f10, f10
	  stfs      f10, 0x8C(r1)
	  lfs       f12, 0x8C(r1)

	.loc_0x32C:
	  lwz       r3, 0x1C(r26)
	  addi      r4, r4, 0x4
	  addi      r6, r6, 0x1
	  lfs       f10, 0x3D4(r3)
	  fdivs     f10, f10, f12
	  fadds     f9, f9, f10
	  bdnz+     .loc_0x1FC
	  lwz       r3, 0x224(r3)
	  lfs       f10, 0x390(r3)
	  fcmpo     cr0, f9, f10
	  ble-      .loc_0x368
	  fmr       f6, f0
	  fmr       f7, f1
	  fmr       f8, f2
	  b         .loc_0x374

	.loc_0x368:
	  fmr       f3, f0
	  fmr       f4, f1
	  fmr       f5, f2

	.loc_0x374:
	  addi      r5, r5, 0x1

	.loc_0x378:
	  lwz       r3, 0x1C(r26)
	  lwz       r3, 0x224(r3)
	  lwz       r0, 0x3C0(r3)
	  cmpw      r5, r0
	  blt+      .loc_0x1D0
	  lwz       r3, 0x20(r26)
	  stfs      f27, 0x80(r1)
	  stfs      f27, 0x7C(r1)
	  stfs      f27, 0x78(r1)
	  lfsu      f3, 0x94(r3)
	  fsubs     f0, f3, f0
	  lfs       f4, 0x8(r3)
	  lfs       f3, 0x4(r3)
	  fsubs     f2, f4, f2
	  stfs      f0, 0x74(r1)
	  fsubs     f1, f3, f1
	  lfs       f0, 0x74(r1)
	  stfs      f0, 0x78(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f2, 0x80(r1)
	  lfs       f1, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x80(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x156D34
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x3F8
	  fmr       f31, f1

	.loc_0x3F8:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x4
	  addi      r28, r28, 0xC
	  blt+      .loc_0x140
	  lmw       r26, 0x138(r1)
	  lfs       f0, -0x54CC(r2)
	  lwz       r0, 0x18C(r1)
	  fsubs     f1, f31, f0
	  lfd       f31, 0x180(r1)
	  lfd       f30, 0x178(r1)
	  lfd       f29, 0x170(r1)
	  lfd       f28, 0x168(r1)
	  lfd       f27, 0x160(r1)
	  lfd       f26, 0x158(r1)
	  lfd       f25, 0x150(r1)
	  addi      r1, r1, 0x188
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801649CC
 * Size:	000020
 */
void Slime::TubeSphereUpdater::getPos()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x1C(r4)
	  lfsu      f0, 0x4(r4)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r4)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801649EC
 * Size:	00000C
 */
void Slime::TubeSphereUpdater::getSize()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x1C(r3)
	  lfs       f1, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801649F8
 * Size:	000020
 */
void Slime::BoundSphereUpdater::getPos()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x1C(r4)
	  lfsu      f0, 0x94(r4)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r4)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80164A18
 * Size:	000110
 */
void Slime::BoundSphereUpdater::getSize()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stw       r31, 0x44(r1)
	  li        r31, 0
	  stw       r30, 0x40(r1)
	  li        r30, 0
	  stw       r29, 0x3C(r1)
	  mr        r29, r3
	  lfs       f31, -0x54D8(r2)
	  stfs      f31, 0x20(r3)
	  b         .loc_0xCC

	.loc_0x34:
	  lwz       r5, 0x1C(r29)
	  lwz       r3, 0x3F4(r5)
	  lwzx      r3, r3, r31
	  cmplwi    r3, 0
	  beq-      .loc_0xC4
	  stfs      f31, 0x30(r1)
	  addi      r4, r3, 0x94
	  stfs      f31, 0x2C(r1)
	  stfs      f31, 0x28(r1)
	  lfs       f1, 0x94(r3)
	  lfs       f0, 0x94(r5)
	  lfs       f4, 0x8(r4)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r5)
	  lfs       f2, 0x4(r4)
	  lfs       f1, 0x98(r5)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x24(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x24(r1)
	  stfs      f0, 0x28(r1)
	  stfs      f1, 0x2C(r1)
	  stfs      f3, 0x30(r1)
	  lfs       f1, 0x28(r1)
	  lfs       f0, 0x2C(r1)
	  lfs       f2, 0x30(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x156E88
	  lfs       f0, 0x20(r29)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xC4
	  stfs      f1, 0x20(r29)

	.loc_0xC4:
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0xCC:
	  lwz       r3, 0x3168(r13)
	  lwz       r0, 0x28(r3)
	  cmpw      r30, r0
	  blt+      .loc_0x34
	  lfs       f1, 0x20(r29)
	  lfs       f0, -0x54B0(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r29)
	  lfs       f1, 0x20(r29)
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80164B28
 * Size:	000050
 */
void SlimeProp::read(RandomAccessStream&)
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
	  bl        -0x105FAC
	  addi      r3, r30, 0x58
	  addi      r4, r31, 0
	  bl        -0x105FB8
	  addi      r3, r30, 0x200
	  addi      r4, r31, 0
	  bl        -0x105FC4
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
