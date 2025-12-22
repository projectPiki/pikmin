#include "Age.h"
#include "DebugLog.h"
#include "DynObject.h"
#include "DynSimulator.h"
#include "Generator.h"
#include "MapMgr.h"
#include "sysNew.h"

MapMgr* GenObjectMapObject::mapMgr;

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
DEFINE_PRINT("genMapObject");

/**
 * @TODO: Documentation
 */
static GenObject* makeObjectMapObject()
{
	return new GenObjectMapObject;
}

/**
 * @TODO: Documentation
 */
GenObjectMapObject::GenObjectMapObject()
    : GenObject('mobj', "create MAP OBJECT")
{
	mObjType = 0;
}

/**
 * @TODO: Documentation
 */
void GenObjectMapObject::initialise(MapMgr* mgr)
{
	mapMgr = mgr;
	GenObjectFactory::factory->registerMember('mobj', &makeObjectMapObject, "create MAP OBJECT", 'v0.0');
}

/**
 * @TODO: Documentation
 */
void GenObjectMapObject::doRead(RandomAccessStream& input)
{
	mObjType = input.readInt();
}

/**
 * @TODO: Documentation
 */
void GenObjectMapObject::render(Graphics&, Generator*)
{
}

/**
 * @TODO: Documentation
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

#ifdef WIN32

int numObjects = 8;

static char* objectNames[] = { "see-saw", "log", "tabaco", "faller", "iwa", "mini see-saw", "kinoko", "lift" };

void GenObjectMapObject::doGenAge(AgeServer& server)
{
	server.StartOptionBox("Map Object", (int*)&mObjType, 252);
	for (int i = 0; i < numObjects; i++) {
		server.NewOption(objectNames[i], i);
	}
	server.EndOptionBox();
}

void GenObjectMapObject::refreshSection(AgeServer& server)
{
	server.RefreshSection();
}

#endif
