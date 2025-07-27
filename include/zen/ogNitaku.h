#ifndef _ZEN_OGNITAKU_H
#define _ZEN_OGNITAKU_H

#include "Colour.h"
#include "types.h"
#include "zen/SpectrumCursorMgr.h"

struct Controller;
struct Graphics;
struct P2DScreen;
struct P2DTextBox;

namespace zen {

struct TextColorCallBack;

/**
 * @brief TODO
 */
struct ogNitakuMgr {
public:
	/**
	 * @brief TODO
	 */
	enum NitakuStatus {
		Status_0    = 0,
		Status_1    = 1,
		Exiting     = 2,
		Status_3    = 3,
		Status_4    = 4,
		ExitSuccess = 5,
		ExitFailure = 6,
		// TODO: this
	};

	ogNitakuMgr(P2DScreen*, P2DTextBox*, P2DTextBox*, P2DTextBox*, bool, bool);

	void start();
	NitakuStatus update(Controller*);
	void stop();

private:
	void MoveCursorYes(f32);
	void MoveCursorNo(f32);
	void InitCursor();
	void cursorEnable(f32);
	void cursorDisable(f32);

	NitakuStatus mStatus;              // _00
	NitakuStatus mStatus2;             // _04
	P2DScreen* mScreen;                // _08
	bool mDoStartYes;                  // _0C
	bool mCanCancel;                   // _0D
	SpectrumCursorMgr mLeftCursorMgr;  // _10
	f32 _40;                           // _40
	f32 _44;                           // _44
	f32 _48;                           // _48
	f32 _4C;                           // _4C
	SpectrumCursorMgr mRightCursorMgr; // _50
	f32 _80;                           // _80
	f32 _84;                           // _84
	f32 _88;                           // _88
	f32 _8C;                           // _8C
	bool mIsYes;                       // _90
	P2DTextBox* mTextBoxA;             // _94
	TextColorCallBack* mMesgColorA;    // _98
	P2DTextBox* mTextBoxB;             // _9C
	TextColorCallBack* mMesgColorB;    // _A0
	Colour _A4;                        // _A4
	Colour _A8;                        // _A8
	Colour _AC;                        // _AC
	Colour _B0;                        // _B0
	int _B4;                           // _B4
	P2DPane* mRootPane;                // _B8
	f32 mWaitTimer;                    // _BC
	bool _C0;                          // _C0
};

} // namespace zen

#endif
