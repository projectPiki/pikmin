#ifndef _UTEFFECT_H
#define _UTEFFECT_H

#include "types.h"
#include "KEffect.h"
#include "EffectMgr.h"
#include "Collision.h"
#include "MapMgr.h"
#include "Matrix3f.h"
#include "zen/Math.h"

struct Navi;

// NB: could maybe split these into smaller headers down the line
// Most of their functions are in uteffect in Kando, so they're here for now.

// clang-format off
DEFINE_ENUM_TYPE(
	KandoEffect,

	Goal = 0,         // 0
	NaviWhistle0,     // 1
	NaviWhistle1,     // 2
	SmokeSoil,        // 3
	SmokeRock,        // 4
	SmokeGrass,       // 5
	SmokeTree,        // 6
	NaviFue0,         // 7
	NaviFue1,         // 8, unused
	PikiGrowup1,      // 9
	PikiGrowup2,      // 10
	WallHit1,         // 11
	WallHit0,         // 12
	WallHit2,         // 13
	WallHit3,         // 14
	WallBreak0,       // 15
	WallBreak1,       // 16
	Bubbles,          // 17
	Ripples,          // 18
	Bomb,             // 19
	BombLight,        // 20
	UfoSuck,          // 21
	UfoSuikomi,       // 22
	WhistleTemplate0, // 23
	WhistleTemplate1, // 24
	IdleBluePiki,     // 25
	IdleRedPiki,      // 26
	IdleYellowPiki,   // 27
	COUNT,            // 28

	START = Goal,         // 0
	END = IdleYellowPiki, // 27

	SmokeOffset = SmokeSoil, // 3, for different map code attributes
);
// clang-format on

/**
 * @brief TODO
 */
struct BombEffect : public KEffect {
	virtual void emit(EffectParm& parm) // _2C
	{
		zen::particleGenerator* efx = effectMgr->create(EffectMgr::EFF_Bomb_Glow, parm.mPosition, nullptr, nullptr);
		if (efx) {
			Vector3f nrm(0.0f, 1.0f, 0.0f);
			efx->setOrientedNormalVector(nrm);
		}
		effectMgr->create(EffectMgr::EFF_Bomb_Wave, parm.mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Bomb_DustRing, parm.mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Bomb_Bang, parm.mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Bomb_FireBang, parm.mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Bomb_FireGlow, parm.mPosition, nullptr, nullptr);
	}
	virtual void kill() { } // _30

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct BombEffectLight : public KEffect {
	virtual void emit(EffectParm& parm) // _2C
	{
		zen::particleGenerator* efx = effectMgr->create(EffectMgr::EFF_Bomb_Glow, parm.mPosition, nullptr, nullptr);
		if (efx) {
			Vector3f nrm(0.0f, 1.0f, 0.0f);
			efx->setOrientedNormalVector(nrm);
		}
		effectMgr->create(EffectMgr::EFF_BombLight_Bang, parm.mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_BombLight_Wave, parm.mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_BombLight_FireBang, parm.mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_BombLight_FireGlow, parm.mPosition, nullptr, nullptr);
	}
	virtual void kill() { } // _30

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	// TODO: members
};

/**
 * @brief TODO
 */
struct BurnEffect : public KEffect {
	BurnEffect(Vector3f* vec)
	{
		_0C   = vec;
		mEfxA = 0;
		mEfxB = 0;
	}

	virtual bool invoke(zen::particleGenerator*); // _08
	virtual void emit(EffectParm&);               // _2C
	virtual void kill();                          // _30
	virtual void stop();                          // _34
	virtual void restart();                       // _38

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	Vector3f* _0C;                 // _0C
	zen::particleGenerator* mEfxA; // _10
	zen::particleGenerator* mEfxB; // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct FreeLightEffect : public KEffect {
	FreeLightEffect() { mEfx = nullptr; }

	virtual void emit(EffectParm&); // _2C
	virtual void kill();            // _30
	virtual void stop();            // _34
	virtual void restart();         // _38

