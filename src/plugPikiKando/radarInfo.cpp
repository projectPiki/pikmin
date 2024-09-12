#include "RadarInfo.h"
#include "Dolphin/os.h"
#include "sysNew.h"
#include "Creature.h"
#include "Vector.h"

RadarInfo* radarInfo;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "radarInfo");
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
 * Address:	8007B564
 * Size:	0000C8
 */
RadarInfo::RadarInfo()
{
	mAlivePartsList.initCore("alive");
	mDeadPartsList.initCore("dead ");
}

/*
 * --INFO--
 * Address:	8007B62C
 * Size:	0000E8
 */
void RadarInfo::attachParts(Creature* part)
{
	// check if part is already alive/attached
	FOREACH_NODE(PartsInfo, mAlivePartsList.mChild, aliveInfo)
	{
		if (aliveInfo->mPart == part) {
			// part is already attached, do nothing
			return;
		}
	}

	// take next part from detached list if there is one, otherwise make a new one
	PartsInfo* newInfo;
	if (mDeadPartsList.mChild) {
		newInfo = static_cast<PartsInfo*>(mDeadPartsList.mChild);
		newInfo->del();
	} else {
		PartsInfo* newInfo = new PartsInfo();
	}

	mAlivePartsList.add(newInfo);
	newInfo->mPart = part;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  mr        r29, r4
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r3, 0x10(r3)
	  b         .loc_0x3C

	.loc_0x2C:
	  lwz       r0, 0x14(r3)
	  cmplw     r0, r29
	  beq-      .loc_0xC8
	  lwz       r3, 0xC(r3)

	.loc_0x3C:
	  cmplwi    r3, 0
	  bne+      .loc_0x2C
	  lwz       r0, 0x28(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  mr        r30, r0
	  addi      r3, r30, 0
	  bl        -0x3B074
	  b         .loc_0xB8

	.loc_0x60:
	  li        r3, 0x18
	  bl        -0x3468C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xB8
	  lis       r4, 0x8022
	  addi      r0, r4, 0x738C
	  lis       r4, 0x8022
	  stw       r0, 0x0(r30)
	  addi      r0, r4, 0x737C
	  stw       r0, 0x0(r30)
	  li        r31, 0
	  lis       r4, 0x802B
	  stw       r31, 0x10(r30)
	  subi      r4, r4, 0x33DC
	  stw       r31, 0xC(r30)
	  stw       r31, 0x8(r30)
	  bl        -0x567FC
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3398
	  stw       r0, 0x0(r30)
	  stw       r31, 0x14(r30)

	.loc_0xB8:
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        -0x3B114
	  stw       r29, 0x14(r30)

	.loc_0xC8:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007B714
 * Size:	000070
 */
void RadarInfo::detachParts(Creature* part)
{
	// find part and detach it
	FOREACH_NODE(PartsInfo, mAlivePartsList.mChild, aliveInfo)
	{
		if (aliveInfo->mPart == part) {
			aliveInfo->del();
			mDeadPartsList.add(aliveInfo);
			aliveInfo->mPart = nullptr;
			return;
		}
	}
}

/*
 * --INFO--
 * Address:	8007B784
 * Size:	000044
 */
Vector3f RadarInfo::PartsInfo::getPos()
{
	if (mPart) {
		return mPart->mPosition;
	}

	Vector3f vec(0.0f, 0.0f, 0.0f); // this is necessary unfortunately
	return vec;
}
