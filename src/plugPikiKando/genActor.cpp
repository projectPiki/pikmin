#include "Generator.h"
#include "sysNew.h"
#include "Actor.h"
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
DEFINE_PRINT("genActor");

/*
 * --INFO--
 * Address:	80119B30
 * Size:	000078
 */
static GenObject* makeObjectActor() { return new GenObjectActor(); }

/*
 * --INFO--
 * Address:	80119BA8
 * Size:	00008C
 */
void GenObjectActor::initialise()
{
	GenObjectFactory* fact = GenObjectFactory::factory;
	if (fact->mSpawnerCount >= fact->mMaxSpawners) {
		return;
	}

	fact->mSpawnerInfo[fact->mSpawnerCount].mID          = 'actr';
	fact->mSpawnerInfo[fact->mSpawnerCount].mGenFunction = &makeObjectActor;
	fact->mSpawnerInfo[fact->mSpawnerCount].mName        = "create Actor";
	fact->mSpawnerInfo[fact->mSpawnerCount].mVersion     = 'v0.0';

	fact->mSpawnerCount++;
}

/*
 * --INFO--
 * Address:	80119C34
 * Size:	000040
 */
void GenObjectActor::doRead(RandomAccessStream& stream) { mActorId = stream.readInt(); }

/*
 * --INFO--
 * Address:	80119C74
 * Size:	000070
 */
void* GenObjectActor::birth(BirthInfo& info)
{
	Actor* newActor = actorMgr->newActor(0);
	newActor->init(info.mPosition);
	newActor->startAI(0);
	return newActor;
}
