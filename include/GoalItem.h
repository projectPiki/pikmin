#ifndef _GOALITEM_H
#define _GOALITEM_H

#include "types.h"
#include "Suckable.h"
#include "zen/CallBack.h"
#include "zen/particle.h"
#include "CreatureProp.h"
#include "SimpleAI.h"
#include "SoundMgr.h"
#include "Shape.h"
#include "RopeCreature.h"

namespace zen {
struct particleGenerator;
struct particleMdl;
} // namespace zen

struct ItemShapeObject;
struct Piki;
struct SimpleAI;
struct EffShpInst;

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct GoalItemProp : public CreatureProp {
	inline GoalItemProp()
	{
		mCreatureProps.mFriction.mValue     = 0.1f;
		mCreatureProps.mBounceFactor.mValue = 0.8f;
	}

	// _54     = VTBL
	// _00-_58 = CreatureProp
};

/**
 * @brief TODO
 *
 * @note Size: 0x494.
 */
struct GoalItem : public Suckable, public zen::CallBack2<zen::particleGenerator*, zen::particleMdl*> {
	GoalItem(CreatureProp*, ItemShapeObject*, ItemShapeObject*, ItemShapeObject*, SimpleAI*);

	virtual bool insideSafeArea(Vector3f&);                          // _10
	virtual void startAI(int);                                       // _34
	virtual f32 getiMass();                                          // _38
	virtual f32 getSize();                                           // _3C
	virtual bool isVisible();                                        // _74
	virtual bool isAlive();                                          // _88
	virtual bool needShadow();                                       // _90
	virtual bool ignoreAtari(Creature*);                             // _98
	virtual void update();                                           // _E0
	virtual void refresh(Graphics&);                                 // _EC
	virtual void playEffect(int);                                    // _12C
	virtual Vector3f getGoalPos();                                   // _15C
	virtual f32 getGoalPosRadius();                                  // _160
	virtual Vector3f getSuckPos();                                   // _164
	virtual void suckMe(Pellet*);                                    // _168
	virtual int getRouteIndex();                                     // _170
	virtual bool invoke(zen::particleGenerator*, zen::particleMdl*); // _180

	void setFlowEffect(bool);
	void setSpotActive(bool);
	void setFlightLight(bool);
	void enterGoal(Piki*);
	void exitPikis(int);
	Piki* exitPiki();
	void setColorType(int);
	void startTakeoff();
	void startLand();
	void startConeShrink();
	void startConeEmit();
	void startBoot();
	void emitPiki();

	// unused/inlined:
	void updateConeShrink();
	void updateConeEmit();

	static u8 demoHideFlag;

	void disableColorAnim()
	{
		mColourAnimProgress     = 1.0f;
		mColourAnimationEnabled = false;
	}

	void enableColorAnim()
	{
		mColourAnimProgress     = 0.0f;
		mColourAnimationEnabled = true;
	}

	int getTotalStorePikis() { return mHeldPikis[0] + mHeldPikis[1] + mHeldPikis[2]; }

	// _00       = VTBL
	// _00-_3C8  = Suckable
	// _3C8-_3CC = zen::CallBack2
	u8 _3CC;                          // _3CC
	f32 mColourFadeRate;              // _3D0
	f32 mColourAnimProgress;          // _3D4
	bool mColourAnimationEnabled;     // _3D8
	bool mSpotEffectActive;           // _3D9
	zen::particleGenerator* mSpotEfx; // _3DC
	zen::particleGenerator* mHaloEfx; // _3E0
	bool _3E4;                        // _3E4
	zen::particleGenerator* mSuckEfx; // _3E8
	bool _3EC;                        // _3EC
	int _3F0;                         // _3F0
	u8 _3F4;                          // _3F4
	bool _3F5;                        // _3F5
	bool mIsClosing;                  // _3F6
	f32 mConeSizeTimer;               // _3F8
	Vector3f _3FC;                    // _3FC
	bool mIsConeEmit;                 // _408
	EffShpInst* mSpotModelEff;        // _40C
	bool mIsDispensingPikis;          // _410
	int mPikisToExit;                 // _414
	f32 mPikiSpawnTimer;              // _418
	Vector3f _41C;                    // _41C
	u16 mOnionColour;                 // _428
	s16 mWaypointIdx;                 // _42A
	u32 mHeldPikis[3];                // _42C, contains counts for leaf/bud/flower
	ItemShapeObject* _438[3];         // _438
	int _444;                         // _444
	RopeItem* mRope[3];               // _448
	u32 _454;                         // _454
	u32 _458;                         // _458
	SeContext _45C;                   // _45C
	ShapeDynMaterials mDynMaterial;   // _484
};

/**
 * @brief TODO
 */
struct GoalAI : public SimpleAI {

	/**
	 * @brief TODO
	 */
	struct NotFinished : public SAICondition {

		virtual bool satisfy(AICreature*); // _10

		// _00     = VTBL
		// _00-_14 = SAICondition
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct BootDone : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct BootEmit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct BootInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct Effect : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct EmitPiki : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct EmitWait : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct WaitInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	GoalAI();

	// _00     = VTBL
	// _00-_?? = SimpleAI
	// TODO: members
};

#endif
