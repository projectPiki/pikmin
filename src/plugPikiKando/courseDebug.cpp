#include "Generator.h"
#include "CourseDebug.h"
#include "Dolphin/os.h"
#include "sysNew.h"
#include "DebugLog.h"

int CourseDebug::collision;
int CourseDebug::pikiNoAttack;
int CourseDebug::noCarryover;
int CourseDebug::pelletDebug;

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

/*
 * --INFO--
 * Address:	800864A8
 * Size:	00012C
 */
static GenObject* makeObjectDebug()
{
	return new GenObjectDebug();
}

/*
 * --INFO--
 * Address:	800865D4
 * Size:	00008C
 */
void GenObjectDebug::initialise()
{
	GenObjectFactory::factory->registerMember('debg', &makeObjectDebug, "Debug Switches", 'v0.0');
}

/*
 * --INFO--
 * Address:	80086660
 * Size:	000004
 */
void GenObjectDebug::doRead(RandomAccessStream&)
{
}

/*
 * --INFO--
 * Address:	80086664
 * Size:	000028
 */
Creature* GenObjectDebug::birth(BirthInfo&)
{
	CourseDebug::collision    = mCollision();
	CourseDebug::pikiNoAttack = mPikiNoAttack();
	CourseDebug::noCarryover  = mNoCarryover();
	CourseDebug::pelletDebug  = mPelletDebug();
	return nullptr;
}
