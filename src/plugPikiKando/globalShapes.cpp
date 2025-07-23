#include "DebugLog.h"
#include "GlobalShape.h"
#include "Shape.h"
#include "gameflow.h"

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
DEFINE_PRINT("globalShape");

Shape* GlobalShape::arrowShape;
Shape* GlobalShape::markerShape;
Shape* GlobalShape::axisShape;
Shape* GlobalShape::enShape;
Shape* GlobalShape::markerShape2;
Shape* GlobalShape::cursorShape;

void GlobalShape::exitCourse()
{
	arrowShape   = nullptr;
	markerShape  = nullptr;
	axisShape    = nullptr;
	enShape      = nullptr;
	markerShape2 = nullptr;
	cursorShape  = nullptr;
}

void GlobalShape::init()
{
	PRINT("* loading global shapes ...\n");
#ifdef DEVELOP
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
