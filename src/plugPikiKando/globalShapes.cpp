#include "types.h"
#include "gameflow.h"

static char file[] = __FILE__;
static char name[] = "globalShape";

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
