#ifndef _SNAKE_H
#define _SNAKE_H

#include "types.h"
#include "Boss.h"
#include "Collision.h"
#include "zen/Callback.h"
#include "zen/Particle.h"

struct Snake;
struct SnakeAi;
struct SnakeBody;
struct SnakeGenBodyOnGroundCallBack;
struct SnakeGenBodyRotateCallBack;

#define SNAKE_PROP          (static_cast<SnakeProp*>(mProps)->mSnakeProps)
#define C_SNAKE_PROP(snake) (static_cast<SnakeProp*>((snake)->mProps)->mSnakeProps)

/**
 * @brief TODO.
 *
 * @note Size: 0x504
 */
struct SnakeProp : public BossProp, public CoreNode {

	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to SnakeProp for ease of use.
	 */
	struct SnakeProperties : public Parameters {
		inline SnakeProperties()
		    : _204(this, 150.0f, 0.0f, 500.0f, "p00", "")
		    , _214(this, 100.0f, 0.0f, 300.0f, "p01", "")
		    , _224(this, 200.0f, 0.0f, 500.0f, "u00", "2:Front Length")
		    , _234(this, 100.0f, 0.0f, 500.0f, "u01", "2:Side Length")
		    , _244(this, 50.0f, 0.0f, 300.0f, "u02", "2:Vertical Length")
		    , _254(this, 25.0f, 0.0f, 100.0f, "p10", "Attack Damage Navi")
		    , _264(this, 5.0f, 0.0f, 500.0f, "p20", "Near Attack Dist")
		    , _274(this, 80.0f, 0.0f, 500.0f, "p21", "Near Attack Limit")
		    , _284(this, -15.0f, -500.0f, 500.0f, "p22", "Near Attack Minus")
		    , _294(this, 15.0f, -500.0f, 500.0f, "p23", "Near Attack Plus")
		    , _2A4(this, 15.0f, 0.0f, 100.0f, "p24", "Near Attack Height")
		    , _2B4(this, 80.0f, 0.0f, 500.0f, "p30", "Mid Attack Dist")
		    , _2C4(this, 150.0f, 0.0f, 500.0f, "p31", "Mid Attack Limit")
		    , _2D4(this, -20.0f, -500.0f, 500.0f, "p32", "Mid Attack Minus")
		    , _2E4(this, 20.0f, -500.0f, 500.0f, "p33", "Mid Attack Plus")
		    , _2F4(this, 15.0f, 0.0f, 100.0f, "p34", "Mid Attack Height")
		    , _304(this, 150.0f, 0.0f, 500.0f, "p40", "Far Attack Dist")
		    , _314(this, 220.0f, 0.0f, 500.0f, "p41", "Far Attack Limit")
		    , _324(this, -25.0f, -500.0f, 500.0f, "p42", "Far Attack Minus")
		    , _334(this, 25.0f, -500.0f, 500.0f, "p43", "Far Attack Plus")
		    , _344(this, 15.0f, 0.0f, 100.0f, "p44", "Far Attack Height")
		    , _354(this, 70.0f, 0.0f, 500.0f, "p50", "Right Attack Dist")
		    , _364(this, 120.0f, 0.0f, 500.0f, "p51", "Right Attack Limit")
		    , _374(this, 30.0f, -500.0f, 500.0f, "p52", "Right Attack Minus")
		    , _384(this, 100.0f, -500.0f, 500.0f, "p53", "Right Attack Plus")
		    , _394(this, 15.0f, 0.0f, 100.0f, "p54", "Right Attack Height")
		    , _3A4(this, 70.0f, 0.0f, 500.0f, "p60", "Left Attack Dist")
		    , _3B4(this, 120.0f, 0.0f, 500.0f, "p61", "Left Attack Limit")
		    , _3C4(this, -100.0f, -500.0f, 500.0f, "p62", "Left Attack Minus")
		    , _3D4(this, -30.0f, -500.0f, 500.0f, "p63", "Left Attack Plus")
		    , _3E4(this, 15.0f, 0.0f, 100.0f, "p64", "Left Attack Height")
		    , _3F4(this, 1.5f, 0.0f, 5.0f, "t00", "Norm Body Turn")
		    , _404(this, 4.0f, 0.0f, 5.0f, "t01", "Chase Body Turn")
		    , _414(this, 1.0f, 0.0f, 30.0f, "t10", "Chase Blend Ratio")
		    , _424(this, 2.5f, 0.0f, 10.0f, "q00", "Dive Time")
		    , _434(this, 0.0f, 0.0f, 10.0f, "q02", "Under Time")
		    , _444(this, 10.0f, 0.0f, 100.0f, "s00", "Head Scale Speed")
		    , _454(this, 1.0f, 0.0f, 10.0f, "s01", "Head Scale Timer")
		    , _464(this, 5.0f, 0.0f, 100.0f, "s02", "Body Scale Speed")
		    , _474(this, 0.75f, 0.0f, 10.0f, "s03", "Body Scale Timer")
		    , _484(this, 0.1f, 0.0f, 1.0f, "s04", "Body Timer Up Ratio")
		    , _494(this, 0.7f, 0.0f, 1.0f, "s10", "Normal Appear Type")
		    , _4A4(this, 5, 0, 100, "i10", "Struggle Piki(Min)")
		    , _4B4(this, 20, 0, 100, "i11", "Struggle Piki(Max)")
		    , _4C4(this, 1, 0, 10, "i12", "Struggle Loop(Mid)")
		    , _4D4(this, 3, 0, 10, "i13", "Struggle Loop(Max)")
		    , _4E4(this, 1, -1, 3, "i30", "Head Pellet Index")
		    , _4F4(this, 0, -1, 3, "i31", "Body Pellet Index")
		{
		}

