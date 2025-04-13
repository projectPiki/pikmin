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
 * @brief Enum for course point ordering in WorldMap screen files.
 *
 * @note Use mapNoGame2Scr (or mapNoScr2Game) to convert to StageID.
 */
enum WorldMapName {
	WM_START     = 0,
	WM_Yakushima = WM_START, // 0
	WM_Forest,               // 1
	WM_Practice,             // 2
	WM_Cave,                 // 3
	WM_Last,                 // 4
	WM_COUNT,                // 5
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
	void setPane(P2DPane* titlePane) // param type unsure, could be a pane subtype
	{
		_04 = titlePane;
		_04->setOffset(_04->getWidth() >> 1, _04->getHeight() >> 1);
		_00 = 0;
	}
	void init()
	{
		_04->move(640, 480);
		_00 = 0;
		hide();
	}
	void hide() { _04->hide(); }

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
	WorldMapCoursePoint()
	{
		_04        = 0;
		_08        = 0.0f;
		mIsVisible = false;
		_14        = nullptr;
		_18        = nullptr;
		_24        = nullptr;
		_28        = nullptr;
		for (int i = 0; i < 4; i++) {
			_2C[i] = nullptr;
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

	// non-list but DLL inlines, names fabricated:
	void setNeighbors(WorldMapCoursePoint* pt1, WorldMapCoursePoint* pt2, WorldMapCoursePoint* pt3, WorldMapCoursePoint* pt4)
	{
		_2C[0] = pt1;
		_2C[1] = pt2;
		_2C[2] = pt3;
		_2C[3] = pt4;
	}

	void setSecondaryPanes(P2DScreen* pointScreen, u32 onyTag, u32 chaTag)
	{
		_24 = pointScreen->search(onyTag, true);
		_28 = pointScreen->search(chaTag, true);
	}

	void setGameStageID(int stageID) { mGameStageID = stageID; }

	void deselect()
	{
		if (mIsVisible) {
			_14->show();
			_18->hide();
			_20->hide();
		}
	}

	void show()
	{
		mIsVisible = true;
		_14->hide();
		_18->hide();
		_1C->show();
		_20->hide();
	}
	void hide()
	{
		mIsVisible = false;
		_14->hide();
		_18->hide();
		_1C->hide();
		_20->hide();
	}

	static const int EVENT_NONE;          // 0
	static const int EVENT_APPEAR_FINISH; // 1

	u8 _00[0x4];                 // _00, unknown
	u32 _04;                     // _04, unknown
	f32 _08;                     // _08
	bool mIsVisible;             // _0C
	int mGameStageID;            // _10, see StageID enum
	P2DPicture* _14;             // _14, x_N, N=1-5
	P2DPicture* _18;             // _18, x_Ns, N=1-5
	P2DPicture* _1C;             // _1C, po0N, N=1-5
	P2DPane* _20;                // _20, sliN, N=1-5 - might be a sub-class
	P2DPane* _24;                // _24, onyN, N=1-5 - might be a sub-class
	P2DPane* _28;                // _28, chaN, N=1-5 - might be a sub-class
	WorldMapCoursePoint* _2C[4]; // _2C
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

	// DLL inlines:
	bool update(Controller*, bool);
	u32 getEventFlag();
	void createCourseInEffect();
	void getLandPos(int*, int*);
	void getStayPos(int*, int*);

	// not DLL inlines in the list, but definitely inlines in the actual DLL - names fabricated
	void select(int gameStageID)
	{
		mSelectedPoint = &mCoursePoints[mapNoGame2Scr[gameStageID]];
		mSelectedPoint->select();
	}

	void init(P2DScreen* pointScreen, P2DScreen* lineScreen, int startStageID)
	{
		_134 = 0;
		if (playerState) {
			WorldMapCoursePoint* pt0 = &mCoursePoints[0];
			pt0->setPane(pointScreen, 'x_1', 'x_1s', 'po01', lineScreen, 'sli1');
			pt0->setNeighbors(&mCoursePoints[4], &mCoursePoints[1], nullptr, &mCoursePoints[3]);
			if (playerState->courseOpen(STAGE_Yakushima)) {
				WorldMapCoursePoint* pt1 = &mCoursePoints[1];
				pt1->setPane(pointScreen, 'x_2', 'x_2s', 'po02', lineScreen, 'sli2');
				pt1->setNeighbors(&mCoursePoints[0], nullptr, nullptr, &mCoursePoints[2]);
			} else {
				WorldMapCoursePoint* pt1 = &mCoursePoints[1];
				pt1->setPane(pointScreen, 'x_2', 'x_2s', 'po02', lineScreen, 'sli2');
				pt1->setNeighbors(&mCoursePoints[3], nullptr, nullptr, &mCoursePoints[2]);
			}

			WorldMapCoursePoint* pt2 = &mCoursePoints[2];
			pt2->setPane(pointScreen, 'x_3', 'x_3s', 'po03', lineScreen, 'sli3');
			pt2->setNeighbors(&mCoursePoints[3], nullptr, &mCoursePoints[1], nullptr);
			if (playerState->courseOpen(STAGE_Yakushima)) {
				WorldMapCoursePoint* pt3 = &mCoursePoints[3];
				pt3->setPane(pointScreen, 'x_4', 'x_4s', 'po04', lineScreen, 'sli4');
				pt3->setNeighbors(&mCoursePoints[4], &mCoursePoints[2], &mCoursePoints[0], nullptr);
			} else {
				WorldMapCoursePoint* pt3 = &mCoursePoints[3];
				pt3->setPane(pointScreen, 'x_4', 'x_4s', 'po04', lineScreen, 'sli4');
				pt3->setNeighbors(&mCoursePoints[4], &mCoursePoints[2], &mCoursePoints[1], nullptr);
			}

			WorldMapCoursePoint* pt4 = &mCoursePoints[4];
			pt4->setPane(pointScreen, 'x_5', 'x_5s', 'po05', lineScreen, 'sli5');
			pt4->setNeighbors(nullptr, &mCoursePoints[3], &mCoursePoints[0], nullptr);

		} else {
			WorldMapCoursePoint* pt0 = &mCoursePoints[0];
			pt0->setPane(pointScreen, 'x_1', 'x_1s', 'po01', lineScreen, 'sli1');
			pt0->setNeighbors(&mCoursePoints[4], &mCoursePoints[1], nullptr, &mCoursePoints[3]);

			WorldMapCoursePoint* pt1 = &mCoursePoints[1];
			pt1->setPane(pointScreen, 'x_2', 'x_2s', 'po02', lineScreen, 'sli2');
			pt1->setNeighbors(&mCoursePoints[0], nullptr, nullptr, &mCoursePoints[2]);

			WorldMapCoursePoint* pt2 = &mCoursePoints[2];
			pt2->setPane(pointScreen, 'x_3', 'x_3s', 'po03', lineScreen, 'sli3');
			pt2->setNeighbors(&mCoursePoints[3], nullptr, &mCoursePoints[1], nullptr);

			WorldMapCoursePoint* pt3 = &mCoursePoints[3];
			pt3->setPane(pointScreen, 'x_4', 'x_4s', 'po04', lineScreen, 'sli4');
			pt3->setNeighbors(&mCoursePoints[4], &mCoursePoints[2], &mCoursePoints[0], nullptr);

			WorldMapCoursePoint* pt4 = &mCoursePoints[4];
			pt4->setPane(pointScreen, 'x_5', 'x_5s', 'po05', lineScreen, 'sli5');
			pt4->setNeighbors(nullptr, &mCoursePoints[3], &mCoursePoints[0], nullptr);
		}

		for (int i = WM_START; i < WM_COUNT; i++) {
			int gameStageID = mapNoScr2Game[i];
			char onyStr[8];
			sprintf(onyStr, "ony%d", i + 1);
			char chaStr[8];
			sprintf(chaStr, "cha%d", i + 1);

			mCoursePoints[i].setSecondaryPanes(pointScreen, P2DPaneLibrary::makeTag(onyStr), P2DPaneLibrary::makeTag(chaStr));
			mCoursePoints[i].setGameStageID(gameStageID);
			mCoursePoints[i].select();
			mCoursePoints[i].show();
			if (playerState && !playerState->courseOpen(gameStageID)) {
				mCoursePoints[i].hide();
			}
		}

		select(startStageID);
	}

	u32 _00;                              // _00, unknown
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

		update();
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

	// maybe closeMapImage? maybe rename later
	void update()
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

	// DLL inlines to do:
	void closeMapImage();

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
			sprintf(mapStr, "map%d", mapNoScr2Game[i] + 1);
			P2DPane* mapPane = titleScreen->search(P2DPaneLibrary::makeTag(mapStr), true);
			mTitleObjects[i].setPane(mapPane);
		}

		init();
	}
	void init()
	{
		for (int i = 0; i < OBJ_NUM; i++) {
			mTitleObjects[i].init();
		}
		_04 = -1;
	}

	// DLL inlines to do:
	void exitTitle();
	void update();

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
		_04 = 0;
	}

	// DLL inlines to do:
	void rapidFire();
	void update();

	f32 _00; // _00
	u8 _04;  // _04
};

/**
 * @brief TODO
 */
struct DrawWorldMap {

	/**
	 * @brief TODO
	 */
	enum startModeFlag {
		// TODO: this
	};

	/**
	 * @brief TODO
	 */
	enum startPlaceFlag {
		// TODO: this
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

	int _00;                                   // _00
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
