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
	// _00-_0C = KEffect?
	// TODO: members
};

/**
 * @brief TODO
 */
struct BombEffectLight : public KEffect {
	virtual void emit(EffectParm&); // _2C
	virtual void kill();            // _30

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect?
	// TODO: members
};

/**
 * @brief TODO
 */
struct BurnEffect : public KEffect {
	virtual bool invoke(zen::particleGenerator*); // _08
	virtual void emit(EffectParm&);               // _2C
	virtual void kill();                          // _30
	virtual void stop();                          // _34
	virtual void restart();                       // _38

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect?
	// TODO: members
};

/**
 * @brief TODO
 */
struct FreeLightEffect : public KEffect {
	virtual void emit(EffectParm&); // _2C
	virtual void kill();            // _30
	virtual void stop();            // _34
	virtual void restart();         // _38

	void setScale(f32);

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect?
	// TODO: members
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
	// _00-_0C = KEffect?
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
	// _00-_0C = KEffect?
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
	// _00-_0C = KEffect?
	// TODO: members
};

/**
 * @brief TODO
 */
struct RippleEffect : public KEffect {
	virtual void emit(EffectParm&); // _2C
	virtual void kill();            // _30
	virtual void stop();            // _34
	virtual void restart();         // _38

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect?
	// TODO: members
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
	// _00-_0C = KEffect?
	// TODO: members
};

/**
 * @brief TODO
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
	// _00-_0C = KEffect?
	// TODO: members
};

/**
 * @brief TODO
 */
struct SmokeGrassEffect : public KEffect {
	virtual void emit(EffectParm&); // _2C

	// _00     = VTBL1
	// _04     = VTBL2
	// _08     = VTBL3
	// _00-_0C = KEffect?
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
	// _00-_0C = KEffect?
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
	// _00-_0C = KEffect?
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
	// _00-_0C = KEffect?
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
	// _00-_0C = KEffect?
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
	// _00-_0C = KEffect?
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
 */
struct PermanentEffect {
	PermanentEffect();

	void init(Vector3f&, int);
	void updatePos(Vector3f&);
	void changeEffect(int);
	void stop();
	void restart();
	void kill();

	// TODO: members
};

/**
 * @brief TODO
 */
struct UtEffectMgr {
	UtEffectMgr();

	void registerEffect(int, KEffect*);
	void cast(int, EffectParm&);
	void kill(int);

	// TODO: members
};

#endif
