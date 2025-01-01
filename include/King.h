#ifndef _KING_H
#define _KING_H

#include "types.h"
#include "Boss.h"
#include "zen/Callback.h"
#include "zen/Particle.h"
#include "CreatureCollPart.h"
#include "MapMgr.h"

struct KingAi;
struct KingBody;
struct KingDrawer;
struct KingGenSalivaCallBack;
struct KingGenSpreadSalivaCallBack;
struct KingGenSalivaParticleCallBack;
struct KingGenDamageStarCallBack;
struct KingGenRippleCallBack;
struct KingGenSpitPartsParticleCallBack;

/**
 * @brief TODO.
 */
struct KingProp : public BossProp, public CoreNode {

	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to KingProp for ease of use.
	 */
	struct KingProperties : public Parameters {
		inline KingProperties()
		    : _204(this, 60.0f, 0.0f, 0.0f, "o00", nullptr)
		    , _214(this, 0.5f, 0.0f, 0.0f, "o01", nullptr)
		    , _224(this, 0.5f, 0.0f, 0.0f, "o02", nullptr)
		    , _234(this, 180.0f, 0.0f, 0.0f, "p00", nullptr)
		    , _244(this, 40.0f, 0.0f, 0.0f, "p01", nullptr)
		    , _254(this, 25.0f, 0.0f, 0.0f, "p04", nullptr)
		    , _264(this, 40.0f, 0.0f, 0.0f, "p02", nullptr)
		    , _274(this, 40.0f, 0.0f, 0.0f, "p03", nullptr)
		    , _284(this, 70.0f, 0.0f, 0.0f, "p10", nullptr)
		    , _294(this, 60.0f, 0.0f, 0.0f, "q10", nullptr)
		    , _2A4(this, 25.0f, 0.0f, 0.0f, "r00", nullptr)
		    , _2B4(this, 50.0f, 0.0f, 0.0f, "r01", nullptr)
		    , _2C4(this, 1.2f, 0.0f, 0.0f, "s00", nullptr)
		    , _2D4(this, 75.0f, 0.0f, 0.0f, "s10", nullptr)
		    , _2E4(this, 200.0f, 0.0f, 0.0f, "s20", nullptr)
		    , _2F4(this, 150.0f, 0.0f, 0.0f, "s21", nullptr)
		    , _304(this, 0.0f, 0.0f, 0.0f, "s23", nullptr)
		    , _314(this, 5.0f, 0.0f, 0.0f, "s30", nullptr)
		    , _324(this, 50.0f, 0.0f, 0.0f, "s31", nullptr)
		    , _334(this, 50.0f, 0.0f, 0.0f, "s32", nullptr)
		    , _344(this, 30.0f, 0.0f, 0.0f, "s40", nullptr)
		    , _354(this, 0.05f, 0.0f, 0.0f, "s41", nullptr)
		    , _364(this, 0.5f, 0.0f, 0.0f, "t00", nullptr)
		    , _374(this, 0.5f, 0.0f, 0.0f, "t01", nullptr)
		    , _384(this, 0.9f, 0.0f, 0.0f, "t02", nullptr)
		    , _394(this, 0.1f, 0.0f, 0.0f, "t03", nullptr)
		    , _3A4(this, 275.0f, 0.0f, 0.0f, "t10", nullptr)
		    , _3B4(this, 250.0f, 0.0f, 0.0f, "t11", nullptr)
		    , _3C4(this, 120.0f, 0.0f, 0.0f, "t12", nullptr)
		    , _3D4(this, 100, 0, 0, "i00", nullptr)
		    , _3E4(this, 0, 0, 0, "i10", nullptr)
		    , _3F4(this, 10, 0, 0, "i11", nullptr)
		    , _404(this, 4, 0, 0, "i12", nullptr)
		    , _414(this, 4, 0, 0, "i13", nullptr)
		    , _424(this, 6, 0, 0, "i14", nullptr)
		    , _434(this, 0, 0, 0, "i20", nullptr)
		    , _444(this, 10, 0, 0, "i21", nullptr)
		    , _454(this, 4, 0, 0, "i22", nullptr)
		    , _464(this, 4, 0, 0, "i23", nullptr)
		    , _474(this, 6, 0, 0, "i24", nullptr)
		    , _484(this, 2, 0, 0, "i30", nullptr)
		    , _494(this, 3, 0, 0, "i40", nullptr)
		{
		}

