#include "TekiStrategy.h"
#include "DebugLog.h"
#include "sysNew.h"
#include "teki.h"

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
DEFINE_PRINT("tekistrategy")

TekiStrategy::TekiStrategy()
{
}

void TekiStrategy::start(Teki&)
{
}

void TekiStrategy::act(Teki&)
{
}

void TekiStrategy::eventPerformed(immut TekiEvent&)
{
}

void TekiStrategy::createEffect(Teki&, int)
{
}

void TekiStrategy::draw(Teki& teki, Graphics& gfx)
{
	teki.drawDefault(gfx);
}

void TekiStrategy::drawDebugInfo(Teki& teki, Graphics& gfx)
{
	teki.drawTekiDebugInfoDefault(gfx);
}

bool TekiStrategy::interact(Teki& teki, immut TekiInteractionKey& key)
{
	return teki.interactDefault(key);
}

void TekiStrategy::spawnCorpseParts(Teki&)
{
}

TekiStrategyTable::TekiStrategyTable(int count)
{
	mCount      = count;
	mStrategies = new TekiStrategy*[mCount];
	for (int i = 0; i < mCount; i++) {
		mStrategies[i] = nullptr;
	}
}
