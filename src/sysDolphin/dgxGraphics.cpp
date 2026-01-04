#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Font.h"
#include "Graphics.h"
#include "Mesh.h"
#include "Shape.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("DGXGraphics")

GXRenderModeObj progressiveRenderMode = {
	VI_TVMODE_NTSC_PROG, // viTVmode
	640,                 // fbWidth
	480,                 // efbHeight
	480,                 // xfbHeight
	40,                  // viXOrigin
#if defined(VERSION_GPIP01_00)
	47, // viYOrigin
#else
	0, // viYOrigin
#endif
	640,           // viWidth
	480,           // viHeight
	VI_XFBMODE_SF, // xFBmode
	0,             // fiend_rendering
	0,             // aa
	{
	    { 6, 6 }, // sample_pattern
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	},
	{ 0, 0, 21, 22, 21, 0, 0 }, // vfilter
};
#if defined(VERSION_GPIP01_00)
GXRenderModeObj localGXPal528IntDf = {
	VI_TVMODE_PAL_INT, // viTVmode
	640,               // fbWidth
	528,               // efbHeight
	528,               // xfbHeight
	30,                // viXOrigin
	23,                // viYOrigin
	660,               // viWidth
	528,               // viHeight
	VI_XFBMODE_DF,     // xFBmode
	0,                 // fiend_rendering
	0,                 // aa
	{
	    { 6, 6 }, // sample_pattern
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	},
	{ 8, 8, 10, 12, 10, 8, 8 }, // vfilter
};
static GXRenderModeObj* sScreenMode[2] = { &localGXPal528IntDf, &progressiveRenderMode };
#else
GXRenderModeObj localNtsc480IntDf = {
	VI_TVMODE_NTSC_INT, // viTVmode
	640,                // fbWidth
	480,                // efbHeight
	480,                // xfbHeight
	40,                 // viXOrigin
	0,                  // viYOrigin
	640,                // viWidth
	480,                // viHeight
	VI_XFBMODE_DF,      // xFBmode
	0,                  // fiend_rendering
	0,                  // aa
	{
	    { 6, 6 }, // sample_pattern
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	    { 6, 6 },
	},
	{ 5, 6, 14, 14, 14, 6, 5 }, // vfilter
};
static GXRenderModeObj* sScreenMode[2] = { &localNtsc480IntDf, &progressiveRenderMode };
#endif

#if defined(VERSION_PIKIDEMO)
static int sFirstFrame = 2;
#else
static int sFirstFrame = 4;
#endif
static int kDefaultFifoSize = 0x60000;
static int kTempFifoSize    = 0x10000;
static int kDefaultDLSize   = 0x20000;
static bool sendMtxIndx     = true;
static bool sendTxUVIndx[8] = { true, false, false, false, false, false, false, false };

static u32 sFrameSize;
static int oldVerts;
static int oldNorms;
static int oldCols;
static int oldCull;
static int oldTevGroup;
static int frameNum;

