#ifndef _ZEN_DRAWCONTAINER_H
#define _ZEN_DRAWCONTAINER_H

#include "GlobalGameOptions.h"
#include "P2D/Pane.h"
#include "P2D/Picture.h"
#include "P2D/Screen.h"
#include "P2D/TextBox.h"
#include "SoundMgr.h"
#include "nlib/Math.h"
#include "sysNew.h"
#include "types.h"
#include "zen/DrawCommon.h"
#include "zen/Math.h"
#include "zen/TexAnim.h"
#include "zen/ZenController.h"
#include "zen/ogSub.h"
#include <stdio.h>

struct P2DPicture;
struct P2DPerspGraph;
struct P2DTextBox;
struct Graphics;
struct Texture;

namespace zen {

struct MessageMgr;
struct WindowPaneMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x1E0.
 */
struct DrawContainer {
public:
	/**
	 * @brief TODO
	 */
	enum containerType {
		COLOR_Blue   = Blue,
		COLOR_Red    = Red,
		COLOR_Yellow = Yellow,
	};

	/**
	 * @brief Container operation states for the transfer interface
	 */
	enum statusFlag {
		STATE_Wait      = 0, // Waiting state before interface appears
		STATE_Start     = 1, // Interface sliding in animation
		STATE_Operation = 2, // Active operation state - user can transfer Pikmin
		STATE_End       = 3, // Interface sliding out animation
	};

	DrawContainer();

	void start(containerType, int, int, int, int, int, int);
	void draw(Graphics&);
	bool update(int&);

	// unused/inlined:
	~DrawContainer();

	statusFlag getStatus() { return mState; }
	int getContainerPikiDisp() { return mContainerPikiNum; }
	int getMyPikiDisp() { return mSquadPikiNum; }

protected:
	void setDispParam();
	bool waitStatus();
	bool startStatus();
	bool operationStatus();
	bool endStatus();

	static const f32 waitFrame;
	static const f32 addPikiMax; // Technically public, but it's unused so idgaf.

