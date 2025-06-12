#include "zen/ogSub.h"
#include "zen/Number.h"
#include "zen/DrawCommon.h"
#include "P2D/TextBox.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/strtold.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/strtoul.h"
#include "P2D/Screen.h"
#include "gameflow.h"
#include "nlib/Math.h"
#include "SoundMgr.h"
#include "DebugLog.h"
#include "sysNew.h"

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
DEFINE_PRINT("OgSubSection");

namespace zen {
static char workString[0x400];

static char wkstr[0x400]      = {};
static char numStrBuf[0x100]  = {};
static char formatStr[0x100]  = {};
static int SpecialNumber[100] = {};

/*
 * --INFO--
 * Address:	8017E850
 * Size:	00002C
 */
bool ogCheckInsCard()
{
	return gameflow.mMemoryCard.isCardInserted();
}

/*
 * --INFO--
 * Address:	8017E87C
 * Size:	000068
 */
f32 calcPuruPuruScale(f32 p1)
{
	STACK_PAD_VAR(1);

	f32 val = (p1 / 0.5f);
	if (val > 1.0f) {
		val = 1.0f;
	}
	f32 x = (1.0f - val) * 0.08f;
	return (NMathF::cos(2.0f * TAU * val) + 1.0f) * x + 1.0f;
}

/*
 * --INFO--
 * Address:	8017E8E4
 * Size:	000174
 */
void setNumberTag(P2DScreen* screen, u32 tag, int* valuePtr, int digit)
{
	P2DPane* pane = screen->search(tag, true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, valuePtr, digit, false));
}

/*
 * --INFO--
 * Address:	8017EA94
 * Size:	000064
 */
void setTextColor(P2DTextBox* tbox, P2DPicture* pic)
{
	Colour white = tbox->getCharColor();
	Colour black = tbox->getGradColor();
	black.a      = 0;
	pic->setWhite(white);
	pic->setBlack(black);
}

/*
 * --INFO--
 * Address:	8017EAF8
 * Size:	000088
 */
bool getStringCVS(char* p1, char* p2, s16 p3)
{
	s16 count = 512;
	while (p3 > 0) {
		char a = *p2;
		if (!a) {
			return true;
		}
		if (a == ',' || a == '\n') {
			p3--;
		}
		p2++;
	}

	while (true) {
		char a = *p2;
		if (a != 0 && a != ',' && a != '\n') {
			*p1++ = a;
			p2++;
			count--;
			if (count < 0) {
				PRINT("文字列が%d文字を超えました。\n", 0); // 'the string exceeds %d characters.'
				return true;
			}
		} else {
			break;
		}
	};

	*p1 = 0;
	return false;
}

/*
 * --INFO--
 * Address:	8017EB80
 * Size:	000328
 */
PikaAlphaMgr::PikaAlphaMgr(P2DScreen* screen)
{
	_04 = 0;
	char str[512];
	char buf[8];
	for (int i = 0; i < 100; i++) {
		sprintf(buf, "pk%02d", i);
		P2DPane* pane = screen->search(P2DPaneLibrary::makeTag(buf), false);
		if (!pane) {
			continue;
		}

		P2DPane* parent = pane->getPaneTree()->getParent()->getObject();
		if (parent->getTypeID() != PANETYPE_Picture) {
			continue;
		}

		P2DPicture* pic  = (P2DPicture*)parent;
		P2DTextBox* tbox = (P2DTextBox*)pane;
		char* text       = tbox->getString();
		tbox->hide();
		getStringCVS(str, text, 0);
		f32 val0 = atof(str);
		getStringCVS(str, text, 1);
		f32 val1 = atof(str);

		pic->printTagName(false);
		u8 cAlpha = tbox->getCharColor().a;
		u8 gAlpha = tbox->getGradColor().a;

		mTenmetuAlphas[_04] = new setTenmetuAlpha(pic, val0, val1, cAlpha, gAlpha);

		for (int j = 0; j < 20; j++) {
			s16 idx = 7 * j;
			if (getStringCVS(str, text, idx + 2)) {
				break;
			}
			u8 red1 = atoi(str);
			if (getStringCVS(str, text, idx + 3)) {
				break;
			}
			u8 green1 = atoi(str);
			if (getStringCVS(str, text, idx + 4)) {
				break;
			}
			u8 blue1 = atoi(str);
			if (getStringCVS(str, text, idx + 5)) {
				break;
			}
			u8 red2 = atoi(str);
			if (getStringCVS(str, text, idx + 6)) {
				break;
			}
			u8 green2 = atoi(str);
			if (getStringCVS(str, text, idx + 7)) {
				break;
			}
			u8 blue2 = atoi(str);
			if (getStringCVS(str, text, idx + 8)) {
				break;
			}
			f32 val2 = atof(str);

			Colour col1(red1, green1, blue1, 255);
			Colour col2(red2, green2, blue2, 255);
			mTenmetuAlphas[_04]->setColorTab(j, &col1, &col2, val2);
		}
		_04++;
	}
}

