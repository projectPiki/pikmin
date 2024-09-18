#ifndef _PLANTMGR_H
#define _PLANTMGR_H

#include "types.h"
#include "CreatureNode.h"
#include "SimpleAI.h"

struct MapMgr;

/**
 * @brief TODO
 */
struct PlantShapeObject {
	PlantShapeObject(Shape*, char*, char*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct Plant : public AICreature {
	Plant();

	virtual void startAI(int);        // _34
	virtual f32 getiMass();           // _38
	virtual bool isAlive();           // _88
	virtual void update();            // _E0
	virtual void refresh(Graphics&);  // _EC
	virtual void doAnimation();       // _108
	virtual void doKill();            // _10C
	virtual void startMotion(int);    // _130
	virtual void setMotionSpeed(f32); // _14C
	virtual void stopMotion();        // _150

	// unused/inlined:
	void reset(int);

	// _00      = VTBL
	// _00-_??? = AICreature?
	// TODO: work out members
};

/**
 * @brief TODO
 */
struct PlantAI : public SimpleAI {

	/**
	 * @brief TODO
	 */
	struct OpponentMove : public SAICondition {

		virtual bool satisfy(AICreature*); // _10

		// _00     = VTBL
		// _00-_14 = CoreNode
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct TouchInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = CoreNode
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct WaitInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = CoreNode
		// TODO: members
	};

	PlantAI();

	// _00     = VTBL
	// _00-_?? = SimpleAI
	// TODO: members
};

/**
 * @brief TODO
 */
struct PlantMgr : public CreatureNodeMgr {

	/**
	 * @brief TODO
	 */
	struct UseNode : public CoreNode {
		// _00     = VTBL
		// _00-_14 = CoreNode
		// TODO: members
	};

	PlantMgr(MapMgr*);

	virtual ~PlantMgr();           // _48
	virtual Plant* createObject(); // _78

	void initialise();
	void usePlantType(int);

	// unused/inlined:
	void getPlantName(int);
	void addUseList(int);
	void birth();

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_?? = CreatureNodeMgr
	// TODO: members
};

#endif
