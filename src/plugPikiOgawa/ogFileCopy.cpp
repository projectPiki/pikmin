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
}

/*
 * --INFO--
 * Address:	801972A8
 * Size:	0003A8
 */
void zen::ogScrFileSelectMgr::CopyEffectStart()
{
	Vector3f effPos;
	Vector3f attractorPos;

	P2DPane* pane1 = _3B0[_134];
	P2DPane* pane2 = _3D4[_119C];

	effPos.set(0.0f, 0.0f, 0.0f);
	effPos.x = f32(pane1->getPosH()) + f32(pane1->getWidth()) / 2.0f;
	effPos.y = 480.0f - (f32(pane1->getPosV()) + f32(pane1->getHeight()) / 2.0f);

	pane2->getDispPos(&attractorPos);
	attractorPos.y = 480.0f - attractorPos.y;

	mEfx = mEfxMgr->create(EFF2D_Unk42, effPos, nullptr, nullptr);
	mEfx->setNewtonField(attractorPos, 0.0046f, true);

	pane1 = _3BC[_134];
	pane2 = _3E0[_119C];

	effPos.set(0.0f, 0.0f, 0.0f);
	effPos.x = f32(pane1->getPosH()) + f32(pane1->getWidth()) / 2.0f;
	effPos.y = 480.0f - (f32(pane1->getPosV()) + f32(pane1->getHeight()) / 2.0f);

	pane2->getDispPos(&attractorPos);
	attractorPos.y = 480.0f - attractorPos.y;

	mEfx2 = mEfxMgr->create(EFF2D_Unk41, effPos, nullptr, nullptr);
	mEfx2->setNewtonField(attractorPos, 0.0046f, true);
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
			setOperateMode(OPMODE_Normal);
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
			setOperateMode(OPMODE_Normal);
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
		setOperateMode(OPMODE_Normal);
	} else if (status == 5) {
		_1197 = true;
		_118C = 3.0f;
		seSystem->playSysSe(SYSSE_CARDACCESS);
		gameflow.mMemoryCard.copyFile(_2C[_134], _2C[_119C]);
		CopyEffectStart();
		_314->hide();
	} else if (status == 6) {
		setOperateMode(OPMODE_Normal);
	}

	f32 badcompiler[4];
}
