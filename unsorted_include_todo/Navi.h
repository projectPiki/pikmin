#ifndef _NAVI_H
#define _NAVI_H

/**
 * .obj __vt__4Navi, global
 * .4byte __RTTI__4Navi
 * .4byte 0
 * .4byte addCntCallback__12RefCountableFv
 * .4byte subCntCallback__12RefCountableFv
 * .4byte insideSafeArea__8CreatureFR8Vector3f
 * .4byte platAttachable__8CreatureFv
 * .4byte alwaysUpdatePlatform__8CreatureFv
 * .4byte doDoAI__8CreatureFv
 * .4byte setRouteTracer__8CreatureFP11RouteTracer
 * .4byte init__8CreatureFv
 * .4byte init__8CreatureFR8Vector3f
 * .4byte resetPosition__8CreatureFR8Vector3f
 * .4byte initParam__8CreatureFi
 * .4byte startAI__8CreatureFi
 * .4byte getiMass__4NaviFv
 * .4byte getSize__4NaviFv
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
 * .4byte getShadowPos__8CreatureFv
 * .4byte setCentre__8CreatureFR8Vector3f
 * .4byte getShadowSize__4NaviFv
 * .4byte isVisible__4NaviFv
 * .4byte isOrganic__8CreatureFv
 * .4byte isTerrible__8CreatureFv
 * .4byte isBuried__4NaviFv
 * .4byte isAtari__4NaviFv
 * .4byte isAlive__8CreatureFv
 * .4byte isFixed__8CreatureFv
 * .4byte needShadow__8CreatureFv
 * .4byte needFlick__8CreatureFP8Creature
 * .4byte ignoreAtari__4NaviFP8Creature
 * .4byte isFree__8CreatureFv
 * .4byte stimulate__4NaviFR11Interaction
 * .4byte sendMsg__4NaviFP3Msg
 * .4byte collisionCallback__4NaviFR9CollEvent
 * .4byte bounceCallback__4NaviFv
 * .4byte jumpCallback__4NaviFv
 * .4byte wallCallback__4NaviFR5PlaneP13DynCollObject
 * .4byte offwallCallback__4NaviFP13DynCollObject
 * .4byte stickCallback__8CreatureFP8Creature
 * .4byte offstickCallback__8CreatureFP8Creature
 * .4byte stickToCallback__8CreatureFP8Creature
 * .4byte dump__4NaviFv
 * .4byte startWaterEffect__8CreatureFv
 * .4byte finishWaterEffect__8CreatureFv
 * .4byte isRopable__4NaviFv
 * .4byte mayIstick__4NaviFv
 * .4byte getFormationPri__8CreatureFv
 * .4byte update__4NaviFv
 * .4byte postUpdate__4NaviFif
 * .4byte stickUpdate__8CreatureFv
 * .4byte refresh__4NaviFR8Graphics
 * .4byte refresh2d__4NaviFR8Graphics
 * .4byte renderAtari__8CreatureFR8Graphics
 * .4byte drawShadow__8CreatureFR8Graphics
 * .4byte demoDraw__4NaviFR8GraphicsP8Matrix4f
 * .4byte getCatchPos__8CreatureFP8Creature
 * .4byte doAI__4NaviFv
 * .4byte doAnimation__8CreatureFv
 * .4byte doKill__4NaviFv
 * .4byte exitCourse__8CreatureFv
 * .4byte __RTTI__4Navi
 * .4byte 0xFFFFFD48
 * .4byte "@696@animationKeyUpdated__4NaviFR16PaniAnimKeyEvent"
 * .4byte __RTTI__4Navi
 * .4byte 0xFFFFFD44
 * .4byte viewInit__10PelletViewFv
 * .4byte "@700@viewKill__4NaviFv"
 * .4byte "@700@viewDraw__4NaviFR8GraphicsR8Matrix4f"
 * .4byte "@700@viewStartTrembleMotion__4NaviFf"
 * .4byte viewStartExplodeMotion__10PelletViewFf
 * .4byte viewSetMotionSpeed__10PelletViewFf
 * .4byte viewFinishMotion__10PelletViewFv
 * .4byte viewDoAnimation__10PelletViewFv
 * .4byte "@700@viewGetBottomRadius__4NaviFv"
 * .4byte "@700@viewGetHeight__4NaviFv"
 * .4byte viewGetScale__10PelletViewFv
 * .4byte viewKill__4NaviFv
 * .4byte viewDraw__4NaviFR8GraphicsR8Matrix4f
 * .4byte viewGetBottomRadius__4NaviFv
 * .4byte viewGetHeight__4NaviFv
 * .4byte viewStartTrembleMotion__4NaviFf
 * .4byte animationKeyUpdated__4NaviFR16PaniAnimKeyEvent
 */

