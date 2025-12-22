#include "CourseDebug.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Generator.h"
#include "sysNew.h"

int CourseDebug::collision;
int CourseDebug::pikiNoAttack;
int CourseDebug::noCarryover;
int CourseDebug::pelletDebug;

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
DEFINE_PRINT("courseDebug");

/*
 * --INFO--
 * Address:	........
 * Size:	00011C
 */
GenObjectDebug::GenObjectDebug()
    : GenObject('debg', "Debug Switches")
    , mCollision(this, 0, 0, 0, "p00", nullptr)
    , mPikiNoAttack(this, 0, 0, 0, "p01", nullptr)
    , mNoCarryover(this, 0, 0, 0, "p02", nullptr)
    , mPelletDebug(this, 0, 0, 0, "p03", nullptr)
{
}

/**
 * @TODO: Documentation
 */
static GenObject* makeObjectDebug()
{
	return new GenObjectDebug();
}

/**
 * @TODO: Documentation
 */
void GenObjectDebug::initialise()
{
	GenObjectFactory::factory->registerMember('debg', &makeObjectDebug, "Debug Switches", 'v0.0');
}

/**
 * @TODO: Documentation
 */
void GenObjectDebug::doRead(RandomAccessStream&)
{
}

/**
 * @TODO: Documentation
 */
Creature* GenObjectDebug::birth(BirthInfo&)
{
	CourseDebug::collision    = mCollision();
	CourseDebug::pikiNoAttack = mPikiNoAttack();
	CourseDebug::noCarryover  = mNoCarryover();
	CourseDebug::pelletDebug  = mPelletDebug();
	return nullptr;
}
