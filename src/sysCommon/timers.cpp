#include "timers.h"
#include "DebugLog.h"
#include "Font.h"
#include "Graphics.h"
#include "sysNew.h"
#include "system.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Timers")

/**
 * @TODO: Documentation
 */
void Timers::reset()
{
	mTimerList  = nullptr;
	mTimerCount = 0;
}

/**
 * @TODO: Documentation
 */
void Timers::newFrame()
{
	mFrameCount++;
}

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
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
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void Timers::showTimes()
{
	for (TimerInf* info = mTimerList; info; info = info->mNext) {
		PRINT("timer : %s = %f\n", info->mTimerName, info->mAverageTime);
	}
}

/**
 * @TODO: Documentation
 */
void Timers::draw(Graphics& gfx, Font* font)
{
#if defined(DEVELOP) || defined(VERSION_G98E01_PIKIDEMO)
	gfx.useTexture(nullptr, GX_TEXMAP0);
	for (TimerInf* info = mTimerList; info; info = info->mNext) {
		info->mSampleTime++;
		if (info->mSampleTime == 10) {
			info->mAverageTime = info->mDuration / 10.0f;
			if (info->mAverageTime < 0.0f) {
				info->mAverageTime = 0.0f;
			}
			if (info->mAverageTime > info->mPeakTime) {
				info->mDecayTime = 10.0f;
				info->mPeakTime  = info->mAverageTime;
			}
			info->mDuration   = 0.0f;
			info->mSampleTime = 0;
		}

		info->mDecayTime -= gsys->getFrameTime();
		if (info->mDecayTime < 0.0f && info->mPeakTime > 0.0f) {
			info->mPeakTime -= 6.0f * gsys->getFrameTime();
			if (info->mPeakTime < 0.0f) {
				info->mPeakTime = 0.0f;
			}
		}
	}

	f32 a    = 192.0f;
	int b    = 4;
	f32 xPos = gfx.mScreenWidth - 192.0f;
	f32 d    = xPos / 4.0f;
	f32 e    = xPos;
	f32 f    = mTimerCount * 12.0f + 32.0f;
	f32 g    = (gfx.mScreenWidth / 2) - xPos / 2.0f;
	f32 yPos = gfx.mScreenHeight - f;
	f32 h    = g;
	f32 x    = xPos;
	f32 y    = yPos;
	int z    = 0;

	for (TimerInf* info = mTimerList; info; info = info->mNext) {
		f32 x0 = h;
		for (int i = 0; i < b; i++) {
			f32 val;
			if (((z & 1) + i) & 1) {
				val = 0.1f;
			} else {
				val = 0.3f;
			}
			u8 v8 = int(val * 255.0f);
			gfx.setColour(Colour(v8, v8, v8, 128), true);
			gfx.setAuxColour(Colour(v8, v8, v8, 128));

			gfx.fillRectangle(RectArea(x0, y, x0 + d, y + 12.0f));
			x0 += d;
		}

		y += 12.0f;
		z++;
	}

	f32 x1 = h;
	f32 y1 = yPos + 2.0f;
	for (TimerInf* info = mTimerList; info; info = info->mNext) { }

	char buf[PATH_MAX];
	sprintf(buf, "%.1f fps", gsys->getFrameRate());
	gfx.setColour(Colour(255, 255, 255, 255), true);

	gfx.texturePrintf(font, gfx.mScreenWidth / 2 - font->stringWidth(buf) + 30, yPos - 1.0f, buf);
#endif
}
