#include "DebugLog.h"
#include "MizuItem.h"
#include "PikiAI.h"
#include "SoundMgr.h"
#include "WeedsItem.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	800C30A8
 * Size:	000054
 */
ActWeed::ActWeed(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800C30FC
 * Size:	000058
 */
void ActWeed::init(Creature* creature)
{
	mCurrGrass = nullptr;
	if (creature && creature->mObjType == OBJTYPE_GrassGen) {
		mGrassGen = static_cast<GrassGen*>(creature);
		mGrassGen->startWork();
	}

	initApproach();
}

/*
 * --INFO--
 * Address:	800C3154
 * Size:	000060
 */
int ActWeed::exec()
{
	switch (mState) {
	case STATE_Approach:
		return exeApproach();

	case STATE_Adjust:
		return exeAdjust();

	case STATE_Attack:
		return exeNuking();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C31B4
 * Size:	00002C
 */
void ActWeed::cleanup()
{
	if (mGrassGen) {
		mGrassGen->finishWork();
	}
}

/*
 * --INFO--
 * Address:	800C31E0
 * Size:	000070
 */
void ActWeed::initApproach()
{
	mState     = STATE_Approach;
	mCurrGrass = mGrassGen->getRandomGrass();
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
}

/*
 * --INFO--
 * Address:	800C3250
 * Size:	0001E0
 */
int ActWeed::exeApproach()
{
	if (!mCurrGrass) {
		mPiki->mEmotion = PikiEmotion::Sad;
		return ACTOUT_Fail;
	}

	if (!mCurrGrass->isAlive()) {
		initApproach();
		return ACTOUT_Continue;
	}

	Vector3f direction = mCurrGrass->mPosition - mPiki->mPosition;
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
 * Address:	800C3430
 * Size:	00000C
 */
void ActWeed::initAdjust()
{
	mState = STATE_Adjust;
}

/*
 * --INFO--
 * Address:	800C343C
 * Size:	000214
 */
int ActWeed::exeAdjust()
{
	if (!mCurrGrass) {
		mPiki->mEmotion = PikiEmotion::Sad;
		return ACTOUT_Fail;
	}

	if (!mCurrGrass->isAlive()) {
		initApproach();
		return ACTOUT_Continue;
	}

	Vector3f direction = mCurrGrass->mPosition - mPiki->mPosition;
	f32 dist2D         = std::sqrtf(direction.x * direction.x + direction.z * direction.z);
	f32 unused         = direction.normalise();

	if (dist2D < 4.0f) {
		initNuking();
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		return ACTOUT_Continue;
	}

	mPiki->setSpeed(0.5f, direction);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C3650
 * Size:	00008C
 */
void ActWeed::initNuking()
{
	mState = STATE_Attack;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Nuku, this), PaniMotionInfo(PIKIANIM_Nuku));
	_28                = 4;
	mAnimationFinished = 0;
}

/*
 * --INFO--
 * Address:	800C36DC
 * Size:	0000E0
 */
int ActWeed::exeNuking()
{
	if (mAnimationFinished) {
		initApproach();
		return ACTOUT_Continue;
	}

	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);

	if (mAnimationFinished) {
		mPiki->mEmotion = PikiEmotion::None;
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C37BC
 * Size:	0002B4
 */
void ActWeed::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		if (mState != STATE_Attack) {
			return;
		}
		mPiki->mPikiAnimMgr.finishMotion(this);
		int grassState = mCurrGrass->nuku();

		if (grassState == ACTOUT_Continue || grassState == ACTOUT_Success) {
			mPiki->playEventSound(mGrassGen, SEB_GRASS_PULL);
			effectMgr->create(EffectMgr::EFF_Weed_Smoke, mCurrGrass->mPosition, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Weed_Rocks, mCurrGrass->mPosition, nullptr, nullptr);
			zen::particleGenerator* ptclGen = effectMgr->create(EffectMgr::EFF_Weed_Pull, mCurrGrass->mPosition, nullptr, nullptr);
			if (ptclGen) {
				ptclGen->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
			}
			mGrassGen->killGrass();

			if (gsys->getRand(1.0f) > (1.0f - GRASS_NECTAR_CHANCE)) {
				MizuItem* nectar = static_cast<MizuItem*>(itemMgr->birth(OBJTYPE_FallWater));
				if (nectar) {
					Vector3f nectarPos(mCurrGrass->mPosition);
					nectarPos.y += 10.0f;
					f32 randAngle  = 2.0f * (PI * gsys->getRand(1.0f));
					f32 horizSpeed = 30.0f;
					f32 vertSpeed  = 400.0f;
					Vector3f vel(30.0f * sinf(randAngle), vertSpeed, 30.0f * cosf(randAngle));
					nectar->init(nectarPos);
					nectar->mVelocity = vel;
					nectar->startAI(0);
				}
			}
		}
		break;
	case KEY_Finished:
		if (mState == STATE_Attack) {
			mAnimationFinished = 1;
		}

		break;
	}
}
