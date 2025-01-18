#include "PikiAI.h"
#include "PikiState.h"
#include "BuildingItem.h"
#include "AIPerf.h"
#include "UtEffect.h"
#include "gameflow.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "aiBreakWall");
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
 * Address:	800AE13C
 * Size:	000070
 */
ActBreakWall::ActBreakWall(Piki* piki)
    : Action(piki, true)
{
	mName = "breakWall";
}

/*
 * --INFO--
 * Address:	800AE1AC
 * Size:	000154
 */
void ActBreakWall::init(Creature* creature)
{
	_31              = 0;
	mActor->_408     = 2;
	mActor->mEmotion = 0;

	if (creature->isSluice()) {
		mWall = static_cast<BuildingItem*>(creature);
	} else {
		mWall = nullptr;
	}

	mState               = STATE_GotoWall;
	_32                  = 0;
	mActor->mWantToStick = 0;
	_30                  = randFloat(4.0f);
	mActor->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
}

/*
 * --INFO--
 * Address:	800AE300
 * Size:	0000C4
 */
void ActBreakWall::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (piki->getState() != PIKISTATE_LookAt && msg->mEvent.mCollider == mWall && mState != STATE_BreakWall
	    && msg->mEvent.mColliderPart->getID() == 'gate' && !piki->mStickTarget) {
		_20 = piki->mPosition;
		initBreakWall();
	}
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
	  addi      r28, r3, 0
	  addi      r3, r29, 0
	  bl        0x1A228
	  cmpwi     r3, 0x1A
	  beq-      .loc_0xA4
	  lwz       r31, 0x4(r30)
	  lwz       r0, 0x18(r28)
	  cmplw     r31, r0
	  bne-      .loc_0xA4
	  lhz       r0, 0x1C(r28)
	  cmplwi    r0, 0x1
	  beq-      .loc_0xA4
	  addi      r3, r1, 0x14
	  lwz       r4, 0x8(r30)
	  bl        -0x264BC
	  lis       r4, 0x6761
	  addi      r3, r1, 0x14
	  addi      r4, r4, 0x7465
	  bl        -0x6A38C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA4
	  lwz       r0, 0x184(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0xA4
	  lwz       r4, 0x94(r29)
	  mr        r3, r28
	  lwz       r0, 0x98(r29)
	  stw       r4, 0x20(r28)
	  stw       r0, 0x24(r28)
	  lwz       r0, 0x9C(r29)
	  stw       r0, 0x28(r28)
	  bl        0x3E4

	.loc_0xA4:
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
 * Address:	800AE3C4
 * Size:	000190
 */
void ActBreakWall::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		_32 = 1;
		break;
	case KEY_Action1:
		_32 = 0;
		break;
	case KEY_Finished:
		_30 = randFloat(4.0f);
		startWorkMotion();
		_32 = 0;
		break;
	case KEY_PlayEffect:
		if (!mActor->isCreatureFlag(CF_IsAICullingActive) && (AIPerf::optLevel <= 0 || mActor->mOptUpdateContext.updatable())) {
			Vector3f vec = mActor->mEffectPos;
			EffectParm parm(vec);
			if (mWall->mObjType == OBJTYPE_SluiceSoft) {
				UtEffectMgr::cast(11, parm);
			} else if (mWall->mObjType == OBJTYPE_SluiceHard) {
				UtEffectMgr::cast(13, parm);
			} else {
				UtEffectMgr::cast(14, parm);
			}
		}
		break;
	}

	u32 badCompiler;
}

/*
 * --INFO--
 * Address:	800AE554
 * Size:	000148
 */
