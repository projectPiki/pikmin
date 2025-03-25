#include "Slime.h"
#include "Nucleus.h"
#include "CoreNucleus.h"
#include "Interactions.h"
#include "NsMath.h"
#include "PikiMgr.h"
#include "NaviMgr.h"
#include "SoundMgr.h"
#include "EffectMgr.h"
#include "RumbleMgr.h"
#include "PlayerState.h"
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
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	80164B80
 * Size:	000008
 */
SlimeAi::SlimeAi(Slime* slime)
{
	mSlime = slime;
}

/*
 * --INFO--
 * Address:	80164B88
 * Size:	0000A8
 */
void SlimeAi::init(Slime* slime)
{
	mSlime = slime;
	mSlime->setCurrentState(SLIMEAI_Stay);
	mSlime->setNextState(SLIMEAI_Stay);
	mSlime->mAnimator.startMotion(PaniMotionInfo(0));
	mIsContractFinished        = false;
	_01                        = true;
	mPrevNucleusStickPikiCount = 0;
	_0C                        = 0;
	mContractHitType           = SLIMEHIT_NoHit;
	mContractDamage            = 0.0f;
	mStickersRatio             = 0.0f;
	mMaxLength                 = C_SLIME_PROP(mSlime).mNormalMaxLength();
	mMinLength                 = C_SLIME_PROP(mSlime).mNormalMinLength();
}

/*
 * --INFO--
 * Address:	80164C30
 * Size:	000014
 */
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

/*
 * --INFO--
 * Address:	80164C44
 * Size:	000310
 */
void SlimeAi::calcBubblePiki()
{
	CollPart* part = nullptr;
	switch (_0C) {
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
				if (piki->mColor != Blue
				    && qdist2(piki->mPosition.x, piki->mPosition.z, part->mCentre.x, part->mCentre.z) < part->mRadius) {
					// we're close, so do an actual distance calculation
					f32 dist = piki->mPosition.distance(part->mCentre);
					if (dist < part->mRadius) {
						InteractBubble bubble(mSlime, 200.0f);
						piki->stimulate(bubble);
					}
				}
			}
		}
	}

	_0C++;
	if (_0C > 3) {
		_0C = 0;
	}
}

/*
 * --INFO--
 * Address:	80164F54
 * Size:	0000C4
 */
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
	    = 0.6667f * mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mPosition
	    + 0.3333f * mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mPosition;
	mSlime->mSlimeCreatures[SLIMECREATURE_NucleusInner]->mTargetPosition
	    = 0.3333f * mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mPosition
	    + 0.6667f * mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mPosition;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000104
 */
void SlimeAi::makeBodyThickness()
{
	f32 dist = mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mPosition.distance(
	    mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mPosition);
	f32 elongation = (dist - C_SLIME_PROP(mSlime).mNormalMinLength())
	               / (C_SLIME_PROP(mSlime).mMaxLengthAtSticking() - C_SLIME_PROP(mSlime).mNormalMinLength());
	f32 elongateRatio      = NsLibMath<f32>::revice(elongation, 0.0f, 1.0f);
	mSlime->mBodyThickness = C_SLIME_PROP(mSlime).mBodyThicknessElongate() * elongateRatio
	                       + C_SLIME_PROP(mSlime).mBodyThicknessContract() * (1.0f - elongateRatio);
}

/*
 * --INFO--
 * Address:	80165018
 * Size:	000164
 */
void SlimeAi::playExpandingSound()
{
	f32 expansionRatio = mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mPosition.distance(
	                         mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mPosition)
	                   / mMaxLength;
	if (mSlime->mIsMoveLeader && _01 && expansionRatio > 0.8f) {
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

		_01 = false;
	}

	if (!_01 && expansionRatio < 0.7f) {
		_01 = true;
	}
}

/*
 * --INFO--
 * Address:	8016517C
 * Size:	00033C
 */
