#include "PikiAI.h"
#include "sysNew.h"
#include "Dolphin/os.h"
#include "MemStat.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "aiAction");
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

namespace Reaction {
char* info[9] = {
	"-", "WATCH", "ESCAPE", "CHASE", "GOTO", "PICK", "PUT", "KICK", "FORMATION",
};
}

/*
 * --INFO--
 * Address:	800C3AE4
 * Size:	000240
 */
void Action::procMsg(Msg* msg)
{
	u32 badCompiler;
	if (mActor->isCreatureFlag(CF_IsAiDisabled)) {
		return;
	}

	Receiver::procMsg(mActor, msg);

	if (mChildActionIdx != -1 && mChildActionIdx < mChildCount) {
		if (mChildActions[mChildActionIdx].mAction) {
			mChildActions[mChildActionIdx].mAction->procMsg(msg);
		}
	}
}

/*
 * --INFO--
 * Address:	800C3D24
 * Size:	0000AC
 */
void Action::Child::initialise(Creature* creature)
{
	if (mAction) {
		mAction->mActor->mEmotion = 10;
		mAction->mActor->_408     = 2;
	}

	if (mAction) {
		mAction->init(creature);
	}

	if (mInitialiser) {
		mInitialiser->initialise(mAction);

	} else if (mAction) {
		mAction->defaultInitialiser();
	}
}

/*
 * --INFO--
 * Address:	800C3DD0
 * Size:	000038
 */
Action::Action(Piki* actor, bool p2)
{
	mActor          = actor;
	mChildActions   = nullptr;
	mChildActionIdx = mChildCount = 0;
	mName                         = "no name";
}

/*
 * --INFO--
 * Address:	800C3E08
 * Size:	000078
 */
Action::~Action()
{
	if (mChildActions) {
		delete[] mChildActions;
	}
	mChildActions = nullptr;
}

/*
 * --INFO--
 * Address:	800C3F00
 * Size:	00000C
 */
void Action::init(Creature*)
{
	mChildActionIdx = 0;
}

/*
 * --INFO--
 * Address:	800C3F0C
 * Size:	000008
 */
int Action::exec()
{
	return ACTOUT_Success;
}

/*
 * --INFO--
 * Address:	800C3F14
 * Size:	0000E0
 */
void AndAction::init(Creature* creature)
{
	mChildActionIdx = 0;
	mChildActions[mChildActionIdx].initialise(creature);
	mOtherCreature = creature;
}

/*
 * --INFO--
 * Address:	800C3FF4
 * Size:	00014C
 */