	statusFlag mState;              // _00
	P2DScreen mScreen;              // _04
	P2DPerspGraph* mPerspGraph;     // _FC
	Controller* mController;        // _100
	ZenController mZenController;   // _104
	f32 mFrameTimer;                // _170
	containerType mColor;           // _174
	int mInitialContainerCount;     // _178
	int mContainerCapacity;         // _17C
	int mInitialSquadCount;         // _180
	int mSquadCapacity;             // _184
	int mSquadTotalCount;           // _188
	int mSquadTotalLimit;           // _18C
	f32 mTransferSpeed;             // _190
	int mTransferDelta;             // _194
	int mContainerPikiNum;          // _198
	int mSquadPikiNum;              // _19C
	int mDeltaPikiNum;              // _1A0
	WindowPaneMgr* mWindowPaneMgr;  // _1A4
	P2DPicture* mMarkerPicture;     // _1A8
	Vector2f mMarkerBasePosition;   // _1AC
	MessageMgr* mMessageMgr;        // _1B4
	Texture* mPikminTextures[3];    // _1B8
	Texture* mWindowTextures[3];    // _1C4
	Texture* mContainerTextures[3]; // _1D0
	bool mIsActive;                 // _1DC
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct ArrowBasicCallBack {
public:
	/**
	 * @brief Arrow display states based on Pikmin distribution
	 */
	enum arrowType {
		ARROW_Up   = 0, // Squad has Pikmin, container empty - show up arrow
		ARROW_Down = 1, // Container has Pikmin, squad empty - show down arrow
		ARROW_Both = 2, // Both squad and container have Pikmin - show both arrows
		ARROW_None = 3, // Neither squad nor container have Pikmin - hide arrows
	};

	ArrowBasicCallBack() { }
	ArrowBasicCallBack(P2DPane* pane, DrawContainer* container, f32 p3)
	    : mContainerScreen(container)
	    , mAnimationAngle(0.0f)
	    , mAnimationSpeed(p3)
	{
		mOriginalPosX = pane->getPosH();
		mOriginalPosY = pane->getPosV();
		mIsActive     = true;
		mArrowType    = ARROW_None;
	}

	arrowType judgeArrowType()
	{
		if (mContainerScreen->getStatus() == DrawContainer::STATE_Wait) {
			if (mContainerScreen->getContainerPikiDisp() > 0) {
				if (mContainerScreen->getMyPikiDisp() > 0) {
					mArrowType = ARROW_Both;
				} else {
					mArrowType = ARROW_Down;
				}
			} else {
				if (mContainerScreen->getMyPikiDisp() > 0) {
					mArrowType = ARROW_Up;
				} else {
					mArrowType = ARROW_None;
				}
			}
		}
		return mArrowType;
	}

	// DLL inlines:
	void active() { mIsActive = true; }
	void sleep() { mIsActive = false; }

	void update(P2DPicture* pic)
	{
		u8 alpha = pic->getAlpha();
		mAnimationAngle += mAnimationSpeed;
		if (mAnimationAngle < 0.0f) {
			mAnimationAngle += TAU;
		}
		if (mAnimationAngle > TAU) {
			mAnimationAngle -= TAU;
		}

		if (mIsActive) {
			if (alpha < 235) {
				alpha += 20;
			} else {
				alpha = 255;
			}
		} else if (alpha > 40) {
			alpha -= 40;
		} else {
			alpha = 0;
		}

		pic->setAlpha(alpha);
		pic->move(mOriginalPosX, int(NMathF::sin(mAnimationAngle) * 10.0f) + mOriginalPosY);
	}

protected:
	DrawContainer* mContainerScreen; // _00
	int mOriginalPosX;               // _04
	int mOriginalPosY;               // _08
	f32 mAnimationAngle;             // _0C
	f32 mAnimationSpeed;             // _10
	bool mIsActive;                  // _14
	arrowType mArrowType;            // _18
};

/**
 * @brief TODO
 */
struct ArrowCenterCallBack : public P2DPaneCallBack, public ArrowBasicCallBack {
public:
	ArrowCenterCallBack()
	    : P2DPaneCallBack(nullptr, PANETYPE_Pane)
	{
	}
	ArrowCenterCallBack(P2DPane* pane, DrawContainer* container, f32 p3)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	    , ArrowBasicCallBack(pane, container, p3)
	{
		P2DPicture* pic = (P2DPicture*)pane;
		// There is no file named "ys_u.bti" on the disc, but there is one named "ya_u.bti".
		pUpTex   = loadTexExp(TERNARY_BUGFIX("ya_u.bti", "ys_u.bti"), true, true);
		pDownTex = loadTexExp("ya_l.bti", true, true);
		judgeArrowType();
		setTexture(pic);

		// this is just to spawn a random cmpwi that doesn't show up in the DLL
		if (mArrowType == ARROW_None && mContainerScreen) {
			;
		}
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		P2DPicture* pic = (P2DPicture*)pane;
		setTexture(pic);
		update(pic);
		return true;
	}

	arrowType setTexture(P2DPicture* pane)
	{
		judgeArrowType();
		if (mArrowType == ARROW_None || mArrowType == ARROW_Both) {
			sleep();
		} else {
			active();
			if (mArrowType == ARROW_Up) {
				pane->setTexture(pUpTex, 0);
			} else {
				pane->setTexture(pDownTex, 0);
			}
		}

		return mArrowType;
	}

