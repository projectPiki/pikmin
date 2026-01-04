#include "DebugLog.h"
#include "P2D/Picture.h"
#include "SoundMgr.h"
#include "nlib/Math.h"
#include "sysNew.h"
#include "zen/DrawSave.h"
#include "zen/Math.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("drawSaveFailure")

/**
 * @todo: Documentation
 */
zen::DrawSaveFailure::DrawSaveFailure()
{
	mSaveFailScreen   = new DrawScreen("save_x.blo", nullptr, true, true);
	P2DScreen* screen = mSaveFailScreen->getScreenPtr();
	mSaveFailPane     = screen->search('saxx', true);
	mSaveFailPane->setOffset(mSaveFailPane->getWidth() >> 1, mSaveFailPane->getHeight() >> 1);
	mBackIcon = (P2DPicture*)screen->search('back', true);
	setMode(MODE_Unk0);
}

/**
 * @todo: Documentation
 */
bool zen::DrawSaveFailure::update(Controller* controller)
{
	bool res = false;
	switch (mMode) {
	case MODE_Unk0:
		res = true;
		break;

	case MODE_Unk1:
		f32 frame = calcFrame(mTransitionDuration);
		if (frame == 1.0f) {
			setMode(MODE_Unk2);
		} else {
			mSaveFailPane->setScale(-NMathF::cos(4.5f * PI * frame) * (1.0f - frame) + 1.0f);
			mBackIcon->setAlpha(RoundOff(180.0f * frame));
		}
		break;

	case MODE_Unk2:
		if (controller->keyClick(KBBTN_START | KBBTN_A)) {
			setMode(MODE_Unk3);
			SeSystem::playSysSe(SYSSE_DECIDE1);
		}
		break;

	case MODE_Unk3:
		f32 frame2 = calcFrame(mTransitionDuration);
		if (frame2 == 1.0f) {
			setMode(MODE_Unk0);
		} else {
			f32 cframe = 1.0f - frame2;
			mSaveFailPane->setScale(-NMathF::cos(4.0f * PI * cframe) * (1.0f - cframe) + 1.0f);
			mBackIcon->setAlpha(RoundOff(180.0f * cframe));
		}
		break;
	}

	STACK_PAD_TERNARY(controller, 1);
	mSaveFailScreen->update();
	return res;
}

/**
 * @todo: Documentation
 */
void zen::DrawSaveFailure::draw(Graphics&)
{
	if (mMode != MODE_Unk0) {
		mSaveFailScreen->draw();
	}
}

/**
 * @todo: Documentation
 */
void zen::DrawSaveFailure::open(f32 duration)
{
	setMode(MODE_Unk1);
	mTransitionDuration = duration;
	SeSystem::playSysSe(SYSSE_CARDERROR);
	mSaveFailScreen->makeResident();
}

/**
 * @todo: Documentation
 */
void zen::DrawSaveFailure::setMode(zen::DrawSaveFailure::modeFlag mode)
{
	mMode = mode;
	switch (mMode) {
	case MODE_Unk0:
		_08                 = 0.0f;
		mTransitionDuration = 0.0f;
		mSaveFailPane->setScale(0.0f);
		mBackIcon->setAlpha(0);
		break;

	case MODE_Unk1:
		_08 = 0.0f;
		break;

	case MODE_Unk2:
		mSaveFailPane->setScale(1.0f);
		mBackIcon->setAlpha(180);
		break;

	case MODE_Unk3:
		_08 = 0.0f;
		break;
	}
}

/**
 * @todo: Documentation
 */
f32 zen::DrawSaveFailure::calcFrame(f32 max)
{
	_08 += gsys->getFrameTime();
	if (_08 > max) {
		_08 = max;
		return 1.0f;
	}

	return _08 / max;
}

/**
 * @todo: Documentation
 */
void zen::DrawSaveFailure::init()
{
	setMode(MODE_Unk0);
}
