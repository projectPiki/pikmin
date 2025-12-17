#ifndef _ZEN_OGMENU_H
#define _ZEN_OGMENU_H

#include "Colour.h"
#include "P2D/Screen.h"
#include "Vector.h"
#include "nlib/Math.h"
#include "system.h"
#include "types.h"

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
public:
	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		// TODO: this
	};

	ogDrawScrMenu();

	returnStatusFlag update(Controller*, bool, bool);

	// unused/inlined:
	void setScreen(immut char*);
	void calcAngleSpeed(f32);
	bool draw(Graphics&);

	bool chkStopAngle()
	{
		if (mCurrentAngle == mTargetAngle && mAngularVelocity == 0.0f) {
			return true;
		}
		return false;
	}
	P2DPane* getRoot() { return mRootPane; }
	P2DScreen* getPsc() { return mScreen; }
	void setAngle(f32 a)
	{
		mCurrentAngle = a;
		mTargetAngle  = a;
	}
	void setMaxR(f32 a) { mOrbitRadius = a; }
	void start(int state)
	{
		mInitialState = state;
		setAngle((f32)(state - 1) * TAU / 6.0f);
		setMaxR(600.0f);
		mAngularVelocity = 0.0f;

		mRootPane->move((mOrbitRadius * NMathF::sin(mCurrentAngle)), 0, (-mOrbitRadius * NMathF::cos(mCurrentAngle)) + mOrbitRadius);
		mRootPane->rotate(320, 240, P2DROTATE_Y, -mCurrentAngle);
	}

private:
	P2DScreen* mScreen;                   // _00
	returnStatusFlag mUpdateResultStatus; // _04
	P2DPane* mRootPane;                   // _08
	f32 mCurrentAngle;                    // _0C
	f32 mTargetAngle;                     // _10
	f32 mAngularVelocity;                 // _14
	int mMenuDisplayMode;                 // _18
	f32 mOrbitRadius;                     // _1C
	s16 mInitialState;                    // _20
};

/**
 * @brief TODO
 */
struct ogDrawScrController {
public:
	ogDrawScrController();

	void setOriginalColor();
	void setHantenColor();
	void update();

	// There's no way this wasn't public.
	ogDrawScrMenu mControllerScreenMenu; // _00

private:
	void setWinColor();

	P2DPicture* mButtonMaskPanes[9];             // _24
	P2DPicture* mButtonBasePanes[9];             // _48
	P2DTextBox* mButtonTextBoxes[9];             // _6C
	P2DPicture* mButtonBackgroundWindowPanes[9]; // _90
	P2DPicture* mMasterBackgroundWindowPane;     // _B4
	s16 mCurrentButtonIndex;                     // _B8
	f32 mCycleTimer;                             // _BC
	f32 mFlashTimer;                             // _C0
	Colour mHighlightWhiteColor;                 // _C4
	Colour mHighlightBlackColor;                 // _C8
	int _CC;                                     // _CC
	bool mIsColorInverted;                       // _D0
};

/**
 * @brief TODO
 */
struct ogDrawScrInfo {
public:
	ogDrawScrInfo();

	void start();

	// unused/inlined:
	void update(Controller*);

	// There's no way this wasn't public.
	ogDrawScrMenu mInfoScreenMenu; // _00

private:
	int _24;                         // _24
	P2DPane* mStageTitlePanes[5];    // _28
	P2DPane* mRootPane;              // _3C
	P2DPane* mRadarMovementPane;     // _40
	P2DPane* mRadarZoomPane;         // _44
	int _48[7];                      // _48
	P2DPane* mRedPikminFieldPane;    // _64
	P2DPane* mRedPikminTotalPane;    // _68
	P2DPane* mBluePikminFieldPane;   // _6C
	P2DPane* mBluePikminTotalPane;   // _70
	P2DPane* mYellowPikminFieldPane; // _74
	P2DPane* mYellowPikminTotalPane; // _78
	int mRedPikminInSquadCount;      // _7C
	int mBluePikminInSquadCount;     // _80
	int mYellowPikminInSquadCount;   // _84
	int mRedPikminTotalCount;        // _88
	int mBluePikminTotalCount;       // _8C
	int mYellowPikminTotalCount;     // _90
	int mCurrentShipPartsCount;      // _94
	int mTotalShipPartsCount;        // _98
	int mPikminInSquadAndOnionCount; // _9C
	int mFieldPikminCount;           // _A0
};

struct ogDrawScrInfo2 {
public:
	ogDrawScrInfo2(); // unused/inlined

	// unused/inlined:
	void start();
	void update(Controller*);
	void drawHougaku(Graphics&);

	P2DPane* getPaneMaps() { return mMapsPane; }

	// There's no way this wasn't public.
	ogDrawScrMenu mMinimapScreenMenu; // _00

private:
	P2DPane* mMapsPane;               // _24
	Vector3f mMapAnchorPosition;      // _28
	P2DPane* mDirectionArrowPane;     // _34
};

// This struct is completely inlined
struct ogDrawLR {
public:
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
		_14      = NMathF::sin(-_10) * 0.25f + 0.75f;
		_18      = NMathF::sin(-_10) * 0.25f + 0.75f;
		_1C      = NMathF::cos(-_10) * 0.125f + 0.875f;
		_08->setOffset(48, 48);
		_0C->setOffset(0, 48);
		_08->setScale(_14, _1C, 1.0f);
		_0C->setScale(_18, _1C, 1.0f);
		_10 += time / 0.016666666f * 0.2f; // 0.016666666f = 1/60
		if (_10 >= TAU) {
			_10 -= TAU;
		}
	}

private:
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
public:
	/**
	 * @brief Defines the operational states of the screen menu manager.
	 */
	enum returnStatusFlag {
		STATE_Inactive      = -1, // The manager is idle and not displaying any menu.
		STATE_ActiveDisplay = 0,  // Menu is fully displayed and active, awaiting user interaction.
		STATE_FadingIn      = 1,  // Menu is currently fading into view. Element scale and overlay alpha are progressively increased.
		STATE_FadingOut     = 2,  // Menu is currently fading out of view. Element scale and overlay alpha are progressively decreased.
		STATE_TransitionToInactive = 3, // A transitional state after fading out, leading to the manager becoming fully inactive.
	};

	ogScrMenuMgr();

	returnStatusFlag update(Controller*);
	void start();
	bool draw(Graphics&);

private:
	void updateInfo(Controller*);
	void updateCont(Controller*);

	returnStatusFlag mStatus;               // _00
	s16 mCurrentScreenIndex;                // _04
	P2DScreen* mBlackScreen;                // _08
	P2DPicture* mFadeOverlayPane;           // _0C
	ogDrawLR* mLeftRightIndicator;          // _10
	ogRaderMgr* mRadarManager;              // _14
	ogDrawScrMenu* mScreenMenus[3];         // _18
	int _24[3];                             // _24
	P2DPane* mScreenRootPanes[3];           // _30
	int _3C[3];                             // _3C
	ogDrawScrInfo* mInfoScreen;             // _48
	ogDrawScrController* mControllerScreen; // _4C
	ogDrawScrInfo2* mMinimapScreen;         // _50
	bool mSwitchLeftRequested;              // _54
	bool mSwitchRightRequested;             // _55
	f32 mTransitionTimer;                   // _58
	u8 mTransitionCalcAlpha;                // _5C
	u8 mAlpha;                              // _5D
	Vector3f mRadarScaleVector;             // _60
};

// unused global functions:
void ChkAngle(f32*);

} // namespace zen

#endif
