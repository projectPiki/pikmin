#ifndef _ZEN_EFFECTMGR2D_H
#define _ZEN_EFFECTMGR2D_H

#include "types.h"
#include "zen/Callback.h"
#include "zen/particle.h"

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x4C4.
 */
struct EffectMgr2D {
	EffectMgr2D(int, int, int);

	particleGenerator* create(u32, Vector3f&, zen::CallBack1<zen::particleGenerator*>*,
	                          zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*);
	void update();
	void draw(Graphics&);
	void killAll(bool);

	// unused/inlined:
	~EffectMgr2D();

	// TODO: members
	u8 _00[0x4C4]; // _00, unknown
};

} // namespace zen

#endif
