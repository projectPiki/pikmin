#ifndef _KEFFECT_H
#define _KEFFECT_H

#include "Vector.h"
#include "types.h"
#include "zen/CallBack.h"
#include "zen/particle.h"

struct Creature;

/**
 * @brief TODO
 */
struct EffectParm {
	EffectParm(immut Vector3f* pos)
	{
		mPositionRef = pos;
		mScale       = 1.0f;
	}

	EffectParm(immut Vector3f& pos)
	{
		mPosition = pos;
		mScale    = 1.0f;
	}

	EffectParm(Creature* owner) { mOwner = owner; }

	// DLL inline ctors to make/check:
	EffectParm(immut Vector3f& pos, immut Vector3f& dir)
	{
		// need to confirm
		mPosition  = pos;
		mDirection = dir;
		mScale     = 1.0f;
	}

	Vector3f mPosition;           // _00
	Vector3f mDirection;          // _0C
	u8 _18[0x8];                  // _18, unknown
	immut Vector3f* mPositionRef; // _20
	f32 mScale;                   // _24
	Creature* mOwner;             // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct KEffect : public zen::CallBack1<zen::particleGenerator*>,
                 public zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>,
                 public zen::CallBack1<zen::particleMdl*> {
	virtual bool invoke(zen::particleGenerator*) { return false; }                    // _08 (weak)
	virtual bool invoke(zen::particleGenerator*, zen::particleMdl*) { return false; } // _24 (weak)
	virtual bool invoke(zen::particleMdl*) { return false; }                          // _28 (weak)
	virtual void emit(immut EffectParm&) = 0;                                         // _2C
	virtual void kill() { }                                                           // _30 (weak)
	virtual void stop() { }                                                           // _34 (weak)
	virtual void restart() { }                                                        // _38 (weak)

	// _00 = VTBL1
	// _04 = VTBL2
	// _08 = VTBL3
	// _00-_04 = CallBack1<gen>
	// _04-_08 = CallBack2<gen, mdl>
	// _08-_0C = CallBack1<mdl>
};

/**
 * @brief TODO
 *
 * @note Size: 0x14.
 */
struct SlimeEffect : public KEffect {
	SlimeEffect();

	virtual bool invoke(zen::particleGenerator*, zen::particleMdl*); // _24
	virtual void emit(immut EffectParm&);                            // _2C
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

#endif
