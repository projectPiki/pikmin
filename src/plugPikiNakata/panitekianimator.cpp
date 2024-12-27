#include "PaniAnimator.h"
#include "sysNew.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...) { OSPanic(__FILE__, __LINE__, fmt, "panitekianimator"); }

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

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
	table->addMotion(0, new PaniMotion(0));
	table->addMotion(1, new PaniMotion(1));
	table->addMotion(2, new PaniMotion(2));
	table->addMotion(3, new PaniMotion(3));
	table->addMotion(4, new PaniMotion(4));
	table->addMotion(5, new PaniMotion(5));
	table->addMotion(6, new PaniMotion(6));
	table->addMotion(7, new PaniMotion(7));
	table->addMotion(8, new PaniMotion(8));
	table->addMotion(9, new PaniMotion(9));
	table->addMotion(10, new PaniMotion(10));
	table->addMotion(11, new PaniMotion(11));
	table->addMotion(12, new PaniMotion(12));
	table->addMotion(13, new PaniMotion(13));
	table->addMotion(14, new PaniMotion(14));

	return table;
}

/*
 * --INFO--
 * Address:	8011FEBC
 * Size:	00003C
 */
PaniTekiAnimator::PaniTekiAnimator() { }
