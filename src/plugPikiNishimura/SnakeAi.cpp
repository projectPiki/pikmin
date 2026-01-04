#include "DebugLog.h"
#include "EffectMgr.h"
#include "GameStat.h"
#include "Interactions.h"
#include "MapMgr.h"
#include "NaviMgr.h"
#include "NsMath.h"
#include "Pcam/CameraManager.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "Snake.h"
#include "SoundMgr.h"
#include "zen/Math.h"

static u32 snakeSE[] = {
	SE_SNAKE_APPEAR, SE_SNAKE_DIG,    SE_SNAKE_SHOUT, SE_SNAKE_EAT,   SE_SNAKE_DRINK,
	SE_SNAKE_TURN,   SE_SNAKE_MOGAKU, SE_KING_DEAD2,  SE_SNAKE_DEAD2,
};

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("SnakeAi");

/**
 * @todo: Documentation
 */
SnakeAi::SnakeAi(Snake* snake)
{
	mSnake           = snake;
	mAttackDists     = new f32[5];
	mAttackLimits    = new f32[5];
	mAttackMinus     = new f32[5];
	mAttackPlus      = new f32[5];
	mAttackHeights   = new f32[5];
	_2C              = new u32[5];
	mAttackPositions = new Vector3f[5];
}

/**
 * @todo: Documentation
 */
void SnakeAi::initAI(Snake* snake)
{
	mSnake = snake;
	mSnake->setCurrentState(8);
	mSnake->setNextState(8);
	mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Move1, this));

	mFastAppear        = true;
	mIsFacingTarget    = false;
	mIsAttackAllowed   = true;
	mAttackId          = 0;
	mOccupiedSlotCount = 0;
	mMouthSlotFlag     = 0;
	mMaxSlotCount      = mSnake->mCollInfo->getSphere('slot')->getChildCount();
}

/**
 * @todo: Documentation
 */
void SnakeAi::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
	{
		keyAction0();
		break;
	}
	case KEY_Action1:
	{
		keyAction1();
		break;
	}
	case KEY_LoopEnd:
	{
		keyLoopEnd();
		break;
	}
	case KEY_Finished:
	{
		keyFinished();
		break;
	}
	case KEY_PlaySound:
	{
		playSound(event.mValue);
		break;
	}
	}
}

/**
 * @todo: Documentation
 */
void SnakeAi::keyAction0()
{
	int currState = mSnake->getCurrentState();
	if (currState == SNAKEAI_Die) {
		// https://youtu.be/kUh39du0GOY?list=PLJQZtsZNm8a6FIw5Tz43lPfjeWqZ-DgxV&t=280
		// Confirms that this code is correctly annotated.
		Vector3f headPos(mSnake->mSnakeBody->mSegmentPositionList[SnakeJointType::Neck]);
		headPos.y = mapMgr->getMinY(headPos.x, headPos.z, true);
		effectMgr->create(EffectMgr::EFF_CloudOfDust_1, headPos, nullptr, nullptr);
		return;
	}

	if (currState == SNAKEAI_Attack) {
		checkAttackTarget();
		return;
	}

	if (currState == SNAKEAI_GoInto) {
		mSnake->calcFlickPiki();
		mSnake->disableStick();
		return;
	}

	if (currState == SNAKEAI_Eat) {
		eatStickToMouthPiki();
		return;
	}

	if (currState == SNAKEAI_Appear) {
		effectMgr->create(EffectMgr::EFF_Snake_Appear1, mSnake->mSRT.t, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Snake_Appear2, mSnake->mSRT.t, nullptr, nullptr);
		return;
	}
}

/**
 * @todo: Documentation
 */
