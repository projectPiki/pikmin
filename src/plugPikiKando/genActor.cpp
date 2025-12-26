#include "Actor.h"
#include "Age.h"
#include "DebugLog.h"
#include "Generator.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("genActor");

/**
 * @todo: Documentation
 */
static GenObject* makeObjectActor()
{
	return new GenObjectActor();
}

/**
 * @todo: Documentation
 */
void GenObjectActor::initialise()
{
	GenObjectFactory::factory->registerMember('actr', &makeObjectActor, "create Actor", 'v0.0');
}

/**
 * @todo: Documentation
 */
void GenObjectActor::doRead(RandomAccessStream& stream)
{
	mActorId = stream.readInt();
}

/**
 * @todo: Documentation
 */
Creature* GenObjectActor::birth(BirthInfo& info)
{
	Actor* newActor = actorMgr->newActor(0);
	newActor->init(info.mPosition);
	newActor->startAI(0);
	return newActor;
}

#ifdef WIN32

void GenObjectActor::doGenAge(AgeServer& server)
{
	server.StartOptionBox("Actor", (int*)&mActorId, 252);
	server.NewOption("POLICE", 0);
	server.EndOptionBox();
}

#endif
