#include "gameflow.h"
#include "GlobalShape.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("globalShape");

namespace GlobalShape {

Shape* arrowShape;
Shape* markerShape;
Shape* axisShape;
Shape* enShape;
Shape* markerShape2;
Shape* cursorShape;

void exitCourse()
{
	arrowShape   = nullptr;
	markerShape  = nullptr;
	axisShape    = nullptr;
	enShape      = nullptr;
	markerShape2 = nullptr;
	cursorShape  = nullptr;
}

void init()
{
	markerShape2 = gameflow.loadShape("shapes/cursor/marker.mod", true);
	cursorShape  = gameflow.loadShape("shapes/cursor/cursor.mod", true);
	gameflow.loadShape("pikis/happas/leaf.mod", true);
	gameflow.loadShape("pikis/happas/leaf.mod", true);
	gameflow.loadShape("pikis/happas/leaf.mod", true);
	gameflow.loadShape("pikis/happas/bud.mod", true);
	gameflow.loadShape("pikis/happas/flower.mod", true);
	gameflow.loadShape("pikis/happas/leaf.mod", true);
	gameflow.loadShape("pikis/happas/leaf.mod", true);
	gameflow.loadShape("pikis/happas/leaf.mod", true);
}
} // namespace GlobalShape
