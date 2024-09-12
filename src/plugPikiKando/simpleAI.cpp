#include "SimpleAI.h"

static char file[] = __FILE__;
static char name[] = "simpleAI";

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
 * Address:	8007D26C
 * Size:	0000A4
 */
AICreature::AICreature(CreatureProp* props)
    : Creature(props)
{
	_2BC = 0;
	_2C4.set(0.0f, 0.0f, 0.0f);
	_2D0 = _2D4   = 0;
	mCurrentState = nullptr;
	_2D8          = 0.0f;
	mCurrentState = nullptr; // hm.
	mMaxEventCnt  = 16;
	clearEventFlags();
}

/*
 * --INFO--
 * Address:	8007D310
 * Size:	00006C
 */
void AICreature::collisionCallback(CollEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r6, r3, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x3
	  stwu      r1, -0x20(r1)
	  lwz       r5, 0x0(r4)
	  stw       r0, 0x10(r1)
	  lwz       r0, 0x0(r4)
	  stw       r0, 0x14(r1)
	  lwz       r0, 0x4(r4)
	  stw       r0, 0x18(r1)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x1C(r1)
	  stw       r5, 0x2BC(r3)
	  lwz       r3, 0x2E8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C
	  lwz       r12, 0x0(r3)
	  addi      r4, r6, 0
	  addi      r5, r1, 0x10
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x5C:
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007D37C
 * Size:	000060
 */
void AICreature::bounceCallback()
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x38(r1)
	  lfs       f0, -0x6294(r13)
	  stw       r0, 0x24(r1)
	  lfs       f1, -0x6290(r13)
	  stfs      f0, 0x28(r1)
	  lfs       f0, -0x628C(r13)
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x30(r1)
	  lwz       r3, 0x2E8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  lwz       r12, 0x0(r3)
	  addi      r5, r1, 0x24
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x50:
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007D3DC
 * Size:	0000B4
 */
void AICreature::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x4
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r3, 0x6C(r3)
	  stw       r0, 0x10(r1)
	  subfic    r0, r3, 0x10
	  stw       r31, 0x14(r1)
	  lwz       r3, 0x2E8(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x54
	  lwz       r12, 0x0(r3)
	  addi      r4, r30, 0
	  addi      r5, r1, 0x10
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x54:
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0x7
	  bne-      .loc_0x78
	  mr        r3, r30
	  lwz       r4, 0x4(r31)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x128(r12)
	  mtlr      r12
	  blrl

	.loc_0x78:
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0x8
	  bne-      .loc_0x9C
	  mr        r3, r30
	  lwz       r4, 0x4(r31)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x12C(r12)
	  mtlr      r12
	  blrl

	.loc_0x9C:
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
 * Address:	8007D490
 * Size:	000004
 */
void AICreature::playEffect(int) { }

/*
 * --INFO--
 * Address:	8007D494
 * Size:	000004
 */
void AICreature::playSound(int) { }

/*
 * --INFO--
 * Address:	8007D498
 * Size:	000030
 */
void AICreature::clearEventFlags()
{
	for (int i = 0; i < mMaxEventCnt; i++) {
		mEventFlags[i] = 0;
	}
	_2EC = 0;
}

/*
 * --INFO--
 * Address:	8007D4C8
 * Size:	00001C
 */
void AICreature::setEventFlag(int flagID, bool value)
{
	if (_2EC < mMaxEventCnt) {
		mEventFlags[flagID] = value;
	}

	/*
	.loc_0x0:
	  lwz       r0, 0x2EC(r3)
	  lwz       r6, 0x2F0(r3)
	  cmpw      r0, r6
	  bgelr-
	  add       r3, r3, r4
	  stb       r5, 0x2F4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void AICreature::checkEventFlag(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8007D4E4
 * Size:	000024
 */
SimpleAI::SimpleAI() { }

/*
 * --INFO--
 * Address:	8007D508
 * Size:	000068
 */
void SimpleAI::procMsg(AICreature*, Msg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r5
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  lwz       r12, 0x0(r3)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x50:
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
 * Address:	8007D570
 * Size:	000008
 */
AState<AICreature>* AICreature::getCurrState() { return mCurrentState; }

/*
 * --INFO--
 * Address:	8007D578
 * Size:	0000E8
 */
void SimpleAI::addState(int, int, SAIAction*, SAIAction*, SAIAction*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r25, 0x34(r1)
	  addi      r31, r3, 0
	  addi      r25, r4, 0
	  addi      r26, r5, 0
	  addi      r27, r6, 0
	  addi      r28, r7, 0
	  addi      r29, r8, 0
	  li        r3, 0x58
	  bl        -0x365A0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x44
	  mr        r4, r25
	  bl        0x430

	.loc_0x44:
	  stw       r26, 0x48(r30)
	  stw       r27, 0x4C(r30)
	  stw       r28, 0x50(r30)
	  stw       r29, 0x54(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0xD4
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x88
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x90

	.loc_0x88:
	  li        r0, 0
	  b         .loc_0x94

	.loc_0x90:
	  li        r0, 0x1

	.loc_0x94:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xD4
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

	.loc_0xD4:
	  lmw       r25, 0x34(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007D660
 * Size:	0000F8
 */
void SimpleAI::addArrow(int, SAIEvent*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  addi      r30, r6, 0
	  li        r3, 0x34
	  bl        -0x36680
	  addi      r31, r3, 0
	  mr.       r7, r31
	  beq-      .loc_0x98
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  lis       r3, 0x802B
	  stw       r0, 0x10(r31)
	  lis       r6, 0x802B
	  subi      r4, r3, 0x28C0
	  stw       r0, 0xC(r31)
	  subi      r3, r6, 0x28CC
	  lis       r5, 0x802B
	  stw       r0, 0x8(r31)
	  subi      r0, r5, 0x26D4
	  stw       r3, 0x4(r31)
	  addi      r3, r7, 0x20
	  stw       r0, 0x0(r31)
	  bl        -0x48728
	  lis       r3, 0x802B
	  subi      r0, r3, 0x26FC
	  stw       r0, 0x20(r31)
	  stw       r29, 0x18(r31)
	  stw       r30, 0x14(r31)

	.loc_0x98:
	  lwz       r3, 0x14(r27)
	  rlwinm    r0,r28,2,0,29
	  addi      r4, r31, 0
	  lwzx      r0, r3, r0
	  cmpwi     r0, -0x1
	  bne-      .loc_0xB8
	  li        r3, 0
	  b         .loc_0xE4

	.loc_0xB8:
	  lwz       r3, 0x4(r27)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r27, r3, r0
	  lwz       r0, 0x44(r27)
	  addi      r3, r27, 0x10
	  stw       r0, 0x1C(r31)
	  bl        -0x3D158
	  lwz       r4, 0x44(r27)
	  addi      r3, r31, 0
	  addi      r0, r4, 0x1
	  stw       r0, 0x44(r27)

	.loc_0xE4:
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007D758
 * Size:	00002C
 */
void SimpleAI::start(AICreature* creature, int stateID) { transit(creature, stateID); }

/*
 * --INFO--
 * Address:	8007D784
 * Size:	0000D8
 */
void StateMachine<AICreature>::transit(AICreature*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r5,2,0,29
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x18(r1)
	  addi      r28, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r4, 0x14(r28)
	  lwz       r12, 0x120(r12)
	  lwzx      r31, r4, r0
	  mtlr      r12
	  blrl
	  mr.       r30, r3
	  beq-      .loc_0x6C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x4(r30)
	  stw       r0, 0x18(r28)

	.loc_0x6C:
	  lwz       r0, 0xC(r28)
	  cmpw      r31, r0
	  blt-      .loc_0x7C

	.loc_0x78:
	  b         .loc_0x78

	.loc_0x7C:
	  mr        r3, r29
	  lwz       r4, 0x4(r28)
	  lwz       r12, 0x0(r29)
	  rlwinm    r0,r31,2,0,29
	  lwzx      r31, r4, r0
	  lwz       r12, 0x124(r12)
	  addi      r4, r31, 0
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r29
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007D85C
 * Size:	000004
 */
void AState<AICreature>::init(AICreature*) { }

/*
 * --INFO--
 * Address:	8007D860
 * Size:	000008
 */
void AICreature::setCurrState(AState<AICreature>* state) { mCurrentState = state; }

/*
 * --INFO--
 * Address:	8007D868
 * Size:	000004
 */
void AState<AICreature>::cleanup(AICreature*) { }

/*
 * --INFO--
 * Address:	8007D86C
 * Size:	00007C
 */
void SimpleAI::exec(AICreature* creature)
{
	AState<AICreature>* state = creature->getCurrState();
	if (state) {
		checkEvent(creature);
		state->exec(creature);
	}
}

/*
 * --INFO--
 * Address:	8007D8E8
 * Size:	0000F8
 */
void SimpleAI::checkEvent(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  addi      r28, r4, 0
	  addi      r27, r3, 0
	  addi      r3, r28, 0
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  beq-      .loc_0xE4
	  lwz       r31, 0x20(r3)
	  b         .loc_0xDC

	.loc_0x3C:
	  lwz       r3, 0x18(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  lwz       r0, 0x1C(r31)
	  stw       r0, 0x4(r3)

	.loc_0x50:
	  lwz       r3, 0x18(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  lwz       r3, 0x4(r3)
	  addi      r0, r3, 0x2F4
	  lbzx      r0, r28, r0
	  cmplwi    r0, 0
	  beq-      .loc_0xD8

	.loc_0x70:
	  lwz       r29, 0x30(r31)
	  li        r30, 0x1
	  b         .loc_0xA8

	.loc_0x7C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xA4
	  li        r30, 0
	  b         .loc_0xB0

	.loc_0xA4:
	  lwz       r29, 0xC(r29)

	.loc_0xA8:
	  cmplwi    r29, 0
	  bne+      .loc_0x7C

	.loc_0xB0:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0xD8
	  mr        r3, r27
	  lwz       r5, 0x14(r31)
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE4

	.loc_0xD8:
	  lwz       r31, 0xC(r31)

	.loc_0xDC:
	  cmplwi    r31, 0
	  bne+      .loc_0x3C

	.loc_0xE4:
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007D9E0
 * Size:	000008
 */
bool SAICondition::satisfy(AICreature*) { return true; }

/*
 * --INFO--
 * Address:	8007D9E8
 * Size:	00010C
 */
SAIState::SAIState(int stateID)
    : AState<AICreature>(stateID)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0x2950
	  lis       r6, 0x802B
	  stwu      r1, -0x20(r1)
	  lis       r5, 0x8022
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x802B
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x27B4
	  lis       r3, 0x8022
	  stw       r0, 0x0(r31)
	  subi      r0, r6, 0x2804
	  stw       r4, 0x4(r31)
	  lis       r4, 0x802B
	  subi      r29, r4, 0x28E8
	  stw       r30, 0x8(r31)
	  addi      r4, r29, 0x28
	  stw       r0, 0x0(r31)
	  addi      r0, r5, 0x738C
	  addi      r5, r29, 0x34
	  stw       r0, 0x10(r31)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x802B
	  stw       r0, 0x10(r31)
	  subi      r0, r3, 0x26D4
	  addi      r3, r31, 0x30
	  stw       r30, 0x20(r31)
	  stw       r30, 0x1C(r31)
	  stw       r30, 0x18(r31)
	  stw       r5, 0x14(r31)
	  stw       r0, 0x10(r31)
	  bl        -0x48AC4
	  lis       r3, 0x802B
	  subi      r0, r3, 0x26FC
	  stw       r0, 0x30(r31)
	  li        r5, -0x1
	  addi      r4, r29, 0x44
	  stw       r5, 0x24(r31)
	  addi      r0, r29, 0x54
	  addi      r3, r31, 0
	  stw       r30, 0x28(r31)
	  stw       r30, 0x40(r31)
	  stw       r30, 0x3C(r31)
	  stw       r30, 0x38(r31)
	  stw       r4, 0x34(r31)
	  stw       r5, 0x48(r31)
	  stw       r30, 0x54(r31)
	  stw       r30, 0x50(r31)
	  stw       r30, 0x4C(r31)
	  stw       r30, 0x20(r31)
	  stw       r30, 0x1C(r31)
	  stw       r30, 0x18(r31)
	  stw       r0, 0x14(r31)
	  stw       r30, 0x44(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DAF4
 * Size:	0000A4
 */
void SAIState::init(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r0, 0x48(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x40
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r0
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl

	.loc_0x40:
	  lwz       r3, 0x4C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x60
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x60:
	  li        r4, 0
	  addi      r3, r4, 0
	  b         .loc_0x78

	.loc_0x6C:
	  addi      r0, r4, 0x2F4
	  stbx      r3, r31, r0
	  addi      r4, r4, 0x1

	.loc_0x78:
	  lwz       r0, 0x2F0(r31)
	  cmpw      r4, r0
	  blt+      .loc_0x6C
	  li        r0, 0
	  stw       r0, 0x2EC(r31)
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
 * Address:	8007DB98
 * Size:	000004
 */
void AICreature::startMotion(int) { }

/*
 * --INFO--
 * Address:	8007DB9C
 * Size:	000074
 */
void SAIState::exec(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  lwz       r3, 0x50(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  li        r4, 0
	  addi      r3, r4, 0
	  b         .loc_0x4C

	.loc_0x40:
	  addi      r0, r4, 0x2F4
	  stbx      r3, r31, r0
	  addi      r4, r4, 0x1

	.loc_0x4C:
	  lwz       r0, 0x2F0(r31)
	  cmpw      r4, r0
	  blt+      .loc_0x40
	  li        r0, 0
	  stw       r0, 0x2EC(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DC10
 * Size:	0000A0
 */
void SAIState::procMsg(AICreature*, Msg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x20(r1)
	  mr        r28, r3
	  lwz       r31, 0x20(r3)
	  b         .loc_0x6C

	.loc_0x30:
	  lwz       r3, 0x18(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  lwz       r0, 0x1C(r31)
	  stw       r0, 0x4(r3)

	.loc_0x44:
	  lwz       r3, 0x18(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x68
	  lwz       r12, 0x0(r3)
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x68:
	  lwz       r31, 0xC(r31)

	.loc_0x6C:
	  cmplwi    r31, 0
	  bne+      .loc_0x30
	  lwz       r3, 0x8(r28)
	  mr        r4, r29
	  bl        -0x3A4
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
 * Address:	8007DCB0
 * Size:	000038
 */
void SAIState::cleanup(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x54(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DCE8
 * Size:	000004
 */
void AICreature::startMotion(int, f32) { }

/*
 * --INFO--
 * Address:	8007DCEC
 * Size:	000004
 */
void AICreature::finishMotion(f32) { }

/*
 * --INFO--
 * Address:	8007DCF0
 * Size:	000004
 */
void AICreature::finishMotion() { }

/*
 * --INFO--
 * Address:	8007DCF4
 * Size:	000008
 */
void AICreature::getCurrentMotionName()
{
	/*
	.loc_0x0:
	  subi      r3, r13, 0x6210
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DCFC
 * Size:	000008
 */
void AICreature::getCurrentMotionCounter()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x768C(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DD04
 * Size:	000008
 */
void AICreature::getMotionSpeed()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x768C(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DD0C
 * Size:	000004
 */
void AICreature::setMotionSpeed(f32) { }

/*
 * --INFO--
 * Address:	8007DD10
 * Size:	000004
 */
void AICreature::stopMotion() { }

/*
 * --INFO--
 * Address:	8007DD14
 * Size:	000008
 */
bool Creature::insideSafeArea(Vector3f&) { return true; }

/*
 * --INFO--
 * Address:	8007DD1C
 * Size:	000008
 */
bool Creature::platAttachable() { return false; }

/*
 * --INFO--
 * Address:	8007DD24
 * Size:	000008
 */
bool Creature::doDoAI() { return true; }

/*
 * --INFO--
 * Address:	8007DD2C
 * Size:	000004
 */
void Creature::setRouteTracer(RouteTracer*) { }

/*
 * --INFO--
 * Address:	8007DD30
 * Size:	000004
 */
void Creature::initParam(int) { }

/*
 * --INFO--
 * Address:	8007DD34
 * Size:	000004
 */
void Creature::startAI(int) { }

/*
 * --INFO--
 * Address:	8007DD38
 * Size:	000008
 */
f32 Creature::getiMass()
{
	return 0.0f;
	/*
	.loc_0x0:
	  lfs       f1, -0x7688(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DD40
 * Size:	000008
 */
f32 Creature::getSize()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x7684(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DD48
 * Size:	000008
 */
f32 Creature::getHeight()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x7690(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DD50
 * Size:	000008
 */
f32 Creature::getCylinderHeight()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x7680(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DD58
 * Size:	000004
 */
void Creature::doStore(CreatureInf*) { }

/*
 * --INFO--
 * Address:	8007DD5C
 * Size:	000004
 */
void Creature::doRestore(CreatureInf*) { }

/*
 * --INFO--
 * Address:	8007DD60
 * Size:	000004
 */
void Creature::doSave(RandomAccessStream&) { }

/*
 * --INFO--
 * Address:	8007DD64
 * Size:	000004
 */
void Creature::doLoad(RandomAccessStream&) { }

/*
 * --INFO--
 * Address:	8007DD68
 * Size:	00001C
 */
Vector3f Creature::getShadowPos()
{
	/*
	.loc_0x0:
	  lfs       f0, 0x94(r4)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x98(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x9C(r4)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DD84
 * Size:	00001C
 */
void Creature::setCentre(Vector3f&)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r5, 0x94(r3)
	  stw       r0, 0x98(r3)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x9C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DDA0
 * Size:	000008
 */
bool Creature::isOrganic() { return true; }

/*
 * --INFO--
 * Address:	8007DDA8
 * Size:	000008
 */
bool Creature::isBuried() { return false; }

/*
 * --INFO--
 * Address:	8007DDB8
 * Size:	000018
 */
bool Creature::isAlive()
{
	/*
	.loc_0x0:
	  lfs       f1, 0x58(r3)
	  lfs       f0, -0x7690(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm    r3,r0,2,31,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DDD0
 * Size:	000008
 */
bool Creature::isFixed() { return false; }

/*
 * --INFO--
 * Address:	8007DDD8
 * Size:	000008
 */
bool Creature::needFlick(Creature*) { return true; }

/*
 * --INFO--
 * Address:	8007DDE0
 * Size:	000008
 */
bool Creature::ignoreAtari(Creature*) { return false; }

/*
 * --INFO--
 * Address:	8007DDE8
 * Size:	000018
 */
bool Creature::isFree()
{
	/*
	.loc_0x0:
	  lwz       r0, 0xC8(r3)
	  rlwinm    r0,r0,0,19,19
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DE00
 * Size:	000004
 */
void Creature::sendMsg(Msg*) { }

/*
 * --INFO--
 * Address:	8007DE04
 * Size:	000004
 */
void Creature::jumpCallback() { }

/*
 * --INFO--
 * Address:	8007DE08
 * Size:	000004
 */
void Creature::offwallCallback(DynCollObject*) { }

/*
 * --INFO--
 * Address:	8007DE0C
 * Size:	000004
 */
void Creature::stickCallback(Creature*) { }

/*
 * --INFO--
 * Address:	8007DE10
 * Size:	000004
 */
void Creature::offstickCallback(Creature*) { }

/*
 * --INFO--
 * Address:	8007DE14
 * Size:	000004
 */
void Creature::stickToCallback(Creature*) { }

/*
 * --INFO--
 * Address:	8007DE18
 * Size:	000004
 */
void Creature::dump() { }

/*
 * --INFO--
 * Address:	8007DE1C
 * Size:	000004
 */
void Creature::startWaterEffect() { }

/*
 * --INFO--
 * Address:	8007DE20
 * Size:	000004
 */
void Creature::finishWaterEffect() { }

/*
 * --INFO--
 * Address:	8007DE24
 * Size:	000008
 */
bool Creature::isRopable() { return false; }

/*
 * --INFO--
 * Address:	8007DE2C
 * Size:	000008
 */
bool Creature::mayIstick() { return false; }

/*
 * --INFO--
 * Address:	8007DE34
 * Size:	000008
 */
int Creature::getFormationPri() { return 128; }

/*
 * --INFO--
 * Address:	8007DE3C
 * Size:	000004
 */
void Creature::refresh2d(Graphics&) { }

/*
 * --INFO--
 * Address:	8007DE40
 * Size:	000004
 */
void Creature::doAI() { }

/*
 * --INFO--
 * Address:	8007DE44
 * Size:	000004
 */
void Creature::doAnimation() { }

/*
 * --INFO--
 * Address:	8007DE48
 * Size:	000004
 */
void Creature::exitCourse() { }

/*
 * --INFO--
 * Address:	8007DE54
 * Size:	000004
 */
void AState<AICreature>::exec(AICreature*) { }

/*
 * --INFO--
 * Address:	8007DE58
 * Size:	000004
 */
void AState<AICreature>::resume(AICreature*) { }

/*
 * --INFO--
 * Address:	8007DE5C
 * Size:	000004
 */
void AState<AICreature>::restart(AICreature*) { }

/*
 * --INFO--
 * Address:	8007DE60
 * Size:	000030
 */
void AState<AICreature>::transit(AICreature*, int)
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
 * Address:	8007DE90
 * Size:	000004
 */
void StateMachine<AICreature>::init(AICreature*) { }

/*
 * --INFO--
 * Address:	8007DE94
 * Size:	000058
 */
void StateMachine<AICreature>::exec(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl

	.loc_0x44:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007DEEC
 * Size:	000068
 */
void StateMachine<AICreature>::procMsg(AICreature*, Msg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r5
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  lwz       r12, 0x0(r3)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x50:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
