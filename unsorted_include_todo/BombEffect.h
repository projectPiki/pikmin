#ifndef _BOMBEFFECT_H
#define _BOMBEFFECT_H

/**
 * .obj __vt__10BombEffect, weak
 * .4byte __RTTI__10BombEffect
 * .4byte 0
 * .4byte invoke__7KEffectFPQ23zen17particleGenerator
 * .4byte __RTTI__10BombEffect
 * .4byte 0xFFFFFFFC
 * .4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
 * .4byte __RTTI__10BombEffect
 * .4byte 0xFFFFFFF8
 * .4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
 * .4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
 * .4byte invoke__7KEffectFPQ23zen11particleMdl
 * .4byte emit__10BombEffectFR10EffectParm
 * .4byte kill__10BombEffectFv
 * .4byte stop__7KEffectFv
 * .4byte restart__7KEffectFv
 */

struct KEffect {
	virtual void invoke(zen::particleGenerator*);                    // _08 (weak)
	virtual void _0C() = 0;                                          // _0C
	virtual void _10() = 0;                                          // _10
	virtual void _14() = 0;                                          // _14
	virtual void _18() = 0;                                          // _18
	virtual void _1C() = 0;                                          // _1C
	virtual void _20() = 0;                                          // _20
	virtual void invoke(zen::particleGenerator*, zen::particleMdl*); // _24 (weak)
	virtual void invoke(zen::particleMdl*);                          // _28 (weak)
	virtual void emit(EffectParm&);                                  // _2C
	virtual void kill();                                             // _30
	virtual void stop();                                             // _34 (weak)
	virtual void restart();                                          // _38 (weak)
};

/**
 * @brief TODO
 */
struct BombEffect : public KEffect {
	virtual void emit(EffectParm&); // _2C
	virtual void kill();            // _30
};

#endif
