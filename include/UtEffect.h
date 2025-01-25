#ifndef _UTEFFECT_H
#define _UTEFFECT_H

#include "types.h"
#include "KEffect.h"
#include "EffectMgr.h"

struct Navi;

// NB: could maybe split these into smaller headers down the line
// Most of their functions are in uteffect in Kando, so they're here for now.

/**
 * @brief TODO
 */
struct BombEffect : public KEffect {
	virtual void emit(EffectParm&); // _2C
	virtual void kill();            // _30

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
	virtual void emit(EffectParm&); // _2C
	virtual void kill();            // _30

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
	virtual bool invoke(zen::particleGenerator*); // _08
	virtual void emit(EffectParm&);               // _2C

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviFue : public KEffect {
	NaviFue(Navi* navi)
	{
		mNavi     = navi;
		mEntryNum = 24;
		mEntries  = new zen::particleGenerator*[mEntryNum];
		if (navi) {
			for (int i = 0; i < mEntryNum; i++) {
				mEntries[i] = nullptr;
			}
		}
	}
	virtual bool invoke(zen::particleGenerator*); // _08
	virtual void emit(EffectParm&);               // _2C
	virtual void kill();                          // _30

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	Navi* mNavi;                       // _0C
	int mEntryNum;                     // _10
	zen::particleGenerator** mEntries; // _14
};

/**
 * @brief TODO
 */
struct NaviWhistle : public KEffect {
	NaviWhistle(Navi* navi)
	{
		mNavi = navi;
		mEfxC = 0;
		mEfxB = 0;
		mEfxA = 0;
	}
	virtual bool invoke(zen::particleGenerator*, zen::particleMdl*); // _24
	virtual void emit(EffectParm&);                                  // _2C
	virtual void kill();                                             // _30

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	// TODO: members
	Navi* mNavi;                   // _0C
	zen::particleGenerator* mEfxA; // _10
	zen::particleGenerator* mEfxB; // _14
	zen::particleGenerator* mEfxC; // _18
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
	SimpleEffect(u16 id)
	{
		mEfxId = id;
		mEfx   = 0;
	}
	virtual void emit(EffectParm&); // _2C
	virtual void kill();            // _30

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
	virtual void emit(EffectParm&); // _2C

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
	virtual void emit(EffectParm&); // _2C

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
	virtual void emit(EffectParm&); // _2C

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
	virtual void emit(EffectParm&); // _2C

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

	virtual void emit(EffectParm&); // _2C
	virtual void kill();            // _30

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
	WhistleTemplate(u32 id1, u32 id2)
	{
		mEfxA = mEfxB = 0;
		_2C           = id1;
		_30           = id2;
	}

	virtual bool invoke(zen::particleGenerator*, zen::particleMdl*); // _24
	virtual void emit(EffectParm&);                                  // _2C
	virtual void kill();                                             // _30

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	Vector3f _0C;                  // _0C
	Vector3f _18;                  // _18
	zen::particleGenerator* mEfxA; // _24
	zen::particleGenerator* mEfxB; // _28
	int _2C;                       // _2C
	int _30;                       // _30
};

/**
 * @brief TODO
 */
struct UfoSuckEffect : public WhistleTemplate {
	UfoSuckEffect()
	    : WhistleTemplate(EffectMgr::EFF_Rocket_Bm2, EffectMgr::EFF_Rocket_Suck2)
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
