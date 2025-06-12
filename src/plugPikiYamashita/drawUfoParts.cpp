#include "zen/DrawUfoParts.h"
#include "P2D/TextBox.h"
#include "SoundMgr.h"
#include "Graphics.h"
#include "PlayerState.h"
#include "Pellet.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	801F1D60
 * Size:	0000EC
 */
zen::DrawUfoParts::DrawUfoParts()
{
	mScreen = new DrawScreen("screen/blo/ufo_p.blo", nullptr, true, true);
	mBest.init(mScreen->getScreenPtr());
	mReturnState = RETSTATE_Unk0;
	mMode        = MODE_Sleep;

	mAlphaWipe.setColour(Colour(0, 0, 0, 0), Colour(0, 0, 0, 0));

	// just for stack
	STACK_PAD_TERNARY(mScreen, 1);
}

/*
 * --INFO--
 * Address:	801F1E4C
 * Size:	000130
 */
bool zen::DrawUfoParts::update(Controller* controller)
{
	bool res = false;
	if (mMode != MODE_Sleep) {
		mAlphaWipe.update();
		switch (mMode) {
		case MODE_FadeIn:
			if (mAlphaWipe.isSleep()) {
				mMode = MODE_Operation;
			}
			break;

		case MODE_Operation:
			if (controller->keyClick(KBBTN_START | KBBTN_A)) {
				SeSystem::playSysSe(SYSSE_DECIDE1);
				mReturnState = RETSTATE_Unk2;
				res          = true;
			}

			if (controller->keyClick(KBBTN_B)) {
				SeSystem::playSysSe(SYSSE_CANCEL);
				mReturnState = RETSTATE_Unk1;
				mAlphaWipe.start(0.5f, 0.25f, AlphaWipe::TYPE_Reverse);
				mMode = MODE_FadeOut;
			}
			break;

		case MODE_FadeOut:
			if (mAlphaWipe.isSleep()) {
				mMode = MODE_Sleep;
				res   = true;
			}
			break;
		}

		mScreen->update();
		mBest.update();
	}

	return res;
}

/*
 * --INFO--
 * Address:	801F1F7C
 * Size:	0001B4
 */
void zen::DrawUfoParts::draw(Graphics& gfx)
{
	bool check = false;
	if (mMode != MODE_Sleep) {
		switch (mMode) {
		case MODE_FadeIn:
			if (mAlphaWipe.isDec()) {
				check = true;
			}
			break;

		case MODE_Operation:
			check = true;
			break;

		case MODE_FadeOut:
			if (mAlphaWipe.isInc()) {
				check = true;
			}
			break;
		}

		if (check) {
			Matrix4f mtx;
			gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
			gfx.setColour(Colour(0, 0, 0, 255), true);
			gfx.setAuxColour(Colour(0, 0, 0, 255));
			gfx.fillRectangle(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
			mScreen->draw();
		}

		mAlphaWipe.draw(gfx);
	}
}

/*
 * --INFO--
 * Address:	801F2130
 * Size:	000034
 */
void zen::DrawUfoParts::sleep()
{
	mMode        = MODE_Sleep;
	mReturnState = RETSTATE_Unk0;
	mBest.sleep();
}

/*
 * --INFO--
 * Address:	801F2164
 * Size:	000068
 */
void zen::DrawUfoParts::start()
{
	mScreen->makeResident();
	mMode        = MODE_FadeIn;
	mReturnState = RETSTATE_Unk0;
	dataSet();
	mAlphaWipe.start(0.75f, 0.25f, AlphaWipe::TYPE_Normal);
	mBest.appear();
}

/*
 * --INFO--
 * Address:	801F21CC
 * Size:	00004C
 */
void zen::DrawUfoParts::operation()
{
	mScreen->makeResident();
	mMode        = MODE_Operation;
	mReturnState = RETSTATE_Unk0;
	dataSet();
}

/*
 * --INFO--
 * Address:	801F2218
 * Size:	00020C
 */
void zen::DrawUfoParts::dataSet()
{
	int i;
	char buf[8];
	P2DScreen* screen = mScreen->getScreenPtr();
	for (i = 0; i < MAX_UFO_PARTS; i++) {
		sprintf(buf, "ui%02d", i + 1);
		P2DPicture* partIcon = (P2DPicture*)screen->search(P2DPaneLibrary::makeTag(buf), true);
		sprintf(buf, "un%02d", i + 1);
		P2DTextBox* partLabel = (P2DTextBox*)screen->search(P2DPaneLibrary::makeTag(buf), true);

		if (playerState) {
			if (!playerState->hasUfoParts(PelletMgr::getUfoIDFromIndex(i))) {
				partIcon->setBlack(Colour(48, 48, 48, 0));
				partIcon->setWhite(Colour(0, 0, 0, 255));
				partLabel->setCharColor(Colour(0, 0, 0, 0));
				partLabel->setGradColor(Colour(0, 0, 0, 0));
			}

		} else if ((i % 2) == 0) {
			partIcon->setBlack(Colour(48, 48, 48, 0));
			partIcon->setWhite(Colour(0, 0, 0, 255));
			partLabel->setCharColor(Colour(0, 0, 0, 0));
			partLabel->setGradColor(Colour(0, 0, 0, 0));
		}
	}
}
