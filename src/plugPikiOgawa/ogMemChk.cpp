#include "zen/ogMemChk.h"
#include "zen/EffectMgr2D.h"
#include "zen/ogNitaku.h"
#include "zen/ogSub.h"
#include "zen/ogMakeDefault.h"
#include "P2D/Screen.h"
#include "P2D/Picture.h"
#include "P2D/Graph.h"
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
DEFINE_PRINT("OgMemChkSection")

/*
 * --INFO--
 * Address:	8018D04C
 * Size:	0009D0
 */
zen::ogScrMemChkMgr::ogScrMemChkMgr()
{
	_00 = 0;
	PRINT("---------------------------- ogScrMemChkMgr begin -----------\n");

	_24 = new P2DScreen;
	_24->set("screen/blo/black.blo", false, false, true);
	_28 = (P2DPicture*)_24->search('blck', true);
	_28->setAlpha(255);

	_0C = new EffectMgr2D(0x20, 0x80, 0x80);
	_10 = 0;
	_14 = 0;

	_2C = new P2DScreen;
	_2C->set("screen/blo/data_m.blo", true, true, true);

	P2DScreen* screen = _2C;

	_74  = (P2DTextBox*)screen->search('shom', true);
	_78  = (P2DTextBox*)screen->search('shot', true);
	_80  = (P2DTextBox*)screen->search('shch', true);
	_84  = (P2DTextBox*)screen->search('shoi', true);
	_88  = (P2DTextBox*)screen->search('shok', true);
	_7C  = (P2DTextBox*)screen->search('shos', true);
	_AC  = (P2DTextBox*)screen->search('hai', true);
	_B0  = (P2DTextBox*)screen->search('iie', true);
	_B4  = (P2DTextBox*)screen->search('haic', true);
	_B8  = (P2DTextBox*)screen->search('iiec', true);
	_8C  = (P2DTextBox*)screen->search('shuf', true);
	_90  = (P2DTextBox*)screen->search('shsi', true);
	_94  = (P2DTextBox*)screen->search('shxx', true);
	_EC  = (P2DTextBox*)screen->search('sari', true);
	_F0  = (P2DTextBox*)screen->search('memo', true);
	_F4  = (P2DTextBox*)screen->search('brom', true);
	_F8  = (P2DTextBox*)screen->search('kaim', true);
	_FC  = (P2DTextBox*)screen->search('ijom', true);
	_100 = (P2DTextBox*)screen->search('naim', true);
	_104 = (P2DTextBox*)screen->search('file', true);
	_98  = screen->search('yn_w', true);
	_9C  = screen->search('cpsl', true);

	_A4 = (P2DPicture*)_2C->search('abtn', true);
	_A0 = new setTenmetuAlpha(_A4, 1.0f);
	_A4->hide();
	_A8 = (P2DPicture*)_2C->search('main', true);

	_74->hide();
	_78->hide();
	_80->hide();
	_7C->hide();
	_84->hide();
	_88->hide();
	_8C->hide();
	_90->hide();
	_94->hide();
	_EC->hide();
	_F0->hide();
	_F4->hide();
	_F8->hide();
	_FC->hide();
	_FC->hide();
	_104->hide();

	_C0 = (P2DPicture*)_2C->search('curs', true);
	_BC = new setTenmetuAlpha(_C0, 0.5f);

	_34 = new TypingTextMgr(_74);
	_40 = new TypingTextMgr(_80);
	_38 = new TypingTextMgr(_78);
	_3C = new TypingTextMgr(_7C);
	_44 = new TypingTextMgr(_84);
	_48 = new TypingTextMgr(_88);
	_4C = new TypingTextMgr(_8C);
	_50 = new TypingTextMgr(_90);
	_54 = new TypingTextMgr(_94);
	_58 = new TypingTextMgr(_EC);
	_5C = new TypingTextMgr(_F0);
	_60 = new TypingTextMgr(_F4);
	_64 = new TypingTextMgr(_F8);
	_68 = new TypingTextMgr(_FC);
	_6C = new TypingTextMgr(_100);
	_70 = new TypingTextMgr(_104);

	_30    = _58;
	mState = STATE_NULL;
	_20    = -1;

	P2DTextBox* a1 = (P2DTextBox*)_2C->search('fomt', true);
	P2DTextBox* a2 = (P2DTextBox*)_2C->search('cws', true);
	P2DTextBox* a3 = (P2DTextBox*)_2C->search('rtry', true);
	P2DTextBox* a4 = (P2DTextBox*)_2C->search('se_c', true);
	_D4            = new ogNitakuMgr(_2C, _B4, _B8, a4, false, false);
	a1->hide();
	a2->hide();
	a3->hide();
	_D8 = _AC->getString();
	_DC = _B0->getString();
	_E0 = a1->getString();
	_E4 = a2->getString();
	_E8 = a3->getString();

	_18 = new ogScrMakeDefaultMgr;
	DispYesNo(true);
	DispAcup(false);
	PRINT("---------------------------- ogScrMemChkMgr finish -----------\n");
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void zen::ogScrMemChkMgr::SetNitaku_Y_N()
{
	_AC->setString(_D8);
	_B0->setString(_DC);
	_B4->setString(_D8);
	_B8->setString(_DC);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void zen::ogScrMemChkMgr::SetNitaku_W_R()
{
	_AC->setString(_E4);
	_B0->setString(_E8);
	_B4->setString(_E4);
	_B8->setString(_E8);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void zen::ogScrMemChkMgr::SetNitaku_F_N()
{
	_AC->setString(_E0);
	_B0->setString(_DC);
	_B4->setString(_E0);
	_B8->setString(_DC);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void zen::ogScrMemChkMgr::StartSub()
{
	_30->off();
	_30->transCursor(_C0);
	_BC->start();
	_A4->hide();
	DispAcup(false);
	DispYesNo(true);
	_D4->start();
	_08 = 3;
}

/*
 * --INFO--
 * Address:	8018DA1C
 * Size:	000258
 */
void zen::ogScrMemChkMgr::StatusCheck()
{
	SetNitaku_Y_N();

	switch (mState) {
	case 10:
		_20    = 10;
		mState = STATE_Unk1;
		setPCtex(_48);
		SetNitaku_F_N();
		break;
	case 11:
		_20    = 11;
		mState = STATE_Unk1;
		setPCtex(_44);
		SetNitaku_F_N();
		break;
	}

	// Because the first switch wasnt good enough
	switch (mState) {
	case 1:
		break;
	case 8:
		setPCtex(_58);
		PRINT("<<<<<<<<<< ERR_NOCARD in ogMemChk >>>>>>>>>>\n");
		break;
	case 9:
		setPCtex(_6C);
		PRINT("<<<<<<<<<< ERR_NOTACARD in ogMemChk >>>>>>>>>>\n");
		break;
	case 10:
		setPCtex(_64);
		PRINT("<<<<<<<<<< ERR_ENCODING in ogMemChk >>>>>>>>>>\n");
		SetNitaku_W_R();
		break;
	case 11:
		setPCtex(_68);
		PRINT("<<<<<<<<<< ERR_BROKEN in ogMemChk >>>>>>>>>>\n");
		SetNitaku_W_R();
		break;
	case 12:
		setPCtex(_5C);
		PRINT("<<<<<<<<<< ERR_FULLUP in ogMemChk >>>>>>>>>>\n");
		break;
	case 13:
		setPCtex(_60);
		PRINT("<<<<<<<<<< ERR_UNUSABLE in ogMemChk >>>>>>>>>>\n");
		break;
	case 14:
		setPCtex(_70);
		PRINT("<<<<<<<<<< ERR_NOFILE in ogMemChk >>>>>>>>>>\n");
		break;
	case 16:
		setPCtex(_4C);
		PRINT("<<<<<<<<<< REPAIR_NOW in ogMemChk >>>>>>>>>>\n");
		break;
	case 17:
		setPCtex(_50);
		PRINT("<<<<<<<<<< REPAIR_END in ogMemChk >>>>>>>>>>\n");
		break;
	case 18:
		setPCtex(_54);
		PRINT("<<<<<<<<<< REPAIR_MISS in ogMemChk >>>>>>>>>>\n");
		break;
	default:
		_30->off();
		break;
	}

	_C8 = 0.0f;
}

/*
 * --INFO--
 * Address:	8018DC74
 * Size:	000044
 */
void zen::ogScrMemChkMgr::setPCtex(TypingTextMgr* text)
{
	_30->off();
	_30 = text;
	_30->start();
}

/*
 * --INFO--
 * Address:	8018DCB8
 * Size:	000038
 */
void zen::ogScrMemChkMgr::DispYesNo(bool set)
{
	if (set) {
		_98->show();
	} else {
		_98->hide();
	}
}

/*
 * --INFO--
 * Address:	8018DCF0
 * Size:	000038
 */
void zen::ogScrMemChkMgr::DispAcup(bool set)
{
	if (set) {
		_9C->show();
	} else {
		_9C->hide();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void zen::ogScrMemChkMgr::MakeDefFileStart()
{
	_18->start();
	mState = STATE_Unk15;
	_C8    = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void zen::ogScrMemChkMgr::RepairFileStart()
{
	gameflow.mMemoryCard.repairFile();
	mState = STATE_Unk16;
	setPCtex(_4C);
	_C8 = 0.0f;
	DispYesNo(false);
}

/*
 * --INFO--
 * Address:	8018DD28
 * Size:	000224
 */
void zen::ogScrMemChkMgr::start()
{
	_00    = 0;
	mState = STATE_Unk0;
	if (!ogCheckInsCard()) {
		PRINT("ERR_NOCARD in ogMemChk\n");
		mState = STATE_Unk8;
	} else {
		int cardstate = gameflow.mMemoryCard.getMemoryCardState(false);
		PRINT("ogMemChk error = %d \n", cardstate);
		if (cardstate == -2) {
			PRINT("ERR_NOTACARD in ogMemChk\n");
			mState = STATE_Unk9;
		} else if (cardstate == -5) {
			PRINT("ERR_ENCODING in ogMemChk\n");
			mState = STATE_Unk10;
		} else if (cardstate == -4) {
			PRINT("ERR_BROKEN in ogMemChk\n");
			mState = STATE_Unk11;
		} else if (cardstate == -3) {
			PRINT("ERR_FULLUP in ogMemChk\n");
			mState = STATE_Unk12;
		} else if (cardstate == -6) {
			PRINT("ERR_UNUSABLE in ogMemChk\n");
			mState = STATE_Unk13;
		} else if (cardstate == -8) {
			PRINT("ERR_NOFILE in ogMemChk\n");
			mState = STATE_Unk14;
		} else if (gameflow.mMemoryCard.mSaveFileIndex < 0) {
			MakeDefFileStart();
		} else if (gameflow.mMemoryCard.isFileBroken()) {
			RepairFileStart();
		}
	}

	StartSub();
	StatusCheck();
}

/*
 * --INFO--
 * Address:	8018DF4C
 * Size:	000190
 */
void zen::ogScrMemChkMgr::DebugStart(int state)
{
	_00 = 1;
	_04 = state;
	PRINT("@@@@@@@@@@@@@@ DebugStart(%d)  status = %d @@@@@@@@@@@@@@\n", state, mState);

	if (state >= 1 && state <= 9) {

		mState = (MemChkStatus)(state + 7);

		if (state == 8) {
			MakeDefFileStart();
		} else if (state == 9) {
			RepairFileStart();
		}

		StartSub();
		StatusCheck();
		return;
	}

	start();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000120
 */
void zen::ogScrMemChkMgr::FormatEffectStart()
{
	P2DPane* pane = _A8;
	Vector3f pos;
	pos.set(320.0f, 240.0f, 0.0f);
	pos.x = f32(pane->getPosH()) + f32(pane->getWidth()) / 2.0f;
	pos.y = 480.0f - (f32(pane->getPosV()) + f32(pane->getHeight()) / 2.0f);
	PRINT("FormatEffectStart !! (%f,%f)\n", pos.x, pos.y);
	_10 = _0C->create(EFF2D_Unk39, pos, nullptr, nullptr);
	_14 = _0C->create(EFF2D_Unk40, pos, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
bool zen::ogScrMemChkMgr::checkTypingAll()
{
	if (_30->check() == 2) {
		return true;
	}
	return false;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void zen::ogScrMemChkMgr::checkErrNitaku(ogNitakuMgr* mgr, Controller* input)
{
	if (checkTypingAll()) {
		DispYesNo(true);
		int status = mgr->update(input);
		if (status == 6) {
			mState = STATE_Unk19;
		} else if (status == 5) {
			mState = STATE_Unk20;
		}
	} else {
		DispYesNo(false);
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void zen::ogScrMemChkMgr::setNoCard()
{
	mState = STATE_Unk8;
	setErrorMessage();
	DispYesNo(false);
	_A4->hide();
	DispAcup(false);
	SetNitaku_Y_N();
	_D4->start();
	setPCtex(_58);

	if (_10) {
		_10->finish();
	}

	if (_14) {
		_14->finish();
	}
}

/*
 * --INFO--
 * Address:	8018E0DC
 * Size:	000EC4
 */
zen::ogScrMemChkMgr::MemChkStatus zen::ogScrMemChkMgr::update(Controller* input)
{
	if (mState == STATE_NULL) {
		return mState;
	}

	if (mState == STATE_Unk0) {
		mState = STATE_Unk21;
		return mState;
	}

	if (mState >= STATE_Unk19) {
		mState = STATE_NULL;
		return mState;
	}

	_C8 += gsys->getFrameTime();

	bool hasCard = ogCheckInsCard();
	if (!hasCard && mState != STATE_Unk8) {
		setNoCard();
	}

	switch (mState) {
	case STATE_Unk8:
		if (hasCard) {
			start();
			return mState;
		}
		checkErrNitaku(_D4, input);
		break;

	case STATE_Unk10:
		SetNitaku_W_R();
		PRINT("##### MEMCHK_DISP_ERR_KAIGAI  ######\n");
		checkErrNitaku(_D4, input);
		break;

	case STATE_Unk11:
		SetNitaku_W_R();
		PRINT("##### MEMCHK_DISP_ERR_IJYOU  ######\n");
		checkErrNitaku(_D4, input);
		break;

	case STATE_Unk12:
	case STATE_Unk14:
		SetNitaku_W_R();
		checkErrNitaku(_D4, input);
		break;

	case STATE_Unk9:
	case STATE_Unk13:
		checkErrNitaku(_D4, input);
		break;

	case STATE_Unk1:
		if (checkTypingAll()) {
			mState = STATE_Unk2;
			SetNitaku_F_N();
			_D4->start();
			DispYesNo(true);
		} else {
			DispYesNo(false);
		}
		break;

	case STATE_Unk2: {
		int stat = _D4->update(input);
		if (stat >= 4) {
			if (stat == 5) {
				setPCtex(_34);
				mState = STATE_Unk3;
				_C8    = 0.0f;
			} else {
				_C4 = 0.0f;
				if (_20 == 10) {
					setPCtex(_64);
					mState = STATE_Unk10;
					_D4->start();
				} else if (_20 == 11) {
					setPCtex(_68);
					mState = STATE_Unk11;
					_D4->start();
				} else {
					mState = STATE_Unk1;
				}
				_C8 = 0.0f;
			}
		}
	} break;

	case STATE_Unk3:
		if (checkTypingAll()) {
			mState = STATE_Unk4;
			SetNitaku_Y_N();
			_D4->start();
			DispYesNo(true);
		} else {
			DispYesNo(false);
		}
		break;

	case STATE_Unk4: {
		int stat = _D4->update(input);
		if (stat >= 4) {
			if (stat == 5) {
				setPCtex(_40);
				mState = STATE_Unk5;
				DispYesNo(false);
				DispAcup(false);
				_C8 = 0.0f;
				FormatEffectStart();
			} else {
				if (_20 == 10) {
					setPCtex(_48);
				} else if (_20 == 11) {
					setPCtex(_44);
				}
				_C8    = 0.0f;
				mState = STATE_Unk1;
			}
		}
	} break;

	case STATE_Unk5:
		DispYesNo(false);
		DispAcup(true);
		if (checkTypingAll() && _C8 > 6.0f) {
			_10->finish();
			_14->finish();
			bool format = true;
			if (gameflow.mMemoryCard.doFormatCard()) {
				format = false;
			}
			if (format) {
				setPCtex(_38);
				_A4->show();
				_A0->start();
				mState = STATE_Unk6;
			} else {
				setPCtex(_3C);
				_A4->show();
				_A0->start();
				mState = STATE_Unk7;
			}
		}
		break;

	case STATE_Unk6:
		DispYesNo(false);
		DispAcup(true);
		_A0->update();
		if (input->keyClick(KBBTN_A | KBBTN_START)) {
			seSystem->playSysSe(SYSSE_DECIDE1);
			_C4 = 0.0f;
			if (gameflow.mMemoryCard.mSaveFileIndex < 0) {
				MakeDefFileStart();
			} else {
				mState = STATE_Unk21;
			}
		}
		break;

	case STATE_Unk7:
		_A0->update();
		if (input->keyClick(KBBTN_A | KBBTN_START)) {
			seSystem->playSysSe(SYSSE_DECIDE1);
			_C4    = 0.0f;
			mState = STATE_NULL;
			start();
		}
		break;

	case STATE_Unk15: {
		int stat = _18->update(input);
		if (stat == 4) {
			mState = STATE_Unk21;
		} else if (stat == 5) {
			setPCtex(_68);
			mState = STATE_Unk11;
			SetNitaku_Y_N();
			_D4->start();
			_C4 = 0.0f;
			_C8 = 0.0f;
		}
	} break;

	case STATE_Unk16:
		DispYesNo(false);
		DispAcup(true);
		if (checkTypingAll() && _C8 > 10.0f) {
			int fail = !gameflow.mMemoryCard.didSaveFail();
			if (fail) {
				mState = STATE_Unk17;
				setPCtex(_50);
			} else {
				mState = STATE_Unk18;
				setPCtex(_54);
			}
			_C8 = 0.0f;
			_A0->start();
		}
		break;

	case STATE_Unk17:
		DispYesNo(false);
		DispAcup(true);
		if (checkTypingAll()) {
			_A4->show();
			_A0->update();
			if (input->keyClick(KBBTN_A | KBBTN_START)) {
				seSystem->playSysSe(SYSSE_DECIDE1);
				mState = STATE_Unk21;
			}
		}
		break;

	case STATE_Unk18:
		DispYesNo(false);
		DispAcup(true);
		if (checkTypingAll()) {
			_A4->show();
			_A0->update();
			if (input->keyClick(KBBTN_A | KBBTN_START)) {
				seSystem->playSysSe(SYSSE_DECIDE1);
				setPCtex(_68);
				mState = STATE_Unk11;
				SetNitaku_W_R();
				_D4->start();
				_C4 = 0.0f;
				_C8 = 0.0f;
			}
		}
		break;
	}

	setErrorMessage();

	if (mState >= STATE_Unk19) {
		return mState;
	}
	_0C->update();
	_2C->update();
	_BC->update();
	_30->update();
	_30->transCursor(_C0);
	_24->update();

	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
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
 * Address:	8018EFA0
 * Size:	000110
 */
void zen::ogScrMemChkMgr::draw(Graphics& gfx)
{
	if (mState == STATE_NULL) {
		return;
	}
	if (mState >= STATE_Unk19) {
		return;
	}

	if (_08 > 0) {
		_08--;
		return;
	}

	P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	graf.setPort();
	_24->draw(0, 0, &graf);

	switch (mState) {
	case STATE_Unk15:
		_18->draw(gfx);
		break;

	case STATE_Unk19:
	case STATE_Unk21:
		break;

	case STATE_Unk8:
	default:
		_2C->draw(0, 0, &graf);
		_0C->draw(gfx);
		break;
	}
}

/*
 * --INFO--
 * Address:	8018F0B0
 * Size:	000144
 */
void zen::ogScrMemChkMgr::setErrorMessage()
{
	_EC->hide();
	_100->hide();
	_F8->hide();
	_FC->hide();
	_F0->hide();
	_F4->hide();
	_104->hide();

	switch (mState) {
	case STATE_Unk8:
		_EC->show();
		break;
	case STATE_Unk9:
		_100->show();
		break;
	case STATE_Unk10:
		_F8->show();
		break;
	case STATE_Unk11:
		_FC->show();
		break;
	case STATE_Unk12:
		_F0->show();
		break;
	case STATE_Unk13:
		_F4->show();
		break;
	case STATE_Unk14:
		_104->show();
		break;
	}
}
