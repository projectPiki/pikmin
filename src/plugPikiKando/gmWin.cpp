#include "DebugLog.h"
#include "Font.h"
#include "Geometry.h"
#include "Graphics.h"
#include "Matrix4f.h"
#include "Vector.h"
#include "Win.h"

static Texture* wintex;
static Font* font;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F8
 */
GmWin::GmWin()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
void GmWin::setRect(int, int)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000014
 */
void GmWin::moveHome(Vector2i&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void GmWin::open()
{
	mStatus = 0x1000;
}

/**
 * @TODO: Documentation
 */
void GmWin::close()
{
	if (mCloseListener) {
		mCloseListener->onCloseWindow();
	}
	mStatus = 0x1002;
}

/**
 * @TODO: Documentation
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
	gfx.useTexture(wintex, GX_TEXMAP0);
	gfx.drawRectangle(area, RectArea(0, 0, 128, 128), nullptr);
	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	doRender(gfx);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void GmWin::doRender(Graphics&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void GmWin::placeCentre()
{
	const int centerX = mWidth >> 1;
	const int centerY = mHeight >> 1;

	mPosX = 320 - (centerX);
	mPosY = 240 - (centerY);
}

/**
 * @TODO: Documentation
 */
void GmWin::print(Graphics& gfx, int posX, int posY, immut char* message)
{
	gfx.texturePrintf(font, posX + mPosX, posY + mPosY, message);
}

/**
 * @TODO: Documentation
 */
void GmWin::printcentre(Graphics& gfx, int posY, immut char* message)
{
	const int windowWidth = mWidth >> 1;
	const int stringWidth = font->stringWidth(message) >> 1;
	gfx.texturePrintf(font, mPosX + windowWidth - stringWidth, posY + mPosY, message);
}

/**
 * @TODO: Documentation
 */
void GmWin::printright(Graphics& gfx, int posY, immut char* message)
{
	const int windowWidth = mWidth;
	const int stringWidth = font->stringWidth(message);
	gfx.texturePrintf(font, mPosX + windowWidth - stringWidth - 32, posY + mPosY, message);
}

/**
 * @TODO: Documentation
 */
void GmWin::printleft(Graphics& gfx, int posY, immut char* message)
{
	gfx.texturePrintf(font, 32 + mPosX, posY + mPosY, message);
}

/**
 * @TODO: Documentation
 */
void GmWin::printStart(Graphics& gfx)
{
	gfx.setColour(mColourB, true);
	gfx.setAuxColour(mAuxColourB);
}

/**
 * @TODO: Documentation
 */
void GmWin::texture(Graphics& gfx, Texture* texture, int minX, int minY, int maxX, int maxY, RectArea area)
{
	minX = minX + mPosX;
	minY = minY + mPosY;
	gfx.useTexture(texture, GX_TEXMAP0);
	gfx.drawRectangle(RectArea(minX, minY, minX + maxX, minY + maxY), area, nullptr);
}

/**
 * @TODO: Documentation
 */
void GmWin::texturecentre(Graphics& gfx, Texture* texture, int minY, int width, int height, RectArea area)
{
	const int minX = mPosX + (mWidth >> 1) - (width >> 1);
	minY           = minY + mPosY;
	gfx.useTexture(texture, GX_TEXMAP0);
	gfx.drawRectangle(RectArea(minX, minY, minX + width, minY + height), area, nullptr);
}

/**
 * @TODO: Documentation
 */
void GmWin::textureleft(Graphics& gfx, Texture* texture, int minY, int width, int height, RectArea area)
{
	const int minX = mPosX + 32;
	minY           = minY + mPosY;
	gfx.useTexture(texture, GX_TEXMAP0);
	gfx.drawRectangle(RectArea(minX, minY, minX + width, minY + height), area, 0);
}

/**
 * @TODO: Documentation
 */
void GmWin::textureright(Graphics& gfx, Texture* texture, int minY, int width, int height, RectArea area)
{
	const int minX = mPosX + mWidth - width - 32;
	minY           = minY + mPosY;
	gfx.useTexture(texture, GX_TEXMAP0);
	gfx.drawRectangle(RectArea(minX, minY, minX + width, minY + height), area, nullptr);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
 */
GmWinMgr::GmWinMgr()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000020
 */
void GmWinMgr::addWindow(GmWin*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000058
 */
void GmWinMgr::update()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void GmWin::update()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000A0
 */
void GmWinMgr::render(Graphics&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
void GmWinMgr::getWindow(u32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0005B4
 */
void ContainerWin::doRender(Graphics&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00007C
 */
void ContainerWin::setWin(int, int, ContainerWin::Listener*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000310
 */
void ContainerWin::update()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
void ContainerWin::open()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000080
 */
void ContainerWin::close()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000180
 */
void ResultWin::doRender(Graphics&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void ResultWin::update()
{
	// UNUSED FUNCTION
}
