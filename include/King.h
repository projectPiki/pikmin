#ifndef _KING_H
#define _KING_H

#include "Boss.h"
#include "CreatureCollPart.h"
#include "EffectMgr.h"
#include "GlobalGameOptions.h"
#include "MapMgr.h"
#include "types.h"
#include "zen/CallBack.h"
#include "zen/particle.h"

#define KING_PROP         (static_cast<KingProp*>(mProps)->mKingProps)
#define C_KING_PROP(king) (static_cast<KingProp*>((king)->mProps)->mKingProps)

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
enum KingAIStateID {
	KINGAI_Die          = 0,
	KINGAI_Damage       = 1,
	KINGAI_BombDown     = 2,
	KINGAI_HomeTurn     = 3,
	KINGAI_ChaseTurn    = 4,
	KINGAI_Attack       = 5,
	KINGAI_JumpAttack   = 6,
	KINGAI_Swallow      = 7,
	KINGAI_EatThrowPiki = 8,
	KINGAI_WalkRandom   = 9,
	KINGAI_ChaseNavi    = 10,
	KINGAI_ChasePiki    = 11,
	KINGAI_WalkGoHome   = 12,
	KINGAI_Flick        = 13,
	KINGAI_WaveNeck     = 14,
	KINGAI_Appear       = 15,
	KINGAI_Stay         = 16,
};

/**
 * @brief TODO.
 */
enum KingAttackType {
	KINGATK_Jump   = 0,
	KINGATK_Tongue = 1,
};

/**
 * @brief TODO.
 */
struct KingProp : public BossProp, public CoreNode {
public:
	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to KingProp for ease of use.
	 */
	struct KingProperties : public Parameters {
		inline KingProperties()
		    : mKingWalkSpeed(this, 60.0f, 0.0f, 0.0f, "o00", nullptr)
		    , mWalkingTurnSpeed(this, 0.5f, 0.0f, 0.0f, "o01", nullptr)
		    , mTurningTurnSpeed(this, 0.5f, 0.0f, 0.0f, "o02", nullptr)
		    , mAttackDistance(this, 180.0f, 0.0f, 0.0f, "p00", nullptr)
		    , mNormalAttackRangeXZ(this, 40.0f, 0.0f, 0.0f, "p01", nullptr)
		    , mNormalAttackRangeY(this, 25.0f, 0.0f, 0.0f, "p04", nullptr)
		    , mTongueRangeXZ(this, 40.0f, 0.0f, 0.0f, "p02", nullptr)
		    , mTongueRangeY(this, 40.0f, 0.0f, 0.0f, "p03", nullptr)
		    , mPressAttackRadius(this, 70.0f, 0.0f, 0.0f, "p10", nullptr)
		    , mHiddenUnderneathRadius(this, 60.0f, 0.0f, 0.0f, "q10", nullptr)
		    , mTongueDamageNavi(this, 25.0f, 0.0f, 0.0f, "r00", nullptr)
		    , mPressDamageNavi(this, 50.0f, 0.0f, 0.0f, "r01", nullptr)
		    , mNormalKingScale(this, 1.2f, 0.0f, 0.0f, "s00", nullptr)
		    , mDetectionRadius(this, 75.0f, 0.0f, 0.0f, "s10", nullptr)
		    , mDispelRadius(this, 200.0f, 0.0f, 0.0f, "s20", nullptr)
		    , mDispelPower(this, 150.0f, 0.0f, 0.0f, "s21", nullptr)
		    , mDispelDamage(this, 0.0f, 0.0f, 0.0f, "s23", nullptr)
		    , _314(this, 5.0f, 0.0f, 0.0f, "s30", nullptr)
		    , _324(this, 50.0f, 0.0f, 0.0f, "s31", nullptr)
		    , _334(this, 50.0f, 0.0f, 0.0f, "s32", nullptr)
		    , mDamageScaleOscillationSpeed(this, 30.0f, 0.0f, 0.0f, "s40", nullptr)
		    , mDamageScaleOscillationSize(this, 0.05f, 0.0f, 0.0f, "s41", nullptr)
		    , mJumpAttackHealthThreshold(this, 0.5f, 0.0f, 0.0f, "t00", nullptr)
		    , mJumpAttackNoEatBombChance(this, 0.5f, 0.0f, 0.0f, "t01", nullptr)
		    , mJumpAttackEatBombChance(this, 0.9f, 0.0f, 0.0f, "t02", nullptr)
		    , mJumpAttackEatBombFactor(this, 0.1f, 0.0f, 0.0f, "t03", nullptr)
		    , mAttackTerritoryRadius(this, 275.0f, 0.0f, 0.0f, "t10", nullptr)
		    , mJumpAttackRangeXZ(this, 250.0f, 0.0f, 0.0f, "t11", nullptr)
		    , mMaxJumpAttackAngle(this, 120.0f, 0.0f, 0.0f, "t12", nullptr)
		    , mMaxEatPikiNum(this, MAX_PIKI_ON_FIELD, 0, 0, "i00", nullptr)
		    , mSwallowedBombsMin(this, 0, 0, 0, "i10", nullptr)
		    , mSwallowedBombsMax(this, 10, 0, 0, "i11", nullptr)
		    , mEatBombDamageLoopMin(this, 4, 0, 0, "i12", nullptr)
		    , mEatBombDamageLoopMid(this, 4, 0, 0, "i13", nullptr)
		    , mEatBombDamageLoopMax(this, 6, 0, 0, "i14", nullptr)
		    , mHitTongueBombsMin(this, 0, 0, 0, "i20", nullptr)
		    , mHitTongueBombsMax(this, 10, 0, 0, "i21", nullptr)
		    , mHitBombDamageLoopMin(this, 4, 0, 0, "i22", nullptr)
		    , mHitBombDamageLoopMid(this, 4, 0, 0, "i23", nullptr)
		    , mHitBombDamageLoopMax(this, 6, 0, 0, "i24", nullptr)
		    , mTongueRollLoopCount(this, 2, 0, 0, "i30", nullptr)
		    , mMaxConsecutiveJumpAttacks(this, 3, 0, 0, "i40", nullptr)
		{
		}

