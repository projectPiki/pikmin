#include "zen/ogFileSelect.h"
#include "zen/EffectMgr2D.h"
#include "zen/ogNitaku.h"
#include "P2D/Picture.h"
#include "P2D/TextBox.h"
#include "P2D/Pane.h"
#include "SoundMgr.h"
#include "gameflow.h"
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
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	8019719C
 * Size:	00010C
 */
void zen::ogScrFileSelectMgr::setOperateMode_Copy()
{
	SetTitleMsg(titleMsg_5);

	for (int i = 0; i < 3; i++) {
		if (i != _134) {
			_119C = i;
			break;
		}
	}

	PRINT("cL(%d,%d)  cR(%d,%d)\n", _104[_119C], _11C[_119C], _110[_119C], _128[_119C]);
	_A4.init(_2BC, _448, 'z00l', _104[_119C], _11C[_119C]);
	_D4.init(_2BC, _448, 'z00r', _110[_119C], _128[_119C]);
	_448->show();
	paneOnOffXY(false);
	_11A0 = 1;
	_A4.scale(1.0f, 0.25f);
	_D4.scale(1.0f, 0.25f);

	f32 badcompiler[4];
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void zen::ogScrFileSelectMgr::MoveCpyCursor(int id, f32 a2)
{
	_A4.move(_104[id], _11C[id], a2);
	_D4.move(_110[id], _128[id], a2);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801972A8
 * Size:	0003A8
 */
void zen::ogScrFileSelectMgr::CopyEffectStart()
{
	Vector3f pos1, pos2;

	pos1.set(0.0f, 0.0f, 0.0f);
	f32 w  = mPanes[_134]->getPosH() + mPanes[_134]->getWidth() / 2.0f;
	pos1.x = w;
	f32 h  = mPanes[_134]->getPosV() + mPanes[_134]->getHeight() / 2.0f;
	pos1.y = 480.0f - h;
	mEfx   = mEfxMgr->create(EFF2D_Unk42, pos1, nullptr, nullptr);
	mEfx->setNewtonField(pos1 - mEfx->getGPos(), 0.0046f, true);

	pos1.set(0.0f, 0.0f, 0.0f);
	w      = mPanes[_134]->getPosH() + mPanes[_134]->getWidth() / 2.0f;
	pos1.x = w;
	h      = mPanes[_134]->getPosV() + mPanes[_134]->getHeight() / 2.0f;
	pos1.y = 480.0f - h;
	mEfx2  = mEfxMgr->create(EFF2D_Unk42, pos1, nullptr, nullptr);
	mEfx2->setNewtonField(pos1 - mEfx2->getGPos(), 0.0046f, true);
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x2A
	  stw       r0, 0x4(r1)
	  li        r6, 0
	  li        r7, 0
	  stwu      r1, -0x120(r1)
	  stw       r31, 0x11C(r1)
	  lis       r31, 0x4330
	  addi      r5, r1, 0xC0
	  stw       r30, 0x118(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x114(r1)
	  lfs       f5, -0x4D80(r2)
	  stfs      f5, 0xC8(r1)
	  stfs      f5, 0xC4(r1)
	  stfs      f5, 0xC0(r1)
	  stfs      f5, 0xBC(r1)
	  stfs      f5, 0xB8(r1)
	  lha       r3, 0x134(r3)
	  lwz       r0, 0x119C(r30)
	  rlwinm    r3,r3,2,0,29
	  lfs       f1, 0xE18(r13)
	  add       r8, r30, r3
	  lfs       f0, 0xE1C(r13)
	  rlwinm    r0,r0,2,0,29
	  lwz       r9, 0x3B0(r8)
	  add       r3, r30, r0
	  lwz       r10, 0x3D4(r3)
	  stfs      f1, 0xC0(r1)
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0xE20(r13)
	  stfs      f0, 0xC8(r1)
	  lha       r8, 0x18(r9)
	  lha       r0, 0x1C(r9)
	  xoris     r3, r8, 0x8000
	  lfd       f4, -0x4D70(r2)
	  sub       r0, r0, r8
	  stw       r3, 0x10C(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f3, -0x4D7C(r2)
	  stw       r0, 0x104(r1)
	  lfs       f2, -0x4D78(r2)
	  stw       r31, 0x100(r1)
	  lfd       f0, 0x100(r1)
	  stw       r31, 0x108(r1)
	  fsubs     f0, f0, f4
	  lfd       f1, 0x108(r1)
	  fsubs     f1, f1, f4
	  fmuls     f0, f0, f3
	  fadds     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lha       r8, 0x1A(r9)
	  lha       r0, 0x1E(r9)
	  xoris     r3, r8, 0x8000
	  sub       r0, r0, r8
	  stw       r3, 0xFC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xF4(r1)
	  stw       r31, 0xF0(r1)
	  lfd       f0, 0xF0(r1)
	  stw       r31, 0xF8(r1)
	  fsubs     f0, f0, f4
	  lfd       f1, 0xF8(r1)
	  fsubs     f1, f1, f4
	  fmuls     f0, f0, f3
	  fadds     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0xC4(r1)
	  stfs      f5, 0x98(r1)
	  stfs      f5, 0x94(r1)
	  stfs      f5, 0x90(r1)
	  lfs       f0, 0x84(r10)
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x94(r10)
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0xA4(r10)
	  stfs      f0, 0x98(r1)
	  lwz       r0, 0x90(r1)
	  lwz       r3, 0x94(r1)
	  stw       r0, 0xB4(r1)
	  lwz       r0, 0x98(r1)
	  stw       r3, 0xB8(r1)
	  stw       r0, 0xBC(r1)
	  lfs       f0, 0xB8(r1)
	  fsubs     f0, f2, f0
	  stfs      f0, 0xB8(r1)
	  lwz       r3, 0x0(r30)
	  bl        0x52738
	  stw       r3, 0x4(r30)
	  lwz       r29, 0x4(r30)
	  mr        r3, r29
	  bl        -0x827A4
	  lfs       f1, 0xBC(r1)
	  addi      r6, r1, 0x68
	  lfs       f0, 0x8(r3)
	  addi      r5, r1, 0x64
	  addi      r4, r1, 0x60
	  fsubs     f0, f1, f0
	  lfs       f1, 0xB4(r1)
	  stfs      f0, 0x68(r1)
	  lfs       f2, 0xB8(r1)
	  lfs       f0, 0x4(r3)
	  fsubs     f0, f2, f0
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x0(r3)
	  addi      r3, r1, 0x84
	  fsubs     f0, f1, f0
	  stfs      f0, 0x60(r1)
	  bl        -0x16033C
	  lfs       f0, 0x84(r1)
	  addi      r5, r1, 0xC0
	  li        r4, 0x29
	  stfs      f0, 0x170(r29)
	  li        r6, 0
	  li        r7, 0
	  lfs       f0, 0x88(r1)
	  stfs      f0, 0x174(r29)
	  lfs       f0, 0x8C(r1)
	  stfs      f0, 0x178(r29)
	  lfs       f0, -0x4D74(r2)
	  stfs      f0, 0x17C(r29)
	  lwz       r0, 0x84(r29)
	  oris      r0, r0, 0x10
	  stw       r0, 0x84(r29)
	  lha       r3, 0x134(r30)
	  lwz       r0, 0x119C(r30)
	  rlwinm    r3,r3,2,0,29
	  lfs       f1, 0xE24(r13)
	  add       r8, r30, r3
	  lfs       f0, 0xE28(r13)
	  rlwinm    r0,r0,2,0,29
	  lwz       r9, 0x3BC(r8)
	  add       r3, r30, r0
	  lwz       r10, 0x3E0(r3)
	  stfs      f1, 0xC0(r1)
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0xE2C(r13)
	  stfs      f0, 0xC8(r1)
	  lha       r8, 0x18(r9)
	  lha       r0, 0x1C(r9)
	  xoris     r3, r8, 0x8000
	  lfd       f4, -0x4D70(r2)
	  sub       r0, r0, r8
	  stw       r3, 0xEC(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f3, -0x4D7C(r2)
	  stw       r0, 0xE4(r1)
	  lfs       f2, -0x4D78(r2)
	  stw       r31, 0xE0(r1)
	  lfd       f0, 0xE0(r1)
	  stw       r31, 0xE8(r1)
	  fsubs     f0, f0, f4
	  lfd       f1, 0xE8(r1)
	  fsubs     f1, f1, f4
	  fmuls     f0, f0, f3
	  fadds     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lha       r8, 0x1A(r9)
	  lha       r0, 0x1E(r9)
	  xoris     r3, r8, 0x8000
	  sub       r0, r0, r8
	  stw       r3, 0xDC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xD4(r1)
	  stw       r31, 0xD0(r1)
	  lfd       f0, 0xD0(r1)
	  stw       r31, 0xD8(r1)
	  fsubs     f0, f0, f4
	  lfd       f1, 0xD8(r1)
	  fsubs     f1, f1, f4
	  fmuls     f0, f0, f3
	  fadds     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0xC4(r1)
	  lfs       f0, -0x4D80(r2)
	  stfs      f0, 0x80(r1)
	  stfs      f0, 0x7C(r1)
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x84(r10)
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x94(r10)
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0xA4(r10)
	  stfs      f0, 0x80(r1)
	  lwz       r0, 0x78(r1)
	  lwz       r3, 0x7C(r1)
	  stw       r0, 0xB4(r1)
	  lwz       r0, 0x80(r1)
	  stw       r3, 0xB8(r1)
	  stw       r0, 0xBC(r1)
	  lfs       f0, 0xB8(r1)
	  fsubs     f0, f2, f0
	  stfs      f0, 0xB8(r1)
	  lwz       r3, 0x0(r30)
	  bl        0x5258C
	  stw       r3, 0x8(r30)
	  lwz       r29, 0x8(r30)
	  mr        r3, r29
	  bl        -0x82950
	  lfs       f1, 0xBC(r1)
	  addi      r6, r1, 0x5C
	  lfs       f0, 0x8(r3)
	  addi      r5, r1, 0x58
	  addi      r4, r1, 0x54
	  fsubs     f0, f1, f0
	  lfs       f1, 0xB4(r1)
	  stfs      f0, 0x5C(r1)
	  lfs       f2, 0xB8(r1)
	  lfs       f0, 0x4(r3)
	  fsubs     f0, f2, f0
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x0(r3)
	  addi      r3, r1, 0x6C
	  fsubs     f0, f1, f0
	  stfs      f0, 0x54(r1)
	  bl        -0x1604E8
	  lfs       f0, 0x6C(r1)
	  stfs      f0, 0x170(r29)
	  lfs       f0, 0x70(r1)
	  stfs      f0, 0x174(r29)
	  lfs       f0, 0x74(r1)
	  stfs      f0, 0x178(r29)
	  lfs       f0, -0x4D74(r2)
	  stfs      f0, 0x17C(r29)
	  lwz       r0, 0x84(r29)
	  oris      r0, r0, 0x10
	  stw       r0, 0x84(r29)
	  lwz       r0, 0x124(r1)
	  lwz       r31, 0x11C(r1)
	  lwz       r30, 0x118(r1)
	  lwz       r29, 0x114(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80197650
 * Size:	000488
 */
void zen::ogScrFileSelectMgr::OperateCopy(Controller* input)
{

	if (_1198) {
		_300->show();
		_118C -= gsys->getFrameTime();
		if (_118C < 0.0f) {
			_1198 = false;
			setOperateMode(fileOp_0);
			_300->hide();
		}
		return;
	}

	if (_1197) {
		_2F8->show();
		_2CC->show();
		f32 rate = _118C;
		int x, y;
		if (rate > 2.7f) {
			y = _2CC->getPosV();
			x = (rate - 2.7f) / 0.3f * 640.0f;
		} else if (rate < 0.3f) {
			y = _2CC->getPosV();
			x = (rate - 0.3f) / 0.3f * 640.0f;
			_2CC->move(x, y);
		} else {
			x = _2CC->getPosH();
			y = _2CC->getPosV();
		}
		_2CC->move(x, y);
		_118C -= gsys->getFrameTime();

		if (_118C < 0.0f && gameflow.mMemoryCard.hasCardFinished()) {
			seSystem->playSysSe(SYSSE_CARDOK);
			copyCardInfosSub();
			ChkNewData();
			_1197 = false;
			_1198 = true;
			_118C = 1.0f;
			_2F8->hide();
			_2CC->hide();
			mEfx->finish();
			mEfx2->finish();
		}
		return;
	}

	if (_11A0) {
		if (input->keyClick(KBBTN_B)) {
			seSystem->playSysSe(SYSSE_CANCEL);
			setOperateMode(fileOp_0);
		} else if (input->keyClick(KBBTN_A)) {
			seSystem->playSysSe(SYSSE_DECIDE1);
			_11A0 = false;
			_2D8->show();
			_2D0->show();
			_2D0->setAlpha(_2D4->getAlphaChar());
			_A4.scale(0.0f, 0.25f);
			_D4.scale(0.0f, 0.25f);
			OpenYesNoWindow();
			SetTitleMsg(titleMsg_6);
		} else if (input->keyClick(KBBTN_MSTICK_LEFT)) {
			for (int i = 0; i < 3; i++) {
				if (i != _134) {
					seSystem->playSysSe(SYSSE_MOVE1);
					_119C = i;
					break;
				}
			}
			MoveCpyCursor(_119C, 0.25f);
		} else if (input->keyClick(KBBTN_MSTICK_RIGHT)) {
			for (int i = 2; i >= 0; i--) {
				if (i != _134) {
					seSystem->playSysSe(SYSSE_MOVE1);
					_119C = i;
					break;
				}
			}
			MoveCpyCursor(_119C, 0.25f);
		}
		return;
	}

	ogNitakuMgr::NitakuStatus status = mNitaku->update(input);
	if (status >= 4) {
		CloseYesNoWindow();
	}
	if (status == ogNitakuMgr::Status_4) {
		seSystem->playSysSe(SYSSE_CANCEL);
		setOperateMode(fileOp_0);
	} else if (status == 5) {
		_1197 = true;
		_118C = 3.0f;
		seSystem->playSysSe(SYSSE_CARDACCESS);
		gameflow.mMemoryCard.copyFile(_24[_134], _24[_119C]);
		CopyEffectStart();
		_314->hide();
	} else if (status == 6) {
		setOperateMode(fileOp_0);
	}

	f32 badcompiler[4];
}
