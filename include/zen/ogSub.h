#ifndef _ZEN_OGSUB_H
#define _ZEN_OGSUB_H

#include "P2D/Picture.h"
#include "P2D/TextBox.h"
#include "VersionGroups.h"
#include "types.h"

struct Matrix3f;
struct P2DPane;
struct P2DPicture;
struct P2DScreen;
struct P2DTextBox;
struct Vector3f;
struct Texture;

namespace zen {

/**
 * @brief TODO
 */
struct setTenmetuAlpha {
public:
	/**
	 * @brief Animation mode states for tenmetu alpha effects
	 */
	enum TenmetuMode {
		MODE_Stopped = 0, // Animation is stopped
		MODE_Running = 1, // Animation is running normally
		MODE_FadeIn  = 2, // Animation is fading in
		MODE_FadeOut = 3, // Animation is fading out
	};

	void update(P2DPicture* pic)
	{
		mPic = pic;
		update();
	}

	setTenmetuAlpha(P2DPicture*, f32, f32, u8, u8);
	setTenmetuAlpha(P2DPicture*, f32);

	TenmetuMode update();
	void start();
	void startFadeIn(f32, f32, f32);
	void startFadeOut(f32, f32, f32);

	void setColorTab(u16 p1, Colour* p2, Colour* p3, f32 p4)
	{
		if (p1 < 20) {
			mPrimaryColors[p1]   = *p2;
			mSecondaryColors[p1] = *p3;
			mColorDurations[p1]  = p4;
			mColorCount          = p1 + 1;
		}
	}

private:
	void updateColor();
	void calcAlpha(f32);

	TenmetuMode mMode;           // _00
	P2DPicture* mPic;            // _04
	f32 mPeriod;                 // _08
	f32 mTimer;                  // _0C
	f32 mFadeTimer;              // _10
	f32 mFadeDuration;           // _14
	f32 mAlphaRange;             // _18
	u8 mMinAlpha;                // _1C
	u8 mMaxAlpha;                // _1D
	f32 mFadeRange;              // _20
	f32 mFadeStart;              // _24
	f32 mFadeEnd;                // _28
	u8 _UNUSED2C[0x4];           // _2C, unknown
	Colour mPrimaryColors[20];   // _30
	Colour mSecondaryColors[20]; // _80
	f32 mColorDurations[20];     // _D0
	f32 mColorTimer;             // _120
	f32 mReferenceTime;          // _124
	s16 mColorCount;             // _128
	s16 mCurrentColorIndex;      // _12A
};

/**
 * @brief TODO
 *
 * @note Size: 0x198
 */
struct PikaAlphaMgr {
public:
	PikaAlphaMgr(P2DScreen*);

	void start();
	void startFadeIn(f32);
	void startFadeOut(f32);
	void update();

private:
	int mState;                           // _00
	s16 mAlphaCount;                      // _04
	setTenmetuAlpha* mTenmetuAlphas[100]; // _08
};

/**
 * @brief TODO
 */
struct ogFadeMgr {
public:
	/**
	 * @brief Fade manager status flags
	 */
	enum ogFadeStatusFlag {
		STATUS_Idle    = 0, // No fade operation active
		STATUS_FadeIn  = 1, // Fade in operation
		STATUS_FadeOut = 2, // Fade out operation
	};

	ogFadeMgr(P2DPane*, u8);

	void start(ogFadeStatusFlag, f32);
	ogFadeStatusFlag update();

private:
	void setAlpha();

	ogFadeStatusFlag mState; // _00, unknown
	P2DPane* mPane;          // _04
	u16 mPaneType;           // _08
	f32 mFadeDuration;       // _0C
	f32 mFadeTimer;          // _10
	f32 mCurrentAlpha;       // _14
	f32 mSourceAlpha;        // _18
	f32 mTargetAlpha;        // _1C
};

/**
 * @brief TODO
 */
struct ogTexAnimSubMgr {
public:
	ogTexAnimSubMgr(P2DScreen*, P2DPicture*, P2DTextBox*);

	// unused/inlined:
	void update();

private:
	P2DPicture* mPicture;       // _00
	P2DTextBox* mTextBox;       // _04
	f32 mCurrentDuration;       // _08
	f32 mTimer;                 // _0C
	f32 mSpeedMultiplier;       // _10
	s16 mTextureCount;          // _14
	s16 mCurrentIndex;          // _16
	f32 mDurations[100];        // _18
	P2DPicture* mTextures[100]; // _1A8
};

/**
 * @brief TODO
 *
 * @note Size: 0x194.
 */
struct ogTexAnimMgr {
public:
	ogTexAnimMgr(P2DScreen*);

	void update();

private:
	int mSubMgrCount;               // _00
	ogTexAnimSubMgr* mSubMgrs[100]; // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x18 (0x10 in USA demo).
 */
struct ogMsgCtrlTagMgr {
public:
	ogMsgCtrlTagMgr();

	bool CheckCtrlTag(char*, s16*, f32*);

private:
	char mOnesWaitChar[8];    // _00
	char mTensWaitChar[8];    // _08
#if defined(VERSION_PIKIDEMO) //
#else                         //
	char mHankakuWaitChars[8]; // _10
#endif                        //
};

/**
 * @brief TODO
 *
 * @note Size: 0x418.
 */
struct TypingTextMgr {
public:
	/**
	 * @brief Typing text manager states
	 */
	enum EnumPCTextStat {
		STATE_Stopped  = 0, // Text display is stopped
		STATE_Typing   = 1, // Text is being typed
		STATE_Complete = 2, // Text typing is complete
	};

	TypingTextMgr(P2DTextBox*);

	void start();
	void update();

	void transCursor(P2DPicture* cursor)
	{
		int x = mTextBox->getPosH() + mTextBox->getCursorX();
		int y = mTextBox->getPosV() + mTextBox->getCursorY() - 24;
		cursor->move(x, y);
	}

	void off()
	{
		mTextBox->hide();
		mState = STATE_Stopped;
	}

	// DLL inlines to do:
	EnumPCTextStat check() { return mState; };

private:
	EnumPCTextStat mState;        // _00
	ogMsgCtrlTagMgr* mCtrlTagMgr; // _04
	P2DTextBox* mTextBox;         // _08
	char* mTextPtr;               // _0C
	char mTextBuf[0x400];         // _10
	f32 mTypeTimer;               // _410
	s16 mCharIndex;               // _414
};

// global utility functions
bool ogCheckInsCard();
f32 calcPuruPuruScale(f32);
int getSpecialNumber(int);
void cnvSpecialNumber(char*);
void cnvSpecialNumberHyphen(char*);
bool getStringCVS(char*, char*, short);
::Texture* loadTexExp(const char*, bool, bool);
void makePathName(const char*, const char*, char*);
void makeRotMatrix(Vector3f&, Matrix3f&);
void setNumberTag(P2DScreen*, u32, int*, int);
void setOffsetSub(P2DPicture*);
void setSpecialNumber(int, int);
void setTextColor(P2DTextBox*, P2DPicture*);

// unused/inlined globals:
void movePicturePos(P2DPicture*, P2DPicture*);

} // namespace zen

#endif
