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

/**
 * @TODO: Documentation
 */
TekiStrategy::TekiStrategy()
{
}

/**
 * @TODO: Documentation
 */
void TekiStrategy::start(Teki&)
{
}

/**
 * @TODO: Documentation
 */
void TekiStrategy::act(Teki&)
{
}

/**
 * @TODO: Documentation
 */
void TekiStrategy::eventPerformed(immut TekiEvent&)
{
}

/**
 * @TODO: Documentation
 */
void TekiStrategy::createEffect(Teki&, int)
{
}

/**
 * @TODO: Documentation
 */
void TekiStrategy::draw(Teki& teki, Graphics& gfx)
{
	teki.drawDefault(gfx);
}

/**
 * @TODO: Documentation
 */
void TekiStrategy::drawDebugInfo(Teki& teki, Graphics& gfx)
{
	teki.drawTekiDebugInfoDefault(gfx);
}

/**
 * @TODO: Documentation
 */
bool TekiStrategy::interact(Teki& teki, immut TekiInteractionKey& key)
{
	return teki.interactDefault(key);
}

/**
 * @TODO: Documentation
 */
void TekiStrategy::spawnCorpseParts(Teki&)
{
}

/**
 * @TODO: Documentation
 */
TekiStrategyTable::TekiStrategyTable(int count)
{
	mCount      = count;
	mStrategies = new TekiStrategy*[mCount];
	for (int i = 0; i < mCount; i++) {
		mStrategies[i] = nullptr;
	}
}
