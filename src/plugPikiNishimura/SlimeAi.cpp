#include "CoreNucleus.h"
#include "DebugLog.h"
#include "EffectMgr.h"
#include "Interactions.h"
#include "NaviMgr.h"
#include "NsMath.h"
#include "Nucleus.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "Slime.h"
#include "SoundMgr.h"

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
DEFINE_PRINT(nullptr);

SlimeAi::SlimeAi(Slime* slime)
{
	mSlime = slime;
}

void SlimeAi::init(Slime* slime)
{
	mSlime = slime;
	mSlime->setCurrentState(SLIMEAI_Stay);
	mSlime->setNextState(SLIMEAI_Stay);
	mSlime->mAnimator.startMotion(PaniMotionInfo(TekiMotion::Dead));
	mIsContractFinished        = false;
	mCanPlayExpandSound        = true;
	mPrevNucleusStickPikiCount = 0;
	mBubbleCheckIndex          = 0;
	mContractHitType           = SLIMEHIT_NoHit;
	mContractDamage            = 0.0f;
	mStickersRatio             = 0.0f;
	mMaxLength                 = C_SLIME_PROP(mSlime).mNormalMaxLength();
	mMinLength                 = C_SLIME_PROP(mSlime).mNormalMinLength();
}

void SlimeAi::addDamagePoint(f32 damage)
{
	mSlime->addDamagePoint(damage);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void SlimeAi::setEveryFrame()
{
	calcBubblePiki();
	calcStickersRatio();
	setLeaderIndex();
	calcCollisionCheck();
	makeInterrelation();
	makeBodyThickness();
	playExpandingSound();
	if (mSlime->getDamagePoint() > 0.0f) {
		mSlime->calcBossDamage();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void SlimeAi::afterProcessing()
{
	mPrevNucleusStickPikiCount = mSlime->mNucleus->mNucleusAi->mStickPikiCount;
}

void SlimeAi::calcBubblePiki()
{
	CollPart* part = nullptr;
	switch (mBubbleCheckIndex) {
	case 0:
		part = mSlime->mCollInfo->getSphere('stk1');
		break;

	case 1:
		part = mSlime->mCollInfo->getSphere('stk2');
		break;

	case 2:
		part = mSlime->mCollInfo->getSphere('stk3');
		break;

	default:
		part = mSlime->mCollInfo->getSphere('stk4');
		break;
	}

	if (part) {
		Iterator iter(pikiMgr);
		CI_LOOP(iter)
		{
			Creature* p = *iter;
			if (p && p->isAlive() && p->isVisible() && !p->isBuried()) {
				Piki* piki = static_cast<Piki*>(p);
				if (piki->mColor != Blue && qdist2(piki->mSRT.t.x, piki->mSRT.t.z, part->mCentre.x, part->mCentre.z) < part->mRadius) {
					// we're close, so do an actual distance calculation
					f32 dist = piki->mSRT.t.distance(part->mCentre);
					if (dist < part->mRadius) {
						InteractBubble bubble(mSlime, 200.0f);
						piki->stimulate(bubble);
					}
				}
			}
		}
	}

	mBubbleCheckIndex++;
	if (mBubbleCheckIndex > 3) {
		mBubbleCheckIndex = 0;
	}
}

void SlimeAi::calcStickersRatio()
{
	mStickersRatio = 0.0f;
	if (mSlime->mNucleus->mNucleusAi->mStickPikiCount > 0) {
		mStickersRatio += mSlime->mNucleus->mNucleusAi->mStickPikiCount / C_SLIME_PROP(mSlime).mMaxStickPikiNum();
		if (mStickersRatio > 1.0f) {
			mStickersRatio = 1.0f;
		}
	}

	f32 complRatio = 1.0f - mStickersRatio;
	mMaxLength     = complRatio * C_SLIME_PROP(mSlime).mNormalMaxLength() + mStickersRatio * C_SLIME_PROP(mSlime).mMaxLengthAtSticking();
	mMinLength     = complRatio * C_SLIME_PROP(mSlime).mNormalMinLength() + mStickersRatio * C_SLIME_PROP(mSlime).mMinLengthAtSticking();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void SlimeAi::setLeaderIndex()
{
	// if we now have stick pikis on the nucleus, change to make the core the leader
	// (to set up the player to smack the nuclei together easier)
	if (mPrevNucleusStickPikiCount == 0 && mSlime->mNucleus->mNucleusAi->mStickPikiCount > 0) {
		if (mSlime->mLeaderCreatureIndex == SLIMECREATURE_NucleusOuter) {
			mSlime->mLeaderCreatureIndex   = SLIMECREATURE_CoreOuter;
			mSlime->mFollowerCreatureIndex = SLIMECREATURE_NucleusOuter;
		}
		mSlime->mIsMoveLeader = true;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000194
 */
void SlimeAi::makeInterrelation()
{
	mSlime->mSlimeCreatures[SLIMECREATURE_CoreInner]->mTargetPosition
	    = 0.6667f * mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mSRT.t
	    + 0.3333f * mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mSRT.t;
	mSlime->mSlimeCreatures[SLIMECREATURE_NucleusInner]->mTargetPosition
	    = 0.3333f * mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mSRT.t
	    + 0.6667f * mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mSRT.t;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000104
 */
void SlimeAi::makeBodyThickness()
{
	f32 dist
	    = mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mSRT.t.distance(mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mSRT.t);
	f32 elongation = (dist - C_SLIME_PROP(mSlime).mNormalMinLength())
	               / (C_SLIME_PROP(mSlime).mMaxLengthAtSticking() - C_SLIME_PROP(mSlime).mNormalMinLength());
	f32 elongateRatio      = NsLibMath<f32>::revice(elongation, 0.0f, 1.0f);
	mSlime->mBodyThickness = C_SLIME_PROP(mSlime).mBodyThicknessElongate() * elongateRatio
	                       + C_SLIME_PROP(mSlime).mBodyThicknessContract() * (1.0f - elongateRatio);
}

void SlimeAi::playExpandingSound()
{
	f32 expansionRatio
	    = mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mSRT.t.distance(mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mSRT.t)
	    / mMaxLength;
	if (mSlime->mIsMoveLeader && mCanPlayExpandSound && expansionRatio > 0.8f) {
		if (mStickersRatio > 0.5f) {
			if (mSlime->mSeContext) {
				// very strained stretch
				mSlime->mSeContext->playSound(SE_SLIME_EXT3);
			}
		} else if (mStickersRatio > 0.0f) {
			if (mSlime->mSeContext) {
				// somewhat strained stretch
				mSlime->mSeContext->playSound(SE_SLIME_EXT2);
			}
		} else if (mSlime->mSeContext) {
			// normal stretch
			mSlime->mSeContext->playSound(SE_SLIME_EXT1);
		}

		mCanPlayExpandSound = false;
	}

	if (!mCanPlayExpandSound && expansionRatio < 0.7f) {
		mCanPlayExpandSound = true;
	}
}

void SlimeAi::calcCollisionCheck()
{
	mSlime->mCorePosition
	    = 0.5f * mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mSRT.t + 0.5f * mSlime->mSlimeCreatures[SLIMECREATURE_CoreInner]->mSRT.t;
	mSlime->mNucleusPosition = 0.5f * mSlime->mSlimeCreatures[SLIMECREATURE_NucleusInner]->mSRT.t
	                         + 0.5f * mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mSRT.t;

	if (mSlime->getCurrentState() == SLIMEAI_Appear) {
		return;
	}

	f32 dist = mSlime->mNucleus->mSRT.t.distance(mSlime->mCore->mSRT.t);

	// force distance between nuclei to be mDistanceBetweenNuclei
	if (dist < C_SLIME_PROP(mSlime).mDistanceBetweenNuclei()) {
		Vector3f sep = mSlime->mCore->mSRT.t - mSlime->mNucleus->mSRT.t;
		dist         = (C_SLIME_PROP(mSlime).mDistanceBetweenNuclei() - dist) / 2.0f;
		sep.normalise();
		sep.multiply(dist);
		mSlime->mCorePosition.add(sep);
		mSlime->mNucleusPosition.sub(sep);
		if (mSlime->getCurrentState() == SLIMEAI_Contract) {
			inCaseOfContract();
		}
	}
}

void SlimeAi::setLeaderNearerTarget()
{
	Slime* slime = mSlime;
	// only adjust leader if there aren't any stick pikis - core is always leader if there are stick pikis
	if (slime->mNucleus->mNucleusAi->mStickPikiCount == 0) {
		SlimeCreature* leader   = slime->mSlimeCreatures[slime->mLeaderCreatureIndex];
		SlimeCreature* follower = slime->mSlimeCreatures[slime->mFollowerCreatureIndex];
		Vector3f* targetPos     = slime->getTargetPosition();
		f32 followDist          = qdist2(follower->mSRT.t.x, follower->mSRT.t.z, targetPos->x, targetPos->z);
		f32 leadDist
		    = qdist2(leader->mSRT.t.x, leader->mSRT.t.z, targetPos->x, targetPos->z) - C_SLIME_PROP(slime).mDistanceBetweenNuclei();

		// if difference between leader-target dist and follower-target dist gets bigger than dist between nuclei, flip
		if (leadDist > followDist) {
			int prevLeader                 = mSlime->mLeaderCreatureIndex;
			mSlime->mLeaderCreatureIndex   = mSlime->mFollowerCreatureIndex;
			mSlime->mFollowerCreatureIndex = prevLeader;
			mSlime->mIsMoveLeader          = true;
		}
	}

	STACK_PAD_VAR(2); // this whole function is questionable.
}

void SlimeAi::moveFlagCheck()
{
	f32 dist = mSlime->mSlimeCreatures[mSlime->mLeaderCreatureIndex]->mSRT.t.distance(
	    mSlime->mSlimeCreatures[mSlime->mFollowerCreatureIndex]->mSRT.t);
	if (dist > mMaxLength) {
		if (mSlime->mIsMoveLeader) {
			mSlime->mIsMoveLeader = false;
			mSlime->setAnimTimer(0.0f);
		}
	} else if (dist < mMinLength && !mSlime->mIsMoveLeader) {
		mSlime->mIsMoveLeader = true;
		mSlime->setAnimTimer(0.0f);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void SlimeAi::makeTargetPosition()
{
	SlimeCreature* leader     = mSlime->mSlimeCreatures[mSlime->mLeaderCreatureIndex];
	SlimeCreature* follower   = mSlime->mSlimeCreatures[mSlime->mFollowerCreatureIndex];
	leader->mTargetPosition   = *mSlime->getTargetPosition();
	follower->mTargetPosition = leader->mSRT.t;
	mSlime->addAnimTimer(gsys->getFrameTime());
}

void SlimeAi::makeFollowerVelocity()
{
	SlimeCreature* follower = mSlime->mSlimeCreatures[mSlime->mFollowerCreatureIndex];
	if (!mSlime->mIsMoveLeader) {
		follower->mTargetVelocity.sub(follower->mTargetPosition, follower->mSRT.t);
		follower->mTargetVelocity.y = 0.0f;
		follower->mTargetVelocity.normalise();
		f32 complRatio = 1.0f - mStickersRatio;
		follower->mTargetVelocity.multiply(C_SLIME_PROP(mSlime).mMaxMoveSpeed() * complRatio
		                                   + C_SLIME_PROP(mSlime).mMinMoveSpeed() * mStickersRatio);
	} else {
		follower->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}
}

void SlimeAi::makeLeaderVelocity()
{
	SlimeCreature* leader   = mSlime->mSlimeCreatures[mSlime->mLeaderCreatureIndex];
	SlimeCreature* follower = mSlime->mSlimeCreatures[mSlime->mFollowerCreatureIndex];
	if (mSlime->mIsMoveLeader) {
		leader->mTargetVelocity.sub(leader->mTargetPosition, leader->mSRT.t);
		leader->mTargetVelocity.y = 0.0f;
		leader->mTargetVelocity.normalise();
		leader->mTargetVelocity.multiply(mSlime->mLeaderSpeed);
	} else {
		leader->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}
}

void SlimeAi::setMidPointVelocity()
{
	// ... this is just "do for 1 and 2" but okay
	for (int i = 1; i < bossMgr->mSlimeCreatureCount - 1; i++) {
		mSlime->mSlimeCreatures[i]->mVelocity.multiply(C_SLIME_PROP(mSlime).mTraceMidPoint());

		Vector3f displacement = mSlime->mSlimeCreatures[i]->mTargetPosition - mSlime->mSlimeCreatures[i]->mSRT.t;
		displacement.y        = 0.0f;
		displacement.multiply(C_SLIME_PROP(mSlime).mMidPointSpring());
		mSlime->mSlimeCreatures[i]->mVelocity.add(displacement);
		mSlime->mSlimeCreatures[i]->mTargetVelocity = mSlime->mSlimeCreatures[i]->mVelocity;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000584
 */
void SlimeAi::walkAllState()
{
	setLeaderNearerTarget();
	moveFlagCheck();
	makeTargetPosition();
	makeFollowerVelocity();
	makeLeaderVelocity();
	setMidPointVelocity();
}

void SlimeAi::calcContractDamage()
{
	f32 nucleiDist = mSlime->mCore->mSRT.t.distance(mSlime->mNucleus->mSRT.t);
	if (nucleiDist > C_SLIME_PROP(mSlime).mDamageLengthLarge()) {
		mContractDamage  = nucleiDist * C_SLIME_PROP(mSlime).mDamageRatioLarge();
		mContractHitType = SLIMEHIT_Large;
		return;
	}

	if (nucleiDist > C_SLIME_PROP(mSlime).mDamageLengthMid()) {
		mContractDamage  = nucleiDist * C_SLIME_PROP(mSlime).mDamageRatioMid();
		mContractHitType = SLIMEHIT_Mid;
		return;
	}

	mContractDamage  = nucleiDist * C_SLIME_PROP(mSlime).mDamageRatioSmall();
	mContractHitType = SLIMEHIT_Small;
}

void SlimeAi::contractCoreFlickPiki()
{
	CollPart* corePart = mSlime->mCore->mCollInfo->getBoundingSphere();
	f32 coreRadius     = corePart->mRadius + 30.0f;
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki && piki->isAlive() && piki->isVisible() && !piki->isBuried()
		    && qdist2(piki->mSRT.t.x, piki->mSRT.t.z, corePart->mCentre.x, corePart->mCentre.z) < coreRadius) {
			// close enough, do a proper check
			if (piki->mSRT.t.distance(corePart->mCentre) < coreRadius) {
				InteractFlick flick(mSlime->mCore, C_BOSS_PROP(mSlime->mCore).mFlickKnockback(), C_BOSS_PROP(mSlime->mCore).mFlickDamage(),
				                    FLICK_BACKWARDS_ANGLE);
				piki->stimulate(flick);
			}
		}
	}
}

void SlimeAi::contractSubFlickPiki()
{
	CollPart* nucleusPart = mSlime->mNucleus->mCollInfo->getBoundingSphere();
	f32 nucleusRadius     = nucleusPart->mRadius + 30.0f;
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki && piki->isAlive() && piki->isVisible() && !piki->isBuried()
		    && qdist2(piki->mSRT.t.x, piki->mSRT.t.z, nucleusPart->mCentre.x, nucleusPart->mCentre.z) < nucleusRadius) {
			// close enough, do a proper check
			if (piki->mSRT.t.distance(nucleusPart->mCentre) < nucleusRadius) {
				InteractFlick flick(mSlime->mNucleus, C_BOSS_PROP(mSlime->mNucleus).mFlickKnockback(),
				                    C_BOSS_PROP(mSlime->mNucleus).mFlickDamage(), FLICK_BACKWARDS_ANGLE);
				piki->stimulate(flick);
			}
		}
	}
}

void SlimeAi::inCaseOfContract()
{
	// in case of contract, pull this lever
	if (mIsContractFinished) {
		return;
	}

	mIsContractFinished = true;
	contractSubFlickPiki();

	Vector3f midPoint = 0.5f * (mSlime->mCorePosition + mSlime->mNucleusPosition);
	midPoint.y += 15.0f;

	if (mContractHitType == SLIMEHIT_Small) {
		effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeS, midPoint, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathGlowS, midPoint, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathWaveS, midPoint, nullptr, nullptr);
		rumbleMgr->start(RUMBLE_Unk15, 0, midPoint);
		if (mSlime->mSeContext) {
			mSlime->mSeContext->playSound(SE_SLIME_HIT_SMALL);
		}

	} else if (mContractHitType == SLIMEHIT_Mid) {
		effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeM, midPoint, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathGlowM, midPoint, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathWaveM, midPoint, nullptr, nullptr);
		rumbleMgr->start(RUMBLE_Unk10, 0, midPoint);
		if (mSlime->mSeContext) {
			mSlime->mSeContext->playSound(SE_SLIME_HIT_MID);
		}

	} else if (mContractHitType == SLIMEHIT_Large) {
		effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeL, midPoint, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathGlowL, midPoint, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathWaveL, midPoint, nullptr, nullptr);
		rumbleMgr->start(RUMBLE_Unk14, 0, midPoint);
		if (mSlime->mSeContext) {
			mSlime->mSeContext->playSound(SE_SLIME_HIT_LARGE);
		}
	}

	mSlime->addDamagePoint(mContractDamage);
	mContractDamage  = 0.0f;
	mContractHitType = SLIMEHIT_NoHit;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000120
 */
void SlimeAi::setDieGoal()
{
	// collapse edges into the centre
	Vector3f midPoint
	    = 0.5f * (mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mSRT.t + mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mSRT.t);
	mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mTargetPosition    = midPoint;
	mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mTargetPosition = midPoint;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000204
 */
void SlimeAi::setContractGoal()
{
	f32 goalDistFromMiddle = 5.0f + C_SLIME_PROP(mSlime).mDistanceBetweenNuclei() / 2.0f;
	Vector3f midPoint
	    = 0.5f * (mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mSRT.t + mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mSRT.t);
	Vector3f offsetFromMid = mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mSRT.t - midPoint;
	offsetFromMid.normalise();
	offsetFromMid.multiply(goalDistFromMiddle);
	mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mTargetPosition    = midPoint + offsetFromMid;
	mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mTargetPosition = midPoint - offsetFromMid;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000204
 */
void SlimeAi::setExpansionGoal()
{
	f32 goalDistFromMiddle = 15.0f + C_SLIME_PROP(mSlime).mDistanceBetweenNuclei() / 2.0f;
	Vector3f midPoint      = 0.5f
	                  * (mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mTargetPosition
	                     + mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mTargetPosition);
	Vector3f offsetFromMid = mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mTargetPosition - midPoint;
	offsetFromMid.normalise();
	offsetFromMid.multiply(goalDistFromMiddle);
	mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mTargetPosition    = midPoint + offsetFromMid;
	mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mTargetPosition = midPoint - offsetFromMid;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
void SlimeAi::setAppearGoal()
{
	Navi* navi     = naviMgr->getNavi();
	f32 angle      = atan2f(navi->mSRT.t.x - mSlime->mSRT.t.x, navi->mSRT.t.z - mSlime->mSRT.t.z);
	f32 initialSep = C_SLIME_PROP(mSlime).mDistanceBetweenNuclei() + 100.0f;
	Vector3f naviDir(sinf(angle), 0.0f, cosf(angle));
	mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mTargetPosition = *mSlime->getInitPosition() + initialSep * naviDir;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000154
 */
void SlimeAi::bothEndsToGoal()
{
	Vector3f velOffset;
	mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mVelocity.multiply(C_SLIME_PROP(mSlime).mContractTraceEnd());

	velOffset
	    = mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mTargetPosition - mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mSRT.t;
	velOffset.multiply(C_SLIME_PROP(mSlime).mContractSpringEnd());
	mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mVelocity.add(velOffset);

	mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mVelocity.multiply(C_SLIME_PROP(mSlime).mContractTraceEnd());

	velOffset = mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mTargetPosition
	          - mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mSRT.t;
	velOffset.multiply(C_SLIME_PROP(mSlime).mContractSpringEnd());
	mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mVelocity.add(velOffset);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void SlimeAi::bothEndsToAppearGoal()
{
	Vector3f coreVel;
	coreVel = mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mTargetPosition - mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mSRT.t;
	coreVel.multiply(0.5f);
	mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mTargetVelocity = coreVel;
	mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mVelocity       = coreVel;
}

void SlimeAi::makeTargetRandom()
{
	mSlime->addWalkTimer(gsys->getFrameTime());
	SlimeCreature* leader = mSlime->mSlimeCreatures[mSlime->mLeaderCreatureIndex];
	Vector3f* targetPos   = mSlime->getTargetPosition();
	Vector3f* initPos     = mSlime->getInitPosition();

	if (mSlime->getWalkTimer() > 10.0f || qdist2(targetPos->x, targetPos->z, leader->mSRT.t.x, leader->mSRT.t.z) < 10.0f) {
		f32 randAngle = NsMathF::getRand(TAU);
		Vector3f newTarget;
		newTarget.set(C_BOSS_PROP(mSlime).mMaxWaitRadius() * cosf(randAngle) + initPos->x, initPos->y,
		              C_BOSS_PROP(mSlime).mMaxWaitRadius() * sinf(randAngle) + initPos->z);
		mSlime->setTargetPosition(newTarget);
		mSlime->setWalkTimer(0.0f);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void SlimeAi::setVelocity(f32 speed)
{
	mSlime->mLeaderSpeed = speed;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
bool SlimeAi::motionFinishTransit()
{
	return mSlime->getMotionFinish();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool SlimeAi::dieTransit()
{
	return !mSlime->getAlive();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
bool SlimeAi::outSideChaseRangeTransit()
{
	SlimeCreature* leader = mSlime->mSlimeCreatures[mSlime->mLeaderCreatureIndex];
	Vector3f* initPos     = mSlime->getInitPosition();
	if (qdist2(leader->mSRT.t.x, leader->mSRT.t.z, initPos->x, initPos->z) > C_BOSS_PROP(mSlime).mTerritoryRadius()) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
bool SlimeAi::inSideWaitRangeTransit()
{
	SlimeCreature* follower = mSlime->mSlimeCreatures[mSlime->mFollowerCreatureIndex];
	Vector3f* initPos       = mSlime->getInitPosition();
	if (qdist2(follower->mSRT.t.x, follower->mSRT.t.z, initPos->x, initPos->z) < C_BOSS_PROP(mSlime).mMaxWaitRadius()) {
		return true;
	}
	return false;
}

bool SlimeAi::chaseNaviTransit()
{
	Creature* target      = nullptr;
	SlimeCreature* leader = mSlime->mSlimeCreatures[mSlime->mLeaderCreatureIndex];
	Vector3f* initPos     = mSlime->getInitPosition();
	f32 minDist           = 12800.0f;

	if (mSlime->getTargetCreature()) {
		minDist = leader->mSRT.t.distance(mSlime->getTargetCreature()->mSRT.t);
	}

	Iterator iter(naviMgr);
	CI_LOOP(iter)
	{
		Creature* navi = *iter;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()
		    && qdist2(navi->mSRT.t.x, navi->mSRT.t.z, initPos->x, initPos->z) < C_BOSS_PROP(mSlime).mTerritoryRadius()) {
			f32 quickLeaderDist = qdist2(leader->mSRT.t.x, leader->mSRT.t.z, navi->mSRT.t.x, navi->mSRT.t.z);
			if (quickLeaderDist < C_BOSS_PROP(mSlime).mSearchRadius() && quickLeaderDist < minDist) {
				f32 leaderDist = leader->mSRT.t.distance(navi->mSRT.t);
				if (leaderDist < C_BOSS_PROP(mSlime).mSearchRadius() && leaderDist < minDist) {
					minDist = leaderDist;
					target  = navi;
				}
			}
		}
	}

	if (target) {
		mSlime->setTargetCreature(target);
		return true;
	}
	return false;
}

bool SlimeAi::chasePikiTransit()
{
	Creature* target      = nullptr;
	SlimeCreature* leader = mSlime->mSlimeCreatures[mSlime->mLeaderCreatureIndex];
	Vector3f* initPos     = mSlime->getInitPosition();
	f32 minDist           = 12800.0f;

	if (mSlime->getTargetCreature()) {
		minDist = leader->mSRT.t.distance(mSlime->getTargetCreature()->mSRT.t);
	}

	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Piki* piki = static_cast<Piki*>(*iter);
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried() && piki->mColor != Blue
		    && qdist2(piki->mSRT.t.x, piki->mSRT.t.z, initPos->x, initPos->z) < C_BOSS_PROP(mSlime).mTerritoryRadius()) {
			f32 quickLeaderDist = qdist2(leader->mSRT.t.x, leader->mSRT.t.z, piki->mSRT.t.x, piki->mSRT.t.z);
			if (quickLeaderDist < C_BOSS_PROP(mSlime).mSearchRadius() && quickLeaderDist < minDist) {
				f32 leaderDist = leader->mSRT.t.distance(piki->mSRT.t);
				if (leaderDist < C_BOSS_PROP(mSlime).mSearchRadius() && leaderDist < minDist) {
					minDist = leaderDist;
					target  = piki;
				}
			}
		}
	}

	if (target) {
		mSlime->setTargetCreature(target);
		return true;
	}
	return false;
}

bool SlimeAi::targetLostTransit()
{
	Creature* target = mSlime->getTargetCreature();
	if (target) {
		SlimeCreature* leader = mSlime->mSlimeCreatures[mSlime->mLeaderCreatureIndex];
		if (!target->isAlive() || !target->isVisible() || target->isBuried()) {
			mSlime->setTargetCreature(nullptr);
			return true;
		}

		Vector3f* initPos = mSlime->getInitPosition();
		if (qdist2(target->mSRT.t.x, target->mSRT.t.z, initPos->x, initPos->z) > C_BOSS_PROP(mSlime).mTerritoryRadius()) {
			mSlime->setTargetCreature(nullptr);
			return true;
		}

		if (leader->mSRT.t.distance(target->mSRT.t) > C_BOSS_PROP(mSlime).mSearchRadius()) {
			mSlime->setTargetCreature(nullptr);
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
bool SlimeAi::collisionContractTransit()
{
	if (mSlime->mDoCrashContract) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
bool SlimeAi::dissolutionContractTransit()
{
	if (mPrevNucleusStickPikiCount > 0 && mSlime->mNucleus->mNucleusAi->mStickPikiCount == 0) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
bool SlimeAi::finishContractTransit()
{
	if (mIsContractFinished || mSlime->getAttackTimer() > 2.0f) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool SlimeAi::finishExpansionTransit()
{
	if (mSlime->getAttackTimer() > 1.0f) {
		return true;
	}
	return false;
}

bool SlimeAi::appearTransit()
{
	Vector3f* initPos = mSlime->getInitPosition();
	Iterator iterNavi(naviMgr);
	CI_LOOP(iterNavi)
	{
		Creature* navi = *iterNavi;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()
		    && qdist2(initPos->x, initPos->z, navi->mSRT.t.x, navi->mSRT.t.z) < C_SLIME_PROP(mSlime).mDetectionRadius()) {
			return true;
		}
	}

	Iterator iterPiki(pikiMgr);
	CI_LOOP(iterPiki)
	{
		Creature* piki = *iterPiki;
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried()
		    && qdist2(initPos->x, initPos->z, piki->mSRT.t.x, piki->mSRT.t.z) < C_SLIME_PROP(mSlime).mDetectionRadius()) {
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool SlimeAi::disAppearTransit()
{
	if (mSlime->mAppearanceScale == 0.0f) {
		return true;
	}
	return false;
}

void SlimeAi::initDie(int nextState)
{
	mSlime->setNextState(nextState);
	mSlime->setMotionFinish(false);
	mSlime->mNucleus->subCurrentLife(128000.0f); // lol
	mSlime->mCore->subCurrentLife(128000.0f);    // lol
	mSlime->setAttackTimer(0.0f);
	setContractGoal();
	setExpansionGoal();
	playerState->mResultFlags.setSeen(RESFLAG_Slime);

	for (int i = 0; i < SLIMECREATURE_COUNT; i++) {
		zen::particleGenerator* ptclGenK
		    = effectMgr->create(EffectMgr::EFF_Slime_DeadK, mSlime->mSlimeCreatures[i]->mSRT.t, nullptr, nullptr);
		if (ptclGenK) {
			ptclGenK->setEmitPosPtr(&mSlime->mSlimeCreatures[i]->mSRT.t);
		}

		zen::particleGenerator* ptclGenI
		    = effectMgr->create(EffectMgr::EFF_Slime_DeadI, mSlime->mSlimeCreatures[i]->mSRT.t, nullptr, nullptr);
		if (ptclGenI) {
			ptclGenI->setEmitPosPtr(&mSlime->mSlimeCreatures[i]->mSRT.t);
		}
	}

	if (mSlime->mSeContext) {
		mSlime->mSeContext->stopSound(SE_SLIME_WALK);
	}
	if (mSlime->mSeContext) {
		mSlime->mSeContext->playSound(SE_SLIME_DISAPPEAR);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void SlimeAi::initWalk(int nextState)
{
	mSlime->setNextState(nextState);
	mSlime->setMotionFinish(false);
	mSlime->setTargetCreature(nullptr);
#if defined(VERSION_PIKIDEMO)
#else
	if (mSlime->mSeContext) {
		mSlime->mSeContext->playSound(SE_SLIME_WALK);
	}
#endif
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void SlimeAi::initChase(int nextState)
{
	mSlime->setNextState(nextState);
	mSlime->setMotionFinish(false);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000360
 */
void SlimeAi::initContract(int nextState)
{
	mSlime->setNextState(nextState);
	mSlime->setMotionFinish(false);
	mIsContractFinished = false;
	mSlime->setAttackTimer(0.0f);
	setContractGoal();
	calcContractDamage();
	contractCoreFlickPiki();
	mSlime->mCore->mCoreAi->setHitMotionStart();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000268
 */
void SlimeAi::initExpansion(int nextState)
{
	mSlime->setNextState(nextState);
	mSlime->setMotionFinish(false);
	mSlime->mDoCrashContract = false;
	mSlime->mIsMoveLeader    = true;
	mSlime->setAttackTimer(0.0f);
	setExpansionGoal();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000174
 */
void SlimeAi::initAppear(int nextState)
{
	mSlime->setNextState(nextState);
	mSlime->setMotionFinish(false);
	mSlime->mIsMoveLeader = true;
	mSlime->setAttackTimer(0.0f);
	mSlime->setWalkTimer(0.0f);
	mSlime->setAnimTimer(0.5f);
	setAppearGoal();
	if (mSlime->mSeContext) {
		mSlime->mSeContext->playSound(SE_SLIME_WALK);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void SlimeAi::initDisAppear(int nextState)
{
	mSlime->setNextState(nextState);
	mSlime->setMotionFinish(false);
	mSlime->mIsMoveLeader = false;
	mSlime->setIsAlive(false);
	mSlime->setIsAtari(false);
	mSlime->setAttackTimer(0.0f);
	mSlime->createPellet(mSlime->mSRT.t, 300.0f, true);
	effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeL, mSlime->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Teki_DeathGlowL, mSlime->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Teki_DeathWaveL, mSlime->mSRT.t, nullptr, nullptr);
	if (mSlime->mSeContext) {
		mSlime->mSeContext->playSound(SE_SLIME_DEAD);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000420
 */
void SlimeAi::dieState()
{
	bothEndsToGoal();
	if (mSlime->getAttackTimer() > 0.0f) {
		mSlime->mAppearanceScale -= C_SLIME_PROP(mSlime).mDeadScaleSpeed() * gsys->getFrameTime();
		if (mSlime->mAppearanceScale < 0.0f) {
			mSlime->mAppearanceScale = 0.0f;
		}
		if (!mSlime->getMotionFinish()) {
			mSlime->setMotionFinish(true);
			setDieGoal();
		}
	}
	setMidPointVelocity();
	mSlime->addAttackTimer(gsys->getFrameTime());
}

/*
 * --INFO--
 * Address:	........
 * Size:	00020C
 */
void SlimeAi::walkRandomState()
{
	makeTargetRandom();
	setVelocity(C_SLIME_PROP(mSlime).mMaxMoveSpeed());
	walkAllState();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void SlimeAi::walkGoHomeState()
{
	mSlime->setTargetPosition(*mSlime->getInitPosition());
	setVelocity(C_SLIME_PROP(mSlime).mMaxMoveSpeed());
	walkAllState();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void SlimeAi::chaseNaviState()
{
	mSlime->makeTargetCreature();
	setVelocity(C_SLIME_PROP(mSlime).mMaxMoveSpeed());
	walkAllState();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void SlimeAi::chasePikiState()
{
	mSlime->makeTargetCreature();
	setVelocity(C_SLIME_PROP(mSlime).mMaxMoveSpeed());
	walkAllState();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002C8
 */
void SlimeAi::contractState()
{
	bothEndsToGoal();
	mSlime->addAttackTimer(gsys->getFrameTime());
	setMidPointVelocity();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002C8
 */
void SlimeAi::expansionState()
{
	bothEndsToGoal();
	mSlime->addAttackTimer(gsys->getFrameTime());
	setMidPointVelocity();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SlimeAi::stayState()
{
}

void SlimeAi::appearState()
{
	STACK_PAD_VAR(2);
	f32 slimeScalePts[3];
	slimeScalePts[0] = 0.0f;
	slimeScalePts[1] = C_SLIME_PROP(mSlime).mRadiusContractionScore();
	slimeScalePts[2] = C_SLIME_PROP(mSlime).mRadiusContractionScore();
	f32 timer1       = mSlime->getAttackTimer();
	if (timer1 < 2.0f) {
		mSlime->mAppearanceScale = NsLibMath<f32>::lagrange3(slimeScalePts, timer1);
		if (timer1 < 1.25f) {
			mSlime->addAnimTimer(0.05f);
		} else {
			mSlime->addAnimTimer(-0.1f);
			if (mSlime->getAnimTimer() < 0.2f) {
				mSlime->setAnimTimer(0.2f);
			}
		}
	} else {
		mSlime->mAppearanceScale = C_SLIME_PROP(mSlime).mRadiusContractionScore();
	}

	f32 coreScalePts[3];
	coreScalePts[0] = 0.0f;
	coreScalePts[1] = 1.0f;
	coreScalePts[2] = 1.0f;
	f32 nucleusScalePts[3];
	nucleusScalePts[0] = 0.0f;
	nucleusScalePts[1] = 0.7f;
	nucleusScalePts[2] = 0.7f;
	f32 timer2         = mSlime->getWalkTimer();
	if (timer2 < 1.0f) {
		if (timer2 >= 0.47f && timer2 <= 0.97f) {

			f32 val   = (timer2 - 0.47f) * 4.0f;
			f32 scale = NsLibMath<f32>::lagrange3(coreScalePts, val);
			mSlime->mCore->mSRT.s.set(scale, scale, scale);
		}
		if (timer2 >= 0.4f && timer2 <= 0.9f) {

			f32 val   = (timer2 - 0.4f) * 4.0f;
			f32 scale = NsLibMath<f32>::lagrange3(nucleusScalePts, val);
			mSlime->mNucleus->mSRT.s.set(scale, scale, scale);
		}
	} else {
		mSlime->mCore->mSRT.s.set(coreScalePts[2], coreScalePts[2], coreScalePts[2]);
		mSlime->mNucleus->mSRT.s.set(nucleusScalePts[2], nucleusScalePts[2], nucleusScalePts[2]);
	}

	if (timer1 > 2.0f && timer2 > 1.0f) {
		mSlime->setMotionFinish(true);
		mSlime->mCore->setIsAlive(true);
		mSlime->mNucleus->setIsAlive(true);
		mSlime->mCore->mSRT.s.set(coreScalePts[2], coreScalePts[2], coreScalePts[2]);
		mSlime->mNucleus->mSRT.s.set(nucleusScalePts[2], nucleusScalePts[2], nucleusScalePts[2]);
		mSlime->mIsMoveLeader = true;
	}

	mSlime->addAttackTimer(mSlime->getAnimTimer() * gsys->getFrameTime());
	mSlime->addWalkTimer(gsys->getFrameTime());
	bothEndsToAppearGoal();
	setMidPointVelocity();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001B4
 */
void SlimeAi::disAppearState()
{
	bothEndsToGoal();
	if (mSlime->getAttackTimer() > 3.0f) {
		mSlime->doKill();
	}
	mSlime->addAttackTimer(gsys->getFrameTime());
}

void SlimeAi::update()
{
	setEveryFrame();
	switch (mSlime->getCurrentState()) {
	case SLIMEAI_Die:
		dieState();
		if (disAppearTransit()) {
			initDisAppear(SLIMEAI_Disappear);
		}
		break;

	case SLIMEAI_WalkRandom:
		walkRandomState();
		if (dieTransit()) {
			initDie(SLIMEAI_Die);
		} else if (collisionContractTransit()) {
			initContract(SLIMEAI_Contract);
		} else if (dissolutionContractTransit()) {
			initContract(SLIMEAI_Contract);
		} else if (chaseNaviTransit()) {
			initChase(SLIMEAI_ChaseNavi);
		} else if (chasePikiTransit()) {
			initChase(SLIMEAI_ChasePiki);
		}
		break;

	case SLIMEAI_ChaseNavi:
		chaseNaviState();
		if (dieTransit()) {
			initDie(SLIMEAI_Die);
		} else if (collisionContractTransit()) {
			initContract(SLIMEAI_Contract);
		} else if (dissolutionContractTransit()) {
			initContract(SLIMEAI_Contract);
		} else if (outSideChaseRangeTransit()) {
			initWalk(SLIMEAI_WalkGoHome);
		} else if (chasePikiTransit()) {
			initChase(SLIMEAI_ChasePiki);
		} else if (targetLostTransit()) {
			initWalk(SLIMEAI_WalkRandom);
		}
		break;

	case SLIMEAI_ChasePiki:
		chasePikiState();
		if (dieTransit()) {
			initDie(SLIMEAI_Die);
		} else if (collisionContractTransit()) {
			initContract(SLIMEAI_Contract);
		} else if (dissolutionContractTransit()) {
			initContract(SLIMEAI_Contract);
		} else if (outSideChaseRangeTransit()) {
			initWalk(SLIMEAI_WalkGoHome);
		} else if (chaseNaviTransit()) {
			initChase(SLIMEAI_ChaseNavi);
		} else if (chasePikiTransit()) {
			initChase(SLIMEAI_ChasePiki);
		} else if (targetLostTransit()) {
			initWalk(SLIMEAI_WalkRandom);
		}
		break;

	case SLIMEAI_WalkGoHome:
		walkGoHomeState();
		if (dieTransit()) {
			initDie(SLIMEAI_Die);
		} else if (collisionContractTransit()) {
			initContract(SLIMEAI_Contract);
		} else if (dissolutionContractTransit()) {
			initContract(SLIMEAI_Contract);
		} else if (inSideWaitRangeTransit()) {
			initWalk(SLIMEAI_WalkRandom);
		}
		break;

	case SLIMEAI_Contract:
		contractState();
		if (dieTransit()) {
			initDie(SLIMEAI_Die);
		} else if (finishContractTransit()) {
			initExpansion(SLIMEAI_Expansion);
		}
		break;

	case SLIMEAI_Expansion:
		expansionState();
		if (dieTransit()) {
			initDie(SLIMEAI_Die);
		} else if (collisionContractTransit()) {
			initContract(SLIMEAI_Contract);
		} else if (finishExpansionTransit()) {
			initWalk(SLIMEAI_WalkRandom);
		}
		break;

	case SLIMEAI_Stay:
		stayState();
		if (appearTransit()) {
			initAppear(SLIMEAI_Appear);
		}
		break;

	case SLIMEAI_Appear:
		appearState();
		if (motionFinishTransit()) {
			initWalk(SLIMEAI_WalkRandom);
		}
		break;

	case SLIMEAI_Disappear:
		disAppearState();
		break;
	}

	afterProcessing();
}
