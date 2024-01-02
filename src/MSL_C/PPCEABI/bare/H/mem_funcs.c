#include "types.h"

/*
 * --INFO--
 * Address:	802162B8
 * Size:	0000B0
 */
void __copy_longs_rev_unaligned(void)
{
	/*
	.loc_0x0:
	  add       r12, r3, r5
	  rlwinm.   r0,r12,0,30,31
	  add       r11, r4, r5
	  mr        r3, r0
	  beq-      .loc_0x28
	  sub       r5, r5, r3

	.loc_0x18:
	  lbzu      r0, -0x1(r11)
	  subic.    r3, r3, 0x1
	  stbu      r0, -0x1(r12)
	  bne+      .loc_0x18

	.loc_0x28:
	  rlwinm    r4,r11,3,27,28
	  rlwinm    r9,r11,0,30,31
	  subfic    r10, r4, 0x20
	  subfic    r0, r9, 0x4
	  add       r11, r11, r0
	  lwzu      r7, -0x4(r11)
	  rlwinm    r6,r5,29,3,31

	.loc_0x44:
	  lwz       r8, -0x4(r11)
	  srw       r0, r7, r10
	  subic.    r6, r6, 0x1
	  slw       r3, r8, r4
	  or        r0, r3, r0
	  stw       r0, -0x4(r12)
	  srw       r0, r8, r10
	  lwzu      r7, -0x8(r11)
	  slw       r3, r7, r4
	  or        r0, r3, r0
	  stwu      r0, -0x8(r12)
	  bne+      .loc_0x44
	  rlwinm.   r0,r5,0,29,29
	  beq-      .loc_0x90
	  lwzu      r3, -0x4(r11)
	  srw       r0, r7, r10
	  slw       r3, r3, r4
	  or        r0, r3, r0
	  stwu      r0, -0x4(r12)

	.loc_0x90:
	  rlwinm.   r5,r5,0,30,31
	  beqlr-
	  add       r11, r11, r9

	.loc_0x9C:
	  lbzu      r0, -0x1(r11)
	  subic.    r5, r5, 0x1
	  stbu      r0, -0x1(r12)
	  bne+      .loc_0x9C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80216368
 * Size:	0000C4
 */
void __copy_longs_unaligned(void)
{
	/*
	.loc_0x0:
	  neg       r0, r3
	  rlwinm.   r6,r0,0,30,31
	  subi      r4, r4, 0x1
	  subi      r3, r3, 0x1
	  beq-      .loc_0x28
	  sub       r5, r5, r6

	.loc_0x18:
	  lbzu      r0, 0x1(r4)
	  subic.    r6, r6, 0x1
	  stbu      r0, 0x1(r3)
	  bne+      .loc_0x18

	.loc_0x28:
	  addi      r0, r4, 0x1
	  rlwinm    r11,r0,0,30,31
	  sub       r4, r4, r11
	  subi      r8, r4, 0x3
	  lwzu      r9, 0x4(r8)
	  rlwinm    r4,r0,3,27,28
	  subfic    r12, r4, 0x20
	  subi      r6, r3, 0x3
	  rlwinm    r7,r5,29,3,31

	.loc_0x4C:
	  lwz       r10, 0x4(r8)
	  slw       r3, r9, r4
	  subic.    r7, r7, 0x1
	  srw       r0, r10, r12
	  or        r0, r3, r0
	  stw       r0, 0x4(r6)
	  slw       r3, r10, r4
	  lwzu      r9, 0x8(r8)
	  srw       r0, r9, r12
	  or        r0, r3, r0
	  stwu      r0, 0x8(r6)
	  bne+      .loc_0x4C
	  rlwinm.   r0,r5,0,29,29
	  beq-      .loc_0x98
	  lwzu      r0, 0x4(r8)
	  slw       r3, r9, r4
	  srw       r0, r0, r12
	  or        r0, r3, r0
	  stwu      r0, 0x4(r6)

	.loc_0x98:
	  rlwinm.   r5,r5,0,30,31
	  addi      r4, r8, 0x3
	  addi      r3, r6, 0x3
	  beqlr-
	  subfic    r0, r11, 0x4
	  sub       r4, r4, r0

	.loc_0xB0:
	  lbzu      r0, 0x1(r4)
	  subic.    r5, r5, 0x1
	  stbu      r0, 0x1(r3)
	  bne+      .loc_0xB0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021642C
 * Size:	0000AC
 */
void __copy_longs_rev_aligned(void)
{
	/*
	.loc_0x0:
	  add       r6, r3, r5
	  rlwinm.   r0,r6,0,30,31
	  add       r4, r4, r5
	  mr        r3, r0
	  beq-      .loc_0x28
	  sub       r5, r5, r3

	.loc_0x18:
	  lbzu      r0, -0x1(r4)
	  subic.    r3, r3, 0x1
	  stbu      r0, -0x1(r6)
	  bne+      .loc_0x18

	.loc_0x28:
	  rlwinm.   r3,r5,27,5,31
	  beq-      .loc_0x78

	.loc_0x30:
	  lwz       r0, -0x4(r4)
	  subic.    r3, r3, 0x1
	  stw       r0, -0x4(r6)
	  lwz       r0, -0x8(r4)
	  stw       r0, -0x8(r6)
	  lwz       r0, -0xC(r4)
	  stw       r0, -0xC(r6)
	  lwz       r0, -0x10(r4)
	  stw       r0, -0x10(r6)
	  lwz       r0, -0x14(r4)
	  stw       r0, -0x14(r6)
	  lwz       r0, -0x18(r4)
	  stw       r0, -0x18(r6)
	  lwz       r0, -0x1C(r4)
	  stw       r0, -0x1C(r6)
	  lwzu      r0, -0x20(r4)
	  stwu      r0, -0x20(r6)
	  bne+      .loc_0x30

	.loc_0x78:
	  rlwinm.   r3,r5,30,29,31
	  beq-      .loc_0x90

	.loc_0x80:
	  lwzu      r0, -0x4(r4)
	  subic.    r3, r3, 0x1
	  stwu      r0, -0x4(r6)
	  bne+      .loc_0x80

	.loc_0x90:
	  rlwinm.   r5,r5,0,30,31
	  beqlr-

	.loc_0x98:
	  lbzu      r0, -0x1(r4)
	  subic.    r5, r5, 0x1
	  stbu      r0, -0x1(r6)
	  bne+      .loc_0x98
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802164D8
 * Size:	0000BC
 */
void __copy_longs_aligned(void)
{
	/*
	.loc_0x0:
	  neg       r0, r3
	  rlwinm.   r6,r0,0,30,31
	  subi      r7, r4, 0x1
	  subi      r3, r3, 0x1
	  beq-      .loc_0x28
	  sub       r5, r5, r6

	.loc_0x18:
	  lbzu      r0, 0x1(r7)
	  subic.    r6, r6, 0x1
	  stbu      r0, 0x1(r3)
	  bne+      .loc_0x18

	.loc_0x28:
	  rlwinm.   r4,r5,27,5,31
	  subi      r6, r7, 0x3
	  subi      r3, r3, 0x3
	  beq-      .loc_0x80

	.loc_0x38:
	  lwz       r0, 0x4(r6)
	  subic.    r4, r4, 0x1
	  stw       r0, 0x4(r3)
	  lwz       r0, 0x8(r6)
	  stw       r0, 0x8(r3)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x10(r6)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0x14(r6)
	  stw       r0, 0x14(r3)
	  lwz       r0, 0x18(r6)
	  stw       r0, 0x18(r3)
	  lwz       r0, 0x1C(r6)
	  stw       r0, 0x1C(r3)
	  lwzu      r0, 0x20(r6)
	  stwu      r0, 0x20(r3)
	  bne+      .loc_0x38

	.loc_0x80:
	  rlwinm.   r4,r5,30,29,31
	  beq-      .loc_0x98

	.loc_0x88:
	  lwzu      r0, 0x4(r6)
	  subic.    r4, r4, 0x1
	  stwu      r0, 0x4(r3)
	  bne+      .loc_0x88

	.loc_0x98:
	  rlwinm.   r5,r5,0,30,31
	  addi      r4, r6, 0x3
	  addi      r3, r3, 0x3
	  beqlr-

	.loc_0xA8:
	  lbzu      r0, 0x1(r4)
	  subic.    r5, r5, 0x1
	  stbu      r0, 0x1(r3)
	  bne+      .loc_0xA8
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B8
 */
void __move_mem(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void __copy_mem(void)
{
	// UNUSED FUNCTION
}