	void setScale(f32);

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	u16 mColor;                   // _0C
	zen::particleGenerator* mEfx; // _10, unknown
	f32 mScale;                   // _14
};

/**
 * @brief TODO
 */
struct GoalEffect : public KEffect {
	virtual bool invoke(zen::particleGenerator* efx) // _08
	{
		if (efx->getCurrentFrame() >= 50) {
			Vector3f grav(0.0f, 0.0f, 0.0f);
			efx->setGravityField(grav, false);
		}
		return true;
	}
	virtual void emit(EffectParm& parm) // _2C
	{
		effectMgr->create(EffectMgr::EFF_Onyon_Suck, parm.mPosition, this, this);
	}

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct RippleEffect : public KEffect {
	RippleEffect()
	{
		mEfxA = 0;
		mEfxB = mEfxC = 0;
	}

	virtual void emit(EffectParm&); // _2C
	virtual void kill();            // _30
	virtual void stop();            // _34
	virtual void restart();         // _38

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	zen::particleGenerator* mEfxA; // _0C
	zen::particleGenerator* mEfxB; // _10
	zen::particleGenerator* mEfxC; // _14
};

/**
 * @brief TODO
 */
struct SimpleEffect : public KEffect {
	SimpleEffect(EffectMgr::effTypeTable id)
	{
		mEfxId = id;
		mEfx   = 0;
	}
	virtual void emit(EffectParm& parm) // _2C
	{
		mEfx = effectMgr->create((EffectMgr::effTypeTable)mEfxId, parm.mPosition, nullptr, nullptr);
	}
	virtual void kill() // _30
	{
		if (mEfx) {
			effectMgr->mPtclMgr.killGenerator(mEfx, false);
		}
	}

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	int mEfxId;                   // _0C
	zen::particleGenerator* mEfx; // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct SlimeEffect : public KEffect {
	SlimeEffect();

	virtual bool invoke(zen::particleGenerator*, zen::particleMdl*); // _24
	virtual void emit(EffectParm&);                                  // _2C
	virtual void kill();                                             // _30
	virtual void stop();                                             // _34
	virtual void restart();                                          // _38

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	zen::particleGenerator* mEfxGen; // _0C
	Creature* mObj;                  // _10
};

/**
 * @brief TODO
 */
struct SmokeGrassEffect : public KEffect {
	virtual void emit(EffectParm& parm) // _2C
	{
		effectMgr->create(EffectMgr::EFF_Kogane_Walk1, parm.mPosition, nullptr, nullptr);
	}

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	// TODO: members
};

/**
 * @brief TODO
 */
struct SmokeRockEffect : public KEffect {
	virtual void emit(EffectParm& parm) // _2C
	{
		effectMgr->create(EffectMgr::EFF_Kogane_Walk2, parm.mPosition, nullptr, nullptr);
	}

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	// TODO: members
};

/**
 * @brief TODO
 */
struct SmokeSoilEffect : public KEffect {
	virtual void emit(EffectParm& parm) // _2C
	{
		effectMgr->create(EffectMgr::EFF_Kogane_Walk0, parm.mPosition, nullptr, nullptr);
	}

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	// TODO: members
};

/**
 * @brief TODO
 */
struct SmokeTreeEffect : public KEffect {
	virtual void emit(EffectParm& parm) // _2C
	{
		effectMgr->create(EffectMgr::EFF_Kogane_Walk0, parm.mPosition, nullptr, nullptr);
	}

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	// TODO: members
};

/**
 * @brief TODO
 */
struct UfoSuikomiEffect : public KEffect {
	UfoSuikomiEffect() { mEfx = 0; }

	virtual void emit(EffectParm& parm) // _2C
	{
		_0C = parm.mPosition;
		_18 = parm.mDirection;
		if (mEfx) {
			return;
		}
		mEfx          = effectMgr->create(EffectMgr::EFF_Rocket_Suck2, _0C, this, this);
		Vector3f diff = _18 - _0C;
		mEfx->setNewtonField(Vector3f(_18), 0.0016f, true);
		diff.normalise();
		mEfx->setVortexField(Vector3f(diff), -0.12f, -0.09f, 0.3f, 400.0f, true);
	}
	virtual void kill() // _30
	{
		if (mEfx) {
			effectMgr->mPtclMgr.killGenerator(mEfx, false);
			mEfx = nullptr;
		}
	}

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	Vector3f _0C;                 // _0C
	Vector3f _18;                 // _18
	zen::particleGenerator* mEfx; // _24
};

/**
 * @brief TODO
 */
struct WhistleTemplate : public KEffect {
	WhistleTemplate(EffectMgr::effTypeTable id1, EffectMgr::effTypeTable id2)
	{
		mEfxA = mEfxB = nullptr;
		mEffIDA       = id1;
		mEffIDB       = id2;
	}

