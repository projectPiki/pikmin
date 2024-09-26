#include "types.h"

typedef struct seqp_ seqp_;

/*
 * --INFO--
 * Address:	80014CA0
 * Size:	000090
 */
void Osc_Update_Param(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  stb       r4, 0xC(r1)
	  lbz       r0, 0xC(r1)
	  stfs      f1, 0x10(r1)
	  cmpwi     r0, 0x9
	  beq-      .loc_0x68
	  bge-      .loc_0x34
	  cmpwi     r0, 0x7
	  beq-      .loc_0x50
	  bge-      .loc_0x5C
	  cmpwi     r0, 0x6
	  bge-      .loc_0x44
	  b         .loc_0x88

	.loc_0x34:
	  cmpwi     r0, 0xB
	  beq-      .loc_0x80
	  bge-      .loc_0x88
	  b         .loc_0x74

	.loc_0x44:
	  lfs       f0, 0x10(r1)
	  stfs      f0, 0x350(r3)
	  b         .loc_0x88

	.loc_0x50:
	  lfs       f0, 0x10(r1)
	  stfs      f0, 0x344(r3)
	  b         .loc_0x88

	.loc_0x5C:
	  lfs       f0, 0x10(r1)
	  stfs      f0, 0x354(r3)
	  b         .loc_0x88

	.loc_0x68:
	  lfs       f0, 0x10(r1)
	  stfs      f0, 0x368(r3)
	  b         .loc_0x88

	.loc_0x74:
	  lfs       f0, 0x10(r1)
	  stfs      f0, 0x35C(r3)
	  b         .loc_0x88

	.loc_0x80:
	  lfs       f0, 0x10(r1)
	  stfs      f0, 0x36C(r3)

	.loc_0x88:
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014D40
 * Size:	00003C
 */
void Osc_Setup_Vibrato(seqp_*, u8)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r4,0,24,31
	  lis       r4, 0x8022
	  mulli     r5, r0, 0x18
	  addi      r4, r4, 0x587C
	  li        r0, 0x3
	  subi      r4, r4, 0x8
	  add       r3, r3, r5
	  addi      r5, r3, 0x338
	  mtctr     r0

	.loc_0x24:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r5)
	  stw       r0, 0x4(r5)
	  bdnz+     .loc_0x24
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014D80
 * Size:	00003C
 */
void Osc_Setup_Tremolo(seqp_*, u8)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r4,0,24,31
	  lis       r4, 0x8022
	  mulli     r5, r0, 0x18
	  addi      r4, r4, 0x5894
	  li        r0, 0x3
	  subi      r4, r4, 0x8
	  add       r3, r3, r5
	  addi      r5, r3, 0x338
	  mtctr     r0

	.loc_0x24:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r5)
	  stw       r0, 0x4(r5)
	  bdnz+     .loc_0x24
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014DC0
 * Size:	000064
 */
