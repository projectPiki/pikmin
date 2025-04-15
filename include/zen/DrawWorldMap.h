#ifndef _ZEN_DRAWWORLDMAP_H
#define _ZEN_DRAWWORLDMAP_H

#include "types.h"
#include "P2D/Pane.h"
#include "P2D/Picture.h"
#include "P2D/Screen.h"
#include "zen/Number.h"
#include "zen/ogDiary.h"
#include "zen/DrawWMPause.h"
#include "PlayerState.h"
#include "SoundMgr.h"
#include "OnePlayerSection.h"
#include "zen/SpectrumCursorMgr.h"
#include "zen/DrawCommon.h"
#include "zen/DrawMenu.h"
#include "zen/EffectMgr2D.h"
#include "nlib/Math.h"

struct Controller;
struct Graphics;
struct P2DScreen;

namespace zen {
struct EffectMgr2D;
} // namespace zen

namespace {

extern zen::EffectMgr2D* WMeffMgr;
extern u8 mapNoScr2Game[5];
extern u8 mapNoGame2Scr[5];

/**
 * @brief Enum for course point ordering in actual game - equivalent to StageID
 *
 * @note Use mapNoGame2Scr to convert to WorldMapScreenID
 */
enum WorldMapName {
	WM_NULL     = -1,
	WM_START    = 0,
	WM_Practice = WM_START, // 0, Impact Site
	WM_Forest,              // 1, Forest of Hope
	WM_Cave,                // 2, Forest Navel
	WM_Yakushima,           // 3, Distant Spring
	WM_Last,                // 4, Final Trial
	WM_COUNT,               // 5
};

/**
 * @brief Enum for course point ordering in WorldMap screen files.
 *
 * @note Use mapNoScr2Game to convert to WorldMapName
 */
enum WorldMapScreenID {
	WMSCR_START     = 0,
	WMSCR_Yakushima = WMSCR_START, // 0, Distant Spring
	WMSCR_Forest,                  // 1, Forest of Hope
	WMSCR_Practice,                // 2, Impact Site
	WMSCR_Cave,                    // 3, Forest Navel
	WMSCR_Last,                    // 4, Final Trial
	WMSCR_COUNT,                   // 5
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct WorldMapTitleObj {
	WorldMapTitleObj()
	{
		_04 = nullptr;
		_00 = 0;
	}

	// weak:
	void update()
	{
		switch (_00) {
		case 0:
			break;
		case 1:
			if (move(0.25f)) {
				_00 = 0;
			}
			break;
		case 2:
			if (move(0.5f)) {
				_00 = 0;
				hide();
			}
			break;
		}
		u32 badCompiler;
	}

	// DLL requires these inlines, they aren't in the list though, so fabricated name
	void init(P2DPane* titlePane)
	{
		_04 = titlePane;
		_04->setOffset(_04->getWidth() >> 1, _04->getHeight() >> 1);
		_00 = 0;
	}
	// probably? could be wait, maybe rename later
	void disappear()
	{
		_04->move(640, 480);
		_00 = 0;
		hide();
	}
	void hide() { _04->hide(); }

	bool move(f32 p1)
	{
		bool res = false;
		_08 += gsys->getFrameTime();
		if (_08 > p1) {
			_08 = p1;
			res = true;
		}

		f32 t     = sinf(_08 / p1 * HALF_PI);
		f32 tComp = 1.0f - t;
		_04->move(zen::RoundOff(_10.x * tComp + _1C.x * t), zen::RoundOff(_10.y * tComp + _1C.y * t));
		return res;
	}

	void show() { _04->show(); }

	// might be wait
	void appear()
	{
		_10.set(640.0f, 30.0f, 0.0f);
		_1C.set(40.0f, 30.0f, 0.0f);
		_08 = 0.0f;
		_00 = 1;
		show();
	}

	void wait()
	{
		_10.set(_04->getPosH(), _04->getPosV(), 0.0f);
		_1C.set(_10.x, _10.y - 320.0f, _10.z);
		_08 = 0.0f;
		_00 = 2;
		show();
	}

	int _00;      // _00
	P2DPane* _04; // _04, could be a pane subtype
	f32 _08;      // _08
	u8 _0C[0x4];  // _0C, unknown
	Vector3f _10; // _10
	Vector3f _1C; // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct DrawWorldMapDateCallBack : public P2DPaneCallBack, public zen::NumberTex {
	DrawWorldMapDateCallBack(P2DPane* centrePane, P2DPane* leftPane, P2DPane* rightPane)
	    : P2DPaneCallBack(nullptr, PANETYPE_Pane)
	{
		checkPaneType(centrePane, PANETYPE_Picture);
		checkPaneType(leftPane, PANETYPE_Picture);
		checkPaneType(rightPane, PANETYPE_Picture);

		mCentrePane = (P2DPicture*)centrePane;
		mLeftPane   = (P2DPicture*)leftPane;
		mRightPane  = (P2DPicture*)rightPane;

		setTex();
	}

	virtual bool invoke(P2DPane*) // _08
	{
		setTex();
		return true;
	}

	// weak
	void setTex()
	{
		int dayNum = playerState->getCurrDay() + 1;
		if (dayNum > 9) {
			// need two digits
			mCentrePane->hide();
			mLeftPane->show();
			mLeftPane->setTexture(texTable[dayNum / 10], 0);
			mRightPane->show();
			mRightPane->setTexture(texTable[dayNum % 10], 0);
		} else {
			mCentrePane->show();
			mCentrePane->setTexture(texTable[dayNum], 0);
			mLeftPane->hide();
			mRightPane->hide();
		}
	}

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	// _04     = zen::NumberTex (empty)
	P2DPicture* mCentrePane; // _04, for single digit dates
	P2DPicture* mLeftPane;   // _08, for double digit dates
	P2DPicture* mRightPane;  // _0C, for double digit dates
};

/**
 * @brief TODO
 *
 * @note Size: 0x3C.
 */
struct WorldMapCoursePoint {

