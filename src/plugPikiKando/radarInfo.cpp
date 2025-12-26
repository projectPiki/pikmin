#include "RadarInfo.h"
#include "Creature.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Vector.h"
#include "sysNew.h"

RadarInfo* radarInfo;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("radarInfo");

/**
 * @todo: Documentation
 */
RadarInfo::RadarInfo()
{
	mAlivePartsList.initCore("alive");
	mDeadPartsList.initCore("dead ");
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
Vector3f RadarInfo::PartsInfo::getPos()
{
	if (mPart) {
		return mPart->mSRT.t;
	}

	Vector3f vec(0.0f, 0.0f, 0.0f); // this is necessary unfortunately
	return vec;
}