		// _200-_204 = Parameters
		Parm<f32> mKingWalkSpeed;               // _204, o00
		Parm<f32> mWalkingTurnSpeed;            // _214, o01 - turning speed while walking or chasing
		Parm<f32> mTurningTurnSpeed;            // _224, o02 - turning speed while turning or jump attacking
		Parm<f32> mAttackDistance;              // _234, p00
		Parm<f32> mNormalAttackRangeXZ;         // _244, p01
		Parm<f32> mNormalAttackRangeY;          // _254, p04
		Parm<f32> mTongueRangeXZ;               // _264, p02
		Parm<f32> mTongueRangeY;                // _274, p03
		Parm<f32> mPressAttackRadius;           // _284, p10
		Parm<f32> mHiddenUnderneathRadius;      // _294, q10 - radius in which king loses sight of navi/piki underneath itself (lol)
		Parm<f32> mTongueDamageNavi;            // _2A4, r00
		Parm<f32> mPressDamageNavi;             // _2B4, r01
		Parm<f32> mNormalKingScale;             // _2C4, s00
		Parm<f32> mDetectionRadius;             // _2D4, s10
		Parm<f32> mDispelRadius;                // _2E4, s20 - radius in which navi/piki gets hit by knockback when king appears
		Parm<f32> mDispelPower;                 // _2F4, s21 - how strong knockback effect is when king appears
		Parm<f32> mDispelDamage;                // _304, s23 - blown off damage?
		Parm<f32> _314;                         // _314, s30 - dist from tongue?
		Parm<f32> _324;                         // _324, s31 - height from tongue?
		Parm<f32> _334;                         // _334, s32 - height from map?
		Parm<f32> mDamageScaleOscillationSpeed; // _344, s40
		Parm<f32> mDamageScaleOscillationSize;  // _354, s41
		Parm<f32> mJumpAttackHealthThreshold;   // _364, t00 - chance to do jump attack below this fraction of health
		Parm<f32> mJumpAttackNoEatBombChance;   // _374, t01 - chance for jump based on (1 - eaten bombs factor)
		Parm<f32> mJumpAttackEatBombChance;     // _384, t02 - chance for jump based on eaten bombs factor
		Parm<f32> mJumpAttackEatBombFactor;     // _394, t03 - weighting to give number of bombs eaten when deciding to jump
		Parm<f32> mAttackTerritoryRadius;       // _3A4, t10 - jump attack territory?
		Parm<f32> mJumpAttackRangeXZ;           // _3B4, t11 - jump attack range?
		Parm<f32> mMaxJumpAttackAngle;          // _3C4, t12 - jump attack angle?
		Parm<int> mMaxEatPikiNum;               // _3D4, i00 - 1 attack max eat number?
		Parm<int> mSwallowedBombsMin;           // _3E4, i10 - below this, always get min eat bomb damage loops
		Parm<int> mSwallowedBombsMax;           // _3F4, i11 - above this, always get max eat bomb damage loops
		Parm<int> mEatBombDamageLoopMin;        // _404, i12 - min damage loops from eating bombs
		Parm<int> mEatBombDamageLoopMid;        // _414, i13 - "middle" damage loops from eating bombs (for lagrange interp)
		Parm<int> mEatBombDamageLoopMax;        // _424, i14 - max damage loops from eating bombs
		Parm<int> mHitTongueBombsMin;           // _434, i20 - bomb exploded with tongue (min)?
		Parm<int> mHitTongueBombsMax;           // _444, i21 - bomb exploded with tongue (max)?
		Parm<int> mHitBombDamageLoopMin;        // _454, i22 - damage loop (min)?
		Parm<int> mHitBombDamageLoopMid;        // _464, i23 - damage loop (mid)?
		Parm<int> mHitBombDamageLoopMax;        // _474, i24 - damage loop (max)?
		Parm<int> mTongueRollLoopCount;         // _484, i30 - number of attack loops?
		Parm<int> mMaxConsecutiveJumpAttacks;   // _494, i40 - number of jump attacks?
	};

	KingProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.read(input);
		mBossProps.read(input);
		mKingProps.read(input);
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
public:
	/**
	 * @brief KingBack genuinely doesn't have any specific properties, but still needs this. Go figure.
	 */
	struct KingBackProperties : public Parameters {
		inline KingBackProperties() // TODO
		{
		}

		// _200-_204 = Parameters
	};

	KingBackProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.read(input);
		mBossProps.read(input);
		mKingBackProps.read(input);
	}

	// _F8       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	KingBackProperties mKingBackProps; // _200
};

/**
 * @brief TODO.
 *
 * @note Size: 0x7A4.
 */
struct King : public Boss {
	friend struct KingAi;
	friend struct KingBody;

	friend struct KingGenDamageStarCallBack;
	friend struct KingGenRippleCallBack;
	friend struct KingGenSalivaCallBack;
	friend struct KingGenSalivaParticleCallBack;
	friend struct KingGenSpitPartsParticleCallBack;
	friend struct KingGenSpreadSalivaCallBack;

public:
	King(CreatureProp*);

	virtual void init(immut Vector3f&);              // _28
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

private:
	// _00      = VTBL
	// _00-_3B8 = Boss
	bool mIsBossBgm;            // _3B8
	KingAi* mKingAi;            // _3BC
	KingBody* mKingBody;        // _3C0
	CreaturePlatMgr mPlatMgr;   // _3C4
	ShadowCaster mShadowCaster; // _40C, cast mDrawer to KingDrawer*
};

