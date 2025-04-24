#ifndef _TAI_EFFECTATTACK_H
#define _TAI_EFFECTATTACK_H

#include "types.h"
#include "zen/CallBack.h"
#include "zen/particle.h"

struct Creature;
struct Vector3f;
struct Teki;
struct TAIeffectAttackParam;

/**
 * @brief TODO
 */
struct TAIeffectAttackEventCallBack {

	virtual bool hitCreature(TAIeffectAttackParam*, Creature*) { return false; }                                    // _08
	virtual bool hitCreature(TAIeffectAttackParam*, Creature*, Vector3f) { return false; }                          // _0C
	virtual bool hitCreature(zen::particleGenerator*, TAIeffectAttackParam*, Creature*, Vector3f) { return false; } // _10
	virtual bool hitMap(TAIeffectAttackParam*) { return false; }                                                    // _14
	virtual void playEventSound(zen::particleGenerator*, TAIeffectAttackParam*) { }                                 // _18
	virtual void ptclHitMap(zen::particleGenerator*, TAIeffectAttackParam*) { }                                     // _1C
	virtual bool hitCheckCulling(zen::particleGenerator*, TAIeffectAttackParam*, Creature*) { return true; }        // _20

	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIeffectAttackParam {
	TAIeffectAttackParam() { init(); }

	void init()
	{
		mTeki = nullptr;
		_00   = 0.0f;
		_04   = 0.0f;
		_0C   = 0.0f;
		mPosition.set(0.0f, 0.0f, 0.0f);
		mVelocity.set(0.0f, 0.0f, 0.0f);
		_28.set(0.0f, 0.0f, 0.0f);
		_34 = 0.0f;
		_3C = _40 = nullptr;
		_44       = &mEventCallBack;
		_4C.b     = 0;
		_08       = 100.0f;
	}

	f32 _00;                                     // _00
	f32 _04;                                     // _04
	f32 _08;                                     // _08
	f32 _0C;                                     // _0C
	Vector3f mPosition;                          // _10
	Vector3f mVelocity;                          // _1C
	Vector3f _28;                                // _28
	f32 _34;                                     // _34
	Teki* mTeki;                                 // _38
	zen::particleGenerator* _3C;                 // _3C
	zen::particleGenerator* _40;                 // _40
	TAIeffectAttackEventCallBack* _44;           // _44
	TAIeffectAttackEventCallBack mEventCallBack; // _48
	union {
		u32 m0 : 1;
		u8 b;
	} _4C; // _4C
};

/**
 * @brief TODO
 */
struct EventTypeCallBack : public zen::CallBack1<zen::particleGenerator*> {
	virtual bool invoke(zen::particleGenerator*); // _08

	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	TAIeffectAttackParam* mParam; // _04
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
	// _00-_04 = zen::CallBack1
	TAIeffectAttackParam* mParam; // _04
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
	// _00-_04 = zen::CallBack1
	TAIeffectAttackParam* mParam; // _04
	f32 _08;                      // _08
};

#endif
