#include "DebugLog.h"
#include "P2D/Stream.h"
#include "P2D/Window.h"
#include "sysNew.h"
#include "zen/ogSub.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("P2DWindow")

void P2DWindow::makeResident()
{
	mTLCornerTexture->makeResident();
	mBLCornerTexture->makeResident();
	mTRCornerTexture->makeResident();
	mBRCornerTexture->makeResident();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
Texture* P2DWindow::loadResource(immut char* name)
{
	Texture* tex = nullptr;

	if (name) {
		tex = zen::loadTexExp(name, true, true);
		if (!tex) {
			PRINT("can't load texture\n");
		}
	} else {
		PRINT("No texName.\n");
	}

	return tex;
}

void P2DWindow::loadResource()
{
	mTLCornerTexture = new P2DWindowTexture(loadResource(mTLTexName));
	mTRCornerTexture = new P2DWindowTexture(loadResource(mTRTexName));
	mBLCornerTexture = new P2DWindowTexture(loadResource(mBLTexName));
	mBRCornerTexture = new P2DWindowTexture(loadResource(mBRTexName));

	mMinWidth  = mTLCornerTexture->getWidth() + mTRCornerTexture->getWidth();
	mMinHeight = mTLCornerTexture->getHeight() + mBLCornerTexture->getHeight();
}

P2DWindow::P2DWindow(P2DPane* parent, RandomAccessStream* input, u16 paneType)
    : P2DPane(parent, input, paneType)
{
	P2DStream stream(input);
	mWindowBounds.mMinX = (int)input->readShort();
	mWindowBounds.mMinY = (int)input->readShort();
	mWindowBounds.mMaxX = mWindowBounds.mMinX + (int)input->readShort();
	mWindowBounds.mMaxY = mWindowBounds.mMinY + (int)input->readShort();

	mTLTexName = stream.getResource('TIMG');
	mTRTexName = stream.getResource('TIMG');
	mBLTexName = stream.getResource('TIMG');
	mBRTexName = stream.getResource('TIMG');
	stream.getResource('TLUT');
	mWindowFlag = input->readByte();
	stream.getColour(&mTLCornerColour);
	stream.getColour(&mTRCornerColour);
	stream.getColour(&mBLCornerColour);
	stream.getColour(&mBRCornerColour);

	stream.align(4);
}

void P2DWindow::drawSelf(int x, int y)
{
	Matrix4f mtx;
	mtx.makeIdentity();
	drawSelf(x, y, &mtx);
}

void P2DWindow::drawSelf(int x, int y, immut Matrix4f* mtx)
{
	PUTRect bounds(mGlobalBounds.mMinX, mGlobalBounds.mMinY, mGlobalBounds.mMaxX, mGlobalBounds.mMaxY);
	bounds.add(x, y);
	draw_private(bounds, mWindowBounds, mtx);
	clip(mWindowBounds);
}

void P2DWindow::draw_private(const PUTRect& bounds, const PUTRect& windowBounds, immut Matrix4f* transform)
{
	if (bounds.getWidth() >= mMinWidth && bounds.getHeight() >= mMinHeight) {
		Matrix4f mtx1;
		transform->multiplyTo(mWorldMtx, mtx1);
		GXLoadPosMtxImm(mtx1.mMtx, 0);
		drawContents(windowBounds);

		int x = bounds.getWidth() - mBRCornerTexture->getWidth();
		int y = bounds.getHeight() - mBRCornerTexture->getHeight();

		GXClearVtxDesc();
		GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
		GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
		GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
		GXSetNumTexGens(1);

		mTLCornerTexture->draw(0, 0, mWindowFlag & 0x80, mWindowFlag & 0x40);
		mTRCornerTexture->draw(x, 0, mWindowFlag & 0x20, mWindowFlag & 0x10);
		mBLCornerTexture->draw(0, y, mWindowFlag & 0x8, mWindowFlag & 0x4);
		mBRCornerTexture->draw(x, y, mWindowFlag & 0x2, mWindowFlag & 0x1);

		int height, width;
		width  = mTLCornerTexture->getWidth();
		height = mTLCornerTexture->getHeight();

		u16 flag4, flag3, flag2, flag1;
		flag2 = flag4 = (mWindowFlag & 0x20) ? (u16)0x8000 : (u16)0;
		flag1         = (mWindowFlag & 0x10) ? (u16)0 : (u16)0x8000;
		flag3         = flag1 ^ 0x8000;
		mTRCornerTexture->draw(width, 0, x - width, mTRCornerTexture->getHeight(), flag2, flag1, flag4, flag3);

		flag4 = flag2 = (mWindowFlag & 0x2) ? (u16)0x8000 : (u16)0;
		flag1         = (mWindowFlag & 0x1) ? (u16)0 : (u16)0x8000;
		flag3         = flag1 ^ 0x8000;
		mBRCornerTexture->draw(width, y, x - width, mBRCornerTexture->getHeight(), flag2, flag1, flag4, flag3);

		flag1 = (mWindowFlag & 0x8) ? (u16)0 : (u16)0x8000;
		flag3 = flag1 ^ 0x8000;
		flag2 = (mWindowFlag & 0x4) ? (u16)0x8000 : (u16)0;
		flag4 = flag2;

		/* In the code below there is no discernible reason for why the developers would
		have passed the variables around like this, therefore it is simply structured this
		way for the sake of matching. */

		int make_it_match_1 = 0;
		int make_it_match_2 = height;
		int make_it_match_3 = mBLCornerTexture->getWidth();
		int make_it_match_4 = y - height;
		mBLCornerTexture->draw(make_it_match_1, make_it_match_2, make_it_match_3, make_it_match_4, flag1, flag2, flag3, flag4);

		flag1 = (mWindowFlag & 0x2) ? (u16)0 : (u16)0x8000;
		flag3 = flag1 ^ 0x8000;
		flag2 = (mWindowFlag & 0x1) ? (u16)0x8000 : (u16)0;
		flag4 = flag2;

		make_it_match_1 = x;
		mBRCornerTexture->draw(make_it_match_1, height, mBRCornerTexture->getWidth(), y - height, flag1, flag2, flag3, flag4);

		GXSetNumTexGens(0);
		GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
		GXSetVtxDesc(GX_VA_TEX0, GX_NONE);
	}
}

void P2DWindow::drawContents(const PUTRect& windowBounds)
{
	if (!windowBounds.isEmpty()) {
		GXClearVtxDesc();
		GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
		GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
		GXSetNumChans(1);
		GXSetNumTexGens(0);
		GXSetNumTevStages(1);
		GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
		GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_VTX, 0, GX_DF_NONE, GX_AF_NONE);

		if (mTLCornerColour.a == 255 && mTRCornerColour.a == 255 && mBLCornerColour.a == 255 && mBRCornerColour.a == 255) {
			GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_SET);
		} else {
			GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
		}

		GXBegin(GX_QUADS, GX_VTXFMT0, 4);

		// top left
		GXPosition3s16(windowBounds.mMinX, windowBounds.mMinY, 0);
		GXColor1u32(*(u32*)&mTLCornerColour);

		// top right
		GXPosition3s16(windowBounds.mMaxX, windowBounds.mMinY, 0);
		GXColor1u32(*(u32*)&mTRCornerColour);

		// bottom right
		GXPosition3s16(windowBounds.mMaxX, windowBounds.mMaxY, 0);
		GXColor1u32(*(u32*)&mBRCornerColour);

		// bottom left
		GXPosition3s16(windowBounds.mMinX, windowBounds.mMaxY, 0);
		GXColor1u32(*(u32*)&mBLCornerColour);
	}
}

void P2DWindow::P2DWindowTexture::draw(int x, int y, int width, int height, u16 u0, u16 v0, u16 u1, u16 v1)
{
	int x1 = x + width;
	int y1 = y + height;

	mTexture->makeResident();
	GXLoadTexObj(mTexture->mTexObj, GX_TEXMAP0);
	setTevMode();

	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	GXPosition3s16(x, y, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2s16(u1, v1);

	GXPosition3s16(x1, y, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2s16(u0, v1);

	GXPosition3s16(x1, y1, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2s16(u0, v0);

	GXPosition3s16(x, y1, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2s16(u1, v0);
}

void P2DWindow::P2DWindowTexture::draw(int x, int y, bool p3, bool p4)
{
	draw(x, y, mTexture->mWidth, mTexture->mHeight, u16(p3 ? 0 : 0x8000), u16(p4 ? 0 : 0x8000), u16(p3 ? 0x8000 : 0), u16(p4 ? 0x8000 : 0));
}

void P2DWindow::P2DWindowTexture::setTevMode()
{
	GXSetNumTevStages(1);
	GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
	GXSetTevOp(GX_TEVSTAGE0, GX_REPLACE);
	GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
}
