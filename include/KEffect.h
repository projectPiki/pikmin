#ifndef _KEFFECT_H
#define _KEFFECT_H

#include "types.h"
#include "zen/particle.h"
#include "zen/CallBack.h"

/**
 * @brief TODO
 */
struct EffectParm {
	// TODO: members
};

/**
 * @brief TODO
 */
struct KEffect : public zen::CallBack1<zen::particleGenerator*>,
                 public zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>,
                 public zen::CallBack1<zen::particleMdl*> {
	virtual bool invoke(zen::particleGenerator*);                    // _08 (weak)
	virtual bool invoke(zen::particleGenerator*, zen::particleMdl*); // _24 (weak)
	virtual bool invoke(zen::particleMdl*);                          // _28 (weak)
	virtual void emit(EffectParm&) = 0;                              // _2C
	virtual void kill();                                             // _30 (weak)
	virtual void stop();                                             // _34 (weak)
	virtual void restart();                                          // _38 (weak)

	// _00 = VTBL1
	// _04 = VTBL2
	// _08 = VTBL3
	// _00-_04 = CallBack1<gen>
	// _04-_08 = CallBack2<gen, mdl>
	// _08-_0C = CallBack1<mdl>
	// TODO: members
};

#endif
