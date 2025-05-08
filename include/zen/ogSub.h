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
 *
 * @note Size: 0x198
 */
struct PikaAlphaMgr {
	PikaAlphaMgr(P2DScreen*);

	void start();
	void startFadeIn(f32);
	void startFadeOut(f32);
	void update();

	// TODO: members
	u8 _00[0x198]; // _00, unknown
};

/**
 * @brief TODO
 */
struct setTenmetuAlpha {

	/**
	 * @brief TODO
	 */
	enum TenmetuMode {
		// TODO: this
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

	// TODO: members
	int _00;
	P2DPicture* mPic; // _04
	u8 _08[0x124];    // _08
};

/**
 * @brief TODO
 */
struct ogFadeMgr {

	/**
	 * @brief TODO
	 */
	enum ogFadeStatusFlag {
		Status_1 = 1,
		Status_2 = 2,
		Status_3 = 3,
		// TODO: this
	};

	ogFadeMgr(P2DPane*, u8);

	void start(ogFadeStatusFlag, f32);
	void setAlpha();
	ogFadeStatusFlag update();

	u8 _00[0x20]; // _00
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
	u8 _00[0x194]; // _00, unknown
};

/**
 * @brief TODO
 */
struct ogTexAnimSubMgr {
	ogTexAnimSubMgr(P2DScreen*, P2DPicture*, P2DTextBox*);

	// unused/inlined:
	void update();

	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct ogMsgCtrlTagMgr {
	ogMsgCtrlTagMgr();

	void CheckCtrlTag(char*, s16*, f32*);

	u8 _00[0x18]; // _00, unknown
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

	// DLL inlines to do:
	void off();
	EnumPCTextStat check();

	int _00;                      // _00
	ogMsgCtrlTagMgr* mCtrlTagMgr; // _04
	P2DTextBox* mTextBox;         // _08
	char* mTextPtr;               // _0C
	char mTextBuf[0x400];         // _10
	f32 _410;                     // _410
	u16 _414;                     // _414
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
