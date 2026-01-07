#include "timers.h"
#include "DebugLog.h"
#include "Font.h"
#include "Graphics.h"
#include "sysNew.h"
#include "system.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Timers")

/**
 * @todo: Documentation
 */
void Timers::reset()
{
	mTimerList  = nullptr;
	mTimerCount = 0;
}

/**
 * @todo: Documentation
 */
void Timers::newFrame()
{
	mFrameCount++;
}

/**
 * @todo: Documentation
 */
void Timers::_start(immut char* name, bool set)
{
#if defined(DEVELOP) || defined(VERSION_G98E01_PIKIDEMO)
	if (gsys->mTimerState != TS_Full && set) {
		return;
	}

	for (TimerInf* info = mTimerList; info; info = info->mNext) {
		if (strcmp(info->mTimerName, name) == 0) {
			info->mStartTime = gsys->getTime();
			return;
		}
	}

	TimerInf* newInfo = new TimerInf(name);
	newInfo->_20      = !set;

	TimerInf* info  = mTimerList;
	TimerInf* other = nullptr;
	for (info; info; info = info->mNext) {
		if (info->_20) {
			break;
		}
		other = info;
	}

	if (other) {
		newInfo->mNext = info;
		other->mNext   = newInfo;
	} else {
		newInfo->mNext = info;
		mTimerList     = newInfo;
	}

	newInfo->mStartTime = gsys->getTime();
	mTimerCount++;

#endif
}

/**
 * @todo: Documentation
 */
