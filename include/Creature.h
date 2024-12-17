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
	CF_Unk1           = 1 << 0,  // 0x1
	CF_Unk2           = 1 << 1,  // 0x2
	CF_Unk3           = 1 << 2,  // 0x4
	CF_Unk4           = 1 << 3,  // 0x8
	CF_Unk5           = 1 << 4,  // 0x10
	CF_Unk6           = 1 << 5,  // 0x20
	CF_Unk7           = 1 << 6,  // 0x40
	CF_Unk8           = 1 << 7,  // 0x80
	CF_Unk9           = 1 << 8,  // 0x100
	CF_Unk10          = 1 << 9,  // 0x200
	CF_Unk11          = 1 << 10, // 0x400
	CF_Unk12          = 1 << 11, // 0x800
	CF_Free           = 1 << 12, // 0x1000
	CF_Unk14          = 1 << 13, // 0x2000
	CF_StuckToObject  = 1 << 14, // 0x4000, stuck to an object
	CF_StuckToMouth   = 1 << 15, // 0x8000, stuck to mouth of some enemy
	CF_Unk16          = 1 << 16, // 0x10000
	CF_Unk17          = 1 << 17, // 0x20000
	CF_Unk18          = 1 << 18, // 0x40000
	CF_Unk19          = 1 << 19, // 0x80000, use result flags maybe?
	CF_AIAlwaysActive = 1 << 20, // 0x100000, do not cull AI when off-camera
	CF_FixPosition    = 1 << 21, // 0x200000
	CF_Unk22          = 1 << 22, // 0x400000
};

/**
 * @brief TODO
 */
enum CreatureStandType {
	STANDTYPE_Unk0 = 0,
	STANDTYPE_Unk1 = 1,
	STANDTYPE_Unk2 = 2,
	STANDTYPE_Unk3 = 3,
};

/**
 * @brief TODO
 *
 * @note Size: 0x2B5.
 */
struct Creature : public RefCountable, public EventTalker {
	Creature(CreatureProp*);

	virtual bool insideSafeArea(struct Vector3f&);            // _10 (weak)
	virtual bool platAttachable();                            // _14 (weak)
	virtual bool alwaysUpdatePlatform();                      // _18
	virtual bool doDoAI();                                    // _1C (weak)
	virtual void setRouteTracer(RouteTracer*);                // _20 (weak)
	virtual void init();                                      // _24
	virtual void init(Vector3f&);                             // _28
	virtual void resetPosition(Vector3f&);                    // _2C
	virtual void initParam(int);                              // _30 (weak)
	virtual void startAI(int);                                // _34 (weak)
	virtual f32 getiMass();                                   // _38 (weak)
	virtual f32 getSize();                                    // _3C (weak)
	virtual f32 getHeight();                                  // _40 (weak)
	virtual f32 getCylinderHeight();                          // _44 (weak)
	virtual void doStore(CreatureInf*);                       // _48 (weak)
	virtual void doRestore(CreatureInf*);                     // _4C (weak)
	virtual void doSave(struct RandomAccessStream&);          // _50 (weak)
	virtual void doLoad(RandomAccessStream&);                 // _54 (weak)
	virtual Vector3f getCentre();                             // _58
	virtual f32 getCentreSize();                              // _5C
	virtual Vector3f getBoundingSphereCentre();               // _60
	virtual f32 getBoundingSphereRadius();                    // _64
	virtual Vector3f getShadowPos();                          // _68 (weak)
	virtual void setCentre(Vector3f&);                        // _6C (weak)
	virtual f32 getShadowSize();                              // _70
	virtual bool isVisible() { return true; }                 // _74
	virtual bool isOrganic();                                 // _78 (weak)
	virtual bool isTerrible();                                // _7C
	virtual bool isBuried();                                  // _80 (weak)
	virtual bool isAtari() { return true; }                   // _84 (weak)
	virtual bool isAlive();                                   // _88 (weak)
	virtual bool isFixed();                                   // _8C (weak)
	virtual bool needShadow();                                // _90
	virtual bool needFlick(Creature*);                        // _94 (weak)
	virtual bool ignoreAtari(Creature*);                      // _98 (weak)
	virtual bool isFree();                                    // _9C (weak)
	virtual bool stimulate(struct Interaction&);              // _A0
	virtual void sendMsg(Msg*);                               // _A4 (weak)
	virtual void collisionCallback(struct CollEvent&) { }     // _A8 (weak)
	virtual void bounceCallback() { }                         // _AC (weak)
	virtual void jumpCallback();                              // _B0 (weak)
	virtual void wallCallback(struct Plane&, DynCollObject*); // _B4
	virtual void offwallCallback(DynCollObject*);             // _B8 (weak)
	virtual void stickCallback(Creature*);                    // _BC (weak)
	virtual void offstickCallback(Creature*);                 // _C0 (weak)
	virtual void stickToCallback(Creature*);                  // _C4 (weak)
	virtual void dump();                                      // _C8 (weak)
	virtual void startWaterEffect();                          // _CC (weak)
	virtual void finishWaterEffect();                         // _D0 (weak)
	virtual bool isRopable();                                 // _D4 (weak)
	virtual bool mayIstick();                                 // _D8 (weak)
	virtual int getFormationPri();                            // _DC (weak)
	virtual void update();                                    // _E0
	virtual void postUpdate(int, f32);                        // _E4
	virtual void stickUpdate();                               // _E8
	virtual void refresh(struct Graphics&) = 0;               // _EC
	virtual void refresh2d(Graphics&);                        // _F0 (weak)
	virtual void renderAtari(Graphics&);                      // _F4
	virtual void drawShadow(Graphics&);                       // _F8
	virtual void demoDraw(Graphics&, Matrix4f*);              // _FC
	virtual Vector3f getCatchPos(Creature*);                  // _100
	virtual void doAI();                                      // _104 (weak)
	virtual void doAnimation();                               // _108 (weak)
	virtual void doKill() = 0;                                // _10C
	virtual void exitCourse();                                // _110 (weak)

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
	u8 getAvoid(Vector3f&, Vector3f&);
	void respondColl(Creature*, f32, CollPart*, CollPart*, const Vector3f&);
	void moveRotation(f32);
	void moveAttach();
	void moveNew(f32);
	void getNearestPlane(CollTriInfo*);
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
	void startStick(Creature*, CollPart*);
	void endStick();
	void startRope(RopeCreature*, f32);
	void endRope();
	void updateStickPlatform();
	void updateStickNonPlatform();
	void updateStickSphere();
	void updateStickPellet();
	void updateStickTube();
	void updateStickRope();

