#ifndef _CREATURE_H
#define _CREATURE_H

#include "Event.h"
#include "FastGrid.h"
#include "LifeGauge.h"
#include "Matrix4f.h"
#include "ObjType.h"
#include "RefCountable.h"
#include "SearchSystem.h"
#include "UpdateMgr.h"
#include "Vector.h"
#include "types.h"

struct CollEvent;
struct CollInfo;
struct CollTriInfo;
struct CollPart;
struct Colour;
struct Condition;
struct CreatureInf;
struct CreatureProp;
struct DynCollObject;
struct FormationMgr;
struct FormPoint;
struct Generator;
struct Graphics;
struct Interaction;
struct Matrix4f;
struct MoveTrace;
struct Msg;
struct Pellet;
struct Plane;
struct RandomAccessStream;
struct RopeCreature;
struct RouteTracer;
struct SeContext;
struct Sphere;

/**
 * @brief Bitflags stored in Creature::mCreatureFlags.
 *
 * Comments describe observed behavior in current sources.
 */
enum CreatureFlags {
	CF_Unk1                    = (1 << 0),  // 0x1, Functionally unused.
	CF_Unk2                    = (1 << 1),  // 0x2, Functionally unused.
	CF_IsOnGround              = (1 << 2),  // 0x4, On a floor triangle this frame.
	CF_Unk4                    = (1 << 3),  // 0x8, Functionally unused.
	CF_EnableAirDrag           = (1 << 4),  // 0x10, Dampen velocity using mAirResistance.
	CF_SkipPhysicsAndCollision = (1 << 5),  // 0x20, Skip moveVelocity and collisionCheck.
	CF_IsFlying                = (1 << 6),  // 0x40, Flying physics state (no gravity).
	CF_IgnoreGravity           = (1 << 7),  // 0x80, Disable gravity in moveNew.
	CF_EnableGroundOffset      = (1 << 8),  // 0x100, Trace collisions as if lowered by mGroundOffset.
	CF_DisableAutoFaceDir      = (1 << 9),  // 0x200, Don't auto-face; use quat integration.
	CF_UsePriorityFaceDir      = (1 << 10), // 0x400, Force yaw to mFaceDirection.
	CF_IsAiDisabled            = (1 << 11), // 0x800, AI paused (no doAI/moveVelocity).
	CF_Free                    = (1 << 12), // 0x1000, "Free" state, functionally unused.
	CF_IsClimbing              = (1 << 13), // 0x2000, Climbing while stuck to a climbable part.
	CF_StuckToObject           = (1 << 14), // 0x4000, Stuck-to-object mode (sphere/tube/pellet).
	CF_StuckToMouth            = (1 << 15), // 0x8000, Stuck-in-mouth mode (update early-return).
	CF_AdjustFaceDirOnSpawn    = (1 << 16), // 0x10000, Persisted; adjust facing on restore/spawn.
	CF_Unk17                   = (1 << 17), // 0x20000, Functionally unused.
	CF_DisableMovement         = (1 << 18), // 0x40000, Skip movement/rotation in update.
	CF_UseAICulling            = (1 << 19), // 0x80000, Allows culling early-return (name is inverted).
	CF_AIAlwaysActive          = (1 << 20), // 0x100000, Never culled by the AI-culling check.
	CF_IsPositionFixed         = (1 << 21), // 0x200000, Fix-position is currently active.
	CF_AllowFixPosition        = (1 << 22), // 0x400000, Enable fix-position system.
};

/**
 * @brief TODO
 */
enum CreatureStandType {
	STANDTYPE_Ground       = 0, // on a floor tri, no platform
	STANDTYPE_TekiPlatform = 1, // on a platform which has an associated creature
	STANDTYPE_Platform     = 2, // on a platform with no associated creature
	STANDTYPE_Air          = 3, // no floor tri or platform
	STANDTYPE_COUNT,
};

/**
 * @brief TODO
 *
 * @note Size: 0x2B5.
 */
struct Creature : public RefCountable, public EventTalker {
public:
	Creature(CreatureProp*);

