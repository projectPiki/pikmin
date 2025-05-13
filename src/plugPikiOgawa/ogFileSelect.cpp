#include "zen/ogFileSelect.h"
#include "zen/ogNitaku.h"
#include "zen/ogSub.h"
#include "zen/EffectMgr2D.h"
#include "zen/DrawCommon.h"
#include "P2D/Graph.h"
#include "P2D/Pane.h"
#include "P2D/Picture.h"
#include "P2D/TextBox.h"
#include "P2D/Screen.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "Graphics.h"
#include "MemoryCard.h"
#include "sysNew.h"
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
DEFINE_PRINT("OgFileSelectSection")

/*
 * --INFO--
 * Address:	80187790
 * Size:	000140
 */
void zen::ogScrFileSelectMgr::copyCardInfosSub()
{
	CardQuickInfo infos[4];
	gameflow.mMemoryCard.getQuickInfos(infos);

	for (int i = 0; i < 3; i++) {
		_2C[i] = infos[i];
	}
}

/*
 * --INFO--
 * Address:	801878D0
 * Size:	0001F4
 */
bool zen::ogScrFileSelectMgr::getCardFileInfos()
{
	if (gameflow.mMemoryCard.getMemoryCardState(true) == 0 && gameflow.mMemoryCard.mSaveFileIndex >= 0) {
		bool vibe   = gameflow.mGamePrefs.getVibeMode();
		bool stereo = gameflow.mGamePrefs.getStereoMode();
		bool child  = gameflow.mGamePrefs.getChildMode();
		u8 bgmVol   = gameflow.mGamePrefs.getBgmVol();
		u8 sfxVol   = gameflow.mGamePrefs.mSfxVol; // stack's one too big, something's gotta give

		gameflow.mMemoryCard.loadOptions();

		gameflow.mGamePrefs.setVibeMode(vibe);
		gameflow.mGamePrefs.setStereoMode(stereo);
		gameflow.mGamePrefs.setChildMode(child);
		gameflow.mGamePrefs.setBgmVol(bgmVol);
		gameflow.mGamePrefs.setSfxVol(sfxVol);

		copyCardInfosSub();
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	80187AC4
 * Size:	000020
 */
void zen::ogScrFileSelectMgr::paneOnOffXY(bool set)
{
	if (mSaveMode) {
		_278 = false;
	} else {
		_278 = set;
	}
}

/*
 * --INFO--
 * Address:	80187AE4
 * Size:	0000E0
 */
void zen::ogScrFileSelectMgr::MovePaneXY()
{
	int x0 = _2C4->getPosH();
	int y0 = _2C4->getPosV();
	int x1 = _2C8->getPosH();
	int y1 = _2C8->getPosV();

	if (_278) {
		if (x0 > _270) {
			x0 -= 40;
			if (x0 < _270) {
				x0 = _270;
			}
		}

		if (x1 > _274) {
			x1 -= 20;
			if (x1 < _274) {
				x1 = _274;
			}
		}
	} else {
		if (x0 < 650) {
			x0 += 40;
		}
		if (x1 < 650) {
			x1 += 20;
		}
	}

	_2C4->move(x0, y0);
	_2C8->move(x1, y1);
}

/*
 * --INFO--
 * Address:	80187BC4
 * Size:	0000B4
 */
void zen::ogScrFileSelectMgr::OpenYesNoWindow()
{
	_28D = 1;
	_290 = 0.0f;
	mNitaku->start();
	_2D8->setScale(0.0f);
	int x = _2D8->getPosH() / 2;
	int y = _2D8->getPosV() / 2;
	_2D8->setOffset(x, y);
	_2D8->show();
	_2D0->show();
	_2D0->setAlpha(0);
}

/*
 * --INFO--
 * Address:	80187C78
 * Size:	000014
 */
void zen::ogScrFileSelectMgr::CloseYesNoWindow()
{
	_28D = 0;
	_290 = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void zen::ogScrFileSelectMgr::UpDateYesNoWindow()
{
	if (_290 < 0.25f) {
		_290 += gsys->getFrameTime();
		f32 t = _290 / 0.25f;
		if (_28D) {
			_2D8->setScale(t);
			f32 alpha = _2D4->getAlpha() * t;
			_2D0->setAlpha(alpha);
		} else {
			_2D8->setScale(1.0f - t);
			f32 alpha = _2D4->getAlpha() * (1.0f - t);
			_2D0->setAlpha(alpha);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void zen::ogScrFileSelectMgr::setOperateMode_Normal()
{
	SetTitleMsg(titleMsg_1);
	if (_1190[_134]) {
		paneOnOffXY(false);
	} else {
		paneOnOffXY(true);
	}

	_A4.scale(0.0f, 0.2f);
	_D4.scale(0.0f, 0.2f);
}

/*
 * --INFO--
 * Address:	80187C8C
 * Size:	0000F0
 */
void zen::ogScrFileSelectMgr::setOperateMode(zen::ogScrFileSelectMgr::FileOperateMode mode)
{
	mOperateMode = mode;
	switch (mOperateMode) {
	case OPMODE_Normal:
		setOperateMode_Normal();
		break;

	case OPMODE_Copy:
		setOperateMode_Copy();
		break;

	case OPMODE_Delete:
		setOperateMode_Delete();
		break;
	}
}

/*
 * --INFO--
 * Address:	80187D7C
 * Size:	0004E0
 */
void zen::ogScrFileSelectMgr::getPane_FileTop1()
{
	_2C4 = _2B4->search('p_co', true);
	_2C8 = _2B4->search('p_sh', true);
	_270 = _2C4->getPosH();
	_274 = _2C8->getPosH();
	_278 = false;

	_2DC = _2B4->search('p_ma', true);
	_2D8 = _2B4->search('yn_w', true);
	_2CC = (P2DPicture*)_2B4->search('chui', true);
	_2D0 = (P2DPicture*)_2B4->search('back', true);
	_2D4 = (P2DTextBox*)_2B4->search('se_c', true);
	_2E0 = (P2DTextBox*)_2B4->search('hai', true);
	_2E4 = (P2DTextBox*)_2B4->search('iie', true);
	_2E8 = _2B4->search('dono', true);
	_310 = (P2DTextBox*)_2B4->search('hsho', true);
	_2EC = _2B4->search('sho', true);
	_2F0 = _2B4->search('dsho', true);
	_2F4 = _2B4->search('doko', true);
	_314 = (P2DTextBox*)_2B4->search('d1co', true);
	_2F8 = _2B4->search('copc', true);
	_2FC = _2B4->search('dcxx', true);
	_300 = _2B4->search('dcop', true);
	_318 = (P2DTextBox*)_2B4->search('dasa', true);
	_304 = _2B4->search('dosa', true);
	_308 = _2B4->search('savc', true);
	_30C = _2B4->search('ddxx', true);
	_31C = (P2DTextBox*)_2B4->search('uasa', true);
	_320 = (P2DTextBox*)_2B4->search('u1co', true);
	_324 = (P2DTextBox*)_2B4->search('usho', true);

	Colour colour;
	colour.set(255, 255, 255, 255);
	_31C->setCharColor(colour);
	_31C->setAlpha(255);
	_320->setAlpha(255);
	_324->setAlpha(255);

	_260 = new ogCnvStringMgr(_310);
	_264 = new ogCnvStringMgr(_314);
	_268 = new ogCnvStringMgr(_318);

	mNitaku = new ogNitakuMgr(_2B4, _2E0, _2E4, _2D4, false, true);

	_2D0->hide();
	_2D8->hide();
	_2CC->hide();
}

/*
 * --INFO--
 * Address:	8018825C
 * Size:	00032C
 */
void zen::ogScrFileSelectMgr::getPane_FileTop2()
{
	_328 = _2B8->search('da_1', true);
	_32C = _2B8->search('da_2', true);
	_330 = _2B8->search('da_3', true);
	_338 = _2B8->search('ro_l', true);
	_33C = _2B8->search('ro_r', true);
	_340 = _2B8->search('rt_l', true);
	_344 = _2B8->search('rt_r', true);
	_348 = _2B8->search('rc_l', true);
	_34C = _2B8->search('rc_c', true);
	_350 = _2B8->search('rc_r', true);
	_354 = _2B8->search('bc_l', true);
	_358 = _2B8->search('bc_c', true);
	_35C = _2B8->search('bc_r', true);
	_360 = _2B8->search('yc_l', true);
	_364 = _2B8->search('yc_c', true);
	_368 = _2B8->search('yc_r', true);
	_36C = _2B8->search('rcon', true);
	_370 = _2B8->search('bcon', true);
	_374 = _2B8->search('ycon', true);
	_334 = _2B8->search('dall', true);
	_378 = _2B8->search('navi', true);
	_37C = _2B8->search('newd', true);

	_294 = _374->getPosH();
	_298 = _374->getPosV();
	setFileData(0);
}

/*
 * --INFO--
 * Address:	80188588
 * Size:	000164
 */
void zen::ogScrFileSelectMgr::setFileData(int fileNum)
{
	P2DScreen* screen = _2B8;
	int* redNum       = &_2C[fileNum].mRedPikiCount;
	int* blueNum      = &_2C[fileNum].mBluePikiCount;
	int* yellowNum    = &_2C[fileNum].mYellowPikiCount;
	int* partsNum     = &_2C[fileNum].mCurrentPartsCount;
	mMaxPartsNum      = 30;

	setNumberTag(screen, 'ro_l', partsNum, 10);
	setNumberTag(screen, 'ro_r', partsNum, 1);
	setNumberTag(screen, 'rt_l', &mMaxPartsNum, 10);
	setNumberTag(screen, 'rt_r', &mMaxPartsNum, 1);
	setNumberTag(screen, 'rc_l', redNum, 100);
	setNumberTag(screen, 'rc_c', redNum, 10);
	setNumberTag(screen, 'rc_r', redNum, 1);
	setNumberTag(screen, 'bc_l', blueNum, 100);
	setNumberTag(screen, 'bc_c', blueNum, 10);
	setNumberTag(screen, 'bc_r', blueNum, 1);
	setNumberTag(screen, 'yc_l', yellowNum, 100);
	setNumberTag(screen, 'yc_c', yellowNum, 10);
	setNumberTag(screen, 'yc_r', yellowNum, 1);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void zen::ogScrFileSelectMgr::set_SM_C()
{
	for (int i = 0; i < 3; i++) {
		Colour colour = _434[i]->getWhite();
		u8 alpha      = _434[i]->getAlpha();

		_3F8[i]->setWhite(colour);
		_3F8[i]->setAlpha(alpha);
		_41C[i]->setWhite(colour);
		_41C[i]->setAlpha(alpha);
		_428[i]->setWhite(colour);
		_428[i]->setAlpha(alpha);
	}
}

/*
 * --INFO--
 * Address:	801886EC
 * Size:	000520
 */
void zen::ogScrFileSelectMgr::getPane_FileIcon()
{
	_440 = _29C[0]->search('no_c', true);
	_444 = _29C[0]->search('ne_c', true);

	for (int i = 0; i < 3; i++) {
		P2DScreen* screen = _29C[i];
		_38C[i]           = screen->search('root', true);
		_398[i]           = screen->search('newi', true);
		_3A4[i]           = screen->search('nemi', true);
		_398[i]->hide();
		_3A4[i]->hide();

		_3B0[i] = screen->search('fp', true);
		_3BC[i] = screen->search('fp_m', true);

		_3B0[i]->show();
		_3BC[i]->show();

		int x = _3B0[i]->getWidth();
		int y = _3B0[i]->getHeight();
		_3B0[i]->setOffset(x / 2, y / 2);

		x = _3BC[i]->getWidth();
		y = _3BC[i]->getHeight();
		_3BC[i]->setOffset(x / 2, y / 2);

		x = _398[i]->getWidth();
		y = _398[i]->getHeight();
		_398[i]->setOffset(x / 2, y / 2);

		x = _3A4[i]->getWidth();
		y = _3A4[i]->getHeight();
		_3A4[i]->setOffset(x / 2, y / 2);

		_158[i] = _3B0[i]->getPosH();
		_164[i] = _3B0[i]->getPosV();
		_170[i] = _3BC[i]->getPosH();
		_17C[i] = _3BC[i]->getPosV();

		_188[i] = _3B0[i]->getScale();
		_1AC[i] = _3BC[i]->getScale();

		_200[i] = _398[i]->getPosH();
		_20C[i] = _398[i]->getPosV();

		_230[i] = _3A4[i]->getPosH();
		_23C[i] = _3A4[i]->getPosV();

		_3C8[i] = screen->search('ce_p', true);
		_3D4[i] = screen->search('ef_c', true);
		_3E0[i] = screen->search('efmc', true);

		f32 scale = 0.7f;
		int x0    = _3C8[i]->getPosH();
		int y0    = _3C8[i]->getPosV();
		_29C[i]->setOffset(x0, y0);
		_29C[i]->setScale(scale);
		_2A8[i]->setOffset(x0, y0);
		_2A8[i]->setScale(scale);

		_3EC[i] = screen->search('dc_c', true);
		_3F8[i] = (P2DPicture*)screen->search('dcmc', true);
		_404[i] = screen->search('dc_l', true);
		_410[i] = screen->search('dc_r', true);
		_41C[i] = (P2DPicture*)screen->search('dcml', true);
		_428[i] = (P2DPicture*)screen->search('dcmr', true);
		_434[i] = (P2DPicture*)screen->search('sm_c', true);

		Colour white = _434[i]->getWhite();
		u8 alpha     = _434[i]->getAlpha();

		PRINT("data %d : wc(%d,%d,%d) a %d\n", i, white.r, white.g, white.b, alpha);

		_3F8[i]->setWhite(white);
		_3F8[i]->setAlpha(alpha);
		_41C[i]->setWhite(white);
		_41C[i]->setAlpha(alpha);
		_428[i]->setWhite(white);
		_428[i]->setAlpha(alpha);

		OnOffKetaNissuu(i);
	}
}

/*
 * --INFO--
 * Address:	80188C0C
 * Size:	0001B8
 */
void zen::ogScrFileSelectMgr::OnOffKetaNissuu(int fileNum)
{
	P2DScreen* screen = _29C[fileNum];
	int* dayNum       = &_2C[fileNum].mCurrentDay;

	if (_2C[fileNum].mCurrentDay < 10) {
		setNumberTag(screen, 'dc_c', dayNum, 1);
		setNumberTag(screen, 'dcmc', dayNum, 1);

		_3EC[fileNum]->show();
		_3F8[fileNum]->show();
		_404[fileNum]->hide();
		_410[fileNum]->hide();
		_41C[fileNum]->hide();
		_428[fileNum]->hide();
	} else {
		setNumberTag(screen, 'dc_l', dayNum, 10);
		setNumberTag(screen, 'dc_r', dayNum, 1);
		setNumberTag(screen, 'dcml', dayNum, 10);
		setNumberTag(screen, 'dcmr', dayNum, 1);

		_404[fileNum]->show();
		_410[fileNum]->show();
		_41C[fileNum]->show();
		_428[fileNum]->show();
		_3EC[fileNum]->hide();
		_3F8[fileNum]->hide();
	}

	u32 badCompiler;
}

/*
 * --INFO--
 * Address:	80188DC4
 * Size:	0002F0
 */
void zen::ogScrFileSelectMgr::getPane_CpyCurScreen()
{
	P2DScreen* screen  = _2BC;
	_448               = screen->search('root', true);
	P2DPane* paneUp0   = screen->search('i00u', true);
	P2DPane* paneDown0 = screen->search('i00d', true);
	P2DPane* paneUp1   = screen->search('i01u', true);
	P2DPane* paneDown1 = screen->search('i01d', true);
	P2DPane* paneUp2   = screen->search('i02u', true);
	P2DPane* paneDown2 = screen->search('i02d', true);

	paneUp0->hide();
	paneDown0->hide();
	paneUp1->hide();
	paneDown1->hide();
	paneUp2->hide();
	paneDown2->hide();

	_104[0] = paneUp0->getPosH();
	_11C[0] = paneUp0->getPosV();
	_104[1] = paneUp1->getPosH();
	_11C[1] = paneUp1->getPosV();
	_104[2] = paneUp2->getPosH();
	_11C[2] = paneUp2->getPosV();

	_110[0] = paneDown0->getPosH();
	_128[0] = paneDown0->getPosV();
	_110[1] = paneDown1->getPosH();
	_128[1] = paneDown1->getPosV();
	_110[2] = paneDown2->getPosH();
	_128[2] = paneDown2->getPosV();

	_A4.init(screen, _448, 'z00l', _104[0], _11C[0]);
	_D4.init(screen, _448, 'z00r', _110[0], _128[0]);
}

/*
 * --INFO--
 * Address:	801890B4
 * Size:	000340
 */
void zen::ogScrFileSelectMgr::SetTitleMsg(zen::ogScrFileSelectMgr::titleMessageFlag flag)
{
	_2E8->hide();
	_310->hide();
	_2EC->hide();
	_2F0->hide();
	_2F4->hide();
	_314->hide();
	_2F8->hide();
	_2FC->hide();
	_300->hide();
	_318->hide();
	_304->hide();
	_308->hide();
	_30C->hide();

	setSpecialNumber(6, _134 + 1);
	setSpecialNumber(7, _119C + 1);
	_260->convert();
	_264->convert();
	_268->convert();

	_31C->setString(_318->getString());
	_320->setString(_314->getString());
	_324->setString(_310->getString());

	if (flag != mTitleMsg) {
		mTitleMsg = flag;
		_280      = 0.0f;
		_284      = 1;
	}

	switch (flag) {
	case titleMsg_1:
		_2E8->show();
		break;

	case titleMsg_2:
		_310->show();
		break;

	case titleMsg_3:
		_2EC->show();
		break;

	case titleMsg_4:
		_2F0->show();
		break;

	case titleMsg_5:
		_2F4->show();
		break;

	case titleMsg_6:
		_314->show();
		break;

	case titleMsg_7:
		_2F8->show();
		break;

	case titleMsg_8:
		_2FC->show();
		break;

	case titleMsg_9:
		_300->show();
		break;

	case titleMsg_10:
		_318->show();
		break;

	case titleMsg_11:
		_304->show();
		break;

	case titleMsg_12:
		_308->show();
		break;

	case titleMsg_13:
		_30C->show();
		break;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B8
 */
void zen::ogScrFileSelectMgr::ScaleAnimeTitle()
{
	if (_284) {
		_280 += gsys->getFrameTime();
		if (_280 > 5.0f) {
			_284 = 0;
		}

		f32 scale = calcPuruPuruScale(_280);
		_2DC->setScale(scale, scale, 1.0f);
		int x = _2DC->getWidth();
		int y = _2DC->getHeight();
		_2DC->setOffset(x / 2, y / 2);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void zen::ogScrFileSelectMgr::ScaleAnimeData()
{
	if (_28C) {
		_288 += gsys->getFrameTime();
		if (_288 > 5.0f) {
			_28C = 0;
		}

		f32 scale = calcPuruPuruScale(_288);
		_2B8->setScale(scale, scale, 1.0f);
		_2DC->getWidth(); // nice copy and pasting ogawa
		_2DC->getHeight();
		_2B8->setOffset(320, 400);
	}
}

/*
 * --INFO--
 * Address:	801893F4
 * Size:	0002C8
 */
void zen::ogScrFileSelectMgr::setDataNumber(int p1)
{
	_288 = 0.0f;
	_28C = 1;
	_328->hide();
	_32C->hide();
	_330->hide();

	switch (p1) {
	case 0:
		_328->show();
		break;

	case 1:
		_32C->show();
		break;

	case 2:
		_330->show();
		break;
	}

	ChkNewData();
	ChkOnyonOnOff();

	P2DPane* pane = _3B0[_134];
	Vector3f pos;
	pos.set(0.0f, 0.0f, 0.0f);
	pos.x = f32(pane->getPosH()) + f32(pane->getWidth()) / 2.0f;
	pos.y = 480.0f - (f32(pane->getPosV()) + f32(pane->getHeight()) / 2.0f);

	if (_14) {
		_14->forceFinish();
	}

	_14 = mEfxMgr->create(EFF2D_Unk36, pos, nullptr, nullptr);

	pane = _3BC[_134];
	Vector3f pos2;
	pos2.set(0.0f, 0.0f, 0.0f);
	pos2.x = f32(pane->getPosH()) + f32(pane->getWidth()) / 2.0f;
	pos2.y = 480.0f - (f32(pane->getPosV()) + f32(pane->getHeight()) / 2.0f);

	if (_18) {
		_18->forceFinish();
	}

	_18 = mEfxMgr->create(EFF2D_Unk35, pos2, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void zen::ogScrFileSelectMgr::init()
{
	mState    = STATE_NULL;
	_1193     = 0;
	_1194     = 0;
	_1195     = 0;
	_1196     = 0;
	_1198     = 0;
	mSaveMode = 0;
	_150      = 0.0f;
	_1180     = 0;
	_294      = 0;
	_298      = 0;
	_14       = 0;
	_18       = 0;
}

/*
 * --INFO--
 * Address:	801896BC
 * Size:	0008F8
 */
zen::ogScrFileSelectMgr::ogScrFileSelectMgr()
{
	init();
	mEfxMgr = new EffectMgr2D(16, 0x400, 0x400);
	_29C[0] = new P2DScreen();
	_29C[1] = new P2DScreen();
	_29C[2] = new P2DScreen();
	_29C[0]->set("screen/blo/data1.blo", true, true, true);
	_29C[1]->set("screen/blo/data2.blo", true, true, true);
	_29C[2]->set("screen/blo/data3.blo", true, true, true);

	_2A8[0] = new P2DScreen();
	_2A8[1] = new P2DScreen();
	_2A8[2] = new P2DScreen();
	_2A8[0]->set("screen/blo/data1_n.blo", true, true, true);
	_2A8[1]->set("screen/blo/data2_n.blo", true, true, true);
	_2A8[2]->set("screen/blo/data3_n.blo", true, true, true);
	int i;
	for (i = 0; i < 3; i++) {
		_380[i] = _2A8[i]->search('root', true);
	}

	_2B4 = new P2DScreen();
	_2B4->set("screen/blo/data_t1.blo", true, true, true);
	_2B8 = new P2DScreen();
	_2B8->set("screen/blo/data_t2.blo", true, true, true);
	_2BC = new P2DScreen();
	_2BC->set("screen/blo/data_i.blo", true, true, true);
	_2C0 = new P2DScreen();
	_2C0->set("screen/blo/black.blo", false, false, true);

	_44C = (P2DPicture*)_2C0->search('blck', true);
	_44C->setAlpha(255);

	getPane_FileTop1();
	getPane_FileTop2();
	getPane_FileIcon();
	getPane_CpyCurScreen();
	SetTitleMsg(titleMsg_1);
	setOperateMode(OPMODE_Normal);

	for (i = 0; i < 3; i++) {
		_29C[i]->setScale(1.0f);
		_2A8[i]->setScale(1.0f);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void zen::ogScrFileSelectMgr::setDataScale()
{
	for (int i = 0; i < 3; i++) {
		_38C[i]->setScale(_138[i]);
		_380[i]->setScale(_144[i]);
	}
}

/*
 * --INFO--
 * Address:	80189FC0
 * Size:	0001B8
 */
void zen::ogScrFileSelectMgr::chaseDataScale()
{
	for (int i = 0; i < 3; i++) {
		if (_134 == i) {
			_138[i] += (1.0f - _138[i]) / 10.0f;
			_144[i] += (1.0f - _144[i]) / 4.0f;
			P2DPaneLibrary::setFamilyAlpha(_3B0[i], 255);
			P2DPaneLibrary::setFamilyAlpha(_3BC[i], 70);
			P2DPaneLibrary::setFamilyAlpha(_398[i], 255);
			P2DPaneLibrary::setFamilyAlpha(_3A4[i], 255);

		} else {
			_138[i] += (0.7f - _138[i]) / 10.0f;
			_144[i] += (0.7f - _144[i]) / 4.0f;
			P2DPaneLibrary::setFamilyAlpha(_3B0[i], 128);
			P2DPaneLibrary::setFamilyAlpha(_3BC[i], 64);
			P2DPaneLibrary::setFamilyAlpha(_398[i], 128);
			P2DPaneLibrary::setFamilyAlpha(_3A4[i], 128);
		}
	}

	setDataScale();
}

/*
 * --INFO--
 * Address:	8018A178
 * Size:	0001B8
 */
void zen::ogScrFileSelectMgr::OnOffNewPane(int fileNum)
{
	if (_1190[fileNum]) {
		_398[fileNum]->show();
		_3A4[fileNum]->show();
		_3B0[fileNum]->hide();
		_3BC[fileNum]->hide();

		if (fileNum == _134) {
			_334->hide();
			_378->hide();
			_37C->show();
			paneOnOffXY(false);
		}
	} else {
		_398[fileNum]->hide();
		_3A4[fileNum]->hide();
		_3B0[fileNum]->show();
		_3BC[fileNum]->show();
		OnOffKetaNissuu(fileNum);

		if (fileNum == _134) {
			setFileData(fileNum);
			_334->show();
			_378->show();
			_37C->hide();
			paneOnOffXY(true);
		}
	}
}

/*
 * --INFO--
 * Address:	8018A330
 * Size:	0000B8
 */
void zen::ogScrFileSelectMgr::ChkOnyonOnOff()
{
	int fileNum = _134;
	int reds    = _2C[fileNum].mRedPikiCount;
	int blues   = _2C[fileNum].mBluePikiCount;
	int yellows = _2C[fileNum].mYellowPikiCount;

	if (reds < 0) {
		_36C->hide();
	} else {
		_36C->show();
	}
	if (blues < 0) {
		_370->hide();
	} else {
		_370->show();
	}
	if (yellows < 0) {
		_374->hide();
	} else {
		_374->show();
	}
}

/*
 * --INFO--
 * Address:	8018A3E8
 * Size:	000088
 */
void zen::ogScrFileSelectMgr::ChkNewData()
{
	_1190[0] = _2C[0]._08 == 1;
	_1190[1] = _2C[1]._08 == 1;
	_1190[2] = _2C[2]._08 == 1;

	for (int i = 0; i < 3; i++) {
		OnOffNewPane(i);
	}
}

/*
 * --INFO--
 * Address:	8018A470
 * Size:	000404
 */
void zen::ogScrFileSelectMgr::start(bool saveMode, int fileSelMode)
{
	PRINT("///////////// ogScrFileSelectMgr start() save_mode = %d  FS-Mode %d //////////////\n", saveMode, fileSelMode);
	init();
	mSaveMode = saveMode;
	if (mSaveMode) {
		SetTitleMsg(titleMsg_11);
	} else {
		SetTitleMsg(titleMsg_1);
	}

	_14 = nullptr;
	_18 = nullptr;
	getCardFileInfos();

	_1193  = 0;
	_1194  = 0;
	_1195  = 0;
	_1196  = 0;
	_1197  = 0;
	_54C   = 0.0f;
	_1184  = 0.0f;
	mState = STATE_Unk1;
	int i;
	for (i = 0; i < 3; i++) {
		if (i != _134) {
			_119C = i;
			break;
		}
	}

	_134 = 0;
	setDataNumber(_134);

	for (i = 0; i < 3; i++) {
		if (_134 == i) {
			_138[i] = 1.0f;
			_144[i] = 1.0f;
		} else {
			_138[i] = 0.7f;
			_144[i] = 0.7f;
		}

		_1D0[i] = _158[i];
		_1DC[i] = _164[i];
		_1E8[i] = _170[i];
		_1F4[i] = _17C[i];

		_3B0[i]->move(_1D0[i], _1DC[i]);
		_3B0[i]->setScale(1.0f);

		_3BC[i]->move(_1E8[i], _1F4[i]);
		_3BC[i]->setScale(1.0f);

		P2DPaneLibrary::setFamilyAlpha(_3B0[i], 255);

		_218[i] = _200[i];
		_224[i] = _20C[i];
		_398[i]->move(_218[i], _224[i]);
		_398[i]->setScale(1.0f);

		_248[i] = _230[i];
		_254[i] = _23C[i];
		_3A4[i]->move(_248[i], _254[i]);
		_3A4[i]->setScale(1.0f);
	}

	_1180     = 0;
	mTitleMsg = titleMsg_0;
	_284      = 0;
	_28C      = 0;

	_44C->setAlpha(255);

	setDataScale();

	if (!mSaveMode) {
		Vector3f pos;
		pos.set(320.0f, 240.0f, 0.0f);
		mEfxMgr->create(EFF2D_Unk17, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk18, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk19, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk20, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk21, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk22, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk23, pos, nullptr, nullptr);
		mEfxMgr->create(EFF2D_Unk24, pos, nullptr, nullptr);
	}

	PRINT("///////////// ogScrFileSelectMgr start() end //////////////\n");
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void zen::ogScrFileSelectMgr::BeginFadeOut()
{
	mState = STATE_Unk2;
	_1184  = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
int zen::ogScrFileSelectMgr::CanToCopy(int p1)
{
	int res = 0;
	for (int i = 0; i < 3; i++) {
		if (_1190[i] && i != p1) {
			res++;
		}
	}

	return res;
}

/*
 * --INFO--
 * Address:	8018A874
 * Size:	00036C
 */
void zen::ogScrFileSelectMgr::OperateSelect(Controller* controller)
{
	if (controller->keyClick(KBBTN_MSTICK_LEFT) && _134 > 0) {
		SeSystem::playSysSe(SYSSE_MOVE1);
		_134--;
		setDataNumber(_134);
		return;
	}

	if (controller->keyClick(KBBTN_MSTICK_RIGHT) && _134 < 2) {
		SeSystem::playSysSe(SYSSE_MOVE1);
		_134++;
		setDataNumber(_134);
		return;
	}

	if (controller->keyClick(KBBTN_A)) {
		SeSystem::playSysSe(SYSSE_DECIDE1);
		KetteiEffectStart();
		if (mSaveMode) {
			mState = STATE_Unk2;
			_1184  = 0.0f;
			BeginFadeOut();
		} else {
			_150   = 0.0f;
			mState = STATE_Unk3;
			_53C   = 0.1f;
			if (_14) {
				_14->forceFinish();
			}
			if (_18) {
				_18->forceFinish();
			}

			TailEffectStart();
		}
		return;
	}

	if (controller->keyClick(KBBTN_B)) {
		_1193 = 1;
		BeginFadeOut();
		SeSystem::playSysSe(SYSSE_CANCEL);
		if (_14) {
			_14->forceFinish();
		}
		if (_18) {
			_18->forceFinish();
		}
		return;
	}

	if (controller->keyClick(KBBTN_Y)) {
		if (!_1190[_134] && !mSaveMode) {
			SeSystem::playSysSe(SYSSE_DECIDE1);
			setOperateMode(OPMODE_Copy);
		}
		return;
	}

	if (controller->keyClick(KBBTN_X)) {
		if (!_1190[_134] && !mSaveMode) {
			SeSystem::playSysSe(SYSSE_DECIDE1);
			setOperateMode(OPMODE_Delete);
		}
	}
}

/*
 * --INFO--
 * Address:	8018ABE0
 * Size:	0001FC
 */
void zen::ogScrFileSelectMgr::KetteiEffectStart()
{
	Vector3f pos;
	pos.set(0.0f, 0.0f, 0.0f);
	pos.x = f32(_3B0[_134]->getPosH()) + f32(_3B0[_134]->getWidth()) / 2.0f;
	pos.y = 480.0f - (f32(_3B0[_134]->getPosV()) + f32(_3B0[_134]->getHeight()) / 2.0f);

	mEfxMgr->create(EFF2D_Unk37, pos, nullptr, nullptr);

	pos.x = f32(_3BC[_134]->getPosH()) + f32(_3BC[_134]->getWidth()) / 2.0f;
	pos.y = 480.0f - (f32(_3BC[_134]->getPosV()) + f32(_3BC[_134]->getHeight()) / 2.0f);

	mEfxMgr->create(EFF2D_Unk34, pos, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	8018ADDC
 * Size:	0001D4
 */
void zen::ogScrFileSelectMgr::TailEffectStart()
{
	Vector3f pos;
	pos.set(0.0f, 0.0f, 0.0f);
	pos.x = f32(_3B0[_134]->getPosH()) + f32(_3B0[_134]->getWidth()) / 2.0f;
	pos.y = 480.0f - (_3B0[_134]->getPosV() + _3B0[_134]->getHeight());

	_0C = mEfxMgr->create(EFF2D_Unk38, pos, nullptr, nullptr);

	pos.x = f32(_3BC[_134]->getPosH()) + f32(_3BC[_134]->getWidth()) / 2.0f;
	pos.y = 480.0f - (_3BC[_134]->getPosV() + _3BC[_134]->getHeight());

	_10 = mEfxMgr->create(EFF2D_Unk33, pos, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void zen::ogScrFileSelectMgr::TailEffectMove(int x, int y)
{
	Vector3f pos;
	int newX = x + _3B0[_134]->getWidth() / 2;
	int newY = y + _3B0[_134]->getHeight();

	pos.set(newX, 480 - newY, 0.0f);
	_0C->setEmitPos(pos);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void zen::ogScrFileSelectMgr::TailEffectMoveM(int x, int y)
{
	Vector3f pos;
	int newX = x + _3BC[_134]->getWidth() / 2;
	int newY = y + _3BC[_134]->getHeight();

	pos.set(newX, 480 - newY + 100, 0.0f);
	_10->setEmitPos(pos);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void zen::ogScrFileSelectMgr::quit()
{
	mState = STATE_NULL;
	if (_14) {
		_14->forceFinish();
	}
	if (_18) {
		_18->forceFinish();
	}
}

/*
 * --INFO--
 * Address:	8018AFB0
 * Size:	000A20
 */
zen::ogScrFileSelectMgr::returnStatusFlag zen::ogScrFileSelectMgr::update(Controller* controller, CardQuickInfo& cardInfo)
{
	if (mState == STATE_NULL) {
		return mState;
	}

	cardInfo = _2C[_134];
	mEfxMgr->update();
	set_SM_C();
	MovePaneXY();
	ScaleAnimeTitle();
	ScaleAnimeData();
	UpDateYesNoWindow();

	if (_54C < 1.0f) {
		_54C += gsys->getFrameTime();
	}

	_A4.update();
	_D4.update();

	if (mState == STATE_Unk1) {
		_1184 += gsys->getFrameTime();
		if (_1184 >= 0.5f) {
			mState = STATE_Unk0;
		} else {
			_1180 = 255.0f * _1184 / 0.5f;
			_44C->setAlpha(255 - _1180);
		}

		if (_1184 < 0.05f) {
			return mState;
		}
	} else if (mState == STATE_Unk2) {
		_1184 += gsys->getFrameTime();
		if (_1184 >= 0.5f) {
			mEfxMgr->killAll(true);
			if (_1193) {
				mState = STATE_Unk6;
			} else {
				switch (_134) {
				case 0:
					mState = STATE_Unk7;
					break;

				case 1:
					mState = STATE_Unk8;
					break;

				case 2:
					mState = STATE_Unk9;
					break;

				default:
					mState = STATE_Unk10;
					break;
				}
			}
		} else {
			_1180 = 255.0f * (0.5f - _1184) / 0.5f;
			_44C->setAlpha(255 - _1180);
		}
		return mState;

	} else if (mState >= STATE_Unk6) {
		quit();
		mState = STATE_NULL;
		return mState;
	}

	chaseDataScale();

	for (int i = 0; i < 3; i++) {
		_29C[i]->update();
		_2A8[i]->update();
	}

	_2B4->update();
	_2B8->update();
	_2BC->update();
	_2C0->update();

	_150 += gsys->getFrameTime();

	if (mState == STATE_Unk3) {
		_53C += 0.4f;
		_1DC[_134] -= _53C;
		_1F4[_134] += _53C;
		_3B0[_134]->move(_1D0[_134], _1DC[_134]);
		_3BC[_134]->move(_1E8[_134], _1F4[_134]);

		_224[_134] -= _53C;
		_254[_134] += _53C;
		_398[_134]->move(_218[_134], _224[_134]);
		_3A4[_134]->move(_248[_134], _254[_134]);

		TailEffectMove(_1D0[_134], _1DC[_134]);
		TailEffectMoveM(_1E8[_134], _1F4[_134]);
		int diff = _164[_134] - _1DC[_134];
		f32 v    = fabs((f64)diff);
		if (v > 200.0f) {
			v = 200.0f;
		}

		u32 badCompiler;
		Vector3f scale = _3B0[_134]->getScale();
		scale.x        = 1.0f - v / 200.0f;
		scale.y        = 1.0f - v / 200.0f;

		_3B0[_134]->setScale(scale);
		_3BC[_134]->setScale(scale);
		_398[_134]->setScale(scale);
		_3A4[_134]->setScale(scale);

		if (_150 > 1.0f) {
			BeginFadeOut();
			_0C->finish();
			_10->finish();
		}

		return mState;
	}

	if (_150 > 1.0f) {
		switch (mOperateMode) {
		case OPMODE_Normal:
			OperateSelect(controller);
			break;

		case OPMODE_Copy:
			OperateCopy(controller);
			break;

		case OPMODE_Delete:
			OperateDelete(controller);
			break;
		}
	}

	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";

	return mState;
}

/*
 * --INFO--
 * Address:	8018B9F4
 * Size:	00015C
 */
void zen::ogScrFileSelectMgr::draw(Graphics& gfx)
{
	if (mState == STATE_NULL) {
		return;
	}

	P2DPerspGraph perspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	perspGraph.setPort();

	for (int i = 0; i < 3; i++) {
		_29C[i]->draw(0, 0, &perspGraph);
		_2A8[i]->draw(0, 0, &perspGraph);
	}

	mEfxMgr->draw(gfx);
	gfx.setFog(false);
	GXSetZMode(GX_FALSE, GX_ALWAYS, GX_FALSE);
	_2BC->draw(0, 0, &perspGraph);
	_2B4->draw(0, 0, &perspGraph);
	_2B8->draw(0, 0, &perspGraph);
	_2C0->draw(0, 0, &perspGraph);
}
