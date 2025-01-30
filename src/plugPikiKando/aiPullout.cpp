#include "PikiAI.h"
#include "PikiState.h"
#include "Navi.h"
#include "NaviState.h"
#include "Interactions.h"
#include "PikiMgr.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("aiPullout")

/*
 * --INFO--
 * Address:	800BD670
 * Size:	000100
 */
ActPullout::ActPullout(Piki* piki)
    : AndAction(piki)
{
	setChildren(CHILD_COUNT, new ActGoto(piki), nullptr, new ActAdjust(piki), nullptr, new ActPulloutCreature(piki), nullptr);
	mTarget.clear();
}

/*
 * --INFO--
 * Address:	800BD770
 * Size:	000250
 */
void ActPullout::init(Creature* target)
{
	if (!target) {
		Iterator iter(pikiMgr);
		Creature* pikiList[100];
		f32 minDist = 300.0f;
		int count   = 0;
		CI_LOOP(iter)
		{
			Piki* piki = static_cast<Piki*>(*iter);
			f32 dist   = qdist2(piki, mPiki);
			if (piki != mPiki && piki->isBuried() && dist < minDist && count < 100) {
				pikiList[count++] = piki;
			}
		}
		if (count > 0) {
			int randIdx = System::getRand(1.0f) * f32(count);
			if (randIdx >= count) {
				randIdx = count - 1;
			}
			target = pikiList[randIdx];
		}
	}
	if (target) {
		mTarget.set(target);
		AndAction::init(target);
	} else {
		mTarget.reset();
	}
}

/*
 * --INFO--
 * Address:	800BD9C0
 * Size:	0000DC
 */
int ActPullout::exec()
{
	if (mTarget.isNull()) {
		return ACTOUT_Success;
	}

	if (mPiki->_518) {
		if (mPiki->mNavi->mStateMachine->getCurrID(mPiki->mNavi) != NAVISTATE_Nuku) {
			return ACTOUT_Fail;
		}

		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->turnTo(mPiki->mNavi->mPosition);

	} else {
		int res = AndAction::exec();
		if (res) {
			init(nullptr);
			return ACTOUT_Continue;
		}
		return res;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800BDA9C
 * Size:	000050
 */
void ActPullout::cleanup()
{
	Action::cleanup();
	mPiki->_518 = 1;
	mTarget.reset();
}

/*
 * --INFO--
 * Address:	800BDAEC
 * Size:	000074
 */
void ActPulloutCreature::cleanup()
{
	if (!mPulloutSuccess) {
		Piki* piki = static_cast<Piki*>(mTarget.getPtr());
		if (piki) {
			piki->mFSM->transit(piki, PIKISTATE_Bury);
		}
	}

	mTarget.reset();
}

/*
 * --INFO--
 * Address:	800BDB60
 * Size:	000078
 */
void ActPulloutCreature::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action1:
		mPulloutSuccess = 1;
		Piki* piki      = static_cast<Piki*>(mTarget.getPtr());
		if (piki) {
			piki->changeShape(piki->mFormationPriority);
		}
		break;
	case KEY_Finished:
		mState = STATE_Unk2;
		break;
	}
}

/*
 * --INFO--
 * Address:	800BDBD8
 * Size:	00005C
 */
ActPulloutCreature::ActPulloutCreature(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800BDC34
 * Size:	000094
 */
void ActPulloutCreature::init(Creature* target)
{
	mState = STATE_Unk0;
	mTarget.set(target);
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mPulloutSuccess = 0;
}

/*
 * --INFO--
 * Address:	800BDCC8
 * Size:	000240
 */
int ActPulloutCreature::exec()
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	switch (mState) {
	case STATE_Unk2:
		return ACTOUT_Success;

	case STATE_Unk0:
		Vector3f dir = mTarget.getPtr()->mPosition - mPiki->mPosition;
		f32 angleSep = atan2f(dir.x, dir.z);
		mPiki->mFaceDirection += 0.4f * angDist(angleSep, mPiki->mFaceDirection);
		mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection);
		if (quickABS(angDist(angleSep, mPiki->mFaceDirection)) < 0.1f) {
			mState = STATE_Unk1;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Nuku, this), PaniMotionInfo(PIKIANIM_Nuku));
			mTarget.getPtr()->stimulate(InteractPullout(mPiki));
			mPulloutTimer = 0.0f;
		}
		break;
	case STATE_Unk1:
		Piki* target = static_cast<Piki*>(mTarget.getPtr());
		mPulloutTimer += gsys->getFrameTime();

		if (mPulloutTimer >= f32(target->mFormationPriority)) {
			mPiki->mPikiAnimMgr.finishMotion(this);
			target->mPikiAnimMgr.finishMotion(target);
		}

		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		break;
	}

	return ACTOUT_Continue;
}
