#ifndef _ZEN_DRAWWORLDMAP_H
#define _ZEN_DRAWWORLDMAP_H

#include "OnePlayerSection.h"
#include "P2D/Pane.h"
#include "P2D/Picture.h"
#include "P2D/Screen.h"
#include "PlayerState.h"
#include "SoundMgr.h"
#include "nlib/Math.h"
#include "types.h"
#include "zen/DrawCommon.h"
#include "zen/DrawMenu.h"
#include "zen/DrawWMPause.h"
#include "zen/EffectMgr2D.h"
#include "zen/Number.h"
#include "zen/SpectrumCursorMgr.h"
#include "zen/ogDiary.h"

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
 * @brief Animation states for world map title objects
 */
BEGIN_ENUM_TYPE(TitleAnimState)
enum {
	Idle      = 0, // Title is stationary or hidden
	Appearing = 1, // Title is animating into view
	Hiding    = 2, // Title is animating out of view
} END_ENUM_TYPE;

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct WorldMapTitleObj {
public:
	WorldMapTitleObj()
	{
		mTitlePane = nullptr;
		mAnimState = TitleAnimState::Idle;
	}

	// weak:
	void update()
	{
		switch (mAnimState) {
		case TitleAnimState::Idle:
			break;
		case TitleAnimState::Appearing:
			if (move(0.25f)) {
				mAnimState = TitleAnimState::Idle;
			}
			break;
		case TitleAnimState::Hiding:
			if (move(0.5f)) {
				mAnimState = TitleAnimState::Idle;
				hide();
			}
			break;
		}
		STACK_PAD_VAR(1);
	}

	// DLL requires these inlines, they aren't in the list though, so fabricated name
	void init(P2DPane* titlePane)
	{
		mTitlePane = titlePane;
		mTitlePane->setOffset(mTitlePane->getWidth() >> 1, mTitlePane->getHeight() >> 1);
		mAnimState = TitleAnimState::Idle;
	}
	// probably? could be wait, maybe rename later
	void disappear()
	{
		mTitlePane->move(640, 480);
		mAnimState = TitleAnimState::Idle;
		hide();
	}
	void hide() { mTitlePane->hide(); }

	void show() { mTitlePane->show(); }

	// might be wait
	void appear()
	{
		mStartPos.set(640.0f, 30.0f, 0.0f);
		mTargetPos.set(40.0f, 30.0f, 0.0f);
		mAnimTimer = 0.0f;
		mAnimState = TitleAnimState::Appearing;
		show();
	}

	void wait()
	{
		mStartPos.set(mTitlePane->getPosH(), mTitlePane->getPosV(), 0.0f);
		mTargetPos.set(mStartPos.x, mStartPos.y - 320.0f, mStartPos.z);
		mAnimTimer = 0.0f;
		mAnimState = TitleAnimState::Hiding;
		show();
	}

protected:
	bool move(f32 time)
	{
		bool res = false;
		mAnimTimer += gsys->getFrameTime();
		if (mAnimTimer > time) {
			mAnimTimer = time;
			res        = true;
		}

		f32 t     = sinf(mAnimTimer / time * HALF_PI);
		f32 tComp = 1.0f - t;
		mTitlePane->move(zen::RoundOff(mStartPos.x * tComp + mTargetPos.x * t), zen::RoundOff(mStartPos.y * tComp + mTargetPos.y * t));
		return res;
	}

	int mAnimState;      // _00
	P2DPane* mTitlePane; // _04, could be a pane subtype
	f32 mAnimTimer;      // _08
	u8 _UNUSED0C[0x4];   // _0C, unknown
	Vector3f mStartPos;  // _10
	Vector3f mTargetPos; // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct DrawWorldMapDateCallBack : public P2DPaneCallBack, public zen::NumberTex {
public:
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

protected:
	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	// _04     = zen::NumberTex (empty)
	P2DPicture* mCentrePane; // _04, for single digit dates
	P2DPicture* mLeftPane;   // _08, for double digit dates
	P2DPicture* mRightPane;  // _0C, for double digit dates
};

/**
 * @brief Appearance states for course point animations
 */
BEGIN_ENUM_TYPE(CourseAppearState)
enum {
	Ready          = 0, // Course point is ready/idle
	RocketIncoming = 1, // Rocket is approaching (0.5s timer)
	Exploding      = 2, // Explosion effects playing (1.0s timer)
	Revealing      = 3, // Final reveal animation (1.0s timer)
} END_ENUM_TYPE;

/**
 * @brief TODO
 *
 * @note Size: 0x3C.
 */
