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
 * Address:	8005EA80
 * Size:	00006C
 */
BaseParm::BaseParm(Parameters*, ayuID)
{
	/*
	.loc_0x0:
	  lis       r6, 0x802B
	  subi      r0, r6, 0x7964
	  stw       r0, 0x8(r3)
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  lwz       r6, 0x0(r4)
	  mr        r7, r6
	  b         .loc_0x24

	.loc_0x20:
	  lwz       r7, 0x4(r7)

	.loc_0x24:
	  cmplwi    r7, 0
	  bne+      .loc_0x20
	  li        r7, 0
	  b         .loc_0x3C

	.loc_0x34:
	  mr        r7, r6
	  lwz       r6, 0x4(r6)

	.loc_0x3C:
	  cmplwi    r6, 0
	  bne+      .loc_0x34
	  cmplwi    r7, 0
	  beq-      .loc_0x54
	  stw       r3, 0x4(r7)
	  b         .loc_0x58

	.loc_0x54:
	  stw       r3, 0x0(r4)

	.loc_0x58:
	  lwz       r4, 0x0(r5)
	  li        r0, 0
	  stw       r4, 0x0(r3)
	  stw       r0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005EAEC
 * Size:	0000A8
 */
void Parameters::write(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  lwz       r31, 0x0(r3)
	  b         .loc_0x70

	.loc_0x20:
	  mr        r3, r31
	  lwz       r12, 0x8(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x4(r30)
	  lwz       r0, 0x0(r31)
	  lwz       r12, 0x24(r12)
	  rlwinm    r0,r0,0,0,23
	  mtlr      r12
	  or        r4, r0, r3
	  addi      r3, r30, 0
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x8(r31)
	  mr        r4, r30
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0x4(r31)

	.loc_0x70:
	  cmplwi    r31, 0
	  bne+      .loc_0x20
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  li        r4, -0x1
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
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
 * Address:	8005EB94
 * Size:	000004
 */
void BaseParm::write(RandomAccessStream&) { }

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void Parameters::sizeInFile()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005EB98
 * Size:	0000D4
 */
void Parameters::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x128(r1)
	  stw       r31, 0x124(r1)
	  stw       r30, 0x120(r1)
	  stw       r29, 0x11C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x118(r1)
	  addi      r28, r3, 0

	.loc_0x24:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r3, -0x1
	  beq-      .loc_0xB4
	  lwz       r4, 0x0(r28)
	  rlwinm    r31,r3,0,24,31
	  rlwinm    r3,r3,0,0,23
	  li        r30, 0
	  b         .loc_0x84

	.loc_0x54:
	  lwz       r0, 0x0(r4)
	  cmpw      r3, r0
	  bne-      .loc_0x80
	  mr        r3, r4
	  lwz       r12, 0x8(r4)
	  addi      r4, r29, 0
	  li        r30, 0x1
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x8C

	.loc_0x80:
	  lwz       r4, 0x4(r4)

	.loc_0x84:
	  cmplwi    r4, 0
	  bne+      .loc_0x54

	.loc_0x8C:
	  rlwinm.   r0,r30,0,24,31
	  bne+      .loc_0x24
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  addi      r5, r31, 0
	  addi      r4, r1, 0x18
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x24

	.loc_0xB4:
	  lwz       r0, 0x12C(r1)
	  lwz       r31, 0x124(r1)
	  lwz       r30, 0x120(r1)
	  lwz       r29, 0x11C(r1)
	  lwz       r28, 0x118(r1)
	  addi      r1, r1, 0x128
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005EC6C
 * Size:	000004
 */
void BaseParm::read(RandomAccessStream&) { }

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void Parm<Colour>::read(RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void Parm<Colour>::write(RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void Parm<Vector3f>::read(RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void Parm<Vector3f>::write(RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005EC70
 * Size:	000040
 */
void Parm<f32>::read(RandomAccessStream&)
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
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0xC(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005ECB0
 * Size:	000038
 */
void Parm<f32>::write(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r3, 0
	  stw       r0, 0x4(r1)
	  addi      r3, r4, 0
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x4(r4)
	  lfs       f1, 0xC(r5)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005ECE8
 * Size:	000040
 */
void Parm<int>::read(RandomAccessStream&)
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
	  stw       r3, 0xC(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005ED28
 * Size:	000038
 */
void Parm<int>::write(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r3, 0
	  stw       r0, 0x4(r1)
	  addi      r3, r4, 0
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x4(r3)
	  lwz       r4, 0xC(r5)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005ED60
 * Size:	000058
 */
void Parm<String>::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x4(r4)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x1C(r1)
	  li        r0, 0
	  stw       r0, 0x18(r1)
	  lwz       r3, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stw       r3, 0xC(r31)
	  stw       r0, 0x10(r31)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005EDB8
 * Size:	000038
 */
void Parm<String>::write(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r3, 0
	  stw       r0, 0x4(r1)
	  addi      r3, r4, 0
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x4(r4)
	  addi      r4, r5, 0xC
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
