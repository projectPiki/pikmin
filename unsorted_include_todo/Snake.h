#ifndef _SNAKE_H
#define _SNAKE_H

/**
 * .obj __vt__5Snake, global
 * .4byte __RTTI__5Snake
 * .4byte 0
 * .4byte addCntCallback__12RefCountableFv
 * .4byte subCntCallback__12RefCountableFv
 * .4byte insideSafeArea__8CreatureFR8Vector3f
 * .4byte platAttachable__8CreatureFv
 * .4byte alwaysUpdatePlatform__8CreatureFv
 * .4byte doDoAI__8CreatureFv
 * .4byte setRouteTracer__8CreatureFP11RouteTracer
 * .4byte init__8CreatureFv
 * .4byte init__5SnakeFR8Vector3f
 * .4byte resetPosition__8CreatureFR8Vector3f
 * .4byte initParam__8CreatureFi
 * .4byte startAI__8CreatureFi
 * .4byte getiMass__5SnakeFv
 * .4byte getSize__8CreatureFv
 * .4byte getHeight__8CreatureFv
 * .4byte getCylinderHeight__8CreatureFv
 * .4byte doStore__8CreatureFP11CreatureInf
 * .4byte doRestore__8CreatureFP11CreatureInf
 * .4byte doSave__8CreatureFR18RandomAccessStream
 * .4byte doLoad__8CreatureFR18RandomAccessStream
 * .4byte getCentre__4BossFv
 * .4byte getCentreSize__5SnakeFv
 * .4byte getBoundingSphereCentre__8CreatureFv
 * .4byte getBoundingSphereRadius__8CreatureFv
 * .4byte getShadowPos__8CreatureFv
 * .4byte setCentre__8CreatureFR8Vector3f
 * .4byte getShadowSize__4BossFv
 * .4byte isVisible__4BossFv
 * .4byte isOrganic__4BossFv
 * .4byte isTerrible__8CreatureFv
 * .4byte isBuried__8CreatureFv
 * .4byte isAtari__4BossFv
 * .4byte isAlive__4BossFv
 * .4byte isFixed__4BossFv
 * .4byte needShadow__4BossFv
 * .4byte needFlick__8CreatureFP8Creature
 * .4byte ignoreAtari__4BossFP8Creature
 * .4byte isFree__8CreatureFv
 * .4byte stimulate__4BossFR11Interaction
 * .4byte sendMsg__8CreatureFP3Msg
 * .4byte collisionCallback__4BossFR9CollEvent
 * .4byte bounceCallback__8CreatureFv
 * .4byte jumpCallback__8CreatureFv
 * .4byte wallCallback__4BossFR5PlaneP13DynCollObject
 * .4byte offwallCallback__8CreatureFP13DynCollObject
 * .4byte stickCallback__8CreatureFP8Creature
 * .4byte offstickCallback__8CreatureFP8Creature
 * .4byte stickToCallback__8CreatureFP8Creature
 * .4byte dump__8CreatureFv
 * .4byte startWaterEffect__8CreatureFv
 * .4byte finishWaterEffect__8CreatureFv
 * .4byte isRopable__8CreatureFv
 * .4byte mayIstick__8CreatureFv
 * .4byte getFormationPri__8CreatureFv
 * .4byte update__5SnakeFv
 * .4byte postUpdate__8CreatureFif
 * .4byte stickUpdate__8CreatureFv
 * .4byte refresh__5SnakeFR8Graphics
 * .4byte refresh2d__5SnakeFR8Graphics
 * .4byte renderAtari__8CreatureFR8Graphics
 * .4byte drawShadow__8CreatureFR8Graphics
 * .4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
 * .4byte getCatchPos__8CreatureFP8Creature
 * .4byte doAI__5SnakeFv
 * .4byte doAnimation__5SnakeFv
 * .4byte doKill__5SnakeFv
 * .4byte exitCourse__5SnakeFv
 * .4byte isBossBgm__4BossFv
 * .4byte attackDefaultPortion__4BossFv
 * .4byte bombDamageCounter__4BossFP8CollPart
 * .4byte drawShape__5SnakeFR8Graphics
 */

