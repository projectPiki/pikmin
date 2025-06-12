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
DEFINE_ERROR()

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
		if (gsys->mDvdErrorCode < 0) {
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
	int i, j;
	// Part 1: Y plane processing
	u32* y0 = (u32*)src;         // r11
	u32* y1 = y0 + (stride / 4); // r0
	u32* y2 = y1 + (stride / 4); // r7
	u32* y3 = y2 + (stride / 4); // r26
	u32* dy = (u32*)dst;         // r9

	for (i = height; i > 0; i -= 4) {
		for (j = 0; j < stride; j += 8) {
			dy[0] = y0[0];
			dy[1] = y0[1];
			dy[2] = y1[0];
			dy[3] = y1[1];
			dy[4] = y2[0];
			dy[5] = y2[1];
			dy[6] = y3[0];
			dy[7] = y3[1];

			y0 += 2;
			y1 += 2;
			y2 += 2;
			y3 += 2;
			dy += 8;
		}

		// advance to next 4 lines
		y0 = y3;
		y1 = y0 + (stride / 4);
		y2 = y1 + (stride / 4);
		y3 = y2 + (stride / 4);
	}

	// Part 2: UV plane processing
	// base pointers for four lines of U and V
	u8* u0 = src + (stride * height); // r4
	u8* u1 = u0 + (stride / 2);
	u8* u2 = u1 + (stride / 2);
	u8* u3 = u2 + (stride / 2);

	u8* v0 = src + (stride * height) + ((stride / 2) * (height / 2)); // r8/r9
	u8* v1 = v0 + (stride / 2);
	u8* v2 = v1 + (stride / 2);
	u8* v3 = v2 + (stride / 2);

	u32* duv = (u32*)(dst + (stride * height));

	for (i = height / 2; i > 0; i -= 4) {
		for (j = 0; j < (stride / 2); j += 4) {
			// two packed pixels per line per iteration
			// Line 0
			duv[0] = ((u32)u0[0] << 24) | ((u32)v0[0] << 16) | ((u32)u0[1] << 8) | ((u32)v0[1]);
			duv[1] = ((u32)u0[2] << 24) | ((u32)v0[2] << 16) | ((u32)u0[3] << 8) | ((u32)v0[3]);
			u0 += 4;
			v0 += 4;

			// Line 1
			duv[2] = ((u32)u1[0] << 24) | ((u32)v1[0] << 16) | ((u32)u1[1] << 8) | ((u32)v1[1]);
			duv[3] = ((u32)u1[2] << 24) | ((u32)v1[2] << 16) | ((u32)u1[3] << 8) | ((u32)v1[3]);
			u1 += 4;
			v1 += 4;

			// Line 2
			duv[4] = ((u32)u2[0] << 24) | ((u32)v2[0] << 16) | ((u32)u2[1] << 8) | ((u32)v2[1]);
			duv[5] = ((u32)u2[2] << 24) | ((u32)v2[2] << 16) | ((u32)u2[3] << 8) | ((u32)v2[3]);
			u2 += 4;
			v2 += 4;

			// Line 3
			duv[6] = ((u32)u3[0] << 24) | ((u32)v3[0] << 16) | ((u32)u3[1] << 8) | ((u32)v3[1]);
			duv[7] = ((u32)u3[2] << 24) | ((u32)v3[2] << 16) | ((u32)u3[3] << 8) | ((u32)v3[3]);
			u3 += 4;
			v3 += 4;

			duv += 8;
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

	/*
	.loc_0x0:
	  mflr      r0
	  addi      r11, r5, 0
	  stw       r0, 0x4(r1)
	  srawi     r0, r3, 0x2
	  addze     r0, r0
	  stwu      r1, -0x38(r1)
	  rlwinm    r8,r0,2,0,29
	  add       r0, r5, r8
	  stmw      r25, 0x1C(r1)
	  add       r7, r0, r8
	  mr        r12, r0
	  addi      r25, r7, 0
	  addi      r10, r4, 0
	  addi      r9, r6, 0
	  add       r26, r7, r8
	  b         .loc_0x1F4

	.loc_0x40:
	  cmpwi     r3, 0
	  addi      r7, r3, 0x7
	  rlwinm    r7,r7,29,3,31
	  ble-      .loc_0x1D8
	  rlwinm.   r0,r7,30,2,31
	  mtctr     r0
	  beq-      .loc_0x17C

	.loc_0x5C:
	  lwz       r0, 0x0(r11)
	  stw       r0, 0x0(r9)
	  lwz       r0, 0x4(r11)
	  stw       r0, 0x4(r9)
	  lwz       r0, 0x0(r12)
	  stw       r0, 0x8(r9)
	  lwz       r0, 0x4(r12)
	  stw       r0, 0xC(r9)
	  lwz       r0, 0x0(r25)
	  stw       r0, 0x10(r9)
	  lwz       r0, 0x4(r25)
	  stw       r0, 0x14(r9)
	  lwz       r0, 0x0(r26)
	  stw       r0, 0x18(r9)
	  lwz       r0, 0x4(r26)
	  stw       r0, 0x1C(r9)
	  lwz       r0, 0x8(r11)
	  stw       r0, 0x20(r9)
	  lwz       r0, 0xC(r11)
	  stw       r0, 0x24(r9)
	  lwz       r0, 0x8(r12)
	  stw       r0, 0x28(r9)
	  lwz       r0, 0xC(r12)
	  stw       r0, 0x2C(r9)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x30(r9)
	  lwz       r0, 0xC(r25)
	  stw       r0, 0x34(r9)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x38(r9)
	  lwz       r0, 0xC(r26)
	  stw       r0, 0x3C(r9)
	  lwz       r0, 0x10(r11)
	  stw       r0, 0x40(r9)
	  lwz       r0, 0x14(r11)
	  stw       r0, 0x44(r9)
	  lwz       r0, 0x10(r12)
	  stw       r0, 0x48(r9)
	  lwz       r0, 0x14(r12)
	  stw       r0, 0x4C(r9)
	  lwz       r0, 0x10(r25)
	  stw       r0, 0x50(r9)
	  lwz       r0, 0x14(r25)
	  stw       r0, 0x54(r9)
	  lwz       r0, 0x10(r26)
	  stw       r0, 0x58(r9)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x5C(r9)
	  lwz       r0, 0x18(r11)
	  stw       r0, 0x60(r9)
	  lwz       r0, 0x1C(r11)
	  addi      r11, r11, 0x20
	  stw       r0, 0x64(r9)
	  lwz       r0, 0x18(r12)
	  stw       r0, 0x68(r9)
	  lwz       r0, 0x1C(r12)
	  addi      r12, r12, 0x20
	  stw       r0, 0x6C(r9)
	  lwz       r0, 0x18(r25)
	  stw       r0, 0x70(r9)
	  lwz       r0, 0x1C(r25)
	  addi      r25, r25, 0x20
	  stw       r0, 0x74(r9)
	  lwz       r0, 0x18(r26)
	  stw       r0, 0x78(r9)
	  lwz       r0, 0x1C(r26)
	  addi      r26, r26, 0x20
	  stw       r0, 0x7C(r9)
	  addi      r9, r9, 0x80
	  bdnz+     .loc_0x5C
	  andi.     r7, r7, 0x3
	  beq-      .loc_0x1D8

	.loc_0x17C:
	  mtctr     r7

	.loc_0x180:
	  lwz       r0, 0x0(r11)
	  stw       r0, 0x0(r9)
	  lwz       r0, 0x4(r11)
	  addi      r11, r11, 0x8
	  stw       r0, 0x4(r9)
	  lwz       r0, 0x0(r12)
	  stw       r0, 0x8(r9)
	  lwz       r0, 0x4(r12)
	  addi      r12, r12, 0x8
	  stw       r0, 0xC(r9)
	  lwz       r0, 0x0(r25)
	  stw       r0, 0x10(r9)
	  lwz       r0, 0x4(r25)
	  addi      r25, r25, 0x8
	  stw       r0, 0x14(r9)
	  lwz       r0, 0x0(r26)
	  stw       r0, 0x18(r9)
	  lwz       r0, 0x4(r26)
	  addi      r26, r26, 0x8
	  stw       r0, 0x1C(r9)
	  addi      r9, r9, 0x20
	  bdnz+     .loc_0x180

	.loc_0x1D8:
	  add       r0, r26, r8
	  add       r7, r0, r8
	  addi      r11, r26, 0
	  mr        r12, r0
	  addi      r25, r7, 0
	  add       r26, r7, r8
	  subi      r10, r10, 0x4

	.loc_0x1F4:
	  cmpwi     r10, 0
	  bgt+      .loc_0x40
	  srawi     r31, r3, 0x1
	  addze     r31, r31
	  srawi     r30, r4, 0x1
	  mullw     r0, r3, r4
	  addze     r30, r30
	  add       r4, r5, r0
	  add       r3, r4, r31
	  mullw     r29, r31, r30
	  add       r8, r4, r29
	  add       r10, r8, r31
	  add       r11, r10, r31
	  add       r7, r3, r31
	  addi      r5, r3, 0
	  addi      r9, r8, 0
	  add       r8, r7, r31
	  add       r12, r11, r31
	  add       r3, r6, r0
	  b         .loc_0x3C4

	.loc_0x244:
	  addi      r28, r31, 0x3
	  rlwinm    r28,r28,30,2,31
	  cmpwi     r31, 0
	  mtctr     r28
	  ble-      .loc_0x3A0

	.loc_0x258:
	  lbz       r25, 0x0(r9)
	  lbz       r26, 0x0(r4)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x1(r4)
	  rlwimi    r25,r26,24,0,7
	  lbz       r28, 0x1(r9)
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0x0(r3)
	  lbz       r25, 0x2(r9)
	  lbz       r28, 0x3(r9)
	  addi      r9, r9, 0x4
	  lbz       r26, 0x2(r4)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x3(r4)
	  rlwimi    r25,r26,24,0,7
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0x4(r3)
	  addi      r4, r4, 0x4
	  lbz       r25, 0x0(r10)
	  lbz       r26, 0x0(r5)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x1(r5)
	  rlwimi    r25,r26,24,0,7
	  lbz       r28, 0x1(r10)
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0x8(r3)
	  lbz       r25, 0x2(r10)
	  lbz       r28, 0x3(r10)
	  addi      r10, r10, 0x4
	  lbz       r26, 0x2(r5)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x3(r5)
	  rlwimi    r25,r26,24,0,7
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0xC(r3)
	  addi      r5, r5, 0x4
	  lbz       r25, 0x0(r11)
	  lbz       r26, 0x0(r7)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x1(r7)
	  rlwimi    r25,r26,24,0,7
	  lbz       r28, 0x1(r11)
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0x10(r3)
	  lbz       r25, 0x2(r11)
	  lbz       r28, 0x3(r11)
	  addi      r11, r11, 0x4
	  lbz       r26, 0x2(r7)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x3(r7)
	  rlwimi    r25,r26,24,0,7
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0x14(r3)
	  addi      r7, r7, 0x4
	  lbz       r25, 0x0(r12)
	  lbz       r26, 0x0(r8)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x1(r8)
	  rlwimi    r25,r26,24,0,7
	  lbz       r28, 0x1(r12)
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0x18(r3)
	  lbz       r28, 0x2(r12)
	  lbz       r25, 0x3(r12)
	  addi      r12, r12, 0x4
	  lbz       r27, 0x2(r8)
	  rlwinm    r28,r28,16,0,15
	  lbz       r26, 0x3(r8)
	  rlwimi    r28,r27,24,0,7
	  rlwimi    r28,r26,8,16,23
	  or        r28, r25, r28
	  stw       r28, 0x1C(r3)
	  addi      r3, r3, 0x20
	  addi      r8, r8, 0x4
	  bdnz+     .loc_0x258

	.loc_0x3A0:
	  add       r5, r8, r31
	  add       r10, r12, r31
	  add       r7, r5, r31
	  addi      r4, r8, 0
	  add       r11, r10, r31
	  addi      r9, r12, 0
	  add       r8, r7, r31
	  add       r12, r11, r31
	  subi      r30, r30, 0x4

	.loc_0x3C4:
	  cmpwi     r30, 0
	  bgt+      .loc_0x244
	  rlwinm    r4,r29,1,0,30
	  addi      r3, r6, 0
	  add       r4, r0, r4
	  bl        0x17E954
	  lmw       r25, 0x1C(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
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
