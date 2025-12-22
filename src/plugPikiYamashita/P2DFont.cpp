#include "DebugLog.h"
#include "P2D/Font.h"
#include "Texture.h"
#include "sysNew.h"

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

/**
 * @TODO: Documentation
 */
Font* P2DFont::loadFont(immut char* name, int& rows, int& columns)
{
	Font* font       = nullptr;
	FntobjInfo* info = (FntobjInfo*)gsys->findGfxObject(name, 'font');
	if (info) {
		font = info->mFont;
	}

	if (!font) {
		font             = new Font();
		FntobjInfo* info = new FntobjInfo();
		info->mString    = StdSystem::stringDup(name);
		info->mId.setID('font');
		info->mFont = font;
		gsys->addGfxObject(info);

		char unused[PATH_MAX];
		sprintf(unused, "%s", name); // why.

		Texture* fontTex = gsys->loadTexture("bigFont.bti", true);
		rows             = 21;
		columns          = 42;
		font->setTexture(fontTex, rows, columns);

	} else {
		rows    = 21;
		columns = 42;
	}

	return font;
}

/**
 * @TODO: Documentation
 */
P2DFont::P2DFont(immut char* fileName)
{
	int rows, columns;
	mFont     = loadFont(fileName, rows, columns);
	mFontType = 2;
	mWidth    = (mFont->mTexture->mWidth / rows);
	mLeading  = 5;
	mDescent  = (s32)((mFont->mTexture->mHeight / columns) * 0.0f);
	mAscent   = (mFont->mTexture->mHeight / columns) - mDescent;
}

/**
 * @TODO: Documentation
 */
void P2DFont::setGX()
{
	GXSetNumChans(1);
	GXSetNumTevStages(1);
	GXSetNumTexGens(1);
	GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
	GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
	GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);

	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S16, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U16, 15);
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
}

/**
 * @TODO: Documentation
 */
void P2DFont::setGradColor(const Colour& topColour, const Colour& bottomColour)
{
	mTLColour = topColour;
	mTRColour = topColour;
	mBLColour = bottomColour;
	mBRColour = bottomColour;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
int P2DFont::charToIndex(int c)
{
	if (c & ~0xFF) {
		return mFont->charToIndex(u16(c));
	}

	return mFont->charToIndex(char(c));
}

/**
 * @TODO: Documentation
 */
f32 P2DFont::getWidth(int charCode, int drawWidth)
{
	f32 a = mFont->mChars[charToIndex(charCode)].mCharSpacing;
	f32 b = drawWidth;
	a *= b / getWidth();
	return a + 1.0f;
}

/**
 * @TODO: Documentation
 */
f32 P2DFont::drawChar(f32 xPos, f32 yPos, int charCode, int drawWidth, int drawHeight)
{
	FontChar* fc = &mFont->mChars[charToIndex(charCode)];
	f32 xScale   = f32(drawWidth) / getWidth();
	f32 yScale   = f32(drawHeight) / getHeight();
	f32 x0       = xPos - fc->mLeftOffset * xScale;
	f32 x1       = xPos + (fc->mWidth - fc->mLeftOffset) * xScale;
	f32 y0       = yPos - getAscent() * yScale;
	f32 y1       = yPos + getDescent() * yScale;

	u16 s0 = f32(fc->mTextureCoords.mMinX + 0.5f) * 32768.0f * mFont->mTexture->mWidthFactor;
	u16 t0 = f32(fc->mTextureCoords.mMinY + 0.5f) * 32768.0f * mFont->mTexture->mHeightFactor;
	u16 s1 = f32(fc->mTextureCoords.mMaxX + 0.5f) * 32768.0f * mFont->mTexture->mWidthFactor;
	u16 t1 = f32(fc->mTextureCoords.mMaxY + 0.5f) * 32768.0f * mFont->mTexture->mHeightFactor;

	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	GXPosition3f32(x0, y0, 0.0f);
	GXColor1u32(*(u32*)&mTLColour);
	GXTexCoord2u16(s0, t0);

	GXPosition3f32(x1, y0, 0.0f);
	GXColor1u32(*(u32*)&mTRColour);
	GXTexCoord2u16(s1, t0);

	GXPosition3f32(x1, y1, 0.0f);
	GXColor1u32(*(u32*)&mBRColour);
	GXTexCoord2u16(s1, t1);

	GXPosition3f32(x0, y1, 0.0f);
	GXColor1u32(*(u32*)&mBLColour);
	GXTexCoord2u16(s0, t1);

	GXEnd();
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S16, 0);

	STACK_PAD_VAR(2);

	return x1 - x0;
}
