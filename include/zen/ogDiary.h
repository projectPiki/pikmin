#ifndef _ZEN_OGDIARY_H
#define _ZEN_OGDIARY_H

#include "types.h"
#include "zen/ogMessage.h"
#include "zen/SpectrumCursorMgr.h"

struct Controller;
struct Graphics;
struct P2DTextBox;
struct P2DPane;
struct P2DScreen;
struct P2DPicture;
struct Font;

namespace zen {

struct ZenController;
struct EffectMgr2D;
struct setTenmetuAlpha;

/**
 * @brief TODO
 */
struct ogScrDiaryMgr {

	/**
	 * @brief TODO
	 */
	enum DiaryStatus {
		Status_Null = -1,
		Status_0    = 0,
		// TODO: this
	};

	ogScrDiaryMgr();

	DiaryStatus update(Controller*);
	void draw(Graphics&);
	void start(s16, s16);
	void typePage();
	bool nextPage();
	void backPage();
	void exit();

	// unused/inlined:
	void setDiarySpecialNumber(s16);
	void setCursorXY(P2DTextBox*);
	void updateDiary(Controller*);

	void setScale(f32 scale) { mMesgMgr->setScale(scale); }
	ogScrMessageMgr* getScrMsgMgr() { return mMesgMgr; }

	// TODO: members
	DiaryStatus mStatus;        // _00
	ogScrMessageMgr* mMesgMgr;  // _04
	int _08;                    // _08
	int _0C;                    // _0C
	ZenController* mController; // _10
	Font* mFont;                // _14
	P2DPane* mPaneCapu;         // _18
	int _1C;                    // _1C
	int _20;                    // _20
	int _24;                    // _24
};

/**
 * @brief TODO
 */
struct ogDrawDiary {

	/**
	 * @brief TODO
	 */
	enum DiaryStatus {
		Status_0 = 0,
		Status_1 = 1,
		Status_2 = 2,
		Status_3 = 3,
		// TODO: this
	};

	ogDrawDiary();

	void open(f32, f32, s16);
	DiaryStatus update(Controller*);

	// unused/inlined:
	void start();
	void setOffset();
	void draw(Graphics&);

	// TODO: members
	ogScrDiaryMgr* mDiaryMgr; // _00
	EffectMgr2D* mEfxMgr;     // _04
	DiaryStatus mStatus;      // _08
	f32 mScreenScale;         // _0C
	P2DScreen* mScreen;       // _10
	f32 _14;                  // _14
	f32 _18;                  // _18
	f32 _1C;                  // _1C
	f32 _20;                  // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x2F0.
 */
struct ogDrawSelectDiary {

	/**
	 * @brief TODO
	 */
	enum SelectDiaryStatus {
		SELECT_NULL = -1,
		SELECT_0    = 0,
		SELECT_1    = 1,
		SELECT_2    = 2,
		SELECT_3    = 3,
		SELECT_4    = 4,
	};

	ogDrawSelectDiary();

	void start();
	void setCursorAlpha();
	bool MoveCursor();
	SelectDiaryStatus update(Controller*);
	void draw(Graphics&);

	int getOpenX();
	int getOpenY();

	SelectDiaryStatus mStatus;  // _00
	P2DScreen* mScreen;         // _04
	SpectrumCursorMgr _08;      // _08
	SpectrumCursorMgr _38;      // _38
	P2DPane* _68[30];           // _68
	P2DPane* _E0[30];           // _E0
	P2DPane* _168[30];          // _168
	P2DPane* _1D0[30];          // _1D0
	P2DPicture* _248[30];       // _248
	int _2C0;                   // _2C0
	P2DScreen* _2C4;            // _2C4
	P2DPicture* _2C8;           // _2C8
	P2DPicture* _2CC;           // _2CC
	setTenmetuAlpha* _2D0;      // _2D0
	ogDrawDiary* _2D4;          // _2D4
	int _2D8;                   // _2D8
	ZenController* mController; // _2DC
	s16 _2E0;                   // _2E0
	s16 _2E2;                   // _2E2
	s16 _2E4;                   // _2E4
	u16 _2E6;                   // _2E6
	s16 mDay;                   // _2E8
	f32 _2EC;                   // _2EC
};

} // namespace zen

#endif
