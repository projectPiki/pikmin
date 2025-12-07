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

/*
 * --INFO--
 * Address:	8014D1A4
 * Size:	000010
 */
TekiStrategy::TekiStrategy()
{
}

/*
 * --INFO--
 * Address:	8014D1B4
 * Size:	000004
 */
void TekiStrategy::start(Teki&)
{
}

/*
 * --INFO--
 * Address:	8014D1B8
 * Size:	000004
 */
void TekiStrategy::act(Teki&)
{
}

/*
 * --INFO--
 * Address:	8014D1BC
 * Size:	000004
 */
void TekiStrategy::eventPerformed(immut TekiEvent&)
{
}

/*
 * --INFO--
 * Address:	8014D1C0
 * Size:	000004
 */
void TekiStrategy::createEffect(Teki&, int)
{
}

/*
 * --INFO--
 * Address:	8014D1C4
 * Size:	000034
 */
void TekiStrategy::draw(Teki& teki, Graphics& gfx)
{
	teki.drawDefault(gfx);
}

/*
 * --INFO--
 * Address:	8014D1F8
 * Size:	000034
 */
void TekiStrategy::drawDebugInfo(Teki& teki, Graphics& gfx)
{
	teki.drawTekiDebugInfoDefault(gfx);
}

/*
 * --INFO--
 * Address:	8014D22C
 * Size:	000034
 */
bool TekiStrategy::interact(Teki& teki, immut TekiInteractionKey& key)
{
	return teki.interactDefault(key);
}

/*
 * --INFO--
 * Address:	8014D260
 * Size:	000004
 */
void TekiStrategy::spawnCorpseParts(Teki&)
{
}

/*
 * --INFO--
 * Address:	8014D264
 * Size:	00006C
 */
TekiStrategyTable::TekiStrategyTable(int count)
{
	mCount      = count;
	mStrategies = new TekiStrategy*[mCount];
	for (int i = 0; i < mCount; i++) {
		mStrategies[i] = nullptr;
	}
}
