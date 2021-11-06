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
 * Address:	8007CDFC
 * Size:	00015C
 */
void SAIEventInit()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x8
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x35E08
  cmplwi    r3, 0
  beq-      .loc_0x48
  lis       r4, 0x802B
  subi      r0, r4, 0x2950
  lis       r4, 0x802B
  stw       r0, 0x0(r3)
  subi      r0, r4, 0x2988
  stw       r0, 0x0(r3)
  li        r0, -0x1
  lis       r4, 0x802B
  stw       r0, 0x4(r3)
  subi      r0, r4, 0x29C0
  stw       r0, 0x0(r3)

.loc_0x48:
  stw       r3, 0x2F30(r13)
  li        r3, 0x8
  bl        -0x35E48
  cmplwi    r3, 0
  beq-      .loc_0x88
  lis       r4, 0x802B
  subi      r0, r4, 0x2950
  lis       r4, 0x802B
  stw       r0, 0x0(r3)
  subi      r0, r4, 0x2988
  stw       r0, 0x0(r3)
  li        r0, -0x1
  lis       r4, 0x802B
  stw       r0, 0x4(r3)
  subi      r0, r4, 0x2B4C
  stw       r0, 0x0(r3)

.loc_0x88:
  stw       r3, 0x2F34(r13)
  li        r3, 0x8
  bl        -0x35E88
  cmplwi    r3, 0
  beq-      .loc_0xC8
  lis       r4, 0x802B
  subi      r0, r4, 0x2950
  lis       r4, 0x802B
  stw       r0, 0x0(r3)
  subi      r0, r4, 0x2988
  stw       r0, 0x0(r3)
  li        r0, -0x1
  lis       r4, 0x802B
  stw       r0, 0x4(r3)
  subi      r0, r4, 0x2BA8
  stw       r0, 0x0(r3)

.loc_0xC8:
  stw       r3, 0x2F40(r13)
  li        r3, 0x8
  bl        -0x35EC8
  cmplwi    r3, 0
  beq-      .loc_0x108
  lis       r4, 0x802B
  subi      r0, r4, 0x2950
  lis       r4, 0x802B
  stw       r0, 0x0(r3)
  subi      r0, r4, 0x2988
  stw       r0, 0x0(r3)
  li        r0, -0x1
  lis       r4, 0x802B
  stw       r0, 0x4(r3)
  subi      r0, r4, 0x2C04
  stw       r0, 0x0(r3)

.loc_0x108:
  stw       r3, 0x2F44(r13)
  li        r3, 0x8
  bl        -0x35F08
  cmplwi    r3, 0
  beq-      .loc_0x148
  lis       r4, 0x802B
  subi      r0, r4, 0x2950
  lis       r4, 0x802B
  stw       r0, 0x0(r3)
  subi      r0, r4, 0x2988
  stw       r0, 0x0(r3)
  li        r0, -0x1
  lis       r4, 0x802B
  stw       r0, 0x4(r3)
  subi      r0, r4, 0x2A20
  stw       r0, 0x0(r3)

.loc_0x148:
  stw       r3, 0x2F48(r13)
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007CF58
 * Size:	000040
 */
