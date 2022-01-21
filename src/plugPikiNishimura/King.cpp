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
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8016B4A4
 * Size:	0007BC
 */
KingProp::KingProp()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2C8(r1)
	  stmw      r26, 0x2B0(r1)
	  mr        r31, r3
	  bl        -0x1DBEC
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x1EC(r31)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x1EC(r31)
	  li        r29, 0
	  lis       r3, 0x802D
	  stw       r29, 0x1FC(r31)
	  addi      r6, r3, 0x394
	  lis       r4, 0x802D
	  stw       r29, 0x1F8(r31)
	  addi      r3, r4, 0xB4
	  addi      r0, r6, 0xC
	  stw       r29, 0x1F4(r31)
	  addi      r5, r1, 0x158
	  addi      r4, r31, 0x200
	  stw       r3, 0x1F0(r31)
	  addi      r3, r31, 0x204
	  stw       r6, 0x54(r31)
	  stw       r0, 0x1EC(r31)
	  stw       r29, 0x200(r31)
	  lwz       r0, 0x1C0(r13)
	  stw       r0, 0x160(r1)
	  lwz       r0, 0x160(r1)
	  stw       r0, 0x158(r1)
	  bl        -0x10CAA4
	  lis       r3, 0x802A
	  addi      r30, r3, 0x6098
	  stw       r30, 0x20C(r31)
	  addi      r5, r1, 0x154
	  addi      r3, r31, 0x214
	  lfs       f0, -0x53F8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x210(r31)
	  lwz       r0, 0x1C4(r13)
	  stw       r0, 0x168(r1)
	  lwz       r0, 0x168(r1)
	  stw       r0, 0x154(r1)
	  bl        -0x10CAD8
	  stw       r30, 0x21C(r31)
	  addi      r5, r1, 0x150
	  addi      r3, r31, 0x224
	  lfs       f0, -0x53F4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x220(r31)
	  lwz       r0, 0x1C8(r13)
	  stw       r0, 0x170(r1)
	  lwz       r0, 0x170(r1)
	  stw       r0, 0x150(r1)
	  bl        -0x10CB04
	  stw       r30, 0x22C(r31)
	  addi      r5, r1, 0x14C
	  addi      r3, r31, 0x234
	  lfs       f0, -0x53F4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x230(r31)
	  lwz       r0, 0x1CC(r13)
	  stw       r0, 0x178(r1)
	  lwz       r0, 0x178(r1)
	  stw       r0, 0x14C(r1)
	  bl        -0x10CB30
	  stw       r30, 0x23C(r31)
	  addi      r5, r1, 0x148
	  addi      r3, r31, 0x244
	  lfs       f0, -0x53F0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x240(r31)
	  lwz       r0, 0x1D0(r13)
	  stw       r0, 0x180(r1)
	  lwz       r0, 0x180(r1)
	  stw       r0, 0x148(r1)
	  bl        -0x10CB5C
	  stw       r30, 0x24C(r31)
	  addi      r5, r1, 0x144
	  addi      r3, r31, 0x254
	  lfs       f0, -0x53EC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x250(r31)
	  lwz       r0, 0x1D4(r13)
	  stw       r0, 0x188(r1)
	  lwz       r0, 0x188(r1)
	  stw       r0, 0x144(r1)
	  bl        -0x10CB88
	  stw       r30, 0x25C(r31)
	  addi      r5, r1, 0x140
	  addi      r3, r31, 0x264
	  lfs       f0, -0x53E8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x260(r31)
	  lwz       r0, 0x1D8(r13)
	  stw       r0, 0x190(r1)
	  lwz       r0, 0x190(r1)
	  stw       r0, 0x140(r1)
	  bl        -0x10CBB4
	  stw       r30, 0x26C(r31)
	  addi      r5, r1, 0x13C
	  addi      r3, r31, 0x274
	  lfs       f0, -0x53EC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x270(r31)
	  lwz       r0, 0x1DC(r13)
	  stw       r0, 0x198(r1)
	  lwz       r0, 0x198(r1)
	  stw       r0, 0x13C(r1)
	  bl        -0x10CBE0
	  stw       r30, 0x27C(r31)
	  addi      r5, r1, 0x138
	  addi      r3, r31, 0x284
	  lfs       f0, -0x53EC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x280(r31)
	  lwz       r0, 0x1E0(r13)
	  stw       r0, 0x1A0(r1)
	  lwz       r0, 0x1A0(r1)
	  stw       r0, 0x138(r1)
	  bl        -0x10CC0C
	  stw       r30, 0x28C(r31)
	  addi      r5, r1, 0x134
	  addi      r3, r31, 0x294
	  lfs       f0, -0x53E4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x290(r31)
	  lwz       r0, 0x1E4(r13)
	  stw       r0, 0x1A8(r1)
	  lwz       r0, 0x1A8(r1)
	  stw       r0, 0x134(r1)
	  bl        -0x10CC38
	  stw       r30, 0x29C(r31)
	  addi      r5, r1, 0x130
	  addi      r3, r31, 0x2A4
	  lfs       f0, -0x53F8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2A0(r31)
	  lwz       r0, 0x1E8(r13)
	  stw       r0, 0x1B0(r1)
	  lwz       r0, 0x1B0(r1)
	  stw       r0, 0x130(r1)
	  bl        -0x10CC64
	  stw       r30, 0x2AC(r31)
	  addi      r5, r1, 0x12C
	  addi      r3, r31, 0x2B4
	  lfs       f0, -0x53E8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2B0(r31)
	  lwz       r0, 0x1EC(r13)
	  stw       r0, 0x1B8(r1)
	  lwz       r0, 0x1B8(r1)
	  stw       r0, 0x12C(r1)
	  bl        -0x10CC90
	  stw       r30, 0x2BC(r31)
	  addi      r5, r1, 0x128
	  addi      r3, r31, 0x2C4
	  lfs       f0, -0x53E0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2C0(r31)
	  lwz       r0, 0x1F0(r13)
	  stw       r0, 0x1C0(r1)
	  lwz       r0, 0x1C0(r1)
	  stw       r0, 0x128(r1)
	  bl        -0x10CCBC
	  stw       r30, 0x2CC(r31)
	  addi      r5, r1, 0x124
	  addi      r3, r31, 0x2D4
	  lfs       f0, -0x53DC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2D0(r31)
	  lwz       r0, 0x1F4(r13)
	  stw       r0, 0x1C8(r1)
	  lwz       r0, 0x1C8(r1)
	  stw       r0, 0x124(r1)
	  bl        -0x10CCE8
	  stw       r30, 0x2DC(r31)
	  addi      r5, r1, 0x120
	  addi      r3, r31, 0x2E4
	  lfs       f0, -0x53D8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2E0(r31)
	  lwz       r0, 0x1F8(r13)
	  stw       r0, 0x1D0(r1)
	  lwz       r0, 0x1D0(r1)
	  stw       r0, 0x120(r1)
	  bl        -0x10CD14
	  stw       r30, 0x2EC(r31)
	  addi      r5, r1, 0x11C
	  addi      r3, r31, 0x2F4
	  lfs       f0, -0x53D4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2F0(r31)
	  lwz       r0, 0x1FC(r13)
	  stw       r0, 0x1D8(r1)
	  lwz       r0, 0x1D8(r1)
	  stw       r0, 0x11C(r1)
	  bl        -0x10CD40
	  stw       r30, 0x2FC(r31)
	  addi      r5, r1, 0x118
	  addi      r3, r31, 0x304
	  lfs       f0, -0x53D0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x300(r31)
	  lwz       r0, 0x200(r13)
	  stw       r0, 0x1E0(r1)
	  lwz       r0, 0x1E0(r1)
	  stw       r0, 0x118(r1)
	  bl        -0x10CD6C
	  stw       r30, 0x30C(r31)
	  addi      r5, r1, 0x114
	  addi      r3, r31, 0x314
	  lfs       f0, -0x53CC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x310(r31)
	  lwz       r0, 0x204(r13)
	  stw       r0, 0x1E8(r1)
	  lwz       r0, 0x1E8(r1)
	  stw       r0, 0x114(r1)
	  bl        -0x10CD98
	  stw       r30, 0x31C(r31)
	  addi      r5, r1, 0x110
	  addi      r3, r31, 0x324
	  lfs       f0, -0x53C8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x320(r31)
	  lwz       r0, 0x208(r13)
	  stw       r0, 0x1F0(r1)
	  lwz       r0, 0x1F0(r1)
	  stw       r0, 0x110(r1)
	  bl        -0x10CDC4
	  stw       r30, 0x32C(r31)
	  addi      r5, r1, 0x10C
	  addi      r3, r31, 0x334
	  lfs       f0, -0x53E0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x330(r31)
	  lwz       r0, 0x20C(r13)
	  stw       r0, 0x1F8(r1)
	  lwz       r0, 0x1F8(r1)
	  stw       r0, 0x10C(r1)
	  bl        -0x10CDF0
	  stw       r30, 0x33C(r31)
	  addi      r5, r1, 0x108
	  addi      r3, r31, 0x344
	  lfs       f0, -0x53E0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x340(r31)
	  lwz       r0, 0x210(r13)
	  stw       r0, 0x200(r1)
	  lwz       r0, 0x200(r1)
	  stw       r0, 0x108(r1)
	  bl        -0x10CE1C
	  stw       r30, 0x34C(r31)
	  addi      r5, r1, 0x104
	  addi      r3, r31, 0x354
	  lfs       f0, -0x53C4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x350(r31)
	  lwz       r0, 0x214(r13)
	  stw       r0, 0x208(r1)
	  lwz       r0, 0x208(r1)
	  stw       r0, 0x104(r1)
	  bl        -0x10CE48
	  stw       r30, 0x35C(r31)
	  addi      r5, r1, 0x100
	  addi      r3, r31, 0x364
	  lfs       f0, -0x53C0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x360(r31)
	  lwz       r0, 0x218(r13)
	  stw       r0, 0x210(r1)
	  lwz       r0, 0x210(r1)
	  stw       r0, 0x100(r1)
	  bl        -0x10CE74
	  stw       r30, 0x36C(r31)
	  addi      r5, r1, 0xFC
	  addi      r3, r31, 0x374
	  lfs       f0, -0x53F4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x370(r31)
	  lwz       r0, 0x21C(r13)
	  stw       r0, 0x218(r1)
	  lwz       r0, 0x218(r1)
	  stw       r0, 0xFC(r1)
	  bl        -0x10CEA0
	  stw       r30, 0x37C(r31)
	  addi      r5, r1, 0xF8
	  addi      r3, r31, 0x384
	  lfs       f0, -0x53F4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x380(r31)
	  lwz       r0, 0x220(r13)
	  stw       r0, 0x220(r1)
	  lwz       r0, 0x220(r1)
	  stw       r0, 0xF8(r1)
	  bl        -0x10CECC
	  stw       r30, 0x38C(r31)
	  addi      r5, r1, 0xF4
	  addi      r3, r31, 0x394
	  lfs       f0, -0x53BC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x390(r31)
	  lwz       r0, 0x224(r13)
	  stw       r0, 0x228(r1)
	  lwz       r0, 0x228(r1)
	  stw       r0, 0xF4(r1)
	  bl        -0x10CEF8
	  stw       r30, 0x39C(r31)
	  addi      r5, r1, 0xF0
	  addi      r3, r31, 0x3A4
	  lfs       f0, -0x53B8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x3A0(r31)
	  lwz       r0, 0x228(r13)
	  stw       r0, 0x230(r1)
	  lwz       r0, 0x230(r1)
	  stw       r0, 0xF0(r1)
	  bl        -0x10CF24
	  stw       r30, 0x3AC(r31)
	  addi      r5, r1, 0xEC
	  addi      r3, r31, 0x3B4
	  lfs       f0, -0x53B4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x3B0(r31)
	  lwz       r0, 0x22C(r13)
	  stw       r0, 0x238(r1)
	  lwz       r0, 0x238(r1)
	  stw       r0, 0xEC(r1)
	  bl        -0x10CF50
	  stw       r30, 0x3BC(r31)
	  addi      r5, r1, 0xE8
	  addi      r3, r31, 0x3C4
	  lfs       f0, -0x53B0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x3C0(r31)
	  lwz       r0, 0x230(r13)
	  stw       r0, 0x240(r1)
	  lwz       r0, 0x240(r1)
	  stw       r0, 0xE8(r1)
	  bl        -0x10CF7C
	  stw       r30, 0x3CC(r31)
	  addi      r5, r1, 0xE4
	  addi      r3, r31, 0x3D4
	  lfs       f0, -0x53AC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x3D0(r31)
	  lwz       r0, 0x234(r13)
	  stw       r0, 0x248(r1)
	  lwz       r0, 0x248(r1)
	  stw       r0, 0xE4(r1)
	  bl        -0x10CFA8
	  lis       r3, 0x802A
	  addi      r30, r3, 0x60C4
	  stw       r30, 0x3DC(r31)
	  li        r0, 0x64
	  addi      r5, r1, 0xE0
	  stw       r0, 0x3E0(r31)
	  addi      r3, r31, 0x3E4
	  addi      r4, r31, 0x200
	  lwz       r0, 0x238(r13)
	  stw       r0, 0x250(r1)
	  lwz       r0, 0x250(r1)
	  stw       r0, 0xE0(r1)
	  bl        -0x10CFDC
	  stw       r30, 0x3EC(r31)
	  addi      r5, r1, 0xDC
	  addi      r3, r31, 0x3F4
	  stw       r29, 0x3F0(r31)
	  addi      r4, r31, 0x200
	  lwz       r0, 0x23C(r13)
	  stw       r0, 0x258(r1)
	  lwz       r0, 0x258(r1)
	  stw       r0, 0xDC(r1)
	  bl        -0x10D004
	  stw       r30, 0x3FC(r31)
	  li        r26, 0xA
	  addi      r5, r1, 0xD8
	  stw       r26, 0x400(r31)
	  addi      r3, r31, 0x404
	  addi      r4, r31, 0x200
	  lwz       r0, 0x240(r13)
	  stw       r0, 0x260(r1)
	  lwz       r0, 0x260(r1)
	  stw       r0, 0xD8(r1)
	  bl        -0x10D030
	  stw       r30, 0x40C(r31)
	  li        r27, 0x4
	  addi      r5, r1, 0xD4
	  stw       r27, 0x410(r31)
	  addi      r3, r31, 0x414
	  addi      r4, r31, 0x200
	  lwz       r0, 0x244(r13)
	  stw       r0, 0x268(r1)
	  lwz       r0, 0x268(r1)
	  stw       r0, 0xD4(r1)
	  bl        -0x10D05C
	  stw       r30, 0x41C(r31)
	  addi      r5, r1, 0xD0
	  addi      r3, r31, 0x424
	  stw       r27, 0x420(r31)
	  addi      r4, r31, 0x200
	  lwz       r0, 0x248(r13)
	  stw       r0, 0x270(r1)
	  lwz       r0, 0x270(r1)
	  stw       r0, 0xD0(r1)
	  bl        -0x10D084
	  stw       r30, 0x42C(r31)
	  li        r28, 0x6
	  addi      r5, r1, 0xCC
	  stw       r28, 0x430(r31)
	  addi      r3, r31, 0x434
	  addi      r4, r31, 0x200
	  lwz       r0, 0x24C(r13)
	  stw       r0, 0x278(r1)
	  lwz       r0, 0x278(r1)
	  stw       r0, 0xCC(r1)
	  bl        -0x10D0B0
	  stw       r30, 0x43C(r31)
	  addi      r5, r1, 0xC8
	  addi      r3, r31, 0x444
	  stw       r29, 0x440(r31)
	  addi      r4, r31, 0x200
	  lwz       r0, 0x250(r13)
	  stw       r0, 0x280(r1)
	  lwz       r0, 0x280(r1)
	  stw       r0, 0xC8(r1)
	  bl        -0x10D0D8
	  stw       r30, 0x44C(r31)
	  addi      r5, r1, 0xC4
	  addi      r3, r31, 0x454
	  stw       r26, 0x450(r31)
	  addi      r4, r31, 0x200
	  lwz       r0, 0x254(r13)
	  stw       r0, 0x288(r1)
	  lwz       r0, 0x288(r1)
	  stw       r0, 0xC4(r1)
	  bl        -0x10D100
	  stw       r30, 0x45C(r31)
	  addi      r5, r1, 0xC0
	  addi      r3, r31, 0x464
	  stw       r27, 0x460(r31)
	  addi      r4, r31, 0x200
	  lwz       r0, 0x258(r13)
	  stw       r0, 0x290(r1)
	  lwz       r0, 0x290(r1)
	  stw       r0, 0xC0(r1)
	  bl        -0x10D128
	  stw       r30, 0x46C(r31)
	  addi      r5, r1, 0xBC
	  addi      r3, r31, 0x474
	  stw       r27, 0x470(r31)
	  addi      r4, r31, 0x200
	  lwz       r0, 0x25C(r13)
	  stw       r0, 0x298(r1)
	  lwz       r0, 0x298(r1)
	  stw       r0, 0xBC(r1)
	  bl        -0x10D150
	  stw       r30, 0x47C(r31)
	  addi      r5, r1, 0xB8
	  addi      r3, r31, 0x484
	  stw       r28, 0x480(r31)
	  addi      r4, r31, 0x200
	  lwz       r0, 0x260(r13)
	  stw       r0, 0x2A0(r1)
	  lwz       r0, 0x2A0(r1)
	  stw       r0, 0xB8(r1)
	  bl        -0x10D178
	  stw       r30, 0x48C(r31)
	  li        r0, 0x2
	  addi      r5, r1, 0xB4
	  stw       r0, 0x490(r31)
	  addi      r3, r31, 0x494
	  addi      r4, r31, 0x200
	  lwz       r0, 0x264(r13)
	  stw       r0, 0x2A8(r1)
	  lwz       r0, 0x2A8(r1)
	  stw       r0, 0xB4(r1)
	  bl        -0x10D1A4
	  stw       r30, 0x49C(r31)
	  li        r0, 0x3
	  addi      r3, r31, 0
	  stw       r0, 0x4A0(r31)
	  lfs       f1, -0x53A8(r2)
	  stfs      f1, 0x10(r31)
	  lfs       f0, -0x53CC(r2)
	  stfs      f0, 0x30(r31)
	  stfs      f1, 0x40(r31)
	  lwz       r0, 0x2CC(r1)
	  lmw       r26, 0x2B0(r1)
	  addi      r1, r1, 0x2C8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016BC60
 * Size:	000148
 */
