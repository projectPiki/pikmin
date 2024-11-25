#include "PaniAnimator.h"
#include "Dolphin/os.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...) { OSPanic(__FILE__, __LINE__, fmt, "paniPlantAnimator"); }

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

char* PaniPlantAnimator::motionLabels[7] = {
	"1", "2", "3", "4", "5", "6", "7",
};

/*
 * --INFO--
 * Address:	8011B148
 * Size:	000148
 */
PaniMotionTable* PaniPlantAnimator::createMotionTable()
{
	PaniMotionTable* table = new PaniMotionTable(7);
	table->mMotions[0]     = new PaniMotion(0);
	table->mMotions[1]     = new PaniMotion(1);
	table->mMotions[2]     = new PaniMotion(2);
	table->mMotions[3]     = new PaniMotion(3);
	table->mMotions[4]     = new PaniMotion(4);
	table->mMotions[5]     = new PaniMotion(5);
	table->mMotions[6]     = new PaniMotion(6);

	return table;
}

/*
 * --INFO--
 * Address:	8011B290
 * Size:	00003C
 */
PaniPlantAnimator::PaniPlantAnimator() { }
