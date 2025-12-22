#include "zen/MenuPanelMgr.h"
#include "DebugLog.h"
#include "sysNew.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("menuPanelMgr")

/**
 * @TODO: Documentation
 */
void zen::MenuPanelMgr::setCallBack(P2DScreen* screen, P2DPane* parent)
{
	int i;
	P2DPane* pane;
	P2DPane* centPane = screen->search('cent', true);
	P2DPaneLibrary::changeParent(centPane, parent);
	i = 0;
	char buf[8];
	sprintf(buf, "p%03d", 0);
	while (pane = screen->search(P2DPaneLibrary::makeTag(buf), false)) {
		P2DPaneLibrary::changeParent(pane, parent);
		pane->setCallBack(new MenuPanel(pane, centPane, this));
		sprintf(buf, "p%03d", ++i);
	}
}

/**
 * @TODO: Documentation
 */
bool zen::MenuPanelMgr::update()
{
	bool res;
	switch (mState) {
	case STATE_Start:
	case STATE_End:
		f32 v = mTimer += gsys->getFrameTime();
		if (v > mDuration) {
			mTimer = mDuration;
			res    = true;
		} else {
			res = false;
		}
		break;

	default:
		res = true;
		break;
	}

	updateRatio();
	return res;
}

/**
 * @TODO: Documentation
 */
bool zen::MenuPanelMgr::checkFinish()
{
	bool res = false;
	switch (mState) {
	case STATE_Start:
	case STATE_End:
		if (mTimer >= mDuration) {
			res = true;
		}
		break;

	default:
		res = true;
		break;
	}

	return res;
}
