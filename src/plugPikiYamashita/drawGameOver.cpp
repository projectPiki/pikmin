#include "zen/DrawGameOver.h"
#include "DebugLog.h"
#include "P2D/Picture.h"
#include "sysNew.h"
#include "zen/Math.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(15)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("drawGameOver")

namespace zen {
/**
 * @brief The animation state for an individual letter in the "Game Over" text.
 */
BEGIN_ENUM_TYPE(LetterState)
enum {
	Idle   = 0, // The letter is in its initial, unmoving state.
	Wait   = 1, // The letter is waiting for a staggered delay before starting its animation.
	Fall   = 2, // The letter is falling, bouncing, and rotating into its final position.
	Settle = 3  // The letter has landed and is settling into its final scale and rotation.
} END_ENUM_TYPE;

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct DrawGameOverLetter {
public:
	DrawGameOverLetter()
	{
		mState           = LetterState::Idle;
		mLetterPic       = 0;
		mTargetX         = 0;
		mTargetY         = 0;
		mPositionX       = 0.0f;
		mPositionY       = 0.0f;
		mVelocityX       = 0.0f;
		mVelocityY       = 0.0f;
		mAngularVelocity = 0.0f;
		mScaleVelocity   = 0.0f;
		mStateTimer      = 0.0f;
		mStartDelay      = 0.0f;
	}

	// weak
	void init(P2DPane* pane)
	{
		if (pane->getTypeID() != PANETYPE_Picture) {
			PRINT("not picture pane.\n");
			ERROR("not picture pane.\n");
		} else {
			mLetterPic = (P2DPicture*)pane;
			mTargetX   = mLetterPic->getPosH();
			mTargetY   = mLetterPic->getPosV();
			initParams();
		}
	}

	bool update()
	{
		bool res = false;
		switch (mState) {
		case LetterState::Idle:
			break;

		case LetterState::Wait:
			mStateTimer += gsys->getFrameTime();
			if (mStateTimer > mStartDelay) {
				mStateTimer = 0.0f;
				mState      = LetterState::Fall;
				mLetterPic->setScale(0.5f);
			}
			break;

		case LetterState::Fall:
			mVelocityY += gsys->getFrameTime() * 7200.0f * gsys->getFrameTime();
			mPositionY += gsys->getFrameTime() * mVelocityY * 30.0f;
			mPositionX += gsys->getFrameTime() * mVelocityX * 30.0f;
			if (mPositionY > mTargetY) {
				mVelocityX = gsys->getFrameTime() * ((mTargetX - mPositionX) / 3.0f) * 30.0f;
				if (mVelocityX > 10.0f) {
					mVelocityX = 10.0f;
				}
				if (mVelocityX < -10.0f) {
					mVelocityX = -10.0f;
				}
				mPositionY = mTargetY;
				mVelocityY *= Rand(0.2f) + -0.6f;
				mAngularVelocity = gsys->getFrameTime() * (mVelocityX * 0.1f) * 30.0f;
			}

			mLetterPic->move(RoundOff(mPositionX), RoundOff(mPositionY));
			mLetterPic->rotateZ(mLetterPic->getWidth() >> 1, RoundOff(mLetterPic->getHeight() * 0.75f),
			                    mLetterPic->getRotate() + mAngularVelocity);
			mStateTimer += gsys->getFrameTime();
			if (mStateTimer > 1.7f) {
				mAngularVelocity = 0.0f;
				mStateTimer      = 0.0f;
				mState           = LetterState::Settle;
				mScaleVelocity   = 0.0f;
			}
			break;

		case LetterState::Settle:
			mStateTimer += gsys->getFrameTime();
			if (mStateTimer > 5.0f) {
				mStateTimer      = 0.0f;
				mAngularVelocity = PI / 10.0f;
				mScaleVelocity   = -0.2f;
			}

			if (mLetterPic->getRotate() < PI) {
				mAngularVelocity += -mLetterPic->getRotate() * gsys->getFrameTime();
			} else {
				mAngularVelocity += (TAU - mLetterPic->getRotate()) * gsys->getFrameTime();
			}

			mAngularVelocity *= 0.95f;
			mLetterPic->rotateZ(mLetterPic->getWidth() >> 1, RoundOff(mLetterPic->getHeight() * 0.75f),
			                    mLetterPic->getRotate() + mAngularVelocity);
			Vector3f scale(mLetterPic->getScale());
			mScaleVelocity += gsys->getFrameTime() * (1.0f - scale.x) * 4.0f;
			mScaleVelocity *= 0.85f;
			mLetterPic->setScale(scale.x + mScaleVelocity);
			break;
		}

		return res;
	}

	// DLL inlines to do:
	void start(f32 startDelay)
	{
		initParams();
		mState      = LetterState::Wait;
		mStateTimer = 0.0f;
		mStartDelay = startDelay;
	}

protected:
	void initParams()
	{
		mState      = LetterState::Idle;
		mStateTimer = 0.0f;
		mStartDelay = 0.0f;
		mPositionX  = 320.0f;
		mPositionY  = mTargetY - 480.0f;
		mLetterPic->move(RoundOff(mPositionX), RoundOff(mPositionY));
		mVelocityX       = Rand(10.0f) - 5.0f;
		mVelocityY       = 0.0f;
		mAngularVelocity = 0.0f;
		mScaleVelocity   = 0.0f;
	}

	int mState;             // _00
	f32 mStateTimer;        // _04
	f32 mStartDelay;        // _08
	P2DPicture* mLetterPic; // _0C
	int mTargetX;           // _10
	int mTargetY;           // _14
	f32 mPositionX;         // _18
	f32 mPositionY;         // _1C
	f32 mVelocityX;         // _20
	f32 mVelocityY;         // _24
	f32 mAngularVelocity;   // _28
	f32 mScaleVelocity;     // _2C
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct DrawGameOverScreen {
public:
	DrawGameOverScreen(immut char* bloFileName)
	{
		mScreen      = new DrawScreen(bloFileName, nullptr, true, true);
		mLetterCount = 0;
		char buf[8];
		sprintf(buf, "go%02d", mLetterCount);
		while (mScreen->getScreenPtr()->search(P2DPaneLibrary::makeTag(buf), false)) {
			mLetterCount++;
			sprintf(buf, "go%02d", mLetterCount);
		}

		if (mLetterCount == 0) {
			PRINT("no letter Pane.\n");
			ERROR("no letter Pane.\n");
		}

		mLetters = new DrawGameOverLetter[mLetterCount];

		for (int i = 0; i < mLetterCount; i++) {
			sprintf(buf, "go%02d", i);
			P2DPane* pane = mScreen->getScreenPtr()->search(P2DPaneLibrary::makeTag(buf), true);
			mLetters[i].init(pane);
		}
	}

	// DLL inlines to do:
	void start()
	{
		for (int i = 0; i < mLetterCount; i++) {
			mLetters[i].start(f32(i) * 0.1f);
		}
	}

	bool update()
	{
		for (int i = 0; i < mLetterCount; i++) {
			mLetters[i].update();
		}
		mScreen->update();
		return false;
	}

	void draw(Graphics&) { mScreen->draw(); }

protected:
	DrawScreen* mScreen;          // _00
	int mLetterCount;             // _04
	DrawGameOverLetter* mLetters; // _08
};
} // namespace zen

/**
 * @todo: Documentation
 */
zen::DrawGameOver::DrawGameOver()
{
	mGameOverA    = new DrawGameOverScreen("screen/blo/gameover.blo");
	mGameOverB    = new DrawGameOverScreen("screen/blo/gameove2.blo");
	mState        = GameOverState::Inactive;
	mMode         = MODE_NaviDown;
	mStateTimer   = 0.0f;
	mActiveScreen = 0;
}

/**
 * @todo: Documentation
 */
void zen::DrawGameOver::start(zen::DrawGameOver::modeFlag mode, f32 p2)
{
	mState         = GameOverState::Start;
	mMode          = mode;
	mInputWaitTime = p2;
	switch (mMode) {
	case MODE_NaviDown:
		mActiveScreen = mGameOverA;
		break;

	case MODE_Extinction:
		mActiveScreen = mGameOverB;
		break;

	default:
		PRINT("Unknown mode %d \n", mMode);
		ERROR("Unknown mode %d \n", mMode);
		break;
	}

	mActiveScreen->start();
}

/**
 * @todo: Documentation
 */
bool zen::DrawGameOver::update(Controller* controller)
{
	bool isInputPeriodDone = false;
	if (mState) {
		mStateTimer += gsys->getFrameTime();
		switch (mState) {
		case GameOverState::Start:
			if (mStateTimer > 2.0f) {
				mState      = GameOverState::WaitInput;
				mStateTimer = 0.0f;
			}
			break;

		case GameOverState::WaitInput:
			if (controller->keyClick(KBBTN_START | KBBTN_A)) {
				isInputPeriodDone = true;
			}
			if (mStateTimer > mInputWaitTime) {
				mStateTimer       = mInputWaitTime;
				isInputPeriodDone = true;
			}
			break;
		}

		mActiveScreen->update();
	}

	return isInputPeriodDone;
}

/**
 * @todo: Documentation
 */
void zen::DrawGameOver::draw(Graphics& gfx)
{
	if (mState) {
		mActiveScreen->draw(gfx);
	}
}