		// _200-_204 = Parameters
		Parm<f32> _204; // _204
		Parm<f32> _214; // _214
		Parm<f32> _224; // _224
		Parm<f32> _234; // _234
		Parm<f32> _244; // _244
		Parm<f32> _254; // _254
		Parm<f32> _264; // _264
		Parm<f32> _274; // _274
		Parm<f32> _284; // _284
		Parm<f32> _294; // _294
		Parm<f32> _2A4; // _2A4
		Parm<f32> _2B4; // _2B4
		Parm<f32> _2C4; // _2C4
		Parm<f32> _2D4; // _2D4
		Parm<f32> _2E4; // _2E4
		Parm<f32> _2F4; // _2F4
		Parm<f32> _304; // _304
		Parm<f32> _314; // _314
		Parm<f32> _324; // _324
		Parm<f32> _334; // _334
		Parm<f32> _344; // _344
		Parm<f32> _354; // _354
		Parm<f32> _364; // _364
		Parm<f32> _374; // _374
		Parm<f32> _384; // _384
		Parm<f32> _394; // _394
		Parm<f32> _3A4; // _3A4
		Parm<f32> _3B4; // _3B4
		Parm<f32> _3C4; // _3C4
		Parm<f32> _3D4; // _3D4
		Parm<f32> _3E4; // _3E4
		Parm<f32> _3F4; // _3F4
		Parm<f32> _404; // _404
		Parm<f32> _414; // _414
		Parm<f32> _424; // _424
		Parm<f32> _434; // _434
		Parm<f32> _444; // _444
		Parm<f32> _454; // _454
		Parm<f32> _464; // _464
		Parm<f32> _474; // _474
		Parm<f32> _484; // _484
		Parm<f32> _494; // _494
		Parm<int> _4A4; // _4A4
		Parm<int> _4B4; // _4B4
		Parm<int> _4C4; // _4C4
		Parm<int> _4D4; // _4D4
		Parm<int> _4E4; // _4E4
		Parm<int> _4F4; // _4F4
	};

	SnakeProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.Parameters::read(input);
		mBossProps.Parameters::read(input);
		mSnakeProps.Parameters::read(input);
	};

	// _54       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	SnakeProperties mSnakeProps; // _200
};

/**
 * @brief TODO
 *
 * @note Size: 0x890.
 */
struct SnakeBody {
	SnakeBody(Snake*);

	void setBodyOnGroundEffect();
	void killCallBackEffect(bool);
	void init(Vector3f&, Snake*);
	void initBlending(f32);
	void makeTurnVelocity();
	void makeResultPosition();
	void makeVectorMatrix();
	void createDeadHeadEffect();
	void createDeadBodyEffect();
	void makeDeadPattern01();
	void update();
	void makeBodySize();
	void makeHeadPosition();
	void makeBodyMatrix();
	void makeAnimMatrix();
	void caseOfMatrix(Matrix4f*);
	void makeBlending(Matrix4f*);
	void setDeadPattern01(Matrix4f*);
	void returnJoint(BossShapeObject*, Graphics&, Matrix4f*);
	void refresh(BossShapeObject*, Graphics&);

	// unused/inlined:
	void updateBlendingRatio();
	void setInitializePosition();
	void copyAnimPosition();
	void makeHeadDirection();
	void makeNewPosition();
	void createDeadPellet(Vector3f&, int);
	void makeDeadPattern02();
	void makeDeadScaleParms();
	void makeAnimation(BossShapeObject*, Graphics&);
	void checkBlendingParm(Matrix4f*);
	void setDeadPattern02(Matrix4f*);
	void setDeadScale(Matrix4f*);

	Snake* mSnake;                                   // _00
	bool _04;                                        // _04
	u8 _05;                                          // _05
	int _08;                                         // _08
	f32 mBlendingRatio;                              // _0C
	f32 mBlendingRate;                               // _10
	f32 _14[7];                                      // _14
	f32 _30[8];                                      // _30
	Vector3f _50;                                    // _50
	Vector3f _5C[8];                                 // _5C
	Vector3f _BC[6];                                 // _BC
	Vector3f _104[8][4];                             // _104
	Matrix4f _284[8];                                // _284
	Matrix4f _484[8];                                // _484
	Matrix4f _684[8];                                // _684
	SnakeGenBodyOnGroundCallBack* mOnGroundCallBack; // _884
	SnakeGenBodyRotateCallBack* mRotateCallBack;     // _888
	zen::particleGenerator** mHeadPtclGens;          // _88C
};

/**
 * @brief TODO.
 *
 * @note Size: 0x3DC.
 */
struct Snake : public Boss {

	/**
	 * @brief TODO.
	 */
	struct BoundSphereUpdater : public CollPartUpdater {
		inline BoundSphereUpdater(Snake* snake) { mSnake = snake; }

		virtual Vector3f getPos() // _08
		{
			mCentrePosition.x = (mSnake->mSnakeBody->_50.x + mSnake->mPosition.x) / 2.0f;
			mCentrePosition.y = (mSnake->mSnakeBody->_50.y + mSnake->mPosition.y) / 2.0f;
			mCentrePosition.z = (mSnake->mSnakeBody->_50.z + mSnake->mPosition.z) / 2.0f;

			return mCentrePosition;
		}
		virtual f32 getSize() // _0C
		{
			mSize = mSnake->mSnakeBody->_50.distance(mCentrePosition);
			mSize += 55.0f;
			return mSize;
		}

		// _00     = VTBL
		// _00-_1C = CollPartUpdater
		Snake* mSnake;            // _1C
		f32 mSize;                // _20
		Vector3f mCentrePosition; // _24
	};

	Snake(CreatureProp*);

