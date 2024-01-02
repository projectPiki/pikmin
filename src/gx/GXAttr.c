#include "types.h"

/*
 * --INFO--
 * Address:	8020F2A8
 * Size:	000158
 */
void __GXXfVtxSpecs(void)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x2A68(r13)
	  lwz       r4, 0x14(r5)
	  rlwinm.   r0,r4,19,30,31
	  beq-      .loc_0x18
	  li        r3, 0x1
	  b         .loc_0x1C

	.loc_0x18:
	  li        r3, 0

	.loc_0x1C:
	  rlwinm.   r0,r4,17,30,31
	  beq-      .loc_0x2C
	  li        r4, 0x1
	  b         .loc_0x30

	.loc_0x2C:
	  li        r4, 0

	.loc_0x30:
	  lbz       r0, 0x41D(r5)
	  add       r7, r3, r4
	  cmplwi    r0, 0
	  beq-      .loc_0x48
	  li        r4, 0x2
	  b         .loc_0x60

	.loc_0x48:
	  lbz       r0, 0x41C(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C
	  li        r4, 0x1
	  b         .loc_0x60

	.loc_0x5C:
	  li        r4, 0

	.loc_0x60:
	  lwz       r6, 0x18(r5)
	  rlwinm.   r0,r6,0,30,31
	  beq-      .loc_0x74
	  li        r3, 0x1
	  b         .loc_0x78

	.loc_0x74:
	  li        r3, 0

	.loc_0x78:
	  rlwinm.   r0,r6,30,30,31
	  beq-      .loc_0x88
	  li        r5, 0x1
	  b         .loc_0x8C

	.loc_0x88:
	  li        r5, 0

	.loc_0x8C:
	  rlwinm.   r0,r6,28,30,31
	  add       r8, r3, r5
	  beq-      .loc_0xA0
	  li        r3, 0x1
	  b         .loc_0xA4

	.loc_0xA0:
	  li        r3, 0

	.loc_0xA4:
	  rlwinm.   r0,r6,26,30,31
	  add       r8, r8, r3
	  beq-      .loc_0xB8
	  li        r3, 0x1
	  b         .loc_0xBC

	.loc_0xB8:
	  li        r3, 0

	.loc_0xBC:
	  rlwinm.   r0,r6,24,30,31
	  add       r8, r8, r3
	  beq-      .loc_0xD0
	  li        r3, 0x1
	  b         .loc_0xD4

	.loc_0xD0:
	  li        r3, 0

	.loc_0xD4:
	  rlwinm.   r0,r6,22,30,31
	  add       r8, r8, r3
	  beq-      .loc_0xE8
	  li        r3, 0x1
	  b         .loc_0xEC

	.loc_0xE8:
	  li        r3, 0

	.loc_0xEC:
	  rlwinm.   r0,r6,20,30,31
	  add       r8, r8, r3
	  beq-      .loc_0x100
	  li        r3, 0x1
	  b         .loc_0x104

	.loc_0x100:
	  li        r3, 0

	.loc_0x104:
	  rlwinm.   r0,r6,18,30,31
	  add       r8, r8, r3
	  beq-      .loc_0x118
	  li        r6, 0x1
	  b         .loc_0x11C

	.loc_0x118:
	  li        r6, 0

	.loc_0x11C:
	  li        r0, 0x10
	  lwz       r3, 0x2A68(r13)
	  lis       r5, 0xCC01
	  add       r8, r8, r6
	  stb       r0, -0x8000(r5)
	  rlwinm    r0,r4,2,0,29
	  li        r4, 0x1008
	  stw       r4, -0x8000(r5)
	  rlwinm    r4,r8,4,0,27
	  or        r0, r7, r0
	  or        r0, r4, r0
	  stw       r0, -0x8000(r5)
	  li        r0, 0
	  sth       r0, 0x2(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020F400
 * Size:	000338
 */
void GXSetVtxDesc(void)
{
	/*
	.loc_0x0:
	  cmplwi    r3, 0x19
	  bgt-      .loc_0x2DC
	  lis       r5, 0x802F
	  subi      r5, r5, 0x7400
	  rlwinm    r0,r3,2,0,29
	  lwzx      r0, r5, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0x2A68(r13)
	  lwzu      r0, 0x14(r3)
	  rlwinm    r0,r0,0,0,30
	  or        r0, r0, r4
	  stw       r0, 0x0(r3)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,1,0,30
	  addi      r4, r3, 0x14
	  lwz       r3, 0x14(r3)
	  rlwinm    r3,r3,0,31,29
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,2,0,29
	  addi      r4, r3, 0x14
	  lwz       r3, 0x14(r3)
	  rlwinm    r3,r3,0,30,28
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,3,0,28
	  addi      r4, r3, 0x14
	  lwz       r3, 0x14(r3)
	  rlwinm    r3,r3,0,29,27
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,4,0,27
	  addi      r4, r3, 0x14
	  lwz       r3, 0x14(r3)
	  rlwinm    r3,r3,0,28,26
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,5,0,26
	  addi      r4, r3, 0x14
	  lwz       r3, 0x14(r3)
	  rlwinm    r3,r3,0,27,25
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,6,0,25
	  addi      r4, r3, 0x14
	  lwz       r3, 0x14(r3)
	  rlwinm    r3,r3,0,26,24
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,7,0,24
	  addi      r4, r3, 0x14
	  lwz       r3, 0x14(r3)
	  rlwinm    r3,r3,0,25,23
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,8,0,23
	  addi      r4, r3, 0x14
	  lwz       r3, 0x14(r3)
	  rlwinm    r3,r3,0,24,22
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,9,0,22
	  addi      r4, r3, 0x14
	  lwz       r3, 0x14(r3)
	  rlwinm    r3,r3,0,23,20
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  neg       r5, r4
	  lwz       r3, 0x2A68(r13)
	  subic     r0, r5, 0x1
	  subfe     r0, r0, r5
	  cmpwi     r4, 0
	  stb       r0, 0x41C(r3)
	  beq-      .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  stw       r4, 0x418(r3)
	  b         .loc_0x2DC
	  neg       r5, r4
	  lwz       r3, 0x2A68(r13)
	  subic     r0, r5, 0x1
	  subfe     r0, r0, r5
	  cmpwi     r4, 0
	  stb       r0, 0x41D(r3)
	  beq-      .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  stw       r4, 0x418(r3)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,13,0,18
	  addi      r4, r3, 0x14
	  lwz       r3, 0x14(r3)
	  rlwinm    r3,r3,0,19,16
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,15,0,16
	  addi      r4, r3, 0x14
	  lwz       r3, 0x14(r3)
	  rlwinm    r3,r3,0,17,14
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  lwzu      r0, 0x18(r3)
	  rlwinm    r0,r0,0,0,29
	  or        r0, r0, r4
	  stw       r0, 0x0(r3)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,2,0,29
	  addi      r4, r3, 0x18
	  lwz       r3, 0x18(r3)
	  rlwinm    r3,r3,0,30,27
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,4,0,27
	  addi      r4, r3, 0x18
	  lwz       r3, 0x18(r3)
	  rlwinm    r3,r3,0,28,25
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,6,0,25
	  addi      r4, r3, 0x18
	  lwz       r3, 0x18(r3)
	  rlwinm    r3,r3,0,26,23
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,8,0,23
	  addi      r4, r3, 0x18
	  lwz       r3, 0x18(r3)
	  rlwinm    r3,r3,0,24,21
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,10,0,21
	  addi      r4, r3, 0x18
	  lwz       r3, 0x18(r3)
	  rlwinm    r3,r3,0,22,19
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,12,0,19
	  addi      r4, r3, 0x18
	  lwz       r3, 0x18(r3)
	  rlwinm    r3,r3,0,20,17
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x2DC
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r4,14,0,17
	  addi      r4, r3, 0x18
	  lwz       r3, 0x18(r3)
	  rlwinm    r3,r3,0,18,15
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)

	.loc_0x2DC:
	  lwz       r3, 0x2A68(r13)
	  lbz       r0, 0x41C(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x2F8
	  lbz       r0, 0x41D(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x318

	.loc_0x2F8:
	  addi      r4, r3, 0x14
	  lwz       r0, 0x418(r3)
	  lwz       r3, 0x14(r3)
	  rlwinm    r0,r0,11,0,20
	  rlwinm    r3,r3,0,21,18
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x324

	.loc_0x318:
	  lwzu      r0, 0x14(r3)
	  rlwinm    r0,r0,0,21,18
	  stw       r0, 0x0(r3)

	.loc_0x324:
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x4F0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020F738
 * Size:	00035C
 */
void GXSetVtxDescv(void)
{
	/*
	.loc_0x0:
	  lis       r4, 0x802F
	  subi      r4, r4, 0x7398
	  b         .loc_0x2F4

	.loc_0xC:
	  lwz       r5, 0x0(r3)
	  lwz       r0, 0x4(r3)
	  cmplwi    r5, 0x19
	  bgt-      .loc_0x2F0
	  rlwinm    r5,r5,2,0,29
	  lwzx      r5, r4, r5
	  mtctr     r5
	  bctr
	  lwz       r5, 0x2A68(r13)
	  addi      r6, r5, 0x14
	  lwz       r5, 0x14(r5)
	  rlwinm    r5,r5,0,0,30
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,1,0,30
	  addi      r6, r5, 0x14
	  lwz       r5, 0x14(r5)
	  rlwinm    r5,r5,0,31,29
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,2,0,29
	  addi      r6, r5, 0x14
	  lwz       r5, 0x14(r5)
	  rlwinm    r5,r5,0,30,28
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,3,0,28
	  addi      r6, r5, 0x14
	  lwz       r5, 0x14(r5)
	  rlwinm    r5,r5,0,29,27
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,4,0,27
	  addi      r6, r5, 0x14
	  lwz       r5, 0x14(r5)
	  rlwinm    r5,r5,0,28,26
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,5,0,26
	  addi      r6, r5, 0x14
	  lwz       r5, 0x14(r5)
	  rlwinm    r5,r5,0,27,25
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,6,0,25
	  addi      r6, r5, 0x14
	  lwz       r5, 0x14(r5)
	  rlwinm    r5,r5,0,26,24
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,7,0,24
	  addi      r6, r5, 0x14
	  lwz       r5, 0x14(r5)
	  rlwinm    r5,r5,0,25,23
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,8,0,23
	  addi      r6, r5, 0x14
	  lwz       r5, 0x14(r5)
	  rlwinm    r5,r5,0,24,22
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,9,0,22
	  addi      r6, r5, 0x14
	  lwz       r5, 0x14(r5)
	  rlwinm    r5,r5,0,23,20
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  neg       r7, r0
	  lwz       r5, 0x2A68(r13)
	  subic     r6, r7, 0x1
	  subfe     r6, r6, r7
	  cmpwi     r0, 0
	  stb       r6, 0x41C(r5)
	  beq-      .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  stw       r0, 0x418(r5)
	  b         .loc_0x2F0
	  neg       r7, r0
	  lwz       r5, 0x2A68(r13)
	  subic     r6, r7, 0x1
	  subfe     r6, r6, r7
	  cmpwi     r0, 0
	  stb       r6, 0x41D(r5)
	  beq-      .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  stw       r0, 0x418(r5)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,13,0,18
	  addi      r6, r5, 0x14
	  lwz       r5, 0x14(r5)
	  rlwinm    r5,r5,0,19,16
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,15,0,16
	  addi      r6, r5, 0x14
	  lwz       r5, 0x14(r5)
	  rlwinm    r5,r5,0,17,14
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  addi      r6, r5, 0x18
	  lwz       r5, 0x18(r5)
	  rlwinm    r5,r5,0,0,29
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,2,0,29
	  addi      r6, r5, 0x18
	  lwz       r5, 0x18(r5)
	  rlwinm    r5,r5,0,30,27
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,4,0,27
	  addi      r6, r5, 0x18
	  lwz       r5, 0x18(r5)
	  rlwinm    r5,r5,0,28,25
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,6,0,25
	  addi      r6, r5, 0x18
	  lwz       r5, 0x18(r5)
	  rlwinm    r5,r5,0,26,23
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,8,0,23
	  addi      r6, r5, 0x18
	  lwz       r5, 0x18(r5)
	  rlwinm    r5,r5,0,24,21
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,10,0,21
	  addi      r6, r5, 0x18
	  lwz       r5, 0x18(r5)
	  rlwinm    r5,r5,0,22,19
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,12,0,19
	  addi      r6, r5, 0x18
	  lwz       r5, 0x18(r5)
	  rlwinm    r5,r5,0,20,17
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)
	  b         .loc_0x2F0
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r0,14,0,17
	  addi      r6, r5, 0x18
	  lwz       r5, 0x18(r5)
	  rlwinm    r5,r5,0,18,15
	  or        r0, r5, r0
	  stw       r0, 0x0(r6)

	.loc_0x2F0:
	  addi      r3, r3, 0x8

	.loc_0x2F4:
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0xFF
	  bne+      .loc_0xC
	  lwz       r3, 0x2A68(r13)
	  lbz       r0, 0x41C(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x31C
	  lbz       r0, 0x41D(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x33C

	.loc_0x31C:
	  addi      r4, r3, 0x14
	  lwz       r0, 0x418(r3)
	  lwz       r3, 0x14(r3)
	  rlwinm    r0,r0,11,0,20
	  rlwinm    r3,r3,0,21,18
	  or        r0, r3, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x348

	.loc_0x33C:
	  lwzu      r0, 0x14(r3)
	  rlwinm    r0,r0,0,21,18
	  stw       r0, 0x0(r3)

	.loc_0x348:
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x4F0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020FA94
 * Size:	000168
 */
void __GXSetVCD(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0x8
	  stw       r0, 0x4(r1)
	  lis       r5, 0xCC01
	  li        r3, 0x50
	  stwu      r1, -0x20(r1)
	  li        r0, 0x60
	  stw       r31, 0x1C(r1)
	  stb       r6, -0x8000(r5)
	  lwz       r4, 0x2A68(r13)
	  stb       r3, -0x8000(r5)
	  lwz       r3, 0x14(r4)
	  stw       r3, -0x8000(r5)
	  stb       r6, -0x8000(r5)
	  stb       r0, -0x8000(r5)
	  lwz       r0, 0x18(r4)
	  stw       r0, -0x8000(r5)
	  bl        -0x830
	  lwz       r3, 0x2A68(r13)
	  lhz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x154
	  lwz       r31, 0x14(r3)
	  addi      r9, r13, 0x2A78
	  lwz       r4, 0x18(r3)
	  addi      r7, r13, 0x2A70
	  rlwinm    r0,r31,0,31,31
	  rlwinm    r11,r31,31,31,31
	  lbz       r5, 0x41D(r3)
	  rlwinm    r6,r31,21,30,31
	  rlwinm    r5,r5,1,0,30
	  lbzx      r10, r9, r6
	  addi      r8, r5, 0x1
	  add       r0, r0, r11
	  rlwinm    r12,r31,30,31,31
	  rlwinm    r5,r31,23,30,31
	  rlwinm    r6,r31,19,30,31
	  lbzx      r11, r9, r5
	  rlwinm    r5,r31,17,30,31
	  lbzx      r6, r7, r6
	  add       r0, r0, r12
	  lbzx      r9, r7, r5
	  rlwinm    r5,r31,29,31,31
	  add       r0, r0, r5
	  rlwinm    r5,r31,28,31,31
	  add       r0, r0, r5
	  rlwinm    r5,r31,27,31,31
	  add       r0, r0, r5
	  rlwinm    r7,r31,26,31,31
	  mullw     r5, r10, r8
	  add       r0, r0, r7
	  rlwinm    r7,r31,25,31,31
	  add       r0, r0, r7
	  rlwinm    r7,r31,24,31,31
	  add       r0, r0, r7
	  add       r0, r0, r11
	  add       r0, r0, r5
	  add       r0, r0, r6
	  rlwinm    r6,r4,0,30,31
	  addi      r8, r13, 0x2A74
	  rlwinm    r5,r4,30,30,31
	  lbzx      r7, r8, r6
	  add       r0, r0, r9
	  lbzx      r6, r8, r5
	  rlwinm    r5,r4,28,30,31
	  add       r0, r0, r7
	  lbzx      r7, r8, r5
	  rlwinm    r5,r4,26,30,31
	  add       r0, r0, r6
	  lbzx      r6, r8, r5
	  rlwinm    r5,r4,24,30,31
	  add       r0, r0, r7
	  lbzx      r7, r8, r5
	  rlwinm    r5,r4,22,30,31
	  add       r0, r0, r6
	  lbzx      r6, r8, r5
	  rlwinm    r5,r4,20,30,31
	  add       r0, r0, r7
	  lbzx      r5, r8, r5
	  rlwinm    r4,r4,18,30,31
	  add       r0, r0, r6
	  lbzx      r4, r8, r4
	  add       r0, r0, r5
	  add       r0, r0, r4
	  stw       r0, 0x4(r3)

	.loc_0x154:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001B4
 */
void GXGetVtxDesc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void GXGetVtxDescv(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020FBFC
 * Size:	00004C
 */
void GXClearVtxDesc(void)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2A68(r13)
	  li        r4, 0
	  stw       r4, 0x14(r3)
	  lwz       r3, 0x2A68(r13)
	  lwzu      r0, 0x14(r3)
	  rlwinm    r0,r0,0,23,20
	  ori       r0, r0, 0x200
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x2A68(r13)
	  stw       r4, 0x18(r3)
	  lwz       r3, 0x2A68(r13)
	  stb       r4, 0x41C(r3)
	  lwz       r3, 0x2A68(r13)
	  stb       r4, 0x41D(r3)
	  lwz       r3, 0x2A68(r13)
	  lwz       r0, 0x4F0(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x4F0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020FC48
 * Size:	00035C
 */
void GXSetVtxAttrFmt(void)
{
	/*
	.loc_0x0:
	  subi      r0, r4, 0x9
	  lwz       r8, 0x2A68(r13)
	  rlwinm    r4,r3,2,0,29
	  add       r9, r8, r4
	  cmplwi    r0, 0x10
	  addi      r4, r9, 0x1C
	  addi      r8, r9, 0x3C
	  addi      r9, r9, 0x5C
	  bgt-      .loc_0x328
	  lis       r10, 0x802F
	  subi      r10, r10, 0x7330
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r10, r0
	  mtctr     r0
	  bctr
	  lwz       r0, 0x0(r4)
	  rlwinm    r6,r6,1,0,30
	  rlwinm    r0,r0,0,0,30
	  or        r0, r0, r5
	  stw       r0, 0x0(r4)
	  rlwinm    r0,r7,4,20,27
	  lwz       r5, 0x0(r4)
	  rlwinm    r5,r5,0,31,27
	  or        r5, r5, r6
	  stw       r5, 0x0(r4)
	  lwz       r5, 0x0(r4)
	  rlwinm    r5,r5,0,28,22
	  or        r0, r5, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x328
	  lwz       r7, 0x0(r4)
	  rlwinm    r0,r6,10,0,21
	  cmpwi     r5, 0x2
	  rlwinm    r6,r7,0,22,18
	  or        r0, r6, r0
	  stw       r0, 0x0(r4)
	  bne-      .loc_0xB8
	  lwz       r0, 0x0(r4)
	  rlwinm    r0,r0,0,23,21
	  ori       r0, r0, 0x200
	  stw       r0, 0x0(r4)
	  lwz       r0, 0x0(r4)
	  rlwinm    r0,r0,0,1,31
	  oris      r0, r0, 0x8000
	  stw       r0, 0x0(r4)
	  b         .loc_0x328

	.loc_0xB8:
	  lwz       r6, 0x0(r4)
	  rlwinm    r0,r5,9,0,22
	  rlwinm    r5,r6,0,23,21
	  or        r0, r5, r0
	  stw       r0, 0x0(r4)
	  lwz       r0, 0x0(r4)
	  rlwinm    r0,r0,0,1,31
	  stw       r0, 0x0(r4)
	  b         .loc_0x328
	  lwz       r7, 0x0(r4)
	  rlwinm    r5,r5,13,0,18
	  rlwinm    r0,r6,14,0,17
	  rlwinm    r6,r7,0,19,17
	  or        r5, r6, r5
	  stw       r5, 0x0(r4)
	  lwz       r5, 0x0(r4)
	  rlwinm    r5,r5,0,18,14
	  or        r0, r5, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x328
	  lwz       r7, 0x0(r4)
	  rlwinm    r5,r5,17,0,14
	  rlwinm    r0,r6,18,0,13
	  rlwinm    r6,r7,0,15,13
	  or        r5, r6, r5
	  stw       r5, 0x0(r4)
	  lwz       r5, 0x0(r4)
	  rlwinm    r5,r5,0,14,10
	  or        r0, r5, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x328
	  lwz       r8, 0x0(r4)
	  rlwinm    r0,r5,21,0,10
	  rlwinm    r5,r8,0,11,9
	  or        r0, r5, r0
	  stw       r0, 0x0(r4)
	  rlwinm    r5,r6,22,0,9
	  rlwinm    r0,r7,25,0,6
	  lwz       r6, 0x0(r4)
	  rlwinm    r6,r6,0,10,6
	  or        r5, r6, r5
	  stw       r5, 0x0(r4)
	  lwz       r5, 0x0(r4)
	  rlwinm    r5,r5,0,7,1
	  or        r0, r5, r0
	  stw       r0, 0x0(r4)
	  b         .loc_0x328
	  lwz       r0, 0x0(r8)
	  rlwinm    r4,r6,1,0,30
	  rlwinm    r0,r0,0,0,30
	  or        r0, r0, r5
	  stw       r0, 0x0(r8)
	  rlwinm    r0,r7,4,20,27
	  lwz       r5, 0x0(r8)
	  rlwinm    r5,r5,0,31,27
	  or        r4, r5, r4
	  stw       r4, 0x0(r8)
	  lwz       r4, 0x0(r8)
	  rlwinm    r4,r4,0,28,22
	  or        r0, r4, r0
	  stw       r0, 0x0(r8)
	  b         .loc_0x328
	  lwz       r4, 0x0(r8)
	  rlwinm    r0,r5,9,0,22
	  rlwinm    r4,r4,0,23,21
	  or        r0, r4, r0
	  stw       r0, 0x0(r8)
	  rlwinm    r4,r6,10,0,21
	  rlwinm    r0,r7,13,11,18
	  lwz       r5, 0x0(r8)
	  rlwinm    r5,r5,0,22,18
	  or        r4, r5, r4
	  stw       r4, 0x0(r8)
	  lwz       r4, 0x0(r8)
	  rlwinm    r4,r4,0,19,13
	  or        r0, r4, r0
	  stw       r0, 0x0(r8)
	  b         .loc_0x328
	  lwz       r4, 0x0(r8)
	  rlwinm    r0,r5,18,0,13
	  rlwinm    r4,r4,0,14,12
	  or        r0, r4, r0
	  stw       r0, 0x0(r8)
	  rlwinm    r4,r6,19,0,12
	  rlwinm    r0,r7,22,2,9
	  lwz       r5, 0x0(r8)
	  rlwinm    r5,r5,0,13,9
	  or        r4, r5, r4
	  stw       r4, 0x0(r8)
	  lwz       r4, 0x0(r8)
	  rlwinm    r4,r4,0,10,4
	  or        r0, r4, r0
	  stw       r0, 0x0(r8)
	  b         .loc_0x328
	  lwz       r10, 0x0(r8)
	  rlwinm    r0,r5,27,0,4
	  rlwinm    r4,r6,28,0,3
	  rlwinm    r5,r10,0,5,3
	  or        r0, r5, r0
	  stw       r0, 0x0(r8)
	  rlwinm    r0,r7,0,24,31
	  lwz       r5, 0x0(r8)
	  rlwinm    r5,r5,0,4,0
	  or        r4, r5, r4
	  stw       r4, 0x0(r8)
	  lwz       r4, 0x0(r9)
	  rlwinm    r4,r4,0,0,26
	  or        r0, r4, r0
	  stw       r0, 0x0(r9)
	  b         .loc_0x328
	  lwz       r4, 0x0(r9)
	  rlwinm    r0,r5,5,0,26
	  rlwinm    r4,r4,0,27,25
	  or        r0, r4, r0
	  stw       r0, 0x0(r9)
	  rlwinm    r4,r6,6,0,25
	  rlwinm    r0,r7,9,15,22
	  lwz       r5, 0x0(r9)
	  rlwinm    r5,r5,0,26,22
	  or        r4, r5, r4
	  stw       r4, 0x0(r9)
	  lwz       r4, 0x0(r9)
	  rlwinm    r4,r4,0,23,17
	  or        r0, r4, r0
	  stw       r0, 0x0(r9)
	  b         .loc_0x328
	  lwz       r4, 0x0(r9)
	  rlwinm    r0,r5,14,0,17
	  rlwinm    r4,r4,0,18,16
	  or        r0, r4, r0
	  stw       r0, 0x0(r9)
	  rlwinm    r4,r6,15,0,16
	  rlwinm    r0,r7,18,6,13
	  lwz       r5, 0x0(r9)
	  rlwinm    r5,r5,0,17,13
	  or        r4, r5, r4
	  stw       r4, 0x0(r9)
	  lwz       r4, 0x0(r9)
	  rlwinm    r4,r4,0,14,8
	  or        r0, r4, r0
	  stw       r0, 0x0(r9)
	  b         .loc_0x328
	  lwz       r4, 0x0(r9)
	  rlwinm    r0,r5,23,0,8
	  rlwinm    r4,r4,0,9,7
	  or        r0, r4, r0
	  stw       r0, 0x0(r9)
	  rlwinm    r0,r6,24,0,7
	  lwz       r4, 0x0(r9)
	  rlwinm    r4,r4,0,8,4
	  or        r0, r4, r0
	  stw       r0, 0x0(r9)
	  lwz       r0, 0x0(r9)
	  rlwinm    r0,r0,0,5,31
	  rlwimi    r0,r7,27,0,4
	  stw       r0, 0x0(r9)

	.loc_0x328:
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r3,0,24,31
	  li        r3, 0x1
	  lwz       r4, 0x4F0(r5)
	  slw       r0, r3, r0
	  rlwinm    r0,r0,0,24,31
	  ori       r3, r4, 0x10
	  stw       r3, 0x4F0(r5)
	  lwz       r4, 0x2A68(r13)
	  lbz       r3, 0x4EE(r4)
	  or        r0, r3, r0
	  stb       r0, 0x4EE(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020FFA4
 * Size:	00037C
 */
void GXSetVtxAttrFmtv(void)
{
	/*
	.loc_0x0:
	  lwz       r6, 0x2A68(r13)
	  rlwinm    r0,r3,2,0,29
	  lis       r5, 0x802F
	  add       r6, r6, r0
	  addi      r8, r6, 0x1C
	  addi      r9, r6, 0x3C
	  addi      r10, r6, 0x5C
	  subi      r5, r5, 0x72EC
	  b         .loc_0x33C

	.loc_0x24:
	  lwz       r6, 0x0(r4)
	  lbz       r7, 0xC(r4)
	  subi      r11, r6, 0x9
	  lwz       r6, 0x8(r4)
	  cmplwi    r11, 0x10
	  lwz       r0, 0x4(r4)
	  bgt-      .loc_0x338
	  rlwinm    r11,r11,2,0,29
	  lwzx      r11, r5, r11
	  mtctr     r11
	  bctr
	  lwz       r12, 0x0(r8)
	  rlwinm    r11,r6,1,0,30
	  rlwinm    r6,r7,4,0,27
	  rlwinm    r7,r12,0,0,30
	  or        r0, r7, r0
	  stw       r0, 0x0(r8)
	  lwz       r0, 0x0(r8)
	  rlwinm    r0,r0,0,31,27
	  or        r0, r0, r11
	  stw       r0, 0x0(r8)
	  lwz       r0, 0x0(r8)
	  rlwinm    r0,r0,0,28,22
	  or        r0, r0, r6
	  stw       r0, 0x0(r8)
	  b         .loc_0x338
	  lwz       r7, 0x0(r8)
	  rlwinm    r6,r6,10,0,21
	  cmpwi     r0, 0x2
	  rlwinm    r7,r7,0,22,18
	  or        r6, r7, r6
	  stw       r6, 0x0(r8)
	  bne-      .loc_0xCC
	  lwz       r0, 0x0(r8)
	  rlwinm    r0,r0,0,23,21
	  ori       r0, r0, 0x200
	  stw       r0, 0x0(r8)
	  lwz       r0, 0x0(r8)
	  rlwinm    r0,r0,0,1,31
	  oris      r0, r0, 0x8000
	  stw       r0, 0x0(r8)
	  b         .loc_0x338

	.loc_0xCC:
	  lwz       r6, 0x0(r8)
	  rlwinm    r0,r0,9,0,22
	  rlwinm    r6,r6,0,23,21
	  or        r0, r6, r0
	  stw       r0, 0x0(r8)
	  lwz       r0, 0x0(r8)
	  rlwinm    r0,r0,0,1,31
	  stw       r0, 0x0(r8)
	  b         .loc_0x338
	  lwz       r11, 0x0(r8)
	  rlwinm    r7,r0,13,0,18
	  rlwinm    r0,r6,14,0,17
	  rlwinm    r6,r11,0,19,17
	  or        r6, r6, r7
	  stw       r6, 0x0(r8)
	  lwz       r6, 0x0(r8)
	  rlwinm    r6,r6,0,18,14
	  or        r0, r6, r0
	  stw       r0, 0x0(r8)
	  b         .loc_0x338
	  lwz       r11, 0x0(r8)
	  rlwinm    r7,r0,17,0,14
	  rlwinm    r0,r6,18,0,13
	  rlwinm    r6,r11,0,15,13
	  or        r6, r6, r7
	  stw       r6, 0x0(r8)
	  lwz       r6, 0x0(r8)
	  rlwinm    r6,r6,0,14,10
	  or        r0, r6, r0
	  stw       r0, 0x0(r8)
	  b         .loc_0x338
	  lwz       r11, 0x0(r8)
	  rlwinm    r0,r0,21,0,10
	  rlwinm    r6,r6,22,0,9
	  rlwinm    r11,r11,0,11,9
	  or        r0, r11, r0
	  stw       r0, 0x0(r8)
	  rlwinm    r0,r7,25,0,6
	  lwz       r7, 0x0(r8)
	  rlwinm    r7,r7,0,10,6
	  or        r6, r7, r6
	  stw       r6, 0x0(r8)
	  lwz       r6, 0x0(r8)
	  rlwinm    r6,r6,0,7,1
	  or        r0, r6, r0
	  stw       r0, 0x0(r8)
	  b         .loc_0x338
	  lwz       r12, 0x0(r9)
	  rlwinm    r11,r6,1,0,30
	  rlwinm    r6,r7,4,0,27
	  rlwinm    r7,r12,0,0,30
	  or        r0, r7, r0
	  stw       r0, 0x0(r9)
	  lwz       r0, 0x0(r9)
	  rlwinm    r0,r0,0,31,27
	  or        r0, r0, r11
	  stw       r0, 0x0(r9)
	  lwz       r0, 0x0(r9)
	  rlwinm    r0,r0,0,28,22
	  or        r0, r0, r6
	  stw       r0, 0x0(r9)
	  b         .loc_0x338
	  lwz       r11, 0x0(r9)
	  rlwinm    r0,r0,9,0,22
	  rlwinm    r6,r6,10,0,21
	  rlwinm    r11,r11,0,23,21
	  or        r0, r11, r0
	  stw       r0, 0x0(r9)
	  rlwinm    r0,r7,13,0,18
	  lwz       r7, 0x0(r9)
	  rlwinm    r7,r7,0,22,18
	  or        r6, r7, r6
	  stw       r6, 0x0(r9)
	  lwz       r6, 0x0(r9)
	  rlwinm    r6,r6,0,19,13
	  or        r0, r6, r0
	  stw       r0, 0x0(r9)
	  b         .loc_0x338
	  lwz       r11, 0x0(r9)
	  rlwinm    r0,r0,18,0,13
	  rlwinm    r6,r6,19,0,12
	  rlwinm    r11,r11,0,14,12
	  or        r0, r11, r0
	  stw       r0, 0x0(r9)
	  rlwinm    r0,r7,22,0,9
	  lwz       r7, 0x0(r9)
	  rlwinm    r7,r7,0,13,9
	  or        r6, r7, r6
	  stw       r6, 0x0(r9)
	  lwz       r6, 0x0(r9)
	  rlwinm    r6,r6,0,10,4
	  or        r0, r6, r0
	  stw       r0, 0x0(r9)
	  b         .loc_0x338
	  lwz       r12, 0x0(r9)
	  rlwinm    r11,r0,27,0,4
	  rlwinm    r0,r6,28,0,3
	  rlwinm    r6,r12,0,5,3
	  or        r6, r6, r11
	  stw       r6, 0x0(r9)
	  lwz       r6, 0x0(r9)
	  rlwinm    r6,r6,0,4,0
	  or        r0, r6, r0
	  stw       r0, 0x0(r9)
	  lwz       r0, 0x0(r10)
	  rlwinm    r0,r0,0,0,26
	  or        r0, r0, r7
	  stw       r0, 0x0(r10)
	  b         .loc_0x338
	  lwz       r11, 0x0(r10)
	  rlwinm    r0,r0,5,0,26
	  rlwinm    r6,r6,6,0,25
	  rlwinm    r11,r11,0,27,25
	  or        r0, r11, r0
	  stw       r0, 0x0(r10)
	  rlwinm    r0,r7,9,0,22
	  lwz       r7, 0x0(r10)
	  rlwinm    r7,r7,0,26,22
	  or        r6, r7, r6
	  stw       r6, 0x0(r10)
	  lwz       r6, 0x0(r10)
	  rlwinm    r6,r6,0,23,17
	  or        r0, r6, r0
	  stw       r0, 0x0(r10)
	  b         .loc_0x338
	  lwz       r11, 0x0(r10)
	  rlwinm    r0,r0,14,0,17
	  rlwinm    r6,r6,15,0,16
	  rlwinm    r11,r11,0,18,16
	  or        r0, r11, r0
	  stw       r0, 0x0(r10)
	  rlwinm    r0,r7,18,0,13
	  lwz       r7, 0x0(r10)
	  rlwinm    r7,r7,0,17,13
	  or        r6, r7, r6
	  stw       r6, 0x0(r10)
	  lwz       r6, 0x0(r10)
	  rlwinm    r6,r6,0,14,8
	  or        r0, r6, r0
	  stw       r0, 0x0(r10)
	  b         .loc_0x338
	  lwz       r12, 0x0(r10)
	  rlwinm    r11,r0,23,0,8
	  rlwinm    r0,r6,24,0,7
	  rlwinm    r6,r12,0,9,7
	  or        r6, r6, r11
	  stw       r6, 0x0(r10)
	  lwz       r6, 0x0(r10)
	  rlwinm    r6,r6,0,8,4
	  or        r0, r6, r0
	  stw       r0, 0x0(r10)
	  lwz       r0, 0x0(r10)
	  rlwinm    r0,r0,0,5,31
	  rlwimi    r0,r7,27,0,4
	  stw       r0, 0x0(r10)

	.loc_0x338:
	  addi      r4, r4, 0x10

	.loc_0x33C:
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0xFF
	  bne+      .loc_0x24
	  lwz       r5, 0x2A68(r13)
	  rlwinm    r0,r3,0,24,31
	  li        r3, 0x1
	  lwz       r4, 0x4F0(r5)
	  slw       r0, r3, r0
	  rlwinm    r0,r0,0,24,31
	  ori       r3, r4, 0x10
	  stw       r3, 0x4F0(r5)
	  lwz       r4, 0x2A68(r13)
	  lbz       r3, 0x4EE(r4)
	  or        r0, r3, r0
	  stb       r0, 0x4EE(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80210320
 * Size:	00009C
 */
void __GXSetVAT(void)
{
	/*
	.loc_0x0:
	  lwz       r10, 0x2A68(r13)
	  li        r12, 0
	  li        r11, 0
	  lis       r7, 0xCC01
	  b         .loc_0x80

	.loc_0x14:
	  rlwinm    r9,r12,0,24,31
	  lbz       r3, 0x4EE(r10)
	  li        r0, 0x1
	  slw       r0, r0, r9
	  and.      r0, r3, r0
	  beq-      .loc_0x78
	  li        r8, 0x8
	  stb       r8, -0x8000(r7)
	  ori       r3, r9, 0x70
	  addi      r0, r11, 0x1C
	  stb       r3, -0x8000(r7)
	  ori       r5, r9, 0x80
	  addi      r4, r11, 0x3C
	  lwzx      r6, r10, r0
	  ori       r3, r9, 0x90
	  addi      r0, r11, 0x5C
	  stw       r6, -0x8000(r7)
	  stb       r8, -0x8000(r7)
	  stb       r5, -0x8000(r7)
	  lwzx      r4, r10, r4
	  stw       r4, -0x8000(r7)
	  stb       r8, -0x8000(r7)
	  stb       r3, -0x8000(r7)
	  lwzx      r0, r10, r0
	  stw       r0, -0x8000(r7)

	.loc_0x78:
	  addi      r11, r11, 0x4
	  addi      r12, r12, 0x1

	.loc_0x80:
	  rlwinm    r0,r12,0,24,31
	  cmplwi    r0, 0x8
	  blt+      .loc_0x14
	  lwz       r3, 0x2A68(r13)
	  li        r0, 0
	  stb       r0, 0x4EE(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000248
 */
void GXGetVtxAttrFmt(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void GXGetVtxAttrFmtv(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802103BC
 * Size:	00008C
 */
void GXSetArray(void)
{
	/*
	.loc_0x0:
	  cmpwi     r3, 0x19
	  bne-      .loc_0xC
	  li        r3, 0xA

	.loc_0xC:
	  li        r0, 0x8
	  subi      r6, r3, 0x9
	  lis       r3, 0xCC01
	  stb       r0, -0x8000(r3)
	  ori       r0, r6, 0xA0
	  rlwinm    r4,r4,0,2,31
	  stb       r0, -0x8000(r3)
	  subic.    r0, r6, 0xC
	  stw       r4, -0x8000(r3)
	  blt-      .loc_0x4C
	  cmpwi     r0, 0x4
	  bge-      .loc_0x4C
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  stw       r4, 0x88(r3)

	.loc_0x4C:
	  li        r0, 0x8
	  lis       r3, 0xCC01
	  stb       r0, -0x8000(r3)
	  ori       r0, r6, 0xB0
	  rlwinm    r4,r5,0,24,31
	  stb       r0, -0x8000(r3)
	  subic.    r0, r6, 0xC
	  stw       r4, -0x8000(r3)
	  bltlr-
	  cmpwi     r0, 0x4
	  bgelr-
	  lwz       r3, 0x2A68(r13)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  stw       r4, 0x98(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80210448
 * Size:	000010
 */
void GXInvalidateVtxCache(void)
{
	/*
	.loc_0x0:
	  li        r0, 0x48
	  lis       r3, 0xCC01
	  stb       r0, -0x8000(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80210458
 * Size:	0002D0
 */
void GXSetTexCoordGen2(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r5, 0x14
	  stw       r0, 0x4(r1)
	  li        r11, 0
	  li        r12, 0
	  stwu      r1, -0x8(r1)
	  li        r10, 0x5
	  bgt-      .loc_0xB4
	  lis       r9, 0x802F
	  subi      r9, r9, 0x728C
	  rlwinm    r0,r5,2,0,29
	  lwzx      r0, r9, r0
	  mtctr     r0
	  bctr
	  li        r10, 0
	  li        r12, 0x1
	  b         .loc_0xB4
	  li        r10, 0x1
	  li        r12, 0x1
	  b         .loc_0xB4
	  li        r10, 0x3
	  li        r12, 0x1
	  b         .loc_0xB4
	  li        r10, 0x4
	  li        r12, 0x1
	  b         .loc_0xB4
	  li        r10, 0x2
	  b         .loc_0xB4
	  li        r10, 0x2
	  b         .loc_0xB4
	  li        r10, 0x5
	  b         .loc_0xB4
	  li        r10, 0x6
	  b         .loc_0xB4
	  li        r10, 0x7
	  b         .loc_0xB4
	  li        r10, 0x8
	  b         .loc_0xB4
	  li        r10, 0x9
	  b         .loc_0xB4
	  li        r10, 0xA
	  b         .loc_0xB4
	  li        r10, 0xB
	  b         .loc_0xB4
	  li        r10, 0xC

	.loc_0xB4:
	  cmpwi     r4, 0x1
	  beq-      .loc_0xDC
	  bge-      .loc_0xCC
	  cmpwi     r4, 0
	  bge-      .loc_0xF0
	  b         .loc_0x16C

	.loc_0xCC:
	  cmpwi     r4, 0xA
	  beq-      .loc_0x144
	  bge-      .loc_0x16C
	  b         .loc_0x108

	.loc_0xDC:
	  rlwinm    r0,r12,2,0,29
	  rlwinm    r4,r0,0,28,19
	  rlwinm    r0,r10,7,0,24
	  or        r11, r4, r0
	  b         .loc_0x16C

	.loc_0xF0:
	  rlwinm    r0,r12,2,0,29
	  ori       r0, r0, 0x2
	  rlwinm    r4,r0,0,28,19
	  rlwinm    r0,r10,7,0,24
	  or        r11, r4, r0
	  b         .loc_0x16C

	.loc_0x108:
	  rlwinm    r0,r12,2,0,29
	  rlwinm    r0,r0,0,28,24
	  ori       r0, r0, 0x10
	  rlwinm    r9,r0,0,25,19
	  rlwinm    r0,r10,7,0,24
	  or        r9, r9, r0
	  subi      r5, r5, 0xC
	  subi      r0, r4, 0x2
	  rlwinm    r9,r9,0,20,16
	  rlwinm    r4,r5,12,0,19
	  or        r4, r9, r4
	  rlwinm    r4,r4,0,17,13
	  rlwinm    r0,r0,15,0,16
	  or        r11, r4, r0
	  b         .loc_0x16C

	.loc_0x144:
	  cmpwi     r5, 0x13
	  rlwinm    r0,r12,2,0,29
	  bne-      .loc_0x15C
	  rlwinm    r0,r0,0,28,24
	  ori       r0, r0, 0x20
	  b         .loc_0x164

	.loc_0x15C:
	  rlwinm    r0,r0,0,28,24
	  ori       r0, r0, 0x30

	.loc_0x164:
	  rlwinm    r0,r0,0,25,19
	  ori       r11, r0, 0x100

	.loc_0x16C:
	  li        r10, 0x10
	  lis       r9, 0xCC01
	  stb       r10, -0x8000(r9)
	  addi      r0, r3, 0x1040
	  subi      r4, r8, 0x40
	  stw       r0, -0x8000(r9)
	  rlwinm    r5,r4,0,24,22
	  rlwinm    r4,r7,8,16,23
	  stw       r11, -0x8000(r9)
	  addi      r0, r3, 0x1050
	  cmplwi    r3, 0x6
	  stb       r10, -0x8000(r9)
	  or        r4, r5, r4
	  stw       r0, -0x8000(r9)
	  stw       r4, -0x8000(r9)
	  bgt-      .loc_0x29C
	  lis       r4, 0x802F
	  subi      r4, r4, 0x72A8
	  rlwinm    r0,r3,2,0,29
	  lwzx      r0, r4, r0
	  mtctr     r0
	  bctr
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r6,6,0,25
	  addi      r5, r4, 0x80
	  lwz       r4, 0x80(r4)
	  rlwinm    r4,r4,0,26,19
	  or        r0, r4, r0
	  stw       r0, 0x0(r5)
	  b         .loc_0x2B8
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r6,12,0,19
	  addi      r5, r4, 0x80
	  lwz       r4, 0x80(r4)
	  rlwinm    r4,r4,0,20,13
	  or        r0, r4, r0
	  stw       r0, 0x0(r5)
	  b         .loc_0x2B8
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r6,18,0,13
	  addi      r5, r4, 0x80
	  lwz       r4, 0x80(r4)
	  rlwinm    r4,r4,0,14,7
	  or        r0, r4, r0
	  stw       r0, 0x0(r5)
	  b         .loc_0x2B8
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r6,24,0,7
	  addi      r5, r4, 0x80
	  lwz       r4, 0x80(r4)
	  rlwinm    r4,r4,0,8,1
	  or        r0, r4, r0
	  stw       r0, 0x0(r5)
	  b         .loc_0x2B8
	  lwz       r4, 0x2A68(r13)
	  lwzu      r0, 0x84(r4)
	  rlwinm    r0,r0,0,0,25
	  or        r0, r0, r6
	  stw       r0, 0x0(r4)
	  b         .loc_0x2B8
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r6,6,0,25
	  addi      r5, r4, 0x84
	  lwz       r4, 0x84(r4)
	  rlwinm    r4,r4,0,26,19
	  or        r0, r4, r0
	  stw       r0, 0x0(r5)
	  b         .loc_0x2B8
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r6,12,0,19
	  addi      r5, r4, 0x84
	  lwz       r4, 0x84(r4)
	  rlwinm    r4,r4,0,20,13
	  or        r0, r4, r0
	  stw       r0, 0x0(r5)
	  b         .loc_0x2B8

	.loc_0x29C:
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r0,r6,18,0,13
	  addi      r5, r4, 0x84
	  lwz       r4, 0x84(r4)
	  rlwinm    r4,r4,0,14,7
	  or        r0, r4, r0
	  stw       r0, 0x0(r5)

	.loc_0x2B8:
	  addi      r3, r3, 0x1
	  bl        0x40D8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80210728
 * Size:	000048
 */
void GXSetNumTexGens(void)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2A68(r13)
	  rlwinm    r7,r3,0,24,31
	  li        r3, 0x10
	  addi      r6, r4, 0x204
	  lwz       r5, 0x204(r4)
	  lis       r4, 0xCC01
	  li        r0, 0x103F
	  rlwinm    r5,r5,0,0,27
	  or        r5, r5, r7
	  stw       r5, 0x0(r6)
	  stb       r3, -0x8000(r4)
	  lwz       r3, 0x2A68(r13)
	  stw       r0, -0x8000(r4)
	  stw       r7, -0x8000(r4)
	  lwz       r0, 0x4F0(r3)
	  ori       r0, r0, 0x4
	  stw       r0, 0x4F0(r3)
	  blr
	*/
}