static int oldTexs[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

GColor GColors[1];

static const char* mtxTypes[] = {
	"GX_TEXMTX0", "GX_TEXMTX1", "GX_TEXMTX2", "GX_TEXMTX3", "GX_TEXMTX4",  "GX_TEXMTX5",
	"GX_TEXMTX6", "GX_TEXMTX7", "GX_TEXMTX8", "GX_TEXMTX9", "GX_IDENTITY",
};
static const char* genSrcs[] = {
	"GX_TG_POS",       "GX_TG_NRM",       "GX_TG_BINRM",     "GX_TG_TANGENT",   "GX_TG_TEX0",      "GX_TG_TEX1",      "GX_TG_TEX2",
	"GX_TG_TEX3",      "GX_TG_TEX4",      "GX_TG_TEX5",      "GX_TG_TEX6",      "GX_TG_TEX7",      "GX_TG_TEXCOORD0", "GX_TG_TEXCOORD1",
	"GX_TG_TEXCOORD2", "GX_TG_TEXCOORD3", "GX_TG_TEXCOORD4", "GX_TG_TEXCOORD5", "GX_TG_TEXCOORD6", "GX_TG_COLOR0",    "GX_TG_COLOR1",
};

static GXVtxDescList meshVCD[] = {
	{ GX_VA_PNMTXIDX, GX_DIRECT }, { GX_VA_TEX0MTXIDX, GX_NONE }, { GX_VA_TEX1MTXIDX, GX_NONE }, { GX_VA_TEX2MTXIDX, GX_NONE },
	{ GX_VA_TEX3MTXIDX, GX_NONE }, { GX_VA_TEX4MTXIDX, GX_NONE }, { GX_VA_TEX5MTXIDX, GX_NONE }, { GX_VA_TEX6MTXIDX, GX_NONE },
	{ GX_VA_TEX7MTXIDX, GX_NONE }, { GX_VA_POS, GX_INDEX16 },     { GX_VA_NBT, GX_NONE },        { GX_VA_NRM, GX_INDEX16 },
	{ GX_VA_CLR0, GX_NONE },       { GX_VA_CLR1, GX_NONE },       { GX_VA_TEX0, GX_INDEX16 },    { GX_VA_TEX1, GX_NONE },
	{ GX_VA_TEX2, GX_NONE },       { GX_VA_TEX3, GX_NONE },       { GX_VA_TEX4, GX_NONE },       { GX_VA_TEX5, GX_NONE },
	{ GX_VA_TEX6, GX_NONE },       { GX_VA_TEX7, GX_NONE },       { GX_VA_NULL, GX_NONE },
};

static GXVtxAttrFmtList meshVAT[] = {
	{ GX_VA_POS, GX_POS_XYZ, GX_F32, 0 }, { GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0 }, { GX_VA_TEX0, GX_TEX_ST, GX_F32, 0 },
	{ GX_VA_TEX1, GX_TEX_ST, GX_F32, 0 }, { GX_VA_TEX2, GX_TEX_ST, GX_F32, 0 }, { GX_VA_TEX3, GX_TEX_ST, GX_F32, 0 },
	{ GX_VA_TEX4, GX_TEX_ST, GX_F32, 0 }, { GX_VA_TEX5, GX_TEX_ST, GX_F32, 0 }, { GX_VA_TEX6, GX_TEX_ST, GX_F32, 0 },
	{ GX_VA_TEX7, GX_TEX_ST, GX_F32, 0 }, { GX_VA_NULL, GX_TEX_ST, GX_S16, 0 },
};

/**
 * @todo: Documentation
 */
DGXGraphics::DGXGraphics(bool flag)
{
	mDefaultFifoBuffer = new (0x20) u8[kDefaultFifoSize];
	mTempFifoBuffer    = new (0x20) u8[kTempFifoSize];
	mDefaultDLBuffer   = new (0x20) u8[kDefaultDLSize];
	mGpFifo            = GXInit(mDefaultFifoBuffer, kDefaultFifoSize);

	if (flag) {
		mRenderMode = 1;
	} else {
		mRenderMode = 0;
	}

	mScreenWidth = sScreenMode[mRenderMode]->fbWidth;
#if defined(VERSION_GPIP01_00)
	mScreenHeight = 480;

	GXSetDispCopySrc(0, 0, sScreenMode[mRenderMode]->fbWidth, mScreenHeight);
	GXSetDispCopyDst(sScreenMode[mRenderMode]->fbWidth, sScreenMode[mRenderMode]->xfbHeight);
	GXSetDispCopyYScale(1.1f);
#else
	mScreenHeight = sScreenMode[mRenderMode]->efbHeight;
	GXSetDispCopySrc(0, 0, sScreenMode[mRenderMode]->fbWidth, sScreenMode[mRenderMode]->efbHeight);
	GXSetDispCopyDst(sScreenMode[mRenderMode]->fbWidth, sScreenMode[mRenderMode]->xfbHeight);
	GXSetDispCopyYScale((f32)sScreenMode[mRenderMode]->xfbHeight / (f32)sScreenMode[mRenderMode]->efbHeight);
#endif
	GXSetCopyFilter(sScreenMode[mRenderMode]->aa, sScreenMode[mRenderMode]->sample_pattern, GX_TRUE, sScreenMode[mRenderMode]->vfilter);

	if (sScreenMode[mRenderMode]->aa) {
		GXSetPixelFmt(GX_PF_RGB565_Z16, GX_ZC_LINEAR);
	} else {
		GXSetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
	}

	VIInit();
	videoReset();

#if defined(VERSION_GPIP01_00)
	sFrameSize = (sScreenMode[mRenderMode]->fbWidth + 0xf & 0xfff0) * (sScreenMode[mRenderMode]->xfbHeight + 2) * 2;
#else
	sFrameSize = (sScreenMode[mRenderMode]->fbWidth + 0xf & 0xfff0) * sScreenMode[mRenderMode]->xfbHeight * 2;
#endif

#if defined(VERSION_PIKIDEMO)
	VISetBlack(TRUE);
	VIFlush();
	VIWaitForRetrace();
	VIWaitForRetrace();
#endif

	int backup = gsys->getHeap(gsys->mActiveHeapIdx)->mAllocType;
	gsys->getHeap(gsys->mActiveHeapIdx)->setAllocType(AYU_STACK_GROW_UP);

	mDisplayBuffer = new (0x20) u8[sFrameSize];
	u16* test      = (u16*)mDisplayBuffer;
	for (int i = 0; i < sFrameSize / 2; i++) {
		test[i] = 0x1080;
	}

	DCFlushRange(mDisplayBuffer, sFrameSize);
	gsys->getHeap(gsys->mActiveHeapIdx)->mAllocType = backup;
#if defined(VERSION_PIKIDEMO)
	VISetNextFrameBuffer(mDisplayBuffer);
#else
	VISetBlack(TRUE);
	VISetNextFrameBuffer(mDisplayBuffer);
	VIFlush();
	VIWaitForRetrace();
#endif
	setupRender();
	gfx                   = this;
	mPostRetraceWaitCount = 0;
	mRetraceCount         = VIGetRetraceCount();
	mSystemFrameRate      = gsys->mFrameRate;
	mRetraceCallback      = VISetPostRetraceCallback(retraceProc);
	OSInitMessageQueue(&mPostRetraceMsgQueue, &mPostRetraceMsgBuffer, 1);

	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setVerticalFilter(u8* vf)
{
	sScreenMode[mRenderMode]->vfilter[0] = vf[0];
	sScreenMode[mRenderMode]->vfilter[1] = vf[1];
	sScreenMode[mRenderMode]->vfilter[2] = vf[2];
	sScreenMode[mRenderMode]->vfilter[3] = vf[3];
	sScreenMode[mRenderMode]->vfilter[4] = vf[4];
	sScreenMode[mRenderMode]->vfilter[5] = vf[5];
	sScreenMode[mRenderMode]->vfilter[6] = vf[6];
}

/**
 * @todo: Documentation
 */
void DGXGraphics::getVerticalFilter(u8* vf)
{
	vf[0] = sScreenMode[mRenderMode]->vfilter[0];
	vf[1] = sScreenMode[mRenderMode]->vfilter[1];
	vf[2] = sScreenMode[mRenderMode]->vfilter[2];
	vf[3] = sScreenMode[mRenderMode]->vfilter[3];
	vf[4] = sScreenMode[mRenderMode]->vfilter[4];
	vf[5] = sScreenMode[mRenderMode]->vfilter[5];
	vf[6] = sScreenMode[mRenderMode]->vfilter[6];
}

/**
 * @todo: Documentation
 */
void DGXGraphics::videoReset()
{
#if defined(VERSION_PIKIDEMO)
#else
	static int videoModeAsIs = -1;

	if (videoModeAsIs != mRenderMode) {
		videoModeAsIs = mRenderMode;
#endif
	sFirstFrame = 2;
#if defined(VERSION_GPIE01_00)
	__VIInit(mRenderMode == 0 ? VI_TVMODE_NTSC_INT : VI_TVMODE_NTSC_PROG);
#endif
	VIConfigure(sScreenMode[mRenderMode]);
	VIFlush();
	VIWaitForRetrace();
	VIWaitForRetrace();
#if defined(VERSION_PIKIDEMO)
#else
	}
#endif
}

/**
 * @todo: Documentation
 */
void DGXGraphics::resetCopyFilter()
{
	GXSetCopyFilter(sScreenMode[mRenderMode]->aa, sScreenMode[mRenderMode]->sample_pattern, GX_TRUE, sScreenMode[mRenderMode]->vfilter);
}

DGXGraphics* DGXGraphics::gfx;

static bool sendTxIndx;  // type unsure
static bool sendColIndx; // type unsure
static bool sendNbtIndx; // type unsure

/**
 * @todo: Documentation
 */
void DGXGraphics::setupRender()
{
	mRetraceCount    = VIGetRetraceCount();
	mDisplayListPtr  = mDefaultDLBuffer;
	mDisplayListSize = kDefaultDLSize;
}

/**
 * @todo: Documentation
 */
u8* DGXGraphics::getDListPtr()
{
	return mDisplayListPtr;
}

/**
 * @todo: Documentation
 */
u32 DGXGraphics::getDListRemainSize()
{
	return mDisplayListSize;
}

/**
 * @todo: Documentation
 */
void DGXGraphics::useDList(u32 num)
{
	mDisplayListSize -= num;
	mDisplayListPtr += num;
}

/**
 * @todo: Documentation
 */
u32 DGXGraphics::compileMaterial(Material* mat)
{
	if (!(mat->mFlags & MATFLAG_PVW)) {
		return 0;
	}

	gsys->mIsRendering;
	u8* dl               = gsys->mDGXGfx->getDListPtr();
	mat->mDisplayListPtr = dl;
	GXBeginDisplayList(dl, getDListRemainSize());

	if (mat->mPeInfo.mControlFlags & 1) {
		GXSetBlendMode((GXBlendMode)(mat->mPeInfo.mBlendModeFlags & 0xf), (GXBlendFactor)(mat->mPeInfo.mBlendModeFlags >> 4 & 0xf),
		               (GXBlendFactor)(mat->mPeInfo.mBlendModeFlags >> 8 & 0xf), (GXLogicOp)(mat->mPeInfo.mBlendModeFlags >> 12 & 0xf));

		GXSetAlphaCompare((GXCompare)(mat->mPeInfo.mAlphaCompareFlags & 0xF), (mat->mPeInfo.mAlphaCompareFlags >> 4 & 0xFF),
		                  (GXAlphaOp)(mat->mPeInfo.mAlphaCompareFlags >> 16 & 0xF),
		                  (GXCompare)(mat->mPeInfo.mAlphaCompareFlags >> 20 & 0xF), mat->mPeInfo.mAlphaCompareFlags >> 24 & 0xFF);

		GXSetZMode((mat->mPeInfo.mDepthTestFlags & 1) != 0, (GXCompare)(mat->mPeInfo.mDepthTestFlags >> 8 & 0xFF),
		           (mat->mPeInfo.mDepthTestFlags & 2) != 0);
	} else if (mat->mFlags & MATFLAG_INVERT_BLEND) {
		GXSetBlendMode(GX_BM_BLEND, GX_BL_ZERO, GX_BL_INVSRCCOL, GX_LO_CLEAR);
		GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
	} else if (mat->mFlags & MATFLAG_OPAQUE) {
		GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_COPY);
		GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
	} else if (mat->mFlags & MATFLAG_ALPHA_TEST) {
		GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_COPY);
		GXSetAlphaCompare(GX_GEQUAL, 0x80, GX_AOP_AND, GX_LEQUAL, 255);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
	} else if (mat->mFlags & MATFLAG_ALPHA_BLEND) {
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_COPY);
		GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
	}

	GXSetTevKColor(GX_KCOLOR0, *((GXColor*)&mat->mTevInfo->mKonstColors[0]));
	GXSetTevKColor(GX_KCOLOR1, *((GXColor*)&mat->mTevInfo->mKonstColors[1]));
	GXSetTevKColor(GX_KCOLOR2, *((GXColor*)&mat->mTevInfo->mKonstColors[2]));
	GXSetTevKColor(GX_KCOLOR3, *((GXColor*)&mat->mTevInfo->mKonstColors[3]));
	for (int i = 0; i < mat->mTevInfo->mTevStageCount; i++) {
		PVWTevStage& stage = mat->mTevInfo->mTevStages[i];
		GXSetTevColorIn((GXTevStageID)i, (GXTevColorArg)stage.mTevColorCombiner.mInArgA, (GXTevColorArg)stage.mTevColorCombiner.mInArgB,
		                (GXTevColorArg)stage.mTevColorCombiner.mInArgC, (GXTevColorArg)stage.mTevColorCombiner.mInArgD);
		GXSetTevColorOp((GXTevStageID)i, (GXTevOp)stage.mTevColorCombiner.mTevOp, (GXTevBias)stage.mTevColorCombiner.mBias,
		                (GXTevScale)stage.mTevColorCombiner.mScale, (GXBool)stage.mTevColorCombiner.mDoClamp,
		                (GXTevRegID)stage.mTevColorCombiner.mOutReg);
		GXSetTevAlphaIn((GXTevStageID)i, (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgA, (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgB,
		                (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgC, (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgD);
		GXSetTevAlphaOp((GXTevStageID)i, (GXTevOp)stage.mTevAlphaCombiner.mTevOp, (GXTevBias)stage.mTevAlphaCombiner.mBias,
		                (GXTevScale)stage.mTevAlphaCombiner.mScale, (GXBool)stage.mTevAlphaCombiner.mDoClamp,
		                (GXTevRegID)stage.mTevAlphaCombiner.mOutReg);
	}

	PVWLightingInfo* lightInfo = &mat->mLightingInfo;
	bool doCombined            = (mat->mLightingInfo.mCtrlFlag & LightingControlFlags::EnableColor0) != 0;
	if (lightInfo) {
		bool doEnableColor0 = (lightInfo->mCtrlFlag & LightingControlFlags::EnableColor0);
		u32 diffFnColor0    = (lightInfo->mCtrlFlag >> LightingControlFlags::DiffFnColor0Shift) & 0x3;
		u32 diffFnAlpha0    = (lightInfo->mCtrlFlag >> LightingControlFlags::DiffFnAlpha0Shift) & 0x3;
		bool doEnableAlpha0 = (lightInfo->mCtrlFlag & LightingControlFlags::EnableAlpha0);
		bool ambSrcColor0   = (lightInfo->mCtrlFlag & LightingControlFlags::AmbSrcColor0Vtx);
		bool ambSrcAlpha0   = (lightInfo->mCtrlFlag & LightingControlFlags::AmbSrcAlpha0Vtx);
		bool matSrcColor0   = (lightInfo->mCtrlFlag & LightingControlFlags::MatSrcColor0Vtx);
		bool matSrcAlpha0   = (lightInfo->mCtrlFlag & LightingControlFlags::MatSrcAlpha0Vtx);

		GXSetChanCtrl(GX_COLOR0, doEnableColor0, (GXColorSrc)ambSrcColor0, (GXColorSrc)matSrcColor0, 3, (GXDiffuseFn)diffFnColor0,
		              (!doEnableColor0) ? GX_AF_NONE : GX_AF_SPOT);
		GXSetChanCtrl(GX_ALPHA0, doEnableAlpha0, (GXColorSrc)ambSrcAlpha0, (GXColorSrc)matSrcAlpha0, 3, (GXDiffuseFn)diffFnAlpha0,
		              (!doEnableAlpha0) ? GX_AF_NONE : GX_AF_SPOT);

	} else {
		GXBool enable = doCombined;
		GXSetChanCtrl(GX_COLOR0A0, enable, GX_SRC_REG, GX_SRC_REG, 3, GX_DF_CLAMP, !doCombined ? GX_AF_NONE : GX_AF_SPOT);
	}

	int numChans = 1;
	if (lightInfo && lightInfo->mCtrlFlag & LightingControlFlags::EnableSpecular) {
		GXSetChanCtrl(GX_COLOR1, GX_TRUE, GX_SRC_REG, GX_SRC_REG, 0x80,
		              (GXDiffuseFn)((lightInfo->mCtrlFlag >> LightingControlFlags::DiffFnSpecularShift) & 0x3), GX_AF_SPEC);
		GXSetChanCtrl(GX_ALPHA1, GX_FALSE, GX_SRC_REG, GX_SRC_REG, 0x80, GX_DF_CLAMP, GX_AF_NONE);
		numChans = 2;
	} else {
		GXSetChanCtrl(GX_COLOR1A1, GX_FALSE, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_NONE, GX_AF_NONE);
	}

	mat->mLightingInfo.mNumChans = numChans;
	mat->mDisplayListSize        = GXEndDisplayList();
	return mat->mDisplayListSize;
}

/**
 * @todo: Documentation
 */
void DGXGraphics::initRender(int a1, int a2)
{
	frameNum++;
	Graphics::initRender(a1, a2);
	mLightIntensity = 1.0f;
	oldCull         = 0;
	GXSetCullMode(GX_CULL_BACK);
	GXSetCoPlanar(GX_FALSE);
	GXSetColorUpdate(GX_TRUE);
	GXSetDither(GX_FALSE);
	GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_NOOP);
	GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
	mIsDepthEnabled = true;
	GXSetZCompLoc(GX_FALSE);
	GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
	mLineWidth = 1.0f;
	GXSetLineWidth(mLineWidth * 6.0f, GX_TO_ZERO);
	GXSetPointSize(24, GX_TO_ZERO);
	mHasTexGen      = FALSE;
	mIsEnvMapActive = false;
	mCullFlip       = 0;
	useTexture(nullptr, GX_TEXMAP0);
	setMatHandler(nullptr);
	mRenderState      = (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk3);
	mCurrentMatrixId  = 0;
	mTexMtxBaseID     = 30;
	oldVerts          = 0;
	oldNorms          = 0;
	oldCols           = 0;
	oldTexs[0]        = 0;
	oldTexs[1]        = 0;
	oldTexs[2]        = 0;
	oldTexs[3]        = 0;
	oldTexs[4]        = 0;
	oldTexs[5]        = 0;
	oldTexs[6]        = 0;
	oldTexs[7]        = 0;
	mActiveTexture[0] = nullptr;
	mActiveTexture[1] = nullptr;
	mActiveTexture[2] = nullptr;
	mActiveTexture[3] = nullptr;
	mActiveTexture[4] = nullptr;
	mActiveTexture[5] = nullptr;
	mActiveTexture[6] = nullptr;
	mActiveTexture[7] = nullptr;
	mCustomScale      = 0;
	gsys->resetLFlares();
}

/**
 * @todo: Documentation
 */
void DGXGraphics::beginRender()
{
	gsys->mIsRendering; // volatile ints are very cool
	gsys->mIsRendering = 1;
	GXInvalidateTexAll();
	GXInvalidateVtxCache();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000084
 */
void DGXGraphics::GXReInit()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void DGXGraphics::doneRender()
{
	GXFlush();
	GXDrawDone();
	gsys->mIsRendering = 0;
}

/**
 * @todo: Documentation
 */
void DGXGraphics::waitRetrace()
{
	waitPostRetrace();
	if (sFirstFrame) {
		sFirstFrame--;
		if (sFirstFrame == 0) {
			sFirstFrame = 0;
		}
	}
	VIFlush();
	VIWaitForRetrace();
	GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);

	bool set = (gsys->mIsLoadScreenActive || gsys->mSoftResetPending) ? false : true;
	GXCopyDisp(mDisplayBuffer, set);

	mRetraceCount    = VIGetRetraceCount();
	mSystemFrameRate = gsys->mFrameRate;
}

/**
 * @todo: Documentation
 */
void DGXGraphics::waitPostRetrace()
{
	BOOL interrupt = OSDisableInterrupts();

	int a = mSystemFrameRate - (VIGetRetraceCount() - mRetraceCount) - 1;
	if (a > 0) {
		mPostRetraceWaitCount = a;
		OSReceiveMessage(&mPostRetraceMsgQueue, nullptr, OS_MESSAGE_BLOCK);
	}

	OSRestoreInterrupts(interrupt);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::retraceProc(u32)
{
	gsys->nudgeDvdThread();
	if (gsys->mIsLoadingActive) {
		gsys->nudgeLoading();
		return;
	}

	gsys->mRetraceCount++;
	if (gfx->mPostRetraceWaitCount != 0 && --gfx->mPostRetraceWaitCount == 0) {
		OSSendMessage(&gfx->mPostRetraceMsgQueue, (OSMessage)'DONE', 0);
	}
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setCamera(Camera* a1)
{
	mCamera = a1;
}

/**
 * @brief Transforms a given model matrix for an object from world space to the camera's view space.
 *
 * @param modelMtx Matrix for an object (in world space).
 * @param viewMtx Output matrix, now in view space.
 */
void DGXGraphics::calcViewMatrix(immut Matrix4f& modelMtx, Matrix4f& viewMtx)
{
	mLastModelMatrix = &modelMtx;
	mCamera->mLookAtMtx.multiplyTo(modelMtx, viewMtx);
}

/**
 * @todo: Documentation
 */
f32 DGXGraphics::setLineWidth(f32 width)
{
	f32 old    = mLineWidth;
	mLineWidth = width;
	GXSetLineWidth(mLineWidth * 6.0f, GX_TO_ZERO);
	return old;
}

/**
 * @todo: Documentation
 */
u8 DGXGraphics::setDepth(bool enabled)
{
	bool old        = mIsDepthEnabled;
	mIsDepthEnabled = enabled;
	if (!enabled) {
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
	} else {
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
	}
	return old;
}

/**
 * @todo: Documentation
 */
int DGXGraphics::setCullFront(int cull)
{
	mCullMode = cull;
	if (oldCull != mCullMode) {
		if (mCullMode == 1) {
			GXSetCullMode(GX_CULL_FRONT);
		} else if (mCullMode == 0) {
			GXSetCullMode(GX_CULL_BACK);
		} else {
			GXSetCullMode(GX_CULL_NONE);
		}
	}
	oldCull = mCullMode;
	return oldCull;
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setAmbient()
{
	GColors[0].mAmbColor.r = mAmbientFogColour.r;
	GColors[0].mAmbColor.g = mAmbientFogColour.g;
	GColors[0].mAmbColor.b = mAmbientFogColour.b;
	GColors[0].mAmbColor.a = f32(mAmbientFogColour.a) * mLightIntensity;

	GXSetChanAmbColor(GX_COLOR0A0, GColors[0].mAmbColor);
	GXSetChanMatColor(GX_COLOR1A1, GColors[0].mMatColor);
}

/**
 * @todo: Documentation
 */
bool DGXGraphics::setLighting(bool set, PVWLightingInfo* lightInfo)
{
	bool prevSetting   = mIsLightingEnabled;
	mIsLightingEnabled = set;
	if (lightInfo) {
		bool doEnableColor0 = (lightInfo->mCtrlFlag & LightingControlFlags::EnableColor0);
		u32 diffFnColor0    = (lightInfo->mCtrlFlag >> LightingControlFlags::DiffFnColor0Shift) & 0x3;
		u32 diffFnAlpha0    = (lightInfo->mCtrlFlag >> LightingControlFlags::DiffFnAlpha0Shift) & 0x3;
		bool doEnableAlpha0 = (lightInfo->mCtrlFlag & LightingControlFlags::EnableAlpha0);
		bool ambSrcColor0   = (lightInfo->mCtrlFlag & LightingControlFlags::AmbSrcColor0Vtx);
		bool ambSrcAlpha0   = (lightInfo->mCtrlFlag & LightingControlFlags::AmbSrcAlpha0Vtx);
		bool matSrcColor0   = (lightInfo->mCtrlFlag & LightingControlFlags::MatSrcColor0Vtx);
		bool matSrcAlpha0   = (lightInfo->mCtrlFlag & LightingControlFlags::MatSrcAlpha0Vtx);

		GXSetChanCtrl(GX_COLOR0, doEnableColor0, (GXColorSrc)ambSrcColor0, (GXColorSrc)matSrcColor0, mActiveLightMask,
		              (GXDiffuseFn)diffFnColor0, (!doEnableColor0) ? GX_AF_NONE : GX_AF_SPOT);
		GXSetChanCtrl(GX_ALPHA0, doEnableAlpha0, (GXColorSrc)ambSrcAlpha0, (GXColorSrc)matSrcAlpha0, mActiveLightMask,
		              (GXDiffuseFn)diffFnAlpha0, (!doEnableAlpha0) ? GX_AF_NONE : GX_AF_SPOT);

	} else {
		GXBool enable = set;
		GXSetChanCtrl(GX_COLOR0A0, enable, GX_SRC_REG, GX_SRC_REG, mActiveLightMask, GX_DF_CLAMP, !set ? GX_AF_NONE : GX_AF_SPOT);
	}

	int numChans = 1;
	if (lightInfo && lightInfo->mCtrlFlag & LightingControlFlags::EnableSpecular) {
		GXSetChanCtrl(GX_COLOR1, GX_TRUE, GX_SRC_REG, GX_SRC_REG, 0x80,
		              (GXDiffuseFn)((lightInfo->mCtrlFlag >> LightingControlFlags::DiffFnSpecularShift) & 0x3), GX_AF_SPEC);
		GXSetChanCtrl(GX_ALPHA1, GX_FALSE, GX_SRC_REG, GX_SRC_REG, 0x80, GX_DF_CLAMP, GX_AF_NONE);
		numChans = 2;
	} else {
		GXSetChanCtrl(GX_COLOR1A1, GX_FALSE, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_NONE, GX_AF_NONE);
	}

	GXSetNumChans(numChans);
	return prevSetting;
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setLight(Light* light, int idx)
{
	gsys->mLightSetNum++;
	GXLightObj* gxLight = &mGXLights[idx];
	GXInitLightAttn(gxLight, light->mSpotConstTerm, light->mSpotLinearTerm, light->mSpotQuadTerm, light->mConstantAttn, light->mLinearAttn,
	                light->mQuadAttn);
	Vector3f lightPos(light->mPosition);
	lightPos.multMatrix(mCamera->mLookAtMtx);
	GXInitLightPos(gxLight, lightPos.x, lightPos.y, lightPos.z);

	Vector3f lightDir;
	if (GET_LIGHT_TYPE(light->mLightFlag) == LIGHT_Spot) {
		lightDir = light->mDirection;
		lightDir.normalise();
		lightDir.rotate(mCamera->mLookAtMtx);
		GXInitLightDir(gxLight, lightDir.x, lightDir.y, lightDir.z);
	} else if (GET_LIGHT_TYPE(light->mLightFlag) == LIGHT_Parallel) {
		lightDir = light->mPosition;
		lightDir.normalise();
		lightDir.rotate(mCamera->mLookAtMtx);
		GXInitLightDir(gxLight, lightDir.x, lightDir.y, lightDir.z);
	}

	Colour lightColour = light->mDiffuseColour;
	if (idx == 7) {
		lightDir = light->mDirection;
		lightDir.normalise();
		lightDir.rotate(mCamera->mLookAtMtx);
		GXInitSpecularDir(gxLight, lightDir.x, lightDir.y, lightDir.z);
		GXInitLightAttn(gxLight, 0.0f, 0.0f, 1.0f, mLightDistance / 2.0f, 0.0f, 1.0f - (mLightDistance / 2.0f));
	}

	lightColour.a *= mLightIntensity;
	GXInitLightColor(gxLight, *(GXColor*)&lightColour);
	GXLoadLightObjImm(gxLight, GXLightID(1 << idx));
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setPerspective(Mtx mtx, f32 a1, f32 a2, f32 a3, f32 a4, f32 a5)
{
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
	C_MTXPerspective(mtx, a1, a2, a3, a4);
#else
	MTXPerspective(mtx, a1, a2, a3, a4);
#endif
	GXSetProjection(mtx, GX_PERSPECTIVE);
	f32 a     = 1.0f / (a4 - a3);
	mtx[2][2] = a * -(a4 + a3);
	mtx[2][3] = a * -(a4 * 2.0f * a3);
	GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
}

/**
 * @brief Constructs an orthogonal/projection matrix (in device coordinates) from the supplied bounds.
 *
 * Also sets up the graphics pipeline to be ready to display 2D elements properly.
 *
 * @param orthoMtx Output orthogonal matrix in device coordinates.
 * @param bounds Bounds to use when constructing the orthogonal matrix.
 */
void DGXGraphics::setOrthogonal(Mtx orthoMtx, immut RectArea& bounds)
{
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
	C_MTXOrtho(orthoMtx, bounds.mMinY, bounds.mMaxY, bounds.mMinX, bounds.mMaxX, 0.0f, -1.0f);
#else
	MTXOrtho(orthoMtx, bounds.mMinY, bounds.mMaxY, bounds.mMinX, bounds.mMaxX, 0.0f, -1.0f);
#endif
	GXSetProjection(orthoMtx, GX_ORTHOGRAPHIC);
	GXLoadPosMtxImm(Matrix4f::ident.mMtx, 0);
	GXSetCurrentMtx(0);
	GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, 1, GX_DF_NONE, GX_AF_NONE);
	GXSetNumChans(1);
	GXSetZMode(GX_FALSE, GX_LEQUAL, GX_TRUE);
	setScissor(bounds);
	setViewport(bounds);
	GXSetNumTexGens(1);
	GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3X4, GX_TG_TEX0, 0x3c, 0, 0x7d);
	useTexture(nullptr, GX_TEXMAP0);
	setFog(false);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setScissor(immut RectArea& bounds)
{
	GXSetScissor(bounds.mMinX, bounds.mMinY, bounds.width(), bounds.height());
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setViewport(immut RectArea& bounds)
{
	GXSetViewport(bounds.mMinX, bounds.mMinY, bounds.width(), bounds.height(), 0.0f, 1.0f);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setViewportOffset(immut RectArea& bounds)
{
	GXSetScissorBoxOffset(-bounds.mMinX, -bounds.mMinY);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::initReflectTex(bool)
{
}

/**
 * @todo: Documentation
 */
void DGXGraphics::initProjTex(bool set, LightCamera* cam)
{
	STACK_PAD_VAR(0x40);
	Mtx mtx;
	if (set) {
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
		C_MTXLightPerspective(mProjectionTextureMatrix, cam->mFov, cam->mAspectRatio, cam->mProjectionScale.x, -cam->mProjectionScale.y,
		                      0.5f, 0.5f);
#else
		MTXLightPerspective(mProjectionTextureMatrix, cam->mFov, cam->mAspectRatio, cam->mProjectionScale.x, -cam->mProjectionScale.y, 0.5f,
		                    0.5f);
#endif
		immut Matrix4f& camMtx = cam->mLookAtMtx;
		PSMTXConcat(mProjectionTextureMatrix, camMtx.mMtx, mProjectionTextureMatrix);
		PSMTXConcat(mProjectionTextureMatrix, Matrix4f::ident.mMtx, mtx);
		GXLoadTexMtxImm(mtx, 30, GX_MTX3x4);
		GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2X4, GX_TG_POS, 30, GX_FALSE, 125);
	} else {
		GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3X4, GX_TG_TEX0, 60, GX_FALSE, 125);
	}
}

/**
 * @todo: Documentation
 */
void DGXGraphics::useMatrixQuick(immut Matrix4f& mtx, int id)
{
	int gxID      = id * 3;
	mActiveMatrix = &mtx;
	GXLoadPosMtxImm(mtx.mMtx, gxID);

	if (mCustomScale) {
		Mtx mtx2; // 0x110
		Mtx mtx3; // 0xE0
		Mtx mtx4; // 0xB0
		Mtx mtx5; // 0x80

#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
		PSMTXScale(mtx2, mCustomScale->x, mCustomScale->y, mCustomScale->z);
#else
		MTXScale(mtx2, mCustomScale->x, mCustomScale->y, mCustomScale->z);
#endif
		PSMTXInverse(mtx.mMtx, mtx5);
		PSMTXTranspose(mtx5, mtx3);
		PSMTXConcat(mtx3, mtx2, mtx4);
		GXLoadNrmMtxImm(mtx4, gxID);
	} else {
		GXLoadNrmMtxImm(mtx.mMtx, gxID);
	}

	if (mLightCam) {
		Mtx tmpLightMtx;
		PSMTXConcat(mProjectionTextureMatrix, Matrix4f::ident.mMtx, tmpLightMtx);
		GXLoadTexMtxImm(tmpLightMtx, 30, GX_MTX3x4);
		return;
	}

	if (mHasTexGen) {
		Mtx texMtx;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
		f32 mag = 0.5f / PSVECMag((Vec*)mtx.mMtx);
#else
		f32 mag = 0.5f / VECMag((Vec*)mtx.mMtx);
#endif
		texMtx[0][0] = mag * mtx.mMtx[0][0];
		texMtx[0][1] = mag * mtx.mMtx[0][1];
		texMtx[0][2] = mag * mtx.mMtx[0][2];
		texMtx[0][3] = 0.5f;
		texMtx[1][0] = mag * mtx.mMtx[1][0];
		texMtx[1][1] = mag * mtx.mMtx[1][1];
		texMtx[1][2] = mag * mtx.mMtx[1][2];
		texMtx[1][3] = 0.5f;

		GXLoadTexMtxImm(texMtx, mTexMtxBaseID + gxID, GX_MTX2x4);
	}

	STACK_PAD_VAR(3);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::useMatrix(immut Matrix4f& mtx, int a)
{
	useMatrixQuick(mtx, a);
	mCurrentMatrixId = a * 3;
	GXSetCurrentMtx(mCurrentMatrixId);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::useTexture(Texture* texture, int id)
{
	mHasTexGen = FALSE;
	if (!texture || texture != mActiveTexture[id]) {
		if (texture) {
			texture->makeResident();
			GXLoadTexObj(texture->mTexObj, (GXTexMapID)id);
			GXSetNumTexGens(1);
			GXSetNumTevStages(1);
			GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
			GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		} else {
			GXSetNumTexGens(0);
			GXSetNumTevStages(1);
			GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
			GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
		}
		mActiveTexture[id] = texture;
	}
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setMatMatrices(Material* mat, int p2)
{
	mHasTexGen = (mat->mTextureInfo.mTevStageCount) ? true : false;
	GXSetNumTexGens(mat->mTextureInfo.mTexGenDataCount);

	int matrixType = 30;
	for (int i = 0, j = 0; i < mat->mTextureInfo.mTexGenDataCount; i++) {

		u32 postMtxId = mat->mTextureInfo.mTexGenData[i].mMatrixType;
		if (postMtxId != 10) {
			postMtxId = matrixType;
		} else {
			postMtxId = 60;
		}

		GXTexGenSrc texGenSrc   = GXTexGenSrc(mat->mTextureInfo.mTexGenData[i].mTexGenSrc);
		GXTexGenType texGenType = GXTexGenType(mat->mTextureInfo.mTexGenData[i].mTexGenType);
		GXTexCoordID texCoordID = GXTexCoordID(mat->mTextureInfo.mTexGenData[i].mTexCoordID);
		GXSetTexCoordGen2(texCoordID, texGenType, texGenSrc, postMtxId, GX_FALSE, GX_PTIDENTITY);

		if (mat->mTextureInfo.mTexGenData[i].mTexGenType != 1) {
			continue;
		}

		int animFactor = mat->mTextureInfo.mTextureData[j].mAnimationFactor;
		if (animFactor != 0xFF) {
			int id = (animFactor != 10) ? matrixType : 60;
			GXLoadTexMtxImm(mat->mTextureInfo.mTextureData[j].mAnimatedTexMtx.mMtx, id, GX_MTX2x4);

			if (mHasTexGen && mat->mTextureInfo.mTexGenData[i].mTexGenSrc == 1) {
				mTexMtxBaseID = matrixType;
				matrixType += (mat->mTextureInfo.mTevStageCount * p2) * 3;
			} else {
				matrixType += 3;
			}
		}
		j++;
	}
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setMaterial(Material* mat, bool p2)
{
	if (mat) {
		gsys->mMaterialCount++;

		if (mat->mFlags & MATFLAG_PVW) {
			if (mat->mDisplayListPtr) {
				GXCallDisplayList(mat->mDisplayListPtr, mat->mDisplayListSize);
				GXSetNumChans(mat->mLightingInfo.mNumChans);
			} else {
				if (mat->mPeInfo.mControlFlags & 1) {
					GXSetBlendMode(
					    (GXBlendMode)(mat->mPeInfo.mBlendModeFlags & 0xf), (GXBlendFactor)(mat->mPeInfo.mBlendModeFlags >> 4 & 0xf),
					    (GXBlendFactor)(mat->mPeInfo.mBlendModeFlags >> 8 & 0xf), (GXLogicOp)(mat->mPeInfo.mBlendModeFlags >> 12 & 0xf));

					GXSetAlphaCompare((GXCompare)(mat->mPeInfo.mAlphaCompareFlags & 0xF), (mat->mPeInfo.mAlphaCompareFlags >> 4 & 0xFF),
					                  (GXAlphaOp)(mat->mPeInfo.mAlphaCompareFlags >> 16 & 0xF),
					                  (GXCompare)(mat->mPeInfo.mAlphaCompareFlags >> 20 & 0xF),
					                  mat->mPeInfo.mAlphaCompareFlags >> 24 & 0xFF);

					GXSetZMode((mat->mPeInfo.mDepthTestFlags & 1) != 0, (GXCompare)(mat->mPeInfo.mDepthTestFlags >> 8 & 0xFF),
					           (mat->mPeInfo.mDepthTestFlags & 2) != 0);
				} else if (mat->mFlags & MATFLAG_INVERT_BLEND) {
					GXSetBlendMode(GX_BM_BLEND, GX_BL_ZERO, GX_BL_INVSRCCOL, GX_LO_CLEAR);
					GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
					GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
				} else if (mat->mFlags & MATFLAG_OPAQUE) {
					GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_COPY);
					GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
					GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
				} else if (mat->mFlags & MATFLAG_ALPHA_TEST) {
					GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_COPY);
					GXSetAlphaCompare(GX_GEQUAL, 0x80, GX_AOP_AND, GX_LEQUAL, 255);
					GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
				} else if (mat->mFlags & MATFLAG_ALPHA_BLEND) {
					GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_COPY);
					GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
					GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
				}

				GXSetTevKColor(GX_KCOLOR0, *((GXColor*)&mat->mTevInfo->mKonstColors[0]));
				GXSetTevKColor(GX_KCOLOR1, *((GXColor*)&mat->mTevInfo->mKonstColors[1]));
				GXSetTevKColor(GX_KCOLOR2, *((GXColor*)&mat->mTevInfo->mKonstColors[2]));
				GXSetTevKColor(GX_KCOLOR3, *((GXColor*)&mat->mTevInfo->mKonstColors[3]));
				for (int i = 0; i < mat->mTevInfo->mTevStageCount; i++) {
					PVWTevStage& stage = mat->mTevInfo->mTevStages[i];
					GXSetTevColorIn((GXTevStageID)i, (GXTevColorArg)stage.mTevColorCombiner.mInArgA,
					                (GXTevColorArg)stage.mTevColorCombiner.mInArgB, (GXTevColorArg)stage.mTevColorCombiner.mInArgC,
					                (GXTevColorArg)stage.mTevColorCombiner.mInArgD);
					GXSetTevColorOp((GXTevStageID)i, (GXTevOp)stage.mTevColorCombiner.mTevOp, (GXTevBias)stage.mTevColorCombiner.mBias,
					                (GXTevScale)stage.mTevColorCombiner.mScale, (GXBool)stage.mTevColorCombiner.mDoClamp,
					                (GXTevRegID)stage.mTevColorCombiner.mOutReg);
					GXSetTevAlphaIn((GXTevStageID)i, (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgA,
					                (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgB, (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgC,
					                (GXTevAlphaArg)stage.mTevAlphaCombiner.mInArgD);
					GXSetTevAlphaOp((GXTevStageID)i, (GXTevOp)stage.mTevAlphaCombiner.mTevOp, (GXTevBias)stage.mTevAlphaCombiner.mBias,
					                (GXTevScale)stage.mTevAlphaCombiner.mScale, (GXBool)stage.mTevAlphaCombiner.mDoClamp,
					                (GXTevRegID)stage.mTevAlphaCombiner.mOutReg);
				}

				gsys->mLightingSets++;
				setLighting((mat->mLightingInfo.mCtrlFlag & LightingControlFlags::EnableColor0) != 0, &mat->mLightingInfo);
			}

			for (int i = 0; i < mat->mTextureInfo.mTextureDataCount; i++) {
				if (mat->mTextureInfo.mTextureData[i].mTexture != mActiveTexture[i]) {
					mActiveTexture[i] = mat->mTextureInfo.mTextureData[i].mTexture;
					mActiveTexture[i]->makeResident();
					GXLoadTexObj(mActiveTexture[i]->mTexObj, GXTexMapID(i));
				}
			}

			GXSetTevColorS10(GX_TEVREG0, *(GXColorS10*)&mat->mTevInfo->mTevColRegs[0].mAnimatedColor);
			GXSetTevColorS10(GX_TEVREG1, *(GXColorS10*)&mat->mTevInfo->mTevColRegs[1].mAnimatedColor);
			GXSetTevColorS10(GX_TEVREG2, *(GXColorS10*)&mat->mTevInfo->mTevColRegs[2].mAnimatedColor);

			GXSetNumTevStages(mat->mTevInfo->mTevStageCount);

			for (int i = 0; i < mat->mTevInfo->mTevStageCount; i++) {
				PVWTevStage& stage = mat->mTevInfo->mTevStages[i];
				GXSetTevOrder(GXTevStageID(i), GXTexCoordID(stage.mTexCoordID), GXTexMapID(stage.mTexMapID), GXChannelID(stage.mChannelID));
				GXSetTevKColorSel(GXTevStageID(i), GXTevKColorSel(stage.mTevKColorSel));
				GXSetTevKAlphaSel(GXTevStageID(i), GXTevKAlphaSel(stage.mTevKAlphaSel));
			}

			Colour color;
			color.set(mat->mColourInfo.mColour.r, mat->mColourInfo.mColour.g, mat->mColourInfo.mColour.b,
			          mLightIntensity * mat->mColourInfo.mColour.a);
			GXSetChanMatColor(GX_COLOR0A0, *(GXColor*)&color);

			if (mat->mTextureInfo.mUseScale) {
				mCustomScale = &mat->mTextureInfo.mScale;
			} else {
				mCustomScale = nullptr;
			}

			setMatMatrices(mat, mMtxDepIdx);

			return;
		}

		mCustomScale = nullptr;
		if (mat->mFlags & MATFLAG_INVERT_BLEND) {
			GXSetBlendMode(GX_BM_BLEND, GX_BL_ZERO, GX_BL_INVSRCCOL, GX_LO_CLEAR);
			GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
			GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
		} else if (mat->mFlags & MATFLAG_OPAQUE) {
			GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_COPY);
			GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
			GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
		} else if (mat->mFlags & MATFLAG_ALPHA_TEST) {
			GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_COPY);
			GXSetAlphaCompare(GX_GEQUAL, 0x80, GX_AOP_AND, GX_LEQUAL, 255);
			GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
		} else if (mat->mFlags & MATFLAG_ALPHA_BLEND) {
			GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_COPY);
			GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
			GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
		}

		useTexture(mat->mTexture, GX_TEXMAP0);
		Colour color;
		color.set(mat->mColourInfo.mColour.r, mat->mColourInfo.mColour.g, mat->mColourInfo.mColour.b,
		          mLightIntensity * mat->mColourInfo.mColour.a);
		GXSetChanMatColor(GX_COLOR0A0, *(GXColor*)&color);

		if (mLightCam) {
			return;
		}

		if (mat->mEnvMapTexture) {
			if (!mIsEnvMapActive) {
				useTexture(mat->mEnvMapTexture, GX_TEXMAP1);
				if (mat->mTexture) {
					GXSetNumTexGens(2);
					GXSetNumTevStages(2);
				} else {
					GXSetNumTexGens(1);
					GXSetNumTevStages(1);
				}

				GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX3X4, GX_TG_NRM, mCurrentMatrixId + 30, GX_FALSE, GX_PTIDENTITY);
				GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR_NULL);
				if (mat->mTexture) {
					GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
					GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
				}

				GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_CPREV, GX_CC_ONE, GX_CC_TEXC, GX_CC_ZERO);
				GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
				GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_APREV, GX_CA_TEXA, GX_CA_ZERO);
				GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
				mIsEnvMapActive = true;
			}

			mHasTexGen = TRUE;
			return;
		}
	}

	mCustomScale = nullptr;
	if (mIsEnvMapActive) {
		GXSetTevOp(GX_TEVSTAGE1, GX_PASSCLR);
		GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX3X4, GX_TG_TEX1, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
		GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		mIsEnvMapActive = false;
	}

	GXSetNumTevStages(1);
	GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
	oldCull = FALSE;
	GXSetCullMode(GX_CULL_BACK);

	STACK_PAD_TERNARY(mCustomScale, 7);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::initMesh(Shape* model)
{
	oldTevGroup = 0;
	GXSetVtxAttrFmtv(GX_VTXFMT0, meshVAT);
	GXSetVtxDescv(meshVCD);
	if (model->mVertexList) {
		if (model->mVertexCacheFlags & VertexCacheFlags::VertexList) {
			DCStoreRange(model->mVertexList, model->mVertexCount * sizeof(Vector3f));
		}
		GXSetArray(GX_VA_POS, model->mVertexList, sizeof(Vector3f));
	}

	if (model->mNormalList) {
		if (model->mVertexCacheFlags & VertexCacheFlags::NormalList) {
			DCStoreRange(model->mNormalList, model->mNormalCount * sizeof(Vector3f));
		}
		GXSetArray(GX_VA_NRM, model->mNormalList, sizeof(Vector3f));
	}

	if (model->mNBTList) {
		if (model->mVertexCacheFlags & VertexCacheFlags::NBTList) {
			DCStoreRange(model->mNBTList, model->mNBTCount * sizeof(NBT));
		}
	}

	int i;
	for (i = 0; i < model->mTotalActiveTexCoords; i++) {
		if (model->mTexCoordList[i]) {
			if (model->mVertexCacheFlags & (1 << (i + 5))) {
				DCStoreRange(model->mTexCoordList[i], model->mTexCoordCounts[i] * sizeof(Vector2f));
			}
			GXSetArray((GXAttr)(GX_VA_TEX0 + i), model->mTexCoordList[i], sizeof(Vector2f));
		}
	}

	if (model->mVtxColorList) {
		if (model->mVertexCacheFlags & VertexCacheFlags::ColorList) {
			DCStoreRange(model->mVtxColorList, model->mVertexCount * sizeof(Colour));
		}

		GXSetArray(GX_VA_CLR0, model->mVtxColorList, sizeof(Colour));
	}

	model->mVertexCacheFlags = VertexCacheFlags::None;

	sendTxIndx      = false;
	sendMtxIndx     = true;
	sendColIndx     = false;
	sendNbtIndx     = false;
	sendTxUVIndx[0] = true;
	sendTxUVIndx[1] = false;
	sendTxUVIndx[2] = false;
	sendTxUVIndx[3] = false;
	sendTxUVIndx[4] = false;
	sendTxUVIndx[5] = false;
	sendTxUVIndx[6] = false;
	sendTxUVIndx[7] = false;

	for (i = 0; i < 8; i++) {
		mActiveTexture[i] = nullptr;
	}
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setupVtxDesc(Shape* model, Material* mat, Mesh* mesh)
{
	if (mesh->mVertexDescriptor & 0x1) {
		if (!sendMtxIndx) {
			GXSetVtxDesc(GX_VA_PNMTXIDX, GX_DIRECT);
			sendMtxIndx = true;
		}
	} else {
		if (sendMtxIndx) {
			GXSetVtxDesc(GX_VA_PNMTXIDX, GX_NONE);
			sendMtxIndx = false;
		}
	}

	if (mesh->mVertexDescriptor & 0x2) {
		if (!sendTxIndx) {
			GXSetVtxDesc(GX_VA_TEX1MTXIDX, GX_DIRECT);
			sendTxIndx = true;
		}
	} else {
		if (sendTxIndx) {
			GXSetVtxDesc(GX_VA_TEX1MTXIDX, GX_NONE);
			sendTxIndx = false;
		}
	}

	if (mCustomScale) {
		if (!sendNbtIndx) {
			GXSetArray(GX_VA_NBT, model->mNBTList, sizeof(NBT));
			GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NBT, GX_NRM_NBT, GX_F32, 0);
			GXSetVtxDesc(GX_VA_NRM, GX_NONE);
			GXSetVtxDesc(GX_VA_NBT, GX_INDEX16);
			sendNbtIndx = true;
		}
	} else {
		if (sendNbtIndx) {
			GXSetArray(GX_VA_NRM, model->mNormalList, sizeof(Vector3f));
			GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
			GXSetVtxDesc(GX_VA_NRM, GX_INDEX16);
			GXSetVtxDesc(GX_VA_NBT, GX_NONE);
			sendNbtIndx = false;
		}
	}

	for (int i = 0; i < 8; i++) {
		if (mesh->mVertexDescriptor & (1 << (i + 3))) {
			if (!sendTxUVIndx[i]) {
				GXSetVtxDesc(GXAttr(GX_VA_TEX0 + i), GX_INDEX16);
				sendTxUVIndx[i] = true;
			}
		} else {
			if (sendTxUVIndx[i]) {
				GXSetVtxDesc(GXAttr(GX_VA_TEX0 + i), GX_NONE);
				sendTxUVIndx[i] = false;
			}
		}
	}

	if (mesh->mVertexDescriptor & 0x4) {
		if (!sendColIndx) {
			GXSetVtxDesc(GX_VA_CLR0, GX_INDEX16);
			sendColIndx = true;
		}
	} else {
		if (sendColIndx) {
			GXSetVtxDesc(GX_VA_CLR0, GX_NONE);
			sendColIndx = false;
		}
	}
}

/**
 * @todo: Documentation
 */
void DGXGraphics::drawSingleMatpoly(Shape* model, Joint::MatPoly* matPoly)
{
	Mesh& mesh    = model->mMeshList[matPoly->mMeshIndex];
	Material& mat = model->mMaterialList[matPoly->mIndex];

	if (!mesh.mJointList || mat.mFlags & MATFLAG_SKIP) {
		return;
	}

	if ((!mesh.mJointList->mFlags) & 0x1) { // is this a typo? feels like a typo.
		return;
	}

	if (!(mat.mFlags & mRenderState)) {
		return;
	}

	mMtxDepIdx = mesh.mMtxDepIdx;
	useMaterial(&mat);
	setupVtxDesc(model, &mat, &mesh);

	for (int i = 0; i < mesh.mMtxGroupCount; i++) {
		MtxGroup& group = mesh.mMtxGroupList[i];
		for (int j = 0; j < group.mDepLength; j++) {
			if (group.mDepList[j] == -1) {
				continue;
			}

			VtxMatrix& vtxMtx = model->mVtxMatrixList[group.mDepList[j]];
			if (model->mCurrentAnimation->mData) {
				if (vtxMtx.mHasPartialWeights) {
					useMatrixQuick(model->getAnimMatrix(vtxMtx.mIndex), j);
				} else {
					useMatrixQuick(model->getAnimMatrix(model->mJointCount + vtxMtx.mIndex), j);
				}
			} else {
				useMatrixQuick(model->mJointList[vtxMtx.mIndex].mAnimMatrix, j);
			}
		}

		for (int j = 0; j < group.mDispLength; j++) {
			DispList& list = group.mDispList[j];
			setCullFront((list.mFlags & 3) ^ mCullFlip);
			gsys->mPolygonCount += list.mFaceCount;
			gsys->mDispCount++;
			GXCallDisplayList(list.mData, list.mDataLength);
		}
	}
}

/**
 * @todo: Documentation
 */
void DGXGraphics::drawMeshes(Camera&, Shape* shape)
{
	initMesh(shape);
	for (int i = shape->mTotalMatpolyCount - 1; i >= 0; i--) {
		drawSingleMatpoly(shape, shape->mMatpolyList[i]);
	}
	useMaterial(nullptr);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setColour(immut Colour& color, bool set)
{
	mPrimaryColour = color;
	if (set) {
		mAuxiliaryColour = color;
	}

	GXColor color2;
	color2.r = mPrimaryColour.r;
	color2.g = mPrimaryColour.g;
	color2.b = mPrimaryColour.b;
	color2.a = mPrimaryColour.a;

	color2.a *= mLightIntensity;
	GXSetChanMatColor(GX_COLOR0A0, color2);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setAuxColour(immut Colour& color)
{
	mAuxiliaryColour = color;
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setPrimEnv(immut Colour* col1, immut Colour* col2)
{
	if (col1) {
		GXSetTevColor(GX_TEVREG0, *(GXColor*)col1);
	}
	if (col2) {
		GXSetTevColor(GX_TEVREG1, *(GXColor*)col2);
	}
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setClearColour(immut Colour& color)
{
	mBufferClearColour = color;
}

/**
 * @todo: Documentation
 */
void DGXGraphics::clearBuffer(int, bool)
{
	GXSetCopyClear(*(GXColor*)&mBufferClearColour, 0xFFFFFF); // max clear_z value
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setFog(bool set)
{
	if (set) {
#if defined(VERSION_PIKIDEMO)
		GXSetFog(GX_FOG_LINEAR, mFogStart, mFogEnd, mCamera->mNear, mCamera->mFar, *(GXColor*)&mFogColour);
#else
		if (mCamera->mNear < mCamera->mFar) {
			GXSetFog(GX_FOG_LINEAR, mFogStart, mFogEnd, mCamera->mNear, mCamera->mFar, *(GXColor*)&mFogColour);
		} else {
#if defined(VERSION_GPIP01_00)
			OSReport("%s:%d Warning: cam->vNear >= cam->vFar\n", __FILE__, 1732);
#else
			OSReport("%s:%d Warning: cam->vNear >= cam->vFar\n", __FILE__, 1683);
#endif
		}
#endif
	} else {
		GXSetFog(GX_FOG_NONE, 0.0f, 0.0f, 0.0f, 0.0f, (GXColor) { 0, 0, 0, 0 });
	}
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setFog(bool set, immut Colour& color, f32 density, f32 start, f32 end)
{
	mFogColour  = color;
	mFogStart   = start;
	mFogEnd     = end;
	mFogDensity = density;
	setFog(set);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::setBlendMode(u8 blendFactor, u8 zMode, u8 blendMode)
{
	GXSetBlendMode(GX_BM_BLEND, (GXBlendFactor)(blendFactor & 0xf), (GXBlendFactor)(blendFactor >> 4), GX_LO_SET);

	GXSetZMode((GXBool)((zMode & 8) >> 3), (GXCompare)(zMode & 7), (GXBool)(zMode >> 4));

	GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
	GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
	GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_TEXA, GX_CA_A0, GX_CA_ZERO);

	switch (blendMode) {
	case 0:
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C0, GX_CC_ONE, GX_CC_TEXC, GX_CC_ZERO);
		break;
	case 1:
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_C0, GX_CC_TEXC, GX_CC_ZERO);
		break;
	case 2:
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C2, GX_CC_C0, GX_CC_TEXC, GX_CC_ZERO);
		break;
	case 3:
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_C0, GX_CC_C2);
		break;
	case 4:
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_C0);
		break;
	}
}

/**
 * @brief Configures the GX unit to use a specific color blending preset (blend, Z, and alpha test settings).
 *
 * @param blendMode Preset to set the color blending mode to - see `BlendMode` enum.
 * @return The previous `BlendMode` being overridden.
 */
int DGXGraphics::setCBlending(int blendMode)
{
	int old    = mBlendMode;
	mBlendMode = blendMode;
	GXSetNumTexGens(1);
	GXSetNumTevStages(1);
	GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);

	switch (blendMode) {
	case BLEND_Alpha:
		GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
		break;
	case BLEND_Additive:
		GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_SET);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
		break;
	case BLEND_InverseColor:
		GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_ZERO, GX_BL_INVSRCCOL, GX_LO_CLEAR);
		GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
		break;
	case BLEND_AlphaAdditive:
		GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_SET);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
		break;
	case BLEND_AdditiveNoZ:
		GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_SET);
		GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
		break;
	case BLEND_AlphaTest:
		GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
		GXSetAlphaCompare(GX_GEQUAL, 0x80, GX_AOP_AND, GX_LEQUAL, 0xff);
		break;
	case BLEND_MultiTexture:
		GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
		GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
		GXSetNumTexGens(2);
		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
		GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR0A0);
		GXSetNumTevStages(4);

		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
		GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_RASC, GX_CC_TEXC, GX_CC_ZERO);
		GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_RASA, GX_CA_TEXA, GX_CA_ZERO);
		GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

		GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR0A0);
		GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_CPREV);
		GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
		GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

		GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		GXSetTevColorIn(GX_TEVSTAGE2, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_CPREV);
		GXSetTevColorOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_ZERO, GX_CA_APREV, GX_CA_APREV, GX_CA_ZERO);
		GXSetTevAlphaOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

		GXSetTevOrder(GX_TEVSTAGE3, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
		GXSetTevColorIn(GX_TEVSTAGE3, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_CPREV);
		GXSetTevColorOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
		GXSetTevAlphaIn(GX_TEVSTAGE3, GX_CA_ZERO, GX_CA_A0, GX_CA_APREV, GX_CA_ZERO);
		GXSetTevAlphaOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

		GXSetAlphaCompare(GX_GEQUAL, 0, GX_AOP_AND, GX_LESS, 0xff);
		break;
	}
	return old;
}

