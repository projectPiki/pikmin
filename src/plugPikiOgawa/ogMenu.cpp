#include "zen/ogMenu.h"
#include "BaseInf.h"
#include "Camera.h"
#include "DebugLog.h"
#include "FlowController.h"
#include "GameStat.h"
#include "GlobalGameOptions.h"
#include "P2D/Graph.h"
#include "P2D/Pane.h"
#include "P2D/Screen.h"
#include "PlayerState.h"
#include "SoundMgr.h"
#include "VersionGroups.h"
#include "gameflow.h"
#include "jaudio/verysimple.h"
#include "nlib/Math.h"
#include "sysNew.h"
#include "zen/ogRader.h"
#include "zen/ogSub.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("OgMenuSection")

namespace zen {
static f32 RotateAngleData[]
    = { 0.0f,  2.0f,  4.0f,  6.0f,  8.0f,  10.0f, 12.0f, 14.0f, 16.0f, 18.0f, 20.0f, 22.0f, 24.0f, 26.0f, 28.0f, 30.0f,
	    32.0f, 34.0f, 36.0f, 38.0f, 40.0f, 42.0f, 44.0f, 46.0f, 48.0f, 50.0f, 52.0f, 54.0f, 56.0f, 58.0f, 60.0f, -1.0f };

} // namespace zen

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void zen::ogDrawScrMenu::setScreen(char* path)
{
	PRINT("setScreen(%s) \n", path);
	mScreen->set(path, true, true, true);
	mRootPane = mScreen->search('root', true);
}

/*
 * --INFO--
 * Address:	80191294
 * Size:	0000C0
 */
