#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8012E48C
 * Size:	000014
 */
void TaiBounceAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  neg       r0, r0
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E4A0
 * Size:	000014
 */
void TaiGroundCollisionAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  neg       r0, r0
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E4B4
 * Size:	000014
 */
void TaiWallCollisionAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  subfic    r0, r0, 0x2
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E4C8
 * Size:	000014
 */
void TaiCreatureCollisionAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  subfic    r0, r0, 0x1
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E4DC
 * Size:	00003C
 */
void TaiPikiCollisionAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x14
	  li        r3, 0
	  blr

	.loc_0x14:
	  lwz       r3, 0x8(r4)
	  cmplwi    r3, 0
	  bne-      .loc_0x28
	  li        r3, 0
	  blr

	.loc_0x28:
	  lwz       r0, 0x6C(r3)
	  neg       r0, r0
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E518
 * Size:	00003C
 */
void TaiNaviCollisionAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x14
	  li        r3, 0
	  blr

	.loc_0x14:
	  lwz       r3, 0x8(r4)
	  cmplwi    r3, 0
	  bne-      .loc_0x28
	  li        r3, 0
	  blr

	.loc_0x28:
	  lwz       r0, 0x6C(r3)
	  subfic    r0, r0, 0x36
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E554
 * Size:	000054
 */
void TaiTekiTypeCollisionAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x14
	  li        r3, 0
	  blr

	.loc_0x14:
	  lwz       r4, 0x8(r4)
	  cmplwi    r4, 0
	  bne-      .loc_0x28
	  li        r3, 0
	  blr

	.loc_0x28:
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x37
	  beq-      .loc_0x3C
	  li        r3, 0
	  blr

	.loc_0x3C:
	  lwz       r4, 0x320(r4)
	  lwz       r0, 0x8(r3)
	  sub       r0, r0, r4
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}
