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

/**
 * @TODO: Documentation
 */
static GenObject* makeObjectActor()
{
	return new GenObjectActor();
}

/**
 * @TODO: Documentation
 */
void GenObjectActor::initialise()
{
	GenObjectFactory::factory->registerMember('actr', &makeObjectActor, "create Actor", 'v0.0');
}

/**
 * @TODO: Documentation
 */
void GenObjectActor::doRead(RandomAccessStream& stream)
{
	mActorId = stream.readInt();
}

/**
 * @TODO: Documentation
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
