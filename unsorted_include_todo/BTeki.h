#ifndef _BTEKI_H
#define _BTEKI_H

/**
 * .obj __vt__5BTeki, global
 * .4byte __RTTI__5BTeki
 * .4byte 0
 * .4byte addCntCallback__12RefCountableFv
 * .4byte subCntCallback__12RefCountableFv
 * .4byte insideSafeArea__8CreatureFR8Vector3f
 * .4byte platAttachable__8CreatureFv
 * .4byte alwaysUpdatePlatform__5BTekiFv
 * .4byte doDoAI__8CreatureFv
 * .4byte setRouteTracer__8CreatureFP11RouteTracer
 * .4byte init__8CreatureFv
 * .4byte init__8CreatureFR8Vector3f
 * .4byte resetPosition__8CreatureFR8Vector3f
 * .4byte initParam__8CreatureFi
 * .4byte startAI__5BTekiFi
 * .4byte getiMass__5BTekiFv
 * .4byte getSize__8CreatureFv
 * .4byte getHeight__8CreatureFv
 * .4byte getCylinderHeight__8CreatureFv
 * .4byte doStore__5BTekiFP11CreatureInf
 * .4byte doRestore__5BTekiFP11CreatureInf
 * .4byte doSave__8CreatureFR18RandomAccessStream
 * .4byte doLoad__8CreatureFR18RandomAccessStream
 * .4byte getCentre__8CreatureFv
 * .4byte getCentreSize__8CreatureFv
 * .4byte getBoundingSphereCentre__8CreatureFv
 * .4byte getBoundingSphereRadius__8CreatureFv
 * .4byte getShadowPos__8CreatureFv
 * .4byte setCentre__8CreatureFR8Vector3f
 * .4byte getShadowSize__5BTekiFv
 * .4byte isVisible__5BTekiFv
 * .4byte isOrganic__5BTekiFv
 * .4byte isTerrible__8CreatureFv
 * .4byte isBuried__8CreatureFv
 * .4byte isAtari__5BTekiFv
 * .4byte isAlive__5BTekiFv
 * .4byte isFixed__8CreatureFv
 * .4byte needShadow__5BTekiFv
 * .4byte needFlick__8CreatureFP8Creature
 * .4byte ignoreAtari__5BTekiFP8Creature
 * .4byte isFree__8CreatureFv
 * .4byte stimulate__5BTekiFR11Interaction
 * .4byte sendMsg__8CreatureFP3Msg
 * .4byte collisionCallback__5BTekiFR9CollEvent
 * .4byte bounceCallback__5BTekiFv
 * .4byte jumpCallback__8CreatureFv
 * .4byte wallCallback__5BTekiFR5PlaneP13DynCollObject
 * .4byte offwallCallback__8CreatureFP13DynCollObject
 * .4byte stickCallback__8CreatureFP8Creature
 * .4byte offstickCallback__8CreatureFP8Creature
 * .4byte stickToCallback__8CreatureFP8Creature
 * .4byte dump__5BTekiFv
 * .4byte startWaterEffect__8CreatureFv
 * .4byte finishWaterEffect__8CreatureFv
 * .4byte isRopable__8CreatureFv
 * .4byte mayIstick__8CreatureFv
 * .4byte getFormationPri__8CreatureFv
 * .4byte update__5BTekiFv
 * .4byte postUpdate__8CreatureFif
 * .4byte stickUpdate__8CreatureFv
 * .4byte refresh__5BTekiFR8Graphics
 * .4byte refresh2d__5BTekiFR8Graphics
 * .4byte renderAtari__8CreatureFR8Graphics
 * .4byte drawShadow__8CreatureFR8Graphics
 * .4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
 * .4byte getCatchPos__8CreatureFP8Creature
 * .4byte doAI__5BTekiFv
 * .4byte doAnimation__5BTekiFv
 * .4byte doKill__5BTekiFv
 * .4byte exitCourse__5BTekiFv
 * .4byte __RTTI__5BTeki
 * .4byte 0xfffffd48
 * .4byte viewInit__10PelletViewFv
 * .4byte "@696@viewKill__5BTekiFv"
 * .4byte "@696@viewDraw__5BTekiFR8GraphicsR8Matrix4f"
 * .4byte "@696@viewStartTrembleMotion__5BTekiFf"
 * .4byte viewStartExplodeMotion__10PelletViewFf
 * .4byte "@696@viewSetMotionSpeed__5BTekiFf"
 * .4byte "@696@viewFinishMotion__5BTekiFv"
 * .4byte "@696@viewDoAnimation__5BTekiFv"
 * .4byte "@696@viewGetBottomRadius__5BTekiFv"
 * .4byte "@696@viewGetHeight__5BTekiFv"
 * .4byte "@696@viewGetScale__5BTekiFv"
 * .4byte viewStartTrembleMotion__5BTekiFf
 * .4byte viewSetMotionSpeed__5BTekiFf
 * .4byte viewDoAnimation__5BTekiFv
 * .4byte viewFinishMotion__5BTekiFv
 * .4byte viewDraw__5BTekiFR8GraphicsR8Matrix4f
 * .4byte viewKill__5BTekiFv
 * .4byte viewGetScale__5BTekiFv
 * .4byte viewGetBottomRadius__5BTekiFv
 * .4byte viewGetHeight__5BTekiFv
 * .4byte init__5BTekiFi
 * .4byte reset__5BTekiFv
 * .4byte startMotion__5BTekiFi
 * .4byte die__5BTekiFv
 * .4byte updateTimers__5BTekiFv
 * .4byte gravitate__5BTekiFf
 * .4byte animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent
 * .4byte getTekiCollisionSize__5BTekiFv
 * .4byte makeDamaged__5BTekiFv
 * .4byte startDamageMotion__5BTekiFff
 * .4byte generateTeki__5BTekiFi
 * .4byte spawnTeki__5BTekiFi
 * .4byte shootBall__5BTekiFR8Creature
 * .4byte eventPerformed__5BTekiFR9TekiEvent
 * .4byte interact__5BTekiFR18TekiInteractionKey
 * .4byte interactDefault__5BTekiFR18TekiInteractionKey
 * .4byte drawDefault__5BTekiFR8Graphics
 * .4byte drawTekiShape__5BTekiFR8Graphics
 * .4byte drawTekiDebugInfo__5BTekiFR8Graphics
 * .4byte drawTekiDebugInfoDefault__5BTekiFR8Graphics
 * .4byte playTableSound__5BTekiFi
 * .4byte playSound__5BTekiFi
 * .4byte stopSound__5BTekiFi
 * .4byte createTekiEffect__5BTekiFi
 * .4byte setTekiOption__5BTekiFi
 * .4byte clearTekiOption__5BTekiFi
 * .4byte setTekiOptions__5BTekiFi
 * .4byte clearTekiOptions__5BTekiFv
 * .4byte setAnimationKeyOption__5BTekiFi
 * .4byte clearAnimationKeyOption__5BTekiFi
 * .4byte setAnimationKeyOptions__5BTekiFi
 * .4byte clearAnimationKeyOptions__5BTekiFv
 * .4byte dieSoon__5BTekiFv
 * .4byte becomeCorpse__5BTekiFv
 * .4byte __RTTI__5BTeki
 * .4byte 0xfffffbac
 * .4byte "@1108@4@animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent"
*/

