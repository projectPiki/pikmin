#include "types.h"

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
 * Address:	80083E60
 * Size:	00004C
 */
void AIConstant::createInstance()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  lwz       r0, 0x2F80(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x38
	  li        r3, 0x194
	  bl        -0x3CE7C
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x34
	  bl        .loc_0x4C

	.loc_0x34:
	  stw       r31, 0x2F80(r13)

	.loc_0x38:
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr

	.loc_0x4C:
	*/
}

/*
 * --INFO--
 * Address:	80083EAC
 * Size:	000470
 */
AIConstant::AIConstant()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x738C
	  subi      r4, r13, 0x6038
	  stwu      r1, -0x198(r1)
	  stmw      r27, 0x184(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x8022
	  li        r27, 0
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x737C
	  addi      r3, r31, 0
	  stw       r0, 0x0(r31)
	  stw       r27, 0x10(r31)
	  stw       r27, 0xC(r31)
	  stw       r27, 0x8(r31)
	  bl        -0x5F01C
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6038
	  bl        -0x437CC
	  lis       r3, 0x802B
	  subi      r0, r3, 0x186C
	  stw       r0, 0x0(r31)
	  addi      r5, r1, 0xC0
	  addi      r3, r31, 0x24
	  stw       r27, 0x20(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x6030(r13)
	  stw       r0, 0xC8(r1)
	  lwz       r0, 0xC8(r1)
	  stw       r0, 0xC0(r1)
	  bl        -0x254B8
	  lis       r3, 0x802A
	  addi      r28, r3, 0x6098
	  stw       r28, 0x2C(r31)
	  addi      r5, r1, 0xBC
	  addi      r3, r31, 0x34
	  lfs       f0, -0x75E0(r2)
	  addi      r4, r31, 0x20
	  stfs      f0, 0x30(r31)
	  lwz       r0, -0x602C(r13)
	  stw       r0, 0xD0(r1)
	  lwz       r0, 0xD0(r1)
	  stw       r0, 0xBC(r1)
	  bl        -0x254EC
	  lis       r3, 0x802A
	  addi      r30, r3, 0x60C4
	  stw       r30, 0x3C(r31)
	  li        r29, 0x1
	  addi      r5, r1, 0xB8
	  stw       r29, 0x40(r31)
	  addi      r3, r31, 0x44
	  addi      r4, r31, 0x20
	  lwz       r0, -0x6028(r13)
	  stw       r0, 0xD8(r1)
	  lwz       r0, 0xD8(r1)
	  stw       r0, 0xB8(r1)
	  bl        -0x25520
	  stw       r30, 0x4C(r31)
	  addi      r5, r1, 0xB4
	  addi      r3, r31, 0x54
	  stw       r29, 0x50(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x6024(r13)
	  stw       r0, 0xE0(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r0, 0xB4(r1)
	  bl        -0x25548
	  stw       r30, 0x5C(r31)
	  addi      r5, r1, 0xB0
	  addi      r3, r31, 0x64
	  stw       r27, 0x60(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x6020(r13)
	  stw       r0, 0xE8(r1)
	  lwz       r0, 0xE8(r1)
	  stw       r0, 0xB0(r1)
	  bl        -0x25570
	  stw       r30, 0x6C(r31)
	  addi      r5, r1, 0xAC
	  addi      r3, r31, 0x74
	  stw       r29, 0x70(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x601C(r13)
	  stw       r0, 0xF0(r1)
	  lwz       r0, 0xF0(r1)
	  stw       r0, 0xAC(r1)
	  bl        -0x25598
	  stw       r30, 0x7C(r31)
	  addi      r5, r1, 0xA8
	  addi      r3, r31, 0x84
	  stw       r29, 0x80(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x6018(r13)
	  stw       r0, 0xF8(r1)
	  lwz       r0, 0xF8(r1)
	  stw       r0, 0xA8(r1)
	  bl        -0x255C0
	  stw       r30, 0x8C(r31)
	  addi      r5, r1, 0xA4
	  addi      r3, r31, 0x94
	  stw       r29, 0x90(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x6014(r13)
	  stw       r0, 0x100(r1)
	  lwz       r0, 0x100(r1)
	  stw       r0, 0xA4(r1)
	  bl        -0x255E8
	  stw       r30, 0x9C(r31)
	  addi      r5, r1, 0xA0
	  addi      r3, r31, 0xA4
	  stw       r29, 0xA0(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x6010(r13)
	  stw       r0, 0x108(r1)
	  lwz       r0, 0x108(r1)
	  stw       r0, 0xA0(r1)
	  bl        -0x25610
	  stw       r30, 0xAC(r31)
	  addi      r5, r1, 0x9C
	  addi      r3, r31, 0xB4
	  stw       r29, 0xB0(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x600C(r13)
	  stw       r0, 0x110(r1)
	  lwz       r0, 0x110(r1)
	  stw       r0, 0x9C(r1)
	  bl        -0x25638
	  stw       r30, 0xBC(r31)
	  addi      r5, r1, 0x98
	  addi      r3, r31, 0xC4
	  stw       r29, 0xC0(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x6008(r13)
	  stw       r0, 0x118(r1)
	  lwz       r0, 0x118(r1)
	  stw       r0, 0x98(r1)
	  bl        -0x25660
	  stw       r30, 0xCC(r31)
	  addi      r5, r1, 0x94
	  addi      r3, r31, 0xD4
	  stw       r29, 0xD0(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x6004(r13)
	  stw       r0, 0x120(r1)
	  lwz       r0, 0x120(r1)
	  stw       r0, 0x94(r1)
	  bl        -0x25688
	  stw       r28, 0xDC(r31)
	  addi      r5, r1, 0x90
	  addi      r3, r31, 0xE4
	  lfs       f0, -0x75DC(r2)
	  addi      r4, r31, 0x20
	  stfs      f0, 0xE0(r31)
	  lwz       r0, -0x6000(r13)
	  stw       r0, 0x128(r1)
	  lwz       r0, 0x128(r1)
	  stw       r0, 0x90(r1)
	  bl        -0x256B4
	  stw       r30, 0xEC(r31)
	  addi      r5, r1, 0x8C
	  addi      r3, r31, 0xF4
	  stw       r29, 0xF0(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x5FFC(r13)
	  stw       r0, 0x130(r1)
	  lwz       r0, 0x130(r1)
	  stw       r0, 0x8C(r1)
	  bl        -0x256DC
	  stw       r30, 0xFC(r31)
	  addi      r5, r1, 0x88
	  addi      r3, r31, 0x104
	  stw       r29, 0x100(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x5FF8(r13)
	  stw       r0, 0x138(r1)
	  lwz       r0, 0x138(r1)
	  stw       r0, 0x88(r1)
	  bl        -0x25704
	  stw       r30, 0x10C(r31)
	  addi      r5, r1, 0x84
	  addi      r3, r31, 0x114
	  stw       r29, 0x110(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x5FF4(r13)
	  stw       r0, 0x140(r1)
	  lwz       r0, 0x140(r1)
	  stw       r0, 0x84(r1)
	  bl        -0x2572C
	  stw       r30, 0x11C(r31)
	  li        r0, 0x64
	  addi      r5, r1, 0x80
	  stw       r0, 0x120(r31)
	  addi      r3, r31, 0x124
	  addi      r4, r31, 0x20
	  lwz       r0, -0x5FF0(r13)
	  stw       r0, 0x148(r1)
	  lwz       r0, 0x148(r1)
	  stw       r0, 0x80(r1)
	  bl        -0x25758
	  stw       r30, 0x12C(r31)
	  addi      r5, r1, 0x7C
	  addi      r3, r31, 0x134
	  stw       r29, 0x130(r31)
	  addi      r4, r31, 0x20
	  lwz       r0, -0x5FEC(r13)
	  stw       r0, 0x150(r1)
	  lwz       r0, 0x150(r1)
	  stw       r0, 0x7C(r1)
	  bl        -0x25780
	  stw       r28, 0x13C(r31)
	  addi      r5, r1, 0x78
	  addi      r3, r31, 0x144
	  lfs       f0, -0x75D8(r2)
	  addi      r4, r31, 0x20
	  stfs      f0, 0x140(r31)
	  lwz       r0, -0x5FE8(r13)
	  stw       r0, 0x158(r1)
	  lwz       r0, 0x158(r1)
	  stw       r0, 0x78(r1)
	  bl        -0x257AC
	  stw       r28, 0x14C(r31)
	  addi      r5, r1, 0x74
	  addi      r3, r31, 0x154
	  lfs       f0, -0x75D4(r2)
	  addi      r4, r31, 0x20
	  stfs      f0, 0x150(r31)
	  lwz       r0, -0x5FE4(r13)
	  stw       r0, 0x160(r1)
	  lwz       r0, 0x160(r1)
	  stw       r0, 0x74(r1)
	  bl        -0x257D8
	  stw       r30, 0x15C(r31)
	  li        r0, 0x6
	  addi      r5, r1, 0x70
	  stw       r0, 0x160(r31)
	  addi      r3, r31, 0x164
	  addi      r4, r31, 0x20
	  lwz       r0, -0x5FE0(r13)
	  stw       r0, 0x168(r1)
	  lwz       r0, 0x168(r1)
	  stw       r0, 0x70(r1)
	  bl        -0x25804
	  stw       r30, 0x16C(r31)
	  li        r0, 0xC
	  addi      r5, r1, 0x6C
	  stw       r0, 0x170(r31)
	  addi      r3, r31, 0x174
	  addi      r4, r31, 0x20
	  lwz       r0, -0x5FDC(r13)
	  stw       r0, 0x170(r1)
	  lwz       r0, 0x170(r1)
	  stw       r0, 0x6C(r1)
	  bl        -0x25830
	  stw       r30, 0x17C(r31)
	  li        r0, 0x1D
	  addi      r5, r1, 0x68
	  stw       r0, 0x180(r31)
	  addi      r3, r31, 0x184
	  addi      r4, r31, 0x20
	  lwz       r0, -0x5FD8(r13)
	  stw       r0, 0x178(r1)
	  lwz       r0, 0x178(r1)
	  stw       r0, 0x68(r1)
	  bl        -0x2585C
	  stw       r30, 0x18C(r31)
	  li        r0, 0x1E
	  lis       r3, 0x802B
	  stw       r0, 0x190(r31)
	  subi      r5, r3, 0x1930
	  addi      r3, r31, 0
	  subi      r4, r13, 0x5FD4
	  li        r6, 0x1
	  bl        -0x43C60
	  mr        r3, r31
	  lmw       r27, 0x184(r1)
	  lwz       r0, 0x19C(r1)
	  addi      r1, r1, 0x198
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008431C
 * Size:	000024
 */
void AIConstant::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r3, 0x20
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x25794
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
