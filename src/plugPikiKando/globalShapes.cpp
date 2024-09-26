#include "gameflow.h"
#include "Dolphin/os.h"
#include "GlobalShape.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "globalShape");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

namespace GlobalShape {

void* arrowShape;
void* markerShape;
void* axisShape;
void* enShape;
void* markerShape2;
void* cursorShape;

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
