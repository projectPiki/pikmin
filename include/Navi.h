#ifndef _NAVI_H
#define _NAVI_H

#include "types.h"
#include "Creature.h"
#include "Node.h"
#include "PaniAnimator.h"
#include "PaniPikiAnimator.h"
#include "PelletView.h"
#include "MapMgr.h"
#include "Piki.h"

struct CPlate;
struct BurnEffect;
struct RippleEffect;
struct PermanentEffect;
struct SlimeEffect;
struct Kontroller;
struct NaviDrawer;
struct NaviStateMachine;
struct GoalItem;
struct NaviState;
struct Piki;
struct PikiHeadItem;

#define NAVI_PROP         (static_cast<NaviProp*>(mProps)->mNaviProps)
#define C_NAVI_PROP(navi) (static_cast<NaviProp*>((navi)->mProps)->mNaviProps)

/**
 * @brief TODO
 */
struct Navi : public Creature, public PaniAnimKeyListener, public PelletView {

	struct Locus {
		Locus(); // DLL, todo

		void update();

		Vector3f _00;        // _00
		Vector3f _0C;        // _0C
		PermanentEffect _18; // _18
	};

	Navi(CreatureProp*, int);

	virtual f32 getiMass();                              // _38
	virtual f32 getSize();                               // _3C
	virtual f32 getShadowSize() { return 20.0f; }        // _70 (weak)
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
	virtual bool mayIstick() { return false; }           // _D8 (weak)
	virtual void update();                               // _E0
	virtual void postUpdate(int, f32);                   // _E4
	virtual void refresh(Graphics&);                     // _EC
	virtual void refresh2d(Graphics&);                   // _F0
	virtual void demoDraw(Graphics&, Matrix4f*);         // _FC
	virtual void doAI();                                 // _104
	virtual void doKill();                               // _10C
	virtual void viewKill();                             // _154 (weak)
	virtual void viewDraw(Graphics&, Matrix4f&);         // _158 (weak)
	virtual f32 viewGetBottomRadius();                   // _15C (weak)
	virtual f32 viewGetHeight();                         // _160 (weak)
	virtual void viewStartTrembleMotion(f32);            // _164 (weak)
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _168 (weak)

	bool demoCheck();
	bool isNuking();
	void startMovieInf();
	void incPlatePiki();
	void decPlatePiki();
	int getPlatePikis();
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
	bool procActionButton();
	void letPikiWork();
	void reviseController(Vector3f&);
	void makeVelocity(bool);
	void makeCStick(bool);
	void draw(Graphics&);
	void renderCircle(Graphics&);
	bool orimaDamaged();
	void throwPiki(Piki*, Vector3f&);
	void swapMotion(PaniMotionInfo&, PaniMotionInfo&);
	void finishLook();
	void updateLook();
	void updateHeadMatrix();

	// unused/inlined:
	void startMovie(bool);
	bool movieMode();
	bool startDamage();
	bool doMotionBlend();
	void doAttack();
	bool insideOnyon();
	void procDamage(f32);
	void throwLocus(Vector3f&);
	void renderParabola(Graphics&, f32, f32);

	AState<Navi>* getCurrState() { return mCurrState; }
	void setCurrState(AState<Navi>* state) { mCurrState = state; }

	void setPellet(bool isPellet) { mIsPellet = isPellet; }

	/*
	    DLL inlines:

	    bool isPellet();

	    void forceFinishLook();
	    void startLook(Vector3f*);
	*/

