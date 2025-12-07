#ifndef _UFOITEM_H
#define _UFOITEM_H

#include "CreatureProp.h"
#include "EffectMgr.h"
#include "Shape.h"
#include "SoundMgr.h"
#include "Suckable.h"
#include "types.h"

struct Piki;
struct SimpleAI;

/**
 * @brief TODO
 */
struct UfoShapeObject {
	UfoShapeObject(Shape*);

	// TODO: members
	Shape* mShape;              // _00
	AnimMgr* mAnimMgr;          // _04
	AnimContext* mAnimContexts; // _08, array of 8 contexts
};

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct UfoItemProp : public CreatureProp {
	inline UfoItemProp()
	{
		mCreatureProps.mFriction.mValue     = 0.1f;
		mCreatureProps.mBounceFactor.mValue = 0.8f;
	}

	// _54     = VTBL
	// _00-_58 = CreatureProp
};

/**
 * @brief TODO
 */
struct UfoAnimator {
public:
	UfoAnimator();

	void init(UfoShapeObject*, PaniMotionTable*);
	void startMotion(int, PaniMotionInfo*);
	void setMotionSpeed(int, f32);
	int getMotionIndex(int);
	void stopAllMotions();
	void initFlagMotions(int);
	void startFlagMotions(int);
	void updateAnimation();
	void updateContext();

	f32 getMotionSpeed(int id) { return mAnimSpeeds[id]; }

protected:
	void setMotionLastFrame(int);

	PaniUfoAnimator* mAnims; // _00
	f32* mAnimSpeeds;        // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x5D0.
 */
struct UfoItem : public Suckable {
public:
	/**
	 * @brief TODO
	 */
	struct LightAnimator {
		LightAnimator();

		void start(int);

		// unused/inlined:
		void update();

		void setSpeed(f32 speed) { mSpeed = speed; }

		ShapeDynMaterials* mDyn; // _00
		f32 mFrame;              // _04
		f32 mSpeed;              // _08
		u16 mType;               // _0C
	};

	/**
	 * @brief TODO
	 */
	struct Spot {
		Spot() { }

		Vector3f mPosition; // _00
		f32 mRadius;        // _0C
		f32 mAngleOffset;   // _10
		f32 mRotationTime;  // _14
		f32 _18;            // _18
	};

	UfoItem(CreatureProp*, UfoShapeObject*);

	virtual bool insideSafeArea(immut Vector3f&);              // _10
	virtual void startAI(int);                                 // _34
	virtual f32 getiMass();                                    // _38
	virtual f32 getSize();                                     // _3C
	virtual bool needShadow();                                 // _90
	virtual bool ignoreAtari(Creature*);                       // _98
	virtual void update();                                     // _E0
	virtual void refresh(Graphics&);                           // _EC
	virtual void demoDraw(Graphics&, immut Matrix4f*);         // _FC
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _154
	virtual Vector3f getGoalPos();                             // _15C
	virtual f32 getGoalPosRadius();                            // _160
	virtual Vector3f getSuckPos();                             // _164
	virtual void suckMe(Pellet*);                              // _168
	virtual void finishSuck(Pellet*);                          // _16C
	virtual int getRouteIndex() { return mWaypointID; }        // _170
	virtual bool isVisible() { return true; }                  // _74
	virtual bool isAlive() { return true; }                    // _88

	void setSpotTurn(bool);
	void setSpotActive(bool);
	void setTroubleEffect(bool);
	void startTroubleEffectOne(int);
	void updateTroubleEffect();
	void startConeEffect(int);
	void finishConeEffect();
	void initLevelFlag(int);
	void startLevelFlag(int);
	void setJetEffect(int, bool);
	void startYozora();
	void startGalaxy();
	void startTakeoff();
	bool accessible();
	void startAccess();
	void finishAccess();
	void setPca1Effect(bool);
	void setPca2Effect(bool);

protected:
	void lightLevelFlag(int);

	// I took `GameCoreSection` and `AIPerf` directly accessing members as a clue that this class was never properly encapsulated.
public:
	// _00      = VTBL
	// _00-_3C8 = Suckable
	bool mIsMenuOpen;                                     // _3C8
	bool mIsLightActive;                                  // _3C9
	bool mShouldLightActivate;                            // _3CA
	zen::particleGenerator* mRingFx;                      // _3CC
	zen::particleGenerator* mSparkleFx;                   // _3D0
	Spot mSpots[3];                                       // _3D4
	bool mIsTroubleFxEnabled;                             // _428
	f32 mTroubleFxTimer;                                  // _42C
	u32 mTroubleFxState;                                  // _430
	Vector3f _434;                                        // _434
	Vector3f _440;                                        // _440
	Vector3f _44C;                                        // _44C
	Vector3f _458;                                        // _458
	Vector3f _464;                                        // _464
	Vector3f _470;                                        // _470
	Vector3f mTroubleFxPositionList[6];                   // _47C
	zen::particleGenerator* mTroubleFxGenList[6];         // _4C4
	s16 mJetLevel;                                        // _4DC
	zen::particleGenerator* mEngineParticleGenList[4][4]; // _4E0
	u8 mShipUpgradeLevel;                                 // _520
	UfoAnimator mAnimator;                                // _524
	int mConeEffectId;                                    // _52C
	Vector3f mPca1FxPosition;                             // _530
	Vector3f mPca2FxPosition;                             // _53C
	bool mIsPca1FxActive;                                 // _548
	bool mIsPca2FxActive;                                 // _549
	Vector3f mSpotlightPosition;                          // _54C
	int mWaypointID;                                      // _558
	UfoShapeObject* mShipModel;                           // _55C
	SeContext mShipSe;                                    // _560
	ShapeDynMaterials* mDynMat;                           // _588
	LightAnimator mLightAnims[4];                         // _58C
	bool mNeedPathfindRefresh;                            // _5CC
};

#endif
