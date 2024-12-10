#include "jaudio/playercall.h"

static PLAYER_CALL PLAYER_CALLLIST[16];

/*
 * --INFO--
 * Address:	80007120
 * Size:	00002C
 */
void ResetPlayerCallback()
{
	int i;

	for (i = 0; i < 16; i++) {
		PLAYER_CALLLIST[i].callback = nullptr;
	}
	/*
	.loc_0x0:
	  li        r3, 0
	  lis       r4, 0x802F
	  li        r0, 0x10
	  addi      r6, r3, 0
	  subi      r5, r4, 0x68B0
	  mtctr     r0

	.loc_0x18:
	  add       r4, r5, r3
	  addi      r3, r3, 0xC
	  stw       r6, 0x0(r4)
	  bdnz+     .loc_0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007160
 * Size:	000050
 */
s32 Jac_CheckPlayerCallback(PlayerCallBack, void*)
{
	/*
	.loc_0x0:
	  lis       r5, 0x802F
	  li        r0, 0x10
	  subi      r6, r5, 0x68B0
	  li        r8, 0
	  li        r5, 0
	  mtctr     r0

	.loc_0x18:
	  add       r7, r6, r5
	  lwz       r0, 0x0(r7)
	  cmplw     r0, r3
	  bne-      .loc_0x3C
	  lwz       r0, 0x4(r7)
	  cmplw     r0, r4
	  bne-      .loc_0x3C
	  mr        r3, r8
	  blr

	.loc_0x3C:
	  addi      r8, r8, 0x1
	  addi      r5, r5, 0xC
	  bdnz+     .loc_0x18
	  li        r3, -0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void Jac_RejectPlayerCallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800071C0
 * Size:	000048
 */
s32 Jac_RegisterDspPlayerCallback(PlayerCallBack, void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x54
	  cmpwi     r3, -0x1
	  bne-      .loc_0x20
	  li        r3, -0x1
	  b         .loc_0x38

	.loc_0x20:
	  mulli     r0, r3, 0xC
	  lis       r4, 0x802F
	  subi      r4, r4, 0x68B0
	  li        r5, 0x1
	  add       r4, r4, r0
	  stw       r5, 0x8(r4)

	.loc_0x38:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007220
 * Size:	0000A4
 */
s32 Jac_RegisterPlayerCallback(PlayerCallBack, void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802F
	  stw       r0, 0x4(r1)
	  li        r0, 0x10
	  stwu      r1, -0x20(r1)
	  stmw      r28, 0x10(r1)
	  addi      r28, r3, 0
	  addi      r29, r4, 0
	  subi      r31, r5, 0x68B0
	  li        r30, 0
	  li        r3, 0
	  mtctr     r0

	.loc_0x30:
	  lwzx      r0, r31, r3
	  cmplwi    r0, 0
	  beq-      .loc_0x48
	  addi      r30, r30, 0x1
	  addi      r3, r3, 0xC
	  bdnz+     .loc_0x30

	.loc_0x48:
	  cmplwi    r30, 0x10
	  bne-      .loc_0x58
	  li        r3, -0x1
	  b         .loc_0x90

	.loc_0x58:
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        -0x120
	  cmpwi     r3, -0x1
	  beq-      .loc_0x74
	  li        r3, -0x1
	  b         .loc_0x90

	.loc_0x74:
	  mulli     r4, r30, 0xC
	  li        r0, 0
	  addi      r3, r30, 0
	  stwx      r28, r31, r4
	  add       r4, r31, r4
	  stw       r29, 0x4(r4)
	  stw       r0, 0x8(r4)

	.loc_0x90:
	  lmw       r28, 0x10(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800072E0
 * Size:	00007C
 */
void PlayerCallback()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802F
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r27, 0xC(r1)
	  li        r31, 0
	  addi      r30, r31, 0
	  subi      r29, r3, 0x68B0
	  li        r27, 0

	.loc_0x24:
	  add       r28, r29, r31
	  lwz       r12, 0x0(r28)
	  cmplwi    r12, 0
	  beq-      .loc_0x58
	  lwz       r0, 0x8(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x58
	  lwz       r3, 0x4(r28)
	  mtlr      r12
	  blrl
	  cmpwi     r3, -0x1
	  bne-      .loc_0x58
	  stw       r30, 0x0(r28)

	.loc_0x58:
	  addi      r27, r27, 0x1
	  addi      r31, r31, 0xC
	  cmplwi    r27, 0x10
	  blt+      .loc_0x24
	  lmw       r27, 0xC(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007360
 * Size:	00007C
 */
void DspPlayerCallback()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802F
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r27, 0xC(r1)
	  li        r31, 0
	  addi      r30, r31, 0
	  subi      r29, r3, 0x68B0
	  li        r27, 0

	.loc_0x24:
	  add       r28, r29, r31
	  lwz       r12, 0x0(r28)
	  cmplwi    r12, 0
	  beq-      .loc_0x58
	  lwz       r0, 0x8(r28)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x58
	  lwz       r3, 0x4(r28)
	  mtlr      r12
	  blrl
	  cmpwi     r3, -0x1
	  bne-      .loc_0x58
	  stw       r30, 0x0(r28)

	.loc_0x58:
	  addi      r27, r27, 0x1
	  addi      r31, r31, 0xC
	  cmplwi    r27, 0x10
	  blt+      .loc_0x24
	  lmw       r27, 0xC(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
