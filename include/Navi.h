#ifndef _NAVI_H
#define _NAVI_H

#include "types.h"
#include "Creature.h"
#include "Node.h"
#include "PaniAnimator.h"
#include "PelletView.h"

struct NaviState;
struct Piki;

/**
 * @brief TODO
 */
struct Navi : public Creature, public PaniAnimKeyListener, public PelletView {

	struct Locus {
		void update();
	};

	Navi(CreatureProp*, int);

	virtual f32 getiMass();                              // _38
	virtual f32 getSize();                               // _3C
	virtual f32 getShadowSize();                         // _70 (weak)
	virtual bool isVisible();                            // _74
	virtual bool isBuried();                             // _80
	virtual bool isAtari();                              // _84
	virtual bool ignoreAtari(Creature*);                 // _98
	virtual bool stimulate(Interaction&);                // _A0
	virtual void sendMsg(Msg*);                          // _A4
	virtual void collisionCallback(CollEvent&);          // _A8
	virtual void bounceCallback();                       // _AC
	virtual void jumpCallback();                         // _B0
	virtual void wallCallback(Plane&, DynCollObject*);   // _B4
	virtual void offwallCallback(DynCollObject*);        // _B8
	virtual void dump();                                 // _C8
	virtual bool isRopable();                            // _D4
	virtual bool mayIstick();                            // _D8 (weak)
	virtual void update();                               // _E0
	virtual void postUpdate(int, f32);                   // _E4
	virtual void refresh(Graphics&);                     // _EC
	virtual void refresh2d(Graphics&);                   // _F0
	virtual void demoDraw(Graphics&, Matrix4f*);         // _FC
	virtual void doAI();                                 // _104
	virtual void doKill();                               // _10C
	virtual void viewKill();                             // _154 (weak)
	virtual void viewDraw(Graphics&, Matrix4f&);         // _158 (weak)
	virtual void viewGetBottomRadius();                  // _15C (weak)
	virtual void viewGetHeight();                        // _160 (weak)
	virtual void viewStartTrembleMotion(f32);            // _164 (weak)
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
	void startKontroller();
	void rideUfo();
	void reset();
	void findNextThrowPiki();
	void startMotion(struct PaniMotionInfo&, PaniMotionInfo&);
	void enableMotionBlend();
	void updateWalkAnimation();
	void callPikis(f32);
	void callDebugs(f32);
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

	// unused/inlined:
	void startMovie(bool);
	void movieMode();
	void startDamage();
	void doMotionBlend();
	void doAttack();
	void insideOnyon();
	void procDamage(f32);
	void throwLocus(Vector3f&);
	void renderParabola(Graphics&, f32, f32);

	// _00       = VTBL
	// _000-_2B8 = Creature
	// _2B8-_2BC = PaniAnimKeyListener
	// _2BC-_2C4 = PelletView
	u8 _2C4[0x710 - 0x2C4]; // _2C4, TODO: work out members
	u32 _710;               // _710, unknown
	u8 _714[0x738 - 0x714]; // _714, TODO: work out members
	f32 _738;               // _738
	u8 _73C[0x7E4 - 0x73C]; // _73C, TODO: work out members
	u8 _7E4;                // _7E4
	u8 _7E5;                // _7E5
	u8 _7E6[0xADC - 0x7E6]; // _7E6, TODO: work out members
	NaviState* mCurrState;  // _ADC
};

/**
 * @brief TODO
 */
struct NaviDrawer : public Node {
	virtual void draw(Graphics&); // _14 (weak)

	// _00     = VTBL
	// _00-_1C = Node
	// TODO: members
};

#endif