int AndAction::exec()
{
	Child* child = &mChildActions[mChildActionIdx];
	switch (child->mAction->exec()) {
	case ACTOUT_Success:
		mChildActions[mChildActionIdx].mAction->cleanup();
		mChildActionIdx++;
		if (mChildActionIdx >= mChildCount) {
			return ACTOUT_Success;
		}
		Child* child = &mChildActions[mChildActionIdx];
		child->initialise(mOtherCreature);
		break;

	case ACTOUT_Fail:
		return ACTOUT_Fail;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C4140
 * Size:	0000E0
 */
void OrAction::init(Creature* creature)
{
	mChildActionIdx = 0;
	mChildActions[mChildActionIdx].initialise(creature);
	mOtherCreature = creature;
}

/*
 * --INFO--
 * Address:	800C4220
 * Size:	000150
 */
int OrAction::exec()
{
	Child* child = &mChildActions[mChildActionIdx];
	switch (child->mAction->exec()) {
	case ACTOUT_Success:
		return ACTOUT_Success;

	case ACTOUT_Fail:
		mChildActions[mChildActionIdx].mAction->cleanup();
		mChildActionIdx++;
		if (mChildActionIdx >= mChildCount) {
			return ACTOUT_Fail;
		}
		Child* child = &mChildActions[mChildActionIdx];
		child->initialise(mOtherCreature);
		return ACTOUT_Fail;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C4370
 * Size:	000124
 */
void Action::setChildren(int count, ...)
{
	mChildActions = new Child[count];
	mChildCount   = count;

	va_list list;
	va_start(list, count);
	for (int i = 0; i < count; i++) {
		Action* action           = va_arg(list, Action*);
		mChildActions[i].mAction = action;

		Initialiser* init             = va_arg(list, Initialiser*);
		mChildActions[i].mInitialiser = init;
	}
	va_end(list);
}

/*
 * --INFO--
 * Address:	800C44A4
 * Size:	000070
 */
void Action::cleanup()
{
	for (int i = 0; i < mChildCount; i++) {
		mChildActions[i].mAction->cleanup();
	}
}

/*
 * --INFO--
 * Address:	800C4514
 * Size:	0000DC
 */
void TopAction::MotionListener::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Finished:
		mAction->_1A = 0;
		mAction->mChildActions[mAction->mChildActionIdx].initialise(mAction->_20);
		break;
	}
}

/*
 * --INFO--
 * Address:	800C45F0
 * Size:	00064C
 */
TopAction::TopAction(Piki* piki)
    : Action(piki, false)
{
	_18 = 0;

	memStat->start("topaction");

	mListener = new MotionListener(this);
	_20       = 0;
	_24       = -1;
	_2C       = 1.0f;
	_28       = 0;
	_19       = 0;
	_1A       = 0;
	mName     = "top action";

	setChildren(PikiAction::COUNT, new ActRandomBoid(piki), nullptr, new ActWatch(piki), nullptr, new ActEscape(piki), nullptr,
	            new ActChase(piki), nullptr, new ActGoto(piki), nullptr, new ActPickCreature(piki), nullptr, new ActPutItem(piki), nullptr,
	            new ActFormation(piki), nullptr, new ActAttack(piki), nullptr, new ActShoot(piki), nullptr, new ActGuard(piki), nullptr,
	            new ActPullout(piki), nullptr, new ActPickItem(piki), nullptr, new ActDecoy(piki), nullptr, new ActCrowd(piki), nullptr,
	            new ActFree(piki), nullptr, new ActRope(piki), nullptr, new ActEnter(piki), nullptr, new ActExit(piki), nullptr,
	            new ActBreakWall(piki), nullptr, new ActMine(piki), nullptr, new ActTransport(piki), nullptr, new ActKinoko(piki), nullptr,
	            new ActBridge(piki), nullptr, new ActPush(piki), nullptr, new ActPutBomb(piki), nullptr, new ActRescue(piki), nullptr,
	            new ActWeed(piki), nullptr, new ActStone(piki), nullptr, new ActBoMake(piki), nullptr, new ActBou(piki), nullptr);

	_1C = -1;

	memStat->end("topAction");

	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802C
	  stw       r0, 0x4(r1)
	  lis       r6, 0x802B
	  stwu      r1, -0x178(r1)
	  stmw      r14, 0x130(r1)
	  addi      r31, r4, 0
	  li        r29, 0
	  stw       r3, 0xE8(r1)
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7E08
	  lwz       r30, 0xE8(r1)
	  lis       r3, 0x802B
	  addi      r4, r3, 0x7FD4
	  stw       r0, 0x0(r30)
	  subi      r0, r5, 0x7E6C
	  subi      r5, r13, 0x4380
	  stw       r0, 0x0(r30)
	  addi      r0, r6, 0x7EB0
	  addi      r3, r30, 0x30
	  stw       r31, 0xC(r30)
	  stw       r29, 0x4(r30)
	  sth       r29, 0xA(r30)
	  sth       r29, 0x8(r30)
	  stw       r5, 0x10(r30)
	  stw       r0, 0x128(r1)
	  stw       r4, 0x0(r30)
	  bl        0xEE0
	  lwz       r3, 0x128(r1)
	  stb       r29, 0x18(r30)
	  addi      r4, r3, 0xA4
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x3DF38
	  li        r3, 0x8
	  bl        -0x7D674
	  cmplwi    r3, 0
	  beq-      .loc_0xB0
	  lis       r4, 0x802B
	  subi      r0, r4, 0x246C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x7F80
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)

	.loc_0xB0:
	  lwz       r6, 0xE8(r1)
	  li        r5, 0
	  li        r4, -0x1
	  stw       r3, 0x14(r6)
	  lwz       r3, 0x128(r1)
	  stw       r5, 0x20(r6)
	  addi      r0, r3, 0xB0
	  stw       r4, 0x24(r6)
	  li        r3, 0x28
	  lfs       f0, -0x6A60(r2)
	  stfs      f0, 0x2C(r6)
	  stw       r5, 0x28(r6)
	  stb       r5, 0x19(r6)
	  stb       r5, 0x1A(r6)
	  stw       r0, 0x10(r6)
	  bl        -0x7D6D8
	  stw       r3, 0x124(r1)
	  lwz       r0, 0x124(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x10C
	  lwz       r3, 0x124(r1)
	  mr        r4, r31
	  bl        -0x39F0

	.loc_0x10C:
	  li        r3, 0x2C
	  bl        -0x7D6FC
	  stw       r3, 0x120(r1)
	  lwz       r0, 0x120(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x130
	  lwz       r3, 0x120(r1)
	  mr        r4, r31
	  bl        -0x1AC4

	.loc_0x130:
	  li        r3, 0x30
	  bl        -0x7D720
	  stw       r3, 0x11C(r1)
	  lwz       r0, 0x11C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x154
	  lwz       r3, 0x11C(r1)
	  mr        r4, r31
	  bl        -0xBF18

	.loc_0x154:
	  li        r3, 0x1C
	  bl        -0x7D744
	  stw       r3, 0x118(r1)
	  lwz       r0, 0x118(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x178
	  lwz       r3, 0x118(r1)
	  mr        r4, r31
	  bl        -0xF0DC

	.loc_0x178:
	  li        r3, 0x24
	  bl        -0x7D768
	  stw       r3, 0x114(r1)
	  lwz       r0, 0x114(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x19C
	  lwz       r3, 0x114(r1)
	  mr        r4, r31
	  bl        -0x9820

	.loc_0x19C:
	  li        r3, 0x1C
	  bl        -0x7D78C
	  stw       r3, 0x110(r1)
	  lwz       r0, 0x110(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C0
	  lwz       r3, 0x110(r1)
	  mr        r4, r31
	  bl        -0x7448

	.loc_0x1C0:
	  li        r3, 0x24
	  bl        -0x7D7B0
	  stw       r3, 0x10C(r1)
	  lwz       r0, 0x10C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x1E4
	  lwz       r3, 0x10C(r1)
	  mr        r4, r31
	  bl        -0x4884

	.loc_0x1E4:
	  li        r3, 0x34
	  bl        -0x7D7D4
	  stw       r3, 0x108(r1)
	  lwz       r0, 0x108(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x208
	  lwz       r3, 0x108(r1)
	  mr        r4, r31
	  bl        -0xABF0

	.loc_0x208:
	  li        r3, 0x2C
	  bl        -0x7D7F8
	  stw       r3, 0x104(r1)
	  lwz       r0, 0x104(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x22C
	  lwz       r3, 0x104(r1)
	  mr        r4, r31
	  bl        -0x1C530

	.loc_0x22C:
	  li        r3, 0x28
	  bl        -0x7D81C
	  stw       r3, 0x100(r1)
	  lwz       r0, 0x100(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x250
	  lwz       r3, 0x100(r1)
	  mr        r4, r31
	  bl        -0x26D0

	.loc_0x250:
	  li        r3, 0x4C
	  bl        -0x7D840
	  stw       r3, 0xFC(r1)
	  lwz       r0, 0xFC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x274
	  lwz       r3, 0xFC(r1)
	  mr        r4, r31
	  bl        -0x932C

	.loc_0x274:
	  li        r3, 0x1C
	  bl        -0x7D864
	  stw       r3, 0xF8(r1)
	  lwz       r0, 0xF8(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x298
	  lwz       r3, 0xF8(r1)
	  mr        r4, r31
	  bl        -0x7214

	.loc_0x298:
	  li        r3, 0x1C
	  bl        -0x7D888
	  stw       r3, 0xF4(r1)
	  lwz       r0, 0xF4(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x2BC
	  lwz       r3, 0xF4(r1)
	  mr        r4, r31
	  bl        -0x7DAC

	.loc_0x2BC:
	  li        r3, 0x20
	  bl        -0x7D8AC
	  stw       r3, 0xF0(r1)
	  lwz       r0, 0xF0(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x2E0
	  lwz       r3, 0xF0(r1)
	  mr        r4, r31
	  bl        -0xD120

	.loc_0x2E0:
	  li        r3, 0x88
	  bl        -0x7D8D0
	  mr.       r14, r3
	  beq-      .loc_0x300
	  addi      r3, r14, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0xEE40

	.loc_0x300:
	  li        r3, 0x50
	  bl        -0x7D8F0
	  mr.       r15, r3
	  beq-      .loc_0x320
	  addi      r3, r15, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0xA30C

	.loc_0x320:
	  li        r3, 0x24
	  bl        -0x7D910
	  mr.       r16, r3
	  beq-      .loc_0x33C
	  addi      r3, r16, 0
	  addi      r4, r31, 0
	  bl        -0x2B04

	.loc_0x33C:
	  li        r3, 0x30
	  bl        -0x7D92C
	  mr.       r17, r3
	  beq-      .loc_0x358
	  addi      r3, r17, 0
	  addi      r4, r31, 0
	  bl        -0xC9E0

	.loc_0x358:
	  li        r3, 0x24
	  bl        -0x7D948
	  mr.       r18, r3
	  beq-      .loc_0x374
	  addi      r3, r18, 0
	  addi      r4, r31, 0
	  bl        -0xBBF8

	.loc_0x374:
	  li        r3, 0x34
	  bl        -0x7D964
	  mr.       r19, r3
	  beq-      .loc_0x390
	  addi      r3, r19, 0
	  addi      r4, r31, 0
	  bl        -0x16840

	.loc_0x390:
	  li        r3, 0x30
	  bl        -0x7D980
	  mr.       r20, r3
	  beq-      .loc_0x3B0
	  addi      r3, r20, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0xB6DC

	.loc_0x3B0:
	  li        r3, 0xC0
	  bl        -0x7D9A0
	  mr.       r21, r3
	  beq-      .loc_0x3D0
	  addi      r3, r21, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0x157CC

	.loc_0x3D0:
	  li        r3, 0x38
	  bl        -0x7D9C0
	  mr.       r22, r3
	  beq-      .loc_0x3F0
	  addi      r3, r22, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0x1046C

	.loc_0x3F0:
	  li        r3, 0x58
	  bl        -0x7D9E0
	  mr.       r23, r3
	  beq-      .loc_0x410
	  addi      r3, r23, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0x17B5C

	.loc_0x410:
	  li        r3, 0x50
	  bl        -0x7DA00
	  mr.       r24, r3
	  beq-      .loc_0x430
	  addi      r3, r24, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0x6A2C

	.loc_0x430:
	  li        r3, 0x30
	  bl        -0x7DA20
	  mr.       r25, r3
	  beq-      .loc_0x450
	  addi      r3, r25, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0x5FA8

	.loc_0x450:
	  li        r3, 0x3C
	  bl        -0x7DA40
	  mr.       r26, r3
	  beq-      .loc_0x470
	  addi      r3, r26, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0x3774

	.loc_0x470:
	  li        r3, 0x2C
	  bl        -0x7DA60
	  mr.       r27, r3
	  beq-      .loc_0x48C
	  addi      r3, r27, 0
	  addi      r4, r31, 0
	  bl        -0x19D0

	.loc_0x48C:
	  li        r3, 0x2C
	  bl        -0x7DA7C
	  mr.       r28, r3
	  beq-      .loc_0x4A8
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        -0x1DD00

	.loc_0x4A8:
	  li        r3, 0x24
	  bl        -0x7DA98
	  mr.       r30, r3
	  beq-      .loc_0x4C4
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x187A4

	.loc_0x4C4:
	  li        r3, 0x34
	  bl        -0x7DAB4
	  mr.       r29, r3
	  beq-      .loc_0x4E0
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  bl        -0x18330

	.loc_0x4E0:
	  lwz       r0, 0x118(r1)
	  crclr     6, 0x6
	  lwz       r3, 0x114(r1)
	  li        r4, 0x1F
	  stw       r0, 0x8(r1)
	  li        r0, 0
	  lwz       r5, 0x124(r1)
	  stw       r0, 0xC(r1)
	  li        r6, 0
	  lwz       r7, 0x120(r1)
	  li        r8, 0
	  stw       r3, 0x10(r1)
	  lwz       r3, 0x110(r1)
	  li        r10, 0
	  stw       r0, 0x14(r1)
	  lwz       r9, 0x11C(r1)
	  stw       r3, 0x18(r1)
	  lwz       r3, 0x10C(r1)
	  stw       r0, 0x1C(r1)
	  stw       r3, 0x20(r1)
	  lwz       r3, 0x108(r1)
	  stw       r0, 0x24(r1)
	  stw       r3, 0x28(r1)
	  lwz       r3, 0x104(r1)
	  stw       r0, 0x2C(r1)
	  stw       r3, 0x30(r1)
	  lwz       r3, 0x100(r1)
	  stw       r0, 0x34(r1)
	  stw       r3, 0x38(r1)
	  lwz       r3, 0xFC(r1)
	  stw       r0, 0x3C(r1)
	  stw       r3, 0x40(r1)
	  lwz       r3, 0xF8(r1)
	  stw       r0, 0x44(r1)
	  stw       r3, 0x48(r1)
	  lwz       r3, 0xF4(r1)
	  stw       r0, 0x4C(r1)
	  stw       r3, 0x50(r1)
	  lwz       r3, 0xF0(r1)
	  stw       r0, 0x54(r1)
	  stw       r3, 0x58(r1)
	  stw       r0, 0x5C(r1)
	  stw       r14, 0x60(r1)
	  stw       r0, 0x64(r1)
	  stw       r15, 0x68(r1)
	  stw       r0, 0x6C(r1)
	  stw       r16, 0x70(r1)
	  stw       r0, 0x74(r1)
	  stw       r17, 0x78(r1)
	  stw       r0, 0x7C(r1)
	  stw       r18, 0x80(r1)
	  stw       r0, 0x84(r1)
	  stw       r19, 0x88(r1)
	  stw       r0, 0x8C(r1)
	  stw       r20, 0x90(r1)
	  stw       r0, 0x94(r1)
	  stw       r21, 0x98(r1)
	  stw       r0, 0x9C(r1)
	  stw       r22, 0xA0(r1)
	  stw       r0, 0xA4(r1)
	  stw       r23, 0xA8(r1)
	  stw       r0, 0xAC(r1)
	  stw       r24, 0xB0(r1)
	  stw       r0, 0xB4(r1)
	  stw       r25, 0xB8(r1)
	  stw       r0, 0xBC(r1)
	  stw       r26, 0xC0(r1)
	  stw       r0, 0xC4(r1)
	  stw       r27, 0xC8(r1)
	  stw       r0, 0xCC(r1)
	  stw       r28, 0xD0(r1)
	  stw       r0, 0xD4(r1)
	  stw       r30, 0xD8(r1)
	  stw       r0, 0xDC(r1)
	  stw       r29, 0xE0(r1)
	  stw       r0, 0xE4(r1)
	  lwz       r3, 0xE8(r1)
	  bl        -0x894
	  lwz       r29, 0xE8(r1)
	  li        r0, -0x1
	  lwz       r3, 0x128(r1)
	  stw       r0, 0x1C(r29)
	  addi      r4, r3, 0xA4
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x3E3D8
	  mr        r3, r29
	  lmw       r14, 0x130(r1)
	  lwz       r0, 0x17C(r1)
	  addi      r1, r1, 0x178
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C4C3C
 * Size:	000088
 */
TopAction::~TopAction()
{
}

/*
 * --INFO--
 * Address:	800C4CC4
 * Size:	0000E8
 */
void TopAction::init(Creature* creature)
{
	mChildActionIdx = 0;
	mChildActions[mChildActionIdx].initialise(creature);
	_20 = nullptr;
	_2C = 1.0f;
	_28 = 0;
	_1A = 0;
	_19 = 0;
}

/*
 * --INFO--
 * Address:	800C4DAC
 * Size:	000598
 */
int TopAction::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  mr        r30, r3
	  stw       r29, 0x4C(r1)
	  stw       r28, 0x48(r1)
	  lbz       r0, 0x19(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x38
	  li        r3, 0
	  b         .loc_0x574

	.loc_0x38:
	  lha       r0, 0x8(r30)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x108
	  lwz       r3, 0xC(r30)
	  bl        0x3760
	  cmpwi     r3, 0xE
	  beq-      .loc_0x100
	  lwz       r3, 0xC(r30)
	  li        r4, 0
	  li        r0, 0xF
	  sth       r4, 0x4FC(r3)
	  sth       r0, 0x8(r30)
	  lha       r0, 0x8(r30)
	  lwz       r3, 0x4(r30)
	  rlwinm    r0,r0,3,0,28
	  add       r28, r3, r0
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0xA0
	  lwz       r3, 0xC(r3)
	  li        r4, 0xA
	  li        r0, 0x2
	  stb       r4, 0x400(r3)
	  lwz       r3, 0x0(r28)
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)

	.loc_0xA0:
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0xC0
	  lwz       r12, 0x0(r3)
	  li        r4, 0
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0xC0:
	  lwz       r3, 0x4(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0xE4
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x0(r28)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x100

	.loc_0xE4:
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x100
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl

	.loc_0x100:
	  li        r3, 0
	  b         .loc_0x574

	.loc_0x108:
	  cmpwi     r0, 0x7
	  bne-      .loc_0x288
	  lwz       r3, 0xC(r30)
	  bl        0x74AC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x288
	  lha       r0, 0x8(r30)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x134
	  li        r3, 0
	  b         .loc_0x140

	.loc_0x134:
	  lwz       r3, 0x4(r30)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0

	.loc_0x140:
	  lbz       r0, 0x18(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x288
	  lwz       r29, 0x30AC(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x6A5C(r2)
	  mr        r28, r3
	  b         .loc_0x22C

	.loc_0x170:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x198
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3
	  b         .loc_0x1B4

	.loc_0x198:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x1B4:
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x210
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x210
	  lwz       r0, 0x2A8(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x210
	  mr        r3, r31
	  lwz       r4, 0xC(r30)
	  bl        -0x38120
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x210
	  lwz       r3, 0xC(r30)
	  li        r4, 0x5
	  lwz       r5, 0x504(r3)
	  bl        0x8218
	  b         .loc_0x288

	.loc_0x210:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x22C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x254
	  li        r0, 0x1
	  b         .loc_0x280

	.loc_0x254:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x27C
	  li        r0, 0x1
	  b         .loc_0x280

	.loc_0x27C:
	  li        r0, 0

	.loc_0x280:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x170

	.loc_0x288:
	  lha       r0, 0x8(r30)
	  lwz       r3, 0x4(r30)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r3, 0x3
	  bge-      .loc_0x570
	  cmpwi     r3, 0x1
	  bge-      .loc_0x2C0
	  b         .loc_0x570

	.loc_0x2C0:
	  lha       r0, 0x8(r30)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x2D4
	  li        r3, 0x1
	  b         .loc_0x574

	.loc_0x2D4:
	  lwz       r3, 0x4(r30)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stw       r0, 0x20(r30)
	  li        r0, -0x1
	  sth       r0, 0x8(r30)
	  lfs       f0, -0x6A60(r2)
	  stfs      f0, 0x2C(r30)
	  lwz       r4, 0xC(r30)
	  lhz       r0, 0x4FC(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x538
	  lbz       r0, 0x408(r4)
	  li        r28, 0
	  cmpwi     r0, 0x1
	  beq-      .loc_0x33C
	  bge-      .loc_0x368
	  cmpwi     r0, 0
	  bge-      .loc_0x364
	  b         .loc_0x368
	  b         .loc_0x368

	.loc_0x33C:
	  lwz       r3, 0x504(r4)
	  bl        -0x38270
	  lwz       r3, 0xC(r30)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x478(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x368
	  li        r28, 0x1
	  b         .loc_0x368

	.loc_0x364:
	  li        r28, 0x1

	.loc_0x368:
	  rlwinm.   r0,r28,0,24,31
	  beq-      .loc_0x3F4
	  lwz       r3, 0xC(r30)
	  li        r4, 0x1
	  li        r5, 0
	  lbz       r28, 0x400(r3)
	  bl        0x80A0
	  lwz       r3, 0xC(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3C0
	  lwz       r4, 0xC(r30)
	  li        r5, 0x1D
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3EC

	.loc_0x3C0:
	  cmpwi     r28, 0xA
	  beq-      .loc_0x3EC
	  lwz       r3, 0xC(r30)
	  li        r5, 0x1F
	  stb       r28, 0x400(r3)
	  lwz       r4, 0xC(r30)
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x3EC:
	  li        r3, 0
	  b         .loc_0x574

	.loc_0x3F4:
	  lwz       r3, 0xC(r30)
	  lbz       r0, 0x408(r3)
	  cmplwi    r0, 0x3
	  bne-      .loc_0x420
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x420
	  lwz       r5, 0x504(r3)
	  li        r4, 0x12
	  bl        0x8008
	  b         .loc_0x570

	.loc_0x420:
	  lbz       r31, 0x400(r3)
	  li        r4, 0
	  li        r0, 0xF
	  sth       r4, 0x4FC(r3)
	  sth       r0, 0x8(r30)
	  lha       r0, 0x8(r30)
	  lwz       r3, 0x4(r30)
	  rlwinm    r0,r0,3,0,28
	  add       r28, r3, r0
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x46C
	  lwz       r3, 0xC(r3)
	  li        r4, 0xA
	  li        r0, 0x2
	  stb       r4, 0x400(r3)
	  lwz       r3, 0x0(r28)
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)

	.loc_0x46C:
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x48C
	  lwz       r12, 0x0(r3)
	  li        r4, 0
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x48C:
	  lwz       r3, 0x4(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x4B0
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x0(r28)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4CC

	.loc_0x4B0:
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x4CC
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl

	.loc_0x4CC:
	  lwz       r3, 0xC(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x508
	  lwz       r4, 0xC(r30)
	  li        r5, 0x1D
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x570

	.loc_0x508:
	  cmpwi     r31, 0xA
	  beq-      .loc_0x570
	  lwz       r3, 0xC(r30)
	  li        r5, 0x1F
	  stb       r31, 0x400(r3)
	  lwz       r4, 0xC(r30)
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x570

	.loc_0x538:
	  lbz       r28, 0x400(r4)
	  mr        r3, r4
	  bl        0x2DD0
	  cmpwi     r28, 0xA
	  beq-      .loc_0x570
	  lwz       r3, 0xC(r30)
	  li        r5, 0x1F
	  stb       r28, 0x400(r3)
	  lwz       r4, 0xC(r30)
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x570:
	  li        r3, 0

	.loc_0x574:
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  lwz       r28, 0x48(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C5344
 * Size:	000084
 */
void TopAction::abandon(zen::particleGenerator* particle)
{
	if (mChildActionIdx != -1) {
		mChildActions[mChildActionIdx].mAction->cleanup();
		if (mActor->isKinoko()) {
			(mChildActionIdx < -1);
		}
	}

	mChildActionIdx = -1;
	_28             = 0;
	_24             = 0;
	_20             = nullptr;
	_19             = 0;
}

/*
 * --INFO--
 * Address:	800C53C8
 * Size:	00004C
 */
bool TopAction::resumable()
{
	if (mChildActionIdx != -1) {
		return mChildActions[mChildActionIdx].mAction->resumable();
	}
	return false;
}

/*
 * --INFO--
 * Address:	800C5414
 * Size:	00004C
 */
void TopAction::resume()
{
	_19 = 1;
	if (mChildActionIdx != -1) {
		mChildActions[mChildActionIdx].mAction->resume();
	}
}

/*
 * --INFO--
 * Address:	800C5460
 * Size:	00004C
 */
void TopAction::restart()
{
	_19 = 0;
	if (mChildActionIdx != -1) {
		mChildActions[mChildActionIdx].mAction->restart();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void TopAction::knowledgeCheck()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C54AC
 * Size:	000090
 */
TopAction::ObjBore::ObjBore()
{
	_0C  = 0;
	mCnt = 5;
	_00  = new u32[mCnt];
	_04  = new u32[mCnt];
	_08  = new u8[mCnt];

	for (int i = 0; i < mCnt; i++) {
		_08[i] = 0;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void TopAction::ObjBore::getIndex(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000134
 */
void TopAction::ObjBore::addBoredom(int, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000124
 */
void TopAction::ObjBore::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C553C
 * Size:	00008C
 */
TopAction::Boredom::Boredom()
{
	_08        = 0;
	mObjectCnt = 30;
	mObjects   = new ObjBore[mObjectCnt];
	_04        = new u32[mObjectCnt];
	_10        = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void TopAction::Boredom::getIndex(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void TopAction::Boredom::getBoredom(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void TopAction::Boredom::addBoredom(int, int, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000134
 */
void TopAction::Boredom::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000180
 */
void TopAction::Boredom::draw2d(Graphics&, int)
{
	// UNUSED FUNCTION
}
