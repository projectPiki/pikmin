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
 * Address:	80152794
 * Size:	0009C8
 */
SpiderProp::SpiderProp()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x370(r1)
  stw       r31, 0x36C(r1)
  mr        r31, r3
  stw       r30, 0x368(r1)
  stw       r29, 0x364(r1)
  stw       r28, 0x360(r1)
  bl        -0x4EE8
  lis       r3, 0x8022
  addi      r0, r3, 0x738C
  lis       r3, 0x8022
  stw       r0, 0x1EC(r31)
  addi      r0, r3, 0x737C
  stw       r0, 0x1EC(r31)
  li        r7, 0
  lis       r3, 0x802D
  stw       r7, 0x1FC(r31)
  subi      r6, r3, 0xBA0
  lis       r4, 0x802D
  stw       r7, 0x1F8(r31)
  subi      r3, r4, 0xE84
  addi      r0, r6, 0xC
  stw       r7, 0x1F4(r31)
  addi      r5, r1, 0x1B0
  addi      r4, r31, 0x200
  stw       r3, 0x1F0(r31)
  addi      r3, r31, 0x204
  stw       r6, 0x54(r31)
  stw       r0, 0x1EC(r31)
  stw       r7, 0x200(r31)
  lwz       r0, -0x398(r13)
  stw       r0, 0x1B8(r1)
  lwz       r0, 0x1B8(r1)
  stw       r0, 0x1B0(r1)
  bl        -0xF3DA0
  lis       r3, 0x802A
  addi      r30, r3, 0x6098
  stw       r30, 0x20C(r31)
  addi      r5, r1, 0x1AC
  addi      r3, r31, 0x214
  lfs       f0, -0x5780(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x210(r31)
  lwz       r0, -0x394(r13)
  stw       r0, 0x1C0(r1)
  lwz       r0, 0x1C0(r1)
  stw       r0, 0x1AC(r1)
  bl        -0xF3DD4
  stw       r30, 0x21C(r31)
  addi      r5, r1, 0x1A8
  addi      r3, r31, 0x224
  lfs       f0, -0x577C(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x220(r31)
  lwz       r0, -0x390(r13)
  stw       r0, 0x1C8(r1)
  lwz       r0, 0x1C8(r1)
  stw       r0, 0x1A8(r1)
  bl        -0xF3E00
  stw       r30, 0x22C(r31)
  addi      r5, r1, 0x1A4
  addi      r3, r31, 0x234
  lfs       f0, -0x5778(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x230(r31)
  lwz       r0, -0x38C(r13)
  stw       r0, 0x1D0(r1)
  lwz       r0, 0x1D0(r1)
  stw       r0, 0x1A4(r1)
  bl        -0xF3E2C
  stw       r30, 0x23C(r31)
  addi      r5, r1, 0x1A0
  addi      r3, r31, 0x244
  lfs       f0, -0x5774(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x240(r31)
  lwz       r0, -0x388(r13)
  stw       r0, 0x1D8(r1)
  lwz       r0, 0x1D8(r1)
  stw       r0, 0x1A0(r1)
  bl        -0xF3E58
  stw       r30, 0x24C(r31)
  addi      r5, r1, 0x19C
  addi      r3, r31, 0x254
  lfs       f0, -0x5770(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x250(r31)
  lwz       r0, -0x384(r13)
  stw       r0, 0x1E0(r1)
  lwz       r0, 0x1E0(r1)
  stw       r0, 0x19C(r1)
  bl        -0xF3E84
  stw       r30, 0x25C(r31)
  addi      r5, r1, 0x198
  addi      r3, r31, 0x264
  lfs       f0, -0x576C(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x260(r31)
  lwz       r0, -0x380(r13)
  stw       r0, 0x1E8(r1)
  lwz       r0, 0x1E8(r1)
  stw       r0, 0x198(r1)
  bl        -0xF3EB0
  stw       r30, 0x26C(r31)
  addi      r5, r1, 0x194
  addi      r3, r31, 0x274
  lfs       f0, -0x5768(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x270(r31)
  lwz       r0, -0x37C(r13)
  stw       r0, 0x1F0(r1)
  lwz       r0, 0x1F0(r1)
  stw       r0, 0x194(r1)
  bl        -0xF3EDC
  stw       r30, 0x27C(r31)
  addi      r5, r1, 0x190
  addi      r3, r31, 0x284
  lfs       f0, -0x5764(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x280(r31)
  lwz       r0, -0x378(r13)
  stw       r0, 0x1F8(r1)
  lwz       r0, 0x1F8(r1)
  stw       r0, 0x190(r1)
  bl        -0xF3F08
  stw       r30, 0x28C(r31)
  addi      r5, r1, 0x18C
  addi      r3, r31, 0x294
  lfs       f0, -0x5760(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x290(r31)
  lwz       r0, -0x374(r13)
  stw       r0, 0x200(r1)
  lwz       r0, 0x200(r1)
  stw       r0, 0x18C(r1)
  bl        -0xF3F34
  stw       r30, 0x29C(r31)
  addi      r5, r1, 0x188
  addi      r3, r31, 0x2A4
  lfs       f0, -0x5764(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x2A0(r31)
  lwz       r0, -0x370(r13)
  stw       r0, 0x208(r1)
  lwz       r0, 0x208(r1)
  stw       r0, 0x188(r1)
  bl        -0xF3F60
  stw       r30, 0x2AC(r31)
  addi      r5, r1, 0x184
  addi      r3, r31, 0x2B4
  lfs       f0, -0x575C(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x2B0(r31)
  lwz       r0, -0x36C(r13)
  stw       r0, 0x210(r1)
  lwz       r0, 0x210(r1)
  stw       r0, 0x184(r1)
  bl        -0xF3F8C
  stw       r30, 0x2BC(r31)
  addi      r5, r1, 0x180
  addi      r3, r31, 0x2C4
  lfs       f0, -0x5758(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x2C0(r31)
  lwz       r0, -0x368(r13)
  stw       r0, 0x218(r1)
  lwz       r0, 0x218(r1)
  stw       r0, 0x180(r1)
  bl        -0xF3FB8
  stw       r30, 0x2CC(r31)
  addi      r5, r1, 0x17C
  addi      r3, r31, 0x2D4
  lfs       f0, -0x5754(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x2D0(r31)
  lwz       r0, -0x364(r13)
  stw       r0, 0x220(r1)
  lwz       r0, 0x220(r1)
  stw       r0, 0x17C(r1)
  bl        -0xF3FE4
  stw       r30, 0x2DC(r31)
  addi      r5, r1, 0x178
  addi      r3, r31, 0x2E4
  lfs       f0, -0x5754(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x2E0(r31)
  lwz       r0, -0x360(r13)
  stw       r0, 0x228(r1)
  lwz       r0, 0x228(r1)
  stw       r0, 0x178(r1)
  bl        -0xF4010
  stw       r30, 0x2EC(r31)
  addi      r5, r1, 0x174
  addi      r3, r31, 0x2F4
  lfs       f0, -0x5750(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x2F0(r31)
  lwz       r0, -0x35C(r13)
  stw       r0, 0x230(r1)
  lwz       r0, 0x230(r1)
  stw       r0, 0x174(r1)
  bl        -0xF403C
  stw       r30, 0x2FC(r31)
  addi      r5, r1, 0x170
  addi      r3, r31, 0x304
  lfs       f0, -0x574C(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x300(r31)
  lwz       r0, -0x358(r13)
  stw       r0, 0x238(r1)
  lwz       r0, 0x238(r1)
  stw       r0, 0x170(r1)
  bl        -0xF4068
  stw       r30, 0x30C(r31)
  addi      r5, r1, 0x16C
  addi      r3, r31, 0x314
  lfs       f0, -0x5748(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x310(r31)
  lwz       r0, -0x354(r13)
  stw       r0, 0x240(r1)
  lwz       r0, 0x240(r1)
  stw       r0, 0x16C(r1)
  bl        -0xF4094
  stw       r30, 0x31C(r31)
  addi      r5, r1, 0x168
  addi      r3, r31, 0x324
  lfs       f0, -0x5744(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x320(r31)
  lwz       r0, -0x350(r13)
  stw       r0, 0x248(r1)
  lwz       r0, 0x248(r1)
  stw       r0, 0x168(r1)
  bl        -0xF40C0
  stw       r30, 0x32C(r31)
  addi      r5, r1, 0x164
  addi      r3, r31, 0x334
  lfs       f0, -0x5740(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x330(r31)
  lwz       r0, -0x34C(r13)
  stw       r0, 0x250(r1)
  lwz       r0, 0x250(r1)
  stw       r0, 0x164(r1)
  bl        -0xF40EC
  stw       r30, 0x33C(r31)
  addi      r5, r1, 0x160
  addi      r3, r31, 0x344
  lfs       f0, -0x573C(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x340(r31)
  lwz       r0, -0x348(r13)
  stw       r0, 0x258(r1)
  lwz       r0, 0x258(r1)
  stw       r0, 0x160(r1)
  bl        -0xF4118
  stw       r30, 0x34C(r31)
  addi      r5, r1, 0x15C
  addi      r3, r31, 0x354
  lfs       f0, -0x5738(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x350(r31)
  lwz       r0, -0x344(r13)
  stw       r0, 0x260(r1)
  lwz       r0, 0x260(r1)
  stw       r0, 0x15C(r1)
  bl        -0xF4144
  stw       r30, 0x35C(r31)
  addi      r5, r1, 0x158
  addi      r3, r31, 0x364
  lfs       f0, -0x5734(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x360(r31)
  lwz       r0, -0x340(r13)
  stw       r0, 0x268(r1)
  lwz       r0, 0x268(r1)
  stw       r0, 0x158(r1)
  bl        -0xF4170
  stw       r30, 0x36C(r31)
  addi      r5, r1, 0x154
  addi      r3, r31, 0x374
  lfs       f0, -0x5754(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x370(r31)
  lwz       r0, -0x33C(r13)
  stw       r0, 0x270(r1)
  lwz       r0, 0x270(r1)
  stw       r0, 0x154(r1)
  bl        -0xF419C
  stw       r30, 0x37C(r31)
  addi      r5, r1, 0x150
  addi      r3, r31, 0x384
  lfs       f0, -0x5730(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x380(r31)
  lwz       r0, -0x338(r13)
  stw       r0, 0x278(r1)
  lwz       r0, 0x278(r1)
  stw       r0, 0x150(r1)
  bl        -0xF41C8
  stw       r30, 0x38C(r31)
  addi      r5, r1, 0x14C
  addi      r3, r31, 0x394
  lfs       f0, -0x572C(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x390(r31)
  lwz       r0, -0x334(r13)
  stw       r0, 0x280(r1)
  lwz       r0, 0x280(r1)
  stw       r0, 0x14C(r1)
  bl        -0xF41F4
  stw       r30, 0x39C(r31)
  addi      r5, r1, 0x148
  addi      r3, r31, 0x3A4
  lfs       f0, -0x5728(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x3A0(r31)
  lwz       r0, -0x330(r13)
  stw       r0, 0x288(r1)
  lwz       r0, 0x288(r1)
  stw       r0, 0x148(r1)
  bl        -0xF4220
  stw       r30, 0x3AC(r31)
  addi      r5, r1, 0x144
  addi      r3, r31, 0x3B4
  lfs       f0, -0x572C(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x3B0(r31)
  lwz       r0, -0x32C(r13)
  stw       r0, 0x290(r1)
  lwz       r0, 0x290(r1)
  stw       r0, 0x144(r1)
  bl        -0xF424C
  stw       r30, 0x3BC(r31)
  addi      r5, r1, 0x140
  addi      r3, r31, 0x3C4
  lfs       f0, -0x5724(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x3C0(r31)
  lwz       r0, -0x328(r13)
  stw       r0, 0x298(r1)
  lwz       r0, 0x298(r1)
  stw       r0, 0x140(r1)
  bl        -0xF4278
  stw       r30, 0x3CC(r31)
  addi      r5, r1, 0x13C
  addi      r3, r31, 0x3D4
  lfs       f0, -0x5720(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x3D0(r31)
  lwz       r0, -0x324(r13)
  stw       r0, 0x2A0(r1)
  lwz       r0, 0x2A0(r1)
  stw       r0, 0x13C(r1)
  bl        -0xF42A4
  stw       r30, 0x3DC(r31)
  addi      r5, r1, 0x138
  addi      r3, r31, 0x3E4
  lfs       f0, -0x571C(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x3E0(r31)
  lwz       r0, -0x320(r13)
  stw       r0, 0x2A8(r1)
  lwz       r0, 0x2A8(r1)
  stw       r0, 0x138(r1)
  bl        -0xF42D0
  stw       r30, 0x3EC(r31)
  addi      r5, r1, 0x134
  addi      r3, r31, 0x3F4
  lfs       f0, -0x5720(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x3F0(r31)
  lwz       r0, -0x31C(r13)
  stw       r0, 0x2B0(r1)
  lwz       r0, 0x2B0(r1)
  stw       r0, 0x134(r1)
  bl        -0xF42FC
  stw       r30, 0x3FC(r31)
  addi      r5, r1, 0x130
  addi      r3, r31, 0x404
  lfs       f0, -0x5728(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x400(r31)
  lwz       r0, -0x318(r13)
  stw       r0, 0x2B8(r1)
  lwz       r0, 0x2B8(r1)
  stw       r0, 0x130(r1)
  bl        -0xF4328
  stw       r30, 0x40C(r31)
  addi      r5, r1, 0x12C
  addi      r3, r31, 0x414
  lfs       f0, -0x5718(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x410(r31)
  lwz       r0, -0x314(r13)
  stw       r0, 0x2C0(r1)
  lwz       r0, 0x2C0(r1)
  stw       r0, 0x12C(r1)
  bl        -0xF4354
  stw       r30, 0x41C(r31)
  addi      r5, r1, 0x128
  addi      r3, r31, 0x424
  lfs       f0, -0x5714(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x420(r31)
  lwz       r0, -0x310(r13)
  stw       r0, 0x2C8(r1)
  lwz       r0, 0x2C8(r1)
  stw       r0, 0x128(r1)
  bl        -0xF4380
  stw       r30, 0x42C(r31)
  addi      r5, r1, 0x124
  addi      r3, r31, 0x434
  lfs       f0, -0x5710(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x430(r31)
  lwz       r0, -0x30C(r13)
  stw       r0, 0x2D0(r1)
  lwz       r0, 0x2D0(r1)
  stw       r0, 0x124(r1)
  bl        -0xF43AC
  stw       r30, 0x43C(r31)
  addi      r5, r1, 0x120
  addi      r3, r31, 0x444
  lfs       f0, -0x570C(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x440(r31)
  lwz       r0, -0x308(r13)
  stw       r0, 0x2D8(r1)
  lwz       r0, 0x2D8(r1)
  stw       r0, 0x120(r1)
  bl        -0xF43D8
  stw       r30, 0x44C(r31)
  addi      r5, r1, 0x11C
  addi      r3, r31, 0x454
  lfs       f0, -0x5708(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x450(r31)
  lwz       r0, -0x304(r13)
  stw       r0, 0x2E0(r1)
  lwz       r0, 0x2E0(r1)
  stw       r0, 0x11C(r1)
  bl        -0xF4404
  stw       r30, 0x45C(r31)
  addi      r5, r1, 0x118
  addi      r3, r31, 0x464
  lfs       f0, -0x5704(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x460(r31)
  lwz       r0, -0x300(r13)
  stw       r0, 0x2E8(r1)
  lwz       r0, 0x2E8(r1)
  stw       r0, 0x118(r1)
  bl        -0xF4430
  stw       r30, 0x46C(r31)
  addi      r5, r1, 0x114
  addi      r3, r31, 0x474
  lfs       f0, -0x5700(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x470(r31)
  lwz       r0, -0x2FC(r13)
  stw       r0, 0x2F0(r1)
  lwz       r0, 0x2F0(r1)
  stw       r0, 0x114(r1)
  bl        -0xF445C
  stw       r30, 0x47C(r31)
  addi      r5, r1, 0x110
  addi      r3, r31, 0x484
  lfs       f0, -0x56FC(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x480(r31)
  lwz       r0, -0x2F8(r13)
  stw       r0, 0x2F8(r1)
  lwz       r0, 0x2F8(r1)
  stw       r0, 0x110(r1)
  bl        -0xF4488
  stw       r30, 0x48C(r31)
  addi      r5, r1, 0x10C
  addi      r3, r31, 0x494
  lfs       f0, -0x5770(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x490(r31)
  lwz       r0, -0x2F4(r13)
  stw       r0, 0x300(r1)
  lwz       r0, 0x300(r1)
  stw       r0, 0x10C(r1)
  bl        -0xF44B4
  stw       r30, 0x49C(r31)
  addi      r5, r1, 0x108
  addi      r3, r31, 0x4A4
  lfs       f0, -0x5770(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x4A0(r31)
  lwz       r0, -0x2F0(r13)
  stw       r0, 0x308(r1)
  lwz       r0, 0x308(r1)
  stw       r0, 0x108(r1)
  bl        -0xF44E0
  stw       r30, 0x4AC(r31)
  addi      r5, r1, 0x104
  addi      r3, r31, 0x4B4
  lfs       f0, -0x5754(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x4B0(r31)
  lwz       r0, -0x2EC(r13)
  stw       r0, 0x310(r1)
  lwz       r0, 0x310(r1)
  stw       r0, 0x104(r1)
  bl        -0xF450C
  stw       r30, 0x4BC(r31)
  addi      r5, r1, 0x100
  addi      r3, r31, 0x4C4
  lfs       f0, -0x5754(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x4C0(r31)
  lwz       r0, -0x2E8(r13)
  stw       r0, 0x318(r1)
  lwz       r0, 0x318(r1)
  stw       r0, 0x100(r1)
  bl        -0xF4538
  stw       r30, 0x4CC(r31)
  addi      r5, r1, 0xFC
  addi      r3, r31, 0x4D4
  lfs       f0, -0x56F8(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x4D0(r31)
  lwz       r0, -0x2E4(r13)
  stw       r0, 0x320(r1)
  lwz       r0, 0x320(r1)
  stw       r0, 0xFC(r1)
  bl        -0xF4564
  stw       r30, 0x4DC(r31)
  addi      r5, r1, 0xF8
  addi      r3, r31, 0x4E4
  lfs       f0, -0x5714(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x4E0(r31)
  lwz       r0, -0x2E0(r13)
  stw       r0, 0x328(r1)
  lwz       r0, 0x328(r1)
  stw       r0, 0xF8(r1)
  bl        -0xF4590
  stw       r30, 0x4EC(r31)
  addi      r5, r1, 0xF4
  addi      r3, r31, 0x4F4
  lfs       f0, -0x56F4(r2)
  addi      r4, r31, 0x200
  stfs      f0, 0x4F0(r31)
  lwz       r0, -0x2DC(r13)
  stw       r0, 0x330(r1)
  lwz       r0, 0x330(r1)
  stw       r0, 0xF4(r1)
  bl        -0xF45BC
  lis       r3, 0x802A
  addi      r29, r3, 0x60C4
  stw       r29, 0x4FC(r31)
  li        r30, 0x1
  addi      r5, r1, 0xF0
  stw       r30, 0x500(r31)
  addi      r3, r31, 0x504
  addi      r4, r31, 0x200
  lwz       r0, -0x2D8(r13)
  stw       r0, 0x338(r1)
  lwz       r0, 0x338(r1)
  stw       r0, 0xF0(r1)
  bl        -0xF45F0
  stw       r29, 0x50C(r31)
  li        r28, 0x2
  addi      r5, r1, 0xEC
  stw       r28, 0x510(r31)
  addi      r3, r31, 0x514
  addi      r4, r31, 0x200
  lwz       r0, -0x2D4(r13)
  stw       r0, 0x340(r1)
  lwz       r0, 0x340(r1)
  stw       r0, 0xEC(r1)
  bl        -0xF461C
  stw       r29, 0x51C(r31)
  addi      r5, r1, 0xE8
  addi      r3, r31, 0x524
  stw       r28, 0x520(r31)
  addi      r4, r31, 0x200
  lwz       r0, -0x2D0(r13)
  stw       r0, 0x348(r1)
  lwz       r0, 0x348(r1)
  stw       r0, 0xE8(r1)
  bl        -0xF4644
  stw       r29, 0x52C(r31)
  li        r0, 0x4
  addi      r5, r1, 0xE4
  stw       r0, 0x530(r31)
  addi      r3, r31, 0x534
  addi      r4, r31, 0x200
  lwz       r0, -0x2CC(r13)
  stw       r0, 0x350(r1)
  lwz       r0, 0x350(r1)
  stw       r0, 0xE4(r1)
  bl        -0xF4670
  stw       r29, 0x53C(r31)
  addi      r5, r1, 0xE0
  addi      r3, r31, 0x544
  stw       r30, 0x540(r31)
  addi      r4, r31, 0x200
  lwz       r0, -0x2C8(r13)
  stw       r0, 0x358(r1)
  lwz       r0, 0x358(r1)
  stw       r0, 0xE0(r1)
  bl        -0xF4698
  stw       r29, 0x54C(r31)
  mr        r3, r31
  stw       r30, 0x550(r31)
  lfs       f1, -0x5718(r2)
  stfs      f1, 0x10(r31)
  lfs       f0, -0x5730(r2)
  stfs      f0, 0x30(r31)
  stfs      f1, 0x40(r31)
  lwz       r0, 0x374(r1)
  lwz       r31, 0x36C(r1)
  lwz       r30, 0x368(r1)
  lwz       r29, 0x364(r1)
  lwz       r28, 0x360(r1)
  addi      r1, r1, 0x370
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8015315C
 * Size:	000140
 */
Spider::Spider(CreatureProp *)
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
  bl        -0x5300
  lis       r3, 0x802D
  subi      r0, r3, 0xD80
  stw       r0, 0x0(r31)
  addi      r3, r31, 0x3CC
  bl        -0xE9C5C
  li        r3, 0x14
  bl        -0x10C190
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x50
  li        r4, 0x18
  bl        -0xCA578

.loc_0x50:
  stw       r30, 0x220(r31)
  li        r3, 0xC
  bl        -0x10C1B0
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x70
  mr        r4, r31
  bl        0x678

.loc_0x70:
  stw       r30, 0x3C0(r31)
  li        r3, 0x68C
  bl        -0x10C1D0
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x90
  mr        r4, r31
  bl        0x3908

.loc_0x90:
  stw       r30, 0x3C4(r31)
  li        r30, 0
  subi      r0, r13, 0x2C4
  stw       r30, 0x3DC(r31)
  addi      r3, r31, 0x3CC
  stw       r30, 0x3D8(r31)
  stw       r30, 0x3D4(r31)
  stw       r0, 0x3D0(r31)
  bl        -0xE9BA8
  li        r3, 0x24
  bl        -0x10C210
  mr.       r29, r3
  beq-      .loc_0x11C
  lis       r3, 0x8022
  addi      r0, r3, 0x738C
  lis       r3, 0x8022
  stw       r0, 0x0(r29)
  addi      r0, r3, 0x737C
  stw       r0, 0x0(r29)
  addi      r3, r29, 0
  subi      r4, r13, 0x2C4
  stw       r30, 0x10(r29)
  stw       r30, 0xC(r29)
  stw       r30, 0x8(r29)
  bl        -0x12E378
  lis       r3, 0x8023
  subi      r0, r3, 0x71E0
  stw       r0, 0x0(r29)
  addi      r3, r29, 0
  subi      r4, r13, 0x2C4
  bl        -0x112B28
  lis       r3, 0x802D
  subi      r0, r3, 0xE2C
  stw       r0, 0x0(r29)
  stw       r31, 0x20(r29)

.loc_0x11C:
  stw       r29, 0x760(r31)
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
 * Address:	8015329C
 * Size:	000008
 */
void Spider::getiMass()
{
/*
.loc_0x0:
  lfs       f1, -0x5770(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	801532A4
 * Size:	0000C4
 */
void Spider::init(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0x1
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  li        r31, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  addi      r4, r30, 0
  lfs       f0, -0x56F0(r2)
  stfs      f0, 0x270(r3)
  stb       r0, 0x2BC(r3)
  stb       r31, 0x2BB(r3)
  stb       r31, 0x3B8(r3)
  stb       r0, 0x3B9(r3)
  stb       r31, 0x3BA(r3)
  stb       r0, 0x3BB(r3)
  stw       r31, 0x3BC(r3)
  lwz       r3, 0x3C0(r3)
  bl        0x570
  lwz       r3, 0x3C4(r30)
  mr        r4, r30
  bl        0x399C
  stb       r31, 0x3C9(r30)
  lis       r31, 0x6C65
  addi      r4, r31, 0x6731
  lfs       f0, -0x56EC(r2)
  li        r5, 0x3
  stfs      f0, 0x5AC(r30)
  lwz       r3, 0x220(r30)
  bl        -0xC9714
  lwz       r3, 0x220(r30)
  addi      r4, r31, 0x6732
  li        r5, 0x3
  bl        -0xC9724
  lwz       r3, 0x220(r30)
  addi      r4, r31, 0x6733
  li        r5, 0x3
  bl        -0xC9734
  lwz       r3, 0x220(r30)
  addi      r4, r31, 0x6734
  li        r5, 0x3
  bl        -0xC9744
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
 * Address:	80153368
 * Size:	000058
 */
void Spider::doKill()
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
  stb       r0, 0x3B8(r3)
  stb       r0, 0x2B8(r3)
  stb       r0, 0x2B9(r3)
  lwz       r3, 0x3C4(r3)
  bl        0x3444
  addi      r3, r31, 0x3CC
  bl        -0x112D8C
  lwz       r3, 0x3168(r13)
  mr        r4, r31
  bl        -0x1210
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801533C0
 * Size:	000028
 */
void Spider::exitCourse()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x3C4(r3)
  bl        0x3404
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801533E8
 * Size:	00006C
 */
void Spider::update()
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
  lwz       r3, 0x3C4(r31)
  bl        0x635C
  mr        r3, r31
  bl        -0xC641C
  lwz       r4, 0x2DEC(r13)
  mr        r3, r31
  lfs       f1, 0x28C(r4)
  bl        -0xC4E4C
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
 * Address:	........
 * Size:	000100
 */
void Spider::draw(Graphics &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80153454
 * Size:	00014C
 */
void Spider::refresh(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stfd      f31, 0x58(r1)
  addi      r0, r1, 0x14
  addi      r6, r1, 0x1C
  stfd      f30, 0x50(r1)
  stw       r31, 0x4C(r1)
  addi      r31, r4, 0
  mr        r4, r0
  stw       r30, 0x48(r1)
  addi      r30, r3, 0
  lwz       r5, 0x2F00(r13)
  lfs       f0, 0x9C(r3)
  lwz       r3, 0x4(r5)
  addi      r5, r1, 0x18
  lfs       f1, 0x1410(r3)
  addi      r7, r3, 0x1408
  addi      r3, r1, 0x34
  fsubs     f0, f1, f0
  stfs      f0, 0x1C(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x98(r30)
  fsubs     f0, f1, f0
  stfs      f0, 0x18(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x94(r30)
  fsubs     f0, f1, f0
  stfs      f0, 0x14(r1)
  bl        -0x11C3AC
  lfs       f31, 0x34(r1)
  lfs       f0, -0x5730(r2)
  fmuls     f1, f31, f31
  lfs       f30, 0x3C(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f30, f30
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x1458AC
  lfs       f0, -0x5730(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0xB0
  fdivs     f31, f31, f1
  fdivs     f30, f30, f1

.loc_0xB0:
  lfs       f1, -0x56E8(r2)
  mr        r5, r31
  lwz       r3, 0x3C4(r30)
  fmuls     f31, f31, f1
  lfs       f2, -0x56E4(r2)
  lfs       f0, 0x264(r3)
  fmuls     f30, f30, f1
  lfs       f1, 0x98(r30)
  fadds     f0, f0, f31
  lfs       f3, 0x26C(r3)
  fadds     f2, f2, f1
  fadds     f1, f3, f30
  stfs      f0, 0x748(r30)
  stfs      f2, 0x74C(r30)
  stfs      f1, 0x750(r30)
  lwz       r4, 0x3C4(r30)
  lfs       f2, -0x575C(r2)
  lfs       f1, 0x98(r30)
  lfs       f0, 0x264(r4)
  fadds     f1, f2, f1
  stfs      f0, 0x754(r30)
  stfs      f1, 0x758(r30)
  lfs       f0, 0x26C(r4)
  stfs      f0, 0x75C(r30)
  lwz       r3, 0x3C4(r30)
  lwz       r4, 0x390(r30)
  bl        0x64EC
  lwz       r3, 0x220(r30)
  addi      r4, r31, 0
  li        r5, 0
  bl        -0xC9A90
  lwz       r0, 0x64(r1)
  lfd       f31, 0x58(r1)
  lfd       f30, 0x50(r1)
  lwz       r31, 0x4C(r1)
  lwz       r30, 0x48(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801535A0
 * Size:	000078
 */
void Spider::drawShape(Graphics &)
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
  bl        -0x11DFD0
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
  bl        -0x123190
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
 * Address:	80153618
 * Size:	000024
 */
void Spider::doAI()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x3C0(r3)
  bl        0x9E8
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8015363C
 * Size:	000044
 */
void Spider::doAnimation()
{
/*
.loc_0x0:
  mflr      r0
  mr        r4, r3
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x390(r3)
  cmplwi    r0, 0
  beq-      .loc_0x34
  lwz       r12, 0x36C(r4)
  addi      r3, r4, 0x33C
  lfs       f1, 0x2D8(r4)
  lwz       r12, 0xC(r12)
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
 * Address:	80153680
 * Size:	000160
 */
void SpiderDrawer::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x68(r1)
  stfd      f31, 0x60(r1)
  addi      r0, r1, 0x14
  addi      r6, r1, 0x1C
  stfd      f30, 0x58(r1)
  stw       r31, 0x54(r1)
  stw       r30, 0x50(r1)
  addi      r30, r4, 0
  mr        r4, r0
  stw       r29, 0x4C(r1)
  mr        r29, r3
  lwz       r5, 0x2F00(r13)
  lwz       r31, 0x20(r3)
  lwz       r3, 0x4(r5)
  addi      r5, r1, 0x18
  lfs       f0, 0x9C(r31)
  lfs       f1, 0x1410(r3)
  addi      r7, r3, 0x1408
  addi      r3, r1, 0x34
  fsubs     f0, f1, f0
  stfs      f0, 0x1C(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x98(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0x18(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x94(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0x14(r1)
  bl        -0x11C5E0
  lfs       f31, 0x34(r1)
  lfs       f0, -0x5730(r2)
  fmuls     f1, f31, f31
  lfs       f30, 0x3C(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f30, f30
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x145AE0
  lfs       f0, -0x5730(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0xB8
  fdivs     f31, f31, f1
  fdivs     f30, f30, f1

.loc_0xB8:
  lfs       f1, -0x56E8(r2)
  mr        r5, r30
  lwz       r3, 0x3C4(r31)
  fmuls     f31, f31, f1
  lfs       f2, -0x56E4(r2)
  lfs       f0, 0x264(r3)
  fmuls     f30, f30, f1
  lfs       f1, 0x98(r31)
  fadds     f0, f0, f31
  lfs       f3, 0x26C(r3)
  fadds     f2, f2, f1
  fadds     f1, f3, f30
  stfs      f0, 0x748(r31)
  stfs      f2, 0x74C(r31)
  stfs      f1, 0x750(r31)
  lwz       r4, 0x3C4(r31)
  lfs       f2, -0x575C(r2)
  lfs       f1, 0x98(r31)
  lfs       f0, 0x264(r4)
  fadds     f1, f2, f1
  stfs      f0, 0x754(r31)
  stfs      f1, 0x758(r31)
  lfs       f0, 0x26C(r4)
  stfs      f0, 0x75C(r31)
  lwz       r3, 0x3C4(r31)
  lwz       r4, 0x390(r31)
  bl        0x62B8
  lwz       r3, 0x20(r29)
  mr        r4, r30
  lwz       r12, 0x0(r3)
  lwz       r12, 0x120(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x6C(r1)
  lfd       f31, 0x60(r1)
  lfd       f30, 0x58(r1)
  lwz       r31, 0x54(r1)
  lwz       r30, 0x50(r1)
  lwz       r29, 0x4C(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801537E0
 * Size:	000008
 */
void Spider::isBossBgm()
{
/*
.loc_0x0:
  lbz       r3, 0x3B8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801537E8
 * Size:	000050
 */
void SpiderProp::read(RandomAccessStream &)
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
  bl        -0xF4C6C
  addi      r3, r30, 0x58
  addi      r4, r31, 0
  bl        -0xF4C78
  addi      r3, r30, 0x200
  addi      r4, r31, 0
  bl        -0xF4C84
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
 * Address:	80153838
 * Size:	000008
 */
void SpiderProp::@492@read(RandomAccessStream &)
{
/*
.loc_0x0:
  subi      r3, r3, 0x1EC
  b         -0x54
*/
}
