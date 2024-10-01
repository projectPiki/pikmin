#include "TAI/MessageActions.h"
#include "Dolphin/os.h"
#include "teki.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "taimessageactions");
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
 * Address:	80131EF8
 * Size:	00002C
 */
void TaiSendMessageAction::start(Teki& teki) { teki.sendMessage(_08); }

/*
 * --INFO--
 * Address:	80131F24
 * Size:	000040
 */
bool TaiKeySendMessageAction::act(Teki& teki)
{
	if (teki.isAnimKeyOption(mAnimKeyOpt)) {
		teki.sendMessage(_08);
	}
	return false;
}
