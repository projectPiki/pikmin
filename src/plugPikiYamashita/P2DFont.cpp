#include "P2D/Font.h"
#include "Texture.h"
#include "DebugLog.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	801B5C64
 * Size:	000150
 */
Font* P2DFont::loadFont(char* name, int& rows, int& columns)
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

/*
 * --INFO--
 * Address:	801B5DB4
 * Size:	0000BC
 */
P2DFont::P2DFont(char* fileName)
{
	int rows, columns;
	mFont     = loadFont(fileName, rows, columns);
	mFontType = 2;
	mWidth    = (mFont->mTexture->mWidth / rows);
	mLeading  = 5;
	mDescent  = (mFont->mTexture->mHeight / columns) * 0.0f;
	mAscent   = (mFont->mTexture->mHeight / columns) - mDescent;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r3, 0
	  addi      r5, r1, 0x18
	  addi      r6, r1, 0x14
	  bl        -0x16C
	  stw       r3, 0x0(r31)
	  li        r3, 0x2
	  li        r0, 0x5
	  sth       r3, 0x4(r31)
	  lis       r5, 0x4330
	  addi      r3, r31, 0
	  lwz       r6, 0x0(r31)
	  lwz       r4, 0x18(r1)
	  lwz       r6, 0x0(r6)
	  lhz       r6, 0x8(r6)
	  divw      r4, r6, r4
	  sth       r4, 0x6(r31)
	  sth       r0, 0x8(r31)
	  lwz       r6, 0x0(r31)
	  lfs       f0, -0x48F0(r2)
	  lwz       r6, 0x0(r6)
	  fctiwz    f0, f0
	  lwz       r4, 0x14(r1)
	  lhz       r6, 0xA(r6)
	  divw      r4, r6, r4
	  stfd      f0, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  sth       r0, 0xC(r31)
	  xoris     r0, r4, 0x8000
	  lwz       r4, 0x0(r31)
	  stw       r0, 0x2C(r1)
	  lwz       r4, 0x0(r4)
	  lwz       r0, 0x14(r1)
	  lhz       r4, 0xA(r4)
	  stw       r5, 0x28(r1)
	  divw      r0, r4, r0
	  lhz       r4, 0xC(r31)
	  sub       r0, r0, r4
	  sth       r0, 0xA(r31)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B5E70
 * Size:	0000D8
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

/*
 * --INFO--
 * Address:	801B5F48
 * Size:	000024
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

/*
 * --INFO--
 * Address:	801B5F6C
 * Size:	0000C4
 */
f32 P2DFont::getWidth(int charCode, int drawWidth)
{
	f32 a = mFont->mChars[charToIndex(charCode)].mCharSpacing;
	f32 b = drawWidth;
	return b / getWidth() * a + 1.0f;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,0,23
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x38(r1)
	  addi      r30, r3, 0
	  beq-      .loc_0x34
	  lwz       r3, 0x0(r30)
	  rlwinm    r4,r4,0,16,31
	  bl        -0x18DF40
	  b         .loc_0x40

	.loc_0x34:
	  lwz       r3, 0x0(r30)
	  rlwinm    r4,r4,0,24,31
	  bl        -0x18DFF4

	.loc_0x40:
	  lhz       r0, 0x6(r30)
	  xoris     r4, r31, 0x8000
	  lwz       r6, 0x0(r30)
	  lis       r5, 0x4330
	  stw       r4, 0x2C(r1)
	  lfd       f3, -0x48E8(r2)
	  mulli     r3, r3, 0x1C
	  stw       r0, 0x24(r1)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x28(r1)
	  lfd       f1, -0x48D8(r2)
	  add       r3, r0, r3
	  stw       r5, 0x20(r1)
	  lfd       f2, 0x28(r1)
	  lfd       f0, 0x20(r1)
	  fsubs     f2, f2, f3
	  lha       r0, 0x8(r3)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x48E0(r2)
	  xoris     r0, r0, 0x8000
	  fdivs     f1, f2, f1
	  stw       r0, 0x34(r1)
	  stw       r5, 0x30(r1)
	  lfd       f2, 0x30(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f2, f1
	  fadds     f1, f0, f2
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B6030
 * Size:	000308
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
