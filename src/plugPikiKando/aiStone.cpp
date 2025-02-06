#include "PikiAI.h"
#include "WeedsItem.h"
#include "MizuItem.h"
#include "SoundMgr.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	800A6D94
 * Size:	000054
 */
ActStone::ActStone(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800A6DE8
 * Size:	000058
 */
void ActStone::init(Creature* creature)
{
	mCurrPebble = nullptr;
	if (creature && creature->mObjType == OBJTYPE_RockGen) {
		mRockGen = static_cast<RockGen*>(creature);
		mRockGen->startWork();
	}

	initApproach();
}

/*
 * --INFO--
 * Address:	800A6E40
 * Size:	000074
 */
int ActStone::exec()
{
	if (mCurrPebble == nullptr) {
		return ACTOUT_Success;
	}

	switch (mState) {
	case STATE_Approach:
		return exeApproach();

	case STATE_Adjust:
		return exeAdjust();

	case STATE_Attack:
		return exeAttack();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800A6EB4
 * Size:	00004C
 */
void ActStone::cleanup()
{
	mPiki->disableFixPos();
	mPiki->resetCreatureFlag(CF_IsPositionFixed);
	if (mRockGen) {
		mRockGen->finishWork();
	}
}

/*
 * --INFO--
 * Address:	800A6F00
 * Size:	000084
 */
void ActStone::initApproach()
{
	if (mRockGen) {
		mCurrPebble = mRockGen->getRandomPebble();
	} else {
		mCurrPebble = nullptr;
	}

	mState = STATE_Approach;

	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
}

/*
 * --INFO--
 * Address:	800A6F84
 * Size:	000190
 */
int ActStone::exeApproach()
{
	if (!mCurrPebble || !mCurrPebble->isAlive()) {
		mPiki->mEmotion = PikiEmotion::Unk1;
		return ACTOUT_Fail;
	}

	Vector3f direction = mCurrPebble->mPosition - mPiki->mPosition;
	f32 dist2D         = std::sqrtf(direction.x * direction.x + direction.z * direction.z);
	f32 unused         = direction.normalise();

	if (dist2D <= 20.0f) {
		initAdjust();
		return ACTOUT_Continue;
	}

	mPiki->setSpeed(0.7f, direction);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800A7114
 * Size:	00000C
 */
void ActStone::initAdjust()
{
	mState = STATE_Adjust;
}

/*
 * --INFO--
 * Address:	800A7120
 * Size:	0001C4
 */
int ActStone::exeAdjust()
{
	if (!mCurrPebble || !mCurrPebble->isAlive()) {
		mPiki->mEmotion = PikiEmotion::Unk1;
		return ACTOUT_Fail;
	}

	Vector3f direction = mCurrPebble->mPosition - mPiki->mPosition;
	f32 dist2D         = std::sqrtf(direction.x * direction.x + direction.z * direction.z);
	f32 unused         = direction.normalise();

	if (dist2D < 8.0f) {
		initAttack();
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		return ACTOUT_Continue;
	}

	mPiki->setSpeed(0.5f, direction);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800A72E4
 * Size:	000094
 */
void ActStone::initAttack()
{
	mState = STATE_Attack;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Job2, this), PaniMotionInfo(PIKIANIM_Job2));
	mIsAttackReady = 0;
	mPiki->enableFixPos();
}

/*
 * --INFO--
 * Address:	800A7378
 * Size:	000174
 */
int ActStone::exeAttack()
{
	if (mCurrPebble->mHealth == 0) {
		mPiki->disableFixPos();
		mPiki->resetCreatureFlag(CF_IsPositionFixed);

		initApproach();
		return ACTOUT_Continue;
	}

	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
	if (mIsAttackReady) {
		initAttack();
		return ACTOUT_Continue;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800A74EC
 * Size:	00030C
 */
void ActStone::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		if (mState != STATE_Attack) {
			return;
		}
		mPiki->mPikiAnimMgr.finishMotion(this);
		int pebbleState = mCurrPebble->attack();

		if (pebbleState == ACTOUT_Fail) {
			return;
		}

		Vector3f effectPos(sinf(mPiki->mFaceDirection), 0.0f, cosf(mPiki->mFaceDirection));
		effectPos = effectPos * 5.0f + mPiki->mPosition;
		EffectParm parm(effectPos);
		UtEffectMgr::cast(KandoEffect::WallHit0, parm);

		if (pebbleState == ACTOUT_Success) {
			UtEffectMgr::cast(KandoEffect::PikiGrowup2, parm);
			mRockGen->killPebble();
			mPiki->playEventSound(mRockGen, SEB_STONE_BREAK);
			if (System::getRand(1.0f) > (1.0f - STONE_NECTAR_CHANCE)) {
				MizuItem* nectar = static_cast<MizuItem*>(itemMgr->birth(OBJTYPE_FallWater));
				if (nectar) {
					Vector3f nectarPos(effectPos);
					nectarPos.y += 10.0f;
					f32 randAngle  = 2.0f * (PI * System::getRand(1.0f));
					f32 horizSpeed = 30.0f;
					f32 vertSpeed  = 400.0f;
					Vector3f vel(30.0f * sinf(randAngle), vertSpeed, 30.0f * cosf(randAngle));
					nectar->init(nectarPos);
					nectar->mVelocity = vel;
					nectar->startAI(0);
					u32 badCompiler[2];
				}
			}
		} else {
			mPiki->playEventSound(mRockGen, SEB_STONE_HIT);
		}
		break;
	case KEY_Finished:
		if (mState == STATE_Attack) {
			mIsAttackReady = 1;
		}

		break;
	}
}