void Osc_Setup_Simple(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,0,24,31
	  cmpwi     r0, 0x1
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x40
	  bge-      .loc_0x28
	  cmpwi     r0, 0
	  bge-      .loc_0x34
	  b         .loc_0x54

	.loc_0x28:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x54
	  b         .loc_0x4C

	.loc_0x34:
	  li        r4, 0x1
	  bl        -0xB8
	  b         .loc_0x54

	.loc_0x40:
	  li        r4, 0
	  bl        -0x84
	  b         .loc_0x54

	.loc_0x4C:
	  li        r4, 0x1
	  bl        -0x90

	.loc_0x54:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014E40
 * Size:	000010
 */
void Osc_Clear_Overwrite(void)
{
	/*
	.loc_0x0:
	  li        r0, 0xF
	  stb       r0, 0x370(r3)
	  stb       r0, 0x371(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014E60
 * Size:	00004C
 */
void Osc_Init_Env(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r4, r4, 0x58AC
	  li        r0, 0x3
	  addi      r6, r3, 0x338
	  stwu      r1, -0x8(r1)
	  subi      r5, r4, 0x8
	  mtctr     r0

	.loc_0x24:
	  lwzu      r4, 0x8(r5)
	  lwz       r0, 0x4(r5)
	  stwu      r4, 0x8(r6)
	  stw       r0, 0x4(r6)
	  bdnz+     .loc_0x24
	  bl        -0x58
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014EC0
 * Size:	000094
 */
void Osc_Setup_SimpleEnv(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,0,24,31
	  cmpwi     r0, 0x1
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  beq-      .loc_0x70
	  bge-      .loc_0x80
	  cmpwi     r0, 0
	  bge-      .loc_0x30
	  b         .loc_0x80

	.loc_0x30:
	  lis       r3, 0x8022
	  li        r0, 0x3
	  addi      r3, r3, 0x58AC
	  addi      r6, r31, 0x338
	  subi      r4, r3, 0x8
	  mtctr     r0

	.loc_0x48:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r6)
	  stw       r0, 0x4(r6)
	  bdnz+     .loc_0x48
	  addi      r3, r31, 0
	  addi      r4, r5, 0
	  bl        -0x5B24
	  stw       r3, 0x348(r31)
	  b         .loc_0x80

	.loc_0x70:
	  addi      r3, r31, 0
	  addi      r4, r5, 0
	  bl        -0x5B38
	  stw       r3, 0x34C(r31)

	.loc_0x80:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80014F60
 * Size:	0000B0
 */
void Osc_Setup_ADSR(void)
{
	/*
	.loc_0x0:
	  lis       r5, 0x8022
	  li        r0, 0x3
	  addi      r8, r5, 0x5828
	  addi      r7, r3, 0x338
	  addi      r6, r8, 0xAC
	  mtctr     r0

	.loc_0x18:
	  lwzu      r5, 0x8(r6)
	  lwz       r0, 0x4(r6)
	  stwu      r5, 0x8(r7)
	  stw       r0, 0x4(r7)
	  bdnz+     .loc_0x18
	  addi      r0, r3, 0x372
	  addi      r6, r3, 0x38A
	  stw       r0, 0x348(r3)
	  li        r0, 0xC
	  li        r5, 0
	  stw       r6, 0x34C(r3)
	  mtctr     r0

	.loc_0x48:
	  add       r6, r8, r5
	  addi      r0, r5, 0x372
	  lha       r6, 0x9C(r6)
	  addi      r5, r5, 0x2
	  sthx      r6, r3, r0
	  bdnz+     .loc_0x48
	  li        r0, 0x6
	  li        r5, 0
	  mtctr     r0

	.loc_0x6C:
	  add       r6, r8, r5
	  addi      r0, r5, 0x38A
	  lha       r6, 0x48(r6)
	  addi      r5, r5, 0x2
	  sthx      r6, r3, r0
	  bdnz+     .loc_0x6C
	  lha       r0, 0x0(r4)
	  sth       r0, 0x374(r3)
	  lha       r0, 0x2(r4)
	  sth       r0, 0x37A(r3)
	  lha       r0, 0x4(r4)
	  sth       r0, 0x380(r3)
	  lha       r0, 0x6(r4)
	  sth       r0, 0x382(r3)
	  lha       r0, 0x8(r4)
	  sth       r0, 0x38C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80015020
 * Size:	00010C
 */
void Osc_Setup_Full(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm    r9,r4,0,28,31
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,24,24
	  rlwinm    r10,r4,0,25,25
	  stwu      r1, -0x30(r1)
	  stmw      r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r29, r6, 0
	  rlwinm    r31,r4,28,31,31
	  rlwinm    r30,r4,0,26,26
	  beq-      .loc_0x84
	  mulli     r8, r31, 0x18
	  lis       r3, 0x8022
	  addi      r3, r3, 0x58AC
	  li        r0, 0x3
	  add       r7, r28, r8
	  subi      r4, r3, 0x8
	  addi      r6, r7, 0x338
	  mtctr     r0
	  addi      r7, r7, 0x340

	.loc_0x54:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r6)
	  stw       r0, 0x4(r6)
	  bdnz+     .loc_0x54
	  cmpwi     r9, 0x1
	  stb       r9, 0x0(r7)
	  beq-      .loc_0x78
	  b         .loc_0x84

	.loc_0x78:
	  lfs       f0, -0x7EB0(r2)
	  add       r3, r28, r8
	  stfs      f0, 0x354(r3)

	.loc_0x84:
	  cmplwi    r10, 0
	  beq-      .loc_0xBC
	  cmplwi    r5, 0
	  bne-      .loc_0xA4
	  mulli     r0, r31, 0x18
	  li        r4, 0
	  add       r3, r28, r0
	  stw       r4, 0x348(r3)

	.loc_0xA4:
	  addi      r3, r28, 0
	  addi      r4, r5, 0
	  bl        -0x5CCC
	  mulli     r0, r31, 0x18
	  add       r4, r28, r0
	  stw       r3, 0x348(r4)

	.loc_0xBC:
	  cmplwi    r30, 0
	  beq-      .loc_0xF8
	  cmplwi    r29, 0
	  bne-      .loc_0xE0
	  mulli     r0, r31, 0x18
	  lis       r3, 0x8022
	  addi      r4, r3, 0x5870
	  add       r3, r28, r0
	  stw       r4, 0x34C(r3)

	.loc_0xE0:
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        -0x5D08
	  mulli     r0, r31, 0x18
	  add       r4, r28, r0
	  stw       r3, 0x34C(r4)

	.loc_0xF8:
	  lmw       r28, 0x20(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}