struct RefCountable {
	virtual void addCntCallback(); // _08 (weak)
	virtual void subCntCallback(); // _0C (weak)
};

struct Creature {
	virtual void _08() = 0;                            // _08
	virtual void _0C() = 0;                            // _0C
	virtual void insideSafeArea(Vector3f&);            // _10 (weak)
	virtual void platAttachable();                     // _14 (weak)
	virtual void alwaysUpdatePlatform();               // _18
	virtual void doDoAI();                             // _1C (weak)
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
	virtual void getShadowPos();                       // _68 (weak)
	virtual void setCentre(Vector3f&);                 // _6C (weak)
	virtual void getShadowSize();                      // _70 (weak)
	virtual void isVisible();                          // _74
	virtual void isOrganic();                          // _78 (weak)
	virtual void isTerrible();                         // _7C
	virtual void isBuried();                           // _80
	virtual void isAtari();                            // _84
	virtual void isAlive();                            // _88 (weak)
	virtual void isFixed();                            // _8C (weak)
	virtual void needShadow();                         // _90
	virtual void needFlick(Creature*);                 // _94 (weak)
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
	virtual void stickToCallback(Creature*);           // _C4 (weak)
	virtual void dump();                               // _C8
	virtual void startWaterEffect();                   // _CC (weak)
	virtual void finishWaterEffect();                  // _D0 (weak)
	virtual void isRopable();                          // _D4
	virtual void mayIstick();                          // _D8 (weak)
	virtual void getFormationPri();                    // _DC (weak)
	virtual void update();                             // _E0
	virtual void postUpdate(int, float);               // _E4
	virtual void stickUpdate();                        // _E8
	virtual void refresh(Graphics&);                   // _EC
	virtual void refresh2d(Graphics&);                 // _F0
	virtual void renderAtari(Graphics&);               // _F4
	virtual void drawShadow(Graphics&);                // _F8
	virtual void demoDraw(Graphics&, Matrix4f*);       // _FC
	virtual void getCatchPos(Creature*);               // _100
	virtual void doAI();                               // _104
	virtual void doAnimation();                        // _108 (weak)
	virtual void doKill();                             // _10C
	virtual void exitCourse();                         // _110 (weak)
};

struct PelletView {
	virtual void _08() = 0;                            // _08
	virtual void _0C() = 0;                            // _0C
	virtual void _10() = 0;                            // _10
	virtual void _14() = 0;                            // _14
	virtual void _18() = 0;                            // _18
	virtual void _1C() = 0;                            // _1C
	virtual void _20() = 0;                            // _20
	virtual void _24() = 0;                            // _24
	virtual void _28() = 0;                            // _28
	virtual void _2C() = 0;                            // _2C
	virtual void _30() = 0;                            // _30
	virtual void _34() = 0;                            // _34
	virtual void getiMass();                           // _38
	virtual void getSize();                            // _3C
	virtual void _40() = 0;                            // _40
	virtual void _44() = 0;                            // _44
	virtual void _48() = 0;                            // _48
	virtual void _4C() = 0;                            // _4C
	virtual void _50() = 0;                            // _50
	virtual void _54() = 0;                            // _54
	virtual void _58() = 0;                            // _58
	virtual void _5C() = 0;                            // _5C
	virtual void _60() = 0;                            // _60
	virtual void _64() = 0;                            // _64
	virtual void _68() = 0;                            // _68
	virtual void _6C() = 0;                            // _6C
	virtual void getShadowSize();                      // _70 (weak)
	virtual void isVisible();                          // _74
	virtual void _78() = 0;                            // _78
	virtual void _7C() = 0;                            // _7C
	virtual void isBuried();                           // _80
	virtual void isAtari();                            // _84
	virtual void _88() = 0;                            // _88
	virtual void _8C() = 0;                            // _8C
	virtual void _90() = 0;                            // _90
	virtual void _94() = 0;                            // _94
	virtual void ignoreAtari(Creature*);               // _98
	virtual void _9C() = 0;                            // _9C
	virtual void stimulate(Interaction&);              // _A0
	virtual void sendMsg(Msg*);                        // _A4
	virtual void collisionCallback(CollEvent&);        // _A8
	virtual void bounceCallback();                     // _AC
	virtual void jumpCallback();                       // _B0
	virtual void wallCallback(Plane&, DynCollObject*); // _B4
	virtual void offwallCallback(DynCollObject*);      // _B8
	virtual void _BC() = 0;                            // _BC
	virtual void _C0() = 0;                            // _C0
	virtual void _C4() = 0;                            // _C4
	virtual void dump();                               // _C8
	virtual void _CC() = 0;                            // _CC
	virtual void _D0() = 0;                            // _D0
	virtual void isRopable();                          // _D4
	virtual void mayIstick();                          // _D8 (weak)
	virtual void _DC() = 0;                            // _DC
	virtual void update();                             // _E0
	virtual void postUpdate(int, float);               // _E4
	virtual void _E8() = 0;                            // _E8
	virtual void refresh(Graphics&);                   // _EC
	virtual void refresh2d(Graphics&);                 // _F0
	virtual void _F4() = 0;                            // _F4
	virtual void _F8() = 0;                            // _F8
	virtual void demoDraw(Graphics&, Matrix4f*);       // _FC
	virtual void _100() = 0;                           // _100
	virtual void doAI();                               // _104
	virtual void _108() = 0;                           // _108
	virtual void doKill();                             // _10C
	virtual void _110() = 0;                           // _110
	virtual void _114() = 0;                           // _114
	virtual void _118() = 0;                           // _118
	virtual void _11C() = 0;                           // _11C
	virtual void _120() = 0;                           // _120
	virtual void _124() = 0;                           // _124
	virtual void viewInit();                           // _128 (weak)
	virtual void _12C() = 0;                           // _12C
	virtual void _130() = 0;                           // _130
	virtual void _134() = 0;                           // _134
	virtual void viewStartExplodeMotion(float);        // _138 (weak)
	virtual void viewSetMotionSpeed(float);            // _13C (weak)
	virtual void viewFinishMotion();                   // _140 (weak)
	virtual void viewDoAnimation();                    // _144 (weak)
	virtual void _148() = 0;                           // _148
	virtual void _14C() = 0;                           // _14C
	virtual void viewGetScale();                       // _150 (weak)
};

