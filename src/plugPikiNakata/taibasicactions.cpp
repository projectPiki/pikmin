#include "DebugLog.h"
#include "Dolphin/os.h"
#include "PlayerState.h"
#include "TAI/BasicActions.h"
#include "teki.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("taibasicactions")

/**
 * @todo: Documentation
 */
void TaiActionStateAction::start(Teki& teki)
{
	teki.mActionStateId = 0;
}

/**
 * @todo: Documentation
 */
bool TaiActionStateAction::act(Teki& teki)
{
	if (teki.mActionStateId == mActionState) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void TaiPlaySoundAction::start(Teki& teki)
{
	teki.playSound(mSoundID);
}

/**
 * @todo: Documentation
 */
void TaiStopSoundAction::start(Teki& teki)
{
	teki.stopSound(mSoundID);
}

/**
 * @todo: Documentation
 */
void TaiTypeNaviWatchResultOnAction::start(Teki& teki)
{
	if (!teki.isCreatureFlag(CF_UseAICulling)) {
		int resFlag = tekiMgr->getResultFlag(teki.mTekiType);
		PRINT_NAKATA("TaiTypeNaviWatchResultOnAction::start:%08x:%d\n", &teki, resFlag);
		playerState->mResultFlags.setOn(resFlag);
	}
}

/**
 * @todo: Documentation
 */
void TaiNaviWatchResultOnAction::start(Teki& teki)
{
	if (!teki.isCreatureFlag(CF_UseAICulling)) {
		playerState->mResultFlags.setOn(mResultFlag);
	}
}
