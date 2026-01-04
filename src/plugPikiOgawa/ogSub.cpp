#include "zen/ogSub.h"
#include "DebugLog.h"
#include "P2D/Screen.h"
#include "P2D/TextBox.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/strtold.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/strtoul.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "nlib/Math.h"
#include "sysNew.h"
#include "zen/DrawCommon.h"
#include "zen/Number.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("OgSubSection");

namespace zen {
static char workString[0x400];

static char wkstr[0x400]      = {};
static char numStrBuf[0x100]  = {};
static char formatStr[0x100]  = {};
static int SpecialNumber[100] = {};

/**
 * @todo: Documentation
 */
bool ogCheckInsCard()
{
	return gameflow.mMemoryCard.isCardInserted();
}

/**
 * @todo: Documentation
 */
f32 calcPuruPuruScale(f32 timer)
{
	STACK_PAD_VAR(1);

	f32 normalizedTime = (timer / 0.5f);
	if (normalizedTime > 1.0f) {
		normalizedTime = 1.0f;
	}

	f32 amplitude = (1.0f - normalizedTime) * 0.08f;
	return (NMathF::cos(2.0f * TAU * normalizedTime) + 1.0f) * amplitude + 1.0f;
}

/**
 * @todo: Documentation
 */
void setNumberTag(P2DScreen* screen, u32 tag, int* valuePtr, int digit)
{
	P2DPane* pane = screen->search(tag, true);
	pane->setCallBack(new NumberPicCallBack<int>(pane, valuePtr, digit, false));
}

/**
 * @todo: Documentation
 */
void setTextColor(P2DTextBox* tbox, P2DPicture* pic)
{
	Colour white = tbox->getCharColor();
	Colour black = tbox->getGradColor();
	black.a      = 0;
	pic->setWhite(white);
	pic->setBlack(black);
}

/**
 * @todo: Documentation
 */
bool getStringCVS(char* outStr, immut char* csvText, s16 fieldIndex)
{
	s16 remainingChars = 512;
	while (fieldIndex > 0) {
		char currentChar = *csvText;
		if (!currentChar) {
			return true;
		}
		if (currentChar == ',' || currentChar == '\n') {
			fieldIndex--;
		}
		csvText++;
	}

	while (true) {
		char currentChar = *csvText;
		if (currentChar != 0 && currentChar != ',' && currentChar != '\n') {
			*outStr++ = currentChar;
			csvText++;
			remainingChars--;
			if (remainingChars < 0) {
				PRINT("文字列が%d文字を超えました。\n", 0); // 'the string exceeds %d characters.'
				return true;
			}
		} else {
			break;
		}
	};

	*outStr = 0;
	return false;
}

/**
 * @todo: Documentation
 */
PikaAlphaMgr::PikaAlphaMgr(P2DScreen* screen)
{
	mAlphaCount = 0;
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
		immut char* text = tbox->getString();
		tbox->hide();
		getStringCVS(str, text, 0);
		f32 val0 = atof(str);
		getStringCVS(str, text, 1);
		f32 val1 = atof(str);

		pic->printTagName(false);
		u8 cAlpha = tbox->getCharColor().a;
		u8 gAlpha = tbox->getGradColor().a;

		mTenmetuAlphas[mAlphaCount] = new setTenmetuAlpha(pic, val0, val1, cAlpha, gAlpha);

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
			mTenmetuAlphas[mAlphaCount]->setColorTab(j, &col1, &col2, val2);
		}
		mAlphaCount++;
	}
}

/**
 * @todo: Documentation
 */
void PikaAlphaMgr::start()
{
	mState = 0;
	for (int i = 0; i < mAlphaCount; i++) {
		mTenmetuAlphas[i]->start();
	}
}

/**
 * @todo: Documentation
 */
void PikaAlphaMgr::startFadeIn(f32 duration)
{
	mState = 1;
	for (int i = 0; i < mAlphaCount; i++) {
		mTenmetuAlphas[i]->startFadeIn(duration, 0.0f, 1.0f);
	}
}

/**
 * @todo: Documentation
 */
void PikaAlphaMgr::startFadeOut(f32 duration)
{
	mState = 2;
	for (int i = 0; i < mAlphaCount; i++) {
		mTenmetuAlphas[i]->startFadeOut(duration, 0.0f, 1.0f);
	}
}

/**
 * @todo: Documentation
 */
