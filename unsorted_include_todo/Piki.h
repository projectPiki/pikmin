#ifndef _PIKI_H
#define _PIKI_H

/**
 * .obj __vt__4Piki, global
 * .4byte __RTTI__4Piki
 * .4byte 0
 * .4byte addCntCallback__4PikiFv
 * .4byte subCntCallback__4PikiFv
 * .4byte insideSafeArea__8CreatureFR8Vector3f
 * .4byte platAttachable__4PikiFv
 * .4byte alwaysUpdatePlatform__8CreatureFv
 * .4byte doDoAI__4PikiFv
 * .4byte setRouteTracer__8CreatureFP11RouteTracer
 * .4byte init__8CreatureFv
 * .4byte init__8CreatureFR8Vector3f
 * .4byte resetPosition__4PikiFR8Vector3f
 * .4byte initParam__8CreatureFi
 * .4byte startAI__8CreatureFi
 * .4byte getiMass__4PikiFv
 * .4byte getSize__4PikiFv
 * .4byte getHeight__8CreatureFv
 * .4byte getCylinderHeight__8CreatureFv
 * .4byte doStore__8CreatureFP11CreatureInf
 * .4byte doRestore__8CreatureFP11CreatureInf
 * .4byte doSave__8CreatureFR18RandomAccessStream
 * .4byte doLoad__8CreatureFR18RandomAccessStream
 * .4byte getCentre__8CreatureFv
 * .4byte getCentreSize__8CreatureFv
 * .4byte getBoundingSphereCentre__8CreatureFv
 * .4byte getBoundingSphereRadius__8CreatureFv
 * .4byte getShadowPos__4PikiFv
 * .4byte setCentre__8CreatureFR8Vector3f
 * .4byte getShadowSize__8CreatureFv
 * .4byte isVisible__4PikiFv
 * .4byte isOrganic__8CreatureFv
 * .4byte isTerrible__8CreatureFv
 * .4byte isBuried__4PikiFv
 * .4byte isAtari__4PikiFv
 * .4byte isAlive__4PikiFv
 * .4byte isFixed__4PikiFv
 * .4byte needShadow__4PikiFv
 * .4byte needFlick__4PikiFP8Creature
 * .4byte ignoreAtari__4PikiFP8Creature
 * .4byte isFree__8CreatureFv
 * .4byte stimulate__4PikiFR11Interaction
 * .4byte sendMsg__4PikiFP3Msg
 * .4byte collisionCallback__4PikiFR9CollEvent
 * .4byte bounceCallback__4PikiFv
 * .4byte jumpCallback__4PikiFv
 * .4byte wallCallback__4PikiFR5PlaneP13DynCollObject
 * .4byte offwallCallback__4PikiFP13DynCollObject
 * .4byte stickCallback__8CreatureFP8Creature
 * .4byte offstickCallback__8CreatureFP8Creature
 * .4byte stickToCallback__4PikiFP8Creature
 * .4byte dump__4PikiFv
 * .4byte startWaterEffect__8CreatureFv
 * .4byte finishWaterEffect__8CreatureFv
 * .4byte isRopable__4PikiFv
 * .4byte mayIstick__4PikiFv
 * .4byte getFormationPri__4PikiFv
 * .4byte update__8CreatureFv
 * .4byte postUpdate__8CreatureFif
 * .4byte stickUpdate__8CreatureFv
 * .4byte 0
 * .4byte refresh2d__8CreatureFR8Graphics
 * .4byte renderAtari__8CreatureFR8Graphics
 * .4byte drawShadow__8CreatureFR8Graphics
 * .4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
 * .4byte getCatchPos__4PikiFP8Creature
 * .4byte doAI__4PikiFv
 * .4byte doAnimation__4PikiFv
 * .4byte doKill__4PikiFv
 * .4byte exitCourse__8CreatureFv
 * .4byte __RTTI__4Piki
 * .4byte 0xFFFFFD48
 * .4byte "@696@animationKeyUpdated__4PikiFR16PaniAnimKeyEvent"
 * .4byte 0
 * .4byte animationKeyUpdated__4PikiFR16PaniAnimKeyEvent
 * .4byte initBirth__4PikiFv
 * .4byte changeShape__4PikiFi
 * .4byte setFlower__4PikiFi
 * .4byte setLeaves__4PikiFi
 */

