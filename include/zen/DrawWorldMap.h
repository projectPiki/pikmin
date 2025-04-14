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

struct Controller;
struct Graphics;
struct P2DScreen;

namespace zen {
struct EffectMgr2D;
} // namespace zen

namespace {

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
	void update();

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

	// DLL to do:
	bool move(f32);
	void show();
	void appear();
	void wait();

	u32 _00;      // _00, unknown
	P2DPane* _04; // _04, could be a pane subtype
	u8 _08[0x8];  // _08, unknown
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

	virtual bool invoke(P2DPane*); // _08

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
		LINK_Unk0 = 0,
		LINK_Unk1 = 1,
		LINK_Unk2 = 2,
		LINK_Unk3 = 3,
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
	void setLink(WorldMapCoursePoint* pt1, WorldMapCoursePoint* pt2, WorldMapCoursePoint* pt3, WorldMapCoursePoint* pt4)
	{
		mLinkPoints[LINK_Unk0] = pt1;
		mLinkPoints[LINK_Unk1] = pt2;
		mLinkPoints[LINK_Unk2] = pt3;
		mLinkPoints[LINK_Unk3] = pt4;
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

	// DLL inlines:
	void createCourseInEffect();
	bool update(bool);
	u32 getEventFlag();
	bool getOpenSw();
	WorldMapCoursePoint* getLinkCoursePointPtr(linkFlag);

	static const int EVENT_NONE;          // 0
	static const int EVENT_APPEAR_FINISH; // 1

	u8 _00[0x4];                                  // _00, unknown
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

extern zen::EffectMgr2D* WMeffMgr;
extern u8 mapNoScr2Game[5];
extern u8 mapNoGame2Scr[5];
} // namespace

namespace zen {

struct DrawScreen;

/**
 * @brief TODO
 *
 * @note Size: 0x138.
 */
struct WorldMapCoursePointMgr {
	WorldMapCoursePointMgr()
	{
		mSelectedPoint = 0;
		_134           = 0;
		_00            = 0;
	}

	bool modeAppear();
	bool modeOperation(Controller*, bool);

	// DLL:
	void setSelectCourse(WorldMapName gameStageID)
	{
		mSelectedPoint = &mCoursePoints[mapNoGame2Scr[gameStageID]];
		mSelectedPoint->select();
	}

	void init(P2DScreen* pointScreen, P2DScreen* lineScreen, WorldMapName startStageID)
	{
		WorldMapCoursePoint* point;
		_134 = 0;
		if (playerState) {
			point = &mCoursePoints[0];
			point->setPane(pointScreen, 'x_1', 'x_1s', 'po01', lineScreen, 'sli1');
			point->setLink(&mCoursePoints[4], &mCoursePoints[1], nullptr, &mCoursePoints[3]);
			if (playerState->courseOpen(STAGE_Yakushima)) {
				point = &mCoursePoints[1];
				point->setPane(pointScreen, 'x_2', 'x_2s', 'po02', lineScreen, 'sli2');
				point->setLink(&mCoursePoints[0], nullptr, nullptr, &mCoursePoints[2]);
			} else {
				point = &mCoursePoints[1];
				point->setPane(pointScreen, 'x_2', 'x_2s', 'po02', lineScreen, 'sli2');
				point->setLink(&mCoursePoints[3], nullptr, nullptr, &mCoursePoints[2]);
			}

			point = &mCoursePoints[2];
			point->setPane(pointScreen, 'x_3', 'x_3s', 'po03', lineScreen, 'sli3');
			point->setLink(&mCoursePoints[3], nullptr, &mCoursePoints[1], nullptr);
			if (playerState->courseOpen(STAGE_Yakushima)) {
				point = &mCoursePoints[3];
				point->setPane(pointScreen, 'x_4', 'x_4s', 'po04', lineScreen, 'sli4');
				point->setLink(&mCoursePoints[4], &mCoursePoints[2], &mCoursePoints[0], nullptr);
			} else {
				point = &mCoursePoints[3];
				point->setPane(pointScreen, 'x_4', 'x_4s', 'po04', lineScreen, 'sli4');
				point->setLink(&mCoursePoints[4], &mCoursePoints[2], &mCoursePoints[1], nullptr);
			}

			point = &mCoursePoints[4];
			point->setPane(pointScreen, 'x_5', 'x_5s', 'po05', lineScreen, 'sli5');
			point->setLink(nullptr, &mCoursePoints[3], &mCoursePoints[0], nullptr);

		} else {
			point = &mCoursePoints[0];
			point->setPane(pointScreen, 'x_1', 'x_1s', 'po01', lineScreen, 'sli1');
			point->setLink(&mCoursePoints[4], &mCoursePoints[1], nullptr, &mCoursePoints[3]);

			point = &mCoursePoints[1];
			point->setPane(pointScreen, 'x_2', 'x_2s', 'po02', lineScreen, 'sli2');
			point->setLink(&mCoursePoints[0], nullptr, nullptr, &mCoursePoints[2]);

			point = &mCoursePoints[2];
			point->setPane(pointScreen, 'x_3', 'x_3s', 'po03', lineScreen, 'sli3');
			point->setLink(&mCoursePoints[3], nullptr, &mCoursePoints[1], nullptr);

			point = &mCoursePoints[3];
			point->setPane(pointScreen, 'x_4', 'x_4s', 'po04', lineScreen, 'sli4');
			point->setLink(&mCoursePoints[4], &mCoursePoints[2], &mCoursePoints[0], nullptr);

			point = &mCoursePoints[4];
			point->setPane(pointScreen, 'x_5', 'x_5s', 'po05', lineScreen, 'sli5');
			point->setLink(nullptr, &mCoursePoints[3], &mCoursePoints[0], nullptr);
		}

		for (int i = WM_START; i < WM_COUNT; i++) {
			WorldMapName gameStageID = (WorldMapName)mapNoScr2Game[i];
			char onyStr[8];
			sprintf(onyStr, "ony%d", i + 1);
			char chaStr[8];
			sprintf(chaStr, "cha%d", i + 1);

			mCoursePoints[i].setCursorPoint(pointScreen, P2DPaneLibrary::makeTag(onyStr), P2DPaneLibrary::makeTag(chaStr));
			mCoursePoints[i].setNumber(gameStageID);
			mCoursePoints[i].nonSelect();
			mCoursePoints[i].openCourse();
			if (playerState && !playerState->courseOpen(gameStageID)) {
				mCoursePoints[i].closeCourse();
			}
		}

		setSelectCourse(startStageID);
	}

