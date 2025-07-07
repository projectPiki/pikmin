#include "Actor.h"
#include "Age.h"
#include "DebugLog.h"
#include "Generator.h"
#include "sysNew.h"

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
DEFINE_PRINT("genActor");

/*
 * --INFO--
 * Address:	80119B30
 * Size:	000078
 */
static GenObject* makeObjectActor()
{
	return new GenObjectActor();
}

/*
 * --INFO--
 * Address:	80119BA8
 * Size:	00008C
 */
void GenObjectActor::initialise()
{
	GenObjectFactory::factory->registerMember('actr', &makeObjectActor, "create Actor", 'v0.0');
}

/*
 * --INFO--
 * Address:	80119C34
 * Size:	000040
 */
void GenObjectActor::doRead(RandomAccessStream& stream)
{
	mActorId = stream.readInt();
}

/*
 * --INFO--
 * Address:	80119C74
 * Size:	000070
 */
Creature* GenObjectActor::birth(BirthInfo& info)
{
	Actor* newActor = actorMgr->newActor(0);
	newActor->init(info.mPosition);
	newActor->startAI(0);
	return newActor;
}

#ifdef DEVELOP

void GenObjectActor::doGenAge(AgeServer& server)
{
	server.StartOptionBox("Actor", (int*)&mActorId, 252);
	server.NewOption("POLICE", 0);
	server.EndOptionBox();
}

#endif
