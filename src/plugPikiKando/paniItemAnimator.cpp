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
DEFINE_PRINT("paniItemAnimator")

immut char* PaniItemAnimator::motionLabels[15] = {
	"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15",
};

PaniMotionTable* PaniItemAnimator::createMotionTable()
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

PaniItemAnimator::PaniItemAnimator()
{
}
