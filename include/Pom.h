#ifndef _POM_H
#define _POM_H

#include "Boss.h"
#include "Shape.h"
#include "types.h"
#include "zen/CallBack.h"
#include "zen/particle.h"

struct PomAi;
struct PomGenOpenStarCallBack;
struct ShapeDynMaterials;

#define POM_PROP        (static_cast<PomProp*>(mProps)->mPomProps)
#define C_POM_PROP(pom) (static_cast<PomProp*>((pom)->mProps)->mPomProps)

/**
 * @brief TODO.
 */
struct PomProp : public BossProp, public CoreNode {

	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to PomProp for ease of use.
	 */
	struct PomProperties : public Parameters {
		inline PomProperties() // TODO
		    : mSquashAmount(this, 0.2f, 0.0f, 0.0f, "s00", nullptr)
		    , mSquashPersistence(this, 0.5f, 0.0f, 0.0f, "s01", nullptr)
		    , mSquashMultiplier(this, 0.15f, 0.0f, 0.0f, "s02", nullptr)
		    , mCloseWaitTime(this, 10.0f, 0.0f, 0.0f, "p00", nullptr)
		    , mDischargeAngle(this, 180.0f, 0.0f, 0.0f, "p10", nullptr)
		    , mMaxPikiPerCycle(this, 10, 0, 0, "i00", nullptr)
		    , mMinCycles(this, 10, 0, 0, "i10", nullptr)
		    , mMaxCycles(this, 10, 0, 0, "i11", nullptr)
		    , mDoAnimLoopWhenClosed(this, FALSE, FALSE, TRUE, "i20", nullptr)
		    , mDoKillSameColorPiki(this, FALSE, FALSE, TRUE, "i90", nullptr)
		    , mStickOrSwallow(this, 1, 0, 1, "i91", nullptr)
		    , mOpenOnInteractionOnly(this, 0, 0, 1, "i92", nullptr)
		{
		}

		// _200-_204 = Parameters
		Parm<f32> mSquashAmount;          // _204, s00
		Parm<f32> mSquashPersistence;     // _214, s01
		Parm<f32> mSquashMultiplier;      // _224, s02
		Parm<f32> mCloseWaitTime;         // _234, p00
		Parm<f32> mDischargeAngle;        // _244, p10
		Parm<int> mMaxPikiPerCycle;       // _254, i00
		Parm<int> mMinCycles;             // _264, i10
		Parm<int> mMaxCycles;             // _274, i11
		Parm<int> mDoAnimLoopWhenClosed;  // _284, i20
		Parm<BOOL> mDoKillSameColorPiki;  // _294, i90
		Parm<int> mStickOrSwallow;        // _2A4, i91 - 0=stick and attack, 1=swallowed
		Parm<int> mOpenOnInteractionOnly; // _2B4, i92 - 0=open immediately, 1=open after interacting
	};

	PomProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.Parameters::read(input);
		mBossProps.Parameters::read(input);
		mPomProps.Parameters::read(input);
	};

	// _54       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	PomProperties mPomProps; // _200
};

/**
 * @brief TODO.
 *
 * @note Size: 0x3D4.
 */
struct Pom : public Boss {
	Pom(CreatureProp*);

	virtual void init(Vector3f&);               // _28
	virtual f32 getiMass();                     // _38
	virtual void collisionCallback(CollEvent&); // _A8
	virtual void update();                      // _E0
	virtual void refresh(Graphics&);            // _EC
	virtual void doAI();                        // _104
	virtual void doAnimation();                 // _108
	virtual void doKill();                      // _10C
	virtual void exitCourse();                  // _110
	virtual void drawShape(Graphics&);          // _120

	void setColor(int);

	inline PomProp* getPomProp() { return static_cast<PomProp*>(mProps); }

	// _00      = VTBL
	// _00-_3B8 = Boss
	bool mIsPikiOrPlayerTouching;   // _3B8
	int mColor;                     // _3BC
	PomAi* mPomAi;                  // _3C0
	ShapeDynMaterials mDynMaterial; // _3C4
};

/**
 * @brief TODO.
 *
 * @note Size: 0x24.
 */
struct PomAi : public PaniAnimKeyListener {
	PomAi(Pom*);

	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

	void initAI(Pom*);
	void keyAction0();
	void keyAction1();
	void keyLoopEnd();
	void keyFinished();
	void playSound(int);
	void killCallBackEffect(bool);
	void collidePetal(Creature*);
	void setCollideSound(Creature*);
	int killStickPiki();
	void createPikiHead();
	void calcPetalStickers();
	void initWait(int);
	void initDischarge(int);
	void update();

	// unused/inlined:
	void keyAction2();
	void keyAction3();
	void setEveryFrame();
	void resultFlagOn();
	bool isMotionFinishTransit();
	void initDie(int);
	void dieState();
	void checkSwayAndScale();
	void calcSwayAndScale();
	void setInitPosition();
	void emitPomOpenEffect(u32);
	void createPomOpenEffect();
	void resultFlagSeen();
	bool deadTransit();
	bool petalOpenTransit();
	bool petalShakeTransit();
	bool petalCloseTransit();
	bool dischargeTransit();
	void initPetalOpen(int);
	void initPetalShake(int);
	void initPetalClose(int);
	void waitState();
	void openState();
	void shakeState();
	void closeState();
	void dischargeState();

	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	Pom* mPom;                                 // _04
	bool mHasCollided;                         // _08
	u8 mPlaySound;                             // _09
	bool mIsOpening;                           // _0A
	int mPrevStickPikiCount;                   // _0C
	int mReleasedSeedCount;                    // _10
	int mMaxSeedCount;                         // _14
	f32 mDeformAmount;                         // _18
	f32 mCurrentDeform;                        // _1C
	PomGenOpenStarCallBack* mOpenStarCallBack; // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct PomGenOpenStarCallBack : public zen::CallBack1<zen::particleGenerator*> {
	PomGenOpenStarCallBack() { }

	virtual bool invoke(zen::particleGenerator* ptcl) // _08
	{
		if (!*mIsActive) {
			ptcl->finish();
		}

		return true;
	}

	void set(bool* val) { mIsActive = val; }

	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	bool* mIsActive; // _04, points to _0A in PomAi
};

#endif