		// _200-_204 = Parameters
		Parm<f32> _204; // _204, o00
		Parm<f32> _214; // _214, o01
		Parm<f32> _224; // _224, o02
		Parm<f32> _234; // _234, p00
		Parm<f32> _244; // _244, p01
		Parm<f32> _254; // _254, p04
		Parm<f32> _264; // _264, p02
		Parm<f32> _274; // _274, p03
		Parm<f32> _284; // _284, p10
		Parm<f32> _294; // _294, q10
		Parm<f32> _2A4; // _2A4, r00
		Parm<f32> _2B4; // _2B4, r01
		Parm<f32> _2C4; // _2C4, s00
		Parm<f32> _2D4; // _2D4, s10
		Parm<f32> _2E4; // _2E4, s20
		Parm<f32> _2F4; // _2F4, s21
		Parm<f32> _304; // _304, s23
		Parm<f32> _314; // _314, s30
		Parm<f32> _324; // _324, s31
		Parm<f32> _334; // _334, s32
		Parm<f32> _344; // _344, s40
		Parm<f32> _354; // _354, s41
		Parm<f32> _364; // _364, t00
		Parm<f32> _374; // _374, t01
		Parm<f32> _384; // _384, t02
		Parm<f32> _394; // _394, t03
		Parm<f32> _3A4; // _3A4, t10
		Parm<f32> _3B4; // _3B4, t11
		Parm<f32> _3C4; // _3C4, t12
		Parm<int> _3D4; // _3D4, i00
		Parm<int> _3E4; // _3E4, i10
		Parm<int> _3F4; // _3F4, i11
		Parm<int> _404; // _404, i12
		Parm<int> _414; // _414, i13
		Parm<int> _424; // _424, i14
		Parm<int> _434; // _434, i20
		Parm<int> _444; // _444, i21
		Parm<int> _454; // _454, i22
		Parm<int> _464; // _464, i23
		Parm<int> _474; // _474, i24
		Parm<int> _484; // _484, i30
		Parm<int> _494; // _494, i40
	};

	KingProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.Parameters::read(input);
		mBossProps.Parameters::read(input);
		mKingProps.Parameters::read(input);
	};

	// _54       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	KingProperties mKingProps; // _200
};

/**
 * @brief TODO.
 */
struct KingBackProp : public BossProp, public CoreNode {
	KingBackProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.read(input);
		mBossProps.read(input);
		_200.read(input);
	}

	// _F8       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	Parameters _200; // _200
};

/**
 * @brief TODO.
 *
 * @note Size: 0x7A4.
 */
struct King : public Boss {
	King(CreatureProp*);

	virtual void init(Vector3f&);                    // _28
	virtual f32 getiMass();                          // _38
	virtual void update();                           // _E0
	virtual void refresh(Graphics&);                 // _EC
	virtual void doAI();                             // _104
	virtual void doAnimation();                      // _108
	virtual void doKill();                           // _10C
	virtual void exitCourse();                       // _110
	virtual bool isBossBgm() { return mIsBossBgm; }; // _114
	virtual void bombDamageCounter(CollPart*);       // _11C
	virtual void drawShape(Graphics&);               // _120

	void draw(Graphics&);

	inline KingProp* getKingProp() { return static_cast<KingProp*>(mProps); }

	// _00      = VTBL
	// _00-_3B8 = Boss
	bool mIsBossBgm;            // _3B8
	KingAi* mKingAi;            // _3BC
	KingBody* mKingBody;        // _3C0
	CreaturePlatMgr mPlatMgr;   // _3C4
	ShadowCaster mShadowCaster; // _40C
	KingDrawer* mKingDrawer;    // _7A0
};

/**
 * @brief TODO.
 *
 * @note Size: 0x400.
 */
struct KingBack : public Boss {
	KingBack(CreatureProp*);

	virtual void init(Vector3f&);      // _28
	virtual f32 getiMass();            // _38
	virtual void update();             // _E0
	virtual void refresh(Graphics&);   // _EC
	virtual void doAI();               // _104
	virtual void doAnimation();        // _108
	virtual void doKill();             // _10C
	virtual void exitCourse();         // _110
	virtual void drawShape(Graphics&); // _120

	// _00      = VTBL
	// _00-_3B8 = Boss
	CreaturePlatMgr mPlatMgr; // _3B8
};

/**
 * @brief TODO.
 *
 * @note Size: 0x110.
 */
struct KingBody {
	KingBody(King*);

