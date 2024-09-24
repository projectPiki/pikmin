#ifndef _ZEN_OGSUB_H
#define _ZEN_OGSUB_H

#include "types.h"

struct Matrix3f;
struct P2DPane;
struct P2DPicture;
struct P2DScreen;
struct P2DTextBox;
struct Vector3f;

namespace zen {

/**
 * @brief TODO
 */
struct PikaAlphaMgr {
	PikaAlphaMgr(P2DScreen*);

	void start();
	void startFadeIn(f32);
	void startFadeOut(f32);
	void update();

	// TODO: members
};

/**
 * @brief TODO
 */
struct setTenmetuAlpha {
	setTenmetuAlpha(P2DPicture*, f32, f32, u8, u8);
	setTenmetuAlpha(P2DPicture*, f32);

	void updateColor();
	void start();
	void startFadeIn(f32, f32, f32);
	void startFadeOut(f32, f32, f32);
	void update();

	// unused/inlined:
	void calcAlpha(f32);

	// TODO: members
};

/**
 * @brief TODO
 */
struct ogFadeMgr {

	/**
	 * @brief TODO
	 */
	enum ogFadeStatusFlag {

	};

	ogFadeMgr(P2DPane*, u8);

	void start(ogFadeStatusFlag, f32);
	void setAlpha();
	void update();
};

/**
 * @brief TODO
 */
struct ogTexAnimMgr {
	ogTexAnimMgr(P2DScreen*);

	void update();

	// TODO: members
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
 */
struct TypingTextMgr {
	TypingTextMgr(P2DTextBox*);

	void start();
	void update();

	// TODO: members
};

/**
 * @brief TODO
 */
struct ogMsgCtrlTagMgr {
	ogMsgCtrlTagMgr();

	void CheckCtrlTag(char*, s16*, f32*);

	// TODO: members
};

// global utility functions
void ogCheckInsCard();
void calcPuruPuruScale(f32);
void setNumberTag(P2DScreen*, u32, int*, int);
void setTextColor(P2DTextBox*, P2DPicture*);
void getStringCVS(char*, char*, s16);
void getSpecialNumber(int);
void setSpecialNumber(int, int);
void cnvSpecialNumber(char*);
void cnvSpecialNumberHyphen(char*);
void getDistPointAndLine(Vector3f, Vector3f, Vector3f, f32&);
void makeRotMatrix(Vector3f&, Matrix3f&);
void makePathName(const char*, const char*, char*);
void loadTexExp(const char*, bool, bool);

// unused/inlined globals:
void movePicturePos(P2DPicture*, P2DPicture*);

} // namespace zen

#endif