struct WorldMapCoursePoint {
public:
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
		mAppearState   = CourseAppearState::Ready;
		mAppearTimer   = 0.0f;
		mIsVisible     = false;
		mUnselectedPic = nullptr;
		mSelectedPic   = nullptr;
		mStayPane      = nullptr;
		mLandPane      = nullptr;
		for (int i = 0; i < 4; i++) {
			mLinkPoints[i] = nullptr;
		}
	}

	// weak functions
	void select()
	{
		if (mIsVisible) {
			mUnselectedPic->hide();
			mSelectedPic->show();
			mSelectionLine->show();
		}
	}
	void setPane(P2DScreen* pointScreen, u32 tag1, u32 tag2, u32 tag3, P2DScreen* lineScreen, u32 tag4)
	{
		P2DPane* pointPane1 = pointScreen->search(tag1, true);
		if (pointPane1->getTypeID() == PANETYPE_Picture) {
			mUnselectedPic = (P2DPicture*)pointPane1;
			mUnselectedPic->setOffset(mUnselectedPic->getWidth() >> 1, mUnselectedPic->getHeight());
		}
		P2DPane* pointPane2 = pointScreen->search(tag2, true);
		if (pointPane2->getTypeID() == PANETYPE_Picture) {
			mSelectedPic = (P2DPicture*)pointPane2;
			mSelectedPic->setOffset(mSelectedPic->getWidth() >> 1, mSelectedPic->getHeight());
		}
		P2DPane* pointPane3 = pointScreen->search(tag3, true);
		if (pointPane3->getTypeID() == PANETYPE_Picture) {
			mOpenedPic = (P2DPicture*)pointPane3;
			mOpenedPic->setOffset(mSelectedPic->getWidth() >> 1, mSelectedPic->getHeight());
			mOpenedPic->hide();
		}
		mSelectionLine = lineScreen->search(tag4, true);
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
			mUnselectedPic->show();
			mSelectedPic->hide();
			mSelectionLine->hide();
		}
	}

	void openCourse()
	{
		mIsVisible = true;
		mUnselectedPic->hide();
		mSelectedPic->hide();
		mOpenedPic->show();
		mSelectionLine->hide();
	}
	void closeCourse()
	{
		mIsVisible = false;
		mUnselectedPic->hide();
		mSelectedPic->hide();
		mOpenedPic->hide();
		mSelectionLine->hide();
	}

	void appear()
	{
		mAppearTimer = 0.0f;
		mAppearState = CourseAppearState::RocketIncoming;
		mUnselectedPic->hide();
		mSelectedPic->hide();
		mOpenedPic->hide();
		mSelectionLine->hide();
	}

	P2DPane* getStayPane() { return mStayPane; }
	P2DPane* getLandPane() { return mLandPane; }
	WorldMapName getNumber() { return mGameStageID; }

	void createCourseInEffect()
	{
		P2DPicture* pic = mUnselectedPic;
		Vector3f vec1;
		vec1.set(pic->getPosH() + (pic->getWidth() >> 1), 480 - (pic->getPosV() + (pic->getHeight() >> 1)), 0.0f);
		WMeffMgr->create(EFF2D_MapRocketIn, vec1, nullptr, nullptr);
	}

	bool update(bool isSelected)
	{
		bool res   = false;
		mEventFlag = EVENT_NONE;
		switch (mAppearState) {
		case CourseAppearState::Ready:
			res = true;
			break;
		case CourseAppearState::RocketIncoming:
			f32 timer1 = mAppearTimer += gsys->getFrameTime();
			if (timer1 > 0.5f) {
				Vector3f vec1;
				vec1.set(mUnselectedPic->getPosH() + (mUnselectedPic->getWidth() >> 1),
				         480 - (mUnselectedPic->getPosV() + (mUnselectedPic->getHeight() >> 1)), 0.0f);
				WMeffMgr->create(EFF2D_MapAppear1, vec1, nullptr, nullptr);
				WMeffMgr->create(EFF2D_MapAppear2, vec1, nullptr, nullptr);
				SeSystem::playSysSe(SYSSE_SELECT_COURSEOPEN);
				mAppearState = CourseAppearState::Exploding;
				mAppearTimer = 0.0f;
			}
			break;
		case CourseAppearState::Exploding:
			f32 timer2 = mAppearTimer += gsys->getFrameTime();
			if (timer2 > 1.0f) {
				mAppearTimer = 0.0f;
				mAppearState = CourseAppearState::Revealing;
				mOpenedPic->show();
			}
			break;
		case CourseAppearState::Revealing:
			f32 timer3 = mAppearTimer += gsys->getFrameTime();
			if (timer3 > 1.0f) {
				mAppearTimer = 0.0f;
				mAppearState = CourseAppearState::Ready;
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

protected:
	u32 mEventFlag;                               // _00
	int mAppearState;                             // _04
	f32 mAppearTimer;                             // _08
	bool mIsVisible;                              // _0C
	WorldMapName mGameStageID;                    // _10
	P2DPicture* mUnselectedPic;                   // _14, x_N, N=1-5
	P2DPicture* mSelectedPic;                     // _18, x_Ns, N=1-5
	P2DPicture* mOpenedPic;                       // _1C, po0N, N=1-5
	P2DPane* mSelectionLine;                      // _20, sliN, N=1-5 - might be a sub-class
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
public:
	WorldMapTitleMgr()
	{
		mTitleObjects      = new WorldMapTitleObj[OBJ_NUM];
		mCurrentTitleIndex = -1;
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
		mCurrentTitleIndex = -1;
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
		if (mCurrentTitleIndex != scrID) {
			mCurrentTitleIndex = scrID;
			mTitleObjects[mCurrentTitleIndex].appear();
		}
	}

	void exitTitle()
	{
		if (mCurrentTitleIndex != -1) {
			mTitleObjects[mCurrentTitleIndex].wait();
			mCurrentTitleIndex = -1;
		}
	}

protected:
	static const int OBJ_NUM;

	WorldMapTitleObj* mTitleObjects; // _00, array of OBJ_NUM objects
	int mCurrentTitleIndex;          // _04
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
public:
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
			WMeffMgr->create(EFF2D_MapShootingStar, Vector3f(zen::Rand(640.0f), 500.0f - zen::Rand(50.0f), -zen::Rand(150.0f)), nullptr,
			                 nullptr);
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

protected:
	f32 mStarFallChance;   // _00, as a percent
	bool mIsRapidFireMode; // _04
};

/**
 * @brief Main operational modes for the world map screen
 */
BEGIN_ENUM_TYPE(DrawWorldMapMode)
enum {
	Null         = -1, // Invalid or uninitialized mode
	Start        = 0,  // Initial setup and transition in
	Appear       = 1,  // Course unlock animation playing
	Operation    = 2,  // Normal user interaction mode
	Paused       = 3,  // Pause menu is open
	Confirm      = 4,  // Course selection confirmation dialog
	DiaryClosing = 5,  // Transitioning to diary
	Diary        = 6,  // Captain's diary is open
	DiaryOpening = 7,  // Returning from diary
	End          = 8,  // Transition out of world map
} END_ENUM_TYPE;

/**
 * @brief TODO
 */
struct DrawWorldMap {
public:
	/**
	 * @brief Type of course unlock animation to play
	 */
	enum startModeFlag {
		None         = 0, // No unlock animation
		ForestUnlock = 1, // Forest of Hope unlock
		CaveUnlock   = 2, // Forest Navel unlock
		SpringUnlock = 3, // Distant Spring unlock
		FinalUnlock  = 4, // Final Trial unlock
	};

	/**
	 * @brief Starting course selection for world map
	 */
	enum startPlaceFlag {
		ImpactSite    = 0, // Start at Impact Site
		ForestHope    = 1, // Start at Forest of Hope
		ForestNavel   = 2, // Start at Forest Navel
		DistantSpring = 3, // Start at Distant Spring
		FinalTrial    = 4, // Start at Final Trial
	};

	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		RETURNSTATUS_Null = -1,          // Invalid or uninitialized flag
		RETURNSTATUS_UfoLandedPractice,  // See `DrawWorldMap::modeOperation`
		RETURNSTATUS_UfoLandedForest,    // ...
		RETURNSTATUS_UfoLandedCave,      // ...
		RETURNSTATUS_UfoLandedYakushima, // ...
		RETURNSTATUS_UfoLandedLast,      // ...
		RETURNSTATUS_WorldMapActive,     // See `DrawWorldMap::start`
		RETURNSTATUS_WorldMapPaused,     // See `DrawWorldMap::update`
	};

	DrawWorldMap();

	bool update(Controller*);
	void draw(Graphics&);
	void start(startModeFlag, startPlaceFlag);

	// unused/inlined:
	~DrawWorldMap();

	// DLL inlines:
	returnStatusFlag getReturnStatusFlag() { return mReturnStatus; }

protected:
	void setCoursePoint(startPlaceFlag);
	bool modeStart(Controller*);
	bool modeAppear(Controller*);
	bool modeOperation(Controller*);
	bool modeConfirm(Controller*);
	bool modeEnd(Controller*);
	void updateScreens();
	void closeMapInfo();
	void openMapInfo();

	startModeFlag mStartMode;                  // _00
	int mCurrentMode;                          // _04
	returnStatusFlag mReturnStatus;            // _08
	f32 mModeTimer;                            // _0C
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
