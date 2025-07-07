#ifndef _TAI_MAR_H
#define _TAI_MAR_H

#include "MapCode.h"
#include "PaniAnimator.h"
#include "Pcam/CameraManager.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "TAI/Aattack.h"
#include "TAI/Ajudge.h"
#include "TAI/Amove.h"
#include "TAI/Animation.h"
#include "TAI/Areaction.h"
#include "TAI/EffectAttack.h"
#include "TekiConditions.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"
#include "types.h"
#include "zen/CallBack.h"

/////////// Puffy Blowhog AI Actions ///////////

BEGIN_ENUM_TYPE(TAImarFloatParams)
enum {
	Unk50 = TPF_COUNT, // 50
	Unk51,             // 51
	Unk52,             // 52
	Unk53,             // 53
	Unk54,             // 54
	Unk55,             // 55
	Unk56,             // 56
	COUNT,             // 57
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAImarIntParams)
enum {
	Unk20 = TPI_COUNT, // 20
	Unk21,             // 21
	Unk22,             // 22
	COUNT,             // 23
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAImarStateID)
enum {
	Unk0  = 0,
	Unk1  = 1,
	Unk2  = 2,
	Unk3  = 3,
	Unk4  = 4,
	Unk5  = 5,
	Unk6  = 6,
	Unk7  = 7,
	Unk8  = 8,
	Unk9  = 9,
	Unk10 = 10,
	Unk11 = 11,
	Unk12 = 12,
	Unk13 = 13,
	Unk14 = 14,
	COUNT, // 15
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAImarMotionID)
enum {
	Unk0  = 0,  //
	Unk1  = 1,  //
	Unk2  = 2,  //
	Unk6  = 6,  //
	Unk7  = 7,  //
	Unk8  = 8,  //
	Unk9  = 9,  //
	Unk10 = 10, //
	Unk11 = 11, //
	Unk12 = 12, //
} END_ENUM_TYPE;

/*
 * @brief TODO
 */