struct Creature {
	virtual void addCntCallback();                     // _08
	virtual void subCntCallback();                     // _0C
	virtual void insideSafeArea(Vector3f&);            // _10 (weak)
	virtual void platAttachable();                     // _14
	virtual void alwaysUpdatePlatform();               // _18
	virtual void doDoAI();                             // _1C
	virtual void setRouteTracer(RouteTracer*);         // _20 (weak)
	virtual void init();                               // _24
	virtual void init(Vector3f&);                      // _28
	virtual void resetPosition(Vector3f&);             // _2C
	virtual void initParam(int);                       // _30 (weak)
	virtual void startAI(int);                         // _34 (weak)
	virtual void getiMass();                           // _38
	virtual void getSize();                            // _3C
	virtual void getHeight();                          // _40 (weak)
	virtual void getCylinderHeight();                  // _44 (weak)
	virtual void doStore(CreatureInf*);                // _48 (weak)
	virtual void doRestore(CreatureInf*);              // _4C (weak)
	virtual void doSave(RandomAccessStream&);          // _50 (weak)
	virtual void doLoad(RandomAccessStream&);          // _54 (weak)
	virtual void getCentre();                          // _58
	virtual void getCentreSize();                      // _5C
	virtual void getBoundingSphereCentre();            // _60
	virtual void getBoundingSphereRadius();            // _64
	virtual void getShadowPos();                       // _68
	virtual void setCentre(Vector3f&);                 // _6C (weak)
	virtual void getShadowSize();                      // _70
	virtual void isVisible();                          // _74
	virtual void isOrganic();                          // _78 (weak)
	virtual void isTerrible();                         // _7C
	virtual void isBuried();                           // _80
	virtual void isAtari();                            // _84
	virtual void isAlive();                            // _88
	virtual void isFixed();                            // _8C
	virtual void needShadow();                         // _90
	virtual void needFlick(Creature*);                 // _94
	virtual void ignoreAtari(Creature*);               // _98
	virtual void isFree();                             // _9C (weak)
	virtual void stimulate(Interaction&);              // _A0
	virtual void sendMsg(Msg*);                        // _A4
	virtual void collisionCallback(CollEvent&);        // _A8
	virtual void bounceCallback();                     // _AC
	virtual void jumpCallback();                       // _B0
	virtual void wallCallback(Plane&, DynCollObject*); // _B4
	virtual void offwallCallback(DynCollObject*);      // _B8
	virtual void stickCallback(Creature*);             // _BC (weak)
	virtual void offstickCallback(Creature*);          // _C0 (weak)
	virtual void stickToCallback(Creature*);           // _C4
	virtual void dump();                               // _C8
	virtual void startWaterEffect();                   // _CC (weak)
	virtual void finishWaterEffect();                  // _D0 (weak)
	virtual void isRopable();                          // _D4
	virtual void mayIstick();                          // _D8
	virtual void getFormationPri();                    // _DC
	virtual void update();                             // _E0
	virtual void postUpdate(int, f32);                 // _E4
	virtual void stickUpdate();                        // _E8
	virtual void _EC() = 0;                            // _EC
	virtual void refresh2d(Graphics&);                 // _F0 (weak)
	virtual void renderAtari(Graphics&);               // _F4
	virtual void drawShadow(Graphics&);                // _F8
	virtual void demoDraw(Graphics&, Matrix4f*);       // _FC
	virtual void getCatchPos(Creature*);               // _100
	virtual void doAI();                               // _104
	virtual void doAnimation();                        // _108
	virtual void doKill();                             // _10C
	virtual void exitCourse();                         // _110 (weak)
};

/**
 * @brief TODO
 */
struct Piki : public Creature {
	virtual void addCntCallback();                       // _08
	virtual void subCntCallback();                       // _0C
	virtual void platAttachable();                       // _14
	virtual void doDoAI();                               // _1C
	virtual void resetPosition(Vector3f&);               // _2C
	virtual void getiMass();                             // _38
	virtual void getSize();                              // _3C
	virtual void getShadowPos();                         // _68
	virtual void isVisible();                            // _74
	virtual void isBuried();                             // _80
	virtual void isAtari();                              // _84
	virtual void isAlive();                              // _88
	virtual void isFixed();                              // _8C
	virtual void needShadow();                           // _90
	virtual void needFlick(Creature*);                   // _94
	virtual void ignoreAtari(Creature*);                 // _98
	virtual void stimulate(Interaction&);                // _A0
	virtual void sendMsg(Msg*);                          // _A4
	virtual void collisionCallback(CollEvent&);          // _A8
	virtual void bounceCallback();                       // _AC
	virtual void jumpCallback();                         // _B0
	virtual void wallCallback(Plane&, DynCollObject*);   // _B4
	virtual void offwallCallback(DynCollObject*);        // _B8
	virtual void stickToCallback(Creature*);             // _C4
	virtual void dump();                                 // _C8
	virtual void isRopable();                            // _D4
	virtual void mayIstick();                            // _D8
	virtual void getFormationPri();                      // _DC
	virtual void _EC() = 0;                              // _EC
	virtual void getCatchPos(Creature*);                 // _100
	virtual void doAI();                                 // _104
	virtual void doAnimation();                          // _108
	virtual void doKill();                               // _10C
	virtual void _120() = 0;                             // _120
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _124
	virtual void initBirth();                            // _128
	virtual void changeShape(int);                       // _12C
	virtual void setFlower(int);                         // _130
	virtual void setLeaves(int);                         // _134
};

#endif
