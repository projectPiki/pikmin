#include "MovSampleSection.h"
#include "Dolphin/gx.h"
#include "jaudio/app_inter.h"
#include "jaudio/piki_scene.h"
#include "Graphics.h"
#include "FlowController.h"
#include "sysNew.h"
#include "DebugLog.h"

u16 ImgH;
u16 ImgW;
GXTexObj YtexObj;
GXTexObj UVtexObj;
OSThread playbackThread;
u8 playbackThreadStack[0x1000];
bool finishPlayback;

static void* playbackFunc(void*);

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
DEFINE_PRINT("MovSample")

/**
 * @brief TODO
 */
struct MovSampleSetupSection : public Node {
	MovSampleSetupSection()
	{
		mName       = "MovSample section";
		mController = new Controller;
		_28         = 160;
		_30         = 0;
		gsys->setFade(1.0f, 3.0f);

		static char* movieNames[6] = { "../MovieData/cntA_S.h4m", "../MovieData/cntB_S.h4m", "../MovieData/cntC_S.h4m",
			                           "../MovieData/cntD_S.h4m", "../MovieData/sr_S.h4m",   "../MovieData/srhp_S.h4m" };
		int size                   = 0xe00000;
		u8* store                  = new (0x20) u8[size];
		Jac_StreamMovieInit(movieNames[gameflow.mIntroMovieId], store, size);
		ImgW      = 640;
		ImgH      = 480;
		int size2 = 0x70800;
		_48[0]    = new (0x20) u8[size2];
		_48[1]    = new (0x20) u8[size2];
		for (int i = 0; i < 2; i++) {
			void* dest  = _48[i];
			void* dest2 = &_48[i][ImgW * ImgH];
			memset(dest, 0x10, ImgW * ImgH);
			memset(dest2, 0x80, (ImgW / 2) * (ImgH / 2) * 2);
		}
		OSCreateThread(&playbackThread, &playbackFunc, 0, &playbackThreadStack[0x1000], 0x1000, 0x14, 1);
		finishPlayback = false;
		OSResumeThread(&playbackThread);
	}

