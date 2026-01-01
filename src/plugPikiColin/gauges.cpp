#include "LifeGauge.h"

#include "Colour.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Light.h"
#include "MoviePlayer.h"
#include "gameflow.h"
#include "sysMath.h"
#include "sysNew.h"
#include "system.h"

/// Life gauge border color for bar-style health gauges (grey by default, never used in-game).
static Colour lgborder;

/// Life gauge color for 1/4 health (red by default).
static Colour lglev0;

/// Below this health ratio, colour is red (lglev0).
#define LG_RED_RATIO (0.25f)

/// Life gauge color for 1/2 health (yellow by default).
static Colour lglev1;

/// Health ratio when colour is yellow (lglev1).
#define LG_YELLOW_RATIO (0.5f)

/// Life gauge color for 3/4 health (light green by default).
static Colour lglev2;

/// Health ratio when colour is light green (lglev2).
#define LG_LIGHT_GREEN_RATIO (0.75f)

/// Life gauge color for full health (green by default).
static Colour lglev3;

/// Health ratio when colour is green (lglev3).
#define LG_GREEN_RATIO (1.0f)

/// Number of triangles to break health gauge rendering into.
#define LG_TRIANGLE_COUNT (32)

/// Global life gauge manager instance.
LifeGaugeMgr* lgMgr;

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Gauges")

/**
 * @brief Primes the carry number to start fading in.
 * @note UNUSED Size: 000020
 */
void GaugeInfo::init()
{
	mState        = STATE_FadeIn;
	mFadeInPhase  = 0.0f;
	mDisplayAlpha = 0.0f;
	mHeightOffset = 0.0f;
	PRINT("gauge init\n");
	mIsPendingRemoval = FALSE;
}

/**
 * @brief Updates the carry number, handling display states and hide/removal triggers.
 */
void GaugeInfo::update()
{
	switch (mState) {
	case STATE_FadeIn: {
		// fade in, grow number, increase height offset over ~0.75s

		mFadeInPhase += gsys->getFrameTime() * 2.0f;
		if (mFadeInPhase >= HALF_PI) {
			mState = STATE_Visible;
		}

		f32 clampedPhase = mFadeInPhase < HALF_PI ? mFadeInPhase : HALF_PI;

		// do fade-in over the first quarter of a sine curve for nice smooth motion
		mDisplayAlpha    = sinf(clampedPhase) * 255.0f; // 0-255
		mHeightOffset    = sinf(clampedPhase) * 30.0f;  // 0-30
		mDigitHalfWidth  = sinf(clampedPhase) * 8.0f;   // 0-8
		mDigitHalfHeight = sinf(clampedPhase) * 8.0f;   // 0-8
		break;
	}

	case STATE_Visible:
		// check if gauge has been marked to remove/hide
		if (mIsPendingRemoval) {
			mState = STATE_FadeOut;
		}
		break;

	case STATE_FadeOut:
		// fade out text REALLY FAST
		mDisplayAlpha -= gsys->getFrameTime() * 1200.0f;
		if (mDisplayAlpha < 0.0f) {
			mDisplayAlpha = 0.0f;
			// add gauge to inactive list to be reused
			lgMgr->removeLG(this);
		}
	}
}

/**
 * @brief Queues a number (0-99) to the light flare manager to be drawn.
 *
 * @param centerPos Center position of the total number to be drawn.
 * @param colour Colour of the number.
 * @param number Number to draw, between 0 and 99. Numbers above 99 will be clamped to 99 (except in demo and JP).
 * @param digitHalfWidth The half-width size to draw each digit as.
 * @param digitHalfHeight The half-height size to draw each digit as.
 */
void GaugeInfo::showDigits(Vector3f centerPos, immut Colour& colour, int number, f32 digitHalfWidth, f32 digitHalfHeight)
{
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
	STACK_PAD_VAR(2);
	// NB: if number = 100, digits will start overlapping
	int num = number;
#else
	// clamp number to two digits, because that's all this is coded to handle
	// (in practice, I don't think anything can be carried/pushed by 100 Pikmin at once, but this is safer)
	int num = number > 99 ? 99 : number;
#endif

	int numDigits = num >= 10 ? 2 : 1;

	// if 2 digits, move the "ones" digit position to the right (since we draw that first)
	if (numDigits == 2) {
		// this ends up overlapping the digits very slightly, so they read as one number
		// (width of overlap is 1/4 of a digit)
		centerPos.x += digitHalfWidth * 1.5f * 0.5f;
	}

	// draw the digits - ones first (then tens if 2-digit)
	for (int i = 0; i < numDigits; i++) {
		f32 texEntryWidth = 1 / 11.0f; // 11 entries in the bti (0,1,2,3,4,5,6,7,8,9,-), each unit width

		// grab appropriate texture start/stop points for the ones digit
		f32 uvStart = (num % 10) * texEntryWidth;
		f32 uvEnd   = ((num % 10) + 1.0f) * texEntryWidth;

		// draw the colored texture digit (flare)
		lgMgr->mDigitFlareGroup->addLFlare(colour, centerPos, Vector2f(digitHalfWidth, digitHalfHeight), &Vector2f(uvStart, 0.0f),
		                                   &Vector2f(uvEnd, 1.0f));

		// get tens digit, in case it's a 2-digit number
		num /= 10;

		// adjust left to draw tens digit if required
		centerPos.x -= digitHalfWidth * 1.5f;
	}
	FORCE_DONT_INLINE;
}

