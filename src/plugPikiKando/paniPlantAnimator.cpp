#include "DebugLog.h"
#include "Dolphin/os.h"
#include "PaniAnimator.h"
#include "sysNew.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("paniPlantAnimator")

immut char* PaniPlantAnimator::motionLabels[PlantMotion::COUNT] = {
	"1", "2", "3", "4", "5", "6", "7",
};

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
PaniPlantAnimator::PaniPlantAnimator()
{
}