struct RefCountable {
	virtual void addCntCallback();  // _08 (weak)
	virtual void subCntCallback();  // _0C (weak)
};

struct Creature {
	virtual void _08() = 0;                               // _08
	virtual void _0C() = 0;                               // _0C
	virtual void insideSafeArea(Vector3f &);              // _10 (weak)
	virtual void platAttachable();                        // _14 (weak)
	virtual void alwaysUpdatePlatform();                  // _18
	virtual void doDoAI();                                // _1C (weak)
	virtual void setRouteTracer(RouteTracer *);           // _20 (weak)
	virtual void init();                                  // _24
	virtual void init(Vector3f &);                        // _28
	virtual void resetPosition(Vector3f &);               // _2C
	virtual void initParam(int);                          // _30 (weak)
	virtual void startAI(int);                            // _34
	virtual void getiMass();                              // _38
	virtual void getSize();                               // _3C (weak)
	virtual void getHeight();                             // _40 (weak)
	virtual void getCylinderHeight();                     // _44 (weak)
	virtual void doStore(CreatureInf *);                  // _48
	virtual void doRestore(CreatureInf *);                // _4C
	virtual void doSave(RandomAccessStream &);            // _50 (weak)
	virtual void doLoad(RandomAccessStream &);            // _54 (weak)
	virtual void getCentre();                             // _58
	virtual void getCentreSize();                         // _5C
	virtual void getBoundingSphereCentre();               // _60
	virtual void getBoundingSphereRadius();               // _64
	virtual void getShadowPos();                          // _68 (weak)
	virtual void setCentre(Vector3f &);                   // _6C (weak)
	virtual void getShadowSize();                         // _70
	virtual void isVisible();                             // _74
	virtual void isOrganic();                             // _78
	virtual void isTerrible();                            // _7C
	virtual void isBuried();                              // _80 (weak)
	virtual void isAtari();                               // _84
	virtual void isAlive();                               // _88
	virtual void isFixed();                               // _8C (weak)
	virtual void needShadow();                            // _90
	virtual void needFlick(Creature *);                   // _94 (weak)
	virtual void ignoreAtari(Creature *);                 // _98
	virtual void isFree();                                // _9C (weak)
	virtual void stimulate(Interaction &);                // _A0
	virtual void sendMsg(Msg *);                          // _A4 (weak)
	virtual void collisionCallback(CollEvent &);          // _A8
	virtual void bounceCallback();                        // _AC
	virtual void jumpCallback();                          // _B0 (weak)
	virtual void wallCallback(Plane &, DynCollObject *);  // _B4
	virtual void offwallCallback(DynCollObject *);        // _B8 (weak)
	virtual void stickCallback(Creature *);               // _BC (weak)
	virtual void offstickCallback(Creature *);            // _C0 (weak)
	virtual void stickToCallback(Creature *);             // _C4 (weak)
	virtual void dump();                                  // _C8
	virtual void startWaterEffect();                      // _CC (weak)
	virtual void finishWaterEffect();                     // _D0 (weak)
	virtual void isRopable();                             // _D4 (weak)
	virtual void mayIstick();                             // _D8 (weak)
	virtual void getFormationPri();                       // _DC (weak)
	virtual void update();                                // _E0
	virtual void postUpdate(int, float);                  // _E4
	virtual void stickUpdate();                           // _E8
	virtual void refresh(Graphics &);                     // _EC
	virtual void refresh2d(Graphics &);                   // _F0
	virtual void renderAtari(Graphics &);                 // _F4
	virtual void drawShadow(Graphics &);                  // _F8
	virtual void demoDraw(Graphics &, Matrix4f *);        // _FC
	virtual void getCatchPos(Creature *);                 // _100
};