/**
 * @brief Draws both top and bottom digits of the display, flat to screen.
 *
 * @param gfx Graphics context for rendering.
 */
void GaugeInfo::refresh(Graphics& gfx)
{
	Vector3f pos(mParentLifeGauge->mPosition.x, mParentLifeGauge->mPosition.y + mHeightOffset, mParentLifeGauge->mPosition.z);
	// project to screen space, so it's flat no matter the angle
	pos.multMatrix(gfx.mCamera->mLookAtMtx);

	// bottom value first (red, changing value showing how many Pikmin are lifting/pushing/moving the object)
	Colour colour;
	colour.set(255, 32, 32, (int)mDisplayAlpha);

	// makes a visually "dominant" value by scaling down the other digit to 75%
	// - when we're below the minimum number to move the object, make top value (target number) dominant
	// - when we're able to move the object, make bottom value (current number) dominant
	f32 bottomScale = (mStickCount < mMinCount) ? 0.75f : 1.0f;
	f32 topScale    = (mStickCount < mMinCount) ? 1.0f : 0.75f;

	// draw bottom digit (current number)
	showDigits(pos, colour, mStickCount, mDigitHalfWidth * bottomScale, mDigitHalfHeight * bottomScale);

	// draw dividing line 10 units above center of bottom value
	pos.y += 10.0f;
	// "-" is at the end of the 11 .bti digits, so UV goes from 10/11 to 11/11 (1)
	f32 uvEnd   = 1.0f;
	f32 uvStart = 10.0f / 11.0f;
	// add to flare queue to draw
	lgMgr->mDigitFlareGroup->addLFlare(colour, pos, Vector2f(mDigitHalfWidth, mDigitHalfHeight), &Vector2f(uvStart, 0.0f),
	                                   &Vector2f(uvEnd, 1.0f));

	// draw center of top number (blue, static value showing target amount to move object) 10 units above line
	pos.y += 10.0f;
	colour.set(32, 32, 255, (int)mDisplayAlpha);
	showDigits(pos, colour, mMinCount, mDigitHalfWidth * topScale, mDigitHalfHeight * topScale);

	STACK_PAD_VAR(1);
	FORCE_DONT_INLINE;
}

/**
 * @brief Initialises a fresh gauge list, and sets up carry number display texture information.
 *
 * @param maxGauges Maximum number of gauges to have active at any given time.
 */
void LifeGaugeMgr::init(int maxGauges)
{
	// reset active and inactive lists
	mActiveGaugeList.initCore("");
	mInactiveGaugeList.initCore("");

	GaugeInfo* gaugeList = new GaugeInfo[maxGauges];

	// set up inactive list to allocate gauges from
	for (int i = 0; i < maxGauges; i++) {
		mInactiveGaugeList.add(&gaugeList[i]);
	}

	// set up default drawing info for carry number displays
	mDigitFlareGroup             = gsys->registerLFlare(gsys->loadTexture("intro/item_0_9.bti", true));
	mDigitFlareGroup->mBlendMode = BLEND_AlphaTest;
}

/**
 * @brief Updates all active gauges.
 */
void LifeGaugeMgr::update()
{
	FOREACH_NODE(GaugeInfo, mActiveGaugeList.mChild, gauge)
	{
		gauge->update();
	}
}

/**
 * @brief Draws all active gauges (unless cutscene is playing, then draws none).
 *
 * @param gfx Graphics context for rendering.
 */
void LifeGaugeMgr::refresh(Graphics& gfx)
{
	if (!gameflow.mMoviePlayer->mIsActive) {
		FOREACH_NODE(GaugeInfo, mActiveGaugeList.mChild, gauge)
		{
			gauge->refresh(gfx);
		}
	}
}

