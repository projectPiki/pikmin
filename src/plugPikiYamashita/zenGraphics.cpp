#include "Colour.h"
#include "Dolphin/gx.h"
#include "NaviMgr.h"
#include "nlib/Math.h"
#include "zen/Graphics.h"
#include "zen/Math.h"

const f32 zen::DrawLifeCircle::TRI_NUM = 128.0f;

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void zen::zenGraphics::drawOneTri(immut Vector3f* vertices, immut Colour& color)
{
	GXBegin(GX_TRIANGLEFAN, GX_VTXFMT0, 3);
	u32 gxColor = *reinterpret_cast<immut u32*>(&color);
	for (int i = 0; i < 3; i++, vertices++) {
		GXPosition3f32(vertices->x, vertices->y, vertices->z);
		GXColor1u32(gxColor);
	}
	GXEnd();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void zen::zenGraphics::setTevFillPolygon()
{
	GXSetNumTevStages(1);
	GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
	GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
	GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_VTX, 0, GX_DF_NONE, GX_AF_NONE);
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX0, GX_NONE);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
}

void zen::DrawLifeCircle::drawLifeCircle(f32 healthRatio)
{
	Vector3f vecs[3];
	Colour color;
	zenGraphics::setTevFillPolygon();
	int drawCount = RoundOff(TRI_NUM * healthRatio);

	if (mDisplayedTriCount != drawCount) {
		f32 v;
		if (drawCount < mDisplayedTriCount) {
			v = 0.02f;
		} else {
			v = 0.05f;
		}

		mUpdateTimer += gsys->getFrameTime();
		if (mUpdateTimer > v) {
			int a = RoundOff(gsys->getFrameTime() * 30.0f) * (mDisplayedTriCount < drawCount ? 1 : -1);
			if (Abs(mDisplayedTriCount - drawCount) < Abs(a)) {
				a = Abs(mDisplayedTriCount - drawCount) * (mDisplayedTriCount < drawCount ? 1 : -1);
			}
			mDisplayedTriCount += a;
			mUpdateTimer -= v;
		}
	}

	if (healthRatio < 0.2f) {
		color.set(255, 0, 0, 255); // red for low health
	} else if (healthRatio < 0.5f) {
		color.set(255, 255, 0, 255); // yellow for middling health
	} else {
		color.set(0, 255, 0, 255); // green for good health
	}

	vecs[0].x = mRadius + 0.0f;
	vecs[0].y = mRadius + 0.0f;
	vecs[0].z = 0.0f;

	for (int i = 0; i < mDisplayedTriCount; i++) {
		f32 angle = -HALF_PI - 1.0f / TRI_NUM * f32(i) * TAU;
		vecs[1].x = NMathF::cos(angle) * mRadius + vecs[0].x;
		vecs[1].y = NMathF::sin(angle) * mRadius + vecs[0].y;
		vecs[1].z = 0.0f + vecs[0].z;

		angle     = -HALF_PI - 1.0f / TRI_NUM * f32(i + 1) * TAU;
		vecs[2].x = NMathF::cos(angle) * mRadius + vecs[0].x;
		vecs[2].y = NMathF::sin(angle) * mRadius + vecs[0].y;
		vecs[2].z = 0.0f + vecs[0].z;

		zenGraphics::drawOneTri(vecs, color);
	}
}

void zen::DrawNaviLifeCircle::drawLifeCircle()
{
	if (naviMgr) {
		Navi* navi = naviMgr->getNavi(mNaviIndex);
		DrawLifeCircle::drawLifeCircle(navi->mHealth / C_NAVI_PROP(navi).mHealth()); // ratio of current health to parameter health
	} else {
		DrawLifeCircle::drawLifeCircle(1.0f);
	}
}