struct RefCountable {
	virtual void addCntCallback(); // _08 (weak)
	virtual void subCntCallback(); // _0C (weak)
};

struct Creature {
	virtual void _08() = 0;                       // _08
	virtual void _0C() = 0;                       // _0C
	virtual void insideSafeArea(Vector3f&);       // _10 (weak)
	virtual void platAttachable();                // _14 (weak)
	virtual void alwaysUpdatePlatform();          // _18
	virtual void doDoAI();                        // _1C (weak)
	virtual void setRouteTracer(RouteTracer*);    // _20 (weak)
	virtual void init();                          // _24
	virtual void init(Vector3f&);                 // _28
	virtual void resetPosition(Vector3f&);        // _2C
	virtual void initParam(int);                  // _30 (weak)
	virtual void startAI(int);                    // _34 (weak)
	virtual f32 getiMass();                      // _38
	virtual void getSize();                       // _3C (weak)
	virtual void getHeight();                     // _40 (weak)
	virtual void getCylinderHeight();             // _44 (weak)
	virtual void doStore(CreatureInf*);           // _48 (weak)
	virtual void doRestore(CreatureInf*);         // _4C (weak)
	virtual void doSave(RandomAccessStream&);     // _50 (weak)
	virtual void doLoad(RandomAccessStream&);     // _54 (weak)
	virtual void _58() = 0;                       // _58
	virtual f32 getCentreSize();                 // _5C
	virtual void getBoundingSphereCentre();       // _60
	virtual void getBoundingSphereRadius();       // _64
	virtual void getShadowPos();                  // _68 (weak)
	virtual void setCentre(Vector3f&);            // _6C (weak)
	virtual void _70() = 0;                       // _70
	virtual void _74() = 0;                       // _74
	virtual void _78() = 0;                       // _78
	virtual void isTerrible();                    // _7C
	virtual void isBuried();                      // _80 (weak)
	virtual void _84() = 0;                       // _84
	virtual void _88() = 0;                       // _88
	virtual void _8C() = 0;                       // _8C
	virtual void _90() = 0;                       // _90
	virtual void needFlick(Creature*);            // _94 (weak)
	virtual void _98() = 0;                       // _98
	virtual void isFree();                        // _9C (weak)
	virtual void _A0() = 0;                       // _A0
	virtual void sendMsg(Msg*);                   // _A4 (weak)
	virtual void _A8() = 0;                       // _A8
	virtual void bounceCallback();                // _AC (weak)
	virtual void jumpCallback();                  // _B0 (weak)
	virtual void _B4() = 0;                       // _B4
	virtual void offwallCallback(DynCollObject*); // _B8 (weak)
	virtual void stickCallback(Creature*);        // _BC (weak)
	virtual void offstickCallback(Creature*);     // _C0 (weak)
	virtual void stickToCallback(Creature*);      // _C4 (weak)
	virtual void dump();                          // _C8 (weak)
	virtual void startWaterEffect();              // _CC (weak)
	virtual void finishWaterEffect();             // _D0 (weak)
	virtual void isRopable();                     // _D4 (weak)
	virtual void mayIstick();                     // _D8 (weak)
	virtual void getFormationPri();               // _DC (weak)
	virtual void update();                        // _E0
	virtual void postUpdate(int, float);          // _E4
	virtual void stickUpdate();                   // _E8
	virtual void refresh(Graphics&);              // _EC
	virtual void refresh2d(Graphics&);            // _F0
	virtual void renderAtari(Graphics&);          // _F4
	virtual void drawShadow(Graphics&);           // _F8
	virtual void demoDraw(Graphics&, Matrix4f*);  // _FC
	virtual void getCatchPos(Creature*);          // _100
};

