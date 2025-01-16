#ifndef _CREATURE_H
#define _CREATURE_H

#include "types.h"
#include "Event.h"
#include "FastGrid.h"
#include "ObjType.h"
#include "RefCountable.h"
#include "SearchSystem.h"
#include "LifeGauge.h"
#include "UpdateMgr.h"
#include "Vector.h"
#include "Matrix4f.h"

struct CollInfo;
struct CollTriInfo;
struct CollPart;
struct Colour;
struct Condition;
struct CreatureInf;
struct CreatureProp;
struct DynCollObject;
struct Generator;
struct Matrix4f;
struct MoveTrace;
struct Msg;
struct Pellet;
struct RopeCreature;
struct RouteTracer;
struct SeContext;

/**
 * @brief TODO
 */
enum CreatureFlags {
	CF_Unk1                = 1 << 0,  // 0x1
	CF_GravityEnabled      = 1 << 1,  // 0x2
	CF_IsOnGround          = 1 << 2,  // 0x4
	CF_Unk4                = 1 << 3,  // 0x8
	CF_Unk5                = 1 << 4,  // 0x10
	CF_Unk6                = 1 << 5,  // 0x20
	CF_IsFlying            = 1 << 6,  // 0x40
	CF_Unk8                = 1 << 7,  // 0x80
	CF_GroundOffsetEnabled = 1 << 8,  // 0x100
	CF_Unk10               = 1 << 9,  // 0x200
	CF_Unk11               = 1 << 10, // 0x400
	CF_IsAiDisabled        = 1 << 11, // 0x800, aka aiSTOP
	CF_Free                = 1 << 12, // 0x1000
	CF_IsClimbing          = 1 << 13, // 0x2000
	CF_StuckToObject       = 1 << 14, // 0x4000, stuck to an object
	CF_StuckToMouth        = 1 << 15, // 0x8000, stuck to mouth of some enemy
	CF_FaceDirAdjust       = 1 << 16, // 0x10000
	CF_Unk17               = 1 << 17, // 0x20000
	CF_Unk18               = 1 << 18, // 0x40000
	CF_IsAICullingActive   = 1 << 19, // 0x80000, creature is off camera
	CF_AIAlwaysActive      = 1 << 20, // 0x100000, do not cull AI when off-camera
	CF_FixPosition         = 1 << 21, // 0x200000
	CF_Unk22               = 1 << 22, // 0x400000
};

/**
 * @brief TODO
 */
enum CreatureStandType {
	STANDTYPE_Ground       = 0, // on a floor tri, no platform
	STANDTYPE_TekiPlatform = 1, // on a platform which has an associated creature
	STANDTYPE_Platform     = 2, // on a platform with no associated creature
	STANDTYPE_Air          = 3, // no floor tri or platform
};

/**
 * @brief TODO
 *
 * @note Size: 0x2B5.
 */
struct Creature : public RefCountable, public EventTalker {
	Creature(CreatureProp*);

