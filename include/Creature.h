#ifndef _CREATURE_H
#define _CREATURE_H

#include "types.h"
#include "Event.h"
#include "FastGrid.h"
#include "ObjType.h"
#include "RefCountable.h"

struct CollInfo;
struct CollTriInfo;
struct CollPart;
struct Condition;
struct CreatureInf;
struct CreatureProp;
struct DynCollObject;
struct Matrix4f;
struct Msg;
struct RopeCreature;
struct RouteTracer;
struct SeContext;

/**
 * @brief TODO
 */
enum CreatureFlags {
	CF_Unk1         = 1 << 0,  // 0x1
	CF_Unk2         = 1 << 1,  // 0x2
	CF_Unk3         = 1 << 2,  // 0x4
	CF_Unk4         = 1 << 3,  // 0x8
	CF_Unk5         = 1 << 4,  // 0x10
	CF_Unk6         = 1 << 5,  // 0x20
	CF_Unk7         = 1 << 6,  // 0x40
	CF_Unk8         = 1 << 7,  // 0x80
	CF_Unk9         = 1 << 8,  // 0x100
	CF_Unk10        = 1 << 9,  // 0x200
	CF_Unk11        = 1 << 10, // 0x400
	CF_Unk12        = 1 << 11, // 0x800
	CF_Unk13        = 1 << 12, // 0x1000
	CF_Unk14        = 1 << 13, // 0x2000
	CF_Unk15        = 1 << 14, // 0x4000
	CF_StuckToMouth = 1 << 15, // 0x8000
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
	virtual void alwaysUpdatePlatform();                      // _18
	virtual bool doDoAI();                                    // _1C (weak)
	virtual void setRouteTracer(RouteTracer*);                // _20 (weak)
	virtual void init();                                      // _24
	virtual void init(Vector3f&);                             // _28
	virtual void resetPosition(Vector3f&);                    // _2C
	virtual void initParam(int);                              // _30 (weak)
	virtual void startAI(int);                                // _34 (weak)
	virtual f32 getiMass();                                   // _38 (weak)
	virtual void getSize();                                   // _3C (weak)
	virtual void getHeight();                                 // _40 (weak)
	virtual void getCylinderHeight();                         // _44 (weak)
	virtual void doStore(CreatureInf*);                       // _48 (weak)
	virtual void doRestore(CreatureInf*);                     // _4C (weak)
	virtual void doSave(struct RandomAccessStream&);          // _50 (weak)
	virtual void doLoad(RandomAccessStream&);                 // _54 (weak)
	virtual void getCentre();                                 // _58
	virtual f32 getCentreSize();                              // _5C
	virtual void getBoundingSphereCentre();                   // _60
	virtual void getBoundingSphereRadius();                   // _64
	virtual void getShadowPos();                              // _68 (weak)
	virtual void setCentre(Vector3f&);                        // _6C (weak)
	virtual void getShadowSize();                             // _70
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
	virtual void stimulate(struct Interaction&);              // _A0
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
	virtual void getCatchPos(Creature*);                      // _100
	virtual void doAI();                                      // _104 (weak)
	virtual void doAnimation();                               // _108 (weak)
	virtual void doKill() = 0;                                // _10C
	virtual void exitCourse();                                // _110 (weak)

	void finishFixPosition();
	void load(RandomAccessStream&, bool);
	void save(RandomAccessStream&, bool);
	void getCollidePlatformCreature();
	void getCollidePlatformNormal();
	bool isBoss();
	void enableStick();
	void disableStick();
	void getNearestCollPart(Vector3f&, u32);
	void getRandomCollPart(u32);
	void playEventSound(Creature*, int);
	void stopEventSound(Creature*, int);
	void getStandType();
	void getGeneratorID();
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
	void startStickObject(Creature*, CollPart*, f32);
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

	inline void setCreatureFlag(u32 flag) { mCreatureFlags |= flag; }
	inline void resetCreatureFlag(u32 flag) { mCreatureFlags &= ~flag; }
	inline bool isCreatureFlag(u32 flag) const { return mCreatureFlags & flag; }

	// _00     = VTBL
	// _00-_08 = RefCountable
	// _08-_1C = EventTalker
	u8 _1C[0x2C - 0x1C];    // _1C, TODO: work out members
	SeContext* mSeContext;  // _2C
	u8 _30[0x40 - 0x30];    // _30, TODO: work out members
	FastGrid mGrid;         // _40
	u8 _58[0x6C - 0x58];    // _58, TODO: work out members
	EObjType mObjType;      // _6C, object type
	u8 _70[0xC8 - 0x70];    // _70, TODO: work out members
	u32 mCreatureFlags;     // _C8, bitflag
	u8 _CC[0x184 - 0xCC];   // _CC, TODO: work out members
	Creature* mStickTarget; // _184, creature/object this creature is stuck to
	u8 _188[0x220 - 0x188]; // _188, TODO: work out members
	CollInfo* mCollInfo;    // _220
	CreatureProp* mProps;   // _224, creature properties
	u8 _228[0x2B5 - 0x228]; // _228, TODO: work out members
};

#endif
