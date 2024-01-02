#include "types.h"

/*
 * --INFO--
 * Address:	80212BC8
 * Size:	00009C
 */
void GXSetTevIndirect(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x28(r1)
	  rlwinm    r4,r4,0,30,27
	  rlwinm    r0,r5,2,0,29
	  or        r0, r4, r0
	  lwz       r11, 0x34(r1)
	  rlwinm    r5,r0,0,28,24
	  lbz       r12, 0x33(r1)
	  rlwinm    r0,r6,4,0,27
	  lwz       r4, 0x2A68(r13)
	  or        r0, r5, r0
	  rlwinm    r5,r0,0,25,22
	  rlwinm    r0,r11,7,0,24
	  or        r0, r5, r0
	  rlwinm    r5,r0,0,23,18
	  rlwinm    r0,r7,9,0,22
	  or        r0, r5, r0
	  rlwinm    r5,r0,0,19,15
	  rlwinm    r0,r8,13,0,18
	  or        r0, r5, r0
	  addi      r5, r3, 0x10
	  rlwinm    r3,r0,0,16,12
	  rlwinm    r0,r9,16,0,15
	  or        r0, r3, r0
	  rlwinm    r3,r0,0,13,11
	  rlwinm    r0,r12,19,0,12
	  or        r0, r3, r0
	  rlwinm    r3,r0,0,12,10
	  rlwinm    r0,r10,20,4,11
	  or        r6, r3, r0
	  li        r0, 0x61
	  lis       r3, 0xCC01
	  stb       r0, -0x8000(r3)
	  rlwinm    r0,r5,24,0,7
	  rlwimi    r0,r6,0,8,31
	  stw       r0, -0x8000(r3)
	  li        r0, 0x1
	  addi      r1, r1, 0x28
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000160
 */
void GXSetIndTexMtx(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80212C64
 * Size:	0001D4
 */
void GXSetIndTexCoordScale(void)
{
	/*
	.loc_0x0:
	  cmpwi     r3, 0x2
	  beq-      .loc_0xF8
	  bge-      .loc_0x1C
	  cmpwi     r3, 0
	  beq-      .loc_0x28
	  bge-      .loc_0x90
	  b         .loc_0x1C4

	.loc_0x1C:
	  cmpwi     r3, 0x4
	  bge-      .loc_0x1C4
	  b         .loc_0x160

	.loc_0x28:
	  lwz       r6, 0x2A68(r13)
	  rlwinm    r3,r5,4,0,27
	  li        r0, 0x61
	  addi      r7, r6, 0x128
	  lwz       r6, 0x128(r6)
	  lis       r5, 0xCC01
	  rlwinm    r6,r6,0,0,27
	  or        r4, r6, r4
	  stw       r4, 0x0(r7)
	  lwz       r4, 0x2A68(r13)
	  addi      r6, r4, 0x128
	  lwz       r4, 0x128(r4)
	  rlwinm    r4,r4,0,28,23
	  or        r3, r4, r3
	  stw       r3, 0x0(r6)
	  lwz       r3, 0x2A68(r13)
	  addi      r4, r3, 0x128
	  lwz       r3, 0x128(r3)
	  rlwinm    r3,r3,0,8,31
	  oris      r3, r3, 0x2500
	  stw       r3, 0x0(r4)
	  stb       r0, -0x8000(r5)
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x128(r3)
	  stw       r0, -0x8000(r5)
	  b         .loc_0x1C4

	.loc_0x90:
	  lwz       r7, 0x2A68(r13)
	  rlwinm    r3,r5,12,0,19
	  lwzu      r5, 0x128(r7)
	  rlwinm    r6,r4,8,0,23
	  li        r0, 0x61
	  rlwinm    r5,r5,0,24,19
	  or        r5, r5, r6
	  stw       r5, 0x0(r7)
	  lis       r4, 0xCC01
	  lwz       r5, 0x2A68(r13)
	  addi      r6, r5, 0x128
	  lwz       r5, 0x128(r5)
	  rlwinm    r5,r5,0,20,15
	  or        r3, r5, r3
	  stw       r3, 0x0(r6)
	  lwz       r3, 0x2A68(r13)
	  addi      r5, r3, 0x128
	  lwz       r3, 0x128(r3)
	  rlwinm    r3,r3,0,8,31
	  oris      r3, r3, 0x2500
	  stw       r3, 0x0(r5)
	  stb       r0, -0x8000(r4)
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x128(r3)
	  stw       r0, -0x8000(r4)
	  b         .loc_0x1C4

	.loc_0xF8:
	  lwz       r6, 0x2A68(r13)
	  rlwinm    r3,r5,4,0,27
	  li        r0, 0x61
	  addi      r7, r6, 0x12C
	  lwz       r6, 0x12C(r6)
	  lis       r5, 0xCC01
	  rlwinm    r6,r6,0,0,27
	  or        r4, r6, r4
	  stw       r4, 0x0(r7)
	  lwz       r4, 0x2A68(r13)
	  addi      r6, r4, 0x12C
	  lwz       r4, 0x12C(r4)
	  rlwinm    r4,r4,0,28,23
	  or        r3, r4, r3
	  stw       r3, 0x0(r6)
	  lwz       r3, 0x2A68(r13)
	  addi      r4, r3, 0x12C
	  lwz       r3, 0x12C(r3)
	  rlwinm    r3,r3,0,8,31
	  oris      r3, r3, 0x2600
	  stw       r3, 0x0(r4)
	  stb       r0, -0x8000(r5)
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x12C(r3)
	  stw       r0, -0x8000(r5)
	  b         .loc_0x1C4

	.loc_0x160:
	  lwz       r7, 0x2A68(r13)
	  rlwinm    r3,r5,12,0,19
	  lwzu      r5, 0x12C(r7)
	  rlwinm    r6,r4,8,0,23
	  li        r0, 0x61
	  rlwinm    r5,r5,0,24,19
	  or        r5, r5, r6
	  stw       r5, 0x0(r7)
	  lis       r4, 0xCC01
	  lwz       r5, 0x2A68(r13)
	  addi      r6, r5, 0x12C
	  lwz       r5, 0x12C(r5)
	  rlwinm    r5,r5,0,20,15
	  or        r3, r5, r3
	  stw       r3, 0x0(r6)
	  lwz       r3, 0x2A68(r13)
	  addi      r5, r3, 0x12C
	  lwz       r3, 0x12C(r3)
	  rlwinm    r3,r3,0,8,31
	  oris      r3, r3, 0x2600
	  stw       r3, 0x0(r5)
	  stb       r0, -0x8000(r4)
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x12C(r3)
	  stw       r0, -0x8000(r4)

	.loc_0x1C4:
	  lwz       r3, 0x2A68(r13)
	  li        r0, 0x1
	  sth       r0, 0x2(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000138
 */
void GXSetIndTexOrder(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80212E38
 * Size:	00002C
 */
void GXSetNumIndStages(void)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r3,16,8,15
	  lwzu      r3, 0x204(r4)
	  rlwinm    r3,r3,0,16,12
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  ori       r0, r0, 0x6
	  stw       r0, 0x4F0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80212E64
 * Size:	000048
 */
void GXSetTevDirect(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  li        r5, 0
	  stwu      r1, -0x18(r1)
	  li        r6, 0
	  li        r7, 0
	  stw       r0, 0x8(r1)
	  li        r8, 0
	  li        r9, 0
	  stw       r0, 0xC(r1)
	  li        r10, 0
	  bl        -0x2D0
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void GXSetTevIndWarp(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001AC
 */
void GXSetTevIndTile(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void GXSetTevIndBumpST(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void GXSetTevIndBumpXYZ(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void GXSetTevIndRepeat(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80212EAC
 * Size:	0000CC
 */
void __GXUpdateBPMask(void)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2A68(r13)
	  li        r6, 0
	  li        r4, 0
	  lwz       r0, 0x204(r3)
	  rlwinm    r0,r0,16,29,31
	  cmplwi    r0, 0
	  mtctr     r0
	  ble-      .loc_0x88

	.loc_0x20:
	  cmpwi     r4, 0x2
	  beq-      .loc_0x60
	  bge-      .loc_0x3C
	  cmpwi     r4, 0
	  beq-      .loc_0x48
	  bge-      .loc_0x54
	  b         .loc_0x74

	.loc_0x3C:
	  cmpwi     r4, 0x4
	  bge-      .loc_0x74
	  b         .loc_0x6C

	.loc_0x48:
	  lwz       r0, 0x120(r3)
	  rlwinm    r5,r0,0,29,31
	  b         .loc_0x74

	.loc_0x54:
	  lwz       r0, 0x120(r3)
	  rlwinm    r5,r0,26,29,31
	  b         .loc_0x74

	.loc_0x60:
	  lwz       r0, 0x120(r3)
	  rlwinm    r5,r0,20,29,31
	  b         .loc_0x74

	.loc_0x6C:
	  lwz       r0, 0x120(r3)
	  rlwinm    r5,r0,14,29,31

	.loc_0x74:
	  li        r0, 0x1
	  slw       r0, r0, r5
	  or        r6, r6, r0
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x20

	.loc_0x88:
	  addi      r4, r3, 0x124
	  lwz       r3, 0x124(r3)
	  rlwinm    r0,r3,0,24,31
	  cmplw     r0, r6
	  beqlr-
	  rlwinm    r0,r3,0,0,23
	  or        r0, r0, r6
	  stw       r0, 0x0(r4)
	  li        r0, 0x61
	  lis       r5, 0xCC01
	  stb       r0, -0x8000(r5)
	  li        r0, 0x1
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x124(r4)
	  stw       r3, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80212F78
 * Size:	000024
 */
void __GXFlushTextureState(void)
{
	/*
	.loc_0x0:
	  li        r0, 0x61
	  lwz       r4, 0x2A68(r13)
	  lis       r5, 0xCC01
	  stb       r0, -0x8000(r5)
	  li        r0, 0x1
	  lwz       r3, 0x124(r4)
	  stw       r3, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}
