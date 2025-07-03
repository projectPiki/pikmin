#include "TAI/Aeffect.h"
#include "teki.h"
#include "MapMgr.h"
#include "RumbleMgr.h"
#include "MapCode.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(14)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("TAIAeffect")

const int TAIAeffCloudOfDust::RUMBLE_NONE = -1;

/*
 * --INFO--
 * Address:	801D5E50
 * Size:	0000B8
 */
void TAIAeffCloudOfDust::init(EffectMgr::effTypeTable effID, bool p2, int soundID, int rumbleType, f32 sinkThreshold, int footNum,
                              int jointID0, int jointID1, int jointID2, int jointID3)
{
	_20 = p2;
	if (footNum > 4) {
		PRINT("foot Max is %d", 4);
		ERROR("foot Max is %d", 4);
		return;
	}

	mEffectType        = effID;
	mSoundID           = soundID;
	mRumbleType        = rumbleType;
	mFootSinkThreshold = sinkThreshold;
	mFootNum           = footNum;
	mFootJointID       = new int[mFootNum];
	if (mFootNum > 0) {
		mFootJointID[0] = jointID0;
	}
	if (mFootNum > 1) {
		mFootJointID[1] = jointID1;
	}
	if (mFootNum > 2) {
		mFootJointID[2] = jointID2;
	}
	if (mFootNum > 3) {
		mFootJointID[3] = jointID3;
	}
}

/*
 * --INFO--
 * Address:	801D5F08
 * Size:	0000A0
 */
void TAIAeffCloudOfDust::start(Teki& teki)
{
	for (int i = 0; i < mFootNum; i++) {
		CollPart* foot = getCollPart(teki, mFootJointID[i]);
		if (foot) {
			teki.setFootPosY((YTeki::effFootIndexFlag)i, foot->mCentre.y);
			teki.setFootEffectSwitch((YTeki::effFootIndexFlag)i, true);
			teki.setMapCode(ATTR_NULL);
		}
	}
}

/*
 * --INFO--
 * Address:	801D5FA8
 * Size:	000068
 */
bool TAIAeffCloudOfDust::act(Teki& teki)
{
	for (int i = 0; i < mFootNum; i++) {
		createCloudOfDust(teki, i);
	}
	return false;
}

/*
 * --INFO--
 * Address:	801D6010
 * Size:	000040
 */
void TAIAeffCloudOfDust::setType(Vector3f& p1, int p2, int p3)
{
	p1.y = mapMgr->getMinY(p1.x, p1.z, true);
}

/*
 * --INFO--
 * Address:	801D6050
 * Size:	0001AC
 */
void TAIAeffCloudOfDust::createCloudOfDust(Teki& teki, int footIdx)
{
	CollPart* foot = getCollPart(teki, mFootJointID[footIdx]);
	if (!foot) {
		return;
	}

	f32 yDiff = foot->mCentre.y - teki.getFootPosY((YTeki::effFootIndexFlag)footIdx);

	if (teki.getFootEffectSwitch((YTeki::effFootIndexFlag)footIdx)) {
		if (foot->mCentre.y - foot->mRadius < mapMgr->getMinY(foot->mCentre.x, foot->mCentre.z, true)
		    && foot->mCentre.y - foot->mRadius < teki.getPosition().y && yDiff < mFootSinkThreshold) {
			CollTriInfo* tri = mapMgr->getCurrTri(foot->mCentre.x, foot->mCentre.z, true);
			if (tri) {
				int attr = MapCode::getAttribute(tri);
				Vector3f footPos(foot->mCentre);
				setType(footPos, attr, mFootJointID[footIdx]);
				if (mEffectType != EffectMgr::EFF_NULL) {
					effectMgr->create(mEffectType, footPos, nullptr, nullptr);
				}

				if (mSoundID != -1) {
					teki.playEventSound(&teki, mSoundID);
				}

				if (mRumbleType != -1) {
					rumbleMgr->start(mRumbleType, 0, footPos);
				}
				teki.setMapCode(attr);
				teki.setFootEffectSwitch((YTeki::effFootIndexFlag)footIdx, false);
			}
		}
	} else if (yDiff > 0.0f) {
		teki.setFootEffectSwitch((YTeki::effFootIndexFlag)footIdx, true);
	}

	teki.setFootPosY((YTeki::effFootIndexFlag)footIdx, foot->mCentre.y);
}

/*
 * --INFO--
 * Address:	801D61FC
 * Size:	000050
 */
CollPart* TAIAeffCloudOfDust::getCollPart(Teki& teki, int partID)
{
	CollPart* part = teki.mCollInfo->getSphere(partID);
	if (!part && _20) {
		PRINT("collPart [%c%c%c%c] is not found.\n", (partID & 0xFF000000) >> 24, (partID & 0xFF0000) >> 16, (partID & 0xFF00) >> 8,
		      partID & 0xFF);
		ERROR("collPart is not found.\n");
	}
	return part;
}