	void init(King*);
	void initBlending(f32);
	void setSeedFlashEffect();
	void setEatBombEffect();
	void createWaterEffect(int);
	void createUfoParts();
	void killCallBackEffect(bool);
	void setVelocityFromPosition();
	void emitOnGroundEffect();
	void update();
	void makeBlending(Matrix4f*);
	void copyJointPosition(Matrix4f*);
	void refresh(BossShapeObject*, Graphics&);

	// unused/inlined:
	void setSalivaEffect();
	void updateBlendingRatio();
	void checkOnGround();
	void emitSlipEffect();
	void copyOnGround();
	void makeAnimation(BossShapeObject*, Graphics&, Matrix4f*);
	void checkBlendingParm(Matrix4f*);
	void returnJoint(BossShapeObject*, Graphics&, Matrix4f*);

	King* mKing;                                                  // _00
	u8 _04;                                                       // _04
	u8 _05;                                                       // _05
	u8 _06;                                                       // _06
	u8 _07[2];                                                    // _07
	u8 _09[2];                                                    // _09
	bool _0B[2];                                                  // _0B
	int _10[2];                                                   // _10
	f32 _18;                                                      // _18
	f32 _1C;                                                      // _1C
	f32 _20;                                                      // _20
	Vector3f _24[2];                                              // _24
	Vector3f _3C[2];                                              // _3C
	Vector3f _54;                                                 // _54
	Vector3f _60;                                                 // _60
	Vector3f _6C;                                                 // _6C
	Vector3f _78[2];                                              // _78
	Vector3f _90[2];                                              // _90
	Vector3f _A8[4];                                              // _A8
	Vector3f _D8;                                                 // _D8
	Vector3f _E4;                                                 // _E4
	Matrix4f* _F0;                                                // _F0
	Matrix4f* _F4;                                                // _F4
	KingGenSalivaCallBack* mSalivaCallBacks;                      // _F8
	KingGenSpreadSalivaCallBack* mSpreadSalivaCallBack;           // _FC
	KingGenSalivaParticleCallBack* mSalivaParticleCallBack;       // _100
	KingGenDamageStarCallBack* mDamageStarCallBack;               // _104
	KingGenRippleCallBack* mRippleCallBacks;                      // _108
	KingGenSpitPartsParticleCallBack* mSpitPartsParticleCallBack; // _10C
};

/**
 * @brief TODO.
 *
 * @note Size: 0x24.
 */
struct KingDrawer : public Node {
	inline KingDrawer(King* king)
	    : Node("")
	{
		mKing = king;
	}

	virtual void draw(Graphics&); // _14

	// _00     = VTBL
	// _00-_20 = Node
	King* mKing; // _20
};

/**
 * @brief TODO.
 *
 * @note Size: 0x50.
 */
struct KingAi : public PaniAnimKeyListener {
	KingAi(King*);

	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

	void initAI(King*);
	void keyAction0();
	void keyAction1();
	void keyAction2();
	void keyLoopEnd();
	void keyFinished();
	void playSound(int);
	void createEffect(int);
	void calcDamageScale();
	void startSpreadSaliva();
	void endSpreadSaliva();
	void fallBackSide();
	void pikiStickToKingMouth();
	void tongueBombExplosion();
	void killStickToMouthPiki();
	void tongueAttackNavi();
	void dispelNaviPiki();
	void setDamageLoopCounter(int, int, int, int, int, int);
	void setEatDamageLoopCounter();
	void setAttackPriority();
	void inJumpAngle(Creature*);
	void inTurnAngleTransit();
	void chaseNaviTransit();
	void chasePikiTransit();
	void attackTransit();
	void jumpAttackTransit();
	void eatThrowPikiTransit();
	void targetLostTransit();
	void appearTransit();
	void initDie(int);
	void initAppear(int);
	void update();

