#include "DebugLog.h"
#include "PikiAI.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(7)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("pickCreature\n")

/*
 * --INFO--
 * Address:	800BD364
 * Size:	0000CC
 */
ActPickCreature::ActPickCreature(Piki* piki)
    : AndAction(piki)
{
	setChildren(CHILD_COUNT,                //
	            new ActGoto(piki), nullptr, //
	            new ActPick(piki), nullptr  //
	);
}

/*
 * --INFO--
 * Address:	800BD430
 * Size:	000020
 */
void ActPickCreature::init(Creature* target)
{
	ERROR("don't use this!\n"); // lol
	AndAction::init(target);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void ActPickCreature::InitGoto::initialise(Action*, Action*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00019C
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

/*
 * --INFO--
 * Address:	800BD450
 * Size:	000064
 */
void ActDeliver::Initialiser::initialise(Action* deliverAction)
{
	ActDeliver* deliver = static_cast<ActDeliver*>(deliverAction);
	deliver->mObject.set(mObject);
}

/*
 * --INFO--
 * Address:	800BD4B4
 * Size:	000084
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