struct PelletView {
	virtual void _08() = 0;                               // _08
	virtual void _0C() = 0;                               // _0C
	virtual void _10() = 0;                               // _10
	virtual void _14() = 0;                               // _14
	virtual void alwaysUpdatePlatform();                  // _18
	virtual void _1C() = 0;                               // _1C
	virtual void _20() = 0;                               // _20
	virtual void _24() = 0;                               // _24
	virtual void _28() = 0;                               // _28
	virtual void _2C() = 0;                               // _2C
	virtual void _30() = 0;                               // _30
	virtual void startAI(int);                            // _34
	virtual void getiMass();                              // _38
	virtual void _3C() = 0;                               // _3C
	virtual void _40() = 0;                               // _40
	virtual void _44() = 0;                               // _44
	virtual void doStore(CreatureInf *);                  // _48
	virtual void doRestore(CreatureInf *);                // _4C
	virtual void _50() = 0;                               // _50
	virtual void _54() = 0;                               // _54
	virtual void _58() = 0;                               // _58
	virtual void _5C() = 0;                               // _5C
	virtual void _60() = 0;                               // _60
	virtual void _64() = 0;                               // _64
	virtual void _68() = 0;                               // _68
	virtual void _6C() = 0;                               // _6C
	virtual void getShadowSize();                         // _70
	virtual void isVisible();                             // _74
	virtual void isOrganic();                             // _78
	virtual void _7C() = 0;                               // _7C
	virtual void _80() = 0;                               // _80
	virtual void isAtari();                               // _84
	virtual void isAlive();                               // _88
	virtual void _8C() = 0;                               // _8C
	virtual void needShadow();                            // _90
	virtual void _94() = 0;                               // _94
	virtual void ignoreAtari(Creature *);                 // _98
	virtual void _9C() = 0;                               // _9C
	virtual void stimulate(Interaction &);                // _A0
	virtual void _A4() = 0;                               // _A4
	virtual void collisionCallback(CollEvent &);          // _A8
	virtual void bounceCallback();                        // _AC
	virtual void _B0() = 0;                               // _B0
	virtual void wallCallback(Plane &, DynCollObject *);  // _B4
	virtual void _B8() = 0;                               // _B8
	virtual void _BC() = 0;                               // _BC
	virtual void _C0() = 0;                               // _C0
	virtual void _C4() = 0;                               // _C4
	virtual void dump();                                  // _C8
	virtual void _CC() = 0;                               // _CC
	virtual void _D0() = 0;                               // _D0
	virtual void _D4() = 0;                               // _D4
	virtual void _D8() = 0;                               // _D8
	virtual void _DC() = 0;                               // _DC
	virtual void update();                                // _E0
	virtual void _E4() = 0;                               // _E4
	virtual void _E8() = 0;                               // _E8
	virtual void refresh(Graphics &);                     // _EC
	virtual void refresh2d(Graphics &);                   // _F0
	virtual void _F4() = 0;                               // _F4
	virtual void _F8() = 0;                               // _F8
	virtual void _FC() = 0;                               // _FC
	virtual void _100() = 0;                              // _100
	virtual void doAI();                                  // _104
	virtual void doAnimation();                           // _108
	virtual void doKill();                                // _10C
	virtual void exitCourse();                            // _110
	virtual void _114() = 0;                              // _114
	virtual void _118() = 0;                              // _118
	virtual void viewInit();                              // _11C (weak)
	virtual void _120() = 0;                              // _120
	virtual void _124() = 0;                              // _124
	virtual void _128() = 0;                              // _128
	virtual void viewStartExplodeMotion(float);           // _12C (weak)
};

