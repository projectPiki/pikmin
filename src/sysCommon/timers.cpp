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

/**
 * @todo: Documentation
 */
void Timers::draw(Graphics& gfx, Font* font)
{
#if defined(DEVELOP) || defined(VERSION_G98E01_PIKIDEMO)
	gfx.useTexture(nullptr, GX_TEXMAP0);

	// I'm leaving the variables with their Ghidra names for now because they were helpful for navigating the function's stack.  This
	// should be all of the variables in the exact order they were defined, which Ghidra bungles and I had to read assembly to learn.

	for (TimerInf* local_c = mTimerList; local_c; local_c = local_c->mNext) {
		local_c->mSampleTime++;
		if (local_c->mSampleTime == 10) {
			local_c->mAverageTime = local_c->mDuration / 10.0f;
			if (local_c->mAverageTime < 0.0f) {
				local_c->mAverageTime = 0.0f;
			}
			if (local_c->mAverageTime > local_c->mPeakTime) {
				local_c->mDecayTime = 10.0f;
				local_c->mPeakTime  = local_c->mAverageTime;
			}
			local_c->mDuration   = 0.0f;
			local_c->mSampleTime = 0;
		}

		local_c->mDecayTime -= gsys->getFrameTime();
		if (local_c->mDecayTime < 0.0f && local_c->mPeakTime > 0.0f) {
			local_c->mPeakTime -= 6.0f * gsys->getFrameTime();
			if (local_c->mPeakTime < 0.0f) {
				local_c->mPeakTime = 0.0f;
			}
		}
	}

	// Making any of the following named constants `const` breaks the stack for matching.  Lovely `const` memes!

	immut f32 local_10 = TERNARY_BUGFIX(256.0f, 192.0f);         // Chart Horizontal Margin Size (Combined)
	immut int local_14 = 4;                                      // Chart Horizontal Scale
	immut int local_18 = 12;                                     // Chart Vertical Scale
	                                                             // ------------------------------
	immut f32 local_1c = gfx.mScreenWidth - local_10;            // Chart Width
	immut f32 local_20 = local_1c / local_14;                    // Chart Tick Width
	immut f32 local_24 = local_1c;                               // unused
	immut f32 local_28 = (f32)mTimerCount * local_18 + 32.0f;    // Chart Height
	immut f32 local_2c = gfx.mScreenWidth / 2 - local_1c / 2.0f; // Drawing Origin X
	immut f32 local_30 = gfx.mScreenHeight - local_28;           // Drawing Origin Y

	// These really didn't need to exist, but they do according to the DLL.
	immut f32 local_34 = local_2c; // Replaces `local_2c` in usage
	immut f32 local_38 = local_30; // unused

	f32 local_3c;
	f32 local_40 = local_30;
	int local_44 = 0;

	for (TimerInf* local_48 = mTimerList; local_48; local_48 = local_48->mNext) {
		local_3c = local_34;
		for (int local_4c = 0; local_4c < local_14; ++local_4c) {
			// Something horrendous is going here.  Based on my understanding of stack variables in the DLL, there are no more
			// lvalues in this function, therefore this must be a ternary.  Just what is going on with this condition, though?
			int local_50 = (((local_44 & 1) + local_4c & 1) ? 0.1f : 0.3f) * 255.0f;

			gfx.setColour(Colour(local_50, local_50, local_50, 128), true);
			gfx.setAuxColour(Colour(local_50, local_50, local_50, 128));

			gfx.fillRectangle(RectArea(local_3c, local_40, local_3c + local_20, local_40 + local_18));
			local_3c += local_20;
		}
		local_40 += local_18;
		++local_44;
	}

	local_3c = local_34;
	local_40 = local_30 + 2.0f;

	for (TimerInf* local_54 = mTimerList; local_54; local_54 = local_54->mNext) {
		f32 local_58 = local_54->mAverageTime / 16.666666f;

		if (local_58 > local_14) {
			gfx.setColour(Colour(255, 0, 0, 255), true);
			gfx.setAuxColour(Colour(32, 0, 0, 255));
			local_58 = local_14;
		} else {
			gfx.setColour(Colour(128, 255, 128, 255), true);
			gfx.setAuxColour(Colour(0, 32, 0, 255));
		}

		local_58 *= local_20;
		gfx.fillRectangle(RectArea(local_3c, local_40, local_3c + local_58, int(local_40) + local_18 - 4));

		f32 local_5c = local_54->mPeakTime / 16.666666f;
		local_5c *= local_20;
		gfx.setColour(Colour(0xff, 0xc0, 0x40, 0x60), true);
		gfx.setAuxColour(Colour(0x20, 0, 0, 0x60));
		gfx.fillRectangle(RectArea(local_3c + local_58, local_40, local_3c + local_5c, int(local_40) + local_18 - 4));

		local_40 += local_18;
	}
	local_40 = local_30 - 1.0f;

	char local_15c[PATH_MAX];
	sprintf(local_15c, "%.1f fps", gsys->getFrameRate());
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.texturePrintf(font, gfx.mScreenWidth / 2 - font->stringWidth(local_15c) + 30, int(local_40) - 14, "%s", local_15c);

	gfx.setColour(Colour(255, 255, 255, 128), true);
	for (TimerInf* local_160 = mTimerList; local_160; local_160 = local_160->mNext) {
		gfx.texturePrintf(font, int(local_10 * 0.5f) - font->stringWidth(local_160->mTimerName), local_40, "%s", local_160->mTimerName);
		gfx.texturePrintf(font, gfx.mScreenWidth - int(local_10 * 0.5f), local_40, "%.4f", local_160->mAverageTime / 16.666666f);
		local_40 += local_18;
	}
#endif
}