	/**
	 * @brief TODO
	 */
	enum linkFlag {
		LINK_Up    = 0,
		LINK_Down  = 1,
		LINK_Left  = 2,
		LINK_Right = 3,
		LINK_COUNT, // 4
	};

	WorldMapCoursePoint()
	{
		_04        = 0;
		_08        = 0.0f;
		mIsVisible = false;
		_14        = nullptr;
		_18        = nullptr;
		mStayPane  = nullptr;
		mLandPane  = nullptr;
		for (int i = 0; i < 4; i++) {
			mLinkPoints[i] = nullptr;
		}
	}

	// weak functions
	void select()
	{
		if (mIsVisible) {
			_14->hide();
			_18->show();
			_20->show();
		}
	}
	void setPane(P2DScreen* pointScreen, u32 tag1, u32 tag2, u32 tag3, P2DScreen* lineScreen, u32 tag4)
	{
		P2DPane* pointPane1 = pointScreen->search(tag1, true);
		if (pointPane1->getTypeID() == PANETYPE_Picture) {
			_14 = (P2DPicture*)pointPane1;
			_14->setOffset(_14->getWidth() >> 1, _14->getHeight());
		}
		P2DPane* pointPane2 = pointScreen->search(tag2, true);
		if (pointPane2->getTypeID() == PANETYPE_Picture) {
			_18 = (P2DPicture*)pointPane2;
			_18->setOffset(_18->getWidth() >> 1, _18->getHeight());
		}
		P2DPane* pointPane3 = pointScreen->search(tag3, true);
		if (pointPane3->getTypeID() == PANETYPE_Picture) {
			_1C = (P2DPicture*)pointPane3;
			_1C->setOffset(_18->getWidth() >> 1, _18->getHeight());
			_1C->hide();
		}
		_20 = lineScreen->search(tag4, true);
	}

	// DLL:
	void setLink(WorldMapCoursePoint* upPt, WorldMapCoursePoint* downPt, WorldMapCoursePoint* leftPt, WorldMapCoursePoint* rightPt)
	{
		mLinkPoints[LINK_Up]    = upPt;
		mLinkPoints[LINK_Down]  = downPt;
		mLinkPoints[LINK_Left]  = leftPt;
		mLinkPoints[LINK_Right] = rightPt;
	}

	void setCursorPoint(P2DScreen* pointScreen, u32 onyTag, u32 chaTag)
	{
		mStayPane = pointScreen->search(onyTag, true);
		mLandPane = pointScreen->search(chaTag, true);
	}

	void setNumber(WorldMapName stageID) { mGameStageID = stageID; }

	void nonSelect()
	{
		if (mIsVisible) {
			_14->show();
			_18->hide();
			_20->hide();
		}
	}

	void openCourse()
	{
		mIsVisible = true;
		_14->hide();
		_18->hide();
		_1C->show();
		_20->hide();
	}
	void closeCourse()
	{
		mIsVisible = false;
		_14->hide();
		_18->hide();
		_1C->hide();
		_20->hide();
	}

	void appear()
	{
		_08 = 0.0f;
		_04 = 1;
		_14->hide();
		_18->hide();
		_1C->hide();
		_20->hide();
	}

	P2DPane* getStayPane() { return mStayPane; }
	P2DPane* getLandPane() { return mLandPane; }
	WorldMapName getNumber() { return mGameStageID; }