void SlimeAi::calcCollisionCheck()
{
	mSlime->mCorePosition = 0.5f * mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mPosition
	                      + 0.5f * mSlime->mSlimeCreatures[SLIMECREATURE_CoreInner]->mPosition;
	mSlime->mNucleusPosition = 0.5f * mSlime->mSlimeCreatures[SLIMECREATURE_NucleusInner]->mPosition
	                         + 0.5f * mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mPosition;

	if (mSlime->getCurrentState() == SLIMEAI_Appear) {
		return;
	}

	f32 dist = mSlime->mNucleus->mPosition.distance(mSlime->mCore->mPosition);

	// force distance between nuclei to be mDistanceBetweenNuclei
	if (dist < C_SLIME_PROP(mSlime).mDistanceBetweenNuclei()) {
		Vector3f sep = mSlime->mCore->mPosition - mSlime->mNucleus->mPosition;
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

/*
 * --INFO--
 * Address:	801654B8
 * Size:	0000E8
 */
void SlimeAi::setLeaderNearerTarget()
{
	Slime* slime = mSlime;
	// only adjust leader if there aren't any stick pikis - core is always leader if there are stick pikis
	if (slime->mNucleus->mNucleusAi->mStickPikiCount == 0) {
		SlimeCreature* leader   = slime->mSlimeCreatures[slime->mLeaderCreatureIndex];
		SlimeCreature* follower = slime->mSlimeCreatures[slime->mFollowerCreatureIndex];
		Vector3f* targetPos     = slime->getTargetPosition();
		f32 followDist          = qdist2(follower->mPosition.x, follower->mPosition.z, targetPos->x, targetPos->z);
		f32 leadDist
		    = qdist2(leader->mPosition.x, leader->mPosition.z, targetPos->x, targetPos->z) - C_SLIME_PROP(slime).mDistanceBetweenNuclei();

		// if difference between leader-target dist and follower-target dist gets bigger than dist between nuclei, flip
		if (leadDist > followDist) {
			int prevLeader                 = mSlime->mLeaderCreatureIndex;
			mSlime->mLeaderCreatureIndex   = mSlime->mFollowerCreatureIndex;
			mSlime->mFollowerCreatureIndex = prevLeader;
			mSlime->mIsMoveLeader          = true;
		}
	}

	u32 badCompiler[2]; // this whole function is questionable.
}

/*
 * --INFO--
 * Address:	801655A0
 * Size:	000118
 */
void SlimeAi::moveFlagCheck()
{
	f32 dist = mSlime->mSlimeCreatures[mSlime->mLeaderCreatureIndex]->mPosition.distance(
	    mSlime->mSlimeCreatures[mSlime->mFollowerCreatureIndex]->mPosition);
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
	follower->mTargetPosition = leader->mPosition;
	mSlime->addAnimTimer(gsys->getFrameTime());
}

/*
 * --INFO--
 * Address:	801656B8
 * Size:	000144
 */
void SlimeAi::makeFollowerVelocity()
{
	SlimeCreature* follower = mSlime->mSlimeCreatures[mSlime->mFollowerCreatureIndex];
	if (!mSlime->mIsMoveLeader) {
		follower->mTargetVelocity.sub(follower->mTargetPosition, follower->mPosition);
		follower->mTargetVelocity.y = 0.0f;
		follower->mTargetVelocity.normalise();
		f32 complRatio = 1.0f - mStickersRatio;
		follower->mTargetVelocity.multiply(C_SLIME_PROP(mSlime).mMaxMoveSpeed() * complRatio
		                                   + C_SLIME_PROP(mSlime).mMinMoveSpeed() * mStickersRatio);
	} else {
		follower->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}
}

/*
 * --INFO--
 * Address:	801657FC
 * Size:	000124
 */
void SlimeAi::makeLeaderVelocity()
{
	SlimeCreature* leader   = mSlime->mSlimeCreatures[mSlime->mLeaderCreatureIndex];
	SlimeCreature* follower = mSlime->mSlimeCreatures[mSlime->mFollowerCreatureIndex];
	if (mSlime->mIsMoveLeader) {
		leader->mTargetVelocity.sub(leader->mTargetPosition, leader->mPosition);
		leader->mTargetVelocity.y = 0.0f;
		leader->mTargetVelocity.normalise();
		leader->mTargetVelocity.multiply(mSlime->mLeaderSpeed);
	} else {
		leader->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}
}

/*
 * --INFO--
 * Address:	80165920
 * Size:	0000E8
 */
void SlimeAi::setMidPointVelocity()
{
	// ... this is just "do for 1 and 2" but okay
	for (int i = 1; i < bossMgr->mSlimeCreatureCount - 1; i++) {
		mSlime->mSlimeCreatures[i]->mVelocity.multiply(C_SLIME_PROP(mSlime).mTraceMidPoint());

		Vector3f displacement = mSlime->mSlimeCreatures[i]->mTargetPosition - mSlime->mSlimeCreatures[i]->mPosition;
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

/*
 * --INFO--
 * Address:	80165A08
 * Size:	000104
 */
void SlimeAi::calcContractDamage()
{
	f32 nucleiDist = mSlime->mCore->mPosition.distance(mSlime->mNucleus->mPosition);
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

/*
 * --INFO--
 * Address:	80165B0C
 * Size:	000280
 */
void SlimeAi::contractCoreFlickPiki()
{
	CollPart* corePart = mSlime->mCore->mCollInfo->getBoundingSphere();
	f32 coreRadius     = corePart->mRadius + 30.0f;
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki && piki->isAlive() && piki->isVisible() && !piki->isBuried()
		    && qdist2(piki->mPosition.x, piki->mPosition.z, corePart->mCentre.x, corePart->mCentre.z) < coreRadius) {
			// close enough, do a proper check
			if (piki->mPosition.distance(corePart->mCentre) < coreRadius) {
				InteractFlick flick(mSlime->mCore, C_BOSS_PROP(mSlime->mCore).mFlickKnockback(), C_BOSS_PROP(mSlime->mCore).mFlickDamage(),
				                    FLICK_BACKWARDS_ANGLE);
				piki->stimulate(flick);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80165D8C
 * Size:	000280
 */
void SlimeAi::contractSubFlickPiki()
{
	CollPart* nucleusPart = mSlime->mNucleus->mCollInfo->getBoundingSphere();
	f32 nucleusRadius     = nucleusPart->mRadius + 30.0f;
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki && piki->isAlive() && piki->isVisible() && !piki->isBuried()
		    && qdist2(piki->mPosition.x, piki->mPosition.z, nucleusPart->mCentre.x, nucleusPart->mCentre.z) < nucleusRadius) {
			// close enough, do a proper check
			if (piki->mPosition.distance(nucleusPart->mCentre) < nucleusRadius) {
				InteractFlick flick(mSlime->mNucleus, C_BOSS_PROP(mSlime->mNucleus).mFlickKnockback(),
				                    C_BOSS_PROP(mSlime->mNucleus).mFlickDamage(), FLICK_BACKWARDS_ANGLE);
				piki->stimulate(flick);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8016600C
 * Size:	00029C
 */
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
		rumbleMgr->start(15, 0, midPoint);
		if (mSlime->mSeContext) {
			mSlime->mSeContext->playSound(SE_SLIME_HIT_SMALL);
		}

	} else if (mContractHitType == SLIMEHIT_Mid) {
		effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeM, midPoint, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathGlowM, midPoint, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathWaveM, midPoint, nullptr, nullptr);
		rumbleMgr->start(10, 0, midPoint);
		if (mSlime->mSeContext) {
			mSlime->mSeContext->playSound(SE_SLIME_HIT_MID);
		}

	} else if (mContractHitType == SLIMEHIT_Large) {
		effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeL, midPoint, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathGlowL, midPoint, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Teki_DeathWaveL, midPoint, nullptr, nullptr);
		rumbleMgr->start(14, 0, midPoint);
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
	    = 0.5f
	    * (mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mPosition + mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mPosition);
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
	    = 0.5f
	    * (mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mPosition + mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mPosition);
	Vector3f offsetFromMid = mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mPosition - midPoint;
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
	f32 angle      = atan2f(navi->mPosition.x - mSlime->mPosition.x, navi->mPosition.z - mSlime->mPosition.z);
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
	    = mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mTargetPosition - mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mPosition;
	velOffset.multiply(C_SLIME_PROP(mSlime).mContractSpringEnd());
	mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mVelocity.add(velOffset);

	mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mVelocity.multiply(C_SLIME_PROP(mSlime).mContractTraceEnd());

	velOffset = mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mTargetPosition
	          - mSlime->mSlimeCreatures[SLIMECREATURE_NucleusOuter]->mPosition;
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
	coreVel
	    = mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mTargetPosition - mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mPosition;
	coreVel.multiply(0.5f);
	mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mTargetVelocity = coreVel;
	mSlime->mSlimeCreatures[SLIMECREATURE_CoreOuter]->mVelocity       = coreVel;
}

/*
 * --INFO--
 * Address:	801662A8
 * Size:	00016C
 */
void SlimeAi::makeTargetRandom()
{
	mSlime->addWalkTimer(gsys->getFrameTime());
	SlimeCreature* leader = mSlime->mSlimeCreatures[mSlime->mLeaderCreatureIndex];
	Vector3f* targetPos   = mSlime->getTargetPosition();
	Vector3f* initPos     = mSlime->getInitPosition();

	if (mSlime->getWalkTimer() > 10.0f || qdist2(targetPos->x, targetPos->z, leader->mPosition.x, leader->mPosition.z) < 10.0f) {
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
	if (qdist2(leader->mPosition.x, leader->mPosition.z, initPos->x, initPos->z) > C_BOSS_PROP(mSlime).mTerritoryRadius()) {
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
	if (qdist2(follower->mPosition.x, follower->mPosition.z, initPos->x, initPos->z) < C_BOSS_PROP(mSlime).mMaxWaitRadius()) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80166414
 * Size:	000308
 */
bool SlimeAi::chaseNaviTransit()
{
	Creature* target      = nullptr;
	SlimeCreature* leader = mSlime->mSlimeCreatures[mSlime->mLeaderCreatureIndex];
	Vector3f* initPos     = mSlime->getInitPosition();
	f32 minDist           = 12800.0f;

	if (mSlime->getTargetCreature()) {
		minDist = leader->mPosition.distance(mSlime->getTargetCreature()->mPosition);
	}

	Iterator iter(naviMgr);
	CI_LOOP(iter)
	{
		Creature* navi = *iter;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()
		    && qdist2(navi->mPosition.x, navi->mPosition.z, initPos->x, initPos->z) < C_BOSS_PROP(mSlime).mTerritoryRadius()) {
			f32 quickLeaderDist = qdist2(leader->mPosition.x, leader->mPosition.z, navi->mPosition.x, navi->mPosition.z);
			if (quickLeaderDist < C_BOSS_PROP(mSlime).mSearchRadius() && quickLeaderDist < minDist) {
				f32 leaderDist = leader->mPosition.distance(navi->mPosition);
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

/*
 * --INFO--
 * Address:	8016671C
 * Size:	00030C
 */
bool SlimeAi::chasePikiTransit()
{
	Creature* target      = nullptr;
	SlimeCreature* leader = mSlime->mSlimeCreatures[mSlime->mLeaderCreatureIndex];
	Vector3f* initPos     = mSlime->getInitPosition();
	f32 minDist           = 12800.0f;

	if (mSlime->getTargetCreature()) {
		minDist = leader->mPosition.distance(mSlime->getTargetCreature()->mPosition);
	}

	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Piki* piki = static_cast<Piki*>(*iter);
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried() && piki->mColor != Blue
		    && qdist2(piki->mPosition.x, piki->mPosition.z, initPos->x, initPos->z) < C_BOSS_PROP(mSlime).mTerritoryRadius()) {
			f32 quickLeaderDist = qdist2(leader->mPosition.x, leader->mPosition.z, piki->mPosition.x, piki->mPosition.z);
			if (quickLeaderDist < C_BOSS_PROP(mSlime).mSearchRadius() && quickLeaderDist < minDist) {
				f32 leaderDist = leader->mPosition.distance(piki->mPosition);
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

/*
 * --INFO--
 * Address:	80166A28
 * Size:	000198
 */
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
		if (qdist2(target->mPosition.x, target->mPosition.z, initPos->x, initPos->z) > C_BOSS_PROP(mSlime).mTerritoryRadius()) {
			mSlime->setTargetCreature(nullptr);
			return true;
		}

		if (leader->mPosition.distance(target->mPosition) > C_BOSS_PROP(mSlime).mSearchRadius()) {
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

/*
 * --INFO--
 * Address:	80166BC0
 * Size:	0002E4
 */
bool SlimeAi::appearTransit()
{
	Vector3f* initPos = mSlime->getInitPosition();
	Iterator iterNavi(naviMgr);
	CI_LOOP(iterNavi)
	{
		Creature* navi = *iterNavi;
		if (navi->isAlive() && navi->isVisible() && !navi->isBuried()
		    && qdist2(initPos->x, initPos->z, navi->mPosition.x, navi->mPosition.z) < C_SLIME_PROP(mSlime).mDetectionRadius()) {
			return true;
		}
	}

	Iterator iterPiki(pikiMgr);
	CI_LOOP(iterPiki)
	{
		Creature* piki = *iterPiki;
		if (piki->isAlive() && piki->isVisible() && !piki->isBuried()
		    && qdist2(initPos->x, initPos->z, piki->mPosition.x, piki->mPosition.z) < C_SLIME_PROP(mSlime).mDetectionRadius()) {
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
	if (mSlime->_3D4 == 0.0f) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80166EA4
 * Size:	00053C
 */
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
		    = effectMgr->create(EffectMgr::EFF_Slime_DeadK, mSlime->mSlimeCreatures[i]->mPosition, nullptr, nullptr);
		if (ptclGenK) {
			ptclGenK->setEmitPosPtr(&mSlime->mSlimeCreatures[i]->mPosition);
		}

		zen::particleGenerator* ptclGenI
		    = effectMgr->create(EffectMgr::EFF_Slime_DeadI, mSlime->mSlimeCreatures[i]->mPosition, nullptr, nullptr);
		if (ptclGenI) {
			ptclGenI->setEmitPosPtr(&mSlime->mSlimeCreatures[i]->mPosition);
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
	if (mSlime->mSeContext) {
		mSlime->mSeContext->playSound(SE_SLIME_WALK);
	}
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
	mSlime->createPellet(mSlime->mPosition, 300.0f, true);
	effectMgr->create(EffectMgr::EFF_Teki_DeathSmokeL, mSlime->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Teki_DeathGlowL, mSlime->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Teki_DeathWaveL, mSlime->mPosition, nullptr, nullptr);
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
		mSlime->_3D4 -= C_SLIME_PROP(mSlime).mDeadScaleSpeed() * gsys->getFrameTime();
		if (mSlime->_3D4 < 0.0f) {
			mSlime->_3D4 = 0.0f;
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

/*
 * --INFO--
 * Address:	801673E0
 * Size:	000494
 */
void SlimeAi::appearState()
{
	u32 badCompiler[2];
	f32 slimeScalePts[3];
	slimeScalePts[0] = 0.0f;
	slimeScalePts[1] = C_SLIME_PROP(mSlime).mRadiusContractionScore();
	slimeScalePts[2] = C_SLIME_PROP(mSlime).mRadiusContractionScore();
	f32 timer1       = mSlime->getAttackTimer();
	if (timer1 < 2.0f) {
		mSlime->_3D4 = NsLibMath<f32>::lagrange3(slimeScalePts, timer1);
		if (timer1 < 1.25f) {
			mSlime->addAnimTimer(0.05f);
		} else {
			mSlime->addAnimTimer(-0.1f);
			if (mSlime->getAnimTimer() < 0.2f) {
				mSlime->setAnimTimer(0.2f);
			}
		}
	} else {
		mSlime->_3D4 = C_SLIME_PROP(mSlime).mRadiusContractionScore();
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
			mSlime->mCore->mScale.set(scale, scale, scale);
		}
		if (timer2 >= 0.4f && timer2 <= 0.9f) {

			f32 val   = (timer2 - 0.4f) * 4.0f;
			f32 scale = NsLibMath<f32>::lagrange3(nucleusScalePts, val);
			mSlime->mNucleus->mScale.set(scale, scale, scale);
		}
	} else {
		mSlime->mCore->mScale.set(coreScalePts[2], coreScalePts[2], coreScalePts[2]);
		mSlime->mNucleus->mScale.set(nucleusScalePts[2], nucleusScalePts[2], nucleusScalePts[2]);
	}

	if (timer1 > 2.0f && timer2 > 1.0f) {
		mSlime->setMotionFinish(true);
		mSlime->mCore->setIsAlive(true);
		mSlime->mNucleus->setIsAlive(true);
		mSlime->mCore->mScale.set(coreScalePts[2], coreScalePts[2], coreScalePts[2]);
		mSlime->mNucleus->mScale.set(nucleusScalePts[2], nucleusScalePts[2], nucleusScalePts[2]);
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

/*
 * --INFO--
 * Address:	80167874
 * Size:	002D88
 */
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xBA8(r1)
	  stfd      f31, 0xBA0(r1)
	  stfd      f30, 0xB98(r1)
	  stfd      f29, 0xB90(r1)
	  stfd      f28, 0xB88(r1)
	  stw       r31, 0xB84(r1)
	  mr        r31, r3
	  stw       r30, 0xB80(r1)
	  bl        -0x2C58
	  mr        r3, r31
	  bl        -0x2950
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x88
	  lwz       r4, 0x20(r31)
	  lwz       r3, 0x3F8(r4)
	  lwz       r3, 0x3BC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x88
	  addi      r3, r4, 0x3C8
	  lwz       r0, 0x3C8(r4)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x7C
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  li        r0, 0x3
	  lwz       r3, 0x20(r31)
	  stw       r0, 0x3CC(r3)

	.loc_0x7C:
	  lwz       r3, 0x20(r31)
	  li        r0, 0x1
	  stb       r0, 0x3C4(r3)

	.loc_0x88:
	  mr        r3, r31
	  bl        -0x2784
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x3A4
	  lfs       f1, 0x12C(r13)
	  addi      r5, r1, 0x3A0
	  lwz       r3, 0x3F4(r3)
	  addi      r4, r1, 0x39C
	  lwz       r3, 0xC(r3)
	  lfs       f0, 0x9C(r3)
	  addi      r7, r3, 0x94
	  addi      r3, r1, 0xB4C
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3A4(r1)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3A0(r1)
	  lfs       f0, 0x0(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x39C(r1)
	  bl        -0x130830
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x398
	  lfs       f1, 0x128(r13)
	  addi      r5, r1, 0x394
	  lwz       r3, 0x3F4(r3)
	  addi      r4, r1, 0x390
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x9C(r3)
	  addi      r7, r3, 0x94
	  addi      r3, r1, 0xB40
	  fmuls     f0, f0, f1
	  stfs      f0, 0x398(r1)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x394(r1)
	  lfs       f0, 0x0(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x390(r1)
	  bl        -0x13087C
	  lfs       f1, 0xB48(r1)
	  addi      r6, r1, 0x5BC
	  lfs       f0, 0xB54(r1)
	  addi      r5, r1, 0x5B8
	  lfs       f3, 0xB44(r1)
	  fadds     f4, f1, f0
	  lfs       f2, 0xB50(r1)
	  lfs       f1, 0xB40(r1)
	  addi      r4, r1, 0x5B4
	  lfs       f0, 0xB4C(r1)
	  fadds     f2, f3, f2
	  stfs      f4, 0x5BC(r1)
	  fadds     f0, f1, f0
	  addi      r3, r1, 0xB34
	  stfs      f2, 0x5B8(r1)
	  stfs      f0, 0x5B4(r1)
	  bl        -0x1308C0
	  lwz       r4, 0x20(r31)
	  addi      r6, r1, 0x38C
	  lwz       r3, 0xB34(r1)
	  addi      r5, r1, 0x388
	  lwz       r7, 0x3F4(r4)
	  lwz       r0, 0xB38(r1)
	  addi      r4, r1, 0x384
	  lwz       r7, 0x4(r7)
	  stw       r3, 0x2BC(r7)
	  addi      r3, r1, 0xB70
	  stw       r0, 0x2C0(r7)
	  lwz       r0, 0xB3C(r1)
	  stw       r0, 0x2C4(r7)
	  lwz       r7, 0x20(r31)
	  lfs       f1, 0x134(r13)
	  lwz       r7, 0x3F4(r7)
	  lwz       r7, 0xC(r7)
	  addi      r7, r7, 0x94
	  lfs       f0, 0x8(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38C(r1)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x388(r1)
	  lfs       f0, 0x0(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x384(r1)
	  bl        -0x130930
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x380
	  lfs       f1, 0x130(r13)
	  addi      r5, r1, 0x37C
	  lwz       r3, 0x3F4(r3)
	  addi      r4, r1, 0x378
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x9C(r3)
	  addi      r7, r3, 0x94
	  addi      r3, r1, 0xB64
	  fmuls     f0, f0, f1
	  stfs      f0, 0x380(r1)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x37C(r1)
	  lfs       f0, 0x0(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x378(r1)
	  bl        -0x13097C
	  lfs       f1, 0xB6C(r1)
	  addi      r6, r1, 0x5B0
	  lfs       f0, 0xB78(r1)
	  addi      r5, r1, 0x5AC
	  lfs       f3, 0xB68(r1)
	  fadds     f4, f1, f0
	  lfs       f2, 0xB74(r1)
	  lfs       f1, 0xB64(r1)
	  addi      r4, r1, 0x5A8
	  lfs       f0, 0xB70(r1)
	  fadds     f2, f3, f2
	  stfs      f4, 0x5B0(r1)
	  fadds     f0, f1, f0
	  addi      r3, r1, 0xB58
	  stfs      f2, 0x5AC(r1)
	  stfs      f0, 0x5A8(r1)
	  bl        -0x1309C0
	  lwz       r4, 0x20(r31)
	  addi      r6, r1, 0x374
	  lwz       r3, 0xB58(r1)
	  addi      r5, r1, 0x370
	  lwz       r7, 0x3F4(r4)
	  lwz       r0, 0xB5C(r1)
	  addi      r4, r1, 0x36C
	  lwz       r7, 0x8(r7)
	  stw       r3, 0x2BC(r7)
	  addi      r3, r1, 0x59C
	  stw       r0, 0x2C0(r7)
	  lwz       r0, 0xB60(r1)
	  stw       r0, 0x2C4(r7)
	  lwz       r7, 0x20(r31)
	  lfs       f0, -0x54A8(r2)
	  lwz       r7, 0x3F4(r7)
	  lwz       r8, 0xC(r7)
	  lwz       r7, 0x0(r7)
	  addi      r8, r8, 0x94
	  stfs      f0, 0x5A4(r1)
	  addi      r7, r7, 0x94
	  stfs      f0, 0x5A0(r1)
	  stfs      f0, 0x59C(r1)
	  lfs       f1, 0x8(r8)
	  lfs       f0, 0x8(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x374(r1)
	  lfs       f1, 0x4(r8)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x370(r1)
	  lfs       f1, 0x0(r8)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x36C(r1)
	  bl        -0x10A4E0
	  lfs       f1, 0x59C(r1)
	  lfs       f0, 0x5A0(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x5A4(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x159F50
	  lwz       r5, 0x20(r31)
	  lfs       f3, -0x54A8(r2)
	  lwz       r4, 0x224(r5)
	  lfs       f2, 0x250(r4)
	  lfs       f0, 0x260(r4)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fdivs     f0, f1, f0
	  fcmpo     cr0, f0, f3
	  bge-      .loc_0x34C
	  b         .loc_0x360

	.loc_0x34C:
	  lfs       f3, -0x54A0(r2)
	  fcmpo     cr0, f0, f3
	  ble-      .loc_0x35C
	  b         .loc_0x360

	.loc_0x35C:
	  fmr       f3, f0

	.loc_0x360:
	  lfs       f0, -0x54A0(r2)
	  mr        r3, r31
	  lfs       f2, 0x350(r4)
	  fsubs     f1, f0, f3
	  lfs       f0, 0x360(r4)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x3D8(r5)
	  bl        -0x2BE0
	  lwz       r3, 0x20(r31)
	  lfs       f0, -0x54A8(r2)
	  lfs       f1, 0x2C0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x3A0
	  bl        -0x196C8

	.loc_0x3A0:
	  lwz       r5, 0x20(r31)
	  lwz       r0, 0x2E4(r5)
	  cmplwi    r0, 0x9
	  bgt-      .loc_0x2D4C
	  lis       r3, 0x802D
	  subi      r3, r3, 0x110
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lfs       f0, -0x54A8(r2)
	  addi      r6, r1, 0x580
	  addi      r5, r1, 0x57C
	  stfs      f0, 0xB24(r1)
	  addi      r4, r1, 0x578
	  addi      r3, r1, 0xB1C
	  stfs      f0, 0xB20(r1)
	  stfs      f0, 0xB1C(r1)
	  lwz       r8, 0x20(r31)
	  lwz       r7, 0x3F4(r8)
	  lwz       r8, 0x224(r8)
	  lwz       r7, 0x0(r7)
	  lfs       f1, 0x310(r8)
	  lfsu      f0, 0x70(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x8(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r7)
	  lwz       r7, 0x20(r31)
	  lwz       r7, 0x3F4(r7)
	  lwz       r7, 0x0(r7)
	  addi      r8, r7, 0x94
	  addi      r7, r7, 0x2BC
	  lfs       f0, 0x8(r8)
	  lfs       f1, 0x8(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x580(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x57C(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x578(r1)
	  bl        -0x130BBC
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x574
	  lfs       f0, 0xB1C(r1)
	  addi      r5, r1, 0x570
	  lwz       r3, 0x224(r3)
	  addi      r4, r1, 0x56C
	  lfs       f1, 0x320(r3)
	  addi      r3, r1, 0xB1C
	  fmuls     f0, f0, f1
	  stfs      f0, 0xB1C(r1)
	  lfs       f0, 0xB20(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xB20(r1)
	  lfs       f0, 0xB24(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xB24(r1)
	  lwz       r7, 0x20(r31)
	  lfs       f0, 0xB1C(r1)
	  lwz       r7, 0x3F4(r7)
	  lwz       r7, 0x0(r7)
	  lfsu      f1, 0x70(r7)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r7)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0xB20(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r7)
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0xB24(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r7)
	  lwz       r8, 0x20(r31)
	  lwz       r7, 0x3F4(r8)
	  lwz       r8, 0x224(r8)
	  lwz       r7, 0xC(r7)
	  lfs       f1, 0x310(r8)
	  lfsu      f0, 0x70(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x8(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r7)
	  lwz       r7, 0x20(r31)
	  lwz       r7, 0x3F4(r7)
	  lwz       r7, 0xC(r7)
	  addi      r8, r7, 0x94
	  addi      r7, r7, 0x2BC
	  lfs       f0, 0x8(r8)
	  lfs       f1, 0x8(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x574(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x570(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x56C(r1)
	  bl        -0x130CB8
	  lwz       r3, 0x20(r31)
	  lfs       f0, 0xB1C(r1)
	  lwz       r3, 0x224(r3)
	  lfs       f1, 0x320(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xB1C(r1)
	  lfs       f0, 0xB20(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xB20(r1)
	  lfs       f0, 0xB24(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xB24(r1)
	  lwz       r3, 0x20(r31)
	  lfs       f0, 0xB1C(r1)
	  lwz       r3, 0x3F4(r3)
	  lwz       r3, 0xC(r3)
	  lfsu      f1, 0x70(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r3)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0xB20(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r3)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0xB24(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r3)
	  lwz       r5, 0x20(r31)
	  lfs       f3, -0x54A8(r2)
	  lfs       f0, 0x2D4(r5)
	  fcmpo     cr0, f0, f3
	  ble-      .loc_0x6C0
	  lwz       r4, 0x224(r5)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x330(r4)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x3D4(r5)
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x3D4(r5)
	  lwz       r3, 0x20(r31)
	  lfsu      f0, 0x3D4(r3)
	  fcmpo     cr0, f0, f3
	  bge-      .loc_0x618
	  stfs      f3, 0x0(r3)

	.loc_0x618:
	  lwz       r3, 0x20(r31)
	  lbzu      r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x6C0
	  li        r0, 0x1
	  stb       r0, 0x0(r3)
	  addi      r3, r1, 0xAFC
	  lwz       r4, 0x20(r31)
	  lwz       r5, 0x3F4(r4)
	  lwz       r4, 0x0(r5)
	  lwz       r5, 0xC(r5)
	  addi      r4, r4, 0x94
	  addi      r5, r5, 0x94
	  bl        .loc_0x2D88
	  addi      r3, r1, 0xAF0
	  addi      r4, r1, 0xAFC
	  addi      r5, r13, 0x164
	  bl        -0xC89FC
	  lfs       f0, 0xAF0(r1)
	  lfs       f1, 0xAF4(r1)
	  stfs      f0, 0xAE4(r1)
	  lfs       f0, 0xAF8(r1)
	  stfs      f1, 0xAE8(r1)
	  stfs      f0, 0xAEC(r1)
	  lwz       r4, 0x20(r31)
	  lwz       r3, 0xAE4(r1)
	  lwz       r4, 0x3F4(r4)
	  lwz       r0, 0xAE8(r1)
	  lwz       r4, 0x0(r4)
	  stw       r3, 0x2BC(r4)
	  stw       r0, 0x2C0(r4)
	  lwz       r0, 0xAEC(r1)
	  stw       r0, 0x2C4(r4)
	  lwz       r4, 0x20(r31)
	  lwz       r3, 0xAE4(r1)
	  lwz       r4, 0x3F4(r4)
	  lwz       r0, 0xAE8(r1)
	  lwz       r4, 0xC(r4)
	  stw       r3, 0x2BC(r4)
	  stw       r0, 0x2C0(r4)
	  lwz       r0, 0xAEC(r1)
	  stw       r0, 0x2C4(r4)

	.loc_0x6C0:
	  mr        r3, r31
	  bl        -0x2618
	  lwz       r4, 0x20(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D4(r4)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D4(r4)
	  lwz       r3, 0x20(r31)
	  lfs       f1, -0x54A8(r2)
	  lfs       f0, 0x3D4(r3)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x6FC
	  li        r0, 0x1
	  b         .loc_0x700

	.loc_0x6FC:
	  li        r0, 0

	.loc_0x700:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x2D4C
	  li        r0, 0x9
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  li        r5, 0x1
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x3C4(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2B8(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2B9(r3)
	  lfs       f0, -0x54A8(r2)
	  lwz       r3, 0x20(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x20(r31)
	  lfs       f1, -0x5458(r2)
	  addi      r4, r3, 0x94
	  bl        -0x19EB4
	  lwz       r5, 0x20(r31)
	  li        r4, 0x39
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x34B58
	  lwz       r5, 0x20(r31)
	  li        r4, 0x38
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x34B3C
	  lwz       r5, 0x20(r31)
	  li        r4, 0x37
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x34B20
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2D4C
	  li        r4, 0x91
	  bl        -0xC4260
	  b         .loc_0x2D4C
	  mr        r3, r31
	  bl        -0x1D94
	  lwz       r5, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0x224(r5)
	  lfs       f0, 0x220(r4)
	  stfs      f0, 0x3D0(r5)
	  bl        -0x2B9C
	  mr        r3, r31
	  bl        -0x2ABC
	  lwz       r6, 0x20(r31)
	  lwz       r3, 0x3C8(r6)
	  lwz       r0, 0x3CC(r6)
	  lwz       r7, 0x3F4(r6)
	  rlwinm    r4,r3,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x30C(r6)
	  lwzx      r5, r7, r4
	  lwzx      r4, r7, r0
	  lwz       r0, 0x310(r6)
	  stw       r3, 0x2BC(r5)
	  stw       r0, 0x2C0(r5)
	  lwz       r0, 0x314(r6)
	  stw       r0, 0x2C4(r5)
	  lwz       r3, 0x94(r5)
	  lwz       r0, 0x98(r5)
	  stw       r3, 0x2BC(r4)
	  stw       r0, 0x2C0(r4)
	  lwz       r0, 0x9C(r5)
	  stw       r0, 0x2C4(r4)
	  lwz       r3, 0x2DEC(r13)
	  bl        -0xE8E08
	  lwz       r4, 0x20(r31)
	  mr        r3, r31
	  lfs       f0, 0x2D8(r4)
	  fadds     f0, f0, f1
	  stfs      f0, 0x2D8(r4)
	  bl        -0x2A14
	  mr        r3, r31
	  bl        -0x28D8
	  mr        r3, r31
	  bl        -0x27BC
	  lwz       r4, 0x20(r31)
	  lfs       f0, -0x54A8(r2)
	  lfs       f1, 0x2C4(r4)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x898
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x1260
	  b         .loc_0x2D4C

	.loc_0x898:
	  lbz       r0, 0x3C5(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x8AC
	  li        r0, 0x1
	  b         .loc_0x8B0

	.loc_0x8AC:
	  li        r0, 0

	.loc_0x8B0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xAC8
	  li        r0, 0x5
	  stw       r0, 0x2E8(r4)
	  li        r0, 0
	  addi      r3, r1, 0xA84
	  lwz       r4, 0x20(r31)
	  stb       r0, 0x2BD(r4)
	  stb       r0, 0x0(r31)
	  lfs       f0, -0x54A8(r2)
	  lwz       r4, 0x20(r31)
	  stfs      f0, 0x2D4(r4)
	  lwz       r5, 0x20(r31)
	  lfs       f0, -0x548C(r2)
	  lwz       r4, 0x224(r5)
	  lwz       r5, 0x3F4(r5)
	  lfs       f1, 0x280(r4)
	  lwz       r4, 0x0(r5)
	  fmuls     f0, f1, f0
	  lfs       f2, -0x5478(r2)
	  lwz       r5, 0xC(r5)
	  addi      r4, r4, 0x94
	  fadds     f31, f2, f0
	  addi      r5, r5, 0x94
	  bl        .loc_0x2D88
	  addi      r3, r1, 0xA78
	  addi      r4, r1, 0xA84
	  addi      r5, r13, 0x168
	  bl        -0xC8CC0
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x350
	  lfs       f30, 0xA80(r1)
	  addi      r5, r1, 0x34C
	  lwz       r3, 0x3F4(r3)
	  lfs       f29, 0xA7C(r1)
	  addi      r4, r1, 0x348
	  lwz       r3, 0x0(r3)
	  lfs       f28, 0xA78(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r7, r3, 0x94
	  addi      r3, r1, 0xA90
	  fsubs     f0, f0, f30
	  stfs      f0, 0x350(r1)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f0, f29
	  stfs      f0, 0x34C(r1)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f0, f28
	  stfs      f0, 0x348(r1)
	  bl        -0x1310CC
	  lfs       f1, 0xA90(r1)
	  lfs       f0, 0xA94(r1)
	  stfs      f1, 0xA6C(r1)
	  stfs      f0, 0xA70(r1)
	  lfs       f0, 0xA98(r1)
	  stfs      f0, 0xA74(r1)
	  lfs       f1, 0xA6C(r1)
	  lfs       f0, 0xA70(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xA74(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15A5E4
	  lfs       f0, -0x54A8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x9C8
	  addi      r3, r1, 0xA6C
	  bl        -0xDECEC

	.loc_0x9C8:
	  lfs       f0, 0xA6C(r1)
	  addi      r6, r1, 0x558
	  addi      r5, r1, 0x554
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x550
	  addi      r3, r1, 0xA9C
	  stfs      f0, 0xA6C(r1)
	  lfs       f0, 0xA70(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xA70(r1)
	  lfs       f0, 0xA74(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xA74(r1)
	  lfs       f1, 0xA74(r1)
	  lfs       f0, 0xA6C(r1)
	  fadds     f1, f30, f1
	  fadds     f0, f28, f0
	  stfs      f1, 0x558(r1)
	  lfs       f1, 0xA70(r1)
	  fadds     f1, f29, f1
	  stfs      f0, 0x550(r1)
	  stfs      f1, 0x554(r1)
	  bl        -0x131178
	  lwz       r4, 0x20(r31)
	  addi      r6, r1, 0x54C
	  lwz       r3, 0xA9C(r1)
	  addi      r5, r1, 0x548
	  lwz       r7, 0x3F4(r4)
	  lwz       r0, 0xAA0(r1)
	  addi      r4, r1, 0x544
	  lwz       r7, 0x0(r7)
	  stw       r3, 0x2BC(r7)
	  addi      r3, r1, 0xAA8
	  stw       r0, 0x2C0(r7)
	  lwz       r0, 0xAA4(r1)
	  stw       r0, 0x2C4(r7)
	  lfs       f1, 0xA74(r1)
	  lfs       f0, 0xA6C(r1)
	  fsubs     f1, f30, f1
	  fsubs     f0, f28, f0
	  stfs      f1, 0x54C(r1)
	  lfs       f1, 0xA70(r1)
	  fsubs     f1, f29, f1
	  stfs      f0, 0x544(r1)
	  stfs      f1, 0x548(r1)
	  bl        -0x1311D4
	  lwz       r5, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0xAA8(r1)
	  lwz       r5, 0x3F4(r5)
	  lwz       r0, 0xAAC(r1)
	  lwz       r5, 0xC(r5)
	  stw       r4, 0x2BC(r5)
	  stw       r0, 0x2C0(r5)
	  lwz       r0, 0xAB0(r1)
	  stw       r0, 0x2C4(r5)
	  bl        -0x2914
	  mr        r3, r31
	  bl        -0x2818
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x3FC(r3)
	  lwz       r3, 0x3C0(r3)
	  bl        0x12B50
	  b         .loc_0x2D4C

	.loc_0xAC8:
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0
	  ble-      .loc_0xAF0
	  lwz       r3, 0x3F8(r4)
	  lwz       r3, 0x3BC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xAF0
	  li        r0, 0x1
	  b         .loc_0xAF4

	.loc_0xAF0:
	  li        r0, 0

	.loc_0xAF4:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xD0C
	  li        r0, 0x5
	  stw       r0, 0x2E8(r4)
	  li        r0, 0
	  addi      r3, r1, 0xA24
	  lwz       r4, 0x20(r31)
	  stb       r0, 0x2BD(r4)
	  stb       r0, 0x0(r31)
	  lfs       f0, -0x54A8(r2)
	  lwz       r4, 0x20(r31)
	  stfs      f0, 0x2D4(r4)
	  lwz       r5, 0x20(r31)
	  lfs       f0, -0x548C(r2)
	  lwz       r4, 0x224(r5)
	  lwz       r5, 0x3F4(r5)
	  lfs       f1, 0x280(r4)
	  lwz       r4, 0x0(r5)
	  fmuls     f0, f1, f0
	  lfs       f2, -0x5478(r2)
	  lwz       r5, 0xC(r5)
	  addi      r4, r4, 0x94
	  fadds     f31, f2, f0
	  addi      r5, r5, 0x94
	  bl        .loc_0x2D88
	  addi      r3, r1, 0xA18
	  addi      r4, r1, 0xA24
	  addi      r5, r13, 0x168
	  bl        -0xC8F04
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x344
	  lfs       f28, 0xA20(r1)
	  addi      r5, r1, 0x340
	  lwz       r3, 0x3F4(r3)
	  lfs       f29, 0xA1C(r1)
	  addi      r4, r1, 0x33C
	  lwz       r3, 0x0(r3)
	  lfs       f30, 0xA18(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r7, r3, 0x94
	  addi      r3, r1, 0xA30
	  fsubs     f0, f0, f28
	  stfs      f0, 0x344(r1)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f0, f29
	  stfs      f0, 0x340(r1)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f0, f30
	  stfs      f0, 0x33C(r1)
	  bl        -0x131310
	  lfs       f1, 0xA30(r1)
	  lfs       f0, 0xA34(r1)
	  stfs      f1, 0xA0C(r1)
	  stfs      f0, 0xA10(r1)
	  lfs       f0, 0xA38(r1)
	  stfs      f0, 0xA14(r1)
	  lfs       f1, 0xA0C(r1)
	  lfs       f0, 0xA10(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xA14(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15A828
	  lfs       f0, -0x54A8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xC0C
	  addi      r3, r1, 0xA0C
	  bl        -0xDEF30

	.loc_0xC0C:
	  lfs       f0, 0xA0C(r1)
	  addi      r6, r1, 0x538
	  addi      r5, r1, 0x534
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x530
	  addi      r3, r1, 0xA3C
	  stfs      f0, 0xA0C(r1)
	  lfs       f0, 0xA10(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xA10(r1)
	  lfs       f0, 0xA14(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xA14(r1)
	  lfs       f1, 0xA14(r1)
	  lfs       f0, 0xA0C(r1)
	  fadds     f1, f28, f1
	  fadds     f0, f30, f0
	  stfs      f1, 0x538(r1)
	  lfs       f1, 0xA10(r1)
	  fadds     f1, f29, f1
	  stfs      f0, 0x530(r1)
	  stfs      f1, 0x534(r1)
	  bl        -0x1313BC
	  lwz       r4, 0x20(r31)
	  addi      r6, r1, 0x52C
	  lwz       r3, 0xA3C(r1)
	  addi      r5, r1, 0x528
	  lwz       r7, 0x3F4(r4)
	  lwz       r0, 0xA40(r1)
	  addi      r4, r1, 0x524
	  lwz       r7, 0x0(r7)
	  stw       r3, 0x2BC(r7)
	  addi      r3, r1, 0xA48
	  stw       r0, 0x2C0(r7)
	  lwz       r0, 0xA44(r1)
	  stw       r0, 0x2C4(r7)
	  lfs       f1, 0xA14(r1)
	  lfs       f0, 0xA0C(r1)
	  fsubs     f1, f28, f1
	  fsubs     f0, f30, f0
	  stfs      f1, 0x52C(r1)
	  lfs       f1, 0xA10(r1)
	  fsubs     f1, f29, f1
	  stfs      f0, 0x524(r1)
	  stfs      f1, 0x528(r1)
	  bl        -0x131418
	  lwz       r5, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0xA48(r1)
	  lwz       r5, 0x3F4(r5)
	  lwz       r0, 0xA4C(r1)
	  lwz       r5, 0xC(r5)
	  stw       r4, 0x2BC(r5)
	  stw       r0, 0x2C0(r5)
	  lwz       r0, 0xA50(r1)
	  stw       r0, 0x2C4(r5)
	  bl        -0x2B58
	  mr        r3, r31
	  bl        -0x2A5C
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x3FC(r3)
	  lwz       r3, 0x3C0(r3)
	  bl        0x1290C
	  b         .loc_0x2D4C

	.loc_0xD0C:
	  mr        r3, r31
	  bl        -0x2170
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD38
	  lwz       r3, 0x20(r31)
	  li        r4, 0x2
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2BD(r3)
	  b         .loc_0x2D4C

	.loc_0xD38:
	  mr        r3, r31
	  bl        -0x1E94
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2D4C
	  lwz       r3, 0x20(r31)
	  li        r4, 0x3
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2BD(r3)
	  b         .loc_0x2D4C
	  mr        r3, r5
	  bl        -0x1A044
	  lwz       r5, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0x224(r5)
	  lfs       f0, 0x220(r4)
	  stfs      f0, 0x3D0(r5)
	  bl        -0x313C
	  mr        r3, r31
	  bl        -0x305C
	  lwz       r6, 0x20(r31)
	  lwz       r3, 0x3C8(r6)
	  lwz       r0, 0x3CC(r6)
	  lwz       r7, 0x3F4(r6)
	  rlwinm    r4,r3,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x30C(r6)
	  lwzx      r5, r7, r4
	  lwzx      r4, r7, r0
	  lwz       r0, 0x310(r6)
	  stw       r3, 0x2BC(r5)
	  stw       r0, 0x2C0(r5)
	  lwz       r0, 0x314(r6)
	  stw       r0, 0x2C4(r5)
	  lwz       r3, 0x94(r5)
	  lwz       r0, 0x98(r5)
	  stw       r3, 0x2BC(r4)
	  stw       r0, 0x2C0(r4)
	  lwz       r0, 0x9C(r5)
	  stw       r0, 0x2C4(r4)
	  lwz       r3, 0x2DEC(r13)
	  bl        -0xE93A8
	  lwz       r4, 0x20(r31)
	  mr        r3, r31
	  lfs       f0, 0x2D8(r4)
	  fadds     f0, f0, f1
	  stfs      f0, 0x2D8(r4)
	  bl        -0x2FB4
	  mr        r3, r31
	  bl        -0x2E78
	  mr        r3, r31
	  bl        -0x2D5C
	  lwz       r30, 0x20(r31)
	  lfs       f0, -0x54A8(r2)
	  lfs       f1, 0x2C4(r30)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0xE38
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x1800
	  b         .loc_0x2D4C

	.loc_0xE38:
	  lbz       r0, 0x3C5(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xE4C
	  li        r0, 0x1
	  b         .loc_0xE50

	.loc_0xE4C:
	  li        r0, 0

	.loc_0xE50:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1068
	  li        r0, 0x5
	  stw       r0, 0x2E8(r30)
	  li        r0, 0
	  addi      r3, r1, 0x9AC
	  lwz       r4, 0x20(r31)
	  stb       r0, 0x2BD(r4)
	  stb       r0, 0x0(r31)
	  lfs       f0, -0x54A8(r2)
	  lwz       r4, 0x20(r31)
	  stfs      f0, 0x2D4(r4)
	  lwz       r5, 0x20(r31)
	  lfs       f0, -0x548C(r2)
	  lwz       r4, 0x224(r5)
	  lwz       r5, 0x3F4(r5)
	  lfs       f1, 0x280(r4)
	  lwz       r4, 0x0(r5)
	  fmuls     f0, f1, f0
	  lfs       f2, -0x5478(r2)
	  lwz       r5, 0xC(r5)
	  addi      r4, r4, 0x94
	  fadds     f31, f2, f0
	  addi      r5, r5, 0x94
	  bl        .loc_0x2D88
	  addi      r3, r1, 0x9A0
	  addi      r4, r1, 0x9AC
	  addi      r5, r13, 0x168
	  bl        -0xC9260
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x330
	  lfs       f28, 0x9A8(r1)
	  addi      r5, r1, 0x32C
	  lwz       r3, 0x3F4(r3)
	  lfs       f29, 0x9A4(r1)
	  addi      r4, r1, 0x328
	  lwz       r3, 0x0(r3)
	  lfs       f30, 0x9A0(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r7, r3, 0x94
	  addi      r3, r1, 0x9B8
	  fsubs     f0, f0, f28
	  stfs      f0, 0x330(r1)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f0, f29
	  stfs      f0, 0x32C(r1)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f0, f30
	  stfs      f0, 0x328(r1)
	  bl        -0x13166C
	  lfs       f1, 0x9B8(r1)
	  lfs       f0, 0x9BC(r1)
	  stfs      f1, 0x994(r1)
	  stfs      f0, 0x998(r1)
	  lfs       f0, 0x9C0(r1)
	  stfs      f0, 0x99C(r1)
	  lfs       f1, 0x994(r1)
	  lfs       f0, 0x998(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x99C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15AB84
	  lfs       f0, -0x54A8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xF68
	  addi      r3, r1, 0x994
	  bl        -0xDF28C

	.loc_0xF68:
	  lfs       f0, 0x994(r1)
	  addi      r6, r1, 0x514
	  addi      r5, r1, 0x510
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x50C
	  addi      r3, r1, 0x9C4
	  stfs      f0, 0x994(r1)
	  lfs       f0, 0x998(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x998(r1)
	  lfs       f0, 0x99C(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x99C(r1)
	  lfs       f1, 0x99C(r1)
	  lfs       f0, 0x994(r1)
	  fadds     f1, f28, f1
	  fadds     f0, f30, f0
	  stfs      f1, 0x514(r1)
	  lfs       f1, 0x998(r1)
	  fadds     f1, f29, f1
	  stfs      f0, 0x50C(r1)
	  stfs      f1, 0x510(r1)
	  bl        -0x131718
	  lwz       r4, 0x20(r31)
	  addi      r6, r1, 0x508
	  lwz       r3, 0x9C4(r1)
	  addi      r5, r1, 0x504
	  lwz       r7, 0x3F4(r4)
	  lwz       r0, 0x9C8(r1)
	  addi      r4, r1, 0x500
	  lwz       r7, 0x0(r7)
	  stw       r3, 0x2BC(r7)
	  addi      r3, r1, 0x9D0
	  stw       r0, 0x2C0(r7)
	  lwz       r0, 0x9CC(r1)
	  stw       r0, 0x2C4(r7)
	  lfs       f1, 0x99C(r1)
	  lfs       f0, 0x994(r1)
	  fsubs     f1, f28, f1
	  fsubs     f0, f30, f0
	  stfs      f1, 0x508(r1)
	  lfs       f1, 0x998(r1)
	  fsubs     f1, f29, f1
	  stfs      f0, 0x500(r1)
	  stfs      f1, 0x504(r1)
	  bl        -0x131774
	  lwz       r5, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0x9D0(r1)
	  lwz       r5, 0x3F4(r5)
	  lwz       r0, 0x9D4(r1)
	  lwz       r5, 0xC(r5)
	  stw       r4, 0x2BC(r5)
	  stw       r0, 0x2C0(r5)
	  lwz       r0, 0x9D8(r1)
	  stw       r0, 0x2C4(r5)
	  bl        -0x2EB4
	  mr        r3, r31
	  bl        -0x2DB8
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x3FC(r3)
	  lwz       r3, 0x3C0(r3)
	  bl        0x125B0
	  b         .loc_0x2D4C

	.loc_0x1068:
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0
	  ble-      .loc_0x1090
	  lwz       r3, 0x3F8(r30)
	  lwz       r3, 0x3BC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x1090
	  li        r0, 0x1
	  b         .loc_0x1094

	.loc_0x1090:
	  li        r0, 0

	.loc_0x1094:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x12AC
	  li        r0, 0x5
	  stw       r0, 0x2E8(r30)
	  li        r0, 0
	  addi      r3, r1, 0x94C
	  lwz       r4, 0x20(r31)
	  stb       r0, 0x2BD(r4)
	  stb       r0, 0x0(r31)
	  lfs       f0, -0x54A8(r2)
	  lwz       r4, 0x20(r31)
	  stfs      f0, 0x2D4(r4)
	  lwz       r5, 0x20(r31)
	  lfs       f0, -0x548C(r2)
	  lwz       r4, 0x224(r5)
	  lwz       r5, 0x3F4(r5)
	  lfs       f1, 0x280(r4)
	  lwz       r4, 0x0(r5)
	  fmuls     f0, f1, f0
	  lfs       f2, -0x5478(r2)
	  lwz       r5, 0xC(r5)
	  addi      r4, r4, 0x94
	  fadds     f31, f2, f0
	  addi      r5, r5, 0x94
	  bl        .loc_0x2D88
	  addi      r3, r1, 0x940
	  addi      r4, r1, 0x94C
	  addi      r5, r13, 0x168
	  bl        -0xC94A4
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x324
	  lfs       f28, 0x948(r1)
	  addi      r5, r1, 0x320
	  lwz       r3, 0x3F4(r3)
	  lfs       f29, 0x944(r1)
	  addi      r4, r1, 0x31C
	  lwz       r3, 0x0(r3)
	  lfs       f30, 0x940(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r7, r3, 0x94
	  addi      r3, r1, 0x958
	  fsubs     f0, f0, f28
	  stfs      f0, 0x324(r1)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f0, f29
	  stfs      f0, 0x320(r1)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f0, f30
	  stfs      f0, 0x31C(r1)
	  bl        -0x1318B0
	  lfs       f1, 0x958(r1)
	  lfs       f0, 0x95C(r1)
	  stfs      f1, 0x934(r1)
	  stfs      f0, 0x938(r1)
	  lfs       f0, 0x960(r1)
	  stfs      f0, 0x93C(r1)
	  lfs       f1, 0x934(r1)
	  lfs       f0, 0x938(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x93C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15ADC8
	  lfs       f0, -0x54A8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x11AC
	  addi      r3, r1, 0x934
	  bl        -0xDF4D0

	.loc_0x11AC:
	  lfs       f0, 0x934(r1)
	  addi      r6, r1, 0x4F4
	  addi      r5, r1, 0x4F0
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x4EC
	  addi      r3, r1, 0x964
	  stfs      f0, 0x934(r1)
	  lfs       f0, 0x938(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x938(r1)
	  lfs       f0, 0x93C(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x93C(r1)
	  lfs       f1, 0x93C(r1)
	  lfs       f0, 0x934(r1)
	  fadds     f1, f28, f1
	  fadds     f0, f30, f0
	  stfs      f1, 0x4F4(r1)
	  lfs       f1, 0x938(r1)
	  fadds     f1, f29, f1
	  stfs      f0, 0x4EC(r1)
	  stfs      f1, 0x4F0(r1)
	  bl        -0x13195C
	  lwz       r4, 0x20(r31)
	  addi      r6, r1, 0x4E8
	  lwz       r3, 0x964(r1)
	  addi      r5, r1, 0x4E4
	  lwz       r7, 0x3F4(r4)
	  lwz       r0, 0x968(r1)
	  addi      r4, r1, 0x4E0
	  lwz       r7, 0x0(r7)
	  stw       r3, 0x2BC(r7)
	  addi      r3, r1, 0x970
	  stw       r0, 0x2C0(r7)
	  lwz       r0, 0x96C(r1)
	  stw       r0, 0x2C4(r7)
	  lfs       f1, 0x93C(r1)
	  lfs       f0, 0x934(r1)
	  fsubs     f1, f28, f1
	  fsubs     f0, f30, f0
	  stfs      f1, 0x4E8(r1)
	  lfs       f1, 0x938(r1)
	  fsubs     f1, f29, f1
	  stfs      f0, 0x4E0(r1)
	  stfs      f1, 0x4E4(r1)
	  bl        -0x1319B8
	  lwz       r5, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0x970(r1)
	  lwz       r5, 0x3F4(r5)
	  lwz       r0, 0x974(r1)
	  lwz       r5, 0xC(r5)
	  stw       r4, 0x2BC(r5)
	  stw       r0, 0x2C0(r5)
	  lwz       r0, 0x978(r1)
	  stw       r0, 0x2C4(r5)
	  bl        -0x30F8
	  mr        r3, r31
	  bl        -0x2FFC
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x3FC(r3)
	  lwz       r3, 0x3C0(r3)
	  bl        0x1236C
	  b         .loc_0x2D4C

	.loc_0x12AC:
	  lwz       r0, 0x3C8(r30)
	  lwz       r3, 0x3F4(r30)
	  rlwinm    r0,r0,2,0,29
	  lfs       f3, 0x300(r30)
	  lwzx      r3, r3, r0
	  lfs       f4, 0x308(r30)
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x9C(r3)
	  bl        -0x130518
	  lwz       r3, 0x224(r30)
	  lfs       f0, 0x68(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x12E8
	  li        r0, 0x1
	  b         .loc_0x12EC

	.loc_0x12E8:
	  li        r0, 0

	.loc_0x12EC:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1330
	  lwz       r3, 0x20(r31)
	  li        r4, 0x4
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x20(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2D4C
	  li        r4, 0x8D
	  bl        -0xC4DCC
	  b         .loc_0x2D4C

	.loc_0x1330:
	  mr        r3, r31
	  bl        -0x248C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x135C
	  lwz       r3, 0x20(r31)
	  li        r4, 0x3
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2BD(r3)
	  b         .loc_0x2D4C

	.loc_0x135C:
	  mr        r3, r31
	  bl        -0x21AC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2D4C
	  lwz       r3, 0x20(r31)
	  li        r4, 0x1
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x20(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2D4C
	  li        r4, 0x8D
	  bl        -0xC4E44
	  b         .loc_0x2D4C
	  mr        r3, r5
	  bl        -0x1A688
	  lwz       r5, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0x224(r5)
	  lfs       f0, 0x220(r4)
	  stfs      f0, 0x3D0(r5)
	  bl        -0x3780
	  mr        r3, r31
	  bl        -0x36A0
	  lwz       r6, 0x20(r31)
	  lwz       r3, 0x3C8(r6)
	  lwz       r0, 0x3CC(r6)
	  lwz       r7, 0x3F4(r6)
	  rlwinm    r4,r3,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x30C(r6)
	  lwzx      r5, r7, r4
	  lwzx      r4, r7, r0
	  lwz       r0, 0x310(r6)
	  stw       r3, 0x2BC(r5)
	  stw       r0, 0x2C0(r5)
	  lwz       r0, 0x314(r6)
	  stw       r0, 0x2C4(r5)
	  lwz       r3, 0x94(r5)
	  lwz       r0, 0x98(r5)
	  stw       r3, 0x2BC(r4)
	  stw       r0, 0x2C0(r4)
	  lwz       r0, 0x9C(r5)
	  stw       r0, 0x2C4(r4)
	  lwz       r3, 0x2DEC(r13)
	  bl        -0xE99EC
	  lwz       r4, 0x20(r31)
	  mr        r3, r31
	  lfs       f0, 0x2D8(r4)
	  fadds     f0, f0, f1
	  stfs      f0, 0x2D8(r4)
	  bl        -0x35F8
	  mr        r3, r31
	  bl        -0x34BC
	  mr        r3, r31
	  bl        -0x33A0
	  lwz       r30, 0x20(r31)
	  lfs       f0, -0x54A8(r2)
	  lfs       f1, 0x2C4(r30)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x147C
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x1E44
	  b         .loc_0x2D4C

	.loc_0x147C:
	  lbz       r0, 0x3C5(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x1490
	  li        r0, 0x1
	  b         .loc_0x1494

	.loc_0x1490:
	  li        r0, 0

	.loc_0x1494:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x16AC
	  li        r0, 0x5
	  stw       r0, 0x2E8(r30)
	  li        r0, 0
	  addi      r3, r1, 0x8BC
	  lwz       r4, 0x20(r31)
	  stb       r0, 0x2BD(r4)
	  stb       r0, 0x0(r31)
	  lfs       f0, -0x54A8(r2)
	  lwz       r4, 0x20(r31)
	  stfs      f0, 0x2D4(r4)
	  lwz       r5, 0x20(r31)
	  lfs       f0, -0x548C(r2)
	  lwz       r4, 0x224(r5)
	  lwz       r5, 0x3F4(r5)
	  lfs       f1, 0x280(r4)
	  lwz       r4, 0x0(r5)
	  fmuls     f0, f1, f0
	  lfs       f2, -0x5478(r2)
	  lwz       r5, 0xC(r5)
	  addi      r4, r4, 0x94
	  fadds     f31, f2, f0
	  addi      r5, r5, 0x94
	  bl        .loc_0x2D88
	  addi      r3, r1, 0x8B0
	  addi      r4, r1, 0x8BC
	  addi      r5, r13, 0x168
	  bl        -0xC98A4
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x310
	  lfs       f28, 0x8B8(r1)
	  addi      r5, r1, 0x30C
	  lwz       r3, 0x3F4(r3)
	  lfs       f29, 0x8B4(r1)
	  addi      r4, r1, 0x308
	  lwz       r3, 0x0(r3)
	  lfs       f30, 0x8B0(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r7, r3, 0x94
	  addi      r3, r1, 0x8C8
	  fsubs     f0, f0, f28
	  stfs      f0, 0x310(r1)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f0, f29
	  stfs      f0, 0x30C(r1)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f0, f30
	  stfs      f0, 0x308(r1)
	  bl        -0x131CB0
	  lfs       f1, 0x8C8(r1)
	  lfs       f0, 0x8CC(r1)
	  stfs      f1, 0x8A4(r1)
	  stfs      f0, 0x8A8(r1)
	  lfs       f0, 0x8D0(r1)
	  stfs      f0, 0x8AC(r1)
	  lfs       f1, 0x8A4(r1)
	  lfs       f0, 0x8A8(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8AC(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15B1C8
	  lfs       f0, -0x54A8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x15AC
	  addi      r3, r1, 0x8A4
	  bl        -0xDF8D0

	.loc_0x15AC:
	  lfs       f0, 0x8A4(r1)
	  addi      r6, r1, 0x4D0
	  addi      r5, r1, 0x4CC
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x4C8
	  addi      r3, r1, 0x8D4
	  stfs      f0, 0x8A4(r1)
	  lfs       f0, 0x8A8(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x8A8(r1)
	  lfs       f0, 0x8AC(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x8AC(r1)
	  lfs       f1, 0x8AC(r1)
	  lfs       f0, 0x8A4(r1)
	  fadds     f1, f28, f1
	  fadds     f0, f30, f0
	  stfs      f1, 0x4D0(r1)
	  lfs       f1, 0x8A8(r1)
	  fadds     f1, f29, f1
	  stfs      f0, 0x4C8(r1)
	  stfs      f1, 0x4CC(r1)
	  bl        -0x131D5C
	  lwz       r4, 0x20(r31)
	  addi      r6, r1, 0x4C4
	  lwz       r3, 0x8D4(r1)
	  addi      r5, r1, 0x4C0
	  lwz       r7, 0x3F4(r4)
	  lwz       r0, 0x8D8(r1)
	  addi      r4, r1, 0x4BC
	  lwz       r7, 0x0(r7)
	  stw       r3, 0x2BC(r7)
	  addi      r3, r1, 0x8E0
	  stw       r0, 0x2C0(r7)
	  lwz       r0, 0x8DC(r1)
	  stw       r0, 0x2C4(r7)
	  lfs       f1, 0x8AC(r1)
	  lfs       f0, 0x8A4(r1)
	  fsubs     f1, f28, f1
	  fsubs     f0, f30, f0
	  stfs      f1, 0x4C4(r1)
	  lfs       f1, 0x8A8(r1)
	  fsubs     f1, f29, f1
	  stfs      f0, 0x4BC(r1)
	  stfs      f1, 0x4C0(r1)
	  bl        -0x131DB8
	  lwz       r5, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0x8E0(r1)
	  lwz       r5, 0x3F4(r5)
	  lwz       r0, 0x8E4(r1)
	  lwz       r5, 0xC(r5)
	  stw       r4, 0x2BC(r5)
	  stw       r0, 0x2C0(r5)
	  lwz       r0, 0x8E8(r1)
	  stw       r0, 0x2C4(r5)
	  bl        -0x34F8
	  mr        r3, r31
	  bl        -0x33FC
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x3FC(r3)
	  lwz       r3, 0x3C0(r3)
	  bl        0x11F6C
	  b         .loc_0x2D4C

	.loc_0x16AC:
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0
	  ble-      .loc_0x16D4
	  lwz       r3, 0x3F8(r30)
	  lwz       r3, 0x3BC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x16D4
	  li        r0, 0x1
	  b         .loc_0x16D8

	.loc_0x16D4:
	  li        r0, 0

	.loc_0x16D8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x18F0
	  li        r0, 0x5
	  stw       r0, 0x2E8(r30)
	  li        r0, 0
	  addi      r3, r1, 0x85C
	  lwz       r4, 0x20(r31)
	  stb       r0, 0x2BD(r4)
	  stb       r0, 0x0(r31)
	  lfs       f0, -0x54A8(r2)
	  lwz       r4, 0x20(r31)
	  stfs      f0, 0x2D4(r4)
	  lwz       r5, 0x20(r31)
	  lfs       f0, -0x548C(r2)
	  lwz       r4, 0x224(r5)
	  lwz       r5, 0x3F4(r5)
	  lfs       f1, 0x280(r4)
	  lwz       r4, 0x0(r5)
	  fmuls     f0, f1, f0
	  lfs       f2, -0x5478(r2)
	  lwz       r5, 0xC(r5)
	  addi      r4, r4, 0x94
	  fadds     f31, f2, f0
	  addi      r5, r5, 0x94
	  bl        .loc_0x2D88
	  addi      r3, r1, 0x850
	  addi      r4, r1, 0x85C
	  addi      r5, r13, 0x168
	  bl        -0xC9AE8
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x304
	  lfs       f28, 0x858(r1)
	  addi      r5, r1, 0x300
	  lwz       r3, 0x3F4(r3)
	  lfs       f29, 0x854(r1)
	  addi      r4, r1, 0x2FC
	  lwz       r3, 0x0(r3)
	  lfs       f30, 0x850(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r7, r3, 0x94
	  addi      r3, r1, 0x868
	  fsubs     f0, f0, f28
	  stfs      f0, 0x304(r1)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f0, f29
	  stfs      f0, 0x300(r1)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f0, f30
	  stfs      f0, 0x2FC(r1)
	  bl        -0x131EF4
	  lfs       f1, 0x868(r1)
	  lfs       f0, 0x86C(r1)
	  stfs      f1, 0x844(r1)
	  stfs      f0, 0x848(r1)
	  lfs       f0, 0x870(r1)
	  stfs      f0, 0x84C(r1)
	  lfs       f1, 0x844(r1)
	  lfs       f0, 0x848(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x84C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15B40C
	  lfs       f0, -0x54A8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x17F0
	  addi      r3, r1, 0x844
	  bl        -0xDFB14

	.loc_0x17F0:
	  lfs       f0, 0x844(r1)
	  addi      r6, r1, 0x4B0
	  addi      r5, r1, 0x4AC
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x4A8
	  addi      r3, r1, 0x874
	  stfs      f0, 0x844(r1)
	  lfs       f0, 0x848(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x848(r1)
	  lfs       f0, 0x84C(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x84C(r1)
	  lfs       f1, 0x84C(r1)
	  lfs       f0, 0x844(r1)
	  fadds     f1, f28, f1
	  fadds     f0, f30, f0
	  stfs      f1, 0x4B0(r1)
	  lfs       f1, 0x848(r1)
	  fadds     f1, f29, f1
	  stfs      f0, 0x4A8(r1)
	  stfs      f1, 0x4AC(r1)
	  bl        -0x131FA0
	  lwz       r4, 0x20(r31)
	  addi      r6, r1, 0x4A4
	  lwz       r3, 0x874(r1)
	  addi      r5, r1, 0x4A0
	  lwz       r7, 0x3F4(r4)
	  lwz       r0, 0x878(r1)
	  addi      r4, r1, 0x49C
	  lwz       r7, 0x0(r7)
	  stw       r3, 0x2BC(r7)
	  addi      r3, r1, 0x880
	  stw       r0, 0x2C0(r7)
	  lwz       r0, 0x87C(r1)
	  stw       r0, 0x2C4(r7)
	  lfs       f1, 0x84C(r1)
	  lfs       f0, 0x844(r1)
	  fsubs     f1, f28, f1
	  fsubs     f0, f30, f0
	  stfs      f1, 0x4A4(r1)
	  lfs       f1, 0x848(r1)
	  fsubs     f1, f29, f1
	  stfs      f0, 0x49C(r1)
	  stfs      f1, 0x4A0(r1)
	  bl        -0x131FFC
	  lwz       r5, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0x880(r1)
	  lwz       r5, 0x3F4(r5)
	  lwz       r0, 0x884(r1)
	  lwz       r5, 0xC(r5)
	  stw       r4, 0x2BC(r5)
	  stw       r0, 0x2C0(r5)
	  lwz       r0, 0x888(r1)
	  stw       r0, 0x2C4(r5)
	  bl        -0x373C
	  mr        r3, r31
	  bl        -0x3640
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x3FC(r3)
	  lwz       r3, 0x3C0(r3)
	  bl        0x11D28
	  b         .loc_0x2D4C

	.loc_0x18F0:
	  lwz       r0, 0x3C8(r30)
	  lwz       r3, 0x3F4(r30)
	  rlwinm    r0,r0,2,0,29
	  lfs       f3, 0x300(r30)
	  lwzx      r3, r3, r0
	  lfs       f4, 0x308(r30)
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x9C(r3)
	  bl        -0x130B5C
	  lwz       r3, 0x224(r30)
	  lfs       f0, 0x68(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x192C
	  li        r0, 0x1
	  b         .loc_0x1930

	.loc_0x192C:
	  li        r0, 0

	.loc_0x1930:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1974
	  lwz       r3, 0x20(r31)
	  li        r4, 0x4
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x20(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2D4C
	  li        r4, 0x8D
	  bl        -0xC5410
	  b         .loc_0x2D4C

	.loc_0x1974:
	  mr        r3, r31
	  bl        -0x2DD8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19A0
	  lwz       r3, 0x20(r31)
	  li        r4, 0x2
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2BD(r3)
	  b         .loc_0x2D4C

	.loc_0x19A0:
	  mr        r3, r31
	  bl        -0x2AFC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x19CC
	  lwz       r3, 0x20(r31)
	  li        r4, 0x3
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2BD(r3)
	  b         .loc_0x2D4C

	.loc_0x19CC:
	  mr        r3, r31
	  bl        -0x281C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2D4C
	  lwz       r3, 0x20(r31)
	  li        r4, 0x1
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x20(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2D4C
	  li        r4, 0x8D
	  bl        -0xC54B4
	  b         .loc_0x2D4C
	  lwz       r4, 0x300(r5)
	  mr        r3, r31
	  lwz       r0, 0x304(r5)
	  stw       r4, 0x30C(r5)
	  stw       r0, 0x310(r5)
	  lwz       r0, 0x308(r5)
	  stw       r0, 0x314(r5)
	  lwz       r5, 0x20(r31)
	  lwz       r4, 0x224(r5)
	  lfs       f0, 0x220(r4)
	  stfs      f0, 0x3D0(r5)
	  bl        -0x3E00
	  mr        r3, r31
	  bl        -0x3D20
	  lwz       r6, 0x20(r31)
	  lwz       r3, 0x3C8(r6)
	  lwz       r0, 0x3CC(r6)
	  lwz       r7, 0x3F4(r6)
	  rlwinm    r4,r3,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x30C(r6)
	  lwzx      r5, r7, r4
	  lwzx      r4, r7, r0
	  lwz       r0, 0x310(r6)
	  stw       r3, 0x2BC(r5)
	  stw       r0, 0x2C0(r5)
	  lwz       r0, 0x314(r6)
	  stw       r0, 0x2C4(r5)
	  lwz       r3, 0x94(r5)
	  lwz       r0, 0x98(r5)
	  stw       r3, 0x2BC(r4)
	  stw       r0, 0x2C0(r4)
	  lwz       r0, 0x9C(r5)
	  stw       r0, 0x2C4(r4)
	  lwz       r3, 0x2DEC(r13)
	  bl        -0xEA06C
	  lwz       r4, 0x20(r31)
	  mr        r3, r31
	  lfs       f0, 0x2D8(r4)
	  fadds     f0, f0, f1
	  stfs      f0, 0x2D8(r4)
	  bl        -0x3C78
	  mr        r3, r31
	  bl        -0x3B3C
	  mr        r3, r31
	  bl        -0x3A20
	  lwz       r30, 0x20(r31)
	  lfs       f0, -0x54A8(r2)
	  lfs       f1, 0x2C4(r30)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x1AFC
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x24C4
	  b         .loc_0x2D4C

	.loc_0x1AFC:
	  lbz       r0, 0x3C5(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x1B10
	  li        r0, 0x1
	  b         .loc_0x1B14

	.loc_0x1B10:
	  li        r0, 0

	.loc_0x1B14:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1D2C
	  li        r0, 0x5
	  stw       r0, 0x2E8(r30)
	  li        r0, 0
	  addi      r3, r1, 0x7BC
	  lwz       r4, 0x20(r31)
	  stb       r0, 0x2BD(r4)
	  stb       r0, 0x0(r31)
	  lfs       f0, -0x54A8(r2)
	  lwz       r4, 0x20(r31)
	  stfs      f0, 0x2D4(r4)
	  lwz       r5, 0x20(r31)
	  lfs       f0, -0x548C(r2)
	  lwz       r4, 0x224(r5)
	  lwz       r5, 0x3F4(r5)
	  lfs       f1, 0x280(r4)
	  lwz       r4, 0x0(r5)
	  fmuls     f0, f1, f0
	  lfs       f2, -0x5478(r2)
	  lwz       r5, 0xC(r5)
	  addi      r4, r4, 0x94
	  fadds     f31, f2, f0
	  addi      r5, r5, 0x94
	  bl        .loc_0x2D88
	  addi      r3, r1, 0x7B0
	  addi      r4, r1, 0x7BC
	  addi      r5, r13, 0x168
	  bl        -0xC9F24
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x2F0
	  lfs       f28, 0x7B8(r1)
	  addi      r5, r1, 0x2EC
	  lwz       r3, 0x3F4(r3)
	  lfs       f29, 0x7B4(r1)
	  addi      r4, r1, 0x2E8
	  lwz       r3, 0x0(r3)
	  lfs       f30, 0x7B0(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r7, r3, 0x94
	  addi      r3, r1, 0x7C8
	  fsubs     f0, f0, f28
	  stfs      f0, 0x2F0(r1)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f0, f29
	  stfs      f0, 0x2EC(r1)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f0, f30
	  stfs      f0, 0x2E8(r1)
	  bl        -0x132330
	  lfs       f1, 0x7C8(r1)
	  lfs       f0, 0x7CC(r1)
	  stfs      f1, 0x7A4(r1)
	  stfs      f0, 0x7A8(r1)
	  lfs       f0, 0x7D0(r1)
	  stfs      f0, 0x7AC(r1)
	  lfs       f1, 0x7A4(r1)
	  lfs       f0, 0x7A8(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x7AC(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15B848
	  lfs       f0, -0x54A8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1C2C
	  addi      r3, r1, 0x7A4
	  bl        -0xDFF50

	.loc_0x1C2C:
	  lfs       f0, 0x7A4(r1)
	  addi      r6, r1, 0x488
	  addi      r5, r1, 0x484
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x480
	  addi      r3, r1, 0x7D4
	  stfs      f0, 0x7A4(r1)
	  lfs       f0, 0x7A8(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x7A8(r1)
	  lfs       f0, 0x7AC(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x7AC(r1)
	  lfs       f1, 0x7AC(r1)
	  lfs       f0, 0x7A4(r1)
	  fadds     f1, f28, f1
	  fadds     f0, f30, f0
	  stfs      f1, 0x488(r1)
	  lfs       f1, 0x7A8(r1)
	  fadds     f1, f29, f1
	  stfs      f0, 0x480(r1)
	  stfs      f1, 0x484(r1)
	  bl        -0x1323DC
	  lwz       r4, 0x20(r31)
	  addi      r6, r1, 0x47C
	  lwz       r3, 0x7D4(r1)
	  addi      r5, r1, 0x478
	  lwz       r7, 0x3F4(r4)
	  lwz       r0, 0x7D8(r1)
	  addi      r4, r1, 0x474
	  lwz       r7, 0x0(r7)
	  stw       r3, 0x2BC(r7)
	  addi      r3, r1, 0x7E0
	  stw       r0, 0x2C0(r7)
	  lwz       r0, 0x7DC(r1)
	  stw       r0, 0x2C4(r7)
	  lfs       f1, 0x7AC(r1)
	  lfs       f0, 0x7A4(r1)
	  fsubs     f1, f28, f1
	  fsubs     f0, f30, f0
	  stfs      f1, 0x47C(r1)
	  lfs       f1, 0x7A8(r1)
	  fsubs     f1, f29, f1
	  stfs      f0, 0x474(r1)
	  stfs      f1, 0x478(r1)
	  bl        -0x132438
	  lwz       r5, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0x7E0(r1)
	  lwz       r5, 0x3F4(r5)
	  lwz       r0, 0x7E4(r1)
	  lwz       r5, 0xC(r5)
	  stw       r4, 0x2BC(r5)
	  stw       r0, 0x2C0(r5)
	  lwz       r0, 0x7E8(r1)
	  stw       r0, 0x2C4(r5)
	  bl        -0x3B78
	  mr        r3, r31
	  bl        -0x3A7C
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x3FC(r3)
	  lwz       r3, 0x3C0(r3)
	  bl        0x118EC
	  b         .loc_0x2D4C

	.loc_0x1D2C:
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0
	  ble-      .loc_0x1D54
	  lwz       r3, 0x3F8(r30)
	  lwz       r3, 0x3BC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x1D54
	  li        r0, 0x1
	  b         .loc_0x1D58

	.loc_0x1D54:
	  li        r0, 0

	.loc_0x1D58:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1F70
	  li        r0, 0x5
	  stw       r0, 0x2E8(r30)
	  li        r0, 0
	  addi      r3, r1, 0x75C
	  lwz       r4, 0x20(r31)
	  stb       r0, 0x2BD(r4)
	  stb       r0, 0x0(r31)
	  lfs       f0, -0x54A8(r2)
	  lwz       r4, 0x20(r31)
	  stfs      f0, 0x2D4(r4)
	  lwz       r5, 0x20(r31)
	  lfs       f0, -0x548C(r2)
	  lwz       r4, 0x224(r5)
	  lwz       r5, 0x3F4(r5)
	  lfs       f1, 0x280(r4)
	  lwz       r4, 0x0(r5)
	  fmuls     f0, f1, f0
	  lfs       f2, -0x5478(r2)
	  lwz       r5, 0xC(r5)
	  addi      r4, r4, 0x94
	  fadds     f31, f2, f0
	  addi      r5, r5, 0x94
	  bl        .loc_0x2D88
	  addi      r3, r1, 0x750
	  addi      r4, r1, 0x75C
	  addi      r5, r13, 0x168
	  bl        -0xCA168
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x2E4
	  lfs       f28, 0x758(r1)
	  addi      r5, r1, 0x2E0
	  lwz       r3, 0x3F4(r3)
	  lfs       f29, 0x754(r1)
	  addi      r4, r1, 0x2DC
	  lwz       r3, 0x0(r3)
	  lfs       f30, 0x750(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r7, r3, 0x94
	  addi      r3, r1, 0x768
	  fsubs     f0, f0, f28
	  stfs      f0, 0x2E4(r1)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f0, f29
	  stfs      f0, 0x2E0(r1)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f0, f30
	  stfs      f0, 0x2DC(r1)
	  bl        -0x132574
	  lfs       f1, 0x768(r1)
	  lfs       f0, 0x76C(r1)
	  stfs      f1, 0x744(r1)
	  stfs      f0, 0x748(r1)
	  lfs       f0, 0x770(r1)
	  stfs      f0, 0x74C(r1)
	  lfs       f1, 0x744(r1)
	  lfs       f0, 0x748(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x74C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15BA8C
	  lfs       f0, -0x54A8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1E70
	  addi      r3, r1, 0x744
	  bl        -0xE0194

	.loc_0x1E70:
	  lfs       f0, 0x744(r1)
	  addi      r6, r1, 0x468
	  addi      r5, r1, 0x464
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x460
	  addi      r3, r1, 0x774
	  stfs      f0, 0x744(r1)
	  lfs       f0, 0x748(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x748(r1)
	  lfs       f0, 0x74C(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x74C(r1)
	  lfs       f1, 0x74C(r1)
	  lfs       f0, 0x744(r1)
	  fadds     f1, f28, f1
	  fadds     f0, f30, f0
	  stfs      f1, 0x468(r1)
	  lfs       f1, 0x748(r1)
	  fadds     f1, f29, f1
	  stfs      f0, 0x460(r1)
	  stfs      f1, 0x464(r1)
	  bl        -0x132620
	  lwz       r4, 0x20(r31)
	  addi      r6, r1, 0x45C
	  lwz       r3, 0x774(r1)
	  addi      r5, r1, 0x458
	  lwz       r7, 0x3F4(r4)
	  lwz       r0, 0x778(r1)
	  addi      r4, r1, 0x454
	  lwz       r7, 0x0(r7)
	  stw       r3, 0x2BC(r7)
	  addi      r3, r1, 0x780
	  stw       r0, 0x2C0(r7)
	  lwz       r0, 0x77C(r1)
	  stw       r0, 0x2C4(r7)
	  lfs       f1, 0x74C(r1)
	  lfs       f0, 0x744(r1)
	  fsubs     f1, f28, f1
	  fsubs     f0, f30, f0
	  stfs      f1, 0x45C(r1)
	  lfs       f1, 0x748(r1)
	  fsubs     f1, f29, f1
	  stfs      f0, 0x454(r1)
	  stfs      f1, 0x458(r1)
	  bl        -0x13267C
	  lwz       r5, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0x780(r1)
	  lwz       r5, 0x3F4(r5)
	  lwz       r0, 0x784(r1)
	  lwz       r5, 0xC(r5)
	  stw       r4, 0x2BC(r5)
	  stw       r0, 0x2C0(r5)
	  lwz       r0, 0x788(r1)
	  stw       r0, 0x2C4(r5)
	  bl        -0x3DBC
	  mr        r3, r31
	  bl        -0x3CC0
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x3FC(r3)
	  lwz       r3, 0x3C0(r3)
	  bl        0x116A8
	  b         .loc_0x2D4C

	.loc_0x1F70:
	  lwz       r0, 0x3CC(r30)
	  lwz       r3, 0x3F4(r30)
	  rlwinm    r0,r0,2,0,29
	  lfs       f3, 0x300(r30)
	  lwzx      r3, r3, r0
	  lfs       f4, 0x308(r30)
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x9C(r3)
	  bl        -0x1311DC
	  lwz       r3, 0x224(r30)
	  lfs       f0, 0x78(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1FAC
	  li        r0, 0x1
	  b         .loc_0x1FB0

	.loc_0x1FAC:
	  li        r0, 0

	.loc_0x1FB0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x2D4C
	  lwz       r3, 0x20(r31)
	  li        r4, 0x1
	  li        r0, 0
	  stw       r4, 0x2E8(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x20(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2D4C
	  li        r4, 0x8D
	  bl        -0xC5A90
	  b         .loc_0x2D4C
	  lfs       f0, -0x54A8(r2)
	  addi      r6, r1, 0x450
	  addi      r5, r1, 0x44C
	  stfs      f0, 0x720(r1)
	  addi      r4, r1, 0x448
	  addi      r3, r1, 0x718
	  stfs      f0, 0x71C(r1)
	  stfs      f0, 0x718(r1)
	  lwz       r8, 0x20(r31)
	  lwz       r7, 0x3F4(r8)
	  lwz       r8, 0x224(r8)
	  lwz       r7, 0x0(r7)
	  lfs       f1, 0x310(r8)
	  lfsu      f0, 0x70(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x8(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r7)
	  lwz       r7, 0x20(r31)
	  lwz       r7, 0x3F4(r7)
	  lwz       r7, 0x0(r7)
	  addi      r8, r7, 0x94
	  addi      r7, r7, 0x2BC
	  lfs       f0, 0x8(r8)
	  lfs       f1, 0x8(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x450(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x44C(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x448(r1)
	  bl        -0x1327E8
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x444
	  lfs       f0, 0x718(r1)
	  addi      r5, r1, 0x440
	  lwz       r3, 0x224(r3)
	  addi      r4, r1, 0x43C
	  lfs       f1, 0x320(r3)
	  addi      r3, r1, 0x718
	  fmuls     f0, f0, f1
	  stfs      f0, 0x718(r1)
	  lfs       f0, 0x71C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x71C(r1)
	  lfs       f0, 0x720(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x720(r1)
	  lwz       r7, 0x20(r31)
	  lfs       f0, 0x718(r1)
	  lwz       r7, 0x3F4(r7)
	  lwz       r7, 0x0(r7)
	  lfsu      f1, 0x70(r7)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r7)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x71C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r7)
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x720(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r7)
	  lwz       r8, 0x20(r31)
	  lwz       r7, 0x3F4(r8)
	  lwz       r8, 0x224(r8)
	  lwz       r7, 0xC(r7)
	  lfs       f1, 0x310(r8)
	  lfsu      f0, 0x70(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x8(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r7)
	  lwz       r7, 0x20(r31)
	  lwz       r7, 0x3F4(r7)
	  lwz       r7, 0xC(r7)
	  addi      r8, r7, 0x94
	  addi      r7, r7, 0x2BC
	  lfs       f0, 0x8(r8)
	  lfs       f1, 0x8(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x444(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x440(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x43C(r1)
	  bl        -0x1328E4
	  lwz       r4, 0x20(r31)
	  mr        r3, r31
	  lfs       f0, 0x718(r1)
	  lwz       r4, 0x224(r4)
	  lfs       f1, 0x320(r4)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x718(r1)
	  lfs       f0, 0x71C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x71C(r1)
	  lfs       f0, 0x720(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x720(r1)
	  lwz       r4, 0x20(r31)
	  lfs       f0, 0x718(r1)
	  lwz       r4, 0x3F4(r4)
	  lwz       r4, 0xC(r4)
	  lfsu      f1, 0x70(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r4)
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x71C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r4)
	  lfs       f1, 0x8(r4)
	  lfs       f0, 0x720(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r4)
	  lwz       r5, 0x20(r31)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x2D4(r5)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D4(r5)
	  bl        -0x416C
	  lwz       r3, 0x20(r31)
	  lfs       f0, -0x54A8(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x2248
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x2C10
	  b         .loc_0x2D4C

	.loc_0x2248:
	  lbz       r0, 0x0(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x2264
	  lfs       f1, 0x2D4(r3)
	  lfs       f0, -0x5460(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x226C

	.loc_0x2264:
	  li        r0, 0x1
	  b         .loc_0x2270

	.loc_0x226C:
	  li        r0, 0

	.loc_0x2270:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x2D4C
	  li        r0, 0x6
	  stw       r0, 0x2E8(r3)
	  li        r5, 0
	  li        r0, 0x1
	  lwz       r4, 0x20(r31)
	  addi      r3, r1, 0x6CC
	  stb       r5, 0x2BD(r4)
	  lwz       r4, 0x20(r31)
	  stb       r5, 0x3C5(r4)
	  lwz       r4, 0x20(r31)
	  stb       r0, 0x3C4(r4)
	  lfs       f0, -0x54A8(r2)
	  lwz       r4, 0x20(r31)
	  stfs      f0, 0x2D4(r4)
	  lwz       r5, 0x20(r31)
	  lfs       f0, -0x548C(r2)
	  lwz       r4, 0x224(r5)
	  lwz       r5, 0x3F4(r5)
	  lfs       f1, 0x280(r4)
	  lwz       r4, 0x0(r5)
	  fmuls     f0, f1, f0
	  lfs       f2, -0x547C(r2)
	  lwz       r5, 0xC(r5)
	  addi      r4, r4, 0x2BC
	  fadds     f31, f2, f0
	  addi      r5, r5, 0x2BC
	  bl        .loc_0x2D88
	  addi      r3, r1, 0x6C0
	  addi      r4, r1, 0x6CC
	  addi      r5, r13, 0x16C
	  bl        -0xCA690
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x2C8
	  lfs       f28, 0x6C8(r1)
	  addi      r5, r1, 0x2C4
	  lwz       r3, 0x3F4(r3)
	  lfs       f29, 0x6C4(r1)
	  addi      r4, r1, 0x2C0
	  lwz       r3, 0x0(r3)
	  lfs       f30, 0x6C0(r1)
	  lfs       f0, 0x2C4(r3)
	  addi      r7, r3, 0x2BC
	  addi      r3, r1, 0x6D8
	  fsubs     f0, f0, f28
	  stfs      f0, 0x2C8(r1)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f0, f29
	  stfs      f0, 0x2C4(r1)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f0, f30
	  stfs      f0, 0x2C0(r1)
	  bl        -0x132A9C
	  lfs       f1, 0x6D8(r1)
	  lfs       f0, 0x6DC(r1)
	  stfs      f1, 0x6B4(r1)
	  stfs      f0, 0x6B8(r1)
	  lfs       f0, 0x6E0(r1)
	  stfs      f0, 0x6BC(r1)
	  lfs       f1, 0x6B4(r1)
	  lfs       f0, 0x6B8(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x6BC(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15BFB4
	  lfs       f0, -0x54A8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2398
	  addi      r3, r1, 0x6B4
	  bl        -0xE06BC

	.loc_0x2398:
	  lfs       f0, 0x6B4(r1)
	  addi      r6, r1, 0x42C
	  addi      r5, r1, 0x428
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x424
	  addi      r3, r1, 0x6E4
	  stfs      f0, 0x6B4(r1)
	  lfs       f0, 0x6B8(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x6B8(r1)
	  lfs       f0, 0x6BC(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x6BC(r1)
	  lfs       f1, 0x6BC(r1)
	  lfs       f0, 0x6B4(r1)
	  fadds     f1, f28, f1
	  fadds     f0, f30, f0
	  stfs      f1, 0x42C(r1)
	  lfs       f1, 0x6B8(r1)
	  fadds     f1, f29, f1
	  stfs      f0, 0x424(r1)
	  stfs      f1, 0x428(r1)
	  bl        -0x132B48
	  lwz       r4, 0x20(r31)
	  addi      r6, r1, 0x420
	  lwz       r3, 0x6E4(r1)
	  addi      r5, r1, 0x41C
	  lwz       r7, 0x3F4(r4)
	  lwz       r0, 0x6E8(r1)
	  addi      r4, r1, 0x418
	  lwz       r7, 0x0(r7)
	  stw       r3, 0x2BC(r7)
	  addi      r3, r1, 0x6F0
	  stw       r0, 0x2C0(r7)
	  lwz       r0, 0x6EC(r1)
	  stw       r0, 0x2C4(r7)
	  lfs       f1, 0x6BC(r1)
	  lfs       f0, 0x6B4(r1)
	  fsubs     f1, f28, f1
	  fsubs     f0, f30, f0
	  stfs      f1, 0x420(r1)
	  lfs       f1, 0x6B8(r1)
	  fsubs     f1, f29, f1
	  stfs      f0, 0x418(r1)
	  stfs      f1, 0x41C(r1)
	  bl        -0x132BA4
	  lwz       r4, 0x20(r31)
	  lwz       r3, 0x6F0(r1)
	  lwz       r4, 0x3F4(r4)
	  lwz       r0, 0x6F4(r1)
	  lwz       r4, 0xC(r4)
	  stw       r3, 0x2BC(r4)
	  stw       r0, 0x2C0(r4)
	  lwz       r0, 0x6F8(r1)
	  stw       r0, 0x2C4(r4)
	  b         .loc_0x2D4C
	  lfs       f0, -0x54A8(r2)
	  addi      r6, r1, 0x414
	  addi      r5, r1, 0x410
	  stfs      f0, 0x6A4(r1)
	  addi      r4, r1, 0x40C
	  addi      r3, r1, 0x69C
	  stfs      f0, 0x6A0(r1)
	  stfs      f0, 0x69C(r1)
	  lwz       r8, 0x20(r31)
	  lwz       r7, 0x3F4(r8)
	  lwz       r8, 0x224(r8)
	  lwz       r7, 0x0(r7)
	  lfs       f1, 0x310(r8)
	  lfsu      f0, 0x70(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x8(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r7)
	  lwz       r7, 0x20(r31)
	  lwz       r7, 0x3F4(r7)
	  lwz       r7, 0x0(r7)
	  addi      r8, r7, 0x94
	  addi      r7, r7, 0x2BC
	  lfs       f0, 0x8(r8)
	  lfs       f1, 0x8(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x414(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x410(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x40C(r1)
	  bl        -0x132C6C
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x408
	  lfs       f0, 0x69C(r1)
	  addi      r5, r1, 0x404
	  lwz       r3, 0x224(r3)
	  addi      r4, r1, 0x400
	  lfs       f1, 0x320(r3)
	  addi      r3, r1, 0x69C
	  fmuls     f0, f0, f1
	  stfs      f0, 0x69C(r1)
	  lfs       f0, 0x6A0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x6A0(r1)
	  lfs       f0, 0x6A4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x6A4(r1)
	  lwz       r7, 0x20(r31)
	  lfs       f0, 0x69C(r1)
	  lwz       r7, 0x3F4(r7)
	  lwz       r7, 0x0(r7)
	  lfsu      f1, 0x70(r7)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r7)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x6A0(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r7)
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x6A4(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r7)
	  lwz       r8, 0x20(r31)
	  lwz       r7, 0x3F4(r8)
	  lwz       r8, 0x224(r8)
	  lwz       r7, 0xC(r7)
	  lfs       f1, 0x310(r8)
	  lfsu      f0, 0x70(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x8(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r7)
	  lwz       r7, 0x20(r31)
	  lwz       r7, 0x3F4(r7)
	  lwz       r7, 0xC(r7)
	  addi      r8, r7, 0x94
	  addi      r7, r7, 0x2BC
	  lfs       f0, 0x8(r8)
	  lfs       f1, 0x8(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x408(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x404(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x400(r1)
	  bl        -0x132D68
	  lwz       r4, 0x20(r31)
	  mr        r3, r31
	  lfs       f0, 0x69C(r1)
	  lwz       r4, 0x224(r4)
	  lfs       f1, 0x320(r4)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x69C(r1)
	  lfs       f0, 0x6A0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x6A0(r1)
	  lfs       f0, 0x6A4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x6A4(r1)
	  lwz       r4, 0x20(r31)
	  lfs       f0, 0x69C(r1)
	  lwz       r4, 0x3F4(r4)
	  lwz       r4, 0xC(r4)
	  lfsu      f1, 0x70(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r4)
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x6A0(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r4)
	  lfs       f1, 0x8(r4)
	  lfs       f0, 0x6A4(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r4)
	  lwz       r5, 0x20(r31)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x2D4(r5)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D4(r5)
	  bl        -0x45F0
	  lwz       r3, 0x20(r31)
	  lfs       f0, -0x54A8(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x26CC
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x3094
	  b         .loc_0x2D4C

	.loc_0x26CC:
	  lbz       r0, 0x3C5(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x26E0
	  li        r0, 0x1
	  b         .loc_0x26E4

	.loc_0x26E0:
	  li        r0, 0

	.loc_0x26E4:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x28FC
	  li        r0, 0x5
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  addi      r3, r1, 0x654
	  lwz       r4, 0x20(r31)
	  stb       r0, 0x2BD(r4)
	  stb       r0, 0x0(r31)
	  lfs       f0, -0x54A8(r2)
	  lwz       r4, 0x20(r31)
	  stfs      f0, 0x2D4(r4)
	  lwz       r5, 0x20(r31)
	  lfs       f0, -0x548C(r2)
	  lwz       r4, 0x224(r5)
	  lwz       r5, 0x3F4(r5)
	  lfs       f1, 0x280(r4)
	  lwz       r4, 0x0(r5)
	  fmuls     f0, f1, f0
	  lfs       f2, -0x5478(r2)
	  lwz       r5, 0xC(r5)
	  addi      r4, r4, 0x94
	  fadds     f31, f2, f0
	  addi      r5, r5, 0x94
	  bl        .loc_0x2D88
	  addi      r3, r1, 0x648
	  addi      r4, r1, 0x654
	  addi      r5, r13, 0x168
	  bl        -0xCAAF4
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x2AC
	  lfs       f28, 0x650(r1)
	  addi      r5, r1, 0x2A8
	  lwz       r3, 0x3F4(r3)
	  lfs       f29, 0x64C(r1)
	  addi      r4, r1, 0x2A4
	  lwz       r3, 0x0(r3)
	  lfs       f30, 0x648(r1)
	  lfs       f0, 0x9C(r3)
	  addi      r7, r3, 0x94
	  addi      r3, r1, 0x660
	  fsubs     f0, f0, f28
	  stfs      f0, 0x2AC(r1)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f0, f29
	  stfs      f0, 0x2A8(r1)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f0, f30
	  stfs      f0, 0x2A4(r1)
	  bl        -0x132F00
	  lfs       f1, 0x660(r1)
	  lfs       f0, 0x664(r1)
	  stfs      f1, 0x63C(r1)
	  stfs      f0, 0x640(r1)
	  lfs       f0, 0x668(r1)
	  stfs      f0, 0x644(r1)
	  lfs       f1, 0x63C(r1)
	  lfs       f0, 0x640(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x644(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15C418
	  lfs       f0, -0x54A8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x27FC
	  addi      r3, r1, 0x63C
	  bl        -0xE0B20

	.loc_0x27FC:
	  lfs       f0, 0x63C(r1)
	  addi      r6, r1, 0x3F0
	  addi      r5, r1, 0x3EC
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x3E8
	  addi      r3, r1, 0x66C
	  stfs      f0, 0x63C(r1)
	  lfs       f0, 0x640(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x640(r1)
	  lfs       f0, 0x644(r1)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x644(r1)
	  lfs       f1, 0x644(r1)
	  lfs       f0, 0x63C(r1)
	  fadds     f1, f28, f1
	  fadds     f0, f30, f0
	  stfs      f1, 0x3F0(r1)
	  lfs       f1, 0x640(r1)
	  fadds     f1, f29, f1
	  stfs      f0, 0x3E8(r1)
	  stfs      f1, 0x3EC(r1)
	  bl        -0x132FAC
	  lwz       r4, 0x20(r31)
	  addi      r6, r1, 0x3E4
	  lwz       r3, 0x66C(r1)
	  addi      r5, r1, 0x3E0
	  lwz       r7, 0x3F4(r4)
	  lwz       r0, 0x670(r1)
	  addi      r4, r1, 0x3DC
	  lwz       r7, 0x0(r7)
	  stw       r3, 0x2BC(r7)
	  addi      r3, r1, 0x678
	  stw       r0, 0x2C0(r7)
	  lwz       r0, 0x674(r1)
	  stw       r0, 0x2C4(r7)
	  lfs       f1, 0x644(r1)
	  lfs       f0, 0x63C(r1)
	  fsubs     f1, f28, f1
	  fsubs     f0, f30, f0
	  stfs      f1, 0x3E4(r1)
	  lfs       f1, 0x640(r1)
	  fsubs     f1, f29, f1
	  stfs      f0, 0x3DC(r1)
	  stfs      f1, 0x3E0(r1)
	  bl        -0x133008
	  lwz       r5, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0x678(r1)
	  lwz       r5, 0x3F4(r5)
	  lwz       r0, 0x67C(r1)
	  lwz       r5, 0xC(r5)
	  stw       r4, 0x2BC(r5)
	  stw       r0, 0x2C0(r5)
	  lwz       r0, 0x680(r1)
	  stw       r0, 0x2C4(r5)
	  bl        -0x4748
	  mr        r3, r31
	  bl        -0x464C
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x3FC(r3)
	  lwz       r3, 0x3C0(r3)
	  bl        0x10D1C
	  b         .loc_0x2D4C

	.loc_0x28FC:
	  lfs       f1, 0x2D4(r3)
	  lfs       f0, -0x54A0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2914
	  li        r0, 0x1
	  b         .loc_0x2918

	.loc_0x2914:
	  li        r0, 0

	.loc_0x2918:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x2D4C
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x20(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2D4C
	  li        r4, 0x8D
	  bl        -0xC63F4
	  b         .loc_0x2D4C
	  mr        r3, r31
	  bl        -0x3610
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2D4C
	  lwz       r3, 0x20(r31)
	  li        r0, 0x8
	  li        r4, 0
	  stw       r0, 0x2E8(r3)
	  li        r0, 0x1
	  lwz       r3, 0x20(r31)
	  stb       r4, 0x2BD(r3)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x3C4(r3)
	  lfs       f0, -0x54A8(r2)
	  lwz       r3, 0x20(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x20(r31)
	  stfs      f0, 0x2D0(r3)
	  lfs       f0, -0x548C(r2)
	  lwz       r3, 0x20(r31)
	  stfs      f0, 0x2D8(r3)
	  lwz       r3, 0x3120(r13)
	  bl        -0x52E60
	  lwz       r4, 0x20(r31)
	  lfs       f3, 0x94(r3)
	  lfs       f1, 0x94(r4)
	  lfs       f2, 0x9C(r3)
	  lfs       f0, 0x9C(r4)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0xB17B4
	  lwz       r3, 0x20(r31)
	  fmr       f30, f1
	  lfs       f2, -0x5474(r2)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x280(r3)
	  fadds     f29, f2, f0
	  bl        0xB18F4
	  fmr       f28, f1
	  fmr       f1, f30
	  bl        0xB1A7C
	  lfs       f2, 0x170(r13)
	  fmuls     f0, f1, f29
	  fmuls     f3, f28, f29
	  addi      r6, r1, 0x2A0
	  fmuls     f1, f2, f29
	  stfs      f0, 0x298(r1)
	  addi      r5, r1, 0x29C
	  stfs      f3, 0x2A0(r1)
	  addi      r4, r1, 0x298
	  addi      r3, r1, 0x600
	  stfs      f1, 0x29C(r1)
	  bl        -0x133180
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x3D0
	  lfs       f0, 0x608(r1)
	  addi      r5, r1, 0x3CC
	  lfs       f2, 0x308(r3)
	  addi      r7, r3, 0x300
	  lfs       f1, 0x604(r1)
	  fadds     f2, f2, f0
	  lfs       f0, 0x600(r1)
	  addi      r4, r1, 0x3C8
	  addi      r3, r1, 0x5F4
	  stfs      f2, 0x3D0(r1)
	  lfs       f2, 0x4(r7)
	  fadds     f1, f2, f1
	  stfs      f1, 0x3CC(r1)
	  lfs       f1, 0x0(r7)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3C8(r1)
	  bl        -0x1331CC
	  lwz       r4, 0x20(r31)
	  lwz       r3, 0x5F4(r1)
	  lwz       r4, 0x3F4(r4)
	  lwz       r0, 0x5F8(r1)
	  lwz       r4, 0x0(r4)
	  stw       r3, 0x2BC(r4)
	  stw       r0, 0x2C0(r4)
	  lwz       r0, 0x5FC(r1)
	  stw       r0, 0x2C4(r4)
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2D4C
	  li        r4, 0x8D
	  bl        -0xC6554
	  b         .loc_0x2D4C
	  mr        r3, r31
	  bl        -0x2F50
	  lwz       r3, 0x20(r31)
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x2D4C
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x2BD(r3)
	  lwz       r3, 0x20(r31)
	  stw       r0, 0x318(r3)
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2D4C
	  li        r4, 0x8D
	  bl        -0xC65A4
	  b         .loc_0x2D4C
	  lfs       f0, -0x54A8(r2)
	  addi      r6, r1, 0x3C0
	  addi      r5, r1, 0x3BC
	  stfs      f0, 0x5D4(r1)
	  addi      r4, r1, 0x3B8
	  addi      r3, r1, 0x5CC
	  stfs      f0, 0x5D0(r1)
	  stfs      f0, 0x5CC(r1)
	  lwz       r8, 0x20(r31)
	  lwz       r7, 0x3F4(r8)
	  lwz       r8, 0x224(r8)
	  lwz       r7, 0x0(r7)
	  lfs       f1, 0x310(r8)
	  lfsu      f0, 0x70(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x8(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r7)
	  lwz       r7, 0x20(r31)
	  lwz       r7, 0x3F4(r7)
	  lwz       r7, 0x0(r7)
	  addi      r8, r7, 0x94
	  addi      r7, r7, 0x2BC
	  lfs       f0, 0x8(r8)
	  lfs       f1, 0x8(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x3C0(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x3BC(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x3B8(r1)
	  bl        -0x1332FC
	  lwz       r3, 0x20(r31)
	  addi      r6, r1, 0x3B4
	  lfs       f0, 0x5CC(r1)
	  addi      r5, r1, 0x3B0
	  lwz       r3, 0x224(r3)
	  addi      r4, r1, 0x3AC
	  lfs       f1, 0x320(r3)
	  addi      r3, r1, 0x5CC
	  fmuls     f0, f0, f1
	  stfs      f0, 0x5CC(r1)
	  lfs       f0, 0x5D0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x5D0(r1)
	  lfs       f0, 0x5D4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x5D4(r1)
	  lwz       r7, 0x20(r31)
	  lfs       f0, 0x5CC(r1)
	  lwz       r7, 0x3F4(r7)
	  lwz       r7, 0x0(r7)
	  lfsu      f1, 0x70(r7)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r7)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x5D0(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r7)
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x5D4(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r7)
	  lwz       r8, 0x20(r31)
	  lwz       r7, 0x3F4(r8)
	  lwz       r8, 0x224(r8)
	  lwz       r7, 0xC(r7)
	  lfs       f1, 0x310(r8)
	  lfsu      f0, 0x70(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x8(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r7)
	  lwz       r7, 0x20(r31)
	  lwz       r7, 0x3F4(r7)
	  lwz       r7, 0xC(r7)
	  addi      r8, r7, 0x94
	  addi      r7, r7, 0x2BC
	  lfs       f0, 0x8(r8)
	  lfs       f1, 0x8(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x3B4(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x3B0(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x3AC(r1)
	  bl        -0x1333F8
	  lwz       r3, 0x20(r31)
	  lfs       f0, 0x5CC(r1)
	  lwz       r3, 0x224(r3)
	  lfs       f1, 0x320(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x5CC(r1)
	  lfs       f0, 0x5D0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x5D0(r1)
	  lfs       f0, 0x5D4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x5D4(r1)
	  lwz       r3, 0x20(r31)
	  lfs       f0, 0x5CC(r1)
	  lwz       r3, 0x3F4(r3)
	  lwz       r3, 0xC(r3)
	  lfsu      f1, 0x70(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r3)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x5D0(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r3)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x5D4(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x20(r31)
	  lfs       f0, -0x542C(r2)
	  lfs       f1, 0x2D4(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2D34
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10C(r12)
	  mtlr      r12
	  blrl

	.loc_0x2D34:
	  lwz       r4, 0x20(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D4(r4)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D4(r4)

	.loc_0x2D4C:
	  lwz       r3, 0x20(r31)
	  lwz       r3, 0x3F8(r3)
	  lwz       r3, 0x3BC(r3)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x4(r31)
	  lwz       r0, 0xBAC(r1)
	  lfd       f31, 0xBA0(r1)
	  lfd       f30, 0xB98(r1)
	  lfd       f29, 0xB90(r1)
	  lfd       f28, 0xB88(r1)
	  lwz       r31, 0xB84(r1)
	  lwz       r30, 0xB80(r1)
	  addi      r1, r1, 0xBA8
	  mtlr      r0
	  blr

	.loc_0x2D88:
	*/
}
