#include "types.h"
#include "MapCode.h"
#include "math.h"
#include "Collision.h"

/*
 * --INFO--
 * Address:	80116080
 * Size:	00000C
 */
u32 MapCode::getAttribute(CollTriInfo* triInfo) { return triInfo->mMapCode >> 29; };

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
char* MapCode::getAttributeName(int)
{
	// UNUSED FUNCTION
	return "UNUSED";
};

/*
 * --INFO--
 * Address:	8011608C
 * Size:	00001C
 */
u32 MapCode::getSlipCode(CollTriInfo* triInfo)
{
	if (triInfo) {
		return triInfo->mMapCode >> 27 & 3;
	} else {
		return 0;
	}
};

/*
 * --INFO--
 * Address:	801160A8
 * Size:	000068
 */
bool MapCode::isBald(CollTriInfo* triInfo)
{
	return (triInfo) ? (triInfo->_18.y < sinf(45 * PI / 180)) ? true : ((triInfo->mMapCode >> 25 & 1) != 0) ? false : true : true;
}
