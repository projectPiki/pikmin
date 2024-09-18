#ifndef _UFOITEM_H
#define _UFOITEM_H

#include "types.h"
#include "Suckable.h"
#include "CreatureProp.h"

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
 */
struct UfoItemProp : public CreatureProp {

	// _54     = VTBL
	// _00-_58 = CreatureProp
	// TODO: members
};

/**
 * @brief TODO
 */
struct UfoItem : public Suckable {

	/**
	 * @brief TODO
	 */
	struct LightAnimator {
		LightAnimator();

		void start(int);

		// unused/inlined:
		void update();

		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct Spot {
		Spot();

		// TODO: members
	};

	UfoItem(CreatureProp*, UfoShapeObject*);

	virtual bool insideSafeArea(Vector3f&);              // _10
	virtual void startAI(int);                           // _34
	virtual f32 getiMass();                              // _38
	virtual f32 getSize();                               // _3C
	virtual bool isVisible();                            // _74
	virtual bool isAlive();                              // _88
	virtual bool needShadow();                           // _90
	virtual bool ignoreAtari(Creature*);                 // _98
	virtual void update();                               // _E0
	virtual void refresh(Graphics&);                     // _EC
	virtual void demoDraw(Graphics&, Matrix4f*);         // _FC
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _154
	virtual void getGoalPos();                           // _15C
	virtual void getGoalPosRadius();                     // _160
	virtual void getSuckPos();                           // _164
	virtual void suckMe(Pellet*);                        // _168
	virtual void finishSuck(Pellet*);                    // _16C
	virtual void getRouteIndex();                        // _170

	void setSpotTurn(bool);
	void setSpotActive(bool);
	void setTroubleEffect(bool);
	void startTroubleEffectOne(int);
	void updateTroubleEffect();
	void startConeEffect(int);
	void finishConeEffect();
	void startLevelFlag(int);
	void lightLevelFlag(int);
	void setJetEffect(int, bool);
	void startYozora();
	void startGalaxy();
	void startTakeoff();
	void accessible();
	void startAccess();
	void finishAccess();
	void setPca1Effect(bool);
	void setPca2Effect(bool);

	// unused/inlined:
	void initLevelFlag(int);

	// _00      = VTBL
	// _00-_3C8 = Suckable
	// TODO: members
};

/**
 * @brief TODO
 */
struct UfoAnimator {
	UfoAnimator();

	void init(UfoShapeObject*, PaniMotionTable*);
	void startMotion(int, PaniMotionInfo*);
	void setMotionSpeed(int, f32);
	void getMotionIndex(int);
	void stopAllMotions();
	void initFlagMotions(int);
	void startFlagMotions(int);
	void setMotionLastFrame(int);
	void updateAnimation();
	void updateContext();

	// TODO: members
};

#endif