	virtual bool insideSafeArea(immut Vector3f&) { return true; }       // _10 (weak)
	virtual bool platAttachable() { return false; }                     // _14 (weak)
	virtual bool alwaysUpdatePlatform() { return false; }               // _18
	virtual bool doDoAI() { return true; }                              // _1C (weak)
	virtual void setRouteTracer(RouteTracer*) { }                       // _20 (weak)
	virtual void init();                                                // _24
	virtual void init(immut Vector3f& pos);                             // _28
	virtual void resetPosition(immut Vector3f& pos);                    // _2C
	virtual void initParam(int) { }                                     // _30 (weak)
	virtual void startAI(int) { }                                       // _34 (weak)
	virtual f32 getiMass() { return 100.0f; }                           // _38 (weak)
	virtual f32 getSize() { return 15.0f; }                             // _3C (weak)
	virtual f32 getHeight() { return 0.0f; }                            // _40 (weak)
	virtual f32 getCylinderHeight() { return 10.0f; }                   // _44 (weak)
	virtual void doStore(CreatureInf*) { }                              // _48 (weak)
	virtual void doRestore(CreatureInf*) { }                            // _4C (weak)
	virtual void doSave(RandomAccessStream&) { }                        // _50 (weak)
	virtual void doLoad(RandomAccessStream&) { }                        // _54 (weak)
	virtual Vector3f getCentre();                                       // _58
	virtual f32 getCentreSize();                                        // _5C
	virtual Vector3f getBoundingSphereCentre();                         // _60
	virtual f32 getBoundingSphereRadius();                              // _64
	virtual Vector3f getShadowPos() { return mSRT.t; }                  // _68 (weak)
	virtual void setCentre(immut Vector3f& centre) { mSRT.t = centre; } // _6C (weak)
	virtual f32 getShadowSize();                                        // _70
	virtual bool isVisible() { return true; }                           // _74
	virtual bool isOrganic() { return true; }                           // _78 (weak)
	virtual bool isTerrible();                                          // _7C
	virtual bool isBuried() { return false; }                           // _80 (weak)
	virtual bool isAtari() { return true; }                             // _84 (weak)
	virtual bool isAlive() { return mHealth > 0.0f; }                   // _88 (weak)
	virtual bool isFixed() { return false; }                            // _8C (weak)
	virtual bool needShadow();                                          // _90
	virtual bool needFlick(Creature*) { return true; }                  // _94 (weak)
	virtual bool ignoreAtari(Creature*) { return false; }               // _98 (weak)
	virtual bool isFree() { return isCreatureFlag(CF_Free) != 0; }      // _9C (weak)
	virtual bool stimulate(immut Interaction&);                         // _A0
	virtual void sendMsg(Msg*) { }                                      // _A4 (weak)
	virtual void collisionCallback(immut CollEvent&) { }                // _A8 (weak)
	virtual void bounceCallback() { }                                   // _AC (weak)
	virtual void jumpCallback() { }                                     // _B0 (weak)
	virtual void wallCallback(immut Plane&, DynCollObject*) { }         // _B4
	virtual void offwallCallback(DynCollObject*) { }                    // _B8 (weak)
	virtual void stickCallback(Creature*) { }                           // _BC (weak)
	virtual void offstickCallback(Creature*) { }                        // _C0 (weak)
	virtual void stickToCallback(Creature*) { }                         // _C4 (weak)
	virtual void dump() { }                                             // _C8 (weak)
	virtual void startWaterEffect() { }                                 // _CC (weak)
	virtual void finishWaterEffect() { }                                // _D0 (weak)
	virtual bool isRopable() { return false; }                          // _D4 (weak)
	virtual bool mayIstick() { return false; }                          // _D8 (weak)
	virtual int getFormationPri() { return 128; }                       // _DC (weak)
	virtual void update();                                              // _E0
	virtual void postUpdate(int unused, f32 deltaTime);                 // _E4
	virtual void stickUpdate();                                         // _E8
	virtual void refresh(Graphics&) = 0;                                // _EC
	virtual void refresh2d(Graphics&) { }                               // _F0 (weak)
	virtual void renderAtari(Graphics&);                                // _F4
	virtual void drawShadow(Graphics&);                                 // _F8
	virtual void demoDraw(Graphics&, immut Matrix4f*) { }               // _FC
	virtual Vector3f getCatchPos(Creature*);                            // _100

protected:
	virtual void doAI() { }        // _104 (weak)
	virtual void doAnimation() { } // _108 (weak)
	virtual void doKill() = 0;     // _10C

public:
	virtual void exitCourse() { } // _110 (weak), public for `Creature`

