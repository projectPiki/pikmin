#ifndef _TAI_BEATLE_H
#define _TAI_BEATLE_H

#include "types.h"
#include "TAI/Aattack.h"
#include "TAI/Amove.h"
#include "TAI/Areaction.h"
#include "TAI/Ajudge.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "zen/particle.h"
#include "PaniAnimator.h"
#include "SoundID.h"
#include "PlayerState.h"
#include "iterator.h"
#include "PikiMgr.h"
#include "Pcam/CameraManager.h"
#include "RumbleMgr.h"

/////////// Armored Cannon Beetle AI Actions ///////////

BEGIN_ENUM_TYPE(TAIbeatleFloatParms)
enum {
	FlickingTime = TPF_COUNT,
	AttackRange,
	Unk2,
	SuctionAngle,
	SuctionRadius,
	COUNT,
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAIbeatleStateID)
enum {
	Dying,
	Initializing,
	Unk2,
	Unk3,
	Unk4,
	Unk5,
	Unk6,
	Unk7,
	Unk8,
	Unk9,
	Unk10,
	Unk11,
	Unk12,
	Unk13,
	COUNT,
} END_ENUM_TYPE;

/*
 * @brief TODO
 */
struct TAIbeatleSoundTable : public PaniSoundTable {
	TAIbeatleSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIbeatleParameters : public TekiParameters {
	TAIbeatleParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIbeatleStrategy : public YaiStrategy {
	TAIbeatleStrategy();

	virtual void act(Teki&);                           // _0C
	virtual bool interact(Teki&, TekiInteractionKey&); // _20

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIbeatleAnimation : public TAIanimation {
	TAIbeatleAnimation()
	    : TAIanimation(TEKI_Beatle, "tekis/beatle/anims.bun")
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Defined in TAIbeatle.cpp
 */
struct TAIAinitBeatle;

/**
 * @brief TODO
 */
struct TAIAcheckInsideRangePikiBeatle : public TAIAcheckInsideRangePiki {
	TAIAcheckInsideRangePikiBeatle(int nextState, int pikiMax)
	    : TAIAcheckInsideRangePiki(nextState, pikiMax, 0.0f)
	{
	}

	virtual f32 getRange(Teki& teki) { return teki.getParameterF(TPF_AttackRange); } // _20

	// _04     = VTBL
	// _00-_08 = TAIAcheckInsideRangePiki?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdisableStick : public TaiAction {
	inline TAIAdisableStick(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) { teki.disableStick(); } // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickingBeatle : public TAIAflicking {
	TAIAflickingBeatle(int nextState, int motionIdx)
	    : TAIAflicking(nextState, motionIdx)
	{
	}

	virtual void flick(Teki& teki) // _1C
	{
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			InteractFlick& flick1 = InteractFlick(&teki, teki.getParameterF(TPF_UpperFlickPower), teki.getParameterF(TPF_UpperAttackPower),
			                                      getFlickDirection(teki));
			InteractFlick& flick2 = InteractFlick(&teki, teki.getParameterF(TPF_LowerFlickPower), teki.getParameterF(TPF_LowerAttackPower),
			                                      getFlickDirection(teki));
			teki.flick(flick1, flick2);

			effectMgr->create(EffectMgr::EFF_BigDustRing, teki.getPosition(), nullptr, nullptr);
		}
	}

	// _04     = VTBL
	// _00-_0C = TAIAflicking?
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Defined in TAIbeatle.cpp
 */
struct TAIAflickingAfterMotionLoopBeatle;

/**
 * @brief TODO
 */
struct TAIArockAttack : public TAIAreserveMotion {
	inline TAIArockAttack(int nextState, int p2, int motionIdx) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionIdx)
	{
		_0C = nextState;
		_10 = p2;
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAreserveMotion::start(teki);

		teki.setBiteSwitch(false);
		teki.setCreaturePointer(2, nullptr);
		teki.setPtclGenPtr(YTeki::PTCL_Unk6, nullptr);
		teki.setPtclGenPtr(YTeki::PTCL_Unk7, nullptr);

		if (teki.isNaviWatch()) {
			playerState->mResultFlags.setOn(RESFLAG_Beatle);
		}
	}

	virtual bool act(Teki& teki) // _10
	{
		bool result = false;
		if (TAIAreserveMotion::act(teki)) {
			zen::particleGenerator* ptclGen;
			CollPart* nozzlePart = teki.mCollInfo->getSphere('slot');

			Vector3f suckPosition;
			Vector3f suckPartSep;
			Vector3f suckNormal;

			suckPosition = teki.getPosition();
			suckPosition.x += NMathF::sin(teki.mFaceDirection) * teki.getParameterF(TAIbeatleFloatParms::SuctionRadius);
			suckPosition.y += 53.0f;
			suckPosition.z += NMathF::cos(teki.mFaceDirection) * teki.getParameterF(TAIbeatleFloatParms::SuctionRadius);

			suckPartSep.set(suckPosition - nozzlePart->mCentre);
			if (zen::RoundOff(teki.mTekiAnimator->mAnimationCounter) == 1) {
				ptclGen = effectMgr->create(EffectMgr::EFF_Beatle_SuckAir1, suckPosition, nullptr, nullptr);
				teki.setPtclGenPtr(YTeki::PTCL_Unk6, ptclGen);

				ptclGen = effectMgr->create(EffectMgr::EFF_Beatle_SuckAir2, suckPosition, nullptr, nullptr);
				if (ptclGen != nullptr) {
					Vector3f startPos;
					Vector3f suckNormal2;

					startPos.set(nozzlePart->mCentre.x, nozzlePart->mCentre.y - 15.0f, nozzlePart->mCentre.z);

					suckNormal2.set(suckPosition - startPos);
					suckNormal2.normalize();
					suckNormal2.multiply(-4.0f);

					ptclGen->setOrientedNormalVector(suckNormal2);
					ptclGen->setAirField(suckNormal2, true);

					teki.setPtclGenPtr(YTeki::PTCL_Unk7, ptclGen);
				}
			}

			suckNormal.set(suckPartSep);
			suckNormal.normalize();
			ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk6);
			if (ptclGen != nullptr) {
				Vector3f attractorPos;
				attractorPos.set(nozzlePart->mCentre + Vector3f(suckNormal * -30.0f));
				ptclGen->setNewtonField(attractorPos, ptclGen->getNewtonFieldFrc(), true);
			}

			STACK_PAD_STRUCT(3);

			ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk7);
			if (ptclGen != nullptr) {
				Vector3f particleNormal;
				particleNormal.set(suckNormal);
				particleNormal.multiply(-7.0f);
				ptclGen->setOrientedNormalVector(particleNormal);
				ptclGen->setAirField(particleNormal, true);
			}

			if (zen::RoundOff(teki.mTekiAnimator->mAnimationCounter) > 4 && teki.getPtclGenPtr(YTeki::PTCL_Unk6) != nullptr) {
				STACK_PAD_VAR(2);
				Iterator pikiIter(pikiMgr);
				CI_LOOP(pikiIter)
				{
					Creature* piki = *pikiIter;
					if (piki == nullptr || !piki->isAlive()) {
						continue;
					}

					Vector3f pikiSlotSep = piki->getPosition() - nozzlePart->mCentre;
					if (suckPartSep.DP(pikiSlotSep) > 0.0f) {
						f32 distanceToSuckPos = suckPartSep.length();
						f32 distanceToPiki    = pikiSlotSep.length();
						if (distanceToPiki < distanceToSuckPos) {
							if (distanceToSuckPos != 0.0f) {
								suckPartSep.div(distanceToSuckPos);
							}

							if (distanceToPiki != 0.0f) {
								pikiSlotSep.div(distanceToPiki);
							}

							if (suckPartSep.DP(pikiSlotSep)
							    > NMathF::cos(teki.getParameterF(TAIbeatleFloatParms::SuctionAngle) * PI / 180.0f)) {
								f32 knockbackStrength = 300.0f;
								Vector3f knockbackVel;
								knockbackVel.set(-pikiSlotSep.x * knockbackStrength, -pikiSlotSep.y * knockbackStrength,
								                 -pikiSlotSep.z * knockbackStrength);

								InteractWind wind(&teki, knockbackVel, 0.0f, nullptr);
								STACK_PAD_VAR(1);
								piki->stimulate(wind);
							}
						}
					}
				}
			}

			if (teki.mCurrentAnimEvent == KEY_Action0) {
				teki.setBiteSwitch(true);
			}

			if (teki.mCurrentAnimEvent == KEY_Action1) {
				teki.setBiteSwitch(false);
			}

			if (teki.getBiteSwitch() != false && teki.getCreaturePointer(2) == nullptr && nozzlePart != nullptr) {
				Iterator pikiIter(pikiMgr);
				CI_LOOP(pikiIter)
				{
					Creature* piki = *pikiIter;
					Vector3f pikiSlotSep;
					if (piki == nullptr || !piki->isAlive()) {
						continue;
					}

					pikiSlotSep.set(nozzlePart->mCentre - piki->getPosition());
					if (pikiSlotSep.length() < teki.getParameterF(TAIbeatleFloatParms::Unk2)) {

						Matrix4f mtx = nozzlePart->getMatrix();

						Vector3f emitDir;
						emitDir.set(mtx.mMtx[0][0], mtx.mMtx[1][0], mtx.mMtx[2][0]);

						teki.setCreaturePointer(2, piki);

						// somehow this stuff gets created way higher up
						InteractSwallow swallow(&teki, nozzlePart, 0);
						piki->stimulate(swallow);

						ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk6);
						if (ptclGen != nullptr) {
							ptclGen->forceFinish();
						}

						ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk7);
						if (ptclGen != nullptr) {
							ptclGen->forceFinish();
						}

						ptclGen = effectMgr->create(EffectMgr::EFF_Beatle_ShootRockHalo, nozzlePart->mCentre, nullptr, nullptr);
						if (ptclGen != nullptr) {
							ptclGen->setEmitDir(emitDir);
							ptclGen->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
						}

						ptclGen = effectMgr->create(EffectMgr::EFF_Beatle_ShootRockSpecks, nozzlePart->mCentre, nullptr, nullptr);
						if (ptclGen != nullptr) {
							ptclGen->setEmitDir(emitDir);
							ptclGen->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
						}

						teki.playEventSound(&teki, SE_KABUTO_TUMARI);
						mNextState = _10;
						result     = true;
						break;
					}
				}
			}

			if (teki.mCurrentAnimEvent == KEY_Action3) {
				teki.flick();
			}

			if (teki.mCurrentAnimEvent == KEY_Action2) {
				CollPart* kutiPart = teki.mCollInfo->getSphere('kuti');
				if (kutiPart != nullptr) {
					Matrix4f mtx = kutiPart->getMatrix();

					Vector3f vec1;
					Vector3f vec2;

					Teki* rock = teki.spawnTeki(teki.getParameterI(TPI_SpawnType));
					if (rock != nullptr) {
						vec2.set(mtx.mMtx[0][0], mtx.mMtx[1][0], mtx.mMtx[2][0]);
						vec1.set(kutiPart->mCentre + vec2 * 60.0f);

						ptclGen = effectMgr->create(EffectMgr::EFF_Beatle_RockClouds, vec1, nullptr, nullptr);
						if (ptclGen != nullptr) {
							ptclGen->setEmitDir(vec2);
						}

						ptclGen = effectMgr->create(EffectMgr::EFF_Beatle_RockSpray, vec1, nullptr, nullptr);
						if (ptclGen != nullptr) {
							ptclGen->setEmitDir(vec2);
						}

						ptclGen = effectMgr->create(EffectMgr::EFF_Beatle_RockBlast, vec1, nullptr, nullptr);
						if (ptclGen != nullptr) {
							ptclGen->setEmitDir(vec2);
						}

						rock->setPersonalityI(TekiPersonality::INT_Parameter0, 1);

						Vector3f spawnPos;
						teki.outputSpawnPosition(spawnPos);
						rock->inputPosition(spawnPos);

						Vector3f velocity;
						teki.outputDirectionVector(velocity);
						velocity.scale(teki.getParameterF(TPF_SpawnVelocity) * teki.getPersonalityF(TekiPersonality::FLT_Strength));
						rock->inputVelocity(velocity);
						rock->startAI(0);

						teki.playEventSound(&teki, SE_KABUTO_SHOT);
						cameraMgr->startVibrationEvent(3, teki.getPosition());
						rumbleMgr->start(RUMBLE_Unk14, 0, teki.getPosition());
					} else {
						Matrix4f kutiMtx = kutiPart->getMatrix();

						Vector3f flickEmitDir;
						flickEmitDir.set(kutiMtx.mMtx[0][0], kutiMtx.mMtx[1][0], kutiMtx.mMtx[2][0]);

						ptclGen = effectMgr->create(EffectMgr::EFF_Beatle_Flick1, kutiPart->mCentre, nullptr, nullptr);
						if (ptclGen != nullptr) {
							ptclGen->setEmitPosPtr(&kutiPart->mCentre);
							ptclGen->setEmitDir(flickEmitDir);
						}
					}
				}
			}

			if (teki.getCreaturePointer(2) == nullptr && teki.mCurrentAnimEvent == KEY_LoopEnd) {
				mNextState = _0C;
				teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
			}

			if (teki.mCurrentAnimEvent == KEY_Finished) {
				result = true;
			}
		}

