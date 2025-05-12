#ifndef _ZEN_OGSUB_H
#define _ZEN_OGSUB_H

#include "types.h"
#include "P2D/Picture.h"
#include "P2D/TextBox.h"

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

	/**
	 * @brief TODO
	 */
	enum TenmetuMode {
		MODE_Unk0 = 0,
		MODE_Unk1 = 1,
		MODE_Unk2 = 2,
		MODE_Unk3 = 3,
	};

	setTenmetuAlpha(P2DPicture*, f32, f32, u8, u8);
	setTenmetuAlpha(P2DPicture*, f32);

	void updateColor();
	void start();
	void startFadeIn(f32, f32, f32);
	void startFadeOut(f32, f32, f32);
	TenmetuMode update();

	void update(P2DPicture* pic)
	{
		mPic = pic;
		update();
	}

	// unused/inlined:
	void calcAlpha(f32);

	// DLL inlines to do:
	void setColorTab(u16 p1, Colour* p2, Colour* p3, f32 p4)
	{
		if (p1 < 20) {
			_30[p1] = *p2;
			_80[p1] = *p3;
			_D0[p1] = p4;
			_128    = p1 + 1;
		}
	}

	TenmetuMode mMode; // _00
	P2DPicture* mPic;  // _04
	f32 _08;           // _08
	f32 _0C;           // _0C
	f32 _10;           // _10
	f32 _14;           // _14
	f32 _18;           // _18
	u8 _1C;            // _1C
	u8 _1D;            // _1D
	f32 _20;           // _20
	f32 _24;           // _24
	f32 _28;           // _28
	u8 _2C[0x4];       // _2C, unknown
	Colour _30[20];    // _30
	Colour _80[20];    // _80
	f32 _D0[20];       // _D0
	f32 _120;          // _120
	f32 _124;          // _124
	s16 _128;          // _128
	s16 _12A;          // _12A
};

/**
 * @brief TODO
 *
 * @note Size: 0x198
 */
struct PikaAlphaMgr {
	PikaAlphaMgr(P2DScreen*);

	void start();
	void startFadeIn(f32);
	void startFadeOut(f32);
	void update();

	int mState;                           // _00
	s16 _04;                              // _04
	setTenmetuAlpha* mTenmetuAlphas[100]; // _08
};

/**
 * @brief TODO
 */
struct ogFadeMgr {

	/**
	 * @brief TODO
	 */
	enum ogFadeStatusFlag {
		Status_0 = 0,
		Status_1 = 1,
		Status_2 = 2,
		Status_3 = 3,
		// TODO: this
	};

	ogFadeMgr(P2DPane*, u8);

	void start(ogFadeStatusFlag, f32);
	void setAlpha();
	ogFadeStatusFlag update();

	ogFadeStatusFlag mState; // _00, unknown
	P2DPane* mPane;          // _04
	u16 mPaneType;           // _08
	f32 _0C;                 // _0C
	f32 _10;                 // _10
	f32 _14;                 // _14
	f32 _18;                 // _18
	f32 _1C;                 // _1C
};

/**
 * @brief TODO
 */
struct ogTexAnimSubMgr {
	ogTexAnimSubMgr(P2DScreen*, P2DPicture*, P2DTextBox*);

	// unused/inlined:
	void update();

	P2DPicture* mPicture;  // _00
	P2DTextBox* mTextBox;  // _04
	f32 _08;               // _08
	f32 _0C;               // _0C
	f32 _10;               // _10
	s16 _14;               // _14
	s16 _16;               // _16
	f32 _18[100];          // _18
	P2DPicture* _1A8[100]; // _1A8
};

/**
 * @brief TODO
 *
 * @note Size: 0x194.
 */
struct ogTexAnimMgr {
	ogTexAnimMgr(P2DScreen*);

	void update();

	// TODO: members
	int _00; // _00
	ogTexAnimSubMgr* mSubMgrs[100];
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct ogMsgCtrlTagMgr {
	ogMsgCtrlTagMgr();

	bool CheckCtrlTag(char*, s16*, f32*);

	char _00[8]; // _00
	char _08[8]; // _08
	char _10[8]; // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x418.
 */
struct TypingTextMgr {
	enum EnumPCTextStat {
		// TODO: this
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
		_00 = 0;
	}

	// DLL inlines to do:
	EnumPCTextStat check() { return (EnumPCTextStat)_00; };

	int _00;                      // _00
	ogMsgCtrlTagMgr* mCtrlTagMgr; // _04
	P2DTextBox* mTextBox;         // _08
	char* mTextPtr;               // _0C
	char mTextBuf[0x400];         // _10
	f32 _410;                     // _410
	s16 _414;                     // _414
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
