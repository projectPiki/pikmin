#include "DebugLog.h"
#include "PikiAI.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(7)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("pickCreature\n")

/**
 * @TODO: Documentation
 */
ActPickCreature::ActPickCreature(Piki* piki)
    : AndAction(piki)
{
	setChildren(CHILD_COUNT,                //
	            new ActGoto(piki), nullptr, //
	            new ActPick(piki), nullptr  //
	);
}

/**
 * @TODO: Documentation
 */
void ActPickCreature::init(Creature* target)
{
	ERROR("don't use this!\n"); // lol
	AndAction::init(target);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void ActPickCreature::InitGoto::initialise(Action*, Action*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00019C
 */
ActDeliver::ActDeliver(Piki* piki)
    : AndAction(piki)
{
	setChildren(CHILD_COUNT,                                                       //
	            new ActPickCreature(piki), nullptr,                                //
	            new ActGoto(piki), new ActGoto::Initialiser(50.0f, 0.0f, nullptr), //
	            new ActPut(piki), nullptr                                          //
	);
}

/**
 * @TODO: Documentation
 */
void ActDeliver::Initialiser::initialise(Action* deliverAction)
{
	ActDeliver* deliver = static_cast<ActDeliver*>(deliverAction);
	deliver->mObject.set(mObject);
}

/**
 * @TODO: Documentation
 */
void ActDeliver::init(Creature* target)
{
	AndAction::init(target);
	if (mObject.isNull()) {
		mObject.set(target);
		return;
	}

	if (mChildActions[CHILD_Goto].mInitialiser) {
		static_cast<ActGoto::Initialiser*>(mChildActions[CHILD_Goto].mInitialiser)->mTarget = mObject.getPtr();
	}
}
