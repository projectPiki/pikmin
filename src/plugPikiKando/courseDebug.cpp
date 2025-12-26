#include "CourseDebug.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Generator.h"
#include "sysNew.h"

int CourseDebug::collision;
int CourseDebug::pikiNoAttack;
int CourseDebug::noCarryover;
int CourseDebug::pelletDebug;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("courseDebug");

/**
 * @todo: Documentation
 * @note UNUSED Size: 00011C
 */
GenObjectDebug::GenObjectDebug()
    : GenObject('debg', "Debug Switches")
    , mCollision(this, 0, 0, 0, "p00", "collision debug")
    , mPikiNoAttack(this, 0, 0, 0, "p01", "ピキの攻撃力を０にする")
    , mNoCarryover(this, 0, 0, 0, "p02", "ピキを次の面にもちこさない")
    , mPelletDebug(this, 0, 0, 0, "p03", "ペレットデバッグ")
{
}

/**
 * @todo: Documentation
 */
static GenObject* makeObjectDebug()
{
	return new GenObjectDebug();
}

/**
 * @todo: Documentation
 */
void GenObjectDebug::initialise()
{
	GenObjectFactory::factory->registerMember('debg', &makeObjectDebug, "Debug Switches", 'v0.0');
}

/**
 * @todo: Documentation
 */
void GenObjectDebug::doRead(RandomAccessStream&)
{
}

/**
 * @todo: Documentation
 */
Creature* GenObjectDebug::birth(BirthInfo&)
{
	CourseDebug::collision    = mCollision();
	CourseDebug::pikiNoAttack = mPikiNoAttack();
	CourseDebug::noCarryover  = mNoCarryover();
	CourseDebug::pelletDebug  = mPelletDebug();
	return nullptr;
}
