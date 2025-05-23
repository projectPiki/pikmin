#include "Generator.h"
#include "DynSimulator.h"
#include "DynObject.h"
#include "MapMgr.h"
#include "sysNew.h"
#include "DebugLog.h"

MapMgr* GenObjectMapObject::mapMgr;

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
DEFINE_PRINT("genMapObject");

/*
 * --INFO--
 * Address:	8005D0E8
 * Size:	000040
 */
static GenObject* makeObjectMapObject()
{
	return new GenObjectMapObject;
}

/*
 * --INFO--
 * Address:	8005D128
 * Size:	000068
 */
GenObjectMapObject::GenObjectMapObject()
    : GenObject('mobj', "create MAP OBJECT")
{
	_18 = 0;
}

/*
 * --INFO--
 * Address:	8005D190
 * Size:	000090
 */
void GenObjectMapObject::initialise(MapMgr* mgr)
{
	mapMgr = mgr;
	GenObjectFactory::factory->registerMember('mobj', &makeObjectMapObject, "create MAP OBJECT", 'v0.0');
}

/*
 * --INFO--
 * Address:	8005D220
 * Size:	000040
 */
void GenObjectMapObject::doRead(RandomAccessStream& input)
{
	_18 = input.readInt();
}

/*
 * --INFO--
 * Address:	8005D260
 * Size:	000004
 */
void GenObjectMapObject::render(Graphics&, Generator*)
{
}

/*
 * --INFO--
 * Address:	8005D264
 * Size:	000008
 */
Creature* GenObjectMapObject::birth(BirthInfo&)
{
	Creature* obj = nullptr;
	if (obj) {
		// this doesn't generate assembly but it DOES generate weak functions.
		DynObjBridge* bridge = new DynObjBridge();
		RigidBody* body      = new RigidBody[2];
		bridge->readScript(mapMgr, "objects/mapobjs/faller.ini");
		bridge->initBodyCollisions();
		// some vector stuff here - i dont think it's enough to spawn Vector3f::set?
		bridge->mInitPosition.set(Vector3f(5.0f, 40.0f, 4.0f));
		mapMgr->mCollShape->add(bridge);
	}
	return obj;
}