zen::ogDrawScrMenu::ogDrawScrMenu()
{
	PRINT("ogDrawScrMenu() \n");
	mScreen          = new P2DScreen;
	mCurrentAngle    = 0.0f;
	mTargetAngle     = 0.0f;
	mAngularVelocity = 0.0f;
	mOrbitRadius     = 600.0f;
	mMenuDisplayMode = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void zen::ChkAngle(f32* out)
{
	f32 angle = *out;
	if (angle < 0.0f) {
		angle += TAU;
	}

	if (angle >= TAU) {
		angle -= TAU;
	}

	*out = angle;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void zen::ogDrawScrMenu::calcAngleSpeed(f32 angle)
{
	f32 temp = mTargetAngle - mCurrentAngle;
	if (temp < -PI) {
		temp += TAU;
	}
	if (temp > PI) {
		temp -= TAU;
	}
	mAngularVelocity += temp / angle;
}

/*
 * --INFO--
 * Address:	80191354
 * Size:	000350
 */
zen::ogDrawScrMenu::returnStatusFlag zen::ogDrawScrMenu::update(Controller* input, bool a1, bool a2)
{
	if (a1) {
		mTargetAngle += THIRD_PI;
		zen::ChkAngle(&mTargetAngle);
		mAngularVelocity = 0.0f;
		calcAngleSpeed(5.0f);
		seSystem->playSysSe(SYSSE_CMENU_SELECT);
	}

	if (a2) {
		mTargetAngle -= THIRD_PI;
		zen::ChkAngle(&mTargetAngle);
		mAngularVelocity = 0.0f;
		calcAngleSpeed(5.0f);
		seSystem->playSysSe(SYSSE_CMENU_SELECT);
	}

	calcAngleSpeed(10.0f);
	mAngularVelocity -= mAngularVelocity * 0.4f;
	f32 a = mAngularVelocity;
	if (quickABS(a) < 0.005f) {
		a = mCurrentAngle - mTargetAngle;
		if (quickABS(a) < 0.005f) {
			mCurrentAngle    = mTargetAngle;
			mAngularVelocity = 0.0f;
		}
	}
	mCurrentAngle += mAngularVelocity * (gsys->getFrameTime() / 0.016666666f);
	ChkAngle(&mCurrentAngle);

	mRootPane->move((mOrbitRadius * NMathF::sin(mCurrentAngle)), 0, (-mOrbitRadius * NMathF::cos(mCurrentAngle)) + mOrbitRadius);

	mRootPane->rotate(320, 240, P2DROTATE_Y, -mCurrentAngle);
	if (mCurrentAngle > 1.2566371f && mCurrentAngle < 5.0265484f) {
		mRootPane->hide();
	} else {
		mRootPane->show();
	}
	mScreen->update();

	STACK_PAD_VAR(1);
	return mUpdateResultStatus;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
bool zen::ogDrawScrMenu::draw(Graphics& gfx)
{
	P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	graf.setPort();
	mScreen->draw(0, 0, &graf);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801916E4
 * Size:	000278
 */
zen::ogDrawScrController::ogDrawScrController()
{
	mControllerScreenMenu.setScreen("screen/blo/cont_00.blo");
	P2DScreen* screen = mControllerScreenMenu.getPsc();
	setTextColor((P2DTextBox*)screen->search('st_c', false), (P2DPicture*)screen->search('st', false));
	mHighlightWhiteColor.set(255, 255, 255, 255);
	mHighlightBlackColor.set(0, 0, 0, 0);
	mMasterBackgroundWindowPane = (P2DPicture*)screen->search('3d_w', true);

	static u32 pane_name[9]  = { 'l_m', 'r_m', 'z_m', 'y_m', 'x_m', 'a_m', 'b_m', 'c_m', '3d_m' };
	static u32 pane_name2[9] = { 'l', 'r', 'z', 'y', 'x', 'a', 'b', 'c', '3d' };
	static u32 pane_name3[9] = { 'l_c', 'r_c', 'z_c', 'y_c', 'x_c', 'a_c', 'b_c', 'c_c', '3d_c' };
	static u32 pane_name4[9] = { 'l_w', 'r_w', 'z_w', 'y_w', 'x_w', 'a_w', 'b_w', 'c_w', '3d_w' };

	for (int i = 0; i < 9; i++) {
		mButtonMaskPanes[i]             = (P2DPicture*)screen->search(pane_name[i], true);
		mButtonBasePanes[i]             = (P2DPicture*)screen->search(pane_name2[i], true);
		mButtonTextBoxes[i]             = (P2DTextBox*)screen->search(pane_name3[i], true);
		mButtonBackgroundWindowPanes[i] = (P2DPicture*)screen->search(pane_name4[i], true);
		setTextColor(mButtonTextBoxes[i], mButtonMaskPanes[i]);
		setTextColor(mButtonTextBoxes[i], mButtonBasePanes[i]);
	}
	mCurrentButtonIndex = 0;
	mCycleTimer         = 1.0f;
	mIsColorInverted    = true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void zen::ogDrawScrController::setWinColor()
{
	Colour white = mMasterBackgroundWindowPane->getWhite();
	for (int i = 0; i < 9; i++) {
		mButtonBackgroundWindowPanes[i]->setWhite(white);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void zen::ogDrawScrController::setOriginalColor()
{
	Colour white = mButtonTextBoxes[mCurrentButtonIndex]->getCharColor();
	Colour black = mButtonTextBoxes[mCurrentButtonIndex]->getGradColor();
	black.a      = 0;

	mButtonMaskPanes[mCurrentButtonIndex]->setWhite(white);
	mButtonMaskPanes[mCurrentButtonIndex]->setBlack(black);
	mButtonBasePanes[mCurrentButtonIndex]->setWhite(white);
	mButtonBasePanes[mCurrentButtonIndex]->setBlack(black);
	mIsColorInverted = false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void zen::ogDrawScrController::setHantenColor()
{
	mButtonMaskPanes[mCurrentButtonIndex]->setWhite(mHighlightWhiteColor);
	mButtonMaskPanes[mCurrentButtonIndex]->setBlack(mHighlightBlackColor);
	mButtonBasePanes[mCurrentButtonIndex]->setWhite(mHighlightWhiteColor);
	mButtonBasePanes[mCurrentButtonIndex]->setBlack(mHighlightBlackColor);
	mIsColorInverted = true;
}

/*
 * --INFO--
 * Address:	8019195C
 * Size:	00041C
 */
void zen::ogDrawScrController::update()
{
	mCycleTimer -= gsys->getFrameTime();
	if (mCycleTimer <= 0.0f) {
		mCycleTimer = 1.0f;
		setOriginalColor();
		mCurrentButtonIndex++;
		if (mCurrentButtonIndex >= 9) {
			mCurrentButtonIndex = 0;
		}
		setHantenColor();
		mFlashTimer = 0.166666f;
	} else {
		mFlashTimer -= gsys->getFrameTime();
		if (mFlashTimer < 0.0f) {
			mFlashTimer = 0.166666f;
			if (mIsColorInverted) {
				setOriginalColor();
			} else {
				setHantenColor();
			}
		}
	}
	setWinColor();
}

/*
 * --INFO--
 * Address:	80191D78
 * Size:	000554
 */
zen::ogDrawScrInfo::ogDrawScrInfo()
{
#if defined(VERSION_PIKIDEMO)
	mInfoScreenMenu.setScreen("screen/blo/ot_menu2.blo");
#else
	mInfoScreenMenu.setScreen("screen/blo/m_menu2.blo");
#endif
	P2DScreen* screen  = mInfoScreenMenu.getPsc();
	mRootPane          = screen->search('root', true);
	mRadarMovementPane = screen->search('idou', true);
	mRadarZoomPane     = screen->search('zoom', true);

	mRedPikminInSquadCount    = 0;
	mBluePikminInSquadCount   = 0;
	mYellowPikminInSquadCount = 0;
	mRedPikminTotalCount      = 0;
	mBluePikminTotalCount     = 0;
	mYellowPikminTotalCount   = 0;
	mCurrentShipPartsCount    = 0;
	mTotalShipPartsCount      = 0;

	setNumberTag(screen, 'rp_l', &mRedPikminInSquadCount, 100);
	setNumberTag(screen, 'rp_c', &mRedPikminInSquadCount, 10);
	setNumberTag(screen, 'rp_r', &mRedPikminInSquadCount, 1);

	setNumberTag(screen, 'bp_l', &mBluePikminInSquadCount, 100);
	setNumberTag(screen, 'bp_c', &mBluePikminInSquadCount, 10);
	setNumberTag(screen, 'bp_r', &mBluePikminInSquadCount, 1);

	setNumberTag(screen, 'yp_l', &mYellowPikminInSquadCount, 100);
	setNumberTag(screen, 'yp_c', &mYellowPikminInSquadCount, 10);
	setNumberTag(screen, 'yp_r', &mYellowPikminInSquadCount, 1);

	setNumberTag(screen, 'rc_l', &mRedPikminTotalCount, 100);
	setNumberTag(screen, 'rc_c', &mRedPikminTotalCount, 10);
	setNumberTag(screen, 'rc_r', &mRedPikminTotalCount, 1);

	setNumberTag(screen, 'bc_l', &mBluePikminTotalCount, 100);
	setNumberTag(screen, 'bc_c', &mBluePikminTotalCount, 10);
	setNumberTag(screen, 'bc_r', &mBluePikminTotalCount, 1);

	setNumberTag(screen, 'yc_l', &mYellowPikminTotalCount, 100);
	setNumberTag(screen, 'yc_c', &mYellowPikminTotalCount, 10);
	setNumberTag(screen, 'yc_r', &mYellowPikminTotalCount, 1);

	setNumberTag(screen, 'rt_l', &mTotalShipPartsCount, 10);
	setNumberTag(screen, 'rt_r', &mTotalShipPartsCount, 1);

	setNumberTag(screen, 'ro_l', &mCurrentShipPartsCount, 10);
	setNumberTag(screen, 'ro_r', &mCurrentShipPartsCount, 1);

	setNumberTag(screen, 'fp_l', &mFieldPikminCount, 100);
	setNumberTag(screen, 'fp_c', &mFieldPikminCount, 10);
	setNumberTag(screen, 'fp_r', &mFieldPikminCount, 1);

	mRedPikminFieldPane    = screen->search('p_rp', true);
	mRedPikminTotalPane    = screen->search('p_rc', true);
	mBluePikminFieldPane   = screen->search('p_bp', true);
	mBluePikminTotalPane   = screen->search('p_bc', true);
	mYellowPikminFieldPane = screen->search('p_yp', true);
	mYellowPikminTotalPane = screen->search('p_yc', true);

	mStageTitlePanes[0] = screen->search('ti00', true);
	mStageTitlePanes[1] = screen->search('ti01', true);
	mStageTitlePanes[2] = screen->search('ti02', true);
	mStageTitlePanes[3] = screen->search('ti03', true);
	mStageTitlePanes[4] = screen->search('ti04', true);
	for (int i = 0; i < 5; i++) {
		mStageTitlePanes[i]->hide();
	}
}

/*
 * --INFO--
 * Address:	801922CC
 * Size:	000300
 */
void zen::ogDrawScrInfo::start()
{
	mBluePikminInSquadCount   = GameStat::formationPikis[Blue];
	mRedPikminInSquadCount    = GameStat::formationPikis[Red];
	mYellowPikminInSquadCount = GameStat::formationPikis[Yellow];
	PRINT("ScrInfo start!\n");
	mBluePikminTotalCount   = pikiInfMgr.getColorTotal(Blue);
	mRedPikminTotalCount    = pikiInfMgr.getColorTotal(Red);
	mYellowPikminTotalCount = pikiInfMgr.getColorTotal(Yellow);

	mPikminInSquadAndOnionCount = GameStat::formationPikis + GameStat::containerPikis; // All Pikmin in formation + in the onion
	mFieldPikminCount           = GameStat::freePikis + GameStat::workPikis + GameStat::mePikis;

	if (playerState) {
		mCurrentShipPartsCount = playerState->getCurrParts();
		mTotalShipPartsCount   = playerState->getTotalParts();
	} else {
		mCurrentShipPartsCount = 1;
		mTotalShipPartsCount   = 77;
	}

	mStageTitlePanes[flowCont.mCurrentStage->mStageID]->show();
	mRedPikminFieldPane->hide();
	mRedPikminTotalPane->hide();
	mBluePikminFieldPane->hide();
	mBluePikminTotalPane->hide();
	mYellowPikminFieldPane->hide();
	mYellowPikminTotalPane->hide();

	if (playerState->displayPikiCount(Blue)) {
		mBluePikminFieldPane->show();
		mBluePikminTotalPane->show();
	}
	if (playerState->displayPikiCount(Red)) {
		mRedPikminFieldPane->show();
		mRedPikminTotalPane->show();
	}
	if (playerState->displayPikiCount(Yellow)) {
		mYellowPikminFieldPane->show();
		mYellowPikminTotalPane->show();
	}

	if (playerState->hasRadar()) {
		mRadarMovementPane->show();
		mRadarZoomPane->show();
	} else {
		mRadarMovementPane->hide();
		mRadarZoomPane->hide();
	}

	PRINT("ScrInfo end STAGE(%d)\n", flowCont.mCurrentStage->mStageID);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void zen::ogDrawScrInfo::update(Controller*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000170
 */
zen::ogDrawScrInfo2::ogDrawScrInfo2()
{
	mMinimapScreenMenu.setScreen("screen/blo/m_menu2m.blo");
	P2DScreen* screen = mMinimapScreenMenu.getPsc();

	mMapAnchorPosition.set(0.0f, 0.0f, 0.0f);
	mMapsPane           = screen->search('maps', true);
	mDirectionArrowPane = screen->search('yaji', true);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void zen::ogDrawScrInfo2::start()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void zen::ogDrawScrInfo2::update(Controller*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void zen::ogDrawScrInfo2::drawHougaku(Graphics& gfx)
{
	int w     = mDirectionArrowPane->getWidth() / 2;
	int h     = mDirectionArrowPane->getHeight() / 2;
	f32 a     = -gfx.mCamera->mViewZAxis.z;
	f32 angle = atan2f(-gfx.mCamera->mViewZAxis.x, -gfx.mCamera->mViewZAxis.z);

	// final trial check?
	if (flowCont.mCurrentStage->mStageID == 4) {
		angle += PI;
	}
	mDirectionArrowPane->rotateZ(w, h, angle);

	if (!playerState->hasRadar()) {
		mDirectionArrowPane->hide();
	} else {
		mDirectionArrowPane->show();
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801925CC
 * Size:	0003FC
 */
zen::ogScrMenuMgr::ogScrMenuMgr()
{
	mLeftRightIndicator = new ogDrawLR;
	mLeftRightIndicator->setAct_L(false);
	mLeftRightIndicator->setAct_R(false);

	mRadarManager     = new ogRaderMgr;
	mInfoScreen       = new ogDrawScrInfo;
	mControllerScreen = new ogDrawScrController;
	mMinimapScreen    = new ogDrawScrInfo2;

	mScreenMenus[0] = &mInfoScreen->mInfoScreenMenu;
	mScreenMenus[1] = &mControllerScreen->mControllerScreenMenu;
	mScreenMenus[2] = &mMinimapScreen->mMinimapScreenMenu;

	for (int i = 0; i < 3; i++) {
		mScreenRootPanes[i] = mScreenMenus[i]->getRoot();
	}

	mBlackScreen = new P2DScreen;
	mBlackScreen->set("screen/blo/black.blo", false, false, true);
	mFadeOverlayPane = (P2DPicture*)mBlackScreen->search('blck', true);

	P2DTextBox* txt = (P2DTextBox*)mInfoScreen->mInfoScreenMenu.getPsc()->search('se_c', true);
	mAlpha          = txt->getAlphaChar();
	PRINT("se_c = %d\n", mAlpha);
	mFadeOverlayPane->setAlpha(0);
	mCurrentScreenIndex = 0;
	mRadarScaleVector.set(1.0f, 0.0f, 1.0f);
	mStatus = STATE_Inactive;
	STACK_PAD_TERNARY(mStatus, 1);
}

/*
 * --INFO--
 * Address:	801929C8
 * Size:	00026C
 */
void zen::ogScrMenuMgr::start()
{
	mStatus             = STATE_FadingIn;
	mTransitionTimer    = 0;
	mCurrentScreenIndex = 1;
	mLeftRightIndicator->start();
	mLeftRightIndicator->setAct_L(false);
	mLeftRightIndicator->setAct_R(false);
	mInfoScreen->start();
	mScreenMenus[0]->start(1);
	mScreenMenus[1]->start(2);
	mScreenMenus[2]->start(1);
	mRadarManager->startMenu(mMinimapScreen->getPaneMaps());
	seSystem->playSysSe(SYSSE_CMENU_ON);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void zen::ogScrMenuMgr::updateInfo(Controller* input)
{
	mLeftRightIndicator->setAct_L(false);
	mLeftRightIndicator->setAct_R(true);
	if (!input->keyClick(KBBTN_L) && input->keyClick(KBBTN_R)) {
		mCurrentScreenIndex++;
		mSwitchRightRequested = true;
#if defined(VERSION_PIKIDEMO)
#else
		mRadarManager->end();
#endif
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void zen::ogScrMenuMgr::updateCont(Controller* input)
{
	mLeftRightIndicator->setAct_L(true);
	mLeftRightIndicator->setAct_R(false);
	if (input->keyClick(KBBTN_L)) {
		mCurrentScreenIndex--;
		mSwitchLeftRequested = true;
#if defined(VERSION_PIKIDEMO)
#else
		mRadarManager->MapOn();
#endif
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80192C34
 * Size:	000598
 */
zen::ogScrMenuMgr::returnStatusFlag zen::ogScrMenuMgr::update(Controller* input)
{
	if (mStatus == STATE_Inactive) {
		return mStatus;
	}

	for (int i = 0; i < 3; i++) {
		mScreenMenus[i]->update(input, mSwitchLeftRequested, mSwitchRightRequested);
	}
	mInfoScreen->update(input);

	if (mStatus == STATE_FadingIn) {
		mTransitionTimer += gsys->getFrameTime();
		if (mTransitionTimer >= 0.3f) {
			mStatus = STATE_ActiveDisplay;
			for (int i = 0; i < 3; i++) {
				mScreenRootPanes[i]->setScale(1.0f);
			}
			mFadeOverlayPane->setAlpha(mAlpha);
		} else {
			f32 scale            = mTransitionTimer / 0.3f;
			mTransitionCalcAlpha = 255.0f * scale;
			for (int i = 0; i < 3; i++) {
				mScreenRootPanes[i]->setScale(scale);
				mFadeOverlayPane->setAlpha(mAlpha * scale);
			}
		}
		return mStatus;
	}

	if (mStatus == STATE_FadingOut) {
		mTransitionTimer += gsys->getFrameTime();
		if (mTransitionTimer >= 0.3f) {
			mStatus = STATE_TransitionToInactive;
			for (int i = 0; i < 3; i++) {
				mScreenRootPanes[i]->setScale(0.0f);
			}
			mFadeOverlayPane->setAlpha(0);
		} else {
			f32 scale            = (0.3f - mTransitionTimer) / 0.3f;
			mTransitionCalcAlpha = (0.3f - mTransitionTimer) * 255.0f / 0.3f; // sure, DONT use the temp you just made. that's fine.
			for (int i = 0; i < 3; i++) {
				mScreenRootPanes[i]->setScale(scale);
				mFadeOverlayPane->setAlpha(mAlpha * scale);
			}
		}
		return mStatus;
	}

	if (mStatus == STATE_TransitionToInactive) {
		mStatus = STATE_Inactive;
		return mStatus;
	}

	mSwitchLeftRequested  = false;
	mSwitchRightRequested = false;

#if defined(VERSION_PIKIDEMO)
#else
	if (input->keyClick(KBBTN_Y | KBBTN_B)) {
		mTransitionTimer = 0.0f;
		mStatus          = STATE_FadingOut;
		seSystem->playSysSe(SYSSE_CMENU_OFF);
		mRadarManager->end();
	}
#endif

	if (mCurrentScreenIndex) {
		if (mCurrentScreenIndex == 1) {
			updateInfo(input);
			mRadarManager->update(input);
		} else if (mCurrentScreenIndex == 2) {
			updateCont(input);
			mControllerScreen->update();
		}
	}
	mLeftRightIndicator->update();
	mBlackScreen->update();

#if defined(VERSION_PIKIDEMO)
	if (input->keyClick(KBBTN_Y | KBBTN_B)) {
		mTransitionTimer = 0.0f;
		mStatus          = STATE_FadingOut;
		seSystem->playSysSe(SYSSE_CMENU_OFF); // why is this one using the right enum.
		seSystem->stopSysSe(JACSYS_MenuScroll);
		seSystem->stopSysSe(JACSYS_MenuZoomIn);
		seSystem->stopSysSe(JACSYS_MenuZoomOut);
	}
#endif

	return mStatus;
}

/*
 * --INFO--
 * Address:	801931CC
 * Size:	0003C8
 */
bool zen::ogScrMenuMgr::draw(Graphics& gfx)
{
	if (mStatus == STATE_Inactive) {
		return false;
	}
	P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	graf.setPort();

	GXColor color = { 0 };
	GXSetFog(GX_FOG_NONE, 0.0f, 1.0f, 0.1f, 1.0f, color);
	GXSetFogRangeAdj(GX_FALSE, 0, nullptr);

	mBlackScreen->draw(0, 0, &graf);
	mScreenMenus[0]->draw(gfx);
	mScreenMenus[1]->draw(gfx);

	if (mCurrentScreenIndex == 1 && mInfoScreen->mInfoScreenMenu.chkStopAngle()) {
		f32 y = mRadarScaleVector.y;
		if (y < 1.0f) {
			y += 0.2f;
			if (y > 1.0f) {
				y = 1.0f;
			}
		}
		mRadarScaleVector.set(1.0f, y, 1.0f);
	} else {
		mRadarScaleVector.set(1.0f, 0.0f, 1.0f);
	}

	P2DPane* maps    = mMinimapScreen->getPaneMaps();
	P2DScreen* rader = mRadarManager->getScrPtr();

	rader->setScale(mRadarScaleVector);
	rader->setOffset(maps->getPosH() + (maps->getWidth() / 2), maps->getPosV() + (maps->getHeight() / 2));

	if (mStatus == STATE_ActiveDisplay) {
		mRadarManager->draw(gfx);
		mMinimapScreen->drawHougaku(gfx);
		mScreenMenus[2]->draw(gfx);
		mLeftRightIndicator->draw();
	}

	STACK_PAD_TERNARY(mStatus, 1);

	return true;
}
