#ifndef _NINLOGOSETUPSECTION_H
#define _NINLOGOSETUPSECTION_H

#include "types.h"
#include "Section.h"
#include "Controller.h"
#include "zen/DrawProgre.h"
#include "Dolphin/vi.h"
#include "Dolphin/os.h"
#include "gameflow.h"
#include "Graphics.h"
#include "Menu.h"
#include "sysNew.h"

struct Menu;

// WARNING: DO NOT INCLUDE THIS HEADER OTHER THAN IN NINLOGO.CPP
static zen::DrawProgre* progresWindow;

/**
 * @brief TODO
 *
 * @note Size: 0x50.
 */
struct NinLogoSetupSection : public Node {
	inline NinLogoSetupSection()
	{
		setName("NinLogo section");
		mController   = new Controller();
		progresWindow = nullptr;

		if ((VIGetDTVStatus() && OSGetProgressiveMode()) || (VIGetDTVStatus() && gsys->mControllerMgr.keyDown(KBBTN_DPAD_RIGHT))) {
			progresWindow = new zen::DrawProgre();
			progresWindow->start();
		}
		_2C                     = 0;
		gameflow.mGamePrefs._1E = 1;
		gsys->setFade(1.0f, 3.0f);
	}

	virtual void update() // _10
	{
		mController->update();
		if (_2C) {
			_2C = _2C->doUpdate(false);
			return;
		}

		if (progresWindow) {
			int windowStatus = progresWindow->update(mController);
			if (windowStatus == 1) {
				OSSetProgressiveMode(TRUE);
				gsys->mGfx->_00 = 1;
				gsys->mGfx->videoReset();
				progresWindow = nullptr;
				return;
			}
			if (windowStatus == 2) {
				OSSetProgressiveMode(FALSE);
				progresWindow = nullptr;
				return;
			}
		} else {
			gameflow.mGameSectionID = SECTION_Titles;
			gsys->mPending          = true;
		}
	}
	virtual void draw(Graphics&); // _14

	void drawMenu(Graphics&, Menu*, f32);

	// _00     = VTBL
	// _00-_20 = Node
	u8 _20[0x28 - 0x20];     // _20, unknown
	Controller* mController; // _28
	Menu* _2C;               // _2C
	u8 _30[0x50 - 0x30];     // _30, unknown
};

#endif
