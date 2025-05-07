#ifndef _ZEN_OGMESSAGE_H
#define _ZEN_OGMESSAGE_H

#include "types.h"
#include "P2D/Screen.h"

struct Controller;
struct Graphics;
struct P2DTextBox;

namespace zen {

struct TextInfoType {
	char* _00;
	u16 _04;
	s16 _06;
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
	void makePageInfo(char***);
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
	void setCursorXY(P2DTextBox* textBox) { }
	void setScale(f32 scale)
	{
		mScreen->setScale(scale);
		_54F8->setScale(scale);
	}
	void setLastPageAbutton(bool set) { _4DE = set; } // guessing which of these is which
	void setSolidMode(bool set) { _4E0 = set; }
	P2DScreen* getBaseScreenPtr() { return _54F8; }
	P2DScreen* getScreenPtr() { return mScreen; }
	bool checkDisp() { return _4DF; }
	s16 getTxtLineMax() { return _A59C; }
	TextInfoType* getPageInfo() { return (TextInfoType*)_1C[_4D0]; }
	void move(int x, int y)
	{
		mScreen->move(x, y);
		_54F8->move(x, y);
	}

	P2DScreen* mScreen;        // _00
	u8 _04[0x18];              // _04, unknown
	char** _1C[1];             // _1C, unsure of array size
	u8 _20[0x4D0 - 0x20];      // _20, unknown
	s16 _4D0;                  // _4D0
	u8 _4D2[0x4DC - 0x4D2];    // _4D2, unknown
	bool _4DC;                 // _4DC
	bool _4DD;                 // _4DD
	bool _4DE;                 // _4DE
	bool _4DF;                 // _4DF
	u8 _4E0;                   // _4E0
	u8 _4E1[0x54F8 - 0x4E1];   // _4E1, unknown
	P2DScreen* _54F8;          // _54F8
	u8 _54FC[0xA59C - 0x54FC]; // _54FC
	s16 _A59C;                 // _A59C
	u8 _A59E[0xA5F0 - 0xA59E]; // _A59E, unknown
};

} // namespace zen

#endif
