#ifndef _KEFFECT_H
#define _KEFFECT_H

/**
 * .obj __vt__7KEffect, weak
 * .4byte __RTTI__7KEffect
 * .4byte 0
 * .4byte invoke__7KEffectFPQ23zen17particleGenerator
 * .4byte __RTTI__7KEffect
 * .4byte 0xFFFFFFFC
 * .4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
 * .4byte __RTTI__7KEffect
 * .4byte 0xFFFFFFF8
 * .4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
 * .4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
 * .4byte invoke__7KEffectFPQ23zen11particleMdl
 * .4byte 0
 * .4byte kill__7KEffectFv
 * .4byte stop__7KEffectFv
 * .4byte restart__7KEffectFv
*/

/**
 * @brief TODO
 */
struct KEffect {
	virtual void invoke(zen::particleGenerator *);                      // _08 (weak)
	virtual void invoke(zen::particleGenerator *, zen::particleMdl *);  // _24 (weak)
	virtual void invoke(zen::particleMdl *);                            // _28 (weak)
	virtual void _2C() = 0;                                             // _2C
	virtual void kill();                                                // _30 (weak)
	virtual void stop();                                                // _34 (weak)
	virtual void restart();                                             // _38 (weak)

};

#endif
