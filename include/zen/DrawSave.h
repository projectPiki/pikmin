#ifndef _ZEN_DRAWSAVE_H
#define _ZEN_DRAWSAVE_H

#include "types.h"
#include "zen/ogMemChk.h"
#include "zen/DrawCommon.h"

struct Graphics;
struct Controller;
struct P2DPicture;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct DrawSaveFailure {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		MODE_Unk0 = 0,
		MODE_Unk1 = 1,
		MODE_Unk2 = 2,
		MODE_Unk3 = 3,
	};

	DrawSaveFailure();

	bool update(Controller*);
	void draw(Graphics&);
	void open(f32);
	void setMode(modeFlag);
	f32 calcFrame(f32);
	void init();

	DrawScreen* mSaveFailScreen; // _00
	modeFlag mMode;              // _04
	f32 _08;                     // _08
	f32 _0C;                     // _0C
	P2DPane* mSaveFailPane;      // _10
	P2DPicture* mBackIcon;       // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0x4C.
 */
struct DrawSaveMes {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		MODE_Unk0 = 0,
		MODE_Unk1 = 1,
		MODE_Unk2 = 2,
		MODE_Unk3 = 3,
		MODE_Unk4 = 4,
		MODE_Unk5 = 5,
		MODE_Unk6 = 6,
		MODE_Unk7 = 7,
		MODE_Unk8 = 8,
	};

	DrawSaveMes();

	void sleep();
	void mesAppear();
	void saveFinish();
	void saveError();
	bool update(Controller*);
	void draw(Graphics&);
	void setMode(modeFlag);

	// unused/inlined:
	void hide();

	// DLL inlines to do:
	modeFlag getModeFlag() { return mMode; }

	modeFlag mMode;               // _00
	u8 _04[0x34 - 0x4];           // _04, unknown
	DrawSaveFailure mSaveFailure; // _34
};

/**
 * @brief TODO
 */
struct DrawOptionSave {
	enum Mode {
		MODE_Sleep     = 0,
		MODE_Start     = 1,
		MODE_CardCheck = 2,
		MODE_Saving    = 3,
		MODE_SaveFail  = 4,
		MODE_SaveOK    = 5,
		MODE_Unk6      = 6,
		MODE_Unk7      = 7,
		MODE_Unk8      = 8,
		MODE_Unk9      = 9,
	};

	DrawOptionSave();

	bool update(Controller*);
	void draw(Graphics&);
	void modeCardCheck(Controller*);
	void init();
	void start();
	void setMode(u32, Controller*);

	// DLL inlines to do:
	u32 getModeFlag();

	u32 mMode;                 // _00
	DrawSaveMes mSaveMes;      // _04
	ogScrMemChkMgr mMemChkMgr; // _50
};

} // namespace zen

#endif
