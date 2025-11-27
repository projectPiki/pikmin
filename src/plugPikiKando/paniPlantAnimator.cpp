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

char* PaniPlantAnimator::motionLabels[PlantMotion::COUNT] = {
	"1", "2", "3", "4", "5", "6", "7",
};

/*
 * --INFO--
 * Address:	8011B148
 * Size:	000148
 */
PaniMotionTable* PaniPlantAnimator::createMotionTable()
{
	PaniMotionTable* table = new PaniMotionTable(PlantMotion::COUNT);
	table->setMotion(PlantMotion::Touch, new PaniMotion(PlantMotion::Touch));
	table->setMotion(PlantMotion::Unused1, new PaniMotion(PlantMotion::Unused1));
	table->setMotion(PlantMotion::Unused2, new PaniMotion(PlantMotion::Unused2));
	table->setMotion(PlantMotion::Unused3, new PaniMotion(PlantMotion::Unused3));
	table->setMotion(PlantMotion::Unused4, new PaniMotion(PlantMotion::Unused4));
	table->setMotion(PlantMotion::Unused5, new PaniMotion(PlantMotion::Unused5));
	table->setMotion(PlantMotion::Unused6, new PaniMotion(PlantMotion::Unused6));

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
