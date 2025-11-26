#include "DebugLog.h"
#include "Dolphin/os.h"
#include "PaniAnimator.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("paniPlantAnimator")

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
	table->setMotion(0, new PaniMotion(0));
	table->setMotion(1, new PaniMotion(1));
	table->setMotion(2, new PaniMotion(2));
	table->setMotion(3, new PaniMotion(3));
	table->setMotion(4, new PaniMotion(4));
	table->setMotion(5, new PaniMotion(5));
	table->setMotion(6, new PaniMotion(6));

	return table;
}

/*
 * --INFO--
 * Address:	8011B290
 * Size:	00003C
 */
PaniPlantAnimator::PaniPlantAnimator()
{
}
