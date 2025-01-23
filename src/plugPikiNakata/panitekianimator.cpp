#include "PaniAnimator.h"
#include "sysNew.h"
#include "Dolphin/os.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("panitekianimator")

char* PaniTekiAnimator::motionLabels[15] = {
	"DEAD",         // 0
	"DAMAGE",       // 1
	"WAIT_1",       // 2
	"WAIT_2",       // 3
	"WAITACTION_1", // 4
	"WAITACTION_2", // 5
	"MOVE_1",       // 6
	"MOVE_2",       // 7
	"ATTACK",       // 8
	"FLICK",        // 9
	"TYPE_1",       // 10
	"TYPE_2",       // 11
	"TYPE_3",       // 12
	"TYPE_4",       // 13
	"TYPE_5",       // 14
};

/*
 * --INFO--
 * Address:	8011FC54
 * Size:	000268
 */
PaniMotionTable* PaniTekiAnimator::createMotionTable()
{
	PaniMotionTable* table = new PaniMotionTable(15);
	table->setMotion(0, new PaniMotion(0));
	table->setMotion(1, new PaniMotion(1));
	table->setMotion(2, new PaniMotion(2));
	table->setMotion(3, new PaniMotion(3));
	table->setMotion(4, new PaniMotion(4));
	table->setMotion(5, new PaniMotion(5));
	table->setMotion(6, new PaniMotion(6));
	table->setMotion(7, new PaniMotion(7));
	table->setMotion(8, new PaniMotion(8));
	table->setMotion(9, new PaniMotion(9));
	table->setMotion(10, new PaniMotion(10));
	table->setMotion(11, new PaniMotion(11));
	table->setMotion(12, new PaniMotion(12));
	table->setMotion(13, new PaniMotion(13));
	table->setMotion(14, new PaniMotion(14));

	return table;
}

/*
 * --INFO--
 * Address:	8011FEBC
 * Size:	00003C
 */
PaniTekiAnimator::PaniTekiAnimator()
{
}
