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

void TaiActionStateAction::start(Teki& teki)
{
	teki.mActionStateId = 0;
}

bool TaiActionStateAction::act(Teki& teki)
{
	if (teki.mActionStateId == mActionState) {
		return true;
	}
	return false;
}

void TaiSetOptionAction::start(Teki& teki)
{
	if (mDoSet) {
		teki.setTekiOption(mOpt);
	} else {
		teki.clearTekiOption(mOpt);
	}
}

void TaiPlaySoundAction::start(Teki& teki)
{
	teki.playSound(mSoundID);
}

void TaiStopSoundAction::start(Teki& teki)
{
	teki.stopSound(mSoundID);
}

void TaiTypeNaviWatchResultOnAction::start(Teki& teki)
{
	if (!teki.isCreatureFlag(CF_IsAICullingActive)) {
		int resFlag = tekiMgr->getResultFlag(teki.mTekiType);
		PRINT_NAKATA("TaiTypeNaviWatchResultOnAction::start:%08x:%d\n", &teki, resFlag);
		playerState->mResultFlags.setOn(resFlag);
	}
}

void TaiNaviWatchResultOnAction::start(Teki& teki)
{
	if (!teki.isCreatureFlag(CF_IsAICullingActive)) {
		playerState->mResultFlags.setOn(mResultFlag);
	}
}
