#include "MapCode.h"

#include "Collision.h"
#include "math.h"

/*
 * --INFO--
 * Address:	80116080
 * Size:	00000C
 */
int MapCode::getAttribute(CollTriInfo* triInfo)
{
	return triInfo->mMapCode >> 29;
};

// I'm not sure how this was originally coded, but when this array was stripped I think it bloated the .sdata2 of this TU.
static char* mapcodeNames[] = {
	"solid", "rock", "grass", "wood", "mud", "water", "hole",
};

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
char* MapCode::getAttributeName(int num)
{
	// UNUSED FUNCTION (matching by size)
	return mapcodeNames[num];
};

/*
 * --INFO--
 * Address:	8011608C
 * Size:	00001C
 */
int MapCode::getSlipCode(CollTriInfo* triInfo)
{
	if (triInfo) {
		return triInfo->mMapCode >> 27 & 3;
	}
	return 0;
};

/*
 * --INFO--
 * Address:	801160A8
 * Size:	000068
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
