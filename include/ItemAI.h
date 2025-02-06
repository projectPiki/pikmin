#ifndef _ITEMAI_H
#define _ITEMAI_H

#include "types.h"
#include "SimpleAI.h"

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct SluiceAI : public SimpleAI {

	enum SluiceStateID {
		Sluice_Init       = 0,
		Sluice_WaitInit   = 1,
		Sluice_ChangeInit = 2,
		Sluice_AddCount   = 3,
		Sluice_MotionDone = 4,
		Sluice_DamageInit = 5,
		Sluice_COUNT, // 6
	};

	/**
	 * @brief TODO
	 */
	struct AddCount : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct ChangeInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct DamageInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct Init : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct MotionDone : public SAIAction {

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

	SluiceAI();

	// _00     = VTBL
	// _00-_1C = SimpleAI
};

/**
 * @brief TODO
 */
struct WaterAI : public SimpleAI {

	/**
	 * @brief TODO
	 */
	enum WaterStateID {
		WATER_Unk0 = 0,
		WATER_Unk1 = 1,
		WATER_Unk2 = 2,
		WATER_Unk3 = 3,
		WATER_Die  = 4,
		WATER_COUNT, // 5
	};

	/**
	 * @brief TODO
	 */
	struct CollideChar : public SAICondition {

		virtual bool satisfy(AICreature*); // _10

		// _00     = VTBL
		// _00-_14 = SAICondition
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct Die : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	WaterAI();

	// _00     = VTBL
	// _00-_?? = SimpleAI
	// TODO: members
};

/**
 * @brief TODO
 */
struct FallWaterAI : public SimpleAI {

	/**
	 * @brief TODO
	 */
	enum FallWaterStateID {
		FALLWATER_Unk0      = 0,
		FALLWATER_Unk1      = 1,
		FALLWATER_Collide   = 2,
		FALLWATER_Emit      = 3,
		FALLWATER_Disappear = 4,
		FALLWATER_COUNT, // 5
	};

	/**
	 * @brief TODO
	 */
	struct CollideInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct DisappearInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct EmitInit : public SAIAction {

		virtual void act(AICreature*); // _08

		// _00     = VTBL
		// _00-_14 = SAIAction
		// TODO: members
	};

	FallWaterAI();

	// _00     = VTBL
	// _00-_?? = SimpleAI
	// TODO: members
};

#endif
