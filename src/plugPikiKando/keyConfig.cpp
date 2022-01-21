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
 * Address:	800846C0
 * Size:	00004C
 */
void KeyConfig::createInstance()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  lwz       r0, 0x2F98(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x38
	  li        r3, 0xF8
	  bl        -0x3D6DC
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x34
	  bl        .loc_0x4C

	.loc_0x34:
	  stw       r31, 0x2F98(r13)

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
 * Address:	8008470C
 * Size:	0001DC
 */
KeyConfig::KeyConfig()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x738C
	  lis       r4, 0x802B
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x8022
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  subi      r28, r4, 0x1820
	  subi      r4, r13, 0x5F80
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x737C
	  addi      r3, r31, 0
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  stw       r0, 0x10(r31)
	  stw       r0, 0xC(r31)
	  stw       r0, 0x8(r31)
	  bl        -0x5F890
	  lis       r3, 0x8023
	  subi      r29, r3, 0x71E0
	  stw       r29, 0x0(r31)
	  addi      r3, r31, 0
	  subi      r4, r13, 0x5F80
	  bl        -0x44040
	  lis       r3, 0x802B
	  subi      r0, r3, 0x172C
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0x20
	  subi      r4, r13, 0x5F80
	  bl        -0x4F7DC
	  stw       r29, 0x20(r31)
	  addi      r3, r31, 0x20
	  subi      r4, r13, 0x5F80
	  bl        -0x44068
	  lis       r3, 0x802B
	  subi      r30, r3, 0x1784
	  stw       r30, 0x20(r31)
	  addi      r3, r31, 0x44
	  subi      r4, r13, 0x5F80
	  bl        -0x4F804
	  stw       r29, 0x44(r31)
	  addi      r3, r31, 0x44
	  subi      r4, r13, 0x5F80
	  bl        -0x44090
	  stw       r30, 0x44(r31)
	  addi      r3, r31, 0x68
	  subi      r4, r13, 0x5F80
	  bl        -0x4F824
	  stw       r29, 0x68(r31)
	  addi      r3, r31, 0x68
	  subi      r4, r13, 0x5F80
	  bl        -0x440B0
	  stw       r30, 0x68(r31)
	  addi      r3, r31, 0x8C
	  subi      r4, r13, 0x5F80
	  bl        -0x4F844
	  stw       r29, 0x8C(r31)
	  addi      r3, r31, 0x8C
	  subi      r4, r13, 0x5F80
	  bl        -0x440D0
	  stw       r30, 0x8C(r31)
	  addi      r3, r31, 0xB0
	  subi      r4, r13, 0x5F80
	  bl        -0x4F864
	  stw       r29, 0xB0(r31)
	  addi      r3, r31, 0xB0
	  subi      r4, r13, 0x5F80
	  bl        -0x440F0
	  stw       r30, 0xB0(r31)
	  addi      r3, r31, 0xD4
	  subi      r4, r13, 0x5F80
	  bl        -0x4F884
	  stw       r29, 0xD4(r31)
	  addi      r3, r31, 0xD4
	  subi      r4, r13, 0x5F80
	  bl        -0x44110
	  stw       r30, 0xD4(r31)
	  subi      r0, r13, 0x5F78
	  lis       r3, 0x1
	  stw       r0, 0x24(r31)
	  li        r10, 0x1000
	  addi      r5, r28, 0x1C
	  stw       r10, 0x40(r31)
	  li        r4, 0x2000
	  subi      r0, r13, 0x5F70
	  stw       r5, 0x48(r31)
	  addi      r6, r28, 0x2C
	  subi      r9, r13, 0x5F68
	  stw       r4, 0x64(r31)
	  li        r8, 0x4000
	  addi      r7, r28, 0x38
	  stw       r0, 0x6C(r31)
	  subi      r0, r3, 0x8000
	  addi      r3, r31, 0
	  stw       r4, 0x88(r31)
	  subi      r4, r13, 0x5F60
	  subi      r5, r13, 0x5F58
	  stw       r6, 0x90(r31)
	  li        r6, 0x1
	  stw       r10, 0xAC(r31)
	  stw       r9, 0xD8(r31)
	  stw       r8, 0xF4(r31)
	  stw       r7, 0xB4(r31)
	  stw       r0, 0xD0(r31)
	  bl        -0x44220
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800848E8
 * Size:	0000C0
 */
void KeyConfig::read(RandomAccessStream&)
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
	  addi      r3, r30, 0x20
	  lwz       r12, 0x20(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x44
	  lwz       r12, 0x44(r30)
	  mr        r4, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x68
	  lwz       r12, 0x68(r30)
	  mr        r4, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x8C
	  lwz       r12, 0x8C(r30)
	  mr        r4, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0xD4
	  lwz       r12, 0xD4(r30)
	  mr        r4, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0xB0
	  lwz       r12, 0xB0(r30)
	  mr        r4, r31
	  lwz       r12, 0xC(r12)
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
 * Address:	800849A8
 * Size:	000040
 */
void KeyConfig::Key::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x4(r4)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x20(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
