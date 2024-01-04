#ifndef _TAIEFFECTATTACKEVENTCALLBACK_H
#define _TAIEFFECTATTACKEVENTCALLBACK_H

/**
 * .obj __vt__28TAIeffectAttackEventCallBack, weak
 * .4byte __RTTI__28TAIeffectAttackEventCallBack
 * .4byte 0
 * .4byte hitCreature__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParamP8Creature
 * .4byte hitCreature__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParamP8Creature8Vector3f
 * .4byte hitCreature__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParamP8Creature8Vector3f
 * .4byte hitMap__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParam
 * .4byte playEventSound__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParam
 * .4byte ptclHitMap__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParam
 * .4byte hitCheckCulling__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParamP8Creature
 */

/**
 * @brief TODO
 */
struct TAIeffectAttackEventCallBack {
	virtual void hitCreature(TAIeffectAttackParam*, Creature*);                                    // _08
	virtual void hitCreature(TAIeffectAttackParam*, Creature*, Vector3f);                          // _0C
	virtual void hitCreature(zen::particleGenerator*, TAIeffectAttackParam*, Creature*, Vector3f); // _10
	virtual void hitMap(TAIeffectAttackParam*);                                                    // _14
	virtual void playEventSound(zen::particleGenerator*, TAIeffectAttackParam*);                   // _18
	virtual void ptclHitMap(zen::particleGenerator*, TAIeffectAttackParam*);                       // _1C
	virtual void hitCheckCulling(zen::particleGenerator*, TAIeffectAttackParam*, Creature*);       // _20
};

#endif