/**
 * @todo: Documentation
 */
bool DGXGraphics::initParticle(bool a)
{
	if (!mActiveTexture[0]) {
		return false;
	}

	GXClearVtxDesc();

	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);

	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_POS_XYZ, GX_F32, 0);
	if (a) {
		GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
		GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_POS_XYZ, GX_RGBA8, 0);
	}
	return true;
}

/**
 * @todo: Documentation
 */
void DGXGraphics::drawRotParticle(Camera& cam, immut Vector3f& pos, u16 angle, f32 radius)
{
	gsys->mPolygonCount += 2;

	// max - 0x2000
	Vector3f vec1(radius * sinShort(angle + 0xE000), radius * cosShort(angle + 0xE000), 0.0f);
	// min + 0x2000
	Vector3f vec2(radius * sinShort(angle + 0x2000), radius * cosShort(angle + 0x2000), 0.0f);
	// min + 0x6000
	Vector3f vec3(radius * sinShort(angle + 0x6000), radius * cosShort(angle + 0x6000), 0.0f);
	// max - 0x6000
	Vector3f vec4(radius * sinShort(angle + 0xA000), radius * cosShort(angle + 0xA000), 0.0f);

	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	GXPosition3f32(pos.x + vec1.DP(cam.mViewXAxis), pos.y + vec1.DP(cam.mViewYAxis), pos.z + vec1.DP(cam.mViewZAxis));
	GXTexCoord2f32(0.0f, 0.0f);

	GXPosition3f32(pos.x + vec2.DP(cam.mViewXAxis), pos.y + vec2.DP(cam.mViewYAxis), pos.z + vec2.DP(cam.mViewZAxis));
	GXTexCoord2f32(1.0f, 0.0f);

	GXPosition3f32(pos.x + vec3.DP(cam.mViewXAxis), pos.y + vec3.DP(cam.mViewYAxis), pos.z + vec3.DP(cam.mViewZAxis));
	GXTexCoord2f32(1.0f, 1.0f);

	GXPosition3f32(pos.x + vec4.DP(cam.mViewXAxis), pos.y + vec4.DP(cam.mViewYAxis), pos.z + vec4.DP(cam.mViewZAxis));
	GXTexCoord2f32(0.0f, 1.0f);

	GXEnd();
}