void Timers::_stop(immut char* name)
{
#if defined(DEVELOP) || defined(VERSION_G98E01_PIKIDEMO)
	for (TimerInf* info = mTimerList; info; info = info->mNext) {
		if (strcmp(info->mTimerName, name) == 0) {
			info->mDuration += (gsys->getTime() - info->mStartTime);
			break;
		}
	}
#endif
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void Timers::showTimes()
{
	for (TimerInf* info = mTimerList; info; info = info->mNext) {
		PRINT("timer : %s = %f\n", info->mTimerName, info->mAverageTime);
	}
}

// BUG: This assumes the game is running at 60fps, when (most of the time) it is not.
#define MILLISEC_PER_FRAME (1000.0f / 60.0f)

/**
 * @todo: Documentation
 */
void Timers::draw(Graphics& gfx, Font* font)
{
#if defined(DEVELOP) || defined(VERSION_G98E01_PIKIDEMO)
	gfx.useTexture(nullptr, GX_TEXMAP0);

	// Calculate the peak and average times of the various subsystems now.
	for (TimerInf* info = mTimerList; info; info = info->mNext) {
		// For the average time, we measure 10 frames worth of data.
		info->mSampleTime++;
		if (info->mSampleTime == 10) {
			info->mAverageTime = info->mDuration / 10.0f;
			// This function even handles time-travelling!  Wow!
			if (info->mAverageTime < 0.0f) {
				info->mAverageTime = 0.0f;
			}
			// Establish a new peak time if the average time exceeds it.
			if (info->mAverageTime > info->mPeakTime) {
				// And hold that mark of shame on the chart for 10 seconds.
				info->mDecayTime = 10.0f;
				info->mPeakTime  = info->mAverageTime;
			}
			info->mDuration   = 0.0f;
			info->mSampleTime = 0;
		}

		info->mDecayTime -= gsys->getFrameTime();
		// If enough time has passed since the last lag-spike, start wiping it away.
		if (info->mDecayTime < 0.0f && info->mPeakTime > 0.0f) {
			info->mPeakTime -= 6.0f * gsys->getFrameTime();
			if (info->mPeakTime < 0.0f) {
				info->mPeakTime = 0.0f;
			}
		}
	}

	// Making these three named constants `const` breaks the stack for matching.  Lovely `const` memes!
	immut f32 chartMarginSize = TERNARY_BUGFIX(256.0f, 192.0f);
	immut int chartTimeScale  = 4; // How many multiples of `MILLISEC_PER_FRAME` to fit on the chart
	immut int chartBarHeight  = 12;

	// Further calculations on how to draw the timers chart.
	const f32 chartWidth     = gfx.mScreenWidth - chartMarginSize;
	const f32 chartTickWidth = chartWidth / chartTimeScale;
	const f32 local_24       = chartWidth; // unused
	const f32 chartHeight    = (f32)mTimerCount * chartBarHeight + 32.0f;
	const f32 local_2c       = gfx.mScreenWidth / 2 - chartWidth / 2.0f; // upper-left origin of the chart
	const f32 chartOriginY   = gfx.mScreenHeight - chartHeight;          // upper-left origin of the chart

	// These really didn't need to exist, but they do according to the DLL, and `chartOriginX` is load-bearing.
	const f32 chartOriginX = local_2c;     // Replaces `local_2c` in usage
	const f32 local_38     = chartOriginY; // Unused, because of course nothing is ever consistent.

	// First we draw the checkered background of the timer chart, indicating the time scale chosen by `chartTimeScale`.
	f32 drawPosX;
	f32 drawPosY = chartOriginY;

	int chartCurrBar = 0;
	for (TimerInf* info = mTimerList; info; info = info->mNext) {
		drawPosX = chartOriginX;
		for (int chartCurrTick = 0; chartCurrTick < chartTimeScale; ++chartCurrTick) {
			// Alternate between the shades #191919 and #4C4C4C for the checkered background
			int value = (((chartCurrBar & 1) + chartCurrTick & 1) ? 0.1f : 0.3f) * 255.0f;

			gfx.setColour(Colour(value, value, value, 128), true);
			gfx.setAuxColour(Colour(value, value, value, 128));

			gfx.fillRectangle(RectArea(drawPosX, drawPosY, drawPosX + chartTickWidth, drawPosY + chartBarHeight));
			drawPosX += chartTickWidth;
		}
		drawPosY += chartBarHeight; // Reposition for the next bar.
		++chartCurrBar;
	}

	// Then we draw the actual bar graphs: green or red for average time, orange for peak time).
	drawPosX = chartOriginX;
	drawPosY = chartOriginY + 2.0f;

	for (TimerInf* info = mTimerList; info; info = info->mNext) {
		f32 chartBarAvgTimeScale = info->mAverageTime / MILLISEC_PER_FRAME;

		// If the bar we're about to draw is LITERALLY off the charts.
		if (chartBarAvgTimeScale > chartTimeScale) {
			// UNACCEPTABLE LAG SPIKE DETECTED!  YOU GET THE RED BAR OF SHAME!
			gfx.setColour(Colour(255, 0, 0, 255), true);
			gfx.setAuxColour(Colour(32, 0, 0, 255));
			chartBarAvgTimeScale = chartTimeScale; // Don't actually go off the charts (yet).
		} else {
			// Otherwise, you get the nice green coloured bar.
			gfx.setColour(Colour(128, 255, 128, 255), true);
			gfx.setAuxColour(Colour(0, 32, 0, 255));
		}

		// Convert from time scale to display scale.
		chartBarAvgTimeScale *= chartTickWidth;
		gfx.fillRectangle(RectArea(drawPosX, drawPosY, drawPosX + chartBarAvgTimeScale, int(drawPosY) + chartBarHeight - 4));

		// Draw the peak time bar in much the same way (though this one is allowed to go off the charts).
		f32 chartBarPeakTimeScale = info->mPeakTime / MILLISEC_PER_FRAME;
		chartBarPeakTimeScale *= chartTickWidth;
		gfx.setColour(Colour(255, 192, 64, 96), true);
		gfx.setAuxColour(Colour(32, 0, 0, 96));
		gfx.fillRectangle(
		    RectArea(drawPosX + chartBarAvgTimeScale, drawPosY, drawPosX + chartBarPeakTimeScale, int(drawPosY) + chartBarHeight - 4));

		drawPosY += chartBarHeight; // Reposition for the next bar.
	}

	// Next we draw an FPS counter at the top of the chart.
	drawPosY = chartOriginY - 1.0f;

	char fpsStr[PATH_MAX];
	sprintf(fpsStr, "%.1f fps", gsys->getFrameRate());
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.texturePrintf(font, gfx.mScreenWidth / 2 - font->stringWidth(fpsStr) + 30, int(drawPosY) - 14, "%s", fpsStr);

	// Finally we annotate the chart with timer names and the precise time measured in fractions of a frame.
	gfx.setColour(Colour(255, 255, 255, 128), true);
	for (TimerInf* info = mTimerList; info; info = info->mNext) {
		// Timer name on the left, precise time (ratio) on the right.
		gfx.texturePrintf(font, int(chartMarginSize * 0.5f) - font->stringWidth(info->mTimerName), drawPosY, "%s", info->mTimerName);
		gfx.texturePrintf(font, gfx.mScreenWidth - int(chartMarginSize * 0.5f), drawPosY, "%.4f", info->mAverageTime / MILLISEC_PER_FRAME);
		drawPosY += chartBarHeight;
	}
#endif
}
