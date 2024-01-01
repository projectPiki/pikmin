#ifndef _SLIMEEFFECT_H
#define _SLIMEEFFECT_H

/**
 * .obj __vt__11SlimeEffect, global
 * .4byte __RTTI__11SlimeEffect
 * .4byte 0
 * .4byte invoke__7KEffectFPQ23zen17particleGenerator
 * .4byte __RTTI__11SlimeEffect
 * .4byte 0xFFFFFFFC
 * .4byte "@4@invoke__11SlimeEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
 * .4byte __RTTI__11SlimeEffect
 * .4byte 0xFFFFFFF8
 * .4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
 * .4byte invoke__11SlimeEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
 * .4byte invoke__7KEffectFPQ23zen11particleMdl
 * .4byte emit__11SlimeEffectFR10EffectParm
 * .4byte kill__11SlimeEffectFv
 * .4byte stop__11SlimeEffectFv
 * .4byte restart__11SlimeEffectFv
*/

struct KEffect {
	virtual void invoke(zen::particleGenerator *);                      // _08 (weak)
	virtual void _0C() = 0;                                             // _0C
	virtual void _10() = 0;                                             // _10
	virtual void _14() = 0;                                             // _14
	virtual void _18() = 0;                                             // _18
	virtual void _1C() = 0;                                             // _1C
	virtual void _20() = 0;                                             // _20
	virtual void invoke(zen::particleGenerator *, zen::particleMdl *);  // _24
	virtual void invoke(zen::particleMdl *);                            // _28 (weak)
};

/**
 * @brief TODO
 */
struct SlimeEffect : public KEffect {
	virtual void invoke(zen::particleGenerator *, zen::particleMdl *);  // _24
	virtual void emit(EffectParm &);                                    // _2C
	virtual void kill();                                                // _30
	virtual void stop();                                                // _34
	virtual void restart();                                             // _38

};

#endif