	virtual void update() // _10 (weak)
	{
		mController->update();

		int pic = 0;
		u8* a   = nullptr;
		int b, c;
		if (gsys->mDvdErrorCode < DvdError::ReadingDisc) { // AKA: DvdError::None (no issue)
			pic = Jac_StreamMovieGetPicture(&a, &b, &c);
		}

		if (a && pic) {
			convHVQM4TexY8UV8(b, c, a, _48[_3C ^ 1]);
			_3C ^= 1;
		}

		bool check = false;
		if (flowCont._244 == 0 && mController->keyClick(KBBTN_START | KBBTN_A | KBBTN_B)) {
			check = true;
		}

		if (check || pic == -1) {
			Jac_StreamMovieStop();
			OSCancelThread(&playbackThread);

			if (flowCont._244) {
				Jac_SceneExit(13, 0);
				flowCont._244 = 0;
			}

			gameflow.mGameSectionID = SECTION_Titles;
			gsys->softReset();
		}

		STACK_PAD_VAR(1);
	}
	virtual void draw(Graphics& gfx) // _14 (weak)
	{
		// NON-MATCHING
		gfx.setViewport(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setScissor(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
		gfx.setClearColour(Colour(0, 0, 0, 0));
		gfx.clearBuffer(3, false);
		Matrix4f mtx;
		STACK_PAD_VAR(64);
		gfx.setOrthogonal(mtx.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

		GXSetNumTexGens(2);
		GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3X4, GX_TG_TEX0, 60, 0, 125);
		GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX3X4, GX_TG_TEX0, 60, 0, 125);
		GXInvalidateTexAll();
		GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_CLEAR);
		GXSetNumTevStages(4);

		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_KONST, GX_CC_C0);
		GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
		GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_TEXA, GX_CA_KONST, GX_CA_A0);
		GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
		GXSetTevKColorSel(GX_TEVSTAGE0, GX_TEV_KCSEL_K0);
		GXSetTevKAlphaSel(GX_TEVSTAGE0, GX_TEV_KASEL_K0_A);
		GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP1);

		GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR_NULL);
		GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_TEXC, GX_CC_KONST, GX_CC_CPREV);
		GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_2, GX_FALSE, GX_TEVPREV);
		GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_TEXA, GX_CA_KONST, GX_CA_APREV);
		GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_2, GX_FALSE, GX_TEVPREV);
		GXSetTevKColorSel(GX_TEVSTAGE1, GX_TEV_KCSEL_K1);
		GXSetTevKAlphaSel(GX_TEVSTAGE1, GX_TEV_KASEL_K1_A);
		GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);

		GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
		GXSetTevColorIn(GX_TEVSTAGE2, GX_CC_ZERO, GX_CC_TEXC, GX_CC_KONST, GX_CC_CPREV);
		GXSetTevColorOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_ZERO, GX_CA_TEXA, GX_CA_KONST, GX_CA_APREV);
		GXSetTevAlphaOp(GX_TEVSTAGE2, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevKColorSel(GX_TEVSTAGE2, GX_TEV_KCSEL_K2);
		GXSetTevKAlphaSel(GX_TEVSTAGE2, GX_TEV_KASEL_K2_A);
		GXSetTevSwapMode(GX_TEVSTAGE2, GX_TEV_SWAP0, GX_TEV_SWAP2);

		GXSetTevOrder(GX_TEVSTAGE3, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		GXSetTevColorIn(GX_TEVSTAGE3, GX_CC_CPREV, GX_CC_APREV, GX_CC_KONST, GX_CC_ZERO);
		GXSetTevColorOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevAlphaIn(GX_TEVSTAGE3, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
		GXSetTevAlphaOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevSwapMode(GX_TEVSTAGE3, GX_TEV_SWAP0, GX_TEV_SWAP0);
		GXSetTevKColorSel(GX_TEVSTAGE3, GX_TEV_KCSEL_K3);

		setTevColors();

		GXSetTevSwapModeTable(GX_TEV_SWAP0, GX_CH_RED, GX_CH_GREEN, GX_CH_BLUE, GX_CH_ALPHA);
		GXSetTevSwapModeTable(GX_TEV_SWAP1, GX_CH_RED, GX_CH_ALPHA, GX_CH_ALPHA, GX_CH_ALPHA);
		GXSetTevSwapModeTable(GX_TEV_SWAP2, GX_CH_RED, GX_CH_RED, GX_CH_ALPHA, GX_CH_RED);

		u8* data = _48[_3C];
		GXInitTexObj(&YtexObj, data, ImgW, ImgH, GX_TF_I8, GX_CLAMP, GX_CLAMP, GX_FALSE);
		GXInitTexObjLOD(&YtexObj, GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
		GXLoadTexObj(&YtexObj, GX_TEXMAP1);

		GXInitTexObj(&UVtexObj, &data[ImgW * ImgH], ImgW / 2, ImgH / 2, GX_TF_IA8, GX_CLAMP, GX_CLAMP, GX_FALSE);
		GXInitTexObjLOD(&UVtexObj, GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
		GXLoadTexObj(&UVtexObj, GX_TEXMAP0);

		gfx.setColour(Colour(255, 255, 255, 255), true);

		// WHY WONT YOU USE DIFFERENT REGISTERS
		gfx.testRectangle(RectArea(0, 0, 640, 480));

		GXSetTevSwapModeTable(GX_TEV_SWAP0, GX_CH_RED, GX_CH_GREEN, GX_CH_BLUE, GX_CH_ALPHA);
		GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
		GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
		GXSetTevSwapMode(GX_TEVSTAGE2, GX_TEV_SWAP0, GX_TEV_SWAP0);
		GXSetTevSwapMode(GX_TEVSTAGE3, GX_TEV_SWAP0, GX_TEV_SWAP0);

		gfx.setColour(Colour(255, 255, 64, 255), true);
		gfx.setAuxColour(Colour(255, 0, 64, 255));

		gameflow.drawLoadLogo(gfx, false, gameflow.mLevelBannerTexture, gameflow.mLevelBannerFadeValue);
	}

	// not in the DLL, but needed for stack ordering
	void setTevColors()
	{
		GXSetTevColorS10(GX_TEVREG0, (GXColorS10) { 0xFF91, 0x00, 0xFF76, 0x44 });
		GXSetTevKColor(GX_KCOLOR0, (GXColor) { 0x66, 0, 0xFF, 0x32 });
		GXSetTevKColor(GX_KCOLOR1, (GXColor) { 0x94, 0, 0x94, 0x94 });
		GXSetTevKColor(GX_KCOLOR2, (GXColor) { 0xCB, 0, 5, 0xCF });
		GXSetTevKColor(GX_KCOLOR3, (GXColor) { 0, 0xFF, 0, 0 });
	}

	// _00     = VTBL
	// _00-_20 = Node
	int _20;                 // _20
	int _24;                 // _24
	int _28;                 // _28
	Controller* mController; // _2C
	int _30;                 // _30
	int _34;                 // _34
	int _38;                 // _38
	int _3C;                 // _3C
	int _40;                 // _40
	int _44;                 // _44
	u8* _48[2];              // _48
};

/*
 * --INFO--
 * Address:	80077EF0
 * Size:	0003F0
 */
void convHVQM4TexY8UV8(int stride, int height, u8* src, u8* dst)
{
	u32* out;
	int i, j;

	// Part 1: Y plane processing
	u32* y0 = (u32*)src;
	u32* y1 = y0 + (stride / 4);
	u32* y2 = y1 + (stride / 4);
	u32* y3 = y2 + (stride / 4);

	for (i = height, out = (u32*)dst; i > 0; i -= 4) {
		for (j = stride; j > 0; j -= 8) {
			out[0] = y0[0];
			out[1] = y0[1];
			out[2] = y1[0];
			out[3] = y1[1];
			out[4] = y2[0];
			out[5] = y2[1];
			out[6] = y3[0];
			out[7] = y3[1];

			y0 += 2;
			y1 += 2;
			y2 += 2;
			y3 += 2;
			out += 8;
		}

		// advance to next 4 lines
		y0 = y3;
		y1 = y0 + (stride / 4);
		y2 = y1 + (stride / 4);
		y3 = y2 + (stride / 4);
	}

	// Part 2: UV plane processing
	u8* srcuv = src + (stride * height);

	// base pointers for four lines of U and V
	u8* u0 = srcuv;
	u8* u1 = u0 + (stride / 2);
	u8* u2 = u1 + (stride / 2);
	u8* u3 = u2 + (stride / 2);

	u8* v0 = srcuv + ((stride / 2) * (height / 2));
	u8* v1 = v0 + (stride / 2);
	u8* v2 = v1 + (stride / 2);
	u8* v3 = v2 + (stride / 2);

	out = (u32*)(dst + (stride * height));

	for (i = height / 2; i > 0; i -= 4) {
		for (j = stride / 2; j > 0; j -= 4) {
			// two packed pixels per line per iteration
			// Line 0
			out[0] = ((u32)u0[0] << 24) | ((u32)v0[0] << 16) | ((u32)u0[1] << 8) | ((u32)v0[1]);
			out[1] = ((u32)u0[2] << 24) | ((u32)v0[2] << 16) | ((u32)u0[3] << 8) | ((u32)v0[3]);
			u0 += 4;
			v0 += 4;

			// Line 1
			out[2] = ((u32)u1[0] << 24) | ((u32)v1[0] << 16) | ((u32)u1[1] << 8) | ((u32)v1[1]);
			out[3] = ((u32)u1[2] << 24) | ((u32)v1[2] << 16) | ((u32)u1[3] << 8) | ((u32)v1[3]);
			u1 += 4;
			v1 += 4;

			// Line 2
			out[4] = ((u32)u2[0] << 24) | ((u32)v2[0] << 16) | ((u32)u2[1] << 8) | ((u32)v2[1]);
			out[5] = ((u32)u2[2] << 24) | ((u32)v2[2] << 16) | ((u32)u2[3] << 8) | ((u32)v2[3]);
			u2 += 4;
			v2 += 4;

			// Line 3
			out[6] = ((u32)u3[0] << 24) | ((u32)v3[0] << 16) | ((u32)u3[1] << 8) | ((u32)v3[1]);
			out[7] = ((u32)u3[2] << 24) | ((u32)v3[2] << 16) | ((u32)u3[3] << 8) | ((u32)v3[3]);
			u3 += 4;
			v3 += 4;

			out += 8;
		}

		// advance to next block of 4 UV lines
		u0 = u3;
		u1 = u0 + (stride / 2);
		u2 = u1 + (stride / 2);
		u3 = u2 + (stride / 2);

		v0 = v3;
		v1 = v0 + (stride / 2);
		v2 = v1 + (stride / 2);
		v3 = v2 + (stride / 2);
	}

	DCStoreRange(dst, (stride * height) + ((stride / 2) * (height / 2)) * 2);
}

/*
 * --INFO--
 * Address:	800782E0
 * Size:	000034
 */
static void* playbackFunc(void*)
{
	while (!finishPlayback) {
		Jac_StreamMovieUpdate();
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	80078314
 * Size:	000258
 */
void MovSampleSection::init()
{
	Node::init("<MovSampleSection>");
	gsys->setFrameClamp(1);
	gsys->mTimerState = 0;
	gsys->startLoading(nullptr, true, 60);

	add(new MovSampleSetupSection);
	gsys->endLoading();
}
