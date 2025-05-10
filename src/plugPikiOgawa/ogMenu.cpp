#include "zen/ogMenu.h"
#include "zen/ogSub.h"
#include "zen/ogRader.h"
#include "P2D/Pane.h"
#include "P2D/Screen.h"
#include "P2D/Graph.h"
#include "SoundMgr.h"
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
f32 RotateAngleData[] = { 0.0f,  2.0f,  4.0f,  6.0f,  8.0f,  10.0f, 12.0f, 14.0f, 16.0f, 18.0f, 20.0f, 22.0f, 24.0f, 26.0f, 28.0f, 30.0f,
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
	if (absF(_14) < 0.005f && absF(_0C - _10) < 0.005f) {
		_0C = _10;
		_14 = 0.0f;
	}
	_0C += _14 * (gsys->getFrameTime() / 0.016666666f);
	ChkAngle(&_0C);

	f32 c = cosf(_0C);
	f32 s = sinf(_0C);
	_08->move(c + _1C, (-_1C * s) + _1C, 0.0f);

	_08->rotate(320, 240, P2DROTATE_Y, -_0C);
	if (_0C > 1.2566371f && _0C < 5.0265484f) {
		_08->hide();
	} else {
		_08->show();
	}
	mScreen->update();
	return _04;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r5,0,24,31
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r6, 0
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  beq-      .loc_0xC0
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x4E74(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r30)
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x4E88(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x50
	  lfs       f0, -0x4E80(r2)
	  fadds     f1, f1, f0

	.loc_0x50:
	  lfs       f0, -0x4E80(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x64
	  fsubs     f1, f1, f0

	.loc_0x64:
	  stfs      f1, 0x10(r30)
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0x14(r30)
	  lfs       f2, 0x10(r30)
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x4E7C(r2)
	  fsubs     f2, f2, f1
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x90
	  lfs       f0, -0x4E80(r2)
	  fadds     f2, f2, f0

	.loc_0x90:
	  lfs       f0, -0x4E78(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0xA4
	  lfs       f0, -0x4E80(r2)
	  fsubs     f2, f2, f0

	.loc_0xA4:
	  lfs       f0, -0x4E70(r2)
	  li        r3, 0x118
	  lfs       f1, 0x14(r30)
	  fdivs     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  bl        -0xEC09C

	.loc_0xC0:
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x160
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x4E74(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r30)
	  lfs       f1, 0x10(r30)
	  lfs       f0, -0x4E88(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xF0
	  lfs       f0, -0x4E80(r2)
	  fadds     f1, f1, f0

	.loc_0xF0:
	  lfs       f0, -0x4E80(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x104
	  fsubs     f1, f1, f0

	.loc_0x104:
	  stfs      f1, 0x10(r30)
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0x14(r30)
	  lfs       f2, 0x10(r30)
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x4E7C(r2)
	  fsubs     f2, f2, f1
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x130
	  lfs       f0, -0x4E80(r2)
	  fadds     f2, f2, f0

	.loc_0x130:
	  lfs       f0, -0x4E78(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x144
	  lfs       f0, -0x4E80(r2)
	  fsubs     f2, f2, f0

	.loc_0x144:
	  lfs       f0, -0x4E70(r2)
	  li        r3, 0x118
	  lfs       f1, 0x14(r30)
	  fdivs     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  bl        -0xEC13C

	.loc_0x160:
	  lfs       f2, 0x10(r30)
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x4E7C(r2)
	  fsubs     f2, f2, f1
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x180
	  lfs       f0, -0x4E80(r2)
	  fadds     f2, f2, f0

	.loc_0x180:
	  lfs       f0, -0x4E78(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x194
	  lfs       f0, -0x4E80(r2)
	  fsubs     f2, f2, f0

	.loc_0x194:
	  lfs       f0, -0x4E6C(r2)
	  lfs       f1, 0x14(r30)
	  fdivs     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  lfs       f1, 0x14(r30)
	  lfs       f0, -0x4E68(r2)
	  fmuls     f0, f0, f1
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  lfs       f0, 0x14(r30)
	  lfs       f2, -0x4E64(r2)
	  stfs      f0, 0x3C(r1)
	  lwz       r0, 0x3C(r1)
	  rlwinm    r0,r0,0,1,31
	  stw       r0, 0x3C(r1)
	  lfs       f0, 0x3C(r1)
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0x218
	  lfs       f1, 0xC(r30)
	  lfs       f0, 0x10(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x38(r1)
	  lwz       r0, 0x38(r1)
	  rlwinm    r0,r0,0,1,31
	  stw       r0, 0x38(r1)
	  lfs       f0, 0x38(r1)
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0x218
	  lfs       f0, 0x10(r30)
	  stfs      f0, 0xC(r30)
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0x14(r30)

	.loc_0x218:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, -0x4E60(r2)
	  lfs       f1, 0x28C(r3)
	  lfs       f2, 0x14(r30)
	  fdivs     f0, f1, f0
	  lfs       f1, 0xC(r30)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r30)
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x4E88(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x254
	  lfs       f0, -0x4E80(r2)
	  fadds     f1, f1, f0

	.loc_0x254:
	  lfs       f0, -0x4E80(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x268
	  fsubs     f1, f1, f0

	.loc_0x268:
	  stfs      f1, 0xC(r30)
	  lfs       f1, 0xC(r30)
	  bl        0x8A590
	  lfs       f0, 0xC(r30)
	  fmr       f31, f1
	  fmr       f1, f0
	  bl        0x8A714
	  lfs       f3, 0x1C(r30)
	  li        r5, 0
	  lwz       r3, 0x8(r30)
	  fmuls     f1, f3, f1
	  fneg      f0, f3
	  lwz       r12, 0x0(r3)
	  fctiwz    f2, f1
	  lwz       r12, 0x1C(r12)
	  fmuls     f0, f0, f31
	  mtlr      r12
	  stfd      f2, 0x48(r1)
	  fadds     f1, f3, f0
	  lwz       r4, 0x4C(r1)
	  blrl
	  lfs       f0, 0xC(r30)
	  li        r4, 0x140
	  lwz       r3, 0x8(r30)
	  li        r0, 0xF0
	  fneg      f1, f0
	  sth       r4, 0xB8(r3)
	  li        r4, 0x79
	  sth       r0, 0xBA(r3)
	  bl        -0xAE24
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x4E5C(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x314
	  lfs       f0, -0x4E58(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x314
	  lwz       r3, 0x8(r30)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x328

	.loc_0x314:
	  lwz       r3, 0x8(r30)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x328:
	  lwz       r3, 0x0(r30)
	  bl        0x214D0
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
bool zen::ogDrawScrMenu::draw(Graphics& gfx)
{
	P2DPerspGraph graf(0, 0, 640, 480, 0.0f, 0.0f, 0.0f);
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
	int w     = _34->getWidth();
	int h     = _34->getHeight();
	f32 angle = atan2f(-gfx.mCamera->mViewZAxis.x, -gfx.mCamera->mViewZAxis.z);

	// final trial check?
	if (flowCont.mCurrentStage->mStageID == 4) {
		angle += PI;
	}
	_34->rotateZ(w / 2, h / 2, angle);

	if (playerState->hasRadar()) {
		_34->show();
	} else {
		_34->hide();
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
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stmw      r27, 0x44(r1)
	  li        r28, 0x1
	  addi      r31, r3, 0
	  stw       r28, 0x0(r3)
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0x58(r3)
	  sth       r28, 0x4(r3)
	  lwz       r3, 0x10(r3)
	  stfs      f0, 0x10(r3)
	  lfs       f0, -0x4E50(r2)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x18(r3)
	  stfs      f0, 0x1C(r3)
	  stb       r4, 0x4(r3)
	  stb       r4, 0x5(r3)
	  lwz       r3, 0x10(r31)
	  stb       r4, 0x4(r3)
	  lwz       r3, 0x8(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x10(r31)
	  stb       r4, 0x5(r3)
	  lwz       r3, 0xC(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x48(r31)
	  bl        -0x780
	  lwz       r30, 0x18(r31)
	  sth       r28, 0x20(r30)
	  lfs       f1, -0x4E88(r2)
	  stfs      f1, 0xC(r30)
	  stfs      f1, 0x10(r30)
	  lfs       f0, -0x4E84(r2)
	  stfs      f0, 0x1C(r30)
	  stfs      f1, 0x14(r30)
	  lfs       f1, 0xC(r30)
	  bl        0x890E0
	  lfs       f0, 0xC(r30)
	  fmr       f31, f1
	  fmr       f1, f0
	  bl        0x89264
	  lfs       f2, 0x1C(r30)
	  li        r5, 0
	  lwz       r3, 0x8(r30)
	  fmuls     f1, f2, f1
	  fneg      f0, f2
	  lwz       r12, 0x0(r3)
	  fctiwz    f1, f1
	  lwz       r12, 0x1C(r12)
	  fmuls     f0, f0, f31
	  mtlr      r12
	  stfd      f1, 0x38(r1)
	  fadds     f1, f2, f0
	  lwz       r4, 0x3C(r1)
	  blrl
	  lfs       f0, 0xC(r30)
	  li        r29, 0x140
	  lwz       r3, 0x8(r30)
	  li        r30, 0xF0
	  fneg      f1, f0
	  sth       r29, 0xB8(r3)
	  li        r4, 0x79
	  sth       r30, 0xBA(r3)
	  bl        -0xC2D4
	  lwz       r27, 0x1C(r31)
	  li        r0, 0x2
	  sth       r0, 0x20(r27)
	  lfs       f0, -0x4E74(r2)
	  stfs      f0, 0xC(r27)
	  stfs      f0, 0x10(r27)
	  lfs       f0, -0x4E84(r2)
	  stfs      f0, 0x1C(r27)
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0x14(r27)
	  lfs       f1, 0xC(r27)
	  bl        0x89044
	  lfs       f0, 0xC(r27)
	  fmr       f31, f1
	  fmr       f1, f0
	  bl        0x891C8
	  lfs       f2, 0x1C(r27)
	  li        r5, 0
	  lwz       r3, 0x8(r27)
	  fmuls     f1, f2, f1
	  fneg      f0, f2
	  lwz       r12, 0x0(r3)
	  fctiwz    f1, f1
	  lwz       r12, 0x1C(r12)
	  fmuls     f0, f0, f31
	  mtlr      r12
	  stfd      f1, 0x30(r1)
	  fadds     f1, f2, f0
	  lwz       r4, 0x34(r1)
	  blrl
	  lfs       f0, 0xC(r27)
	  li        r4, 0x79
	  lwz       r3, 0x8(r27)
	  fneg      f1, f0
	  sth       r29, 0xB8(r3)
	  sth       r30, 0xBA(r3)
	  bl        -0xC368
	  lwz       r27, 0x20(r31)
	  sth       r28, 0x20(r27)
	  lfs       f1, -0x4E88(r2)
	  stfs      f1, 0xC(r27)
	  stfs      f1, 0x10(r27)
	  lfs       f0, -0x4E84(r2)
	  stfs      f0, 0x1C(r27)
	  stfs      f1, 0x14(r27)
	  lfs       f1, 0xC(r27)
	  bl        0x88FB8
	  lfs       f0, 0xC(r27)
	  fmr       f31, f1
	  fmr       f1, f0
	  bl        0x8913C
	  lfs       f2, 0x1C(r27)
	  li        r5, 0
	  lwz       r3, 0x8(r27)
	  fmuls     f1, f2, f1
	  fneg      f0, f2
	  lwz       r12, 0x0(r3)
	  fctiwz    f1, f1
	  lwz       r12, 0x1C(r12)
	  fmuls     f0, f0, f31
	  mtlr      r12
	  stfd      f1, 0x28(r1)
	  fadds     f1, f2, f0
	  lwz       r4, 0x2C(r1)
	  blrl
	  lfs       f0, 0xC(r27)
	  li        r4, 0x79
	  lwz       r3, 0x8(r27)
	  fneg      f1, f0
	  sth       r29, 0xB8(r3)
	  sth       r30, 0xBA(r3)
	  bl        -0xC3F4
	  lwz       r4, 0x50(r31)
	  lwz       r3, 0x14(r31)
	  lwz       r4, 0x24(r4)
	  bl        -0xC3BC
	  li        r3, 0x116
	  bl        -0xED8A4
	  lmw       r27, 0x44(r1)
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
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
	if (!input->keyClick(KBBTN_MSTICK_DOWN) && input->keyClick(KBBTN_MSTICK_LEFT)) {
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
	if (input->keyClick(KBBTN_MSTICK_DOWN)) {
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
	if (mStatus = Status_NULL) {
		return mStatus;
	}

	for (int i = 0; i < 3; i++) {
		_18[i]->update(input, _54, _55);
	}
	_48->update(input);

	if (mStatus == Status_1) {
		_58 += gsys->getFrameTime();
		if (_58 > 0.3f) {
			mStatus = Status_0;
			for (int i = 0; i < 3; i++) {
				_30[i]->setScale(1.0f);
			}
			_0C->setAlpha(mAlpha);
		} else {
			f32 scale = _58 / 0.3f * 255.0f;
			mAlpha    = scale;
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
			_0C->setAlpha(mAlpha);
		} else {
			f32 scale = _58 / 0.3f * 255.0f;
			mAlpha    = scale;
			for (int i = 0; i < 3; i++) {
				_30[i]->setScale(scale);
				_0C->setAlpha(mAlpha * scale);
			}
		}
		return mStatus;
	}

	if (mStatus = Status_3) {
		mStatus = Status_NULL;
		return mStatus;
	}

	_54 = false;
	_55 = false;

	if (input->keyClick(KBBTN_MSTICK_UP)) {
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
		_10->update();
		_08->update();
	}

	return mStatus;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x120(r1)
	  stfd      f31, 0x118(r1)
	  stw       r31, 0x114(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x110(r1)
	  mr        r30, r3
	  stw       r29, 0x10C(r1)
	  stw       r28, 0x108(r1)
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x38
	  b         .loc_0x574

	.loc_0x38:
	  li        r28, 0
	  rlwinm    r0,r28,2,0,29
	  add       r29, r30, r0

	.loc_0x44:
	  lwz       r3, 0x18(r29)
	  mr        r4, r31
	  lbz       r5, 0x54(r30)
	  lbz       r6, 0x55(r30)
	  bl        -0x1934
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x3
	  addi      r29, r29, 0x4
	  blt+      .loc_0x44
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1C8
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x58(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x58(r30)
	  lfs       f1, 0x58(r30)
	  lfs       f0, -0x4E44(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xE8
	  li        r0, 0
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x30(r30)
	  lfs       f0, -0x4E50(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x34(r30)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x38(r30)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lwz       r3, 0xC(r30)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x1C0

	.loc_0xE8:
	  fdivs     f2, f1, f0
	  lfs       f0, -0x4E40(r2)
	  lis       r4, 0x4330
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x100(r1)
	  lwz       r0, 0x104(r1)
	  stb       r0, 0x5C(r30)
	  lwz       r3, 0x30(r30)
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lfd       f1, -0x4E28(r2)
	  stw       r0, 0xFC(r1)
	  lwz       r3, 0xC(r30)
	  stw       r4, 0xF8(r1)
	  lfd       f0, 0xF8(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0xF0(r1)
	  lwz       r0, 0xF4(r1)
	  stb       r0, 0xF0(r3)
	  lwz       r3, 0x34(r30)
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lwz       r3, 0xC(r30)
	  stw       r0, 0xEC(r1)
	  stw       r4, 0xE8(r1)
	  lfd       f0, 0xE8(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0xE0(r1)
	  lwz       r0, 0xE4(r1)
	  stb       r0, 0xF0(r3)
	  lwz       r3, 0x38(r30)
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lwz       r3, 0xC(r30)
	  stw       r0, 0xDC(r1)
	  stw       r4, 0xD8(r1)
	  lfd       f0, 0xD8(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0xD0(r1)
	  lwz       r0, 0xD4(r1)
	  stb       r0, 0xF0(r3)

	.loc_0x1C0:
	  lwz       r3, 0x0(r30)
	  b         .loc_0x574

	.loc_0x1C8:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x32C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x58(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x58(r30)
	  lfs       f0, 0x58(r30)
	  lfs       f1, -0x4E44(r2)
	  fcmpo     cr0, f0, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x244
	  li        r0, 0x3
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  lwz       r3, 0x30(r30)
	  lfs       f0, -0x4E88(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x34(r30)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x38(r30)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0xC(r30)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x324

	.loc_0x244:
	  fsubs     f2, f1, f0
	  lfs       f0, -0x4E40(r2)
	  lis       r4, 0x4330
	  fmuls     f0, f0, f2
	  fdivs     f2, f2, f1
	  fdivs     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0xD0(r1)
	  lwz       r0, 0xD4(r1)
	  stb       r0, 0x5C(r30)
	  lwz       r3, 0x30(r30)
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lfd       f1, -0x4E28(r2)
	  stw       r0, 0xDC(r1)
	  lwz       r3, 0xC(r30)
	  stw       r4, 0xD8(r1)
	  lfd       f0, 0xD8(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0xE0(r1)
	  lwz       r0, 0xE4(r1)
	  stb       r0, 0xF0(r3)
	  lwz       r3, 0x34(r30)
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lwz       r3, 0xC(r30)
	  stw       r0, 0xEC(r1)
	  stw       r4, 0xE8(r1)
	  lfd       f0, 0xE8(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0xF0(r1)
	  lwz       r0, 0xF4(r1)
	  stb       r0, 0xF0(r3)
	  lwz       r3, 0x38(r30)
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC8(r3)
	  lbz       r0, 0x5D(r30)
	  lwz       r3, 0xC(r30)
	  stw       r0, 0xFC(r1)
	  stw       r4, 0xF8(r1)
	  lfd       f0, 0xF8(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x100(r1)
	  lwz       r0, 0x104(r1)
	  stb       r0, 0xF0(r3)

	.loc_0x324:
	  lwz       r3, 0x0(r30)
	  b         .loc_0x574

	.loc_0x32C:
	  cmpwi     r0, 0x3
	  bne-      .loc_0x344
	  li        r0, -0x1
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x574

	.loc_0x344:
	  li        r0, 0
	  stb       r0, 0x54(r30)
	  stb       r0, 0x55(r30)
	  lwz       r0, 0x28(r31)
	  andi.     r0, r0, 0xA000
	  beq-      .loc_0x37C
	  lfs       f0, -0x4E88(r2)
	  li        r0, 0x2
	  li        r3, 0x117
	  stfs      f0, 0x58(r30)
	  stw       r0, 0x0(r30)
	  bl        -0xEDC30
	  lwz       r3, 0x14(r30)
	  bl        -0xB9C4

	.loc_0x37C:
	  lha       r3, 0x4(r30)
	  extsh.    r0, r3
	  beq-      .loc_0x470
	  cmpwi     r3, 0x1
	  bne-      .loc_0x404
	  lwz       r3, 0x10(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stb       r5, 0x4(r3)
	  lwz       r3, 0x8(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x10(r30)
	  stb       r4, 0x5(r3)
	  lwz       r3, 0xC(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x28(r31)
	  rlwinm.   r0,r3,0,14,14
	  bne-      .loc_0x3F4
	  rlwinm.   r0,r3,0,13,13
	  beq-      .loc_0x3F4
	  lha       r3, 0x4(r30)
	  addi      r0, r3, 0x1
	  sth       r0, 0x4(r30)
	  stb       r4, 0x55(r30)
	  lwz       r3, 0x14(r30)
	  bl        -0xBA3C

	.loc_0x3F4:
	  lwz       r3, 0x14(r30)
	  mr        r4, r31
	  bl        -0xC190
	  b         .loc_0x470

	.loc_0x404:
	  cmpwi     r3, 0x2
	  bne-      .loc_0x470
	  lwz       r3, 0x10(r30)
	  li        r5, 0x1
	  li        r4, 0
	  stb       r5, 0x4(r3)
	  lwz       r3, 0x8(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x10(r30)
	  stb       r4, 0x5(r3)
	  lwz       r3, 0xC(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x28(r31)
	  rlwinm.   r0,r0,0,14,14
	  beq-      .loc_0x468
	  lha       r3, 0x4(r30)
	  subi      r0, r3, 0x1
	  sth       r0, 0x4(r30)
	  stb       r5, 0x54(r30)
	  lwz       r3, 0x14(r30)
	  bl        -0xC71C

	.loc_0x468:
	  lwz       r3, 0x4C(r30)
	  bl        -0x1744

	.loc_0x470:
	  lwz       r31, 0x10(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x10(r31)
	  lfs       f31, 0x28C(r3)
	  fneg      f1, f0
	  bl        0x88C30
	  lfs       f0, -0x4E38(r2)
	  lfs       f2, -0x4E3C(r2)
	  fmuls     f0, f0, f1
	  fadds     f0, f2, f0
	  stfs      f0, 0x14(r31)
	  lfs       f0, 0x10(r31)
	  fneg      f1, f0
	  bl        0x88C10
	  lfs       f0, -0x4E38(r2)
	  lfs       f2, -0x4E3C(r2)
	  fmuls     f0, f0, f1
	  fadds     f0, f2, f0
	  stfs      f0, 0x18(r31)
	  lfs       f0, 0x10(r31)
	  fneg      f1, f0
	  bl        0x88A5C
	  lfs       f0, -0x4E30(r2)
	  li        r3, 0x30
	  lfs       f2, -0x4E34(r2)
	  li        r0, 0
	  fmuls     f0, f0, f1
	  fadds     f0, f2, f0
	  stfs      f0, 0x1C(r31)
	  lwz       r4, 0x8(r31)
	  sth       r3, 0xB8(r4)
	  sth       r3, 0xBA(r4)
	  lwz       r4, 0xC(r31)
	  sth       r0, 0xB8(r4)
	  sth       r3, 0xBA(r4)
	  lfs       f1, 0x1C(r31)
	  lwz       r3, 0x8(r31)
	  lfs       f0, 0x14(r31)
	  stfs      f0, 0xC0(r3)
	  stfs      f1, 0xC4(r3)
	  lfs       f1, -0x4E50(r2)
	  stfs      f1, 0xC8(r3)
	  lfs       f2, 0x1C(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f0, 0x18(r31)
	  stfs      f0, 0xC0(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f1, 0xC8(r3)
	  lfs       f0, -0x4E60(r2)
	  lfs       f1, -0x4E2C(r2)
	  fdivs     f0, f31, f0
	  lfs       f2, 0x10(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x10(r31)
	  lfs       f1, 0x10(r31)
	  lfs       f0, -0x4E80(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x568
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r31)

	.loc_0x568:
	  lwz       r3, 0x8(r30)
	  bl        0x1F9B0
	  lwz       r3, 0x0(r30)

	.loc_0x574:
	  lwz       r0, 0x124(r1)
	  lfd       f31, 0x118(r1)
	  lwz       r31, 0x114(r1)
	  lwz       r30, 0x110(r1)
	  lwz       r29, 0x10C(r1)
	  lwz       r28, 0x108(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr
	*/
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
			_60.set(1.0f, y, 1.0f);
		}
	} else {
		_60.set(1.0f, 0.0f, 1.0f);
	}

	if (mStatus == Status_0) {
		_50->drawHougaku(gfx);
		_18[2]->draw(gfx);
		_10->draw();
	}
	return true;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x430(r1)
	  stmw      r27, 0x41C(r1)
	  mr        r29, r3
	  addi      r30, r4, 0
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x2C
	  li        r3, 0
	  b         .loc_0x3B4

	.loc_0x2C:
	  lfs       f1, -0x4E54(r2)
	  addi      r3, r1, 0x334
	  lfs       f2, -0x4E50(r2)
	  li        r4, 0
	  lfs       f3, -0x4E4C(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1CF78
	  addi      r3, r1, 0x334
	  bl        0x1D080
	  lfs       f2, -0x4E50(r2)
	  addi      r4, r1, 0x320
	  lwz       r0, -0x4E20(r2)
	  li        r3, 0
	  fmr       f4, f2
	  stw       r0, 0x320(r1)
	  lfs       f1, -0x4E88(r2)
	  lfs       f3, -0x4E1C(r2)
	  bl        0x80754
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  bl        0x808F8
	  lwz       r3, 0x8(r29)
	  addi      r6, r1, 0x334
	  li        r4, 0
	  li        r5, 0
	  bl        0x1FC6C
	  lwz       r28, 0x18(r29)
	  addi      r3, r1, 0x23C
	  lfs       f1, -0x4E54(r2)
	  li        r4, 0
	  lfs       f2, -0x4E50(r2)
	  lfs       f3, -0x4E4C(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1CF00
	  addi      r3, r1, 0x23C
	  bl        0x1D008
	  lwz       r3, 0x0(r28)
	  addi      r6, r1, 0x23C
	  li        r4, 0
	  li        r5, 0
	  bl        0x1FC28
	  lis       r3, 0x802E
	  lfs       f1, -0x4E54(r2)
	  addi      r28, r3, 0x698
	  lfs       f2, -0x4E50(r2)
	  lis       r3, 0x802E
	  stw       r28, 0x23C(r1)
	  addi      r31, r3, 0x5D4
	  lfs       f3, -0x4E4C(r2)
	  stw       r31, 0x23C(r1)
	  addi      r3, r1, 0x158
	  li        r4, 0
	  lwz       r27, 0x1C(r29)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1CEA4
	  addi      r3, r1, 0x158
	  bl        0x1CFAC
	  lwz       r3, 0x0(r27)
	  addi      r6, r1, 0x158
	  li        r4, 0
	  li        r5, 0
	  bl        0x1FBCC
	  stw       r28, 0x158(r1)
	  stw       r31, 0x158(r1)
	  lha       r0, 0x4(r29)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1CC
	  lwz       r3, 0x48(r29)
	  lfs       f1, 0xC(r3)
	  lfs       f0, 0x10(r3)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x180
	  lfs       f1, -0x4E88(r2)
	  lfs       f0, 0x14(r3)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x180
	  li        r0, 0x1
	  b         .loc_0x184

	.loc_0x180:
	  li        r0, 0

	.loc_0x184:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1CC
	  lfs       f0, 0x64(r29)
	  lfs       f1, -0x4E50(r2)
	  fmr       f2, f0
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x1B4
	  lfs       f0, -0x4E2C(r2)
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x1B4
	  fmr       f2, f1

	.loc_0x1B4:
	  lfs       f0, 0xDE0(r13)
	  stfs      f0, 0x60(r29)
	  stfs      f2, 0x64(r29)
	  lfs       f0, 0xDE4(r13)
	  stfs      f0, 0x68(r29)
	  b         .loc_0x1E4

	.loc_0x1CC:
	  lfs       f0, 0xDE8(r13)
	  stfs      f0, 0x60(r29)
	  lfs       f0, 0xDEC(r13)
	  stfs      f0, 0x64(r29)
	  lfs       f0, 0xDF0(r13)
	  stfs      f0, 0x68(r29)

	.loc_0x1E4:
	  lwz       r4, 0x50(r29)
	  lwz       r3, 0x14(r29)
	  lwz       r4, 0x24(r4)
	  lwz       r5, 0x3C(r3)
	  lwz       r3, 0x60(r29)
	  lwz       r0, 0x64(r29)
	  stw       r3, 0xC0(r5)
	  stw       r0, 0xC4(r5)
	  lwz       r0, 0x68(r29)
	  stw       r0, 0xC8(r5)
	  lha       r6, 0x1A(r4)
	  lha       r0, 0x1E(r4)
	  lha       r7, 0x18(r4)
	  sub       r3, r0, r6
	  lha       r0, 0x1C(r4)
	  srawi     r3, r3, 0x1
	  addze     r3, r3
	  sub       r0, r0, r7
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r7, r0
	  extsh     r0, r0
	  add       r3, r6, r3
	  sth       r0, 0xB8(r5)
	  extsh     r0, r3
	  sth       r0, 0xBA(r5)
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0
	  bne-      .loc_0x398
	  lwz       r3, 0x14(r29)
	  mr        r4, r30
	  bl        -0xBE08
	  lwz       r31, 0x50(r29)
	  lwz       r4, 0x2E4(r30)
	  lwz       r5, 0x34(r31)
	  lfs       f0, 0x194(r4)
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  fneg      f1, f0
	  lfs       f0, 0x19C(r4)
	  sub       r4, r0, r3
	  lha       r3, 0x1A(r5)
	  lha       r0, 0x1E(r5)
	  srawi     r28, r4, 0x1
	  fneg      f2, f0
	  addze     r28, r28
	  sub       r0, r0, r3
	  srawi     r27, r0, 0x1
	  addze     r27, r27
	  bl        0x88584
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r3, 0xA8(r3)
	  lhz       r0, 0x26(r3)
	  cmplwi    r0, 0x4
	  bne-      .loc_0x2CC
	  lfs       f0, -0x4E78(r2)
	  fadds     f1, f1, f0

	.loc_0x2CC:
	  lwz       r3, 0x34(r31)
	  extsh     r0, r28
	  li        r4, 0x7A
	  sth       r0, 0xB8(r3)
	  extsh     r0, r27
	  sth       r0, 0xBA(r3)
	  bl        -0xCCA4
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x11(r3)
	  rlwinm.   r0,r0,0,31,31
	  bne-      .loc_0x310
	  lwz       r3, 0x34(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x324

	.loc_0x310:
	  lwz       r3, 0x34(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x324:
	  lwz       r27, 0x20(r29)
	  addi      r3, r1, 0x64
	  lfs       f1, -0x4E54(r2)
	  li        r4, 0
	  lfs       f2, -0x4E50(r2)
	  lfs       f3, -0x4E4C(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1CC7C
	  addi      r3, r1, 0x64
	  bl        0x1CD84
	  lwz       r3, 0x0(r27)
	  addi      r6, r1, 0x64
	  li        r4, 0
	  li        r5, 0
	  bl        0x1F9A4
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x64(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x64(r1)
	  li        r4, 0
	  li        r5, 0
	  lwz       r3, 0x10(r29)
	  li        r6, 0
	  lwz       r3, 0x0(r3)
	  bl        0x1F974

	.loc_0x398:
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x334(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x334(r1)
	  li        r3, 0x1

	.loc_0x3B4:
	  lmw       r27, 0x41C(r1)
	  lwz       r0, 0x434(r1)
	  addi      r1, r1, 0x430
	  mtlr      r0
	  blr
	*/
}