	// DLL inlines to do:
	void makeResident()
	{
		if (pUpTex) {
			pUpTex->makeResident();
		}
		if (pDownTex) {
			pDownTex->makeResident();
		}
	}

protected:
	static Texture* pDownTex;
	static Texture* pUpTex;

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	// _04-_20 = ArrowBasicCallBack
};

/**
 * @brief TODO
 */
struct ArrowLRCallBack : public P2DPaneCallBack, public ArrowBasicCallBack {
public:
	ArrowLRCallBack(P2DPane* pane, DrawContainer* container, f32 p3)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	    , ArrowBasicCallBack(pane, container, p3)
	{
		P2DPicture* pic = (P2DPicture*)pane;
		judgeArrowType();
		if (mArrowType != ARROW_Both) {
			pic->setAlpha(0);
		}
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		P2DPicture* pic = (P2DPicture*)pane;
		judgeArrowType();
		if (mArrowType == ARROW_Both) {
			active();
		} else {
			sleep();
		}
		update(pic);
		return true;
	}

protected:
	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	// _04-_20 = ArrowBasicCallBack
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct StickCallBack : public P2DPaneCallBack {
public:
	StickCallBack()
	    : P2DPaneCallBack(nullptr, PANETYPE_Pane)
	{
	}
	StickCallBack(P2DPane* pane, DrawContainer* container)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	{
		mContainerScreen = container;
		char buf[8];

		// DON'T LOOK AT MY STACK MANIPULATION CRIMES PLEASE.
		// CRIMES START
		DrawContainer* container2  = container;
		DrawContainer* container3  = container;
		DrawContainer* container4  = container;
		DrawContainer* container5  = container;
		DrawContainer* container6  = container;
		DrawContainer* container7  = container;
		DrawContainer* container8  = container;
		DrawContainer* container9  = container;
		DrawContainer* container10 = container;
		DrawContainer* container11 = container;
		DrawContainer* container12 = container;
		DrawContainer* container13 = container;
		DrawContainer* container14 = container;
		DrawContainer* container15 = container;
		DrawContainer* container16 = container;
		DrawContainer* container17 = container;
		DrawContainer* container18 = container;
		DrawContainer* container19 = container;
		DrawContainer* container20 = container;
		DrawContainer* container21 = container;
		DrawContainer* container22 = container;
		DrawContainer* container23 = container;
		DrawContainer* container24 = container;
		DrawContainer* container25 = container;
		DrawContainer* container26 = container;
		DrawContainer* container27 = container;
		DrawContainer* container28 = container;
		DrawContainer* container29 = container;
		DrawContainer* container30 = container;
		DrawContainer* container31 = container;
		DrawContainer* container32 = container;
		DrawContainer* container33 = container;
		DrawContainer* container34 = container;
		DrawContainer* container35 = container;
		DrawContainer* container36 = container;
		DrawContainer* container37 = container;
		DrawContainer* container38 = container;
		DrawContainer* container39 = container;
		DrawContainer* container40 = container;
		DrawContainer* container41 = container;
		DrawContainer* container42 = container;
		DrawContainer* container43 = container;
		DrawContainer* container44 = container;
		DrawContainer* container45 = container;
		DrawContainer* container46 = container;
		DrawContainer* container47 = container;
		DrawContainer* container48 = container;
		DrawContainer* container49 = container;
		DrawContainer* container50 = container;
		DrawContainer* container51 = container;
		DrawContainer* container52 = container;
		DrawContainer* container53 = container;
		DrawContainer* container54 = container;
		DrawContainer* container55 = container;
		DrawContainer* container56 = container;
		DrawContainer* container57 = container;
		DrawContainer* container58 = container;
		DrawContainer* container59 = container;
		DrawContainer* container60 = container;
		DrawContainer* container61 = container;
		DrawContainer* container62 = container;
		DrawContainer* container63 = container;
		// CRIMES END

		for (int i = 0; i < 21; i++) {
			sprintf(buf, "c_anim%02d.bti", i + 1);
			pTexTable[i] = loadTexExp(buf, true, true);
		}

		mLeftAnimation = new TexAnim(20);
		mLeftAnimation->setData(0, pTexTable[10], 0.2f);
		mLeftAnimation->setData(1, pTexTable[9], 0.05f);
		mLeftAnimation->setData(2, pTexTable[8], 0.05f);
		mLeftAnimation->setData(3, pTexTable[7], 0.05f);
		mLeftAnimation->setData(4, pTexTable[6], 0.05f);
		mLeftAnimation->setData(5, pTexTable[5], 0.05f);
		mLeftAnimation->setData(6, pTexTable[4], 0.05f);
		mLeftAnimation->setData(7, pTexTable[3], 0.05f);
		mLeftAnimation->setData(8, pTexTable[2], 0.05f);
		mLeftAnimation->setData(9, pTexTable[1], 0.05f);
		mLeftAnimation->setData(10, pTexTable[0], 0.3f);
		mLeftAnimation->setData(11, pTexTable[1], 0.025f);
		mLeftAnimation->setData(12, pTexTable[2], 0.025f);
		mLeftAnimation->setData(13, pTexTable[3], 0.025f);
		mLeftAnimation->setData(14, pTexTable[4], 0.025f);
		mLeftAnimation->setData(15, pTexTable[5], 0.025f);
		mLeftAnimation->setData(16, pTexTable[6], 0.025f);
		mLeftAnimation->setData(17, pTexTable[7], 0.025f);
		mLeftAnimation->setData(18, pTexTable[8], 0.025f);
		mLeftAnimation->setData(19, pTexTable[9], 0.025f);

		mRightAnimation = new TexAnim(20);
		mRightAnimation->setData(0, pTexTable[10], 0.2f);
		mRightAnimation->setData(1, pTexTable[11], 0.05f);
		mRightAnimation->setData(2, pTexTable[12], 0.05f);
		mRightAnimation->setData(3, pTexTable[13], 0.05f);
		mRightAnimation->setData(4, pTexTable[14], 0.05f);
		mRightAnimation->setData(5, pTexTable[15], 0.05f);
		mRightAnimation->setData(6, pTexTable[16], 0.05f);
		mRightAnimation->setData(7, pTexTable[17], 0.05f);
		mRightAnimation->setData(8, pTexTable[18], 0.05f);
		mRightAnimation->setData(9, pTexTable[19], 0.05f);
		mRightAnimation->setData(10, pTexTable[20], 0.3f);
		mRightAnimation->setData(11, pTexTable[19], 0.025f);
		mRightAnimation->setData(12, pTexTable[18], 0.025f);
		mRightAnimation->setData(13, pTexTable[17], 0.025f);
		mRightAnimation->setData(14, pTexTable[16], 0.025f);
		mRightAnimation->setData(15, pTexTable[15], 0.025f);
		mRightAnimation->setData(16, pTexTable[14], 0.025f);
		mRightAnimation->setData(17, pTexTable[13], 0.025f);
		mRightAnimation->setData(18, pTexTable[12], 0.025f);
		mRightAnimation->setData(19, pTexTable[11], 0.025f);

		mBothAnimation = new TexAnim(40);
		mBothAnimation->setData(0, pTexTable[10], 0.3f);
		mBothAnimation->setData(1, pTexTable[9], 0.05f);
		mBothAnimation->setData(2, pTexTable[8], 0.05f);
		mBothAnimation->setData(3, pTexTable[7], 0.05f);
		mBothAnimation->setData(4, pTexTable[6], 0.05f);
		mBothAnimation->setData(5, pTexTable[5], 0.05f);
		mBothAnimation->setData(6, pTexTable[4], 0.05f);
		mBothAnimation->setData(7, pTexTable[3], 0.05f);
		mBothAnimation->setData(8, pTexTable[2], 0.05f);
		mBothAnimation->setData(9, pTexTable[1], 0.05f);
		mBothAnimation->setData(10, pTexTable[0], 0.2f);
		mBothAnimation->setData(11, pTexTable[1], 0.025f);
		mBothAnimation->setData(12, pTexTable[2], 0.025f);
		mBothAnimation->setData(13, pTexTable[3], 0.025f);
		mBothAnimation->setData(14, pTexTable[4], 0.025f);
		mBothAnimation->setData(15, pTexTable[5], 0.025f);
		mBothAnimation->setData(16, pTexTable[6], 0.025f);
		mBothAnimation->setData(17, pTexTable[7], 0.025f);
		mBothAnimation->setData(18, pTexTable[8], 0.025f);
		mBothAnimation->setData(19, pTexTable[9], 0.025f);
		mBothAnimation->setData(20, pTexTable[10], 0.025f);
		mBothAnimation->setData(21, pTexTable[11], 0.025f);
		mBothAnimation->setData(22, pTexTable[12], 0.025f);
		mBothAnimation->setData(23, pTexTable[13], 0.025f);
		mBothAnimation->setData(24, pTexTable[14], 0.025f);
		mBothAnimation->setData(25, pTexTable[15], 0.025f);
		mBothAnimation->setData(26, pTexTable[16], 0.025f);
		mBothAnimation->setData(27, pTexTable[17], 0.025f);
		mBothAnimation->setData(28, pTexTable[18], 0.025f);
		mBothAnimation->setData(29, pTexTable[19], 0.025f);
		mBothAnimation->setData(30, pTexTable[20], 0.2f);
		mBothAnimation->setData(31, pTexTable[19], 0.05f);
		mBothAnimation->setData(32, pTexTable[18], 0.05f);
		mBothAnimation->setData(33, pTexTable[17], 0.05f);
		mBothAnimation->setData(34, pTexTable[16], 0.05f);
		mBothAnimation->setData(35, pTexTable[15], 0.05f);
		mBothAnimation->setData(36, pTexTable[14], 0.05f);
		mBothAnimation->setData(37, pTexTable[13], 0.05f);
		mBothAnimation->setData(38, pTexTable[12], 0.05f);
		mBothAnimation->setData(39, pTexTable[11], 0.05f);
		mCurrentAnimation = 0;
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		P2DPicture* pic = (P2DPicture*)pane;
		TexAnim* anim;
		Texture* tex;
		if (mContainerScreen->getContainerPikiDisp() > 0) {
			if (mContainerScreen->getMyPikiDisp() > 0) {
				anim = mBothAnimation;
			} else {
				anim = mRightAnimation;
			}
		} else {
			if (mContainerScreen->getMyPikiDisp() > 0) {
				anim = mLeftAnimation;
			} else {
				anim = nullptr;
			}
		}

		if (mCurrentAnimation) {
			tex = mCurrentAnimation->update();
			if (mCurrentAnimation != anim) {
				if (anim) {
					if (tex == anim->getTexPtr()) {
						mCurrentAnimation = anim;
					}
				} else {
					mCurrentAnimation = nullptr;
					tex               = pTexTable[10];
				}
			}
		} else {
			if (anim) {
				mCurrentAnimation = anim;
			}
			tex = pTexTable[10];
		}

		pic->setTexture(tex, 0);
		return true;
	}

	// DLL inlines to do:
	void makeResident()
	{
		for (int i = 0; i < 21; i++) {
			if (pTexTable[i]) {
				pTexTable[i]->makeResident();
			}
		}
	}

protected:
	static Texture* pTexTable[21];

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	TexAnim* mCurrentAnimation;      // _04
	TexAnim* mLeftAnimation;         // _08
	TexAnim* mRightAnimation;        // _0C
	TexAnim* mBothAnimation;         // _10
	DrawContainer* mContainerScreen; // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct MessageMgr {
public:
	/**
	 * @brief Message display types for container interface feedback
	 */
	enum messageFlag {
		MSG_NULL              = -1, // No message displayed
		MSG_BothHavePikmin    = 0,  // Both container and squad have Pikmin
		MSG_ContainerOnly     = 1,  // Only container has Pikmin
		MSG_SquadOnly         = 2,  // Only squad has Pikmin
		MSG_NeitherHave       = 3,  // Neither have Pikmin
		MSG_ContainerFull     = 4,  // Container at capacity
		MSG_SquadCapacityFull = 5,  // Squad at capacity limit
		MSG_SquadTotalFull    = 6,  // Squad at total limit
		MSG_NotEnoughInSquad  = 7,  // Not enough Pikmin in squad
		MSG_ContainerEmpty    = 8,  // Container is empty
		MSG_NothingToTransfer = 9,  // No Pikmin available to transfer
		MSG_WaitInput         = 10, // Waiting for stick input to continue
		MSG_COUNT,                  // 11
	};

	MessageMgr(P2DScreen& screen)
	{
		mMessageCount      = MSG_COUNT;
		mRedTextBoxes      = new P2DTextBox*[mMessageCount];
		mRedShadowBoxes    = new P2DTextBox*[mMessageCount];
		mBlueTextBoxes     = new P2DTextBox*[mMessageCount];
		mBlueShadowBoxes   = new P2DTextBox*[mMessageCount];
		mYellowTextBoxes   = new P2DTextBox*[mMessageCount];
		mYellowShadowBoxes = new P2DTextBox*[mMessageCount];
		mCurrentTime       = 0.0f;
		mDuration          = 0.0f;
		mMessage           = MSG_NULL;

		char buf[8];
		for (int i = 0; i < MSG_COUNT; i++) {
			sprintf(buf, "rm%02d", i);
			int tag1 = P2DPaneLibrary::makeTag(buf);
			sprintf(buf, "rs%02d", i);
			int tag2 = P2DPaneLibrary::makeTag(buf);
			setTextBox(DrawContainer::COLOR_Red, screen, i, tag1, tag2);

			sprintf(buf, "bm%02d", i);
			tag1 = P2DPaneLibrary::makeTag(buf);
			sprintf(buf, "bs%02d", i);
			tag2 = P2DPaneLibrary::makeTag(buf);
			setTextBox(DrawContainer::COLOR_Blue, screen, i, tag1, tag2);

			sprintf(buf, "ym%02d", i);
			tag1 = P2DPaneLibrary::makeTag(buf);
			sprintf(buf, "ys%02d", i);
			tag2 = P2DPaneLibrary::makeTag(buf);
			setTextBox(DrawContainer::COLOR_Yellow, screen, i, tag1, tag2);
		}

		init(DrawContainer::COLOR_Red);
	}

	// weak:
	void init(DrawContainer::containerType color)
	{
		setColorMode(color);
		setMessage(MSG_NULL, 0.0f);
		for (int i = 0; i < MSG_COUNT; i++) {
			mRedTextBoxes[i]->setAlpha(0);
			mRedShadowBoxes[i]->setAlpha(0);
			mBlueTextBoxes[i]->setAlpha(0);
			mBlueShadowBoxes[i]->setAlpha(0);
			mYellowTextBoxes[i]->setAlpha(0);
			mYellowShadowBoxes[i]->setAlpha(0);
		}
	}
	void setTextBox(DrawContainer::containerType color, P2DScreen& screen, int msg, int tag1, int tag2)
	{
		P2DPane* parent;

		P2DTextBox* tBox1 = (P2DTextBox*)screen.search(tag1, true);
		P2DTextBox* tBox2 = (P2DTextBox*)screen.search(tag2, true);

		parent = screen.search('pall', true);
		P2DPaneLibrary::changeParent(tBox2, parent);
		P2DPaneLibrary::changeParent(tBox1, parent);

		switch (color) {
		case DrawContainer::COLOR_Red:
		{
			mRedTextBoxes[msg]   = tBox1;
			mRedShadowBoxes[msg] = tBox2;
			break;
		}
		case DrawContainer::COLOR_Blue:
		{
			mBlueTextBoxes[msg]   = tBox1;
			mBlueShadowBoxes[msg] = tBox2;
			break;
		}
		case DrawContainer::COLOR_Yellow:
		{
			mYellowTextBoxes[msg]   = tBox1;
			mYellowShadowBoxes[msg] = tBox2;
			break;
		}
		}

		tBox1->hide();
		tBox1->setAlpha(0);
		tBox2->hide();
		tBox2->setAlpha(0);
	}
	void setMessage(messageFlag msg, f32 p2)
	{
		if (mMessage != msg) {
			switch (msg) {
			case MSG_ContainerFull:
			case MSG_SquadCapacityFull:
			case MSG_SquadTotalFull:
			case MSG_NotEnoughInSquad:
			case MSG_ContainerEmpty:
			case MSG_NothingToTransfer:
			{
				SeSystem::playSysSe(SYSSE_CMENU_ERROR);
				break;
			}
			}
		}
		mCurrentTime = 0.0f;
		mDuration    = p2;
		mMessage     = msg;

		if (msg != MSG_NULL) {
			switch (mColorMode) {
			case DrawContainer::COLOR_Red:
			{
				mRedTextBoxes[mMessage]->show();
				mRedShadowBoxes[mMessage]->show();
				break;
			}
			case DrawContainer::COLOR_Blue:
			{
				mBlueTextBoxes[mMessage]->show();
				mBlueShadowBoxes[mMessage]->show();
				break;
			}
			case DrawContainer::COLOR_Yellow:
			{
				mYellowTextBoxes[mMessage]->show();
				mYellowShadowBoxes[mMessage]->show();
				break;
			}
			}
		}
	}

	// DLL inlines:
	void setColorMode(DrawContainer::containerType color) { mColorMode = color; }

	// DLL inlines to do:
	void update(Controller* controller, int containerNum, int squadNum)
	{
		bool check = false;
		if (mDuration >= 0.0f) {
			mCurrentTime += gsys->getFrameTime();
			if (mCurrentTime > mDuration) {
				mCurrentTime = 0.0f;
				check        = true;
			}
		}

		if (mMessage == MSG_WaitInput && controller->keyDown(KBBTN_MSTICK_UP | KBBTN_MSTICK_DOWN)) {
			setMessage(MSG_NULL, 0.0f);
		}

		if (check) {
			switch (mMessage) {
			case MSG_NULL:
			case MSG_BothHavePikmin:
			case MSG_ContainerOnly:
			case MSG_SquadOnly:
			case MSG_NeitherHave:
			{
				if (mMessage == MSG_NULL) {
					if (containerNum > 0) {
						if (squadNum > 0) {
							setMessage(MSG_BothHavePikmin, 4.0f);
						} else {
							setMessage(MSG_ContainerOnly, 4.0f);
						}
					} else {
						if (squadNum > 0) {
							setMessage(MSG_SquadOnly, 4.0f);
						} else {
							setMessage(MSG_NeitherHave, -1.0f);
						}
					}
				} else {
					setMessage(MSG_WaitInput, -1.0f);
				}
				break;
			}
			default:
			{
				setMessage(MSG_NULL, 0.0f);
				break;
			}
			}
		}

		P2DTextBox** tBox1;
		P2DTextBox** tBox2;
		switch (mColorMode) {
		case DrawContainer::COLOR_Red:
		{
			tBox1 = mRedTextBoxes;
			tBox2 = mRedShadowBoxes;
			break;
		}
		case DrawContainer::COLOR_Blue:
		{
			tBox1 = mBlueTextBoxes;
			tBox2 = mBlueShadowBoxes;
			break;
		}
		case DrawContainer::COLOR_Yellow:
		{
			tBox1 = mYellowTextBoxes;
			tBox2 = mYellowShadowBoxes;
			break;
		}
		}

		for (int i = 0; i < mMessageCount; i++, tBox1++, tBox2++) {
			u8 alpha = (*tBox1)->getAlpha();
			if (i == mMessage) {
				(*tBox1)->show();
				(*tBox2)->show();
				if (alpha < 235) {
					alpha += 20;
				} else {
					alpha = 255;
				}
			} else if (alpha > 20) {
				alpha -= 20;
			} else {
				alpha = 0;
				(*tBox1)->hide();
				(*tBox2)->hide();
			}

			(*tBox1)->setAlpha(alpha);
			(*tBox2)->setAlpha(alpha);
		}
	}

protected:
	messageFlag mMessage;                    // _00
	int mMessageCount;                       // _04
	P2DTextBox** mRedTextBoxes;              // _08
	P2DTextBox** mRedShadowBoxes;            // _0C
	P2DTextBox** mBlueTextBoxes;             // _10
	P2DTextBox** mBlueShadowBoxes;           // _14
	P2DTextBox** mYellowTextBoxes;           // _18
	P2DTextBox** mYellowShadowBoxes;         // _1C
	f32 mCurrentTime;                        // _20
	f32 mDuration;                           // _24
	DrawContainer::containerType mColorMode; // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct WindowPaneMgr {
public:
	/**
	 * @brief Window pane animation modes for interface transitions
	 */
	enum modeFlag {
		MODE_Idle     = 0, // No movement
		MODE_SlideIn  = 1, // Sliding in from right
		MODE_Hold     = 2, // Holding position during operation
		MODE_SlideOut = 3, // Sliding out to left
	};

	WindowPaneMgr(P2DPane* pane)
	{
		mPane = pane;
		mBasePosition.set(mPane->getPosH(), mPane->getPosV(), 0.0f);
		init();
	}

	// DLL, but this needs to be above update or sdata gets screwy
	void init()
	{
		mPane->setScale(1.0f);
		mPane->move(mBasePosition.x + 640.0f, mBasePosition.y);
		mPane->setOffset(mPane->getWidth() >> 1, mPane->getHeight() >> 4);
		mPane->rotate(P2DROTATE_Z, 0.0f);
		mWeightPosition.set(mPane->getPosH(), mPane->getPosV() + weightPosLength, 0.0f);
		mVelocity.set(0.0f, 0.0f, 0.0f);
	}

	// weak:
	void update(modeFlag mode, f32 t, f32 tComp)
	{
		switch (mode) {
		case MODE_Idle:
		{
			break;
		}
		case MODE_SlideIn:
		{
			mPane->move(RoundOff(mBasePosition.x * t + (mBasePosition.x + 640.0f) * tComp),
			            RoundOff(mBasePosition.y * t + (mBasePosition.y - 0.0f) * tComp));
			break;
		}
		case MODE_SlideOut:
		{
			mPane->move(RoundOff(mBasePosition.x * tComp + (mBasePosition.x - 640.0f) * t),
			            RoundOff(mBasePosition.y * tComp + (mBasePosition.y - 0.0f) * t));
			break;
		}
		}

		Vector3f vec1;
		Vector3f vec2;

		mVelocity.y += weightPosGravity;
		vec2.set(mWeightPosition.x + mVelocity.x, mWeightPosition.y + mVelocity.y, 0.0f);
		vec1.x = vec2.x - mPane->getPosH();
		vec1.y = vec2.y - mPane->getPosV();

		if (vec1.length() != 0.0f) {
			vec1.normalize();
			vec1.multiply(weightPosLength);
			vec2.x = mPane->getPosH() + vec1.x;
			vec2.y = mPane->getPosV() + vec1.y;
			mVelocity.set(vec2.x - mWeightPosition.x, vec2.y - mWeightPosition.y, 0.0f);
			mWeightPosition = vec2;
			mPane->rotate(P2DROTATE_Z, NMathF::atan2(-vec1.y, -vec1.x) + HALF_PI);
		}
	}

	static const f32 weightPosGravity;
	static const f32 weightPosLength;

protected:
	P2DPane* mPane;           // _00
	Vector3f mBasePosition;   // _04
	Vector3f mWeightPosition; // _10
	Vector3f mVelocity;       // _1C
};

} // namespace zen

extern zen::DrawContainer* containerWindow;

#endif