struct TAImarSoundTable : public PaniSoundTable {
	TAImarSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAImarParameters : public TekiParameters {
	TAImarParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAImarStrategy : public YaiStrategy {
	TAImarStrategy();

	virtual void act(Teki&);                           // _0C
	virtual bool interact(Teki&, TekiInteractionKey&); // _20

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAImarAnimation : public TAIanimation {
	TAImarAnimation()
	    : TAIanimation(TEKI_Mar, "tekis/mar/anims.bun")
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIeffectAttackEventCallBackMar;

/**
 * @brief TODO
 */
struct TAIAinitMar : public TaiAction {
	TAIAinitMar(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		teki.mCollisionRadius = 64.0f;
	}
	virtual bool act(Teki&) { return true; } // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingDistanceInTerritoryMar : public TAIAflyingDistanceInTerritory {
	TAIAflyingDistanceInTerritoryMar(int nextState, int motionID, f32 p3, f32 p4)
	    : TAIAflyingDistanceInTerritory(nextState, motionID, p3, 0.0f, p4)
	{
	}

	virtual f32 getVelocity(Teki& teki) { return teki.getParameterF(TPF_RunVelocity); }        // _20
	virtual f32 getOffset(Teki& teki) { return teki.getParameterF(TAImarFloatParams::Unk50); } // _30

	// _04     = VTBL 1
	// _08     = VTBL 2
	// _00-_14 = TAIAflyingDistanceInTerritory
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAfireBreathMar : public TAIAfireBreath {
	inline TAIAfireBreathMar(int nextState, int motionID, zen::CallBack1<Teki&>* cb)
	    : TAIAfireBreath(nextState, motionID, cb)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAfireBreath::start(teki);
		if (teki.isNaviWatch()) {
			playerState->mResultFlags.setOn(RESFLAG_Mar);
		}
	}
	virtual bool act(Teki& teki) { return TAIAfireBreath::act(teki); }                                  // _10
	virtual f32 getPreviousAnimSpeed(Teki&) { return 60.0f; }                                           // _1C
	virtual f32 getAttackAnimSpeed(Teki& teki) { return teki.getParameterF(TAImarFloatParams::Unk52); } // _20

	// _04     = VTBL
	// _00-_0C = TAIAfireBreath?
	// TODO: members
};

/**
 * @brief TODO
 */
struct BreathEffect;

/**
 * @brief TODO
 */
struct TAIAflyingDistanceMar : public TAIAflyingDistance {
	TAIAflyingDistanceMar(int nextState, f32 p2, f32 p3)
	    : TAIAflyingDistance(nextState, p2, 0.0f, p3)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		bool res = TAIAflyingDistance::act(teki);

		// if base flyingDistance act succeeds, check for puffy-specific act.
		if (res) {
			// the more pikis we find in range, the more likely this act succeeds (hyperbolic, for whatever reason, so min is 1)
			int weight = 1;

			// loop through all pikis on field.
			Iterator iter(pikiMgr);
			CI_LOOP(iter)
			{
				Creature* piki = *iter;

				// if piki is within DangerTerritoryRange, increase chance of success by a small amount
				if (teki.getPosition().distance(piki->getPosition()) < teki.getParameterF(TPF_DangerTerritoryRange)) {
					weight++;
				}
			}

			// higher weight = smaller rand range = higher chance of success
			// work out the chance of this by taking the integral and finding the area under the distribution curve
			// P(XY <= 1) bounded by XY = 1 => Y = 1/X. take into account max X = A, max Y = 30, where A = 100 / weight
			// P(XY <= 1) = (ln(A) + ln(30) + 1) / (30 * A)
			// so, for:
			// - weight = 1 (no pikis in range), A = 100, chance of success is 0.3%
			// - weight = 51 (50 pikis in range), A = 100/51, chance of success is 8.6%
			// - weight = 101 (100 pikis in range), A = 100/101, chance of success is 14.8%
			if (zen::Rand(100.0f / weight) * zen::Rand(30.0f) <= 1.0f) {
				res = true;
			} else {
				res = false;
			}
		}

		return res;
	}
	virtual f32 getGoalAreaRange(Teki&) { return 40.0f; }                                      // _28
	virtual f32 getOffset(Teki& teki) { return teki.getParameterF(TAImarFloatParams::Unk50); } // _2C

	// _04     = VTBL 1
	// _08     = VTBL 2
	// _00-_10 = FlyingDistance
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAtimerTakeOffMar : public TAIAtimerReaction {
	TAIAtimerTakeOffMar(int nextState)
	    : TAIAtimerReaction(nextState, 0.0f)
	{
	}

	virtual f32 getFrameMax(Teki& teki) { return teki.getParameterF(TAImarFloatParams::Unk54); } // _1C

	// _04     = VTBL
	// _00-_0C = TAIAtimerReaction
};

/**
 * @brief TODO
 */
struct TAIAtakeOffMar : public TAIAtakeOff {
	TAIAtakeOffMar(int nextState, int motionID)
	    : TAIAtakeOff(nextState, motionID)
	{
	}

	virtual void startFlying(Teki& teki) // _1C
	{
		CollTriInfo* tri = mapMgr->getCurrTri(teki.getPosition().x, teki.getPosition().z, true);
		if (tri && MapCode::getAttribute(tri) == ATTR_Water) {
			effectMgr->create(EffectMgr::EFF_Onyon_Bubbles, teki.getPosition(), nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Onyon_Bubbles, teki.getPosition(), nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Onyon_Bubbles, teki.getPosition(), nullptr, nullptr);
			teki.playEventSound(&teki, SE_FLOG_WATERJUMP);
		}

		TAIAtakeOff::startFlying(teki);
	}

	// _04     = VTBL
	// _00-_08 = TAIAtakeOff?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAstickingPikiMar : public TAIAstickingPiki {
	TAIAstickingPikiMar(int nextState) // TODO: this is a guess
	    : TAIAstickingPiki(nextState, 0)
	{
	}

	virtual int getPikiNum(Teki& teki) { return teki.getParameterI(TAImarIntParams::Unk22); } // _1C

	// _04     = VTBL
	// _00-_08 = TAIAstickingPiki?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickCheckMar : public TAIAflickCheck {
	TAIAflickCheckMar(int nextState)
	    : TAIAflickCheck(nextState, TAImarMotionID::Unk1)
	{
	}

	virtual int getDamageCountLimit(Teki& teki) { return teki.getParameterI(TAImarIntParams::Unk20); } // _1C

	// _04     = VTBL
	// _00-_08 = TAIAflickCheck?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAlandingMar : public TAIAlanding {
	TAIAlandingMar(int nextState, int motionID)
	    : TAIAlanding(nextState, motionID)
	{
	}

	virtual void landingEffect(Teki& teki) // _1C
	{
		CollTriInfo* tri = mapMgr->getCurrTri(teki.getPosition().x, teki.getPosition().z, true);
		if (tri) {
			if (MapCode::getAttribute(tri) == ATTR_Water) {
				effectMgr->create(EffectMgr::EFF_Onyon_Bubbles, teki.getPosition(), nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Onyon_Bubbles, teki.getPosition(), nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Onyon_Bubbles, teki.getPosition(), nullptr, nullptr);
				teki.playEventSound(&teki, SE_FLOG_WATERJUMP);
			} else {
				effectMgr->create(EffectMgr::EFF_BigDustRing, teki.getPosition(), nullptr, nullptr);
				teki.playEventSound(&teki, SE_MAR_DROP);
			}
		} else {
			effectMgr->create(EffectMgr::EFF_BigDustRing, teki.getPosition(), nullptr, nullptr);
			teki.playEventSound(&teki, SE_MAR_DROP);
		}

		cameraMgr->startVibrationEvent(3, teki.getPosition());
		rumbleMgr->start(RUMBLE_Unk11, 0, teki.getPosition());
	}

	// _04     = VTBL
	// _00-_0C = TAIAlanding?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAstickingPikiMarFly : public TAIAstickingPiki {
	TAIAstickingPikiMarFly(int nextState) // TODO: this is a guess
	    : TAIAstickingPiki(nextState, 0)
	{
	}

	virtual int getPikiNum(Teki& teki) { return teki.getParameterI(TAImarIntParams::Unk21); } // _1C

	// _04     = VTBL
	// _00-_08 = TAIAstickingPiki?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickingMar : public TAIAflicking {
	TAIAflickingMar(int nextState, int motionIdx)
	    : TAIAflicking(nextState, motionIdx)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAflicking::start(teki);
		teki.playEventSound(&teki, SE_CHAPPY_SWING);
	}
	virtual void flick(Teki& teki) // _1C
	{
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			InteractFlick& flick = InteractFlick(&teki, teki.getParameterF(TPF_UpperFlickPower), teki.getParameterF(TPF_UpperAttackPower),
			                                     getFlickDirection(teki));
			teki.flickUpper(flick);
		}
	}

	// _04     = VTBL
	// _00-_0C = TAIAflicking?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickCheckTimerMar : public TaiAction {
	TAIAflickCheckTimerMar(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) { teki.setFrameCounter(0.0f); } // _08
	virtual bool act(Teki& teki)                                   // _10
	{
		bool res = false;
		setTimerStartFlag(teki);
		if (teki.getTimerStart()) {
			if (teki.addFrameCounter(gsys->getFrameTime()) > teki.getParameterF(TAImarFloatParams::Unk53)) {
				res = true;
				teki.setTimerStart(false);
			}
		}

		return res;
	}

	void setTimerStartFlag(Teki& teki)
	{
		int pikis = teki.countPikis(TekiStickerCondition(&teki));
		if (pikis > 0) {
			teki.setTimerStart(true);
		} else {
			teki.setTimerStart(false);
			teki.setFrameCounter(0.0f);
		}

		STACK_PAD_TERNARY(pikis, 2);
	}

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingBaseMar : public TAIAflyingBase {
	inline TAIAflyingBaseMar(int nextState) // TODO: this is a guess
	    : TAIAflyingBase(nextState)
	{
	}

	virtual f32 getFlyingStayVelocity(Teki& teki) { return teki.getParameterF(TAImarFloatParams::Unk56); } // _1C

	// _04     = VTBL
	// _00-_08 = TAIAflyingBase?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdyingMar : public TAIAdying {
	TAIAdyingMar(int nextState, int motionID)
	    : TAIAdying(nextState, motionID)
	{
		effectScale0       = 1.0f;
		effectStartCounter = 0.0f;
		effectScale1       = 1.0f;
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAdying::start(teki);
		teki.setPtclGenPtr(YTeki::PTCL_Unk1, nullptr);
		teki.setPtclGenPtr(YTeki::PTCL_Unk2, nullptr);
		playerState->mResultFlags.setSeen(RESFLAG_Mar);
	}
	virtual bool act(Teki& teki) // _10
	{
		zen::particleGenerator* ptclGen1 = teki.getPtclGenPtr(YTeki::PTCL_Unk1);
		zen::particleGenerator* ptclGen2 = teki.getPtclGenPtr(YTeki::PTCL_Unk2);

		if (teki.mCurrentAnimEvent == KEY_Action1) {
			if (ptclGen1) {
				ptclGen1->finish();
			}
			teki.setPtclGenPtr(YTeki::PTCL_Unk1, nullptr);
			if (ptclGen2) {
				ptclGen2->finish();
			}
			teki.setPtclGenPtr(YTeki::PTCL_Unk2, nullptr);
		}

		bool res = TAIAdying::act(teki);
		if (!res) {
			CollPart* mouth = teki.mCollInfo->getSphere('kuti');
			Matrix4f mtx    = mouth->getMatrix();
			Vector3f dir;
			dir.set(mtx.mMtx[0][0], mtx.mMtx[1][0], mtx.mMtx[2][0]);
			if (ptclGen1 && ptclGen2) {
				ptclGen1->setEmitDir(dir);
				ptclGen2->setEmitDir(dir);
				f32 t = 1.0f
				      - (teki.mTekiAnimator->mAnimationCounter - effectStartCounter)
				            / (teki.mTekiAnimator->mAnimInfo->mData->mTotalFrameCount - effectStartCounter);
				ptclGen1->setScaleSize(effectScale0 * t);
				ptclGen2->setScaleSize(effectScale1 * t);
			} else if (teki.mCurrentAnimEvent == KEY_Action0 && mouth) {
				ptclGen1 = effectMgr->create(EffectMgr::EFF_Mar_DeadSmoke, mouth->mCentre, nullptr, nullptr);
				teki.setPtclGenPtr(YTeki::PTCL_Unk1, ptclGen1);
				if (ptclGen1) {
					ptclGen1->setEmitPos(mouth->mCentre);
					ptclGen1->setEmitDir(dir);
					effectScale0       = ptclGen1->getScaleSize();
					effectStartCounter = teki.mTekiAnimator->mAnimationCounter;
				}

				ptclGen2 = effectMgr->create(EffectMgr::EFF_Mar_DeadJet, mouth->mCentre, nullptr, nullptr);
				teki.setPtclGenPtr(YTeki::PTCL_Unk2, ptclGen2);
				if (ptclGen2) {
					ptclGen2->setEmitPos(mouth->mCentre);
					ptclGen2->setEmitDir(dir);
					effectScale1 = ptclGen2->getScaleSize();
				}
			}
		}

		return res;
	}

	static f32 effectScale0;
	static f32 effectScale1;
	static f32 effectStartCounter;

	// _04     = VTBL
	// _00-_0C = TAIAdying?
	// TODO: members
};

#endif
