#ifndef _PIKI_H
#define _PIKI_H

#include "types.h"
#include "Creature.h"

struct Navi;

/**
 * @brief TODO
 */
struct Piki : public Creature {
	Piki(CreatureProp*);

	virtual void addCntCallback();                              // _08
	virtual void subCntCallback();                              // _0C
	virtual void platAttachable();                              // _14
	virtual void doDoAI();                                      // _1C
	virtual void resetPosition(Vector3f&);                      // _2C
	virtual void getiMass();                                    // _38
	virtual void getSize();                                     // _3C
	virtual void getShadowPos();                                // _68
	virtual bool isVisible();                                   // _74
	virtual bool isBuried();                                    // _80
	virtual bool isAtari();                                     // _84
	virtual bool isAlive();                                     // _88
	virtual bool isFixed();                                     // _8C
	virtual bool needShadow();                                  // _90
	virtual void needFlick(Creature*);                          // _94
	virtual void ignoreAtari(Creature*);                        // _98
	virtual void stimulate(Interaction&);                       // _A0
	virtual void sendMsg(Msg*);                                 // _A4
	virtual void collisionCallback(CollEvent&);                 // _A8
	virtual void bounceCallback();                              // _AC
	virtual void jumpCallback();                                // _B0
	virtual void wallCallback(Plane&, DynCollObject*);          // _B4
	virtual void offwallCallback(DynCollObject*);               // _B8
	virtual void stickToCallback(Creature*);                    // _C4
	virtual void dump();                                        // _C8
	virtual bool isRopable();                                   // _D4
	virtual void mayIstick();                                   // _D8
	virtual void getFormationPri();                             // _DC
	virtual void getCatchPos(Creature*);                        // _100
	virtual void doAI();                                        // _104
	virtual void doAnimation();                                 // _108
	virtual void doKill();                                      // _10C
	virtual void animationKeyUpdated(struct PaniAnimKeyEvent&); // _124
	virtual void initBirth();                                   // _128
	virtual void changeShape(int);                              // _12C
	virtual void setFlower(int);                                // _130
	virtual void setLeaves(int);                                // _134

	void getSpeed(f32);
	void setSpeed(f32, Vector3f&);
	void setSpeed(f32, f32);
	void init(Navi*);
	bool isFruit();
	void updateLookCreature();
	void updateWalkAnimation();
	void realAI();
	void changeMode(int, Navi*);
	void startHimaLook(Vector3f*);
	void finishLook();
	bool isLooking();
	void updateLook();
	void demoCheck();
	bool isSafeMePos(Vector3f&);
	void startDemo();
	void finishDemo();
	void appearDemo();
	void getUpperMotionIndex();
	void getAttackPower();
	void findRoute(int, int, bool, bool);
	void moveRouteTraceDynamic(f32);
	void initRouteTrace(Vector3f&, bool);
	void moveRouteTrace(f32);
	void crGetPoint(int);
	void crPointOpen(int);
	void crGetRadius(int);
	void crMakeRefs();
	bool hasBomb();
	void startFire();
	void endFire();
	bool isTeki(Piki*);
	void actOnSituaton(); // dev spelling
	void getState();
	void graspSituation(Creature**);
	void initColor(int);
	void startKinoko();
	void endKinoko();
	void setColor(int);
	void setPastel();
	void unsetPastel();
	void updateColor();
	void startDamage();
	void finishDamage();
	bool isThrowable();
	void startMotion(struct PaniMotionInfo&, PaniMotionInfo&);
	void enableMotionBlend();
	void checkBridgeWall(Creature*, Vector3f&);

	// _00      = VTBL
	// _00-_2B8 = Creature
	u8 _2B8[0x585 - 0x2B8]; // _2B8, TODO: work out members
};

#endif
