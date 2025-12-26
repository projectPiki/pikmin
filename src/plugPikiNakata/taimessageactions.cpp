#include "DebugLog.h"
#include "Dolphin/os.h"
#include "TAI/MessageActions.h"
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
DEFINE_PRINT("taimessageactions")

/**
 * @todo: Documentation
 */
void TaiSendMessageAction::start(Teki& teki)
{
	PRINT_NAKATA("TaiSendMessageAction::start:%08x:type:%d,id:%d\n", &teki, teki.mTekiType, mMessage);
	teki.sendMessage(mMessage);
}

/**
 * @todo: Documentation
 */
bool TaiKeySendMessageAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(mAnimKeyOpt)) {
		PRINT_NAKATA("TaiSendMessageAction::act:%08x:type:%d,id:%d\n", &teki, teki.mTekiType, mMessage);
		teki.sendMessage(mMessage);
	}
	return false;
}