/**
 * @brief TODO.
 *
 * @note Size: 0x400.
 */
struct KingBack : public Boss {
public:
	KingBack(CreatureProp*);

	virtual void init(immut Vector3f&); // _28
	virtual f32 getiMass();             // _38
	virtual void update();              // _E0
	virtual void refresh(Graphics&);    // _EC
	virtual void doAI();                // _104
	virtual void doAnimation();         // _108
	virtual void doKill();              // _10C
	virtual void exitCourse();          // _110
	virtual void drawShape(Graphics&);  // _120

private:
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
	friend struct KingAi;
	friend struct KingBody;

	friend struct KingGenDamageStarCallBack;
	friend struct KingGenRippleCallBack;
	friend struct KingGenSalivaCallBack;
	friend struct KingGenSalivaParticleCallBack;
	friend struct KingGenSpitPartsParticleCallBack;
	friend struct KingGenSpreadSalivaCallBack;

public:
	KingBody(King*);

	void init(King*);
	void killCallBackEffect(bool);
	void refresh(BossShapeObject*, Graphics&);
	void update();
	void setSeedFlashEffect();
	void setEatBombEffect();
	void createUfoParts();
	void initBlending(f32);

private:
	void setSalivaEffect();
	void createWaterEffect(int);
	void updateBlendingRatio();
	void checkOnGround();
	void setVelocityFromPosition();
	void emitOnGroundEffect();
	void emitSlipEffect();
	void copyOnGround();
	void makeAnimation(BossShapeObject*, Graphics&, Matrix4f*);
	void checkBlendingParm(Matrix4f*);
	void makeBlending(Matrix4f*);
	void copyJointPosition(immut Matrix4f*);
	void returnJoint(BossShapeObject*, Graphics&, immut Matrix4f*);

	King* mKing;                                                  ///< _00
	bool mIsBlending;                                             ///< _04
	bool mDoFallSalivaEffect;                                     ///< _05
	bool mDoSpreadSalivaEffect;                                   ///< _06
	bool mIsFootOnGround[2];                                      ///< _07
	bool mPrevIsFootOnGround[2];                                  ///< _09
	bool mIsFootGeneratingRipples[2];                             ///< _0B
	int mFootMapAttr[2];                                          ///< _10
	f32 mBlendingRate;                                            ///< _18
	f32 mBlendingRatio;                                           ///< _1C
	f32 mMoveSpeed;                                               ///< _20
	Vector3f mFootPosList[2];                                     ///< _24
	Vector3f mOldFootPosList[2];                                  ///< _3C
	Vector3f _UNUSED54;                                           ///< _54
	Vector3f mNormalisedJointDir;                                 ///< _60
	Vector3f mMouthPos;                                           ///< _6C, TODO: these need confirmation (someone?)
	Vector3f mEyePositions[2];                                    ///< _78, TODO: these need confirmation (someone?)
	Vector3f mCheekPositions[2];                                  ///< _90, TODO: these need confirmation (someone?)
	Vector3f mSalivaJointPositions[4];                            ///< _A8
	Vector3f mSalivaEffectPos;                                    ///< _D8
	Vector3f mPrevSalivaEffectPos;                                ///< _E4
	Matrix4f* mBlendStartMatrices;                                ///< _F0
	Matrix4f* mBlendResultMatrices;                               ///< _F4
	KingGenSalivaCallBack* mSalivaCallBacks;                      ///< _F8
	KingGenSpreadSalivaCallBack* mSpreadSalivaCallBack;           ///< _FC
	KingGenSalivaParticleCallBack* mSalivaParticleCallBack;       ///< _100
	KingGenDamageStarCallBack* mDamageStarCallBack;               ///< _104
	KingGenRippleCallBack* mRippleCallBacks;                      ///< _108
	KingGenSpitPartsParticleCallBack* mSpitPartsParticleCallBack; ///< _10C
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
public:
	KingAi(King*);
	void initAI(King*);
	void update();

private:
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _08