	void finishFixPosition();
	void load(RandomAccessStream&, bool);
	void save(RandomAccessStream&, bool);
	Creature* getCollidePlatformCreature();
	Vector3f getCollidePlatformNormal();
	bool isBoss();
	void enableStick();
	void disableStick();
	CollPart* getNearestCollPart(immut Vector3f&, u32);
	CollPart* getRandomCollPart(u32);
	void playEventSound(Creature*, int);
	void stopEventSound(Creature*, int);
	int getStandType();
	u32 getGeneratorID();
	bool setStateGrabbed(Creature*);
	void resetStateGrabbed();
	void turnTo(immut Vector3f&);
	void detachGenerator();
	void kill(bool);
	void updateStatic();
	void updateAI();
	void moveVelocity();
	bool getAvoid(immut Vector3f&, immut Vector3f&);
	void moveRotation(f32);
	void moveNew(f32);
	Plane* getNearestPlane(CollTriInfo*);
	void interactStickers(Creature*, immut Interaction&, immut Condition*);
	void killStickers(Creature*, immut Condition*, int);
	void startClimb();
	void endClimb();
	bool isStickToPlatform();
	void startStickMouth(Creature*, CollPart*);
	void endStickMouth();
	void startStickObject(Creature*, CollPart*, int, f32);
	void endStickObject();
	bool startStick(Creature*, CollPart*);
	void endStick();
	bool startRope(RopeCreature*, f32);
	void endRope();
	void updateStickPlatform();
	void updateStickNonPlatform();
	void updateStickRope();

	// unused/inlined:
	void startFixPosition();
	bool insideSphere(immut Sphere&);
	void adjustDistance(immut Vector3f&, f32);
	int getAtariType();
	CollTriInfo* checkForward(immut Vector3f&, f32, f32&);
	CollTriInfo* getNextTri(CollTriInfo*, immut Vector3f&, int&);
	void renderCollTriInfo(Graphics&, CollTriInfo*, immut Colour&);
	bool isStickToSphere();
	void adjustStickObject(immut Vector3f&);
	bool isStickLeader();

	// these are ONE PAIR of the inlines.
	inline void setFlag80() { setCreatureFlag(CF_IgnoreGravity); }
	inline void unsetFlag80() { resetCreatureFlag(CF_IgnoreGravity); }

	inline void setFlag400() { setCreatureFlag(CF_UsePriorityFaceDir); }
	inline void resetFlag400() { resetCreatureFlag(CF_UsePriorityFaceDir); }

	// these are setFlag/resetFlag/isFlag in the DLL, but this is clearer.
	void setCreatureFlag(u32 flag) { mCreatureFlags |= flag; }
	void resetCreatureFlag(u32 flag) { mCreatureFlags &= ~flag; }
	bool isCreatureFlag(u32 flag) { return mCreatureFlags & flag; }

	void enableFixPos() { setCreatureFlag(CF_AllowFixPosition); }
	void disableFixPos() { resetCreatureFlag(CF_AllowFixPosition); }

	void startFix() { setCreatureFlag(CF_DisableMovement); }
	void finishFix() { resetCreatureFlag(CF_DisableMovement); }

	void setInsideView() { setCreatureFlag(CF_AIAlwaysActive); }
	void setOutsideView() { resetCreatureFlag(CF_AIAlwaysActive); }
	bool insideView() { return isCreatureFlag(CF_AIAlwaysActive); }

	void enableFaceDirAdjust() { setCreatureFlag(CF_AdjustFaceDirOnSpawn); }
	void disableFaceDirAdjust() { resetCreatureFlag(CF_AdjustFaceDirOnSpawn); }

	void startFlying()
	{
		setCreatureFlag(CF_IsFlying);
		resetCreatureFlag(CF_Unk2);
	}