	void createCourseInEffect()
	{
		P2DPicture* pic = _14;
		Vector3f vec1;
		vec1.set(pic->getPosH() + (pic->getWidth() >> 1), 480 - (pic->getPosV() + (pic->getHeight() >> 1)), 0.0f);
		WMeffMgr->create(45, vec1, nullptr, nullptr);
	}

	bool update(bool isSelected)
	{
		bool res   = false;
		mEventFlag = EVENT_NONE;
		switch (_04) {
		case 0:
			res = true;
			break;
		case 1:
			f32 timer1 = _08 += gsys->getFrameTime();
			if (timer1 > 0.5f) {
				Vector3f vec1;
				vec1.set(_14->getPosH() + (_14->getWidth() >> 1), 480 - (_14->getPosV() + (_14->getHeight() >> 1)), 0.0f);
				WMeffMgr->create(46, vec1, nullptr, nullptr);
				WMeffMgr->create(47, vec1, nullptr, nullptr);
				SeSystem::playSysSe(SYSSE_SELECT_COURSEOPEN);
				_04 = 2;
				_08 = 0.0f;
			}
			break;
		case 2:
			f32 timer2 = _08 += gsys->getFrameTime();
			if (timer2 > 1.0f) {
				_08 = 0.0f;
				_04 = 3;
				_1C->show();
			}
			break;
		case 3:
			f32 timer3 = _08 += gsys->getFrameTime();
			if (timer3 > 1.0f) {
				_08 = 0.0f;
				_04 = 0;
				mEventFlag |= EVENT_APPEAR_FINISH;
				res = true;
			}
			break;
		}

		return res;
	}

	u32 getEventFlag() { return mEventFlag; }

	bool getOpenSw() { return mIsVisible; }

	WorldMapCoursePoint* getLinkCoursePointPtr(linkFlag id) { return mLinkPoints[id]; }

	static const int EVENT_NONE;          // 0
	static const int EVENT_APPEAR_FINISH; // 1

	u32 mEventFlag;                               // _00
	int _04;                                      // _04
	f32 _08;                                      // _08
	bool mIsVisible;                              // _0C
	WorldMapName mGameStageID;                    // _10
	P2DPicture* _14;                              // _14, x_N, N=1-5
	P2DPicture* _18;                              // _18, x_Ns, N=1-5
	P2DPicture* _1C;                              // _1C, po0N, N=1-5
	P2DPane* _20;                                 // _20, sliN, N=1-5 - might be a sub-class
	P2DPane* mStayPane;                           // _24, onyN, N=1-5 - might be a sub-class
	P2DPane* mLandPane;                           // _28, chaN, N=1-5 - might be a sub-class - cha for charkuriku = land
	WorldMapCoursePoint* mLinkPoints[LINK_COUNT]; // _2C, indexed by linkFlag presumably
};

} // namespace

namespace zen {

struct DrawScreen;

/**
 * @brief TODO
 *
 * @note Size: 0x138. In drawWorldMap.cpp.
 */
struct WorldMapCoursePointMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x88. In drawWorldMap.cpp.
 */
struct WorldMapConfirmMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x3C. In drawWorldMap.cpp.
 */
struct WorldMapCursorOnyon;

/**
 * @brief TODO
 *
 * @note Size: 0x12C. In drawWorldMap.cpp.
 */
struct WorldMapCursorMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x24. In drawWorldMap.cpp.
 */
struct WorldMapMapImageMgr;

/**
 * @brief TODO
 *
 * @note Size: 0xC. In drawWorldMap.cpp.
 */
struct WorldMapPartsInfoMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct WorldMapTitleMgr {
	WorldMapTitleMgr()
	{
		mTitleObjects = new WorldMapTitleObj[OBJ_NUM];
		_04           = -1;
	}

	// DLL:
	void init(P2DScreen* titleScreen)
	{
		for (int i = 0; i < OBJ_NUM; i++) {
			char mapStr[8];
			WorldMapName gameStageID = (WorldMapName)mapNoScr2Game[i];
			sprintf(mapStr, "map%d", gameStageID + 1);
			P2DPane* mapPane = titleScreen->search(P2DPaneLibrary::makeTag(mapStr), true);
			mTitleObjects[i].init(mapPane);
		}

		init();
	}
	void init()
	{
		for (int i = 0; i < OBJ_NUM; i++) {
			mTitleObjects[i].disappear();
		}
		_04 = -1;
	}

	void update()
	{
		for (int i = 0; i < OBJ_NUM; i++) {
			mTitleObjects[i].update();
		}
	}