/*
 * --INFO--
 * Address:	8017EEA8
 * Size:	00006C
 */
void PikaAlphaMgr::start()
{
	mState = 0;
	for (int i = 0; i < _04; i++) {
		mTenmetuAlphas[i]->start();
	}
}

/*
 * --INFO--
 * Address:	8017EF14
 * Size:	000084
 */
void PikaAlphaMgr::startFadeIn(f32 p1)
{
	mState = 1;
	for (int i = 0; i < _04; i++) {
		mTenmetuAlphas[i]->startFadeIn(p1, 0.0f, 1.0f);
	}
}

/*
 * --INFO--
 * Address:	8017EF98
 * Size:	000084
 */
void PikaAlphaMgr::startFadeOut(f32 p1)
{
	mState = 2;
	for (int i = 0; i < _04; i++) {
		mTenmetuAlphas[i]->startFadeOut(p1, 0.0f, 1.0f);
	}
}

/*
 * --INFO--
 * Address:	8017F01C
 * Size:	000118
 */
void PikaAlphaMgr::update()
{
	int i;
	switch (mState) {
	case 1:
		for (i = 0; i < _04; i++) {
			if (mTenmetuAlphas[i]->update() == 1) {
				mState = 0;
			}
		}
		break;

	case 2:
		for (i = 0; i < _04; i++) {
			if (mTenmetuAlphas[i]->update() == 0) {
				mState = -1;
			}
		}
		break;

	case 0:
		for (i = 0; i < _04; i++) {
			mTenmetuAlphas[i]->update();
		}
		break;

	case -1:
		break;
	}
}

/*
 * --INFO--
 * Address:	8017F134
 * Size:	0000F0
 */
setTenmetuAlpha::setTenmetuAlpha(P2DPicture* pic, f32 p2, f32 p3, u8 p4, u8 p5)
{
	mMode = MODE_Unk0;
	mPic  = pic;
	_08   = p2;
	_0C   = p3;
	_1C   = p4;
	_1D   = p5;
	_18   = (_1D - _1C);
	_128  = 0;
	_12A  = 0;
	_120  = p3;
	_124  = p3;
	_10   = 0.0f;
	_14   = 1.0f;
}

/*
 * --INFO--
 * Address:	8017F224
 * Size:	0000F0
 */
setTenmetuAlpha::setTenmetuAlpha(P2DPicture* pic, f32 p2)
{
	mMode = MODE_Unk0;
	mPic  = pic;
	_08   = p2;
	_0C   = 0.0f;
	_1C   = 0;
	_1D   = 255;
	_18   = (_1D - _1C);
	_128  = 0;
	_12A  = 0;
	_120  = 0.0f;
	_124  = 0.0f;
	_10   = 0.0f;
	_14   = 1.0f;
}

