#include "NaviMgr.h"
#include "MemStat.h"
#include "gameflow.h"
#include "Dolphin/os.h"
#include "PikiMacros.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "naviiMgr");
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

NaviMgr* naviMgr;

/*
 * --INFO--
 * Address:	801171C4
 * Size:	000180
 */
NaviMgr::NaviMgr()
{
	memStat->start("naviparms");
	mNaviParms = new NaviProp();
	load("parms/", "naviMgr.bin", 1);
	memStat->end("naviparms");

	memStat->start("navi shape anim");

	memStat->start("navi mtable");
	mMotionTable = PaniPikiAnimator::createMotionTable();
	memStat->end("navi mtable");

	memStat->start("navi shape");
	mNaviShape = gameflow.loadShape("pikis/nv3Model.mod", true);
	memStat->end("navi shape");

	memStat->start("navi shapeobject");
	mNaviShapeObject = new PikiShapeObject(mNaviShape);
	memStat->end("navi shapeobject");

	memStat->start("navi animmgr");
	mNaviShapeObject->mAnimMgr = PikiShapeObject::getAnimMgr();
	memStat->end("navi animmgr");

	mNaviID = 0;
	memStat->end("navi shape anim");
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NaviMgr::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80117344
 * Size:	000060
 */
Navi* NaviMgr::createObject()
{
	Navi* navi = new Navi(mNaviParms, mNaviID);
	mNaviID++;
	return navi;
}

/*
 * --INFO--
 * Address:	801173A4
 * Size:	000020
 */
void NaviMgr::update() { MonoObjectMgr::update(); }

/*
 * --INFO--
 * Address:	801173C4
 * Size:	000074
 */
Navi* NaviMgr::getNavi()
{
	u32 badCompiler[4];

	return static_cast<Navi*>(getCreatureCheck(getFirst()));
}

/*
 * --INFO--
 * Address:	80117438
 * Size:	000018
 */
Navi* NaviMgr::getNavi(int idx)
{
	if (idx >= _30) {
		DEBUGPRINT(idx >= 0);
	}
	return static_cast<Navi*>(_28[idx]);
}

/*
 * --INFO--
 * Address:	80117450
 * Size:	00011C
 */
void NaviMgr::refresh2d(Graphics& gfx)
{
	TRAVERSELOOP(this, idx) { getCreatureCheck(idx)->refresh2d(gfx); }
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  mr        r29, r4
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xA4

	.loc_0x38:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x5C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x74

	.loc_0x5C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  lwz       r12, 0x0(r3)
	  mr        r4, r29
	  lwz       r12, 0xF0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xA4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xCC
	  li        r0, 0x1
	  b         .loc_0xF8

	.loc_0xCC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xF4
	  li        r0, 0x1
	  b         .loc_0xF8

	.loc_0xF4:
	  li        r0, 0

	.loc_0xF8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x38
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011756C
 * Size:	000110
 */
void NaviMgr::renderCircle(Graphics& gfx)
{
	TRAVERSELOOP(this, idx) { static_cast<Navi*>(getCreatureCheck(idx))->renderCircle(gfx); }
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  mr        r29, r4
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x98

	.loc_0x38:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x5C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x74

	.loc_0x5C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  mr        r4, r29
	  bl        -0x18038
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x98:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC0
	  li        r0, 0x1
	  b         .loc_0xEC

	.loc_0xC0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xE8
	  li        r0, 0x1
	  b         .loc_0xEC

	.loc_0xE8:
	  li        r0, 0

	.loc_0xEC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x38
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011767C
 * Size:	00011C
 */
void NaviMgr::drawShadow(Graphics& gfx)
{
	TRAVERSELOOP(this, idx) { getCreatureCheck(idx)->drawShadow(gfx); }
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  mr        r29, r4
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xA4

	.loc_0x38:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x5C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x74

	.loc_0x5C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  lwz       r12, 0x0(r3)
	  mr        r4, r29
	  lwz       r12, 0xF8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xA4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xCC
	  li        r0, 0x1
	  b         .loc_0xF8

	.loc_0xCC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xF4
	  li        r0, 0x1
	  b         .loc_0xF8

	.loc_0xF4:
	  li        r0, 0

	.loc_0xF8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x38
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80117798
 * Size:	000030
 */
void NaviMgr::read(RandomAccessStream& input) { mNaviParms->read(input); }