/**
 * @todo: Documentation
 */
void DGXGraphics::drawParticle(Camera& cam, immut Vector3f& pos, f32 size)
{
	gsys->mPolygonCount += 2;
	u32 primClr = *(u32*)&mPrimaryColour;

	Vector3f vec1(-size, size, 0.0f);
	Vector3f vec2(size, size, 0.0f);
	Vector3f vec3(size, -size, 0.0f);
	Vector3f vec4(-size, -size, 0.0f);

	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	GXPosition3f32(pos.x + vec1.DP(cam.mViewXAxis), pos.y + vec1.DP(cam.mViewYAxis), pos.z + vec1.DP(cam.mViewZAxis));
	GXColor1u32(primClr);
	GXTexCoord2f32(0.0f, 0.0f);

	GXPosition3f32(pos.x + vec2.DP(cam.mViewXAxis), pos.y + vec2.DP(cam.mViewYAxis), pos.z + vec2.DP(cam.mViewZAxis));
	GXColor1u32(primClr);
	GXTexCoord2f32(1.0f, 0.0f);

	GXPosition3f32(pos.x + vec3.DP(cam.mViewXAxis), pos.y + vec3.DP(cam.mViewYAxis), pos.z + vec3.DP(cam.mViewZAxis));
	GXColor1u32(primClr);
	GXTexCoord2f32(1.0f, 1.0f);

	GXPosition3f32(pos.x + vec4.DP(cam.mViewXAxis), pos.y + vec4.DP(cam.mViewYAxis), pos.z + vec4.DP(cam.mViewZAxis));
	GXColor1u32(primClr);
	GXTexCoord2f32(0.0f, 1.0f);

	GXEnd();
}

