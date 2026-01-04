#ifndef _ZEN_DRAWGAMEINFO_H
#define _ZEN_DRAWGAMEINFO_H

#include "P2D/Graph.h"
#include "P2D/Pane.h"
#include "P2D/Screen.h"
#include "nlib/Math.h"
#include "system.h"
#include "types.h"
#include "zen/DamageEffect.h"
#include "zen/DrawCommon.h"
#include "zen/Number.h"

struct Graphics;
struct P2DPerspGraph;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct GameInfo {
	GameInfo()
	{
		mEncodedNextThrowType = 0;
		mFormationPikiNum     = 0;
		mMapPikiNum           = 0;
		mTotalPikiNum         = 0;
	}

	int mEncodedNextThrowType; // _00
	s16 mFormationPikiNum;     // _04
	s16 mMapPikiNum;           // _06
	s16 mTotalPikiNum;         // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x104.
 */
struct DGIScreenMgr {
public:
	enum modeFlag {
		MODE_Unk0 = 0,
		MODE_Unk1 = 1,
		MODE_Unk2 = 2,
		MODE_Unk3 = 3,
	};

	DGIScreenMgr(immut char* bloFileName)
	{
		_04   = 0.0f;
		_08   = 0.5f;
		mMode = 0;
		mScreen.set(bloFileName, true, true, true);
		mScreen.setOffset(mScreen.getWidth() >> 1, mScreen.getHeight() >> 1);
	}

	P2DPane* search(u32 tag, bool p2) { return mScreen.search(tag, p2); }

	void update()
	{
		mScreen.update();
		switch (mMode) {
		case MODE_Unk0:
		{
			mScreen.hide();
			break;
		}
		case MODE_Unk1:
		{
			f32 frame;
			if (addFrame(&frame)) {
				mMode = MODE_Unk2;
			}
			mScreen.setScale(2.0f - 1.0f * frame);
			break;
		}
		case MODE_Unk2:
		{
			mScreen.setScale(1.0f);
			break;
		}
		case MODE_Unk3:
		{
			f32 frame2;
			if (addFrame(&frame2)) {
				mMode = MODE_Unk0;
			}
			mScreen.setScale(1.0f * frame2 + 1.0f);
			break;
		}
		}
	}

	void draw(P2DPerspGraph* perspGraph) { mScreen.draw(0, 0, perspGraph); }

	void makeResident() { P2DPaneLibrary::makeResident(&mScreen); }

	void displayOn()
	{
		mMode = MODE_Unk2;
		mScreen.show();
		mScreen.setScale(1.0f);
	}

	void displayOff()
	{
		mMode = MODE_Unk0;
		mScreen.hide();
		mScreen.setScale(2.0f);
	}

	void frameIn(f32 p1)
	{
		mMode = MODE_Unk1;
		_04   = 0.0f;
		_08   = p1;
		mScreen.show();
		mScreen.setScale(2.0f);
	}

	void frameOut(f32 p1)
	{
		mMode = MODE_Unk3;
		_04   = 0.0f;
		_08   = p1;
		mScreen.show();
		mScreen.setScale(1.0f);
	}

	// DLL inlines to do:
	bool isFrameIn() { return mMode == MODE_Unk2; }
	bool isFrameOut() { return mMode == MODE_Unk0; }

protected:
	bool addFrame(f32* val)
	{
		bool res = false;
		_04 += gsys->getFrameTime();
		if (_04 > _08) {
			_04 = _08;
			res = true;
		}
		*val = sinf(_04 / _08 * 90.0f * PI / 180.0f);
		return res;
	}

	int mMode;         // _00
	f32 _04;           // _04
	f32 _08;           // _08
	P2DScreen mScreen; // _0C
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct DrawGameInfo {
public:
	/**
	 * @brief TODO
	 */
	enum playModeFlag {
		MODE_Story     = 0,
		MODE_Challenge = 1,
	};

	DrawGameInfo(playModeFlag);

	void update();
	void draw(Graphics&);
	void upperFrameIn(f32, bool);
	void upperFrameOut(f32, bool);
	void lowerFrameIn(f32, bool);
	void lowerFrameOut(f32, bool);

	// unused/inlined:
	void upperDisplayOn();
	void upperDisplayOff();
	void lowerDisplayOn();
	void lowerDisplayOff();
	bool isUpperFrameIn();
	bool isUpperFrameOut();
	bool isLowerFrameIn();
	bool isLowerFrameOut();

protected:
	DGIScreenMgr* mUpperScreenMgr; // _00
	DGIScreenMgr* mLowerScreenMgr; // _04
	DGIScreenMgr* mModeScreenMgr;  // _08
	GameInfo mInfo;                // _0C
	DamageEffect mDamageEffect;    // _18
};

extern GameInfo* pGameInfo;

} // namespace zen

#endif