	void setTitle(WorldMapName id)
	{
		WorldMapScreenID scrID = (WorldMapScreenID)mapNoScr2Game[id];
		if (_04 != scrID) {
			_04 = scrID;
			mTitleObjects[_04].appear();
		}
	}

	void exitTitle()
	{
		if (_04 != -1) {
			mTitleObjects[_04].wait();
			_04 = -1;
		}
	}

	static const int OBJ_NUM;

	WorldMapTitleObj* mTitleObjects; // _00, array of OBJ_NUM objects
	int _04;                         // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x28. In drawWorldMap.cpp.
 */
struct WorldMapWipe;

/**
 * @brief TODO
 *
 * @note Size: 0xB0. In drawWorldMap.cpp.
 */
struct WorldMapWipeMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct WorldMapShootingStarMgr {
	WorldMapShootingStarMgr()
	{
		mStarFallChance  = 0.2f;
		mIsRapidFireMode = false;
	}

	void rapidFire()
	{
		mIsRapidFireMode = true;

		// make star falls certain for 0.25 * 100 = 400 frames after opening Final Trial
		// - chance then drops from 100% by 0.25% per frame, down to a minimum chance of 0.2% per frame
		mStarFallChance = 200.0f;
	}

	void update()
	{
		if (zen::Rand(100.0f) < mStarFallChance) {
			WMeffMgr->create(51, Vector3f(zen::Rand(640.0f), 500.0f - zen::Rand(50.0f), -zen::Rand(150.0f)), nullptr, nullptr);
		}
		if (mIsRapidFireMode) {
			if (mStarFallChance < 0.0f) {
				mIsRapidFireMode = false;
				mStarFallChance  = 0.2f;
			} else {
				mStarFallChance -= 0.25f;
			}
		}
	}

	f32 mStarFallChance;   // _00, as a percent
	bool mIsRapidFireMode; // _04
};

/**
 * @brief TODO
 */
struct DrawWorldMap {

	/**
	 * @brief TODO
	 */
	enum startModeFlag {
		START_Unk0 = 0,
		START_Unk1 = 1,
		START_Unk2 = 2,
		START_Unk3 = 3,
		START_Unk4 = 4,
	};

	/**
	 * @brief TODO
	 */
	enum startPlaceFlag {
		PLACE_Unk0 = 0,
		PLACE_Unk1 = 1,
		PLACE_Unk2 = 2,
		PLACE_Unk3 = 3,
		PLACE_Unk4 = 4,
	};

	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		// TODO: this
	};

	DrawWorldMap();

	bool update(Controller*);
	void draw(Graphics&);
	void start(startModeFlag, startPlaceFlag);
	bool modeStart(Controller*);
	bool modeAppear(Controller*);
	bool modeOperation(Controller*);
	bool modeConfirm(Controller*);
	bool modeEnd(Controller*);
	void updateScreens();
	void closeMapInfo();
	void openMapInfo();

	// unused/inlined:
	~DrawWorldMap();
	void setCoursePoint(startPlaceFlag);

	// DLL inlines:
	returnStatusFlag getReturnStatusFlag();

	startModeFlag mStartMode;                  // _00
	int _04;                                   // _04
	int _08;                                   // _08
	f32 _0C;                                   // _0C
	DrawScreen* mWipeScreen;                   // _10
	DrawScreen* mIconScreen;                   // _14
	DrawScreen* mTitleScreen;                  // _18
	DrawScreen* mMoniScreen;                   // _1C
	DrawScreen* mData1Screen;                  // _20
	DrawScreen* mData2Screen;                  // _24
	DrawScreen* mPointScreen;                  // _28
	DrawScreen* mLineScreen;                   // _2C
	DrawScreen* mBackScreen;                   // _30
	WorldMapCursorMgr* mCursorMgr;             // _34
	WorldMapCoursePointMgr* mCoursePointMgr;   // _38
	int mTotalPartsNum;                        // _3C
	int mCurrentPartsNum;                      // _40
	int mTotalPikiCounts[PikiColorCount];      // _44, indexed by PikiColor
	EffectMgr2D* mEffectMgr2D;                 // _50
	WorldMapMapImageMgr* mMapImageMgr;         // _54
	WorldMapWipeMgr* mWipeMgr;                 // _58
	WorldMapTitleMgr* mTitleMgr;               // _5C
	WorldMapPartsInfoMgr* mPartsInfoMgr;       // _60
	DrawWMPause mPause;                        // _64
	WorldMapConfirmMgr* mConfirmMgr;           // _70
	ogDrawSelectDiary mSelectDiary;            // _74
	WorldMapShootingStarMgr* mShootingStarMgr; // _364
};

} // namespace zen

#endif