int ActBreakWall::exec()
{
	if (!mWall || !mWall->isAlive()) {
		return ACTOUT_Fail;
	}

	switch (mState) {
	case STATE_GotoWall:
		return gotoWall();

	case STATE_BreakWall:
		Vector3f sep = _20 - mActor->mPosition;
		if (sep.length() > 5.0f) {
			mState = STATE_GotoWall;
			break;
		}
		return breakWall();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AE6BC
 * Size:	0000C8
 */
int ActBreakWall::gotoWall()
{
	Vector3f direction = mWall->mPosition - mActor->mPosition;
	direction.normalise();
	mActor->setSpeed(1.0f, direction);
	u32 badCompiler;
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AE784
 * Size:	000090
 */
void ActBreakWall::initBreakWall()
{
	_30 = randFloat(4.0f);
	startWorkMotion();
	mState = STATE_BreakWall;
	_2C    = gameflow.mWorldClock.mMinutes;
}

/*
 * --INFO--
 * Address:	800AE814
 * Size:	0000F4
 */
void ActBreakWall::startWorkMotion()
{
	if (_30 == 0) {
		if (mActor->getCollidePlatformCreature() && mActor->getCollidePlatformNormal().y > 0.7f) {
			mActor->startMotion(PaniMotionInfo(PIKIANIM_Job2, this), PaniMotionInfo(PIKIANIM_Job2));
		} else {
			mActor->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  mr        r29, r3
	  lbz       r0, 0x30(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xD8
	  lwz       r3, 0xC(r29)
	  bl        -0x245F8
	  cmplwi    r3, 0
	  beq-      .loc_0x98
	  addi      r3, r1, 0x38
	  lwz       r4, 0xC(r29)
	  bl        -0x245F0
	  lfs       f1, 0x3C(r1)
	  lfs       f0, -0x7024(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x98
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x64
	  addi      r30, r30, 0x14

	.loc_0x64:
	  addi      r3, r1, 0x28
	  li        r4, 0x13
	  bl        0x706D8
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x30
	  li        r4, 0x13
	  bl        0x706F8
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1C134
	  b         .loc_0xD8

	.loc_0x98:
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0xA8
	  addi      r30, r30, 0x14

	.loc_0xA8:
	  addi      r3, r1, 0x18
	  li        r4, 0x30
	  bl        0x70694
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x20
	  li        r4, 0x30
	  bl        0x706B4
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1C0F0

	.loc_0xD8:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AE908
 * Size:	0002E4
 */
int ActBreakWall::breakWall()
{
	if (_30 != 0) {
		_30--;
		if (_30 == 0) {
			startWorkMotion();
		}
		return ACTOUT_Continue;
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stw       r31, 0x84(r1)
	  stw       r30, 0x80(r1)
	  mr        r30, r3
	  stw       r29, 0x7C(r1)
	  stw       r28, 0x78(r1)
	  lbz       r3, 0x30(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xFC
	  subi      r0, r3, 0x1
	  stb       r0, 0x30(r30)
	  lbz       r0, 0x30(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0xF4
	  bne-      .loc_0xF4
	  lwz       r3, 0xC(r30)
	  bl        -0x24708
	  cmplwi    r3, 0
	  beq-      .loc_0xB4
	  addi      r3, r1, 0x28
	  lwz       r4, 0xC(r30)
	  bl        -0x24700
	  lfs       f1, 0x2C(r1)
	  lfs       f0, -0x7024(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xB4
	  cmplwi    r30, 0
	  addi      r29, r30, 0
	  beq-      .loc_0x80
	  addi      r29, r29, 0x14

	.loc_0x80:
	  addi      r3, r1, 0x3C
	  li        r4, 0x13
	  bl        0x705C8
	  addi      r28, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x34
	  li        r4, 0x13
	  bl        0x705E8
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r28
	  bl        0x1C024
	  b         .loc_0xF4

	.loc_0xB4:
	  cmplwi    r30, 0
	  addi      r29, r30, 0
	  beq-      .loc_0xC4
	  addi      r29, r29, 0x14

	.loc_0xC4:
	  addi      r3, r1, 0x4C
	  li        r4, 0x30
	  bl        0x70584
	  addi      r28, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x44
	  li        r4, 0x30
	  bl        0x705A4
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r28
	  bl        0x1BFE0

	.loc_0xF4:
	  li        r3, 0
	  b         .loc_0x2C4

	.loc_0xFC:
	  lis       r3, 0x803A
	  lwz       r5, 0x2C(r30)
	  subi      r3, r3, 0x2848
	  addi      r31, r3, 0x300
	  lwz       r0, 0x300(r3)
	  lis       r4, 0x8889
	  lis       r3, 0x803A
	  sub       r5, r0, r5
	  addi      r5, r5, 0x3C
	  subi      r0, r4, 0x7777
	  mulhw     r0, r0, r5
	  add       r0, r0, r5
	  subi      r3, r3, 0x24E0
	  srawi     r0, r0, 0x5
	  lwz       r3, 0xA8(r3)
	  rlwinm    r4,r0,1,31,31
	  add       r4, r0, r4
	  lhz       r0, 0x26(r3)
	  mulli     r3, r4, 0x3C
	  cmplwi    r0, 0
	  sub       r3, r5, r3
	  bne-      .loc_0x158
	  li        r3, 0x1

	.loc_0x158:
	  cmpwi     r3, 0
	  ble-      .loc_0x288
	  lbz       r0, 0x32(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x288
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x7040(r2)
	  stw       r0, 0x74(r1)
	  lis       r28, 0x4330
	  lis       r4, 0x802B
	  lfs       f0, -0x7020(r2)
	  stw       r28, 0x70(r1)
	  lis       r3, 0x802B
	  lwz       r5, 0xC(r30)
	  lfd       f1, 0x70(r1)
	  subi      r0, r4, 0x3064
	  stw       r0, 0x54(r1)
	  subi      r0, r3, 0x31FC
	  fsubs     f1, f1, f2
	  stw       r5, 0x58(r1)
	  li        r29, 0
	  addi      r4, r1, 0x54
	  fdivs     f0, f1, f0
	  stw       r0, 0x54(r1)
	  stfs      f0, 0x5C(r1)
	  stw       r29, 0x60(r1)
	  stb       r29, 0x64(r1)
	  stb       r29, 0x32(r30)
	  lwz       r3, 0x18(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x280
	  lwz       r3, 0x18(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x208
	  li        r3, 0x2
	  b         .loc_0x2C4

	.loc_0x208:
	  lbz       r3, 0x31(r30)
	  addi      r0, r3, 0x1
	  stb       r0, 0x31(r30)
	  bl        0x169554
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7040(r2)
	  stw       r0, 0x74(r1)
	  lfs       f2, -0x7048(r2)
	  stw       r28, 0x70(r1)
	  lfs       f1, -0x704C(r2)
	  lfd       f3, 0x70(r1)
	  lfs       f0, -0x701C(r2)
	  fsubs     f3, f3, f4
	  lbz       r4, 0x31(r30)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x68(r1)
	  lwz       r3, 0x6C(r1)
	  addi      r0, r3, 0x3
	  cmpw      r4, r0
	  blt-      .loc_0x280
	  lwz       r4, 0xC(r30)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  lwz       r4, 0xC(r30)
	  stb       r29, 0x408(r4)
	  b         .loc_0x2C4

	.loc_0x280:
	  lwz       r0, 0x0(r31)
	  stw       r0, 0x2C(r30)

	.loc_0x288:
	  lwz       r4, 0xC(r30)
	  li        r3, 0
	  lfs       f0, -0x4E28(r13)
	  stfsu     f0, 0x70(r4)
	  lfs       f0, -0x4E24(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x4E20(r13)
	  stfs      f0, 0x8(r4)
	  lwz       r4, 0xC(r30)
	  lfs       f0, -0x4E1C(r13)
	  stfsu     f0, 0xA4(r4)
	  lfs       f0, -0x4E18(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x4E14(r13)
	  stfs      f0, 0x8(r4)

	.loc_0x2C4:
	  lwz       r0, 0x8C(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  lwz       r29, 0x7C(r1)
	  lwz       r28, 0x78(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AEC08
 * Size:	000004
 */
void ActBreakWall::cleanup()
{
}
