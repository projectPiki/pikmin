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
		MODE_Unk0 = 0,
		MODE_Unk1 = 1,
		MODE_Unk2 = 2,
		MODE_Unk3 = 3,
		MODE_Unk4 = 4,
	};

	/**
	 * @brief TODO
	 */
	enum mesFlag {
		MES_Unk0 = 0,
		MES_Unk1 = 1,
	};

	DrawProgreMes()
	{
		mProgreScreen     = new DrawScreen("progre2.blo", nullptr, false, false);
		P2DScreen* screen = mProgreScreen->getScreenPtr();
		_20               = screen->search('ms_1', true);
		_24               = screen->search('ms_2', true);
		_20->hide();
		_24->hide();
		mMenuTitle.setPane(screen, screen, 'yoko');
		mMenuPanelMgr.setCallBack(screen, screen);

		setMode(MODE_Unk0);
	}

	// DLL:
	void init() { setMode(MODE_Unk0); }

	bool update(Controller* controller)
	{
		switch (mMode) {
		case MODE_Unk0:
			mMenuTitle.wait();
			mMenuPanelMgr.wait();
			mMenuTitle.update(0.0f);
			break;

		case MODE_Unk1:
			_28 += gsys->getFrameTime();
			if (_28 > _2C) {
				setMode(MODE_Unk2);
			} else {
				mMenuTitle.update(_28 / _2C);
			}
			break;

		case MODE_Unk2:
			if (controller->keyClick(KBBTN_START | KBBTN_A)) {
				SeSystem::playSysSe(SYSSE_DECIDE1);
				setMode(MODE_Unk3);
			}
			break;

		case MODE_Unk3:
			_28 += gsys->getFrameTime();
			if (_28 > _2C) {
				setMode(MODE_Unk4);
			} else {
				mMenuTitle.update(_28 / _2C);
			}
			break;

		case MODE_Unk4:
			break;
		}

		mMenuPanelMgr.update();
		mProgreScreen->update();
	}

	modeFlag getModeFlag() { return mMode; }

	void start(mesFlag mes)
	{
		_20->hide();
		_24->hide();
		switch (mes) {
		case MES_Unk0:
			_24->show();
			break;

		case MES_Unk1:
			_20->show();
			break;
		}

		setMode(MODE_Unk1);
	}

	void draw(Graphics&) { mProgreScreen->draw(); }

protected:
	// weak:
	void setMode(zen::DrawProgreMes::modeFlag mode)
	{
		mMode = mode;
		switch (mMode) {
		case MODE_Unk0:
			_28 = 0.0f;
			_2C = 0.0f;
			break;

		case MODE_Unk1:
			_28 = 0.0f;
			_2C = 0.5f;
			mMenuPanelMgr.start(_2C);
			mMenuTitle.start();
			break;

		case MODE_Unk2:
			mMenuPanelMgr.operation();
			break;

		case MODE_Unk3:
			_28 = 0.0f;
			_2C = 0.5f;
			mMenuPanelMgr.end(_2C);
			mMenuTitle.end();
			break;
		}
	}

	modeFlag mMode;             // _00
	DrawScreen* mProgreScreen;  // _04
	DrawMenuTitle mMenuTitle;   // _08
	MenuPanelMgr mMenuPanelMgr; // _10
	P2DPane* _20;               // _20
	P2DPane* _24;               // _24
	f32 _28;                    // _28
	f32 _2C;                    // _2C
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
		RETSTATE_NULL = -1,
		RETSTATE_Unk0 = 0,
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