void SAIMotionDoneEvent::procAnimMsg(AICreature *, MsgAnim *)
{
/*
.loc_0x0:
  mflr      r0
  mr        r6, r4
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r5, 0x4(r5)
  lwz       r4, 0x4(r3)
  addi      r3, r6, 0
  lwz       r0, 0x0(r5)
  neg       r0, r0
  cntlzw    r0, r0
  rlwinm    r5,r0,27,5,31
  bl        0x544
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007CF98
 * Size:	000040
 */
void SAIMotionAction0Event::procAnimMsg(AICreature *, MsgAnim *)
{
/*
.loc_0x0:
  mflr      r0
  mr        r6, r4
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r5, 0x4(r5)
  lwz       r4, 0x4(r3)
  addi      r3, r6, 0
  lwz       r0, 0x0(r5)
  subfic    r0, r0, 0x1
  cntlzw    r0, r0
  rlwinm    r5,r0,27,5,31
  bl        0x504
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007CFD8
 * Size:	000040
 */
void SAIMotionLoopStartEvent::procAnimMsg(AICreature *, MsgAnim *)
{
/*
.loc_0x0:
  mflr      r0
  mr        r6, r4
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r5, 0x4(r5)
  lwz       r4, 0x4(r3)
  addi      r3, r6, 0
  lwz       r0, 0x0(r5)
  subfic    r0, r0, 0x5
  cntlzw    r0, r0
  rlwinm    r5,r0,27,5,31
  bl        0x4C4
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007D018
 * Size:	000040
 */
void SAIMotionLoopEndEvent::procAnimMsg(AICreature *, MsgAnim *)
{
/*
.loc_0x0:
  mflr      r0
  mr        r6, r4
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r5, 0x4(r5)
  lwz       r4, 0x4(r3)
  addi      r3, r6, 0
  lwz       r0, 0x0(r5)
  subfic    r0, r0, 0x6
  cntlzw    r0, r0
  rlwinm    r5,r0,27,5,31
  bl        0x484
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007D058
 * Size:	000030
 */
void SAIBounceEvent::procBounceMsg(AICreature *, MsgBounce *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  mr        r0, r4
  stwu      r1, -0x8(r1)
  lwz       r4, 0x4(r3)
  mr        r3, r0
  bl        0x454
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007D088
 * Size:	000030
 */
void SAICollideEvent::procCollideMsg(AICreature *, MsgCollide *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  mr        r0, r4
  stwu      r1, -0x8(r1)
  lwz       r4, 0x4(r3)
  mr        r3, r0
  bl        0x424
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007D0B8
 * Size:	000030
 */
void SAIGroundEvent::procGroundMsg(AICreature *, MsgGround *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  mr        r0, r4
  stwu      r1, -0x8(r1)
  lwz       r4, 0x4(r3)
  mr        r3, r0
  bl        0x3F4
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007D0E8
 * Size:	000040
 */
void SAIUserEvent::procUserMsg(AICreature *, MsgUser *)
{
/*
.loc_0x0:
  mflr      r0
  mr        r6, r4
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x4(r5)
  lwz       r5, 0x8(r3)
  lwz       r4, 0x4(r3)
  addi      r3, r6, 0
  sub       r0, r0, r5
  cntlzw    r0, r0
  rlwinm    r5,r0,27,5,31
  bl        0x3B4
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007D128
 * Size:	000004
 */
void Receiver<AICreature>::procBounceMsg(AICreature *, MsgBounce *)
{
}

/*
 * --INFO--
 * Address:	8007D12C
 * Size:	000004
 */
void Receiver<AICreature>::procStickMsg(AICreature *, MsgStick *)
{
}

/*
 * --INFO--
 * Address:	8007D130
 * Size:	000004
 */
void Receiver<AICreature>::procHangMsg(AICreature *, MsgHang *)
{
}

/*
 * --INFO--
 * Address:	8007D134
 * Size:	000004
 */
void Receiver<AICreature>::procTargetMsg(AICreature *, MsgTarget *)
{
}

/*
 * --INFO--
 * Address:	8007D138
 * Size:	000004
 */
void Receiver<AICreature>::procCollideMsg(AICreature *, MsgCollide *)
{
}

/*
 * --INFO--
 * Address:	8007D13C
 * Size:	000004
 */
void Receiver<AICreature>::procAnimMsg(AICreature *, MsgAnim *)
{
}

/*
 * --INFO--
 * Address:	8007D140
 * Size:	000004
 */
void Receiver<AICreature>::procDamageMsg(AICreature *, MsgDamage *)
{
}

/*
 * --INFO--
 * Address:	8007D144
 * Size:	000004
 */
void Receiver<AICreature>::procWallMsg(AICreature *, MsgWall *)
{
}

/*
 * --INFO--
 * Address:	8007D148
 * Size:	000004
 */
void Receiver<AICreature>::procOffWallMsg(AICreature *, MsgOffWall *)
{
}

/*
 * --INFO--
 * Address:	8007D14C
 * Size:	000004
 */
void Receiver<AICreature>::procUserMsg(AICreature *, MsgUser *)
{
}

/*
 * --INFO--
 * Address:	8007D150
 * Size:	000004
 */
void Receiver<AICreature>::procGroundMsg(AICreature *, MsgGround *)
{
}

/*
 * --INFO--
 * Address:	8007D154
 * Size:	000118
 */
void Receiver<AICreature>::procMsg(AICreature *, Msg *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x0(r5)
  cmplwi    r0, 0xA
  bgt-      .loc_0x108
  lis       r6, 0x802B
  subi      r6, r6, 0x2918
  rlwinm    r0,r0,2,0,29
  lwzx      r0, r6, r0
  mtctr     r0
  bctr      
  lwz       r12, 0x0(r3)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  b         .loc_0x108
  lwz       r12, 0x0(r3)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  b         .loc_0x108
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  b         .loc_0x108
  lwz       r12, 0x0(r3)
  lwz       r12, 0x18(r12)
  mtlr      r12
  blrl      
  b         .loc_0x108
  lwz       r12, 0x0(r3)
  lwz       r12, 0x1C(r12)
  mtlr      r12
  blrl      
  b         .loc_0x108
  lwz       r12, 0x0(r3)
  lwz       r12, 0x20(r12)
  mtlr      r12
  blrl      
  b         .loc_0x108
  lwz       r12, 0x0(r3)
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      
  b         .loc_0x108
  lwz       r12, 0x0(r3)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  b         .loc_0x108
  lwz       r12, 0x0(r3)
  lwz       r12, 0x2C(r12)
  mtlr      r12
  blrl      
  b         .loc_0x108
  lwz       r12, 0x0(r3)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  b         .loc_0x108
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      

.loc_0x108:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}