	virtual bool insideSafeArea(struct Vector3f&) { return true; }   // _10 (weak)
	virtual bool platAttachable() { return false; }                  // _14 (weak)
	virtual bool alwaysUpdatePlatform();                             // _18
	virtual bool doDoAI() { return true; }                           // _1C (weak)
	virtual void setRouteTracer(RouteTracer*) { }                    // _20 (weak)
	virtual void init();                                             // _24
	virtual void init(Vector3f& pos);                                // _28
	virtual void resetPosition(Vector3f& pos);                       // _2C
	virtual void initParam(int) { }                                  // _30 (weak)
	virtual void startAI(int) { }                                    // _34 (weak)
	virtual f32 getiMass() { return 100.0f; }                        // _38 (weak)
	virtual f32 getSize() { return 15.0f; }                          // _3C (weak)
	virtual f32 getHeight() { return 0.0f; }                         // _40 (weak)
	virtual f32 getCylinderHeight() { return 10.0f; }                // _44 (weak)
	virtual void doStore(CreatureInf*) { }                           // _48 (weak)
	virtual void doRestore(CreatureInf*) { }                         // _4C (weak)
	virtual void doSave(struct RandomAccessStream&) { }              // _50 (weak)
	virtual void doLoad(RandomAccessStream&) { }                     // _54 (weak)
	virtual Vector3f getCentre();                                    // _58
	virtual f32 getCentreSize();                                     // _5C
	virtual Vector3f getBoundingSphereCentre();                      // _60
	virtual f32 getBoundingSphereRadius();                           // _64
	virtual Vector3f getShadowPos() { return mPosition; }            // _68 (weak)
	virtual void setCentre(Vector3f& centre) { mPosition = centre; } // _6C (weak)
	virtual f32 getShadowSize();                                     // _70
	virtual bool isVisible() { return true; }                        // _74
	virtual bool isOrganic() { return true; }                        // _78 (weak)
	virtual bool isTerrible();                                       // _7C
	virtual bool isBuried() { return false; }                        // _80 (weak)
	virtual bool isAtari() { return true; }                          // _84 (weak)
	virtual bool isAlive() { return mHealth > 0.0f; }                // _88 (weak)
	virtual bool isFixed() { return false; }                         // _8C (weak)
	virtual bool needShadow();                                       // _90
	virtual bool needFlick(Creature*) { return true; }               // _94 (weak)
	virtual bool ignoreAtari(Creature*) { return false; }            // _98 (weak)
	virtual bool isFree() { return isCreatureFlag(CF_Free) != 0; }   // _9C (weak)
	virtual bool stimulate(struct Interaction&);                     // _A0
	virtual void sendMsg(Msg*) { }                                   // _A4 (weak)
	virtual void collisionCallback(struct CollEvent&) { }            // _A8 (weak)
	virtual void bounceCallback() { }                                // _AC (weak)
	virtual void jumpCallback() { }                                  // _B0 (weak)
	virtual void wallCallback(struct Plane&, DynCollObject*);        // _B4
	virtual void offwallCallback(DynCollObject*) { }                 // _B8 (weak)
	virtual void stickCallback(Creature*) { }                        // _BC (weak)
	virtual void offstickCallback(Creature*) { }                     // _C0 (weak)
	virtual void stickToCallback(Creature*) { }                      // _C4 (weak)
	virtual void dump() { }                                          // _C8 (weak)
	virtual void startWaterEffect() { }                              // _CC (weak)
	virtual void finishWaterEffect() { }                             // _D0 (weak)
	virtual bool isRopable() { return false; }                       // _D4 (weak)
	virtual bool mayIstick() { return false; }                       // _D8 (weak)
	virtual int getFormationPri() { return 128; }                    // _DC (weak)
	virtual void update();                                           // _E0
	virtual void postUpdate(int, f32);                               // _E4
	virtual void stickUpdate();                                      // _E8
	virtual void refresh(struct Graphics&) = 0;                      // _EC
	virtual void refresh2d(Graphics&) { }                            // _F0 (weak)
	virtual void renderAtari(Graphics&);                             // _F4
	virtual void drawShadow(Graphics&);                              // _F8
	virtual void demoDraw(Graphics&, Matrix4f*);                     // _FC
	virtual Vector3f getCatchPos(Creature*);                         // _100
	virtual void doAI() { }                                          // _104 (weak)
	virtual void doAnimation() { }                                   // _108 (weak)
	virtual void doKill() = 0;                                       // _10C
	virtual void exitCourse() { }                                    // _110 (weak)

	void finishFixPosition();
	void load(RandomAccessStream&, bool);
	void save(RandomAccessStream&, bool);
	Creature* getCollidePlatformCreature();
	Vector3f getCollidePlatformNormal();
	bool isBoss();
	void enableStick();
	void disableStick();
	CollPart* getNearestCollPart(Vector3f&, u32);
	CollPart* getRandomCollPart(u32);
	void playEventSound(Creature*, int);
	void stopEventSound(Creature*, int);
	int getStandType();
	u32 getGeneratorID();
	bool setStateGrabbed(Creature*);
	void resetStateGrabbed();
	void turnTo(Vector3f&);
	void detachGenerator();
	void kill(bool);
	void updateStatic();
	void updateAI();
	void collisionCheck(f32);
	void moveVelocity();
	bool getAvoid(Vector3f&, Vector3f&);
	void respondColl(Creature*, f32, CollPart*, CollPart*, const Vector3f&);
	void moveRotation(f32);
	void moveAttach();
	void moveNew(f32);
	Plane* getNearestPlane(CollTriInfo*);
	void interactStickers(Creature*, Interaction&, Condition*);
	void killStickers(Creature*, Condition*, int);
	void startClimb();
	void endClimb();
	bool isStickToPlatform();
	void startStickMouth(Creature*, CollPart*);
	void endStickMouth();
	void startStickObjectSphere(Creature*, CollPart*, f32);
	void startStickObjectTube(Creature*, CollPart*);
	void startStickObject(Creature*, CollPart*, int, f32);
	void endStickObject();
	bool startStick(Creature*, CollPart*);
	void endStick();
	bool startRope(RopeCreature*, f32);
	void endRope();
	void updateStickPlatform();
	void updateStickNonPlatform();
	void updateStickSphere();
	void updateStickPellet();
	void updateStickTube();
	void updateStickRope();

