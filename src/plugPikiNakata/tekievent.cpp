#include "types.h"
#include "Teki.h"

/*
 * --INFO--
 * Address:	8014A398
 * Size:	000034
 */
TekiEvent::TekiEvent(int p1, Teki* teki) { init(p1, teki, nullptr); }

/*
 * --INFO--
 * Address:	8014A3CC
 * Size:	000030
 */
TekiEvent::TekiEvent(int p1, Teki* teki, Creature* creature) { init(p1, teki, creature); }

/*
 * --INFO--
 * Address:	8014A3FC
 * Size:	000010
 */
void TekiEvent::init(int p1, Teki* teki, Creature* creature)
{
	_00   = p1;
	mTeki = teki;
	_08   = creature;
}
