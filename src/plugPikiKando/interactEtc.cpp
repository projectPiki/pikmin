#include "DebugLog.h"
#include "Interactions.h"
#include "Msg.h"
#include "Piki.h"
#include "PikiAI.h"
#include "PikiState.h"

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
DEFINE_PRINT("interactEtc")

/*
 * --INFO--
 * Address:	8007C9F8
 * Size:	00003C
 */
bool InteractTalk::actPiki(Piki* piki)
{
	MsgTarget msg(mOwner);
	piki->mActiveAction->procMsg(&msg);
	return true;
}

/*
 * --INFO--
 * Address:	8007CA34
 * Size:	000104
 */
bool InteractWarn::actPiki(Piki* piki)
{
	int state = piki->getState();
	if (!piki->isAlive()) {
		return false;
	}

	if (piki->isKinoko() || !piki->mIsCallable || piki->mMode == 1) {
		return false;
	}

	if (state == PIKISTATE_Swallowed || state == PIKISTATE_Drown || state == PIKISTATE_LookAt || state == PIKISTATE_Pressed) {
		return false;
	}

	if (!piki->mIsBeingDamaged && state != PIKISTATE_Flick) {
		piki->mFSM->transit(piki, PIKISTATE_LookAt);

	} else {
		piki->mIsWhistlePending = true;
	}

	return true;
}
