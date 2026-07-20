#ifndef _ACTOR_H
#define _ACTOR_H

#include "AICreature.h"
#include "Graphics.h"
#include "ItemMgr.h"
#include "MapMgr.h"
#include "ObjectMgr.h"
#include "Piki.h"
#include "SAIEvent.h"
#include "types.h"


class ActorMgr;
struct NaviProp;
struct PoliceAI;
class SimpleAI;

/**
 * @brief TODO
 *
 * @note Fun fact: The vtable for this does spawn, but then gets stripped :')
 * @note Size: 0x3DC.
 */
class Actor : public AICreature {
	friend class ActorMgr;

public:
	Actor(); // unused/inlined

	void setType(int, PikiShapeObject*, CreatureProp*, SimpleAI*);

	// unused/inlined:
	virtual void startAI(int);          // _34
	virtual void refresh(Graphics&);    // _EC
	virtual void update();              // _E0
	virtual void doAnimation();         // _108
	virtual void doAI();                // _104
	virtual void startMotion(int);      // _130
	virtual void startMotion(int, f32); // _13C
	virtual void finishMotion();        // _134
	virtual void finishMotion(f32);     // _138

protected:
	virtual void doKill(); // _10C

	// _00      = VTBL
	// _00-_304 = AICreature
	PaniPikiAnimMgr mPikiAnimMgr; // _304
	PikiShapeObject* mPikiShape;  // _3B0
	SearchData mSearchData[3];    // _3B4
	ActorMgr* mMgr;               // _3D8
};

/**
 * @brief TODO
 *
 * @note This also spawns a vtable but it gets stripped.
 */
class ActorMgr : public MonoObjectMgr {
	friend class Actor;

public:
	ActorMgr(MapMgr*); // unused/inlined

	virtual ~ActorMgr() { } // _48

	Actor* newActor(int);

protected:
	virtual Creature* createObject(); // _80

	// _00     = VTBL
	// _08     = VTBL
	// _00-_3C = MonoObjectMgr
	PaniMotionTable* mMotionTable;      // _3C
	PikiShapeObject** mShapeObjectList; // _40
	NaviProp** mNaviPropList;           // _44
	PoliceAI** mPoliceAIList;           // _48
	u32 mListsLength;                   // _4C
	MapMgr* mMapMgr;                    // _50
};

extern ActorMgr* actorMgr;

/**
 * @note DLL-exclusive class, therefore its accuracy is unverified.
 * It might not even belong in this file for all I know.
 */
struct PoliceAI : public SimpleAI {

	/**
	 * @brief TODO
	 */
	BEGIN_ENUM_TYPE(PoliceStateID)
	enum {
		StopMove     = 0,
		GoToCreature = 1,
		COUNT,
	} END_ENUM_TYPE;

	// This likely was not defined inline, but that means it exists in some file we don't know about.
	PoliceAI();

	/**
	 * @note DLL-exclusive class, therefore its accuracy is unverified.
	 */
	struct StopMove : public SAIAction {

		StopMove()
		{
			// Intentionally left blank
		}

		virtual void act(AICreature* police) // _08
		{
			police->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		}

		// _00     = VTBL
	};

	/**
	 * @note DLL-exclusive class, therefore its accuracy is unverified.
	 */
	struct GoToCreature : public SAIAction {

		GoToCreature()
		{
			// Intentionally left blank
		}

		virtual void act(AICreature* police) // _08
		{
			Vector3f displacement   = police->mSAICtx.mCollidingCreature->mSRT.t - police->mSRT.t;
			f32 norm                = displacement.normalise();
			police->mTargetVelocity = 50.0f * displacement;
		}

		// _00     = VTBL
	};

	/**
	 * @note DLL-exclusive class, therefore its accuracy is unverified.
	 */
	struct Reached : public SAICondition {

		virtual bool satisfy(AICreature* police) // _10
		{
			Vector3f displacement = police->mSAICtx.mCollidingCreature->mSRT.t - police->mSRT.t;
			f32 distance          = displacement.length();
			return distance <= mSatisfyDistance;
		}

		Reached(f32 satisfyDistance)
		    : mSatisfyDistance(satisfyDistance)
		{
		}

		// _00     = VTBL
		// _00-_14 = CoreNode
		f32 mSatisfyDistance; // _14
	};

	/**
	 * @note DLL-exclusive class, therefore its accuracy is unverified.
	 */
	struct SearchItem : public SAICondition {

		virtual bool satisfy(AICreature* police) // _10
		{
			Iterator iter(itemMgr);
			Creature* target = nullptr;
			f32 maxDistance  = 900.0f;

			Creature* candidates[16];
			int candidateCount = 0;

			CI_LOOP(iter)
			{
				Creature* item = *iter;
				if (item->mObjType == mSatisfyObjType && police->mSAICtx.mCollidingCreature != item) {
					f32 distance = qdist2(item, police);
					if (distance < maxDistance && candidateCount < ARRAY_SIZE(candidates)) {
						candidates[candidateCount++] = item;
					}
				}
			}
			if (candidateCount > 0) {
				target = candidates[static_cast<int>(gsys->getRand(1.0f) * candidateCount)];
			}

			if (target) {
				police->mSAICtx.mCollidingCreature = target;
				return true;
			}
			return false;
		}

		// The ILK names no constructor for this class.  Did they not write one?
		// This class goes unused, even in the DLL, so maybe not even a default constructor was generated?

		// _00     = VTBL
		// _00-_14 = CoreNode
		EObjType mSatisfyObjType;
	};
};

#endif
