#ifndef _ZEN_OGMEMCHK_H
#define _ZEN_OGMEMCHK_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DScreen;
struct P2DPane;
struct P2DPicture;
struct P2DTextBox;

namespace zen {

struct ogNitakuMgr;
struct TypingTextMgr;
struct EffectMgr2D;
struct setTenmetuAlpha;
struct ogScrMakeDefaultMgr;
struct particleGenerator;

/**
 *
 * @note Size: 0x10C (0xF0 in USA demo).
 */
struct ogScrMemChkMgr {
public:
	/**
	 * @brief TODO
	 */
	enum MemChkStatus {
		Inactive = -1,
		Starting,
		WritingFormatMsg,
		DoFormatSelection,
		FormatConfirmation,
		DoYouFormat,
		Formatting,
		FormatSuccess,
		FormatFail,
		NoCard,
		NotACard,
		UnformattedCard,
		BrokenCard,
		CardFull,
		UnusableCard,
		FileNotMade,
		MakeDefaultFile,
		RepairFile,
		RepairSuccess,
		RepairFail,
		ExitFailure,
		ExitSuccess,
		Finished,
	};

	ogScrMemChkMgr();

	void draw(Graphics&);
	MemChkStatus update(Controller*);
	void start();
	void DebugStart(int);

private:
	void SetNitaku_Y_N();
	void SetNitaku_W_R();
	void SetNitaku_F_N();
	void StartSub();
	void StatusCheck();
	void setPCtex(TypingTextMgr*);
	void DispYesNo(bool);
	void DispAcup(bool);
	void MakeDefFileStart();
	void RepairFileStart();
	void FormatEffectStart();
	bool checkTypingAll();
	void checkErrNitaku(zen::ogNitakuMgr*, Controller*);
	void setNoCard();
	void setErrorMessage();

	bool mIsDebugMode;                       // _00
	int mDebugState;                         // _04
	s16 mDrawWaitCounter;                    // _08
	EffectMgr2D* mEfxMgr;                    // _0C
	particleGenerator* mEfxA;                // _10
	particleGenerator* mEfxB;                // _14
	ogScrMakeDefaultMgr* mMakeDefaultMgr;    // _18
	MemChkStatus mStatus;                    // _1C
	MemChkStatus mPrevStatusCheck;           // _20
	P2DScreen* mBlackScreen;                 // _24
	P2DPicture* mBlackPane;                  // _28
	P2DScreen* mMainScreen;                  // _2C
	TypingTextMgr* mActiveTextMgr;           // _30
	TypingTextMgr* mFormatConfirmTextMgr;    // _34
	TypingTextMgr* mFormattedTextMgr;        // _38
	TypingTextMgr* mCantFormatTextMgr;       // _3C
	TypingTextMgr* mFormattingTextMgr;       // _40
	TypingTextMgr* mNeedFormatTextMgr;       // _44
	TypingTextMgr* mDoFixUnformattedTextMgr; // _48
	TypingTextMgr* mRepairFileTextMgr;       // _4C
	TypingTextMgr* mRepairSuccessTextMgr;    // _50
	TypingTextMgr* mRepairFailTextMgr;       // _54
	TypingTextMgr* mNoCardTextMgr;           // _58
	TypingTextMgr* mCardFullTextMgr;         // _5C
	TypingTextMgr* mUnusableCardTextMgr;     // _60
	TypingTextMgr* mUnformattedCardTextMgr;  // _64
	TypingTextMgr* mBrokenCardTextMgr;       // _68
	TypingTextMgr* mNotACardTextMgr;         // _6C
	TypingTextMgr* mFileNotMadeTextMgr;      // _70
	P2DTextBox* mFormatConfirmTextBox;       // _74
	P2DTextBox* mFormattedTextBox;           // _78
	P2DTextBox* mCantFormatTextBox;          // _7C
	P2DTextBox* mFormattingTextBox;          // _80
	P2DTextBox* mNeedFormatTextBox;          // _84
	P2DTextBox* mDoFixUnformattedTextBox;    // _88
	P2DTextBox* mRepairFileTextBox;          // _8C
	P2DTextBox* mRepairSuccessTextBox;       // _90
	P2DTextBox* mRepairFailTextBox;          // _94
	P2DPane* mYesNoWindow;                   // _98
	P2DPane* mCapsulePane;                   // _9C
	setTenmetuAlpha* mAButtonAlphaMgr;       // _A0
	P2DPicture* mAButtonPane;                // _A4
	P2DPane* mFormatEffPane;                 // _A8
	P2DTextBox* mYesPane;                    // _AC
	P2DTextBox* mNoPane;                     // _B0
#if defined(VERSION_PIKIDEMO)                //
#else                                        //
	P2DTextBox* mYesPane2; // _B4
	P2DTextBox* mNoPane2;  // _B8
#endif                                       //
	setTenmetuAlpha* mCursorAlphaMgr;        // _BC
	P2DPicture* mCursorPane;                 // _C0
	f32 _UNUSEDC4;                           // _C4
	f32 mWaitTimer;                          // _C8
	int _CC;                                 // _CC
	int _D0;                                 // _D0
	ogNitakuMgr* mNitakuMgr;                 // _D4
#if defined(VERSION_PIKIDEMO)                //
#else                                        //
	char* mYesText;            // _D8
	char* mNoText;             // _DC
	char* mFormatText;         // _E0
	char* mContinueNoSaveText; // _E4
	char* mRetryText;          // _E8
#endif                                       //
	P2DTextBox* mNoCardTextBox;              // _EC
	P2DTextBox* mCardFullTextBox;            // _F0
	P2DTextBox* mUnusableCardTextBox;        // _F4
	P2DTextBox* mUnformattedCardTextBox;     // _F8
	P2DTextBox* mBrokenCardTextBox;          // _FC
	P2DTextBox* mNotACardTextBox;            // _100
	P2DTextBox* mFileNotMadeTextBox;         // _104
	int _108;                                // _108
};

} // namespace zen

#endif
