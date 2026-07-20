#ifndef _ZEN_OGRADER_H
#define _ZEN_OGRADER_H

#include "GlobalGameOptions.h"
#include "Vector.h"
#include "types.h"

class P2DPane;
class P2DPicture;
class Controller;
class Graphics;
class P2DScreen;

namespace zen {

struct PikaAlphaMgr;

struct ogRaderMgr {
public:
	// Completely fabricated struct
	struct PikiRaderEntry {
		P2DPicture* mPic; // _00
		s16 mColor;       // _04
	};

	/**
	 * @brief TODO
	 */
	enum RaderStatus {
		STATE_INACTIVE      = -1,
		STATE_ACTIVE_ZOOM_2 = 0,
		STATE_ACTIVE_ZOOM_4 = 1,
		STATE_ACTIVE_ZOOM_8 = 2,
		STATE_ACTIVE_MAX    = 3,
		STATE_FADE_IN       = 4,
		STATE_FADE_OUT      = 5,
		STATE_HIDDEN        = 6,
		STATE_END_PENDING   = 7,
		// TODO: this
	};

	enum RaderControlMode {
		CONTROL_GAME = 0,
		CONTROL_MENU = 1,
	};

	P2DScreen* getScrPtr() { return mMainScreen; }

	ogRaderMgr();

	void startMenu(P2DPane*);
	void end();
	void MapOn();
	RaderStatus update(Controller*);
	void draw(Graphics&);
	void start();
	void MapOff();

private:
	Vector3f ogCalcDispXZ(Vector3f);
	void setRaderScale(f32);
	void chaseRaderScale(f32);
	void setRaderAngle(f32);
	void setRaderScroll(int, int);
	void getOrimaPos();
	void getContainerPos();
	void getRocketPos();
	void getPartsPos();
	void getAllPikiPos();
	void startSub();
	void updateGame(Controller*);
	void AreaScroll(f32*, f32*, f32, f32);
	void updateMenu(Controller*);
	void RotatePos(f32*, f32*);
	void DrawCircle(u8, u8, u8, u8, f32);

	bool mIsScrollSeActive;        // _00
	bool mIsZoomInSeActive;        // _01
	bool mIsZoomOutSeActive;       // _02
	RaderControlMode mControlMode; // _04
	RaderStatus mStatus;           // _08
	f32 mCenterX;                  // _0C
	f32 mCenterY;                  // _10
	int mScissorX;                 // _14
	int mScissorY;                 // _18
	int mScissorWidth;             // _1C
	int mScissorHeight;            // _20
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
	Vector3f mDemoAreaCorners[4]; // _24
#endif
	f32 mMapAreaCenterX;                    // _24
	f32 mMapAreaCenterZ;                    // _28
	f32 mMapAreaRadius;                     // _2C
	f32 mRangeCirclePulseTimer;             // _30
	f32 mScrollOffsetX;                     // _34
	f32 mScrollOffsetY;                     // _38
	P2DScreen* mMainScreen;                 // _3C
	P2DPicture* mContainerIcons[3];         // _40
	P2DPicture* mStageMapPicture;           // _4C
	PikaAlphaMgr* mAlphaMgr;                // _50
	int mStageId;                           // _54
	P2DPane* mRootPane;                     // _58
	P2DPicture* mBluePikiIconTemplate;      // _5C
	P2DPicture* mRedPikiIconTemplate;       // _60
	P2DPicture* mYellowPikiIconTemplate;    // _64
	P2DPicture* mSeedIconTemplate;          // _68
	P2DPicture* mOlimarIcon;                // _6C
	P2DPicture* mBlueContainerIcon;         // _70
	P2DPicture* mRedContainerIcon;          // _74
	P2DPicture* mYellowContainerIcon;       // _78
	P2DPicture* mRocketIcon;                // _7C
	P2DPicture* mPartIconTemplate;          // _80
	P2DPicture* mPartIcons[MAX_UFO_PARTS];  // _84
	s16 mVisiblePikiCount;                  // _FC
	PikiRaderEntry mPikiEntries[MAX_PIKI_ON_FIELD]; // _100
	P2DPicture* mMapPicture;                        // _420
	P2DPane* mIconPane;                             // _424
	f32 mCurrentScale;                              // _428
	f32 mTargetScale;                               // _42C
	Vector3f mOlimarWorldPos;                       // _430
	Vector3f mOlimarMapPos;                         // _43C
	int mOlimarMapPosX;                             // _448
	int mOlimarMapPosY;                             // _44C
	f32 mOlimarIconAngle;                           // _450
	f32 mMapRotationAngle;                          // _454
	s16 mCurrentMapAlpha;                           // _458
	s16 mTargetMapAlpha;                            // _45A
};

} // namespace zen

#endif