void PikaAlphaMgr::update()
{
	int i;
	switch (mState) {
	case 1:
		for (i = 0; i < mAlphaCount; i++) {
			if (mTenmetuAlphas[i]->update() == 1) {
				mState = 0;
			}
		}
		break;

	case 2:
		for (i = 0; i < mAlphaCount; i++) {
			if (mTenmetuAlphas[i]->update() == 0) {
				mState = -1;
			}
		}
		break;

	case 0:
		for (i = 0; i < mAlphaCount; i++) {
			mTenmetuAlphas[i]->update();
		}
		break;

	case -1:
		break;
	}
}

/**
 * @todo: Documentation
 */
setTenmetuAlpha::setTenmetuAlpha(P2DPicture* pic, f32 p2, f32 p3, u8 p4, u8 p5)
{
	mMode              = MODE_Stopped;
	mPic               = pic;
	mPeriod            = p2;
	mTimer             = p3;
	mMinAlpha          = p4;
	mMaxAlpha          = p5;
	mAlphaRange        = (mMaxAlpha - mMinAlpha);
	mColorCount        = 0;
	mCurrentColorIndex = 0;
	mColorTimer        = p3;
	mReferenceTime     = p3;
	mFadeTimer         = 0.0f;
	mFadeDuration      = 1.0f;
}

/**
 * @todo: Documentation
 */
setTenmetuAlpha::setTenmetuAlpha(P2DPicture* pic, f32 p2)
{
	mMode              = MODE_Stopped;
	mPic               = pic;
	mPeriod            = p2;
	mTimer             = 0.0f;
	mMinAlpha          = 0;
	mMaxAlpha          = 255;
	mAlphaRange        = (mMaxAlpha - mMinAlpha);
	mColorCount        = 0;
	mCurrentColorIndex = 0;
	mColorTimer        = 0.0f;
	mReferenceTime     = 0.0f;
	mFadeTimer         = 0.0f;
	mFadeDuration      = 1.0f;
}

/**
 * @todo: Documentation
 */
