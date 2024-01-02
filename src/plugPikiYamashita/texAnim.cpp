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
 * Address:	801C10A0
 * Size:	000024
 */
void zen::TexAnim::setData(u32, Texture*, f32)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x4(r3)
	  cmplw     r4, r0
	  bgelr-
	  lwz       r3, 0x8(r3)
	  rlwinm    r0,r4,3,0,28
	  add       r3, r3, r0
	  stw       r5, 0x0(r3)
	  stfs      f1, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C10C4
 * Size:	00007C
 */
void zen::TexAnim::update()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2DEC(r13)
	  li        r5, 0
	  lfs       f1, 0xC(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r3)
	  lwz       r0, 0x0(r3)
	  lwz       r4, 0x8(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r4, r4, r0
	  b         .loc_0x64

	.loc_0x2C:
	  lfs       f0, 0xC(r3)
	  fsubs     f0, f0, f1
	  stfs      f0, 0xC(r3)
	  lwz       r4, 0x0(r3)
	  addi      r4, r4, 0x1
	  stw       r4, 0x0(r3)
	  lwz       r0, 0x4(r3)
	  cmplw     r4, r0
	  blt-      .loc_0x54
	  stw       r5, 0x0(r3)

	.loc_0x54:
	  lwz       r0, 0x0(r3)
	  lwz       r4, 0x8(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r4, r4, r0

	.loc_0x64:
	  lfs       f0, 0xC(r3)
	  lfs       f1, 0x4(r4)
	  fcmpo     cr0, f0, f1
	  bgt+      .loc_0x2C
	  lwz       r3, 0x0(r4)
	  blr
	*/
}