void SnakeAi::keyAction1()
{
	if (mSnake->getCurrentState() == SNAKEAI_Die) {
		Vector3f headPos(mSnake->mSnakeBody->mSegmentPositionList[SnakeJointType::Neck]);
		headPos.y = mapMgr->getMinY(headPos.x, headPos.z, true);
		effectMgr->create(EffectMgr::EFF_CloudOfDust_2, headPos, nullptr, nullptr);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void SnakeAi::keyAction2()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void SnakeAi::keyAction3()
{
}

/**
 * @todo: Documentation
 */
void SnakeAi::keyLoopEnd()
{
	mSnake->addLoopCounter(1);
	if (mSnake->getCurrentState() == SNAKEAI_Attack && mIsAttackAllowed) {
		f32 attackVals[5] = { 32.0f, 32.0f, 32.0f, 28.0f, 28.0f };

		attackTransit(5);
		initAttack(SNAKEAI_Attack, attackVals[mAttackId]);
	}
}

/**
 * @todo: Documentation
 */
void SnakeAi::keyFinished()
{
	mSnake->setMotionFinish(true);
}

/**
 * @todo: Documentation
 */
void SnakeAi::playSound(int snakeSoundID)
{
	if (mSnake->mSeContext) {
		mSnake->mSeContext->playSound(snakeSE[snakeSoundID]);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000054
 */
void SnakeAi::setEveryFrame()
{
	setInitPosition();
	traceTargetPosition();
	setAttackPosition();
	if (mSnake->getDamagePoint() > 0.0f) {
		mSnake->calcBossDamage();
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00002C
 */
void SnakeAi::setInitPosition()
{
	Vector3f* initPos = mSnake->getInitPosition();
	mSnake->mSRT.t.x  = initPos->x;
	mSnake->mSRT.t.y  = initPos->y;
	mSnake->mSRT.t.z  = initPos->z;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
void SnakeAi::setUnderPosition()
{
	mSnake->setInitPosition(mSnake->mSpawnPosition);
	mSnake->mSRT.t = mSnake->mSpawnPosition;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00012C
 */
void SnakeAi::setAppearPosition01()
{
	Vector3f appearPos;
	f32 randAngle    = NsMathF::getRand(TAU);
	Creature* target = mSnake->getTargetCreature();
	appearPos.x      = C_SNAKE_PROP(mSnake).mType1AppearDist() * cosf(randAngle) + target->mSRT.t.x;
	appearPos.z      = C_SNAKE_PROP(mSnake).mType1AppearDist() * sinf(randAngle) + target->mSRT.t.z;
	appearPos.y      = mapMgr->getMinY(appearPos.x, appearPos.z, true);
	mSnake->setInitPosition(appearPos);
	mSnake->mSRT.t = appearPos;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0002A0
 */
void SnakeAi::setAppearPosition02()
{
	Vector3f appearPos;
	Vector3f targetPos(mSnake->getTargetCreature()->mSRT.t);
	Vector3f dir(sinf(mSnake->_3C0), 0.0f, cosf(mSnake->_3C0));

	Vector3f startPoint  = mSnake->mSpawnPosition + C_SNAKE_PROP(mSnake).mType2AppearFrontDist() * dir;
	Vector3f endPoint    = mSnake->mSpawnPosition - C_SNAKE_PROP(mSnake).mType2AppearFrontDist() * dir;
	Vector3f lineSegment = endPoint - startPoint;

	f32 blendRatio;
	zen::getDistPointAndLine(targetPos, startPoint, endPoint, blendRatio);
	blendRatio = NsLibMath<f32>::revice(blendRatio, 0.0f, 1.0f);

	appearPos   = startPoint + blendRatio * lineSegment;
	appearPos.y = mapMgr->getMinY(appearPos.x, appearPos.z, true);

	mSnake->setInitPosition(appearPos);
	mSnake->mSRT.t = appearPos;
}

/**
 * @todo: Documentation
 */
void SnakeAi::traceTargetPosition()
{
	mIsFacingTarget = false;
	mSnake->makeTargetCreature();

	// Handle chase states
	if (mSnake->getCurrentState() >= SNAKEAI_ChaseNavi && mSnake->getCurrentState() <= SNAKEAI_ChasePiki) {
		if (mSnake->mSnakeBody->mBlendingRatio == 0.0f) {
			mIsFacingTarget = mSnake->changeDirection(C_SNAKE_PROP(mSnake).mChaseBodyTurnSpeed());
		} else {
			mIsFacingTarget = mSnake->changeDirection(C_SNAKE_PROP(mSnake).mNormBodyTurnSpeed());
		}
	}
	// Handle attack states
	else if (mSnake->getCurrentState() == SNAKEAI_Attack && mIsAttackAllowed) {
		if (mAttackId == 0) {
			mIsFacingTarget = mSnake->changeDirection(C_SNAKE_PROP(mSnake).mNormBodyTurnSpeed());
		} else if (mAttackId == 1) {
			mIsFacingTarget = mSnake->changeDirection(C_SNAKE_PROP(mSnake).mNormBodyTurnSpeed() / 3.0f);
		} else if (mAttackId == 2) {
			mIsFacingTarget = mSnake->changeDirection(C_SNAKE_PROP(mSnake).mNormBodyTurnSpeed() / 5.0f);
		}
	}
}

/**
 * @todo: Documentation
 */
void SnakeAi::setAttackPosition()
{
	// Calculate front and side direction vectors
	mSnakeFrontDir.set(sinf(mSnake->mSRT.r.y), 0.0f, cosf(mSnake->mSRT.r.y));
	NsCalculation::calcOuterPro(mSnakeFrontDir, Vector3f(0.0f, 1.0f, 0.0f), mSnakeSideDir);
	mSnakeFrontDir.normalise();
	mSnakeSideDir.normalise();

	// Calculate NEAR attack values
	mAttackDists[SNAKEATK_Near]   = C_SNAKE_PROP(mSnake).mNearAttackDist();
	mAttackLimits[SNAKEATK_Near]  = C_SNAKE_PROP(mSnake).mNearAttackLimit();
	mAttackMinus[SNAKEATK_Near]   = C_SNAKE_PROP(mSnake).mNearAttackMinus();
	mAttackPlus[SNAKEATK_Near]    = C_SNAKE_PROP(mSnake).mNearAttackPlus();
	mAttackHeights[SNAKEATK_Near] = C_SNAKE_PROP(mSnake).mNearAttackHeight();

	f32 nearFront                     = (mAttackDists[SNAKEATK_Near] + mAttackLimits[SNAKEATK_Near]) / 2.0f;
	f32 nearSide                      = (mAttackMinus[SNAKEATK_Near] + mAttackPlus[SNAKEATK_Near]) / 2.0f;
	mAttackPositions[SNAKEATK_Near]   = mSnake->mSRT.t + nearFront * mSnakeFrontDir + nearSide * mSnakeSideDir;
	mAttackPositions[SNAKEATK_Near].y = mapMgr->getMinY(mAttackPositions[SNAKEATK_Near].x, mAttackPositions[SNAKEATK_Near].z, true);

	// Calculate MID attack values
	mAttackDists[SNAKEATK_Mid]   = C_SNAKE_PROP(mSnake).mMidAttackDist();
	mAttackLimits[SNAKEATK_Mid]  = C_SNAKE_PROP(mSnake).mMidAttackLimit();
	mAttackMinus[SNAKEATK_Mid]   = C_SNAKE_PROP(mSnake).mMidAttackMinus();
	mAttackPlus[SNAKEATK_Mid]    = C_SNAKE_PROP(mSnake).mMidAttackPlus();
	mAttackHeights[SNAKEATK_Mid] = C_SNAKE_PROP(mSnake).mMidAttackHeight();

	f32 midFront                     = (mAttackDists[SNAKEATK_Mid] + mAttackLimits[SNAKEATK_Mid]) / 2.0f;
	f32 midSide                      = (mAttackMinus[SNAKEATK_Mid] + mAttackPlus[SNAKEATK_Mid]) / 2.0f;
	mAttackPositions[SNAKEATK_Mid]   = mSnake->mSRT.t + midFront * mSnakeFrontDir + midSide * mSnakeSideDir;
	mAttackPositions[SNAKEATK_Mid].y = mapMgr->getMinY(mAttackPositions[SNAKEATK_Mid].x, mAttackPositions[SNAKEATK_Mid].z, true);

	// Calculate FAR attack values
	mAttackDists[SNAKEATK_Far]   = C_SNAKE_PROP(mSnake).mFarAttackDist();
	mAttackLimits[SNAKEATK_Far]  = C_SNAKE_PROP(mSnake).mFarAttackLimit();
	mAttackMinus[SNAKEATK_Far]   = C_SNAKE_PROP(mSnake).mFarAttackMinus();
	mAttackPlus[SNAKEATK_Far]    = C_SNAKE_PROP(mSnake).mFarAttackPlus();
	mAttackHeights[SNAKEATK_Far] = C_SNAKE_PROP(mSnake).mFarAttackHeight();

	f32 farFront                     = (mAttackDists[SNAKEATK_Far] + mAttackLimits[SNAKEATK_Far]) / 2.0f;
	f32 farSide                      = (mAttackMinus[SNAKEATK_Far] + mAttackPlus[SNAKEATK_Far]) / 2.0f;
	mAttackPositions[SNAKEATK_Far]   = mSnake->mSRT.t + farFront * mSnakeFrontDir + farSide * mSnakeSideDir;
	mAttackPositions[SNAKEATK_Far].y = mapMgr->getMinY(mAttackPositions[SNAKEATK_Far].x, mAttackPositions[SNAKEATK_Far].z, true);

	// Calculate RIGHT attack values
	mAttackDists[SNAKEATK_Right]   = C_SNAKE_PROP(mSnake).mRightAttackDist();
	mAttackLimits[SNAKEATK_Right]  = C_SNAKE_PROP(mSnake).mRightAttackLimit();
	mAttackMinus[SNAKEATK_Right]   = C_SNAKE_PROP(mSnake).mRightAttackMinus();
	mAttackPlus[SNAKEATK_Right]    = C_SNAKE_PROP(mSnake).mRightAttackPlus();
	mAttackHeights[SNAKEATK_Right] = C_SNAKE_PROP(mSnake).mRightAttackHeight();

	f32 rightFront                     = (mAttackDists[SNAKEATK_Right] + mAttackLimits[SNAKEATK_Right]) / 2.0f;
	f32 rightSide                      = (mAttackMinus[SNAKEATK_Right] + mAttackPlus[SNAKEATK_Right]) / 2.0f;
	mAttackPositions[SNAKEATK_Right]   = mSnake->mSRT.t + rightFront * mSnakeFrontDir + rightSide * mSnakeSideDir;
	mAttackPositions[SNAKEATK_Right].y = mapMgr->getMinY(mAttackPositions[SNAKEATK_Right].x, mAttackPositions[SNAKEATK_Right].z, true);

	// Calculate LEFT attack values
	mAttackDists[SNAKEATK_Left]   = C_SNAKE_PROP(mSnake).mLeftAttackDist();
	mAttackLimits[SNAKEATK_Left]  = C_SNAKE_PROP(mSnake).mLeftAttackLimit();
	mAttackMinus[SNAKEATK_Left]   = C_SNAKE_PROP(mSnake).mLeftAttackMinus();
	mAttackPlus[SNAKEATK_Left]    = C_SNAKE_PROP(mSnake).mLeftAttackPlus();
	mAttackHeights[SNAKEATK_Left] = C_SNAKE_PROP(mSnake).mLeftAttackHeight();

	f32 leftFront                     = (mAttackDists[SNAKEATK_Left] + mAttackLimits[SNAKEATK_Left]) / 2.0f;
	f32 leftSide                      = (mAttackMinus[SNAKEATK_Left] + mAttackPlus[SNAKEATK_Left]) / 2.0f;
	mAttackPositions[SNAKEATK_Left]   = mSnake->mSRT.t + leftFront * mSnakeFrontDir + leftSide * mSnakeSideDir;
	mAttackPositions[SNAKEATK_Left].y = mapMgr->getMinY(mAttackPositions[SNAKEATK_Left].x, mAttackPositions[SNAKEATK_Left].z, true);
}

/**
 * @todo: Documentation
 */
void SnakeAi::checkAttackTarget()
{
	Creature* target = nullptr;
	f32 targetDist   = 12800.0f;
	nearNaviInAttackArea(&target, &targetDist, mAttackId);
	nearPikiInAttackArea(&target, &targetDist, mAttackId);

	if (target) {
		bool isNavi = false;
		mSnake->setTargetCreature(target);
		if (target->mObjType == OBJTYPE_Navi) {
			naviNudge();
			isNavi = true;
		} else if (target->mObjType == OBJTYPE_Piki) {
			pikiStickMouth();
		} else {
			PRINT(" Hanai Bug. Report it to Mr. Hanai !! ( No such object type ) \n");
		}

		// check if we should stop attacking (hit a navi, full mouth, or no pikis)
		if (isNavi || collPartMaxTransit() || !pikiInAttackArea(5)) {
			mSnake->mAnimator.finishMotion(PaniMotionInfo(PANI_NO_MOTION, this));
			mIsAttackAllowed = false;
		}
		return;
	}

	// no target found
	mSnake->setTargetCreature(nullptr);
	mSnake->mAnimator.finishMotion(PaniMotionInfo(PANI_NO_MOTION, this));
	mIsAttackAllowed = false;
}

/**
 * @todo: Documentation
 */
void SnakeAi::naviNudge()
{
	// lol at calling it a nudge when it's trying to peck your brains out
	InteractAttack nudge(mSnake, nullptr, C_SNAKE_PROP(mSnake).mAttackDamageNavi(), false);
	mSnake->getTargetCreature()->stimulate(nudge);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000018
 */
void SnakeAi::setMouthCollPart(int partNum)
{
	mMouthSlotFlag |= (1 << partNum);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000010
 */
int SnakeAi::getMouthCollPart(int partNum)
{
	return (mMouthSlotFlag >> partNum) & 1;
}

/**
 * @todo: Documentation
 */
void SnakeAi::pikiStickMouth()
{
	CollPart* mouth  = mSnake->mCollInfo->getSphere('slot');
	int randStartNum = NsMathI::getRand(mMaxSlotCount);
	int partNum;
	for (int i = 0; i < mMaxSlotCount; i++) {
		if (randStartNum >= mMaxSlotCount) {
			randStartNum = 0;
		}

		if (!getMouthCollPart(randStartNum)) {
			setMouthCollPart(randStartNum);
			mOccupiedSlotCount++;
			partNum = randStartNum;
			break;
		}
		randStartNum++;
	}

	InteractSwallow swallow(mSnake, mouth->getChildAt(partNum), 0);
	mSnake->getTargetCreature()->stimulate(swallow);
}

/**
 * @todo: Documentation
 */
void SnakeAi::eatStickToMouthPiki()
{
	mOccupiedSlotCount = 0;
	mMouthSlotFlag     = 0;
	mSnake->killStickToMouthPiki();
}

/**
 * @todo: Documentation
 */
void SnakeAi::nearNaviInAttackArea(Creature** target, f32* targetDist, int attackID)
{
	f32 frontDist = (mAttackDists[attackID] + mAttackLimits[attackID]) / 2.0f;
	f32 sideDist  = (mAttackMinus[attackID] + mAttackPlus[attackID]) / 2.0f;

	Iterator iter(naviMgr);
	CI_LOOP(iter)
	{
		Creature* navi = *iter;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()) {
			f32 xDiff = navi->mSRT.t.x - mSnake->mSRT.t.x;
			f32 zDiff = navi->mSRT.t.z - mSnake->mSRT.t.z;

			f32 frontProj = mSnakeFrontDir.x * xDiff + mSnakeFrontDir.z * zDiff;
			f32 sideProj  = mSnakeSideDir.x * xDiff + mSnakeSideDir.z * zDiff;

			if (frontProj > mAttackDists[attackID] && frontProj < mAttackLimits[attackID] && sideProj > mAttackMinus[attackID]
			    && sideProj < mAttackPlus[attackID]
			    && NsLibMath<f32>::abs(mAttackPositions[attackID].y - navi->mSRT.t.y) < mAttackHeights[attackID]) {
				f32 dist = qdist2(frontProj, sideProj, frontDist, sideDist);
				if (dist < *targetDist) {
					*targetDist = dist;
					*target     = navi;
				}
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void SnakeAi::nearPikiInAttackArea(Creature** target, f32* targetDist, int attackID)
{
	f32 frontDist = (mAttackDists[attackID] + mAttackLimits[attackID]) / 2.0f;
	f32 sideDist  = (mAttackMinus[attackID] + mAttackPlus[attackID]) / 2.0f;

	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried()) {
			f32 xDiff = piki->mSRT.t.x - mSnake->mSRT.t.x;
			f32 zDiff = piki->mSRT.t.z - mSnake->mSRT.t.z;

			f32 frontProj = mSnakeFrontDir.x * xDiff + mSnakeFrontDir.z * zDiff;
			f32 sideProj  = mSnakeSideDir.x * xDiff + mSnakeSideDir.z * zDiff;

			if (frontProj > mAttackDists[attackID] && frontProj < mAttackLimits[attackID] && sideProj > mAttackMinus[attackID]
			    && sideProj < mAttackPlus[attackID]
			    && NsLibMath<f32>::abs(mAttackPositions[attackID].y - piki->mSRT.t.y) < mAttackHeights[attackID]) {
				f32 dist = qdist2(frontProj, sideProj, frontDist, sideDist);
				if (dist < *targetDist) {
					*targetDist = dist;
					*target     = piki;
				}
			}
		}
	}
}

/**
 * @todo: Documentation
 */
bool SnakeAi::naviInAttackArea(int attackType)
{
	Iterator iter(naviMgr);
	CI_LOOP(iter)
	{
		Creature* navi = *iter;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()) {
			f32 xDiff = navi->mSRT.t.x - mSnake->mSRT.t.x;
			f32 zDiff = navi->mSRT.t.z - mSnake->mSRT.t.z;

			f32 frontProj = mSnakeFrontDir.x * xDiff + mSnakeFrontDir.z * zDiff;
			f32 sideProj  = mSnakeSideDir.x * xDiff + mSnakeSideDir.z * zDiff;
			for (int i = 0; i < attackType; i++) {
				if (frontProj > mAttackDists[i] && frontProj < mAttackLimits[i] && sideProj > mAttackMinus[i] && sideProj < mAttackPlus[i]
				    && NsLibMath<f32>::abs(mAttackPositions[i].y - navi->mSRT.t.y) < mAttackHeights[i]) {
					mSnake->setTargetCreature(navi);
					mAttackId = i;
					return true;
				}
			}
		}
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool SnakeAi::pikiInAttackArea(int attackType)
{
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried()) {
			f32 xDiff = piki->mSRT.t.x - mSnake->mSRT.t.x;
			f32 zDiff = piki->mSRT.t.z - mSnake->mSRT.t.z;

			f32 frontProj = mSnakeFrontDir.x * xDiff + mSnakeFrontDir.z * zDiff;
			f32 sideProj  = mSnakeSideDir.x * xDiff + mSnakeSideDir.z * zDiff;
			for (int i = 0; i < attackType; i++) {
				if (frontProj > mAttackDists[i] && frontProj < mAttackLimits[i] && sideProj > mAttackMinus[i] && sideProj < mAttackPlus[i]
				    && NsLibMath<f32>::abs(mAttackPositions[i].y - piki->mSRT.t.y) < mAttackHeights[i]) {
					mSnake->setTargetCreature(piki);
					mAttackId = i;
					return true;
				}
			}
		}
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool SnakeAi::appearType01()
{
	// check for pikis first
	Iterator iterPiki(pikiMgr);
	CI_LOOP(iterPiki)
	{
		Creature* piki = *iterPiki;
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried()) {
			if (qdist2(piki->mSRT.t.x, piki->mSRT.t.z, mSnake->mSpawnPosition.x, mSnake->mSpawnPosition.z)
			        < C_SNAKE_PROP(mSnake).mType1DetectionRadius()
			    && mSnake->mSpawnPosition.distance(piki->mSRT.t) < C_SNAKE_PROP(mSnake).mType1DetectionRadius()) {
				mSnake->setTargetCreature(piki);
				return true;
			}
		}
	}

	// no pikis found, check for navis
	Iterator iterNavi(naviMgr);
	CI_LOOP(iterNavi)
	{
		Creature* navi = *iterNavi;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()) {
			if (qdist2(navi->mSRT.t.x, navi->mSRT.t.z, mSnake->mSpawnPosition.x, mSnake->mSpawnPosition.z)
			        < C_SNAKE_PROP(mSnake).mType1DetectionRadius()
			    && mSnake->mSpawnPosition.distance(navi->mSRT.t) < C_SNAKE_PROP(mSnake).mType1DetectionRadius()) {
				mSnake->setTargetCreature(navi);
				return true;
			}
		}
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool SnakeAi::appearType02()
{
	f32 perpAngle = mSnake->_3C0 + HALF_PI;
	f32 radius    = C_SNAKE_PROP(mSnake).mType2AppearFrontDist() + C_SNAKE_PROP(mSnake).mType2AppearSideDist();
	Vector3f frontDir(sinf(mSnake->_3C0), 0.0f, cosf(mSnake->_3C0));
	Vector3f sideDir(sinf(perpAngle), 0.0f, cosf(perpAngle));

	f32 frontProj;
	f32 sideProj;
	// check for pikis first
	Iterator iterPiki(pikiMgr);
	CI_LOOP(iterPiki)
	{
		Creature* piki = *iterPiki;
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried()) {
			if (qdist2(piki->mSRT.t.x, piki->mSRT.t.z, mSnake->mSpawnPosition.x, mSnake->mSpawnPosition.z) < radius
			    && NsLibMath<f32>::abs(piki->mSRT.t.y - mSnake->mSpawnPosition.y) < C_SNAKE_PROP(mSnake).mType2AppearVertDist()) {
				f32 xDiff = piki->mSRT.t.x - mSnake->mSpawnPosition.x;
				f32 zDiff = piki->mSRT.t.z - mSnake->mSpawnPosition.z;

				frontProj = frontDir.x * xDiff + frontDir.z * zDiff;
				sideProj  = sideDir.x * xDiff + sideDir.z * zDiff;
				if (NsLibMath<f32>::abs(frontProj) < C_SNAKE_PROP(mSnake).mType2AppearFrontDist()
				    && NsLibMath<f32>::abs(sideProj) < C_SNAKE_PROP(mSnake).mType2AppearSideDist()) {
					mSnake->setTargetCreature(piki);
					return true;
				}
			}
		}
	}

	// no pikis found, check for navis
	Iterator iterNavi(naviMgr);
	CI_LOOP(iterNavi)
	{
		Creature* navi = *iterNavi;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()) {
			if (qdist2(navi->mSRT.t.x, navi->mSRT.t.z, mSnake->mSpawnPosition.x, mSnake->mSpawnPosition.z) < radius
			    && NsLibMath<f32>::abs(navi->mSRT.t.y - mSnake->mSpawnPosition.y) < C_SNAKE_PROP(mSnake).mType2AppearVertDist()) {
				f32 xDiff = navi->mSRT.t.x - mSnake->mSpawnPosition.x;
				f32 zDiff = navi->mSRT.t.z - mSnake->mSpawnPosition.z;

				frontProj = frontDir.x * xDiff + frontDir.z * zDiff;
				sideProj  = sideDir.x * xDiff + sideDir.z * zDiff;
				if (NsLibMath<f32>::abs(frontProj) < C_SNAKE_PROP(mSnake).mType2AppearFrontDist()
				    && NsLibMath<f32>::abs(sideProj) < C_SNAKE_PROP(mSnake).mType2AppearSideDist()) {
					mSnake->setTargetCreature(navi);
					return true;
				}
			}
		}
	}

	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
void SnakeAi::resultFlagOn()
{
	if (mSnake->insideAndInSearch()) {
		playerState->mResultFlags.setOn(zen::RESFLAG_Snake);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00002C
 */
void SnakeAi::resultFlagSeen()
{
	playerState->mResultFlags.setSeen(zen::RESFLAG_Snake);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
bool SnakeAi::dieTransit()
{
	return !mSnake->getAlive();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
bool SnakeAi::struggleTransit()
{
	return mSnake->getStickNoMouthPikiCount() > 0;
}

/**
 * @todo: Documentation
 */
bool SnakeAi::chaseNaviTransit()
{
	Creature* target = nullptr;
	f32 minDist      = 12800.0f;

	Vector3f snakePos(mSnake->mSnakeBody->mNeckPosition);
	Vector3f* initPos = mSnake->getInitPosition();

	if (mSnake->getTargetCreature()) {
		minDist = snakePos.distance(mSnake->getTargetCreature()->mSRT.t);
	}

	Iterator iter(naviMgr);
	CI_LOOP(iter)
	{
		Creature* navi = *iter;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()) {
			f32 quickDist = qdist2(snakePos.x, snakePos.z, navi->mSRT.t.x, navi->mSRT.t.z);
			if (quickDist < C_BOSS_PROP(mSnake).mSearchRadius() && quickDist < minDist) {
				if (mSnake->inSearchAngle(navi)) {
					f32 dist = snakePos.distance(navi->mSRT.t);
					if (dist < C_BOSS_PROP(mSnake).mSearchRadius() && dist < minDist
					    && initPos->distance(navi->mSRT.t) < C_BOSS_PROP(mSnake).mTerritoryRadius()) {
						minDist = dist;
						target  = navi;
					}
				}
			}
		}
	}

	if (target) {
		mSnake->setTargetCreature(target);
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool SnakeAi::chasePikiTransit()
{
	Creature* target = nullptr;
	f32 minDist      = 12800.0f;

	Vector3f snakePos(mSnake->mSnakeBody->mNeckPosition);
	Vector3f* initPos = mSnake->getInitPosition();

	if (mSnake->getTargetCreature()) {
		minDist = snakePos.distance(mSnake->getTargetCreature()->mSRT.t);
	}

	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried() && piki->getStickObject() != mSnake) {
			f32 quickDist = qdist2(snakePos.x, snakePos.z, piki->mSRT.t.x, piki->mSRT.t.z);
			if (quickDist < C_BOSS_PROP(mSnake).mSearchRadius() && quickDist < minDist) {
				if (mSnake->inSearchAngle(piki)) {
					f32 dist = snakePos.distance(piki->mSRT.t);
					if (dist < C_BOSS_PROP(mSnake).mSearchRadius() && dist < minDist
					    && initPos->distance(piki->mSRT.t) < C_BOSS_PROP(mSnake).mTerritoryRadius()) {
						minDist = dist;
						target  = piki;
					}
				}
			}
		}
	}

	if (target) {
		mSnake->setTargetCreature(target);
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool SnakeAi::targetLostTransit()
{
	Creature* target = mSnake->getTargetCreature();
	if (target) {
		if (!target->isAlive() || !target->isVisible() || target->isBuried() || target->getStickObject() == mSnake) {
			mSnake->setTargetCreature(nullptr);
			return true;
		}

		if (!mSnake->inSearchAngle(target)) {
			mSnake->setTargetCreature(nullptr);
			return true;
		}

		if (mSnake->mSnakeBody->mNeckPosition.distance(target->mSRT.t) > C_BOSS_PROP(mSnake).mSearchRadius()) {
			mSnake->setTargetCreature(nullptr);
			return true;
		}

		if (mSnake->getInitPosition()->distance(target->mSRT.t) > C_BOSS_PROP(mSnake).mTerritoryRadius()) {
			mSnake->setTargetCreature(nullptr);
			return true;
		}
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool SnakeAi::attackTransit(int attackType)
{
	bool res = pikiInAttackArea(attackType);
	if (!res) {
		res = naviInAttackArea(attackType);
	}

	return res;
}

/**
 * @todo: Documentation
 */
bool SnakeAi::collPartMaxTransit()
{
	if (mOccupiedSlotCount < mMaxSlotCount) {
		return false;
	}
	return true;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00001C
 */
bool SnakeAi::eatPikiTransit()
{
	if (mOccupiedSlotCount > 0) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
bool SnakeAi::intoGroundTransit()
{
	return mSnake->flickPikiTransit();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000028
 */
bool SnakeAi::diveTimerTransit()
{
	if (mSnake->getWalkTimer() > C_SNAKE_PROP(mSnake).mWaitBeforeDiveTime()) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000028
 */
bool SnakeAi::underTimerTransit()
{
	if (mSnake->getWalkTimer() > C_SNAKE_PROP(mSnake).mWaitUndergroundTime()) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000038
 */
bool SnakeAi::appearTransit()
{
	if (mSnake->mBossType) {
		return appearType01();
	}

	return appearType02();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000088
 */
void SnakeAi::initDie(int nextState)
{
	mSnake->setNextState(nextState);
	mSnake->setMotionFinish(false);
	mSnake->setWalkTimer(0.0f);
	mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Dead, this));
	mSnake->mSnakeBody->initBlending(2.0f);
	resultFlagSeen();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
void SnakeAi::initStruggle(int nextState)
{
	mSnake->setNextState(nextState);
	mSnake->setMotionFinish(false);
	mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::WaitAct2, this));
	mSnake->setLoopCounter(0);
	mSnake->mSnakeBody->initBlending(3.0f);
	resultFlagOn();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000090
 */
void SnakeAi::initChase(int nextState)
{
	mSnake->setNextState(nextState);
	mSnake->setMotionFinish(false);
	mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait1, this));
	mSnake->mSnakeBody->initBlending(C_SNAKE_PROP(mSnake).mChaseBlendingRate());
	resultFlagOn();
}

/**
 * @todo: Documentation
 */
void SnakeAi::initAttack(int nextState, f32 frame)
{
	mSnake->setNextState(nextState);
	mSnake->setAnimTimer(30.0f);
	mSnake->setMotionFinish(false);
	mSnake->setWalkTimer(0.0f);
	mIsAttackAllowed = true;

	if (mAttackId == 0) {
		mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Type1, this));
	} else if (mAttackId == 1) {
		mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Type2, this));
	} else if (mAttackId == 2) {
		mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Type3, this));
	} else if (mAttackId == 3) {
		mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Type4, this));
	} else if (mAttackId == 4) {
		mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Type5, this));
	} else {
		PRINT(" Hanai Bug. Report it to Mr. Hanai !! ( No such attack area ) \n");
	}

	if (frame == 0.0f) {
		mSnake->mSnakeBody->initBlending(3.0f);
	} else {
		mSnake->mAnimator.setCounter(frame);
	}
	resultFlagOn();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00008C
 */
void SnakeAi::initEat(int nextState)
{
	mSnake->setNextState(nextState);
	mSnake->setMotionFinish(false);
	mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::WaitAct1, this));
	mSnake->mSnakeBody->initBlending(3.0f);
	resultFlagOn();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000088
 */
void SnakeAi::initWait(int nextState)
{
	mSnake->setNextState(nextState);
	mSnake->setMotionFinish(false);
	mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Wait1, this));
	mSnake->setTargetCreature(nullptr);
	mSnake->setWalkTimer(0.0f);
	mSnake->mSnakeBody->initBlending(1.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000D8
 */
void SnakeAi::initGointo(int nextState)
{
	mSnake->setNextState(nextState);
	mSnake->setMotionFinish(false);
	mSnake->setShadowNeed(false);
	mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Flick, this));
	mSnake->mSnakeBody->initBlending(2.0f);
	effectMgr->create(EffectMgr::EFF_Snake_Appear1, mSnake->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Snake_Appear2, mSnake->mSRT.t, nullptr, nullptr);
	rumbleMgr->start(RUMBLE_Unk6, 0, mSnake->mSRT.t);
	cameraMgr->startVibrationEvent(4, mSnake->mSRT.t);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000108
 */
void SnakeAi::initUnder(int nextState)
{
	mSnake->setNextState(nextState);
	mSnake->setMotionFinish(false);
	mSnake->setAnimTimer(0.0f);
	mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Move1, this));
	effectMgr->create(EffectMgr::EFF_BigDustRing, mSnake->mSRT.t, nullptr, nullptr);
	mSnake->mSnakeBody->initBlending(12800.0f);
	mOccupiedSlotCount = 0;
	mMouthSlotFlag     = 0;
	mSnake->killStickToMouthPiki();
	mSnake->setWalkTimer(0.0f);
	mSnake->setIsAlive(false);
	mSnake->setIsAtari(false);
	mSnake->_3C4 = 0.0f;
	setUnderPosition();
}

/**
 * @todo: Documentation
 */
void SnakeAi::initAppear(int nextState)
{
	mSnake->setNextState(nextState);
	mSnake->setMotionFinish(false);
	mSnake->setAnimTimer(30.0f);
	if (mFastAppear) {
		mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Move1, this));
		mFastAppear = false;
	} else if (NsMathF::getRand(1.0f) < C_SNAKE_PROP(mSnake).mFastAppearChance()) {
		mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Move1, this));
	} else {
		mSnake->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Move2, this));
	}

	mSnake->mSnakeBody->initBlending(12800.0f);

	if (mSnake->mBossType) {
		setAppearPosition01();
	} else {
		setAppearPosition02();
	}

	mSnake->makeTargetCreature();
	mSnake->changeDirection(12800.0f);
	mSnake->enableStick();

	mSnake->setIsAlive(true);
	mSnake->setIsAtari(true);
	mSnake->setShadowNeed(true);
	mSnake->_3C4 = 1.0f;
	effectMgr->create(EffectMgr::EFF_Snake_Appear1, mSnake->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Snake_Appear2, mSnake->mSRT.t, nullptr, nullptr);

	mSnake->mSnakeBody->setBodyOnGroundEffect();

	rumbleMgr->start(RUMBLE_Unk11, 0, mSnake->mSRT.t);
	cameraMgr->startVibrationEvent(4, mSnake->mSRT.t);
	resultFlagOn();

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x208(r1)
	  stfd      f31, 0x200(r1)
	  stfd      f30, 0x1F8(r1)
	  stfd      f29, 0x1F0(r1)
	  stfd      f28, 0x1E8(r1)
	  stfd      f27, 0x1E0(r1)
	  stfd      f26, 0x1D8(r1)
	  stfd      f25, 0x1D0(r1)
	  stfd      f24, 0x1C8(r1)
	  stfd      f23, 0x1C0(r1)
	  stfd      f22, 0x1B8(r1)
	  stw       r31, 0x1B4(r1)
	  mr        r31, r3
	  stw       r30, 0x1B0(r1)
	  li        r30, 0
	  stw       r29, 0x1AC(r1)
	  lwz       r3, 0x4C(r3)
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x4C(r31)
	  stb       r30, 0x2BD(r3)
	  lfs       f0, -0x555C(r2)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x2D8(r3)
	  lbz       r0, 0x6(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x98
	  addi      r5, r31, 0
	  addi      r3, r1, 0x194
	  li        r4, 0x6
	  bl        -0x3F1DC
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3EFB8
	  stb       r30, 0x6(r31)
	  b         .loc_0x12C

	.loc_0x98:
	  lwz       r3, 0x4C(r31)
	  lwz       r3, 0x224(r3)
	  addi      r30, r3, 0x4A0
	  bl        0xB9EE0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x5580(r2)
	  stw       r0, 0x1A4(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x5588(r2)
	  stw       r0, 0x1A0(r1)
	  lfs       f2, -0x558C(r2)
	  lfd       f0, 0x1A0(r1)
	  lfs       f1, -0x5568(r2)
	  fsubs     f4, f0, f4
	  lfs       f0, 0x0(r30)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x10C
	  addi      r5, r31, 0
	  addi      r3, r1, 0x18C
	  li        r4, 0x6
	  bl        -0x3F254
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3F030
	  b         .loc_0x12C

	.loc_0x10C:
	  addi      r5, r31, 0
	  addi      r3, r1, 0x184
	  li        r4, 0x7
	  bl        -0x3F278
	  lwz       r5, 0x4C(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x3F054

	.loc_0x12C:
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x556C(r2)
	  lwz       r3, 0x3CC(r3)
	  bl        0x1F00
	  lwz       r4, 0x4C(r31)
	  lbz       r0, 0x3BC(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x23C
	  lfs       f0, -0x5590(r2)
	  stfs      f0, 0x16C(r1)
	  stfs      f0, 0x168(r1)
	  stfs      f0, 0x164(r1)
	  bl        0xB9E28
	  xoris     r0, r3, 0x8000
	  lwz       r4, 0x4C(r31)
	  stw       r0, 0x1A4(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x224(r4)
	  stw       r0, 0x1A0(r1)
	  lfd       f1, -0x5580(r2)
	  addi      r29, r3, 0x220
	  lfd       f0, 0x1A0(r1)
	  lfs       f2, -0x5588(r2)
	  fsubs     f3, f0, f1
	  lfs       f1, -0x558C(r2)
	  lfs       f0, -0x5584(r2)
	  lwz       r30, 0x318(r4)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f26, f0, f1
	  fmr       f1, f26
	  bl        0xBD8C0
	  lfs       f2, 0x0(r29)
	  lfs       f0, 0x94(r30)
	  fmuls     f2, f2, f1
	  fmr       f1, f26
	  fadds     f0, f0, f2
	  stfs      f0, 0x164(r1)
	  lwz       r3, 0x4C(r31)
	  lwz       r3, 0x224(r3)
	  addi      r29, r3, 0x220
	  bl        0xBDA2C
	  lfs       f2, 0x0(r29)
	  li        r4, 0x1
	  lfs       f0, 0x9C(r30)
	  fmuls     f1, f2, f1
	  fadds     f0, f0, f1
	  stfs      f0, 0x16C(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x164(r1)
	  lfs       f2, 0x16C(r1)
	  bl        -0xF63E0
	  stfs      f1, 0x168(r1)
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0x164(r1)
	  lwz       r0, 0x168(r1)
	  stw       r3, 0x300(r4)
	  stw       r0, 0x304(r4)
	  lwz       r0, 0x16C(r1)
	  stw       r0, 0x308(r4)
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0x164(r1)
	  lwz       r0, 0x168(r1)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r0, 0x16C(r1)
	  stw       r0, 0x9C(r4)
	  b         .loc_0x4B0

	.loc_0x23C:
	  lfs       f0, -0x5590(r2)
	  stfs      f0, 0xB4(r1)
	  stfs      f0, 0xB0(r1)
	  stfs      f0, 0xAC(r1)
	  lwz       r3, 0x318(r4)
	  lfsu      f31, 0x94(r3)
	  lfs       f1, 0x3C0(r4)
	  lfs       f30, 0x4(r3)
	  lfs       f29, 0x8(r3)
	  bl        0xBD808
	  lwz       r3, 0x4C(r31)
	  fmr       f26, f1
	  lfs       f1, 0x3C0(r3)
	  bl        0xBD98C
	  stfs      f1, 0xC4(r1)
	  lfs       f0, -0x70(r13)
	  stfs      f0, 0xC8(r1)
	  stfs      f26, 0xCC(r1)
	  lwz       r3, 0x4C(r31)
	  lwz       r3, 0x224(r3)
	  addi      r3, r3, 0x224
	  bl        .loc_0x5C8
	  addi      r5, r3, 0
	  addi      r3, r1, 0x104
	  addi      r4, r1, 0xC4
	  bl        -0xBEEB8
	  lwz       r3, 0x4C(r31)
	  addi      r6, r1, 0x78
	  lfs       f0, 0x10C(r1)
	  addi      r5, r1, 0x74
	  lfs       f2, 0x3D8(r3)
	  addi      r7, r3, 0x3D0
	  lfs       f1, 0x108(r1)
	  fadds     f2, f2, f0
	  lfs       f0, 0x104(r1)
	  addi      r4, r1, 0x70
	  addi      r3, r1, 0xF8
	  stfs      f2, 0x78(r1)
	  lfs       f2, 0x4(r7)
	  fadds     f1, f2, f1
	  stfs      f1, 0x74(r1)
	  lfs       f1, 0x0(r7)
	  fadds     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  bl        -0x1272BC
	  lwz       r3, 0x4C(r31)
	  lfs       f28, 0xF8(r1)
	  lwz       r3, 0x224(r3)
	  lfs       f27, 0xFC(r1)
	  lfs       f26, 0x100(r1)
	  addi      r3, r3, 0x224
	  bl        .loc_0x5C8
	  addi      r5, r3, 0
	  addi      r3, r1, 0x11C
	  addi      r4, r1, 0xC4
	  bl        -0xBEF30
	  lwz       r3, 0x4C(r31)
	  addi      r6, r1, 0x6C
	  lfs       f0, 0x124(r1)
	  addi      r5, r1, 0x68
	  lfs       f2, 0x3D8(r3)
	  addi      r7, r3, 0x3D0
	  lfs       f1, 0x120(r1)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x11C(r1)
	  addi      r4, r1, 0x64
	  addi      r3, r1, 0x110
	  stfs      f2, 0x6C(r1)
	  lfs       f2, 0x4(r7)
	  fsubs     f1, f2, f1
	  stfs      f1, 0x68(r1)
	  lfs       f1, 0x0(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x64(r1)
	  bl        -0x127334
	  lfs       f22, 0x110(r1)
	  addi      r6, r1, 0x60
	  lfs       f25, 0x114(r1)
	  addi      r5, r1, 0x5C
	  lfs       f24, 0x118(r1)
	  fsubs     f1, f25, f27
	  addi      r4, r1, 0x58
	  fsubs     f2, f24, f26
	  addi      r3, r1, 0x128
	  fsubs     f0, f22, f28
	  stfs      f2, 0x60(r1)
	  stfs      f1, 0x5C(r1)
	  stfs      f0, 0x58(r1)
	  bl        -0x12736C
	  stfs      f22, 0x14C(r1)
	  addi      r5, r1, 0x14C
	  lfs       f23, 0x128(r1)
	  addi      r4, r1, 0x140
	  stfs      f31, 0x134(r1)
	  lfs       f22, 0x12C(r1)
	  addi      r3, r1, 0x134
	  stfs      f28, 0x140(r1)
	  addi      r6, r1, 0xF4
	  lfs       f31, 0x130(r1)
	  stfs      f25, 0x150(r1)
	  stfs      f27, 0x144(r1)
	  stfs      f30, 0x138(r1)
	  stfs      f24, 0x154(r1)
	  stfs      f26, 0x148(r1)
	  stfs      f29, 0x13C(r1)
	  bl        0x3D454
	  lfs       f0, 0xF4(r1)
	  lfs       f3, -0x5590(r2)
	  fcmpo     cr0, f0, f3
	  bge-      .loc_0x3F8
	  b         .loc_0x40C

	.loc_0x3F8:
	  lfs       f3, -0x558C(r2)
	  fcmpo     cr0, f0, f3
	  ble-      .loc_0x408
	  b         .loc_0x40C

	.loc_0x408:
	  fmr       f3, f0

	.loc_0x40C:
	  fmuls     f2, f31, f3
	  stfs      f3, 0xF4(r1)
	  fmuls     f1, f22, f3
	  addi      r6, r1, 0x54
	  fmuls     f0, f23, f3
	  stfs      f2, 0x54(r1)
	  addi      r5, r1, 0x50
	  addi      r4, r1, 0x4C
	  stfs      f1, 0x50(r1)
	  addi      r3, r1, 0x158
	  stfs      f0, 0x4C(r1)
	  bl        -0x127408
	  lfs       f1, 0x158(r1)
	  li        r4, 0x1
	  lfs       f0, 0x15C(r1)
	  fadds     f1, f28, f1
	  fadds     f0, f27, f0
	  stfs      f1, 0xAC(r1)
	  stfs      f0, 0xB0(r1)
	  lfs       f0, 0x160(r1)
	  fadds     f0, f26, f0
	  stfs      f0, 0xB4(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0xAC(r1)
	  lfs       f2, 0xB4(r1)
	  bl        -0xF6658
	  stfs      f1, 0xB0(r1)
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r3, 0x300(r4)
	  stw       r0, 0x304(r4)
	  lwz       r0, 0xB4(r1)
	  stw       r0, 0x308(r4)
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r0, 0xB4(r1)
	  stw       r0, 0x9C(r4)

	.loc_0x4B0:
	  lwz       r3, 0x4C(r31)
	  bl        -0x10008
	  lwz       r3, 0x4C(r31)
	  lfs       f1, -0x556C(r2)
	  bl        -0x101FC
	  lwz       r3, 0x4C(r31)
	  bl        -0xD42E8
	  lwz       r3, 0x4C(r31)
	  li        r0, 0x1
	  li        r4, 0x7E
	  stb       r0, 0x2B8(r3)
	  li        r6, 0
	  li        r7, 0
	  lwz       r3, 0x4C(r31)
	  stb       r0, 0x2B9(r3)
	  lwz       r3, 0x4C(r31)
	  stb       r0, 0x2BE(r3)
	  lfs       f0, -0x558C(r2)
	  lwz       r3, 0x4C(r31)
	  stfs      f0, 0x3C4(r3)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x3180(r13)
	  addi      r5, r5, 0x94
	  bl        0x3E540
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x7F
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3E524
	  lwz       r3, 0x4C(r31)
	  lwz       r3, 0x3CC(r3)
	  bl        0x1688
	  lwz       r6, 0x4C(r31)
	  li        r4, 0xB
	  lwz       r3, 0x3178(r13)
	  li        r5, 0
	  addi      r6, r6, 0x94
	  bl        0x1E79C
	  lwz       r5, 0x4C(r31)
	  li        r4, 0x4
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r5, 0x94
	  bl        -0x3A674
	  lwz       r3, 0x4C(r31)
	  bl        -0xF294
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x584
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x30
	  addi      r3, r3, 0x70
	  bl        -0xDAC6C

	.loc_0x584:
	  lwz       r0, 0x20C(r1)
	  lfd       f31, 0x200(r1)
	  lfd       f30, 0x1F8(r1)
	  lfd       f29, 0x1F0(r1)
	  lfd       f28, 0x1E8(r1)
	  lfd       f27, 0x1E0(r1)
	  lfd       f26, 0x1D8(r1)
	  lfd       f25, 0x1D0(r1)
	  lfd       f24, 0x1C8(r1)
	  lfd       f23, 0x1C0(r1)
	  lfd       f22, 0x1B8(r1)
	  lwz       r31, 0x1B4(r1)
	  lwz       r30, 0x1B0(r1)
	  lwz       r29, 0x1AC(r1)
	  addi      r1, r1, 0x208
	  mtlr      r0
	  blr

	.loc_0x5C8:
	*/
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000128
 */
void SnakeAi::dieState()
{
	if (mSnake->getMotionFinish()) {
		mSnake->setIsAlive(false);
		mSnake->setIsAtari(false);
		mSnake->setShadowNeed(false);

		if (mSnake->mSnakeBody->mSegmentScaleList[0] == 0.0f) {
			Vector3f pos(mSnake->mSRT.t);
			pos.y = mapMgr->getMinY(pos.x, pos.z, true);
			mSnake->setMotionFinish(false);
			effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeM, pos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Teki_DeathGlowM, pos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Teki_DeathWaveM, pos, nullptr, nullptr);

			mSnake->createPellet(pos, 300.0f, true);
			GameStat::killTekis.inc();

			mSnake->doKill();
		}
	}
}

/**
 * @todo: Documentation
 */
void SnakeAi::struggleState()
{
	if (mSnake->getLoopCounter() < C_SNAKE_PROP(mSnake).mStruggleLoopMax()) {
		int stickPikiNum = mSnake->getStickNoMouthPikiCount();
		int loopLimit    = 0;
		if (stickPikiNum >= C_SNAKE_PROP(mSnake).mStrugglePikiMax()) {
			loopLimit = C_SNAKE_PROP(mSnake).mStruggleLoopMax();
		} else if (stickPikiNum > C_SNAKE_PROP(mSnake).mStrugglePikiMin()) {
			f32 lVals[3];
			lVals[0] = 0.0f;
			lVals[1] = C_SNAKE_PROP(mSnake).mStruggleLoopMid();
			lVals[2] = C_SNAKE_PROP(mSnake).mStruggleLoopMax();
			f32 val  = 2.0f
			        * (f32(stickPikiNum - C_SNAKE_PROP(mSnake).mStrugglePikiMin())
			           / f32(C_SNAKE_PROP(mSnake).mStrugglePikiMax() - C_SNAKE_PROP(mSnake).mStrugglePikiMin()));
			loopLimit = NsLibMath<f32>::lagrange3(lVals, val) + 0.5f;
			loopLimit = NsLibMath<int>::revice(loopLimit, 0, C_SNAKE_PROP(mSnake).mStruggleLoopMax());
		}

		if (mSnake->getLoopCounter() >= loopLimit) {
			mSnake->setLoopCounter(C_SNAKE_PROP(mSnake).mStruggleLoopMax());
			mSnake->mAnimator.finishMotion(PaniMotionInfo(PANI_NO_MOTION, this));
		}
	} else {
		mSnake->mAnimator.finishMotion(PaniMotionInfo(PANI_NO_MOTION, this));
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void SnakeAi::chaseState()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void SnakeAi::attackState()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void SnakeAi::eatState()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000074
 */
void SnakeAi::waitState()
{
	if (mSnake->getStickNoMouthPikiCount() > 0) {
		mSnake->addWalkTimer(gsys->getFrameTime() * 5.0f);
	} else {
		mSnake->addWalkTimer(gsys->getFrameTime());
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void SnakeAi::gointoState()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00001C
 */
void SnakeAi::underState()
{
	mSnake->addWalkTimer(gsys->getFrameTime());
}

/**
 * @todo: Documentation
 */
void SnakeAi::update()
{
	setEveryFrame();
	switch (mSnake->getCurrentState()) {
	case SNAKEAI_Die:
	{
		dieState();
		break;
	}
	case SNAKEAI_Struggle:
	{
		struggleState();
		if (dieTransit()) {
			initDie(SNAKEAI_Die);
		} else if (intoGroundTransit()) {
			initGointo(SNAKEAI_GoInto);
		} else if (mSnake->getMotionFinish()) {
			if (attackTransit(5)) {
				initAttack(SNAKEAI_Attack, 0.0f);
			} else {
				initWait(SNAKEAI_Wait);
			}
		}
		break;
	}
	case SNAKEAI_ChaseNavi:
	{
		chaseState();
		if (dieTransit()) {
			initDie(SNAKEAI_Die);
		} else if (intoGroundTransit()) {
			initGointo(SNAKEAI_GoInto);
		} else if (attackTransit(5)) {
			if (struggleTransit()) {
				initStruggle(SNAKEAI_Struggle);
			} else {
				initAttack(SNAKEAI_Attack, 0.0f);
			}
		} else if (chasePikiTransit()) {
			initChase(SNAKEAI_ChasePiki);
		} else if (chaseNaviTransit()) {
			initChase(SNAKEAI_ChaseNavi);
		} else if (targetLostTransit()) {
			initWait(SNAKEAI_Wait);
		}
		break;
	}
	case SNAKEAI_ChasePiki:
	{
		chaseState();
		if (dieTransit()) {
			initDie(SNAKEAI_Die);
		} else if (intoGroundTransit()) {
			initGointo(SNAKEAI_GoInto);
		} else if (attackTransit(5)) {
			if (struggleTransit()) {
				initStruggle(SNAKEAI_Struggle);
			} else {
				initAttack(SNAKEAI_Attack, 0.0f);
			}
		} else if (chasePikiTransit()) {
			initChase(SNAKEAI_ChasePiki);
		} else if (chaseNaviTransit()) {
			initChase(SNAKEAI_ChaseNavi);
		} else if (targetLostTransit()) {
			initWait(SNAKEAI_Wait);
		}
		break;
	}
	case SNAKEAI_Attack:
	{
		attackState();
		if (dieTransit()) {
			initDie(SNAKEAI_Die);
		} else if (intoGroundTransit()) {
			initGointo(SNAKEAI_GoInto);
		} else if (mSnake->getMotionFinish()) {
			initWait(SNAKEAI_Wait);
		}
		break;
	}
	case SNAKEAI_Eat:
	{
		eatState();
		if (dieTransit()) {
			initDie(SNAKEAI_Die);
		} else if (intoGroundTransit()) {
			initGointo(SNAKEAI_GoInto);
		} else if (mSnake->getMotionFinish()) {
			initWait(SNAKEAI_Wait);
		}
		break;
	}
	case SNAKEAI_Wait:
	{
		waitState();
		if (dieTransit()) {
			initDie(SNAKEAI_Die);
		} else if (intoGroundTransit()) {
			initGointo(SNAKEAI_GoInto);
		} else if (eatPikiTransit()) {
			initEat(SNAKEAI_Eat);
		} else if (diveTimerTransit()) {
			initGointo(SNAKEAI_GoInto);
		} else if (chasePikiTransit()) {
			initChase(SNAKEAI_ChasePiki);
		} else if (chaseNaviTransit()) {
			initChase(SNAKEAI_ChaseNavi);
		}
		break;
	}
	case SNAKEAI_GoInto:
	{
		gointoState();
		if (dieTransit()) {
			initDie(SNAKEAI_Die);
		} else if (mSnake->getMotionFinish()) {
			initUnder(SNAKEAI_Under);
		}
		break;
	}
	case SNAKEAI_Under:
	{
		underState();
		if (underTimerTransit() && appearTransit()) {
			initAppear(SNAKEAI_Appear);
		}
		break;
	}
	case SNAKEAI_Appear:
	{
		if (dieTransit()) {
			initDie(SNAKEAI_Die);
		} else if (mSnake->getMotionFinish()) {
			initWait(SNAKEAI_Wait);
		}
		break;
	}
	}
}