	// unused/inlined:
	void startFixPosition();
	bool insideSphere(struct Sphere&);
	void adjustDistance(Vector3f&, f32);
	int getAtariType();
	CollTriInfo* checkForward(Vector3f&, f32, f32&);
	CollTriInfo* getNextTri(CollTriInfo*, Vector3f&, int&);
	void renderCollTriInfo(Graphics&, CollTriInfo*, Colour&);
	bool isStickToSphere();
	void adjustStickObject(Vector3f&);
	void startStickObjectPellet(Pellet*, int, f32);
	bool isStickLeader();

	inline void setUnk22() { setCreatureFlag(CF_Unk22); }
	inline void resetUnk22() { resetCreatureFlag(CF_Unk22); } // TODO: rename this to one of the DLL inlines later

	// this is a guess name-wise
	void restartAI() { setCreatureFlag(CF_AIAlwaysActive); }

	// these are setFlag/resetFlag/isFlag in the DLL, but this is clearer.
	void setCreatureFlag(u32 flag) { mCreatureFlags |= flag; }
	void resetCreatureFlag(u32 flag) { mCreatureFlags &= ~flag; }
	bool isCreatureFlag(u32 flag) { return mCreatureFlags & flag; }

	Vector3f& getPosition() { return mPosition; }

	void disableFaceDirAdjust() { resetCreatureFlag(CF_FaceDirAdjust); } // this should be one of the disable inlines

	void startFlying()
	{
		setCreatureFlag(CF_IsFlying);
		resetCreatureFlag(CF_GravityEnabled);
	}

	void disableAICulling() { resetCreatureFlag(CF_IsAICullingActive); }
	void enableAICulling() { setCreatureFlag(CF_IsAICullingActive); }
	bool aiCullable() { return !isCreatureFlag(CF_IsAICullingActive); }

	// we're grabbed if we're held by something
	bool isGrabbed() { return !mHoldingCreature.isNull(); }
	Creature* getHolder() { return mHoldingCreature.getPtr(); }

	// we're holding if we've grabbed something
	bool isHolding() { return !mGrabbedCreature.isNull(); }
	Creature* getHoldCreature() { return mGrabbedCreature.getPtr(); }

	// idk why this is a BOOL and not bool but go figure
	BOOL isStickToMouth() { return isCreatureFlag(CF_StuckToMouth); }

	CollPart* getStickPart() { return mStickPart; }
	Creature* getStickObject() { return mStickTarget; }
	bool isStickTo() { return mStickTarget != nullptr; }
	bool doAlwaysUpdate() { return !isCreatureFlag(CF_IsAICullingActive); }

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

	void enableGroundOffset(f32 offset)
	{
		setCreatureFlag(CF_GroundOffsetEnabled);
		mGroundOffset = offset;
	}

	void disableGroundOffset() { resetCreatureFlag(CF_GroundOffsetEnabled); }

	/*
	    DLL inlines to assign/make:
	    bool insideView();
	    bool isAIActive();
	    bool isDamaged();
	    bool isObjType(int);
	    BOOL isFlying();

	    f32 calcDistance(Creature&);

	    void enableFaceDirAdjust();
	    void disableFaceDirAdjust();

	    void enableFixPos();
	    void disableFixPos();

	    void enableGravity();
	    void disableGravity();

	    void enableAirResist(f32);

	    void startFix();
	    void finishFix();

	    void finishFlying();

	    void inputPosition(Vector3f&);
	    void outputPosition(Vector3f&);

	    void setStateDamaged();
	    void resetStateDamaged();

	    void restartAI();
	    void stopAI();

	    void setCarryOver();
	    void unsetCarryOver();

	    void setFree(bool);
	    void setInsideView();
	    void setOutsideView();
	*/

