#include "Actor.h"

ActorMgr* actorMgr;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
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

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
ActorMgr::ActorMgr(MapMgr*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
Creature* ActorMgr::createObject()
{
	return nullptr;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80119AB4
 * Size:	00007C
 */
Actor* ActorMgr::newActor(int p1)
{
	Actor* actor = (Actor*)birth();
	if (actor) {
		actor->setType(p1, _40[0], _44[0], _48[0]);
	}
	return actor;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
ActorMgr::~ActorMgr()
{
	// UNUSED FUNCTION
}