/**
 * @brief Allocates a new gauge from the inactive list and initialises it.
 *
 * Does not add it to the active list.
 *
 * @return Pointer to newly initialised gauge from the inactive list; `nullptr` if no inactive gauges left to allocate.
 * @note UNUSED Size: 000080
 */
GaugeInfo* LifeGaugeMgr::getGaugeInfo()
{
	if (mInactiveGaugeList.mChild) {
		GaugeInfo* info = (GaugeInfo*)mInactiveGaugeList.mChild;
		info->init();
		info->del();
		info->initCore("");
		return info;
	}
	return nullptr;
}

/**
 * @brief Adds the given gauge to the active list.
 *
 * @param info Gauge to add to active list.
 * @note UNUSED Size: 000020
 */
void LifeGaugeMgr::addLG(GaugeInfo* info)
{
	mActiveGaugeList.add(info);
}

/**
 * @brief Removes the given gauge from the active list, and adds it to the inactive list.
 *
 * @param info Gauge to add to inactive list.
 */
void LifeGaugeMgr::removeLG(GaugeInfo* info)
{
	info->del();
	info->initCore("");
	mInactiveGaugeList.add(info);
}

/**
 * @brief Constructs a new life gauge with default values.
 *
 * Defaults to a (full health) bar-style life gauge which is always overwritten.
 */
LifeGauge::LifeGauge()
{
	mRenderStyle               = LifeGauge::Bar;
	mDisplayState              = STATE_Hidden;
	mFadeTransitionValue       = 0.0f;
	mVisibleHoldTimer          = 0.0f;
	mSnapToTargetHealth        = false;
	mCurrentDisplayHealthRatio = 1.0f;
	mTargetHealthRatio         = 1.0f;

	// every new life gauge that's created will re-set these common values, which feels... silly.
	lgborder.set(128, 128, 128, 192); // grey
	lglev3.set(0, 255, 0, 255);       // green
	lglev2.set(128, 255, 0, 255);     // light green
	lglev1.set(255, 255, 0, 255);     // yellow
	lglev0.set(255, 0, 0, 255);       // red

	mOffset.set(0.0f, 100.0f, 0.0f);
	mScale             = 48.0f;
	mActiveCarryNumber = nullptr;
}

/**
 * @brief Sets the reference health values for health gauge displays.
 *
 * @param currHealth Current health of the owner, for ratio calculation.
 * @param maxHealth Maximum health of the owner, for ratio calculation.
 */
void LifeGauge::updValue(f32 currHealth, f32 maxHealth)
{
	// sets the target rather than current, so we can have a gradual display increase if we want
	mTargetHealthRatio = currHealth / maxHealth;

	if (mTargetHealthRatio < 1.0f && mFadeTransitionValue != 1.0f) {
		// always display less-than-full health gauges (that aren't already displayed)
		mDisplayState = STATE_FadeIn;
	}
}

/**
 * @brief Updates health ratio to gradually change towards target (or snap to target if requested).
 * @note UNUSED Size: 00005C
 */
void LifeGauge::adjustValue()
{
	// slowly bring display value up to target
	mCurrentDisplayHealthRatio += 2.0f * gsys->getFrameTime() * (mTargetHealthRatio - mCurrentDisplayHealthRatio);

	// force display value to be target with no gradual increase if we ask nicely
	// (or if we're close enough to not make any visible difference)
	if (mSnapToTargetHealth || absF(mCurrentDisplayHealthRatio - mTargetHealthRatio) < 1.0f / 64.0f) {
		mCurrentDisplayHealthRatio = mTargetHealthRatio;
	}
}

/**
 * @brief Draws the current health gauge if required, and updates its display state.
 *
 * @param gfx Graphics context for rendering.
 */
