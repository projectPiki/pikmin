#ifndef _ZEN_DRAWCM_H
#define _ZEN_DRAWCM_H

#include "gameflow.h"
#include "nlib/Math.h"
#include "stl/stdio.h"
#include "types.h"
#include "zen/DrawMenu.h"
#include "zen/Number.h"
#include "zen/ogGraph.h"

struct GameChalQuickInfo;
struct Graphics;
struct Controller;
struct P2DScreen;

namespace zen {

struct DrawOptionSave;
struct EffectMgr2D;

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct DrawCMtitleObj {
public:
	typedef bool (DrawCMtitleObj::*ModeFunc)();

	DrawCMtitleObj()
	{
		mTitlePane    = nullptr;
		_10           = -1;
		mModeFunction = nullptr;
	}

	void init(P2DScreen*);
	void update();
	void wait(f32);
	void appear(f32);
	bool modeSleep();
	bool modeAppear();
	bool modeWait();

	u32 getEvent() { return mEventFlag; }

protected:
	P2DPane* mTitlePane;    // _00
	Vector3f mPosition;     // _04
	int _10;                // _10
	ModeFunc mModeFunction; // _14
	f32 _20;                // _20
	f32 _24;                // _24
	u32 mEventFlag;         // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x50. Lives in drawCMscore for data reasons.
 */
struct DrawCMscoreObj;

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct DrawCMscoreMgr {
public:
	typedef bool (DrawCMscoreMgr::*ModeFunc)();

	enum Mode {
		MODE_Sleep  = -1,
		MODE_Appear = 0,
		MODE_Unk1   = 1,
	};

	DrawCMscoreMgr()
	{
		mScoreObjs    = nullptr;
		mMode         = -1;
		mModeFunction = nullptr;
		mEventFlag    = 0;
	}

	void init(P2DScreen*);
	void update();
	void hide();
	void sleep();
	void appear(f32);
	void setScore(int, int);

	// unused/inlined:
	void show();

	// DLL inlines to do:
	u32 getEventFlag() { return mEventFlag; }

protected:
	bool modeSleep();
	bool modeAppear();
	bool modeWait();

	static const int MEMORY_BEST_SCORE;

	DrawCMscoreObj* mScoreObjs; // _00
	int mMode;                  // _04
	ModeFunc mModeFunction;     // _08
	u8 _14[0x8];                // _14, unknown
	u32 mEventFlag;             // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x20. In drawCMbest.cpp for ordering reasons.
 * If it has to be here for some reason later, we'll have to find another way of doing PRINT/ERROR.
 */
struct DrawCMBpicObj;

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct DrawCMbest {
public:
	typedef bool (DrawCMbest::*ModeFunc)();

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		MODE_Sleep  = 0,
		MODE_Appear = 1,
		MODE_Wait   = 2,
	};

	DrawCMbest()
	{
		mMode         = MODE_Sleep;
		_04           = nullptr;
		mPicObjs      = nullptr;
		mModeFunction = nullptr;
		_0C           = 0;
	}

	void init(P2DScreen*);
	void sleep();
	void update();
	void appear();
	void wait();

	void show() { _04->show(); }
	void hide() { _04->hide(); }

protected:
	bool modeSleep();
	bool modeWait();
	bool modeAppear();
	void setMode(modeFlag);

	modeFlag mMode;          // _00
	P2DPane* _04;            // _04
	DrawCMBpicObj* mPicObjs; // _08
	int _0C;                 // _0C
	ModeFunc mModeFunction;  // _10
};

/**
 * @brief TODO
 */
struct DrawCMresultAlpha {
public:
	DrawCMresultAlpha() { init(); }

	virtual bool update() // _08
	{
		switch (_04) {
		case 1:
			if (_08 < 255) {
				_08++;
			}
			break;

		case 2:
			if (_08 != 0) {
				_08--;
			}
			break;
		}
		return false;
	}

	void init()
	{
		_08 = 0;
		_04 = 0;
	}

	void appear() { _04 = 1; }

protected:
	// _00 = VTBL
	int _04; // _04
	u8 _08;  // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct DrawCMresultGraph : public DrawCMresultAlpha {
public:
	DrawCMresultGraph(P2DScreen* screen) { mGraphMgr = new ogGraphMgr(screen); }

	// DLL inlines to do:
	void draw() { mGraphMgr->draw(_08); }

protected:
	// _00     = VTBL
	// _00-_0C = DrawCMresultAlpha
	ogGraphMgr* mGraphMgr; // _0C
};

/**
 * @brief TODO
 *
 * @note Size: 0xA0.
 */
struct DrawCMresult {
public:
	typedef bool (DrawCMresult::*ModeFunc)(Controller*);

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		MODE_Sleep      = 0,
		MODE_WaitAppear = 1,
		MODE_Appear     = 2,
		MODE_Operation  = 3,
		MODE_Save       = 4,
		MODE_Unk5       = 5,
	};

	DrawCMresult();

	bool update(Controller*);
	void draw(Graphics&);
	void start(const GameChalQuickInfo&);

protected:
	void makeResident();
	void setMode(modeFlag);
	bool modeSleep(Controller*);
	bool modeWaitAppear(Controller*);
	bool modeAppear(Controller*);
	bool modeOperation(Controller*);
	bool modeSave(Controller*);
	void createRankInEffect();

	modeFlag mMode;                  // _00
	ModeFunc mModeFunction;          // _04
	DrawScreen* mResultScreen;       // _10
	DrawScreen* mScoreScreen;        // _14
	DrawScreen* mBestScreen;         // _18
	DrawCMtitleObj mTitleObj;        // _1C
	DrawCMscoreMgr mScoreMgr;        // _48
	DrawCMbest mBest;                // _68
	int _84;                         // _84
	int _88;                         // _88
	int _8C;                         // _8C
	EffectMgr2D* mEffectMgr2D;       // _90
	f32 _94;                         // _94
	DrawCMresultGraph* mResultGraph; // _98
	DrawOptionSave* mOptionSave;     // _9C
};

/**
 * @brief TODO
 *
 * @note Size: 0x19C. In drawCMcourseSelect because of data ordering.
 */
struct DrawCMCSmenu;

/**
 * @brief TODO
 *
 * @note Size: 0x94.
 */
struct DrawCMcourseSelect {
public:
	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		RETSTATE_UnkN3 = -3,
		RETSTATE_UnkN2 = -2,
		RETSTATE_UnkN1 = -1,
		RETSTATE_Unk0  = 0,
		RETSTATE_Unk1  = 1,
		RETSTATE_Unk2  = 2,
		RETSTATE_Unk3  = 3,
		RETSTATE_Unk4  = 4,
	};

	enum modeFlag {
		MODE_Unk0 = 0,
		MODE_Unk1 = 1,
		MODE_Unk2 = 2,
		MODE_Unk3 = 3,
	};

	DrawCMcourseSelect();

	void start();
	bool update(Controller*);
	void draw(Graphics&);
	returnStatusFlag getReturnStatusFlag();

protected:
	void setBestScore();
	bool modeOperation(Controller*);

	DrawScreen* mSelectScreen;     // _00
	DrawScreen* mScoreScreen;      // _04
	DrawScreen* mBestScreen;       // _08
	returnStatusFlag mReturnState; // _0C
	u8 _10[0x4];                   // _10, unknown
	modeFlag mMode;                // _14
	u8 _18[0x4];                   // _18, unknown
	DrawCMCSmenu* mMenu;           // _1C
	DrawCMtitleObj mTitleObj;      // _20
	DrawCMscoreMgr mScoreMgr;      // _4C
	DrawCMbest mBest;              // _6C
	EffectMgr2D* mEffectMgr2D;     // _88
	P2DPane* _8C;                  // _8C
	u8 _90;                        // _90
};
} // namespace zen

#endif
