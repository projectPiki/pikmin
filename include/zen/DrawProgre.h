#ifndef _ZEN_DRAWPROGRE_H
#define _ZEN_DRAWPROGRE_H

#include "SoundMgr.h"
#include "types.h"
#include "zen/DrawMenu.h"

struct Controller;
struct Graphics;

// DrawProgre = 'Progressive mode' screen

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct DrawProgreMes {
public:
	/**
	 * @brief TODO
	 */
	enum modeFlag {
		MODE_Wait      = 0,
		MODE_FadeIn    = 1,
		MODE_Operation = 2,
		MODE_FadeOut   = 3,
		MODE_Finished  = 4,
	};

	/**
	 * @brief TODO
	 */
	enum mesFlag {
		MES_Progressive = 0,
		MES_Interlace   = 1,
	};

	DrawProgreMes()
	{
		mScreen             = new DrawScreen("progre2.blo", nullptr, false, false);
		P2DScreen* screen   = mScreen->getScreenPtr();
		mInterlaceModeMsg   = screen->search('ms_1', true);
		mProgressiveModeMsg = screen->search('ms_2', true);
		mInterlaceModeMsg->hide();
		mProgressiveModeMsg->hide();
		mMenuTitle.setPane(screen, screen, 'yoko');
		mMenuPanelMgr.setCallBack(screen, screen);

		setMode(MODE_Wait);
	}

	// DLL:
	void init() { setMode(MODE_Wait); }

	bool update(Controller* controller)
	{
		switch (mMode) {
		case MODE_Wait:
		{
			mMenuTitle.wait();
			mMenuPanelMgr.wait();
			mMenuTitle.update(0.0f);
			break;
		}
		case MODE_FadeIn:
		{
			mFadeTimer += gsys->getFrameTime();
			if (mFadeTimer > mMaxFadeTime) {
				setMode(MODE_Operation);
			} else {
				mMenuTitle.update(mFadeTimer / mMaxFadeTime);
			}
			break;
		}
		case MODE_Operation:
		{
			if (controller->keyClick(KBBTN_START | KBBTN_A)) {
				SeSystem::playSysSe(SYSSE_DECIDE1);
				setMode(MODE_FadeOut);
			}
			break;
		}
		case MODE_FadeOut:
		{
			mFadeTimer += gsys->getFrameTime();
			if (mFadeTimer > mMaxFadeTime) {
				setMode(MODE_Finished);
			} else {
				mMenuTitle.update(mFadeTimer / mMaxFadeTime);
			}
			break;
		}
		case MODE_Finished:
		{
			break;
		}
		}

		mMenuPanelMgr.update();
		mScreen->update();
	}

	modeFlag getModeFlag() { return mMode; }

	void start(mesFlag mes)
	{
		mInterlaceModeMsg->hide();
		mProgressiveModeMsg->hide();
		switch (mes) {
		case MES_Progressive:
		{
			mProgressiveModeMsg->show();
			break;
		}
		case MES_Interlace:
		{
			mInterlaceModeMsg->show();
			break;
		}
		}

		setMode(MODE_FadeIn);
	}

	void draw(Graphics&) { mScreen->draw(); }

protected:
	// weak:
	void setMode(zen::DrawProgreMes::modeFlag mode)
	{
		mMode = mode;
		switch (mMode) {
		case MODE_Wait:
		{
			mFadeTimer   = 0.0f;
			mMaxFadeTime = 0.0f;
			break;
		}
		case MODE_FadeIn:
		{
			mFadeTimer   = 0.0f;
			mMaxFadeTime = 0.5f;
			mMenuPanelMgr.start(mMaxFadeTime);
			mMenuTitle.start();
			break;
		}
		case MODE_Operation:
		{
			mMenuPanelMgr.operation();
			break;
		}
		case MODE_FadeOut:
		{
			mFadeTimer   = 0.0f;
			mMaxFadeTime = 0.5f;
			mMenuPanelMgr.end(mMaxFadeTime);
			mMenuTitle.end();
			break;
		}
		}
	}

	modeFlag mMode;               // _00
	DrawScreen* mScreen;          // _04
	DrawMenuTitle mMenuTitle;     // _08
	MenuPanelMgr mMenuPanelMgr;   // _10
	P2DPane* mInterlaceModeMsg;   // _20
	P2DPane* mProgressiveModeMsg; // _24
	f32 mFadeTimer;               // _28
	f32 mMaxFadeTime;             // _2C
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct DrawProgre {
public:
	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		RETSTATE_NULL        = -1,
		RETSTATE_Active      = 0,
		RETSTATE_Progressive = 1,
		RETSTATE_Interlaced  = 2,
	};

	DrawProgre();

	void start();
	returnStatusFlag update(Controller*);
	void draw(Graphics&);

protected:
	DrawMenu* mMenu;               // _00
	returnStatusFlag mReturnState; // _04
	u8 _08[0x4];                   // _08, unknown
	DrawProgreMes* mProgreMes;     // _0C
};

} // namespace zen

#endif