void setTenmetuAlpha::updateColor()
{
	if (mColorCount > 0) {
		Colour col1 = mPrimaryColors[mCurrentColorIndex];
		Colour col2 = mPrimaryColors[(mCurrentColorIndex + 1) % mColorCount];
		f32 t       = mColorTimer / mColorDurations[mCurrentColorIndex];

		if (t > 1.0f) {
			t = 1.0f;
		}

		f32 tComp = 1.0f - t;

		Colour targCol(col1.r * tComp + col2.r * t, col1.g * tComp + col2.g * t, col1.b * tComp + col2.b * t, col1.a * tComp + col2.a * t);
		mPic->setWhite(targCol);
		col1 = mSecondaryColors[mCurrentColorIndex];
		col2 = mSecondaryColors[(mCurrentColorIndex + 1) % mColorCount];
		t    = mColorTimer / mColorDurations[mCurrentColorIndex];
		if (t > 1.0f) {
			t = 1.0f;
		}

		tComp = 1.0f - t;

		targCol.set(col1.r * tComp + col2.r * t, col1.g * tComp + col2.g * t, col1.b * tComp + col2.b * t, 0);
		mPic->setBlack(targCol);

		mColorTimer += gsys->getFrameTime();
		if (mColorTimer > mColorDurations[mCurrentColorIndex]) {
			mColorTimer = 0.0f;
			mCurrentColorIndex++;
			if (mCurrentColorIndex >= mColorCount) {
				mCurrentColorIndex = 0;
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void setTenmetuAlpha::start()
{
	mCurrentColorIndex = 0;
	mTimer             = mReferenceTime;
	mColorTimer        = mReferenceTime;
	mMode              = MODE_Running;
}

/**
 * @todo: Documentation
 */
void setTenmetuAlpha::startFadeIn(f32 duration, f32 start, f32 end)
{
	if (mMode == MODE_Running) {
		return;
	}

	if (duration <= 0.0f) {
		duration = 0.01f;
	}

	mCurrentColorIndex = 0;
	mTimer             = mReferenceTime;
	mColorTimer        = mReferenceTime;
	mFadeDuration      = duration;
	mFadeTimer         = 0.0f;
	mFadeStart         = start;
	mFadeEnd           = end;
	mFadeRange         = end - start;
	mMode              = MODE_FadeIn;
}

/**
 * @todo: Documentation
 */
void setTenmetuAlpha::startFadeOut(f32 duration, f32 start, f32 end)
{
	if (mMode == MODE_Stopped) {
		return;
	}

	if (duration <= 0.0f) {
		duration = 0.01f;
	}

	mFadeDuration = duration;
	mFadeTimer    = 0.0f;
	mFadeStart    = start;
	mFadeEnd      = end;
	mFadeRange    = end - start;
	mMode         = MODE_FadeOut;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
void setTenmetuAlpha::calcAlpha(f32 maxAlpha)
{
	if (mPeriod > 0.0f) {
		mTimer += gsys->getFrameTime();
		if (mTimer > mPeriod) {
			mTimer -= mPeriod;
		}

		updateColor();
		f32 angle = TAU * mTimer / mPeriod;
		u8 alpha  = u8(mMinAlpha + int((sinf(angle) + 1.0f) * mAlphaRange / 2.0f));
		alpha     = alpha * maxAlpha;
		mPic->setAlpha(alpha);
	}
}

/**
 * @todo: Documentation
 */
setTenmetuAlpha::TenmetuMode setTenmetuAlpha::update()
{
	if (mMode == MODE_Stopped) {
		return mMode;
	}

	f32 t;
	switch (mMode) {
	case MODE_FadeIn:
		mFadeTimer += gsys->getFrameTime();
		t = mFadeTimer / mFadeDuration;
		if (t < 0.0f) {
			t = 0.0f;
		}
		if (t > 1.0f) {
			t     = 1.0f;
			mMode = MODE_Running;
		}

		calcAlpha(mFadeStart + mFadeRange * t);
		break;

	case MODE_FadeOut:
		mFadeTimer += gsys->getFrameTime();
		t = mFadeTimer / mFadeDuration;
		if (t < 0.0f) {
			t = 0.0f;
		}
		if (t > 1.0f) {
			t     = 1.0f;
			mMode = MODE_Stopped;
		}

		calcAlpha(mFadeEnd - mFadeRange * t);
		break;

	case MODE_Running:
		calcAlpha(1.0f);
		break;
	}

	return mMode;
}

/**
 * @todo: Documentation
 */
ogFadeMgr::ogFadeMgr(P2DPane* pane, u8 p2)
{
	mState        = STATUS_Idle;
	mPane         = pane;
	mFadeDuration = 1.0f;
	mFadeTimer    = 0.0f;
	mCurrentAlpha = 0.0f;
	mSourceAlpha  = 0.0f;
	mTargetAlpha  = p2;
	mPaneType     = mPane->getTypeID();
	setAlpha();
}

/**
 * @todo: Documentation
 */
void ogFadeMgr::start(ogFadeMgr::ogFadeStatusFlag state, f32 p2)
{
	if (p2 == 0.0f) {
		return;
	}
	mState        = state;
	mFadeDuration = p2;
	mFadeTimer    = 0.0f;
	switch (mState) {
	case STATUS_FadeIn:
		mCurrentAlpha = mSourceAlpha;
		break;

	case STATUS_FadeOut:
		mCurrentAlpha = mTargetAlpha;
		break;
	}

	setAlpha();
}

/**
 * @todo: Documentation
 */
void ogFadeMgr::setAlpha()
{
	switch (mPaneType) {
	case PANETYPE_Picture:
		P2DPicture* pic = (P2DPicture*)mPane;
		pic->setAlpha(mCurrentAlpha);
		break;

	case PANETYPE_TextBox:
		P2DTextBox* tbox = (P2DTextBox*)mPane;
		tbox->setAlpha(mCurrentAlpha);
		break;

	default:
		mPane->hide();
		break;
	}
}

/**
 * @todo: Documentation
 */
ogFadeMgr::ogFadeStatusFlag ogFadeMgr::update()
{
	if (mState == STATUS_Idle) {
		return mState;
	}

	mFadeTimer += gsys->getFrameTime();
	if (mFadeTimer > mFadeDuration) {
		mFadeTimer = mFadeDuration;
	}

	f32 t = mFadeTimer / mFadeDuration;
	switch (mState) {
	case STATUS_FadeIn:
		mCurrentAlpha = mSourceAlpha * (1.0f - t) + mTargetAlpha * t;
		break;

	case STATUS_FadeOut:
		mCurrentAlpha = mTargetAlpha * (1.0f - t) + mSourceAlpha * t;
		break;
	}

	setAlpha();

	if (mFadeTimer >= mFadeDuration) {
		mState = STATUS_Idle;
	}

	return mState;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
void movePicturePos(P2DPicture* alignPic, P2DPicture* movingPic)
{
	int x = alignPic->getPosH();
	int y = alignPic->getPosV();
	movingPic->move(x, y);
}

/**
 * @todo: Documentation
 */
ogTexAnimSubMgr::ogTexAnimSubMgr(P2DScreen* screen, P2DPicture* pic, P2DTextBox* tbox)
{
	char tmpStr[512];
	mTextureCount    = 0;
	mPicture         = pic;
	mTextBox         = tbox;
	immut char* text = mTextBox->getString();

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

		mTextures[i] = pane;
		if (getStringCVS(tmpStr, text, 2 * i + 1)) {
			break;
		}

		mDurations[i] = atof(tmpStr);
		mTextureCount++;
	}

	mCurrentIndex    = 0;
	mTimer           = 0.0f;
	mSpeedMultiplier = 1.0f;
	if (mTextureCount > 0) {
		mCurrentDuration = mDurations[mCurrentIndex];
		movePicturePos(mPicture, mTextures[mCurrentIndex]);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000108
 */
void ogTexAnimSubMgr::update()
{
	if (mTextureCount) {
		mTimer += gsys->getFrameTime() * mSpeedMultiplier;
		if (mTimer > mCurrentDuration) {
			mTextures[mCurrentIndex]->hide();
			mCurrentIndex++;
			if (mCurrentIndex >= mTextureCount) {
				mCurrentIndex = 0;
			}

			mTimer           = 0.0f;
			mCurrentDuration = mDurations[mCurrentIndex];
			movePicturePos(mPicture, mTextures[mCurrentIndex]);
			mTextures[mCurrentIndex]->show();
		}
	}
}

/**
 * @todo: Documentation
 */
ogTexAnimMgr::ogTexAnimMgr(P2DScreen* screen)
{
	char buf[8];
	mSubMgrCount = 0;
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
			mSubMgrCount++;
		}
	}
}

/**
 * @todo: Documentation
 */
void ogTexAnimMgr::update()
{
	for (int i = 0; i < mSubMgrCount; i++) {
		mSubMgrs[i]->update();
	}
}

/**
 * @todo: Documentation
 */
int getSpecialNumber(int idx)
{
	if (idx < 0 || idx > 99) {
		return -1;
	}

	return SpecialNumber[idx];
}

/**
 * @todo: Documentation
 */
void setSpecialNumber(int idx, int value)
{
	PRINT("setSpecialNumber()  @d%d = %d\n", idx, value);
	if (idx < 0 || idx > 99) {
		return;
	}

	SpecialNumber[idx] = value;
}

/**
 * @todo: Documentation
 */
void cnvSpecialNumber(char* str)
{
	const char* tmp = str;
	char* work      = wkstr;
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
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
#else
				if (c == 0) {
					break;
				}
#endif
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
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
#else
					tmp++;
#endif
				}
			} else if (b == 'd') {
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
#else
				if (c == 0) {
					break;
				}
#endif
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

/**
 * @todo: Documentation
 */
TypingTextMgr::TypingTextMgr(P2DTextBox* textBox)
{
	mTextBox = textBox;
	mTextPtr = textBox->getString();
	sprintf(mTextBuf, "");
	mState     = STATE_Stopped;
	mTypeTimer = 0.0f;
	mCharIndex = 0;

	textBox->hide();
	mCtrlTagMgr = new ogMsgCtrlTagMgr();
}

/**
 * @todo: Documentation
 */
void TypingTextMgr::start()
{
	STACK_PAD_VAR(1);

	mState     = STATE_Typing;
	mTypeTimer = 0.0f;
	mCharIndex = 0;
	sprintf(mTextBuf, "");
	mTextBox->show();
	mTextBox->setString(mTextBuf);
}

/**
 * @todo: Documentation
 */
ogMsgCtrlTagMgr::ogMsgCtrlTagMgr()
{
	P2DScreen* screen = new P2DScreen();
	screen->set("screen/blo/wait_char.blo", false, false, true);

	P2DTextBox* onesBox = (P2DTextBox*)screen->search('maru', true);
	P2DTextBox* tensBox = (P2DTextBox*)screen->search('ten', true);
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
#else
	P2DTextBox* hundredsBox = (P2DTextBox*)screen->search('han', true);
#endif

	strcpy(mOnesWaitChar, onesBox->getString());
	strcpy(mTensWaitChar, tensBox->getString());
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
#else
	strcpy(mHankakuWaitChars, hundredsBox->getString());
#endif
}

/**
 * @todo: Documentation
 */
bool ogMsgCtrlTagMgr::CheckCtrlTag(immut char* text, s16* indexPtr, f32* waitTimePtr)
{
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
	char ch;
	int charIndex      = *indexPtr;
	const char* cursor = &text[*indexPtr];
	ch                 = *cursor;
	*waitTimePtr       = 0.0f;
#else
	STACK_PAD_VAR(1);
	int charIndex      = *indexPtr;
	const char* cursor = &text[*indexPtr];
	char ch            = *cursor;
	*waitTimePtr       = 0.0f;
#endif

	if (ch == 0) {
		return true;
	}

	s16 nextIndex;
	if (strncmp(cursor, mOnesWaitChar, 2) == 0) {
		PRINT("Hit MARU !!\n");
		*waitTimePtr = 0.25f;
		nextIndex    = charIndex + 2;
	} else if (strncmp(cursor, mTensWaitChar, 2) == 0) {
		PRINT("Hit TEN !!\n");
		*waitTimePtr = 0.25f;
		nextIndex    = charIndex + 2;
	} else if (ch == 0x1B) { // esc character
		nextIndex       = charIndex + 1;
		const char* tag = text + nextIndex;
		if (strncmp(tag, "CC", 2) == 0 || strncmp(tag, "GC", 2) == 0 || strncmp(tag, "TM", 2) == 0 || strncmp(tag, "Z", 1) == 0
		    || strncmp(tag, "CA", 2) == 0 || strncmp(tag, "GA", 2) == 0 || strncmp(tag, "TB", 2) == 0 || strncmp(tag, "BS", 2) == 0
		    || strncmp(tag, "CU", 2) == 0 || strncmp(tag, "CD", 2) == 0 || strncmp(tag, "CL", 2) == 0 || strncmp(tag, "CR", 2) == 0
		    || strncmp(tag, "LU", 2) == 0 || strncmp(tag, "LD", 2) == 0 || strncmp(tag, "HM", 2) == 0 || strncmp(tag, "ST", 2) == 0
		    || strncmp(tag, "FX", 2) == 0 || strncmp(tag, "FY", 2) == 0 || strncmp(tag, "SH", 2) == 0 || strncmp(tag, "SV", 2) == 0
		    || strncmp(tag, "GM", 2) == 0) {
			if (strncmp(tag, "Z", 1) == 0) {
				nextIndex++;
			} else if (strncmp(tag, "TM", 2) == 0) {
				*waitTimePtr = 0.25f;
				nextIndex += 2;
			} else {
				const char* closingBracket = strstr(tag, "]");
				if (closingBracket) {
					int count = closingBracket - tag + 1;
					strncpy(workString, tag, count);
					workString[count] = 0;
					PRINT("SKIP '%s'\n", workString);
					nextIndex += count;
				} else {
					nextIndex += 2;
				}
			}
		} else {
			PRINT("Tag ERROR !!! (%s)\n", tag);
		}
	} else if (ch & 0x80) {
		nextIndex = charIndex + 2;
		SeSystem::playSysSe(SYSSE_TYPEWRITER);
	}
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
#else
	else if (strchr(mHankakuWaitChars, ch)) {
		PRINT("Hit HANKAKU WAIT!!\n");
		*waitTimePtr = 0.25f;
		SeSystem::playSysSe(SYSSE_TYPEWRITER);
		nextIndex = charIndex + 1;
	}
#endif
	else {
		nextIndex = charIndex + 1;
		SeSystem::playSysSe(SYSSE_TYPEWRITER);
	}

	*indexPtr = nextIndex;
	return false;
}

/**
 * @todo: Documentation
 */
void TypingTextMgr::update()
{
	if (mState == STATE_Stopped) {
		mTextBox->hide();
		return;
	}

	if (mState == STATE_Complete) {
		mTextBox->setString(mTextPtr);
		return;
	}

	mTypeTimer += gsys->getFrameTime();
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIJ01_01)
	if (mTypeTimer >= 0.04f) {
		mTypeTimer -= 0.04f;
#else
	if (mTypeTimer >= 0.029639998f) {
		mTypeTimer -= 0.029639998f;
#endif
		f32 a;
		if (mCtrlTagMgr->CheckCtrlTag(mTextPtr, &mCharIndex, &a)) {
			mState = STATE_Complete;
		}

		if (a > 0.0f) {
			mTypeTimer = -a;
		}
		if (mCharIndex > 1023) {
			mCharIndex = 1023;
		}
		strncpy(mTextBuf, mTextPtr, mCharIndex);
		mTextBuf[mCharIndex] = 0;
	}
}

/**
 * @todo: Documentation
 */
void cnvSpecialNumberHyphen(char* str)
{
	const char* tmp = str;
	char* work      = wkstr;
	int num         = 0;
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
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIJ01_01)
								buf[i] = '-';
#else
								buf[i] = '*';
#endif
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
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIJ01_01)
								buf[i] = '-';
#else
								buf[i] = '*';
#endif
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
