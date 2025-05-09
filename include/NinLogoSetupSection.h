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
#include "Geometry.h"
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
		mMenu                            = 0;
		gameflow.mGamePrefs.mHasSaveGame = 1;
		gsys->setFade(1.0f, 3.0f);
	}

	virtual void update() // _10
	{
		mController->update();
		if (mMenu) {
			mMenu = mMenu->doUpdate(false);
			return;
		}

		if (progresWindow) {
			int windowStatus = progresWindow->update(mController);
			if (windowStatus == 1) {
				OSSetProgressiveMode(TRUE);
				gsys->mGfx->mRenderMode = 1;
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
			gsys->softReset();
		}
	}
	virtual void draw(Graphics& gfx) // _14
	{
		gfx.setViewport(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setScissor(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setClearColour(Colour(0, 0, 0, 0));
		gfx.clearBuffer(3, false);

		Matrix4f mtx;
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setColour(Colour(255, 255, 64, 255), true);
		gfx.setAuxColour(Colour(255, 0, 64, 255));

		if (mMenu) {
			drawMenu(gfx, mMenu, 1.0f);
		} else if (progresWindow) {
			progresWindow->draw(gfx);
		}

		gameflow.drawLoadLogo(gfx, false, gameflow.mLevelBannerTexture, gameflow.mLevelBannerFadeValue);

		// either this is a lot of inlines or there's a lot of debug stuff here.
		u32 badCompiler[64];
	}

	void drawMenu(Graphics& gfx, Menu* menu, f32 p3)
	{
		if (menu->mUseCustomPosition) {
			drawMenu(gfx, menu->mParentMenu, 0.5f * p3);
		}

		menu->draw(gfx, p3);
	}

	// _00     = VTBL
	// _00-_20 = Node
	u8 _20[0x28 - 0x20];     // _20, unknown
	Controller* mController; // _28
	Menu* mMenu;             // _2C
	u8 _30[0x50 - 0x30];     // _30, unknown
};

#endif
