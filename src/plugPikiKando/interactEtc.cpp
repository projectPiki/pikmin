#include "DebugLog.h"
#include "Interactions.h"
#include "Msg.h"
#include "Piki.h"
#include "PikiAI.h"
#include "PikiState.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("interactEtc")

/**
 * @TODO: Documentation
 */
bool InteractTalk::actPiki(Piki* piki) immut
{
	MsgTarget msg(mOwner);
	piki->mActiveAction->procMsg(&msg);
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractWarn::actPiki(Piki* piki) immut
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
