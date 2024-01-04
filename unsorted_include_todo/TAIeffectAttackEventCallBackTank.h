#ifndef _TAIEFFECTATTACKEVENTCALLBACKTANK_H
#define _TAIEFFECTATTACKEVENTCALLBACKTANK_H

/**
 * .obj __vt__32TAIeffectAttackEventCallBackTank, weak
 * .4byte __RTTI__32TAIeffectAttackEventCallBackTank
 * .4byte 0
 * .4byte hitCreature__32TAIeffectAttackEventCallBackTankFP20TAIeffectAttackParamP8Creature
 * .4byte hitCreature__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParamP8Creature8Vector3f
 * .4byte hitCreature__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParamP8Creature8Vector3f
 * .4byte hitMap__32TAIeffectAttackEventCallBackTankFP20TAIeffectAttackParam
 * .4byte playEventSound__32TAIeffectAttackEventCallBackTankFPQ23zen17particleGeneratorP20TAIeffectAttackParam
 * .4byte ptclHitMap__32TAIeffectAttackEventCallBackTankFPQ23zen17particleGeneratorP20TAIeffectAttackParam
 * .4byte hitCheckCulling__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParamP8Creature
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

/**
 * @brief TODO
 */
struct TAIeffectAttackEventCallBackTank : public TAIeffectAttackEventCallBack {
	virtual void hitCreature(TAIeffectAttackParam*, Creature*);                  // _08
	virtual void hitMap(TAIeffectAttackParam*);                                  // _14
	virtual void playEventSound(zen::particleGenerator*, TAIeffectAttackParam*); // _18
	virtual void ptclHitMap(zen::particleGenerator*, TAIeffectAttackParam*);     // _1C
};

#endif
