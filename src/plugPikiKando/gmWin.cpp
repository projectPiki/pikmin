#include "Font.h"
#include "Geometry.h"
#include "Graphics.h"
#include "Matrix4f.h"
#include "Vector.h"
#include "Win.h"
#include "DebugLog.h"

static Texture* wintex;
static Font* font;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
GmWin::GmWin()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void GmWin::setRect(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void GmWin::moveHome(Vector2i&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80111E14
 * Size:	00000C
 */
void GmWin::open()
{
	mStatus = 0x1000;
}

/*
 * --INFO--
 * Address:	80111E20
 * Size:	00004C
 */
void GmWin::close()
{
	if (mCloseListener) {
		mCloseListener->onCloseWindow();
	}
	mStatus = 0x1002;
}

/*
 * --INFO--
 * Address:	80111E6C
 * Size:	00019C
 */
void GmWin::render(Graphics& gfx)
{
	RectArea area(0, 0, mWidth, mHeight);
	area.mMinX += mPosX;
	area.mMaxX += mPosX;
	area.mMinY += mPosY;
	area.mMaxY += mPosY;
	Matrix4f matrix;
	gfx.setOrthogonal(matrix.mMtx, area);
	gfx.setColour(mColourA, true);
	gfx.setAuxColour(mAuxColourA);
	gfx.useTexture(wintex, 0);
	gfx.drawRectangle(area, RectArea(0, 0, 128, 128), nullptr);
	gfx.useTexture(nullptr, 0);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	doRender(gfx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void GmWin::doRender(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80112008
 * Size:	000024
 */
void GmWin::placeCentre()
{
	const int centerX = mWidth >> 1;
	const int centerY = mHeight >> 1;

	mPosX = 320 - (centerX);
	mPosY = 240 - (centerY);
}

/*
 * --INFO--
 * Address:	8011202C
 * Size:	000050
 */
void GmWin::print(Graphics& gfx, int posX, int posY, char* message)
{
	gfx.texturePrintf(font, posX + mPosX, posY + mPosY, message);
}

/*
 * --INFO--
 * Address:	8011207C
 * Size:	000080
 */
void GmWin::printcentre(Graphics& gfx, int posY, char* message)
{
	const int windowWidth = mWidth >> 1;
	const int stringWidth = font->stringWidth(message) >> 1;
	gfx.texturePrintf(font, mPosX + windowWidth - stringWidth, posY + mPosY, message);
}

/*
 * --INFO--
 * Address:	801120FC
 * Size:	000080
 */
void GmWin::printright(Graphics& gfx, int posY, char* message)
{
	const int windowWidth = mWidth;
	const int stringWidth = font->stringWidth(message);
	gfx.texturePrintf(font, mPosX + windowWidth - stringWidth - 32, posY + mPosY, message);
}

/*
 * --INFO--
 * Address:	8011217C
 * Size:	000058
 */
void GmWin::printleft(Graphics& gfx, int posY, char* message)
{
	gfx.texturePrintf(font, 32 + mPosX, posY + mPosY, message);
}

/*
 * --INFO--
 * Address:	801121D4
 * Size:	000068
 */
void GmWin::printStart(Graphics& gfx)
{
	gfx.setColour(mColourB, true);
	gfx.setAuxColour(mAuxColourB);
}

/*
 * --INFO--
 * Address:	8011223C
 * Size:	000098
 */
void GmWin::texture(Graphics& gfx, Texture* texture, int minX, int minY, int maxX, int maxY, RectArea area)
{
	minX = minX + mPosX;
	minY = minY + mPosY;
	gfx.useTexture(texture, 0);
	gfx.drawRectangle(RectArea(minX, minY, minX + maxX, minY + maxY), area, nullptr);
}

/*
 * --INFO--
 * Address:	801122D4
 * Size:	0000A8
 */
void GmWin::texturecentre(Graphics& gfx, Texture* texture, int minY, int width, int height, RectArea area)
{
	const int minX = mPosX + (mWidth >> 1) - (width >> 1);
	minY           = minY + mPosY;
	gfx.useTexture(texture, 0);
	gfx.drawRectangle(RectArea(minX, minY, minX + width, minY + height), area, nullptr);
}

/*
 * --INFO--
 * Address:	8011237C
 * Size:	000098
 */
void GmWin::textureleft(Graphics& gfx, Texture* texture, int minY, int width, int height, RectArea area)
{
	const int minX = mPosX + 32;
	minY           = minY + mPosY;
	gfx.useTexture(texture, 0);
	gfx.drawRectangle(RectArea(minX, minY, minX + width, minY + height), area, 0);
}

/*
 * --INFO--
 * Address:	80112414
 * Size:	0000A4
 */
void GmWin::textureright(Graphics& gfx, Texture* texture, int minY, int width, int height, RectArea area)
{
	const int minX = mPosX + mWidth - width - 32;
	minY           = minY + mPosY;
	gfx.useTexture(texture, 0);
	gfx.drawRectangle(RectArea(minX, minY, minX + width, minY + height), area, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
GmWinMgr::GmWinMgr()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void GmWinMgr::addWindow(GmWin*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void GmWinMgr::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void GmWin::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void GmWinMgr::render(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void GmWinMgr::getWindow(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0005B4
 */
void ContainerWin::doRender(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void ContainerWin::setWin(int, int, ContainerWin::Listener*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000310
 */
void ContainerWin::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void ContainerWin::open()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void ContainerWin::close()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000180
 */
void ResultWin::doRender(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void ResultWin::update()
{
	// UNUSED FUNCTION
}
