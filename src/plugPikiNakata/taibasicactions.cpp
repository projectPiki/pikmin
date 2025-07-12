#include "DebugLog.h"
#include "Dolphin/os.h"
#include "PlayerState.h"
#include "TAI/BasicActions.h"
#include "teki.h"

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
DEFINE_PRINT("taibasicactions")

/*
 * --INFO--
 * Address:	801283A8
 * Size:	00000C
 */
void TaiActionStateAction::start(Teki& teki)
{
	teki.mActionStateId = 0;
}

/*
 * --INFO--
 * Address:	801283B4
 * Size:	000020
 */
bool TaiActionStateAction::act(Teki& teki)
{
	if (teki.mActionStateId == mActionState) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	801283D4
 * Size:	000060
 */
void TaiSetOptionAction::start(Teki& teki)
{
	if (mDoSet) {
		teki.setTekiOption(mOpt);
	} else {
		teki.clearTekiOption(mOpt);
	}
}

/*
 * --INFO--
 * Address:	80128434
 * Size:	000038
 */
void TaiPlaySoundAction::start(Teki& teki)
{
	teki.playSound(mSoundID);
}

/*
 * --INFO--
 * Address:	8012846C
 * Size:	000038
 */
void TaiStopSoundAction::start(Teki& teki)
{
	teki.stopSound(mSoundID);
}

/*
 * --INFO--
 * Address:	801284A4
 * Size:	000044
 */
void TaiTypeNaviWatchResultOnAction::start(Teki& teki)
{
	if (!teki.isCreatureFlag(CF_IsAICullingActive)) {
		int resFlag = tekiMgr->getResultFlag(teki.mTekiType);
		PRINT("TaiTypeNaviWatchResultOnAction::start:%08x:%d\n", &teki, resFlag);
		playerState->mResultFlags.setOn(resFlag);
	}
}

/*
 * --INFO--
 * Address:	801284E8
 * Size:	000038
 */
void TaiNaviWatchResultOnAction::start(Teki& teki)
{
	if (!teki.isCreatureFlag(CF_IsAICullingActive)) {
		playerState->mResultFlags.setOn(mResultFlag);
	}
}
