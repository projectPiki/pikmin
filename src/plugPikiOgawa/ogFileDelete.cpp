#include "zen/ogFileSelect.h"
#include "zen/EffectMgr2D.h"
#include "zen/ogNitaku.h"
#include "P2D/Pane.h"
#include "gameflow.h"
#include "SoundMgr.h"
#include "P2D/Picture.h"
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
 * Address:	80197AD8
 * Size:	000064
 */
void zen::ogScrFileSelectMgr::setOperateMode_Delete()
{
	SetTitleMsg(titleMsg_2);
	OpenYesNoWindow();
	paneOnOffXY(false);
	_A4.scale(0.0f, 0.001f);
	_D4.scale(0.0f, 0.001f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000178
 */
void zen::ogScrFileSelectMgr::DeleteEffectStart()
{
	SetTitleMsg(titleMsg_3);
	Vector3f pos1, pos2;

	pos1.set(0.0f, 0.0f, 0.0f);
	f32 w  = _3B0[_134]->getPosH() + _3B0[_134]->getWidth() / 2.0f;
	pos1.x = w;

	f32 h  = _3B0[_134]->getPosV() + _3B0[_134]->getHeight() / 2.0f;
	pos1.y = 480.0f - h;
	mEfxMgr->create(EFF2D_Unk44, pos1, nullptr, nullptr);

	pos2.set(pos1.x, (480.0f - pos1.y) - 80.0f, 0.0f);
	mEfxMgr->create(EFF2D_Unk43, pos2, nullptr, nullptr);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80197B3C
 * Size:	0003EC
 */
void zen::ogScrFileSelectMgr::OperateDelete(Controller* input)
{
	if (_1196) {
		_1188 -= gsys->getFrameTime();
		if (_1188 < 0.0f) {
			_1196 = false;
			setOperateMode(OPMODE_Normal);
		}
		return;
	}

	if (_1195) {
		_2CC->show();
		f32 rate = _1188;
		int x, y;
		if (rate > 1.7f) {
			y = _2CC->getPosV();
			x = (rate - 1.7f) / 0.3f * 640.0f;
		} else if (rate < 0.3f) {
			y = _2CC->getPosV();
			x = (rate - 0.3f) / 0.3f * 640.0f;
			_2CC->move(x, y);
		} else {
			x = _2CC->getPosH();
			y = _2CC->getPosV();
		}
		_2CC->move(x, y);
		_1188 -= gsys->getFrameTime();

		if (!_1199 && gameflow.mMemoryCard.hasCardFinished()) {
			_1199 = true;
			copyCardInfosSub();
			ChkNewData();
			seSystem->playSysSe(SYSSE_CARDOK);
		}

		if (_1199 && _1188 < 0.0f) {
			_1195 = false;
			_1196 = true;
			_1188 = 1.0f;
			_2CC->hide();
			SetTitleMsg(titleMsg_4);
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
		seSystem->playSysSe(SYSSE_CARDACCESS);
		gameflow.mMemoryCard.delFile(_2C[_134]);
		DeleteEffectStart();
		_1188 = 2.0f;
		_1195 = true;
		_1199 = false;
	} else if (status == 6) {
		setOperateMode(OPMODE_Normal);
	}
}