/**
 * @brief TODO
 */
struct BTeki : public RefCountable, public Creature, public PelletView {
	virtual void alwaysUpdatePlatform();                  // _18
	virtual void startAI(int);                            // _34
	virtual void getiMass();                              // _38
	virtual void doStore(CreatureInf *);                  // _48
	virtual void doRestore(CreatureInf *);                // _4C
	virtual void getShadowSize();                         // _70
	virtual void isVisible();                             // _74
	virtual void isOrganic();                             // _78
	virtual void isAtari();                               // _84
	virtual void isAlive();                               // _88
	virtual void needShadow();                            // _90
	virtual void ignoreAtari(Creature *);                 // _98
	virtual void stimulate(Interaction &);                // _A0
	virtual void collisionCallback(CollEvent &);          // _A8
	virtual void bounceCallback();                        // _AC
	virtual void wallCallback(Plane &, DynCollObject *);  // _B4
	virtual void dump();                                  // _C8
	virtual void update();                                // _E0
	virtual void refresh(Graphics &);                     // _EC
	virtual void refresh2d(Graphics &);                   // _F0
	virtual void doAI();                                  // _104
	virtual void doAnimation();                           // _108
	virtual void doKill();                                // _10C
	virtual void exitCourse();                            // _110
	virtual void viewStartTrembleMotion(float);           // _148
	virtual void viewSetMotionSpeed(float);               // _14C
	virtual void viewDoAnimation();                       // _150
	virtual void viewFinishMotion();                      // _154
	virtual void viewDraw(Graphics &, Matrix4f &);        // _158
	virtual void viewKill();                              // _15C
	virtual void viewGetScale();                          // _160
	virtual void viewGetBottomRadius();                   // _164
	virtual void viewGetHeight();                         // _168
	virtual void init(int);                               // _16C
	virtual void reset();                                 // _170
	virtual void startMotion(int);                        // _174
	virtual void die();                                   // _178
	virtual void updateTimers();                          // _17C
	virtual void gravitate(float);                        // _180
	virtual void animationKeyUpdated(PaniAnimKeyEvent &); // _184 (weak)
	virtual void getTekiCollisionSize();                  // _188
	virtual void makeDamaged();                           // _18C
	virtual void startDamageMotion(float, float);         // _190
	virtual void generateTeki(int);                       // _194
	virtual void spawnTeki(int);                          // _198
	virtual void shootBall(Creature &);                   // _19C
	virtual void eventPerformed(TekiEvent &);             // _1A0
	virtual void interact(TekiInteractionKey &);          // _1A4
	virtual void interactDefault(TekiInteractionKey &);   // _1A8
	virtual void drawDefault(Graphics &);                 // _1AC
	virtual void drawTekiShape(Graphics &);               // _1B0
	virtual void drawTekiDebugInfo(Graphics &);           // _1B4
	virtual void drawTekiDebugInfoDefault(Graphics &);    // _1B8
	virtual void playTableSound(int);                     // _1BC
	virtual void playSound(int);                          // _1C0
	virtual void stopSound(int);                          // _1C4
	virtual void createTekiEffect(int);                   // _1C8
	virtual void setTekiOption(int);                      // _1CC
	virtual void clearTekiOption(int);                    // _1D0
	virtual void setTekiOptions(int);                     // _1D4
	virtual void clearTekiOptions();                      // _1D8
	virtual void setAnimationKeyOption(int);              // _1DC
	virtual void clearAnimationKeyOption(int);            // _1E0
	virtual void setAnimationKeyOptions(int);             // _1E4
	virtual void clearAnimationKeyOptions();              // _1E8
	virtual void dieSoon();                               // _1EC
	virtual void becomeCorpse();                          // _1F0

};

#endif
