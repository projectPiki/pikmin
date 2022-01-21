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
 * Address:	800DED68
 * Size:	000130
 */
GeneratorCache::GeneratorCache()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r25, 0x14(r1)
	  addi      r25, r3, 0
	  addi      r26, r4, 0x738C
	  lis       r3, 0x8022
	  addi      r27, r3, 0x737C
	  lis       r3, 0x802C
	  subi      r29, r3, 0x53E4
	  li        r28, 0
	  addi      r3, r25, 0
	  mr        r4, r29
	  stw       r26, 0x0(r25)
	  stw       r27, 0x0(r25)
	  stw       r28, 0x10(r25)
	  stw       r28, 0xC(r25)
	  stw       r28, 0x8(r25)
	  bl        -0xB9EE0
	  lis       r3, 0x802C
	  subi      r30, r3, 0x5294
	  stw       r30, 0x0(r25)
	  subi      r31, r13, 0x3918
	  addi      r4, r29, 0
	  stw       r28, 0x10(r25)
	  addi      r3, r25, 0x38
	  stw       r28, 0xC(r25)
	  stw       r28, 0x8(r25)
	  stw       r31, 0x4(r25)
	  stw       r28, 0x14(r25)
	  stw       r28, 0x2C(r25)
	  stw       r28, 0x1C(r25)
	  stw       r28, 0x18(r25)
	  stw       r26, 0x38(r25)
	  stw       r27, 0x38(r25)
	  stw       r28, 0x48(r25)
	  stw       r28, 0x44(r25)
	  stw       r28, 0x40(r25)
	  bl        -0xB9F30
	  stw       r30, 0x38(r25)
	  li        r3, 0x6C00
	  stw       r28, 0x48(r25)
	  stw       r28, 0x44(r25)
	  stw       r28, 0x40(r25)
	  stw       r31, 0x3C(r25)
	  stw       r28, 0x4C(r25)
	  stw       r28, 0x64(r25)
	  stw       r28, 0x54(r25)
	  stw       r28, 0x50(r25)
	  bl        -0x97E2C
	  addi      r4, r3, 0
	  addi      r3, r25, 0
	  li        r5, 0x6C00
	  bl        .loc_0x130
	  stw       r28, 0x10(r25)
	  li        r26, 0
	  stw       r28, 0xC(r25)
	  stw       r28, 0x8(r25)
	  stw       r31, 0x4(r25)
	  stw       r28, 0x48(r25)
	  stw       r28, 0x44(r25)
	  stw       r28, 0x40(r25)
	  stw       r31, 0x3C(r25)

	.loc_0x100:
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  bl        0xF8
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x5
	  blt+      .loc_0x100
	  mr        r3, r25
	  lmw       r25, 0x14(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0x130:
	*/
}

/*
 * --INFO--
 * Address:	800DEE98
 * Size:	000018
 */
