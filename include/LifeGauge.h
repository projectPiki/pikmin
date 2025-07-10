#ifndef _LIFEGAUGE_H
#define _LIFEGAUGE_H

#include "Colour.h"
#include "CoreNode.h"
#include "Material.h"
#include "Vector.h"
#include "types.h"

struct Colour;
struct Graphics;
struct LifeGauge;
struct LFlareGroup;

/**
 * @brief TODO
 *
 * @note Size: 0x48.
 */
struct GaugeInfo : public CoreNode {
	GaugeInfo()
	    : CoreNode("")
	{
		mOwner = 0;
	}

	void update();
	void showDigits(Vector3f, Colour&, int, f32, f32);
	void refresh(Graphics&);

	// unused/inlined:
	void init();

	// _00     = VTBL
	// _00-_14 = CoreNode
	LifeGauge* mOwner;             // _14
	u32 mUpdateState;              // _18
	int mPrimaryValue;             // _1C
	int mSecondaryValue;           // _20
	int mIsPendingRemoval;         // _24
	Vector3f mOwnerCachedPosition; // _28
	f32 mAnimationPhase;           // _34
	f32 mHeightOffset;             // _38
	f32 mTextAlpha;                // _3C
	f32 mDigitBaseWidth;           // _40
	f32 mDigitBaseHeight;          // _44
};

/**
 * @brief TODO
 */
struct LifeGaugeMgr {
	LifeGaugeMgr() { init(66); }

	void init(int);
	void update();
	void refresh(Graphics&);
	GaugeInfo* getGaugeInfo();
	void addLG(GaugeInfo*);
	void removeLG(GaugeInfo*);

	GaugeInfo mActiveGaugeList;   // _00
	GaugeInfo mInactiveGaugeList; // _48
	LFlareGroup* mLFlare;         // _90
	Material _94;                 // _94
};

/**
 * @brief TODO
 */
struct LifeGauge {
	enum RenderStyle {
		Bar, // The always-overwritten default.
		Wheel,
	};

	LifeGauge();

	void updValue(f32, f32);
	void adjustValue();
	void refresh(Graphics&);
	void countOn(Vector3f&, int, int);
	void countOff();

	Vector3f mPosition;             // _00
	Vector3f mOffset;               // _0C
	int mDisplayState;              // _18
	RenderStyle mRenderStyle;       // _1C
	bool mSnapToTargetHealth;       // _20
	f32 mFadeTransitionValue;       // _24
	f32 mVisibleHoldTimer;          // _28
	f32 mHealthRatio;               // _2C, aka "value"
	f32 mCurrentDisplayHealthRatio; // _30
	f32 mScale;                     // _34
	GaugeInfo* mActiveGauge;        // _38
};

extern LifeGaugeMgr* lgMgr;

#endif
