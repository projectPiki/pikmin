#include "DebugLog.h"
#include "GameStat.h"
#include "Navi.h"
#include "PikiAI.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(23)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("free")

static int motions[] = { PIKIANIM_Rinbow, PIKIANIM_Akubi, PIKIANIM_Sagasu2, PIKIANIM_Chatting };
int numMotions       = 4;

/*
 * --INFO--
 * Address:	800BA600
 * Size:	0000CC
 */
ActFree::ActFree(Piki* piki)
    : Action(piki, true)
{
	setName("free");
	mSelectAction = new ActFreeSelect(piki);
}

/*
 * --INFO--
 * Address:	800BA6CC
 * Size:	0000D0
 */
void ActFree::initBoid(Vector3f& targetPosition, f32 radius)
{
	mIsBoidActive   = true;
	mTargetPosition = targetPosition;
	mArrivalRadius  = radius;
	if (mPiki->isHolding()) {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Pick), PaniMotionInfo(PIKIANIM_Pick));
		mPiki->enableMotionBlend();
	} else {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
	}

	mBoidTimer = 3.0f;
}

/*
 * --INFO--
 * Address:	800BA79C
 * Size:	0001C4
 */
void ActFree::exeBoid()
{
	Vector3f dirToTarget = mTargetPosition - mPiki->mPosition;
	f32 distanceToTarget = dirToTarget.normalise();
	mBoidTimer -= gsys->getFrameTime();

	if (distanceToTarget < 0.9f * mArrivalRadius || mBoidTimer <= 0.0f) {
		mPiki->enableFixPos();
		mFixedPositionTimer = 3.0f;
		mIsBoidActive       = false;
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		if (mPiki->isHolding() && mPiki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() != PIKIANIM_Pick) {
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Pick, this), PaniMotionInfo(PIKIANIM_Pick));
			mPiki->mPikiAnimMgr.getUpperAnimator().mAnimationCounter = 18.0f;
			mPiki->mPikiAnimMgr.getLowerAnimator().mAnimationCounter = 18.0f;
			mPiki->enableMotionBlend();
		}
	} else {
		mPiki->setSpeed(0.5f, dirToTarget);
	}
}

/*
 * --INFO--
 * Address:	800BA960
 * Size:	0002F4
 */
void ActFree::init(Creature*)
{
	mIsBoidActive           = false;
	mCollisionCooldownTimer = 1.0f;
	mBoidTimer              = C_PIKI_PROP(mPiki).mDefaultFreeBoidTime() + (3.0f * gsys->getRand(1.0f));
	_20                     = 0.9f * mBoidTimer;
	_24                     = 0.8f * mBoidTimer;

	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (mPiki->isHolding()) {
		PRINT("### piki is holding !\n");
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Wait, this), PaniMotionInfo(PIKIANIM_Wait));
	} else {
		f32 r         = gsys->getRand(1.0f);
		int motionIdx = f32(numMotions) * r;
		if (motionIdx >= numMotions) {
			motionIdx = 0;
		}
		mPiki->startMotion(PaniMotionInfo(motions[motionIdx], this), PaniMotionInfo(motions[motionIdx]));
	}

	mPiki->setPastel();
	_1C            = 0;
	mTouchedPlayer = false;
	mSelectAction->init(nullptr);

	GameStat::workPikis.dec(mPiki->mColor);
	GameStat::freePikis.inc(mPiki->mColor);

	GameStat::update();

	if (mPiki->aiCullable() && !PikiMgr::meNukiMode) {
		seSystem->playPikiSound(SEF_PIKI_BREAKUP, mPiki->mPosition);
	}

	EffectParm parm(&mPiki->mEffectPos);
	mPiki->mFreeLightEffect->mColor = mPiki->mColor;
	mPiki->mFreeLightEffect->emit(parm);
	mPiki->enableFixPos();
	mFixedPositionTimer = 3.0f;
}

/*
 * --INFO--
 * Address:	800BAC54
 * Size:	0000AC
 */
void ActFree::cleanup()
{
	mPiki->disableFixPos();
	mPiki->mCreatureFlags &= ~CF_IsPositionFixed;
	mPiki->mFreeLightEffect->kill();
	GameStat::workPikis.inc(mPiki->mColor);
	GameStat::freePikis.dec(mPiki->mColor);
#if 0 // DLL only?  Stack is too large if this is included.
	if (GameStat::freePikis < 0) {
		ERROR("counter minus(fp)");
	}
#endif
	GameStat::update();
}

/*
 * --INFO--
 * Address:	800BAD00
 * Size:	000004
 */
void ActFree::animationKeyUpdated(PaniAnimKeyEvent&)
{
}

/*
 * --INFO--
 * Address:	800BAD04
 * Size:	0000F0
 */
int ActFree::exec()
{
	Creature* target;
	STACK_PAD_VAR(23); // huh.

	if (mCollisionCooldownTimer > 0.0f) {
		mCollisionCooldownTimer -= gsys->getFrameTime();
	}

	// Look, but don't touch.
	if (mTouchedPlayer) {
		mPiki->mFSM->transit(mPiki, PIKISTATE_LookAt);
		return ACTOUT_Continue;
	}

	if (mIsBoidActive) {
		exeBoid();
		return ACTOUT_Continue;
	}

	int res = mSelectAction->exec();
	if (!mPiki->mPikiUpdateContext.updatable()) {
		return ACTOUT_Continue;
	}

	if (mPiki->graspSituation(&target)) {
		mSelectAction->finishRest();
	}

	return res;
}

/*
 * --INFO--
 * Address:	800BADF4
 * Size:	0000D8
 */
void ActFree::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (mCollisionCooldownTimer > 0.0f || mIsBoidActive) {
		return;
	}

	Creature* collider = msg->mEvent.mCollider;
	if (collider->mObjType == OBJTYPE_Navi && !piki->isKinoko() && !collider->mStickListHead && !mTouchedPlayer
	    && (piki->mPlayerId == -1 || static_cast<Navi*>(collider)->mNaviID == piki->mPlayerId)) {
		rumbleMgr->start(RUMBLE_Unk2, 0, nullptr);
		mTouchedPlayer = true;
		piki->mNavi    = static_cast<Navi*>(collider);
	}
}