King::King(CreatureProp*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  bl        -0x1DE04
	  lis       r3, 0x802D
	  addi      r0, r3, 0x1B4
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  addi      r3, r31, 0x40C
	  stw       r0, 0x408(r31)
	  bl        -0x102768
	  li        r3, 0x14
	  bl        -0x124C9C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x58
	  li        r4, 0x26
	  bl        -0xE3084

	.loc_0x58:
	  stw       r30, 0x220(r31)
	  li        r3, 0x50
	  bl        -0x124CBC
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x78
	  mr        r4, r31
	  bl        0x5DC

	.loc_0x78:
	  stw       r30, 0x3BC(r31)
	  li        r3, 0x110
	  bl        -0x124CDC
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x98
	  mr        r4, r31
	  bl        0x78F4

	.loc_0x98:
	  stw       r30, 0x3C0(r31)
	  li        r30, 0
	  addi      r0, r13, 0x268
	  stw       r30, 0x41C(r31)
	  addi      r3, r31, 0x40C
	  stw       r30, 0x418(r31)
	  stw       r30, 0x414(r31)
	  stw       r0, 0x410(r31)
	  bl        -0x1026B4
	  li        r3, 0x24
	  bl        -0x124D1C
	  mr.       r29, r3
	  beq-      .loc_0x124
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x0(r29)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x0(r29)
	  addi      r3, r29, 0
	  addi      r4, r13, 0x268
	  stw       r30, 0x10(r29)
	  stw       r30, 0xC(r29)
	  stw       r30, 0x8(r29)
	  bl        -0x146E84
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r29)
	  addi      r3, r29, 0
	  addi      r4, r13, 0x268
	  bl        -0x12B634
	  lis       r3, 0x802D
	  addi      r0, r3, 0x108
	  stw       r0, 0x0(r29)
	  stw       r31, 0x20(r29)

	.loc_0x124:
	  stw       r29, 0x7A0(r31)
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
 * Address:	8016BDA8
 * Size:	000008
 */
