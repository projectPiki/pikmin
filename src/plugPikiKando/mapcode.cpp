#include "MapCode.h"

#include "Collision.h"
#include <math.h>

/**
 * @TODO: Documentation
 */
int MapCode::getAttribute(CollTriInfo* triInfo)
{
	return triInfo->mMapCode >> 29;
};

// I'm not sure how this was originally coded, but when this array was stripped I think it bloated the .sdata2 of this TU.
static immut char* mapcodeNames[] = {
	"solid", "rock", "grass", "wood", "mud", "water", "hole",
};

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000018
 */
immut char* MapCode::getAttributeName(int num)
{
	// UNUSED FUNCTION (matching by size)
	return mapcodeNames[num];
};

/**
 * @TODO: Documentation
 */
int MapCode::getSlipCode(CollTriInfo* triInfo)
{
	if (triInfo) {
		return triInfo->mMapCode >> 27 & 3;
	}
	return 0;
};

/**
 * @TODO: Documentation
 */
bool MapCode::isBald(CollTriInfo* triInfo)
{
	if (triInfo) {
		if (triInfo->mTriangle.mNormal.y < sinf(45 * PI / 180)) {
			return true;
		}
		if (triInfo->mMapCode >> 25 & 1) {
			return false;
		}
		return true;
	}
	return true;
}
