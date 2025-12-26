#include "DebugLog.h"
#include "PikiAI.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(7)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("pickCreature\n")

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void ActPickCreature::init(Creature* target)
{
	ERROR("don't use this!\n"); // lol
	AndAction::init(target);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void ActPickCreature::InitGoto::initialise(Action*, Action*)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void ActDeliver::Initialiser::initialise(Action* deliverAction)
{
	ActDeliver* deliver = static_cast<ActDeliver*>(deliverAction);
	deliver->mObject.set(mObject);
}

/**
 * @todo: Documentation
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
