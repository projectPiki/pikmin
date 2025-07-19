#include "DebugLog.h"
#include "Dolphin/os.h"
#include "TAI/MessageActions.h"
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
DEFINE_PRINT("taimessageactions")

/*
 * --INFO--
 * Address:	80131EF8
 * Size:	00002C
 */
void TaiSendMessageAction::start(Teki& teki)
{
	PRINT_NAKATA("TaiSendMessageAction::start:%08x:type:%d,id:%d\n", &teki, teki.mTekiType, mMessage);
	teki.sendMessage(mMessage);
}

/*
 * --INFO--
 * Address:	80131F24
 * Size:	000040
 */
bool TaiKeySendMessageAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(mAnimKeyOpt)) {
		PRINT_NAKATA("TaiSendMessageAction::act:%08x:type:%d,id:%d\n", &teki, teki.mTekiType, mMessage);
		teki.sendMessage(mMessage);
	}
	return false;
}
