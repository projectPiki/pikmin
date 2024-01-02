#include "types.h"

/*
 * --INFO--
 * Address:	8021E7C0
 * Size:	0000C4
 */
void TRK_fill_mem(void)
{
	/*
	.loc_0x0:
	  cmplwi    r5, 0x20
	  subi      r6, r3, 0x1
	  rlwinm    r0,r4,0,24,31
	  mr        r7, r0
	  blt-      .loc_0xA8
	  not       r0, r6
	  rlwinm.   r0,r0,0,30,31
	  mr        r3, r0
	  beq-      .loc_0x38
	  sub       r5, r5, r3
	  rlwinm    r0,r7,0,24,31

	.loc_0x2C:
	  subic.    r3, r3, 0x1
	  stbu      r0, 0x1(r6)
	  bne+      .loc_0x2C

	.loc_0x38:
	  cmplwi    r7, 0
	  beq-      .loc_0x58
	  rlwinm    r3,r7,24,0,7
	  rlwinm    r0,r7,16,0,15
	  rlwinm    r4,r7,8,0,23
	  or        r0, r3, r0
	  or        r0, r4, r0
	  or        r7, r7, r0

	.loc_0x58:
	  rlwinm.   r0,r5,27,5,31
	  subi      r3, r6, 0x3
	  beq-      .loc_0x8C

	.loc_0x64:
	  stw       r7, 0x4(r3)
	  subic.    r0, r0, 0x1
	  stw       r7, 0x8(r3)
	  stw       r7, 0xC(r3)
	  stw       r7, 0x10(r3)
	  stw       r7, 0x14(r3)
	  stw       r7, 0x18(r3)
	  stw       r7, 0x1C(r3)
	  stwu      r7, 0x20(r3)
	  bne+      .loc_0x64

	.loc_0x8C:
	  rlwinm.   r0,r5,30,29,31
	  beq-      .loc_0xA0

	.loc_0x94:
	  subic.    r0, r0, 0x1
	  stwu      r7, 0x4(r3)
	  bne+      .loc_0x94

	.loc_0xA0:
	  addi      r6, r3, 0x3
	  rlwinm    r5,r5,0,30,31

	.loc_0xA8:
	  cmplwi    r5, 0
	  beqlr-
	  rlwinm    r0,r7,0,24,31

	.loc_0xB4:
	  subic.    r5, r5, 0x1
	  stbu      r0, 0x1(r6)
	  bne+      .loc_0xB4
	  blr
	*/
}
