#ifndef _UTEFFECT_H
#define _UTEFFECT_H

#include "types.h"
#include "KEffect.h"

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
		_0C = vec;
		_10 = 0;
		_14 = 0;
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
	Vector3f* _0C; // _0C
	u32 _10;       // _10, unknown
	u32 _14;       // _14, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct FreeLightEffect : public KEffect {
	FreeLightEffect() { _10 = 0; }

	virtual void emit(EffectParm&); // _2C
	virtual void kill();            // _30
	virtual void stop();            // _34
	virtual void restart();         // _38

	void setScale(f32);

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	u8 _0C[4];   // _0C, unknown
	u32 _10;     // _10, unknown
	u8 _14[0x4]; // _14, unknown
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
	virtual bool invoke(zen::particleGenerator*); // _08
	virtual void emit(EffectParm&);               // _2C
	virtual void kill();                          // _30

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	// TODO: members
};

/**
 * @brief TODO
 */
struct NaviWhistle : public KEffect {
	virtual bool invoke(zen::particleGenerator*, zen::particleMdl*); // _24
	virtual void emit(EffectParm&);                                  // _2C
	virtual void kill();                                             // _30

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
		_0C = 0;
		_10 = _14 = 0;
	}

	virtual void emit(EffectParm&); // _2C
	virtual void kill();            // _30
	virtual void stop();            // _34
	virtual void restart();         // _38

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	u32 _0C; // _0C, unknown
	u32 _10; // _10, unknown
	u32 _14; // _14, unknown
};

/**
 * @brief TODO
 */
struct SimpleEffect : public KEffect {
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
	u8 _0C[0x14 - 0xC]; // _0C, unknown
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
struct WhistleTemplate : public KEffect {
	virtual bool invoke(zen::particleGenerator*, zen::particleMdl*); // _24
	virtual void emit(EffectParm&);                                  // _2C
	virtual void kill();                                             // _30

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect
	// TODO: members
};

/**
 * @brief TODO
 */
struct UfoSuckEffect : public WhistleTemplate {
	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = WhistleTemplate?
	// TODO: members
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
	void kill(int);

	static void cast(int, EffectParm&);

	// TODO: members
};

extern UtEffectMgr* utEffectMgr;

#endif
