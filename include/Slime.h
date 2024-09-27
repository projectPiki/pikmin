#ifndef _SLIME_H
#define _SLIME_H

#include "types.h"
#include "Boss.h"
#include "Collision.h"

/**
 * @brief TODO.
 */
struct SlimeProp : public BossProp, public CoreNode {
	SlimeProp();

	virtual void read(RandomAccessStream&); // _08

	// _F8       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	// TODO: members
};

/**
 * @brief TODO.
 */
struct Slime : public Boss {

	/**
	 * @brief TODO.
	 */
	struct BoundSphereUpdater : public CollPartUpdater {
		virtual void getPos();  // _08
		virtual void getSize(); // _0C
	};

	/**
	 * @brief TODO.
	 */
	struct CollideSphereUpdater : public CollPartUpdater {
		CollideSphereUpdater();

		virtual void getPos();  // _08
		virtual void getSize(); // _0C
	};

	/**
	 * @brief TODO.
	 */
	struct TubeSphereUpdater : public CollPartUpdater {
		TubeSphereUpdater();

		virtual void getPos();  // _08
		virtual void getSize(); // _0C
	};

	Slime(CreatureProp*, BossShapeObject*);

	virtual void init(Vector3f&);               // _28
	virtual f32 getiMass();                     // _38
	virtual f32 getCentreSize();                // _5C
	virtual void collisionCallback(CollEvent&); // _A8
	virtual void update();                      // _E0
	virtual void refresh(Graphics&);            // _EC
	virtual void doAI();                        // _104
	virtual void doAnimation();                 // _108
	virtual void doKill();                      // _10C
	virtual void exitCourse();                  // _110
	virtual void drawShape(Graphics&);          // _120

	// _00      = VTBL
	// _00-_2B8 = Boss?
};

/**
 * @brief TODO.
 */
struct SlimeBody {
	SlimeBody(Slime*);

	void init(Slime*);
	void sortPosition(Vector3f*, Vector3f*, Vector3f*);
	void update();
	void refresh(BossShapeObject*, Graphics&);

	// unused/inlined:
	void traceCreaturePosition();
	void makeCentrePosition();
	void makeInnerPosition();
	void makeMaxRadius();
	void setSpherePosition();
	void calcVertexScore(Vector3f*, Vector3f*, f32*);
	void makeSlimeBody();
	void setJointPosition(BossShapeObject*, Graphics&);

	// TODO: members
};

/**
 * @brief TODO.
 */
struct SlimeCreature : public Creature {
	SlimeCreature(CreatureProp*);

	virtual f32 getiMass();              // _38
	virtual f32 getSize();               // _3C
	virtual Vector3f getCentre();        // _58
	virtual void setCentre(Vector3f&);   // _6C
	virtual bool isAtari();              // _84
	virtual bool isAlive();              // _88
	virtual bool isFixed();              // _8C
	virtual bool ignoreAtari(Creature*); // _98
	virtual void update();               // _E0
	virtual void refresh(Graphics&);     // _EC
	virtual void doAI();                 // _104
	virtual void doAnimation();          // _108
	virtual void doKill();               // _10C

	void init(Vector3f&, Slime*);

	// _00      = VTBL
	// _00-_2B8 = Creature
	// TODO: members
};

/**
 * @brief TODO.
 */
struct SlimeAi {
	SlimeAi(Slime*);

	void init(Slime*);
	void addDamagePoint(f32);
	void calcBubblePiki();
	void calcStickersRatio();
	void playExpandingSound();
	void calcCollisionCheck();
	void setLeaderNearerTarget();
	void moveFlagCheck();
	void makeFollowerVelocity();
	void makeLeaderVelocity();
	void setMidPointVelocity();
	void calcContractDamage();
	void contractCoreFlickPiki();
	void contractSubFlickPiki();
	void inCaseOfContract();
	void makeTargetRandom();
	void chaseNaviTransit();
	void chasePikiTransit();
	void targetLostTransit();
	void appearTransit();
	void initDie(int);
	void appearState();
	void update();

	// unused/inlined:
	void setEveryFrame();
	void afterProcessing();
	void setLeaderIndex();
	void makeInterrelation();
	void makeBodyThickness();
	void makeTargetPosition();
	void walkAllState();
	void setDieGoal();
	void setContractGoal();
	void setExpansionGoal();
	void setAppearGoal();
	void bothEndsToGoal();
	void bothEndsToAppearGoal();
	void setVelocity(f32);
	void motionFinishTransit();
	void dieTransit();
	void outSideChaseRangeTransit();
	void inSideWaitRangeTransit();
	void collisionContractTransit();
	void dissolutionContractTransit();
	void finishContractTransit();
	void finishExpansionTransit();
	void disAppearTransit();
	void initWalk(int);
	void initChase(int);
	void initContract(int);
	void initExpansion(int);
	void initAppear(int);
	void initDisAppear(int);
	void dieState();
	void walkRandomState();
	void walkGoHomeState();
	void chaseNaviState();
	void chasePikiState();
	void contractState();
	void expansionState();
	void stayState();
	void disAppearState();

	// TODO: members
};

#endif