struct Boss {
	virtual void _08() = 0;                            // _08
	virtual void _0C() = 0;                            // _0C
	virtual void _10() = 0;                            // _10
	virtual void _14() = 0;                            // _14
	virtual void _18() = 0;                            // _18
	virtual void _1C() = 0;                            // _1C
	virtual void _20() = 0;                            // _20
	virtual void _24() = 0;                            // _24
	virtual void init(Vector3f&);                      // _28
	virtual void _2C() = 0;                            // _2C
	virtual void _30() = 0;                            // _30
	virtual void _34() = 0;                            // _34
	virtual f32 getiMass();                           // _38
	virtual void _3C() = 0;                            // _3C
	virtual void _40() = 0;                            // _40
	virtual void _44() = 0;                            // _44
	virtual void _48() = 0;                            // _48
	virtual void _4C() = 0;                            // _4C
	virtual void _50() = 0;                            // _50
	virtual void _54() = 0;                            // _54
	virtual void getCentre();                          // _58
	virtual f32 getCentreSize();                      // _5C
	virtual void _60() = 0;                            // _60
	virtual void _64() = 0;                            // _64
	virtual void _68() = 0;                            // _68
	virtual void _6C() = 0;                            // _6C
	virtual void getShadowSize();                      // _70
	virtual void isVisible();                          // _74
	virtual void isOrganic();                          // _78
	virtual void _7C() = 0;                            // _7C
	virtual void _80() = 0;                            // _80
	virtual void isAtari();                            // _84
	virtual void isAlive();                            // _88
	virtual void isFixed();                            // _8C
	virtual void needShadow();                         // _90
	virtual void _94() = 0;                            // _94
	virtual void ignoreAtari(Creature*);               // _98
	virtual void _9C() = 0;                            // _9C
	virtual void stimulate(Interaction&);              // _A0
	virtual void _A4() = 0;                            // _A4
	virtual void collisionCallback(CollEvent&);        // _A8
	virtual void _AC() = 0;                            // _AC
	virtual void _B0() = 0;                            // _B0
	virtual void wallCallback(Plane&, DynCollObject*); // _B4
	virtual void _B8() = 0;                            // _B8
	virtual void _BC() = 0;                            // _BC
	virtual void _C0() = 0;                            // _C0
	virtual void _C4() = 0;                            // _C4
	virtual void _C8() = 0;                            // _C8
	virtual void _CC() = 0;                            // _CC
	virtual void _D0() = 0;                            // _D0
	virtual void _D4() = 0;                            // _D4
	virtual void _D8() = 0;                            // _D8
	virtual void _DC() = 0;                            // _DC
	virtual void update();                             // _E0
	virtual void _E4() = 0;                            // _E4
	virtual void _E8() = 0;                            // _E8
	virtual void refresh(Graphics&);                   // _EC
	virtual void refresh2d(Graphics&);                 // _F0
	virtual void _F4()  = 0;                           // _F4
	virtual void _F8()  = 0;                           // _F8
	virtual void _FC()  = 0;                           // _FC
	virtual void _100() = 0;                           // _100
	virtual void doAI();                               // _104
	virtual void doAnimation();                        // _108
	virtual void doKill();                             // _10C
	virtual void exitCourse();                         // _110
	virtual void isBossBgm();                          // _114
	virtual void attackDefaultPortion();               // _118
	virtual void bombDamageCounter(CollPart*);         // _11C
};

/**
 * @brief TODO
 */
struct Snake : public RefCountable, public Creature, public Boss {
	virtual void init(Vector3f&);      // _28
	virtual f32 getiMass();           // _38
	virtual f32 getCentreSize();      // _5C
	virtual void update();             // _E0
	virtual void refresh(Graphics&);   // _EC
	virtual void refresh2d(Graphics&); // _F0
	virtual void doAI();               // _104
	virtual void doAnimation();        // _108
	virtual void doKill();             // _10C
	virtual void exitCourse();         // _110
	virtual void drawShape(Graphics&); // _120
};

#endif
