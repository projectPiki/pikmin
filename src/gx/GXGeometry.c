#include "types.h"

/*
 * --INFO--
 * Address:	80210B48
 * Size:	00008C
 */
void __GXSetDirtyState(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x20
	  bl        0x1EF8

	.loc_0x20:
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x34
	  bl        0x2334

	.loc_0x34:
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x48
	  bl        0x350

	.loc_0x48:
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  rlwinm.   r0,r0,0,28,28
	  beq-      .loc_0x5C
	  bl        -0x110C

	.loc_0x5C:
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  rlwinm.   r0,r0,0,27,27
	  beq-      .loc_0x70
	  bl        -0x894

	.loc_0x70:
	  lwz       r3, 0x2A68(r13)
	  li        r0, 0
	  stw       r0, 0x4F0(r3)
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80210BD4
 * Size:	0000DC
 */
void GXBegin(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  lwz       r6, 0x2A68(r13)
	  lwz       r0, 0x4F0(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x9C
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x40
	  bl        0x1E4C

	.loc_0x40:
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x54
	  bl        0x2288

	.loc_0x54:
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x68
	  bl        0x2A4

	.loc_0x68:
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  rlwinm.   r0,r0,0,28,28
	  beq-      .loc_0x7C
	  bl        -0x11B8

	.loc_0x7C:
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  rlwinm.   r0,r0,0,27,27
	  beq-      .loc_0x90
	  bl        -0x940

	.loc_0x90:
	  lwz       r3, 0x2A68(r13)
	  li        r0, 0
	  stw       r0, 0x4F0(r3)

	.loc_0x9C:
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xB0
	  bl        .loc_0xDC

	.loc_0xB0:
	  or        r0, r30, r29
	  lis       r3, 0xCC01
	  stb       r0, -0x8000(r3)
	  sth       r31, -0x8000(r3)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr

	.loc_0xDC:
	*/
}

/*
 * --INFO--
 * Address:	80210CB0
 * Size:	000088
 */
void __GXSendFlushPrim(void)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2A68(r13)
	  li        r0, 0x98
	  lis       r5, 0xCC01
	  lhz       r6, 0x0(r3)
	  li        r4, 0
	  lwz       r3, 0x4(r3)
	  mullw     r7, r6, r3
	  stb       r0, -0x8000(r5)
	  sth       r6, -0x8000(r5)
	  addi      r3, r7, 0x3
	  cmplwi    r7, 0
	  rlwinm    r3,r3,30,2,31
	  ble-      .loc_0x78
	  rlwinm.   r0,r3,29,3,31
	  mtctr     r0
	  beq-      .loc_0x6C

	.loc_0x40:
	  stw       r4, -0x8000(r5)
	  stw       r4, -0x8000(r5)
	  stw       r4, -0x8000(r5)
	  stw       r4, -0x8000(r5)
	  stw       r4, -0x8000(r5)
	  stw       r4, -0x8000(r5)
	  stw       r4, -0x8000(r5)
	  stw       r4, -0x8000(r5)
	  bdnz+     .loc_0x40
	  andi.     r3, r3, 0x7
	  beq-      .loc_0x78

	.loc_0x6C:
	  mtctr     r3

	.loc_0x70:
	  stw       r4, -0x8000(r5)
	  bdnz+     .loc_0x70

	.loc_0x78:
	  lwz       r3, 0x2A68(r13)
	  li        r0, 0
	  sth       r0, 0x2(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80210D38
 * Size:	000058
 */
void GXSetLineWidth(void)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r6,r4,16,0,15
	  li        r4, 0x61
	  lwz       r0, 0x7C(r5)
	  addi      r7, r5, 0x7C
	  lis       r5, 0xCC01
	  rlwinm    r0,r0,0,0,23
	  rlwimi    r0,r3,0,24,31
	  stw       r0, 0x0(r7)
	  li        r0, 0x1
	  lwz       r3, 0x2A68(r13)
	  addi      r7, r3, 0x7C
	  lwz       r3, 0x7C(r3)
	  rlwinm    r3,r3,0,16,12
	  or        r3, r3, r6
	  stw       r3, 0x0(r7)
	  stb       r4, -0x8000(r5)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x7C(r4)
	  stw       r3, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void GXGetLineWidth(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80210D90
 * Size:	000054
 */
void GXSetPointSize(void)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r6,r4,19,0,12
	  lwzu      r0, 0x7C(r5)
	  li        r4, 0x61
	  rlwinm    r0,r0,0,24,15
	  rlwimi    r0,r3,8,16,23
	  stw       r0, 0x0(r5)
	  lis       r5, 0xCC01
	  li        r0, 0x1
	  lwz       r3, 0x2A68(r13)
	  addi      r7, r3, 0x7C
	  lwz       r3, 0x7C(r3)
	  rlwinm    r3,r3,0,13,9
	  or        r3, r3, r6
	  stw       r3, 0x0(r7)
	  stb       r4, -0x8000(r5)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x7C(r4)
	  stw       r3, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void GXGetPointSize(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80210DE4
 * Size:	000064
 */
void GXEnableTexOffsets(void)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x2A68(r13)
	  rlwinm    r7,r3,2,0,29
	  add       r6, r0, r7
	  lwz       r3, 0xB8(r6)
	  rlwinm    r0,r4,18,6,13
	  rlwinm    r4,r5,19,5,12
	  rlwinm    r3,r3,0,14,12
	  or        r0, r3, r0
	  stw       r0, 0xB8(r6)
	  li        r3, 0x61
	  lis       r5, 0xCC01
	  lwz       r6, 0x2A68(r13)
	  li        r0, 0x1
	  add       r8, r6, r7
	  lwz       r6, 0xB8(r8)
	  rlwinm    r6,r6,0,13,11
	  or        r4, r6, r4
	  stw       r4, 0xB8(r8)
	  lwz       r4, 0x2A68(r13)
	  stb       r3, -0x8000(r5)
	  add       r3, r4, r7
	  lwz       r3, 0xB8(r3)
	  stw       r3, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80210E48
 * Size:	000050
 */
void GXSetCullMode(void)
{
	/*
	.loc_0x0:
	  cmpwi     r3, 0x2
	  beq-      .loc_0x20
	  bge-      .loc_0x24
	  cmpwi     r3, 0x1
	  bge-      .loc_0x18
	  b         .loc_0x24

	.loc_0x18:
	  li        r3, 0x2
	  b         .loc_0x24

	.loc_0x20:
	  li        r3, 0x1

	.loc_0x24:
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r3,14,0,17
	  lwzu      r3, 0x204(r4)
	  rlwinm    r3,r3,0,18,15
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  ori       r0, r0, 0x4
	  stw       r0, 0x4F0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void GXGetCullMode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80210E98
 * Size:	000044
 */
void GXSetCoPlanar(void)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r3,19,5,12
	  li        r5, 0x61
	  lwz       r3, 0x204(r4)
	  addi      r6, r4, 0x204
	  lis       r4, 0xCC01
	  rlwinm    r3,r3,0,13,11
	  or        r0, r3, r0
	  stw       r0, 0x0(r6)
	  lis       r0, 0xFE08
	  stb       r5, -0x8000(r4)
	  lwz       r3, 0x2A68(r13)
	  stw       r0, -0x8000(r4)
	  stb       r5, -0x8000(r4)
	  lwz       r0, 0x204(r3)
	  stw       r0, -0x8000(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80210EDC
 * Size:	000024
 */
void __GXSetGenMode(void)
{
	/*
	.loc_0x0:
	  li        r0, 0x61
	  lwz       r4, 0x2A68(r13)
	  lis       r5, 0xCC01
	  stb       r0, -0x8000(r5)
	  li        r0, 0x1
	  lwz       r3, 0x204(r4)
	  stw       r3, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}
