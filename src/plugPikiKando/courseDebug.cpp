#include "Generator.h"
#include "CourseDebug.h"
#include "Dolphin/os.h"
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
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "courseDebug");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

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
static GenObjectDebug* makeObjectDebug() { return new GenObjectDebug; }

/*
 * --INFO--
 * Address:	800865D4
 * Size:	00008C
 */
void GenObjectDebug::initialise()
{
	/*
	.loc_0x0:
	  lwz       r7, 0x3074(r13)
	  lwz       r5, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  cmpw      r5, r0
	  bgelr-
	  lis       r4, 0x6465
	  lwz       r3, 0x8(r7)
	  addi      r4, r4, 0x6267
	  rlwinm    r0,r5,4,0,27
	  stwx      r4, r3, r0
	  lis       r6, 0x8008
	  lis       r4, 0x802B
	  lwz       r0, 0x0(r7)
	  lis       r3, 0x7630
	  lwz       r5, 0x8(r7)
	  addi      r6, r6, 0x64A8
	  rlwinm    r0,r0,4,0,27
	  add       r5, r5, r0
	  stw       r6, 0x4(r5)
	  subi      r5, r4, 0x11A0
	  addi      r4, r3, 0x2E30
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r5, 0x8(r3)
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r4, 0xC(r3)
	  lwz       r3, 0x0(r7)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r7)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80086660
 * Size:	000004
 */
void GenObjectDebug::doRead(RandomAccessStream&) { }

/*
 * --INFO--
 * Address:	80086664
 * Size:	000028
 */
void* GenObjectDebug::birth(BirthInfo&)
{
	CourseDebug::collision    = mCollision();
	CourseDebug::pikiNoAttack = mPikiNoAttack();
	CourseDebug::noCarryover  = mNoCarryover();
	CourseDebug::pelletDebug  = mPelletDebug();

	return nullptr;
}

/*
 * --INFO--
 * Address:	8008668C
 * Size:	000004
 */
void GenObject::render(Graphics&, Generator*) { }
