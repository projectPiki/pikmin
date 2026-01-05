#include "NinLogoSection.h"

#include "Controller.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Dolphin/vi.h"
#include "Geometry.h"
#include "Graphics.h"
#include "Menu.h"
#include "Section.h"
#include "gameflow.h"
#include "sysNew.h"
#include "types.h"
#include "zen/DrawProgre.h"

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr);

/// "Would you like to display in Progressive Scan mode?" screen.
static zen::DrawProgre* progresWindow;

/**
 * @brief Inner control game section for the boot-up screen, which does more of the labour than its parent `NinLogoSection`.
 *
 * Controls the progressive mode option screen, if required, and sets up while the Nintendo logo is displayed.
 * (It doesn't start the logo, but it does keep it displayed while the progressive scan choice screen is open.)
 *
 * @note Size: 0x50.
 */
struct NinLogoSetupSection : public Node {

	/// Constructs a new control section for progressive scan mode choice.
	NinLogoSetupSection()
	{
		setName("NinLogo section");
		mController   = new Controller(1);
		progresWindow = nullptr;

#if defined(VERSION_GPIP01_00)
		// no progressive mode for PAL
#else
		if ((VIGetDTVStatus() && OSGetProgressiveMode()) || (VIGetDTVStatus() && gsys->mControllerMgr.keyDown(KBBTN_DPAD_RIGHT))) {
			progresWindow = new zen::DrawProgre();
			progresWindow->start();
		}
#endif
		mActiveDebugMenu                 = nullptr;
		gameflow.mGamePrefs.mHasSaveGame = true;
		gsys->setFade(1.0f);
	}

	/// Updates the current frame of boot-up, handling progressive scan choice and transiting to the title screen.
	virtual void update() // _10
	{
		mController->update();

		// there is no debug menu that could exist here, but update it just in case
		if (mActiveDebugMenu) {
			mActiveDebugMenu = mActiveDebugMenu->doUpdate(false);
			return;
		}

		// handle progressive scan mode choice window
		if (progresWindow) {
			zen::DrawProgre::returnStatusFlag scanMode = progresWindow->update(mController);
			if (scanMode == zen::DrawProgre::RETSTATE_Progressive) {
				OSSetProgressiveMode(TRUE);
				gsys->mDGXGfx->mRenderMode = 1;
				gsys->mDGXGfx->videoReset();
				progresWindow = nullptr;
				return;
			}
			if (scanMode == zen::DrawProgre::RETSTATE_Interlaced) {
				OSSetProgressiveMode(FALSE);
				progresWindow = nullptr;
				return;
			}
		} else {
			// transit to title once progressive mode window is complete
			gameflow.mNextGameSectionID = SECTION_Titles;
			gsys->softReset();
		}
	}

	/**
	 * @brief Renders the current frame of boot-up, mostly handling the progressive scan mode screen.
	 * @param gfx Graphics context for rendering.
	 */
	virtual void draw(Graphics& gfx) // _14
	{
		gfx.setViewport(AREA_FULL_SCREEN(gfx));
		gfx.setScissor(AREA_FULL_SCREEN(gfx));
		gfx.setClearColour(COLOUR_TRANSPARENT);
		gfx.clearBuffer(3, false);

		// draw debug menu or progressive scan choice screen full-screen
		Matrix4f orthoMtx;
		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
		gfx.setColour(Colour(255, 255, 64, 255), true);
		gfx.setAuxColour(Colour(255, 0, 64, 255));

		if (mActiveDebugMenu) {
			drawMenu(gfx, mActiveDebugMenu, 1.0f);
		} else if (progresWindow) {
			progresWindow->draw(gfx);
		}

		// keep Nintendo logo open while progressive scan mode choice is going
		gameflow.drawLoadLogo(gfx, false, gameflow.mLevelBannerTex, gameflow.mLevelBannerFadeValue);

		// either this is a lot of inlines or there's a lot of debug stuff here.
		STACK_PAD_VAR(64);
	}

	/**
	 * @brief Renders the given debug menu, handling any pop-out submenu overlay alphas.
	 * @param gfx Graphics context for rendering.
	 * @param menu Menu to render.
	 * @param fadeFactor Factor to apply to menu alpha (0-1, 0=no alpha, 1=full alpha).
	 */
	void drawMenu(Graphics& gfx, Menu* menu, f32 fadeFactor)
	{
		if (menu->mAlignToParentItem) {
			// create pop-out submenu effect - have parent menu at half alpha behind this menu
			drawMenu(gfx, menu->mParentMenu, 0.5f * fadeFactor);
		}

		menu->draw(gfx, fadeFactor);
	}

	// _00     = VTBL
	// _00-_20 = Node
	u8 _20[0x28 - 0x20];     ///< _20, unknown/unused.
	Controller* mController; ///< _28, active player controller.
	Menu* mActiveDebugMenu;  ///< _2C, current active debug menu (always `nullptr`, since we have none set up).
	u8 _30[0x50 - 0x30];     ///< _30, unknown/unused.
};

/**
 * @brief Initialises progressive scan mode screen game section.
 *
 * Most of the hard work gets farmed out to NinLogoSetupSection above.
 */
void NinLogoSection::init()
{
	Node::init("<NinLogoSection>");
	// make sure debug timer display is off for players
	gsys->mTimerState = TS_Off;

	// do the actual setup and controlling
	add(new NinLogoSetupSection());
}
