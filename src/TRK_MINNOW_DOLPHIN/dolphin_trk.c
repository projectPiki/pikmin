#include "types.h"

/*
 * --INFO--
 * Address:	8021FE60
 * Size:	000094
 */
void InitMetroTRK(void)
{
	/*
	.loc_0x0:
	  subi      r1, r1, 0x4
	  stw       r3, 0x0(r1)
	  lis       r3, 0x803D
	  ori       r3, r3, 0x5E40
	  stmw      r0, 0x0(r3)
	  lwz       r4, 0x0(r1)
	  addi      r1, r1, 0x4
	  stw       r1, 0x4(r3)
	  stw       r4, 0xC(r3)
	  mflr      r4
	  stw       r4, 0x84(r3)
	  stw       r4, 0x80(r3)
	  mfcr      r4
	  stw       r4, 0x88(r3)
	  mfmsr     r4
	  ori       r3, r4, 0x8000
	  xori      r3, r3, 0x8000
	  mtmsr     r3
	  mtsrr1    r4
	  bl        0x1F4
	  lis       r3, 0x803D
	  ori       r3, r3, 0x5E40
	  lmw       r0, 0x0(r3)
	  li        r0, 0
	  mtspr     1010, r0
	  mtdabr    r0
	  lis       r1, 0x803F
	  ori       r1, r1, 0xE840
	  mr        r3, r5
	  bl        0x64C
	  cmpwi     r3, 0x1
	  bne-      .loc_0x90
	  lwz       r4, 0x84(r3)
	  mtlr      r4
	  lmw       r0, 0x0(r3)
	  blr

	.loc_0x90:
	  b         0x528
	*/
}

/*
 * --INFO--
 * Address:	8021FEF4
 * Size:	000020
 */
void EnableMetroTRKInterrupts(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x74C
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021FF14
 * Size:	000048
 */
void TRKTargetTranslate(void)
{
	/*
	.loc_0x0:
	  lis       r4, 0x803D
	  addi      r4, r4, 0x6270
	  lwz       r4, 0x0(r4)
	  cmplw     r3, r4
	  blt-      .loc_0x3C
	  addi      r0, r4, 0x4000
	  cmplw     r3, r0
	  bge-      .loc_0x3C
	  lis       r4, 0x803D
	  addi      r4, r4, 0x5E40
	  lwz       r0, 0x238(r4)
	  rlwinm    r0,r0,0,30,31
	  cmplwi    r0, 0
	  beq-      .loc_0x3C
	  b         .loc_0x44

	.loc_0x3C:
	  rlwinm    r0,r3,0,2,31
	  oris      r3, r0, 0x8000

	.loc_0x44:
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021FF5C
 * Size:	000060
 */
void TRK_copy_vector(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  stw       r30, 0x8(r1)
	  mr        r30, r3
	  mr        r3, r30
	  bl        -0x64
	  lis       r4, 0x8000
	  addi      r0, r4, 0x34B8
	  mr        r31, r3
	  add       r4, r0, r30
	  mr        r3, r31
	  li        r5, 0x100
	  bl        -0x21CB30
	  mr        r3, r31
	  li        r4, 0x100
	  bl        -0x1818
	  lwz       r31, 0xC(r1)
	  lwz       r30, 0x8(r1)
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021FFBC
 * Size:	000094
 */
void __TRK_copy_vectors(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  stw       r29, 0xC(r1)
	  stw       r28, 0x8(r1)
	  li        r3, 0x44
	  bl        -0xC8
	  li        r29, 0
	  lwz       r28, 0x0(r3)
	  lis       r3, 0x802F
	  rlwinm    r4,r29,2,0,29
	  subi      r0, r3, 0x6A50
	  add       r30, r0, r4
	  b         .loc_0x40

	.loc_0x40:
	  li        r31, 0x1
	  b         .loc_0x48

	.loc_0x48:
	  b         .loc_0x4C

	.loc_0x4C:
	  slw       r0, r31, r29
	  and       r0, r28, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x64
	  lwz       r3, 0x0(r30)
	  bl        -0xC0

	.loc_0x64:
	  addi      r30, r30, 0x4
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0xE
	  ble+      .loc_0x4C
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  lwz       r29, 0xC(r1)
	  lwz       r28, 0x8(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80220050
 * Size:	000050
 */
void TRKInitializeTarget(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  lis       r3, 0x803D
	  addi      r31, r3, 0x5D98
	  li        r0, 0x1
	  stw       r0, 0x98(r31)
	  bl        -0x17EC
	  stw       r3, 0x8C(r31)
	  lis       r3, 0x803D
	  addi      r3, r3, 0x6270
	  lis       r0, 0xE000
	  stw       r0, 0x0(r3)
	  li        r3, 0
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}