	void finishFlying()
	{
		resetCreatureFlag(CF_IsFlying);
		setCreatureFlag(CF_Unk2);
	}

	BOOL isFlying() { return isCreatureFlag(CF_IsFlying); }

	void disableAICulling() { resetCreatureFlag(CF_UseAICulling); }
	void enableAICulling() { setCreatureFlag(CF_UseAICulling); }
	bool aiCullable() { return !isCreatureFlag(CF_UseAICulling); }

	bool isAIActive() { return !isCreatureFlag(CF_IsAiDisabled); }
	void stopAI() { setCreatureFlag(CF_IsAiDisabled); }
	void restartAI() { resetCreatureFlag(CF_IsAiDisabled); }

	BOOL isStickToMouth() { return isCreatureFlag(CF_StuckToMouth); }

	void enableGroundOffset(f32 offset)
	{
		setCreatureFlag(CF_EnableGroundOffset);
		mGroundOffset = offset;
	}

	void disableGroundOffset() { resetCreatureFlag(CF_EnableGroundOffset); }

	void setFree(bool set) { set ? setCreatureFlag(CF_Free) : resetCreatureFlag(CF_Free); }

	void enableAirResist(f32 res)
	{
		setCreatureFlag(CF_EnableAirDrag);
		mAirResistance = res;
	}

	// were these necessary Nakata.
	Vector3f& getPosition() { return mSRT.t; }
	void inputPosition(immut Vector3f& pos) { mSRT.t = pos; }
	void outputPosition(Vector3f& pos) immut { pos = mSRT.t; }

	// we're grabbed if we're held by something
	bool isGrabbed() { return !mHoldingCreature.isNull(); }
	Creature* getHolder() { return mHoldingCreature.getPtr(); }

	// we're holding if we've grabbed something
	bool isHolding() { return !mGrabbedCreature.isNull(); }
	Creature* getHoldCreature() { return mGrabbedCreature.getPtr(); }

	CollPart* getStickPart() { return mStickPart; }
	Creature* getStickObject() { return mStickTarget; }
	bool isStickTo() { return mStickTarget != nullptr; }

	bool isObjType(int type) { return mObjType == type; }

	// AKA: is this a gate?
	bool isSluice()
	{
		return mObjType == OBJTYPE_SluiceSoft || mObjType == OBJTYPE_SluiceHard || mObjType == OBJTYPE_SluiceBomb
		    || mObjType == OBJTYPE_SluiceBombHard;
	}

	bool isTeki() { return mObjType == OBJTYPE_Teki; }

	bool isPiki() { return mObjType == OBJTYPE_Piki; }

	void setRebirthDay(int day) { mRebirthDay = day; }
	int getRebirthDay() { return mRebirthDay; }

	bool roughCulling(Creature* other, f32 p2) { return mGrid.doCulling(other->mGrid, p2); }

	void setStateDamaged() { mIsBeingDamaged = true; }
	void resetStateDamaged() { mIsBeingDamaged = false; }
	bool isDamaged() { return mIsBeingDamaged; }

	/*
	    DLL inlines to assign/make:

	    f32 calcDistance(Creature&);

	    void enableGravity();
	    void disableGravity();

	    void setCarryOver();
	    void unsetCarryOver();
	*/

protected:
	void moveAttach();
	void respondColl(Creature*, f32, CollPart*, CollPart*, const Vector3f&);

	void startStickObjectSphere(Creature*, CollPart*, f32);
	void startStickObjectTube(Creature*, CollPart*);
	void startStickObjectPellet(Pellet*, int, f32);

	void updateStickSphere();
	void updateStickPellet();
	void updateStickTube();

private:
	void collisionCheck(f32);

