#include "RadarInfo.h"
#include "Dolphin/os.h"
#include "sysNew.h"
#include "Creature.h"
#include "Vector.h"
#include "DebugLog.h"

RadarInfo* radarInfo;

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
DEFINE_PRINT("radarInfo");

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
			PRINT("try to attach twice !\n");
			return;
		}
	}

	// take next part from detached list if there is one, otherwise make a new one
	PartsInfo* newInfo;
	if (mDeadPartsList.mChild) {
		newInfo = static_cast<PartsInfo*>(mDeadPartsList.mChild);
		newInfo->del();
	} else {
		newInfo = new PartsInfo();
	}

	mAlivePartsList.add(newInfo);
	newInfo->mPart = part;
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
