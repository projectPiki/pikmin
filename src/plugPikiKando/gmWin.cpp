#include "DebugLog.h"
#include "FlowController.h"
#include "Font.h"
#include "Geometry.h"
#include "Graphics.h"
#include "Matrix4f.h"
#include "Vector.h"
#include "Win.h"

static Texture* wintex;
static Texture* arrowtex;
static Texture* udarrowtex;
// This does not appear in the MW Linker Map because it would have been the only object
// in the .bss section of gmWin.o, meaning everything in the .bss section of gmWin.o was
// unused and the section got stripped entirely.  Unfortunately, none of these static
// variables appear in the ILK, so it's impossible to know what this variable was named.
static Texture* sticktexs[3];
static Texture* ketteitex;

static Font* font;

GmWinMgr* gmWinMgr;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0 (Matching by size)
 */
DEFINE_PRINT(TERNARY_BUILD_MATCHING("gwWin", "gmWin")) // Nice typo

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F8 (Matching by size)
 */
GmWin::GmWin()
{
	mWidth  = 100;
	mHeight = 100;
	mHome.set(0, 0);
	initCore("gmwin");
	mColourA.set(100, 100, 255, 255);
	mAuxColourA.set(50, 50, 255, 255);
	mColourB.set(255, 255, 255, 255);
	mAuxColourB.set(255, 100, 0, 255);
	mStatus        = GMWIN_Inactive;
	mCloseListener = nullptr;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00000C (Matching by size)
 */
void GmWin::setRect(int width, int height)
{
	mWidth  = width;
	mHeight = height;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000014 (Matching by size)
 */
void GmWin::moveHome(Vector2i& newHome)
{
	mHome = newHome;
}

/**
 * @todo: Documentation
 */
void GmWin::open()
{
	mStatus = GMWIN_Opening;
}

/**
 * @todo: Documentation
 */
void GmWin::close()
{
	if (mCloseListener) {
		mCloseListener->onCloseWindow();
	}
	mStatus = GMWIN_Closing;
}

/**
 * @todo: Documentation
 */
void GmWin::render(Graphics& gfx)
{
	RectArea area(0, 0, mWidth, mHeight);
	area.mMinX += mHome.x;
	area.mMaxX += mHome.x;
	area.mMinY += mHome.y;
	area.mMaxY += mHome.y;
	Matrix4f matrix;
	gfx.setOrthogonal(matrix.mMtx, area);
	gfx.setColour(mColourA, true);
	gfx.setAuxColour(mAuxColourA);
	gfx.useTexture(wintex, GX_TEXMAP0);
	gfx.drawRectangle(area, RectArea(0, 0, 128, 128), nullptr);
	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setColour(COLOUR_WHITE, true);
	doRender(gfx);
}

// `GmWin::doRender` spawns here in the DOL because it was just used for the first time.

/**
 * @todo: Documentation
 */
void GmWin::placeCentre()
{
	const int centerX = mWidth >> 1;
	const int centerY = mHeight >> 1;

	mHome.x = 320 - centerX;
	mHome.y = 240 - centerY;
}

/**
 * @todo: Documentation
 */
void GmWin::print(Graphics& gfx, int posX, int posY, immut char* message)
{
	gfx.texturePrintf(font, posX + mHome.x, posY + mHome.y, message);
}

/**
 * @todo: Documentation
 */
void GmWin::printcentre(Graphics& gfx, int posY, immut char* message)
{
	const int windowWidth = mWidth >> 1;
	const int stringWidth = font->stringWidth(message) >> 1;
	gfx.texturePrintf(font, mHome.x + windowWidth - stringWidth, posY + mHome.y, message);
}

/**
 * @todo: Documentation
 */
void GmWin::printright(Graphics& gfx, int posY, immut char* message)
{
	const int windowWidth = mWidth;
	const int stringWidth = font->stringWidth(message);
	gfx.texturePrintf(font, mHome.x + windowWidth - stringWidth - 32, posY + mHome.y, message);
}

/**
 * @todo: Documentation
 */
void GmWin::printleft(Graphics& gfx, int posY, immut char* message)
{
	gfx.texturePrintf(font, 32 + mHome.x, posY + mHome.y, message);
}

/**
 * @todo: Documentation
 */
void GmWin::printStart(Graphics& gfx)
{
	gfx.setColour(mColourB, true);
	gfx.setAuxColour(mAuxColourB);
}

/**
 * @todo: Documentation
 */
void GmWin::texture(Graphics& gfx, Texture* texture, int minX, int minY, int maxX, int maxY, RectArea area)
{
	minX = minX + mHome.x;
	minY = minY + mHome.y;
	gfx.useTexture(texture, GX_TEXMAP0);
	gfx.drawRectangle(RectArea(minX, minY, minX + maxX, minY + maxY), area, nullptr);
}

/**
 * @todo: Documentation
 */
void GmWin::texturecentre(Graphics& gfx, Texture* texture, int minY, int width, int height, RectArea area)
{
	const int minX = mHome.x + (mWidth >> 1) - (width >> 1);
	minY           = minY + mHome.y;
	gfx.useTexture(texture, GX_TEXMAP0);
	gfx.drawRectangle(RectArea(minX, minY, minX + width, minY + height), area, nullptr);
}

/**
 * @todo: Documentation
 */
void GmWin::textureleft(Graphics& gfx, Texture* texture, int minY, int width, int height, RectArea area)
{
	const int minX = mHome.x + 32;
	minY           = minY + mHome.y;
	gfx.useTexture(texture, GX_TEXMAP0);
	gfx.drawRectangle(RectArea(minX, minY, minX + width, minY + height), area, 0);
}

/**
 * @todo: Documentation
 */
void GmWin::textureright(Graphics& gfx, Texture* texture, int minY, int width, int height, RectArea area)
{
	const int minX = mHome.x + mWidth - width - 32;
	minY           = minY + mHome.y;
	gfx.useTexture(texture, GX_TEXMAP0);
	gfx.drawRectangle(RectArea(minX, minY, minX + width, minY + height), area, nullptr);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C (Matching by size?)
 */
GmWinMgr::GmWinMgr()
{
	mRoot.initCore("gmwin-root");

	// This function's size is way off when naively following the DLL.  Something has got to give.
#if !defined(BUILD_MATCHING) || defined(WIN32)
	wintex       = gsys->loadTexture("2d_data/karltexs/gmwin.bti", true);
	arrowtex     = gsys->loadTexture("2d_data/karltexs/arrow.bti", true);
	udarrowtex   = gsys->loadTexture("2d_data/karltexs/udarrow.bti", true);
	ketteitex    = gsys->loadTexture("2d_data/karltexs/kettei.bti", true);
	sticktexs[0] = gsys->loadTexture("2d_data/karltexs/stick_u.bti", true);
	sticktexs[1] = gsys->loadTexture("2d_data/karltexs/stick_n.bti", true);
	sticktexs[2] = gsys->loadTexture("2d_data/karltexs/stick_d.bti", true);

	font = new Font();
	font->setTexture(gsys->loadTexture("bigFont.bti", true), 21, 36);
#endif
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000020 (Matching by size)
 */
void GmWinMgr::addWindow(GmWin* win)
{
	mRoot.add(win);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000058 (Matching by size)
 */
void GmWinMgr::update()
{
	FOREACH_NODE(GmWin, mRoot.mChild, win)
	{
		if (win->mStatus != GMWIN_Inactive) {
			win->update();
		}
	}
}

// `GmWin::update` spawns here in the DOL because it was just used for the first time.

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000A0 (Matching by size)
 */
void GmWinMgr::render(Graphics& gfx)
{
	FOREACH_NODE(GmWin, mRoot.mChild, win)
	{
		if (win->mStatus != GMWIN_Inactive) {
			win->render(gfx);
		}
	}
	Matrix4f mtx;
	gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000028 (Matching by size)
 */
GmWin* GmWinMgr::getWindow(u32 id)
{
	FOREACH_NODE(GmWin, mRoot.mChild, win)
	{
		if (win->_2C.mId = id) {
			return win;
		}
	}
	return nullptr;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0005B4 (Matching by size)
 */
void ContainerWin::doRender(Graphics& gfx)
{
	printStart(gfx);

	char buffer[64];

	switch (_60) {
	case 1:
	{
		sprintf(buffer, "ピキをだす？");
		break;
	}
	case -1:
	{
		sprintf(buffer, "ピキをいれる？");
		break;
	}
	case 0:
	{
		sprintf(buffer, "ピキをだす？いれる？");
		break;
	}
	default:
	{
		sprintf(buffer, "なにもできません");
		break;
	}
	}
	printcentre(gfx, 32, buffer);

	sprintf(buffer, "%d", _64);
	printcentre(gfx, 80, buffer);

	sprintf(buffer, "%d", _68);
	printcentre(gfx, 182, buffer);

	switch (_60) {
	case 1:
	{
		// Inside-out `RectArea` flips the texture vertically.
		texturecentre(gfx, arrowtex, 115, 32, 64, RectArea(0, 64, 64, 0));
		break;
	}
	case -1:
	{
		texturecentre(gfx, arrowtex, 115, 32, 64, RectArea(0, 0, 64, 64));
		break;
	}
	case 0:
	{
		if (mToContainer == 0) {
			texturecentre(gfx, udarrowtex, 115, 32, 64, RectArea(0, 0, 64, 64));
		} else if (mToContainer < 0) {
			// Inside-out `RectArea` flips the texture vertically.
			texturecentre(gfx, arrowtex, 115, 32, 64, RectArea(0, 64, 64, 0));
		} else /* (_5C > 0) */ {
			texturecentre(gfx, arrowtex, 115, 32, 64, RectArea(0, 0, 64, 64));
		}
		break;
	}
	}

	if (mToContainer != 0) {
		sprintf(buffer, "%d", mToContainer > 0 ? mToContainer : -mToContainer);
		printcentre(gfx, 131, buffer);
	}

	gfx.setColour(COLOUR_WHITE, true);
	gfx.setAuxColour(COLOUR_WHITE);
	texture(gfx, ketteitex, 240, 160, 96, 96, RectArea(0, 0, 128, 128));

	// Function-scope static variables are handled differently across MWCC and MSVC:
	// MWCC puts ALL static variables into .(s)bss and initializes them at runtime
	// with a `init$` boolean flag dedicated to each variable.  MSVC initializes
	// primitive static variables at compile-time: zero-initialized variables go
	// into .bss, otherwise they go into .data.  With this knowledge, we can recover
	// these variable names from the MW Linker Map and initial values from the DLL
	// with a reasonable level of confidence in their accuracy.  Context clues also
	// help. The ILK doesn't expose local symbol names, so it doesn't help us here.

	static int stickpic = 0;
	static int stimer   = 10;
	static int mv       = 1;

	if (--stimer == 0) {
		stickpic += mv;
		if (stickpic < 0) {
			stickpic = 1;
			mv       = -mv;
		} else if (stickpic > 2) {
			stickpic = 1;
			mv       = -mv;
		}
		stimer = 10;
	}

	texture(gfx, sticktexs[stickpic], 20, 160, 96, 96, RectArea(0, 0, 128, 128));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00007C (Matching by size)
 */
void ContainerWin::setWin(int param_1, int param_2, Listener* listener)
{
	_64                = param_1;
	_68                = param_2;
	mContainerListener = listener;

	if (_64 > 0 && _68 == 0) {
		_60 = 1;
	} else if (_64 == 0 && _68 > 0) {
		_60 = -1;
	} else if (_64 > 0 && _68 > 0) {
		_60 = 0;
	} else {
		_60 = -2;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000310 (Nonmatching by size)
 * I'm gonna be so for real, I don't care anymore.  Probably equivalent.  Every named temporary variable is accounted for.
 * Ghidra LOVES aggressively interpreting the if-statements BACKWARDS for some reason.  I wish we had a DLL matching setup...
 * EXTREMELY similar to `SeWin::update`, to the point where it's clear they copy-pasted a lot of this one way or the other.
 */
void ContainerWin::update()
{
	switch (mStatus) {
	case GMWIN_Opening:
	{
		--mAnimFramesRemaining;
		mHome.y += 32;
		if (mAnimFramesRemaining == 0) {
			mStatus = GMWIN_Active;
		}
		if (absF(mController->getMainStickY()) > 0.5f) {
			mStickWasPushed = true;
		}
		return;
	}
	case GMWIN_Closing:
	{
		--mAnimFramesRemaining;
		mHome.y += 32;
		if (mAnimFramesRemaining == 0) {
			mStatus = GMWIN_Inactive;
		}
		return;
	}
	case GMWIN_Active:
	{
		if (mStickWasPushed) {
			if (absF(mController->getMainStickY() > 0.5f)) {
				return;
			}
			mStickWasPushed = false;
		}
		const f32 mainStickY = mController->getMainStickY();

		bool flag = true;
		if (mainStickY > 0.5f) {
			if (mUp <= 0) {
				mScrollTime = 0.0f;
			} else if (mScrollTime < 0.8f) {
				flag = false;
			}
			mScrollTime += gsys->getFrameTime();
			if (mScrollTime > 1.4f) {
				if (mUp < 6) {
					mUp += 1;
				}
			} else {
				mUp = 1;
			}
		} else if (mainStickY < 0.5f) {
			if (mUp >= 0) {
				mScrollTime = 0.0f;
			} else if (mScrollTime < 0.8f) {
				flag = false;
			}
			mScrollTime += gsys->getFrameTime();
			if (mScrollTime > 1.4f) {
				if (mUp > -6) {
					mUp -= 1;
				}
			} else {
				mUp = -1;
			}
		} else {
			mUp         = 0;
			mScrollTime = 0.0;
		}

		if (mUp != 0 && flag) {
			if (mUp > 0) {
				int min = (_68 - mToContainer < mUp) ? _68 - mToContainer : mUp;
				mToContainer += min;
				// No PRINT here.
			} else {
				int min = -(_64 + mToContainer) < mUp ? -(_64 + mToContainer) : mUp;
				mToContainer += min;
				PRINT("min = %d : toContainer = %d\n", min, mToContainer);
			}
		}

		if (mController->keyClick(KBBTN_A)) {
			mContainerListener->informWin(mToContainer);
			_64 += mToContainer;
			_68 -= mToContainer;
			close();
		} else if (mController->keyClick(KBBTN_B) || mController->keyClick(KBBTN_Z)) {
			close();
		} else if (mController->keyClick(KBBTN_CSTICK_RIGHT) || mController->keyClick(KBBTN_CSTICK_LEFT)) {
			// Intentionally left blank
		}
		return;
	}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00006C (Matching by size)
 * Similar in implementation to `SeWin::open` which DOES exist in the DOL
 */
void ContainerWin::open()
{
	if (mStatus == GMWIN_Opening) {
		// already opening!
		return;
	}

	placeCentre();
	GmWin::open();

	mAnimFramesRemaining = (mHome.y + 120) / 32;
	mHome.y              = -120;
	mUp                  = 0;
	mScrollTime          = 0.0f;
	mToContainer         = 0;
	mStickWasPushed      = false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000080 (Matching by size)
 * Identical in implementation to `SeWin::close` which DOES exist in the DOL
 */
void ContainerWin::close()
{
	if (mStatus == GMWIN_Closing) {
		// already closing!
		return;
	}

	placeCentre();
	GmWin::close();

	mAnimFramesRemaining = 15;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000180 (Matching by size)
 */
void ResultWin::doRender(Graphics& gfx)
{
	char buffer[64];

	printStart(gfx);
	printcentre(gfx, 32, "きょうのけっか"); // "Today's Results"

	printleft(gfx, 90, "とったピキ"); // "Picked Pikis"
	sprintf(buffer, "%d", flowCont.mClearStatePikiCount);
	printright(gfx, 90, buffer);

	printleft(gfx, 130, "しんだピキ"); // "Dead Pikis"
	sprintf(buffer, "%d", flowCont._258);
	printright(gfx, 130, buffer);

	printleft(gfx, 170, "ペレット"); // "Pellet"
	sprintf(buffer, "%d", flowCont._254);
	printright(gfx, 170, buffer);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004 (Matching by size)
 */
void ResultWin::update()
{
}
