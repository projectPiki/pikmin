#include "zen/ogMenu.h"
#include "zen/ogSub.h"
#include "zen/ogRader.h"
#include "P2D/Pane.h"
#include "P2D/Screen.h"
#include "P2D/Graph.h"
#include "SoundMgr.h"
#include "nlib/Math.h"
#include "gameflow.h"
#include "GameStat.h"
#include "FlowController.h"
#include "PlayerState.h"
#include "sysNew.h"
#include "BaseInf.h"
#include "Camera.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

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
	_08 = mScreen->search('root', true);
}

/*
 * --INFO--
 * Address:	80191294
 * Size:	0000C0
 */
zen::ogDrawScrMenu::ogDrawScrMenu()
{
	PRINT("ogDrawScrMenu() \n");
	mScreen = new P2DScreen;
	_0C     = 0.0f;
	_10     = 0.0f;
	_14     = 0.0f;
	_1C     = 600.0f;
	_18     = 0;
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
	f32 temp = _10 - _0C;
	if (temp < -PI) {
		temp += TAU;
	}
	if (temp > PI) {
		temp -= TAU;
	}
	_14 += temp / angle;
}

/*
 * --INFO--
 * Address:	80191354
 * Size:	000350
 */
zen::ogDrawScrMenu::returnStatusFlag zen::ogDrawScrMenu::update(Controller* input, bool a1, bool a2)
{
	if (a1) {
		_10 += THIRD_PI;
		zen::ChkAngle(&_10);
		_14 = 0.0f;
		calcAngleSpeed(5.0f);
		seSystem->playSysSe(SYSSE_CMENU_SELECT);
	}

	if (a2) {
		_10 -= THIRD_PI;
		zen::ChkAngle(&_10);
		_14 = 0.0f;
		calcAngleSpeed(5.0f);
		seSystem->playSysSe(SYSSE_CMENU_SELECT);
	}

	calcAngleSpeed(10.0f);
	_14 -= _14 * 0.4f;
	f32 a = _14;
	if (quickABS(a) < 0.005f) {
		a = _0C - _10;
		if (quickABS(a) < 0.005f) {
			_0C = _10;
			_14 = 0.0f;
		}
	}
	_0C += _14 * (gsys->getFrameTime() / 0.016666666f);
	ChkAngle(&_0C);

	_08->move((_1C * NMathF::sin(_0C)), 0, (-_1C * NMathF::cos(_0C)) + _1C);

	_08->rotate(320, 240, P2DROTATE_Y, -_0C);
	if (_0C > 1.2566371f && _0C < 5.0265484f) {
		_08->hide();
	} else {
		_08->show();
	}
	mScreen->update();

	u32 badCompiler;
	return _04;
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
	_00.setScreen("screen/blo/cont_00.blo");
	P2DScreen* screen = _00.getPsc();
	setTextColor((P2DTextBox*)screen->search('st_c', false), (P2DPicture*)screen->search('st', false));
	_C4.set(255, 255, 255, 255);
	_C8.set(0, 0, 0, 0);
	_B4 = (P2DPicture*)screen->search('3d_w', true);

	static u32 pane_name[9]  = { 'l_m', 'r_m', 'z_m', 'y_m', 'x_m', 'a_m', 'b_m', 'c_m', '3d_m' };
	static u32 pane_name2[9] = { 'l', 'r', 'z', 'y', 'x', 'a', 'b', 'c', '3d' };
	static u32 pane_name3[9] = { 'l_c', 'r_c', 'z_c', 'y_c', 'x_c', 'a_c', 'b_c', 'c_c', '3d_c' };
	static u32 pane_name4[9] = { 'l_w', 'r_w', 'z_w', 'y_w', 'x_w', 'a_w', 'b_w', 'c_w', '3d_w' };

	for (int i = 0; i < 9; i++) {
		_24[i] = (P2DPicture*)screen->search(pane_name[i], true);
		_48[i] = (P2DPicture*)screen->search(pane_name2[i], true);
		_6C[i] = (P2DTextBox*)screen->search(pane_name3[i], true);
		_90[i] = (P2DPicture*)screen->search(pane_name4[i], true);
		setTextColor(_6C[i], _24[i]);
		setTextColor(_6C[i], _48[i]);
	}
	_B8 = 0;
	_BC = 1.0f;
	_D0 = true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void zen::ogDrawScrController::setWinColor()
{
	Colour white = _B4->getWhite();
	for (int i = 0; i < 9; i++) {
		_90[i]->setWhite(white);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void zen::ogDrawScrController::setOriginalColor()
{
	Colour white = _6C[_B8]->getCharColor();
	Colour black = _6C[_B8]->getGradColor();
	black.a      = 0;

	_24[_B8]->setWhite(white);
	_24[_B8]->setBlack(black);
	_48[_B8]->setWhite(white);
	_48[_B8]->setBlack(black);
	_D0 = false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void zen::ogDrawScrController::setHantenColor()
{
	_24[_B8]->setWhite(_C4);
	_24[_B8]->setBlack(_C8);
	_48[_B8]->setWhite(_C4);
	_48[_B8]->setBlack(_C8);
	_D0 = true;
}

/*
 * --INFO--
 * Address:	8019195C
 * Size:	00041C
 */
void zen::ogDrawScrController::update()
{
	_BC -= gsys->getFrameTime();
	if (_BC <= 0.0f) {
		_BC = 1.0f;
		setOriginalColor();
		_B8++;
		if (_B8 >= 9) {
			_B8 = 0;
		}
		setHantenColor();
		_C0 = 0.166666f;
	} else {
		_C0 -= gsys->getFrameTime();
		if (_C0 < 0.0f) {
			_C0 = 0.166666f;
			if (_D0) {
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
	_00.setScreen("screen/blo/m_menu2.blo");
	P2DScreen* screen = _00.getPsc();
	_3C               = screen->search('root', true);
	_40               = screen->search('idou', true);
	_44               = screen->search('zoom', true);

	_7C = 0;
	_80 = 0;
	_84 = 0;
	_88 = 0;
	_8C = 0;
	_90 = 0;
	_94 = 0;
	_98 = 0;

	setNumberTag(screen, 'rp_l', &_7C, 100);
	setNumberTag(screen, 'rp_c', &_7C, 10);
	setNumberTag(screen, 'rp_r', &_7C, 1);

	setNumberTag(screen, 'bp_l', &_80, 100);
	setNumberTag(screen, 'bp_c', &_80, 10);
	setNumberTag(screen, 'bp_r', &_80, 1);

	setNumberTag(screen, 'yp_l', &_84, 100);
	setNumberTag(screen, 'yp_c', &_84, 10);
	setNumberTag(screen, 'yp_r', &_84, 1);

	setNumberTag(screen, 'rc_l', &_88, 100);
	setNumberTag(screen, 'rc_c', &_88, 10);
	setNumberTag(screen, 'rc_r', &_88, 1);

	setNumberTag(screen, 'bc_l', &_8C, 100);
	setNumberTag(screen, 'bc_c', &_8C, 10);
	setNumberTag(screen, 'bc_r', &_8C, 1);

	setNumberTag(screen, 'yc_l', &_90, 100);
	setNumberTag(screen, 'yc_c', &_90, 10);
	setNumberTag(screen, 'yc_r', &_90, 1);

	setNumberTag(screen, 'rt_l', &_98, 10);
	setNumberTag(screen, 'rt_r', &_98, 1);

	setNumberTag(screen, 'ro_l', &_94, 10);
	setNumberTag(screen, 'ro_r', &_94, 1);

	setNumberTag(screen, 'fp_l', &_A0, 100);
	setNumberTag(screen, 'fp_c', &_A0, 10);
	setNumberTag(screen, 'fp_r', &_A0, 1);

	_64 = screen->search('p_rp', true);
	_68 = screen->search('p_rc', true);
	_6C = screen->search('p_bp', true);
	_70 = screen->search('p_bc', true);
	_74 = screen->search('p_yp', true);
	_78 = screen->search('p_yc', true);

	_28[0] = screen->search('ti00', true);
	_28[1] = screen->search('ti01', true);
	_28[2] = screen->search('ti02', true);
	_28[3] = screen->search('ti03', true);
	_28[4] = screen->search('ti04', true);
	for (int i = 0; i < 5; i++) {
		_28[i]->hide();
	}
}

/*
 * --INFO--
 * Address:	801922CC
 * Size:	000300
 */
void zen::ogDrawScrInfo::start()
{
	_80 = GameStat::formationPikis[0];
	_7C = GameStat::formationPikis[1];
	_84 = GameStat::formationPikis[2];
	PRINT("ScrInfo start!\n");
	_8C = pikiInfMgr.getColorTotal(0);
	_88 = pikiInfMgr.getColorTotal(1);
	_90 = pikiInfMgr.getColorTotal(2);

	_9C = GameStat::formationPikis + GameStat::containerPikis;
	_A0 = GameStat::freePikis + GameStat::workPikis + GameStat::mePikis;

	if (playerState) {
		_94 = playerState->getCurrParts();
		_98 = playerState->getTotalParts();
	} else {
		_94 = 1;
		_98 = 77;
	}

	_28[flowCont.mCurrentStage->mStageID]->show();
	_64->hide();
	_68->hide();
	_6C->hide();
	_70->hide();
	_74->hide();
	_78->hide();

	if (playerState->displayPikiCount(Blue)) {
		_6C->show();
		_70->show();
	}
	if (playerState->displayPikiCount(Red)) {
		_64->show();
		_68->show();
	}
	if (playerState->displayPikiCount(Yellow)) {
		_74->show();
		_78->show();
	}

	if (playerState->hasRadar()) {
		_40->show();
		_44->show();
	} else {
		_40->hide();
		_44->hide();
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
	_00.setScreen("screen/blo/m_menu2m.blo");
	P2DScreen* screen = _00.getPsc();

	_28.set(0.0f, 0.0f, 0.0f);
	_24 = screen->search('maps', true);
	_34 = screen->search('yaji', true);
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
	int w     = _34->getWidth() / 2;
	int h     = _34->getHeight() / 2;
	f32 a     = -gfx.mCamera->mViewZAxis.z;
	f32 angle = atan2f(-gfx.mCamera->mViewZAxis.x, -gfx.mCamera->mViewZAxis.z);

	// final trial check?
	if (flowCont.mCurrentStage->mStageID == 4) {
		angle += PI;
	}
	_34->rotateZ(w, h, angle);

	if (!playerState->hasRadar()) {
		_34->hide();
	} else {
		_34->show();
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
	_10 = new ogDrawLR;
	_10->setAct_L(false);
	_10->setAct_R(false);

	_14 = new ogRaderMgr;
	_48 = new ogDrawScrInfo;
	_4C = new ogDrawScrController;
	_50 = new ogDrawScrInfo2;

	_18[0] = &_48->_00;
	_18[1] = &_4C->_00;
	_18[2] = &_50->_00;

	for (int i = 0; i < 3; i++) {
		_30[i] = _18[i]->getRoot();
	}

	_08 = new P2DScreen;
	_08->set("screen/blo/black.blo", false, false, true);
	_0C = (P2DPicture*)_08->search('blck', true);

	P2DTextBox* txt = (P2DTextBox*)_48->_00.getPsc()->search('se_c', true);
	mAlpha          = txt->getAlphaChar();
	PRINT("se_c = %d\n", mAlpha);
	_0C->setAlpha(0);
	_04 = 0;
	_60.set(1.0f, 0.0f, 1.0f);
	mStatus = Status_NULL;
	mStatus ? "fake" : "fake";
}

/*
 * --INFO--
 * Address:	801929C8
 * Size:	00026C
 */
void zen::ogScrMenuMgr::start()
{
	mStatus = Status_1;
	_58     = 0;
	_04     = 1;
	_10->start();
	_10->setAct_L(false);
	_10->setAct_R(false);
	_48->start();
	_18[0]->start(1);
	_18[1]->start(2);
	_18[2]->start(1);
	_14->startMenu(_50->getPaneMaps());
	seSystem->playSysSe(SYSSE_CMENU_ON);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void zen::ogScrMenuMgr::updateInfo(Controller* input)
{
	_10->setAct_L(false);
	_10->setAct_R(true);
	if (!input->keyClick(KBBTN_L) && input->keyClick(KBBTN_R)) {
		_04++;
		_55 = true;
		_14->end();
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
	_10->setAct_L(true);
	_10->setAct_R(false);
	if (input->keyClick(KBBTN_L)) {
		_04--;
		_54 = true;
		_14->MapOn();
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
	if (mStatus == Status_NULL) {
		return mStatus;
	}

	for (int i = 0; i < 3; i++) {
		_18[i]->update(input, _54, _55);
	}
	_48->update(input);

	if (mStatus == Status_1) {
		_58 += gsys->getFrameTime();
		if (_58 >= 0.3f) {
			mStatus = Status_0;
			for (int i = 0; i < 3; i++) {
				_30[i]->setScale(1.0f);
			}
			_0C->setAlpha(mAlpha);
		} else {
			f32 scale = _58 / 0.3f;
			_5C       = 255.0f * scale;
			for (int i = 0; i < 3; i++) {
				_30[i]->setScale(scale);
				_0C->setAlpha(mAlpha * scale);
			}
		}
		return mStatus;
	}

	if (mStatus == Status_2) {
		_58 += gsys->getFrameTime();
		if (_58 >= 0.3f) {
			mStatus = Status_3;
			for (int i = 0; i < 3; i++) {
				_30[i]->setScale(0.0f);
			}
			_0C->setAlpha(0);
		} else {
			f32 scale = (0.3f - _58) / 0.3f;
			_5C       = (0.3f - _58) * 255.0f / 0.3f; // sure, DONT use the temp you just made. that's fine.
			for (int i = 0; i < 3; i++) {
				_30[i]->setScale(scale);
				_0C->setAlpha(mAlpha * scale);
			}
		}
		return mStatus;
	}

	if (mStatus == Status_3) {
		mStatus = Status_NULL;
		return mStatus;
	}

	_54 = false;
	_55 = false;

	if (input->keyClick(KBBTN_Y | KBBTN_B)) {
		_58     = 0.0f;
		mStatus = Status_2;
		seSystem->playSysSe(SYSSE_CMENU_OFF);
		_14->end();
	}

	if (_04) {
		if (_04 == 1) {
			updateInfo(input);
			_14->update(input);
		} else if (_04 == 2) {
			updateCont(input);
			_4C->update();
		}
	}
	_10->update();
	_08->update();

	return mStatus;
}

/*
 * --INFO--
 * Address:	801931CC
 * Size:	0003C8
 */
bool zen::ogScrMenuMgr::draw(Graphics& gfx)
{
	if (mStatus == Status_NULL) {
		return false;
	}
	P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	graf.setPort();

	GXColor color = { 0 };
	GXSetFog(GX_FOG_NONE, 0.0f, 1.0f, 0.1f, 1.0f, color);
	GXSetFogRangeAdj(GX_FALSE, 0, nullptr);

	_08->draw(0, 0, &graf);
	_18[0]->draw(gfx);
	_18[1]->draw(gfx);

	if (_04 == 1 && _48->_00.chkStopAngle()) {
		f32 y = _60.y;
		if (y < 1.0f) {
			y += 0.2f;
			if (y > 1.0f) {
				y = 1.0f;
			}
		}
		_60.set(1.0f, y, 1.0f);
	} else {
		_60.set(1.0f, 0.0f, 1.0f);
	}

	P2DPane* maps    = _50->getPaneMaps();
	P2DScreen* rader = _14->getScrPtr();

	rader->setScale(_60);
	rader->setOffset(maps->getPosH() + (maps->getWidth() / 2), maps->getPosV() + (maps->getHeight() / 2));

	if (mStatus == Status_0) {
		_14->draw(gfx);
		_50->drawHougaku(gfx);
		_18[2]->draw(gfx);
		_10->draw();
	}

	mStatus ? "fake" : "fake";

	return true;
}