		if (result) {
			teki.setPtclGenPtr(YTeki::PTCL_Unk6, nullptr);
			teki.setPtclGenPtr(YTeki::PTCL_Unk7, nullptr);
		}

		STACK_PAD_TERNARY(result, 3);
		STACK_PAD_VAR(3);
		return result;
	}

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	int _0C; // _0C
	int _10; // _10
};

/**
 * @brief TODO
 */
struct TAIAinsideOptionalRangeBeatle : public TAIAinsideOptionalRange {
	TAIAinsideOptionalRangeBeatle(int nextState)
	    : TAIAinsideOptionalRange(nextState)
	{
	}

	virtual bool setTargetPosition(Teki& teki) { setTargetPositionCreature(teki); }                           // _1C
	virtual f32 getOptionalRange(Teki& teki) { return teki.getParameterF(TAIbeatleFloatParms::AttackRange); } // _20

	// _04     = VTBL
	// _00-_08 = TAIAinsideOptionalRange?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAvisiblePikiBeatle : public TaiAction {
	inline TAIAvisiblePikiBeatle(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		bool result = false;

		Iterator pikiIter(pikiMgr);
		CI_LOOP(pikiIter)
		{
			Creature* piki = *pikiIter;
			if (!teki.visibleCreature(*piki) || piki->getStickObject() == &teki) {
				continue;
			}

			if (teki.getPosition().distance(piki->getPosition()) > 100.0f) {
				teki.setCreaturePointer(0, piki);

				result = true;
				break;
			}
		}

		return result;
	}

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdamageBeatle : public TAIAdamage {
	inline TAIAdamageBeatle(int nextState) // TODO: this is a guess
	    : TAIAdamage(nextState, true)
	{
	}

	virtual bool judgeDamage(Teki& teki) // _1C
	{
		if (teki._344 == 0) {
			return true;
		}

		teki.mStoredDamage = 0.0f;
		return false;
	}

	// _04     = VTBL
	// _00-_0C = TAIAdying?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdyingBeatle : public TAIAdying {
	inline TAIAdyingBeatle(int nextState, int motionIdx) // TODO: this is a guess
	    : TAIAdying(nextState, motionIdx)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAdying::start(teki);

		for (int i = 0; i < YTeki::PTCL_COUNT; i++) {
			zen::particleGenerator* ptclGen = teki.getPtclGenPtr((YTeki::ptclIndexFlag)i);
			if (ptclGen != nullptr) {
				ptclGen->finish();
				teki.setPtclGenPtr((YTeki::ptclIndexFlag)i, nullptr);
			}
		}

		playerState->mResultFlags.setSeen(RESFLAG_Beatle);
	}

	virtual bool act(Teki& teki) // _10
	{
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			teki.playEventSound(&teki, SE_KABUTO_DEAD);
		}

		TAIAdying::act(teki);
	}

	// _04     = VTBL
	// _00-_0C = TAIAdying?
	// TODO: members
};

#endif