	// Not even going to pretend this shit was ever properly encapsulated.  I don't blame them, either.
public:
	// _00     = VTBL
	// _00-_08 = RefCountable
	// _08-_1C = EventTalker
	Vector3f mFixedPosition;             // _1C
	FormPoint* mFormPoint;               // _28
	SeContext* mSeContext;               // _2C
	u8 _30;                              // _30
	int mRebirthDay;                     // _34
	u8 _38[0x40 - 0x38];                 // _38, TODO: work out members
	FastGrid mGrid;                      // _40
	f32 mHealth;                         // _58
	f32 mMaxHealth;                      // _5C
	u8 mWaterFxTimer;                    // _60
	Generator* mGenerator;               // _64
	u32 _68;                             // _68, might be int
	EObjType mObjType;                   // _6C
	Vector3f mVelocity;                  // _70
	SRT mSRT;                            // _7C scale, _88 rotation, _94 translation (position)
	f32 mFaceDirection;                  // _A0
	Vector3f mTargetVelocity;            // _A4, a.k.a. "drive"
	Vector3f _B0;                        // _B0
	Vector3f mVolatileVelocity;          // _BC
	u32 mCreatureFlags;                  // _C8, bitflag
	f32 mAirResistance;                  // _CC
	f32 mGroundOffset;                   // _D0
	Vector3f mPrevAngularVelocity;       // _D4
	Quat mRotationQuat;                  // _E0
	Quat mPreGrabRotation;               // _F0
	Quat _100;                           // _100
	f32 _110;                            // _110
	Matrix4f mConstrainedMoveMtx;        // _114, moving on a rope or falling along a fixed path, etc
	Creature* mRopeListHead;             // _154, first holder in list of holders holding onto this rope
	RopeCreature* mRope;                 // _158
	f32 mRopePosRatio;                   // _15C, how far along the rope are we
	Creature* mNextRopeHolder;           // _160, rope holder after this one in the rope list
	Creature* mPrevRopeHolder;           // _164, rope holder before this one in the rope list
	UpdateContext mSearchContext;        // _168
	UpdateContext mOptUpdateContext;     // _174
	Creature* mStickListHead;            // _180, first sticker in list of stickers stuck to this creature
	Creature* mStickTarget;              // _184, creature/object this creature is stuck to
	CollPart* mStickPart;                // _188
	Creature* mNextSticker;              // _18C, sticker after this one in the sticker list
	Creature* mPrevSticker;              // _190, sticker before this one in the sticker list
	Vector3f mAttachPosition;            // _194
	int mPelletStickSlot;                // _1A0
	u32 mHasCollChangedVelocity;         // _1A4
	u32 mCollisionOccurred;              // _1A8, unknown
	Vector3f mLastPosition;              // _1AC
	SearchBuffer mSearchBuffer;          // _1B8
	LifeGauge mLifeGauge;                // _1E0
	FormationMgr* mFormMgr;              // _21C
	CollInfo* mCollInfo;                 // _220
	CreatureProp* mProps;                // _224, creature properties
	Matrix4f mWorldMtx;                  // _228
	f32 _268;                            // _268
	f32 mSize;                           // _26C
	f32 mCollisionRadius;                // _270
	Vector3f mPositionInShapeSpace;      // _274, this is actually a wrapper around a Vector3f in the DLL, but idk what yet.
	DynCollObject* mCollPlatform;        // _280
	Vector3f* mCollPlatNormal;           // _284
	CollTriInfo* mClimbingTri;           // _288
	CollTriInfo* mGroundTriangle;        // _28C
	CollTriInfo* mPreviousTriangle;      // _290
	Shape* mCurrCollisionModel;          // _294
	u32 _298;                            // _298, unknown
	Vector3f mPlatformAdjustDelta;       // _29C, difference between platform position last frame and this frame
	SmartPtr<Creature> mHoldingCreature; // _2A8, what is holding this creature (e.g. what piki if this is a bomb)
	SmartPtr<Creature> mGrabbedCreature; // _2AC, what is this creature holding (e.g. what bomb if this is a piki)
	u32 mIsFrozen;                       // _2B0, unknown
	bool mIsBeingDamaged;                // _2B4
};

// Global helper functions:
f32 centreDist(Creature*, Creature*);
f32 sphereDist(Creature*, Creature*);
f32 qdist2(Creature*, Creature*);
f32 circleDist(Creature*, Creature*);
bool roughCull(Creature*, Creature*, f32);
void traceMove2(Creature*, MoveTrace&, f32);

#endif