/*
 * --INFO--
 * Address:	8017F314
 * Size:	000368
 */
void setTenmetuAlpha::updateColor()
{
	if (_128 > 0) {
		Colour col1 = _30[_12A];
		Colour col2 = _30[(_12A + 1) % _128];
		f32 t       = _120 / _D0[_12A];

		if (t > 1.0f) {
			t = 1.0f;
		}

		f32 tComp = 1.0f - t;

		Colour targCol(col1.r * tComp + col2.r * t, col1.g * tComp + col2.g * t, col1.b * tComp + col2.b * t, col1.a * tComp + col2.a * t);
		mPic->setWhite(targCol);
		col1 = _80[_12A];
		col2 = _80[(_12A + 1) % _128];
		t    = _120 / _D0[_12A];
		if (t > 1.0f) {
			t = 1.0f;
		}

		tComp = 1.0f - t;

		targCol.set(col1.r * tComp + col2.r * t, col1.g * tComp + col2.g * t, col1.b * tComp + col2.b * t, 0);
		mPic->setBlack(targCol);

		_120 += gsys->getFrameTime();
		if (_120 > _D0[_12A]) {
			_120 = 0.0f;
			_12A++;
			if (_12A >= _128) {
				_12A = 0;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8017F67C
 * Size:	000024
 */
void setTenmetuAlpha::start()
{
	_12A  = 0;
	_0C   = _124;
	_120  = _124;
	mMode = MODE_Unk1;
}

/*
 * --INFO--
 * Address:	8017F6A0
 * Size:	000060
 */
void setTenmetuAlpha::startFadeIn(f32 p1, f32 p2, f32 p3)
{
	if (mMode == MODE_Unk1) {
		return;
	}

	if (p1 <= 0.0f) {
		p1 = 0.01f;
	}

	_12A  = 0;
	_0C   = _124;
	_120  = _124;
	_14   = p1;
	_10   = 0.0f;
	_24   = p2;
	_28   = p3;
	_20   = p3 - p2;
	mMode = MODE_Unk2;
}

/*
 * --INFO--
 * Address:	8017F700
 * Size:	000048
 */
void setTenmetuAlpha::startFadeOut(f32 p1, f32 p2, f32 p3)
{
	if (mMode == MODE_Unk0) {
		return;
	}

	if (p1 <= 0.0f) {
		p1 = 0.01f;
	}

	_14   = p1;
	_10   = 0.0f;
	_24   = p2;
	_28   = p3;
	_20   = p3 - p2;
	mMode = MODE_Unk3;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void setTenmetuAlpha::calcAlpha(f32 p1)
{
	if (_08 > 0.0f) {
		_0C += gsys->getFrameTime();
		if (_0C > _08) {
			_0C -= _08;
		}

		updateColor();
		f32 angle = TAU * _0C / _08;
		u8 alpha  = u8(_1C + int((sinf(angle) + 1.0f) * _18 / 2.0f));
		alpha     = alpha * p1;
		mPic->setAlpha(alpha);
	}
}

/*
 * --INFO--
 * Address:	8017F748
 * Size:	000358
 */
setTenmetuAlpha::TenmetuMode setTenmetuAlpha::update()
{
	if (mMode == MODE_Unk0) {
		return mMode;
	}

	switch (mMode) {
	case MODE_Unk2:
		_10 += gsys->getFrameTime();
		f32 t = _10 / _14;
		if (t < 0.0f) {
			t = 0.0f;
		}
		if (t > 1.0f) {
			t     = 1.0f;
			mMode = MODE_Unk1;
		}

		calcAlpha(_24 + _20 * t);
		break;

	case MODE_Unk3:
		_10 += gsys->getFrameTime();
		t = _10 / _14;
		if (t < 0.0f) {
			t = 0.0f;
		}
		if (t > 1.0f) {
			t     = 1.0f;
			mMode = MODE_Unk0;
		}

		calcAlpha(_28 - _20 * t);
		break;

	case MODE_Unk1:
		calcAlpha(1.0f);
		break;
	}

	return mMode;
}

/*
 * --INFO--
 * Address:	8017FAA0
 * Size:	000080
 */
ogFadeMgr::ogFadeMgr(P2DPane* pane, u8 p2)
{
	mState    = Status_0;
	mPane     = pane;
	_0C       = 1.0f;
	_10       = 0.0f;
	_14       = 0.0f;
	_18       = 0.0f;
	_1C       = p2;
	mPaneType = mPane->getTypeID();
	setAlpha();
}

/*
 * --INFO--
 * Address:	8017FB20
 * Size:	000068
 */
void ogFadeMgr::start(ogFadeMgr::ogFadeStatusFlag state, f32 p2)
{
	if (p2 == 0.0f) {
		return;
	}
	mState = state;
	_0C    = p2;
	_10    = 0.0f;
	switch (mState) {
	case Status_1:
		_14 = _18;
		break;

	case Status_2:
		_14 = _1C;
		break;
	}

	setAlpha();
}

/*
 * --INFO--
 * Address:	8017FB88
 * Size:	000078
 */
void ogFadeMgr::setAlpha()
{
	switch (mPaneType) {
	case PANETYPE_Picture:
		P2DPicture* pic = (P2DPicture*)mPane;
		pic->setAlpha(_14);
		break;

	case PANETYPE_TextBox:
		P2DTextBox* tbox = (P2DTextBox*)mPane;
		tbox->setAlpha(_14);
		break;

	default:
		mPane->hide();
		break;
	}
}

/*
 * --INFO--
 * Address:	8017FC00
 * Size:	000140
 */
ogFadeMgr::ogFadeStatusFlag ogFadeMgr::update()
{
	if (mState == Status_0) {
		return mState;
	}

	_10 += gsys->getFrameTime();
	if (_10 > _0C) {
		_10 = _0C;
	}

	f32 t = _10 / _0C;
	switch (mState) {
	case Status_1:
		_14 = _18 * (1.0f - t) + _1C * t;
		break;

	case Status_2:
		_14 = _1C * (1.0f - t) + _18 * t;
		break;
	}

	setAlpha();

	if (_10 >= _0C) {
		mState = Status_0;
	}

	return mState;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void movePicturePos(P2DPicture* alignPic, P2DPicture* movingPic)
{
	int x = alignPic->getPosH();
	int y = alignPic->getPosV();
	movingPic->move(x, y);
}

/*
 * --INFO--
 * Address:	8017FD64
 * Size:	000178
 */
ogTexAnimSubMgr::ogTexAnimSubMgr(P2DScreen* screen, P2DPicture* pic, P2DTextBox* tbox)
{
	char tmpStr[512];
	_14        = 0;
	mPicture   = pic;
	mTextBox   = tbox;
	char* text = mTextBox->getString();

	for (int i = 0; i < 100; i++) {
		if (getStringCVS(tmpStr, text, 2 * i)) {
			break;
		}

		if (strcmp(tmpStr, "") == 0) {
			break;
		}

		P2DPicture* pane = (P2DPicture*)screen->search(P2DPaneLibrary::makeTag(tmpStr), true);
		if (!pane) {
			break;
		}

		_1A8[i] = pane;
		if (getStringCVS(tmpStr, text, 2 * i + 1)) {
			break;
		}

		_18[i] = atof(tmpStr);
		_14++;
	}

	_16 = 0;
	_0C = 0.0f;
	_10 = 1.0f;
	if (_14 > 0) {
		_08 = _18[_16];
		movePicturePos(mPicture, _1A8[_16]);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
void ogTexAnimSubMgr::update()
{
	if (_14) {
		_0C += gsys->getFrameTime() * _10;
		if (_0C > _08) {
			_1A8[_16]->hide();
			_16++;
			if (_16 >= _14) {
				_16 = 0;
			}

			_0C = 0.0f;
			_08 = _18[_16];
			movePicturePos(mPicture, _1A8[_16]);
			_1A8[_16]->show();
		}
	}
}

/*
 * --INFO--
 * Address:	8017FEDC
 * Size:	0000F4
 */
ogTexAnimMgr::ogTexAnimMgr(P2DScreen* screen)
{
	char buf[8];
	_00 = 0;
	for (int i = 0; i < 100; i++) {
		sprintf(buf, "at%02d", i);
		P2DPane* pane = screen->search(P2DPaneLibrary::makeTag(buf), false);
		if (!pane) {
			continue;
		}

		P2DPane* parent = pane->getPaneTree()->getParent()->getObject();
		if (parent->getTypeID() == PANETYPE_Picture) {
			P2DPicture* pic  = (P2DPicture*)parent;
			P2DTextBox* tbox = (P2DTextBox*)pane;
			mSubMgrs[i]      = new ogTexAnimSubMgr(screen, pic, tbox);
			_00++;
		}
	}
}

/*
 * --INFO--
 * Address:	8017FFD0
 * Size:	00014C
 */
void ogTexAnimMgr::update()
{
	for (int i = 0; i < _00; i++) {
		mSubMgrs[i]->update();
	}
}

/*
 * --INFO--
 * Address:	8018011C
 * Size:	000030
 */
int getSpecialNumber(int idx)
{
	if (idx < 0 || idx > 99) {
		return -1;
	}

	return SpecialNumber[idx];
}

/*
 * --INFO--
 * Address:	8018014C
 * Size:	00002C
 */
void setSpecialNumber(int idx, int value)
{
	if (idx < 0 || idx > 99) {
		return;
	}

	SpecialNumber[idx] = value;
}

/*
 * --INFO--
 * Address:	80180178
 * Size:	000218
 */
void cnvSpecialNumber(char* str)
{
	char* tmp  = str;
	char* work = wkstr;
	strcpy(formatStr, "%d");

	while (true) {
		char a = tmp[0];
		char b = tmp[1];
		char c = tmp[2];
		char d = tmp[3];

		if (a == 0) {
			break;
		}

		if (a == 0x1B) { // esc character
			if (strncmp(tmp + 1, "TM", 2) == 0) {
				tmp += 3;
			} else if (b == 'Z') {
				if (c == 0) {
					break;
				}
				if (c >= '0' && c <= '9') {
					int digit = c - '0';
					PRINT("zero_long = %d\n", digit);
					tmp += 3;
					if (digit > 1) {
						sprintf(formatStr, "%%0%dd", digit);
					} else {
						strcpy(formatStr, "%d");
					}
					PRINT("formatStr = '%s'\n", formatStr);
				} else {
					tmp++;
				}
			} else if (b == 'd') {
				if (c == 0) {
					break;
				}
				if (c >= '0' && c <= '9') {
					if (d >= '0' && d <= '9') {
						int idx = 10 * (c - '0');
						idx += d - '0';
						int num = SpecialNumber[idx];
						tmp += 4;
						sprintf(work, formatStr, num);
						sprintf(numStrBuf, formatStr, num);
						work += strlen(numStrBuf);
					} else {
						int num = SpecialNumber[c - '0'];
						tmp += 3;
						sprintf(work, formatStr, num);
						sprintf(numStrBuf, formatStr, num);
						work += strlen(numStrBuf);
					}
				} else {
					tmp += 2;
				}
			} else {
				PRINT("ERR ? \n");
				*work++ = *tmp++;
			}
		} else if (a & 0x80) {
			*work  = a;
			char e = tmp[1];
			tmp += 2;
			work[1] = e;
			work += 2;
		} else {
			*work = a;
			work++;
			tmp++;
		}
	}
	*work = 0;
	strcpy(str, wkstr);
}

/*
 * --INFO--
 * Address:	80180390
 * Size:	000090
 */
TypingTextMgr::TypingTextMgr(P2DTextBox* textBox)
{
	mTextBox = textBox;
	mTextPtr = textBox->getString();
	sprintf(mTextBuf, "");
	_00  = 0;
	_410 = 0.0f;
	_414 = 0;

	textBox->hide();
	mCtrlTagMgr = new ogMsgCtrlTagMgr();
}

/*
 * --INFO--
 * Address:	80180420
 * Size:	000074
 */
void TypingTextMgr::start()
{
	STACK_PAD_VAR(1);

	_00  = 1;
	_410 = 0.0f;
	_414 = 0;
	sprintf(mTextBuf, "");
	mTextBox->show();
	mTextBox->setString(mTextBuf);
}

/*
 * --INFO--
 * Address:	80180494
 * Size:	000160
 */
ogMsgCtrlTagMgr::ogMsgCtrlTagMgr()
{
	P2DScreen* screen = new P2DScreen();
	screen->set("screen/blo/wait_char.blo", false, false, true);

	P2DTextBox* onesBox     = (P2DTextBox*)screen->search('maru', true);
	P2DTextBox* tensBox     = (P2DTextBox*)screen->search('ten', true);
	P2DTextBox* hundredsBox = (P2DTextBox*)screen->search('han', true);

	strcpy(_00, onesBox->getString());
	strcpy(_08, tensBox->getString());
	strcpy(_10, hundredsBox->getString());
}

/*
 * --INFO--
 * Address:	801805F4
 * Size:	0003A8
 */
bool ogMsgCtrlTagMgr::CheckCtrlTag(char* p1, s16* p2, f32* p3)
{
	STACK_PAD_VAR(1);
	int a         = *p2;
	char* tmpStr1 = &p1[*p2];
	char b        = *tmpStr1;
	*p3           = 0.0f;

	if (b == 0) {
		return true;
	}

	s16 c;
	if (strncmp(tmpStr1, _00, 2) == 0) {
		PRINT("Hit MARU !!\n");
		*p3 = 0.25f;
		c   = a + 2;
	} else if (strncmp(tmpStr1, _08, 2) == 0) {
		PRINT("Hit TEN !!\n");
		*p3 = 0.25f;
		c   = a + 2;
	} else if (b == 0x1B) { // esc character
		c       = a + 1;
		char* d = p1 + c;
		if (strncmp(d, "CC", 2) == 0 || strncmp(d, "GC", 2) == 0 || strncmp(d, "TM", 2) == 0 || strncmp(d, "Z", 1) == 0
		    || strncmp(d, "CA", 2) == 0 || strncmp(d, "GA", 2) == 0 || strncmp(d, "TB", 2) == 0 || strncmp(d, "BS", 2) == 0
		    || strncmp(d, "CU", 2) == 0 || strncmp(d, "CD", 2) == 0 || strncmp(d, "CL", 2) == 0 || strncmp(d, "CR", 2) == 0
		    || strncmp(d, "LU", 2) == 0 || strncmp(d, "LD", 2) == 0 || strncmp(d, "HM", 2) == 0 || strncmp(d, "ST", 2) == 0
		    || strncmp(d, "FX", 2) == 0 || strncmp(d, "FY", 2) == 0 || strncmp(d, "SH", 2) == 0 || strncmp(d, "SV", 2) == 0
		    || strncmp(d, "GM", 2) == 0) {
			if (strncmp(d, "Z", 1) == 0) {
				c++;
			} else if (strncmp(d, "TM", 2) == 0) {
				*p3 = 0.25f;
				c += 2;
			} else {
				char* tmp = strstr(d, "]");
				if (tmp) {
					int count = tmp - d + 1;
					strncpy(workString, d, count);
					workString[count] = 0;
					PRINT("SKIP '%s'\n", workString);
					c += count;
				} else {
					c += 2;
				}
			}
		} else {
			PRINT("Tag ERROR !!! (%s)\n", d);
		}
	} else if (b & 0x80) {
		c = a + 2;
		SeSystem::playSysSe(SYSSE_TYPEWRITER);
	} else if (strchr(_10, b)) {
		PRINT("Hit HANKAKU WAIT!!\n");
		*p3 = 0.25f;
		SeSystem::playSysSe(SYSSE_TYPEWRITER);
		c = a + 1;
	} else {
		c = a + 1;
		SeSystem::playSysSe(SYSSE_TYPEWRITER);
	}

	*p2 = c;
	return false;
}

/*
 * --INFO--
 * Address:	8018099C
 * Size:	000104
 */
void TypingTextMgr::update()
{
	if (_00 == 0) {
		mTextBox->hide();
		return;
	}
	if (_00 == 2) {
		mTextBox->setString(mTextPtr);
		return;
	}

	_410 += gsys->getFrameTime();
	if (_410 >= 0.029639998f) {
		_410 -= 0.029639998f;
		f32 a;
		if (mCtrlTagMgr->CheckCtrlTag(mTextPtr, &_414, &a)) {
			_00 = 2;
		}

		if (a > 0.0f) {
			_410 = -a;
		}
		if (_414 > 1023) {
			_414 = 1023;
		}
		strncpy(mTextBuf, mTextPtr, _414);
		mTextBuf[_414] = 0;
	}
}

/*
 * --INFO--
 * Address:	80180AA0
 * Size:	0003B4
 */
void cnvSpecialNumberHyphen(char* str)
{
	char* tmp  = str;
	char* work = wkstr;
	int num    = 0;
	strcpy(formatStr, "%d");

	while (true) {
		char a = tmp[0];
		char b = tmp[1];
		char c = tmp[2];
		char d = tmp[3];

		if (a == 0) {
			break;
		}

		if (a == 0x1B) { // esc character
			if (strncmp(tmp + 1, "TM", 2) == 0) {
				tmp += 3;
			} else if (b == 'Z') {
				if (c >= '0' && c <= '9') {
					num = c - '0';
					tmp += 3;
					if (num > 1) {
						sprintf(formatStr, "%%0%dd", num);
					} else {
						strcpy(formatStr, "%d");
					}
				}
			} else if (b == 'd') {
				if (c >= '0' && c <= '9') {
					if (d >= '0' && d <= '9') {
						int idx = 10 * (c - '0');
						idx += d - '0';
						int num2 = SpecialNumber[idx];
						tmp += 4;
						if (num2 >= 0) {
							sprintf(work, formatStr, num2);
							sprintf(numStrBuf, formatStr, num2);
						} else {
							char buf[PATH_MAX];
							STACK_PAD_VAR(1);
							for (int i = 0; i < num; i++) {
								buf[i] = '*';
							}
							buf[num] = 0;
							sprintf(work, "%s", buf);
							sprintf(numStrBuf, "%s", buf);
						}
						work += strlen(numStrBuf);
					} else {
						int num2 = SpecialNumber[c - '0'];
						tmp += 3;
						if (num2 >= 0) {
							sprintf(work, formatStr, num2);
							sprintf(numStrBuf, formatStr, num2);
						} else {
							char buf[PATH_MAX];
							for (int i = 0; i < num; i++) {
								buf[i] = '*';
							}
							buf[num] = 0;
							sprintf(work, "%s", buf);
							sprintf(numStrBuf, "%s", buf);
						}
						work += strlen(numStrBuf);
					}
				} else {
					tmp += 2;
				}
			} else {
				*work++ = *tmp++;
			}
		} else if (a & 0x80) {
			*work  = a;
			char e = tmp[1];
			tmp += 2;
			work[1] = e;
			work += 2;
		} else {
			*work = a;
			work++;
			tmp++;
		}
	}

	*work = 0;
	strcpy(str, wkstr);
}

} // namespace zen
