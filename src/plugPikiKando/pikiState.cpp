#include "PikiState.h"

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
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800CF0E8
 * Size:	001428
 */
void PikiStateMachine::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802C
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x7324
	  stwu      r1, -0x1B0(r1)
	  stw       r31, 0x1AC(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x1A8(r1)
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x489D4
	  li        r0, 0x23
	  stw       r0, 0xC(r31)
	  li        r0, 0
	  stw       r0, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x88124
	  stw       r3, 0x4(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x88134
	  stw       r3, 0x10(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x88144
	  stw       r3, 0x14(r31)
	  li        r3, 0x20
	  bl        -0x88150
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x80
	  bl        0x18C4

	.loc_0x80:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x100
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0xB4
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0xBC

	.loc_0xB4:
	  li        r0, 0
	  b         .loc_0xC0

	.loc_0xBC:
	  li        r0, 0x1

	.loc_0xC0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x100
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x100:
	  li        r3, 0x24
	  bl        -0x881E8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x118
	  bl        0x3D6C

	.loc_0x118:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x198
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x14C
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x154

	.loc_0x14C:
	  li        r0, 0
	  b         .loc_0x158

	.loc_0x154:
	  li        r0, 0x1

	.loc_0x158:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x198
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x198:
	  li        r3, 0x24
	  bl        -0x88280
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1B0
	  bl        0x43B4

	.loc_0x1B0:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x230
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x1E4
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x1EC

	.loc_0x1E4:
	  li        r0, 0
	  b         .loc_0x1F0

	.loc_0x1EC:
	  li        r0, 0x1

	.loc_0x1F0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x230
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x230:
	  li        r3, 0x14
	  bl        -0x88318
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x248
	  bl        0x5C74

	.loc_0x248:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x2C8
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x27C
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x284

	.loc_0x27C:
	  li        r0, 0
	  b         .loc_0x288

	.loc_0x284:
	  li        r0, 0x1

	.loc_0x288:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x2C8
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x2C8:
	  li        r3, 0x14
	  bl        -0x883B0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x2E0
	  bl        0x4C30

	.loc_0x2E0:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x360
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x314
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x31C

	.loc_0x314:
	  li        r0, 0
	  b         .loc_0x320

	.loc_0x31C:
	  li        r0, 0x1

	.loc_0x320:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x360
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x360:
	  li        r3, 0x2C
	  bl        -0x88448
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x378
	  bl        0x4DC4

	.loc_0x378:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x3F8
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x3AC
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x3B4

	.loc_0x3AC:
	  li        r0, 0
	  b         .loc_0x3B8

	.loc_0x3B4:
	  li        r0, 0x1

	.loc_0x3B8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x3F8
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x3F8:
	  li        r3, 0x1C
	  bl        -0x884E0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x410
	  bl        0x115C

	.loc_0x410:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x490
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x444
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x44C

	.loc_0x444:
	  li        r0, 0
	  b         .loc_0x450

	.loc_0x44C:
	  li        r0, 0x1

	.loc_0x450:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x490
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x490:
	  li        r3, 0x14
	  bl        -0x88578
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x4A8
	  bl        0x34CC

	.loc_0x4A8:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x528
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x4DC
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x4E4

	.loc_0x4DC:
	  li        r0, 0
	  b         .loc_0x4E8

	.loc_0x4E4:
	  li        r0, 0x1

	.loc_0x4E8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x528
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x528:
	  li        r3, 0x20
	  bl        -0x88610
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x540
	  bl        0x2CE4

	.loc_0x540:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x5C0
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x574
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x57C

	.loc_0x574:
	  li        r0, 0
	  b         .loc_0x580

	.loc_0x57C:
	  li        r0, 0x1

	.loc_0x580:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x5C0
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x5C0:
	  li        r3, 0x20
	  bl        -0x886A8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x5D8
	  bl        0x2F98

	.loc_0x5D8:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x658
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x60C
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x614

	.loc_0x60C:
	  li        r0, 0
	  b         .loc_0x618

	.loc_0x614:
	  li        r0, 0x1

	.loc_0x618:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x658
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x658:
	  li        r3, 0x14
	  bl        -0x88740
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x670
	  bl        0x3188

	.loc_0x670:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x6F0
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x6A4
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x6AC

	.loc_0x6A4:
	  li        r0, 0
	  b         .loc_0x6B0

	.loc_0x6AC:
	  li        r0, 0x1

	.loc_0x6B0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x6F0
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x6F0:
	  li        r3, 0x10
	  bl        -0x887D8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x708
	  bl        0x5470

	.loc_0x708:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x788
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x73C
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x744

	.loc_0x73C:
	  li        r0, 0
	  b         .loc_0x748

	.loc_0x744:
	  li        r0, 0x1

	.loc_0x748:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x788
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x788:
	  li        r3, 0x10
	  bl        -0x88870
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x7A0
	  bl        0x5578

	.loc_0x7A0:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x820
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x7D4
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x7DC

	.loc_0x7D4:
	  li        r0, 0
	  b         .loc_0x7E0

	.loc_0x7DC:
	  li        r0, 0x1

	.loc_0x7E0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x820
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x820:
	  li        r3, 0x10
	  bl        -0x88908
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x838
	  bl        0x5120

	.loc_0x838:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x8B8
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x86C
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x874

	.loc_0x86C:
	  li        r0, 0
	  b         .loc_0x878

	.loc_0x874:
	  li        r0, 0x1

	.loc_0x878:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x8B8
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x8B8:
	  li        r3, 0x44
	  bl        -0x889A0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x8D0
	  bl        0x586C

	.loc_0x8D0:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x950
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x904
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x90C

	.loc_0x904:
	  li        r0, 0
	  b         .loc_0x910

	.loc_0x90C:
	  li        r0, 0x1

	.loc_0x910:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x950
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x950:
	  li        r3, 0x10
	  bl        -0x88A38
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x968
	  bl        0x6524

	.loc_0x968:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x9E8
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x99C
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x9A4

	.loc_0x99C:
	  li        r0, 0
	  b         .loc_0x9A8

	.loc_0x9A4:
	  li        r0, 0x1

	.loc_0x9A8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x9E8
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x9E8:
	  li        r3, 0x10
	  bl        -0x88AD0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xA00
	  bl        0x67D8

	.loc_0xA00:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0xA80
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0xA34
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0xA3C

	.loc_0xA34:
	  li        r0, 0
	  b         .loc_0xA40

	.loc_0xA3C:
	  li        r0, 0x1

	.loc_0xA40:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xA80
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xA80:
	  li        r3, 0x10
	  bl        -0x88B68
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xA98
	  bl        0x7148

	.loc_0xA98:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0xB18
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0xACC
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0xAD4

	.loc_0xACC:
	  li        r0, 0
	  b         .loc_0xAD8

	.loc_0xAD4:
	  li        r0, 0x1

	.loc_0xAD8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xB18
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xB18:
	  li        r3, 0x10
	  bl        -0x88C00
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xB30
	  bl        0x698C

	.loc_0xB30:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0xBB0
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0xB64
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0xB6C

	.loc_0xB64:
	  li        r0, 0
	  b         .loc_0xB70

	.loc_0xB6C:
	  li        r0, 0x1

	.loc_0xB70:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xBB0
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xBB0:
	  li        r3, 0x14
	  bl        -0x88C98
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xBC8
	  bl        0x69C8

	.loc_0xBC8:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0xC48
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0xBFC
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0xC04

	.loc_0xBFC:
	  li        r0, 0
	  b         .loc_0xC08

	.loc_0xC04:
	  li        r0, 0x1

	.loc_0xC08:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xC48
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xC48:
	  li        r3, 0x18
	  bl        -0x88D30
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xC60
	  bl        0x6C44

	.loc_0xC60:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0xCE0
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0xC94
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0xC9C

	.loc_0xC94:
	  li        r0, 0
	  b         .loc_0xCA0

	.loc_0xC9C:
	  li        r0, 0x1

	.loc_0xCA0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xCE0
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xCE0:
	  li        r3, 0x10
	  bl        -0x88DC8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xCF8
	  bl        0x7354

	.loc_0xCF8:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0xD78
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0xD2C
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0xD34

	.loc_0xD2C:
	  li        r0, 0
	  b         .loc_0xD38

	.loc_0xD34:
	  li        r0, 0x1

	.loc_0xD38:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xD78
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xD78:
	  li        r3, 0x10
	  bl        -0x88E60
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xD90
	  bl        0x70A4

	.loc_0xD90:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0xE10
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0xDC4
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0xDCC

	.loc_0xDC4:
	  li        r0, 0
	  b         .loc_0xDD0

	.loc_0xDCC:
	  li        r0, 0x1

	.loc_0xDD0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xE10
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xE10:
	  li        r3, 0x14
	  bl        -0x88EF8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xE28
	  bl        0x7714

	.loc_0xE28:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0xEA8
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0xE5C
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0xE64

	.loc_0xE5C:
	  li        r0, 0
	  b         .loc_0xE68

	.loc_0xE64:
	  li        r0, 0x1

	.loc_0xE68:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xEA8
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xEA8:
	  li        r3, 0x18
	  bl        -0x88F90
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xEC0
	  bl        0x78C0

	.loc_0xEC0:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0xF40
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0xEF4
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0xEFC

	.loc_0xEF4:
	  li        r0, 0
	  b         .loc_0xF00

	.loc_0xEFC:
	  li        r0, 0x1

	.loc_0xF00:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xF40
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xF40:
	  li        r3, 0x1C
	  bl        -0x89028
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xF58
	  bl        0xC64

	.loc_0xF58:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0xFD8
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0xF8C
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0xF94

	.loc_0xF8C:
	  li        r0, 0
	  b         .loc_0xF98

	.loc_0xF94:
	  li        r0, 0x1

	.loc_0xF98:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xFD8
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xFD8:
	  li        r3, 0x10
	  bl        -0x890C0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xFF0
	  bl        0x7978

	.loc_0xFF0:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x1070
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x1024
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x102C

	.loc_0x1024:
	  li        r0, 0
	  b         .loc_0x1030

	.loc_0x102C:
	  li        r0, 0x1

	.loc_0x1030:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1070
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x1070:
	  li        r3, 0x10
	  bl        -0x89158
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1088
	  bl        0x7B10

	.loc_0x1088:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x1108
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x10BC
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x10C4

	.loc_0x10BC:
	  li        r0, 0
	  b         .loc_0x10C8

	.loc_0x10C4:
	  li        r0, 0x1

	.loc_0x10C8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1108
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x1108:
	  li        r3, 0x28
	  bl        -0x891F0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1120
	  bl        0x1578

	.loc_0x1120:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x11A0
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x1154
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x115C

	.loc_0x1154:
	  li        r0, 0
	  b         .loc_0x1160

	.loc_0x115C:
	  li        r0, 0x1

	.loc_0x1160:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x11A0
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x11A0:
	  li        r3, 0x2C
	  bl        -0x89288
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x11B8
	  bl        0xCF0

	.loc_0x11B8:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x1238
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x11EC
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x11F4

	.loc_0x11EC:
	  li        r0, 0
	  b         .loc_0x11F8

	.loc_0x11F4:
	  li        r0, 0x1

	.loc_0x11F8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1238
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x1238:
	  li        r3, 0x24
	  bl        -0x89320
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1250
	  bl        0x7A80

	.loc_0x1250:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x12D0
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x1284
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x128C

	.loc_0x1284:
	  li        r0, 0
	  b         .loc_0x1290

	.loc_0x128C:
	  li        r0, 0x1

	.loc_0x1290:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x12D0
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x12D0:
	  li        r3, 0x14
	  bl        -0x893B8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x12E8
	  bl        0x5CB8

	.loc_0x12E8:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x1368
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x131C
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x1324

	.loc_0x131C:
	  li        r0, 0
	  b         .loc_0x1328

	.loc_0x1324:
	  li        r0, 0x1

	.loc_0x1328:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1368
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x1368:
	  li        r3, 0x10
	  bl        -0x89450
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1380
	  bl        0x382C

	.loc_0x1380:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x1400
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x13B4
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x13BC

	.loc_0x13B4:
	  li        r0, 0
	  b         .loc_0x13C0

	.loc_0x13BC:
	  li        r0, 0x1

	.loc_0x13C0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1400
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x1400:
	  lis       r4, 0x802C
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r4, 0x7324
	  bl        -0x49CAC
	  lwz       r0, 0x1B4(r1)
	  lwz       r31, 0x1AC(r1)
	  lwz       r30, 0x1A8(r1)
	  addi      r1, r1, 0x1B0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0510
 * Size:	00002C
 */
void PikiState::dump()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D053C
 * Size:	000004
 */
void PikiState::doDump() { }

/*
 * --INFO--
 * Address:	800D0540
 * Size:	0000E0
 */
void PikiStateMachine::transit(Piki*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  mr        r29, r4
	  stw       r28, 0x50(r1)
	  addi      r28, r3, 0
	  lwz       r30, 0x52C(r4)
	  cmplwi    r30, 0
	  beq-      .loc_0x38
	  lwz       r0, 0x4(r30)
	  b         .loc_0x3C

	.loc_0x38:
	  li        r0, -0x1

	.loc_0x3C:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x58
	  cmplwi    r30, 0
	  beq-      .loc_0x54
	  lwz       r0, 0x4(r30)
	  b         .loc_0x58

	.loc_0x54:
	  li        r0, -0x1

	.loc_0x58:
	  lwz       r3, 0x14(r28)
	  rlwinm    r0,r5,2,0,29
	  cmplwi    r30, 0
	  lwzx      r31, r3, r0
	  beq-      .loc_0x8C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x4(r30)
	  stw       r0, 0x18(r28)

	.loc_0x8C:
	  lwz       r0, 0xC(r28)
	  cmpw      r31, r0
	  blt-      .loc_0x9C

	.loc_0x98:
	  b         .loc_0x98

	.loc_0x9C:
	  lwz       r3, 0x4(r28)
	  rlwinm    r0,r31,2,0,29
	  addi      r4, r29, 0
	  lwzx      r3, r3, r0
	  stw       r3, 0x52C(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  lwz       r28, 0x50(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0620
 * Size:	000030
 */
void PikiState::transit(Piki*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x8(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0650
 * Size:	00004C
 */
PikiLookAtState::PikiLookAtState()
    : PikiState(PIKISTATE_LookAt, "LOOKAT")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x1A
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3FE0
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5EB8
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D069C
 * Size:	0000A0
 */
void PikiLookAtState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  bl        0x1479B8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x1C(r1)
	  lis       r3, 0x4330
	  lfs       f2, -0x68E4(r2)
	  li        r0, 0
	  stw       r3, 0x18(r1)
	  lfs       f1, -0x68E8(r2)
	  li        r3, 0x145
	  lfd       f3, 0x18(r1)
	  lfs       f0, -0x68E0(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  stfs      f0, 0x10(r30)
	  stw       r0, 0x14(r30)
	  bl        -0x2B324
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x100
	  bl        -0x2C308
	  mr        r3, r31
	  bl        -0x3FEA0
	  mr        r3, r31
	  bl        -0x3FD44
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D073C
 * Size:	00020C
 */
void PikiLookAtState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  stw       r30, 0x78(r1)
	  stw       r29, 0x74(r1)
	  mr        r29, r4
	  stw       r28, 0x70(r1)
	  mr        r28, r3
	  lwz       r4, 0x504(r4)
	  lfs       f0, -0x3FD8(r13)
	  lfs       f4, 0x94(r29)
	  lfs       f1, 0x94(r4)
	  lfs       f3, 0x9C(r29)
	  lfs       f2, 0x9C(r4)
	  fsubs     f1, f4, f1
	  stfs      f0, 0xA4(r29)
	  fsubs     f2, f3, f2
	  lfs       f0, -0x3FD4(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x3FD0(r13)
	  stfs      f0, 0xAC(r29)
	  lfs       f0, -0x68D0(r2)
	  stfs      f0, 0x78(r29)
	  stfs      f0, 0x70(r29)
	  bl        0x14B258
	  lfs       f2, 0xA0(r29)
	  bl        -0x981F4
	  lfs       f2, -0x68CC(r2)
	  lfs       f0, 0xA0(r29)
	  fmuls     f1, f2, f1
	  fadds     f1, f0, f1
	  bl        -0x98234
	  stfs      f1, 0xA0(r29)
	  lwz       r0, 0x14(r28)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x128
	  bge-      .loc_0xA8
	  cmpwi     r0, 0
	  beq-      .loc_0xB4
	  bge-      .loc_0x1EC
	  b         .loc_0x154

	.loc_0xA8:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x154
	  b         .loc_0x1EC

	.loc_0xB4:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r28)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r28)
	  lfs       f1, 0x10(r28)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1EC
	  cmplwi    r29, 0
	  stfs      f0, 0x10(r28)
	  mr        r30, r29
	  beq-      .loc_0xEC
	  addi      r30, r30, 0x2B8

	.loc_0xEC:
	  addi      r3, r1, 0x44
	  li        r4, 0x2D
	  bl        0x4E728
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x4C
	  li        r4, 0x2D
	  bl        0x4E748
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x5E7C
	  li        r0, 0x1
	  stw       r0, 0x14(r28)
	  b         .loc_0x1EC

	.loc_0x128:
	  lfs       f1, 0xA0(r29)
	  lfs       f0, 0x18(r28)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA0(r29)
	  lfs       f0, -0x3FCC(r13)
	  stfs      f0, 0x88(r29)
	  lfs       f0, 0x18(r28)
	  stfs      f0, 0x8C(r29)
	  lfs       f0, -0x3FC8(r13)
	  stfs      f0, 0x90(r29)
	  b         .loc_0x1EC

	.loc_0x154:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r28)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r28)
	  lwz       r0, 0x184(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A8
	  lfs       f1, -0x68C8(r2)
	  lfs       f0, 0xA0(r29)
	  fadds     f1, f1, f0
	  bl        -0x98334
	  stfs      f1, 0xA0(r29)
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  lwz       r12, 0x0(r28)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1EC

	.loc_0x1A8:
	  lfs       f1, 0x10(r28)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1EC
	  stfs      f0, 0x10(r28)
	  lfs       f1, -0x68C8(r2)
	  lfs       f0, 0xA0(r29)
	  fadds     f1, f1, f0
	  bl        -0x9837C
	  stfs      f1, 0xA0(r29)
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  lwz       r12, 0x0(r28)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x1EC:
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  lwz       r29, 0x74(r1)
	  lwz       r28, 0x70(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0948
 * Size:	00002C
 */
void PikiLookAtState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x504(r4)
	  li        r4, 0x1
	  bl        -0x3794
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0974
 * Size:	0000B4
 */
void PikiLookAtState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x48
	  bge-      .loc_0x3C
	  cmpwi     r0, 0
	  bge-      .loc_0x94
	  b         .loc_0x9C

	.loc_0x3C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x9C
	  b         .loc_0x88

	.loc_0x48:
	  li        r0, 0x2
	  stw       r0, 0x14(r30)
	  lwz       r3, 0x504(r31)
	  lfsu      f3, 0x94(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x9C(r31)
	  lfs       f2, 0x8(r3)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0x14B018
	  lfs       f2, 0xA0(r31)
	  bl        -0x98434
	  lfs       f0, -0x68C4(r2)
	  fdivs     f0, f1, f0
	  stfs      f0, 0x18(r30)
	  b         .loc_0x9C

	.loc_0x88:
	  li        r0, 0x3
	  stw       r0, 0x14(r30)
	  b         .loc_0x9C

	.loc_0x94:
	  li        r0, 0x4
	  stw       r0, 0x14(r30)

	.loc_0x9C:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0A28
 * Size:	000048
 */
PikiNormalState::PikiNormalState()
    : PikiState(PIKISTATE_Normal, "NORMAL")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  subi      r6, r5, 0x5DC4
	  subi      r5, r13, 0x3FC4
	  stw       r0, 0x8(r3)
	  lis       r4, 0x802C
	  subi      r0, r4, 0x5F50
	  stw       r6, 0x0(r3)
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0A70
 * Size:	000088
 */
void PikiNormalState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  addi      r30, r4, 0
	  li        r4, 0x2
	  stw       r29, 0x34(r1)
	  addi      r29, r3, 0
	  addi      r3, r1, 0x1C
	  bl        0x4E4C0
	  addi      r31, r3, 0
	  addi      r3, r1, 0x24
	  li        r4, 0x2
	  bl        0x4E4B0
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  bl        -0x60E0
	  li        r0, 0
	  stw       r0, 0x10(r29)
	  lfs       f0, -0x68D0(r2)
	  stfs      f0, 0x14(r29)
	  lwz       r3, 0x224(r30)
	  lfs       f0, 0x2D8(r3)
	  stfs      f0, 0x1C(r29)
	  stw       r0, 0x18(r29)
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0AF8
 * Size:	00002C
 */
void PikiNormalState::restart(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0B24
 * Size:	00006C
 */
void PikiNormalState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x54
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x7
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x54:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0B90
 * Size:	000004
 */
void PikiNormalState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D0B94
 * Size:	000004
 */
void PikiNormalState::procWallMsg(Piki*, MsgWall*) { }

/*
 * --INFO--
 * Address:	800D0B98
 * Size:	000014
 */
void PikiNormalState::procOffWallMsg(Piki*, MsgOffWall*)
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x10(r3)
	  lfs       f0, -0x68D0(r2)
	  stfs      f0, 0x14(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0BAC
 * Size:	0000F4
 */
void PikiNormalState::procCollideMsg(Piki*, MsgCollide*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r5
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xD8
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  lwz       r4, 0x6C(r3)
	  mr        r31, r3
	  stw       r0, 0x18(r29)
	  lbz       r0, 0x2B4(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0xD8
	  lhz       r0, 0x4FC(r30)
	  cmplwi    r0, 0x9
	  beq-      .loc_0xD8
	  cmpwi     r4, 0x1
	  beq-      .loc_0x84
	  bge-      .loc_0xD8
	  cmpwi     r4, 0
	  bge-      .loc_0xC4
	  b         .loc_0xD8

	.loc_0x84:
	  lwz       r0, 0x520(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xD8
	  lwz       r5, 0x504(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x3A7C
	  stw       r31, 0x494(r30)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  lwz       r12, 0x0(r29)
	  li        r5, 0x1C
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xD8

	.loc_0xC4:
	  mr        r3, r31
	  bl        -0x8720
	  cmpwi     r3, 0x14
	  bne-      .loc_0xD8
	  stw       r31, 0x18(r29)

	.loc_0xD8:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0CA0
 * Size:	00004C
 */
PikiAbsorbState::PikiAbsorbState()
    : PikiState(PIKISTATE_Absorb, "ABSORB")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x1C
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3FBC
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5FE8
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0CEC
 * Size:	0000A4
 */
void PikiAbsorbState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x30
	  addi      r30, r30, 0x2B8

	.loc_0x30:
	  addi      r3, r1, 0x10
	  li        r4, 0x2F
	  bl        0x4E234
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x2F
	  bl        0x4E254
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x6370
	  li        r4, 0
	  stw       r4, 0x10(r28)
	  mr        r3, r29
	  lwz       r0, 0x494(r29)
	  stw       r0, 0x18(r28)
	  stb       r4, 0x14(r28)
	  lwz       r4, 0x18(r28)
	  addi      r4, r4, 0x94
	  bl        -0x46330
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0D90
 * Size:	0000E8
 */
void PikiAbsorbState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lfs       f0, -0x68D0(r2)
	  stfs      f0, 0x78(r4)
	  stfs      f0, 0x70(r4)
	  lfs       f0, -0x3FB4(r13)
	  stfs      f0, 0xA4(r4)
	  lfs       f0, -0x3FB0(r13)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, -0x3FAC(r13)
	  stfs      f0, 0xAC(r4)
	  lwz       r0, 0x10(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x50
	  b         .loc_0xA4

	.loc_0x50:
	  lwz       r3, 0x18(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x9C
	  li        r0, 0xA
	  stw       r0, 0x10(r1)
	  li        r0, 0
	  addi      r5, r1, 0x10
	  stw       r0, 0x14(r1)
	  lwz       r4, 0x18(r30)
	  stw       r31, 0x2BC(r4)
	  lwz       r3, 0x2E8(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x9C:
	  li        r0, 0x1
	  stb       r0, 0x14(r30)

	.loc_0xA4:
	  mr        r3, r31
	  bl        -0xA3B8
	  cmpwi     r3, 0x2F
	  beq-      .loc_0xD0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0xD0:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0E78
 * Size:	000110
 */
void PikiAbsorbState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x5
	  beq-      .loc_0x48
	  bge-      .loc_0x3C
	  cmpwi     r0, 0
	  beq-      .loc_0xB0
	  b         .loc_0xF8

	.loc_0x3C:
	  cmpwi     r0, 0x7
	  bge-      .loc_0xF8
	  b         .loc_0x70

	.loc_0x48:
	  lwz       r0, 0x10(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x64
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x103
	  bl        -0x2CAD0

	.loc_0x64:
	  li        r0, 0x1
	  stw       r0, 0x10(r30)
	  b         .loc_0xF8

	.loc_0x70:
	  lwz       r3, 0x18(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xF8
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x9C
	  addi      r4, r4, 0x2B8

	.loc_0x9C:
	  addi      r3, r31, 0x354
	  bl        0x4EBA8
	  li        r0, 0x2
	  stw       r0, 0x10(r30)
	  b         .loc_0xF8

	.loc_0xB0:
	  lbz       r0, 0x14(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xDC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x13
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xF8

	.loc_0xDC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0xF8:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0F88
 * Size:	000004
 */
void PikiAbsorbState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D0F8C
 * Size:	00005C
 */
PikiDrownState::PikiDrownState()
    : PikiState(PIKISTATE_Drown, "DROWN")
    , _1C(0.0f)
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x18
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3FA8
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6080
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  lfs       f0, -0x68D0(r2)
	  stfs      f0, 0x24(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D0FE8
 * Size:	000208
 */
void PikiDrownState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  mr        r31, r4
	  stw       r30, 0x78(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x74(r1)
	  stw       r28, 0x70(r1)
	  lhz       r0, 0x524(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x38
	  mr        r3, r31
	  bl        -0x9100

	.loc_0x38:
	  lwz       r0, 0x39C(r31)
	  cmpwi     r0, 0x38
	  bne-      .loc_0x50
	  li        r0, 0
	  sth       r0, 0x10(r30)
	  b         .loc_0x98

	.loc_0x50:
	  li        r0, 0x1
	  cmplwi    r31, 0
	  sth       r0, 0x10(r30)
	  mr        r28, r31
	  beq-      .loc_0x68
	  addi      r28, r28, 0x2B8

	.loc_0x68:
	  addi      r3, r1, 0x30
	  li        r4, 0x39
	  bl        0x4DF00
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x38
	  li        r4, 0x39
	  bl        0x4DF20
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0x66A4

	.loc_0x98:
	  bl        0x146FF0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x6C(r1)
	  lis       r29, 0x4330
	  lfs       f2, -0x68E4(r2)
	  stw       r29, 0x68(r1)
	  lfs       f1, -0x68E8(r2)
	  lfd       f3, 0x68(r1)
	  lfs       f0, -0x68C0(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x60(r1)
	  lwz       r3, 0x64(r1)
	  addi      r0, r3, 0x6
	  sth       r0, 0x12(r30)
	  lfs       f0, -0x3FA0(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x3F9C(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x3F98(r13)
	  stfs      f0, 0xAC(r31)
	  bl        0x146F8C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x5C(r1)
	  lfs       f2, -0x68E4(r2)
	  stw       r29, 0x58(r1)
	  lfs       f1, -0x68E8(r2)
	  lfd       f3, 0x58(r1)
	  lfs       f0, -0x68C0(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f2, f1, f2
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x50(r1)
	  lwz       r0, 0x54(r1)
	  sth       r0, 0x14(r30)
	  lwz       r0, 0x2AC(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x184
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3064
	  stw       r0, 0x40(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x2E74
	  stw       r31, 0x44(r1)
	  addi      r4, r1, 0x40
	  stw       r0, 0x40(r1)
	  stfs      f1, 0x48(r1)
	  lwz       r3, 0x2AC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x184:
	  lwz       r3, 0x3038(r13)
	  addi      r6, r31, 0x94
	  li        r4, 0x5
	  li        r5, 0xB5
	  bl        -0x2CD48
	  li        r0, 0
	  sth       r0, 0x16(r30)
	  li        r4, 0
	  lfs       f0, -0x3F94(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x3F90(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x3F8C(r13)
	  stfs      f0, 0xAC(r31)
	  lwz       r3, 0x4F8(r31)
	  bl        -0xBE64
	  lwz       r0, 0x184(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1E0
	  mr        r3, r31
	  bl        -0x40944
	  mr        r3, r31
	  bl        -0x407E8

	.loc_0x1E0:
	  li        r0, 0
	  stb       r0, 0x28(r30)
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  lwz       r29, 0x74(r1)
	  lwz       r28, 0x70(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D11F0
 * Size:	0003DC
 */
void PikiDrownState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1B8(r1)
	  stfd      f31, 0x1B0(r1)
	  stfd      f30, 0x1A8(r1)
	  stfd      f29, 0x1A0(r1)
	  stw       r31, 0x19C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x198(r1)
	  mr        r30, r3
	  lhz       r0, 0x10(r3)
	  cmplwi    r0, 0x2
	  beq-      .loc_0x130
	  lhz       r0, 0x426(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x130
	  lhz       r3, 0x16(r30)
	  addi      r0, r3, 0x1
	  sth       r0, 0x16(r30)
	  lhz       r0, 0x16(r30)
	  cmplwi    r0, 0x1
	  ble-      .loc_0x138
	  lfs       f1, 0x98(r31)
	  lfs       f0, -0x68BC(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x98(r31)
	  lfs       f1, 0xA0(r31)
	  bl        0x14A8F8
	  fmr       f31, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x14AA80
	  stfs      f1, 0x188(r1)
	  mr        r3, r31
	  lfs       f0, -0x3F88(r13)
	  stfs      f0, 0x18C(r1)
	  stfs      f31, 0x190(r1)
	  lfs       f0, 0x188(r1)
	  lfs       f1, -0x68B8(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x188(r1)
	  lfs       f0, 0x18C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x18C(r1)
	  lfs       f0, 0x190(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x190(r1)
	  lwz       r4, 0x188(r1)
	  lwz       r0, 0x18C(r1)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x190(r1)
	  stw       r0, 0x78(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x108
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x17
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3B8

	.loc_0x108:
	  li        r0, 0x3
	  stb       r0, 0x400(r31)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1F
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3B8

	.loc_0x130:
	  li        r0, 0
	  sth       r0, 0x16(r30)

	.loc_0x138:
	  lhz       r0, 0x10(r30)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x1E4
	  lwz       r3, 0x504(r31)
	  lfsu      f3, 0x94(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x98(r31)
	  lfs       f2, 0x4(r3)
	  fsubs     f31, f3, f1
	  lfs       f1, 0x8(r3)
	  fsubs     f30, f2, f0
	  lfs       f0, 0x9C(r31)
	  fsubs     f29, f1, f0
	  fmuls     f1, f31, f31
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC3730
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x19C
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x19C:
	  mr        r3, r31
	  lfs       f1, -0x68B4(r2)
	  bl        -0x5630
	  fmuls     f3, f31, f1
	  fmuls     f2, f30, f1
	  fmuls     f0, f29, f1
	  stfs      f3, 0xAC(r1)
	  lfs       f1, 0xAC(r1)
	  stfs      f1, 0x150(r1)
	  stfs      f2, 0x154(r1)
	  stfs      f0, 0x158(r1)
	  lwz       r3, 0x150(r1)
	  lwz       r0, 0x154(r1)
	  stw       r3, 0x1C(r30)
	  stw       r0, 0x20(r30)
	  lwz       r0, 0x158(r1)
	  stw       r0, 0x24(r30)
	  b         .loc_0x1FC

	.loc_0x1E4:
	  lfs       f0, -0x3F84(r13)
	  stfs      f0, 0x1C(r30)
	  lfs       f0, -0x3F80(r13)
	  stfs      f0, 0x20(r30)
	  lfs       f0, -0x3F7C(r13)
	  stfs      f0, 0x24(r30)

	.loc_0x1FC:
	  lbz       r0, 0x28(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x224
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x240

	.loc_0x224:
	  lfs       f0, -0x3F78(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x3F74(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x3F70(r13)
	  stfs      f0, 0xAC(r31)
	  b         .loc_0x3B8

	.loc_0x240:
	  lfs       f3, 0x1C(r30)
	  lfs       f2, 0xA4(r31)
	  lfs       f1, 0x20(r30)
	  lfs       f0, 0xA8(r31)
	  fsubs     f29, f3, f2
	  lfs       f2, 0x24(r30)
	  fsubs     f30, f1, f0
	  lfs       f0, 0xAC(r31)
	  fmuls     f1, f29, f29
	  fsubs     f31, f2, f0
	  fmuls     f0, f30, f30
	  fmuls     f2, f31, f31
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC3828
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x294
	  fdivs     f29, f29, f1
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1

	.loc_0x294:
	  lbz       r0, 0x28(r30)
	  lfs       f4, -0x68B0(r2)
	  cmplwi    r0, 0
	  beq-      .loc_0x2AC
	  lfs       f0, -0x68C0(r2)
	  fmuls     f4, f4, f0

	.loc_0x2AC:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f3, 0x28C(r3)
	  fmuls     f0, f4, f3
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x348
	  fmuls     f2, f29, f4
	  fmuls     f1, f30, f4
	  fmuls     f0, f31, f4
	  stfs      f2, 0x90(r1)
	  fmuls     f1, f1, f3
	  lfs       f2, 0x90(r1)
	  fmuls     f0, f0, f3
	  fmuls     f2, f2, f3
	  stfs      f2, 0xEC(r1)
	  lfs       f2, 0xEC(r1)
	  stfs      f2, 0x12C(r1)
	  stfs      f1, 0x130(r1)
	  stfs      f0, 0x134(r1)
	  lfs       f1, 0xA4(r31)
	  lfs       f0, 0x12C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xE0(r1)
	  lfs       f0, 0xE0(r1)
	  stfs      f0, 0x138(r1)
	  lfs       f1, 0xA8(r31)
	  lfs       f0, 0x130(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x13C(r1)
	  lfs       f1, 0xAC(r31)
	  lfs       f0, 0x134(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x140(r1)
	  lwz       r3, 0x138(r1)
	  lwz       r0, 0x13C(r1)
	  stw       r3, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0x140(r1)
	  stw       r0, 0xAC(r31)
	  b         .loc_0x3A0

	.loc_0x348:
	  fmuls     f2, f29, f3
	  fmuls     f1, f30, f3
	  fmuls     f0, f31, f3
	  stfs      f2, 0xD4(r1)
	  lfs       f3, 0xA4(r31)
	  lfs       f2, 0xD4(r1)
	  fadds     f2, f3, f2
	  stfs      f2, 0xC8(r1)
	  lfs       f2, 0xC8(r1)
	  stfs      f2, 0x114(r1)
	  lfs       f2, 0xA8(r31)
	  fadds     f1, f2, f1
	  stfs      f1, 0x118(r1)
	  lfs       f1, 0xAC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x11C(r1)
	  lwz       r3, 0x114(r1)
	  lwz       r0, 0x118(r1)
	  stw       r3, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0x11C(r1)
	  stw       r0, 0xAC(r31)

	.loc_0x3A0:
	  lwz       r3, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)

	.loc_0x3B8:
	  lwz       r0, 0x1BC(r1)
	  lfd       f31, 0x1B0(r1)
	  lfd       f30, 0x1A8(r1)
	  lfd       f29, 0x1A0(r1)
	  lwz       r31, 0x19C(r1)
	  lwz       r30, 0x198(r1)
	  addi      r1, r1, 0x1B8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D15CC
 * Size:	000004
 */
void PikiDrownState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D15D0
 * Size:	0001AC
 */
void PikiDrownState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x48(r1)
	  addi      r28, r3, 0
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x38
	  b         .loc_0x18C

	.loc_0x38:
	  lhz       r0, 0x10(r28)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x68
	  lwz       r3, 0x3038(r13)
	  addi      r6, r29, 0x94
	  li        r4, 0x5
	  li        r5, 0xB6
	  bl        -0x2D1F0
	  addi      r3, r29, 0
	  li        r4, 0
	  bl        -0x46950
	  b         .loc_0x18C

	.loc_0x68:
	  cmplwi    r0, 0x1
	  bne-      .loc_0x128
	  lhz       r3, 0x12(r28)
	  subi      r3, r3, 0x1
	  rlwinm.   r0,r3,0,16,31
	  sth       r3, 0x12(r28)
	  bne-      .loc_0xE4
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x94
	  addi      r30, r30, 0x2B8

	.loc_0x94:
	  addi      r3, r1, 0x34
	  li        r4, 0x3A
	  bl        0x4D8EC
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x3C
	  li        r4, 0x3A
	  bl        0x4D90C
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x6CB8
	  lwz       r3, 0x3038(r13)
	  addi      r6, r29, 0x94
	  li        r4, 0x5
	  li        r5, 0xB7
	  bl        -0x2D270
	  li        r0, 0x2
	  sth       r0, 0x10(r28)
	  b         .loc_0x18C

	.loc_0xE4:
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0xF4
	  addi      r30, r30, 0x2B8

	.loc_0xF4:
	  addi      r3, r1, 0x24
	  li        r4, 0x39
	  bl        0x4D88C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x2C
	  li        r4, 0x39
	  bl        0x4D8AC
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x6D18
	  b         .loc_0x18C

	.loc_0x128:
	  cmplwi    r0, 0
	  bne-      .loc_0x18C
	  li        r0, 0x1
	  cmplwi    r29, 0
	  sth       r0, 0x10(r28)
	  mr        r30, r29
	  beq-      .loc_0x148
	  addi      r30, r30, 0x2B8

	.loc_0x148:
	  addi      r3, r1, 0x14
	  li        r4, 0x39
	  bl        0x4D838
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x39
	  bl        0x4D858
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x6D6C
	  lwz       r3, 0x3038(r13)
	  addi      r6, r29, 0x94
	  li        r4, 0x5
	  li        r5, 0xB5
	  bl        -0x2D324

	.loc_0x18C:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  lwz       r28, 0x48(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D177C
 * Size:	00005C
 */
PikiKinokoState::PikiKinokoState()
    : PikiState(PIKISTATE_Kinoko, "KINOKO")
    , _18(0.0f)
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x17
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3F6C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6150
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  lfs       f0, -0x68D0(r2)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  stfs      f0, 0x18(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D17D8
 * Size:	0000A4
 */
void PikiKinokoState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  addi      r3, r30, 0
	  bl        -0x7EAC
	  lwz       r3, 0x3160(r13)
	  addi      r4, r30, 0x94
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x10(r29)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        .loc_0xA4
	  addi      r3, r1, 0x10
	  li        r4, 0x2
	  bl        0x4D724
	  addi      r31, r3, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x2
	  bl        0x4D714
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  bl        -0x6E7C
	  li        r0, 0
	  stw       r0, 0x24(r29)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0xA4:
	*/
}

/*
 * --INFO--
 * Address:	800D187C
 * Size:	000268
 */
void PikiKinokoState::initWalk(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB8(r1)
	  stfd      f31, 0xB0(r1)
	  stfd      f30, 0xA8(r1)
	  stfd      f29, 0xA0(r1)
	  stw       r31, 0x9C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x98(r1)
	  addi      r30, r3, 0
	  bl        0x1467CC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x94(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  stw       r0, 0x90(r1)
	  lfs       f2, -0x68E8(r2)
	  lfd       f1, 0x90(r1)
	  lfs       f0, -0x68C0(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6898(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  lwz       r3, 0x10(r30)
	  lfsu      f3, 0x94(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x98(r31)
	  lfs       f2, 0x4(r3)
	  fsubs     f31, f3, f1
	  lfs       f1, 0x8(r3)
	  fsubs     f30, f2, f0
	  lfs       f0, 0x9C(r31)
	  fsubs     f29, f1, f0
	  fmuls     f1, f31, f31
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC3CE4
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xC4
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0xC4:
	  stfs      f29, 0x74(r1)
	  fneg      f0, f31
	  lfs       f1, -0x3F64(r13)
	  stfs      f1, 0x78(r1)
	  stfs      f0, 0x7C(r1)
	  bl        0x14671C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x94(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x68E4(r2)
	  stw       r0, 0x90(r1)
	  lfs       f1, -0x68E8(r2)
	  lfd       f3, 0x90(r1)
	  lfs       f0, -0x68B4(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x13C
	  lfs       f0, 0x74(r1)
	  lfs       f1, -0x6894(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x78(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x7C(r1)

	.loc_0x13C:
	  bl        0x1466B8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x94(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  addi      r6, r1, 0x30
	  stw       r0, 0x90(r1)
	  lfs       f2, -0x68E8(r2)
	  addi      r5, r1, 0x2C
	  lfd       f1, 0x90(r1)
	  addi      r4, r1, 0x28
	  lfs       f0, -0x68B4(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6890(r2)
	  addi      r3, r1, 0x58
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fmuls     f2, f29, f0
	  fmuls     f1, f30, f0
	  fmuls     f0, f31, f0
	  stfs      f2, 0x30(r1)
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x28(r1)
	  bl        -0x9A904
	  lfs       f1, 0x74(r1)
	  lfs       f0, 0x58(r1)
	  lfs       f3, 0x78(r1)
	  lfs       f2, 0x5C(r1)
	  fadds     f0, f1, f0
	  lfs       f4, 0x7C(r1)
	  lfs       f1, 0x60(r1)
	  fadds     f2, f3, f2
	  stfs      f0, 0x74(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x78(r1)
	  stfs      f0, 0x7C(r1)
	  lfs       f1, 0x74(r1)
	  lfs       f0, 0x78(r1)
	  lfs       f2, 0x7C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC3E34
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x22C
	  lfs       f0, 0x74(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x78(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x7C(r1)

	.loc_0x22C:
	  lwz       r3, 0x74(r1)
	  lwz       r0, 0x78(r1)
	  stw       r3, 0x18(r30)
	  stw       r0, 0x1C(r30)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0x20(r30)
	  lwz       r0, 0xBC(r1)
	  lfd       f31, 0xB0(r1)
	  lfd       f30, 0xA8(r1)
	  lfd       f29, 0xA0(r1)
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D1AE4
 * Size:	000044
 */
void PikiKinokoState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x24(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x30
	  bge-      .loc_0x34
	  cmpwi     r0, 0
	  bge-      .loc_0x28
	  b         .loc_0x34

	.loc_0x28:
	  bl        0x20
	  b         .loc_0x34

	.loc_0x30:
	  bl        .loc_0x44

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x44:
	*/
}

/*
 * --INFO--
 * Address:	800D1B28
 * Size:	000004
 */
void PikiKinokoState::exeAttack(Piki*) { }

/*
 * --INFO--
 * Address:	800D1B2C
 * Size:	0007B8
 */
void PikiKinokoState::exeBoid(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2D8(r1)
	  stfd      f31, 0x2D0(r1)
	  stfd      f30, 0x2C8(r1)
	  stfd      f29, 0x2C0(r1)
	  stfd      f28, 0x2B8(r1)
	  stfd      f27, 0x2B0(r1)
	  stfd      f26, 0x2A8(r1)
	  stfd      f25, 0x2A0(r1)
	  stfd      f24, 0x298(r1)
	  stfd      f23, 0x290(r1)
	  stfd      f22, 0x288(r1)
	  stmw      r25, 0x26C(r1)
	  mr        r30, r3
	  mr        r31, r4
	  lwz       r5, 0x2DEC(r13)
	  lfs       f1, 0x14(r3)
	  lfs       f0, 0x28C(r5)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r3)
	  lfs       f1, 0x14(r3)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x2B0
	  bl        0x1464E0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x264(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  addi      r6, r1, 0xB4
	  stw       r0, 0x260(r1)
	  lfs       f2, -0x68E8(r2)
	  addi      r5, r1, 0xB0
	  lfd       f1, 0x260(r1)
	  addi      r4, r1, 0xAC
	  lfs       f0, -0x68C0(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6898(r2)
	  addi      r3, r1, 0x178
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  lwz       r7, 0x10(r30)
	  lfs       f0, 0x9C(r31)
	  addi      r7, r7, 0x94
	  lfs       f1, 0x8(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xB4(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x98(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xB0(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x94(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xAC(r1)
	  bl        -0x9AB00
	  lfs       f27, 0x178(r1)
	  lfs       f28, 0x17C(r1)
	  fmuls     f1, f27, f27
	  lfs       f29, 0x180(r1)
	  fmuls     f0, f28, f28
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC4000
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x130
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1
	  fdivs     f29, f29, f1

	.loc_0x130:
	  stfs      f29, 0x16C(r1)
	  fneg      f0, f27
	  lfs       f1, -0x3F64(r13)
	  stfs      f1, 0x170(r1)
	  stfs      f0, 0x174(r1)
	  bl        0x146400
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x264(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x68E4(r2)
	  stw       r0, 0x260(r1)
	  lfs       f1, -0x68E8(r2)
	  lfd       f3, 0x260(r1)
	  lfs       f0, -0x68B4(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1A8
	  lfs       f0, 0x16C(r1)
	  lfs       f1, -0x6894(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x16C(r1)
	  lfs       f0, 0x170(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x170(r1)
	  lfs       f0, 0x174(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x174(r1)

	.loc_0x1A8:
	  bl        0x14639C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x264(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  addi      r6, r1, 0x88
	  stw       r0, 0x260(r1)
	  lfs       f2, -0x68E8(r2)
	  addi      r5, r1, 0x84
	  lfd       f1, 0x260(r1)
	  addi      r4, r1, 0x80
	  lfs       f0, -0x68B4(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6890(r2)
	  addi      r3, r1, 0x188
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fmuls     f2, f29, f0
	  fmuls     f1, f28, f0
	  fmuls     f0, f27, f0
	  stfs      f2, 0x88(r1)
	  stfs      f1, 0x84(r1)
	  stfs      f0, 0x80(r1)
	  bl        -0x9AC20
	  lfs       f1, 0x16C(r1)
	  lfs       f0, 0x188(r1)
	  lfs       f3, 0x170(r1)
	  lfs       f2, 0x18C(r1)
	  fadds     f0, f1, f0
	  lfs       f4, 0x174(r1)
	  lfs       f1, 0x190(r1)
	  fadds     f2, f3, f2
	  stfs      f0, 0x16C(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x170(r1)
	  stfs      f0, 0x174(r1)
	  lfs       f1, 0x16C(r1)
	  lfs       f0, 0x170(r1)
	  lfs       f2, 0x174(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC4150
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x298
	  lfs       f0, 0x16C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x16C(r1)
	  lfs       f0, 0x170(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x170(r1)
	  lfs       f0, 0x174(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x174(r1)

	.loc_0x298:
	  lwz       r3, 0x16C(r1)
	  lwz       r0, 0x170(r1)
	  stw       r3, 0x18(r30)
	  stw       r0, 0x1C(r30)
	  lwz       r0, 0x174(r1)
	  stw       r0, 0x20(r30)

	.loc_0x2B0:
	  addi      r28, r31, 0x1B8
	  lfs       f27, -0x3F60(r13)
	  mr        r3, r28
	  lfs       f28, -0x3F5C(r13)
	  lwz       r12, 0x0(r28)
	  li        r26, 0
	  lfs       f29, -0x3F58(r13)
	  li        r29, 0
	  lwz       r12, 0xC(r12)
	  lfs       f30, -0x3F54(r13)
	  mtlr      r12
	  lfs       f31, -0x3F50(r13)
	  lfs       f26, -0x3F4C(r13)
	  lfs       f25, -0x3F48(r13)
	  lfs       f24, -0x3F44(r13)
	  lfs       f23, -0x3F40(r13)
	  lfs       f22, -0x688C(r2)
	  blrl
	  mr        r27, r3
	  b         .loc_0x408

	.loc_0x300:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x324
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x33C

	.loc_0x324:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x33C:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x3EC
	  cmplw     r3, r31
	  addi      r25, r3, 0
	  beq-      .loc_0x3EC
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3EC
	  lfs       f1, 0x94(r25)
	  lfs       f2, 0x9C(r25)
	  lfs       f3, 0x94(r31)
	  lfs       f4, 0x9C(r31)
	  bl        -0x99884
	  fcmpo     cr0, f1, f22
	  bge-      .loc_0x3B8
	  lfs       f4, 0x94(r31)
	  fmr       f22, f1
	  lfs       f0, 0x94(r25)
	  li        r29, 0x1
	  lfs       f3, 0x98(r31)
	  lfs       f2, 0x98(r25)
	  lfs       f1, 0x9C(r31)
	  fsubs     f25, f4, f0
	  lfs       f0, 0x9C(r25)
	  fsubs     f24, f3, f2
	  fsubs     f23, f1, f0

	.loc_0x3B8:
	  lfs       f1, 0x94(r25)
	  addi      r26, r26, 0x1
	  lfs       f0, 0x98(r25)
	  lfs       f3, 0x9C(r25)
	  fadds     f27, f27, f1
	  lfs       f2, 0x70(r25)
	  fadds     f28, f28, f0
	  lfs       f1, 0x74(r25)
	  lfs       f0, 0x78(r25)
	  fadds     f29, f29, f3
	  fadds     f30, f30, f2
	  fadds     f31, f31, f1
	  fadds     f26, f26, f0

	.loc_0x3EC:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x408:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x430
	  li        r0, 0x1
	  b         .loc_0x45C

	.loc_0x430:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x458
	  li        r0, 0x1
	  b         .loc_0x45C

	.loc_0x458:
	  li        r0, 0

	.loc_0x45C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x300
	  cmpwi     r26, 0
	  ble-      .loc_0x6C8
	  fmuls     f1, f25, f25
	  fmuls     f0, f24, f24
	  fmuls     f2, f23, f23
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC436C
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x49C
	  fdivs     f25, f25, f1
	  fdivs     f24, f24, f1
	  fdivs     f23, f23, f1

	.loc_0x49C:
	  xoris     r0, r26, 0x8000
	  lfd       f1, -0x68D8(r2)
	  stw       r0, 0x264(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x68E8(r2)
	  stw       r0, 0x260(r1)
	  lfd       f0, 0x260(r1)
	  fsubs     f0, f0, f1
	  fdivs     f3, f2, f0
	  fmuls     f30, f30, f3
	  fmuls     f31, f31, f3
	  fmuls     f26, f26, f3
	  fmuls     f1, f30, f30
	  fmuls     f0, f31, f31
	  fmuls     f2, f26, f26
	  fmuls     f27, f27, f3
	  fadds     f0, f1, f0
	  fmuls     f28, f28, f3
	  fmuls     f29, f29, f3
	  fadds     f1, f2, f0
	  bl        -0xC43D8
	  lfs       f2, 0x94(r31)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0x9C(r31)
	  fsubs     f26, f27, f2
	  fsubs     f27, f28, f1
	  lfs       f1, 0xA0(r31)
	  fsubs     f28, f29, f0
	  bl        0x149B1C
	  fmr       f30, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x149CA4
	  fmuls     f2, f26, f26
	  lfs       f22, -0x3F3C(r13)
	  fmuls     f0, f27, f27
	  fmuls     f3, f28, f28
	  fmr       f31, f1
	  fadds     f0, f2, f0
	  fadds     f1, f3, f0
	  bl        -0xC4424
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x554
	  fdivs     f26, f26, f1
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1

	.loc_0x554:
	  lfs       f0, -0x68D0(r2)
	  rlwinm.   r0,r29,0,24,31
	  stfs      f0, 0x210(r1)
	  stfs      f0, 0x20C(r1)
	  stfs      f0, 0x208(r1)
	  beq-      .loc_0x5A8
	  lfs       f4, -0x3F34(r13)
	  lfs       f5, -0x3F38(r13)
	  fmuls     f2, f25, f4
	  fmuls     f3, f31, f5
	  fmuls     f1, f22, f5
	  fmuls     f0, f24, f4
	  fadds     f2, f3, f2
	  fmuls     f3, f23, f4
	  fmuls     f4, f30, f5
	  fadds     f1, f1, f0
	  stfs      f2, 0x208(r1)
	  fadds     f0, f4, f3
	  stfs      f1, 0x20C(r1)
	  stfs      f0, 0x210(r1)
	  b         .loc_0x660

	.loc_0x5A8:
	  lfs       f0, -0x3F2C(r13)
	  addi      r6, r1, 0xA0
	  lfs       f5, 0x20(r30)
	  addi      r5, r1, 0x9C
	  lfs       f6, -0x3F28(r13)
	  lfs       f4, 0x1C(r30)
	  fmuls     f2, f28, f0
	  lfs       f3, 0x18(r30)
	  fmuls     f1, f27, f0
	  fmuls     f0, f26, f0
	  fmuls     f29, f5, f6
	  fmuls     f28, f4, f6
	  stfs      f2, 0xA0(r1)
	  fmuls     f27, f3, f6
	  stfs      f1, 0x9C(r1)
	  addi      r4, r1, 0x98
	  stfs      f0, 0x98(r1)
	  addi      r3, r1, 0x1B0
	  bl        -0x9B000
	  lfs       f0, -0x3F30(r13)
	  addi      r6, r1, 0x94
	  addi      r5, r1, 0x90
	  fmuls     f2, f30, f0
	  addi      r4, r1, 0x8C
	  fmuls     f1, f22, f0
	  addi      r3, r1, 0x1BC
	  fmuls     f0, f31, f0
	  stfs      f2, 0x94(r1)
	  stfs      f1, 0x90(r1)
	  stfs      f0, 0x8C(r1)
	  bl        -0x9B030
	  lfs       f2, 0x1BC(r1)
	  lfs       f0, 0x1B0(r1)
	  lfs       f1, 0x1C0(r1)
	  fadds     f2, f2, f0
	  lfs       f0, 0x1B4(r1)
	  lfs       f3, 0x1C4(r1)
	  fadds     f0, f1, f0
	  lfs       f1, 0x1B8(r1)
	  fadds     f2, f2, f27
	  fadds     f3, f3, f1
	  fadds     f1, f0, f28
	  stfs      f2, 0x208(r1)
	  fadds     f0, f3, f29
	  stfs      f1, 0x20C(r1)
	  stfs      f0, 0x210(r1)

	.loc_0x660:
	  lfs       f1, 0x208(r1)
	  lfs       f0, 0x20C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x210(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC456C
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x6B4
	  lfs       f0, 0x208(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x208(r1)
	  lfs       f0, 0x20C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x20C(r1)
	  lfs       f0, 0x210(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x210(r1)

	.loc_0x6B4:
	  lfs       f1, -0x68E0(r2)
	  addi      r3, r31, 0
	  addi      r4, r1, 0x208
	  bl        -0x6414
	  b         .loc_0x6D8

	.loc_0x6C8:
	  lfs       f1, -0x68E0(r2)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x18
	  bl        -0x6428

	.loc_0x6D8:
	  lwz       r3, 0x10(r30)
	  lfsu      f1, 0x94(r3)
	  lfs       f0, 0x94(r31)
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x98(r31)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  lfs       f1, 0x9C(r31)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x1FC(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x200(r1)
	  stfs      f0, 0x204(r1)
	  lfs       f1, 0x1FC(r1)
	  lfs       f0, 0x200(r1)
	  lfs       f2, 0x204(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC4618
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x760
	  lfs       f0, 0x1FC(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x1FC(r1)
	  lfs       f0, 0x200(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x200(r1)
	  lfs       f0, 0x204(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x204(r1)

	.loc_0x760:
	  lfs       f0, -0x6888(r2)
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0x77C
	  lfs       f1, -0x68B4(r2)
	  addi      r3, r31, 0
	  addi      r4, r1, 0x1FC
	  bl        -0x64CC

	.loc_0x77C:
	  lmw       r25, 0x26C(r1)
	  lwz       r0, 0x2DC(r1)
	  lfd       f31, 0x2D0(r1)
	  lfd       f30, 0x2C8(r1)
	  lfd       f29, 0x2C0(r1)
	  lfd       f28, 0x2B8(r1)
	  lfd       f27, 0x2B0(r1)
	  lfd       f26, 0x2A8(r1)
	  lfd       f25, 0x2A0(r1)
	  lfd       f24, 0x298(r1)
	  lfd       f23, 0x290(r1)
	  lfd       f22, 0x288(r1)
	  addi      r1, r1, 0x2D8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D22E4
 * Size:	000024
 */
void PikiKinokoState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x8974
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D2308
 * Size:	00004C
 */
PikiBubbleState::PikiBubbleState()
    : PikiState(PIKISTATE_Bubble, "BUBBLE")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0xA
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3F24
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x61E8
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D2354
 * Size:	00012C
 */
void PikiBubbleState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  stw       r30, 0x70(r1)
	  mr        r30, r4
	  stw       r29, 0x6C(r1)
	  addi      r29, r3, 0
	  addi      r3, r30, 0
	  lwz       r5, 0x504(r4)
	  li        r4, 0
	  bl        -0x51B4
	  addi      r3, r1, 0x20
	  li        r4, 0x45
	  bl        0x4CBCC
	  addi      r31, r3, 0
	  addi      r3, r1, 0x28
	  li        r4, 0x45
	  bl        0x4CBBC
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  bl        -0x79D4
	  mr        r3, r30
	  bl        -0x77A8
	  lwz       r3, 0x224(r30)
	  lfs       f0, 0x3E8(r3)
	  stfs      f0, 0x10(r29)
	  bl        0x145CAC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x64(r1)
	  lis       r0, 0x4330
	  lfs       f0, -0x68E4(r2)
	  addi      r4, r1, 0x30
	  stw       r0, 0x60(r1)
	  lfs       f3, -0x68E8(r2)
	  lfd       f2, 0x60(r1)
	  lfs       f1, -0x68CC(r2)
	  fsubs     f4, f2, f4
	  lfs       f2, 0x10(r29)
	  fdivs     f0, f4, f0
	  fmuls     f0, f3, f0
	  fmuls     f0, f1, f0
	  fadds     f0, f3, f0
	  fmuls     f0, f2, f0
	  stfs      f0, 0x10(r29)
	  stfs      f1, 0x14(r29)
	  lfs       f0, 0xA0(r30)
	  stfs      f0, 0x18(r29)
	  stfs      f3, 0x1C(r29)
	  lfs       f0, -0x68D0(r2)
	  stfs      f0, 0x38(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  stfs      f0, 0x44(r1)
	  stfs      f0, 0x40(r1)
	  stfs      f0, 0x3C(r1)
	  stw       r30, 0x58(r1)
	  lwz       r3, 0x438(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3038(r13)
	  addi      r5, r30, 0x94
	  li        r4, 0x104
	  bl        -0x2E058
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D2480
 * Size:	000154
 */
void PikiBubbleState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x40(r1)
	  addi      r30, r3, 0
	  lfs       f1, 0x1C(r3)
	  lfs       f2, 0x18(r3)
	  mr        r3, r31
	  bl        -0x660C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r30)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x14(r30)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  lfs       f0, 0x10(r30)
	  lfs       f1, -0x68D0(r2)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x84
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x6
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x13C

	.loc_0x84:
	  lfs       f0, 0x14(r30)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x13C
	  bl        0x145B60
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x3C(r1)
	  lis       r31, 0x4330
	  lfs       f2, -0x68E4(r2)
	  stw       r31, 0x38(r1)
	  lfs       f0, -0x68E8(r2)
	  lfd       f3, 0x38(r1)
	  lfs       f1, -0x6890(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  bl        0x145B20
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x68D8(r2)
	  stw       r0, 0x34(r1)
	  lfs       f5, -0x68E4(r2)
	  stw       r31, 0x30(r1)
	  lfs       f4, -0x68E8(r2)
	  lfd       f0, 0x30(r1)
	  lfs       f1, -0x6884(r2)
	  fsubs     f6, f0, f2
	  lfs       f0, -0x6880(r2)
	  lfs       f2, -0x68C8(r2)
	  lfs       f3, 0x18(r30)
	  fdivs     f5, f6, f5
	  fmuls     f4, f4, f5
	  fmuls     f1, f1, f4
	  fdivs     f0, f1, f0
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x18(r30)
	  lfs       f1, 0x18(r30)
	  bl        -0x9A01C
	  stfs      f1, 0x18(r30)
	  lfs       f1, 0x1C(r30)
	  lfs       f0, -0x687C(r2)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x1C(r30)

	.loc_0x13C:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D25D4
 * Size:	000080
 */
void PikiBubbleState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  addi      r3, r1, 0x10
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x10(r1)
	  addi      r5, r1, 0x1C
	  lfs       f1, 0x14(r1)
	  li        r4, 0x25
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x18(r1)
	  li        r6, 0
	  stfs      f1, 0x20(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x24(r1)
	  bl        0xCA510
	  lwz       r3, 0x438(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D2654
 * Size:	00004C
 */
PikiFiredState::PikiFiredState()
    : PikiState(PIKISTATE_Fired, "FIRED")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x9
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3F1C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6280
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D26A0
 * Size:	0000E4
 */
void PikiFiredState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  mr        r30, r4
	  stw       r29, 0x3C(r1)
	  addi      r29, r3, 0
	  addi      r3, r30, 0
	  lwz       r5, 0x504(r4)
	  li        r4, 0
	  bl        -0x5500
	  addi      r3, r1, 0x20
	  li        r4, 0x45
	  bl        0x4C880
	  addi      r31, r3, 0
	  addi      r3, r1, 0x28
	  li        r4, 0x45
	  bl        0x4C870
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  bl        -0x7D20
	  mr        r3, r30
	  bl        -0x7AF4
	  lwz       r3, 0x224(r30)
	  lfs       f0, 0x3E8(r3)
	  stfs      f0, 0x10(r29)
	  bl        0x145960
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x34(r1)
	  lis       r0, 0x4330
	  lfs       f0, -0x68E4(r2)
	  stw       r0, 0x30(r1)
	  lfs       f3, -0x68E8(r2)
	  lfd       f2, 0x30(r1)
	  lfs       f1, -0x68CC(r2)
	  fsubs     f4, f2, f4
	  lfs       f2, 0x10(r29)
	  fdivs     f0, f4, f0
	  fmuls     f0, f3, f0
	  fmuls     f0, f1, f0
	  fadds     f0, f3, f0
	  fmuls     f0, f2, f0
	  stfs      f0, 0x10(r29)
	  stfs      f1, 0x14(r29)
	  lfs       f0, 0xA0(r30)
	  stfs      f0, 0x18(r29)
	  stfs      f3, 0x1C(r29)
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D2784
 * Size:	000154
 */
void PikiFiredState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x40(r1)
	  addi      r30, r3, 0
	  lfs       f1, 0x1C(r3)
	  lfs       f2, 0x18(r3)
	  mr        r3, r31
	  bl        -0x6910
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r30)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x14(r30)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  lfs       f0, 0x10(r30)
	  lfs       f1, -0x68D0(r2)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x84
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x6
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x13C

	.loc_0x84:
	  lfs       f0, 0x14(r30)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x13C
	  bl        0x14585C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x3C(r1)
	  lis       r31, 0x4330
	  lfs       f2, -0x68E4(r2)
	  stw       r31, 0x38(r1)
	  lfs       f0, -0x68E8(r2)
	  lfd       f3, 0x38(r1)
	  lfs       f1, -0x6890(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  bl        0x14581C
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x68D8(r2)
	  stw       r0, 0x34(r1)
	  lfs       f5, -0x68E4(r2)
	  stw       r31, 0x30(r1)
	  lfs       f4, -0x68E8(r2)
	  lfd       f0, 0x30(r1)
	  lfs       f1, -0x6884(r2)
	  fsubs     f6, f0, f2
	  lfs       f0, -0x6880(r2)
	  lfs       f2, -0x68C8(r2)
	  lfs       f3, 0x18(r30)
	  fdivs     f5, f6, f5
	  fmuls     f4, f4, f5
	  fmuls     f1, f1, f4
	  fdivs     f0, f1, f0
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x18(r30)
	  lfs       f1, 0x18(r30)
	  bl        -0x9A320
	  stfs      f1, 0x18(r30)
	  lfs       f1, 0x1C(r30)
	  lfs       f0, -0x687C(r2)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x1C(r30)

	.loc_0x13C:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D28D8
 * Size:	000004
 */
void PikiFiredState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D28DC
 * Size:	000050
 */
PikiSwallowedState::PikiSwallowedState()
    : PikiState(PIKISTATE_Swallowed, "SWALLOWED")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x8
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r4, 0x5DC4
	  subi      r5, r5, 0x7318
	  stw       r0, 0x0(r3)
	  lis       r4, 0x802C
	  subi      r0, r4, 0x6318
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D292C
 * Size:	000010
 */
void PikiSwallowedState::init(Piki*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0xC8(r4)
	  ori       r0, r0, 0x800
	  stw       r0, 0xC8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D293C
 * Size:	000104
 */
void PikiSwallowedState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0xC8(r4)
	  rlwinm.   r0,r0,0,16,16
	  bne-      .loc_0xA4
	  lwz       r3, 0x4F8(r31)
	  lbz       r0, 0x19(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x84
	  lwz       r3, 0x4F8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x84
	  lwz       r3, 0x4F8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x84:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xEC

	.loc_0xA4:
	  lwz       r3, 0x184(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xEC
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xEC
	  mr        r3, r31
	  bl        -0x429EC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0xEC:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D2A40
 * Size:	000018
 */
void PikiSwallowedState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x4A4(r4)
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,21,19
	  stw       r0, 0xC8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D2A58
 * Size:	00004C
 */
PikiBulletState::PikiBulletState()
    : PikiState(PIKISTATE_Bullet, "BULLET")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x1B
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3F14
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x63B4
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D2AA4
 * Size:	000070
 */
void PikiBulletState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r4, 0
	  li        r4, 0x22
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  addi      r3, r1, 0x10
	  bl        0x4C48C
	  addi      r31, r3, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x22
	  bl        0x4C47C
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  bl        -0x8114
	  lfs       f0, -0x68D0(r2)
	  stfs      f0, 0x10(r29)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D2B14
 * Size:	0003F0
 */
void PikiBulletState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stfd      f29, 0xD0(r1)
	  stfd      f28, 0xC8(r1)
	  stmw      r27, 0xB4(r1)
	  addi      r30, r3, 0
	  addi      r31, r4, 0
	  lwz       r28, 0x3160(r13)
	  lwz       r12, 0x0(r28)
	  addi      r3, r28, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f29, -0x68D0(r2)
	  mr        r27, r3
	  lfd       f30, -0x68A8(r2)
	  lfd       f31, -0x68A0(r2)
	  lfs       f28, -0x6888(r2)
	  b         .loc_0x1F0

	.loc_0x58:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x80
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x9C

	.loc_0x80:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x9C:
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D4
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D4
	  lwz       r0, 0xC8(r29)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x1D4
	  lfs       f3, 0x98(r29)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x94(r29)
	  lfs       f0, 0x94(r31)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x9C(r29)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x9C(r31)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f29
	  ble-      .loc_0x170
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0x68(r1)
	  lfs       f2, 0x68(r1)

	.loc_0x170:
	  fcmpo     cr0, f2, f28
	  bge-      .loc_0x1D4
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0xD950
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0x8
	  addi      r4, r29, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0xEF98
	  li        r0, 0x2
	  sth       r0, 0x4FC(r31)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  lwz       r12, 0x0(r30)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3CC

	.loc_0x1D4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x1F0:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x218
	  li        r0, 0x1
	  b         .loc_0x244

	.loc_0x218:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x240
	  li        r0, 0x1
	  b         .loc_0x244

	.loc_0x240:
	  li        r0, 0

	.loc_0x244:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x58
	  lfs       f1, 0x70(r31)
	  lfs       f0, 0x74(r31)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x78(r31)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x68D0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x2D0
	  fsqrte    f1, f4
	  lfd       f3, -0x68A8(r2)
	  lfd       f2, -0x68A0(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x60(r1)
	  lfs       f4, 0x60(r1)

	.loc_0x2D0:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r30)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f4, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r30)
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x6878(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x328
	  lwz       r5, 0x504(r31)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x5C4C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3CC

	.loc_0x328:
	  lfs       f1, 0x70(r31)
	  lfs       f0, 0x74(r31)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r31)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC521C
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x37C
	  lfs       f0, 0x70(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x70(r31)
	  lfs       f0, 0x74(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x74(r31)
	  lfs       f0, 0x78(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x78(r31)

	.loc_0x37C:
	  mr        r3, r31
	  lfs       f1, -0x68E8(r2)
	  bl        -0x7134
	  lfs       f0, 0x70(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x74(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x78(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x84(r1)
	  lwz       r3, 0x7C(r1)
	  lwz       r0, 0x80(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x84(r1)
	  stw       r0, 0x78(r31)

	.loc_0x3CC:
	  lmw       r27, 0xB4(r1)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lfd       f29, 0xD0(r1)
	  lfd       f28, 0xC8(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D2F04
 * Size:	000060
 */
void PikiBulletState::procWallMsg(Piki*, MsgWall*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r5, 0x504(r4)
	  li        r4, 0x1
	  bl        -0x5D60
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D2F64
 * Size:	000004
 */
void PikiBulletState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D2F68
 * Size:	00004C
 */
PikiFlickState::PikiFlickState()
    : PikiState(PIKISTATE_Flick, "FLICK")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x16
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3F0C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x644C
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D2FB4
 * Size:	000168
 */
void PikiFlickState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x4C(r1)
	  mr        r29, r4
	  sth       r0, 0x10(r3)
	  lfs       f0, 0x49C(r4)
	  stfs      f0, 0x18(r3)
	  bl        0x14508C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x44(r1)
	  lis       r31, 0x4330
	  lfs       f3, -0x68E4(r2)
	  stw       r31, 0x40(r1)
	  lfs       f2, -0x68E8(r2)
	  lfd       f1, 0x40(r1)
	  lfs       f0, -0x68C8(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x68CC(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  stfs      f0, 0x1C(r30)
	  bl        0x145048
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x3C(r1)
	  lfs       f3, -0x68E4(r2)
	  stw       r31, 0x38(r1)
	  lfs       f2, -0x68E8(r2)
	  lfd       f1, 0x38(r1)
	  lfs       f0, -0x688C(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6888(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x74(r29)
	  bl        0x145008
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x68D8(r2)
	  stw       r0, 0x34(r1)
	  lfs       f2, -0x68E4(r2)
	  stw       r31, 0x30(r1)
	  lfs       f1, -0x68E8(r2)
	  lfd       f0, 0x30(r1)
	  lfs       f4, 0x498(r29)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x68CC(r2)
	  fmuls     f0, f0, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fadds     f0, f4, f0
	  stfs      f0, 0x20(r30)
	  lwz       r3, 0x4F8(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x54(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x11C
	  addi      r30, r30, 0x2B8

	.loc_0x11C:
	  addi      r3, r1, 0x1C
	  li        r4, 0x1F
	  bl        0x4BE80
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x24
	  li        r4, 0x1F
	  bl        0x4BEA0
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x8724
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D311C
 * Size:	0001A0
 */
void PikiFlickState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  stw       r29, 0x44(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x40(r1)
	  mr        r28, r3
	  lhz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x74
	  lfs       f31, 0x20(r28)
	  lfs       f1, 0x18(r28)
	  bl        0x148B90
	  fneg      f31, f31
	  fmuls     f0, f31, f1
	  stfs      f0, 0x70(r29)
	  lfs       f1, 0x18(r28)
	  bl        0x1489E8
	  fmuls     f0, f31, f1
	  stfs      f0, 0x78(r29)
	  lfs       f1, 0xA0(r29)
	  lfs       f0, 0x1C(r28)
	  fadds     f1, f1, f0
	  bl        -0x9ABFC
	  stfs      f1, 0xA0(r29)
	  b         .loc_0x17C

	.loc_0x74:
	  cmplwi    r0, 0x2
	  bne-      .loc_0x148
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x14(r28)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r28)
	  lfs       f1, 0x14(r28)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0xAC
	  lbz       r0, 0x4A0(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x110

	.loc_0xAC:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x110
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0xD8
	  addi      r30, r30, 0x2B8

	.loc_0xD8:
	  addi      r3, r1, 0x2C
	  li        r4, 0x20
	  bl        0x4BD5C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x34
	  li        r4, 0x20
	  bl        0x4BD7C
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x8848
	  li        r0, 0x3
	  sth       r0, 0x10(r28)

	.loc_0x110:
	  lfs       f1, -0x6874(r2)
	  lfs       f0, 0x70(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x70(r29)
	  lfs       f0, 0x78(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x78(r29)
	  lfs       f0, -0x3F04(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x3F00(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x3EFC(r13)
	  stfs      f0, 0xAC(r29)
	  b         .loc_0x17C

	.loc_0x148:
	  lfs       f1, -0x6874(r2)
	  lfs       f0, 0x70(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x70(r29)
	  lfs       f0, 0x78(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x78(r29)
	  lfs       f0, -0x3EF8(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x3EF4(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x3EF0(r13)
	  stfs      f0, 0xAC(r29)

	.loc_0x17C:
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  lwz       r28, 0x40(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D32BC
 * Size:	000294
 */
void PikiFlickState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stfd      f30, 0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x60(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x5C(r1)
	  stw       r28, 0x58(r1)
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x40
	  b         .loc_0x26C

	.loc_0x40:
	  lhz       r0, 0x10(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x98
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x5C
	  addi      r28, r28, 0x2B8

	.loc_0x5C:
	  addi      r3, r1, 0x3C
	  li        r4, 0x1E
	  bl        0x4BC38
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x44
	  li        r4, 0x1E
	  bl        0x4BC58
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0x896C
	  li        r0, 0x1
	  sth       r0, 0x10(r30)
	  b         .loc_0x26C

	.loc_0x98:
	  cmplwi    r0, 0x1
	  bne-      .loc_0x128
	  li        r0, 0x2
	  sth       r0, 0x10(r30)
	  lwz       r4, 0x224(r31)
	  lfs       f30, 0x328(r4)
	  lfs       f31, 0x338(r4)
	  bl        0x144D00
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x54(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x68E4(r2)
	  fsubs     f0, f30, f31
	  stw       r0, 0x50(r1)
	  lfs       f1, -0x68E8(r2)
	  lfd       f3, 0x50(r1)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fadds     f0, f31, f0
	  stfs      f0, 0x14(r30)
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x26C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x7
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x26C

	.loc_0x128:
	  bl        0x144C8C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x54(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x68E4(r2)
	  stw       r0, 0x50(r1)
	  lfs       f1, -0x68E8(r2)
	  lfd       f3, 0x50(r1)
	  lfs       f0, -0x6870(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1F8
	  lwz       r3, 0x520(r31)
	  cmpwi     r3, 0x1
	  blt-      .loc_0x1F8
	  subi      r0, r3, 0x1
	  stw       r0, 0x520(r31)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r4, 0x520(r31)
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x464
	  li        r4, 0x1B
	  li        r6, 0
	  li        r7, 0
	  bl        0xC96D8
	  cmplwi    r3, 0
	  beq-      .loc_0x1E0
	  lfs       f0, -0x3EEC(r13)
	  lfs       f1, -0x3EE8(r13)
	  stfs      f0, 0x30(r1)
	  lfs       f0, -0x3EE4(r13)
	  stfs      f1, 0x34(r1)
	  stfs      f0, 0x38(r1)
	  lwz       r4, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x38(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0x1E0:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x464
	  li        r4, 0x1C
	  li        r6, 0
	  li        r7, 0
	  bl        0xC9688

	.loc_0x1F8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x250
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0xE194
	  lwz       r5, 0x504(r31)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x631C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x1D
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x26C

	.loc_0x250:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x26C:
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lfd       f30, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  lwz       r28, 0x58(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D3550
 * Size:	0000F8
 */
void PikiFlickState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xE4
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,16,16
	  bne-      .loc_0xE4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x88
	  lbz       r0, 0x4A0(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x88
	  lwz       r5, 0x504(r31)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x63F4
	  mr        r3, r31
	  bl        -0x42D50
	  li        r0, 0
	  stb       r0, 0x4A0(r31)
	  b         .loc_0xE4

	.loc_0x88:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD8
	  lwz       r3, 0x4F8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD8
	  lwz       r3, 0x4F8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE4

	.loc_0xD8:
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0xE2EC

	.loc_0xE4:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D3648
 * Size:	00004C
 */
PikiFlownState::PikiFlownState()
    : PikiState(PIKISTATE_Flown, "FLOWN")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x19
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3EE0
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x64E4
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D3694
 * Size:	000124
 */
void PikiFlownState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  mr        r29, r4
	  stw       r28, 0x38(r1)
	  addi      r28, r3, 0
	  sth       r0, 0x20(r3)
	  lfs       f1, 0x70(r4)
	  lfs       f2, 0x78(r4)
	  bl        0x148330
	  stfs      f1, 0x14(r28)
	  bl        0x1449A0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x34(r1)
	  lis       r31, 0x4330
	  lfs       f3, -0x68E4(r2)
	  stw       r31, 0x30(r1)
	  lfs       f2, -0x68E8(r2)
	  lfd       f1, 0x30(r1)
	  lfs       f0, -0x68C8(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x68CC(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  stfs      f0, 0x18(r28)
	  bl        0x14495C
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x68D8(r2)
	  stw       r0, 0x2C(r1)
	  cmplwi    r29, 0
	  lfs       f2, -0x68E4(r2)
	  mr        r30, r29
	  stw       r31, 0x28(r1)
	  lfs       f1, -0x68E8(r2)
	  lfd       f0, 0x28(r1)
	  lfs       f4, 0x498(r29)
	  fsubs     f3, f0, f3
	  lfs       f0, -0x68CC(r2)
	  fmuls     f0, f0, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fadds     f0, f4, f0
	  stfs      f0, 0x1C(r28)
	  beq-      .loc_0xD4
	  addi      r30, r30, 0x2B8

	.loc_0xD4:
	  addi      r3, r1, 0x18
	  li        r4, 0x1F
	  bl        0x4B7E8
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x20
	  li        r4, 0x1F
	  bl        0x4B808
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x8DBC
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D37B8
 * Size:	000098
 */
void PikiFlownState::procBounceMsg(Piki*, MsgBounce*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x28(r1)
	  mr        r28, r3
	  lhz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x78
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x40
	  addi      r30, r30, 0x2B8

	.loc_0x40:
	  addi      r3, r1, 0x14
	  li        r4, 0x1E
	  bl        0x4B758
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x1E
	  bl        0x4B778
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x8E4C
	  li        r0, 0x1
	  sth       r0, 0x20(r28)

	.loc_0x78:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D3850
 * Size:	000170
 */
void PikiFlownState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  stw       r29, 0x44(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x40(r1)
	  mr        r28, r3
	  lhz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x48
	  lfs       f1, 0xA0(r29)
	  lfs       f0, 0x18(r28)
	  fadds     f1, f1, f0
	  bl        -0x9B304
	  stfs      f1, 0xA0(r29)
	  b         .loc_0x150

	.loc_0x48:
	  cmplwi    r0, 0x2
	  bne-      .loc_0x11C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r28)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r28)
	  lfs       f1, 0x10(r28)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0x80
	  lbz       r0, 0x4A0(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0xE4

	.loc_0x80:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE4
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0xAC
	  addi      r30, r30, 0x2B8

	.loc_0xAC:
	  addi      r3, r1, 0x2C
	  li        r4, 0x20
	  bl        0x4B654
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x34
	  li        r4, 0x20
	  bl        0x4B674
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x8F50
	  li        r0, 0x3
	  sth       r0, 0x20(r28)

	.loc_0xE4:
	  lfs       f1, -0x6874(r2)
	  lfs       f0, 0x70(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x70(r29)
	  lfs       f0, 0x78(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x78(r29)
	  lfs       f0, -0x3ED8(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x3ED4(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x3ED0(r13)
	  stfs      f0, 0xAC(r29)
	  b         .loc_0x150

	.loc_0x11C:
	  lfs       f1, -0x6874(r2)
	  lfs       f0, 0x70(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x70(r29)
	  lfs       f0, 0x78(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x78(r29)
	  lfs       f0, -0x3ECC(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x3EC8(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x3EC4(r13)
	  stfs      f0, 0xAC(r29)

	.loc_0x150:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  lwz       r28, 0x40(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D39C0
 * Size:	000230
 */
void PikiFlownState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stfd      f30, 0x50(r1)
	  stw       r31, 0x4C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x38
	  b         .loc_0x210

	.loc_0x38:
	  lhz       r0, 0x20(r30)
	  cmplwi    r0, 0x1
	  bne-      .loc_0xCC
	  li        r0, 0x2
	  sth       r0, 0x20(r30)
	  lwz       r4, 0x224(r31)
	  lfs       f30, 0x328(r4)
	  lfs       f31, 0x338(r4)
	  bl        0x144658
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x68E4(r2)
	  fsubs     f0, f30, f31
	  stw       r0, 0x40(r1)
	  lfs       f1, -0x68E8(r2)
	  lfd       f3, 0x40(r1)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fadds     f0, f31, f0
	  stfs      f0, 0x10(r30)
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x210
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x7
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x210

	.loc_0xCC:
	  bl        0x1445E4
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x68E4(r2)
	  stw       r0, 0x40(r1)
	  lfs       f1, -0x68E8(r2)
	  lfd       f3, 0x40(r1)
	  lfs       f0, -0x6870(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x19C
	  lwz       r3, 0x520(r31)
	  cmpwi     r3, 0x1
	  blt-      .loc_0x19C
	  subi      r0, r3, 0x1
	  stw       r0, 0x520(r31)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r4, 0x520(r31)
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x464
	  li        r4, 0x1B
	  li        r6, 0
	  li        r7, 0
	  bl        0xC9030
	  cmplwi    r3, 0
	  beq-      .loc_0x184
	  lfs       f0, -0x3EC0(r13)
	  lfs       f1, -0x3EBC(r13)
	  stfs      f0, 0x30(r1)
	  lfs       f0, -0x3EB8(r13)
	  stfs      f1, 0x34(r1)
	  stfs      f0, 0x38(r1)
	  lwz       r4, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x38(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0x184:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x464
	  li        r4, 0x1C
	  li        r6, 0
	  li        r7, 0
	  bl        0xC8FE0

	.loc_0x19C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1F4
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0xE83C
	  lwz       r5, 0x504(r31)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x69C4
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x1D
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x210

	.loc_0x1F4:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x210:
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lfd       f30, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D3BF0
 * Size:	0000A0
 */
void PikiFlownState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x8C
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,16,16
	  bne-      .loc_0x8C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x80
	  lbz       r0, 0x4A0(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x80
	  lwz       r5, 0x504(r31)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x6A94
	  li        r0, 0
	  stb       r0, 0x4A0(r31)
	  b         .loc_0x8C

	.loc_0x80:
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        -0xE934

	.loc_0x8C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D3C90
 * Size:	000050
 */
PikiFallMeckState::PikiFallMeckState()
    : PikiState(PIKISTATE_FallMeck, "FALLMECK")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x1E
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r4, 0x5DC4
	  subi      r5, r5, 0x730C
	  stw       r0, 0x0(r3)
	  lis       r4, 0x802C
	  subi      r0, r4, 0x657C
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D3CE0
 * Size:	000084
 */
void PikiFallMeckState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  addi      r30, r29, 0
	  beq-      .loc_0x28
	  addi      r30, r30, 0x2B8

	.loc_0x28:
	  addi      r3, r1, 0x10
	  li        r4, 0x1D
	  bl        0x4B248
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x1D
	  bl        0x4B268
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x935C
	  mr        r3, r29
	  bl        -0x43D20
	  li        r0, 0
	  stw       r0, 0x4A4(r29)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D3D64
 * Size:	000004
 */
void PikiFallMeckState::exec(Piki*) { }

/*
 * --INFO--
 * Address:	800D3D68
 * Size:	000288
 */
void PikiFallMeckState::procBounceMsg(Piki*, MsgBounce*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stfd      f30, 0x58(r1)
	  stmw      r27, 0x44(r1)
	  mr        r28, r4
	  addi      r27, r3, 0
	  li        r30, -0x1
	  lwz       r0, 0x28C(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C
	  mr        r3, r0
	  bl        0x422E4
	  mr        r30, r3

	.loc_0x3C:
	  mr        r3, r28
	  bl        -0xBF38
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1D8
	  addi      r3, r28, 0x94
	  bl        -0xD860
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D8
	  lwz       r3, 0x28C(r28)
	  bl        0x422E0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1D8
	  cmpwi     r30, 0x5
	  beq-      .loc_0x1D8
	  li        r30, 0x1
	  lwz       r3, 0x30AC(r13)
	  stb       r30, 0x30A8(r13)
	  li        r4, 0xF
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  li        r31, 0
	  mr.       r29, r3
	  stb       r31, 0x30A8(r13)
	  beq-      .loc_0x1D8
	  lfs       f0, 0x94(r28)
	  li        r4, 0x1
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x98(r28)
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x9C(r28)
	  stfs      f0, 0x34(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x2C(r1)
	  lfs       f2, 0x34(r1)
	  bl        -0x6BF30
	  stfs      f1, 0x30(r1)
	  addi      r5, r1, 0x2C
	  li        r4, 0x32
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        0xC8CE8
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x2C
	  li        r4, 0x33
	  li        r6, 0
	  li        r7, 0
	  bl        0xC8CD0
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r1, 0x2C
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lhz       r4, 0x510(r28)
	  bl        0x18C14
	  bl        0x1441E0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  stw       r0, 0x38(r1)
	  lfs       f2, -0x68E8(r2)
	  lfd       f1, 0x38(r1)
	  lfs       f0, -0x68C8(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x68C0(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f30, f1, f0
	  fmr       f1, f30
	  bl        0x147C80
	  lfs       f0, -0x686C(r2)
	  fmuls     f31, f0, f1
	  fmr       f1, f30
	  bl        0x147E04
	  lfs       f0, -0x686C(r2)
	  addi      r3, r29, 0
	  li        r4, 0
	  fmuls     f0, f0, f1
	  stfs      f0, 0x70(r29)
	  lfs       f0, -0x3EB4(r13)
	  stfs      f0, 0x74(r29)
	  stfs      f31, 0x78(r29)
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r31, 0x3E0(r29)
	  addi      r4, r29, 0
	  li        r5, 0x5
	  lwz       r3, 0x2E8(r29)
	  bl        -0x567D0
	  stb       r30, 0x584(r28)
	  addi      r3, r28, 0
	  li        r4, 0x1
	  bl        -0x49258
	  b         .loc_0x26C

	.loc_0x1D8:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  addi      r4, r28, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  bl        -0xC0F0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x26C
	  lwz       r30, 0x2AC(r28)
	  mr        r3, r30
	  bl        -0x495A0
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0xE
	  bne-      .loc_0x26C
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x26C
	  li        r0, 0xA
	  stw       r0, 0x20(r1)
	  li        r0, 0x1
	  addi      r4, r30, 0
	  stw       r0, 0x24(r1)
	  addi      r5, r1, 0x20
	  stw       r0, 0x2D0(r30)
	  lwz       r3, 0x2E8(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x26C:
	  lmw       r27, 0x44(r1)
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lfd       f30, 0x58(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D3FF0
 * Size:	000004
 */
void PikiFallMeckState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D3FF4
 * Size:	00004C
 */
PikiFallState::PikiFallState()
    : PikiState(PIKISTATE_Fall, "FALL")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x11
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3EB0
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6618
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4040
 * Size:	000088
 */
void PikiFallState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x30
	  addi      r30, r30, 0x2B8

	.loc_0x30:
	  addi      r3, r1, 0x10
	  li        r4, 0x1D
	  bl        0x4AEE0
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x1D
	  bl        0x4AF00
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x96C4
	  li        r0, 0
	  stw       r0, 0x10(r28)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D40C8
 * Size:	000004
 */
void PikiFallState::exec(Piki*) { }

/*
 * --INFO--
 * Address:	800D40CC
 * Size:	00007C
 */
void PikiFallState::procBounceMsg(Piki*, MsgBounce*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  mr.       r29, r4
	  stw       r0, 0x10(r3)
	  mr        r30, r29
	  beq-      .loc_0x30
	  addi      r30, r30, 0x2B8

	.loc_0x30:
	  addi      r3, r1, 0x14
	  li        r4, 0x1E
	  bl        0x4AE54
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x1E
	  bl        0x4AE74
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x9750
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4148
 * Size:	0000D4
 */
void PikiFallState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x28(r1)
	  addi      r28, r3, 0
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x38
	  b         .loc_0xB4

	.loc_0x38:
	  lwz       r0, 0x10(r28)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x90
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x54
	  addi      r30, r30, 0x2B8

	.loc_0x54:
	  addi      r3, r1, 0x14
	  li        r4, 0x20
	  bl        0x4ADB4
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x20
	  bl        0x4ADD4
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x97F0
	  li        r0, 0x2
	  stw       r0, 0x10(r28)
	  b         .loc_0xB4

	.loc_0x90:
	  cmpwi     r0, 0x2
	  bne-      .loc_0xB4
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  addi      r4, r29, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0xB4:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D421C
 * Size:	000004
 */
void PikiFallState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D4220
 * Size:	00005C
 */
PikiCliffState::PikiCliffState()
    : PikiState(PIKISTATE_Cliff, "CLIFF")
    , _1C(0.0f)
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x10
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3EA8
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x66B0
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  lfs       f0, -0x68D0(r2)
	  stfs      f0, 0x24(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D427C
 * Size:	000138
 */
void PikiCliffState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  mr        r29, r4
	  stw       r28, 0x38(r1)
	  mr        r28, r3
	  lwz       r4, 0x70(r4)
	  lwz       r0, 0x74(r29)
	  stw       r4, 0x1C(r3)
	  stw       r0, 0x20(r3)
	  lwz       r0, 0x78(r29)
	  stw       r0, 0x24(r3)
	  lfs       f1, 0x1C(r3)
	  lfs       f0, 0x20(r3)
	  lfs       f2, 0x24(r3)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC6698
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x90
	  lfs       f0, 0x1C(r28)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x1C(r28)
	  lfs       f0, 0x20(r28)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x20(r28)
	  lfs       f0, 0x24(r28)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x24(r28)

	.loc_0x90:
	  lfs       f0, -0x68E8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xA8
	  li        r0, 0
	  stw       r0, 0x18(r28)
	  b         .loc_0xB0

	.loc_0xA8:
	  li        r0, 0x1
	  stw       r0, 0x18(r28)

	.loc_0xB0:
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0xC0
	  addi      r30, r30, 0x2B8

	.loc_0xC0:
	  addi      r3, r1, 0x20
	  li        r4, 0xD
	  bl        0x4AC14
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x28
	  li        r4, 0xD
	  bl        0x4AC34
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x9990
	  lfs       f0, -0x3EA0(r13)
	  li        r0, 0
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x3E9C(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x3E98(r13)
	  stfs      f0, 0xAC(r29)
	  stw       r0, 0x10(r28)
	  lfs       f0, 0xA0(r29)
	  stfs      f0, 0x28(r28)
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D43B4
 * Size:	00003C
 */
void PikiCliffState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x28C(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x2C
	  lwz       r12, 0x0(r3)
	  li        r5, 0x11
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void PikiCliffState::startFall(Piki*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800D43F0
 * Size:	0001A4
 */
void PikiCliffState::nearEnough(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stfd      f30, 0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r4
	  lfs       f1, 0xA0(r4)
	  bl        0x147744
	  fmr       f31, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x1478CC
	  lwz       r3, 0x28C(r31)
	  li        r0, -0x1
	  lfsu      f3, 0x28(r3)
	  lfs       f5, -0x3E94(r13)
	  lfs       f2, 0x4(r3)
	  fmuls     f3, f3, f1
	  lfs       f4, 0x8(r3)
	  fmuls     f2, f2, f5
	  lfs       f0, -0x6894(r2)
	  fmuls     f4, f4, f31
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x6C
	  li        r0, 0

	.loc_0x6C:
	  lwz       r3, 0x28C(r31)
	  lfsu      f3, 0x38(r3)
	  lfs       f2, 0x4(r3)
	  fmuls     f3, f3, f1
	  lfs       f4, 0x8(r3)
	  fmuls     f2, f2, f5
	  fmuls     f4, f4, f31
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x9C
	  li        r0, 0x1

	.loc_0x9C:
	  lwz       r3, 0x28C(r31)
	  lfsu      f3, 0x48(r3)
	  lfs       f2, 0x4(r3)
	  fmuls     f3, f3, f1
	  lfs       f4, 0x8(r3)
	  fmuls     f2, f2, f5
	  fmuls     f4, f4, f31
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0xCC
	  li        r0, 0x2

	.loc_0xCC:
	  rlwinm    r3,r0,4,0,27
	  lwz       r0, 0x28C(r31)
	  addi      r3, r3, 0x28
	  lfs       f6, 0x94(r31)
	  add       r3, r0, r3
	  lfs       f30, 0x98(r31)
	  lfs       f2, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f4, f2, f6
	  lfs       f5, 0x8(r3)
	  fmuls     f3, f0, f30
	  lfs       f7, 0x9C(r31)
	  lfs       f2, 0xC(r3)
	  fmuls     f5, f5, f7
	  lfs       f0, -0x6890(r2)
	  fadds     f3, f4, f3
	  lfs       f4, 0x270(r31)
	  fadds     f0, f0, f4
	  fadds     f3, f5, f3
	  fsubs     f2, f3, f2
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x184
	  fmuls     f1, f1, f4
	  lfs       f2, -0x6898(r2)
	  fmuls     f0, f31, f4
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  fmuls     f1, f2, f1
	  fmuls     f0, f2, f0
	  fadds     f1, f6, f1
	  fadds     f2, f7, f0
	  bl        -0x6C634
	  mr        r3, r31
	  fmr       f31, f1
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, -0x6868(r2)
	  fsubs     f0, f30, f31
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f0, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x184
	  li        r3, 0x1
	  b         .loc_0x188

	.loc_0x184:
	  li        r3, 0

	.loc_0x188:
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lfd       f30, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4594
 * Size:	0004A4
 */
void PikiCliffState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stfd      f31, 0x98(r1)
	  stw       r31, 0x94(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x90(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x8C(r1)
	  stw       r28, 0x88(r1)
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x190
	  bge-      .loc_0x480
	  cmpwi     r0, 0
	  beq-      .loc_0x48
	  b         .loc_0x480

	.loc_0x48:
	  lwz       r0, 0x10(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x480
	  bge-      .loc_0x68
	  cmpwi     r0, 0
	  beq-      .loc_0x74
	  bge-      .loc_0x170
	  b         .loc_0x480

	.loc_0x68:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x480
	  b         .loc_0x124

	.loc_0x74:
	  lwz       r0, 0x18(r30)
	  cmpwi     r0, 0x2
	  bge-      .loc_0x480
	  cmpwi     r0, 0
	  bge-      .loc_0x8C
	  b         .loc_0x480

	.loc_0x8C:
	  li        r0, 0x1
	  stw       r0, 0x10(r30)
	  bl        0x143A48
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x84(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x68E4(r2)
	  cmplwi    r31, 0
	  stw       r0, 0x80(r1)
	  lfs       f1, -0x68E8(r2)
	  mr        r28, r31
	  lfd       f3, 0x80(r1)
	  lfs       f0, -0x68C0(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x78(r1)
	  lwz       r3, 0x7C(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x14(r30)
	  beq-      .loc_0xF0
	  addi      r28, r28, 0x2B8

	.loc_0xF0:
	  addi      r3, r1, 0x64
	  li        r4, 0x3C
	  bl        0x4A8CC
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x6C
	  li        r4, 0x3C
	  bl        0x4A8EC
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0x9CD8
	  b         .loc_0x480

	.loc_0x124:
	  lwz       r0, 0x28C(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x150
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x11
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x480

	.loc_0x150:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x480

	.loc_0x170:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x480

	.loc_0x190:
	  lwz       r0, 0x10(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x41C
	  bge-      .loc_0x480
	  cmpwi     r0, 0x1
	  bge-      .loc_0x1AC
	  b         .loc_0x480

	.loc_0x1AC:
	  lwz       r3, 0x14(r30)
	  subi      r0, r3, 0x1
	  stw       r0, 0x14(r30)
	  lwz       r0, 0x14(r30)
	  cmpwi     r0, 0
	  bgt-      .loc_0x480
	  lwz       r0, 0x18(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x3A0
	  lwz       r0, 0x28C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x350
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x388
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x350
	  lfs       f1, -0x68C8(r2)
	  lfs       f0, 0x28(r30)
	  fadds     f1, f1, f0
	  bl        -0x9C208
	  cmplwi    r31, 0
	  stfs      f1, 0xA0(r31)
	  mr        r28, r31
	  beq-      .loc_0x214
	  addi      r28, r28, 0x2B8

	.loc_0x214:
	  addi      r3, r1, 0x54
	  li        r4, 0x3B
	  bl        0x4A7A8
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x5C
	  li        r4, 0x3B
	  bl        0x4A7C8
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0x9DFC
	  mr        r3, r31
	  lwz       r4, 0x28C(r31)
	  bl        -0x454A4
	  cmplwi    r3, 0
	  beq-      .loc_0x330
	  lfs       f3, 0x0(r3)
	  lfs       f2, 0x94(r31)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x98(r31)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x8(r3)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x9C(r31)
	  lwz       r12, 0x0(r31)
	  fmuls     f3, f4, f3
	  lfs       f0, 0xC(r3)
	  fadds     f1, f2, f1
	  lwz       r12, 0x5C(r12)
	  mr        r3, r31
	  mtlr      r12
	  fadds     f1, f3, f1
	  fsubs     f31, f1, f0
	  blrl
	  lfs       f0, -0x6864(r2)
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x310
	  lfs       f0, -0x6860(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x310
	  li        r0, 0x2
	  stw       r0, 0x10(r30)
	  bl        0x14381C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x7C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x68E4(r2)
	  stw       r0, 0x78(r1)
	  lfs       f1, -0x68E8(r2)
	  lfd       f3, 0x78(r1)
	  lfs       f0, -0x68C0(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x80(r1)
	  lwz       r3, 0x84(r1)
	  addi      r0, r3, 0x2
	  stw       r0, 0x14(r30)
	  b         .loc_0x480

	.loc_0x310:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x480

	.loc_0x330:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x480

	.loc_0x350:
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x364
	  addi      r28, r28, 0x2B8

	.loc_0x364:
	  addi      r3, r1, 0x40
	  li        r4, 0x3D
	  bl        0x4A658
	  addi      r31, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x38
	  li        r4, 0x3D
	  bl        0x4A678
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x9F4C
	  li        r0, 0x3
	  stw       r0, 0x10(r30)
	  b         .loc_0x480

	.loc_0x3A0:
	  lwz       r0, 0x28C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x3CC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x480

	.loc_0x3CC:
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x3E0
	  addi      r28, r28, 0x2B8

	.loc_0x3E0:
	  addi      r3, r1, 0x30
	  li        r4, 0x3D
	  bl        0x4A5DC
	  addi      r31, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x28
	  li        r4, 0x3D
	  bl        0x4A5FC
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0x9FC8
	  li        r0, 0x3
	  stw       r0, 0x10(r30)
	  b         .loc_0x480

	.loc_0x41C:
	  lwz       r3, 0x14(r30)
	  subi      r0, r3, 0x1
	  stw       r0, 0x14(r30)
	  lwz       r0, 0x14(r30)
	  cmpwi     r0, 0
	  bgt-      .loc_0x480
	  mr        r4, r31
	  lwz       r12, 0x0(r31)
	  addi      r3, r1, 0x48
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0x48(r1)
	  mr        r3, r30
	  lwz       r0, 0x4C(r1)
	  addi      r4, r31, 0
	  li        r5, 0x11
	  stw       r6, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x50(r1)
	  stw       r0, 0x9C(r31)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x480:
	  lwz       r0, 0xA4(r1)
	  lfd       f31, 0x98(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  lwz       r29, 0x8C(r1)
	  lwz       r28, 0x88(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4A38
 * Size:	000004
 */
void PikiCliffState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D4A3C
 * Size:	00004C
 */
PikiGoHangState::PikiGoHangState()
    : PikiState(PIKISTATE_GoHang, "GOHANG")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0xB
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3E90
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6748
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4A88
 * Size:	00005C
 */
void PikiGoHangState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r3, r1, 0x10
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  li        r4, 0
	  bl        0x4A4B0
	  addi      r31, r3, 0
	  addi      r3, r1, 0x18
	  li        r4, 0
	  bl        0x4A4A0
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  bl        -0xA0F0
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4AE4
 * Size:	000174
 */
void PikiGoHangState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF0(r1)
	  stfd      f31, 0xE8(r1)
	  stfd      f30, 0xE0(r1)
	  stfd      f29, 0xD8(r1)
	  stw       r31, 0xD4(r1)
	  mr        r31, r4
	  stw       r30, 0xD0(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x504(r4)
	  lis       r4, 0x7268
	  addi      r4, r4, 0x6E64
	  lwz       r3, 0x220(r5)
	  bl        -0x4B40C
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x94(r31)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x98(r31)
	  fsubs     f31, f3, f2
	  lfs       f2, 0xC(r3)
	  fsubs     f30, f1, f0
	  lfs       f0, 0x9C(r31)
	  fmuls     f1, f31, f31
	  fsubs     f29, f2, f0
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC6F18
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x90
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x90:
	  lwz       r3, 0x504(r31)
	  lfs       f2, -0x68C0(r2)
	  lwz       r3, 0x224(r3)
	  lfs       f3, -0x68E8(r2)
	  lfs       f0, 0x1C8(r3)
	  fmuls     f0, f2, f0
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xB4
	  fmr       f3, f2

	.loc_0xB4:
	  lwz       r3, 0x224(r31)
	  lfs       f2, 0x78(r3)
	  fmuls     f1, f31, f2
	  fmuls     f0, f30, f2
	  fmuls     f2, f29, f2
	  stfs      f1, 0x80(r1)
	  lfs       f1, 0x80(r1)
	  stfs      f1, 0x98(r1)
	  stfs      f0, 0x9C(r1)
	  stfs      f2, 0xA0(r1)
	  lfs       f0, 0x98(r1)
	  fmuls     f0, f0, f3
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x70(r1)
	  stfs      f0, 0xA4(r1)
	  lfs       f0, 0x9C(r1)
	  fmuls     f0, f0, f3
	  stfs      f0, 0xA8(r1)
	  lfs       f0, 0xA0(r1)
	  fmuls     f0, f0, f3
	  stfs      f0, 0xAC(r1)
	  lwz       r3, 0xA4(r1)
	  lwz       r0, 0xA8(r1)
	  stw       r3, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0xAC(r1)
	  stw       r0, 0xAC(r31)
	  lwz       r3, 0x504(r31)
	  lwz       r3, 0xADC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x150
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x150:
	  lwz       r0, 0xF4(r1)
	  lfd       f31, 0xE8(r1)
	  lfd       f30, 0xE0(r1)
	  lfd       f29, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  addi      r1, r1, 0xF0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4C58
 * Size:	000004
 */
void PikiGoHangState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D4C5C
 * Size:	00004C
 */
PikiHangedState::PikiHangedState()
    : PikiState(PIKISTATE_Hanged, "HANGED")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0xC
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3E88
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x67E0
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4CA8
 * Size:	000038
 */
void PikiHangedState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r5)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x20
	  b         .loc_0x28

	.loc_0x20:
	  li        r3, 0x144
	  bl        -0x2F8F0

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4CE0
 * Size:	0000B4
 */
void PikiHangedState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  lfs       f0, -0x685C(r2)
	  mr        r30, r29
	  stfs      f0, 0x47C(r4)
	  beq-      .loc_0x30
	  addi      r30, r30, 0x2B8

	.loc_0x30:
	  addi      r3, r1, 0x10
	  li        r4, 0x1C
	  bl        0x4A240
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x1C
	  bl        0x4A260
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xA364
	  li        r0, 0
	  stw       r0, 0x1A4(r29)
	  lfs       f0, -0x3E80(r13)
	  stfs      f0, 0x70(r29)
	  lfs       f0, -0x3E7C(r13)
	  stfs      f0, 0x74(r29)
	  lfs       f0, -0x3E78(r13)
	  stfs      f0, 0x78(r29)
	  lfs       f0, -0x3E74(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x3E70(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x3E6C(r13)
	  stfs      f0, 0xAC(r29)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4D94
 * Size:	000044
 */
void PikiHangedState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x504(r4)
	  lwz       r5, 0xADC(r5)
	  lwz       r0, 0x4(r5)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x34
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4DD8
 * Size:	000024
 */
void PikiHangedState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x144
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x2F9D8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4DFC
 * Size:	000050
 */
PikiWaterHangedState::PikiWaterHangedState()
    : PikiState(PIKISTATE_WaterHanged, "WATERHANGED")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0xD
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r4, 0x5DC4
	  subi      r5, r5, 0x7300
	  stw       r0, 0x0(r3)
	  lis       r4, 0x802C
	  subi      r0, r4, 0x6878
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4E4C
 * Size:	000038
 */
void PikiWaterHangedState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r5)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x20
	  b         .loc_0x28

	.loc_0x20:
	  li        r3, 0x144
	  bl        -0x2FA94

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4E84
 * Size:	0000B4
 */
void PikiWaterHangedState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  lfs       f0, -0x685C(r2)
	  mr        r30, r29
	  stfs      f0, 0x47C(r4)
	  beq-      .loc_0x30
	  addi      r30, r30, 0x2B8

	.loc_0x30:
	  addi      r3, r1, 0x10
	  li        r4, 0x1C
	  bl        0x4A09C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x1C
	  bl        0x4A0BC
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xA508
	  li        r0, 0
	  stw       r0, 0x1A4(r29)
	  lfs       f0, -0x3E68(r13)
	  stfs      f0, 0x70(r29)
	  lfs       f0, -0x3E64(r13)
	  stfs      f0, 0x74(r29)
	  lfs       f0, -0x3E60(r13)
	  stfs      f0, 0x78(r29)
	  lfs       f0, -0x3E5C(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x3E58(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x3E54(r13)
	  stfs      f0, 0xAC(r29)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4F38
 * Size:	000044
 */
void PikiWaterHangedState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x504(r4)
	  lwz       r5, 0xADC(r5)
	  lwz       r0, 0x4(r5)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x34
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4F7C
 * Size:	000024
 */
void PikiWaterHangedState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x144
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x2FB7C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4FA0
 * Size:	00004C
 */
PikiEmitState::PikiEmitState()
    : PikiState(PIKISTATE_Emit, "EMIT")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0xF
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3E50
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6918
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D4FEC
 * Size:	0000A4
 */
void PikiEmitState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r30, r29, 0
	  lfs       f0, -0x685C(r2)
	  stfs      f0, 0x47C(r4)
	  beq-      .loc_0x38
	  addi      r30, r30, 0x2B8

	.loc_0x38:
	  addi      r3, r1, 0x10
	  li        r4, 0x23
	  bl        0x49F2C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x23
	  bl        0x49F4C
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xA678
	  lwz       r4, 0xC8(r29)
	  li        r3, 0
	  li        r0, 0x1
	  ori       r4, r4, 0x800
	  stw       r4, 0xC8(r29)
	  stw       r3, 0x1A4(r29)
	  stb       r0, 0x10(r28)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D5090
 * Size:	000040
 */
void PikiEmitState::exec(Piki*)
{
	/*
	.loc_0x0:
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  bnelr-
	  lfs       f0, -0x3E48(r13)
	  stfs      f0, 0x70(r4)
	  lfs       f0, -0x3E44(r13)
	  stfs      f0, 0x74(r4)
	  lfs       f0, -0x3E40(r13)
	  stfs      f0, 0x78(r4)
	  lfs       f0, -0x3E3C(r13)
	  stfs      f0, 0xA4(r4)
	  lfs       f0, -0x3E38(r13)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, -0x3E34(r13)
	  stfs      f0, 0xAC(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D50D0
 * Size:	000010
 */
void PikiEmitState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,21,19
	  stw       r0, 0xC8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D50E0
 * Size:	00008C
 */
void PikiEmitState::procBounceMsg(Piki*, MsgBounce*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  addi      r29, r4, 0
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  li        r0, 0
	  cmplwi    r29, 0
	  stb       r0, 0x10(r3)
	  mr        r30, r29
	  beq-      .loc_0x40
	  addi      r30, r30, 0x2B8

	.loc_0x40:
	  addi      r3, r1, 0x14
	  li        r4, 0x26
	  bl        0x49E30
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x26
	  bl        0x49E50
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xA774

	.loc_0x70:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D516C
 * Size:	0000B4
 */
void PikiEmitState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  mr        r29, r4
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x30
	  b         .loc_0x98

	.loc_0x30:
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x80
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x4C
	  addi      r30, r30, 0x2B8

	.loc_0x4C:
	  addi      r3, r1, 0x14
	  li        r4, 0x23
	  bl        0x49D98
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x23
	  bl        0x49DB8
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xA80C
	  b         .loc_0x98

	.loc_0x80:
	  lwz       r12, 0x0(r3)
	  addi      r4, r29, 0
	  li        r5, 0x2
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x98:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D5220
 * Size:	00008C
 */
PikiFlyingState::PikiFlyingState()
    : PikiState(PIKISTATE_Flying, "FLYING")
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802C
	  stw       r0, 0x4(r1)
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x802C
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x5E4C
	  lis       r3, 0x802C
	  stw       r0, 0x0(r31)
	  li        r0, 0xE
	  stw       r0, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x8(r31)
	  subi      r0, r4, 0x5DC4
	  subi      r4, r13, 0x3E30
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x69B0
	  addi      r3, r31, 0x10
	  stw       r4, 0xC(r31)
	  stw       r0, 0x0(r31)
	  bl        0x3F0E8
	  lfs       f0, -0x68D0(r2)
	  mr        r3, r31
	  stfs      f0, 0x34(r31)
	  stfs      f0, 0x30(r31)
	  stfs      f0, 0x2C(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D52AC
 * Size:	000024
 */
void PikiFlyingState::stopEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x3F220
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D52D0
 * Size:	000024
 */
void PikiFlyingState::restartEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x3F218
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D52F4
 * Size:	0000B0
 */
void PikiFlyingState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x2C(r1)
	  addi      r29, r3, 0
	  addi      r3, r1, 0x18
	  lfs       f0, -0x685C(r2)
	  stfs      f0, 0x47C(r4)
	  li        r4, 0x22
	  bl        0x49C34
	  addi      r31, r3, 0
	  addi      r3, r1, 0x20
	  li        r4, 0x22
	  bl        0x49C24
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  bl        -0xA96C
	  lwz       r0, 0xC8(r30)
	  li        r31, 0
	  li        r3, 0x142
	  ori       r0, r0, 0x800
	  stw       r0, 0xC8(r30)
	  stw       r31, 0x1A4(r30)
	  bl        -0x2FF84
	  li        r0, 0x1
	  stb       r0, 0x470(r30)
	  addi      r3, r29, 0x10
	  addi      r4, r30, 0x94
	  stb       r31, 0x24(r29)
	  li        r5, 0x31
	  bl        0x3F020
	  stw       r31, 0x40(r29)
	  stb       r31, 0x25(r29)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D53A4
 * Size:	0003C0
 */
void PikiFlyingState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x110(r1)
	  stfd      f31, 0x108(r1)
	  stfd      f30, 0x100(r1)
	  stfd      f29, 0xF8(r1)
	  stfd      f28, 0xF0(r1)
	  stw       r31, 0xEC(r1)
	  mr        r31, r4
	  stw       r30, 0xE8(r1)
	  addi      r30, r3, 0
	  stw       r29, 0xE4(r1)
	  lwz       r0, 0xC8(r4)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0xA0
	  lwz       r3, 0x40(r30)
	  addi      r0, r3, 0x1
	  stw       r0, 0x40(r30)
	  lwz       r0, 0x40(r30)
	  cmpwi     r0, 0xA
	  blt-      .loc_0xA8
	  li        r3, 0x8
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x6C

	.loc_0x68:
	  bdnz-     .loc_0x68

	.loc_0x6C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x394

	.loc_0xA0:
	  li        r0, 0
	  stw       r0, 0x40(r30)

	.loc_0xA8:
	  addi      r3, r30, 0x10
	  addi      r4, r31, 0x94
	  bl        0x3EFD4
	  lwz       r4, 0x2F80(r13)
	  lwz       r3, 0x224(r31)
	  lfs       f0, -0x6858(r2)
	  lfs       f2, 0x30(r4)
	  lfs       f1, 0x388(r3)
	  fmuls     f30, f0, f2
	  lbz       r5, 0x24(r30)
	  fmuls     f29, f2, f1
	  lfs       f0, -0x6854(r2)
	  lfs       f1, -0x6850(r2)
	  fsubs     f31, f30, f29
	  cmplwi    r5, 0
	  fmuls     f2, f30, f0
	  fmuls     f0, f29, f0
	  fmuls     f1, f1, f31
	  fsubs     f1, f2, f1
	  fsubs     f28, f1, f0
	  bne-      .loc_0x2BC
	  lwz       r0, 0x520(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x2BC
	  lfs       f1, 0x74(r31)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x2BC
	  li        r0, 0x1
	  stb       r0, 0x24(r30)
	  addi      r3, r1, 0xA0
	  li        r4, 0x1C
	  bl        0x49A88
	  addi      r29, r3, 0
	  addi      r3, r1, 0xA8
	  li        r4, 0x1C
	  bl        0x49A78
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xAB18
	  lhz       r0, 0x510(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x16C
	  lwz       r3, 0x504(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f3, 0x1A8(r3)
	  b         .loc_0x178

	.loc_0x16C:
	  lwz       r3, 0x504(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f3, 0x188(r3)

	.loc_0x178:
	  lfs       f1, -0x68C0(r2)
	  fmuls     f2, f28, f28
	  lfs       f0, -0x68D0(r2)
	  fmuls     f1, f1, f3
	  fmuls     f1, f1, f29
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1AC
	  fsqrte    f0, f1
	  fmul      f0, f1, f0
	  frsp      f0, f0
	  stfs      f0, 0x88(r1)
	  lfs       f1, 0x88(r1)

	.loc_0x1AC:
	  fneg      f0, f28
	  lwz       r3, 0x504(r31)
	  lfs       f3, -0x68B4(r2)
	  lwz       r3, 0x224(r3)
	  fadds     f1, f0, f1
	  lfs       f2, 0x1B8(r3)
	  lfs       f0, 0x70(r31)
	  fdivs     f1, f1, f29
	  stfs      f0, 0x2C(r30)
	  lfs       f0, -0x68D0(r2)
	  stfs      f0, 0x30(r30)
	  lfs       f0, 0x78(r31)
	  fmuls     f2, f3, f2
	  stfs      f0, 0x34(r30)
	  lfs       f3, 0x2C(r30)
	  fdivs     f29, f2, f1
	  lfs       f0, 0x30(r30)
	  lfs       f2, 0x34(r30)
	  fmuls     f1, f3, f3
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC796C
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x23C
	  lfs       f0, 0x2C(r30)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x2C(r30)
	  lfs       f0, 0x30(r30)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x30(r30)
	  lfs       f0, 0x34(r30)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x34(r30)

	.loc_0x23C:
	  lfs       f0, 0x70(r31)
	  lfs       f1, 0x78(r31)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x68D0(r2)
	  fmuls     f1, f1, f1
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x270
	  fsqrte    f0, f1
	  fmul      f0, f1, f0
	  frsp      f0, f0
	  stfs      f0, 0x7C(r1)
	  lfs       f1, 0x7C(r1)

	.loc_0x270:
	  stfs      f1, 0x38(r30)
	  lfs       f0, -0x68B4(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r30)
	  lfs       f0, 0x70(r31)
	  fmuls     f0, f0, f29
	  stfs      f0, 0x70(r31)
	  lfs       f0, 0x78(r31)
	  fmuls     f0, f0, f29
	  stfs      f0, 0x78(r31)
	  lfs       f0, 0x70(r31)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x78(r31)
	  stfs      f0, 0xAC(r31)
	  lfs       f0, -0x68D0(r2)
	  stfs      f0, 0x74(r31)
	  stfs      f0, 0xA8(r31)
	  stfs      f0, 0x20(r30)
	  b         .loc_0x394

	.loc_0x2BC:
	  cmplwi    r5, 0
	  beq-      .loc_0x394
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x68C8(r2)
	  lfs       f2, 0x28C(r3)
	  lfs       f0, -0x684C(r2)
	  fmuls     f1, f1, f2
	  lfs       f2, 0xA0(r31)
	  fdivs     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9D100
	  stfs      f1, 0xA0(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x20(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r30)
	  bl        0x1429CC
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x68D8(r2)
	  stw       r0, 0xDC(r1)
	  lis       r0, 0x4330
	  lfs       f4, -0x68E4(r2)
	  stw       r0, 0xD8(r1)
	  lfs       f3, -0x68E8(r2)
	  lfd       f0, 0xD8(r1)
	  lfs       f1, -0x68B4(r2)
	  fsubs     f5, f0, f2
	  lfs       f6, 0x20(r30)
	  lfs       f0, -0x6854(r2)
	  lfs       f2, -0x6848(r2)
	  fdivs     f4, f5, f4
	  fmuls     f3, f3, f4
	  fcmpo     cr0, f6, f0
	  fsubs     f1, f3, f1
	  fmuls     f2, f2, f1
	  bge-      .loc_0x360
	  fdivs     f0, f31, f0
	  fmuls     f0, f6, f0
	  fsubs     f3, f30, f0
	  b         .loc_0x364

	.loc_0x360:
	  fmr       f3, f29

	.loc_0x364:
	  lwz       r3, 0x2F80(r13)
	  lfs       f1, -0x68E8(r2)
	  lfs       f0, 0x30(r3)
	  lwz       r3, 0x2DEC(r13)
	  fadds     f2, f1, f2
	  fsubs     f1, f0, f3
	  lfs       f3, 0x74(r31)
	  lfs       f0, 0x28C(r3)
	  fmuls     f1, f2, f1
	  fmuls     f0, f1, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x74(r31)

	.loc_0x394:
	  lwz       r0, 0x114(r1)
	  lfd       f31, 0x108(r1)
	  lfd       f30, 0x100(r1)
	  lfd       f29, 0xF8(r1)
	  lfd       f28, 0xF0(r1)
	  lwz       r31, 0xEC(r1)
	  lwz       r30, 0xE8(r1)
	  lwz       r29, 0xE4(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D5764
 * Size:	000044
 */
void PikiFlyingState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r3, 0x10
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  bl        0x3ED98
	  lwz       r3, 0xC8(r31)
	  li        r0, 0
	  rlwinm    r3,r3,0,21,19
	  stw       r3, 0xC8(r31)
	  stb       r0, 0x470(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D57A8
 * Size:	0006DC
 */
void PikiFlyingState::procCollideMsg(Piki*, MsgCollide*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x120(r1)
	  stfd      f31, 0x118(r1)
	  stfd      f30, 0x110(r1)
	  stfd      f29, 0x108(r1)
	  stfd      f28, 0x100(r1)
	  stfd      f27, 0xF8(r1)
	  stfd      f26, 0xF0(r1)
	  stmw      r27, 0xDC(r1)
	  mr        r29, r5
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  lwz       r5, 0x4(r5)
	  lwz       r31, 0x6C(r5)
	  addi      r30, r5, 0
	  cmpwi     r31, 0x26
	  bne-      .loc_0x5C
	  lfs       f1, 0x74(r28)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  beq-      .loc_0x6B0

	.loc_0x5C:
	  subi      r0, r31, 0x21
	  cmplwi    r0, 0x1
	  ble-      .loc_0x6B0
	  cmpwi     r31, 0x1
	  bne-      .loc_0x7C
	  lwz       r0, 0x520(r28)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x6B0

	.loc_0x7C:
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x1B5(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x6B0
	  lwz       r0, 0x2AC(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x6B0
	  cmpwi     r31, 0x26
	  bne-      .loc_0x160
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r28, 0x94
	  lwz       r12, 0x168(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4F8(r28)
	  li        r4, 0
	  bl        -0x10540
	  lwz       r3, 0x4F8(r28)
	  li        r0, 0x17
	  addi      r4, r30, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r28)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xB8
	  bl        -0x11B80
	  li        r0, 0x10
	  sth       r0, 0x4FC(r28)
	  b         .loc_0x6B0

	.loc_0x10C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x160(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x160
	  lwz       r3, 0x4F8(r28)
	  li        r4, 0
	  bl        -0x10594
	  lwz       r3, 0x4F8(r28)
	  li        r0, 0x18
	  addi      r4, r30, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r28)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0xC0
	  bl        -0x11BD4
	  li        r0, 0x11
	  sth       r0, 0x4FC(r28)
	  b         .loc_0x6B0

	.loc_0x160:
	  cmpwi     r31, 0x33
	  beq-      .loc_0x6B0
	  cmpwi     r31, 0x20
	  beq-      .loc_0x6B0
	  subi      r0, r31, 0x21
	  cmplwi    r0, 0x1
	  ble-      .loc_0x6B0
	  cmpwi     r31, 0x33
	  beq-      .loc_0x18C
	  li        r3, 0x141
	  bl        -0x30554

	.loc_0x18C:
	  cmpwi     r31, 0x37
	  beq-      .loc_0x1A4
	  mr        r3, r30
	  bl        -0x4B698
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x298

	.loc_0x1A4:
	  lfs       f3, 0x94(r30)
	  lfs       f2, 0x94(r28)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x98(r28)
	  fsubs     f31, f3, f2
	  lfs       f2, 0x9C(r30)
	  fsubs     f30, f1, f0
	  lfs       f0, 0x9C(r28)
	  fmuls     f1, f31, f31
	  fsubs     f29, f2, f0
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC7D44
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1F8
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x1F8:
	  mr        r3, r28
	  fmr       f28, f31
	  lwz       r12, 0x0(r28)
	  fmr       f27, f30
	  fmr       f26, f29
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x6898(r2)
	  lis       r4, 0x802B
	  lis       r3, 0x802D
	  lfs       f2, 0x94(r28)
	  fmuls     f3, f0, f1
	  lfs       f1, 0x98(r28)
	  subi      r0, r3, 0x2688
	  lfs       f0, 0x9C(r28)
	  subi      r4, r4, 0x3064
	  lwz       r5, 0x8(r29)
	  fmuls     f31, f31, f3
	  fmuls     f30, f30, f3
	  mr        r3, r30
	  stw       r4, 0x9C(r1)
	  fmuls     f29, f29, f3
	  stw       r28, 0xA0(r1)
	  fadds     f31, f31, f2
	  addi      r4, r1, 0x9C
	  stw       r0, 0x9C(r1)
	  fadds     f30, f30, f1
	  stfs      f31, 0xA4(r1)
	  fadds     f29, f29, f0
	  stfs      f30, 0xA8(r1)
	  stfs      f29, 0xAC(r1)
	  stfs      f28, 0xB0(r1)
	  stfs      f27, 0xB4(r1)
	  stfs      f26, 0xB8(r1)
	  stw       r5, 0xBC(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x298:
	  lwz       r0, 0x8(r29)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x3A8
	  bl        -0x4DD10
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3A8
	  lbz       r0, 0x25(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x39C
	  lfs       f0, 0x94(r30)
	  lfs       f1, 0x94(r28)
	  lfs       f3, 0x98(r28)
	  lfs       f2, 0x98(r30)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x9C(r28)
	  lfs       f1, 0x9C(r30)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x90(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0x90(r1)
	  lfs       f0, 0x94(r1)
	  lfs       f2, 0x98(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC7E78
	  lfs       f0, -0x68D0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x344
	  lfs       f0, 0x90(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x94(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x98(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x98(r1)

	.loc_0x344:
	  lfs       f0, 0x90(r1)
	  lfs       f1, -0x6844(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x94(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x98(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x98(r1)
	  lwz       r3, 0x90(r1)
	  lwz       r0, 0x94(r1)
	  stw       r3, 0x70(r28)
	  stw       r0, 0x74(r28)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0x78(r28)
	  lwz       r3, 0x90(r1)
	  lwz       r0, 0x94(r1)
	  stw       r3, 0xA4(r28)
	  stw       r0, 0xA8(r28)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0xAC(r28)

	.loc_0x39C:
	  li        r0, 0x1
	  stb       r0, 0x25(r27)
	  b         .loc_0x6B0

	.loc_0x3A8:
	  cmpwi     r31, 0x37
	  bne-      .loc_0x4D8
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x4D8
	  lwz       r3, 0x4F8(r28)
	  li        r4, 0
	  bl        -0x10838
	  lwz       r3, 0x8(r29)
	  lbz       r4, 0x5C(r3)
	  cmplwi    r4, 0x3
	  bne-      .loc_0x43C
	  bl        -0x4DFD0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x410
	  lwz       r5, 0x8(r29)
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        -0x452C4
	  li        r3, 0x149
	  bl        -0x307D4
	  b         .loc_0x490

	.loc_0x410:
	  lwz       r3, 0x8(r29)
	  bl        -0x4DED8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x490
	  lwz       r5, 0x8(r29)
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        -0x452F0
	  li        r3, 0x149
	  bl        -0x30800
	  b         .loc_0x490

	.loc_0x43C:
	  cmplwi    r4, 0
	  beq-      .loc_0x464
	  cmplwi    r4, 0x5
	  li        r0, 0x1
	  beq-      .loc_0x45C
	  cmplwi    r4, 0x6
	  beq-      .loc_0x45C
	  li        r0, 0

	.loc_0x45C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x490

	.loc_0x464:
	  bl        -0x4E04C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x490
	  lwz       r5, 0x8(r29)
	  mr        r3, r28
	  lfs       f1, -0x68D0(r2)
	  addi      r4, r30, 0
	  li        r6, -0x1
	  bl        -0x45574
	  li        r3, 0x149
	  bl        -0x30858

	.loc_0x490:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  addi      r4, r28, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4F8(r28)
	  li        r0, 0x8
	  addi      r4, r30, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r28)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0x40
	  bl        -0x11F4C
	  li        r0, 0x2
	  sth       r0, 0x4FC(r28)
	  b         .loc_0x6B0

	.loc_0x4D8:
	  mr        r3, r30
	  bl        -0x4B9DC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x58C
	  lwz       r3, 0x8(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x58C
	  bl        -0x4E0DC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x58C
	  lwz       r5, 0x8(r29)
	  lbz       r0, 0x5C(r5)
	  cmplwi    r0, 0x3
	  bne-      .loc_0x528
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        -0x453DC
	  li        r3, 0x149
	  bl        -0x308EC
	  b         .loc_0x544

	.loc_0x528:
	  lfs       f1, -0x68D0(r2)
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  li        r6, -0x1
	  bl        -0x45628
	  li        r3, 0x149
	  bl        -0x3090C

	.loc_0x544:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  addi      r4, r28, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4F8(r28)
	  li        r0, 0x8
	  addi      r4, r30, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r28)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0x40
	  bl        -0x12000
	  li        r0, 0x2
	  sth       r0, 0x4FC(r28)
	  b         .loc_0x6B0

	.loc_0x58C:
	  lwz       r5, 0x6C(r30)
	  li        r3, 0x1
	  addi      r4, r3, 0
	  cmpwi     r5, 0x16
	  addi      r0, r3, 0
	  beq-      .loc_0x5B0
	  cmpwi     r5, 0x17
	  beq-      .loc_0x5B0
	  li        r0, 0

	.loc_0x5B0:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x5C4
	  cmpwi     r5, 0x18
	  beq-      .loc_0x5C4
	  li        r4, 0

	.loc_0x5C4:
	  rlwinm.   r0,r4,0,24,31
	  bne-      .loc_0x5D8
	  cmpwi     r5, 0x19
	  beq-      .loc_0x5D8
	  li        r3, 0

	.loc_0x5D8:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x628
	  li        r0, 0xD
	  sth       r0, 0x4FC(r28)
	  li        r0, 0x13
	  addi      r4, r30, 0
	  lwz       r3, 0x4F8(r28)
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r28)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0x98
	  bl        -0x12088
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  addi      r4, r28, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x6B0

	.loc_0x628:
	  cmpwi     r31, 0x34
	  bne-      .loc_0x680
	  mr        r3, r30
	  bl        -0x3FA7C
	  cmpwi     r3, -0x1
	  beq-      .loc_0x680
	  lwz       r3, 0x4F8(r28)
	  li        r4, 0
	  bl        -0x10AAC
	  lwz       r3, 0x4F8(r28)
	  li        r0, 0x15
	  addi      r4, r30, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r28)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        -0x120F4
	  li        r0, 0x9
	  sth       r0, 0x4FC(r28)
	  b         .loc_0x6B0

	.loc_0x680:
	  cmpwi     r31, 0x36
	  beq-      .loc_0x6B0
	  lwz       r0, 0xC8(r28)
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  rlwinm    r0,r0,0,21,19
	  stw       r0, 0xC8(r28)
	  li        r5, 0
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x6B0:
	  lmw       r27, 0xDC(r1)
	  lwz       r0, 0x124(r1)
	  lfd       f31, 0x118(r1)
	  lfd       f30, 0x110(r1)
	  lfd       f29, 0x108(r1)
	  lfd       f28, 0x100(r1)
	  lfd       f27, 0xF8(r1)
	  lfd       f26, 0xF0(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D5E84
 * Size:	000004
 */
void PikiFlyingState::procStickMsg(Piki*, MsgStick*) { }

/*
 * --INFO--
 * Address:	800D5E88
 * Size:	0000E8
 */
void PikiFlyingState::procBounceMsg(Piki*, MsgBounce*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  addi      r31, r4, 0
	  lbz       r0, 0x25(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  lwz       r0, 0xC8(r31)
	  addi      r4, r31, 0
	  li        r5, 0
	  rlwinm    r0,r0,0,21,19
	  stw       r0, 0xC8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0xE
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lwz       r4, 0x504(r31)
	  lwz       r3, 0x4(r3)
	  addi      r3, r3, 0x70
	  bl        -0x121C4
	  li        r0, 0x1
	  sth       r0, 0x4FC(r31)
	  b         .loc_0xD4

	.loc_0x70:
	  lwz       r0, 0xC8(r31)
	  addi      r4, r31, 0
	  li        r5, 0
	  rlwinm    r0,r0,0,21,19
	  stw       r0, 0xC8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xFD
	  bl        -0x31B20
	  lwz       r3, 0x2AC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xCC
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0xE
	  lwz       r5, 0x504(r31)
	  addi      r3, r31, 0
	  li        r4, 0x12
	  bl        -0x8D80
	  b         .loc_0xD4

	.loc_0xCC:
	  mr        r3, r31
	  bl        -0xDE9C

	.loc_0xD4:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D5F70
 * Size:	00004C
 */
PikiGrowState::PikiGrowState()
    : PikiState(PIKISTATE_Grow, "GROW")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x1
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3E28
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6A48
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D5FBC
 * Size:	00007C
 */
void PikiGrowState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  addi      r30, r29, 0
	  beq-      .loc_0x28
	  addi      r30, r30, 0x2B8

	.loc_0x28:
	  addi      r3, r1, 0x10
	  li        r4, 0x11
	  bl        0x48F6C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x11
	  bl        0x48F8C
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xB638
	  li        r0, 0
	  stw       r0, 0x4B8(r29)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6038
 * Size:	000004
 */
void PikiGrowState::exec(Piki*) { }

/*
 * --INFO--
 * Address:	800D603C
 * Size:	000004
 */
void PikiGrowState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D6040
 * Size:	000044
 */
void PikiGrowState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x20
	  b         .loc_0x34

	.loc_0x20:
	  lwz       r12, 0x0(r3)
	  li        r5, 0x2
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6084
 * Size:	000050
 */
PikiKinokoChangeState::PikiKinokoChangeState()
    : PikiState(PIKISTATE_KinokoChange, "KINOKOCHANGE")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x1D
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r4, 0x5DC4
	  subi      r5, r5, 0x72F0
	  stw       r0, 0x0(r3)
	  lis       r4, 0x802C
	  subi      r0, r4, 0x6AE0
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D60D4
 * Size:	0000AC
 */
void PikiKinokoChangeState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r4, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x48
	  li        r0, 0
	  stb       r0, 0x10(r30)
	  b         .loc_0x50

	.loc_0x48:
	  li        r0, 0x1
	  stb       r0, 0x10(r30)

	.loc_0x50:
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x60
	  addi      r30, r30, 0x2B8

	.loc_0x60:
	  addi      r3, r1, 0x10
	  li        r4, 0x11
	  bl        0x48E1C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x11
	  bl        0x48E3C
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xB788
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6180
 * Size:	00002C
 */
void PikiKinokoChangeState::restart(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D61AC
 * Size:	000078
 */
void PikiKinokoChangeState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lfs       f0, -0x3E20(r13)
	  stfs      f0, 0xA4(r4)
	  lfs       f0, -0x3E1C(r13)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, -0x3E18(r13)
	  stfs      f0, 0xAC(r4)
	  lfs       f0, -0x3E14(r13)
	  stfs      f0, 0x70(r4)
	  lfs       f0, -0x3E10(r13)
	  stfs      f0, 0x74(r4)
	  lfs       f0, -0x3E0C(r13)
	  stfs      f0, 0x78(r4)
	  lwz       r0, 0x39C(r4)
	  cmpwi     r0, 0x11
	  beq-      .loc_0x68
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  mr        r3, r4
	  bl        -0xC8B4
	  b         .loc_0x68

	.loc_0x60:
	  mr        r3, r4
	  bl        -0xC890

	.loc_0x68:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6224
 * Size:	000004
 */
void PikiKinokoChangeState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D6228
 * Size:	000094
 */
void PikiKinokoChangeState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x34
	  bge-      .loc_0x80
	  cmpwi     r0, 0
	  bge-      .loc_0x68
	  b         .loc_0x80

	.loc_0x34:
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C
	  mr        r3, r31
	  bl        -0xC91C
	  lwz       r4, 0x4A8(r31)
	  addi      r3, r31, 0
	  li        r5, 0x6C
	  bl        -0x4BCC8
	  b         .loc_0x80

	.loc_0x5C:
	  mr        r3, r31
	  bl        -0xC908
	  b         .loc_0x80

	.loc_0x68:
	  lwz       r12, 0x0(r3)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x80:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D62BC
 * Size:	00004C
 */
PikiGrowupState::PikiGrowupState()
    : PikiState(PIKISTATE_GrowUp, "GROWUP")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x13
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3E08
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6B80
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6308
 * Size:	0000C8
 */
void PikiGrowupState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  mr        r29, r4
	  lwz       r0, 0x514(r4)
	  cmpwi     r0, 0x1
	  bge-      .loc_0x6C
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x38
	  addi      r30, r30, 0x2B8

	.loc_0x38:
	  addi      r3, r1, 0x20
	  li        r4, 0x11
	  bl        0x48C10
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x28
	  li        r4, 0x11
	  bl        0x48C30
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xB994
	  b         .loc_0xAC

	.loc_0x6C:
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x7C
	  addi      r30, r30, 0x2B8

	.loc_0x7C:
	  addi      r3, r1, 0x10
	  li        r4, 0x12
	  bl        0x48BCC
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x12
	  bl        0x48BEC
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xB9D8

	.loc_0xAC:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D63D0
 * Size:	000098
 */
void PikiGrowupState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  mr        r3, r31
	  lfs       f0, -0x3E00(r13)
	  stfs      f0, 0xA4(r4)
	  lfs       f0, -0x3DFC(r13)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, -0x3DF8(r13)
	  stfs      f0, 0xAC(r4)
	  lfs       f0, -0x3DF4(r13)
	  stfs      f0, 0x70(r4)
	  lfs       f0, -0x3DF0(r13)
	  stfs      f0, 0x74(r4)
	  lfs       f0, -0x3DEC(r13)
	  stfs      f0, 0x78(r4)
	  bl        -0xF9A0
	  cmpwi     r3, 0x11
	  beq-      .loc_0x80
	  cmpwi     r3, 0x12
	  beq-      .loc_0x80
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x80:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6468
 * Size:	000004
 */
void PikiGrowupState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D646C
 * Size:	000134
 */
void PikiGrowupState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x38
	  bge-      .loc_0x11C
	  cmpwi     r0, 0
	  bge-      .loc_0x104
	  b         .loc_0x11C

	.loc_0x38:
	  lwz       r3, 0x514(r30)
	  addi      r5, r30, 0x94
	  li        r4, 0x10C
	  addi      r0, r3, 0x1
	  stw       r0, 0x514(r30)
	  lwz       r3, 0x3038(r13)
	  bl        -0x320B4
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0x2
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x21
	  addi      r3, r3, 0x70
	  bl        -0x52AE4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1A
	  addi      r3, r3, 0x54
	  bl        -0x54030
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xE4
	  lis       r3, 0x803A
	  subi      r31, r3, 0x2848
	  lwz       r3, 0x1DC(r31)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xE4
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0xE4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1A
	  addi      r3, r3, 0x54
	  bl        -0x53DE0
	  lwz       r3, 0x1E8(r31)
	  li        r4, 0
	  li        r5, 0x16
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xE4:
	  lhz       r0, 0x4FC(r30)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x11C
	  lwz       r3, 0x504(r30)
	  mr        r4, r30
	  lwz       r3, 0x710(r3)
	  bl        -0x307B0
	  b         .loc_0x11C

	.loc_0x104:
	  lwz       r12, 0x0(r3)
	  addi      r4, r30, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x11C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D65A0
 * Size:	00004C
 */
PikiWaveState::PikiWaveState()
    : PikiState(PIKISTATE_Wave, "WAVE")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x12
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3DE8
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6C18
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D65EC
 * Size:	000004
 */
void PikiWaveState::init(Piki*) { }

/*
 * --INFO--
 * Address:	800D65F0
 * Size:	000004
 */
void PikiWaveState::exec(Piki*) { }

/*
 * --INFO--
 * Address:	800D65F4
 * Size:	000004
 */
void PikiWaveState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D65F8
 * Size:	000030
 */
void PikiWaveState::resume(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6628
 * Size:	000004
 */
void PikiWaveState::restart(Piki*) { }

/*
 * --INFO--
 * Address:	800D662C
 * Size:	000048
 */
void PikiWaveState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x24
	  blt-      .loc_0x38
	  b         .loc_0x38

	.loc_0x24:
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x38:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void PikiWaveState::waveAttack(Piki*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800D6674
 * Size:	00004C
 */
PikiPushState::PikiPushState()
    : PikiState(PIKISTATE_Push, "PUSH")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x14
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3DE0
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6CB0
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D66C0
 * Size:	000088
 */
void PikiPushState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x30
	  addi      r30, r30, 0x2B8

	.loc_0x30:
	  addi      r3, r1, 0x10
	  li        r4, 0
	  bl        0x48860
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x25
	  bl        0x48880
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xBD44
	  li        r0, 0
	  stb       r0, 0x10(r28)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6748
 * Size:	000150
 */
void PikiPushState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stfd      f29, 0x58(r1)
	  stfd      f28, 0x50(r1)
	  stw       r31, 0x4C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  lfs       f0, -0x685C(r2)
	  stfs      f0, 0x47C(r4)
	  lwz       r3, 0x504(r4)
	  lfsu      f30, 0x74C(r3)
	  lfs       f1, 0xA0(r4)
	  lfs       f29, 0x4(r3)
	  lfs       f28, 0x8(r3)
	  bl        0x1453C4
	  fmr       f31, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x14554C
	  lfs       f2, -0x3DD8(r13)
	  fmuls     f3, f30, f1
	  fmuls     f4, f28, f31
	  lfs       f0, -0x6840(r2)
	  fmuls     f1, f29, f2
	  fadds     f1, f3, f1
	  fadds     f1, f4, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x9C
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x8C
	  addi      r4, r4, 0x2B8

	.loc_0x8C:
	  addi      r3, r31, 0x354
	  bl        0x492E8
	  li        r0, 0x1
	  stb       r0, 0x10(r30)

	.loc_0x9C:
	  lbz       r0, 0x10(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x104
	  lwz       r3, 0x504(r31)
	  lfsu      f1, 0x764(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r3)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC8BD4
	  lfs       f0, -0x68CC(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x104
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0xF0
	  addi      r4, r4, 0x2B8

	.loc_0xF0:
	  addi      r3, r31, 0x354
	  bl        0x49284
	  li        r0, 0x1
	  stb       r0, 0x10(r30)
	  b         .loc_0x128

	.loc_0x104:
	  lwz       r0, 0x4E4(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x128
	  lwz       r3, 0x2F80(r13)
	  lwz       r0, 0x70(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x128
	  li        r0, 0x1
	  stw       r0, 0x4D8(r31)

	.loc_0x128:
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lfd       f29, 0x58(r1)
	  lfd       f28, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6898
 * Size:	00000C
 */
void PikiPushState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x4E4(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D68A4
 * Size:	000030
 */
void PikiPushState::resume(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D68D4
 * Size:	000004
 */
void PikiPushState::restart(Piki*) { }

/*
 * --INFO--
 * Address:	800D68D8
 * Size:	000038
 */
void PikiPushState::procOffWallMsg(Piki*, MsgOffWall*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  addi      r5, r4, 0
	  stwu      r1, -0x8(r1)
	  beq-      .loc_0x1C
	  addi      r5, r5, 0x2B8

	.loc_0x1C:
	  addi      r3, r4, 0x354
	  addi      r4, r5, 0
	  bl        0x491C4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6910
 * Size:	000078
 */
void PikiPushState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x2C
	  bge-      .loc_0x68
	  cmpwi     r0, 0
	  beq-      .loc_0x54
	  b         .loc_0x68

	.loc_0x2C:
	  lwz       r0, 0x4E4(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x68
	  lwz       r3, 0x2F80(r13)
	  lwz       r0, 0x70(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x68
	  li        r0, 0x1
	  stw       r0, 0x4D8(r4)
	  b         .loc_0x68

	.loc_0x54:
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x68:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6988
 * Size:	000050
 */
PikiPushPikiState::PikiPushPikiState()
    : PikiState(PIKISTATE_PushPiki, "PUSHPIKI")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x15
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r4, 0x5DC4
	  subi      r5, r5, 0x72E0
	  stw       r0, 0x0(r3)
	  lis       r4, 0x802C
	  subi      r0, r4, 0x6D48
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D69D8
 * Size:	000090
 */
void PikiPushPikiState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x30
	  addi      r30, r30, 0x2B8

	.loc_0x30:
	  addi      r3, r1, 0x10
	  li        r4, 0x25
	  bl        0x48548
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x25
	  bl        0x48568
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        -0xC05C
	  li        r0, 0x1
	  stw       r0, 0x10(r28)
	  li        r0, 0
	  stb       r0, 0x14(r28)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6A68
 * Size:	0000F4
 */
void PikiPushPikiState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lbz       r0, 0x14(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x68
	  lwz       r3, 0x4DC(r31)
	  bl        -0xE540
	  cmpwi     r3, 0x14
	  beq-      .loc_0x68
	  lwz       r3, 0x4DC(r31)
	  bl        -0xE550
	  cmpwi     r3, 0x15
	  beq-      .loc_0x68
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x58
	  addi      r4, r4, 0x2B8

	.loc_0x58:
	  addi      r3, r31, 0x354
	  bl        0x48FFC
	  li        r0, 0x1
	  stb       r0, 0x14(r30)

	.loc_0x68:
	  lfs       f0, -0x685C(r2)
	  stfs      f0, 0x47C(r31)
	  lbz       r0, 0x14(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0xD4
	  lwz       r3, 0x504(r31)
	  lfsu      f1, 0x764(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r3)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xC8EC8
	  lfs       f0, -0x68CC(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xD4
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0xC4
	  addi      r4, r4, 0x2B8

	.loc_0xC4:
	  addi      r3, r31, 0x354
	  bl        0x48F90
	  li        r0, 0x1
	  stb       r0, 0x14(r30)

	.loc_0xD4:
	  li        r0, 0
	  stw       r0, 0x10(r30)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6B5C
 * Size:	00000C
 */
void PikiPushPikiState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x4DC(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6B68
 * Size:	000030
 */
void PikiPushPikiState::resume(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6B98
 * Size:	000004
 */
void PikiPushPikiState::restart(Piki*) { }

/*
 * --INFO--
 * Address:	800D6B9C
 * Size:	0000A4
 */
void PikiPushPikiState::procCollideMsg(Piki*, MsgCollide*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x2C(r1)
	  addi      r29, r3, 0
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x6C(r5)
	  addi      r3, r5, 0
	  cmpwi     r0, 0
	  beq-      .loc_0x38
	  b         .loc_0x88

	.loc_0x38:
	  mr        r31, r3
	  bl        -0xE684
	  cmpwi     r3, 0x14
	  bne-      .loc_0x88
	  lfs       f0, 0x4BC(r31)
	  li        r0, 0x1
	  stfs      f0, 0x14(r1)
	  lfs       f0, 0x4C0(r31)
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x4C4(r31)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0xA0(r30)
	  lwz       r4, 0x14(r1)
	  lwz       r3, 0x18(r1)
	  stw       r4, 0x4BC(r30)
	  stw       r3, 0x4C0(r30)
	  lwz       r3, 0x1C(r1)
	  stw       r3, 0x4C4(r30)
	  stw       r0, 0x10(r29)

	.loc_0x88:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6C40
 * Size:	000004
 */
void PikiPushPikiState::procWallMsg(Piki*, MsgWall*) { }

/*
 * --INFO--
 * Address:	800D6C44
 * Size:	000080
 */
void PikiPushPikiState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x34
	  bge-      .loc_0x6C
	  cmpwi     r0, 0
	  beq-      .loc_0x54
	  b         .loc_0x6C

	.loc_0x34:
	  lwz       r0, 0x4E4(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x6C
	  lfs       f1, 0xA0(r31)
	  bl        0x144ECC
	  lfs       f1, 0xA0(r31)
	  bl        0x145058
	  b         .loc_0x6C

	.loc_0x54:
	  lwz       r12, 0x0(r3)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x6C:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6CC4
 * Size:	00004C
 */
PikiBuryState::PikiBuryState()
    : PikiState(PIKISTATE_Bury, "BURY")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x2
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3DD4
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6DE4
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6D10
 * Size:	000004
 */
void PikiBuryState::init(Piki*) { }

/*
 * --INFO--
 * Address:	800D6D14
 * Size:	000200
 */
void PikiBuryState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  addi      r30, r4, 0
	  li        r4, 0xF
	  stw       r29, 0x34(r1)
	  addi      r29, r3, 0
	  stb       r0, 0x30A8(r13)
	  lwz       r3, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stb       r0, 0x30A8(r13)
	  mr        r31, r3
	  li        r0, -0x1
	  lwz       r3, 0x28C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x6C
	  bl        0x3F308
	  mr        r0, r3

	.loc_0x6C:
	  cmplwi    r31, 0
	  beq-      .loc_0x1C0
	  cmpwi     r0, 0x5
	  beq-      .loc_0x1C0
	  lfs       f0, 0x94(r30)
	  li        r4, 0x1
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x20(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x18(r1)
	  lfs       f2, 0x20(r1)
	  bl        -0x6EEB4
	  stfs      f1, 0x1C(r1)
	  addi      r5, r1, 0x18
	  li        r4, 0x32
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        0xC5D64
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x18
	  li        r4, 0x33
	  li        r6, 0
	  li        r7, 0
	  bl        0xC5D4C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  addi      r4, r1, 0x18
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lhz       r4, 0x510(r30)
	  bl        0x15C90
	  bl        0x14125C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x2C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  stw       r0, 0x28(r1)
	  lfs       f2, -0x68E8(r2)
	  lfd       f1, 0x28(r1)
	  lfs       f0, -0x68C8(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x68C0(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f30, f1, f0
	  fmr       f1, f30
	  bl        0x144CFC
	  lfs       f0, -0x686C(r2)
	  fmuls     f31, f0, f1
	  fmr       f1, f30
	  bl        0x144E80
	  lfs       f0, -0x686C(r2)
	  addi      r3, r31, 0
	  li        r4, 0
	  fmuls     f0, f0, f1
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x3DCC(r13)
	  stfs      f0, 0x74(r31)
	  stfs      f31, 0x78(r31)
	  lwz       r0, 0x520(r30)
	  stw       r0, 0x3D0(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stw       r0, 0x3E0(r31)
	  addi      r4, r31, 0
	  li        r5, 0x5
	  lwz       r3, 0x2E8(r31)
	  bl        -0x59760
	  li        r0, 0x1
	  stb       r0, 0x584(r30)
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x4C1EC
	  b         .loc_0x1DC

	.loc_0x1C0:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x1DC:
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6F14
 * Size:	000004
 */
void PikiBuryState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D6F18
 * Size:	000050
 */
PikiNukareWaitState::PikiNukareWaitState()
    : PikiState(PIKISTATE_NukareWait, "NUKAREWAIT")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x4
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r4, 0x5DC4
	  subi      r5, r5, 0x72D4
	  stw       r0, 0x0(r3)
	  lis       r4, 0x802C
	  subi      r0, r4, 0x6E7C
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D6F68
 * Size:	00014C
 */
void PikiNukareWaitState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr.       r29, r4
	  lfs       f0, -0x3DC8(r13)
	  mr        r30, r29
	  stfs      f0, 0x70(r4)
	  lfs       f0, -0x3DC4(r13)
	  stfs      f0, 0x74(r4)
	  lfs       f0, -0x3DC0(r13)
	  stfs      f0, 0x78(r4)
	  lfs       f0, -0x3DBC(r13)
	  stfs      f0, 0xA4(r4)
	  lfs       f0, -0x3DB8(r13)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, -0x3DB4(r13)
	  stfs      f0, 0xAC(r4)
	  lfs       f0, -0x3DB0(r13)
	  stfs      f0, 0xBC(r4)
	  lfs       f0, -0x3DAC(r13)
	  stfs      f0, 0xC0(r4)
	  lfs       f0, -0x3DA8(r13)
	  stfs      f0, 0xC4(r4)
	  beq-      .loc_0x70
	  addi      r30, r30, 0x2B8

	.loc_0x70:
	  addi      r3, r1, 0x10
	  li        r4, 0x6
	  bl        0x47F78
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x6
	  bl        0x47F98
	  addi      r4, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r29, 0x354
	  bl        0x48A64
	  lhz       r0, 0x510(r29)
	  cmplwi    r0, 0x1
	  bne-      .loc_0xC4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x4
	  addi      r3, r3, 0x54
	  bl        -0x54B5C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10C

	.loc_0xC4:
	  lhz       r0, 0x510(r29)
	  cmplwi    r0, 0x2
	  bne-      .loc_0xE8
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x5
	  addi      r3, r3, 0x54
	  bl        -0x54B80
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10C

	.loc_0xE8:
	  lhz       r0, 0x510(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x130
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x6
	  addi      r3, r3, 0x54
	  bl        -0x54BA4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x130

	.loc_0x10C:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0xE
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x130:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D70B4
 * Size:	000078
 */
void PikiNukareWaitState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r4, 0
	  addi      r31, r30, 0x358
	  lfs       f0, -0x3DA4(r13)
	  stfs      f0, 0x70(r4)
	  lfs       f0, -0x3DA0(r13)
	  stfs      f0, 0x74(r4)
	  lfs       f0, -0x3D9C(r13)
	  stfs      f0, 0x78(r4)
	  lwz       r0, 0x39C(r4)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x54
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl

	.loc_0x54:
	  lfs       f0, -0x68D0(r2)
	  stfs      f0, 0x2C(r31)
	  stfs      f0, 0x3D8(r30)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D712C
 * Size:	000004
 */
void PikiNukareWaitState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D7130
 * Size:	00004C
 */
PikiNukareState::PikiNukareState()
    : PikiState(PIKISTATE_Nukare, "NUKARE")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x3
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3D98
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6F18
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D717C
 * Size:	0000AC
 */
void PikiNukareState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  li        r4, 0x7
	  lfs       f0, -0x3D90(r13)
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x3D8C(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x3D88(r13)
	  stfs      f0, 0x78(r31)
	  lfs       f0, -0x3D84(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x3D80(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x3D7C(r13)
	  stfs      f0, 0xAC(r31)
	  lfs       f0, -0x3D78(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x3D74(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x3D70(r13)
	  stfs      f0, 0xC4(r31)
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x54
	  bl        -0x54A94
	  mr        r3, r31
	  bl        0x24D8
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0xE
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7228
 * Size:	000004
 */
void PikiNukareState::exec(Piki*) { }

/*
 * --INFO--
 * Address:	800D722C
 * Size:	000264
 */
void PikiNukareState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x56DD0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x94
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1E
	  addi      r3, r3, 0x54
	  bl        -0x54D98
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x94
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1ED0
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  add       r0, r0, r4
	  add       r0, r3, r0
	  cmpwi     r0, 0xF
	  blt-      .loc_0x94
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1E
	  addi      r3, r3, 0x54
	  bl        -0x54B48
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0
	  li        r5, 0x1E
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x94:
	  lhz       r0, 0x510(r31)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x124
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x4
	  addi      r3, r3, 0x54
	  bl        -0x54E14
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x124
	  lwz       r3, 0x2F6C(r13)
	  addi      r5, r31, 0
	  li        r4, 0x4
	  addi      r3, r3, 0x54
	  bl        -0x54DD8
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x7
	  addi      r3, r3, 0x54
	  bl        -0x54BB4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x3
	  addi      r3, r3, 0x54
	  bl        -0x54BC4
	  lwz       r4, 0x2F70(r13)
	  lwz       r3, 0x3120(r13)
	  addi      r31, r4, 0x60
	  bl        0x400A0
	  lwz       r4, 0x2F6C(r13)
	  addi      r5, r3, 0
	  lfs       f1, 0x0(r31)
	  addi      r3, r4, 0x54
	  li        r4, 0x9
	  bl        -0x54BBC
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1
	  bl        -0x56D5C
	  b         .loc_0x22C

	.loc_0x124:
	  lhz       r0, 0x510(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x19C
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x5
	  addi      r3, r3, 0x54
	  bl        -0x54EA4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x19C
	  lwz       r3, 0x2F6C(r13)
	  addi      r5, r31, 0
	  li        r4, 0x5
	  addi      r3, r3, 0x54
	  bl        -0x54E68
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x25
	  addi      r3, r3, 0x70
	  bl        -0x53994
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x24
	  addi      r3, r3, 0x70
	  bl        -0x539A4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2
	  lbz       r0, 0x184(r3)
	  ori       r0, r0, 0x4
	  stb       r0, 0x184(r3)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x56DD4
	  b         .loc_0x22C

	.loc_0x19C:
	  lhz       r0, 0x510(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x22C
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x6
	  addi      r3, r3, 0x54
	  bl        -0x54F1C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x22C
	  lwz       r3, 0x2F6C(r13)
	  addi      r5, r31, 0
	  li        r4, 0x6
	  addi      r3, r3, 0x54
	  bl        -0x54EE0
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x12
	  addi      r3, r3, 0x70
	  bl        -0x53A0C
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0
	  lbz       r0, 0x184(r3)
	  ori       r0, r0, 0x1
	  stb       r0, 0x184(r3)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x56E3C
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lbzu      r0, 0xB6(r3)
	  ori       r0, r0, 0x1
	  stb       r0, 0x0(r3)
	  lbz       r0, 0x0(r3)
	  ori       r0, r0, 0x2
	  stb       r0, 0x0(r3)
	  lbz       r0, 0x0(r3)
	  ori       r0, r0, 0x4
	  stb       r0, 0x0(r3)

	.loc_0x22C:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0xE
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7490
 * Size:	000190
 */
void PikiNukareState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x3C
	  bge-      .loc_0x178
	  cmpwi     r0, 0
	  bge-      .loc_0xB8
	  b         .loc_0x178

	.loc_0x3C:
	  lwz       r3, 0x3178(r13)
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  bl        0xA586C
	  lwz       r3, 0x28C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x84
	  bl        0x3EB94
	  cmpwi     r3, 0x5
	  bne-      .loc_0x84
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xF
	  li        r6, 0
	  li        r7, 0
	  bl        0xC562C
	  b         .loc_0x178

	.loc_0x84:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x32
	  li        r6, 0
	  li        r7, 0
	  bl        0xC5610
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x33
	  li        r6, 0
	  li        r7, 0
	  bl        0xC55F8
	  b         .loc_0x178

	.loc_0xB8:
	  lwz       r3, 0x504(r31)
	  li        r4, 0x1
	  lfs       f0, 0xA0(r3)
	  stfs      f0, 0x8C(r31)
	  lfs       f0, 0x8C(r31)
	  stfs      f0, 0xA0(r31)
	  lwz       r3, 0x44C(r31)
	  lwz       r0, 0x450(r31)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x454(r31)
	  stw       r0, 0x9C(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x6F680
	  lfs       f0, 0x98(r31)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x110
	  lfs       f0, -0x68E8(r2)
	  fadds     f0, f0, f1
	  stfs      f0, 0x98(r31)

	.loc_0x110:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x504(r31)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0xA3FC
	  lwz       r4, 0x504(r31)
	  lwz       r0, 0x310(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x178
	  lwz       r3, 0x30C(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x30C(r4)
	  lwz       r5, 0x504(r31)
	  lwz       r4, 0x224(r5)
	  lwz       r3, 0x30C(r5)
	  lwz       r0, 0x3F8(r4)
	  cmpw      r3, r0
	  blt-      .loc_0x178
	  li        r0, 0x1
	  stw       r0, 0x310(r5)

	.loc_0x178:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7620
 * Size:	000050
 */
PikiAutoNukiState::PikiAutoNukiState()
    : PikiState(PIKISTATE_AutoNuki, "AUTONUKI")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x5
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r4, 0x5DC4
	  subi      r5, r5, 0x72C8
	  stw       r0, 0x0(r3)
	  lis       r4, 0x802C
	  subi      r0, r4, 0x6FB0
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7670
 * Size:	0000DC
 */
void PikiAutoNukiState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r27, 0x2C(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r3, r1, 0x20
	  li        r4, 0x1
	  lwz       r5, -0x683C(r2)
	  lwz       r0, -0x6838(r2)
	  stw       r5, 0x20(r1)
	  stw       r0, 0x24(r1)
	  bl        0x3EA70
	  cmplwi    r28, 0
	  addi      r29, r3, 0
	  addi      r30, r28, 0
	  beq-      .loc_0x48
	  addi      r30, r30, 0x2B8

	.loc_0x48:
	  addi      r3, r1, 0x10
	  addi      r4, r29, 0
	  bl        0x47898
	  addi      r31, r3, 0
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  bl        0x478B8
	  addi      r4, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r28, 0x354
	  bl        0x48384
	  li        r0, 0
	  stb       r0, 0x10(r27)
	  lfs       f0, -0x3D6C(r13)
	  stfs      f0, 0x70(r28)
	  lfs       f0, -0x3D68(r13)
	  stfs      f0, 0x74(r28)
	  lfs       f0, -0x3D64(r13)
	  stfs      f0, 0x78(r28)
	  lfs       f0, -0x3D60(r13)
	  stfs      f0, 0xA4(r28)
	  lfs       f0, -0x3D5C(r13)
	  stfs      f0, 0xA8(r28)
	  lfs       f0, -0x3D58(r13)
	  stfs      f0, 0xAC(r28)
	  lfs       f0, -0x3D54(r13)
	  stfs      f0, 0xBC(r28)
	  lfs       f0, -0x3D50(r13)
	  stfs      f0, 0xC0(r28)
	  lfs       f0, -0x3D4C(r13)
	  stfs      f0, 0xC4(r28)
	  lwz       r0, 0x44(r1)
	  lmw       r27, 0x2C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D774C
 * Size:	000078
 */
void PikiAutoNukiState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x32
	  li        r6, 0
	  li        r7, 0
	  bl        0xC53B0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x33
	  li        r6, 0
	  li        r7, 0
	  bl        0xC5398
	  li        r0, 0
	  stb       r0, 0x10(r30)

	.loc_0x60:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D77C4
 * Size:	000004
 */
void PikiAutoNukiState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D77C8
 * Size:	00009C
 */
void PikiAutoNukiState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x34
	  bge-      .loc_0x88
	  cmpwi     r0, 0
	  bge-      .loc_0x48
	  b         .loc_0x88

	.loc_0x34:
	  li        r0, 0x1
	  stb       r0, 0x10(r3)
	  li        r3, 0x147
	  bl        -0x3242C
	  b         .loc_0x88

	.loc_0x48:
	  lwz       r6, 0x44C(r31)
	  addi      r4, r31, 0
	  lwz       r0, 0x450(r31)
	  li        r5, 0
	  stw       r6, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x454(r31)
	  stw       r0, 0x9C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x504(r31)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0xA680

	.loc_0x88:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7864
 * Size:	00004C
 */
PikiPressedState::PikiPressedState()
    : PikiState(PIKISTATE_Pressed, "PRESSED")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x21
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3D48
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x704C
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D78B0
 * Size:	000024
 */
void PikiPressedState::procCollideMsg(Piki*, MsgCollide*)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x4(r5)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x37
	  bnelr-
	  lfs       f0, -0x6898(r2)
	  li        r0, 0x1
	  stfs      f0, 0x10(r3)
	  stb       r0, 0x14(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D78D4
 * Size:	000034
 */
void PikiPressedState::init(Piki*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x224(r4)
	  li        r0, 0x1
	  lfs       f1, -0x68C0(r2)
	  lfs       f0, 0xA8(r5)
	  fmuls     f1, f1, f0
	  stfs      f1, 0x7C(r4)
	  lfs       f0, -0x3D40(r13)
	  stfs      f0, 0x80(r4)
	  stfs      f1, 0x84(r4)
	  lfs       f0, -0x6898(r2)
	  stfs      f0, 0x10(r3)
	  stb       r0, 0x14(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7908
 * Size:	000140
 */
void PikiPressedState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x48(r1)
	  mr        r30, r3
	  lbz       r0, 0x14(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x3C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x48C(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x48C(r31)

	.loc_0x3C:
	  lwz       r4, 0x224(r31)
	  lfs       f2, 0x48C(r31)
	  lfs       f1, 0x168(r4)
	  lfs       f0, 0x178(r4)
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x8C
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x8C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x7
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x128

	.loc_0x8C:
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0xCC
	  stfs      f0, 0x48C(r31)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  lwz       r12, 0x0(r30)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x224(r31)
	  lfs       f0, 0xA8(r3)
	  stfs      f0, 0x7C(r31)
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x84(r31)

	.loc_0xCC:
	  lfs       f0, -0x3D3C(r13)
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x3D38(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x3D34(r13)
	  stfs      f0, 0x78(r31)
	  lfs       f0, -0x3D30(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x3D2C(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x3D28(r13)
	  stfs      f0, 0xAC(r31)
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x120
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r30)
	  b         .loc_0x128

	.loc_0x120:
	  li        r0, 0
	  stb       r0, 0x14(r30)

	.loc_0x128:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7A48
 * Size:	000004
 */
void PikiPressedState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D7A4C
 * Size:	00004C
 */
PikiDyingState::PikiDyingState()
    : PikiState(PIKISTATE_Dying, "DYING")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x6
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3D24
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x70E8
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7A98
 * Size:	00011C
 */
void PikiDyingState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  stw       r28, 0x48(r1)
	  mr        r28, r4
	  lwz       r3, 0x4F8(r4)
	  li        r4, 0
	  bl        -0x1277C
	  lis       r3, 0x8022
	  addi      r6, r3, 0x24D8
	  lwz       r5, 0x0(r6)
	  addi      r3, r1, 0x2C
	  lwz       r0, 0x4(r6)
	  li        r4, 0x3
	  stw       r5, 0x2C(r1)
	  stw       r0, 0x30(r1)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x34(r1)
	  stw       r0, 0x38(r1)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x3C(r1)
	  stw       r0, 0x40(r1)
	  bl        0x3E60C
	  cmplwi    r28, 0
	  addi      r29, r3, 0
	  addi      r30, r28, 0
	  beq-      .loc_0x84
	  addi      r30, r30, 0x2B8

	.loc_0x84:
	  addi      r3, r1, 0x14
	  addi      r4, r29, 0
	  bl        0x47434
	  addi      r31, r3, 0
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x1C
	  bl        0x47454
	  addi      r4, r3, 0
	  addi      r3, r28, 0
	  addi      r5, r31, 0
	  bl        -0xD170
	  mr        r3, r28
	  bl        -0xFCE0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xFC
	  lwz       r29, 0x2AC(r28)
	  li        r3, 0xA
	  li        r0, 0
	  stw       r3, 0x24(r1)
	  addi      r4, r29, 0
	  addi      r5, r1, 0x24
	  stw       r0, 0x28(r1)
	  lwz       r3, 0x2E8(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  bl        -0x4D1BC

	.loc_0xFC:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  lwz       r28, 0x48(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7BB4
 * Size:	000034
 */
void PikiDyingState::exec(Piki*)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x3D1C(r13)
	  stfs      f0, 0x70(r4)
	  lfs       f0, -0x3D18(r13)
	  stfs      f0, 0x74(r4)
	  lfs       f0, -0x3D14(r13)
	  stfs      f0, 0x78(r4)
	  lfs       f0, -0x3D10(r13)
	  stfs      f0, 0xA4(r4)
	  lfs       f0, -0x3D0C(r13)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, -0x3D08(r13)
	  stfs      f0, 0xAC(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7BE8
 * Size:	000004
 */
void PikiDyingState::cleanup(Piki*) { }

/*
 * --INFO--
 * Address:	800D7BEC
 * Size:	000090
 */
void PikiDyingState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x30
	  b         .loc_0x78

	.loc_0x30:
	  lhz       r0, 0x524(r31)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x5C
	  mr        r3, r31
	  bl        -0xFD10
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x464
	  li        r4, 0x1D
	  li        r6, 0
	  li        r7, 0
	  bl        0xC4EF4

	.loc_0x5C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x7
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x78:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7C7C
 * Size:	00004C
 */
PikiDeadState::PikiDeadState()
    : PikiState(PIKISTATE_Dead, "DEAD")
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x7
	  lis       r5, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802C
	  stw       r0, 0x8(r3)
	  subi      r0, r5, 0x5DC4
	  subi      r5, r13, 0x3D04
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x7180
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7CC8
 * Size:	000034
 */
void PikiDeadState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lfs       f0, -0x6898(r2)
	  stfs      f0, 0x48C(r4)
	  lhz       r0, 0x4FC(r4)
	  subfic    r0, r0, 0x1
	  bl        -0x47470
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7CFC
 * Size:	00009C
 */
void PikiDeadState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lfs       f0, -0x6898(r2)
	  lfs       f1, 0x48C(r4)
	  fdivs     f0, f1, f0
	  stfs      f0, 0x7C(r4)
	  stfs      f0, 0x80(r4)
	  stfs      f0, 0x84(r4)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x48C(r4)
	  lfs       f0, 0x28C(r3)
	  lfs       f1, -0x6834(r2)
	  fsubs     f0, f2, f0
	  fcmpo     cr0, f2, f1
	  stfs      f0, 0x48C(r4)
	  lfs       f0, -0x3CFC(r13)
	  stfs      f0, 0xA4(r4)
	  lfs       f0, -0x3CF8(r13)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, -0x3CF4(r13)
	  stfs      f0, 0xAC(r4)
	  lfs       f0, -0x3CF0(r13)
	  stfs      f0, 0x70(r4)
	  lfs       f0, -0x3CEC(r13)
	  stfs      f0, 0x74(r4)
	  lfs       f0, -0x3CE8(r13)
	  stfs      f0, 0x78(r4)
	  lfs       f1, 0x48C(r4)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x8C
	  addi      r3, r4, 0
	  li        r4, 0
	  bl        -0x4D0A4

	.loc_0x8C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7D98
 * Size:	00001C
 */
void PikiDeadState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x3CE4(r13)
	  stfs      f0, 0x7C(r4)
	  lfs       f0, -0x3CE0(r13)
	  stfs      f0, 0x80(r4)
	  lfs       f0, -0x3CDC(r13)
	  stfs      f0, 0x84(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7DB4
 * Size:	000060
 */
PikiEmotionState::PikiEmotionState()
    : PikiState(PIKISTATE_Emotion, "EMOTION")
    , _10(0.0f)
    , _1D(0)
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  subi      r0, r4, 0x7E08
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5E4C
	  stw       r0, 0x0(r3)
	  li        r0, 0x1F
	  li        r6, 0
	  stw       r0, 0x4(r3)
	  lis       r5, 0x802C
	  subi      r0, r5, 0x5DC4
	  stw       r6, 0x8(r3)
	  subi      r5, r13, 0x3CD8
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x7218
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  lfs       f0, -0x68D0(r2)
	  stfs      f0, 0x18(r3)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stb       r6, 0x1D(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D7E14
 * Size:	000784
 */
void PikiEmotionState::init(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x190(r1)
	  stmw      r27, 0x17C(r1)
	  addi      r30, r3, 0
	  addi      r31, r4, 0
	  stb       r0, 0x1C(r3)
	  lis       r3, 0x8022
	  addi      r5, r3, 0x24D8
	  lbz       r0, 0x400(r4)
	  cmplwi    r0, 0xA
	  beq-      .loc_0x770
	  cmplwi    r0, 0x9
	  bgt-      .loc_0x770
	  lis       r3, 0x802C
	  subi      r3, r3, 0x72BC
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lwz       r0, 0x18(r5)
	  lwz       r4, 0x1C(r5)
	  lwz       r3, -0x6830(r2)
	  stw       r0, 0x158(r1)
	  lwz       r0, -0x682C(r2)
	  stw       r4, 0x15C(r1)
	  lwz       r6, 0x20(r5)
	  lwz       r4, 0x24(r5)
	  stw       r6, 0x160(r1)
	  stw       r3, 0x150(r1)
	  stw       r4, 0x164(r1)
	  stw       r0, 0x154(r1)
	  bl        0x1401D8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x174(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  addi      r6, r1, 0x158
	  stw       r0, 0x170(r1)
	  lfs       f2, -0x68E8(r2)
	  addi      r4, r1, 0x150
	  lfd       f1, 0x170(r1)
	  addi      r5, r31, 0x94
	  lfs       f0, -0x68C0(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6820(r2)
	  lwz       r3, 0x3038(r13)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x168(r1)
	  lwz       r0, 0x16C(r1)
	  rlwinm    r7,r0,3,0,28
	  rlwinm    r0,r0,2,0,29
	  lwzx      r28, r6, r7
	  lwzx      r4, r4, r0
	  bl        -0x33AFC
	  cmplwi    r31, 0
	  addi      r30, r31, 0
	  beq-      .loc_0x104
	  addi      r30, r30, 0x2B8

	.loc_0x104:
	  addi      r3, r1, 0xB8
	  addi      r4, r28, 0
	  bl        0x47038
	  addi      r29, r3, 0
	  addi      r4, r28, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0xC0
	  bl        0x47058
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xD56C
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x144
	  addi      r4, r4, 0x2B8

	.loc_0x144:
	  addi      r3, r31, 0x354
	  bl        0x47B64
	  b         .loc_0x770
	  lwz       r3, 0x28(r5)
	  lwz       r0, 0x2C(r5)
	  stw       r3, 0x138(r1)
	  stw       r0, 0x13C(r1)
	  lwz       r3, 0x30(r5)
	  lwz       r0, 0x34(r5)
	  stw       r3, 0x140(r1)
	  stw       r0, 0x144(r1)
	  lwz       r3, 0x38(r5)
	  lwz       r0, 0x3C(r5)
	  stw       r3, 0x148(r1)
	  stw       r0, 0x14C(r1)
	  lwz       r3, 0x40(r5)
	  lwz       r0, 0x44(r5)
	  stw       r3, 0x12C(r1)
	  stw       r0, 0x130(r1)
	  lwz       r0, 0x48(r5)
	  stw       r0, 0x134(r1)
	  bl        0x1400C4
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x16C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  addi      r6, r1, 0x138
	  stw       r0, 0x168(r1)
	  lfs       f2, -0x68E8(r2)
	  addi      r4, r1, 0x12C
	  lfd       f1, 0x168(r1)
	  addi      r5, r31, 0x94
	  lfs       f0, -0x6860(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6820(r2)
	  lwz       r3, 0x3038(r13)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x170(r1)
	  lwz       r0, 0x174(r1)
	  rlwinm    r7,r0,3,0,28
	  rlwinm    r0,r0,2,0,29
	  lwzx      r28, r6, r7
	  lwzx      r4, r4, r0
	  bl        -0x33C10
	  cmplwi    r31, 0
	  addi      r30, r31, 0
	  beq-      .loc_0x218
	  addi      r30, r30, 0x2B8

	.loc_0x218:
	  addi      r3, r1, 0xA8
	  addi      r4, r28, 0
	  bl        0x46F24
	  addi      r29, r3, 0
	  addi      r4, r28, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0xB0
	  bl        0x46F44
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xD680
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x258
	  addi      r4, r4, 0x2B8

	.loc_0x258:
	  addi      r3, r31, 0x354
	  bl        0x47A50
	  b         .loc_0x770
	  lwz       r6, 0x4C(r5)
	  addi      r3, r1, 0x11C
	  lwz       r0, 0x50(r5)
	  li        r4, 0x2
	  stw       r6, 0x11C(r1)
	  stw       r0, 0x120(r1)
	  lwz       r6, 0x54(r5)
	  lwz       r0, 0x58(r5)
	  stw       r6, 0x124(r1)
	  stw       r0, 0x128(r1)
	  bl        0x3E070
	  cmplwi    r31, 0
	  addi      r28, r3, 0
	  addi      r30, r31, 0
	  beq-      .loc_0x2A4
	  addi      r30, r30, 0x2B8

	.loc_0x2A4:
	  addi      r3, r1, 0x98
	  addi      r4, r28, 0
	  bl        0x46E98
	  addi      r29, r3, 0
	  addi      r4, r28, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0xA0
	  bl        0x46EB8
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xD70C
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x2E4
	  addi      r4, r4, 0x2B8

	.loc_0x2E4:
	  addi      r3, r31, 0x354
	  bl        0x479C4
	  b         .loc_0x770
	  lwz       r0, 0x5C(r5)
	  lwz       r4, 0x60(r5)
	  lwz       r3, -0x6828(r2)
	  stw       r0, 0x10C(r1)
	  lwz       r0, -0x6824(r2)
	  stw       r4, 0x110(r1)
	  lwz       r6, 0x64(r5)
	  lwz       r4, 0x68(r5)
	  stw       r6, 0x114(r1)
	  stw       r3, 0x104(r1)
	  stw       r4, 0x118(r1)
	  stw       r0, 0x108(r1)
	  bl        0x13FF3C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x16C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  addi      r6, r1, 0x10C
	  stw       r0, 0x168(r1)
	  lfs       f2, -0x68E8(r2)
	  addi      r4, r1, 0x104
	  lfd       f1, 0x168(r1)
	  addi      r5, r31, 0x94
	  lfs       f0, -0x68C0(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6820(r2)
	  lwz       r3, 0x3038(r13)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x170(r1)
	  lwz       r0, 0x174(r1)
	  rlwinm    r7,r0,3,0,28
	  rlwinm    r0,r0,2,0,29
	  lwzx      r28, r6, r7
	  lwzx      r4, r4, r0
	  bl        -0x33D98
	  cmplwi    r31, 0
	  addi      r30, r31, 0
	  beq-      .loc_0x3A0
	  addi      r30, r30, 0x2B8

	.loc_0x3A0:
	  addi      r3, r1, 0x88
	  addi      r4, r28, 0
	  bl        0x46D9C
	  addi      r29, r3, 0
	  addi      r4, r28, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x90
	  bl        0x46DBC
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xD808
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x3E0
	  addi      r4, r4, 0x2B8

	.loc_0x3E0:
	  addi      r3, r31, 0x354
	  bl        0x478C8
	  b         .loc_0x770
	  cmplwi    r31, 0
	  addi      r30, r31, 0
	  beq-      .loc_0x3FC
	  addi      r30, r30, 0x2B8

	.loc_0x3FC:
	  addi      r3, r1, 0x78
	  li        r4, 0x49
	  bl        0x46D40
	  addi      r29, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x80
	  li        r4, 0x49
	  bl        0x46D60
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xD864
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x43C
	  addi      r4, r4, 0x2B8

	.loc_0x43C:
	  addi      r3, r31, 0x354
	  bl        0x4786C
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xEF
	  bl        -0x33E5C
	  b         .loc_0x770
	  cmplwi    r31, 0
	  addi      r30, r31, 0
	  beq-      .loc_0x468
	  addi      r30, r30, 0x2B8

	.loc_0x468:
	  addi      r3, r1, 0x68
	  li        r4, 0x54
	  bl        0x46CD4
	  addi      r29, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x70
	  li        r4, 0x54
	  bl        0x46CF4
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xD8D0
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x4A8
	  addi      r4, r4, 0x2B8

	.loc_0x4A8:
	  addi      r3, r31, 0x354
	  bl        0x47800
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xE9
	  bl        -0x33EC8
	  b         .loc_0x770
	  cmplwi    r31, 0
	  addi      r30, r31, 0
	  beq-      .loc_0x4D4
	  addi      r30, r30, 0x2B8

	.loc_0x4D4:
	  addi      r3, r1, 0x58
	  li        r4, 0x51
	  bl        0x46C68
	  addi      r29, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x60
	  li        r4, 0x51
	  bl        0x46C88
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xD93C
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x514
	  addi      r4, r4, 0x2B8

	.loc_0x514:
	  addi      r3, r31, 0x354
	  bl        0x47794
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xFE
	  bl        -0x33F34
	  b         .loc_0x770
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x540
	  addi      r28, r28, 0x2B8

	.loc_0x540:
	  addi      r3, r1, 0x48
	  li        r4, 0x3
	  bl        0x46BFC
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x50
	  li        r4, 0x3
	  bl        0x46C1C
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xD9A8
	  lwz       r3, 0x404(r31)
	  li        r29, 0
	  addi      r0, r3, 0x94
	  stw       r0, 0x33C(r31)
	  stb       r29, 0x340(r31)
	  stb       r29, 0x330(r31)
	  lwz       r3, 0x338(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x59C
	  bl        0xBFC4
	  stw       r29, 0x338(r31)

	.loc_0x59C:
	  li        r0, 0x1
	  stb       r0, 0x1C(r30)
	  b         .loc_0x770
	  lwz       r3, 0x6C(r5)
	  lwz       r0, 0x70(r5)
	  stw       r3, 0xDC(r1)
	  stw       r0, 0xE0(r1)
	  lwz       r3, 0x74(r5)
	  lwz       r0, 0x78(r5)
	  stw       r3, 0xE4(r1)
	  stw       r0, 0xE8(r1)
	  lwz       r3, 0x7C(r5)
	  lwz       r0, 0x80(r5)
	  stw       r3, 0xEC(r1)
	  stw       r0, 0xF0(r1)
	  lwz       r3, 0x84(r5)
	  lwz       r0, 0x88(r5)
	  stw       r3, 0xF4(r1)
	  stw       r0, 0xF8(r1)
	  lwz       r3, 0x8C(r5)
	  lwz       r0, 0x90(r5)
	  stw       r3, 0xFC(r1)
	  stw       r0, 0x100(r1)
	  lwz       r3, 0x94(r5)
	  lwz       r0, 0x98(r5)
	  stw       r3, 0xC8(r1)
	  stw       r0, 0xCC(r1)
	  lwz       r3, 0x9C(r5)
	  lwz       r0, 0xA0(r5)
	  stw       r3, 0xD0(r1)
	  stw       r0, 0xD4(r1)
	  lwz       r0, 0xA4(r5)
	  stw       r0, 0xD8(r1)
	  bl        0x13FC3C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x16C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  addi      r6, r1, 0xDC
	  stw       r0, 0x168(r1)
	  lfs       f2, -0x68E8(r2)
	  addi      r4, r1, 0xC8
	  lfd       f1, 0x168(r1)
	  addi      r5, r31, 0x94
	  lfs       f0, -0x6868(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6820(r2)
	  lwz       r3, 0x3038(r13)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x170(r1)
	  lwz       r0, 0x174(r1)
	  rlwinm    r7,r0,3,0,28
	  rlwinm    r0,r0,2,0,29
	  lwzx      r27, r6, r7
	  lwzx      r4, r4, r0
	  bl        -0x34098
	  cmplwi    r31, 0
	  addi      r28, r31, 0
	  beq-      .loc_0x6A0
	  addi      r28, r28, 0x2B8

	.loc_0x6A0:
	  addi      r3, r1, 0x38
	  addi      r4, r27, 0
	  bl        0x46A9C
	  addi      r29, r3, 0
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x40
	  bl        0x46ABC
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xDB08
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x6E0
	  addi      r4, r4, 0x2B8

	.loc_0x6E0:
	  addi      r3, r31, 0x354
	  bl        0x475C8
	  lbz       r0, 0x1D(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x770
	  li        r0, 0x5
	  cmplwi    r31, 0
	  stb       r0, 0x1D(r30)
	  mr        r28, r31
	  beq-      .loc_0x70C
	  addi      r28, r28, 0x2B8

	.loc_0x70C:
	  addi      r3, r1, 0x28
	  li        r4, 0x3
	  bl        0x46A30
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x30
	  li        r4, 0x3
	  bl        0x46A50
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        -0xDB74
	  lwz       r3, 0x404(r31)
	  li        r29, 0
	  addi      r0, r3, 0x94
	  stw       r0, 0x33C(r31)
	  stb       r29, 0x340(r31)
	  stb       r29, 0x330(r31)
	  lwz       r3, 0x338(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x768
	  bl        0xBDF8
	  stw       r29, 0x338(r31)

	.loc_0x768:
	  li        r0, 0x1
	  stb       r0, 0x1C(r30)

	.loc_0x770:
	  lmw       r27, 0x17C(r1)
	  lwz       r0, 0x194(r1)
	  addi      r1, r1, 0x190
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D8598
 * Size:	000004
 */
void PikiEmotionState::doDump() { }

/*
 * --INFO--
 * Address:	800D859C
 * Size:	0001B8
 */
void PikiEmotionState::exec(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x30(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x2C(r1)
	  lfs       f0, -0x3CD0(r13)
	  stfs      f0, 0xA4(r4)
	  lfs       f0, -0x3CCC(r13)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, -0x3CC8(r13)
	  stfs      f0, 0xAC(r4)
	  lbz       r0, 0x400(r4)
	  cmplwi    r0, 0xA
	  bne-      .loc_0x60
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x60:
	  lbz       r0, 0x400(r31)
	  cmplwi    r0, 0x4
	  beq-      .loc_0x80
	  cmplwi    r0, 0x9
	  bne-      .loc_0x19C
	  lbz       r0, 0x1D(r30)
	  cmplwi    r0, 0x5
	  bne-      .loc_0x19C

	.loc_0x80:
	  lbz       r0, 0x1C(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x150
	  bge-      .loc_0x19C
	  cmpwi     r0, 0x1
	  bge-      .loc_0xA0
	  b         .loc_0x19C
	  b         .loc_0x19C

	.loc_0xA0:
	  lwz       r3, 0x404(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x19C
	  li        r0, 0x2
	  stb       r0, 0x1C(r30)
	  addi      r0, r30, 0x10
	  li        r29, 0
	  lwz       r5, 0x404(r31)
	  lwz       r4, 0x94(r5)
	  lwz       r3, 0x98(r5)
	  stw       r4, 0x10(r30)
	  stw       r3, 0x14(r30)
	  lwz       r3, 0x9C(r5)
	  stw       r3, 0x18(r30)
	  stw       r0, 0x33C(r31)
	  stb       r29, 0x340(r31)
	  stb       r29, 0x330(r31)
	  lwz       r3, 0x338(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x108
	  bl        0xBCD0
	  stw       r29, 0x338(r31)

	.loc_0x108:
	  bl        0x13F9CC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x68D8(r2)
	  stw       r0, 0x24(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x68E4(r2)
	  stw       r0, 0x20(r1)
	  lfs       f2, -0x68E8(r2)
	  lfd       f1, 0x20(r1)
	  lfs       f0, -0x6840(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6898(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r30)
	  b         .loc_0x19C

	.loc_0x150:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x20(r30)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x20(r30)
	  lfs       f1, 0x20(r30)
	  lfs       f0, -0x68D0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x19C
	  mr        r3, r31
	  bl        0xFB0
	  li        r0, 0x3
	  cmplwi    r31, 0
	  stb       r0, 0x1C(r30)
	  mr        r4, r31
	  beq-      .loc_0x194
	  addi      r4, r4, 0x2B8

	.loc_0x194:
	  addi      r3, r31, 0x354
	  bl        0x4738C

	.loc_0x19C:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D8754
 * Size:	000034
 */
void PikiEmotionState::cleanup(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0xA
	  stwu      r1, -0x8(r1)
	  stb       r0, 0x400(r4)
	  li        r0, 0
	  stw       r0, 0x404(r4)
	  bl        0xF50
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D8788
 * Size:	000084
 */
void PikiEmotionState::procAnimMsg(Piki*, MsgAnim*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x4(r5)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x20
	  b         .loc_0x74

	.loc_0x20:
	  lbz       r0, 0x400(r4)
	  cmplwi    r0, 0x9
	  bne-      .loc_0x58
	  lbz       r5, 0x1D(r3)
	  subi      r0, r5, 0x1
	  stb       r0, 0x1D(r3)
	  lbz       r0, 0x1D(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x58
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x74

	.loc_0x58:
	  li        r0, 0
	  stb       r0, 0x1D(r3)
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D880C
 * Size:	000008
 */
bool PikiDeadState::useLookUpdate() { return false; }

/*
 * --INFO--
 * Address:	800D8814
 * Size:	000008
 */
bool PikiDyingState::useLookUpdate() { return false; }

/*
 * --INFO--
 * Address:	800D881C
 * Size:	000008
 */
bool PikiPressedState::useLookUpdate() { return false; }

/*
 * --INFO--
 * Address:	800D8824
 * Size:	000008
 */
bool PikiAutoNukiState::useLookUpdate() { return false; }

/*
 * --INFO--
 * Address:	800D882C
 * Size:	000008
 */
bool PikiNukareState::useLookUpdate() { return false; }

/*
 * --INFO--
 * Address:	800D8834
 * Size:	000008
 */
bool PikiNukareWaitState::useLookUpdate() { return false; }

/*
 * --INFO--
 * Address:	800D883C
 * Size:	000008
 */
bool PikiGrowupState::useLookUpdate() { return false; }

/*
 * --INFO--
 * Address:	800D8844
 * Size:	000008
 */
bool PikiKinokoChangeState::useLookUpdate() { return false; }

/*
 * --INFO--
 * Address:	800D884C
 * Size:	000008
 */
bool PikiGrowState::useLookUpdate() { return false; }

/*
 * --INFO--
 * Address:	800D8854
 * Size:	000008
 */
bool PikiNormalState::collideAI() { return true; }

/*
 * --INFO--
 * Address:	800D885C
 * Size:	000008
 */
bool PikiNormalState::freeAI() { return true; }

/*
 * --INFO--
 * Address:	800D8864
 * Size:	000030
 */
void AState<Piki>::transit(Piki*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x8(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
