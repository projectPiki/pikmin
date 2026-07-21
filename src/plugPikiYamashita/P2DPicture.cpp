#include "DebugLog.h"
#include "Geometry.h"
#include "P2D/Picture.h"
#include "P2D/Stream.h"
#include "P2D/Util.h"
#include "Texture.h"
#include "zen/ogSub.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(35)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("P2DPicture")

/**
 * @todo: Documentation
 */
void P2DPicture::makeResident()
{
	for (int i = 0; i < mTextureCount; i++) {
		if (mTextures[i]) {
			mTextures[i]->makeResident();
		}
	}
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
P2DPicture::~P2DPicture()
{
	for (int i = 0; i < mTextureCount; i++) {
		if (mTextures[i] && _F2[i]) {
			delete mTextures[i];
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000058
 */
P2DPicture::P2DPicture()
{
	mTextures[0]  = nullptr;
	mTextureCount = 0;
	initinfo();
}

/**
 * @todo: Documentation
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
	_F2[0]        = true;
	setAlpha(255);
	initBlack();
	initWhite();
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
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
	_F2[idx]       = false;
	mTextureCount++;
	return true;
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
void P2DPicture::drawSelf(int x, int y)
{
	Matrix4f mtx;
	mtx.makeIdentity();
	drawSelf(x, y, &mtx);
}

/**
 * @todo: Documentation
 */
void P2DPicture::drawSelf(int x, int y, immut Matrix4f* mtx)
{
	if (mTextures[0]) {
		drawFullSet(mGlobalBounds.mMinX + x, mGlobalBounds.mMinY + y, getWidth(), getHeight(), mBinding, mMirror, mTumble, mWrapS, mWrapT,
		            mtx);
	}
}

/**
 * @todo: Documentation
 */
void P2DPicture::drawFullSet(int x, int y, int width, int height, P2DBinding binding, P2DMirror mirror, bool tumble, P2DWrapmode wrapS,
                             P2DWrapmode wrapT, immut Matrix4f* mtx)
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 00040C (Nonmatching)
 */
void P2DPicture::draw(int, int, int, int, bool, bool, bool)
{
	if (!IsVisible()) {
		return;
	}

	for (u8 i = 0; i < mTextureCount; ++i) {
		load(i);
	}

	// Presumably GX function calls follow this point.  Who knows which ones?
	// In the DLL, OpenGL function calls actually do follow past this point.
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0002F4 (Nonmatching)
 */
void P2DPicture::drawOut(const PUTRect&, const PUTRect&)
{
	if (!IsVisible()) {
		return;
	}

	for (u8 i = 0; i < mTextureCount; ++i) {
		load(i);
	}

	// Presumably GX function calls follow this point.  Who knows which ones?
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo: Documentation
 */
void P2DPicture::drawTexCoord(int x, int y, int width, int height, f32 uBL, f32 vBL, f32 uBR, f32 vBR, f32 uTL, f32 vTL, f32 uTR, f32 vTR,
                              immut Matrix4f* mtx)
{
	for (int i = 0; i < mTextureCount; i++) {
		load(i);
	}

	int xEnd = x + width;
	int yEnd = y + height;

#if PIKI_USE_DGX
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);

	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S16, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_POS_XYZ, GX_RGBA8, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_POS_XYZ, GX_F32, 0);
	GXSetNumTexGens(mTextureCount);

	Matrix4f mtx1;
	mtx->multiplyTo(mWorldMtx, mtx1);
	GXLoadPosMtxImm(mtx1.mMtx, 0);

	setTevMode();

	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	// bottom left
	GXPosition3s16(x, y, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2f32(uBL, vBL);

	// bottom right
	GXPosition3s16(xEnd, y, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2f32(uBR, vBR);

	// top right
	GXPosition3s16(xEnd, yEnd, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2f32(uTR, vTR);

	// top left
	GXPosition3s16(x, yEnd, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2f32(uTL, vTL);

	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_POS_XYZ, GX_U16, 15);

	GXEnd();
#endif
}

/**
 * @todo: Documentation
 */
void P2DPicture::setTevMode()
{
#if PIKI_USE_DGX
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
		GXSetTevColor(GX_TEVREG0, reinterpret_cast<GXColor&>(mBlack));
		GXSetTevColor(GX_TEVREG1, reinterpret_cast<GXColor&>(mWhite));
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
#endif
}

/**
 * @todo: Documentation
 */
void P2DPicture::swap(f32& val1, f32& val2)
{
	f32 tmp = val1;
	val1    = val2;
	val2    = tmp;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00017C (Nonmatching)
 */
void P2DPicture::drawTest()
{
	Texture* texture = mTextures[0];
	texture->makeResident();

	RectArea local_1c(mBounds.mMinX, mBounds.mMinY, mBounds.mMaxX, mBounds.mMaxY);
	RectArea local_2c(0, 0, texture->mWidth, texture->mHeight);
	Vector3f local_38(0.0f, 0.0f, 0.0f);

	// Presumably GX function calls follow this point.  Who knows which ones?
	TRAP_UNIMPLEMENTED;
}