void GeneratorCache::init(unsigned char*, int)
{
	/*
	.loc_0x0:
	  stw       r4, 0x70(r3)
	  li        r0, 0
	  stw       r5, 0x74(r3)
	  stw       r0, 0x78(r3)
	  stw       r5, 0x7C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800DEEB0
 * Size:	0000B8
 */
void GeneratorCache::initGame()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  stw       r0, 0x78(r3)
	  lwz       r0, 0x74(r3)
	  stw       r0, 0x7C(r3)
	  lwz       r31, 0x10(r3)
	  b         .loc_0x50

	.loc_0x34:
	  lwz       r30, 0xC(r31)
	  mr        r3, r31
	  bl        -0x9E8DC
	  addi      r3, r29, 0x38
	  addi      r4, r31, 0
	  bl        -0x9E920
	  mr        r31, r30

	.loc_0x50:
	  cmplwi    r31, 0
	  bne+      .loc_0x34
	  lwz       r4, 0x48(r29)
	  li        r3, 0
	  li        r0, 0
	  b         .loc_0x94

	.loc_0x68:
	  stw       r3, 0x14(r4)
	  addi      r3, r3, 0x1
	  stw       r0, 0x18(r4)
	  stw       r0, 0x1C(r4)
	  stw       r0, 0x20(r4)
	  stw       r0, 0x24(r4)
	  stw       r0, 0x28(r4)
	  stw       r0, 0x2C(r4)
	  stw       r0, 0x30(r4)
	  stw       r0, 0x34(r4)
	  lwz       r4, 0xC(r4)

	.loc_0x94:
	  cmplwi    r4, 0
	  bne+      .loc_0x68
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
 * Address:	800DEF68
 * Size:	0000F4
 */
void GeneratorCache::addOne(unsigned long)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  addi      r5, r29, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  addi      r4, r28, 0
	  bl        0x650
	  cmplwi    r3, 0
	  bne-      .loc_0xD4
	  addi      r3, r28, 0
	  addi      r5, r29, 0
	  addi      r4, r28, 0x38
	  bl        0x638
	  cmplwi    r3, 0
	  bne-      .loc_0xD4
	  li        r3, 0x38
	  bl        -0x97FB8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xC8
	  lis       r4, 0x8022
	  addi      r0, r4, 0x738C
	  lis       r4, 0x8022
	  stw       r0, 0x0(r30)
	  addi      r0, r4, 0x737C
	  stw       r0, 0x0(r30)
	  li        r31, 0
	  lis       r4, 0x802C
	  stw       r31, 0x10(r30)
	  subi      r4, r4, 0x53E4
	  stw       r31, 0xC(r30)
	  stw       r31, 0x8(r30)
	  bl        -0xBA128
	  lis       r3, 0x802C
	  subi      r0, r3, 0x5294
	  stw       r0, 0x0(r30)
	  subi      r0, r13, 0x3918
	  stw       r29, 0x14(r30)
	  stw       r31, 0x10(r30)
	  stw       r31, 0xC(r30)
	  stw       r31, 0x8(r30)
	  stw       r0, 0x4(r30)
	  stw       r31, 0x2C(r30)
	  stw       r31, 0x1C(r30)
	  stw       r31, 0x18(r30)

	.loc_0xC8:
	  addi      r4, r30, 0
	  addi      r3, r28, 0x38
	  bl        -0x9EA60

	.loc_0xD4:
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
 * Address:	800DF05C
 * Size:	000134
 */
void GeneratorCache::saveCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x4(r29)
	  lwz       r4, 0x78(r28)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r4, 0x7C(r28)
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  li        r31, 0

	.loc_0x6C:
	  mr        r3, r29
	  lwz       r4, 0x70(r28)
	  lwz       r12, 0x4(r29)
	  lbzx      r4, r4, r31
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x6C00
	  blt+      .loc_0x6C
	  li        r31, 0

	.loc_0x98:
	  addi      r3, r28, 0
	  addi      r4, r28, 0
	  addi      r5, r31, 0
	  bl        0x4E4
	  mr.       r30, r3
	  beq-      .loc_0xCC
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  li        r4, 0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xFC

	.loc_0xCC:
	  addi      r3, r28, 0
	  addi      r5, r31, 0
	  addi      r4, r28, 0x38
	  bl        0x4B0
	  addi      r0, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x4(r29)
	  mr        r30, r0
	  li        r4, 0xFF
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl

	.loc_0xFC:
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  bl        0x26C
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x5
	  blt+      .loc_0x98
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
 * Address:	800DF190
 * Size:	00023C
 */
void GeneratorCache::loadCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r27, 0x4C(r1)
	  addi      r31, r4, 0
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x78(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x7C(r30)
	  lwz       r3, 0x10(r30)
	  b         .loc_0x6C

	.loc_0x50:
	  mr        r29, r3
	  lwz       r28, 0xC(r3)
	  bl        -0x9EBD8
	  addi      r3, r30, 0x38
	  addi      r4, r29, 0
	  bl        -0x9EC1C
	  mr        r3, r28

	.loc_0x6C:
	  cmplwi    r3, 0
	  bne+      .loc_0x50
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  li        r28, 0

	.loc_0x8C:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x70(r30)
	  stbx      r3, r4, r28
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x6C00
	  blt+      .loc_0x8C
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x10(r1)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x10(r1)
	  li        r28, 0
	  lis       r3, 0x802C
	  stw       r28, 0x20(r1)
	  subi      r4, r3, 0x53E4
	  addi      r3, r1, 0x10
	  stw       r28, 0x1C(r1)
	  stw       r28, 0x18(r1)
	  bl        -0xBA3A4
	  lis       r3, 0x802C
	  subi      r0, r3, 0x5294
	  stw       r0, 0x10(r1)
	  subi      r0, r13, 0x3918
	  stw       r28, 0x20(r1)
	  stw       r28, 0x1C(r1)
	  stw       r28, 0x18(r1)
	  stw       r0, 0x14(r1)
	  stw       r28, 0x24(r1)
	  stw       r28, 0x3C(r1)
	  stw       r28, 0x2C(r1)
	  stw       r28, 0x28(r1)

	.loc_0x11C:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  addi      r4, r30, 0x38
	  bl        0x314
	  mr.       r27, r3
	  bne-      .loc_0x160
	  lwz       r3, 0x48(r30)
	  b         .loc_0x158

	.loc_0x154:
	  lwz       r3, 0xC(r3)

	.loc_0x158:
	  cmplwi    r3, 0
	  bne+      .loc_0x154

	.loc_0x160:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r27, 0
	  addi      r4, r31, 0
	  bl        0x1CC
	  rlwinm.   r0,r29,0,24,31
	  bne-      .loc_0x1A0
	  mr        r3, r27
	  bl        -0x9ED0C
	  addi      r3, r1, 0x10
	  addi      r4, r27, 0
	  bl        -0x9ED50
	  b         .loc_0x1B4

	.loc_0x1A0:
	  mr        r3, r27
	  bl        -0x9ED24
	  addi      r3, r30, 0x38
	  addi      r4, r27, 0
	  bl        -0x9ED68

	.loc_0x1B4:
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x5
	  blt+      .loc_0x11C
	  lwz       r0, 0x20(r1)
	  b         .loc_0x218

	.loc_0x1C8:
	  lwz       r4, 0x20(r1)
	  li        r3, -0x1
	  li        r27, 0
	  b         .loc_0x1F0

	.loc_0x1D8:
	  lwz       r0, 0x18(r4)
	  cmplw     r3, r0
	  ble-      .loc_0x1EC
	  mr        r3, r0
	  addi      r27, r4, 0

	.loc_0x1EC:
	  lwz       r4, 0xC(r4)

	.loc_0x1F0:
	  cmplwi    r4, 0
	  bne+      .loc_0x1D8
	  cmplwi    r27, 0
	  beq-      .loc_0x214
	  mr        r3, r27
	  bl        -0x9ED84
	  addi      r3, r30, 0
	  addi      r4, r27, 0
	  bl        -0x9EDC8

	.loc_0x214:
	  lwz       r0, 0x20(r1)

	.loc_0x218:
	  cmplwi    r0, 0
	  bne+      .loc_0x1C8
	  mr        r3, r30
	  bl        0xE08
	  lmw       r27, 0x4C(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800DF3CC
 * Size:	00010C
 */
void GeneratorCache::Cache::saveCard(RandomAccessStream&)
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
	  lwz       r12, 0x4(r31)
	  lwz       r4, 0x14(r30)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x18(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x1C(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x20(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x24(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x28(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x2C(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x30(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x34(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x24(r12)
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
 * Address:	800DF4D8
 * Size:	00010C
 */
void GeneratorCache::Cache::loadCard(RandomAccessStream&)
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
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x14(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x18(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x1C(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x20(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x24(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x28(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x2C(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x30(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x34(r30)
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
 * Address:	800DF5E4
 * Size:	000028
 */
void GeneratorCache::findCache(GeneratorCache::Cache&, unsigned long)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x10(r4)
	  b         .loc_0x18

	.loc_0x8:
	  lwz       r0, 0x14(r3)
	  cmplw     r0, r5
	  beqlr-
	  lwz       r3, 0xC(r3)

	.loc_0x18:
	  cmplwi    r3, 0
	  bne+      .loc_0x8
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800DF60C
 * Size:	000160
 */
void GeneratorCache::preload(unsigned long)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x8
	  stw       r0, 0x4(r1)
	  subfic    r0, r5, 0xA
	  cmpwi     r5, 0xA
	  mtctr     r0
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x44(r1)
	  stw       r28, 0x40(r1)
	  bge-      .loc_0x38

	.loc_0x34:
	  bdnz-     .loc_0x34

	.loc_0x38:
	  lwz       r31, 0x10(r30)
	  b         .loc_0x54

	.loc_0x40:
	  lwz       r0, 0x14(r31)
	  cmplw     r0, r4
	  bne-      .loc_0x50
	  b         .loc_0x60

	.loc_0x50:
	  lwz       r31, 0xC(r31)

	.loc_0x54:
	  cmplwi    r31, 0
	  bne+      .loc_0x40
	  li        r31, 0

	.loc_0x60:
	  cmplwi    r31, 0
	  beq-      .loc_0x128
	  lis       r3, 0x8022
	  lwz       r6, 0x70(r30)
	  addi      r4, r3, 0x7398
	  lwz       r5, 0x18(r31)
	  lwz       r7, 0x1C(r31)
	  lis       r3, 0x8022
	  addi      r0, r3, 0x74C8
	  stw       r4, 0x2C(r1)
	  lis       r3, 0x802A
	  addi      r3, r3, 0x755C
	  stw       r0, 0x2C(r1)
	  add       r4, r6, r5
	  li        r0, 0
	  stw       r3, 0x2C(r1)
	  li        r28, 0
	  stw       r4, 0x30(r1)
	  stw       r0, 0x34(r1)
	  stw       r7, 0x38(r1)
	  b         .loc_0x110

	.loc_0xB4:
	  li        r3, 0xB8
	  bl        -0x986C0
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xCC
	  bl        -0x3BF4

	.loc_0xCC:
	  li        r0, 0x1
	  stb       r0, 0x3070(r13)
	  mr        r3, r29
	  addi      r4, r1, 0x28
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stb       r0, 0x3070(r13)
	  mr        r4, r29
	  stw       r28, 0xB4(r29)
	  stb       r0, 0xB0(r29)
	  lwz       r3, 0x3094(r13)
	  lwz       r3, 0x0(r3)
	  bl        -0x9F13C
	  addi      r28, r28, 0x1

	.loc_0x110:
	  lwz       r0, 0x2C(r31)
	  cmplw     r28, r0
	  blt+      .loc_0xB4
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x570

	.loc_0x128:
	  li        r3, 0x8
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x140

	.loc_0x13C:
	  bdnz-     .loc_0x13C

	.loc_0x140:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  lwz       r28, 0x40(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800DF76C
 * Size:	000128
 */
void GeneratorCache::hasUfoParts(unsigned long, unsigned long)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r5
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  lwz       r30, 0x10(r3)
	  b         .loc_0x38

	.loc_0x24:
	  lwz       r0, 0x14(r30)
	  cmplw     r0, r4
	  bne-      .loc_0x34
	  b         .loc_0x44

	.loc_0x34:
	  lwz       r30, 0xC(r30)

	.loc_0x38:
	  cmplwi    r30, 0
	  bne+      .loc_0x24
	  li        r30, 0

	.loc_0x44:
	  cmplwi    r30, 0
	  beq-      .loc_0x108
	  lis       r4, 0x8022
	  lwz       r6, 0x70(r3)
	  addi      r0, r4, 0x7398
	  lwz       r8, 0x24(r30)
	  lwz       r7, 0x20(r30)
	  lis       r4, 0x8022
	  lwz       r5, 0x18(r30)
	  lis       r3, 0x802A
	  lwz       r9, 0x28(r30)
	  add       r5, r5, r7
	  stw       r0, 0x20(r1)
	  addi      r0, r4, 0x74C8
	  add       r5, r5, r8
	  stw       r0, 0x20(r1)
	  addi      r0, r3, 0x755C
	  add       r5, r6, r5
	  stw       r0, 0x20(r1)
	  li        r0, 0
	  li        r29, 0
	  stw       r5, 0x24(r1)
	  stw       r0, 0x28(r1)
	  stw       r9, 0x2C(r1)
	  b         .loc_0xFC

	.loc_0xA8:
	  addi      r3, r1, 0x1C
	  bl        -0xBA768
	  cmplw     r3, r31
	  bne-      .loc_0xC0
	  li        r3, 0x1
	  b         .loc_0x10C

	.loc_0xC0:
	  addi      r3, r1, 0x1C
	  bl        -0xBA6D8
	  addi      r3, r1, 0x1C
	  bl        -0xBA6E0
	  addi      r3, r1, 0x1C
	  bl        -0xBA6E8
	  addi      r3, r1, 0x1C
	  bl        -0xBA760
	  addi      r3, r1, 0x1C
	  bl        -0xBA6F8
	  addi      r3, r1, 0x1C
	  bl        -0xBA700
	  addi      r3, r1, 0x1C
	  bl        -0xBA708
	  addi      r29, r29, 0x1

	.loc_0xFC:
	  lwz       r0, 0x34(r30)
	  cmplw     r29, r0
	  blt+      .loc_0xA8

	.loc_0x108:
	  li        r3, 0

	.loc_0x10C:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800DF894
 * Size:	00019C
 */
void GeneratorCache::load(unsigned long)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  mr        r30, r3
	  stw       r29, 0x34(r1)
	  lwz       r31, 0x10(r3)
	  b         .loc_0x38

	.loc_0x24:
	  lwz       r0, 0x14(r31)
	  cmplw     r0, r4
	  bne-      .loc_0x34
	  b         .loc_0x44

	.loc_0x34:
	  lwz       r31, 0xC(r31)

	.loc_0x38:
	  cmplwi    r31, 0
	  bne+      .loc_0x24
	  li        r31, 0

	.loc_0x44:
	  cmplwi    r31, 0
	  beq-      .loc_0x180
	  lis       r3, 0x8022
	  lwz       r7, 0x20(r31)
	  addi      r0, r3, 0x7398
	  lwz       r5, 0x18(r31)
	  lwz       r6, 0x70(r30)
	  lis       r4, 0x8022
	  lwz       r8, 0x24(r31)
	  lis       r3, 0x802A
	  li        r29, 0
	  stw       r0, 0x1C(r1)
	  addi      r0, r4, 0x74C8
	  add       r4, r5, r7
	  stw       r0, 0x1C(r1)
	  addi      r0, r3, 0x755C
	  add       r4, r6, r4
	  stw       r0, 0x1C(r1)
	  li        r0, 0
	  stw       r4, 0x20(r1)
	  stw       r0, 0x24(r1)
	  stw       r8, 0x28(r1)
	  b         .loc_0xC4

	.loc_0xA0:
	  addi      r3, r1, 0x18
	  bl        -0xBA888
	  mr        r0, r3
	  lwz       r3, 0x3094(r13)
	  mr        r4, r0
	  bl        -0xD58
	  addi      r4, r1, 0x18
	  bl        -0x3B74
	  addi      r29, r29, 0x1

	.loc_0xC4:
	  lwz       r0, 0x30(r31)
	  cmplw     r29, r0
	  blt+      .loc_0xA0
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x44C
	  mr        r3, r30
	  bl        0x848
	  lwz       r29, 0x1C(r31)
	  mr        r4, r31
	  b         .loc_0x138

	.loc_0xF0:
	  lwz       r3, 0x70(r30)
	  li        r6, 0
	  lwz       r0, 0x18(r4)
	  add       r5, r3, r0
	  sub       r0, r5, r29
	  mr        r3, r0
	  b         .loc_0x120

	.loc_0x10C:
	  lbz       r0, 0x0(r5)
	  addi      r6, r6, 0x1
	  addi      r5, r5, 0x1
	  stb       r0, 0x0(r3)
	  addi      r3, r3, 0x1

	.loc_0x120:
	  lwz       r0, 0x1C(r4)
	  cmplw     r6, r0
	  blt+      .loc_0x10C
	  lwz       r0, 0x18(r4)
	  sub       r0, r0, r29
	  stw       r0, 0x18(r4)

	.loc_0x138:
	  lwz       r4, 0xC(r4)
	  cmplwi    r4, 0
	  bne+      .loc_0xF0
	  mr        r3, r31
	  bl        -0x9F3CC
	  addi      r3, r30, 0x38
	  addi      r4, r31, 0
	  bl        -0x9F410
	  lwz       r0, 0x78(r30)
	  addi      r3, r30, 0
	  sub       r0, r0, r29
	  stw       r0, 0x78(r30)
	  lwz       r0, 0x7C(r30)
	  add       r0, r0, r29
	  stw       r0, 0x7C(r30)
	  bl        0x7B4
	  mr        r3, r30
	  bl        0x750

	.loc_0x180:
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
 * Address:	800DFA30
 * Size:	000090
 */
void GeneratorCache::beginSave(unsigned long)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x48(r3)
	  b         .loc_0x1C

	.loc_0x8:
	  lwz       r0, 0x14(r5)
	  cmplw     r0, r4
	  bne-      .loc_0x18
	  b         .loc_0x28

	.loc_0x18:
	  lwz       r5, 0xC(r5)

	.loc_0x1C:
	  cmplwi    r5, 0
	  bne+      .loc_0x8
	  li        r5, 0

	.loc_0x28:
	  cmplwi    r5, 0
	  addi      r6, r5, 0
	  bne-      .loc_0x60
	  lwz       r5, 0x10(r3)
	  b         .loc_0x50

	.loc_0x3C:
	  lwz       r0, 0x14(r5)
	  cmplw     r0, r4
	  bne-      .loc_0x4C
	  b         .loc_0x5C

	.loc_0x4C:
	  lwz       r5, 0xC(r5)

	.loc_0x50:
	  cmplwi    r5, 0
	  bne+      .loc_0x3C
	  li        r5, 0

	.loc_0x5C:
	  mr        r6, r5

	.loc_0x60:
	  lwz       r5, 0x78(r3)
	  li        r0, 0
	  stw       r5, 0x18(r6)
	  stw       r0, 0x1C(r6)
	  stw       r0, 0x20(r6)
	  stw       r0, 0x24(r6)
	  stw       r0, 0x28(r6)
	  stw       r0, 0x2C(r6)
	  stw       r0, 0x30(r6)
	  stw       r0, 0x34(r6)
	  stw       r4, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800DFAC0
 * Size:	000080
 */
void GeneratorCache::endSave()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r4, 0x80(r3)
	  lwz       r3, 0x48(r3)
	  b         .loc_0x38

	.loc_0x24:
	  lwz       r0, 0x14(r3)
	  cmplw     r0, r4
	  bne-      .loc_0x34
	  b         .loc_0x44

	.loc_0x34:
	  lwz       r3, 0xC(r3)

	.loc_0x38:
	  cmplwi    r3, 0
	  bne+      .loc_0x24
	  li        r3, 0

	.loc_0x44:
	  cmplwi    r3, 0
	  addi      r31, r3, 0
	  mr        r3, r31
	  bl        -0x9F500
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x9F544
	  mr        r3, r30
	  bl        0x698
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
 * Address:	800DFB40
 * Size:	000160
 */
void GeneratorCache::saveGenerator(Generator*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x3C(r1)
	  lwz       r4, 0x94(r4)
	  cmpwi     r4, -0x1
	  beq-      .loc_0x40
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x2FC(r3)
	  cmpw      r4, r0
	  ble-      .loc_0x144

	.loc_0x40:
	  lwz       r3, 0x80(r30)
	  lwz       r31, 0x48(r30)
	  b         .loc_0x60

	.loc_0x4C:
	  lwz       r0, 0x14(r31)
	  cmplw     r0, r3
	  bne-      .loc_0x5C
	  b         .loc_0x6C

	.loc_0x5C:
	  lwz       r31, 0xC(r31)

	.loc_0x60:
	  cmplwi    r31, 0
	  bne+      .loc_0x4C
	  li        r31, 0

	.loc_0x6C:
	  cmplwi    r31, 0
	  lis       r3, 0x8022
	  lwz       r7, 0x70(r30)
	  addi      r0, r3, 0x7398
	  lwz       r6, 0x78(r30)
	  lwz       r8, 0x7C(r30)
	  lis       r3, 0x8022
	  addi      r4, r3, 0x74C8
	  stw       r0, 0x18(r1)
	  lis       r3, 0x802A
	  addi      r0, r3, 0x755C
	  stw       r4, 0x18(r1)
	  add       r3, r7, r6
	  li        r29, 0
	  stw       r0, 0x18(r1)
	  li        r0, 0x1
	  lis       r6, 0x4330
	  stw       r3, 0x1C(r1)
	  mr        r3, r5
	  addi      r4, r1, 0x14
	  stw       r29, 0x20(r1)
	  stw       r8, 0x24(r1)
	  lwz       r7, 0x7C(r30)
	  stb       r0, 0x3070(r13)
	  xoris     r7, r7, 0x8000
	  stw       r7, 0x34(r1)
	  lwz       r0, 0x2C(r31)
	  stw       r6, 0x30(r1)
	  stw       r0, 0xB4(r5)
	  bl        -0x2FCC
	  stb       r29, 0x3070(r13)
	  lwz       r29, 0x20(r1)
	  lwz       r0, 0x78(r30)
	  add       r0, r0, r29
	  stw       r0, 0x78(r30)
	  lwz       r0, 0x7C(r30)
	  sub       r0, r0, r29
	  stw       r0, 0x7C(r30)
	  lwz       r0, 0x7C(r30)
	  cmpwi     r0, 0
	  bgt-      .loc_0x11C
	  mr        r3, r30
	  bl        0x50C
	  b         .loc_0x120

	.loc_0x11C:
	  cmpwi     r0, 0x400

	.loc_0x120:
	  lwz       r3, 0x2C(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2C(r31)
	  lwz       r0, 0x1C(r31)
	  add       r0, r0, r29
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0x20(r31)
	  add       r0, r0, r29
	  stw       r0, 0x20(r31)

	.loc_0x144:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800DFCA0
 * Size:	000118
 */
void GeneratorCache::prepareUfoParts(GeneratorCache::Cache*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  li        r29, 0
	  stw       r28, 0x38(r1)
	  lwz       r6, 0x70(r3)
	  lis       r3, 0x8022
	  addi      r0, r3, 0x7398
	  lwz       r8, 0x24(r4)
	  lwz       r7, 0x20(r4)
	  lwz       r5, 0x18(r4)
	  lis       r4, 0x8022
	  lwz       r9, 0x28(r31)
	  lis       r3, 0x802A
	  add       r5, r5, r7
	  stw       r0, 0x28(r1)
	  addi      r0, r4, 0x74C8
	  add       r4, r5, r8
	  stw       r0, 0x28(r1)
	  addi      r0, r3, 0x755C
	  add       r4, r6, r4
	  stw       r0, 0x28(r1)
	  li        r0, 0
	  stw       r4, 0x2C(r1)
	  stw       r0, 0x30(r1)
	  stw       r9, 0x34(r1)
	  b         .loc_0xEC

	.loc_0x7C:
	  addi      r3, r1, 0x24
	  bl        -0xBAC70
	  addi      r28, r3, 0
	  addi      r4, r28, 0
	  addi      r3, r1, 0x18
	  bl        -0x9BE9C
	  lwz       r3, 0x301C(r13)
	  mr        r4, r28
	  bl        -0x47018
	  mr.       r30, r3
	  addi      r3, r1, 0x24
	  bl        -0xBABF0
	  addi      r3, r1, 0x24
	  bl        -0xBABF8
	  addi      r3, r1, 0x24
	  bl        -0xBAC00
	  addi      r3, r1, 0x24
	  bl        -0xBAC78
	  addi      r3, r1, 0x24
	  bl        -0xBAC10
	  addi      r3, r1, 0x24
	  bl        -0xBAC18
	  addi      r3, r1, 0x24
	  bl        -0xBAC20
	  lwz       r3, 0x301C(r13)
	  lwz       r4, 0x44(r30)
	  bl        -0x47280
	  addi      r29, r29, 0x1

	.loc_0xEC:
	  lwz       r0, 0x34(r31)
	  cmplw     r29, r0
	  blt+      .loc_0x7C
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800DFDB8
 * Size:	00011C
 */
void GeneratorCache::loadUfoParts(GeneratorCache::Cache*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r4
	  stw       r30, 0x30(r1)
	  li        r30, 0
	  stw       r29, 0x2C(r1)
	  lwz       r6, 0x70(r3)
	  lis       r3, 0x8022
	  addi      r0, r3, 0x7398
	  lwz       r8, 0x24(r4)
	  lwz       r7, 0x20(r4)
	  lwz       r5, 0x18(r4)
	  lis       r4, 0x8022
	  lwz       r9, 0x28(r31)
	  lis       r3, 0x802A
	  add       r5, r5, r7
	  stw       r0, 0x18(r1)
	  addi      r0, r4, 0x74C8
	  add       r4, r5, r8
	  stw       r0, 0x18(r1)
	  addi      r0, r3, 0x755C
	  add       r4, r6, r4
	  stw       r0, 0x18(r1)
	  li        r0, 0
	  stw       r4, 0x1C(r1)
	  stw       r0, 0x20(r1)
	  stw       r9, 0x24(r1)
	  b         .loc_0xF4

	.loc_0x78:
	  addi      r3, r1, 0x14
	  bl        -0xBAD84
	  mr        r0, r3
	  lwz       r3, 0x301C(r13)
	  mr        r4, r0
	  li        r5, 0
	  bl        -0x47898
	  addi      r29, r3, 0
	  addi      r4, r1, 0x14
	  li        r5, 0x1
	  bl        -0x55DC0
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r29, 0x94
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x470(r29)
	  addi      r4, r29, 0
	  li        r5, 0x5
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r30, 0x1

	.loc_0xF4:
	  lwz       r0, 0x34(r31)
	  cmplw     r30, r0
	  blt+      .loc_0x78
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800DFED4
 * Size:	000124
 */
void GeneratorCache::saveUfoParts(Pellet*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  mr        r30, r4
	  stw       r29, 0x34(r1)
	  mr        r29, r3
	  lwz       r3, 0x80(r3)
	  lwz       r31, 0x48(r29)
	  b         .loc_0x40

	.loc_0x2C:
	  lwz       r0, 0x14(r31)
	  cmplw     r0, r3
	  bne-      .loc_0x3C
	  b         .loc_0x4C

	.loc_0x3C:
	  lwz       r31, 0xC(r31)

	.loc_0x40:
	  cmplwi    r31, 0
	  bne+      .loc_0x2C
	  li        r31, 0

	.loc_0x4C:
	  cmplwi    r31, 0
	  lis       r3, 0x8022
	  lwz       r6, 0x70(r29)
	  addi      r4, r3, 0x7398
	  lwz       r5, 0x78(r29)
	  lwz       r7, 0x7C(r29)
	  lis       r3, 0x8022
	  addi      r0, r3, 0x74C8
	  stw       r4, 0x18(r1)
	  lis       r3, 0x802A
	  addi      r3, r3, 0x755C
	  stw       r0, 0x18(r1)
	  add       r4, r6, r5
	  li        r0, 0
	  stw       r3, 0x18(r1)
	  addi      r3, r1, 0x14
	  stw       r4, 0x1C(r1)
	  stw       r0, 0x20(r1)
	  stw       r7, 0x24(r1)
	  lwz       r4, 0x55C(r30)
	  lwz       r4, 0x2C(r4)
	  bl        -0xBAC8C
	  addi      r3, r30, 0
	  addi      r4, r1, 0x14
	  li        r5, 0x1
	  bl        -0x55E14
	  lwz       r4, 0x20(r1)
	  lwz       r0, 0x78(r29)
	  add       r0, r0, r4
	  stw       r0, 0x78(r29)
	  lwz       r0, 0x7C(r29)
	  sub       r0, r0, r4
	  stw       r0, 0x7C(r29)
	  lwz       r0, 0x7C(r29)
	  cmpwi     r0, 0
	  bgt-      .loc_0xE0
	  b         .loc_0xE4

	.loc_0xE0:
	  cmpwi     r0, 0x400

	.loc_0xE4:
	  lwz       r3, 0x34(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x34(r31)
	  lwz       r0, 0x1C(r31)
	  add       r0, r0, r4
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0x28(r31)
	  add       r0, r0, r4
	  stw       r0, 0x28(r31)
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
 * Address:	800DFFF8
 * Size:	000168
 */
void GeneratorCache::saveGeneratorCreature(Generator*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x3C(r1)
	  addi      r29, r3, 0
	  addi      r3, r30, 0
	  bl        -0x4278
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x14C
	  lwz       r3, 0x80(r29)
	  lwz       r31, 0x48(r29)
	  b         .loc_0x50

	.loc_0x3C:
	  lwz       r0, 0x14(r31)
	  cmplw     r0, r3
	  bne-      .loc_0x4C
	  b         .loc_0x5C

	.loc_0x4C:
	  lwz       r31, 0xC(r31)

	.loc_0x50:
	  cmplwi    r31, 0
	  bne+      .loc_0x3C
	  li        r31, 0

	.loc_0x5C:
	  cmplwi    r31, 0
	  lis       r3, 0x8022
	  lwz       r6, 0x70(r29)
	  addi      r4, r3, 0x7398
	  lwz       r5, 0x78(r29)
	  lwz       r7, 0x7C(r29)
	  lis       r3, 0x8022
	  addi      r0, r3, 0x74C8
	  stw       r4, 0x18(r1)
	  lis       r3, 0x802A
	  addi      r3, r3, 0x755C
	  stw       r0, 0x18(r1)
	  add       r4, r6, r5
	  li        r0, 0
	  stw       r3, 0x18(r1)
	  lis       r3, 0x4330
	  stw       r4, 0x1C(r1)
	  stw       r0, 0x20(r1)
	  stw       r7, 0x24(r1)
	  lwz       r4, 0x7C(r29)
	  lwz       r0, 0x84(r30)
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x34(r1)
	  cmplwi    r0, 0
	  stw       r3, 0x30(r1)
	  beq-      .loc_0x14C
	  li        r0, 0x1
	  stb       r0, 0x3070(r13)
	  lwz       r0, 0x84(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xF0
	  addi      r3, r1, 0x14
	  lwz       r4, 0xB4(r30)
	  bl        -0xBADF0
	  addi      r3, r30, 0
	  addi      r4, r1, 0x14
	  bl        -0x4204

	.loc_0xF0:
	  li        r0, 0
	  stb       r0, 0x3070(r13)
	  lwz       r4, 0x20(r1)
	  lwz       r0, 0x78(r29)
	  add       r0, r0, r4
	  stw       r0, 0x78(r29)
	  lwz       r0, 0x7C(r29)
	  sub       r0, r0, r4
	  stw       r0, 0x7C(r29)
	  lwz       r0, 0x7C(r29)
	  cmpwi     r0, 0
	  bgt-      .loc_0x124
	  b         .loc_0x128

	.loc_0x124:
	  cmpwi     r0, 0x400

	.loc_0x128:
	  lwz       r3, 0x30(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x30(r31)
	  lwz       r0, 0x1C(r31)
	  add       r0, r0, r4
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0x24(r31)
	  add       r0, r0, r4
	  stw       r0, 0x24(r31)

	.loc_0x14C:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void GeneratorCache::Cache::dump()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E0160
 * Size:	00005C
 */
void GeneratorCache::dump()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  lis       r0, 0x4330
	  lwz       r5, 0x10(r3)
	  lfd       f1, -0x6758(r2)
	  lfs       f0, -0x6760(r2)
	  b         .loc_0x28

	.loc_0x18:
	  lwz       r4, 0x1C(r5)
	  lwz       r5, 0xC(r5)
	  stw       r4, 0x14(r1)
	  stw       r0, 0x10(r1)

	.loc_0x28:
	  cmplwi    r5, 0
	  bne+      .loc_0x18
	  lwz       r4, 0x48(r3)
	  lis       r0, 0x4330
	  b         .loc_0x4C

	.loc_0x3C:
	  lwz       r3, 0x1C(r4)
	  lwz       r4, 0xC(r4)
	  stw       r3, 0x14(r1)
	  stw       r0, 0x10(r1)

	.loc_0x4C:
	  cmplwi    r4, 0
	  bne+      .loc_0x3C
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E01BC
 * Size:	00006C
 */
void GeneratorCache::assertValid()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r31, 0x10(r3)
	  b         .loc_0x48

	.loc_0x28:
	  lwz       r0, 0x18(r31)
	  cmplw     r0, r30
	  beq-      .loc_0x3C
	  mr        r3, r29
	  bl        -0x94

	.loc_0x3C:
	  lwz       r0, 0x1C(r31)
	  lwz       r31, 0xC(r31)
	  add       r30, r30, r0

	.loc_0x48:
	  cmplwi    r31, 0
	  bne+      .loc_0x28
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
