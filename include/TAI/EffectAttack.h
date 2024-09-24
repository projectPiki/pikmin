#ifndef _TAI_EFFECTATTACK_H
#define _TAI_EFFECTATTACK_H

#include "types.h"
#include "zen/CallBack.h"
#include "zen/particle.h"

struct Creature;
struct Vector3f;
struct Teki;

/**
 * @brief TODO
 */
struct TAIeffectAttackParam {
	void init();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIeffectAttackEventCallBack {

	virtual bool hitCreature(TAIeffectAttackParam*, Creature*);                                    // _08
	virtual bool hitCreature(TAIeffectAttackParam*, Creature*, Vector3f);                          // _0C
	virtual bool hitCreature(zen::particleGenerator*, TAIeffectAttackParam*, Creature*, Vector3f); // _10
	virtual bool hitMap(TAIeffectAttackParam*);                                                    // _14
	virtual void playEventSound(zen::particleGenerator*, TAIeffectAttackParam*);                   // _18
	virtual void ptclHitMap(zen::particleGenerator*, TAIeffectAttackParam*);                       // _1C
	virtual bool hitCheckCulling(zen::particleGenerator*, TAIeffectAttackParam*, Creature*);       // _20

	// TODO: members
};

/**
 * @brief TODO
 */
struct EventTypeCallBack : public zen::CallBack1<zen::particleGenerator*> {
	virtual bool invoke(zen::particleGenerator*); // _08

	// _00     = VTBL
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

/**
 * @brief TODO
 */
struct CylinderTypeCallBack : public zen::CallBack1<zen::particleGenerator*> {
	virtual bool invoke(zen::particleGenerator*); // _08

	void init(TAIeffectAttackParam*, Teki*, Vector3f&, Vector3f, f32, f32, f32, f32, TAIeffectAttackEventCallBack*);
	void hitCheckCommon(zen::particleGenerator*, Creature*);

	// unused/inlined:
	void hitCheck(zen::particleGenerator*);

	// _00     = VTBL
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

/**
 * @brief TODO
 */
struct ConeTypeCallBack : public zen::CallBack1<zen::particleGenerator*> {
	virtual bool invoke(zen::particleGenerator*); // _08

	void init(TAIeffectAttackParam*, Teki*, Vector3f&, Vector3f, f32, f32, f32, f32, TAIeffectAttackEventCallBack*);
	void hitCheckCommon(zen::particleGenerator*, Creature*);

	// unused/inlined:
	void hitCheck(zen::particleGenerator*);

	// _00     = VTBL
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

#endif