void LifeGauge::refresh(Graphics& gfx)
{
	// don't draw life gauges during cutscenes
	if (gameflow.mMoviePlayer->mIsActive) {
		return;
	}

	switch (mDisplayState) {
	case STATE_FadeIn:
		adjustValue();
		mFadeTransitionValue += 2.0f * gsys->getFrameTime();
		if (mFadeTransitionValue > 1.0f) {
			// keep full health gauge visible for 5 seconds before hiding it
			mFadeTransitionValue = 1.0f;
			mDisplayState        = STATE_Display;
			mVisibleHoldTimer    = 5.0f;
		}
		break;

	case STATE_Display:
		adjustValue();
		mVisibleHoldTimer -= gsys->getFrameTime();
		if (mVisibleHoldTimer <= 0.0f) {
			mVisibleHoldTimer = 0.0f;
			if (mRenderStyle == LifeGauge::Bar || mCurrentDisplayHealthRatio <= 0.0f || mCurrentDisplayHealthRatio >= 1.0f) {
				// no point drawing full or empty health gauges for too long, hide it again
				mDisplayState = STATE_FadeOut;
			}
		}
		break;

	case STATE_FadeOut:
		mFadeTransitionValue -= 2.0f * gsys->getFrameTime();
		if (mFadeTransitionValue < 0.0f) {
			// fade out finished
			mFadeTransitionValue = 0.0f;
			mDisplayState        = STATE_Hidden;
		}
		break;
	}

	if (mDisplayState == STATE_Hidden) {
		// don't waste resources trying to draw hidden health gauges
		return;
	}

	Colour gaugeColour;
	if (mCurrentDisplayHealthRatio > LG_LIGHT_GREEN_RATIO) {
		// lerp between green and light green
		lglev3.lerpTo(lglev2, 1.0f - (mCurrentDisplayHealthRatio - LG_LIGHT_GREEN_RATIO) / (LG_GREEN_RATIO - LG_LIGHT_GREEN_RATIO),
		              gaugeColour);
	} else if (mCurrentDisplayHealthRatio > LG_YELLOW_RATIO) {
		// lerp between light green and yellow
		lglev2.lerpTo(lglev1, 1.0f - (mCurrentDisplayHealthRatio - LG_YELLOW_RATIO) / (LG_LIGHT_GREEN_RATIO - LG_YELLOW_RATIO),
		              gaugeColour);
	} else if (mCurrentDisplayHealthRatio > LG_RED_RATIO) {
		// lerp between yellow and red
		lglev1.lerpTo(lglev0, 1.0f - (mCurrentDisplayHealthRatio - LG_RED_RATIO) / (LG_YELLOW_RATIO - LG_RED_RATIO), gaugeColour);
	} else {
		// last quarter health is always the same red
		gaugeColour = lglev0;
	}

	gfx.useTexture(nullptr, GX_TEXMAP0);
	Vector3f pos1 = mPosition + mOffset; // ma'am these are the same
	Vector3f pos2 = mPosition + mOffset;

	f32 depth1 = gfx.mCamera->projectWorldPoint(gfx, pos1); // which means these are the same
	f32 depth2 = gfx.mCamera->projectWorldPoint(gfx, pos2);

	gfx.setColour(COLOUR_WHITE, true);
	gfx.setAuxColour(COLOUR_WHITE);

	STACK_PAD_VAR(2);

	// don't bother drawing points behind the camera (negative depths)
	if (depth1 > 0.0f && depth2 > 0.0f) {
		if (mRenderStyle == LifeGauge::Bar) {
			// never used in-game, but fun!
			// draw border of bar gauge
			gfx.setColour(Colour(lgborder.r, lgborder.g, lgborder.b, (int)(f32(lgborder.a) * mFadeTransitionValue)), true);
			gfx.setAuxColour(Colour(lgborder.r, lgborder.g, lgborder.b, (int)(f32(lgborder.a) * mFadeTransitionValue)));
			gfx.lineRectangle(RectArea(pos2.x - 19.0f, pos2.y - 10.0f, pos2.x + 19.0f, pos2.y - 6.0f));

			// draw text bubble-like callout lines
			gfx.drawLine(Vector3f(pos2.x - 10.0f, pos2.y - 5.0f, 0.0f), Vector3f(pos1.x, pos1.y, 0.0f));
			gfx.drawLine(Vector3f(pos2.x - 5.0f, pos2.y - 5.0f, 0.0f), Vector3f(pos1.x, pos1.y, 0.0f));

			// draw coloured part of gauge
			gfx.setColour(Colour(gaugeColour.r, gaugeColour.g, gaugeColour.b, (int)(f32(gaugeColour.a) * mFadeTransitionValue)), true);
			gfx.setAuxColour(Colour(gaugeColour.r, gaugeColour.g, gaugeColour.b, (int)(f32(gaugeColour.a) * mFadeTransitionValue)));
			gfx.fillRectangle(
			    RectArea(pos2.x - 18.0f, pos2.y - 9.0f, pos2.x - 18.0f + (mCurrentDisplayHealthRatio * 37.0f), pos2.y - 7.0f));
		} else {
			f32 innerRadius = mScale * (1.0f - depth1); // radius of the actual coloured section
			f32 outerRadius = innerRadius * 1.1666f;    // radius of the background black circle

			Vector3f vertices[4]; // buffer for points to draw

			// these are blank, since we don't actually draw any textures
			Vector2f texCoords[4];
			texCoords[0].set(0.0f, 0.0f);
			texCoords[1].set(0.0f, 0.0f);
			texCoords[2].set(0.0f, 0.0f);
			texCoords[3].set(0.0f, 0.0f);

			for (int i = 0; i < LG_TRIANGLE_COUNT; i++) {
				// draw triangles from 12 o'clock anti-clockwise
				f32 startAngle = f32(i) * ((360.0f / LG_TRIANGLE_COUNT) * PI / 180.0f);
				f32 endAngle   = f32((i + 1) % 32) * ((360.0f / LG_TRIANGLE_COUNT) * PI / 180.0f);
				vertices[0].set(pos2.x, pos2.y, 0.0f);
				vertices[1].set(sinf(endAngle) * -innerRadius + pos2.x, cosf(endAngle) * -innerRadius + pos2.y, 0.0f);
				vertices[2].set(sinf(startAngle) * -innerRadius + pos2.x, cosf(startAngle) * -innerRadius + pos2.y, 0.0f);

				// colour triangles "health" coloured until we hit our health ratio around the circle
				if ((mCurrentDisplayHealthRatio > 0.0f && i == 0) || i < int(LG_TRIANGLE_COUNT * mCurrentDisplayHealthRatio)) {
					gfx.setColour(gaugeColour, true);
					gfx.drawOneTri(vertices, nullptr, texCoords, 3);
				} else {
					// draw remaining triangles a slightly transparent dark grey
					gfx.setColour(Colour(32, 32, 32, 192), true);
					gfx.drawOneTri(vertices, nullptr, texCoords, 3);
				}

				// draw small black box on outside edge of triangle, to form the "background" black circle
				vertices[0].set(sinf(endAngle) * -innerRadius + pos2.x, cosf(endAngle) * -innerRadius + pos2.y, 0.0f);
				vertices[1].set(sinf(endAngle) * -outerRadius + pos2.x, cosf(endAngle) * -outerRadius + pos2.y, 0.0f);
				vertices[2].set(sinf(startAngle) * -outerRadius + pos2.x, cosf(startAngle) * -outerRadius + pos2.y, 0.0f);
				vertices[3].set(sinf(startAngle) * -innerRadius + pos2.x, cosf(startAngle) * -innerRadius + pos2.y, 0.0f);

				gfx.setColour(COLOUR_BLACK, true);
				gfx.drawOneTri(vertices, nullptr, texCoords, 4);
			}
		}
	}
}

