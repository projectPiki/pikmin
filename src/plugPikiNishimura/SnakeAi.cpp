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