	// _00     = VTBL
	// _00-_08 = RefCountable
	// _08-_1C = EventTalker
	Vector3f mFixedPosition;             // _1C
	u32 _28;                             // _28, unknown
	SeContext* mSeContext;               // _2C
	u8 _30;                              // _30
	int mRebirthDay;                     // _34
	u8 _38[0x40 - 0x38];                 // _38, TODO: work out members
	FastGrid mGrid;                      // _40
	f32 mHealth;                         // _58
	f32 mMaxHealth;                      // _5C
	u8 _60;                              // _60
	Generator* mGenerator;               // _64
	u32 _68;                             // _68, might be int
	EObjType mObjType;                   // _6C
	Vector3f mVelocity;                  // _70
	Vector3f mScale;                     // _7C, NB: these 3 vectors are an SRT according to DLL
	Vector3f mRotation;                  // _88, but I really don't want that extra level to access these
	Vector3f mPosition;                  // _94, just a heads up in case it becomes important
	f32 mDirection;                      // _A0
	Vector3f mTargetVelocity;            // _A4, a.k.a. "drive"
	Vector3f _B0;                        // _B0
	Vector3f mVolatileVelocity;          // _BC
	u32 mCreatureFlags;                  // _C8, bitflag
	u32 _CC;                             // _CC
	f32 mGroundOffset;                   // _D0
	Vector3f mPrevAngularVelocity;       // _D4
	Quat mRotationQuat;                  // _E0
	Quat mPreGrabRotation;               // _F0
	Quat _100;                           // _100
	f32 _110;                            // _110
	Matrix4f _114;                       // _114
	Creature* mRopeListHead;             // _154, first holder in list of holders holding onto this rope
	RopeCreature* mRope;                 // _158
	f32 mRopeRatio;                      // _15C, how far along the rope are we
	Creature* mNextRopeHolder;           // _160, rope holder after this one in the rope list
	Creature* mPrevRopeHolder;           // _164, rope holder before this one in the rope list
	UpdateContext _168;                  // _168
	UpdateContext _174;                  // _174
	Creature* mStickListHead;            // _180, first sticker in list of stickers stuck to this creature
	Creature* mStickTarget;              // _184, creature/object this creature is stuck to
	CollPart* mStickPart;                // _188
	Creature* mNextSticker;              // _18C, sticker after this one in the sticker list
	Creature* mPrevSticker;              // _190, sticker before this one in the sticker list
	Vector3f _194;                       // _194
	int mPelletStickSlot;                // _1A0
	u32 _1A4;                            // _1A4
	u32 _1A8;                            // _1A8, unknown
	Vector3f _1AC;                       // _1AC
	SearchBuffer mSearchBuffer;          // _1B8
	LifeGauge mLifeGauge;                // _1E0
	u32 _21C;                            // _21C, unknown
	CollInfo* mCollInfo;                 // _220
	CreatureProp* mProps;                // _224, creature properties
	Matrix4f mTransformMatrix;           // _228
	f32 _268;                            // _268
	f32 _26C;                            // _26C
	f32 mCollisionRadius;                // _270
	Vector3f _274;                       // _274, this is actually a wrapper around a Vector3f in the DLL, but idk what yet.
	DynCollObject* mCollPlatform;        // _280
	Vector3f* mCollPlatNormal;           // _284
	u32 _288;                            // _288, unknown
	CollTriInfo* mFloorTri;              // _28C
	u32 _290;                            // _290, unknown
	u8 _294[0x4];                        // _294, unknown
	u32 _298;                            // _298, unknown
	Vector3f _29C;                       // _29C
	SmartPtr<Creature> mHoldingCreature; // _2A8, what is holding this creature (e.g. what piki if this is a bomb)
	SmartPtr<Creature> mGrabbedCreature; // _2AC, what is this creature holding (e.g. what bomb if this is a piki)
	u32 _2B0;                            // _2B0, unknown
	bool mIsBeingDamaged;                // _2B4
};

// Global helper functions:
f32 centreDist(Creature*, Creature*);
f32 sphereDist(Creature*, Creature*);
f32 qdist2(Creature*, Creature*);
f32 circleDist(Creature*, Creature*);
bool roughCull(Creature*, Creature*, f32);

// these are probably SmartPtr inlines, or creature inlines - TODO: fix.
// these are the things that make the most sense so far, this code comes up in weird spots
inline void resetCreature(Creature*& creature)
{
	if (creature) {
		creature->subCnt();
		creature = nullptr;
	}
}

inline void postSetCreature(Creature*& creature)
{
	if (creature) {
		creature->addCnt();
	}
}

#endif
