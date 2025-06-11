#include "gameflow.h"
#include "GlobalShape.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

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
	PRINT("* loading global shapes ...\n");
#if 0 // DLL only:
	arrowShape = gameflow.loadShape("shapes/arrow.mod", true);
	arrowShape->removeMtxDependancy();
	markerShape = gameflow.loadShape("shapes/oldMarkr.mod", true);
	markerShape->removeMtxDependancy();
	axisShape = gameflow.loadShape("shapes/axis.mod", true);
	axisShape->removeMtxDependancy();
	enShape = gameflow.loadShape("shapes/en.mod", true);
	enShape->removeMtxDependancy();
#endif
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
	PRINT("* done\n");
}
} // namespace GlobalShape