	virtual void init(Vector3f&);      // _28
	virtual f32 getiMass();            // _38
	virtual f32 getCentreSize();       // _5C
	virtual void update();             // _E0
	virtual void refresh(Graphics&);   // _EC
	virtual void refresh2d(Graphics&); // _F0
	virtual void doAI();               // _104
	virtual void doAnimation();        // _108
	virtual void doKill();             // _10C
	virtual void exitCourse();         // _110
	virtual void drawShape(Graphics&); // _120

	void setBossType(bool);

	inline SnakeProp* getSnakeProp() { return static_cast<SnakeProp*>(mProps); }

	// _00      = VTBL
	// _00-_3B8 = Boss
	BoundSphereUpdater* mBoundsUpdater; // _3B8
	bool mBossType;                     // _3BC
	f32 _3C0;                           // _3C0
	f32 _3C4;                           // _3C4
	SnakeAi* mSnakeAi;                  // _3C8
	SnakeBody* mSnakeBody;              // _3CC
	Vector3f _3D0;                      // _3D0
};

/**
 * @brief TODO.
 *
 * @note Size: 0x50.
 */
struct SnakeAi : public PaniAnimKeyListener {
	SnakeAi(Snake*);

	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

	void initAI(Snake*);
	void keyAction0();
	void keyAction1();
	void keyLoopEnd();
	void keyFinished();
	void playSound(int);
	void traceTargetPosition();
	void setAttackPosition();
	void checkAttackTarget();
	void naviNudge();
	void pikiStickMouth();
	void eatStickToMouthPiki();
	void nearNaviInAttackArea(Creature**, f32*, int);
	void nearPikiInAttackArea(Creature**, f32*, int);
	void naviInAttackArea(int);
	void pikiInAttackArea(int);
	void appearType01();
	void appearType02();
	void chaseNaviTransit();
	void chasePikiTransit();
	void targetLostTransit();
	void attackTransit(int);
	void collPartMaxTransit();
	void initAttack(int, f32);
	void initAppear(int);
	void struggleState();
	void update();

	// unused/inlined:
	void keyAction2();
	void keyAction3();
	void setEveryFrame();
	void setInitPosition();
	void setUnderPosition();
	void setAppearPosition01();
	void setAppearPosition02();
	void setMouthCollPart(int);
	void getMouthCollPart(int);
	void resultFlagOn();
	void resultFlagSeen();
	void dieTransit();
	void struggleTransit();
	void eatPikiTransit();
	void intoGroundTransit();
	void diveTimerTransit();
	void underTimerTransit();
	void appearTransit();
	void initDie(int);
	void initStruggle(int);
	void initChase(int);
	void initEat(int);
	void initWait(int);
	void initGointo(int);
	void initUnder(int);
	void dieState();
	void chaseState();
	void attackState();
	void eatState();
	void waitState();
	void gointoState();
	void underState();

	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	u8 _04;             // _04
	u8 _05[0x50 - 0x5]; // _05, unknown
};

/**
 * @brief TODO
 */
struct SnakeGenBodyOnGroundCallBack : public zen::CallBack1<zen::particleGenerator*> {
	virtual bool invoke(zen::particleGenerator* ptclGen) // _08
	{
		if (!mSnake->getAlive() || mSnake->getNextState() == 8) {
			ptclGen->finish();
		}

		return true;
	}

	void set(Snake* snake) { mSnake = snake; }

	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	Snake* mSnake; // _04
};

/**
 * @brief TODO
 */
struct SnakeGenBodyRotateCallBack : public zen::CallBack1<zen::particleGenerator*> {
	virtual bool invoke(zen::particleGenerator* ptclGen) // _08
	{
		if (mSnake->mSnakeAi->_04) {
			ptclGen->startGen();
		} else {
			ptclGen->stopGen();
		}

		if (!mSnake->getAlive() || mSnake->getNextState() == 8) {
			ptclGen->finish();
		}

		return true;
	}

	void set(Snake* snake) { mSnake = snake; }

	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	Snake* mSnake; // _04
};

#endif