	// might be appear
	void start(WorldMapName id)
	{
		_00 = 0;
		for (int i = 0; i < WM_COUNT; i++) {
			mCoursePoints[i].nonSelect();
		}
		setSelectCourse(id);
	}

	void getLandPos(int* x, int* y)
	{
		P2DPane* landPane = mSelectedPoint->getLandPane();
		*x                = landPane->getPosH();
		*y                = landPane->getPosV();
	}
	void getStayPos(int* x, int* y)
	{
		P2DPane* landPane = mSelectedPoint->getStayPane();
		*x                = landPane->getPosH();
		*y                = landPane->getPosV();
	}

	void appear(WorldMapName id)
	{
		_00 = 1;
		for (int i = 0; i < WM_COUNT; i++) {
			if (mSelectedPoint != &mCoursePoints[i]) {
				mCoursePoints[i].nonSelect();
			} else {
				mCoursePoints[i].select();
			}
		}

		mCoursePoints[mapNoGame2Scr[id]].appear();
	}

	WorldMapName getSelectCourseNumber()
	{
		WorldMapName id = WM_NULL;
		if (mSelectedPoint) {
			id = mSelectedPoint->getNumber();
		}
		return id;
	}

	// DLL inlines to do:
	bool update(Controller*, bool);
	u32 getEventFlag();
	void createCourseInEffect();
	void keyOperation(Controller*, u32, WorldMapCoursePoint::linkFlag);

	int _00;                              // _00
	WorldMapCoursePoint* mSelectedPoint;  // _04
	WorldMapCoursePoint mCoursePoints[5]; // _08
	u32 _134;                             // _134, unknown
};

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
 */
struct WorldMapMapImageMgr {
	WorldMapMapImageMgr()
	{
		_04 = 2;
		_08 = -1;
		_00 = 0.0f;
		_20 = 0;
		for (int i = 0; i < 5; i++) {
			mMapImagePanes[i] = nullptr;
		}
	}

	// weak:
	void init()
	{
		_04 = 0;
		for (int i = 0; i < 5; i++) {
			if (mMapImagePanes[i]) {
				mMapImagePanes[i]->hide();
				mMapImagePanes[i]->setOffset(mMapImagePanes[i]->getWidth() >> 1, mMapImagePanes[i]->getHeight() >> 1);
			}
		}

		_08 = 0;

		closeMapImage();
	}
	void modeOpen();
	void modeClose();

	// DLL:
	void init(P2DScreen* moniScreen)
	{
		P2DPane* pane1 = moniScreen->search('mi_1', true);
		if (pane1->getTypeID() == PANETYPE_Picture) {
			mMapImagePanes[0] = (P2DPicture*)pane1;
		}
		P2DPane* pane2 = moniScreen->search('mi_2', true);
		if (pane2->getTypeID() == PANETYPE_Picture) {
			mMapImagePanes[1] = (P2DPicture*)pane2;
		}
		P2DPane* pane3 = moniScreen->search('mi_3', true);
		if (pane3->getTypeID() == PANETYPE_Picture) {
			mMapImagePanes[2] = (P2DPicture*)pane3;
		}
		P2DPane* pane4 = moniScreen->search('mi_4', true);
		if (pane4->getTypeID() == PANETYPE_Picture) {
			mMapImagePanes[3] = (P2DPicture*)pane4;
		}
		P2DPane* pane5 = moniScreen->search('mi_5', true);
		if (pane5->getTypeID() == PANETYPE_Picture) {
			mMapImagePanes[4] = (P2DPicture*)pane5;
		}

		init();
	}

	void closeMapImage()
	{
		switch (_04) {
		case 0:
			_00 = 0.0f;
			_04 = 1;
			break;
		case 2:
			_20 = 1;
			break;
		}
	}

	void update()
	{
		switch (_04) {
		case 0:
			if (_08 != -1) {
				mMapImagePanes[_08]->show();
				mMapImagePanes[_08]->setScale(1.0f);
			}
			break;
		case 1:
			modeClose();
			break;
		case 2:
			modeOpen();
			break;
		}
	}

	f32 _00;                       // _00
	int _04;                       // _04
	int _08;                       // _08
	P2DPicture* mMapImagePanes[5]; // _0C
	u8 _20;                        // _20
};

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

	// DLL inlines to do:
	void exitTitle();

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
 * @brief PRETTY sure this is what this is.
 */
struct WorldMapShootingStarMgr {
	WorldMapShootingStarMgr()
	{
		_00 = 0.2f;
		_04 = false;
	}

	void rapidFire()
	{
		_04 = true;
		_00 = 200.0f;
	}

	// DLL inlines to do:
	void update();

	f32 _00;  // _00
	bool _04; // _04
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