	// unused/inlined:
	void keyAction3();
	void setAttackPosition();
	void startFallSaliva();
	void endFallSaliva();
	void setMouthCollPart(int);
	void getMouthCollPart(int);
	void setDispelParm(Creature*, f32);
	void setBombDamageLoopCounter();
	void setMoveVelocity(f32);
	void resetAttackPriority();
	void resultFlagOn();
	void resultFlagSeen();
	void attackInArea(Creature*, Vector3f*);
	void jumpAttackInArea(Creature*, Vector3f*);
	void dieTransit();
	void damageTransit();
	void bombDownTransit();
	void isMotionFinishTransit();
	void outSideChaseRangeTransit();
	void inSideWaitRangeTransit();
	void missAttackNextTransit();
	void swallowTransit();
	void flickTransit();
	void initDamage(int);
	void initBombDown(int);
	void initWalkRandom(int, bool);
	void initWalkGoHome(int, bool);
	void initChaseNavi(int, bool);
	void initChasePiki(int, bool);
	void initHomeTurn(int);
	void initChaseTurn(int);
	void initAttack(int);
	void initJumpAttack(int);
	void initSwallow(int);
	void initEatThrowPiki(int);
	void initFlick(int);
	void initWaveNeck(int);
	void initStay(int);
	void dieState();
	void damageState();
	void bombDownState();
	void walkRandomState();
	void walkGoHomeState();
	void homeTurnState();
	void chaseTurnState();
	void chaseNaviState();
	void chasePikiState();
	void attackState();
	void jumpAttackState();
	void swallowState();
	void eatThrowPikiState();
	void flickState();
	void waitState();
	void waveNeckState();
	void appearState();
	void stayState();
	void setEveryFrame();
	void afterProcessing();

	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	King* mKing;            // _04
	u8 _08;                 // _08, might be bool
	u8 _09;                 // _09, might be bool
	u32 _0C;                // _0C, unknown
	u32 _10;                // _10, might be int
	u8 _14[0x4];            // _14, unknown
	u32 _18;                // _18, unknown
	int mBombDamageCounter; // _1C
	int _20;                // _20
	f32 _24;                // _24
	f32 _28;                // _28
	Vector3f _2C;           // _2C
	Vector3f _38;           // _38
	Vector3f _44;           // _44
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct KingGenDamageStarCallBack : public zen::CallBack1<zen::particleGenerator*> {
	virtual bool invoke(zen::particleGenerator*); // _08

	void set(King* king) { mKing = king; }

	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	King* mKing; // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct KingGenRippleCallBack : public zen::CallBack1<zen::particleGenerator*> {
	virtual bool invoke(zen::particleGenerator*); // _08

	void set(King* king, Vector3f* p2, bool* p3)
	{
		mKing = king;
		_0C   = p2;
		_04   = p3;
	}

	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	bool* _04;     // _04
	King* mKing;   // _08
	Vector3f* _0C; // _0C
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct KingGenSalivaCallBack : public zen::CallBack1<zen::particleGenerator*> {
	virtual bool invoke(zen::particleGenerator* ptcl) // _08
	{
		Vector3f midPt = *_04 + *_08;
		midPt.multiply(0.5f);

		Vector3f dir = *_04 - *_08;
		dir.normalise();

		ptcl->setEmitPos(midPt);
		ptcl->setEmitDir(dir);

		if (mKing->mKingBody->_05) {
			ptcl->startGen();
		} else {
			ptcl->stopGen();
		}

		if (!mKing->getAlive()) {
			ptcl->finish();
		}

		return true;
	}

	void set(Vector3f* p1, Vector3f* p2, King* king)
	{
		_04   = p1;
		_08   = p2;
		mKing = king;
	}

	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	Vector3f* _04; // _04
	Vector3f* _08; // _08
	King* mKing;   // _0C
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct KingGenSalivaParticleCallBack : public zen::CallBack2<zen::particleGenerator*, zen::particleMdl*> {
	virtual bool invoke(zen::particleGenerator*, zen::particleMdl*); // _08

	void set(King* king) { mKing = king; }

	// _00     = VTBL
	// _00-_04 = zen::CallBack2
	King* mKing; // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct KingGenSpitPartsParticleCallBack : public zen::CallBack2<zen::particleGenerator*, zen::particleMdl*> {
	virtual bool invoke(zen::particleGenerator*, zen::particleMdl*); // _08

	// _00     = VTBL
	// _00-_04 = zen::CallBack2
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct KingGenSpreadSalivaCallBack : public zen::CallBack1<zen::particleGenerator*> {
	virtual bool invoke(zen::particleGenerator* ptcl) // _08
	{
		ptcl->setEmitDir(mKing->mKingBody->_60);
		if (mKing->mKingBody->_06) {
			ptcl->startGen();
		} else {
			ptcl->stopGen();
		}

		if (!mKing->getAlive()) {
			ptcl->finish();
		}

		return true;
	}

	void set(King* king) { mKing = king; }

	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	King* mKing; // _04
};

#endif
