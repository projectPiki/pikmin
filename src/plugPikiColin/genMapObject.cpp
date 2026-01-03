#include "Generator.h"

#include "Age.h"
#include "DebugLog.h"
#include "DynObject.h"
#include "DynSimulator.h"
#include "MapMgr.h"
#include "sysNew.h"

/// Pointer to active map manager to use when initialising objects.
MapMgr* GenObjectMapObject::mapMgr;

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("genMapObject");

/**
 * @brief Instantiates a map object spawner. Used by the `GenObjectFactory` to create map object spawners.
 *
 * @return Pointer to newly created `GenObjectMapObject`.
 */
static GenObject* makeObjectMapObject()
{
	return new GenObjectMapObject;
}

/**
 * @brief Constructs a map object spawner. Assigned as a see-saw type by default.
 */
GenObjectMapObject::GenObjectMapObject()
    : GenObject('mobj', "create MAP OBJECT")
{
	mObjType = TYPE_SeeSaw;
}

/**
 * @brief Registers the `GenObjectMapObject` spawner type with the `GenObjectFactory`.
 *
 * @param mgr Active map manager to assign and use when birthing map objects.
 */
void GenObjectMapObject::initialise(MapMgr* mgr)
{
	mapMgr = mgr;
	GenObjectFactory::factory->registerMember('mobj', &makeObjectMapObject, "create MAP OBJECT", 'v0.0');
}

/**
 * @brief Reads spawner object type from file - see `MapObjectType` enum.
 *
 * @param input File stream to read from.
 */
void GenObjectMapObject::doRead(RandomAccessStream& input)
{
	mObjType = input.readInt();
}

#ifdef WIN32

void GenObjectMapObject::doWrite(RandomAccessStream& output)
{
	output.writeInt(mObjType);
}

int numObjects = 8;

static char* objectNames[] = { "see-saw", "log", "tabaco", "faller", "iwa", "mini see-saw", "kinoko", "lift" };

void GenObjectMapObject::refreshSection(AgeServer& server)
{
	server.RefreshSection();
}

void GenObjectMapObject::doGenAge(AgeServer& server)
{
	server.StartOptionBox("Map Object", (int*)&mObjType, 252);
	for (int i = 0; i < numObjects; i++) {
		server.NewOption(objectNames[i], i);
	}
	server.EndOptionBox();
}

#endif

/**
 * @brief Renders any debug information about the spawner - nothing to render in this case.
 */
void GenObjectMapObject::render(Graphics&, Generator*)
{
}

/**
 * @brief Does nothing (not fully finished).
 *
 * Expected behaviour would be to birth a map object of the saved type, but these types seem to have never been finished.
 * The stripped if code is required to spawn some weak functions, and is somewhat exposed in the DLL, but clearly unfinished.
 *
 * @return `nullptr` always.
 */
Creature* GenObjectMapObject::birth(BirthInfo& birthInfo)
{
	return nullptr;

	for (int i = 0; i < 10; i++) {
		// this doesn't generate assembly in the DOL due to the early return but it DOES generate weak functions
		// (it also generates assembly in the DLL, which is where this is drawn from)
		DynObjBridge* bridge = new DynObjBridge();

		bridge->mStaticEnvironmentShape = mapMgr->mMapShape;
		bridge->readScript(mapMgr, "objects/mapobjs/faller.ini");
		bridge->initBodyCollisions();
		bridge->mInitPosition.set(
		    Vector3f(birthInfo.mPosition.z + 4.0f + 40.0f * f32(i), birthInfo.mPosition.y - 5.0f, birthInfo.mPosition.x));
		bridge->mInitOrientationX = Vector3f(0.0f, 0.0f, 1.0f);
		bridge->mInitOrientationY = Vector3f(0.0f, 1.0f, 0.0f);
		bridge->mInitOrientationZ = Vector3f(1.0f, 0.0f, 0.0f);
		mapMgr->mDynSimulator->add(bridge);
		mapMgr->mCollShape->add(bridge->mCollObj);
	}

	// this is purely a fix to get the RigidBody ctor to spawn in this file, and isn't part of the DLL or DOL code.
#ifdef BUILD_MATCHING
	RigidBody* body = new RigidBody[2];
#endif

	return nullptr;
}
