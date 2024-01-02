#include "types.h"

/*
 * --INFO--
 * Address:	80213998
 * Size:	0001B4
 */
void GXSetFog(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  fcmpu     cr0, f4, f3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x3C(r1)
	  stw       r28, 0x38(r1)
	  addi      r28, r4, 0
	  beq-      .loc_0x34
	  fcmpu     cr0, f2, f1
	  bne-      .loc_0x44

	.loc_0x34:
	  lfs       f3, -0x3C58(r2)
	  lfs       f4, -0x3C54(r2)
	  fmr       f5, f3
	  b         .loc_0x60

	.loc_0x44:
	  fsubs     f0, f4, f3
	  fsubs     f5, f2, f1
	  fmuls     f2, f4, f3
	  fdivs     f4, f4, f0
	  fmuls     f0, f0, f5
	  fdivs     f5, f1, f5
	  fdivs     f3, f2, f0

	.loc_0x60:
	  lfs       f1, -0x3C54(r2)
	  li        r3, 0
	  lfd       f0, -0x3C50(r2)
	  b         .loc_0x78

	.loc_0x70:
	  fmuls     f4, f4, f1
	  addi      r3, r3, 0x1

	.loc_0x78:
	  fcmpo     cr0, f4, f0
	  bgt+      .loc_0x70
	  lfd       f0, -0x3C40(r2)
	  lfs       f2, -0x3C48(r2)
	  lfs       f1, -0x3C58(r2)
	  b         .loc_0x98

	.loc_0x90:
	  fmuls     f4, f4, f2
	  subi      r3, r3, 0x1

	.loc_0x98:
	  fcmpo     cr0, f4, f1
	  ble-      .loc_0xA8
	  fcmpo     cr0, f4, f0
	  blt+      .loc_0x90

	.loc_0xA8:
	  addi      r29, r3, 0x1
	  lfs       f0, -0x3C38(r2)
	  li        r31, 0x1
	  lfd       f2, -0x3C30(r2)
	  slw       r0, r31, r29
	  fmuls     f1, f0, f4
	  xoris     r3, r0, 0x8000
	  stfs      f5, 0x28(r1)
	  lis       r0, 0x4330
	  stw       r3, 0x34(r1)
	  stw       r0, 0x30(r1)
	  lfd       f0, 0x30(r1)
	  fsubs     f0, f0, f2
	  fdivs     f0, f3, f0
	  stfs      f0, 0x2C(r1)
	  bl        0x134C
	  lwz       r0, 0x2C(r1)
	  rlwinm    r9,r3,0,8,31
	  lbz       r6, 0x1(r28)
	  rlwinm    r8,r29,0,8,31
	  rlwinm    r4,r0,20,13,20
	  rlwimi    r4,r0,20,21,31
	  lbz       r11, 0x2(r28)
	  rlwinm    r0,r0,20,12,12
	  lbz       r5, 0x0(r28)
	  rlwimi    r0,r4,0,13,31
	  lwz       r12, 0x28(r1)
	  rlwinm    r7,r0,0,8,31
	  lwz       r3, 0x2A68(r13)
	  oris      r10, r7, 0xEE00
	  li        r0, 0x61
	  lis       r4, 0xCC01
	  stb       r0, -0x8000(r4)
	  oris      r7, r9, 0xEF00
	  rlwinm    r6,r6,8,0,23
	  stw       r10, -0x8000(r4)
	  rlwinm    r10,r12,20,13,20
	  rlwimi    r10,r12,20,21,31
	  stb       r0, -0x8000(r4)
	  rlwinm    r9,r12,20,12,12
	  rlwimi    r9,r10,0,13,31
	  stw       r7, -0x8000(r4)
	  oris      r7, r8, 0xF000
	  rlwimi    r6,r11,0,24,31
	  stb       r0, -0x8000(r4)
	  stw       r7, -0x8000(r4)
	  rlwinm    r7,r30,21,0,10
	  rlwimi    r7,r9,0,12,31
	  rlwinm    r7,r7,0,8,31
	  stb       r0, -0x8000(r4)
	  oris      r7, r7, 0xF100
	  stw       r7, -0x8000(r4)
	  stb       r0, -0x8000(r4)
	  rlwinm    r0,r5,16,0,15
	  rlwimi    r0,r6,0,16,31
	  rlwinm    r0,r0,0,8,31
	  oris      r0, r0, 0xF200
	  stw       r0, -0x8000(r4)
	  sth       r31, 0x2(r3)
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  mtlr      r0
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x48
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001C8
 */
void GXInitFogAdjTable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80213B4C
 * Size:	000100
 */
void GXSetFogRangeAdj(void)
{
	/*
	.loc_0x0:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC4
	  lhz       r8, 0x2(r5)
	  li        r0, 0x61
	  lhz       r10, 0x0(r5)
	  lis       r6, 0xCC01
	  rlwinm    r8,r8,12,0,19
	  rlwimi    r8,r10,0,20,31
	  stb       r0, -0x8000(r6)
	  li        r7, 0xE9
	  rlwinm    r9,r8,0,8,31
	  rlwimi    r9,r7,24,0,7
	  stw       r9, -0x8000(r6)
	  li        r7, 0xEA
	  rlwinm    r9,r7,24,0,7
	  lhzu      r10, 0x4(r5)
	  li        r7, 0xEB
	  lhz       r8, 0x2(r5)
	  rlwinm    r8,r8,12,0,19
	  stb       r0, -0x8000(r6)
	  rlwimi    r8,r10,0,20,31
	  rlwimi    r9,r8,0,8,31
	  stw       r9, -0x8000(r6)
	  rlwinm    r9,r7,24,0,7
	  li        r7, 0xEC
	  lhz       r8, 0x6(r5)
	  lhz       r10, 0x4(r5)
	  rlwinm    r8,r8,12,0,19
	  rlwimi    r8,r10,0,20,31
	  stb       r0, -0x8000(r6)
	  rlwimi    r9,r8,0,8,31
	  stw       r9, -0x8000(r6)
	  rlwinm    r9,r7,24,0,7
	  li        r7, 0xED
	  lhz       r8, 0xA(r5)
	  lhz       r10, 0x8(r5)
	  rlwinm    r8,r8,12,0,19
	  rlwimi    r8,r10,0,20,31
	  stb       r0, -0x8000(r6)
	  rlwimi    r9,r8,0,8,31
	  stw       r9, -0x8000(r6)
	  lhz       r8, 0xE(r5)
	  lhz       r10, 0xC(r5)
	  rlwinm    r8,r8,12,0,19
	  rlwimi    r8,r10,0,20,31
	  stb       r0, -0x8000(r6)
	  rlwinm    r9,r8,0,8,31
	  rlwimi    r9,r7,24,0,7
	  stw       r9, -0x8000(r6)

	.loc_0xC4:
	  rlwinm    r5,r4,0,16,31
	  lwz       r4, 0x2A68(r13)
	  addi      r0, r5, 0x154
	  rlwinm    r5,r0,0,22,20
	  rlwinm    r0,r3,10,14,21
	  or        r0, r5, r0
	  rlwinm    r5,r0,0,8,31
	  li        r0, 0x61
	  lis       r3, 0xCC01
	  stb       r0, -0x8000(r3)
	  oris      r5, r5, 0xE800
	  li        r0, 0x1
	  stw       r5, -0x8000(r3)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80213C4C
 * Size:	000104
 */
void GXSetBlendMode(void)
{
	/*
	.loc_0x0:
	  cmpwi     r3, 0x1
	  li        r9, 0x1
	  beq-      .loc_0x18
	  cmpwi     r3, 0x3
	  beq-      .loc_0x18
	  li        r9, 0

	.loc_0x18:
	  lwz       r8, 0x2A68(r13)
	  subfic    r0, r3, 0x3
	  cntlzw    r7, r0
	  addi      r10, r8, 0x1D0
	  lwz       r8, 0x1D0(r8)
	  subfic    r0, r3, 0x2
	  rlwinm    r3,r8,0,0,30
	  or        r3, r3, r9
	  stw       r3, 0x0(r10)
	  cntlzw    r0, r0
	  rlwinm    r3,r7,6,0,20
	  lwz       r9, 0x2A68(r13)
	  rlwinm    r8,r0,28,4,30
	  lwzu      r0, 0x1D0(r9)
	  rlwinm    r7,r6,12,0,19
	  rlwinm    r6,r4,8,0,23
	  rlwinm    r0,r0,0,21,19
	  or        r0, r0, r3
	  stw       r0, 0x0(r9)
	  rlwinm    r4,r5,5,0,26
	  li        r3, 0x61
	  lwz       r9, 0x2A68(r13)
	  lis       r5, 0xCC01
	  li        r0, 0x1
	  addi      r10, r9, 0x1D0
	  lwz       r9, 0x1D0(r9)
	  rlwinm    r9,r9,0,31,29
	  or        r8, r9, r8
	  stw       r8, 0x0(r10)
	  lwz       r8, 0x2A68(r13)
	  addi      r9, r8, 0x1D0
	  lwz       r8, 0x1D0(r8)
	  rlwinm    r8,r8,0,20,15
	  or        r7, r8, r7
	  stw       r7, 0x0(r9)
	  lwz       r7, 0x2A68(r13)
	  addi      r8, r7, 0x1D0
	  lwz       r7, 0x1D0(r7)
	  rlwinm    r7,r7,0,24,20
	  or        r6, r7, r6
	  stw       r6, 0x0(r8)
	  lwz       r6, 0x2A68(r13)
	  addi      r7, r6, 0x1D0
	  lwz       r6, 0x1D0(r6)
	  rlwinm    r6,r6,0,27,23
	  or        r4, r6, r4
	  stw       r4, 0x0(r7)
	  lwz       r4, 0x2A68(r13)
	  addi      r6, r4, 0x1D0
	  lwz       r4, 0x1D0(r4)
	  rlwinm    r4,r4,0,8,31
	  oris      r4, r4, 0x4100
	  stw       r4, 0x0(r6)
	  stb       r3, -0x8000(r5)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x1D0(r4)
	  stw       r3, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80213D50
 * Size:	000040
 */
void GXSetColorUpdate(void)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r3,3,21,28
	  li        r3, 0x61
	  addi      r6, r4, 0x1D0
	  lwz       r4, 0x1D0(r4)
	  lis       r5, 0xCC01
	  rlwinm    r4,r4,0,29,27
	  or        r0, r4, r0
	  stw       r0, 0x0(r6)
	  li        r0, 0x1
	  stb       r3, -0x8000(r5)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x1D0(r4)
	  stw       r3, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80213D90
 * Size:	000040
 */
void GXSetAlphaUpdate(void)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r3,4,20,27
	  li        r3, 0x61
	  addi      r6, r4, 0x1D0
	  lwz       r4, 0x1D0(r4)
	  lis       r5, 0xCC01
	  rlwinm    r4,r4,0,28,26
	  or        r0, r4, r0
	  stw       r0, 0x0(r6)
	  li        r0, 0x1
	  stb       r3, -0x8000(r5)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x1D0(r4)
	  stw       r3, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80213DD0
 * Size:	000078
 */
void GXSetZMode(void)
{
	/*
	.loc_0x0:
	  lwz       r6, 0x2A68(r13)
	  rlwinm    r0,r3,0,24,31
	  lwz       r3, 0x1D8(r6)
	  addi      r7, r6, 0x1D8
	  rlwinm    r6,r4,1,0,30
	  rlwinm    r3,r3,0,0,30
	  or        r0, r3, r0
	  stw       r0, 0x0(r7)
	  rlwinm    r4,r5,4,20,27
	  li        r3, 0x61
	  lwz       r7, 0x2A68(r13)
	  lis       r5, 0xCC01
	  li        r0, 0x1
	  addi      r8, r7, 0x1D8
	  lwz       r7, 0x1D8(r7)
	  rlwinm    r7,r7,0,31,27
	  or        r6, r7, r6
	  stw       r6, 0x0(r8)
	  lwz       r6, 0x2A68(r13)
	  addi      r7, r6, 0x1D8
	  lwz       r6, 0x1D8(r6)
	  rlwinm    r6,r6,0,28,26
	  or        r4, r6, r4
	  stw       r4, 0x0(r7)
	  stb       r3, -0x8000(r5)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x1D8(r4)
	  stw       r3, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80213E48
 * Size:	000040
 */
void GXSetZCompLoc(void)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r3,6,18,25
	  li        r3, 0x61
	  addi      r6, r4, 0x1DC
	  lwz       r4, 0x1DC(r4)
	  lis       r5, 0xCC01
	  rlwinm    r4,r4,0,26,24
	  or        r0, r4, r0
	  stw       r0, 0x0(r6)
	  li        r0, 0x1
	  stb       r3, -0x8000(r5)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x1DC(r4)
	  stw       r3, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80213E88
 * Size:	000110
 */
void GXSetPixelFmt(void)
{
	/*
	.loc_0x0:
	  lwz       r7, 0x2A68(r13)
	  lis       r5, 0x802F
	  rlwinm    r6,r3,2,0,29
	  addi      r8, r7, 0x1DC
	  subi      r0, r5, 0x7028
	  lwz       r7, 0x1DC(r7)
	  add       r9, r0, r6
	  lwz       r5, 0x0(r9)
	  rlwinm    r6,r7,0,0,28
	  rlwinm    r0,r4,3,0,28
	  or        r4, r6, r5
	  stw       r4, 0x0(r8)
	  lwz       r4, 0x2A68(r13)
	  addi      r5, r4, 0x1DC
	  lwz       r4, 0x1DC(r4)
	  rlwinm    r4,r4,0,29,25
	  or        r0, r4, r0
	  stw       r0, 0x0(r5)
	  lwz       r4, 0x2A68(r13)
	  lwz       r5, 0x1DC(r4)
	  cmplw     r7, r5
	  beq-      .loc_0xA8
	  li        r0, 0x61
	  lis       r4, 0xCC01
	  stb       r0, -0x8000(r4)
	  cmpwi     r3, 0x2
	  stw       r5, -0x8000(r4)
	  bne-      .loc_0x78
	  li        r0, 0x1
	  b         .loc_0x7C

	.loc_0x78:
	  li        r0, 0

	.loc_0x7C:
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r0,9,15,22
	  addi      r5, r4, 0x204
	  lwz       r4, 0x204(r4)
	  rlwinm    r4,r4,0,23,21
	  or        r0, r4, r0
	  stw       r0, 0x0(r5)
	  lwz       r4, 0x2A68(r13)
	  lwz       r0, 0x4F0(r4)
	  ori       r0, r0, 0x4
	  stw       r0, 0x4F0(r4)

	.loc_0xA8:
	  lwz       r0, 0x0(r9)
	  cmplwi    r0, 0x4
	  bne-      .loc_0x100
	  lwz       r4, 0x2A68(r13)
	  subi      r3, r3, 0x4
	  li        r0, 0x61
	  addi      r5, r4, 0x1D4
	  lwz       r4, 0x1D4(r4)
	  rlwinm    r4,r4,0,23,20
	  rlwimi    r4,r3,9,21,22
	  stw       r4, 0x0(r5)
	  lis       r4, 0xCC01
	  lwz       r3, 0x2A68(r13)
	  addi      r5, r3, 0x1D4
	  lwz       r3, 0x1D4(r3)
	  rlwinm    r3,r3,0,8,31
	  oris      r3, r3, 0x4200
	  stw       r3, 0x0(r5)
	  stb       r0, -0x8000(r4)
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x1D4(r3)
	  stw       r0, -0x8000(r4)

	.loc_0x100:
	  lwz       r3, 0x2A68(r13)
	  li        r0, 0x1
	  sth       r0, 0x2(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80213F98
 * Size:	000040
 */
void GXSetDither(void)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r3,2,22,29
	  li        r3, 0x61
	  addi      r6, r4, 0x1D0
	  lwz       r4, 0x1D0(r4)
	  lis       r5, 0xCC01
	  rlwinm    r4,r4,0,30,28
	  or        r0, r4, r0
	  stw       r0, 0x0(r6)
	  li        r0, 0x1
	  stb       r3, -0x8000(r5)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x1D0(r4)
	  stw       r3, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80213FD8
 * Size:	000054
 */
void GXSetDstAlpha(void)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r6,r3,8,16,23
	  lwzu      r0, 0x1D4(r5)
	  li        r3, 0x61
	  rlwinm    r0,r0,0,0,23
	  rlwimi    r0,r4,0,24,31
	  stw       r0, 0x0(r5)
	  lis       r5, 0xCC01
	  li        r0, 0x1
	  lwz       r4, 0x2A68(r13)
	  addi      r7, r4, 0x1D4
	  lwz       r4, 0x1D4(r4)
	  rlwinm    r4,r4,0,24,22
	  or        r4, r4, r6
	  stw       r4, 0x0(r7)
	  stb       r3, -0x8000(r5)
	  lwz       r4, 0x2A68(r13)
	  lwz       r3, 0x1D4(r4)
	  stw       r3, -0x8000(r5)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021402C
 * Size:	000038
 */
void GXSetFieldMask(void)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r4,0,24,31
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r5,r0,0,31,29
	  rlwinm    r0,r3,1,23,30
	  or        r0, r5, r0
	  rlwinm    r5,r0,0,8,31
	  li        r0, 0x61
	  lis       r3, 0xCC01
	  stb       r0, -0x8000(r3)
	  oris      r5, r5, 0x4400
	  li        r0, 0x1
	  stw       r5, -0x8000(r3)
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80214064
 * Size:	000080
 */
void GXSetFieldMode(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,22,2,9
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  lis       r31, 0xCC01
	  stw       r30, 0x18(r1)
	  li        r30, 0x61
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r5, 0x2A68(r13)
	  lwzu      r4, 0x7C(r5)
	  rlwinm    r4,r4,0,10,8
	  or        r0, r4, r0
	  stw       r0, 0x0(r5)
	  stb       r30, -0x8000(r31)
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x7C(r3)
	  stw       r0, -0x8000(r31)
	  bl        -0x1138
	  rlwinm    r0,r29,0,24,31
	  stb       r30, -0x8000(r31)
	  oris      r0, r0, 0x6800
	  stw       r0, -0x8000(r31)
	  bl        -0x114C
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}