	// unused/inlined:
	void startFixPosition();
	void insideSphere(struct Sphere&);
	void adjustDistance(Vector3f&, f32);
	void getAtariType();
	void checkForward(Vector3f&, f32, f32&);
	void getNextTri(CollTriInfo*, Vector3f&, int&);
	void renderCollTriInfo(Graphics&, CollTriInfo*, Colour&);
	void isStickToSphere();
	void adjustStickObject(Vector3f&);
	void startStickObjectPellet(Pellet*, int, f32);
	void isStickLeader();

	inline void setCreatureFlag(u32 flag) { mCreatureFlags |= flag; }
	inline void resetCreatureFlag(u32 flag) { mCreatureFlags &= ~flag; }
	inline bool isCreatureFlag(u32 flag) const { return mCreatureFlags & flag; }

	inline Vector3f& getPosition() { return mPosition; }

	inline bool isWall()
	{
		return mObjType == OBJTYPE_SluiceSoft || mObjType == OBJTYPE_SluiceHard || mObjType == OBJTYPE_SluiceBomb
		    || mObjType == OBJTYPE_SluiceBombHard;
	}

	inline void reset70andA4()
	{ // TODO: rename when we know what _70 and _A4 are
		_70.reset();
		_A4.reset();
	}

	inline bool isStuckTo(Creature* creature) { return mStickTarget == creature; }

	inline CollPart* getStickPart() { return _188; }

	inline Creature* get2AC() { return _2AC; }

	// _00     = VTBL
	// _00-_08 = RefCountable
	// _08-_1C = EventTalker
	Vector3f _1C;               // _1C
	u32 _28;                    // _28, unknown
	SeContext* mSeContext;      // _2C
	u8 _30;                     // _30
	int _34;                    // _34
	u8 _38[0x40 - 0x38];        // _38, TODO: work out members
	FastGrid mGrid;             // _40
	f32 mHealth;                // _58
	f32 _5C;                    // _5C
	u8 _60;                     // _60
	Generator* mGenerator;      // _64
	u32 _68;                    // _68, might be int
	EObjType mObjType;          // _6C, object type
	Vector3f _70;               // _70
	Vector3f mScale;            // _7C
	Vector3f mRotation;         // _88
	Vector3f mPosition;         // _94
	f32 mDirection;             // _A0
	Vector3f _A4;               // _A4
	Vector3f _B0;               // _B0
	Vector3f _BC;               // _BC
	u32 mCreatureFlags;         // _C8, bitflag
	u32 _CC;                    // _CC
	f32 _D0;                    // _D0
	Vector3f _D4;               // _D4
	Quat _E0;                   // _E0
	Quat _F0;                   // _F0
	Quat _100;                  // _100
	f32 _110;                   // _110
	Matrix4f _114;              // _114
	Creature* _154;             // _154
	u32 _158;                   // _158, maybe Rope* or RopeCreature*?
	f32 _15C;                   // _15C
	u32 _160;                   // _160, unknown
	u32 _164;                   // _164, unknown
	UpdateContext _168;         // _168
	UpdateContext _174;         // _174
	Creature* _180;             // _180, unknown
	Creature* mStickTarget;     // _184, creature/object this creature is stuck to
	CollPart* _188;             // _188
	Creature* _18C;             // _18C, unknown
	u32 _190;                   // _190, unknown
	Vector3f _194;              // _194
	int _1A0;                   // _1A0
	u32 _1A4;                   // _1A4
	u8 _1A8[0x4];               // _1A8, unknown
	Vector3f _1AC;              // _1AC
	SearchBuffer mSearchBuffer; // _1B8
	LifeGauge mLifeGauge;       // _1E0
	u32 _21C;                   // _21C, unknown
	CollInfo* mCollInfo;        // _220
	CreatureProp* mProps;       // _224, creature properties
	Matrix4f _228;              // _228
	f32 _268;                   // _268
	f32 _26C;                   // _26C
	f32 mCollisionRadius;       // _270
	Vector3f _274;              // _274
	DynCollObject* _280;        // _280
	Vector3f* _284;             // _284, coll plat normal maybe?
	u32 _288;                   // _288, unknown
	CollTriInfo* mFloorTri;     // _28C
	u32 _290;                   // _290, unknown
	u8 _294[0x4];               // _294, unknown
	u32 _298;                   // _298, unknown
	Vector3f _29C;              // _29C
	Creature* _2A8;             // _2A8
	Creature* _2AC;             // _2AC
	u32 _2B0;                   // _2B0, unknown
	bool mIsBeingDamaged;       // _2B4
};

// Global helper functions:
f32 centreDist(Creature*, Creature*);
f32 sphereDist(Creature*, Creature*);
f32 qdist2(Creature*, Creature*);
f32 circleDist(Creature*, Creature*);
bool roughCull(Creature*, Creature*, f32);

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