/**
 * @brief TODO
 */
struct Navi : public RefCountable, public Creature, public PelletView {
	virtual void getiMass();                             // _38
	virtual void getSize();                              // _3C
	virtual void getShadowSize();                        // _70 (weak)
	virtual void isVisible();                            // _74
	virtual void isBuried();                             // _80
	virtual void isAtari();                              // _84
	virtual void ignoreAtari(Creature*);                 // _98
	virtual void stimulate(Interaction&);                // _A0
	virtual void sendMsg(Msg*);                          // _A4
	virtual void collisionCallback(CollEvent&);          // _A8
	virtual void bounceCallback();                       // _AC
	virtual void jumpCallback();                         // _B0
	virtual void wallCallback(Plane&, DynCollObject*);   // _B4
	virtual void offwallCallback(DynCollObject*);        // _B8
	virtual void dump();                                 // _C8
	virtual void isRopable();                            // _D4
	virtual void mayIstick();                            // _D8 (weak)
	virtual void update();                               // _E0
	virtual void postUpdate(int, float);                 // _E4
	virtual void refresh(Graphics&);                     // _EC
	virtual void refresh2d(Graphics&);                   // _F0
	virtual void demoDraw(Graphics&, Matrix4f*);         // _FC
	virtual void doAI();                                 // _104
	virtual void doKill();                               // _10C
	virtual void viewKill();                             // _154 (weak)
	virtual void viewDraw(Graphics&, Matrix4f&);         // _158 (weak)
	virtual void viewGetBottomRadius();                  // _15C (weak)
	virtual void viewGetHeight();                        // _160 (weak)
	virtual void viewStartTrembleMotion(float);          // _164 (weak)
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _168 (weak)

	void demoCheck();
	void isNuking();
	void startMovieInf();
	void incPlatePiki();
	void decPlatePiki();
	void getPlatePikis();
	void startDayEnd();
	void updateDayEnd(Vector3f&);
	void enterAllPikis();
	void startDamageEffect();
	void finishDamage();
	Navi(CreatureProp*, int);
	void startKontroller();
	void rideUfo();
	void reset();
	void findNextThrowPiki();
	void startMotion(PaniMotionInfo&, PaniMotionInfo&);
	void enableMotionBlend();
	void updateWalkAnimation();
	void callPikis(float);
	void callDebugs(float);
	void releasePikis();
	void procActionButton();
	void letPikiWork();
	void reviseController(Vector3f&);
	void makeVelocity(bool);
	void makeCStick(bool);
	void draw(Graphics&);
	void renderCircle(Graphics&);
	void orimaDamaged();
	void throwPiki(Piki*, Vector3f&);
	void swapMotion(PaniMotionInfo&, PaniMotionInfo&);
	void finishLook();
	void updateLook();
	void updateHeadMatrix();
};

#endif
