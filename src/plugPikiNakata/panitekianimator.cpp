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
DEFINE_PRINT("panitekianimator")

immut char* PaniTekiAnimator::motionLabels[TekiMotion::COUNT] = {
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

/**
 * @TODO: Documentation
 */
PaniMotionTable* PaniTekiAnimator::createMotionTable()
{
	PaniMotionTable* table = new PaniMotionTable(TekiMotion::COUNT);
	table->setMotion(TekiMotion::Dead, new PaniMotion(TekiMotion::Dead));
	table->setMotion(TekiMotion::Damage, new PaniMotion(TekiMotion::Damage));
	table->setMotion(TekiMotion::Wait1, new PaniMotion(TekiMotion::Wait1));
	table->setMotion(TekiMotion::Wait2, new PaniMotion(TekiMotion::Wait2));
	table->setMotion(TekiMotion::WaitAct1, new PaniMotion(TekiMotion::WaitAct1));
	table->setMotion(TekiMotion::WaitAct2, new PaniMotion(TekiMotion::WaitAct2));
	table->setMotion(TekiMotion::Move1, new PaniMotion(TekiMotion::Move1));
	table->setMotion(TekiMotion::Move2, new PaniMotion(TekiMotion::Move2));
	table->setMotion(TekiMotion::Attack, new PaniMotion(TekiMotion::Attack));
	table->setMotion(TekiMotion::Flick, new PaniMotion(TekiMotion::Flick));
	table->setMotion(TekiMotion::Type1, new PaniMotion(TekiMotion::Type1));
	table->setMotion(TekiMotion::Type2, new PaniMotion(TekiMotion::Type2));
	table->setMotion(TekiMotion::Type3, new PaniMotion(TekiMotion::Type3));
	table->setMotion(TekiMotion::Type4, new PaniMotion(TekiMotion::Type4));
	table->setMotion(TekiMotion::Type5, new PaniMotion(TekiMotion::Type5));

	return table;
}

/**
 * @TODO: Documentation
 */
PaniTekiAnimator::PaniTekiAnimator()
{
}
