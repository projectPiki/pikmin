#ifndef _TAIEFFECTATTACKEVENTCALLBACKHIBAA_H
#define _TAIEFFECTATTACKEVENTCALLBACKHIBAA_H

/**
 * .obj __vt__33TAIeffectAttackEventCallBackHibaA, weak
 * .4byte __RTTI__33TAIeffectAttackEventCallBackHibaA
 * .4byte 0
 * .4byte hitCreature__33TAIeffectAttackEventCallBackHibaAFP20TAIeffectAttackParamP8Creature
 * .4byte hitCreature__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParamP8Creature8Vector3f
 * .4byte hitCreature__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParamP8Creature8Vector3f
 * .4byte hitMap__33TAIeffectAttackEventCallBackHibaAFP20TAIeffectAttackParam
 * .4byte playEventSound__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParam
 * .4byte ptclHitMap__33TAIeffectAttackEventCallBackHibaAFPQ23zen17particleGeneratorP20TAIeffectAttackParam
 * .4byte hitCheckCulling__33TAIeffectAttackEventCallBackHibaAFPQ23zen17particleGeneratorP20TAIeffectAttackParamP8Creature
 */

struct TAIeffectAttackEventCallBack {
	virtual void hitCreature(TAIeffectAttackParam*, Creature*);                                    // _08
	virtual void hitCreature(TAIeffectAttackParam*, Creature*, Vector3f);                          // _0C
	virtual void hitCreature(zen::particleGenerator*, TAIeffectAttackParam*, Creature*, Vector3f); // _10
	virtual void hitMap(TAIeffectAttackParam*);                                                    // _14
	virtual void playEventSound(zen::particleGenerator*, TAIeffectAttackParam*);                   // _18
};

/**
 * @brief TODO
 */
struct TAIeffectAttackEventCallBackHibaA : public TAIeffectAttackEventCallBack {
	virtual void hitCreature(TAIeffectAttackParam*, Creature*);                              // _08
	virtual void hitMap(TAIeffectAttackParam*);                                              // _14
	virtual void ptclHitMap(zen::particleGenerator*, TAIeffectAttackParam*);                 // _1C
	virtual void hitCheckCulling(zen::particleGenerator*, TAIeffectAttackParam*, Creature*); // _20
};

#endif
