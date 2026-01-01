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
 * @brief Manages and draws carry numbers (X / Y) - variable text numbers above objects.
 *
 * Used for both `Pellet` carry numbers and `HinderRock` pushable amounts.
 * `GaugeInfo`s must be connected to a `LifeGauge`, though in practice they are never drawn together.
 *
 * @note Size: 0x48.
 */
struct GaugeInfo : public CoreNode {

	/**
	 * @brief States that gauge numbers go through while updating.
	 */
	enum State {
		STATE_FadeIn  = 0,
		STATE_Visible = 1,
		STATE_FadeOut = 2,
	};

	/// Constructs an empty info with no associated life gauge.
	GaugeInfo()
	    : CoreNode("")
	{
		mParentLifeGauge = nullptr;
	}

	void update();
	void showDigits(Vector3f centerPos, immut Colour& colour, int number, f32 digitHalfWidth, f32 digitHalfHeight);
	void refresh(Graphics& gfx);

	// unused/inlined:

	void init();

	// _00     = VTBL
	// _00-_14 = CoreNode
	LifeGauge* mParentLifeGauge;   ///< _14, life gauge associated with this display.
	u32 mState;                    ///< _18, state the gauge display is in.
	int mStickCount;               ///< _1C, number of Pikmin currently stuck to/trying to move object (denominator, in red).
	int mMinCount;                 ///< _20, number of Pikmin required to pick up/move object (numerator, in blue)
	BOOL mIsPendingRemoval;        ///< _24, flag for whether display should fade out and hide.
	Vector3f mCachedOwnerPosition; ///< _28, owner position - stored but never used (grabs position from owner directly when drawing).
	f32 mFadeInPhase;              ///< _34, phase/angle used in fade-in/growing animation - in radians, takes pi/4 sec to fade in at 30fps.
	f32 mHeightOffset;             ///< _38, current vertical offset above the life gauge position (0-30 fade in).
	f32 mDisplayAlpha;             ///< _3C, current alpha for the display (0-255 fade in).
	f32 mDigitHalfWidth;           ///< _40, half-width of digits to display (0-8 fade in). Scaled down to 75% for non-dominant number.
	f32 mDigitHalfHeight;          ///< _44, half-height of digits to display (0-8 fade in). Scaled down to 75% for non-dominant number.
};

/**
 * @brief Manages, updates, and renders all active carry number (and box pushing) display (`GaugeInfo`s).
 *
 * Despite the name, this only really handles carry number displays. Circular `LifeGauge`s are handled by their owner `Creature`.
 *
 * @note Size: 0x130.
 */
struct LifeGaugeMgr {

	/// Constructs a new life gauge manager with up to 66 carry number gauges active at once.
	LifeGaugeMgr() { init(66); }

	void init(int maxGauges);
	void update();
	void refresh(Graphics& gfx);
	GaugeInfo* getGaugeInfo();
	void addLG(GaugeInfo* info);
	void removeLG(GaugeInfo* info);

	GaugeInfo mActiveGaugeList;    ///< _00, list of actively displayed carry numbers.
	GaugeInfo mInactiveGaugeList;  ///< _48, list of inactive carry numbers, to be assigned.
	LFlareGroup* mDigitFlareGroup; ///< _90, light flare group for displaying carry numbers.
	Material _94;                  ///< _94, unused material, never initialised or referenced.
};

/**
 * @brief Information about a single health gauge for a `Creature`.
 *
 * The bulk of this structure is for health gauges (green-to-red circles in-game).
 * The associated `mActiveCarryNumber` is for carry numbers - both are never drawn at the same time.
 * Drawing of the health gauges is handled by the owner `Creature`, while drawing of the carry number is handled by the global
 * `LifeGaugeMgr`.
 *
 * @note Size: 0x3C.
 */
struct LifeGauge {

	/**
	 * @brief TODO
	 */
	enum RenderStyle {
		Bar,   ///< 0, render gauge as a horizontal bar - the always-overwritten default.
		Wheel, ///< 1, render gauge as a circle/wheel - always used in-game.
	};

	/**
	 * @brief TODO
	 */
	enum DisplayState {
		STATE_Inactive = -1, ///< -1, inactive.
		STATE_Hidden,        ///< 0, not currently rendered.
		STATE_FadeIn,        ///< 1, fading in.
		STATE_Display,       ///< 2, steady visible display.
		STATE_FadeOut,       ///< 3, fading out.
	};

	LifeGauge();

	void updValue(f32 currHealth, f32 maxHealth);
	void adjustValue();
	void refresh(Graphics& gfx);
	void countOn(immut Vector3f& position, int stickCount, int minCount);
	void countOff();

	Vector3f mPosition;             ///< _00
	Vector3f mOffset;               ///< _0C
	int mDisplayState;              ///< _18
	RenderStyle mRenderStyle;       ///< _1C
	bool mSnapToTargetHealth;       ///< _20
	f32 mFadeTransitionValue;       ///< _24
	f32 mVisibleHoldTimer;          ///< _28
	f32 mTargetHealthRatio;         ///< _2C, aka "value"
	f32 mCurrentDisplayHealthRatio; ///< _30
	f32 mScale;                     ///< _34
	GaugeInfo* mActiveCarryNumber;  ///< _38
};

extern LifeGaugeMgr* lgMgr;

#endif
