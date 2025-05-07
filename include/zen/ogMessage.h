#ifndef _ZEN_OGMESSAGE_H
#define _ZEN_OGMESSAGE_H

#include "types.h"
#include "P2D/Screen.h"

struct Controller;
struct Graphics;
struct P2DTextBox;
struct P2DPicture;
struct Font;

namespace zen {
struct ogMsgCtrlTagMgr;
struct setTenmetuAlpha;

struct TextInfoType {
	char* _00; // _00
	s16 _04;   // _04
	s16 _06;   // _06
};

/**
 * @brief TODO
 *
 * @note Size: 0xA5F0.
 */
struct ogScrMessageMgr {

	/**
	 * @brief TODO
	 */
	enum MessageStatus {
		// TODO: this
	};

	ogScrMessageMgr(char*);

	s16 SearchTopPage(int);
	void resetPage();
	void start(int);
	void setPage(int);
	void nextPage();
	void backPage();
	s16 makePageInfo(char***);
	void cnvSingleMulti(char*);
	void cnvButtonIcon(char*);
	void setPageInfoSub();
	void MakeAndSetPageInfo(char***);
	void dispAll();
	void fadeOut();
	MessageStatus update(Controller*);
	void draw(Graphics&);

	// unused/inlined:
	void setMessagePage(int);
	void ReadAllScreen();
	void setScreenAlpha(u8);

	// DLL inlines
	TextInfoType* getPageInfo() { return mPageInfos[mCurrPageNum]; }
	s16 getTxtLineMax() { return _A59C; }
	P2DScreen* getBaseScreenPtr() { return _54F8; } // these might be swapped?
	P2DScreen* getScreenPtr() { return mScreen; }

	void setLastPageAbutton(bool set) { _4DE = set; } // guessing which of these is which
	void setSolidMode(bool set) { _4E0 = set; }

	void setCursorXY(P2DTextBox* textBox) { }
	void setScale(f32 scale)
	{
		mScreen->setScale(scale);
		_54F8->setScale(scale);
	}

	bool checkDisp() { return _4DF; }

	void move(int x, int y)
	{
		mScreen->move(x, y);
		_54F8->move(x, y);
	}

	P2DScreen* mScreen;            // _00
	ogMsgCtrlTagMgr* mCtrlTagMgr;  // _04
	Font* mFont;                   // _08
	P2DPicture* _0C;               // _0C
	P2DPicture* _10;               // _10
	setTenmetuAlpha* _14;          // _14
	setTenmetuAlpha* _18;          // _18
	TextInfoType* mPageInfos[300]; // _1C, unsure of array size, make it less if necessary
	int _4CC;                      // _4CC
	s16 mCurrPageNum;              // _4D0
	f32 _4D4;                      // _4D4
	f32 _4D8;                      // _4D8
	bool _4DC;                     // _4DC
	bool _4DD;                     // _4DD
	bool _4DE;                     // _4DE
	bool _4DF;                     // _4DF
	u8 _4E0;                       // _4E0
	u16 _4E2;                      // _4E2
	u8 _4E4[0x4];                  // _4E4, unknown
	u16 _4E8;                      // _4E8, might be s16
	u16 _4EA;                      // _4EA, might be s16
	u16 _4EC;                      // _4EC, might be s16
	u16 _4EE;                      // _4EE, might be s16
	u8 _4F0[0x54F2 - 0x4F0];       // _4F0, unknown
	u16 _54F2;                     // _54F2, might be s16
	u8 _54F4;                      // _54F4
	P2DScreen* _54F8;              // _54F8
	u8 _54FC[0xA59C - 0x54FC];     // _54FC
	s16 _A59C;                     // _A59C
	char _A59E[12];                // _A59E
	char _A5AA[34];                // _A5AA, unknown size
	char* _A5CC;                   // _A5CC
	char* _A5D0;                   // _A5D0
	char* _A5D4;                   // _A5D4
	char* _A5D8;                   // _A5D8
	char* _A5DC;                   // _A5DC
	char* _A5E0;                   // _A5E0
	char* _A5E4;                   // _A5E4
	char* _A5E8;                   // _A5E8
	char* _A5EC;                   // _A5EC
};

} // namespace zen

#endif
