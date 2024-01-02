#include "types.h"
#include "teki.h"

/*
 * --INFO--
 * Address:	8014A398
 * Size:	000034
 */
TekiEvent::TekiEvent(int int_arg, Teki* teki_arg)
{
	init(int_arg, teki_arg, nullptr);
}

/*
 * --INFO--
 * Address:	8014A3CC
 * Size:	000030
 */
TekiEvent::TekiEvent(int int_arg, Teki* teki_arg, Creature* creature_arg)
{
	init(int_arg, teki_arg, creature_arg);
}

/*
 * --INFO--
 * Address:	8014A3FC
 * Size:	000010
 */
void TekiEvent::init(int int_arg, Teki* teki_arg, Creature* creature_arg)
{
	mInt         = int_arg;
	mTekiptr     = teki_arg;
	mCreatureptr = creature_arg;
}
