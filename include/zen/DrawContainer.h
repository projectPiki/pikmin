#ifndef _ZEN_DRAWCONTAINER_H
#define _ZEN_DRAWCONTAINER_H

#include "types.h"
#include "P2D/Pane.h"
#include "P2D/Screen.h"
#include "P2D/TextBox.h"
#include "P2D/Picture.h"
#include "zen/ZenController.h"
#include "zen/DrawCommon.h"
#include "zen/TexAnim.h"
#include "zen/Math.h"
#include "zen/ogSub.h"
#include "stl/stdio.h"
#include "nlib/Math.h"
#include "SoundMgr.h"
#include "sysNew.h"

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

	/**
	 * @brief TODO
	 */
	enum containerType {
		COLOR_Blue   = 0, // probably blue?
		COLOR_Red    = 1, // probably red?
		COLOR_Yellow = 2, // probably yellow?
	};

	/**
	 * @brief TODO
	 */
	enum statusFlag {
		STATE_Wait  = 0,
		STATE_Start = 1,
		STATE_Unk2  = 2,
		STATE_Unk3  = 3,
	};

	DrawContainer();

	void start(containerType, int, int, int, int, int, int);
	void draw(Graphics&);
	void setDispParam();
	bool operationStatus();
	bool update(int&);

	// unused/inlined:
	~DrawContainer();
	bool waitStatus();
	bool startStatus();
	bool endStatus();

	statusFlag getStatus() { return mState; }
	int getContainerPikiDisp() { return mContainerPikiNum; }
	int getMyPikiDisp() { return mSquadPikiNum; }

	static const f32 waitFrame;
	static const f32 addPikiMax;

	statusFlag mState;             // _00
	P2DScreen mScreen;             // _04
	P2DPerspGraph* mPerspGraph;    // _FC
	Controller* mController;       // _100
	ZenController mZenController;  // _104
	f32 _170;                      // _170
	containerType mColor;          // _174
	int _178;                      // _178
	int _17C;                      // _17C
	int _180;                      // _180
	int _184;                      // _184
	int _188;                      // _188
	int _18C;                      // _18C
	f32 _190;                      // _190
	int _194;                      // _194
	int mContainerPikiNum;         // _198
	int mSquadPikiNum;             // _19C
	int mDeltaPikiNum;             // _1A0
	WindowPaneMgr* mWindowPaneMgr; // _1A4
	P2DPicture* _1A8;              // _1A8
	Vector2f _1AC;                 // _1AC
	MessageMgr* mMessageMgr;       // _1B4
	Texture* _1B8[3];              // _1B8
	Texture* _1C4[3];              // _1C4
	Texture* _1D0[3];              // _1D0
	u8 _1DC;                       // _1DC
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct ArrowBasicCallBack {

	/**
	 * @brief TODO
	 */
	enum arrowType {
		ARROW_Up   = 0,
		ARROW_Down = 1,
		ARROW_Unk2 = 2,
		ARROW_Unk3 = 3,
	};

	ArrowBasicCallBack() { }
	ArrowBasicCallBack(P2DPane* pane, DrawContainer* container, f32 p3)
	    : mContainerScreen(container)
	    , _0C(0.0f)
	    , _10(p3)
	{
		_04        = pane->getPosH();
		_08        = pane->getPosV();
		mIsActive  = true;
		mArrowType = ARROW_Unk3;
	}

	arrowType judgeArrowType()
	{
		if (mContainerScreen->getStatus() == DrawContainer::STATE_Wait) {
			if (mContainerScreen->getContainerPikiDisp() > 0) {
				if (mContainerScreen->getMyPikiDisp() > 0) {
					mArrowType = ARROW_Unk2;
				} else {
					mArrowType = ARROW_Down;
				}
			} else {
				if (mContainerScreen->getMyPikiDisp() > 0) {
					mArrowType = ARROW_Up;
				} else {
					mArrowType = ARROW_Unk3;
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
		_0C += _10;
		if (_0C < 0.0f) {
			_0C += TAU;
		}
		if (_0C > TAU) {
			_0C -= TAU;
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
		pic->move(_04, int(NMathF::sin(_0C) * 10.0f) + _08);
	}

	DrawContainer* mContainerScreen; // _00
	int _04;                         // _04
	int _08;                         // _08
	f32 _0C;                         // _0C
	f32 _10;                         // _10
	bool mIsActive;                  // _14
	arrowType mArrowType;            // _18
};

/**
 * @brief TODO
 */
struct ArrowCenterCallBack : public P2DPaneCallBack, public ArrowBasicCallBack {
	ArrowCenterCallBack()
	    : P2DPaneCallBack(nullptr, PANETYPE_Pane)
	{
	}
	ArrowCenterCallBack(P2DPane* pane, DrawContainer* container, f32 p3)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	    , ArrowBasicCallBack(pane, container, p3)
	{
		P2DPicture* pic = (P2DPicture*)pane;
		pUpTex          = loadTexExp("ys_u.bti", true, true);
		pDownTex        = loadTexExp("ya_l.bti", true, true);
		judgeArrowType();
		setTexture(pic);

		// this is just to spawn a random cmpwi that doesn't show up in the DLL
		if (mArrowType == ARROW_Unk3 && mContainerScreen) {
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
		if (mArrowType == ARROW_Unk3 || mArrowType == ARROW_Unk2) {
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
	ArrowLRCallBack(P2DPane* pane, DrawContainer* container, f32 p3)
	    : P2DPaneCallBack(pane, PANETYPE_Picture)
	    , ArrowBasicCallBack(pane, container, p3)
	{
		P2DPicture* pic = (P2DPicture*)pane;
		judgeArrowType();
		if (mArrowType != ARROW_Unk2) {
			pic->setAlpha(0);
		}
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		P2DPicture* pic = (P2DPicture*)pane;
		judgeArrowType();
		if (mArrowType == ARROW_Unk2) {
			active();
		} else {
			sleep();
		}
		update(pic);
		return true;
	}

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

		_08 = new TexAnim(20);
		_08->setData(0, pTexTable[10], 0.2f);
		_08->setData(1, pTexTable[9], 0.05f);
		_08->setData(2, pTexTable[8], 0.05f);
		_08->setData(3, pTexTable[7], 0.05f);
		_08->setData(4, pTexTable[6], 0.05f);
		_08->setData(5, pTexTable[5], 0.05f);
		_08->setData(6, pTexTable[4], 0.05f);
		_08->setData(7, pTexTable[3], 0.05f);
		_08->setData(8, pTexTable[2], 0.05f);
		_08->setData(9, pTexTable[1], 0.05f);
		_08->setData(10, pTexTable[0], 0.3f);
		_08->setData(11, pTexTable[1], 0.025f);
		_08->setData(12, pTexTable[2], 0.025f);
		_08->setData(13, pTexTable[3], 0.025f);
		_08->setData(14, pTexTable[4], 0.025f);
		_08->setData(15, pTexTable[5], 0.025f);
		_08->setData(16, pTexTable[6], 0.025f);
		_08->setData(17, pTexTable[7], 0.025f);
		_08->setData(18, pTexTable[8], 0.025f);
		_08->setData(19, pTexTable[9], 0.025f);

		_0C = new TexAnim(20);
		_0C->setData(0, pTexTable[10], 0.2f);
		_0C->setData(1, pTexTable[11], 0.05f);
		_0C->setData(2, pTexTable[12], 0.05f);
		_0C->setData(3, pTexTable[13], 0.05f);
		_0C->setData(4, pTexTable[14], 0.05f);
		_0C->setData(5, pTexTable[15], 0.05f);
		_0C->setData(6, pTexTable[16], 0.05f);
		_0C->setData(7, pTexTable[17], 0.05f);
		_0C->setData(8, pTexTable[18], 0.05f);
		_0C->setData(9, pTexTable[19], 0.05f);
		_0C->setData(10, pTexTable[20], 0.3f);
		_0C->setData(11, pTexTable[19], 0.025f);
		_0C->setData(12, pTexTable[18], 0.025f);
		_0C->setData(13, pTexTable[17], 0.025f);
		_0C->setData(14, pTexTable[16], 0.025f);
		_0C->setData(15, pTexTable[15], 0.025f);
		_0C->setData(16, pTexTable[14], 0.025f);
		_0C->setData(17, pTexTable[13], 0.025f);
		_0C->setData(18, pTexTable[12], 0.025f);
		_0C->setData(19, pTexTable[11], 0.025f);

		_10 = new TexAnim(40);
		_10->setData(0, pTexTable[10], 0.3f);
		_10->setData(1, pTexTable[9], 0.05f);
		_10->setData(2, pTexTable[8], 0.05f);
		_10->setData(3, pTexTable[7], 0.05f);
		_10->setData(4, pTexTable[6], 0.05f);
		_10->setData(5, pTexTable[5], 0.05f);
		_10->setData(6, pTexTable[4], 0.05f);
		_10->setData(7, pTexTable[3], 0.05f);
		_10->setData(8, pTexTable[2], 0.05f);
		_10->setData(9, pTexTable[1], 0.05f);
		_10->setData(10, pTexTable[0], 0.2f);
		_10->setData(11, pTexTable[1], 0.025f);
		_10->setData(12, pTexTable[2], 0.025f);
		_10->setData(13, pTexTable[3], 0.025f);
		_10->setData(14, pTexTable[4], 0.025f);
		_10->setData(15, pTexTable[5], 0.025f);
		_10->setData(16, pTexTable[6], 0.025f);
		_10->setData(17, pTexTable[7], 0.025f);
		_10->setData(18, pTexTable[8], 0.025f);
		_10->setData(19, pTexTable[9], 0.025f);
		_10->setData(20, pTexTable[10], 0.025f);
		_10->setData(21, pTexTable[11], 0.025f);
		_10->setData(22, pTexTable[12], 0.025f);
		_10->setData(23, pTexTable[13], 0.025f);
		_10->setData(24, pTexTable[14], 0.025f);
		_10->setData(25, pTexTable[15], 0.025f);
		_10->setData(26, pTexTable[16], 0.025f);
		_10->setData(27, pTexTable[17], 0.025f);
		_10->setData(28, pTexTable[18], 0.025f);
		_10->setData(29, pTexTable[19], 0.025f);
		_10->setData(30, pTexTable[20], 0.2f);
		_10->setData(31, pTexTable[19], 0.05f);
		_10->setData(32, pTexTable[18], 0.05f);
		_10->setData(33, pTexTable[17], 0.05f);
		_10->setData(34, pTexTable[16], 0.05f);
		_10->setData(35, pTexTable[15], 0.05f);
		_10->setData(36, pTexTable[14], 0.05f);
		_10->setData(37, pTexTable[13], 0.05f);
		_10->setData(38, pTexTable[12], 0.05f);
		_10->setData(39, pTexTable[11], 0.05f);
		_04 = 0;
	}

	virtual bool invoke(P2DPane* pane) // _08
	{
		P2DPicture* pic = (P2DPicture*)pane;
		TexAnim* anim;
		Texture* tex;
		if (mContainerScreen->getContainerPikiDisp() > 0) {
			if (mContainerScreen->getMyPikiDisp() > 0) {
				anim = _10;
			} else {
				anim = _0C;
			}
		} else {
			if (mContainerScreen->getMyPikiDisp() > 0) {
				anim = _08;
			} else {
				anim = nullptr;
			}
		}

		if (_04) {
			tex = _04->update();
			if (_04 != anim) {
				if (anim) {
					if (tex == anim->getTexPtr()) {
						_04 = anim;
					}
				} else {
					_04 = nullptr;
					tex = pTexTable[10];
				}
			}
		} else {
			if (anim) {
				_04 = anim;
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

	static Texture* pTexTable[21];

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack
	TexAnim* _04;                    // _04
	TexAnim* _08;                    // _08
	TexAnim* _0C;                    // _0C
	TexAnim* _10;                    // _10
	DrawContainer* mContainerScreen; // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct MessageMgr {

	/**
	 * @brief TODO
	 */
	enum messageFlag {
		MSG_NULL  = -1,
		MSG_Unk0  = 0,
		MSG_Unk1  = 1,
		MSG_Unk2  = 2,
		MSG_Unk3  = 3,
		MSG_Unk4  = 4,
		MSG_Unk5  = 5,
		MSG_Unk6  = 6,
		MSG_Unk7  = 7,
		MSG_Unk8  = 8,
		MSG_Unk9  = 9,
		MSG_Unk10 = 10,
		MSG_COUNT, // 1
	};

	MessageMgr(P2DScreen& screen)
	{
		mMessageCount = MSG_COUNT;
		_08           = new P2DTextBox*[mMessageCount];
		_0C           = new P2DTextBox*[mMessageCount];
		_10           = new P2DTextBox*[mMessageCount];
		_14           = new P2DTextBox*[mMessageCount];
		_18           = new P2DTextBox*[mMessageCount];
		_1C           = new P2DTextBox*[mMessageCount];
		_20           = 0.0f;
		_24           = 0.0f;
		mMessage      = MSG_NULL;

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
			_08[i]->setAlpha(0);
			_0C[i]->setAlpha(0);
			_10[i]->setAlpha(0);
			_14[i]->setAlpha(0);
			_18[i]->setAlpha(0);
			_1C[i]->setAlpha(0);
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
			_08[msg] = tBox1;
			_0C[msg] = tBox2;
			break;

		case DrawContainer::COLOR_Blue:
			_10[msg] = tBox1;
			_14[msg] = tBox2;
			break;

		case DrawContainer::COLOR_Yellow:
			_18[msg] = tBox1;
			_1C[msg] = tBox2;
			break;
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
			case MSG_Unk4:
			case MSG_Unk5:
			case MSG_Unk6:
			case MSG_Unk7:
			case MSG_Unk8:
			case MSG_Unk9:
				SeSystem::playSysSe(SYSSE_CMENU_ERROR);
				break;
			}
		}
		_20      = 0.0f;
		_24      = p2;
		mMessage = msg;

		if (msg != MSG_NULL) {
			switch (mColorMode) {
			case DrawContainer::COLOR_Red:
				_08[mMessage]->show();
				_0C[mMessage]->show();
				break;

			case DrawContainer::COLOR_Blue:
				_10[mMessage]->show();
				_14[mMessage]->show();
				break;

			case DrawContainer::COLOR_Yellow:
				_18[mMessage]->show();
				_1C[mMessage]->show();
				break;
			}
		}
	}

	// DLL inlines:
	void setColorMode(DrawContainer::containerType color) { mColorMode = color; }

	// DLL inlines to do:
	void update(Controller* controller, int containerNum, int squadNum)
	{
		bool check = false;
		if (_24 >= 0.0f) {
			_20 += gsys->getFrameTime();
			if (_20 > _24) {
				_20   = 0.0f;
				check = true;
			}
		}

		if (mMessage == MSG_Unk10 && controller->keyDown(KBBTN_MSTICK_UP | KBBTN_MSTICK_DOWN)) {
			setMessage(MSG_NULL, 0.0f);
		}

		if (check) {
			switch (mMessage) {
			case MSG_NULL:
			case MSG_Unk0:
			case MSG_Unk1:
			case MSG_Unk2:
			case MSG_Unk3:
				if (mMessage == MSG_NULL) {
					if (containerNum > 0) {
						if (squadNum > 0) {
							setMessage(MSG_Unk0, 4.0f);
						} else {
							setMessage(MSG_Unk1, 4.0f);
						}
					} else {
						if (squadNum > 0) {
							setMessage(MSG_Unk2, 4.0f);
						} else {
							setMessage(MSG_Unk3, -1.0f);
						}
					}
				} else {
					setMessage(MSG_Unk10, -1.0f);
				}
				break;

			default:
				setMessage(MSG_NULL, 0.0f);
				break;
			}
		}

		P2DTextBox** tBox1;
		P2DTextBox** tBox2;
		switch (mColorMode) {
		case DrawContainer::COLOR_Red:
			tBox1 = _08;
			tBox2 = _0C;
			break;

		case DrawContainer::COLOR_Blue:
			tBox1 = _10;
			tBox2 = _14;
			break;

		case DrawContainer::COLOR_Yellow:
			tBox1 = _18;
			tBox2 = _1C;
			break;
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

	messageFlag mMessage;                    // _00
	int mMessageCount;                       // _04
	P2DTextBox** _08;                        // _08
	P2DTextBox** _0C;                        // _0C
	P2DTextBox** _10;                        // _10
	P2DTextBox** _14;                        // _14
	P2DTextBox** _18;                        // _18
	P2DTextBox** _1C;                        // _1C
	f32 _20;                                 // _20
	f32 _24;                                 // _24
	DrawContainer::containerType mColorMode; // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct WindowPaneMgr {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		MODE_Unk0 = 0,
		MODE_Unk1 = 1,
		MODE_Unk2 = 2,
		MODE_Unk3 = 3,
	};

	WindowPaneMgr(P2DPane* pane)
	{
		_00 = pane;
		_04.set(_00->getPosH(), _00->getPosV(), 0.0f);
		init();
	}

	// DLL, but this needs to be above update or sdata gets screwy
	void init()
	{
		_00->setScale(1.0f);
		_00->move(_04.x + 640.0f, _04.y);
		_00->setOffset(_00->getWidth() >> 1, _00->getHeight() >> 4);
		_00->rotate(P2DROTATE_Z, 0.0f);
		_10.set(_00->getPosH(), _00->getPosV() + weightPosLength, 0.0f);
		_1C.set(0.0f, 0.0f, 0.0f);
	}

	// weak:
	void update(modeFlag mode, f32 t, f32 tComp)
	{
		switch (mode) {
		case MODE_Unk0:
			break;

		case MODE_Unk1:
			_00->move(RoundOff(_04.x * t + (_04.x + 640.0f) * tComp), RoundOff(_04.y * t + (_04.y - 0.0f) * tComp));
			break;

		case MODE_Unk3:
			_00->move(RoundOff(_04.x * tComp + (_04.x - 640.0f) * t), RoundOff(_04.y * tComp + (_04.y - 0.0f) * t));
			break;
		}

		Vector3f vec1;
		Vector3f vec2;

		_1C.y += weightPosGravity;
		vec2.set(_10.x + _1C.x, _10.y + _1C.y, 0.0f);
		vec1.x = vec2.x - _00->getPosH();
		vec1.y = vec2.y - _00->getPosV();

		if (vec1.length() != 0.0f) {
			vec1.normalize();
			vec1.multiply(weightPosLength);
			vec2.x = _00->getPosH() + vec1.x;
			vec2.y = _00->getPosV() + vec1.y;
			_1C.set(vec2.x - _10.x, vec2.y - _10.y, 0.0f);
			_10 = vec2;
			_00->rotate(P2DROTATE_Z, NMathF::atan2(-vec1.y, -vec1.x) + HALF_PI);
		}
	}

	static const f32 weightPosGravity;
	static const f32 weightPosLength;

	P2DPane* _00; // _00
	Vector3f _04; // _04
	Vector3f _10; // _10
	Vector3f _1C; // _1C
};

} // namespace zen

extern zen::DrawContainer* containerWindow;

#endif