	// _00       = VTBL
	// _000-_2B8 = Creature
	// _2B8-_2BC = PaniAnimKeyListener
	// _2BC-_2C4 = PelletView
	OdoMeter mOdoMeter;                  // _2C4
	zen::particleGenerator* mDamageEfxA; // _2D4
	zen::particleGenerator* mDamageEfxB; // _2D8
	zen::particleGenerator* mDamageEfxC; // _2DC
	u8 _2E0;                             // _2E0
	bool mIsPellet;                      // _2E1, is lying down/carryable
	Kontroller* mKontroller;             // _2E4
	Camera* mNaviCamera;                 // _2E8, could be CullFrustum*, but probably Camera*
	Vector3f* mLookAtPosPtr;             // _2EC
	u8 _2F0;                             // _2F0
	f32 _2F4;                            // _2F4
	f32 _2F8;                            // _2F8
	Creature* _2FC;                      // _2FC
	f32 _300;                            // _300
	Creature* _304;                      // _304, maybe Pellet*?
	bool mIsInWater;                     // _308
	u32 _30C;                            // _30C, unknown
	u32 _310;                            // _310, unknown
	BurnEffect* mBurnEffect;             // _314
	RippleEffect* mRippleEffect;         // _318
	SlimeEffect* mSlimeEffect;           // _31C
	NaviStateMachine* mStateMachine;     // _320
	ShadowCaster mShadowCaster;          // _324
	NaviDrawer* mNaviDrawer;             // _6B8
	f32 mMotionSpeed;                    // _6BC
	int mIsDayEnd;                       // _6C0
	ShapeDynMaterials mNaviDynMats;      // _6C4
	Vector3f mCursorPosition;            // _6D4, where cursor (whistle) currently is
	f32 mCursorNaviDist;                 // _6E0, how far is the cursor from us?
	Vector3f mCursorTargetPosition;      // _6E4, where we want cursor to be
	Vector3f _6F0;                       // _6F0, also cursor related?
	int _6FC;                            // _6FC
	int _700;                            // _700
	f32 _704;                            // _704
	GoalItem* mGoalItem;                 // _708
	u8 _70C;                             // _70C
	CPlate* mPlateMgr;                   // _710, manages pikis in navi's party
	u8 _714[0x4];                        // _714, unknown
	u8 _718;                             // _718
	u8 _719;                             // _719
	u32 _71C;                            // _71C, unknown
	u32 _720;                            // _720, unknown
	u8 _724;                             // _724
	u8 _725[0x72C - 0x725];              // _725, TODO: work out members
	u32 _72C;                            // _72C, unknown
	u32 _730;                            // _730, unknown
	u32 _734;                            // _734, unknown
	f32 _738;                            // _738, sleep button held timer?
	u8 _73C[0x4];                        // _73C, TODO: work out members
	Vector3f _740;                       // _740
	Vector3f _74C;                       // _74C
	Vector3f _758;                       // _758
	Vector3f _764;                       // _764
	u32 _770;                            // _770, unknown
	PermanentEffect* mNaviLightEfx;      // _774
	PermanentEffect* mNaviLightGlowEfx;  // _778
	PermanentEffect* _77C;               // _77C
	PermanentEffect* _780;               // _780
	Vector3f _784;                       // _784
	Vector3f mDayEndPosition;            // _790
	Vector3f _79C;                       // _79C
	f32 mAiTickTimer;                    // _7A8
	Plane* mWallPlane;                   // _7AC
	DynCollObject* mWallCollObj;         // _7B0
	int _7B4;                            // _7B4
	int _7B8;                            // _7B8
	Piki* _7BC;                          // _7BC
	PikiHeadItem* _7C0;                  // _7C0
	Vector3f _7C4;                       // _7C4
	f32 _7D0;                            // _7D0
	u8 _7D4[0x7D8 - 0x7D4];              // _7D4, TODO: work out members
	SmartPtr<Creature> _7D8;             // _7D8
	f32 _7DC;                            // _7DC
	int mPreBlendLowerMotionID;          // _7E0
	bool mIsPlucking;                    // _7E4
	bool mIsFastPluckEnabled;            // _7E5
	u8 mNoPluckTimer;                    // _7E6, count after plucking stops to zoom out camera/stop fast pluck
	u8 _7E7[0x7F8 - 0x7E7];              // _7E7, TODO: work out members
	Piki* mNextThrowPiki;                // _7F8
	u8 _7FC;                             // _7FC
	f32 _800;                            // _800
	u8 _804[0x8];                        // _804, unknown
	int _80C;                            // _80C
	u32 _810;                            // _810, unknown
	f32 _814;                            // _814
	f32 _818;                            // _818
	Vector3f _81C;                       // _81C
	u32 _828;                            // _828, unknown
	PikiShapeObject* mNaviShapeObject;   // _82C
	u8 _830;                             // _830
	PaniPikiAnimMgr mNaviAnimMgr;        // _834
	SearchData mNaviSearchData[6];       // _8E0
	u32 _928;                            // _928, unknown
	int mNaviID;                         // _92C
	u8 _930[0x8];                        // _930, unknown
	Vector3f _938[32];                   // _938
	f32 _AB8;                            // _AB8
	u32 _ABC;                            // _ABC, unknown
	u8 _AC0[0x4];                        // _AC0, unknown
	f32 _AC4;                            // _AC4
	u8 _AC8[0x4];                        // _AC8, unknown
	u8 _ACC;                             // _ACC
	u32 _AD0;                            // _AD0, unknown
	u8 _AD4[0x4];                        // _AD4, unknown
	f32 _AD8;                            // _AD8
	AState<Navi>* mCurrState;            // _ADC
};

/**
 * @brief TODO
 */
struct NaviDrawer : public Node {
	NaviDrawer(Navi* navi)
	    : Node("")
	{
		mNavi = navi;
	}

	virtual void draw(Graphics& gfx) { mNavi->draw(gfx); } // _14 (weak)

	// _00     = VTBL
	// _00-_20 = Node
	Navi* mNavi; // _20
};

extern bool DelayPikiBirth;

#endif
