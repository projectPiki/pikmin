#ifndef _ZEN_OGMENU_H
#define _ZEN_OGMENU_H

#include "types.h"
#include "Colour.h"
#include "Vector.h"
#include "system.h"
#include "P2D/Screen.h"

struct Controller;
struct Graphics;
struct P2DPicture;
struct P2DTextBox;
struct P2DPane;

namespace zen {

struct ogRaderMgr;

/**
 * @brief TODO
 */
struct ogDrawScrMenu {

	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		// TODO: this
	};

	ogDrawScrMenu();

	returnStatusFlag update(Controller*, bool, bool);

	// unused/inlined:
	void setScreen(char*);
	void calcAngleSpeed(f32);
	bool draw(Graphics&);

	bool chkStopAngle()
	{
		if (_0C == _10 && _14 == 0.0f) {
			return true;
		}
		return false;
	}
	P2DPane* getRoot() { return _08; }
	P2DScreen* getPsc() { return mScreen; }
	void setAngle(f32 a) { }
	void setMaxR(f32 a) { }
	void start(int state)
	{
		_20 = state;
		setAngle((f32)(state - 1) * TAU / 6.0f);
		setMaxR(600.0f);
		_14 = 0.0f;

		f32 c = cosf(_0C);
		f32 s = sinf(_0C);
		_08->move(c + _1C, (-_1C * s) + _1C, 0.0f);
		_08->rotate(320, 240, P2DROTATE_Y, -_0C);
	}

	P2DScreen* mScreen;   // _00
	returnStatusFlag _04; // _04
	P2DPane* _08;         // _08
	f32 _0C;              // _0C
	f32 _10;              // _10
	f32 _14;              // _14
	int _18;              // _18
	f32 _1C;              // _1C
	int _20;              // _20
};

/**
 * @brief TODO
 */
struct ogDrawScrController {
	ogDrawScrController();

	void update();

	// unused/inlined:
	void setWinColor();
	void setOriginalColor();
	void setHantenColor();

	// TODO: members
	ogDrawScrMenu _00;  // _00
	P2DPicture* _24[9]; // _24
	P2DPicture* _48[9]; // _48
	P2DTextBox* _6C[9]; // _6C
	P2DPicture* _90[9]; // _90
	P2DPicture* _B4;    // _B4
	s16 _B8;            // _B8
	f32 _BC;            // _BC
	f32 _C0;            // _C0
	Colour _C4;         // _C4
	Colour _C8;         // _C8
	int _CC;            // _CC
	bool _D0;           // _D0
};

/**
 * @brief TODO
 */
struct ogDrawScrInfo {
	ogDrawScrInfo();

	void start();

	// unused/inlined:
	void update(Controller*);

	ogDrawScrMenu _00; // _00
	int _24;           // _24
	P2DPane* _28[5];   // _28
	P2DPane* _3C;      // _3C
	P2DPane* _40;      // _40
	P2DPane* _44;      // _44
	int _48[7];        // _48
	P2DPane* _64;      // _64
	P2DPane* _68;      // _68
	P2DPane* _6C;      // _6C
	P2DPane* _70;      // _70
	P2DPane* _74;      // _74
	P2DPane* _78;      // _78
	int _7C;           // _7C
	int _80;           // _80
	int _84;           // _84
	int _88;           // _88
	int _8C;           // _8C
	int _90;           // _90
	int _94;           // _94
	int _98;           // _98
	int _9C;           // _9C
	int _A0;           // _A0
};

struct ogDrawScrInfo2 {
	ogDrawScrInfo2(); // unused/inlined

	// unused/inlined:
	void start();
	void update(Controller*);
	void drawHougaku(Graphics&);

	P2DPane* getPaneMaps() { return _24; }

	ogDrawScrMenu _00; // _00
	P2DPane* _24;      // _24
	Vector3f _28;      // _28
	P2DPane* _34;      // _34
};

// This struct is completely inlined
struct ogDrawLR {
	ogDrawLR()
	{
		mScreen = new P2DScreen;
		mScreen->set("screen/blo/cont_y.blo", true);
		_10 = 0.0f;
		_14 = 1.0f;
		_18 = 1.0f;
		_1C = 1.0f;
		_04 = 0;
		_05 = 0;
		_08 = mScreen->search('ya_l', true);
		_0C = mScreen->search('ya_r', true);
		_08->hide();
		_0C->hide();
	}

	void draw() { mScreen->draw(0, 0, nullptr); }
	void setAct_L(bool set)
	{
		_04 = set;
		if (set) {
			_08->show();
		} else {
			_08->hide();
		}
	}
	void setAct_R(bool set)
	{
		_05 = set;
		if (set) {
			_0C->show();
		} else {
			_0C->hide();
		}
	}
	void start()
	{
		_10 = 0.0f;
		_14 = 1.0f;
		_18 = 1.0f;
		_1C = 1.0f;
		_04 = false;
		_05 = false;
	}
	void update()
	{
		f32 time = gsys->getFrameTime();
		_14      = sinf(-_10) * 0.25f + 0.75f;
		_18      = sinf(-_10) * 0.25f + 0.75f;
		_1C      = cosf(-_10) * 0.125f + 0.875f;
		_08->setOffset(48, 48);
		_0C->setOffset(0, 48);
		_08->setScale(_14, _1C, 1.0f);
		_0C->setScale(_18, _1C, 1.0f);
		_10 += time / 0.016666666f * 0.2f;
		if (_10 >= TAU) {
			_10 -= TAU;
		}
	}

	P2DScreen* mScreen; // _00
	u8 _04;             // _04
	u8 _05;             // _05
	P2DPane* _08;       // _08
	P2DPane* _0C;       // _0C
	f32 _10;            // _10
	f32 _14;            // _14
	f32 _18;            // _18
	f32 _1C;            // _1C
};

/**
 * @brief TODO
 */
struct ogScrMenuMgr {

	enum returnStatusFlag {
		Status_NULL = -1,
		Status_0    = 0,
		Status_1    = 1,
		Status_2    = 2,
		Status_3    = 3,
		// TODO: this
	};

	ogScrMenuMgr();

	void start();
	returnStatusFlag update(Controller*);
	bool draw(Graphics&);

	// unused/inlined:
	void updateInfo(Controller*);
	void updateCont(Controller*);

	returnStatusFlag mStatus; // _00
	s16 _04;                  // _04
	P2DScreen* _08;           // _08
	P2DPicture* _0C;          // _0C
	ogDrawLR* _10;            // _10
	ogRaderMgr* _14;          // _14
	ogDrawScrMenu* _18[3];    // _18
	int _24[3];               // _24
	P2DPane* _30[3];          // _30
	int _3C[3];               // _3C
	ogDrawScrInfo* _48;       // _48
	ogDrawScrController* _4C; // _4C
	ogDrawScrInfo2* _50;      // _50
	bool _54;                 // _54
	bool _55;                 // _55
	f32 _58;                  // _58
	u8 _5C;                   // _5C
	u8 mAlpha;                // _5D
	Vector3f _60;             // _60
};

// unused global functions:
void ChkAngle(f32*);

} // namespace zen

#endif
