#include "TekiStrategy.h"
#include "DebugLog.h"
#include "sysNew.h"
#include "teki.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("tekistrategy")

/**
 * @todo: Documentation
 */
TekiStrategy::TekiStrategy()
{
}

/**
 * @todo: Documentation
 */
void TekiStrategy::start(Teki&)
{
}

/**
 * @todo: Documentation
 */
void TekiStrategy::act(Teki&)
{
}

/**
 * @todo: Documentation
 */
void TekiStrategy::eventPerformed(immut TekiEvent&)
{
}

/**
 * @todo: Documentation
 */
void TekiStrategy::createEffect(Teki&, int)
{
}

/**
 * @todo: Documentation
 */
void TekiStrategy::draw(Teki& teki, Graphics& gfx)
{
	teki.drawDefault(gfx);
}

/**
 * @todo: Documentation
 */
void TekiStrategy::drawDebugInfo(Teki& teki, Graphics& gfx)
{
	teki.drawTekiDebugInfoDefault(gfx);
}

/**
 * @todo: Documentation
 */
bool TekiStrategy::interact(Teki& teki, immut TekiInteractionKey& key)
{
	return teki.interactDefault(key);
}

/**
 * @todo: Documentation
 */
void TekiStrategy::spawnCorpseParts(Teki&)
{
}

/**
 * @todo: Documentation
 */
TekiStrategyTable::TekiStrategyTable(int count)
{
	mCount      = count;
	mStrategies = new TekiStrategy*[mCount];
	for (int i = 0; i < mCount; i++) {
		mStrategies[i] = nullptr;
	}
}
