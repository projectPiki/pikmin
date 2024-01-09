#ifndef _BOSS_H
#define _BOSS_H

#include "types.h"
#include "Creature.h"
#include "CreatureProp.h"
#include "ID32.h"
#include "PaniAnimator.h"
#include "ObjectMgr.h"
#include "SearchSystem.h"
#include "Vector3f.h"

struct GenObjectBoss;
struct BossShapeObject;

/**
 * @brief TODO
 */
struct BossProp : public CreatureProp {
	BossProp();

	virtual void read(RandomAccessStream&); // _08

	// _F8     = VTBL
	// _00-_FC = CreatureProp
	u8 _FC[0x1EC - 0xFC]; // _FC, TODO: work out members
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
	virtual bool ignoreAtari(Creature*);               // _98
	virtual void stimulate(Interaction&);              // _A0
	virtual void collisionCallback(CollEvent&);        // _A8
	virtual void wallCallback(Plane&, DynCollObject*); // _B4
	virtual void update();                             // _E0
	virtual void refresh(Graphics&);                   // _EC
	virtual void refresh2d(Graphics&);                 // _F0
	virtual void doKill();                             // _10C
	virtual void exitCourse();                         // _110
	virtual bool isBossBgm();                          // _114
	virtual bool attackDefaultPortion();               // _118
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
	u8 _2B8;                       // _2B8
	u8 _2B9;                       // _2B9
	u8 _2BA[0x2];                  // _2BA, unknown/padding
	u8 _2BC[0x300 - 0x2BC];        // _2BC, unknown
	Vector3f _300;                 // _300
	Vector3f _30C;                 // _30C
	u8 _318[0x4];                  // _318, unknown
	ID32 mID;                      // _31C
	Vector3f _328;                 // _328
	u8 _334[0x8];                  // _334, unknown
	PaniTekiAnimator mAnimator;    // _33C
	u8 _370[0x390 - 0x370];        // _370, unknown
	BossShapeObject* mShapeObject; // _390
	SearchData mSearchData[3];     // _394
};

/**
 * @brief TODO
 */
struct BossMgr : public ObjectMgr {
	BossMgr();

	virtual Creature* getCreature(int); // _08
	virtual int getFirst();             // _0C
	virtual int getNext(int);           // _10
	virtual bool isDone(int);           // _14
	virtual ~BossMgr();                 // _48
	virtual void update();              // _4C
	virtual void refresh(Graphics&);    // _58
	virtual int getSize();              // _60
	virtual int getMax();               // _64
	virtual void killAll();             // _74

	void addUseCount(int, int);
	void constructBoss();
	void initSlime(int);
	void init(int, int);
	void create(int, BirthInfo&, GenObjectBoss*);
	void kill(Creature*);
	void refresh2d(Graphics&);
	void finalSetup();
	void getBossShapeObject(int);

	// unused/inlined:
	void useBoss(int);
	void getUseCount(int);
	void animatorInit(Boss*);
	void initSpider(int);
	void initSnake(int);
	void initBoxSnake(int);
	void initKing(int);
	void initKogane(int);
	void initPom(int);
	void initKingBack(int);
	void initMizu(int);
	void initGeyzer(int);
	void setBossParam(Boss*, GenObjectBoss*);
	void createBoss(int);

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_1C = ObjectMgr?
	// TODO: members
};

extern BossMgr* bossMgr;

#endif
