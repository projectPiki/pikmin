#include "types.h"
#include "std/Math.h"

/*
 * --INFO--
 * Address:	8000DC20
 * Size:	000020
 */
void sqrtf2(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        .loc_0x20
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x20:
	*/
}

/*
 * --INFO--
 * Address:	8000DC40
 * Size:	000064
 */
void std::sqrtf(f32)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x10(r1)
	  lfs       f0, -0x7F60(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x5C
	  fsqrte    f2, f1
	  lfd       f4, -0x7F58(r2)
	  lfd       f3, -0x7F50(r2)
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fnmsub    f0, f1, f0, f3
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fnmsub    f0, f1, f0, f3
	  fmul      f2, f2, f0
	  fmul      f0, f2, f2
	  fmul      f2, f4, f2
	  fnmsub    f0, f1, f0, f3
	  fmul      f0, f2, f0
	  fmul      f0, f1, f0
	  frsp      f0, f0
	  stfs      f0, 0xC(r1)
	  lfs       f1, 0xC(r1)

	.loc_0x5C:
	  addi      r1, r1, 0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void cosf2(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000DCC0
 * Size:	000024
 */
void atanf2(f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x20DA1C
	  frsp      f1, f1
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void sinf2(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000DD00
 * Size:	000088
 */
void Jac_InitSinTable()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  addi      r11, r1, 0x38
	  bl        0x207150
	  stmw      r28, 0x10(r1)
	  lis       r3, 0x8031
	  lfs       f29, -0x7F48(r2)
	  lfd       f30, -0x7F40(r2)
	  subi      r30, r3, 0x2520
	  lfs       f31, -0x7F44(r2)
	  li        r28, 0
	  li        r31, 0
	  lis       r29, 0x4330

	.loc_0x38:
	  stw       r28, 0xC(r1)
	  stw       r29, 0x8(r1)
	  lfd       f0, 0x8(r1)
	  fsubs     f0, f0, f30
	  fmuls     f0, f29, f0
	  fmuls     f1, f0, f31
	  bl        0x20DF98
	  addi      r28, r28, 0x1
	  add       r3, r30, r31
	  cmplwi    r28, 0x101
	  stfs      f1, 0x0(r3)
	  addi      r31, r31, 0x4
	  blt+      .loc_0x38
	  lwz       r0, 0x3C(r1)
	  addi      r11, r1, 0x38
	  bl        0x207138
	  lmw       r28, 0x10(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000DDA0
 * Size:	000034
 */
void sinf3(f32)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  lis       r3, 0x8031
	  subi      r0, r3, 0x2520
	  lfs       f0, -0x7F38(r2)
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x10(r1)
	  lwz       r3, 0x14(r1)
	  rlwinm    r3,r3,2,0,29
	  add       r3, r0, r3
	  lfs       f1, 0x0(r3)
	  addi      r1, r1, 0x18
	  blr
	*/
}
