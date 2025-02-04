#ifndef _KEFFECT_H
#define _KEFFECT_H

#include "types.h"
#include "zen/particle.h"
#include "zen/CallBack.h"
#include "Vector.h"

struct Creature;

/**
 * @brief TODO
 */
struct EffectParm {
	EffectParm(Vector3f* p1)
	{
		_20 = p1;
		_24 = 1.0f;
	}

	EffectParm(Vector3f& pos)
	{
		mPosition = pos;
		_24       = 1.0f;
	}

	EffectParm(Creature* owner) { _28 = owner; }

	// DLL inline ctors to make/check:
	EffectParm(Vector3f& pos, Vector3f& dir)
	{
		// need to confirm
		mPosition  = pos;
		mDirection = dir;
		_24        = 1.0f;
	}

	Vector3f mPosition;  // _00
	Vector3f mDirection; // _0C
	u8 _18[0x8];         // _18, unknown
	Vector3f* _20;       // _20
	f32 _24;             // _24
	Creature* _28;       // _28
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
	virtual void emit(EffectParm&) = 0;                                               // _2C
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

#endif