	virtual bool invoke(zen::particleGenerator* ptclGen, zen::particleMdl* ptcl) // _24
	{
		// NON-MATCHING
		Vector3f diff         = _0C - _18;
		f32 ratio             = f32(ptcl->mAge) / f32(ptcl->mLifeTime);
		f32 compRatio         = 1.0f - ratio;
		ptcl->mGlobalPosition = _18;
		ptcl->mLocalPosition  = diff * ratio;

		if (_0C.y < _18.y + 15.0f) {
			CollTriInfo* tri = mapMgr->getCurrTri(_0C.x, _0C.z, true);
			Matrix3f mtx1;
			Matrix3f mtx2;
			Quat q1;
			Quat q2;

			diff.normalise();
			zen::makeRotMatrix(diff, mtx1);
			// some really subtle stack issue here
			zen::makeRotMatrix(Vector3f(tri->mTriangle.mNormal * -1.0f), mtx2);

			q1.fromMat3f(mtx1);
			q2.fromMat3f(mtx2);
			q1.slerp(q2, ratio, 0);
			q1.genVectorY(ptcl->mOrientedNormal);
			q1.genVectorX(ptcl->mVelocity);
			ptcl->mVelocity.multiply(0.01f);
		} else {
			ptcl->mOrientedNormal.set(diff);
		}

		return false;
	}
	virtual void emit(EffectParm& parm) // _2C
	{
		_0C = parm.mPosition;
		_18 = parm.mDirection;
		if (mEfxA || mEfxB) {
			return;
		}
		mEfxA = effectMgr->create(mEffIDA, _18, this, this);
		mEfxB = effectMgr->create(mEffIDB, _18, this, this);

		if (mEfxA) {
			mEfxA->setOrientedConstZAxis(true);
		}
	}
	virtual void kill() // _30
	{
		// PRINT("** KILL WHISTLE TYPE\n");
		if (mEfxA) {
			// PRINT("* DO KILL pg2\n");
			effectMgr->mPtclMgr.killGenerator(mEfxA, false);
			mEfxA = nullptr;
		}
		if (mEfxB) {
			// PRINT("* DO KILL pg3\n");
			effectMgr->mPtclMgr.killGenerator(mEfxB, false);
			mEfxB = nullptr;
		}
	}

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	Vector3f _0C;                    // _0C
	Vector3f _18;                    // _18
	zen::particleGenerator* mEfxA;   // _24
	zen::particleGenerator* mEfxB;   // _28
	EffectMgr::effTypeTable mEffIDA; // _2C
	EffectMgr::effTypeTable mEffIDB; // _30
};

/**
 * @brief TODO
 */
struct UfoSuckEffect : public WhistleTemplate {
	UfoSuckEffect()
	    : WhistleTemplate(EffectMgr::EFF_Rocket_Bm1, EffectMgr::EFF_Rocket_Bm2)
	{
	}

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_34 = WhistleTemplate
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct PermanentEffect {
	PermanentEffect();

	void init(Vector3f&, int);
	void updatePos(Vector3f&);
	void changeEffect(int);
	void stop();
	void restart();
	void kill();

	Vector3f mPosition;               // _00
	zen::particleGenerator* mPtclGen; // _0C
};

/**
 * @brief TODO
 */
struct UtEffectMgr {
	UtEffectMgr();

	void registerEffect(int, KEffect*);
	static void kill(int);

	static void cast(int, EffectParm&);

	static KEffect** effects;

	// TODO: members
};

extern UtEffectMgr* utEffectMgr;

#endif