void King::getiMass()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x53A4(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016BDB0
 * Size:	000020
 */
void King::bombDamageCounter(CollPart*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x5
	  bnelr-
	  lwz       r4, 0x3BC(r3)
	  lwz       r3, 0x1C(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x1C(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016BDD0
 * Size:	000084
 */
void King::init(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  li        r3, 0x1
	  lfs       f0, -0x53E0(r2)
	  addi      r4, r31, 0
	  stfs      f0, 0x270(r31)
	  stb       r3, 0x2BC(r31)
	  stb       r0, 0x2BB(r31)
	  lfs       f0, -0x53D0(r2)
	  stfs      f0, 0x2E0(r31)
	  stb       r0, 0x3B8(r31)
	  lwz       r3, 0x3BC(r31)
	  bl        0x4E8
	  lwz       r3, 0x3C0(r31)
	  mr        r4, r31
	  bl        0x7A40
	  lfs       f0, -0x53A0(r2)
	  addi      r4, r31, 0
	  addi      r3, r31, 0x3C4
	  stfs      f0, 0x5EC(r31)
	  lwz       r6, 0x390(r31)
	  lwz       r5, 0x2F00(r13)
	  lwz       r6, 0x0(r6)
	  bl        -0xDDD7C
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016BE54
 * Size:	000060
 */
void King::doKill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stb       r0, 0x2B8(r3)
	  stb       r0, 0x2B9(r3)
	  stb       r0, 0x3B8(r3)
	  lwz       r3, 0x3C0(r3)
	  bl        0x768C
	  addi      r3, r31, 0x3C4
	  bl        -0xDDD28
	  addi      r3, r31, 0x40C
	  bl        -0x12B880
	  lwz       r3, 0x3168(r13)
	  mr        r4, r31
	  bl        -0x19D04
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016BEB4
 * Size:	000028
 */
void King::exitCourse()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x3C0(r3)
	  bl        0x7644
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016BEDC
 * Size:	000064
 */
void King::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x104(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0xDEF08
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r31
	  lfs       f1, 0x28C(r4)
	  bl        -0xDD938
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x108(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016BF40
 * Size:	000178
 */
void King::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB8(r1)
	  stfd      f31, 0xB0(r1)
	  stfd      f30, 0xA8(r1)
	  stw       r31, 0xA4(r1)
	  mr        r31, r4
	  stw       r30, 0xA0(r1)
	  mr        r30, r3
	  lwz       r5, 0x2F00(r13)
	  lfs       f0, -0x53CC(r2)
	  lwz       r3, 0x4(r5)
	  lfsu      f4, 0x1408(r3)
	  fmuls     f0, f0, f0
	  lfs       f3, 0x94(r30)
	  lfs       f1, 0x9C(r30)
	  lfs       f2, 0x8(r3)
	  fsubs     f31, f4, f3
	  fsubs     f30, f2, f1
	  fmuls     f1, f31, f31
	  fmuls     f2, f30, f30
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15E35C
	  lfs       f0, -0x53CC(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x74
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1

	.loc_0x74:
	  lfs       f0, -0x53D0(r2)
	  lwz       r3, 0x220(r30)
	  fmuls     f31, f31, f0
	  fmuls     f30, f30, f0
	  bl        -0xE28BC
	  addi      r3, r3, 0x4
	  lfs       f1, 0x98(r30)
	  lfs       f3, 0x4(r3)
	  lfs       f0, -0x53CC(r2)
	  fsubs     f4, f3, f1
	  lfs       f1, 0x0(r3)
	  lfs       f2, 0x8(r3)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xB8
	  lfs       f0, -0x539C(r2)
	  fmuls     f0, f0, f4
	  fadds     f3, f3, f0

	.loc_0xB8:
	  fadds     f1, f1, f31
	  addi      r3, r30, 0x228
	  fadds     f0, f2, f30
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  stfs      f1, 0x788(r30)
	  addi      r6, r30, 0x94
	  lfs       f1, -0x5398(r2)
	  fadds     f1, f1, f3
	  stfs      f1, 0x78C(r30)
	  stfs      f0, 0x790(r30)
	  lfs       f2, -0x53E0(r2)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x94(r30)
	  fadds     f1, f2, f1
	  stfs      f0, 0x794(r30)
	  stfs      f1, 0x798(r30)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x79C(r30)
	  bl        -0x12DF50
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x48
	  addi      r3, r3, 0x1E0
	  bl        -0x12DF84
	  addi      r3, r30, 0x33C
	  lwz       r12, 0x36C(r30)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x390(r30)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x48
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0x136D70
	  lwz       r3, 0x3C0(r30)
	  mr        r5, r31
	  lwz       r4, 0x390(r30)
	  bl        0x868C
	  lwz       r0, 0xBC(r1)
	  lfd       f31, 0xB0(r1)
	  lfd       f30, 0xA8(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016C0B8
 * Size:	000054
 */
void King::refresh(Graphics&)
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
	  bl        -0x194
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0xE25F8
	  addi      r3, r30, 0x3C4
	  addi      r4, r31, 0
	  bl        -0xDDF28
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
 * Address:	8016C10C
 * Size:	000078
 */
void King::drawShape(Graphics&)
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
	  lwz       r3, 0x390(r3)
	  lwz       r3, 0x0(r3)
	  bl        -0x136B3C
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x390(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  lwz       r3, 0x0(r3)
	  bl        -0x13BCFC
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
 * Address:	8016C184
 * Size:	000024
 */
void King::doAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x3BC(r3)
	  bl        0x3B6C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016C1A8
 * Size:	000054
 */
void King::doAnimation()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x3C0(r3)
	  bl        0x7C20
	  lwz       r0, 0x390(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x40
	  lwz       r12, 0x36C(r31)
	  addi      r3, r31, 0x33C
	  lfs       f1, 0x2D8(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x40:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016C1FC
 * Size:	000054
 */
void KingDrawer::draw(Graphics&)
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
	  lwz       r3, 0x20(r3)
	  bl        -0x2DC
	  lwz       r3, 0x20(r30)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x120(r12)
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
 * Address:	8016C250
 * Size:	000008
 */
void King::isBossBgm()
{
	/*
	.loc_0x0:
	  lbz       r3, 0x3B8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016C258
 * Size:	000050
 */
void KingProp::read(RandomAccessStream&)
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
	  bl        -0x10D6DC
	  addi      r3, r30, 0x58
	  addi      r4, r31, 0
	  bl        -0x10D6E8
	  addi      r3, r30, 0x200
	  addi      r4, r31, 0
	  bl        -0x10D6F4
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
 * Address:	8016C2A8
 * Size:	000008
 */
void KingProp::@492 @read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  subi      r3, r3, 0x1EC
	  b         -0x54
	*/
}
