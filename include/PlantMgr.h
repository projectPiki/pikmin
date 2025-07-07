#ifndef _PLANTMGR_H
#define _PLANTMGR_H

#include "CreatureNode.h"
#include "SimpleAI.h"
#include "types.h"

struct MapMgr;

/**
 * @brief Descriptions taken from translations or from Minty Meeo's documentation.
 */
enum PlantTypes {
	PLANT_NULL     = -1,
	PLANT_START    = 0,
	PLANT_Clover   = 0,  // clover
	PLANT_Chidome  = 1,  // red lawn marshpennywort (Hydrocotyle sibthorpioides)
	PLANT_Hutaba   = 2,  // (really) short shoot
	PLANT_Ine      = 3,  // tall grass
	PLANT_Tanpopo  = 4,  // dandelion
	PLANT_Ooinu_l  = 5,  // birdseye speedwell (Veronica persica), large
	PLANT_Ooinu_s  = 6,  // birdseye speedwell (Veronica persica), small
	PLANT_Mizukusa = 7,  // pygmy chain sword (Echinodorus Tenellus)
	PLANT_Wakame_l = 8,  // shoot, large
	PLANT_Wakame_s = 9,  // shoot, small
	PLANT_KinokoLt = 10, // glowcap (kinoko light)
	PLANT_Hae      = 11, // flies (yes flies are a plant in Pikmin)
	PLANT_COUNT,         // 12
};

/**
 * @brief TODO
 */
struct PlantShapeObject {
	PlantShapeObject(Shape* shape, char* plantName, char* fileName);

	Shape* mShape;            // _00
	AnimMgr* mAnimMgr;        // _04
	AnimContext mAnimContext; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x398.
 */
struct Plant : public AICreature {
	Plant();

	virtual void startAI(int);                                       // _34
	virtual f32 getiMass() { return 0.0f; }                          // _38
	virtual bool isAlive() { return !_30C; }                         // _88
	virtual void update();                                           // _E0
	virtual void refresh(Graphics&);                                 // _EC
	virtual void doAnimation();                                      // _108
	virtual void doKill();                                           // _10C
	virtual void startMotion(int);                                   // _130
	virtual void setMotionSpeed(f32 speed) { mMotionSpeed = speed; } // _14C
	virtual void stopMotion() { mMotionSpeed = 0.0f; }               // _150

	// unused/inlined:
	void reset(int);

	// _00      = VTBL
	// _00-_304 = AICreature
	u16 mPlantType;                   // _304, see PlantTypes enum
	f32 mMotionSpeed;                 // _308
	u8 _30C;                          // _30C
	PaniPlantAnimator mPlantAnimator; // _310
	SearchData mPlantSearchData[3];   // _364
	Vector3f _388;                    // _388
	u8 _394;                          // _394
	                                  // TODO: work out members
};

/**
 * @brief TODO
 */
struct PlantAI : public SimpleAI {

	/**
	 * @brief TODO
	 */
	enum StateID {
		STATE_Wait  = 0,
		STATE_Touch = 1,
		STATE_COUNT, // 2
	};

	/**
	 * @brief Condition to move from WaitInit to TouchInit.
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
	// _00-_1C = SimpleAI
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
		UseNode() { initCore("usageNode"); }

		// _00     = VTBL
		// _00-_14 = CoreNode
		int mPlantType; // _14
	};

	PlantMgr(MapMgr*);

	virtual ~PlantMgr() { }           // _48
	virtual Creature* createObject(); // _78

	void initialise();
	bool usePlantType(int);

	// unused/inlined:
	char* getPlantName(int);
	void addUseList(int);
	Creature* birth();

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_40 = CreatureNodeMgr
	PlantShapeObject** mPlantShapes;   // _40
	PaniMotionTable* mMotionTable;     // _44
	MapMgr* mMapMgr;                   // _48
	UseNode mRootUseNode;              // _4C
	PlantAI* mAI;                      // _64
	CreatureProp* mPlantProps;         // _68
	AnimFrameCacher* mAnimFrameCacher; // _6C
};

extern PlantMgr* plantMgr;

#endif
