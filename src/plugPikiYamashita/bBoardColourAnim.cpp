#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A1E10
 * Size:	00009C
 */
void zen::bBoardColourAnimData::set(unsigned char *)
{
/*
.loc_0x0:
  cmplwi    r4, 0
  beqlr-    
  lbz       r0, 0x0(r4)
  addi      r7, r4, 0x4
  li        r5, 0
  stb       r0, 0x0(r3)
  lbz       r0, 0x1(r4)
  stb       r0, 0x1(r3)
  lbz       r0, 0x2(r4)
  stb       r0, 0x2(r3)
  lbz       r0, 0x3(r4)
  stb       r0, 0x3(r3)
  lbz       r4, 0x3(r3)
  cmplwi    r4, 0
  stw       r7, 0x4(r3)
  ble-      .loc_0x84
  cmplwi    r4, 0x8
  subi      r6, r4, 0x8
  ble-      .loc_0x6C
  addi      r0, r6, 0x7
  rlwinm    r0,r0,29,3,31
  cmplwi    r6, 0
  mtctr     r0
  ble-      .loc_0x6C

.loc_0x60:
  addi      r7, r7, 0x20
  addi      r5, r5, 0x8
  bdnz+     .loc_0x60

.loc_0x6C:
  sub       r0, r4, r5
  cmplw     r5, r4
  mtctr     r0
  bge-      .loc_0x84

.loc_0x7C:
  addi      r7, r7, 0x4
  bdnz+     .loc_0x7C

.loc_0x84:
  lbz       r0, 0x3(r3)
  stw       r7, 0x8(r3)
  rlwinm    r0,r0,2,0,29
  add       r7, r7, r0
  stw       r7, 0xC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801A1EAC
 * Size:	0003C0
 */
void zen::bBoardColourAnim::update(float, Colour *, Colour *)
{
/*
.loc_0x0:
  stwu      r1, -0xF8(r1)
  lis       r0, 0x4330
  lha       r6, 0x6(r3)
  lwz       r9, 0x8(r3)
  subi      r6, r6, 0x1
  lbz       r7, 0x4(r3)
  xoris     r6, r6, 0x8000
  lfd       f4, -0x4C08(r2)
  stw       r6, 0xF4(r1)
  rlwinm    r10,r7,2,0,29
  lwz       r8, 0x4(r9)
  stw       r6, 0xEC(r1)
  add       r6, r8, r10
  lfsx      f5, r8, r10
  stw       r0, 0xF0(r1)
  lfs       f2, 0x4(r6)
  stw       r0, 0xE8(r1)
  lfd       f3, 0xF0(r1)
  lfd       f0, 0xE8(r1)
  fsubs     f6, f3, f4
  lfs       f3, 0x0(r3)
  fsubs     f4, f0, f4
  lfs       f0, -0x4C10(r2)
  fmuls     f5, f6, f5
  fmuls     f2, f4, f2
  fsubs     f4, f3, f5
  fsubs     f3, f2, f5
  fdivs     f3, f4, f3
  fcmpo     cr0, f3, f0
  fmr       f4, f3
  ble-      .loc_0x80
  fmr       f4, f0

.loc_0x80:
  addi      r0, r7, 0x1
  lwz       r6, 0x8(r9)
  rlwinm    r0,r0,2,0,29
  lfs       f3, -0x4C10(r2)
  add       r9, r6, r0
  lfd       f0, -0x4C00(r2)
  add       r8, r6, r10
  lbz       r6, 0x0(r9)
  lbz       r7, 0x0(r8)
  lis       r0, 0x4330
  stw       r6, 0xF4(r1)
  fsubs     f3, f3, f4
  stw       r7, 0xEC(r1)
  stw       r0, 0xE8(r1)
  stw       r0, 0xF0(r1)
  lfd       f6, 0xE8(r1)
  lfd       f5, 0xF0(r1)
  fsubs     f6, f6, f0
  fsubs     f5, f5, f0
  fmuls     f6, f6, f3
  fmuls     f5, f5, f4
  fadds     f5, f6, f5
  fctiwz    f5, f5
  stfd      f5, 0xE0(r1)
  lwz       r6, 0xE4(r1)
  stb       r6, 0x0(r4)
  lbz       r7, 0x1(r8)
  lbz       r6, 0x1(r9)
  stw       r7, 0xDC(r1)
  stw       r6, 0xD4(r1)
  stw       r0, 0xD8(r1)
  stw       r0, 0xD0(r1)
  lfd       f6, 0xD8(r1)
  lfd       f5, 0xD0(r1)
  fsubs     f6, f6, f0
  fsubs     f5, f5, f0
  fmuls     f6, f6, f3
  fmuls     f5, f5, f4
  fadds     f5, f6, f5
  fctiwz    f5, f5
  stfd      f5, 0xC8(r1)
  lwz       r6, 0xCC(r1)
  stb       r6, 0x1(r4)
  lbz       r7, 0x2(r8)
  lbz       r6, 0x2(r9)
  stw       r7, 0xC4(r1)
  stw       r6, 0xBC(r1)
  stw       r0, 0xC0(r1)
  stw       r0, 0xB8(r1)
  lfd       f6, 0xC0(r1)
  lfd       f5, 0xB8(r1)
  fsubs     f6, f6, f0
  fsubs     f5, f5, f0
  fmuls     f6, f6, f3
  fmuls     f5, f5, f4
  fadds     f5, f6, f5
  fctiwz    f5, f5
  stfd      f5, 0xB0(r1)
  lwz       r6, 0xB4(r1)
  stb       r6, 0x2(r4)
  lbz       r7, 0x3(r8)
  lbz       r6, 0x3(r9)
  stw       r7, 0xAC(r1)
  stw       r6, 0xA4(r1)
  stw       r0, 0xA8(r1)
  stw       r0, 0xA0(r1)
  lfd       f6, 0xA8(r1)
  lfd       f5, 0xA0(r1)
  fsubs     f6, f6, f0
  fsubs     f5, f5, f0
  fmuls     f6, f6, f3
  fmuls     f5, f5, f4
  fadds     f5, f6, f5
  fctiwz    f5, f5
  stfd      f5, 0x98(r1)
  lwz       r6, 0x9C(r1)
  stb       r6, 0x3(r4)
  lbz       r7, 0x4(r3)
  lwz       r6, 0x8(r3)
  addi      r4, r7, 0x1
  lwz       r9, 0xC(r6)
  rlwinm    r6,r4,2,0,29
  rlwinm    r4,r7,2,0,29
  add       r8, r9, r6
  add       r7, r9, r4
  lbz       r6, 0x0(r7)
  lbz       r4, 0x0(r8)
  stw       r6, 0x94(r1)
  stw       r4, 0x8C(r1)
  stw       r0, 0x90(r1)
  stw       r0, 0x88(r1)
  lfd       f6, 0x90(r1)
  lfd       f5, 0x88(r1)
  fsubs     f6, f6, f0
  fsubs     f5, f5, f0
  fmuls     f6, f6, f3
  fmuls     f5, f5, f4
  fadds     f5, f6, f5
  fctiwz    f5, f5
  stfd      f5, 0x80(r1)
  lwz       r4, 0x84(r1)
  stb       r4, 0x0(r5)
  lbz       r6, 0x1(r7)
  lbz       r4, 0x1(r8)
  stw       r6, 0x7C(r1)
  stw       r4, 0x74(r1)
  stw       r0, 0x78(r1)
  stw       r0, 0x70(r1)
  lfd       f6, 0x78(r1)
  lfd       f5, 0x70(r1)
  fsubs     f6, f6, f0
  fsubs     f5, f5, f0
  fmuls     f6, f6, f3
  fmuls     f5, f5, f4
  fadds     f5, f6, f5
  fctiwz    f5, f5
  stfd      f5, 0x68(r1)
  lwz       r4, 0x6C(r1)
  stb       r4, 0x1(r5)
  lbz       r6, 0x2(r7)
  lbz       r4, 0x2(r8)
  stw       r6, 0x64(r1)
  stw       r4, 0x5C(r1)
  stw       r0, 0x60(r1)
  stw       r0, 0x58(r1)
  lfd       f6, 0x60(r1)
  lfd       f5, 0x58(r1)
  fsubs     f6, f6, f0
  fsubs     f5, f5, f0
  fmuls     f6, f6, f3
  fmuls     f5, f5, f4
  fadds     f5, f6, f5
  fctiwz    f5, f5
  stfd      f5, 0x50(r1)
  lwz       r4, 0x54(r1)
  stb       r4, 0x2(r5)
  lbz       r6, 0x3(r7)
  lbz       r4, 0x3(r8)
  stw       r6, 0x4C(r1)
  stw       r4, 0x44(r1)
  stw       r0, 0x48(r1)
  stw       r0, 0x40(r1)
  lfd       f6, 0x48(r1)
  lfd       f5, 0x40(r1)
  fsubs     f6, f6, f0
  fsubs     f0, f5, f0
  fmuls     f3, f6, f3
  fmuls     f0, f0, f4
  fadds     f0, f3, f0
  fctiwz    f0, f0
  stfd      f0, 0x38(r1)
  lwz       r0, 0x3C(r1)
  stb       r0, 0x3(r5)
  lfs       f0, 0x0(r3)
  fcmpo     cr0, f0, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x334
  lbz       r4, 0x4(r3)
  addi      r0, r4, 0x1
  stb       r0, 0x4(r3)
  rlwinm    r0,r0,0,24,31
  lwz       r5, 0x8(r3)
  lbz       r4, 0x3(r5)
  subi      r4, r4, 0x1
  cmpw      r0, r4
  blt-      .loc_0x334
  lbz       r0, 0x2(r5)
  cmplwi    r0, 0
  beq-      .loc_0x32C
  stb       r4, 0x4(r3)
  b         .loc_0x334

.loc_0x32C:
  li        r0, 0
  stb       r0, 0x4(r3)

.loc_0x334:
  lfs       f0, 0x0(r3)
  lis       r5, 0x4330
  fadds     f0, f0, f1
  stfs      f0, 0x0(r3)
  lha       r0, 0x6(r3)
  lfd       f1, -0x4C08(r2)
  xoris     r6, r0, 0x8000
  lfs       f2, 0x0(r3)
  stw       r6, 0x3C(r1)
  stw       r5, 0x38(r1)
  lfd       f0, 0x38(r1)
  fsubs     f0, f0, f1
  fcmpo     cr0, f2, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x3B8
  lwz       r4, 0x8(r3)
  lbz       r0, 0x2(r4)
  cmplwi    r0, 0
  beq-      .loc_0x3A8
  stw       r6, 0x3C(r1)
  stw       r5, 0x38(r1)
  lfd       f0, 0x38(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x0(r3)
  lwz       r4, 0x8(r3)
  lbz       r4, 0x3(r4)
  subi      r0, r4, 0x1
  stb       r0, 0x4(r3)
  b         .loc_0x3B8

.loc_0x3A8:
  lfs       f0, -0x4C0C(r2)
  li        r0, 0
  stfs      f0, 0x0(r3)
  stb       r0, 0x4(r3)

.loc_0x3B8:
  addi      r1, r1, 0xF8
  blr
*/
}