/**
 * @todo: Documentation
 */
void DGXGraphics::drawCamParticle(Camera& cam, immut Vector3f& pos, immut Vector2f& extents, immut Vector2f& uvMin, immut Vector2f& uvMax)
{
	gsys->mPolygonCount += 2;

	f32 y0, z, x1, y1, x0;

	y0 = extents.y + pos.y;
	x0 = -extents.x + pos.x;
	x1 = extents.x + pos.x;
	y1 = -extents.y + pos.y;
	z  = pos.z;

	u32 primClr = *(u32*)&mPrimaryColour;

	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	GXPosition3f32(x0, y0, z);
	GXColor1u32(primClr);
	GXTexCoord2f32(uvMin.x, uvMin.y);

	GXPosition3f32(x1, y0, z);
	GXColor1u32(primClr);
	GXTexCoord2f32(uvMax.x, uvMin.y);

	GXPosition3f32(x1, y1, z);
	GXColor1u32(primClr);
	GXTexCoord2f32(uvMax.x, uvMax.y);

	GXPosition3f32(x0, y1, z);
	GXColor1u32(primClr);
	GXTexCoord2f32(uvMin.x, uvMax.y);

	GXEnd();

	STACK_PAD_VAR(40);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::drawLine(immut Vector3f& start, immut Vector3f& end)
{
	useTexture(nullptr, GX_TEXMAP0);
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);

	u32 primClr = *(u32*)&mPrimaryColour;

	GXBegin(GX_LINES, GX_VTXFMT0, 2);

	GXPosition3f32(start.x, start.y, start.z);
	GXColor1u32(primClr);

	GXPosition3f32(end.x, end.y, end.z);
	GXColor1u32(primClr);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::drawPoints(immut Vector3f* points, int count)
{
	useTexture(nullptr, GX_TEXMAP0);
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);

	u32 primClr = *(u32*)&mPrimaryColour;

	GXBegin(GX_POINTS, GX_VTXFMT0, count);

	for (int i = 0; i < count; i++) {
		GXPosition3f32(points[i].x, points[i].y, points[i].z);
		GXColor1u32(primClr);
	}
}

