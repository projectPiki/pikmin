#include "Interactions.h"
#include "Msg.h"
#include "Piki.h"
#include "PikiAI.h"
#include "PikiState.h"

static char file[] = __FILE__;
static char name[] = "interactEtc";

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
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
 * Address:	8007C9F8
 * Size:	00003C
 */
bool InteractTalk::actPiki(Piki* piki)
{
	MsgTarget msg(mOwner);
	piki->_4F8->procMsg(&msg);
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

	if (piki->isKinoko() || !piki->_409 || piki->_4FC == 1) {
		return false;
	}

	if (state == PIKISTATE_Swallowed || state == PIKISTATE_Drown || state == PIKISTATE_LookAt || state == PIKISTATE_Pressed) {
		return false;
	}

	if (piki->_2B4 == 0 && state != PIKISTATE_Flick) {
		piki->mFSM->transit(piki, PIKISTATE_LookAt);

	} else {
		piki->_4A0 = 1;
	}

	return true;
}
