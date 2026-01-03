#include "Controller.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Dolphin/vi.h"
#include "Geometry.h"
#include "Graphics.h"
#include "Menu.h"
#include "NinLogoSection.h"
#include "Section.h"
#include "gameflow.h"
#include "sysNew.h"
#include "types.h"
#include "zen/DrawProgre.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr);

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
		mController   = new Controller(1);
		progresWindow = nullptr;

#if defined(VERSION_GPIP01_00)
#else
		if ((VIGetDTVStatus() && OSGetProgressiveMode()) || (VIGetDTVStatus() && gsys->mControllerMgr.keyDown(KBBTN_DPAD_RIGHT))) {
			progresWindow = new zen::DrawProgre();
			progresWindow->start();
		}
#endif
		mMenu                            = nullptr;
		gameflow.mGamePrefs.mHasSaveGame = true;
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
				gsys->mDGXGfx->mRenderMode = 1;
				gsys->mDGXGfx->videoReset();
				progresWindow = nullptr;
				return;
			}
			if (windowStatus == 2) {
				OSSetProgressiveMode(FALSE);
				progresWindow = nullptr;
				return;
			}
		} else {
			gameflow.mNextGameSectionID = SECTION_Titles;
			gsys->softReset();
		}
	}
	virtual void draw(Graphics& gfx) // _14
	{
		gfx.setViewport(AREA_FULL_SCREEN(gfx));
		gfx.setScissor(AREA_FULL_SCREEN(gfx));
		gfx.setClearColour(COLOUR_TRANSPARENT);
		gfx.clearBuffer(3, false);

		Matrix4f mtx;
		gfx.setOrthogonal(mtx.mMtx, AREA_FULL_SCREEN(gfx));
		gfx.setColour(Colour(255, 255, 64, 255), true);
		gfx.setAuxColour(Colour(255, 0, 64, 255));

		if (mMenu) {
			drawMenu(gfx, mMenu, 1.0f);
		} else if (progresWindow) {
			progresWindow->draw(gfx);
		}

		gameflow.drawLoadLogo(gfx, false, gameflow.mLevelBannerTex, gameflow.mLevelBannerFadeValue);

		// either this is a lot of inlines or there's a lot of debug stuff here.
		STACK_PAD_VAR(64);
	}

	void drawMenu(Graphics& gfx, Menu* menu, f32 p3)
	{
		if (menu->mAlignToParentItem) {
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

/**
 * @todo: Documentation
 */
void NinLogoSection::init()
{
	Node::init("<NinLogoSection>");
	gsys->mTimerState = TS_Off;
	add(new NinLogoSetupSection());
}
