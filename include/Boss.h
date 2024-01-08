#ifndef _BOSS_H
#define _BOSS_H

#include "types.h"
#include "Creature.h"
#include "CreatureProp.h"

/**
 * @brief TODO
 */
struct BossProp : public CreatureProp {
	BossProp();

	virtual void read(RandomAccessStream&); // _08

	// _F8     = VTBL
	// _00-_FC = CreatureProp
	// TODO: members
};

/**
 * @brief TODO
 */
struct Boss : public Creature {
	Boss(CreatureProp*);

	virtual void getCentre();                          // _58
	virtual void getShadowSize();                      // _70
	virtual bool isVisible();                          // _74
	virtual bool isOrganic();                          // _78
	virtual bool isAtari();                            // _84
	virtual bool isAlive();                            // _88
	virtual bool isFixed();                            // _8C
	virtual bool needShadow();                         // _90
	virtual void ignoreAtari(Creature*);               // _98
	virtual void stimulate(Interaction&);              // _A0
	virtual void collisionCallback(CollEvent&);        // _A8
	virtual void wallCallback(Plane&, DynCollObject*); // _B4
	virtual void update();                             // _E0
	virtual void refresh(Graphics&);                   // _EC
	virtual void refresh2d(Graphics&);                 // _F0
	virtual void doKill();                             // _10C
	virtual void exitCourse();                         // _110
	virtual bool isBossBgm();                          // _114
	virtual void attackDefaultPortion();               // _118
	virtual void bombDamageCounter(CollPart*);         // _11C
	virtual void drawShape(Graphics&);                 // _120

	void initBoss(struct BirthInfo&, int);
	void calcFlickPiki();
	void createPellet(Vector3f&, f32, bool);
	void changeDirection(f32);
	void stopMovement();
	void calcBossDamage();
	void makeTargetCreature();
	void makeTargetRandom(f32);
	void chaseNaviTransit();
	void chasePikiTransit();
	void targetLostTransit();
	void inSideWaitRangeTransit();
	void outSideChaseRangeTransit();
	bool inSearchAngle(Creature*);
	void flickPikiTransit();
	int getStickPikiCount();
	int getStickMouthPikiCount();
	int getStickNoMouthPikiCount();
	void killStickToMouthPiki();
	void getMapAttribute(Vector3f&);
	void insideAndInSearch();
	void updateBoss();
	void refreshViewCulling(Graphics&);

	// unused/inlined:
	void towardFaceDirection(f32);
	void checkInWater(Vector3f&);
	void recoveryLife();

	// _00      = VTBL
	// _00-_2B8 = Creature
	// TODO: members
};

/**
 * @brief TODO
 */
struct BossMgr {
};

#endif
