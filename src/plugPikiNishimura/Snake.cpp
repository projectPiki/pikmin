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
 * Address:	8015A2C4
 * Size:	0008F0
 */
SnakeProp::SnakeProp()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x320(r1)
	  stw       r31, 0x31C(r1)
	  mr        r31, r3
	  stw       r30, 0x318(r1)
	  stw       r29, 0x314(r1)
	  stw       r28, 0x310(r1)
	  bl        -0xCA18
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x1EC(r31)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x1EC(r31)
	  li        r29, 0
	  lis       r3, 0x802D
	  stw       r29, 0x1FC(r31)
	  subi      r6, r3, 0x688
	  lis       r4, 0x802D
	  stw       r29, 0x1F8(r31)
	  subi      r3, r4, 0x954
	  addi      r0, r6, 0xC
	  stw       r29, 0x1F4(r31)
	  addi      r5, r1, 0x188
	  addi      r4, r31, 0x200
	  stw       r3, 0x1F0(r31)
	  addi      r3, r31, 0x204
	  stw       r6, 0x54(r31)
	  stw       r0, 0x1EC(r31)
	  stw       r29, 0x200(r31)
	  lwz       r0, -0x1B0(r13)
	  stw       r0, 0x190(r1)
	  lwz       r0, 0x190(r1)
	  stw       r0, 0x188(r1)
	  bl        -0xFB8D0
	  lis       r3, 0x802A
	  addi      r30, r3, 0x6098
	  stw       r30, 0x20C(r31)
	  addi      r5, r1, 0x184
	  addi      r3, r31, 0x214
	  lfs       f0, -0x5608(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x210(r31)
	  lwz       r0, -0x1AC(r13)
	  stw       r0, 0x198(r1)
	  lwz       r0, 0x198(r1)
	  stw       r0, 0x184(r1)
	  bl        -0xFB904
	  stw       r30, 0x21C(r31)
	  addi      r5, r1, 0x180
	  addi      r3, r31, 0x224
	  lfs       f0, -0x5604(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x220(r31)
	  lwz       r0, -0x1A8(r13)
	  stw       r0, 0x1A0(r1)
	  lwz       r0, 0x1A0(r1)
	  stw       r0, 0x180(r1)
	  bl        -0xFB930
	  stw       r30, 0x22C(r31)
	  addi      r5, r1, 0x17C
	  addi      r3, r31, 0x234
	  lfs       f0, -0x5600(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x230(r31)
	  lwz       r0, -0x1A4(r13)
	  stw       r0, 0x1A8(r1)
	  lwz       r0, 0x1A8(r1)
	  stw       r0, 0x17C(r1)
	  bl        -0xFB95C
	  stw       r30, 0x23C(r31)
	  addi      r5, r1, 0x178
	  addi      r3, r31, 0x244
	  lfs       f0, -0x5604(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x240(r31)
	  lwz       r0, -0x1A0(r13)
	  stw       r0, 0x1B0(r1)
	  lwz       r0, 0x1B0(r1)
	  stw       r0, 0x178(r1)
	  bl        -0xFB988
	  stw       r30, 0x24C(r31)
	  addi      r5, r1, 0x174
	  addi      r3, r31, 0x254
	  lfs       f0, -0x55FC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x250(r31)
	  lwz       r0, -0x19C(r13)
	  stw       r0, 0x1B8(r1)
	  lwz       r0, 0x1B8(r1)
	  stw       r0, 0x174(r1)
	  bl        -0xFB9B4
	  stw       r30, 0x25C(r31)
	  addi      r5, r1, 0x170
	  addi      r3, r31, 0x264
	  lfs       f0, -0x55F8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x260(r31)
	  lwz       r0, -0x198(r13)
	  stw       r0, 0x1C0(r1)
	  lwz       r0, 0x1C0(r1)
	  stw       r0, 0x170(r1)
	  bl        -0xFB9E0
	  stw       r30, 0x26C(r31)
	  addi      r5, r1, 0x16C
	  addi      r3, r31, 0x274
	  lfs       f0, -0x55F4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x270(r31)
	  lwz       r0, -0x194(r13)
	  stw       r0, 0x1C8(r1)
	  lwz       r0, 0x1C8(r1)
	  stw       r0, 0x16C(r1)
	  bl        -0xFBA0C
	  stw       r30, 0x27C(r31)
	  addi      r5, r1, 0x168
	  addi      r3, r31, 0x284
	  lfs       f0, -0x55F0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x280(r31)
	  lwz       r0, -0x190(r13)
	  stw       r0, 0x1D0(r1)
	  lwz       r0, 0x1D0(r1)
	  stw       r0, 0x168(r1)
	  bl        -0xFBA38
	  stw       r30, 0x28C(r31)
	  addi      r5, r1, 0x164
	  addi      r3, r31, 0x294
	  lfs       f0, -0x55EC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x290(r31)
	  lwz       r0, -0x18C(r13)
	  stw       r0, 0x1D8(r1)
	  lwz       r0, 0x1D8(r1)
	  stw       r0, 0x164(r1)
	  bl        -0xFBA64
	  stw       r30, 0x29C(r31)
	  addi      r5, r1, 0x160
	  addi      r3, r31, 0x2A4
	  lfs       f0, -0x55E8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2A0(r31)
	  lwz       r0, -0x188(r13)
	  stw       r0, 0x1E0(r1)
	  lwz       r0, 0x1E0(r1)
	  stw       r0, 0x160(r1)
	  bl        -0xFBA90
	  stw       r30, 0x2AC(r31)
	  addi      r5, r1, 0x15C
	  addi      r3, r31, 0x2B4
	  lfs       f0, -0x55E8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2B0(r31)
	  lwz       r0, -0x184(r13)
	  stw       r0, 0x1E8(r1)
	  lwz       r0, 0x1E8(r1)
	  stw       r0, 0x15C(r1)
	  bl        -0xFBABC
	  stw       r30, 0x2BC(r31)
	  addi      r5, r1, 0x158
	  addi      r3, r31, 0x2C4
	  lfs       f0, -0x55F0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2C0(r31)
	  lwz       r0, -0x180(r13)
	  stw       r0, 0x1F0(r1)
	  lwz       r0, 0x1F0(r1)
	  stw       r0, 0x158(r1)
	  bl        -0xFBAE8
	  stw       r30, 0x2CC(r31)
	  addi      r5, r1, 0x154
	  addi      r3, r31, 0x2D4
	  lfs       f0, -0x5608(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2D0(r31)
	  lwz       r0, -0x17C(r13)
	  stw       r0, 0x1F8(r1)
	  lwz       r0, 0x1F8(r1)
	  stw       r0, 0x154(r1)
	  bl        -0xFBB14
	  stw       r30, 0x2DC(r31)
	  addi      r5, r1, 0x150
	  addi      r3, r31, 0x2E4
	  lfs       f0, -0x55E4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2E0(r31)
	  lwz       r0, -0x178(r13)
	  stw       r0, 0x200(r1)
	  lwz       r0, 0x200(r1)
	  stw       r0, 0x150(r1)
	  bl        -0xFBB40
	  stw       r30, 0x2EC(r31)
	  addi      r5, r1, 0x14C
	  addi      r3, r31, 0x2F4
	  lfs       f0, -0x55E0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x2F0(r31)
	  lwz       r0, -0x174(r13)
	  stw       r0, 0x208(r1)
	  lwz       r0, 0x208(r1)
	  stw       r0, 0x14C(r1)
	  bl        -0xFBB6C
	  stw       r30, 0x2FC(r31)
	  addi      r5, r1, 0x148
	  addi      r3, r31, 0x304
	  lfs       f0, -0x55E8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x300(r31)
	  lwz       r0, -0x170(r13)
	  stw       r0, 0x210(r1)
	  lwz       r0, 0x210(r1)
	  stw       r0, 0x148(r1)
	  bl        -0xFBB98
	  stw       r30, 0x30C(r31)
	  addi      r5, r1, 0x144
	  addi      r3, r31, 0x314
	  lfs       f0, -0x5608(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x310(r31)
	  lwz       r0, -0x16C(r13)
	  stw       r0, 0x218(r1)
	  lwz       r0, 0x218(r1)
	  stw       r0, 0x144(r1)
	  bl        -0xFBBC4
	  stw       r30, 0x31C(r31)
	  addi      r5, r1, 0x140
	  addi      r3, r31, 0x324
	  lfs       f0, -0x55DC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x320(r31)
	  lwz       r0, -0x168(r13)
	  stw       r0, 0x220(r1)
	  lwz       r0, 0x220(r1)
	  stw       r0, 0x140(r1)
	  bl        -0xFBBF0
	  stw       r30, 0x32C(r31)
	  addi      r5, r1, 0x13C
	  addi      r3, r31, 0x334
	  lfs       f0, -0x55D8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x330(r31)
	  lwz       r0, -0x164(r13)
	  stw       r0, 0x228(r1)
	  lwz       r0, 0x228(r1)
	  stw       r0, 0x13C(r1)
	  bl        -0xFBC1C
	  stw       r30, 0x33C(r31)
	  addi      r5, r1, 0x138
	  addi      r3, r31, 0x344
	  lfs       f0, -0x55F8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x340(r31)
	  lwz       r0, -0x160(r13)
	  stw       r0, 0x230(r1)
	  lwz       r0, 0x230(r1)
	  stw       r0, 0x138(r1)
	  bl        -0xFBC48
	  stw       r30, 0x34C(r31)
	  addi      r5, r1, 0x134
	  addi      r3, r31, 0x354
	  lfs       f0, -0x55E8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x350(r31)
	  lwz       r0, -0x15C(r13)
	  stw       r0, 0x238(r1)
	  lwz       r0, 0x238(r1)
	  stw       r0, 0x134(r1)
	  bl        -0xFBC74
	  stw       r30, 0x35C(r31)
	  addi      r5, r1, 0x130
	  addi      r3, r31, 0x364
	  lfs       f0, -0x55D4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x360(r31)
	  lwz       r0, -0x158(r13)
	  stw       r0, 0x240(r1)
	  lwz       r0, 0x240(r1)
	  stw       r0, 0x130(r1)
	  bl        -0xFBCA0
	  stw       r30, 0x36C(r31)
	  addi      r5, r1, 0x12C
	  addi      r3, r31, 0x374
	  lfs       f0, -0x55D0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x370(r31)
	  lwz       r0, -0x154(r13)
	  stw       r0, 0x248(r1)
	  lwz       r0, 0x248(r1)
	  stw       r0, 0x12C(r1)
	  bl        -0xFBCCC
	  stw       r30, 0x37C(r31)
	  addi      r5, r1, 0x128
	  addi      r3, r31, 0x384
	  lfs       f0, -0x55CC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x380(r31)
	  lwz       r0, -0x150(r13)
	  stw       r0, 0x250(r1)
	  lwz       r0, 0x250(r1)
	  stw       r0, 0x128(r1)
	  bl        -0xFBCF8
	  stw       r30, 0x38C(r31)
	  addi      r5, r1, 0x124
	  addi      r3, r31, 0x394
	  lfs       f0, -0x5604(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x390(r31)
	  lwz       r0, -0x14C(r13)
	  stw       r0, 0x258(r1)
	  lwz       r0, 0x258(r1)
	  stw       r0, 0x124(r1)
	  bl        -0xFBD24
	  stw       r30, 0x39C(r31)
	  addi      r5, r1, 0x120
	  addi      r3, r31, 0x3A4
	  lfs       f0, -0x55E8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x3A0(r31)
	  lwz       r0, -0x148(r13)
	  stw       r0, 0x260(r1)
	  lwz       r0, 0x260(r1)
	  stw       r0, 0x120(r1)
	  bl        -0xFBD50
	  stw       r30, 0x3AC(r31)
	  addi      r5, r1, 0x11C
	  addi      r3, r31, 0x3B4
	  lfs       f0, -0x55D4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x3B0(r31)
	  lwz       r0, -0x144(r13)
	  stw       r0, 0x268(r1)
	  lwz       r0, 0x268(r1)
	  stw       r0, 0x11C(r1)
	  bl        -0xFBD7C
	  stw       r30, 0x3BC(r31)
	  addi      r5, r1, 0x118
	  addi      r3, r31, 0x3C4
	  lfs       f0, -0x55D0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x3C0(r31)
	  lwz       r0, -0x140(r13)
	  stw       r0, 0x270(r1)
	  lwz       r0, 0x270(r1)
	  stw       r0, 0x118(r1)
	  bl        -0xFBDA8
	  stw       r30, 0x3CC(r31)
	  addi      r5, r1, 0x114
	  addi      r3, r31, 0x3D4
	  lfs       f0, -0x55C8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x3D0(r31)
	  lwz       r0, -0x13C(r13)
	  stw       r0, 0x278(r1)
	  lwz       r0, 0x278(r1)
	  stw       r0, 0x114(r1)
	  bl        -0xFBDD4
	  stw       r30, 0x3DC(r31)
	  addi      r5, r1, 0x110
	  addi      r3, r31, 0x3E4
	  lfs       f0, -0x55C4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x3E0(r31)
	  lwz       r0, -0x138(r13)
	  stw       r0, 0x280(r1)
	  lwz       r0, 0x280(r1)
	  stw       r0, 0x110(r1)
	  bl        -0xFBE00
	  stw       r30, 0x3EC(r31)
	  addi      r5, r1, 0x10C
	  addi      r3, r31, 0x3F4
	  lfs       f0, -0x55E8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x3F0(r31)
	  lwz       r0, -0x134(r13)
	  stw       r0, 0x288(r1)
	  lwz       r0, 0x288(r1)
	  stw       r0, 0x10C(r1)
	  bl        -0xFBE2C
	  stw       r30, 0x3FC(r31)
	  addi      r5, r1, 0x108
	  addi      r3, r31, 0x404
	  lfs       f0, -0x55C0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x400(r31)
	  lwz       r0, -0x130(r13)
	  stw       r0, 0x290(r1)
	  lwz       r0, 0x290(r1)
	  stw       r0, 0x108(r1)
	  bl        -0xFBE58
	  stw       r30, 0x40C(r31)
	  addi      r5, r1, 0x104
	  addi      r3, r31, 0x414
	  lfs       f0, -0x55BC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x410(r31)
	  lwz       r0, -0x12C(r13)
	  stw       r0, 0x298(r1)
	  lwz       r0, 0x298(r1)
	  stw       r0, 0x104(r1)
	  bl        -0xFBE84
	  stw       r30, 0x41C(r31)
	  addi      r5, r1, 0x100
	  addi      r3, r31, 0x424
	  lfs       f0, -0x55B8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x420(r31)
	  lwz       r0, -0x128(r13)
	  stw       r0, 0x2A0(r1)
	  lwz       r0, 0x2A0(r1)
	  stw       r0, 0x100(r1)
	  bl        -0xFBEB0
	  stw       r30, 0x42C(r31)
	  addi      r5, r1, 0xFC
	  addi      r3, r31, 0x434
	  lfs       f0, -0x55B4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x430(r31)
	  lwz       r0, -0x124(r13)
	  stw       r0, 0x2A8(r1)
	  lwz       r0, 0x2A8(r1)
	  stw       r0, 0xFC(r1)
	  bl        -0xFBEDC
	  stw       r30, 0x43C(r31)
	  addi      r5, r1, 0xF8
	  addi      r3, r31, 0x444
	  lfs       f0, -0x55B0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x440(r31)
	  lwz       r0, -0x120(r13)
	  stw       r0, 0x2B0(r1)
	  lwz       r0, 0x2B0(r1)
	  stw       r0, 0xF8(r1)
	  bl        -0xFBF08
	  stw       r30, 0x44C(r31)
	  addi      r5, r1, 0xF4
	  addi      r3, r31, 0x454
	  lfs       f0, -0x55AC(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x450(r31)
	  lwz       r0, -0x11C(r13)
	  stw       r0, 0x2B8(r1)
	  lwz       r0, 0x2B8(r1)
	  stw       r0, 0xF4(r1)
	  bl        -0xFBF34
	  stw       r30, 0x45C(r31)
	  addi      r5, r1, 0xF0
	  addi      r3, r31, 0x464
	  lfs       f0, -0x55B8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x460(r31)
	  lwz       r0, -0x118(r13)
	  stw       r0, 0x2C0(r1)
	  lwz       r0, 0x2C0(r1)
	  stw       r0, 0xF0(r1)
	  bl        -0xFBF60
	  stw       r30, 0x46C(r31)
	  addi      r5, r1, 0xEC
	  addi      r3, r31, 0x474
	  lfs       f0, -0x55F4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x470(r31)
	  lwz       r0, -0x114(r13)
	  stw       r0, 0x2C8(r1)
	  lwz       r0, 0x2C8(r1)
	  stw       r0, 0xEC(r1)
	  bl        -0xFBF8C
	  stw       r30, 0x47C(r31)
	  addi      r5, r1, 0xE8
	  addi      r3, r31, 0x484
	  lfs       f0, -0x55A8(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x480(r31)
	  lwz       r0, -0x110(r13)
	  stw       r0, 0x2D0(r1)
	  lwz       r0, 0x2D0(r1)
	  stw       r0, 0xE8(r1)
	  bl        -0xFBFB8
	  stw       r30, 0x48C(r31)
	  addi      r5, r1, 0xE4
	  addi      r3, r31, 0x494
	  lfs       f0, -0x55A4(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x490(r31)
	  lwz       r0, -0x10C(r13)
	  stw       r0, 0x2D8(r1)
	  lwz       r0, 0x2D8(r1)
	  stw       r0, 0xE4(r1)
	  bl        -0xFBFE4
	  stw       r30, 0x49C(r31)
	  addi      r5, r1, 0xE0
	  addi      r3, r31, 0x4A4
	  lfs       f0, -0x55A0(r2)
	  addi      r4, r31, 0x200
	  stfs      f0, 0x4A0(r31)
	  lwz       r0, -0x108(r13)
	  stw       r0, 0x2E0(r1)
	  lwz       r0, 0x2E0(r1)
	  stw       r0, 0xE0(r1)
	  bl        -0xFC010
	  lis       r3, 0x802A
	  addi      r30, r3, 0x60C4
	  stw       r30, 0x4AC(r31)
	  li        r0, 0x5
	  addi      r5, r1, 0xDC
	  stw       r0, 0x4B0(r31)
	  addi      r3, r31, 0x4B4
	  addi      r4, r31, 0x200
	  lwz       r0, -0x104(r13)
	  stw       r0, 0x2E8(r1)
	  lwz       r0, 0x2E8(r1)
	  stw       r0, 0xDC(r1)
	  bl        -0xFC044
	  stw       r30, 0x4BC(r31)
	  li        r0, 0x14
	  addi      r5, r1, 0xD8
	  stw       r0, 0x4C0(r31)
	  addi      r3, r31, 0x4C4
	  addi      r4, r31, 0x200
	  lwz       r0, -0x100(r13)
	  stw       r0, 0x2F0(r1)
	  lwz       r0, 0x2F0(r1)
	  stw       r0, 0xD8(r1)
	  bl        -0xFC070
	  stw       r30, 0x4CC(r31)
	  li        r28, 0x1
	  addi      r5, r1, 0xD4
	  stw       r28, 0x4D0(r31)
	  addi      r3, r31, 0x4D4
	  addi      r4, r31, 0x200
	  lwz       r0, -0xFC(r13)
	  stw       r0, 0x2F8(r1)
	  lwz       r0, 0x2F8(r1)
	  stw       r0, 0xD4(r1)
	  bl        -0xFC09C
	  stw       r30, 0x4DC(r31)
	  li        r0, 0x3
	  addi      r5, r1, 0xD0
	  stw       r0, 0x4E0(r31)
	  addi      r3, r31, 0x4E4
	  addi      r4, r31, 0x200
	  lwz       r0, -0xF8(r13)
	  stw       r0, 0x300(r1)
	  lwz       r0, 0x300(r1)
	  stw       r0, 0xD0(r1)
	  bl        -0xFC0C8
	  stw       r30, 0x4EC(r31)
	  addi      r5, r1, 0xCC
	  addi      r3, r31, 0x4F4
	  stw       r28, 0x4F0(r31)
	  addi      r4, r31, 0x200
	  lwz       r0, -0xF4(r13)
	  stw       r0, 0x308(r1)
	  lwz       r0, 0x308(r1)
	  stw       r0, 0xCC(r1)
	  bl        -0xFC0F0
	  stw       r30, 0x4FC(r31)
	  mr        r3, r31
	  stw       r29, 0x500(r31)
	  lfs       f1, -0x55B8(r2)
	  stfs      f1, 0x10(r31)
	  lfs       f0, -0x55B0(r2)
	  stfs      f0, 0x30(r31)
	  stfs      f1, 0x40(r31)
	  lwz       r0, 0x324(r1)
	  lwz       r31, 0x31C(r1)
	  lwz       r30, 0x318(r1)
	  lwz       r29, 0x314(r1)
	  lwz       r28, 0x310(r1)
	  addi      r1, r1, 0x320
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015ABB4
 * Size:	000104
 */
Snake::Snake(CreatureProp*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  stw       r30, 0x10(r1)
	  bl        -0xCD54
	  lis       r3, 0x802D
	  subi      r0, r3, 0x8CC
	  stw       r0, 0x0(r31)
	  li        r3, 0x14
	  lfs       f0, -0x55B0(r2)
	  stfs      f0, 0x3D8(r31)
	  stfs      f0, 0x3D4(r31)
	  stfs      f0, 0x3D0(r31)
	  bl        -0x113BEC
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x54
	  li        r4, 0x18
	  bl        -0xD1FD4

	.loc_0x54:
	  stw       r30, 0x220(r31)
	  li        r3, 0x30
	  bl        -0x113C0C
	  mr.       r30, r3
	  beq-      .loc_0xA4
	  lis       r3, 0x802D
	  subi      r0, r3, 0x760
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0x4
	  bl        -0x116DD0
	  addi      r3, r30, 0x10
	  bl        -0x116DD8
	  lis       r3, 0x802D
	  subi      r0, r3, 0x770
	  stw       r0, 0x0(r30)
	  lfs       f0, -0x55B0(r2)
	  stfs      f0, 0x2C(r30)
	  stfs      f0, 0x28(r30)
	  stfs      f0, 0x24(r30)
	  stw       r31, 0x1C(r30)

	.loc_0xA4:
	  stw       r30, 0x3B8(r31)
	  li        r3, 0x50
	  bl        -0x113C5C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xC4
	  mr        r4, r31
	  bl        0x57C

	.loc_0xC4:
	  stw       r30, 0x3C8(r31)
	  li        r3, 0x890
	  bl        -0x113C7C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xE4
	  mr        r4, r31
	  bl        0x529C

	.loc_0xE4:
	  stw       r30, 0x3CC(r31)
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
 * Address:	8015ACB8
 * Size:	000008
 */
void Snake::setBossType(bool a1)
{
	// Generated from stb r4, 0x3BC(r3)
	_3BC = a1;
}

/*
 * --INFO--
 * Address:	8015ACC0
 * Size:	00000C
 */
void Snake::getCentreSize()
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
 * Address:	8015ACCC
 * Size:	000008
 */
void Snake::getiMass()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x559C(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015ACD4
 * Size:	0000B8
 */
void Snake::init(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r4, r30, 0
	  lfs       f0, -0x55E8(r2)
	  stfs      f0, 0x270(r3)
	  lfs       f0, -0x55CC(r2)
	  stfs      f0, 0x2E0(r3)
	  stb       r0, 0x3BC(r3)
	  lfs       f0, 0x8C(r3)
	  stfs      f0, 0x3C0(r3)
	  lfs       f0, -0x55B0(r2)
	  stfs      f0, 0x3C4(r3)
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x4(r31)
	  stw       r3, 0x3D0(r30)
	  stw       r0, 0x3D4(r30)
	  lwz       r0, 0x8(r31)
	  stw       r0, 0x3D8(r30)
	  lwz       r3, 0x3C8(r30)
	  bl        0x588
	  lwz       r3, 0x3CC(r30)
	  addi      r4, r31, 0
	  addi      r5, r30, 0
	  bl        0x5340
	  lis       r4, 0x626E
	  lwz       r3, 0x220(r30)
	  lwz       r5, 0x3B8(r30)
	  addi      r4, r4, 0x6473
	  bl        -0xD10A4
	  lis       r4, 0x7475
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x6265
	  li        r5, 0x7
	  bl        -0xD1168
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
 * Address:	8015AD8C
 * Size:	00004C
 */
void Snake::doKill()
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
	  lwz       r3, 0x3CC(r3)
	  bl        0x5114
	  lwz       r3, 0x3168(r13)
	  mr        r4, r31
	  bl        -0x8C28
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015ADD8
 * Size:	000028
 */
void Snake::exitCourse()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x3CC(r3)
	  bl        0x50DC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015AE00
 * Size:	000064
 */
void Snake::update()
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
	  bl        -0xCDE2C
	  lwz       r4, 0x2DEC(r13)
	  mr        r3, r31
	  lfs       f1, 0x28C(r4)
	  bl        -0xCC85C
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
 * Address:	8015AE64
 * Size:	0000A8
 */
void Snake::refresh(Graphics&)
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
	  bl        -0x11CD9C
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x10
	  addi      r3, r3, 0x1E0
	  bl        -0x11CDD0
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
	  bl        -0x125BBC
	  lwz       r3, 0x3CC(r30)
	  mr        r5, r31
	  lwz       r4, 0x390(r30)
	  bl        0x7DE4
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0xD1404
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
 * Address:	8015AF0C
 * Size:	000078
 */
void Snake::drawShape(Graphics&)
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
	  bl        -0x12593C
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
	  bl        -0x12AAFC
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
 * Address:	8015AF84
 * Size:	000074
 */
void Snake::refresh2d(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r6, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x94(r3)
	  lwz       r0, 0x98(r3)
	  addi      r3, r6, 0x1E0
	  stw       r5, 0x1E0(r6)
	  stw       r0, 0x1E4(r6)
	  lwz       r0, 0x9C(r6)
	  stw       r0, 0x1E8(r6)
	  lwz       r5, 0x224(r6)
	  lfs       f1, 0x1E4(r6)
	  lfs       f0, 0x108(r5)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1E4(r6)
	  lwz       r5, 0x224(r6)
	  lfs       f1, 0x3C4(r6)
	  lfs       f0, 0xF8(r5)
	  lwz       r5, 0x2E4(r4)
	  fmuls     f1, f1, f0
	  lfs       f0, 0x1D0(r5)
	  fdivs     f0, f1, f0
	  stfs      f0, 0x214(r6)
	  bl        -0xFEF40
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015AFF8
 * Size:	000024
 */
void Snake::doAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x3C8(r3)
	  bl        0x3864
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015B01C
 * Size:	000054
 */
void Snake::doAnimation()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x390(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x38
	  lwz       r12, 0x36C(r31)
	  addi      r3, r31, 0x33C
	  lfs       f1, 0x2D8(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x38:
	  lwz       r3, 0x3CC(r31)
	  bl        0x6090
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015B070
 * Size:	000074
 */
void Snake::BoundSphereUpdater::getPos()
{
	/*
	.loc_0x0:
	  lwz       r6, 0x1C(r4)
	  lfs       f2, -0x5598(r2)
	  lwz       r5, 0x3CC(r6)
	  lfs       f0, 0x94(r6)
	  lfs       f1, 0x50(r5)
	  fadds     f0, f1, f0
	  fmuls     f0, f0, f2
	  stfs      f0, 0x24(r4)
	  lwz       r6, 0x1C(r4)
	  lwz       r5, 0x3CC(r6)
	  lfs       f0, 0x98(r6)
	  lfs       f1, 0x54(r5)
	  fadds     f0, f1, f0
	  fmuls     f0, f0, f2
	  stfs      f0, 0x28(r4)
	  lwz       r6, 0x1C(r4)
	  lwz       r5, 0x3CC(r6)
	  lfs       f0, 0x9C(r6)
	  lfs       f1, 0x58(r5)
	  fadds     f0, f1, f0
	  fmuls     f0, f0, f2
	  stfs      f0, 0x2C(r4)
	  lfs       f0, 0x24(r4)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x28(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x2C(r4)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015B0E4
 * Size:	0000B4
 */
void Snake::BoundSphereUpdater::getSize()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lwz       r3, 0x1C(r3)
	  lfs       f0, -0x55B0(r2)
	  lwz       r3, 0x3CC(r3)
	  stfs      f0, 0x30(r1)
	  stfs      f0, 0x2C(r1)
	  stfs      f0, 0x28(r1)
	  lfsu      f0, 0x50(r3)
	  lfs       f1, 0x24(r31)
	  lfs       f4, 0x2C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x28(r31)
	  lfs       f1, 0x4(r3)
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
	  bl        -0x14D528
	  stfs      f1, 0x20(r31)
	  lfs       f1, 0x20(r31)
	  lfs       f0, -0x5594(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r31)
	  lfs       f1, 0x20(r31)
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015B198
 * Size:	000050
 */
void SnakeProp::read(RandomAccessStream&)
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
	  bl        -0xFC61C
	  addi      r3, r30, 0x58
	  addi      r4, r31, 0
	  bl        -0xFC628
	  addi      r3, r30, 0x200
	  addi      r4, r31, 0
	  bl        -0xFC634
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
 * Address:	8015B1E8
 * Size:	000008
 */
void SnakeProp::@492 @read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  subi      r3, r3, 0x1EC
	  b         -0x54
	*/
}