/**
 * @todo: Documentation
 */
void DGXGraphics::drawOneTri(immut Vector3f* vertices, immut Vector3f* normals, immut Vector2f* texCoords, int count)
{
	gsys->mPolygonCount++;
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	if (normals) {
		GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
	} else {
		GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	}

	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	if (normals) {
		GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
	} else {
		GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	}
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);

	u32 primClr = *(u32*)&mPrimaryColour;

	GXBegin(GX_TRIANGLEFAN, GX_VTXFMT0, count);

	for (int i = 0; i < count; i++) {
		GXPosition3f32(vertices[i].x, vertices[i].y, vertices[i].z);
		if (normals) {
			GXNormal3f32(normals[i].x, normals[i].y, normals[i].z);
		} else {
			GXColor1u32(primClr);
		}
		GXTexCoord2f32(texCoords[i].x, texCoords[i].y);
	}
}

/**
 * @todo: Documentation
 */
void DGXGraphics::blatRectangle(immut RectArea& rect)
{
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX1, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX1, GX_TEX_ST, GX_F32, 0);

	u32 primClr = *(u32*)&mPrimaryColour;
	u32 auxClr  = *(u32*)&mAuxiliaryColour;
	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	GXPosition3f32(rect.mMinX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(0.0f, 0.0f);
	GXTexCoord2f32(0.0f, 0.0f);

	GXPosition3f32(rect.mMaxX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(1.0f, 0.0f);
	GXTexCoord2f32(1.0f, 0.0f);

	GXPosition3f32(rect.mMaxX, rect.mMaxY, 0.0f);
	GXColor1u32(auxClr);
	GXTexCoord2f32(1.0f, 1.0f);
	GXTexCoord2f32(1.0f, 1.0f);

	GXPosition3f32(rect.mMinX, rect.mMaxY, 0.0f);
	GXColor1u32(auxClr);
	GXTexCoord2f32(0.0f, 1.0f);
	GXTexCoord2f32(0.0f, 1.0f);

	GXEnd();

	STACK_PAD_VAR(4);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::testRectangle(immut RectArea& rect)
{
	u32 primClr = *(u32*)&mPrimaryColour;
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);

	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	GXPosition3f32(rect.mMinX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(0.0f, 0.0f);

	GXPosition3f32(rect.mMaxX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(1.0f, 0.0f);

	GXPosition3f32(rect.mMaxX, rect.mMaxY, 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(1.0f, 1.0f);

	GXPosition3f32(rect.mMinX, rect.mMaxY, 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(0.0f, 1.0f);

	GXEnd();

	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::drawRectangle(immut RectArea& bounds, immut RectArea& texCoords, immut Vector3f* offset)
{
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
	GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
	GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);

	u32 primClr = *(u32*)&mPrimaryColour;
	u32 auxClr  = *(u32*)&mAuxiliaryColour;

	GXBegin(GX_QUADS, GX_VTXFMT0, 4);
	GXPosition3f32(bounds.mMinX + ((offset) ? offset->x : 0.0f), bounds.mMinY + ((offset) ? offset->y : 0.0f), (offset) ? offset->z : 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(f32(texCoords.mMinX) * mActiveTexture[0]->mWidthFactor, f32(texCoords.mMinY) * mActiveTexture[0]->mHeightFactor);

	GXPosition3f32(bounds.mMaxX + ((offset) ? offset->x : 0.0f), bounds.mMinY + ((offset) ? offset->y : 0.0f), (offset) ? offset->z : 0.0f);
	GXColor1u32(primClr);
	GXTexCoord2f32(f32(texCoords.mMaxX) * mActiveTexture[0]->mWidthFactor, f32(texCoords.mMinY) * mActiveTexture[0]->mHeightFactor);

	GXPosition3f32(bounds.mMaxX + ((offset) ? offset->x : 0.0f), bounds.mMaxY + ((offset) ? offset->y : 0.0f), (offset) ? offset->z : 0.0f);
	GXColor1u32(auxClr);
	GXTexCoord2f32(f32(texCoords.mMaxX) * mActiveTexture[0]->mWidthFactor, f32(texCoords.mMaxY) * mActiveTexture[0]->mHeightFactor);

	GXPosition3f32(bounds.mMinX + ((offset) ? offset->x : 0.0f), bounds.mMaxY + ((offset) ? offset->y : 0.0f), (offset) ? offset->z : 0.0f);
	GXColor1u32(auxClr);
	GXTexCoord2f32(f32(texCoords.mMinX) * mActiveTexture[0]->mWidthFactor, f32(texCoords.mMaxY) * mActiveTexture[0]->mHeightFactor);
}

/**
 * @todo: Documentation
 */
void DGXGraphics::lineRectangle(immut RectArea& rect)
{
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);

	useTexture(nullptr, GX_TEXMAP0);

	u32 primClr = *(u32*)&mPrimaryColour;
	u32 auxClr  = *(u32*)&mAuxiliaryColour;
	GXBegin(GX_LINESTRIP, GX_VTXFMT0, 5);

	GXPosition3f32(rect.mMinX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);

	GXPosition3f32(rect.mMaxX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);

	GXPosition3f32(rect.mMaxX, rect.mMaxY, 0.0f);
	GXColor1u32(auxClr);

	GXPosition3f32(rect.mMinX, rect.mMaxY, 0.0f);
	GXColor1u32(auxClr);

	GXPosition3f32(rect.mMinX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);

	GXEnd();
}

/**
 * @todo: Documentation
 */
void DGXGraphics::fillRectangle(immut RectArea& rect)
{
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);

	useTexture(nullptr, GX_TEXMAP0);

	u32 primClr = *(u32*)&mPrimaryColour;
	u32 auxClr  = *(u32*)&mAuxiliaryColour;
	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	GXPosition3f32(rect.mMinX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);

	GXPosition3f32(rect.mMaxX, rect.mMinY, 0.0f);
	GXColor1u32(primClr);

	GXPosition3f32(rect.mMaxX, rect.mMaxY, 0.0f);
	GXColor1u32(auxClr);

	GXPosition3f32(rect.mMinX, rect.mMaxY, 0.0f);
	GXColor1u32(auxClr);

	GXEnd();
}

/**
 * @todo: Documentation
 */
void DGXGraphics::texturePrintf(Font* font, int x, int y, immut char* format, ...)
{
	char buf[PATH_MAX];
	va_list vlist;
	va_start(vlist, format);
	vsprintf(buf, format, vlist);
	GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
	GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
	useTexture(font->mTexture, GX_TEXMAP0);

	GXSetChanMatColor(GX_COLOR0, *(GXColor*)&mPrimaryColour);

	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);

	int xPos           = x;
	int yPos           = y;
	const char* bufPtr = buf;
	while (*bufPtr) {
#if defined(VERSION_GPIP01_00)
		char z = *bufPtr;
		STACK_PAD_VAR(2);
		int idx;
		if (z >= 0xa0) {
			idx = font->charToIndex(z);
			bufPtr++;
		} else if (z & 0x80) {
			idx = font->charToIndex(u16(bufPtr[0] << 8 | bufPtr[1]));
			bufPtr += 2;
		} else {
			idx = font->charToIndex(z);
			bufPtr++;
		}
#else
		int idx;
		if (*bufPtr & 0x80) {
			idx = font->charToIndex(u16(bufPtr[0] << 8 | bufPtr[1]));
			bufPtr += 2;
		} else {
			idx = font->charToIndex(*bufPtr);
			bufPtr++;
		}
#endif

		RectArea& texCoords = font->mChars[idx].mTextureCoords;

		RectArea bounds;
		bounds.mMinY = yPos;
		bounds.mMaxY = yPos + font->mChars[idx].mHeight;
		bounds.mMinX = xPos - font->mChars[idx].mLeftOffset;
		bounds.mMaxX = xPos - font->mChars[idx].mLeftOffset + font->mChars[idx].mWidth;

		u32 primClr = *(u32*)&mPrimaryColour;
		u32 auxClr  = *(u32*)&mAuxiliaryColour;

		GXBegin(GX_QUADS, GX_VTXFMT0, 4);
		GXPosition3f32(bounds.mMinX, bounds.mMinY, 0.0f);
		GXColor1u32(primClr);
		GXTexCoord2f32((0.5f + texCoords.mMinX) * mActiveTexture[0]->mWidthFactor,
		               (0.5f + texCoords.mMinY) * mActiveTexture[0]->mHeightFactor);

		GXPosition3f32(bounds.mMaxX, bounds.mMinY, 0.0f);
		GXColor1u32(primClr);
		GXTexCoord2f32((0.5f + texCoords.mMaxX) * mActiveTexture[0]->mWidthFactor,
		               (0.5f + texCoords.mMinY) * mActiveTexture[0]->mHeightFactor);

		GXPosition3f32(bounds.mMaxX, bounds.mMaxY, 0.0f);
		GXColor1u32(auxClr);
		GXTexCoord2f32((0.5f + texCoords.mMaxX) * mActiveTexture[0]->mWidthFactor,
		               (0.5f + texCoords.mMaxY) * mActiveTexture[0]->mHeightFactor);

		GXPosition3f32(bounds.mMinX, bounds.mMaxY, 0.0f);
		GXColor1u32(auxClr);
		GXTexCoord2f32((0.5f + texCoords.mMinX) * mActiveTexture[0]->mWidthFactor,
		               (0.5f + texCoords.mMaxY) * mActiveTexture[0]->mHeightFactor);
		GXEnd();

		xPos += font->mChars[idx].mCharSpacing;
	}

	STACK_PAD_TERNARY(font, 4);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0001A0
 */
void DGXGraphics::showCrash(u16, OSContext*)
{
	OSReport("Unknown addr !!");
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000184
 */
void DGXGraphics::showError(immut char* msg1, immut char* fileName, int line)
{
	OSReport("ERROR: %s", msg1);
	OSReport("ERROR: in %s at line %d", fileName, line);
	// UNUSED FUNCTION
}

static char sAsciiTable[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x29, 0xFF, 0xFF, 0xFF, 0x2B, 0xFF, 0xFF, 0x25, 0x26, 0xFF, 0x2A,
	0xFF, 0x27, 0x2C, 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x24, 0xFF, 0xFF, 0xFF, 0xFF, 0x28, 0xFF, 0x0A,
	0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
	0x21, 0x22, 0x23, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16,
	0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

static char sFontData[] = {
	0x70, 0x87, 0x1C, 0x30, 0x89, 0x88, 0xA2, 0x50, 0x88, 0x80, 0x82, 0x90, 0x88, 0x83, 0x1C, 0x90, 0x88, 0x84, 0x02, 0xF8, 0x88, 0x88,
	0x22, 0x10, 0x71, 0xCF, 0x9C, 0x10, 0xF9, 0xCF, 0x9C, 0x70, 0x82, 0x28, 0xA2, 0x88, 0xF2, 0x00, 0xA2, 0x88, 0x0B, 0xC1, 0x1C, 0x78,
	0x0A, 0x22, 0x22, 0x08, 0x8A, 0x22, 0x22, 0x88, 0x71, 0xC2, 0x1C, 0x70, 0x23, 0xC7, 0x38, 0xF8, 0x52, 0x28, 0xA4, 0x80, 0x8A, 0x28,
	0x22, 0x80, 0x8B, 0xC8, 0x22, 0xF0, 0xFA, 0x28, 0x22, 0x80, 0x8A, 0x28, 0xA4, 0x80, 0x8B, 0xC7, 0x38, 0xF8, 0xF9, 0xC8, 0x9C, 0x08,
	0x82, 0x28, 0x88, 0x08, 0x82, 0x08, 0x88, 0x08, 0xF2, 0xEF, 0x88, 0x08, 0x82, 0x28, 0x88, 0x88, 0x82, 0x28, 0x88, 0x88, 0x81, 0xC8,
	0x9C, 0x70, 0x8A, 0x08, 0xA2, 0x70, 0x92, 0x0D, 0xA2, 0x88, 0xA2, 0x0A, 0xB2, 0x88, 0xC2, 0x0A, 0xAA, 0x88, 0xA2, 0x08, 0xA6, 0x88,
	0x92, 0x08, 0xA2, 0x88, 0x8B, 0xE8, 0xA2, 0x70, 0xF1, 0xCF, 0x1C, 0xF8, 0x8A, 0x28, 0xA2, 0x20, 0x8A, 0x28, 0xA0, 0x20, 0xF2, 0x2F,
	0x1C, 0x20, 0x82, 0xAA, 0x02, 0x20, 0x82, 0x49, 0x22, 0x20, 0x81, 0xA8, 0x9C, 0x20, 0x8A, 0x28, 0xA2, 0x88, 0x8A, 0x28, 0xA2, 0x88,
	0x8A, 0x28, 0x94, 0x88, 0x8A, 0x2A, 0x88, 0x50, 0x89, 0x4A, 0x94, 0x20, 0x89, 0x4A, 0xA2, 0x20, 0x70, 0x85, 0x22, 0x20, 0xF8, 0x01,
	0x10, 0x00, 0x08, 0x02, 0x08, 0x00, 0x10, 0x84, 0x04, 0x00, 0x20, 0x04, 0x04, 0x70, 0x40, 0x84, 0x04, 0x00, 0x80, 0x02, 0x08, 0x00,
	0xF8, 0x01, 0x10, 0x00, 0x70, 0x80, 0x00, 0x00, 0x88, 0x82, 0x22, 0x00, 0x08, 0x82, 0x04, 0x00, 0x10, 0x8F, 0x88, 0x00, 0x20, 0x82,
	0x10, 0x00, 0x00, 0x02, 0x22, 0x00, 0x20, 0x80, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
};

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000D0
 */
void DGXGraphics::directDrawChar(int, int, int)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F8
 */
void DGXGraphics::directDrawChar(RectArea&, RectArea&)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0001D8
 */
void DGXGraphics::directPrint(int, int, immut char*, ...)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000108
 */
void DGXGraphics::directErase(RectArea&, bool)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
Shape::Shape()
{
}

/**
 * @todo: Documentation
 */
void Shape::optimize()
{
	if (!mTexCoordList[0]) {
		mTexCoordList[0]      = new Vector2f[1];
		mTexCoordList[0][0].x = 0.0f;
		mTexCoordList[0][0].y = 0.0f;
	}

	mVertexCacheFlags
	    = VertexCacheFlags::VertexList | VertexCacheFlags::NormalList | VertexCacheFlags::NBTList | VertexCacheFlags::ColorList;
	for (int i = 0; i < mTotalActiveTexCoords; i++) {
		mVertexCacheFlags |= (1 << (i + 5));
	}

	if (!mMeshCount) {
		return;
	}

	for (int i = 0; i < mMeshCount; i++) {
		for (int j = 0; j < mMeshList[i].mMtxGroupCount; j++) {
			DispList* list = mMeshList[i].mMtxGroupList[j].mDispList;
			for (int k = 0; k < mMeshList[i].mMtxGroupList[j].mDispLength; k++) {
				DCStoreRange(list->mData, list->mDataLength);
				list++; // why.
			}
		}
	}
}
