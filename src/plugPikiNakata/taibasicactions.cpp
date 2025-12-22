#include "DebugLog.h"
#include "Dolphin/os.h"
#include "PlayerState.h"
#include "TAI/BasicActions.h"
#include "teki.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("taibasicactions")

/**
 * @TODO: Documentation
 */
void TaiActionStateAction::start(Teki& teki)
{
	teki.mActionStateId = 0;
}

/**
 * @TODO: Documentation
 */
bool TaiActionStateAction::act(Teki& teki)
{
	if (teki.mActionStateId == mActionState) {
		return true;
	}
	return false;
}

/**
 * @TODO: Documentation
 */
void TaiSetOptionAction::start(Teki& teki)
{
	if (mDoSet) {
		teki.setTekiOption(mOpt);
	} else {
		teki.clearTekiOption(mOpt);
	}
}

/**
 * @TODO: Documentation
 */
void TaiPlaySoundAction::start(Teki& teki)
{
	teki.playSound(mSoundID);
}

/**
 * @TODO: Documentation
 */
void TaiStopSoundAction::start(Teki& teki)
{
	teki.stopSound(mSoundID);
}

/**
 * @TODO: Documentation
 */
void TaiTypeNaviWatchResultOnAction::start(Teki& teki)
{
	if (!teki.isCreatureFlag(CF_IsAICullingActive)) {
		int resFlag = tekiMgr->getResultFlag(teki.mTekiType);
		PRINT_NAKATA("TaiTypeNaviWatchResultOnAction::start:%08x:%d\n", &teki, resFlag);
		playerState->mResultFlags.setOn(resFlag);
	}
}

/**
 * @TODO: Documentation
 */
void TaiNaviWatchResultOnAction::start(Teki& teki)
{
	if (!teki.isCreatureFlag(CF_IsAICullingActive)) {
		playerState->mResultFlags.setOn(mResultFlag);
	}
}
