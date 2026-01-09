#ifndef _MAPPARTS_H
#define _MAPPARTS_H

#include "Animator.h"
#include "DynColl.h"
#include "ShadowCaster.h"
#include "Shape.h"
#include "types.h"

struct DynMapObject;
struct MapObjectPart;

/**
 * @brief Context info connecting an object's model and its animations.
 *
 * Stripped struct used in one ctor, but needed for genning a weak ctor.
 *
 * @note Size: 0x18.
 */
struct MapAnimShapeObject {
	Shape* mModel;            ///< _00, object's model.
	AnimContext mAnimContext; ///< _04, context info about an object's current animation.
	AnimMgr* mMgr;            ///< _14, object's animation manager.
};

/**
 * @brief Animator for a(n unused) dynamic map object.
 *
 * Advances the object's state on animation finish.
 *
 * @note Size: 0x38.
 */
struct MapObjAnimator : public Animator {

	virtual void finishOneShot(); // _10

	// _30     = VTBL
	// _00-_34 = Animator
	DynMapObject* mMapObj; ///< _34
};

/**
 * @brief Dynamic map object capable of animation, shadow casting and state transitions, with multiple sub-parts.
 *
 * Completely unused in-game.
 *
 * @note Size: 0x54C.
 */
struct DynMapObject : public DynCollShape {

	/// Animation-related state the object is in.
	enum State {
		STATE_Unk0 = 0, ///< 0, unknown - no animation files remain.
		STATE_Unk1 = 1, ///< 1, unknown - no animation files remain.
		STATE_Unk2 = 2, ///< 2, unknown - no animation files remain.
		STATE_Unk3 = 3, ///< 3, unknown - no animation files remain.
		STATE_Unk4 = 4, ///< 4, unknown - no animation files remain.
		STATE_Unk5 = 5, ///< 5, unknown - no animation files remain.
		STATE_COUNT,    ///< 6, number of states - loops from 0-5.
	};

	/// Animation for the object to play - unknown what these actually would've corresponded to, as no animations remain.
	enum AnimationID {
		MAPANIM_Unk0 = 0, ///< 0, first animation.
		MAPANIM_Unk1 = 1, ///< 1, second animation.
	};

	DynMapObject(MapMgr* map, MapAnimShapeObject* shapeObj);

	virtual void update();                                                      // _10
	virtual void draw(Graphics& gfx);                                           // _14
	virtual void touchCallback(immut Plane&, immut Vector3f&, immut Vector3f&); // _38
	virtual void refresh(Graphics& gfx);                                        // _44

	void nextState();

	// _00     = VTBL
	// _00-_140 = DynCollShape
	MapAnimShapeObject* mShapeObject; ///< _140, context wrapper for the object's model, also containing some animation info.
	MapObjAnimator mAnimator;         ///< _144, object's dedicated animator.
	MapMgr* mMapMgr;                  ///< _17C, manager for the map the object is on.
	ShadowCaster mShadowCaster;       ///< _180, shadow source for the object - cast `mDrawer` to `DynMapObject*`.
	int mState;                       ///< _518, current animation-related state of the object.
	f32 mTransitionTimer;             ///< _51C, state transition delay timer.
	SRT mSRT;                         ///< _520, scale (_520), rotation (_52C) and position (_538) of object.
	int mPlatObjCount;                ///< _544, number of platform sub-parts in object list.
	MapObjectPart** mPlatObjects;     ///< _548, list of platform sub-parts of this object.
};

/**
 * @brief Platform sub-part of DynMapObject with its own associated joint and collision.
 *
 * @note Size: 0x148.
 */
struct MapObjectPart : public DynCollShape {
	MapObjectPart(Shape* model)
	    : DynCollShape(model)
	{
		mJointIndex   = 0;
		mParentObject = nullptr;
	}

	virtual void update() { }                                                                                      // _10
	virtual void refresh(Graphics&) { }                                                                            // _44
	virtual void touchCallback(immut Plane& contactPlane, immut Vector3f& contactPos, immut Vector3f& colliderVel) // _38
	{
		if (mParentObject)
			mParentObject->touchCallback(contactPlane, contactPos, colliderVel);
	}

	// _00     = VTBL
	// _00-_140 = DynCollShape
	int mJointIndex;             ///< _140, joint index this part is connected to on parent's model.
	DynMapObject* mParentObject; ///< _144, parent object this sub-part is connected to.
};

/**
 * @brief Holder for path start and end points.
 *
 * This struct is mentioned literally once in the ILK (its compiler-generated default constructor).
 *
 * @note Size: 0x18.
 */
struct LinePath {
	Vector3f mStartPosition; ///< _00, path starting position.
	Vector3f mEndPosition;   ///< _0C, path ending position.
};

/**
 * @brief Base class for simple map elements that move or follow a path, not requiring animations or multiple parts.
 *
 * Does not move or update in base class and requires overriding.
 *
 * @note Size: 0x150.
 */
struct MapParts : public DynCollShape {
	MapParts(Shape* shape)
	    : DynCollShape(shape)
	{
		mLinePath = nullptr;
	}

	virtual void read(RandomAccessStream&) { }                                  // _0C
	virtual void update() { }                                                   // _10
	virtual void applyVelocity(immut Plane&, immut Vector3f&, immut Vector3f&); // _34
	virtual void init() { }                                                     // _48

	static immut char* getShapeFile(int);

	static immut char* shapeFiles[4];

	// _00      = VTBL
	// _00-_140 = DynCollShape
	LinePath* mLinePath; ///< _140
	Vector3f mVelocity;  ///< _144
};

/**
 * @brief Moveable map objects with friction.
 *
 * Does not follow its line path, just moves under any applied velocities.
 *
 * @note Size: 0x150.
 */
struct MapEntity : public MapParts {
	MapEntity(Shape*);

	virtual void update(); // _10

	// _00      = VTBL
	// _00-_150 = MapParts
};

/**
 * @brief Sliding platform or object, with states, triggers and timings.
 *
 * @note Size: 0x184.
 */
struct MapSlider : public MapParts {
	MapSlider(Shape*, int, int, f32, f32, f32, int);

	virtual void update();           // _10
	virtual void refresh(Graphics&); // _44
	virtual void init();             // _48

	// _00      = VTBL
	// _00-_150 = MapParts
	Vector3f mSliderPosition; ///< _150
	f32 mFaceDirection;       ///< _15C
	int mActivationCount;     ///< _160
	int mTriggerCount;        ///< _164
	f32 mHoldTime1;           ///< _168
	f32 mHoldTime2;           ///< _16C
	f32 mMoveSpeed;           ///< _170
	int mMoveMode;            ///< _174
	int mStateMode;           ///< _178
	int mDirectionMode;       ///< _17C
	f32 mTimer;               ///< _180
};

#endif
