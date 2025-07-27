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
		mTeki        = nullptr;
		mCurrentTime = 0.0f;
		mDuration    = 0.0f;
		mMaxRange    = 0.0f;
		mPosition.set(0.0f, 0.0f, 0.0f);
		mVelocity.set(0.0f, 0.0f, 0.0f);
		mDirection.set(0.0f, 0.0f, 0.0f);
		mDamage      = 0.0f;
		mSubEmitter1 = mSubEmitter2 = nullptr;
		mCallBackRef                = &mEventCallBack;
		mState.b                    = 0;
		mRadius                     = 100.0f;
	}

	f32 mCurrentTime;                            // _00
	f32 mDuration;                               // _04
	f32 mRadius;                                 // _08
	f32 mMaxRange;                               // _0C
	Vector3f mPosition;                          // _10
	Vector3f mVelocity;                          // _1C
	Vector3f mDirection;                         // _28
	f32 mDamage;                                 // _34
	Teki* mTeki;                                 // _38
	zen::particleGenerator* mSubEmitter1;        // _3C
	zen::particleGenerator* mSubEmitter2;        // _40
	TAIeffectAttackEventCallBack* mCallBackRef;  // _44
	TAIeffectAttackEventCallBack mEventCallBack; // _48
	union {
		u32 mIsMoving : 1;
		u8 b; // Unused
	} mState; // _4C
};

/**
 * @brief TODO
 */
struct EventTypeCallBack : public zen::CallBack1<zen::particleGenerator*> {
public:
	virtual bool invoke(zen::particleGenerator*); // _08

	void init(TAIeffectAttackParam* param) { mParam = param; }

protected:
	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	TAIeffectAttackParam* mParam; // _04
};

/**
 * @brief TODO
 */
struct CylinderTypeCallBack : public zen::CallBack1<zen::particleGenerator*> {
public:
	virtual bool invoke(zen::particleGenerator*); // _08

	void init(TAIeffectAttackParam*, Teki*, Vector3f&, Vector3f, f32, f32, f32, f32, TAIeffectAttackEventCallBack*);
	void hitCheckCommon(zen::particleGenerator*, Creature*);

	// unused/inlined:
	void hitCheck(zen::particleGenerator*);

protected:
	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	TAIeffectAttackParam* mParam; // _04
};

/**
 * @brief TODO
 */
struct ConeTypeCallBack : public zen::CallBack1<zen::particleGenerator*> {
public:
	virtual bool invoke(zen::particleGenerator*); // _08

	void init(TAIeffectAttackParam*, Teki*, Vector3f&, Vector3f, f32, f32, f32, f32, TAIeffectAttackEventCallBack*);
	void hitCheckCommon(zen::particleGenerator*, Creature*);

	// unused/inlined:
	void hitCheck(zen::particleGenerator*);

protected:
	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	TAIeffectAttackParam* mParam; // _04
	f32 mConeHalfAngle;           // _08
};

#endif
