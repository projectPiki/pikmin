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
// DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT(nullptr)

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

	_30 = _58;
	_1C = STATE_NULL;
	_20 = -1;

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

	switch (_1C) {
	case 10:
		_20 = 10;
		_1C = STATE_Unk1;
		setPCtex(_48);
		SetNitaku_F_N();
		break;
	case 11:
		_20 = 11;
		_1C = STATE_Unk1;
		setPCtex(_44);
		SetNitaku_F_N();
		break;
	}

	// Because the first switch wasnt good enough
	switch (_1C) {
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
	_1C = STATE_Unk15;
	_C8 = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void zen::ogScrMemChkMgr::RepairFileStart()
{
	gameflow.mMemoryCard.repairFile();
	_1C = STATE_Unk16;
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
	_00 = 0;
	_1C = STATE_Unk0;
	if (!ogCheckInsCard()) {
		PRINT("ERR_NOCARD in ogMemChk\n");
		_1C = STATE_Unk8;
	} else {
		int cardstate = gameflow.mMemoryCard.getMemoryCardState(false);
		PRINT("ogMemChk error = %d \n", cardstate);
		if (cardstate == -2) {
			PRINT("ERR_NOTACARD in ogMemChk\n");
			_1C = STATE_Unk9;
		} else if (cardstate == -5) {
			PRINT("ERR_ENCODING in ogMemChk\n");
			_1C = STATE_Unk10;
		} else if (cardstate == -4) {
			PRINT("ERR_BROKEN in ogMemChk\n");
			_1C = STATE_Unk11;
		} else if (cardstate == -3) {
			PRINT("ERR_FULLUP in ogMemChk\n");
			_1C = STATE_Unk12;
		} else if (cardstate == -6) {
			PRINT("ERR_UNUSABLE in ogMemChk\n");
			_1C = STATE_Unk13;
		} else if (cardstate == -8) {
			PRINT("ERR_NOFILE in ogMemChk\n");
			_1C = STATE_Unk14;
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
	PRINT("@@@@@@@@@@@@@@ DebugStart(%d)  status = %d @@@@@@@@@@@@@@\n", state, _1C);

	if (state >= 1 && state <= 9) {

		_1C = (MemChkStatus)(state + 7);

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
	Vector3f pos;
	pos.set(320.0f, 240.0f, 0.0f);
	pos.x = _A8->getWidth() / 2 + _A8->getPosH();
	pos.y = 480.0f - (_A8->getHeight() / 2 + _A8->getPosV());
	PRINT("FormatEffectStart !! (%f,%f)\n", pos.x, pos.y);
	_10 = _0C->create(EFF2D_Unk39, pos, nullptr, nullptr);
	_14 = _0C->create(EFF2D_Unk40, pos, nullptr, nullptr);
	// UNUSED FUNCTION
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
			_1C = STATE_Unk19;
		} else if (status == 5) {
			_1C = STATE_Unk20;
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
	_1C = STATE_Unk8;
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
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018E0DC
 * Size:	000EC4
 */
zen::ogScrMemChkMgr::MemChkStatus zen::ogScrMemChkMgr::update(Controller* input)
{
	if (_1C == STATE_NULL) {
		return _1C;
	}

	if (_1C == STATE_Unk0) {
		_1C = STATE_Unk21;
		return _1C;
	}

	if (_1C >= STATE_Unk19) {
		_1C = STATE_NULL;
		return _1C;
	}

	_C8 += gsys->getFrameTime();

	bool hasCard = ogCheckInsCard();
	if (!hasCard && _1C != STATE_Unk8) {
		setNoCard();
	}

	switch (_1C) {
	case STATE_Unk1:
		if (checkTypingAll()) {
			_1C = STATE_Unk2;
			SetNitaku_F_N();
			_D4->start();
			DispYesNo(true);
		} else {
			DispYesNo(false);
		}
		break;
	case STATE_Unk2: {
		int stat = _D4->update(input);
		if (stat > 3) {
			if (stat == 5) {
				setPCtex(_34);
				_1C = STATE_Unk3;
				_C8 = 0.0f;
			} else {
				_C4 = 0.0f;
				if (_20 == 10) {
					setPCtex(_64);
					_1C = STATE_Unk10;
					_D4->start();
				} else if (_20 == 11) {
					setPCtex(_68);
					_1C = STATE_Unk11;
					_D4->start();
				} else {
					_1C = STATE_Unk1;
				}
				_C8 = 0.0f;
			}
		}
		break;
	}
	case STATE_Unk3:
		if (checkTypingAll()) {
			_1C = STATE_Unk4;
			SetNitaku_Y_N();
			_D4->start();
			DispYesNo(true);
		} else {
			DispYesNo(false);
		}
		break;
	case STATE_Unk8:
		if (hasCard) {
			start();
			return _1C;
		}
		checkErrNitaku(_D4, input);
		break;
	case STATE_Unk9:
	case STATE_Unk13:
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
	case STATE_Unk4: {
		int stat = _D4->update(input);
		if (stat > 3) {
			if (stat == 5) {
				setPCtex(_40);
				_1C = STATE_Unk5;
				DispYesNo(false);
				DispAcup(false);
				_C8 = 0.0f;
				FormatEffectStart();
			} else {
				if (_20 == 10) {
					setPCtex(_48);
				} else if (_20 == 11) {
					setPCtex(_64);
				}
				_C8 = 0.0f;
				_1C = STATE_Unk1;
			}
		}
		break;
	case STATE_Unk5:
		DispYesNo(false);
		DispAcup(true);
		if (checkTypingAll() && _C8 > 6.0f) {
			_10->finish();
			_14->finish();
			if (!gameflow.mMemoryCard.doFormatCard()) {
				setPCtex(_38);
				_A4->show();
				_A0->start();
				_1C = STATE_Unk6;
			} else {
				setPCtex(_3C);
				_A4->show();
				_A0->start();
				_1C = STATE_Unk7;
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
				_1C = STATE_Unk21;
			}
		}
		break;
	case STATE_Unk7:
		_A0->update();
		if (input->keyClick(KBBTN_A | KBBTN_START)) {
			seSystem->playSysSe(SYSSE_DECIDE1);
			_C4 = 0.0f;
			_1C = STATE_NULL;
			start();
		}
		break;
	case STATE_Unk15: {
		int stat = _18->update(input);
		if (stat == 4) {
			_1C = STATE_Unk21;
		} else if (stat == 5) {
			setPCtex(_68);
			_1C = STATE_Unk11;
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
			u8 fail = gameflow.mMemoryCard.didSaveFail();
			if (!fail) {
				_1C = STATE_Unk17;
				setPCtex(_50);
			} else {
				_1C = STATE_Unk18;
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
				_1C = STATE_Unk21;
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
				_1C = STATE_Unk11;
				SetNitaku_W_R();
				_D4->start();
				_C4 = 0.0f;
				_C8 = 0.0f;
			}
		}
		break;
	}
	}

	setErrorMessage();

	if (_1C >= STATE_Unk19) {
		return _1C;
	} else {
		_0C->update();
		_2C->update();
		_BC->update();
		_30->update();
		_30->transCursor(_C0);
		_24->update();
	}

	return _1C;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x378(r1)
	  stw       r31, 0x374(r1)
	  mr        r31, r3
	  stw       r30, 0x370(r1)
	  stw       r29, 0x36C(r1)
	  stw       r28, 0x368(r1)
	  addi      r28, r4, 0
	  lwz       r3, 0x1C(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x34
	  b         .loc_0xEA4

	.loc_0x34:
	  cmpwi     r3, 0
	  bne-      .loc_0x4C
	  li        r0, 0x15
	  stw       r0, 0x1C(r31)
	  lwz       r3, 0x1C(r31)
	  b         .loc_0xEA4

	.loc_0x4C:
	  cmpwi     r3, 0x13
	  blt-      .loc_0x64
	  li        r0, -0x1
	  stw       r0, 0x1C(r31)
	  lwz       r3, 0x1C(r31)
	  b         .loc_0xEA4

	.loc_0x64:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0xC8(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC8(r31)
	  bl        -0xF904
	  rlwinm.   r0,r3,0,24,31
	  addi      r29, r3, 0
	  bne-      .loc_0x168
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0x8
	  beq-      .loc_0x168
	  li        r0, 0x8
	  stw       r0, 0x1C(r31)
	  mr        r3, r31
	  bl        0xF34
	  lwz       r3, 0x98(r31)
	  li        r30, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xA4(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0xD8(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xD8(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r3, 0xD4(r31)
	  bl        0x8A60
	  lwz       r5, 0x30(r31)
	  lwz       r4, 0x58(r31)
	  lwz       r3, 0x8(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r30, 0x0(r5)
	  stw       r4, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xDDF0
	  lwz       r3, 0x10(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x150
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x150:
	  lwz       r3, 0x14(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x168
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x168:
	  lwz       r0, 0x1C(r31)
	  cmplwi    r0, 0x12
	  bgt-      .loc_0xE28
	  lis       r3, 0x802D
	  addi      r3, r3, 0x5D44
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x1A4
	  mr        r3, r31
	  bl        -0x54C
	  lwz       r3, 0x1C(r31)
	  b         .loc_0xEA4

	.loc_0x1A4:
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xD4(r31)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x1C0
	  li        r0, 0x1
	  b         .loc_0x1C4

	.loc_0x1C0:
	  li        r0, 0

	.loc_0x1C4:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x210
	  lwz       r5, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r4,7,24,24
	  addi      r4, r28, 0
	  stb       r0, 0xC(r5)
	  bl        0x8B98
	  cmpwi     r3, 0x6
	  bne-      .loc_0x1FC
	  li        r0, 0x13
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x1FC:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xE28
	  li        r0, 0x14
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x210:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xD4(r31)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x274
	  li        r0, 0x1
	  b         .loc_0x278

	.loc_0x274:
	  li        r0, 0

	.loc_0x278:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x2C4
	  lwz       r5, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r4,7,24,24
	  addi      r4, r28, 0
	  stb       r0, 0xC(r5)
	  bl        0x8AE4
	  cmpwi     r3, 0x6
	  bne-      .loc_0x2B0
	  li        r0, 0x13
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x2B0:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xE28
	  li        r0, 0x14
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x2C4:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xD4(r31)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x328
	  li        r0, 0x1
	  b         .loc_0x32C

	.loc_0x328:
	  li        r0, 0

	.loc_0x32C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x378
	  lwz       r5, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r4,7,24,24
	  addi      r4, r28, 0
	  stb       r0, 0xC(r5)
	  bl        0x8A30
	  cmpwi     r3, 0x6
	  bne-      .loc_0x364
	  li        r0, 0x13
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x364:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xE28
	  li        r0, 0x14
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x378:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xD4(r31)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x3DC
	  li        r0, 0x1
	  b         .loc_0x3E0

	.loc_0x3DC:
	  li        r0, 0

	.loc_0x3E0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x42C
	  lwz       r5, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r4,7,24,24
	  addi      r4, r28, 0
	  stb       r0, 0xC(r5)
	  bl        0x897C
	  cmpwi     r3, 0x6
	  bne-      .loc_0x418
	  li        r0, 0x13
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x418:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xE28
	  li        r0, 0x14
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x42C:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xD4(r31)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x460
	  li        r0, 0x1
	  b         .loc_0x464

	.loc_0x460:
	  li        r0, 0

	.loc_0x464:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x4B0
	  lwz       r5, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r4,7,24,24
	  addi      r4, r28, 0
	  stb       r0, 0xC(r5)
	  bl        0x88F8
	  cmpwi     r3, 0x6
	  bne-      .loc_0x49C
	  li        r0, 0x13
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x49C:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xE28
	  li        r0, 0x14
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x4B0:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x4E0
	  li        r0, 0x1
	  b         .loc_0x4E4

	.loc_0x4E0:
	  li        r0, 0

	.loc_0x4E4:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x544
	  li        r0, 0x2
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0xE0(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE0(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r3, 0xD4(r31)
	  bl        0x8644
	  lwz       r3, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28

	.loc_0x544:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r3, 0xD4(r31)
	  mr        r4, r28
	  bl        0x8818
	  cmpwi     r3, 0x4
	  blt-      .loc_0xE28
	  cmpwi     r3, 0x5
	  bne-      .loc_0x5B8
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x34(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE25C
	  li        r0, 0x3
	  stw       r0, 0x1C(r31)
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0xE28

	.loc_0x5B8:
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC4(r31)
	  lwz       r0, 0x20(r31)
	  cmpwi     r0, 0xA
	  bne-      .loc_0x60C
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x64(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE2B0
	  li        r0, 0xA
	  stw       r0, 0x1C(r31)
	  lwz       r3, 0xD4(r31)
	  bl        0x8568
	  b         .loc_0x65C

	.loc_0x60C:
	  cmpwi     r0, 0xB
	  bne-      .loc_0x654
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x68(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE2F8
	  li        r0, 0xB
	  stw       r0, 0x1C(r31)
	  lwz       r3, 0xD4(r31)
	  bl        0x8520
	  b         .loc_0x65C

	.loc_0x654:
	  li        r0, 0x1
	  stw       r0, 0x1C(r31)

	.loc_0x65C:
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0xE28
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x680
	  li        r0, 0x1
	  b         .loc_0x684

	.loc_0x680:
	  li        r0, 0

	.loc_0x684:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x6E4
	  li        r0, 0x4
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0xD8(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xD8(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r3, 0xD4(r31)
	  bl        0x84A4
	  lwz       r3, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28

	.loc_0x6E4:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r3, 0xD4(r31)
	  mr        r4, r28
	  bl        0x8678
	  cmpwi     r3, 0x4
	  blt-      .loc_0xE28
	  cmpwi     r3, 0x5
	  bne-      .loc_0x86C
	  lwz       r5, 0x30(r31)
	  li        r28, 0
	  lwz       r4, 0x40(r31)
	  lwz       r3, 0x8(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r28,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r28, 0x0(r5)
	  stw       r4, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE3FC
	  li        r0, 0x5
	  stw       r0, 0x1C(r31)
	  lis       r8, 0x4330
	  addi      r5, r1, 0x334
	  lwz       r3, 0x98(r31)
	  li        r4, 0x27
	  li        r6, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r28,7,24,24
	  li        r7, 0
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r28,7,24,24
	  stb       r0, 0xC(r3)
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  lwz       r9, 0xA8(r31)
	  stfs      f0, 0x33C(r1)
	  stfs      f0, 0x338(r1)
	  stfs      f0, 0x334(r1)
	  lfs       f1, 0xD78(r13)
	  lfs       f0, 0xD7C(r13)
	  stfs      f1, 0x334(r1)
	  stfs      f0, 0x338(r1)
	  lfs       f0, 0xD80(r13)
	  stfs      f0, 0x33C(r1)
	  lha       r10, 0x18(r9)
	  lha       r3, 0x1C(r9)
	  xoris     r0, r10, 0x8000
	  lfd       f4, -0x4EF0(r2)
	  stw       r0, 0x364(r1)
	  sub       r3, r3, r10
	  xoris     r0, r3, 0x8000
	  lfs       f3, -0x4EFC(r2)
	  stw       r0, 0x35C(r1)
	  lfs       f2, -0x4EF4(r2)
	  stw       r8, 0x358(r1)
	  lfd       f0, 0x358(r1)
	  stw       r8, 0x360(r1)
	  fsubs     f0, f0, f4
	  lfd       f1, 0x360(r1)
	  fsubs     f1, f1, f4
	  fmuls     f0, f0, f3
	  fadds     f0, f1, f0
	  stfs      f0, 0x334(r1)
	  lha       r10, 0x1A(r9)
	  lha       r3, 0x1E(r9)
	  xoris     r0, r10, 0x8000
	  stw       r0, 0x354(r1)
	  sub       r3, r3, r10
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x34C(r1)
	  stw       r8, 0x348(r1)
	  lfd       f0, 0x348(r1)
	  stw       r8, 0x350(r1)
	  fsubs     f0, f0, f4
	  lfd       f1, 0x350(r1)
	  fsubs     f1, f1, f4
	  fmuls     f0, f0, f3
	  fadds     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x338(r1)
	  lwz       r3, 0xC(r31)
	  bl        0x5B21C
	  stw       r3, 0x10(r31)
	  addi      r5, r1, 0x334
	  li        r4, 0x28
	  lwz       r3, 0xC(r31)
	  li        r6, 0
	  li        r7, 0
	  bl        0x5B200
	  stw       r3, 0x14(r31)
	  b         .loc_0xE28

	.loc_0x86C:
	  lwz       r0, 0x20(r31)
	  cmpwi     r0, 0xA
	  bne-      .loc_0x8A8
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x48(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE55C
	  b         .loc_0x8DC

	.loc_0x8A8:
	  cmpwi     r0, 0xB
	  bne-      .loc_0x8DC
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x44(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE594

	.loc_0x8DC:
	  lfs       f0, -0x4EF8(r2)
	  li        r0, 0x1
	  stfs      f0, 0xC8(r31)
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  li        r5, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x92C
	  b         .loc_0x930

	.loc_0x92C:
	  mr        r5, r4

	.loc_0x930:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0xE28
	  lfs       f1, 0xC8(r31)
	  lfs       f0, -0x4EE8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xE28
	  lwz       r4, 0x10(r31)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x80(r4)
	  addi      r3, r3, 0x24
	  li        r28, 0x1
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)
	  lwz       r4, 0x14(r31)
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)
	  bl        -0x118E38
	  cmpwi     r3, 0
	  beq-      .loc_0x988
	  li        r28, 0

	.loc_0x988:
	  rlwinm.   r0,r28,0,24,31
	  beq-      .loc_0x9E4
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x38(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE674
	  lwz       r3, 0xA4(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xA0(r31)
	  bl        -0xF434
	  li        r0, 0x6
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x9E4:
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x3C(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE6C8
	  lwz       r3, 0xA4(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xA0(r31)
	  bl        -0xF488
	  li        r0, 0x7
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28
	  lwz       r3, 0x98(r31)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xA0(r31)
	  bl        -0xF3F8
	  lis       r3, 0x100
	  lwz       r4, 0x28(r28)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0xE28
	  li        r3, 0x111
	  bl        -0xE97E8
	  lfs       f0, -0x4EF8(r2)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  stfs      f0, 0xC4(r31)
	  lwz       r0, 0x5C(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0xABC
	  lwz       r3, 0x18(r31)
	  bl        0x517C
	  li        r0, 0xF
	  stw       r0, 0x1C(r31)
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0xE28

	.loc_0xABC:
	  li        r0, 0x15
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28
	  lwz       r3, 0xA0(r31)
	  bl        -0xF460
	  lis       r3, 0x100
	  lwz       r4, 0x28(r28)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0xE28
	  li        r3, 0x111
	  bl        -0xE9850
	  lfs       f0, -0x4EF8(r2)
	  li        r0, -0x1
	  addi      r3, r31, 0
	  stfs      f0, 0xC4(r31)
	  stw       r0, 0x1C(r31)
	  bl        -0xEB4
	  b         .loc_0xE28
	  lwz       r3, 0x18(r31)
	  mr        r4, r28
	  bl        0x51FC
	  cmpwi     r3, 0x4
	  bne-      .loc_0xB28
	  li        r0, 0x15
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0xB28:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xE28
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x68(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE814
	  li        r0, 0xB
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0xD8(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xD8(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r3, 0xD4(r31)
	  bl        0x7FD4
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC4(r31)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0xE28
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  li        r5, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0xBE8
	  b         .loc_0xBEC

	.loc_0xBE8:
	  mr        r5, r4

	.loc_0xBEC:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0xE28
	  lfs       f1, 0xC8(r31)
	  lfs       f0, -0x4EE4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xE28
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r3, r3, 0x24
	  bl        -0x1182C4
	  rlwinm    r0,r3,0,24,31
	  cntlzw    r0, r0
	  rlwinm.   r0,r0,27,24,31
	  beq-      .loc_0xC5C
	  li        r0, 0x11
	  stw       r0, 0x1C(r31)
	  li        r4, 0
	  lwz       r6, 0x30(r31)
	  lwz       r5, 0x50(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE910
	  b         .loc_0xC90

	.loc_0xC5C:
	  li        r0, 0x12
	  stw       r0, 0x1C(r31)
	  li        r4, 0
	  lwz       r6, 0x30(r31)
	  lwz       r5, 0x54(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE948

	.loc_0xC90:
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  lwz       r3, 0xA0(r31)
	  bl        -0xF6FC
	  b         .loc_0xE28
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  li        r5, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0xCE0
	  b         .loc_0xCE4

	.loc_0xCE0:
	  mr        r5, r4

	.loc_0xCE4:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0xE28
	  lwz       r3, 0xA4(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xA0(r31)
	  bl        -0xF698
	  lis       r3, 0x100
	  lwz       r4, 0x28(r28)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0xE28
	  li        r3, 0x111
	  bl        -0xE9A88
	  li        r0, 0x15
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  li        r5, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0xD6C
	  b         .loc_0xD70

	.loc_0xD6C:
	  mr        r5, r4

	.loc_0xD70:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0xE28
	  lwz       r3, 0xA4(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xA0(r31)
	  bl        -0xF724
	  lis       r3, 0x100
	  lwz       r4, 0x28(r28)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0xE28
	  li        r3, 0x111
	  bl        -0xE9B14
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x68(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xEA94
	  li        r0, 0xB
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r3, 0xD4(r31)
	  bl        0x7D54
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC4(r31)
	  stfs      f0, 0xC8(r31)

	.loc_0xE28:
	  mr        r3, r31
	  bl        0x1A8
	  lwz       r3, 0x1C(r31)
	  cmpwi     r3, 0x13
	  blt-      .loc_0xE40
	  b         .loc_0xEA4

	.loc_0xE40:
	  lwz       r3, 0xC(r31)
	  bl        0x5AC68
	  lwz       r3, 0x2C(r31)
	  bl        0x23C28
	  lwz       r3, 0xBC(r31)
	  bl        -0xF7E8
	  lwz       r3, 0x30(r31)
	  bl        -0xE59C
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xC0(r31)
	  lwz       r7, 0x8(r4)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x116(r7)
	  lwz       r12, 0x14(r12)
	  subi      r5, r4, 0x18
	  lha       r0, 0x1A(r7)
	  lha       r6, 0x114(r7)
	  mtlr      r12
	  lha       r4, 0x18(r7)
	  add       r5, r0, r5
	  add       r4, r4, r6
	  blrl
	  lwz       r3, 0x24(r31)
	  bl        0x23BD8
	  lwz       r3, 0x1C(r31)

	.loc_0xEA4:
	  lwz       r0, 0x37C(r1)
	  lwz       r31, 0x374(r1)
	  lwz       r30, 0x370(r1)
	  lwz       r29, 0x36C(r1)
	  lwz       r28, 0x368(r1)
	  addi      r1, r1, 0x378
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018EFA0
 * Size:	000110
 */
void zen::ogScrMemChkMgr::draw(Graphics& gfx)
{
	if (_1C == STATE_NULL) {
		return;
	}
	if (_1C >= STATE_Unk19) {
		return;
	}

	if (_08 > 0) {
		_08--;
		return;
	}

	P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	graf.setPort();
	_24->draw(0, 0, &graf);

	switch (_1C) {
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

	switch (_1C) {
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