/**
 * @brief Makes a carry (or box pushing) number display visible, or updates its values if already visible.
 *
 * @param position Reference position - center of bottom number is drawn 30 units above this.
 * @param stickCount Number to draw on the bottom - how many Pikmin are trying to move the object?
 * @param minCount Number to draw on the top - how many Pikmin are required to move the object?
 */
void LifeGauge::countOn(immut Vector3f& position, int stickCount, int minCount)
{
	if (!mActiveCarryNumber) {
		// set up a carry number gauge info

		// the health ratio is never used in this situation, since the health display wheel/bar is hidden
		mCurrentDisplayHealthRatio = stickCount;
		mDisplayState              = STATE_Hidden;
		mVisibleHoldTimer          = 0.0f;

		// idk why we'd magically have one now but fine, double confirm we don't
		if (mActiveCarryNumber) {
			mActiveCarryNumber->mIsPendingRemoval = TRUE;
			mActiveCarryNumber                    = nullptr;
		}

		// allocate a new gauge from the inactive list
		GaugeInfo* info = lgMgr->getGaugeInfo();
		if (info) {
			// set up gauge
			info->mParentLifeGauge = this;
			info->mStickCount      = stickCount;
			info->mMinCount        = minCount;

			// add it to manager so it gets drawn
			lgMgr->addLG(info);
			mActiveCarryNumber = info;
		}
	} else {
		// already have a visible carry number, just update the values
		mActiveCarryNumber->mStickCount = stickCount;
		mActiveCarryNumber->mMinCount   = minCount;
	}

	// update the carry numbers position
	mPosition = position;
	if (mActiveCarryNumber) {
		// this is never used
		mActiveCarryNumber->mCachedOwnerPosition = mPosition;
	}

	STACK_PAD_VAR(1);
}

/**
 * @brief Documentation
 */
void LifeGauge::countOff()
{
	mDisplayState     = STATE_Inactive;
	mVisibleHoldTimer = 0.0f;
	// flag that we should hide the carry number
	if (mActiveCarryNumber) {
		mActiveCarryNumber->mIsPendingRemoval = TRUE;
		mActiveCarryNumber                    = nullptr;
	}
}
