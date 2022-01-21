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
 * Address:	80118D04
 * Size:	000CD0
 */
void PaniPikiAnimator::createMotionTable()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x8
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  bl        -0xD1D18
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x30
	  li        r4, 0x5A
	  bl        0x62D8

	.loc_0x30:
	  li        r3, 0x8
	  bl        -0xD1D34
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x4C
	  li        r4, 0
	  bl        0x627C

	.loc_0x4C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x0(r4)
	  bl        -0xD1D58
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x70
	  li        r4, 0x4
	  bl        0x6258

	.loc_0x70:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x4(r4)
	  bl        -0xD1D7C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x94
	  li        r4, 0x19
	  bl        0x6234

	.loc_0x94:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x8(r4)
	  bl        -0xD1DA0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xB8
	  li        r4, 0xC
	  bl        0x6210

	.loc_0xB8:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xC(r4)
	  bl        -0xD1DC4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xDC
	  li        r4, 0x1
	  bl        0x61EC

	.loc_0xDC:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x10(r4)
	  bl        -0xD1DE8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x100
	  li        r4, 0x1C
	  bl        0x61C8

	.loc_0x100:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x14(r4)
	  bl        -0xD1E0C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x124
	  li        r4, 0x1D
	  bl        0x61A4

	.loc_0x124:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x18(r4)
	  bl        -0xD1E30
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x148
	  li        r4, 0x14
	  bl        0x6180

	.loc_0x148:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x1C(r4)
	  bl        -0xD1E54
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x16C
	  li        r4, 0x2A
	  bl        0x615C

	.loc_0x16C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x20(r4)
	  bl        -0xD1E78
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x190
	  li        r4, 0x30
	  bl        0x6138

	.loc_0x190:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x24(r4)
	  bl        -0xD1E9C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1B4
	  li        r4, 0x15
	  bl        0x6114

	.loc_0x1B4:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x28(r4)
	  bl        -0xD1EC0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1D8
	  li        r4, 0x2C
	  bl        0x60F0

	.loc_0x1D8:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x2C(r4)
	  bl        -0xD1EE4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1FC
	  li        r4, 0x2D
	  bl        0x60CC

	.loc_0x1FC:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x30(r4)
	  bl        -0xD1F08
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x220
	  li        r4, 0x34
	  bl        0x60A8

	.loc_0x220:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x34(r4)
	  bl        -0xD1F2C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x244
	  li        r4, 0x35
	  bl        0x6084

	.loc_0x244:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x38(r4)
	  bl        -0xD1F50
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x268
	  li        r4, 0x22
	  bl        0x6060

	.loc_0x268:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x3C(r4)
	  bl        -0xD1F74
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x28C
	  li        r4, 0x27
	  bl        0x603C

	.loc_0x28C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x44(r4)
	  bl        -0xD1F98
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x2B0
	  li        r4, 0x28
	  bl        0x6018

	.loc_0x2B0:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x48(r4)
	  bl        -0xD1FBC
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x2D4
	  li        r4, 0x29
	  bl        0x5FF4

	.loc_0x2D4:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x4C(r4)
	  bl        -0xD1FE0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x2F8
	  li        r4, 0x18
	  bl        0x5FD0

	.loc_0x2F8:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x50(r4)
	  bl        -0xD2004
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x31C
	  li        r4, 0x9
	  bl        0x5FAC

	.loc_0x31C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x54(r4)
	  bl        -0xD2028
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x340
	  li        r4, 0xD
	  bl        0x5F88

	.loc_0x340:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x58(r4)
	  bl        -0xD204C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x364
	  li        r4, 0x12
	  bl        0x5F64

	.loc_0x364:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x5C(r4)
	  bl        -0xD2070
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x388
	  li        r4, 0x21
	  bl        0x5F40

	.loc_0x388:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x60(r4)
	  bl        -0xD2094
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x3AC
	  li        r4, 0x5E
	  bl        0x5F1C

	.loc_0x3AC:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x64(r4)
	  bl        -0xD20B8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x3D0
	  li        r4, 0x24
	  bl        0x5EF8

	.loc_0x3D0:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x68(r4)
	  bl        -0xD20DC
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x3F4
	  li        r4, 0x36
	  bl        0x5ED4

	.loc_0x3F4:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x6C(r4)
	  bl        -0xD2100
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x418
	  li        r4, 0x37
	  bl        0x5EB0

	.loc_0x418:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x70(r4)
	  bl        -0xD2124
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x43C
	  li        r4, 0x38
	  bl        0x5E8C

	.loc_0x43C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x74(r4)
	  bl        -0xD2148
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x460
	  li        r4, 0x39
	  bl        0x5E68

	.loc_0x460:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x78(r4)
	  bl        -0xD216C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x484
	  li        r4, 0x3A
	  bl        0x5E44

	.loc_0x484:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x7C(r4)
	  bl        -0xD2190
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x4A8
	  li        r4, 0x3B
	  bl        0x5E20

	.loc_0x4A8:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x80(r4)
	  bl        -0xD21B4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x4CC
	  li        r4, 0x3C
	  bl        0x5DFC

	.loc_0x4CC:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x84(r4)
	  bl        -0xD21D8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x4F0
	  li        r4, 0x3D
	  bl        0x5DD8

	.loc_0x4F0:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x88(r4)
	  bl        -0xD21FC
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x514
	  li        r4, 0x3E
	  bl        0x5DB4

	.loc_0x514:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x8C(r4)
	  bl        -0xD2220
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x538
	  li        r4, 0x3F
	  bl        0x5D90

	.loc_0x538:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x90(r4)
	  bl        -0xD2244
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x55C
	  li        r4, 0x40
	  bl        0x5D6C

	.loc_0x55C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x94(r4)
	  bl        -0xD2268
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x580
	  li        r4, 0x1F
	  bl        0x5D48

	.loc_0x580:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x98(r4)
	  bl        -0xD228C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x5A4
	  li        r4, 0xA
	  bl        0x5D24

	.loc_0x5A4:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x9C(r4)
	  bl        -0xD22B0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x5C8
	  li        r4, 0x10
	  bl        0x5D00

	.loc_0x5C8:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xA0(r4)
	  bl        -0xD22D4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x5EC
	  li        r4, 0x3
	  bl        0x5CDC

	.loc_0x5EC:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xA4(r4)
	  bl        -0xD22F8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x610
	  li        r4, 0x26
	  bl        0x5CB8

	.loc_0x610:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xA8(r4)
	  bl        -0xD231C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x634
	  li        r4, 0x2F
	  bl        0x5C94

	.loc_0x634:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xAC(r4)
	  bl        -0xD2340
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x658
	  li        r4, 0x20
	  bl        0x5C70

	.loc_0x658:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xB0(r4)
	  bl        -0xD2364
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x67C
	  li        r4, 0x42
	  bl        0x5C4C

	.loc_0x67C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xB4(r4)
	  bl        -0xD2388
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x6A0
	  li        r4, 0x44
	  bl        0x5C28

	.loc_0x6A0:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xB8(r4)
	  bl        -0xD23AC
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x6C4
	  li        r4, 0x43
	  bl        0x5C04

	.loc_0x6C4:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xBC(r4)
	  bl        -0xD23D0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x6E8
	  li        r4, 0x47
	  bl        0x5BE0

	.loc_0x6E8:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xC0(r4)
	  bl        -0xD23F4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x70C
	  li        r4, 0x4A
	  bl        0x5BBC

	.loc_0x70C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xC4(r4)
	  bl        -0xD2418
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x730
	  li        r4, 0x4B
	  bl        0x5B98

	.loc_0x730:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xC8(r4)
	  bl        -0xD243C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x754
	  li        r4, 0x4C
	  bl        0x5B74

	.loc_0x754:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xCC(r4)
	  bl        -0xD2460
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x778
	  li        r4, 0x4D
	  bl        0x5B50

	.loc_0x778:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xD0(r4)
	  bl        -0xD2484
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x79C
	  li        r4, 0x4E
	  bl        0x5B2C

	.loc_0x79C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xD4(r4)
	  bl        -0xD24A8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x7C0
	  li        r4, 0x4F
	  bl        0x5B08

	.loc_0x7C0:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xD8(r4)
	  bl        -0xD24CC
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x7E4
	  li        r4, 0x50
	  bl        0x5AE4

	.loc_0x7E4:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xDC(r4)
	  bl        -0xD24F0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x808
	  li        r4, 0x51
	  bl        0x5AC0

	.loc_0x808:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xE0(r4)
	  bl        -0xD2514
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x82C
	  li        r4, 0x52
	  bl        0x5A9C

	.loc_0x82C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xE4(r4)
	  bl        -0xD2538
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x850
	  li        r4, 0x53
	  bl        0x5A78

	.loc_0x850:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xE8(r4)
	  bl        -0xD255C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x874
	  li        r4, 0x54
	  bl        0x5A54

	.loc_0x874:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xEC(r4)
	  bl        -0xD2580
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x898
	  li        r4, 0x55
	  bl        0x5A30

	.loc_0x898:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xF0(r4)
	  bl        -0xD25A4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x8BC
	  li        r4, 0x56
	  bl        0x5A0C

	.loc_0x8BC:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xF4(r4)
	  bl        -0xD25C8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x8E0
	  li        r4, 0x57
	  bl        0x59E8

	.loc_0x8E0:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xF8(r4)
	  bl        -0xD25EC
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x904
	  li        r4, 0x58
	  bl        0x59C4

	.loc_0x904:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0xFC(r4)
	  bl        -0xD2610
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x928
	  li        r4, 0x59
	  bl        0x59A0

	.loc_0x928:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x100(r4)
	  bl        -0xD2634
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x94C
	  li        r4, 0x5A
	  bl        0x597C

	.loc_0x94C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x104(r4)
	  bl        -0xD2658
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x970
	  li        r4, 0x5B
	  bl        0x5958

	.loc_0x970:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x108(r4)
	  bl        -0xD267C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x994
	  li        r4, 0x5C
	  bl        0x5934

	.loc_0x994:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x10C(r4)
	  bl        -0xD26A0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x9B8
	  li        r4, 0x5F
	  bl        0x5910

	.loc_0x9B8:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x114(r4)
	  bl        -0xD26C4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x9DC
	  li        r4, 0x8
	  bl        0x58EC

	.loc_0x9DC:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x118(r4)
	  bl        -0xD26E8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xA00
	  li        r4, 0x1A
	  bl        0x58C8

	.loc_0xA00:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x11C(r4)
	  bl        -0xD270C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xA24
	  li        r4, 0x23
	  bl        0x58A4

	.loc_0xA24:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x40(r4)
	  bl        -0xD2730
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xA48
	  li        r4, 0x5
	  bl        0x5880

	.loc_0xA48:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x120(r4)
	  bl        -0xD2754
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xA6C
	  li        r4, 0x6
	  bl        0x585C

	.loc_0xA6C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x124(r4)
	  bl        -0xD2778
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xA90
	  li        r4, 0x7
	  bl        0x5838

	.loc_0xA90:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x128(r4)
	  bl        -0xD279C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xAB4
	  li        r4, 0xE
	  bl        0x5814

	.loc_0xAB4:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x12C(r4)
	  bl        -0xD27C0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xAD8
	  li        r4, 0xB
	  bl        0x57F0

	.loc_0xAD8:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x130(r4)
	  bl        -0xD27E4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xAFC
	  li        r4, 0x11
	  bl        0x57CC

	.loc_0xAFC:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x134(r4)
	  bl        -0xD2808
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xB20
	  li        r4, 0x13
	  bl        0x57A8

	.loc_0xB20:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x138(r4)
	  bl        -0xD282C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xB44
	  li        r4, 0x1B
	  bl        0x5784

	.loc_0xB44:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x13C(r4)
	  bl        -0xD2850
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xB68
	  li        r4, 0x25
	  bl        0x5760

	.loc_0xB68:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x140(r4)
	  bl        -0xD2874
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xB8C
	  li        r4, 0x16
	  bl        0x573C

	.loc_0xB8C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x144(r4)
	  bl        -0xD2898
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xBB0
	  li        r4, 0x2B
	  bl        0x5718

	.loc_0xBB0:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x148(r4)
	  bl        -0xD28BC
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xBD4
	  li        r4, 0x5D
	  bl        0x56F4

	.loc_0xBD4:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x14C(r4)
	  bl        -0xD28E0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xBF8
	  li        r4, 0x45
	  bl        0x56D0

	.loc_0xBF8:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x150(r4)
	  bl        -0xD2904
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xC1C
	  li        r4, 0x48
	  bl        0x56AC

	.loc_0xC1C:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x154(r4)
	  bl        -0xD2928
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xC40
	  li        r4, 0x60
	  bl        0x5688

	.loc_0xC40:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x158(r4)
	  bl        -0xD294C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xC64
	  li        r4, 0x61
	  bl        0x5664

	.loc_0xC64:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x15C(r4)
	  bl        -0xD2970
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xC88
	  li        r4, 0x62
	  bl        0x5640

	.loc_0xC88:
	  lwz       r4, 0x4(r31)
	  li        r3, 0x8
	  stw       r30, 0x160(r4)
	  bl        -0xD2994
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xCAC
	  li        r4, 0x63
	  bl        0x561C

	.loc_0xCAC:
	  lwz       r4, 0x4(r31)
	  mr        r3, r31
	  stw       r30, 0x164(r4)
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
 * Address:	801199D4
 * Size:	00003C
 */
PaniPikiAnimator::PaniPikiAnimator()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        0x56F8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x37A4
	  stw       r0, 0x30(r31)
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
