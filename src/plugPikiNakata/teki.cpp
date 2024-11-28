#include "teki.h"
#include "TekiParameters.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80143BF0
 * Size:	000084
 */
Teki::Teki() { }

/*
 * --INFO--
 * Address:	80143C74
 * Size:	00008C
 */
void YTeki::init(int p1)
{
	BTeki::init(p1);
	_478    = 0.0f;
	_498[0] = 0;
	_498[1] = 0;
	_498[2] = 0;
	_498[3] = 0;
	_498[4] = 0;
	_498[5] = 0;
	_498[6] = 0;
	_498[7] = 0;

	for (int i = 8; i > 0; i++) {
		_498[i] = 0;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  bl        0xCA8
	  lfs       f0, -0x58B8(r2)
	  li        r3, 0
	  li        r5, 0x8
	  stfs      f0, 0x478(r31)
	  stw       r3, 0x498(r31)
	  stw       r3, 0x49C(r31)
	  stw       r3, 0x4A0(r31)
	  stw       r3, 0x4A4(r31)
	  stw       r3, 0x4A8(r31)
	  stw       r3, 0x4AC(r31)
	  stw       r3, 0x4B0(r31)
	  stw       r3, 0x4B4(r31)
	  b         .loc_0x6C

	.loc_0x4C:
	  subfic    r0, r5, 0x9
	  cmpwi     r5, 0x9
	  mtctr     r0
	  bge-      .loc_0x78

	.loc_0x5C:
	  stw       r3, 0x498(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x5C
	  b         .loc_0x78

	.loc_0x6C:
	  rlwinm    r0,r5,2,0,29
	  add       r4, r31, r0
	  b         .loc_0x4C

	.loc_0x78:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80143D00
 * Size:	000008
 */
void BTeki::setTekiOptions(int opts) { mTekiOptions = opts; }

/*
 * --INFO--
 * Address:	80143D08
 * Size:	00000C
 */
void BTeki::clearTekiOptions() { mTekiOptions = 0; }

/*
 * --INFO--
 * Address:	80143D14
 * Size:	000010
 */
void BTeki::setAnimationKeyOption(int opt) { mAnimKeyOptions |= opt; }

/*
 * --INFO--
 * Address:	80143D24
 * Size:	000010
 */
void BTeki::clearAnimationKeyOption(int opt) { mAnimKeyOptions &= ~opt; }

/*
 * --INFO--
 * Address:	80143D34
 * Size:	000008
 */
void BTeki::setAnimationKeyOptions(int opts) { mAnimKeyOptions = opts; }

/*
 * --INFO--
 * Address:	80143D3C
 * Size:	00000C
 */
void BTeki::clearAnimationKeyOptions() { mAnimKeyOptions = 0; }

/*
 * --INFO--
 * Address:	80143D48
 * Size:	000018
 */
f32 BTeki::getShadowSize() { return mTekiParams->getF(TPF_ShadowSize); }

/*
 * --INFO--
 * Address:	80143D60
 * Size:	00001C
 */
bool BTeki::isVisible() { return isTekiOption(TEKI_OPTION_VISIBLE) != 0; }

/*
 * --INFO--
 * Address:	80143D7C
 * Size:	00001C
 */
bool BTeki::isOrganic() { return isTekiOption(TEKI_OPTION_ORGANIC) != 0; }

/*
 * --INFO--
 * Address:	80143D98
 * Size:	00001C
 */
bool BTeki::isAtari() { return isTekiOption(TEKI_OPTION_ATARI) != 0; }

/*
 * --INFO--
 * Address:	80143DB4
 * Size:	00001C
 */
bool BTeki::isAlive() { return isTekiOption(TEKI_OPTION_ALIVE) != 0; }

/*
 * --INFO--
 * Address:	80143DD0
 * Size:	00001C
 */
bool BTeki::needShadow() { return isTekiOption(TEKI_OPTION_SHADOW_VISIBLE) != 0; }
