#include "P2D/Picture.h"
#include "P2D/Stream.h"
#include "P2D/Util.h"
#include "zen/ogSub.h"
#include "Texture.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("P2DPicture")

/*
 * --INFO--
 * Address:	801B18C4
 * Size:	000074
 */
void P2DPicture::makeResident()
{
	for (int i = 0; i < mTextureCount; i++) {
		if (mTextures[i]) {
			mTextures[i]->makeResident();
		}
	}
}

/*
 * --INFO--
 * Address:	801B1938
 * Size:	000058
 */
void P2DPicture::loadResource()
{
	if (!mTexName) {
		PRINT("No texName.\n");
		return;
	}

	Texture* tex = zen::loadTexExp(mTexName, true, true);
	if (tex) {
		mTextures[0] = tex;
		mTextureCount++;
	} else {
		PRINT("can't load texture [%s] \n", mTexName);
		ERROR("can't load texture [%s] \n", mTexName);
	}
}

/*
 * --INFO--
 * Address:	801B1990
 * Size:	0000B4
 */
P2DPicture::~P2DPicture()
{
	for (int i = 0; i < mTextureCount; i++) {
		if (mTextures[i] && _F2[i]) {
			delete mTextures[i];
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
P2DPicture::P2DPicture()
{
	mTextures[0]  = nullptr;
	mTextureCount = 0;
	initinfo();
}

/*
 * --INFO--
 * Address:	801B1A44
 * Size:	000134
 */
P2DPicture::P2DPicture(P2DPane* parent, RandomAccessStream* input, u16 paneType)
    : P2DPane(parent, input, paneType)
{
	P2DStream stream(input);
	mTexName = stream.getResource('TIMG');
	stream.getResource('TLUT');
	mBinding = (P2DBinding)input->readByte();
	u32 flag = input->readByte();
	mMirror  = (P2DMirror)(flag & 3);
	mTumble  = (flag & 4) ? TRUE : FALSE;
	mWrapS   = (P2DWrapmode)((flag >> 3) & 3);
	mWrapT   = mWrapS;
	stream.align(4);
	mTextures[0]  = nullptr;
	mTextureCount = 0;
	_F2[0]        = 1;
	setAlpha(255);
	initBlack();
	initWhite();
}

/*
 * --INFO--
 * Address:	801B1B78
 * Size:	0000AC
 */
P2DPicture::P2DPicture(Texture* texture)
{
	mTextures[0]  = nullptr;
	mTextureCount = 0;
	if (texture) {
		append(texture, 1.0f);
		place(PUTRect(0, 0, mTextures[0]->mWidth, mTextures[0]->mHeight));
	}

	initinfo();
}

/*
 * --INFO--
 * Address:	801B1C24
 * Size:	00009C
 */
bool P2DPicture::insert(Texture* texture, u8 idx, f32)
{
	// only configured for a single texture
	if (mTextureCount >= 1 || idx >= 1 || idx > mTextureCount) {
		return false;
	}

	// idk that this really works for a single texture yamashita.
	for (u8 i = 0; i > idx; i--) {
		mTextures[i] = mTextures[i - 1];
		_F2[i]       = _F2[i - 1];
	}

	mTextures[idx] = texture;
	_F2[idx]       = 0;
	mTextureCount++;
	return true;
}

/*
 * --INFO--
 * Address:	801B1CC0
 * Size:	000054
 */
void P2DPicture::initinfo()
{
	mPaneType = PANETYPE_Picture;
	setBinding(P2DBIND_All);
	setMirror(P2DMIRROR_Unk0);
	setTumble(false);
	setWrapmode(P2DWRAP_NULL, P2DWRAP_NULL);
	setAlpha(255);
	initBlack();
	initWhite();
}

/*
 * --INFO--
 * Address:	801B1D14
 * Size:	000068
 */
void P2DPicture::drawSelf(int x, int y)
{
	Matrix4f mtx;
	mtx.makeIdentity();
	drawSelf(x, y, &mtx);
}

/*
 * --INFO--
 * Address:	801B1D7C
 * Size:	000078
 */
void P2DPicture::drawSelf(int x, int y, Matrix4f* mtx)
{
	if (mTextures[0]) {
		drawFullSet(_20.mMinX + x, _20.mMinY + y, getWidth(), getHeight(), mBinding, mMirror, mTumble, mWrapS, mWrapT, mtx);
	}
}

/*
 * --INFO--
 * Address:	801B1DF4
 * Size:	000664
 */
void P2DPicture::drawFullSet(int x, int y, int width, int height, P2DBinding binding, P2DMirror mirror, bool tumble, P2DWrapmode wrapS,
                             P2DWrapmode wrapT, Matrix4f* mtx)
{
	int outX = x;
	int outY = y;
	if (wrapS == P2DWRAP_Unk0) {
		f32 tmpWidth;
		if (!tumble) {
			tmpWidth = mTextures[0]->mWidth;
		} else {
			tmpWidth = mTextures[0]->mHeight;
		}
		if (binding & P2DBIND_Unk3) {
			if (!(binding & P2DBIND_Unk2) && tmpWidth < f32(width)) {
				width = tmpWidth;
			}
		} else if (tmpWidth < f32(width)) {
			outX  = (binding & P2DBIND_Unk2) ? (x + width) - (int)tmpWidth : (width - (int)tmpWidth) / 2 + x;
			width = tmpWidth;
		}
	}

	if (wrapT == P2DWRAP_Unk0) {
		f32 tmpHeight;
		if (!tumble) {
			tmpHeight = mTextures[0]->mHeight;
		} else {
			tmpHeight = mTextures[0]->mWidth;
		}
		if (binding & P2DBIND_Unk1) {
			if (!(binding & P2DBIND_Unk0) && tmpHeight < f32(height)) {
				height = tmpHeight;
			}
		} else if (tmpHeight < f32(height)) {
			outY   = (binding & P2DBIND_Unk0) ? (y + height) - (int)tmpHeight : (height - (int)tmpHeight) / 2 + y;
			height = tmpHeight;
		}
	}

	bool a, b, c, d;
	if (!tumble) {
		if (mirror & P2DMIRROR_Unk2) {
			a = (binding & P2DBIND_Unk2) != 0;
		} else {
			a = (binding & P2DBIND_Unk3) != 0;
		}
		if (mirror & P2DMIRROR_Unk2) {
			b = (binding & P2DBIND_Unk3) != 0;
		} else {
			b = (binding & P2DBIND_Unk2) != 0;
		}
		if (mirror & P2DMIRROR_Unk1) {
			c = (binding & P2DBIND_Unk0) != 0;
		} else {
			c = (binding & P2DBIND_Unk1) != 0;
		}
		if (mirror & P2DMIRROR_Unk1) {
			d = (binding & P2DBIND_Unk1) != 0;
		} else {
			d = (binding & P2DBIND_Unk0) != 0;
		}
	} else {
		if (mirror & P2DMIRROR_Unk2) {
			a = (binding & P2DBIND_Unk0) != 0;
		} else {
			a = (binding & P2DBIND_Unk1) != 0;
		}
		if (mirror & P2DMIRROR_Unk2) {
			b = (binding & P2DBIND_Unk1) != 0;
		} else {
			b = (binding & P2DBIND_Unk0) != 0;
		}
		if (mirror & P2DMIRROR_Unk1) {
			c = (binding & P2DBIND_Unk3) != 0;
		} else {
			c = (binding & P2DBIND_Unk2) != 0;
		}
		if (mirror & P2DMIRROR_Unk1) {
			d = (binding & P2DBIND_Unk2) != 0;
		} else {
			d = (binding & P2DBIND_Unk3) != 0;
		}
	}

	f32 tmpWidth  = mTextures[0]->mWidth;
	f32 tmpHeight = mTextures[0]->mHeight;

	int tmp1 = (!tumble) ? width : height;
	int tmp2 = (!tumble) ? height : width;

	f32 outF1, outF3, outF4, outF2;
	if (a) {
		outF1 = 0.0f;
		outF4 = (b) ? 1.0f : tmp1 / tmpWidth;

	} else if (b) {
		outF1 = 1.0f - tmp1 / tmpWidth;
		outF4 = 1.0f;

	} else {
		outF1 = 0.5f - tmp1 / tmpWidth / 2.0f;
		outF4 = tmp1 / tmpWidth / 2.0f + 0.5f;
	}

	if (c) {
		outF3 = 0.0f;
		outF2 = (d) ? 1.0f : tmp2 / tmpHeight;

	} else if (d) {
		outF3 = 1.0f - tmp2 / tmpHeight;
		outF2 = 1.0f;

	} else {
		outF3 = 0.5f - tmp2 / tmpHeight / 2.0f;
		outF2 = tmp2 / tmpHeight / 2.0f + 0.5f;
	}

	if (mirror & P2DMIRROR_Unk2) {
		swap(outF1, outF4);
	}
	if (mirror & P2DMIRROR_Unk1) {
		swap(outF3, outF2);
	}

	if (!tumble) {
		drawTexCoord(outX - x, outY - y, width, height, outF1, outF3, outF4, outF3, outF1, outF2, outF4, outF2, mtx);
	} else {
		drawTexCoord(outX - x, outY - y, width, height, outF1, outF2, outF1, outF3, outF4, outF2, outF4, outF3, mtx);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00040C
 */
void P2DPicture::draw(int, int, int, int, bool, bool, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002F4
 */
void P2DPicture::drawOut(const PUTRect&, const PUTRect&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B2458
 * Size:	000234
 */
void P2DPicture::drawTexCoord(int x, int y, int width, int height, f32 p5, f32 p6, f32 p7, f32 p8, f32 p9, f32 p10, f32 p11, f32 p12,
                              Matrix4f* mtx)
{
	for (int i = 0; i < mTextureCount; i++) {
		load(i);
	}

	int xEnd = x + width;
	int yEnd = y + height;

	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);

	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S16, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_POS_XYZ, GX_RGBA8, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_POS_XYZ, GX_F32, 0);
	GXSetNumTexGens(mTextureCount);

	Matrix4f mtx1;
	mtx->multiplyTo(_78, mtx1);
	GXLoadPosMtxImm(mtx1.mMtx, 0);

	setTevMode();

	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	// bottom left
	GXPosition3s16(x, y, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2f32(p5, p6);

	// bottom right
	GXPosition3s16(xEnd, y, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2f32(p7, p8);

	// top right
	GXPosition3s16(xEnd, yEnd, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2f32(p11, p12);

	// top left
	GXPosition3s16(x, yEnd, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2f32(p9, p10);

	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_POS_XYZ, GX_U16, 15);

	GXEnd();
}

/*
 * --INFO--
 * Address:	801B268C
 * Size:	0004B0
 */
void P2DPicture::setTevMode()
{
	GXColor color;
	for (int i = 0; i < mTextureCount; i++) {
		GXSetTexCoordGen2((GXTexCoordID)i, GX_TG_MTX3X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
	}

	GXSetNumChans(1);

	GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_NONE, GX_AF_NONE);
	GXSetChanMatColor(GX_COLOR0A0, (GXColor) { 255, 255, 255, mAlpha });

	for (int i = 0; i < mTextureCount; i++) {
		GXSetTevOrder((GXTevStageID)i, (GXTexCoordID)i, (GXTexMapID)i, GX_COLOR_NULL);
	}

	if (mTextureCount == 1 && mAlpha == 255 && ((COLOUR_TO_U32(mBlack) == 0) ? true : false)
	    && ((COLOUR_TO_U32(mWhite) == 0xFFFFFFFF) ? true : false)) {
		GXSetNumTevStages(1);
		GXSetTevOp(GX_TEVSTAGE0, GX_REPLACE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
		return;
	}

	GXSetTevColor(GX_TEVREG2, (GXColor) { 255, 255, 255, 255 });
	GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
	GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
	GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
	GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

	*(u32*)&color = 0xFFFFFFFF;
	GXSetTevKColor(GX_KCOLOR0, color);
	int i;
	for (i = 1; i < mTextureCount; i++) {
		GXSetTevKColorSel((GXTevStageID)i, (GXTevKColorSel)(32 - 4 * i));
		GXSetTevKAlphaSel((GXTevStageID)i, (GXTevKAlphaSel)(32 - 4 * i));
		GXSetTevColorIn((GXTevStageID)i, GX_CC_CPREV, GX_CC_TEXC, GX_CC_KONST, GX_CC_ZERO);
		GXSetTevAlphaIn((GXTevStageID)i, GX_CA_APREV, GX_CA_TEXA, GX_CA_KONST, GX_CA_ZERO);
		GXSetTevColorOp((GXTevStageID)i, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevAlphaOp((GXTevStageID)i, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
	}

	if (!((COLOUR_TO_U32(mBlack) == 0) ? true : false) || !((COLOUR_TO_U32(mWhite) == 0xFFFFFFFF) ? true : false)) {
		GXSetTevOrder((GXTevStageID)i, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		GXSetTevColor(GX_TEVREG0, *(GXColor*)&mBlack);
		GXSetTevColor(GX_TEVREG1, *(GXColor*)&mWhite);
		GXSetTevColorIn((GXTevStageID)i, GX_CC_C0, GX_CC_C2, GX_CC_CPREV, GX_CC_ZERO);
		GXSetTevAlphaIn((GXTevStageID)i, GX_CA_A0, GX_CA_A1, GX_CA_APREV, GX_CA_ZERO);
		GXSetTevColorOp((GXTevStageID)i, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevAlphaOp((GXTevStageID)i, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		i++;
	}

	if (mAlpha != 255) {
		GXSetTevOrder((GXTevStageID)i, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
		GXSetTevColorIn((GXTevStageID)i, GX_CC_CPREV, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
		GXSetTevAlphaIn((GXTevStageID)i, GX_CA_ZERO, GX_CA_APREV, GX_CA_RASA, GX_CA_ZERO);
		GXSetTevColorOp((GXTevStageID)i, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevAlphaOp((GXTevStageID)i, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		i++;
	}

	GXSetNumTevStages(i);
	GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  stw       r28, 0x38(r1)
	  li        r28, 0
	  b         .loc_0x48

	.loc_0x28:
	  addi      r3, r28, 0
	  li        r4, 0x1
	  li        r5, 0x4
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x5DD8C
	  addi      r28, r28, 0x1

	.loc_0x48:
	  lbz       r0, 0xF1(r31)
	  cmpw      r28, r0
	  blt+      .loc_0x28
	  li        r3, 0x1
	  bl        0x5F7F0
	  li        r3, 0x4
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, 0x2
	  bl        0x5F81C
	  lwz       r0, -0x4928(r2)
	  addi      r4, r1, 0x2C
	  li        r3, 0x4
	  stw       r0, 0x28(r1)
	  lbz       r0, 0xF0(r31)
	  stb       r0, 0x2B(r1)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x2C(r1)
	  bl        0x5F644
	  li        r28, 0
	  b         .loc_0xC0

	.loc_0xA8:
	  addi      r3, r28, 0
	  addi      r4, r28, 0
	  addi      r5, r28, 0
	  li        r6, 0xFF
	  bl        0x61080
	  addi      r28, r28, 0x1

	.loc_0xC0:
	  lbz       r0, 0xF1(r31)
	  cmpw      r28, r0
	  blt+      .loc_0xA8
	  cmplwi    r0, 0x1
	  bne-      .loc_0x184
	  lbz       r0, 0xF0(r31)
	  cmplwi    r0, 0xFF
	  bne-      .loc_0x184
	  lbz       r3, 0x10C(r31)
	  lbz       r0, 0x10D(r31)
	  rlwinm    r3,r3,24,0,7
	  lbz       r4, 0x10E(r31)
	  rlwimi    r3,r0,16,8,15
	  lbz       r5, 0x10F(r31)
	  rlwimi    r3,r4,8,16,23
	  or.       r0, r5, r3
	  bne-      .loc_0x10C
	  li        r0, 0x1
	  b         .loc_0x110

	.loc_0x10C:
	  li        r0, 0

	.loc_0x110:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x184
	  lbz       r3, 0x108(r31)
	  lbz       r0, 0x109(r31)
	  rlwinm    r3,r3,24,0,7
	  lbz       r4, 0x10A(r31)
	  rlwimi    r3,r0,16,8,15
	  lbz       r5, 0x10B(r31)
	  rlwimi    r3,r4,8,16,23
	  or        r3, r5, r3
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0x14C
	  li        r0, 0x1
	  b         .loc_0x150

	.loc_0x14C:
	  li        r0, 0

	.loc_0x150:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x184
	  li        r3, 0x1
	  bl        0x6117C
	  li        r3, 0
	  li        r4, 0x3
	  bl        0x607A8
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0xF
	  bl        0x61444
	  b         .loc_0x490

	.loc_0x184:
	  lwz       r0, -0x4924(r2)
	  addi      r4, r1, 0x24
	  li        r3, 0x3
	  stw       r0, 0x20(r1)
	  lwz       r0, 0x20(r1)
	  stw       r0, 0x24(r1)
	  bl        0x60B9C
	  li        r3, 0
	  li        r4, 0x8
	  li        r5, 0xF
	  li        r6, 0xF
	  li        r7, 0xF
	  bl        0x60900
	  li        r3, 0
	  li        r4, 0x4
	  li        r5, 0x7
	  li        r6, 0x7
	  li        r7, 0x7
	  bl        0x60968
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x609D0
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x60A74
	  li        r0, -0x1
	  stw       r0, 0x30(r1)
	  addi      r4, r1, 0x1C
	  li        r3, 0
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x1C(r1)
	  bl        0x60C00
	  li        r30, 0x1
	  rlwinm    r29,r30,2,0,29
	  b         .loc_0x2BC

	.loc_0x230:
	  subfic    r28, r29, 0x20
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        0x60C58
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        0x60CB8
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0xE
	  li        r7, 0xF
	  bl        0x60854
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0x4
	  li        r6, 0x6
	  li        r7, 0x7
	  bl        0x608BC
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x60924
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x609C8
	  addi      r29, r29, 0x4
	  addi      r30, r30, 0x1

	.loc_0x2BC:
	  lbz       r0, 0xF1(r31)
	  cmpw      r30, r0
	  blt+      .loc_0x230
	  lbz       r3, 0x10C(r31)
	  lbz       r0, 0x10D(r31)
	  rlwinm    r3,r3,24,0,7
	  lbz       r4, 0x10E(r31)
	  rlwimi    r3,r0,16,8,15
	  lbz       r5, 0x10F(r31)
	  rlwimi    r3,r4,8,16,23
	  or.       r0, r5, r3
	  bne-      .loc_0x2F4
	  li        r0, 0x1
	  b         .loc_0x2F8

	.loc_0x2F4:
	  li        r0, 0

	.loc_0x2F8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x340
	  lbz       r3, 0x108(r31)
	  lbz       r0, 0x109(r31)
	  rlwinm    r3,r3,24,0,7
	  lbz       r4, 0x10A(r31)
	  rlwimi    r3,r0,16,8,15
	  lbz       r5, 0x10B(r31)
	  rlwimi    r3,r4,8,16,23
	  or        r3, r5, r3
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0x334
	  li        r0, 0x1
	  b         .loc_0x338

	.loc_0x334:
	  li        r0, 0

	.loc_0x338:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x3E8

	.loc_0x340:
	  addi      r3, r30, 0
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0xFF
	  bl        0x60DE8
	  lwz       r0, 0x10C(r31)
	  addi      r4, r1, 0x18
	  li        r3, 0x1
	  stw       r0, 0x18(r1)
	  bl        0x609D4
	  lwz       r0, 0x108(r31)
	  addi      r4, r1, 0x14
	  li        r3, 0x2
	  stw       r0, 0x14(r1)
	  bl        0x609C0
	  addi      r3, r30, 0
	  li        r4, 0x2
	  li        r5, 0x4
	  li        r6, 0
	  li        r7, 0xF
	  bl        0x60724
	  addi      r3, r30, 0
	  li        r4, 0x1
	  li        r5, 0x2
	  li        r6, 0
	  li        r7, 0x7
	  bl        0x6078C
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x607F4
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x60898
	  addi      r30, r30, 0x1

	.loc_0x3E8:
	  lbz       r0, 0xF0(r31)
	  cmplwi    r0, 0xFF
	  beq-      .loc_0x474
	  addi      r3, r30, 0
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0x4
	  bl        0x60D34
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0xF
	  li        r6, 0xF
	  li        r7, 0xF
	  bl        0x60698
	  addi      r3, r30, 0
	  li        r4, 0x7
	  li        r5, 0
	  li        r6, 0x5
	  li        r7, 0x7
	  bl        0x60700
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x60768
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x6080C
	  addi      r30, r30, 0x1

	.loc_0x474:
	  rlwinm    r3,r30,0,24,31
	  bl        0x60E60
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0xF
	  bl        0x61134

	.loc_0x490:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B2B3C
 * Size:	000014
 */
void P2DPicture::swap(f32& val1, f32& val2)
{
	f32 tmp = val1;
	val1    = val2;
	val2    = tmp;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00017C
 */
void P2DPicture::drawTest()
{
	// UNUSED FUNCTION
}
