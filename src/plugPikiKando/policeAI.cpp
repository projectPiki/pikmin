#include "Actor.h"

/**
 * @brief DLL-exclusive function from a DLL-exclusive translation unit.  Use with caution.
 */
PoliceAI::PoliceAI()
{
	create(PoliceStateID::COUNT);

	addState(PoliceStateID::StopMove, 3, new StopMove());
	addState(PoliceStateID::GoToCreature, 2, nullptr, new GoToCreature());

	addArrow(PoliceStateID::GoToCreature, nullptr, PoliceStateID::StopMove)->addCondition(new Reached(5.0f));
}