	void keyAction0();
	void keyAction1();
	void keyAction2();
	void keyAction3();
	void keyLoopEnd();
	void keyFinished();
	void playSound(int);
	void createEffect(BOOL);
	void setAttackPosition();
	void calcDamageScale();
	void startSpreadSaliva();
	void endSpreadSaliva();
	void startFallSaliva();
	void endFallSaliva();
	void fallBackSide();
	void setMouthCollPart(int);
	int getMouthCollPart(int);
	void pikiStickToKingMouth();
	void tongueBombExplosion();
	void killStickToMouthPiki();
	void tongueAttackNavi();
	void setDispelParm(Creature*, f32);
	void dispelNaviPiki();
	void setDamageLoopCounter(int, int, int, int, int, int);
	void setEatDamageLoopCounter();
	void setBombDamageLoopCounter();
	void setMoveVelocity(f32);
	void setAttackPriority();
	void resetAttackPriority();
	void resultFlagOn();
	void resultFlagSeen();
	bool attackInArea(Creature*, immut Vector3f*);
	bool inJumpAngle(Creature*);
	bool jumpAttackInArea(Creature*, immut Vector3f*);
	bool dieTransit();
	bool damageTransit();
	bool bombDownTransit();
	bool isMotionFinishTransit();
	bool outSideChaseRangeTransit();
	bool inSideWaitRangeTransit();
	bool inTurnAngleTransit();
	bool chaseNaviTransit();
	bool chasePikiTransit();
	bool attackTransit();
	bool missAttackNextTransit();
	bool jumpAttackTransit();
	bool swallowTransit();
	bool eatThrowPikiTransit();
	bool flickTransit();
	bool targetLostTransit();
	bool appearTransit();
	void initDie(int);
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
	void initAppear(int);
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

public:
	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	King* mKing;                        // _04
	u8 mAttackType;                     // _08, see KingAttackType enum
	bool mIsTongueOut;                  // _09
	int mMouthSlotFlag;                 // _0C
	int mMaxMouthSlots;                 // _10
	int mDamageLoopCounter;             // _14
	int mConsecutiveJumpCount;          // _18
	int mBombDamageCounter;             // _1C
	int mEatBombDamageCounter;          // _20
	f32 mDamageScaleOscillation;        // _24
	f32 mMaxJumpAttackAngle;            // _28
	Vector3f mAttackPosition;           // _2C
	Vector3f mJumpAttackStartPosition;  // _38
	Vector3f mJumpAttackTargetPosition; // _44
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct KingGenDamageStarCallBack : public zen::CallBack1<zen::particleGenerator*> {
public:
	virtual bool invoke(zen::particleGenerator* ptclGen) // _08
	{
		if (mKing->getCurrentState() != 1 && mKing->getCurrentState() != 2) {
			ptclGen->finish();
		}
		return true;
	}

	void set(King* king) { mKing = king; }

private:
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
public:
	virtual bool invoke(zen::particleGenerator* ptclGen) // _08
	{
		Vector3f emitPos(*mRippleEmitPos);
		emitPos.y = mKing->mSRT.t.y;
		ptclGen->setEmitPos(emitPos);
		if (!mKing->getAlive() || !*mIsActiveRef) {
			ptclGen->finish();
		}
		return true;
	}

	void set(King* king, immut Vector3f* emitPos, bool* isActive)
	{
		mKing          = king;
		mRippleEmitPos = emitPos;
		mIsActiveRef   = isActive;
	}

private:
	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	bool* mIsActiveRef;             // _04
	King* mKing;                    // _08
	immut Vector3f* mRippleEmitPos; // _0C
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct KingGenSalivaCallBack : public zen::CallBack1<zen::particleGenerator*> {
public:
	virtual bool invoke(zen::particleGenerator* ptcl) // _08
	{
		Vector3f midPt = *mStartPos + *mEndPos;
		midPt.multiply(0.5f);

		Vector3f dir = *mStartPos - *mEndPos;
		dir.normalise();

		ptcl->setEmitPos(midPt);
		ptcl->setEmitDir(dir);

		if (mKing->mKingBody->mDoFallSalivaEffect) {
			ptcl->startGen();
		} else {
			ptcl->stopGen();
		}

		if (!mKing->getAlive()) {
			ptcl->finish();
		}

		return true;
	}

	void set(immut Vector3f* start, immut Vector3f* end, King* king)
	{
		mStartPos = start;
		mEndPos   = end;
		mKing     = king;
	}

private:
	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	immut Vector3f* mStartPos; // _04
	immut Vector3f* mEndPos;   // _08
	King* mKing;               // _0C
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct KingGenSalivaParticleCallBack : public zen::CallBack2<zen::particleGenerator*, zen::particleMdl*> {
	virtual bool invoke(zen::particleGenerator* ptclGen, zen::particleMdl* ptcl) // _08
	{
		if (ptcl->mAge == 0) {
			ptcl->mVelocity.x += (mKing->mKingBody->mSalivaEffectPos.x - mKing->mKingBody->mPrevSalivaEffectPos.x) / 2.0f;
			ptcl->mVelocity.z += (mKing->mKingBody->mSalivaEffectPos.z - mKing->mKingBody->mPrevSalivaEffectPos.z) / 2.0f;
		}

		Vector3f ptclPos = ptcl->getPos();
		f32 minY         = mapMgr->getMinY(ptclPos.x, ptclPos.z, true);

		if (minY > ptclPos.y) {
			CollTriInfo* currTri = mapMgr->getCurrTri(ptclPos.x, ptclPos.z, true);
			if (currTri) {
				Vector3f norm(currTri->mEdgePlanes[0].mNormal);
				norm.multiply(0.01f);
				ptclPos.y = minY;
				ptclGen->killParticle(ptcl);
				zen::particleGenerator* newGen = effectMgr->create(EffectMgr::EFF_King_SalivaDroplet, ptclPos, nullptr, nullptr);
				if (newGen) {
					newGen->setOrientedNormalVector(currTri->mTriangle.mNormal);
					newGen->setEmitDir(norm);
				}
			}
		}
		return true;
	}

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
	virtual bool invoke(zen::particleGenerator* ptclGen, zen::particleMdl* ptcl) // _08
	{
		Vector3f ptclPos = ptcl->getPos();
		f32 minY         = mapMgr->getMinY(ptclPos.x, ptclPos.z, true);
		if (minY > ptclPos.y) {
			CollTriInfo* currTri = mapMgr->getCurrTri(ptclPos.x, ptclPos.z, true);
			if (currTri) {
				Vector3f norm(currTri->mEdgePlanes[0].mNormal);
				norm.multiply(0.01f);
				ptclPos.y = minY;
				ptclGen->killParticle(ptcl);
				zen::particleGenerator* newGen = effectMgr->create(EffectMgr::EFF_King_SalivaDroplet, ptclPos, nullptr, nullptr);
				if (newGen) {
					newGen->setOrientedNormalVector(currTri->mTriangle.mNormal);
					newGen->setEmitDir(norm);
				}
			}
		}
		return true;
	}

	// _00     = VTBL
	// _00-_04 = zen::CallBack2
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct KingGenSpreadSalivaCallBack : public zen::CallBack1<zen::particleGenerator*> {
public:
	virtual bool invoke(zen::particleGenerator* ptcl) // _08
	{
		ptcl->setEmitDir(mKing->mKingBody->mNormalisedJointDir);
		if (mKing->mKingBody->mDoSpreadSalivaEffect) {
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

private:
	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	King* mKing; // _04
};

#endif
