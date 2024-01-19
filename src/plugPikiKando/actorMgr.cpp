#include "Actor.h"

ActorMgr* actorMgr;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
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
void ActorMgr::createObject()
{
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
